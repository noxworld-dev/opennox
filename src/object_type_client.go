package opennox

/*
#include "GAME2.h"
#include "client__drawable__drawdb.h"
#include "client__draw__debugdraw.h"
void nox_xxx_draw_44C650_free(void* lpMem, void* draw);
void nox_xxx_free_42BF80();
void sub_44C620_free();
extern int nox_things_count;
extern nox_thing* nox_things_head;
extern nox_thing** nox_things_array;
*/
import "C"
import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

var (
	nox_things clientObjTypes
)

type clientObjTypes struct{}

type nox_thing struct {
	name            *C.char        // 0, 0x0
	pretty_name     *wchar_t       // 1, 0x4, 4
	desc            *wchar_t       // 2, 0x8, 8
	hwidth          uint8          // 3, 0xc, 12
	hheight         uint8          // 3, 0xd, 13
	weight          uint8          // 3, 0xe, 14
	field_f         uint8          // 3, 0xf, 15
	field_10        uint32         // 4, 0x10, 16
	shape_kind      uint16         // 5, 0x14, 20
	z               uint16         // 5, 0x16, 22
	light_dir       uint16         // 6, 0x18, 24
	light_penumbra  uint16         // 6, 0x1a, 26
	field_1c        int32          // 7, 0x1c, 28, ID? index?
	pri_class       uint32         // 8, 0x20, 32
	sub_class       uint32         // 9, 0x24, 36
	flags           int32          // 10, 0x28, 40
	light_intensity float32        // 11, 0x2c, 44
	light_color_r   int32          // 12, 0x30, 48
	light_color_g   int32          // 13, 0x34, 52
	light_color_b   int32          // 14, 0x38, 56
	field_3c        uint32         // 15, 0x3c
	shape_r         float32        // 16, 0x40, 64
	zsize_min       float32        // 17, 0x44, 68
	zsize_max       float32        // 18, 0x48, 72
	shape_w         float32        // 19, 0x4c, 76
	shape_h         float32        // 20, 0x50, 80
	field_54        uint32         // 21, 0x54
	draw_func       unsafe.Pointer // 22, 0x58, 88, same as nox_drawable->draw_func
	field_5c        unsafe.Pointer // 23, 0x5c, 92
	field_60        uint32         // 24, 0x60, 96
	client_update   uint32         // 25, 0x64, 100
	audio_loop      uint32         // 26, 0x68, 104
	next            *nox_thing     // 27, 0x6c, 108
	pretty_image    uint32         // 28, 0x70, 112
	menuicon        int32          // 29, 0x74, 116
	lifetime        int32          // 30, 0x78, 120
	health          uint16         // 31, 0x7c, 124
	field_7e        uint16         // 31, 0x7e, 126
}

func (t *nox_thing) C() *C.nox_thing {
	return (*C.nox_thing)(unsafe.Pointer(t))
}

func (t *nox_thing) Index() int {
	if t == nil {
		return 0
	}
	return int(t.field_1c)
}

func (c *clientObjTypes) nox_things_free_44C580() {
	var next *nox_thing
	for cur := (*nox_thing)(unsafe.Pointer(C.nox_things_head)); cur != nil; cur = next {
		next = cur.next
		if cur.name != nil {
			StrFree(cur.name)
		}
		if cur.field_5c != nil {
			C.nox_xxx_draw_44C650_free(cur.field_5c, cur.draw_func)
		}
		alloc.Free(unsafe.Pointer(cur))
	}
	C.nox_things_head = nil
	if C.nox_things_array != nil {
		C.free(unsafe.Pointer(C.nox_things_array))
		C.nox_things_array = nil
	}
	C.nox_things_count = 0
	C.sub_44C620_free()
	if !noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_free_42BF80()
	}
}

func (c *clientObjTypes) readType(thg *MemFile, buf []byte) error {
	typ, _ := alloc.New(nox_thing{})
	id, err := thg.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read object type: %w", err)
	}
	typ.name = CString(id)
	typ.menuicon = -1
	typ.field_1c = int32(C.nox_things_count)
	C.nox_things_count++
	typ.flags |= 0x1000000
	typ.field_f = 0
	typ.field_10 = 0xFFFF
	typ.audio_loop = 0
	typ.draw_func = C.nox_thing_debug_draw
	typ.zsize_min = 0
	typ.zsize_max = 30.0
	if C.nox_parse_thing(thg.C(), (*C.char)(unsafe.Pointer(&buf[0])), typ.C()) == 0 {
		return fmt.Errorf("cannot parse object type %q", id)
	}
	typ.next = (*nox_thing)(unsafe.Pointer(C.nox_things_head))
	C.nox_things_head = typ.C()
	C.nox_xxx_spriteDefByAlphabetAdd_44CD10(typ.name)
	return nil
}
