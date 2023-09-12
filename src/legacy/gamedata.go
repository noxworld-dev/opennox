package legacy

/*
int nox_xxx_loadMonsterBin_517010();
*/
import "C"

//export nox_xxx_gamedataGetFloat_419D40
func nox_xxx_gamedataGetFloat_419D40(k *C.char) C.double {
	key := GoString(k)
	val := C.double(GetServer().S().Balance.Float(key))
	return val
}

//export nox_xxx_gamedataGetFloatTable_419D70
func nox_xxx_gamedataGetFloatTable_419D70(k *C.char, i int) C.double {
	key := GoString(k)
	val := C.double(GetServer().S().Balance.FloatInd(key, i))
	return val
}

func Nox_xxx_loadMonsterBin_517010() int {
	return int(C.nox_xxx_loadMonsterBin_517010())
}
