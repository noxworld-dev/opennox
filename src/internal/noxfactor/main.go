package main

import (
	"bytes"
	"flag"
	"fmt"
	"go/ast"
	"go/format"
	"go/parser"
	"go/printer"
	"go/token"
	"log"
	"os"
	"path/filepath"
	"strconv"

	noxflags "nox/v1/common/flags"
)

var (
	fPath = flag.String("path", ".", "path to scan")
)

func main() {
	flag.Parse()
	if err := run(*fPath); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run(path string) error {
	list, err := os.ReadDir(path)
	if err != nil {
		return err
	}
	for _, fi := range list {
		if fi.IsDir() {
			continue
		}
		if filepath.Ext(fi.Name()) != ".go" {
			continue
		}
		if err := runFile(filepath.Join(path, fi.Name())); err != nil {
			return err
		}
	}
	return nil
}

func runFile(path string) error {
	log.Println(path)
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	fs := token.NewFileSet()
	f, err := parser.ParseFile(fs, path, data, parser.ParseComments)
	if err != nil {
		return err
	}
	v := &visitor{}
	ast.Walk(v, f)
	if !v.changed {
		return nil
	}
	var buf bytes.Buffer
	err = format.Node(&buf, fs, f)
	if err != nil {
		log.Println(err)
		buf.Reset()
		err = printer.Fprint(&buf, fs, f)
		if err != nil {
			return err
		}
	}
	return os.WriteFile(path, buf.Bytes(), 0644)
}

type visitor struct {
	changed bool
}

func (v *visitor) visitFlagsCall(n *ast.CallExpr, fnc string) {
	switch fnc {
	case "HasGame", "SetGame", "UnsetGame":
		if len(n.Args) != 1 {
			return
		}
		arg, ok := n.Args[0].(*ast.BasicLit)
		if !ok || arg.Kind != token.INT {
			return
		}
		val, err := strconv.ParseUint(arg.Value, 0, 64)
		if err != nil {
			log.Println(err)
			return
		}
		v.changed = true
		n.Args[0] = &ast.Ident{Name: noxflags.GameFlag(val).GoString()}
	}
}
func (v *visitor) visitCall(n *ast.CallExpr) {
	sel, ok := n.Fun.(*ast.SelectorExpr)
	if !ok {
		return
	}
	pkg, ok := sel.X.(*ast.Ident)
	if !ok {
		return
	}
	switch pkg.Name {
	case "noxflags":
		v.visitFlagsCall(n, sel.Sel.Name)
	}
}

func (v *visitor) Visit(n ast.Node) ast.Visitor {
	switch n := n.(type) {
	case *ast.CallExpr:
		v.visitCall(n)
	}
	return v
}
