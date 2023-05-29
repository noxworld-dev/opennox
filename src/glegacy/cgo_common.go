package legacy

type char = int8
type size_t = int32
type long = int32
type ulonglong = uint64

type int2 struct {
	field_0 int32
	field_4 int32
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
