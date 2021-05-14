package noxcolor

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestRGBA4444(t *testing.T) {
	for i := 0; i < 0xFFFF; i++ {
		c := RGBA4444(i)
		cl := c.RGBA32()
		c2 := ToRGBA4444(cl.R, cl.G, cl.B, cl.A)
		require.Equal(t, c, c2, "0x%x", int(c))
	}
}
