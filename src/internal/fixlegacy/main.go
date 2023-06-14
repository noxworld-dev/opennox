package main

import (
	"flag"
	"fmt"
	"go/ast"
	"go/format"
	"go/token"
	"go/types"
	"log"
	"os"
	"path/filepath"

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
		return err
	} else if len(pkgs) != 1 {
		return fmt.Errorf("unexpected packages")
	}
	pkg := pkgs[0]
	if len(pkg.CompiledGoFiles) != len(pkg.Syntax) {
		return fmt.Errorf("unexpected list of files")
	}
	for i, f := range pkg.Syntax {
		fname := pkg.CompiledGoFiles[i]
		if err := processFile(pkg, fname, f); err != nil {
			return err
		}
	}
	return nil
}

func processFile(pkg *packages.Package, fname string, f *ast.File) error {
	changed := false
	ast.Inspect(f, func(n ast.Node) bool {
		switch n := n.(type) {
		case *ast.CallExpr:
			if len(n.Args) == 1 {
				changed = fixSameTypeConv(pkg, n) || changed
				changed = fixUnsafeAdd(pkg, n) || changed
			}
		}
		return true
	})
	if !changed {
		return nil
	}
	w, err := os.Create(fname)
	if err != nil {
		return err
	}
	defer w.Close()
	err = format.Node(w, pkg.Fset, f)
	log.Println(filepath.Base(fname))
	return err
}

func fixSameTypeConv(pkg *packages.Package, n *ast.CallExpr) bool {
	if len(n.Args) != 1 {
		return false
	}
	switch t := pkg.TypesInfo.TypeOf(n.Fun).(type) {
	case *types.Basic, *types.Pointer:
		sz := pkg.TypesSizes.Sizeof(t)
		if x := findSameTypeConv(pkg, sz, t, n.Args[0]); x != nil {
			n.Args[0] = x
			return true
		}
	}
	return false
}

func findSameTypeConv(pkg *packages.Package, sz int64, t types.Type, x ast.Expr) ast.Expr {
	x = unwrapParen(x)
	if t2 := pkg.TypesInfo.TypeOf(x); t2 == nil {
		return nil
	} else if types.Identical(t, t2) {
		return x
	}
	switch x := x.(type) {
	case *ast.CallExpr:
		if len(x.Args) != 1 {
			return nil
		}
		t2 := pkg.TypesInfo.TypeOf(x.Fun)
		if _, ok := t2.(*types.Signature); ok {
			return nil // real call, not a conversion
		}
		if types.Identical(t, t2) {
			return x.Args[0]
		}
		if pkg.TypesSizes.Sizeof(t2) != sz {
			return nil
		}
		return findSameTypeConv(pkg, sz, t, x.Args[0])
	default:
		return nil
	}
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
