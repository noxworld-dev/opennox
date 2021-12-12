package main

import (
	"bytes"
	"errors"
	"fmt"
	"go/ast"
	"go/format"
	"go/parser"
	"go/token"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"strconv"
	"strings"

	"github.com/spf13/cobra"
)

const (
	memmapName  = "memmap.c"
	varDefsName = "vardefs.c"
	dataName    = "GAME_data.c"
	initName    = "GAME_data_init.c"
)

func main() {
	cmd := &cobra.Command{
		Use:   "offalign",
		Short: "given an array parameters and the blob offset, rewrites static offsets to appear as array access",
	}
	fBlob := cmd.Flags().Uint("blob", 0, "blob to rewrite")
	fBase := cmd.Flags().Uint("base", 0, "base offset of the array/structure in the blob")
	fElem := cmd.Flags().Uint("elem", 0, "size of the element or structure in the array")
	fCnt := cmd.Flags().Uint("cnt", 1, "number of elements in the array")
	fPrint := cmd.Flags().Bool("print", false, "print base offsets of each element")
	fPath := cmd.Flags().String("path", ".", "path to sources and other files")
	cmd.RunE = func(cmd *cobra.Command, args []string) error {
		cmd.SilenceUsage = true
		base := *fBase
		elem := *fElem
		cnt := *fCnt
		if *fPrint {
			for i := uint(0); i < cnt; i++ {
				log.Printf("elem %d: %d", i, base+elem*i)
			}
		}
		_, err := offsetAlignDir(*fPath, uintptr(*fBlob), uintptr(base), uintptr(elem), uintptr(cnt))
		return err
	}
	if err := cmd.Execute(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func offsetAlignDir(path string, blob, base, elem, cnt uintptr) (int, error) {
	if blob == 0 {
		return 0, errors.New("blob address must be specified")
	}
	if base == 0 {
		return 0, errors.New("base offset in the blob must be specified")
	}
	if elem == 0 {
		return 0, errors.New("element size must be specified")
	}
	num := 0
	if err := eachFileGo(path, nil, func(path string) error {
		ok, err := rewriteFile(path, func(data []byte) []byte {
			return offsetAlignGo(path, data, blob, base, elem, cnt)
		})
		if err != nil {
			return err
		}
		if ok {
			num++
		}
		return nil
	}); err != nil {
		return num, err
	}
	paths, err := readFileListC(path, []string{
		memmapName,
		dataName,
	})
	if err != nil {
		return num, err
	}
	for _, fname := range paths {
		ok, err := offsetAlignFile(fname, blob, base, elem, cnt)
		if err != nil {
			return num, err
		}
		if ok {
			num++
		}
	}
	return num, nil
}

type AlignedOffset struct {
	Base  uintptr
	Elem  BlobOffMult
	Field uintptr
	Raw   []string
}

func (o AlignedOffset) String() string {
	var parts []string
	if o.Base != 0 {
		parts = append(parts, strconv.FormatUint(uint64(o.Base), 10))
	}
	if o.Elem.Static != 0 {
		parts = append(parts, o.Elem.String())
	}
	if o.Field != 0 {
		parts = append(parts, strconv.FormatUint(uint64(o.Field), 10))
	}
	parts = append(parts, o.Raw...)
	return strings.Join(parts, " + ")
}

func (o AlignedOffset) Replace(fnc func(string) string) {
	o.Elem.Replace(fnc)
	for i, s := range o.Raw {
		o.Raw[i] = fnc(s)
	}
}

func (o *BlobOffSum) AddMult(m BlobOffMult) {
	for i, m2 := range o.Mult {
		if m.Static == m2.Static {
			o.Mult[i].Sum.Merge(m.Sum)
			return
		}
	}
	o.Mult = append(o.Mult, m)
}

func (o BlobOffSum) Align(base, elem, cnt uintptr) (AlignedOffset, bool) {
	size := elem * cnt
	if o.Static < base || (size != 0 && o.Static >= base+size) {
		return AlignedOffset{}, false
	}
	out := AlignedOffset{
		Base:  base,
		Field: o.Static - base,
	}
	if out.Field >= elem {
		o.Mult = append([]BlobOffMult{}, o.Mult...)
		n := out.Field / elem
		out.Field %= elem
		o.AddMult(BlobOffMult{Static: elem, Sum: BlobOffSum{Static: n}})
	}
	el, mrest := o.FindMult(elem)
	if el != nil {
		out.Elem = *el
	}
	for _, m := range mrest {
		out.Raw = append(out.Raw, m.String())
	}
	out.Raw = append(out.Raw, o.Raw...)
	return out, true
}

func rewriteFile(path string, fnc func(data []byte) []byte) (bool, error) {
	data, err := ioutil.ReadFile(path)
	if err != nil {
		return false, err
	}
	out := fnc(data)
	if out == nil || bytes.Equal(data, out) {
		return false, nil // skip
	}
	err = ioutil.WriteFile(path, out, 0644)
	return true, err
}

func offsetAlignFile(path string, blob, base, elem, cnt uintptr) (bool, error) {
	data, err := ioutil.ReadFile(path)
	if err != nil {
		return false, err
	}
	out := offsetAlign(data, blob, base, elem, cnt)
	if out == nil || bytes.Equal(data, out) {
		return false, nil // skip
	}
	err = ioutil.WriteFile(path, out, 0644)
	return rewriteFile(path, func(data []byte) []byte {
		return offsetAlign(data, blob, base, elem, cnt)
	})
}

func offsetAlign(data []byte, blob, base, elem, cnt uintptr) []byte {
	if cnt <= 0 {
		cnt = 1
	}
	var (
		buf      bytes.Buffer
		replaced = 0
	)
	for {
		b, ok := nextBlobCall(data)
		if !ok {
			if buf.Len() == 0 {
				return nil // skip
			}
			buf.Write(data)
			break
		}
		if buf.Len() == 0 {
			buf.Grow(len(data))
		}
		next := b.Off[0] // continue from the expression - it may contain other calls
		if b.Base != blob {
			buf.Write(data[:next])
			data = data[next:]
			continue // skip
		}
		exp := bytes.TrimSpace(data[b.Off[0]:b.Off[1]])
		offs, ok := parseOffSum(exp)
		if !ok {
			buf.Write(data[:next])
			data = data[next:]
			continue // skip
		}
		aoff, ok := offs.Align(base, elem, cnt)
		if !ok {
			buf.Write(data[:next])
			data = data[next:]
			continue // skip
		}
		buf.Write(data[:b.Pos[0]])
		fmt.Fprintf(&buf, "%s(0x%X, ", b.Name, b.Base)
		aoff.Replace(func(s string) string {
			nout := offsetAlign([]byte(s), blob, base, elem, cnt)
			if len(nout) == 0 {
				return s
			}
			return string(nout)
		})
		buf.WriteString(aoff.String())
		buf.WriteString(")")
		data = data[b.Pos[1]:]
		replaced++
	}
	if replaced == 0 {
		return nil
	}
	return buf.Bytes()
}

func readFileListC(path string, ignore []string) ([]string, error) {
	var out []string
	err := filepath.WalkDir(path, func(path string, info os.DirEntry, err error) error {
		if err != nil {
			return err
		} else if info.IsDir() {
			return nil // descend
		}
		if !strings.HasSuffix(path, ".c") {
			return nil // ignore
		}
		for _, name := range ignore {
			if strings.HasSuffix(path, name) {
				return nil // ignore
			}
		}
		out = append(out, path)
		return nil
	})
	return out, err
}

func eachFileGo(path string, ignore []string, fnc func(path string) error) error {
	return filepath.WalkDir(path, func(path string, info os.DirEntry, err error) error {
		if err != nil {
			return err
		} else if info.IsDir() {
			base := filepath.Base(path)
			if base != "." && strings.HasPrefix(base, ".") {
				return filepath.SkipDir
			}
			return nil // descend
		}
		if !strings.HasSuffix(path, ".go") {
			return nil // ignore
		}
		for _, name := range ignore {
			if strings.HasSuffix(path, name) {
				return nil // ignore
			}
		}
		return fnc(path)
	})
}

func offsetAlignGo(path string, data []byte, blob, base, elem, cnt uintptr) []byte {
	fset := token.NewFileSet()
	f, err := parser.ParseFile(fset, path, data, parser.ParseComments|parser.SkipObjectResolution)
	if err != nil {
		panic(err)
	}
	found := false
	for _, im := range f.Imports {
		if (im.Name != nil && im.Name.Name == "memmap") || strings.HasSuffix(im.Path.Value, "memmap\"") {
			found = true
			break
		}
	}
	if !found {
		return nil
	}
	al := &offAligner{
		blob: blob,
		base: base,
		elem: elem,
		cnt:  cnt,
	}
	ast.Walk(al, f)
	if al.replaced == 0 {
		return nil
	}
	var buf bytes.Buffer
	if err := format.Node(&buf, fset, f); err != nil {
		panic(err)
	}
	return buf.Bytes()
}

type offAligner struct {
	blob, base, elem, cnt uintptr
	replaced              int
}

func (v *offAligner) Visit(n ast.Node) ast.Visitor {
	switch n := n.(type) {
	default:
		return v
	case *ast.CallExpr:
		if len(n.Args) != 2 {
			return v
		}
		sel, ok := n.Fun.(*ast.SelectorExpr)
		if !ok {
			return v
		}
		pkg, ok := sel.X.(*ast.Ident)
		if !ok || pkg.Name != "memmap" {
			return v
		}
		blobe, ok := n.Args[0].(*ast.BasicLit)
		if !ok || blobe.Kind != token.INT {
			return v
		}
		blob, err := strconv.ParseUint(blobe.Value, 0, 64)
		if err != nil {
			panic(err)
		}
		if uintptr(blob) != v.blob {
			return v
		}
		off, rest := staticExprGo(n.Args[1])
		if off == 0 {
			return v
		}
		x := v.alignGo(off, rest)
		if x == nil {
			return v
		}
		n.Args[1] = x
		v.replaced++
		return v
	}
}

func staticExprGo(n ast.Expr) (uintptr, ast.Expr) {
	if n == nil {
		return 0, nil
	}
	switch n := n.(type) {
	default:
		return 0, n
	case *ast.ParenExpr:
		v, r := staticExprGo(n.X)
		if v == 0 {
			return 0, n
		}
		if r == nil {
			return v, nil
		}
		n.X = r
		return v, n
	case *ast.BasicLit:
		if n.Kind != token.INT {
			return 0, n
		}
		v, err := strconv.ParseUint(n.Value, 0, 64)
		if err != nil {
			return 0, n
		}
		return uintptr(v), nil
	case *ast.BinaryExpr:
		switch n.Op {
		default:
			return 0, n
		case token.MUL:
			x, xr := staticExprGo(n.X)
			y, yr := staticExprGo(n.Y)
			if xr != nil || yr != nil {
				return 0, n
			}
			return x * y, nil
		case token.QUO:
			x, xr := staticExprGo(n.X)
			y, yr := staticExprGo(n.Y)
			if xr != nil || yr != nil {
				return 0, n
			}
			return x / y, nil
		case token.SUB:
			x, xr := staticExprGo(n.X)
			if x == 0 {
				// no positive static part, and we ignore negative
				return 0, n
			}
			// have positive part, maybe with some additions
			if xr == nil {
				// nothing more from the positive side, so can use negative rest
				return x, &ast.UnaryExpr{X: n.Y, Op: n.Op}
			}
			n.X = xr
			return x, n
		case token.ADD:
			x, xr := staticExprGo(n.X)
			y, yr := staticExprGo(n.Y)
			if x == 0 && y == 0 {
				// nothing interesting, keep original
				return 0, n
			}
			v := x + y
			if xr == nil && yr == nil {
				return v, nil
			}
			if xr == nil {
				return v, yr
			} else if yr == nil {
				return v, xr
			}
			n.X = xr
			n.Y = yr
			return v, n
		}
	}
}

func (v *offAligner) alignGo(static uintptr, rest ast.Expr) ast.Expr {
	size := v.elem * v.cnt
	if static < v.base || (size != 0 && static >= v.base+size) {
		return nil
	}
	var parts []ast.Expr
	parts = append(parts, astUint(uint64(v.base)))
	off := static - v.base
	n := off / v.elem
	field := off % v.elem
	isMul := n != 0 || v.cnt != 0
	if muly, mulrest := v.getMultExpr(rest); muly != nil {
		isMul = true
		if n != 0 {
			muly = astAdd(muly, astUint(uint64(n)))
		}
		parts = append(parts, astMul(astUint(uint64(v.elem)), muly))
		if mulrest != nil {
			parts = append(parts, mulrest)
		}
	} else {
		if n != 0 || isMul {
			parts = append(parts, astMul(astUint(uint64(v.elem)), astUint(uint64(n))))
		}
		if rest != nil {
			parts = append(parts, rest)
		}
	}
	if field != 0 || v.elem > 1 {
		parts = append(parts, astUint(uint64(field)))
	}
	return astAdd(parts...)
}

func (v *offAligner) getMultExpr(e ast.Expr) (y, r ast.Expr) {
	switch e := e.(type) {
	default:
		return nil, nil
	case *ast.ParenExpr:
		return v.getMultExpr(e.X)
	case *ast.BinaryExpr:
		switch e.Op {
		default:
			return nil, nil
		case token.MUL:
			xi, xr := staticExprGo(e.X)
			yi, yr := staticExprGo(e.Y)
			if xi*yi == v.elem {
				if xr != nil || yr != nil {
					return nil, nil // one of the parts has additive
				}
				return astUint(1), nil
			}
			if xi == v.elem && yi == 0 {
				if xr != nil {
					return nil, nil // mult has additive
				}
				return yr, nil
			} else if yi == v.elem && xi == 0 {
				if yr != nil {
					return nil, nil // mult has additive
				}
				return xr, nil
			}
			return nil, nil
		case token.ADD:
			xy, xr := v.getMultExpr(e.X)
			yy, yr := v.getMultExpr(e.Y)
			if xy == nil && yy == nil {
				return nil, nil
			}
			var vy ast.Expr
			if xy == nil {
				vy = yy
			} else if yy == nil {
				vy = xy
			} else {
				vy = astAdd(xy, yy)
			}
			if xr == nil && yr == nil {
				return vy, nil
			} else if xr == nil {
				return vy, yr
			} else if yr == nil {
				return vy, xr
			}
			return vy, astAdd(xr, yr)
		}
	}
}

func astUint(v uint64) *ast.BasicLit {
	return &ast.BasicLit{Kind: token.INT, Value: strconv.FormatUint(v, 10)}
}

func astAdd(parts ...ast.Expr) ast.Expr {
	return astCommut(token.ADD, parts...)
}

func astMul(parts ...ast.Expr) ast.Expr {
	return astCommut(token.MUL, parts...)
}

func astCommut(op token.Token, parts ...ast.Expr) ast.Expr {
	for _, v := range parts {
		if v == nil {
			panic("nil expr")
		}
	}
	n := len(parts)
	switch n {
	case 0:
		panic("no parts")
	case 1:
		return parts[0]
	case 2:
		return &ast.BinaryExpr{X: parts[0], Op: op, Y: parts[1]}
	default:
		return &ast.BinaryExpr{X: astCommut(op, parts[:n-1]...), Op: op, Y: parts[n-1]}
	}
}
