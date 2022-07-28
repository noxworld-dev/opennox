package opennox

import "C"
import "unsafe"

//export nox_client_onMapDownloadStart
func nox_client_onMapDownloadStart(a1 *C.char, a2 C.uint) {
	noxClient.mapsend.onMapDownloadStart(GoString(a1), uint(a2))
}

//export nox_client_onMapDownloadPart
func nox_client_onMapDownloadPart(a1 C.ushort, a2p unsafe.Pointer, a3 C.uint) {
	if a2p == nil || a3 == 0 {
		return
	}
	ind := uint(a1)
	data := unsafe.Slice((*byte)(a2p), int(a3))
	noxClient.mapsend.onMapDownloadPart(ind, data)
}

//export nox_client_onMapDownloadAbort
func nox_client_onMapDownloadAbort() {
	noxClient.mapsend.onMapDownloadAbort()
}
