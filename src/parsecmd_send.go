package opennox

/*
#include "GAME2_1.h"
#include "client__system__parsecmd.h"
*/
import "C"

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
)

func nox_xxx_netServerCmd_440950(id byte, cmd string) {
	buf := make([]byte, 5+2*(len(cmd)+1))
	buf[0] = byte(noxnet.MSG_SERVER_CMD)
	buf[1] = id
	binary.LittleEndian.PutUint16(buf[2:], uint16(clientPlayerNetCode()))
	buf[4] = 0
	if cmd != "" {
		buf[4] = byte(len(cmd) + 1)
		WStrCopyBytes(buf[5:], cmd)
	}
	binary.LittleEndian.PutUint16(buf[5+2*len(cmd):], 0)
	nox_xxx_netClientSend2_4E53C0(common.MaxPlayers-1, buf, 0, 1)
}

func nox_xxx_serverHandleClientConsole_443E90(pl *Player, a2 byte, cmd string) {
	cstr, free := CWString(cmd)
	defer free()
	C.nox_xxx_serverHandleClientConsole_443E90(pl.C(), C.char(a2), cstr)
}

func nox_xxx_cmdSayDo_46A4B0(text string, a2 int) {
	cstr, free := CWString(text)
	defer free()
	C.nox_xxx_cmdSayDo_46A4B0(cstr, C.int(a2))
}

func nox_console_sendSysOpPass_4409D0(pass string) {
	buf := make([]byte, 21)
	buf[0] = byte(noxnet.MSG_SYSOP_PW)
	WStrCopyBytes(buf[1:17], pass)
	binary.LittleEndian.PutUint16(buf[17:], 0)
	binary.LittleEndian.PutUint16(buf[19:], uint16(clientPlayerNetCode()))
	nox_xxx_netClientSend2_4E53C0(common.MaxPlayers-1, buf, 0, 1)
}
