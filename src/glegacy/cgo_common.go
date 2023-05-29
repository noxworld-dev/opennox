package legacy

type char = int8
type size_t = int32
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
