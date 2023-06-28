package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"go/types"
	"strconv"
	"strings"

	"golang.org/x/tools/go/packages"
)

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

func int64lit(v int64) ast.Expr {
	return &ast.BasicLit{Kind: token.INT, Value: strconv.FormatInt(v, 10)}
}

func maybeParen(x ast.Expr) ast.Expr {
	switch x.(type) {
	case *ast.StarExpr, *ast.ArrayType, *ast.InterfaceType:
		return &ast.ParenExpr{X: x}
	}
	return x
}

func astType(pkg *packages.Package, t types.Type) ast.Expr {
	switch t := t.(type) {
	case *types.Named:
		obj := t.Obj()
		if obj.Pkg() == pkg.Types {
			return ast.NewIdent(obj.Name())
		}
		return &ast.SelectorExpr{X: ast.NewIdent(obj.Pkg().Name()), Sel: ast.NewIdent(obj.Name())}
	case *types.Basic:
		if t.Kind() == types.UnsafePointer {
			return &ast.SelectorExpr{X: ast.NewIdent("unsafe"), Sel: ast.NewIdent("Pointer")}
		}
		return ast.NewIdent(t.Name())
	case *types.Pointer:
		return &ast.StarExpr{X: astType(pkg, t.Elem())}
	case *types.Slice:
		return &ast.ArrayType{Elt: astType(pkg, t.Elem())}
	case *types.Array:
		return &ast.ArrayType{Len: int64lit(t.Len()), Elt: astType(pkg, t.Elem())}
	}
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
	return x
}
