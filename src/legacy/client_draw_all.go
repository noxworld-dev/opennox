package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func Get_nox_thing_static_random_draw() unsafe.Pointer {
	return ccall.FuncAddr(nox_thing_static_random_draw)
}
func Get_nox_thing_red_spark_draw() unsafe.Pointer {
	return ccall.FuncAddr(nox_thing_red_spark_draw)
}
func Get_nox_thing_blue_spark_draw() unsafe.Pointer {
	return ccall.FuncAddr(nox_thing_blue_spark_draw)
}
func Get_nox_thing_yellow_spark_draw() unsafe.Pointer {
	return ccall.FuncAddr(nox_thing_yellow_spark_draw)
}
func Get_nox_thing_green_spark_draw() unsafe.Pointer {
	return ccall.FuncAddr(nox_thing_green_spark_draw)
}
func Get_nox_thing_cyan_spark_draw() unsafe.Pointer {
	return ccall.FuncAddr(nox_thing_cyan_spark_draw)
}
