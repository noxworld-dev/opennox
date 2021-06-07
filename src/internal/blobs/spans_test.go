package blobs

import (
	"sort"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestBlobSpans(t *testing.T) {
	SetPath("../../")
	spans, err := BlobSpans(0x5D4594)
	require.NoError(t, err)
	t.Logf("spans: %d", len(spans))
	var (
		free []Span
		used []Span
	)
	for _, s := range spans {
		if s.Used {
			used = append(used, s)
		} else {
			free = append(free, s)
		}
	}
	spans = nil
	sort.Slice(free, func(i, j int) bool {
		return free[i].Size > free[j].Size
	})
	sort.Slice(used, func(i, j int) bool {
		return used[i].Size > used[j].Size
	})
	if len(used) > 10 {
		used = used[:10]
	}
	if len(free) > 10 {
		free = free[:10]
	}
	t.Logf("used: %d", len(used))
	for _, s := range used {
		t.Logf("\t%d-%d [%d]", s.Off, s.Off+s.Size, s.Size)
	}
	t.Logf("free: %d", len(free))
	for _, s := range free {
		t.Logf("\t%d-%d [%d]", s.Off, s.Off+s.Size, s.Size)
	}
}
