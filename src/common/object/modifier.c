#include "../../proto.h"

//----- (00411B90) --------------------------------------------------------
int __cdecl sub_411B90(int a1, char* a2, int a3) {
	int result;  // eax
	char* v4;    // ebx
	wchar_t* v5; // eax
	size_t v6;   // eax
	size_t v7;   // esi
	wchar_t* v8; // eax
	char v9[8];  // [esp+Ch] [ebp-8h]

	strcpy(v9, " =\n\r\t");
	result = (int)strtok(a2, v9);
	v4 = (char*)result;
	if (result) {
		v5 = loadString_sub_40F1D0((char*)result, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 418);
		v6 = nox_wcslen(v5);
		v7 = v6;
		result = (int)nox_malloc(2 * v6 + 2);
		*(_DWORD*)(a3 + 8) = result;
		if (result) {
			v8 = loadString_sub_40F1D0(v4, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 426);
			nox_wcsncpy(*(wchar_t**)(a3 + 8), v8, v7);
			*(_WORD*)(*(_DWORD*)(a3 + 8) + 2 * v7) = 0;
			result = 1;
		}
	}
	return result;
}

//----- (00412100) --------------------------------------------------------
int __cdecl sub_412100_parse_desc(const char* a1, char* a2, obj_412ae0_t* a3) {
	int result;  // eax
	char* v4;    // ebx
	wchar_t* v5; // eax
	size_t v6;   // eax
	size_t v7;   // esi
	wchar_t* v8; // eax
	char v9[8];  // [esp+Ch] [ebp-8h]

	strcpy(v9, " =\n\r\t");
	result = (int)strtok(a2, v9);
	v4 = (char*)result;
	if (!result) {
		return 0;
	}
	v5 = loadString_sub_40F1D0((char*)result, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 733);
	v6 = nox_wcslen(v5);
	v7 = v6;
	a3->field_2 = (wchar_t*)nox_malloc(2 * v6 + 2);
	if (!a3->field_2) {
		return 0;
	}
	v8 = loadString_sub_40F1D0(v4, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 741);
	nox_wcsncpy(*(wchar_t**)(&a3->field_2), v8, v7);
	*(_WORD*)(*(_DWORD*)(&a3->field_2) + 2 * v7) = 0;
	return 1;
}

//----- (004121B0) --------------------------------------------------------
int __cdecl sub_4121B0_parse_second_desc(const char* a1, char* a2, obj_412ae0_t* a3) {
	int result;  // eax
	char* v4;    // ebx
	wchar_t* v5; // eax
	size_t v6;   // eax
	size_t v7;   // esi
	wchar_t* v8; // eax
	char v9[8];  // [esp+Ch] [ebp-8h]

	strcpy(v9, " =\n\r\t");
	result = (int)strtok(a2, v9);
	v4 = (char*)result;
	if (!result) {
		return 0;
	}
	v5 = loadString_sub_40F1D0((char*)result, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 767);
	v6 = nox_wcslen(v5);
	v7 = v6;
	a3->field_3 = (wchar_t*)nox_malloc(2 * v6 + 2);
	if (!a3->field_3) {
		return 0;
	}
	v8 = loadString_sub_40F1D0(v4, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 775);
	nox_wcsncpy(*(wchar_t**)(&a3->field_3), v8, v7);
	*(_WORD*)(*(_DWORD*)(&a3->field_3) + 2 * v7) = 0;
	return 1;
}

//----- (00412260) --------------------------------------------------------
int __cdecl sub_412260_parse_ident_desc(const char* a1, char* a2, obj_412ae0_t* a3) {
	int result;  // eax
	char* v4;    // ebx
	wchar_t* v5; // eax
	size_t v6;   // eax
	size_t v7;   // esi
	wchar_t* v8; // eax
	char v9[8];  // [esp+Ch] [ebp-8h]

	strcpy(v9, " =\n\r\t");
	result = (int)strtok(a2, v9);
	v4 = (char*)result;
	if (!result) {
		return 0;
	}
	v5 = loadString_sub_40F1D0((char*)result, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 801);
	v6 = nox_wcslen(v5);
	v7 = v6;
	a3->field_4 = (wchar_t*)nox_malloc(2 * v6 + 2);
	if (!a3->field_4) {
		return 0;
	}
	v8 = loadString_sub_40F1D0(v4, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 809);
	nox_wcsncpy(*(wchar_t**)(&a3->field_4), v8, v7);
	*(_WORD*)(*(_DWORD*)(&a3->field_4) + 2 * v7) = 0;
	return 1;
}

//----- (00413480) --------------------------------------------------------
wchar_t* __cdecl sub_413480(char a1) {
	int v1;              // ecx
	unsigned __int8* v2; // eax

	v1 = 0;
	v2 = &byte_587000[27332];
	while (a1 != *v2) {
		v2 += 20;
		++v1;
		if ((int)v2 >= (int)&byte_587000[27452])
			return 0;
	}
	return loadString_sub_40F1D0(*(char**)&byte_587000[20 * v1 + 27344], 0,
				     "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 2087);
}