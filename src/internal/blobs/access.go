package blobs

import (
	"fmt"
	"go/token"
	"strconv"
	"strings"
)

type AddrPos struct {
	// Val is the parsed value of the address.
	Val uintptr
	// Pos is the Val byte position in the source file.
	Pos []token.Pos
}

func (p *AddrPos) Zero() bool {
	return p == nil || (p.Val == 0 && p.Pos == nil)
}

type StringPos struct {
	// Val is the raw string value in the source file.
	Val string
	// Pos is the Val byte position in the source file.
	Pos []token.Pos
}

func (p *StringPos) Zero() bool {
	return p == nil || (p.Val == "" && p.Pos == nil)
}

// Access is the blob access in the source code.
type Access struct {
	// Name is the name of the blob access function used.
	Name StringPos

	// Blob is the base address of the blob.
	Blob AddrPos

	// Off is the static offset into the blob.
	Off AddrPos

	// Index is the rest of the expression that defines the offset into the blob.
	Index StringPos

	// Expr is the complete expression, as seen in the code. Used for replacement.
	Expr StringPos
}

func (a Access) String() string {
	if a.Name.Val == "" {
		panic("no name")
	}
	if a.Blob.Val == 0 {
		panic("no blob")
	}
	var val []string
	if a.Off.Val != 0 {
		val = append(val, strconv.FormatUint(uint64(a.Off.Val), 10))
	}
	if a.Index.Val != "" {
		v := strings.TrimSpace(a.Index.Val)
		if !strings.HasPrefix(v, "+") && !strings.HasPrefix(v, "-") {
			v = "+ " + v
		}
		val = append(val, v)
	}
	if len(val) == 0 {
		if a.Off.Pos == nil {
			panic("no offset: " + a.Expr.Val)
		}
		val = append(val, "0")
	}
	return fmt.Sprintf("%s(0x%X, %s)", a.Name.Val, a.Blob.Val, strings.Join(val, " "))
}
