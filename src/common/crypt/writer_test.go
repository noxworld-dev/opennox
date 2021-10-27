package crypt

import (
	"bytes"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestWriter(t *testing.T) {
	const (
		key     = ThingBin
		encoded = "\x2c\xc3\x70\x31\x5e\xda\x12\x3c\x49\x28\x27\x6d\x9a\x62\x8e\x94\x95\x36\x9f\xa2\x0d\xd0\x04\xee"
		decoded = "ROLF\x01\x00\x00\x00\x03\x4d\x75\x64\x3e\x20\x03\x00\x08\x00\x00\x00\x00\x00\x00\x00"
	)

	buf := bytes.NewBuffer(nil)

	w, err := NewWriter(buf, key)
	require.NoError(t, err)
	_, err = w.Write([]byte(decoded))
	require.NoError(t, err)
	err = w.Close()
	require.NoError(t, err)
	require.Equal(t, encoded, string(buf.Bytes()))

	buf.Reset()
	w.Reset(buf)

	for _, b := range []byte(decoded) {
		_, err = w.Write([]byte{b})
		require.NoError(t, err)
	}
	err = w.Close()
	require.NoError(t, err)
	require.Equal(t, encoded, string(buf.Bytes()))
}
