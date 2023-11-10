package ntype

import "image"

type PlayerInd int

type Player interface {
	PlayerIndex() PlayerInd
}

type Point32 struct {
	X, Y int32
}

func (p Point32) Point() image.Point {
	return image.Point{X: int(p.X), Y: int(p.Y)}
}
