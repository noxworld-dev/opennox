package server

import (
	"bytes"
	"strings"

	"github.com/noxworld-dev/opennox-lib/types"
)

type WaypointSub struct {
	Waypoint *Waypoint
	Ind      byte
	_        [3]byte
}

type Waypoint struct {
	Index     uint32
	Field1    uint32
	PosVec    types.Pointf
	NameBuf   [76]byte
	Points    [32]WaypointSub
	_         [32]uint32
	PointsCnt byte
	Flags2    byte
	_         [2]byte
	Flags     uint32
	WpNext    *Waypoint
	WpPrev    *Waypoint
	KeyX      uint16
	KeyY      uint16
	Field12   *Waypoint
	Field13   *Waypoint
	Field14   uint32
	Field15   uint32
	Field16   uint32
}

func (w *Waypoint) ID() string {
	if w == nil {
		return ""
	}
	arr := w.NameBuf[:]
	i := bytes.IndexByte(arr, 0)
	if i < 0 {
		return string(arr)
	}
	return string(arr[:i])
}

func (w *Waypoint) EqualID(id2 string) bool {
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
	return w != nil && w.Flags&0x1 != 0
}

func (w *Waypoint) Enable(enable bool) {
	if enable {
		w.Flags |= 0x1
	} else {
		w.Flags &^= 0x1
	}
}

func (w *Waypoint) Toggle() {
	w.Flags ^= 0x1
}

func (w *Waypoint) Pos() types.Pointf {
	return w.PosVec
}

func (w *Waypoint) SetPos(p types.Pointf) {
	w.PosVec = p
}
