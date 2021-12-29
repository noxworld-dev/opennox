package things

import (
	"bytes"
	"fmt"
	"io"
	"reflect"
	"strconv"
	"strings"

	"nox/v1/common/strman"
	"nox/v1/common/types"
)

var (
	reflThing     = reflect.TypeOf(Thing{})
	reflProcFunc  = reflect.TypeOf(ProcFunc{})
	reflThingKeys = make(map[string]reflect.StructField)
)

func init() {
	for i := 0; i < reflThing.NumField(); i++ {
		f := reflThing.Field(i)
		tag := f.Tag.Get("nox")
		name := strings.SplitN(tag, ",", 2)[0]
		if name == "" || name == "-" {
			continue
		}
		reflThingKeys[name] = f
	}
}

type Extent interface {
	isExtent()
}

type Circle struct {
	R int `json:"r"`
}

func (Circle) isExtent() {}

type Box struct {
	W int `json:"w"`
	H int `json:"h"`
}

func (Box) isExtent() {}

type Center struct{}

func (Center) isExtent() {}

type Flag string
type Class string

type RGB struct {
	R byte `json:"r"`
	G byte `json:"g"`
	B byte `json:"b"`
}

type ProcFunc struct {
	Name string   `json:"name"`
	Args []string `json:"args,omitempty"`
}

type Thing struct {
	Name        string    `json:"name" nox:"-"`
	PrettyName  strman.ID `json:"pretty_name,omitempty" nox:"PRETTYNAME"`
	Description strman.ID `json:"description,omitempty" nox:"DESCRIPTION"`
	Class       []Class   `json:"class,omitempty" nox:"CLASS"`
	SubClass    []Class   `json:"sub_class,omitempty" nox:"SUBCLASS"`
	Flags       []Flag    `json:"flags,omitempty" nox:"FLAGS"`

	Menu           *ImageRef   `json:"menu,omitempty" nox:"MENUICON"`
	Image          *ImageRef   `json:"image,omitempty" nox:"PRETTYIMAGE"`
	Health         *int        `json:"health,omitempty" nox:"HEALTH"`
	Speed          *int        `json:"speed,omitempty" nox:"SPEED"`
	Size           *types.Size `json:"size,omitempty" nox:"-"`
	ZSize          *ZSize      `json:"zsize,omitempty" nox:"-"`
	Z              *int        `json:"z,omitempty" nox:"Z"`
	Extent         Extent      `json:"extent,omitempty" nox:"-"`
	Mass           float64     `json:"mass,omitempty" nox:"MASS"`
	Weight         int         `json:"weight,omitempty" nox:"WEIGHT"`
	Price          *int        `json:"price,omitempty" nox:"WORTH"`
	CarryCap       int         `json:"carry_cap,omitempty" nox:"CARRYCAPACITY"`
	Lifetime       int         `json:"lifetime,omitempty" nox:"LIFETIME"`
	Experience     int         `json:"experience,omitempty" nox:"EXPERIENCE"`
	Material       string      `json:"material,omitempty" nox:"MATERIAL"`
	Draw           Draw        `json:"draw,omitempty" nox:"-"`
	AudioLoop      string      `json:"audio_loop,omitempty" nox:"AUDIOLOOP"`
	DamageSound    string      `json:"damage_sound,omitempty" nox:"DAMAGESOUND"`
	LightIntensity int         `json:"light_intensity,omitempty" nox:"LIGHTINTENSITY"`
	LightDirection int         `json:"light_direction,omitempty" nox:"LIGHTDIRECTION"`
	LightPenumbra  int         `json:"light_penumbra,omitempty" nox:"LIGHTPENUMBRA"`
	LightColor     *RGB        `json:"light_color,omitempty" nox:"-"`

	Preprocess     *ProcFunc `json:"preprocess,omitempty" nox:"PREPROCESS"`
	OnCreate       *ProcFunc `json:"on_create,omitempty" nox:"CREATE"`
	OnInit         *ProcFunc `json:"on_init,omitempty" nox:"INIT"`
	OnUpdate       *ProcFunc `json:"on_update,omitempty" nox:"UPDATE"`
	OnDamage       *ProcFunc `json:"on_damage,omitempty" nox:"DAMAGE"`
	OnClientUpdate *ProcFunc `json:"on_client_update,omitempty" nox:"CLIENTUPDATE"`
	OnCollide      *ProcFunc `json:"on_collide,omitempty" nox:"COLLIDE"`
	OnPickup       *ProcFunc `json:"on_pickup,omitempty" nox:"PICKUP"`
	OnUse          *ProcFunc `json:"on_use,omitempty" nox:"USE"`
	OnDrop         *ProcFunc `json:"on_drop,omitempty" nox:"DROP"`
	OnXfer         *ProcFunc `json:"on_xfer,omitempty" nox:"XFER"`
	OnDestroy      *ProcFunc `json:"on_destroy,omitempty" nox:"DESTROY"`
	OnDie          *ProcFunc `json:"on_die,omitempty" nox:"DIE"`
}

type ZSize struct {
	Bottom int `json:"bottom"`
	Top    int `json:"top"`
}

func (f *Reader) ReadThings() ([]Thing, error) {
	if err := f.seek(0, io.SeekStart); err != nil {
		return nil, err
	}
	var out []Thing
	for {
		ok, err := f.skipUntil("THNG")
		if !ok {
			return out, err
		}
		th, err := f.readThing()
		if err != nil {
			return out, err
		}
		out = append(out, *th)
	}
}

func parseThingAttrByKey(th *Thing, key, val string) (bool, error) {
	f, ok := reflThingKeys[key]
	if !ok {
		return false, nil
	}
	ft := f.Type
	rv := reflect.ValueOf(th).Elem().Field(f.Index[0])
	if ft.Kind() == reflect.Ptr {
		nv := reflect.New(ft.Elem())
		rv.Set(nv)
		rv = nv.Elem()
		ft = ft.Elem()
	}
	if ft == reflProcFunc {
		arr := strings.Fields(val)
		rv.Set(reflect.ValueOf(ProcFunc{
			Name: arr[0], Args: arr[1:],
		}))
		return true, nil
	} else if ft.Kind() == reflect.String {
		rv.SetString(val)
		return true, nil
	} else if ft.Kind() == reflect.Int {
		v, err := strconv.Atoi(val)
		if err != nil {
			return false, fmt.Errorf("cannot parse %q: %w", key, err)
		}
		rv.SetInt(int64(v))
		return true, nil
	} else if ft.Kind() == reflect.Float64 {
		if strings.HasPrefix(val, ".") {
			val = "0" + val
		}
		v, err := strconv.ParseFloat(val, 64)
		if err != nil {
			return false, fmt.Errorf("cannot parse %q: %w", key, err)
		}
		rv.SetFloat(v)
		return true, nil
	} else if ft.Kind() == reflect.Slice && ft.Elem().Kind() == reflect.String {
		sub := strings.Split(val, "+")
		arr := reflect.MakeSlice(reflect.SliceOf(ft.Elem()), len(sub), len(sub))
		rv.Set(arr)
		for i, v := range sub {
			v = strings.TrimSpace(v)
			v = strings.ToUpper(v)
			arr.Index(i).SetString(v)
		}
		return true, nil
	}
	return false, fmt.Errorf("unsupported Go type for %q: %v", key, ft)
}

func fixThingAttrs(attr string) []string {
	sub := strings.Split(attr, "=")
	var kvs []string
	for i, s := range sub {
		s = strings.TrimSpace(s)
		if i == 0 || i == len(sub)-1 {
			kvs = append(kvs, s)
			continue
		}
		i := strings.LastIndex(s, " ")
		if i < 0 {
			kvs = append(kvs, s)
			continue
		}
		kvs = append(kvs, strings.TrimSpace(s[:i]), strings.TrimSpace(s[i+1:]))
	}
	var out []string
	for i := 0; i < len(kvs); i += 2 {
		if i+1 >= len(kvs) {
			out = append(out, kvs[i])
		} else {
			out = append(out, kvs[i]+" = "+kvs[i+1])
		}
	}
	return out
}

func (f *Reader) readThing() (*Thing, error) {
	name, err := f.readString8()
	if err != nil {
		return nil, err
	}
	th := &Thing{Name: name}
	for {
		attr, err := f.readString8()
		if err != nil {
			return th, err
		} else if len(attr) == 0 {
			return th, nil
		}
		// this hack exists only because some files are broken
		attrs := []string{attr}
		if strings.Count(attr, "=") > 1 {
			attrs = fixThingAttrs(attr)
		}
		for _, attr := range attrs {
			kv := strings.SplitN(attr, "=", 2)
			key := strings.ToUpper(strings.TrimSpace(kv[0]))
			val := ""
			if len(kv) == 2 {
				val = strings.TrimSpace(kv[1])
			}
			switch key {
			case "DRAW":
				if val != "" {
					return th, fmt.Errorf("unexpected value for attr %q: %q", key, val)
				}
				dr, err := f.readThingDraw()
				if err != nil {
					return th, err
				}
				th.Draw = dr
			case "MENUICON":
				if val != "" {
					return th, fmt.Errorf("unexpected value for attr %q: %q", key, val)
				}
				th.Menu, err = f.readImageRef()
				if err != nil {
					return th, err
				}
			case "PRETTYIMAGE":
				if val != "" {
					return th, fmt.Errorf("unexpected value for attr %q: %q", key, val)
				}
				th.Image, err = f.readImageRef()
				if err != nil {
					return th, err
				}
			case "SIZE", "ZSIZE":
				sub := strings.Fields(val)
				if len(sub) != 2 {
					return th, fmt.Errorf("expected two element for %q", key)
				}
				v1, err := strconv.Atoi(sub[0])
				if err != nil {
					return th, fmt.Errorf("error parsing %q: %w", key, err)
				}
				v2, err := strconv.Atoi(sub[1])
				if err != nil {
					return th, fmt.Errorf("error parsing %q: %w", key, err)
				}
				switch key {
				case "SIZE":
					th.Size = &types.Size{W: v1, H: v2}
				case "ZSIZE":
					th.ZSize = &ZSize{Bottom: v1, Top: v2}
				}
			case "LIGHTCOLOR":
				sub := strings.Fields(val)
				if len(sub) != 3 {
					return th, fmt.Errorf("expected three element for %q", key)
				}
				r, err := strconv.ParseUint(sub[0], 10, 8)
				if err != nil {
					return th, fmt.Errorf("error parsing %q: %w", key, err)
				}
				g, err := strconv.ParseUint(sub[1], 10, 8)
				if err != nil {
					return th, fmt.Errorf("error parsing %q: %w", key, err)
				}
				b, err := strconv.ParseUint(sub[2], 10, 8)
				if err != nil {
					return th, fmt.Errorf("error parsing %q: %w", key, err)
				}
				th.LightColor = &RGB{
					R: byte(r),
					G: byte(g),
					B: byte(b),
				}
			case "EXTENT":
				sub := strings.Fields(val)
				typ := strings.ToUpper(sub[0])
				sub = sub[1:]
				switch typ {
				default:
					return th, fmt.Errorf("unsupported extent type: %q (%q)", typ, attr)
				case "CENTER":
					if len(sub) != 0 {
						return th, fmt.Errorf("expected zero element for %q", typ)
					}
					th.Extent = Center{}
				case "CIRCLE":
					if len(sub) != 1 {
						return th, fmt.Errorf("expected one element for %q", typ)
					}
					r, err := strconv.Atoi(sub[0])
					if err != nil {
						return th, fmt.Errorf("error parsing %q: %w", key, err)
					}
					th.Extent = Circle{R: r}
				case "BOX":
					if len(sub) != 2 {
						return th, fmt.Errorf("expected two element for %q", typ)
					}
					w, err := strconv.Atoi(sub[0])
					if err != nil {
						return th, fmt.Errorf("error parsing %q: %w", key, err)
					}
					h, err := strconv.Atoi(sub[1])
					if err != nil {
						return th, fmt.Errorf("error parsing %q: %w", key, err)
					}
					th.Extent = Box{W: w, H: h}
				}
			default:
				ok, err := parseThingAttrByKey(th, key, val)
				if err != nil {
					return nil, err
				} else if !ok {
					return th, fmt.Errorf("unsupported thing attr: %q", attr)
				}
			}
		}
	}
}

func (f *Reader) skipTHNG() error {
	if err := f.skipBytes8(); err != nil {
		return err
	}
	for {
		attr, err := f.readBytes8()
		if err != nil {
			return err
		} else if len(attr) == 0 {
			return nil
		}
		attr = bytes.SplitN(attr, []byte{'='}, 2)[0]
		attr = bytes.TrimSpace(attr)
		attr = bytes.ToUpper(attr)
		switch name := string(attr); name {
		case "DRAW":
			if err := f.skipThingDraw(); err != nil {
				return err
			}
		case "MENUICON", "PRETTYIMAGE":
			if err := f.skipImageRef(); err != nil {
				return err
			}
		}
	}
}

func (f *Reader) skipThingAnimComplexHeader() (int, error) {
	n, err := f.readU8()
	if err != nil {
		return 0, err
	}
	if err := f.skip(1); err != nil {
		return 0, err
	}
	if err := f.skipBytes8(); err != nil {
		return 0, err
	}
	return int(n), nil
}

func (f *Reader) skipThingAnimVectorDraw() error {
	n, err := f.skipThingAnimComplexHeader()
	if err != nil {
		return err
	}
	for i := 0; i < 8; i++ {
		for j := 0; j < n; j++ {
			if err := f.skipImageRef(); err != nil {
				return err
			}
		}
	}
	return nil
}

func (f *Reader) skipThingAnimStateDraw() error {
	for {
		cmd, err := f.readSect()
		if err == io.EOF {
			return nil
		} else if err != nil {
			return err
		}
		if cmd == "END " {
			return nil
		}
		if err := f.skip(4); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		n, err := f.skipThingAnimComplexHeader()
		if err != nil {
			return err
		}
		for i := 0; i < n; i++ {
			if err := f.skipImageRef(); err != nil {
				return err
			}
		}
	}
}

func (f *Reader) skipThingMonsterDraw() error {
	for {
		sect, err := f.readSect()
		if err == io.EOF {
			return nil
		} else if err != nil {
			return err
		}
		switch sect {
		default:
			return fmt.Errorf("unsupported player draw sect: %q", sect)
		case "END ":
			return nil
		case "STAT":
		}
		if err := f.skip(1); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		n, err := f.skipThingAnimComplexHeader()
		if err != nil {
			return err
		}
		for i := 0; i < 8; i++ {
			for j := 0; j < n; j++ {
				if err := f.skipImageRef(); err != nil {
					return err
				}
			}
		}
	}
}

func (f *Reader) skipThingPlayerDraw() error {
	sect, err := f.readSect()
	if err == io.EOF {
		return nil
	} else if err != nil {
		return err
	}
	switch sect {
	default:
		return fmt.Errorf("unsupported player draw sect: %q", sect)
	case "END ":
		return nil
	case "STAT":
	}
stat:
	for {
		if err := f.skipBytes8(); err != nil {
			return err
		}
		n, err := f.skipThingAnimComplexHeader()
		if err != nil {
			return err
		}
		for {
			sect, err := f.readSect()
			if err == io.EOF {
				return io.ErrUnexpectedEOF
			} else if err != nil {
				return err
			}
			switch sect {
			default:
				return fmt.Errorf("unsupported player draw sect: %q", sect)
			case "END ":
				return nil
			case "STAT":
				goto stat
			case "SEQU":
			}
			if err := f.skipBytes8(); err != nil {
				return err
			}
			for i := 0; i < 8; i++ {
				for j := 0; j < n; j++ {
					if err := f.skipImageRef(); err != nil {
						return err
					}
				}
			}
		}
	}
}
