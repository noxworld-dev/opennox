package main

/*
#include "proto.h"
#include "common__net_list.h"
#include "common__log.h"

extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;
extern unsigned int dword_5d4594_1569652;
extern unsigned int dword_5d4594_1569656;
extern unsigned int dword_5d4594_2650652;
extern unsigned int nox_xxx_questFlag_1556148;
extern unsigned int dword_5d4594_2649712;
extern unsigned int nox_xxx_host_player_unit_3843628;

void nox_xxx_abilUpdateMB_4FBEE0();
char* nox_server_updateRemotePlayers_4DEC80();
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
int  nox_xxx_playerSomeWallsUpdate_5003B0(int a1);
void sub_4139C0();
int sub_446040();
void sub_446190();
int sub_4DCF20();
int sub_4E76C0();
void sub_4FC680();
int sub_4FC6D0();
bool sub_57B140();
int sub_417C60();
int nox_xxx_free_4E2A20();
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"fmt"
	"unsafe"

	noxflags "nox/v1/common/flags"
	"nox/v1/common/fs"
	"nox/v1/common/memmap"
	"nox/v1/server/script"
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
		scriptTick()
		C.nox_xxx_voteUptate_506F30()
		C.nox_xxx_unitsUpdateDeletedList_4E5E20()
	}
	updateRemotePlayers()
	C.nox_xxx_unitsNewAddToList_4DAC00()
	if C.nox_xxx_checkKeybTimeout_4160F0(0x10, C.uint(10*gameFPS())) != 0 {
		C.nox_xxx_protectUnitDefUpdateMB_4E3C20()
		C.nox_xxx_setKeybTimeout_4160D0(16)
	}
	if noxflags.HasGame(noxflags.GameServerXxx) && C.nox_xxx_check_flag_aaa_43AF70() == 1 && !noxflags.HasGame(noxflags.GameFlag8) && C.nox_xxx_checkKeybTimeout_4160F0(0xF, C.uint(60*gameFPS())) != 0 {
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
	if unit := getPlayerByInd(31).UnitC(); unit != nil {
		C.nox_xxx_playerSomeWallsUpdate_5003B0(C.int(uintptr(unit.CObj())))
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
		clearScriptTriggers()
		scriptOnEvent(script.EventMapInitialize)
		C.nox_xxx_resetMapInit_4FC570(0)
	}
}

func nox_xxx_mapEntry_4FC600() {
	if C.dword_5d4594_1569656 != 0 && hasPlayerUnits() {
		scriptOnEvent(script.EventMapEntry)
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
	nox_game_setQuestStage_4E3CD0(0)
	C.sub_4169F0()
}

func mapLoad4D2450(file string) {
	C.nox_xxx_mapLoad_4D2450(internCStr(file))
}

func updateRemotePlayers() {
	for _, pl := range getPlayers() {
		if pl.UnitC() == nil {
			continue
		}
		fr := 30
		if pl.field_3680&0x10 != 0 {
			fr = 90
		}
		if gameFrame()-uint32(pl.frame_3596) > uint32(fr)*gameFPS() {
			m := uint32(pl.netCode)
			// TODO: passing Go pointer
			C.nox_xxx_netInformTextMsg2_4DA180(3, (*C.uchar)(unsafe.Pointer(&m)))
			var buf [1]byte
			buf[0] = 198
			C.nox_xxx_netSendSock_552640(C.uint(pl.Index()+1), (*C.char)(unsafe.Pointer(&buf[0])), C.int(len(buf)), C.NOX_NET_SEND_NO_LOCK|C.NOX_NET_SEND_FLAG2)
			pl.Disconnect(3)
		}
		if pl.field_3680&0x80 != 0 {
			pl.Disconnect(4)
		}
		if (pl.field_3676 != 3) || (pl.field_3680&0x10 == 0) {
			var buf [3]byte
			buf[0] = 39
			binary.LittleEndian.PutUint16(buf[1:], uint16(gameFrame()))
			// TODO: passing Go pointer
			C.nox_netlist_addToMsgListCli_40EBC0(C.int(pl.Index()), 1, (*C.uchar)(unsafe.Pointer(&buf[0])), C.int(len(buf)))
		} else {
			C.nox_xxx_netUpdate_518EE0((*C.uint)(pl.UnitC().CObj()))
		}
		if pl.UnitC() == HostPlayerUnit() {
			C.nox_xxx_netImportant_4E5770(C.uchar(pl.Index()), 1)
		} else if C.dword_5d4594_2650652 == 0 || (gameFrame()%uint32(C.nox_xxx_rateGet_40A6C0()) == 0) || noxflags.HasGame(noxflags.GameFlag4) {
			C.nox_xxx_netSendReadPacket_5528B0(C.uint(pl.Index()+1), 0)
		}
	}
}

func nox_xxx_servNewSession_4D1660() error {
	C.sub_4D15C0()
	C.dword_5d4594_2649712 = 0x80000000
	C.nox_xxx_host_player_unit_3843628 = 0
	C.sub_4D7B40()
	C.sub_41E4B0(0)
	C.nox_xxx_servResetObjectGIDs_4E3C70()
	C.sub_56F1C0()
	C.nox_xxx_cliResetAllPlayers_416E30()
	C.nox_netlist_resetAll_40EE60()
	C.sub_4E4EF0()
	C.sub_4E4ED0()
	if C.nox_xxx_allocAudEventArray_501860() == 0 {
		return errors.New("nox_xxx_allocAudEventArray_501860 failed")
	}
	if C.nox_read_things_alternative_4E2B60() == 0 {
		return errors.New("nox_read_things_alternative_4E2B60 failed")
	}
	C.nox_motd_4463E0(1)
	C.sub_417C60()
	C.sub_4259C0()
	C.sub_4D7C60()
	C.nox_xxx_unitDefFindMaxDataSize_4E3320()
	if C.sub_518770() == 0 {
		return errors.New("sub_518770 failed")
	}
	noxflags.HasGame(noxflags.GameFlag22)
	if C.nox_xxx_allocClassArrayObjects_4E3360(0x1388) == 0 {
		return errors.New("nox_xxx_allocClassArrayObjects_4E3360 failed")
	}
	if C.sub_517AE0() == 0 {
		return errors.New("sub_517AE0 failed")
	}
	if C.nox_xxx_allocVisitNodesArray_50AB90() == 0 {
		return errors.New("nox_xxx_allocVisitNodesArray_50AB90 failed")
	}
	if C.nox_xxx_allocSpellRelatedArrays_4FC9B0() == 0 {
		return errors.New("nox_xxx_allocSpellRelatedArrays_4FC9B0 failed")
	}
	if C.nox_xxx_allocSpringsArray_5112C0() == 0 {
		return errors.New("nox_xxx_allocSpringsArray_5112C0 failed")
	}
	if C.nox_xxx_allocDebugDataArray_57C410() == 0 {
		return errors.New("nox_xxx_allocDebugDataArray_57C410 failed")
	}
	if C.nox_xxx_allocGroupRelatedArrays_57BFB0() == 0 {
		return errors.New("nox_xxx_allocGroupRelatedArrays_57BFB0 failed")
	}
	if C.nox_xxx_allocItemRespawnArray_4ECA60() == 0 {
		return errors.New("nox_xxx_allocItemRespawnArray_4ECA60 failed")
	}
	if C.nox_xxx_registerShopClasses_50E2A0() == 0 {
		return errors.New("nox_xxx_registerShopClasses_50E2A0 failed")
	}
	if C.nox_xxx_allocMonsterRelatedArrays_50D780() == 0 {
		return errors.New("nox_xxx_allocMonsterRelatedArrays_50D780 failed")
	}
	if C.nox_xxx_allocVoteArray_5066D0() == 0 {
		return errors.New("nox_xxx_allocVoteArray_5066D0 failed")
	}
	if C.nox_xxx_allocMagicWallArray_4FF730() == 0 {
		return errors.New("nox_xxx_allocMagicWallArray_4FF730 failed")
	}
	if C.nox_xxx_monsterList_517520() == 0 {
		return errors.New("nox_xxx_monsterList_517520 failed")
	}
	C.sub_416920()
	if !noxflags.HasGame(noxflags.GameSolo) {
		v1 := C.nox_xxx_servGetPort_40A430()
		*memmap.PtrInt32(0x5D4594, 1548516) = int32(C.nox_xxx_netAddPlayerHandler_4DEBC0(v1))
		if !noxflags.HasGame(noxflags.GameFlag26) {
			C.nox_xxx_networkLog_init_413CC0()
		}
	}
	C.nox_xxx_allocArrayExecAbilities_4FB990()
	if C.nox_xxx_allocPendingOwnsArray_516EE0() == 0 {
		return errors.New("nox_xxx_allocPendingOwnsArray_516EE0 failed")
	}
	C.sub_421B10()
	C.sub_4DB0A0()
	C.sub_4D0F30()
	if err := gameStartHTTP(); err != nil {
		return err
	}
	if err := gameStartNAT(); err != nil {
		return err
	}
	return nil
}

func nox_server_netCloseHandler_4DEC60(a1 uint32) {
	C.nox_xxx_netStructReadPackets_5545B0(C.uint(a1))
	C.nox_server_netClose_5546A0(C.uint(a1))
	C.nox_xxx_host_player_unit_3843628 = 0
	C.sub_552450()
	gameStopNAT()
	gameStopHTTP()
}

func nox_xxx_servEndSession_4D3200() {
	C.sub_50D1E0()
	C.sub_4DB100()
	C.sub_421B10()
	C.sub_516F10()
	C.sub_4FF770()
	C.nox_xxx_replayStopSave_4D33B0()
	C.nox_xxx_replayStopReadMB_4D3530()
	C.nox_xxx_cliResetAllPlayers_416E30()
	C.sub_446490(1)
	C.sub_4259F0()
	C.nox_xxx_mapSwitchLevel_4D12E0(0)
	nox_xxx_mapLoad_40A380()
	C.sub_4E4DE0()
	C.sub_57C460()
	C.sub_57C030()
	C.sub_511310()
	C.nox_xxx_freeSpellRelated_4FCA80()
	C.sub_50ABF0()
	C.sub_517B30()
	C.sub_5018D0()
	C.sub_4ECA90()
	C.sub_506720()
	C.sub_50D820()
	C.nox_xxx_deleteShopInventories_50E300()
	C.sub_416950()
	C.sub_4E3420()
	C.nox_xxx_free_4E2A20()
	if !noxflags.HasGame(noxflags.GameSolo) {
		nox_server_netCloseHandler_4DEC60(*memmap.PtrUint32(0x5D4594, 1548516))
		if !noxflags.HasGame(noxflags.GameFlag26) {
			C.nox_xxx_networkLog_close_413D00()
		}
	}
	C.sub_56F3B0()
	C.nox_netlist_resetAll_40EE60()
	_ = fs.Remove(fmt.Sprintf("%s\\Save\\_temp_.dat", getDataPath()))
}
