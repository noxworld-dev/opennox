package video

// #cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
// #cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
// #cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
// #cgo CFLAGS: -DNOX_CGO
import "C"
import (
	_ "nox/client/video/sdl"
)
