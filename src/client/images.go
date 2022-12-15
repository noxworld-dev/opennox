package client

import (
	"archive/zip"
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

	"github.com/noxworld-dev/opennox-lib/bag"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/noximage/pcx"
)

var debugBagImages = os.Getenv("NOX_DEBUG_BAG_IMAGES") == "true"

type bagImage struct {
	*bag.ImageRec
	Meta *pcx.ImageMeta
}

type videoBag struct {
	once   sync.Once
	err    error
	bySect map[int]map[int]*bagImage
	seen   map[*bagImage]struct{}
	zip    *zip.ReadCloser
}

func (b *videoBag) loadAndIndexVideoBag() error {
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

func (b *videoBag) openVideoZip() error {
	zf, err := zip.OpenReader(datapath.Data("video.bag.zip"))
	if os.IsNotExist(err) {
		return nil
	} else if err != nil {
		return err
	}
	b.zip = zf
	return nil
}

func (b *videoBag) openImage(base string) (image.Image, error) {
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

func (b *videoBag) openImageMeta(base string) (*pcx.ImageMeta, error) {
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

func (b *videoBag) openImageZip(base string) (image.Image, error) {
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

func (b *videoBag) ImageByBagSection(sect, offs int) (*pcx.Image, error) {
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
