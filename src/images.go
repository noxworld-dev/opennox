package main

import (
	"encoding/json"
	"fmt"
	"image"
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

var videoBag struct {
	once   sync.Once
	err    error
	bySect map[int]map[int]*bag.Image
	seen   map[*bag.Image]struct{}
}

func loadAndIndexVideoBag() error {
	f, err := bag.Open(filepath.Join(getDataPath(), "video.bag"))
	if err != nil {
		return fmt.Errorf("error reading video bag: %w", err)
	}
	sects, err := f.Segments()
	if err != nil {
		return fmt.Errorf("error reading video bag sections: %w", err)
	}
	videoBag.seen = make(map[*bag.Image]struct{})
	videoBag.bySect = make(map[int]map[int]*bag.Image)
	for _, s := range sects {
		byOff := make(map[int]*bag.Image)
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

func imageByBagSection(sect, offs int) (image.Image, image.Point, error) {
	videoBag.once.Do(func() {
		if err := loadAndIndexVideoBag(); err != nil {
			videoBag.err = err
			log.Println(err)
		}
	})
	if videoBag.err != nil {
		return nil, image.Point{}, videoBag.err
	}
	img, ok := videoBag.bySect[sect][offs]
	if !ok {
		return nil, image.Point{}, fmt.Errorf("image not found: %d, %d", sect, offs)
	}
	if _, ok := videoBag.seen[img]; !ok {
		videoBag.seen[img] = struct{}{}
		log.Printf("image access: %q", img.Name)
	}
	ext := path.Ext(img.Name)
	base := strings.TrimSuffix(img.Name, ext)
	base = filepath.Join(getDataPath(), "images", base)
	im, err := openImage(base)
	if os.IsNotExist(err) {
		return nil, image.Point{}, nil
	} else if err != nil {
		return nil, image.Point{}, err
	}
	var pt image.Point
	if jdata, err := ioutil.ReadFile(base + ".json"); err == nil {
		if err := json.Unmarshal(jdata, &pt); err != nil {
			return nil, image.Point{}, err
		}
	}
	return im, pt, nil
}
