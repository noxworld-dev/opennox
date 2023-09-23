package legacy

/*
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "common__net_list.h"
#include "defs.h"
extern unsigned int dword_5d4594_1046492;
extern unsigned int dword_5d4594_2650652;
extern unsigned int nox_player_netCode_85319C;
void nox_xxx_WideScreenDo_515240(bool enable);
static void nox_xxx_printToAll_4D9FD0_go(int a1, wchar2_t* str) {
	nox_xxx_printToAll_4D9FD0(a1, str);
}

extern float nox_xxx_warriorMaxHealth_587000_312784;
extern float nox_xxx_warriorMaxMana_587000_312788;

extern float nox_xxx_conjurerMaxHealth_587000_312800;
extern float nox_xxx_conjurerMaxMana_587000_312804;

extern float nox_xxx_wizardMaxHealth_587000_312816;
extern float nox_xxx_wizardMaximumMana_587000_312820;

*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
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

type nox_playerInfo = C.nox_playerInfo

func asPlayerS(p *nox_playerInfo) *server.Player {
	return (*server.Player)(unsafe.Pointer(p))
}

func AsPlayerP(p unsafe.Pointer) *server.Player {
	return (*server.Player)(p)
}

//export nox_xxx_playerSpell_4FB2A0_magic_plyrspel
func nox_xxx_playerSpell_4FB2A0_magic_plyrspel(up *nox_object_t) {
	GetServer().PlayerSpell(asObjectS(up))
}

//export nox_xxx_updateSpellRelated_424830
func nox_xxx_updateSpellRelated_424830(p unsafe.Pointer, ph int) unsafe.Pointer {
	return ((*server.PhonemeLeaf)(p)).Next(spell.Phoneme(ph)).C()
}

//export nox_common_playerInfoGetFirst_416EA0
func nox_common_playerInfoGetFirst_416EA0() *nox_playerInfo {
	return (*nox_playerInfo)(GetServer().S().Players.First().C())
}

//export nox_common_playerInfoGetNext_416EE0
func nox_common_playerInfoGetNext_416EE0(it *nox_playerInfo) *nox_playerInfo {
	return (*nox_playerInfo)(GetServer().S().Players.Next(asPlayerS(it)).C())
}

//export nox_common_playerInfoCount_416F40
func nox_common_playerInfoCount_416F40() int {
	return GetServer().S().Players.Count()
}

//export nox_common_playerInfoGetByID_417040
func nox_common_playerInfoGetByID_417040(id int) *nox_playerInfo {
	return (*nox_playerInfo)(GetServer().S().Players.ByID(id).C())
}

//export nox_common_playerInfoFromNum_417090
func nox_common_playerInfoFromNum_417090(ind int) *nox_playerInfo {
	return (*nox_playerInfo)(GetServer().S().Players.ByInd(ntype.PlayerInd(ind)).C())
}

//export nox_common_playerInfoFromNumRaw
func nox_common_playerInfoFromNumRaw(ind int) *nox_playerInfo {
	return (*nox_playerInfo)(GetServer().S().Players.ByIndRaw(ntype.PlayerInd(ind)).C())
}

//export nox_xxx_playerDisconnByPlrID_4DEB00
func nox_xxx_playerDisconnByPlrID_4DEB00(id int) {
	Nox_xxx_playerDisconnByPlrID_4DEB00(ntype.PlayerInd(id))
}

//export nox_xxx_playerCallDisconnect_4DEAB0
func nox_xxx_playerCallDisconnect_4DEAB0(ind int, v C.char) *C.char {
	Nox_xxx_playerCallDisconnect_4DEAB0(ntype.PlayerInd(ind), int8(v))
	return nil
}

//export nox_xxx_playerCameraUnlock_4E6040
func nox_xxx_playerCameraUnlock_4E6040(cplayer *nox_object_t) {
	Nox_xxx_playerCameraUnlock_4E6040(asObjectS(cplayer))
}

//export nox_xxx_playerCameraFollow_4E6060
func nox_xxx_playerCameraFollow_4E6060(cplayer, cunit *nox_object_t) {
	Nox_xxx_playerCameraFollow_4E6060(asObjectS(cplayer), asObjectS(cunit))
}

//export nox_xxx_playerGetPossess_4DDF30
func nox_xxx_playerGetPossess_4DDF30(cplayer *nox_object_t) *nox_object_t {
	return asObjectC(Nox_xxx_playerGetPossess_4DDF30(asObjectS(cplayer)))
}

//export nox_xxx_playerGoObserver_4E6860
func nox_xxx_playerGoObserver_4E6860(pl *nox_playerInfo, a2 int, a3 int) int {
	return Nox_xxx_playerGoObserver_4E6860(asPlayerS(pl), a2, a3)
}

//export nox_xxx_playerObserveClear_4DDEF0
func nox_xxx_playerObserveClear_4DDEF0(cplayer *nox_object_t) {
	Nox_xxx_playerObserveClear_4DDEF0(asObjectS(cplayer))
}

//export nox_client_onClassStats
func nox_client_onClassStats(cbuf *C.uchar, sz int) {
	data := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), sz)
	Nox_client_onClassStats(data)
}

//export nox_xxx_playerObserveMonster_4DDE80
func nox_xxx_playerObserveMonster_4DDE80(cplayer, cunit *nox_object_t) {
	Nox_xxx_playerObserveMonster_4DDE80(asObjectS(cplayer), asObjectS(cunit))
}
func Nox_xxx_scavengerTreasureMax_4D1600() uint32 {
	return uint32(C.nox_xxx_scavengerTreasureMax_4D1600())
}

func Nox_xxx_netMsgFadeBeginPlayer(ind int, dir int, a3 int) {
	C.nox_xxx_netMsgFadeBeginPlayer(C.int(ind), C.int(dir), C.int(a3))
}

func PrintToPlayers(text string) {
	cstr, free := CWString(text)
	defer free()
	C.nox_xxx_printToAll_4D9FD0_go(0, cstr)
}

func ClientPlayerNetCode() int {
	return int(C.nox_player_netCode_85319C)
}

func ClientSetPlayerNetCode(id int) {
	C.nox_player_netCode_85319C = C.uint(id)
}

func Nox_xxx_playerForceDisconnect_4DE7C0(ind ntype.PlayerInd) {
	C.nox_xxx_playerForceDisconnect_4DE7C0(C.int(ind))
}

func Get_nox_xxx_updatePlayerMonsterBot_4FAB20() unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_updatePlayerMonsterBot_4FAB20)
}

func Nox_xxx_netNeedTimestampStatus_4174F0(pl *server.Player, v int) {
	C.nox_xxx_netNeedTimestampStatus_4174F0((*nox_playerInfo)(pl.C()), C.int(v))
}

func Sub_40A1F0(v int) {
	C.sub_40A1F0(C.int(v))
}

func Nox_game_sendQuestStage_4D6960(v ntype.PlayerInd) {
	C.nox_game_sendQuestStage_4D6960(C.int(v))
}

func Nox_xxx_playerForceSendLessons_416E50(v int) {
	C.nox_xxx_playerForceSendLessons_416E50(C.int(v))
}

func Get_nox_xxx_updatePlayerObserver_4E62F0() unsafe.Pointer {
	return C.nox_xxx_updatePlayerObserver_4E62F0
}

func Nox_xxx_playerRemoveSpawnedStuff_4E5AD0(u *server.Object) {
	C.nox_xxx_playerRemoveSpawnedStuff_4E5AD0(asObjectC(u))
}

func Sub_4D7E50(u *server.Object) {
	C.sub_4D7E50(asObjectC(u))
}

func Nox_xxx_playerObserverFindGoodSlave0_4E6280(p *server.Player) *server.Object {
	return asObjectS(C.nox_xxx_playerObserverFindGoodSlave0_4E6280((*nox_playerInfo)(p.C())))
}

func Sub_4E6150(p *server.Player) *server.Object {
	return asObjectS(C.sub_4E6150((*nox_playerInfo)(p.C())))
}

func Get_nox_xxx_updatePlayer_4F8100() unsafe.Pointer {
	return C.nox_xxx_updatePlayer_4F8100
}

func Nox_xxx_playerUnsetStatus_417530(p *server.Player, a2 int) {
	C.nox_xxx_playerUnsetStatus_417530((*nox_playerInfo)(p.C()), C.int(a2))
}

func Nox_xxx_playerResetImportantCtr_4E4F40(v ntype.PlayerInd) {
	C.nox_xxx_playerResetImportantCtr_4E4F40(C.int(v))
}

func Get_dword_5d4594_1046492() int {
	return int(C.dword_5d4594_1046492)
}

func Nox_xxx_playerInitColors_461460(pl *server.Player) {
	C.nox_xxx_playerInitColors_461460((*nox_playerInfo)(pl.C()))
}

func Sub_425B30(a1 unsafe.Pointer, a2 ntype.PlayerInd) {
	C.sub_425B30(a1, C.int(a2))
}

func Sub_425A70(a1 int) unsafe.Pointer {
	return unsafe.Pointer(C.sub_425A70(C.int(a1)))
}

func Sub_425AD0(a1 int, a2 *uint16) unsafe.Pointer {
	return unsafe.Pointer(C.sub_425AD0(C.int(a1), (*C.ushort)(unsafe.Pointer(a2))))
}

func Sub_41D670(a1 string) {
	C.sub_41D670(internCStr(a1))
}

func Sub_425F10(p *server.Player) {
	C.sub_425F10((*nox_playerInfo)(p.C()))
}

func Sub_4DF3C0(p *server.Player) {
	C.sub_4DF3C0((*nox_playerInfo)(p.C()))
}

func Sub_40AA70(p *server.Player) int {
	return int(C.sub_40AA70((*nox_playerInfo)(p.C())))
}

func Nox_xxx_netReportPlayerStatus_417630(p *server.Player) {
	C.nox_xxx_netReportPlayerStatus_417630((*nox_playerInfo)(p.C()))
}

func Sub_509C30(p *server.Player) {
	C.sub_509C30((*nox_playerInfo)(p.C()))
}

func Nox_xxx_playerLeaveObserver_0_4E6AA0(p *server.Player) {
	C.nox_xxx_playerLeaveObserver_0_4E6AA0((*nox_playerInfo)(p.C()))
}

func Nox_xxx_netGuiGameSettings_4DD9B0(a1 int, a2 unsafe.Pointer, a3 int) {
	C.nox_xxx_netGuiGameSettings_4DD9B0(C.char(a1), a2, C.int(a3))
}

func Sub_459AA0(a1 unsafe.Pointer) {
	C.sub_459AA0(a1)
}

func Nox_xxx_netNotifyRate_4D7F10(v ntype.PlayerInd) {
	C.nox_xxx_netNotifyRate_4D7F10(C.int(v))
}

func Nox_xxx_plrReadVals_4EEDC0(obj *server.Object, a2 int) {
	C.nox_xxx_plrReadVals_4EEDC0(asObjectC(obj), C.int(a2))
}

func Nox_xxx_playerManaAdd_4EEB80(obj *server.Object, v int) {
	C.nox_xxx_playerManaAdd_4EEB80(asObjectC(obj), C.short(v))
}

func Nox_xxx_removePoison_4EE9D0(obj *server.Object) {
	C.nox_xxx_removePoison_4EE9D0(asObjectC(obj))
}

func Sub_4FD0E0(obj *server.Object, sp spell.ID) int {
	return int(C.sub_4FD0E0(asObjectC(obj), C.int(sp)))
}

func Nox_xxx_checkPlrCantCastSpell_4FD150(obj *server.Object, sp spell.ID, a3 int) int {
	return int(C.nox_xxx_checkPlrCantCastSpell_4FD150(asObjectC(obj), C.int(sp), C.int(a3)))
}

func Sub_4FCF90(obj *server.Object, sp spell.ID, a3 int) int {
	return int(C.sub_4FCF90(asObjectC(obj), C.int(sp), C.int(a3)))
}

func Get_nox_xxx_warriorMaxHealth_587000_312784() float32 {
	return float32(C.nox_xxx_warriorMaxHealth_587000_312784)
}

func Get_nox_xxx_warriorMaxMana_587000_312788() float32 {
	return float32(C.nox_xxx_warriorMaxMana_587000_312788)
}

func Get_nox_xxx_conjurerMaxHealth_587000_312800() float32 {
	return float32(C.nox_xxx_conjurerMaxHealth_587000_312800)
}

func Get_nox_xxx_conjurerMaxMana_587000_312804() float32 {
	return float32(C.nox_xxx_conjurerMaxMana_587000_312804)
}

func Get_nox_xxx_wizardMaxHealth_587000_312816() float32 {
	return float32(C.nox_xxx_wizardMaxHealth_587000_312816)
}

func Get_nox_xxx_wizardMaximumMana_587000_312820() float32 {
	return float32(C.nox_xxx_wizardMaximumMana_587000_312820)
}

func Set_nox_xxx_warriorMaxHealth_587000_312784(v float32) {
	C.nox_xxx_warriorMaxHealth_587000_312784 = C.float(v)
}

func Set_nox_xxx_warriorMaxMana_587000_312788(v float32) {
	C.nox_xxx_warriorMaxMana_587000_312788 = C.float(v)
}

func Set_nox_xxx_conjurerMaxHealth_587000_312800(v float32) {
	C.nox_xxx_conjurerMaxHealth_587000_312800 = C.float(v)
}

func Set_nox_xxx_conjurerMaxMana_587000_312804(v float32) {
	C.nox_xxx_conjurerMaxMana_587000_312804 = C.float(v)
}

func Set_nox_xxx_wizardMaxHealth_587000_312816(v float32) {
	C.nox_xxx_wizardMaxHealth_587000_312816 = C.float(v)
}

func Set_nox_xxx_wizardMaximumMana_587000_312820(v float32) {
	C.nox_xxx_wizardMaximumMana_587000_312820 = C.float(v)
}

func Sub_4D79A0(pli ntype.PlayerInd) {
	C.sub_4D79A0(C.char(pli))
}

func Sub_4E80C0(pli ntype.PlayerInd) {
	C.sub_4E80C0(C.char(pli))
}

func Nox_xxx_player_4E3CE0() int {
	return int(C.nox_xxx_player_4E3CE0())
}

func Sub_425E90(pl *server.Player, a2 int8) {
	C.sub_425E90(pl.C(), C.char(a2))
}

func Sub_4E55F0(pli ntype.PlayerInd) {
	C.sub_4E55F0(C.uchar(pli))
}
