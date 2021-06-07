package blobs

import (
	"os"
	"strconv"
	"strings"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestSplitBlob(t *testing.T) {
	if os.Getenv("NOX_DO_SPLIT") == "" {
		t.SkipNow()
	}
	SetPath("../../")
	sub := strings.Split(os.Getenv("NOX_DO_SPLIT"), ",")
	blob, err := strconv.ParseUint(sub[0], 0, 64)
	require.NoError(t, err)
	off, err := strconv.ParseUint(sub[1], 0, 64)
	require.NoError(t, err)
	var size uint64
	if len(sub) > 2 {
		size, err = strconv.ParseUint(sub[2], 0, 64)
		require.NoError(t, err)
	}
	err = SplitBlob(uintptr(blob), uintptr(off), uintptr(size))
	require.NoError(t, err)
}
