package server

import (
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type WaypointSub struct {
	Waypoint *Waypoint
	Ind      byte
	_        [3]byte
}

type Waypoint struct {
	Index     uint32          // 0, 0
	Field1    uint32          // 1, 4
	PosVec    types.Pointf    // 2, 8
	NameBuf   [76]byte        // 4, 16
	Points    [32]WaypointSub // 23, 92
	_         [32]uint32
	PointsCnt byte // 476
	Flags2    byte // 477
	_         [2]byte
	Flags     uint32    // 480
	WpNext    *Waypoint // 484
	WpPrev    *Waypoint // 488
	KeyX      uint16    // 492
	KeyY      uint16    // 494
	Field12   *Waypoint // 496
	Field13   *Waypoint // 500
	Field14   uint32    // 504
	Field15   uint32    // 508
	Field16   uint32    // 512
}

func (w *Waypoint) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Waypoint) ID() string {
	if w == nil {
		return ""
	}
	return alloc.GoStringS(w.NameBuf[:])
}

func (w *Waypoint) SetID(id string) {
	alloc.StrCopyZero(w.NameBuf[:], id)
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

func (w *Waypoint) Toggle() bool {
	w.Flags ^= 0x1
	return w.IsEnabled()
}

func (w *Waypoint) Pos() types.Pointf {
	if w == nil {
		return types.Pointf{}
	}
	return w.PosVec
}

func (w *Waypoint) SetPos(p types.Pointf) {
	w.PosVec = p
}

func (w *Waypoint) HasFlag2Mask(mask byte) bool {
	return mask&w.Flags2 != 0
}
