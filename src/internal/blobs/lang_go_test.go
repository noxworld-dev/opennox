package blobs

import (
	"go/token"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestBlobAccessesGo(t *testing.T) {
	fs := token.NewFileSet()
	const file = `
package main

func foo() {
	memmap.PtrUint16(0x1234, 5678)
	memmap.PtrPtr(0x1234, 5678 + 2)
	memmap.Int32(0x587000, 8*uintptr(v12)+192088)
}
`
	list, err := BlobAccessesGo(fs, "test.go", []byte(file))
	require.NoError(t, err)
	require.Len(t, list, 3)

	resolveString := func(pos []token.Pos) string {
		require.NotEmpty(t, pos)
		return resolveTokString(fs, []byte(file), pos)
	}

	a := list[0]
	require.Equal(t, "memmap.PtrUint16(0x1234, 5678)", a.Expr.Val)
	require.Equal(t, "memmap.PtrUint16", a.Name.Val)
	require.Equal(t, uintptr(0x1234), a.Blob.Val)
	require.Equal(t, uintptr(5678), a.Off.Val)
	require.Equal(t, "", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "memmap.PtrUint16", resolveString(a.Name.Pos))
	require.Equal(t, "0x1234", resolveString(a.Blob.Pos))
	require.Equal(t, "5678", resolveString(a.Off.Pos))
	require.Nil(t, a.Index.Pos)

	a = list[1]
	require.Equal(t, "memmap.PtrPtr(0x1234, 5678 + 2)", a.Expr.Val)
	require.Equal(t, "memmap.PtrPtr", a.Name.Val)
	require.Equal(t, uintptr(0x1234), a.Blob.Val)
	require.Equal(t, uintptr(5680), a.Off.Val)
	require.Equal(t, "", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "memmap.PtrPtr", resolveString(a.Name.Pos))
	require.Equal(t, "0x1234", resolveString(a.Blob.Pos))
	require.Nil(t, a.Off.Pos)
	require.Nil(t, a.Index.Pos)

	a = list[2]
	require.Equal(t, "memmap.Int32(0x587000, 8*uintptr(v12)+192088)", a.Expr.Val)
	require.Equal(t, "memmap.Int32", a.Name.Val)
	require.Equal(t, uintptr(0x587000), a.Blob.Val)
	require.Equal(t, uintptr(192088), a.Off.Val)
	require.Equal(t, "8*uintptr(v12)", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "memmap.Int32", resolveString(a.Name.Pos))
	require.Equal(t, "0x587000", resolveString(a.Blob.Pos))
	require.Equal(t, "192088", resolveString(a.Off.Pos))
	require.Equal(t, "8*uintptr(v12)", resolveString(a.Index.Pos))
}
