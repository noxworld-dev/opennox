package noxrender

import (
	"bytes"
	"crypto/md5"
	"encoding/hex"
	"image"
	"image/draw"
	"image/png"
	"io"
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"
)

var particleCases = []struct {
	name string
	opt  particleOpt
	exp  string
}{
	{
		name: "white",
		opt:  particleOpt{rad: 10, blur: 0, intens: 0xff, color: RGB{0xff, 0xff, 0xff}},
		exp:  "6e3837c001f5a381cbd4782670c720b3",
	},
	{
		name: "green",
		opt:  particleOpt{rad: 10, blur: 0, intens: 0xff, color: RGB{140, 220, 80}},
		exp:  "1b05032774d7e7844c344a7407d110b0",
	},
	{
		name: "white3",
		opt:  particleOpt{rad: 10, blur: 3, intens: 0xff, color: RGB{0xff, 0xff, 0xff}},
		exp:  "e142606bc079722e906ca7dcfd6ec028",
	},
	{
		name: "green3",
		opt:  particleOpt{rad: 10, blur: 3, intens: 0xff, color: RGB{140, 220, 80}},
		exp:  "ddc81813a16118c94748af5b238dcea0",
	},
	{
		name: "white32",
		opt:  particleOpt{rad: 10, blur: 32, intens: 0x80, color: RGB{0xff, 0xff, 0xff}},
		exp:  "67112c5925f52475b777284ae29f754b",
	},
	{
		name: "green32",
		opt:  particleOpt{rad: 10, blur: 32, intens: 0x80, color: RGB{140, 220, 80}},
		exp:  "d3edce3ebc525291df9b7a610c9bfd38",
	},
}

func TestDrawParticle(t *testing.T) {
	debug := os.Getenv("NOX_RENDER_DEBUG") == "true"
	var (
		h   = md5.New()
		buf bytes.Buffer
	)
	const outDir = ".testOut"
	if debug {
		err := os.MkdirAll(outDir, 0755)
		require.NoError(t, err)
	}
	for _, c := range particleCases {
		t.Run(c.name, func(t *testing.T) {
			img := genParticle(c.opt)
			off, sz, _ := img.Meta()
			csz := image.Point{
				X: (sz.X + off.X) * 2,
				Y: (sz.Y + off.Y) * 2,
			}
			pos := image.Pt(sz.X/2, sz.Y/2)

			pix := newBlack16(csz.X, csz.Y)
			d := newRenderData(csz.X, csz.Y)

			r := NewRender(nil)
			r.SetPixBuffer(pix)
			r.SetData(d)

			r.DrawImage16(img, pos)

			h.Reset()
			buf.Reset()

			var w io.Writer = h
			if debug {
				fname := filepath.Join(outDir, "part_"+c.name+".png")
				out, err := os.Create(fname)
				require.NoError(t, err)
				defer out.Close()
				w = io.MultiWriter(w, out)
			}
			err := png.Encode(w, pix)
			require.NoError(t, err)

			got := hex.EncodeToString(h.Sum(nil))
			skip := false
			if c.exp == "" {
				skip = true
				t.Logf("%q", got)
			} else {
				require.Equal(t, c.exp, got)
			}
			if debug {
				rgba := image.NewNRGBA(pix.Rect)
				draw.Draw(rgba, pix.Rect, pix, image.Pt(0, 0), draw.Src)
				h.Reset()
				h.Write(rgba.Pix)
				rgbaHex := hex.EncodeToString(h.Sum(nil))
				t.Logf("RGBA32: %q", rgbaHex)
			}
			if skip {
				t.SkipNow()
			}
		})
	}
}
