package blobs

import (
	"fmt"
	"go/token"
)

// SplitBlob takes a blob and splits it into two smaller ones. It will automatically rewrite all accesses to it.
// Is size is set to 0, the blob will be split by a given offset. If size is not zero, it will be removed as a gap.
func SplitBlob(blob, off, size uintptr) error {
	base := off + size
	bl, err := ReadBlobs()
	if err != nil {
		return err
	}

	// update old blob
	old := bl.Get(blob)
	if old == nil {
		return fmt.Errorf("old blob not found: 0x%X", blob)
	}
	osize := old.Size
	old.Size = off
	data := old.Data
	if data != nil {
		old.Data = data[:off]
		data = data[base:]
	}
	bl.Update(*old)

	// add new blob
	bl.Add(Blob{Blob: blob + base, Size: osize - base, Data: data})

	if err = bl.Write(); err != nil {
		return err
	}
	return RewriteAccess(func(a *Access) (bool, error) {
		if a.Blob.Val != blob || a.Off.Val < off {
			// different blob or the first half of the old one
			return false, nil
		}
		if size > 0 && a.Off.Val < base {
			return false, fmt.Errorf("one of the accesses is inside the gap: '%s'", a.Expr.Val)
		}
		// blob will have new base address
		a.Blob.Val += base
		a.Blob.Pos = nil
		// and a smaller offset
		a.Off.Val -= base
		a.Off.Pos = []token.Pos{0, 0} // must be non-nil to print correctly
		return true, nil
	})
}
