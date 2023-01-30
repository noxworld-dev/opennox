package legacy

import (
	"fmt"
	"path/filepath"
	"runtime"
	"strings"
)

func bool2int(v bool) int {
	if v {
		return 1
	}
	return 0
}

func caller(skip int) string {
	pc, file, line, ok := runtime.Caller(skip + 1)
	if !ok {
		return "<unknown>"
	}
	fnc := "<unknown>"
	if f := runtime.FuncForPC(pc); f != nil {
		fnc = f.Name()
		if i := strings.LastIndexByte(fnc, '.'); i >= 0 {
			fnc = fnc[i+1:]
		}
	}
	return fmt.Sprintf("%s, %s:%d", fnc, filepath.Base(file), line)
}
