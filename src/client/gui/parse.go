package gui

import (
	"image/color"
	"io"
	"strconv"
	"strings"
	"unicode"
)

func ReadNextToken(r io.ByteReader) (string, error) {
	tab := true
	var out []byte
	for {
		b, err := r.ReadByte()
		if err == io.EOF {
			if len(out) == 0 {
				return "", io.EOF
			}
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

func ParseNextField(str string) (v, rest string) {
	const space = " \t\n\r"
	str = strings.TrimLeft(str, space)
	i := strings.IndexAny(str, " \t\n\r")
	if i < 0 {
		return str, ""
	}
	return str[:i], str[i+1:]
}

func ParseNextUintField(str string) (v uint, rest string) {
	var s string
	s, rest = ParseNextField(str)
	vi, _ := strconv.ParseUint(s, 10, 64)
	return uint(vi), rest
}

func ParseNextIntField(str string) (v int, rest string) {
	var s string
	s, rest = ParseNextField(str)
	vi, _ := strconv.ParseInt(s, 10, 64)
	return int(vi), rest
}

func ParseColor(str string) (r, g, b int) {
	var v uint
	v, str = ParseNextUintField(str)
	r = int(v)

	v, str = ParseNextUintField(str)
	g = int(v)

	v, str = ParseNextUintField(str)
	b = int(v)
	return
}

func ParseColorTransp(str string) (color.Color, bool) {
	if str == "TRANSPARENT" {
		return color.Transparent, true
	}
	r, g, b := ParseColor(str)
	return color.NRGBA{R: byte(r), G: byte(g), B: byte(b), A: 0xff}, true
}
