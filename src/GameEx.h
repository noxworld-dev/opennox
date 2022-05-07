#ifndef NOX_GAMEEX_H
#define NOX_GAMEEX_H

unsigned char KeyCodeMatcher(char* a1);
void GameExCfgSaver();
const char* SomeStringSearcher(const char* result, const char* a2, char* a3);
char GameExCfgLoader();
void DestroyNoxWindow();
int copyServerMatchData(char* a1);
char getPlayerClassFromObjPtr(int a1);
char playerInfoStructParser_0(char* a1); // idb
char playerInfoStructParser_1(int a1, int a2, int* a3);
char mix_MouseKeyboardWeaponRoll(int playerObj, char a2); // idb
char playerDropATrap(int playerObj);                      // idb
void* GameIpParser(int a1, int a2, int a3);
unsigned int pingAllServersInGameIp(int ebx0, int edi0, int a1, int a2, int a3);
signed int inputNewIp_(int a1, int ebx0, int a2, int a3, int a4);
unsigned int invalidIpChecker(unsigned int interval, void* param);
int startInvalidIpChecker();
int modifyWndInputHandler(int a1, int a2, int a3, int a4);
int getFlagValueFromFlagIndex(signed int a1);

#endif // NOX_GAMEEX_H
