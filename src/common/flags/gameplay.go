package noxflags

var (
	gameplay GameplayFlag
)

const (
	GameplayFlag1 = GameplayFlag(0x1)
	GameplayFlag2 = GameplayFlag(0x2)
	GameplayFlag4 = GameplayFlag(0x4)
)

type GameplayFlag uint

func GetGamePlay() GameplayFlag {
	return gameplay
}

func HasGamePlay(v GameplayFlag) bool {
	return gameplay&v != 0
}

func SetGamePlay(v GameplayFlag) {
	gameplay |= v
}

func UnsetGamePlay(v GameplayFlag) {
	gameplay &^= v
}
