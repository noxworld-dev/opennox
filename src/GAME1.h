#ifndef NOX_PORT_GAME1
#define NOX_PORT_GAME1

#include "defs.h"
#include "common__system__team.h"

extern int nox_server_gameSettingsUpdated;

void nox_common_setEngineFlag(const nox_engine_flag flags);
void nox_common_resetEngineFlag(const nox_engine_flag flags);
bool nox_common_getEngineFlag(const nox_engine_flag flags);
void nox_xxx_parseRead_4093E0(FILE* a1, char* a2, int a3);
int nox_xxx_parseString_409470(FILE* a1, uint8_t* a2);
int sub_409A70(short a1);
unsigned short nox_client_getVersionBuild_409AC0();
unsigned int nox_client_getVersionCode_409AD0();
void nox_client_setVersion_409AE0(unsigned int vers);
int nox_xxx_mapCrcGetMB_409B00();
int nox_xxx_mapSetCrcMB_409B10(int a1);
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
const char* nox_xxx_servStartCountdown_40A2A0(int a1, const char* a2);
int sub_40A300();
long long sub_40A310(int a1);
void nox_xxx_set3512_40A340(int a1);
int nox_xxx_get3512_40A350();
void nox_xxx_setMapCRC_40A360(int crc);
unsigned int sub_40A3C0(unsigned int a1);
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
int nox_xxx_countNonEliminatedPlayersInTeam_40A830(int a1);
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
void nox_xxx_soloGameEscMenuCallback_40AF90(int a1, int a2, char a3, int a4, uint8_t* a5, unsigned int a6);
int sub_40B170(int a1);
char* sub_40B1F0(unsigned char a1);
void sub_40B250(int a1, unsigned char a2, unsigned short a3, const void* a4, size_t a5);
int nox_xxx_netXfer_40B4B0(unsigned int a1, char a2);
int sub_40B4E0(unsigned char a1);
char* sub_40B530(unsigned char a1, char a2);
int nox_xxx_neXfer_40B590(unsigned int a1, char a2, char a3);
int sub_40B5D0(unsigned int a1, char a2, const char* a3, size_t a4, char a5);
int sub_40B690(unsigned int a1, char a2, char a3);
char* sub_40B6D0(uint8_t* a1);
char* sub_40B720(int a1, unsigned char a2);
void sub_40B740();
int sub_40B790();
void sub_40B810(int a1, int a2, int a3);
void sub_40B850(int a1, char a2);
void* sub_40B890(int a1);
int sub_40B930(int a1);
void sub_40B970();
int sub_40BA90(unsigned int a1, char a2, short a3, short a4, const void* a5);
char* sub_40BB20(unsigned int a1, int a2, char a3);
void sub_40BBC0(int a1, char a2);
char* sub_40BC10(int a1, char a2);
int sub_40BC60(int a1, int a2, const char* a3, void* a4, int a5, int a6);
int nox_xxx_netXferMsg_40BE80(unsigned int a1, char a2, const char* a3, int a4, char a5);
char* sub_40BF10(uint8_t* a1);
char* sub_40BF60(int a1, char a2, int a3);
char* sub_40BFF0(int a1, char a2, char* a3);
char* sub_40C030(int a1, char a2);
char* sub_40C070(int a1, int a2, char a3);
void sub_40C0D0();
void sub_40C0E0(int a1);
int sub_40C140(int a1, int a2, uint32_t* a3);
int sub_40C1B0(int a1, int a2, int a3);
int sub_40C1F0(int a1, int a2, const void* a3);
int sub_40C240(int a1, int a2, int a3);
int sub_40C2E0(int a1, int a2, int a3, const char* a4);
int sub_40C420(int a1, int a2, int a3, int* a4);
int sub_40C4E0(int a1, int a2, int a3, int a4);
int sub_40C4F0(int a1, int a2, int a3);
int sub_40C500(int a1, int a2, int a3);
int sub_40C510(int a1, int a2, int a3);
int sub_40C520(int a1, int a2, int a3);
int sub_40C530(int a1, int a2, int a3, uint8_t* a4);
int sub_40C580(int a1, int a2, int a3, int a4, uint8_t* a5);
int sub_40C5C0(int a1, int a2, int a3, int a4, uint8_t* a5);
int sub_40C600(int a1, int a2, int a3, uint8_t* a4);
int sub_40C650(int a1, int a2, int a3, int a4);
int sub_40C660(int a1, int a2, int a3, int a4, int a5);
int sub_40C670(int a1, int a2, int a3, int a4, int a5);
int sub_40C690(int a1, int a2, int a3, int a4, int a5);
int sub_40C710(int a1, int a2, int a3);
int sub_40C720(int a1, int a2, uint32_t* a3);
int sub_40C7A0(int a1, int a2);
int sub_40C7D0(int a1, int a2, int a3, uint8_t* a4);
int sub_40C830(int a1, int a2, int a3);
int sub_40C880(int a1, int a2, const char* a3, int a4, int a5);
int sub_40C8C0(int a1, int a2, int a3, int a4);
int sub_40C8F0(int a1, int a2, int a3, int a4);
int sub_40C960(int a1, int a2, uint32_t* a3);
int sub_40C9D0(int a1, int a2, int* a3);
int sub_40CA40(int a1, int a2);
int sub_40CA50(int a1, int a2);
int sub_40CA60(int a1, int a2, const void* a3);
int sub_40CB90(int a1, int a2, int a3);
int sub_40CBA0(int a1, int a2, int a3);
int sub_40CBE0(int a1, int a2);
int sub_40CD00();
int sub_40CD50(int a1, int a2, int a3);
int nox_xxx_somejoinproc_40CD60(int a1, int a2, int a3);
int sub_40CDC0(int a1, int a2, int a3, int a4);
void sub_40D0F0();
int sub_40D250();
int sub_40D280(int a1, int a2, int a3, int a4, int a5);
int sub_40D2C0(int a1, int a2, int a3);
int sub_40D2F0(int a1, int a2);
int sub_40D320(int a1);
int sub_40D350(int a1);
void sub_40D380();
int sub_40D3B0();
int sub_40D3E0(int a1);
int sub_40D410(int a1, int a2);
int sub_40D440();
int sub_40D4D0(int a1);
int sub_40D500(int a1, int a2);
int sub_40D530(int a1);
int sub_40D560(int a1);
int sub_40D5B0(int a1);
int sub_40D670(int a1);
int sub_40D740(int a1);
int sub_40D770(int a1, int a2);
int sub_40D7A0(int a1, int a2);
int sub_40D7D0(int a1, int a2);
int sub_40D890(int a1);
int sub_40D950(int a1);
int sub_40D980(int a1, int a2, int a3);
int sub_40D9C0(int a1, int a2, int a3, int a4);
int sub_40DA90(int a1, int a2);
int sub_40DB20(int a1);
int sub_40DB50(int a1, int a2);
int sub_40DB80(int a1, int a2);
int sub_40DBB0(int a1);
int sub_40DBE0(int a1, int a2);
int sub_40DC10(int a1, int a2, int a3, int a4, int a5);
int sub_40DC50(int a1, int a2);
int sub_40DC60(int a1);
int sub_40DC70();
int sub_40DC90(int a1, int a2, int a3, int a4, int a5, int a6);
int sub_40DCD0();
int sub_40DD00(int a1, int a2, int a3, int a4, int a5);
int sub_40DD10(int a1, int a2, int a3, int a4, int a5, int a6);
int sub_40DD60(int a1, int a2);
int sub_40DD70(int a1, int a2, int a3, const char* a4, const char* a5);
int sub_40DE10(int a1, int a2, int a3, int a4);
int sub_40DE90(int a1, int a2, int a3, int a4);
int sub_40DEA0(int a1, int a2, int a3, int a4);
int sub_40DF20(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
int sub_40DF90();
int sub_40DFE0(int a1, int a2, int a3, int a4, int a5, int a6);
int sub_40E020(int a1, int a2, int a3, int a4);
void sub_40E090();
void sub_40E0A0();
int sub_40E0B0();
int sub_40E0C0();
int sub_40E490(int a1);
int sub_40E4B0(volatile int* lpMem);
int sub_40E4F0(int a1, uint32_t* a2, int* a3);
void sub_40E5F0(uint32_t* a1);
int sub_40E680(volatile int* lpMem);
int sub_40E6C0(int a1, uint32_t* a2, int* a3);
void sub_40E7C0(uint32_t* a1);
int sub_40E850(volatile int* lpMem);
int sub_40E890(int a1, uint32_t* a2, int* a3);
void sub_40E990(uint32_t* a1);
int nox_xxx_netSendBySock_40EE10(unsigned int a1, int a2, unsigned int a3);
int nox_xxx_cliCanTalkMB_4100F0(short* a1);
void nox_xxx_wall_410160();
void* nox_xxx_wallCreateAt_410250(int a1, int a2);
uint8_t* nox_xxx_doorAttachWall_410360(int a1, int a2, int a3);
uint32_t* sub_410390(int a1, int a2, int a3);
uint32_t* nox_xxx_mapDelWallAtPt_410430(int a1, int a2);
int* nox_xxx_wallDestroyedByWallid_410520(short a1);
int sub_410550(short a1);
void* nox_server_getWallAtGrid_410580(int a1, int a2);
void* nox_xxx_wall_4105E0(int a1, int a2);
int sub_4106A0(int a1);
void sub_4106C0();
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
int nox_xxx_parseWeapColor_411C40(const char* a1, char* a2, int a3);
int sub_411C80(const char* a1);
char* nox_xxx_parseBinColor_411CF0(char* a1, uint8_t* a2);
int sub_411D90(const char* a1, char* a2, int a3);
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
void sub_4130C0(void* lpMem);
void sub_413100(void* lpMem);
void nox_xxx_modifFreeOne_413140(void* lpMem);
uint32_t* nox_xxx_getProjectileClassById_413250(int a1);
uint32_t* nox_xxx_equipClothFindDefByTT_413270(int a1);
int nox_xxx_modifGetIdByName_413290(const char* a1);
obj_412ae0_t* nox_xxx_modifGetDescById_413330(int a1);
void* sub_413370();
int sub_413380(int a1);
void* sub_413390();
int sub_4133A0(int a1);
obj_412ae0_t* nox_xxx_modifGetModifListByType_4133B0(int a1);
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
char* nox_clone_str(const char* a1);
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
int sub_415840(char* a1);
int nox_xxx_ammoCheck_415880(unsigned short typ_ind);
int sub_415910(char* a1);
int sub_415960(wchar_t* a1);
char* sub_4159B0(char* a1);
int sub_4159F0(int a1);
int sub_415A30(char* a1);
double sub_415BD0(int a1);
double nox_xxx_itemApplyDefendEffect_415C00(int a1);
int nox_xxx_unitArmorInventoryEquipFlags_415C70(nox_object_t* item);
int sub_415C90(const nox_object_t* item);
int sub_415CD0(char* a1);
int sub_415D10(int a1);
int sub_415DA0(wchar_t* a1);
int sub_415DF0(char* a1);
char* sub_415E40(char* a1);
int sub_415E80(int a1);
int sub_415EC0(char* a1);
int nox_xxx_setKeybTimeout_4160D0(int a1);
bool nox_xxx_checkKeybTimeout_4160F0(unsigned char a1, unsigned int a2);
bool sub_416120(unsigned char a1);
int sub_416150(int a1, int a2);
int sub_416170(int a1);
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
void nox_ticks_reset_416D40();
char* nox_xxx_playerForceSendLessons_416E50(int a1);
nox_playerInfo* nox_common_playerInfoGetFirst_416EA0();
nox_playerInfo* nox_common_playerInfoGetNext_416EE0(nox_playerInfo* p);
int nox_common_playerInfoCount_416F40();
nox_playerInfo* nox_common_playerInfoNew_416F60(int a1);
nox_playerInfo* nox_common_playerInfoGetByID_417040(int a1);
nox_playerInfo* nox_common_playerInfoFromNum_417090(int i);
nox_playerInfo* nox_common_playerInfoFromNumRaw(int i);
char* nox_xxx_playerByName_4170D0(wchar_t* a1);
int nox_xxx_netMarkMinimapObject_417190(int a1, int a2, int a3);
int sub_417270(int a1);
int sub_4172C0(int a1);
int nox_xxx_netUnmarkMinimapObj_417300(int a1, int a2, int a3);
int nox_xxx_playerMapTracksObj_4173D0(int a1, int a2);
char* nox_xxx_netMinimapUnmark4All_417430(int a1);
char* nox_xxx_netUnmarkMinimapSpec_417470(int a1, int a2);
char* nox_xxx_netMarkMinimapForAll_4174B0(int a1, int a2);
int nox_xxx_netNeedTimestampStatus_4174F0(int a1, int a2);
char nox_xxx_playerUnsetStatus_417530(nox_playerInfo* a1, int a2);
char* nox_xxx_sendAllClientStatus_4175C0(int a1);
int nox_xxx_netReportPlayerStatus_417630(nox_playerInfo* pl);
void nox_xxx_cliPlayerRespawn_417680(int a1, char a2);
char* nox_xxx_clientEquipWeaponArmor_417AA0(char a1, int a2, int a3, int a4);
char* sub_417B80(char a1, int a2, int a3);
char* sub_417C00(char* a1, int a2);
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

int sub_40E320(int (***a1)(uint32_t, void*, int*), int a2, int a3);
int nox_xxx_wallForeachFn_410640(void (*a1)(int, int), int a2);

#endif // NOX_PORT_GAME1
