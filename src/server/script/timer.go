package script

import "time"

func Frames(num int) Duration {
	return Duration{frames: num}
}

func Time(dt time.Duration) Duration {
	return Duration{time: dt}
}

type Duration struct {
	frames int
	time   time.Duration
}

func (d Duration) LessOrEq(d2 Duration) bool {
	if d.IsFrames() && d2.IsFrames() {
		return d.frames <= d2.frames
	}
	if d.IsTime() && d2.IsTime() {
		return d.time <= d2.time
	}
	return false
}

func (d Duration) Add(d2 Duration) Duration {
	if d.IsFrames() && d2.IsFrames() {
		d.frames += d2.frames
	}
	if d.IsTime() && d2.IsTime() {
		d.time += d2.time
	}
	return d
}

func (d Duration) IsTime() bool {
	return d.time != 0
}

func (d Duration) IsFrames() bool {
	return d.frames != 0
}

func (d Duration) Time() (time.Duration, bool) {
	return d.time, d.IsTime()
}

func (d Duration) Frames() (int, bool) {
	return d.frames, d.IsFrames()
}

type TimeSource interface {
	Frame() int
	Time() time.Duration
}

func NewTimers(src TimeSource) *Timers {
	return &Timers{
		src: src,
		cur: Duration{
			time:   src.Time(),
			frames: src.Frame(),
		},
		active: make(map[uint]*Timer),
	}
}

type Timers struct {
	src    TimeSource
	last   uint
	cur    Duration
	active map[uint]*Timer
}

func (t *Timers) stopTimer(id uint) {
	delete(t.active, id)
}

func (t *Timers) SetTimer(d Duration, fnc func()) *Timer {
	t.last++
	tm := &Timer{t: t, id: t.last, at: d.Add(t.cur), fnc: fnc}
	t.active[tm.id] = tm
	return tm
}

func (t *Timers) Tick() {
	t.cur = Duration{
		frames: t.src.Frame(),
		time:   t.src.Time(),
	}
	for _, tm := range t.active {
		if tm.at.LessOrEq(t.cur) {
			tm.fnc()
			tm.fnc = nil
			t.stopTimer(tm.id)
		}
	}
}

type Timer struct {
	t   *Timers
	id  uint
	at  Duration
	fnc func()
}

func (t *Timer) Stop() {
	if t.fnc != nil {
		t.fnc = nil
		t.t.stopTimer(t.id)
	}
}
