package nox

import (
	"bytes"
	"fmt"
	"image/png"
	"math"
	"os"
	"path/filepath"
	"strings"
	"time"

	"gopkg.in/yaml.v2"

	"nox/v1/client/input/keybind"
	"nox/v1/client/seat"
	"nox/v1/common/log"
	"nox/v1/common/platform"
	"nox/v1/common/types"
)

var (
	e2eLog      = log.New("E2E")
	e2eOverride = os.Getenv("NOX_E2E_OVERRIDE") == "true"
)

var e2e struct {
	path    string
	p       *platformE2E
	onInput []func(ev seat.InputEvent)

	slow       time.Duration
	real       seat.Seat
	realMouse  types.Point
	realEnable bool

	done  chan<- struct{}
	steps []e2eStep
	input []seat.InputEvent
}

type e2eStep struct {
	name string
	time time.Duration
	fnc  func()
}

type e2eScenario struct {
	steps []e2eStep
	done  chan struct{}
}

func (sc *e2eScenario) Exec() {
	sc.done = make(chan struct{})
	e2eJobs <- sc
	<-sc.done
	sc.steps = nil
}

func (sc *e2eScenario) add(dt time.Duration, name string, fnc func()) {
	var last time.Duration
	if n := len(sc.steps); n != 0 {
		last = sc.steps[n-1].time
	}
	sc.steps = append(sc.steps, e2eStep{name: name, time: last + dt, fnc: fnc})
}

func (sc *e2eScenario) Slow(dt time.Duration) {
	sc.add(0, "", func() {
		e2e.slow = dt
	})
}

func (sc *e2eScenario) Wait(dt time.Duration, name string) {
	if dt == 0 && name == "" {
		return
	}
	sc.add(dt, name, nil)
}

func (sc *e2eScenario) Input(dt time.Duration, name string, evs ...seat.InputEvent) {
	sc.add(dt, name, func() {
		e2eQueueInput(evs...)
	})
}

func (sc *e2eScenario) Quit(dt time.Duration) {
	sc.Input(dt, "", seat.WindowClosed)
	sc.Input(1, "", seat.WindowClosed)
	sc.Wait(1, "")
}

func (sc *e2eScenario) Move(x, y int, name string) {
	sc.Input(0, name, &seat.MouseMoveEvent{Pos: types.Point{X: x, Y: y}, Relative: false})
}

func (sc *e2eScenario) Click(pos types.Point, btn seat.MouseButton, name string) {
	sc.Input(0, name,
		&seat.MouseMoveEvent{Pos: pos, Relative: false},
		&seat.MouseButtonEvent{Button: btn, Pressed: true},
	)
	sc.Input(1, "", &seat.MouseButtonEvent{Button: btn, Pressed: false})
}

func (sc *e2eScenario) ClickSlow(pos types.Point, btn seat.MouseButton, name string) {
	sc.Input(0, name, &seat.MouseMoveEvent{Pos: pos, Relative: false})
	sc.Input(1, "", &seat.MouseButtonEvent{Button: btn, Pressed: true})
	sc.Input(1, "", &seat.MouseButtonEvent{Button: btn, Pressed: false})
}

func (sc *e2eScenario) Key(key keybind.Key, name string) {
	sc.Input(0, name, &seat.KeyboardEvent{Key: key, Pressed: true})
	sc.Input(1, "", &seat.KeyboardEvent{Key: key, Pressed: false})
}

func (sc *e2eScenario) ClickLeft(x, y int, name string) {
	sc.Click(types.Point{X: x, Y: y}, seat.MouseButtonLeft, name)
}

func (sc *e2eScenario) ClickSlowLeft(x, y int, name string) {
	sc.ClickSlow(types.Point{X: x, Y: y}, seat.MouseButtonLeft, name)
}

func e2eAngToPos(ang float64, dist int) types.Point {
	sz := types.Size{W: 1024, H: 768}
	rad := (0.5 - ang) * math.Pi
	return types.Point{
		X: sz.W/2 + int(math.Cos(rad)*float64(dist)),
		Y: sz.H/2 - int(math.Sin(rad)*float64(dist)),
	}
}

func (sc *e2eScenario) runStart(ang float64, dist int, name string) {
	sc.add(0, name, func() {
		pos := e2eAngToPos(ang, dist)
		e2eQueueInput(
			&seat.MouseMoveEvent{Pos: pos, Relative: false},
			&seat.MouseButtonEvent{Button: seat.MouseButtonRight, Pressed: true},
		)
	})
}

func (sc *e2eScenario) runDir(ang float64, dist int, name string) {
	sc.add(0, name, func() {
		pos := e2eAngToPos(ang, dist)
		e2eQueueInput(&seat.MouseMoveEvent{Pos: pos, Relative: false})
	})
}

func (sc *e2eScenario) runEnd(dt time.Duration) {
	sc.Input(dt, "", &seat.MouseButtonEvent{Button: seat.MouseButtonRight, Pressed: false})
	sc.Wait(5, "")
}

func (sc *e2eScenario) runFor(ang float64, dist int, dt time.Duration, name string) {
	sc.runStart(ang, dist, name)
	sc.runEnd(dt)
}

const (
	e2eWalkDist = 50
	e2eRunDist  = 200
)

func (sc *e2eScenario) WalkFor(ang float64, dt time.Duration, name string) {
	sc.runFor(ang, e2eWalkDist, dt, name)
}

func (sc *e2eScenario) WalkStart(ang float64, dt time.Duration, name string) {
	sc.runStart(ang, e2eWalkDist, name)
	sc.Wait(dt, "")
}

func (sc *e2eScenario) WalkDir(ang float64, dt time.Duration, name string) {
	sc.runDir(ang, e2eWalkDist, name)
	sc.Wait(dt, "")
}

func (sc *e2eScenario) WalkEnd() {
	sc.runEnd(0)
}

func (sc *e2eScenario) RunFor(ang float64, dt time.Duration, name string) {
	sc.runFor(ang, e2eRunDist, dt, name)
}

func (sc *e2eScenario) RunStart(ang float64, dt time.Duration, name string) {
	sc.runStart(ang, e2eRunDist, name)
	sc.Wait(dt, "")
}

func (sc *e2eScenario) RunDir(ang float64, dt time.Duration, name string) {
	sc.runDir(ang, e2eRunDist, name)
	sc.Wait(dt, "")
}

func (sc *e2eScenario) RunEnd() {
	sc.runEnd(0)
}

func (sc *e2eScenario) Melee(ang float64, name string) {
	sc.add(0, name, func() {
		pos := e2eAngToPos(ang, 20)
		e2eQueueInput(
			&seat.MouseMoveEvent{Pos: pos, Relative: false},
			&seat.MouseButtonEvent{Button: seat.MouseButtonLeft, Pressed: true},
		)
	})
	sc.Input(1, "", &seat.MouseButtonEvent{Button: seat.MouseButtonLeft, Pressed: false})
}

func (sc *e2eScenario) Screen(name string) {
	sc.add(0, name, func() {
		fname := strings.ReplaceAll(strings.ToLower(name), " ", "_")
		fname = filepath.Join(e2e.path, "testdata", fname)
		img := copyGamePixBuffer()
		var buf bytes.Buffer
		if err := png.Encode(&buf, img); err != nil {
			panic(err)
		}
		if e2eOverride {
			_ = os.WriteFile(fname+".png", buf.Bytes(), 0644)
			return
		}
		if data, err := os.ReadFile(fname + ".png"); err == nil {
			if !bytes.Equal(buf.Bytes(), data) {
				fname2 := fname + "_got.png"
				_ = os.WriteFile(fname+"_got.png", buf.Bytes(), 0644)
				err = fmt.Errorf("unexpected screen state, see %q", fname2)
				panic(err)
			}
		} else if os.IsNotExist(err) {
			_ = os.WriteFile(fname+".png", buf.Bytes(), 0644)
		} else {
			panic(err)
		}
	})
}

func (sc *e2eScenario) Load(path string) {
	e2eLog.Printf("LOAD: %s", path)
	data, err := os.ReadFile(path)
	if err != nil {
		panic(err)
	}
	var list struct {
		Steps []struct {
			Action string        `yaml:"action"`
			Time   uint64        `yaml:"dt"`
			Dur    time.Duration `yaml:"dur"`
			Name   string        `yaml:"name"`
			X      int           `yaml:"x"`
			Y      int           `yaml:"y"`
			Ang    float64       `yaml:"ang"`
			Slot   int           `yaml:"slot"`
		} `yaml:"steps"`
	}
	err = yaml.Unmarshal(data, &list)
	if err != nil {
		panic(err)
	}
	for _, l := range list.Steps {
		dt := time.Duration(l.Time)
		if l.Dur != 0 {
			dt = l.Dur
		}
		switch l.Action {
		case "quit":
			sc.Quit(dt)
		case "slow":
			sc.Slow(dt)
		case "wait":
			sc.Wait(dt, l.Name)
		case "move":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.Move(l.X, l.Y, l.Name)
		case "click":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.ClickLeft(l.X, l.Y, l.Name)
		case "interact":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.ClickSlowLeft(l.X, l.Y, l.Name)
		case "walk":
			sc.WalkFor(l.Ang, dt, l.Name)
		case "walk-start":
			sc.WalkStart(l.Ang, dt, l.Name)
		case "walk-dir":
			sc.WalkDir(l.Ang, dt, l.Name)
		case "walk-stop":
			sc.WalkEnd()
		case "run":
			sc.RunFor(l.Ang, dt, l.Name)
		case "run-start":
			sc.RunStart(l.Ang, dt, l.Name)
		case "run-dir":
			sc.RunDir(l.Ang, dt, l.Name)
		case "run-stop":
			sc.RunEnd()
		case "screen":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.Screen(l.Name)
		case "esc":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.Key(keybind.KeyEsc, l.Name)
		case "inventory":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.Key(keybind.KeyI, l.Name)
		case "jump":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.Key(keybind.KeySpace, l.Name)
		case "melee":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			sc.Melee(l.Ang, l.Name)
		case "cast":
			if dt != 0 {
				sc.Wait(dt, "")
			}
			switch l.Slot {
			default:
				fallthrough
			case 1:
				sc.Key(keybind.KeyA, l.Name)
			case 2:
				sc.Key(keybind.KeyS, l.Name)
			case 3:
				sc.Key(keybind.KeyD, l.Name)
			case 4:
				sc.Key(keybind.KeyF, l.Name)
			case 5:
				sc.Key(keybind.KeyG, l.Name)
			}
		default:
			panic("unsupported type: " + l.Action)
		}
	}
}

var (
	e2eJobs = make(chan *e2eScenario)
)

func e2eInit() {
	e2e.path = filepath.Join(filepath.Dir(os.Args[0]), "e2e")
	fname := filepath.Join(e2e.path, "e2e.yaml")
	if s := os.Getenv("NOX_E2E"); s != "" && s != "true" {
		fname = s
		e2e.path = filepath.Dir(s)
	}

	e2eLog.Println("WARNING: starting in e2e test mode")
	e2e.p = newPlayformE2E()
	platform.Set(e2e.p)

	go testInit(fname)
	sc, ok := <-e2eJobs
	if !ok {
		panic("cannot init e2e")
	}
	e2eQueue(sc)
}

func e2eDone() {
	close(e2eJobs)
}

func testInit(fname string) {
	defer e2eDone()
	var sc e2eScenario
	sc.Load(fname)
	sc.Exec()
}

func e2eQueue(sc *e2eScenario) {
	var last time.Duration
	if n := len(e2e.steps); n == 0 {
		last = e2e.p.ticks()
	} else {
		last = e2e.steps[n-1].time
	}
	for _, st := range sc.steps {
		st.time += last
		e2e.steps = append(e2e.steps, st)
	}
	sc.steps = nil
	e2e.done = sc.done
}

func e2eQueueInput(evs ...seat.InputEvent) {
	e2e.input = append(e2e.input, evs...)
}

func e2eRun() {
	defer e2e.p.tick(1)
	if e2e.slow != 0 {
		time.Sleep(e2e.slow)
	}
	if len(e2e.steps) == 0 {
		if e2e.done != nil {
			close(e2e.done)
			e2e.done = nil
			e2eLog.Println("DONE")
			if sc, ok := <-e2eJobs; ok {
				e2eQueue(sc)
			} else {
				e2e.realEnable = true
				if e2e.slow == 0 {
					e2e.slow = 15 * time.Millisecond
				}
				e2eLog.Println("SCRIPT COMPLETE")
			}
		}
		return
	}
	t := e2e.p.Ticks()
	n := 0
	for _, s := range e2e.steps {
		if t < s.time {
			break
		}
		n++
		if s.name != "" {
			e2eLog.Println("STATE:", s.name)
		}
		if s.fnc != nil {
			s.fnc()
		}
	}
	e2e.steps = e2e.steps[n:]
}

func e2eRealInput(ev seat.InputEvent) {
	t := platform.Ticks()
	switch ev := ev.(type) {
	case *seat.MouseMoveEvent:
		if !ev.Relative {
			e2e.realMouse = ev.Pos
		}
	case *seat.MouseButtonEvent:
		e2eLog.Printf("input(%v,%d): %#v @ %v", t, uint64(t), ev, e2e.realMouse)
	}
	if e2e.realEnable {
		e2eQueueInput(ev)
		return
	}
	switch ev := ev.(type) {
	case seat.WindowEvent:
		switch ev {
		case seat.WindowClosed:
			e2eQueueInput(ev)
			e2e.realEnable = true
			e2e.steps = nil
		}
	}
}

func e2eInputTick() {
	for _, ev := range e2e.input {
		for _, fnc := range e2e.onInput {
			fnc(ev)
		}
	}
	e2e.input = e2e.input[:0]
}
