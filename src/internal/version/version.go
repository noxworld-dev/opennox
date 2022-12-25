package version

import (
	"github.com/noxworld-dev/opennox-lib/log"
)

var Log = log.New("version")

func LogVersion() {
	Log.Printf("version: %s (%s)", Version(), Commit())
}

const (
	DefVersion = "v1.8.12-dev"
)

const (
	devCommit = "<dev>"
)

var (
	version = DefVersion
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
