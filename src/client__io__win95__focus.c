#include "client__io__win95__focus.h"

#include "client__gui__window.h"
#include "client__io__console.h"
#include "common__strman.h"

extern obj_5D4594_754088_t* ptr_5D4594_754088;
extern int ptr_5D4594_754088_cnt;

extern obj_5D4594_754088_t* ptr_5D4594_754092;
extern int ptr_5D4594_754092_cnt;

//----- (0042EBB0) --------------------------------------------------------
void  sub_42EBB0(unsigned int a1, void (*fnc)(int), int field_4, const char* name) {
	wchar_t* v6; // eax
	wchar_t* v8; // eax

	if (a1 == 1) {
		obj_5D4594_754088_t* arr =
			(obj_5D4594_754088_t*)realloc(ptr_5D4594_754088, sizeof(obj_5D4594_754088_t) * (ptr_5D4594_754088_cnt + 1));
		ptr_5D4594_754088 = arr;
		if (!arr) {
			v6 = nox_strman_loadString_40F1D0("MallocFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\focus.c",
									   37);
			sub_4516C0(v6);
			nox_exit(-1);
		}
		arr[ptr_5D4594_754088_cnt].fnc = fnc;
		arr[ptr_5D4594_754088_cnt].field_4 = field_4;
		strcpy(arr[ptr_5D4594_754088_cnt].name, name);
		++ptr_5D4594_754088_cnt;
	} else if (a1 == 2) {
		obj_5D4594_754088_t* arr =
			realloc(ptr_5D4594_754092, sizeof(obj_5D4594_754088_t) * (ptr_5D4594_754092_cnt + 1));
		ptr_5D4594_754092 = arr;
		if (!arr) {
			v8 = nox_strman_loadString_40F1D0("MallocFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\focus.c",
									   52);
			sub_4516C0(v8);
			nox_exit(-1);
		}
		arr[ptr_5D4594_754092_cnt].fnc = fnc;
		arr[ptr_5D4594_754092_cnt].field_4 = field_4;
		int sz = strlen(name) + 1;
		memcpy(arr[ptr_5D4594_754092_cnt].name, name, sz);
		++ptr_5D4594_754092_cnt;
	}
}
