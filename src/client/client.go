package client

// #cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
// #cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
// #cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
import "C"
import (
	_ "nox/client/audio"
	_ "nox/client/draw"
	_ "nox/client/drawable"
	_ "nox/client/gui"
	_ "nox/client/io"
	_ "nox/client/light"
	_ "nox/client/network"
	_ "nox/client/shell"
	_ "nox/client/system"
	_ "nox/client/video"
)
