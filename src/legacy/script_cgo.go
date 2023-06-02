package legacy

import (
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/server"
)

var scriptLog = log.New("script")

// nox_script_event_playerLeave
func nox_script_event_playerLeave(pl *server.Player) {
	GetServer().Nox_script_event_playerLeave(asPlayerS(pl))
}
