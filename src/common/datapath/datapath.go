package datapath

import (
	"os"
	"path/filepath"
	"sync"

	"nox/v1/common"
	"nox/v1/common/fs"
	"nox/v1/common/log"
)

var Log = log.New("path")

var (
	workdir string

	once    sync.Once
	datadir string
)

func init() {
	if wd, err := os.Getwd(); err != nil {
		Log.Printf("cannot get workdir: %w", err)
	} else {
		workdir = wd
	}
}

// get returns the current Nox data dir.
func get() string {
	once.Do(func() {
		if datadir == "" {
			Set(Find())
		}
	})
	return datadir
}

// Path returns the current Nox data dir. If additional args are provided, they will joined with the data dir.
func Path(path ...string) string {
	if len(path) == 0 {
		return get()
	}
	args := make([]string, 0, 1+len(path))
	args = append(args, get())
	args = append(args, path...)
	return filepath.Join(args...)
}

// Maps returns the current Nox maps dir. If additional args are provided, they will joined with the maps dir.
func Maps(path ...string) string {
	const dir = common.MapsDir
	if len(path) == 0 {
		return Path(dir)
	}
	args := make([]string, 0, 2+len(path))
	args = append(args, get(), dir)
	args = append(args, path...)
	return filepath.Join(args...)
}

// Save returns the current Nox save dir. If additional args are provided, it will joined with the save dir.
func Save(path ...string) string {
	args := make([]string, 0, 2+len(path))
	args = append(args, get(), common.SaveDir)
	args = append(args, path...)
	return filepath.Join(args...)
}

// Set the Nox data dir.
func Set(dir string) {
	if abs, err := filepath.Abs(dir); err == nil {
		dir = abs
	}
	datadir = dir
	Log.Printf("setting data dir to: %q", dir)
}

// Find locates game data path. It returns empty string if not found.
func Find() string {
	consider := []string{
		os.Getenv("NOX_DATA"),    // takes priority
		".",                      // current dir overrides registry and other install paths
		filepath.Dir(os.Args[0]), // same for binary dir
	}
	// search in registry by default
	consider = append(consider, registryPaths()...)
	// prefer GoG, since it's patched and official
	consider = append(consider, gogPaths()...)
	// then try Reloaded: patched, though unofficial
	consider = append(consider, reloadedPaths()...)
	// lastly, check Origin
	consider = append(consider, originPaths()...)
	for _, path := range consider {
		if path == "" {
			continue
		}
		if !filepath.IsAbs(path) {
			// this is a workaround for Nox trying to chdir from time to time
			path = filepath.Join(workdir, path)
		}
		if Check(path) {
			return path
		}
	}
	return ""
}

var checkFiles = []string{
	"gamedata.bin",
	"modifier.bin",
	"monster.bin",
	"thing.bin",
}

// Check if a directory contains Nox game data.
func Check(path string) bool {
	if fi, err := fs.Stat(path); err != nil || !fi.IsDir() {
		return false
	}
	for _, name := range checkFiles {
		fpath := filepath.Join(path, name)
		if fi, err := fs.Stat(fpath); err != nil || fi.IsDir() {
			return false
		}
	}
	return true
}
