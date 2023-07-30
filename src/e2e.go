package opennox

import (
	"bytes"
	"encoding/hex"
	"fmt"
	"hash"
	"image"
	"image/png"
	"io"
	"io/fs"
	"math"
	"os"
	"path/filepath"
	"strings"
	"time"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"golang.org/x/crypto/blake2b"
	"golang.org/x/exp/maps"
	"gopkg.in/yaml.v2"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/client/seat"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/platform"
	"github.com/noxworld-dev/opennox-lib/types"
)

var (
	e2eLog = log.New("E2E")

	e2ePlay     = os.Getenv("NOX_E2E")
	e2eRecord   = os.Getenv("NOX_E2E_RECORD")
	e2eSlow     = os.Getenv("NOX_E2E_SLOW")
	e2eOverride = os.Getenv("NOX_E2E_OVERRIDE") == "true"
	e2eFailFast = os.Getenv("NOX_E2E_FAILFAST") != "false"
)

const e2eDefaultDelay = 15 * time.Millisecond

var e2e struct {
	recording bool
	path      string
	p         *platformE2E
	onInput   []func(ev seat.InputEvent)

	slow       time.Duration
	real       seat.Seat
	realMouse  image.Point
	realEnable bool

	done      chan<- struct{}
	steps     []e2eStep
	input     []seat.InputEvent
	recorded  []e2eRecordedEvent
	err       error
	checkSave *e2eCheckSave
}

func e2eError(err error) {
	if e2eFailFast {
		panic(err)
	}
	e2eLog.Println(err)
	e2e.err = err
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
	sc.add(1, "", func() {
		if e2e.err != nil {
			panic(e2e.err)
		}
	})
}

func (sc *e2eScenario) Move(x, y int, name string) {
	sc.Input(0, name, &seat.MouseMoveEvent{Pos: image.Point{X: x, Y: y}, Relative: false})
}

func (sc *e2eScenario) Click(pos image.Point, btn seat.MouseButton, name string) {
	sc.Input(0, name,
		&seat.MouseMoveEvent{Pos: pos, Relative: false},
		&seat.MouseButtonEvent{Button: btn, Pressed: true},
	)
	sc.Input(1, "", &seat.MouseButtonEvent{Button: btn, Pressed: false})
}

func (sc *e2eScenario) ClickSlow(pos image.Point, btn seat.MouseButton, name string) {
	sc.Input(0, name, &seat.MouseMoveEvent{Pos: pos, Relative: false})
	sc.Input(1, "", &seat.MouseButtonEvent{Button: btn, Pressed: true})
	sc.Input(1, "", &seat.MouseButtonEvent{Button: btn, Pressed: false})
}

func (sc *e2eScenario) Key(key keybind.Key, name string) {
	sc.Input(0, name, &seat.KeyboardEvent{Key: key, Pressed: true})
	sc.Input(1, "", &seat.KeyboardEvent{Key: key, Pressed: false})
}

func (sc *e2eScenario) ClickLeft(x, y int, name string) {
	sc.Click(image.Point{X: x, Y: y}, seat.MouseButtonLeft, name)
}

func (sc *e2eScenario) ClickSlowLeft(x, y int, name string) {
	sc.ClickSlow(image.Point{X: x, Y: y}, seat.MouseButtonLeft, name)
}

func e2eAngToPos(ang float64, dist int) image.Point {
	sz := image.Point{X: 1024, Y: 768}
	rad := (0.5 - ang) * math.Pi
	return image.Point{
		X: sz.X/2 + int(math.Cos(rad)*float64(dist)),
		Y: sz.Y/2 - int(math.Sin(rad)*float64(dist)),
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

func imageDiff(pix1, pix2 []byte) []byte {
	out := make([]byte, len(pix1))
	for i := range out {
		dp := int16(pix1[i]) - int16(pix2[i])
		if dp < 0 {
			dp = -dp
		}
		dp *= 10
		if dp > 0xff {
			dp = 0xff
		}
		if i%4 == 3 { // alpha
			dp = 0xff - dp
		}
		out[i] = byte(dp)
	}
	return out
}

type e2eCheckSave struct {
	Name   string
	Hashes map[string]string
}

func (sc *e2eScenario) Save(name string, hashes map[string]string) {
	sc.add(0, name, func() {
		e2e.checkSave = &e2eCheckSave{Name: name, Hashes: hashes}
	})
}

func (sc *e2eScenario) Screen(name string) {
	sc.add(0, name, func() {
		fname := strings.ReplaceAll(strings.ToLower(name), " ", "_")
		fname = filepath.Join(e2e.path, "testdata", fname)
		img := noxClient.r.CopyPixBuffer()
		var ibuf bytes.Buffer
		if err := png.Encode(&ibuf, img); err != nil {
			panic(err)
		}
		if e2eOverride {
			_ = os.WriteFile(fname+".png", ibuf.Bytes(), 0644)
			return
		}
		gotName := fname + "_got.png"
		diffName := fname + "_diff.png"
		if _, err := os.Stat(gotName); err == nil {
			if err = os.Remove(gotName); err != nil {
				e2eLog.Println(err)
			}
		}
		if _, err := os.Stat(diffName); err == nil {
			if err = os.Remove(diffName); err != nil {
				e2eLog.Println(err)
			}
		}
		if data, err := os.ReadFile(fname + ".png"); err == nil {
			exp, err := png.Decode(bytes.NewReader(data))
			if err != nil {
				panic(err)
			}
			var edata []byte
			switch exp := exp.(type) {
			case *image.RGBA:
				edata = exp.Pix
			case *image.NRGBA:
				edata = exp.Pix
			default:
				panic(exp)
			}
			if !bytes.Equal(img.Pix, edata) {
				_ = os.WriteFile(gotName, ibuf.Bytes(), 0644)

				diff := imageDiff(img.Pix, edata)
				ibuf.Reset()
				img.Pix = diff
				if err := png.Encode(&ibuf, img); err != nil {
					panic(err)
				}
				_ = os.WriteFile(diffName, ibuf.Bytes(), 0644)
				e2eError(err)
			}
		} else if os.IsNotExist(err) {
			_ = os.WriteFile(fname+".png", ibuf.Bytes(), 0644)
		} else {
			panic(err)
		}
	})
}

type e2eFileYML struct {
	Steps []e2eStepYML `yaml:"steps"`
}

type e2eStepYML struct {
	Action string        `yaml:"action"`
	Time   uint64        `yaml:"dt,omitempty"`
	Dur    time.Duration `yaml:"dur,omitempty"`
	Name   string        `yaml:"name,omitempty"`
	X      int           `yaml:"x,omitempty"`
	Y      int           `yaml:"y,omitempty"`
	Ang    float64       `yaml:"ang,omitempty"`
	Slot   int           `yaml:"slot,omitempty"`
	Event  *e2eStepRaw   `yaml:"ev,omitempty"`
}

func (sc *e2eScenario) Load(path string) {
	e2eLog.Printf("LOAD: %s", path)
	data, err := os.ReadFile(path)
	if err != nil {
		panic(err)
	}
	var list e2eFileYML
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
		case "raw":
			ev := l.Event
			switch ev.Type {
			case "save":
				sc.Save(ev.SaveName, ev.Hashes)
			case "move":
				sc.Input(dt, "", &seat.MouseMoveEvent{
					Relative: ev.Relative, Pos: ev.Pos, Rel: ev.Rel,
				})
			case "button":
				sc.Input(dt, "", &seat.MouseButtonEvent{
					Pressed: ev.Pressed, Button: ev.Button,
				})
			case "wheel":
				sc.Input(dt, "", &seat.MouseWheelEvent{
					Wheel: ev.Wheel,
				})
			case "key":
				sc.Input(dt, "", &seat.KeyboardEvent{
					Pressed: ev.Pressed, Key: ev.Key,
				})
			case "text_edit":
				sc.Input(dt, "", &seat.TextEditEvent{
					Text: ev.Text,
				})
			case "text_input":
				sc.Input(dt, "", &seat.TextInputEvent{
					Text: ev.Text,
				})
			case "closed":
				sc.Input(dt, "", seat.WindowClosed)
			default:
				panic("unsupported type: " + ev.Type)
			}
		default:
			panic("unsupported type: " + l.Action)
		}
	}
}

var (
	e2eJobs = make(chan *e2eScenario)
)

func e2eAbsPath(s string) string {
	if filepath.IsAbs(s) {
		return s
	}
	if _, err := os.Stat(s); err != nil {
		s = filepath.Join(filepath.Dir(os.Args[0]), s)
	}
	p, err := filepath.Abs(s)
	if err != nil {
		panic(err)
	}
	return p
}

func e2eInit() {
	opennoxDir := filepath.Dir(os.Args[0])
	e2e.path = filepath.Join(opennoxDir, "e2e")
	fname := filepath.Join(e2e.path, "e2e.yaml")
	if s := e2eRecord; s != "" {
		if filepath.Ext(s) == "" {
			s = filepath.Join(s, "e2e.yaml")
		}
		s = e2eAbsPath(s)
		e2e.recording = true
		fname = s
		e2e.path = s
	} else if s = e2ePlay; s != "" && s != "true" {
		s = e2eAbsPath(s)
		fname = s
		e2e.path = filepath.Dir(s)
	}
	if s := e2eSlow; s != "" {
		dt, err := time.ParseDuration(s)
		if err != nil {
			panic(err)
		}
		e2e.slow = dt
	}

	e2eLog.Println("WARNING: starting in e2e test mode")
	e2e.p = newPlayformE2E()
	platform.Set(e2e.p)
	if e2e.recording {
		e2eLog.Printf("RECORD: %s", fname)
		if e2e.slow == 0 {
			e2e.slow = e2eDefaultDelay
		}
		return
	}

	go testInit(fname)
	sc, ok := <-e2eJobs
	if !ok {
		panic("cannot init e2e")
	}
	e2eQueue(sc)
}

type e2eStepRaw struct {
	Type string `yaml:"type"`

	Relative bool         `yaml:"rel,omitempty"`
	Pos      image.Point  `yaml:"pos,omitempty"`
	Rel      types.Pointf `yaml:"pos_rel,omitempty"`

	Button  seat.MouseButton `yaml:"button,omitempty"`
	Pressed bool             `yaml:"pressed,omitempty"`
	Key     keybind.Key      `yaml:"key,omitempty"`

	Wheel int `yaml:"wheel,omitempty"`

	Text string `yaml:"text,omitempty"`

	SaveName string            `yaml:"savename,omitempty"`
	Hashes   map[string]string `yaml:"hashes,omitempty"`
}

func e2eSaveRecording() {
	var list e2eFileYML
	var last time.Duration
	for _, r := range e2e.recorded {
		dt := r.Time - last
		last = r.Time
		if r.Save != nil {
			list.Steps = append(list.Steps, e2eStepYML{
				Action: "raw",
				Time:   uint64(dt),
				Event: &e2eStepRaw{
					Type:     "save",
					SaveName: r.Save.Name,
					Hashes:   r.Save.Hash,
				},
			})
		} else if r.Input != nil {
			s := e2eStepYML{Action: "raw", Time: uint64(dt)}
			switch ev := r.Input.(type) {
			case *seat.MouseMoveEvent:
				s.Event = &e2eStepRaw{
					Type:     "move",
					Relative: ev.Relative,
					Pos:      ev.Pos,
					Rel:      ev.Rel,
				}
			case *seat.MouseButtonEvent:
				s.Event = &e2eStepRaw{
					Type:    "button",
					Pressed: ev.Pressed,
					Button:  ev.Button,
				}
			case *seat.MouseWheelEvent:
				s.Event = &e2eStepRaw{
					Type:  "wheel",
					Wheel: ev.Wheel,
				}
			case *seat.KeyboardEvent:
				s.Event = &e2eStepRaw{
					Type:    "key",
					Pressed: ev.Pressed,
					Key:     ev.Key,
				}
			case *seat.TextEditEvent:
				s.Event = &e2eStepRaw{
					Type: "text_edit",
					Text: ev.Text,
				}
			case *seat.TextInputEvent:
				s.Event = &e2eStepRaw{
					Type: "text_input",
					Text: ev.Text,
				}
			case seat.WindowEvent:
				switch ev {
				case seat.WindowClosed:
					s.Event = &e2eStepRaw{
						Type: "closed",
					}
				default:
					e2eLog.Printf("SKIPPED: %T", ev)
				}
			default:
				e2eLog.Printf("SKIPPED: %T", ev)
			}
			if s.Event != nil {
				list.Steps = append(list.Steps, s)
			}
		}
	}
	f, err := os.Create(e2e.path)
	if err != nil {
		panic(err)
	}
	defer f.Close()
	enc := yaml.NewEncoder(f)
	if err = enc.Encode(list); err != nil {
		panic(err)
	}
	if err = f.Close(); err != nil {
		panic(err)
	}
	e2eLog.Printf("RECORDED: %d events", len(list.Steps))
}

func e2eStop() {
	if !e2e.recording {
		return
	}
	e2eSaveRecording()
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
	if e2e.recording {
		return
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
					e2e.slow = e2eDefaultDelay
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

type e2eRecordedEvent struct {
	Time  time.Duration
	Input seat.InputEvent
	Save  *e2eSave
}

type e2eSave struct {
	Name string            `json:"name"`
	Hash map[string]string `json:"hash"`
}

func e2eOnSave(name string) {
	if e2e.recording {
		t := platform.Ticks()
		path := datapath.Save(name)
		hash := e2eHashDir(path)
		e2e.recorded = append(e2e.recorded, e2eRecordedEvent{
			Time: t - 1, Save: &e2eSave{Name: name, Hash: hash},
		})
	} else if s := e2e.checkSave; s != nil {
		defer func() {
			e2e.checkSave = nil
		}()
		path := datapath.Save(name)
		got := e2eHashDir(path)
		if !maps.Equal(got, s.Hashes) {
			err := fmt.Errorf("unexpected save data:\ngot: %+v\nvs\nexp: %+v", got, s.Hashes)
			e2eError(err)
		}
	}
}

func e2eRealInput(ev seat.InputEvent) {
	t := platform.Ticks()
	if e2e.recording {
		if ev == seat.WindowClosed {
			e2eSaveRecording()
		}
		e2e.recorded = append(e2e.recorded, e2eRecordedEvent{
			Time: t - 1, Input: ev,
		})
		e2eQueueInput(ev)
		return
	}
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

const e2eInputConf = `
---
MousePickup = Left
MOUSE_BUTTON_RIGHT = MoveForward
MOUSE_BUTTON_LEFT = Action
SPACE = Jump
MOUSE_BUTTON_MID = Jump
I = ToggleInventory
Q = ToggleInventory
B = ToggleBook
TAB = ToggleMap
1 = MapZoomOut
2 = MapZoomIn
A = InvokeSlot1
S = InvokeSlot2
D = InvokeSlot3
F = InvokeSlot4
G = InvokeSlot5
MOUSE_WHEEL_UP = PreviousSpellSet
W = PreviousSpellSet
MOUSE_WHEEL_DOWN = NextSpellSet
E = NextSpellSet
R = SelectSpellSet
LEFT_SHIFT = InvertSpellTarget
RIGHT_SHIFT = InvertSpellTarget
T = PlaceTrapBomber
V = SwapWeapons
X = QuickHealth
C = QuickMana
Z = QuickCurePoison
ENTER = Chat
BACKSPACE = TeamChat
F1 = ToggleConsole
ESC = ToggleQuitMenu
HOME = ToggleServerMenu
F9 = ToggleRank
F10 = ToggleNetstat
F11 = ToggleGUI
F2 = AutoSave
F4 = AutoLoad
J = Taunt
K = Point
L = Laugh
PAGEUP = IncreaseWindowSize
PAGEDOWN = DecreaseWindowSize
INS = IncreaseGamma
DEL = DecreaseGamma
F12 = ScreenShot
---
`

func e2eHash() hash.Hash {
	h, err := blake2b.New256(nil)
	if err != nil {
		panic(err)
	}
	return h
}

func e2eHashDir(dir string) map[string]string {
	hashes := make(map[string]string)
	err := ifs.WalkDir(dir, func(path string, d fs.DirEntry, err error) error {
		if err != nil {
			return err
		}
		if d.IsDir() {
			return nil
		}
		h := e2eHash()
		f, err := ifs.Open(path)
		if err != nil {
			return err
		}
		defer f.Close()
		_, err = io.Copy(h, f)
		if err != nil {
			return err
		}
		name := strings.TrimPrefix(path, dir)
		name = strings.TrimPrefix(name, string(filepath.Separator))
		name = strings.ReplaceAll(name, string(filepath.Separator), "/")
		hashes[name] = hex.EncodeToString(h.Sum(nil))
		return nil
	})
	if err != nil {
		panic(err)
	}
	return hashes
}
