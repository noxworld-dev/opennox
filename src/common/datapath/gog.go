package datapath

import (
	"nox/v1/common/log"
)

var gogLog = log.New("gog")

// gogPaths returns possible path of GoG Nox installation.
func gogPaths() []string {
	out := tryPaths([]string{
		// new paths
		`GOG Games\Nox`,
		`Games\GOG.com\Nox`,
		// some legacy ones, just in case
		`Program Files (x86)\GOG.com\Nox`,
		`Program Files\GOG.com\Nox`,
		`Program Files (x86)\GOGcom\Nox`,
		`Program Files\GOGcom\Nox`,
	})
	for _, path := range out {
		gogLog.Printf("potential install path: %q", path)
	}
	return out
}
