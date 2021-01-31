package main

/*
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
