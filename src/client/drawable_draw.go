package client

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

func init() {
	RegisterThingParse("DRAW", parseThingDraw)

	RegisterDraw("NoDraw", nil, 0, nil)
}

type thingsDraw struct {
	Name  string
	Draw  unsafe.Pointer
	Kind  int
	Parse ThingFieldFunc
}

var drawFuncs = make(map[string]*thingsDraw)

func RegisterDraw(name string, draw unsafe.Pointer, kind int, parse ThingFieldFunc) {
	if _, ok := drawFuncs[name]; ok {
		panic("already registered")
	}
	drawFuncs[name] = &thingsDraw{Name: name, Draw: draw, Kind: kind, Parse: parse}
}

func parseThingDraw(obj *ObjectType, f *binfile.MemFile, str string, buf []byte) error {
	name, _ := f.ReadString8()
	// TODO: After cleanup: Figure out if this value has any significance to the data in the file, or if the file was
	_ = f.ReadU64Align()
	item := drawFuncs[name]
	if item == nil {
		thingsLog.Printf("unsupported draw function: %q", name)
		return nil
	}
	if item.Parse != nil {
		if err := item.Parse(obj, f, str, buf); err != nil {
			thingsLog.Printf("failed to parse draw %q: %s", name, err)
		}
	}
	obj.DrawFunc = item.Draw
	return nil
}
