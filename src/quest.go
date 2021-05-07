package main

/*
#include "proto.h"
int  sub_51A920(int a1);
void sub_4D10F0(char* a1);
void sub_4F1F20();
void sub_51A1F0(int a1);
*/
import "C"
import (
	"log"
	"os"
	"strconv"
	"unsafe"
)

const (
	questLevelWrapIncDef    = 5
	questLevelWrapCutoffDef = 20
)

var (
	questLevelInc          = 1
	questLevelWarpInc      = questLevelWrapIncDef
	questLevelWarpInfinite = os.Getenv("NOX_QUEST_WARP_INF") == "true"
	questLog               = log.New(os.Stderr, "[quest]: ", log.LstdFlags|log.Lmsgprefix)
)

func init() {
	if str := os.Getenv("NOX_QUEST_LVL_INC"); str != "" {
		v, err := strconv.ParseUint(str, 10, 32)
		if err != nil {
			questLog.Printf("cannot parse level increment: %v", err)
		} else {
			questLog.Printf("setting level increment to %d", v)
			questLevelInc = int(v)
		}
	}
	if str := os.Getenv("NOX_QUEST_WARP_INC"); str != "" {
		v, err := strconv.ParseUint(str, 10, 32)
		if err != nil {
			questLog.Printf("cannot parse warp increment: %v", err)
		} else {
			questLog.Printf("setting warp increment to %d", v)
			questLevelWarpInc = int(v)
		}
	}
}

func nox_game_getQuestStage_4E3CC0() int {
	return int(C.nox_game_getQuestStage_4E3CC0())
}

func nox_xxx_getQuestStage_51A930() int {
	return int(C.nox_xxx_getQuestStage_51A930())
}

func nox_game_setQuestStage_4E3CD0(lvl int) {
	C.nox_game_setQuestStage_4E3CD0(C.int(lvl))
}

func questNextStageThreshold(lvl int) int {
	if !questLevelWarpInfinite && lvl >= questLevelWrapCutoffDef {
		return lvl
	}
	next := (lvl / questLevelWarpInc) + 1
	return next * questLevelWarpInc
}

//export nox_server_questNextStageThreshold_4D74F0
func nox_server_questNextStageThreshold_4D74F0(lvl C.int) C.int {
	return C.int(questNextStageThreshold(int(lvl)))
}

//export nox_server_questMapNextLevel
func nox_server_questMapNextLevel() {
	// server loading next quest level
	C.sub_51A920(C.int(nox_common_randomInt_415FA0(0, 2)))
	lvl := nox_game_getQuestStage_4E3CC0()
	lvl += questLevelInc
	questLog.Printf("switching level to %d", lvl)
	nox_game_setQuestStage_4E3CD0(lvl)
	lvl = nox_xxx_getQuestStage_51A930()
	C.sub_51A1F0(C.int(lvl))
	C.sub_4E3D50()
	C.sub_4E3DD0()
	C.sub_4F1F20()
	name := nox_server_currentMapGetFilename_409B30()
	questLog.Printf("loading map: %q", name)
	C.sub_4D10F0(internCStr(name))
	C.sub_4D7520(1)
	if !questLevelWarpInfinite {
		cutoff := uint(C.nox_xxx_gamedataGetFloat_419D40(unsafe.Pointer(internCStr("WarpGateCutoffStage"))))
		if uint(nox_game_getQuestStage_4E3CC0()) >= cutoff {
			C.sub_4D7520(0)
		}
	}
}
