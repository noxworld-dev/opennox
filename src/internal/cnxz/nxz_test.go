package cnxz

import (
	"crypto/sha1"
	"encoding/hex"
	"io"
	"os"
	"path/filepath"
	"testing"

	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxtest"
	"github.com/stretchr/testify/require"
)

func TestDecompress(t *testing.T) {
	maps := noxtest.DataPath(t, "maps")
	files, err := os.ReadDir(maps)
	require.NoError(t, err)
	for _, fi := range files {
		mname := filepath.Join(maps, fi.Name(), fi.Name()+".map")
		zname := filepath.Join(maps, fi.Name(), fi.Name()+".nxz")
		if _, err = ifs.Stat(zname); err != nil {
			continue
		}
		t.Run(fi.Name(), func(t *testing.T) {
			mexp, mexpN := hashFile(t, mname)
			gotc, gotcN := decompressC(t, zname)
			require.Equal(t, mexpN, gotcN)
			require.Equal(t, mexp, gotc)
		})
	}
}

func TestCompress(t *testing.T) {
	maps := noxtest.DataPath(t, "maps")
	files, err := os.ReadDir(maps)
	require.NoError(t, err)
	for _, fi := range files {
		mname := filepath.Join(maps, fi.Name(), fi.Name()+".map")
		zname := filepath.Join(maps, fi.Name(), fi.Name()+".nxz")
		if _, err = ifs.Stat(zname); err != nil {
			continue
		}
		t.Run(fi.Name(), func(t *testing.T) {
			mexp, mexpN := hashFile(t, zname)
			gotc, gotcN := compressC(t, mname)
			require.Equal(t, mexpN, gotcN)
			require.Equal(t, mexp, gotc)
		})
	}
}

func decompressC(t testing.TB, path string) (string, int) {
	out, err := os.CreateTemp("", "nxzmap_*.map")
	require.NoError(t, err)
	defer func() {
		out.Close()
		_ = os.Remove(out.Name())
	}()
	err = DecompressFile(path, out.Name())
	require.NoError(t, err)
	return hashFile(t, out.Name())
}

func compressC(t testing.TB, path string) (string, int) {
	out, err := os.CreateTemp("", "nxzmap_*.nxz")
	require.NoError(t, err)
	defer func() {
		out.Close()
		_ = os.Remove(out.Name())
	}()
	err = CompressFile(path, out.Name())
	require.NoError(t, err)
	return hashFile(t, out.Name())
}

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
