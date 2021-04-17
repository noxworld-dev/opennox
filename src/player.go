package main

/*
#include "proto.h"
extern nox_playerInfo nox_playerinfo_arr[NOX_PLAYERINFO_MAX];
extern unsigned int nox_xxx_host_player_unit_3843628;
*/
import "C"
import "unsafe"

const NOX_PLAYERINFO_MAX = C.NOX_PLAYERINFO_MAX

//export nox_xxx_playerCallDisconnect_4DEAB0
func nox_xxx_playerCallDisconnect_4DEAB0(ind C.int, v C.char) *C.char {
	getPlayerByInd(int(ind)).Disconnect(int(v))
	return nil
}

func newPlayer(ind int, data unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_playerNew_4DD320(C.int(ind), data))
}

func asPlayer(p *C.nox_playerInfo) *Player {
	return (*Player)(p)
}

type Player C.nox_playerInfo

type Unit = unsafe.Pointer

func HostPlayerUnit() Unit {
	return Unit(uintptr(C.nox_xxx_host_player_unit_3843628))
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

func (p *Player) IsActive() bool {
	return p != nil && p.active != 0
}

func (p *Player) Unit() Unit {
	if p == nil {
		return nil
	}
	return p.playerUnit
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
		if p.Unit() != nil {
			return true
		}
	}
	return false
}
