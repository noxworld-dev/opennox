package noxtest

import (
	"testing"

	"nox/v1/common/datapath"
)

func DataPath(t testing.TB, sub ...string) string {
	path := datapath.Path(sub...)
	if path == "" {
		t.Skip("cannot detect Nox path and NOX_DATA is not set")
	}
	return path
}
