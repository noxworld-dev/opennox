package noxfont

import (
	"bytes"
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/datapath"
)

func TestFonts(t *testing.T) {
	path := datapath.Path()
	if _, err := os.Stat(filepath.Join(path, DefaultName+Ext)); os.IsNotExist(err) {
		t.Skip("no Nox installation detected")
	}
	for _, name := range []string{
		DefaultName, LargeName, SmallName, NumbersName,
	} {
		t.Run(name, func(t *testing.T) {
			path := filepath.Join(path, name+Ext)
			data, err := os.ReadFile(path)
			require.NoError(t, err)
			fnt, err := Decode(bytes.NewReader(data))
			require.NoError(t, err)
			got, err := fnt.Encode()
			require.NoError(t, err)
			require.Equal(t, data, got)
		})
	}
}
