package types

type Point struct {
	X int
	Y int
}

func (p Point) Pointf() Pointf {
	return Pointf{
		X: float32(p.X),
		Y: float32(p.Y),
	}
}

type Pointf struct {
	X float32
	Y float32
}

func (p Pointf) Point() Point {
	return Point{
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
