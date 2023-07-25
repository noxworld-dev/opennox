package main

import (
	"flag"
	"fmt"
	"go/ast"
	"go/constant"
	"go/format"
	"go/token"
	"go/types"
	"log"
	"os"
	"path/filepath"

	"golang.org/x/tools/go/packages"
)

var (
	fDir = flag.String("dir", ".", "source directory")
)

func main() {
	flag.Parse()
	if err := run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run() error {
	for i := 0; i < 25; i++ {
		if i > 0 {
			log.Printf("iteration: %d", i+1)
		}
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
	}, "./legacy")
	if err != nil {
		return false, err
	} else if len(pkgs) != 1 {
		return false, fmt.Errorf("unexpected packages")
	}
	var legacy *packages.Package
	for _, pkg := range pkgs {
		if pkg.Name == "legacy" {
			legacy = pkg
			continue
		}
		for _, e := range pkg.Errors {
			log.Println(e)
		}
	}
	if len(legacy.CompiledGoFiles) != len(legacy.Syntax) {
		return false, fmt.Errorf("unexpected list of files")
	} else if legacy.Name != "legacy" {
		return false, fmt.Errorf("unexpected package: %q", legacy.Name)
	}
	proc := &Processor{pkg: legacy}
	anyChanged := false
	for i, f := range legacy.Syntax {
		fname := legacy.CompiledGoFiles[i]
		changed, err := proc.processFile(fname, f)
		if err != nil {
			return false, err
		}
		anyChanged = anyChanged || changed
	}
	return anyChanged, nil
}

type Processor struct {
	pkg     *packages.Package
	curFile string
}

func (proc *Processor) processFile(fname string, f *ast.File) (bool, error) {
	proc.curFile = filepath.Base(fname)
	defer func() {
		proc.curFile = ""
	}()
	changed := false
	ast.Inspect(f, func(n ast.Node) bool {
		switch n := n.(type) {
		case *ast.ParenExpr:
			proc.simplifyExpr(&n.X, &changed)
		case *ast.StarExpr:
			proc.simplifyExpr(&n.X, &changed)
		case *ast.UnaryExpr:
			proc.simplifyExpr(&n.X, &changed)
		case *ast.BinaryExpr:
			proc.simplifyExpr(&n.X, &changed)
			proc.simplifyExpr(&n.Y, &changed)
			proc.fixBinExprConv(n, &changed)
		case *ast.IncDecStmt:
			proc.simplifyExpr(&n.X, &changed)
		case *ast.CallExpr:
			if len(n.Args) == 1 {
				changed = proc.fixUnsafeAdd(n) || changed
			}
			for i := range n.Args {
				proc.simplifyExpr(&n.Args[i], &changed)
			}
			if ft, ok := proc.pkg.TypesInfo.TypeOf(n.Fun).(*types.Signature); ok && len(n.Args) == ft.Params().Len() {
				for i := range n.Args {
					proc.expectType(ft.Params().At(i).Type(), &n.Args[i], &changed)
				}
			}
			if len(n.Args) == 2 {
				if fullNameOf(n.Fun) == "unsafe.Add" {
					t2 := proc.pkg.TypesInfo.TypeOf(n.Args[0])
					if isValidType(t2) {
						if pt, ok := t2.(*types.Pointer); ok {
							if nt, ok := pt.Elem().(*types.Named); ok {
								if _, ok := nt.Underlying().(*types.Struct); ok {
									n.Args[0] = newCall("unsafe.Pointer", n.Args[0])
									changed = true
								}
							}
						}
					}
				}
			}
		case *ast.AssignStmt:
			if len(n.Lhs) == len(n.Rhs) {
				for i := range n.Lhs {
					proc.simplifyExpr(&n.Lhs[i], &changed)
					proc.simplifyExpr(&n.Rhs[i], &changed)
				}
				if n.Tok != token.DEFINE {
					for i := range n.Lhs {
						t := proc.pkg.TypesInfo.TypeOf(n.Lhs[i])
						if t == nil {
							continue
						}
						proc.expectType(t, &n.Rhs[i], &changed)
					}
				}
			}
		case *ast.BlockStmt:
			proc.optimizeBlock(n, &changed)
		case *ast.IfStmt:
			proc.simplifyExpr(&n.Cond, &changed)
		case *ast.ForStmt:
			if n.Cond != nil {
				proc.simplifyExpr(&n.Cond, &changed)
			}
		case *ast.SwitchStmt:
			if n.Tag != nil {
				proc.simplifyExpr(&n.Tag, &changed)
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
	err = format.Node(w, proc.pkg.Fset, f)
	log.Println(filepath.Base(fname))
	return err == nil, err
}

func (proc *Processor) fixUnsafeAdd(c1 *ast.CallExpr) bool {
	if len(c1.Args) != 1 {
		return false
	}
	if t, ok := proc.pkg.TypesInfo.TypeOf(c1.Fun).(*types.Basic); !ok || t.Kind() != types.UnsafePointer {
		return false
	}
	c2, ok := unwrapParen(c1.Args[0]).(*ast.CallExpr)
	if !ok || len(c2.Args) != 1 {
		return false
	} else if t, ok := proc.pkg.TypesInfo.TypeOf(c2.Fun).(*types.Basic); !ok || t.Kind() != types.Uintptr {
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

func (proc *Processor) shouldUnwrapCasts(x ast.Expr) bool {
	if call, ok := x.(*ast.CallExpr); ok {
		switch fullNameOf(call.Fun) {
		case "nox_new_window_from_file",
			"nox_window_new",
			"nox_xxx_wndGetChildByID_46B0C0",
			"nox_xxx_gLoadImg_42F970",
			"nox_xxx_getFirstPlayerUnit_4DA7C0",
			"nox_xxx_getNextPlayerUnit_4DA7F0",
			"nox_common_playerInfoGetFirst_416EA0",
			"nox_common_playerInfoGetNext_416EE0",
			"nox_common_playerInfoFromNum_417090",
			"nox_xxx_findParentChainPlayer_4EC580",
			"nox_server_getFirstObject_4DA790",
			"nox_server_getNextObject_4DA7A0",
			"nox_xxx_newObjectByTypeID_4E3810",
			"nox_server_teamByXxx_418AE0",
			"nox_server_teamFirst_418B10":
			return true
		}
	}
	return false
}

func (proc *Processor) simplifyExpr(p *ast.Expr, changed *bool) {
	switch x := (*p).(type) {
	case *ast.StarExpr:
		if y, ok := x.X.(*ast.UnaryExpr); ok && y.Op == token.AND {
			*p = y.X
			*changed = true
		}
	case *ast.CallExpr:
		if y, ok := proc.unwrapConv(x); ok {
			if proc.shouldUnwrapCasts(y) {
				*p = y
				*changed = true
			}
		}
	}
	proc.fixUnsafeFieldAccess(p, changed)
}

func (proc *Processor) expectType(t types.Type, p *ast.Expr, changed *bool) {
	if !isValidType(t) {
		return
	}
	if hasKind[*types.Interface](t) {
		return
	}
	if hasKind[*types.Signature](t) {
		return
	}
	if proc.shouldUnwrapCasts(*p) {
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
			switch proc.pkg.TypesInfo.TypeOf(x.Fun).(type) {
			case *types.Basic, *types.Pointer:
				t2 := proc.pkg.TypesInfo.TypeOf(x.Args[0])
				if t2 != nil && types.Identical(t, t2) {
					*p = x.Args[0]
					*changed = true
					return
				}
			}
		}
	}
	proc.fixSameTypeConv2(t, *p, p, changed)
	proc.fixTypeConv(t, p, changed)
}

func (proc *Processor) fixSameTypeConv2(t types.Type, x ast.Expr, p *ast.Expr, changed *bool) {
	root := x == *p
	x = unwrapParen(x)
	if t2 := proc.pkg.TypesInfo.TypeOf(x); !isValidType(t2) {
		return
	} else if types.Identical(t, t2) && !root {
		*p = x
		*changed = true
		return
	}
	switch x := x.(type) {
	case *ast.CallExpr:
		if len(x.Args) == 0 {
			if dot, ok := x.Fun.(*ast.SelectorExpr); ok && (dot.Sel.Name == "C" || dot.Sel.Name == "CObj") {
				ct := proc.pkg.TypesInfo.TypeOf(dot.X)
				if types.Identical(t, ct) {
					*p = dot.X
					*changed = true
					return
				}
				if proc.pkg.TypesSizes.Sizeof(ct) != proc.pkg.TypesSizes.Sizeof(t) {
					return // incompatible value sizes - stop
				}
				proc.fixSameTypeConv2(t, dot.X, p, changed)
			}
			return
		}
		if len(x.Args) != 1 {
			return
		}
		ct := proc.pkg.TypesInfo.TypeOf(x.Fun)
		if _, ok := ct.(*types.Signature); ok {
			return // real call, not a conversion
		}
		if types.Identical(t, ct) && !root {
			*p = x
			*changed = true
			return
		}
		if proc.pkg.TypesSizes.Sizeof(ct) != proc.pkg.TypesSizes.Sizeof(t) {
			return // incompatible value sizes - stop
		}
		proc.fixSameTypeConv2(t, x.Args[0], p, changed)
	}
}

func (proc *Processor) fixTypeConv(t types.Type, p *ast.Expr, changed *bool) {
	x := unwrapParen(*p)
	xt := proc.pkg.TypesInfo.TypeOf(x)
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
			if isPointer(t) {
				if v, ok := proc.evalInt(x); ok && v == 0 {
					*p = ast.NewIdent("nil")
					*changed = true
					return
				}
			}
			return
		}
	}
	if types.ConvertibleTo(xt, t) {
		*p = &ast.CallExpr{Fun: maybeParen(proc.astType(t)), Args: []ast.Expr{x}}
		*changed = true
		return
	}
}

func (proc *Processor) fixUnsafeFieldAccess(p *ast.Expr, changed *bool) {
	x := unwrapParen(*p)
	star, ok := x.(*ast.StarExpr)
	if !ok {
		return
	}
	conv, ok := unwrapParen(star.X).(*ast.CallExpr)
	if !ok || len(conv.Args) != 1 {
		return
	}
	cpt, ok := proc.pkg.TypesInfo.TypeOf(conv.Fun).(*types.Pointer)
	if !ok {
		return
	}
	ct := cpt.Elem()
	x = unwrapParen(conv.Args[0])
	add, ok := x.(*ast.CallExpr)
	if !ok || len(add.Args) != 2 {
		return
	}
	if fullNameOf(add.Fun) != "unsafe.Add" {
		return
	}
	ptr, offx := unwrapParen(add.Args[0]), unwrapParen(add.Args[1])
	offv := proc.pkg.TypesInfo.Types[offx].Value
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
			if dot, ok := unwrapParen(px.Fun).(*ast.SelectorExpr); ok && (dot.Sel.Name == "C" || dot.Sel.Name == "CObj") {
				ptr = dot.X
			}
		} else if len(px.Args) == 1 {
			if fullNameOf(px.Fun) == "unsafe.Pointer" {
				ptr = px.Args[0]
			}
		}
	}
	t := proc.pkg.TypesInfo.TypeOf(ptr)
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
	if x := proc.fieldForOff(nt, st, ptr, off, proc.pkg.TypesSizes.Sizeof(ct)); x != nil {
		*p = x
		*changed = true
	}
}

func (proc *Processor) fieldForOff(nt *types.Named, st *types.Struct, x ast.Expr, off, sz int64) ast.Expr {
	if proc.pkg.TypesSizes.Sizeof(st) <= off {
		return nil
	}
	fields := make([]*types.Var, 0, st.NumFields())
	for i := 0; i < st.NumFields(); i++ {
		fields = append(fields, st.Field(i))
	}
	foffs := proc.pkg.TypesSizes.Offsetsof(fields)
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
	if fld == nil {
		return nil
	}
	if nt != nil {
		obj := nt.Obj()
		if fld.Exported() || obj.Pkg() == proc.pkg.Types {
			x = &ast.SelectorExpr{X: x, Sel: ast.NewIdent(fld.Name())}
		} else {
			switch obj.Pkg().Name() + "." + obj.Name() + "." + fld.Name() {
			case "gui.Window.drawData":
				x = &ast.CallExpr{Fun: &ast.SelectorExpr{X: x, Sel: ast.NewIdent("DrawData")}}
			default:
				return nil
			}
		}
	}
	ftyp := fld.Type()
	nt2, ok := ftyp.(*types.Named)
	if ok {
		ftyp = nt2.Underlying()
	}
	st2, ok := ftyp.(*types.Struct)
	if !ok {
		if doff == 0 && proc.pkg.TypesSizes.Sizeof(fld.Type()) == sz {
			return x
		}
		return nil
	}
	return proc.fieldForOff(nt2, st2, x, doff, sz)
}

func (proc *Processor) fixBinExprConv(b *ast.BinaryExpr, changed *bool) {
	switch b.Op {
	case token.SHL, token.SHR:
		return
	}
	tx := proc.pkg.TypesInfo.TypeOf(b.X)
	ty := proc.pkg.TypesInfo.TypeOf(b.Y)
	best := bestBinExprType(tx, ty)
	if best == nil {
		return
	}
	proc.expectType(best, &b.X, changed)
	proc.expectType(best, &b.Y, changed)
}

func bestBinExprType(x, y types.Type) types.Type {
	if !isValidType(x) || !isValidType(y) {
		return nil
	}
	if types.Identical(x, y) {
		return nil
	}
	if hasKind[*types.Interface](x) || hasKind[*types.Interface](y) {
		return nil
	}
	if isBasicKind(x, types.Int) && isInteger(y) {
		return x
	}
	if isBasicKind(x, types.Int) && isInteger(x) {
		return y
	}
	if isPointer(x) && isInteger(y) {
		return x
	}
	if isPointer(y) && isInteger(x) {
		return y
	}
	return nil
}

func (proc *Processor) optimizeBlock(b *ast.BlockStmt, changed *bool) {
	n := len(b.List)
	if n >= 2 {
		ret, ok1 := b.List[n-1].(*ast.ReturnStmt)
		iff, ok2 := b.List[n-2].(*ast.IfStmt)
		if ok1 && len(ret.Results) == 1 &&
			ok2 && iff.Init == nil && iff.Else == nil &&
			stmtCount(iff.Body) > 3 &&
			!Is[*ast.ReturnStmt](iff.Body.List[len(iff.Body.List)-1]) {
			b.List = b.List[:n-2]
			b.List = append(b.List,
				&ast.IfStmt{Cond: not(iff.Cond), Body: &ast.BlockStmt{List: []ast.Stmt{
					&ast.ReturnStmt{Results: ret.Results},
				}}},
			)
			b.List = append(b.List, iff.Body.List...)
			b.List = append(b.List, &ast.ReturnStmt{Results: ret.Results})
			*changed = true
			return
		}
	}
}
