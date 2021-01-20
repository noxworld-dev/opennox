package common

// #cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
// #cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
// #cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
import "C"
import (
	_ "nox/common/ability"
	_ "nox/common/gamemech"
	_ "nox/common/magic"
	_ "nox/common/object"
	_ "nox/common/system"
	_ "nox/common/telnet"
	_ "nox/common/wolapi"
	_ "nox/common/xfer"
)
