package noxflags

var (
	game       GameFlag
	gameChange []func(f GameFlag)
	gameSet    []func(f GameFlag)
	gameUnset  []func(f GameFlag)
)

const (
	GameServer      = GameFlag(0x1)
	GameFlag2       = GameFlag(0x2)
	GameFlag3       = GameFlag(0x4)
	GameFlag4       = GameFlag(0x8)
	GameFlag5       = GameFlag(0x10)
	GameFlag6       = GameFlag(0x20)
	GameFlag7       = GameFlag(0x40)
	GameFlag8       = GameFlag(0x80)
	GameFlag9       = GameFlag(0x100)
	GameFlag10      = GameFlag(0x200)
	GameFlag11      = GameFlag(0x400)
	GameSolo        = GameFlag(0x800)
	GameFlag13      = GameFlag(0x1000)
	GameFlag14      = GameFlag(0x2000)
	GameFlag15      = GameFlag(0x4000)
	GameFlag16      = GameFlag(0x8000)
	GameFlag17      = GameFlag(0x10000)
	GameFlag18      = GameFlag(0x20000)
	GameFlag19      = GameFlag(0x40000)
	GameFlag20      = GameFlag(0x80000)
	GameFlag21      = GameFlag(0x100000)
	GameFlag22      = GameFlag(0x200000)
	GameFlag23      = GameFlag(0x400000)
	GameFlag24      = GameFlag(0x800000)
	GameFlag25      = GameFlag(0x1000000)
	GameFlag26      = GameFlag(0x2000000)
	GameSuddenDeath = GameFlag(0x4000000)
	GameFlag28      = GameFlag(0x8000000)
	GameFlag29      = GameFlag(0x10000000)
	GameFlag30      = GameFlag(0x20000000)
	GameFlag31      = GameFlag(0x40000000)
	GameFlag32      = GameFlag(0x80000000)
)

const (
	GameServerSettings = GameFlag(0x7FFF0)
)

// GameFlag is a type for Nox game flags.
type GameFlag uint

// Has checks if one of the flags is set.
func (f GameFlag) Has(f2 GameFlag) bool {
	return f&f2 != 0
}

// HasAll checks if all of the flags are set.
func (f GameFlag) HasAll(f2 GameFlag) bool {
	return f&f2 == f2
}

// GetGame returns all game flags.
func GetGame() GameFlag {
	return game
}

// ResetGame resets all game flags.
func ResetGame() {
	game = 0
}

// HasGame check if one of the game flags is set.
func HasGame(f GameFlag) bool {
	return game.Has(f)
}

// SetGame sets one or more game flags.
func SetGame(f GameFlag) {
	if game&f == f {
		return // already set
	}
	game |= f
	for _, fnc := range gameChange {
		fnc(f)
	}
	for _, fnc := range gameSet {
		fnc(f)
	}
}

// UnsetGame resets one or more game flags.
func UnsetGame(f GameFlag) {
	if game&f == 0 {
		return // already unset
	}
	game &= ^f
	for _, fnc := range gameChange {
		fnc(f)
	}
	for _, fnc := range gameUnset {
		fnc(f)
	}
}

// OnGameChange registers a hook that triggers when game flags change.
func OnGameChange(fnc func(f GameFlag)) {
	gameChange = append(gameChange, fnc)
}

// OnGameSet registers a hook that triggers when a game flag is set.
func OnGameSet(fnc func(f GameFlag)) {
	gameSet = append(gameSet, fnc)
}

// OnGameUnset registers a hook that triggers when a game flag is unset.
func OnGameUnset(fnc func(f GameFlag)) {
	gameUnset = append(gameUnset, fnc)
}
