package opennox

/*
#include "common__config.h"
*/
import "C"
import (
	"errors"
	"os"

	"github.com/noxworld-dev/opennox-lib/ifs"
)

func noxConfigRead(path string, skip bool) error {
	ctrlEvent.Reset()
	f, err := ifs.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()

	cfile := &File{File: f, text: true}
	file := newFileHandle(cfile)
	defer cfile.Close()

	if !skip {
		if C.nox_common_parsecfg_all(file) == 0 {
			return errors.New("config parsing failed")
		}
	}
	if C.nox_common_skipcfgfile_4331E0(file, C.int(bool2int(skip))) == 0 {
		return errors.New("config parsing failed")
	}
	return nil
}

func nox_common_readcfgfile(path string, skip bool) error {
	err := noxConfigRead(path, skip)
	if err == nil {
		return nil
	} else if !os.IsNotExist(err) {
		return err
	}
	// not found: read default and write config back
	orig := err
	err = noxConfigRead("default.cfg", skip)
	if os.IsNotExist(err) {
		return orig
	} else if err != nil {
		return err
	}
	C.nox_common_writecfgfile(internCStr("nox.cfg"))
	return nil
}
