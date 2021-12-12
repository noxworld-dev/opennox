package nox

/*
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_1.h"
int  sub_51A920(int a1);
void sub_4D10F0(char* a1);
void sub_4F1F20();
void sub_51A1F0(int a1);
*/
import "C"
import (
	"os"
	"strconv"

	"nox/v1/common/console"
	"nox/v1/common/log"
)

const (
	questLevelWrapIncDef    = 5
	questLevelWrapCutoffDef = 20
)

var (
	questLevelInc          = 1
	questLevelWarpInc      = questLevelWrapIncDef
	questAllowDefault      = os.Getenv("NOX_QUEST_WARP_ALWAYS_ALLOW") == "true"
	questLevelWarpInfinite = os.Getenv("NOX_QUEST_WARP_INF") == "true"
	questLog               = log.New("quest")
	noxCmdSetQuest         = &console.Command{
		Token: "quest",
		Help:  "set Quest-related variables",
		Flags: console.Server | console.Cheat,
		Sub: []*console.Command{
			{
				Token: "level.inc", Flags: console.Server | console.Cheat, Func: cmdSetQuestLevelInc,
				Help: "set level increment for finishing the stage",
			},
			{
				Token: "warp.allow", Flags: console.Server | console.Cheat, Func: cmdSetQuestWarpAllow,
				Help: "allow warp gate even if player has lower level",
			},
			{
				Token: "warp.inc", Flags: console.Server | console.Cheat, Func: cmdSetQuestWarpInc,
				Help: "set level increment for the warp gate",
			},
			{
				Token: "warp.inf", Flags: console.Server | console.Cheat, Func: cmdSetQuestWarpInf,
				Help: "keep the warp gate working indefinitely",
			},
		},
	}
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
	noxCmdSet.Register(noxCmdSetQuest)
}

func cmdSetQuestLevelInc(c *console.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	v, err := strconv.Atoi(tokens[0])
	if err != nil {
		c.Printf(console.ColorRed, "cannot parse value")
		return false
	}
	questLevelInc = v
	c.Printf(console.ColorLightYellow, "Quest completion will skip %d levels", v)
	return true
}

func cmdSetQuestWarpAllow(c *console.Console, tokens []string) bool {
	if len(tokens) > 1 {
		return false
	}
	v := true
	if len(tokens) > 0 {
		b, err := strconv.ParseBool(tokens[0])
		if err != nil {
			c.Printf(console.ColorRed, "cannot parse value")
			return false
		}
		v = b
	}
	questAllowDefault = v
	if v {
		c.Printf(console.ColorLightYellow, "Quest warp gate will work for everyone")
	} else {
		c.Printf(console.ColorLightYellow, "Quest warp gate will only work if you've passed the level already")
	}
	return true
}

func cmdSetQuestWarpInc(c *console.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	v, err := strconv.Atoi(tokens[0])
	if err != nil {
		c.Printf(console.ColorRed, "cannot parse value")
		return false
	}
	questLevelWarpInc = v
	c.Printf(console.ColorLightYellow, "Quest warp gate will skip %d levels", v)
	return true
}

func cmdSetQuestWarpInf(c *console.Console, tokens []string) bool {
	if len(tokens) > 1 {
		return false
	}
	v := true
	if len(tokens) > 0 {
		b, err := strconv.ParseBool(tokens[0])
		if err != nil {
			c.Printf(console.ColorRed, "cannot parse value")
			return false
		}
		v = b
	}
	questLevelWarpInfinite = v
	if v {
		c.Printf(console.ColorLightYellow, "Quest warp gate will work indefinitely")
	} else {
		c.Printf(console.ColorLightYellow, "Quest warp gate will cutoff at some point")
	}
	return true
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

//export nox_server_questAllowDefault
func nox_server_questAllowDefault() C.bool {
	return C.bool(questAllowDefault)
}

//export nox_server_questNextStageThreshold_4D74F0
func nox_server_questNextStageThreshold_4D74F0(lvl C.int) C.int {
	return C.int(questNextStageThreshold(int(lvl)))
}

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
		cutoff := uint(gamedataFloat("WarpGateCutoffStage"))
		if uint(nox_game_getQuestStage_4E3CC0()) >= cutoff {
			C.sub_4D7520(0)
		}
	}
}
