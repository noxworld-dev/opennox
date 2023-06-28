package legacy

import (
	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/gotranspile/cxgo/runtime/stdio"
)

func nox_fs_fprintf(f *FILE, format *byte, _rest ...interface{}) int32 {
	var (
		buf  [2048]byte = [2048]byte{}
		args libc.ArgList
	)
	args.Start(format, _rest)
	stdio.Vsnprintf(&buf[0], 2048, libc.GoString(format), args)
	args.End()
	return nox_fs_fputs(f, &buf[0])
}
