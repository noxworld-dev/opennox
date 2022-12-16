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
	return nox_things.TypeByID(id).C()
}

var (
	nox_things clientObjTypes
)

type clientObjTypes struct {
	first *nox_thing
	byInd []*nox_thing
	byID  map[string]*nox_thing
}

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

func (t *nox_thing) ID() string {
	if t == nil {
		return ""
	}
	return GoString(t.name)
}

func (t *nox_thing) Index() int {
	if t == nil {
		return 0
	}
	return int(t.field_1c)
}

func (c *clientObjTypes) nox_things_free_44C580() {
	var next *nox_thing
	for cur := nox_things.first; cur != nil; cur = next {
		next = cur.next
		if cur.field_5c != nil {
			C.nox_xxx_draw_44C650_free(cur.field_5c, cur.draw_func)
		}
		alloc.Free(unsafe.Pointer(cur))
	}
	c.first = nil
	c.byInd = []*nox_thing{nil}
	c.byID = make(map[string]*nox_thing)
	if !noxflags.HasGame(noxflags.GameHost) {
		nox_xxx_free_42BF80()
	}
}

func (c *clientObjTypes) readType(thg *MemFile, buf []byte) error {
	typ, _ := alloc.New(nox_thing{})
	id, err := thg.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read object type: %w", err)
	}
	typ.name = internCStr(id)
	typ.menuicon = -1
	typ.field_1c = int32(len(c.byInd))
	c.byInd = append(c.byInd, typ)
	typ.flags |= 0x1000000
	typ.field_f = 0
	typ.field_10 = 0xFFFF
	typ.audio_loop = 0
	typ.draw_func = C.nox_thing_debug_draw
	typ.zsize_min = 0
	typ.zsize_max = 30.0
	if err := c.parseThing(thg, buf, typ); err != nil {
		return fmt.Errorf("cannot parse object type %q: %w", id, err)
	}
	typ.next = c.first
	c.first = typ
	c.byID[strings.ToLower(id)] = typ
	if typ.weight != 0 {
		if typ.pretty_name == nil {
			typ.pretty_name = internWStr(strMan.GetStringInFile(strman.ID(fmt.Sprintf("thing.db:%sPrettyName", id)), "drawdb.c"))
		}
		if typ.desc == nil {
			typ.desc = internWStr(strMan.GetStringInFile(strman.ID(fmt.Sprintf("thing.db:%sDescription", id)), "drawdb.c"))
		}
	}
	return nil
}

func (c *clientObjTypes) parseThing(f *MemFile, buf []byte, typ *nox_thing) error {
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

func (c *clientObjTypes) TypeByID(id string) *nox_thing {
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
	return nox_things.byInd[i].name
}

//export nox_get_thing
func nox_get_thing(i C.int) *C.nox_thing {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return nil
	}
	return nox_things.byInd[i].C()
}

//export nox_get_thing_pretty_name
func nox_get_thing_pretty_name(i C.int) *wchar_t {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return nil
	}
	return nox_things.byInd[i].pretty_name
}

//export nox_get_thing_desc
func nox_get_thing_desc(i C.int) *wchar_t {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return nil
	}
	return nox_things.byInd[i].desc
}

//export nox_get_thing_pretty_image
func nox_get_thing_pretty_image(i C.int) C.int {
	if i < 1 || int(i) >= len(nox_things.byInd) {
		return 0
	}
	return C.int(nox_things.byInd[i].pretty_image)
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
	*(*uint8)(unsafe.Add(unsafe.Pointer(&dr.field_0), 0)) = typ.hwidth
	*(*uint8)(unsafe.Add(unsafe.Pointer(&dr.field_0), 1)) = typ.hheight
	dr.field_26_1 = typ.z // TODO: shouldn't it put this in dr.z?
	dr.flags28 = typ.pri_class
	dr.flags29 = typ.sub_class
	dr.flags30 = uint32(typ.flags)
	dr.flags70 = typ.field_54
	dr.field_74_3 = typ.weight
	dr.draw_func = typ.draw_func
	dr.field_76 = typ.field_5c
	dr.field_77 = typ.field_60
	dr.field_116 = typ.client_update
	dr.field_123 = typ.audio_loop
	dr.light_flags = uint32(typ.field_f)
	dr.field_42 = typ.field_10
	dr.light_color_r = uint32(typ.light_color_r)
	dr.light_color_g = uint32(typ.light_color_g)
	dr.light_color_b = uint32(typ.light_color_b)
	dr.field_41_0 = typ.light_dir
	dr.field_41_1 = typ.light_penumbra

	dr.shape.Kind = server.ShapeKind(typ.shape_kind)
	dr.shape.Circle.R = typ.shape_r
	dr.shape.Circle.R2 = typ.shape_r * typ.shape_r
	dr.shape.Box.W = typ.shape_w
	dr.shape.Box.H = typ.shape_h
	if dr.shape.Kind == server.ShapeKindBox {
		dr.shape.Box.Calc()
	}

	dr.field_24 = typ.zsize_min
	dr.field_25 = typ.zsize_max
	intens := typ.light_intensity
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
	if typ.lifetime != 0 {
		C.nox_xxx_spriteTransparentDecay_49B950(dr.C(), C.int(typ.lifetime))
	}
	return 1
}

type clientThingFieldFunc func(typ *nox_thing, f *MemFile, str string, buf []byte) error

func wrapClientThingFuncC(fnc unsafe.Pointer) clientThingFieldFunc {
	return func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		StrNCopyBytes(buf, str)
		if !C.go_nox_drawable_call_parse_func((*[0]byte)(fnc), typ.C(), f.C(), unsafe.Pointer(&buf[0])) {
			return fmt.Errorf("failed to parse %q", str)
		}
		return nil
	}
}

var clientThingParseFuncs = map[string]clientThingFieldFunc{
	"CLASS": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.pri_class = uint32(v)
		return nil
	},
	"SUBCLASS": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseSubClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.sub_class = uint32(v)
		return nil
	},
	"FLAGS": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := object.ParseFlagSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.flags = int32(v)
		return nil
	},
	"EXTENT": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := things.ParseExtent(str)
		if err != nil {
			return fmt.Errorf("cannot parse %q: %w", str, err)
		}
		typ.shape_r = 0
		typ.shape_w = 0
		typ.shape_h = 0
		switch v := v.(type) {
		case nil:
			typ.shape_kind = uint16(server.ShapeKindNone)
		case things.Center:
			typ.shape_kind = uint16(server.ShapeKindCenter)
		case things.Circle:
			typ.shape_kind = uint16(server.ShapeKindCircle)
			typ.shape_r = v.R
		case things.Box:
			typ.shape_kind = uint16(server.ShapeKindBox)
			typ.shape_w = v.W
			typ.shape_h = v.H
		default:
			return fmt.Errorf("unsupported shape type: %T", v)
		}
		return nil
	},
	"LIGHTINTENSITY": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseFloat(firstWord(str), 32)
		if err != nil {
			return err
		}
		typ.light_intensity = float32(v)
		return nil
	},
	"DRAW": wrapClientThingFuncC(C.nox_parse_thing_draw),
	"Z": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.z = uint16(v)
		return nil
	},
	"ZSIZE": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
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
		typ.zsize_min = float32(min)
		typ.zsize_max = float32(max)
		return nil
	},
	"SIZE": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
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
		typ.hwidth = uint8(w / 2)
		typ.hheight = uint8(h / 2)
		return nil
	},
	"MENUICON": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		typ.menuicon = f.ReadI32()
		if typ.menuicon == -1 {
			f.Skip(1)
			f.SkipString8()
		}
		return nil
	},
	"LIGHTCOLOR": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
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
		typ.field_f = 2
		typ.light_color_r = int32(r)
		typ.light_color_g = int32(g)
		typ.light_color_b = int32(b)
		return nil
	},
	"LIGHTDIRECTION": wrapClientThingFuncC(C.nox_parse_thing_light_dir),
	"LIGHTPENUMBRA":  wrapClientThingFuncC(C.nox_parse_thing_light_penumbra),
	"AUDIOLOOP": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		typ.audio_loop = uint32(sound.ByName(str))
		return nil
	},
	"CLIENTUPDATE": wrapClientThingFuncC(C.nox_parse_thing_client_update),
	"LIFETIME": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.lifetime = int32(v)
		return nil
	},
	"WEIGHT": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 8)
		if err != nil {
			return err
		}
		typ.weight = byte(v)
		typ.pri_class |= uint32(object.ClassPickup)
		return nil
	},
	"PRETTYNAME": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		typ.pretty_name = internWStr(noxClient.Strings().GetStringInFile(strman.ID(str), "drawdb.c"))
		return nil
	},
	"DESCRIPTION": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		typ.desc = internWStr(noxClient.Strings().GetStringInFile(strman.ID(str), "drawdb.c"))
		return nil
	},
	"PRETTYIMAGE": wrapClientThingFuncC(C.nox_parse_thing_pretty_image),
	"HEALTH": func(typ *nox_thing, f *MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.health = uint16(v)
		return nil
	},
}
