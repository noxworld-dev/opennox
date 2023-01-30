package main

import (
	"fmt"
	"go/ast"
	"go/token"
	"log"
	"path/filepath"
	"strings"
	"unicode"

	"golang.org/x/tools/go/ast/astutil"
)

func runCCall() error {
	type File struct {
		Path    string
		AST     *ast.File
		Changed bool
	}
	fs := token.NewFileSet()
	srcs := make(map[string]*File)
	dsts := make(map[string]*File)
	if err := eachSrcAST(fs, func(path string, file *ast.File) error {
		srcs[filepath.Base(path)] = &File{Path: path, AST: file}
		return nil
	}); err != nil {
		return err
	}
	if err := eachDstAST(fs, func(path string, file *ast.File) error {
		dsts[filepath.Base(path)] = &File{Path: path, AST: file}
		return nil
	}); err != nil {
		return err
	}
	// Find all already defined imported C functions.
	// Collect getters and setters as well.
	cdefs := make(map[string]struct{})
	getters := make(map[string]ast.Expr)
	setters := make(map[string]ast.Expr)
	var importFncs []string
	for _, f := range dsts {
		for _, n := range f.AST.Decls {
			switch n := n.(type) {
			case *ast.FuncDecl:
				cdefs[n.Name.Name] = struct{}{}
				if strings.HasPrefix(n.Name.Name, "Get_") {
					name := n.Name.Name[4:]
					if typ := n.Type; (typ.Params == nil || len(typ.Params.List) == 0) && typ.Results != nil && len(typ.Results.List) == 1 {
						getters[name] = typ.Results.List[0].Type
					}
				} else if strings.HasPrefix(n.Name.Name, "Set_") {
					name := n.Name.Name[4:]
					if typ := n.Type; (typ.Results == nil || len(typ.Results.List) == 0) && typ.Params != nil && len(typ.Params.List) == 1 {
						setters[name] = typ.Params.List[0].Type
					}
				}
			case *ast.GenDecl:
				switch n.Tok {
				case token.VAR, token.CONST:
					for _, sp := range n.Specs {
						switch sp := sp.(type) {
						case *ast.ValueSpec:
							for _, name := range sp.Names {
								cdefs[name.Name] = struct{}{}
							}
							if len(sp.Names) == 1 {
								if _, ok := sp.Type.(*ast.FuncType); ok {
									importFncs = append(importFncs, sp.Names[0].Name)
								}
							}
						}
					}
				}
			}
		}
	}
	// Find all C calls and add missing definitions as needed.
	// Also consider assignments and other variable usages,
	added := make(map[string]struct{})
	const varsFile = "vardefs.go"
	varsF := dsts[varsFile]
	if varsF == nil {
		varsF = &File{
			Path: filepath.Join(*fDir, "legacy", varsFile),
			AST: &ast.File{
				Name: ast.NewIdent("legacy"),
				Decls: []ast.Decl{
					&ast.GenDecl{Tok: token.IMPORT, Specs: []ast.Spec{
						&ast.ImportSpec{Path: &ast.BasicLit{
							Kind: token.STRING, Value: `"C"`,
						}},
					}},
				},
			},
		}
		dsts[varsFile] = varsF
	}
	expG := srcs["legacy_exports.go"]
	var expGBody *ast.BlockStmt
	expGDone := make(map[string]struct{})
	for _, d := range expG.AST.Decls {
		switch d := d.(type) {
		case *ast.FuncDecl:
			if d.Name.Name == "init" {
				expGBody = d.Body
			}
		}
	}
	varGetter := func(name string) ast.Expr {
		x := &ast.CallExpr{Fun: ast.NewIdent("legacy.Get_" + name)}
		if _, ok := getters[name]; ok {
			return x
		}
		typ := ast.NewIdent("int")
		getters[name] = typ
		varsF.Changed = true
		varsF.AST.Decls = append(varsF.AST.Decls, &ast.FuncDecl{
			Name: ast.NewIdent("Get_" + name),
			Type: &ast.FuncType{
				Params: &ast.FieldList{},
				Results: &ast.FieldList{List: []*ast.Field{{
					Type: typ,
				}}},
			},
			Body: &ast.BlockStmt{List: []ast.Stmt{
				&ast.ReturnStmt{Results: []ast.Expr{
					&ast.CallExpr{Fun: typ, Args: []ast.Expr{
						&ast.SelectorExpr{X: ast.NewIdent("C"), Sel: ast.NewIdent(name)},
					}},
				}},
			}},
		})
		return x
	}
	varSetter := func(name string, v ast.Expr) ast.Expr {
		x := &ast.CallExpr{Fun: ast.NewIdent("legacy.Set_" + name), Args: []ast.Expr{v}}
		if _, ok := setters[name]; ok {
			return x
		}
		var typ ast.Expr = ast.NewIdent("int")
		if gtyp, ok := getters[name]; ok {
			typ = gtyp
		}
		setters[name] = typ
		varsF.Changed = true
		varsF.AST.Decls = append(varsF.AST.Decls, &ast.FuncDecl{
			Name: ast.NewIdent("Set_" + name),
			Type: &ast.FuncType{
				Params: &ast.FieldList{
					List: []*ast.Field{
						{Names: []*ast.Ident{ast.NewIdent("v")}, Type: typ},
					},
				},
			},
			Body: &ast.BlockStmt{List: []ast.Stmt{
				&ast.AssignStmt{
					Lhs: []ast.Expr{
						&ast.SelectorExpr{X: ast.NewIdent("C"), Sel: ast.NewIdent(name)},
					},
					Tok: token.ASSIGN,
					Rhs: []ast.Expr{ast.NewIdent("v")},
				},
			}},
		})
		return x
	}
	for key, f := range srcs {
		f2 := dsts[key]
		varSeen := make(map[ast.Expr]struct{})
		f.AST = astutil.Apply(f.AST, func(c *astutil.Cursor) bool {
			switch n := c.Node().(type) {
			case *ast.StarExpr:
				varSeen[n.X] = struct{}{}
				return true
			case *ast.CompositeLit:
				varSeen[n.Type] = struct{}{}
				return true
			case *ast.ArrayType:
				// prevent it from being picked up by read code path
				return false
			case *ast.SelectorExpr:
				vr, ok := isC(n)
				if !ok {
					return true
				}
				if _, ok := varSeen[n]; ok {
					return true
				}
				f.Changed = true
				c.Replace(varGetter(vr.Name))
				return true
			case *ast.IncDecStmt:
				// prevent it from being picked up by read code path
				return false
			case *ast.AssignStmt:
				for _, x := range n.Lhs {
					varSeen[x] = struct{}{}
				}
				if len(n.Lhs) == 1 && n.Tok == token.ASSIGN {
					if vname, ok := isC(n.Lhs[0]); ok {
						f.Changed = true
						c.Replace(&ast.ExprStmt{X: varSetter(vname.Name, n.Rhs[0])})
						return false
					}
					if sel, ok := n.Lhs[0].(*ast.SelectorExpr); ok {
						if pkg, ok := sel.X.(*ast.Ident); ok && pkg.Name == "legacy" {
							expGDone[sel.Sel.Name] = struct{}{}
						}
					}
				}
				return true
			case *ast.ValueSpec:
				varSeen[n.Type] = struct{}{}
				return true
			case *ast.CallExpr:
				fname, ok := isC(n.Fun)
				if !ok {
					return true
				}
				// prevent it from being picked up by read code path
				varSeen[n.Fun] = struct{}{}
				name := fname.Name
				switch name {
				case "int", "uint", "bool", "short", "ushort", "char", "uchar", "float", "double":
					return true
				}
				lname := asExportedName(name)
				if _, ok = cdefs[lname]; ok {
					return true // already defined
				}
				// Rewrite function call
				f.Changed = true
				n.Fun = &ast.SelectorExpr{X: ast.NewIdent("legacy"), Sel: ast.NewIdent(lname)}
				var (
					params []*ast.Field
					args   []ast.Expr
				)
				for i := 0; i < len(n.Args); i++ {
					aname := fmt.Sprintf("a%d", i+1)
					a, typ, wrap := ccallInferType(n.Args[i])
					n.Args[i] = a
					params = append(params, &ast.Field{
						Names: []*ast.Ident{ast.NewIdent(aname)},
						Type:  typ,
					})
					var x ast.Expr = ast.NewIdent(aname)
					if wrap != nil {
						x = wrap(x)
					}
					args = append(args, x)
				}
				if _, ok := added[name]; ok {
					return true // already defined
				}
				// Generate function declaration
				added[name] = struct{}{}
				f2.Changed = true
				f2.AST.Decls = append(f2.AST.Decls, &ast.FuncDecl{
					Name: ast.NewIdent(lname),
					Type: &ast.FuncType{Params: &ast.FieldList{List: params}},
					Body: &ast.BlockStmt{List: []ast.Stmt{
						&ast.ExprStmt{X: &ast.CallExpr{
							Fun:  &ast.SelectorExpr{X: ast.NewIdent("C"), Sel: ast.NewIdent(name)},
							Args: args,
						}},
					}},
				})
			}
			return true
		}, nil).(*ast.File)
	}
	for _, name := range importFncs {
		if _, ok := expGDone[name]; ok {
			continue
		}
		expGBody.List = append(expGBody.List, &ast.AssignStmt{
			Lhs: []ast.Expr{&ast.SelectorExpr{
				X: ast.NewIdent("legacy"), Sel: ast.NewIdent(name),
			}},
			Tok: token.ASSIGN,
			Rhs: []ast.Expr{
				ast.NewIdent(string(unicode.ToLower(rune(name[0]))) + name[1:]),
			},
		})
		expG.Changed = true
	}
	for _, f := range dsts {
		if f.Changed {
			log.Println("changed:", f.Path)
			if err := writeAST(f.Path, fs, f.AST); err != nil {
				return err
			}
		}
	}
	for _, f := range srcs {
		if f.Changed {
			log.Println("changed:", f.Path)
			if err := writeAST(f.Path, fs, f.AST); err != nil {
				return err
			}
		}
	}
	return nil
}

func ccallInferType(a ast.Expr) (ast.Expr, ast.Expr, func(e ast.Expr) ast.Expr) {
	def := ast.NewIdent("fixme")
	switch a := a.(type) {
	case *ast.BasicLit:
		switch a.Kind {
		case token.INT:
			return a, ast.NewIdent("int"), func(e ast.Expr) ast.Expr {
				return &ast.CallExpr{Fun: ast.NewIdent("C.int"), Args: []ast.Expr{e}}
			}
		case token.STRING:
			return a, ast.NewIdent("string"), func(e ast.Expr) ast.Expr {
				return &ast.CallExpr{Fun: ast.NewIdent("internCStr"), Args: []ast.Expr{e}}
			}
		}
	case *ast.Ident:
		switch a.Name {
		case "nil":
			return a, ast.NewIdent("unsafe.Pointer"), nil
		case "true", "false":
			return a, ast.NewIdent("bool"), nil
		}
	case *ast.CallExpr:
		switch fnc := a.Fun.(type) {
		case *ast.Ident:
			switch fnc.Name {
			case "int", "uint", "int32", "uint32", "int16", "uint16", "int8", "uint8", "byte",
				"float32", "float64", "string":
				return a.Args[0], ast.NewIdent(fnc.Name), nil
			case "internCStr", "internWStr":
				return a.Args[0], ast.NewIdent("string"), func(e ast.Expr) ast.Expr {
					return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
				}
			}
		case *ast.SelectorExpr:
			c, ok := fnc.X.(*ast.Ident)
			if !ok {
				return a, def, nil
			}
			switch c.Name {
			case "unsafe":
				return a, &ast.SelectorExpr{X: ast.NewIdent("unsafe"), Sel: ast.NewIdent("Pointer")}, nil
			case "C":
				switch fnc.Sel.Name {
				case "int":
					return a.Args[0], ast.NewIdent("int"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				case "uint":
					return a.Args[0], ast.NewIdent("uint"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				case "short":
					return a.Args[0], ast.NewIdent("int16"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				case "ushort":
					return a.Args[0], ast.NewIdent("uint16"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				case "char":
					return a.Args[0], ast.NewIdent("int8"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				case "uchar":
					return a.Args[0], ast.NewIdent("uint8"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				case "float":
					return a.Args[0], ast.NewIdent("float32"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				case "double":
					return a.Args[0], ast.NewIdent("float64"), func(e ast.Expr) ast.Expr {
						return &ast.CallExpr{Fun: fnc, Args: []ast.Expr{e}}
					}
				}
			}
		}
	}
	return a, def, nil
}
