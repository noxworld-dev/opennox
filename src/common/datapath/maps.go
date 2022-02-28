package datapath

import (
	"path/filepath"

	"nox/v1/common"
)

// Maps returns the current Nox maps dir. If additional args are provided, they will joined with the maps dir.
func Maps(path ...string) string {
	const dir = common.MapsDir
	if len(path) == 0 {
		return Data(dir)
	}
	args := make([]string, 0, 2+len(path))
	args = append(args, getData(), dir)
	args = append(args, path...)
	return filepath.Join(args...)
}
