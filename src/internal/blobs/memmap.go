package blobs

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"regexp"
	"sort"
	"strconv"
)

var reMapping = regexp.MustCompile(`[ \t]+(//[ \t]*)?\{0x([A-Fa-f\d]+), (\d+), (\d+), ("[^"]+")\},\s*(?://\s*(?:(?:0x[A-Fa-f\d]+)|([A-Z]+:[^\n]+)))?\n`)

type Var struct {
	Blob     uintptr
	Off      uintptr
	Size     uintptr
	Name     string
	Comment  string
	Disabled bool
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
		disabled := loc[2] >= 0
		blob, err := strconv.ParseUint(string(data[loc[4]:loc[5]]), 16, 64)
		if err != nil {
			return nil, err
		}
		off, err := strconv.ParseUint(string(data[loc[6]:loc[7]]), 0, 64)
		if err != nil {
			return nil, err
		}
		size, err := strconv.ParseUint(string(data[loc[8]:loc[9]]), 0, 64)
		if err != nil {
			return nil, err
		}
		name, err := strconv.Unquote(string(data[loc[10]:loc[11]]))
		if err != nil {
			return nil, err
		}
		var cm string
		if len(loc) >= 14 && loc[12] > 0 {
			cm = string(data[loc[12]:loc[13]])
		}
		m.Vars = append(m.Vars, Var{
			Blob:     uintptr(blob),
			Off:      uintptr(off),
			Size:     uintptr(size),
			Name:     name,
			Comment:  cm,
			Disabled: disabled,
		})
		data = data[end:]
	}
	sort.Slice(m.Vars, func(i, j int) bool {
		v1, v2 := m.Vars[i], m.Vars[j]
		return v1.Blob+v1.Off < v2.Blob+v2.Off
	})
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
		tab := "\t"
		if v.Disabled {
			tab = "\t// "
		}
		cm := v.Comment
		if cm == "" {
			cm = fmt.Sprintf("0x%X", v.Blob+v.Off)
		}
		_, err = fmt.Fprintf(bw, "%s{0x%X, %d, %d, %q},\t// %s\n", tab, v.Blob, v.Off, v.Size, v.Name, cm)
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
	if err := goFormat(memmapGo2); err != nil {
		return err
	}
	return f.Close()
}
