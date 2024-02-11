package netxfer

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/noxnet/xfer"

	"github.com/noxworld-dev/opennox/v1/server/netlib"
)

const (
	minStreams = 16
	maxStreams = 256
)

type Action = xfer.Action

type Time = uint32

type NetXfer struct {
	send sender
	recv receiver
}

func (x *NetXfer) Init(n int, onRecv ReceiveFunc) {
	x.send.Init(n)
	x.recv.Init(n, onRecv)
}

func (x *NetXfer) Free() {
	x.send.Free()
	x.recv.Free()
}

func (x *NetXfer) Update(ts Time) {
	x.send.Update(ts)
	x.recv.Update(ts)
}

func (x *NetXfer) Send(conn netlib.SendStream, act Action, typ string, data []byte, onDone DoneFunc, onAbort AbortFunc) bool {
	return x.send.Send(conn, act, typ, data, onDone, onAbort)
}

func (x *NetXfer) CancelSend(conn netlib.SendStream) {
	x.send.Cancel(conn)
}

func (x *NetXfer) Handle(conn netlib.SendStreamID, ts Time, m *noxnet.MsgXfer) {
	switch m := m.Msg.(type) {
	case *xfer.MsgStart:
		x.recv.HandleStart(conn, ts, m)
	case *xfer.MsgAccept:
		x.send.HandleAccept(conn, m)
	case *xfer.MsgCancel:
		x.recv.HandleCancel(m)
	case *xfer.MsgAbort:
		x.send.HandleAbort(conn, m)
	case *xfer.MsgData:
		x.recv.HandleData(conn.Player(), conn, ts, m)
	case *xfer.MsgAck:
		x.send.HandleAck(conn, m)
	case *xfer.MsgDone:
		x.send.HandleDone(conn, m)
	}
}
