package opennox

import (
	"bytes"
	"encoding/binary"
	"encoding/hex"
	"errors"
	"fmt"
	"image"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_netOnPacketRecvCli_48EA70(ind ntype.PlayerInd, buf *byte, sz int) int {
	return noxClient.nox_xxx_netOnPacketRecvCli48EA70(ind, unsafe.Slice(buf, sz))
}

func nox_xxx_netHandleCliPacket_43C860(_ netstr.Handle, data []byte) int {
	op := noxnet.Op(data[0])
	noxPerfmon.packetSizeCli = len(data)
	if op == noxnet.MSG_XXX_STOP {
		sub_446380()
	} else if op == noxnet.MSG_PING {
		noxPerfmon.ping = time.Duration(binary.LittleEndian.Uint32(data[1:])) * time.Millisecond
	} else if op >= noxnet.MSG_TIMESTAMP {
		noxClient.nox_xxx_netOnPacketRecvCli48EA70(server.HostPlayerIndex, data)
		if nox_client_isConnected() {
			legacy.Sub_48D660()
		}
	}
	lastCliHandlePackets = platformTicks()
	if dword_5d4594_815704 {
		legacy.Sub_4AB4A0(0)
		dword_5d4594_815704 = false
	}
	if dword_5d4594_815708 {
		sub_43CF40()
	}
	return 1
}

func (c *Client) nox_xxx_netOnPacketRecvCli48EA70_switch(ind ntype.PlayerInd, op noxnet.Op, data []byte, localFrame *uint32, localFrame16 *uint16) int {
	if len(data) == 0 {
		return 0
	}
	if n, ok, err := c.Client.OnClientPacketOpSub(ind, op, data, localFrame, localFrame16, client.CurPlayerInfo{
		Connected: nox_client_isConnected(),
		Class:     getPlayerClass(),
	}); err != nil {
		return -1
	} else if ok {
		return n
	}
	switch op {
	case noxnet.MSG_FULL_TIMESTAMP:
		var p noxnet.MsgFullTimestamp
		n, err := p.Decode(data[1:])
		if err != nil {
			return -1
		}
		frame := p.T
		*localFrame = frame
		c.tsFullPRev = frame
		c.tsUpperPrev = (frame & 0xffff) >> 14
		c.srv.SetFrame(frame)
		if p := getCurPlayer(); p != nil {
			legacy.Nox_xxx_playerUnsetStatus_417530(p, 64)
		}
		legacy.Sub_43C650()
		return 1 + n
	case noxnet.MSG_SIMULATED_TIMESTAMP:
		frame := uint32(*localFrame16)
		if frame < (c.tsFullPRev + sub_43C790()) {
			c.srv.SetFrame(frame)
		}
		return 5
	case noxnet.MSG_TIMESTAMP:
		var p noxnet.MsgTimestamp
		n, err := p.Decode(data[1:])
		if err != nil {
			return -1
		}
		fr16 := p.T
		*localFrame16 = fr16
		if p := getCurPlayer(); p != nil && p.Field3680&0x40 != 0 {
			return 1 + n
		}
		v9 := true
		prevFrame := c.srv.Frame()
		fullFrame := uint32(fr16) + (c.srv.Frame() & 0xFFFF0000)
		if upper := uint32(fr16) >> 14; upper != c.tsUpperPrev {
			if upper == ((uint32(c.tsUpperPrev&0xff) + 1) & 3) {
				c.tsUpperPrev = upper
				if upper == 0 {
					fullFrame += 0x10000
				}
			} else {
				v9 = false
			}
		}
		if fullFrame < c.srv.Frame() {
			v9 = false
		}
		if !noxflags.HasGame(noxflags.GameHost) && v9 {
			c.srv.SetFrame(fullFrame)
			c.tsFullPRev = fullFrame
		}
		*localFrame = fullFrame
		if !noxflags.HasGame(noxflags.GameHost) && !v9 {
			noxPerfmon.latePackets--
			*memmap.PtrUint32(0x85B3FC, 120)++
		} else {
			if c.srv.Frame() > prevFrame+1 {
				noxPerfmon.latePackets += int(c.srv.Frame() - prevFrame)
			}
			legacy.Sub_43C650()
		}
		return 1 + n
	case noxnet.MSG_RATE_CHANGE:
		if nox_client_isConnected() {
			sub_43C7A0(uint32(data[1]))
		}
		return 1 + 1
	case noxnet.MSG_SERVER_QUIT:
		var buf [1]byte
		buf[0] = byte(noxnet.MSG_SERVER_QUIT_ACK)
		netstrGetClientIndex().Send(buf[:1], netstr.SendFlush)
		sub_446380()
		return 1
	case noxnet.MSG_USE_MAP:
		var p noxnet.MsgUseMap
		n, err := p.Decode(data[1:])
		if err != nil {
			return -1
		}
		if mframe := p.T; mframe > uint32(legacy.Get_dword_5d4594_1200804()) {
			noxSetUseMapFrame(int(mframe))
			c.nox_xxx_gameClearAll_467DF0(true)
			c.srv.nox_xxx_gameSetMapPath_409D70(p.MapName.Value)
			nox_xxx_mapSetCrcMB_409B10(p.CRC)
			if !noxflags.HasGame(noxflags.GameHost) {
				noxflags.UnsetGame(noxflags.GameFlag4)
				if legacy.Get_dword_5d4594_2650652() != 0 {
					legacy.Sub_41D6C0()
				}
			}
			noxflags.SetGame(noxflags.GameFlag24)
			legacy.Set_dword_5d4594_1200804(c.srv.Frame())
			nox_xxx_gameSetCliConnected(false)
			legacy.Sub_49C7A0()
			legacy.Nox_xxx_guiServerOptionsHide_4597E0(0)
			sub_44A400()
		}
		return 1 + n
	case noxnet.MSG_JOIN_DATA:
		var p noxnet.MsgJoinData
		n, err := p.Decode(data[1:])
		if err != nil {
			return -1
		}
		playerID := nox_xxx_netClearHighBit_578B30(p.NetCode)
		legacy.ClientSetPlayerNetCode(int(playerID))
		pl := c.srv.Players.NewRaw(int(playerID))
		if pl != nil {
			pl.Field2068 = p.Unk2
			setCurPlayer(pl)
		}
		if !noxflags.HasGame(noxflags.GameHost) {
			legacy.Sub_57B920(memmap.PtrOff(0x5D4594, 1198020))
		}
		legacy.Set_dword_5d4594_1200804(0)
		noxPerfmon.latePackets = 0
		*memmap.PtrUint32(0x85B3FC, 120) = 0
		noxPerfmon.ping = 0
		legacy.Set_dword_5d4594_1200832(0)
		legacy.Nox_xxx_cliSetSettingsAcquired_4169D0(0)
		return 1 + n
	case noxnet.MSG_NEW_PLAYER:
		if len(data) < 129 {
			return -1
		}
		playerID := nox_xxx_netClearHighBit_578B30(binary.LittleEndian.Uint16(data[1:]))
		pl := c.srv.Players.NewRaw(int(playerID))
		if pl == nil {
			return 129
		}
		if !noxflags.HasGame(noxflags.GameHost) {
			pl.NetCodeVal = uint32(playerID)
			pl.Lessons = int32(int16(binary.LittleEndian.Uint16(data[100:])))
			pl.Field2140 = uint32(int32(int16(binary.LittleEndian.Uint16(data[102:]))))
			pl.ArmorEquip = binary.LittleEndian.Uint32(data[104:])
			pl.WeaponEquip = binary.LittleEndian.Uint32(data[108:])
			pl.Field2152 = uint32(data[116])
			pl.Field2156 = uint32(data[117])
			pl.SetField2096(alloc.GoStringS(data[119:]))
			pl.Field3680 |= binary.LittleEndian.Uint32(data[112:])
			pl.Info()
			*pl.Info() = *(*server.PlayerInfo)(unsafe.Pointer(&data[3 : 3+97][0])) // TODO: safe copy
			pl.SetName(pl.Info().Name() + pl.Info().NameSuff())
			if legacy.Get_dword_5d4594_2650652() != 0 {
				pl.Field2108 = 0
				legacy.Sub_41D670(pl.Field2096())
			}
			legacy.Nox_xxx_playerInitColors_461460(pl)
		}
		legacy.Sub_457140(int(playerID), &pl.NameFinal[0])
		legacy.Sub_455920(&pl.NameFinal[0])
		if gameGetPlayState() == 3 {
			format := c.Strings().GetStringInFile("PlayerJoined", "cdecode.c")
			nox_xxx_printCentered_445490(fmt.Sprintf(format, pl.Name()))
		}
		if uint32(playerID) == uint32(legacy.ClientPlayerNetCode()) && alloc.GoString16((*uint16)(memmap.PtrOff(0x85B3FC, 12204))) != pl.Name() {
			legacy.Set_dword_5d4594_1200832(1)
		}
		return 129
	case noxnet.MSG_PLAYER_QUIT:
		if len(data) < 3 {
			return -1
		}
		if !nox_client_isConnected() {
			return 3
		}

		playerID := nox_xxx_netClearHighBit_578B30(binary.LittleEndian.Uint16(data[1:]))
		pl := c.srv.Players.ByID(int(playerID))
		var msg string
		if pl != nil {
			legacy.Sub_456DF0(int(playerID))
			legacy.Sub_455950(&pl.NameFinal[0])
			format := c.Strings().GetStringInFile("PlayerLeft", "cdecode.c")
			msg = fmt.Sprintf(format, pl.Name())

			pl.Active = 0
			tobj := nox_xxx_objGetTeamByNetCode_418C80(int(playerID))
			if tobj != nil && tobj.Has() {
				legacy.Nox_xxx_netChangeTeamMb_419570(tobj, uint32(playerID))
			}
		} else {
			msg = c.Strings().GetStringInFile("UnknownLeft", "cdecode.c")
		}
		if gameGetPlayState() == 3 {
			nox_xxx_printCentered_445490(msg)
		}
		return 3
	case noxnet.MSG_REPORT_SPELL_START:
		if len(data) < 2 {
			return -1
		}
		legacy.Sub_49BB80(data[1])
		return 2
	case noxnet.MSG_REPORT_INVENTORY_LOADED:
		legacy.Sub_467CA0()
		return 1
	case noxnet.MSG_FX_DEATH_RAY:
		if len(data) < 9 {
			return -1
		}
		p1x := binary.LittleEndian.Uint16(data[1:])
		p1y := binary.LittleEndian.Uint16(data[3:])
		p2x := binary.LittleEndian.Uint16(data[5:])
		p2y := binary.LittleEndian.Uint16(data[7:])
		c.clientFXDeathRay(image.Pt(int(p1x), int(p1y)), image.Pt(int(p2x), int(p2y)))
		return 9
	case noxnet.MSG_FX_PARTICLEFX:
		if len(data) < 14 {
			return -1
		}
		if nox_client_isConnected() {
			dr := c.Objs.ByNetCode(binary.LittleEndian.Uint16(data[8:]))
			c.r.partfx.onParticleFx(data[1], dr, int(binary.LittleEndian.Uint16(data[2:])), binary.LittleEndian.Uint16(data[4:]) != 0, int(binary.LittleEndian.Uint16(data[6:])))
		}
		return 14
	case noxnet.MSG_IMPORTANT:
		n := 1
		if noxflags.HasGame(noxflags.GameHost) {
			n = 5
		}
		if len(data) < n {
			return -1
		}
		if nox_client_isConnected() {
			var buf [5]byte
			buf[0] = byte(noxnet.MSG_IMPORTANT_ACK)
			if noxflags.HasGame(noxflags.GameHost) {
				v := binary.LittleEndian.Uint32(data[1:])
				binary.LittleEndian.PutUint32(buf[1:], v)
			} else {
				binary.LittleEndian.PutUint32(buf[1:], *localFrame)
			}
			c.srv.NetList.AddToMsgListCli(ind, 0, buf[:5])
		}
		return n
	case noxnet.MSG_MAP_SEND_START:
		if len(data) < 88 {
			return -1
		}
		sz := binary.LittleEndian.Uint32(data[4:])
		name := alloc.GoStringS(data[8:88])
		c.mapsend.onMapDownloadStart(name, uint(sz))
		return 88
	case noxnet.MSG_MAP_SEND_PACKET:
		if len(data) < 6 {
			return -1
		}
		bind := binary.LittleEndian.Uint16(data[2:])
		sz := binary.LittleEndian.Uint16(data[4:])
		c.mapsend.onMapDownloadPart(uint(bind), data[6:6+sz])
		return 6 + int(sz)
	case noxnet.MSG_MAP_SEND_ABORT:
		if len(data) < 2 {
			return -1
		}
		c.mapsend.onMapDownloadAbort()
		return 2
	case noxnet.MSG_FADE_BEGIN:
		var p noxnet.MsgFadeBegin
		n, err := p.Decode(data[1:])
		if err != nil {
			return -1
		}
		if nox_client_isConnected() && !noxflags.HasEngine(noxflags.EngineNoRendering) {
			if p.Out == 1 {
				legacy.Set_nox_gameDisableMapDraw_5d4594_2650672(0)
				sub_413A00(1)
			}
			c.clientPacketFade(p.Menu == 1, p.Out == 1)
		}
		return 1 + n
	case noxnet.MSG_DIALOG:
		if len(data) < 2 {
			return -1
		}
		typ := data[1]
		switch typ {
		case 3:
			if len(data) < 135 {
				return -1
			}
			if nox_client_isConnected() {
				str := strman.ID(alloc.GoStringS(data[2:34]))
				title := alloc.GoString16B(data[34:98])
				snd := sound.ID(binary.LittleEndian.Uint32(data[98:]))
				pic := alloc.GoStringS(data[102:134])
				flags := server.DialogFlags(data[134])
				guiOpenNPCDialogID(title, snd, str, pic, flags)
				if pl := getCurPlayer(); pl != nil {
					legacy.Nox_xxx_netNeedTimestampStatus_4174F0(pl, 512)
				}
			}
			return 135
		case 4:
			if nox_client_isConnected() {
				guiCloseNPCDialog()
				if pl := getCurPlayer(); pl != nil {
					legacy.Nox_xxx_playerUnsetStatus_417530(pl, 512)
				}
			}
			return 2
		}
		return -1
	case noxnet.MSG_XFER_MSG:
		var p noxnet.MsgXfer
		n, err := p.Decode(data[1:])
		if err != nil {
			return -1
		}
		conn := netstrGetClientIndex()
		switch x := p.Msg.(type) {
		case *noxnet.MsgXferStart:
			xferRecvr.HandleStart(conn, c.Server.Frame(), x.Act, x.Type.Value, x.Size, x.Token)
		case *noxnet.MsgXferState:
			switch x.Code {
			case noxnet.XferAccept:
				xferSendr.HandleAccept(conn, x.Stream, x.Token)
			case noxnet.XferCode5:
				xferRecvr.HandleCancel(x.Token, x.Stream)
			case noxnet.XferCode6:
				xferSendr.HandleAbort(conn, x.Token, x.Stream)
			}
		case *noxnet.MsgXferData:
			xferRecvr.HandleData(conn, c.Server.Frame(), x.Stream, x.Chunk, x.Data)
		case *noxnet.MsgXferAck:
			xferSendr.HandleAck(conn, x.Stream, x.Chunk)
		case *noxnet.MsgXferClose:
			xferSendr.HandleDone(conn, x.Stream)
		}
		return 1 + n
	case noxnet.MSG_TEXT_MESSAGE:
		var p noxnet.MsgText
		n, err := p.Decode(data[1:])
		if err != nil {
			return -1
		}
		netcode := p.NetCode

		// Buffer size in vanilla: 636
		text := p.Text()
		if p.Flags.Has(noxnet.TextLocalized) { // Localized
			name := strman.ID(text)
			text = c.Strings().GetStringInFile(name, "cdecode.c")
		} else {
			if p.Flags.Has(noxnet.TextTeam) { // Team chat
				tstr := c.Strings().GetStringInFile("Guirank.c:team", "cdecode.c")
				text = fmt.Sprintf("%s: %s", tstr, text)
			}
		}
		msz := 1 + n
		if !nox_client_isConnected() {
			return msz
		}
		if gameGetPlayState() != 3 {
			return msz
		}
		if p.Flags.Has(noxnet.TextNotice) { // Notice
			str := c.Strings().GetStringInFile("guiserv.c:Notice", "cdecode.c")
			NewDialogWindow(nil, str, text, gui.DialogFlag6|gui.DialogOKButton, nil, nil)
			return msz
		}
		if netcode == 0 { // From server
			nox_xxx_printCentered_445490(text)
			return msz
		}
		pl := c.Server.Players.ByID(int(netcode))
		if pl != nil { // From player
			if !nox_xxx_playerCantTalkMB_57A160(pl) {
				c.Printf(console.ColorYellow, "%s> %s", pl.Name(), text)
				legacy.Nox_xxx_createTextBubble_48D880(data, text)
			}
			return msz
		}
		// From object
		legacy.Nox_xxx_createTextBubble_48D880(data, text)
		if dr := c.Objs.ByNetCode(netcode); dr != nil {
			var pname string
			if t := c.Things.TypeByInd(int(dr.TypeIDVal)); t != nil {
				pname = alloc.GoString16(t.PrettyName)
			}
			c.Printf(console.ColorRed, "%s(%d)> %s", pname, netcode, text)
		}
		return msz
	}
	return legacy.Nox_xxx_netOnPacketRecvCli_48EA70_switch(ind, op, data)
}

func (c *Client) HandleMessage(ind ntype.PlayerInd, msg noxnet.Message) int {
	// TODO: avoid re-encoding
	buf, err := noxnet.AppendPacket(nil, msg)
	if err != nil {
		panic(err)
	}
	return c.nox_xxx_netOnPacketRecvCli48EA70(ind, buf)
}

func (c *Client) nox_xxx_netOnPacketRecvCli48EA70(ind ntype.PlayerInd, data []byte) int {
	orig := data
	var iters [][]byte
	c.guiFPS.sub_470A80()
	var (
		localFrame   uint32
		localFrame16 uint16
	)
	for len(data) > 0 {
		op := noxnet.Op(data[0])
		n := c.nox_xxx_netOnPacketRecvCli48EA70_switch(ind, op, data, &localFrame, &localFrame16)
		if n == 0 {
			break // stop earlier
		} else if n < 0 {
			return 0 // error
		}
		if n == 0 { // safeguard
			n = 1
		}
		if n > len(data) {
			var buf bytes.Buffer
			fmt.Fprintf(&buf, "overflow when handling net packet: [%d:%d]\n", n, len(data))
			fmt.Fprintf(&buf, "PACKET: (%d bytes)\n", len(orig))
			buf.WriteString(hex.EncodeToString(orig))
			buf.WriteString("\n")
			buf.WriteString("SPLIT:\n")
			for _, b := range iters {
				buf.WriteString(hex.EncodeToString(b))
				buf.WriteString("\n")
			}
			buf.WriteString(hex.EncodeToString(data))
			buf.WriteString("\n")
			panic(errors.New(buf.String()))
		}
		iters = append(iters, data[:n])
		noxOnCliPacketDebug(op, data[:n])
		data = data[n:]
	}
	return 1
}
