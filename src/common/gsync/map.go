package gsync

import "sync"

type Map[K comparable, V any] struct {
	m sync.Map
}

func (m *Map[K, V]) Load(k K) (V, bool) {
	v, ok := m.m.Load(k)
	if !ok {
		var zero V
		return zero, false
	}
	return v.(V), true
}

func (m *Map[K, V]) Store(k K, v V) {
	m.m.Store(k, v)
}

func (m *Map[K, V]) Delete(k K) {
	m.m.Delete(k)
}
