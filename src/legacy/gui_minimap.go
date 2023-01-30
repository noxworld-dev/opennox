package legacy

import "C"

var (
	Sub_473670                  func() int
	Nox_client_toggleMap_473610 func() int
)

//export sub_473670
func sub_473670() int { return Sub_473670() }

//export nox_client_toggleMap_473610
func nox_client_toggleMap_473610() C.char { return C.char(Nox_client_toggleMap_473610()) }
