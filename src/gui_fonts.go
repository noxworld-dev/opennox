package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

func (c *Client) loadGameFonts() error {
	if err := c.r.Fonts.Load(c.Strings().Lang()); err != nil {
		return err
	}
	c.nox_xxx_fontLoadMB_43F1C0()
	return nil
}

func (c *Client) nox_xxx_fontLoadMB_43F1C0() {
	legacy.Set_dword_5d4594_816444(0)
	v1 := unsafe.Slice((*uint32)(memmap.PtrOff(0x5D4594, 816464)), 5)
	for i := range v1 {
		v1[i] = 0
	}
}
