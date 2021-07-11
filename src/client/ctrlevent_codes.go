package client

import "fmt"

const (
	CCOrientation            = CtrlCode(1)
	CCMoveForward            = CtrlCode(2)
	CCMoveBackward           = CtrlCode(3)
	CCMoveLeft               = CtrlCode(4)
	CCMoveRight              = CtrlCode(5)
	CCAction                 = CtrlCode(6)
	CCJump                   = CtrlCode(7)
	CCChat                   = CtrlCode(8)
	CCTeamChat               = CtrlCode(9)
	CCReadSpellbook          = CtrlCode(10)
	CCToggleConsole          = CtrlCode(11)
	CCIncreaseWindowSize     = CtrlCode(12)
	CCDecreaseWindowSize     = CtrlCode(13)
	CCIncreaseGamma          = CtrlCode(14)
	CCDecreaseGamma          = CtrlCode(15)
	CCQuit                   = CtrlCode(16)
	CCQuitMenu               = CtrlCode(17)
	CCReadMap                = CtrlCode(18)
	CCInventory              = CtrlCode(19)
	CCSpellGestureUp         = CtrlCode(20)
	CCSpellGestureDown       = CtrlCode(21)
	CCSpellGestureLeft       = CtrlCode(22)
	CCSpellGestureRight      = CtrlCode(23)
	CCSpellGestureUpperRight = CtrlCode(24)
	CCSpellGestureUpperLeft  = CtrlCode(25)
	CCSpellGestureLowerRight = CtrlCode(26)
	CCSpellGestureLowerLeft  = CtrlCode(27)
	CCSpellPatternEnd        = CtrlCode(28)
	CCCastQueuedSpell        = CtrlCode(29)
	CCCastMostRecentSpell    = CtrlCode(30)
	CCCastSpell1             = CtrlCode(31)
	CCCastSpell2             = CtrlCode(32)
	CCCastSpell3             = CtrlCode(33)
	CCCastSpell4             = CtrlCode(34)
	CCCastSpell5             = CtrlCode(35)
	CCMapZoomIn              = CtrlCode(36)
	CCMapZoomOut             = CtrlCode(37)
	CCNextWeapon             = CtrlCode(38)
	CCQuickHealthPotion      = CtrlCode(39)
	CCQuickManaPotion        = CtrlCode(40)
	CCQuickCurePoisonPotion  = CtrlCode(41)
	CCNextSpellSet           = CtrlCode(42)
	CCPreviousSpellSet       = CtrlCode(43)
	CCSelectSpellSet         = CtrlCode(44)
	CCBuildTrap              = CtrlCode(45)
	CCServerOptions          = CtrlCode(46)
	CCTaunt                  = CtrlCode(47)
	CCLaugh                  = CtrlCode(48)
	CCPoint                  = CtrlCode(49)
	CCInvertSpellTarget      = CtrlCode(50)
	CCToggleRank             = CtrlCode(51)
	CCToggleNetstat          = CtrlCode(52)
	CCToggleGUI              = CtrlCode(53)
	CCAutoSave               = CtrlCode(54)
	CCAutoLoad               = CtrlCode(55)
	CCScreenShot             = CtrlCode(56)
)

type CtrlCode byte

func (code CtrlCode) String() string {
	if name := ctrlCodes[code].Name; name != "" {
		return name
	}
	return fmt.Sprintf("CtrlCode(%d)", int(code))
}

func (code CtrlCode) DataSize() int {
	return ctrlCodes[code].Size
}

func (code CtrlCode) CanPauseMode() bool {
	return !ctrlCodes[code].NoPause
}

func (code CtrlCode) IsMagicRelated() bool {
	return ctrlCodes[code].Magic
}

var ctrlCodes = map[CtrlCode]struct {
	Name    string
	Size    int
	Magic   bool
	NoPause bool
}{
	0:                        {Name: "Null", NoPause: true},
	CCOrientation:            {Name: "Orientation", Size: 1, NoPause: true},
	CCMoveForward:            {Name: "MoveForward", Size: 1, NoPause: true},
	CCMoveBackward:           {Name: "MoveBackward", Size: 1, NoPause: true},
	CCMoveLeft:               {Name: "MoveLeft", Size: 1, NoPause: true},
	CCMoveRight:              {Name: "MoveRight", Size: 1, NoPause: true},
	CCAction:                 {Name: "Action"},
	CCJump:                   {Name: "Jump"},
	CCChat:                   {Name: "Chat"},
	CCTeamChat:               {Name: "TeamChat"},
	CCReadSpellbook:          {Name: "ReadSpellbook"},
	CCToggleConsole:          {Name: "ToggleConsole"},
	CCIncreaseWindowSize:     {Name: "IncreaseWindowSize"},
	CCDecreaseWindowSize:     {Name: "DecreaseWindowSize"},
	CCIncreaseGamma:          {Name: "IncreaseGamma"},
	CCDecreaseGamma:          {Name: "DecreaseGamma"},
	CCQuit:                   {Name: "Quit"},
	CCQuitMenu:               {Name: "QuitMenu"},
	CCReadMap:                {Name: "ReadMap"},
	CCInventory:              {Name: "Inventory"},
	CCSpellGestureUp:         {Name: "SpellGestureUp", Magic: true},
	CCSpellGestureDown:       {Name: "SpellGestureDown", Magic: true},
	CCSpellGestureLeft:       {Name: "SpellGestureLeft", Magic: true},
	CCSpellGestureRight:      {Name: "SpellGestureRight", Magic: true},
	CCSpellGestureUpperRight: {Name: "SpellGestureUpperRight", Magic: true},
	CCSpellGestureUpperLeft:  {Name: "SpellGestureUpperLeft", Magic: true},
	CCSpellGestureLowerRight: {Name: "SpellGestureLowerRight", Magic: true},
	CCSpellGestureLowerLeft:  {Name: "SpellGestureLowerLeft", Magic: true},
	CCSpellPatternEnd:        {Name: "SpellPatternEnd", Size: 1, Magic: true},
	CCCastQueuedSpell:        {Name: "CastQueuedSpell", Size: 4, Magic: true},
	CCCastMostRecentSpell:    {Name: "CastMostRecentSpell", Size: 4, Magic: true},
	CCCastSpell1:             {Name: "CastSpell1"},
	CCCastSpell2:             {Name: "CastSpell2"},
	CCCastSpell3:             {Name: "CastSpell3"},
	CCCastSpell4:             {Name: "CastSpell4"},
	CCCastSpell5:             {Name: "CastSpell5"},
	CCMapZoomIn:              {Name: "MapZoomIn", NoPause: true},
	CCMapZoomOut:             {Name: "MapZoomOut", NoPause: true},
	CCNextWeapon:             {Name: "NextWeapon"},
	CCQuickHealthPotion:      {Name: "QuickHealthPotion"},
	CCQuickManaPotion:        {Name: "QuickManaPotion"},
	CCQuickCurePoisonPotion:  {Name: "QuickCurePoisonPotion"},
	CCNextSpellSet:           {Name: "NextSpellSet", Magic: true},
	CCPreviousSpellSet:       {Name: "PreviousSpellSet", Magic: true},
	CCSelectSpellSet:         {Name: "SelectSpellSet", Magic: true},
	CCBuildTrap:              {Name: "BuildTrap", Magic: true},
	CCServerOptions:          {Name: "ServerOptions"},
	CCTaunt:                  {Name: "Taunt"},
	CCLaugh:                  {Name: "Laugh"},
	CCPoint:                  {Name: "Point"},
	CCInvertSpellTarget:      {Name: "InvertSpellTarget", NoPause: true},
	CCToggleRank:             {Name: "ToggleRank"},
	CCToggleNetstat:          {Name: "ToggleNetstat"},
	CCToggleGUI:              {Name: "ToggleGUI"},
	CCAutoSave:               {Name: "AutoSave"},
	CCAutoLoad:               {Name: "AutoLoad"},
	CCScreenShot:             {Name: "ScreenShot"},
}
