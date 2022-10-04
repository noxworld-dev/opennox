package opennox

import "unsafe"

func nox_common_list_getFirstSafe_425890(list unsafe.Pointer) unsafe.Pointer {
	return nox_common_list_getNextSafe_4258A0(list)
}

func nox_common_list_getNextSafe_4258A0(list unsafe.Pointer) unsafe.Pointer {
	if list == nil {
		return nil
	}
	return nox_common_list_getNext_425940(list)
}

func nox_common_list_getNext_425940(list unsafe.Pointer) unsafe.Pointer {
	if list == nil {
		return nil
	}
	hdr := unsafe.Slice((*unsafe.Pointer)(list), 3)
	it := hdr[0]
	if it == hdr[2] {
		return nil
	}
	return it
}

func nox_common_list_clear_425760(list unsafe.Pointer) {
	hdr := unsafe.Slice((*unsafe.Pointer)(list), 3)
	hdr[0] = list
	hdr[1] = list
	hdr[2] = list
}
