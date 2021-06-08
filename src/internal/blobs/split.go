package blobs

import (
	"fmt"
	"go/token"
)

// SplitBlob takes a blob and splits it into two smaller ones. It will automatically rewrite all accesses to it.
// Is size is set to 0, the blob will be split by a given offset. If size is not zero, it will be removed as a gap.
func SplitBlob(blob, off, size uintptr) error {
	bl, err := ReadBlobs()
	if err != nil {
		return err
	}

	// update old blob
	old := bl.Get(blob)
	if old == nil {
		return fmt.Errorf("old blob not found: 0x%X", blob)
	}
	// calculate offset
	oldBlob := old.Blob
	oldSize := old.Size
	leftBlob := oldBlob
	leftSize := off
	gapOff := off
	gapBlob := oldBlob + gapOff
	rightOff := off + size
	rightBlob := oldBlob + rightOff
	rightSize := oldSize - rightOff

	old.Blob = leftBlob
	old.Size = leftSize
	data := old.Data
	if data != nil {
		old.Data = data[:leftSize]
		data = data[rightOff:]
		data = data[:rightSize]
	}
	bl.Update(*old)

	// add new blob
	if rightSize > 0 {
		bl.Add(Blob{Blob: rightBlob, Size: rightSize, Data: data})
	}

	if err = bl.Write(); err != nil {
		return err
	}

	m, err := ReadMemmap()
	if err != nil {
		return err
	}
	for i, v := range m.Vars {
		if v.Blob != blob {
			// different blob
			continue
		}
		varOff := v.Off
		varEnd := v.Off + v.Size
		if varOff < gapOff { // starts in the left blob
			if varEnd > gapOff { // crosses the gap
				return fmt.Errorf("one of the mappings is not aligned with the gap: 0x%x, %d", v.Blob, v.Off)
			}
			// completely in the left blob
			continue
		}
		p := &m.Vars[i]
		if varOff < rightOff { // starts in the gab
			if varEnd > rightOff { // crosses the gap
				return fmt.Errorf("one of the mappings is not aligned with the gap: 0x%x, %d", v.Blob, v.Off)
			}
			// completely in the gap
			p.Blob = gapBlob
			p.Off -= gapOff
		} else {
			// completely in the right blob
			p.Blob = rightBlob
			p.Off -= rightOff
		}
	}
	if err = m.Write(); err != nil {
		return err
	}

	return RewriteAccess(func(a *Access) (bool, error) {
		if a.Blob.Val != blob {
			// different blob
			return false, nil
		}
		varOff := a.Off.Val
		if varOff < gapOff {
			// starts in the left blob
			return false, nil
		}
		if varOff < rightOff { // starts in the gab
			return false, fmt.Errorf("one of the accesses is inside the gap: '%s'", a.Expr.Val)
		}
		// completely in the right blob
		a.Blob.Val = rightBlob
		a.Blob.Pos = nil
		// and a smaller offset
		a.Off.Val -= rightOff
		a.Off.Pos = []token.Pos{0, 0} // must be non-nil to print correctly
		return true, nil
	})
}
