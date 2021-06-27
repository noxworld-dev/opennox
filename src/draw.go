package main

/*
#include "proto.h"
#include "client__system__client.h"
#include "client__gui__guiquit.h"
#include "client__gui__guiggovr.h"
*/
import "C"
import (
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
)

func nox_xxx_client_435F80_draw() bool {
	mpos := nox_mouse.pos
	if C.nox_xxx_serverIsClosing_446180() != 0 {
		C.sub_446190()
	}
	if C.sub_437060() == 0 && !noxflags.HasGame(8) {
		nox_xxx_setContinueMenuOrHost_43DDD0(0)
		return false
	}
	C.sub_437100()
	if C.sub_478030() == 0 && !nox_xxx_guiCursor_477600() {
		C.sub_470DE0()
	}
	ctrlEvent.nox_xxx_input_42D220()
	if C.nox_xxx_get_430890() == 1 {
		C.sub_430880(0)
	}
	C.nox_xxx_clientEnumHover_476FA0()
	vp := noxGetViewport()
	ipx := int(vp.field_4) + mpos.X - int(vp.x1)
	ipy := int(vp.field_5) + mpos.Y - int(vp.y1)
	if !clientSendInput(31, uint16(ipx), uint16(ipy)) {
		return true
	}
	if !noxflags.HasGame(1) {
		C.sub_40B970()
		C.sub_40B790()
	}
	if noxflags.HasGame(1) {
		C.nox_xxx_spriteDeleteSomeList_49C4B0()
		if C.nox_netlist_receiveCli_494E90(31) == 0 {
			return true
		}
	} else {
		C.sub_43CCA0()
	}
	C.sub_49BD70(vp)
	C.sub_49BBC0()
	C.nox_xxx_polygonDrawColor_421B80()
	if C.nox_client_isConnected_43C700() != 0 {
		C.nox_xxx_cliToggleObsWindow_4357A0()
	}
	C.nox_xxx_clientDrawAll_436100_draw()
	C.sub_49BB40()
	C.sub_49BA70()
	if C.sub_409F40(4096) != 0 {
		C.nox_xxx_screenshot_46D830()
	}
	if memmap.Uint32(0x5D4594, 826068) != 0 {
		C.nox_xxx_motd_4467F0()
	}
	if C.sub_42EBA0() == 1 {
		C.sub_42EB90(0)
		C.nox_xxx_consoleEsc_49B7A0()
	}
	C.sub_49B6E0()
	return C.int(memmap.Uint32(0x587000, 85720)) != 0
}
