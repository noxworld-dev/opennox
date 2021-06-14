package datapath

import (
	"path/filepath"

	"nox/v1/common/fs"
)

func tryPaths(paths []string) []string {
	var out []string
	for _, pref := range pathPrefixes() {
		for _, path := range paths {
			fpath := filepath.Join(pref, path)
			if _, err := fs.Stat(fpath); err == nil {
				out = append(out, fpath)
			}
		}
	}
	return out
}
