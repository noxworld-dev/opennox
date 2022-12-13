package cryptfile

import (
	"hash/crc32"
	"math"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestCRCUpdate(t *testing.T) {
	data := make([]byte, 256)
	for i := range data {
		data[i] = byte(i)
	}
	crc := crcUpdate(math.MaxUint32, data)
	scrc := crc32.Update(0, crcTable, data)
	require.Equal(t, crc, scrc)
}
