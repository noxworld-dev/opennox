package opennox

import "unsafe"

type listHead struct {
	listItem
}

func (l *listHead) First() *listItem {
	return l.Next()
}

func (l *listHead) Clear() {
	l.field_0 = &l.listItem
	l.field_1 = &l.listItem
	l.field_2 = &l.listItem
}

func (l *listHead) Append(cur *listItem) {
	if l == nil || cur == nil {
		panic("nil list or item")
	}
	it := l.field_1

	// FIXME: in some cases 'it' is null, which suggests that some lists are not initialized properly
	//        auto-initializing them however leads to more serious issues like double-free
	if false {
		if it == nil && l.field_0 == nil && l.field_2 == nil {
			l.Clear()
			it = l.field_1
		}
	}

	cur.field_0 = &l.listItem
	cur.field_1 = it

	l.field_1 = cur
	if it != nil { // see above note
		it.field_0 = cur
	}
}

type listItem struct {
	field_0 *listItem
	field_1 *listItem
	field_2 *listItem
}

func (l *listItem) Next() *listItem {
	if l == nil {
		return nil
	}
	it := l.field_0
	if it == l.field_2 {
		return nil
	}
	return it
}

func nox_common_list_getFirstSafe_425890(list unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer((*listHead)(list).First())
}

func nox_common_list_getNextSafe_4258A0(list unsafe.Pointer) unsafe.Pointer {
	if list == nil {
		return nil
	}
	return nox_common_list_getNext_425940(list)
}

func nox_common_list_getNext_425940(list unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer((*listItem)(list).Next())
}

func nox_common_list_clear_425760(list unsafe.Pointer) {
	(*listHead)(list).Clear()
}

func nox_common_list_append_4258E0(list, cur unsafe.Pointer) {
	(*listHead)(list).Append((*listItem)(cur))
}
