package main

import (
	"flag"
	"fmt"
	"go/ast"
	"go/constant"
	"go/format"
	"go/parser"
	"go/token"
	"go/types"
	"log"
	"os"
	"path/filepath"
	"strings"

	"golang.org/x/tools/go/packages"
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

func run() error {
	for i := 0; i < 10; i++ {
		changed, err := runOnce()
		if err != nil {
			return err
		} else if !changed {
			break
		}
	}
	return nil
}

func runOnce() (bool, error) {
	fs := token.NewFileSet()
	pkgs, err := packages.Load(&packages.Config{
		Mode: packages.NeedName |
			packages.NeedCompiledGoFiles |
			packages.NeedTypes |
			packages.NeedTypesInfo |
			packages.NeedTypesSizes |
			packages.NeedSyntax,
		Dir:  *fDir,
		Env:  append(os.Environ(), "GOARCH=386"),
		Fset: fs,
	}, ".")
	if err != nil {
		return false, err
	} else if len(pkgs) != 1 {
		return false, fmt.Errorf("unexpected packages")
	}
	pkg := pkgs[0]
	if len(pkg.CompiledGoFiles) != len(pkg.Syntax) {
		return false, fmt.Errorf("unexpected list of files")
	}
	anyChanged := false
	for i, f := range pkg.Syntax {
		fname := pkg.CompiledGoFiles[i]
		changed, err := processFile(pkg, fname, f)
		if err != nil {
			return false, err
		}
		anyChanged = anyChanged || changed
	}
	return anyChanged, nil
}

func processFile(pkg *packages.Package, fname string, f *ast.File) (bool, error) {
	changed := false
	ast.Inspect(f, func(n ast.Node) bool {
		switch n := n.(type) {
		case *ast.ParenExpr:
			simplifyExpr(pkg, &n.X, &changed)
		case *ast.StarExpr:
			simplifyExpr(pkg, &n.X, &changed)
		case *ast.UnaryExpr:
			simplifyExpr(pkg, &n.X, &changed)
		case *ast.BinaryExpr:
			simplifyExpr(pkg, &n.X, &changed)
			simplifyExpr(pkg, &n.Y, &changed)
		case *ast.IncDecStmt:
			simplifyExpr(pkg, &n.X, &changed)
		case *ast.CallExpr:
			if len(n.Args) == 1 {
				changed = fixUnsafeAdd(pkg, n) || changed
			}
			for i := range n.Args {
				simplifyExpr(pkg, &n.Args[i], &changed)
			}
			if ft, ok := pkg.TypesInfo.TypeOf(n.Fun).(*types.Signature); ok && len(n.Args) == ft.Params().Len() {
				for i := range n.Args {
					expectType(pkg, ft.Params().At(i).Type(), &n.Args[i], &changed)
				}
			}
		case *ast.AssignStmt:
			if len(n.Lhs) == len(n.Rhs) {
				for i := range n.Lhs {
					simplifyExpr(pkg, &n.Lhs[i], &changed)
					simplifyExpr(pkg, &n.Rhs[i], &changed)
				}
				if n.Tok != token.DEFINE {
					for i := range n.Lhs {
						t := pkg.TypesInfo.TypeOf(n.Lhs[i])
						if t == nil {
							continue
						}
						expectType(pkg, t, &n.Rhs[i], &changed)
					}
				}
			}
		}
		return true
	})
	if !changed {
		return false, nil
	}
	w, err := os.Create(fname)
	if err != nil {
		return false, err
	}
	defer w.Close()
	err = format.Node(w, pkg.Fset, f)
	log.Println(filepath.Base(fname))
	return err == nil, err
}

func unwrapParen(x ast.Expr) ast.Expr {
	switch x := x.(type) {
	case *ast.ParenExpr:
		return unwrapParen(x.X)
	default:
		return x
	}
}
func newCall(name string, args ...ast.Expr) ast.Expr {
	return &ast.CallExpr{Fun: ast.NewIdent(name), Args: args}
}
func fixUnsafeAdd(pkg *packages.Package, c1 *ast.CallExpr) bool {
	if len(c1.Args) != 1 {
		return false
	}
	if t, ok := pkg.TypesInfo.TypeOf(c1.Fun).(*types.Basic); !ok || t.Kind() != types.UnsafePointer {
		return false
	}
	c2, ok := unwrapParen(c1.Args[0]).(*ast.CallExpr)
	if !ok || len(c2.Args) != 1 {
		return false
	} else if t, ok := pkg.TypesInfo.TypeOf(c2.Fun).(*types.Basic); !ok || t.Kind() != types.Uintptr {
		return false
	}
	add, ok := c2.Args[0].(*ast.BinaryExpr)
	if !ok || add.Op != token.ADD {
		return false
	}
	rhs, ok := add.Y.(*ast.BasicLit)
	if !ok || rhs.Kind != token.INT {
		return false
	}
	*c1 = ast.CallExpr{
		Fun: ast.NewIdent("unsafe.Add"),
		Args: []ast.Expr{
			newCall("unsafe.Pointer", newCall("uintptr", add.X)),
			add.Y,
		},
	}
	return true
}

func simplifyExpr(pkg *packages.Package, p *ast.Expr, changed *bool) {
	switch x := (*p).(type) {
	case *ast.StarExpr:
		if y, ok := x.X.(*ast.UnaryExpr); ok && y.Op == token.AND {
			*p = y.X
			*changed = true
		}
	}
	fixUnsafeFieldAccess(pkg, p, changed)
}

func expectType(pkg *packages.Package, t types.Type, p *ast.Expr, changed *bool) {
	if !isValidType(t) {
		return
	}
	if hasKind[*types.Interface](t) {
		return
	}
	if hasKind[*types.Signature](t) {
		return
	}
	switch x := (*p).(type) {
	case *ast.BasicLit:
		switch x.Kind {
		case token.INT:
			if x.Value == "0" {
				changeToNil := false
				switch t := t.(type) {
				case *types.Pointer:
					changeToNil = true
				case *types.Basic:
					if t.Kind() == types.UnsafePointer {
						changeToNil = true
					}
				}
				if changeToNil {
					*p = ast.NewIdent("nil")
					*changed = true
					return
				}
			}
		}
	case *ast.CallExpr:
		if len(x.Args) == 1 {
			// unconvert
			switch pkg.TypesInfo.TypeOf(x.Fun).(type) {
			case *types.Basic, *types.Pointer:
				t2 := pkg.TypesInfo.TypeOf(x.Args[0])
				if t2 != nil && types.Identical(t, t2) {
					*p = x.Args[0]
					*changed = true
					return
				}
			}
		}
	}
	fixSameTypeConv2(pkg, t, *p, p, changed)
	fixTypeConv(pkg, t, p, changed)
}

func fixSameTypeConv2(pkg *packages.Package, t types.Type, x ast.Expr, p *ast.Expr, changed *bool) {
	root := x == *p
	x = unwrapParen(x)
	if t2 := pkg.TypesInfo.TypeOf(x); !isValidType(t2) {
		return
	} else if types.Identical(t, t2) && !root {
		*p = x
		*changed = true
		return
	}
	switch x := x.(type) {
	case *ast.CallExpr:
		if len(x.Args) == 0 {
			if dot, ok := x.Fun.(*ast.SelectorExpr); ok && dot.Sel.Name == "C" {
				ct := pkg.TypesInfo.TypeOf(dot.X)
				if types.Identical(t, ct) {
					*p = dot.X
					*changed = true
					return
				}
				if pkg.TypesSizes.Sizeof(ct) != pkg.TypesSizes.Sizeof(t) {
					return // incompatible value sizes - stop
				}
				fixSameTypeConv2(pkg, t, dot.X, p, changed)
			}
			return
		}
		if len(x.Args) != 1 {
			return
		}
		ct := pkg.TypesInfo.TypeOf(x.Fun)
		if _, ok := ct.(*types.Signature); ok {
			return // real call, not a conversion
		}
		if types.Identical(t, ct) && !root {
			*p = x
			*changed = true
			return
		}
		if pkg.TypesSizes.Sizeof(ct) != pkg.TypesSizes.Sizeof(t) {
			return // incompatible value sizes - stop
		}
		fixSameTypeConv2(pkg, t, x.Args[0], p, changed)
	}
}

func hasKind[T types.Type](t types.Type) bool {
	switch t := t.(type) {
	case T:
		return true
	case *types.Named:
		return hasKind[T](t.Underlying())
	default:
		return false
	}
}

func hasPtrKind[T types.Type](t types.Type) bool {
	switch t := t.(type) {
	case T:
		return true
	case *types.Named:
		return hasPtrKind[T](t.Underlying())
	case *types.Pointer:
		return hasKind[T](t.Elem())
	default:
		return false
	}
}

func fixTypeConv(pkg *packages.Package, t types.Type, p *ast.Expr, changed *bool) {
	x := unwrapParen(*p)
	xt := pkg.TypesInfo.TypeOf(x)
	if !isValidType(xt) {
		return
	}
	if types.Identical(t, xt) {
		return
	}
	if hasKind[*types.Interface](t) {
		return
	}
	if hasKind[*types.TypeParam](t) || hasPtrKind[*types.TypeParam](t) {
		return
	}
	switch xt := xt.(type) {
	case *types.Basic:
		if xt.Info()&types.IsUntyped != 0 {
			return
		}
	}
	if types.ConvertibleTo(xt, t) {
		*p = &ast.CallExpr{Fun: astType(pkg, t), Args: []ast.Expr{x}}
		*changed = true
	}
}

func astType(pkg *packages.Package, t types.Type) ast.Expr {
	s := types.TypeString(t, func(p *types.Package) string {
		if p == pkg.Types {
			return ""
		}
		return p.Name()
	})
	s = strings.ReplaceAll(s, "\n\t", " ")
	x, err := parser.ParseExprFrom(pkg.Fset, "", s, 0)
	if err != nil {
		panic(fmt.Errorf("cannot parse: %q, %w", s, err))
	}
	switch x.(type) {
	case *ast.StarExpr, *ast.ArrayType, *ast.InterfaceType:
		return &ast.ParenExpr{X: x}
	}
	return x
}

func isValidType(t types.Type) bool {
	switch t := t.(type) {
	case nil:
		return false
	case *types.Basic:
		return t.Kind() != types.Invalid
	default:
		return true
	}
}

func fixUnsafeFieldAccess(pkg *packages.Package, p *ast.Expr, changed *bool) {
	x := unwrapParen(*p)
	star, ok := x.(*ast.StarExpr)
	if !ok {
		return
	}
	conv, ok := star.X.(*ast.CallExpr)
	if !ok || len(conv.Args) != 1 {
		return
	}
	ct := pkg.TypesInfo.TypeOf(conv.Fun)
	if !isValidType(ct) {
		return
	}
	if _, ok := ct.(*types.Signature); ok {
		return // real call, not conversion
	}
	x = unwrapParen(conv.Args[0])
	add, ok := x.(*ast.CallExpr)
	if !ok || len(add.Args) != 2 {
		return
	}
	if fullNameOf(add.Fun) != "unsafe.Add" {
		return
	}
	ptr, offx := unwrapParen(add.Args[0]), unwrapParen(add.Args[1])
	offv := pkg.TypesInfo.Types[offx].Value
	if offv == nil || offv.Kind() != constant.Int {
		return
	}
	off, ok := constant.Int64Val(offv)
	if !ok || off < 0 {
		return
	}
	switch px := ptr.(type) {
	case *ast.CallExpr:
		if len(px.Args) == 0 {
			if dot, ok := unwrapParen(px.Fun).(*ast.SelectorExpr); ok && dot.Sel.Name == "C" {
				ptr = dot.X
			}
		} else if len(px.Args) == 1 {
			if fullNameOf(px.Fun) == "unsafe.Pointer" {
				ptr = px.Args[0]
			}
		}
	}
	t := pkg.TypesInfo.TypeOf(ptr)
	if !isValidType(t) {
		return
	}
	pt, ok := t.(*types.Pointer)
	if !ok {
		return
	}
	nt, ok := pt.Elem().(*types.Named)
	if !ok {
		return
	}
	st, ok := nt.Underlying().(*types.Struct)
	if !ok {
		return
	}
	if x := fieldForOff(pkg, st, ptr, off, pkg.TypesSizes.Sizeof(ct)); x != nil {
		*p = x
		*changed = true
	}
}

func fieldForOff(pkg *packages.Package, st *types.Struct, x ast.Expr, off, sz int64) ast.Expr {
	if pkg.TypesSizes.Sizeof(st) <= off {
		return nil
	}
	fields := make([]*types.Var, 0, st.NumFields())
	for i := 0; i < st.NumFields(); i++ {
		fields = append(fields, st.Field(i))
	}
	foffs := pkg.TypesSizes.Offsetsof(fields)
	var (
		fld  *types.Var
		doff int64
	)
	for i, foff := range foffs {
		if off >= foff {
			fld = fields[i]
			doff = off - foff
		}
	}
	if fld == nil || !fld.Exported() {
		return nil
	}
	x = &ast.SelectorExpr{X: x, Sel: ast.NewIdent(fld.Name())}
	nt, ok := fld.Type().(*types.Named)
	if !ok {
		if doff == 0 && pkg.TypesSizes.Sizeof(fld.Type()) == sz {
			return x
		}
		return nil
	}
	st2, ok := nt.Underlying().(*types.Struct)
	if !ok {
		if doff == 0 && pkg.TypesSizes.Sizeof(fld.Type()) == sz {
			return x
		}
		return nil
	}
	return fieldForOff(pkg, st2, x, doff, sz)
}

func fullNameOf(x ast.Expr) string {
	x = unwrapParen(x)
	switch x := x.(type) {
	case *ast.Ident:
		return x.Name
	case *ast.SelectorExpr:
		return fullNameOf(x.X) + "." + x.Sel.Name
	default:
		return ""
	}
}
