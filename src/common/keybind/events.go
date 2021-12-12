package keybind

const (
	EventAction             = Event(0x1)
	EventMoveForward        = Event(0x2)
	EventMoveBackward       = Event(0x3)
	EventMoveLeft           = Event(0x4)
	EventMoveRight          = Event(0x5)
	EventJump               = Event(0x6)
	EventToggleInventory    = Event(0x7)
	EventChat               = Event(0x8)
	EventTeamChat           = Event(0x9)
	EventToggleBook         = Event(0xa)
	EventToggleConsole      = Event(0xb)
	EventIncreaseWindowSize = Event(0xc)
	EventDecreaseWindowSize = Event(0xd)
	EventIncreaseGamma      = Event(0xe)
	EventDecreaseGamma      = Event(0xf)
	EventToggleMap          = Event(0x10)
	EventCastQueued         = Event(0x11)
	EventPhonemeUN          = Event(0x12) // up
	EventPhonemeZO          = Event(0x13) // down
	EventPhonemeET          = Event(0x14) // left
	EventPhonemeCHA         = Event(0x15) // right
	EventPhonemeIN          = Event(0x16) // upper-right
	EventPhonemeKA          = Event(0x17) // upper-left
	EventPhonemeDO          = Event(0x18) // lower-right
	EventPhonemeRO          = Event(0x19) // lower-left
	EventSpellEnd           = Event(0x1a)
	EventCastRecent         = Event(0x1b)
	EventInvokeSlot1        = Event(0x1c)
	EventInvokeSlot2        = Event(0x1d)
	EventInvokeSlot3        = Event(0x1e)
	EventInvokeSlot4        = Event(0x1f)
	EventInvokeSlot5        = Event(0x20)
	EventMapZoomIn          = Event(0x21)
	EventMapZoomOut         = Event(0x22)
	EventSwapWeapons        = Event(0x23)
	EventQuickHealth        = Event(0x24)
	EventQuickMana          = Event(0x25)
	EventQuickCurePoison    = Event(0x26)
	EventNextSpellSet       = Event(0x27)
	EventPreviousSpellSet   = Event(0x28)
	EventSelectSpellSet     = Event(0x29)
	EventPlaceTrapBomber    = Event(0x2a)
	EventQuit               = Event(0x2b)
	EventToggleQuitMenu     = Event(0x2c)
	EventToggleServerMenu   = Event(0x2d)
	EventTaunt              = Event(0x2e)
	EventLaugh              = Event(0x2f)
	EventPoint              = Event(0x30)
	EventInvertSpellTarget  = Event(0x31)
	EventToggleRank         = Event(0x32)
	EventToggleNetstat      = Event(0x33)
	EventToggleGUI          = Event(0x34)
	EventAutoSave           = Event(0x35)
	EventAutoLoad           = Event(0x36)
	EventScreenShot         = Event(0x37)
)

// Extensions to the key bindings.
const (
	EventSpellSet1 = Event(0x50 + iota)
	EventSpellSet2
	EventSpellSet3
	EventSpellSet4
	EventSpellSet5
	EventTrapDrop
	EventTrapBomber1
	EventTrapBomber2
	EventTrapBomber3
	EventCreaturesBanish
	EventCreaturesGuard
	EventCreaturesEscort
	EventCreaturesHunt
	EventAcceptItemsBatch
)

var defBindEvents = []BindEvent{
	{Name: "", Event: 0}, // represents no binding
	{Name: "MoveForward", Event: EventMoveForward},
	{Name: "Action", Event: EventAction},
	{Name: "Jump", Event: EventJump},
	{Name: "ToggleInventory", Event: EventToggleInventory},
	{Name: "ToggleBook", Event: EventToggleBook},
	{Name: "ToggleMap", Event: EventToggleMap},
	{Name: "MapZoomOut", Event: EventMapZoomOut},
	{Name: "MapZoomIn", Event: EventMapZoomIn},

	{Name: "InvokeSlot1", Event: EventInvokeSlot1},
	{Name: "InvokeSlot2", Event: EventInvokeSlot2},
	{Name: "InvokeSlot3", Event: EventInvokeSlot3},
	{Name: "InvokeSlot4", Event: EventInvokeSlot4},
	{Name: "InvokeSlot5", Event: EventInvokeSlot5},
	{Name: "PreviousSpellSet", Event: EventPreviousSpellSet},
	{Name: "NextSpellSet", Event: EventNextSpellSet},
	{Name: "SelectSpellSet", Event: EventSelectSpellSet},
	{Name: "SpellSet1", Event: EventSpellSet1, Title: "Spell Set 1"},
	{Name: "SpellSet2", Event: EventSpellSet2, Title: "Spell Set 2"},
	{Name: "SpellSet3", Event: EventSpellSet3, Title: "Spell Set 3"},
	{Name: "SpellSet4", Event: EventSpellSet4, Title: "Spell Set 4"},
	{Name: "SpellSet5", Event: EventSpellSet5, Title: "Spell Set 5"},
	{Name: "InvertSpellTarget", Event: EventInvertSpellTarget},

	{Name: "PlaceTrapBomber", Event: EventPlaceTrapBomber},
	{Name: "TrapBomber1", Event: EventTrapBomber1, Title: "Trap/Bomber 1"},
	{Name: "TrapBomber2", Event: EventTrapBomber2, Title: "Trap/Bomber 2"},
	{Name: "TrapBomber3", Event: EventTrapBomber3, Title: "Trap/Bomber 3"},
	{Name: "DropTrap", Event: EventTrapDrop, Title: "Drop Trap"},

	{Name: "SwapWeapons", Event: EventSwapWeapons},
	{Name: "QuickHealth", Event: EventQuickHealth},
	{Name: "QuickMana", Event: EventQuickMana},
	{Name: "QuickCurePoison", Event: EventQuickCurePoison},
	{Name: "Chat", Event: EventChat},
	{Name: "TeamChat", Event: EventTeamChat},
	{Name: "ToggleConsole", Event: EventToggleConsole},
	{Name: "ToggleQuitMenu", Event: EventToggleQuitMenu},
	{Name: "ToggleServerMenu", Event: EventToggleServerMenu},
	{Name: "ToggleRank", Event: EventToggleRank},
	{Name: "ToggleNetstat", Event: EventToggleNetstat},
	{Name: "ToggleGUI", Event: EventToggleGUI},
	{Name: "AutoSave", Event: EventAutoSave},
	{Name: "AutoLoad", Event: EventAutoLoad},
	{Name: "Taunt", Event: EventTaunt},
	{Name: "Point", Event: EventPoint},
	{Name: "Laugh", Event: EventLaugh},
	{Name: "IncreaseWindowSize", Event: EventIncreaseWindowSize},
	{Name: "DecreaseWindowSize", Event: EventDecreaseWindowSize},
	{Name: "IncreaseGamma", Event: EventIncreaseGamma},
	{Name: "DecreaseGamma", Event: EventDecreaseGamma},
	{Name: "ScreenShot", Event: EventScreenShot},
	// restored phoneme bindings
	{Name: "CastQueued", Event: EventCastQueued, Title: "Cast queued spell"},
	{Name: "PhonemeUN", Event: EventPhonemeUN, Title: "Phoneme UN (N)"},    // up
	{Name: "PhonemeZO", Event: EventPhonemeZO, Title: "Phoneme ZO (S)"},    // down
	{Name: "PhonemeET", Event: EventPhonemeET, Title: "Phoneme ET (W)"},    // left
	{Name: "PhonemeCHA", Event: EventPhonemeCHA, Title: "Phoneme CHA (E)"}, // right
	{Name: "PhonemeIN", Event: EventPhonemeIN, Title: "Phoneme IN (NE)"},   // upper-right
	{Name: "PhonemeKA", Event: EventPhonemeKA, Title: "Phoneme KA (NW)"},   // upper-left
	{Name: "PhonemeDO", Event: EventPhonemeDO, Title: "Phoneme DO (SE)"},   // lower-right
	{Name: "PhonemeRO", Event: EventPhonemeRO, Title: "Phoneme RO (SW)"},   // lower-left
	{Name: "SpellEnd", Event: EventSpellEnd, Title: "Spell end"},
	{Name: "CastRecent", Event: EventCastRecent, Title: "Cast recent spell"},
	// creature control
	{Name: "CreaturesBanish", Event: EventCreaturesBanish, Title: "Creatures command: Banish"},
	{Name: "CreaturesGuard", Event: EventCreaturesGuard, Title: "Creatures command: Guard"},
	{Name: "CreaturesEscort", Event: EventCreaturesEscort, Title: "Creatures command: Escort"},
	{Name: "CreaturesHunt", Event: EventCreaturesHunt, Title: "Creatures command: Hunt"},
	// other
	{Name: "AcceptItemsBatch", Event: EventAcceptItemsBatch, Title: "Accept Trade / Drop"},
}
