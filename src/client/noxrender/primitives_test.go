package noxrender

import (
	"image"
	"image/png"
	"os"
	"testing"

	"github.com/noxworld-dev/opennox-lib/noximage"
	"github.com/stretchr/testify/require"
)

func TestDrawCircle(t *testing.T) {
	sz := image.Pt(100, 100)
	d := newRenderData(sz.X, sz.Y)
	img := noximage.NewImage16(image.Rectangle{Max: sz})
	r := NewRender()
	r.SetPixBuffer(img)
	r.SetData(d)

	cl := ColorRGB(200, 50, 25)
	for i := 0; i < 5; i++ {
		r.DrawCircleOpaque(70, 70, 10+10*i, cl)
	}
	cl2 := ColorRGB(0, 255, 25)
	for i := 0; i < 5; i++ {
		r.DrawCircleAlpha(21, 20, 10+10*i, cl2)
	}
	cl3 := ColorRGB(0, 0, 255)
	cl4 := ColorRGB(255, 255, 0)
	d.clip = true
	d.clipRect = image.Rect(20, 20, 70, 70)
	for i := 0; i < 5; i++ {
		r.DrawCircleOpaque(70, 20, 10+10*i, cl3)
		r.DrawCircleAlpha(20, 70, 10+10*i, cl4)
	}

	f, err := os.Create("circles.png")
	require.NoError(t, err)
	defer f.Close()
	err = png.Encode(f, img)
	require.NoError(t, err)
}
