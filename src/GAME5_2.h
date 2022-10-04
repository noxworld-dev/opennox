#ifndef NOX_PORT_GAME5_2
#define NOX_PORT_GAME5_2

#include "defs.h"

int sub_42CC50(void** this);
void sub_448640(void);
int nox_xxx_j_inventoryNameSignInit_467460(void);
int nullsub_8(int a1, int a2);
void nullsub_9(uint32_t a1);
void nullsub_10(uint32_t a1);
void nox_xxx_j_resetNPCRenderData_49A2E0(void);
void nox_alloc_npcs_2();
void nullsub_22(void);
void nullsub_36(void);
void nullsub_35(uint32_t a1, uint32_t a2);
void nullsub_24(uint32_t a1);
void nox_xxx_j_allocHitArray_511840(void);
void nullsub_27(uint32_t a1);
void nullsub_28(uint32_t a1);
void nullsub_29(void);
void nullsub_30(uint32_t a1);
int nox_xxx_netSendReadPacket_5528B0(int a1, unsigned char a2);
int nox_xxx_servNetInitialPackets_552A80(unsigned int id, char flags);
int sub_552E70(unsigned int a1);
int nox_xxx_netBigSwitch_553210(unsigned int id, unsigned char* packet, int packetSz, void* outb, struct nox_net_sockaddr_in* from);
int sub_553D10();
int sub_553D30(struct nox_net_sockaddr_in* addr);
void sub_553F40(int a1, int a2);
void nox_xxx_netCountData_554030(int a1, int a2);
unsigned int nox_server_makeServerInfoPacket_554040(const char* inBuf, int inSz, char* out);
void* nox_xxx_findPlayerID_5541D0(int a1);
int nox_xxx_net_getIP_554200(unsigned int a1);
char* sub_554230();
int sub_554240(int a1);
unsigned int sub_554290();
int sub_554300();
short sub_5545A0();
int nox_xxx_netStructReadPackets_5545B0(unsigned int a1);
int nox_xxx_createSocketLocal_554B40(uint16_t hostshort);
int sub_554D10();
int sub_5550D0(int a1, uint16_t hostshort, char* buf);
int sub_555130(int a1, void* a2, int a3);
int sub_555250(unsigned int a1, uint32_t* a2);
int sub_555290(unsigned int a1, uint32_t* a2);
int nox_xxx_netSend_5552D0(unsigned int a1, char a2, int a3);
int sub_555360(unsigned int a1, unsigned char a2, int a3);
void nullsub_31(uint32_t a1);
int sub_56F1C0();
int nox_xxx_protect_56F240();
int sub_56F250();
int nox_xxx_protectionCreateStructForInt_56F280(int a1, int a2);
int sub_56F2F0(uint32_t* a1);
uint32_t* sub_56F3B0();
int nox_xxx_protectionCreateInt_56F400(int a1);
int nox_xxx_protectionCreateStructForFloat_56F480(int a1, float a2);
int sub_56F4F0(int* a1);
int sub_56F510(int a1);
uint32_t* sub_56F590(int a1);
int nox_xxx_protectData_56F5C0();
uint32_t* sub_56F6F0(int a1);
void sub_56F720(int* a1, int* a2);
uint32_t* sub_56F780(int a1, int a2);
uint32_t* nox_xxx_playerResetProtectionCRC_56F7D0(int a1, int a2);
uint32_t* sub_56F820(int a1, unsigned char a2);
uint32_t* nox_xxx_protectPlayerHPMana_56F870(int a1, unsigned short a2);
uint32_t* sub_56F8C0(int a1, float a2);
uint32_t* sub_56F920(int a1, int a2);
uint32_t* nox_xxx_protectMana_56F9E0(int a1, short a2);
uint32_t* sub_56FA40(int a1, float a2);
int nox_xxx_protectionStringCRC_56FAC0(int* a1, unsigned int a2);
int nox_xxx_protectionStringCRCLen_56FAE0(int* a1, unsigned int a2);
int sub_56FB00(int* a1, unsigned int a2, int a3);
int sub_56FB60(nox_object_t* item);
int nox_xxx_protect_56FBF0(int a1, nox_object_t* item);
int nox_xxx_protect_56FC50(int a1, const nox_object_t* object);
int sub_56FCB0(int a1, int a2);
int nox_xxx_playerAwardSpellProtectionCRC_56FCE0(int a1, int a2, int a3);
int nox_xxx_playerApplyProtectionCRC_56FD50(int a1, void* a2, int a3);
double nox_xxx_unkDoubleSmth_56FE30();
void sub_56FF00(int a1);
int sub_56FF80(int a1, int a2);
unsigned int nox_xxx_netGetUnitCodeServ_578AC0(nox_object_t* item);
unsigned int nox_xxx_netGetUnitCodeCli_578B00(int a1);
int nox_xxx_netClearHighBit_578B30(short a1);
int nox_xxx_packetDynamicUnitCode_578B40(int a1);
unsigned int nox_xxx_netTestHighBit_578B70(unsigned int a1);
uint32_t* sub_578B80();
unsigned int sub_578BA0(unsigned int a1);
int sub_578BB0(void** a1, int a2, unsigned char* a3, int a4);
void sub_578BD0(void* lpMem);
uint32_t* sub_578BF0();
int nox_xxx_nxzDecompress_578C10(uint32_t* a1, uint8_t* a2, uint32_t* a3, unsigned int a4, uint32_t* a5);
void sub_578C40(void* lpMem);
char* nox_xxx_GetEndgameDialog_578D80();
void* nox_xxx_waypointGetList_579860();
int nox_xxx_waypointNext_579870(int a1);
int sub_579890();
int sub_5798A0(int a1);
unsigned int nox_xxx_waypoint_5798C0();
uint32_t* nox_xxx_waypointNew_5798F0(float a1, float a2);
float* nox_xxx_waypointNewNotMap_579970(int a1, float a2, float a3);
char* nox_xxx_waypoint_5799C0();
char* sub_579A30();
float* sub_579AD0(float a1, float a2);
uint32_t* nox_server_getWaypointById_579C40(int a1);
int sub_579C60(int a1);
uint32_t* sub_579C80(int a1);
int sub_579CA0();
int sub_579D20();
void nox_xxx_waypointDeleteAll_579DD0();
const char* nox_xxx_waypointByName_579E30(const char* a1);
uint32_t* sub_579E70();
void sub_579E90(int a1);
int sub_579EE0(int a1, unsigned char a2);
int nox_xxx_waypoint_579F00(uint32_t* a1, int a2);
int nox_xxx_playerCanTalkMB_57A160(int a1);
int nox_xxx_giant_57A190(int a1);
char* sub_57A1B0(short a1);
char sub_57A1E0(int* a1, const char* a2, int* a3, char a4, short a5);
int sub_57A3F0(char* a1, int a2, int a3, int a4);
void sub_57A4D0(wchar_t* a1, int a2, int a3, int a4);
int sub_57A620(unsigned char a1, const wchar_t** a2, int a3, int a4);
int sub_57A950(char* a1);
int sub_57A9F0(const char* a1, const char* a2);
char sub_57AAA0(const char* a1, char* a2, int* a3);
int* sub_57ADF0(int* a1);
int sub_57AE30(const char* a1);
int nox_xxx_playerCheckSpellClass_57AEA0(int a1, int a2);
int sub_57AEE0(int a1, int a2);
int nox_xxx_get_57AF20();
void sub_57B0A0();
long long nox_xxx___Getcvt_57B180();
int sub_57B190(unsigned short a1, unsigned short a2);
float* sub_57B350();
float* nox_xxx_plrGetMaxVarsPtr_57B360(int a1);
char sub_57B370(int a1, unsigned char a2, int a3);
int nox_xxx_playerClassCanUseItem_57B3D0(nox_object_t* item, char a2);
int nox_xxx_client_57B400(int a1);
int sub_57B450(nox_drawable* a1p);
int sub_57B4D0(int a1);
char sub_57B500(int a1, int a2, char a3);
char sub_57B630(int a1, int a2, int a3);
float2* sub_57B770(float2* a1, float2* a2);
int nox_xxx_collideReflect_57B810(float* a1, int a2);
int nox_xxx_map_57B850(float2* a1, float* a2, float2* a3);
int sub_57B920(void* a1);
char sub_57B930(int a1, int a2, int a3, unsigned int a4);
char nox_xxx_cliGenerateAlias_57B9A0(int a1, int a2, int a3, unsigned int a4);
int sub_57BA10(int a1, short a2, short a3, int a4);
int sub_57BA30(int2* a1, int2* a2, int4* a3);
int nox_xxx_mapNxzDecompress_57BC50(char* a1, char* a2);
int nox_xxx_mapFile_57BDD0(void* lpMem, int a2);
unsigned int sub_57BF80();
int nox_xxx_allocGroupRelatedArrays_57BFB0();
void sub_57C000();
int sub_57C030();
int nox_server_getFirstMapGroup_57C080();
int nox_server_getNextMapGroup_57C090(int a1);
int nox_server_scriptGetGroup_57C0A0(int a1);
int nox_server_mapLoadAddGroup_57C0C0(char* a1, int a2, char a3);
int sub_57C130(uint32_t* a1, int a2);
void* nox_server_scriptGetMapGroupByName_57C280(const char* a1, int a2);
void* sub_57C330();
void* sub_57C360();
void sub_57C370(uint64_t* a1);
void sub_57C390(uint64_t* a1);
int nox_server_addNewMapGroup_57C3B0(int a1);
void sub_57C790(float4* a1, float2* a2, float2* a3, float a4);
int nox_xxx_mathPointOnTheLine_57C8A0(float4* a1, float2* a2, float2* a3);
int sub_57CDB0(int2* a1, float* a2, float2* a3);
void sub_57D150(void** this);
int sub_57D1C0(void** this, int a2, unsigned char* a3, int a4);
uint32_t* sub_57DD90(uint32_t* this);
void sub_57DDC0(void** this);
unsigned int sub_57DDE0(int a1, int a2);
int sub_57DEA0(uint32_t* this, uint16_t* a2);
uint32_t* sub_57DF00(uint32_t* this);
void sub_57DF70(void** this);
int sub_57DFC0(uint32_t* this, int* a2);
int sub_57E2C0(uint32_t** this);
unsigned int sub_57E3F0(uint32_t** this, unsigned int a2, int a3);
int sub_57E4C0(uint32_t** this, unsigned int a2, int a3, unsigned int a4, unsigned int a5);
int sub_57E7D0(uint32_t** this);
uint32_t* sub_57E8A0(uint32_t* this);
void sub_57E910(void** this);
uint32_t* sub_57E9A0(uint32_t* this);
void sub_57EA00(void** this);
int nox_xxx_nxzDecompressImpl_57EA80(uint32_t* this, uint8_t* a2, uint32_t* a3, unsigned int a4, uint32_t* a5);
uint32_t* sub_57F160(int this, int a2, int a3);
char sub_57F1D0(float2* a1);
int sub_57F2A0(float2* a1, int a2, int a3);

#endif // NOX_PORT_GAME5_2
