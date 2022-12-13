package opennox

/*
#include <stdint.h>
extern void* dword_5d4594_2523756;
extern uint32_t dword_5d4594_3835312;
int  nox_server_scriptGetGroupId_57C2D0(int** a1);
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

//export nox_server_getFirstMapGroup_57C080
func nox_server_getFirstMapGroup_57C080() unsafe.Pointer {
	return noxServer.mapGroups.getFirstMapGroup().C()
}

//export nox_server_scriptGetGroup_57C0A0
func nox_server_scriptGetGroup_57C0A0(a1 C.int) unsafe.Pointer {
	return noxServer.mapGroups.GroupByInd(int(a1)).C()
}

//export sub_504600
func sub_504600(name *C.char, ind uint32, typ uint8) {
	noxServer.mapGroups.sub504600(GoString(name), ind, typ)
}

//export sub_57C130
func sub_57C130(d *uint32, ind uint32) int32 {
	var arg []uint32
	if d != nil {
		arg = unsafe.Slice(d, 2)
	}
	return noxServer.mapGroups.sub57C130(arg, ind)
}

//export sub_5046A0
func sub_5046A0(d *uint32, ind uint32) int {
	var arg []uint32
	if d != nil {
		arg = unsafe.Slice(d, 2)
	}
	return noxServer.mapGroups.sub5046A0(arg, ind)
}

//export sub_4CFFE0
func sub_4CFFE0(sid int) *nox_object_t {
	return noxServer.pendingObjByScriptID4CFFE0(sid).CObj()
}

//export sub_579C60
func sub_579C60(id uint32) *nox_waypoint_t {
	return noxServer.pendingWaypointByInd579C60(id).C()
}

//export nox_server_mapLoadAddGroup_57C0C0
func nox_server_mapLoadAddGroup_57C0C0(name *C.char, ind uint32, typ byte) int32 {
	return noxServer.mapGroups.mapLoadAddGroup57C0C0(GoString(name), ind, typ)
}

//export sub_504720
func sub_504720(a1, a2 uint32) int32 {
	return noxServer.sub504720(a1, a2)
}

type serverMapGroups struct {
	allocGroup alloc.ClassT[mapGroup]
	allocItem  alloc.ClassT[mapGroupItem]
	groups     *mapGroup
	refs       *mapGroupRef
}

type mapGroupKind byte

const (
	mapGroupObjects   = mapGroupKind(0)
	mapGroupWaypoints = mapGroupKind(1)
	mapGroupWalls     = mapGroupKind(2)
	mapGroupGroups    = mapGroupKind(3)
)

var _ = [1]struct{}{}[96-unsafe.Sizeof(mapGroup{})]

type mapGroup struct {
	typ  byte // 0, 0
	_    [3]byte
	ind  uint32        // 1, 4
	name [76]byte      // 2, 8
	list *mapGroupItem // 21, 84
	next *mapGroup     // 22, 88
	prev *mapGroup     // 23, 92
}

func (s *serverMapGroups) getFirstMapGroup() *mapGroup { // nox_server_getFirstMapGroup_57C080
	return s.groups
}

func (s *serverMapGroups) Init() {
	s.allocGroup = alloc.NewClassT("ItemGroupInfo", mapGroup{}, 512)
	s.allocItem = alloc.NewClassT("ItemGroupElement", mapGroupItem{}, 5000)
}

func (s *serverMapGroups) Reset() {
	s.allocItem.FreeAllObjects()
	s.allocGroup.FreeAllObjects()
	s.groups = nil
}

func (s *serverMapGroups) Free() {
	if s.allocGroup.Class != nil {
		s.allocGroup.Free()
	}
	if s.allocItem.Class != nil {
		s.allocItem.Free()
	}
	s.groups = nil
}

func (s *serverMapGroups) sub57C330() *mapGroup {
	if !noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
		return nil
	}
	return s.allocGroup.NewObject()
}

func (s *serverMapGroups) addNewMapGroup57C3B0(p *mapGroup) {
	p.prev = nil
	p.next = s.groups
	if head := s.groups; head != nil {
		head.prev = p
	}
	s.groups = p
}

func (s *serverMapGroups) nextMapGroupIndex() uint32 {
	var max uint32
	for it := s.getFirstMapGroup(); it != nil; it = it.Next() {
		if it.ind+1 > max {
			max = it.ind + 1
		}
	}
	return max
}

type mapGroupRef struct {
	field0 *mapGroup
	next4  *mapGroupRef
	prev8  *mapGroupRef
}

func (s *serverMapGroups) sub504600(name string, ind uint32, typ uint8) {
	g := s.sub57C330()
	if g == nil {
		return
	}
	p, _ := alloc.New(mapGroupRef{})
	p.field0 = g
	p.next4 = s.refs
	p.prev8 = nil
	if head := s.refs; head != nil {
		head.prev8 = p
	}
	s.refs = p
	g.next = nil
	g.prev = nil
	g.list = nil
	g.ind = ind
	g.typ = typ
	StrCopyBytes(g.name[:], name)
}

func (s *serverMapGroups) sub57C130(arg []uint32, ind uint32) int32 {
	if arg == nil {
		return 0
	}
	if s.groups == nil {
		return 0
	}
	var found *mapGroup
	for g := s.groups; g != nil; g = g.next {
		if g.ind == ind {
			found = g
			break
		}
	}
	if found == nil {
		return 0
	}
	g := found
	it := s.allocItem.NewObject()
	if it == nil {
		return 0
	}
	switch g.GroupType() {
	case mapGroupWalls:
		it.data0 = arg[0]
		it.data4 = arg[1]
	case mapGroupObjects, mapGroupWaypoints, mapGroupGroups:
		it.data0 = arg[0]
	default:
		s.allocItem.FreeObjectFirst(it)
		return 0
	}
	it.next8 = g.list
	it.prev12 = nil
	if head := g.list; head != nil {
		head.prev12 = it
	}
	g.list = it
	return 1
}

func (s *serverMapGroups) sub5046A0(arg []uint32, ind uint32) int {
	if arg == nil {
		return 0
	}
	var found *mapGroupRef
	for v2 := s.refs; v2 != nil; v2 = v2.next4 {
		if v2.field0.ind == ind {
			found = v2
			break
		}
	}
	if found == nil {
		return 0
	}
	v2 := found
	v4 := s.allocItem.NewObject()
	if v4 == nil {
		return 0
	}
	switch v2.field0.GroupType() {
	case mapGroupWalls:
		v4.data0 = arg[0]
		v4.data4 = arg[1]
	case mapGroupObjects, mapGroupWaypoints, mapGroupGroups:
		v4.data0 = arg[0]
	default:
		return 0
	}
	v4.prev12 = nil
	v4.next8 = v2.field0.list
	if head := v2.field0.list; head != nil {
		head.prev12 = v4
	}
	v2.field0.list = v4
	return 1
}

func (s *Server) sub504720(a1, a2 uint32) int32 {
	s.groupsAdjust(a1, a2)
	for it := s.mapGroups.refs; it != nil; it = it.next4 {
		s.mapGroups.addNewMapGroup57C3B0(it.field0)
	}
	return 1
}

func (s *Server) pendingObjByScriptID4CFFE0(sid int) *Object {
	for it := asObjectS(s.Objs.Pending); it != nil; it.Next() {
		if it.ScriptID == sid {
			return it
		}
	}
	return nil
}

func (s *Server) pendingWaypointByInd579C60(id uint32) *Waypoint {
	for it := asWaypoint(C.dword_5d4594_2523756); it != nil; it = it.Next() {
		if it.Field1 == id {
			return it
		}
	}
	return nil
}

func (s *Server) groupsAdjust(dx, dy uint32) {
	di := s.mapGroups.nextMapGroupIndex()
	for it := s.mapGroups.refs; it != nil; it = it.next4 {
		name := fmt.Sprintf("%s%%%d", it.field0.ID(), int(C.dword_5d4594_3835312))
		StrCopyBytes(it.field0.name[:], name)
		it.field0.ind += di

		for it2 := it.field0.list; it2 != nil; it2 = it2.next8 {
			switch it.field0.GroupType() {
			case mapGroupObjects:
				if p := s.pendingObjByScriptID4CFFE0(it2.Data1()); p != nil {
					it2.data0 = p.Extent
				}
			case mapGroupWaypoints:
				if p := s.pendingWaypointByInd579C60(it2.data0); p != nil {
					it2.data0 = p.Index
				}
			case mapGroupWalls:
				it2.data0 = (dx + it2.data0*common.GridStep) / common.GridStep
				it2.data4 = (dy + it2.data4*common.GridStep) / common.GridStep
			case mapGroupGroups:
				it2.data0 += di
			}
		}
	}
}

func (s *serverMapGroups) mapLoadAddGroup57C0C0(name string, ind uint32, typ byte) int32 {
	p := s.sub57C330()
	if p == nil {
		return 0
	}
	p.ind = ind
	p.typ = typ
	StrCopyBytes(p.name[:], name)
	p.list = nil
	head := s.groups
	p.prev = nil
	p.next = head
	if s.groups != nil {
		s.groups.prev = p
	}
	s.groups = p
	return 1
}

func (s *serverMapGroups) GroupByInd(ind int) *mapGroup {
	for p := s.getFirstMapGroup(); p != nil; p = p.Next() {
		if int(p.Ind()) == ind {
			return p
		}
	}
	return nil
}

func (s *serverMapGroups) GroupByID(id string, typ mapGroupKind) *mapGroup {
	for p := s.getFirstMapGroup(); p != nil; p = p.Next() {
		if p.Type() != typ {
			continue
		}
		id2 := p.ID()
		if id == id2 || strings.HasSuffix(id2, ":"+id) {
			return p
		}
	}
	return nil
}

func (g *mapGroup) C() unsafe.Pointer {
	return unsafe.Pointer(g)
}

// GroupType gets the group type (non-recursively).
func (g *mapGroup) GroupType() mapGroupKind {
	return mapGroupKind(g.typ)
}

func (g *mapGroup) Ind() uint32 {
	return g.ind
}

// Type determines the group's type recursively.
func (g *mapGroup) Type() mapGroupKind {
	return mapGroupKind(C.nox_server_scriptGetGroupId_57C2D0((**C.int)(g.C())))
}

func (g *mapGroup) ID() string {
	return GoStringS(g.name[:])
}

func (g *mapGroup) Next() *mapGroup {
	if g == nil {
		return nil
	}
	return g.next
}

func (g *mapGroup) First() *mapGroupItem {
	if g == nil {
		return nil
	}
	return g.list
}

type mapGroupItem struct {
	data0  uint32
	data4  uint32
	next8  *mapGroupItem
	prev12 *mapGroupItem
}

func (it *mapGroupItem) C() unsafe.Pointer {
	return unsafe.Pointer(it)
}

func (it *mapGroupItem) Data1() int {
	return int(it.data0)
}

func (it *mapGroupItem) Data2() int {
	return int(it.data4)
}

func (it *mapGroupItem) Next() *mapGroupItem {
	return it.next8
}
