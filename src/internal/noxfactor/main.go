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
	r := new(Refactorer)
	return r.ProcessDir(path)
}

func (r *Refactorer) ProcessDir(path string) error {
	list, err := os.ReadDir(path)
	if err != nil {
		return err
	}
	var filtered []string
	for _, fi := range list {
		if fi.IsDir() {
			continue
		}
		if filepath.Ext(fi.Name()) != ".go" {
			continue
		}
		filtered = append(filtered, filepath.Join(path, fi.Name()))
	}
	list = nil
	r.defined = make(map[string]struct{})
	for _, fpath := range filtered {
		if err := r.preProcessFile(fpath); err != nil {
			return err
		}
	}
	for _, fpath := range filtered {
		if err := r.processFile(fpath); err != nil {
			return err
		}
	}
	return nil
}

func (r *Refactorer) preProcessFile(path string) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	fs := token.NewFileSet()
	f, err := parser.ParseFile(fs, path, data, parser.ParseComments)
	if err != nil {
		return err
	}
	for _, v := range f.Decls {
		switch v := v.(type) {
		case *ast.FuncDecl:
			if v.Recv == nil {
				r.defined[v.Name.Name] = struct{}{}
			}
		}
	}
	return nil
}

func (r *Refactorer) processFile(path string) error {
	r.fileChanged = false
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
	ast.Walk(r, f)
	if !r.fileChanged {
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

type Refactorer struct {
	fileChanged bool
	inDecl      string
	defined     map[string]struct{}
}

func (r *Refactorer) visitCCall(n *ast.CallExpr, fnc string) {
	if fnc == r.inDecl {
		return
	}
	if _, ok := r.defined[fnc]; ok {
		n.Fun = n.Fun.(*ast.SelectorExpr).Sel
		r.fileChanged = true
	}
}
func (r *Refactorer) visitFlagsCall(n *ast.CallExpr, fnc string) {
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
		r.fileChanged = true
		n.Args[0] = &ast.Ident{Name: noxflags.GameFlag(val).GoString()}
	}
}
func (r *Refactorer) visitCall(n *ast.CallExpr) {
	sel, ok := n.Fun.(*ast.SelectorExpr)
	if !ok {
		return
	}
	pkg, ok := sel.X.(*ast.Ident)
	if !ok {
		return
	}
	switch pkg.Name {
	case "C":
		r.visitCCall(n, sel.Sel.Name)
	case "noxflags":
		r.visitFlagsCall(n, sel.Sel.Name)
	}
}

func (r *Refactorer) Visit(n ast.Node) ast.Visitor {
	switch n := n.(type) {
	case *ast.FuncDecl:
		r.inDecl = n.Name.Name
	case *ast.CallExpr:
		r.visitCall(n)
	}
	return r
}
