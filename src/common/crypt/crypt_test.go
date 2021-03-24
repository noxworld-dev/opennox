package crypt

import (
	"testing"
)

func keyEqual(t *testing.T, exp, got []uint32) {
	for i := range exp {
		if exp[i] != got[i] {
			t.Fatalf("%d: %08x != %08x", i, got[i], exp[i])
		}
	}
}

func TestKey7(t *testing.T) {
	e, err := newCoder(7, false)
	if err != nil {
		t.Fatal(err)
	}
	keyEqual(t, keyA7[:], e.keyA[:])
}

var keyA7 = keyA{
	2685602555,
	2224177424,
	3818581036,
	1597590766,
	303927664,
	3835289578,
	2664370356,
	2353741922,
	2165690199,
	3446265359,
	2487671745,
	3325016349,
	945526154,
	216152034,
	3995240103,
	3355199544,
	1756156406,
	1470639093,
}
