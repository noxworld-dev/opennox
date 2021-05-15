package gui

const (
	StylePushButton    = StyleFlags(0x1)
	StyleRadioButton   = StyleFlags(0x2)
	StyleCheckBox      = StyleFlags(0x4)
	StyleVertSlider    = StyleFlags(0x8)
	StyleHorizSlider   = StyleFlags(0x10)
	StyleScrollListBox = StyleFlags(0x20)
	StyleEntryField    = StyleFlags(0x80)
	StyleStaticText    = StyleFlags(0x800)
	StyleProgressBar   = StyleFlags(0x1000)
	StyleUserWindow    = StyleFlags(0x2000)
)

type StyleFlags int

func (s *StyleFlags) Set(s2 StyleFlags) {
	*s |= s2
}

func (s StyleFlags) IsPushButton() bool {
	return s&StylePushButton != 0
}

func (s StyleFlags) IsRadioButton() bool {
	return s&StyleRadioButton != 0
}

func (s StyleFlags) IsCheckBox() bool {
	return s&StyleCheckBox != 0
}

func (s StyleFlags) IsVertSlider() bool {
	return s&StyleVertSlider != 0
}

func (s StyleFlags) IsHorizSlider() bool {
	return s&StyleHorizSlider != 0
}

func (s StyleFlags) IsScrollListBox() bool {
	return s&StyleScrollListBox != 0
}

func (s StyleFlags) IsEntryField() bool {
	return s&StyleEntryField != 0
}

func (s StyleFlags) IsStaticText() bool {
	return s&StyleStaticText != 0
}

func (s StyleFlags) IsProgressBar() bool {
	return s&StyleProgressBar != 0
}

func (s StyleFlags) IsUserWindow() bool {
	return s&StyleUserWindow != 0
}
