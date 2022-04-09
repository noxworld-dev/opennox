package opennox

import (
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
	"testing"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func TestHeatMaps(t *testing.T) {
	vars := memmap.Variables()
	accs := findBlobAccesses(t, noxRoot)
	for _, b := range memmap.Blobs() {
		var bvars []memmap.Variable
		for _, v := range vars {
			if b.Contains(v.Addr) {
				bvars = append(bvars, v)
			}
		}
		var baccs []blobAccess
		for _, a := range accs {
			if b.Addr == a.Blob {
				baccs = append(baccs, a)
			}
		}
		if err := drawBlobHeatMap(b, bvars, accs); err != nil {
			t.Fatal(err)
		}
	}
}

func drawBlobHeatMap(b memmap.Blob, vars []memmap.Variable, accs []blobAccess) error {
	const memLayers = 3
	var (
		clMap   = image.NewUniform(color.RGBA{G: 128, A: 128})
		clAcc   = image.NewUniform(color.RGBA{R: 128, G: 128, A: 128})
		clAccGo = image.NewUniform(color.NRGBA{R: 102, G: 207, B: 221, A: 128})
	)

	img := image.NewRGBA(image.Rect(0, 0, 2048, memLayers*12))
	draw.Draw(img, img.Rect, image.NewUniform(color.Black), image.Point{}, draw.Src)

	rect := img.Bounds()
	w, h := rect.Dx(), rect.Dy()
	mass := float32(w) / float32(b.Size)
	for _, v := range vars {
		off := v.Addr - b.Addr
		if off == 0 && v.Size == b.Size {
			continue
		}
		const li = 0
		x1 := int(float32(off) * mass)
		x2 := int(float32(off+v.Size) * mass)
		y1, y2 := li*(h/memLayers), (li+1)*(h/memLayers)
		draw.Draw(img, image.Rect(x1, y1, x2, y2), clMap, image.Point{}, draw.Over)
	}
	for _, a := range accs {
		off := a.Off
		li := 1
		cl := clAcc
		if a.Go {
			li = 2
			cl = clAccGo
		}
		x1 := int(float32(off) * mass)
		x2 := x1 + 1
		y1, y2 := li*(h/memLayers), (li+1)*(h/memLayers)
		draw.Draw(img, image.Rect(x1, y1, x2, y2), cl, image.Point{}, draw.Over)
	}

	return writePNG(fmt.Sprintf("blob_0x%x.png", b.Addr), img)
}

func writePNG(name string, img image.Image) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}
	defer f.Close()
	if err = png.Encode(f, img); err != nil {
		return err
	}
	return f.Close()
}
