package blobs

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestReadBlobs(t *testing.T) {
	SetPath("../../")
	bl, err := ReadBlobs()
	require.NoError(t, err)
	const blobCnt = 3
	require.GreaterOrEqual(t, len(bl.data.blobs), blobCnt)
	require.GreaterOrEqual(t, len(bl.mapc.blobs1), blobCnt)
	require.GreaterOrEqual(t, len(bl.mapc.blobs2), blobCnt)
	require.GreaterOrEqual(t, len(bl.mapg1.blobs1), blobCnt)
	require.GreaterOrEqual(t, len(bl.mapg1.blobs2), blobCnt)
	require.GreaterOrEqual(t, len(bl.mapg2.blobs), blobCnt)
	err = bl.Write()
	require.NoError(t, err)
}
