package netlib

import (
	"net/netip"
	"time"

	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
)

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
	String() string
	IsHost() bool
	Player() ntype.PlayerInd
	IP() netip.Addr
	Addr() netip.AddrPort
}

type StreamStats interface {
	StreamID
	TransferStats() uint32
}

type Stream interface {
	StreamID
	StreamStats
	SendStream
	RecvStream
	Close() error
}

type RecvStream interface {
	StreamID
	RecvLoop(noHooks bool) int
}

type SendStream interface {
	StreamID

	SendUnreliable(buf []byte, flush bool) (int, error)
	SendUnreliableMsg(msg noxnet.Message, flush bool) (int, error)

	SendReliable(buf []byte) (int, error)
	SendReliableMsg(msg noxnet.Message) (int, error)
	ReliableInQueue(ops ...noxnet.Op) int

	Flush() error
	FlushAndPoll() error
	SendCode6() int
	SendClose()
	SendCode11()
}

type SendStreamID interface {
	StreamID
	SendStream
}

type Streams interface {
	HostStream() Stream
	StreamByPlayerInd(pid ntype.PlayerInd) Stream
	MaybeSendReliable()
	ProcessStats(min, max time.Duration)
	GetTimingByInd1(ind ntype.PlayerInd) int
}
