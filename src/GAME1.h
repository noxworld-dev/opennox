#ifndef NOX_PORT_GAME1
#define NOX_PORT_GAME1

#include "defs.h"

extern int nox_server_gameSettingsUpdated;

void nox_common_setEngineFlag(const nox_engine_flag flags);
void nox_common_resetEngineFlag(const nox_engine_flag flags);
void nox_common_toggleEngineFlag(const nox_engine_flag flags);
bool nox_common_getEngineFlag(const nox_engine_flag flags);
int nox_get_audio_enabled();
wchar_t* nox_xxx_getNoxVer_401020();
BOOL sub_401040();
int sub_401060();
int cmain(int argc, const char* argv[]);
void sub_401B20(char* a1);
void nox_xxx_parseRead_4093E0(FILE* a1, char* a2, int a3);
int nox_xxx_parseString_409470(FILE* a1, _BYTE* a2);
int sub_409A70(__int16 a1);
unsigned short nox_client_getVersionBuild_409AC0();
unsigned char nox_client_getVersionMajor_409AA0();
unsigned char nox_client_getVersionMinor_409AB0();
unsigned int nox_client_getVersionCode_409AD0();
void nox_client_setVersion_409AE0(unsigned int vers);
int nox_xxx_mapCrcGetMB_409B00();
int nox_xxx_mapSetCrcMB_409B10(int a1);
char* nox_server_currentMapGetFilename_409B30();
char* nox_xxx_mapGetMapName_409B40();
unsigned int sub_409B50(const char* a1);
char* sub_409B80();
char* nox_server_get_current_map_path_409B90();
char* sub_409C70();
char* nox_xxx_gameSetMapPath_409D70(char* a1);
int sub_409E40(int a1);
int nox_xxx_getServerSubFlags_409E60();
int sub_409E70(int a1);
int sub_409EC0(int a1);
int sub_409EF0(int a1);
BOOL sub_409F40(int a1);
int nox_xxx_servSetPlrLimit_409F80(int a1);
int nox_xxx_servGetPlrLimit_409FA0();
__int16 nox_xxx_servGamedataGet_40A020(__int16 a1);
unsigned __int8 sub_40A180(__int16 a1);
BOOL sub_40A1A0();
int sub_40A1F0(int a1);
int sub_40A220();
int sub_40A230();
__int64 sub_40A250();
const char* nox_xxx_servStartCountdown_40A2A0(int a1, const char* a2);
int sub_40A300();
__int64 sub_40A310(int a1);
void nox_xxx_set3512_40A340(int a1);
int nox_xxx_get3512_40A350();
void nox_xxx_setMapCRC_40A360(int crc);
int nox_xxx_getMapCRC_40A370();
void nox_xxx_mapLoad_40A380();
unsigned int sub_40A3C0(unsigned int a1);
void nox_xxx_setPortParam_40A3E0(int a1);
int nox_xxx_setClientNetPort_40A410(int a1);
int nox_client_getClientPort_40A420();
int nox_xxx_servGetPort_40A430();
char* nox_xxx_gameSetServername_40A440(char* a1);
char* nox_xxx_serverOptionsGetServername_40A4C0();
void nox_xxx_setGameFlags_40A4D0(unsigned int f);
void nox_common_gameFlags_unset_40A540(unsigned int f);
unsigned int nox_common_gameFlags_getVal_40A5B0();
bool nox_common_gameFlags_check_40A5C0(unsigned int f);
int nox_xxx_ruleSetNoRespawn_40A5E0(int a1);
int nox_server_doPlayersAutoRespawn_40A5F0();
wchar_t* nox_xxx_sysopSetPass_40A610(wchar_t* a1);
wchar_t* nox_xxx_sysopGetPass_40A630();
wchar_t* sub_40A640(wchar_t* a1);
wchar_t* sub_40A660();
void nox_server_gameSettingsUpdated_40A670();
int nox_server_gameDoSwitchMap_40A680();
void nox_server_gameUnsetMapLoad_40A690();
int sub_40A6A0(int a1);
int sub_40A6B0();
int nox_xxx_rateGet_40A6C0();
int nox_xxx_rateUpdate_40A6D0(int a1);
int sub_40A710(int a1);
BOOL sub_40A740();
int sub_40A770();
int nox_xxx_countNonEliminatedPlayersInTeam_40A830(int a1);
int nox_xxx_gamePlayIsAnyPlayers_40A8A0();
void sub_40A970();
BOOL sub_40AA00();
int sub_40AA20();
int sub_40AA30(int a1);
int sub_40AA40();
int sub_40AA50();
int sub_40AA60(int a1);
int sub_40AA70(int a1);
bool nox_xxx_checkHasSoloMaps_40ABD0();
int nox_xxx_PtFuncCompare_40AE90(const void* a1, const void* a2);
int sub_40AEB0(const void* a1, const void* a2);
void nox_init_sound_index_40AED0();
void sub_40AF30();
int nox_xxx_utilFindSound_40AF50(void* a1);
const char* nox_xxx_getSndName_40AF80(int a1);
void nox_xxx_soloGameEscMenuCallback_40AF90(int a1, int a2, char a3, int a4, _BYTE* a5, unsigned int a6);
int sub_40B170(int a1);
char* sub_40B1F0(unsigned __int8 a1);
void sub_40B250(int a1, unsigned __int8 a2, unsigned __int16 a3, const void* a4, size_t a5);
int nox_xxx_netXfer_40B4B0(unsigned int a1, char a2);
int sub_40B4E0(unsigned __int8 a1);
char* sub_40B530(unsigned __int8 a1, char a2);
int nox_xxx_neXfer_40B590(unsigned int a1, char a2, char a3);
int sub_40B5D0(unsigned int a1, char a2, const char* a3, size_t a4, char a5);
int sub_40B690(unsigned int a1, char a2, char a3);
char* sub_40B6D0(_BYTE* a1);
char* sub_40B720(int a1, unsigned __int8 a2);
void sub_40B740();
int sub_40B790();
void sub_40B810(int a1, int a2, int a3);
void sub_40B850(int a1, char a2);
void* sub_40B890(int a1);
int sub_40B930(int a1);
void sub_40B970();
int sub_40BA90(unsigned int a1, char a2, __int16 a3, __int16 a4, const void* a5);
char* sub_40BB20(unsigned int a1, int a2, char a3);
void sub_40BBC0(int a1, char a2);
char* sub_40BC10(int a1, char a2);
int sub_40BC60(int a1, int a2, const char* a3, int a4, int a5, int a6);
int nox_xxx_netXferMsg_40BE80(unsigned int a1, char a2, const char* a3, int a4, char a5);
char* sub_40BF10(_BYTE* a1);
char* sub_40BF60(int a1, char a2, int a3);
char* sub_40BFF0(int a1, char a2, char* a3);
char* sub_40C030(int a1, char a2);
char* sub_40C070(int a1, int a2, char a3);
void sub_40C0D0();
void sub_40C0E0(int a1);
int __stdcall sub_40C140(int a1, int a2, _DWORD* a3);
int __stdcall sub_40C1B0(int a1, int a2, int a3);
int __stdcall sub_40C1F0(int a1, int a2, const void* a3);
int __stdcall sub_40C240(int a1, int a2, int a3);
int __stdcall sub_40C2E0(int a1, int a2, int a3, const char* a4);
int __stdcall sub_40C420(int a1, int a2, int a3, int* a4);
int __stdcall sub_40C4E0(int a1, int a2, int a3, int a4);
int __stdcall sub_40C4F0(int a1, int a2, int a3);
int __stdcall sub_40C500(int a1, int a2, int a3);
int __stdcall sub_40C510(int a1, int a2, int a3);
int __stdcall sub_40C520(int a1, int a2, int a3);
int __stdcall sub_40C530(int a1, int a2, int a3, _BYTE* a4);
int __stdcall sub_40C580(int a1, int a2, int a3, int a4, _BYTE* a5);
int __stdcall sub_40C5C0(int a1, int a2, int a3, int a4, _BYTE* a5);
int __stdcall sub_40C600(int a1, int a2, int a3, _BYTE* a4);
int __stdcall sub_40C650(int a1, int a2, int a3, int a4);
int __stdcall sub_40C660(int a1, int a2, int a3, int a4, int a5);
int __stdcall sub_40C670(int a1, int a2, int a3, int a4, int a5);
int __stdcall sub_40C690(int a1, int a2, int a3, int a4, int a5);
int __stdcall sub_40C710(int a1, int a2, int a3);
int __stdcall sub_40C720(int a1, int a2, _DWORD* a3);
int __stdcall sub_40C7A0(int a1, int a2);
int __stdcall sub_40C7D0(int a1, int a2, int a3, _BYTE* a4);
int __stdcall sub_40C830(int a1, int a2, int a3);
int __stdcall sub_40C880(int a1, int a2, const char* a3, int a4, int a5);
int __stdcall sub_40C8C0(int a1, int a2, int a3, int a4);
int __stdcall sub_40C8F0(int a1, int a2, int a3, int a4);
int __stdcall sub_40C960(int a1, int a2, _DWORD* a3);
int __stdcall sub_40C9D0(int a1, int a2, int* a3);
int __stdcall sub_40CA40(int a1, int a2);
int __stdcall sub_40CA50(int a1, int a2);
BOOL __stdcall sub_40CA60(int a1, int a2, const void* a3);
int __stdcall sub_40CB90(int a1, int a2, int a3);
int __stdcall sub_40CBA0(int a1, int a2, int a3);
int __stdcall sub_40CBE0(int a1, int a2);
int sub_40CD00();
int __stdcall sub_40CD50(int a1, int a2, int a3);
int __stdcall nox_xxx_somejoinproc_40CD60(int a1, int a2, int a3);
int __stdcall sub_40CDC0(int a1, int a2, int a3, int a4);
int sub_40CE60();
void sub_40D0F0();
BOOL sub_40D250();
BOOL sub_40D280(int a1, int a2, int a3, int a4, int a5);
BOOL sub_40D2C0(int a1, int a2, int a3);
BOOL sub_40D2F0(int a1, int a2);
BOOL sub_40D320(int a1);
BOOL sub_40D350(int a1);
void sub_40D380();
BOOL sub_40D3B0();
BOOL sub_40D3E0(int a1);
BOOL sub_40D410(int a1, int a2);
int sub_40D440();
BOOL sub_40D470(int a1, int a2);
BOOL sub_40D4A0(int a1);
BOOL sub_40D4D0(int a1);
BOOL sub_40D500(int a1, int a2);
BOOL sub_40D530(int a1);
int sub_40D560(int a1);
BOOL sub_40D5B0(int a1);
BOOL sub_40D5E0(int a1);
BOOL sub_40D610(int a1);
BOOL sub_40D640(int a1);
BOOL sub_40D670(int a1);
BOOL sub_40D6A0(int a1);
BOOL sub_40D6D0(int a1);
BOOL sub_40D700(int a1, int a2, int a3, int a4, int a5, int a6);
BOOL sub_40D740(int a1);
BOOL sub_40D770(int a1, int a2);
BOOL sub_40D7A0(int a1, int a2);
BOOL sub_40D7D0(int a1, int a2);
BOOL sub_40D800(int a1);
BOOL sub_40D830(int a1);
BOOL sub_40D860();
BOOL sub_40D890(int a1);
BOOL sub_40D8C0(int a1, int a2);
BOOL sub_40D8F0(int a1);
BOOL sub_40D920(int a1);
BOOL sub_40D950(int a1);
BOOL sub_40D980(int a1, int a2, int a3);
BOOL sub_40D9C0(int a1, int a2, int a3, int a4);
BOOL sub_40DA00(int a1);
BOOL sub_40DA30(int a1);
BOOL sub_40DA60(int a1, int a2);
BOOL sub_40DA90(int a1, int a2);
BOOL sub_40DAC0(int a1);
BOOL sub_40DAF0();
BOOL sub_40DB20(int a1);
BOOL sub_40DB50(int a1, int a2);
BOOL sub_40DB80(int a1, int a2);
int __stdcall sub_40DBB0(int a1);
int __stdcall sub_40DBE0(int a1, int a2);
int __stdcall sub_40DC10(int a1, int a2, int a3, int a4, int a5);
int __stdcall sub_40DC50(int a1, int a2);
int __stdcall sub_40DC60(int a1);
BOOL sub_40DC70();
BOOL sub_40DC90(int a1, int a2, int a3, int a4, int a5, int a6);
BOOL sub_40DCD0();
int __stdcall sub_40DD00(int a1, int a2, int a3, int a4, int a5);
int __stdcall sub_40DD10(int a1, int a2, int a3, int a4, int a5, int a6);
int __stdcall sub_40DD60(int a1, int a2);
int __stdcall sub_40DD70(int a1, int a2, int a3, const char* a4, const char* a5);
int __stdcall sub_40DE10(int a1, int a2, int a3, int a4);
int __stdcall sub_40DE90(int a1, int a2, int a3, int a4);
BOOL sub_40DEA0(int a1, int a2, int a3, int a4);
BOOL sub_40DED0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
BOOL sub_40DF20(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
BOOL sub_40DF60(int a1, int a2, int a3);
BOOL sub_40DF90();
BOOL sub_40DFC0(int a1, int a2);
BOOL sub_40DFE0(int a1, int a2, int a3, int a4, int a5, int a6);
BOOL sub_40E020(int a1, int a2, int a3, int a4);
BOOL sub_40E050(int a1, int a2);
void sub_40E070();
void sub_40E090();
void nox_xxx____setargv_0_40E0A0();
BOOL sub_40E0B0();
int sub_40E0C0();
int nox_common_getInstallPath_40E0D0(char* dst, const char* lpSubKey, int a3);
int __thiscall sub_40E3D0(int* this);
int __stdcall sub_40E3E0(_DWORD* a1);
char* __thiscall sub_40E470(char* this);
LONG __stdcall sub_40E490(int a1);
LONG __stdcall sub_40E4B0(volatile LONG* lpMem);
int __stdcall sub_40E4F0(int a1, _DWORD* a2, int* a3);
void __fastcall sub_40E5F0(_DWORD* a1);
int __stdcall sub_40E630(_DWORD* a1);
LONG __stdcall sub_40E680(volatile LONG* lpMem);
int __stdcall sub_40E6C0(int a1, _DWORD* a2, int* a3);
void __fastcall sub_40E7C0(_DWORD* a1);
int __stdcall sub_40E800(_DWORD* a1);
LONG __stdcall sub_40E850(volatile LONG* lpMem);
int __stdcall sub_40E890(int a1, _DWORD* a2, int* a3);
void __fastcall sub_40E990(_DWORD* a1);
int nox_xxx_netSendBySock_40EE10(unsigned int a1, int a2, unsigned int a3);
int nox_xxx_cliCanTalkMB_4100F0(__int16* a1);
BOOL sub_410120();
int nox_xxx_wall_410160();
int nox_xxx_mapAlloc_4101D0();
LPVOID nox_xxx_wallCreateAt_410250(int a1, int a2);
_BYTE* nox_xxx_doorAttachWall_410360(int a1, int a2, int a3);
_DWORD* sub_410390(int a1, int a2, int a3);
_DWORD* nox_xxx_mapDelWallAtPt_410430(int a1, int a2);
int* nox_xxx_wallDestroyedByWallid_410520(__int16 a1);
int sub_410550(__int16 a1);
void* nox_server_getWallAtGrid_410580(int a1, int a2);
int nox_xxx_wall_4105E0(int a1, int a2);
int sub_4106A0(int a1);
void sub_4106C0();
_DWORD* sub_410730();
_DWORD* nox_xxx_wallSecretBlock_410760(_DWORD* a1);
LPVOID nox_xxx_wallSecretGetFirstWall_410780();
int nox_xxx_wallSecretNext_410790(int* a1);
int* sub_4107A0(LPVOID lpMem);
_DWORD* nox_xxx_wallBreackableListClear_410810();
_DWORD* nox_xxx_wallBreackableListAdd_410840(int a1);
LPVOID nox_xxx_wallGetFirstBreakableCli_410870();
int nox_xxx_wallGetNextBreakableCli_410880(int* a1);
int* nox_xxx_wallBreakableRemove_410890(int* lpMem);
int nox_thing_read_WALL_410900(nox_memfile* f, char* a2);
char* sub_410D40(int a1);
int nox_xxx_wallTileByName_410D60(const char* a1);
unsigned __int8 nox_xxx_mapWallMaxVariation_410DD0(int a1, int a2, int a3);
unsigned __int8 nox_xxx_map_410E00(int a1);
unsigned __int8 nox_xxx_mapWallGetHpByTile_410E20(int a1);
unsigned __int8 nox_xxx_wallGetBrickTypeMB_410E40(int a1);
char* nox_xxx_wallGetBrickObj_410E60(int a1, int a2);
char* nox_xxx_wallSoundByTile_410EA0(int a1);
char* nox_xxx_wallFindOpenSound_410EE0(int a1);
char* nox_xxx_wallFindCloseSound_410F20(int a1);
int nox_xxx_tileAlloc_410F60_init();
void nox_xxx_tileFree_410FC0_free();
int nox_xxx_tileUnusedMB_410FF0();
int nox_xxx_tileNFromPoint_411160(float2* a1);
int sub_411350(int* a1, int* a2, int a3);
int sub_4113A0(int* a1, int a2);
int sub_411490(int a1, int a2);
int nox_thing_read_FLOR_411540(nox_memfile* f, _BYTE* a2);
int nox_xxx_checkFacade_4117E0(const char* a1);
int nox_thing_read_EDGE_411850(nox_memfile* f, _BYTE* a2);
BOOL nox_xxx_mapTileAllowTeleport_411A90(float2* a1);
BOOL nox_xxx_parseWeapColor_411C40(const char* a1, char* a2, int a3);
int sub_411C80(const char* a1);
char* nox_xxx_parseBinColor_411CF0(char* a1, _BYTE* a2);
BOOL sub_411D90(const char* a1, char* a2, int a3);
int sub_411E60(int a1, char* a2, int a3);
char* sub_411ED0(int a1, char* a2, int a3);
char* sub_411F20(int a1, char* a2, int a3);
char* sub_411F70(int a1, char* a2, int a3);
char* sub_411FC0(int a1, char* a2, int a3);
const char* nox_xxx_parseWeapDamageType_412010(int a1, char* a2, int a3);
char* sub_412060(int a1, char* a2, int a3);
char* sub_4120B0(int a1, char* a2, int a3);
int nox_xxx_parseEnchWorth_412310_parse_worth(const char* a1, char* a2, obj_412ae0_t* a3);
int nox_xxx_parseEnchColor_412360_parse_color(const char* a1, char* a2, obj_412ae0_t* a3);
int nox_xxx_parseEnchEffect_412380_parse_attack_effect(const char* a1, char* a2, obj_412ae0_t* obj);
int nox_xxx_parseEnchDefend_412490_parse_defend_effect(const char* a1, char* a2, obj_412ae0_t* obj);
int nox_xxx_parseEnchEngageOrDisEng_412580_parse_engage_effect(const char* a1, char* a2, obj_412ae0_t* obj);
int nox_xxx_parseEnchUpdate_412670_parse_update_effect(const char* a1, char* a2, obj_412ae0_t* obj);
int nox_xxx_parseEnchAllowedWeapon_412740_parse_allowed_weapons(const char* a1, char* a2, obj_412ae0_t* a3);
int nox_xxx_parseAllowedWeaponArmor_412760(char* a1, int* a2);
int nox_xxx_parseEnchAllowedArmor_4128A0_parse_allowed_armor(const char* a1, char* a2, obj_412ae0_t* a3);
int nox_xxx_parseAllowedPosition_4128C0_parse_allowed_pos(const char* a1, char* a2, obj_412ae0_t* a3);
int nox_xxx_parseModifierBin_412930(char* a1, char* a2);
int nox_xxx_parseModifDesc_412AE0(const char* a1, FILE* a2, char* a3);
int nox_xxx_parseModifAddByType_412C60(const char* a1, obj_412ae0_t* a2);
int nox_xxx_parseWeaponDef_412D40(int a1, FILE* a2, char* a3);
int sub_412ED0(int a1, FILE* a2, char* a3);
void nox_xxx_freeWeaponArmorDefAndModifs_413060();
void sub_4130C0(LPVOID lpMem);
void sub_413100(LPVOID lpMem);
void nox_xxx_modifFreeOne_413140(LPVOID lpMem);
_DWORD* nox_xxx_getProjectileClassById_413250(int a1);
_DWORD* nox_xxx_equipClothFindDefByTT_413270(int a1);
int nox_xxx_modifGetIdByName_413290(const char* a1);
int sub_413300(int a1);
obj_412ae0_t* nox_xxx_modifGetDescById_413330(int a1);
LPVOID sub_413370();
int sub_413380(int a1);
LPVOID sub_413390();
int sub_4133A0(int a1);
obj_412ae0_t* nox_xxx_modifGetModifListByType_4133B0(int a1);
obj_412ae0_t* nox_xxx_modifNext_4133C0(obj_412ae0_t* a1);
BOOL sub_4133D0(int a1);
int sub_413420(char a1);
int sub_4134D0();
void sub_4134F0();
void sub_413760();
void sub_413780();
BOOL sub_4137A0();
int sub_4137C0();
int sub_4137E0();
void nox_game_cdMaybeSwitchState_413800();
BOOL nox_xxx_testCD_413830();
BOOL nox_xxx_testCDAndSolo_413840();
int sub_413850();
BOOL sub_413870(int a1);
char* sub_413890();
void sub_4138E0(int a1);
void sub_413900(int a1);
int sub_413920();
void sub_413960();
BOOL sub_4139B0();
void sub_413A00(int a1);
BOOL nox_xxx_checkGameFlagPause_413A50();
int sub_413E10();
void nox_xxx_gameLoopMemDump_413E30();
int sub_413F60(const void* a1, const void* a2);
char* nox_clone_str(const char* a1);
int sub_4144B0(int a1);
int sub_414580();
int sub_414590();
int sub_4145A0();
int sub_4145B0();
void* sub_4145C0(size_t a1, size_t a2);
void sub_4145E0(LPVOID lpMem);
int nox_readHiddenCode_4145F0(char* a1);
int sub_414800();
unsigned int sub_4148D0(LPCSTR lpFileName);
int sub_4149A0(LPCSTR lpFileName, LPVOID lpBuffer, LPVOID a3, LPVOID a4);
int nox_common_getRegistryValue_414A40(LPCSTR lpSubKey, LPCSTR lpValueName);
int nox_common_setRegistryValue_414A90(LPCSTR lpSubKey, LPCSTR lpValueName, BYTE* lpData);
char* nox_common_convertWideToMbString_414B00(LPCWSTR lpWideCharStr, LPSTR lpMultiByteStr, int cbMultiByte);
void nox_common_readHiddenExeMsg_414B30(uint8_t* src_8byte, uint8_t* dst_12byte);
int sub_414BA0(int a1);
int sub_414BD0(signed int a1);
int sub_414C50(signed int a1);
char nox_xxx_initSinCosTables_414C90();
int nox_thing_skip_AUD_414D40(nox_memfile* f);
BOOL nox_thing_read_FLOR_414DB0(nox_memfile* f);
BOOL nox_thing_read_EDGE_414E70(int a1, void* a2);
BOOL nox_thing_read_WALL_414F60(_DWORD* a1, void* a2);
int nox_thing_skip_spells_415100(int a1);
int nox_thing_read_image_415240(int a1);
int nox_thing_read_ability_415320(int a1);
bool nox_xxx_loadAllBinFiles_415470(void);
int nox_thing_read_audio_415660(int a1, char* a2);
int nox_thing_read_SPEL_4156B0(nox_memfile* f, void* a2);
int nox_thing_read_IMAG_415700(nox_memfile* f, char* buf);
int nox_thing_read_ABIL_415750(nox_memfile* f, void* a2);
int nox_xxx_weaponInventoryEquipFlags_415820(nox_object_t* item);
int sub_415840(char* a1);
int nox_xxx_ammoCheck_415880(unsigned short typ_ind);
int sub_415910(char* a1);
int sub_415960(wchar_t* a1);
char* sub_4159B0(char* a1);
int sub_4159F0(int a1);
int sub_415A30(char* a1);
int sub_415B20(char* a1);
double sub_415BD0(int a1);
double nox_xxx_itemApplyDefendEffect_415C00(int a1);
int nox_xxx_unitArmorInventoryEquipFlags_415C70(nox_object_t* item);
int sub_415C90(const nox_object_t* item);
int sub_415CD0(char* a1);
int sub_415D10(char* a1);
int sub_415DA0(wchar_t* a1);
int sub_415DF0(char* a1);
char* sub_415E40(char* a1);
int sub_415E80(int a1);
int sub_415EC0(char* a1);
int nox_xxx_setKeybTimeout_4160D0(int a1);
bool nox_xxx_checkKeybTimeout_4160F0(unsigned __int8 a1, unsigned int a2);
bool sub_416120(unsigned __int8 a1);
int sub_416150(int a1, int a2);
int sub_416170(int a1);
int nox_xxx_clear18hDD_416190();
BOOL sub_4161B0(unsigned __int8 a1);
int sub_4161E0();
void sub_4164F0();
void nox_xxx_mapSetDataDefault_416500();
int sub_416580();
char* nox_xxx_cliGamedataGet_416590(int a1);
char* sub_4165B0();
char* sub_4165D0(int a1);
int sub_4165F0(int a1, int a2);
char* sub_416630();
void* sub_416640();
int sub_416650();
int sub_416670(int a1);
void sub_416690();
void sub_416720();
int* sub_416770(int a1, wchar_t* a2, const char* a3);
void sub_416820(int a1);
int* sub_416860(int a1);
int* sub_4168A0(wchar_t* a1);
int* sub_4168E0();
int* sub_4168F0(int* a1);
int* sub_416900();
int* sub_416910(int* a1);
int sub_416920();
int* sub_416950();
int sub_4169C0();
int nox_xxx_cliSetSettingsAcquired_4169D0(int a1);
char* sub_4169E0();
char* sub_4169F0();
unsigned int sub_416A00();
void nox_framerate_limit_416C70(int fps);
bool nox_ticks_should_update_416CD0();
__int64 nox_ticks_until_next_416D00();
void nox_ticks_reset_416D40();
bool nox_ticks_check_416D70();
void nox_ticks_maybe_sleep_416DD0();
void nox_xxx_cliResetAllPlayers_416E30();
char* nox_xxx_playerForceSendLessons_416E50(int a1);
nox_playerInfo* nox_common_playerInfoGetFirst_416EA0();
nox_playerInfo* nox_common_playerInfoGetNext_416EE0(nox_playerInfo* p);
int nox_common_playerInfoCount_416F40();
nox_playerInfo* nox_common_playerInfoNew_416F60(int a1);
void nox_common_playerInfoReset_416FD0(nox_playerInfo* p);
nox_playerInfo* nox_common_playerInfoResetInd_417000(int i);
nox_playerInfo* nox_common_playerInfoGetByID_417040(int a1);
nox_playerInfo* nox_common_playerInfoFromNum_417090(int i);
char* nox_xxx_playerByName_4170D0(wchar_t* a1);
wchar_t* sub_417120(int a1);
int nox_xxx_netMarkMinimapObject_417190(int a1, int a2, int a3);
int sub_417270(int a1);
int sub_4172C0(int a1);
int nox_xxx_netUnmarkMinimapObj_417300(int a1, int a2, int a3);
int nox_xxx_playerMapTracksObj_4173D0(int a1, int a2);
char* nox_xxx_netMinimapUnmark4All_417430(int a1);
char* nox_xxx_netUnmarkMinimapSpec_417470(int a1, int a2);
char* nox_xxx_netMarkMinimapForAll_4174B0(int a1, int a2);
int nox_xxx_netNeedTimestampStatus_4174F0(int a1, int a2);
char nox_xxx_playerUnsetStatus_417530(int a1, int a2);
char* nox_xxx_sendAllClientStatus_4175C0(int a1);
int nox_xxx_netReportPlayerStatus_417630(int a1);
void nox_xxx_cliPlayerRespawn_417680(int a1, char a2);
char* nox_xxx_clientEquipWeaponArmor_417AA0(char a1, int a2, int a3, int a4);
char* sub_417B80(char a1, int a2, int a3);
char* sub_417C00(char* a1, int a2);
int sub_417CF0();
int sub_417D00();
int nox_xxx_SetGameplayFlag_417D50(int a1);
int nox_xxx_UnsetGameplayFlags_417D70(int a1);
int nox_xxx_GetGameplayFlags_417D90();
BOOL nox_xxx_CheckGameplayFlags_417DA0(int a1);
int sub_417DC0();
unsigned __int8 nox_xxx_getTeamCounter_417DD0();
char sub_417DE0();
int nox_xxx_mapInfoSetCapflag_417EA0();
bool sub_417EC0();
char nox_xxx_mapInfoSetFlagball_417F30();
int sub_417F50(int a1);
int nox_xxx_mapInfoSetKotr_4180D0();
void sub_4181F0(int a1);
int sub_418390();
int sub_4183C0();
void sub_4184D0(wchar_t* a1);
int nox_xxx_wndGuiTeamCreate_4185B0();
int nox_xxx_teamAssignFlags_418640();
char* nox_xxx_toggleAllTeamFlags_418690(int a1);

int __stdcall sub_40E260(int(__stdcall*** a1)(_DWORD, void*, int*), int a2, int a3, int a4);
int __stdcall sub_40E320(int(__stdcall*** a1)(_DWORD, void*, int*), int a2, int a3);
int nox_xxx_wallForeachFn_410640(void(* a1)(int, int), int a2);
int sub_410670(void(* a1)(int, int), int a2);
char sub_414690(unsigned int* a1, void(__stdcall* a2)(char*));

#endif // NOX_PORT_GAME1
