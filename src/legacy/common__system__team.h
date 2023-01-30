#ifndef NOX_PORT_COMMON_TEAM
#define NOX_PORT_COMMON_TEAM

#include "static_assert.h"
#include "defs.h"

typedef struct {
	wchar_t name[21]; // 0, 0
	uint16_t field_42; // 10, 42
	uint32_t field_44; // 11, 44
	uint32_t field_48; // 12, 48
	int lessons; // 13, 52
	uint8_t  def_ind; // 14, 56
	uint8_t  field_57; // 14, 57 TODO: team def code?
	uint8_t  ind; // 14, 58
	uint8_t  field_59; // 14, 59
	uint32_t field_60; // 15, 60 TODO: id? net code?
	uint32_t active; // 16, 64
	uint32_t field_68; // 17, 68
	void* field_72; // 18, 72 TODO: team flag? team spawn?
	uint32_t field_76; // 19, 76
} nox_team_t;
_Static_assert(sizeof(nox_team_t) == 80, "wrong size of nox_team_t structure!");

nox_team_t* nox_server_teamByXxx_418AE0(int a1);
nox_team_t* nox_server_teamFirst_418B10();
nox_team_t* nox_server_teamNext_418B60(nox_team_t* a1);
unsigned char nox_xxx_getTeamCounter_417DD0();
nox_team_t* nox_xxx_clientGetTeamColor_418AB0(int a1);
nox_team_t* nox_xxx_teamCreate_4186D0(char a1);
wchar_t* nox_server_teamTitle_418C20(int a1);
uint32_t nox_xxx_materialGetTeamColor_418D50(nox_team_t* a1);
void nox_xxx_createAtImpl_4191D0(unsigned char a1, void* a2, int a3, int a4, int a5);
int nox_server_teamsResetYyy_417D00();
int nox_server_teamsZzz_419030(int a1);

#endif // NOX_PORT_COMMON_TEAM
