//go:build !server

package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
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
	c.info.Free()
	c.Server.NPCs.Init()
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
	s := noxServer
	c := noxClient
	legacy.Nox_xxx_spriteDeleteSomeList_49C4B0()
	start := s.Frame()
	c.Conn.RecvLoop(false)
	if start != s.Frame() && legacy.Get_dword_5d4594_2650652() == 1 && !noxflags.HasGame(noxflags.GameHost) {
		if v1 := legacy.Sub_40A710(1); sub_43C790() > v1 {
			legacy.Sub_43CEB0()
			v2 := memmap.Uint64(0x5D4594, 815740) + memmap.Uint64(0x587000, 91880)/uint64(sub_43C790())
			if platformTicks() >= v2 {
				buf, err := noxnet.AppendPacket(nil, &noxnet.MsgFullTimestamp{
					T: s.Frame() + 1,
				})
				if err != nil {
					panic(err)
				}
				c.nox_xxx_netOnPacketRecvCli48EA70(server.HostPlayerIndex, buf)
			}
		}
	}

	if dt := platformTicks() - ticks815724; dt >= 2000 {
		ticks815724 = platformTicks()
		c.Conn.SendCode6()
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		legacy.Nox_xxx_netImportant_4E5770(0x1F, 0)
	}
	s.nox_xxx_netSendBySock_40EE10(c.Conn, server.HostPlayerIndex, netlist.Kind0)
	s.NetStr.MaybeSendReliable()
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
