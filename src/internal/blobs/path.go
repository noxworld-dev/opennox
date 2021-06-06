package blobs

import (
	"io"
	"io/ioutil"
	"os"
	"path/filepath"
)

var blobPath = "."

// SetPath sets the root path where all source and blob files are located.
func SetPath(path string) {
	blobPath = path
}

// Path returns the root path where all source and blob files are located.
func Path(arr ...string) string {
	if len(arr) == 0 {
		return blobPath
	}
	return filepath.Join(blobPath, filepath.Join(arr...))
}

// ReadFile is a helper that reads a file relative to Path.
func ReadFile(path string) ([]byte, error) {
	return ioutil.ReadFile(Path(path))
}

var excludeFiles = map[string]struct{}{
	"memmap.go":   {},
	"memmap.c":    {},
	"GAME_data.c": {},
	"vardefs.c":   {},
}

// EachFile runs the callback function for every file in Path.
func EachFile(fnc func(path string) error) error {
	dir, err := os.Open(Path())
	if err != nil {
		return err
	}
	defer dir.Close()
	for {
		list, err := dir.ReadDir(100)
		if err == io.EOF {
			return nil
		} else if err != nil {
			return err
		}
		for _, e := range list {
			if e.IsDir() {
				continue
			}
			if _, ok := excludeFiles[e.Name()]; ok {
				continue
			}
			switch filepath.Ext(e.Name()) {
			case ".c", ".go":
				if err := fnc(e.Name()); err != nil {
					return err
				}
			}
		}
	}
}
