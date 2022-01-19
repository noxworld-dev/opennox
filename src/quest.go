package nox

/*
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_1.h"
int  sub_51A920(int a1);
void sub_4D10F0(char* a1);
void sub_4F1F20();
void sub_51A1F0(int a1);
extern unsigned int nox_client_gui_flag_1556112;
*/
import "C"
import (
	"context"
	"os"
	"strconv"

	"nox/v1/common/console"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/fs"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
)

const (
	questLevelWrapIncDef    = 5
	questLevelWrapCutoffDef = 20
)

type questServer struct {
	mapName                   string // 0x5D4594, 1563104
	nox_xxx_questFlag_1556148 int
}

var (
	questFlag_1556156      bool
	questPlayerFile        string // 0x5D4594, 1560984
	questPlayerSet         bool   // dword_5d4594_1563052
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
	noxConsole.Register(&console.Command{
		Token: "startSoloQuest", HelpID: "nohelp",
		Flags: console.Server | console.NoHelp,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if noxServer.nox_xxx_isQuest_4D6F50() && !noxflags.HasGame(noxflags.GameModeQuest) {
				noxServer.cmdStartSoloQuest()
			}
			return true
		},
	})
}

func cmdSetQuestLevelInc(ctx context.Context, c *console.Console, tokens []string) bool {
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

func cmdSetQuestWarpAllow(ctx context.Context, c *console.Console, tokens []string) bool {
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

func cmdSetQuestWarpInc(ctx context.Context, c *console.Console, tokens []string) bool {
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

func cmdSetQuestWarpInf(ctx context.Context, c *console.Console, tokens []string) bool {
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

func (s *Server) nox_game_getQuestStage_4E3CC0() int {
	return int(C.nox_game_getQuestStage_4E3CC0())
}

func (s *Server) nox_xxx_getQuestStage_51A930() int {
	return int(C.nox_xxx_getQuestStage_51A930())
}

func (s *Server) nox_game_setQuestStage_4E3CD0(lvl int) {
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

func (s *Server) nox_server_questMapNextLevel() {
	// server loading next quest level
	C.sub_51A920(C.int(nox_common_randomInt_415FA0(0, 2)))
	lvl := s.nox_game_getQuestStage_4E3CC0()
	lvl += questLevelInc
	questLog.Printf("switching level to %d", lvl)
	s.nox_game_setQuestStage_4E3CD0(lvl)
	lvl = s.nox_xxx_getQuestStage_51A930()
	C.sub_51A1F0(C.int(lvl))
	C.sub_4E3D50()
	C.sub_4E3DD0()
	C.sub_4F1F20()
	name := s.nox_server_currentMapGetFilename_409B30()
	questLog.Printf("loading map: %q", name)
	C.sub_4D10F0(internCStr(name))
	C.sub_4D7520(1)
	if !questLevelWarpInfinite {
		cutoff := uint(gamedataFloat("WarpGateCutoffStage"))
		if uint(s.nox_game_getQuestStage_4E3CC0()) >= cutoff {
			C.sub_4D7520(0)
		}
	}
}

func (s *Server) switchQuestIfRequested4D6FD0() {
	if s.quest.nox_xxx_questFlag_1556148 == 0 {
		return
	}
	s.quest.nox_xxx_questFlag_1556148--
	if s.quest.nox_xxx_questFlag_1556148 != 0 {
		return
	}
	mapName := s.getQuestMapName()
	C.nox_server_setupQuestGame_4D6C70()
	var mapFile string
	if mapName != "" {
		mapFile = mapName + ".map"
	} else {
		mapFile = GoString(C.nox_xxx_getQuestMapFile_4D0F60())
	}
	s.switchMap(mapFile)
	s.setQuestMapName("")
	s.nox_game_setQuestStage_4E3CD0(0)
	sub_4169F0()
}

func (s *Server) setQuestFlag(v int) {
	s.quest.nox_xxx_questFlag_1556148 = v
}

func (s *Server) getQuestFlag() int {
	return s.quest.nox_xxx_questFlag_1556148
}

func (s *Server) cmdStartSoloQuest() { // nox_server_conCmdHandler_startSoloQuest_4D7080
	C.nox_client_gui_flag_1556112 = 1
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	*memmap.PtrUint32(0x5D4594, 1556152) = uint32(bool2int(sub_416A00()))
	sub_4169E0()
	noxServer.setQuestFlag(30)
}

func sub_4DCE60(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1563100) = uint32(a1)
}

func (s *Server) setQuestMapName(name string) { // sub_4DCE80
	s.quest.mapName = name
}

func (s *Server) getQuestMapName() string { // nox_xxx_getQuestMapName_4DCED0
	return s.quest.mapName
}

//export sub_4DCEE0
func sub_4DCEE0(str *C.char) {
	sub4DCEE0(GoString(str))
}

func sub4DCEE0(path string) { // sub_4DCEE0
	if path != "" {
		questPlayerFile = path
		questPlayerSet = true
	} else {
		questPlayerSet = false
	}
}

func sub_4DCF20() {
	if questPlayerSet && noxServer.getQuestFlag() == 0 {
		if pl := noxServer.getPlayerByInd(31); pl != nil && pl.field_3680&0x10 != 0 {
			path := questPlayerFile
			C.nox_xxx_cliPlrInfoLoadFromFile_41A2E0(internCStr(path), 31)
			questPlayerSet = false
			fs.Remove(path)
		}
	}
}

//export sub_4D6F30
func sub_4D6F30() C.int {
	return C.int(bool2int(sub4D6F30()))
}

func sub4D6F30() bool { // sub_4D6F30
	return questFlag_1556156
}

//export sub_4D6F40
func sub_4D6F40(a1 C.int) {
	sub4D6F40(a1 != 0)
}

func sub4D6F40(a1 bool) { // sub_4D6F40
	questFlag_1556156 = a1
}
