#include "client/drawable/drawable.h"
#include "common/system/team.h"

#include "client/gui/chathelp.h"
#include "client/gui/gadgets/listbox.h"
#include "client/gui/gamewin/psscript.h"
#include "client/gui/guiinv.h"
#include "client/gui/guiquit.h"
#include "client/gui/guivote.h"
#include "client/network/cdecode.h"
#include "client/network/deathmsg.h"
#include "client/shell/noxworld.h"

#include "client/draw/fx.h"
#include "client/gui/guibook.h"

#include "proto.h"

extern _DWORD dword_5d4594_1305724;
extern _DWORD dword_5d4594_1301808;
extern _DWORD dword_5d4594_1303508;
extern _DWORD dword_5d4594_1200776;
extern _DWORD dword_5d4594_1305716;
extern _DWORD dword_5d4594_1305700;
extern _DWORD dword_5d4594_1301796;
extern _DWORD dword_5d4594_3798708;
extern _DWORD dword_5d4594_1305712;
extern _DWORD dword_5d4594_1203832;
extern _DWORD dword_5d4594_1305720;
extern _DWORD dword_5d4594_1200796;
extern _DWORD dword_5d4594_1305788;
extern void* nox_alloc_healthChange_1301772;
extern _DWORD dword_5d4594_3798712;
extern _DWORD nox_server_sanctuaryHelp_54276;
extern _DWORD dword_5d4594_1303536;
extern _DWORD dword_5d4594_1197308;
extern _DWORD dword_5d4594_1301824;
extern _DWORD dword_5d4594_1197372;
extern _DWORD dword_5d4594_1305800;
extern _DWORD dword_5d4594_1301816;
extern void* nox_alloc_friendList_1203860;
extern _DWORD dword_5d4594_1301812;
extern _DWORD dword_5d4594_1305748;
extern _DWORD dword_5d4594_1197328;
extern _DWORD dword_5d4594_1303472;
extern _DWORD dword_5d4594_1197352;
extern _DWORD dword_5d4594_1197336;
extern _DWORD dword_5d4594_1197356;
extern _DWORD dword_5d4594_1303468;
extern _DWORD dword_5d4594_1301780;
extern _DWORD dword_5d4594_1203836;
extern _DWORD dword_5d4594_1203840;
extern _DWORD dword_5d4594_1197332;
extern _DWORD dword_5d4594_1301840;
extern void* nox_alloc_chat_1197364;
extern _DWORD dword_5d4594_1203864;
extern _DWORD dword_5d4594_1217452;
extern _DWORD dword_5d4594_3798716;
extern _DWORD dword_5d4594_1193712;
extern _DWORD nox_server_connectionType_3596;
extern _DWORD dword_5d4594_3804668;
extern _DWORD dword_5d4594_810636;
extern _DWORD dword_5d4594_1301828;
extern _DWORD dword_5d4594_1193584;
extern _DWORD dword_5d4594_1301832;
extern _DWORD dword_5d4594_1301836;
extern _DWORD dword_5d4594_1301776;
extern _DWORD dword_5d4594_1307204;
extern _DWORD dword_5d4594_1197316;
extern _DWORD dword_5d4594_3798720;
extern _DWORD dword_5d4594_1217460;
extern _DWORD dword_5d4594_3801804;
extern void* nox_alloc_pixelSpan_1301844;
extern _DWORD dword_5d4594_1197320;
extern _DWORD dword_587000_166704;
extern _DWORD dword_5d4594_1197324;
extern _DWORD dword_5d4594_1217456;
extern _DWORD dword_5d4594_1301800;
extern _DWORD dword_5d4594_810640;
extern _DWORD dword_5d4594_1305680;
extern _DWORD dword_5d4594_1301792;
extern _DWORD dword_5d4594_1301848;
extern _DWORD dword_5d4594_1197312;
extern _DWORD dword_5d4594_1303452;
extern _DWORD dword_5d4594_3798696;
extern _DWORD dword_5d4594_815132;
extern _DWORD dword_5d4594_1305684;
extern _DWORD dword_5d4594_1193516;
extern _DWORD dword_5d4594_1217464;
extern _DWORD dword_5d4594_3801780;
extern _DWORD dword_5d4594_810632;
extern _DWORD nox_client_renderGUI_80828;
extern _DWORD dword_5d4594_1217448;
extern _DWORD dword_5d4594_3804672;
extern _DWORD dword_5d4594_3804656;
extern _DWORD dword_5d4594_3804664;
extern BYTE** nox_pixbuffer_rows_3798784;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

const int nox_max_npcs = 1024;
nox_npc* npc_array;

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;
extern obj_5D4594_3799572_t obj_5D4594_3800716;

nox_drawable*** nox_drawable_2d_index = 0;
int nox_drawable_2d_index_size = 0;
const int nox_drawable_2d_index_cap = 47;

int4*(__cdecl* func_5D4594_1305696)(int, int, int, int, int);
void(__cdecl* func_5D4594_1305708)(_DWORD*, int, unsigned int);

//----- (0048C4D0) --------------------------------------------------------
int sub_48C4D0() {
	unsigned __int16* v0; // esi
	_WORD* v1;            // edi
	unsigned __int16 v2;  // ax
	int v3;               // eax
	int result;           // eax
	int v6;               // [esp-4h] [ebp-10h]

	v0 = *(unsigned __int16**)&dword_5d4594_1193516;
	v1 = *(_WORD**)&dword_5d4594_1193584;
	v6 = *(_DWORD*)&byte_5D4594[1193520];
	do {
		v2 = *v0;
		++v0;
		v3 = (unsigned __int8)*(_DWORD*)(dword_5d4594_3804668 + v2);
		result =
			*(_DWORD*)(dword_5d4594_3804672 +
					   2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[34]) * v3) >> 8)) |
			*(_DWORD*)(dword_5d4594_3804656 +
					   2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[35]) * v3) >> 8)) |
			*(_DWORD*)(dword_5d4594_3804664 + 2 * ((unsigned int)(*(_DWORD*)(&obj_5D4594_3800716.data[36]) * v3) >> 8));
		*v1 = result;
		++v1;
	} while ((*(_DWORD*)&byte_5D4594[1193520])-- > 1);
	*(_DWORD*)&byte_5D4594[1193520] = v6;
	dword_5d4594_1193516 = v0;
	dword_5d4594_1193584 = v1;
	return result;
}

//----- (0048C560) --------------------------------------------------------
int sub_48C560() { return 1; }

//----- (0048C580) --------------------------------------------------------
void __cdecl sub_48C580(pixel8888* a1, int num) {
	unsigned __int32* pix = (unsigned __int32*)a1;
	for (int i = num - 1; i >= 0; i--) {
		unsigned __int32 result = *pix;
		for (unsigned __int32* it = &pix[i]; it > pix; --it) {
			if (result > *it) {
				result = InterlockedExchange((volatile signed __int32*)it, result);
			}
		}
		*pix = result;
		++pix;
	}
}

//----- (0048C5B0) --------------------------------------------------------
__int16 __cdecl sub_48C5B0(__int16* a1, int a2) {
	__int16* v2;    // edi
	int v3;         // ecx
	__int16* v4;    // ebx
	__int16 result; // ax
	__int16 v6;     // t0

	v2 = a1;
	v3 = a2;
	do {
		v4 = &v2[v3];
		result = *v2;
		do {
			--v4;
			if (result > *v4) {
				v6 = result;
				result = *v4;
				*v4 = v6;
			}
		} while (v4 != v2);
		*v2 = result;
		++v2;
		--v3;
	} while (v3);
	return result;
}

//----- (0048C5E0) --------------------------------------------------------
int __cdecl sub_48C5E0(int a1, int a2) {
	unsigned int v2; // eax
	int v3;          // ecx
	bool v4;         // tt

	v2 = *(_DWORD*)&byte_587000[156212];
	v3 = 32;
	do {
		v4 = __CFSHL__(v2, 1);
		v2 = __ROL4__(v2, 1);
		if (v4)
			v2 ^= 0xA0Au;
		--v3;
	} while (v3);
	*(_DWORD*)&byte_587000[156212] = v2;
	return a1 + (((unsigned int)(a2 - a1) * (unsigned __int64)v2) >> 32);
}

//----- (0048C610) --------------------------------------------------------
__int16 sub_48C610() {
	int v0;  // eax
	int v1;  // ecx
	bool v2; // tt

	v0 = *(_DWORD*)&byte_587000[156216];
	v1 = 16;
	do {
		v2 = __CFSHL__(v0, 1);
		LOWORD(v0) = __ROL2__(v0, 1);
		if (v2)
			v0 ^= 0xAu;
		--v1;
	} while (v1);
	*(_DWORD*)&byte_587000[156216] = v0;
	return v0;
}

//----- (0048C650) --------------------------------------------------------
_DWORD* __cdecl sub_48C650(int a1, int a2, int a3, _DWORD* a4, _DWORD* a5) {
	int v5;         // eax
	_DWORD* result; // eax

	v5 = sub_48C5E0(a1, a2);
	sub_4AEDA0(&a2, &a1, v5, a3);
	*a4 += a2;
	result = a5;
	*a5 += a1;
	return result;
}

//----- (0048C690) --------------------------------------------------------
unsigned int __cdecl sub_48C690(int a1, int a2, int a3, int a4) {
	return sub_48C730((a3 - a1) * (a3 - a1) + (a4 - a2) * (a4 - a2));
}

//----- (0048C6B0) --------------------------------------------------------
unsigned int __cdecl sub_48C6B0(int a1, int a2) { return sub_48C730(a2 * a2 + a1 * a1); }

//----- (0048C6D0) --------------------------------------------------------
double __cdecl sub_48C6D0(float a1, float a2, float a3, float a4) {
	return (double)sub_48C730((__int64)((a3 - a1) * (a3 - a1) + (a4 - a2) * (a4 - a2)));
}
// 48C6F6: variable 'v4' is possibly undefined

//----- (0048C700) --------------------------------------------------------
double __cdecl sub_48C700(float a1, float a2) { return (double)sub_48C730((__int64)(a1 * a1 + a2 * a2)); }
// 48C722: variable 'v2' is possibly undefined

//----- (0048C730) --------------------------------------------------------
unsigned __fastcall sub_48C730(unsigned int a1) {
	int result; // eax

	if (a1 < 0x10000) {
		if (a1 < 0x100) {
			if (a1 < 0x10) {
				if (a1 < 4) {
					result = byte_587000[155956 + 64 * a1] >> 7;
				} else {
					result = byte_587000[155956 + 16 * a1] >> 6;
				}
			} else if (a1 < 0x40) {
				result = byte_587000[155956 + 4 * a1] >> 5;
			} else {
				result = byte_587000[155956 + a1] >> 4;
			}
		} else if (a1 < 0x1000) {
			if (a1 < 0x400) {
				result = byte_587000[155956 + (a1 >> 2)] >> 3;
			} else {
				result = byte_587000[155956 + (a1 >> 4)] >> 2;
			}
		} else if (a1 < 0x4000) {
			result = byte_587000[155956 + (a1 >> 6)] >> 1;
		} else {
			result = byte_587000[155956 + (a1 >> 8)];
		}
	} else if (a1 < 0x1000000) {
		if (a1 < 0x100000) {
			if (a1 < 0x40000) {
				result = byte_587000[155956 + (a1 >> 10)] << 1;
			} else {
				result = byte_587000[155956 + (a1 >> 12)] << 2;
			}
		} else if (a1 < 0x400000) {
			result = byte_587000[155956 + (a1 >> 14)] << 3;
		} else {
			result = byte_587000[155956 + (a1 >> 16)] << 4;
		}
	} else if (a1 < 0x10000000) {
		if (a1 < 0x4000000) {
			result = byte_587000[155956 + (a1 >> 18)] << 5;
		} else {
			result = byte_587000[155956 + (a1 >> 20)] << 6;
		}
	} else if (a1 < 0x40000000) {
		result = byte_587000[155956 + (a1 >> 22)] << 7;
	} else {
		result = (unsigned __int8)byte_587000[155956 + (a1 >> 24)] << 8;
	}
	return result;
}

//----- (0048C870) --------------------------------------------------------
int __cdecl nox_client_winVerGetMajor_48C870(LPSTR printOut) {
	int v1;                                    // esi
	unsigned __int8* v2;                       // ebx
	struct _OSVERSIONINFOA VersionInformation; // [esp+Ch] [ebp-94h]

	memset(&VersionInformation, 0, sizeof(VersionInformation));
	v1 = 0;
	v2 = &byte_587000[156220];
	VersionInformation.dwOSVersionInfoSize = 148;
	if (GetVersionExA(&VersionInformation)) {
		if (VersionInformation.dwPlatformId) {
			if (VersionInformation.dwPlatformId == 1) {
				if (VersionInformation.dwMajorVersion > 4 ||
					VersionInformation.dwMajorVersion == 4 && VersionInformation.dwMinorVersion) {
					v1 = 4;
					v2 = &byte_587000[156240];
				} else if (LOWORD(VersionInformation.dwBuildNumber) <= 0x3E8u) {
					v1 = 2;
					v2 = &byte_587000[156268];
				} else {
					v1 = 3;
					v2 = &byte_587000[156252];
				}
			} else if (VersionInformation.dwPlatformId == 2) {
				v1 = 5;
				v2 = &byte_587000[156280];
			}
		} else {
			v1 = 1;
			v2 = &byte_587000[156228];
		}
	}
	if (printOut)
		nox_wsprintfA(printOut, (LPCSTR)&byte_587000[156292], VersionInformation.dwMajorVersion,
					  VersionInformation.dwMinorVersion, LOWORD(VersionInformation.dwBuildNumber), v2);
	return v1;
}

//----- (0048CA70) --------------------------------------------------------
int __cdecl sub_48CA70(int a1) { return nox_window_set_hidden(*(int*)&dword_5d4594_1193712, a1); }

//----- (0048CA90) --------------------------------------------------------
BOOL sub_48CA90() { return dword_5d4594_1193712 && !wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1193712); }

//----- (0048CAB0) --------------------------------------------------------
int sub_48CAB0() {
	int result; // eax

	result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1193712);
	dword_5d4594_1193712 = 0;
	return result;
}

//----- (0048CAD0) --------------------------------------------------------
int sub_48CAD0() {
	if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1197312))
		return 0;
	sub_46C6E0(*(int*)&dword_5d4594_1197312);
	nox_window_set_hidden(*(int*)&dword_5d4594_1197312, 1);
	return 1;
}

//----- (0048D000) --------------------------------------------------------
int sub_48D000() {
	_DWORD* v0; // eax

	v0 = nox_new_window_from_file("GuiKick.wnd", sub_48D0A0);
	dword_5d4594_1197312 = v0;
	if (!v0)
		return 0;
	dword_5d4594_1197316 = sub_46B0C0(v0, 4320);
	dword_5d4594_1197320 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1197312, 4321);
	nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_1197312, (nox_win_width - *(int*)(dword_5d4594_1197312 + 8)) / 2,
					   *(_DWORD*)(dword_5d4594_1197312 + 20));
	nox_window_set_hidden(*(int*)&dword_5d4594_1197312, 1);
	dword_5d4594_1197324 = 0;
	dword_5d4594_1197328 = 0;
	dword_5d4594_1197332 = 0;
	dword_5d4594_1197336 = 0;
	return 1;
}

//----- (0048D0A0) --------------------------------------------------------
int __cdecl sub_48D0A0(int a1, int a2, int* a3, int a4) {
	int v4; // eax

	if (a2 != 16391)
		return 0;
	v4 = sub_46B0A0(a3) - 4311;
	if (v4) {
		if (v4 == 1) {
		LABEL_14:
			sub_48CAD0();
			goto LABEL_15;
		}
	} else {
		if (dword_5d4594_1197308 != 4) {
			if (dword_5d4594_1197308 == 2) {
				sub_48D340();
			} else {
				if (dword_5d4594_1197308 && dword_5d4594_1197308 != 1 && dword_5d4594_1197308 != 3) {
					goto LABEL_15;
				}
				sub_48D120();
			}
			goto LABEL_14;
		}
		sub_48D410();
	}
LABEL_15:
	sub_452D80(921, 100);
	return 1;
}

//----- (0048D120) --------------------------------------------------------
int sub_48D120() {
	int v0;             // ebp
	int* v1;            // eax
	int* v2;            // esi
	int i;              // eax
	const wchar_t* v4;  // eax
	wchar_t* v5;        // ebx
	int v6;             // esi
	const wchar_t* v7;  // edi
	int result;         // eax
	int v9;             // ebp
	wchar_t* v10;       // ebx
	int v11;            // esi
	const wchar_t* v12; // edi

	v0 = 0;
	dword_5d4594_1197328 = dword_5d4594_1197324;
	qmemcpy(&byte_5D4594[1195512], &byte_5D4594[1193720], 0x700u);
	dword_5d4594_1197324 = 0;
	v1 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16404, 0, 0);
	v2 = v1;
	for (i = *v1; i != -1; ++v2) {
		v4 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16406, i, 0);
		if (v4) {
			nox_wcscpy((wchar_t*)&byte_5D4594[56 * dword_5d4594_1197324 + 1193720], v4);
			++dword_5d4594_1197324;
		}
		i = v2[1];
	}
	if (*(int*)&dword_5d4594_1197328 > 0) {
		v5 = (wchar_t*)&byte_5D4594[1195512];
		do {
			v6 = 0;
			if (*(int*)&dword_5d4594_1197324 <= 0) {
			LABEL_11:
				sub_48D260(v5);
			} else {
				v7 = (const wchar_t*)&byte_5D4594[1193720];
				while (nox_wcscmp(v5, v7)) {
					++v6;
					v7 += 28;
					if (v6 >= *(int*)&dword_5d4594_1197324)
						goto LABEL_11;
				}
			}
			++v0;
			v5 += 28;
		} while (v0 < *(int*)&dword_5d4594_1197328);
	}
	result = dword_5d4594_1197324;
	v9 = 0;
	if (*(int*)&dword_5d4594_1197324 > 0) {
		v10 = (wchar_t*)&byte_5D4594[1193720];
		do {
			v11 = 0;
			if (*(int*)&dword_5d4594_1197328 <= 0) {
			LABEL_19:
				sub_48D2D0(v10);
			} else {
				v12 = (const wchar_t*)&byte_5D4594[1195512];
				while (nox_wcscmp(v10, v12)) {
					++v11;
					v12 += 28;
					if (v11 >= *(int*)&dword_5d4594_1197328)
						goto LABEL_19;
				}
			}
			result = dword_5d4594_1197324;
			++v9;
			v10 += 28;
		} while (v9 < *(int*)&dword_5d4594_1197324);
	}
	return result;
}

//----- (0048D260) --------------------------------------------------------
char* __cdecl sub_48D260(wchar_t* a1) {
	char* result; // eax
	int v2;       // esi
	char v3[52];  // [esp+8h] [ebp-34h]

	result = nox_common_playerInfoGetFirst_416EA0();
	v2 = (int)result;
	if (result) {
		while (nox_wcscmp((const wchar_t*)(v2 + 4704), a1)) {
			result = nox_common_playerInfoGetNext_416EE0(v2);
			v2 = (int)result;
			if (!result)
				return result;
		}
		*(_WORD*)v3 = 750;
		nox_wcscpy((wchar_t*)&v3[2], a1);
		result = (char*)sub_40EBC0(31, 0, v3, 52);
	}
	return result;
}

//----- (0048D2D0) --------------------------------------------------------
char* __cdecl sub_48D2D0(wchar_t* a1) {
	char* result; // eax
	int v2;       // esi
	char v3[52];  // [esp+8h] [ebp-34h]

	result = nox_common_playerInfoGetFirst_416EA0();
	v2 = (int)result;
	if (result) {
		while (nox_wcscmp((const wchar_t*)(v2 + 4704), a1)) {
			result = nox_common_playerInfoGetNext_416EE0(v2);
			v2 = (int)result;
			if (!result)
				return result;
		}
		*(_WORD*)v3 = 238;
		nox_wcscpy((wchar_t*)&v3[2], a1);
		result = (char*)sub_40EBC0(31, 0, v3, 52);
	}
	return result;
}

//----- (0048D340) --------------------------------------------------------
int sub_48D340() {
	int result; // eax

	if (nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16404, 0, 0)) {
		result = 0;
		dword_5d4594_1197332 = 0;
		if (dword_5d4594_1197336 == 1) {
			result = sub_48D3E0();
			dword_5d4594_1197336 = dword_5d4594_1197332;
			return result;
		}
	} else {
		result = 1;
		dword_5d4594_1197332 = 1;
		if (!dword_5d4594_1197336) {
			result = sub_48D3B0();
			dword_5d4594_1197336 = dword_5d4594_1197332;
			return result;
		}
	}
	dword_5d4594_1197336 = result;
	return result;
}

//----- (0048D3B0) --------------------------------------------------------
int sub_48D3B0() {
	char v1[2]; // [esp+0h] [ebp-2h]

	v1[0] = -18;
	v1[1] = 4;
	return sub_4E53C0(31, v1, 2, 0, 1);
}

//----- (0048D3E0) --------------------------------------------------------
int sub_48D3E0() {
	char v1[2]; // [esp+0h] [ebp-2h]

	v1[0] = -18;
	v1[1] = 5;
	return sub_4E53C0(31, v1, 2, 0, 1);
}

//----- (0048D410) --------------------------------------------------------
_DWORD* sub_48D410() {
	_DWORD* result; // eax

	result = (_DWORD*)nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16404, 0, 0);
	if (!result)
		return sub_48CB10(2);
	if (result == (_DWORD*)1)
		result = sub_48CB10(3);
	return result;
}

//----- (0048D450) --------------------------------------------------------
int sub_48D450() {
	int result; // eax

	sub_46C6E0(*(int*)&dword_5d4594_1197312);
	sub_46ADE0(*(int*)&dword_5d4594_1197312);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1197312);
	result = 0;
	dword_5d4594_1197312 = 0;
	dword_5d4594_1197316 = 0;
	dword_5d4594_1197320 = 0;
	dword_5d4594_1197324 = 0;
	dword_5d4594_1197328 = 0;
	dword_5d4594_1197332 = 0;
	dword_5d4594_1197336 = 0;
	return result;
}

//----- (0048D4A0) --------------------------------------------------------
int sub_48D4A0() {
	int result; // eax

	result = 0;
	dword_5d4594_1197332 = 0;
	dword_5d4594_1197336 = 0;
	return result;
}

//----- (0048D4B0) --------------------------------------------------------
int __cdecl sub_48D4B0(int a1) {
	int result; // eax

	*(_DWORD*)&byte_5D4594[1197304] = a1;
	if (a1 == 1)
		result = sub_4C3460(0);
	else
		result = sub_4C3460(1);
	return result;
}

//----- (0048D4E0) --------------------------------------------------------
int sub_48D4E0() { return *(_DWORD*)&byte_5D4594[1197304]; }

//----- (0048D4F0) --------------------------------------------------------
BOOL __cdecl sub_48D4F0(unsigned __int16 a1, unsigned __int16 a2) {
	unsigned __int16 v2; // cx

	v2 = 10000;
	if (a1 - 10000 < 0) {
		if (a2 >= 0xFFFF - (unsigned __int16)(10000 - a1))
			return 1;
		v2 = a1;
	}
	return a2 < a1 && a2 >= a1 - v2;
}

//----- (0048D560) --------------------------------------------------------
int __cdecl sub_48D560(unsigned __int16 a1) {
	int* v1; // eax

	v1 = sub_425890((int*)&byte_5D4594[1197340]);
	if (!v1)
		return 0;
	while (v1[2] != a1) {
		v1 = sub_4258A0(v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (0048D5A0) --------------------------------------------------------
_DWORD* __cdecl sub_48D5A0(int a1) {
	_DWORD* result; // eax
	_DWORD* v2;     // ebx

	result = (_DWORD*)sub_48D4F0(*(unsigned __int16*)&byte_5D4594[1197360], *(_WORD*)(a1 + 1));
	if (!result) {
		result = (_DWORD*)sub_48D560(*(_WORD*)(a1 + 1));
		if (!result) {
			result = nox_calloc(*(unsigned __int8*)(a1 + 3) + 32, 1u);
			v2 = result;
			if (result) {
				sub_425770(result);
				v2[2] = *(unsigned __int16*)(a1 + 1);
				*((_WORD*)v2 + 12) = *(unsigned __int8*)(a1 + 3);
				*((_QWORD*)v2 + 2) = sub_416BB0();
				qmemcpy(v2 + 8, (const void*)(a1 + 4), *(unsigned __int8*)(a1 + 3));
				if (*(_WORD*)&byte_5D4594[1197360] == *(_WORD*)(a1 + 1))
					dword_5d4594_1197352 = v2;
				result = (_DWORD*)sub_425790((int*)&byte_5D4594[1197340], v2);
			}
		}
	}
	return result;
}

//----- (0048D660) --------------------------------------------------------
int sub_48D660() {
	unsigned __int64 v0; // rax
	int* v1;             // esi
	int* v2;             // edi

	LODWORD(v0) = dword_5d4594_1197352;
	if (!dword_5d4594_1197352) {
		if (dword_5d4594_1197356) {
			v0 = sub_416BB0() - *(_QWORD*)(dword_5d4594_1197356 + 16);
			if (v0 > 0x7530) {
				*(_WORD*)&byte_5D4594[1197360] = *(_WORD*)(dword_5d4594_1197356 + 8);
				dword_5d4594_1197352 = dword_5d4594_1197356;
				LODWORD(v0) = sub_4258A0(*(int**)&dword_5d4594_1197356);
				dword_5d4594_1197356 = v0;
			}
		}
	}
	v1 = *(int**)&dword_5d4594_1197352;
	if (dword_5d4594_1197352) {
		do {
			LODWORD(v0) = v1[2];
			if ((_DWORD)v0 != *(unsigned __int16*)&byte_5D4594[1197360])
				break;
			v2 = sub_4258A0(v1);
			if (!v2) {
				v2 = sub_425890((int*)&byte_5D4594[1197340]);
				if (v2 == v1)
					v2 = 0;
			}
			sub_48EA70(31, (unsigned int)(v1 + 8), *((unsigned __int16*)v1 + 12));
			++*(_WORD*)&byte_5D4594[1197360];
			sub_425920((_DWORD**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
	dword_5d4594_1197356 = v1;
	dword_5d4594_1197352 = 0;
	return v0;
}

//----- (0048D740) --------------------------------------------------------
int sub_48D740() {
	int result; // eax

	sub_425760(&byte_5D4594[1197340]);
	result = 0;
	dword_5d4594_1197352 = 0;
	dword_5d4594_1197356 = 0;
	*(_WORD*)&byte_5D4594[1197360] = 0;
	return result;
}

//----- (0048D760) --------------------------------------------------------
_DWORD* sub_48D760() {
	int* v0;        // esi
	int* v1;        // edi
	_DWORD* result; // eax

	v0 = sub_425890((int*)&byte_5D4594[1197340]);
	if (v0) {
		do {
			v1 = sub_4258A0(v0);
			sub_425920((_DWORD**)v0);
			free(v0);
			v0 = v1;
		} while (v1);
	}
	result = sub_425760(&byte_5D4594[1197340]);
	*(_WORD*)&byte_5D4594[1197360] = 0;
	return result;
}

//----- (0048D7B0) --------------------------------------------------------
int* sub_48D7B0() {
	int* result; // eax

	for (result = sub_425890((int*)&byte_5D4594[1197340]); result; result = sub_4258A0(result))
		;
	return result;
}

//----- (0048D7D0) --------------------------------------------------------
BOOL sub_48D7D0() {
	nox_alloc_chat_1197364 = nox_new_alloc_class("Chat", 692, 64);
	return nox_alloc_chat_1197364 != 0;
}

//----- (0048D800) --------------------------------------------------------
int sub_48D800() {
	if (nox_alloc_chat_1197364)
		nox_free_alloc_class(*(LPVOID*)&nox_alloc_chat_1197364);
	nox_alloc_chat_1197364 = 0;
	*(_DWORD*)&byte_5D4594[1197368] = 0;
	return 1;
}

//----- (0048D830) --------------------------------------------------------
BOOL __cdecl sub_48D830(nox_drawable* dr) {
	int a1 = dr;
	return sub_48D850(*(_DWORD*)(a1 + 128)) != 0;
}

//----- (0048D850) --------------------------------------------------------
int __cdecl sub_48D850(int a1) {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[1197368];
	if (!*(_DWORD*)&byte_5D4594[1197368])
		return 0;
	while (*(_DWORD*)(result + 656) != a1) {
		result = *(_DWORD*)(result + 684);
		if (!result)
			return 0;
	}
	return result;
}

//----- (0048D880) --------------------------------------------------------
wchar_t* __cdecl sub_48D880(int a1, wchar_t* a2) {
	wchar_t* v2;     // esi
	int v3;          // ebx
	wchar_t* result; // eax
	int v5;          // eax
	int v6;          // eax

	v2 = (wchar_t*)sub_48D850(*(unsigned __int16*)(a1 + 1));
	if (v2) {
		v3 = 0;
	} else {
		result = (wchar_t*)nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_chat_1197364);
		v2 = result;
		if (!result)
			return result;
		v3 = 1;
	}
	nox_wcscpy(v2, a2);
	*((_DWORD*)v2 + 159) = *(unsigned __int8*)(a1 + 8);
	*((_DWORD*)v2 + 161) = *(_DWORD*)(a1 + 4);
	*((_DWORD*)v2 + 164) = *(unsigned __int16*)(a1 + 1);
	if (*(_WORD*)(a1 + 9)) {
		v6 = *(unsigned __int16*)(a1 + 9);
	} else {
		v5 = *((_DWORD*)v2 + 159) / 8;
		if (v5 >= 8)
			v5 = 8;
		v6 = *(_DWORD*)&byte_5D4594[2649704] * (v5 + 2);
	}
	result = (wchar_t*)(*(_DWORD*)&byte_5D4594[2598000] + v6);
	*((_DWORD*)v2 + 160) = result;
	if (v3) {
		result = *(wchar_t**)&byte_5D4594[1197368];
		if (*(_DWORD*)&byte_5D4594[1197368]) {
			result = *(wchar_t**)&dword_5d4594_1197372;
			*(_DWORD*)(dword_5d4594_1197372 + 684) = v2;
			*((_DWORD*)v2 + 172) = dword_5d4594_1197372;
			*((_DWORD*)v2 + 171) = 0;
			dword_5d4594_1197372 = v2;
		} else {
			*(_DWORD*)&byte_5D4594[1197368] = v2;
			dword_5d4594_1197372 = v2;
			*((_DWORD*)v2 + 172) = 0;
			*((_DWORD*)v2 + 171) = 0;
		}
	}
	return result;
}

//----- (0048D990) --------------------------------------------------------
int4* __cdecl sub_48D990(_DWORD* a1) {
	int v1;     // ebx
	_DWORD* v2; // esi
	int v3;     // eax
	_DWORD* v4; // edi
	char* v5;   // eax
	char* v6;   // eax
	int* v7;    // eax
	int v8;     // edi
	int v9;     // eax
	int v10;    // eax
	int v11;    // ebp
	int v12;    // ebp
	int v13;    // esi
	int v14;    // ebp
	int v15;    // esi
	int v16;    // ebp
	int v18;    // [esp+Ch] [ebp-28h]
	int i;      // [esp+10h] [ebp-24h]
	_WORD* v20; // [esp+14h] [ebp-20h]
	int v21;    // [esp+18h] [ebp-1Ch]
	int v22;    // [esp+1Ch] [ebp-18h]
	int v23;    // [esp+20h] [ebp-14h]
	int v24;    // [esp+24h] [ebp-10h]
	int v25;    // [esp+24h] [ebp-10h]
	int v26;    // [esp+24h] [ebp-10h]
	int v27;    // [esp+28h] [ebp-Ch]
	int v28;    // [esp+28h] [ebp-Ch]
	int v29;    // [esp+2Ch] [ebp-8h]
	int v30;    // [esp+38h] [ebp+4h]

	v22 = sub_43F320(0);
	v1 = v22 / 2;
	sub_437260();
	sub_48DCF0(a1);
	v2 = *(_DWORD**)&byte_5D4594[1197368];
	v30 = *(_DWORD*)&byte_5D4594[1197368];
	if (*(_DWORD*)&byte_5D4594[1197368]) {
		while (1) {
			if (v2[165]) {
				v3 = v2[167];
				v21 = *(_DWORD*)&byte_5D4594[2523948];
				v20 = 0;
				if (v3 && *(_BYTE*)(v3 + 112) & 4) {
					v4 = sub_418C80(*(_DWORD*)(v3 + 128));
					v5 = sub_417040(v2[164]);
					if (v5)
						v20 = v5 + 4704;
					if (v4) {
						v6 = sub_418AB0(*((unsigned __int8*)v4 + 4));
						if (v6) {
							v7 = (int*)sub_418D50((int)v6);
							if (v7)
								v21 = *v7;
						}
					}
				}
				v8 = v2[162];
				v18 = v2[163];
				for (i = 0; i < 2; ++i) {
					if (i) {
						v9 = *(_DWORD*)&byte_5D4594[2650660];
						--v8;
						--v18;
					} else {
						v9 = *(_DWORD*)&byte_5D4594[2614248];
					}
					nox_client_drawSetColor_434460(v9);
					v23 = v8 - v1;
					nox_client_drawAddPoint_49F500(v8, v18 - v1);
					nox_client_drawAddPoint_49F500(v8 - v1, v18);
					nox_client_drawLineFromPoints_49E4B0();
					v10 = *(_DWORD*)(v30 + 672);
					v11 = v10 + v8;
					v24 = v10 + v8;
					nox_client_drawAddPoint_49F500(v8, v18 - v1);
					nox_client_drawAddPoint_49F500(v11, v18 - v1);
					nox_client_drawLineFromPoints_49E4B0();
					v12 = v1 + v11;
					nox_client_drawAddPoint_49F500(v12, v18);
					nox_client_drawAddPoint_49F500(v24, v18 - v1);
					nox_client_drawLineFromPoints_49E4B0();
					v25 = v12;
					v27 = v18 + *(_DWORD*)(v30 + 676);
					nox_client_drawAddPoint_49F500(v12, v18);
					nox_client_drawAddPoint_49F500(v12, v27);
					nox_client_drawLineFromPoints_49E4B0();
					v13 = v1 + v27;
					v14 = v12 - v1;
					nox_client_drawAddPoint_49F500(v14, v1 + v27);
					nox_client_drawAddPoint_49F500(v25, v27);
					nox_client_drawLineFromPoints_49E4B0();
					if (*(_DWORD*)(v30 + 664)) {
						v28 = v1 + v27;
						v26 = v1 + v8 + *(int*)(v30 + 672) / 2;
						nox_client_drawAddPoint_49F500(v14, v13);
						nox_client_drawAddPoint_49F500(v26, v13);
						nox_client_drawLineFromPoints_49E4B0();
						v15 = v22 + v13;
						v29 = v8 + *(int*)(v30 + 672) / 2;
						nox_client_drawAddPoint_49F500(v29, v15);
						nox_client_drawAddPoint_49F500(v26, v28);
						nox_client_drawLineFromPoints_49E4B0();
						v16 = v8 + *(int*)(v30 + 672) / 2 - v1;
						nox_client_drawAddPoint_49F500(v29, v15);
						v13 = v28;
						nox_client_drawAddPoint_49F500(v16, v28);
						nox_client_drawLineFromPoints_49E4B0();
						nox_client_drawAddPoint_49F500(v8, v28);
						nox_client_drawAddPoint_49F500(v16, v28);
					} else {
						nox_client_drawAddPoint_49F500(v8, v13);
						nox_client_drawAddPoint_49F500(v14, v13);
					}
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v8, v13);
					nox_client_drawAddPoint_49F500(v23, v13 - v1);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v23, v13 - v1 - *(_DWORD*)(v30 + 676));
					nox_client_drawAddPoint_49F500(v23, v13 - v1);
					nox_client_drawLineFromPoints_49E4B0();
				}
				sub_434390(*(int*)&byte_5D4594[2523948]);
				sub_4343E0(*(int*)&byte_5D4594[2614248]);
				sub_43FD00(0, (_WORD*)v30, v8, v18, 128, 0);
				if (v20) {
					sub_434390(v21);
					sub_43FD00(0, v20, v8, v18 - v22 - 1, 128, 0);
				}
				v2 = (_DWORD*)v30;
			}
			v30 = v2[171];
			if (!v30)
				break;
			v2 = (_DWORD*)v2[171];
		}
	}
	return sub_437290();
}

//----- (0048DCF0) --------------------------------------------------------
void __cdecl sub_48DCF0(_DWORD* a1) {
	int v1;               // eax
	int v2;               // esi
	_DWORD* v3;           // ebx
	int v4;               // eax
	unsigned int v5;      // edx
	int v6;               // ecx
	int v7;               // eax
	_DWORD* v8;           // eax
	int v9;               // eax
	unsigned __int16 v10; // dx
	int* v11;             // ebp
	int v12;              // edx
	_DWORD* v13;          // edi
	int v14;              // eax
	int v15;              // eax
	int v16;              // eax
	int v17;              // ecx
	int v18;              // eax
	int v19;              // eax
	int v20;              // ecx
	int v21;              // eax
	int v22;              // eax
	int v23;              // eax
	int v24;              // [esp+8h] [ebp-18h]
	int v25;              // [esp+Ch] [ebp-14h]
	int4 a1a;             // [esp+10h] [ebp-10h]
	int v27;              // [esp+24h] [ebp+4h]

	v1 = sub_43F320(0);
	v2 = *(_DWORD*)&byte_5D4594[1197368];
	v3 = a1;
	v24 = v1;
	v4 = 0;
	if (*(_DWORD*)&byte_5D4594[1197368]) {
		while (1) {
			v5 = *(_DWORD*)(v2 + 656);
			v6 = *(_DWORD*)(v2 + 684);
			*(_DWORD*)(v2 + 680) = v4;
			v25 = v6;
			v27 = v4 + 1;
			*(_DWORD*)(v2 + 668) = 0;
			if (sub_578B70(v5)) {
				v7 = sub_578B30(*(_DWORD*)(v2 + 656));
				v8 = sub_45A720(v7);
			} else {
				v9 = sub_578B30(*(_DWORD*)(v2 + 656));
				v8 = sub_45A6F0(v9);
			}
			*(_DWORD*)(v2 + 668) = v8;
			if (v8) {
				*(_WORD*)(v2 + 644) = *((_WORD*)v8 + 6);
				*(_WORD*)(v2 + 646) = *((_WORD*)v8 + 8);
			}
			v10 = *(_WORD*)(v2 + 646);
			v11 = (_DWORD*)(v2 + 672);
			*(_DWORD*)(v2 + 648) = *v3 + *(unsigned __int16*)(v2 + 644) - v3[4];
			*(_DWORD*)(v2 + 652) = v3[1] + v10 - v3[5];
			sub_43F840(0, (unsigned __int16*)v2, (int*)(v2 + 672), (_DWORD*)(v2 + 676), 128);
			if (*(_DWORD*)(v2 + 672) > 128)
				*v11 = 128;
			v12 = *(_DWORD*)(v2 + 676);
			*(_DWORD*)(v2 + 648) += *v11 / -2;
			v13 = (_DWORD*)(v2 + 664);
			*(_DWORD*)(v2 + 652) += -64 - v12;
			*(_DWORD*)(v2 + 660) = 1;
			*(_DWORD*)(v2 + 664) = 1;
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v14 = *(_DWORD*)(v2 + 648);
				if (v14 < *v3 || v14 > v3[2] || (v15 = *(_DWORD*)(v2 + 652) - 64, v15 < v3[1]) || v15 > v3[3]) {
					*(_DWORD*)(v2 + 660) = 0;
					*v13 = 0;
				}
			}
			if (*(_DWORD*)(v2 + 660))
				break;
		LABEL_27:
			if (*(_DWORD*)&byte_5D4594[2598000] > *(int*)(v2 + 640)) {
				v22 = *(_DWORD*)(v2 + 688);
				if (v22)
					*(_DWORD*)(v22 + 684) = *(_DWORD*)(v2 + 684);
				else
					*(_DWORD*)&byte_5D4594[1197368] = *(_DWORD*)(v2 + 684);
				v23 = *(_DWORD*)(v2 + 684);
				if (v23)
					*(_DWORD*)(v23 + 688) = *(_DWORD*)(v2 + 688);
				else
					dword_5d4594_1197372 = *(_DWORD*)(v2 + 688);
				sub_414330(*(unsigned int**)&nox_alloc_chat_1197364, (_QWORD*)v2);
			}
			v2 = v25;
			if (!v25) {
				v2 = *(_DWORD*)&byte_5D4594[1197368];
				goto LABEL_37;
			}
			v4 = v27;
		}
		v16 = *v3 + v24;
		v17 = *(_DWORD*)(v2 + 648);
		if (v17 >= v16) {
			v18 = v3[2];
			if (v24 + v17 + *v11 <= v18)
				goto LABEL_22;
			v16 = v18 - *v11 - v24;
		}
		*(_DWORD*)(v2 + 648) = v16;
		*v13 = 0;
	LABEL_22:
		v19 = v3[1] + 2 * v24 + 2;
		v20 = *(_DWORD*)(v2 + 652);
		if (v20 >= v19) {
			v21 = v3[3];
			if (v24 + *(_DWORD*)(v2 + 676) + v20 <= v21) {
			LABEL_26:
				a1a.field_0 = *(_DWORD*)(v2 + 648);
				a1a.field_4 = *(_DWORD*)(v2 + 652);
				a1a.field_8 = *(_DWORD*)(v2 + 648) + *v11;
				a1a.field_C = *(_DWORD*)(v2 + 676) + *(_DWORD*)(v2 + 652);
				sub_48E000(&a1a, (_DWORD*)(v2 + 664));
				*(_DWORD*)(v2 + 648) = a1a.field_0;
				*(_DWORD*)(v2 + 652) = a1a.field_4;
				goto LABEL_27;
			}
			v19 = v21 - *(_DWORD*)(v2 + 676) - v24;
		}
		*(_DWORD*)(v2 + 652) = v19;
		*v13 = 0;
		goto LABEL_26;
	}
LABEL_37:
	while (v2) {
		sub_48E240((int)v3, (_DWORD*)v2);
		v2 = *(_DWORD*)(v2 + 684);
	}
}
// 48DD5E: variable 'v7' is possibly undefined
// 48DD72: variable 'v9' is possibly undefined

//----- (0048E000) --------------------------------------------------------
bool __cdecl sub_48E000(int4* a1, _DWORD* a2) {
	int v2;   // ebx
	BOOL v3;  // eax
	int v4;   // eax
	int v5;   // eax
	int v6;   // eax
	int v7;   // eax
	int v8;   // eax
	int v9;   // eax
	int4 v11; // [esp+10h] [ebp-10h]

	if (a1->field_0 < 0 || a1->field_4 < 0 || a1->field_8 > nox_win_width || a1->field_C > nox_win_height) {
		*a2 = 0;
	}
	v11.field_0 = 0;
	v11.field_4 = 0;
	v11.field_8 = 563;
	if (sub_467C80()) {
		v2 = 279;
		v11.field_C = 279;
		v3 = sub_4281F0((int2*)a1, &v11);
		if (v3 || (v3 = sub_4281F0((int2*)&a1->field_8, &v11), v3)) {
		LABEL_12:
			a1->field_4 = v2;
			*a2 = 0;
			goto LABEL_13;
		}
	} else {
		v2 = 55;
		v11.field_C = 55;
		v3 = sub_4281F0((int2*)a1, &v11);
		if (v3)
			goto LABEL_12;
		v3 = sub_4281F0((int2*)&a1->field_8, &v11);
		if (v3)
			goto LABEL_12;
	}
LABEL_13:
	if (nox_client_renderGUI_80828) {
		v11.field_0 = 0;
		v11.field_C = nox_win_height;
		v11.field_8 = 111;
		v11.field_4 = nox_win_height - 127;
		v4 = sub_4281F0((int2*)a1, &v11);
		if (v4 || (v5 = sub_4281F0((int2*)&a1->field_8, &v11), v5)) {
			a1->field_4 += v11.field_4 - a1->field_C;
			*a2 = 0;
		}
		v11.field_4 = nox_win_height - 74;
		v11.field_0 = nox_win_width / 2 - 160;
		v11.field_8 = v11.field_0 + 320;
		v11.field_C = nox_win_height;
		v6 = sub_4281F0((int2*)a1, &v11);
		if (v6 || (v7 = sub_4281F0((int2*)&a1->field_8, &v11), v7)) {
			a1->field_4 += v11.field_4 - a1->field_C;
			*a2 = 0;
		}
		v11.field_8 = nox_win_width;
		v11.field_0 = nox_win_width - 91;
		v11.field_C = nox_win_height;
		v11.field_4 = nox_win_height - 201;
		v8 = sub_4281F0((int2*)a1, &v11);
		if (v8 || (v9 = sub_4281F0((int2*)&a1->field_8, &v11), v9)) {
			a1->field_4 += v11.field_4 - a1->field_C;
			*a2 = 0;
		}
		v3 = sub_4C3260();
		if (v3) {
			v11.field_0 = nox_win_width - 87;
			v11.field_4 = 0;
			v11.field_8 = nox_win_width;
			v11.field_C = 145;
			v3 = sub_4281F0((int2*)a1, &v11);
			if (v3 || (v3 = sub_4281F0((int2*)&a1->field_8, &v11), v3)) {
				a1->field_4 = 145;
				*a2 = 0;
			}
		}
	}
	return v3;
}
// 48E069: variable 'v3' is possibly undefined
// 48E0EF: variable 'v4' is possibly undefined
// 48E104: variable 'v5' is possibly undefined
// 48E156: variable 'v6' is possibly undefined
// 48E16B: variable 'v7' is possibly undefined
// 48E1B4: variable 'v8' is possibly undefined
// 48E1C9: variable 'v9' is possibly undefined

//----- (0048E240) --------------------------------------------------------
char __cdecl sub_48E240(int a1, _DWORD* a2) {
	int v2;     // eax
	_DWORD* v3; // esi
	int v4;     // edi
	_DWORD* v5; // ebp
	char v6;    // bl
	int v7;     // edi
	int v8;     // edx
	int v9;     // edi
	int v10;    // edx
	int v12;    // [esp+Ch] [ebp-Ch]
	int v13;    // [esp+10h] [ebp-8h]
	int v14;    // [esp+14h] [ebp-4h]
	char v15;   // [esp+20h] [ebp+8h]

	LOBYTE(v2) = byte_5D4594[1197368];
	v3 = a2;
	if (a2 != *(_DWORD**)&byte_5D4594[1197368]) {
		v4 = 0;
		v5 = *(_DWORD**)&byte_5D4594[1197368];
		if (*(_DWORD*)&byte_5D4594[1197368]) {
			while (1) {
				v2 = v5[165];
				if (v2) {
					v2 = v5[170];
					if (v2 >= a2[170])
						goto LABEL_9;
					v2 = sub_48E480(a2, v5);
					if (v2)
						break;
				}
				v5 = (_DWORD*)v5[171];
				if (!v5)
					return v2;
			}
			v4 = 1;
		LABEL_9:
			if (v5 && v4) {
				v6 = 0;
				v15 = 0;
				switch (sub_48E530(v3[162] + v3[168] / 2, v3[163] + v3[169] / 2)) {
				case 17:
					v6 = -96;
					v15 = 8;
					break;
				case 18:
					v6 = 48;
					v15 = -118;
					break;
				case 20:
					v6 = -112;
					v15 = 2;
					break;
				case 33:
					v6 = -64;
					v15 = 44;
					break;
				case 34:
					v6 = -16;
					v15 = 15;
					break;
				case 36:
					v6 = -64;
					v15 = 19;
					break;
				case 65:
					v6 = 96;
					v15 = 4;
					break;
				case 66:
					v6 = 48;
					v15 = 69;
					break;
				case 68:
					v6 = 80;
					v15 = 1;
					break;
				default:
					break;
				}
				v7 = 0;
				while (1) {
					LOBYTE(v2) = 1 << v7;
					LOBYTE(v14) = 1 << v7;
					if ((unsigned __int8)(1 << v7) & (unsigned __int8)v6) {
						sub_48E6A0(v14, v3, v5, &v12, &v13);
						v2 = sub_48E5C0(v3, v12, v13);
						if (v2)
							break;
					}
					if (++v7 >= 8)
						goto LABEL_27;
				}
				v8 = v13;
				v3[162] = v12;
				v3[163] = v8;
			LABEL_27:
				if (v7 == 8) {
					v9 = 0;
					while (1) {
						LOBYTE(v2) = 1 << v9;
						LOBYTE(v14) = 1 << v9;
						if ((unsigned __int8)(1 << v9) & (unsigned __int8)v15) {
							sub_48E6A0(v14, v3, v5, &v12, &v13);
							v2 = sub_48E5C0(v3, v12, v13);
							if (v2)
								break;
						}
						if (++v9 >= 8)
							return v2;
					}
					v10 = v13;
					v3[162] = v12;
					v3[163] = v10;
				}
			}
		}
	}
	return v2;
}

//----- (0048E480) --------------------------------------------------------
BOOL __cdecl sub_48E480(_DWORD* a1, _DWORD* a2) {
	int v2; // eax
	int v3; // esi
	int v4; // edx
	int v5; // ebx
	int v7; // [esp+24h] [ebp-Ch]
	int v8; // [esp+34h] [ebp+4h]

	v2 = sub_43F320(0);
	v3 = a1[162];
	v7 = a1[163] - v2;
	v4 = v2 + v3 + a1[168];
	v5 = v2 + a1[163] + a1[169];
	v8 = a2[163];
	return v3 - v2 < v2 + a2[162] + a2[168] && v4 > a2[162] - v2 && v7 < v2 + v8 + a2[169] && v5 > v8 - v2;
}

//----- (0048E530) --------------------------------------------------------
int __cdecl sub_48E530(int a1, int a2) {
	int v2; // edi
	int v3; // eax

	if (a1 >= nox_win_width / 3) {
		v3 = (a1 >= 2 * nox_win_width / 3) - 1;
		LOBYTE(v3) = v3 & 0xE0;
		v2 = v3 + 64;
	} else {
		v2 = 16;
	}
	if (a2 < nox_win_height / 3)
		return v2 | 1;
	if (a2 >= 2 * nox_win_height / 3)
		return v2 | 4;
	return v2 | 2;
}

//----- (0048E5C0) --------------------------------------------------------
int __cdecl sub_48E5C0(_DWORD* a1, int a2, int a3) {
	int v3;     // edx
	int v4;     // eax
	_DWORD* v6; // edi
	int v7;     // ebx
	int v8;     // ebp
	BOOL v9;    // eax
	BOOL a2a;   // [esp+10h] [ebp-14h]
	int4 a1a;   // [esp+14h] [ebp-10h]

	a2a = 1;
	sub_43F320(0);
	a1a.field_0 = a2;
	v3 = a1[168];
	a1a.field_4 = a3;
	v4 = a3 + a1[169];
	a1a.field_8 = a2 + v3;
	a1a.field_C = v4;
	sub_48E000(&a1a, &a2a);
	if (!a2a)
		return 0;
	v6 = *(_DWORD**)&byte_5D4594[1197368];
	if (*(_DWORD*)&byte_5D4594[1197368]) {
		while (1) {
			if (a1[165]) {
				if (v6[170] >= a1[170])
					return 1;
				v7 = a1[162];
				v8 = a1[163];
				a1[162] = a2;
				a1[163] = a3;
				v9 = sub_48E480(a1, v6);
				a2a = v9;
				a1[162] = v7;
				a1[163] = v8;
				if (v9)
					break;
			}
			v6 = (_DWORD*)v6[171];
			if (!v6)
				return 1;
		}
		return 0;
	}
	return 1;
}

//----- (0048E6A0) --------------------------------------------------------
int* __cdecl sub_48E6A0(char a1, _DWORD* a2, _DWORD* a3, int* a4, int* a5) {
	int* result; // eax
	int v6;      // ecx
	_DWORD* v7;  // ecx
	int v8;      // edx
	char* v9;    // edx
	int v10;     // edx

	result = (int*)(2 * sub_43F320(0));
	switch (a1) {
	case 1:
		*a4 = a3[162] - a2[168] - (_DWORD)result;
		*a5 = a3[163] - a2[169] - (_DWORD)result;
		return result;
	case 2:
		*a4 = (int)result + a3[162] + a3[168];
		v6 = a3[163] - a2[169] - (_DWORD)result;
		result = a5;
		*a5 = v6;
		return result;
	case 4:
		v7 = a3;
		*a4 = a3[162] - a2[168] - (_DWORD)result;
		goto LABEL_8;
	case 8:
		v7 = a3;
		*a4 = (int)result + a3[162] + a3[168];
		goto LABEL_8;
	case 0x10:
		*a4 = a2[162];
		v8 = a3[163] - a2[169] - (_DWORD)result;
		result = a5;
		*a5 = v8;
		return result;
	case 0x20:
		*a4 = a2[162];
		v7 = a3;
	LABEL_8:
		v9 = (char*)result + v7[163] + v7[169];
		result = a5;
		*a5 = (int)v9;
		break;
	case 0x40:
		v10 = a3[162] - a2[168] - (_DWORD)result;
		result = a4;
		*a4 = v10;
		*a5 = a2[163];
		break;
	case 0x80:
		*a4 = (int)result + a3[162] + a3[168];
		result = a5;
		*a5 = a2[163];
		break;
	default:
		return result;
	}
	return result;
}

//----- (0048E8E0) --------------------------------------------------------
void __cdecl sub_48E8E0(int a1) {
	int v1; // eax
	int v2; // ecx
	int v3; // ecx

	v1 = sub_48D850(a1);
	if (v1) {
		v2 = *(_DWORD*)(v1 + 688);
		if (v2)
			*(_DWORD*)(v2 + 684) = *(_DWORD*)(v1 + 684);
		else
			*(_DWORD*)&byte_5D4594[1197368] = *(_DWORD*)(v1 + 684);
		v3 = *(_DWORD*)(v1 + 684);
		if (v3)
			*(_DWORD*)(v3 + 688) = *(_DWORD*)(v1 + 688);
		sub_414330(*(unsigned int**)&nox_alloc_chat_1197364, (_QWORD*)v1);
	}
}

//----- (0048E940) --------------------------------------------------------
void sub_48E940() {
	sub_4144D0(*(_DWORD**)&nox_alloc_chat_1197364);
	*(_DWORD*)&byte_5D4594[1197368] = 0;
}

//----- (0048E960) --------------------------------------------------------
void sub_48E960() { nox_srand(0xA32u); }

//----- (0048E970) --------------------------------------------------------
_DWORD* __cdecl sub_48E970(int a1, unsigned int a2, int a3, int a4) {
	int v4;     // eax
	int v5;     // ebx
	_DWORD* v6; // eax
	_DWORD* v7; // esi
	int v8;     // eax
	int v10;    // [esp-4h] [ebp-10h]

	v4 = sub_578B30(a2);
	v5 = v4;
	v10 = v4;
	if (sub_578B70(a2))
		v6 = sub_45A720(v10);
	else
		v6 = sub_45A6F0(v10);
	v7 = v6;
	if (v6) {
		sub_49AA90(v6, a3, a4);
	} else {
		if (!*(_DWORD*)&byte_5D4594[1200836])
			*(_DWORD*)&byte_5D4594[1200836] = sub_44CFC0((CHAR*)&byte_587000[157096]);
		if (!*(_DWORD*)&byte_5D4594[1200840])
			*(_DWORD*)&byte_5D4594[1200840] = sub_44CFC0((CHAR*)&byte_587000[157104]);
		v8 = sub_45A360_drawable(a1, a3, a4);
		v7 = (_DWORD*)v8;
		if (!v8) {
			sub_4356E0();
			return 0;
		}
		*(_DWORD*)(v8 + 128) = v5;
		if (a1 == *(_DWORD*)&byte_5D4594[1200836] || a1 == *(_DWORD*)&byte_5D4594[1200840] ||
			*(_DWORD*)(v8 + 112) & 0x10000000) {
			sub_459DD0(v8, 1);
		}
	}
	sub_45A990_drawable((int)v7);
	sub_49BA10(v7);
	v7[80] = *(_DWORD*)&byte_5D4594[2598000];
	v7[122] = 0;
	return v7;
}
// 48E97E: variable 'v4' is possibly undefined

// 48EC64: variable 'v16' is possibly undefined
// 48ECC4: variable 'v18' is possibly undefined
// 48ED16: variable 'v20' is possibly undefined
// 48EDD6: variable 'v24' is possibly undefined
// 48F160: variable 'v31' is possibly undefined
// 48F596: variable 'v40' is possibly undefined
// 48F671: variable 'v42' is possibly undefined
// 48F6EB: variable 'v44' is possibly undefined
// 48F793: variable 'v49' is possibly undefined
// 48F831: variable 'v54' is possibly undefined
// 48F929: variable 'v57' is possibly undefined
// 48F952: variable 'v59' is possibly undefined
// 48FAB0: variable 'v62' is possibly undefined
// 48FB1E: variable 'v64' is possibly undefined
// 48FD0B: variable 'v69' is possibly undefined
// 48FDA2: variable 'v71' is possibly undefined
// 48FE68: variable 'v77' is possibly undefined
// 48FEFD: variable 'v82' is possibly undefined
// 48FF39: variable 'k' is possibly undefined
// 48FF58: variable 'v84' is possibly undefined
// 49008E: variable 'v88' is possibly undefined
// 490118: variable 'v90' is possibly undefined
// 490281: variable 'v92' is possibly undefined
// 4902D3: variable 'v94' is possibly undefined
// 490334: variable 'v96' is possibly undefined
// 490394: variable 'v98' is possibly undefined
// 4904D6: variable 'v103' is possibly undefined
// 49056F: variable 'v105' is possibly undefined
// 49060D: variable 'v109' is possibly undefined
// 49096A: variable 'v120' is possibly undefined
// 4909AC: variable 'v122' is possibly undefined
// 4909ED: variable 'v124' is possibly undefined
// 490AC3: variable 'v129' is possibly undefined
// 490B3C: variable 'v132' is possibly undefined
// 490C1D: variable 'v137' is possibly undefined
// 490CFC: variable 'v140' is possibly undefined
// 490FE2: variable 'v152' is possibly undefined
// 491687: variable 'v178' is possibly undefined
// 4916D9: variable 'v180' is possibly undefined
// 491710: variable 'v5' is possibly undefined
// 49172D: variable 'v182' is possibly undefined
// 491768: variable 'v184' is possibly undefined
// 49180F: variable 'v189' is possibly undefined
// 49187C: variable 'v193' is possibly undefined
// 4918F3: variable 'v196' is possibly undefined
// 491AA8: variable 'v198' is possibly undefined
// 491D48: variable 'v209' is possibly undefined
// 491EEA: variable 'v214' is possibly undefined
// 49252B: variable 'v236' is possibly undefined
// 49308F: variable 'v274' is possibly undefined
// 493335: variable 'v281' is possibly undefined
// 493364: variable 'v283' is possibly undefined
// 493378: variable 'v284' is possibly undefined
// 493639: variable 'v291' is possibly undefined
// 493696: variable 'v293' is possibly undefined
// 4936AF: variable 'v294' is possibly undefined
// 4939A7: variable 'v297' is possibly undefined
// 467460: using guessed type int sub_467460(void);

//----- (004947E0) --------------------------------------------------------
char* __cdecl sub_4947E0(int a1) {
	__int16 v1;   // ax
	int v2;       // edi
	char* result; // eax
	int i;        // esi

	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_common_gameFlags_getVal_40A5B0();
		v2 = (unsigned __int16)sub_40A020(v1);
	} else {
		v2 = *((unsigned __int16*)sub_416590(0) + 27);
	}
	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (!(*(_BYTE*)(i + 3680) & 1)) {
			if (i == a1) {
				if (nox_common_gameFlags_check_40A5C0(1024)) {
					if (*(_DWORD*)(i + 2140) >= v2)
						*(_DWORD*)(i + 2140) = v2 - 1;
				} else {
					*(_DWORD*)(i + 2136) = v2;
				}
			} else if (nox_common_gameFlags_check_40A5C0(1024)) {
				if (*(_DWORD*)(i + 2140) < v2)
					*(_DWORD*)(i + 2140) = v2;
			} else if (*(_DWORD*)(i + 2136) >= v2) {
				*(_DWORD*)(i + 2136) = v2 - 1;
			}
		}
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (004948B0) --------------------------------------------------------
int __cdecl sub_4948B0(int a1) {
	__int16 v1; // ax
	int v2;     // edi
	char* i;    // esi
	int result; // eax
	int j;      // ebp
	char* v6;   // eax
	char* v7;   // esi
	int k;      // ebp
	char* v9;   // eax
	char* v10;  // esi

	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_common_gameFlags_getVal_40A5B0();
		v2 = (unsigned __int16)sub_40A020(v1);
	} else {
		v2 = *((unsigned __int16*)sub_416590(0) + 27);
	}
	for (i = sub_418B10(); i; i = sub_418B60((int)i)) {
		if (i == (char*)a1) {
			if (!nox_common_gameFlags_check_40A5C0(1024))
				*((_DWORD*)i + 13) = v2;
		} else if (!nox_common_gameFlags_check_40A5C0(1024) && *((_DWORD*)i + 13) >= v2) {
			*((_DWORD*)i + 13) = v2 - 1;
		}
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		result = sub_4DA7C0();
		for (j = result; result; j = result) {
			if (!sub_419180(j + 48, *(_BYTE*)(a1 + 57))) {
				v6 = sub_417040(*(_DWORD*)(j + 36));
				v7 = v6;
				if (v6) {
					if (!(v6[3680] & 1)) {
						if (nox_common_gameFlags_check_40A5C0(1024)) {
							if (*((_DWORD*)v7 + 535) < v2)
								*((_DWORD*)v7 + 535) = v2;
						} else if (*((_DWORD*)v7 + 534) >= v2) {
							*((_DWORD*)v7 + 534) = v2 - 1;
						}
					}
				}
			}
			result = sub_4DA7F0(j);
		}
	} else {
		result = sub_45A000();
		for (k = result; result; k = result) {
			if (!sub_419180(k + 24, *(_BYTE*)(a1 + 57))) {
				v9 = sub_417040(*(_DWORD*)(k + 128));
				v10 = v9;
				if (v9) {
					if (!(v9[3680] & 1)) {
						if (nox_common_gameFlags_check_40A5C0(1024)) {
							if (*((_DWORD*)v10 + 535) < v2)
								*((_DWORD*)v10 + 535) = v2;
						} else if (*((_DWORD*)v10 + 534) >= v2) {
							*((_DWORD*)v10 + 534) = v2 - 1;
						}
					}
				}
			}
			result = sub_45A010(k);
		}
	}
	return result;
}

//----- (00494A60) --------------------------------------------------------
int __cdecl sub_494A60(unsigned __int8* a1, int a2, _DWORD* a3) {
	unsigned __int16 v3;  // di
	unsigned __int16 v4;  // bp
	unsigned __int8* v5;  // esi
	int v6;               // ebx
	int v7;               // eax
	unsigned __int16 v8;  // ax
	unsigned __int16 v9;  // cx
	unsigned __int8* v10; // esi
	unsigned __int8 v11;  // bl
	unsigned __int8* v12; // esi
	unsigned __int8 v13;  // dl
	unsigned __int8 v14;  // dl
	int v15;              // esi
	_DWORD* v16;          // eax
	unsigned __int8 v17;  // cl
	int v18;              // edx
	unsigned __int16 v20; // [esp+10h] [ebp-18h]
	unsigned __int16 v21; // [esp+14h] [ebp-14h]
	unsigned __int8* v22; // [esp+18h] [ebp-10h]
	char v23[10];         // [esp+1Ch] [ebp-Ch]
	unsigned __int8 v24;  // [esp+2Ch] [ebp+4h]
	unsigned __int8 v25;  // [esp+2Ch] [ebp+4h]
	unsigned __int8 v26;  // [esp+30h] [ebp+8h]

	v22 = a1;
	if (*a1 == 0xFFu) {
		v3 = *(_WORD*)(a1 + 1);
		v4 = *(_WORD*)(a1 + 3);
		v5 = a1 + 5;
		v6 = *(unsigned __int16*)(a1 + 3);
		v24 = sub_57B9A0((int)&byte_5D4594[1198020], v3, v6, *(unsigned int*)&byte_5D4594[2598000]);
		if (v24 != -1) {
			sub_57BA10((int)&byte_5D4594[8 * v24 + 1198020], v3, v6, -1);
			v23[0] = -91;
			*(_WORD*)&v23[2] = v3;
			*(_WORD*)&v23[4] = v4;
			v23[1] = v24;
			*(_DWORD*)&v23[6] = -1;
			sub_40EBC0(a2, 0, v23, 10);
		}
	} else {
		v7 = 8 * *a1;
		v5 = a1 + 1;
		v3 = *(_WORD*)&byte_5D4594[v7 + 1198020];
		v4 = *(_WORD*)&byte_5D4594[v7 + 1198022];
	}
	v8 = *(_WORD*)v5;
	v9 = *((_WORD*)v5 + 1);
	v20 = *(_WORD*)v5;
	v10 = v5 + 4;
	v21 = v9;
	v11 = *v10;
	v12 = v10 + 1;
	if ((v11 & 0x80u) == 0) {
		v25 = 0;
	} else {
		v13 = *v12++;
		v25 = v13;
	}
	v14 = *v12;
	v15 = (int)(v12 + 1);
	v26 = v14;
	if (v3 || v4) {
		v16 = sub_48E970(v4, v3, v8, v9);
		if (v16) {
			v16[72] = *(_DWORD*)&byte_5D4594[2598000];
			v17 = (v11 >> 4) & 7;
			*((_BYTE*)v16 + 297) = v17;
			if (v17 > 3u)
				*((_BYTE*)v16 + 297) = v17 + 1;
			if (v16[69] != v26) {
				v18 = *(_DWORD*)&byte_5D4594[2598000];
				v16[69] = v26;
				v16[79] = v18;
			}
			sub_45AB80((int)v16, v25);
		}
	}
	*a3 = v20;
	a3[1] = v21;
	sub_435600(v20, v21);
	return v15 - (_DWORD)v22;
}

//----- (00494C30) --------------------------------------------------------
unsigned __int8* __cdecl sub_494C30(unsigned __int8* a1, int a2, int* a3) {
	unsigned __int8* v3; // esi
	unsigned __int8 v4;  // al
	unsigned __int16 v6; // di
	_WORD* v7;           // esi
	unsigned __int16 v8; // bp
	unsigned __int16 v9; // bx
	__int16* v10;        // esi
	int v11;             // eax
	int v12;             // ecx
	int* v13;            // ebx
	int v14;             // esi
	int v15;             // eax
	int v16;             // ecx
	int v17;             // eax
	_DWORD* v18;         // eax
	int v19;             // edi
	char v20;            // cl
	unsigned __int8 v21; // al
	unsigned __int8 v22; // dl
	int v23;             // ecx
	unsigned __int8 v24; // [esp+10h] [ebp-18h]
	int v25;             // [esp+14h] [ebp-14h]
	char v26[10];        // [esp+1Ch] [ebp-Ch]
	char v27;            // [esp+34h] [ebp+Ch]
	unsigned __int8 v28; // [esp+34h] [ebp+Ch]

	v3 = a1;
	v4 = *a1;
	v25 = 0;
	if (!*a1) {
		v4 = a1[1];
		v3 = a1 + 1;
		if (!v4 && !a1[2])
			return (unsigned __int8*)-3;
		v25 = 1;
	}
	if (v4 == 0xFFu) {
		v6 = *(_WORD*)(v3 + 1);
		v7 = v3 + 3;
		v8 = *v7;
		v9 = *v7;
		v10 = v7 + 1;
		v24 = sub_57B9A0((int)&byte_5D4594[1198020], v6, v9, *(unsigned int*)&byte_5D4594[2598000]);
		if (v24 != -1) {
			sub_57BA10((int)&byte_5D4594[8 * v24 + 1198020], v6, v9, *(_DWORD*)&byte_5D4594[2598000] + 60);
			v26[1] = v24;
			v26[0] = -91;
			*(_WORD*)&v26[2] = v6;
			*(_WORD*)&v26[4] = v8;
			*(_DWORD*)&v26[6] = *(_DWORD*)&byte_5D4594[2598000] + 60;
			sub_40EBC0(a2, 0, v26, 10);
		}
	} else {
		v11 = 8 * v4;
		v10 = (__int16*)(v3 + 1);
		v6 = *(_WORD*)&byte_5D4594[v11 + 1198020];
		v8 = *(_WORD*)&byte_5D4594[v11 + 1198022];
	}
	if (v25) {
		v12 = *v10;
		v13 = a3;
		v14 = (int)(v10 + 2);
		*a3 = v12;
		a3[1] = *(__int16*)(v14 - 2);
	} else {
		v13 = a3;
		v15 = *(char*)v10;
		v14 = (int)(v10 + 1);
		*a3 += v15;
		a3[1] += *(char*)(v14 - 1);
	}
	v16 = *v13;
	if ((int)*v13 < 0)
		return &a1[-v14];
	if (v16 > 6000)
		return &a1[-v14];
	v17 = v13[1];
	if (v17 < 0)
		return &a1[-v14];
	if (v17 > 6000)
		return &a1[-v14];
	v18 = sub_48E970(v8, v6, v16, v13[1]);
	v19 = (int)v18;
	if (!v18)
		return &a1[-v14];
	if (v18[28] & 0x200000) {
		v18[72] = *(_DWORD*)&byte_5D4594[2598000];
		v27 = *(_BYTE*)v14;
		v20 = *(_BYTE*)v14;
		v21 = (*(_BYTE*)v14 >> 4) & 7;
		*(_BYTE*)(v19 + 297) = v21;
		if (v21 > 3u)
			*(_BYTE*)(v19 + 297) = v21 + 1;
		if (v20 < 0) {
			sub_45AB80(v19, *(unsigned __int8*)++v14);
			v20 = v27;
		}
		if (*(_BYTE*)(v19 + 112) & 4) {
			v22 = *(_BYTE*)++v14;
			v28 = v22;
		} else {
			v28 = v20 & 0xF;
		}
		if (*(_DWORD*)(v19 + 276) != v28) {
			v23 = *(_DWORD*)&byte_5D4594[2598000];
			*(_DWORD*)(v19 + 276) = v28;
			*(_DWORD*)(v19 + 316) = v23;
		}
		++v14;
	} else {
		v18[72] = *(_DWORD*)&byte_5D4594[2598000];
		sub_49AA00_drawable(v18);
	}
	*v13 = *(_DWORD*)(v19 + 12);
	v13[1] = *(_DWORD*)(v19 + 16);
	return (unsigned __int8*)(v14 - (_DWORD)a1);
}

//----- (00494E90) --------------------------------------------------------
int __cdecl sub_494E90(int a1) {
	int v1;              // esi
	unsigned __int8* v2; // eax
	int v3;              // edi
	unsigned __int8* v4; // eax
	int v5;              // esi

	v1 = a1;
	v2 = sub_40F120(a1, &a1);
	if (v2)
		v3 = sub_48EA70(v1, (unsigned int)v2, a1);
	else
		v3 = a1;
	v4 = sub_40ED60(v1, 1u, &a1);
	if (!v4)
		return v3;
	v5 = sub_48EA70(v1, (unsigned int)v4, a1);
	if (v5)
		sub_48D660();
	return v5;
}

//----- (00494F00) --------------------------------------------------------
int sub_494F00() {
	int result; // eax
	int v1;     // esi
	int v2;     // eax

	*(_DWORD*)&byte_5D4594[1200772] = sub_44CFC0((CHAR*)&byte_587000[161236]);
	if (!*(_DWORD*)&byte_5D4594[1200772])
		return 0;
	result = sub_44CFC0((CHAR*)&byte_587000[161244]);
	dword_5d4594_1200776 = result;
	if (result) {
		result = sub_44CFC0((CHAR*)&byte_587000[161256]);
		*(_DWORD*)&byte_5D4594[1200780] = result;
		if (result) {
			result = sub_44CFC0((CHAR*)&byte_587000[161268]);
			*(_DWORD*)&byte_5D4594[1200784] = result;
			if (result) {
				result = sub_44CFC0((CHAR*)&byte_587000[161280]);
				*(_DWORD*)&byte_5D4594[1200788] = result;
				if (result) {
					result = sub_44CFC0((CHAR*)&byte_587000[161292]);
					*(_DWORD*)&byte_5D4594[1200792] = result;
					if (result) {
						v1 = 0;
						while (1) {
							v2 = sub_44CFC0(*(CHAR**)&byte_587000[v1 + 161216]);
							*(_DWORD*)&byte_5D4594[v1 + 1200812] = v2;
							if (!v2)
								break;
							v1 += 4;
							if (v1 >= 20) {
								dword_5d4594_1200796 = sub_44CFC0((CHAR*)&byte_587000[161376]);
								return dword_5d4594_1200796 != 0;
							}
						}
						return 0;
					}
				}
			}
		}
	}
	return result;
}

//----- (00494FE0) --------------------------------------------------------
void sub_494FE0() { nox_srand(0xA33u); }

//----- (00494FF0) --------------------------------------------------------
char* sub_494FF0() {
	int v0;              // eax
	unsigned __int8* v1; // ecx

	v0 = 0;
	v1 = &byte_5D4594[1200928];
	while (*(_DWORD*)v1) {
		v1 += 16;
		++v0;
		if ((int)v1 >= (int)&byte_5D4594[1201440])
			return 0;
	}
	return (char*)&byte_5D4594[16 * v0 + 1200916];
}

//----- (00495020) --------------------------------------------------------
char* __cdecl sub_495020(int a1) {
	int v1;              // eax
	unsigned __int8* v2; // ecx

	v1 = 0;
	v2 = &byte_5D4594[1200916];
	while (!*((_DWORD*)v2 + 3) || *(_DWORD*)v2 != a1) {
		v2 += 16;
		++v1;
		if ((int)v2 >= (int)&byte_5D4594[1201428])
			return 0;
	}
	return (char*)&byte_5D4594[16 * v1 + 1200916];
}

//----- (00495060) --------------------------------------------------------
int __cdecl sub_495060(int a1, __int16 a2, __int16 a3) {
	unsigned __int8* v3; // eax
	char* v4;            // eax

	v3 = &byte_5D4594[1200916];
	do {
		if (*((_DWORD*)v3 + 3) == 1 && *(_DWORD*)v3 == a1)
			return 1;
		v3 += 16;
	} while ((int)v3 < (int)&byte_5D4594[1201428]);
	v4 = sub_494FF0();
	if (v4) {
		*((_WORD*)v4 + 3) = a2;
		*((_WORD*)v4 + 4) = a3;
		*((_DWORD*)v4 + 3) = 1;
		v4[4] = 0;
		*(_DWORD*)v4 = a1;
		return 1;
	}
	return 0;
}

//----- (004950C0) --------------------------------------------------------
int __cdecl sub_4950C0(int a1) {
	char* v1; // eax

	v1 = sub_495020(a1);
	if (!v1)
		return 0;
	*((_DWORD*)v1 + 3) = 0;
	return 1;
}

//----- (004950F0) --------------------------------------------------------
int __cdecl sub_4950F0(int a1, char a2) {
	char* v2; // eax

	v2 = sub_495020(a1);
	if (!v2)
		return 0;
	v2[4] = a2;
	return 1;
}

//----- (00495120) --------------------------------------------------------
int __cdecl sub_495120(int a1, __int16 a2, __int16 a3) {
	char* v3; // eax

	v3 = sub_495020(a1);
	if (!v3)
		return 0;
	*((_WORD*)v3 + 3) = a2;
	*((_WORD*)v3 + 4) = a3;
	return 1;
}

//----- (00495150) --------------------------------------------------------
int __cdecl sub_495150(int a1, __int16 a2) {
	char* v2; // eax

	v2 = sub_495020(a1);
	if (!v2)
		return 0;
	*((_WORD*)v2 + 3) = a2;
	return 1;
}

//----- (00495180) --------------------------------------------------------
int __cdecl sub_495180(int a1, _WORD* a2, _WORD* a3, _BYTE* a4) {
	char* v4; // eax

	v4 = sub_495020(a1);
	if (!v4)
		return 0;
	*a2 = *((_WORD*)v4 + 3);
	*a3 = *((_WORD*)v4 + 4);
	*a4 = v4[4];
	return 1;
}

//----- (004951C0) --------------------------------------------------------
char* sub_4951C0() {
	char* result; // eax

	result = (char*)&byte_5D4594[1200922];
	do {
		*(_DWORD*)(result + 6) = 0;
		*(_WORD*)result = 0;
		*((_WORD*)result + 1) = 0;
		*(result - 2) = 0;
		*(_DWORD*)(result - 6) = 0;
		result += 16;
	} while ((int)result < (int)&byte_5D4594[1201434]);
	return result;
}

//----- (004951F0) --------------------------------------------------------
BOOL __cdecl sub_4951F0(int a1) { return sub_495020(a1) != 0; }

//----- (00495210) --------------------------------------------------------
int __cdecl sub_495210(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // eax

	v1 = dword_5d4594_1203836;
	if ((dword_5d4594_1203836 + 1) % 100 == dword_5d4594_1203840)
		dword_5d4594_1203840 = (dword_5d4594_1203840 + 1) % 100;
	if (*(_BYTE*)(a1 + 10) == 1) {
		v2 = *(unsigned __int16*)(a1 + 8);
		if ((unsigned __int16)v2 == *(_DWORD*)&byte_5D4594[1203844]) {
			*(_WORD*)(a1 + 8) = *(_WORD*)&byte_5D4594[1203856];
		LABEL_8:
			v1 = dword_5d4594_1203836;
			goto LABEL_9;
		}
		if (v2 == *(_DWORD*)&byte_5D4594[1203848]) {
			*(_WORD*)(a1 + 8) = *(_WORD*)&byte_5D4594[1203852];
			goto LABEL_8;
		}
	}
LABEL_9:
	v3 = 24 * v1;
	*(_DWORD*)&byte_5D4594[v3 + 1201428] = *(unsigned __int16*)(a1 + 2);
	*(_DWORD*)&byte_5D4594[v3 + 1201432] = *(unsigned __int16*)(a1 + 4);
	*(_DWORD*)&byte_5D4594[v3 + 1201436] = *(unsigned __int16*)(a1 + 6);
	*(_DWORD*)&byte_5D4594[v3 + 1201440] = *(unsigned __int16*)(a1 + 8);
	*(_DWORD*)&byte_5D4594[v3 + 1201444] = *(unsigned __int8*)(a1 + 10);
	*(_DWORD*)&byte_5D4594[v3 + 1201448] = *(_DWORD*)&byte_5D4594[2598000];
	dword_5d4594_1203836 = (v1 + 1) % 100;
	return sub_4952E0((_WORD*)a1);
}

//----- (00495430) --------------------------------------------------------
int sub_495430() {
	int v0;     // ecx
	int v1;     // esi
	int result; // eax
	int i;      // edi
	__int64 v4; // rtt

	dword_5d4594_1203832 = 0;
	nox_client_drawEnableAlpha_434560(0);
	sub_4345F0(0);
	sub_434600(0);
	v0 = dword_5d4594_1203840;
	v1 = dword_5d4594_1203840;
	result = dword_5d4594_1203836;
	for (i = nox_win_height / 4 / 36; v1 != dword_5d4594_1203836; v1 = (v1 + 1) % 100) {
		if (dword_5d4594_1203832 > i)
			break;
		if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[24 * v0 + 1201448]) <= 0x5A) {
			sub_495500((int*)&byte_5D4594[24 * v1 + 1201428]);
			v0 = dword_5d4594_1203840;
			++dword_5d4594_1203832;
		} else {
			v4 = v0 + 1;
			v0 = (v0 + 1) % 100;
			dword_5d4594_1203840 = v4 % 100;
		}
		result = dword_5d4594_1203836;
	}
	return result;
}

//----- (00495500) --------------------------------------------------------
int* __cdecl sub_495500(int* a1) {
	int v1;          // edi
	int v2;          // eax
	int v3;          // ebp
	bool v4;         // zf
	char* v5;        // eax
	char* v6;        // eax
	char* v7;        // eax
	int v8;          // ebp
	int v11;         // esi
	int v12;         // esi
	int v13;         // ecx
	int v14;         // kr04_4
	int v15;         // esi
	int v16;         // edi
	int v17;         // ebx
	int v18;         // esi
	int* result;     // eax
	int v20;         // esi
	int v21;         // [esp+10h] [ebp-DCh]
	int v22;         // [esp+14h] [ebp-D8h]
	int v23;         // [esp+18h] [ebp-D4h]
	int v24;         // [esp+1Ch] [ebp-D0h]
	int v25;         // [esp+20h] [ebp-CCh]
	int v26;         // [esp+24h] [ebp-C8h]
	int v27;         // [esp+28h] [ebp-C4h]
	wchar_t v28[32]; // [esp+2Ch] [ebp-C0h]
	wchar_t v29[32]; // [esp+6Ch] [ebp-80h]
	wchar_t v30[32]; // [esp+ACh] [ebp-40h]

	v1 = sub_43F360((char*)&byte_587000[161680]);
	v2 = *a1;
	v3 = 0;
	v4 = *a1 == 0;
	v24 = v1;
	v29[0] = 0;
	v28[0] = 0;
	v30[0] = 0;
	v23 = 0;
	v25 = 0;
	v27 = 0;
	v26 = 0;
	if (!v4) {
		v5 = sub_417040(v2);
		if (v5) {
			v3 = 1;
			nox_swprintf(v29, (const wchar_t*)v5 + 2352);
		}
	}
	if (a1[1]) {
		v6 = sub_417040(a1[1]);
		if (v6) {
			if (v3)
				nox_swprintf(v28, L"+%s", v6 + 4704);
			else
				nox_swprintf(v28, (const wchar_t*)v6 + 2352);
		}
	}
	if (a1[2]) {
		v7 = sub_417040(a1[2]);
		if (v7)
			nox_swprintf(v30, (const wchar_t*)v7 + 2352);
	}
	if (a1[4] != 1) {
		if (a1[4] == 2) {
			switch (a1[3]) {
			case 1:
			case 12:
				v8 = sub_424A90(5);
				goto LABEL_26;
			case 2:
				v8 = sub_425310(1, 0);
				goto LABEL_26;
			case 4:
				v8 = sub_424A90(130);
				goto LABEL_26;
			case 5:
				v8 = sub_424A90(60);
				goto LABEL_26;
			case 9:
			case 17:
				v8 = sub_424A90(43);
				goto LABEL_26;
			case 15:
				v8 = sub_424A90(56);
				goto LABEL_26;
			case 16:
				v8 = sub_424A90(16);
				goto LABEL_26;
			default:
				break;
			}
		}
	LABEL_27:
		v8 = *(_DWORD*)&byte_5D4594[1203828];
		goto LABEL_28;
	}
	nox_thing* t9 = nox_get_thing(a1[3]);
	if (!t9)
		goto LABEL_27;
	if (t9->pri_class & 0x1001000)
		sub_4B9650(a1[3]);
	v8 = t9->pretty_image;
LABEL_26:
	if (!v8)
		goto LABEL_27;
LABEL_28:
	sub_47D5C0(v8, &v27, &v26, &v23, &v25);
	sub_43F840(v1, v29, &v21, &v22, 0);
	v11 = v21;
	sub_43F840(v1, v28, &v21, &v22, 0);
	v12 = v21 + v11;
	sub_43F840(v1, v30, &v21, &v22, 0);
	v13 = v12 + v23 + v21 + 20;
	v14 = nox_win_width - (v12 + v23 + v21 + 10);
	v15 = v14 / 2;
	v16 = 36 * dword_5d4594_1203832;
	nox_client_drawRectFilledAlpha_49CF10(v14 / 2 - 5, 36 * dword_5d4594_1203832, v13, 36);
	v17 = v16 + (36 - v22) / 2;
	if (*a1) {
		sub_434390(*(int*)&byte_5D4594[2597996]);
		if (*a1 == *(_DWORD*)&byte_5D4594[2616328])
			sub_434390(*(int*)&byte_5D4594[2618904]);
		v15 = sub_43F6E0(v24, (__int16*)v29, v14 / 2, v17);
	}
	if (a1[1]) {
		sub_434390(*(int*)&byte_5D4594[2597996]);
		if (a1[1] == *(_DWORD*)&byte_5D4594[2616328])
			sub_434390(*(int*)&byte_5D4594[2618904]);
		v15 = sub_43F6E0(v24, (__int16*)v28, v15, v17);
	}
	v18 = v15 + 5;
	if (v8)
		nox_client_drawImageAt_47D2C0(v8, v18 - v27, v16 + (36 - v25) / 2 - v26);
	result = a1;
	v20 = v18 + v23 + 5;
	if (a1[2]) {
		sub_434390(*(int*)&byte_5D4594[2597996]);
		if (a1[2] == *(_DWORD*)&byte_5D4594[2616328])
			sub_434390(*(int*)&byte_5D4594[2618904]);
		result = (int*)sub_43F6E0(v24, (__int16*)v30, v20, v17);
	}
	return result;
}

//----- (004958F0) --------------------------------------------------------
int sub_4958F0() {
	int result; // eax

	dword_5d4594_1203840 = 0;
	dword_5d4594_1203836 = 0;
	if (!*(_DWORD*)&byte_5D4594[1203844])
		*(_DWORD*)&byte_5D4594[1203844] = sub_44CFC0((CHAR*)&byte_587000[161696]);
	if (!*(_DWORD*)&byte_5D4594[1203848])
		*(_DWORD*)&byte_5D4594[1203848] = sub_44CFC0((CHAR*)&byte_587000[161708]);
	if (!*(_DWORD*)&byte_5D4594[1203852])
		*(_DWORD*)&byte_5D4594[1203852] = sub_44CFC0((CHAR*)&byte_587000[161720]);
	if (!*(_DWORD*)&byte_5D4594[1203856])
		*(_DWORD*)&byte_5D4594[1203856] = sub_44CFC0((CHAR*)&byte_587000[161724]);
	result = sub_424A90(15);
	*(_DWORD*)&byte_5D4594[1203828] = result;
	return result;
}

//----- (00495980) --------------------------------------------------------
BOOL sub_495980() {
	nox_alloc_friendList_1203860 = nox_new_alloc_class("FriendListClass", 8, 128);
	return nox_alloc_friendList_1203860 != 0;
}

//----- (004959B0) --------------------------------------------------------
void sub_4959B0() {
	sub_4144D0(*(_DWORD**)&nox_alloc_friendList_1203860);
	dword_5d4594_1203864 = 0;
}

//----- (004959D0) --------------------------------------------------------
int sub_4959D0() {
	int result; // eax

	nox_free_alloc_class(*(LPVOID*)&nox_alloc_friendList_1203860);
	result = 0;
	nox_alloc_friendList_1203860 = 0;
	dword_5d4594_1203864 = 0;
	return result;
}

//----- (004959F0) --------------------------------------------------------
_DWORD* __cdecl sub_4959F0(int a1) {
	_DWORD* result; // eax

	result = nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_friendList_1203860);
	if (result) {
		*result = a1;
		result[1] = dword_5d4594_1203864;
		dword_5d4594_1203864 = result;
	}
	return result;
}

//----- (00495A20) --------------------------------------------------------
void __cdecl sub_495A20(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = dword_5d4594_1203864;
	v2 = 0;
	if (dword_5d4594_1203864) {
		while (*(_DWORD*)v1 != a1) {
			v2 = v1;
			v1 = *(_DWORD*)(v1 + 4);
			if (!v1)
				return;
		}
		if (v2)
			*(_DWORD*)(v2 + 4) = *(_DWORD*)(v1 + 4);
		else
			dword_5d4594_1203864 = *(_DWORD*)(v1 + 4);
		sub_414330(*(unsigned int**)&nox_alloc_friendList_1203860, (_QWORD*)v1);
	}
}

//----- (00495A80) --------------------------------------------------------
int __cdecl sub_495A80(int a1) {
	_DWORD* v1; // eax

	v1 = *(_DWORD**)&dword_5d4594_1203864;
	if (!dword_5d4594_1203864)
		return 0;
	while (*v1 != a1) {
		v1 = (_DWORD*)v1[1];
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (00495AB0) --------------------------------------------------------
int sub_495AB0() {
	int result; // eax

	result = nox_new_alloc_class("DrawableFX", 80, 128);
	*(_DWORD*)&byte_5D4594[1203868] = result;
	if (result) {
		*(_DWORD*)&byte_5D4594[1203872] = 0;
		result = 1;
	}
	return result;
}

//----- (00495AE0) --------------------------------------------------------
int sub_495AE0() {
	int result; // eax

	nox_free_alloc_class(*(LPVOID*)&byte_5D4594[1203868]);
	result = 0;
	*(_DWORD*)&byte_5D4594[1203868] = 0;
	*(_DWORD*)&byte_5D4594[1203872] = 0;
	return result;
}

//----- (00495B00) --------------------------------------------------------
void __cdecl sub_495B00(nox_drawable* dr) {
	int a1 = dr;
	_DWORD* v1; // esi
	_DWORD* v2; // edi

	v1 = *(_DWORD**)(a1 + 456);
	if (v1) {
		do {
			v2 = (_DWORD*)v1[16];
			sub_495B50(v1);
			sub_414330(*(unsigned int**)&byte_5D4594[1203868], v1);
			v1 = v2;
		} while (v2);
		*(_DWORD*)(a1 + 456) = 0;
	} else {
		*(_DWORD*)(a1 + 456) = 0;
	}
}

//----- (00495B50) --------------------------------------------------------
_DWORD* __cdecl sub_495B50(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx
	int v4;         // ecx
	int v5;         // edx
	int v6;         // ecx

	result = a1;
	if (a1) {
		v2 = a1[18];
		if (v2)
			*(_DWORD*)(v2 + 76) = a1[19];
		v3 = a1[19];
		if (v3)
			*(_DWORD*)(v3 + 72) = a1[18];
		else
			*(_DWORD*)&byte_5D4594[1203872] = a1[18];
		v4 = a1[16];
		v5 = a1[15];
		if (v4)
			*(_DWORD*)(v4 + 68) = a1[17];
		v6 = a1[17];
		if (v6) {
			*(_DWORD*)(v6 + 64) = a1[16];
		} else {
			result = (_DWORD*)a1[16];
			*(_DWORD*)(v5 + 456) = result;
		}
	}
	return result;
}

//----- (00495BB0) --------------------------------------------------------
_DWORD* __cdecl sub_495BB0(_DWORD* a1, _DWORD* a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // esi

	result = (_DWORD*)a1[114];
	if (result) {
		do {
			v3 = (_DWORD*)result[16];
			if (*result == 1) {
				sub_495BF0((int)a1, (int)result, (int)a2);
			} else if (*result == 2) {
				sub_495D00(a1, (int)result, a2);
			}
			result = v3;
		} while (v3);
	}
	return result;
}

//----- (00495BF0) --------------------------------------------------------
int __cdecl sub_495BF0(int a1, int a2, int a3) {
	int v3;              // ecx
	int result;          // eax
	_DWORD* v5;          // edx
	int v6;              // edx
	int v7;              // edi
	int v8;              // ebx
	_DWORD* v9;          // edi
	int v10;             // ecx
	_DWORD* v11;         // eax
	char v12;            // al
	unsigned __int8 v13; // [esp+10h] [ebp-Ch]
	int v14;             // [esp+14h] [ebp-8h]
	int v15;             // [esp+18h] [ebp-4h]

	v3 = 0;
	result = *(unsigned __int8*)(a2 + 56);
	v13 = -1;
	if (result <= 0) {
	LABEL_6:
		if (*(_DWORD*)(a1 + 12) == *(_DWORD*)(a1 + 32) && *(_DWORD*)(a1 + 16) == *(_DWORD*)(a1 + 36)) {
			*(_BYTE*)(a2 + 56) = 0;
			return result;
		}
	} else {
		v5 = (_DWORD*)(a2 + 8);
		while (*v5 == v5[2] || v5[1] == v5[3]) {
			++v3;
			v5 += 2;
			if (v3 >= result)
				goto LABEL_6;
		}
	}
	v6 = *(_DWORD*)(a1 + 12);
	v7 = *(_DWORD*)(a1 + 16);
	v8 = 0;
	v14 = *(_DWORD*)(a1 + 12);
	v15 = *(_DWORD*)(a1 + 16);
	if (result > 0) {
		v9 = (_DWORD*)(a2 + 8);
		do {
			v13 -= 42;
			nox_client_drawEnableAlpha_434560(1);
			nox_client_drawSetAlpha_434580(v13);
			*(_DWORD*)(a1 + 12) = *v9;
			*(_DWORD*)(a1 + 16) = v9[1];
			(*(void(__cdecl**)(int, int))(a1 + 300))(a3, a1);
			++v8;
			v9 += 2;
		} while (v8 < *(unsigned __int8*)(a2 + 56));
		v7 = v15;
		v6 = v14;
	}
	v10 = *(unsigned __int8*)(a2 + 56);
	if (v10 > 0) {
		v11 = (_DWORD*)(a2 + 8 * v10);
		do {
			v11[2] = *v11;
			v11[3] = v11[1];
			v11 -= 2;
			--v10;
		} while (v10);
	}
	*(_DWORD*)(a1 + 12) = v6;
	*(_DWORD*)(a1 + 16) = v7;
	v12 = *(_BYTE*)(a2 + 56);
	*(_DWORD*)(a2 + 8) = v6;
	*(_DWORD*)(a2 + 12) = v7;
	if (v12 != 5)
		*(_BYTE*)(a2 + 56) = v12 + 1;
	return nox_client_drawEnableAlpha_434560(0);
}

//----- (00495D00) --------------------------------------------------------
int __cdecl sub_495D00(_DWORD* a1, int a2, _DWORD* a3) {
	int v3;              // eax
	int v4;              // ecx
	_DWORD* v5;          // edx
	_DWORD* v6;          // ebp
	int result;          // eax
	_DWORD* v8;          // edi
	int v9;              // ebx
	int v10;             // esi
	int v11;             // ebx
	int v12;             // ecx
	int v13;             // esi
	int v14;             // ebp
	int v15;             // esi
	int v16;             // ebp
	int v17;             // eax
	bool v18;            // cc
	int v19;             // edx
	_DWORD* v20;         // eax
	char v21;            // al
	float v22;           // [esp+0h] [ebp-2Ch]
	float v23;           // [esp+0h] [ebp-2Ch]
	float v24;           // [esp+0h] [ebp-2Ch]
	float v25;           // [esp+0h] [ebp-2Ch]
	unsigned __int8 v26; // [esp+14h] [ebp-18h]
	int v27;             // [esp+18h] [ebp-14h]
	float* v28;          // [esp+1Ch] [ebp-10h]
	float* v29;          // [esp+20h] [ebp-Ch]
	int v30;             // [esp+28h] [ebp-4h]
	int v31;             // [esp+28h] [ebp-4h]
	_DWORD* v32;         // [esp+38h] [ebp+Ch]

	v3 = 0;
	v4 = *(unsigned __int8*)(a2 + 56);
	v26 = -1;
	if (v4 <= 0) {
	LABEL_6:
		v6 = a1;
		if (a1[3] == a1[8]) {
			result = a1[9];
			if (a1[4] == result) {
				*(_BYTE*)(a2 + 56) = 0;
				return result;
			}
		}
	} else {
		v5 = (_DWORD*)(a2 + 8);
		while (*v5 == v5[2] || v5[1] == v5[3]) {
			++v3;
			v5 += 2;
			if (v3 >= v4)
				goto LABEL_6;
		}
		v6 = a1;
	}
	v8 = a3;
	v9 = v6[3] + *a3 - a3[4];
	v10 = 8 * v6[77];
	v30 = v6[4] - *((__int16*)v6 + 52) - *((__int16*)v6 + 53) - a3[5] + a3[1] - 10;
	v28 = (float*)&byte_587000[64 * v6[77] + 194136];
	v22 = *(float*)&byte_587000[64 * v6[77] + 194136] * -12.0;
	v11 = nox_float2int(v22) + v9;
	v29 = (float*)&byte_587000[8 * v10 + 194140];
	v23 = *(float*)&byte_587000[8 * v10 + 194140] * -12.0;
	v27 = 0;
	v31 = nox_float2int(v23) + v30;
	v12 = a2;
	if (*(_BYTE*)(a2 + 56)) {
		v32 = (_DWORD*)(a2 + 12);
		do {
			v26 -= 63;
			nox_client_drawEnableAlpha_434560(1);
			nox_client_drawSetAlpha_434580(v26);
			v13 = *v8 + *(v32 - 1) - v8[4];
			v14 = *v32 - *((__int16*)v6 + 52) - *((__int16*)v6 + 53) - v8[5] + v8[1] - 10;
			v24 = *v28 * -12.0;
			v15 = nox_float2int(v24) + v13;
			v25 = *v29 * -12.0;
			v16 = nox_float2int(v25) + v14;
			v17 = sub_4344A0(200, 200, 200);
			nox_client_drawSetColor_434460(v17);
			nox_client_drawAddPoint_49F500(v11, v31);
			nox_client_drawAddPoint_49F500(v15, v16);
			nox_client_drawLineFromPoints_49E4B0();
			v12 = a2;
			v32 += 2;
			v31 = v16;
			v6 = a1;
			v18 = v27 + 1 < *(unsigned __int8*)(a2 + 56);
			v11 = v15;
			++v27;
		} while (v18);
	}
	v19 = *(unsigned __int8*)(v12 + 56);
	if (v19 > 0) {
		v20 = (_DWORD*)(v12 + 8 * v19);
		do {
			v20[2] = *v20;
			v20[3] = v20[1];
			v20 -= 2;
			--v19;
		} while (v19);
	}
	*(_DWORD*)(v12 + 8) = v6[3];
	*(_DWORD*)(v12 + 12) = v6[4];
	v21 = *(_BYTE*)(v12 + 56);
	if (v21 != 5)
		*(_BYTE*)(v12 + 56) = v21 + 1;
	return nox_client_drawEnableAlpha_434560(0);
}

//----- (00495F30) --------------------------------------------------------
void __cdecl sub_495F30(int a1, int a2) {
	_DWORD* v2; // esi

	v2 = *(_DWORD**)(a1 + 456);
	if (v2) {
		while (*v2 != a2) {
			v2 = (_DWORD*)v2[16];
			if (!v2)
				return;
		}
		sub_495B50(v2);
		sub_414330(*(unsigned int**)&byte_5D4594[1203868], v2);
	}
}

//----- (00495F70) --------------------------------------------------------
void __cdecl sub_495F70(int a1) {
	_DWORD* v1; // eax

	if (a1 && sub_496020(a1, 1) != 1) {
		v1 = nox_alloc_class_new_obj_zero(*(_DWORD**)&byte_5D4594[1203868]);
		if (v1) {
			*v1 = 1;
			v1[1] = 0;
			sub_495FC0(v1, a1);
		}
	}
}

//----- (00495FC0) --------------------------------------------------------
_DWORD* __cdecl sub_495FC0(_DWORD* a1, int a2) {
	_DWORD* result; // eax
	int v3;         // edx

	result = a1;
	if (a1 && a2) {
		a1[15] = a2;
		a1[18] = *(_DWORD*)&byte_5D4594[1203872];
		a1[19] = 0;
		if (*(_DWORD*)&byte_5D4594[1203872])
			*(_DWORD*)(*(_DWORD*)&byte_5D4594[1203872] + 76) = a1;
		*(_DWORD*)&byte_5D4594[1203872] = a1;
		a1[16] = *(_DWORD*)(a2 + 456);
		a1[17] = 0;
		v3 = *(_DWORD*)(a2 + 456);
		if (v3)
			*(_DWORD*)(v3 + 68) = a1;
		*(_DWORD*)(a2 + 456) = a1;
	}
	return result;
}

//----- (00496020) --------------------------------------------------------
int __cdecl sub_496020(int a1, int a2) {
	_DWORD* v2; // eax

	v2 = *(_DWORD**)(a1 + 456);
	if (!v2)
		return 0;
	while (*v2 != a2) {
		v2 = (_DWORD*)v2[16];
		if (!v2)
			return 0;
	}
	return 1;
}

//----- (00496050) --------------------------------------------------------
void __cdecl sub_496050(int a1) {
	_DWORD* v1; // eax
	int v2;     // ecx

	if (a1 && sub_496020(a1, 2) != 1) {
		v1 = nox_alloc_class_new_obj_zero(*(_DWORD**)&byte_5D4594[1203868]);
		if (v1) {
			*v1 = 2;
			v2 = *((unsigned __int8*)v1 + 56);
			v1[1] = 0;
			v1[2 * v2 + 2] = *(_DWORD*)(a1 + 12);
			v1[2 * v2 + 3] = *(_DWORD*)(a1 + 16);
			++*((_BYTE*)v1 + 56);
			sub_495FC0(v1, a1);
		}
	}
}

//----- (004960B0) --------------------------------------------------------
int sub_4960B0() {
	int result; // eax

	result = (int)nox_malloc(4 * (4 * nox_win_width / 23 * (nox_win_height / 23) / 2));
	dword_5d4594_1217456 = result;
	if (result) {
		sub_4CA860();
		result = 1;
	}
	return result;
}

//----- (00496120) --------------------------------------------------------
int sub_496120() {
	if (dword_5d4594_1217456) {
		free(*(LPVOID*)&dword_5d4594_1217456);
		dword_5d4594_1217456 = 0;
	}
	return 1;
}

//----- (00496150) --------------------------------------------------------
int __cdecl sub_496150(int* a1) {
	int v1;               // esi
	int v2;               // ecx
	int v3;               // ebx
	int v4;               // ebp
	int v5;               // ebx
	int v6;               // esi
	int v7;               // eax
	int v8;               // ebp
	unsigned __int8* v9;  // esi
	unsigned __int8 v10;  // dl
	int v11;              // ecx
	unsigned __int8 v12;  // al
	unsigned __int8 v13;  // al
	int v14;              // edx
	unsigned __int8 v15;  // al
	unsigned __int8* v16; // esi
	bool v17;             // zf
	int v18;              // ebp
	int v19;              // esi
	int v20;              // ebx
	int v21;              // ebp
	int v22;              // eax
	int v23;              // ecx
	char v24;             // al
	int v25;              // ebp
	int v26;              // edx
	int v27;              // ecx
	int v28;              // ebp
	int v29;              // eax
	int v30;              // ebp
	int v31;              // edx
	int v32;              // ecx
	int v33;              // ecx
	int v34;              // ebp
	double v35;           // st7
	int v36;              // ebx
	int v37;              // ebx
	int v38;              // ecx
	int v39;              // ebp
	int v40;              // ebx
	int v41;              // ebx
	int v42;              // ebx
	double v43;           // st7
	double v44;           // st7
	int v45;              // ebx
	int v46;              // ebx
	int v47;              // ebx
	int v48;              // edx
	int v49;              // ecx
	int v50;              // edx
	int v51;              // ebx
	int v52;              // ebx
	int v53;              // esi
	int v54;              // eax
	unsigned __int8 v55;  // cl
	unsigned __int8 v56;  // dl
	int v57;              // ecx
	int v58;              // edi
	int v59;              // ebp
	int v60;              // ecx
	int v61;              // ecx
	int v62;              // ecx
	int v63;              // ecx
	int v64;              // ebp
	int v65;              // ecx
	int v66;              // ecx
	int v68;              // [esp+4h] [ebp-8Ch]
	int v69;              // [esp+18h] [ebp-78h]
	int v70;              // [esp+1Ch] [ebp-74h]
	int v71;              // [esp+20h] [ebp-70h]
	int v72;              // [esp+20h] [ebp-70h]
	unsigned int v73;     // [esp+28h] [ebp-68h]
	int v74;              // [esp+2Ch] [ebp-64h]
	int v75;              // [esp+30h] [ebp-60h]
	int v76;              // [esp+34h] [ebp-5Ch]
	float2 a4;            // [esp+38h] [ebp-58h]
	float2 v78;           // [esp+40h] [ebp-50h]
	int v79;              // [esp+48h] [ebp-48h]
	int v80;              // [esp+4Ch] [ebp-44h]
	int2 a1a;             // [esp+50h] [ebp-40h]
	int2 a2;              // [esp+58h] [ebp-38h]
	float4 v83;           // [esp+60h] [ebp-30h]
	float4 a3;            // [esp+70h] [ebp-20h]
	float4 v86;           // [esp+80h] [ebp-10h]

	sub_4CAE60();
	dword_5d4594_1217464 = 0;
	dword_5d4594_1217460 = 0;
	v1 = a1[4];
	v2 = a1[5];
	v3 = a1[8];
	v79 = v1 / 23;
	v80 = v2 / 23;
	v74 = (v3 + v1) / 23 - v1 / 23;
	v4 = (a1[9] + v2) / 23 - v2 / 23;
	*(_DWORD*)&byte_5D4594[1217444] = v1 + v3 / 2;
	dword_5d4594_1217448 = a1[5] + a1[12] + a1[9] / 2;
	sub_498030(a1);
	sub_497260(a1);
	if (v4 < 0)
		goto LABEL_32;
	v5 = v80;
	v6 = v74;
	v71 = v80;
	v70 = 23 * v80;
	v75 = v4 + 1;
	do {
		v7 = ((_BYTE)v5 + (_BYTE)v79) & 1;
		if (v7 > v6)
			goto LABEL_31;
		v8 = v7 + v79;
		v69 = 23 * (v7 + v79);
		v73 = (unsigned int)(v6 - v7 + 2) >> 1;
		do {
			v9 = (unsigned __int8*)nox_server_getWallAtPoint_410580(v8, v5);
			if (v9) {
				v10 = (unsigned char)sub_57B500(v8, v5, 64);
				if (v10 != 255) {
					v11 = v9[1];
					v12 = v9[4];
					if (byte_5D4594[12332 * v11 + 2692780] & 1) {
						if (v12 & 0x40) {
							if ((*(int*)&byte_5D4594[1217444] - v69 - 11) * (*(int*)&byte_5D4594[1217444] - v69 - 11) +
									(*(int*)&dword_5d4594_1217448 - v70 - 11) *
										(*(int*)&dword_5d4594_1217448 - v70 - 11) <
								3600) {
								v5 = v71;
								v9[4] = v12 | 1;
								goto LABEL_29;
							}
							v5 = v71;
						}
						if (v10) {
							if (v10 == 1) {
								sub_497C40(v8, v5, 6);
							} else {
								v16 = &byte_587000[v10 + 161764];
								if (byte_587000[v10 + 161764] & 2)
									sub_497C40(v8, v5, 2);
								if (*v16 & 1)
									sub_497C40(v8, v5, 1);
								if (*v16 & 8)
									sub_497C40(v8, v5, 8);
								if (*v16 & 4)
									sub_497C40(v8, v5, 4);
							}
						} else {
							sub_497C40(v8, v5, 9);
						}
					} else {
						v13 = v12 | 1;
						v14 = v9[6];
						v9[4] = v13;
						if (23 * v14 <= *(int*)&dword_5d4594_1217448)
							v15 = v13 & 0xFD;
						else
							v15 = v13 | 2;
						v9[4] = v15;
						if (byte_5D4594[12332 * v11 + 2692780] & 4)
							sub_4754C0((int)v9);
					}
				}
			}
		LABEL_29:
			v8 += 2;
			v17 = v73 == 1;
			v69 += 46;
			--v73;
		} while (!v17);
		v6 = v74;
	LABEL_31:
		++v5;
		v17 = v75 == 1;
		v70 += 23;
		v71 = v5;
		--v75;
	} while (!v17);
LABEL_32:
	sub_498110();
	v72 = 0;
	a3.field_0 = (double)*(int*)&byte_5D4594[1217444];
	a3.field_4 = (double)*(int*)&dword_5d4594_1217448;
	if (*(int*)&dword_5d4594_1217460 <= 0) {
		v51 = dword_5d4594_1217464;
	} else {
		do {
			v18 = 0;
			v19 = *(_DWORD*)(dword_5d4594_1217456 + 4 * v72);
			switch (*(unsigned __int8*)(v19 + 56)) {
			case 0u:
				v20 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(int)(*(_DWORD*)&byte_5D4594[1217444] + sub_414BD0(6434 - v20));
				a3.field_C = (double)(int)(dword_5d4594_1217448 + sub_414BD0(v20));
				sub_4CA960((_DWORD*)(v19 + 24), *(_BYTE*)(v19 + 36), &a3, &a4);
				v21 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(int)(*(_DWORD*)&byte_5D4594[1217444] + sub_414BD0(6434 - v21));
				a3.field_C = (double)(int)(dword_5d4594_1217448 + sub_414BD0(v21));
				sub_4CA960((_DWORD*)(v19 + 24), *(_BYTE*)(v19 + 36), &a3, &v78);
				v22 = nox_server_getWallAtPoint_410580(*(_DWORD*)(v19 + 24), *(_DWORD*)(v19 + 28));
				v23 = v22;
				LOBYTE(v22) = *(_BYTE*)(v22 + 4);
				*(_DWORD*)(v23 + 12) = 1;
				v24 = v22 | 1;
				*(_BYTE*)(v23 + 4) = v24;
				if (v78.field_0 < (double)a4.field_0)
					*(_BYTE*)(v23 + 4) = v24 | 2;
				*(_BYTE*)(v23 + 3) |= *(_BYTE*)(v19 + 36);
				v18 = *(_DWORD*)(v19 + 24) + (*(_DWORD*)(v19 + 28) << 8);
				break;
			case 1u:
				a4.field_0 = (double)(*(int*)&byte_5D4594[1217444] +
									  sub_414C50(25736 * *(int*)(v19 + 40) / 75000 - 19302) * (a1[9] / 2) / 4096);
				a4.field_4 = (double)a1[5];
				v18 = 0;
				v78.field_0 = (double)(*(int*)&byte_5D4594[1217444] +
									   sub_414C50(25736 * *(int*)(v19 + 44) / 75000 - 19302) * (a1[9] / 2) / 4096);
				v78.field_4 = (double)a1[5];
				break;
			case 2u:
				v25 = a1[9];
				v26 = *(_DWORD*)&byte_5D4594[1217444] -
					  sub_414C50(25736 * *(int*)(v19 + 40) / 75000 - 6434) * (v25 / 2) / 4096;
				v27 = a1[5] + v25 - 1;
				v28 = a1[9];
				a4.field_0 = (double)v26;
				a4.field_4 = (double)v27;
				v29 = sub_414C50(25736 * *(int*)(v19 + 44) / 75000 - 6434);
				v76 = a1[5] + v28 - 1;
				v78.field_0 = (double)(*(int*)&byte_5D4594[1217444] - v29 * (v28 / 2) / 4096);
				v78.field_4 = (double)v76;
				v18 = 0;
				break;
			case 3u:
				v32 = 25736 * *(_DWORD*)(v19 + 40);
				a4.field_0 = (double)a1[4];
				a4.field_4 =
					(double)(*(int*)&dword_5d4594_1217448 - sub_414C50(v32 / 75000 - 12868) * (a1[8] / 2) / 4096);
				v33 = 25736 * *(_DWORD*)(v19 + 44);
				v78.field_0 = (double)a1[4];
				v18 = 0;
				v78.field_4 =
					(double)(*(int*)&dword_5d4594_1217448 - sub_414C50(v33 / 75000 - 12868) * (a1[8] / 2) / 4096);
				break;
			case 4u:
				v30 = a1[8];
				v68 = 25736 * *(int*)(v19 + 40) / 75000;
				a4.field_0 = (double)(int)(a1[8] + a1[4] - 1);
				a4.field_4 = (double)(int)(dword_5d4594_1217448 + sub_414C50(v68) * (v30 / 2) / 4096);
				v31 = 25736 * *(int*)(v19 + 44) / 75000;
				v78.field_0 = (double)(int)(a1[4] + v30 - 1);
				v78.field_4 = (double)(int)(dword_5d4594_1217448 + sub_414C50(v31) * (a1[8] / 2) / 4096);
				v18 = 0;
				break;
			case 6u:
				v34 = *(_DWORD*)(v19 + 20);
				v35 = (double)*(int*)(v34 + 12);
				*(_DWORD*)(v34 + 132) = 1;
				v86.field_0 = v35;
				v86.field_4 = (double)*(int*)(v34 + 16);
				v86.field_8 =
					(double)(*(int*)(v34 + 12) + *(int*)&byte_587000[8 * *(unsigned __int8*)(v34 + 299) + 196184]);
				v86.field_C =
					(double)(*(int*)(v34 + 16) + *(int*)&byte_587000[8 * *(unsigned __int8*)(v34 + 299) + 196188]);
				v36 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(*(int*)&byte_5D4594[1217444] + sub_414BD0(6434 - v36));
				a3.field_C = (double)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v36));
				if (!sub_497180(&a3.field_0, &v86.field_0, &a4.field_0))
					a4 = *(float2*)&v86.field_0;
				v37 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(*(int*)&byte_5D4594[1217444] + sub_414BD0(6434 - v37));
				a3.field_C = (double)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v37));
				if (!sub_497180(&a3.field_0, &v86.field_0, &v78.field_0))
					v78 = *(float2*)&v86.field_8;
				v18 = *(_DWORD*)(v34 + 128);
				break;
			case 7u:
				*(_DWORD*)(*(_DWORD*)(v19 + 20) + 132) = 1;
				v38 = *(_DWORD*)(v19 + 20);
				v39 = *(_DWORD*)&byte_5D4594[1217444] - *(_DWORD*)(v38 + 12);
				v40 = *(_DWORD*)(v38 + 16) - dword_5d4594_1217448;
				nox_double2int(sqrt((double)*(int*)(v19 + 32)));
				v83.field_0 = (double)(int)(v40 + *(int*)(*(_DWORD*)(v19 + 20) + 12));
				v83.field_4 = (double)(int)(v39 + *(int*)(*(_DWORD*)(v19 + 20) + 16));
				v83.field_8 = (double)(int)(*(int*)(*(_DWORD*)(v19 + 20) + 12) - v40);
				v83.field_C = (double)(int)(*(int*)(*(_DWORD*)(v19 + 20) + 16) - v39);
				v41 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(int)(*(int*)&byte_5D4594[1217444] + sub_414BD0(6434 - v41));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v41));
				if (!sub_497180(&a3.field_0, &v83.field_0, &a4.field_0))
					a4 = *(float2*)&v83;
				v42 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(int)(*(int*)&byte_5D4594[1217444] + sub_414BD0(6434 - v42));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v42));
				if (sub_497180(&a3.field_0, &v83.field_0, &v78.field_0))
					goto LABEL_63;
				goto LABEL_62;
			case 8u:
			case 9u:
			case 0xAu:
			case 0xBu:
			case 0xDu:
			case 0xEu:
				*(_DWORD*)(*(_DWORD*)(v19 + 20) + 132) = 1;
				switch (*(unsigned __int8*)(v19 + 56)) {
				case 8u:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 64);
					v83.field_4 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 68);
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 72);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 76);
					goto LABEL_58;
				case 9u:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 64);
					v44 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 68);
					goto LABEL_57;
				case 0xAu:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 88);
					v83.field_4 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 92);
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 72);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 76);
					goto LABEL_58;
				case 0xBu:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 88);
					v44 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 92);
					goto LABEL_57;
				case 0xDu:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 64);
					v83.field_4 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 68);
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 88);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 92);
					goto LABEL_58;
				case 0xEu:
					v83.field_0 = (double)*(int*)(*(_DWORD*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 72);
					v44 = (double)*(int*)(*(_DWORD*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 76);
				LABEL_57:
					v83.field_4 = v44;
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(_DWORD*)(v19 + 20) + 80);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(_DWORD*)(v19 + 20) + 84);
				LABEL_58:
					v83.field_C = v43;
					break;
				default:
					break;
				}
				v45 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(int)(*(int*)&byte_5D4594[1217444] + sub_414BD0(6434 - v45));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v45));
				if (!sub_497180(&a3.field_0, &v83.field_0, &a4.field_0))
					a4 = *(float2*)&v83.field_0;
				v46 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(int)(*(int*)&byte_5D4594[1217444] + sub_414BD0(6434 - v46));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v46));
				if (!sub_497180(&a3.field_0, &v83.field_0, &v78.field_0))
				LABEL_62:
					v78 = *(float2*)&v83.field_8;
			LABEL_63:
				v18 = *(_DWORD*)(*(_DWORD*)(v19 + 20) + 128);
				break;
			default:
				break;
			}
			a1a.field_0 = *a1 - a1[4] + nox_float2int(a4.field_0);
			a1a.field_4 = a1[1] - a1[5] + nox_float2int(a4.field_4);
			a2.field_0 = *a1 - a1[4] + nox_float2int(v78.field_0);
			a2.field_4 = a1[1] - a1[5] + nox_float2int(v78.field_4);
			// dprintf("%d\t%d\t%d %d %d %d", v72, *(unsigned __int8 *)(v19 + 56), a1a.field_0, a1a.field_4,
			// a2.field_0, a2.field_4);
			if (sub_57BA30(&a1a, &a2, (int4*)a1)) {
				v47 = dword_5d4594_1217464;
				v48 = a1a.field_4;
				*(_DWORD*)&byte_5D4594[8 * dword_5d4594_1217464 + 1203876] = a1a.field_0;
				v49 = a2.field_0;
				*(_DWORD*)&byte_5D4594[8 * v47 + 1203880] = v48;
				v50 = a2.field_4;
				*(_DWORD*)&byte_5D4594[4 * v47 + 1213348] = v18;
				byte_5D4594[v47++ + 1212324] = *(_BYTE*)(v19 + 56);
				dword_5d4594_1217464 = v47;
				*(_DWORD*)&byte_5D4594[8 * v47 + 1203876] = v49;
				*(_DWORD*)&byte_5D4594[8 * v47 + 1203880] = v50;
				*(_DWORD*)&byte_5D4594[4 * v47 + 1213348] = v18;
				byte_5D4594[v47 + 1212324] = *(_BYTE*)(v19 + 56);
				v51 = v47 + 1;
				dword_5d4594_1217464 = v51;
			} else {
				v51 = dword_5d4594_1217464;
			}
			++v72;
		} while (v72 < *(int*)&dword_5d4594_1217460);
	}
	v52 = v51 - 1;
	v53 = 0;
	dword_5d4594_1217464 = v52;
	v54 = v52 - 1;
	while (v53 < v52) {
		v55 = byte_5D4594[v54 + 1212324];
		if (v55) {
			v56 = byte_5D4594[v53 + 1212324];
			if (!v56)
				goto LABEL_89;
			if (v56 != v55)
				goto LABEL_99;
			if (*(_DWORD*)&byte_5D4594[4 * v53 + 1213348] != *(_DWORD*)&byte_5D4594[4 * v54 + 1213348]) {
				v57 = *(_DWORD*)&byte_5D4594[8 * v54 + 1203876];
				v58 = *(_DWORD*)&byte_5D4594[8 * v53 + 1203876] - v57;
				if (v58 < 0) {
					v59 = v57 - *(_DWORD*)&byte_5D4594[8 * v53 + 1203876];
				LABEL_83:
					v61 = *(_DWORD*)&byte_5D4594[8 * v54 + 1203880];
					if (*(int*)&byte_5D4594[8 * v53 + 1203880] - v61 >= 0)
						v62 = *(_DWORD*)&byte_5D4594[8 * v53 + 1203880] - v61;
					else
						v62 = v61 - *(_DWORD*)&byte_5D4594[8 * v53 + 1203880];
					if (v59 <= 4 && v62 <= 4)
						goto LABEL_100;
				LABEL_99:
					byte_5D4594[v54 + 1212324] = 12;
					goto LABEL_100;
				}
			LABEL_82:
				v59 = v58;
				goto LABEL_83;
			}
		} else {
			if (byte_5D4594[v53 + 1212324]) {
			LABEL_89:
				if (v55 == 6 || byte_5D4594[v53 + 1212324] == 6) {
					v63 = *(_DWORD*)&byte_5D4594[8 * v54 + 1203876];
					v64 = *(int*)&byte_5D4594[8 * v53 + 1203876] - v63 >= 0
							  ? *(_DWORD*)&byte_5D4594[8 * v53 + 1203876] - v63
							  : v63 - *(_DWORD*)&byte_5D4594[8 * v53 + 1203876];
					v65 = *(_DWORD*)&byte_5D4594[8 * v54 + 1203880];
					v66 = *(int*)&byte_5D4594[8 * v53 + 1203880] - v65 >= 0
							  ? *(_DWORD*)&byte_5D4594[8 * v53 + 1203880] - v65
							  : v65 - *(_DWORD*)&byte_5D4594[8 * v53 + 1203880];
					if (v64 <= 4 && v66 <= 4)
						goto LABEL_100;
				}
				goto LABEL_99;
			}
			if (*(_DWORD*)&byte_5D4594[4 * v54 + 1213348] != *(_DWORD*)&byte_5D4594[4 * v53 + 1213348]) {
				v60 = *(_DWORD*)&byte_5D4594[8 * v54 + 1203876];
				v58 = *(_DWORD*)&byte_5D4594[8 * v53 + 1203876] - v60;
				if (v58 < 0) {
					v59 = v60 - *(_DWORD*)&byte_5D4594[8 * v53 + 1203876];
					goto LABEL_83;
				}
				goto LABEL_82;
			}
		}
	LABEL_100:
		v54 = v53++;
	}
	sub_4989A0();
	return sub_4C52E0((int*)&byte_5D4594[1203876], *(int*)&dword_5d4594_1217464);
}

//----- (00497180) --------------------------------------------------------
int __cdecl sub_497180(float* a1, float* a2, float* a3) {
	double v3;  // st7
	double v4;  // st6
	float v5;   // ecx
	double v6;  // st5
	float v7;   // eax
	float v8;   // eax
	int result; // eax
	float v10;  // [esp+4h] [ebp-1Ch]
	float v11;  // [esp+8h] [ebp-18h]
	float v12;  // [esp+14h] [ebp-Ch]

	if (*a1 >= (double)a1[2]) {
		v3 = a1[2];
		v4 = *a1;
	} else {
		v3 = *a1;
		v4 = a1[2];
	}
	if (a1[1] >= (double)a1[3]) {
		v5 = a1[1];
		v12 = a1[3];
	} else {
		v5 = a1[3];
		v12 = a1[1];
	}
	if (*a2 >= (double)a2[2]) {
		v6 = a2[2];
		v7 = *a2;
	} else {
		v6 = *a2;
		v7 = a2[2];
	}
	v11 = v7;
	if (a2[1] >= (double)a2[3]) {
		v10 = a2[3];
		v8 = a2[1];
	} else {
		v10 = a2[1];
		v8 = a2[3];
	}
	if (v6 > v4 || v11 < v3 || v10 > (double)v5 || v8 < (double)v12)
		result = 0;
	else
		result = sub_4278B0(a1, a2, a3);
	return result;
}

//----- (00497260) --------------------------------------------------------
int __cdecl sub_497260(int* a1) {
	int result; // eax
	int v2;     // esi
	int* v3;    // edi
	double v4;  // st7
	double v5;  // st6
	int v6;     // eax
	double v7;  // st7
	double v8;  // st6
	double v9;  // st7
	double v10; // st6
	float v11;  // [esp+Ch] [ebp-Ch]
	float v12;  // [esp+Ch] [ebp-Ch]
	float v13;  // [esp+Ch] [ebp-Ch]
	float v14;  // [esp+10h] [ebp-8h]
	float v15;  // [esp+10h] [ebp-8h]
	float v16;  // [esp+10h] [ebp-8h]
	float v17;  // [esp+14h] [ebp-4h]
	float v18;  // [esp+14h] [ebp-4h]
	float v19;  // [esp+14h] [ebp-4h]
	float v20;  // [esp+1Ch] [ebp+4h]
	float v21;  // [esp+1Ch] [ebp+4h]
	float v22;  // [esp+1Ch] [ebp+4h]

	result = sub_45A030();
	v2 = result;
	if (result) {
		v3 = a1;
		do {
			*(_DWORD*)(v2 + 132) = 0;
			if (!sub_4356C0(v2, 0)) {
				if (*(char*)(v2 + 112) >= 0) {
					v6 = *(_DWORD*)(v2 + 44);
					if (v6 == 2) {
						v7 = (double)*(int*)(v2 + 12);
						v8 = (double)*(int*)(v2 + 16);
						if (v7 - *(float*)(v2 + 48) < (double)(v3[4] + v3[8])) {
							v21 = v7;
							v15 = v21 + *(float*)(v2 + 48);
							if ((double)v3[4] < v15) {
								v12 = v8 - *(float*)(v2 + 48);
								if ((double)(v3[5] + v3[9]) > v12) {
									v18 = v8 + *(float*)(v2 + 48);
									if ((double)v3[5] < v18)
										sub_497650(*(float*)&v2);
								}
							}
						}
					} else if (v6 == 3) {
						v9 = (double)*(int*)(v2 + 12);
						v10 = (double)*(int*)(v2 + 16);
						if (v9 + *(float*)(v2 + 72) < (double)(v3[4] + v3[8])) {
							v22 = v9;
							v16 = v22 + *(float*)(v2 + 80);
							if ((double)v3[4] < v16) {
								v13 = v10 + *(float*)(v2 + 68);
								if ((double)(v3[5] + v3[9]) > v13) {
									v19 = v10 + *(float*)(v2 + 92);
									if ((double)v3[5] < v19)
										sub_4977C0(v2);
								}
							}
						}
					}
				} else {
					v4 = (double)*(int*)(v2 + 12);
					v5 = (double)*(int*)(v2 + 16);
					if (v4 - 32.0 < (double)(v3[4] + v3[8])) {
						v20 = v4;
						v14 = v20 + 32.0;
						if ((double)v3[4] < v14) {
							v11 = v5 - 32.0;
							if ((double)(v3[5] + v3[9]) > v11) {
								v17 = v5 + 32.0;
								if ((double)v3[5] < v17)
									sub_4974B0(v2);
							}
						}
					}
				}
			}
			result = sub_45A040(v2);
			v2 = result;
		} while (result);
	}
	return result;
}

//----- (004974B0) --------------------------------------------------------
void __cdecl sub_4974B0(int a1) {
	int v1;    // edi
	int v2;    // esi
	int v3;    // ecx
	double v4; // st7
	int v5;    // eax
	int v6;    // eax
	int v7;    // eax
	int v8;    // eax
	int v9;    // eax
	int v10;   // eax
	int v11;   // eax
	int v12;   // ecx
	int v13;   // eax
	float v14; // [esp+0h] [ebp-14h]
	int v15;   // [esp+18h] [ebp+4h]

	v1 = a1;
	if (!(*(_BYTE*)(a1 + 116) & 4)) {
		v2 = sub_4CADD0();
		*(_BYTE*)(v2 + 48) = 1;
		*(_BYTE*)(v2 + 56) = 6;
		*(_DWORD*)(v2 + 20) = a1;
		v3 = 8 * *(unsigned __int8*)(a1 + 299);
		v4 =
			(double)(int)(*(_DWORD*)&byte_5D4594[1217444] - *(int*)&byte_587000[v3 + 196184] / 2 - *(_DWORD*)(a1 + 12));
		v15 = dword_5d4594_1217448 - *(int*)&byte_587000[v3 + 196188] / 2 - *(_DWORD*)(a1 + 16);
		v14 = (double)v15 * (double)v15 + v4 * v4;
		*(_DWORD*)(v2 + 32) = nox_float2int(v14);
		v5 = sub_4CA8B0(*(_DWORD*)(v1 + 16) - dword_5d4594_1217448,
						*(_DWORD*)(v1 + 12) - *(_DWORD*)&byte_5D4594[1217444]);
		*(_DWORD*)(v2 + 40) = v5;
		if (v5 < 0) {
			do {
				v6 = *(_DWORD*)(v2 + 40);
				*(_DWORD*)(v2 + 40) = v6 + 75000;
			} while (v6 + 75000 < 0);
		}
		if (*(int*)(v2 + 40) >= 75000) {
			do {
				v7 = *(_DWORD*)(v2 + 40) - 75000;
				*(_DWORD*)(v2 + 40) = v7;
			} while (v7 >= 75000);
		}
		v8 = sub_4CA8B0(*(_DWORD*)(v1 + 16) + *(int*)&byte_587000[8 * *(unsigned __int8*)(v1 + 299) + 196188] -
							dword_5d4594_1217448,
						*(_DWORD*)(v1 + 12) + *(int*)&byte_587000[8 * *(unsigned __int8*)(v1 + 299) + 196184] -
							*(_DWORD*)&byte_5D4594[1217444]);
		*(_DWORD*)(v2 + 44) = v8;
		if (v8 < 0) {
			do {
				v9 = *(_DWORD*)(v2 + 44);
				*(_DWORD*)(v2 + 44) = v9 + 75000;
			} while (v9 + 75000 < 0);
		}
		if (*(int*)(v2 + 44) >= 75000) {
			do {
				v10 = *(_DWORD*)(v2 + 44) - 75000;
				*(_DWORD*)(v2 + 44) = v10;
			} while (v10 >= 75000);
		}
		v11 = *(_DWORD*)(v2 + 44);
		v12 = *(_DWORD*)(v2 + 40);
		if (v11 < v12) {
			*(_DWORD*)(v2 + 40) = v11;
			*(_DWORD*)(v2 + 44) = v12;
		}
		if ((double)(int)(*(_DWORD*)(v2 + 44) - *(_DWORD*)(v2 + 40)) >= 37500.0) {
			v13 = sub_4CAED0(v2);
			*(_DWORD*)(v13 + 40) = 0;
			*(_DWORD*)(v13 + 44) = *(_DWORD*)(v2 + 40);
			*(_DWORD*)(v2 + 40) = *(_DWORD*)(v2 + 44);
			*(_DWORD*)(v2 + 44) = 74999;
			sub_4CAE90(v13);
		}
		sub_4CAE90(v2);
	}
}

//----- (00497650) --------------------------------------------------------
int __cdecl sub_497650(float a1) {
	int v1;     // eax
	float v2;   // edi
	_DWORD* v3; // esi
	int v4;     // ecx
	double v5;  // st7
	int v6;     // eax
	int v7;     // ebx
	int v8;     // eax
	int v9;     // ebp
	int v10;    // eax
	int v11;    // eax
	int v12;    // ecx
	int v13;    // edi
	int v14;    // ebp
	int v15;    // eax
	int v16;    // eax
	int v17;    // eax
	int v18;    // ecx
	int v19;    // eax
	float v21;  // [esp+0h] [ebp-1Ch]
	int v22;    // [esp+0h] [ebp-1Ch]
	float v23;  // [esp+14h] [ebp-8h]
	float v24;  // [esp+20h] [ebp+4h]

	v1 = sub_4CADD0();
	v2 = a1;
	v3 = (_DWORD*)v1;
	*(_BYTE*)(v1 + 48) = 1;
	*(_BYTE*)(v1 + 56) = 7;
	*(float*)(v1 + 20) = a1;
	v4 = *(_DWORD*)(LODWORD(a1) + 16);
	v24 = (double)(int)(*(_DWORD*)(LODWORD(a1) + 12) - *(_DWORD*)&byte_5D4594[1217444]);
	v5 = (double)(int)(v4 - dword_5d4594_1217448);
	v23 = v5;
	v21 = v5 * v23 + v24 * v24;
	v6 = nox_float2int(v21);
	v3[8] = v6;
	v7 = (__int64)sqrt((double)v6);
	v22 = nox_float2int(v24);
	v8 = nox_float2int(v23);
	v9 = sub_4CA8B0(v8, v22);
	v10 = nox_float2int(*(float*)(LODWORD(v2) + 48));
	v11 = sub_4CA8B0(v10, v7);
	v3[10] = v11 + v9;
	if (v11 + v9 < 0) {
		do {
			v12 = v3[10];
			v3[10] = v12 + 75000;
		} while (v12 + 75000 < 0);
	}
	if (v3[10] >= 75000) {
		do {
			v13 = v3[10] - 75000;
			v3[10] = v13;
		} while (v13 >= 75000);
	}
	v14 = v9 - v11;
	v3[11] = v14;
	if (v14 < 0) {
		do {
			v15 = v3[11];
			v3[11] = v15 + 75000;
		} while (v15 + 75000 < 0);
	}
	if (v3[11] >= 75000) {
		do {
			v16 = v3[11] - 75000;
			v3[11] = v16;
		} while (v16 >= 75000);
	}
	v17 = v3[11];
	v18 = v3[10];
	if (v17 < v18) {
		v3[10] = v17;
		v3[11] = v18;
	}
	if ((double)(v3[11] - v3[10]) >= 37500.0) {
		v19 = sub_4CAED0((int)v3);
		*(_DWORD*)(v19 + 40) = 0;
		*(_DWORD*)(v19 + 44) = v3[10];
		v3[10] = v3[11];
		v3[11] = 74999;
		sub_4CAE90(v19);
	}
	return sub_4CAE90((int)v3);
}

//----- (004977C0) --------------------------------------------------------
int __cdecl sub_4977C0(int a1) {
	int v1;       // esi
	double v2;    // st7
	double v3;    // st6
	int v4;       // eax
	int v5;       // edi
	int v6;       // eax
	int v7;       // ebp
	int v8;       // eax
	int v9;       // ebx
	int v10;      // eax
	int result;   // eax
	double v12;   // st7
	int v13;      // eax
	double v14;   // st7
	int v15;      // eax
	double v16;   // st7
	int v17;      // eax
	double v18;   // st7
	int v19;      // eax
	double v20;   // st7
	int v21;      // eax
	double v22;   // st7
	int v23;      // eax
	float v24;    // [esp+0h] [ebp-40h]
	float v25;    // [esp+0h] [ebp-40h]
	float v26;    // [esp+0h] [ebp-40h]
	float v27;    // [esp+0h] [ebp-40h]
	float v28;    // [esp+0h] [ebp-40h]
	float v29;    // [esp+0h] [ebp-40h]
	int v30;      // [esp+4h] [ebp-3Ch]
	int v31;      // [esp+4h] [ebp-3Ch]
	int v32;      // [esp+4h] [ebp-3Ch]
	int v33;      // [esp+4h] [ebp-3Ch]
	float v34;    // [esp+1Ch] [ebp-24h]
	float v35;    // [esp+1Ch] [ebp-24h]
	float v36;    // [esp+1Ch] [ebp-24h]
	float v37;    // [esp+1Ch] [ebp-24h]
	float v38[8]; // [esp+20h] [ebp-20h]
	float v39;    // [esp+44h] [ebp+4h]
	int v40;      // [esp+44h] [ebp+4h]

	v1 = a1;
	v2 = (double)*(int*)(a1 + 12);
	v38[0] = v2 + *(float*)(a1 + 64);
	v3 = (double)*(int*)(a1 + 16);
	v39 = v3;
	v38[1] = v3 + *(float*)(v1 + 68);
	v38[2] = v2 + *(float*)(v1 + 72);
	v38[3] = v39 + *(float*)(v1 + 76);
	v38[4] = v2 + *(float*)(v1 + 80);
	v38[5] = v39 + *(float*)(v1 + 84);
	v38[6] = v2 + *(float*)(v1 + 88);
	v38[7] = v39 + *(float*)(v1 + 92);
	v30 = nox_float2int(v38[0]) - *(_DWORD*)&byte_5D4594[1217444];
	v4 = nox_float2int(v38[1]);
	v5 = sub_4CA8B0(v4 - dword_5d4594_1217448, v30);
	v31 = nox_float2int(v38[2]) - *(_DWORD*)&byte_5D4594[1217444];
	v6 = nox_float2int(v38[3]);
	v7 = sub_4CA8B0(v6 - dword_5d4594_1217448, v31);
	v32 = nox_float2int(v38[4]) - *(_DWORD*)&byte_5D4594[1217444];
	v8 = nox_float2int(v38[5]);
	v9 = sub_4CA8B0(v8 - dword_5d4594_1217448, v32);
	v33 = nox_float2int(v38[6]) - *(_DWORD*)&byte_5D4594[1217444];
	v10 = nox_float2int(v38[7]);
	v40 = sub_4CA8B0(v10 - dword_5d4594_1217448, v33);
	result = (unsigned __int8)sub_497B80(v38, (int*)&byte_5D4594[1217444]) - 1;
	switch (result) {
	case 0:
		v35 = (v38[5] + v38[1]) * 0.5;
		v14 = (v38[4] + v38[0]) * 0.5 - (double)*(int*)&byte_5D4594[1217444];
		v25 = (v35 - (double)*(int*)&dword_5d4594_1217448) * (v35 - (double)*(int*)&dword_5d4594_1217448) + v14 * v14;
		v15 = nox_float2int(v25);
		result = sub_497F60(v5, v9, 9, v15, v1);
		break;
	case 1:
		v37 = (v38[7] + v38[3]) * 0.5;
		v18 = (v38[6] + v38[2]) * 0.5 - (double)*(int*)&byte_5D4594[1217444];
		v27 = (v37 - (double)*(int*)&dword_5d4594_1217448) * (v37 - (double)*(int*)&dword_5d4594_1217448) + v18 * v18;
		v19 = nox_float2int(v27);
		result = sub_497F60(v40, v7, 10, v19, v1);
		break;
	case 3:
		v34 = (v38[3] + v38[1]) * 0.5;
		v12 = (v38[2] + v38[0]) * 0.5 - (double)*(int*)&byte_5D4594[1217444];
		v24 = (v34 - (double)*(int*)&dword_5d4594_1217448) * (v34 - (double)*(int*)&dword_5d4594_1217448) + v12 * v12;
		v13 = nox_float2int(v24);
		result = sub_497F60(v5, v7, 8, v13, v1);
		break;
	case 4:
	case 9:
		v22 = (double)(int)(*(_DWORD*)(v1 + 12) - *(_DWORD*)&byte_5D4594[1217444]);
		v29 = (double)(int)(*(_DWORD*)(v1 + 16) - dword_5d4594_1217448) *
				  (double)(int)(*(_DWORD*)(v1 + 16) - dword_5d4594_1217448) +
			  v22 * v22;
		v23 = nox_float2int(v29);
		result = sub_497F60(v7, v9, 14, v23, v1);
		break;
	case 5:
	case 8:
		v20 = (double)(int)(*(_DWORD*)(v1 + 12) - *(_DWORD*)&byte_5D4594[1217444]);
		v28 = (double)(int)(*(_DWORD*)(v1 + 16) - dword_5d4594_1217448) *
				  (double)(int)(*(_DWORD*)(v1 + 16) - dword_5d4594_1217448) +
			  v20 * v20;
		v21 = nox_float2int(v28);
		result = sub_497F60(v5, v40, 13, v21, v1);
		break;
	case 7:
		v36 = (v38[7] + v38[5]) * 0.5;
		v16 = (v38[6] + v38[4]) * 0.5 - (double)*(int*)&byte_5D4594[1217444];
		v26 = (v36 - (double)*(int*)&dword_5d4594_1217448) * (v36 - (double)*(int*)&dword_5d4594_1217448) + v16 * v16;
		v17 = nox_float2int(v26);
		result = sub_497F60(v40, v9, 11, v17, v1);
		break;
	default:
		return result;
	}
	return result;
}

//----- (00497B80) --------------------------------------------------------
char __cdecl sub_497B80(float* a1, int* a2) {
	int* v2;   // eax
	float* v3; // ecx
	char v4;   // dl
	double v5; // st7
	float v7;  // [esp+0h] [ebp-4h]
	float v8;  // [esp+8h] [ebp+4h]
	float v9;  // [esp+Ch] [ebp+8h]

	v2 = a2;
	v3 = a1;
	v4 = 0;
	v9 = (double)*a2;
	v7 = (double)v2[1];
	v5 = (a1[5] + a1[4] - v9 - v7) * 0.70709997;
	v8 = (a1[1] + *a1 - v9 - v7) * 0.70709997;
	if ((v3[1] - *v3 + v9 - v7) * 0.70709997 <= 0.0) {
		if ((v3[3] - v3[2] + v9 - v7) * 0.70709997 < 0.0)
			v4 = 2;
	} else {
		v4 = 1;
	}
	if (v5 < 0.0)
		return v4 | 8;
	if (v8 > 0.0)
		v4 |= 4u;
	return v4;
}

//----- (00497C40) --------------------------------------------------------
int __cdecl sub_497C40(int a1, int a2, char a3) {
	int v3;  // edi
	int v4;  // ebp
	int v5;  // ebx
	int v6;  // esi
	int v7;  // ecx
	int v8;  // eax
	int v9;  // edi
	int v10; // ecx
	int v11; // eax
	int v12; // eax
	int v13; // eax
	int v14; // eax
	int v15; // eax
	int v16; // eax
	int v17; // eax
	int v18; // ecx
	int v19; // eax
	int v21; // [esp+10h] [ebp-10h]
	int v22; // [esp+14h] [ebp-Ch]
	int v23; // [esp+18h] [ebp-8h]
	int v24; // [esp+1Ch] [ebp-4h]

	v21 = 23 * a1;
	v22 = 23 * a2;
	v3 = 23 * a1 + nox_float2int(11.5);
	v4 = 23 * a2 + nox_float2int(11.5);
	v5 = sub_4CADD0();
	*(_DWORD*)(v5 + 24) = a1;
	*(_BYTE*)(v5 + 36) = a3;
	*(_DWORD*)(v5 + 28) = a2;
	*(_BYTE*)(v5 + 48) = 1;
	*(_BYTE*)(v5 + 56) = 0;
	switch (a3) {
	case 1:
		v6 = v3 - *(_DWORD*)&byte_5D4594[1217444] + nox_float2int(5.75);
		v7 = v4 - dword_5d4594_1217448 - nox_float2int(5.75);
		v8 = v3;
		v9 = 23 * a2;
		v23 = v21 + 23;
		break;
	case 2:
		v6 = v3 - *(_DWORD*)&byte_5D4594[1217444] - nox_float2int(5.75);
		v7 = v4 - dword_5d4594_1217448 - nox_float2int(5.75);
		v8 = v3;
		v9 = 23 * a2;
		v23 = 23 * a1;
		break;
	case 4:
		v6 = v3 - *(_DWORD*)&byte_5D4594[1217444] + nox_float2int(5.75);
		v10 = nox_float2int(5.75);
		v8 = v3;
		v7 = v4 - dword_5d4594_1217448 + v10;
		v23 = v21 + 23;
		v9 = v22 + 23;
		break;
	case 6:
		v8 = 23 * a1;
		v7 = v4 - dword_5d4594_1217448;
		v4 = 23 * a2;
		v6 = v3 - *(_DWORD*)&byte_5D4594[1217444];
		v23 = v21 + 23;
		v9 = v22 + 23;
		break;
	case 8:
		v6 = v3 - *(_DWORD*)&byte_5D4594[1217444] - nox_float2int(5.75);
		v23 = 23 * a1;
		v7 = v4 - dword_5d4594_1217448 + nox_float2int(5.75);
		v8 = v3;
		v9 = v22 + 23;
		break;
	case 9:
		v6 = v3 - *(_DWORD*)&byte_5D4594[1217444];
		v7 = v4 - dword_5d4594_1217448;
		v4 = 23 * a2;
		v8 = v21 + 23;
		v23 = 23 * a1;
		v9 = v22 + 23;
		break;
	default:
		v6 = a1;
		v7 = a1;
		v4 = v24;
		v8 = v23;
		v9 = v24;
		break;
	}
	*(_DWORD*)(v5 + 32) = v6 * v6 + v7 * v7;
	v11 = sub_4CA8B0(v4 - dword_5d4594_1217448, v8 - *(_DWORD*)&byte_5D4594[1217444]);
	*(_DWORD*)(v5 + 40) = v11;
	if (v11 < 0) {
		do {
			v12 = *(_DWORD*)(v5 + 40);
			*(_DWORD*)(v5 + 40) = v12 + 75000;
		} while (v12 + 75000 < 0);
	}
	if (*(_DWORD*)(v5 + 40) >= 75000) {
		do {
			v13 = *(_DWORD*)(v5 + 40) - 75000;
			*(_DWORD*)(v5 + 40) = v13;
		} while (v13 >= 75000);
	}
	v14 = sub_4CA8B0(v9 - dword_5d4594_1217448, v23 - *(_DWORD*)&byte_5D4594[1217444]);
	*(_DWORD*)(v5 + 44) = v14;
	if (v14 < 0) {
		do {
			v15 = *(_DWORD*)(v5 + 44);
			*(_DWORD*)(v5 + 44) = v15 + 75000;
		} while (v15 + 75000 < 0);
	}
	if (*(_DWORD*)(v5 + 44) >= 75000) {
		do {
			v16 = *(_DWORD*)(v5 + 44) - 75000;
			*(_DWORD*)(v5 + 44) = v16;
		} while (v16 >= 75000);
	}
	v17 = *(_DWORD*)(v5 + 44);
	v18 = *(_DWORD*)(v5 + 40);
	if (v17 < v18) {
		*(_DWORD*)(v5 + 40) = v17;
		*(_DWORD*)(v5 + 44) = v18;
	}
	if (*(_DWORD*)(v5 + 44) - *(_DWORD*)(v5 + 40) >= 37500) {
		v19 = sub_4CAED0(v5);
		*(_DWORD*)(v19 + 40) = 0;
		*(_DWORD*)(v19 + 44) = *(_DWORD*)(v5 + 40);
		*(_DWORD*)(v5 + 40) = *(_DWORD*)(v5 + 44);
		*(_DWORD*)(v5 + 44) = 74999;
		sub_4CAE90(v19);
	}
	return sub_4CAE90(v5);
}
// 497E2E: variable 'v24' is possibly undefined
// 497E32: variable 'v23' is possibly undefined

//----- (00497F60) --------------------------------------------------------
int __cdecl sub_497F60(int a1, int a2, char a3, int a4, int a5) {
	int v5;  // esi
	int v6;  // ecx
	int v7;  // edx
	int v8;  // edx
	int v9;  // edx
	int v10; // eax

	v5 = sub_4CADD0();
	*(_BYTE*)(v5 + 56) = a3;
	*(_DWORD*)(v5 + 32) = a4;
	*(_BYTE*)(v5 + 48) = 1;
	*(_DWORD*)(v5 + 20) = a5;
	if (a2 >= a1) {
		*(_DWORD*)(v5 + 40) = a1;
		*(_DWORD*)(v5 + 44) = a2;
	} else {
		*(_DWORD*)(v5 + 40) = a2;
		*(_DWORD*)(v5 + 44) = a1;
	}
	if (*(int*)(v5 + 40) < 0) {
		do {
			v6 = *(_DWORD*)(v5 + 40);
			*(_DWORD*)(v5 + 40) = v6 + 75000;
		} while (v6 + 75000 < 0);
	}
	if (*(_DWORD*)(v5 + 40) >= 75000) {
		do {
			v7 = *(_DWORD*)(v5 + 40) - 75000;
			*(_DWORD*)(v5 + 40) = v7;
		} while (v7 >= 75000);
	}
	if (*(int*)(v5 + 44) < 0) {
		do {
			v8 = *(_DWORD*)(v5 + 44);
			*(_DWORD*)(v5 + 44) = v8 + 75000;
		} while (v8 + 75000 < 0);
	}
	if (*(_DWORD*)(v5 + 44) >= 75000) {
		do {
			v9 = *(_DWORD*)(v5 + 44) - 75000;
			*(_DWORD*)(v5 + 44) = v9;
		} while (v9 >= 75000);
	}
	if (*(int*)(v5 + 44) - *(int*)(v5 + 40) >= 37500) {
		v10 = sub_4CAED0(v5);
		*(_DWORD*)(v10 + 40) = 0;
		*(_DWORD*)(v10 + 44) = *(_DWORD*)(v5 + 40);
		*(_DWORD*)(v5 + 40) = *(_DWORD*)(v5 + 44);
		*(_DWORD*)(v5 + 44) = 74999;
		sub_4CAE90(v10);
	}
	return sub_4CAE90(v5);
}

//----- (00498030) --------------------------------------------------------
int __cdecl sub_498030(_DWORD* a1) {
	int v1; // esi
	int v2; // edi
	int v3; // ebx
	int v4; // ebp
	int v5; // edi
	int v6; // ebx
	int v7; // esi
	int v9; // [esp+14h] [ebp+4h]

	v1 = a1[4];
	v2 = a1[5];
	v3 = a1[8] + v1;
	v4 = a1[9] + v2;
	v9 = sub_4CA8B0(v2 - dword_5d4594_1217448, v1 - *(_DWORD*)&byte_5D4594[1217444]);
	v5 = sub_4CA8B0(v2 - dword_5d4594_1217448, v3 - *(_DWORD*)&byte_5D4594[1217444]);
	v6 = sub_4CA8B0(v4 - dword_5d4594_1217448, v3 - *(_DWORD*)&byte_5D4594[1217444]);
	v7 = sub_4CA8B0(v4 - dword_5d4594_1217448, v1 - *(_DWORD*)&byte_5D4594[1217444]);
	sub_497F60(v9, v5, 1, 0x7FFFFFFF, 0);
	sub_497F60(v5, v6, 4, 0x7FFFFFFF, 0);
	sub_497F60(v6, v7, 2, 0x7FFFFFFF, 0);
	return sub_497F60(v7, v9, 3, 0x7FFFFFFF, 0);
}

//----- (00498110) --------------------------------------------------------
int sub_498110() {
	int result; // eax

	for (result = sub_4CAEB0(); result; result = sub_4CAEB0()) {
		sub_498130(result);
	}
	return result;
}

//----- (00498130) --------------------------------------------------------
int __cdecl sub_498130(int a1) {
	int i;  // ebx
	int v2; // esi

	for (i = sub_498290(a1); i < *(int*)&dword_5d4594_1217460; ++i) {
		v2 = *(_DWORD*)(dword_5d4594_1217456 + 4 * i);
		if (*(int*)(v2 + 40) > *(int*)(a1 + 44))
			break;
		sub_498380(a1, *(_DWORD*)(dword_5d4594_1217456 + 4 * i));
		if (!*(_BYTE*)(a1 + 48) || *(int*)(a1 + 44) - *(int*)(a1 + 40) < 0)
			return sub_4CAE40(a1);
		if (!*(_BYTE*)(v2 + 48) || *(int*)(v2 + 44) - *(int*)(v2 + 40) < 0) {
			if (sub_4982E0(v2) <= i)
				--i;
			sub_4CAE40(v2);
		}
	}
	return sub_4981D0(a1);
}

//----- (004981D0) --------------------------------------------------------
int __cdecl sub_4981D0(int a1) {
	int v1; // ecx
	int v2; // esi
	int v3; // eax

	v1 = dword_5d4594_1217460 - 1;
	v2 = 0;
	while (v2 <= v1) {
		v3 = (v1 + v2) / 2;
		if (*(int*)(*(_DWORD*)(dword_5d4594_1217456 + 4 * v3) + 40) >= *(int*)(a1 + 40))
			v1 = v3 - 1;
		else
			v2 = v3 + 1;
	}
	return sub_498220(a1, v2);
}

//----- (00498220) --------------------------------------------------------
int __cdecl sub_498220(int a1, int a2) {
	if (a2 < *(int*)&dword_5d4594_1217460)
		memmove(dword_5d4594_1217456 + 4 * a2 + 4, (_BYTE*)(dword_5d4594_1217456 + 4 * a2),
				4 * (dword_5d4594_1217460 + 0x3FFFFFFF * a2));
	*(_DWORD*)(dword_5d4594_1217456 + 4 * a2) = a1;
	return ++dword_5d4594_1217460;
}

//----- (00498290) --------------------------------------------------------
int __cdecl sub_498290(int a1) {
	int v1;     // esi
	int v2;     // ecx
	int v3;     // eax
	int result; // eax

	v1 = 0;
	v2 = dword_5d4594_1217460 - 1;
	if (*(int*)&dword_5d4594_1217460 - 1 < 0)
		goto LABEL_11;
	do {
		v3 = (v2 + v1) / 2;
		if (*(int*)(*(_DWORD*)(dword_5d4594_1217456 + 4 * v3) + 44) >= *(int*)(a1 + 40))
			v2 = v3 - 1;
		else
			v1 = v3 + 1;
	} while (v1 <= v2);
	if (v2 >= 0)
		result = v2;
	else
	LABEL_11:
		result = 0;
	return result;
}

//----- (004982E0) --------------------------------------------------------
int __cdecl sub_4982E0(int a1) {
	int v1; // esi

	v1 = sub_498330(a1);
	memmove(dword_5d4594_1217456 + 4 * v1, (_BYTE*)(dword_5d4594_1217456 + 4 * (v1 + 1)),
			4 * (dword_5d4594_1217460 + 0x3FFFFFFF * (v1 + 1)));
	--dword_5d4594_1217460;
	return v1;
}

//----- (00498330) --------------------------------------------------------
int __cdecl sub_498330(int a1) {
	int v1;     // ebx
	int v2;     // edi
	int v3;     // esi
	int result; // eax
	int v5;     // ecx

	v1 = *(_DWORD*)(a1 + 40);
	v2 = 0;
	v3 = dword_5d4594_1217460 - 1;
	while (1) {
		result = (v3 + v2) / 2;
		v5 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1217456 + 4 * result) + 40);
		if (v5 == v1)
			break;
		if (v5 >= v1)
			v3 = (v3 + v2) / 2;
		else
			v2 = result + 1;
		if (v2 > v3)
			nox_exit(-1);
	}
	return result;
}

//----- (00498380) --------------------------------------------------------
void __cdecl sub_498380(int a1, int a2) {
	int v2;   // ebx
	int v3;   // edx
	int v4;   // ecx
	int v5;   // eax
	int v6;   // ecx
	int v7;   // eax
	int v8;   // ebx
	int v9;   // ecx
	int v10;  // ecx
	int v11;  // esi
	bool v12; // cc
	int v13;  // edx
	int v14;  // eax
	int v15;  // ebx
	int v16;  // ecx
	int v17;  // ecx
	int v18;  // edi
	int v19;  // ecx
	int v20;  // eax
	int v21;  // eax
	int v22;  // ecx

	v2 = *(_DWORD*)(a1 + 40);
	v3 = *(_DWORD*)(a2 + 44);
	if (v3 < v2)
		return;
	v4 = *(_DWORD*)(a2 + 40);
	v5 = *(_DWORD*)(a1 + 44);
	if (v4 > v5)
		return;
	if (v4 < v2) {
		if (v3 <= v5) {
			if (*(int*)(a1 + 32) >= *(int*)(a2 + 32)) {
				v6 = *(_DWORD*)(a1 + 44);
				*(_DWORD*)(a1 + 40) = v3 + 1;
				if (v3 + 1 > v6)
					*(_BYTE*)(a1 + 48) = 0;
			} else {
				*(_DWORD*)(a2 + 44) = v2 - 1;
			}
			return;
		}
		if (*(int*)(a1 + 32) < *(int*)(a2 + 32)) {
			v7 = sub_4CAED0(a2);
			v8 = *(_DWORD*)(v7 + 44);
			v9 = *(_DWORD*)(a1 + 44) + 1;
			*(_DWORD*)(v7 + 40) = v9;
			if (v9 > v8)
				*(_BYTE*)(v7 + 48) = 0;
			v10 = *(_DWORD*)(a1 + 40) - 1;
			v11 = *(_DWORD*)(a2 + 40);
			*(_DWORD*)(a2 + 44) = v10;
			if (v11 > v10)
				*(_BYTE*)(a2 + 48) = 0;
			sub_4CAE90(v7);
			return;
		}
	LABEL_27:
		*(_BYTE*)(a1 + 48) = 0;
		return;
	}
	v12 = v3 <= v5;
	v13 = *(_DWORD*)(a1 + 32);
	if (v12) {
		if (v13 >= *(int*)(a2 + 32)) {
			v14 = sub_4CAED0(a1);
			v15 = *(_DWORD*)(v14 + 44);
			v16 = *(_DWORD*)(a2 + 44) + 1;
			*(_DWORD*)(v14 + 40) = v16;
			if (v16 > v15)
				*(_BYTE*)(v14 + 48) = 0;
			v17 = *(_DWORD*)(a2 + 40) - 1;
			v18 = *(_DWORD*)(a1 + 40);
			*(_DWORD*)(a1 + 44) = v17;
			if (v18 > v17)
				*(_BYTE*)(a1 + 48) = 0;
			sub_4CAE90(v14);
		} else {
			*(_BYTE*)(a2 + 48) = 0;
		}
	} else {
		if (v13 >= *(int*)(a2 + 32)) {
			v21 = v4 - 1;
			v22 = *(_DWORD*)(a1 + 40);
			*(_DWORD*)(a1 + 44) = v21;
			if (v22 <= v21)
				return;
			goto LABEL_27;
		}
		v19 = *(_DWORD*)(a2 + 44);
		v20 = v5 + 1;
		*(_DWORD*)(a2 + 40) = v20;
		if (v20 > v19)
			*(_BYTE*)(a2 + 48) = 0;
	}
}

//----- (004984B0) --------------------------------------------------------
int __cdecl sub_4984B0_drawable(int a1) {
	int v1;    // edi
	int v3;    // ebx
	int v4;    // ecx
	int v5;    // kr0C_4
	int v6;    // ebp
	int v7;    // esi
	int v8;    // ebx
	int v9;    // ecx
	int v10;   // edx
	int v11;   // eax
	int v12;   // eax
	int v13;   // ebp
	int v14;   // esi
	int v15;   // ebx
	int v16;   // ecx
	int v17;   // esi
	int v18;   // eax
	int v19;   // ebp
	int v20;   // ecx
	int v21;   // edx
	int* v22;  // esi
	int v23;   // edi
	int v24;   // ebx
	int v25;   // ecx
	int v26;   // edx
	int v27;   // ebp
	int* v28;  // esi
	int v29;   // edi
	int v30;   // ebx
	int v31;   // [esp+10h] [ebp-58h]
	int v32;   // [esp+10h] [ebp-58h]
	char* v33; // [esp+14h] [ebp-54h]
	int v34;   // [esp+18h] [ebp-50h]
	int v35;   // [esp+18h] [ebp-50h]
	int v36;   // [esp+18h] [ebp-50h]
	int v37;   // [esp+1Ch] [ebp-4Ch]
	int v38;   // [esp+1Ch] [ebp-4Ch]
	int v39;   // [esp+20h] [ebp-48h]
	int v40;   // [esp+20h] [ebp-48h]
	int v41;   // [esp+24h] [ebp-44h]
	int v42;   // [esp+28h] [ebp-40h]
	int v43;   // [esp+2Ch] [ebp-3Ch]
	int v44;   // [esp+30h] [ebp-38h]
	int v45;   // [esp+34h] [ebp-34h]
	int4 a1a;  // [esp+38h] [ebp-30h]
	int4 a2;   // [esp+48h] [ebp-20h]
	int4 v48;  // [esp+58h] [ebp-10h]
	int* i;    // [esp+6Ch] [ebp+4h]
	int v50;   // [esp+6Ch] [ebp+4h]
	int v51;   // [esp+6Ch] [ebp+4h]

	v1 = a1;
	if (!*(_DWORD*)(a1 + 300))
		return 0;
	if (a1 == *(_DWORD*)&byte_5D4594[2614252])
		return 1;
	if ((signed char)*(_BYTE*)(a1 + 112) >= 0) {
		v42 = *(_DWORD*)(a1 + 12);
		v43 = *(_DWORD*)(a1 + 16);
		v6 = *(_DWORD*)(a1 + 12);
	} else {
		if (!(*(_BYTE*)(a1 + 116) & 4))
			return *(_DWORD*)(a1 + 132);
		v3 = *(_DWORD*)(a1 + 12);
		v4 = 8 * *(unsigned __int8*)(a1 + 299);
		v5 = *(int*)&byte_587000[v4 + 196184];
		v6 = v3 + v5 / 2;
		v42 = v3 + v5 / 2;
		v43 = *(_DWORD*)(a1 + 16) + *(int*)&byte_587000[v4 + 196188] / 2;
	}
	if (*(_DWORD*)(a1 + 120) & 0x10000)
		return *(_DWORD*)(a1 + 132);
	v31 = 0;
	v33 = sub_437250();
	v7 = *((_DWORD*)v33 + 4) - *(_DWORD*)v33;
	v44 = v7;
	v8 = *((_DWORD*)v33 + 5) - *((_DWORD*)v33 + 1);
	v45 = v8;
	a1a.field_0 = *(_DWORD*)v33 + *((int*)v33 + 8) / 2;
	a1a.field_4 = *((_DWORD*)v33 + 1) + *((_DWORD*)v33 + 12) + *((int*)v33 + 9) / 2;
	v37 = v6 - v7;
	a1a.field_8 = v6 - v7;
	a1a.field_C = v43 - v8;
	v9 = *(_DWORD*)&byte_5D4594[8 * dword_5d4594_1217464 + 1203868];
	v10 = *(_DWORD*)&byte_5D4594[8 * dword_5d4594_1217464 + 1203872];
	if (*(int*)&dword_5d4594_1217464 <= 0)
		return 1;
	for (i = (int*)&byte_5D4594[1203880];; i += 2) {
		a2.field_4 = v10;
		a2.field_0 = v9;
		v34 = *(i - 1);
		v11 = *i;
		a2.field_8 = *(i - 1);
		v39 = v11;
		a2.field_C = v11;
		if (sub_427C80(&a1a, &a2))
			break;
		v9 = v34;
		v10 = v39;
		if (++v31 >= *(int*)&dword_5d4594_1217464)
			return 1;
	}
	if (*(_DWORD*)(v1 + 44) == 2) {
		v12 = nox_float2int(*(float*)(v1 + 48));
		v50 = v12;
		if (*(_WORD*)(v1 + 2)) {
			v35 = *(unsigned __int16*)(v1 + 6);
			v13 = v6 - (*(unsigned __int16*)(v1 + 4) >> 1) - v7;
			v14 = v43 + v12 + *(__int16*)(v1 + 104) - v35 - v8 - nox_float2int(*(float*)(v1 + 96));
			v15 = v13 + *(unsigned __int16*)(v1 + 4);
			v16 = v14 + v35;
		} else {
			v13 = v6 - v12 - v7;
			v14 = v43 - v12 - v8 - nox_float2int(*(float*)(v1 + 100));
			v15 = v42 + v50 - v44;
			v16 = v43 + v50 + *(__int16*)(v1 + 104) - v45 - nox_float2int(*(float*)(v1 + 96));
		}
	} else if (*(_WORD*)(v1 + 2)) {
		v13 = v6 - (*(unsigned __int16*)(v1 + 4) >> 1) - v7;
		v16 = nox_float2int(*(float*)(v1 + 92)) + v43 + *(__int16*)(v1 + 104) - v8;
		v14 = v16 - *(unsigned __int16*)(v1 + 6);
		v15 = v13 + *(unsigned __int16*)(v1 + 4);
	} else {
		v13 = v37 + nox_float2int(*(float*)(v1 + 72));
		v17 = v43 - v8 - nox_float2int(*(float*)(v1 + 100));
		v14 = nox_float2int(*(float*)(v1 + 68)) + v17;
		v15 = v37 + nox_float2int(*(float*)(v1 + 80));
		v16 = nox_float2int(*(float*)(v1 + 92)) + v43 + *(__int16*)(v1 + 104) - v45;
	}
	v32 = 0;
	v51 = 0;
	v41 = v13;
	v38 = v14;
	v40 = v15;
	v36 = v16;
	if (v13 < *(int*)v33 || v13 > *((_DWORD*)v33 + 2))
		v32 = 1;
	else
		v51 = 1;
	if (v14 < *((_DWORD*)v33 + 1) || v14 > *((_DWORD*)v33 + 3))
		++v32;
	else
		++v51;
	if (v15 < *(int*)v33 || v15 > *((_DWORD*)v33 + 2))
		++v32;
	else
		++v51;
	if (v16 < *((_DWORD*)v33 + 1) || v16 > *((_DWORD*)v33 + 3))
		++v32;
	else
		++v51;
	if (*(_WORD*)(v1 + 2)) {
		if (v15 - v13 > 6) {
			v13 += 3;
			v15 -= 3;
		}
		if (v16 - v14 >= 22) {
			v14 += 11;
			v16 -= 11;
		}
	}
	if (!v51 || !v32)
		return 0;
	v48.field_0 = a1a.field_0;
	v48.field_4 = a1a.field_4;
	if (v41 >= *(int*)v33) {
		if (v40 <= *((_DWORD*)v33 + 2))
			goto LABEL_50;
		v48.field_8 = v13;
		a1a.field_8 = v13;
	} else {
		v48.field_8 = v15;
		a1a.field_8 = v15;
	}
	a1a.field_C = v14;
	v48.field_C = v16;
LABEL_50:
	if (v38 >= *((_DWORD*)v33 + 1)) {
		if (v36 <= *((_DWORD*)v33 + 3))
			goto LABEL_55;
		a1a.field_8 = v13;
		v48.field_C = v14;
		a1a.field_C = v14;
	} else {
		a1a.field_8 = v13;
		v48.field_C = v16;
		a1a.field_C = v16;
	}
	v48.field_8 = v15;
LABEL_55:
	v18 = dword_5d4594_1217464;
	v19 = 0;
	v20 = *(_DWORD*)&byte_5D4594[8 * dword_5d4594_1217464 + 1203868];
	v21 = *(_DWORD*)&byte_5D4594[8 * dword_5d4594_1217464 + 1203872];
	if (*(int*)&dword_5d4594_1217464 <= 0) {
	LABEL_59:
		v25 = *(_DWORD*)&byte_5D4594[8 * v18 + 1203868];
		v26 = *(_DWORD*)&byte_5D4594[8 * v18 + 1203872];
		v27 = 0;
		if (v18 <= 0)
			return 1;
		v28 = (int*)&byte_5D4594[1203880];
		while (1) {
			v29 = *(v28 - 1);
			v30 = *v28;
			a2.field_0 = v25;
			a2.field_4 = v26;
			a2.field_8 = v29;
			a2.field_C = v30;
			if (sub_427C80(&v48, &a2))
				break;
			++v27;
			v28 += 2;
			v25 = v29;
			v26 = v30;
			if (v27 >= *(int*)&dword_5d4594_1217464)
				return 1;
		}
	} else {
		v22 = (int*)&byte_5D4594[1203880];
		while (1) {
			v23 = *(v22 - 1);
			v24 = *v22;
			a2.field_4 = v21;
			a2.field_0 = v20;
			a2.field_8 = v23;
			a2.field_C = v24;
			if (sub_427C80(&a1a, &a2))
				break;
			v18 = dword_5d4594_1217464;
			++v19;
			v22 += 2;
			v20 = v23;
			v21 = v24;
			if (v19 >= *(int*)&dword_5d4594_1217464)
				goto LABEL_59;
		}
	}
	return 0;
}

//----- (004989A0) --------------------------------------------------------
void __cdecl sub_4989A0() {
	int v0;               // ebp
	unsigned __int8* v1;  // edx
	int v2;               // eax
	int v3;               // ecx
	int v4;               // esi
	int v5;               // edi
	int v6;               // ebx
	int v7;               // [esp+0h] [ebp-24h]
	unsigned __int8* v8;  // [esp+4h] [ebp-20h]
	unsigned __int8* v9;  // [esp+8h] [ebp-1Ch]
	int v10;              // [esp+Ch] [ebp-18h]
	unsigned __int8* v11; // [esp+10h] [ebp-14h]
	int v12;              // [esp+14h] [ebp-10h]
	int v13;              // [esp+18h] [ebp-Ch]
	unsigned __int8* i;   // [esp+1Ch] [ebp-8h]
	unsigned __int8 v15;  // [esp+20h] [ebp-4h]

	if (dword_5d4594_1217464 > 2) {
		v0 = 2;
		v1 = &byte_5D4594[1203896];
		v12 = *(_DWORD*)&byte_5D4594[1203876];
		v2 = *(_DWORD*)&byte_5D4594[1203884];
		v13 = *(_DWORD*)&byte_5D4594[1203880];
		v3 = *(_DWORD*)&byte_5D4594[1203888];
		v10 = 2;
		v7 = 1;
		v9 = &byte_5D4594[1213352];
		v8 = &byte_5D4594[1203888];
		v11 = &byte_5D4594[1213356];
		for (i = &byte_5D4594[1203896];; i += 8) {
			v4 = *((_DWORD*)v1 - 1);
			v5 = *(_DWORD*)v1;
			v15 = byte_5D4594[v0 + 1212324];
			if ((v12 - v2) * (*(_DWORD*)v1 - v3) != (v13 - v3) * (v4 - v2))
				break;
			v6 = v7;
			if (byte_5D4594[v10 + 1212324] != byte_5D4594[v7 + 1212324])
				goto LABEL_7;
		LABEL_8:
			v0 = v10 + 1;
			*((_DWORD*)v8 - 1) = v4;
			*(_DWORD*)v8 = v5;
			v10 = v0;
			byte_5D4594[v6 + 1212324] = v15;
			*(_DWORD*)v9 = *(_DWORD*)v11;
			v3 = v5;
			v2 = v4;
			v1 = i + 8;
			v11 += 4;
			if (v0 >= *(int*)&dword_5d4594_1217464) {
				dword_5d4594_1217464 = v6 + 1;
				return;
			}
		}
		v6 = v7;
	LABEL_7:
		v7 = ++v6;
		v8 += 8;
		v12 = v2;
		v9 += 4;
		v13 = v3;
		goto LABEL_8;
	}
}

//----- (00498AE0) --------------------------------------------------------
int sub_498AE0() {
	int v0; // ecx
	int v1; // esi
	int i;  // eax

	nox_client_drawEnableAlpha_434560(1);
	sub_434430(0, 0, 0);
	v0 = dword_5d4594_1217464;
	v1 = 0;
	for (i = dword_5d4594_1217464 - 1; v1 < v0; ++v1) {
		if (byte_5D4594[i + 1212324] == 12) {
			sub_498B50(*(_DWORD*)&byte_5D4594[8 * i + 1203876], *(_DWORD*)&byte_5D4594[8 * i + 1203880],
					   *(_DWORD*)&byte_5D4594[8 * v1 + 1203876], *(_DWORD*)&byte_5D4594[8 * v1 + 1203880]);
			v0 = dword_5d4594_1217464;
		}
		i = v1;
	}
	return nox_client_drawEnableAlpha_434560(0);
}

//----- (00498B50) --------------------------------------------------------
int __cdecl sub_498B50(int a1, int a2, int a3, int a4) {
	int v4;              // ebp
	int v5;              // esi
	int v6;              // edi
	int v7;              // ecx
	int v8;              // eax
	int v9;              // ebx
	int v10;             // edx
	int v11;             // eax
	int v12;             // ebx
	int v13;             // ebp
	int result;          // eax
	unsigned __int8 v15; // [esp+14h] [ebp+4h]
	int v16;             // [esp+18h] [ebp+8h]
	int v17;             // [esp+1Ch] [ebp+Ch]
	int v18;             // [esp+20h] [ebp+10h]

	v4 = a3;
	v5 = a1;
	v6 = a2;
	v7 = a2 - a4;
	v8 = a1 - a3;
	v9 = a1 - a3;
	v10 = a4 - a2;
	if (a1 - a3 < 0)
		v8 = a3 - a1;
	if (v7 < 0)
		v7 = a4 - a2;
	if (v8 <= v7) {
		v16 = 0;
		v17 = v10 < 0 ? 1 : -1;
	} else {
		v17 = 0;
		v11 = (v9 < 0) - 1;
		LOBYTE(v11) = v11 & 0xFE;
		v16 = v11 + 1;
	}
	v15 = -48;
	v12 = a4 - v6;
	v13 = v4 - v5;
	v18 = 10;
	do {
		nox_client_drawSetAlpha_434580(v15);
		v15 -= 20;
		nox_client_drawAddPoint_49F500(v5, v6);
		nox_client_drawAddPoint_49F500(v5 + v13, v12 + v6);
		nox_client_drawLineFromPoints_49E4B0();
		v5 += v17;
		v6 += v16;
		result = --v18;
	} while (v18);
	return result;
}

//----- (00498C20) --------------------------------------------------------
int __cdecl sub_498C20(int2* a1, int2* a2, int a3) {
	int2* v3;             // edi
	int2* v4;             // ebp
	char v5;              // al
	char v6;              // bl
	int v7;               // eax
	int v8;               // edx
	int* v9;              // ecx
	int v10;              // eax
	int v11;              // ebp
	int v12;              // edx
	int v13;              // ebp
	int v14;              // edx
	int v15;              // eax
	int v16;              // esi
	int v17;              // eax
	int v18;              // ecx
	bool v19;             // cc
	float v21;            // [esp+0h] [ebp-44h]
	float v22;            // [esp+0h] [ebp-44h]
	float v23;            // [esp+0h] [ebp-44h]
	float v24;            // [esp+0h] [ebp-44h]
	float v25;            // [esp+0h] [ebp-44h]
	float v26;            // [esp+0h] [ebp-44h]
	float v27;            // [esp+4h] [ebp-40h]
	float v28;            // [esp+14h] [ebp-30h]
	float v29;            // [esp+18h] [ebp-2Ch]
	float v30;            // [esp+1Ch] [ebp-28h]
	int v31;              // [esp+20h] [ebp-24h]
	int v32;              // [esp+24h] [ebp-20h]
	unsigned __int8* v33; // [esp+28h] [ebp-1Ch]
	int2 a1a;             // [esp+2Ch] [ebp-18h]
	int2 a2a;             // [esp+34h] [ebp-10h]
	int2 a3a;             // [esp+3Ch] [ebp-8h]
	char v37;             // [esp+48h] [ebp+4h]
	char v38;             // [esp+50h] [ebp+Ch]
	float v39;            // [esp+50h] [ebp+Ch]

	v3 = a1;
	if (!a1)
		return 0;
	v4 = a2;
	if (!a2)
		return 0;
	if (!a3)
		return 0;
	dword_5d4594_1217452 = 0;
	v5 = sub_4990D0(a1, a2);
	v6 = v5;
	v37 = v5;
	if (!v5)
		return 0;
	if (v5 != 4 && v5 != 8) {
		v29 = (double)(a2->field_4 - v3->field_4) / (double)(a2->field_0 - v3->field_0);
		v27 = (double)v3->field_0 * v29;
		v31 = v3->field_4 - nox_float2int(v27);
	}
	v7 = dword_5d4594_1217464;
	v8 = 0;
	v32 = 0;
	if (dword_5d4594_1217464 > 0) {
		v9 = (int*)&byte_5D4594[1203884];
		v33 = &byte_5D4594[1203884];
		while (1) {
			a2a = *((int2*)v9 - 1);
			if (v8 == v7 - 1) {
				a3a = *(int2*)&byte_5D4594[1203876];
			} else {
				v10 = v9[1];
				a3a.field_0 = *v9;
				a3a.field_4 = v10;
			}
			v38 = sub_4990D0(&a2a, &a3a);
			if (v38 &&
				(!(v6 & 1) || a2a.field_0 <= v3->field_0 || a2a.field_0 <= v4->field_0 || a3a.field_0 <= v3->field_0 ||
				 a3a.field_0 <= v4->field_0) &&
				(!(v37 & 2) || a2a.field_0 >= v3->field_0 || a2a.field_0 >= v4->field_0 ||
				 a3a.field_0 >= v3->field_0)) {
				if (!(v37 & 4) || (v11 = v3->field_4, a2a.field_4 <= v11) || (v12 = a2->field_4, a2a.field_4 <= v12) ||
					a3a.field_4 <= v11 || a3a.field_4 <= v12) {
					if (!(v37 & 8) || (v13 = v3->field_4, a2a.field_4 >= v13) ||
						(v14 = a2->field_4, a2a.field_4 >= v14) || a3a.field_4 >= v13 || a3a.field_4 >= v14) {
						if (a2a.field_0 == a3a.field_0) {
							if (v37 == 4 || v37 == 8)
								goto LABEL_65;
							if (v37 != 1 && v37 != 2) {
								a1a.field_0 = a2a.field_0;
								v26 = (double)a2a.field_0 * v29;
								a1a.field_4 = v31 + nox_float2int(v26);
							LABEL_59:
								if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
									sub_499130(&a1a.field_0);
								goto LABEL_65;
							}
							a1a.field_4 = v3->field_0;
							a1a.field_0 = a2a.field_0;
							if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2)) {
							LABEL_64:
								sub_499130(&a1a.field_0);
								goto LABEL_65;
							}
						} else {
							v28 = (double)(a3a.field_4 - a2a.field_4) / (double)(a3a.field_0 - a2a.field_0);
							v21 = (double)a2a.field_0 * v28;
							v15 = nox_float2int(v21);
							v16 = a2a.field_4 - v15;
							if (v37 == 4 || v37 == 8) {
								if (v38 == 1 || v38 == 2) {
									a1a.field_0 = v3->field_0;
									a1a.field_4 = a2a.field_0;
									if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
										sub_499130(&a1a.field_0);
								} else {
									a1a.field_0 = v3->field_0;
									v22 = (double)a1a.field_0 * v28;
									a1a.field_4 = v16 + nox_float2int(v22);
									if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
										sub_499130(&a1a.field_0);
								}
							}
							if (v37 == 1 || v37 == 2) {
								if (v38 == 1 || v38 == 2)
									goto LABEL_65;
								v25 = (double)(v31 - v16) / v28;
								v17 = nox_float2int(v25);
								v18 = v3->field_4;
								a1a.field_0 = v17;
								a1a.field_4 = v18;
								goto LABEL_59;
							}
							if (v29 != v28) {
								v39 = (double)(v31 - v16);
								v30 = v28 - v29;
								v23 = v39 / v30;
								a1a.field_0 = nox_float2int(v23);
								v24 = v39 * v28 / v30;
								a1a.field_4 = v16 + nox_float2int(v24);
								if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2))
									goto LABEL_64;
							}
						}
					}
				}
			}
		LABEL_65:
			v7 = dword_5d4594_1217464;
			v8 = v32 + 1;
			v9 = (int*)(v33 + 8);
			v19 = ++v32 < *(int*)&dword_5d4594_1217464;
			v33 += 8;
			if (!v19)
				break;
			v6 = v37;
			v4 = a2;
		}
	}
	sub_4991E0(v3);
	return dword_5d4594_1217452;
}
// 498EE0: variable 'v29' is possibly undefined
// 498EFA: variable 'v31' is possibly undefined

//----- (004990D0) --------------------------------------------------------
char __cdecl sub_4990D0(_DWORD* a1, _DWORD* a2) {
	int v2;      // ecx
	int v3;      // edx
	char result; // al
	int v5;      // ecx
	int v6;      // edx
	int v7;      // ecx
	int v8;      // edx

	if (*a1 <= *a2) {
		if (*a1 >= *a2) {
			v7 = a1[1];
			v8 = a2[1];
			if (v7 <= v8) {
				if (v7 >= v8)
					result = 0;
				else
					result = 8;
			} else {
				result = 4;
			}
		} else {
			v5 = a1[1];
			v6 = a2[1];
			result = 2;
			if (v5 <= v6) {
				if (v5 < v6)
					result = 10;
			} else {
				result = 6;
			}
		}
	} else {
		v2 = a1[1];
		v3 = a2[1];
		result = 1;
		if (v2 <= v3) {
			if (v2 < v3)
				result = 9;
		} else {
			result = 5;
		}
	}
	return result;
}

//----- (00499130) --------------------------------------------------------
int __cdecl sub_499130(int* a1) {
	int result; // eax

	result = dword_5d4594_1217452;
	if (*(int*)&dword_5d4594_1217452 < 32) {
		result = dword_5d4594_1217452 + 1;
		*(_DWORD*)&byte_5D4594[8 * result + 1212060] = *a1;
		*(_DWORD*)&byte_5D4594[8 * result + 1212064] = a1[1];
		dword_5d4594_1217452 = result;
	}
	return result;
}

//----- (00499160) --------------------------------------------------------
BOOL __cdecl sub_499160(int2* a1, int2* a2, int2* a3) {
	int v3;      // edi
	int v4;      // esi
	int v5;      // eax
	int v6;      // edx
	int v7;      // ecx
	BOOL result; // eax

	v3 = a3->field_0;
	if (a3->field_0 > a2->field_0) {
		v4 = a3->field_4;
		if (v4 > a2->field_4) {
			v3 = a3->field_0;
			v6 = a2->field_0;
			v4 = a2->field_4;
			v5 = a3->field_4;
		} else {
			v6 = a2->field_0;
			v5 = a2->field_4;
		}
	} else {
		v4 = a2->field_4;
		if (a3->field_4 > v4) {
			v6 = a3->field_0;
			v3 = a2->field_0;
			v5 = a3->field_4;
		} else {
			v5 = a2->field_4;
			v6 = a3->field_0;
			v4 = a3->field_4;
			v3 = a2->field_0;
		}
	}
	result = 0;
	if (a1->field_0 >= v6 && a1->field_0 <= v3) {
		v7 = a1->field_4;
		if (v7 >= v4 && v7 <= v5)
			result = 1;
	}
	return result;
}

//----- (004991E0) --------------------------------------------------------
void __cdecl sub_4991E0(_DWORD* a1) {
	int v1;              // ebp
	_DWORD* v2;          // ebx
	int v3;              // esi
	unsigned __int8* v4; // edx
	int v5;              // edi
	int v6;              // edi
	_DWORD* v7;          // ecx
	int v8;              // eax
	int v9;              // eax
	int v10;             // esi
	int v11;             // eax
	int v12;             // [esp+4h] [ebp-4h]
	int v13;             // [esp+Ch] [ebp+4h]

	v1 = dword_5d4594_1217452;
	if (dword_5d4594_1217452 > 0) {
		v2 = a1;
		v3 = 1;
		v12 = 1;
		v4 = &byte_5D4594[1212068];
		do {
			v5 = *((_DWORD*)v4 + 1) - v2[1];
			v6 = (*(_DWORD*)v4 - *v2) * (*(_DWORD*)v4 - *v2) + v5 * v5;
			if (v3 < v1) {
				v7 = v4 + 8;
				v13 = v1 - v3;
				do {
					v8 = v7[1] - v2[1];
					v9 = (*v7 - *v2) * (*v7 - *v2) + v8 * v8;
					if (v9 < v6) {
						v10 = *((_DWORD*)v4 + 1);
						v6 = v9;
						v11 = *(_DWORD*)v4;
						*(_DWORD*)v4 = *v7;
						*((_DWORD*)v4 + 1) = v7[1];
						*v7 = v11;
						v7[1] = v10;
					}
					v7 += 2;
					--v13;
				} while (v13);
				v1 = dword_5d4594_1217452;
				v3 = v12;
			}
			++v3;
			v4 += 8;
			v12 = v3;
		} while (v3 - 1 < v1);
	}
}

//----- (00499290) --------------------------------------------------------
_QWORD __cdecl sub_499290(int a1) {
	__int64 result; // rax

	LODWORD(result) = *(_DWORD*)&byte_5D4594[8 * a1 + 1212068];
	HIDWORD(result) = *(_DWORD*)&byte_5D4594[8 * a1 + 1212072];
	return result;
}

//----- (004992B0) --------------------------------------------------------
BOOL __cdecl sub_4992B0(int a1, int a2) {
	BOOL result; // eax
	int v3;      // ecx
	int v4;      // ebp
	int v5;      // ecx
	int v6;      // edx
	BOOL v7;     // [esp+0h] [ebp-8h]
	int v8;      // [esp+4h] [ebp-4h]

	result = 0;
	v7 = 0;
	v8 = 0;
	if (*(int*)&dword_5d4594_1217464 > 0) {
		v3 = 8 * *(int*)&dword_5d4594_1217464 - 8;
		do {
			v4 = *(int*)&byte_5D4594[v3 + 1203876];
			v5 = *(int*)&byte_5D4594[v3 + 1203880];
			v6 = *(int*)&byte_5D4594[8 * v8 + 1203880];
			if (v6 > a2) {
				if (v5 > a2)
					goto LABEL_11;
			} else if (a2 < v5) {
				goto LABEL_8;
			}
			if (a2 < v6) {
			LABEL_8:
				if (a1 >= *(int*)&byte_5D4594[8 * v8 + 1203876] +
							  (a2 - v6) * (v4 - *(int*)&byte_5D4594[8 * v8 + 1203876]) / (v5 - v6)) {
					result = v7;
				} else {
					result = !v7;
					v7 = !v7;
				}
			}
		LABEL_11:
			v3 = 8 * v8++;
		} while (v8 < *(int*)&dword_5d4594_1217464);
	}
	return result;
}

//----- (00499360) --------------------------------------------------------
int sub_499360() {
	int v0;              // eax
	int v1;              // eax
	int v2;              // eax
	int v3;              // eax
	int v4;              // eax
	int v5;              // eax
	int v6;              // eax
	int v7;              // eax
	unsigned __int8* v8; // eax

	v0 = sub_44CFC0((CHAR*)&byte_587000[161848]);
	*(_DWORD*)&byte_5D4594[1217468] = nox_new_drawable_for_thing(v0);
	v1 = sub_44CFC0((CHAR*)&byte_587000[161868]);
	*(_DWORD*)&byte_5D4594[1217472] = nox_new_drawable_for_thing(v1);
	v2 = sub_44CFC0((CHAR*)&byte_587000[161888]);
	*(_DWORD*)&byte_5D4594[1217476] = nox_new_drawable_for_thing(v2);
	v3 = sub_44CFC0((CHAR*)&byte_587000[161908]);
	*(_DWORD*)&byte_5D4594[1217480] = nox_new_drawable_for_thing(v3);
	*(_DWORD*)&byte_5D4594[1217484] = 0;
	v4 = sub_44CFC0((CHAR*)&byte_587000[161928]);
	*(_DWORD*)&byte_5D4594[1217488] = nox_new_drawable_for_thing(v4);
	v5 = sub_44CFC0((CHAR*)&byte_587000[161948]);
	*(_DWORD*)&byte_5D4594[1217492] = nox_new_drawable_for_thing(v5);
	v6 = sub_44CFC0((CHAR*)&byte_587000[161968]);
	*(_DWORD*)&byte_5D4594[1217496] = nox_new_drawable_for_thing(v6);
	v7 = sub_44CFC0((CHAR*)&byte_587000[161988]);
	*(_DWORD*)&byte_5D4594[1217500] = nox_new_drawable_for_thing(v7);
	v8 = &byte_5D4594[1217468];
	while (v8 == &byte_5D4594[1217484]) {
	LABEL_5:
		v8 += 4;
		if ((int)v8 >= (int)&byte_5D4594[1217504]) {
			*(_DWORD*)&byte_5D4594[1217504] = 0;
			return 1;
		}
	}
	if (*(_DWORD*)v8) {
		*(_DWORD*)(*(_DWORD*)v8 + 120) |= 0x1000000u;
		goto LABEL_5;
	}
	return 0;
}

//----- (00499450) --------------------------------------------------------
int sub_499450() {
	unsigned __int8* v0; // esi
	int result;          // eax

	v0 = &byte_5D4594[1217468];
	do {
		result = *(_DWORD*)v0;
		if (*(_DWORD*)v0)
			result = sub_45A4B0(*(_QWORD**)v0);
		*(_DWORD*)v0 = 0;
		v0 += 4;
	} while ((int)v0 < (int)&byte_5D4594[1217504]);
	*(_DWORD*)&byte_5D4594[1217504] = 0;
	return result;
}

//----- (00499810) --------------------------------------------------------
int __cdecl sub_499810(int a1, int a2) {
	int v3; // [esp-4h] [ebp-8h]

	*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * *(unsigned __int8*)(a2 + 297) + 1217468] + 12) =
		*(_DWORD*)(a2 + 12) + *(_DWORD*)&byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 161776];
	*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * *(unsigned __int8*)(a2 + 297) + 1217468] + 16) =
		*(_DWORD*)(a2 + 16) + *(__int16*)(a2 + 104) +
		*(_DWORD*)&byte_587000[8 * *(unsigned __int8*)(a2 + 297) + 161780];
	v3 = *(_DWORD*)&byte_5D4594[4 * *(unsigned __int8*)(a2 + 297) + 1217468];
	(*(void(__cdecl**)(int, int))(v3 + 300))(a1, v3);
	return 0;
}

//----- (00499880) --------------------------------------------------------
_DWORD* __cdecl sub_499880(__int16* a1) {
	int i;          // ebx
	_DWORD* result; // eax
	_DWORD* v3;     // esi
	int v4;         // eax
	double v5;      // st7

	if (!*(_DWORD*)&byte_5D4594[1217508])
		*(_DWORD*)&byte_5D4594[1217508] = sub_44CFC0((CHAR*)&byte_587000[162360]);
	for (i = 0; i < 256; i += 6) {
		result = (_DWORD*)sub_45A360_drawable(*(int*)&byte_5D4594[1217508], *a1, a1[1]);
		v3 = result;
		if (result) {
			v4 = 8 * (__int16)i;
			*((_WORD*)v3 + 254) = i;
			*((float*)v3 + 117) = *(float*)&byte_587000[v4 + 194136] * 4.0;
			v5 = *(float*)&byte_587000[v4 + 194140] * 4.0;
			v3[119] = 0;
			*((float*)v3 + 118) = v5;
			v3[79] = *(_DWORD*)&byte_5D4594[2598000];
			v3[81] = *a1;
			v3[82] = a1[1];
			v3[115] = sub_4CA540;
			sub_49BC80_drawable(v3);
			result = sub_49BAB0_drawable(v3);
		}
	}
	return result;
}

//----- (00499B70) --------------------------------------------------------
void __cdecl sub_499B70(int xLeft, int yTop, int a3) {
	switch (a3) {
	case 0:
	case 1:
		sub_49EFA0(xLeft, yTop);
		break;
	case 2:
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, 2, 2);
		break;
	case 3:
		sub_49EFA0(xLeft, yTop - 1);
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 1, yTop, 3, 1);
		sub_49EFA0(xLeft, yTop + 1);
		break;
	case 4:
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop - 1, 2, 1);
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 1, yTop, 4, 2);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop + 2, 2, 1);
		break;
	case 5:
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 1, yTop - 2, 3, 1);
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 2, yTop - 1, 5, 3);
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 1, yTop + 2, 3, 1);
		break;
	case 6:
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop - 2, 2, 1);
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 1, yTop - 1, 4, 1);
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 2, yTop, 6, 2);
		nox_client_drawRectFilledOpaque_49CE30(xLeft - 1, yTop + 2, 4, 1);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop + 3, 2, 1);
		break;
	default:
		sub_4B0BC0(xLeft, yTop, a3 >> 1);
		break;
	}
}

//----- (00499CF0) --------------------------------------------------------
void sub_499CF0(int* a1, int a2, int a3) {
	unsigned int result; // eax
	int v4;              // esi
	int2 a3a;            // [esp+8h] [ebp-8h]

	sub_437250();
	if (!nox_common_gameFlags_check_40A5C0(2048) ||
		(result = sub_430B40_get_mouse_prev_seq() - *(_DWORD*)&byte_5D4594[1217504], result >= 2)) {
		*(_DWORD*)&byte_5D4594[1217504] = sub_430B40_get_mouse_prev_seq();
		if (a1 == (int*)2)
			v4 = 0;
		else
			v4 = (a1 == (int*)3) + 2;
		a3a.field_0 = 5;
		a3a.field_4 = nox_win_height / 3;
		sub_45D200(a1, a2, &a3a);
		sub_499E70(v4, a3a.field_0, a3a.field_4, 271, 166, 1, 1);
		sub_499E70(v4, a3a.field_0, a3a.field_4, 135, 166, 2, 1);
		sub_499E70(v4, a3a.field_0, a3a.field_4 + 166, 135, 166, 2, 1);
		sub_499E70(v4, a3a.field_0 + 271, a3a.field_4, 271, 166, 1, 2);
		sub_499E70(v4, a3a.field_0 + 135, a3a.field_4, 135, 166, 2, 2);
		sub_499E70(v4, a3a.field_0 + 135, a3a.field_4 + 166, 135, 166, 2, 2);
		if (a1 != (int*)4 && a3 == 1)
			sub_45D570((int)a1, a2);
	}
}

//----- (00499F60) --------------------------------------------------------
_DWORD* __cdecl sub_499F60(int a1, int a2, int a3, __int16 a4, char a5, char a6, char a7, char a8, char a9, int a10) {
	_DWORD* result; // eax
	int v11;        // edx
	int v12;        // ecx
	_DWORD* v13;    // esi
	int v14;        // eax

	if (!*(_DWORD*)&byte_5D4594[1217512]) {
		*(_DWORD*)&byte_5D4594[1217512] = sub_44CFC0((CHAR*)&byte_587000[162824]);
		*(_DWORD*)&byte_5D4594[1217516] = sub_44CFC0((CHAR*)&byte_587000[162844]);
		*(_DWORD*)&byte_5D4594[1217520] = sub_44CFC0((CHAR*)&byte_587000[162864]);
		*(_DWORD*)&byte_5D4594[1217524] = sub_44CFC0((CHAR*)&byte_587000[162888]);
		*(_DWORD*)&byte_5D4594[1217528] = sub_44CFC0((CHAR*)&byte_587000[162912]);
		*(_DWORD*)&byte_5D4594[1217532] = sub_44CFC0((CHAR*)&byte_587000[162932]);
		*(_DWORD*)&byte_5D4594[1217536] = sub_44CFC0((CHAR*)&byte_587000[162956]);
		*(_DWORD*)&byte_5D4594[1217540] = sub_44CFC0((CHAR*)&byte_587000[162984]);
	}
	result = (_DWORD*)sub_45A360_drawable(a1, a2, a3);
	v13 = result;
	if (result) {
		BYTE1(v11) = HIBYTE(a4);
		LOBYTE(result) = *((_BYTE*)result + 160);
		LOBYTE(v12) = *((_BYTE*)v13 + 156);
		*((_WORD*)v13 + 52) = a4;
		LOBYTE(v11) = *((_BYTE*)v13 + 152);
		v13[108] = sub_4344A0(v11, v12, (int)result);
		if (a1 == *(_DWORD*)&byte_5D4594[1217512]) {
			v14 = sub_4344A0(255, 128, 128);
		} else if (a1 == *(_DWORD*)&byte_5D4594[1217516]) {
			v14 = sub_4344A0(255, 255, 255);
		} else if (a1 == *(_DWORD*)&byte_5D4594[1217524]) {
			v14 = sub_4344A0(255, 100, 50);
		} else if (a1 == *(_DWORD*)&byte_5D4594[1217528]) {
			v14 = sub_4344A0(64, 255, 64);
		} else if (a1 == *(_DWORD*)&byte_5D4594[1217532]) {
			v14 = sub_4344A0(255, 100, 255);
		} else if (a1 == *(_DWORD*)&byte_5D4594[1217536]) {
			v14 = sub_4344A0(255, 200, 255);
		} else if (a1 == *(_DWORD*)&byte_5D4594[1217540]) {
			v14 = sub_4344A0(255, 255, 200);
		} else {
			v14 = sub_4344A0(200, 200, 255);
		}
		v13[109] = v14;
		*((_BYTE*)v13 + 440) = a5;
		*((_BYTE*)v13 + 443) = a6;
		*((_BYTE*)v13 + 442) = a6;
		*((_BYTE*)v13 + 441) = 1;
		*((_BYTE*)v13 + 444) = a8;
		*((_BYTE*)v13 + 445) = a9;
		*((_BYTE*)v13 + 446) = a7;
		sub_49BAB0_drawable(v13);
		sub_49B950(v13, a10);
		result = sub_45A110_drawable(v13);
	}
	return result;
}
// 49A025: variable 'v11' is possibly undefined
// 49A025: variable 'v12' is possibly undefined

//----- (0049A2C0) --------------------------------------------------------
void nox_alloc_npcs() { npc_array = nox_calloc(nox_max_npcs, sizeof(nox_npc)); }

//----- (0049A300) --------------------------------------------------------
nox_npc* __cdecl nox_new_npc(int id) {
	int n = 0;
	nox_npc* cur = npc_array;
	while (cur->live) {
		cur++;
		n++;
		if (n >= nox_max_npcs)
			return 0;
	}
	nox_init_npc(cur, id);
	return cur;
}

//----- (0049A340) --------------------------------------------------------
nox_npc* __cdecl nox_npc_by_id(int id) {
	int n = 0;
	nox_npc* cur = npc_array;
	while (cur->id != id || !cur->live) {
		cur++;
		n++;
		if (n >= nox_max_npcs)
			return 0;
	}
	return cur;
}

//----- (0049A380) --------------------------------------------------------
int __cdecl nox_init_npc(nox_npc* ptr, int id) {
	memset(ptr, 0, sizeof(nox_npc));
	ptr->live = 1;
	ptr->id = id;
	return id;
}

//----- (0049A3B0) --------------------------------------------------------
nox_npc* __cdecl nox_npc_set_328(int id, int a2) {
	nox_npc* p = nox_npc_by_id(id);
	if (p)
		p->data8[326] = a2;
	return p;
}

//----- (0049A3D0) --------------------------------------------------------
char* __cdecl sub_49A3D0(char a1, int a2, int a3, int a4) {
	char* npc;  // eax
	_DWORD* k;  // edx
	char* v7;   // ecx
	char** v8;  // edi
	int l;      // esi
	_DWORD* i;  // edx
	char* v12;  // ecx
	char** v13; // edi
	int j;      // esi

	npc = nox_npc_by_id(a2);
	if (!npc)
		return 0;
	if (a1 == 81 || a1 == 80) {
		int v10 = 0;
		for (i = npc + 32; *i; i += 6) {
			if (++v10 >= 27)
				return npc;
		}
		v12 = &npc[24 * v10];
		*((_DWORD*)v12 + 8) = a3;
		v13 = (char**)(v12 + 36);
		*((_DWORD*)npc + 326) |= a3;
		for (j = 0; j < 4; ++j) {
			npc = (char*)sub_413330(*(unsigned __int8*)(j + a4));
			*v13 = npc;
			++v13;
		}
	} else {
		int v5 = 0;
		for (k = npc + 680; *k; k += 6) {
			if (++v5 >= 26)
				return npc;
		}
		v7 = &npc[24 * v5];
		*((_DWORD*)v7 + 170) = a3;
		v8 = (char**)(v7 + 684);
		*((_DWORD*)npc + 327) |= a3;
		for (l = 0; l < 4; ++l) {
			npc = (char*)sub_413330(*(unsigned __int8*)(l + a4));
			*v8 = npc;
			++v8;
		}
	}
	return npc;
}

//----- (0049A5F0) --------------------------------------------------------
int sub_49A5F0() {
	int result; // eax

	result = nox_new_alloc_class("HealthChange", 20, 32);
	nox_alloc_healthChange_1301772 = result;
	if (result) {
		dword_5d4594_1301780 = sub_43F360((char*)&byte_587000[163264]);
		result = 1;
	}
	return result;
}

//----- (0049A630) --------------------------------------------------------
void sub_49A630() {
	sub_4144D0(*(_DWORD**)&nox_alloc_healthChange_1301772);
	dword_5d4594_1301776 = 0;
}

//----- (0049A650) --------------------------------------------------------
_WORD* __cdecl sub_49A650(int a1, __int16 a2) {
	_WORD* result; // eax
	_WORD* v3;     // esi

	result = nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_healthChange_1301772);
	v3 = result;
	if (result) {
		*(_DWORD*)result = a1;
		result[2] = a2;
		*((_DWORD*)result + 2) = sub_430B40_get_mouse_prev_seq();
		*((_DWORD*)v3 + 3) = dword_5d4594_1301776;
		*((_DWORD*)v3 + 4) = 0;
		result = *(_WORD**)&dword_5d4594_1301776;
		if (dword_5d4594_1301776)
			*(_DWORD*)(dword_5d4594_1301776 + 16) = v3;
		dword_5d4594_1301776 = v3;
	}
	return result;
}

//----- (0049A6A0) --------------------------------------------------------
void __cdecl sub_49A6A0(_DWORD* a1, int a2) {
	_DWORD* v2;      // eax
	int v3;          // esi
	_DWORD* v4;      // edi
	int v5;          // edi
	int v6;          // esi
	int v7;          // edi
	_DWORD* v8;      // [esp+4h] [ebp-C0h]
	int v9;          // [esp+Ch] [ebp-B8h]
	int v10;         // [esp+10h] [ebp-B4h]
	_DWORD* v11;     // [esp+1Ch] [ebp-A8h]
	int v12;         // [esp+20h] [ebp-A4h]
	wchar_t v13[80]; // [esp+24h] [ebp-A0h]

	v10 = sub_430B40_get_mouse_prev_seq();
	if (a2 == *(_DWORD*)&byte_5D4594[2614252])
		v9 = *(_DWORD*)&byte_5D4594[2650644];
	else
		v9 = *(_DWORD*)&byte_5D4594[2589772];
	v2 = *(_DWORD**)&dword_5d4594_1301776;
	v8 = *(_DWORD**)&dword_5d4594_1301776;
	if (dword_5d4594_1301776) {
		while (1) {
			v3 = v2[2];
			v4 = (_DWORD*)v2[3];
			v11 = (_DWORD*)v2[3];
			if ((unsigned int)(v10 - v3) <= 0x1E) {
				if (*v2 == *(_DWORD*)(a2 + 128)) {
					v5 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
					v6 = *(_DWORD*)(a2 + 16) + a1[1] + 2 * (v3 - v10) - *(__int16*)(a2 + 104) -
						 (unsigned __int64)(__int64)*(float*)(a2 + 100) - a1[5];
					nox_swprintf(v13, L"%d", abs32(*((__int16*)v8 + 2)));
					sub_43F840(*(int*)&dword_5d4594_1301780, v13, &v12, 0, 0);
					v7 = v12 / -2 + v5;
					sub_434390(*(int*)&byte_5D4594[2650656]);
					sub_43F6E0(*(int*)&dword_5d4594_1301780, (__int16*)v13, v7 - 1, v6 - 1);
					sub_43F6E0(*(int*)&dword_5d4594_1301780, (__int16*)v13, v7 - 1, v6 + 1);
					sub_43F6E0(*(int*)&dword_5d4594_1301780, (__int16*)v13, v7 + 1, v6 - 1);
					sub_43F6E0(*(int*)&dword_5d4594_1301780, (__int16*)v13, v7 + 1, v6 + 1);
					if (*((short*)v8 + 2) <= 0)
						sub_434390(v9);
					else
						sub_434390(*(int*)&byte_5D4594[2618904]);
					sub_43F6E0(*(int*)&dword_5d4594_1301780, (__int16*)v13, v7, v6);
					v4 = v11;
				}
			} else {
				sub_49A880((int)v2);
			}
			v8 = v4;
			if (!v4)
				break;
			v2 = v4;
		}
	}
}

//----- (0049A880) --------------------------------------------------------
void __cdecl sub_49A880(int a1) {
	int v1; // ecx
	int v2; // ecx

	v1 = *(_DWORD*)(a1 + 16);
	if (v1)
		*(_DWORD*)(v1 + 12) = *(_DWORD*)(a1 + 12);
	else
		dword_5d4594_1301776 = *(_DWORD*)(a1 + 12);
	v2 = *(_DWORD*)(a1 + 12);
	if (v2)
		*(_DWORD*)(v2 + 16) = *(_DWORD*)(a1 + 16);
	sub_414330(*(unsigned int**)&nox_alloc_healthChange_1301772, (_QWORD*)a1);
}

//----- (0049A8C0) --------------------------------------------------------
int sub_49A8C0() {
	int result; // eax

	nox_free_alloc_class(*(LPVOID*)&nox_alloc_healthChange_1301772);
	result = 0;
	nox_alloc_healthChange_1301772 = 0;
	dword_5d4594_1301776 = 0;
	dword_5d4594_1301780 = 0;
	return result;
}

//----- (0049A8E0) --------------------------------------------------------
int sub_49A8E0_init() {
	nox_drawable_2d_index_size = nox_drawable_2d_index_cap;
	nox_drawable_2d_index = nox_malloc(nox_drawable_2d_index_size * sizeof(void*));
	if (!nox_drawable_2d_index)
		return 0;

	if (nox_drawable_2d_index_size <= 0)
		return 1;

	for (int i = 0; i < nox_drawable_2d_index_size; i++) {
		nox_drawable_2d_index[i] = nox_calloc(nox_drawable_2d_index_size, sizeof(void*));
		if (!nox_drawable_2d_index[i])
			return 0;
	}
	return 1;
}

//----- (0049A950) --------------------------------------------------------
int sub_49A950_free() {
	if (!nox_drawable_2d_index)
		return 1;
	for (int i = 0; i < nox_drawable_2d_index_size; i++) {
		free(nox_drawable_2d_index[i]);
	}
	free(nox_drawable_2d_index);
	nox_drawable_2d_index = 0;
	return 1;
}

//----- (0049A9B0) --------------------------------------------------------
int __cdecl sub_49A9B0_drawable(nox_drawable* dr) {
	int a1 = dr;
	int result; // eax
	int v2;     // ecx
	int v3;     // ecx

	result = a1;
	v2 = *(_DWORD*)(a1 + 404);
	if (v2)
		*(_DWORD*)(v2 + 400) = *(_DWORD*)(a1 + 400);
	else
		**(_DWORD**)(a1 + 396) = *(_DWORD*)(a1 + 400);
	v3 = *(_DWORD*)(a1 + 400);
	if (v3)
		*(_DWORD*)(v3 + 404) = *(_DWORD*)(a1 + 404);
	*(_DWORD*)(a1 + 396) = 0;
	return result;
}

//----- (0049AA00) --------------------------------------------------------
void __cdecl sub_49AA00_drawable(nox_drawable* dr) {
	int i = dr->field_3 / 128;
	int j = dr->field_4 / 128;

	if (dr->field_99)
		sub_49A9B0_drawable(dr);

	dr->field_101 = 0;

	nox_drawable* v4 = nox_drawable_2d_index[i][j];
	dr->field_100 = v4;
	if (v4)
		v4->field_101 = dr;
	nox_drawable_2d_index[i][j] = dr;

	dr->field_99 = &nox_drawable_2d_index[i][j];
}

//----- (0049AA90) --------------------------------------------------------
void __cdecl sub_49AA90(nox_drawable* dr, int a2, int a3) {
	_DWORD* a1 = dr;
	int v3; // ebx
	int v4; // ecx
	int v5; // edi
	int v6; // edx

	v3 = a2;
	v4 = a1[4];
	a1[8] = a1[3];
	a1[9] = v4;
	if (a2 < 0 || a2 >= 5888 || (v5 = a3, a3 < 0) || a3 >= 5888) {
		v3 = 50;
		v5 = 50;
		if (!(a1[30] & 0x400000))
			sub_45A110_drawable(dr);
	}
	v6 = a1[5];
	a1[3] = v3;
	a1[10] = v6;
	a1[4] = v5;
	a1[5] = *(_DWORD*)&byte_5D4594[2598000];
	sub_49AA00_drawable(dr);
}

//----- (0049AB00) --------------------------------------------------------
void __cdecl sub_49AB00(int4* a1, void(__cdecl* draw_fnc)(nox_drawable*, int), int a3) {
	if (!draw_fnc)
		return;

	int v3;  // edi
	int v4;  // esi
	int v5;  // ecx
	int v6;  // ebp
	int v8;  // [esp+10h] [ebp-10h]
	int v9;  // [esp+14h] [ebp-Ch]
	int v10; // [esp+18h] [ebp-8h]

	v3 = a1->field_0 / 128;
	v4 = a1->field_4 / 128;
	v5 = a1->field_C / 128;
	v10 = a1->field_0 / 128;
	v8 = a1->field_8 / 128;
	v9 = a1->field_C / 128;
	if (v3 < 0) {
		v10 = 0;
		v3 = 0;
	}
	if (a1->field_8 / 128 >= nox_drawable_2d_index_size)
		v8 = nox_drawable_2d_index_size - 1;
	if (v4 < 0)
		v4 = 0;
	if (v5 >= nox_drawable_2d_index_size) {
		v9 = nox_drawable_2d_index_size - 1;
		v5 = nox_drawable_2d_index_size - 1;
	}
	v6 = v4;
	if (v4 <= v5) {
		while (1) {
			if (v10 <= v8) {
				do {
					nox_drawable* cur = nox_drawable_2d_index[v3][v6];
					if (cur) {
						do {
							draw_fnc(cur, a3);
							cur = cur->field_100;
						} while (cur);
						v5 = v9;
					}
					++v3;
				} while (v3 <= v8);
			}
			if (++v6 > v5)
				break;
			v3 = v10;
		}
	}
}

//----- (0049ABF0) --------------------------------------------------------
_DWORD* __cdecl sub_49ABF0(_DWORD* a1, int a2) {
	int v2;      // ecx
	_DWORD* v3;  // edi
	int v4;      // ebx
	int v5;      // esi
	int v6;      // ebp
	int v7;      // esi
	int v8;      // eax
	int v9;      // edx
	int v10;     // ebp
	_DWORD* v11; // esi
	int v12;     // eax
	int v13;     // eax
	_DWORD* v15; // [esp+10h] [ebp-10h]
	int v16;     // [esp+14h] [ebp-Ch]
	int i;       // [esp+18h] [ebp-8h]
	int v18;     // [esp+1Ch] [ebp-4h]
	int v19;     // [esp+24h] [ebp+4h]
	int v20;     // [esp+24h] [ebp+4h]
	int v21;     // [esp+28h] [ebp+8h]

	v2 = a2;
	v3 = a1;
	v18 = a2 * a2;
	v4 = 999999999;
	v5 = *a1;
	v15 = 0;
	v16 = (*a1 - a2) / 128;
	if (v16 < 0)
		v16 = 0;
	v19 = a1[1];
	v6 = (v19 - a2) / 128;
	if (v6 < 0)
		v6 = 0;
	v7 = (v5 + a2) / 128;
	v21 = v7;
	if (v7 >= nox_drawable_2d_index_size) {
		v21 = nox_drawable_2d_index_size - 1;
		v7 = nox_drawable_2d_index_size - 1;
	}
	v8 = (v2 + v19) / 128;
	v20 = v8;
	if (v8 >= nox_drawable_2d_index_size) {
		v20 = nox_drawable_2d_index_size - 1;
		v8 = nox_drawable_2d_index_size - 1;
	}
	v9 = v6;
	for (i = v6; v9 <= v8; i = v9) {
		v10 = v16;
		if (v16 <= v7) {
			do {
				v11 = nox_drawable_2d_index[v10][v9];
				if (v11) {
					do {
						if (sub_4984B0_drawable((int)v11)) {
							v12 = v3[1] - v11[4];
							v13 = (*v3 - v11[3]) * (*v3 - v11[3]) + v12 * v12;
							if (v13 < v4 && v13 < v18) {
								v4 = v13;
								v15 = v11;
							}
						}
						v11 = (_DWORD*)v11[100];
					} while (v11);
					v8 = v20;
					v9 = i;
				}
				++v10;
			} while (v10 <= v21);
			v7 = v21;
		}
		++v9;
	}
	return v15;
}

//----- (0049AD20) --------------------------------------------------------
int __cdecl sub_49AD20(_DWORD* a1, int a2) {
	int v2;     // ecx
	int v3;     // eax
	int v4;     // ebp
	int v5;     // ecx
	int v6;     // ebx
	int v7;     // edi
	_DWORD* v8; // esi
	int result; // eax
	int v10;    // [esp+14h] [ebp+4h]

	v2 = *a1 / 128;
	v3 = a1[1] / 128;
	v4 = (v2 - 1) & ((v2 - 1 < 0) - 1);
	v5 = v2 + 1;
	if (v5 >= nox_drawable_2d_index_size - 1)
		v5 = nox_drawable_2d_index_size - 1;
	v10 = v3 + 1;
	if (v3 + 1 >= nox_drawable_2d_index_size - 1)
		v10 = nox_drawable_2d_index_size - 1;
	v6 = v3 - 1 < 0 ? 0 : v3 - 1;
	if (v6 > v10)
		return 0;
	while (1) {
		v7 = v4;
		if (v4 <= v5)
			break;
	LABEL_12:
		if (++v6 > v10)
			return 0;
	}
	v8 = &nox_drawable_2d_index[v4];
	while (1) {
		result = *(_DWORD*)(*v8 + 4 * v6);
		if (result)
			break;
	LABEL_11:
		++v7;
		++v8;
		if (v7 > v5)
			goto LABEL_12;
	}
	while (*(_DWORD*)(result + 128) != a2) {
		result = *(_DWORD*)(result + 400);
		if (!result)
			goto LABEL_11;
	}
	return result;
}

//----- (0049ADD0) --------------------------------------------------------
int __cdecl sub_49ADD0(int a1) {
	_DWORD* v2; // eax
	int v3;     // ecx

	nox_alloc_pixelSpan_1301844 = 0;
	dword_5d4594_1301848 = 0;
	dword_5d4594_1301824 = 0;
	dword_5d4594_1301832 = 0;
	dword_5d4594_1301800 = 0;
	dword_5d4594_1301828 = 0;
	dword_5d4594_1301840 = 0;
	dword_5d4594_1301792 = 0;
	dword_5d4594_1301836 = 0;
	dword_5d4594_1301812 = 0;
	*(_DWORD*)&byte_5D4594[1301804] = 0;
	dword_5d4594_1301816 = 0;
	dword_5d4594_1301808 = 0;
	dword_5d4594_1301796 = 0;
	*(_DWORD*)&byte_5D4594[1301820] = a1;
	nox_alloc_pixelSpan_1301844 = nox_new_alloc_class("PixelSpan", 12, a1);
	if (!nox_alloc_pixelSpan_1301844)
		return 0;
	dword_5d4594_1301824 = nox_win_height;
	v2 = nox_malloc(4 * nox_win_height);
	dword_5d4594_1301848 = v2;
	if (!v2)
		return 0;
	v3 = 0;
	if (dword_5d4594_1301824 > 0) {
		while (1) {
			v2[v3++] = 0;
			if (v3 >= *(int*)&dword_5d4594_1301824)
				break;
			v2 = *(_DWORD**)&dword_5d4594_1301848;
		}
	}
	return 1;
}

//----- (0049AEA0) --------------------------------------------------------
int sub_49AEA0() {
	if (nox_alloc_pixelSpan_1301844) {
		nox_free_alloc_class(*(LPVOID*)&nox_alloc_pixelSpan_1301844);
		nox_alloc_pixelSpan_1301844 = 0;
	}
	if (dword_5d4594_1301848) {
		free(*(LPVOID*)&dword_5d4594_1301848);
		dword_5d4594_1301848 = 0;
	}
	return 1;
}

//----- (0049AEE0) --------------------------------------------------------
void sub_49AEE0() {
	int v0;          // edx
	unsigned int v1; // ecx
	int v2;          // eax

	v0 = 0;
	dword_5d4594_1301792 = 0;
	dword_5d4594_1301812 = 0;
	dword_5d4594_1301816 = 0;
	dword_5d4594_1301796 = 0;
	if (dword_5d4594_1301824 > 0) {
		do {
			v1 = 0;
			dword_5d4594_1301808 = 0;
			v2 = *(_DWORD*)(dword_5d4594_1301848 + 4 * v0);
			if (v2) {
				do {
					dword_5d4594_1301808 = ++v1;
					v2 = *(_DWORD*)(v2 + 8);
				} while (v2);
				if (v1 > *(int*)&dword_5d4594_1301816) {
					dword_5d4594_1301816 = v1;
					dword_5d4594_1301796 = v0;
				}
			}
			++v0;
			dword_5d4594_1301812 += v1;
			*(_DWORD*)(dword_5d4594_1301848 + 4 * v0 - 4) = 0;
		} while (v0 < *(int*)&dword_5d4594_1301824);
		if (dword_5d4594_1301812 > *(int*)&byte_5D4594[1301804])
			*(_DWORD*)&byte_5D4594[1301804] = dword_5d4594_1301812;
	}
	sub_4144D0(*(_DWORD**)&nox_alloc_pixelSpan_1301844);
}

//----- (0049AF80) --------------------------------------------------------
int* __cdecl sub_49AF80(int a1, int a2, int a3) {
	int* result; // eax
	int v4;      // edx
	int* v5;     // esi

	dword_5d4594_1301836 = a1;
	if (*(_DWORD*)(dword_5d4594_1301848 + 4 * a1)) {
		result = *(int**)&dword_5d4594_1301800;
		if (dword_5d4594_1301832) {
			if (dword_5d4594_1301832 != dword_5d4594_1301800) {
				if (dword_5d4594_1301800)
					v4 = *(_DWORD*)(dword_5d4594_1301800 + 4);
				else
					v4 = a3;
				*(_DWORD*)(dword_5d4594_1301832 + 4) = v4;
				result = (int*)sub_49B1D0(*(int*)&dword_5d4594_1301832, *(int*)&dword_5d4594_1301840);
			}
		} else if (dword_5d4594_1301800) {
			**(_DWORD**)&dword_5d4594_1301800 = a2;
			result = (int*)sub_49B1D0(*(int*)&dword_5d4594_1301828, *(int*)&dword_5d4594_1301800);
		} else {
			result = (int*)nox_alloc_class_new_obj(nox_alloc_pixelSpan_1301844);
			v5 = result;
			if (result) {
				*result = a2;
				result[1] = a3;
				sub_49B1D0(*(int*)&dword_5d4594_1301828, *(int*)&dword_5d4594_1301840);
				result = *(int**)&dword_5d4594_1301828;
				if (dword_5d4594_1301828) {
					*(_DWORD*)(dword_5d4594_1301828 + 8) = v5;
				} else {
					result = *(int**)&dword_5d4594_1301848;
					*(_DWORD*)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836) = v5;
				}
				v5[2] = dword_5d4594_1301840;
			}
		}
	} else {
		result = (int*)nox_alloc_class_new_obj(nox_alloc_pixelSpan_1301844);
		if (result) {
			*result = a2;
			result[1] = a3;
			result[2] = 0;
			*(_DWORD*)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836) = result;
		}
	}
	return result;
}

//----- (0049B0A0) --------------------------------------------------------
int __cdecl sub_49B0A0(int a1, int a2, int a3) {
	int* v3; // eax
	int* v5; // ecx
	int* v6; // eax

	if (dword_5d4594_1301792) {
		sub_49B1A0(*(int*)&dword_5d4594_1301792);
		dword_5d4594_1301792 = 0;
	}
	dword_5d4594_1301836 = a1;
	v3 = (int*)nox_alloc_class_new_obj(nox_alloc_pixelSpan_1301844);
	dword_5d4594_1301792 = v3;
	if (!v3)
		return 0;
	*v3 = a2;
	*(_DWORD*)(dword_5d4594_1301792 + 4) = a3;
	v5 = 0;
	*(_DWORD*)(dword_5d4594_1301792 + 8) = 0;
	dword_5d4594_1301832 = 0;
	dword_5d4594_1301828 = 0;
	v6 = *(int**)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836);
	if (!v6)
		goto LABEL_22;
	do {
		if (*v6 > a2)
			break;
		if (v6[1] + 1 >= a2) {
			dword_5d4594_1301832 = v6;
			goto LABEL_13;
		}
		v5 = v6;
		dword_5d4594_1301828 = v6;
		v6 = (int*)v6[2];
	} while (v6);
	v6 = v5;
	if (!v5)
	LABEL_22:
		v6 = *(int**)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836);
LABEL_13:
	dword_5d4594_1301800 = 0;
	dword_5d4594_1301840 = 0;
	if (v6) {
		while (*v6 - 1 <= a3) {
			if (v6[1] >= a3) {
				dword_5d4594_1301800 = v6;
				v6 = (int*)v6[2];
				break;
			}
			v6 = (int*)v6[2];
			if (!v6) {
				dword_5d4594_1301840 = 0;
				return sub_49B260();
			}
		}
	}
	dword_5d4594_1301840 = v6;
	return sub_49B260();
}

//----- (0049B1A0) --------------------------------------------------------
int __cdecl sub_49B1A0(int a1) {
	int result; // eax
	int v2;     // esi

	result = a1;
	if (a1) {
		do {
			v2 = *(_DWORD*)(result + 8);
			sub_414330(*(unsigned int**)&nox_alloc_pixelSpan_1301844, (_QWORD*)result);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (0049B1D0) --------------------------------------------------------
int __cdecl sub_49B1D0(int a1, int a2) {
	int* v2;    // ecx
	int result; // eax

	if (a1) {
		for (result = *(_DWORD*)(a1 + 8); result; result = *(_DWORD*)(a1 + 8)) {
			if (result == a2)
				break;
			*(_DWORD*)(a1 + 8) = *(_DWORD*)(result + 8);
			sub_414330(*(unsigned int**)&nox_alloc_pixelSpan_1301844, (_QWORD*)result);
		}
	} else {
		v2 = (int*)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836);
		for (result = *v2; result; v2 = (int*)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836)) {
			if (result == a2)
				break;
			*v2 = *(_DWORD*)(result + 8);
			sub_414330(*(unsigned int**)&nox_alloc_pixelSpan_1301844, (_QWORD*)result);
			result = *(_DWORD*)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836);
		}
	}
	return result;
}

//----- (0049B260) --------------------------------------------------------
int sub_49B260() {
	int* v0; // edi
	int* v1; // ebx
	int* v3; // esi
	int v4;  // ebp
	int* v5; // eax
	int v6;  // edx

	if (dword_5d4594_1301832) {
		if (dword_5d4594_1301832 == dword_5d4594_1301800)
			return 0;
		**(_DWORD**)&dword_5d4594_1301792 = *(_DWORD*)(dword_5d4594_1301832 + 4) + 1;
		v0 = *(int**)(dword_5d4594_1301832 + 8);
		if (dword_5d4594_1301800) {
			*(_DWORD*)(dword_5d4594_1301792 + 4) = **(_DWORD**)&dword_5d4594_1301800 - 1;
			v1 = *(int**)&dword_5d4594_1301800;
			goto LABEL_11;
		}
	LABEL_10:
		v1 = *(int**)&dword_5d4594_1301840;
		goto LABEL_11;
	}
	v0 = *(int**)&dword_5d4594_1301828;
	if (!dword_5d4594_1301828)
		v0 = *(int**)(dword_5d4594_1301848 + 4 * dword_5d4594_1301836);
	if (!dword_5d4594_1301800)
		goto LABEL_10;
	*(_DWORD*)(dword_5d4594_1301792 + 4) = **(_DWORD**)&dword_5d4594_1301800 - 1;
	v1 = *(int**)&dword_5d4594_1301800;
LABEL_11:
	v3 = *(int**)&dword_5d4594_1301792;
	v4 = *(_DWORD*)(dword_5d4594_1301792 + 4);
	if (v0 != v1) {
		while (*v0 <= v4) {
			if (*v0 >= *v3) {
				v5 = (int*)nox_alloc_class_new_obj(nox_alloc_pixelSpan_1301844);
				if (!v5) {
					sub_49B1A0(*(int*)&dword_5d4594_1301792);
					dword_5d4594_1301792 = 0;
					return 0;
				}
				*v5 = v0[1] + 1;
				v5[1] = v3[1];
				v5[2] = 0;
				v6 = *v0;
				v3[2] = (int)v5;
				v3[1] = v6 - 1;
				v3 = v5;
			}
			v0 = (int*)v0[2];
			if (v0 == v1)
				return dword_5d4594_1301792;
		}
	}
	return dword_5d4594_1301792;
}

//----- (0049B370) --------------------------------------------------------
int sub_49B370() { return dword_5d4594_1301796; }

//----- (0049B380) --------------------------------------------------------
int sub_49B380() { return dword_5d4594_1301816; }

//----- (0049B3A0) --------------------------------------------------------
int sub_49B3A0() { return dword_5d4594_1301812; }

//----- (0049B3B0) --------------------------------------------------------
int sub_49B3B0() { return *(_DWORD*)&byte_5D4594[1301820]; }

//----- (0049B3C0) --------------------------------------------------------
int sub_49B3C0() {
	int result; // eax

	result = 0;
	dword_5d4594_1301812 = 0;
	dword_5d4594_1301816 = 0;
	dword_5d4594_1301808 = 0;
	dword_5d4594_1301796 = 0;
	return result;
}

//----- (0049B3E0) --------------------------------------------------------
int sub_49B3E0() {
	int result; // eax

	result = nox_new_window_from_file("GGOver.wnd", sub_49B420);
	dword_5d4594_1303452 = result;
	if (result) {
		nox_window_set_hidden(result, 1);
		sub_46ABB0(*(int*)&dword_5d4594_1303452, 0);
		result = 1;
	}
	return result;
}

//----- (0049B420) --------------------------------------------------------
int __cdecl sub_49B420(int a1, int a2, int* a3, int a4) {
	int v3; // esi

	if (a2 == 16391) {
		v3 = sub_46B0A0(a3);
		sub_452D80(766, 100);
		if (v3 == 10701) {
			sub_4460C0();
			sub_49B6B0();
		} else if (v3 == 10702) {
			LOWORD(a2) = 1008;
			sub_4E53C0(31, &a2, 2, 0, 1);
			sub_49B6B0();
			return 0;
		}
	}
	return 0;
}

//----- (0049B490) --------------------------------------------------------
int sub_49B490() {
	int result; // eax

	result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1303452);
	dword_5d4594_1303452 = 0;
	return result;
}

//----- (0049B6B0) --------------------------------------------------------
int sub_49B6B0() {
	nox_window_set_hidden(*(int*)&dword_5d4594_1303452, 1);
	sub_46ABB0(*(int*)&dword_5d4594_1303452, 0);
	return sub_46B500(0);
}

//----- (0049B7A0) --------------------------------------------------------
void sub_49B7A0() {
	int v0; // esi

	v0 = 0;
	if (!sub_477600() && !sub_44E0D0()) {
		if (sub_460660())
			v0 = 1;
		if (!sub_46A6A0() && v0 != 1) {
			if (sub_45D9B0() == 1) {
				sub_45D870();
			} else {
				if (sub_4BFE40())
					v0 = 1;
				if (sub_4606B0())
					v0 = 1;
				if (sub_462740())
					v0 = 1;
				if (!sub_44A4E0() && v0 != 1) {
					if (sub_479590() == 2) {
						sub_4795A0(1);
					} else if (sub_479590() == 3) {
						sub_4795A0(1);
					} else if (sub_479590() == 4) {
						sub_4795A0(1);
					} else if (!sub_478040() && !sub_479950()) {
						if (sub_467C10())
							v0 = 1;
						if (sub_45ACA0(0))
							v0 = 1;
						if (sub_4512B0())
							v0 = 1;
						if (sub_446780())
							v0 = 1;
						if (sub_4574D0())
							v0 = 1;
						if (sub_48CAD0())
							v0 = 1;
						if (sub_4AD9B0(1))
							v0 = 1;
						if (sub_4C35B0(1))
							v0 = 1;
						if (!sub_46D6F0() && v0 != 1) {
							if (sub_4DCCB0())
								sub_445C40();
							else
								sub_452D80(231, 100);
						}
					}
				}
			}
		}
	}
}
// 49B874: variable 'v1' is possibly undefined
// 49B881: variable 'v2' is possibly undefined

//----- (0049B950) --------------------------------------------------------
_DWORD* __cdecl sub_49B950(_DWORD* a1, int a2) {
	unsigned int v2; // edx
	_DWORD* result;  // eax
	_DWORD* v4;      // ecx
	int v5;          // ecx

	if (a1[89])
		sub_49BA10(a1);
	v2 = *(_DWORD*)&byte_5D4594[2598000] + a2;
	a1[89] = *(_DWORD*)&byte_5D4594[2598000] + a2;
	result = *(_DWORD**)&dword_5d4594_1303468;
	if (dword_5d4594_1303468) {
		v4 = 0;
		while (result[89] < v2) {
			v4 = result;
			result = (_DWORD*)result[87];
			if (!result)
				goto LABEL_10;
		}
		if (!result) {
		LABEL_10:
			v4[87] = a1;
			a1[87] = 0;
			a1[88] = v4;
			return result;
		}
		a1[87] = result;
		a1[88] = result[88];
		v5 = result[88];
		if (v5)
			*(_DWORD*)(v5 + 348) = a1;
		else
			dword_5d4594_1303468 = a1;
		result[88] = a1;
	} else {
		a1[87] = dword_5d4594_1303468;
		a1[88] = result;
		dword_5d4594_1303468 = a1;
	}
	return result;
}

//----- (0049BA10) --------------------------------------------------------
_DWORD* __cdecl sub_49BA10(nox_drawable* dr) {
	_DWORD* a1 = dr;
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx

	result = a1;
	if (a1[89]) {
		v2 = a1[88];
		if (v2)
			*(_DWORD*)(v2 + 348) = a1[87];
		else
			dword_5d4594_1303468 = a1[87];
		v3 = a1[87];
		if (v3)
			*(_DWORD*)(v3 + 352) = a1[88];
		a1[89] = 0;
	}
	return result;
}

//----- (0049BA70) --------------------------------------------------------
int sub_49BA70() {
	int result; // eax
	int v1;     // esi

	result = dword_5d4594_1303468;
	if (dword_5d4594_1303468) {
		do {
			v1 = *(_DWORD*)(result + 348);
			if (*(_DWORD*)(result + 356) > *(int*)&byte_5D4594[2598000])
				break;
			sub_45A4E0_drawable(result);
			result = v1;
		} while (v1);
	}
	return result;
}

//----- (0049BAB0) --------------------------------------------------------
_DWORD* __cdecl sub_49BAB0_drawable(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	a1[84] = 0;
	a1[83] = dword_5d4594_1303472;
	if (dword_5d4594_1303472)
		*(_DWORD*)(dword_5d4594_1303472 + 336) = a1;
	dword_5d4594_1303472 = a1;
	a1[30] |= 0x200000u;
	return result;
}

//----- (0049BAF0) --------------------------------------------------------
_DWORD* __cdecl sub_49BAF0(nox_drawable* dr) {
	_DWORD* a1 = dr;
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx

	result = a1;
	if (a1[30] & 0x200000) {
		v2 = a1[84];
		if (v2)
			*(_DWORD*)(v2 + 332) = a1[83];
		else
			dword_5d4594_1303472 = a1[83];
		v3 = a1[83];
		if (v3)
			*(_DWORD*)(v3 + 336) = a1[84];
		a1[30] &= 0xFFDFFFFF;
	}
	return result;
}

//----- (0049BB40) --------------------------------------------------------
void sub_49BB40() {
	int v0; // esi
	int v1; // edi

	v0 = dword_5d4594_1303472;
	if (dword_5d4594_1303472) {
		do {
			v1 = *(_DWORD*)(v0 + 332);
			if (*(_DWORD*)(v0 + 340) < (unsigned int)sub_435590())
				sub_45A4E0_drawable(v0);
			v0 = v1;
		} while (v1);
	}
}

//----- (0049BB80) --------------------------------------------------------
void* __cdecl sub_49BB80(char a1) {
	void* result; // eax

	byte_5D4594[1303504] = a1;
	byte_5D4594[1303512] = 0;
	*(_DWORD*)&byte_5D4594[1303516] = *(_DWORD*)&byte_5D4594[2598000];
	result = sub_424820();
	dword_5d4594_1303508 = result;
	return result;
}

//----- (0049BBB0) --------------------------------------------------------
void sub_49BBB0() { byte_5D4594[1303504] = 0; }

//----- (0049BBC0) --------------------------------------------------------
void sub_49BBC0() {
	int v0;             // eax
	unsigned __int8 v1; // [esp+0h] [ebp-4h]

	if (byte_5D4594[1303504]) {
		v1 = sub_424A20(byte_5D4594[1303504])[byte_5D4594[1303512]];
		if (*(_DWORD*)&byte_5D4594[2598000] >= *(int*)&byte_5D4594[1303516]) {
			v0 = sub_4FE1C0(*(int*)&byte_5D4594[2616328], v1);
			sub_452D80(v0, 100);
			sub_476E00(*(_DWORD*)&byte_587000[4 * v1 + 163576]);
			*(_DWORD*)&byte_5D4594[1303516] = *(_DWORD*)&byte_5D4594[2598000] + 3;
			dword_5d4594_1303508 = sub_424830(*(int*)&dword_5d4594_1303508, v1);
			++byte_5D4594[1303512];
		}
		if (**(_DWORD**)&dword_5d4594_1303508 == byte_5D4594[1303504])
			sub_49BBB0();
	}
}

//----- (0049BC80) --------------------------------------------------------
_DWORD* __cdecl sub_49BC80_drawable(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	if (!a1[96]) {
		a1[95] = 0;
		a1[94] = dword_5d4594_1303536;
		if (dword_5d4594_1303536)
			*(_DWORD*)(dword_5d4594_1303536 + 380) = a1;
		dword_5d4594_1303536 = a1;
		a1[96] = 1;
	}
	return result;
}

//----- (0049BCD0) --------------------------------------------------------
_DWORD* __cdecl sub_49BCD0(nox_drawable* dr) {
	_DWORD* a1 = dr;
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx
	int v4;         // ecx

	result = a1;
	if (a1[96]) {
		v2 = a1[95];
		if (v2) {
			*(_DWORD*)(v2 + 376) = a1[94];
			v3 = a1[94];
			if (v3) {
				*(_DWORD*)(v3 + 380) = a1[95];
				a1[96] = 0;
				return result;
			}
		} else {
			dword_5d4594_1303536 = a1[94];
			v4 = a1[94];
			if (v4)
				*(_DWORD*)(v4 + 380) = 0;
		}
		a1[96] = 0;
	}
	return result;
}

//----- (0049BD40) --------------------------------------------------------
int sub_49BD40() { return dword_5d4594_1303536; }

//----- (0049BD50) --------------------------------------------------------
int __cdecl sub_49BD50(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 376);
	else
		result = 0;
	return result;
}

//----- (0049BD70) --------------------------------------------------------
int(__cdecl* __cdecl sub_49BD70(int a1))(int, int) {
	int result;                       // eax
	int(__cdecl * result2)(int, int); // eax
	int v2;                           // esi
	int v3;                           // edi
	int(__cdecl * v4)(int, _DWORD);   // eax

	result = sub_413A50();
	if (result != 1) {
		result = sub_49BD40();
		v2 = result;
		if (result) {
			do {
				v3 = sub_49BD50(v2);
				v4 = (int(__cdecl*)(int, _DWORD)) * ((_DWORD*)v2 + 116);
				if (!v4 || (result = v4(a1, v2)) != 0) {
					result2 = (int(__cdecl*)(int, int)) * ((_DWORD*)v2 + 115);
					if (result2)
						result = result2(a1, (int)v2);
					else
						result = 0;
				}
				v2 = v3;
			} while (v3);
		}
	}
	return result;
}

//----- (0049C160) --------------------------------------------------------
_DWORD* __cdecl sub_49C160(int a1) {
	_DWORD* result;       // eax
	int v2;               // eax
	int v3;               // esi
	int v4;               // eax
	int v5;               // ebx
	_DWORD* v6;           // eax
	_DWORD* v7;           // edi
	int v8;               // esi
	int v9;               // edi
	int v10;              // kr00_4
	int v11;              // ecx
	int v12;              // edx
	int v13;              // edx
	unsigned __int8* v14; // ecx

	result = *(_DWORD**)&byte_5D4594[1304312];
	if (*(int*)&byte_5D4594[1304312] < 96) {
		if (!*(_DWORD*)&byte_5D4594[1304352]) {
			*(_DWORD*)&byte_5D4594[1304352] = sub_44CFC0((CHAR*)&byte_587000[164344]);
			*(_DWORD*)&byte_5D4594[1304356] = sub_44CFC0((CHAR*)&byte_587000[164364]);
			*(_DWORD*)&byte_5D4594[1304360] = sub_44CFC0((CHAR*)&byte_587000[164388]);
			*(_DWORD*)&byte_5D4594[1304364] = sub_44CFC0((CHAR*)&byte_587000[164408]);
			*(_DWORD*)&byte_5D4594[1304368] = sub_44CFC0((CHAR*)&byte_587000[164416]);
			*(_DWORD*)&byte_5D4594[1304372] = sub_44CFC0((CHAR*)&byte_587000[164428]);
			*(_DWORD*)&byte_5D4594[1304376] = sub_44CFC0((CHAR*)&byte_587000[164444]);
			*(_DWORD*)&byte_5D4594[1304380] = sub_44CFC0((CHAR*)&byte_587000[164452]);
			*(_DWORD*)&byte_5D4594[1304384] = sub_44CFC0((CHAR*)&byte_587000[164464]);
			*(_DWORD*)&byte_5D4594[1304388] = sub_44CFC0((CHAR*)&byte_587000[164480]);
			*(_DWORD*)&byte_5D4594[1304392] = sub_44CFC0((CHAR*)&byte_587000[164488]);
			*(_DWORD*)&byte_5D4594[1304396] = sub_44CFC0((CHAR*)&byte_587000[164500]);
		}
		v2 = sub_578B30(*(_WORD*)(a1 + 3));
		v3 = v2;
		v4 = sub_578B30(*(_WORD*)(a1 + 5));
		v5 = v4;
		v6 = sub_578B70(*(unsigned __int16*)(a1 + 3)) ? sub_45A720(v3) : sub_45A6F0(v3);
		v7 = v6;
		result = sub_578B70(*(unsigned __int16*)(a1 + 5)) ? sub_45A720(v5) : sub_45A6F0(v5);
		if (v7 && result) {
			v8 = v7[3];
			v9 = v7[4];
			v10 = result[4] - v9;
			v11 = v8 + ((int)result[3] - v8) / 2;
			result = (_DWORD*)(v9 + v10 / 2);
			switch (*(unsigned __int8*)(a1 + 1)) {
			case 1u:
				v12 = *(_DWORD*)&byte_5D4594[1304368];
				goto LABEL_21;
			case 2u:
				v12 = *(_DWORD*)&byte_5D4594[1304380];
				goto LABEL_21;
			case 3u:
				v12 = *(_DWORD*)&byte_5D4594[1304356];
				goto LABEL_21;
			case 4u:
				v12 = *(_DWORD*)&byte_5D4594[1304360];
				goto LABEL_21;
			case 5u:
				v12 = *(_DWORD*)&byte_5D4594[1304372];
				goto LABEL_21;
			case 6u:
				v12 = *(_DWORD*)&byte_5D4594[1304376];
				goto LABEL_21;
			case 7u:
				v12 = *(_DWORD*)&byte_5D4594[1304396];
				goto LABEL_21;
			case 0x8Cu:
				v12 = *(_DWORD*)&byte_5D4594[1304352];
			LABEL_21:
				result = (_DWORD*)sub_45A360_drawable(v12, v11, v9 + v10 / 2);
				if (!result)
					return result;
				*((_BYTE*)result + 432) = 1;
				*(_DWORD*)((char*)result + 437) = *(unsigned __int16*)(a1 + 3);
				*(_DWORD*)((char*)result + 441) = *(unsigned __int16*)(a1 + 5);
				v13 = 0;
				*(_DWORD*)((char*)result + 433) = *(unsigned __int8*)(a1 + 2);
				v14 = &byte_5D4594[1303924];
				break;
			default:
				return result;
			}
			while (*(_DWORD*)v14) {
				v14 += 4;
				++v13;
				if ((int)v14 >= (int)&byte_5D4594[1304308])
					return result;
			}
			*(_DWORD*)&byte_5D4594[4 * v13 + 1303924] = result;
		}
	}
	return result;
}
// 49C248: variable 'v2' is possibly undefined
// 49C256: variable 'v4' is possibly undefined

//----- (0049C450) --------------------------------------------------------
void __cdecl sub_49C450(int a1) {
	int v1;  // esi
	int* v2; // ecx

	v1 = 0;
	v2 = (int*)&byte_5D4594[1303924];
	while (1) {
		int result = *v2;
		if (*v2) {
			if (*(unsigned __int16*)(a1 + 3) == *(_DWORD*)(result + 437) &&
				*(unsigned __int16*)(a1 + 5) == *(_DWORD*)(result + 441)) {
				break;
			}
		}
		++v2;
		++v1;
		if ((int)v2 >= (int)&byte_5D4594[1304308])
			return;
	}
	sub_45A4E0_drawable(*v2);
	*(_DWORD*)&byte_5D4594[4 * v1 + 1303924] = 0;
}

//----- (0049C4B0) --------------------------------------------------------
void sub_49C4B0() {
	int v0;  // esi
	int* v1; // edi

	v0 = 0;
	if (*(_DWORD*)&byte_5D4594[1304308] > 0) {
		v1 = (int*)&byte_5D4594[1303540];
		do {
			sub_45A4E0_drawable(*v1);
			++v0;
			++v1;
		} while (v0 < *(int*)&byte_5D4594[1304308]);
	}
	*(_DWORD*)&byte_5D4594[1304308] = 0;
	sub_4C5050();
}

//----- (0049C4F0) --------------------------------------------------------
void sub_49C4F0() {
	int* v0 = (int*)&byte_5D4594[1303924];
	do {
		if (*v0) {
			sub_45A4E0_drawable(*v0);
			*v0 = 0;
		}
		++v0;
	} while ((int)v0 < (int)&byte_5D4594[1304308]);
}

//----- (0049C520) --------------------------------------------------------
int __cdecl sub_49C520(int a1) {
	unsigned __int8* v1; // eax
	int v2;              // eax
	unsigned __int8* i;  // ecx

	v1 = &byte_5D4594[1303924];
	while (a1 != *(_DWORD*)v1) {
		v1 += 4;
		if ((int)v1 >= (int)&byte_5D4594[1304308]) {
			v2 = 0;
			if (*(int*)&byte_5D4594[1304308] <= 0)
				return 0;
			for (i = &byte_5D4594[1303540]; a1 != *(_DWORD*)i; i += 4) {
				if (++v2 >= *(int*)&byte_5D4594[1304308])
					return 0;
			}
			return 1;
		}
	}
	return 1;
}

//----- (0049C760) --------------------------------------------------------
int __cdecl sub_49C760(int a1, int a2, int* a3, int a4) {
	int v3; // esi

	if (a2 == 16391) {
		v3 = sub_46B0A0(a3);
		sub_452D80(766, 100);
		if (v3 == 4103)
			sub_49C7A0();
	}
	return 1;
}

//----- (0049C7A0) --------------------------------------------------------
int sub_49C7A0() {
	int result; // eax

	result = dword_5d4594_1305680;
	if (dword_5d4594_1305680) {
		nox_server_sanctuaryHelp_54276 = ((unsigned int)~sub_46B0C0(*(_DWORD**)&dword_5d4594_1305680, 4104)[9] >> 2) & 1;
		sub_46C6E0(*(int*)&dword_5d4594_1305680);
		sub_46ADE0(*(int*)&dword_5d4594_1305680);
		sub_46C4E0(*(_DWORD**)&dword_5d4594_1305680);
		dword_5d4594_1305680 = 0;
		sub_46B500(0);
		result = nox_common_gameFlags_check_40A5C0(1);
		if (result)
			result = sub_459D80(0);
	}
	return result;
}

//----- (0049C810) --------------------------------------------------------
BOOL sub_49C810() { return dword_5d4594_1305680 != 0; }

//----- (0049CA60) --------------------------------------------------------
int __cdecl sub_49CA60(int a1, int a2, int* a3, int a4) {
	int v3;     // esi
	_DWORD* v4; // eax
	int v5;     // eax
	int v6;     // eax

	if (a2 == 16391) {
		v3 = sub_46B0A0(a3);
		sub_452D80(766, 100);
		if (v3 == 10353) {
			sub_46C6E0(*(int*)&dword_5d4594_1305684);
			sub_46ADE0(*(int*)&dword_5d4594_1305684);
			if (nox_common_gameFlags_check_40A5C0(128) && nox_server_sanctuaryHelp_54276)
				sub_49C560();
			else
				sub_459D80(0);
			v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1305684, 10352);
			v5 = nox_window_call_field_94((int)v4, 16404, 0, 0);
			nox_server_connectionType_3596 = v5 + 1;
			v6 = sub_40A710(v5 + 1);
			sub_40A6D0(v6);
			sub_46C4E0(*(_DWORD**)&dword_5d4594_1305684);
			dword_5d4594_1305684 = 0;
			sub_46B500(0);
		}
	}
	return 1;
}

//----- (0049CB40) --------------------------------------------------------
BOOL sub_49CB40() { return dword_5d4594_1305684 != 0; }

//----- (0049CB50) --------------------------------------------------------
int nox_video_initRectDrawingFuncs_49CB50() {
	if (!dword_5d4594_3801780) {
		*(_DWORD*)&byte_5D4594[1305704] = sub_49D1E0;
		dword_5d4594_1305712 = sub_49D680;
		dword_5d4594_1305720 = sub_49D880;            // seems to be unused
		dword_5d4594_1305700 = sub_49DA90;            // seems to be unused
		dword_5d4594_1305716 = sub_49DB20;            // opaque filled
		func_5D4594_1305696 = sub_49DD60; // string size
		func_5D4594_1305708 = sub_49E380; // cursor?
		return 1;
	}
	if (dword_5d4594_3801780 != 1)
		return 1;
	*(_DWORD*)&byte_5D4594[1305704] = sub_49D270; // alpha filled
	if (dword_5d4594_3801804) {
		*(_DWORD*)&byte_5D4594[1305692] = sub_49D540;
		dword_5d4594_1305712 = sub_49D770;
		dword_5d4594_1305720 = sub_49D770;
		dword_5d4594_1305700 = sub_49D9A0;
		dword_5d4594_1305716 = sub_49DC70;
	} else {
		*(_DWORD*)&byte_5D4594[1305692] = sub_49D370;
		dword_5d4594_1305712 = sub_49D6F0;
		dword_5d4594_1305720 = sub_49D6F0;
		dword_5d4594_1305700 = sub_49D8E0;
		dword_5d4594_1305716 = sub_49DBB0;
	}
	func_5D4594_1305696 = sub_49E060; // string size
	func_5D4594_1305708 = sub_49E3C0; // cursor?
	return 1;
}

//----- (0049CC70) --------------------------------------------------------
void __cdecl nox_client_drawBorderLines_49CC70(int xLeft, int yTop, int a3, int a4) {
	int v4;  // ebx
	int v5;  // ebp
	RECT rc; // [esp+10h] [ebp-10h]

	if (a3) {
		if (a4) {
			if (!ptr_5D4594_3799572->data[0] ||
				(SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4),
				 sub_49F930((int4*)&rc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[1])))) {
				v4 = xLeft + a3 - 1;
				(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(xLeft, yTop, v4);
				v5 = yTop + a4 - 1;
				(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798712)(v4, yTop + 1, v5);
				(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(xLeft, v5, xLeft + a3 - 2);
				(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798712)(xLeft, yTop + 1, yTop + a4 - 2);
			}
		}
	}
}

// Most probably borders with alpha
//----- (0049CD30) --------------------------------------------------------
void __cdecl sub_49CD30(int xLeft, int yTop, int a3, int a4, int a5, int a6) {
	RECT rc; // [esp+10h] [ebp-10h]

	if (a3) {
		if (a4) {
			if (!ptr_5D4594_3799572->data[0] ||
				(SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4),
				 sub_49F930((int4*)&rc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[1])))) {
				sub_434040(a5);
				sub_434080(a6);
				nox_client_drawAddPoint_49F500(xLeft, yTop);
				nox_client_drawAddPoint_49F500(xLeft + a3 - 1, yTop);
				sub_49E4F0(64);
				nox_client_drawAddPoint_49F500(xLeft + a3, yTop);
				nox_client_drawAddPoint_49F500(xLeft + a3, yTop + a4 - 1);
				sub_49E4F0(64);
				nox_client_drawAddPoint_49F500(xLeft + a3, yTop + a4);
				nox_client_drawAddPoint_49F500(xLeft, yTop + a4);
				sub_49E4F0(64);
				nox_client_drawAddPoint_49F500(xLeft, yTop + a4 - 1);
				nox_client_drawAddPoint_49F500(xLeft, yTop + 1);
				sub_49E4F0(64);
			}
		}
	}
}

//----- (0049CE30) --------------------------------------------------------
void __cdecl nox_client_drawRectFilledOpaque_49CE30(int xLeft, int yTop, int a3, int a4) {
	int v4; // ecx
	int v5; // eax
	obj_5D4594_3799572_t* v6;
	int v7;  // edx
	LONG v8; // esi
	int v9;  // esi
	RECT rc; // [esp+8h] [ebp-10h]

	v4 = a3;
	if (a3) {
		v5 = a4;
		if (a4) {
			v6 = ptr_5D4594_3799572;
			v7 = yTop;
			if (ptr_5D4594_3799572->data[0]) {
				SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
				if (!sub_49F930((int4*)&rc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[1])))
					return;
				v7 = rc.top;
				v6 = ptr_5D4594_3799572;
				v8 = rc.left;
				v4 = rc.right - rc.left;
				v5 = rc.bottom - rc.top;
			} else {
				v8 = xLeft;
			}
			if (v8 || v7 || v4 != nox_backbuffer_width || v5 != nox_backbuffer_height) {
				(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305704])(v8, v7, v4, v5);
			} else {
				v9 = v6->data[58];
				v6->data[58] = v6->data[61];
				sub_440900();
				ptr_5D4594_3799572->data[58] = v9;
			}
		}
	}
}

//----- (0049CF10) --------------------------------------------------------
int4* __cdecl nox_client_drawRectFilledAlpha_49CF10(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rc;      // [esp+4h] [ebp-10h]

	if (!ptr_5D4594_3799572->data[0])
		return (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) & dword_5d4594_1305712)(xLeft, yTop, a3, a4);
	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = sub_49F930((int4*)&rc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[1]));
	if (result)
		result = (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) &
						 dword_5d4594_1305712)(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
	return result;
}

// unused
//----- (0049CFB0) --------------------------------------------------------
int4* __cdecl sub_49CFB0(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rc;      // [esp+4h] [ebp-10h]

	if (!ptr_5D4594_3799572->data[0])
		return (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) & dword_5d4594_1305720)(xLeft, yTop, a3, a4);
	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = sub_49F930((int4*)&rc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[1]));
	if (result)
		result = (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) &
						 dword_5d4594_1305720)(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
	return result;
}

// black screen
//----- (0049D050) --------------------------------------------------------
int4* __cdecl sub_49D050(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rc;      // [esp+4h] [ebp-10h]

	if (!ptr_5D4594_3799572->data[0])
		return (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) & dword_5d4594_1305700)(xLeft, yTop, a3, a4);
	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = sub_49F930((int4*)&rc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[1]));
	if (result)
		result = (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) &
						 dword_5d4594_1305700)(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
	return result;
}

// black screen fade-in/out
//----- (0049D0F0) --------------------------------------------------------
int4* __cdecl nox_client_drawRectFadingScreen_49D0F0(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rc;      // [esp+4h] [ebp-10h]

	if (!ptr_5D4594_3799572->data[0])
		return (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) & dword_5d4594_1305716)(xLeft, yTop, a3, a4);
	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = sub_49F930((int4*)&rc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[1]));
	if (result)
		result = (int4*)(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) &
						 dword_5d4594_1305716)(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
	return result;
}

//----- (0049D190) --------------------------------------------------------
int __cdecl nox_client_drawRectStringSize_49D190(int a1, int a2, int a3, int a4, int a5) {
	return func_5D4594_1305696(a1, a2, a3, a4, a5);
}

//----- (0049D1C0) --------------------------------------------------------
int __cdecl sub_49D1C0(int a1, int a2, int a3) {
	func_5D4594_1305708(a1, a2, a3);
	return 0;
}

//----- (0049D1E0) --------------------------------------------------------
void __cdecl sub_49D1E0(int a1, int a2, unsigned int a3, int a4) {
	int result; // eax
	_DWORD* v5; // esi
	char* v6;   // edi
	char* v7;   // edi

	result = ptr_5D4594_3799572;
	if (ptr_5D4594_3799572->data[13]) {
		sub_49D2F0(a1, a2, a3, a4);
		return;
	}
	if (a4 > 0 && (int)a3 > 0) {
		result = ptr_5D4594_3799572->data[61];
		v5 = &nox_pixbuffer_rows_3798784[a2];
		do {
			v6 = (char*)(a1 + *v5);
			memset32(v6, result, a3 >> 2);
			v7 = &v6[4 * (a3 >> 2)];
			if (a3 & 3) {
				*v7 = result;
				if ((a3 & 3) != 1) {
					v7[1] = result;
					if ((a3 & 3) != 2)
						v7[2] = result;
				}
			}
			++v5;
		} while (a4-- > 1);
	}
}

//----- (0049D270) --------------------------------------------------------
void __cdecl sub_49D270(int a1, int a2, unsigned int a3, int a4) {
	int result; // eax
	int v5;     // edx
	_DWORD* v6; // esi
	char* v7;   // edi
	char* v8;   // edi

	result = ptr_5D4594_3799572;
	if (ptr_5D4594_3799572->data[13]) {
		(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD)) & byte_5D4594[1305692])(a1, a2, a3, a4);
		return;
	}
	v5 = a4;
	if (a4 > 0 && (int)a3 > 0) {
		result = ptr_5D4594_3799572->data[61];
		v6 = &nox_pixbuffer_rows_3798784[a2];
		do {
			v7 = (char*)(2 * a1 + *v6);
			memset32(v7, result, a3 >> 1);
			v8 = &v7[4 * (a3 >> 1)];
			if (a3 & 1)
				*(_WORD*)v8 = result;
			++v6;
		} while (v5-- > 1);
	}
}

//----- (0049D2F0) --------------------------------------------------------
int __cdecl sub_49D2F0(int a1, int a2, int a3, int a4) {
	int result;          // eax
	int v5;              // edi
	int v6;              // eax
	unsigned __int8* v7; // eax
	int v8;              // esi
	int v9;              // edx
	unsigned __int8 v10; // [esp+0h] [ebp-4h]

	result = a4 - 1;
	v10 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
	if (a4) {
		v5 = 4 * a2;
		do {
			v6 = nox_pixbuffer_rows_3798784[v5/4];
			v5 += 4;
			v7 = (unsigned __int8*)(a1 + v6);
			if (a3) {
				v8 = a3;
				do {
					v9 = v10 + (*v7++ << 8);
					--v8;
					*(v7 - 1) = *(_BYTE*)(v9 + dword_5d4594_810632);
				} while (v8);
			}
			result = --a4;
		} while (a4);
	}
	return result;
}

//----- (0049D370) --------------------------------------------------------
void __cdecl sub_49D370(int a1, int a2, int a3, int a4) {
	int v4;              // eax
	unsigned __int8 v5;  // bl
	int result;          // eax
	int v7;              // ecx
	int v8;              // edx
	int v9;              // esi
	__int16* v10;        // esi
	int v11;             // ebp
	__int16 v12;         // cx
	bool v13;            // zf
	unsigned __int8 v14; // [esp+Ch] [ebp-28h]
	unsigned __int8 v15; // [esp+10h] [ebp-24h]
	unsigned __int8 v16; // [esp+14h] [ebp-20h]
	int v17;             // [esp+38h] [ebp+4h]
	int v18;             // [esp+3Ch] [ebp+8h]
	int v19;             // [esp+44h] [ebp+10h]

	v4 = ptr_5D4594_3799572->data[61] & 0xFFFF;
	v17 = 2 * a1;
	v5 = byte_5D4594[3804372];
	v16 = (*(_DWORD*)&byte_5D4594[3804364] & (unsigned int)v4) >> byte_5D4594[3804376];
	v15 = (*(_DWORD*)&byte_5D4594[3804368] & (unsigned int)v4) >> byte_5D4594[3804380];
	v14 = ((unsigned __int8)ptr_5D4594_3799572->data[61] & byte_5D4594[3804372]) << byte_5D4594[3804384];
	result = a4 - 1;
	if (a4) {
		v7 = a3;
		v8 = 4 * a2;
		v18 = a4;
		do {
			v9 = nox_pixbuffer_rows_3798784[v8/4];
			v8 += 4;
			v10 = (__int16*)(v17 + v9);
			if (v7) {
				v11 = v16;
				v19 = v7;
				while (1) {
					v12 = *v10;
					++v10;
					v13 = v19 == 1;
					*(v10 - 1) =
						*(_WORD*)(dword_5d4594_3804664 +
								  2 * (unsigned __int8)((((unsigned __int8)v12 & v5) << byte_5D4594[3804384]) +
														((v14 - (unsigned __int8)(((unsigned __int8)v12 & v5)
																				  << byte_5D4594[3804384])) >>
														 1))) |
						*(_WORD*)(dword_5d4594_3804656 +
								  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & v12) >>
														 byte_5D4594[3804380]) +
														((v15 -
														  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594
																								   [3804368] &
																							   v12) >>
																			byte_5D4594[3804380])) >>
														 1))) |
						*(_WORD*)(dword_5d4594_3804672 +
								  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & v12) >>
														 byte_5D4594[3804376]) +
														((v11 -
														  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594
																								   [3804364] &
																							   v12) >>
																			byte_5D4594[3804376])) >>
														 1)));
					v5 = byte_5D4594[3804372];
					--v19;
					if (v13)
						break;
					v11 = v16;
				}
				v7 = a3;
			}
			result = --v18;
		} while (v18);
	}
}

int __cdecl sub_49D540(int a1, int a2, int a3, int a4) {
	DebugBreak();
	return 0;
}

#if 0
//----- (0049D540) --------------------------------------------------------
int __cdecl sub_49D540(int a1, int a2, int a3, int a4)
{
    __m64 v4; // mm0
    __m64 v5; // mm1
    __m64 v6; // mm2
    int* v7; // esi
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    __m64 v13; // mm4
    __m64 v14; // mm5
    __m64 v15; // mm3
    bool v16; // cc
    int v17; // ecx
    __m64 v18; // [esp+Ch] [ebp-8h]
    __m64 v19; // [esp+Ch] [ebp-8h]

    v18.m64_i32[0] = *(_DWORD*)(&obj_5D4594_3800716.data[61]);
    v18.m64_i32[1] = *(_DWORD*)(&obj_5D4594_3800716.data[61]);
    v4 = _m_psrlw(_m_pand(v18, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
    v5 = _m_psrlw(_m_pand(v18, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
    v6 = _m_psllw(_m_pand(v18, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
    v7 = (int*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v7;
        ++v7;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_psrlw(_m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
            v13 = _m_psrlw(_m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
            v14 = _m_psllw(_m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
            v15 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(_m_paddw(v12, _m_psrlwi(_m_psubw(v4, v12), 1u)), *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(_m_paddw(v13, _m_psrlwi(_m_psubw(v5, v13), 1u)), *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(_m_paddw(v14, _m_psrlwi(_m_psubw(v6, v14), 1u)), *(__m64*) & byte_5D4594[3804460]));
            v16 = v9 < 4;
            v9 -= 4;
            if (v16)
                break;
            v11->m64_u64 = (unsigned __int64)v15;
            ++v11;
            if (v16)
            {
                v16 = a4-- <= 1;
                if (!v16)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v19 = v15;
        LOWORD(v11->m64_i32[0]) = v19.m64_i16[0];
        v17 = v9 + 3;
        if (v17)
        {
            HIWORD(v11->m64_i32[0]) = v19.m64_i16[1];
            if (v17 != 1)
                LOWORD(v11->m64_i32[1]) = v19.m64_i16[2];
        }
        v16 = a4-- <= 1;
        if (!v16)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}
#endif

//----- (0049D680) --------------------------------------------------------
int __cdecl sub_49D680(int a1, int a2, int a3, int a4) {
	int result;          // eax
	int v5;              // ecx
	unsigned __int8* v6; // eax
	int v7;              // esi
	int v8;              // edx

	result = a4 - 1;
	if (a4) {
		v5 = 4 * a2;
		do {
			v5 += 4;
			v6 = (unsigned __int8*)(a1 + *(_DWORD*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784 - 4));
			if (a3) {
				v7 = a3;
				do {
					v8 = *v6++ << 8;
					--v7;
					*(v6 - 1) = *(_BYTE*)(v8 + dword_5d4594_810632);
				} while (v7);
			}
			result = --a4;
		} while (a4);
	}
	return result;
}

//----- (0049D6F0) --------------------------------------------------------
__int16 __cdecl sub_49D6F0(int a1, int a2, unsigned int a3, int a4) {
	unsigned int v4; // eax
	_DWORD* v5;      // esi
	int v6;          // edx
	int v7;          // ebx
	char v8;         // cf
	// char v9; // of
	char v10;          // cc
	int v11;           // ecx
	unsigned int* v12; // edi
	int v13;           // ecx
	unsigned int* v14; // edi
	unsigned int v16;  // [esp+1Ch] [ebp+10h]

	if (a4 > 0) {
		LOWORD(v4) = a2;
		v5 = &nox_pixbuffer_rows_3798784[a2];
		v6 = *(_DWORD*)&byte_5D4594[3804388];
		v7 = 2 * a1;
		v8 = a3 & 1;
		// v10 = (((a3 >> 1) & 0x80000000) != 0) ^ v9 | (a3 >> 1 == 0);
		v16 = a3 >> 1;
		if (v16) {
			if (v8) {
				do {
					v13 = v16;
					v14 = (unsigned int*)(v7 + *v5);
					do {
						*v14 = (v6 & *v14) >> 1;
						++v14;
						v10 = v13-- <= 1;
					} while (!v10);
					LOWORD(v4) = (unsigned __int16)(v6 & *(_WORD*)v14) >> 1;
					*(_WORD*)v14 = v4;
					++v5;
					v10 = a4-- <= 1;
				} while (!v10);
			} else {
				do {
					v11 = v16;
					v12 = (unsigned int*)(v7 + *v5);
					do {
						v4 = (v6 & *v12) >> 1;
						*v12 = v4;
						++v12;
						v10 = v11-- <= 1;
					} while (!v10);
					++v5;
					v10 = a4-- <= 1;
				} while (!v10);
			}
		}
	}
	return v4;
}

void __cdecl sub_49D770(int a1, int a2, unsigned int a3, int a4) {
	DebugBreak();
	return;
}

#if 0
//----- (0049D770) --------------------------------------------------------
void __cdecl sub_49D770(int a1, int a2, unsigned int a3, int a4)
{
    _DWORD* v4; // esi
    __m64 v5; // mm1
    int v6; // edx
    int v7; // ebx
    unsigned int v8; // eax
    signed int v9; // ecx
    __m64* v10; // edi
    bool v11; // cc
    signed int v12; // ecx
    __m64* v13; // edi
    signed int v14; // ecx
    __m64* v15; // edi
    signed int v16; // ecx
    __m64* v17; // edi

    if (a4 > 0 && (int)a3 > 0)
    {
        v4 = (_DWORD*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
        v5 = *(__m64*) & byte_5D4594[3804516];
        v6 = _mm_cvtsi64_si32(*(__m64*) & byte_5D4594[3804516]);
        v7 = 2 * a1;
        v8 = a3 >> 1;
        if (a3 & 1)
        {
            if (v8 & 1)
            {
                do
                {
                    v14 = a3 >> 2;
                    v15 = (__m64*)(v7 + *v4);
                    do
                    {
                        v15->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v15->m64_u64, v5), 1u);
                        ++v15;
                        v11 = v14-- <= 1;
                    } while (!v11);
                    v15->m64_i32[0] = ((unsigned int)v6 & v15->m64_i32[0]) >> 1;
                    HIWORD(v15->m64_i32[0]) = (unsigned __int16)(v6 & HIWORD(v15->m64_i32[0])) >> 1;
                    ++v4;
                    v11 = a4-- <= 1;
                } while (!v11);
            }
            else
            {
                do
                {
                    v12 = a3 >> 2;
                    v13 = (__m64*)(v7 + *v4);
                    do
                    {
                        v13->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v13->m64_u64, v5), 1u);
                        ++v13;
                        v11 = v12-- <= 1;
                    } while (!v11);
                    LOWORD(v13->m64_i32[0]) = (unsigned __int16)(v6 & LOWORD(v13->m64_i32[0])) >> 1;
                    ++v4;
                    v11 = a4-- <= 1;
                } while (!v11);
            }
        }
        else if (v8 & 1)
        {
            do
            {
                v9 = a3 >> 2;
                v10 = (__m64*)(v7 + *v4);
                do
                {
                    v10->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v10->m64_u64, v5), 1u);
                    ++v10;
                    v11 = v9-- <= 1;
                } while (!v11);
                v10->m64_i32[0] = ((unsigned int)v6 & v10->m64_i32[0]) >> 1;
                ++v4;
                v11 = a4-- <= 1;
            } while (!v11);
        }
        else
        {
            do
            {
                v16 = a3 >> 2;
                v17 = (__m64*)(v7 + *v4);
                do
                {
                    v17->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v17->m64_u64, v5), 1u);
                    ++v17;
                    v11 = v16-- <= 1;
                } while (!v11);
                ++v4;
                v11 = a4-- <= 1;
            } while (!v11);
        }
        _m_femms();
    }
}
#endif

//----- (0049D880) --------------------------------------------------------
void __cdecl sub_49D880(int a1, int a2, int a3, int a4) {
	_DWORD* v4;          // esi
	int v5;              // ebx
	int v6;              // ecx
	unsigned __int8* v7; // edi
	bool v9;             // cc

	if (a4 > 0 && a3 > 0) {
		v4 = &nox_pixbuffer_rows_3798784[a2];
		v5 = (*(_DWORD*)(&obj_5D4594_3800716.data[258]) >> 3) + dword_5d4594_810636;
		do {
			v6 = a3;
			v7 = (unsigned __int8*)(a1 + *v4);
			do {
				*v7++ = *(_BYTE*)(v5 + 32 * *v7);
				v9 = v6-- <= 1;
			} while (!v9);
			++v4;
			v9 = a4-- <= 1;
		} while (!v9);
	}
}

//----- (0049D8E0) --------------------------------------------------------
int __cdecl sub_49D8E0(int a1, int a2, int a3, int a4) {
	int* v4;         // esi
	int v5;          // edi
	_WORD* v6;       // edi
	unsigned int v7; // edx
	int v8;          // eax
	unsigned int v9; // ebx
	int v10;         // edx
	int result;      // eax
	bool v12;        // cc
	int v13;         // [esp+Ch] [ebp-4h]

	v4 = &nox_pixbuffer_rows_3798784[a2];
	do {
		v13 = a3;
		v5 = *v4;
		++v4;
		v6 = (_WORD*)(a1 + a1 + v5);
		do {
			v7 = (unsigned __int16)*v6;
			v8 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v6) >> byte_5D4594[3804376];
			LOBYTE(v8) = SADD8(obj_5D4594_3800716.data[54],
							   v8); //__CFADD__(obj_5D4594_3800716.data[54], (_BYTE)v8) ? -1 : (unsigned
									//__int8)(obj_5D4594_3800716.data[54] + v8);
			v9 = (*(_DWORD*)&byte_5D4594[3804368] & v7) >> byte_5D4594[3804380];
			LOBYTE(v9) = SADD8(obj_5D4594_3800716.data[55],
							   v9); //__CFADD__(obj_5D4594_3800716.data[55], (_BYTE)v9) ? -1 : (unsigned
									//__int8)(obj_5D4594_3800716.data[55] + v9);
			v10 = (*(_DWORD*)&byte_5D4594[3804372] & v7) << byte_5D4594[3804384];
			LOBYTE(v10) = SADD8(obj_5D4594_3800716.data[56],
								v10); //__CFADD__(obj_5D4594_3800716.data[56], (_BYTE)v10) ? -1 : (unsigned
									  //__int8)(obj_5D4594_3800716.data[56] + v10);
			result = *(_DWORD*)(dword_5d4594_3804664 + 2 * v10) | *(_DWORD*)(dword_5d4594_3804656 + 2 * v9) |
					 *(_DWORD*)(dword_5d4594_3804672 + 2 * v8);
			*v6 = result;
			++v6;
			v12 = v13-- <= 1;
		} while (!v12);
		v12 = a4-- <= 1;
	} while (!v12);
	return result;
}

int __cdecl sub_49D9A0(int a1, int a2, int a3, int a4) {
	DebugBreak();
	return 0;
}

#if 0
//----- (0049D9A0) --------------------------------------------------------
int __cdecl sub_49D9A0(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    __m64 v5; // mm0
    __m64 v6; // mm1
    __m64 v7; // mm2
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    bool v13; // cc
    int v14; // ecx
    __m64 v15; // [esp+Ch] [ebp-8h]

    v4 = (int*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
    v5 = *(__m64*)(&obj_5D4594_3800716.data[48]);
    v6 = *(__m64*)(&obj_5D4594_3800716.data[50]);
    v7 = *(__m64*)(&obj_5D4594_3800716.data[52]);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v4;
        ++v4;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(
                            _m_paddusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804396]),
                                    *(__m64*) & byte_5D4594[3804444]),
                                v5),
                            *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(
                            _m_paddusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804404]),
                                    *(__m64*) & byte_5D4594[3804452]),
                                v6),
                            *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(
                    _m_paddusb(
                        _m_psllw(
                            _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804412]),
                            *(__m64*) & byte_5D4594[3804460]),
                        v7),
                    *(__m64*) & byte_5D4594[3804460]));
            v13 = v9 < 4;
            v9 -= 4;
            if (v13)
                break;
            v11->m64_u64 = (unsigned __int64)v12;
            ++v11;
            if (v13)
            {
                v13 = a4-- <= 1;
                if (!v13)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v15 = v12;
        LOWORD(v11->m64_i32[0]) = v15.m64_i16[0];
        v14 = v9 + 3;
        if (v14)
        {
            HIWORD(v11->m64_i32[0]) = v15.m64_i16[1];
            if (v14 != 1)
                LOWORD(v11->m64_i32[1]) = v15.m64_i16[2];
        }
        v13 = a4-- <= 1;
        if (!v13)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}

#endif

//----- (0049DA90) --------------------------------------------------------
unsigned __int8 __cdecl sub_49DA90(int a1, int a2, int a3, int a4) {
	int* v4;                // esi
	int v5;                 // ecx
	int v6;                 // edi
	unsigned __int8* v7;    // edi
	int v8;                 // eax
	char v9;                // bl
	char v10;               // bh
	int v11;                // eax
	unsigned __int8 result; // al
	bool v13;               // cc

	v4 = &nox_pixbuffer_rows_3798784[a2];
	do {
		v5 = a3;
		v6 = *v4;
		++v4;
		v7 = (unsigned __int8*)(a1 + v6);
		do {
			v8 = *v7;
			// v9 = (unsigned __int8)(__CFADD__(obj_5D4594_3800716.data[56], byte_5D4594[4 * v8 + 3803310])
			// ? -1 : (unsigned __int8)(obj_5D4594_3800716.data[56] + byte_5D4594[4 * v8 + 3803310])) >> 3;
			v9 = SADD8(obj_5D4594_3800716.data[56], byte_5D4594[4 * v8 + 3803310]) >> 3;
			// v10 = (__CFADD__(obj_5D4594_3800716.data[55], byte_5D4594[4 * v8 + 3803309]) ? -1 : (unsigned
			// __int8)(obj_5D4594_3800716.data[55] + byte_5D4594[4 * v8 + 3803309])) & 0xF8;
			v10 = SADD8(obj_5D4594_3800716.data[55], byte_5D4594[4 * v8 + 3803309]) & 0xF8;
			// v11 = 32
			//    * (((unsigned __int8)-__CFADD__(obj_5D4594_3800716.data[54], byte_5D4594[4 * v8 +
			//    3803308]) | (unsigned __int8)(obj_5D4594_3800716.data[54] + byte_5D4594[4 * v8 +
			//    3803308])) & 0xF8);
			v11 = 32 * (SADD8(obj_5D4594_3800716.data[54], byte_5D4594[4 * v8 + 3803308]) & 0xF8);
			LOBYTE(v11) = v10;
			v11 *= 4;
			LOBYTE(v11) = v9 | v11;
			result = *(_BYTE*)(dword_5d4594_810640 + v11);
			*v7++ = result;
			v13 = v5-- <= 1;
		} while (!v13);
		v13 = a4-- <= 1;
	} while (!v13);
	return result;
}

//----- (0049DB20) --------------------------------------------------------
unsigned __int8 __cdecl sub_49DB20(int a1, int a2, int a3, int a4) {
	int* v4;                // esi
	int v5;                 // ecx
	int v6;                 // edi
	unsigned __int8* v7;    // edi
	int v8;                 // eax
	char v9;                // bl
	char v10;               // bh
	int v11;                // eax
	unsigned __int8 result; // al
	bool v13;               // cc

	v4 = &nox_pixbuffer_rows_3798784[a2];
	do {
		v5 = a3;
		v6 = *v4;
		++v4;
		v7 = (unsigned __int8*)(a1 + v6);
		do {
			v8 = *v7;
			v9 = (unsigned __int8)(byte_5D4594[4 * v8 + 3803310] < obj_5D4594_3800716.data[56]
									   ? 0
									   : (unsigned __int8)(byte_5D4594[4 * v8 + 3803310] -
														   obj_5D4594_3800716.data[56])) >>
				 3;
			v10 = (byte_5D4594[4 * v8 + 3803309] < obj_5D4594_3800716.data[55]
					   ? 0
					   : (unsigned __int8)(byte_5D4594[4 * v8 + 3803309] - obj_5D4594_3800716.data[55])) &
				  0xF8;
			v11 = 32 * ((unsigned __int8)((byte_5D4594[4 * v8 + 3803308] < obj_5D4594_3800716.data[54]) - 1) &
						(unsigned __int8)(byte_5D4594[4 * v8 + 3803308] - obj_5D4594_3800716.data[54]) & 0xF8);
			LOBYTE(v11) = v10;
			v11 *= 4;
			LOBYTE(v11) = v9 | v11;
			result = *(_BYTE*)(dword_5d4594_810640 + v11);
			*v7++ = result;
			v13 = v5-- <= 1;
		} while (!v13);
		v13 = a4-- <= 1;
	} while (!v13);
	return result;
}

//----- (0049DBB0) --------------------------------------------------------
int __cdecl sub_49DBB0(int a1, int a2, int a3, int a4) {
	int* v4;             // esi
	int v5;              // edi
	_WORD* v6;           // edi
	unsigned __int64 v7; // kr00_8
	unsigned __int64 v8; // kr08_8
	int result;          // eax
	bool v10;            // cc
	int v11;             // [esp+Ch] [ebp-4h]

	v4 = &nox_pixbuffer_rows_3798784[a2];
	do {
		v11 = a3;
		v5 = *v4;
		++v4;
		v6 = (_WORD*)(a1 + a1 + v5);
		do {
			v7 = ((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v6) >> byte_5D4594[3804380]) -
				 (unsigned __int64)*(unsigned int*)&obj_5D4594_3800716.data[55];
			v8 = ((unsigned __int16)(*(_WORD*)&byte_5D4594[3804372] & *v6) << byte_5D4594[3804384]) -
				 (unsigned __int64)*(unsigned int*)&obj_5D4594_3800716.data[56];
			result =
				*(_DWORD*)(dword_5d4594_3804664 + 2 * (~HIDWORD(v8) & v8)) |
				*(_DWORD*)(dword_5d4594_3804656 + 2 * (~HIDWORD(v7) & v7)) |
				*(_DWORD*)(dword_5d4594_3804672 +
						   2 * (~((__PAIR64__(*(unsigned int*)&byte_5D4594[3804376],
											  (unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v6) >>
												  byte_5D4594[3804376]) -
								   __PAIR64__(*(unsigned int*)&byte_5D4594[3804376],
											  *(unsigned int*)&obj_5D4594_3800716.data[54])) >>
								  32) &
								(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v6) >> byte_5D4594[3804376]) -
								 *(_DWORD*)(&obj_5D4594_3800716.data[54]))));
			*v6 = result;
			++v6;
			v10 = v11-- <= 1;
		} while (!v10);
		v10 = a4-- <= 1;
	} while (!v10);
	return result;
}

int __cdecl sub_49DC70(int a1, int a2, int a3, int a4) {
	DebugBreak();
	return 0;
}

#if 0
//----- (0049DC70) --------------------------------------------------------
int __cdecl sub_49DC70(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    __m64 v5; // mm0
    __m64 v6; // mm1
    __m64 v7; // mm2
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    bool v13; // cc
    int v14; // ecx
    __m64 v15; // [esp+Ch] [ebp-8h]

    v4 = (int*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
    v5 = *(__m64*)(&obj_5D4594_3800716.data[48]);
    v6 = *(__m64*)(&obj_5D4594_3800716.data[50]);
    v7 = *(__m64*)(&obj_5D4594_3800716.data[52]);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v4;
        ++v4;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(
                            _m_psubusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804396]),
                                    *(__m64*) & byte_5D4594[3804444]),
                                v5),
                            *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(
                            _m_psubusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804404]),
                                    *(__m64*) & byte_5D4594[3804452]),
                                v6),
                            *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(
                    _m_psubusb(
                        _m_psllw(
                            _m_pand((__m64)v11->m64_u64, *(__m64*) & byte_5D4594[3804412]),
                            *(__m64*) & byte_5D4594[3804460]),
                        v7),
                    *(__m64*) & byte_5D4594[3804460]));
            v13 = v9 < 4;
            v9 -= 4;
            if (v13)
                break;
            v11->m64_u64 = (unsigned __int64)v12;
            ++v11;
            if (v13)
            {
                v13 = a4-- <= 1;
                if (!v13)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v15 = v12;
        LOWORD(v11->m64_i32[0]) = v15.m64_i16[0];
        v14 = v9 + 3;
        if (v14)
        {
            HIWORD(v11->m64_i32[0]) = v15.m64_i16[1];
            if (v14 != 1)
                LOWORD(v11->m64_i32[1]) = v15.m64_i16[2];
        }
        v13 = a4-- <= 1;
        if (!v13)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}
#endif
//----- (0049DD60) --------------------------------------------------------
int4* __cdecl sub_49DD60(int a1, int a2, int a3, int a4, int a5) {
	int4* result;         // eax
	int v6;               // ebp
	int v7;               // esi
	int4* v8;             // ecx
	unsigned __int8 v9;   // dl
	int v10;              // eax
	int v11;              // ebx
	int v12;              // ecx
	int v13;              // edi
	_BYTE* v14;           // eax
	_BYTE* v15;           // ecx
	_BYTE* v16;           // esi
	int v17;              // edi
	int v18;              // ebp
	int v19;              // ebx
	int v20;              // edx
	unsigned __int8* v21; // eax
	int v22;              // esi
	int v23;              // ecx
	int v24;              // ecx
	int v25;              // eax
	int v26;              // edx
	char v27;             // al
	int* v28;             // eax
	int v29;              // ecx
	int v30;              // esi
	bool v31;             // zf
	int v32;              // [esp+Ch] [ebp-6Ch]
	int v33;              // [esp+10h] [ebp-68h]
	int v34;              // [esp+18h] [ebp-60h]
	int v35;              // [esp+1Ch] [ebp-5Ch]
	int v36;              // [esp+20h] [ebp-58h]
	int4 a3a;             // [esp+24h] [ebp-54h]
	int4 a2a;             // [esp+34h] [ebp-44h]
	int4 a1a;             // [esp+44h] [ebp-34h]
	_BYTE* v40[9];        // [esp+54h] [ebp-24h]
	int v41;              // [esp+84h] [ebp+Ch]

	if (ptr_5D4594_3799572->data[0]) {
		a2a.field_0 = a2;
		a2a.field_8 = a4 + a2;
		a2a.field_4 = a3;
		a2a.field_C = a5 + a3;
		a3a.field_4 = 1;
		a3a.field_0 = 1;
		a3a.field_8 = nox_backbuffer_width - 1;
		a3a.field_C = nox_backbuffer_height - 1;
		result = sub_49F930(&a1a, &a2a, &a3a);
		if (!result)
			return result;
		v6 = a1a.field_0;
		a2 = a1a.field_0;
		v7 = a1a.field_4;
		a4 = a1a.field_8 - a1a.field_0;
		v8 = (int4*)(a1a.field_C - a1a.field_4);
	} else {
		v8 = (int4*)a5;
		v7 = a3;
		v6 = a2;
	}
	v9 = a1;
	v10 = 4 * a1;
	v34 = byte_5D4594[v10 + 3803308];
	v35 = byte_5D4594[v10 + 3803309];
	v11 = byte_5D4594[v10 + 3803310];
	result = v8;
	v12 = (int)&v8[-1].field_C + 3;
	v36 = v11;
	if (result) {
		v13 = 4 * v7;
		v41 = 4 * v7;
		v33 = v12 + 1;
		while (1) {
			v14 = (_BYTE*)(v6 + *(_DWORD*)(v13 + (_DWORD)nox_pixbuffer_rows_3798784 - 4));
			v40[1] = v14;
			v40[0] = v14 - 1;
			v40[2] = v14 + 1;
			v15 = (_BYTE*)(v6 + (_DWORD)nox_pixbuffer_rows_3798784[v13/4]);
			v16 = (_BYTE*)(v6 + *(_DWORD*)(v13 + (_DWORD)nox_pixbuffer_rows_3798784 + 4));
			v40[4] = v15;
			v40[7] = v16;
			v40[3] = v15 - 1;
			v40[5] = v15 + 1;
			v40[6] = v16 - 1;
			v40[8] = v16 + 1;
			if (a4 > 0) {
				v32 = a4;
				while (1) {
					if (*v40[0] == v9 || *v14 == v9 || *v40[2] == v9 || *v40[3] == v9 || *v15 == v9 || *v40[5] == v9 ||
						*v40[6] == v9 || *v16 == v9 || *v40[8] == v9) {
						v17 = 0;
						v18 = 0;
						v19 = 0;
						v20 = 0;
						do {
							v21 = v40[v20];
							v22 = *(_DWORD*)&byte_581450[v20 * 4 + 9680];
							++v20;
							v23 = 4 * *v21;
							v17 += v22 * byte_5D4594[v23 + 3803308];
							v18 += v22 * byte_5D4594[v23 + 3803309];
							v19 += v22 * byte_5D4594[v23 + 3803310];
						} while (v20 < 9);
						v24 = v17 / 12;
						v25 = v19 / 12;
						if (v17 / 12 > v34)
							LOBYTE(v24) = v34;
						v26 = v18 / 12;
						if (v18 / 12 > v35)
							LOBYTE(v26) = v35;
						if (v25 > v36)
							v25 = v36;
						v6 = a2;
						v13 = v41;
						v27 = *(
							_BYTE*)(((v25 >> 3) & 0xFFFF | (unsigned __int16)(4 * (v26 & 0xF8 | (32 * (v24 & 0xF8))))) +
									dword_5d4594_810640);
						v9 = a1;
						*v40[4] = v27;
					}
					v28 = (int*)v40;
					v29 = 9;
					do {
						v30 = *v28;
						++v28;
						--v29;
						*(v28 - 1) = v30 + 1;
					} while (v29);
					if (!--v32)
						break;
					v16 = v40[7];
					v14 = v40[1];
					v15 = v40[4];
				}
			}
			result = (int4*)(v33 - 1);
			v31 = v33 == 1;
			v41 = v13 + 4;
			--v33;
			if (v31)
				break;
			v13 += 4;
		}
	}
	return result;
}

//----- (0049E060) --------------------------------------------------------
int4* __cdecl sub_49E060(int a1, int a2, int a3, int a4, int a5) {
	int4* result;          // eax
	int v6;                // ebx
	int v7;                // ebp
	int v8;              // edx
	__int16 v9;            // di
	int v10;               // edx
	int v11;               // ebx
	int v12;               // esi
	_WORD* v13;            // eax
	_WORD* v14;            // ecx
	_WORD* v15;            // edx
	int v16;               // esi
	int v17;               // eax
	int v18;               // ebx
	unsigned __int16* v19; // edx
	int v20;               // edi
	unsigned int v21;      // edx
	int v22;               // ecx
	int v23;               // edi
	int v24;               // eax
	__int16 v25;           // ax
	int* v26;              // eax
	int v27;               // ecx
	bool v29;              // zf
	int v30;               // [esp+10h] [ebp-68h]
	int v31;               // [esp+14h] [ebp-64h]
	int v32;               // [esp+18h] [ebp-60h]
	int v33;               // [esp+1Ch] [ebp-5Ch]
	int v34;               // [esp+20h] [ebp-58h]
	int4 a3a;              // [esp+24h] [ebp-54h]
	int4 a2a;              // [esp+34h] [ebp-44h]
	int4 a1a;              // [esp+44h] [ebp-34h]
	_WORD* v38[9];
	int v47; // [esp+80h] [ebp+8h]
	int v48; // [esp+84h] [ebp+Ch]
	int v49; // [esp+8Ch] [ebp+14h]

	if (ptr_5D4594_3799572->data[0]) {
		a2a.field_0 = a2;
		a2a.field_8 = a4 + a2;
		a2a.field_4 = a3;
		a2a.field_C = a5 + a3;
		a3a.field_4 = 1;
		a3a.field_0 = 1;
		a3a.field_8 = nox_backbuffer_width - 1;
		a3a.field_C = nox_backbuffer_height - 1;
		result = sub_49F930(&a1a, &a2a, &a3a);
		if (!result)
			return result;
		v6 = a1a.field_0;
		v7 = a1a.field_4;
		a4 = a1a.field_8 - a1a.field_0;
		v8 = a1a.field_C - a1a.field_4;
	} else {
		v8 = a5;
		v7 = a3;
		v6 = a2;
	}
	v9 = a1;
	v31 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & a1) >> byte_5D4594[3804376];
	v32 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & a1) >> byte_5D4594[3804380];
	v33 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804372] & a1) << byte_5D4594[3804384];
	result = v8;
	v10 = (int)v8 - 1;
	if (result) {
		v11 = 2 * v6;
		v12 = 4 * v7;
		v34 = v11;
		v47 = 4 * v7;
		v30 = v10 + 1;
		do {
			v13 = (_WORD*)(v11 + *(_DWORD*)(v12 + (_DWORD)nox_pixbuffer_rows_3798784 - 4));
			v38[1] = v13;
			v38[0] = v13 - 1;
			v38[2] = v13 + 1;
			v14 = (_WORD*)(v11 + (_DWORD)nox_pixbuffer_rows_3798784[v12/4]);
			v15 = (_WORD*)(v11 + *(_DWORD*)(v12 + (_DWORD)nox_pixbuffer_rows_3798784 + 4));
			v38[4] = v14;
			v38[7] = v15;
			v38[3] = v14 - 1;
			v38[5] = v14 + 1;
			v38[6] = v15 - 1;
			v38[8] = v15 + 1;
			if (a4 > 0) {
				v48 = a4;
				while (1) {
					if (*v38[0] == v9 || *v13 == v9 || *v38[2] == v9 || *v38[3] == v9 || *v14 == v9 || *v38[5] == v9 ||
						*v38[6] == v9 || *v15 == v9 || *v38[8] == v9) {
						v16 = 0;
						v17 = 0;
						v18 = 0;
						v49 = 0;
						do {
							v19 = v38[v16];
							v20 = *(_DWORD*)&byte_581450[v16 * 4 + 9680];
							++v16;
							v21 = *v19;
							v17 += v20 * ((*(_DWORD*)&byte_5D4594[3804364] & v21) >> byte_5D4594[3804376]);
							v18 += v20 * ((*(_DWORD*)&byte_5D4594[3804368] & v21) >> byte_5D4594[3804380]);
							v49 += v20 * ((*(_DWORD*)&byte_5D4594[3804372] & v21) << byte_5D4594[3804384]);
						} while (v16 < 9);
						v22 = v17 / 12;
						v23 = v18 / 12;
						v24 = v49 / 12;
						if (v22 > v31)
							v22 = v31;
						if (v23 > v32)
							v23 = v32;
						if (v24 > v33)
							v24 = v33;
						v11 = v34;
						v12 = v47;
						v25 = *(_WORD*)(dword_5d4594_3804656 + 2 * v23) | *(_WORD*)(dword_5d4594_3804664 + 2 * v24);
						v9 = a1;
						*v38[4] = *(_WORD*)(dword_5d4594_3804672 + 2 * v22) | v25;
					}
					v26 = (int*)v38;
					for (v27 = 0; v27 < 9; v27++) {
						v26[v27] += 2;
					}
					if (!--v48)
						break;
					v15 = v38[7];
					v14 = v38[4];
					v13 = v38[1];
				}
			}
			v12 += 4;
			result = (int4*)(v30 - 1);
			v29 = v30 == 1;
			v47 = v12;
			--v30;
		} while (!v29);
	}
	return result;
}

//----- (0049E380) --------------------------------------------------------
void __cdecl sub_49E380(_DWORD* a1, int a2, unsigned int a3) {
	int v3;        // edi
	signed int v4; // ecx

	if ((int)a3 > 0) {
		v3 = a1;
		v4 = a3 >> 2;
		if (a3 >> 2) {
			do {
				*(_DWORD*)v3 = a2;
				v3 += 4;
			} while (v4-- > 1);
		}
		if (a3 & 3) {
			*(_BYTE*)v3 = a2;
			if ((a3 & 3) != 1) {
				*(_BYTE*)(v3 + 1) = a2;
				if ((a3 & 3) != 2)
					*(_BYTE*)(v3 + 2) = a2;
			}
		}
	}
}

//----- (0049E3C0) --------------------------------------------------------
void __cdecl sub_49E3C0(_DWORD* a1, int a2, unsigned int a3) {
	_DWORD* v3;    // edi
	signed int v4; // ecx

	if ((int)a3 > 0) {
		v3 = a1;
		v4 = a3 >> 2;
		if (a3 >> 2) {
			do {
				*v3 = a2;
				++v3;
			} while (v4-- > 1);
		}
		if ((int)(a3 & 3) >= 2)
			*(_WORD*)v3 = a2;
	}
}

//----- (0049E3F0) --------------------------------------------------------
int nox_video_initLineDrawingFuncs_49E3F0() {
	if (!dword_5d4594_3801780) {
		dword_5d4594_3798716 = sub_49E540;
		*(_DWORD*)&byte_5D4594[3798700] = sub_49EFC0;
		*(_DWORD*)&byte_5D4594[3798704] = sub_49ED80;
		dword_5d4594_3798720 = sub_49F060;
		dword_5d4594_3798708 = sub_49F0F0;
		dword_5d4594_3798712 = sub_49F3A0;
		return 1;
	}
	if (dword_5d4594_3801780 != 1)
		return 1;
	dword_5d4594_3798720 = sub_49F180;
	dword_5d4594_3798708 = sub_49F210;
	if (!dword_5d4594_3801804)
		dword_5d4594_3798708 = sub_49F180;
	dword_5d4594_3798712 = sub_49F420;
	dword_5d4594_3798716 = sub_49E930;
	*(_DWORD*)&byte_5D4594[3798700] = sub_49F010;
	*(_DWORD*)&byte_5D4594[3798704] = sub_49ED80;
	return 1;
}

//----- (0049E4B0) --------------------------------------------------------
int nox_client_drawLineFromPoints_49E4B0() { return (*(int(__cdecl**)(_DWORD)) & dword_5d4594_3798716)(0); }

//----- (0049E4C0) --------------------------------------------------------
int __cdecl sub_49E4C0(int a1, int a2, int a3, int a4) {
	nox_client_drawAddPoint_49F500(a1, a2);
	nox_client_drawAddPoint_49F500(a3, a4);
	return (*(int(__cdecl**)(_DWORD)) & dword_5d4594_3798716)(0);
}

//----- (0049E4F0) --------------------------------------------------------
int __cdecl sub_49E4F0(int a1) { return (*(int(__cdecl**)(_DWORD, _DWORD)) & byte_5D4594[3798704])(a1, 0); }

//----- (0049E510) --------------------------------------------------------
int __cdecl sub_49E510(int a1) {
	int i; // esi

	for (i = a1 - 1; i > 0; --i) {
		if (!(*(int(__cdecl**)(_DWORD)) & dword_5d4594_3798716)(1))
			break;
	}
	return (*(int(__cdecl**)(_DWORD)) & dword_5d4594_3798716)(0);
}

//----- (0049E540) --------------------------------------------------------
int __cdecl sub_49E540(int a1) {
	int result;          // eax
	int v2;              // esi
	int v3;              // eax
	int v4;              // ecx
	int v5;              // ebx
	int v6;              // edi
	int v7;              // edx
	int v8;              // edi
	int v9;              // edi
	int v10;             // edx
	unsigned __int8 v11; // bl
	unsigned __int8* i;  // edi
	bool v13;            // cc
	int v14;             // edi
	int v15;             // ebx
	unsigned __int8 v16; // dl
	int v17;             // [esp+Ch] [ebp-24h]
	int v18;             // [esp+10h] [ebp-20h]
	int v19;             // [esp+14h] [ebp-1Ch]
	int v20;             // [esp+18h] [ebp-18h]
	int v21;             // [esp+1Ch] [ebp-14h]
	int v22;             // [esp+1Ch] [ebp-14h]
	int v23;             // [esp+20h] [ebp-10h]
	int v24;             // [esp+24h] [ebp-Ch]
	int v25;             // [esp+28h] [ebp-8h]
	int v26;             // [esp+2Ch] [ebp-4h]
	int v27;             // [esp+38h] [ebp+8h]
	int v28;             // [esp+38h] [ebp+8h]

	if (ptr_5D4594_3799572->data[13])
		return sub_49E6C0(a1);
	result = sub_49F5B0(&v25, &v23, 0);
	if (result) {
		result = sub_49F5B0(&v26, &v24, a1);
		if (result) {
			if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v26, &v24, &v25, &v23)) {
				v2 = nox_pixbuffer_rows_3798784;
				v3 = v26;
				v4 = v24;
				if (v26 == v25) {
					(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798712)(v26, v24, v23);
				} else if (v24 == v23) {
					(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(v26, v24, v25);
				} else {
					v5 = v25 - v26;
					v6 = 1;
					if (v25 < v26) {
						v6 = -1;
						v5 = v26 - v25;
					}
					v17 = v6;
					v18 = v5;
					v7 = v23 - v24;
					v8 = 1;
					if (v23 < v24) {
						v8 = -1;
						v7 = v24 - v23;
					}
					v19 = v8;
					v20 = v7;
					if (v5 < v7) {
						v14 = v5;
						v22 = 2 * v5;
						v15 = 2 * v5 - v7;
						v28 = 2 * (v14 - v7);
						v16 = obj_5D4594_3800716.data[61];
						while (1) {
							*(_BYTE*)(v3 + *(_DWORD*)(v2 + 4 * v4)) = v16;
							v13 = v20-- < 1;
							if (v13)
								break;
							v4 += v19;
							if (v15 >= 0) {
								v15 += v28;
								v3 += v17;
							} else {
								v15 += v22;
							}
						}
					} else {
						v9 = v7;
						v21 = 2 * v7;
						v10 = 2 * v7 - v5;
						v27 = 2 * (v9 - v5);
						v11 = obj_5D4594_3800716.data[61];
					LABEL_18:
						for (i = (unsigned __int8*)(v3 + *(_DWORD*)(v2 + 4 * v4));; i += v17) {
							*i = v11;
							v13 = v18-- < 1;
							if (v13)
								break;
							v3 += v17;
							if (v10 >= 0) {
								v10 += v27;
								v4 += v19;
								goto LABEL_18;
							}
							v10 += v21;
						}
					}
				}
			}
			result = 1;
		}
	}
	return result;
}

//----- (0049E6C0) --------------------------------------------------------
int __cdecl sub_49E6C0(int a1) {
	int result;           // eax
	unsigned __int8* v2;  // ecx
	int v3;               // esi
	int v4;               // ebx
	int v5;               // edi
	int v6;               // edx
	int v7;               // edi
	int v8;               // edi
	int v9;               // edx
	_BYTE* i;             // edi
	unsigned __int8* v11; // ecx
	bool v12;             // cc
	int v13;              // edi
	int v14;              // ebx
	_BYTE* v15;           // edi
	unsigned __int8* v16; // ecx
	__int16 v17;          // [esp+0h] [ebp-38h]
	__int16 v18;          // [esp+4h] [ebp-34h]
	int v19;              // [esp+8h] [ebp-30h]
	int v20;              // [esp+Ch] [ebp-2Ch]
	int v21;              // [esp+10h] [ebp-28h]
	int v22;              // [esp+14h] [ebp-24h]
	int v23;              // [esp+18h] [ebp-20h]
	int v24;              // [esp+1Ch] [ebp-1Ch]
	int v25;              // [esp+1Ch] [ebp-1Ch]
	int v26;              // [esp+20h] [ebp-18h]
	int v27;              // [esp+20h] [ebp-18h]
	int v28;              // [esp+28h] [ebp-10h]
	int v29;              // [esp+2Ch] [ebp-Ch]
	int v30;              // [esp+30h] [ebp-8h]
	int v31;              // [esp+34h] [ebp-4h]

	result = sub_49F5B0(&v29, &v28, 0);
	if (result) {
		result = sub_49F5B0(&v30, &v31, a1);
		if (result) {
			if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v30, &v31, &v29, &v28)) {
				v2 = &byte_5D4594[4 * obj_5D4594_3800716.data[61] + 3803308];
				v3 = nox_pixbuffer_rows_3798784;
				v17 = *v2;
				v18 = v2[1];
				v19 = v2[2];
				v4 = v29 - v30;
				v5 = 1;
				if (v29 < v30) {
					v5 = -1;
					v4 = v30 - v29;
				}
				v20 = v5;
				v6 = v28 - v31;
				v21 = v4;
				v7 = 1;
				if (v28 < v31) {
					v7 = -1;
					v6 = v31 - v28;
				}
				v22 = v7;
				v23 = v6;
				if (v4 < v6) {
					v13 = v4;
					v25 = 2 * v4;
					v14 = 2 * v4 - v6;
					v27 = 2 * (v13 - v6);
					while (1) {
						v15 = (_BYTE*)(v30 + *(_DWORD*)(v3 + 4 * v31));
						v16 = &byte_5D4594[4 * (unsigned __int8)*v15 + 3803308];
						*v15 = *(
							_BYTE*)(dword_5d4594_810640 +
									(unsigned __int16)((4 *
														((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) *
																			  (v18 - v16[1])) >>
														   8) +
														  v16[1]) &
														 0xF8)) |
													   (((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) *
																			  (v17 - *v16)) >>
														   8) +
														  *v16) &
														 0xF8)
														<< 7) |
													   ((((*(_DWORD*)(&obj_5D4594_3800716.data[259]) *
														   (v19 - (unsigned int)v16[2])) >>
														  8) +
														 v16[2]) >>
														3)));
						v12 = v23-- < 1;
						if (v12)
							break;
						v31 += v22;
						if (v14 >= 0) {
							v14 += v27;
							v30 += v20;
						} else {
							v14 += v25;
						}
					}
				} else {
					v8 = v6;
					v24 = 2 * v6;
					v9 = 2 * v6 - v4;
					v26 = 2 * (v8 - v4);
				LABEL_15:
					for (i = (_BYTE*)(v30 + *(_DWORD*)(v3 + 4 * v31));; i += v20) {
						v11 = &byte_5D4594[4 * (unsigned __int8)*i + 3803308];
						*i = *(
							_BYTE*)(dword_5d4594_810640 +
									(unsigned __int16)((4 *
														((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) *
																			  (v18 - v11[1])) >>
														   8) +
														  v11[1]) &
														 0xF8)) |
													   (((((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716.data[259]) *
																			  (v17 - *v11)) >>
														   8) +
														  *v11) &
														 0xF8)
														<< 7) |
													   ((((*(_DWORD*)(&obj_5D4594_3800716.data[259]) *
														   (v19 - (unsigned int)v11[2])) >>
														  8) +
														 v11[2]) >>
														3)));
						v12 = v21-- < 1;
						if (v12)
							break;
						v30 += v20;
						if (v9 >= 0) {
							v9 += v26;
							v31 += v22;
							goto LABEL_15;
						}
						v9 += v24;
					}
				}
				result = 1;
			} else {
				result = 1;
			}
		}
	}
	return result;
}

//----- (0049E930) --------------------------------------------------------
int __cdecl sub_49E930(int a1) {
	int result;  // eax
	int v2;      // esi
	int v3;      // ecx
	int v4;      // ebx
	int v5;      // edi
	int v6;      // edx
	int v7;      // edi
	int v8;      // eax
	int v9;      // edi
	int v10;     // edx
	__int16 v11; // bx
	_WORD* i;    // edi
	bool v13;    // cc
	int v14;     // edi
	int v15;     // ebx
	__int16 v16; // dx
	int v17;     // [esp+Ch] [ebp-24h]
	int v18;     // [esp+10h] [ebp-20h]
	int v19;     // [esp+14h] [ebp-1Ch]
	int v20;     // [esp+18h] [ebp-18h]
	int v21;     // [esp+1Ch] [ebp-14h]
	int v22;     // [esp+1Ch] [ebp-14h]
	int v23;     // [esp+20h] [ebp-10h]
	int v24;     // [esp+24h] [ebp-Ch]
	int v25;     // [esp+28h] [ebp-8h]
	int v26;     // [esp+2Ch] [ebp-4h]
	int v27;     // [esp+38h] [ebp+8h]
	int v28;     // [esp+38h] [ebp+8h]

	if (ptr_5D4594_3799572->data[13])
		return sub_49EAB0(a1);
	result = sub_49F5B0(&v25, &v23, 0);
	if (result) {
		result = sub_49F5B0(&v26, &v24, a1);
		if (result) {
			if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v26, &v24, &v25, &v23)) {
				v2 = nox_pixbuffer_rows_3798784;
				v3 = v24;
				if (v26 == v25) {
					(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798712)(v26, v24, v23);
				} else if (v24 == v23) {
					(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(v26, v24, v25);
				} else {
					v4 = v25 - v26;
					v5 = 2;
					if (v25 < v26) {
						v5 = -2;
						v4 = v26 - v25;
					}
					v17 = v5;
					v18 = v4;
					v6 = v23 - v24;
					v7 = 1;
					if (v23 < v24) {
						v7 = -1;
						v6 = v24 - v23;
					}
					v19 = v7;
					v20 = v6;
					v8 = 2 * v26;
					if (v4 < v6) {
						v14 = v4;
						v22 = 2 * v4;
						v15 = 2 * v4 - v6;
						v28 = 2 * (v14 - v6);
						v16 = *(_WORD*)(&obj_5D4594_3800716.data[61]);
						while (1) {
							*(_WORD*)(v8 + *(_DWORD*)(v2 + 4 * v3)) = v16;
							v13 = v20-- < 1;
							if (v13)
								break;
							v3 += v19;
							if (v15 >= 0) {
								v15 += v28;
								v8 += v17;
							} else {
								v15 += v22;
							}
						}
					} else {
						v9 = v6;
						v21 = 2 * v6;
						v10 = 2 * v6 - v4;
						v27 = 2 * (v9 - v4);
						v11 = *(_WORD*)(&obj_5D4594_3800716.data[61]);
					LABEL_18:
						for (i = (_WORD*)(v8 + *(_DWORD*)(v2 + 4 * v3));; i = (_WORD*)((char*)i + v17)) {
							*i = v11;
							v13 = v18-- < 1;
							if (v13)
								break;
							v8 += v17;
							if (v10 >= 0) {
								v10 += v27;
								v3 += v19;
								goto LABEL_18;
							}
							v10 += v21;
						}
					}
				}
			}
			result = 1;
		}
	}
	return result;
}

//----- (0049EAB0) --------------------------------------------------------
int __cdecl sub_49EAB0(int a1) {
	int result;   // eax
	int v2;       // esi
	int v3;       // ebx
	int v4;       // edi
	int v5;       // edx
	int v6;       // edi
	int v7;       // edi
	int v8;       // edx
	__int16* i;   // edi
	__int16 v10;  // ax
	bool v11;     // cc
	int v12;      // edi
	int v13;      // ebx
	__int16* v14; // edi
	__int16 v15;  // ax
	int v16;      // [esp+0h] [ebp-38h]
	int v17;      // [esp+4h] [ebp-34h]
	int v18;      // [esp+8h] [ebp-30h]
	int v19;      // [esp+Ch] [ebp-2Ch]
	int v20;      // [esp+10h] [ebp-28h]
	int v21;      // [esp+14h] [ebp-24h]
	int v22;      // [esp+18h] [ebp-20h]
	int v23;      // [esp+1Ch] [ebp-1Ch]
	int v24;      // [esp+1Ch] [ebp-1Ch]
	int v25;      // [esp+20h] [ebp-18h]
	int v26;      // [esp+20h] [ebp-18h]
	int v27;      // [esp+28h] [ebp-10h]
	int v28;      // [esp+2Ch] [ebp-Ch]
	int v29;      // [esp+30h] [ebp-8h]
	int v30;      // [esp+34h] [ebp-4h]

	result = sub_49F5B0(&v28, &v27, 0);
	if (result) {
		result = sub_49F5B0(&v29, &v30, a1);
		if (result) {
			if (!ptr_5D4594_3799572->data[0] || sub_49F990(&v29, &v30, &v28, &v27)) {
				v16 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *(_WORD*)(&obj_5D4594_3800716.data[61])) >>
					  byte_5D4594[3804376];
				v17 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *(_WORD*)(&obj_5D4594_3800716.data[61])) >>
					  byte_5D4594[3804380];
				v18 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804372] & *(_WORD*)(&obj_5D4594_3800716.data[61]))
					  << byte_5D4594[3804384];
				v2 = nox_pixbuffer_rows_3798784;
				v3 = v28 - v29;
				v4 = 2;
				if (v28 < v29) {
					v4 = -2;
					v3 = v29 - v28;
				}
				v19 = v4;
				v5 = v27 - v30;
				v20 = v3;
				v6 = 1;
				if (v27 < v30) {
					v6 = -1;
					v5 = v30 - v27;
				}
				v21 = v6;
				v22 = v5;
				v29 *= 2;
				if (v3 < v5) {
					v12 = v3;
					v24 = 2 * v3;
					v13 = 2 * v3 - v5;
					v26 = 2 * (v12 - v5);
					while (1) {
						v14 = (__int16*)(v29 + *(_DWORD*)(v2 + 4 * v30));
						v15 = *v14;
						*v14 =
							*(_WORD*)(dword_5d4594_3804656 +
									  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716
																							   .data[259]) *
																				(v17 -
																				 ((unsigned __int16)(*(_WORD*)&byte_5D4594
																										 [3804368] &
																									 v15) >>
																				  byte_5D4594[3804380]))) >>
															 8) +
															((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & v15) >>
															 byte_5D4594[3804380]))) |
							*(_WORD*)(dword_5d4594_3804672 +
									  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716
																							   .data[259]) *
																				(v16 -
																				 ((unsigned __int16)(*(_WORD*)&byte_5D4594
																										 [3804364] &
																									 v15) >>
																				  byte_5D4594[3804376]))) >>
															 8) +
															((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & v15) >>
															 byte_5D4594[3804376]))) |
							*(_WORD*)(dword_5d4594_3804664 +
									  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716
																							   .data[259]) *
																				(v18 -
																				 ((unsigned __int16)(*(_WORD*)&byte_5D4594
																										 [3804372] &
																									 v15)
																				  << byte_5D4594[3804384]))) >>
															 8) +
															((unsigned __int16)(*(_WORD*)&byte_5D4594[3804372] & v15)
															 << byte_5D4594[3804384])));
						v11 = v22-- < 1;
						if (v11)
							break;
						v30 += v21;
						if (v13 >= 0) {
							v13 += v26;
							v29 += v19;
						} else {
							v13 += v24;
						}
					}
				} else {
					v7 = v5;
					v23 = 2 * v5;
					v8 = 2 * v5 - v3;
					v25 = 2 * (v7 - v3);
				LABEL_15:
					for (i = (__int16*)(v29 + *(_DWORD*)(v2 + 4 * v30));; i = (__int16*)((char*)i + v19)) {
						v10 = *i;
						*i =
							*(_WORD*)(dword_5d4594_3804656 +
									  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716
																							   .data[259]) *
																				(v17 -
																				 ((unsigned __int16)(*(_WORD*)&byte_5D4594
																										 [3804368] &
																									 v10) >>
																				  byte_5D4594[3804380]))) >>
															 8) +
															((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & v10) >>
															 byte_5D4594[3804380]))) |
							*(_WORD*)(dword_5d4594_3804672 +
									  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716
																							   .data[259]) *
																				(v16 -
																				 ((unsigned __int16)(*(_WORD*)&byte_5D4594
																										 [3804364] &
																									 v10) >>
																				  byte_5D4594[3804376]))) >>
															 8) +
															((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & v10) >>
															 byte_5D4594[3804376]))) |
							*(_WORD*)(dword_5d4594_3804664 +
									  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)(&obj_5D4594_3800716
																							   .data[259]) *
																				(v18 -
																				 ((unsigned __int16)(*(_WORD*)&byte_5D4594
																										 [3804372] &
																									 v10)
																				  << byte_5D4594[3804384]))) >>
															 8) +
															((unsigned __int16)(*(_WORD*)&byte_5D4594[3804372] & v10)
															 << byte_5D4594[3804384])));
						v11 = v20-- < 1;
						if (v11)
							break;
						v29 += v19;
						if (v8 >= 0) {
							v8 += v25;
							v30 += v21;
							goto LABEL_15;
						}
						v8 += v23;
					}
				}
				result = 1;
			} else {
				result = 1;
			}
		}
	}
	return result;
}

//----- (0049ED80) --------------------------------------------------------
int __cdecl sub_49ED80(unsigned __int8 a1, int a2) {
	int result; // eax
	int v3;     // edi
	int v4;     // esi
	int* v5;    // ebp
	int v6;     // esi
	int v7;     // ebx
	int v8;     // ecx
	int v9;     // edi
	int v10;    // edi
	int v11;    // ecx
	int v12;    // edi
	int v13;    // ebx
	int v14;    // eax
	int v15;    // esi
	int v16;    // esi
	int v17;    // ecx
	int v18;    // [esp+0h] [ebp-1Ch]
	int v19;    // [esp+4h] [ebp-18h]
	int v20;    // [esp+8h] [ebp-14h]
	int v21;    // [esp+Ch] [ebp-10h]
	int v22;    // [esp+10h] [ebp-Ch]
	int v23;    // [esp+14h] [ebp-8h]
	int v24;    // [esp+18h] [ebp-4h]
	int v25;    // [esp+20h] [ebp+4h]
	int v26;    // [esp+20h] [ebp+4h]
	int v27;    // [esp+24h] [ebp+8h]

	if (ptr_5D4594_3799572->data[13])
		return sub_49EAB0(a2);
	result = sub_49F5B0(&v22, &v23, 0);
	if (result) {
		result = sub_49F5B0(&v19, &v18, a2);
		if (result) {
			if (ptr_5D4594_3799572->data[0] && !sub_49F990(&v19, &v18, &v22, &v23))
				return 1;
			v3 = v22 - v19;
			v4 = v23 - v18;
			if (v19 <= v22) {
				v21 = v19 != v22;
			} else {
				v21 = -1;
				v3 = v19 - v22;
			}
			if (v18 <= v23) {
				v20 = v18 != v23;
			} else {
				v20 = -1;
				v4 = v18 - v23;
			}
			v5 = sub_4B0680(0, a1);
			v27 = 0;
			v24 = *v5 >> 2;
			if (v3 <= v4) {
				v26 = 2 * v3;
				v12 = 2 * (v3 - v4);
				v13 = v26 - v4;
				sub_4B0820((int)v5, v19, v18);
				v14 = v4;
				v15 = v4 - 1;
				if (v14) {
					v16 = v15 + 1;
					do {
						v17 = v20 + v18;
						v18 += v20;
						if (v13 >= 0) {
							v13 += v12;
							v19 += v21;
						} else {
							v13 += v26;
						}
						if (++v27 >= v24) {
							sub_4B0820((int)v5, v19, v17);
							v27 = 0;
						}
						--v16;
					} while (v16);
				}
			} else {
				v25 = 2 * v4;
				v6 = 2 * (v4 - v3);
				v7 = v25 - v3;
				sub_4B0820((int)v5, v19, v18);
				v8 = v3;
				v9 = v3 - 1;
				if (v8) {
					v10 = v9 + 1;
					do {
						v11 = v21 + v19;
						v19 += v21;
						if (v7 >= 0) {
							v7 += v6;
							v18 += v20;
						} else {
							v7 += v25;
						}
						if (++v27 >= v24) {
							sub_4B0820((int)v5, v11, v18);
							v27 = 0;
						}
						--v10;
					} while (v10);
					return 1;
				}
			}
			return 1;
		}
	}
	return result;
}

//----- (0049EFA0) --------------------------------------------------------
int __cdecl sub_49EFA0(int a1, int a2) { return (*(int(__cdecl**)(_DWORD, _DWORD)) & byte_5D4594[3798700])(a1, a2); }

//----- (0049EFC0) --------------------------------------------------------
int __cdecl sub_49EFC0(int a1, int a2) {
	int result; // eax

	result = a1;
	if (!ptr_5D4594_3799572->data[0] || a1 <= ptr_5D4594_3799572->data[7] && a1 >= ptr_5D4594_3799572->data[5] &&
											a2 >= ptr_5D4594_3799572->data[6] && a2 <= ptr_5D4594_3799572->data[8]) {
		nox_pixbuffer_rows_3798784[a2][a1] = ptr_5D4594_3799572->data[61];
	}
	return result;
}

//----- (0049F010) --------------------------------------------------------
int __cdecl sub_49F010(int a1, int a2) {
	int result; // eax

	result = a1;
	if (!ptr_5D4594_3799572->data[0] || a1 <= ptr_5D4594_3799572->data[7] && a1 >= ptr_5D4594_3799572->data[5] &&
											a2 >= ptr_5D4594_3799572->data[6] && a2 <= ptr_5D4594_3799572->data[8]) {
		*(_WORD*)(a1 + a1 + (_DWORD)nox_pixbuffer_rows_3798784[a2]) = ptr_5D4594_3799572->data[61];
	}
	return result;
}

//----- (0049F060) --------------------------------------------------------
void __cdecl sub_49F060(int a1, int a2, int a3) {
	int v3;           // ecx
	int v4;           // edx
	int v5;           // edi
	int v6;           // esi
	int v7;           // ecx
	unsigned int v9;  // ecx
	int v10;          // eax
	char* v11;        // edi
	char v12;         // bl
	unsigned int v13; // ecx
	char* v14;        // edi
	int v15;          // ebx
	int v16;          // ebx

	v3 = a3;
	v4 = a1;
	if (a1 > a3) {
		v4 = a3;
		v3 = a1;
	}
	if (ptr_5D4594_3799572->data[0]) {
		v5 = ptr_5D4594_3799572->data[7];
		if (v4 > v5)
			return;
		v6 = ptr_5D4594_3799572->data[5];
		if (v3 < v6 || a2 < (int)ptr_5D4594_3799572->data[6] || a2 > (int)ptr_5D4594_3799572->data[8]) {
			return;
		}
		if (v4 < v6)
			v4 = ptr_5D4594_3799572->data[5];
		if (v3 > v5)
			v3 = ptr_5D4594_3799572->data[7];
	}
	v7 = v3 - v4;
	v9 = v7 + 1;
	if ((int)v9 > 0) {
		v10 = ptr_5D4594_3799572->data[61];
		v11 = (char*)(v4 + (_DWORD)nox_pixbuffer_rows_3798784[a2]);
		v12 = v9;
		v13 = v9 >> 2;
		memset32(v11, v10, v13);
		v14 = &v11[4 * v13];
		v15 = v12 & 3;
		if (v15) {
			*v14 = v10;
			v16 = v15 - 1;
			if (v16) {
				v14[1] = v10;
				if (v16 != 1)
					v14[2] = v10;
			}
		}
	}
}

//----- (0049F0F0) --------------------------------------------------------
unsigned __int8* __cdecl sub_49F0F0(int a1, int a2, int a3) {
	int v3;                  // ecx
	int v4;                  // esi
	int v5;                  // edx
	unsigned __int8* result; // eax
	int v7;                  // edx
	int v8;                  // ecx
	int v9;                  // esi
	int v10;                 // ecx
	unsigned __int8 v11;     // [esp+10h] [ebp+4h]

	v3 = a1;
	v4 = a3;
	if (a1 > a3) {
		v3 = a3;
		v4 = a1;
	}
	if (ptr_5D4594_3799572->data[0]) {
		v5 = ptr_5D4594_3799572->data[7];
		result = *(unsigned __int8**)(&ptr_5D4594_3799572->data[5]);
		if (v3 > v5 || v4 < (int)result || a2 < (int)ptr_5D4594_3799572->data[6] ||
			a2 > (int)ptr_5D4594_3799572->data[8]) {
			return result;
		}
		if (v3 < (int)result)
			v3 = ptr_5D4594_3799572->data[5];
		if (v4 > v5)
			v4 = ptr_5D4594_3799572->data[7];
	}
	v7 = v3;
	result = (unsigned __int8*)(v3 + (_DWORD)nox_pixbuffer_rows_3798784[a2]);
	v8 = v3 + 1;
	if (v7 <= v4) {
		v11 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
		v9 = v4 - v8 + 2;
		do {
			v10 = *result++ << 8;
			--v9;
			*(result - 1) = *(_BYTE*)(v11 + v10 + dword_5d4594_810632);
		} while (v9);
	}
	return result;
}

//----- (0049F180) --------------------------------------------------------
void __cdecl sub_49F180(int a1, int a2, int a3) {
	int v3;          // ecx
	int v4;          // edx
	int v5;          // edi
	int v6;          // esi
	int v7;          // ecx
	char v8;         // cc
	unsigned int v9; // ecx
	int v10;         // eax
	int v11;         // edi
	char v12;        // cf
	int v13;         // ecx

	v3 = a3;
	v4 = a1;
	if (a1 > a3) {
		v4 = a3;
		v3 = a1;
	}
	if (ptr_5D4594_3799572->data[0]) {
		v5 = ptr_5D4594_3799572->data[7];
		if (v4 > v5)
			return;
		v6 = ptr_5D4594_3799572->data[5];
		if (v3 < v6 || a2 < (int)ptr_5D4594_3799572->data[6] || a2 > (int)ptr_5D4594_3799572->data[8]) {
			return;
		}
		if (v4 < v6)
			v4 = ptr_5D4594_3799572->data[5];
		if (v3 > v5)
			v3 = ptr_5D4594_3799572->data[7];
	}
	v7 = v3 - v4;
	v9 = v7 + 1;
	if ((int)v9 > 0) {
		v10 = ptr_5D4594_3799572->data[61];
		v11 = (_DWORD)nox_pixbuffer_rows_3798784[a2] + 2 * v4;
		if (!(v11 & 2) || (*(_WORD*)v11 = v10, v11 += 2, --v9, v9)) {
			v12 = v9 & 1;
			v13 = v9 >> 1;
			if (v13) {
				do {
					*(_DWORD*)v11 = v10;
					v11 += 4;
					v8 = v13-- <= 1;
				} while (!v8);
			}
			if (v12)
				*(_WORD*)v11 = v10;
		}
	}
}

__int16 __cdecl sub_49F210(int a1, int a2, int a3) {
	DebugBreak();
	return 0;
}
#if 0
//----- (0049F210) --------------------------------------------------------
__int16 __cdecl sub_49F210(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // eax
    int v6; // edi
    int v7; // esi
    int v8; // ecx
    int v9; // ecx
    __m64 v10; // mm4
    __m64 v11; // mm4
    __m64 v12; // mm5
    __m64 v13; // mm6
    __m64* v14; // edi
    __m64 v15; // mm4
    __m64 v16; // mm0
    __m64 v17; // mm1
    __m64 v18; // mm2
    __m64 v19; // mm0
    char v20; // cc
    _WORD* v21; // edi
    int v22; // ecx
    _WORD* v23; // edi
    __m64 v25; // [esp+Ch] [ebp-8h]

    v3 = a3;
    v4 = a1;
    if (a1 > a3)
    {
        LOWORD(v5) = a1;
        v4 = a3;
        v3 = a1;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v6 = ptr_5D4594_3799572->data[7];
        if (v4 > v6)
            return v5;
        v7 = ptr_5D4594_3799572->data[5];
        if (v3 < v7)
            return v5;
        v5 = ptr_5D4594_3799572->data[6];
        if (a2 < v5)
            return v5;
        v5 = ptr_5D4594_3799572->data[8];
        if (a2 > v5)
            return v5;
        if (v4 < v7)
            v4 = ptr_5D4594_3799572->data[5];
        if (v3 > v6)
            v3 = ptr_5D4594_3799572->data[7];
    }
    v8 = v3 - v4;
    v20 = (v8 + 1 < 0) ^ __OFADD__(1, v8) | (v8 == -1);
    v9 = v8 + 1;
    if (!v20)
    {
        v10 = _mm_cvtsi32_si64(ptr_5D4594_3799572->data[61]);
        v11 = _m_por(_m_psllqi(v10, 0x20u), v10);
        v12 = _m_psrlw(_m_pand(v11, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
        v13 = _m_psllw(_m_pand(v11, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
        v14 = (__m64*)(*(_DWORD*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2) + 2 * v4);
        v15 = _m_psrlw(_m_pand(v11, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
        while (1)
        {
            v16 = _m_psrlw(_m_pand((__m64)v14->m64_u64, *(__m64*) & byte_5D4594[3804396]), *(__m64*) & byte_5D4594[3804444]);
            v17 = _m_psrlw(_m_pand((__m64)v14->m64_u64, *(__m64*) & byte_5D4594[3804404]), *(__m64*) & byte_5D4594[3804452]);
            v18 = _m_psllw(_m_pand((__m64)v14->m64_u64, *(__m64*) & byte_5D4594[3804412]), *(__m64*) & byte_5D4594[3804460]);
            v19 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(_m_paddw(v16, _m_psrlwi(_m_psubw(v15, v16), 1u)), *(__m64*) & byte_5D4594[3804444]),
                        *(__m64*) & byte_5D4594[3804396]),
                    _m_pand(
                        _m_psllw(_m_paddw(v17, _m_psrlwi(_m_psubw(v12, v17), 1u)), *(__m64*) & byte_5D4594[3804452]),
                        *(__m64*) & byte_5D4594[3804404])),
                _m_psrlw(_m_paddw(v18, _m_psrlwi(_m_psubw(v13, v18), 1u)), *(__m64*) & byte_5D4594[3804460]));
            v20 = v9 < 4;
            v9 -= 4;
            if (v20)
                break;
            v14->m64_u64 = (unsigned __int64)v19;
            ++v14;
            if (v20)
                goto LABEL_20;
        }
        v25 = v19;
        LOWORD(v5) = v25.m64_i16[0];
        LOWORD(v14->m64_i32[0]) = v25.m64_i16[0];
        v21 = (_WORD*)((char*)v14->m64_i32 + 2);
        v22 = v9 + 3;
        if (v22)
        {
            LOWORD(v5) = v25.m64_i16[1];
            *v21 = v25.m64_i16[1];
            v23 = v21 + 1;
            if (v22 != 1)
            {
                LOWORD(v5) = v25.m64_i16[2];
                *v23 = v25.m64_i16[2];
            }
        }
    }
LABEL_20:
    _m_femms();
    return v5;
}
#endif
//----- (0049F3A0) --------------------------------------------------------
void __cdecl sub_49F3A0(int a1, int a2, int a3) {
	int v3;      // ecx
	int v4;      // edx
	int v5;      // edi
	int v6;      // esi
	int v7;      // ecx
	char v8;     // cc
	int v9;      // ecx
	char v10;    // al
	_DWORD* v11; // esi
	_BYTE* v12;  // edi

	v3 = a3;
	v4 = a2;
	if (a2 > a3) {
		v4 = a3;
		v3 = a2;
	}
	if (ptr_5D4594_3799572->data[0]) {
		v5 = ptr_5D4594_3799572->data[8];
		if (v4 > v5)
			return;
		v6 = ptr_5D4594_3799572->data[6];
		if (v3 < v6 || a1 < (int)ptr_5D4594_3799572->data[5] || a1 > (int)ptr_5D4594_3799572->data[7]) {
			return;
		}
		if (v4 < v6)
			v4 = ptr_5D4594_3799572->data[6];
		if (v3 > v5)
			v3 = ptr_5D4594_3799572->data[8];
	}
	v7 = v3 - v4;
	v9 = v7 + 1;
	if ((int)v9 > 0) {
		v10 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
		v11 = &nox_pixbuffer_rows_3798784[v4];
		do {
			v12 = (_BYTE*)(a1 + *v11);
			++v11;
			*v12 = v10;
			v8 = v9-- <= 1;
		} while (!v8);
	}
}

//----- (0049F420) --------------------------------------------------------
void __cdecl sub_49F420(int a1, int a2, int a3) {
	int v3;      // ecx
	int v4;      // edx
	int v5;      // edi
	int v6;      // esi
	int v7;      // ecx
	char v8;     // cc
	int v9;      // ecx
	__int16 v10; // ax
	_DWORD* v11; // esi
	_WORD* v12;  // edi

	v3 = a3;
	v4 = a2;
	if (a2 > a3) {
		v4 = a3;
		v3 = a2;
	}
	if (ptr_5D4594_3799572->data[0]) {
		v5 = ptr_5D4594_3799572->data[8];
		if (v4 > v5)
			return;
		v6 = ptr_5D4594_3799572->data[6];
		if (v3 < v6 || a1 < (int)ptr_5D4594_3799572->data[5] || a1 > (int)ptr_5D4594_3799572->data[7]) {
			return;
		}
		if (v4 < v6)
			v4 = ptr_5D4594_3799572->data[6];
		if (v3 > v5)
			v3 = ptr_5D4594_3799572->data[8];
	}
	v7 = v3 - v4;
	v9 = v7 + 1;
	if ((int)v9 > 0) {
		v10 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
		v11 = &nox_pixbuffer_rows_3798784[v4];
		do {
			v12 = (_WORD*)(2 * a1 + *v11);
			++v11;
			*v12 = v10;
			v8 = v9-- <= 1;
		} while (!v8);
	}
}

//----- (0049F4A0) --------------------------------------------------------
BOOL sub_49F4A0() {
	dword_5d4594_1305724 = 32;
	*(_DWORD*)&byte_5D4594[3798692] = 0;
	dword_5d4594_3798696 = nox_calloc(0x20u, 8u);
	return dword_5d4594_3798696 != 0;
}

//----- (0049F4D0) --------------------------------------------------------
void sub_49F4D0() {
	if (dword_5d4594_3798696) {
		free(*(LPVOID*)&dword_5d4594_3798696);
		dword_5d4594_3798696 = 0;
		*(_DWORD*)&byte_5D4594[3798692] = 0;
	}
}

//----- (0049F500) --------------------------------------------------------
int __cdecl nox_client_drawAddPoint_49F500(int a1, int a2) {
	if (*(_DWORD*)&byte_5D4594[3798692] >= *(int*)&dword_5d4594_1305724) {
		dword_5d4594_1305724 += 16;
		dword_5d4594_3798696 = realloc(*(LPVOID*)&dword_5d4594_3798696, 8 * dword_5d4594_1305724);
	}
	*(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692]) = a1;
	*(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] + 4) = a2;
	return ++*(_DWORD*)&byte_5D4594[3798692];
}

//----- (0049F570) --------------------------------------------------------
int __cdecl sub_49F570(int a1, int a2) {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[3798692];
	if (*(_DWORD*)&byte_5D4594[3798692])
		result = nox_client_drawAddPoint_49F500(
			a1 + *(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] - 8),
			a2 + *(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] - 4));
	return result;
}

//----- (0049F5B0) --------------------------------------------------------
int __cdecl sub_49F5B0(_DWORD* a1, _DWORD* a2, int a3) {
	int v3; // ecx

	if (*(int*)&byte_5D4594[3798692] <= 0)
		return 0;
	v3 = --*(_DWORD*)&byte_5D4594[3798692];
	if (a1)
		*a1 = *(_DWORD*)(dword_5d4594_3798696 + 8 * v3);
	if (a2)
		*a2 = *(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] + 4);
	if (a3)
		++*(_DWORD*)&byte_5D4594[3798692];
	return 1;
}

//----- (0049F610) --------------------------------------------------------
int sub_49F610() {
	ptr_5D4594_3799572->data[0] = 0;
	ptr_5D4594_3799572->data[9] = 0;
	ptr_5D4594_3799572->data[1] = 0;
	ptr_5D4594_3799572->data[10] = 0;
	ptr_5D4594_3799572->data[2] = 0;
	ptr_5D4594_3799572->data[11] = nox_backbuffer_width;
	ptr_5D4594_3799572->data[3] = nox_backbuffer_width;
	ptr_5D4594_3799572->data[12] = nox_backbuffer_height;
	ptr_5D4594_3799572->data[4] = nox_backbuffer_height;
	ptr_5D4594_3799572->data[5] = 0;
	ptr_5D4594_3799572->data[6] = 0;
	ptr_5D4594_3799572->data[7] = nox_backbuffer_width - 1;
	ptr_5D4594_3799572->data[8] = nox_backbuffer_height - 1;
	dword_5d4594_1305748 = 0;
	return 1;
}

//----- (0049F6D0) --------------------------------------------------------
int __cdecl sub_49F6D0(int a1) {
	int result; // eax

	result = ptr_5D4594_3799572->data[0];
	ptr_5D4594_3799572->data[0] = a1;
	return result;
}

//----- (0049F6E0) --------------------------------------------------------
int sub_49F6E0() { return ptr_5D4594_3799572->data[0]; }

//----- (0049F6F0) --------------------------------------------------------
int4* __cdecl nox_client_copyRect_49F6F0(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rcSrc;   // [esp+0h] [ebp-20h]
	RECT rc;      // [esp+10h] [ebp-10h]

	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = sub_49F930((int4*)&rcSrc, (int4*)&rc, (int4*)(&ptr_5D4594_3799572->data[9]));
	if (result) {
		CopyRect((LPRECT)(&ptr_5D4594_3799572->data[1]), &rcSrc);
		--rcSrc.right;
		--rcSrc.bottom;
		result = (int4*)CopyRect((LPRECT)(&ptr_5D4594_3799572->data[5]), &rcSrc);
	}
	return result;
}

//----- (0049F780) --------------------------------------------------------
int4* __cdecl sub_49F780(int xLeft, int a2) {
	int v2; // esi
	int v3; // eax

	v2 = xLeft;
	if (xLeft < (int)ptr_5D4594_3799572->data[1])
		v2 = ptr_5D4594_3799572->data[1];
	v3 = a2;
	if (a2 > (int)ptr_5D4594_3799572->data[3])
		v3 = ptr_5D4594_3799572->data[3];
	return nox_client_copyRect_49F6F0(v2, ptr_5D4594_3799572->data[2], v3 - v2,
									  ptr_5D4594_3799572->data[4] - ptr_5D4594_3799572->data[2]);
}

//----- (0049F7C0) --------------------------------------------------------
int4* __cdecl sub_49F7C0(int a1) {
	int v1; // eax

	v1 = a1;
	if (a1 > (int)ptr_5D4594_3799572->data[4])
		v1 = ptr_5D4594_3799572->data[4];
	return nox_client_copyRect_49F6F0(ptr_5D4594_3799572->data[1], ptr_5D4594_3799572->data[2],
									  ptr_5D4594_3799572->data[3] - ptr_5D4594_3799572->data[1],
									  v1 - ptr_5D4594_3799572->data[2]);
}

//----- (0049F7F0) --------------------------------------------------------
int sub_49F7F0() {
	int result; // eax
	int v1;     // edx

	result = dword_5d4594_1305748;
	if (!dword_5d4594_1305748) {
		*(_DWORD*)&byte_5D4594[1305772] = ptr_5D4594_3799572->data[0];
		result = (_DWORD)(&ptr_5D4594_3799572->data[5]);
		*(_DWORD*)&byte_5D4594[1305756] = ptr_5D4594_3799572->data[1];
		*(_DWORD*)&byte_5D4594[1305760] = ptr_5D4594_3799572->data[2];
		*(_DWORD*)&byte_5D4594[1305764] = ptr_5D4594_3799572->data[3];
		*(_DWORD*)&byte_5D4594[1305768] = ptr_5D4594_3799572->data[4];
		*(_DWORD*)&byte_5D4594[1305732] = ptr_5D4594_3799572->data[5];
		*(_DWORD*)&byte_5D4594[1305736] = ptr_5D4594_3799572->data[6];
		*(_DWORD*)&byte_5D4594[1305740] = ptr_5D4594_3799572->data[7];
		v1 = ptr_5D4594_3799572->data[8];
		dword_5d4594_1305748 = 1;
		*(_DWORD*)&byte_5D4594[1305744] = v1;
	}
	return result;
}

//----- (0049F860) --------------------------------------------------------
int sub_49F860() {
	int result; // eax
	_DWORD* v1; // edx
	_DWORD* v2; // edx

	result = dword_5d4594_1305748;
	if (dword_5d4594_1305748) {
		ptr_5D4594_3799572->data[0] = *(_DWORD*)&byte_5D4594[1305772];
		v1 = &ptr_5D4594_3799572->data[1];
		ptr_5D4594_3799572->data[1] = *(_DWORD*)&byte_5D4594[1305756];
		v1[1] = *(_DWORD*)&byte_5D4594[1305760];
		v1[2] = *(_DWORD*)&byte_5D4594[1305764];
		v1[3] = *(_DWORD*)&byte_5D4594[1305768];
		v2 = &ptr_5D4594_3799572->data[5];
		ptr_5D4594_3799572->data[5] = *(_DWORD*)&byte_5D4594[1305732];
		v2[1] = *(_DWORD*)&byte_5D4594[1305736];
		result = *(_DWORD*)&byte_5D4594[1305740];
		v2[2] = *(_DWORD*)&byte_5D4594[1305740];
		v2[3] = *(_DWORD*)&byte_5D4594[1305744];
		dword_5d4594_1305748 = 0;
	}
	return result;
}

//----- (0049F8E0) --------------------------------------------------------
BOOL __cdecl sub_49F8E0(int a1, int a2, int a3) {
	return a1 - a3 < (int)ptr_5D4594_3799572->data[1] || a3 + a1 >= (int)ptr_5D4594_3799572->data[3] ||
		   a2 - a3 < (int)ptr_5D4594_3799572->data[2] || a3 + a2 >= (int)ptr_5D4594_3799572->data[4];
}

//----- (0049F930) --------------------------------------------------------
int4* __cdecl sub_49F930(int4* a1, int4* a2, int4* a3) {
	int v3;       // ecx
	int v4;       // edx
	int v5;       // ebx
	int v6;       // edi
	int4* result; // eax

	v3 = a3->field_0;
	if (a2->field_0 >= a3->field_0)
		v3 = a2->field_0;
	v4 = a3->field_8;
	if (a2->field_8 <= v4)
		v4 = a2->field_8;
	if (v3 >= v4)
		return 0;
	v5 = a3->field_4;
	if (a2->field_4 >= v5)
		v5 = a2->field_4;
	v6 = a3->field_C;
	if (a2->field_C <= v6)
		v6 = a2->field_C;
	if (v5 >= v6)
		return 0;
	result = a1;
	a1->field_0 = v3;
	a1->field_4 = v5;
	a1->field_8 = v4;
	a1->field_C = v6;
	return result;
}

//----- (0049F990) --------------------------------------------------------
int __cdecl sub_49F990(int* a1, int* a2, int* a3, int* a4) {
	int v4;  // ebx
	int v5;  // edi
	int v6;  // esi
	int v7;  // ecx
	int v8;  // ebp
	int v9;  // eax
	int v10; // edx
	int v12; // eax
	int v13; // eax
	int v14; // edx
	int v15; // eax
	int v16; // eax
	int v17; // eax
	int v18; // edx
	int v19; // eax
	int v20; // [esp+10h] [ebp-14h]
	int v21; // [esp+10h] [ebp-14h]
	int v22; // [esp+14h] [ebp-10h]
	int v23; // [esp+18h] [ebp-Ch]
	int v24; // [esp+1Ch] [ebp-8h]
	int v25; // [esp+20h] [ebp-4h]

	v4 = ptr_5D4594_3799572->data[5];
	v24 = ptr_5D4594_3799572->data[8];
	v23 = ptr_5D4594_3799572->data[6];
	v5 = *a2;
	v25 = ptr_5D4594_3799572->data[7];
	v6 = *a3;
	v7 = *a1;
	v8 = *a4;
	v9 = 0;
	if (*a1 >= v4) {
		if (v7 > (int)ptr_5D4594_3799572->data[7])
			v9 = 2;
	} else {
		v9 = 1;
	}
	if (v5 >= v23) {
		if (v5 > v24)
			LOBYTE(v9) = v9 | 4;
	} else {
		LOBYTE(v9) = v9 | 8;
	}
	v22 = 0;
	if (v6 >= v4) {
		if (v6 > v25)
			v22 = 2;
	} else {
		v22 = 1;
	}
	if (v8 >= v23) {
		if (v8 <= v24)
			goto LABEL_18;
		v10 = v22 | 4;
	} else {
		v10 = v22 | 8;
	}
	v22 = v10;
LABEL_18:
	if (!(v9 | v22))
		return 1;
	if (v9 & v22)
		return 0;
	if (v9) {
		if (v9 & 8) {
			if (v8 == v5)
				return 0;
			v12 = (v23 - v5) * (v6 - v7) / (v8 - v5);
			v5 = ptr_5D4594_3799572->data[6];
			v7 += v12;
		} else if (v9 & 4) {
			if (v8 == v5)
				return 0;
			v13 = (v24 - v5) * (v6 - v7) / (v8 - v5);
			v5 = ptr_5D4594_3799572->data[8];
			v7 += v13;
		}
		if (v7 <= v25) {
			if (v7 < v4) {
				if (v6 == v7)
					return 0;
				v15 = (v4 - v7) * (v8 - v5) / (v6 - v7);
				v7 = ptr_5D4594_3799572->data[5];
				v5 += v15;
			}
		} else {
			v20 = v6 - v7;
			if (v6 == v7)
				return 0;
			v14 = v25 - v7;
			v7 = ptr_5D4594_3799572->data[7];
			v5 += v14 * (v8 - v5) / v20;
		}
	}
	if (v22) {
		if (v22 & 8) {
			if (v8 == v5)
				return 0;
			v16 = (v6 - v7) * (v23 - v8) / (v8 - v5);
			v8 = ptr_5D4594_3799572->data[6];
			v6 += v16;
		} else if (v22 & 4) {
			if (v8 == v5)
				return 0;
			v17 = (v6 - v7) * (v24 - v8) / (v8 - v5);
			v8 = ptr_5D4594_3799572->data[8];
			v6 += v17;
		}
		if (v6 <= v25) {
			if (v6 < v4) {
				if (v6 == v7)
					return 0;
				v19 = (v4 - v6) * (v8 - v5) / (v6 - v7);
				v6 = ptr_5D4594_3799572->data[5];
				v8 += v19;
			}
		} else {
			v21 = v6 - v7;
			if (v6 == v7)
				return 0;
			v18 = v25 - v6;
			v6 = ptr_5D4594_3799572->data[7];
			v8 += v18 * (v8 - v5) / v21;
		}
	}
	*a1 = v7;
	*a2 = v5;
	*a3 = v6;
	*a4 = v8;
	if (v7 >= v4 && v7 <= v25 && v5 >= v23 && v5 <= v24 && v6 >= v4 && v6 <= v25 && v8 >= v23 && v8 <= v24)
		return 1;
	return 0;
}

//----- (0049FC20) --------------------------------------------------------
int __cdecl sub_49FC20(int* a1, int* a2, int* a3, int* a4) {
	int v4;  // ebx
	int v5;  // eax
	int v6;  // ebp
	int v7;  // edi
	int v8;  // ecx
	int v9;  // esi
	int v11; // eax
	int v12; // eax
	int v13; // eax
	int v14; // eax
	int v15; // [esp+10h] [ebp-Ch]
	int v16; // [esp+14h] [ebp-8h]
	int v17; // [esp+18h] [ebp-4h]

	if (ptr_5D4594_3799572->data[0]) {
		v4 = ptr_5D4594_3799572->data[6];
		v5 = ptr_5D4594_3799572->data[8];
		v15 = ptr_5D4594_3799572->data[8];
	} else {
		v4 = 0;
		v5 = nox_backbuffer_height - 1;
		v15 = nox_backbuffer_height - 1;
	}
	v16 = 0;
	v6 = *a1;
	v7 = *a3;
	v8 = *a2;
	v9 = *a4;
	if (*a2 >= v4) {
		if (v8 > v5)
			v16 = 4;
	} else {
		v16 = 8;
	}
	v17 = 0;
	if (v9 >= v4) {
		if (v9 > v5)
			v17 = 4;
	} else {
		v17 = 8;
	}
	if (v17 & v16)
		return 0;
	if (v16) {
		if (v16 & 8) {
			if (v9 == v8)
				return 0;
			v11 = (v4 - v8) * (v7 - v6) / (v9 - v8);
			v8 = v4;
			v6 += v11;
		} else if (v16 & 4) {
			if (v9 == v8)
				return 0;
			v12 = (v15 - v8) * (v7 - v6) / (v9 - v8);
			v8 = v15;
			v6 += v12;
		}
	}
	if (v17) {
		if (v17 & 8) {
			if (v9 == v8)
				return 0;
			v13 = (v7 - v6) * (v4 - v9) / (v9 - v8);
			v9 = v4;
			v7 += v13;
		} else if (v17 & 4) {
			if (v9 == v8)
				return 0;
			v14 = (v7 - v6) * (v15 - v9) / (v9 - v8);
			v9 = v15;
			v7 += v14;
		}
	}
	*a1 = v6;
	*a2 = v8;
	*a3 = v7;
	*a4 = v9;
	return 1;
}

//----- (0049FDB0) --------------------------------------------------------
void __cdecl sub_49FDB0(int a1) {
	unsigned __int8* v1; // ebx
	int j;               // esi
	int v3;              // eax
	unsigned __int8* v4; // ebx
	int i;               // esi
	int v6;              // eax
	int v7;              // [esp+0h] [ebp-90h]
	char v8[140];        // [esp+4h] [ebp-8Ch]

	if (!dword_5d4594_1305788) {
		if (sub_43AF70()) {
			v7 = 0;
			if (*(_DWORD*)&byte_587000[4 * a1 + 166016] > 0) {
				v4 = &byte_587000[80 * a1 + 166032];
				do {
					for (i = 0; i < (char)*v4; ++i) {
						v6 = 8 * (12 * a1 + (char)v4[i + 1]);
						sub_420DA0(*(float*)&byte_587000[v6 + 165360], *(float*)&byte_587000[v6 + 165364]);
					}
					strcpy(&v8[4], *((const char**)v4 + 3));
					sub_4211D0((int)v8);
					sub_4214D0();
					v4 += 16;
					++v7;
				} while (v7 < *(int*)&byte_587000[4 * a1 + 166016]);
			}
		} else {
			v1 = &byte_587000[165744];
			do {
				for (j = 0; j < (char)*v1; ++j) {
					v3 = 8 * (char)v1[j + 1];
					sub_420DA0(*(float*)&byte_587000[v3 + 165104], *(float*)&byte_587000[v3 + 165108]);
				}
				strcpy(&v8[4], *((const char**)v1 + 3));
				sub_4211D0((int)v8);
				sub_4214D0();
				v1 += 16;
			} while ((int)v1 < (int)&byte_587000[166016]);
		}
		dword_5d4594_1305788 = 1;
	}
}

//----- (0049FF20) --------------------------------------------------------
_DWORD* sub_49FF20() {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_1305788;
	if (dword_5d4594_1305788) {
		result = sub_421B10();
		dword_5d4594_1305788 = 0;
	}
	return result;
}

//----- (0049FF40) --------------------------------------------------------
char* __cdecl sub_49FF40(__int16* a1) {
	int v1;       // edx
	struc_19* v2; // eax
	char* result; // eax
	int2 v4;      // [esp+0h] [ebp-8h]

	v1 = a1[1] + 10;
	v4.field_0 = *a1 + 10;
	v4.field_4 = v1;
	v2 = sub_4217B0(&v4, 0);
	if (v2 || (v2 = (struc_19*)sub_421990(&v4, 100.0, 0)) != 0)
		result = (char*)&v2->field_0[1];
	else
		result = *(char**)&byte_587000[165756];
	return result;
}

//----- (0049FFA0) --------------------------------------------------------
int* __cdecl sub_49FFA0(int a1) {
	int* result; // eax
	int* v2;     // esi
	int* v3;     // edi

	if (!*(_DWORD*)&byte_5D4594[1305808])
		sub_425760(&byte_5D4594[1305796]);
	result = sub_425890((int*)&byte_5D4594[1305796]);
	v2 = result;
	if (result) {
		do {
			v3 = sub_4258A0(v2);
			sub_425920((_DWORD**)v2);
			if (a1)
				sub_46C4E0((_DWORD*)v2[7]);
			free(v2);
			v2 = v3;
		} while (v3);
		*(_DWORD*)&byte_5D4594[1305808] = 1;
	} else {
		*(_DWORD*)&byte_5D4594[1305808] = 1;
	}
	return result;
}

//----- (004A0020) --------------------------------------------------------
char* sub_4A0020() { return (char*)&byte_5D4594[1305796]; }

//----- (004A0030) --------------------------------------------------------
int __cdecl sub_4A0030(const void* a1) {
	_DWORD* v1;  // ebx
	int v2;      // esi
	int* v3;     // edi
	int v5;      // ecx
	wchar_t* v6; // ebp
	wchar_t* v7; // eax
	wchar_t* v8; // ebp
	wchar_t* v9; // eax

	v1 = nox_calloc(1u, 0xA9u);
	qmemcpy(v1, a1, 0xA9u);
	v2 = 0;
	switch (dword_587000_166704) {
	case 0:
		if (*(unsigned __int8**)&dword_5d4594_1305800 == &byte_5D4594[1305796])
			return sub_425790((int*)&byte_5D4594[1305796], v1);
		v3 = sub_425890((int*)&byte_5D4594[1305796]);
		if (!v3)
			goto LABEL_6;
		do {
			if (_strcmpi((const char*)v1 + 120, (const char*)v3 + 120) <= 0)
				goto LABEL_24;
			++v2;
			v3 = sub_4258A0(v3);
		} while (v3);
		goto LABEL_6;
	case 1:
		if (*(unsigned __int8**)&dword_5d4594_1305800 == &byte_5D4594[1305796])
			return sub_425790((int*)&byte_5D4594[1305796], v1);
		v3 = sub_425890((int*)&byte_5D4594[1305796]);
		if (!v3)
			goto LABEL_6;
		while (_strcmpi((const char*)v1 + 120, (const char*)v3 + 120) < 0) {
			++v2;
			v3 = sub_4258A0(v3);
			if (!v3)
				goto LABEL_6;
		}
		goto LABEL_24;
	case 2:
		v5 = *((unsigned __int8*)v1 + 103);
		goto LABEL_29;
	case 3:
		v1[2] = 32 - *((unsigned __int8*)v1 + 103);
		return sub_425790((int*)&byte_5D4594[1305796], v1);
	case 4:
		if (*(unsigned __int8**)&dword_5d4594_1305800 == &byte_5D4594[1305796])
			return sub_425790((int*)&byte_5D4594[1305796], v1);
		v6 = sub_43BCB0(*(_WORD*)((char*)v1 + 163));
		v3 = sub_425890((int*)&byte_5D4594[1305796]);
		if (!v3)
			goto LABEL_6;
		while (1) {
			v7 = sub_43BCB0(*(_WORD*)((char*)v3 + 163));
			if (nox_wcscmp(v6, v7) <= 0)
				goto LABEL_24;
			++v2;
			v3 = sub_4258A0(v3);
			if (!v3)
				goto LABEL_6;
		}
	case 5:
		if (*(unsigned __int8**)&dword_5d4594_1305800 == &byte_5D4594[1305796])
			return sub_425790((int*)&byte_5D4594[1305796], v1);
		v8 = sub_43BCB0(*(_WORD*)((char*)v1 + 163));
		v3 = sub_425890((int*)&byte_5D4594[1305796]);
		if (!v3)
			goto LABEL_6;
		break;
	case 6:
		v5 = v1[24];
		goto LABEL_29;
	case 7:
		v1[2] = 1000 - v1[24];
		return sub_425790((int*)&byte_5D4594[1305796], v1);
	case 8:
		v5 = v1[25] & 0x30;
	LABEL_29:
		v1[2] = v5;
		return sub_425790((int*)&byte_5D4594[1305796], v1);
	case 9:
		v1[2] = 48 - (v1[25] & 0x30);
		return sub_425790((int*)&byte_5D4594[1305796], v1);
	default:
		return 0;
	}
	while (1) {
		v9 = sub_43BCB0(*(_WORD*)((char*)v3 + 163));
		if (nox_wcscmp(v8, v9) >= 0)
			break;
		++v2;
		v3 = sub_4258A0(v3);
		if (!v3) {
		LABEL_6:
			sub_4258E0((int)&byte_5D4594[1305796], v1);
			return v2;
		}
	}
LABEL_24:
	sub_4258E0((int)v3, v1);
	return v2;
}

//----- (004A0290) --------------------------------------------------------
int __cdecl sub_4A0290(int a1) {
	int result; // eax

	result = a1 - 10047;
	switch (a1) {
	case 10047:
		result = dword_587000_166704;
		dword_587000_166704 = dword_587000_166704 == 0;
		break;
	case 10048:
		dword_587000_166704 = (dword_587000_166704 == 2) + 2;
		break;
	case 10049:
		result = (dword_587000_166704 == 4) + 4;
		dword_587000_166704 = (dword_587000_166704 == 4) + 4;
		break;
	case 10050:
		dword_587000_166704 = (dword_587000_166704 == 6) + 6;
		break;
	case 10051:
		dword_587000_166704 = (dword_587000_166704 == 8) + 8;
		break;
	default:
		return result;
	}
	return result;
}

//----- (004A0330) --------------------------------------------------------
int __cdecl sub_4A0330(int* a1) {
	int v1; // esi
	int* i; // eax

	v1 = 0;
	for (i = sub_425890((int*)&byte_5D4594[1305796]); i; i = sub_4258A0(i)) {
		if (i == a1)
			break;
		++v1;
	}
	return v1;
}

//----- (004A0360) --------------------------------------------------------
int* sub_4A0360() {
	int* result; // eax
	int* i;      // esi

	result = sub_425890((int*)&byte_5D4594[1305796]);
	for (i = result; result; i = result) {
		sub_43B7C0((int)i);
		result = sub_4258A0(i);
	}
	return result;
}

//----- (004A0390) --------------------------------------------------------
int* sub_4A0390() {
	_DWORD* v0; // ecx
	int* v1;    // esi
	int* v2;    // edi
	int v4[3];  // [esp+0h] [ebp-Ch]
	_DWORD* v5; // [esp+4h] [ebp-8h]

	sub_425760(&v4);
	v0 = *(_DWORD**)&dword_5d4594_1305800;
	v4[0] = *(_DWORD*)&byte_5D4594[1305796];
	v5 = *(_DWORD**)&dword_5d4594_1305800;
	if (*(_DWORD*)&byte_5D4594[1305796]) {
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1305796] + 4) = &v4;
		v0 = v5;
	}
	if (v0)
		*v0 = &v4;
	sub_425760(&byte_5D4594[1305796]);
	v1 = sub_425890(&v4);
	if (v1) {
		do {
			v2 = sub_4258A0(v1);
			sub_4A0030(v1);
			v1 = v2;
		} while (v2);
	}
	return sub_4A0360();
}

//----- (004A0410) --------------------------------------------------------
int __cdecl sub_4A0410(const char* a1, __int16 a2) {
	int* v2; // edi

	v2 = sub_425890((int*)&byte_5D4594[1305796]);
	if (!v2)
		return 1;
	while (strcmp(a1, (const char*)v2 + 12) || a2 != *(_WORD*)((char*)v2 + 109)) {
		v2 = sub_4258A0(v2);
		if (!v2)
			return 1;
	}
	return 0;
}

//----- (004A0490) --------------------------------------------------------
int* __cdecl sub_4A0490(int a1) {
	int* result; // eax

	result = sub_425890((int*)&byte_5D4594[1305796]);
	if (!result)
		return 0;
	while (result[9] != a1) {
		result = sub_4258A0(result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (004A04C0) --------------------------------------------------------
int* __cdecl sub_4A04C0(int a1) {
	int v1;      // esi
	int* result; // eax

	v1 = 0;
	result = sub_425890((int*)&byte_5D4594[1305796]);
	if (!result)
		return 0;
	while (a1 != v1) {
		++v1;
		result = sub_4258A0(result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (004A04F0) --------------------------------------------------------
int* __cdecl sub_4A04F0(char* a1) {
	int* v1; // esi

	v1 = sub_425890((int*)&byte_5D4594[1305796]);
	if (!v1)
		return 0;
	while (_strcmpi((const char*)(v1[8] + 52), a1)) {
		v1 = sub_4258A0(v1);
		if (!v1)
			return 0;
	}
	return v1;
}

//----- (004A0540) --------------------------------------------------------
void __cdecl sub_4A0540(LPVOID lpMem) {
	sub_425920((_DWORD**)lpMem);
	sub_46C4E0(*((_DWORD**)lpMem + 7));
	free(lpMem);
}

//----- (004A0560) --------------------------------------------------------
int sub_4A0560() { return dword_587000_166704; }

//----- (004A0570) --------------------------------------------------------
int __cdecl sub_4A0570(int* a1, char* a2) {
	char* v2; // eax
	char* v3; // eax
	char* v4; // eax
	int v6;   // [esp+0h] [ebp-8h]
	int v7;   // [esp+4h] [ebp-4h]
	int v8;

	v2 = strtok(a2, " \t\n\r");
	v7 = atoi(v2);
	v3 = strtok(0, " \t\n\r");
	v6 = atoi(v3);
	v4 = strtok(0, " \t\n\r");
	v8 = atoi(v4);
	*a1 = sub_4344A0(v7, v6, (int)v8);
	return 1;
}
// 4A05C7: variable 'v7' is possibly undefined
// 4A05C7: variable 'v6' is possibly undefined

//----- (004A05E0) --------------------------------------------------------
int __cdecl sub_4A05E0(int* a1, FILE* a2, char* a3) {
	int result; // eax

	fscanf(a2, "%*s");
	sub_57BBC0(a2, (int)a3, 256);
	if (!strcmp(a3, "TRANSPARENT")) {
		result = 1;
		*a1 = 0x80000000;
	} else {
		sub_4A0570(a1, a3);
		result = 1;
	}
	return result;
}

//----- (004A0650) --------------------------------------------------------
int __cdecl sub_4A0650(int a1, char* a2) {
	if (strcmp(a2, "TRANSPARENT"))
		return sub_4A0570((int*)(a1 + 20), a2);
	*(_DWORD*)(a1 + 20) = 0x80000000;
	return 1;
}

//----- (004A0690) --------------------------------------------------------
int __cdecl sub_4A0690(int a1, char* a2) {
	if (strcmp(a2, "TRANSPARENT"))
		return sub_4A0570((int*)(a1 + 28), a2);
	*(_DWORD*)(a1 + 28) = 0x80000000;
	return 1;
}

//----- (004A06D0) --------------------------------------------------------
int __cdecl sub_4A06D0(int a1, char* a2) {
	if (strcmp(a2, "TRANSPARENT"))
		return sub_4A0570((int*)(a1 + 44), a2);
	*(_DWORD*)(a1 + 44) = 0x80000000;
	return 1;
}

//----- (004A0710) --------------------------------------------------------
int __cdecl sub_4A0710(int a1, char* a2) {
	if (strcmp(a2, "TRANSPARENT"))
		return sub_4A0570((int*)(a1 + 36), a2);
	*(_DWORD*)(a1 + 36) = 0x80000000;
	return 1;
}

//----- (004A0750) --------------------------------------------------------
int __cdecl sub_4A0750(int a1, char* a2) {
	if (strcmp(a2, "TRANSPARENT"))
		return sub_4A0570((int*)(a1 + 52), a2);
	*(_DWORD*)(a1 + 52) = 0x80000000;
	return 1;
}

//----- (004A0790) --------------------------------------------------------
int __cdecl sub_4A0790(int a1, char* a2) {
	if (strcmp(a2, "TRANSPARENT"))
		return sub_4A0570((int*)(a1 + 68), a2);
	*(_DWORD*)(a1 + 68) = 0x80000000;
	return 1;
}

//----- (004A07D0) --------------------------------------------------------
int __cdecl sub_4A07D0(int a1, char* a2) {
	int v2; // eax

	v2 = sub_43F360(a2);
	if (!v2)
		return 0;
	*(_DWORD*)(a1 + 200) = v2;
	return 1;
}

//----- (004A0830) --------------------------------------------------------
int __cdecl sub_4A0830(int a1, char* a2) {
	char* v2; // eax
	char* v3; // eax

	v2 = strtok(a2, " \t\n\r");
	*(_DWORD*)(a1 + 60) = atoi(v2);
	v3 = strtok(0, " \t\n\r");
	*(_DWORD*)(a1 + 64) = atoi(v3);
	return 1;
}

//----- (004A0870) --------------------------------------------------------
int __cdecl sub_4A0870(int a1, char* a2) {
	char* v2; // eax

	v2 = strtok(a2, "\t\n\r");
	if (!strcmp(v2, "NULL"))
		*(_DWORD*)(a1 + 24) = 0;
	else
		*(_DWORD*)(a1 + 24) = sub_42F970(v2);
	return 1;
}

//----- (004A08C0) --------------------------------------------------------
int __cdecl sub_4A08C0(int a1, char* a2) {
	char* v2; // eax

	v2 = strtok(a2, "\t\n\r");
	if (!strcmp(v2, "NULL"))
		*(_DWORD*)(a1 + 32) = 0;
	else
		*(_DWORD*)(a1 + 32) = sub_42F970(v2);
	return 1;
}

//----- (004A0910) --------------------------------------------------------
int __cdecl sub_4A0910(int a1, char* a2) {
	char* v2; // eax

	v2 = strtok(a2, "\t\n\r");
	if (!strcmp(v2, "NULL"))
		*(_DWORD*)(a1 + 48) = 0;
	else
		*(_DWORD*)(a1 + 48) = sub_42F970(v2);
	return 1;
}

//----- (004A0960) --------------------------------------------------------
int __cdecl sub_4A0960(int a1, char* a2) {
	char* v2; // eax

	v2 = strtok(a2, "\t\n\r");
	if (!strcmp(v2, "NULL"))
		*(_DWORD*)(a1 + 56) = 0;
	else
		*(_DWORD*)(a1 + 56) = sub_42F970(v2);
	return 1;
}

//----- (004A09B0) --------------------------------------------------------
int __cdecl sub_4A09B0(int a1, char* a2) {
	char* v2; // eax

	v2 = strtok(a2, "\t\n\r");
	if (!strcmp(v2, "NULL"))
		*(_DWORD*)(a1 + 40) = 0;
	else
		*(_DWORD*)(a1 + 40) = sub_42F970(v2);
	return 1;
}

//----- (004A0A00) --------------------------------------------------------
int __cdecl sub_4A0A00(int a1, const char* a2) {
	*(_DWORD*)(a1 + 12) = 0;
	set_bitmask_flags_from_plus_separated_names_423930(a2, (_DWORD*)(a1 + 12), (const char**)&byte_587000[166712]);
	return 1;
}

//----- (004A0A30) --------------------------------------------------------
int __cdecl sub_4A0A30(int a1, const char* a2) {
	*(_DWORD*)(a1 + 8) = 0;
	set_bitmask_flags_from_plus_separated_names_423930(a2, (_DWORD*)(a1 + 8), (const char**)&byte_587000[166780]);
	return 1;
}

//----- (004A0A60) --------------------------------------------------------
int __cdecl sub_4A0A60(int a1, char* a2) {
	char* v2; // eax

	v2 = strtok(a2, "\t\n\r");
	*(_DWORD*)(a1 + 4) = atoi(v2);
	return 1;
}

//----- (004A0AD0) --------------------------------------------------------
nox_window* __cdecl nox_new_window_from_file(const char* name, int (*a2)(int, int, int, int)) {
	char path[256];
	strcpy(path, "window\\");
	memset(&path[8], 0, 0xF8u);
	sub_4A0CF0();
	sub_4A0D10();
	strcat(path, name);

	FILE* f = fopen(path, "r");
	if (!f)
		return 0;

	int v3;
	while (fscanf(f, "%s", &byte_5D4594[1306948]) != -1 && strcmp((const char*)&byte_5D4594[1306948], "END")) {
		if (!strcmp((const char*)&byte_5D4594[1306948], "ENABLEDCOLOR")) {
			v3 = sub_4A05E0((int*)&byte_5D4594[1307264], f, (char*)&byte_5D4594[1306948]);
			if (!v3)
				break;
		} else {
			if (!strcmp((const char*)&byte_5D4594[1306948], "DISABLEDCOLOR")) {
				v3 = sub_4A05E0((int*)&byte_5D4594[1307268], f, (char*)&byte_5D4594[1306948]);
				if (!v3)
					break;
			}
			if (!strcmp((const char*)&byte_5D4594[1306948], "HILITECOLOR")) {
				v3 = sub_4A05E0((int*)&byte_5D4594[1307276], f, (char*)&byte_5D4594[1306948]);
				if (!v3)
					break;
			}
			if (!strcmp((const char*)&byte_5D4594[1306948], "SELECTEDCOLOR")) {
				v3 = sub_4A05E0((int*)&byte_5D4594[1307280], f, (char*)&byte_5D4594[1306948]);
				if (!v3)
					break;
			}
			if (!strcmp((const char*)&byte_5D4594[1306948], "TEXTCOLOR")) {
				v3 = sub_4A05E0((int*)&byte_5D4594[1307284], f, (char*)&byte_5D4594[1306948]);
				if (!v3)
					break;
			}
			if (!strcmp((const char*)&byte_5D4594[1306948], "BACKGROUNDCOLOR")) {
				v3 = sub_4A05E0((int*)&byte_5D4594[1307272], f, (char*)&byte_5D4594[1306948]);
				if (!v3)
					break;
			}
			if (!strcmp((const char*)&byte_5D4594[1306948], "FONT")) {
				if (!sub_4A0D40((int*)&byte_5D4594[1307288], f, (char*)&byte_5D4594[1306948]))
					break;
			} else if (!strcmp((const char*)&byte_5D4594[1306948], "WINDOW")) {
				nox_window* win = sub_4A0D80_parse_window(f, (char*)&byte_5D4594[1306948], a2);
				fclose(f);
				return win;
			}
		}
	}
	fclose(f);
	return 0;
}

//----- (004A0CF0) --------------------------------------------------------
int sub_4A0CF0() {
	int result; // eax

	result = 0;
	memset(&byte_5D4594[1307208], 0, 0x28u);
	dword_5d4594_1307204 = &byte_5D4594[1307208];
	return result;
}

//----- (004A0D10) --------------------------------------------------------
int sub_4A0D10() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[2650656];
	*(_DWORD*)&byte_5D4594[1307288] = 0;
	*(_DWORD*)&byte_5D4594[1307264] = *(_DWORD*)&byte_5D4594[2650656];
	*(_DWORD*)&byte_5D4594[1307268] = *(_DWORD*)&byte_5D4594[2650656];
	*(_DWORD*)&byte_5D4594[1307272] = *(_DWORD*)&byte_5D4594[2650656];
	*(_DWORD*)&byte_5D4594[1307276] = *(_DWORD*)&byte_5D4594[2650656];
	*(_DWORD*)&byte_5D4594[1307280] = *(_DWORD*)&byte_5D4594[2650656];
	*(_DWORD*)&byte_5D4594[1307284] = *(_DWORD*)&byte_5D4594[2650656];
	return result;
}

//----- (004A0D40) --------------------------------------------------------
BOOL __cdecl sub_4A0D40(int* a1, FILE* a2, char* a3) {
	int v3; // eax

	fscanf(a2, "%*s");
	sub_57BBC0(a2, (int)a3, 256);
	v3 = sub_43F360(a3);
	*a1 = v3;
	return v3 != 0;
}

//----- (004A0D80) --------------------------------------------------------
_DWORD* __cdecl sub_4A0D80_parse_window(FILE* a1, char* a2, int (*a3)(int, int, int, int)) {
	int v3;               // eax
	char* v4;             // eax
	char* v5;             // eax
	char* v6;             // eax
	char* v7;             // eax
	char* v8;             // eax
	char* v9;             // eax
	unsigned __int8* v10; // edi
	int v11;              // eax
	float* v15;           // [esp+14h] [ebp-1A4h]
	int v16;              // [esp+18h] [ebp-1A0h]
	wchar_t* v17;         // [esp+1Ch] [ebp-19Ch]
	int v18;              // [esp+20h] [ebp-198h]
	int v19;              // [esp+24h] [ebp-194h]
	int v20;              // [esp+28h] [ebp-190h]
	char v21[64];         // [esp+2Ch] [ebp-18Ch]
	char v22[332];        // [esp+6Ch] [ebp-14Ch], same as nox_window->field_9 ?

	*(_DWORD*)v22 = 0;
	memset(&v22[4], 0, 0x148u);
	*(_DWORD*)&v22[28] = *(_DWORD*)&byte_5D4594[1307264];
	*(_DWORD*)&v22[36] = *(_DWORD*)&byte_5D4594[1307276];
	v3 = *(_DWORD*)&byte_5D4594[1307288];
	*(_DWORD*)&v22[44] = *(_DWORD*)&byte_5D4594[1307268];
	*(_DWORD*)&v22[20] = *(_DWORD*)&byte_5D4594[1307272];
	v15 = 0;
	*(_DWORD*)&v22[52] = *(_DWORD*)&byte_5D4594[1307280];
	*(_DWORD*)&v22[68] = *(_DWORD*)&byte_5D4594[1307284];
	if (!*(_DWORD*)&byte_5D4594[1307288]) {
		if (dword_5d4594_815132)
			v3 = sub_43F360((char*)&byte_587000[167936]);
		else
			v3 = sub_43F360((char*)&byte_587000[167944]);
	}
	*(_DWORD*)&v22[200] = v3;
	sub_57BBC0(a1, (int)a2, 256);
	// OutputDebugStringA(a2);
	// OutputDebugStringA("\n");
	v4 = strtok(a2, " \t\n\r");
	v18 = atoi(v4);
	v5 = strtok(0, " \t\n\r");
	v17 = (wchar_t*)atoi(v5);
	v6 = strtok(0, " \t\n\r");
	v16 = atoi(v6);
	v7 = strtok(0, " \t\n\r");
	v20 = atoi(v7);
	v8 = strtok(0, " \t\n\r");
	v19 = atoi(v8);
	v9 = strtok(0, " \t\n\r");
	strncpy(v21, v9, 0x3Fu);

	nox_window* win = 0;
	while (1) {
		while (1) {
			do {
				fscanf(a1, "%s", a2);
				// OutputDebugStringA(a2);
				// OutputDebugStringA("\n");
				v10 = &byte_587000[166840];
				if (*(_DWORD*)&byte_587000[166844]) {
					while (strcmp(a2, *(const char**)v10)) {
						v11 = *((_DWORD*)v10 + 3);
						v10 += 8;
						if (!v11)
							goto LABEL_11;
					}
					fscanf(a1, "%*s");
					sub_57BBC0(a1, (int)a2, 256);
					// OutputDebugStringA(a2);
					// OutputDebugStringA("\n");
					if (!(*((int(__cdecl**)(char*, char*))v10 + 1))(v22, a2))
						return 0;
				}
			LABEL_11:;
			} while (*((_DWORD*)v10 + 1));
			if (strcmp(a2, "DATA"))
				break;
			fscanf(a1, "%*s");
			sub_57BBC0(a1, (int)a2, 256);
			// OutputDebugStringA(a2);
			// OutputDebugStringA("\n");
			if (!sub_4A10A0(&v15, v21, a2))
				return 0;
		}
		if (!strcmp(a2, "END"))
			break;
		if (!strcmp(a2, "CHILD")) {
			win = sub_4A1440_parse_window(v21, v18, *(int*)&v22[12], v17, v16, v20, v19, v22, v15, a3);
			if (!win || !sub_4A1780(win, a1, a2))
				return 0;
		} else {
			sub_57BBC0(a1, (int)a2, 256);
			// OutputDebugStringA(a2);
			// OutputDebugStringA("\n");
		}
	}
	if (!win)
		win = sub_4A1440_parse_window(v21, v18, *(int*)&v22[12], v17, v16, v20, v19, v22, v15, a3);
	return win;
}

//----- (004A1440) --------------------------------------------------------
nox_window* __cdecl sub_4A1440_parse_window(const char* a1, int a2, int a3, wchar_t* a4, int a5, int a6, int a7,
											_DWORD* a8, float* a9, int (*a10)(int, int, int, int)) {
	int v10; // ebx
	int v12; // edx

	v10 = sub_4A14F0();

	nox_window* win;
	if (!strcmp(a1, "USER")) {
		win = nox_window_new(v10, a3, (int)a4, a5, a6, a7, a10);
		v12 = a8[2];
		BYTE1(v12) |= 0x20u;
		a8[2] = v12;
		sub_46AF80_copy_window_part(win, a8);
	} else {
		win = sub_4A1510_parse_window(a1, v10, a3, a4, a5, a6, a7, a8, a9);
	}
	sub_46B080(win, a2);
	if (v10)
		(*(int(__cdecl**)(int, int, int, _DWORD))(v10 + 376))(v10, 22, a2, 0);
	return win;
}

//----- (004A14F0) --------------------------------------------------------
int sub_4A14F0() {
	int result; // eax

	if (*(unsigned __int8**)&dword_5d4594_1307204 == &byte_5D4594[1307208])
		result = 0;
	else
		result = *(_DWORD*)(dword_5d4594_1307204 - 4);
	return result;
}

//----- (004A1510) --------------------------------------------------------
nox_window* __cdecl sub_4A1510_parse_window(const char* a1, int a2, int a3, wchar_t* a4, int a5, int a6, int a7,
											_DWORD* a8, float* a9) {
	_DWORD* result; // eax
	int v10;        // ebx
	int v11;        // ebx
	int v12;        // ebx
	int v13;        // ebx

	a8[4] = a2;
	if (!strcmp(a1, "PUSHBUTTON")) {
		a8[2] |= 1u;
		return (_DWORD*)sub_4A91A0(a2, a3, (int)a4, a5, a6, a7, a8);
	}
	if (!strcmp(a1, "RADIOBUTTON")) {
		a8[2] |= 2u;
		return (_DWORD*)sub_4A9330(a2, a3, (int)a4, a5, a6, a7, (int)a8, a9);
	}
	if (!strcmp(a1, "CHECKBOX")) {
		a8[2] |= 4u;
		return (_DWORD*)sub_4A91A0(a2, a3, (int)a4, a5, a6, a7, a8);
	}
	if (!strcmp(a1, "VERTSLIDER")) {
		v10 = a8[2] | 8;
	LABEL_9:
		a8[2] = v10;
		return sub_4B4EE0(a2, a3, (int)a4, a5, a6, a7, a8, a9);
	}
	if (!strcmp(a1, "HORZSLIDER")) {
		v10 = a8[2] | 0x10;
		goto LABEL_9;
	}
	if (!strcmp(a1, "SCROLLLISTBOX")) {
		a8[2] |= 0x20u;
		result = sub_4A4310(a2, a3, (int)a4, a5, a6, a7, (int)a8, (__int16*)a9);
	} else if (!strcmp(a1, "ENTRYFIELD")) {
		v11 = a8[2];
		LOBYTE(v11) = v11 | 0x80;
		a8[2] = v11;
		result = sub_488500(a2, a3, (int)a4, a5, a6, a7, (int)a8, (wchar_t*)a9);
	} else if (!strcmp(a1, "STATICTEXT")) {
		v12 = a8[2];
		BYTE1(v12) |= 8u;
		a8[2] = v12;
		result = sub_489300(a2, a3, (int)a4, a5, a6, a7, a8, a9);
	} else if (!strcmp(a1, "PROGRESSBAR")) {
		v13 = a8[2];
		BYTE1(v13) |= 0x10u;
		a8[2] = v13;
		result = sub_4CAF10(a2, a3, (int)a4, a5, a6, a7, a8);
	} else {
		result = (_DWORD*)a7;
	}
	return result;
}

//----- (004A1780) --------------------------------------------------------
BOOL __cdecl sub_4A1780(int a1, FILE* a2, char* a3) {
	_DWORD* v3; // eax

	sub_4A18C0(a1);
	while (fscanf(a2, "%s", a3) != -1 && strcmp(a3, "END")) {
		if (!strcmp(a3, "ENABLEDCOLOR")) {
			v3 = (_DWORD*)sub_4A05E0((int*)&byte_5D4594[1307264], a2, a3);
		LABEL_14:
			if (!v3)
				return 0;
		} else {
			if (!strcmp(a3, "DISABLEDCOLOR")) {
				v3 = (_DWORD*)sub_4A05E0((int*)&byte_5D4594[1307268], a2, a3);
				goto LABEL_14;
			}
			if (!strcmp(a3, "HILITECOLOR")) {
				v3 = (_DWORD*)sub_4A05E0((int*)&byte_5D4594[1307276], a2, a3);
				goto LABEL_14;
			}
			if (!strcmp(a3, "SELECTEDCOLOR")) {
				v3 = (_DWORD*)sub_4A05E0((int*)&byte_5D4594[1307280], a2, a3);
				goto LABEL_14;
			}
			if (!strcmp(a3, "TEXTCOLOR")) {
				v3 = (_DWORD*)sub_4A05E0((int*)&byte_5D4594[1307284], a2, a3);
				goto LABEL_14;
			}
			if (!strcmp(a3, "WINDOW")) {
				v3 = sub_4A0D80_parse_window(a2, a3, 0);
				goto LABEL_14;
			}
		}
	}
	return sub_4A18A0() == a1;
}

//----- (004A18A0) --------------------------------------------------------
int sub_4A18A0() {
	if (*(unsigned __int8**)&dword_5d4594_1307204 == &byte_5D4594[1307208])
		return 0;
	dword_5d4594_1307204 -= 4;
	return **(_DWORD**)&dword_5d4594_1307204;
}

//----- (004A18C0) --------------------------------------------------------
int __cdecl sub_4A18C0(int a1) {
	int result; // eax

	result = dword_5d4594_1307204;
	if (*(unsigned __int8**)&dword_5d4594_1307204 != &byte_5D4594[1307244]) {
		**(_DWORD**)&dword_5d4594_1307204 = a1;
		result = dword_5d4594_1307204 + 4;
		dword_5d4594_1307204 += 4;
	}
	return result;
}

// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);
