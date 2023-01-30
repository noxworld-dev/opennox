package main

import (
	"bytes"
	"fmt"
	"go/ast"
	"go/format"
	"go/printer"
	"go/token"
	"os"
	"unicode"
)

func asExportedName(s string) string {
	return string(unicode.ToUpper(rune(s[0]))) + s[1:]
}

func writeAST(path string, fs *token.FileSet, file *ast.File) error {
	var buf bytes.Buffer
	err := format.Node(&buf, fs, file)
	if err != nil {
		buf.Reset()
		printer.Fprint(&buf, fs, file)
		_ = os.WriteFile(path, buf.Bytes(), 0644)
		return fmt.Errorf("%s: %w", path, err)
	}
	return os.WriteFile(path, buf.Bytes(), 0644)
}

func isC(x ast.Expr) (*ast.Ident, bool) {
	sel, ok := x.(*ast.SelectorExpr)
	if !ok {
		return nil, false
	}
	if p, ok := sel.X.(*ast.Ident); !ok || p.Name != "C" {
		return nil, false
	}
	return sel.Sel, true
}
