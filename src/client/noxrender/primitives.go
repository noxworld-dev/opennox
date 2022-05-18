package noxrender

import (
	"image"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
)

func (r *NoxRender) DrawPixel(pos image.Point) {
	d := r.Data()
	if d.Clip() && !pos.In(d.ClipRect2()) {
		return
	}
	r.PixBuffer().SetRGBA5551(pos.X, pos.Y, noxcolor.RGBA5551(d.Color2()))
}

func (r *NoxRender) DrawLineHorizontal(x1, y, x2 int) {
	xmin, xmax := x1, x2
	if xmin > xmax {
		xmin, xmax = xmax, xmin
	}
	d := r.Data()
	if d.Clip() {
		rect := d.ClipRect2()
		if xmin > rect.Max.X {
			return
		}
		if xmax < rect.Min.X {
			return
		}
		if y < rect.Min.Y || y > rect.Max.Y {
			return
		}
		if xmin < rect.Min.X {
			xmin = rect.Min.X
		}
		if xmax > rect.Max.X {
			xmax = rect.Max.X
		}
	}
	pix := r.PixBuffer()
	cl := noxcolor.RGBA5551(d.Color2())
	for x := xmin; x <= xmax; x++ {
		pix.SetRGBA5551(x, y, cl)
	}
}

func (r *NoxRender) DrawLineVertical(x, y1, y2 int) {
	ymin, ymax := y1, y2
	if ymin > ymax {
		ymin, ymax = ymax, ymin
	}
	d := r.Data()
	if d.Clip() {
		rect := d.ClipRect2()
		if ymin > rect.Max.Y {
			return
		}
		if ymax < rect.Min.Y {
			return
		}
		if x < rect.Min.X || x > rect.Max.X {
			return
		}
		if ymin < rect.Min.Y {
			ymin = rect.Min.Y
		}
		if ymax > rect.Max.Y {
			ymax = rect.Max.Y
		}
	}
	pix := r.PixBuffer()
	cl := noxcolor.RGBA5551(d.Color2())
	for y := ymin; y <= ymax; y++ {
		pix.SetRGBA5551(x, y, cl)
	}
}

func (r *NoxRender) DrawPointRad(p image.Point, rad int) {
	r.DrawLineHorizontal(p.X, p.Y+rad, p.X)
	r.DrawLineHorizontal(p.X-rad, p.Y, p.X+rad)
	r.DrawLineHorizontal(p.X-rad, p.Y, p.X+rad)
	r.DrawLineHorizontal(p.X, p.Y-rad, p.X)
	if rad <= 0 {
		return
	}
	x2 := p.X
	x1 := p.X
	xr2 := p.X + rad
	xr1 := p.X - rad
	v := 1 - rad
	dv1 := 5 - 2*rad
	dv2 := 3
	cr := rad
	for i := 0; i < cr; i++ {
		if v >= 0 {
			v += dv1
			dv1 += 4
			cr--
			xr2--
			xr1++
		} else {
			v += dv2
			dv1 += 2
		}
		x2++
		x1--
		dv2 += 2
		r.DrawLineHorizontal(x1, p.Y+(xr2-p.X), x2)
		r.DrawLineHorizontal(xr1, p.Y+(x2-p.X), xr2)
		r.DrawLineHorizontal(xr1, p.Y+(x1-p.X), xr2)
		r.DrawLineHorizontal(x1, p.Y+(xr1-p.X), x2)
	}
}

func (r *NoxRender) DrawBorder(x, y, w, h int) {
	if w == 0 || h == 0 {
		return
	}
	d := r.Data()
	if d.Clip() {
		rc := image.Rect(x, y, x+w, y+h).Intersect(d.ClipRect())
		if rc.Empty() {
			return
		}
	}
	x2 := x + w - 1
	y2 := y + h - 1
	r.DrawLineHorizontal(x, y, x2)
	r.DrawLineVertical(x2, y+1, y2)
	r.DrawLineHorizontal(x, y2, x+w-2)
	r.DrawLineVertical(x, y+1, y+h-2)
}
