package noxfont

import (
	"bytes"
	"image"
	"image/color"
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"
	"golang.org/x/image/font"
	"golang.org/x/image/math/fixed"

	"nox/v1/common/noxtest"
)

func TestFonts(t *testing.T) {
	path := noxtest.DataPath(t)
	hashes := []string{
		"cbd1d358dc83570f64184a4ac562af12",
		"1539531c8ab5044fd73d89d8729e0e2f",
		"cbd1d358dc83570f64184a4ac562af12",
		"48ab55b27889f81a909b28be5fda5642",
	}
	for i, name := range []string{
		DefaultFile, LargeFile, SmallFile, NumbersFile,
	} {
		t.Run(name, func(t *testing.T) {
			path := filepath.Join(path, name+Ext)
			data, err := os.ReadFile(path)
			require.NoError(t, err)
			fnt, err := Decode(bytes.NewReader(data))
			require.NoError(t, err)
			t.Run("encode", func(t *testing.T) {
				got, err := fnt.Encode()
				require.NoError(t, err)
				require.Equal(t, data, got)
			})
			t.Run("draw", func(t *testing.T) {
				text := "The quick brown fox jumps over the lazy dog."
				if name == NumbersFile {
					text = "0123456789"
				}
				b, _ := font.BoundString(fnt, text)
				dy := (b.Max.Y - b.Min.Y).Ceil()
				img := image.NewGray(image.Rect(0, 0, b.Max.X.Ceil(), dy))
				dr := &font.Drawer{
					Dst:  img,
					Src:  image.NewUniform(color.White),
					Face: fnt,
					Dot:  fixed.P(0, dy),
				}
				dr.DrawString(text)
				noxtest.WritePNG(t, name+".png", img, hashes[i])
			})
		})
	}
}
