package opennox

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_xxx_netServerCmd_440950(id byte, cmd string) {
	buf := make([]byte, 5+2*(len(cmd)+1))
	buf[0] = byte(noxnet.MSG_SERVER_CMD)
	buf[1] = id
	binary.LittleEndian.PutUint16(buf[2:], uint16(legacy.ClientPlayerNetCode()))
	buf[4] = 0
	if cmd != "" {
		buf[4] = byte(len(cmd) + 1)
		alloc.StrCopy16B(buf[5:], cmd)
	}
	binary.LittleEndian.PutUint16(buf[5+2*len(cmd):], 0)
	nox_xxx_netClientSend2_4E53C0(common.MaxPlayers-1, buf, 0, 1)
}

func nox_xxx_serverHandleClientConsole_443E90(pl *Player, a2 byte, cmd string) {
	legacy.Nox_xxx_serverHandleClientConsole_443E90(pl.S(), a2, cmd)
}

func nox_xxx_cmdSayDo_46A4B0(text string, a2 int) {
	legacy.Nox_xxx_cmdSayDo_46A4B0(text, a2)
}

func nox_console_sendSysOpPass_4409D0(pass string) {
	buf := make([]byte, 21)
	buf[0] = byte(noxnet.MSG_SYSOP_PW)
	alloc.StrCopy16B(buf[1:17], pass)
	binary.LittleEndian.PutUint16(buf[17:], 0)
	binary.LittleEndian.PutUint16(buf[19:], uint16(legacy.ClientPlayerNetCode()))
	nox_xxx_netClientSend2_4E53C0(common.MaxPlayers-1, buf, 0, 1)
}
