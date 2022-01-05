package datapath

import (
	"path/filepath"
	"strings"
)

// SaveNameFromPath gives a save directory name based on a path to player save file.
func SaveNameFromPath(src string) string {
	if src == "" {
		return ""
	}
	src = strings.ReplaceAll(src, "\\", "/")
	sub := strings.Split(src, "/")
	n := len(sub)
	if n == 1 {
		return src
	}
	if last := sub[n-1]; filepath.Ext(last) == "" {
		return last
	}
	return sub[len(sub)-2]
}
