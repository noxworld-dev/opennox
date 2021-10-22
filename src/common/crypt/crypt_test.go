package crypt

import "testing"

func TestEncode(t *testing.T) {
	const (
		key     = ThingBin
		encoded = "\x2c\xc3\x70\x31\x5e\xda\x12\x3c"
		decoded = "ROLF\x01\x00\x00\x00"
	)

	buf := []byte(encoded)
	err := Decode(buf, key)
	if err != nil {
		t.Fatal(err)
	} else if string(buf) != decoded {
		t.Fatalf("unexpected data: %q", buf)
	}

	err = Encode(buf, key)
	if err != nil {
		t.Fatal(err)
	} else if string(buf) != encoded {
		t.Fatalf("unexpected data: %q", buf)
	}
}
