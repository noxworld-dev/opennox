package datapath

import "nox/v1/common/log"

var originLog = log.New("origin")

// originPaths returns possible path of Origin Nox installation.
func originPaths() []string {
	out := tryPaths([]string{
		`Program Files (x86)\Origin Games\Nox`,
		`Program Files\Origin Games\Nox`,
	})
	for _, path := range out {
		originLog.Printf("potential install path: %q", path)
	}
	return out
}
