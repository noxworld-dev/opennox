package types

import (
	"image"
	"math"
)

func Point2f(p image.Point) Pointf {
	return Pointf{
		X: float32(p.X),
		Y: float32(p.Y),
	}
}

type Point = image.Point

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

type Size struct {
	W int `json:"w"`
	H int `json:"h"`
}

func (s Size) Point() Point {
	return Point{X: s.W, Y: s.H}
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
