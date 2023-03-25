package ntype

type PlayerInd int

type Player interface {
	PlayerIndex() PlayerInd
}
