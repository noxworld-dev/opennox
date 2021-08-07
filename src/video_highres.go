//+build highres

package main

/*
#cgo CFLAGS: -DNOX_HIGH_RES
*/
import "C"

const (
	NOX_CLIENT_VERS_CODE = 0x000F039A
	noxMaxWidth          = 1920
	noxMaxHeight         = 1080
	noxHighRes           = true
)
