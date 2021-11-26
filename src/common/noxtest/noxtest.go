package noxtest

import (
	"crypto/md5"
	"encoding/hex"
	"image"
	"image/png"
	"io"
	"os"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/datapath"
)

func DataPath(t testing.TB, sub ...string) string {
	path := datapath.Path(sub...)
	if path == "" {
		t.Skip("cannot detect Nox path and NOX_DATA is not set")
	}
	return path
}

func WritePNG(t testing.TB, path string, img image.Image, exp string) {
	f, err := os.Create(path)
	require.NoError(t, err)
	defer f.Close()
	h := md5.New()
	err = png.Encode(io.MultiWriter(f, h), img)
	require.NoError(t, err)
	got := hex.EncodeToString(h.Sum(nil))
	if exp != "" {
		require.Equal(t, exp, got)
	} else {
		t.Logf("%s: %s", path, got)
	}
}
