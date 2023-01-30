package alloc

import "fmt"

type list struct {
	first *object
	last  *object
	n     int
}

func (l *list) Clear() {
	l.first = nil
	l.last = nil
	l.n = 0
}

func (l *list) Count() int {
	cnt := 0
	for it := l.first; it != nil; it = it.next {
		cnt++
	}
	return cnt
}

func (l *list) Each(fnc func(obj *object)) {
	var next *object
	for it := l.first; it != nil; it = next {
		next = it.next
		fnc(it)
	}
}

func (l *list) AddFirst(obj *object) {
	if l.Contains(obj) {
		panic(fmt.Errorf("object already in the list: %p", obj))
	}
	l.n++
	first := l.first
	if first != nil {
		first.prev = obj
	}
	l.first = obj
	obj.next = first
	obj.prev = nil
	if l.last == nil {
		l.last = obj
	}
}

func (l *list) AddLast(obj *object) {
	if l.Contains(obj) {
		panic(fmt.Errorf("object already in the list: %p", obj))
	}
	l.n++
	last := l.last
	if last != nil {
		last.next = obj
	}
	l.last = obj
	obj.next = nil
	obj.prev = last
	if l.first == nil {
		l.first = obj
	}
}

func (l *list) Contains(obj *object) bool {
	for it := l.first; it != nil; it = it.next {
		if it == obj {
			return true
		}
	}
	return false
}

func (l *list) Remove(obj *object) {
	if !l.Contains(obj) {
		panic("object not in the list!")
	}
	l.remove(obj)
}

func (l *list) remove(obj *object) {
	l.n--
	if prev := obj.prev; prev != nil {
		prev.next = obj.next
	} else {
		l.first = obj.next
	}
	if next := obj.next; next != nil {
		next.prev = obj.prev
	} else {
		l.last = obj.prev
	}
	obj.next = nil
	obj.prev = nil
}

func (l *list) PopFirst() *object {
	if l.first == nil {
		return nil
	}
	it := l.first
	l.remove(it)
	return it
}
