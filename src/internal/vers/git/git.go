package git

import (
	"bytes"
	"os"
	"os/exec"
	"strings"

	"github.com/noxworld-dev/opennox/v1/internal/version"
)

const defVersion = version.Series

func do(cmd ...string) string {
	c := exec.Command(cmd[0], cmd[1:]...)
	var buf bytes.Buffer
	c.Stdout = &buf
	c.Stderr = os.Stderr
	c.Env = os.Environ()
	if err := c.Run(); err != nil {
		panic(err)
	}
	return strings.TrimSpace(buf.String())
}

func FullVersion() string {
	vers, sha := Version()
	if sha == "" {
		return vers
	}
	return vers + "-" + sha
}

func Version() (string, string) {
	sha := ShortSHA()
	if sha == "" {
		return defVersion, ""
	}
	vers := do("git", "name-rev", "--tags", "--name-only", sha)
	if vers == "" || vers == "undefined" {
		return defVersion, sha
	}
	return vers, ""
}

func SHA() string {
	return do("git", "rev-parse", "HEAD")
}

func ShortSHA() string {
	return do("git", "rev-parse", "--short", "HEAD")
}
