package nox

import "C"

import "nox/v1/common/log"

var (
	aiLog = log.New("ai")
)

//export nox_ai_debug_print
func nox_ai_debug_print(str *C.char) {
	aiLog.Println(GoString(str))
}
