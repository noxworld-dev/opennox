package server

import (
	"math"

	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

func (s *Server) PixieFindTarget(u *Object) *Object {
	r := float32(640.0)
	if !noxflags.HasGame(noxflags.GameModeQuest) {
		r = 250.0
	}
	return s.EnemyAggroXxx(u, r, math.MaxFloat32)
}

func PixieIdleAnimate(obj *Object, vec types.Pointf, ddir int) {
	dv := obj.Direction2.Vec()
	dir := int(obj.Direction2)
	if dv.X*vec.Y-dv.Y*vec.X >= 0.0 {
		dir += ddir
		for dir >= 256 {
			dir -= 256
		}
	} else {
		dir -= ddir
		for dir < 0 {
			dir += 256
		}
	}
	obj.Direction2 = Dir16(dir)
}
