package noxrender

import (
	"image"
)

func (r *NoxRender) DrawPixel(pos image.Point, cl Color) {
	d := r.Data()
	if d.Clip() && !pos.In(d.ClipRect2()) {
		return
	}
	r.PixBuffer().SetRGBA5551(pos.X, pos.Y, cl)
}

func (r *NoxRender) DrawLineHorizontal(x1, y, x2 int, cl Color) {
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
	for x := xmin; x <= xmax; x++ {
		pix.SetRGBA5551(x, y, cl)
	}
}

func (r *NoxRender) drawLineVertical(x, y1, y2 int, cl Color) {
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
	for y := ymin; y <= ymax; y++ {
		pix.SetRGBA5551(x, y, cl)
	}
}

func (r *NoxRender) DrawPointRad(p image.Point, rad int, cl Color) {
	r.DrawLineHorizontal(p.X, p.Y+rad, p.X, cl)
	r.DrawLineHorizontal(p.X-rad, p.Y, p.X+rad, cl)
	r.DrawLineHorizontal(p.X-rad, p.Y, p.X+rad, cl)
	r.DrawLineHorizontal(p.X, p.Y-rad, p.X, cl)
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
		r.DrawLineHorizontal(x1, p.Y+(xr2-p.X), x2, cl)
		r.DrawLineHorizontal(xr1, p.Y+(x2-p.X), xr2, cl)
		r.DrawLineHorizontal(xr1, p.Y+(x1-p.X), xr2, cl)
		r.DrawLineHorizontal(x1, p.Y+(xr1-p.X), x2, cl)
	}
}

func (r *NoxRender) DrawBorder(x, y, w, h int, cl Color) {
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
	r.DrawLineHorizontal(x, y, x2, cl)
	r.drawLineVertical(x2, y+1, y2, cl)
	r.DrawLineHorizontal(x, y2, x+w-2, cl)
	r.drawLineVertical(x, y+1, y+h-2, cl)
}

func (r *NoxRender) ClearPoints() {
	r.points = r.points[:0]
}

func (r *NoxRender) AddPoint(pos image.Point) {
	r.points = append(r.points, pos)
}

func (r *NoxRender) AddPointRel(pos image.Point) {
	if len(r.points) == 0 {
		return
	}
	r.AddPoint(pos.Add(r.points[len(r.points)-1]))
}

func (r *NoxRender) LastPoint(keep bool) (image.Point, bool) {
	if len(r.points) == 0 {
		return image.Point{}, false
	}
	n := len(r.points)
	pos := r.points[n-1]
	if !keep {
		r.points = r.points[:n-1]
	}
	return pos, true
}

func (r *NoxRender) DrawLineFromPoints(cl Color, arr ...image.Point) bool {
	for _, p := range arr {
		r.AddPoint(p)
	}
	p2, ok := r.LastPoint(false)
	if !ok {
		return false
	}
	p1, ok := r.LastPoint(false)
	if !ok {
		return false
	}
	r.DrawLine(p1, p2, cl)
	return true
}

func (r *NoxRender) DrawVector(base, vec image.Point, cl Color) {
	r.DrawLine(base, base.Add(vec), cl)
}

func (r *NoxRender) DrawLine(p1, p2 image.Point, cl Color) {
	d := r.Data()
	if d.IsAlphaEnabled() {
		r.DrawLineAlpha(p1, p2, cl)
		return
	}

	if d.Clip() && !r.clipToRect2(&p1, &p2) {
		return
	}
	if p1.X == p2.X {
		r.drawLineVertical(p1.X, p1.Y, p2.Y, cl)
		return
	} else if p1.Y == p2.Y {
		r.DrawLineHorizontal(p1.X, p1.Y, p2.X, cl)
		return
	}
	pix := r.PixBuffer()

	y := p1.Y
	w := p2.X - p1.X
	dx := +2
	if p2.X < p1.X {
		dx = -2
		w = p1.X - p2.X
	}
	h := p2.Y - p1.Y
	dy := +1
	if p2.Y < p1.Y {
		dy = -1
		h = p1.Y - p2.Y
	}

	x := 2 * p1.X
	if w < h {
		dv := 2*w - h
		for i := 0; i < h; i++ {
			pix.SetRGBA5551(x/2, y, cl)
			y += dy
			if dv >= 0 {
				dv += 2 * (w - h)
				x += dx
			} else {
				dv += 2 * w
			}
		}
	} else {
		dv := 2*h - w
		for i := 0; i < w; i++ {
			pix.SetRGBA5551(x/2, y, cl)
			x += dx
			if dv >= 0 {
				dv += 2 * (h - w)
				y += dy
			} else {
				dv += 2 * h
			}
		}
	}
}

func (r *NoxRender) DrawLineAlpha(p1, p2 image.Point, cl Color) {
	d := r.Data()
	if d.Clip() && !r.clipToRect2(&p1, &p2) {
		return
	}
	pix := r.PixBuffer()
	alpha := uint16(d.Alpha())
	bc := SplitColor(cl)

	width := p2.X - p1.X
	dx := 1
	if p2.X < p1.X {
		dx = -1
		width = -width
	}
	height := p2.Y - p1.Y
	dy := 1
	if p2.Y < p1.Y {
		dy = -1
		height = -height
	}
	p := p1
	if width < height {
		v := 2*width - height
		for i := 0; i < height; i++ {
			ind := pix.PixOffset(p.X, p.Y)
			c := SplitColor16(pix.Pix[ind])
			pix.Pix[ind] = c.OverAlpha(alpha, bc).Make16()
			p.Y += dy
			if v >= 0 {
				p.X += dx
				v += 2 * (width - height)
			} else {
				v += 2 * width
			}
		}
	} else {
		v := 2*height - width
		for i := 0; i < width; i++ {
			ind := pix.PixOffset(p.X, p.Y)
			c := SplitColor16(pix.Pix[ind])
			pix.Pix[ind] = c.OverAlpha(alpha, bc).Make16()
			p.X += dx
			if v >= 0 {
				v += 2 * (height - width)
				p.Y += dy
			} else {
				v += 2 * height
			}
		}
	}
}

func clipFlags(p image.Point, r image.Rectangle) int {
	flags := 0
	if p.X >= r.Min.X {
		if p.X > r.Max.X {
			flags |= 0x2
		}
	} else {
		flags |= 0x1
	}
	if p.Y >= r.Min.Y {
		if p.Y > r.Max.Y {
			flags |= 0x4
		}
	} else {
		flags |= 0x8
	}
	return flags
}

func clipToRect(r image.Rectangle, p1 *image.Point, p2 image.Point, side bool) bool {
	ds := +1
	if side {
		ds = -1
	}
	if p1.Y < r.Min.Y {
		if p1.Y == p2.Y {
			return false
		}
		dx := (r.Min.Y - p1.Y) * (ds * (p2.X - p1.X)) / (ds * (p2.Y - p1.Y))
		p1.Y = r.Min.Y
		p1.X += dx
	} else if p1.Y > r.Max.Y {
		if p1.Y == p2.Y {
			return false
		}
		dx := (r.Max.Y - p1.Y) * (ds * (p2.X - p1.X)) / (ds * (p2.Y - p1.Y))
		p1.Y = r.Max.Y
		p1.X += dx
	}
	if p1.X > r.Max.X {
		if p1.X == p2.X {
			return false
		}
		dy := (r.Max.X - p1.X) * (ds * (p2.Y - p1.Y)) / (ds * (p2.X - p1.X))
		p1.X = r.Max.X
		p1.Y += dy
	} else if p1.X < r.Min.X {
		if p1.X == p2.X {
			return false
		}
		dy := (r.Min.X - p1.X) * (ds * (p2.Y - p1.Y)) / (ds * (p2.X - p1.X))
		p1.X = r.Min.X
		p1.Y += dy
	}
	return true
}

func (r *NoxRender) clipToRect2(p1, p2 *image.Point) bool {
	d := r.Data()
	rect := d.ClipRect2()
	flag1 := clipFlags(*p1, rect)
	flag2 := clipFlags(*p2, rect)
	if flag1|flag2 == 0 {
		return true
	}
	if flag1&flag2 != 0 {
		return false
	}
	if flag1 != 0 {
		if !clipToRect(rect, p1, *p2, false) {
			return false
		}
	}
	if flag2 != 0 {
		if !clipToRect(rect, p2, *p1, true) {
			return false
		}
	}
	return p1.X >= rect.Min.X && p1.X <= rect.Max.X && p1.Y >= rect.Min.Y && p1.Y <= rect.Max.Y &&
		p2.X >= rect.Min.X && p2.X <= rect.Max.X && p2.Y >= rect.Min.Y && p2.Y <= rect.Max.Y
}

func (r *NoxRender) DrawRectFilledOpaque(x, y, w, h int, cl Color) {
	if w == 0 || h == 0 {
		return
	}
	d := r.Data()
	rx, ry := x, y
	rw, rh := w, h
	if d.Clip() {
		rc := image.Rect(x, y, x+w, y+h)
		out := rc.Intersect(d.ClipRect())
		if out.Empty() {
			return
		}
		ry = out.Min.Y
		rx = out.Min.X
		rw = out.Dx()
		rh = out.Dy()
	}
	sz := r.PixBuffer().Rect
	if rx == 0 && ry == 0 && rw == sz.Dx() && rh == sz.Dy() {
		r.ClearScreen(cl)
	} else {
		r.drawRectFilledOpaque(rx, ry, rw, rh, cl)
	}
}

func (r *NoxRender) drawRectFilledOpaque(x, y, w, h int, cl Color) {
	d := r.Data()
	if d.IsAlphaEnabled() {
		r.drawRectFilledOpaqueOver(x, y, w, h, cl)
		return
	}
	if h <= 0 || w <= 0 {
		return
	}
	pix := r.PixBuffer()
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			pix.SetRGBA5551(x+j, y+i, cl)
		}
	}
}

func (r *NoxRender) drawRectFilledOpaqueOver(x, y, w, h int, cl Color) {
	if w == 0 || h == 0 {
		return
	}
	pix := r.PixBuffer()
	bc := SplitColor(cl)
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			ind := pix.PixOffset(x+j, y+i)
			c := SplitColor16(pix.Pix[ind])
			pix.Pix[ind] = c.Over(bc).Make16()
		}
	}
}

func (r *NoxRender) DrawRectFilledAlpha(x, y, w, h int) {
	d := r.Data()
	if !d.Clip() {
		r.drawRectFilledAlpha(x, y, w, h)
		return
	}
	rc := image.Rect(x, y, x+w, y+h)
	if rc := rc.Intersect(d.ClipRect()); !rc.Empty() {
		r.drawRectFilledAlpha(rc.Min.X, rc.Min.Y, rc.Dx(), rc.Dy())
	}
}

func (r *NoxRender) drawRectFilledAlpha(x, y, w, h int) {
	if w <= 0 || h <= 0 {
		return
	}
	pix := r.PixBuffer()
	const mask = 0xFBDE
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			ind := pix.PixOffset(x+j, y+i)
			pix.Pix[ind] = (mask & pix.Pix[ind]) / 2
		}
	}
}

func (r *NoxRender) DrawPoint(pos image.Point, rad int, cl Color) {
	switch rad {
	case 0, 1:
		r.DrawPixel(pos, cl)
	case 2:
		r.DrawRectFilledOpaque(pos.X, pos.Y, 2, 2, cl)
	case 3:
		r.DrawPixel(pos.Add(image.Point{Y: -1}), cl)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y, 3, 1, cl)
		r.DrawPixel(pos.Add(image.Point{Y: +1}), cl)
	case 4:
		r.DrawRectFilledOpaque(pos.X, pos.Y-1, 2, 1, cl)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y, 4, 2, cl)
		r.DrawRectFilledOpaque(pos.X, pos.Y+2, 2, 1, cl)
	case 5:
		r.DrawRectFilledOpaque(pos.X-1, pos.Y-2, 3, 1, cl)
		r.DrawRectFilledOpaque(pos.X-2, pos.Y-1, 5, 3, cl)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y+2, 3, 1, cl)
	case 6:
		r.DrawRectFilledOpaque(pos.X, pos.Y-2, 2, 1, cl)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y-1, 4, 1, cl)
		r.DrawRectFilledOpaque(pos.X-2, pos.Y, 6, 2, cl)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y+2, 4, 1, cl)
		r.DrawRectFilledOpaque(pos.X, pos.Y+3, 2, 1, cl)
	default:
		r.DrawPointRad(pos, rad/2, cl)
	}
}
