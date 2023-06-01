package legacy

import "github.com/gotranspile/cxgo/runtime/libc"

var nox_log_buf [512]byte = [512]byte{}

func nox_xxx_networkLog_printf_413D30(fmt *byte, _rest ...interface{}) {
	var va libc.ArgList
	va.Start(fmt, _rest)
	nox_vsprintf(&nox_log_buf[0], fmt, va)
	nox_xxx_networkLog_print(&nox_log_buf[0])
}
