package types

import "image"

func Point2f(p image.Point) Pointf {
	return Pointf{
		X: float32(p.X),
		Y: float32(p.Y),
	}
}

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

type Size struct {
	W int `json:"w"`
	H int `json:"h"`
}

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
