package legacy

/*
#include "defs.h"
#include "client__draw__glowdraw.h"
int nox_thing_static_random_draw(uint32_t* a1, nox_drawable* dr);
*/

import "unsafe"

func Get_nox_thing_static_random_draw() unsafe.Pointer {
	return nox_thing_static_random_draw
}
func Get_nox_thing_red_spark_draw() unsafe.Pointer {
	return nox_thing_red_spark_draw
}
func Get_nox_thing_blue_spark_draw() unsafe.Pointer {
	return nox_thing_blue_spark_draw
}
func Get_nox_thing_yellow_spark_draw() unsafe.Pointer {
	return nox_thing_yellow_spark_draw
}
func Get_nox_thing_green_spark_draw() unsafe.Pointer {
	return nox_thing_green_spark_draw
}
func Get_nox_thing_cyan_spark_draw() unsafe.Pointer {
	return nox_thing_cyan_spark_draw
}
