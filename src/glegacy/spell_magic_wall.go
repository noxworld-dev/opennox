package legacy

import "C"
import "github.com/noxworld-dev/opennox/v1/server"

var (
	Sub_5002D0 func(a1 *server.Object)
)

//export sub_5002D0
func sub_5002D0(a1 *nox_object_t) { Sub_5002D0(asObjectS(a1)) }
