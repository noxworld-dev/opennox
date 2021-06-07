package blobs

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"regexp"
	"strconv"
)

var reMapping = regexp.MustCompile(`[ \t]+\{0x([A-Fa-f\d]+), (\d+), (\d+), ("[^"]+")\},\s*(?://\s*0x[A-Fa-f\d]+)?\n`)

type Var struct {
	Blob uintptr
	Off  uintptr
	Size uintptr
	Name string
}

type Mapping struct {
	pre  []byte
	Vars []Var
	post []byte
}

// ReadMemmap reads memory mappings for the blobs and allows to manipulate them.
func ReadMemmap() (*Mapping, error) {
	data, err := ReadFile(memmapGo2)
	if err != nil {
		return nil, err
	}
	m := new(Mapping)
	for {
		loc := reMapping.FindSubmatchIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		if len(bytes.TrimSpace(data[:start])) > 0 {
			m.pre = append(m.pre, data[:start]...)
		}
		blob, err := strconv.ParseUint(string(data[loc[2]:loc[3]]), 16, 64)
		if err != nil {
			return nil, err
		}
		off, err := strconv.ParseUint(string(data[loc[4]:loc[5]]), 0, 64)
		if err != nil {
			return nil, err
		}
		size, err := strconv.ParseUint(string(data[loc[6]:loc[7]]), 0, 64)
		if err != nil {
			return nil, err
		}
		name, err := strconv.Unquote(string(data[loc[8]:loc[9]]))
		if err != nil {
			return nil, err
		}
		m.Vars = append(m.Vars, Var{
			Blob: uintptr(blob),
			Off:  uintptr(off),
			Size: uintptr(size),
			Name: name,
		})
		data = data[end:]
	}
	m.post = append(m.post, data...)
	return m, nil
}

// Write blob mappings back to file.
func (m *Mapping) Write() error {
	f, err := os.Create(Path(memmapGo2))
	if err != nil {
		return err
	}
	defer f.Close()

	if _, err = f.Write(m.pre); err != nil {
		return err
	}
	bw := bufio.NewWriter(f)
	for _, v := range m.Vars {
		_, err = fmt.Fprintf(bw, "\t{0x%X, %d, %d, %q},\t// 0x%X\n", v.Blob, v.Off, v.Size, v.Name, v.Blob+v.Off)
		if err != nil {
			return err
		}
	}
	if err = bw.Flush(); err != nil {
		return err
	}
	if _, err = f.Write(m.post); err != nil {
		return err
	}
	return f.Close()
}
