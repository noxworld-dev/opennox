package gui

var AnimSpeed = 1

type AnimState int

const (
	AnimInDone  = AnimState(0)
	AnimOutDone = AnimState(1)
	AnimOut     = AnimState(2)
	AnimIn      = AnimState(3)
)
