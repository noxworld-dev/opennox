package legacy

import (
	"context"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
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
)

func init() {
	gui.RegisterState(client.StateOptions, "Options", func() bool {
		return Nox_game_showOptions_4AA6B0() != 0
	})
	gui.RegisterState(client.StateClassSelect, "ClassSelect", func() bool {
		return Nox_game_showSelClass_4A4840() != 0
	})
	gui.RegisterState(client.StateColorSelect, "ColorSelect", func() bool {
		return nox_game_showSelColor_4A5D00() != 0
	})
	gui.RegisterState(client.StateServerList, "ServerList", func() bool {
		return Nox_game_showGameSel_4379F0() != 0
	})
	gui.RegisterState(client.StateXxx, "StateXxx", func() bool {
		return Nox_game_showGameSel_4379F0() != 0
	})
}

// nox_xxx_gameGetPlayState_4356B0
func nox_xxx_gameGetPlayState_4356B0() int {
	return GameGetPlayState()
}

// nox_xxx_GetEndgameDialog_578D80
func nox_xxx_GetEndgameDialog_578D80() *byte {
	if s := Nox_xxx_GetEndgameDialog(); s != "" {
		return internCStr(s)
	}
	return nil
}

// nox_xxx_set_god_4EF500
func nox_xxx_set_god_4EF500(v int) {
	ServerCheatGod(v != 0)
}

// nox_xxx_serverHost_43B4D0
func nox_xxx_serverHost_43B4D0() {
	Nox_xxx_serverHost_43B4D0()
}

// nox_xxx_netServerCmd_440950_empty
func nox_xxx_netServerCmd_440950_empty() {
	Nox_xxx_netServerCmd_440950(0, "")
}

// nox_server_parseCmdText_443C80
func nox_server_parseCmdText_443C80(cstr *wchar2_t, _ int) int {
	cmd := GoWString(cstr)
	if cmd == "" {
		return 0
	}
	res := ExecConsoleCmd(context.Background(), cmd)
	return bool2int(res)
}

// nox_xxx_gameIsNotMultiplayer_4DB250
func nox_xxx_gameIsNotMultiplayer_4DB250() int32 {
	return bool2int32(Nox_xxx_gameIsNotMultiplayer_4DB250())
}

// nox_xxx_gameSetSwitchSolo_4DB220
func nox_xxx_gameSetSwitchSolo_4DB220(a1 int32) {
	Nox_xxx_gameSetSwitchSolo_4DB220(int(a1))
}

// nox_xxx_gameIsSwitchToSolo_4DB240
func nox_xxx_gameIsSwitchToSolo_4DB240() int32 {
	return bool2int32(Nox_xxx_gameIsSwitchToSolo_4DB240())
}

// nox_xxx_mapTraceRay_535250
func nox_xxx_mapTraceRay_535250(a1 *float4, a2 *float2, a3 *int2, a4 int8) int32 {
	p1 := (*types.Pointf)(unsafe.Pointer(&a1.field_0))
	p2 := (*types.Pointf)(unsafe.Pointer(&a1.field_8))
	outPos := (*types.Pointf)(unsafe.Pointer(a2))
	outGrid := (*image.Point)(unsafe.Pointer(a3))
	if GetServer().S().MapTraceRayAt(*p1, *p2, outPos, outGrid, server.MapTraceFlags(a4)) {
		return 1
	}
	return 0
}

// nox_xxx_mapTraceObstacles_50B580
func nox_xxx_mapTraceObstacles_50B580(from *server.Object, a2 *float4) int {
	if GetServer().S().MapTraceObstacles(asObjectS(from), types.Pointf{
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

// sub_5178E0
func sub_5178E0(a1 int32, a2 unsafe.Pointer) {
	p := (*server.ObjectIndex)(a2)
	GetServer().S().Map.Sub5178E0(a1 != 0, p)
}

// nox_xxx_waypointMapRegister_5179B0
func nox_xxx_waypointMapRegister_5179B0(a1p *nox_waypoint_t) {
	GetServer().S().Map.Nox_xxx_waypointMapRegister_5179B0(asWaypointS(a1p))
}

// sub_517A70
func sub_517A70(a1p *nox_waypoint_t) {
	GetServer().S().Map.Sub517A70(asWaypointS(a1p))
}

// sub_517B70
func sub_517B70(pos *float2, fnc func(it *server.Object, data unsafe.Pointer), data unsafe.Pointer) {
	if fnc == nil {
		return
	}
	GetServer().S().Map.Sub517B70(*(*types.Pointf)(unsafe.Pointer(pos)), func(it *server.Object) {
		fnc(it, data)
	})
}

// sub_517590
func sub_517590(x float32, y float32) int {
	return bool2int(GetServer().S().Map.ValidIndexPos(types.Ptf(x, y)))
}

// sub_518740
func sub_518740(a1 *float2, a2 uint8) *nox_waypoint_t {
	return (*nox_waypoint_t)(GetServer().Sub_518460(*(*types.Pointf)(unsafe.Pointer(a1)), a2, true).C())
}

type ObjectIter = func(it *server.Object, data unsafe.Pointer)

// nox_xxx_getMissilesInCircle_518170
func nox_xxx_getMissilesInCircle_518170(pos *float2, r float32, fnc ObjectIter, a4 *server.Object) {
	p := *(*types.Pointf)(unsafe.Pointer(pos))
	GetServer().S().Map.EachMissilesInCircle(p, r, func(it *server.Object) bool {
		fnc(it, unsafe.Pointer(a4))
		return true
	})
}

// nox_xxx_getUnitsInRectAdv_517ED0
func nox_xxx_getUnitsInRectAdv_517ED0(rect *float4, fnc ObjectIter, data unsafe.Pointer) {
	r := *(*types.Rectf)(unsafe.Pointer(rect))
	GetServer().S().Map.EachObjAndMissileInRect(r, func(it *server.Object) bool {
		fnc(it, data)
		return true
	})
}

// nox_xxx_getUnitsInRect_517C10
func nox_xxx_getUnitsInRect_517C10(rect *float4, fnc ObjectIter, data unsafe.Pointer) {
	r := *(*types.Rectf)(unsafe.Pointer(rect))
	GetServer().S().Map.EachObjInRect(r, func(it *server.Object) bool {
		fnc(it, data)
		return true
	})
}

// nox_xxx_unitsGetInCircle_517F90
func nox_xxx_unitsGetInCircle_517F90(pos *float2, r float32, fnc ObjectIter, data unsafe.Pointer) {
	p := *(*types.Pointf)(unsafe.Pointer(pos))
	GetServer().S().Map.EachObjInCircle(p, float32(r), func(it *server.Object) bool {
		fnc(it, data)
		return true
	})
}

// nox_xxx_gameSetWallsDamage_4E25A0
func nox_xxx_gameSetWallsDamage_4E25A0(v int32) {
	Nox_xxx_gameSetWallsDamage_4E25A0(int(v))
}

// nox_xxx_mapDamageUnitsAround_4E25B0
func nox_xxx_mapDamageUnitsAround_4E25B0(a1 *float32, a2, a3 float32, a4, a5 int32, a6, a7 *server.Object) {
	cpos := unsafe.Slice(a1, 2)
	pos := types.Pointf{X: float32(cpos[0]), Y: float32(cpos[1])}
	GetServer().Nox_xxx_mapDamageUnitsAround(pos, float32(a2), float32(a3), int(a4), object.DamageType(a5), asObjectS(a6), ToObjS(a7), GetDoDamageWalls())
}

// nox_game_addStateCode_43BDD0
func nox_game_addStateCode_43BDD0(code int32) {
	GetClient().GameAddStateCode(gui.StateID(code))
}

// nox_game_getStateCode_43BE10
func nox_game_getStateCode_43BE10() int32 {
	return int32(GetClient().GameGetStateCode())
}

// nox_game_decStateInd_43BDC0
func nox_game_decStateInd_43BDC0() {
	GetClient().GamePopState()
}

// Nox_game_switchStates_43C0A0
func Nox_game_switchStates_43C0A0() int {
	return bool2int(GetClient().GameStateSwitch())
}

// nox_xxx_wall_410160
func nox_xxx_wall_410160() {
	GetServer().S().Walls.Reset()
}

// sub_4537F0
func sub_4537F0() {
	GetServer().Sub4537F0()
}

// sub_41CC00
func sub_41CC00(cstr *byte) {
	Sub_41CC00(GoString(cstr))
}

// nox_xxx_playerSendMOTD_4DD140
func nox_xxx_playerSendMOTD_4DD140(a1 int32) {
	Nox_xxx_playerSendMOTD_4DD140(ntype.PlayerInd(a1))
}

// nox_xxx_unitCanInteractWith_5370E0
func nox_xxx_unitCanInteractWith_5370E0(a1, a2 *server.Object, a3 int32) int {
	return bool2int(GetServer().S().CanInteract(asObjectS(a1), asObjectS(a2), int(a3)))
}

// nox_xxx_unitCanSee_536FB0
func nox_xxx_unitCanSee_536FB0(a1, a2 *server.Object, a3 int32) int {
	return bool2int(GetServer().S().CanSee(asObjectS(a1), asObjectS(a2), int(a3)))
}

// nox_xxx_mapCheck_537110
func nox_xxx_mapCheck_537110(a1, a2 *server.Object) int {
	return bool2int(GetServer().S().MapTraceVision(asObjectS(a1), asObjectS(a2)))
}

// sub_497180
func sub_497180(r1, r2 *float4, outp *float2) int {
	out := (*types.Pointf)(unsafe.Pointer(outp))
	p, ok := server.LineTracePointXxx(*(*types.Rectf)(unsafe.Pointer(r1)), *(*types.Rectf)(unsafe.Pointer(r2)))
	*out = p
	return bool2int(ok)
}

// sub_427980
func sub_427980(r1, r2 *float4) int {
	return bool2int(server.LineTraceXxx(*(*types.Rectf)(unsafe.Pointer(r1)), *(*types.Rectf)(unsafe.Pointer(r2))))
}

func Nox_xxx_sMakeScorch_537AF0(pos types.Pointf, a2 int) {
	cpos, pfree := alloc.Make([]float32{}, 2)
	defer pfree()
	cpos[0] = pos.X
	cpos[1] = pos.Y
	nox_xxx_sMakeScorch_537AF0((*float32)(unsafe.Pointer(&cpos[0])), int32(a2))
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

	nox_xxx_mapDamageToWalls_534FC0((*int4)(unsafe.Pointer(&crect[0])), unsafe.Pointer(&cpos[0]), float32(rad), int32(dmg), int32(dtyp), who.CObj())
}

func Nox_xxx_getSomeMapName_4D0CF0() string {
	return GoString(nox_xxx_getSomeMapName_4D0CF0())
}

func Nox_server_gameSettingsUpdated_40A670() {
	nox_server_gameSettingsUpdated = 1
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
	return int(nox_server_testTwoPointsAndDirection_4E6E50((*float2)(unsafe.Pointer(cp1)), int32(dir), (*float2)(unsafe.Pointer(cp2))))
}

func Nox_xxx_mapLoadOrSaveMB_4DCC70(v int) {
	nox_xxx_mapLoadOrSaveMB_4DCC70(int32(v))
}
func Sub_4165B0() unsafe.Pointer {
	return unsafe.Pointer(sub_4165B0())
}
func Sub_44E560() unsafe.Pointer {
	return unsafe.Pointer(sub_44E560())
}
func Nox_xxx_serverOptionsGetServername_40A4C0() string {
	return GoString(nox_xxx_serverOptionsGetServername_40A4C0())
}
func Nox_xxx_mapGetMapName_409B40() string {
	return GoString(nox_xxx_mapGetMapName_409B40())
}
func Nox_xxx_servGetPlrLimit_409FA0() int {
	return int(nox_xxx_servGetPlrLimit_409FA0())
}
func Nox_client_xxx_switchChatMap_43B510() {
	nox_client_xxx_switchChatMap_43B510()
}
func Nox_client_guiXxx_43A9D0() {
	nox_client_guiXxx_43A9D0()
}
func Sub_43B630() {
	sub_43B630()
}
func Sub_49FF20() {
	sub_49FF20()
}
func Sub_445450() {
	sub_445450()
}
func Sub_45DB90() {
	sub_45DB90()
}
func Nox_xxx_initTime_435570() {
	nox_xxx_initTime_435570()
}
func Nox_xxx_allocArrayHealthChanges_49A5F0() int {
	return int(nox_xxx_allocArrayHealthChanges_49A5F0())
}
func Nox_xxx_loadGuides_427070() int {
	return int(nox_xxx_loadGuides_427070())
}
func Sub_494F00() int {
	return int(sub_494F00())
}
func Nox_alloc_npcs() {
	nox_alloc_npcs()
}
func Nox_xxx_loadReflSheild_499360() int {
	return int(nox_xxx_loadReflSheild_499360())
}
func Sub_4960B0() int {
	return int(sub_4960B0())
}
func Nox_xxx_allocClassListFriends_495980() int {
	return int(nox_xxx_allocClassListFriends_495980())
}
func Sub_4958F0() {
	sub_4958F0()
}
func Sub_460380() {
	sub_460380()
}
func Nox_xxx_cliPrepareGameplay1_460E60() int {
	return int(nox_xxx_cliPrepareGameplay1_460E60())
}
func Nox_xxx_cliPrepareGameplay2_4721D0() {
	nox_xxx_cliPrepareGameplay2_4721D0()
}
func Sub_4951C0() {
	sub_4951C0()
}
func Nox_xxx_netGameSettings_4DEF00() {
	nox_xxx_netGameSettings_4DEF00()
}
func Nox_server_gameUnsetMapLoad_40A690() {
	nox_server_gameUnsetMapLoad_40A690()
}
func Sub_416650() int {
	return int(sub_416650())
}
func Sub_46DCC0() {
	sub_46DCC0()
}
func Sub_409B80() string {
	return GoString(sub_409B80())
}
func Sub_4EDD70() {
	sub_4EDD70()
}
func Sub_4573B0() {
	sub_4573B0()
}
func Sub_4264D0() {
	sub_4264D0()
}
func Sub_416690() {
	sub_416690()
}
func Sub_426060() {
	sub_426060()
}
func Sub_455C30() int {
	return int(sub_455C30())
}
func Sub_456070() int {
	return int(sub_456070())
}
func Nox_xxx_guiHealthManaInit_4714E0() int {
	return int(nox_xxx_guiHealthManaInit_4714E0())
}
func Nox_xxx_bookInit_45B9D0() int {
	return int(nox_xxx_bookInit_45B9D0())
}
func Sub_476E20() unsafe.Pointer {
	return unsafe.Pointer(sub_476E20())
}
func Sub_4BFAD0() int {
	return int(sub_4BFAD0())
}
func Nox_xxx_wndCreateInventoryMB_465E00() uint32 {
	return uint32(nox_xxx_wndCreateInventoryMB_465E00())
}
func Nox_game_initOptionsInGame_4ADAD0() int {
	return int(nox_game_initOptionsInGame_4ADAD0())
}
func Sub_48D000() int {
	return int(sub_48D000())
}
func Sub_4C3760() int {
	return int(sub_4C3760())
}
func Sub_4C09D0() int {
	return int(sub_4C09D0())
}
func Sub_478110() int {
	return int(sub_478110())
}
func Sub_49B3E0() int {
	return int(sub_49B3E0())
}
func Sub_4BFC90() int {
	return int(sub_4BFC90())
}
func Nox_gui_itemAmount_init_4BFEF0() int {
	return int(nox_gui_itemAmount_init_4BFEF0())
}
func Sub_4799A0() int {
	return int(sub_4799A0())
}
func Sub_46A730() unsafe.Pointer {
	return unsafe.Pointer(sub_46A730())
}
func Sub_4C3500() int {
	return int(sub_4C3500())
}
func Nox_xxx_guiDrawRank_46E870() uint32 {
	return uint32(nox_xxx_guiDrawRank_46E870())
}
func Nox_xxx_guiMotdLoad_4465C0() uint32 {
	return uint32(nox_xxx_guiMotdLoad_4465C0())
}
func Nox_xxx_guiSummonCreatureLoad_4C1D80() int {
	return int(nox_xxx_guiSummonCreatureLoad_4C1D80())
}
func Sub_4AB260() int {
	return int(sub_4AB260())
}
func Nox_xxx_guiChatIconLoad_445650() int {
	return int(nox_xxx_guiChatIconLoad_445650())
}
func Sub_4C3390() int {
	return int(sub_4C3390())
}
func Sub_48C980() int {
	return int(sub_48C980())
}
func Sub_4D22B0() {
	sub_4D22B0()
}
func Sub_459870() unsafe.Pointer {
	return unsafe.Pointer(sub_459870())
}
func Nox_xxx_gamePlayIsAnyPlayers_40A8A0() int {
	return int(nox_xxx_gamePlayIsAnyPlayers_40A8A0())
}
func Sub_40A250() {
	sub_40A250()
}
func Sub_4D2230() {
	sub_4D2230()
}
func Sub_50AFA0() {
	sub_50AFA0()
}
func Sub_50B520() {
	sub_50B520()
}
func Sub_4D2160() {
	sub_4D2160()
}
func Nox_xxx_mapLoadRequired_4DCC80() int {
	return int(nox_xxx_mapLoadRequired_4DCC80())
}
func Sub_40A970() {
	sub_40A970()
}
func Nox_gui_itemAmount_free_4C03E0() {
	nox_gui_itemAmount_free_4C03E0()
}
func Sub_4AE3B0() {
	sub_4AE3B0()
}
func Sub_48D450() {
	sub_48D450()
}
func Sub_4C4220() {
	sub_4C4220()
}
func Nox_xxx_closeP2PTradeWnd_4C12A0() {
	nox_xxx_closeP2PTradeWnd_4C12A0()
}
func Sub_4BFD10() {
	sub_4BFD10()
}
func Sub_49B490() {
	sub_49B490()
}
func Sub_478F80() {
	sub_478F80()
}
func Sub_479D10() {
	sub_479D10()
}
func Sub_4AB470() {
	sub_4AB470()
}
func Sub_4C34A0() {
	sub_4C34A0()
}
func Sub_445770() {
	sub_445770()
}
func Sub_456240() {
	sub_456240()
}
func Sub_455EE0() {
	sub_455EE0()
}
func Sub_4505E0() {
	sub_4505E0()
}
func Sub_46A860() {
	sub_46A860()
}
func Sub_467980() {
	sub_467980()
}
func Sub_460D50() {
	sub_460D50()
}
func Nox_xxx_guiServerOptionsGetGametypeName_4573C0(a1 noxflags.GameFlag) string {
	return GoWString(nox_xxx_guiServerOptionsGetGametypeName_4573C0(int16(a1)))
}
func Sub_40A180(a1 noxflags.GameFlag) int {
	return int(sub_40A180(int16(a1)))
}
func Nox_xxx_servGamedataGet_40A020(a1 int16) int {
	return int(nox_xxx_servGamedataGet_40A020(int16(a1)))
}
func Sub_41D1A0(a1 int) {
	sub_41D1A0(int32(a1))
}
func Nox_xxx_netPlayerIncomingServ_4DDF60(a1 int) {
	nox_xxx_netPlayerIncomingServ_4DDF60(int32(a1))
}
func Nox_xxx_plrLoad_41A480(a1 string) int {
	str := CString(a1)
	defer StrFree(str)
	return int(nox_xxx_plrLoad_41A480(str))
}
func Sub_465DE0(a1 int) {
	sub_465DE0(int32(a1))
}
func Sub_4E79B0(a1 int) {
	sub_4E79B0(int32(a1))
}
func Nox_xxx_playerMakeDefItems_4EF7D0(a1 *server.Object, a2 int, a3 int) {
	nox_xxx_playerMakeDefItems_4EF7D0(int32(uintptr(a1.CObj())), int32(a2), int32(a3))
}
func Nox_xxx_cliGamedataGet_416590(a1 int) unsafe.Pointer {
	return unsafe.Pointer(nox_xxx_cliGamedataGet_416590(int32(a1)))
}
func Sub_4181F0(a1 int) {
	sub_4181F0(int32(a1))
}
func Sub_4AB4A0(a1 int) {
	sub_4AB4A0(int32(a1))
}
func Sub_4AB4D0(a1 int) {
	sub_4AB4D0(int32(a1))
}
func Sub_4721A0(a1 int) {
	sub_4721A0(int32(a1))
}
func Sub_460EA0(a1 int) {
	sub_460EA0(int32(a1))
}
func Nox_window_set_visible_unk5(a1 int) {
	nox_window_set_visible_unk5(int32(a1))
}
func Sub_45D500(a1 int) {
	sub_45D500(int32(a1))
}
func Sub_455A00(a1 int) {
	sub_455A00(int32(a1))
}
func Sub_455F10(a1 int) {
	sub_455F10(int32(a1))
}
func Nox_xxx_mapFindPlayerStart_4F7AB0(a2 *server.Object) types.Pointf {
	cp, freeCp := alloc.New(float2{})
	defer freeCp()
	nox_xxx_mapFindPlayerStart_4F7AB0(cp, asObjectC(a2))
	return types.Pointf{
		X: float32(cp.field_0),
		Y: float32(cp.field_4),
	}
}
func Sub_500510(a1 string) {
	sub_500510(internCStr(a1))
}
func Nox_xxx_mapSwitchLevel_4D12E0(a1 int) {
	nox_xxx_mapSwitchLevel_4D12E0(int32(a1))
}
func Sub_57A1E0(a1 unsafe.Pointer, a2 string, a3 unsafe.Pointer, a4 int, a5 noxflags.GameFlag) {
	sub_57A1E0((*int32)(a1), internCStr(a2), (*int32)(a3), int8(a4), int16(a5))
}
func Sub_57AAA0(a1 string, a2 *byte, a3 unsafe.Pointer) {
	sub_57AAA0(internCStr(a1), a2, (*int32)(a3))
}
func Sub_4EF660(a1 *server.Object) {
	sub_4EF660(asObjectC(a1))
}
func Nox_xxx_resetMapInit_4FC570(a1 int) {
	nox_xxx_resetMapInit_4FC570(int32(a1))
}
func Sub_4DBA30(a1 bool) {
	sub_4DBA30(bool2int32(a1))
}
func Sub_4FC580(a1 int) {
	sub_4FC580(int32(a1))
}
func Nox_xxx_isUnit_4E5B50(a1 *server.Object) int {
	return int(nox_xxx_isUnit_4E5B50(asObjectC(a1)))
}
func Sub_4E5B80(a1 *server.Object) int {
	return int(sub_4E5B80(asObjectC(a1)))
}
func Sub_4E81D0(a1 *server.Object) {
	sub_4E81D0(asObjectC(a1))
}
func Sub_4D71E0(a1 int) {
	sub_4D71E0(int32(a1))
}
func Sub_4D7280(a1 int, a2 int8) {
	sub_4D7280(int32(a1), int8(a2))
}
func Nox_xxx_calcDistance_4E6C00(a1 *server.Object, a2 *server.Object) float32 {
	return float32(nox_xxx_calcDistance_4E6C00(asObjectC(a1), asObjectC(a2)))
}
func Sub_415CD0(a1 int) int {
	return int(sub_415CD0(int32(a1)))
}
func Sub_415840(a1 int) int {
	return int(sub_415840(int32(a1)))
}
func Sub_41CAC0(a1 string, data []byte) {
	sub_41CAC0(internCStr(a1), unsafe.Pointer(&data[0]))
}
func Nox_xxx_spell_4FE680(a1 *server.Object, a2 float32) {
	nox_xxx_spell_4FE680(asObjectC(a1), float32(a2))
}
