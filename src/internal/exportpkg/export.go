package main

import (
	"go/ast"
	"go/parser"
	"go/token"
	"log"
	"os"
	"strings"
)

func exportProcessFile(path, epath string) error {
	if _, err := os.Stat(epath); err == nil {
		log.Println("skipping file (already exported):", path)
		return nil
	}
	fs := token.NewFileSet()
	f, err := os.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()
	file, err := parser.ParseFile(fs, path, f, parser.ParseComments|parser.SkipObjectResolution)
	if err != nil {
		return err
	}
	return exportProcessAST(path, epath, fs, file)
}

func exportProcessAST(path, epath string, fs *token.FileSet, file *ast.File) error {
	var (
		imports []ast.Decl
		vars    = &ast.GenDecl{
			Tok:    token.VAR,
			Lparen: 1,
		}
		export []ast.Decl
	)
	file.Imports = nil
	for i := 0; i < len(file.Decls); i++ {
		d := file.Decls[i]
		switch d := d.(type) {
		case *ast.GenDecl:
			switch d.Tok {
			case token.IMPORT:
				if len(d.Specs) != 1 {
					continue
				}
				sp := d.Specs[0].(*ast.ImportSpec)
				if sp.Path.Value != `"C"` {
					continue
				}
				if d.Doc != nil {
					for i, c := range file.Comments {
						if c == d.Doc {
							file.Comments = append(file.Comments[:i], file.Comments[i+1:]...)
							break
						}
					}
				}
				imports = append(imports, d)
				file.Decls = append(file.Decls[:i], file.Decls[i+1:]...)
				i--
			}
		case *ast.FuncDecl:
			if d.Doc == nil || len(d.Doc.List) == 0 {
				continue
			}
			if !strings.HasPrefix(d.Doc.List[0].Text, "//export") {
				continue
			}
			docs := d.Doc.List
			d.Doc.List = d.Doc.List[1:]
			log.Println("exported:", d.Name.Name)
			ret := d.Type.Results != nil && len(d.Type.Results.List) != 0
			vname := d.Name.Name
			vname = asExportedName(vname)
			var body []ast.Stmt
			expr := &ast.CallExpr{Fun: ast.NewIdent(vname)}
			for _, a := range d.Type.Params.List {
				for _, name := range a.Names {
					expr.Args = append(expr.Args, name)
				}
			}
			if ret {
				body = append(body, &ast.ReturnStmt{Results: []ast.Expr{expr}})
			} else {
				body = append(body, &ast.ExprStmt{X: expr})
			}
			vars.Specs = append(vars.Specs, &ast.ValueSpec{
				Names: []*ast.Ident{ast.NewIdent(vname)},
				Type:  d.Type,
			})
			export = append(export, &ast.FuncDecl{
				Name: d.Name,
				Doc:  &ast.CommentGroup{List: docs},
				Type: d.Type,
				Body: &ast.BlockStmt{List: body},
			})
		}
	}
	var decls []ast.Decl
	decls = append(decls, imports...)
	if len(vars.Specs) != 0 {
		decls = append(decls, vars)
	}
	decls = append(decls, export...)
	if len(decls) == 0 {
		return nil
	}

	log.Println(path, "->", epath)
	if err := writeAST(epath, fs, &ast.File{
		Name:  ast.NewIdent("legacy"),
		Decls: decls,
	}); err != nil {
		return err
	}
	if err := writeAST(path, fs, file); err != nil {
		return err
	}
	return nil
}
