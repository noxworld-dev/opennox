//+build windows

package datapath

import (
	"golang.org/x/sys/windows/registry"
)

func registryStringKey(path, key string) (string, bool) {
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
