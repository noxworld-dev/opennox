#include "guigen.h"

#include "../../proto.h"

extern int nox_win_width;
extern int nox_win_height;

//----- (004A9D00) --------------------------------------------------------
__int16 __cdecl sub_4A9D00(unsigned __int8* a1) {
	unsigned __int8* v1; // ebx
	int v2;              // eax
	int v3;              // edi
	int v4;              // esi
	wchar_t* v5;         // eax
	int v6;              // kr00_4
	int v7;              // esi

	v1 = a1;
	v2 = *(unsigned __int16*)(a1 + 1);
	if ((unsigned __int16)v2 == *(_DWORD*)&byte_5D4594[1309668])
		return v2;
	*(_DWORD*)&byte_5D4594[1309668] = *(unsigned __int16*)(a1 + 1);
	sub_452D80(897, 50);
	sub_430B50(0, 0, nox_win_width - 1, nox_win_height - 1);
	sub_440900();
	v3 = nox_win_height / 2 - 120;
	v4 = nox_win_width / 2 - 160;
	nox_client_drawImageAt_47D2C0(*(_DWORD*)&byte_5D4594[4 * (*(_DWORD*)&byte_5D4594[1309672] % 4) + 1309644], v4, v3);
	nox_client_drawImageAt_47D2C0(*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1309672] + 1309516], v4, v3);
	switch (*v1) {
	case 0x9Bu:
		v5 = loadString_sub_40F1D0((char*)&byte_587000[172368], 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c",
					   89);
		goto LABEL_8;
	case 0x9Cu:
		v5 = loadString_sub_40F1D0((char*)&byte_587000[172416], 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c",
					   92);
		goto LABEL_8;
	case 0x9Du:
		v5 = loadString_sub_40F1D0((char*)&byte_587000[172464], 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c",
					   95);
	LABEL_8:
		*(_DWORD*)&byte_5D4594[1309660] = v5;
		break;
	}
	sub_43F840(0, *(unsigned __int16**)&byte_5D4594[1309660], (int*)&a1, 0, 0);
	v6 = nox_win_width - (_DWORD)a1;
	v7 = nox_win_height / 2 - (2 * sub_43F320(0) + 70);
	sub_434390(*(int*)&byte_5D4594[2523948]);
	sub_4343E0(*(int*)&byte_5D4594[2614248]);
	sub_43F730(0, *(__int16**)&byte_5D4594[1309660], v6 / 2, v7);
	if (++*(_DWORD*)&byte_5D4594[1309672] >= 32)
		*(_DWORD*)&byte_5D4594[1309672] = 0;
	sub_48A220();
	sub_4AD170_call_copy_backbuffer();
	sub_48A290_call_present();
	return v2;
}
