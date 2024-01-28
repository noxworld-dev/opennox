package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

const (
	netXferDef = 16
	netXferMax = 256
)

var netXfer NetXfer

type NetXfer struct {
	send xferSender
	recv xferReceiver
}

func (x *NetXfer) Init(n int) {
	x.send.Init(n)
	x.recv.Init(n)
}

func (x *NetXfer) Free() {
	x.send.Free()
	x.recv.Free()
}

func (x *NetXfer) Update(ts uint32) {
	x.send.Update(ts)
	x.recv.Update(ts)
}

func (x *NetXfer) Send(pli ntype.PlayerInd, act byte, typ string, data []byte, remote bool) {
	x.send.Send(pli, act, typ, data, remote)
}

func (x *NetXfer) CancelSend(conn netstr.Handle) {
	x.send.Cancel(conn)
}

func (x *NetXfer) Handle(conn netstr.Handle, ts uint32, m *noxnet.MsgXfer) {
	switch m := m.Msg.(type) {
	case *noxnet.MsgXferStart:
		x.recv.HandleStart(conn, ts, m)
	case *noxnet.MsgXferState:
		switch m.Code {
		case noxnet.XferAccept:
			x.send.HandleAccept(conn, m)
		case noxnet.XferCode5:
			x.recv.HandleCancel(m)
		case noxnet.XferCode6:
			x.send.HandleAbort(conn, m)
		}
	case *noxnet.MsgXferData:
		x.recv.HandleData(conn, ts, m)
	case *noxnet.MsgXferAck:
		x.send.HandleAck(conn, m)
	case *noxnet.MsgXferClose:
		x.send.HandleDone(conn, m)
	}
}
