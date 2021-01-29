package main

import (
	"fmt"
	"log"

	"github.com/veandco/go-sdl2/sdl"

	"nox/common/types"
)

var gpad *gamepad

type gamepadStick struct {
	Pos  types.Point
	DPos types.Point
}

func (s *gamepadStick) setX(v int) {
	s.DPos.X = v - s.Pos.X
	s.Pos.X = v
}

func (s *gamepadStick) setY(v int) {
	s.DPos.Y = v - s.Pos.Y
	s.Pos.Y = v
}

func (s *gamepadStick) Posf() types.Pointf {
	return types.Pointf{
		X: float32(s.Pos.X) / gpadStickMax,
		Y: float32(s.Pos.Y) / gpadStickMax,
	}
}

type gamepadTrigger struct {
	Val     int
	DVal    int
	Clicked bool
	OnClick func(pressed bool)
}

func (t *gamepadTrigger) setV(v int) {
	t.DVal = v - t.Val
	t.Val = v
	t.maybeClick()
}

func (t *gamepadTrigger) maybeClick() {
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

func newGamepad(ind int, p *sdl.GameController) *gamepad {
	g := &gamepad{g: p, ind: ind}
	g.ltrig.OnClick = func(pressed bool) {
		inputKeyboard(sdl.SCANCODE_W, pressed)
	}
	g.rtrig.OnClick = func(pressed bool) {
		inputKeyboard(sdl.SCANCODE_E, pressed)
	}
	return g
}

type gamepad struct {
	g   *sdl.GameController
	ind int

	lstick gamepadStick
	rstick gamepadStick
	ltrig  gamepadTrigger
	rtrig  gamepadTrigger

	rel struct {
		running bool
	}
	abs struct {
		mouse types.Pointf
	}
}

func (g *gamepad) InRelative() bool {
	if g == nil {
		return false
	}
	s := g.stickRel()
	return abs(s.Pos.X) > gpadDeadZone || abs(s.Pos.Y) > gpadDeadZone
}

func (g *gamepad) stickRel() *gamepadStick {
	return &g.lstick
}

func (g *gamepad) stickAbs() *gamepadStick {
	return &g.rstick
}

func (g *gamepad) Close() {
	fmt.Printf("Closed controller %d\n", g.ind)
	g.g.Close()
	g.g = nil
	g.ind = -1
}

func inputCleanupControllers() {
	if gpad != nil {
		gpad.Close()
		gpad = nil
	}
}

func processGamepadDeviceEvent(ev *sdl.ControllerDeviceEvent) {
	i := int(ev.Which)
	if ev.GetType() == sdl.CONTROLLERDEVICEREMOVED {
		if gpad == nil || i != gpad.ind {
			return
		}
		gpad.Close()
		gpad = nil
		// TODO: check if other devices are still available
		return
	}
	if !sdl.IsGameController(i) {
		return
	}
	name := sdl.GameControllerNameForIndex(i)
	fmt.Printf("Game controller connected %d: %s\n", i, name)
	if gpad != nil {
		return // already have one
	}
	g := sdl.GameControllerOpen(i)
	if g == nil {
		log.Printf("ERROR: Could not open gamecontroller %i: %s\n", i, sdl.GetError())
		return
	}
	gpad = newGamepad(i, g)
	fmt.Printf("Opened controller %d\n", i)
}

func processGamepadAxisEvent(ev *sdl.ControllerAxisEvent) {
	v := int(ev.Value)
	switch ev.Axis {
	case sdl.CONTROLLER_AXIS_LEFTX:
		gpad.lstick.setX(v)
	case sdl.CONTROLLER_AXIS_LEFTY:
		gpad.lstick.setY(v)
	case sdl.CONTROLLER_AXIS_RIGHTX:
		gpad.rstick.setX(v)
	case sdl.CONTROLLER_AXIS_RIGHTY:
		gpad.rstick.setY(v)
	case sdl.CONTROLLER_AXIS_TRIGGERLEFT:
		gpad.ltrig.setV(v)
	case sdl.CONTROLLER_AXIS_TRIGGERRIGHT:
		gpad.rtrig.setV(v)
	}
}

func processGamepadButtonEvent(ev *sdl.ControllerButtonEvent) {
	pressed := ev.State == sdl.PRESSED
	switch ev.Button {
	// spells are on the dpad
	case sdl.CONTROLLER_BUTTON_DPAD_UP:
		inputKeyboard(sdl.SCANCODE_S, pressed) // spell 2
	case sdl.CONTROLLER_BUTTON_DPAD_DOWN:
		inputKeyboard(sdl.SCANCODE_F, pressed) // spell 4
	case sdl.CONTROLLER_BUTTON_DPAD_LEFT:
		inputKeyboard(sdl.SCANCODE_A, pressed) // spell 1
	case sdl.CONTROLLER_BUTTON_DPAD_RIGHT:
		inputKeyboard(sdl.SCANCODE_D, pressed) // spell 3
	case sdl.CONTROLLER_BUTTON_A: // down button
		inputKeyboard(sdl.SCANCODE_SPACE, pressed) // jump
	case sdl.CONTROLLER_BUTTON_B: // right button
		inputKeyboard(sdl.SCANCODE_Z, pressed) // poison potion
	case sdl.CONTROLLER_BUTTON_X: // left button
		inputKeyboard(sdl.SCANCODE_Q, pressed) // inventory
	case sdl.CONTROLLER_BUTTON_Y: // up button
		inputKeyboard(sdl.SCANCODE_V, pressed) // switch weapons
	case sdl.CONTROLLER_BUTTON_BACK:
		inputKeyboard(sdl.SCANCODE_ESCAPE, pressed) // back
	case sdl.CONTROLLER_BUTTON_GUIDE:
		// none
	case sdl.CONTROLLER_BUTTON_START:
		inputKeyboard(sdl.SCANCODE_TAB, pressed) // map
	case sdl.CONTROLLER_BUTTON_LEFTSTICK:
		inputKeyboard(sdl.SCANCODE_X, pressed) // health potion
	case sdl.CONTROLLER_BUTTON_RIGHTSTICK:
		inputKeyboard(sdl.SCANCODE_C, pressed) // mana potion
	case sdl.CONTROLLER_BUTTON_LEFTSHOULDER:
		inputKeyboard(sdl.SCANCODE_G, pressed) // spell 5
	case sdl.CONTROLLER_BUTTON_RIGHTSHOULDER:
		inputMouseButton(noxMouseButtonLeft, pressed) // attack
	}
}

func inputControllerTick() {
	if gpad == nil {
		return
	}
	gpad.Tick()
}

func (g *gamepad) Tick() {
	if g == nil {
		return
	}
	g.tickAbs()
	g.tickRelative()
}

func (g *gamepad) tickAbs() {
	// absolute stick acts as a mouse pointer, os it should move as long as stick has any values
	s := g.stickAbs()
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
	gpad.abs.mouse = inputClampf(gpad.abs.mouse)
	inputMouseSet(gpad.abs.mouse.Point())
}

func (g *gamepad) tickRelative() {
	// automatically start running on a specific threshold on relative stick
	rel := g.stickRel().Posf()
	relV := rel.X*rel.X + rel.Y*rel.Y
	if g.rel.running {
		if relV < gpadStickRelAutoRun {
			inputMouseUp(noxMouseButtonRight) // stop running
			g.rel.running = false
		}
	} else {
		if relV > gpadStickRelAutoRun {
			inputMouseDown(noxMouseButtonRight) // start running
			g.rel.running = true
		}
	}
}
