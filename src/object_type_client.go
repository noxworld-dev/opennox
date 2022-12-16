package opennox

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
import "C"
import (
	"errors"
	"fmt"
	"io"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_xxx_getTTByNameSpriteMB_44CFC0
func nox_xxx_getTTByNameSpriteMB_44CFC0(cstr *C.char) C.int {
	id := GoString(cstr)
	return C.int(nox_things.TypeByID(id).Index())
}

//export sub_44D330
func sub_44D330(cstr *C.char) *C.nox_thing {
	id := GoString(cstr)
	return (*C.nox_thing)(nox_things.TypeByID(id).C())
}

var (
	nox_things clientObjTypes
)

type clientObjTypes struct {
	first *client.ObjectType
	byInd []*client.ObjectType
	byID  map[string]*client.ObjectType
}

func (c *clientObjTypes) nox_things_free_44C580() {
	var next *client.ObjectType
	for cur := nox_things.first; cur != nil; cur = next {
		next = cur.ObjNext
		if cur.Field_5c != nil {
			C.nox_xxx_draw_44C650_free(cur.Field_5c, cur.DrawFunc)
		}
		alloc.Free(unsafe.Pointer(cur))
	}
	c.first = nil
	c.byInd = []*client.ObjectType{nil}
	c.byID = make(map[string]*client.ObjectType)
	if !noxflags.HasGame(noxflags.GameHost) {
		nox_xxx_free_42BF80()
	}
}

func (c *clientObjTypes) readType(thg *MemFile, buf []byte) error {
	typ, _ := alloc.New(client.ObjectType{})
	id, err := thg.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read object type: %w", err)
	}
	typ.Name = internCStrB(id)
	typ.MenuIcon = -1
	typ.Field_1c = int32(len(c.byInd))
	c.byInd = append(c.byInd, typ)
	typ.ObjFlags |= 0x1000000
	typ.Field_f = 0
	typ.Field_10 = 0xFFFF
	typ.AudioLoop = 0
	typ.DrawFunc = C.nox_thing_debug_draw
	typ.ZSizeMin = 0
	typ.ZSizeMax = 30.0
	if err := c.parseThing(thg, buf, typ); err != nil {
		return fmt.Errorf("cannot parse object type %q: %w", id, err)
	}
	typ.ObjNext = c.first
	c.first = typ
	c.byID[strings.ToLower(id)] = typ
	if typ.Weight != 0 {
		if typ.PrettyName == nil {
			typ.PrettyName = internWStrU(strMan.GetStringInFile(strman.ID(fmt.Sprintf("thing.db:%sPrettyName", id)), "drawdb.c"))
		}
		if typ.Desc == nil {
			typ.Desc = internWStrU(strMan.GetStringInFile(strman.ID(fmt.Sprintf("thing.db:%sDescription", id)), "drawdb.c"))
		}
	}
	return nil
}

func (c *clientObjTypes) parseThing(f *MemFile, buf []byte, typ *client.ObjectType) error {
	for {
		line, err := f.ReadString8()
		if err == io.EOF {
			return nil
		} else if err != nil {
			thingsLog.Println(err)
			return nil
		}
		if len(line) == 0 {
			return nil
		}
		attr := firstWord(line)
		fnc := clientThingParseFuncs[attr]
		if fnc == nil {
			continue
		}
		val := ""
		if i := strings.IndexByte(line, '='); i >= 0 {
			val = strings.TrimSpace(line[i+1:])
		}
		if err = fnc(typ, f, val, buf); err != nil {
			thingsLog.Println(err)
		}
	}
}

func (c *clientObjTypes) TypeByID(id string) *client.ObjectType {
	return c.byID[strings.ToLower(id)]
}

func (c *clientObjTypes) IndByID(id string) int {
	return c.TypeByID(id).Index()
}

//export nox_get_thing_name
func nox_get_thing_name(i C.int) *C.char {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return nil
	}
	return (*C.char)(unsafe.Pointer(nox_things.byInd[i].Name))
}

//export nox_get_thing
func nox_get_thing(i C.int) *C.nox_thing {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return nil
	}
	return (*C.nox_thing)(nox_things.byInd[i].C())
}

//export nox_get_thing_pretty_name
func nox_get_thing_pretty_name(i C.int) *wchar_t {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return nil
	}
	return (*wchar_t)(unsafe.Pointer(nox_things.byInd[i].PrettyName))
}

//export nox_get_thing_desc
func nox_get_thing_desc(i C.int) *wchar_t {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return nil
	}
	return (*wchar_t)(unsafe.Pointer(nox_things.byInd[i].Desc))
}

//export nox_get_thing_pretty_image
func nox_get_thing_pretty_image(i C.int) C.int {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return 0
	}
	return C.int(nox_things.byInd[i].PrettyImage)
}

//export nox_drawable_link_thing
func nox_drawable_link_thing(a1c *nox_drawable, i C.int) C.int {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return 0
	}
	dr := asDrawable(a1c)
	*dr = Drawable{}
	typ := nox_things.byInd[i]
	dr.field_27 = uint32(i)
	*(*uint8)(unsafe.Add(unsafe.Pointer(&dr.field_0), 0)) = typ.HWidth
	*(*uint8)(unsafe.Add(unsafe.Pointer(&dr.field_0), 1)) = typ.HHeight
	dr.field_26_1 = typ.Z // TODO: shouldn't it put this in dr.z?
	dr.flags28 = typ.ObjClass
	dr.flags29 = typ.ObjSubClass
	dr.flags30 = uint32(typ.ObjFlags)
	dr.flags70 = typ.Field_54
	dr.field_74_3 = typ.Weight
	dr.draw_func = typ.DrawFunc
	dr.field_76 = typ.Field_5c
	dr.field_77 = typ.Field_60
	dr.field_116 = typ.ClientUpdate
	dr.field_123 = typ.AudioLoop
	dr.light_flags = uint32(typ.Field_f)
	dr.field_42 = typ.Field_10
	dr.light_color_r = uint32(typ.LightColorR)
	dr.light_color_g = uint32(typ.LightColorG)
	dr.light_color_b = uint32(typ.LightColorB)
	dr.field_41_0 = typ.LightDir
	dr.field_41_1 = typ.LightPenumbra

	dr.shape.Kind = server.ShapeKind(typ.ShapeKind)
	dr.shape.Circle.R = typ.ShapeR
	dr.shape.Circle.R2 = typ.ShapeR * typ.ShapeR
	dr.shape.Box.W = typ.ShapeW
	dr.shape.Box.H = typ.ShapeH
	if dr.shape.Kind == server.ShapeKindBox {
		dr.shape.Box.Calc()
	}

	dr.field_24 = typ.ZSizeMin
	dr.field_25 = typ.ZSizeMax
	intens := typ.LightIntensity
	dr.field_43 = 0
	if intens < 0 {
		intens = -intens
		dr.field_43 = 1
	}
	dr.light_intensity = intens
	if intens != 0.0 {
		dr.SetLightIntensity(intens)
		if dr.light_flags == 0 {
			dr.light_flags = 1
			dr.light_color_r = 255
			dr.light_color_g = 255
			dr.light_color_b = 255
		}
	}
	if dr.flags28&0x13001000 != 0 {
		*(*uint32)(dr.field(432)) = 0
		*(*uint32)(dr.field(436)) = 0
		dr.field_110 = 0
		dr.field_111 = 0
		*(*int16)(dr.field(448)) = -1
		*(*int16)(dr.field(450)) = -1
	}
	if typ.Lifetime != 0 {
		C.nox_xxx_spriteTransparentDecay_49B950(dr.C(), C.int(typ.Lifetime))
	}
	return 1
}

type clientThingFieldFunc func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error

func wrapClientThingFuncC(fnc unsafe.Pointer) clientThingFieldFunc {
	return func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		StrNCopyBytes(buf, str)
		if !C.go_nox_drawable_call_parse_func((*[0]byte)(fnc), (*C.nox_thing)(typ.C()), f.C(), unsafe.Pointer(&buf[0])) {
			return fmt.Errorf("failed to parse %q", str)
		}
		return nil
	}
}

var clientThingParseFuncs = map[string]clientThingFieldFunc{
	"CLASS": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.ObjClass = uint32(v)
		return nil
	},
	"SUBCLASS": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseSubClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.ObjSubClass = uint32(v)
		return nil
	},
	"FLAGS": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseFlagSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.ObjFlags = int32(v)
		return nil
	},
	"EXTENT": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := things.ParseExtent(str)
		if err != nil {
			return fmt.Errorf("cannot parse %q: %w", str, err)
		}
		typ.ShapeR = 0
		typ.ShapeW = 0
		typ.ShapeH = 0
		switch v := v.(type) {
		case nil:
			typ.ShapeKind = uint16(server.ShapeKindNone)
		case things.Center:
			typ.ShapeKind = uint16(server.ShapeKindCenter)
		case things.Circle:
			typ.ShapeKind = uint16(server.ShapeKindCircle)
			typ.ShapeR = v.R
		case things.Box:
			typ.ShapeKind = uint16(server.ShapeKindBox)
			typ.ShapeW = v.W
			typ.ShapeH = v.H
		default:
			return fmt.Errorf("unsupported shape type: %T", v)
		}
		return nil
	},
	"LIGHTINTENSITY": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseFloat(firstWord(str), 32)
		if err != nil {
			return err
		}
		typ.LightIntensity = float32(v)
		return nil
	},
	"DRAW": wrapClientThingFuncC(C.nox_parse_thing_draw),
	"Z": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.Z = uint16(v)
		return nil
	},
	"ZSIZE": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		sub := strings.SplitN(str, " ", 2)
		if len(sub) != 2 {
			return errors.New("expected two values")
		}
		min, err := strconv.Atoi(sub[0])
		if err != nil {
			return err
		}
		max, err := strconv.Atoi(sub[1])
		if err != nil {
			return err
		}
		if max < min {
			max = min
		}
		typ.ZSizeMin = float32(min)
		typ.ZSizeMax = float32(max)
		return nil
	},
	"SIZE": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		sub := strings.SplitN(str, " ", 2)
		if len(sub) != 2 {
			return errors.New("expected two values")
		}
		w, err := strconv.Atoi(sub[0])
		if err != nil {
			return err
		}
		h, err := strconv.Atoi(sub[1])
		if err != nil {
			return err
		}
		typ.HWidth = uint8(w / 2)
		typ.HHeight = uint8(h / 2)
		return nil
	},
	"MENUICON": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		typ.MenuIcon = f.ReadI32()
		if typ.MenuIcon == -1 {
			f.Skip(1)
			f.SkipString8()
		}
		return nil
	},
	"LIGHTCOLOR": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		sub := strings.SplitN(str, " ", 3)
		if len(sub) != 3 {
			return errors.New("expected RGB values")
		}
		r, err := strconv.Atoi(sub[0])
		if err != nil {
			return err
		}
		g, err := strconv.Atoi(sub[1])
		if err != nil {
			return err
		}
		b, err := strconv.Atoi(sub[2])
		if err != nil {
			return err
		}
		if r > 255 {
			r = 255
		}
		if g > 255 {
			g = 255
		}
		if b > 255 {
			b = 255
		}
		typ.Field_f = 2
		typ.LightColorR = int32(r)
		typ.LightColorG = int32(g)
		typ.LightColorB = int32(b)
		return nil
	},
	"LIGHTDIRECTION": wrapClientThingFuncC(C.nox_parse_thing_light_dir),
	"LIGHTPENUMBRA":  wrapClientThingFuncC(C.nox_parse_thing_light_penumbra),
	"AUDIOLOOP": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		typ.AudioLoop = uint32(sound.ByName(str))
		return nil
	},
	"CLIENTUPDATE": wrapClientThingFuncC(C.nox_parse_thing_client_update),
	"LIFETIME": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.Lifetime = int32(v)
		return nil
	},
	"WEIGHT": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 8)
		if err != nil {
			return err
		}
		typ.Weight = byte(v)
		typ.ObjClass |= uint32(object.ClassPickup)
		return nil
	},
	"PRETTYNAME": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		typ.PrettyName = internWStrU(noxClient.Strings().GetStringInFile(strman.ID(str), "drawdb.c"))
		return nil
	},
	"DESCRIPTION": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		typ.Desc = internWStrU(noxClient.Strings().GetStringInFile(strman.ID(str), "drawdb.c"))
		return nil
	},
	"PRETTYIMAGE": wrapClientThingFuncC(C.nox_parse_thing_pretty_image),
	"HEALTH": func(typ *client.ObjectType, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.Health = uint16(v)
		return nil
	},
}
