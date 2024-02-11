package opennox

import (
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/netxfer"
)

func netXferSend(pli ntype.PlayerInd, act netxfer.Action, typ string, data []byte, remote bool) bool {
	if len(data) == 0 {
		return false
	}
	c := noxClient
	s := noxServer
	var conn *netstr.Conn
	if !noxflags.HasGame(noxflags.GameHost) {
		conn = c.Conn
	} else {
		if !noxflags.HasGame(noxflags.GameClient) {
			return false
		}
		if !remote || pli == server.HostPlayerIndex {
			netXferLocal(act, data)
			return true
		}
		conn = s.NetStr.ConnByPlayerInd(pli)
	}
	return s.NetXfer.Send(conn, act, typ, data, netXferSendDone, netXferSendAborted)
}
