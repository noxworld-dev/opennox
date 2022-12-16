package opennox

/*
#include <stdint.h>

extern uint32_t dword_5d4594_816444;
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func (c *Client) loadGameFonts() error {
	if err := c.r.Fonts.Load(c.Strings().Lang()); err != nil {
		return err
	}
	c.nox_xxx_fontLoadMB_43F1C0()
	return nil
}

func (c *Client) nox_xxx_fontLoadMB_43F1C0() {
	C.dword_5d4594_816444 = 0
	v1 := unsafe.Slice((*uint32)(memmap.PtrOff(0x5D4594, 816464)), 5)
	for i := range v1 {
		v1[i] = 0
	}
}

//export nox_xxx_guiFontPtrByName_43F360
func nox_xxx_guiFontPtrByName_43F360(cname *C.char) unsafe.Pointer {
	name := GoString(cname)
	return noxClient.r.Fonts.FontPtrByName(name)
}
