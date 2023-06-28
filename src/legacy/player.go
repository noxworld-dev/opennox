package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_updateSpellRelated_424830   func(p unsafe.Pointer, ph int) unsafe.Pointer
	Nox_xxx_playerDisconnByPlrID_4DEB00 func(id ntype.PlayerInd)
	Nox_xxx_playerCallDisconnect_4DEAB0 func(ind ntype.PlayerInd, v int8)
	Nox_xxx_playerCameraUnlock_4E6040   func(cplayer *server.Object)
	Nox_xxx_playerCameraFollow_4E6060   func(cplayer, cunit *server.Object)
	Nox_xxx_playerGetPossess_4DDF30     func(cplayer *server.Object) *server.Object
	Nox_xxx_playerGoObserver_4E6860     func(pl *server.Player, a2 int, a3 int) int
	Nox_xxx_playerObserveClear_4DDEF0   func(cplayer *server.Object)
	Nox_client_onClassStats             func(buf []byte)
	Nox_xxx_playerObserveMonster_4DDE80 func(cplayer, cunit *server.Object)
)

func asPlayerS(p *server.Player) *server.Player {
	return p
}

func AsPlayerP(p unsafe.Pointer) *server.Player {
	return (*server.Player)(p)
}

// nox_xxx_playerSpell_4FB2A0_magic_plyrspel
func nox_xxx_playerSpell_4FB2A0_magic_plyrspel(up *server.Object) {
	GetServer().PlayerSpell(asObjectS(up))
}

// nox_xxx_updateSpellRelated_424830
func nox_xxx_updateSpellRelated_424830(p unsafe.Pointer, ph int32) unsafe.Pointer {
	return Nox_xxx_updateSpellRelated_424830(p, int(ph))
}

// nox_common_playerInfoGetFirst_416EA0
func nox_common_playerInfoGetFirst_416EA0() *server.Player {
	return (*server.Player)(GetServer().S().Players.First().C())
}

// nox_common_playerInfoGetNext_416EE0
func nox_common_playerInfoGetNext_416EE0(it *server.Player) *server.Player {
	return (*server.Player)(GetServer().S().Players.Next(asPlayerS(it)).C())
}

// nox_common_playerInfoCount_416F40
func nox_common_playerInfoCount_416F40() int32 {
	return int32(GetServer().S().Players.Count())
}

// nox_common_playerInfoGetByID_417040
func nox_common_playerInfoGetByID_417040(id int32) *server.Player {
	return (*server.Player)(GetServer().S().Players.ByID(int(id)).C())
}

// nox_common_playerInfoFromNum_417090
func nox_common_playerInfoFromNum_417090(ind int32) *server.Player {
	return (*server.Player)(GetServer().S().Players.ByInd(ntype.PlayerInd(ind)).C())
}

// nox_common_playerInfoFromNumRaw
func nox_common_playerInfoFromNumRaw(ind int32) *server.Player {
	return (*server.Player)(GetServer().S().Players.ByIndRaw(ntype.PlayerInd(ind)).C())
}

// nox_xxx_playerDisconnByPlrID_4DEB00
func nox_xxx_playerDisconnByPlrID_4DEB00(id int32) {
	Nox_xxx_playerDisconnByPlrID_4DEB00(ntype.PlayerInd(id))
}

// nox_xxx_playerCallDisconnect_4DEAB0
func nox_xxx_playerCallDisconnect_4DEAB0(ind int32, v int8) *byte {
	Nox_xxx_playerCallDisconnect_4DEAB0(ntype.PlayerInd(ind), v)
	return nil
}

// nox_xxx_playerCameraUnlock_4E6040
func nox_xxx_playerCameraUnlock_4E6040(cplayer *server.Object) {
	Nox_xxx_playerCameraUnlock_4E6040(asObjectS(cplayer))
}

// nox_xxx_playerCameraFollow_4E6060
func nox_xxx_playerCameraFollow_4E6060(cplayer, cunit *server.Object) {
	Nox_xxx_playerCameraFollow_4E6060(asObjectS(cplayer), asObjectS(cunit))
}

// nox_xxx_playerGetPossess_4DDF30
func nox_xxx_playerGetPossess_4DDF30(cplayer *server.Object) *server.Object {
	return asObjectC(Nox_xxx_playerGetPossess_4DDF30(asObjectS(cplayer)))
}

// nox_xxx_playerGoObserver_4E6860
func nox_xxx_playerGoObserver_4E6860(pl *server.Player, a2 int32, a3 int32) int {
	return Nox_xxx_playerGoObserver_4E6860(asPlayerS(pl), int(a2), int(a3))
}

// nox_xxx_playerObserveClear_4DDEF0
func nox_xxx_playerObserveClear_4DDEF0(cplayer *server.Object) {
	Nox_xxx_playerObserveClear_4DDEF0(asObjectS(cplayer))
}

// nox_client_onClassStats
func nox_client_onClassStats(cbuf *byte, sz int) {
	data := unsafe.Slice(cbuf, sz)
	Nox_client_onClassStats(data)
}

// nox_xxx_playerObserveMonster_4DDE80
func nox_xxx_playerObserveMonster_4DDE80(cplayer, cunit *server.Object) {
	Nox_xxx_playerObserveMonster_4DDE80(asObjectS(cplayer), asObjectS(cunit))
}
func Nox_xxx_scavengerTreasureMax_4D1600() uint32 {
	return uint32(nox_xxx_scavengerTreasureMax_4D1600())
}

func Nox_xxx_netMsgFadeBeginPlayer(ind int, dir int, a3 int) {
	nox_xxx_netMsgFadeBeginPlayer(int32(ind), int32(dir), int32(a3))
}

func PrintToPlayers(text string) {
	cstr, free := CWString(text)
	defer free()
	nox_xxx_printToAll_4D9FD0(0, cstr)
}

func ClientPlayerNetCode() int {
	return int(nox_player_netCode_85319C)
}

func ClientSetPlayerNetCode(id int) {
	nox_player_netCode_85319C = uint32(id)
}

func Nox_xxx_playerForceDisconnect_4DE7C0(ind ntype.PlayerInd) {
	nox_xxx_playerForceDisconnect_4DE7C0(int32(ind))
}

func Nox_xxx_netNeedTimestampStatus_4174F0(pl *server.Player, v int) {
	nox_xxx_netNeedTimestampStatus_4174F0((*server.Player)(pl.C()), int32(v))
}

func Sub_40A1F0(v int) {
	sub_40A1F0(int32(v))
}

func Nox_game_sendQuestStage_4D6960(v ntype.PlayerInd) {
	nox_game_sendQuestStage_4D6960(int32(v))
}

func Nox_xxx_playerForceSendLessons_416E50(v int) {
	nox_xxx_playerForceSendLessons_416E50(int32(v))
}

func Nox_xxx_playerRemoveSpawnedStuff_4E5AD0(u *server.Object) {
	nox_xxx_playerRemoveSpawnedStuff_4E5AD0(asObjectC(u))
}

func Sub_4D7E50(u *server.Object) {
	sub_4D7E50(asObjectC(u))
}

func Nox_xxx_playerObserverFindGoodSlave0_4E6280(p *server.Player) *server.Object {
	return asObjectS(nox_xxx_playerObserverFindGoodSlave0_4E6280((*server.Player)(p.C())))
}

func Sub_4E6150(p *server.Player) *server.Object {
	return asObjectS(sub_4E6150((*server.Player)(p.C())))
}

func Nox_xxx_playerUnsetStatus_417530(p *server.Player, a2 int) {
	nox_xxx_playerUnsetStatus_417530((*server.Player)(p.C()), int32(a2))
}

func Nox_xxx_playerResetImportantCtr_4E4F40(v ntype.PlayerInd) {
	nox_xxx_playerResetImportantCtr_4E4F40(int32(v))
}

func Get_dword_5d4594_1046492() int {
	return int(dword_5d4594_1046492)
}

func Nox_xxx_playerInitColors_461460(pl *server.Player) {
	nox_xxx_playerInitColors_461460((*server.Player)(pl.C()))
}

func Sub_425B30(a1 unsafe.Pointer, a2 ntype.PlayerInd) {
	sub_425B30(a1, int32(a2))
}

func Sub_425A70(a1 int) unsafe.Pointer {
	return sub_425A70(int32(a1))
}

func Sub_425AD0(a1 int, a2 *uint16) unsafe.Pointer {
	return unsafe.Pointer(sub_425AD0(int32(a1), a2))
}

func Sub_41D670(a1 string) {
	sub_41D670(internCStr(a1))
}

func Sub_425F10(p *server.Player) {
	sub_425F10((*server.Player)(p.C()))
}

func Sub_4DF3C0(p *server.Player) {
	sub_4DF3C0((*server.Player)(p.C()))
}

func Sub_40AA70(p *server.Player) int {
	return int(sub_40AA70((*server.Player)(p.C())))
}

func Nox_xxx_netReportPlayerStatus_417630(p *server.Player) {
	nox_xxx_netReportPlayerStatus_417630((*server.Player)(p.C()))
}

func Sub_509C30(p *server.Player) {
	sub_509C30((*server.Player)(p.C()))
}

func Nox_xxx_playerLeaveObserver_0_4E6AA0(p *server.Player) {
	nox_xxx_playerLeaveObserver_0_4E6AA0((*server.Player)(p.C()))
}

func Nox_xxx_netGuiGameSettings_4DD9B0(a1 int, a2 unsafe.Pointer, a3 int) {
	nox_xxx_netGuiGameSettings_4DD9B0(int8(a1), a2, int32(a3))
}

func Sub_459AA0(a1 unsafe.Pointer) {
	sub_459AA0(a1)
}

func Nox_xxx_netNotifyRate_4D7F10(v ntype.PlayerInd) {
	nox_xxx_netNotifyRate_4D7F10(int32(v))
}

func Nox_xxx_plrReadVals_4EEDC0(obj *server.Object, a2 int) {
	nox_xxx_plrReadVals_4EEDC0(asObjectC(obj), int32(a2))
}

func Nox_xxx_playerManaAdd_4EEB80(obj *server.Object, v int) {
	nox_xxx_playerManaAdd_4EEB80(asObjectC(obj), int16(v))
}

func Sub_4FD0E0(obj *server.Object, sp spell.ID) int {
	return int(sub_4FD0E0(asObjectC(obj), int32(sp)))
}

func Nox_xxx_checkPlrCantCastSpell_4FD150(obj *server.Object, sp spell.ID, a3 int) int {
	return int(nox_xxx_checkPlrCantCastSpell_4FD150(asObjectC(obj), int32(sp), int32(a3)))
}

func Sub_4FCF90(obj *server.Object, sp spell.ID, a3 int) int {
	return int(sub_4FCF90(asObjectC(obj), int32(sp), int32(a3)))
}

func Get_nox_xxx_warriorMaxHealth_587000_312784() float32 {
	return float32(nox_xxx_warriorMaxHealth_587000_312784)
}

func Get_nox_xxx_warriorMaxMana_587000_312788() float32 {
	return float32(nox_xxx_warriorMaxMana_587000_312788)
}

func Get_nox_xxx_conjurerMaxHealth_587000_312800() float32 {
	return float32(nox_xxx_conjurerMaxHealth_587000_312800)
}

func Get_nox_xxx_conjurerMaxMana_587000_312804() float32 {
	return float32(nox_xxx_conjurerMaxMana_587000_312804)
}

func Get_nox_xxx_wizardMaxHealth_587000_312816() float32 {
	return float32(nox_xxx_wizardMaxHealth_587000_312816)
}

func Get_nox_xxx_wizardMaximumMana_587000_312820() float32 {
	return float32(nox_xxx_wizardMaximumMana_587000_312820)
}

func Set_nox_xxx_warriorMaxHealth_587000_312784(v float32) {
	nox_xxx_warriorMaxHealth_587000_312784 = v
}

func Set_nox_xxx_warriorMaxMana_587000_312788(v float32) {
	nox_xxx_warriorMaxMana_587000_312788 = v
}

func Set_nox_xxx_conjurerMaxHealth_587000_312800(v float32) {
	nox_xxx_conjurerMaxHealth_587000_312800 = v
}

func Set_nox_xxx_conjurerMaxMana_587000_312804(v float32) {
	nox_xxx_conjurerMaxMana_587000_312804 = v
}

func Set_nox_xxx_wizardMaxHealth_587000_312816(v float32) {
	nox_xxx_wizardMaxHealth_587000_312816 = v
}

func Set_nox_xxx_wizardMaximumMana_587000_312820(v float32) {
	nox_xxx_wizardMaximumMana_587000_312820 = v
}

func Sub_4D79A0(pli ntype.PlayerInd) {
	sub_4D79A0(int8(pli))
}

func Sub_4E80C0(pli ntype.PlayerInd) {
	sub_4E80C0(int8(pli))
}

func Nox_xxx_player_4E3CE0() int {
	return int(nox_xxx_player_4E3CE0())
}

func Sub_425E90(pl *server.Player, a2 int8) {
	sub_425E90(pl.C(), a2)
}

func Sub_4E55F0(pli ntype.PlayerInd) {
	sub_4E55F0(byte(pli))
}
