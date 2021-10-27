package crypt

import (
	"io"
	"io/ioutil"
	"strings"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestReader(t *testing.T) {
	const (
		key     = ThingBin
		encoded = "\x2c\xc3\x70\x31\x5e\xda\x12\x3c\x49\x28\x27\x6d\x9a\x62\x8e\x94\x95\x36\x9f\xa2\x0d\xd0\x04\xee"
		decoded = "ROLF\x01\x00\x00\x00\x03\x4d\x75\x64\x3e\x20\x03\x00\x08\x00\x00\x00\x00\x00\x00\x00"
	)

	r, err := NewReader(strings.NewReader(encoded), key)
	require.NoError(t, err)
	out, err := ioutil.ReadAll(r)
	require.NoError(t, err)
	require.Equal(t, decoded, string(out))

	for i := 1; i < len(encoded); i++ {
		r, err = NewReader(strings.NewReader(encoded), key)
		require.NoError(t, err)
		_, err = r.Seek(int64(i), io.SeekCurrent)
		require.NoError(t, err)
		out, err = ioutil.ReadAll(r)
		require.NoError(t, err)
		require.Equal(t, decoded[i:], string(out))
	}
}
