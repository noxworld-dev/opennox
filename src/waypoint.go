package nox

/*
extern unsigned int nox_xxx_waypointsHead_2523752;
*/
import "C"
import (
	"strings"
	"unsafe"

	"nox/v1/common/types"
	"nox/v1/server/script"
)

func asWaypoint(p unsafe.Pointer) *Waypoint {
	return (*Waypoint)(p)
}

func firstWaypoint() *Waypoint {
	return asWaypoint(unsafe.Pointer(uintptr(C.nox_xxx_waypointsHead_2523752)))
}

func getWaypointByID(id string) *Waypoint {
	for w := firstWaypoint(); w != nil; w = w.Next() {
		if w.equalID(id) {
			return w
		}
	}
	return nil
}

func getWaypointByInd(ind int) *Waypoint {
	for w := firstWaypoint(); w != nil; w = w.Next() {
		if w.Ind() == ind {
			return w
		}
	}
	return nil
}

func getWaypointGroupByID(id string) *script.WaypointGroup {
	g := getMapGroupByID(id, 1)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Waypoint
	for wp := g.FirstItem(); wp != nil; wp = wp.Next() {
		ind := int(*(*int32)(wp.Payload()))
		if wl := getWaypointByInd(ind); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewWaypointGroup(id, list...)
}

func getWaypoints() []*Waypoint {
	var out []*Waypoint
	for w := firstWaypoint(); w != nil; w = w.Next() {
		out = append(out, w)
	}
	return out
}

type Waypoint [0]byte

func (w *Waypoint) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Waypoint) field(dp uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(unsafe.Pointer(w)) + dp)
}

func (w *Waypoint) Next() *Waypoint {
	p := *(*unsafe.Pointer)(w.field(484))
	return asWaypoint(p)
}

func (w *Waypoint) Ind() int {
	return int(*(*int32)(w.field(0)))
}

func (w *Waypoint) ID() string {
	return GoString((*C.char)(w.field(16)))
}

func (w *Waypoint) equalID(id2 string) bool {
	id := w.ID()
	if id == "" {
		return false
	}
	return id == id2 || strings.HasSuffix(id, ":"+id2)
}

func (w *Waypoint) String() string {
	return "Waypoint(" + w.ID() + ")"
}

func (w *Waypoint) IsEnabled() bool {
	return w != nil && *(*byte)(w.field(480))&0x1 != 0
}

func (w *Waypoint) Enable(enable bool) {
	if enable {
		*(*byte)(w.field(480)) |= 0x1
	} else {
		*(*byte)(w.field(480)) &^= 0x1
	}
}

func (w *Waypoint) Pos() types.Pointf {
	return types.Pointf{
		X: float32(*(*C.float)(w.field(8))),
		Y: float32(*(*C.float)(w.field(12))),
	}
}

func (w *Waypoint) SetPos(p types.Pointf) {
	*(*C.float)(w.field(8)) = C.float(p.X)
	*(*C.float)(w.field(12)) = C.float(p.Y)
}
