package legacy

/*
#include "nox_wchar.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__shell__noxworld.h"
#include "client__system__parsecmd.h"
#include "common__net_list.h"
#include "client__gui__guicon.h"
#include "client__gui__guisave.h"
#include "client__gui__guirank.h"
#include "client__gui__guisumn.h"
#include "client__gui__guiquit.h"
#include "client__gui__gui_ctf.h"
#include "client__gui__guitrade.h"
#include "client__gui__guiinput.h"
#include "client__shell__mainmenu.h"
#include "client__shell__selchar.h"
#include "client__shell__selcolor.h"
#include "server__network__playback.h"
#include "client__drawable__drawable.h"
#include "client__gui__guimeter.h"

int sub_4EDD70();
void sub_426060();
void sub_417160();
char* sub_4DB160();
void sub_4D2160();
void sub_4D22B0();
void sub_4D2230();
void sub_4DBA30(int a1);
void sub_50AFA0();
int sub_48C980();
void nox_console_sendSysOpPass_4409D0(wchar2_t* a1);
char* nox_xxx_getSomeMapName_4D0CF0();
int  nox_server_loadMapFile_4CF5F0(char* a1, int a2);
int nox_xxx_mapLoadRequired_4DCC80();
int  sub_4EF660(nox_object_t* a1p);
void  sub_500510(const char* a1);
int nox_xxx_guiChatIconLoad_445650();
int nox_xxx_loadGuides_427070();
void sub_41CAC0(char* a1, void* a2);

wchar2_t* nox_xxx_guiServerOptionsGetGametypeName_4573C0(short mode);
*/
import "C"
import (
	"context"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_GetEndgameDialog            func() string
	GameGetPlayState                    func() int
	ServerCheatGod                      func(enable bool)
	Nox_xxx_serverHost_43B4D0           func()
	Nox_xxx_netServerCmd_440950         func(id byte, cmd string)
	ExecConsoleCmd                      func(ctx context.Context, cmd string) bool
	Nox_xxx_gameIsNotMultiplayer_4DB250 func() bool
	Nox_xxx_gameSetSwitchSolo_4DB220    func(a1 int)
	Nox_xxx_gameIsSwitchToSolo_4DB240   func() bool
	Nox_xxx_gameSetWallsDamage_4E25A0   func(v int)
	GetDoDamageWalls                    func() bool
	Sub_41CC00                          func(s string)
	Nox_xxx_playerSendMOTD_4DD140       func(a1 ntype.PlayerInd)
	Nox_xxx_unitCanInteractWith_5370E0  func(obj1, obj2 *server.Object, a3 int) bool
)

func init() {
	gui.RegisterState(client.StateOptions, "Options", func() bool {
		return C.nox_game_showOptions_4AA6B0() != 0
	})
	gui.RegisterState(client.StateClassSelect, "ClassSelect", func() bool {
		return C.nox_game_showSelClass_4A4840() != 0
	})
	gui.RegisterState(client.StateColorSelect, "ColorSelect", func() bool {
		return C.nox_game_showSelColor_4A5D00() != 0
	})
	gui.RegisterState(client.StateServerList, "ServerList", func() bool {
		return C.nox_game_showGameSel_4379F0() != 0
	})
	gui.RegisterState(client.StateXxx, "StateXxx", func() bool {
		return C.nox_game_showGameSel_4379F0() != 0
	})
}

//export nox_xxx_gameGetPlayState_4356B0
func nox_xxx_gameGetPlayState_4356B0() int {
	return GameGetPlayState()
}

//export nox_xxx_GetEndgameDialog_578D80
func nox_xxx_GetEndgameDialog_578D80() *C.char {
	if s := Nox_xxx_GetEndgameDialog(); s != "" {
		return internCStr(s)
	}
	return nil
}

//export nox_xxx_set_god_4EF500
func nox_xxx_set_god_4EF500(v int) {
	ServerCheatGod(v != 0)
}

//export nox_xxx_serverHost_43B4D0
func nox_xxx_serverHost_43B4D0() {
	Nox_xxx_serverHost_43B4D0()
}

//export nox_xxx_netServerCmd_440950_empty
func nox_xxx_netServerCmd_440950_empty() {
	Nox_xxx_netServerCmd_440950(0, "")
}

//export nox_server_parseCmdText_443C80
func nox_server_parseCmdText_443C80(cstr *wchar2_t, _ int) int {
	cmd := GoWString(cstr)
	if cmd == "" {
		return 0
	}
	res := ExecConsoleCmd(context.Background(), cmd)
	return bool2int(res)
}

//export nox_xxx_gameIsNotMultiplayer_4DB250
func nox_xxx_gameIsNotMultiplayer_4DB250() int {
	return bool2int(Nox_xxx_gameIsNotMultiplayer_4DB250())
}

//export nox_xxx_gameSetSwitchSolo_4DB220
func nox_xxx_gameSetSwitchSolo_4DB220(a1 int) {
	Nox_xxx_gameSetSwitchSolo_4DB220(a1)
}

//export nox_xxx_gameIsSwitchToSolo_4DB240
func nox_xxx_gameIsSwitchToSolo_4DB240() int {
	return bool2int(Nox_xxx_gameIsSwitchToSolo_4DB240())
}

//export nox_xxx_mapTraceRay_535250
func nox_xxx_mapTraceRay_535250(a1 *C.float4, a2 *C.float2, a3 *C.int2, a4 C.char) int {
	p1 := (*types.Pointf)(unsafe.Pointer(&a1.field_0))
	p2 := (*types.Pointf)(unsafe.Pointer(&a1.field_8))
	outPos := (*types.Pointf)(unsafe.Pointer(a2))
	outGrid := (*image.Point)(unsafe.Pointer(a3))
	if GetServer().MapTraceRayAt(*p1, *p2, outPos, outGrid, server.MapTraceFlags(a4)) {
		return 1
	}
	return 0
}

//export nox_xxx_mapTraceObstacles_50B580
func nox_xxx_mapTraceObstacles_50B580(from *nox_object_t, a2 *C.float4) int {
	if GetServer().MapTraceObstacles(asObjectS(from), types.Pointf{
		X: float32(a2.field_0),
		Y: float32(a2.field_4),
	}, types.Pointf{
		X: float32(a2.field_8),
		Y: float32(a2.field_C),
	}) {
		return 1
	}
	return 0
}

//export sub_5178E0
func sub_5178E0(a1 int32, a2 unsafe.Pointer) {
	p := (*server.ObjectIndex)(a2)
	GetServer().S().Map.Sub5178E0(a1 != 0, p)
}

//export nox_xxx_waypointMapRegister_5179B0
func nox_xxx_waypointMapRegister_5179B0(a1p *nox_waypoint_t) {
	GetServer().S().Map.Nox_xxx_waypointMapRegister_5179B0(asWaypointS(a1p))
}

//export sub_517A70
func sub_517A70(a1p *nox_waypoint_t) {
	GetServer().S().Map.Sub517A70(asWaypointS(a1p))
}

//export sub_517B70
func sub_517B70(pos *C.float2, fnc unsafe.Pointer, data unsafe.Pointer) {
	if fnc == nil {
		return
	}
	GetServer().S().Map.Sub517B70(*(*types.Pointf)(unsafe.Pointer(pos)), func(it *server.Object) {
		ccall.CallVoidPtr2(fnc, it.CObj(), data)
	})
}

//export sub_517590
func sub_517590(x float32, y float32) int {
	return bool2int(GetServer().S().Map.ValidIndexPos(types.Ptf(x, y)))
}

//export sub_518740
func sub_518740(a1 *C.float2, a2 uint8) *nox_waypoint_t {
	return (*nox_waypoint_t)(GetServer().Sub_518460(*(*types.Pointf)(unsafe.Pointer(a1)), a2, true).C())
}

//export nox_xxx_getMissilesInCircle_518170
func nox_xxx_getMissilesInCircle_518170(pos *C.float2, r float32, fnc unsafe.Pointer, a4 *nox_object_t) {
	p := *(*types.Pointf)(unsafe.Pointer(pos))
	GetServer().S().Map.EachMissilesInCircle(p, r, func(it *server.Object) bool {
		ccall.CallVoidPtr2(fnc, it.CObj(), unsafe.Pointer(a4))
		return true
	})
}

//export nox_xxx_getUnitsInRectAdv_517ED0
func nox_xxx_getUnitsInRectAdv_517ED0(rect *C.float4, fnc unsafe.Pointer, data unsafe.Pointer) {
	r := *(*types.Rectf)(unsafe.Pointer(rect))
	GetServer().S().Map.EachObjAndMissileInRect(r, func(it *server.Object) bool {
		ccall.CallVoidPtr2(fnc, it.CObj(), data)
		return true
	})
}

//export nox_xxx_getUnitsInRect_517C10
func nox_xxx_getUnitsInRect_517C10(rect *C.float4, fnc unsafe.Pointer, data unsafe.Pointer) {
	r := *(*types.Rectf)(unsafe.Pointer(rect))
	GetServer().S().Map.EachObjInRect(r, func(it *server.Object) bool {
		ccall.CallVoidPtr2(fnc, it.CObj(), data)
		return true
	})
}

//export nox_xxx_unitsGetInCircle_517F90
func nox_xxx_unitsGetInCircle_517F90(pos *C.float2, r C.float, fnc unsafe.Pointer, data unsafe.Pointer) {
	p := *(*types.Pointf)(unsafe.Pointer(pos))
	GetServer().S().Map.EachObjInCircle(p, float32(r), func(it *server.Object) bool {
		ccall.CallVoidPtr2(fnc, it.CObj(), data)
		return true
	})
}

//export nox_xxx_gameSetWallsDamage_4E25A0
func nox_xxx_gameSetWallsDamage_4E25A0(v int) {
	Nox_xxx_gameSetWallsDamage_4E25A0(v)
}

//export nox_xxx_mapDamageUnitsAround_4E25B0
func nox_xxx_mapDamageUnitsAround_4E25B0(a1 *C.float, a2, a3 C.float, a4, a5 int, a6, a7 *nox_object_t) {
	cpos := unsafe.Slice(a1, 2)
	pos := types.Pointf{X: float32(cpos[0]), Y: float32(cpos[1])}
	GetServer().Nox_xxx_mapDamageUnitsAround(pos, float32(a2), float32(a3), int(a4), object.DamageType(a5), asObjectS(a6), ToObjS(a7), GetDoDamageWalls())
}

//export nox_game_addStateCode_43BDD0
func nox_game_addStateCode_43BDD0(code int) {
	GetClient().GameAddStateCode(gui.StateID(code))
}

//export nox_game_getStateCode_43BE10
func nox_game_getStateCode_43BE10() int {
	return int(GetClient().GameGetStateCode())
}

//export nox_game_decStateInd_43BDC0
func nox_game_decStateInd_43BDC0() {
	GetClient().GamePopState()
}

//export nox_game_switchStates_43C0A0
func nox_game_switchStates_43C0A0() int {
	return bool2int(GetClient().GameStateSwitch())
}

//export nox_xxx_wall_410160
func nox_xxx_wall_410160() {
	GetServer().S().Walls.Reset()
}

//export sub_4537F0
func sub_4537F0() {
	GetServer().Sub4537F0()
}

//export sub_41CC00
func sub_41CC00(cstr *C.char) {
	Sub_41CC00(GoString(cstr))
}

//export nox_xxx_playerSendMOTD_4DD140
func nox_xxx_playerSendMOTD_4DD140(a1 int) {
	Nox_xxx_playerSendMOTD_4DD140(ntype.PlayerInd(a1))
}

//export nox_xxx_unitCanInteractWith_5370E0
func nox_xxx_unitCanInteractWith_5370E0(a1, a2 *nox_object_t, a3 int) int {
	return bool2int(Nox_xxx_unitCanInteractWith_5370E0(asObjectS(a1), asObjectS(a2), a3))
}

func Nox_xxx_sMakeScorch_537AF0(pos types.Pointf, a2 int) {
	cpos, pfree := alloc.Make([]float32{}, 2)
	defer pfree()
	cpos[0] = pos.X
	cpos[1] = pos.Y
	C.nox_xxx_sMakeScorch_537AF0((*C.float)(unsafe.Pointer(&cpos[0])), C.int(a2))
}

func Nox_xxx_mapDamageToWalls_534FC0(rect image.Rectangle, pos types.Pointf, rad float32, dmg int, dtyp object.DamageType, who *server.Object) {
	crect, rfree := alloc.Make([]int32{}, 4)
	defer rfree()
	crect[0] = int32(rect.Min.X)
	crect[1] = int32(rect.Min.Y)
	crect[2] = int32(rect.Max.X)
	crect[3] = int32(rect.Max.Y)

	cpos, pfree := alloc.Make([]float32{}, 2)
	defer pfree()
	cpos[0] = pos.X
	cpos[1] = pos.Y

	C.nox_xxx_mapDamageToWalls_534FC0((*C.int4)(unsafe.Pointer(&crect[0])), unsafe.Pointer(&cpos[0]), C.float(rad), C.int(dmg), C.int(dtyp), who.CObj())
}

func Nox_xxx_getSomeMapName_4D0CF0() string {
	return GoString(C.nox_xxx_getSomeMapName_4D0CF0())
}

func Nox_server_gameSettingsUpdated_40A670() {
	C.nox_server_gameSettingsUpdated = 1
}

func Sub_43AF50() {
	Set_dword_5d4594_2650652(0)
}

func Nox_server_testTwoPointsAndDirection_4E6E50(p1 types.Pointf, dir int16, p2 types.Pointf) int {
	cp1, free1 := alloc.New(types.Pointf{})
	defer free1()
	cp2, free2 := alloc.New(types.Pointf{})
	defer free2()
	*cp1, *cp2 = p1, p2
	return int(C.nox_server_testTwoPointsAndDirection_4E6E50((*C.float2)(unsafe.Pointer(cp1)), C.int(dir), (*C.float2)(unsafe.Pointer(cp2))))
}

func Nox_xxx_mapLoadOrSaveMB_4DCC70(v int) {
	C.nox_xxx_mapLoadOrSaveMB_4DCC70(C.int(v))
}
func Sub_4165B0() unsafe.Pointer {
	return unsafe.Pointer(C.sub_4165B0())
}
func Sub_44E560() unsafe.Pointer {
	return unsafe.Pointer(C.sub_44E560())
}
func Nox_xxx_serverOptionsGetServername_40A4C0() string {
	return GoString(C.nox_xxx_serverOptionsGetServername_40A4C0())
}
func Nox_xxx_mapGetMapName_409B40() string {
	return GoString(C.nox_xxx_mapGetMapName_409B40())
}
func Nox_xxx_servGetPlrLimit_409FA0() int {
	return int(C.nox_xxx_servGetPlrLimit_409FA0())
}
func Nox_client_xxx_switchChatMap_43B510() {
	C.nox_client_xxx_switchChatMap_43B510()
}
func Nox_client_guiXxx_43A9D0() {
	C.nox_client_guiXxx_43A9D0()
}
func Sub_43B630() {
	C.sub_43B630()
}
func Sub_49FF20() {
	C.sub_49FF20()
}
func Sub_445450() {
	C.sub_445450()
}
func Sub_45DB90() {
	C.sub_45DB90()
}
func Nox_xxx_initTime_435570() {
	C.nox_xxx_initTime_435570()
}
func Nox_xxx_allocArrayHealthChanges_49A5F0() int {
	return int(C.nox_xxx_allocArrayHealthChanges_49A5F0())
}
func Nox_xxx_loadGuides_427070() int {
	return int(C.nox_xxx_loadGuides_427070())
}
func Sub_494F00() int {
	return int(C.sub_494F00())
}
func Nox_alloc_npcs() {
	C.nox_alloc_npcs()
}
func Nox_xxx_loadReflSheild_499360() int {
	return int(C.nox_xxx_loadReflSheild_499360())
}
func Sub_4960B0() int {
	return int(C.sub_4960B0())
}
func Nox_xxx_allocClassListFriends_495980() int {
	return int(C.nox_xxx_allocClassListFriends_495980())
}
func Sub_4958F0() {
	C.sub_4958F0()
}
func Sub_460380() {
	C.sub_460380()
}
func Nox_xxx_cliPrepareGameplay1_460E60() int {
	return int(C.nox_xxx_cliPrepareGameplay1_460E60())
}
func Nox_xxx_cliPrepareGameplay2_4721D0() {
	C.nox_xxx_cliPrepareGameplay2_4721D0()
}
func Sub_4951C0() {
	C.sub_4951C0()
}
func Nox_xxx_netGameSettings_4DEF00() {
	C.nox_xxx_netGameSettings_4DEF00()
}
func Nox_server_gameUnsetMapLoad_40A690() {
	C.nox_server_gameUnsetMapLoad_40A690()
}
func Sub_416650() int {
	return int(C.sub_416650())
}
func Sub_46DCC0() {
	C.sub_46DCC0()
}
func Sub_409B80() string {
	return GoString(C.sub_409B80())
}
func Sub_4DB160() string {
	return GoString(C.sub_4DB160())
}
func Sub_4EDD70() {
	C.sub_4EDD70()
}
func Sub_4573B0() {
	C.sub_4573B0()
}
func Sub_4264D0() {
	C.sub_4264D0()
}
func Sub_416690() {
	C.sub_416690()
}
func Sub_426060() {
	C.sub_426060()
}
func Sub_455C30() int {
	return int(C.sub_455C30())
}
func Sub_456070() int {
	return int(C.sub_456070())
}
func Nox_xxx_guiHealthManaInit_4714E0() int {
	return int(C.nox_xxx_guiHealthManaInit_4714E0())
}
func Nox_xxx_bookInit_45B9D0() int {
	return int(C.nox_xxx_bookInit_45B9D0())
}
func Sub_476E20() unsafe.Pointer {
	return unsafe.Pointer(C.sub_476E20())
}
func Sub_4BFAD0() int {
	return int(C.sub_4BFAD0())
}
func Nox_xxx_wndCreateInventoryMB_465E00() uint32 {
	return uint32(C.nox_xxx_wndCreateInventoryMB_465E00())
}
func Nox_game_initOptionsInGame_4ADAD0() int {
	return int(C.nox_game_initOptionsInGame_4ADAD0())
}
func Sub_48D000() int {
	return int(C.sub_48D000())
}
func Sub_4C3760() int {
	return int(C.sub_4C3760())
}
func Sub_4C09D0() int {
	return int(C.sub_4C09D0())
}
func Sub_478110() int {
	return int(C.sub_478110())
}
func Sub_49B3E0() int {
	return int(C.sub_49B3E0())
}
func Sub_4BFC90() int {
	return int(C.sub_4BFC90())
}
func Nox_gui_itemAmount_init_4BFEF0() int {
	return int(C.nox_gui_itemAmount_init_4BFEF0())
}
func Sub_4799A0() int {
	return int(C.sub_4799A0())
}
func Sub_46A730() unsafe.Pointer {
	return unsafe.Pointer(C.sub_46A730())
}
func Sub_4C3500() int {
	return int(C.sub_4C3500())
}
func Nox_xxx_guiDrawRank_46E870() uint32 {
	return uint32(C.nox_xxx_guiDrawRank_46E870())
}
func Nox_xxx_guiMotdLoad_4465C0() uint32 {
	return uint32(C.nox_xxx_guiMotdLoad_4465C0())
}
func Nox_xxx_guiSummonCreatureLoad_4C1D80() int {
	return int(C.nox_xxx_guiSummonCreatureLoad_4C1D80())
}
func Sub_4AB260() int {
	return int(C.sub_4AB260())
}
func Nox_xxx_guiChatIconLoad_445650() int {
	return int(C.nox_xxx_guiChatIconLoad_445650())
}
func Sub_4C3390() int {
	return int(C.sub_4C3390())
}
func Sub_48C980() int {
	return int(C.sub_48C980())
}
func Sub_4D22B0() {
	C.sub_4D22B0()
}
func Sub_459870() unsafe.Pointer {
	return unsafe.Pointer(C.sub_459870())
}
func Nox_xxx_gamePlayIsAnyPlayers_40A8A0() int {
	return int(C.nox_xxx_gamePlayIsAnyPlayers_40A8A0())
}
func Sub_40A250() {
	C.sub_40A250()
}
func Sub_4D2230() {
	C.sub_4D2230()
}
func Sub_50AFA0() {
	C.sub_50AFA0()
}
func Sub_50B520() {
	C.sub_50B520()
}
func Sub_4D2160() {
	C.sub_4D2160()
}
func Nox_xxx_mapLoadRequired_4DCC80() int {
	return int(C.nox_xxx_mapLoadRequired_4DCC80())
}
func Sub_40A970() {
	C.sub_40A970()
}
func Nox_gui_itemAmount_free_4C03E0() {
	C.nox_gui_itemAmount_free_4C03E0()
}
func Sub_4AE3B0() {
	C.sub_4AE3B0()
}
func Sub_48D450() {
	C.sub_48D450()
}
func Sub_4C4220() {
	C.sub_4C4220()
}
func Nox_xxx_closeP2PTradeWnd_4C12A0() {
	C.nox_xxx_closeP2PTradeWnd_4C12A0()
}
func Sub_4BFD10() {
	C.sub_4BFD10()
}
func Sub_49B490() {
	C.sub_49B490()
}
func Sub_478F80() {
	C.sub_478F80()
}
func Sub_479D10() {
	C.sub_479D10()
}
func Sub_4AB470() {
	C.sub_4AB470()
}
func Sub_4C34A0() {
	C.sub_4C34A0()
}
func Sub_445770() {
	C.sub_445770()
}
func Sub_456240() {
	C.sub_456240()
}
func Sub_455EE0() {
	C.sub_455EE0()
}
func Sub_4505E0() {
	C.sub_4505E0()
}
func Sub_46A860() {
	C.sub_46A860()
}
func Sub_467980() {
	C.sub_467980()
}
func Sub_460D50() {
	C.sub_460D50()
}
func Nox_xxx_guiServerOptionsGetGametypeName_4573C0(a1 noxflags.GameFlag) string {
	return GoWString(C.nox_xxx_guiServerOptionsGetGametypeName_4573C0(C.short(a1)))
}
func Sub_40A180(a1 noxflags.GameFlag) int {
	return int(C.sub_40A180(C.short(a1)))
}
func Nox_xxx_servGamedataGet_40A020(a1 int16) int {
	return int(C.nox_xxx_servGamedataGet_40A020(C.short(a1)))
}
func Sub_41D1A0(a1 int) {
	C.sub_41D1A0(C.int(a1))
}
func Nox_xxx_netPlayerIncomingServ_4DDF60(a1 int) {
	C.nox_xxx_netPlayerIncomingServ_4DDF60(C.int(a1))
}
func Nox_xxx_plrLoad_41A480(a1 string) int {
	str := CString(a1)
	defer StrFree(str)
	return int(C.nox_xxx_plrLoad_41A480(str))
}
func Sub_465DE0(a1 int) {
	C.sub_465DE0(C.int(a1))
}
func Sub_4E79B0(a1 int) {
	C.sub_4E79B0(C.int(a1))
}
func Nox_xxx_playerMakeDefItems_4EF7D0(a1 *server.Object, a2 int, a3 int) {
	C.nox_xxx_playerMakeDefItems_4EF7D0(C.int(uintptr(a1.CObj())), C.int(a2), C.int(a3))
}
func Nox_xxx_cliGamedataGet_416590(a1 int) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_cliGamedataGet_416590(C.int(a1)))
}
func Sub_4181F0(a1 int) {
	C.sub_4181F0(C.int(a1))
}
func Sub_4AB4A0(a1 int) {
	C.sub_4AB4A0(C.int(a1))
}
func Sub_4AB4D0(a1 int) {
	C.sub_4AB4D0(C.int(a1))
}
func Sub_4721A0(a1 int) {
	C.sub_4721A0(C.int(a1))
}
func Sub_460EA0(a1 int) {
	C.sub_460EA0(C.int(a1))
}
func Nox_window_set_visible_unk5(a1 int) {
	C.nox_window_set_visible_unk5(C.int(a1))
}
func Sub_45D500(a1 int) {
	C.sub_45D500(C.int(a1))
}
func Sub_455A00(a1 int) {
	C.sub_455A00(C.int(a1))
}
func Sub_455F10(a1 int) {
	C.sub_455F10(C.int(a1))
}
func Nox_xxx_mapFindPlayerStart_4F7AB0(a2 *server.Object) types.Pointf {
	cp, freeCp := alloc.New(C.float2{})
	defer freeCp()
	C.nox_xxx_mapFindPlayerStart_4F7AB0(cp, asObjectC(a2))
	return types.Pointf{
		X: float32(cp.field_0),
		Y: float32(cp.field_4),
	}
}
func Sub_500510(a1 string) {
	C.sub_500510(internCStr(a1))
}
func Nox_xxx_mapSwitchLevel_4D12E0(a1 int) {
	C.nox_xxx_mapSwitchLevel_4D12E0(C.int(a1))
}
func Sub_57A1E0(a1 unsafe.Pointer, a2 string, a3 unsafe.Pointer, a4 int, a5 noxflags.GameFlag) {
	C.sub_57A1E0((*C.int)(a1), internCStr(a2), (*C.int)(a3), C.char(a4), C.short(a5))
}
func Sub_57AAA0(a1 string, a2 *byte, a3 unsafe.Pointer) {
	C.sub_57AAA0(internCStr(a1), (*C.char)(unsafe.Pointer(a2)), (*C.int)(a3))
}
func Sub_4EF660(a1 *server.Object) {
	C.sub_4EF660(asObjectC(a1))
}
func Nox_xxx_resetMapInit_4FC570(a1 int) {
	C.nox_xxx_resetMapInit_4FC570(C.int(a1))
}
func Sub_4DBA30(a1 bool) {
	C.sub_4DBA30(C.int(bool2int(a1)))
}
func Sub_4FC580(a1 int) {
	C.sub_4FC580(C.int(a1))
}
func Nox_xxx_isUnit_4E5B50(a1 *server.Object) int {
	return int(C.nox_xxx_isUnit_4E5B50(asObjectC(a1)))
}
func Sub_4E5B80(a1 *server.Object) int {
	return int(C.sub_4E5B80(asObjectC(a1)))
}
func Sub_4E81D0(a1 *server.Object) {
	C.sub_4E81D0(asObjectC(a1))
}
func Sub_4D71E0(a1 int) {
	C.sub_4D71E0(C.int(a1))
}
func Sub_4D7280(a1 int, a2 int8) {
	C.sub_4D7280(C.int(a1), C.char(a2))
}
func Nox_xxx_mathPointOnTheLine_57C8A0(a1 *[4]float32, a2 *types.Pointf, a3 *types.Pointf) int {
	return int(C.nox_xxx_mathPointOnTheLine_57C8A0((*C.float4)(unsafe.Pointer(a1)), (*C.float2)(unsafe.Pointer(a2)), (*C.float2)(unsafe.Pointer(a3))))
}
func Sub_427980(a1 *[4]float32, a2 *[4]float32) int {
	return int(C.sub_427980((*C.float4)(unsafe.Pointer(a1)), (*C.float4)(unsafe.Pointer(a2))))
}
func Nox_xxx_calcDistance_4E6C00(a1 *server.Object, a2 *server.Object) float32 {
	return float32(C.nox_xxx_calcDistance_4E6C00(asObjectC(a1), asObjectC(a2)))
}
func Sub_415CD0(a1 int) int {
	return int(C.sub_415CD0(C.int(a1)))
}
func Sub_415840(a1 int) int {
	return int(C.sub_415840(C.int(a1)))
}
func Get_nox_game_switchStates_43C0A0() unsafe.Pointer {
	return C.nox_game_switchStates_43C0A0
}
func Get_nox_game_showOptions_4AA6B0() unsafe.Pointer {
	return C.nox_game_showOptions_4AA6B0
}
func Get_nox_game_showMainMenu_4A1C00() unsafe.Pointer {
	return C.nox_game_showMainMenu_4A1C00
}
func Sub_41CAC0(a1 string, data []byte) {
	C.sub_41CAC0(internCStr(a1), unsafe.Pointer(&data[0]))
}
func Nox_xxx_unitCanSee_536FB0(obj1, obj2 *server.Object, a3 int) bool {
	return C.nox_xxx_unitCanSee_536FB0(asObjectC(obj1), asObjectC(obj2), C.char(a3)) != 0
}
