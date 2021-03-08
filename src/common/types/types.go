package types

import "image"

func Point2f(p image.Point) Pointf {
	return Pointf{
		X: float32(p.X),
		Y: float32(p.Y),
	}
}

type Pointf struct {
	X float32
	Y float32
}

func (p Pointf) Point() image.Point {
	return image.Point{
		X: int(p.X),
		Y: int(p.Y),
	}
}

type Size struct {
	W int
	H int
}

type Sizef struct {
	W float32
	H float32
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
