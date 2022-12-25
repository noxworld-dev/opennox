package version

import (
	"testing"
)

func TestValid(t *testing.T) {
	if !semverIsValid(DefVersion) {
		t.Fatal("invalid version")
	}
}
