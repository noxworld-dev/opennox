package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
)

type size_t = uint32
type long = int32
type ulonglong = uint64

type int2 struct {
	field_0 int32
	field_4 int32
}

type int4 struct {
	field_0 int32
	field_4 int32
	field_8 int32
	field_C int32
}

type float2 struct {
	field_0 float32
	field_4 float32
}

type float4 struct {
	field_0 float32
	field_4 float32
	field_8 float32
	field_C float32
}

type nox_point struct {
	x int32
	y int32
}

type nox_rect struct {
	min_x int32
	min_y int32
	max_x int32
	max_y int32
}

func bool2int32(v bool) int32 {
	if v {
		return 1
	}
	return 0
}

func COERCE_FLOAT(x uint32) float32 {
	return math.Float32frombits(x)
}

func funAddrP(fnc any) unsafe.Pointer {

}

func funAddr(fnc any) uintptr {

}

func asFuncT[T any](h uintptr) T {

}

func asFunc[T any](h int32, typ *T) any {
	return asFuncT[T](uintptr(h))
}

func memset32(x *uint32, y uint32, z uint32) {
	arr := unsafe.Slice(x, z)
	for i := range arr {
		arr[i] = y
	}
}

func atoi(s *byte) int {
	return libc.Atoi(GoString(s))
}

func atof(s *byte) float64 {
	return libc.Atof(GoString(s))
}
