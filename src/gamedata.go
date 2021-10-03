package nox

import "C"
import (
	"nox/v1/common/balance"
	"nox/v1/common/datapath"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/log"
)

var (
	gamedata struct {
		file *balance.File
	}
	gamedataLog = log.New("gamedata")
)

//export nox_xxx_gamedataFree_419DB0
func nox_xxx_gamedataFree_419DB0() {
	gamedata.file = nil
}

//export nox_xxx_parseGamedataBin_419B30
func nox_xxx_parseGamedataBin_419B30() C.int {
	gamedata.file = nil
	var err error
	gamedata.file, err = balance.ReadBalance(datapath.Path(balance.GamedataFile))
	if err != nil {
		gamedataLog.Println("error parsing gamedata:", err)
		return 0
	}
	return 1
}

//export nox_xxx_gamedataGetFloat_419D40
func nox_xxx_gamedataGetFloat_419D40(k *C.char) C.double {
	key := GoString(k)
	val := C.double(gamedataFloat(key))
	return val
}

//export nox_xxx_gamedataGetFloatTable_419D70
func nox_xxx_gamedataGetFloatTable_419D70(k *C.char, i C.int) C.double {
	key := GoString(k)
	val := C.double(gamedataFloatInd(key, int(i)))
	return val
}

func gamedataTag() string {
	// TODO: check if it's a valid condition
	if noxflags.HasGame(noxflags.GameModeCoop) {
		return balance.TagSolo
	}
	return balance.TagArena
}

func gamedataFloat(key string) float64 {
	tag := gamedataTag()
	return gamedata.file.FloatDef(tag, key, 0)
}

func gamedataFloatInd(key string, i int) float64 {
	if i < 0 {
		return 0
	}
	tag := gamedataTag()
	arr := gamedata.file.Array(tag, key)
	if i >= len(arr) {
		return 0
	}
	return arr[i]
}
