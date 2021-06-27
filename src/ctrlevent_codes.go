package main

const (
	CC_Null          = 0
	CC_Orientation   = 1
	CC_MoveForward   = 2
	CC_MoveBackward  = 3
	CC_MoveLeft      = 4
	CC_MoveRight     = 5
	CC_Action        = 6
	CC_Jump          = 7
	CC_Chat          = 8
	CC_TeamChat      = 9
	CC_ReadSpellbook = 10
	CC_ToggleConsole = 11
	// TODO: somewhere around here the indexes are off by +2 (e.g. CC_QuitMenu = 17)
	CC_IncreaseWindowSize     = 12
	CC_DecreaseWindowSize     = 13
	CC_Quit                   = 14
	CC_QuitMenu               = 15
	CC_ReadMap                = 16
	CC_Inventory              = 17
	CC_SpellGestureUp         = 18
	CC_SpellGestureDown       = 19
	CC_SpellGestureLeft       = 20
	CC_SpellGestureRight      = 21
	CC_SpellGestureUpperRight = 22
	CC_SpellGestureUpperLeft  = 23
	CC_SpellGestureLowerRight = 24
	CC_SpellGestureLowerLeft  = 25
	CC_SpellPatternEnd        = 26
	CC_CastQueuedSpell        = 27
	CC_CastMostRecentSpell    = 28
	CC_CastSpell1             = 29
	CC_CastSpell2             = 30
	CC_CastSpell3             = 31
	CC_CastSpell4             = 32
	CC_CastSpell5             = 33
	CC_MapZoomIn              = 34
	CC_MapZoomOut             = 35
	CC_NextWeapon             = 36
	CC_QuickHealthPotion      = 37
	CC_QuickManaPotion        = 38
	CC_QuickCurePoisonPotion  = 39
	CC_NextSpellSet           = 40
	CC_PreviousSpellSet       = 41
	CC_SelectSpellSet         = 42
	CC_BuildTrap              = 43
	CC_ServerOptions          = 44
	CC_Taunt                  = 45
	CC_Laugh                  = 46
	CC_Point                  = 47
	CC_InvertSpellTarget      = 48
	CC_ToggleRank             = 49
	CC_ToggleNetstat          = 50
	CC_ToggleGUI              = 51
	CC_AutoSave               = 52
	CC_AutoLoad               = 53
	CC_ScreenShot             = 54
	CC_Unknown55              = 55
	CC_Unknown56              = 56
)

func nox_xxx_keyCanPauseMode_42D4B0(code byte) bool {
	switch code {
	default:
		return false
	case CC_Action:
	case CC_Jump:
	case CC_Chat:
	case CC_TeamChat:
	case CC_ReadSpellbook:
	case CC_ToggleConsole:
	case CC_IncreaseWindowSize:
	case CC_DecreaseWindowSize:
	case CC_Quit:
	case CC_QuitMenu:
	case CC_ReadMap:
	case CC_Inventory:
	case CC_SpellGestureUp:
	case CC_SpellGestureDown:
	case CC_SpellGestureLeft:
	case CC_SpellGestureRight:
	case CC_SpellGestureUpperRight:
	case CC_SpellGestureUpperLeft:
	case CC_SpellGestureLowerRight:
	case CC_SpellGestureLowerLeft:
	case CC_SpellPatternEnd:
	case CC_CastQueuedSpell:
	case CC_CastMostRecentSpell:
	case CC_CastSpell1:
	case CC_CastSpell2:
	case CC_CastSpell3:
	case CC_CastSpell4:
	case CC_CastSpell5:
	case CC_MapZoomIn:
	case CC_MapZoomOut:
	case CC_QuickManaPotion:
	case CC_QuickCurePoisonPotion:
	case CC_NextSpellSet:
	case CC_PreviousSpellSet:
	case CC_SelectSpellSet:
	case CC_BuildTrap:
	case CC_ServerOptions:
	case CC_Taunt:
	case CC_Laugh:
	case CC_Point:
	case CC_InvertSpellTarget:
	case CC_ToggleRank:
	case CC_ToggleGUI:
	case CC_AutoSave:
	case CC_AutoLoad:
	case CC_ScreenShot:
	case CC_Unknown55:
	case CC_Unknown56:
	}
	return true
}

func nox_xxx_keyCheckWarrorKeys_42D460(code byte) bool {
	switch code {
	default:
		return false
	case CC_SpellGestureLeft:
	case CC_SpellGestureRight:
	case CC_SpellGestureUpperRight:
	case CC_SpellGestureUpperLeft:
	case CC_SpellGestureLowerRight:
	case CC_SpellGestureLowerLeft:
	case CC_SpellPatternEnd:
	case CC_CastQueuedSpell:
	case CC_CastMostRecentSpell:
	case CC_CastSpell1:
	case CC_CastSpell2:
	case CC_SelectSpellSet:
	case CC_BuildTrap:
	case CC_ServerOptions:
	case CC_Taunt:
	}
	return true
}

func nox_ctrlevent_has_data_42D440(code byte) bool {
	return nox_ctrlevent_code_infos[code].hasData
}

func nox_ctrlevent_data_size_42D450(code byte) int {
	return nox_ctrlevent_code_infos[code].dataSize
}

func (ce *noxCtrlEvent) HasData() bool {
	return nox_ctrlevent_code_infos[ce.code].hasData
}

func (ce *noxCtrlEvent) DataSize() int {
	return nox_ctrlevent_code_infos[ce.code].dataSize
}

var nox_ctrlevent_code_infos = []struct {
	name     string
	hasData  bool
	dataSize int
}{
	{"CC_Null", false, 0},
	{"CC_Orientation", true, 0x1},
	{"CC_MoveForward", true, 0x1},
	{"CC_MoveBackward", true, 0x1},
	{"CC_MoveLeft", true, 0x1},
	{"CC_MoveRight", true, 0x1},
	{"CC_Action", false, 0},
	{"CC_Jump", false, 0},
	{"CC_Chat", false, 0},
	{"CC_TeamChat", false, 0},
	{"CC_ReadSpellbook", false, 0},
	{"CC_ToggleConsole", false, 0},
	// TODO: somewhere around here the names for indexes are off by +2 (e.g. CC_QuitMenu = 17)
	{"CC_IncreaseWindowSize", false, 0},
	{"CC_DecreaseWindowSize", false, 0},
	{"CC_Quit", false, 0},
	{"CC_QuitMenu", false, 0},
	{"CC_ReadMap", false, 0},
	{"CC_Inventory", false, 0},
	{"CC_SpellGestureUp", false, 0},
	{"CC_SpellGestureDown", false, 0},
	{"CC_SpellGestureLeft", false, 0},
	{"CC_SpellGestureRight", false, 0},
	{"CC_SpellGestureUpperRight", false, 0},
	{"CC_SpellGestureUpperLeft", false, 0},
	{"CC_SpellGestureLowerRight", false, 0},
	{"CC_SpellGestureLowerLeft", false, 0},
	{"CC_SpellPatternEnd", true, 0x1},
	{"CC_CastQueuedSpell", true, 0x4},
	{"CC_CastMostRecentSpell", true, 0x4},
	{"CC_CastSpell1", false, 0},
	{"CC_CastSpell2", false, 0},
	{"CC_CastSpell3", false, 0},
	{"CC_CastSpell4", false, 0},
	{"CC_CastSpell5", false, 0},
	{"CC_MapZoomIn", false, 0},
	{"CC_MapZoomOut", false, 0},
	{"CC_NextWeapon", false, 0},
	{"CC_QuickHealthPotion", false, 0},
	{"CC_QuickManaPotion", false, 0},
	{"CC_QuickCurePoisonPotion", false, 0},
	{"CC_NextSpellSet", false, 0},
	{"CC_PreviousSpellSet", false, 0},
	{"CC_SelectSpellSet", false, 0},
	{"CC_BuildTrap", false, 0},
	{"CC_ServerOptions", false, 0},
	{"CC_Taunt", false, 0},
	{"CC_Laugh", false, 0},
	{"CC_Point", false, 0},
	{"CC_InvertSpellTarget", false, 0},
	{"CC_ToggleRank", false, 0},
	{"CC_ToggleNetstat", false, 0},
	{"CC_ToggleGUI", false, 0},
	{"CC_AutoSave", false, 0},
	{"CC_AutoLoad", false, 0},
	{"CC_ScreenShot", false, 0},
	{"CC_Unknown55", false, 0},
	{"CC_Unknown56", false, 0},
}
