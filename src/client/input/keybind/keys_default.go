package keybind

const (
	KeyKp0            = Key(0x52)
	KeyKp1            = Key(0x4f)
	KeyKp2            = Key(0x50)
	KeyKp3            = Key(0x51)
	KeyKp4            = Key(0x4b)
	KeyKp5            = Key(0x4c)
	KeyKp6            = Key(0x4d)
	KeyKp7            = Key(0x47)
	KeyKp8            = Key(0x48)
	KeyKp9            = Key(0x49)
	KeyKpPeriod       = Key(0x53)
	KeyKpStar         = Key(0x37)
	KeyKpMinus        = Key(0x4a)
	KeyKpPlus         = Key(0x4e)
	KeyKpEnter        = Key(0x9c)
	KeyKpSlash        = Key(0xb5)
	KeyEsc            = Key(0x1)
	KeyBackspace      = Key(0xe)
	KeyEnter          = Key(0x1c)
	KeySpace          = Key(0x39)
	KeyTab            = Key(0xf)
	KeyF1             = Key(0x3b)
	KeyF2             = Key(0x3c)
	KeyF3             = Key(0x3d)
	KeyF4             = Key(0x3e)
	KeyF5             = Key(0x3f)
	KeyF6             = Key(0x40)
	KeyF7             = Key(0x41)
	KeyF8             = Key(0x42)
	KeyF9             = Key(0x43)
	KeyF10            = Key(0x44)
	KeyF11            = Key(0x57)
	KeyF12            = Key(0x58)
	KeyA              = Key(0x1e)
	KeyB              = Key(0x30)
	KeyC              = Key(0x2e)
	KeyD              = Key(0x20)
	KeyE              = Key(0x12)
	KeyF              = Key(0x21)
	KeyG              = Key(0x22)
	KeyH              = Key(0x23)
	KeyI              = Key(0x17)
	KeyJ              = Key(0x24)
	KeyK              = Key(0x25)
	KeyL              = Key(0x26)
	KeyM              = Key(0x32)
	KeyN              = Key(0x31)
	KeyO              = Key(0x18)
	KeyP              = Key(0x19)
	KeyQ              = Key(0x10)
	KeyR              = Key(0x13)
	KeyS              = Key(0x1f)
	KeyT              = Key(0x14)
	KeyU              = Key(0x16)
	KeyV              = Key(0x2f)
	KeyW              = Key(0x11)
	KeyX              = Key(0x2d)
	KeyY              = Key(0x15)
	KeyZ              = Key(0x2c)
	Key1              = Key(0x2)
	Key2              = Key(0x3)
	Key3              = Key(0x4)
	Key4              = Key(0x5)
	Key5              = Key(0x6)
	Key6              = Key(0x7)
	Key7              = Key(0x8)
	Key8              = Key(0x9)
	Key9              = Key(0xa)
	Key0              = Key(0xb)
	KeyMinus          = Key(0xc)
	KeyEqual          = Key(0xd)
	KeyLBracket       = Key(0x1a)
	KeyRBracket       = Key(0x1b)
	KeySemiColon      = Key(0x27)
	KeySquote         = Key(0x28)
	KeyApos           = Key(0x29)
	KeyBslash         = Key(0x2b)
	KeyComma          = Key(0x33)
	KeyPeriod         = Key(0x34)
	KeySlash          = Key(0x35)
	KeySysReq         = Key(0xb7)
	KeyCaps           = Key(0x3a)
	KeyNumLck         = Key(0x45)
	KeyScroll         = Key(0x46)
	KeyLCtrl          = Key(0x1d)
	KeyLAlt           = Key(0x38)
	KeyLShift         = Key(0x2a)
	KeyRShift         = Key(0x36)
	KeyRAlt           = Key(0xb8)
	KeyRCtrl          = Key(0x9d)
	KeyUp             = Key(0xc8)
	KeyDown           = Key(0xd0)
	KeyLeft           = Key(0xcb)
	KeyRight          = Key(0xcd)
	KeyHome           = Key(0xc7)
	KeyEnd            = Key(0xcf)
	KeyPgUp           = Key(0xc9)
	KeyPgDn           = Key(0xd1)
	KeyIns            = Key(0xd2)
	KeyDel            = Key(0xd3)
	KeyLeftMouse      = Key(KeyMaskMouse + 0x0)
	KeyMiddleMouse    = Key(KeyMaskMouse + 0x1)
	KeyRightMouse     = Key(KeyMaskMouse + 0x2)
	KeyMouseWheelUp   = Key(KeyMaskMouse + 0x3)
	KeyMouseWheelDown = Key(KeyMaskMouse + 0x4)
)

const (
	KeyMaskMouse    = Key(0x10000)
	KeyMaskJoystick = Key(0x20000)
)

func (k Key) IsKeyboard() bool {
	return k&0xffff0000 == 0
}

func (k Key) IsMouse() bool {
	return k&KeyMaskMouse != 0
}

func (k Key) IsJoystick() bool {
	return k&KeyMaskJoystick != 0
}

var defKeys = []keyDesc{
	{Name: "KP0", Code: KeyKp0, TitleID: StrmanPref + "Kp0"},
	{Name: "KP1", Code: KeyKp1, TitleID: StrmanPref + "Kp1"},
	{Name: "KP2", Code: KeyKp2, TitleID: StrmanPref + "Kp2"},
	{Name: "KP3", Code: KeyKp3, TitleID: StrmanPref + "Kp3"},
	{Name: "KP4", Code: KeyKp4, TitleID: StrmanPref + "Kp4"},
	{Name: "KP5", Code: KeyKp5, TitleID: StrmanPref + "Kp5"},
	{Name: "KP6", Code: KeyKp6, TitleID: StrmanPref + "Kp6"},
	{Name: "KP7", Code: KeyKp7, TitleID: StrmanPref + "Kp7"},
	{Name: "KP8", Code: KeyKp8, TitleID: StrmanPref + "Kp8"},
	{Name: "KP9", Code: KeyKp9, TitleID: StrmanPref + "Kp9"},
	{Name: "KPDEL", Code: KeyKpPeriod, TitleID: StrmanPref + "KpPeriod"},
	{Name: "KPSTAR", Code: KeyKpStar, TitleID: StrmanPref + "KpStar"},
	{Name: "KPMINUS", Code: KeyKpMinus, TitleID: StrmanPref + "KpMinus"},
	{Name: "KPPLUS", Code: KeyKpPlus, TitleID: StrmanPref + "KpPlus"},
	{Name: "KPENTER", Code: KeyKpEnter, TitleID: StrmanPref + "KpEnter"},
	{Name: "KPSLASH", Code: KeyKpSlash, TitleID: StrmanPref + "KpSlash"},
	{Name: "ESC", Code: KeyEsc, TitleID: StrmanPref + "Esc"},
	{Name: "BACKSPACE", Code: KeyBackspace, TitleID: StrmanPref + "Back"},
	{Name: "ENTER", Code: KeyEnter, TitleID: StrmanPref + "Enter"},
	{Name: "SPACE", Code: KeySpace, TitleID: StrmanPref + "Space"},
	{Name: "TAB", Code: KeyTab, TitleID: StrmanPref + "Tab"},
	{Name: "F1", Code: KeyF1, TitleID: StrmanPref + "F1"},
	{Name: "F2", Code: KeyF2, TitleID: StrmanPref + "F2"},
	{Name: "F3", Code: KeyF3, TitleID: StrmanPref + "F3"},
	{Name: "F4", Code: KeyF4, TitleID: StrmanPref + "F4"},
	{Name: "F5", Code: KeyF5, TitleID: StrmanPref + "F5"},
	{Name: "F6", Code: KeyF6, TitleID: StrmanPref + "F6"},
	{Name: "F7", Code: KeyF7, TitleID: StrmanPref + "F7"},
	{Name: "F8", Code: KeyF8, TitleID: StrmanPref + "F8"},
	{Name: "F9", Code: KeyF9, TitleID: StrmanPref + "F9"},
	{Name: "F10", Code: KeyF10, TitleID: StrmanPref + "F10"},
	{Name: "F11", Code: KeyF11, TitleID: StrmanPref + "F11"},
	{Name: "F12", Code: KeyF12, TitleID: StrmanPref + "F12"},
	{Name: "A", Code: KeyA, TitleID: StrmanPref + "A"},
	{Name: "B", Code: KeyB, TitleID: StrmanPref + "B"},
	{Name: "C", Code: KeyC, TitleID: StrmanPref + "C"},
	{Name: "D", Code: KeyD, TitleID: StrmanPref + "D"},
	{Name: "E", Code: KeyE, TitleID: StrmanPref + "E"},
	{Name: "F", Code: KeyF, TitleID: StrmanPref + "F"},
	{Name: "G", Code: KeyG, TitleID: StrmanPref + "G"},
	{Name: "H", Code: KeyH, TitleID: StrmanPref + "H"},
	{Name: "I", Code: KeyI, TitleID: StrmanPref + "I"},
	{Name: "J", Code: KeyJ, TitleID: StrmanPref + "J"},
	{Name: "K", Code: KeyK, TitleID: StrmanPref + "K"},
	{Name: "L", Code: KeyL, TitleID: StrmanPref + "L"},
	{Name: "M", Code: KeyM, TitleID: StrmanPref + "M"},
	{Name: "N", Code: KeyN, TitleID: StrmanPref + "N"},
	{Name: "O", Code: KeyO, TitleID: StrmanPref + "O"},
	{Name: "P", Code: KeyP, TitleID: StrmanPref + "P"},
	{Name: "Q", Code: KeyQ, TitleID: StrmanPref + "Q"},
	{Name: "R", Code: KeyR, TitleID: StrmanPref + "R"},
	{Name: "S", Code: KeyS, TitleID: StrmanPref + "S"},
	{Name: "T", Code: KeyT, TitleID: StrmanPref + "T"},
	{Name: "U", Code: KeyU, TitleID: StrmanPref + "U"},
	{Name: "V", Code: KeyV, TitleID: StrmanPref + "V"},
	{Name: "W", Code: KeyW, TitleID: StrmanPref + "W"},
	{Name: "X", Code: KeyX, TitleID: StrmanPref + "X"},
	{Name: "Y", Code: KeyY, TitleID: StrmanPref + "Y"},
	{Name: "Z", Code: KeyZ, TitleID: StrmanPref + "Z"},
	{Name: "1", Code: Key1, TitleID: StrmanPref + "1"},
	{Name: "2", Code: Key2, TitleID: StrmanPref + "2"},
	{Name: "3", Code: Key3, TitleID: StrmanPref + "3"},
	{Name: "4", Code: Key4, TitleID: StrmanPref + "4"},
	{Name: "5", Code: Key5, TitleID: StrmanPref + "5"},
	{Name: "6", Code: Key6, TitleID: StrmanPref + "6"},
	{Name: "7", Code: Key7, TitleID: StrmanPref + "7"},
	{Name: "8", Code: Key8, TitleID: StrmanPref + "8"},
	{Name: "9", Code: Key9, TitleID: StrmanPref + "9"},
	{Name: "0", Code: Key0, TitleID: StrmanPref + "0"},
	{Name: "MINUS", Code: KeyMinus, TitleID: StrmanPref + "Minus"},
	{Name: "EQUALS", Code: KeyEqual, TitleID: StrmanPref + "Equal"},
	{Name: "LEFT_BRACKET", Code: KeyLBracket, TitleID: StrmanPref + "["},
	{Name: "RIGHT_BRACKET", Code: KeyRBracket, TitleID: StrmanPref + "]"},
	{Name: "SEMICOLON", Code: KeySemiColon, TitleID: StrmanPref + "SemiColon"},
	{Name: "APOSTROPHE", Code: KeySquote, TitleID: StrmanPref + "Squote"},
	{Name: "TICK", Code: KeyApos, TitleID: StrmanPref + "Apos"},
	{Name: "BACKSLASH", Code: KeyBslash, TitleID: StrmanPref + "Bslash"},
	{Name: "COMMA", Code: KeyComma, TitleID: StrmanPref + "Comma"},
	{Name: "PERIOD", Code: KeyPeriod, TitleID: StrmanPref + "Period"},
	{Name: "SLASH", Code: KeySlash, TitleID: StrmanPref + "Slash"},
	{Name: "SYSREQ", Code: KeySysReq, TitleID: StrmanPref + "SysReq"},
	{Name: "CAPS_LOCK", Code: KeyCaps, TitleID: StrmanPref + "Caps"},
	{Name: "NUM", Code: KeyNumLck, TitleID: StrmanPref + "NumLck"},
	{Name: "SCROLL", Code: KeyScroll, TitleID: StrmanPref + "Scroll"},
	{Name: "LEFT_CTRL", Code: KeyLCtrl, TitleID: StrmanPref + "LCtrl"},
	{Name: "LEFT_ALT", Code: KeyLAlt, TitleID: StrmanPref + "LAlt"},
	{Name: "LEFT_SHIFT", Code: KeyLShift, TitleID: StrmanPref + "LShift"},
	{Name: "RIGHT_SHIFT", Code: KeyRShift, TitleID: StrmanPref + "RShift"},
	{Name: "RIGHT_ALT", Code: KeyRAlt, TitleID: StrmanPref + "RAlt"},
	{Name: "RIGHT_CTRL", Code: KeyRCtrl, TitleID: StrmanPref + "RCtrl"},
	{Name: "UP_ARROW", Code: KeyUp, TitleID: StrmanPref + "Up"},
	{Name: "DOWN_ARROW", Code: KeyDown, TitleID: StrmanPref + "Down"},
	{Name: "LEFT_ARROW", Code: KeyLeft, TitleID: StrmanPref + "Left"},
	{Name: "RIGHT_ARROW", Code: KeyRight, TitleID: StrmanPref + "Right"},
	{Name: "HOME", Code: KeyHome, TitleID: StrmanPref + "Home"},
	{Name: "END", Code: KeyEnd, TitleID: StrmanPref + "End"},
	{Name: "PAGEUP", Code: KeyPgUp, TitleID: StrmanPref + "PgUp"},
	{Name: "PAGEDOWN", Code: KeyPgDn, TitleID: StrmanPref + "PgDn"},
	{Name: "INS", Code: KeyIns, TitleID: StrmanPref + "Ins"},
	{Name: "DEL", Code: KeyDel, TitleID: StrmanPref + "Del"},
	{Name: "MOUSE_BUTTON_LEFT", Code: KeyLeftMouse, TitleID: StrmanPref + "LeftMouse"},
	{Name: "MOUSE_BUTTON_MID", Code: KeyMiddleMouse, TitleID: StrmanPref + "MiddleMouse"},
	{Name: "MOUSE_BUTTON_RIGHT", Code: KeyRightMouse, TitleID: StrmanPref + "RightMouse"},
	{Name: "MOUSE_WHEEL_UP", Code: KeyMouseWheelUp, TitleID: StrmanPref + "MouseWheelUp"},
	{Name: "MOUSE_WHEEL_DOWN", Code: KeyMouseWheelDown, TitleID: StrmanPref + "MouseWheelDown"},
	{Name: "JOYSTICK_BUTTON_1", Code: 0x20000},
	{Name: "JOYSTICK_BUTTON_2", Code: 0x20001},
	{Name: "JOYSTICK_BUTTON_3", Code: 0x20002},
	{Name: "JOYSTICK_BUTTON_4", Code: 0x20003},
	{Name: "JOYSTICK_BUTTON_5", Code: 0x20004},
	{Name: "JOYSTICK_BUTTON_6", Code: 0x20005},
	{Name: "JOYSTICK_BUTTON_7", Code: 0x20006},
	{Name: "JOYSTICK_BUTTON_8", Code: 0x20007},
	{Name: "JOYSTICK_BUTTON_9", Code: 0x20008},
	{Name: "JOYSTICK_BUTTON_10", Code: 0x20009},
	{Name: "JOYSTICK_BUTTON_11", Code: 0x2000a},
	{Name: "JOYSTICK_BUTTON_12", Code: 0x2000b},
	{Name: "JOYSTICK_BUTTON_13", Code: 0x2000c},
	{Name: "JOYSTICK_BUTTON_14", Code: 0x2000d},
	{Name: "JOYSTICK_BUTTON_15", Code: 0x2000e},
	{Name: "JOYSTICK_BUTTON_16", Code: 0x2000f},
	{Name: "JOYSTICK_BUTTON_17", Code: 0x20010},
	{Name: "JOYSTICK_BUTTON_18", Code: 0x20011},
	{Name: "JOYSTICK_BUTTON_19", Code: 0x20012},
	{Name: "JOYSTICK_BUTTON_20", Code: 0x20013},
	{Name: "JOYSTICK_BUTTON_21", Code: 0x20014},
	{Name: "JOYSTICK_BUTTON_22", Code: 0x20015},
	{Name: "JOYSTICK_BUTTON_23", Code: 0x20016},
	{Name: "JOYSTICK_BUTTON_24", Code: 0x20017},
	{Name: "JOYSTICK_BUTTON_25", Code: 0x20018},
	{Name: "JOYSTICK_BUTTON_26", Code: 0x20019},
	{Name: "JOYSTICK_BUTTON_27", Code: 0x2001a},
	{Name: "JOYSTICK_BUTTON_28", Code: 0x2001b},
	{Name: "JOYSTICK_BUTTON_29", Code: 0x2001c},
	{Name: "JOYSTICK_BUTTON_30", Code: 0x2001d},
	{Name: "JOYSTICK_BUTTON_31", Code: 0x2001e},
	{Name: "JOYSTICK_BUTTON_32", Code: 0x2001f},
}
