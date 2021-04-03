package main

/*
#include "proto.h"
#include "client__shell__noxworld.h"
#include "client__system__parsecmd.h"
#include "common__magic__comguide.h"
#include "client__drawable__drawdb.h"
extern unsigned int nox_game_createOrJoin_815048;
extern unsigned int nox_client_gui_flag_815132;
extern unsigned int nox_client_gui_flag_1556112;
extern unsigned int dword_5d4594_811372;
extern int nox_win_width;
extern int nox_win_height;
extern obj_5D4594_811068_t obj_5D4594_811068;

int nox_xxx_gameTick_4D2580_server();
int nox_xxx_mapExitAndCheckNext_4D1860_server();
*/
import "C"
import (
	"context"
	"log"
	"unsafe"

	"github.com/noxworld-dev/xwis"

	"nox/common/alloc"
	noxflags "nox/common/flags"
	"nox/common/memmap"
)

func nox_game_setMovieFile_4CB230(name string, out *C.char) bool {
	cname := C.CString(name)
	defer StrFree(cname)
	return C.nox_game_setMovieFile_4CB230(cname, out) != 0
}

//export nox_game_rollLogoAndStart_4AB1F0
func nox_game_rollLogoAndStart_4AB1F0() C.int {
	if isServer || isServerQuest {
		return C.int(startServer())
	}
	path := (*C.char)(alloc.Calloc(128, 1))
	defer alloc.Free(unsafe.Pointer(path))
	C.nox_game_decStateInd_43BDC0()
	if noxflags.HasGame(noxflags.GameFlag26) || !nox_game_setMovieFile_4CB230("WWLogo.vqa", path) {
		nox_game_rollIntroAndStart_4AB170()
		return 1
	}
	C.sub_4B0300(path)
	C.sub_4B0640((*[0]byte)(C.nox_game_rollIntroAndStart_4AB170))
	C.nox_client_drawGeneral_4B0340(0)
	return 1
}

//export nox_game_rollIntroAndStart_4AB170
func nox_game_rollIntroAndStart_4AB170() C.int {
	path := (*C.char)(alloc.Calloc(128, 1))
	defer alloc.Free(unsafe.Pointer(path))
	if C.sub_578DF0()&0x80 != 0 || noxflags.HasGame(noxflags.GameFlag26) || !nox_game_setMovieFile_4CB230("Intro.vqa", path) {
		nox_game_rollNoxLogoAndStart_4AB0F0()
		return 1
	}
	C.sub_4B0300(path)
	C.sub_4B0640((*[0]byte)(C.nox_game_rollNoxLogoAndStart_4AB0F0))
	C.nox_client_drawGeneral_4B0340(1)
	C.sub_578DE0(C.char(C.sub_578DF0() | 0x80))
	return 1
}

//export nox_game_rollNoxLogoAndStart_4AB0F0
func nox_game_rollNoxLogoAndStart_4AB0F0() C.int {
	path := (*C.char)(alloc.Calloc(128, 1))
	defer alloc.Free(unsafe.Pointer(path))
	if noxflags.HasGame(noxflags.GameFlag26) || !nox_game_setMovieFile_4CB230("NoxLogo.vqa", path) {
		if C.nox_game_showLegal_4CC4E0() == 0 {
			nox_xxx_setContinueMenuOrHost_43DDD0(0)
			C.nox_client_gui_flag_815132 = 0
		}
		return 1
	}
	C.sub_4B0300(path)
	C.sub_4B0640((*[0]byte)(C.nox_game_showLegal_4CC4E0))
	C.nox_client_drawGeneral_4B0340(0)
	return 1
}

func startServer() int {
	C.nox_game_createOrJoin_815048 = 1
	setEngineFlag(NOX_ENGINE_FLAG_5)
	resetEngineFlag(NOX_ENGINE_FLAG_6)
	noxflags.SetGame(noxflags.GameServerXxx)
	if !isServerQuest {
		noxflags.SetGame(noxflags.GameNotQuest)
	} else {
		noxflags.UnsetGame(noxflags.GameNotQuest)
	}
	noxflags.UnsetGame(noxflags.GameSolo)
	C.sub_461440(0)
	C.sub_4D6F40(0)
	C.sub_4D6F90(0)
	if !isServerQuest {
		C.sub_4D6F60(0)
	} else {
		C.sub_4D6F60(1)
		C.nox_xxx_cliShowHideTubes_470AA0(1)
	}
	C.sub_4D6F80(0)
	if C.sub_473670() == 0 {
		C.sub_473610()
	}
	if !isServerQuest {
		C.nox_xxx_cliShowHideTubes_470AA0(0)
	}
	C.nox_xxx_cliSetMinimapZoom_472520(2300)
	C.sub_43AF50(0)
	if C.nox_xxx_parseGamedataBinPre_4D1630() == 0 {
		nox_xxx_setContinueMenuOrHost_43DDD0(0)
		C.nox_client_gui_flag_815132 = 0
		return 0
	}
	nox_xxx_serverHost_43B4D0()
	ctx := context.Background()
	go xwisRegister(ctx)
	return 1
}

func xwisRegister(ctx context.Context) {
	cli, err := xwis.NewClient(ctx, "", "")
	if err != nil {
		log.Printf("failed to init xwis: %v", err)
		return
	}
	defer cli.Close()

	// TODO: actually update those values according to what server is doing
	err = cli.HostGame(ctx, xwis.GameInfo{
		Name:       "GNox Dedicated Server",
		Map:        "estate",
		MapType:    xwis.MapTypeChat,
		Resolution: xwis.Res1024x768,
		Players:    1,
		MaxPlayers: 32,
	})
	if err != nil {
		log.Printf("failed to host on xwis: %v", err)
		return
	}
}

//export nox_xxx_serverHost_43B4D0
func nox_xxx_serverHost_43B4D0() {
	if C.nox_game_createOrJoin_815048 != 0 {
		C.sub_43B510()
		C.sub_43A9D0()
		C.sub_4A24A0()
		C.nox_xxx_gameSetAudioFadeoutMb_501AC0(0)
	} else {
		C.sub_43B630()
		C.sub_43B440()
	}
	C.sub_49FF20()
}

func initGameSession435CC0() int {
	C.sub_445450()
	C.sub_45DB90()
	C.sub_41D1A0(0)
	C.nox_xxx_initTime_435570()
	C.nox_client_gui_flag_1556112 = 0

	if C.nox_alloc_drawable_init(5000) == 0 {
		return 0
	}

	if C.sub_49A8E0_init() == 0 {
		return 0
	}

	if C.nox_xxx_allocArrayHealthChanges_49A5F0() == 0 {
		return 0
	}

	if C.nox_xxx_parseThingBinClient_44C840_read_things() == nil {
		return 0
	}

	if C.nox_xxx_loadGuides_427070() == 0 {
		return 0
	}

	if C.sub_494F00() == 0 {
		return 0
	}

	if C.nox_game_guiInit_473680() == 0 {
		return 0
	}

	C.nox_alloc_npcs()
	if C.nox_xxx_loadReflSheild_499360() == 0 {
		return 0
	}

	C.sub_485F80()
	if C.sub_4960B0() == 0 {
		return 0
	}

	if C.sub_473A40() == 0 {
		return 0
	}

	if C.nox_xxx_allocArrayDrawableFX_495AB0() == 0 {
		return 0
	}

	if C.nox_xxx_allocClassListFriends_495980() == 0 {
		return 0
	}

	C.sub_4958F0()
	C.nox_xxx_gameSetCliConnected_43C720(0)
	noxflags.SetGame(noxflags.GameFlag24)
	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_netPlayerIncomingServ_4DDF60(31)
	} else {
		C.nox_xxx_netSendIncomingClient_43CB00()
	}
	C.nox_game_SetCliDrawFunc((*[0]byte)(C.nox_xxx_client_435F80_draw))
	C.dword_5d4594_811372 = 3
	*memmap.PtrUint32(0x587000, 85720) = 1
	C.obj_5D4594_811068.field_0 = 0
	C.obj_5D4594_811068.field_1 = 0
	C.obj_5D4594_811068.field_2 = C.uint(C.nox_win_width - 1)
	C.obj_5D4594_811068.field_3 = C.uint(C.nox_win_height - 1)
	C.obj_5D4594_811068.field_8 = C.int(C.nox_win_width)
	C.obj_5D4594_811068.field_9 = C.int(C.nox_win_height)
	C.obj_5D4594_811068.field_10 = 0
	C.obj_5D4594_811068.field_11 = 0
	C.obj_5D4594_811068.field_12 = 0
	v1 := C.sub_4766D0()
	C.sub_476700(v1, 0)
	if noxflags.HasGame(noxflags.GameSolo) {
		C.sub_41CC00((*C.char)(memmap.PtrOff(0x5D4594, 2660688)))
	} else if C.sub_4D6F50() != 0 || C.sub_4D6F70() != 0 {
		if C.sub_4D6F50() != 0 || C.sub_4D6F70() != 0 {
			C.sub_460380()
			C.nox_xxx_cliPrepareGameplay1_460E60()
			C.nox_xxx_cliPrepareGameplay2_4721D0()
		}
		if !noxflags.HasGame(noxflags.GameHost) {
			C.sub_41CC00((*C.char)(memmap.PtrOff(0x5D4594, 2660688)))
		}
	}
	C.nox_xxx_plrLoad_41A480((*C.char)(memmap.PtrOff(0x5D4594, 2660688)))
	if isServer {
		getPlayers()[0].GoObserver(false, true)
	}
	nox_server_parseCmdText_443C80("execrul autoexec.rul", 1)
	if isServer {
		old := parseCmd.Cheats()
		parseCmd.SetCheats(true)
		nox_server_parseCmdText_443C80("set cycle on", 1)
		for _, cmd := range serverExec {
			if len(cmd) == 0 {
				continue
			}
			nox_server_parseCmdText_443C80(cmd, 1)
		}
		parseCmd.SetCheats(old)
	}
	C.sub_4951C0()
	C.sub_465DE0(0)
	return 1
}

func nox_server_parseCmdText_443C80(cmd string, flag int) int {
	return int(C.nox_server_parseCmdText_443C80(internWStr(cmd), C.int(flag)))
}

func nox_server_currentMapGetFilename_409B30() string {
	return C.GoString((*C.char)(memmap.PtrOff(0x5D4594, 2598188)))
}

func nox_xxx_servInitialMapLoad_4D17F0() bool {
	C.sub_4E79B0(0)
	if nox_server_currentMapGetFilename_409B30()[0] == memmap.Uint8(0x5D4594, 1548720) {
		C.nox_xxx_gameSetMapPath_409D70(internCStr("tutorial.map"))
	}
	C.nox_xxx_netMapSendStop_519870()
	if C.nox_xxx_mapExitAndCheckNext_4D1860_server() == 0 {
		return false
	}
	nox_xxx_setGameState_43DDF0(nox_xxx_gameTick_4D2580_server)
	C.nox_xxx_netBuf_40EE90(1)
	noxflags.SetGame(noxflags.GameFlag18)
	C.nox_xxx_netGameSettings_4DEF00()
	C.nox_server_gameUnsetMapLoad_40A690()
	return true
}

func nox_xxx_gameTick_4D2580_server() bool {
	return C.nox_xxx_gameTick_4D2580_server() != 0
}
