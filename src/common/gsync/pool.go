package gsync

import "sync"

type Pool[T any] struct {
	p   sync.Pool
	New func() *T
}

func (p *Pool[T]) Get() *T {
	v := p.p.Get()
	if v != nil {
		return v.(*T)
	}
	if p.New != nil {
		return p.New()
	}
	return new(T)
}

func (p *Pool[T]) Put(v *T) {
	if v == nil {
		return
	}
	p.p.Put(v)
}
