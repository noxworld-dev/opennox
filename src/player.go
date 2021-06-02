package main

/*
#include "proto.h"
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern nox_playerInfo nox_playerinfo_arr[NOX_PLAYERINFO_MAX];
extern unsigned int nox_xxx_host_player_unit_3843628;
void nox_xxx_WideScreenDo_515240(bool enable);
static void nox_xxx_netSendLineMessage_go(void* a1, wchar_t* str) {
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
	return player.Class(memmap.Uint8(0x5D4594, 2661958))
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

var _ noxObject = (*Player)(nil) // proxies Unit

type Player C.nox_playerInfo

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

func (p *Player) Name() string {
	// TODO: may be wrong field; candidates: 2185, 4704
	return GoWString((*C.wchar_t)(unsafe.Pointer(uintptr(unsafe.Pointer(p)) + 2185)))
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

func (p *Player) CObj() unsafe.Pointer {
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
	return asUnit(unsafe.Pointer(uintptr(C.nox_xxx_host_player_unit_3843628)))
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
	return asUnit(p.playerUnit)
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

func getPlayers() (out []*Player) {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.IsActive() {
			out = append(out, p)
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

func hasPlayerUnits() bool {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.UnitC() != nil {
			return true
		}
	}
	return false
}
