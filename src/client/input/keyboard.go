package input

import (
	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/client/seat"
)

const keyboardEventBuf = 256

type noxKeyEventInt struct {
	code   keybind.Key
	state  byte
	field2 bool
	field3 byte
	seq    uint
}

type noxKeyState struct {
	state  byte
	field2 bool
	seq    uint
}

type noxKeyEvent struct {
	Code    keybind.Key
	Pressed bool
	Seq     uint
}

func newKeyboardHandler(s Sequencer, chk bool) *keyboardHandler {
	h := &keyboardHandler{
		seq:                 s,
		chk:                 chk,
		keyboardEventQueue:  make(chan noxKeyEvent, keyboardEventBuf),
		nox_input_map_byKey: make(map[keybind.Key]noxKeyState),
	}
	h.nox_xxx_initKeyboard_yyy()
	return h
}

type keyboardHandler struct {
	seq                  Sequencer
	chk                  bool
	imeBuffer            string
	keyBinding           *keybind.Binding
	keyboardEventQueue   chan noxKeyEvent
	nox_input_map_byKey  map[keybind.Key]noxKeyState
	nox_input_arr_787228 [256]noxKeyEventInt
	onFullScreen         []func()
	onString             []func(str string)
	onKeyPress           []func(key keybind.Key)
}

func (h *keyboardHandler) OnToggleFullScreen(fnc func()) {
	h.onFullScreen = append(h.onFullScreen, fnc)
}

func (h *keyboardHandler) OnInputString(fnc func(str string)) {
	h.onString = append(h.onString, fnc)
}

func (h *keyboardHandler) OnKeyPress(fnc func(key keybind.Key)) {
	h.onKeyPress = append(h.onKeyPress, fnc)
}

func (h *keyboardHandler) nox_xxx_initKeyboard_yyy() {
	for key := keybind.Key(0); key <= 0xff; key++ {
		h.nox_input_map_byKey[key] = noxKeyState{
			state:  1,
			field2: false,
			seq:    0,
		}
	}
}

func (h *keyboardHandler) GetInputEditBuffer() string {
	return h.imeBuffer
}

func (h *keyboardHandler) setIMEBuffer(buf string) {
	h.imeBuffer = buf
}

func (h *keyboardHandler) GetKeyFlag(k keybind.Key) bool {
	return h.nox_input_map_byKey[k].field2
}

func (h *keyboardHandler) IsPressed(key keybind.Key) bool {
	return h.nox_input_map_byKey[key].state == 2
}

func (h *keyboardHandler) IsReleased(key keybind.Key) bool {
	return h.nox_input_map_byKey[key].state == 1 || h.GetKeyFlag(key)
}

func (h *keyboardHandler) SetFlagKey(k keybind.Key, v bool) {
	st := h.nox_input_map_byKey[k]
	st.field2 = v
	h.nox_input_map_byKey[k] = st
}

func (h *keyboardHandler) KeyboardKeys() []keybind.Key {
	var out []keybind.Key
	for _, p := range h.nox_input_arr_787228 {
		if p.code == 0 {
			break
		}
		out = append(out, p.code)
	}
	return out
}

func (h *keyboardHandler) KeyModCtrl() bool {
	return h.IsPressed(keybind.KeyLCtrl) || h.IsPressed(keybind.KeyRCtrl)
}

func (h *keyboardHandler) KeyModAlt() bool {
	return h.IsPressed(keybind.KeyLAlt) || h.IsPressed(keybind.KeyRAlt)
}

func (h *keyboardHandler) KeyModShift() bool {
	return h.IsPressed(keybind.KeyLShift) || h.IsPressed(keybind.KeyRShift)
}

func (h *keyboardHandler) Keyboard(ev *seat.KeyboardEvent) {
	if ev.Pressed && ev.Key == keybind.KeyEnter && h.KeyModAlt() {
		for _, fnc := range h.onFullScreen {
			fnc()
		}
		return
	}
	h.pushKeyEvent(noxKeyEvent{
		Code:    ev.Key,
		Pressed: ev.Pressed,
	})
}

func (h *keyboardHandler) TextInput(ev *seat.TextInputEvent) {
	h.setIMEBuffer("")
	for _, fnc := range h.onString {
		fnc(ev.Text)
	}
}

func (h *keyboardHandler) TextEdit(ev *seat.TextEditEvent) {
	h.setIMEBuffer(ev.Text)
}

func (h *keyboardHandler) pushKeyEvent(e noxKeyEvent) {
	e.Seq = h.seq.NextEventSeq()
	select {
	case h.keyboardEventQueue <- e:
	default:
		Log.Println("cannot keep up, keyboard event dropped")
	}
}

func (h *keyboardHandler) nextKeyEvent() *noxKeyEvent {
	select {
	case e, ok := <-h.keyboardEventQueue:
		if !ok {
			return nil
		}
		return &e
	default:
		return nil
	}
}

func (h *keyboardHandler) nox_xxx_getKeyFromKeyboardImpl_47FA80() (noxKeyEventInt, bool) {
	ke := h.nextKeyEvent()
	if ke == nil {
		return noxKeyEventInt{}, false
	}
	state := 0
	if ke.Pressed {
		state = 1
	}
	return noxKeyEventInt{
		code:  ke.Code,
		state: byte(state + 1),
		seq:   ke.Seq,
	}, true
}

func (h *keyboardHandler) nox_xxx_getKeyFromKeyboard_430710(cseq uint) bool {
	for i := range h.nox_input_arr_787228 {
		ev := &h.nox_input_arr_787228[i]
		var ok bool
		*ev, ok = h.nox_xxx_getKeyFromKeyboardImpl_47FA80()
		if !ok {
			break
		}
	}

	cnt := 0
	for i := range h.nox_input_arr_787228 {
		ev := &h.nox_input_arr_787228[i]
		if ev.code == 0 {
			break
		}
		if ev.code == keybind.KeyTab {
			if h.KeyModAlt() {
				ev.field2 = true
			}
		} else {
			// FIXME: implement proper language switch
			//if ev.code == keybind.KeyCaps {
			//	nox_input_scanCodeToAlpha(ev.code)
			//}
		}
		if h.chk {
			ev.field2 = true
		}
		h.nox_input_map_byKey[ev.code] = noxKeyState{
			state:  ev.state,
			field2: ev.field2,
			seq:    cseq,
		}
		cnt++
	}
	res := h.sub_4307D0(cseq) || cnt != 0
	// TODO: this probably needs a loop
	if ev := &h.nox_input_arr_787228[0]; ev.code != 0 && !ev.field2 && ev.state == 2 {
		for _, fnc := range h.onKeyPress {
			fnc(ev.code)
		}
	}
	return res
}

func (h *keyboardHandler) sub_4307D0(cseq uint) bool {
	if h.chk {
		return false
	}
	li := 0
	for li = 0; h.nox_input_arr_787228[li].code != 0; li++ {
	}
	for k, p := range h.nox_input_map_byKey {
		if p.state == 2 && cseq-p.seq > 10 {
			h.nox_input_arr_787228[li].code = k
			h.nox_input_arr_787228[li].state = 2
			h.nox_input_arr_787228[li].field2 = false
			h.nox_input_arr_787228[li+1].code = 0
			for k2, p2 := range h.nox_input_map_byKey {
				if k == k2 {
					p2.seq = cseq - 12
				} else {
					p2.seq = cseq
				}
				h.nox_input_map_byKey[k2] = p2
			}
			return true
		}
	}
	return false
}
