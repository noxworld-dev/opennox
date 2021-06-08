package blobs

import (
	"go/ast"
	"go/parser"
	"go/token"
	"os/exec"
	"strconv"
)

// BlobAccessesGo finds all blob accesses in the Go file specified by file and data.
func BlobAccessesGo(fs *token.FileSet, name string, data []byte) ([]Access, error) {
	f, err := parser.ParseFile(fs, name, data, 0)
	if err != nil {
		return nil, err
	}
	vs := &blobAccessVisitor{fs: fs, file: data}
	ast.Walk(vs, f)
	return vs.list, vs.err
}

func nodePos(n ast.Node) []token.Pos {
	if n == nil {
		return nil
	}
	return []token.Pos{
		n.Pos(), n.End(),
	}
}

type blobAccessVisitor struct {
	fs   *token.FileSet
	file []byte
	list []Access
	err  error
}

func (vs *blobAccessVisitor) newString(n ast.Node) *StringPos {
	if n == nil {
		return nil
	}
	pos := nodePos(n)
	return vs.newStringFor(pos)
}

func (vs *blobAccessVisitor) newStringFor(pos []token.Pos) *StringPos {
	if pos == nil {
		return nil
	}
	return &StringPos{
		Val: vs.resolve(pos),
		Pos: pos,
	}
}

func resolveTokString(fs *token.FileSet, data []byte, pos []token.Pos) string {
	if len(pos) < 2 {
		return ""
	}
	si := fs.Position(pos[0])
	ei := fs.Position(pos[1])
	return string(data[si.Offset:ei.Offset])
}

func (vs *blobAccessVisitor) resolve(pos []token.Pos) string {
	return resolveTokString(vs.fs, vs.file, pos)
}

func (vs *blobAccessVisitor) Visit(n ast.Node) ast.Visitor {
	switch n := n.(type) {
	case *ast.CallExpr:
		if len(n.Args) != 2 {
			return vs
		}
		sel, ok := n.Fun.(*ast.SelectorExpr)
		if !ok {
			return vs
		}
		if id, ok := sel.X.(*ast.Ident); !ok || id.Name != "memmap" {
			return vs
		}
		blob, rest := vs.getStatic(n.Args[0])
		if blob.Zero() || !rest.Zero() {
			return vs
		}
		off, rest := vs.getStatic(n.Args[1])
		acc := Access{
			Name: *vs.newString(sel),
			Blob: *blob,
			Expr: *vs.newString(n),
		}
		if !off.Zero() {
			acc.Off = *off
		}
		if !rest.Zero() {
			acc.Index = *rest
		}
		vs.list = append(vs.list, acc)
	}
	return vs
}

func (vs *blobAccessVisitor) getStatic(n ast.Node) (*AddrPos, *StringPos) {
	if n == nil {
		return nil, nil
	}
	switch n := n.(type) {
	case *ast.BasicLit:
		if n.Kind != token.INT {
			return nil, vs.newString(n)
		}
		v, err := strconv.ParseUint(n.Value, 0, 64)
		if err != nil {
			return nil, vs.newString(n)
		}
		return &AddrPos{Val: uintptr(v), Pos: nodePos(n)}, nil
	case *ast.BinaryExpr:
		switch n.Op {
		case token.SUB:
			x, xr := vs.getStatic(n.X)
			if x.Zero() {
				// no positive static part, and we ignore negative
				return nil, vs.newString(n)
			}
			yp := nodePos(n.Y)
			yp[0] = n.OpPos // adjust offset for the "-"
			// have positive part, maybe with some additions
			if xr.Zero() {
				// nothing more from the positive side, so can use negative
				return x, vs.newStringFor(yp)
			}
			// have the rest from positive and negative
			// get the string of both and concatenate
			// we can't set position for this case, unfortunately
			xs := vs.resolve(xr.Pos)
			ys := vs.resolve(yp)
			return x, &StringPos{Val: xs + " " + ys}
		case token.ADD:
			x, xr := vs.getStatic(n.X)
			y, yr := vs.getStatic(n.Y)
			if x.Zero() && y.Zero() {
				// nothing interesting, keep original
				return nil, vs.newString(n)
			}
			var v *AddrPos
			if x.Zero() {
				v = y
			} else if y.Zero() {
				v = x
			} else {
				// merge the two, no position though
				v = &AddrPos{Val: x.Val + y.Val}
			}
			if xr.Zero() && yr.Zero() {
				return v, nil
			}
			var r *StringPos
			if xr.Zero() {
				r = yr
			} else if yr.Zero() {
				r = xr
			} else {
				// merge the two, no position though
				r = &StringPos{Val: xr.Val + yr.Val}
			}
			return v, r
		}
	}
	return nil, vs.newString(n)
}

func goFormat(path string) error {
	cmd := exec.Command("go", "fmt", path)
	cmd.Dir = Path()
	return cmd.Run()
}
