package opennox

import "C"

//export nox_client_onMapDownloadAbort
func nox_client_onMapDownloadAbort() {
	noxClient.mapsend.onMapDownloadAbort()
}
