package legacy

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
#include "client__gui__guicon.h"
#include "client__gui__guisave.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"

extern void* nox_gui_itemAmount_dialog_1319228;

int nox_ctrlevent_add_ticks_42E630();
void nox_client_orderCreature(int creature, int command);
*/
import "C"
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

//export nox_xxx_playerResetControlBuffer_51AC30
func nox_xxx_playerResetControlBuffer_51AC30(pi int) {
	GetServer().S().Players.Control.Player(pi).Reset()
}

//export sub_42E8E0
func sub_42E8E0(key, a2 int) *C.wchar_t {
	s := GetCtrlEvent().Sub_42E8E0_go(keybind.Event(key), a2)
	return internWStr(s)
}

//export sub_42CD90
func sub_42CD90() {
	GetCtrlEvent().Reset()
}

//export nox_client_parseConfigHotkeysLine_42CF50
func nox_client_parseConfigHotkeysLine_42CF50(a1 *C.char) int {
	return Nox_client_parseConfigHotkeysLine_42CF50(GoString(a1))
}

func Nox_xxx_guiSpellTargetClickCheckSend_45DBB0() {
	C.nox_xxx_guiSpellTargetClickCheckSend_45DBB0()
}

func Nox_xxx_clientTrade_42E850(dr *client.Drawable) {
	C.nox_xxx_clientTrade_42E850((*nox_drawable)(dr.C()))
}

func Nox_xxx_clientTalk_42E7B0(dr *client.Drawable) {
	C.nox_xxx_clientTalk_42E7B0((*nox_drawable)(dr.C()))
}

func Nox_xxx_clientCollideOrUse_42E810(dr *client.Drawable) {
	C.nox_xxx_clientCollideOrUse_42E810((*nox_drawable)(dr.C()))
}

func Nox_xxx_packetGetMarshall_476F40() uint32 {
	return uint32(C.nox_xxx_packetGetMarshall_476F40())
}

func Nox_xxx_clientUpdateButtonRow_45E110(ind int) {
	C.nox_xxx_clientUpdateButtonRow_45E110(C.int(ind))
}

func Nox_client_trapSetSelect_4604B0(ind int) {
	C.nox_client_trapSetSelect_4604B0(C.int(ind))
}

func Nox_client_orderCreature(a1, a2 int) {
	C.nox_client_orderCreature(C.int(a1), C.int(a2))
}

func Get_nox_gui_itemAmount_dialog_1319228() *gui.Window {
	return AsWindowP(C.nox_gui_itemAmount_dialog_1319228)
}

func Sub_4C01C0(a1, a2 int, a3 unsafe.Pointer, a4 int) {
	C.sub_4C01C0(C.int(a1), C.int(a2), (*C.int)(a3), C.int(a4))
}

func Nox_client_chatStart_46A430(v int) {
	C.nox_client_chatStart_46A430(C.int(v))
}

func Nox_client_toggleSpellbook_45AC70() {
	C.nox_client_toggleSpellbook_45AC70()
}

func Nox_client_toggleInventory_467C60() {
	C.nox_client_toggleInventory_467C60()
}

func Nox_client_mapZoomIn_4724E0() {
	C.nox_client_mapZoomIn_4724E0()
}

func Nox_client_mapZoomOut_472500() {
	C.nox_client_mapZoomOut_472500()
}

func Nox_client_invAlterWeapon_4672C0() {
	C.nox_client_invAlterWeapon_4672C0()
}

func Nox_client_quickHealthPotion_472220() {
	C.nox_client_quickHealthPotion_472220()
}

func Nox_client_quickManaPotion_472240() {
	C.nox_client_quickManaPotion_472240()
}

func Nox_client_quickCurePoisonPotion_472260() {
	C.nox_client_quickCurePoisonPotion_472260()
}

func Nox_client_spellSetNext_4604F0() {
	C.nox_client_spellSetNext_4604F0()
}

func Nox_client_spellSetPrev_460540() {
	C.nox_client_spellSetPrev_460540()
}

func Nox_client_spellSetSelect_460590() {
	C.nox_client_spellSetSelect_460590()
}

func Nox_client_buildTrap_45E040() {
	C.nox_client_buildTrap_45E040()
}

func Nox_xxx_guiServerOptsLoad_457500() {
	C.nox_xxx_guiServerOptsLoad_457500()
}

func Sub_460630() {
	C.sub_460630()
}
func Nox_xxx_game_4DCCB0() int {
	return int(C.nox_xxx_game_4DCCB0())
}
func Sub_554290() uint32 {
	return uint32(C.sub_554290())
}
func Sub_554300() uint32 {
	return uint32(C.sub_554300())
}
func Nox_client_mousePriKey_430AF0() int {
	return int(C.nox_client_mousePriKey_430AF0())
}
func Sub_42EB90(a1 int) {
	C.sub_42EB90(C.int(a1))
}
func Nox_client_invokeSpellSlot_45DA50(a1 int) {
	C.nox_client_invokeSpellSlot_45DA50(C.int(a1))
}
