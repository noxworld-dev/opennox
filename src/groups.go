package opennox

/*
extern void* dword_5d4594_1599564;
int  nox_server_scriptGetGroupId_57C2D0(int** a1);
*/
import "C"
import (
	"strings"
	"unsafe"

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
	field4 *mapGroupX
	field8 *mapGroupX
}

//export sub_504600
func sub_504600(name *C.char, ind uint32, typ uint8) {
	g := sub57C330()
	if g == nil {
		return
	}
	p, _ := alloc.New(mapGroupX{})
	p.field0 = g
	p.field4 = (*mapGroupX)(C.dword_5d4594_1599564)
	p.field8 = nil
	if head := (*mapGroupX)(C.dword_5d4594_1599564); head != nil {
		head.field8 = p
	}
	C.dword_5d4594_1599564 = unsafe.Pointer(p)
	g.next = nil
	g.prev = nil
	g.list = nil
	g.ind = ind
	g.typ = typ
	StrCopyBytes(g.name[:], GoString(name))
}

//export sub_57C370
func sub_57C370(p unsafe.Pointer) {
	nox_alloc_groupInfo_2523892.FreeObjectFirst((*mapGroup)(p))
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
	switch g.Type() {
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

//export sub_57C360
func sub_57C360() unsafe.Pointer {
	return nox_alloc_itemGroupElem_2523896.NewObject().C()
}

//export sub_57C390
func sub_57C390(p unsafe.Pointer) {
	nox_alloc_itemGroupElem_2523896.FreeObjectFirst((*mapGroupItem)(p))
}

//export nox_server_addNewMapGroup_57C3B0
func nox_server_addNewMapGroup_57C3B0(a1 unsafe.Pointer) {
	p := (*mapGroup)(a1)
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

func (s *Server) getFirstMapGroup() *mapGroup {
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
