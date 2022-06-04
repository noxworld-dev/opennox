package gui

import (
	"image/color"
)

type StyleDefaults struct {
	EnabledColor    color.Color
	DisabledColor   color.Color
	BackgroundColor color.Color
	HighlightColor  color.Color
	SelectedColor   color.Color
	TextColor       color.Color
}

func (s *StyleDefaults) SetColors(def color.Color) {
	s.EnabledColor = def
	s.DisabledColor = def
	s.BackgroundColor = def
	s.HighlightColor = def
	s.SelectedColor = def
	s.TextColor = def
}
