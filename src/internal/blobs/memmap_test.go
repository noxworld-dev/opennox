package blobs

import (
	"sort"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestReadMemmap(t *testing.T) {
	SetPath("../../")
	m, err := ReadMemmap()
	require.NoError(t, err)
	const varCnt = 1396
	require.GreaterOrEqual(t, len(m.Vars), varCnt)
	err = m.Write()
	require.NoError(t, err)
	sort.Slice(m.Vars, func(i, j int) bool {
		return m.Vars[i].Size > m.Vars[j].Size && m.Vars[i].Off > 0
	})
	for _, v := range m.Vars[:10] {
		t.Logf("0x%X, %d [%d]", v.Blob, v.Off, v.Size)
	}
}
