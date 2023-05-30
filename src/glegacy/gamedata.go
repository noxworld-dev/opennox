package legacy

var (
	GamedataFloat    func(key string) float64
	GamedataFloatInd func(key string, ind int) float64
)

// nox_xxx_gamedataGetFloat_419D40
func nox_xxx_gamedataGetFloat_419D40(k *byte) float64 {
	key := GoString(k)
	val := float64(GamedataFloat(key))
	return val
}

// nox_xxx_gamedataGetFloatTable_419D70
func nox_xxx_gamedataGetFloatTable_419D70(k *byte, i int32) float64 {
	key := GoString(k)
	val := float64(GamedataFloatInd(key, int(i)))
	return val
}

func Nox_xxx_loadMonsterBin_517010() int {
	return int(nox_xxx_loadMonsterBin_517010())
}
