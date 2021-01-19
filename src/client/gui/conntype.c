#include "conntype.h"

#include "../../proto.h"
#include "servopts/guiserv.h"

extern _DWORD dword_5d4594_1305684;
extern int nox_win_width;
extern int nox_win_height;

//----- (0049C820) --------------------------------------------------------
int sub_49C820() {
	_DWORD* v0;  // edi
	char** v1;   // esi
	wchar_t* v2; // eax

	dword_5d4594_1305684 = nox_new_window_from_file("conntype.wnd", sub_49CA60);
	sub_46B120(*(_DWORD**)&dword_5d4594_1305684, 0);
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1305684);
	sub_46C690(*(int*)&dword_5d4594_1305684);
	nox_xxx_windowDestroyChildsMB_46B500(*(int*)&dword_5d4594_1305684);
	sub_49C910();
	nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_1305684, nox_win_width / 2 - *(int*)(dword_5d4594_1305684 + 8) / 2,
					   nox_win_height / 2 - *(int*)(dword_5d4594_1305684 + 12) / 2);
	nox_xxx_guiServerOptsLoad_457500();
	sub_459D80(1);
	v0 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1305684, 10352);
	v1 = (char**)getMemAt(0x587000, 164928);
	do {
		v2 = nox_strman_loadString_40F1D0(*v1, 0, "C:\\NoxPost\\src\\client\\Gui\\conntype.c", 158);
		nox_window_call_field_94((int)v0, 16397, (int)v2, -1);
		++v1;
	} while ((int)v1 < (int)getMemAt(0x587000, 164944));
	return nox_window_call_field_94((int)v0, 16403, 0, 0);
}

//----- (0049C910) --------------------------------------------------------
_DWORD* sub_49C910() {
	unsigned __int16* v0; // eax
	unsigned __int16* v1; // esi
	char** v2;            // ebx
	int v3;               // eax
	int v4;               // edi
	unsigned __int16* v5; // eax
	int v6;               // edi
	int v7;               // eax
	_DWORD* result;       // eax
	int v9;               // ecx
	int v10;              // edi
	int v11;              // [esp+Ch] [ebp-8h]
	int v12;              // [esp+10h] [ebp-4h]

	v0 = (unsigned __int16*)nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1305684, 10352);
	v1 = v0;
	v2 = (char**)getMemAt(0x587000, 164928);
	v3 = 5 * (nox_xxx_guiFontHeightMB_43F320(*((_DWORD*)v0 + 59)) + 1);
	*((_DWORD*)v1 + 7) = *((_DWORD*)v1 + 5) + v3 + 2;
	*((_DWORD*)v1 + 3) = v3 + 2;
	v4 = 0;
	do {
		v5 = nox_strman_loadString_40F1D0(*v2, 0, "C:\\NoxPost\\src\\client\\Gui\\conntype.c", 53);
		nox_xxx_drawGetStringSize_43F840(*((_DWORD*)v1 + 59), v5, &v11, 0, 0);
		if (v11 > v4)
			v4 = v11;
		++v2;
	} while ((int)v2 < (int)getMemAt(0x587000, 164944));
	v6 = v4 + 7;
	nox_xxx_drawGetStringSize_43F840(*((_DWORD*)v1 + 59), v1 + 54, &v12, 0, 0);
	if (v6 <= v12)
		v6 = v12;
	v7 = *((_DWORD*)v1 + 4);
	*((_DWORD*)v1 + 2) = v6;
	*((_DWORD*)v1 + 6) = v7 + v6;
	*(_DWORD*)(dword_5d4594_1305684 + 16) = v7 - 40;
	*(_DWORD*)(dword_5d4594_1305684 + 20) = *((_DWORD*)v1 + 5) - 40;
	*(_DWORD*)(dword_5d4594_1305684 + 24) = *((_DWORD*)v1 + 6) + 40;
	*(_DWORD*)(dword_5d4594_1305684 + 28) = *((_DWORD*)v1 + 7) + 40;
	*(_DWORD*)(dword_5d4594_1305684 + 8) = *((_DWORD*)v1 + 2) + 80;
	*(_DWORD*)(dword_5d4594_1305684 + 12) = *((_DWORD*)v1 + 3) + 80;
	result = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1305684, 10353);
	result[5] = *((_DWORD*)v1 + 7) + 10;
	v9 = result[2];
	v10 = result[5];
	result[4] = *((_DWORD*)v1 + 6) - v9;
	result[7] = v10 + result[3];
	result[6] = v9 + result[4];
	return result;
}
