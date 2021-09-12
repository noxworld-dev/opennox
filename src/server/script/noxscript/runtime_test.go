package noxscript

import (
	"os"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestRuntime(t *testing.T) {
	const path = "test.obj"

	f, err := os.Open(path)
	require.NoError(t, err)
	defer f.Close()

	r, err := LoadScript(f)
	require.NoError(t, err)

	err = r.CallByName("Add", nil, nil, 1, 2)
	require.NoError(t, err)
	require.Equal(t, 3, r.PopInt())

	err = r.CallByName("Sub", nil, nil, 1, 2)
	require.NoError(t, err)
	require.Equal(t, -1, r.PopInt())

	err = r.CallByName("If", nil, nil, 1)
	require.NoError(t, err)
	require.Equal(t, 1, r.PopInt())

	err = r.CallByName("If", nil, nil, 2)
	require.NoError(t, err)
	require.Equal(t, 1, r.PopInt())

	err = r.CallByName("If", nil, nil, 0)
	require.NoError(t, err)
	require.Equal(t, 0, r.PopInt())

	err = r.CallByName("AddLocal", nil, nil, 1, 2)
	require.NoError(t, err)
	require.Equal(t, 4, r.PopInt())
	err = r.CallByName("AddLocal", nil, nil, 1, 2)
	require.NoError(t, err)
	require.Equal(t, 4, r.PopInt())

	err = r.CallByName("AddGlobal", nil, nil, 1, 2)
	require.NoError(t, err)
	require.Equal(t, 3, r.PopInt())
	err = r.CallByName("AddGlobal", nil, nil, 1, 2)
	require.NoError(t, err)
	require.Equal(t, 6, r.PopInt())

	err = r.CallByName("AddLocalArr", nil, nil, 1, 2)
	require.NoError(t, err)
	require.Equal(t, 3, r.PopInt())
	err = r.CallByName("AddLocalArrFail", nil, nil, 1, 2)
	require.Error(t, err)
}
