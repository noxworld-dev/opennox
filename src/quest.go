package opennox

import (
	"context"
	"os"
	"strconv"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"

	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
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
	return legacy.Nox_game_getQuestStage_4E3CC0()
}

func (s *Server) nox_xxx_getQuestStage_51A930() int {
	return legacy.Nox_xxx_getQuestStage_51A930()
}

func (s *Server) nox_game_setQuestStage_4E3CD0(lvl int) {
	legacy.Nox_game_setQuestStage_4E3CD0(lvl)
}

func questNextStageThreshold(lvl int) int {
	if !questLevelWarpInfinite && lvl >= questLevelWrapCutoffDef {
		return lvl
	}
	next := (lvl / questLevelWarpInc) + 1
	return next * questLevelWarpInc
}

func nox_server_questAllowDefault() bool {
	return questAllowDefault
}

func nox_server_questNextStageThreshold_4D74F0(lvl int) int {
	return questNextStageThreshold(lvl)
}

func (s *Server) nox_server_questMapNextLevel() {
	// server loading next quest level
	legacy.Sub_51A920(s.Rand.Logic.IntClamp(0, 2))
	lvl := s.nox_game_getQuestStage_4E3CC0()
	lvl += questLevelInc
	questLog.Printf("switching level to %d", lvl)
	questLevel.Set(float64(lvl))
	s.nox_game_setQuestStage_4E3CD0(lvl)
	lvl = s.nox_xxx_getQuestStage_51A930()
	legacy.Sub_51A1F0(lvl)
	legacy.Sub_4E3D50()
	legacy.Sub_4E3DD0()
	legacy.Sub_4F1F20()
	name := s.nox_server_currentMapGetFilename_409B30()
	questLog.Printf("loading map: %q", name)
	legacy.Sub_4D10F0(name)
	legacy.Sub_4D7520(1)
	if !questLevelWarpInfinite {
		cutoff := uint(s.Balance.Float("WarpGateCutoffStage"))
		if uint(s.nox_game_getQuestStage_4E3CC0()) >= cutoff {
			legacy.Sub_4D7520(0)
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
		mapFile = legacy.Nox_xxx_getQuestMapFile_4D0F60()
	}
	s.SwitchMap(mapFile)
	s.setQuestMapName("")
	s.nox_game_setQuestStage_4E3CD0(0)
	sub_4169F0()
}

func (s *Server) setupQuestGame() {
	noxflags.UnsetGame(noxflags.GameModeMask)
	noxflags.SetGame(noxflags.GameModeQuest)
	if !sub4D6F30() {
		legacy.Nox_game_setQuestStage_4E3CD0(0)
	}
	legacy.Sub_4D0F30()
	noxflags.UnsetEngine(noxflags.EngineAdmin)
	noxflags.UnsetGame(noxflags.GameNotQuest)
	legacy.Sub_4D9CF0(255)
	for _, u := range s.Players.ListUnits() {
		u.ControllingPlayer().Field4792 = 0
	}

	for _, u := range s.Players.ListUnits() {
		legacy.Sub_4D6000(u)
		pl := u.ControllingPlayer()
		if noxflags.HasGame(noxflags.GameHost) && noxflags.HasEngine(noxflags.EngineNoRendering) {
			if pl.Index() == common.MaxPlayers-1 {
				pl.Field4792 = 0
			} else {
				pl.Field4792 = legacy.Sub_4E4100()
			}
		} else {
			pl.Field4792 = legacy.Sub_4E4100()
		}
		if pl.Field4792 == 1 {
			legacy.Sub_4D9D20(255, u)
		}
		legacy.Nox_xxx_unitInitPlayer_4EFE80(u)
		asObjectS(u).AddGold(-int(pl.GoldVal))

		var next *server.Object
		for it := u.FirstItem(); it != nil; it = next {
			next = it.NextItem()
			if it.Class().HasAny(object.ClassWeapon) {
				if it.SubClass()&0x8200 != 0 {
					asObjectS(it).Delete()
				}
			} else {
				if it.Class().HasAny(object.ClassArmor) && legacy.Sub_415D10(int(it.TypeInd))&0x405 == 0 {
					asObjectS(it).Delete()
				}
			}
		}
		switch pl.PlayerClass() {
		case player.Warrior:
			legacy.Nox_xxx_playerRespawnItem_4EF750(u, "Sword", nil, 1, 1)
		case player.Wizard:
			item := legacy.Nox_xxx_playerRespawnItem_4EF750(u, "SulphorousFlareWand", nil, 1, 1)

			opt, freeOpt := alloc.Make([]unsafe.Pointer{}, 5)
			mod := s.Modif.Nox_xxx_modifGetIdByName413290("Replenishment1")
			opt[2] = unsafe.Pointer(s.Modif.Nox_xxx_modifGetDescById413330(mod))
			legacy.Nox_xxx_modifSetItemAttrs_4E4990(item, unsafe.Pointer(&opt[0]))
			freeOpt()
		case player.Conjurer:
			legacy.Nox_xxx_playerRespawnItem_4EF750(u, "Bow", nil, 1, 1)
		}
		if pl.Field4792 == 0 {
			s.PlayerGoObserver(pl, false, false)
		}
	}
	s.TeamsRemoveActive(true)
	t := s.Teams.Create(0)
	t.ColorInd = server.TeamOrange
	if title := s.Teams.TeamTitle(server.TeamOrange); title != "" {
		t.SetNameAnd68(title, 1)
	}
	legacy.Sub_4184D0(t.C())
	for _, u := range s.Players.ListUnits() {
		if u.ControllingPlayer().Field4792 == 1 {
			legacy.Nox_xxx_createAtImpl_4191D0(t.ID(), u.TeamPtr(), 1, u.NetCode, 0)
		}
	}
	sub_4D6BE0()
	sub_4D6A60()
}

func (s *Server) setQuestFlag(v int) {
	s.quest.nox_xxx_questFlag_1556148 = v
}

func (s *Server) getQuestFlag() int {
	return s.quest.nox_xxx_questFlag_1556148
}

func (s *Server) cmdStartSoloQuest() {
	legacy.Set_nox_client_gui_flag_1556112(1)
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

func sub4DCEE0(path string) {
	if path != "" {
		questPlayerFile = path
		questPlayerSet = true
	} else {
		questPlayerSet = false
	}
}

func sub_4DCF20() {
	if questPlayerSet && noxServer.getQuestFlag() == 0 {
		if pl := noxServer.Players.ByInd(common.MaxPlayers - 1); pl != nil && pl.Field3680&0x10 != 0 {
			path := questPlayerFile
			legacy.Nox_xxx_cliPlrInfoLoadFromFile_41A2E0(path, common.MaxPlayers-1)
			questPlayerSet = false
			ifs.Remove(path)
		}
	}
}

func sub_4D6F30() int {
	return bool2int(sub4D6F30())
}

func sub4D6F30() bool { // sub_4D6F30
	return questFlag_1556156
}

func sub4D6F40(a1 bool) {
	questFlag_1556156 = a1
}
