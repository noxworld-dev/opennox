package main

/*
#include "proto.h"
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;
extern unsigned int dword_5d4594_1569652;
extern unsigned int dword_5d4594_1569656;
extern unsigned int nox_xxx_questFlag_1556148;

void nox_xxx_abilUpdateMB_4FBEE0();
char* nox_xxx_netUpdateRemotePlayers_4DEC80();
void nox_xxx_netlist_4DEB50();
void nox_xxx_scriptLeverReact_51ADF0();
void nox_xxx_serverLoopSendMap_519990();
void nox_xxx_spellBookReact_4FCB70();
void nox_xxx_unitsUpdateDeletedList_4E5E20();
int  nox_xxx_updateServer_4D2DA0(__int64 a1);
char nox_xxx_updateUnits_51B100();
void nox_xxx_voteUptate_506F30();
void sub_4E4170();
void sub_4EC720();
unsigned int sub_50D890();
void nox_xxx_gameTick_4D2580_server_D();
void nox_script_callOnEvent(const char* event, int a1, int a2);
int  nox_xxx_playerSomeWallsUpdate_5003B0(int a1);
void sub_4139C0();
int sub_446040();
void sub_446190();
int sub_4DCF20();
int sub_4E76C0();
void sub_4FC680();
int sub_4FC6D0();
bool sub_57B140();
*/
import "C"
import (
	noxflags "nox/common/flags"
	"nox/common/memmap"
)

func gameFPS() uint32 {
	return uint32(C.nox_gameFPS)
}

func gameFPSSet(fps uint32) {
	C.nox_gameFPS = C.uint(fps)
}

func gameFrame() uint32 {
	return uint32(C.nox_frame_xxx_2598000)
}

func gameFrameSet(v uint32) {
	C.nox_frame_xxx_2598000 = C.uint(v)
}

func gameFrameSetFromFlags() {
	if noxflags.HasGame(noxflags.GameHost) {
		gameFrameSet(1)
	} else {
		gameFrameSet(0)
	}
}

func gameFrameInc() {
	C.nox_frame_xxx_2598000++
}

//export nox_xxx_gameTick_4D2580_server_B
func nox_xxx_gameTick_4D2580_server_B(ticks int64) C.int {
	C.nox_xxx_updateServer_4D2DA0(C.longlong(ticks))
	nox_server_netMaybeSendInitialPackets_4DEB30()
	C.nox_xxx_netlist_4DEB50()
	if nox_server_mainloop_exiting_43DEA0() {
		return 0
	}
	if gameFrame()%2 == 0 {
		C.nox_xxx_serverLoopSendMap_519990()
	}
	C.sub_40B970()
	C.sub_40B790()
	if !noxflags.HasGame(noxflags.GamePause) {
		C.nox_xxx_updateUnits_51B100()
		C.sub_4EC720()
		if noxflags.HasGame(noxflags.GameFlag13) {
			C.sub_50D890()
			C.sub_4E4170()
		}
		C.nox_xxx_spellBookReact_4FCB70()
		C.nox_xxx_abilUpdateMB_4FBEE0()
		C.nox_xxx_scriptLeverReact_51ADF0()
		C.nox_xxx_voteUptate_506F30()
		C.nox_xxx_unitsUpdateDeletedList_4E5E20()
	}
	C.nox_xxx_netUpdateRemotePlayers_4DEC80()
	C.nox_xxx_unitsNewAddToList_4DAC00()
	if C.nox_xxx_checkKeybTimeout_4160F0(0x10, C.uint(10*gameFPS())) != 0 {
		C.nox_xxx_protectUnitDefUpdateMB_4E3C20()
		C.nox_xxx_setKeybTimeout_4160D0(16)
	}
	if noxflags.HasGame(noxflags.GameServerXxx) && C.sub_43AF70() == 1 && !noxflags.HasGame(noxflags.GameFlag8) && C.nox_xxx_checkKeybTimeout_4160F0(0xF, C.uint(60*gameFPS())) != 0 {
		C.nox_xxx_net_4263C0()
		C.nox_xxx_setKeybTimeout_4160D0(15)
	}
	return 1
}

//export nox_xxx_gameTick_4D2580_server_E
func nox_xxx_gameTick_4D2580_server_E() {
	if getEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE | NOX_ENGINE_FLAG_REPLAY_READ) {
		C.sub_4E76C0()
	}
	if C.nox_xxx_gameGet_4DB1B0() != 0 {
		C.nox_xxx_gameTick_4D2580_server_D()
	}
	C.sub_4139C0()
	if C.nox_xxx_serverIsClosing_446180() != 0 {
		C.sub_446190()
	}
	if C.sub_446030() != 0 && gameFrame() > 5*gameFPS()+uint32(C.sub_446040()) {
		C.sub_446380()
	}
	if !noxflags.HasGame(noxflags.GamePause) {
		gameFrameInc()
	}
	C.nox_xxx_protectData_56F5C0()
	C.sub_4FC6D0()
	nox_xxx_mapInitialize_4FC590()
	nox_xxx_mapEntry_4FC600()
	C.sub_4FC680()
	if unit := getPlayerByInd(31).Unit(); unit != nil {
		C.nox_xxx_playerSomeWallsUpdate_5003B0(C.int(uintptr(unit)))
	}
	if C.nox_xxx_get_57AF20() != 0 && C.sub_57B140() {
		C.sub_57B0A0()
	}
	if C.sub_4D6F50() != 0 {
		switchQuestIfRequested4D6FD0()
		C.sub_4DCF20()
	}
}

//export nox_server_netMaybeSendInitialPackets_4DEB30
func nox_server_netMaybeSendInitialPackets_4DEB30() {
	if !getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ) {
		C.nox_xxx_servNetInitialPackets_552A80(C.uint(memmap.Uint32(0x5D4594, 1563148)), 1)
	}
}

func nox_xxx_mapInitialize_4FC590() {
	if C.dword_5d4594_1569652 != 0 && hasPlayerUnits() {
		C.nox_script_callOnEvent(internCStr("MapInitialize"), 0, 0)
		C.nox_xxx_resetMapInit_4FC570(0)
	}
}

func nox_xxx_mapEntry_4FC600() {
	if C.dword_5d4594_1569656 != 0 && hasPlayerUnits() {
		C.nox_script_callOnEvent(internCStr("MapEntry"), 0, 0)
		C.sub_4FC580(0)
	}
}

func switchQuestIfRequested4D6FD0() {
	if C.nox_xxx_questFlag_1556148 == 0 {
		return
	}
	C.nox_xxx_questFlag_1556148--
	if C.nox_xxx_questFlag_1556148 != 0 {
		return
	}
	mapName := C.GoString(C.nox_xxx_getQuestMapName_4DCED0())
	C.nox_server_setupQuestGame_4D6C70()
	var mapFile string
	if mapName != "" {
		mapFile = mapName + ".map"
	} else {
		mapFile = C.GoString(C.nox_xxx_getQuestMapFile_4D0F60())
	}
	mapLoad4D2450(mapFile)
	C.sub_4DCE80(nil)
	C.sub_4E3CD0(0)
	C.sub_4169F0()
}

func mapLoad4D2450(file string) {
	C.nox_xxx_mapLoad_4D2450(internCStr(file))
}
