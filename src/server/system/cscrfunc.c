#include "../../proto.h"

//----- (00512E80) --------------------------------------------------------
int __cdecl sub_512E80(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)&byte_5D4594[1599628];
	if (*(int*)&byte_5D4594[1599628] < 1024) {
		*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1599628] + 3826092] = a1;
		*(_DWORD*)&byte_5D4594[1599628] = ++v1;
	}
	return v1 - 1;
}

//----- (00528AC0) --------------------------------------------------------
int __cdecl sub_528AC0(int a1, wchar_t* a2, wchar_t a3) {
	char v3;       // al
	__int16 v4;    // ax
	double v5;     // st7
	__int64 v6;    // rax
	double v7;     // st7
	int v8;        // edi
	int result;    // eax
	int i;         // esi
	char v11[520]; // [esp+8h] [ebp-208h]

	v11[0] = -88;
	v11[3] = 0;
	if (sub_4100F0((__int16*)a2))
		v3 = v11[3] | 2;
	else
		v3 = v11[3] | 4;
	v11[3] = v3;
	v4 = sub_578AC0((_DWORD*)a1);
	v5 = *(float*)(a1 + 56);
	*(_WORD*)&v11[1] = v4;
	v6 = (__int64)v5;
	v7 = *(float*)(a1 + 60);
	*(_WORD*)&v11[4] = v6;
	*(_WORD*)&v11[6] = (__int64)v7;
	*(_WORD*)&v11[9] = a3;
	v11[8] = nox_wcslen(a2) + 1;
	if (v11[3] & 4) {
		nox_wcscpy((wchar_t*)&v11[11], a2);
		v8 = 2;
	} else {
		nox_sprintf(&v11[11], "%S", a2);
		v8 = 1;
	}
	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), 1, v11,
			   v8 * (unsigned __int8)v11[8] + 11);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (00512B10) --------------------------------------------------------
int sub_512B10() {
	int v0;      // eax
	wchar_t* v1; // eax

	v0 = script_pop();
	if (*(_DWORD*)&byte_5D4594[3821964] && *(_BYTE*)(*(_DWORD*)&byte_5D4594[3821964] + 8) & 4) {
		v1 = loadString_sub_40F1D0(*(char**)&byte_5D4594[4 * v0 + 3831212], 0,
					   "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1285);
		sub_4D9EB0(*(int*)&byte_5D4594[3821964], v1);
	}
	return 0;
}

//----- (00512B60) --------------------------------------------------------
int sub_512B60() {
	int v0;      // eax
	wchar_t* v1; // eax

	v0 = script_pop();
	v1 = loadString_sub_40F1D0(*(char**)&byte_5D4594[4 * v0 + 3831212], 0,
				   "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1310);
	sub_4D9FD0(0, v1);
	return 0;
}

//----- (00512B90) --------------------------------------------------------
int sub_512B90() {
	int v0;      // edi
	int v1;      // eax
	int v2;      // esi
	char* v3;    // ecx
	wchar_t* v4; // eax
	int v6;      // [esp+8h] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *(char**)&byte_5D4594[4 * v0 + 3831212];
		v6 = 0;
		v4 = loadString_sub_40F1D0(v3, &v6, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1342);
		sub_528AC0(v2, v4, 0);
		if (nox_common_gameFlags_check_40A5C0(2048))
			sub_44D900(v6, 100);
	}
	return 0;
}

//----- (00513F70) --------------------------------------------------------
int sub_513F70() {
	int v0;      // eax
	wchar_t* v1; // eax
	int v2;      // eax

	v0 = script_pop();
	v1 = loadString_sub_40F1D0(*(char**)&byte_5D4594[4 * v0 + 3831212], 0,
				   "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 2901);
	v2 = sub_512E80((int)v1);
	sub_507230(v2);
	return 0;
}

//----- (00514A80) --------------------------------------------------------
int sub_514A80() {
	__int16 v0;  // di
	int v1;      // ebx
	int v2;      // eax
	int v3;      // esi
	char* v4;    // edx
	wchar_t* v5; // eax
	wchar_t v7;  // [esp-4h] [ebp-14h]
	int v8;      // [esp+Ch] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (v3) {
		v4 = *(char**)&byte_5D4594[4 * v1 + 3831212];
		v7 = v0 * *(_WORD*)&byte_5D4594[2649704];
		v8 = 0;
		v5 = loadString_sub_40F1D0(v4, &v8, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3629);
		sub_528AC0(v3, v5, v7);
		if (nox_common_gameFlags_check_40A5C0(2048))
			sub_44D900(v8, 100);
	}
	return 0;
}

//----- (00514B10) --------------------------------------------------------
int sub_514B10() {
	wchar_t v0;  // di
	int v1;      // ebx
	int v2;      // eax
	int v3;      // esi
	char* v4;    // ecx
	wchar_t* v5; // eax
	int v7;      // [esp+Ch] [ebp-4h]

	v0 = script_pop();
	v1 = script_pop();
	v2 = script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (v3) {
		v4 = *(char**)&byte_5D4594[4 * v1 + 3831212];
		v7 = 0;
		v5 = loadString_sub_40F1D0(v4, &v7, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3670);
		sub_528AC0(v3, v5, v0);
		if (v7) {
			if (nox_common_gameFlags_check_40A5C0(2048))
				sub_44D900(v7, 100);
		}
	}
	return 0;
}