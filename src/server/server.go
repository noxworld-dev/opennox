package server

// #cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
// #cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
// #cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
import "C"
import (
	_ "nox/server/ability"
	_ "nox/server/dbase"
	_ "nox/server/gamemech"
	_ "nox/server/magic"
	_ "nox/server/mapgen"
	_ "nox/server/network"
	_ "nox/server/object"
	_ "nox/server/system"
	_ "nox/server/xfer"
)
