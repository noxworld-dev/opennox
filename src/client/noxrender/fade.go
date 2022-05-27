package noxrender

import "image"

type FadeKey int

const (
	FadeInCinemaKey = FadeKey(iota)
	FadeOutCinemaKey
	FadeInScreenKey
	FadeOutScreenKey
	FadeClearScreenKey
)

type noxRenderFade struct {
	arr [4]fade
}

type fadeFlags int

func (f fadeFlags) Has(f2 fadeFlags) bool {
	return f&f2 == f2
}
func (f fadeFlags) HasAny(f2 fadeFlags) bool {
	return f&f2 != 0
}

const (
	fadeActive = fadeFlags(1 << iota)
	fadeKeep
	fadeMenu
)

type fade struct {
	key       FadeKey
	flags     fadeFlags
	remaining int

	doneFunc func()
	drawFunc func(f *fade)
}

func (r *NoxRender) FadeReset() {
	for i := range r.fade.arr {
		r.fade.arr[i].flags = 0
	}
}

func (r *NoxRender) FadeDisable() {
	for i := range r.fade.arr {
		f := &r.fade.arr[i]
		f.flags &^= fadeActive
	}
}

func (r *NoxRender) DrawFade(menu bool) int {
	flags := fadeActive
	if menu {
		flags |= fadeMenu
	}
	const mask = fadeActive | fadeMenu
	for i := range r.fade.arr {
		f := &r.fade.arr[i]
		if f.flags&mask != flags {
			continue
		}
		f.drawFunc(f)
		if f.remaining > 0 {
			f.remaining--
			continue
		}
		if !f.flags.Has(fadeKeep) {
			f.flags &= ^flags
			if f.doneFunc != nil {
				f.doneFunc()
			}
		}
	}
	return 0
}

func (r *NoxRender) newFade(key FadeKey, t int, flags fadeFlags) *fade {
	for i := range r.fade.arr {
		it := &r.fade.arr[i]
		if !it.flags.Has(fadeActive) {
			*it = fade{
				key:       key,
				remaining: t,
				flags:     fadeActive | flags,
			}
			return it
		}
	}
	return nil
}

func (r *NoxRender) StopFade(key FadeKey) bool {
	done := false
	for i := range r.fade.arr {
		it := &r.fade.arr[i]
		if it.flags.Has(fadeActive) && it.key == key {
			it.flags &= ^fadeActive
			if it.doneFunc != nil {
				it.doneFunc()
			}
			done = true
		}
	}
	return done
}

func (r *NoxRender) CheckFade(key FadeKey) bool {
	for i := range r.fade.arr {
		it := &r.fade.arr[i]
		if it.flags.Has(fadeActive) && it.key == key {
			return true
		}
	}
	return false
}

func (r *NoxRender) FadeInCinema(perc float32, t int, cl Color) bool {
	f := r.newFade(FadeInCinemaKey, t, fadeKeep)
	if f == nil {
		return false
	}
	v := perc * float32(r.PixBuffer().Rect.Dy())
	var (
		cur = float32(0)
		dv  = v / float32(t)
	)
	f.drawFunc = func(f *fade) {
		if f.remaining != 0 {
			cur += dv
		}
		r.drawFadeCinema(int(cur), cl)
	}
	return true
}

func (r *NoxRender) FadeOutCinema(perc float32, t int, cl Color) bool {
	f := r.newFade(FadeOutCinemaKey, t, 0)
	if f == nil {
		return false
	}
	v := perc * float32(r.PixBuffer().Rect.Dy())
	var (
		cur  = v
		dv   = v / float32(t)
		flag = false
	)
	f.drawFunc = func(f *fade) {
		if !flag {
			r.StopFade(FadeInCinemaKey)
			flag = true
		}
		cur -= dv
		r.drawFadeCinema(int(cur), cl)
	}
	return true
}

func (r *NoxRender) drawFadeCinema(v int, cl Color) {
	pix := r.PixBuffer()
	r.DrawRectFilledOpaque(0, 0, pix.Rect.Dx(), v, cl)
	r.DrawRectFilledOpaque(0, pix.Rect.Dy()-v, pix.Rect.Dx(), v, cl)
}

func (r *NoxRender) FadeClearScreen(menu bool, cl Color) bool {
	if r.CheckFade(FadeOutScreenKey) {
		return true
	}
	flags := fadeKeep
	if menu {
		flags |= fadeMenu
	}
	f := r.newFade(FadeClearScreenKey, 0, flags)
	if f == nil {
		return false
	}
	f.drawFunc = func(_ *fade) {
		pix := r.PixBuffer()
		r.DrawRectFilledOpaque(0, 0, pix.Rect.Dx(), pix.Rect.Dy(), cl)
	}
	return true
}

func (r *NoxRender) FadeInScreen(t int, menu bool, done func()) bool {
	r.StopFade(FadeInScreenKey)
	flags := fadeFlags(0)
	if menu {
		flags |= fadeMenu
	}
	f := r.newFade(FadeInScreenKey, t, flags)
	if f == nil {
		return false
	}

	f.doneFunc = done
	var (
		cur = float32(0)
		dv  = float32(0xff) / float32(t)
	)
	f.drawFunc = func(f *fade) {
		c := int(cur)
		pix := r.PixBuffer()
		r.drawFadeScreen(pix.Rect, c)
		cur += dv
	}
	return true
}

func (r *NoxRender) FadeOutScreen(t int, menu bool, done func()) int {
	r.StopFade(FadeOutScreenKey)
	flags := fadeFlags(0)
	if menu {
		flags |= fadeMenu
	}
	f := r.newFade(FadeOutScreenKey, t, flags)
	if f == nil {
		return 0
	}
	f.doneFunc = done
	var (
		cur = float32(0xff)
		dv  = float32(0xff) / float32(t)
	)
	f.drawFunc = func(f *fade) {
		c := int(cur)
		pix := r.PixBuffer()
		r.drawFadeScreen(pix.Rect, c)
		cur -= dv
	}
	r.StopFade(FadeClearScreenKey)
	return 1
}

func (r *NoxRender) drawFadeScreen(rc image.Rectangle, bc int) {
	d := r.Data()
	if d.Clip() {
		rc = rc.Intersect(d.ClipRect())
		if rc.Empty() {
			return
		}
	}
	pix := r.PixBuffer()
	for y := rc.Min.Y; y < rc.Max.Y; y++ {
		for x := rc.Min.X; x < rc.Max.X; x++ {
			ind := pix.PixOffset(x, y)
			c := SplitColor16(pix.Pix[ind])
			cr := uint64(c.R) - uint64(bc)
			cg := uint64(c.G) - uint64(bc)
			cb := uint64(c.B) - uint64(bc)
			c.R = uint16(^(cr >> 32) & cr)
			c.G = uint16(^(cg >> 32) & cg)
			c.B = uint16(^(cb >> 32) & cb)
			pix.Pix[ind] = c.Make16()
		}
	}
}
