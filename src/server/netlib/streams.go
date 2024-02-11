package netlib

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
)

const (
	SendQueue = SendFlags(0x1)
	SendFlush = SendFlags(0x2)
)

type SendFlags int

func (v SendFlags) Has(v2 SendFlags) bool {
	return v&v2 != 0
}

const (
	RecvCanRead = RecvFlags(0x1)
	RecvNoHooks = RecvFlags(0x2)
	RecvJustOne = RecvFlags(0x4)
)

type RecvFlags int

func (v RecvFlags) Has(v2 RecvFlags) bool {
	return v&v2 != 0
}

type StreamID interface {
	IsHost() bool
	Player() ntype.PlayerInd
}

type StreamStats interface {
	StreamID
	TransferStats() uint32
}

type Stream interface {
	StreamID
	StreamStats
	SendStream
}

type SendStream interface {
	StreamID
	Send(buf []byte, flags SendFlags) (int, error)
	SendMsg(msg noxnet.Message, flags SendFlags) (int, error)
	SendReadPacket(noHooks bool) int
}

type SendStreamID interface {
	StreamID
	SendStream
}

type Streams interface {
	HostStream() Stream
	StreamByPlayerInd(pid ntype.PlayerInd) Stream
}
