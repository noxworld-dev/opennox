package main

import (
	"testing"
)

func TestNoxFactor(t *testing.T) {
	if err := run("../../"); err != nil {
		t.Fatal(err)
	}
}
