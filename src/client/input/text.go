package input

import (
	"unicode"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
)

type inputCharMap struct {
	lower string
	upper string
	ext   string
}

type textHandler struct {
	capsState bool
	modKey    keybind.Key
	textMap   map[keybind.Key]inputCharMap
}

func (h *Handler) SetLanguage(code int) { // nox_xxx_initKeyboard_47FB10
	h.capsState = h.KeyModShift()
	h.textMap = make(map[keybind.Key]inputCharMap, 256)
	for k, v := range noxInputMapGeneric {
		h.textMap[k] = v
	}
	h.modKey = 0
	var m map[keybind.Key]inputCharMap
	switch code {
	case 0, 4, 6, 7, 8, 9:
		m = noxInputMapLang0
	case 1:
		m = noxInputMapLang1
		h.modKey = 0xb8
	case 2:
		m = noxInputMapLang2
		h.modKey = 0xb8
	case 3:
		m = noxInputMapLang3
		h.modKey = 0xb8
	case 5:
		m = noxInputMapLang5
		h.modKey = 0xb8
	}
	for k, v := range m {
		h.textMap[k] = v
	}
}

func (h *Handler) KeyToWChar(r keybind.Key) uint16 { // nox_input_scanCodeToAlpha
	if r > 0xFF {
		return uint16(r)
	}
	switch r {
	case keybind.KeyLShift, keybind.KeyRShift:
		return 0
	case h.modKey:
		return 0
	case keybind.KeyCaps:
		if !h.GetKeyFlag(r) {
			if h.IsPressed(r) {
				h.capsState = !h.capsState
			}
			h.SetKeyFlag(r, true)
		}
		return 0
	}
	if h.IsPressed(h.modKey) {
		return str2u16(h.textMap[r].ext)
	}
	if h.KeyModShift() || h.capsState && iswalpha(str2u16(h.textMap[r].lower)) {
		if h.KeyModAlt() {
			return str2u16(noxInputMapLangX[r].upper)
		}
		return str2u16(h.textMap[r].upper)
	}
	if h.KeyModAlt() {
		return str2u16(noxInputMapLangX[r].lower)
	}
	return str2u16(h.textMap[r].lower)
}

func str2u16(s string) uint16 {
	if s == "" {
		return 0
	}
	// TODO: properly read it as UTF-16?
	b := []byte(s)
	if len(b) == 1 {
		return uint16(b[0])
	}
	return uint16(b[0]) | uint16(b[1])<<8
}

func iswalpha(b uint16) bool {
	// check only for the range we care about in this file
	if b >= 192 {
		return false
	}
	switch b {
	case 170, 181, 186:
		return false
	default:
		return unicode.IsLetter(rune(b))
	}
}

var (
	noxInputMapGeneric = map[keybind.Key]inputCharMap{
		0xe:  {lower: "\b", upper: "\b"},
		0xf:  {lower: "\t", upper: "\t"},
		0x1c: {lower: "\n", upper: "\n"},
		0x39: {lower: " ", upper: " "},
		0x52: {lower: "0", upper: "0"},
		0x4f: {lower: "1", upper: "1"},
		0x50: {lower: "2", upper: "2"},
		0x51: {lower: "3", upper: "3"},
		0x4b: {lower: "4", upper: "4"},
		0x4c: {lower: "5", upper: "5"},
		0x4d: {lower: "6", upper: "6"},
		0x47: {lower: "7", upper: "7"},
		0x48: {lower: "8", upper: "8"},
		0x49: {lower: "9", upper: "9"},
		0xd3: {lower: "\b", upper: "\b"},
	}
	noxInputMapLang0 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "@"},
		0x4:  {lower: "3", upper: "#"},
		0x5:  {lower: "4", upper: "$"},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "^"},
		0x8:  {lower: "7", upper: "&"},
		0x9:  {lower: "8", upper: "*"},
		0xa:  {lower: "9", upper: "("},
		0xb:  {lower: "0", upper: ")"},
		0xc:  {lower: "-", upper: "_"},
		0xd:  {lower: "=", upper: "+"},
		0x10: {lower: "q", upper: "Q"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "[", upper: "{"},
		0x1b: {lower: "]", upper: "}"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: ";", upper: ":"},
		0x28: {lower: "'", upper: "\""},
		0x29: {lower: "`", upper: "~"},
		0x2b: {lower: "\\", upper: "|"},
		0x2c: {lower: "z", upper: "Z"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M"},
		0x33: {lower: ",", upper: "<"},
		0x34: {lower: ".", upper: ">"},
		0x35: {lower: "/", upper: "?"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang1 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "\""},
		0x4:  {lower: "3", upper: "\xa3"},
		0x5:  {lower: "4", upper: "$", ext: "\xac "},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "^"},
		0x8:  {lower: "7", upper: "&"},
		0x9:  {lower: "8", upper: "*"},
		0xa:  {lower: "9", upper: "("},
		0xb:  {lower: "0", upper: ")"},
		0xc:  {lower: "-", upper: "_"},
		0xd:  {lower: "=", upper: "+"},
		0x10: {lower: "q", upper: "Q"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "[", upper: "{"},
		0x1b: {lower: "]", upper: "}"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: ";", upper: ":"},
		0x28: {lower: "'", upper: "@"},
		0x29: {lower: "`", upper: "\xac", ext: "\xa6"},
		0x2b: {lower: "#", upper: "~"},
		0x2c: {lower: "z", upper: "Z"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M"},
		0x33: {lower: ",", upper: "<"},
		0x34: {lower: ".", upper: ">"},
		0x35: {lower: "/", upper: "?"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x56: {lower: "\\", upper: "|"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang2 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "\"", ext: "\xb2"},
		0x4:  {lower: "3", upper: "\xa7", ext: "\xb3"},
		0x5:  {lower: "4", upper: "$"},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "&"},
		0x8:  {lower: "7", upper: "/", ext: "{"},
		0x9:  {lower: "8", upper: "(", ext: "["},
		0xa:  {lower: "9", upper: ")", ext: "]"},
		0xb:  {lower: "0", upper: "=", ext: "}"},
		0xc:  {lower: "\xdf", upper: "?", ext: "\\"},
		0xd:  {lower: "\xb4", upper: "`"},
		0x10: {lower: "q", upper: "Q", ext: "@"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "z", upper: "Z"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "\xfc", upper: "\xdc"},
		0x1b: {lower: "+", upper: "*", ext: "~"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: "\xf6", upper: "\xd6"},
		0x28: {lower: "\xe4", upper: "\xc4"},
		0x29: {lower: "^", upper: "\xb0"},
		0x2b: {lower: "#", upper: "'"},
		0x2c: {lower: "y", upper: "Y"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M", ext: "\xb5"},
		0x33: {lower: ",", upper: ";"},
		0x34: {lower: ".", upper: ":"},
		0x35: {lower: "-", upper: "_"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ",", upper: ","},
		0x56: {lower: "<", upper: ">", ext: "|"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang3 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "&", upper: "1"},
		0x3:  {lower: "\xe9", upper: "2", ext: "~"},
		0x4:  {lower: "\"", upper: "3", ext: "#"},
		0x5:  {lower: "'", upper: "4", ext: "{"},
		0x6:  {lower: "(", upper: "5", ext: "["},
		0x7:  {lower: "-", upper: "6", ext: "|"},
		0x8:  {lower: "\xe8", upper: "7", ext: "`"},
		0x9:  {lower: "_", upper: "8", ext: "\\"},
		0xa:  {lower: "\xe7", upper: "9"},
		0xb:  {lower: "\xe0", upper: "0", ext: "@"},
		0xc:  {lower: ")", upper: "\xb0", ext: "]"},
		0xd:  {lower: "=", upper: "+", ext: "}"},
		0x10: {lower: "a", upper: "A"},
		0x11: {lower: "z", upper: "Z"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "^", upper: "\xa8"},
		0x1b: {lower: "$", upper: "\xa3", ext: "\xa4"},
		0x1e: {lower: "q", upper: "Q"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: "m", upper: "M"},
		0x28: {lower: "\xf9", upper: "%"},
		0x29: {lower: "\xb2", upper: ""},
		0x2b: {lower: "*", upper: "\xb5"},
		0x2c: {lower: "w", upper: "W"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: ",", upper: "?"},
		0x33: {lower: ";", upper: "."},
		0x34: {lower: ":", upper: "/"},
		0x35: {lower: "!", upper: "\xa7"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x56: {lower: "<", upper: ">"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLang5 = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "\""},
		0x4:  {lower: "3", upper: "\xa3"},
		0x5:  {lower: "4", upper: "$"},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "&"},
		0x8:  {lower: "7", upper: "/"},
		0x9:  {lower: "8", upper: "("},
		0xa:  {lower: "9", upper: ")"},
		0xb:  {lower: "0", upper: "="},
		0xc:  {lower: "'", upper: "?"},
		0xd:  {lower: "\xec", upper: "^"},
		0x10: {lower: "q", upper: "Q"},
		0x11: {lower: "w", upper: "W"},
		0x12: {lower: "e", upper: "E"},
		0x13: {lower: "r", upper: "R"},
		0x14: {lower: "t", upper: "T"},
		0x15: {lower: "y", upper: "Y"},
		0x16: {lower: "u", upper: "U"},
		0x17: {lower: "i", upper: "I"},
		0x18: {lower: "o", upper: "O"},
		0x19: {lower: "p", upper: "P"},
		0x1a: {lower: "\xe8", upper: "\xe9", ext: "["},
		0x1b: {lower: "+", upper: "*", ext: "]"},
		0x1e: {lower: "a", upper: "A"},
		0x1f: {lower: "s", upper: "S"},
		0x20: {lower: "d", upper: "D"},
		0x21: {lower: "f", upper: "F"},
		0x22: {lower: "g", upper: "G"},
		0x23: {lower: "h", upper: "H"},
		0x24: {lower: "j", upper: "J"},
		0x25: {lower: "k", upper: "K"},
		0x26: {lower: "l", upper: "L"},
		0x27: {lower: "\xf2", upper: "\xe7", ext: "@"},
		0x28: {lower: "\xe0", upper: "\xb0", ext: "#"},
		0x29: {lower: "\\", upper: "|"},
		0x2b: {lower: "\xf9", upper: "\xa7"},
		0x2c: {lower: "z", upper: "Z"},
		0x2d: {lower: "x", upper: "X"},
		0x2e: {lower: "c", upper: "C"},
		0x2f: {lower: "v", upper: "V"},
		0x30: {lower: "b", upper: "B"},
		0x31: {lower: "n", upper: "N"},
		0x32: {lower: "m", upper: "M"},
		0x33: {lower: ",", upper: ";"},
		0x34: {lower: ".", upper: ":"},
		0x35: {lower: "-", upper: "_"},
		0x37: {lower: "*", upper: "*"},
		0x4a: {lower: "-", upper: "-"},
		0x4e: {lower: "+", upper: "+"},
		0x53: {lower: ".", upper: "."},
		0x56: {lower: "<", upper: ">"},
		0x9c: {lower: "\n", upper: "\n"},
		0xb5: {lower: "/", upper: "/"},
	}
	noxInputMapLangX = map[keybind.Key]inputCharMap{
		0x2:  {lower: "1", upper: "!"},
		0x3:  {lower: "2", upper: "@"},
		0x4:  {lower: "3", upper: "#"},
		0x5:  {lower: "4", upper: "$"},
		0x6:  {lower: "5", upper: "%"},
		0x7:  {lower: "6", upper: "^"},
		0x8:  {lower: "7", upper: "&"},
		0x9:  {lower: "8", upper: "*"},
		0xa:  {lower: "9", upper: "("},
		0xb:  {lower: "0", upper: ")"},
		0xc:  {lower: "-", upper: "_"},
		0xd:  {lower: "=", upper: "+"},
		0xe:  {lower: "\b", upper: "\b"},
		0xf:  {lower: "\t", upper: "\t"},
		0x10: {lower: "\xe9", upper: "\xc9"},
		0x11: {lower: "\xf6", upper: "\xd6"},
		0x12: {lower: "\xf3", upper: "\xd3"},
		0x13: {lower: "\xea", upper: "\xca"},
		0x14: {lower: "\xe5", upper: "\xc5"},
		0x15: {lower: "\xed", upper: "\xcd"},
		0x16: {lower: "\xe3", upper: "\xc3"},
		0x17: {lower: "\xf8", upper: "\xd8"},
		0x18: {lower: "\xf9", upper: "\xd9"},
		0x19: {lower: "\xe7", upper: "\xc7"},
		0x1a: {lower: "\xf5", upper: "\xd5"},
		0x1b: {lower: "\xfa", upper: "\xda"},
		0x1c: {lower: "\n", upper: "\n"},
		0x1e: {lower: "\xf4", upper: "\xd4"},
		0x1f: {lower: "\xfb", upper: "\xdb"},
		0x20: {lower: "\xe2", upper: "\xc2"},
		0x21: {lower: "\xe0", upper: "\xc0"},
		0x22: {lower: "\xef", upper: "\xcf"},
		0x23: {lower: "\xf0", upper: "\xd0"},
		0x24: {lower: "\xee", upper: "\xce"},
		0x25: {lower: "\xeb", upper: "\xcb"},
		0x26: {lower: "\xe4", upper: "\xc4"},
		0x27: {lower: "\xe6", upper: "\xc6"},
		0x28: {lower: "\xfd", upper: "\xdd"},
		0x29: {lower: "`", upper: "~"},
		0x2b: {lower: "\\", upper: "|"},
		0x2c: {lower: "\xff", upper: "\xdf"},
		0x2d: {lower: "\xf7", upper: "\xd7"},
		0x2e: {lower: "\xf1", upper: "\xd1"},
		0x2f: {lower: "\xec", upper: "\xcc"},
		0x30: {lower: "\xe8", upper: "\xc8"},
		0x31: {lower: "\xf2", upper: "\xd2"},
		0x32: {lower: "\xfc", upper: "\xdc"},
		0x33: {lower: "\xe1", upper: "\xc1"},
		0x34: {lower: "\xfe", upper: "\xde"},
		0x35: {lower: "/", upper: "?"},
		0x37: {lower: "*", upper: "*"},
		0x39: {lower: " ", upper: " "},
		0x47: {lower: "7", upper: "7"},
		0x48: {lower: "8", upper: "8"},
		0x49: {lower: "9", upper: "9"},
		0x4a: {lower: "-", upper: "-"},
		0x4b: {lower: "4", upper: "4"},
		0x4c: {lower: "5", upper: "5"},
		0x4d: {lower: "6", upper: "6"},
		0x4e: {lower: "+", upper: "+"},
		0x4f: {lower: "1", upper: "1"},
		0x50: {lower: "2", upper: "2"},
		0x51: {lower: "3", upper: "3"},
		0x52: {lower: "0", upper: "0"},
		0x53: {lower: ".", upper: "."},
	}
)
