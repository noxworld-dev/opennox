package legacy

/*
#include "GAME2_3.h"
#include "client__draw__debugdraw.h"
void nox_xxx_draw_44C650_free(void* lpMem, void* draw);

bool nox_parse_thing_draw(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_light_dir(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_light_penumbra(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_client_update(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_pretty_image(nox_thing* obj, nox_memfile* f, char* attr_value);

static bool go_nox_drawable_call_parse_func(bool (*fnc)(nox_thing*, nox_memfile*, char*), nox_thing* a1, nox_memfile* a2, void* a3) {
	return fnc(a1, a2, a3);
}
*/

import (
	"fmt"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

func init() {
	client.RegisterThingParse("DRAW", wrapClientThingFuncC(nox_parse_thing_draw))
	client.RegisterThingParse("LIGHTDIRECTION", wrapClientThingFuncC(nox_parse_thing_light_dir))
	client.RegisterThingParse("LIGHTPENUMBRA", wrapClientThingFuncC(nox_parse_thing_light_penumbra))
	client.RegisterThingParse("CLIENTUPDATE", wrapClientThingFuncC(nox_parse_thing_client_update))
	client.RegisterThingParse("PRETTYIMAGE", wrapClientThingFuncC(nox_parse_thing_pretty_image))
	client.ThingDrawDefault = nox_thing_debug_draw
}

type nox_thing = nox_thing

// nox_xxx_getTTByNameSpriteMB_44CFC0
func nox_xxx_getTTByNameSpriteMB_44CFC0(cstr *char) int {
	id := GoString(cstr)
	return GetClient().Cli().Things.TypeByID(id).Index()
}

// sub_44D330
func sub_44D330(cstr *char) *nox_thing {
	id := GoString(cstr)
	return (*nox_thing)(GetClient().Cli().Things.TypeByID(id).C())
}

// nox_get_thing_name
func nox_get_thing_name(i int) *char {
	t := GetClient().Cli().Things.TypeByInd(i)
	if t == nil {
		return nil
	}
	return (*char)(unsafe.Pointer(t.Name))
}

// nox_get_thing
func nox_get_thing(i int) *nox_thing {
	t := GetClient().Cli().Things.TypeByInd(i)
	if t == nil {
		return nil
	}
	return (*nox_thing)(t.C())
}

// nox_get_thing_pretty_name
func nox_get_thing_pretty_name(i int) *wchar2_t {
	t := GetClient().Cli().Things.TypeByInd(i)
	if t == nil {
		return nil
	}
	return (*wchar2_t)(unsafe.Pointer(t.PrettyName))
}

// nox_get_thing_desc
func nox_get_thing_desc(i int) *wchar2_t {
	t := GetClient().Cli().Things.TypeByInd(i)
	if t == nil {
		return nil
	}
	return (*wchar2_t)(unsafe.Pointer(t.Desc))
}

// nox_get_thing_pretty_image
func nox_get_thing_pretty_image(i int) int {
	t := GetClient().Cli().Things.TypeByInd(i)
	if t == nil {
		return 0
	}
	return int(t.PrettyImage)
}

// nox_drawable_link_thing
func nox_drawable_link_thing(a1c *nox_drawable, i int) int {
	return GetClient().Cli().DrawableLinkThing(asDrawable(a1c), i)
}

func wrapClientThingFuncC(fnc unsafe.Pointer) client.ThingFieldFunc {
	return func(typ *client.ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		StrNCopyBytes(buf, str)
		if !go_nox_drawable_call_parse_func((*[0]byte)(fnc), (*nox_thing)(typ.C()), (*nox_memfile)(f.C()), unsafe.Pointer(&buf[0])) {
			return fmt.Errorf("failed to parse %q", str)
		}
		return nil
	}
}
func Nox_xxx_draw_44C650_free(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	nox_xxx_draw_44C650_free(a1, a2)
}
