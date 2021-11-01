#include "GAME1_2.h"
#include "client__gui__window.h"
#include "input.h"
#include "common/fs/nox_fs.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_823776;

FILE* nox_file_log = 0;

//----- (00451610) --------------------------------------------------------
int sub_451610() {
	int result;          // eax
	unsigned char* v1; // ecx

	result = *getMemU32Ptr(0x5D4594, 835876);
	v1 = getMemAt(0x5D4594, 835876);
	do {
		*(uint32_t*)v1 = *((uint32_t*)v1 - 1);
		v1 -= 4;
	} while ((int)v1 > (int)getMemAt(0x5D4594, 835800));
	*getMemU32Ptr(0x5D4594, 835800) = result;
	return result;
}

//----- (00451630) --------------------------------------------------------
unsigned char* sub_451630() {
	unsigned char* v1;     // ecx
	unsigned char* result; // eax
	wchar_t* v3;             // [esp-Ch] [ebp-Ch]
	wchar_t* v4;             // [esp-8h] [ebp-8h]

	nox_file_log = nox_fs_create_text("log");
	if (!nox_file_log) {
		v4 = nox_strman_loadString_40F1D0("FatalError", 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 272);
		v3 = nox_strman_loadString_40F1D0("CantOpenLog", 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 271);
		// nullsub_4(nox_video_getWindow_401FD0(), v3, v4, 0);
		nox_exit(0);
	}
	v1 = getMemAt(0x5D4594, 835880);
	result = getMemAt(0x5D4594, 835800);
	do {
		*(uint32_t*)result = v1;
		*(uint16_t*)v1 = 0;
		result += 4;
		v1 += 200;
	} while ((int)result < (int)getMemAt(0x5D4594, 835880));
	return result;
}

//----- (004516C0) --------------------------------------------------------
void sub_4516C0(wchar_t* a1, ...) {
	unsigned short* v1; // eax
	unsigned short* v3; // [esp-8h] [ebp-8h]
	va_list va;         // [esp+8h] [ebp+8h]

	va_start(va, a1);
	if (!nox_file_log)
		sub_451630();
	sub_451610();
	v1 = nox_strman_loadString_40F1D0("FatalErrorHeader", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Console.c", 314);
	nox_swprintf(getMemU16Ptr(0x5D4594, 833752), v1);
	nox_vswprintf(getMemU16Ptr(0x5D4594, 833778), a1, va);
	nox_fs_fprintf(nox_file_log, "%S", getMemAt(0x5D4594, 833752));
	nox_fs_flush(nox_file_log);
	v3 = nox_strman_loadString_40F1D0("FatalError", 0, (int)"C:\\NoxPost\\src\\Client\\Io\\Console.c", 324);
	// nullsub_4(nox_video_getWindow_401FD0(), getMemAt(0x5D4594, 833752), v3, 0);
	nox_fs_fprintf(nox_file_log, "exiting..\n");
	nox_fs_close(nox_file_log);
	if (*(unsigned int*)&dword_5d4594_823776)
		nox_xxx_freeFloorBuffer_430EF0();
	nox_input_pollEvents_4453A0();
	nox_input_pollEvents_4453A0();
	nox_exit(0);
}

//----- (004517A0) --------------------------------------------------------
wchar_t* sub_4517A0(wchar_t* a1, ...) {
	wchar_t* v1; // esi
	wchar_t* v2; // eax
	wchar_t* v5; // [esp-Ch] [ebp-Ch]
	va_list va;  // [esp+8h] [ebp+8h]

	va_start(va, a1);
	if (!nox_file_log)
		sub_451630();
	v1 = (wchar_t*)sub_451610();
	v2 = nox_strman_loadString_40F1D0("WarningHeader", 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 355);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 833752), v2);
	nox_vswprintf((wchar_t*)getMemAt(0x5D4594, 833770), a1, va);
	nox_fs_fprintf(nox_file_log, "%S", getMemAt(0x5D4594, 833752));
	nox_fs_flush(nox_file_log);
	v5 = nox_strman_loadString_40F1D0("WarningMessage", 0, "C:\\NoxPost\\src\\Client\\Io\\Console.c", 365);
	// nullsub_4(nox_video_getWindow_401FD0(), getMemAt(0x5D4594, 833752), v5, 0);
	return nox_wcsncpy(v1, (const wchar_t*)getMemAt(0x5D4594, 833752), 0x63u);
}

//----- (004515B0) --------------------------------------------------------
wchar_t* nox_xxx_unused_4515B0(wchar_t* a1, ...) {
	wchar_t* v1; // esi
	va_list va;  // [esp+8h] [ebp+8h]

	va_start(va, a1);
	if (!nox_file_log)
		sub_451630();
	v1 = (wchar_t*)sub_451610();
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 833752), a1, va);
	nox_fs_fprintf(nox_file_log, "%S", getMemAt(0x5D4594, 833752));
	nox_fs_flush(nox_file_log);
	return nox_wcsncpy(v1, (const wchar_t*)getMemAt(0x5D4594, 833752), 0x63u);
}
