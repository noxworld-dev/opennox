package gui

const (
	StylePushButton    = StyleFlags(1 << iota) // 0x1
	StyleRadioButton                           // 0x2
	StyleCheckBox                              // 0x4
	StyleVertSlider                            // 0x8
	StyleHorizSlider                           // 0x10
	StyleScrollListBox                         // 0x20
	StyleFadeListBox                           // 0x40
	StyleEntryField                            // 0x80
	StyleMouseTrack                            // 0x100
	StyleAnimated                              // 0x200
	StyleTabStop                               // 0x400
	StyleStaticText                            // 0x800
	StyleProgressBar                           // 0x1000
	StyleUserWindow                            // 0x2000
)

type StyleFlags uint

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
