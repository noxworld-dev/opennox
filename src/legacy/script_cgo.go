package legacy

/*
#include "defs.h"
#include "server__script__script.h"
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox/v1/server"
)

var scriptLog = log.New("script")

//export nox_script_callByEvent_cgo
func nox_script_callByEvent_cgo(event C.int, a1, a2 unsafe.Pointer) {
	GetServer().Nox_script_callByEventcgo(server.ScriptEventType(event), a1, a2)
}
