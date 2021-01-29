package main

import (
	"unicode/utf16"

	"github.com/veandco/go-sdl2/sdl"
)

var inTextInput = false

func inputStartTextInput() {
	sdl.StartTextInput()
	inTextInput = true
}

func inputStopTextInput() {
	sdl.StopTextInput()
	inTextInput = false
}

func processTextEditingEvent(ev *sdl.TextEditingEvent) {
	text := ev.GetText()
	out := utf16.Encode([]rune(text))
	setIMEBuffer(out)
}

func processTextInputEvent(ev *sdl.TextInputEvent) {
	text := ev.GetText()
	setIMEBuffer(nil)
	for _, c := range utf16.Encode([]rune(text)) {
		noxInputOnChar(c)
	}
}

func processTextInputKeyboardEvent(ev *sdl.KeyboardEvent) {
	// TODO: special handling for WASM
	processKeyboardEvent(ev)
}
