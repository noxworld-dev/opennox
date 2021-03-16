//+build !windows

package fs

import (
	"io/ioutil"
	"os"
	"path/filepath"
	"strings"
)

func Normalize(path string) string {
	path = strings.ReplaceAll(path, "\\", string(filepath.Separator))
	if _, err := os.Stat(path); err == nil {
		return path
	}
	// convert to absolute
	abs, err := filepath.Abs(path)
	if err != nil {
		return path
	}
	// normalize recursively
	abs = strings.TrimPrefix(abs, string(filepath.Separator))
	return normalizeRecursive("/", abs)
}

func Denormalize(path string) string {
	return strings.ReplaceAll(path, string(filepath.Separator), "\\")
}

func findCaseInsensitive(dir string, name string) string {
	list, err := ioutil.ReadDir(dir)
	if err != nil {
		return name
	}
	exp := strings.ToLower(name)
	for _, fi := range list {
		if strings.ToLower(fi.Name()) == exp {
			return fi.Name()
		}
	}
	return name
}

func normalizeRecursive(base, path string) string {
	sub := strings.SplitN(path, string(filepath.Separator), 2)
	sub[0] = findCaseInsensitive(base, sub[0])
	base = filepath.Join(base, sub[0])
	if len(sub) == 1 {
		return base
	}
	return normalizeRecursive(base, sub[1])
}
