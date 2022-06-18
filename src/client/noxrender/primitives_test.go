package noxrender

import (
	"image"
	"image/png"
	"math"
	"os"
	"testing"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
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

	cl := noxcolor.RGB5551Color(200, 50, 25)
	for i := 0; i < 5; i++ {
		r.DrawCircleOpaque(70, 70, 10+10*i, cl)
	}
	cl2 := noxcolor.RGB5551Color(0, 255, 25)
	for i := 0; i < 5; i++ {
		r.DrawCircleAlpha(21, 20, 10+10*i, cl2)
	}
	cl3 := noxcolor.RGB5551Color(0, 0, 255)
	cl4 := noxcolor.RGB5551Color(255, 255, 0)
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

func TestDrawLines(t *testing.T) {
	sz := image.Pt(100, 100)
	d := newRenderData(sz.X, sz.Y)
	img := noximage.NewImage16(image.Rectangle{Max: sz})
	r := NewRender()
	r.SetPixBuffer(img)
	r.SetData(d)
	c := sz.Div(2)

	cl := noxcolor.RGB5551Color(200, 50, 25)
	for a := 0; a < 360; a += 15 {
		dx := int(30 * math.Cos(math.Pi*float64(a)/180))
		dy := int(30 * math.Sin(math.Pi*float64(a)/180))
		r.DrawLine(c, c.Add(image.Pt(dx, dy)), cl)
	}
	cl2 := noxcolor.RGB5551Color(0, 255, 25)
	c = c.Add(image.Pt(10, -10))
	d.alpha = 0x80
	d.alphaEnabled = true
	for a := 0; a < 360; a += 15 {
		dx := int(15 * math.Cos(math.Pi*float64(a)/180))
		dy := int(15 * math.Sin(math.Pi*float64(a)/180))
		r.DrawLine(c, c.Add(image.Pt(dx, dy)), cl2)
	}

	f, err := os.Create("lines.png")
	require.NoError(t, err)
	defer f.Close()
	err = png.Encode(f, img)
	require.NoError(t, err)
}
