package legacy

/*
#include "defs.h"
#include "client__gui__window.h"
int sub_4BDFD0();
char  mix_MouseKeyboardWeaponRoll(nox_object_t* playerObj, char a2);
int getFlagValueFromFlagIndex(signed int a1);
int  modifyWndInputHandler(int a1, int a2, int a3, int a4);
int  nox_xxx_clientUpdateButtonRow_45E110(int a1);
unsigned int*  nox_xxx_objGetTeamByNetCode_418C80(int a1);
void  nox_xxx_printCentered_445490(wchar2_t* a1);
char  playerDropATrap(int playerObj);
char playerInfoStructParser_0(void* a1);
char playerInfoStructParser_1(void* a1, int* a3);
*/

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func Sub_4BDFD0() {
	sub_4BDFD0()
}
func Mix_MouseKeyboardWeaponRoll(a1 *server.Object, a2 int8) int {
	return int(mix_MouseKeyboardWeaponRoll(asObjectC(a1), char(a2)))
}
func PlayerInfoStructParser_0(a1 unsafe.Pointer) int {
	return int(playerInfoStructParser_0(a1))
}
func PlayerInfoStructParser_1(a1 unsafe.Pointer, a2 *int32) int {
	return int(playerInfoStructParser_1(a1, (*int)(unsafe.Pointer(a2))))
}
func PlayerDropATrap(a1 *server.Object) {
	playerDropATrap(int(uintptr(a1.CObj())))
}
func GetFlagValueFromFlagIndex(a1 int) uint32 {
	return uint32(getFlagValueFromFlagIndex(int(a1)))
}
