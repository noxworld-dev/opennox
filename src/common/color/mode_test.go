package noxcolor

import "testing"

func TestTransparent(t *testing.T) {
	c := ToRGBA5551(0, 0, 0, 0)
	if c != 0x8000 {
		t.Fatalf("%x", c)
	}
	v := ExtendColor16(c)
	if v != 0x80000000 {
		t.Fatalf("%x", v)
	}
}
