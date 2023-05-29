package legacy

/*
#include "GAME1.h"
int sub_4AD840();
*/
import "C"

func Sub_4AD840() {
	C.sub_4AD840()
}
func Sub_409E70(a1 int) {
	C.sub_409E70(C.int(a1))
}
func Nox_xxx_ammoCheck_415880(a1 int) int {
	return int(C.nox_xxx_ammoCheck_415880(C.ushort(a1)))
}
func Sub_415960(a1 string) int {
	return int(C.sub_415960(internWStr(a1)))
}
func Sub_415910(a1 string) int {
	return int(C.sub_415910(internCStr(a1)))
}
func Sub_415DA0(a1 string) int {
	return int(C.sub_415DA0(internWStr(a1)))
}
func Sub_415DF0(a1 string) int {
	return int(C.sub_415DF0(internCStr(a1)))
}
