package client

import (
	"errors"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/player"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	ErrLobbyNoSocket = errors.New("no broadcast socket")
)

type CurPlayerInfo struct {
	Class player.Class
}

func (c *Client) OnClientPacketOpSub(pli ntype.PlayerInd, op noxnet.Op, data []byte, localFrame *uint32, localFrame16 *uint16, cur CurPlayerInfo) (int, bool, error) {
	switch op {
	case noxnet.MSG_XXX_STOP:
		return 1, true, nil
	case noxnet.MSG_STAT_MULTIPLIERS:
		var p noxnet.MsgStatMult
		n, err := p.Decode(data[1:])
		if err != nil {
			return 0, false, err
		}
		c.Server.OnClassStats(cur.Class, server.ClassStats{
			Health:   p.Health,
			Mana:     p.Mana,
			Strength: p.Strength,
			Speed:    p.Speed,
		})
		return 1 + n, true, nil
	}
	return 0, false, nil
}
