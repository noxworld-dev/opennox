package nox

import (
	"archive/zip"
	"encoding/json"
	"fmt"
	"image"
	"image/draw"
	"image/jpeg"
	"image/png"
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
	"strings"
	"sync"

	"nox/v1/common/bag"
	"nox/v1/common/datapath"
	"nox/v1/common/log"
)

var debugBagImages = os.Getenv("NOX_DEBUG_BAG_IMAGES") == "true"

type bagImage struct {
	*bag.ImageRec
	Meta *bag.ImageMeta
}

var videoBag struct {
	once   sync.Once
	err    error
	bySect map[int]map[int]*bagImage
	seen   map[*bagImage]struct{}
	zip    *zip.ReadCloser
}

func loadAndIndexVideoBag() error {
	f, err := bag.Open(datapath.Path("video.bag"))
	if err != nil {
		return fmt.Errorf("error reading video bag: %w", err)
	}
	// we don't close it because we will load fallback metadata from it
	//defer f.Close()
	sects, err := f.Segments()
	if err != nil {
		return fmt.Errorf("error reading video bag sections: %w", err)
	}
	videoBag.seen = make(map[*bagImage]struct{})
	videoBag.bySect = make(map[int]map[int]*bagImage)
	for _, s := range sects {
		byOff := make(map[int]*bagImage)
		videoBag.bySect[s.Index] = byOff
		for _, img := range s.Images {
			bi := &bagImage{ImageRec: img}
			byOff[int(img.Offset)] = bi
		}
	}
	if err := openVideoZip(); err != nil {
		return err
	}
	return nil
}

func openVideoZip() error {
	zf, err := zip.OpenReader(datapath.Path("video.bag.zip"))
	if os.IsNotExist(err) {
		return nil
	} else if err != nil {
		return err
	}
	videoBag.zip = zf
	return nil
}

func openImage(base string) (image.Image, error) {
	isJPG := false
	f, err := os.Open(base + ".png")
	if os.IsNotExist(err) {
		f, err = os.Open(base + ".jpg")
		isJPG = true
	}
	if os.IsNotExist(err) && videoBag.zip != nil {
		if img, err := openImageZip(filepath.Base(base)); err == nil {
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

func openImageMeta(base string) (*bag.ImageMeta, error) {
	if jdata, err := ioutil.ReadFile(base + ".json"); err == nil {
		var meta bag.ImageMeta
		if err := json.Unmarshal(jdata, &meta); err != nil {
			return nil, err
		}
		return &meta, nil
	} else if !os.IsNotExist(err) {
		return nil, err
	}
	if videoBag.zip == nil {
		return nil, nil
	}
	zf, err := videoBag.zip.Open(filepath.Base(base) + ".json")
	if os.IsNotExist(err) {
		return nil, nil
	} else if err != nil {
		return nil, err
	}
	defer zf.Close()
	var meta bag.ImageMeta
	err = json.NewDecoder(zf).Decode(&meta)
	if err != nil {
		return nil, err
	}
	return &meta, nil
}

func openImageZip(base string) (image.Image, error) {
	isJPG := false
	f, err := videoBag.zip.Open(base + ".png")
	if os.IsNotExist(err) {
		f, err = videoBag.zip.Open(base + ".jpg")
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

func asRGBA(img image.Image) *image.RGBA {
	if rgba, ok := img.(*image.RGBA); ok {
		return rgba
	}
	rgba := image.NewRGBA(img.Bounds())
	draw.Draw(rgba, rgba.Rect, img, img.Bounds().Min, draw.Src)
	return rgba
}

func imageByBagSection(sect, offs int) (*bag.Image, error) {
	videoBag.once.Do(func() {
		if err := loadAndIndexVideoBag(); err != nil {
			videoBag.err = err
			log.Println(err)
		}
	})
	if videoBag.err != nil {
		return nil, videoBag.err
	}
	img, ok := videoBag.bySect[sect][offs]
	if !ok {
		return nil, fmt.Errorf("image not found: %d, %d", sect, offs)
	}
	debug := debugBagImages
	if _, ok := videoBag.seen[img]; !ok {
		videoBag.seen[img] = struct{}{}
	} else {
		debug = false
	}
	ext := path.Ext(img.Name)
	base := strings.TrimSuffix(img.Name, ext)
	base = datapath.Path("images", base)
	im, err := openImage(base)
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
	out := &bag.Image{
		RGBA: *asRGBA(im),
	}
	if mask, err := openImage(base + "_mask"); err == nil {
		out.Mask = asRGBA(mask)
	}
	if meta, err := openImageMeta(base); err != nil {
		log.Printf("image meta error: %q: %v", base, err)
	} else if meta != nil {
		out.ImageMeta = *meta
	} else {
		if img.Meta == nil {
			if meta, err := img.DecodeHeader(); err == nil {
				img.Meta = meta
			} else {
				if debug {
					log.Printf("error decoding header: %v", err)
				}
				img.Meta = &bag.ImageMeta{}
			}
		}
		out.ImageMeta = *img.Meta
	}
	if debug {
		log.Printf("image access: %q: type=%d, %dx%d, (%d, %d)",
			base, out.Type, out.Rect.Dx(), out.Rect.Dy(), out.Point.X, out.Point.Y)
	}
	return out, nil
}
