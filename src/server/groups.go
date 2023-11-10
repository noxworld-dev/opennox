package server

import (
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type ServerMapGroups struct {
	AllocGroup alloc.ClassT[MapGroup]
	AllocItem  alloc.ClassT[MapGroupItem]
	groups     *MapGroup
	Refs       *MapGroupRef
}

func (s *ServerMapGroups) GetFirstMapGroup() *MapGroup { // nox_server_getFirstMapGroup_57C080
	return s.groups
}

func (s *ServerMapGroups) Init() {
	s.AllocGroup = alloc.NewClassT("ItemGroupInfo", MapGroup{}, 512)
	s.AllocItem = alloc.NewClassT("ItemGroupElement", MapGroupItem{}, 5000)
}

func (s *ServerMapGroups) Reset() {
	s.AllocItem.FreeAllObjects()
	s.AllocGroup.FreeAllObjects()
	s.groups = nil
}

func (s *ServerMapGroups) Free() {
	if s.AllocGroup.Class != nil {
		s.AllocGroup.Free()
	}
	if s.AllocItem.Class != nil {
		s.AllocItem.Free()
	}
	s.groups = nil
}

func (s *ServerMapGroups) sub57C330() *MapGroup {
	if !noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
		return nil
	}
	return s.AllocGroup.NewObject()
}

func (s *ServerMapGroups) AddNewMapGroup57C3B0(p *MapGroup) {
	p.prev = nil
	p.next = s.groups
	if head := s.groups; head != nil {
		head.prev = p
	}
	s.groups = p
}

func (s *ServerMapGroups) NextMapGroupIndex() uint32 {
	var max uint32
	for it := s.GetFirstMapGroup(); it != nil; it = it.Next() {
		if it.Ind+1 > max {
			max = it.Ind + 1
		}
	}
	return max
}

func (s *ServerMapGroups) Sub504600(name string, ind uint32, typ uint8) {
	g := s.sub57C330()
	if g == nil {
		return
	}
	p, _ := alloc.New(MapGroupRef{})
	p.Field0 = g
	p.Next4 = s.Refs
	p.Prev8 = nil
	if head := s.Refs; head != nil {
		head.Prev8 = p
	}
	s.Refs = p
	g.next = nil
	g.prev = nil
	g.List = nil
	g.Ind = ind
	g.TypeVal = typ
	alloc.StrCopyZero(g.name[:], name)
}

func (s *ServerMapGroups) Sub57C130(arg []uint32, ind uint32) int32 {
	if arg == nil {
		return 0
	}
	if s.groups == nil {
		return 0
	}
	var found *MapGroup
	for g := s.groups; g != nil; g = g.next {
		if g.Ind == ind {
			found = g
			break
		}
	}
	if found == nil {
		return 0
	}
	g := found
	it := s.AllocItem.NewObject()
	if it == nil {
		return 0
	}
	switch g.GroupType() {
	case MapGroupWalls:
		it.Raw0 = arg[0]
		it.Raw4 = arg[1]
	case MapGroupObjects, MapGroupWaypoints, MapGroupGroups:
		it.Raw0 = arg[0]
	default:
		s.AllocItem.FreeObjectFirst(it)
		return 0
	}
	it.Next8 = g.List
	it.Prev12 = nil
	if head := g.List; head != nil {
		head.Prev12 = it
	}
	g.List = it
	return 1
}

func (s *ServerMapGroups) Sub5046A0(arg []uint32, ind uint32) int {
	if arg == nil {
		return 0
	}
	var found *MapGroupRef
	for v2 := s.Refs; v2 != nil; v2 = v2.Next4 {
		if v2.Field0.Ind == ind {
			found = v2
			break
		}
	}
	if found == nil {
		return 0
	}
	v2 := found
	v4 := s.AllocItem.NewObject()
	if v4 == nil {
		return 0
	}
	switch v2.Field0.GroupType() {
	case MapGroupWalls:
		v4.Raw0 = arg[0]
		v4.Raw4 = arg[1]
	case MapGroupObjects, MapGroupWaypoints, MapGroupGroups:
		v4.Raw0 = arg[0]
	default:
		return 0
	}
	v4.Prev12 = nil
	v4.Next8 = v2.Field0.List
	if head := v2.Field0.List; head != nil {
		head.Prev12 = v4
	}
	v2.Field0.List = v4
	return 1
}

func (s *ServerMapGroups) MapLoadAddGroup57C0C0(name string, ind uint32, typ byte) int32 {
	p := s.sub57C330()
	if p == nil {
		return 0
	}
	p.Ind = ind
	p.TypeVal = typ
	alloc.StrCopyZero(p.name[:], name)
	p.List = nil
	head := s.groups
	p.prev = nil
	p.next = head
	if s.groups != nil {
		s.groups.prev = p
	}
	s.groups = p
	return 1
}

func (s *ServerMapGroups) GroupByInd(ind int) *MapGroup {
	for p := s.GetFirstMapGroup(); p != nil; p = p.Next() {
		if int(p.Index()) == ind {
			return p
		}
	}
	return nil
}

type MapGroupKind byte

const (
	MapGroupObjects   = MapGroupKind(0)
	MapGroupWaypoints = MapGroupKind(1)
	MapGroupWalls     = MapGroupKind(2)
	MapGroupGroups    = MapGroupKind(3)
)

type MapGroupRef struct {
	Field0 *MapGroup
	Next4  *MapGroupRef
	Prev8  *MapGroupRef
}

type MapGroupItem struct {
	Raw0   uint32
	Raw4   uint32
	Next8  *MapGroupItem
	Prev12 *MapGroupItem
}

func (it *MapGroupItem) C() unsafe.Pointer {
	return unsafe.Pointer(it)
}

func (it *MapGroupItem) Data1() int {
	return int(it.Raw0)
}

func (it *MapGroupItem) Data2() int {
	return int(it.Raw4)
}

func (it *MapGroupItem) Next() *MapGroupItem {
	return it.Next8
}

type MapGroup struct {
	TypeVal byte // 0, 0
	_       [3]byte
	Ind     uint32        // 1, 4
	name    [76]byte      // 2, 8
	List    *MapGroupItem // 21, 84
	next    *MapGroup     // 22, 88
	prev    *MapGroup     // 23, 92
}

func (g *MapGroup) C() unsafe.Pointer {
	return unsafe.Pointer(g)
}

// GroupType gets the group type (non-recursively).
func (g *MapGroup) GroupType() MapGroupKind {
	return MapGroupKind(g.TypeVal)
}

func (g *MapGroup) Index() uint32 {
	return g.Ind
}

func (g *MapGroup) ID() string {
	return alloc.GoStringS(g.name[:])
}

func (g *MapGroup) SetID(v string) {
	alloc.StrCopyZero(g.name[:], v)
}

func (g *MapGroup) Next() *MapGroup {
	if g == nil {
		return nil
	}
	return g.next
}

func (g *MapGroup) First() *MapGroupItem {
	if g == nil {
		return nil
	}
	return g.List
}
