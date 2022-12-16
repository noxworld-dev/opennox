package noxrender

import (
	"archive/zip"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"image"
	"image/jpeg"
	"image/png"
	"os"
	"path"
	"path/filepath"
	"strings"
	"sync"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/bag"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/noximage/pcx"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/alloc/handles"
)

var (
	debugBagImages = os.Getenv("NOX_DEBUG_BAG_IMAGES") == "true"
	imgLog         = log.New("images")
)

type Image struct {
	c         *renderSprites
	h         unsafe.Pointer
	typ       int
	bag       *bag.ImageRec
	raw       []byte
	override  []byte
	nocgo     bool
	cdata     []byte
	cfree     func()
	Field_1_0 uint16
	Field_1_1 uint16
}

func (img *Image) C() unsafe.Pointer {
	if img == nil {
		return nil
	}
	if img.nocgo {
		panic("image not allowed in cgo context")
	}
	if img.h == nil {
		img.h = handles.NewPtr()
		img.c.byHandle[img.h] = img
	}
	return img.h
}

func (img *Image) Free() {
	if img == nil {
		return
	}
	img.cdata = nil
	if img.cfree != nil {
		img.cfree()
	}
	img.cfree = nil
}

func (img *Image) String() string {
	if img == nil {
		return "<nil>"
	}
	if img.override != nil {
		return fmt.Sprintf("{type=%d, override=[%d]}", img.Type(), len(img.override))
	}
	if img.bag != nil {
		return fmt.Sprintf("{type=%d, idx=%d, data=[%d]}", img.Type(), img.bag.Index, len(img.raw))
	}
	return fmt.Sprintf("{type=%d, raw=[%d]}", img.Type(), len(img.raw))
}

func (img *Image) Type() int {
	if img.bag != nil {
		return int(img.bag.Type)
	}
	return img.typ
}

func (img *Image) loadOverride() []byte {
	if img == nil || img.raw != nil {
		return nil
	}
	switch img.Type() {
	default:
		return nil
	case 3, 4, 5, 6:
	}
	if img.override != nil {
		return img.override
	}
	sect := int(img.bag.SegmInd)
	offs := int(img.bag.Offset)

	im, err := img.c.ImageByBagSection(sect, offs)
	if err != nil {
		log.Println(err)
		return nil
	} else if im == nil {
		return nil
	}
	img.override = pcx.Encode(im)
	return img.override
}

func (img *Image) Pixdata() []byte {
	if img == nil {
		return nil
	}
	if img.cdata != nil {
		return img.cdata
	}
	data := img.loadOverride()
	if data == nil {
		data = img.bagPixdata()
	}
	if len(data) == 0 {
		panic("cannot load")
	}
	// TODO: remove interning when we get rid of C renderer
	img.cdata, img.cfree = alloc.CloneSlice(data)
	return img.cdata
}

func (img *Image) bagPixdata() []byte { // nox_video_getImagePixdata_42FB30
	if img == nil {
		return nil
	}
	if img.Type()&0x3F == 7 {
		return nil
	}
	if img.Type()&0x80 != 0 {
		panic("unreachable")
	}
	if img.raw != nil {
		return img.raw
	}
	data, err := img.bag.Raw()
	if err != nil {
		panic(err)
	}
	img.raw = data
	return data
}

func (img *Image) Meta() (off, sz image.Point, ok bool) {
	pix := img.Pixdata()
	if len(pix) < 8 {
		ok = false
		return
	}
	sz.X = int(int32(binary.LittleEndian.Uint32(pix[0:])))
	sz.Y = int(int32(binary.LittleEndian.Uint32(pix[4:])))
	if len(pix) < 16 {
		ok = false
		return
	}
	ok = true
	off.X = int(int32(binary.LittleEndian.Uint32(pix[8:])))
	off.Y = int(int32(binary.LittleEndian.Uint32(pix[12:])))
	return
}

func (b *renderSprites) readVideobag(path string) error {
	f, err := bag.Open(path)
	if err != nil {
		return err
	}
	imgs, err := f.Images()
	if err != nil {
		_ = f.Close()
		return err
	}
	b.bag = f
	b.byIndex = make([]*Image, 0, len(imgs))
	for _, img := range imgs {
		b.byIndex = append(b.byIndex, &Image{c: b, bag: img})
	}
	return nil
}

type bagImage struct {
	*bag.ImageRec
	Meta *pcx.ImageMeta
}

func (b *renderSprites) ReadVideoBag() error {
	return b.readVideobag("video.bag")
}

type renderSprites struct {
	bag      *bag.File
	byHandle map[unsafe.Pointer]*Image
	byIndex  []*Image

	once   sync.Once
	err    error
	bySect map[int]map[int]*bagImage
	seen   map[*bagImage]struct{}
	zip    *zip.ReadCloser
}

func (b *renderSprites) init() {
	b.byHandle = make(map[unsafe.Pointer]*Image)
}

func (b *renderSprites) Free() {
	b.bag.Close()
	b.bag = nil
	for _, img := range b.byIndex {
		img.Free()
	}
	b.byIndex = nil
	b.byHandle = make(map[unsafe.Pointer]*Image)
}

func NewRawImage(typ int, data []byte) *Image {
	return &Image{typ: typ, raw: data, nocgo: true}
}

func (b *renderSprites) AsImage(p unsafe.Pointer) *Image {
	if p == nil {
		return nil
	}
	img := b.byHandle[p]
	if img == nil {
		err := fmt.Errorf("unexpected image handle: %x", p)
		imgLog.Printf("%v", err)
	}
	return img
}

func (b *renderSprites) ImageByIndex(ind int) *Image {
	return b.byIndex[ind]
}

func (b *renderSprites) ThingsImageRef(ref *things.ImageRef) *Image {
	if ref == nil {
		return nil
	}
	return b.ImageRef(ref.Ind, byte(ref.Ind2), ref.Name)
}

func (b *renderSprites) ImageRef(ind int, typ byte, name2 string) *Image {
	if ind != -1 {
		return b.ImageByIndex(ind)
	}
	log.Printf("ImageRef(%d, %d, %q)", ind, int(typ), name2)
	return b.LoadExternalImage(typ, name2)
}

func (b *renderSprites) LoadExternalImage(typ byte, name string) *Image {
	// TODO: this one is supposed to load PCX images from FS
	panic("TODO: read PCX from FS")
}

func (b *renderSprites) loadAndIndexVideoBag() error {
	f, err := bag.Open(datapath.Data("video.bag"))
	if err != nil {
		return fmt.Errorf("error reading video bag: %w", err)
	}
	// we don't close it because we will load fallback metadata from it
	//defer f.Close()
	sects, err := f.Segments()
	if err != nil {
		return fmt.Errorf("error reading video bag sections: %w", err)
	}
	b.seen = make(map[*bagImage]struct{})
	b.bySect = make(map[int]map[int]*bagImage)
	for _, s := range sects {
		byOff := make(map[int]*bagImage)
		b.bySect[s.Index] = byOff
		for _, img := range s.Images {
			bi := &bagImage{ImageRec: img}
			byOff[int(img.Offset)] = bi
		}
	}
	if err := b.openVideoZip(); err != nil {
		return err
	}
	return nil
}

func (b *renderSprites) openVideoZip() error {
	zf, err := zip.OpenReader(datapath.Data("video.bag.zip"))
	if os.IsNotExist(err) {
		return nil
	} else if err != nil {
		return err
	}
	b.zip = zf
	return nil
}

func (b *renderSprites) openImage(base string) (image.Image, error) {
	isJPG := false
	f, err := os.Open(base + ".png")
	if os.IsNotExist(err) {
		f, err = os.Open(base + ".jpg")
		isJPG = true
	}
	if os.IsNotExist(err) && b.zip != nil {
		if img, err := b.openImageZip(filepath.Base(base)); err == nil {
			return img, nil
		} else if !os.IsNotExist(err) {
			return nil, err
		}
	}
	if err != nil {
		return nil, err
	}
	defer f.Close()
	if !isJPG {
		return png.Decode(f)
	}
	return jpeg.Decode(f)
}

func (b *renderSprites) openImageMeta(base string) (*pcx.ImageMeta, error) {
	if jdata, err := os.ReadFile(base + ".json"); err == nil {
		var meta pcx.ImageMeta
		if err := json.Unmarshal(jdata, &meta); err != nil {
			return nil, err
		}
		return &meta, nil
	} else if !os.IsNotExist(err) {
		return nil, err
	}
	if b.zip == nil {
		return nil, nil
	}
	zf, err := b.zip.Open(filepath.Base(base) + ".json")
	if os.IsNotExist(err) {
		return nil, nil
	} else if err != nil {
		return nil, err
	}
	defer zf.Close()
	var meta pcx.ImageMeta
	err = json.NewDecoder(zf).Decode(&meta)
	if err != nil {
		return nil, err
	}
	return &meta, nil
}

func (b *renderSprites) openImageZip(base string) (image.Image, error) {
	isJPG := false
	f, err := b.zip.Open(base + ".png")
	if os.IsNotExist(err) {
		f, err = b.zip.Open(base + ".jpg")
		isJPG = true
	}
	if err != nil {
		return nil, err
	}
	defer f.Close()
	if !isJPG {
		return png.Decode(f)
	}
	return jpeg.Decode(f)
}

func (b *renderSprites) ImageByBagSection(sect, offs int) (*pcx.Image, error) {
	b.once.Do(func() {
		if err := b.loadAndIndexVideoBag(); err != nil {
			b.err = err
			log.Println(err)
		}
	})
	if b.err != nil {
		return nil, b.err
	}
	img, ok := b.bySect[sect][offs]
	if !ok {
		return nil, fmt.Errorf("image not found: %d, %d", sect, offs)
	}
	debug := debugBagImages
	if _, ok := b.seen[img]; !ok {
		b.seen[img] = struct{}{}
	} else {
		debug = false
	}
	ext := path.Ext(img.Name)
	base := strings.TrimSuffix(img.Name, ext)
	base = datapath.Data("images", base)
	im, err := b.openImage(base)
	if os.IsNotExist(err) {
		if debug {
			log.Printf("image access miss: %q", base)
		}
		return nil, nil
	} else if err != nil {
		if debug {
			log.Printf("image access error: %q: %v", base, err)
		}
		return nil, err
	}
	out := &pcx.Image{
		Image: im,
	}
	if mat, err := b.openImage(base + "_mat"); err == nil {
		if pal, ok := mat.(*image.Paletted); ok {
			out.Material = pal
		} else {
			log.Printf("image material error: %q: unexpected type: %T", base, mat)
		}
	}
	if meta, err := b.openImageMeta(base); err != nil {
		log.Printf("image meta error: %q: %v", base, err)
	} else if meta != nil {
		out.ImageMeta = *meta
	} else {
		if img.Meta == nil {
			if meta, _, err := img.DecodeHeader(); err == nil {
				img.Meta = meta
			} else {
				if debug {
					log.Printf("error decoding header: %v", err)
				}
				img.Meta = &pcx.ImageMeta{}
			}
		}
		out.ImageMeta = *img.Meta
	}
	if debug {
		log.Printf("image access: %q: type=%d, %dx%d, (%d, %d)",
			base, out.Type, out.Bounds().Dx(), out.Bounds().Dy(), out.Point.X, out.Point.Y)
	}
	return out, nil
}
