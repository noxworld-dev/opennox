package version

import "strings"

const (
	Series = "v1.8.x"
)

const (
	devCommit = "<dev>"
)

var (
	version = Series
	commit  = devCommit
)

func Version() string {
	return version
}

func Commit() string {
	return commit
}

func ClientVersion() string {
	if IsDev() {
		return version + " (" + commit + ")"
	}
	return version
}

func IsDev() bool {
	return commit == devCommit || strings.HasSuffix(version, ".x")
}
