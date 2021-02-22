package gui

import (
	"io"
	"unicode"
)

func ParseNextToken(r io.ByteReader) (string, error) {
	tab := true
	var out []byte
	for {
		b, err := r.ReadByte()
		if err == io.EOF {
			return string(out), nil
		} else if err != nil {
			return string(out), err
		}
		if b == ';' {
			return string(out), nil
		}
		if !unicode.IsSpace(rune(b)) {
			tab = false
			out = append(out, b)
		} else if !tab {
			out = append(out, ' ')
		}
	}
}
