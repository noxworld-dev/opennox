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

func nox_common_list_append_4258E0(list, cur unsafe.Pointer) {
	if list == nil || cur == nil {
		panic("nil list or item")
	}
	listp := unsafe.Slice((*unsafe.Pointer)(list), 3)
	curp := unsafe.Slice((*unsafe.Pointer)(cur), 3)

	var it []unsafe.Pointer
	if listp[1] != nil {
		it = unsafe.Slice((*unsafe.Pointer)(listp[1]), 3)
	}

	// FIXME: in some cases 'it' is null, which suggests that some lists are not initialized properly
	//        auto-initializing them however leads to more serious issues like double-free
	if false {
		if it == nil && listp[0] == nil && listp[2] == nil {
			nox_common_list_clear_425760(list)
			it = unsafe.Slice((*unsafe.Pointer)(listp[1]), 3)
		}
	}

	curp[0] = list
	curp[1] = unsafe.Pointer(&it[0])

	listp[1] = cur
	if it != nil { // see above note
		it[0] = cur
	}
}
