package main

import "nox/v1/client/input/keybind"

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

var (
	imeBuffer            string
	keyBinding           *keybind.Binding
	keyboardEventQueue   = make(chan noxKeyEvent, keyboardEventBuf)
	nox_input_map_byKey  = make(map[keybind.Key]noxKeyState)
	nox_input_arr_787228 [256]noxKeyEventInt
)

func setIMEBuffer(buf string) {
	imeBuffer = buf
}

type noxKeyEvent struct {
	Code    keybind.Key
	Pressed bool
	Seq     uint
}

func pushKeyEvent(e noxKeyEvent) {
	e.Seq = nextInputSeq()
	select {
	case keyboardEventQueue <- e:
	default:
		inputLog.Println("cannot keep up, keyboard event dropped")
	}
}

func nextKeyEvent() *noxKeyEvent {
	select {
	case e, ok := <-keyboardEventQueue:
		if !ok {
			return nil
		}
		return &e
	default:
		return nil
	}
}

func nox_xxx_getKeyFromKeyboardImpl_47FA80() (noxKeyEventInt, bool) {
	ke := nextKeyEvent()
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

func nox_xxx_initKeyboard_yyy() {
	for key := keybind.Key(0); key <= 0xff; key++ {
		nox_input_map_byKey[key] = noxKeyState{
			state:  1,
			field2: false,
			seq:    0,
		}
	}
}

func inputSetKey4309B0(k keybind.Key, v bool) {
	st := nox_input_map_byKey[k]
	st.field2 = v
	nox_input_map_byKey[k] = st
}

func sub_4307D0() bool {
	if get_obj_5D4594_754104_switch() {
		return false
	}
	li := 0
	for li = 0; nox_input_arr_787228[li].code != 0; li++ {
	}
	for k, p := range nox_input_map_byKey {
		if p.state == 2 && nox_input_prev_seq-p.seq > 10 {
			nox_input_arr_787228[li].code = k
			nox_input_arr_787228[li].state = 2
			nox_input_arr_787228[li].field2 = false
			nox_input_arr_787228[li+1].code = 0
			for k2, p2 := range nox_input_map_byKey {
				if k == k2 {
					p2.seq = nox_input_prev_seq - 12
				} else {
					p2.seq = nox_input_prev_seq
				}
				nox_input_map_byKey[k2] = p2
			}
			return true
		}
	}
	return false
}
