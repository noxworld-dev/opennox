package blobs

import "sort"

type Span struct {
	Off  uintptr
	Size uintptr
	Used bool
}

// BlobSpans finds access spans in a given blob. This helps find contiguous used/unused regions of the blob.
func BlobSpans(blob uintptr) ([]Span, error) {
	var acc []Span
	err := RewriteAccess(func(a *Access) (bool, error) {
		if a.Blob.Val == blob {
			// TODO: identify sizes correctly
			acc = append(acc, Span{
				Off:  a.Off.Val,
				Size: 4,
				Used: true,
			})
		}
		return false, nil // don't rewrite
	})
	if err != nil {
		return nil, err
	}
	sort.Slice(acc, func(i, j int) bool {
		return acc[i].Off < acc[j].Off
	})
	var out []Span
	if len(acc) != 0 && acc[0].Off != 0 {
		out = append(out, Span{Size: acc[0].Off, Used: false})
	}
	for _, s := range acc {
		if len(out) == 0 {
			out = append(out, s)
			continue
		}
		last := &out[len(out)-1]
		end := last.Off + last.Size
		if end <= s.Off { // gap or adjacent
			if end < s.Off {
				out = append(out, Span{Off: end, Size: s.Off - end, Used: false})
			}
			out = append(out, s)
			continue
		}
		if s.Off+s.Size <= end {
			continue // is contained inside
		}
		// merge sizes
		last.Size += s.Size - (end - s.Off)
	}
	// TODO: trailing blob part
	return out, nil
}
