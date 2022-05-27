//go:build none

package opennox

import "C"

var (
	// maybe worth keeping mapgen
	_ = C.nox_xxx_mapGenStartAlt_4D5F30
	// unused grip spell effect - could be useful
	_ = C.nox_xxx_unusedCheckGripEffect_4E03F0
	// some game setup code - unused game mode?
	_ = C.nox_xxx_unused_418840
	// TODO: add Go helpers and remove those two as well
	_ = C.nox_client_getVersionMinor_409AB0
	_ = C.nox_client_getVersionMajor_409AA0
)
