package nox

/*
int  nox_server_scriptGetGroupId_57C2D0(int** a1);
extern unsigned int nox_server_mapGroupsHead_2523900;
*/
import "C"
import (
	"strings"
	"unsafe"
)

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

func (it *mapGroupItem) Next() *mapGroupItem {
	return *(**mapGroupItem)(unsafe.Add(unsafe.Pointer(it), 8))
}

func (it *mapGroupItem) Payload() unsafe.Pointer {
	return unsafe.Pointer(it)
}
