package version

import (
	"nox/v1/common/log"
)

var Log = log.New("version")

func LogVersion() {
	Log.Printf("version: %s (%s)", Version(), Commit())
}

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
	return commit == devCommit || semverIsDev(version)
}
