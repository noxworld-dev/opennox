#ifndef NOX_PORT_COMMON_TEAM
#define NOX_PORT_COMMON_TEAM

#include "static_assert.h"
#include "defs.h"

#define NOX_TEAMS_MAX 17

typedef struct {
	uint16_t field_0; // 0, 0
	uint16_t field_2; // 0, 2
	uint32_t field_4; // 1, 4
	uint32_t field_8; // 2, 8
	uint32_t field_12; // 3, 12
	uint32_t field_16; // 4, 16
	uint32_t field_20; // 5, 20
	uint32_t field_24; // 6, 24
	uint32_t field_28; // 7, 28
	uint32_t field_32; // 8, 32
	uint32_t field_36; // 9, 36
	uint32_t field_40; // 10, 40
	uint32_t field_44; // 11, 44
	uint32_t field_48; // 12, 48
	uint32_t field_52; // 13, 52
	uint8_t  field_56; // 14, 56 TODO: same as ind?
	uint8_t  field_57; // 14, 57
	uint8_t  ind; // 14, 58
	uint8_t  field_59; // 14, 59
	uint32_t field_60; // 15, 60 TODO: id? net code?
	uint32_t active; // 16, 64
	uint32_t field_68; // 17, 68
	uint32_t field_72; // 18, 72
	uint32_t field_76; // 19, 76
} nox_team_t;
_Static_assert(sizeof(nox_team_t) == 80, "wrong size of nox_team_t structure!");

nox_team_t* nox_server_teamByXxx_418AE0(int a1);
nox_team_t* nox_server_teamFirst_418B10();
nox_team_t* nox_server_teamNext_418B60(nox_team_t* a1);
int nox_server_teamsReset_417C60();
int nox_xxx_createCoopTeam_417E10();
nox_team_t* nox_xxx_teamCreate_4186D0(char a1);
wchar_t* nox_server_teamTitle_418C20(int a1);
uint32_t* nox_xxx_materialGetTeamColor_418D50(void* a1);
void nox_xxx_createAtImpl_4191D0(unsigned char a1, int a2, int a3, int a4, int a5);

#endif // NOX_PORT_COMMON_TEAM
