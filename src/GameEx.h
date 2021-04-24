#include "DG_dynarr.h"
#include "defs.h"
#include "proto.h"

#ifdef _WIN32
typedef intptr_t INT_PTR;

#include <mmreg.h>
#include <windows.h>
#else
#include "windows_compat.h"
#endif

typedef struct keyCodeStruct {
	unsigned __int8 keyCode;
	char keyName[12];
} keyCodeStruct;

typedef struct smallPlayerStruct {
	char string[18];
} smallPlayerStruct;

DA_TYPEDEF(smallPlayerStruct, smallPlayerStructVector);
DA_TYPEDEF(int, intArray);

//-------------------------------------------------------------------------
// Function declarations

#define __thiscall  // Test compile in C mode
#define __usercall  // Test compile in C mode

unsigned __int8  KeyCodeMatcher(char* a1);
int  GameExCfgSaver();
const char* __usercall SomeStringSearcher(const char* result, const char* a2, char* a3);
char GameExCfgLoader();
int  sendtoWrapper(char* buf, int len, int smth);
void  notifyThisIsServeronly(int ptr, __int16 shortval, BOOL boolval); // idb
int __usercall DestroyNoxWindow();
int __usercall copyServerMatchData(char* a1);
char  getPlayerClassFromObjPtr(int a1);
int __usercall playerInfoStructsToVector(smallPlayerStructVector* vector);
char  playerInfoStructParser_0(char* a1); // idb
char __usercall playerInfoStructParser_1(int a1, int a2, int* a3);
char  mix_MouseKeyboardWeaponRoll(int playerObj, char a2); // idb
char  playerDropATrap(int playerObj);             // idb
HANDLE __usercall GameIpParser(int a1, int a2, int a3);
unsigned int __usercall pingAllServersInGameIp(int ebx0, int edi0, int a1, int a2, int a3);
signed int __usercall inputNewIp_(int a1, int ebx0, int a2, int a3, int a4);
void playErrSoundClient();
unsigned int invalidIpChecker(unsigned int interval, void* param);
int startInvalidIpChecker();
int  modifyWndInputHandler(int a1, int a2, int a3, int a4);
int getFlagValueFromFlagIndex(signed int a1);
