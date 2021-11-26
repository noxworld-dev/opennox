package maprender

import (
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/maps"
	"nox/v1/common/noxtest"
)

var casesMapDraw = []struct {
	Name string
	Hash string
}{
	{Name: "con01a"},
	{Name: "estate", Hash: "1284f517d7fe08f8fef176006037b653"},
	{Name: "g_castle", Hash: "5c1a01f8169587e746a25673887fbf2a"},
	{Name: "g_mines"},
	{Name: "so_brin", Hash: "9c052f87e9f443c56716c333009d71c6"},
}

func TestDraw(t *testing.T) {
	r, err := NewRenderer(noxtest.DataPath(t))
	require.NoError(t, err)
	defer r.Close()
	path := noxtest.DataPath(t, maps.Dir)
	for _, m := range casesMapDraw {
		t.Run(m.Name, func(t *testing.T) {
			mp, err := maps.ReadMap(filepath.Join(path, m.Name))
			require.NoError(t, err)
			img, err := r.DrawMap(mp, nil)
			noxtest.WritePNG(t, m.Name+".png", img, m.Hash)
			require.NoError(t, err)
		})
	}
}

func BenchmarkDraw(b *testing.B) {
	b.ReportAllocs()
	r, err := NewRenderer(noxtest.DataPath(b))
	require.NoError(b, err)
	defer r.Close()
	path := noxtest.DataPath(b, maps.Dir)
	b.StopTimer()
	for _, m := range casesMapDraw {
		b.Run(m.Name, func(b *testing.B) {
			mp, err := maps.ReadMap(filepath.Join(path, m.Name))
			require.NoError(b, err)
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				_, _ = r.DrawMap(mp, nil)
			}
		})
	}
}
