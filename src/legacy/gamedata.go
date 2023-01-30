package legacy

/*
int nox_xxx_loadMonsterBin_517010();
*/
import "C"

var (
	GamedataFloat    func(key string) float64
	GamedataFloatInd func(key string, ind int) float64
)

//export nox_xxx_gamedataGetFloat_419D40
func nox_xxx_gamedataGetFloat_419D40(k *C.char) C.double {
	key := GoString(k)
	val := C.double(GamedataFloat(key))
	return val
}

//export nox_xxx_gamedataGetFloatTable_419D70
func nox_xxx_gamedataGetFloatTable_419D70(k *C.char, i int) C.double {
	key := GoString(k)
	val := C.double(GamedataFloatInd(key, i))
	return val
}

func Nox_xxx_loadMonsterBin_517010() int {
	return int(C.nox_xxx_loadMonsterBin_517010())
}
