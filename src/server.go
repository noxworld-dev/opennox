package main

/*
#include "proto.h"
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;

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
*/
import "C"
import "nox/common/memmap"

//export nox_xxx_gameTick_4D2580_server_B
func nox_xxx_gameTick_4D2580_server_B(ticks int64) C.int {
	C.nox_xxx_updateServer_4D2DA0(C.longlong(ticks))
	nox_server_netMaybeSendInitialPackets_4DEB30()
	C.nox_xxx_netlist_4DEB50()
	if nox_server_mainloop_exiting_43DEA0() {
		return 0
	}
	if C.nox_frame_xxx_2598000&1 == 0 {
		C.nox_xxx_serverLoopSendMap_519990()
	}
	C.sub_40B970()
	C.sub_40B790()
	if C.nox_xxx_checkGFlagNoParticles_413A50() == 0 {
		C.nox_xxx_updateUnits_51B100()
		C.sub_4EC720()
		if getGameFlag(4096) {
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
	if C.nox_xxx_checkKeybTimeout_4160F0(0x10, 10*C.nox_gameFPS) != 0 {
		C.nox_xxx_protectUnitDefUpdateMB_4E3C20()
		C.nox_xxx_setKeybTimeout_4160D0(16)
	}
	if getGameFlag(0x2000) && C.sub_43AF70() == 1 && !getGameFlag(128) && C.nox_xxx_checkKeybTimeout_4160F0(0xF, 60*C.nox_gameFPS) != 0 {
		C.nox_xxx_net_4263C0()
		C.nox_xxx_setKeybTimeout_4160D0(15)
	}
	return 1
}

//export nox_server_netMaybeSendInitialPackets_4DEB30
func nox_server_netMaybeSendInitialPackets_4DEB30() {
	if !getEngineFlag(NOX_ENGINE_FLAG_23) {
		C.nox_xxx_servNetInitialPackets_552A80(C.uint(memmap.Uint32(0x5D4594, 1563148)), 1)
	}
}
