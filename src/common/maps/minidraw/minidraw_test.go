package minidraw

import (
	"image/color"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/maps"
	"nox/v1/common/maps/maprender"
	"nox/v1/common/noxtest"
)

var casesMapDraw = []struct {
	Name string
	Hash string
}{
	{Name: "con01a", Hash: "11469d0c110930473dabf48ea4fc8f6f"},
	{Name: "estate", Hash: "b7e908a904505702ddb624aaf464d4ca"},
	{Name: "g_castle", Hash: "5a722f929db128f1ca954a100992762f"},
	{Name: "g_mines", Hash: "9fe78e456bca7212354293f39d1178b4"},
	{Name: "so_brin", Hash: "75e19ed8717a5bf5ab6c2eca49d4341e"},
}

func TestDraw(t *testing.T) {
	r, err := maprender.NewRenderer(noxtest.DataPath(t))
	require.NoError(t, err)
	defer r.Close()
	path := noxtest.DataPath(t, maps.Dir)
	for _, m := range casesMapDraw {
		t.Run(m.Name, func(t *testing.T) {
			mp, err := maps.ReadMap(filepath.Join(path, m.Name))
			require.NoError(t, err)
			img := MinimapRGBA(mp, color.Black)
			noxtest.WritePNG(t, m.Name+".png", img, m.Hash)
		})
	}
}
