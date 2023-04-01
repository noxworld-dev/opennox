package netstr

import (
	"net/netip"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
)

type Handle struct {
	g *Streams
	i int // hiding it in a struct helps prevent direct casts
}

func (h Handle) Raw() int {
	return h.i
}

func (h Handle) Valid() bool {
	return h.g != nil && h.i >= 0 && h.i < maxStructs
}

func (h Handle) IsFirst() bool {
	return h.i == 0
}

func (h Handle) Player() ntype.PlayerInd {
	return ntype.PlayerInd(h.i - 1)
}

func (h Handle) Get() *Conn {
	if !h.Valid() {
		return nil
	}
	return h.g.streams[h.i]
}

func (h Handle) IP() netip.Addr {
	return h.Get().IP()
}
