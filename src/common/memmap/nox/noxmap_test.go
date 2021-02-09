package nox

import (
	"bytes"
	"fmt"
	"io/ioutil"
	"nox/common/memmap"
	"path/filepath"
	"regexp"
	"sort"
	"strconv"
	"strings"
	"testing"
)

func TestIntersection(t *testing.T) {
	vars := memmap.Variables()
	for i, v := range vars[:len(vars)-1] {
		v2 := vars[i+1]
		if end := v.Addr + v.Size; end > v2.Addr {
			t.Errorf("intersection between %s and %s (%+d)", v.Name, v2.Name, int64(end)-int64(v2.Addr))
		}
	}
}

func TestCodeStatic(t *testing.T) {
	const path = "../../.."
	files, err := ioutil.ReadDir(path)
	if err != nil {
		t.Fatal(err)
	}
	for _, fi := range files {
		if fi.IsDir() {
			continue // we have a flat file tree
		}
		name := fi.Name()
		switch filepath.Ext(name) {
		case ".c", ".h":
			t.Run(filepath.Base(name), func(t *testing.T) {
				if name == "memmap.h" {
					t.SkipNow()
				}
				checkFileC(t, filepath.Join(path, name))
			})
		case ".go":
			t.Run(filepath.Base(name), func(t *testing.T) {
				checkFileGo(t, filepath.Join(path, name))
			})
		}
	}
}

var reBlobAcc = regexp.MustCompile(`(getMem[\w\d]*)\s*\(`)

func checkFileC(t testing.TB, path string) {
	data, err := ioutil.ReadFile(path)
	if err != nil {
		t.Fatal(err)
	}
	for len(data) > 0 {
		loc := reBlobAcc.FindIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		i := indexToken(data[end:], '(', ')')
		if i < 0 {
			data = data[end:]
			continue
		}
		end += i + 1
		expr := data[start:end]
		data = data[end:]
		checkExprC(t, expr)
	}
}

func removeLine(t testing.TB, path, word string) {
	bword := []byte(word)
	data, err := ioutil.ReadFile(path)
	if err != nil {
		t.Fatal(err)
	}
	lines := bytes.Split(data, []byte("\n"))
	for i, line := range lines {
		if bytes.Contains(line, bword) {
			lines[i] = nil
		}
	}
	data = bytes.Join(lines, []byte("\n"))
	err = ioutil.WriteFile(path, data, 0644)
	if err != nil {
		t.Fatal(err)
	}
}

func checkExprC(t testing.TB, expr []byte) bool {
	data := expr
	//t.Logf("%q", string(data))
	i := bytes.IndexByte(data, '(')
	j := bytes.IndexByte(data[i:], ',')
	blob, err := strconv.ParseUint(string(bytes.TrimSpace(data[i+1:i+j])), 0, 64)
	if err != nil {
		t.Fatal(err)
	}
	data = data[i+j+1:]
	data = data[:len(data)-1]
	var (
		parts []string
		neg   = false
	)
	for len(data) > 0 {
		i := indexTokenAll(data, '+', '-')
		if i < 0 {
			s := string(bytes.TrimSpace(data))
			if neg {
				s = "-" + s
			}
			parts = append(parts, s)
			break
		}
		s := string(bytes.TrimSpace(data[:i]))
		if neg {
			s = "-" + s
		}
		parts = append(parts, s)
		neg = data[i] == '-'
		data = data[i+1:]
	}
	var off uintptr
	for _, s := range parts {
		neg := false
		if strings.HasPrefix(s, "-") {
			s = s[1:]
			neg = true
		}
		v, err := strconv.ParseUint(s, 0, 64)
		if err != nil {
			continue
		}
		if neg {
			off -= uintptr(v)
		} else {
			off += uintptr(v)
		}
	}
	//t.Logf("%q = (0x%X, %d); %q", string(expr), blob, off, parts)
	if v := memmap.VariableByAddr(uintptr(blob) + off); v != nil {
		voff := v.Addr - uintptr(blob)
		t.Errorf("invalid access: accessing %s (+%d)[%d] as %q (%+d)", v.Name, voff, v.Size, string(expr), off-voff)
		return false
	}
	return true
}

func checkFileGo(t testing.TB, path string) {
	t.Skip("TODO")
}

func indexToken(data []byte, start, end byte) int {
	cnt := 1
	for i, b := range data {
		switch b {
		case start:
			cnt++
		case end:
			cnt--
			if cnt == 0 {
				return i
			}
		}
	}
	return -1
}

func indexTokenAll(data []byte, tokens ...byte) int {
	bcnt := 0
	scnt := 0
	for i, b := range data {
		switch b {
		case '(':
			bcnt++
		case '[':
			scnt++
		case ')':
			if bcnt == 0 {
				return -1
			}
			bcnt--
		case ']':
			if scnt == 0 {
				return -1
			}
			scnt--
		}
		if scnt == 0 && bcnt == 0 {
			for _, tok := range tokens {
				if b == tok {
					return i
				}
			}
			continue
		}
	}
	return -1
}

func TestSortMemmap(t *testing.T) {
	sort.Slice(noxMemmap, func(i, j int) bool {
		a, b := &noxMemmap[i], &noxMemmap[j]
		return a.blob+a.off < b.blob+b.off
	})
	for _, v := range noxMemmap {
		fmt.Printf("{0x%X, %d, %d, %q}, // 0x%X\n", v.blob, v.off, v.size, v.name, v.blob+v.off)
	}
}
