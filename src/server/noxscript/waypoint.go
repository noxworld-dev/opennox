package noxscript

import asm "github.com/noxworld-dev/opennox-lib/script/noxscript/noxasm"

func init() {
	Register(asm.BuiltinWaypoint, nsGetWaypoint)
	Register(asm.BuiltinGetWaypointX, nsWaypointX)
	Register(asm.BuiltinGetWaypointY, nsWaypointY)
	Register(asm.BuiltinIsWaypointOn, nsWaypointIsEnabled)
	Register(asm.BuiltinWaypointOn, nsWaypointOn)
	Register(asm.BuiltinWaypointOff, nsWaypointOff)
	Register(asm.BuiltinWaypointToggle, nsWaypointToggle)
	Register(asm.BuiltinMoveWaypoint, nsWaypointSetPos)

	Register(asm.BuiltinWaypointGroup, nsGetWaypointGroup)
	Register(asm.BuiltinWaypointGroupOn, nsWaypointGroupOn)
	Register(asm.BuiltinWaypointGroupOff, nsWaypointGroupOff)
	Register(asm.BuiltinWaypointGroupToggle, nsWaypointGroupToggle)
}

func nsGetWaypoint(s VM) int {
	name := s.PopString()
	name += s.NameSuff()
	s.PushHandleNS(s.NoxScript().Waypoint(name))
	return 0
}

func nsWaypointX(s VM) int {
	if wp := s.PopWaypointNS(); wp != nil {
		s.PushF32(wp.Pos().X)
	} else {
		s.PushF32(0)
	}
	return 0
}

func nsWaypointY(s VM) int {
	if wp := s.PopWaypointNS(); wp != nil {
		s.PushF32(wp.Pos().Y)
	} else {
		s.PushF32(0)
	}
	return 0
}

func nsWaypointIsEnabled(s VM) int {
	if wp := s.PopWaypointNS(); wp != nil {
		s.PushBool(wp.IsEnabled())
	} else {
		s.PushBool(false)
	}
	return 0
}

func nsWaypointOn(s VM) int {
	if wp := s.PopWaypointNS(); wp != nil {
		wp.Enable(true)
	}
	return 0
}

func nsWaypointOff(s VM) int {
	if wp := s.PopWaypointNS(); wp != nil {
		wp.Enable(false)
	}
	return 0
}

func nsWaypointToggle(s VM) int {
	if wp := s.PopWaypointNS(); wp != nil {
		wp.Toggle()
	}
	return 0
}

func nsWaypointSetPos(s VM) int {
	p := s.PopPointf()
	wp := s.PopWaypointNS()
	dpos := s.DPosf()
	p = p.Add(dpos)
	if wp != nil {
		wp.SetPos(p)
	}
	return 0
}

func nsGetWaypointGroup(s VM) int {
	str := s.PopString()
	str += s.NameSuff()
	s.PushHandleNS(s.NoxScript().WaypointGroup(str))
	return 0
}

func nsWaypointGroupOn(s VM) int {
	if g := s.PopWpGroupNS(); g != nil {
		g.Enable(true)
	}
	return 0
}

func nsWaypointGroupOff(s VM) int {
	if g := s.PopWpGroupNS(); g != nil {
		g.Enable(false)
	}
	return 0
}

func nsWaypointGroupToggle(s VM) int {
	if g := s.PopWpGroupNS(); g != nil {
		g.Toggle()
	}
	return 0
}
