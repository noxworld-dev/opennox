//+build !server

package input

import (
	"image"
	"log"
	"math"

	"nox/common/types"

	"github.com/veandco/go-sdl2/sdl"
)

const (
	gpadStickMax        = math.MaxInt16
	gpadTrigMax         = math.MaxInt16
	gpadMouseSpeed      = 50.0
	gpadDeadZone        = 1500
	gpadStickRelAutoRun = 0.3
)

type Stick struct {
	Pos  image.Point
	DPos image.Point
}

func (s *Stick) SetX(v int) {
	s.DPos.X = v - s.Pos.X
	s.Pos.X = v
}

func (s *Stick) SetY(v int) {
	s.DPos.Y = v - s.Pos.Y
	s.Pos.Y = v
}

func (s *Stick) Posf() types.Pointf {
	return types.Pointf{
		X: float32(s.Pos.X) / gpadStickMax,
		Y: float32(s.Pos.Y) / gpadStickMax,
	}
}

type Trigger struct {
	Val     int
	DVal    int
	Clicked bool
	OnClick func(pressed bool)
}

func (t *Trigger) SetV(v int) {
	t.DVal = v - t.Val
	t.Val = v
	t.maybeClick()
}

func (t *Trigger) maybeClick() {
	if t.OnClick == nil {
		return
	}
	if t.Clicked {
		if t.Val < gpadTrigMax/2 {
			t.Clicked = false
			t.OnClick(t.Clicked)
		}
	} else {
		if t.Val > gpadTrigMax/2 {
			t.Clicked = true
			t.OnClick(t.Clicked)
		}
	}
}

func (h *Handler) newGamepad(ind int, p *sdl.GameController) *Gamepad {
	g := &Gamepad{h: h, g: p, ind: ind}
	g.ltrig.OnClick = func(pressed bool) {
		h.inputKeyboard(sdl.SCANCODE_W, pressed)
	}
	g.rtrig.OnClick = func(pressed bool) {
		h.inputKeyboard(sdl.SCANCODE_E, pressed)
	}
	return g
}

type Gamepad struct {
	h   *Handler
	g   *sdl.GameController
	ind int

	lstick Stick
	rstick Stick
	ltrig  Trigger
	rtrig  Trigger

	rel struct {
		running bool
	}
	abs struct {
		mouse types.Pointf
	}
}

func (g *Gamepad) InRelative() bool {
	if g == nil {
		return false
	}
	s := g.StickRel()
	return abs(s.Pos.X) > gpadDeadZone || abs(s.Pos.Y) > gpadDeadZone
}

func (g *Gamepad) StickRel() *Stick {
	return &g.lstick
}

func (g *Gamepad) StickAbs() *Stick {
	return &g.rstick
}

func (g *Gamepad) Close() {
	log.Printf("Closed controller %d\n", g.ind)
	g.g.Close()
	g.g = nil
	g.ind = -1
}

func (h *Handler) cleanupControllers() {
	if h.gpad != nil {
		h.gpad.Close()
		h.gpad = nil
	}
}

func (h *Handler) processGamepadDeviceEvent(ev *sdl.ControllerDeviceEvent) {
	i := int(ev.Which)
	if ev.GetType() == sdl.CONTROLLERDEVICEREMOVED {
		if h.gpad == nil || i != h.gpad.ind {
			return
		}
		h.gpad.Close()
		h.gpad = nil
		// TODO: check if other devices are still available
		return
	}
	if !sdl.IsGameController(i) {
		return
	}
	name := sdl.GameControllerNameForIndex(i)
	log.Printf("Game controller connected %d: %s\n", i, name)
	if h.gpad != nil {
		return // already have one
	}
	g := sdl.GameControllerOpen(i)
	if g == nil {
		log.Printf("ERROR: Could not open gamecontroller %i: %s\n", i, sdl.GetError())
		return
	}
	h.gpad = h.newGamepad(i, g)
	log.Printf("Opened controller %d\n", i)
}

func (h *Handler) processGamepadAxisEvent(ev *sdl.ControllerAxisEvent) {
	v := int(ev.Value)
	switch ev.Axis {
	case sdl.CONTROLLER_AXIS_LEFTX:
		h.gpad.lstick.SetX(v)
	case sdl.CONTROLLER_AXIS_LEFTY:
		h.gpad.lstick.SetY(v)
	case sdl.CONTROLLER_AXIS_RIGHTX:
		h.gpad.rstick.SetX(v)
	case sdl.CONTROLLER_AXIS_RIGHTY:
		h.gpad.rstick.SetY(v)
	case sdl.CONTROLLER_AXIS_TRIGGERLEFT:
		h.gpad.ltrig.SetV(v)
	case sdl.CONTROLLER_AXIS_TRIGGERRIGHT:
		h.gpad.rtrig.SetV(v)
	}
}

func (h *Handler) processGamepadButtonEvent(ev *sdl.ControllerButtonEvent) {
	pressed := ev.State == sdl.PRESSED
	switch ev.Button {
	// spells are on the dpad
	case sdl.CONTROLLER_BUTTON_DPAD_UP:
		h.inputKeyboard(sdl.SCANCODE_S, pressed) // spell 2
	case sdl.CONTROLLER_BUTTON_DPAD_DOWN:
		h.inputKeyboard(sdl.SCANCODE_F, pressed) // spell 4
	case sdl.CONTROLLER_BUTTON_DPAD_LEFT:
		h.inputKeyboard(sdl.SCANCODE_A, pressed) // spell 1
	case sdl.CONTROLLER_BUTTON_DPAD_RIGHT:
		h.inputKeyboard(sdl.SCANCODE_D, pressed) // spell 3
	case sdl.CONTROLLER_BUTTON_A: // down button
		h.inputKeyboard(sdl.SCANCODE_SPACE, pressed) // jump
	case sdl.CONTROLLER_BUTTON_B: // right button
		h.inputKeyboard(sdl.SCANCODE_Z, pressed) // poison potion
	case sdl.CONTROLLER_BUTTON_X: // left button
		h.inputKeyboard(sdl.SCANCODE_Q, pressed) // inventory
	case sdl.CONTROLLER_BUTTON_Y: // up button
		h.inputKeyboard(sdl.SCANCODE_V, pressed) // switch weapons
	case sdl.CONTROLLER_BUTTON_BACK:
		h.inputKeyboard(sdl.SCANCODE_ESCAPE, pressed) // back
	case sdl.CONTROLLER_BUTTON_GUIDE:
		// none
	case sdl.CONTROLLER_BUTTON_START:
		h.inputKeyboard(sdl.SCANCODE_TAB, pressed) // map
	case sdl.CONTROLLER_BUTTON_LEFTSTICK:
		h.inputKeyboard(sdl.SCANCODE_X, pressed) // health potion
	case sdl.CONTROLLER_BUTTON_RIGHTSTICK:
		h.inputKeyboard(sdl.SCANCODE_C, pressed) // mana potion
	case sdl.CONTROLLER_BUTTON_LEFTSHOULDER:
		h.inputKeyboard(sdl.SCANCODE_G, pressed) // spell 5
	case sdl.CONTROLLER_BUTTON_RIGHTSHOULDER:
		h.MouseButton(MouseButtonLeft, pressed) // attack
	}
}

func (h *Handler) controllerTick() {
	if h.gpad == nil {
		return
	}
	h.gpad.Tick()
}

func (h *Handler) Gamepad() *Gamepad {
	return h.gpad
}

func (g *Gamepad) Tick() {
	if g == nil {
		return
	}
	g.tickAbs()
	g.tickRelative()
}

func (g *Gamepad) tickAbs() {
	// absolute stick acts as a mouse pointer, os it should move as long as stick has any values
	s := g.StickAbs()
	if abs(s.Pos.X) < gpadDeadZone && abs(s.Pos.Y) < gpadDeadZone {
		return
	}
	dpos := s.Posf()
	if dx := dpos.X; dx >= 0 {
		g.abs.mouse.X += dx * dx * gpadMouseSpeed
	} else {
		g.abs.mouse.X -= dx * dx * gpadMouseSpeed
	}
	if dy := dpos.Y; dy >= 0 {
		g.abs.mouse.Y += dy * dy * gpadMouseSpeed
	} else {
		g.abs.mouse.Y -= dy * dy * gpadMouseSpeed
	}
	g.abs.mouse = g.h.win.inputClampf(g.abs.mouse)
	g.h.MouseSet(g.abs.mouse.Point())
}

func (g *Gamepad) tickRelative() {
	// automatically start running on a specific threshold on relative stick
	rel := g.StickRel().Posf()
	relV := rel.X*rel.X + rel.Y*rel.Y
	if g.rel.running {
		if relV < gpadStickRelAutoRun {
			g.h.MouseUp(MouseButtonRight) // stop running
			g.rel.running = false
		}
	} else {
		if relV > gpadStickRelAutoRun {
			g.h.MouseDown(MouseButtonRight) // start running
			g.rel.running = true
		}
	}
}
