package system

// #cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
// #cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
// #cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
import "C"
