package legacy

import "C"

var (
	Nox_client_setVersion_409AE0 func(v uint32) // for export
)

//export nox_client_setVersion_409AE0
func nox_client_setVersion_409AE0(v uint32) { Nox_client_setVersion_409AE0(v) }
