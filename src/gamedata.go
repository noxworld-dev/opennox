package opennox

import "C"
import (
	"github.com/noxworld-dev/opennox-lib/balance"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

var (
	gamedata struct {
		file *balance.File
	}
	gamedataLog = log.New("gamedata")
)

func nox_xxx_gamedataFree_419DB0() {
	gamedata.file = nil
}

//export nox_xxx_parseGamedataBin_419B30
func nox_xxx_parseGamedataBin_419B30() C.int {
	gamedata.file = nil
	var err error
	gamedata.file, err = balance.ReadBalance(datapath.Data(balance.GamedataFile))
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

func gamedataTag() balance.Tag {
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
