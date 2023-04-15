package server

import (
	"image"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type serverWaypoints struct {
	dword_5d4594_2386928 float32
	dword_5d4594_2386948 *Waypoint
	dword_5d4594_2386960 uint32
}

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

func (s *Server) Sub_518460(pos types.Pointf, mask byte, scanSub bool) *Waypoint {
	s.wps.dword_5d4594_2386960++
	s.wps.dword_5d4594_2386928 = 1000.0
	var found *Waypoint
	for r := float32(0.0); r < 1000.0; {
		x1 := RoundCoord(pos.X - r)
		y1 := RoundCoord(pos.Y - r)
		x2 := RoundCoord(pos.X + r)
		y2 := RoundCoord(pos.Y + r)
		s.wps.dword_5d4594_2386948 = nil
		s.sub_518550(image.Rect(x1, y1, x2, y2), pos, mask, scanSub)
		if s.wps.dword_5d4594_2386948 != nil {
			found = s.wps.dword_5d4594_2386948
			r = s.wps.dword_5d4594_2386928
		} else {
			if found != nil {
				return found
			}
			r += 85.0
		}
	}
	return found
}

func (s *Server) sub_518550(rect image.Rectangle, pos types.Pointf, mask byte, scanSub bool) {
	s.Map.Sub518550Base(rect, mask, scanSub, &s.wps.dword_5d4594_2386960, func(it *Waypoint) {
		if dist := pos.Sub(it.Pos()).Len(); dist < float64(s.wps.dword_5d4594_2386928) {
			if s.MapTraceRayAt(pos, it.Pos(), nil, nil, MapTraceFlag1) {
				s.wps.dword_5d4594_2386948 = it
				s.wps.dword_5d4594_2386928 = float32(dist)
			}
		}
	})
}
