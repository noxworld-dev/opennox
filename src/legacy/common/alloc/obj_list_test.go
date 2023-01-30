package alloc

import (
	"testing"
	"unsafe"

	"github.com/stretchr/testify/require"
)

func TestClassStatic(t *testing.T) {
	const cnt = 3
	al := NewClass("Test", 4, cnt)
	require.Equal(t, cnt, al.static.Count())
	require.Equal(t, 0, al.active.Count())
	require.Equal(t, 0, al.dynamic.Count())

	var ptrs []unsafe.Pointer
	for i := 1; i <= cnt; i++ {
		p := al.NewObject()
		require.NotNil(t, p)
		ptrs = append(ptrs, p)
		require.Equal(t, cnt-i, al.static.Count())
		require.Equal(t, i, al.active.Count())
		require.Equal(t, 0, al.dynamic.Count())
	}

	p := al.NewObject()
	require.Zero(t, p)
	require.Equal(t, 0, al.static.Count())
	require.Equal(t, cnt, al.active.Count())
	require.Equal(t, 0, al.dynamic.Count())

	al.FreeObjectFirst(ptrs[len(ptrs)-1])
	ptrs = ptrs[:len(ptrs)-1]
	require.Equal(t, 1, al.static.Count())
	require.Equal(t, cnt-1, al.active.Count())
	require.Equal(t, 0, al.dynamic.Count())

	al.FreeAllObjects()
	require.Equal(t, cnt, al.static.Count())
	require.Equal(t, 0, al.active.Count())
	require.Equal(t, 0, al.dynamic.Count())
	ptrs = nil

	for i := 1; i <= cnt; i++ {
		p := al.NewObject()
		require.NotNil(t, p)
		ptrs = append(ptrs, p)
		require.Equal(t, cnt-i, al.static.Count())
		require.Equal(t, i, al.active.Count())
		require.Equal(t, 0, al.dynamic.Count())
	}

	for i := range ptrs {
		if i%2 == 0 {
			al.FreeObjectFirst(ptrs[i])
		} else {
			al.FreeObjectLast(ptrs[i])
		}
		require.Equal(t, i+1, al.static.Count())
		require.Equal(t, cnt-(i+1), al.active.Count())
		require.Equal(t, 0, al.dynamic.Count())
	}
	ptrs = nil
}
