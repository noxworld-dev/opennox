//+build !windows

package datapath

import (
	"os"
	"path/filepath"
)

func registryPaths() []string {
	return nil // no registry
}

func pathPrefixes() []string {
	home, err := os.UserHomeDir()
	if err != nil {
		return nil
	}
	return []string{
		filepath.Join(home, "drive_c"),
		filepath.Join(home, "drive_d"),
	}
}
