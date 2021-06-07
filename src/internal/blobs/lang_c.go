package blobs

import (
	"bytes"
	"go/token"
	"regexp"
	"strconv"
	"strings"
)

var reBlobAcc = regexp.MustCompile(`(getMem[\w\d]*)\s*\(`)

// BlobAccessesC finds all blob accesses in the C file specified by file and data.
func BlobAccessesC(fs *token.FileSet, name string, data []byte) ([]Access, error) {
	f := fs.AddFile(name, -1, len(data))
	var (
		out  []Access
		last error
	)
	base := 0
	for len(data) > 0 {
		loc := reBlobAcc.FindIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		endi := end // we must restart from the brace, might be more accesses in args
		i := indexToken(data[end:], '(', ')')
		if i < 0 {
			data = data[end:]
			base += end
			continue
		}
		cbase := base
		end += i + 1
		expr := data[start:end]
		data = data[endi:]
		base += endi

		a, err := parseExprC(f, cbase+start, expr)
		if err != nil {
			last = err
			continue
		}
		out = append(out, *a)
	}
	return out, last
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
	skip := 0
	for i, b := range data {
		if skip > 0 {
			skip--
			continue
		}
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
		case '-': // special case for '->', '--', '-='
			if i+1 < len(data) {
				switch data[i+1] {
				case '-', '=', '>':
					skip++
					continue
				}
			}
		case '+': // special case for '++', '+='
			if i+1 < len(data) {
				switch data[i+1] {
				case '+', '=':
					skip++
					continue
				}
			}
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

func parseExprC(f *token.File, base int, expr []byte) (*Access, error) {
	sexp := StringPos{
		Val: string(expr),
		Pos: []token.Pos{
			f.Pos(base),
			f.Pos(base + len(expr)),
		},
	}
	data := expr
	i := bytes.IndexByte(data, '(')
	name := string(bytes.TrimSpace(data[:i]))
	npos := []token.Pos{
		f.Pos(base),
		f.Pos(base + i),
	}
	j := bytes.IndexByte(data[i:], ',')
	blob, err := strconv.ParseUint(string(bytes.TrimSpace(data[i+1:i+j])), 0, 64)
	if err != nil {
		return nil, err
	}
	bpos := []token.Pos{
		f.Pos(base + i + 1),
		f.Pos(base + i + j),
	}
	base += i + j + 1
	data = data[i+j+1:]
	data = data[:len(data)-1]
	var (
		parts    []string
		partsPos [][]token.Pos
		neg      = false
		opPos    = f.Pos(base)
	)
	for len(data) > 0 {
		i := indexTokenAll(data, '+', '-')
		if i < 0 {
			s := string(bytes.TrimSpace(data))
			if neg {
				s = "- " + s
			} else {
				s = "+ " + s
			}
			parts = append(parts, s)
			partsPos = append(partsPos, []token.Pos{
				opPos, f.Pos(base + len(data)),
			})
			break
		}
		s := string(bytes.TrimSpace(data[:i]))
		if s != "" {
			if neg {
				s = "- " + s
			} else {
				s = "+ " + s
			}
			parts = append(parts, s)
			partsPos = append(partsPos, []token.Pos{
				opPos, f.Pos(base + i - 1),
			})
		}
		opPos = f.Pos(base + i)
		neg = data[i] == '-'
		data = data[i+1:]
		base += i + 1
	}
	var (
		off    uintptr
		offN   int
		offPos []token.Pos
		rest   []StringPos
	)
	for i, s := range parts {
		if s == "+ " || s == "- " {
			panic("bug!")
		}
		op := s
		pos := partsPos[i]
		neg := false
		if strings.HasPrefix(s, "-") {
			s = strings.TrimSpace(s[1:])
			neg = true
		} else if strings.HasPrefix(s, "+") {
			s = strings.TrimSpace(s[1:])
		}
		v, err := strconv.ParseUint(s, 0, 64)
		if err != nil {
			rest = append(rest, StringPos{Val: op, Pos: pos})
			continue
		}
		if neg {
			off -= uintptr(v)
		} else {
			off += uintptr(v)
		}
		offN++
		offPos = pos
	}
	var r StringPos
	if len(rest) == 1 {
		r = rest[0]
	} else {
		var strs []string
		for _, s := range rest {
			strs = append(strs, s.Val)
		}
		r = StringPos{Val: strings.Join(strs, " ")}
	}
	o := AddrPos{Val: off}
	if offN == 1 {
		o.Pos = offPos
	}
	return &Access{
		Expr: sexp,
		Name: StringPos{
			Val: name, Pos: npos,
		},
		Blob: AddrPos{
			Val: uintptr(blob), Pos: bpos,
		},
		Off:   o,
		Index: r,
	}, nil
}
