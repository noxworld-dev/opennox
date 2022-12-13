package opennox

/*
unsigned int sub_4D42E0(const char* a1);
*/
import "C"
import (
	"errors"
	"fmt"
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
)

type serverDebug struct {
	keys  []string
	byKey map[string][]string
}

func (d *serverDebug) Reset() {
	d.keys = nil
	d.byKey = nil
}

func (d *serverDebug) Add(key, val string) { // sub_57C500
	vals, ok := d.byKey[key]
	if !ok {
		d.keys = append(d.keys, key)
	}
	if d.byKey == nil {
		d.byKey = make(map[string][]string)
	}
	d.byKey[key] = append(vals, val)
}

func (d *serverDebug) Get(key string) []string { // sub_57C490
	return d.byKey[key]
}

//export sub_57C490_2
func sub_57C490_2(a1 *C.char) {
	key := GoString(a1)
	if vals := noxServer.debug.Get(key); len(vals) > 0 {
		C.sub_4D42E0(internCStr(vals[0]))
	}
}

func (d *serverDebug) mapReadDebugData(cf *cryptfile.CryptFile) error {
	vers, err := cf.ReadU16()
	if err != nil {
		return errors.New("cannot read DebugData version")
	}
	if vers < 1 {
		return fmt.Errorf("unsupported DebugData version: %d", vers)
	}
	n, _ := cf.ReadU32()
	for i := 0; i < int(n); i++ {
		key, err := cf.ReadString32()
		if err != nil {
			return err
		}
		val, err := cf.ReadString32()
		if err != nil {
			return err
		}
		if !noxflags.HasGame(noxflags.GameFlag23) && noxflags.HasGame(noxflags.GameHost) {
			d.Add(key, val)
		}
	}
	return nil
}

func (d *serverDebug) Each(keys []string, fnc func(key, val string)) {
	if len(keys) == 0 {
		keys = d.keys
	}
	for _, key := range keys {
		for _, val := range d.byKey[key] {
			fnc(key, val)
		}
	}
}

func (d *serverDebug) mapWriteDebugData(cf *cryptfile.CryptFile) error {
	if err := cf.WriteU16(1); err != nil {
		return err
	}
	cnt := 0
	d.Each(nil, func(key, val string) {
		cnt++
	})
	if err := cf.WriteU32(uint32(cnt)); err != nil {
		return err
	}
	var last error
	d.Each(nil, func(key, val string) {
		if err := cf.WriteString32(key); err != nil {
			last = err
		}
		if err := cf.WriteString32(val); err != nil {
			last = err
		}
	})
	return last
}

func (d *serverDebug) mapRWDebugData(cf *cryptfile.CryptFile) error {
	if cf.ReadOnly() {
		return d.mapReadDebugData(cf)
	}
	return d.mapWriteDebugData(cf)
}

func nox_server_mapRWDebugData_5060D0(cf *cryptfile.CryptFile, _ unsafe.Pointer) error {
	return noxServer.debug.mapRWDebugData(cf)
}
