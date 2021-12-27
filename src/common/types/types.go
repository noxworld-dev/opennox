package types

import (
	"image"
	"math"

	"nox/v1/common/noximage"
)

func Point2f(p Point) Pointf {
	return Pointf{
		X: float32(p.X),
		Y: float32(p.Y),
	}
}

type Point = noximage.Point

type Pointf struct {
	X float32 `json:"x"`
	Y float32 `json:"y"`
}

func (p Pointf) Point() image.Point {
	return image.Point{
		X: int(p.X),
		Y: int(p.Y),
	}
}

func (p Pointf) Add(p2 Pointf) Pointf {
	p.X += p2.X
	p.Y += p2.Y
	return p
}

func (p Pointf) Sub(p2 Pointf) Pointf {
	p.X -= p2.X
	p.Y -= p2.Y
	return p
}

func (p Pointf) Mul(v float32) Pointf {
	p.X *= v
	p.Y *= v
	return p
}

func (p Pointf) Len() float64 {
	return math.Sqrt(float64(p.X*p.X + p.Y*p.Y))
}

type Size = noximage.Size

type Sizef struct {
	W float32 `json:"w"`
	H float32 `json:"h"`
}

type Rect struct {
	Left   int
	Top    int
	Right  int
	Bottom int
}

func (r *Rect) IsEmpty() bool {
	return r.Right <= r.Left || r.Bottom <= r.Top
}

type Rectf struct {
	Left   float32
	Top    float32
	Right  float32
	Bottom float32
}

func (r *Rectf) IsEmpty() bool {
	return r.Right <= r.Left || r.Bottom <= r.Top
}

func RectFromPointsf(p1, p2 Pointf) Rectf {
	var r Rectf
	if p1.X >= p2.X {
		r.Left = p2.X
		r.Right = p1.X
	} else {
		r.Left = p1.X
		r.Right = p2.X
	}
	if p1.Y >= p2.Y {
		r.Top = p2.Y
		r.Bottom = p1.Y
	} else {
		r.Top = p1.Y
		r.Bottom = p2.Y
	}
	return r
}

func UtilRectXxx(a2, a3 Rect) (out Rect, _ bool) { // nox_xxx_utilRect_49F930
	left := a3.Left
	if a2.Left >= a3.Left {
		left = a2.Left
	}
	right := a3.Right
	if a2.Right <= right {
		right = a2.Right
	}
	if left >= right {
		return out, false
	}
	top := a3.Top
	if a2.Top >= top {
		top = a2.Top
	}
	bottom := a3.Bottom
	if a2.Bottom <= bottom {
		bottom = a2.Bottom
	}
	if top >= bottom {
		return out, false
	}
	out.Left = left
	out.Top = top
	out.Right = right
	out.Bottom = bottom
	return out, true
}
