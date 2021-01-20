package system

/*
#cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
#cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup

extern int nox_cheats_disabled;
*/
import "C"

func init() {
	SetCheats(true)
}

func SetCheats(enabled bool) {
	if enabled {
		C.nox_cheats_disabled = 0
	} else {
		C.nox_cheats_disabled = 1
	}
}
