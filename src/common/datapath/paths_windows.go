//+build windows

package datapath

import (
	"path/filepath"

	"golang.org/x/sys/windows/registry"

	"nox/v1/common/log"
)

var registryLog = log.New("registry")

func pathPrefixes() []string {
	return []string{`C:\`, `D:\`}
}

func registryPaths() []string {
	var out []string
	if path, ok := getStringKey(`SOFTWARE\WOW6432Node\Westwood\Nox`, "InstallPath"); ok {
		registryLog.Printf("install path (x64): %q", path)
		out = append(out, filepath.Dir(path))
	}
	if path, ok := getStringKey(`SOFTWARE\Westwood\Nox`, "InstallPath"); ok {
		registryLog.Printf("install path: %q", path)
		out = append(out, filepath.Dir(path))
	}
	return out
}

func getStringKey(path, key string) (string, bool) {
	k, err := registry.OpenKey(registry.LOCAL_MACHINE, path, registry.QUERY_VALUE)
	if err != nil {
		registryLog.Printf("error opening key %q: %v", path, err)
		return "", false
	}
	defer k.Close()

	s, _, err := k.GetStringValue(key)
	if err == registry.ErrNotExist {
		return "", false
	} else if err != nil {
		registryLog.Printf("error opening value %q: %v", key, err)
		return "", false
	}
	return s, true
}
