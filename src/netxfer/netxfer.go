package netxfer

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

const (
	minStreams = 16
	maxStreams = 256
)

type Action byte

type Time = uint32

type chunkInd uint16

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

func (x *NetXfer) Send(conn netstr.Handle, act Action, typ string, data []byte, onDone DoneFunc, onAbort AbortFunc) bool {
	return x.send.Send(conn, act, typ, data, onDone, onAbort)
}

func (x *NetXfer) CancelSend(conn netstr.Handle) {
	x.send.Cancel(conn)
}

func (x *NetXfer) Handle(conn netstr.Handle, ts Time, m *noxnet.MsgXfer) {
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
