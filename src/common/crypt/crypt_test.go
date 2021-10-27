package crypt

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestEncode(t *testing.T) {
	const (
		key     = ThingBin
		encoded = "\x2c\xc3\x70\x31\x5e\xda\x12\x3c"
		decoded = "ROLF\x01\x00\x00\x00"
	)

	buf := []byte(encoded)
	err := Decode(buf, key)
	require.NoError(t, err)
	require.Equal(t, decoded, string(buf))

	err = Encode(buf, key)
	require.NoError(t, err)
	require.Equal(t, encoded, string(buf))
}
