//go:build highres
// +build highres

package nox

/*
#cgo CFLAGS: -DNOX_HIGH_RES
*/
import "C"

const (
	NOX_CLIENT_VERS_CODE = 0x000F039A
	noxMaxWidth          = 3840
	noxMaxHeight         = 2160
	noxHighRes           = true
)
