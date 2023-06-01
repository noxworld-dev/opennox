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
	fDir = flag.String("dir", "./glegacy", "source directory")
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
			case *ast.CallExpr:
				name, _ := asIdent(n.Fun)
				switch name {
				default:
					switch {
					case strings.HasPrefix(name, "memmap.Ptr"):
						if len(n.Args) == 2 {
							changed = memmapFixOffset(n.Args[1]) || changed
						}
					}
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
