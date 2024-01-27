package client

import (
	"errors"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/player"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	ErrLobbyNoSocket = errors.New("no broadcast socket")
)

type CurPlayerInfo struct {
	Connected bool
	Class     player.Class
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
	case noxnet.MSG_DESTROY_WALL:
		var p noxnet.MsgWallDestroy
		n, err := p.Decode(data[1:])
		if err != nil {
			return 0, false, err
		}
		if cur.Connected && !noxflags.HasGame(noxflags.GameHost) {
			c.Server.Walls.BreakByID(p.ID)
		}
		return n + 1, true, nil
	}
	return 0, false, nil
}
