package datapath

import (
	"path/filepath"

	"nox/v1/common/log"
)

var gogLog = log.New("gog")

// gogPaths returns possible path of GoG Nox installation.
func gogPaths() []string {
	var paths []string
	// registry paths
	for _, pref := range []string{
		`SOFTWARE\WOW6432Node\GOG.com`,
		`SOFTWARE\GOG.com`,
	} {
		// these exists if installed via GoG Galaxy
		if path, ok := registryStringKey(pref+`\Games\1207658964`, "PATH"); ok {
			gogLog.Printf(`install path at %s\%s: %q`, pref+`\Games\1207658964`, "PATH", path)
			paths = append(paths, path)
		}
		if path, ok := registryStringKey(pref+`\Games\1207658964`, "WORKINGDIR"); ok {
			gogLog.Printf(`install path at %s\%s: %q`, pref+`\Games\1207658964`, "WORKINGDIR", path)
			paths = append(paths, path)
		}
		// this one exists when installed via offline installer
		if path, ok := registryStringKey(pref+`\GOGNOX`, "PATH"); ok {
			gogLog.Printf(`install path at %s\%s: %q`, pref+`\GOGNOX`, "PATH", path)
			paths = append(paths, path)
		}
		// fallback for GoG Galaxy (using client path)
		if path, ok := registryStringKey(pref+`\GalaxyClient\paths`, "client"); ok {
			path = filepath.Join(path, `Games\Nox`)
			gogLog.Printf(`install path at %s\%s: %q`, pref+`\GalaxyClient\paths`, "client", path)
			paths = append(paths, path)
		}
	}
	// static fallback paths
	paths = append(paths,
		// paths for install via GoG Galaxy
		`Program Files (x86)\GOG Galaxy\Games\Nox`,
		`Program Files\GOG Galaxy\Games\Nox`,
		// paths for offline installer
		`GOG Games\Nox`,
		`Games\GOG.com\Nox`,
		// some legacy ones, just in case
		`Program Files (x86)\GOG.com\Nox`,
		`Program Files\GOG.com\Nox`,
		`Program Files (x86)\GOGcom\Nox`,
		`Program Files\GOGcom\Nox`,
	)
	out := tryPaths(paths)
	for _, path := range out {
		gogLog.Printf("potential install path: %q", path)
	}
	return out
}
