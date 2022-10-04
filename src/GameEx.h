#ifndef NOX_GAMEEX_H
#define NOX_GAMEEX_H

#include "defs.h"
char getPlayerClassFromObjPtr(int a1);
char playerInfoStructParser_0(char* a1);
char playerInfoStructParser_1(int a1, int* a3);
char mix_MouseKeyboardWeaponRoll(nox_object_t* playerObj, char a2);
char playerDropATrap(int playerObj);
int getFlagValueFromFlagIndex(signed int a1);

#endif // NOX_GAMEEX_H
