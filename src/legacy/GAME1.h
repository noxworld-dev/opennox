#ifndef NOX_PORT_GAME1
#define NOX_PORT_GAME1

#include "defs.h"
#include "common__system__team.h"

extern int nox_server_gameSettingsUpdated;

void nox_common_setEngineFlag(const nox_engine_flag flags);
void nox_common_resetEngineFlag(const nox_engine_flag flags);
bool nox_common_getEngineFlag(const nox_engine_flag flags);
int nox_xxx_parseString_409470(FILE* a1, uint8_t* a2);
int sub_409A70(short a1);
void nox_client_setVersion_409AE0(unsigned int vers);
char* nox_server_currentMapGetFilename_409B30();
char* nox_xxx_mapGetMapName_409B40();
unsigned int sub_409B50(const char* a1);
char* sub_409B80();
char* nox_xxx_gameSetMapPath_409D70(char* a1);
int sub_409E40(int a1);
int nox_xxx_getServerSubFlags_409E60();
int sub_409E70(int a1);
int sub_409EC0(int a1);
int sub_409EF0(int a1);
int sub_409F40(int a1);
int nox_xxx_servSetPlrLimit_409F80(int a1);
int nox_xxx_servGetPlrLimit_409FA0();
short nox_xxx_servGamedataGet_40A020(short a1);
unsigned char sub_40A180(short a1);
int sub_40A1A0();
int sub_40A1F0(int a1);
int sub_40A220();
int sub_40A230();
long long sub_40A250();
void nox_xxx_servStartCountdown_40A2A0(int a1, char* a2);
int sub_40A300();
long long sub_40A310(int a1);
void nox_xxx_set3512_40A340(int a1);
int nox_xxx_get3512_40A350();
unsigned int sub_40A3C0(unsigned int a1);
int nox_xxx_servGetPort_40A430();
char* nox_xxx_gameSetServername_40A440(char* a1);
char* nox_xxx_serverOptionsGetServername_40A4C0();
void nox_xxx_setGameFlags_40A4D0(unsigned int f);
void nox_common_gameFlags_unset_40A540(unsigned int f);
unsigned int nox_common_gameFlags_getVal_40A5B0();
bool nox_common_gameFlags_check_40A5C0(unsigned int f);
int nox_xxx_ruleSetNoRespawn_40A5E0(int a1);
int nox_server_doPlayersAutoRespawn_40A5F0();
wchar2_t* nox_xxx_sysopSetPass_40A610(wchar2_t* a1);
wchar2_t* nox_xxx_sysopGetPass_40A630();
void nox_server_gameSettingsUpdated_40A670();
int nox_server_gameDoSwitchMap_40A680();
void nox_server_gameUnsetMapLoad_40A690();
int sub_40A6A0(int a1);
int sub_40A6B0();
int nox_xxx_rateGet_40A6C0();
int nox_xxx_rateUpdate_40A6D0(int a1);
int sub_40A710(int a1);
int sub_40A740();
int sub_40A770();
int nox_xxx_countNonEliminatedPlayersInTeam_40A830(nox_team_t* a1);
int nox_xxx_gamePlayIsAnyPlayers_40A8A0();
void sub_40A970();
int sub_40AA00();
int sub_40AA20();
int sub_40AA30(int a1);
int sub_40AA40();
int sub_40AA60(int a1);
int sub_40AA70(nox_playerInfo* pl);
int nox_xxx_utilFindSound_40AF50(char* a1);
char* nox_xxx_getSndName_40AF80(int a1);
char* sub_40B1F0(unsigned char a1);
int sub_40B4E0(unsigned char a1);
void sub_40B970();
int sub_40BA90(int a1, unsigned char a2, short a3, unsigned short a4, void* a5);
int sub_40BC60(int a1, int a2, const char* a3, void* a4, int a5, int a6);
void sub_40E090();
int nox_xxx_cliCanTalkMB_4100F0(short* a1);
void nox_xxx_wall_410160();
void* nox_xxx_wallCreateAt_410250(int a1, int a2);
uint8_t* nox_xxx_doorAttachWall_410360(int a1, int a2, int a3);
uint32_t* sub_410390(int a1, int a2, int a3);
void nox_xxx_mapDelWallAtPt_410430(int a1, int a2);
int* nox_xxx_wallDestroyedByWallid_410520(short a1);
int sub_410550(short a1);
void* nox_server_getWallAtGrid_410580(int a1, int a2);
void* nox_xxx_wall_4105E0(int a1, int a2);
uint32_t* sub_410730();
uint32_t* nox_xxx_wallSecretBlock_410760(uint32_t* a1);
void* nox_xxx_wallSecretGetFirstWall_410780();
int nox_xxx_wallSecretNext_410790(int* a1);
int* sub_4107A0(void* lpMem);
uint32_t* nox_xxx_wallBreackableListClear_410810();
uint32_t* nox_xxx_wallBreackableListAdd_410840(int a1);
void* nox_xxx_wallGetFirstBreakableCli_410870();
int nox_xxx_wallGetNextBreakableCli_410880(int* a1);
int nox_thing_read_WALL_410900(nox_memfile* f, char* a2);
char* sub_410D40(int a1);
int nox_xxx_wallTileByName_410D60(const char* a1);
unsigned char nox_xxx_mapWallMaxVariation_410DD0(int a1, int a2, int a3);
unsigned char nox_xxx_map_410E00(int a1);
unsigned char nox_xxx_mapWallGetHpByTile_410E20(int a1);
unsigned char nox_xxx_wallGetBrickTypeMB_410E40(int a1);
char* nox_xxx_wallGetBrickObj_410E60(int a1, int a2);
char* nox_xxx_wallSoundByTile_410EA0(int a1);
char* nox_xxx_wallFindOpenSound_410EE0(int a1);
char* nox_xxx_wallFindCloseSound_410F20(int a1);
int nox_xxx_tileAlloc_410F60_init();
void nox_xxx_tileFree_410FC0_free();
int nox_xxx_tileNFromPoint_411160(float2* a1);
int sub_411350(int* a1, int* a2, int a3);
int sub_4113A0(int* a1, int a2);
int sub_411490(int a1, int a2);
int nox_thing_read_FLOR_411540(nox_memfile* f, uint8_t* a2);
int nox_xxx_checkFacade_4117E0(const char* a1);
int nox_thing_read_EDGE_411850(nox_memfile* f, uint8_t* a2);
int nox_xxx_mapTileAllowTeleport_411A90(float2* a1);
void* nox_xxx_getProjectileClassById_413250(int a1);
void* nox_xxx_equipClothFindDefByTT_413270(int a1);
int nox_xxx_modifGetIdByName_413290(char* a1);
void* nox_xxx_modifGetDescById_413330(int a1);
void* nox_xxx_modifGetModifListByType_4133B0(int a1);
obj_412ae0_t* nox_xxx_modifNext_4133C0(obj_412ae0_t* a1);
int sub_4133D0(int a1);
int sub_413420(char a1);
int sub_4134D0();
int sub_4137E0();
char* sub_413890();
void sub_4138E0(int a1);
void sub_413900(int a1);
int sub_413920();
int sub_4139B0();
void sub_413A00(int a1);
int nox_xxx_checkGameFlagPause_413A50();
void nox_xxx_gameLoopMemDump_413E30();
int sub_413F60(const void* a1, const void* a2);
int sub_414BD0(signed int a1);
int sub_414C50(signed int a1);
char nox_xxx_initSinCosTables_414C90();
int nox_thing_skip_AUD_414D40(nox_memfile* f);
int nox_thing_read_FLOR_414DB0(nox_memfile* f);
int nox_thing_read_EDGE_414E70(nox_memfile* f, void* a2);
int nox_thing_read_WALL_414F60(nox_memfile* f, void* a2);
int nox_thing_skip_spells_415100(nox_memfile* f);
int nox_thing_read_image_415240(nox_memfile* f);
int nox_thing_read_ability_415320(nox_memfile* f);
int nox_thing_read_audio_415660(nox_memfile* a1, char* a2);
int nox_xxx_weaponInventoryEquipFlags_415820(nox_object_t* item);
int sub_415840(int a1);
int nox_xxx_ammoCheck_415880(unsigned short typ_ind);
int sub_415910(char* a1);
int sub_415960(wchar2_t* a1);
char* sub_4159B0(char* a1);
int sub_4159F0(int a1);
double sub_415BD0(int a1);
double nox_xxx_itemApplyDefendEffect_415C00(int a1);
int nox_xxx_unitArmorInventoryEquipFlags_415C70(nox_object_t* item);
int sub_415C90(const nox_object_t* item);
int sub_415CD0(int a1);
int sub_415D10(int a1);
int sub_415DA0(wchar2_t* a1);
int sub_415DF0(char* a1);
char* sub_415E40(char* a1);
int sub_415E80(int a1);
int nox_xxx_setKeybTimeout_4160D0(int a1);
bool nox_xxx_checkKeybTimeout_4160F0(unsigned char a1, unsigned int a2);
bool sub_416120(unsigned char a1);
int sub_416150(int a1, int a2);
int sub_416170(int a1);
int sub_4161E0();
void sub_4164F0();
int sub_416580();
char* nox_xxx_cliGamedataGet_416590(int a1);
char* sub_4165B0();
char* sub_4165D0(int a1);
int sub_4165F0(int a1, int a2);
char* sub_416630();
void* sub_416640();
int sub_416650();
void sub_416690();
void sub_416720();
int* sub_416770(int a1, wchar2_t* a2, const char* a3);
void sub_416820(int a1);
int* sub_416860(int a1);
int* sub_4168A0(wchar2_t* a1);
int* sub_4168E0();
int* sub_4168F0(int* a1);
int* sub_416900();
int* sub_416910(int* a1);
int sub_416920();
int* sub_416950();
int sub_4169C0();
int nox_xxx_cliSetSettingsAcquired_4169D0(int a1);
char* sub_4169F0();
void nox_ticks_reset_416D40();
char* nox_xxx_playerForceSendLessons_416E50(int a1);
nox_playerInfo* nox_common_playerInfoGetFirst_416EA0();
nox_playerInfo* nox_common_playerInfoGetNext_416EE0(nox_playerInfo* p);
int nox_common_playerInfoCount_416F40();
nox_playerInfo* nox_common_playerInfoGetByID_417040(int a1);
nox_playerInfo* nox_common_playerInfoFromNum_417090(int i);
nox_playerInfo* nox_common_playerInfoFromNumRaw(int i);
char* nox_xxx_playerByName_4170D0(wchar2_t* a1);
int nox_xxx_netMarkMinimapObject_417190(int a1, nox_object_t* a2, int a3);
int sub_417270(int a1);
int nox_xxx_netUnmarkMinimapObj_417300(int a1, nox_object_t* a2, int a3);
int nox_xxx_playerMapTracksObj_4173D0(int a1, nox_object_t* a2);
char* nox_xxx_netUnmarkMinimapSpec_417470(int a1, int a2);
char* nox_xxx_netMarkMinimapForAll_4174B0(int a1, int a2);
int nox_xxx_netNeedTimestampStatus_4174F0(nox_playerInfo* a1, int a2);
char nox_xxx_playerUnsetStatus_417530(nox_playerInfo* a1, int a2);
char* nox_xxx_sendAllClientStatus_4175C0(int a1);
int nox_xxx_netReportPlayerStatus_417630(nox_playerInfo* pl);
void nox_xxx_cliPlayerRespawn_417680(int a1, char a2);
char* nox_xxx_clientEquipWeaponArmor_417AA0(char a1, int a2, int a3, int a4);
char* sub_417B80(char a1, int a2, int a3);
int sub_417CF0();
void nox_xxx_SetGameplayFlag_417D50(int a1);
void nox_xxx_UnsetGameplayFlags_417D70(int a1);
int nox_xxx_GetGameplayFlags_417D90();
bool nox_xxx_CheckGameplayFlags_417DA0(int a1);
int sub_417DC0();
char sub_417DE0();
int nox_xxx_mapInfoSetCapflag_417EA0();
bool sub_417EC0();
char nox_xxx_mapInfoSetFlagball_417F30();
int sub_417F50(int a1);
int nox_xxx_mapInfoSetKotr_4180D0();
void sub_4181F0(int a1);
int sub_418390();
int sub_4183C0();
void sub_4184D0(nox_team_t* a1);
int nox_xxx_wndGuiTeamCreate_4185B0();
int nox_xxx_teamAssignFlags_418640();
char* nox_xxx_toggleAllTeamFlags_418690(int a1);

int nox_xxx_wallForeachFn_410640(void (*a1)(int, int), int a2);

#endif // NOX_PORT_GAME1
