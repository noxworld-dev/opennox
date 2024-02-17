package legacy

/*
#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME3_2.h"

void sub_409FB0_settings(short a1, unsigned short a2);
int sub_4D0DC0(int a1, int a2);
int sub_489FF0(int a1, int a2, const void* a3);
*/
import "C"
import "unsafe"

func Sub_453070() int {
	return int(C.sub_453070())
}
func Sub_44D990() int {
	return int(C.sub_44D990())
}
func Sub_43DC30() int {
	return int(C.sub_43DC30())
}
func Nox_xxx_sysopGetPass_40A630() string {
	return GoWString(C.nox_xxx_sysopGetPass_40A630())
}
func Sub_4D0D70() int {
	return int(C.sub_4D0D70())
}
func Nox_xxx_getServerSubFlags_409E60() uint32 {
	return uint32(C.nox_xxx_getServerSubFlags_409E60())
}
func Nox_xxx_gameSetServername_40A440(a1 string) {
	C.nox_xxx_gameSetServername_40A440(internCStr(a1))
}
func Nox_xxx_sysopSetPass_40A610(a1 string) {
	C.nox_xxx_sysopSetPass_40A610(internWStr(a1))
}
func Nox_xxx_rateUpdate_40A6D0(a1 int) {
	C.nox_xxx_rateUpdate_40A6D0(C.int(a1))
}
func Sub_4D0D90(a1 int) {
	C.sub_4D0D90(C.int(a1))
}
func Sub_409FB0_settings(a1 uint16, a2 uint16) {
	C.sub_409FB0_settings(C.short(a1), C.ushort(a2))
}
func Sub_409EC0(a1 int) {
	C.sub_409EC0(C.int(a1))
}
func Sub_4D0DC0(a1 uint32, a2 int) {
	C.sub_4D0DC0(C.int(a1), C.int(a2))
}
func Sub_489FF0(a1 int, a2 int, a3 unsafe.Pointer) {
	C.sub_489FF0(C.int(a1), C.int(a2), a3)
}
func Sub_409F40(a1 int) int {
	return int(C.sub_409F40(C.int(a1)))
}
func Sub_4D0DE0(a1 uint32) int {
	return int(C.sub_4D0DE0(C.int(a1)))
}
