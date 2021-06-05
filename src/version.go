package main

import "strings"

const (
	devCommit = "<dev>"
)

var (
	Version = "v1.6.x"
	Commit  = devCommit
)

func ClientVersionString() string {
	if IsDevVersion() {
		return Version + " (" + Commit + ")"
	}
	return Version
}

func IsDevVersion() bool {
	return Commit == devCommit || strings.HasSuffix(Version, ".x")
}
