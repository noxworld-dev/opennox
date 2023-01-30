package opennox

import (
	"context"
	"errors"
	"fmt"
	"image"
	"math"
	"path/filepath"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/lobby"
	"github.com/noxworld-dev/xwis"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/discover"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/internal/version"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	useXWIS                   = true
	gameLog                   = log.New("game")
	nox_game_playState_811372 int
	dword_5D4594_251544       []unsafe.Pointer
	dword_5d4594_251556       []unsafe.Pointer
	movieFilesStackCur        int
	movieFilesStack           [2]string
	dword_587000_311372       = -1
	dword_5d4594_2516476      byte
	gameIsNotMultiplayer      bool
	gameIsSwitchToSolo        bool
)

func init() {
	configBoolPtr("network.xwis.register", "NOX_XWIS", true, &useXWIS)
	gui.RegisterState(client.StateMovies, "Movies", nox_game_rollLogoAndStart_4AB1F0)
	gui.RegisterState(client.StateMainMenu, "MainMenu", nox_game_showMainMenu4A1C00)
	gui.RegisterState(client.StateCharSelect, "CharSelect", func() bool {
		legacy.Sub_4A7A70(1)
		return nox_game_showSelChar4A4DB0()
	})
	noxCmdShow.Register(&console.Command{
		Token:  "game",
		HelpID: "showgamehelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) != 0 {
				return false
			}
			players := noxServer.Players.Count()
			if noxflags.HasEngine(noxflags.EngineNoRendering) {
				players--
			}
			subVer := ""
			if noxHighRes {
				subVer = " HD"
			}
			c.Printf(console.ColorRed, "OpenNox%s %s", subVer, version.ClientVersion())
			if noxflags.HasGame(noxflags.GameOnline) {
				sname := noxServer.getServerName()
				str := c.Strings().GetStringInFile("Name", "parsecmd.c")
				c.Printf(console.ColorRed, "%s %s", str, sname)

				v16 := legacy.Nox_xxx_guiServerOptionsGetGametypeName_4573C0(noxflags.GetGame())
				str = c.Strings().GetStringInFile("Type", "parsecmd.c")
				c.Printf(console.ColorRed, "%s %s", str, v16)

				p := legacy.Sub_4165B0()
				ind := int16(*(*uint16)(unsafe.Add(p, 52)))
				timeLimit := legacy.Sub_40A180(noxflags.GameFlag(ind))
				lessons := legacy.Nox_xxx_servGamedataGet_40A020(ind)
				maxPlayers := noxServer.getServerMaxPlayers()
				mname := noxServer.nox_server_currentMapGetFilename_409B30()
				format := c.Strings().GetStringInFile("GameInfo", "parsecmd.c")
				c.Printf(console.ColorRed, format, mname, players, maxPlayers, lessons, timeLimit)
				c.Print(console.ColorRed, netGetIP(0).String())
			}
			return true
		},
	})
}

func gameGetPlayState() int {
	return nox_game_playState_811372
}

func gameSetPlayState(st int) {
	gameLog.Println("play state:", st)
	nox_game_playState_811372 = st
}

func nox_game_setMovieFile_4CB230(name string) (string, bool) {
	filename := filepath.Join("movies", name)
	_, err := ifs.Stat(filename)
	if err != nil {
		gameLog.Printf("movie not found: %q", filename)
		return "", false
	}
	gameLog.Printf("movie found: %q", filename)
	return filename, true
}

func pushMovieFile(path string) {
	if movieFilesStackCur < 2 {
		movieFilesStack[movieFilesStackCur] = path
		movieFilesStackCur++
	}
}

func sub_578E00() {
	dword_587000_311372 = -1
}

func sub_578DF0() byte {
	return dword_5d4594_2516476
}

func sub_578DE0(v byte) {
	dword_5d4594_2516476 = v
}
func nox_xxx_GetEndgameDialog() string {
	if dword_587000_311372 == 0 {
		if dword_5d4594_2516476&2 == 0 {
			return "gmcap14e.wav"
		}
		if dword_5d4594_2516476&4 == 0 {
			return "gmcap13e.wav"
		}
	} else if dword_587000_311372 == 1 {
		if dword_5d4594_2516476&1 == 0 {
			return "gmcap17e.wav"
		}
		if dword_5d4594_2516476&4 == 0 {
			return "gmcap18e.wav"
		}
	} else if dword_587000_311372 == 2 {
		if dword_5d4594_2516476&2 == 0 {
			return "gmcap16e.wav"
		}
		if dword_5d4594_2516476&1 == 0 {
			return "gmcap15e.wav"
		}
	}
	return ""
}

func sub_578CD0() {
	if dword_587000_311372 != -1 {
		names := []string{
			"warrior", "wizard", "conjurer",
		}
		name := names[dword_587000_311372] + ".vqa"
		if path, ok := nox_game_setMovieFile_4CB230(name); ok {
			pushMovieFile(path)
			sub4B0640(sub_578C60)
			if err := noxClient.DrawGeneral(true); err != nil {
				videoLog.Println(err)
			}
		} else {
			sub_578C60()
		}
	}
}

func sub_578C60() {
	if legacy.Sub_44E560() != nil {
		legacy.Nox_client_lockScreenBriefing_450160(255, 1, 0)
		sub_4A2530()
	}
}

func nox_game_rollLogoAndStart_4AB1F0() bool {
	if isServer || isServerQuest {
		// FIXME: switch to server state directly
		return startServer()
	}
	noxClient.GamePopState()
	if noxflags.HasGame(noxflags.GameFlag26) {
		nox_game_rollIntroAndStart_4AB170()
		return true
	}
	path, ok := nox_game_setMovieFile_4CB230("wwlogo.vqa")
	if !ok {
		nox_game_rollIntroAndStart_4AB170()
		return true
	}
	pushMovieFile(path)
	sub4B0640(nox_game_rollIntroAndStart_4AB170)
	if err := noxClient.DrawGeneral(false); err != nil {
		videoLog.Println(err)
	}
	return true
}

func nox_game_rollIntroAndStart_4AB170() {
	if sub_578DF0()&0x80 != 0 || noxflags.HasGame(noxflags.GameFlag26) {
		nox_game_rollNoxLogoAndStart_4AB0F0()
		return
	}
	path, ok := nox_game_setMovieFile_4CB230("intro.vqa")
	if !ok {
		nox_game_rollNoxLogoAndStart_4AB0F0()
		return
	}
	pushMovieFile(path)
	sub4B0640(nox_game_rollNoxLogoAndStart_4AB0F0)
	if err := noxClient.DrawGeneral(true); err != nil {
		videoLog.Println(err)
	}
	sub_578DE0(sub_578DF0() | 0x80)
}

func nox_game_rollNoxLogoAndStart_4AB0F0() {
	if noxflags.HasGame(noxflags.GameFlag26) {
		nox_game_showLegal_4CC4E0()
		return
	}
	path, ok := nox_game_setMovieFile_4CB230("noxlogo.vqa")
	if !ok {
		nox_game_showLegal_4CC4E0()
		return
	}
	pushMovieFile(path)
	sub4B0640(nox_game_showLegal_4CC4E0)
	if err := noxClient.DrawGeneral(false); err != nil {
		videoLog.Println(err)
	}
}

func startServer() bool {
	legacy.Set_nox_game_createOrJoin_815048(1)
	noxflags.SetEngine(noxflags.EngineAdmin)
	noxflags.UnsetEngine(noxflags.EngineGodMode)
	noxflags.SetGame(noxflags.GameOnline)
	if !isServerQuest {
		noxflags.SetGame(noxflags.GameNotQuest)
	} else {
		noxflags.UnsetGame(noxflags.GameNotQuest)
	}
	noxflags.UnsetGame(noxflags.GameModeCoop)
	legacy.Sub_461440(0)
	sub4D6F40(false)
	sub_4D6F90(0)
	if !isServerQuest {
		noxServer.nox_xxx_setQuest_4D6F60(0)
	} else {
		noxServer.nox_xxx_setQuest_4D6F60(1)
		legacy.Nox_xxx_cliShowHideTubes_470AA0(1)
	}
	legacy.Sub_4D6F80(0)
	if sub_473670() == 0 {
		nox_client_toggleMap_473610()
	}
	if !isServerQuest {
		legacy.Nox_xxx_cliShowHideTubes_470AA0(0)
	}
	legacy.Nox_xxx_cliSetMinimapZoom_472520(2300)
	legacy.Sub_43AF50()
	if nox_xxx_parseGamedataBinPre_4D1630() == 0 {
		nox_xxx_setContinueMenuOrHost_43DDD0(0)
		nox_client_gui_flag_815132 = 0
		return false
	}
	nox_xxx_serverHost_43B4D0()
	return true
}

func (s *Server) getServerName() string {
	return legacy.Nox_xxx_serverOptionsGetServername_40A4C0()
}

func (s *Server) getServerMap() string {
	return legacy.Nox_xxx_mapGetMapName_409B40()
}

func (s *Server) getServerMaxPlayers() int {
	return legacy.Nox_xxx_servGetPlrLimit_409FA0()
}

func (s *Server) nox_xxx_isQuest_4D6F50() bool {
	return memmap.Uint32(0x5D4594, 1556160) != 0
}

func (s *Server) nox_xxx_setQuest_4D6F60(v int) {
	*memmap.PtrUint32(0x5D4594, 1556160) = uint32(v)
}

func sub_4D6F90(a1 uint32) {
	*memmap.PtrUint32(0x5D4594, 1556104) = a1
}

type srvReg struct {
	cur xwisInfoShort
	srv *discover.RegServer
}

func nox_xxx_serverHost_43B4D0() {
	isHost := legacy.Get_nox_game_createOrJoin_815048() != 0
	gameLog.Println("host:", isHost)
	if isHost {
		legacy.
			// host
			Nox_client_xxx_switchChatMap_43B510()
		legacy.Nox_client_guiXxx_43A9D0()
		nox_client_guiXxxDestroy_4A24A0()
		noxServer.ai.nox_xxx_gameSetAudioFadeoutMb(0)
	} else {
		legacy.
			// join
			Sub_43B630()
		nox_client_createSockAndJoin_43B440()
	}
	legacy.Sub_49FF20()
	if isHost {
		noxServer.maybeRegisterGameOnline()
	} else {
		noxServer.maybeStopRegister()
	}
}

type xwisInfoShort struct {
	Name       string
	Map        string
	Port       int
	Flags      noxflags.GameFlag
	Access     lobby.GameAccess
	Players    []lobby.PlayerInfo
	MaxPlayers int
	Level      int
	Res        image.Point
}

func (v *xwisInfoShort) Equal(v2 *xwisInfoShort) bool {
	return v.Name == v2.Name && v.Map == v2.Map &&
		v.Port == v2.Port && v.Flags == v2.Flags &&
		v.Access == v2.Access && len(v.Players) == len(v2.Players) &&
		v.MaxPlayers == v2.MaxPlayers && v.Level == v2.Level &&
		v.Res == v2.Res
}

func (s *Server) getGameInfo() xwisInfoShort {
	access := lobby.AccessOpen
	if acc := sub_416640(); acc[100]&0x20 != 0 {
		access = lobby.AccessPassword
	} else if acc[100]&0x10 != 0 {
		access = lobby.AccessClosed
	}
	players := s.GetPlayers()
	list := make([]lobby.PlayerInfo, 0, len(players))
	for _, p := range players {
		list = append(list, lobby.PlayerInfo{
			Name:  p.Name(),
			Class: p.PlayerClass().String(),
		})
	}
	res := videoGetMaxSize()
	if !isDedicatedServer {
		res = noxClient.videoGetGameMode()
	}
	return xwisInfoShort{
		Port:       s.ServerPort(),
		Name:       s.getServerName(),
		Map:        s.getServerMap(),
		Flags:      noxflags.GetGame(),
		Players:    list,
		MaxPlayers: s.getServerMaxPlayers(),
		Level:      s.nox_game_getQuestStage_4E3CC0(),
		Access:     access,
		Res:        res,
	}
}

func xwisIsQuest(info *xwis.GameInfo) bool {
	flags := int(info.Flags) | int(info.MapType)
	return flags&int(xwis.MapTypeQuest) != 0
}

func gameFlagsToMode(f noxflags.GameFlag) lobby.GameMode {
	switch {
	case f.Has(noxflags.GameModeKOTR):
		return lobby.ModeKOTR
	case f.Has(noxflags.GameModeCTF):
		return lobby.ModeCTF
	case f.Has(noxflags.GameModeFlagBall):
		return lobby.ModeFlagBall
	case f.Has(noxflags.GameModeChat):
		return lobby.ModeChat
	case f.Has(noxflags.GameModeArena):
		return lobby.ModeArena
	case f.Has(noxflags.GameModeElimination):
		return lobby.ModeElimination
	case f.Has(noxflags.GameModeQuest):
		return lobby.ModeQuest
	case f.Has(noxflags.GameModeCoop):
		return lobby.ModeCoop
	}
	return lobby.ModeCustom
}

func gameAccessToXWIS(v lobby.GameAccess) xwis.Access {
	switch v {
	case lobby.AccessOpen:
		return xwis.AccessOpen
	case lobby.AccessClosed:
		return xwis.AccessClosed
	case lobby.AccessPassword:
		return xwis.AccessPrivate
	}
	return xwis.AccessOpen
}

func (v xwisInfoShort) GameInfo() discover.GameInfo {
	info := discover.GameInfo{
		Game: lobby.Game{
			Name: v.Name,
			Port: v.Port,
			Map:  v.Map,
			Res: lobby.Resolution{
				Width:   v.Res.X,
				Height:  v.Res.Y,
				HighRes: noxHighRes,
			},
			Mode: gameFlagsToMode(v.Flags),
			Vers: version.Version(),
			Players: lobby.PlayersInfo{
				Cur:  len(v.Players),
				Max:  v.MaxPlayers,
				List: v.Players,
			},
		},
		XWIS: xwis.GameInfo{
			Name:       v.Name,
			Map:        v.Map,
			Resolution: xwis.Res1024x768,
			Flags:      xwis.GameFlags(v.Flags),
			Access:     gameAccessToXWIS(v.Access),
			Players:    len(v.Players),
			MaxPlayers: v.MaxPlayers,
		},
	}
	if v.Flags.Has(noxflags.GameModeQuest) {
		info.Game.Quest = &lobby.QuestInfo{Stage: v.Level}
	}
	if xwisIsQuest(&info.XWIS) {
		info.XWIS.FragLimit = v.Level
	}
	return info
}

func (s *Server) maybeRegisterGameOnline() {
	if !useXWIS || !noxflags.HasGame(noxflags.GameOnline) || env.IsE2E() || !(isDedicatedServer || s.announce) {
		s.maybeStopRegister()
		return
	}
	info := s.getGameInfo()
	if s.srvReg.srv == nil {
		s.srvReg.cur = info
		s.srvReg.srv = discover.NewServer(info.GameInfo())
		return
	}
	if s.srvReg.cur.Equal(&info) {
		return
	}
	s.srvReg.cur = info
	s.srvReg.srv.Update(info.GameInfo())
}

func (s *Server) maybeStopRegister() {
	if s.srvReg.srv != nil {
		s.srvReg.srv.Close()
		s.srvReg.srv = nil
	}
}

func initGameSession435CC0() error {
	ctx := context.Background()
	legacy.Sub_445450()
	legacy.Sub_45DB90()
	legacy.Sub_41D1A0(0)
	legacy.Nox_xxx_initTime_435570()
	legacy.Set_nox_client_gui_flag_1556112(0)

	if legacy.Nox_alloc_drawable_init(5000) == 0 {
		return errors.New("nox_alloc_drawable_init failed")
	}

	sub_49A8E0_init()

	if legacy.Nox_xxx_allocArrayHealthChanges_49A5F0() == 0 {
		return errors.New("nox_xxx_allocArrayHealthChanges_49A5F0 failed")
	}

	if err := nox_xxx_parseThingBinClient_44C840_read_things(); err != nil {
		return err
	}

	if legacy.Nox_xxx_loadGuides_427070() == 0 {
		return errors.New("nox_xxx_loadGuides_427070 failed")
	}

	if legacy.Sub_494F00() == 0 {
		return errors.New("sub_494F00 failed")
	}

	if !isDedicatedServer {
		if err := nox_game_guiInit_473680(); err != nil {
			return fmt.Errorf("game gui init failed: %w", err)
		}
	}
	legacy.Nox_alloc_npcs()
	if legacy.Nox_xxx_loadReflSheild_499360() == 0 {
		return errors.New("nox_xxx_loadReflSheild_499360 failed")
	}

	noxClient.nox_xxx_initSight_485F80()
	if legacy.Sub_4960B0() == 0 {
		return errors.New("sub_4960B0 failed")
	}

	initDrawableLists()

	if legacy.Nox_xxx_allocArrayDrawableFX_495AB0() == 0 {
		return errors.New("nox_xxx_allocArrayDrawableFX_495AB0 failed")
	}

	if legacy.Nox_xxx_allocClassListFriends_495980() == 0 {
		return errors.New("nox_xxx_allocClassListFriends_495980 failed")
	}
	legacy.Sub_4958F0()
	nox_xxx_gameSetCliConnected(false)
	noxflags.SetGame(noxflags.GameFlag24)
	if noxflags.HasGame(noxflags.GameHost) {
		if !isDedicatedServer {
			legacy.Nox_xxx_netPlayerIncomingServ_4DDF60(common.MaxPlayers - 1)
		}
	} else {
		nox_xxx_netSendIncomingClient_43CB00()
	}
	noxClient.SetDrawFunc(noxClient.clientDraw)
	gameSetPlayState(3)
	*memmap.PtrUint32(0x587000, 85720) = 1
	sz := videoGetWindowSize()
	vp := noxClient.Viewport()
	vp.Screen = image.Rect(0, 0, sz.X-1, sz.Y-1)
	vp.Size = sz
	vp.Field10 = 0
	vp.Field11 = 0
	vp.Field12 = 0
	v1 := nox_video_getCutSize()
	noxClient.nox_draw_setCutSize(v1, 0)
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_41CC00((*byte)(memmap.PtrOff(0x85B3FC, 10984)))
	} else if noxServer.nox_xxx_isQuest_4D6F50() || sub_4D6F70() {
		if noxServer.nox_xxx_isQuest_4D6F50() || sub_4D6F70() {
			legacy.Sub_460380()
			legacy.Nox_xxx_cliPrepareGameplay1_460E60()
			legacy.Nox_xxx_cliPrepareGameplay2_4721D0()
		}
		if !noxflags.HasGame(noxflags.GameHost) {
			legacy.Sub_41CC00((*byte)(memmap.PtrOff(0x85B3FC, 10984)))
		}
	}
	if !isServer {
		legacy.Nox_xxx_plrLoad_41A480(alloc.GoString((*byte)(memmap.PtrOff(0x85B3FC, 10984))))
	}
	if isServer && !isDedicatedServer {
		noxServer.GetPlayers()[0].GoObserver(false, true)
	}
	execConsoleCmdAuthed(ctx, "execrul autoexec.rul")
	if isServer {
		execServerCmd("set cycle on")
		for _, cmd := range serverExec {
			if len(cmd) == 0 {
				continue
			}
			execServerCmd(cmd)
		}
	}
	legacy.Sub_4951C0()
	legacy.Sub_465DE0(0)
	return nil
}

func execConsoleCmd(ctx context.Context, cmd string) bool { // nox_server_parseCmdText_443C80
	cmd = strings.TrimSpace(cmd)
	if len(cmd) == 0 {
		return false
	}
	if consoleWaitSysOpPass {
		nox_console_sendSysOpPass_4409D0(cmd)
		consoleWaitSysOpPass = false
		return true
	}
	return execConsoleCmdAuthed(ctx, cmd)
}

func execConsoleCmdAuthed(ctx context.Context, cmd string) bool {
	cmd = strings.TrimSpace(cmd)
	if len(cmd) == 0 {
		return false
	}
	if noxflags.HasGame(noxflags.GameHost) {
		ctx = console.AsServer(ctx)
	} else {
		ctx = console.AsClient(ctx)
	}
	if noxflags.HasEngine(noxflags.EngineNoRendering) {
		ctx = console.AsDedicated(ctx)
	}
	return noxConsole.Exec(ctx, cmd)
}

func execServerCmd(cmd string) {
	cmd = strings.TrimSpace(cmd)
	if len(cmd) == 0 {
		return
	}
	ctx := context.Background()
	ctx = console.AsServer(ctx)
	if noxflags.HasEngine(noxflags.EngineNoRendering) {
		ctx = console.AsDedicated(ctx)
	}
	ctx = console.WithCheats(ctx)
	noxConsole.Exec(ctx, cmd)
}

func serverCmdLoadMap(name string) {
	if len(name) == 0 {
		return
	}
	execServerCmd("load " + name)
}

func (s *Server) nox_server_currentMapGetFilename_409B30() string {
	return memmap.String(0x5D4594, 2598188)
}

func nox_xxx_mapFilenameGetSolo_4DB260() string {
	return dword_5d4594_1559960
}

func (s *Server) nox_xxx_servInitialMapLoad_4D17F0() bool {
	legacy.Sub_4E79B0(0)
	if s.nox_server_currentMapGetFilename_409B30() == "" {
		s.nox_xxx_gameSetMapPath_409D70("tutorial.map")
	}
	legacy.Nox_xxx_netMapSendStop_519870()
	if err := s.nox_xxx_mapExitAndCheckNext_4D1860_server(); err != nil {
		gameLog.Println(err)
		return false
	}
	if debugMainloop {
		log.Println("gameStateFunc = nox_xxx_gameTick_4D2580_server")
	}
	s.SetUpdateFunc(s.nox_xxx_gameTick_4D2580_server)
	netlist.ResetAllInd(netlist.Kind1)
	noxflags.SetGame(noxflags.GameFlag18)
	legacy.Nox_xxx_netGameSettings_4DEF00()
	legacy.Nox_server_gameUnsetMapLoad_40A690()
	return true
}

func (s *Server) nox_xxx_gameTick_4D2580_server() bool {
	defer s.RunTickHooks()
	ticks := platformTicks()
	v2 := false
	if legacy.Get_dword_5d4594_2650652() == 0 {
		netlist.ResetAllInd(netlist.Kind1)
	} else {
		v4 := nox_xxx_rateGet_40A6C0()
		if legacy.Sub_416650() != 0 && legacy.Sub_41E2F0() == 8 {
			v2 = true
		}
		if v4 == 1 || noxflags.HasGame(noxflags.GameFlag4) || s.Frame()%uint32(v4) == 1 {
			netlist.ResetAllInd(netlist.Kind1)
		}
	}
	s.Audio.Reset()
	netstr.Update()
	if noxflags.HasEngine(noxflags.EngineReplayRead) {
		s.nox_xxx_replayTickMB_4D3580_net_playback(true)
	}
	if noxflags.HasEngine(noxflags.EngineLogBand) {
		noxPerfmon.LogBandwidth()
	}
	if noxflags.HasGame(noxflags.GameFlag4) {
		nox_xxx_gameTick_4D2580_server_A1()
		s.nox_xxx_gameTick_4D2580_server_A2(v2)
	} else if legacy.Get_dword_5d4594_1548524() == 0 {
		if !s.nox_xxx_gameTick_4D2580_server_B(ticks) {
			return true
		}
	} else if true || !v2 {
		if !s.nox_xxx_gameTick_4D2580_server_C() {
			return false
		}
	}
	s.nox_xxx_gameTick_4D2580_server_E()
	return true
}

func nox_xxx_gameTick_4D2580_server_A1() {
	if memmap.Uint64(0x5D4594, 1548676) == 0 {
		*memmap.PtrUint64(0x5D4594, 1548676) = platformTicks() + 10000
		legacy.Nox_xxx_guiServerOptionsHide_4597E0(0)
		netstr.Log.Println("EndGame")
		legacy.Sub_46DCC0()
	}
}

func (s *Server) nox_xxx_gameTick_4D2580_server_A2(v2 bool) {
	nox_server_netMaybeSendInitialPackets_4DEB30()
	s.nox_xxx_netlist_4DEB50()
	if platformTicks() <= memmap.Uint64(0x5D4594, 1548676) || v2 {
		return
	}
	*memmap.PtrUint32(0x5D4594, 1548676) = 0
	*memmap.PtrUint32(0x5D4594, 1548680) = 0
	legacy.Set_dword_5d4594_1548524(1)
	sub_416170(12)
	noxflags.UnsetGame(noxflags.GameFlag4)
	for _, u := range s.getPlayerUnits() {
		u.dropAllItems()
		legacy.Nox_xxx_playerMakeDefItems_4EF7D0(u.SObj(), 1, 0)
	}
	s.ObjectsNewAdd()
	if noxflags.HasGame(noxflags.GameModeSolo10) {
		return
	}
	v7 := nox_xxx_cliGamedataGet_416590(0)
	if v7[57] != 0 {
		v8 := legacy.Sub_409B80() + ".map"
		s.nox_xxx_gameSetMapPath_409D70(v8)
		v7[57] = 0
	} else if legacy.Sub_4D0D70() != 0 {
		legacy.Nox_xxx_loadMapCycle_4D0A30()
		v11 := legacy.Nox_xxx_getSomeMapName_4D0CF0()
		if v11 != "" {
			v12 := s.nox_server_currentMapGetFilename_409B30()
			if strings.ToLower(v11) == strings.ToLower(v12) {
				v11 = legacy.Nox_xxx_getSomeMapName_4D0CF0()
			}
			if v11 != "" {
				s.nox_xxx_gameSetMapPath_409D70(v11)
			}
		}
	}
}

func nox_xxx_cliGamedataGet_416590(v int) []byte {
	return unsafe.Slice((*byte)(legacy.Nox_xxx_cliGamedataGet_416590(v)), 60)
}

func nox_xxx_gameSetNoMPFlag_4DB230(a1 int) {
	gameIsNotMultiplayer = a1 != 0
}

func nox_xxx_gameIsNotMultiplayer_4DB250() bool {
	return gameIsNotMultiplayer
}

func nox_xxx_gameSetSwitchSolo_4DB220(a1 int) {
	gameIsSwitchToSolo = a1 != 0
}

func nox_xxx_gameIsSwitchToSolo_4DB240() bool {
	return gameIsSwitchToSolo
}

func (s *Server) nox_xxx_gameTick_4D2580_server_D() {
	pl := s.GetPlayerByInd(common.MaxPlayers - 1)
	if pl == nil {
		return
	}
	u := pl.UnitC()
	if u == nil || sub_4DCC10(u.SObj()) != 1 {
		return
	}
	v23 := false
	v24 := (u.Flags()>>15)&1 != 0
	if !v24 {
		s.scriptOnEvent("MapShutdown")
		noxflags.SetGame(noxflags.GameFlag28)
		v26 := legacy.Sub_4DB160()
		v23 = nox_xxx_saveDoAutosaveMB_4DB370_savegame(v26) != 0
		noxflags.UnsetGame(noxflags.GameFlag28)
		if !v23 && noxflags.HasGame(noxflags.GameClient) {
			v35 := strMan.GetStringInFile("GUISave.c:SaveErrorTitle", "C:\\NoxPost\\src\\Server\\System\\server.c")
			NewDialogWindow(nil, v35, v35, 33, nil, nil)
		}
	}
	v28 := sub_4DB1C0()
	if v24 || !v23 {
		if v28 != nil && !v23 {
			u.SetPos(legacy.AsPointf(unsafe.Pointer(*(*uintptr)(unsafe.Add(v28, 700)) + 80)))
		}
	} else if v28 != nil {
		v30 := alloc.GoString(*(**byte)(unsafe.Add(v28, 700)))
		v31, err := nox_client_checkSaveMapExistsTmp(v30)
		if err == nil && v31 != "" {
			nox_xxx_gameSetSwitchSolo_4DB220(1)
			nox_xxx_gameSetNoMPFlag_4DB230(1)
			nox_xxx_gameSetSoloSavePath_4DB270(v31)
		} else {
			gameLog.Println("check tmp map exists:", err)
		}
		s.SwitchMap(v30)
	}
	sub_4DB170(0, v28, 0)
}

func (s *Server) nox_xxx_gameTick_4D2580_server_C() bool {
	legacy.Sub_4EDD70()
	s.sub_417160()
	legacy.Sub_4573B0()
	if noxflags.HasGamePlay(2) && !noxflags.HasGame(noxflags.GameFlag15|noxflags.GameFlag16) &&
		noxflags.HasGamePlay(4) && !noxflags.HasGame(noxflags.GameModeChat) {
		legacy.Sub_4181F0(1)
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && false && !noxflags.HasGame(noxflags.GameModeChat) {
		legacy.Sub_4264D0()
	}
	noxflags.SetGame(noxflags.GameFlag28)
	noxAudioServeT(500)
	err := s.nox_xxx_mapExitAndCheckNext_4D1860_server()
	noxAudioServe()
	noxflags.UnsetGame(noxflags.GameFlag28)
	mname := s.getServerMap()
	if err != nil {
		gameLog.Println(err)
		format := s.Strings().GetStringInFile("MapAccessError", "C:\\NoxPost\\src\\Server\\System\\server.c")
		legacy.PrintToPlayers(fmt.Sprintf(format, mname))
		//v36 := strMan.GetStringInFile("Error", "C:\\NoxPost\\src\\Server\\System\\server.c")
		//v15 := strMan.GetStringInFile("MapCorrupt", "C:\\NoxPost\\src\\Server\\System\\server.c")
		nox_xxx_setContinueMenuOrHost_43DDD0(0)
		return false
	}
	crc := nox_xxx_mapCrcGetMB_409B00()
	nox_xxx_netUseMap_4DEE00(mname+".map", crc)
	if false {
		legacy.Sub_416690()
		if noxflags.HasGame(noxflags.GameModeChat) {
			if noxflags.HasGame(noxflags.GameFlag16) {
				s.TeamsZzz(1)
			}
			noxflags.UnsetGame(noxflags.GameFlag15 | noxflags.GameFlag16)
		} else {
			legacy.Sub_426060()
			legacy.Sub_41D6C0()
			inputSetKeyTimeoutLegacy(15)
		}
	}
	legacy.Nox_xxx_guiServerOptionsHide_4597E0(0)
	return true
}

func nox_game_guiInit_473680() error {
	*memmap.PtrPtr(0x5D4594, 1096420) = unsafe.Pointer(nox_xxx_gLoadImg("CursorBitmap").C())
	if legacy.Sub_455C30() == 0 {
		return errors.New("sub_455C30 failed")
	}
	if legacy.Sub_456070() == 0 {
		return errors.New("sub_456070 failed")
	}
	if noxClient.initGuiFPS() == 0 {
		return errors.New("sub_470710 failed")
	}
	if legacy.Nox_xxx_guiHealthManaInit_4714E0() == 0 {
		return errors.New("nox_xxx_guiHealthManaInit_4714E0 failed")
	}
	if legacy.Nox_xxx_bookInit_45B9D0() == 0 {
		return errors.New("nox_xxx_bookInit_45B9D0 failed")
	}
	if legacy.Sub_476E20() == nil {
		return errors.New("sub_476E20 failed")
	}
	if legacy.Sub_4BFAD0() == 0 {
		return errors.New("sub_4BFAD0 failed")
	}
	tmp := legacy.Nox_xxx_wndCreateInventoryMB_465E00()
	*memmap.PtrUint32(0x5D4594, 1096328) = tmp
	if tmp == 0 {
		return errors.New("nox_xxx_wndCreateInventoryMB_465E00 failed")
	}
	if legacy.Nox_game_initOptionsInGame_4ADAD0() == 0 {
		return errors.New("nox_game_initOptionsInGame_4ADAD0 failed")
	}
	if legacy.Sub_48D000() == 0 {
		return errors.New("sub_48D000 failed")
	}
	if legacy.Sub_4C3760() == 0 {
		return errors.New("sub_4C3760 failed")
	}
	if nox_savegame_sub_46C730() == 0 {
		return errors.New("nox_savegame_sub_46C730 failed")
	}
	if legacy.Sub_4C09D0() == 0 {
		return errors.New("sub_4C09D0 failed")
	}
	if legacy.Sub_478110() == 0 {
		return errors.New("sub_478110 failed")
	}
	if legacy.Sub_49B3E0() == 0 {
		return errors.New("sub_49B3E0 failed")
	}
	if legacy.Sub_4BFC90() == 0 {
		return errors.New("sub_4BFC90 failed")
	}
	if legacy.Nox_gui_itemAmount_init_4BFEF0() == 0 {
		return errors.New("nox_gui_itemAmount_init_4BFEF0 failed")
	}
	if legacy.Sub_4799A0() == 0 {
		return errors.New("sub_4799A0 failed")
	}
	if legacy.Nox_xxx_cliPrepareGameplay1_460E60() == 0 {
		return errors.New("nox_xxx_cliPrepareGameplay1_460E60 failed")
	}
	vsz := videoGetWindowSize()
	*memmap.PtrPtr(0x5D4594, 1096352) = unsafe.Pointer(guiCon.Init(vsz).C())
	if memmap.Uint32(0x5D4594, 1096352) == 0 {
		return errors.New("nox_gui_console_Create_450C70 failed")
	}
	if legacy.Sub_46A730() == nil {
		return errors.New("sub_46A730 failed")
	}
	if legacy.Sub_44E560() == nil {
		return errors.New("sub_44E560 failed")
	}
	if legacy.Sub_4C3500() == 0 {
		return errors.New("sub_4C3500 failed")
	}
	tmp = legacy.Nox_xxx_guiDrawRank_46E870()
	*memmap.PtrUint32(0x5D4594, 1096340) = tmp
	if tmp == 0 {
		return errors.New("nox_xxx_guiDrawRank_46E870 failed")
	}
	tmp = legacy.Nox_xxx_guiMotdLoad_4465C0()
	*memmap.PtrUint32(0x5D4594, 1096324) = tmp
	if tmp == 0 {
		return errors.New("nox_xxx_guiMotdLoad_4465C0 failed")
	}
	if legacy.Nox_xxx_guiSummonCreatureLoad_4C1D80() == 0 {
		return errors.New("nox_xxx_guiSummonCreatureLoad_4C1D80 failed")
	}
	if nox_xxx_wndLoadQuitMenu_445790() == 0 {
		return errors.New("nox_xxx_wndLoadQuitMenu_445790 failed")
	}
	if legacy.Sub_4AB260() == 0 {
		return errors.New("sub_4AB260 failed")
	}
	if legacy.Nox_xxx_guiChatIconLoad_445650() == 0 {
		return errors.New("nox_xxx_guiChatIconLoad_445650 failed")
	}
	if legacy.Sub_4C3390() == 0 {
		return errors.New("sub_4C3390 failed")
	}
	if legacy.Sub_48C980() == 0 {
		return errors.New("sub_48C980 failed")
	}
	guiCon.Enable(true)
	legacy.Sub_4AB4A0(0)
	legacy.Sub_4AB4D0(0)
	if !nox_client_renderGUI_80828 || noxflags.HasEngine(noxflags.EngineNoRendering) {
		legacy.Sub_4721A0(0)
		legacy.Sub_460EA0(0)
		legacy.Nox_window_set_visible_unk5(0)
		legacy.Sub_45D500(0)
		legacy.Sub_455A00(0)
		legacy.Sub_455F10(0)
	}
	return nil
}

func (s *Server) nox_xxx_mapFindPlayerStart_4F7AB0(a2 *Unit) types.Pointf {
	return legacy.Nox_xxx_mapFindPlayerStart_4F7AB0(a2.SObj())
}

func (s *Server) nox_xxx_mapExitAndCheckNext_4D1860_server() error {
	if noxflags.HasGame(noxflags.GameClient) {
		noxClient.Nox_client_setCursorType(gui.CursorBusy)
	}
	legacy.Sub_4D22B0()
	s.nox_xxx_netMsgFadeBegin_4D9800(false, true)
	s.scriptOnEvent("MapExit")
	v2 := s.getServerMap()
	legacy.Sub_500510(v2)
	legacy.Nox_xxx_mapSwitchLevel_4D12E0(1)
	for _, obj := range s.GetObjects() {
		obj.ObjFlags |= uint32(object.FlagMarked)
	}
	for _, obj := range s.GetObjectsUpdatable2() {
		obj.ObjFlags |= uint32(object.FlagMarked)
	}
	if noxflags.HasGame(noxflags.GameModeCoop) {
		s.spellEnableAll()
		s.Sub4537F0()
	}
	var merr error
	if nox_xxx_gameIsSwitchToSolo_4DB240() {
		v5 := nox_xxx_mapFilenameGetSolo_4DB260()
		merr = s.nox_server_loadMapFile_4CF5F0(v5, false)
	} else {
		v7p := legacy.Sub_4165B0()
		v7 := unsafe.Slice((*byte)(v7p), 58)
		if noxflags.HasGame(noxflags.GameOnline) {
			if v7[57] == 0 {
				v63, freeV63 := alloc.Make([]byte{}, 60)
				defer freeV63()
				copy(v63, alloc.GoStringS(v7))
				v59 := *(*uint16)(unsafe.Pointer(&v7[52]))
				v8 := legacy.Sub_459870()
				legacy.Sub_57A1E0(unsafe.Pointer(&v63[0]), "user.rul", v8, 3, noxflags.GameFlag(v59))
				v9 := legacy.Sub_459870()
				legacy.Sub_57AAA0("user.rul", (*byte)(v7p), v9)
			}
			s.spellEnableAll()
			s.Sub4537F0()
		}
		v10 := s.nox_server_currentMapGetFilename_409B30()
		merr = s.nox_server_loadMapFile_4CF5F0(v10, false)
		if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeChat) {
			v13 := 0
			if legacy.Nox_xxx_gamePlayIsAnyPlayers_40A8A0() != 0 {
				v12 := noxflags.GetGame()
				if legacy.Sub_40A180(v12) != 0 {
					v13 = 1
				}
			}
			legacy.Sub_40A1F0(v13)
			legacy.Sub_40A250()
			v60 := noxflags.GetGame()
			v58 := legacy.Sub_459870()
			v14 := nox_xxx_cliGamedataGet_416590(0)
			legacy.Sub_57A1E0(unsafe.Pointer(&v14[0]), "user.rul", v58, 3, v60)
			legacy.Sub_4D2230()
		}
	}
	if merr != nil {
		*memmap.PtrUint32(0x5D4594, 1548520) = 1
		return merr
	}
	if !noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Nox_xxx_netMapSendPrepair_519EB0_net_mapsend()
	}
	s.ObjectsNewAdd()
	for _, k := range s.getPlayerUnits() {
		legacy.Sub_4EF660(k.SObj())
		v61 := s.nox_xxx_mapFindPlayerStart_4F7AB0(k)
		if noxflags.HasGame(noxflags.GameModeChat) && s.TeamCount() != 0 {
			if !noxflags.HasGamePlay(2) && !noxflags.HasGame(noxflags.GameFlag16) {
				if t := k.Team(); t != nil {
					v61 = s.randomReachablePointAround(50.0, legacy.AsPointf(unsafe.Add(t.Field_72, 56)))
				}
			}
		}
		k.SetPos(v61)
		if !noxflags.HasGame(noxflags.GameModeSolo10) {
			plx := k.ControllingPlayer()
			plx.Lessons = 0
			plx.Field2140 = 0
			plx.Field2144 = s.Frame()
			nox_xxx_netReportLesson_4D8EF0(k)
		}
	}
	legacy.Sub_50AFA0()
	legacy.Sub_50B520()
	*memmap.PtrUint32(0x5D4594, 1548528) = 0
	legacy.Set_dword_5d4594_1548532(nil)
	if memmap.Uint32(0x5D4594, 1548708) == 0 {
		*memmap.PtrUint32(0x5D4594, 1548708) = uint32(s.ObjectTypeByID("PlayerStart").Ind())
	}
	if memmap.Uint32(0x5D4594, 1548712) == 0 {
		*memmap.PtrUint32(0x5D4594, 1548712) = uint32(s.ObjectTypeByID("GameBallStart").Ind())
	}
	var starts struct {
		playerN int
		flagN   int
		ballN   int
	}
	for _, v22 := range s.GetObjects() {
		if v22.Class().Has(0x10000000) {
			v22.Field34 = 0
			legacy.Set_dword_5d4594_1548532(v22.SObj().CObj())
			starts.flagN++
		}
		ti := uint32(v22.TypeInd)
		if ti == memmap.Uint32(0x5D4594, 1548712) {
			starts.ballN++
		}
		if ti == memmap.Uint32(0x5D4594, 1548708) {
			starts.playerN++
		}
	}
	if starts.playerN == 0 {
		v24 := s.Strings().GetStringInFile("StartingPositionError", "C:\\NoxPost\\src\\Server\\System\\server.c")
		legacy.PrintToPlayers(v24)
		return errors.New("cannot find player starting position")
	}
	if noxflags.HasGame(noxflags.GameModeCTF|noxflags.GameModeFlagBall) && starts.flagN < 2 {
		v24 := s.Strings().GetStringInFile("FlagCountError", "C:\\NoxPost\\src\\Server\\System\\server.c")
		legacy.PrintToPlayers(v24)
		return errors.New("invalid flag starting position(s)")
	}
	if noxflags.HasGame(noxflags.GameModeFlagBall) && starts.ballN < 1 {
		v24 := s.Strings().GetStringInFile("BallStartCountError", "C:\\NoxPost\\src\\Server\\System\\server.c")
		legacy.PrintToPlayers(v24)
		return errors.New("invalid ball starting position(s)")
	}

	if noxflags.HasGamePlay(4) || noxflags.HasGame(noxflags.GameFlag16) {
		s.Teams.ResetYyy()
	}
	s.Map.Debug.Each([]string{"spring", "SentryGlobe"}, func(key, val string) {
		switch key {
		case "spring":
			val = strings.TrimSpace(val)
			if sub := strings.Fields(val); len(sub) >= 2 {
				ind1, _ := strconv.Atoi(sub[0])
				obj1 := s.GetObjectByInd(ind1)
				ind2, _ := strconv.Atoi(sub[1])
				obj2 := s.GetObjectByInd(ind2)
				if obj1 != nil && obj2 != nil {
					s.springs.Add(obj1, obj2)
				}
			}
		case "SentryGlobe":
			val = strings.TrimSpace(val)
			if sub := strings.Fields(val); len(sub) >= 3 {
				v34, _ := strconv.Atoi(sub[0])
				if v35 := s.GetObjectByInd(v34).AsUnit(); v35 != nil {
					v36 := unsafe.Slice((*float32)(v35.UpdateData), 3)
					v38, _ := strconv.ParseFloat(sub[1], 64)
					v36[0] = float32(v38 * memmap.Float64(0x581450, 10008))
					v36[1] = v36[0]
					v40, _ := strconv.ParseFloat(sub[2], 64)
					v36[2] = float32(v40 * memmap.Float64(0x581450, 10000) / float64(s.TickRate()))
				}
			}
		}
	})
	legacy.Set_dword_5d4594_1548524(0)
	v41 := s.getServerMap()
	legacy.Sub_500510(v41)
	if !nox_xxx_gameIsSwitchToSolo_4DB240() {
		legacy.Nox_xxx_resetMapInit_4FC570(1)
	}
	noxflags.SetGame(noxflags.GameFlag28)
	noxAudioServeT(500)
	v42 := nox_xxx_gameIsSwitchToSolo_4DB240()
	legacy.Sub_4DBA30(v42)
	noxAudioServe()
	noxflags.UnsetGame(noxflags.GameFlag28)
	legacy.Sub_4FC580(1)
	if s.mapSwitchWPName != "" {
		if wp := s.getWaypointByID(s.mapSwitchWPName); wp != nil {
			gameLog.Printf("moving player to waypoint: %q", s.mapSwitchWPName)
			wpos := wp.Pos()
			for _, u := range s.getPlayerUnits() {
				u.SetPos(wpos)
			}
		} else {
			gameLog.Printf("cannot find map waypoint %q!", s.mapSwitchWPName)
		}
	}
	s.mapSwitchWPName = ""
	if sub_4DCC00() {
		for _, m := range s.getPlayerUnits() {
			for _, np := range m.GetOwned516() {
				var np *Object = np
				if legacy.Nox_xxx_isUnit_4E5B50(np.SObj()) != 0 {
					n := np.AsUnit()
					ud := n.UpdateDataMonster()
					v61 := s.randomReachablePointAround(50.0, m.Pos())
					n.SetPos(v61)
					ud.Field97 = 0
					n.clearActionStack()
					n.Obj130 = nil
					ud.CurrentEnemy = nil
					ud.Field304 = 0
					*(*byte)(unsafe.Add(unsafe.Pointer(ud), 1129)) = 0
					ud.Field0 = 0xDEADFACE
					p := m.Pos()
					n.monsterPushAction(ai.ACTION_ESCORT, p.X, p.Y, m)
					if n.Class().Has(2) && n.SubClass()&0x30 != 0 {
						legacy.Nox_xxx_setNPCColor_4E4A90(n.SObj(), 0, ud.Field519)
					}
				} else if m.Class().Has(1) && legacy.Sub_4E5B80(m.SObj()) != 0 {
					legacy.Sub_4E81D0(m.SObj())
				}
			}
		}
		sub_4DCBF0(0)
	}
	_ = object.FlagMarked
	for _, obj := range s.GetObjects() {
		obj.ObjFlags &= 0x7FFFFFFF
	}
	for _, obj := range s.GetObjectsUpdatable2() {
		obj.ObjFlags &= 0x7FFFFFFF
	}
	if noxflags.HasGame(noxflags.GameModeKOTR) && noxflags.HasGamePlay(4) {
		legacy.Sub_4D2160()
	}
	if noxflags.HasGame(noxflags.GameModeQuest) {
		s.nox_server_questMapNextLevel()
	}
	if noxflags.HasGame(noxflags.GameModeCoop) && legacy.Nox_xxx_mapLoadRequired_4DCC80() == 0 {
		sub_4DB130(common.SaveAuto)
		sub_4DB170(1, nil, 30)
	}
	legacy.Nox_xxx_mapLoadOrSaveMB_4DCC70(0)
	if noxflags.HasGame(noxflags.GameModeCoop) {
		sub_413980(30)
	}
	if noxflags.HasGame(noxflags.GameModeQuest) {
		legacy.Sub_4D7140(s.Frame() + s.TickRate())
	} else {
		legacy.Sub_4D7140(0)
	}
	nox_ticks_reset_416D40()
	legacy.Sub_40A970()
	s.flag1548704 = false
	if noxflags.HasGame(noxflags.GameModeQuest) {
		legacy.Sub_4D71E0(0)
		if legacy.Sub_4D72C0() == 1 {
			legacy.Sub_4D72B0(0)
			v57 := legacy.Sub_4D72C0()
			legacy.Sub_4D7280(255, int8(v57))
		}
	}
	return nil
}

func sub_4DCC00() bool {
	return dword_5d4594_1563064
}

func sub_413980(a1 int) {
	if a1 != 0 {
		sub_413A00(1)
		legacy.Set_dword_5d4594_251744(a1 + int(noxClient.GetInputSeq()))
	} else {
		legacy.Set_dword_5d4594_251744(0)
	}
}

func sub_4139C0() {
	if legacy.Get_dword_5d4594_251744() != 0 {
		if int(noxClient.GetInputSeq()) >= int(legacy.Get_dword_5d4594_251744()) {
			legacy.Set_dword_5d4594_251744(0)
			if !sub_450560() {
				sub_413A00(0)
			}
		}
	}
}

func (s *Server) sub_417160() {
	for _, it := range s.GetPlayers() {
		legacy.Nox_xxx_playerUnsetStatus_417530(it.S(), 16)
	}
}

func (s *Server) randomReachablePointAround(a1 float32, pos types.Pointf) types.Pointf { // sub_4ED970
	v9 := a1 * 0.015625
	v11 := float32(noxRndCounter1.FloatClamp(-math.Pi, math.Pi))
	for v5 := 0; v5 < 64; v5++ {
		v6 := v11 + 1.8849558
		v11 = v6
		p2 := types.Pointf{
			X: float32(math.Cos(float64(v6)))*a1 + pos.X,
			Y: float32(math.Sin(float64(v11)))*a1 + pos.Y,
		}
		if s.MapTraceRay(pos, p2, server.MapTraceFlag1) {
			return p2
		}
		a1 = a1 - v9
	}
	return pos
}

func (s *Server) MapTraceRay9(p1, p2 types.Pointf) bool { // nox_xxx_traceRay_5374B0
	return s.MapTraceRay(p1, p2, server.MapTraceFlag1|server.MapTraceFlag4)
}

func (s *Server) MapTraceRay(p1, p2 types.Pointf, flags server.MapTraceFlags) bool {
	return s.MapTraceRayAt(p1, p2, nil, nil, flags)
}

func (s *Server) MapTraceRayAt(p1, p2 types.Pointf, outPos *types.Pointf, outGrid *image.Point, flags server.MapTraceFlags) bool {
	wx1 := int(p1.X / common.GridStep)
	wy1 := int(p1.Y / common.GridStep)
	if wx1 < 0 || wx1 >= 256 || wy1 < 0 || wy1 >= 256 {
		return false
	}
	wx2 := int(p2.X / common.GridStep)
	wy2 := int(p2.Y / common.GridStep)
	if wx1 == wx2 {
		step := +1
		if p2.Y < p1.Y {
			step = -1
		}
		if wy1 == wy2+step {
			return true
		}
		for yi := wy1; yi != wy2+step; yi += step {
			pi := image.Pt(wx1, yi)
			if a4a := s.mapTraceRayImpl(pi, p1, p2, flags); len(a4a) != 0 {
				if outPos != nil {
					*outPos = a4a[0]
				}
				if outGrid != nil {
					*outGrid = pi
				}
				return false
			}
		}
		return true
	}
	if wy1 == wy2 {
		step := +1
		if p2.X < p1.X {
			step = -1
		}
		if wx1 == wx2+step {
			return true
		}
		for xi := wx1; xi != wx2+step; xi += step {
			pi := image.Pt(xi, wy1)
			if a4a := s.mapTraceRayImpl(pi, p1, p2, flags); len(a4a) != 0 {
				if outPos != nil {
					*outPos = a4a[0]
				}
				if outGrid != nil {
					*outGrid = pi
				}
				return false
			}
		}
		return true
	}
	dx := p2.X - p1.X
	dy := p2.Y - p1.Y
	if math.Abs(float64(dy)) >= math.Abs(float64(dx)) {
		x1 := p1.X
		x2 := p2.X
		mulX := float32(+1.0)
		if x1 >= x2 {
			x1, x2 = x2, x1
			mulX = -1.0
		}
		stepY := +1.0
		if p1.Y >= p2.Y {
			stepY = -1.0
		}
		slope := dy / dx
		var xnext float32
		for x := p1.X; mulX*x <= mulX*p2.X; x = xnext + 0.1*mulX {
			xi := int(math.Trunc(float64(x / common.GridStep)))
			xmin := float32(xi+0) * common.GridStep
			xmax := float32(xi+1) * common.GridStep
			if mulX <= 0 {
				xmax, xmin = xmin, xmax
			}
			xnext = xmax
			y1 := p1.Y + (xmin-p1.X)*slope
			if (stepY > 0 && y1 < p1.Y) || (stepY < 0 && y1 > p1.Y) {
				y1 = p1.Y
			}
			y2 := p1.Y + (xmax-p1.X)*slope
			if (stepY > 0 && y2 > p2.Y) || (stepY < 0 && y2 < p2.Y) {
				y2 = p2.Y
			}
			yi1 := int(math.Trunc(float64(y1/common.GridStep)) - stepY)
			yi2 := int(math.Trunc(float64(y2/common.GridStep)) + stepY)
			ddy := 1
			if yi1 >= yi2 {
				ddy = -1
			}
			for yi := yi1; yi != yi2+ddy; yi += ddy {
				pi := image.Pt(xi, yi)
				if a4a := s.mapTraceRayImpl(pi, p1, p2, flags); len(a4a) != 0 {
					if outPos != nil {
						*outPos = a4a[0]
					}
					if outGrid != nil {
						*outGrid = pi
					}
					return false
				}
			}
		}
		return true
	} else {
		y1 := p1.Y
		y2 := p2.Y
		mulY := float32(+1.0)
		if p1.Y >= p2.Y {
			y1, y2 = y2, y1
			mulY = -1.0
		}
		stepX := +1.0
		if p1.X >= p2.X {
			stepX = -1.0
		}
		slope := dx / dy
		var ynext float32
		for y := p1.Y; mulY*y <= mulY*p2.Y; y = ynext + 0.1*mulY {
			yi := int(math.Trunc(float64(y / common.GridStep)))
			ymin := float32(yi+0) * common.GridStep
			ymax := float32(yi+1) * common.GridStep
			if mulY <= 0 {
				ymin, ymax = ymax, ymin
			}
			ynext = ymax
			x1 := p1.X + (ymin-p1.Y)*slope
			if (stepX > 0 && x1 < p1.X) || (stepX < 0 && x1 > p1.X) {
				x1 = p1.X
			}
			x2 := p1.X + (ymax-p1.Y)*slope
			if (stepX > 0 && x2 > p2.X) || (stepX < 0 && x2 < p2.X) {
				x2 = p2.X
			}
			xi1 := int(math.Trunc(float64(x1/common.GridStep)) - stepX)
			xi2 := int(math.Trunc(float64(x2/common.GridStep)) + stepX)
			ddy := 1
			if xi1 >= xi2 {
				ddy = -1
			}
			for xi := xi1; xi != xi2+ddy; xi += ddy {
				pi := image.Pt(xi, yi)
				if out := s.mapTraceRayImpl(pi, p1, p2, flags); len(out) != 0 {
					if outPos != nil {
						*outPos = out[0]
					}
					if outGrid != nil {
						*outGrid = pi
					}
					return false
				}
			}
		}
		return true
	}
}

var noxMapTable313272 = []struct {
	Field0 byte
	Field4 float32
	Field8 float32
}{
	{Field0: 0, Field4: 0, Field8: 0},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 0, Field4: 0, Field8: 0},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 11.5},
}

func (s *Server) mapTraceRayImpl(pi image.Point, p1, p2 types.Pointf, flags server.MapTraceFlags) []types.Pointf {
	if pi.X < 0 || pi.X >= 256 || pi.Y < 0 || pi.Y >= 256 {
		return nil
	}
	if flags.Has(server.MapTraceFlag4) {
		v7 := float32(pi.X)*common.GridStep + 11.5 - p1.X
		v8 := float32(pi.Y)*common.GridStep + 11.5 - p1.Y
		if v8*v8+v7*v7 < 3600.0 {
			flags |= server.MapTraceFlag3
		}
	}
	v30 := byte(^flags&server.MapTraceFlag3) << 4
	if flags.Has(server.MapTraceFlag1) {
		v30 |= 0x10
	}
	tflag := legacy.Sub_57B500(pi.X, pi.Y, v30)
	if tflag == -1 {
		return nil
	}
	var wl *Wall
	if flags.Has(server.MapTraceFlag1) {
		wl = s.getWallAtGrid2(pi)
	} else {
		wl = s.getWallAtGrid(pi)
	}
	if wl == nil || flags.Has(server.MapTraceFlag8) && wl.field4()&0x4 != 0 && *(*byte)(unsafe.Add(wl.field28(), 20))&0x2 != 0 {
		return nil
	}
	flags2 := *memmap.PtrUint32(0x85B3FC, 43076+12332*uintptr(wl.tile()))
	if flags2&0x2 != 0 || flags.Has(server.MapTraceFlag7) && flags2&0x1 == 0 {
		return nil
	}
	x1 := p1.X
	x2 := p2.X
	if p1.X >= p2.X {
		x1, x2 = x2, x1
	}
	y1 := p1.Y
	y2 := p2.Y
	if p1.Y >= p2.Y {
		y1, y2 = y2, y1
	}
	a2a := types.Pointf{
		X: float32(common.GridStep * pi.X),
		Y: float32(common.GridStep * pi.Y),
	}
	var left types.Pointf
	if tflag != 0 {
		left = sub_57CD30(p1, p2, a2a)
	}
	var right types.Pointf
	if tflag != 1 {
		right = sub_57CD70(p1, p2, a2a.Add(types.Pointf{X: common.GridStep}))
	}
	var out []types.Pointf
	if t := noxMapTable313272[2*int(tflag)+0]; t.Field0 != 0 &&
		a2a.X+t.Field4 <= left.X &&
		a2a.X+t.Field8 >= left.X &&
		left.X >= x1 && left.X <= x2 &&
		left.Y >= y1 && left.Y <= y2 {
		out = append(out, left)
	}
	if t := noxMapTable313272[2*int(tflag)+1]; t.Field0 != 0 &&
		a2a.X+t.Field4 <= right.X &&
		a2a.X+t.Field8 >= right.X &&
		right.X >= x1 && right.X <= x2 &&
		right.Y >= y1 && right.Y <= y2 {
		out = append(out, right)
	}
	if len(out) == 2 {
		dxl := p1.X - left.X
		dxr := p1.X - right.X
		dyl := p1.Y - left.Y
		dyr := p1.Y - right.Y
		if dyr*dyr+dxr*dxr < dyl*dyl+dxl*dxl {
			out[0], out[1] = out[1], out[0]
		}
	}
	return out
}

func sub_57CD30(p1, p2, c types.Pointf) types.Pointf {
	dx := p2.X - p1.X
	dy := p2.Y - p1.Y
	v := ((c.Y-p1.Y)*dx - (c.X-p1.X)*dy) / (dy - dx)
	return c.Add(types.Pointf{X: v, Y: v})
}

func sub_57CD70(p1, p2, a2 types.Pointf) types.Pointf {
	dx := p2.X - p1.X
	dy := p2.Y - p1.Y
	v := ((a2.Y-p1.Y)*dx - (a2.X-p1.X)*dy) / (-dy - dx)
	return a2.Add(types.Pointf{X: -v, Y: v})
}

func (s *Server) MapTraceObstacles(from *server.Object, p1, p2 types.Pointf) bool { // nox_xxx_mapTraceObstacles_50B580
	rect := types.RectFromPointsf(p1, p2)

	p, ppFree := alloc.New([4]float32{})
	defer ppFree()
	p[0], p[1] = p1.X, p1.Y
	p[2], p[3] = p2.X, p2.Y

	searching := true
	s.Map.EachObjInRect(rect, func(it *server.Object) {
		obj := asObjectS(it)
		if !searching {
			return
		}
		if from.SObj() == obj.SObj() {
			return
		}
		if obj.Class().HasAny(object.MaskUnits) {
			u2 := obj.AsUnit()
			if asUnitS(from).isEnemyTo(u2) {
				return
			}
		} else if !obj.Class().HasAny(object.ClassImmobile | object.ClassObstacle) {
			return
		}
		if obj.Flags().HasAny(object.FlagNoCollide|object.FlagAllowOverlap) || obj.Class().Has(object.ClassDoor) {
			return
		}
		pos := obj.Pos()
		sh := &obj.Shape
		switch sh.Kind {
		case server.ShapeKindCircle:
			a3p, a3Free := alloc.New(types.Pointf{})
			defer a3Free()
			if legacy.Nox_xxx_mathPointOnTheLine_57C8A0(p, &obj.PosVec, a3p) != 0 {
				dx := a3p.X - pos.X
				dy := a3p.Y - pos.Y
				if dy*dy+dx*dx <= sh.Circle.R2 {
					searching = false
				}
			}
		case server.ShapeKindBox:
			a2, a2Free := alloc.New([4]float32{})
			defer a2Free()

			v12 := sh.Box.LeftTop + pos.X
			v5 := sh.Box.LeftBottom + pos.Y
			a2[0] = v12
			v13 := v5
			v6 := sh.Box.LeftBottom2 + pos.X
			a2[1] = v13
			v9 := v6
			v7 := sh.Box.LeftTop2 + pos.Y
			a2[2] = v9
			v10 := v7
			v8 := sh.Box.RightTop + pos.X
			a2[3] = v10
			v11 := sh.Box.RightBottom + pos.Y
			xx := sh.Box.RightBottom2 + pos.X
			yy := sh.Box.RightTop2 + pos.Y
			if legacy.Sub_427980(p, a2) != 0 {
				searching = false
				return
			}
			a2[0] = v12
			a2[1] = v13
			a2[2] = v8
			a2[3] = v11
			if legacy.Sub_427980(p, a2) != 0 {
				searching = false
				return
			}
			a2[0] = xx
			a2[1] = yy
			a2[2] = v8
			a2[3] = v11
			if legacy.Sub_427980(p, a2) != 0 {
				searching = false
				return
			}
			a2[0] = xx
			a2[1] = yy
			a2[2] = v9
			a2[3] = v10
			if legacy.Sub_427980(p, a2) != 0 {
				searching = false
			}
		}
	})
	return searching
}

func (s *Server) Sub_518460(pos types.Pointf, mask byte, scanSub bool) *server.Waypoint {
	s.dword_5d4594_2386960++
	s.dword_5d4594_2386928 = 1000.0
	var found *Waypoint
	for r := float32(0.0); r < 1000.0; {
		x1 := server.RoundCoord(pos.X - r)
		y1 := server.RoundCoord(pos.Y - r)
		x2 := server.RoundCoord(pos.X + r)
		y2 := server.RoundCoord(pos.Y + r)
		s.dword_5d4594_2386948 = nil
		s.sub_518550(image.Rect(x1, y1, x2, y2), pos, mask, scanSub)
		if s.dword_5d4594_2386948 != nil {
			found = s.dword_5d4594_2386948
			r = s.dword_5d4594_2386928
		} else {
			if found != nil {
				return found.S()
			}
			r += 85.0
		}
	}
	return found.S()
}

func (s *Server) sub_518550(rect image.Rectangle, pos types.Pointf, mask byte, scanSub bool) {
	s.Map.Sub518550Base(rect, mask, scanSub, &s.dword_5d4594_2386960, func(it *server.Waypoint) {
		if dist := pos.Sub(it.Pos()).Len(); dist < float64(s.dword_5d4594_2386928) {
			if s.MapTraceRayAt(pos, it.Pos(), nil, nil, server.MapTraceFlag1) {
				s.dword_5d4594_2386948 = asWaypointS(it)
				s.dword_5d4594_2386928 = float32(dist)
			}
		}
	})
}

func nox_xxx_calcDistance_4E6C00(obj1, obj2 server.Obj) float32 {
	return legacy.Nox_xxx_calcDistance_4E6C00(toObjectS(obj1), toObjectS(obj2))
}

func nox_xxx_unitCanInteractWith_5370E0(u, obj server.Obj, a3 byte) bool {
	return legacy.Nox_xxx_unitCanInteractWith_5370E0(toObjectS(u), toObjectS(obj), a3)
}

var doDamageWalls = true

func nox_xxx_gameSetWallsDamage_4E25A0(v int) {
	doDamageWalls = v != 0
}

func (s *Server) Nox_xxx_mapDamageUnitsAround(pos types.Pointf, r1, r2 float32, dmg int, dtyp object.DamageType, who *server.Object, a7 server.Obj, damageWalls bool) {
	rr := r1
	if r1 < r2 {
		rr = r2
	}
	rect := types.Rectf{
		Left:   pos.X - rr,
		Top:    pos.Y - rr,
		Right:  pos.X + rr,
		Bottom: pos.Y + rr,
	}
	s.Map.EachObjInRect(rect, func(it *server.Object) {
		u := asUnitS(it)
		if u.SObj() == who.SObj() && !damageWalls {
			return
		}
		if u.SObj() == toObjectS(a7).SObj() {
			return
		}
		pos2 := u.Pos()
		dx := pos2.X - pos.X
		dy := pos2.Y - pos.Y
		dist := float32(math.Sqrt(float64(dy*dy + dx*dx)))
		if dist > rr {
			return
		}
		if !s.MapTraceRay(pos, pos2, server.MapTraceFlag1) {
			return
		}
		rdmg := float32(dmg)
		if dist >= r2 {
			rdmg *= 1.0 - (dist-r2)/(rr-r2)
		}
		u.CallDamage(who, nil, int(rdmg), dtyp)
	})
	wrect := image.Rect(
		int(rect.Left)/common.GridStep,
		int(rect.Top)/common.GridStep,
		int(rect.Right)/common.GridStep,
		int(rect.Bottom)/common.GridStep,
	)
	s.nox_xxx_mapDamageToWalls_534FC0(wrect, pos, r1, dmg, dtyp, asUnitS(who))
	doDamageWalls = true
}

func (s *Server) nox_xxx_mapDamageToWalls_534FC0(rect image.Rectangle, pos types.Pointf, rad float32, dmg int, dtyp object.DamageType, who *Unit) {
	legacy.Nox_xxx_mapDamageToWalls_534FC0(rect, pos, rad, dmg, dtyp, who.SObj())
}

func sub_473840() {
	guiCon.Enable(false)
	legacy.Nox_gui_itemAmount_free_4C03E0()
	sub_46CCB0()
	legacy.Sub_4AE3B0()
	legacy.Sub_48D450()
	legacy.Sub_4C4220()
	legacy.Nox_xxx_closeP2PTradeWnd_4C12A0()
	legacy.Sub_4BFD10()
	legacy.Sub_49B490()
	legacy.Sub_478F80()
	legacy.Sub_479D10()
	legacy.Sub_4AB470()
	legacy.Sub_4C34A0()
	legacy.Sub_445770()
	legacy.Sub_456240()
	legacy.Sub_455EE0()
	sub_460E90()
	legacy.Sub_4505E0()
	legacy.Sub_46A860()
	legacy.Sub_49C7A0()
	legacy.Nox_xxx_guiServerOptionsHide_4597E0(1)
	legacy.Sub_467980()
	noxClient.GUI.DestroyAll()
	nox_client_renderGUI_80828 = nox_xxx_xxxRenderGUI_587000_80832
}

func sub_460E90() {
	if legacy.Sub_460D40() {
		legacy.Sub_460D50()
	}
}

func (s *Server) nox_xxx_netlist_4DEB50() {
	if !noxflags.HasGame(noxflags.GameClient) {
		return
	}
	if noxflags.HasEngine(noxflags.EngineReplayRead) {
		s.nox_xxx_replayTickMB_4D3580_net_playback(false)
		netlist.ResetByInd(common.MaxPlayers-1, netlist.Kind0)
	} else if !isDedicatedServer {
		netlist.HandlePacketsA(common.MaxPlayers-1, netlist.Kind0, func(data []byte) {
			if len(data) == 0 {
				return
			}
			s.onPacketRaw(common.MaxPlayers-1, data)
		})
	}
}

func (c *Client) nox_game_checkStateSwitch_43C1E0() {
	if c.GameGetStateCode() < 0 {
		return
	}
	p := gui.FindAnimForStateID(c.GameGetStateCode())
	if p != nil {
		p.Func12()
		p.Func13Ptr = legacy.Get_nox_game_switchStates_43C0A0()
		c.GamePopState()
	}
}

func (c *Client) nox_game_checkStateOptions_43C220() {
	if c.GameGetStateCode() < 0 {
		return
	}
	p := gui.FindAnimForStateID(c.GameGetStateCode())
	if p != nil {
		p.Func12()
		p.Func13Ptr = legacy.Get_nox_game_showOptions_4AA6B0()
	}
}

func (c *Client) nox_game_checkStateMenu_43C2F0() {
	if c.GameGetStateCode() < 0 {
		return
	}
	p := gui.FindAnimForStateID(c.GameGetStateCode())
	if p != nil {
		if c.GameGetStateCode() == client.StateMainMenu {
			nox_game_showMainMenu_4A1C00()
		} else {
			p.Func12()
			_ = nox_game_showMainMenu_4A1C00
			p.Func13Ptr = legacy.Get_nox_game_showMainMenu_4A1C00()
		}
	}
	c.GamePopStateUntil(client.StateMainMenu)
}

func nox_xxx_mapAlloc_4101D0() int {
	dword_5D4594_251544, _ = alloc.Make([]unsafe.Pointer{}, 32*256)
	if dword_5D4594_251544 == nil {
		return 0
	}
	legacy.Set_dword_5D4594_251544(unsafe.Pointer(&dword_5D4594_251544[0]))

	dword_5d4594_251556, _ = alloc.Make([]unsafe.Pointer{}, 256)
	if dword_5d4594_251556 == nil {
		return 0
	}
	legacy.Set_dword_5d4594_251556(unsafe.Pointer(&dword_5d4594_251556[0]))
	legacy.Set_dword_5d4594_251552(0)
	for v1 := 0; v1 < 32*256; v1++ {
		ptr, _ := alloc.Malloc(36)
		if ptr == nil {
			return 0
		}
		*(*unsafe.Pointer)(unsafe.Add(ptr, 20)) = legacy.Get_dword_5d4594_251548()
		legacy.Set_dword_5d4594_251548(ptr)
	}
	nox_xxx_wall_410160()
	return 1
}

func nox_xxx_wall_410160() {
	for i := 0; i < 32*256; i++ {
		ptr := dword_5D4594_251544[i]
		if ptr == nil {
			dword_5D4594_251544[i] = nil
			continue
		}

		var next unsafe.Pointer
		prev := legacy.Get_dword_5d4594_251548()
		for it := ptr; it != nil; it = next {
			next = *(*unsafe.Pointer)(unsafe.Add(it, 16))
			*(*unsafe.Pointer)(unsafe.Add(it, 20)) = prev
			legacy.Set_dword_5d4594_251548(it)
			prev = it
		}
		dword_5D4594_251544[i] = nil
	}
	legacy.Set_dword_5d4594_251552(0)
	for i := 0; i < 256; i++ {
		dword_5d4594_251556[i] = nil
	}
}
func (s *Server) Sub4537F0() {
	for i := 0; i < 26; i++ {
		if ind := legacy.Sub_415CD0(1 << i); ind != 0 {
			s.ObjectTypeByInd(ind).SetAllowed(true)
		}
	}
	for i := 0; i < 27; i++ {
		if ind := legacy.Sub_415840(1 << i); ind != 0 {
			s.ObjectTypeByInd(ind).SetAllowed(true)
		}
	}
}
