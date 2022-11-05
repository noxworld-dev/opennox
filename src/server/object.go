package server

import "github.com/noxworld-dev/opennox-lib/types"

type Obj interface {
	SObj() *Object
}

type Dir16 uint16

func (v Dir16) Vec() types.Pointf {
	x, y := sincosDir(byte(v))
	return types.Pointf{X: x, Y: y}
}

type Object struct {
	_ [772]byte // TODO
}
