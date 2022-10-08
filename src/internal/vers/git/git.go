package git

import (
	"bytes"
	"os"
	"os/exec"
	"strings"

	"github.com/noxworld-dev/opennox/v1/internal/version"
)

const defVersion = version.Series

func do(cmd ...string) (string, error) {
	c := exec.Command(cmd[0], cmd[1:]...)
	var buf bytes.Buffer
	c.Stdout = &buf
	c.Stderr = os.Stderr
	c.Env = os.Environ()
	err := c.Run()
	if err != nil {
		return "", err
	}
	return strings.TrimSpace(buf.String()), nil
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
	var vers string
	if v := os.Getenv("GIT_TAG"); v != "" {
		vers = v
	} else {
		vers, _ = do("git", "name-rev", "--tags", "--name-only", sha)
	}
	if vers == "" || vers == "undefined" {
		return defVersion, sha
	}
	return vers, ""
}

func SHA() string {
	if v := os.Getenv("GIT_SHA"); v != "" {
		return v
	}
	v, _ := do("git", "rev-parse", "HEAD")
	return v
}

func ShortSHA() string {
	if v := os.Getenv("GIT_SHA"); v != "" {
		return v
	}
	v, _ := do("git", "rev-parse", "--short", "HEAD")
	return v
}
