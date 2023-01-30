package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

func sub_57C490_2(key string) {
	if vals := noxServer.Map.Debug.Get(key); len(vals) > 0 {
		legacy.Sub_4D42E0(vals[0])
	}
}

func nox_server_mapRWDebugData_5060D0(cf *cryptfile.CryptFile, _ unsafe.Pointer) error {
	return noxServer.Map.Debug.ReadWriteDebugData(cf)
}
