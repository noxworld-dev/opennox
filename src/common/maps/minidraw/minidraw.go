// Package minidraw implements functions for drawing simple minimaps based on Nox maps.
package minidraw

import (
	"image"
	"image/color"
	"image/draw"

	"nox/v1/common/maps"
)

func fillImage(img draw.Image, c color.Color) {
	draw.Draw(img, img.Bounds(), image.NewUniform(c), image.Pt(0, 0), draw.Src)
}

// MinimapGray draws a simple gray minimap on a black background.
// Gray levels indicate different wall minimap groups.
func MinimapGray(m *maps.Map) *image.Gray {
	r := m.GridBoundingBox()
	img := image.NewGray(r)
	fillImage(img, color.Black)
	for _, w := range m.Walls() {
		p := w.Pos
		mm := float32(w.Minimap) / 255
		const base = 64
		img.SetGray(int(p.X), int(p.Y), color.Gray{
			Y: base + byte(mm*(255-base)),
		})
	}
	return img
}

// MinimapRGBA draws an RGBA minimap over a given background color.
// If no color is specified, the background will be transparent.
// Wall colors draw by the function indicate wall types, variations and minimap groups.
func MinimapRGBA(m *maps.Map, bg color.Color) *image.RGBA {
	return MinimapRGBAFunc(m, bg, func(w *maps.Wall) color.RGBA {
		mm := float32(w.Minimap) / 255
		va := float32(w.Variant) / 255
		mat := float32(w.Material) / 255
		const base = 64
		return color.RGBA{
			R: base + byte(mm*(255-base)),
			G: 128 + byte(va*(255-128)),
			B: base + byte(mat*(255-base)),
			A: 255,
		}
	})
}

// MinimapRGBAFunc draws an RGBA minimap. It uses a given background color and converts walls to pixels using fnc.
// Background color can be nil, in which case the minimap background will be transparent.
func MinimapRGBAFunc(m *maps.Map, bg color.Color, fnc func(w *maps.Wall) color.RGBA) *image.RGBA {
	r := m.GridBoundingBox()
	img := image.NewRGBA(r)
	if bg != nil && bg != color.Transparent {
		fillImage(img, bg)
	}
	for _, w := range m.Walls() {
		img.SetRGBA(int(w.Pos.X), int(w.Pos.Y), fnc(w))
	}
	return img
}
