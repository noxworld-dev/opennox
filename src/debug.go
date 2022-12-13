package opennox

/*
unsigned int sub_4D42E0(const char* a1);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
)

//export sub_57C490_2
func sub_57C490_2(a1 *C.char) {
	key := GoString(a1)
	if vals := noxServer.Map.Debug.Get(key); len(vals) > 0 {
		C.sub_4D42E0(internCStr(vals[0]))
	}
}

func nox_server_mapRWDebugData_5060D0(cf *cryptfile.CryptFile, _ unsafe.Pointer) error {
	return noxServer.Map.Debug.ReadWriteDebugData(cf)
}
