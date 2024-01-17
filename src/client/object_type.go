package client

import (
	"errors"
	"fmt"
	"io"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	thingsLog        = log.New("things")
	ThingDrawDefault ObjectDrawFunc
)

type ObjectDrawFunc func(*noxrender.Viewport, *Drawable) int
type ObjectUpdateFunc func(*noxrender.Viewport, *Drawable) int

var (
	updateFuncs = make(map[string]ccall.Func[ObjectUpdateFunc])
)

func RegisterObjectUpdate(name string, fnc ObjectUpdateFunc) {
	if _, ok := updateFuncs[name]; ok {
		panic("already registered")
	}
	updateFuncs[name] = ccall.FuncPtr(fnc)
}

type ThingFieldFunc func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error

type clientObjTypes struct {
	sm    *strman.StringManager
	first *ObjectType
	byInd []*ObjectType
	byID  map[string]*ObjectType
}

func (c *clientObjTypes) init(sm *strman.StringManager) {
	c.sm = sm
}

func (c *clientObjTypes) TypesCnt() int {
	return len(c.byInd)
}

func (c *clientObjTypes) TypeByID(id string) *ObjectType {
	return c.byID[strings.ToLower(id)]
}

func (c *clientObjTypes) TypeByInd(i int) *ObjectType {
	if i < 1 || i >= len(c.byInd) {
		return nil
	}
	return c.byInd[i]
}

func (c *clientObjTypes) IndByID(id string) int {
	return c.TypeByID(id).Index()
}

func (c *clientObjTypes) parseThing(f *binfile.MemFile, buf []byte, typ *ObjectType) error {
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

func (c *clientObjTypes) ReadType(thg *binfile.MemFile, buf []byte) error {
	typ, _ := alloc.New(ObjectType{})
	id, err := thg.ReadString8()
	if err != nil {
		return fmt.Errorf("cannot read object type: %w", err)
	}
	typ.Name = alloc.InternCString(id)
	typ.MenuIcon = -1
	typ.Field_1c = int32(len(c.byInd))
	c.byInd = append(c.byInd, typ)
	typ.ObjFlags |= 0x1000000
	typ.LightFlags = 0
	typ.Field_10 = 0xFFFF
	typ.AudioLoop = 0
	typ.DrawFunc = ccall.FuncPtr(ThingDrawDefault)
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
			typ.PrettyName = alloc.InternCString16(c.sm.GetStringInFile(strman.ID(fmt.Sprintf("thing.db:%sPrettyName", id)), "drawdb.c"))
		}
		if typ.Desc == nil {
			typ.Desc = alloc.InternCString16(c.sm.GetStringInFile(strman.ID(fmt.Sprintf("thing.db:%sDescription", id)), "drawdb.c"))
		}
	}
	return nil
}

func (c *clientObjTypes) Each(fnc func(it *ObjectType)) {
	var next *ObjectType
	for it := c.first; it != nil; it = next {
		next = it.ObjNext
		fnc(it)
	}
}

func (c *clientObjTypes) Nox_things_free_44C580_B() {
	c.Each(func(it *ObjectType) {
		alloc.Free(it)
	})
	c.first = nil
	c.byInd = []*ObjectType{nil}
	c.byID = make(map[string]*ObjectType)
}

type ObjectType struct {
	Name           *byte                        // 0, 0x0
	PrettyName     *uint16                      // 1, 0x4, 4
	Desc           *uint16                      // 2, 0x8, 8
	HWidth         uint8                        // 3, 0xc, 12
	HHeight        uint8                        // 3, 0xd, 13
	Weight         uint8                        // 3, 0xe, 14
	LightFlags     uint8                        // 3, 0xf, 15
	Field_10       uint32                       // 4, 0x10, 16
	ShapeKind      uint16                       // 5, 0x14, 20
	Z              uint16                       // 5, 0x16, 22
	LightDir       uint16                       // 6, 0x18, 24
	LightPenumbra  uint16                       // 6, 0x1a, 26
	Field_1c       int32                        // 7, 0x1c, 28, ID? index?
	ObjClass       uint32                       // 8, 0x20, 32
	ObjSubClass    uint32                       // 9, 0x24, 36
	ObjFlags       int32                        // 10, 0x28, 40
	LightIntensity float32                      // 11, 0x2c, 44
	LightColorR    int32                        // 12, 0x30, 48
	LightColorG    int32                        // 13, 0x34, 52
	LightColorB    int32                        // 14, 0x38, 56
	Field_3c       uint32                       // 15, 0x3c
	ShapeR         float32                      // 16, 0x40, 64
	ZSizeMin       float32                      // 17, 0x44, 68
	ZSizeMax       float32                      // 18, 0x48, 72
	ShapeW         float32                      // 19, 0x4c, 76
	ShapeH         float32                      // 20, 0x50, 80
	Field_54       uint32                       // 21, 0x54
	DrawFunc       ccall.Func[ObjectDrawFunc]   // 22, 0x58, 88
	DrawData       unsafe.Pointer               // 23, 0x5c, 92
	Field_60       uint32                       // 24, 0x60, 96
	ClientUpdate   ccall.Func[ObjectUpdateFunc] // 25, 0x64, 100
	AudioLoop      uint32                       // 26, 0x68, 104
	ObjNext        *ObjectType                  // 27, 0x6c, 108
	PrettyImage    noxrender.ImageHandle        // 28, 0x70, 112
	MenuIcon       int32                        // 29, 0x74, 116
	Lifetime       int32                        // 30, 0x78, 120
	Health         uint16                       // 31, 0x7c, 124
	Field_7e       uint16                       // 31, 0x7e, 126
}

func (t *ObjectType) C() unsafe.Pointer {
	return unsafe.Pointer(t)
}

func (t *ObjectType) ID() string {
	if t == nil || t.Name == nil {
		return ""
	}
	return alloc.GoString(t.Name)
}

func (t *ObjectType) Index() int {
	if t == nil {
		return 0
	}
	return int(t.Field_1c)
}

func RegisterThingParse(name string, fnc ThingFieldFunc) {
	if _, ok := clientThingParseFuncs[name]; ok {
		panic("already registered")
	}
	clientThingParseFuncs[name] = fnc
}

var clientThingParseFuncs = map[string]ThingFieldFunc{
	"CLASS": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := object.ParseClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.ObjClass = uint32(v)
		return nil
	},
	"SUBCLASS": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := object.ParseSubClassSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.ObjSubClass = uint32(v)
		return nil
	},
	"FLAGS": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := object.ParseFlagSet(str)
		if err != nil {
			thingsLog.Printf("%q (%d): %v", typ.ID(), typ.Index(), err)
		}
		typ.ObjFlags = int32(v)
		return nil
	},
	"EXTENT": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
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
	"LIGHTINTENSITY": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := strconv.ParseFloat(firstWord(str), 32)
		if err != nil {
			return err
		}
		typ.LightIntensity = float32(v)
		return nil
	},
	"Z": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.Z = uint16(v)
		return nil
	},
	"ZSIZE": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
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
	"SIZE": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
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
	"MENUICON": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		typ.MenuIcon = f.ReadI32()
		if typ.MenuIcon == -1 {
			f.Skip(1)
			f.SkipString8()
		}
		return nil
	},
	"LIGHTCOLOR": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
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
		typ.LightFlags = 2
		typ.LightColorR = int32(r)
		typ.LightColorG = int32(g)
		typ.LightColorB = int32(b)
		return nil
	},
	"AUDIOLOOP": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		typ.AudioLoop = uint32(sound.ByName(str))
		return nil
	},
	"LIFETIME": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.Lifetime = int32(v)
		return nil
	},
	"WEIGHT": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := strconv.ParseUint(firstWord(str), 10, 8)
		if err != nil {
			return err
		}
		typ.Weight = byte(v)
		typ.ObjClass |= uint32(object.ClassPickup)
		return nil
	},
	"HEALTH": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		v, err := strconv.ParseInt(firstWord(str), 10, 32)
		if err != nil {
			return err
		}
		typ.Health = uint16(v)
		return nil
	},
	"CLIENTUPDATE": func(typ *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
		name := firstWord(str)
		fnc, ok := updateFuncs[name]
		if !ok {
			return fmt.Errorf("unsupported object client update func: %q", name)
		}
		typ.ClientUpdate = fnc
		return nil
	},
}
