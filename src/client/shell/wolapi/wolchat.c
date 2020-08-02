#include "wolchat.h"

#include "../../../common/wolapi/wolchnl.h"
#include "../../../proto.h"
extern _DWORD dword_5d4594_829532;
extern _DWORD dword_587000_109280;
extern _DWORD dword_5d4594_829544;
extern _DWORD dword_5d4594_829500;
extern nox_wnd_xxx* dword_5d4594_829520;
extern _DWORD dword_5d4594_829516;
extern _DWORD dword_5d4594_829512;
extern _DWORD dword_5d4594_829484;
extern _DWORD dword_5d4594_829508;
extern _DWORD dword_5d4594_829488;
extern _DWORD dword_5d4594_829492;
extern _DWORD dword_5d4594_829480;

//----- (00446970) --------------------------------------------------------
char* sub_446970_wol_chat() {
	char* result;        // eax
	int v1;              // edi
	unsigned __int8* v2; // esi

	result = *(char**)&byte_5D4594[829568];
	if (!*(_DWORD*)&byte_5D4594[829568]) {
		result = *(char**)&byte_587000[108852];
		v1 = 0;
		if (*(_DWORD*)&byte_587000[108852]) {
			v2 = &byte_587000[108848];
			do {
				*(_DWORD*)v2 = loadString_sub_40F1D0(*((char**)v2 + 1), 0,
													 "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 181);
				result = (char*)*((_DWORD*)v2 + 3);
				v2 += 8;
				++v1;
			} while (result);
		}
		*(_DWORD*)&byte_5D4594[826092] = v1;
		*(_DWORD*)&byte_5D4594[829568] = 1;
	}
	return result;
}

//----- (00446A20) --------------------------------------------------------
int __cdecl sub_446A20_wol_chat(wchar_t* a1) {
	wchar_t* v1; // eax
	wchar_t* v3; // [esp-10h] [ebp-10h]

	sub_446CC0(0);
	sub_41F140(a1);
	sub_44A400();
	v3 = loadString_sub_40F1D0((char*)&byte_587000[110256], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
							   212);
	v1 = loadString_sub_40F1D0((char*)&byte_587000[110324], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
							   211);
	sub_449A10(*(int*)&dword_5d4594_829480, (int)v1, (int)v3, 288, 0, 0);
	return sub_44A4B0();
}

//----- (00446AE0) --------------------------------------------------------
const char* __cdecl sub_446AE0_wol_chat(int a1) {
	const char* result; // eax
	const char* v2;     // ebx
	char v3[108];       // [esp+8h] [ebp-6Ch]

	result = sub_446BC0(a1);
	v2 = result;
	if (result) {
		strcpy(&v3[36], result);
		if (sub_41F9E0((int)v3)) {
			result = (const char*)loadString_sub_40F1D0((char*)&byte_587000[110384], 0,
														"C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 293);
			if (result)
				result = (const char*)sub_447310(0, (int)result);
		} else if (sub_427880(v2)) {
			sub_427850((int)v3);
			sub_41F980(v2, 0);
			result = (const char*)sub_446C10(a1, 0);
		} else {
			sub_427820((int)v3);
			sub_41F980(v2, 1);
			result = (const char*)sub_446C10(a1, 1);
		}
	}
	return result;
}

//----- (00446F80) --------------------------------------------------------
void __cdecl sub_446F80_wol_chat(wchar_t* a1) {
	wchar_t v1;     // ax
	int* v2;        // eax
	int* v3;        // edi
	int i;          // eax
	char* v5;       // eax
	const char* v6; // esi
	char* v7;       // eax
	wchar_t* v8;    // eax

	if (!a1)
		return;
	v1 = *a1;
	if (!*a1 || v1 == 10 || v1 == 13)
		return;
	if (sub_41EC00()) {
		if (sub_446C90()) {
			v2 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0);
			v3 = v2;
			for (i = *v2; i != -1; ++v3) {
				v5 = sub_446F40(i);
				v6 = v5;
				if (v5) {
					if (sub_41F860(v5, a1))
						sub_4471A0(v6, (int)a1, 1, 1);
				}
				i = v3[1];
			}
			return;
		}
		sub_448680(a1, (char*)&byte_5D4594[827176]);
		if (sub_40D3E0((int)&byte_5D4594[827176])) {
			v7 = sub_41FA40();
			sub_4471A0(v7, (int)a1, 0, 0);
			return;
		}
	}
	v8 = loadString_sub_40F1D0((char*)&byte_587000[110480], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
							   1076);
	if (v8)
		sub_447310(0, (int)v8);
}

//----- (00447090) --------------------------------------------------------
void __cdecl sub_447090_wol_chat(wchar_t* a1) {
	wchar_t v1;     // ax
	int* v2;        // eax
	int* v3;        // edi
	int i;          // eax
	char* v5;       // eax
	const char* v6; // esi
	char* v7;       // eax
	wchar_t* v8;    // eax

	if (!a1)
		return;
	v1 = *a1;
	if (!*a1 || v1 == 10 || v1 == 13)
		return;
	if (sub_41EC00()) {
		if (sub_446C90()) {
			v2 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0);
			v3 = v2;
			for (i = *v2; i != -1; ++v3) {
				v5 = sub_446F40(i);
				v6 = v5;
				if (v5) {
					if (sub_41F8F0(v5, a1))
						sub_447250(v6, (int)a1, 1, 1);
				}
				i = v3[1];
			}
			return;
		}
		sub_448680(a1, (char*)&byte_5D4594[827176]);
		if (sub_40D4D0((int)&byte_5D4594[827176])) {
			v7 = sub_41FA40();
			sub_447250(v7, (int)a1, 0, 0);
			return;
		}
	}
	v8 = loadString_sub_40F1D0((char*)&byte_587000[110540], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
							   1123);
	if (v8)
		sub_447310(0, (int)v8);
}

//----- (00447470) --------------------------------------------------------
int sub_447470_wol_chat() {
	wchar_t* v0; // esi
	int result;  // eax

	v0 = loadString_sub_40F1D0((char*)&byte_587000[110616], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
							   1261);
	result = sub_41EC00();
	if (result) {
		nox_swprintf((wchar_t*)&byte_5D4594[827176], v0, result);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)&byte_5D4594[827176], 9);
	}
	return result;
}

//----- (004474C0) --------------------------------------------------------
int __cdecl sub_4474C0_wol_chat(int a1, int a2) {
	wchar_t* v2; // eax
	wchar_t* v3; // eax

	if (a1) {
		v2 = loadString_sub_40F1D0((char*)&byte_587000[110672], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
								   1277);
		nox_swprintf((wchar_t*)&byte_5D4594[827176], v2, a2, a1);
	} else {
		v3 = loadString_sub_40F1D0((char*)&byte_587000[110728], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
								   1281);
		nox_swprintf((wchar_t*)&byte_5D4594[827176], v3, a2);
	}
	return nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)&byte_5D4594[827176], 9);
}

//----- (00447540) --------------------------------------------------------
int __cdecl sub_447540_wol_chat(int a1) {
	wchar_t* v1; // eax

	v1 = loadString_sub_40F1D0((char*)&byte_587000[110792], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
							   1296);
	nox_swprintf((wchar_t*)&byte_5D4594[827176], v1, a1);
	return nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)&byte_5D4594[827176], 9);
}

//----- (00447590) --------------------------------------------------------
int sub_447590_wol_chat() {
	wchar_t* v0; // esi
	int result;  // eax

	v0 = loadString_sub_40F1D0((char*)&byte_587000[110848], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
							   1310);
	result = sub_41EC00();
	if (result) {
		nox_swprintf((wchar_t*)&byte_5D4594[827176], v0, result);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)&byte_5D4594[827176], 9);
	}
	return result;
}

//----- (00447620) --------------------------------------------------------
int sub_447620_wol_chat() {
	int result;          // eax
	char** v1;           // eax
	unsigned __int8* v2; // esi
	wchar_t* v3;         // eax
	_BYTE* v4;           // ecx
	_DWORD* v5;          // edi
	char* v6;            // ebx
	char* v7;            // esi
	_DWORD* v8;          // edi
	_DWORD* v9;          // edi

	sub_43BDD0(1900);
	nox_set_draw_unk1(sub_41E210);
	sub_43FE20(150);
	dword_5d4594_829480 = nox_new_window_from_file("wolchat.wnd", sub_447CC0);
	sub_446970_wol_chat();
	result = dword_5d4594_829480;
	if (dword_5d4594_829480) {
		sub_46A8C0(*(int*)&dword_5d4594_829480);
		sub_44A4B0();
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_829480, sub_447C70, 0, 0);
		sub_46B340(*(int*)&dword_5d4594_829480, sub_4483A0);
		result = nox_wnd_sub_43C5B0(*(_DWORD**)&dword_5d4594_829480, 0, 0, 0, -480, 0, 20, 0, -40);
		dword_5d4594_829520 = result;
		if (dword_5d4594_829520) {
			dword_5d4594_829520->field_0 = 1900;
			dword_5d4594_829520->field_12 = sub_446A90;
			dword_5d4594_829520->field_14 = sub_447BD0;
			dword_5d4594_829484 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1908);
			dword_5d4594_829488 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1909);
			dword_5d4594_829492 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1907);
			*(_DWORD*)&byte_5D4594[829496] = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1916);
			dword_5d4594_829500 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1910);
			*(_DWORD*)&byte_5D4594[829528] = loadString_sub_40F1D0(
				(char*)&byte_587000[110916], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1415);
			dword_5d4594_829532 = loadString_sub_40F1D0((char*)&byte_587000[110980], 0,
														"C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1416);
			*(_DWORD*)&byte_5D4594[829536] = &byte_587000[110992];
			*(_DWORD*)&byte_5D4594[829540] = loadString_sub_40F1D0(
				(char*)&byte_587000[111048], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1418);
			dword_5d4594_829544 = &byte_587000[111056];
			*(_DWORD*)&byte_5D4594[829548] = loadString_sub_40F1D0(
				(char*)&byte_587000[111120], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1420);
			*(_DWORD*)&byte_5D4594[829552] = loadString_sub_40F1D0(
				(char*)&byte_587000[111184], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1421);
			*(_DWORD*)&byte_5D4594[829556] = &byte_587000[111204];
			*(_DWORD*)&byte_5D4594[829560] = loadString_sub_40F1D0(
				(char*)&byte_587000[111264], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1423);
			*(_DWORD*)&byte_5D4594[829564] = loadString_sub_40F1D0(
				(char*)&byte_587000[111328], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1424);
			*(_DWORD*)&byte_5D4594[829524] = loadString_sub_40F1D0(
				(char*)&byte_587000[111392], 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1425);
			dword_587000_109280 = -1;
			sub_446D50();
			sub_46A8A0();
			sub_447600();
			sub_41EBB0(0);
			sub_446CC0(0);
			sub_41F100((char*)&byte_587000[111400]);
			if (**(_BYTE**)&byte_587000[108828]) {
				v1 = (char**)&byte_587000[108828];
				v2 = &byte_587000[108828];
				do {
					v3 = loadString_sub_40F1D0(*v1, 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1446);
					*((_DWORD*)v2 - 1) = v3;
					nox_wcslen(v3);
					v4 = (_BYTE*)*((_DWORD*)v2 + 3);
					v2 += 12;
					v1 = (char**)v2;
				} while (*v4);
			}
			sub_41FFF0();
			dword_5d4594_829508 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1917);
			dword_5d4594_829512 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1918);
			dword_5d4594_829516 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1919);
			v5 = *(_DWORD**)(dword_5d4594_829492 + 32);
			v6 = sub_42F970("ShopInventorySlider");
			v7 = sub_42F970("ShopInventorySliderSelected");
			sub_4B5700(*(int*)&dword_5d4594_829508, 0, 0, (int)v6, (int)v7, (int)v7);
			sub_46B280(*(int*)&dword_5d4594_829508, *(int*)&dword_5d4594_829492);
			sub_46B280(*(int*)&dword_5d4594_829512, *(int*)&dword_5d4594_829492);
			sub_46B280(*(int*)&dword_5d4594_829516, *(int*)&dword_5d4594_829492);
			sub_46B300(*(int*)&dword_5d4594_829492, sub_447BF0);
			v5[9] = dword_5d4594_829508;
			v5[7] = dword_5d4594_829512;
			v5[8] = dword_5d4594_829516;
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_829508 + 400) + 8) = 16;
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_829508 + 400) + 12) = 46;
			dword_5d4594_829508 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1920);
			dword_5d4594_829512 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1921);
			dword_5d4594_829516 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1922);
			v8 = *(_DWORD**)(dword_5d4594_829484 + 32);
			sub_4B5700(*(int*)&dword_5d4594_829508, 0, 0, (int)v6, (int)v7, (int)v7);
			sub_46B280(*(int*)&dword_5d4594_829508, *(int*)&dword_5d4594_829484);
			sub_46B280(*(int*)&dword_5d4594_829512, *(int*)&dword_5d4594_829484);
			sub_46B280(*(int*)&dword_5d4594_829516, *(int*)&dword_5d4594_829484);
			sub_46B300(*(int*)&dword_5d4594_829484, sub_447BF0);
			v8[9] = dword_5d4594_829508;
			v8[7] = dword_5d4594_829512;
			v8[8] = dword_5d4594_829516;
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_829508 + 400) + 8) = 16;
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_829508 + 400) + 12) = 46;
			dword_5d4594_829508 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1923);
			dword_5d4594_829512 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1924);
			dword_5d4594_829516 = sub_46B0C0(*(_DWORD**)&dword_5d4594_829480, 1925);
			v9 = *(_DWORD**)(dword_5d4594_829488 + 32);
			sub_4B5700(*(int*)&dword_5d4594_829508, 0, 0, (int)v6, (int)v7, (int)v7);
			sub_46B280(*(int*)&dword_5d4594_829508, *(int*)&dword_5d4594_829488);
			sub_46B280(*(int*)&dword_5d4594_829512, *(int*)&dword_5d4594_829488);
			sub_46B280(*(int*)&dword_5d4594_829516, *(int*)&dword_5d4594_829488);
			sub_46B300(*(int*)&dword_5d4594_829488, sub_447BF0);
			v9[9] = dword_5d4594_829508;
			v9[7] = dword_5d4594_829512;
			v9[8] = dword_5d4594_829516;
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_829508 + 400) + 8) = 16;
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_829508 + 400) + 12) = 46;
			sub_41F370(0);
			if (nox_common_gameFlags_check_40A5C0(0x2000000))
				sub_448450();
			else
				sub_41F3A0(-99999, 1);
			result = 1;
		}
	}
	return result;
}
