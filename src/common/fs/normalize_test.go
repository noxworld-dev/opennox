//+build !windows

package fs

import (
	"io/ioutil"
	"os"
	"path/filepath"
	"strings"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestNormalize(t *testing.T) {
	dir, err := ioutil.TempDir("", "nox_fs_")
	require.NoError(t, err)
	defer os.RemoveAll(dir)

	dir1 := filepath.Join(dir, "AbC", "def")
	err = os.MkdirAll(dir1, 0755)
	require.NoError(t, err)
	file1 := filepath.Join(dir1, "File.txt")

	err = ioutil.WriteFile(file1, []byte("data"), 0644)
	require.NoError(t, err)

	require.Equal(t,
		file1,
		Normalize(strings.Join([]string{dir, "abc", "Def", "FILE.TXT"}, "\\")),
	)
	require.Equal(t,
		filepath.Join(dir1, "NotExistent"),
		Normalize(strings.Join([]string{dir, "ABC", "DeF", "NotExistent"}, "\\")),
	)
}
