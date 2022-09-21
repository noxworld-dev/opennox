package opennox

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
#include "server__script__activator.h"
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
extern unsigned int dword_5d4594_1548524;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
extern uint32_t dword_5d4594_1563096;

void nox_xxx_abilUpdateMB_4FBEE0();
char* nox_server_updateRemotePlayers_4DEC80();
void nox_xxx_netlist_4DEB50();
//void nox_script_activatorRun_51ADF0();
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
int sub_4DCF20();
int sub_4E76C0();
bool sub_57B140();

void nox_xxx_updateUnits_51B100_A();
void nox_xxx_updateUnits_51B100_B();
void nox_xxx_updateUnits_51B100_C();
void nox_xxx_updateUnits_51B100_D();
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"fmt"
	"path/filepath"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	noxServer *Server
)

func NewServer(pr console.Printer, sm *strman.StringManager) *Server {
	s := &Server{
		port:   common.GamePort,
		Server: server.New(pr, sm),
	}
	s.allocTeams()
	s.initPlayers()
	s.http.init()
	s.initMetrics()
	s.abilities.Init(s)
	s.noxScript.Init(s)
	return s
}

type Server struct {
	*server.Server
	port            int
	players         serverPlayers
	spells          serverSpells
	abilities       serverAbilities
	srvReg          srvReg
	scriptEvents    scriptEvents
	nat             natService
	http            httpService
	noxScript       noxScript
	lua             scriptLUA
	tickHooks       tickHooks
	objs            serverObjTypes
	teams           serverTeams
	ai              aiData
	quest           questServer
	springs         serverSprings
	debug           serverDebug
	mapSwitchWPName string
	announce        bool
}

//export nox_server_ResetObjectGIDs_4E3C70
func nox_server_ResetObjectGIDs_4E3C70() {
	noxServer.ResetObjectScriptIDs()
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
	return C.int(noxServer.getServerPort())
}

func inferHTTPPort(port int) int {
	return common.GameHTTPPort + (port - common.GamePort)
}

func (s *Server) setServerPort(port int) {
	if port <= 0 {
		port = common.GamePort
	}
	s.port = port
}

func (s *Server) getServerPort() int {
	if s.port <= 0 {
		return common.GamePort
	}
	return s.port
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

func (s *Server) updateUnits() { // nox_xxx_updateUnits_51B100
	s.updateUnitsAAA()
	C.nox_xxx_updateUnits_51B100_B()
	s.updateUnitsCallUpdate()
	C.nox_xxx_collisions_511850()
	C.nox_xxx_updateUnits_51B100_C()
	C.nox_xxx_updateUnits_51B100_D()
	C.nox_xxx_decay_511750()
	C.nox_server_checkVictory_509A60()
}

func (s *Server) nox_xxx_gameTick_4D2580_server_B(ticks uint64) bool {
	C.nox_xxx_updateServer_4D2DA0(C.longlong(ticks))
	nox_server_netMaybeSendInitialPackets_4DEB30()
	s.nox_xxx_netlist_4DEB50()
	if !mainloopContinue {
		return false
	}
	if gameFrame()%2 == 0 {
		C.nox_xxx_serverLoopSendMap_519990()
	}
	C.sub_40B970()
	C.sub_40B790()
	if !noxflags.HasGame(noxflags.GamePause) {
		s.updateUnits()
		C.sub_4EC720()
		if noxflags.HasGame(noxflags.GameModeQuest) {
			C.sub_50D890()
			C.sub_4E4170()
		}
		nox_xxx_spellBookReact_4FCB70()
		s.abilities.Update()
		s.noxScript.actRun()
		s.scriptTick()
		C.nox_xxx_voteUptate_506F30()
		C.nox_xxx_unitsUpdateDeletedList_4E5E20()
	}
	if err := s.updateRemotePlayers(); err != nil {
		gameLog.Println("update remote players:", err)
		return false
	}
	C.nox_xxx_unitsNewAddToList_4DAC00()
	if inputKeyCheckTimeoutLegacy(0x10, 10*gameFPS()) {
		s.objs.nox_xxx_protectUnitDefUpdateMB_4E3C20()
		inputSetKeyTimeoutLegacy(16)
	}
	if noxflags.HasGame(noxflags.GameOnline) && nox_xxx_check_flag_aaa_43AF70() == 1 && !noxflags.HasGame(noxflags.GameModeChat) && inputKeyCheckTimeoutLegacy(0xF, 60*gameFPS()) {
		C.nox_xxx_net_4263C0()
		inputSetKeyTimeoutLegacy(15)
	}
	return true
}

func sub_446040() uint32 {
	return dword_5d4594_825768
}

func (s *Server) nox_xxx_gameTick_4D2580_server_E() {
	if noxflags.HasEngine(noxflags.EngineReplayWrite | noxflags.EngineReplayRead) {
		C.sub_4E76C0()
	}
	if nox_xxx_gameGet_4DB1B0() != 0 {
		s.nox_xxx_gameTick_4D2580_server_D()
	}
	sub_4139C0()
	if nox_xxx_serverIsClosing446180() {
		sub_446190()
	}
	if sub_446030() && gameFrame() > 5*gameFPS()+sub_446040() {
		sub_446380()
	}
	if !noxflags.HasGame(noxflags.GamePause) {
		gameFrameInc()
	}
	C.nox_xxx_protectData_56F5C0()
	s.nox_server_xxxInitPlayerUnits_4FC6D0()
	s.maybeRegisterGameOnline() // TODO: not exactly the right place
	s.nox_xxx_mapInitialize_4FC590()
	s.nox_xxx_mapEntry_4FC600()
	s.abilities.sub_4FC680()
	if unit := s.getPlayerByInd(noxMaxPlayers - 1).UnitC(); unit != nil {
		C.nox_xxx_playerSomeWallsUpdate_5003B0(unit.CObj())
	}
	if nox_xxx_get_57AF20() != 0 && C.sub_57B140() {
		C.sub_57B0A0()
	}
	if s.nox_xxx_isQuest_4D6F50() {
		s.switchQuestIfRequested4D6FD0()
		sub_4DCF20()
	}
}

func nox_server_netMaybeSendInitialPackets_4DEB30() {
	if !noxflags.HasEngine(noxflags.EngineReplayRead) {
		C.nox_xxx_servNetInitialPackets_552A80(C.uint(memmap.Uint32(0x5D4594, 1563148)), 1)
	}
}

func (s *Server) nox_xxx_mapInitialize_4FC590() {
	if C.nox_xxx_resetMapInit_1569652 != 0 && s.hasPlayerUnits() {
		s.clearScriptTriggers()
		s.scriptOnEvent(script.EventMapInitialize)
		C.nox_xxx_resetMapInit_4FC570(0)
	}
}

func (s *Server) nox_xxx_mapEntry_4FC600() {
	if C.dword_5d4594_1569656 != 0 && s.hasPlayerUnits() {
		s.scriptOnEvent(script.EventMapEntry)
		C.sub_4FC580(0)
	}
}

func sub_416640() []byte {
	// TODO: size is a guess
	return unsafe.Slice((*byte)(memmap.PtrOff(0x5D4594, 371516)), 168)
}

func sub_416A00() bool {
	v0 := sub_416640()
	return (v0[100]>>4)&0x1 != 0
}

func sub_4169E0() {
	v0 := sub_416640()
	v0[100] |= 0x10
}

func sub_4169F0() {
	v0 := sub_416640()
	v0[100] &= 0xEF
}

func (s *Server) updateRemotePlayers() error {
	for _, pl := range s.getPlayers() {
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
			if uint32(pl.UnitC().Ind()) == DeadWord { // see #401
				pl.playerUnit = nil
				mainloopStop()
				return fmt.Errorf("player unit deleted (%s)", pl.Name())
			}
			C.nox_xxx_netUpdate_518EE0(pl.UnitC().CObj())
		}
		if pl.UnitC() == HostPlayerUnit() {
			C.nox_xxx_netImportant_4E5770(C.uchar(pl.Index()), 1)
		} else if C.dword_5d4594_2650652 == 0 || (gameFrame()%uint32(C.nox_xxx_rateGet_40A6C0()) == 0) || noxflags.HasGame(noxflags.GameFlag4) {
			C.nox_xxx_netSendReadPacket_5528B0(C.uint(pl.Index()+1), 0)
		}
	}
	return nil
}

func (s *Server) nox_xxx_servNewSession_4D1660() error {
	gameLog.Println("nox_xxx_servNewSession_4D1660")
	C.sub_4D15C0()
	C.dword_5d4594_2649712 = 0x80000000
	C.nox_xxx_host_player_unit_3843628 = nil
	C.sub_4D7B40()
	C.sub_41E4B0(0)
	s.ResetObjectScriptIDs()
	C.sub_56F1C0()
	s.resetAllPlayers()
	C.nox_netlist_resetAll_40EE60()
	C.sub_4E4EF0()
	C.sub_4E4ED0()
	if C.nox_xxx_allocAudEventArray_501860() == 0 {
		return errors.New("nox_xxx_allocAudEventArray_501860 failed")
	}
	if err := s.nox_read_things_alternative_4E2B60(); err != nil {
		return err
	}
	C.nox_motd_4463E0(1)
	s.teamsReset()
	C.sub_4259C0()
	C.sub_4D7C60()
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
	s.spells.Init(s)
	s.abilities.Reset()
	if err := nox_xxx_allocSpellRelatedArrays_4FC9B0(); err != nil {
		return err
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
		ind, nport, err := s.nox_xxx_netAddPlayerHandler_4DEBC0(s.getServerPort())
		*memmap.PtrInt32(0x5D4594, 1548516) = int32(ind)
		if err != nil {
			return err
		}
		s.setServerPort(nport)
	}
	if C.nox_xxx_allocPendingOwnsArray_516EE0() == 0 {
		return errors.New("nox_xxx_allocPendingOwnsArray_516EE0 failed")
	}
	C.sub_421B10()
	sub_4DB0A0()
	C.sub_4D0F30()
	srvPort := s.getServerPort()
	httpPort := inferHTTPPort(srvPort)
	if err := s.gameStartHTTP(httpPort); err != nil {
		return err
	}
	if isDedicatedServer || s.announce {
		if err := s.gameStartNAT(srvPort, httpPort); err != nil {
			return err
		}
	} else {
		s.gameStopNAT()
	}
	return nil
}

func (s *Server) nox_server_netCloseHandler_4DEC60(ind int) {
	s.nox_xxx_netStructReadPackets(ind)
	s.nox_server_netClose_5546A0(ind)
	C.nox_xxx_host_player_unit_3843628 = nil
	sub_43DE40(nil)
	s.gameStopNAT()
	s.gameStopHTTP()
}

func (s *Server) nox_xxx_servEndSession_4D3200() {
	s.ai.Free()
	sub_4DB100()
	C.sub_421B10()
	C.sub_516F10()
	C.sub_4FF770()
	s.nox_xxx_replayStopSave_4D33B0()
	s.nox_xxx_replayStopReadMB_4D3530()
	s.resetAllPlayers()
	C.sub_446490(1)
	C.sub_4259F0()
	C.nox_xxx_mapSwitchLevel_4D12E0(0)
	s.nox_xxx_mapLoad_40A380()
	C.sub_4E4DE0()
	s.debug.Reset()
	C.sub_57C030()
	s.springs.Reset()
	s.abilities.Free()
	s.spells.Free()
	nox_xxx_freeSpellRelated_4FCA80()
	C.sub_50ABF0()
	C.sub_517B30()
	C.sub_5018D0()
	C.sub_4ECA90()
	C.sub_506720()
	C.sub_50D820()
	C.nox_xxx_deleteShopInventories_50E300()
	C.sub_416950()
	C.nox_xxx_freeGameObjectClass_4E3420()
	s.objs.nox_xxx_freeObjectTypes_4E2A20()
	if !noxflags.HasGame(noxflags.GameModeCoop) {
		s.nox_server_netCloseHandler_4DEC60(int(memmap.Uint32(0x5D4594, 1548516)))
	}
	C.sub_56F3B0()
	C.nox_netlist_resetAll_40EE60()
	_ = ifs.Remove(datapath.Save("_temp_.dat"))
}

func sub_4D3C30() {
	C.nox_xxx_free_503F40()
	C.sub_51D0E0()
	C.sub_502DF0()
}

func (s *Server) nox_server_loadMapFile_4CF5F0(mname string, noCrypt bool) error {
	gameLog.Printf("loading map %q", mname)
	cntGameMap.WithLabelValues(filepath.Base(mname)).Inc()
	C.sub_481410()
	C.nox_xxx_unitsNewAddToList_4DAC00()
	C.nox_xxx_waypoint_5799C0()
	if mname == "" {
		return errors.New("empty map name")
	}
	if strings.ToLower(mname) == "#return" {
		mname = GoStringP(memmap.PtrOff(0x5D4594, 1523080))
	} else if strings.HasPrefix(mname, "#") {
		v3 := datapath.Data()
		C.sub_4D39F0(internCStr(v3))
		v13 := mname[1:]
		if i := strings.IndexByte(mname, '.'); i > 0 {
			v13 = v3[:i]
		}
		C.sub_4D42E0(internCStr(v13))
		v12 := fmt.Sprintf("$%s.map", v13)
		s.nox_xxx_gameSetMapPath_409D70(v12)
		if C.nox_xxx_mapGenStart_4D4320() == 0 {
			C.nox_xxx_mapSwitchLevel_4D12E0(1)
			return errors.New("nox_xxx_mapGenStart_4D4320 failed")
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
	if _, err := ifs.Stat(fname); err != nil {
		tname := strings.TrimSuffix(fname, filepath.Ext(mname)) + ".nxz"
		if _, err := ifs.Stat(tname); err != nil {
			return err
		}
		if C.nox_xxx_mapNxzDecompress_57BC50(internCStr(tname), internCStr(fname)) == 0 {
			return fmt.Errorf("cannot decompress map: %q", fname)
		}
	}
	v8 := s.getServerMap()
	nox_common_checkMapFile(v8)
	var err error
	if noCrypt {
		err = cryptFileOpen(fname, 1, -1)
	} else {
		err = cryptFileOpen(fname, 1, crypt.MapKey)
	}
	if err != nil {
		return err
	}
	crc, err := mapReadCryptHeader()
	if err != nil {
		cryptFileClose()
		return err
	}
	C.nox_xxx_mapSetCrcMB_409B10(C.int(crc))
	if err := s.nox_xxx_serverParseEntireMap_4CFCE0(); err != nil {
		cryptFileClose()
		gameLog.Println("server read map:", err)
		return err
	}
	s.noxScript.nox_xxx_scriptRunFirst_507290()
	cryptFileClose()
	if !noxflags.HasGame(noxflags.GameFlag22) {
		s.nox_xxx_mapReadSetFlags_4CF990()
		if nox_xxx_check_flag_aaa_43AF70() == 1 {
			C.sub_416690()
		}
		noxflags.UnsetGame(noxflags.GameSuddenDeath)
		C.sub_470680()
		C.sub_4D0550(internCStr(fname))
		C.sub_4161E0()
		if !noxflags.HasGame(noxflags.GameModeChat) {
			C.sub_4165F0(0, 1)
		}
	}
	StrCopyP(memmap.PtrOff(0x5D4594, 1523080), 1024, mname)
	return nil
}

func (s *Server) nox_server_xxxInitPlayerUnits_4FC6D0() {
	if C.nox_xxx_resetMapInit_1569652 != 1 && C.dword_5d4594_1569656 != 1 {
		return
	}
	if len(s.getPlayerUnits()) == 0 {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) {
		if s.nox_game_getQuestStage_4E3CC0() == 1 {
			C.nox_game_sendQuestStage_4D6960(255)
			C.sub_4D7440(1)
			C.sub_4D60B0()
		} else if !sub4D6F30() || C.sub_4D7430() != 0 {
			if C.sub_4D76F0() == 1 {
				C.sub_4D6880(255, 1)
				C.sub_4D76E0(0)
				C.sub_4D7440(1)
				C.sub_4D60B0()
			} else {
				fname := datapath.Save("_temp_.dat")
				for _, u := range s.getPlayerUnits() {
					ud := u.updateDataPlayer()
					plx := ud.Player()
					pi := plx.Index()
					if plx.field_4792 == 1 && ud.field_138 == 0 && nox_xxx_playerSaveToFile_41A140(fname, pi) {
						v5 := sub_419EE0(pi)
						nox_xxx_sendGauntlet_4DCF80(pi, 1)
						if !sub41CFA0(fname, pi) && !v5 {
							nox_xxx_sendGauntlet_4DCF80(pi, 0)
						}
						ifs.Remove(fname)
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
		s.nox_xxx_netMsgFadeBegin_4D9800(true, true)
	}
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeChat) {
		for _, u := range s.getPlayerUnits() {
			plx := u.ControllingPlayer()
			if plx.Index() != noxMaxPlayers-1 && plx.field_3680&1 == 0 {
				u.ApplyEnchant(ENCHANT_INVULNERABLE, 0, 5)
			}
		}
	}
}

//export nox_xxx_mapLoad_4D2450
func nox_xxx_mapLoad_4D2450(a1 *C.char) {
	noxServer.switchMap(GoString(a1))
}

func (s *Server) switchMap(fname string) {
	gameLog.Printf("switch map: %q", fname)
	ptr2408 := unsafe.Slice((*byte)(memmap.PtrOff(0x973F18, 2408)), 1464)

	var v5 [1464]byte
	copy(v5[:], ptr2408)

	name := fname
	if ext := filepath.Ext(fname); ext != "" {
		name = strings.TrimSuffix(name, ext)
	}
	name = strings.ToLower(name)
	nox_common_checkMapFile(name)
	C.sub_4CFDF0(C.int(memmap.Uint32(0x973F18, 3800)))
	copy(ptr2408, v5[:])
	C.dword_5d4594_1548524 = 1
	mname := fname
	if i := strings.IndexByte(fname, ':'); i >= 0 {
		s.mapSwitchWPName = mname[i+1:]
		mname = mname[:i]
	} else {
		s.mapSwitchWPName = ""
	}
	if C.sub_51A130() != 0 {
		C.nox_xxx_mapSendCancelAll_5198B0(0)
	}
	mname = strings.ToLower(mname)
	s.nox_xxx_gameSetMapPath_409D70(mname)
}

func nox_gameModeFromMapPtr(a1 unsafe.Pointer) noxflags.GameFlag {
	v := *(*uint32)(unsafe.Pointer(uintptr(a1) + 1392))
	if v&0x4 != 0 {
		return noxflags.GameModeArena
	}
	if v&0x20 != 0 {
		return noxflags.GameModeElimination
	}
	if v&0x8 != 0 {
		return noxflags.GameModeCTF
	}
	if v&0x10 != 0 {
		return noxflags.GameModeKOTR
	}
	if v&0x40 != 0 {
		return noxflags.GameModeFlagBall
	}
	if v&0x2 != 0 {
		return noxflags.GameModeQuest
	}
	if v&0x1 != 0 {
		return noxflags.GameModeSolo10
	}
	return noxflags.GameModeChat
}

//export nox_mapToGameFlags_4CFF50
func nox_mapToGameFlags_4CFF50(v C.int) C.int {
	return C.int(nox_mapToGameFlags(int(v)))
}

func nox_mapToGameFlags(v int) noxflags.GameFlag {
	var out noxflags.GameFlag
	if v&1 != 0 {
		out |= noxflags.GameModeSolo10
	}
	if v&2 != 0 {
		out |= noxflags.GameModeQuest
	}
	if v&4 != 0 {
		out |= noxflags.GameModeArena
	}
	if v&0x20 != 0 {
		out |= noxflags.GameModeElimination
	}
	if v&8 != 0 {
		out |= noxflags.GameModeCTF
	}
	if v&0x10 != 0 {
		out |= noxflags.GameModeKOTR
	}
	if v&0x40 != 0 {
		out |= noxflags.GameModeFlagBall
	}
	if v < 0 {
		out |= noxflags.GameModeChat
	}
	return out
}

func nox_xxx_mapGetTypeMB_4CFFA0(a1 unsafe.Pointer) noxflags.GameFlag {
	val := *(*int32)(unsafe.Pointer(uintptr(a1) + 1392))
	return nox_mapToGameFlags(int(val))
}

func (s *Server) nox_xxx_mapReadSetFlags_4CF990() {
	v0 := unsafe.Slice((*byte)(unsafe.Pointer(C.sub_4165B0())), 58)
	if noxflags.HasGame(noxflags.GameModeElimination) && (memmap.Int32(0x973F18, 3800) < 0 || (v0[53]&4 == 0)) {
		C.nox_xxx_ruleSetNoRespawn_40A5E0(0)
	}
	C.sub_455C10()
	C.sub_456050()
	if noxflags.HasGame(noxflags.GameModeQuest) && memmap.Int32(0x973F18, 3800) < 0 {
		sub_4D6B10(true)
		nox_server_teamsZzz_419030(1)
	}
	mapname := s.getServerMap()
	gameLog.Printf("checking map flags for %q", filepath.Base(mapname))
	if err := nox_common_checkMapFile(mapname); err != nil {
		gameLog.Println("check map file:", err)
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
		s.nox_xxx_createCoopTeam_417E10()
		noxflags.SetGame(noxflags.GameModeCoop)
	} else if vv&2 != 0 {
		gameLog.Println("setting quest mode")
		isChat := noxflags.HasGame(noxflags.GameModeChat)
		noxflags.UnsetGame(noxflags.GameModeMask)
		noxflags.SetGame(noxflags.GameModeQuest)
		if isChat {
			s.setupQuestGame()
		}
	} else if vv >= 0 {
		pmode := (*uint16)(unsafe.Pointer(uintptr(unsafe.Pointer(&v0[0])) + 52))
		if noxflags.GameFlag(*pmode)&mapType == 0 {
			*pmode = uint16(nox_gameModeFromMapPtr(memmap.PtrOff(0x973F18, 2408)) | noxflags.GameFlag(*pmode)&0xE80F)
		}
		if v0[52]&0x10 == 0 {
			C.nox_xxx_mapFindCrown_4CFC30()
		}
		mode := noxflags.GameFlag(*pmode)
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
				nox_xxx_spellDisable_424BB0(132)
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
		if s.teamCount() != 0 {
			C.nox_xxx_teamAssignFlags_418640()
			if !checkGameplayFlags(2) && !noxflags.HasGame(noxflags.GameFlag16) {
				C.nox_xxx_toggleAllTeamFlags_418690(1)
			}
		}
	}
}

//export nox_xxx_moveUpdateSpecial_517970
func nox_xxx_moveUpdateSpecial_517970(cunit *nox_object_t) {
	unit := asUnitC(cunit)
	C.sub_517870(cunit)
	if C.sub_517590(C.float(unit.new_x), C.float(unit.new_y)) != 0 {
		C.nox_xxx_unitCreateMissileSmth_517640(cunit)
	} else {
		if unit.Class().Has(object.ClassPlayer) {
			gameLog.Printf("attempting to delete player unit; stopping the map")
			mainloopStop()
			return
		}
		unit.Delete()
	}
}

func sub_4DB0A0() {
	questPlayerFile = ""
	dword_5d4594_1563044 = false
	dword_5d4594_1563048 = false
	dword_5d4594_1563080 = 0
	dword_5d4594_1563084 = nil
	dword_5d4594_1563088 = 0
	dword_5d4594_1563092 = 0
	C.dword_5d4594_1563096 = 0
	*memmap.PtrUint32(0x5D4594, 1563100) = 0
	noxServer.quest.mapName = ""
	dword_5d4594_1563064 = false
	questPlayerSet = false
}

//export nox_xxx_mapSwitchLevel_4D12E0_end
func nox_xxx_mapSwitchLevel_4D12E0_end() {
	C.sub_410730()
	C.nox_xxx_wallBreackableListClear_410810()
	C.nox_xxx_waypointDeleteAll_579DD0()
	C.nox_xxx_j_allocHitArray_511840()
	C.nox_xxx_decayDestroy_5117B0()
	noxServer.springs.Reset()
	noxServer.debug.Reset()
	C.sub_57C000()
	C.sub_510E50()
	C.sub_4D1610()
	C.sub_4EC5B0()
	C.sub_50E360()
	C.sub_50D7E0()
	C.sub_4E4F80()
	noxflags.UnsetGame(noxflags.GameFlag20)
}
