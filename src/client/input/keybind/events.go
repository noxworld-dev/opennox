package keybind

var defBindEvents = []BindEvent{
	{Name: "", Event: 0}, // represents no binding
	{Name: "MoveForward", Event: 0x2},
	{Name: "Action", Event: 0x1},
	{Name: "Jump", Event: 0x6},
	{Name: "ToggleInventory", Event: 0x7},
	{Name: "ToggleBook", Event: 0xa},
	{Name: "ToggleMap", Event: 0x10},
	{Name: "MapZoomOut", Event: 0x22},
	{Name: "MapZoomIn", Event: 0x21},
	{Name: "InvokeSlot1", Event: 0x1c},
	{Name: "InvokeSlot2", Event: 0x1d},
	{Name: "InvokeSlot3", Event: 0x1e},
	{Name: "InvokeSlot4", Event: 0x1f},
	{Name: "InvokeSlot5", Event: 0x20},
	{Name: "PreviousSpellSet", Event: 0x28},
	{Name: "NextSpellSet", Event: 0x27},
	{Name: "SelectSpellSet", Event: 0x29},
	{Name: "InvertSpellTarget", Event: 0x31},
	{Name: "PlaceTrapBomber", Event: 0x2a},
	{Name: "SwapWeapons", Event: 0x23},
	{Name: "QuickHealth", Event: 0x24},
	{Name: "QuickMana", Event: 0x25},
	{Name: "QuickCurePoison", Event: 0x26},
	{Name: "Chat", Event: 0x8},
	{Name: "TeamChat", Event: 0x9},
	{Name: "ToggleConsole", Event: 0xb},
	{Name: "ToggleQuitMenu", Event: 0x2c},
	{Name: "ToggleServerMenu", Event: 0x2d},
	{Name: "ToggleRank", Event: 0x32},
	{Name: "ToggleNetstat", Event: 0x33},
	{Name: "ToggleGUI", Event: 0x34},
	{Name: "AutoSave", Event: 0x35},
	{Name: "AutoLoad", Event: 0x36},
	{Name: "Taunt", Event: 0x2e},
	{Name: "Point", Event: 0x30},
	{Name: "Laugh", Event: 0x2f},
	{Name: "IncreaseWindowSize", Event: 0xc},
	{Name: "DecreaseWindowSize", Event: 0xd},
	{Name: "IncreaseGamma", Event: 0xe},
	{Name: "DecreaseGamma", Event: 0xf},
	{Name: "ScreenShot", Event: 0x37},
	// restored phoneme bindings
	{Name: "CastQueued", Event: 0x11, Title: "Cast queued spell"},
	{Name: "PhonemeUN", Event: 0x12, Title: "Phoneme UN (N)"},   // up
	{Name: "PhonemeZO", Event: 0x13, Title: "Phoneme ZO (S)"},   // down
	{Name: "PhonemeET", Event: 0x14, Title: "Phoneme ET (W)"},   // left
	{Name: "PhonemeCHA", Event: 0x15, Title: "Phoneme CHA (E)"}, // right
	{Name: "PhonemeIN", Event: 0x16, Title: "Phoneme IN (NE)"},  // upper-right
	{Name: "PhonemeKA", Event: 0x17, Title: "Phoneme KA (NW)"},  // upper-left
	{Name: "PhonemeDO", Event: 0x18, Title: "Phoneme DO (SE)"},  // lower-right
	{Name: "PhonemeRO", Event: 0x19, Title: "Phoneme RO (SW)"},  // lower-left
	{Name: "SpellEnd", Event: 0x1a, Title: "Spell end"},
	{Name: "CastRecent", Event: 0x1b, Title: "Cast recent spell"},
}
