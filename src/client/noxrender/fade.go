package noxrender

type noxRenderFade struct {
	arr [4]Fade
}

type FadeFlags int

func (f FadeFlags) Has(f2 FadeFlags) bool {
	return f&f2 == f2
}
func (f FadeFlags) HasAny(f2 FadeFlags) bool {
	return f&f2 != 0
}

const (
	FadeActive = FadeFlags(1 << iota)
	FadeKeep
	FadeMenu
)

type Fade struct {
	key       string
	flags     FadeFlags
	remaining int

	DoneFunc func()
	DrawFunc func(f *Fade)
}

func (r *NoxRender) FadeReset() {
	for i := range r.fade.arr {
		r.fade.arr[i].flags = 0
	}
}

func (r *NoxRender) FadeDisable() {
	for i := range r.fade.arr {
		f := &r.fade.arr[i]
		f.flags &^= FadeActive
	}
}

func (r *NoxRender) DrawFade(menu bool) int {
	flags := FadeActive
	if menu {
		flags |= FadeMenu
	}
	const mask = FadeActive | FadeMenu
	for i := range r.fade.arr {
		f := &r.fade.arr[i]
		if f.flags&mask != flags {
			continue
		}
		f.DrawFunc(f)
		if f.remaining > 0 {
			f.remaining--
			continue
		}
		if !f.flags.Has(FadeKeep) {
			f.flags &= ^flags
			if f.DoneFunc != nil {
				f.DoneFunc()
			}
		}
	}
	return 0
}

func (r *NoxRender) NewFade(key string, t int, flags FadeFlags) *Fade {
	for i := range r.fade.arr {
		it := &r.fade.arr[i]
		if !it.flags.Has(FadeActive) {
			*it = Fade{
				key:       key,
				remaining: t,
				flags:     FadeActive | flags,
			}
			return it
		}
	}
	return nil
}

func (r *NoxRender) StopFade(key string) bool {
	done := false
	for i := range r.fade.arr {
		it := &r.fade.arr[i]
		if it.flags.Has(FadeActive) && it.key == key {
			it.flags &= ^FadeActive
			if it.DoneFunc != nil {
				it.DoneFunc()
			}
			done = true
		}
	}
	return done
}

func (r *NoxRender) CheckFade(key string) bool {
	for i := range r.fade.arr {
		it := &r.fade.arr[i]
		if it.flags.Has(FadeActive) && it.key == key {
			return true
		}
	}
	return false
}

const (
	FadeInCinemaKey    = "FadeInCinema"
	FadeOutCinemaKey   = "FadeOutCinema"
	FadeInScreenKey    = "fadeInScreen"
	FadeOutScreenKey   = "fadeOutScreen"
	FadeClearScreenKey = "FadeClearScreen"
)

func (r *NoxRender) FadeInCinema(perc float32, t int, cl Color) bool {
	f := r.NewFade(FadeInCinemaKey, t, FadeKeep)
	if f == nil {
		return false
	}
	v := perc * float32(r.PixBuffer().Rect.Dy())
	var (
		cur = float32(0)
		dv  = v / float32(t)
	)
	f.DrawFunc = func(f *Fade) {
		if f.remaining != 0 {
			cur += dv
		}
		r.drawFadeCinema(int(cur), cl)
	}
	return true
}

func (r *NoxRender) FadeOutCinema(perc float32, t int, cl Color) bool {
	f := r.NewFade(FadeOutCinemaKey, t, 0)
	if f == nil {
		return false
	}
	v := perc * float32(r.PixBuffer().Rect.Dy())
	var (
		cur  = v
		dv   = v / float32(t)
		flag = false
	)
	f.DrawFunc = func(f *Fade) {
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
	flags := FadeKeep
	if menu {
		flags |= FadeMenu
	}
	f := r.NewFade(FadeClearScreenKey, 0, flags)
	if f == nil {
		return false
	}
	f.DrawFunc = func(_ *Fade) {
		pix := r.PixBuffer()
		r.DrawRectFilledOpaque(0, 0, pix.Rect.Dx(), pix.Rect.Dy(), cl)
	}
	return true
}
