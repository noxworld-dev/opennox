package legacy

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
	client.RegisterThingParse("PRETTYIMAGE", wrapClientThingFuncC(nox_parse_thing_pretty_image))
	client.ThingDrawDefault = nox_thing_debug_draw
}

// nox_xxx_getTTByNameSpriteMB_44CFC0
func nox_xxx_getTTByNameSpriteMB_44CFC0(cstr *byte) int32 {
	id := GoString(cstr)
	return int32(GetClient().Cli().Things.TypeByID(id).Index())
}

// sub_44D330
func sub_44D330(cstr *byte) *client.ObjectType {
	id := GoString(cstr)
	return (*client.ObjectType)(GetClient().Cli().Things.TypeByID(id).C())
}

// nox_get_thing_name
func nox_get_thing_name(i int32) *byte {
	t := GetClient().Cli().Things.TypeByInd(int(i))
	if t == nil {
		return nil
	}
	return t.Name
}

// nox_get_thing
func nox_get_thing(i int32) *client.ObjectType {
	t := GetClient().Cli().Things.TypeByInd(int(i))
	if t == nil {
		return nil
	}
	return (*client.ObjectType)(t.C())
}

// nox_get_thing_pretty_name
func nox_get_thing_pretty_name(i int32) *wchar2_t {
	t := GetClient().Cli().Things.TypeByInd(int(i))
	if t == nil {
		return nil
	}
	return t.PrettyName
}

// nox_get_thing_desc
func nox_get_thing_desc(i int32) *wchar2_t {
	t := GetClient().Cli().Things.TypeByInd(int(i))
	if t == nil {
		return nil
	}
	return t.Desc
}

// nox_get_thing_pretty_image
func nox_get_thing_pretty_image(i int32) int32 {
	t := GetClient().Cli().Things.TypeByInd(int(i))
	if t == nil {
		return 0
	}
	return int32(t.PrettyImage)
}

// nox_drawable_link_thing
func nox_drawable_link_thing(a1c *client.Drawable, i int32) int32 {
	return int32(GetClient().Cli().DrawableLinkThing(a1c, int(i)))
}

func wrapClientThingFuncC(fnc func(typ *client.ObjectType, f *binfile.MemFile, data unsafe.Pointer) bool) client.ThingFieldFunc {
	return func(typ *client.ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		StrNCopyBytes(buf, str)
		if !fnc(typ, f, unsafe.Pointer(&buf[0])) {
			return fmt.Errorf("failed to parse %q", str)
		}
		return nil
	}
}
