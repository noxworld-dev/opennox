package legacy

import (
	"github.com/noxworld-dev/opennox-lib/log"
)

var scriptLog = log.New("script")

// nox_script_event_playerLeave
func nox_script_event_playerLeave(pl *nox_playerInfo) {
	GetServer().Nox_script_event_playerLeave(asPlayerS(pl))
}
