package noxtest

import (
	"os"
	"testing"
)

func DataPath(t testing.TB) string {
	path := os.Getenv("NOX_DATA")
	if path == "" {
		t.Skip("NOX_DATA is not set")
	}
	return path
}
