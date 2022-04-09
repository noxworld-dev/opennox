package gui

import (
	noxcolor "github.com/noxworld-dev/opennox-lib/color"
)

type StyleDefaults struct {
	EnabledColor    noxcolor.Color16
	DisabledColor   noxcolor.Color16
	BackgroundColor noxcolor.Color16
	HighlightColor  noxcolor.Color16
	SelectedColor   noxcolor.Color16
	TextColor       noxcolor.Color16
}

func (s *StyleDefaults) SetColors(def noxcolor.Color16) {
	s.EnabledColor = def
	s.DisabledColor = def
	s.BackgroundColor = def
	s.HighlightColor = def
	s.SelectedColor = def
	s.TextColor = def
}
