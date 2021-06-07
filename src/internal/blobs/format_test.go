package blobs

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestFormatAccesses(t *testing.T) {
	SetPath("../../")
	err := FormatAccesses()
	require.NoError(t, err)
}
