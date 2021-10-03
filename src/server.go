package nox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__drawable__drawdb.h"
#include "client__gui__guiquit.h"
#include "common__system__team.h"
#include "server__system__server.h"
#include "server__script__script.h"
#include "common__magic__speltree.h"
#include "common__net_list.h"
#include "common__crypt.h"
#include "common__log.h"

extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;
extern unsigned int nox_xxx_resetMapInit_1569652;
extern unsigned int dword_5d4594_1569656;
extern unsigned int dword_5d4594_2650652;
extern unsigned int nox_xxx_questFlag_1556148;
extern unsigned int dword_5d4594_2649712;
extern unsigned int dword_5d4594_825768;
extern unsigned int dword_5d4594_1548524;
extern unsigned int nox_server_switchToWP_1548664;
extern nox_object_t* nox_xxx_host_player_unit_3843628;

void nox_xxx_abilUpdateMB_4FBEE0();
char* nox_server_updateRemotePlayers_4DEC80();
void nox_xxx_netlist_4DEB50();
//void nox_xxx_scriptLeverReact_51ADF0();
void nox_xxx_serverLoopSendMap_519990();
void nox_xxx_unitsUpdateDeletedList_4E5E20();
int  nox_xxx_updateServer_4D2DA0(long long a1);
void nox_xxx_updateUnits_51B100();
void nox_xxx_voteUptate_506F30();
void sub_4E4170();
void sub_4EC720();
unsigned int sub_50D890();
void nox_xxx_gameTick_4D2580_server_D();
int  nox_xxx_playerSomeWallsUpdate_5003B0(nox_object_t* obj);
void sub_4139C0();
//void sub_446190();
int sub_4DCF20();
int sub_4E76C0();
void sub_4FC680();
bool sub_57B140();
//int sub_417C60();
//int nox_xxx_freeObjectTypes_4E2A20();
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"fmt"
	"path/filepath"
	"strings"
	"unsafe"

	"nox/v1/common"
	"nox/v1/common/crypt"
	"nox/v1/common/datapath"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/fs"
	"nox/v1/common/memmap"
	"nox/v1/server"
	"nox/v1/server/script"
)

var (
	noxServerPort   int = common.GamePort
	noxServer           = server.New()
	mapSwitchWPName string
)

//export nox_server_ResetObjectGIDs_4E3C70
func nox_server_ResetObjectGIDs_4E3C70() {
	noxServer.ResetObjectScriptIDs()
}

//export nox_server_SetFirstObjectScriptID_4E3C60
func nox_server_SetFirstObjectScriptID_4E3C60(id C.int) {
	noxServer.SetFirstObjectScriptID(server.ObjectScriptID(id))
}

//export nox_server_SetLastObjectScriptID
func nox_server_SetLastObjectScriptID(id C.uint) {
	noxServer.SetLastObjectScriptID(server.ObjectScriptID(id))
}

//export nox_server_LastObjectScriptID
func nox_server_LastObjectScriptID() C.uint {
	return C.uint(noxServer.LastObjectScriptID())
}

//export nox_server_NextObjectScriptID
func nox_server_NextObjectScriptID() C.uint {
	return C.uint(noxServer.NextObjectScriptID())
}

//export nox_xxx_servGetPort_40A430
func nox_xxx_servGetPort_40A430() C.int {
	return C.int(getServerPort())
}

//export nox_xxx_setPortParam_40A3E0
func nox_xxx_setPortParam_40A3E0(port C.int) {
	setServerPort(int(port))
}

func inferHTTPPort(port int) int {
	return common.GameHTTPPort + (port - common.GamePort)
}

func setServerPort(port int) {
	if port <= 0 {
		port = common.GamePort
	}
	noxServerPort = port
}

func getServerPort() int {
	if noxServerPort <= 0 {
		return common.GamePort
	}
	return noxServerPort
}

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

func nox_xxx_gameTick_4D2580_server_B(ticks uint64) bool {
	C.nox_xxx_updateServer_4D2DA0(C.longlong(ticks))
	nox_server_netMaybeSendInitialPackets_4DEB30()
	nox_xxx_netlist_4DEB50()
	if nox_server_mainloop_exiting_43DEA0() {
		return false
	}
	if gameFrame()%2 == 0 {
		C.nox_xxx_serverLoopSendMap_519990()
	}
	C.sub_40B970()
	C.sub_40B790()
	if !noxflags.HasGame(noxflags.GamePause) {
		C.nox_xxx_updateUnits_51B100()
		C.sub_4EC720()
		if noxflags.HasGame(noxflags.GameModeQuest) {
			C.sub_50D890()
			C.sub_4E4170()
		}
		nox_xxx_spellBookReact_4FCB70()
		C.nox_xxx_abilUpdateMB_4FBEE0()
		C.nox_xxx_scriptLeverReact_51ADF0()
		scriptTick()
		C.nox_xxx_voteUptate_506F30()
		C.nox_xxx_unitsUpdateDeletedList_4E5E20()
	}
	updateRemotePlayers()
	C.nox_xxx_unitsNewAddToList_4DAC00()
	if inputKeyCheckTimeoutLegacy(0x10, 10*gameFPS()) {
		C.nox_xxx_protectUnitDefUpdateMB_4E3C20()
		inputSetKeyTimeoutLegacy(16)
	}
	if noxflags.HasGame(noxflags.GameOnline) && C.nox_xxx_check_flag_aaa_43AF70() == 1 && !noxflags.HasGame(noxflags.GameModeChat) && inputKeyCheckTimeoutLegacy(0xF, 60*gameFPS()) {
		C.nox_xxx_net_4263C0()
		inputSetKeyTimeoutLegacy(15)
	}
	return true
}

func sub_446040() uint32 {
	return uint32(C.dword_5d4594_825768)
}

func nox_xxx_gameTick_4D2580_server_E() {
	if getEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE | NOX_ENGINE_FLAG_REPLAY_READ) {
		C.sub_4E76C0()
	}
	if C.nox_xxx_gameGet_4DB1B0() != 0 {
		nox_xxx_gameTick_4D2580_server_D()
	}
	C.sub_4139C0()
	if C.nox_xxx_serverIsClosing_446180() != 0 {
		C.sub_446190()
	}
	if C.sub_446030() != 0 && gameFrame() > 5*gameFPS()+sub_446040() {
		C.sub_446380()
	}
	if !noxflags.HasGame(noxflags.GamePause) {
		gameFrameInc()
	}
	C.nox_xxx_protectData_56F5C0()
	nox_server_xxxInitPlayerUnits_4FC6D0()
	maybeRegisterGameOnline() // TODO: not exactly the right place
	nox_xxx_mapInitialize_4FC590()
	nox_xxx_mapEntry_4FC600()
	C.sub_4FC680()
	if unit := getPlayerByInd(31).UnitC(); unit != nil {
		C.nox_xxx_playerSomeWallsUpdate_5003B0(unit.CObj())
	}
	if nox_xxx_get_57AF20() != 0 && C.sub_57B140() {
		C.sub_57B0A0()
	}
	if nox_xxx_isQuest_4D6F50() {
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
	if C.nox_xxx_resetMapInit_1569652 != 0 && hasPlayerUnits() {
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
	switchMap(mapFile)
	C.sub_4DCE80(nil)
	nox_game_setQuestStage_4E3CD0(0)
	C.sub_4169F0()
}

func sub_416640() []byte {
	// TODO: size is a guess
	return unsafe.Slice((*byte)(memmap.PtrOff(0x5D4594, 371516)), 168)
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
			nox_xxx_netSendSock_552640(pl.Index()+1, buf[:], NOX_NET_SEND_NO_LOCK|NOX_NET_SEND_FLAG2)
			pl.Disconnect(3)
		}
		if pl.field_3680&0x80 != 0 {
			pl.Disconnect(4)
		}
		if (pl.field_3676 != 3) || (pl.field_3680&0x10 == 0) {
			var buf [3]byte
			buf[0] = 39
			binary.LittleEndian.PutUint16(buf[1:], uint16(gameFrame()))
			nox_netlist_addToMsgListCli_40EBC0(pl.Index(), 1, buf[:])
		} else {
			C.nox_xxx_netUpdate_518EE0(pl.UnitC().CObj())
		}
		if pl.UnitC() == HostPlayerUnit() {
			C.nox_xxx_netImportant_4E5770(C.uchar(pl.Index()), 1)
		} else if C.dword_5d4594_2650652 == 0 || (gameFrame()%uint32(C.nox_xxx_rateGet_40A6C0()) == 0) || noxflags.HasGame(noxflags.GameFlag4) {
			C.nox_xxx_netSendReadPacket_5528B0(C.uint(pl.Index()+1), 0)
		}
	}
}

func nox_xxx_servNewSession_4D1660() error {
	gameLog.Println("nox_xxx_servNewSession_4D1660")
	C.sub_4D15C0()
	C.dword_5d4594_2649712 = 0x80000000
	C.nox_xxx_host_player_unit_3843628 = nil
	C.sub_4D7B40()
	C.sub_41E4B0(0)
	noxServer.ResetObjectScriptIDs()
	C.sub_56F1C0()
	nox_xxx_cliResetAllPlayers_416E30()
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
	if !noxflags.HasGame(noxflags.GameModeCoop) {
		ind, nport, err := nox_xxx_netAddPlayerHandler_4DEBC0(getServerPort())
		*memmap.PtrInt32(0x5D4594, 1548516) = int32(ind)
		if err != nil {
			return err
		}
		setServerPort(nport)
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
	srvPort := getServerPort()
	httpPort := inferHTTPPort(srvPort)
	if err := gameStartHTTP(httpPort); err != nil {
		return err
	}
	if err := gameStartNAT(srvPort, httpPort); err != nil {
		return err
	}
	return nil
}

func nox_server_netCloseHandler_4DEC60(ind int) {
	nox_xxx_netStructReadPackets(ind)
	nox_server_netClose_5546A0(ind)
	C.nox_xxx_host_player_unit_3843628 = nil
	sub_43DE40(nil)
	gameStopNAT()
	gameStopHTTP()
}

func nox_xxx_servEndSession_4D3200() {
	C.sub_50D1E0()
	C.sub_4DB100()
	C.sub_421B10()
	C.sub_516F10()
	C.sub_4FF770()
	nox_xxx_replayStopSave_4D33B0()
	nox_xxx_replayStopReadMB_4D3530()
	nox_xxx_cliResetAllPlayers_416E30()
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
	C.nox_xxx_freeGameObjectClass_4E3420()
	C.nox_xxx_freeObjectTypes_4E2A20()
	if !noxflags.HasGame(noxflags.GameModeCoop) {
		nox_server_netCloseHandler_4DEC60(int(memmap.Uint32(0x5D4594, 1548516)))
		if !noxflags.HasGame(noxflags.GameFlag26) {
			C.nox_xxx_networkLog_close_413D00()
		}
	}
	C.sub_56F3B0()
	C.nox_netlist_resetAll_40EE60()
	_ = fs.Remove(datapath.Save("_temp_.dat"))
}

func sub_4D3C30() {
	C.nox_xxx_free_503F40()
	C.sub_51D0E0()
	C.sub_502DF0()
}

func nox_server_loadMapFile_4CF5F0(mname string, noCrypt bool) bool {
	gameLog.Printf("loading map %q", mname)
	C.sub_481410()
	C.nox_xxx_unitsNewAddToList_4DAC00()
	C.nox_xxx_waypoint_5799C0()
	if mname == "" {
		return false
	}
	if strings.ToLower(mname) == "#return" {
		mname = GoStringP(memmap.PtrOff(0x5D4594, 1523080))
	} else if strings.HasPrefix(mname, "#") {
		v3 := datapath.Path()
		C.sub_4D39F0(internCStr(v3))
		v13 := mname[1:]
		if i := strings.IndexByte(mname, '.'); i > 0 {
			v13 = v3[:i]
		}
		C.sub_4D42E0(internCStr(v13))
		v12 := fmt.Sprintf("$%s.map", v13)
		nox_xxx_gameSetMapPath_409D70(v12)
		if C.nox_xxx_mapGenStart_4D4320() == 0 {
			C.nox_xxx_mapSwitchLevel_4D12E0(1)
			return false
		}
		sub_4D3C30()
		mname = v12
	}
	var fname string
	if strings.ContainsAny(mname, "\\/") {
		fname = mname
	} else {
		dir := strings.TrimSuffix(mname, filepath.Ext(mname))
		fname = filepath.Join("maps", dir, mname)
	}
	if _, err := fs.Stat(fname); err != nil {
		tname := strings.TrimSuffix(fname, filepath.Ext(mname)) + ".nxz"
		if _, err := fs.Stat(tname); err != nil {
			return false
		}
		if C.nox_xxx_mapNxzDecompress_57BC50(internCStr(tname), internCStr(fname)) == 0 {
			return false
		}
	}
	v8 := getServerMap()
	C.nox_common_checkMapFile_4CFE10(internCStr(v8))
	var err error
	if noCrypt {
		err = cryptFileOpen(fname, 1, -1)
	} else {
		err = cryptFileOpen(fname, 1, crypt.MapKey)
	}
	if err != nil {
		binFileLog.Println(err)
		return false
	}
	var hdr [4]byte
	cryptFileReadWrite(hdr[:4])
	magic := binary.LittleEndian.Uint32(hdr[:])
	if magic == 0xFADEBEEF {
		C.nox_xxx_mapSetCrcMB_409B10(0)
	} else {
		if magic != 0xFADEFACE {
			nox_xxx_cryptClose_4269F0()
			return false
		}
		cryptFileReadMaybeAlign(hdr[:4])
		crc := binary.LittleEndian.Uint32(hdr[:])
		C.nox_xxx_mapSetCrcMB_409B10(C.int(crc))
	}
	if C.nox_xxx_serverParseEntireMap_4CFCE0() == 0 {
		return false
	}
	C.nox_xxx_scriptRunFirst_507290()
	nox_xxx_cryptClose_4269F0()
	if !noxflags.HasGame(0x200000) {
		nox_xxx_mapReadSetFlags_4CF990()
		if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
			C.sub_416690()
		}
		noxflags.UnsetGame(0x4000000)
		C.sub_470680()
		C.sub_4D0550(internCStr(fname))
		C.sub_4161E0()
		if !noxflags.HasGame(128) {
			C.sub_4165F0(0, 1)
		}
	}
	StrCopyP(memmap.PtrOff(0x5D4594, 1523080), 1024, mname)
	return true
}

func nox_server_xxxInitPlayerUnits_4FC6D0() {
	if C.nox_xxx_resetMapInit_1569652 != 1 && C.dword_5d4594_1569656 != 1 {
		return
	}
	if len(getPlayerUnits()) == 0 {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) {
		if nox_game_getQuestStage_4E3CC0() == 1 {
			C.nox_game_sendQuestStage_4D6960(255)
			C.sub_4D7440(1)
			C.sub_4D60B0()
		} else if sub_4D6F30() == 0 || C.sub_4D7430() != 0 {
			if C.sub_4D76F0() == 1 {
				C.sub_4D6880(255, 1)
				C.sub_4D76E0(0)
				C.sub_4D7440(1)
				C.sub_4D60B0()
			} else {
				fname := datapath.Save("_temp_.dat")
				for _, u := range getPlayerUnits() {
					v3 := u.ptrYyy()
					v4 := asPlayer(*(**C.nox_playerInfo)(unsafe.Add(v3, 276)))
					pi := v4.Index()
					if *(*uint32)(v4.field(4792)) == 1 && *(*uint32)(unsafe.Add(v3, 552)) == 0 &&
						nox_xxx_playerSaveToFile_41A140(fname, pi) {
						v5 := C.sub_419EE0(C.char(pi))
						C.nox_xxx_sendGauntlet_4DCF80(C.int(pi), 1)
						if C.sub_41CFA0(internCStr(fname), C.int(pi)) == 0 && v5 == 0 {
							C.nox_xxx_sendGauntlet_4DCF80(C.int(pi), 0)
						}
						fs.Remove(fname)
					}
					C.sub_4D6770(C.int(pi))
				}
				C.sub_4D6880(255, 0)
				C.sub_4D7440(1)
				C.sub_4D60B0()
			}
		} else {
			C.nox_game_sendQuestStage_4D6960(255)
			C.sub_4D7440(1)
			C.sub_4D60B0()
		}
	} else {
		nox_xxx_netMsgFadeBegin_4D9800(true, true)
	}
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(128) {
		for _, u := range getPlayerUnits() {
			v3 := u.ptrYyy()
			v7 := asPlayer(*(**C.nox_playerInfo)(unsafe.Add(v3, 276)))
			if v7.Index() != 31 && v7.field_3680&1 == 0 {
				C.nox_xxx_buffApplyTo_4FF380(u.CObj(), 23, 0, 5)
			}
		}
	}
}

//export nox_xxx_mapLoad_4D2450
func nox_xxx_mapLoad_4D2450(a1 *C.char) {
	switchMap(GoString(a1))
}

func switchMap(fname string) {
	gameLog.Printf("switch map: %q", fname)
	ptr2408 := unsafe.Slice((*byte)(memmap.PtrOff(0x973F18, 2408)), 1464)

	var v5 [1464]byte
	copy(v5[:], ptr2408)

	name := fname
	if ext := filepath.Ext(fname); ext != "" {
		name = strings.TrimSuffix(name, ext)
	}
	name = strings.ToLower(name)
	C.nox_common_checkMapFile_4CFE10(internCStr(name))
	C.sub_4CFDF0(C.int(memmap.Uint32(0x973F18, 3800)))
	copy(ptr2408, v5[:])
	C.dword_5d4594_1548524 = 1
	mname := fname
	if i := strings.IndexByte(fname, ':'); i >= 0 {
		mapSwitchWPName = mname[i+1:]
		mname = mname[:i]
	} else {
		mapSwitchWPName = ""
	}
	if C.sub_51A130() != 0 {
		C.nox_xxx_mapSendCancelAll_5198B0(0)
	}
	mname = strings.ToLower(mname)
	nox_xxx_gameSetMapPath_409D70(mname)
}

func sub_4CFC90(a1 unsafe.Pointer) int {
	v1 := *(*uint32)(unsafe.Pointer(uintptr(a1) + 1392))
	if v1&4 != 0 {
		return 256
	}
	if v1&0x20 != 0 {
		return 1024
	}
	if v1&8 != 0 {
		return 32
	}
	if v1&0x10 != 0 {
		return 16
	}
	if v1&0x40 != 0 {
		return 64
	}
	if v1&0x2 != 0 {
		return 4096
	}
	return 128
}

func sub_4CFF50(v int) int {
	out := 0
	if v&1 != 0 {
		out |= 512
	}
	if v&2 != 0 {
		out |= 0x1000
	}
	if v&4 != 0 {
		out |= 0x100
	}
	if v&0x20 != 0 {
		out |= 0x400
	}
	if v&8 != 0 {
		out |= 0x20
	}
	if v&0x10 != 0 {
		out |= 0x10
	}
	if v&0x40 != 0 {
		out |= 0x40
	}
	if v < 0 {
		out |= 0x80
	}
	return out
}

func nox_xxx_mapGetTypeMB_4CFFA0(a1 unsafe.Pointer) int {
	val := *(*int32)(unsafe.Pointer(uintptr(a1) + 1392))
	return sub_4CFF50(int(val))
}

func nox_xxx_mapReadSetFlags_4CF990() {
	v0 := unsafe.Slice((*byte)(unsafe.Pointer(C.sub_4165B0())), 58)
	if noxflags.HasGame(noxflags.GameModeElimination) && (memmap.Int32(0x973F18, 3800) < 0 || (v0[53]&4 == 0)) {
		C.nox_xxx_ruleSetNoRespawn_40A5E0(0)
	}
	C.sub_455C10()
	C.sub_456050()
	if noxflags.HasGame(noxflags.GameModeQuest) && memmap.Int32(0x973F18, 3800) < 0 {
		C.sub_4D6B10(1)
		C.sub_419030(1)
	}
	mapname := getServerMap()
	gameLog.Printf("checking map flags for %q", filepath.Base(mapname))
	if C.nox_common_checkMapFile_4CFE10(internCStr(mapname)) == 0 {
		if !noxflags.HasGame(noxflags.GameModeSolo10) {
			noxflags.UnsetGame(noxflags.GameModeMask)
			noxflags.SetGame(noxflags.GameModeArena)
			C.sub_4D0D90(1)
		}
		return
	}
	mapType := nox_xxx_mapGetTypeMB_4CFFA0(memmap.PtrOff(0x973F18, 2408))
	vv := memmap.Int32(0x973F18, 3800)
	if vv&1 != 0 {
		gameLog.Println("setting coop mode")
		noxflags.UnsetGame(noxflags.GameModeMask)
		C.nox_xxx_createCoopTeam_417E10()
		noxflags.SetGame(noxflags.GameModeCoop)
	} else if vv&2 != 0 {
		gameLog.Println("setting quest mode")
		isChat := noxflags.HasGame(noxflags.GameModeChat)
		noxflags.UnsetGame(noxflags.GameModeMask)
		noxflags.SetGame(noxflags.GameModeQuest)
		if isChat {
			C.nox_server_setupQuestGame_4D6C70()
		}
	} else if vv >= 0 {
		f52 := (*uint16)(unsafe.Pointer(uintptr(unsafe.Pointer(&v0[0])) + 52))
		if int(*f52)&mapType == 0 {
			*f52 = uint16(sub_4CFC90(memmap.PtrOff(0x973F18, 2408)) | int(*f52)&0xE80F)
		}
		if v0[52]&0x10 == 0 {
			C.nox_xxx_mapFindCrown_4CFC30()
		}
		mode := noxflags.GameFlag(*f52)
		if mode.Has(noxflags.GameModeCTF) {
			gameLog.Println("setting CTF mode")
			if C.nox_xxx_mapInfoSetCapflag_417EA0() != 0 {
				noxflags.UnsetGame(noxflags.GameModeMask)
				noxflags.SetGame(noxflags.GameModeCTF)
			}
		} else if mode.Has(noxflags.GameModeFlagBall) {
			gameLog.Println("setting flagball mode")
			if C.nox_xxx_mapInfoSetFlagball_417F30() != 0 {
				noxflags.UnsetGame(noxflags.GameModeMask)
				noxflags.SetGame(noxflags.GameModeFlagBall)
				C.nox_xxx_spellDisable_424BB0(132)
			}
		} else if mode.Has(noxflags.GameModeKOTR) {
			gameLog.Println("setting KOTR mode")
			if C.nox_xxx_mapInfoSetKotr_4180D0() != 0 {
				noxflags.UnsetGame(noxflags.GameModeMask)
				noxflags.SetGame(noxflags.GameModeKOTR)
			}
		} else if mode.Has(noxflags.GameModeElimination) {
			gameLog.Println("setting elimination mode")
			if !noxflags.HasGame(noxflags.GameModeElimination) {
				C.nox_xxx_ruleSetNoRespawn_40A5E0(1)
			}
			noxflags.UnsetGame(noxflags.GameModeMask)
			noxflags.SetGame(noxflags.GameModeElimination)
		} else {
			gameLog.Println("setting arena mode")
			noxflags.UnsetGame(noxflags.GameModeMask)
			noxflags.SetGame(noxflags.GameModeArena)
		}
	} else {
		gameLog.Println("setting chat mode")
		C.sub_40A1F0(0)
		noxflags.UnsetGame(noxflags.GameModeMask)
		noxflags.SetGame(noxflags.GameModeChat)
		if C.nox_xxx_getTeamCounter_417DD0() != 0 {
			C.nox_xxx_teamAssignFlags_418640()
			if C.nox_xxx_CheckGameplayFlags_417DA0(2) == 0 && !noxflags.HasGame(0x8000) {
				C.nox_xxx_toggleAllTeamFlags_418690(1)
			}
		}
	}
}
