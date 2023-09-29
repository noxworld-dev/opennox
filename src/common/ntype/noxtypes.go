package ntype

type PlayerInd int

type Player interface {
	PlayerIndex() PlayerInd
}

type Point32 struct {
	X, Y int32
}
