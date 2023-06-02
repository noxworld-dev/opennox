package main

import (
	"flag"
	"fmt"
	"go/ast"
	"go/format"
	"go/parser"
	"go/token"
	"os"
	"path/filepath"
	"strings"
)

var (
	fDir = flag.String("dir", "./legacy", "source directory")
)

func main() {
	flag.Parse()
	if err := run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func eachSrcFile(fnc func(path string) error) error {
	names, err := os.ReadDir(*fDir)
	if err != nil {
		return err
	}
	for _, d := range names {
		if !strings.HasSuffix(d.Name(), ".go") {
			continue
		}
		path := filepath.Join(*fDir, d.Name())
		if err := fnc(path); err != nil {
			return err
		}
	}
	return nil
}

func eachSrcAST(fs *token.FileSet, fnc func(path string, file *ast.File) (bool, error)) error {
	return eachSrcFile(func(path string) error {
		f, err := os.Open(path)
		if err != nil {
			return err
		}
		defer f.Close()
		file, err := parser.ParseFile(fs, path, f, parser.ParseComments|parser.SkipObjectResolution)
		if err != nil {
			return err
		}
		_ = f.Close()
		changed, err := fnc(path, file)
		if err != nil {
			return err
		}
		if !changed {
			return nil
		}
		f, err = os.Create(path)
		if err != nil {
			return err
		}
		defer f.Close()
		return format.Node(f, fs, file)
	})
}

func run() error {
	return eachSrcAST(token.NewFileSet(), func(path string, file *ast.File) (bool, error) {
		changed := false
		ast.Inspect(file, func(n ast.Node) bool {
			switch n := n.(type) {
			case *ast.AssignStmt:
				for i := range n.Rhs {
					changed = fixExpr(&n.Rhs[i]) || changed
				}
			case *ast.BinaryExpr:
				changed = fixExpr(&n.X) || changed
				changed = fixExpr(&n.Y) || changed
			case *ast.UnaryExpr:
				changed = fixExpr(&n.X) || changed
			case *ast.ParenExpr:
				changed = fixExpr(&n.X) || changed
			case *ast.ReturnStmt:
				for i := range n.Results {
					changed = fixExpr(&n.Results[i]) || changed
				}
			case *ast.ExprStmt:
				changed = fixExpr(&n.X) || changed
			case *ast.CallExpr:
				changed = fixFuncDerefCall(n) || changed
				name, _ := asIdent(n.Fun)
				switch name {
				case "asFuncT":
					if len(n.Args) == 1 {
						if conv, ok := n.Args[0].(*ast.CallExpr); ok && len(conv.Args) == 1 {
							if typ, _ := asIdent(conv.Fun); typ == "uintptr" {
								n.Args[0] = conv.Args[0]
								changed = true
							}
						}
					}
				case "nox_window_new":
					if len(n.Args) == 7 {
						changed = fixFuncIdent(&n.Args[6]) || changed
					}
				case "nox_xxx_wndSetDrawFn_46B340":
					if len(n.Args) == 2 {
						changed = fixFuncIdent(&n.Args[1]) || changed
					}
				case "nox_xxx_wndSetProc_46B2C0", "nox_xxx_wndSetWindowProc_46B300":
					if len(n.Args) == 2 {
						changed = fixFuncIdent(&n.Args[1]) || changed
					}
				case "nox_window_set_all_funcs":
					if len(n.Args) == 4 {
						changed = fixFuncIdent(&n.Args[1]) || changed
						changed = fixFuncIdent(&n.Args[2]) || changed
						changed = fixFuncIdent(&n.Args[3]) || changed
					}
				case "nox_window_call_field_94_fnc":
					if len(n.Args) == 4 {
						changed = fixUptr(&n.Args[1]) || changed
						changed = fixUptr(&n.Args[2]) || changed
						changed = fixUptr(&n.Args[3]) || changed
					}
				case "unsafe.Pointer":
					if len(n.Args) == 1 {
						switch n2 := n.Args[0].(type) {
						case *ast.CallExpr:
							name2, _ := asIdent(n2.Fun)
							switch name2 {
							case "funAddr":
								*n = *n2
								n.Fun = ast.NewIdent("funAddrP")
								changed = true
							}
						}
					}
				default:
					switch {
					case strings.HasPrefix(name, "memmap.Ptr"):
						if len(n.Args) == 2 {
							changed = memmapFixOffset(n.Args[1]) || changed
						}
					}
				}
				changed = fixExpr(&n.Fun) || changed
				for i := range n.Args {
					changed = fixExpr(&n.Args[i]) || changed
				}
			}
			return true
		})
		return changed, nil
	})
}

func asIdent(n ast.Node) (string, bool) {
	switch n := n.(type) {
	case *ast.Ident:
		return n.Name, true
	case *ast.SelectorExpr:
		pre, ok := asIdent(n.X)
		if !ok {
			return "", false
		}
		return pre + "." + n.Sel.Name, true
	case *ast.ParenExpr:
		return asIdent(n.X)
	case *ast.IndexListExpr:
		return asIdent(n.X)
	case *ast.IndexExpr:
		return asIdent(n.X)
	default:
		return "", false
	}
}

func memmapFixOffset(off ast.Expr) bool {
	add, ok := off.(*ast.BinaryExpr)
	if !ok || add.Op != token.ADD {
		return false
	}
	if _, ok = add.Y.(*ast.BasicLit); !ok {
		return false
	}
	if _, ok = add.X.(*ast.BasicLit); ok {
		return false
	}
	switch ax := add.X.(type) {
	default:
		return false
	case *ast.ParenExpr:
		add.X = &ast.CallExpr{Fun: ast.NewIdent("uintptr"), Args: []ast.Expr{add.X}}
		return true
	case *ast.BinaryExpr:
		if ax.Op != token.MUL {
			return false
		}
		if _, ok = ax.Y.(*ast.BasicLit); !ok {
			return false
		}
		x := ax.X
		if _, ok = x.(*ast.BasicLit); ok {
			return false
		}
		if conv, ok := x.(*ast.CallExpr); ok {
			if name, ok := asIdent(conv.Fun); ok {
				if name == "uintptr" {
					return false
				}
			}
		}
		ax.X = &ast.CallExpr{Fun: ast.NewIdent("uintptr"), Args: []ast.Expr{x}}
		return true
	}
}

func fixFuncRef(p *ast.Expr) bool {
	x := *p
	switch x := x.(type) {
	default:
		return false
	case *ast.Ident:
		if x.Name == "nil" {
			return false
		}
		*p = &ast.CallExpr{Fun: ast.NewIdent("funAddrP"), Args: []ast.Expr{x}}
		return true
	case *ast.FuncLit:
		if len(x.Body.List) != 1 {
			return false
		}
		st := x.Body.List[0]
		var ce ast.Expr
		switch st := st.(type) {
		case *ast.ReturnStmt:
			ce = st.Results[0]
		case *ast.ExprStmt:
			ce = st.X
		default:
			return false
		}
		call, ok := ce.(*ast.CallExpr)
		if !ok {
			return false
		}
		*p = &ast.CallExpr{Fun: ast.NewIdent("funAddrP"), Args: []ast.Expr{call.Fun}}
		return true
	}
}

func fixFuncIdent(p *ast.Expr) bool {
	x := *p
	switch x := x.(type) {
	default:
		return false
	case *ast.CallExpr:
		if len(x.Args) == 1 {
			name, _ := asIdent(x.Fun)
			if name == "ccall.FuncAddr" {
				*p = x.Args[0]
				return true
			}
		}
		return false
	case *ast.FuncLit:
		if len(x.Body.List) != 1 {
			return false
		}
		st := x.Body.List[0]
		var ce ast.Expr
		switch st := st.(type) {
		case *ast.ReturnStmt:
			ce = st.Results[0]
		case *ast.ExprStmt:
			ce = st.X
		default:
			return false
		}
		call, ok := ce.(*ast.CallExpr)
		if !ok {
			return false
		}
		*p = call.Fun
		return true
	}
}

func fixUptr(p *ast.Expr) bool {
	x := *p
	switch x := x.(type) {
	case *ast.Ident:
		if x.Name == "nil" {
			*p = ast.NewIdent("0")
			return true
		}
		*p = newCall("uintptr", x)
		return true
	case *ast.BinaryExpr:
		*p = newCall("uintptr", x)
		return true
	case *ast.CallExpr:
		if len(x.Args) == 1 {
			name, _ := asIdent(x.Fun)
			switch name {
			case "uintptr":
				return false
			case "int32", "uint32", "int", "uint":
				*p = x.Args[0]
				fixUptr(p)
				return true
			}
		}
		return false
	case *ast.StarExpr:
		if conv, ok := x.X.(*ast.CallExpr); ok && len(conv.Args) == 1 {
			typ := conv.Fun
			if t, ok := typ.(*ast.ParenExpr); ok {
				typ = t.X
			}
			if ptr, ok := typ.(*ast.StarExpr); ok {
				tname, _ := asIdent(ptr.X)
				switch tname {
				case "int32", "uint32", "int", "uint":
					*p = newCall("uintptr", x)
					return true
				}
			}
		}
		return false
	case *ast.UnaryExpr:
		if x.Op == token.SUB {
			if v, ok := x.X.(*ast.BasicLit); ok && v.Value == "1" {
				*p = ast.NewIdent("math.MaxUint32")
				return true
			}
		}
		return false
	default:
		return false
	}
}

func fixFuncDerefCall(call *ast.CallExpr) bool {
	fnc := call.Fun
	if x, ok := fnc.(*ast.ParenExpr); ok {
		fnc = x.X
	}
	deref, ok := fnc.(*ast.StarExpr)
	if !ok {
		return false
	}
	conv, ok := deref.X.(*ast.CallExpr)
	if !ok || len(conv.Args) != 1 {
		return false
	}
	ctyp := conv.Fun
	if x, ok := ctyp.(*ast.ParenExpr); ok {
		ctyp = x.X
	}
	ptr, ok := ctyp.(*ast.StarExpr)
	if !ok {
		return false
	}
	typ, ok := ptr.X.(*ast.FuncType)
	if !ok {
		return false
	}
	call.Fun = &ast.CallExpr{Fun: &ast.IndexListExpr{
		X:       ast.NewIdent("asFuncT"),
		Indices: []ast.Expr{typ},
	}, Args: conv.Args}
	return true
}

func fixFuncDerefStar(p *ast.Expr) bool {
	e := *p
	deref, ok := e.(*ast.StarExpr)
	if !ok {
		return false
	}
	conv, ok := deref.X.(*ast.CallExpr)
	if !ok || len(conv.Args) != 1 {
		return false
	}
	ctyp := conv.Fun
	if x, ok := ctyp.(*ast.ParenExpr); ok {
		ctyp = x.X
	}
	ptr, ok := ctyp.(*ast.StarExpr)
	if !ok {
		return false
	}
	typ, ok := ptr.X.(*ast.FuncType)
	if !ok {
		return false
	}
	*p = &ast.CallExpr{Fun: &ast.IndexListExpr{
		X:       ast.NewIdent("asFuncT"),
		Indices: []ast.Expr{typ},
	}, Args: conv.Args}
	return true
}

func fixExpr(p *ast.Expr) bool {
	x := *p
	switch x := x.(type) {
	case *ast.TypeAssertExpr:
		if call, ok := x.X.(*ast.CallExpr); ok {
			name, _ := asIdent(call.Fun)
			if name == "asFunc" {
				*p = &ast.CallExpr{Fun: &ast.IndexListExpr{
					X:       ast.NewIdent("asFuncT"),
					Indices: []ast.Expr{x.Type},
				}, Args: []ast.Expr{
					newCall("unsafe.Pointer", newCall("uintptr", call.Args[0])),
				}}
				return true
			}
		}
	case *ast.CallExpr:
		name, _ := asIdent(x.Fun)
		switch name {
		case "funAddrP":
			if len(x.Args) == 1 {
				if a, _ := asIdent(x.Args[0]); a == "nil" {
					*p = x.Args[0]
					return true
				}
			}
		}
	}
	changed := false
	changed = fixFuncDerefStar(p) || changed
	return changed
}

func newCall(name string, args ...ast.Expr) ast.Expr {
	return &ast.CallExpr{Fun: ast.NewIdent(name), Args: args}
}
