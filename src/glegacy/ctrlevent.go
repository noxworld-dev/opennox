package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
)

type CtrlEventHandler interface {
	Reset()
	Sub_42E8E0_go(key keybind.Event, a2 int) string
}

var (
	GetCtrlEvent                             func() CtrlEventHandler
	Nox_client_parseConfigHotkeysLine_42CF50 func(s string) int
)

// nox_xxx_playerResetControlBuffer_51AC30
func nox_xxx_playerResetControlBuffer_51AC30(pi int) {
	GetServer().S().Players.Control.Player(pi).Reset()
}

// sub_42E8E0
func sub_42E8E0(key, a2 int) *wchar2_t {
	s := GetCtrlEvent().Sub_42E8E0_go(keybind.Event(key), a2)
	return internWStr(s)
}

// sub_42CD90
func sub_42CD90() {
	GetCtrlEvent().Reset()
}

// nox_client_parseConfigHotkeysLine_42CF50
func nox_client_parseConfigHotkeysLine_42CF50(a1 *byte) int {
	return Nox_client_parseConfigHotkeysLine_42CF50(GoString(a1))
}

func Nox_xxx_guiSpellTargetClickCheckSend_45DBB0() {
	nox_xxx_guiSpellTargetClickCheckSend_45DBB0()
}

func Nox_xxx_clientTrade_42E850(dr *client.Drawable) {
	nox_xxx_clientTrade_42E850((*nox_drawable)(dr.C()))
}

func Nox_xxx_clientTalk_42E7B0(dr *client.Drawable) {
	nox_xxx_clientTalk_42E7B0((*nox_drawable)(dr.C()))
}

func Nox_xxx_clientCollideOrUse_42E810(dr *client.Drawable) {
	nox_xxx_clientCollideOrUse_42E810((*nox_drawable)(dr.C()))
}

func Nox_xxx_packetGetMarshall_476F40() uint32 {
	return uint32(nox_xxx_packetGetMarshall_476F40())
}

func Nox_xxx_clientUpdateButtonRow_45E110(ind int) {
	nox_xxx_clientUpdateButtonRow_45E110(int32(ind))
}

func Nox_client_trapSetSelect_4604B0(ind int) {
	nox_client_trapSetSelect_4604B0(int32(ind))
}

func Nox_client_orderCreature(a1, a2 int) {
	nox_client_orderCreature(int32(a1), int32(a2))
}

func Get_nox_gui_itemAmount_dialog_1319228() *gui.Window {
	return AsWindowP(nox_gui_itemAmount_dialog_1319228)
}

func Sub_4C01C0(a1, a2 int, a3 unsafe.Pointer, a4 int) {
	sub_4C01C0(int32(a1), int32(a2), (*int32)(a3), int32(a4))
}

func Nox_client_chatStart_46A430(v int) {
	nox_client_chatStart_46A430(int32(v))
}

func Nox_client_toggleSpellbook_45AC70() {
	nox_client_toggleSpellbook_45AC70()
}

func Nox_client_toggleInventory_467C60() {
	nox_client_toggleInventory_467C60()
}

func Nox_client_mapZoomIn_4724E0() {
	nox_client_mapZoomIn_4724E0()
}

func Nox_client_mapZoomOut_472500() {
	nox_client_mapZoomOut_472500()
}

func Nox_client_invAlterWeapon_4672C0() {
	nox_client_invAlterWeapon_4672C0()
}

func Nox_client_quickHealthPotion_472220() {
	nox_client_quickHealthPotion_472220()
}

func Nox_client_quickManaPotion_472240() {
	nox_client_quickManaPotion_472240()
}

func Nox_client_quickCurePoisonPotion_472260() {
	nox_client_quickCurePoisonPotion_472260()
}

func Nox_client_spellSetNext_4604F0() {
	nox_client_spellSetNext_4604F0()
}

func Nox_client_spellSetPrev_460540() {
	nox_client_spellSetPrev_460540()
}

func Nox_client_spellSetSelect_460590() {
	nox_client_spellSetSelect_460590()
}

func Nox_client_buildTrap_45E040() {
	nox_client_buildTrap_45E040()
}

func Nox_xxx_guiServerOptsLoad_457500() {
	nox_xxx_guiServerOptsLoad_457500()
}

func Sub_460630() {
	sub_460630()
}
func Nox_xxx_game_4DCCB0() int {
	return int(nox_xxx_game_4DCCB0())
}
func Sub_554290() uint32 {
	return uint32(sub_554290())
}
func Sub_554300() uint32 {
	return uint32(sub_554300())
}
func Nox_client_mousePriKey_430AF0() int {
	return int(nox_client_mousePriKey_430AF0())
}
func Sub_42EB90(a1 int) {
	sub_42EB90(int32(a1))
}
func Nox_client_invokeSpellSlot_45DA50(a1 int) {
	nox_client_invokeSpellSlot_45DA50(int32(a1))
}
