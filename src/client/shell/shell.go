package shell

// #cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
// #cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
// #cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
import "C"
import (
	_ "nox/client/shell/inputcfg"
	_ "nox/client/shell/wolapi"
)
