//go:build !server

package opennox

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func sub_4349C0(cl [3]uint32) {
	noxClient.R2().Data().SetLightColor(noxrender.RGB{
		R: int(cl[0]),
		G: int(cl[1]),
		B: int(cl[2]),
	})
}

func (c *Client) nox_xxx_gameClearAll_467DF0(a1 bool) {
	sub_4460A0(0)
	if legacy.Sub_47A260() == 1 {
		guiCloseNPCDialog()
	}
	if legacy.Sub_478030() == 1 {
		legacy.Sub_479280()
	}
	legacy.Sub_45D810()
	legacy.Nox_xxx_gameDeleteSpiningCrownSkull_4B8220()
	legacy.Nox_alloc_npcs()
	legacy.Sub_4573B0()
	acl := [3]uint32{
		25, 25, 25,
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		sub_469B90(acl)
		sub_4349C0(acl)
		legacy.Sub_421B10()
	}
	legacy.Nox_xxx_spriteDeleteSomeList_49C4B0()
	legacy.Nox_xxx_sprite_49C4F0()
	legacy.Sub_49A630()
	legacy.Sub_49BBB0()
	nox_client_resetScreenParticles_431510()
	c.Nox_xxx_spriteDeleteAll_45A5E0(a1)
	if !noxflags.HasGame(noxflags.GameHost) {
		c.srv.Walls.Reset()
		legacy.Nox_xxx_mapSwitchLevel_4D12E0_tileFree()
	}
}

func sub_43CCA0() {
	legacy.Nox_xxx_spriteDeleteSomeList_49C4B0()
	start := noxServer.Frame()
	netstrClientConn.RecvLoop(netstr.RecvCanRead)
	if start != noxServer.Frame() && legacy.Get_dword_5d4594_2650652() == 1 && !noxflags.HasGame(noxflags.GameHost) {
		if v1 := legacy.Sub_40A710(1); sub_43C790() > v1 {
			legacy.Sub_43CEB0()
			v2 := memmap.Uint64(0x5D4594, 815740) + memmap.Uint64(0x587000, 91880)/uint64(sub_43C790())
			if platformTicks() >= v2 {
				buf, free := alloc.Make([]byte{}, 8) // TODO: check if we need extra space
				defer free()
				buf[0] = byte(noxnet.MSG_FULL_TIMESTAMP)
				binary.LittleEndian.PutUint32(buf[1:], noxServer.Frame()+1)
				noxClient.nox_xxx_netOnPacketRecvCli48EA70(common.MaxPlayers-1, buf[:5])
			}
		}
	}

	if dt := platformTicks() - ticks815724; dt >= 2000 {
		ticks815724 = platformTicks()
		netstr.Global.SendCode6(netstrClientConn)
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		legacy.Nox_xxx_netImportant_4E5770(0x1F, 0)
	}
	nox_xxx_netSendBySock_40EE10(netstrClientConn, common.MaxPlayers-1, netlist.Kind0)
	netstr.Global.MaybeSendQueues()
	if lastCliHandlePackets == 0 {
		return
	}

	if dt := platformTicks() - lastCliHandlePackets; dt > 2000 && !dword_5d4594_815704 {
		dword_5d4594_815704 = true
		legacy.Sub_4AB4A0(1)
		ticks815732 = platformTicks()
	}
	if lastCliHandlePackets == 0 {
		return
	}

	if dt := platformTicks() - lastCliHandlePackets; dt <= 20000 || dword_5d4594_815708 {
		return
	}

	if dt := platformTicks() - ticks815732; dt > 20000 {
		sub_43CF70()
	}
}
