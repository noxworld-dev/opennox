package blobs

import (
	"go/token"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestBlobAccessesC(t *testing.T) {
	fs := token.NewFileSet()
	const file = `
#include "test.h"
#include <lib.h>

void foo() {
	getMemAt(0x1234, 5678)
	getMemI16Ptr ( 0x1234 , 5678 - 2 - (i + 2*a));
	getMemFloatPtr(0x1234, 5678 - 2 - (int) (i + 2*a))
	*getMemU32Ptr(0x587000, 8 * dr->field_74_2 + 179884);
	getMemAt(0x5D4594, i + 2701180 + v1)
	getMemU8Ptr( 0x5D4594, v47++ + 1212324)
}
`
	list, err := BlobAccessesC(fs, "test.c", []byte(file))
	require.NoError(t, err)
	require.Len(t, list, 6)

	resolveString := func(pos []token.Pos) string {
		require.NotEmpty(t, pos)
		return resolveTokString(fs, []byte(file), pos)
	}

	a := list[0]
	require.Equal(t, "getMemAt(0x1234, 5678)", a.Expr.Val)
	require.Equal(t, "getMemAt", a.Name.Val)
	require.Equal(t, uintptr(0x1234), a.Blob.Val)
	require.Equal(t, uintptr(5678), a.Off.Val)
	require.Equal(t, "", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "getMemAt", resolveString(a.Name.Pos))
	require.Equal(t, "0x1234", resolveString(a.Blob.Pos))
	require.Equal(t, " 5678", resolveString(a.Off.Pos))
	require.Nil(t, a.Index.Pos)
	require.Equal(t, "getMemAt(0x1234, 5678)", a.String())

	a = list[1]
	require.Equal(t, "getMemI16Ptr ( 0x1234 , 5678 - 2 - (i + 2*a))", a.Expr.Val)
	require.Equal(t, "getMemI16Ptr", a.Name.Val)
	require.Equal(t, uintptr(0x1234), a.Blob.Val)
	require.Equal(t, uintptr(5676), a.Off.Val)
	require.Equal(t, "- (i + 2*a)", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "getMemI16Ptr ", resolveString(a.Name.Pos))
	require.Equal(t, " 0x1234 ", resolveString(a.Blob.Pos))
	require.Nil(t, a.Off.Pos)
	require.Equal(t, "- (i + 2*a)", resolveString(a.Index.Pos))
	require.Equal(t, "getMemI16Ptr(0x1234, 5676 - (i + 2*a))", a.String())

	a = list[2]
	require.Equal(t, "getMemFloatPtr(0x1234, 5678 - 2 - (int) (i + 2*a))", a.Expr.Val)
	require.Equal(t, "getMemFloatPtr", a.Name.Val)
	require.Equal(t, uintptr(0x1234), a.Blob.Val)
	require.Equal(t, uintptr(5676), a.Off.Val)
	require.Equal(t, "- (int) (i + 2*a)", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "getMemFloatPtr", resolveString(a.Name.Pos))
	require.Equal(t, "0x1234", resolveString(a.Blob.Pos))
	require.Nil(t, a.Off.Pos)
	require.Equal(t, "- (int) (i + 2*a)", resolveString(a.Index.Pos))
	require.Equal(t, "getMemFloatPtr(0x1234, 5676 - (int) (i + 2*a))", a.String())

	a = list[3]
	require.Equal(t, "getMemU32Ptr(0x587000, 8 * dr->field_74_2 + 179884)", a.Expr.Val)
	require.Equal(t, "getMemU32Ptr", a.Name.Val)
	require.Equal(t, uintptr(0x587000), a.Blob.Val)
	require.Equal(t, uintptr(179884), a.Off.Val)
	require.Equal(t, "+ 8 * dr->field_74_2", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "getMemU32Ptr", resolveString(a.Name.Pos))
	require.Equal(t, "0x587000", resolveString(a.Blob.Pos))
	require.Equal(t, "+ 179884", resolveString(a.Off.Pos))
	require.Equal(t, " 8 * dr->field_74_2", resolveString(a.Index.Pos))
	require.Equal(t, "getMemU32Ptr(0x587000, 179884 + 8 * dr->field_74_2)", a.String())

	a = list[4]
	require.Equal(t, "getMemAt(0x5D4594, i + 2701180 + v1)", a.Expr.Val)
	require.Equal(t, "getMemAt", a.Name.Val)
	require.Equal(t, uintptr(0x5D4594), a.Blob.Val)
	require.Equal(t, uintptr(2701180), a.Off.Val)
	require.Equal(t, "+ i + v1", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "getMemAt", resolveString(a.Name.Pos))
	require.Equal(t, "0x5D4594", resolveString(a.Blob.Pos))
	require.Equal(t, "+ 2701180", resolveString(a.Off.Pos))
	require.Nil(t, a.Index.Pos)
	require.Equal(t, "getMemAt(0x5D4594, 2701180 + i + v1)", a.String())

	a = list[5]
	require.Equal(t, "getMemU8Ptr( 0x5D4594, v47++ + 1212324)", a.Expr.Val)
	require.Equal(t, "getMemU8Ptr", a.Name.Val)
	require.Equal(t, uintptr(0x5D4594), a.Blob.Val)
	require.Equal(t, uintptr(1212324), a.Off.Val)
	require.Equal(t, "+ v47++", a.Index.Val)
	require.Equal(t, a.Expr.Val, resolveString(a.Expr.Pos))
	require.Equal(t, "getMemU8Ptr", resolveString(a.Name.Pos))
	require.Equal(t, " 0x5D4594", resolveString(a.Blob.Pos))
	require.Equal(t, "+ 1212324", resolveString(a.Off.Pos))
	require.Equal(t, " v47++", resolveString(a.Index.Pos))
	require.Equal(t, "getMemU8Ptr(0x5D4594, 1212324 + v47++)", a.String())
}
