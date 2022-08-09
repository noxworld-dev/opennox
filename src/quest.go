package opennox

/*
#include "GAME1.h"
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
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"

	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox-lib/console"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
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
	questLevel = promauto.NewGauge(prometheus.GaugeOpts{
		Name: "nox_quest_level",
		Help: "The level of Quest game",
	})
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
		c.Print(console.ColorRed, "cannot parse value")
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
			c.Print(console.ColorRed, "cannot parse value")
			return false
		}
		v = b
	}
	questAllowDefault = v
	if v {
		c.Print(console.ColorLightYellow, "Quest warp gate will work for everyone")
	} else {
		c.Print(console.ColorLightYellow, "Quest warp gate will only work if you've passed the level already")
	}
	return true
}

func cmdSetQuestWarpInc(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	v, err := strconv.Atoi(tokens[0])
	if err != nil {
		c.Print(console.ColorRed, "cannot parse value")
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
			c.Print(console.ColorRed, "cannot parse value")
			return false
		}
		v = b
	}
	questLevelWarpInfinite = v
	if v {
		c.Print(console.ColorLightYellow, "Quest warp gate will work indefinitely")
	} else {
		c.Print(console.ColorLightYellow, "Quest warp gate will cutoff at some point")
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
	C.sub_51A920(C.int(noxRndCounter1.IntClamp(0, 2)))
	lvl := s.nox_game_getQuestStage_4E3CC0()
	lvl += questLevelInc
	questLog.Printf("switching level to %d", lvl)
	questLevel.Set(float64(lvl))
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
	s.setupQuestGame()
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

func (s *Server) setupQuestGame() {
	noxflags.UnsetGame(noxflags.GameModeMask)
	noxflags.SetGame(noxflags.GameModeQuest)
	if !sub4D6F30() {
		C.nox_game_setQuestStage_4E3CD0(0)
	}
	C.sub_4D0F30()
	noxflags.UnsetEngine(noxflags.EngineAdmin)
	noxflags.UnsetGame(noxflags.GameNotQuest)
	C.sub_4D9CF0(255)
	for _, u := range s.getPlayerUnits() {
		u.ControllingPlayer().field_4792 = 0
	}

	for _, u := range s.getPlayerUnits() {
		C.sub_4D6000(u.CObj())
		pl := u.ControllingPlayer()
		if noxflags.HasGame(noxflags.GameHost) && noxflags.HasEngine(noxflags.EngineNoRendering) {
			if pl.Index() == NOX_PLAYERINFO_MAX-1 {
				pl.field_4792 = 0
			} else {
				pl.field_4792 = C.uint(C.sub_4E4100())
			}
		} else {
			pl.field_4792 = C.uint(C.sub_4E4100())
		}
		if pl.field_4792 == 1 {
			C.sub_4D9D20(255, u.CObj())
		}
		C.nox_xxx_unitInitPlayer_4EFE80(u.CObj())
		u.AddGold(-int(pl.gold))

		var next *Object
		for it := u.FirstItem(); it != nil; it = next {
			next = it.NextItem()
			if it.Class().HasAny(object.ClassWeapon) {
				if it.SubClass()&0x8200 != 0 {
					it.Delete()
				}
			} else {
				if it.Class().HasAny(object.ClassArmor) && C.sub_415D10(C.int(it.objTypeInd()))&0x405 == 0 {
					it.Delete()
				}
			}
		}
		switch pl.PlayerClass() {
		case player.Warrior:
			C.nox_xxx_playerRespawnItem_4EF750(u.CObj(), internCStr("Sword"), nil, 1, 1)
		case player.Wizard:
			item := asObjectC(C.nox_xxx_playerRespawnItem_4EF750(u.CObj(), internCStr("SulphorousFlareWand"), nil, 1, 1))

			opt, freeOpt := alloc.Make([]unsafe.Pointer{}, 5)
			mod := C.nox_xxx_modifGetIdByName_413290(internCStr("Replenishment1"))
			opt[2] = unsafe.Pointer(C.nox_xxx_modifGetDescById_413330(mod))
			C.nox_xxx_modifSetItemAttrs_4E4990(item.CObj(), (*C.int)(unsafe.Pointer(&opt[0])))
			freeOpt()
		case player.Conjurer:
			C.nox_xxx_playerRespawnItem_4EF750(u.CObj(), internCStr("Bow"), nil, 1, 1)
		}
		if pl.field_4792 == 0 {
			pl.GoObserver(false, false)
		}
	}
	checkGameplayFlags(4)
	s.teamsZzz(1)
	t := s.teamCreate(0)
	t.def_ind = 9
	if title := s.teamTitle(9); title != "" {
		t.setNameAnd68(title, 1)
	}
	C.sub_4184D0(t.C())
	for _, u := range s.getPlayerUnits() {
		if u.ControllingPlayer().field_4792 == 1 {
			C.nox_xxx_createAtImpl_4191D0(C.uchar(t.Ind57()), unsafe.Pointer(u.teamPtr()), 1, C.int(u.net_code), 0)
		}
	}
	C.sub_4D6BE0()
	C.sub_4D6A60()
}

func (s *Server) setQuestFlag(v int) {
	s.quest.nox_xxx_questFlag_1556148 = v
}

func (s *Server) getQuestFlag() int {
	return s.quest.nox_xxx_questFlag_1556148
}

func (s *Server) cmdStartSoloQuest() {
	C.nox_client_gui_flag_1556112 = 1
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	*memmap.PtrUint32(0x5D4594, 1556152) = uint32(bool2int(sub_416A00()))
	sub_4169E0()
	noxServer.setQuestFlag(30)
}

func sub_4DCE60(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1563100) = uint32(a1)
}

func (s *Server) setQuestMapName(name string) {
	s.quest.mapName = name
}

func (s *Server) getQuestMapName() string {
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
			ifs.Remove(path)
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
