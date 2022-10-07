package opennox

/*
int  nox_server_scriptGetGroupId_57C2D0(int** a1);
extern unsigned int nox_server_mapGroupsHead_2523900;
*/
import "C"
import (
	"strings"
	"unsafe"
)

//export nox_server_scriptGetGroup_57C0A0
func nox_server_scriptGetGroup_57C0A0(a1 C.int) C.int {
	return C.int(uintptr(getMapGroupByInd(int(a1)).C()))
}

func getMapGroupByInd(ind int) *mapGroup {
	for p := getFirstMapGroup(); p != nil; p = p.Next() {
		if int(p.Ind()) == ind {
			return p
		}
	}
	return nil
}

func getMapGroupByID(id string, typ int) *mapGroup {
	for p := getFirstMapGroup(); p != nil; p = p.Next() {
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

type mapGroup [0]byte

func getFirstMapGroup() *mapGroup {
	return (*mapGroup)(unsafe.Pointer(uintptr(C.nox_server_mapGroupsHead_2523900)))
}

func (g *mapGroup) C() unsafe.Pointer {
	return unsafe.Pointer(g)
}

func (g *mapGroup) GroupType() byte {
	return *(*byte)(g.C())
}

func (g *mapGroup) Ind() uint32 {
	return *(*uint32)(unsafe.Add(g.C(), 4))
}

// FIXME: Better rename Type into GroupId, and ID into Name?
func (g *mapGroup) Type() int {
	return int(C.nox_server_scriptGetGroupId_57C2D0((**C.int)(g.C())))
}

func (g *mapGroup) ID() string {
	return GoString((*C.char)(unsafe.Add(g.C(), 8)))
}

func (g *mapGroup) Next() *mapGroup {
	if g == nil {
		return nil
	}
	p := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(g), 88))
	return (*mapGroup)(p)
}

func (g *mapGroup) FirstItem() *mapGroupItem {
	return *(**mapGroupItem)(unsafe.Add(g.C(), 21*4))
}

type mapGroupItem [0]byte

func (it *mapGroupItem) Ind() int {
	return *(*int)(it.Payload())
}

func (it *mapGroupItem) Ind2() int {
	return *(*int)(unsafe.Add(it.Payload(), 4))
}

func (it *mapGroupItem) Next() *mapGroupItem {
	return *(**mapGroupItem)(unsafe.Add(unsafe.Pointer(it), 8))
}

func (it *mapGroupItem) Payload() unsafe.Pointer {
	return unsafe.Pointer(it)
}
