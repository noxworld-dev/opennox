package datapath

import (
	"path/filepath"
	"strings"

	"nox/v1/common/log"
)

var (
	registryLog  = log.New("registry")
	registryKeys = []struct {
		Path string
		Key  string
	}{
		// default ones, also used by GoG
		{`SOFTWARE\WOW6432Node\Westwood\Nox`, "InstallPath"},
		{`SOFTWARE\Westwood\Nox`, "InstallPath"},
		// additional ones used by Nox Reloaded
		{`SOFTWARE\WOW6432Node\Westwood\Nox`, "FolderPath"},
		{`SOFTWARE\Westwood\Nox`, "FolderPath"},
		// these are set by Origin
		{`SOFTWARE\WOW6432Node\Westwood Studios\NOX`, "Install Dir"},
		{`SOFTWARE\Westwood Studios\NOX`, "Install Dir"},
	}
)

func registryPaths() []string {
	var out []string
	for _, kv := range registryKeys {
		if path, ok := registryStringKey(kv.Path, kv.Key); ok {
			registryLog.Printf(`install path at %s\%s: %q`, kv.Path, kv.Key, path)
			if strings.HasSuffix(strings.ToLower(path), ".exe") {
				path = filepath.Dir(path)
			}
			out = append(out, path)
		}
	}
	return out
}
