package main

import (
	"flag"
	"fmt"
	"go/ast"
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
	switch x := x.(type) {
	case *ast.ParenExpr:
		return findSameTypeConv(pkg, sz, t, x.X)
	case *ast.CallExpr:
		if len(x.Args) != 1 {
			return nil
		}
		t2 := pkg.TypesInfo.TypeOf(x.Fun)
		if _, ok := t2.(*types.Signature); ok {
			return nil // real call, not a conversion
		}
		if t2 == t {
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
