#include "../../../proto.h"

// TODO: convert table_272352

//----- (004F3A60) --------------------------------------------------------
int __cdecl sub_4F3A60_obj_pickup(int a1, int a2, int a3) {
	int* v3;     // edi
	wchar_t* v4; // eax
	int result;  // eax
	int v6;      // edi
	int v7;      // [esp-8h] [ebp-10h]

	if (*(_BYTE*)(a1 + 8) & 4) {
		v3 = *(int**)(a2 + 692);
		sub_4FA590(a1, *v3);
		sub_4E5CC0(a2);
		v7 = *v3;
		v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 215812), 0,
								   "C:\\NoxPost\\src\\Server\\Object\\pickdrop\\pickup.c", 709);
		sub_4D9EB0(a1, v4, v7);
		sub_501960(307, a1, 0, 0);
		result = 1;
	} else {
		v6 = sub_4F31E0(a1, a2, a3);
		if (v6)
			sub_501960(307, a1, 0, 0);
		result = v6;
	}
	return result;
}