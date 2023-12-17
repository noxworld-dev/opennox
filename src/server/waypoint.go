package server

import (
	"encoding/json"
	"image"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type serverWaypoints struct {
	List                 *Waypoint
	Pending              *Waypoint
	CntXxx               int
	dword_5d4594_2386928 float32
	dword_5d4594_2386948 *Waypoint
	dword_5d4594_2386960 uint32
}

func (s *serverWaypoints) First() *Waypoint { // nox_xxx_waypointGetList_579860
	return s.List
}

func (s *serverWaypoints) All() []*Waypoint {
	var out []*Waypoint
	for w := s.First(); w != nil; w = w.Next() {
		out = append(out, w)
	}
	return out
}

func (s *serverWaypoints) Nox_xxx_waypoint_5798C0() uint32 {
	nextInd := uint32(1)
	for it := s.List; it != nil; it = it.WpNext {
		if nextInd <= it.Index {
			nextInd = it.Index + 1
		}
	}
	return nextInd
}

func (s *serverWaypoints) Sub_579A30() {
	for wp := s.List; wp != nil; wp = wp.WpNext {
		wp.Flags2 = 0
		for i := 0; i < int(wp.PointsCnt); i++ {
			pt := &wp.Points[i]
			wp.Flags2 |= pt.Ind
		}
		for wp2 := s.List; wp2 != nil; wp2 = wp2.WpNext {
			for i := 0; i < int(wp2.PointsCnt); i++ {
				pt := &wp2.Points[i]
				if pt.Waypoint == wp {
					wp.Flags2 |= pt.Ind
				}
			}
		}
	}
}

func (s *serverWaypoints) Sub_579AD0(pos types.Pointf) *Waypoint {
	var out *Waypoint
	min := float32(100.0)
	for it := s.List; it != nil; it = it.WpNext {
		dx := float64(it.PosVec.X - pos.X)
		dy := float64(it.PosVec.Y - pos.Y)
		dd := dy*dy + dx*dx
		if dd < float64(min) {
			min = float32(dd)
			out = it
		}
	}
	return out
}

func (s *serverWaypoints) Nox_xxx_waypointNewNotMap_579970(ind int, pos types.Pointf) *Waypoint {
	wp, _ := alloc.New(Waypoint{})
	wp.Index = uint32(ind)
	wp.PosVec = pos
	wp.Flags |= 0x1
	wp.WpNext = s.Pending
	s.Pending = wp
	return wp
}

func (s *serverWaypoints) Sub_579890() *Waypoint {
	return s.Pending
}

func (s *serverWaypoints) ByInd(ind int) *Waypoint {
	for it := s.List; it != nil; it = it.WpNext {
		if it.Index == uint32(ind) {
			return it
		}
	}
	return nil
}

func (s *serverWaypoints) ByID(id string) *Waypoint {
	for w := s.List; w != nil; w = w.WpNext {
		if w.EqualID(id) {
			return w
		}
	}
	return nil
}

func (s *serverWaypoints) PendingByInd(ind int) *Waypoint { // sub_579C80
	for it := s.Pending; it != nil; it = it.WpNext {
		if it.Index == uint32(ind) {
			return it
		}
	}
	return nil
}

func (s *serverWaypoints) PendingByIndTmp(id uint32) *Waypoint {
	for it := s.Pending; it != nil; it = it.WpNext {
		if it.Field1 == id {
			return it
		}
	}
	return nil
}

func (s *serverWaypoints) Sub_579D20() {
	ind := s.Nox_xxx_waypoint_5798C0()
	for it := s.Pending; it != nil; it = it.WpNext {
		it.Field1 = it.Index
		it.Index = ind
		ind++
	}
	for it := s.Pending; it != nil; it = it.WpNext {
		j := 0
		for i := 0; i < int(it.PointsCnt); i++ {
			pt := &it.Points[j]
			pt.Waypoint = s.PendingByIndTmp(it.Field348[i])
			if pt.Waypoint != nil {
				j++
			}
		}
		it.PointsCnt = uint8(j)
	}
}

func (s *serverWaypoints) Sub_579CA0() int32 {
	for it := s.Pending; it != nil; it = it.WpNext {
		it.Field1 = it.Index
	}
	for it := s.Pending; it != nil; it = it.WpNext {
		if int32(it.PointsCnt) != 0 {
			for i := 0; i < int(it.PointsCnt); i++ {
				pt := &it.Points[i]
				pt.Waypoint = s.PendingByIndTmp(it.Field348[i])
				if pt.Waypoint == nil {
					return 0
				}
			}
		}
	}
	return 1
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
	Field348  [32]uint32      // 87, 348
	PointsCnt byte            // 119, 476
	Flags2    byte            // 119, 477 // TODO: connection flag
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
	return w.Name()
}

func (w *Waypoint) SetID(id string) {
	w.SetName(id)
}

func (w *Waypoint) Name() string {
	if w == nil {
		return ""
	}
	return alloc.GoStringS(w.NameBuf[:])
}

func (w *Waypoint) SetName(name string) {
	alloc.StrCopyZero(w.NameBuf[:], name)
}

func (w *Waypoint) EqualID(id2 string) bool {
	id := w.ID()
	if id == "" {
		return false
	}
	return id == id2 || strings.HasSuffix(id, ":"+id2)
}

func (w *Waypoint) Next() *Waypoint { // sub_5798A0
	return w.WpNext
}

func (w *Waypoint) Ind() int {
	return int(w.Index)
}

func (w *Waypoint) ScriptID() int {
	return int(w.Index)
}

func (w *Waypoint) WaypointScriptID() int {
	return int(w.Index)
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

func (w *Waypoint) HasFlag2Mask(mask byte) bool { // sub_579EE0
	return mask&w.Flags2 != 0
}

type debugWaypoint struct {
	Ind      int          `json:"ind"`
	ID       string       `json:"id,omitempty"`
	ScriptID int          `json:"script_id,omitempty"`
	Pos      types.Pointf `json:"pos"`
	Flags    uint32       `json:"flags,omitempty"`
	Flags2   byte         `json:"flags2,omitempty"`
}

func (w *Waypoint) dump() *debugWaypoint {
	if w == nil {
		return nil
	}
	return &debugWaypoint{
		Ind:      w.Ind(),
		ID:       w.ID(),
		ScriptID: w.ScriptID(),
		Pos:      w.Pos(),
		Flags:    w.Flags,
		Flags2:   w.Flags2,
	}
}

func (w *Waypoint) MarshalJSON() ([]byte, error) {
	return json.Marshal(w.dump())
}

func (s *Server) NewWaypoint(pos types.Pointf) *Waypoint {
	wp, _ := alloc.New(Waypoint{})
	v3 := s.WPs.Nox_xxx_waypoint_5798C0()
	v4 := int32(wp.Flags)
	wp.Index = v3
	wp.PosVec = pos
	wp.Flags = uint32(v4 | 1)
	wp.WpNext = s.WPs.List
	if s.WPs.List != nil {
		s.WPs.List.WpPrev = wp
	}
	s.WPs.List = wp
	if noxflags.HasGame(1) {
		s.Map.Nox_xxx_waypointMapRegister_5179B0(wp)
	}
	return wp
}

func (s *Server) Sub_579E90(wp *Waypoint) {
	wp.Flags |= 0x1000000
	wp.WpNext = s.WPs.Pending
	if s.WPs.Pending != nil {
		s.WPs.Pending.WpPrev = wp
	}
	s.WPs.Pending = wp
	if noxflags.HasGame(1) {
		s.Map.Nox_xxx_waypointMapRegister_5179B0(wp)
	}
}

func (s *Server) Sub_518460(pos types.Pointf, mask byte, scanSub bool) *Waypoint {
	s.WPs.dword_5d4594_2386960++
	s.WPs.dword_5d4594_2386928 = 1000.0
	var found *Waypoint
	for r := float32(0.0); r < 1000.0; {
		x1 := RoundCoord(pos.X - r)
		y1 := RoundCoord(pos.Y - r)
		x2 := RoundCoord(pos.X + r)
		y2 := RoundCoord(pos.Y + r)
		s.WPs.dword_5d4594_2386948 = nil
		s.sub_518550(image.Rect(x1, y1, x2, y2), pos, mask, scanSub)
		if s.WPs.dword_5d4594_2386948 != nil {
			found = s.WPs.dword_5d4594_2386948
			r = s.WPs.dword_5d4594_2386928
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
	s.Map.Sub518550Base(rect, mask, scanSub, &s.WPs.dword_5d4594_2386960, func(it *Waypoint) {
		if dist := pos.Sub(it.Pos()).Len(); dist < float64(s.WPs.dword_5d4594_2386928) {
			if s.MapTraceRayAt(pos, it.Pos(), nil, nil, MapTraceFlag1) {
				s.WPs.dword_5d4594_2386948 = it
				s.WPs.dword_5d4594_2386928 = float32(dist)
			}
		}
	})
}

func (s *Server) Nox_xxx_waypoint_579F00(out *types.Pointf, obj *Object) int {
	var flag *Object
	if noxflags.HasGame(noxflags.GameModeCTF) && obj != nil {
		for it := s.Objs.First(); it != nil; it = it.Next() {
			if it.Class().Has(object.ClassFlag) && !obj.TeamPtr().SameAs(it.TeamPtr()) {
				flag = it
				break
			}
		}
	}
	s.WPs.CntXxx = 0
	for wp := s.WPs.First(); wp != nil; wp = wp.WpNext {
		if wp.HasFlag2Mask(0x80) && wp.Flags&1 != 0 {
			s.WPs.CntXxx++
		}
	}
	if s.WPs.CntXxx == 0 {
		return 0
	}
	cnt := s.Rand.Logic.IntClamp(0, s.WPs.CntXxx-1)
	for wp := s.WPs.First(); wp != nil; wp = wp.WpNext {
		if !wp.HasFlag2Mask(0x80) {
			continue
		}
		if (wp.Flags & 1) == 0 {
			continue
		}
		if noxflags.HasGame(noxflags.GameModeCTF) && flag != nil && obj != nil {
			v7 := (*types.Pointf)(flag.UpdateData)
			if s.MapTraceRayAt(*v7, wp.PosVec, nil, nil, 9) {
				continue
			}
		}
		if cnt == 0 {
			*out = wp.PosVec
			return 1
		}
		cnt--
	}
	return 0
}

func (s *Server) Nox_xxx_waypointDeleteAll_579DD0() {
	var next *Waypoint
	for it := s.WPs.First(); it != nil; it = next {
		next = it.WpNext
		if noxflags.HasGame(1) {
			s.Map.Sub517A70(it)
		}
		alloc.Free(it)
	}
	s.WPs.List = nil
	s.WPs.Pending = nil
	s.WPs.CntXxx = 0
}

func (s *Server) Nox_xxx_waypoint_5799C0() {
	var next *Waypoint
	for it := s.WPs.Pending; it != nil; it = next {
		next = it.WpNext
		it.WpNext = s.WPs.List
		if s.WPs.List != nil {
			s.WPs.List.WpPrev = it
		}
		s.WPs.List = it
		if noxflags.HasGame(1) {
			s.Map.Nox_xxx_waypointMapRegister_5179B0(it)
		}
	}
	s.WPs.Pending = nil
	s.WPs.Sub_579A30()
}
