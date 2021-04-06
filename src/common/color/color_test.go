package noxcolor

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestRGB15(t *testing.T) {
	for i := 0; i < 0x7FFF; i++ {
		c := RGB15(i)
		cl := c.RGBA32()
		c2 := ToRGB15(cl.R, cl.G, cl.B)
		require.Equal(t, c, c2)
	}
}

func TestRGB16(t *testing.T) {
	for i := 0; i < 0xFFFF; i++ {
		c := RGB16(i)
		cl := c.RGBA32()
		c2 := ToRGB16(cl.R, cl.G, cl.B, cl.A)
		require.Equal(t, c, c2)
	}
}
