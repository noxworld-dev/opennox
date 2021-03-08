//+build !server

package input

import (
	"github.com/veandco/go-sdl2/sdl"
)

const (
	KeyShift = Keymod(sdl.KMOD_RSHIFT | sdl.KMOD_LSHIFT)
	KeyAltR  = Keymod(sdl.KMOD_RALT)
)

func (h *Handler) inputKeyboard(code sdl.Scancode, pressed bool) {
	if h.iface == nil {
		return
	}
	h.iface.InputKeyboard(Scancode(code), pressed)
}

func (h *Handler) processKeyboardEvent(ev *sdl.KeyboardEvent) {
	h.inputKeyboard(ev.Keysym.Scancode, ev.State == sdl.PRESSED)
}

func (h *Handler) processTextEditingEvent(ev *sdl.TextEditingEvent) {
	h.iface.TextEdit(ev.GetText())
}

func (h *Handler) processTextInputEvent(ev *sdl.TextInputEvent) {
	h.iface.TextInput(ev.GetText())
}

func (h *Handler) KeyModState(mod Keymod) bool {
	return sdl.GetModState()&sdl.Keymod(mod) != 0
}

func (h *Handler) StartTextInput() {
	sdl.StartTextInput()
}

func (h *Handler) StopTextInput() {
	sdl.StopTextInput()
}
