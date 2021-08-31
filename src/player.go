package main

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
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
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "GAME_data.h"
#include "GAME_data_init.h"
#include "cdrom.h"
#include "client__drawable__drawdb.h"
#include "client__draw__fx.h"
#include "client__draw__image.h"
#include "client__gui__guiinv.h"
#include "client__gui__guimeter.h"
#include "client__gui__guishop.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "client__network__netclint.h"
#include "client__shell__optsback.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "client__video__sdl__draw_nogl.h"
#include "common__config.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME2.h"
#include "GAME3_3.h"
#include "GAME3.h"
#include "GAME4_1.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "input_common.h"
#include "input.h"
#include "movie.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "thing.h"
#include "win.h"
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern nox_playerInfo nox_playerinfo_arr[NOX_PLAYERINFO_MAX];
extern nox_object_t* nox_xxx_host_player_unit_3843628;
void nox_xxx_WideScreenDo_515240(bool enable);
static void nox_xxx_netSendLineMessage_go(nox_object_t* a1, wchar_t* str) {
	nox_xxx_netSendLineMessage_4D9EB0(a1, str);
}
static void nox_xxx_printToAll_4D9FD0_go(int a1, wchar_t* str) {
	nox_xxx_printToAll_4D9FD0(a1, str);
}
*/
import "C"
import (
	"fmt"
	"unsafe"

	"nox/v1/common/memmap"
	"nox/v1/common/player"
	"nox/v1/common/types"
	"nox/v1/server/script"
)

const NOX_PLAYERINFO_MAX = C.NOX_PLAYERINFO_MAX

//export nox_xxx_playerCallDisconnect_4DEAB0
func nox_xxx_playerCallDisconnect_4DEAB0(ind C.int, v C.char) *C.char {
	getPlayerByInd(int(ind)).Disconnect(int(v))
	return nil
}

func getPlayerClass() player.Class {
	return player.Class(memmap.Uint8(0x85B3FC, 12254))
}

func newPlayer(ind int, data unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_playerNew_4DD320(C.int(ind), data))
}

func asPlayer(p *C.nox_playerInfo) *Player {
	return (*Player)(p)
}

func BlindPlayers(blind bool) {
	C.nox_xxx_netMsgFadeBegin_4D9800(C.int(bool2int(!blind)), 0)
}

func CinemaPlayers(cinema bool) {
	C.nox_xxx_WideScreenDo_515240(C.bool(cinema))
}

func PrintToPlayers(text string) {
	cstr := CWString(text)
	defer WStrFree(cstr)
	C.nox_xxx_printToAll_4D9FD0_go(0, cstr)
}

func HostPlayer() *Player {
	// TODO: better way
	for _, p := range getPlayers() {
		if p.IsHost() {
			return p
		}
	}
	return nil
}

var _ noxObject = (*Player)(nil) // proxies Unit

type Player C.nox_playerInfo

func (p *Player) field(off uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(unsafe.Pointer(p)) + off)
}

func (p *Player) Pos() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	u := p.Unit()
	if u == nil {
		return types.Pointf{}
	}
	return u.Pos()
}

func (p *Player) SetPos(pos types.Pointf) {
	if p == nil {
		return
	}
	u := p.Unit()
	if u == nil {
		return
	}
	u.SetPos(pos)
}

func (p *Player) OrigName() string {
	return GoWStringP(p.field(2185))
}

func (p *Player) Name() string {
	return GoWStringP(p.field(4704))
}

func (p *Player) String() string {
	return fmt.Sprintf("Player(%q)", p.Name())
}

func (p *Player) IsHost() bool {
	// TODO: better way
	return p.UnitC() == HostPlayerUnit()
}

func (p *Player) Print(text string) {
	cstr := CWString(text)
	defer WStrFree(cstr)
	C.nox_xxx_netSendLineMessage_go(p.UnitC().CObj(), cstr)
}

func (p *Player) Blind(blind bool) {
	C.nox_xxx_netMsgFadeBeginPlayer(C.int(p.Index()), C.int(bool2int(!blind)), 0)
}

func (p *Player) Cinema(v bool) {
	// TODO: only works for everyone for now
	CinemaPlayers(v)
}

func (p *Player) CObj() *nox_object_t {
	u := p.UnitC()
	if u == nil {
		return nil
	}
	return u.CObj()
}

func (p *Player) GetObject() script.Object {
	u := p.Unit()
	if u == nil {
		return nil
	}
	return u
}

func (p *Player) Unit() script.Unit {
	if p == nil {
		return nil
	}
	return p.UnitC()
}

func HostPlayerUnit() *Unit {
	return asUnit(unsafe.Pointer(C.nox_xxx_host_player_unit_3843628))
}

func (p *Player) C() *C.nox_playerInfo {
	return (*C.nox_playerInfo)(p)
}

func (p *Player) Index() int {
	if p == nil {
		return -1
	}
	return int(p.playerInd)
}

func (p *Player) NetCode() int {
	if p == nil {
		return -1
	}
	return int(p.netCode)
}

func (p *Player) IsActive() bool {
	return p != nil && p.active != 0
}

func (p *Player) UnitC() *Unit {
	if p == nil {
		return nil
	}
	return asUnitC(p.playerUnit)
}

func (p *Player) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return player.Class(p.playerClass)
}

func (p *Player) Disconnect(v int) {
	if !p.IsActive() {
		return
	}
	C.nox_xxx_playerDisconnFinish_4DE530(C.int(p.Index()), C.char(v))
	C.nox_xxx_playerForceDisconnect_4DE7C0(C.int(p.Index()))
	C.sub_4DEC50(C.int(p.Index()))
}

func (p *Player) GoObserver(notify, keepPlayer bool) bool {
	if p == nil {
		return true
	}
	return C.nox_xxx_playerGoObserver_4E6860(p.C(), C.int(bool2int(notify)), C.int(bool2int(keepPlayer))) != 0
}

func cntPlayers() (n int) {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.IsActive() {
			n++
		}
	}
	return n
}

func getPlayers() (out []*Player) {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.IsActive() {
			out = append(out, p)
		}
	}
	return out
}

func getPlayerUnits() (out []*Unit) {
	for _, p := range getPlayers() {
		if u := p.UnitC(); u != nil {
			out = append(out, u)
		}
	}
	return out
}

func getPlayerByInd(i int) *Player {
	if i < 0 || i >= NOX_PLAYERINFO_MAX {
		return nil
	}
	p := asPlayer(&C.nox_playerinfo_arr[i])
	if !p.IsActive() {
		return nil
	}
	p.playerInd = C.uchar(i)
	return p
}

func getPlayerByID(id int) *Player { // nox_common_playerInfoGetByID_417040
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.IsActive() && int(p.netCode) == id {
			return p
		}
	}
	return nil
}

func hasPlayerUnits() bool {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.UnitC() != nil {
			return true
		}
	}
	return false
}
