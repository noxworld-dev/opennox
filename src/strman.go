package opennox

import (
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	strMan     = strman.New()
	strManDone = false
)

func StrmanReadFile(path string) error {
	if strManDone {
		return nil
	}
	err := strMan.ReadFile(path)
	if err != nil {
		return err
	}
	strManDone = true
	return nil
}

func Nox_strman_free_410020() {
	strMan = strman.New()
	strManDone = false
	alloc.FreeStrings()
}
