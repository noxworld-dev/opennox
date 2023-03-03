package noxscript

import (
	"image"

	"github.com/noxworld-dev/noxscript/ns/asm"
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/common"
)

func init() {
	Register(asm.BuiltinNoWallSound, nsNoWallSound)

	Register(asm.BuiltinWall, nsGetWall)
	Register(asm.BuiltinWallOpen, nsWallOpen)
	Register(asm.BuiltinWallClose, nsWallClose)
	Register(asm.BuiltinWallToggle, nsWallToggle)
	Register(asm.BuiltinWallBreak, nsWallBreak)

	Register(asm.BuiltinWallGroup, nsGetWallGroup)
	Register(asm.BuiltinWallGroupOpen, WallGroupOpen)
	Register(asm.BuiltinWallGroupClose, WallGroupClose)
	Register(asm.BuiltinWallGroupToggle, WallGroupToggle)
	Register(asm.BuiltinWallGroupBreak, WallGroupBreak)
}

func gridUnpack(packed int32) image.Point {
	return image.Pt(int(packed>>16), int(uint16(packed))) // Or, packed & 0xffff
}

func popWall(s VM) ns.WallObj {
	p := gridUnpack(s.PopI32())
	return s.NoxScript().Wall(p.X, p.Y)
}

func nsNoWallSound(s VM) int {
	s.NoxScript().NoWallSound(s.PopBool())
	return 0
}

func nsGetWall(s VM) int {
	p := s.PopPoint()
	if dp := s.DPos(); dp != (image.Point{}) {
		p.X = (common.GridStep*p.X + dp.X) / common.GridStep
		p.Y = (common.GridStep*p.Y + dp.Y) / common.GridStep
	}
	s.PushHandleNS(s.NoxScript().Wall(p.X, p.Y))
	return 0
}

func nsGetWallGroup(s VM) int {
	str := s.PopString()
	str += s.NameSuff()
	s.PushHandleNS(s.NoxScript().WallGroup(str))
	return 0
}

func nsWallOpen(s VM) int {
	if w := popWall(s); w != nil {
		w.Enable(false)
	}
	return 0
}

func nsWallClose(s VM) int {
	if w := popWall(s); w != nil {
		w.Enable(true)
	}
	return 0
}

func nsWallToggle(s VM) int {
	if w := popWall(s); w != nil {
		w.Toggle()
	}
	return 0
}

func nsWallBreak(s VM) int {
	if w := popWall(s); w != nil {
		w.Destroy()
	}
	return 0
}

func WallGroupOpen(s VM) int {
	if g := s.PopWallGroupNS(); g != nil {
		g.Enable(false)
	}
	return 0
}

func WallGroupClose(s VM) int {
	if g := s.PopWallGroupNS(); g != nil {
		g.Enable(true)
	}
	return 0
}

func WallGroupToggle(s VM) int {
	if g := s.PopWallGroupNS(); g != nil {
		g.Toggle()
	}
	return 0
}

func WallGroupBreak(s VM) int {
	if g := s.PopWallGroupNS(); g != nil {
		g.Destroy()
	}
	return 0
}
