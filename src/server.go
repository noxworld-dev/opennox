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
#include "client__gui__guiquit.h"
#include "common__system__team.h"
#include "server__system__server.h"
#include "server__script__script.h"
#include "server__script__activator.h"
#include "common__magic__speltree.h"
#include "common__net_list.h"
#include "common__crypt.h"
#include "common__log.h"

extern unsigned int nox_xxx_resetMapInit_1569652;
extern unsigned int dword_5d4594_1569656;
extern unsigned int dword_5d4594_2650652;
extern unsigned int dword_5d4594_2649712;
extern unsigned int dword_5d4594_1548524;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
extern uint32_t dword_5d4594_1563096;
extern uint32_t dword_5d4594_528252;
extern uint32_t dword_5d4594_528260;
extern uint32_t dword_5d4594_2488604;

void nox_xxx_abilUpdateMB_4FBEE0();
char* nox_server_updateRemotePlayers_4DEC80();
void nox_xxx_netlist_4DEB50();
//void nox_script_activatorRun_51ADF0();
void nox_xxx_serverLoopSendMap_519990();
void nox_xxx_unitsUpdateDeletedList_4E5E20();
void nox_xxx_updateUnits_51B100();
void nox_xxx_voteUptate_506F30();
void sub_4E4170();
void sub_4EC720();
unsigned int sub_50D890();
void nox_xxx_gameTick_4D2580_server_D();
int  nox_xxx_playerSomeWallsUpdate_5003B0(nox_object_t* obj);
int nox_xxx_netUpdateObjectSpecial_527E50(nox_object_t* a1p, nox_object_t* a2p);
void sub_4139C0();
int sub_4DCF20();
int sub_4E76C0();
bool sub_57B140();
nox_object_t* sub_537700();

void nox_xxx_updateUnits_51B100_A();
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

	"github.com/noxworld-dev/nat"
	"github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/cnxz"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_xxx_servStartCountdown_40A2A0
func nox_xxx_servStartCountdown_40A2A0(a1 C.int, a2 *C.char) {
	noxServer.servStartCountdown(int(a1), strman.ID(GoString(a2)))
}

//export sub_40A040_settings
func sub_40A040_settings(a1 C.short, a2 C.uchar) {
	noxServer.sub40A040settings(int(a1), int(a2))
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
	return C.int(noxServer.ServerPort())
}

//export sub_40A1A0
func sub_40A1A0() C.int {
	return C.int(bool2int((C.sub_40A180(C.short(noxflags.GetGame())) != 0 || noxServer.flag3592) &&
		memmap.Uint32(0x587000, 4660) != 0 &&
		platformTicks() > memmap.Uint64(0x5D4594, 3468)))
}

//export sub_40A300
func sub_40A300() C.int {
	return C.int(bool2int(noxServer.flag3592))
}

//export nox_xxx_mapLoad_4D2450
func nox_xxx_mapLoad_4D2450(a1 *C.char) {
	noxServer.switchMap(GoString(a1))
}

//export nox_mapToGameFlags_4CFF50
func nox_mapToGameFlags_4CFF50(v C.int) C.int {
	return C.int(nox_mapToGameFlags(int(v)))
}

var (
	noxServer *Server
	useNAT    = true
)

func init() {
	nat.Log = log.New("nat")
	nat.LogUPNP = log.New("nat-upnp")
	configBoolPtr("network.port_forward", "NOX_NET_NAT", true, &useNAT)
}

func NewServer(pr console.Printer, sm *strman.StringManager) *Server {
	s := &Server{
		Server: server.New(pr, sm),
	}
	s.allocTeams()
	s.initPlayers()
	s.initMetrics()
	s.abilities.Init(s)
	s.ai.Init(s)
	s.noxScript.Init(s)
	return s
}

type Server struct {
	*server.Server
	players         serverPlayers
	ctrlbuf         serverCtrlBuf
	spells          serverSpells
	abilities       serverAbilities
	srvReg          srvReg
	scriptEvents    scriptEvents
	noxScript       noxScript
	vms             scriptVMs
	teams           serverTeams
	ai              aiData
	quest           questServer
	springs         serverSprings
	mapGroups       serverMapGroups
	mapSwitchWPName string
	announce        bool

	flag1548704 bool
	flag3592    bool

	dword_5d4594_2386928 float32
	dword_5d4594_2386948 *Waypoint
	dword_5d4594_2386960 uint32
}

//export gameFPS
func gameFPS() uint32 {
	return noxServer.TickRate()
}

//export gameFrame
func gameFrame() uint32 {
	return noxServer.Frame()
}

func (s *Server) Update() bool {
	defer noxPerfmon.startProfileServer()()
	if !s.Server.Update() {
		if debugMainloop {
			gameLog.Println("gameStateFunc exit")
		}
		return false
	}
	return true
}

func (s *Server) updateUnits() { // nox_xxx_updateUnits_51B100
	s.updateUnitsAAA()
	s.updateUnitsBBB()
	s.updateUnitsCallUpdate()
	s.updateCollide()
	s.updateUnitsCCC()
	C.nox_xxx_updateUnits_51B100_D()
	C.nox_xxx_decay_511750()
	C.nox_server_checkVictory_509A60()
}

func (s *Server) updateCollide() {
	C.nox_xxx_allocHitArray_5486D0()
	for i := 0; i < 5; i++ {
		C.nox_xxx_updateObjectsVelocity_5118A0(0.2)
		C.sub_548B60()
	}
	for C.dword_5d4594_2488604 != 0 {
		obj := asObjectC(C.sub_537700())
		if int8(uint8(obj.Class())) >= 0 {
			s.Objs.AddToUpdatable(obj.SObj())
		}
	}
	C.nox_xxx_collide_548740()
}

func (s *Server) updateUnitsCCC() {
	for obj := asObjectS(s.Objs.UpdatableList); obj != nil; obj = asObjectS(obj.UpdatableNext) {
		obj.PrevPos = obj.PosVec
		obj.PosVec = obj.NewPos
		obj.ForceVec = types.Pointf{}

		obj.Direction1 = obj.Direction2
		if obj.Field541 > 4 {
			obj.Field541 = 4
		}
		obj.SpeedCur = (obj.SpeedBonus + obj.SpeedBase) * (1 - 0.2*float32(obj.Field541))
		if obj.HasEnchant(server.ENCHANT_SLOWED) {
			obj.SpeedCur *= 0.5
		}
		if obj.Field541 != 0 || obj.Field540 != 0 {
			if obj.Field542 > 0 {
				obj.Field542--
				if obj.Field542 == 0 {
					if obj.Field541 != 0 {
						obj.Field541--
					}
					if obj.Field540 != 0 && !obj.Flags().Has(object.FlagDead) {
						C.nox_xxx_updatePoison_4EE8F0(obj.CObj(), 1)
					}
					obj.Field542 = 1000
				}
			}
		}
		C.nox_xxx_updateUnitBuffs_4FF620(obj.CObj())
		if v31 := obj.Field540; v31 != 0 {
			if h := obj.HealthData; h != nil && h.Max > 0 && h.Cur > 0 {
				dmg := 1
				if noxflags.HasGame(noxflags.GameModeQuest) {
					dmg += 1
				}
				if h.Field16 == 0 || (noxServer.Frame()-h.Field16) > 60 {
					if v31 > 8 || noxServer.Frame()%uint32(128>>(v31-1)) == 0 {
						obj.CallDamage(nil, nil, dmg, object.DamagePoison)
					}
				}
			}
		}
	}
}

func (s *Server) nox_xxx_updateServer_4D2DA0(a1 uint64) {
	if C.dword_5d4594_528252 == 1 && s.Frame() == uint32(C.dword_5d4594_528260) {
		C.nox_xxx_reconAttempt_41E390()
	}
	C.sub_5096F0()
	if noxflags.HasGame(noxflags.GameFlag4) {
		return
	}
	if noxflags.HasGame(noxflags.GameOnline) {
		C.sub_416720()
		if !noxflags.HasGame(noxflags.GameModeChat) {
			if C.sub_409F40(0x2000) != 0 {
				C.sub_4D7CC0()
			}
		}
	}
	if noxflags.HasGame(noxflags.GameModeElimination) {
		if C.sub_40AA00() != 0 {
			if !s.flag1548704 {
				s.sub_4D2FF0()
			}
		} else {
			s.flag1548704 = false
		}
		if !noxflags.HasGame(noxflags.GameSuddenDeath) && !s.flag3592 {
			for pl := s.playerFirst(); pl != nil; pl = s.playerNext(pl) {
				if int(pl.field_2140) > 0 {
					if C.sub_40AA00() == 0 {
						break
					}
					if checkGameplayFlags(4) {
						if s.teamCount() >= int(C.sub_40AA40()) {
							break
						}
						for tm := s.firstTeam(); tm != nil; tm = s.nextTeam(tm) {
							if C.nox_xxx_countNonEliminatedPlayersInTeam_40A830(tm.C()) == 1 {
								s.servStartCountdown(int(gamedataFloat("SuddenDeathCountdown")), "Settings.c:SuddenDeathImminent")
								break
							}
						}
					} else {
						if C.sub_40A770() < C.sub_40AA40() {
							s.servStartCountdown(int(gamedataFloat("SuddenDeathCountdown")), "Settings.c:SuddenDeathImminent")
						}
					}
					break
				}
			}
		}
	}
	if C.sub_40A6B0() != 0 {
		v8 := sub_416640()
		s.printCompToAll(int(*(*uint32)(unsafe.Pointer(&v8[66]))))
		C.sub_40A6A0(0)
	}
	if (a1 - *memmap.PtrUint64(0x5D4594, 1548692)) > 0x1F4 {
		C.nox_xxx_netReportAllLatency_4D3050()
		*memmap.PtrUint64(0x5D4594, 1548692) = a1
	}
	if noxflags.HasGame(noxflags.GameModeChat) && C.sub_40A740() == 0 && s.teamCount() != 0 && !checkGameplayFlags(2) {
		C.sub_4183C0()
	}
	if noxflags.HasGame(noxflags.GameModeQuest) {
		C.sub_4D7150()
		C.sub_4D71F0()
		C.nox_server_checkWarpGate_4D7600()
		sub_4DCE00()
		C.sub_4D7A80()
	}
}

func (s *Server) printCompToAll(i int) {
	switch i {
	case 0:
		s.netPrintLineToAll("report.c:NoComp")
	case 1:
		s.netPrintLineToAll("report.c:MinComp")
	case 2:
		s.netPrintLineToAll("report.c:AveComp")
	case 3:
		s.netPrintLineToAll("report.c:UserComp")
	}
}

func (s *Server) sub_4D2FF0() {
	if C.sub_40AA70(nil) != 0 {
		s.flag1548704 = true
		return
	}
	for pl := s.playerFirst(); pl != nil; pl = s.playerNext(pl) {
		if pl.field_3680&1 != 0 {
			C.nox_xxx_netNeedTimestampStatus_4174F0(pl.C(), 256)
		}
	}
	s.flag1548704 = true
}

func (s *Server) servStartCountdown(sec int, id strman.ID) { // nox_xxx_servStartCountdown_40A2A0
	*memmap.PtrUint64(0x5D4594, 3468) = platformTicks() + 1000*uint64(sec)
	C.sub_40A1F0(1)
	if id != "" {
		s.netPrintLineToAll(id)
	}
	s.flag3592 = true
}

func (s *Server) sub40A040settings(a1 int, min int) {
	v2 := C.sub_409A70(C.short(a1))
	if memmap.Uint8(0x5D4594, 3500+uintptr(v2)) == byte(min) {
		return
	}
	if !(!noxflags.HasGame(noxflags.GameSuddenDeath) && !s.flag3592) {
		str := s.Strings().GetStringInFile("NotInSuddenDeath", "settings.c")
		nox_xxx_printCentered_445490(str)
		return
	}
	nox_server_gameSettingsUpdated_40A670()
	if nox_client_isConnected() {
		if min == 0 {
			str := s.Strings().GetStringInFile("parsecmd.c:timedisabled", "settings.c")
			nox_xxx_printCentered_445490(str)
		} else {
			str := s.Strings().GetStringInFile("parsecmd.c:timeset", "settings.c")
			nox_xxx_printCentered_445490(fmt.Sprintf(str, min))
			if C.nox_xxx_gamePlayIsAnyPlayers_40A8A0() == 0 {
				str := s.Strings().GetStringInFile("TimeLimitDeferred", "settings.c")
				nox_xxx_printCentered_445490(str)
			}
		}
	}
	*memmap.PtrUint8(0x5D4594, 3500+uintptr(v2)) = byte(min)
	*memmap.PtrUint64(0x5D4594, 3468) = platformTicks() + 60000*uint64(min)
}

func (s *Server) nox_xxx_gameTick_4D2580_server_B(ticks uint64) bool {
	s.nox_xxx_updateServer_4D2DA0(ticks)
	nox_server_netMaybeSendInitialPackets_4DEB30()
	s.nox_xxx_netlist_4DEB50()
	if !mainloopContinue {
		return false
	}
	if s.Frame()%2 == 0 {
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
		s.deletedObjectsUpdate()
	}
	if err := s.updateRemotePlayers(); err != nil {
		gameLog.Println("update remote players:", err)
		return false
	}
	s.objectsNewAdd()
	if inputKeyCheckTimeoutLegacy(0x10, 10*s.TickRate()) {
		s.ProtectTypeCheck()
		inputSetKeyTimeoutLegacy(16)
	}
	if noxflags.HasGame(noxflags.GameOnline) && false && !noxflags.HasGame(noxflags.GameModeChat) && inputKeyCheckTimeoutLegacy(0xF, 60*s.TickRate()) {
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
	if sub_446030() && s.Frame() > 5*s.TickRate()+sub_446040() {
		sub_446380()
	}
	if !noxflags.HasGame(noxflags.GamePause) {
		s.IncFrame()
	}
	C.nox_xxx_protectData_56F5C0()
	s.nox_server_xxxInitPlayerUnits_4FC6D0()
	s.maybeRegisterGameOnline() // TODO: not exactly the right place
	s.nox_xxx_mapInitialize_4FC590()
	s.nox_xxx_mapEntry_4FC600()
	s.abilities.sub_4FC680()
	if unit := s.getPlayerByInd(common.MaxPlayers - 1).UnitC(); unit != nil {
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
		nox_xxx_servNetInitialPackets_552A80(netstr.GetInitInd(), 1)
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
		if s.Frame()-uint32(pl.frame_3596) > uint32(fr)*s.TickRate() {
			m := uint32(pl.netCode)
			// TODO: passing Go pointer
			C.nox_xxx_netInformTextMsg2_4DA180(3, (*C.uchar)(unsafe.Pointer(&m)))
			var buf [1]byte
			buf[0] = byte(noxnet.MSG_TIMEOUT_NOTIFICATION)
			netstr.Send(pl.Index()+1, buf[:], netstr.SendNoLock|netstr.SendFlagFlush)
			pl.Disconnect(3)
		}
		if pl.field_3680&0x80 != 0 {
			pl.Disconnect(4)
		}
		if (pl.field_3676 != 3) || (pl.field_3680&0x10 == 0) {
			var buf [3]byte
			buf[0] = byte(noxnet.MSG_TIMESTAMP)
			binary.LittleEndian.PutUint16(buf[1:], uint16(s.Frame()))
			netlist.AddToMsgListCli(pl.Index(), netlist.Kind1, buf[:])
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
		} else if C.dword_5d4594_2650652 == 0 || (s.Frame()%uint32(nox_xxx_rateGet_40A6C0()) == 0) || noxflags.HasGame(noxflags.GameFlag4) {
			netstr.SendReadPacket(pl.Index()+1, 0)
		}
	}
	return nil
}

func (s *Server) sub_4172C0(pind int) *Object {
	if pind < 0 && pind >= common.MaxPlayers {
		return nil
	}
	pl := s.players.list[pind]
	if pl.field_4580 == nil {
		return nil
	}
	p := *(**nox_object_t)(unsafe.Add(pl.field_4580, 4))
	pl.field_4580 = *(*unsafe.Pointer)(unsafe.Add(pl.field_4580, 8))
	return asObjectC(p)
}

//export sub_519760
func sub_519760(u *nox_object_t, rect *C.float) {
	noxServer.sub519760(asUnitC(u), *(*types.Rectf)(unsafe.Pointer(rect)))
}

func (s *Server) sub519760(u *Unit, rect types.Rectf) {
	ud := u.UpdateDataPlayer()
	pl := asPlayerS(ud.Player)
	pind := pl.Index()
	obj := s.sub_4172C0(pind)
	if obj == nil {
		return
	}
	if obj.Flags().Has(object.FlagDestroyed) {
		s.nox_xxx_netMinimapUnmark4All_417430(obj)
	} else if float64(obj.PosVec.X) < float64(rect.Left) || float64(obj.PosVec.X) > float64(rect.Right) || float64(obj.PosVec.Y) < float64(rect.Top) || float64(obj.PosVec.Y) > float64(rect.Bottom) {
		obj.Field38 |= uint32(1 << pind)
		C.nox_xxx_netSendObjects2Plr_519410(u.CObj(), obj.CObj())
		C.nox_xxx_netReportUnitHeight_4D9020(C.int(pind), obj.CObj())
		ud.Field67 = s.Frame()
	}
}

func (s *Server) nox_xxx_netMinimapUnmark4All_417430(obj *Object) {
	for pl := s.playerFirst(); pl != nil; pl = s.playerNext(pl) {
		C.nox_xxx_netUnmarkMinimapObj_417300(C.int(pl.Index()), obj.CObj(), 3)
	}
}

//export nox_xxx_unitAroundPlayerFn_5193B0
func nox_xxx_unitAroundPlayerFn_5193B0(it *nox_object_t, u *nox_object_t) {
	noxServer.nox_xxx_unitAroundPlayerFn5193B0(asObjectC(it), asUnitC(u))
}

func (s *Server) nox_xxx_unitAroundPlayerFn5193B0(it *Object, u *Unit) {
	ud := u.UpdateDataPlayer()
	pl := asPlayerS(ud.Player)
	if u.SObj() == it.SObj() {
		C.nox_xxx_netUpdateObjectSpecial_527E50(u.CObj(), it.CObj())
		if pl.field_3680&0x1 == 0 {
			return
		}
	}
	if !noxflags.HasGame(noxflags.GameOnline) || ud.Field68 != s.Frame() {
		C.nox_xxx_netSendObjects2Plr_519410(u.CObj(), it.CObj())
	}
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
	netlist.ResetAll()
	C.sub_4E4EF0()
	C.sub_4E4ED0()
	s.Audio.Init()
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
	if !s.Objs.Init(5000) {
		return errors.New("nox_xxx_allocClassArrayObjects_4E3360 failed")
	}
	s.Server.Map.Init()
	if C.nox_xxx_allocVisitNodesArray_50AB90() == 0 {
		return errors.New("nox_xxx_allocVisitNodesArray_50AB90 failed")
	}
	s.spells.Init(s)
	s.abilities.Reset()
	if err := nox_xxx_allocSpellRelatedArrays_4FC9B0(); err != nil {
		return err
	}
	s.mapGroups.Init()
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
		ind, nport, err := s.nox_xxx_netAddPlayerHandler_4DEBC0(s.ServerPort())
		*memmap.PtrInt32(0x5D4594, 1548516) = int32(ind)
		if err != nil {
			return err
		}
		s.SetServerPort(nport)
	}
	if C.nox_xxx_allocPendingOwnsArray_516EE0() == 0 {
		return errors.New("nox_xxx_allocPendingOwnsArray_516EE0 failed")
	}
	C.sub_421B10()
	sub_4DB0A0()
	C.sub_4D0F30()
	if err := s.StartHTTP(); err != nil {
		return err
	}
	if isDedicatedServer || s.announce {
		if err := s.StartNAT(); err != nil {
			return err
		}
	} else {
		s.StopNAT()
	}
	return nil
}

func (s *Server) StartNAT() error {
	if !useNAT || !noxflags.HasGame(noxflags.GameOnline) || env.IsE2E() {
		return nil
	}
	return s.Server.StartNAT()
}

func (s *Server) nox_server_netCloseHandler_4DEC60(ind int) {
	netstr.ReadPackets(ind)
	s.nox_server_netClose_5546A0(ind)
	C.nox_xxx_host_player_unit_3843628 = nil
	sub_43DE40(nil)
	s.StopNAT()
	s.StopHTTP()
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
	s.Map.Debug.Reset()
	s.mapGroups.Free()
	s.springs.Reset()
	s.abilities.Free()
	s.spells.Free()
	nox_xxx_freeSpellRelated_4FCA80()
	C.sub_50ABF0()
	s.Map.Free()
	s.Audio.Free()
	C.sub_4ECA90()
	C.sub_506720()
	C.sub_50D820()
	C.nox_xxx_deleteShopInventories_50E300()
	C.sub_416950()
	s.Objs.FreeObjects()
	s.FreeObjectTypes()
	nox_xxx_free_42BF80()
	if !noxflags.HasGame(noxflags.GameModeCoop) {
		s.nox_server_netCloseHandler_4DEC60(int(memmap.Uint32(0x5D4594, 1548516)))
	}
	C.sub_56F3B0()
	netlist.ResetAll()
	_ = ifs.Remove(datapath.Save("_temp_.dat"))
}

func sub_4D3C30() {
	noxServer.nox_xxx_free503F40()
	C.sub_51D0E0()
	C.sub_502DF0()
}

func (s *Server) nox_server_loadMapFile_4CF5F0(mname string, noCrypt bool) error {
	gameLog.Printf("loading map %q", mname)
	cntGameMap.WithLabelValues(filepath.Base(mname)).Inc()
	C.sub_481410()
	s.objectsNewAdd()
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
		zname := strings.TrimSuffix(fname, filepath.Ext(mname)) + ".nxz"
		if _, err := ifs.Stat(zname); err != nil {
			return err
		}
		if err := cnxz.DecompressFile(zname, fname); err != nil {
			return fmt.Errorf("cannot decompress map %q: %w", zname, err)
		}
	}
	v8 := s.getServerMap()
	nox_common_checkMapFile(v8)
	ckey := crypt.MapKey
	if noCrypt {
		ckey = -1
	}
	err := cryptfile.OpenGlobal(fname, cryptfile.ReadOnly, ckey)
	if err != nil {
		return err
	}
	cf := cryptfile.Global()
	crc, err := mapReadCryptHeader(cf)
	if err != nil {
		cryptfile.Close()
		return err
	}
	nox_xxx_mapSetCrcMB_409B10(crc)
	if err := s.nox_xxx_serverParseEntireMap_4CFCE0(cf); err != nil {
		cryptfile.Close()
		gameLog.Println("server read map:", err)
		return err
	}
	s.noxScript.nox_xxx_scriptRunFirst_507290()
	cryptfile.Close()
	if !noxflags.HasGame(noxflags.GameFlag22) {
		s.nox_xxx_mapReadSetFlags_4CF990()
		if false {
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
					ud := u.UpdateDataPlayer()
					plx := asPlayerS(ud.Player)
					pi := plx.Index()
					if plx.field_4792 == 1 && ud.Field138 == 0 && nox_xxx_playerSaveToFile_41A140(fname, pi) {
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
			if plx.Index() != common.MaxPlayers-1 && plx.field_3680&1 == 0 {
				u.ApplyEnchant(server.ENCHANT_INVULNERABLE, 0, 5)
			}
		}
	}
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
	s := noxServer
	unit := asUnitC(cunit)
	C.sub_517870(cunit)
	if s.Map.ValidIndexPos(unit.NewPos) {
		s.Map.AddMissileXxx(unit.SObj())
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
	s := noxServer
	C.sub_410730()
	C.nox_xxx_wallBreackableListClear_410810()
	C.nox_xxx_waypointDeleteAll_579DD0()
	C.nox_xxx_j_allocHitArray_511840()
	C.nox_xxx_decayDestroy_5117B0()
	s.springs.Reset()
	s.Map.Debug.Reset()
	s.mapGroups.Reset()
	C.sub_510E50()
	C.sub_4D1610()
	C.sub_4EC5B0()
	C.sub_50E360()
	C.sub_50D7E0()
	C.sub_4E4F80()
	noxflags.UnsetGame(noxflags.GameFlag20)
}
