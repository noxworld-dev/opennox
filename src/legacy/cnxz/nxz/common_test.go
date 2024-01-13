package nxz

import (
	"crypto/sha1"
	"encoding/hex"
	"io"
	"testing"

	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/stretchr/testify/require"
)

func hashReader(t testing.TB, r io.Reader) (string, int) {
	h := sha1.New()
	n, err := io.Copy(h, r)
	require.NoError(t, err)
	return hex.EncodeToString(h.Sum(nil)), int(n)
}

func hashFile(t testing.TB, path string) (string, int) {
	f, err := ifs.Open(path)
	require.NoError(t, err)
	defer f.Close()
	return hashReader(t, f)
}
