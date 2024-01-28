package opennox

import (
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/netxfer"
	"github.com/noxworld-dev/opennox/v1/server"
)

var netXfer netxfer.NetXfer

const (
	NetXferMOTD           = netxfer.Action(1)
	NetXferSavedata       = netxfer.Action(2)
	NetXferSaveServer     = netxfer.Action(3)
	NetXferMOTDType       = "MOTD"
	NetXferSavedataType   = "SAVEDATA"
	NetXferSaveServerType = "SAVE_SERVER"
)

func netXferSend(pli ntype.PlayerInd, act netxfer.Action, typ string, data []byte, remote bool) bool {
	if len(data) == 0 {
		return false
	}
	var conn netstr.Handle
	if !noxflags.HasGame(noxflags.GameHost) {
		conn = netstrClientConn
	} else {
		if !noxflags.HasGame(noxflags.GameClient) {
			return false
		}
		if !remote || pli == server.HostPlayerIndex {
			netXferLocal(act, data)
			return true
		}
		conn = netstr.Global.ByPlayerInd(pli)
	}
	return netXfer.Send(conn, act, typ, data, netXferSendDone, netXferSendAborted)
}
