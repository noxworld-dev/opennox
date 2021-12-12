package main

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestParseOffMult(t *testing.T) {
	cases := []struct {
		name string
		raw  string
		mult BlobOffMult
		none bool
	}{
		{
			name: "static",
			raw:  `10`,
			mult: BlobOffMult{
				Static: 10,
			},
		},
		{
			name: "static mult",
			raw:  `10*2*(1+1)`,
			mult: BlobOffMult{
				Static: 40,
			},
		},
		{
			name: "var mult",
			raw:  `10*i`,
			mult: BlobOffMult{
				Static: 10,
				Sum:    BlobOffSum{Raw: []string{"i"}},
			},
		},
		{
			name: "var sum mult",
			raw:  `10*(i+1)`,
			mult: BlobOffMult{
				Static: 10,
				Sum:    BlobOffSum{Static: 1, Raw: []string{"i"}},
			},
		},
		{
			name: "three mult",
			raw:  `10*i*j`,
			none: true,
		},
	}
	for _, c := range cases {
		t.Run(c.name, func(t *testing.T) {
			out, ok := parseOffMult([]byte(c.raw))
			if c.none {
				require.False(t, ok)
				return
			}
			require.True(t, ok)
			require.Equal(t, c.mult, out)
		})
	}
}

var alignCases = []struct {
	name   string
	before string
	after  string
	none   bool
	blob   uint
	base   uint
	elem   uint
	cnt    uint
}{
	{
		name:   "no match",
		before: `a = getMemPtr ( 0x1234, (int)(x + (y)));`,
		none:   true,
		blob:   0x4567, base: 0, elem: 4, cnt: 1,
	},
	{
		name:   "no base match",
		before: `a = getMemBytePtr(0x1a3a, 8);`,
		none:   true,
		blob:   0x1A3A, base: 1, elem: 4, cnt: 1,
	},
	{
		name:   "static",
		before: `a = getMemBytePtr(0x1a3a, 8);`,
		after:  `a = getMemBytePtr(0x1A3A, 6 + 2*1);`,
		blob:   0x1A3A, base: 6, elem: 2, cnt: 4,
	},
	{
		name:   "complex",
		before: `a = getMemBytePtr( 0x1a3A , 3+(int)(x + (y))+8);`,
		after:  `a = getMemBytePtr(0x1A3A, 6 + 2*2 + 1 + (int)(x + (y)));`,
		blob:   0x1A3A, base: 6, elem: 2, cnt: 4,
	},
	{
		name:   "complex 2",
		before: `getMemU8Ptr(0x1234, 100 + 8 + 12*(v5 + (v4 << 8)))`,
		after:  `getMemU8Ptr(0x1234, 100 + 8 + 12*(v5 + (v4 << 8)))`,
		blob:   0x1234, base: 100, elem: 1024, cnt: 1,
	},
	{
		name:   "nested",
		before: `a = getMemBytePtr(0x1A3A, 2+getMemBytePtr(0x1A3A, 9)+8);`,
		after:  `a = getMemBytePtr(0x1A3A, 6 + 2*2 + getMemBytePtr(0x1A3A, 6 + 2*1 + 1));`,
		blob:   0x1A3A, base: 6, elem: 2, cnt: 4,
	},
}

func TestOffsetAlign(t *testing.T) {
	for _, c := range alignCases {
		t.Run(c.name, func(t *testing.T) {
			got := offsetAlign([]byte(c.before), c.blob, c.base, c.elem, c.cnt)
			if c.none {
				require.Nil(t, got)
				return
			}
			exp := c.after
			if exp == "" {
				exp = c.before
			}
			require.Equal(t, exp, string(got))

			// make sure we get the same result, if applied twice
			got = offsetAlign(got, c.blob, c.base, c.elem, c.cnt)
			require.Equal(t, exp, string(got), "repeated align failed")
		})
	} /*
			const str = `
			a = getMemPtr ( 0x1234, (int)(x + (y)));
			a = getMemBytePtr( 0x1a3A , 3+(int)(x + (y))+8);
			a = getMemBytePtr(0x1a3a, 8);
			a = getMemBytePtr(0x1a3a, 6 + 2*1);
			a = getMemBytePtr(0x1a3a, 6 + 2*1 + 1);
			a = getMemBytePtr(0x1A3A, 2+getMemBytePtr(0x1A3A, 9)+8);
		`

			// existing offset
			out = offsetAlign([]byte(str), 0x1a3A, 6, 2, 4)
			require.Equal(t, `
			a = getMemPtr ( 0x1234, (int)(x + (y)));
			a = getMemBytePtr(0x1A3A, 6 + 2*2 + 1 + (int)(x + (y)));
			a = getMemBytePtr(0x1A3A, 6 + 2*1);
			a = getMemBytePtr(0x1A3A, 6 + 2*1);
			a = getMemBytePtr(0x1A3A, 6 + 2*1 + 1);
			a = getMemBytePtr(0x1A3A, 6 + 2*2 + getMemBytePtr(0x1A3A, 6 + 2*1 + 1));
		`, string(out))*/
}
