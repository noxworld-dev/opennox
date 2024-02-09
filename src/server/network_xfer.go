package server

import "github.com/noxworld-dev/opennox/v1/netxfer"

const (
	NetXferMOTD           = netxfer.Action(1)
	NetXferSavedata       = netxfer.Action(2)
	NetXferSaveServer     = netxfer.Action(3)
	NetXferMOTDType       = "MOTD"
	NetXferSavedataType   = "SAVEDATA"
	NetXferSaveServerType = "SAVE_SERVER"
)
