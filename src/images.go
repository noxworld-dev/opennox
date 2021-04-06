package main

import (
	"encoding/json"
	"fmt"
	"image"
	"image/draw"
	"image/jpeg"
	"image/png"
	"io/ioutil"
	"log"
	"os"
	"path"
	"path/filepath"
	"strings"
	"sync"

	"nox/common/bag"
)

var debugBagImages = os.Getenv("NOX_DEBUG_BAG_IMAGES") == "true"

var videoBag struct {
	once   sync.Once
	err    error
	bySect map[int]map[int]*bag.ImageRec
	seen   map[*bag.ImageRec]struct{}
}

func loadAndIndexVideoBag() error {
	f, err := bag.Open(filepath.Join(getDataPath(), "video.bag"))
	if err != nil {
		return fmt.Errorf("error reading video bag: %w", err)
	}
	defer f.Close()
	sects, err := f.Segments()
	if err != nil {
		return fmt.Errorf("error reading video bag sections: %w", err)
	}
	videoBag.seen = make(map[*bag.ImageRec]struct{})
	videoBag.bySect = make(map[int]map[int]*bag.ImageRec)
	for _, s := range sects {
		byOff := make(map[int]*bag.ImageRec)
		videoBag.bySect[s.Index] = byOff
		for _, img := range s.Images {
			byOff[int(img.Offset)] = img
		}
	}
	return nil
}

func openImage(base string) (image.Image, error) {
	isJPG := false
	f, err := os.Open(base + ".png")
	if os.IsNotExist(err) {
		f, err = os.Open(base + ".jpg")
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
	base = filepath.Join(getDataPath(), "images", base)
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
	if jdata, err := ioutil.ReadFile(base + ".json"); err == nil {
		if err := json.Unmarshal(jdata, &out.ImageMeta); err != nil {
			log.Printf("image meta error: %q: %v", base, err)
		}
	}
	if debug {
		log.Printf("image access: %q: type=%d, %dx%d, (%d, %d)",
			base, out.Type, out.Rect.Dx(), out.Rect.Dy(), out.Point.X, out.Point.Y)
	}
	return out, nil
}
