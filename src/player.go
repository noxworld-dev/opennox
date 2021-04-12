package main

/*
#include "proto.h"
extern nox_playerInfo nox_playerinfo_arr[NOX_PLAYERINFO_MAX];
*/
import "C"
import "unsafe"

const NOX_PLAYERINFO_MAX = C.NOX_PLAYERINFO_MAX

func asPlayer(p *C.nox_playerInfo) *Player {
	return (*Player)(p)
}

type Player C.nox_playerInfo

type Unit = unsafe.Pointer

func (p *Player) C() *C.nox_playerInfo {
	return (*C.nox_playerInfo)(p)
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
