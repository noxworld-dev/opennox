package noxcolor

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestRGBA5551(t *testing.T) {
	for i := 0; i < 0xFFFF; i++ {
		c := RGBA5551(i)
		cl := c.RGBA32()
		c2 := ToRGBA5551(cl.R, cl.G, cl.B, cl.A)
		require.Equal(t, c, c2, "0x%x", int(c))
	}
}
