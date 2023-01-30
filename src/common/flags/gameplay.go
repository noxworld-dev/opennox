package noxflags

var (
	gameplay uint32
)

func GetGamePlay() uint32 {
	return gameplay
}

func HasGamePlay(v uint32) bool {
	return gameplay&v != 0
}

func SetGamePlay(v uint32) {
	gameplay |= v
}

func UnsetGamePlay(v uint32) {
	gameplay &^= v
}
