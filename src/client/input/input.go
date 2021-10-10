package input

import (
	"image"

	"nox/v1/client/input/keybind"
	"nox/v1/client/seat"
	"nox/v1/common/log"
	"nox/v1/common/types"
)

var (
	Log = log.New("input")
)

type Checker interface {
	CheckInputFlag() bool
}

type CheckerFunc func() bool

func (f CheckerFunc) CheckInputFlag() bool {
	return f()
}

type Sequencer interface {
	NextEventSeq() uint
}

var _ Sequencer = (*Handler)(nil)

type Handler struct {
	inp seat.Input
	m   *mouseHandler
	k   *keyboardHandler
	textHandler
	inputSeq           uint
	nox_input_seq      uint
	nox_input_seq_prev uint
	onQuit             []func()
}

// New creates a new input handler.
func New(inp seat.Input, chk Checker, lang int) *Handler {
	h := &Handler{inp: inp}
	h.m = newMouseHandler(h, chk)
	h.k = newKeyboardHandler(h, chk)
	h.SetLanguage(lang)
	inp.OnInput(h.InputEvent)
	return h
}

// NextEventSeq implements Sequencer.
func (h *Handler) NextEventSeq() uint {
	v := h.inputSeq
	h.inputSeq++
	return v
}

// CurrentSeq returns current event sequence number.
func (h *Handler) CurrentSeq() uint {
	return h.nox_input_seq
}

func (h *Handler) SeqDelay() int {
	return int(h.nox_input_seq) - int(h.nox_input_seq_prev)
}

// GetSensitivity returns current mouse sensitivity setting.
func (h *Handler) GetSensitivity() float32 {
	return h.m.GetSensitivity()
}

// SetSensitivity sets mouse sensitivity.
func (h *Handler) SetSensitivity(v float32) {
	h.m.SetSensitivity(v)
}

// GetMousePos returns current mouse position in canvas coordinates.
func (h *Handler) GetMousePos() types.Point {
	return h.m.GetMousePos()
}

// GetMouseRel returns relative mouse position in canvas coordinates.
func (h *Handler) GetMouseRel() types.Point {
	return h.m.GetMouseRel()
}

// ChangeMousePos changes mouse position either in absolute value or relatively.
func (h *Handler) ChangeMousePos(p image.Point, isAbs bool) {
	h.m.ChangeMousePos(p, isAbs)
}

// SetMouseBounds changes mouse boundaries.
func (h *Handler) SetMouseBounds(rect image.Rectangle) {
	h.m.SetMouseBounds(rect)
}

// IsMousePressed check if mouse button is pressed.
func (h *Handler) IsMousePressed(btn seat.MouseButton) bool {
	return h.m.IsMousePressed(btn)
}

// GetMouseState return current mouse button state.
func (h *Handler) GetMouseState(btn seat.MouseButton) uint {
	return h.m.GetMouseState(btn)
}

// SetMouseState sets current mouse button state.
func (h *Handler) SetMouseState(btn seat.MouseButton, st uint) {
	h.m.SetMouseState(btn, st)
}

// MouseAction checks if specific mouse action can be triggered.
func (h *Handler) MouseAction(key keybind.Key, ev keybind.Event) bool {
	return h.m.MouseAction(key, ev)
}

func (h *Handler) GetDistSlow() bool {
	return h.m.GetDistSlow()
}

// GetMouseWheel returns current mouse wheel value.
func (h *Handler) GetMouseWheel() int {
	return h.m.GetMouseWheel()
}

// SetMouseWheel sets current mouse wheel value.
func (h *Handler) SetMouseWheel(v int) {
	h.m.SetMouseWheel(v)
}

// IsPressed checks if keyboard key is pressed.
func (h *Handler) IsPressed(key keybind.Key) bool {
	return h.k.IsPressed(key)
}

// IsReleased checks if keyboard key is released.
func (h *Handler) IsReleased(key keybind.Key) bool {
	return h.k.IsReleased(key)
}

// KeyModCtrl checks if Ctrl key is pressed.
func (h *Handler) KeyModCtrl() bool {
	return h.k.KeyModCtrl()
}

// KeyModAlt checks if Alt key is pressed.
func (h *Handler) KeyModAlt() bool {
	return h.k.KeyModAlt()
}

// KeyModShift checks if Shift key is pressed.
func (h *Handler) KeyModShift() bool {
	return h.k.KeyModShift()
}

// GetKeyFlag returns a flag for a given key.
func (h *Handler) GetKeyFlag(key keybind.Key) bool {
	return h.k.GetKeyFlag(key)
}

// SetKeyFlag sets a flag for a given key.
func (h *Handler) SetKeyFlag(key keybind.Key, val bool) {
	h.k.SetFlagKey(key, val)
}

// KeyboardKeys lists active keyboard keys.
func (h *Handler) KeyboardKeys() []keybind.Key {
	return h.k.KeyboardKeys()
}

// SetTextInput enables or disables text input mode.
func (h *Handler) SetTextInput(enable bool) {
	h.inp.SetTextInput(enable)
}

// GetTextEditBuf returns a text edit buffer containing IME characters of an incomplete UTF-8 rune.
func (h *Handler) GetTextEditBuf() string {
	return h.k.GetInputEditBuffer()
}

// OnQuit registers a function that will be called when the user tries to close the game.
func (h *Handler) OnQuit(fnc func()) {
	h.onQuit = append(h.onQuit, fnc)
}

// OnToggleFullScreen registers a function that will be called when the user tries toggle fullscreen mode.
func (h *Handler) OnToggleFullScreen(fnc func()) {
	h.k.OnToggleFullScreen(fnc)
}

// OnMouseWheel registers a function that will be called when a mouse wheel is scrolled.
func (h *Handler) OnMouseWheel(fnc func(dv int)) {
	h.m.OnMouseWheel(fnc)
}

// OnKeyPress registers a function that will be called when a keyboard key is pressed.
func (h *Handler) OnKeyPress(fnc func(key keybind.Key)) {
	h.k.OnKeyPress(fnc)
}

// OnInputString registers a function that will be called on string input.
func (h *Handler) OnInputString(fnc func(str string)) {
	h.k.OnInputString(fnc)
}

// SetWinSize sets the viewport size of the window that accepts input events.
func (h *Handler) SetWinSize(rect image.Rectangle) {
	h.m.SetWinSize(rect)
}

// SetDrawWinSize sets the canvas size for the window. All mouse input positions will be scaled to this size.
func (h *Handler) SetDrawWinSize(sz types.Size) {
	h.m.SetDrawWinSize(sz)
}

// InputEvent handles a single input event.
func (h *Handler) InputEvent(ev seat.InputEvent) {
	switch ev := ev.(type) {
	case seat.WindowEvent:
		h.onWindow(ev)
	case *seat.MouseMoveEvent:
		h.m.MouseMove(ev)
	case *seat.MouseButtonEvent:
		h.m.MouseButton(ev)
	case *seat.MouseWheelEvent:
		h.m.MouseWheel(ev)
	case *seat.KeyboardEvent:
		h.k.Keyboard(ev)
	case *seat.TextEditEvent:
		h.k.TextEdit(ev)
	case *seat.TextInputEvent:
		h.k.TextInput(ev)
	}
}

func (h *Handler) onWindow(ev seat.WindowEvent) {
	switch ev {
	case seat.WindowClosed:
		for _, fnc := range h.onQuit {
			fnc()
		}
	case seat.WindowFocused:
		Log.Println("focused")
		// TODO
	case seat.WindowUnfocused:
		Log.Println("unfocused")
		// TODO
	}
}

func (h *Handler) Reset() {
	h.k.nox_xxx_initKeyboard_yyy()
	h.m.noxResetMouseBuffer(h.nox_input_seq)
}

func (h *Handler) Tick() {
	// poll events
	h.inp.InputTick()
	// process events
	if h.m.nox_client_readMouseBuffer_4306A0(h.nox_input_seq, true) {
		h.nox_input_seq_prev = h.nox_input_seq
	}
	if h.k.nox_xxx_getKeyFromKeyboard_430710(h.nox_input_seq) {
		h.nox_input_seq_prev = h.nox_input_seq
	}
	h.nox_input_seq++
}
