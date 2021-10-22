package crypt

import (
	"io"
	"io/ioutil"
	"strings"
	"testing"
)

func TestReader(t *testing.T) {
	const (
		key     = ThingBin
		encoded = "\x2c\xc3\x70\x31\x5e\xda\x12\x3c\x49\x28\x27\x6d\x9a\x62\x8e\x94\x95\x36\x9f\xa2\x0d\xd0\x04\xee"
		decoded = "ROLF\x01\x00\x00\x00\x03\x4d\x75\x64\x3e\x20\x03\x00\x08\x00\x00\x00\x00\x00\x00\x00"
	)

	r, err := NewReader(strings.NewReader(encoded), key)
	if err != nil {
		t.Fatal(err)
	}
	out, err := ioutil.ReadAll(r)
	if err != nil {
		t.Fatal(err)
	} else if string(out) != decoded {
		t.Fatalf("unexpected data: %q (%x)", out, out)
	}

	for i := 1; i < len(encoded); i++ {
		r, err = NewReader(strings.NewReader(encoded), key)
		if err != nil {
			t.Fatal(err)
		}
		_, err = r.Seek(int64(i), io.SeekCurrent)
		if err != nil {
			t.Fatal(err)
		}
		out, err = ioutil.ReadAll(r)
		if err != nil {
			t.Fatal(err)
		} else if string(out) != decoded[i:] {
			t.Fatalf("unexpected data: %q (%x)", out, out)
		}
	}
}
