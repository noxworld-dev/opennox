package main

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

func (s *mapGroup) C() unsafe.Pointer {
	return unsafe.Pointer(s)
}

func (s *mapGroup) Type() int {
	return int(C.nox_server_scriptGetGroupId_57C2D0((**C.int)(s.C())))
}

func (s *mapGroup) ID() string {
	return GoString((*C.char)(unsafe.Pointer(uintptr(s.C()) + 8)))
}

func (s *mapGroup) Next() *mapGroup {
	if s == nil {
		return nil
	}
	p := *(*unsafe.Pointer)(unsafe.Pointer(uintptr(unsafe.Pointer(s)) + 88))
	return (*mapGroup)(p)
}
