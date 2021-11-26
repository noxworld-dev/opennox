package maprender

import (
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"path/filepath"

	"nox/v1/common"
	"nox/v1/common/bag"
	"nox/v1/common/maps"
	"nox/v1/common/noximage/pcx"
	"nox/v1/common/things"
)

// DrawMap is a helper for drawing a single map. For multiple maps it's more efficient to use Renderer.
func DrawMap(datadir string, m *maps.Map, opts *Options) (*image.RGBA, error) {
	r, err := NewRenderer(datadir)
	if err != nil {
		return nil, err
	}
	defer r.Close()
	return r.DrawMap(m, opts)
}

// NewRenderer creates a Nox map renderer based on a given Nox data dir.
// The renderer can be sued to draw multiple maps.
func NewRenderer(datadir string) (*Renderer, error) {
	tng, err := things.Open(filepath.Join(datadir, "thing.bin"))
	if err != nil {
		return nil, err
	}
	bg, err := bag.Open(filepath.Join(datadir, "video.bag"))
	if err != nil {
		_ = tng.Close()
		return nil, err
	}
	r := &Renderer{tng: tng, bag: bg}
	if err = r.indexThingWalls(); err != nil {
		_ = r.Close()
		return nil, err
	}
	if err = r.indexBagImages(); err != nil {
		_ = r.Close()
		return nil, err
	}
	return r, nil
}

// Renderer is a Nox map renderer.
type Renderer struct {
	tng        *things.File
	bag        *bag.File
	wallByMat  map[int]*things.Wall
	images     []*bag.ImageRec
	imageByInd map[int]*pcx.Image
}

// Close the renderer,
func (r *Renderer) Close() error {
	_ = r.tng.Close()
	_ = r.bag.Close()
	return nil
}

func (r *Renderer) indexThingWalls() error {
	wallvar, err := r.tng.ReadWalls()
	if err != nil {
		return err
	}
	r.wallByMat = make(map[int]*things.Wall)
	for i := range wallvar {
		r.wallByMat[i] = &wallvar[i]
	}
	return nil
}

func (r *Renderer) indexBagImages() error {
	imgs, err := r.bag.Images()
	if err != nil {
		return err
	}
	r.images = imgs
	r.imageByInd = make(map[int]*pcx.Image)
	return nil
}

func (r *Renderer) getImage(ind int) (image.Image, image.Point, error) {
	img, ok := r.imageByInd[ind]
	if !ok {
		var err error
		img, err = r.images[ind].Decode()
		if err != nil {
			return nil, image.Point{}, err
		}
		r.imageByInd[ind] = img
	}
	return &img.RGBA, img.Point, nil
}

func (r *Renderer) getWallImage(w *maps.Wall) (image.Image, image.Point, error) {
	wt := r.wallByMat[int(w.Material)]
	wd := wt.Directions[w.Dir]
	vi := w.Variant / 2
	ii := w.Variant % 2
	if int(vi) >= len(wd.Variants) {
		return nil, image.Point{}, fmt.Errorf("wall variant out of bounds: %d", vi)
	}
	wv := wd.Variants[vi]
	wi := wv.Images[ii]
	ind := wi.Img.Ind
	img, pt, err := r.getImage(ind)
	if err == nil {
		pt = pt.Sub(wi.Pt)
	}
	return img, pt, err
}

type Options struct {
	FailFast bool // return on the first error
	NoFloor  bool // do not draw floor tiles
	NoWalls  bool // do not draw walls
}

// DrawMapFile reads and renders the map file. See DrawMap for details.
// As opposed to DrawMap, the returned image may be nil in case map decoding fails.
func (r *Renderer) DrawMapFile(dir string, opts *Options) (*image.RGBA, error) {
	m, err := maps.ReadMap(dir)
	if err != nil {
		return nil, err
	}
	return r.DrawMap(m, opts)
}

// DrawMap renders the map. It will keep processing the map and return a partial image in case of an error.
// If FailFast option is set, it will fail on the first error instead of returning the last one.
// Passing nil options will use defaults.
func (r *Renderer) DrawMap(m *maps.Map, opts *Options) (*image.RGBA, error) {
	if opts == nil {
		opts = &Options{}
	}
	bb := m.GridBoundingBox()

	// give some space for tiles on the map boundaries
	bb.Min = bb.Min.Add(image.Pt(0, -1))
	bb.Max = bb.Max.Add(image.Pt(4, 3))

	// convert grid coordinates to pixels
	bb.Min.X *= common.GridStep
	bb.Min.Y *= common.GridStep
	bb.Max.X *= common.GridStep
	bb.Max.Y *= common.GridStep

	out := image.NewRGBA(bb)
	// black background
	draw.Draw(out, out.Rect, image.NewUniform(color.Black), image.Pt(0, 0), draw.Src)

	var last error
	if !opts.NoFloor {
		if err := r.drawTiles(out, m, opts); err != nil {
			last = err
			if opts.FailFast {
				return out, last
			}
		}
	}
	if !opts.NoWalls {
		if err := r.drawWalls(out, m, opts); err != nil {
			last = err
			if opts.FailFast {
				return out, last
			}
		}
	}
	return out, last
}

func (r *Renderer) drawTiles(out draw.Image, m *maps.Map, opts *Options) error {
	// TODO: tiles
	return nil
}

func (r *Renderer) drawWalls(out draw.Image, m *maps.Map, opts *Options) error {
	var last error
	for _, w := range m.Walls() {
		img, pt, err := r.getWallImage(w)
		if err != nil {
			last = err
			if opts.FailFast {
				return last
			}
			continue
		}
		p := image.Pt(
			int(w.Pos.X)*common.GridStep+pt.X,
			int(w.Pos.Y)*common.GridStep+pt.Y,
		)
		rect := img.Bounds()
		draw.Draw(out, image.Rect(p.X, p.Y, p.X+rect.Dx(), p.Y+rect.Dy()), img, image.Pt(0, 0), draw.Over)
	}
	return last
}
