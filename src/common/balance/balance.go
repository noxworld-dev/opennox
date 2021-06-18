package balance

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"unicode"

	"gopkg.in/yaml.v2"

	"nox/v1/common/crypt"
	"nox/v1/common/fs"
)

const (
	GamedataFile = "gamedata.bin"
	TagSolo      = "SOLO"
	TagArena     = "ARENA"
)

func newFile() *File {
	return &File{
		Global: make(Config),
		Tags:   make(map[string]Config),
	}
}

type File struct {
	Global Config
	Tags   map[string]Config
	Parent *File
}

func (f *File) Value(tag, k string) Value {
	if f == nil {
		return nil
	}
	k = strings.ToLower(k)
	if m, ok := f.Tags[tag]; ok {
		if v, ok := m[k]; ok {
			return v
		}
	}
	if v, ok := f.Global[k]; ok {
		return v
	}
	return f.Parent.Value(tag, k)
}

func (f *File) FloatDef(tag, k string, def float64) float64 {
	v, ok := f.Float(tag, k)
	if !ok {
		return def
	}
	return v
}

func (f *File) Float(tag, k string) (float64, bool) {
	switch v := f.Value(tag, k).(type) {
	case nil:
		return 0, false
	case Float:
		return float64(v), true
	case Array:
		if len(v) == 0 {
			return 0, false
		}
		return v[0], true
	default:
		panic("unexpected type")
	}
}

func (f *File) Array(tag, k string) []float64 {
	switch v := f.Value(tag, k).(type) {
	case nil:
		return nil
	case Float:
		return []float64{float64(v)}
	case Array:
		return v
	default:
		panic("unexpected type")
	}
}

func (f *File) ArrayDef(tag, k string, def []float64) []float64 {
	v := f.Array(tag, k)
	if len(v) == 0 {
		return def
	}
	return v
}

type Config map[string]Value

type Value interface {
	isValue()
}

type Float float64

func (Float) isValue() {}

type Array []float64

func (Array) isValue() {}

func ReadBalance(path string) (*File, error) {
	orig, err := readGamedata(path)
	oerr := err
	if err != nil && !os.IsNotExist(err) {
		return nil, err
	}
	yml, err := readGamedataYML(path)
	if err != nil && !os.IsNotExist(err) {
		return nil, err
	}
	if orig == nil && yml == nil {
		return nil, oerr
	}
	if orig != nil && yml != nil {
		yml.Parent = orig
		return yml, nil
	}
	if yml != nil {
		return yml, nil
	}
	return orig, nil
}

func readGamedata(path string) (*File, error) {
	f, err := fs.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r, err := crypt.NewReader(f, crypt.GameDataBin)
	if err != nil {
		return nil, err
	}
	sc := bufio.NewScanner(r)

	file := newFile()
	for sc.Scan() {
		raw := bytes.TrimSpace(sc.Bytes())
		raw = bytes.Trim(raw, "\x00")
		if len(raw) == 0 || raw[0] == '#' {
			continue
		}
		// value start
		sub := bytes.SplitN(raw, []byte("="), 2)
		if len(sub) < 2 || len(sub[0]) == 0 {
			return nil, fmt.Errorf("invalid gamedata line: %q", string(raw))
		}
		key := bytes.TrimSpace(sub[0])
		val := bytes.TrimSpace(sub[1])
		sub = bytes.Fields(key)
		if len(sub) > 2 {
			return nil, fmt.Errorf("invalid gamedata key: %q", string(raw))
		}
		var (
			tag  string
			name string
		)
		if len(sub) == 1 {
			name = string(sub[0])
		} else {
			tag = string(sub[0])
			name = string(sub[1])
		}
		name = strings.ToLower(name)
		dst := file.Global
		if tag != "" {
			dst = file.Tags[tag]
			if dst == nil {
				dst = make(Config)
				file.Tags[tag] = dst
			}
		}
		val = append([]byte{}, val...) // copy
		for len(val) == 0 || val[len(val)-1] != ';' {
			if !sc.Scan() {
				return nil, fmt.Errorf("invalid gamedata key: %q", string(raw))
			}
			val = append(val, sc.Bytes()...)
		}
		if len(val) == 0 || val[len(val)-1] != ';' {
			return nil, fmt.Errorf("invalid gamedata key: %q", string(raw))
		}
		val = val[:len(val)-1]
		sub = bytes.FieldsFunc(val, func(r rune) bool {
			return unicode.IsSpace(r) || r == ','
		})
		out := make(Array, 0, len(sub))
		for _, v := range sub {
			if n := len(v); v[n-1] == 'f' {
				v = v[:n-1]
			}
			v, err := strconv.ParseFloat(string(v), 64)
			if err != nil {
				return nil, err
			}
			out = append(out, v)
		}
		if len(out) == 1 {
			dst[name] = Float(out[0])
		} else {
			dst[name] = out
		}
	}
	return file, sc.Err()
}

var (
	_ yaml.Unmarshaler = (*ymlValue)(nil)
)

type ymlValue struct {
	global Value
	tags   map[string]Value
}

func (v *ymlValue) UnmarshalYAML(fnc func(interface{}) error) error {
	var val float64
	if err := fnc(&val); err == nil {
		v.global = Float(val)
		return nil
	}
	var arr []float64
	if err := fnc(&arr); err == nil {
		v.global = Array(arr)
		return nil
	}
	var mval map[string]float64
	if err := fnc(&mval); err == nil {
		v.tags = make(map[string]Value, len(mval))
		for key, val := range mval {
			v.tags[key] = Float(val)
		}
		return nil
	}
	var marr map[string][]float64
	if err := fnc(&marr); err == nil {
		v.tags = make(map[string]Value, len(mval))
		for key, val := range marr {
			v.tags[key] = Array(val)
		}
		return nil
	}
	var s string
	_ = fnc(&s)
	return fmt.Errorf("cannot decode value: %q", s)
}

func readGamedataYML(path string) (*File, error) {
	ext := filepath.Ext(path)
	path = strings.TrimSuffix(path, ext) + ".yml"
	f, err := fs.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	var m map[string]*ymlValue
	if err := yaml.NewDecoder(f).Decode(&m); err != nil {
		return nil, err
	}
	file := newFile()
	for k, v := range m {
		k = strings.ToLower(k)
		if v.global != nil {
			file.Global[k] = v.global
			continue
		}
		for tag, val := range v.tags {
			m := file.Tags[tag]
			if m == nil {
				m = make(Config)
				file.Tags[tag] = m
			}
			m[k] = val
		}
	}
	return file, nil
}
