package console

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestDecodeSecretToken(t *testing.T) {
	got := EncodeSecret("racoiaws")
	require.Equal(t, "0YAKikQs", got)
}
