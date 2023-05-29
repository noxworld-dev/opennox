package legacy

import "unsafe"

var _ = [1]struct{}{}[36-unsafe.Sizeof(Nox_map_list_item{})]

type nox_list_item_t struct {
	field_0 *nox_list_item_t // 0, 0
	field_1 *nox_list_item_t // 1, 4
	field_2 *nox_list_item_t // 2, 8
}

type Nox_map_list_item struct {
	list      nox_list_item_t // 0, 0
	Name      [12]byte        // 3, 12
	Field_6   int32           // 6, 24
	Field_7   uint32          // 7, 28
	Field_8_0 byte            // 8, 32
	Field_8_1 byte            // 8, 33
	Field_8_2 uint16          // 8, 34
}

func Get_nox_common_maplist() unsafe.Pointer {
	return unsafe.Pointer(&nox_common_maplist)
}

func Nox_common_maplist_add_4D0760(p *Nox_map_list_item) {
	nox_common_maplist_add_4D0760((*Nox_map_list_item)(unsafe.Pointer(p)))
}

func Sub_425770(p *Nox_map_list_item) {
	sub_425770(unsafe.Pointer(p))
}
