package opennox

/*
#include <stdint.h>
extern void* dword_5d4594_1599564;
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

var (
	nox_alloc_groupInfo_2523892      alloc.ClassT[mapGroup]
	nox_alloc_itemGroupElem_2523896  alloc.ClassT[mapGroupItem]
	nox_server_mapGroupsHead_2523900 *mapGroup
)

//export nox_server_getFirstMapGroup_57C080
func nox_server_getFirstMapGroup_57C080() unsafe.Pointer {
	return nox_server_mapGroupsHead_2523900.C()
}

//export nox_server_scriptGetGroup_57C0A0
func nox_server_scriptGetGroup_57C0A0(a1 C.int) unsafe.Pointer {
	return noxServer.mapGroupByInd(int(a1)).C()
}

func nox_xxx_allocGroupRelatedArrays_57BFB0() {
	nox_alloc_groupInfo_2523892 = alloc.NewClassT("ItemGroupInfo", mapGroup{}, 512)
	nox_alloc_itemGroupElem_2523896 = alloc.NewClassT("ItemGroupElement", mapGroupItem{}, 5000)
}

func sub_57C000() {
	nox_alloc_itemGroupElem_2523896.FreeAllObjects()
	nox_alloc_groupInfo_2523892.FreeAllObjects()
	nox_server_mapGroupsHead_2523900 = nil
}

func sub_57C030() {
	if nox_alloc_groupInfo_2523892.Class != nil {
		nox_alloc_groupInfo_2523892.Free()
	}
	if nox_alloc_itemGroupElem_2523896.Class != nil {
		nox_alloc_itemGroupElem_2523896.Free()
	}
	nox_server_mapGroupsHead_2523900 = nil
}

func sub57C330() *mapGroup {
	if !noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
		return nil
	}
	return nox_alloc_groupInfo_2523892.NewObject()
}

type mapGroupX struct {
	field0 *mapGroup
	next4  *mapGroupX
	prev8  *mapGroupX
}

//export sub_504600
func sub_504600(name *C.char, ind uint32, typ uint8) {
	g := sub57C330()
	if g == nil {
		return
	}
	p, _ := alloc.New(mapGroupX{})
	p.field0 = g
	p.next4 = (*mapGroupX)(C.dword_5d4594_1599564)
	p.prev8 = nil
	if head := (*mapGroupX)(C.dword_5d4594_1599564); head != nil {
		head.prev8 = p
	}
	C.dword_5d4594_1599564 = unsafe.Pointer(p)
	g.next = nil
	g.prev = nil
	g.list = nil
	g.ind = ind
	g.typ = typ
	StrCopyBytes(g.name[:], GoString(name))
}

//export sub_57C130
func sub_57C130(d *uint32, ind uint32) int32 {
	if d == nil {
		return 0
	}
	if nox_server_mapGroupsHead_2523900 == nil {
		return 0
	}
	var found *mapGroup
	for g := nox_server_mapGroupsHead_2523900; g != nil; g = g.next {
		if g.ind == ind {
			found = g
			break
		}
	}
	if found == nil {
		return 0
	}
	arg := unsafe.Slice(d, 2)
	g := found
	it := nox_alloc_itemGroupElem_2523896.NewObject()
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
		nox_alloc_itemGroupElem_2523896.FreeObjectFirst(it)
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

//export sub_5046A0
func sub_5046A0(d *uint32, ind uint32) int {
	if d == nil {
		return 0
	}
	var found *mapGroupX
	for v2 := (*mapGroupX)(C.dword_5d4594_1599564); v2 != nil; v2 = v2.next4 {
		if v2.field0.ind == ind {
			found = v2
			break
		}
	}
	if found == nil {
		return 0
	}
	arg := unsafe.Slice(d, 2)
	v2 := found
	v4 := nox_alloc_itemGroupElem_2523896.NewObject()
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

//export sub_504720
func sub_504720(a1, a2 uint32) int32 {
	sub_504760(a1, a2)
	for it := (*mapGroupX)(C.dword_5d4594_1599564); it != nil; it = it.next4 {
		nox_server_addNewMapGroup_57C3B0(it.field0)
	}
	return 1
}

//export sub_4CFFE0
func sub_4CFFE0(sid int) *nox_object_t {
	return sub4CFFE0(sid).CObj()
}

func sub4CFFE0(sid int) *Object {
	for it := asObjectS(noxServer.Objs.Pending); it != nil; it.Next() {
		if it.ScriptID == sid {
			return it
		}
	}
	return nil
}

//export sub_579C60
func sub_579C60(id uint32) *nox_waypoint_t {
	return sub579C60(id).C()
}

func sub579C60(id uint32) *Waypoint {
	for it := asWaypoint(C.dword_5d4594_2523756); it != nil; it = it.Next() {
		if it.Field1 == id {
			return it
		}
	}
	return nil
}

func (s *Server) nextMapGroupIndex() uint32 {
	var max uint32
	for it := s.getFirstMapGroup(); it != nil; it = it.Next() {
		if it.ind+1 > max {
			max = it.ind + 1
		}
	}
	return max
}

func sub_504760(dx, dy uint32) {
	di := noxServer.nextMapGroupIndex()
	for it := (*mapGroupX)(C.dword_5d4594_1599564); it != nil; it = it.next4 {
		name := fmt.Sprintf("%s%%%d", it.field0.ID(), int(C.dword_5d4594_3835312))
		StrCopyBytes(it.field0.name[:], name)
		it.field0.ind += di

		for it2 := it.field0.list; it2 != nil; it2 = it2.next8 {
			switch it.field0.GroupType() {
			case mapGroupObjects:
				if p := sub4CFFE0(it2.Data1()); p != nil {
					it2.data0 = p.Extent
				}
			case mapGroupWaypoints:
				if p := sub579C60(it2.data0); p != nil {
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

func nox_server_addNewMapGroup_57C3B0(p *mapGroup) {
	p.prev = nil
	p.next = nox_server_mapGroupsHead_2523900
	if head := nox_server_mapGroupsHead_2523900; head != nil {
		head.prev = p
	}
	nox_server_mapGroupsHead_2523900 = p
}

//export nox_server_mapLoadAddGroup_57C0C0
func nox_server_mapLoadAddGroup_57C0C0(name *C.char, ind uint32, typ byte) int32 {
	p := sub57C330()
	if p == nil {
		return 0
	}
	p.ind = ind
	p.typ = typ
	StrCopyBytes(p.name[:], GoString(name))
	p.list = nil
	head := nox_server_mapGroupsHead_2523900
	p.prev = nil
	p.next = head
	if nox_server_mapGroupsHead_2523900 != nil {
		nox_server_mapGroupsHead_2523900.prev = p
	}
	nox_server_mapGroupsHead_2523900 = p
	return 1
}

func (s *Server) mapGroupByInd(ind int) *mapGroup {
	for p := s.getFirstMapGroup(); p != nil; p = p.Next() {
		if int(p.Ind()) == ind {
			return p
		}
	}
	return nil
}

func (s *Server) getMapGroupByID(id string, typ mapGroupKind) *mapGroup {
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

func (s *Server) getFirstMapGroup() *mapGroup { // nox_server_getFirstMapGroup_57C080
	return nox_server_mapGroupsHead_2523900
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
