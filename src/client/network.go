package client

import (
	"errors"

	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
)

var (
	ErrLobbyNoSocket = errors.New("no broadcast socket")
)

func (c *Client) OnClientPacketOpSub(pli ntype.PlayerInd, op noxnet.Op, data []byte, localFrame *uint32, localFrame16 *uint16) (int, bool, error) {
	switch op {
	case noxnet.MSG_XXX_STOP:
		return 1, true, nil
	}
	return 0, false, nil
}
