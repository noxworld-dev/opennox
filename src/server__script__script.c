#include <stdbool.h>
#include <string.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "common/fs/nox_fs.h"
#include "operators.h"
#include "server__script__builtin.h"
#include "server__script__internal.h"
#include "server__script__script.h"

extern void* nox_script_activatedList_2487236;
extern unsigned int dword_5d4594_1599628;
extern unsigned int nox_frame_xxx_2598000;

_Static_assert(sizeof(nox_script_xxx_t) == 48, "wrong size of nox_script_xxx_t structure!");

void* nox_script_caller_3821964 = 0;
void* nox_script_trigger_3821968 = 0;
nox_script_xxx_t* nox_script_arr_xxx_1599636 = 0;
int nox_script_count_xxx_1599640 = 0;

char* nox_script_strings[1024] = {0};
unsigned int nox_script_strings_xxx = 0;
unsigned int nox_script_strings_cnt = 0;

int nox_script_stack[1024] = {0};
int nox_script_stack_top = 0;

unsigned int nox_script_stack_at(int i) {
	if (i < 0 || i >= 1024) {
		return 0;
	}
	return nox_script_stack[i];
}

//----- (00507230) --------------------------------------------------------
void nox_script_push(int val) {
	if (nox_script_stack_top < 1024) {
		nox_script_stack[nox_script_stack_top] = val;
		nox_script_stack_top++;
	}
}
void nox_script_pushf(float val) { nox_script_push(*((int*)&val)); }

//----- (00507250) --------------------------------------------------------
int nox_script_pop() {
	int i = nox_script_stack_top;
	if (nox_script_stack_top > 0) {
		i = --nox_script_stack_top;
	}
	return nox_script_stack[i];
}
float nox_script_popf() {
	int v = nox_script_pop();
	return *((float*)&v);
}

//----- (00507270) --------------------------------------------------------
int nox_script_nextInt(int** p) {
	int v = **p;
	++*p;
	return v;
}

//----- (00507280) --------------------------------------------------------
double nox_script_nextFloat(float** p) {
	double v = **p;
	++*p;
	return v;
}

//----- (005071D0) --------------------------------------------------------
int nox_script_indexByEvent(const char* a1) {
	if (nox_script_count_xxx_1599640 <= 0) {
		return -1;
	}
	for (int i = 0; i < nox_script_count_xxx_1599640; i++) {
		if (!strcmp(nox_script_arr_xxx_1599636[i].field_0, a1)) {
			return i;
		}
	}
	return -1;
}

void* nox_script_get_caller() { return nox_script_caller_3821964; }

void* nox_script_get_trigger() { return nox_script_trigger_3821968; }

//----- (00512E40) --------------------------------------------------------
int nox_script_addString_512E40(char* s) {
	if (nox_script_strings_cnt >= 1024) {
		return nox_script_strings_cnt - 1;
	}
	char* cstr = _strdup(s);
	int i = nox_script_strings_cnt;
	nox_script_strings[i] = cstr;
	nox_script_strings_cnt++;
	return i;
}

const char* nox_script_getString_512E40(int i) {
	if (i < 0 || i >= nox_script_strings_cnt) {
		return 0;
	}
	return nox_script_strings[i];
}

const char* nox_script_getField36(int i) { return nox_script_arr_xxx_1599636[i].field_36; }

unsigned int nox_script_getField40(int i) { return nox_script_arr_xxx_1599636[i].field_40; }

unsigned int nox_script_getField44(int i) { return nox_script_arr_xxx_1599636[i].field_44; }

//----- (004F5580) --------------------------------------------------------
int nox_xxx_xferReadScriptHandler_4F5580(int a1, char* a2) {
	bool v3;       // zf
	int v4;        // eax
	size_t v5;     // [esp+Ch] [ebp-408h]
	int v6;        // [esp+10h] [ebp-404h]
	char v7[1024]; // [esp+14h] [ebp-400h]

	v6 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 2u);
	if ((short)v6 > 1) {
		return 0;
	}
	if (*getMemU32Ptr(0x973F18, 3872) == 1) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
		if (v5 >= 0x400) {
			return 0;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(v7, v5);
		v3 = v5 == 0;
		v7[v5] = 0;
		if (!v3) {
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				strcpy(a2, v7);
			} else {
				*(unsigned int*)(a1 + 4) = nox_script_indexByEvent(v7);
			}
		}
	} else {
		if (nox_common_gameFlags_check_40A5C0(0x600000)) {
			if (a2) {
				v5 = strlen(a2);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(a2, v5);
				goto LABEL_16;
			}
		} else {
			v4 = *(unsigned int*)(a1 + 4);
			if (v4 != -1) {
				v5 = strlen(nox_script_arr_xxx_1599636[v4].field_0);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(nox_script_arr_xxx_1599636[*(unsigned int*)(a1 + 4)].field_0,
														 v5);
				goto LABEL_16;
			}
		}
		v5 = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
	}
LABEL_16:
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)a1, 4u);
	return 1;
}
// 4F5580: using guessed type char var_400[1024];

//----- (00502490) --------------------------------------------------------
#ifdef NOX_CGO
void nox_script_callByEvent_cgo(int eventCode, int a1, int a2);
#endif // NOX_CGO
unsigned char* nox_xxx_scriptCallByEventBlock_502490(int* a1, int a2, int a3, int eventCode) {
#ifdef NOX_CGO
	nox_script_callByEvent_cgo(eventCode, a2, a3);
#endif // NOX_CGO
	*getMemU32Ptr(0x5D4594, 1599076) = 0;
	int v3 = a1[0];
	if (*a1 & 1) {
		return 0;
	}

	int v4 = a1[1];
	if (v4 == -1) {
		return 0;
	}

	if (v3 & 2) {
		LOBYTE(v3) = v3 | 1;
		a1[0] = v3;
	}
	if (nox_script_stack_top) {
		sub_5025A0((int)a1, a2, a3);
		return getMemAt(0x5D4594, 1599076);
	}
	nox_script_callByIndex_507310(v4, a2, a3);
	if (nox_script_arr_xxx_1599636[a1[1]].stack_size) {
		*getMemU32Ptr(0x5D4594, 1599076) = nox_script_pop();
	}
	nox_script_stack_top = 0;

	if (nox_script_strings_xxx < nox_script_strings_cnt) {
		for (int i = nox_script_strings_xxx; i < nox_script_strings_cnt; i++) {
			free(nox_script_strings[i]);
			nox_script_strings[i] = 0;
		}
	}
	nox_script_strings_cnt = nox_script_strings_xxx;

	sub_5025E0(a1, a2, a3);
	if (*getMemU32Ptr(0x5D4594, 1599468) > 0) {
		nox_xxx_scriptCallByEventBlock_502490(*(int**)getMemAt(0x5D4594, 1599084), *getMemIntPtr(0x5D4594, 1599088),
											  *getMemIntPtr(0x5D4594, 1599092), 0);
	}
	return getMemAt(0x5D4594, 1599076);
}

//----- (00504F90) --------------------------------------------------------
int nox_server_mapRWScriptData_504F90() {
	int result; // eax
	char v1;    // [esp+3h] [ebp-5h]
	int v2;     // [esp+4h] [ebp-4h]

	v2 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v2, 2u);
	if ((short)v2 > 1) {
		return 0;
	}
	v1 = 0;
	if (nox_script_arr_xxx_1599636 && nox_common_gameFlags_check_40A5C0(1) &&
		!nox_common_gameFlags_check_40A5C0(0x400000)) {
		v1 = 1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v1, 1u);
	if (!v1) {
		return 1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(nox_script_arr_xxx_1599636[1].field_28,
											 4 * nox_script_arr_xxx_1599636[1].field_16);
	if (*getMemU32Ptr(0x973F18, 3872)) {
		result = sub_51AF80();
		if (!result) {
			return result;
		}
		return 1;
	}
	result = sub_51AEA0();
	if (result) {
		return 1;
	}
	return result;
}

//----- (00505800) --------------------------------------------------------
int nox_script_ncobj_readInt_505800(FILE* f) {
	int val;
	int n = nox_fs_fread(f, &val, 4);
	return n == 4 ? val : 0;
}

//----- (00505830) --------------------------------------------------------
bool nox_script_ncobj_readString_505830(FILE* f, int sz, char* dst) {
	int n = nox_fs_fread(f, dst, sz);
	dst[sz] = 0;
	return n == sz;
}

//----- (00505870) --------------------------------------------------------
bool nox_script_ncobj_readStringExpect_505870(FILE* f, const char* exp) {
	char buf[256];
	nox_script_ncobj_readString_505830(f, strlen(exp), buf);
	return strcmp(buf, exp) == 0;
}

//----- (00505360) --------------------------------------------------------
int nox_script_ncobj_parse_505360() {
	FILE* f = nox_fs_open("nc.obj");
	if (!f) {
		return 0;
	}
	if (!nox_script_ncobj_readStringExpect_505870(f, "SCRIPT03")) {
		nox_fs_close(f);
		return 0;
	}
	if (!nox_script_ncobj_readStringExpect_505870(f, "STRG")) {
		nox_fs_close(f);
		return 0;
	}
	nox_script_strings_xxx = nox_script_ncobj_readInt_505800(f);
	nox_script_strings_cnt = nox_script_strings_xxx;
	if (nox_script_strings_xxx > 0) {
		for (int i = 0; i < nox_script_strings_xxx; i++) {
			int n = nox_script_ncobj_readInt_505800(f);
			char* str = calloc(1, n + 1);
			nox_script_strings[i] = str;
			if (!nox_script_ncobj_readString_505830(f, n, str)) {
				nox_fs_close(f);
				return 0;
			}
		}
	}
	if (!nox_script_ncobj_readStringExpect_505870(f, "CODE")) {
		nox_fs_close(f);
		return 0;
	}
	nox_script_count_xxx_1599640 = nox_script_ncobj_readInt_505800(f);
	if (nox_script_count_xxx_1599640 < 0) {
		nox_script_count_xxx_1599640 = 0;
	}
	if (nox_script_count_xxx_1599640) {
		nox_script_arr_xxx_1599636 = calloc(1, sizeof(nox_script_xxx_t) * nox_script_count_xxx_1599640);
	}
	char buf[1024];
	for (int ind = 0; ind < nox_script_count_xxx_1599640; ind++) {
		if (!nox_script_ncobj_readStringExpect_505870(f, "FUNC")) {
			nox_fs_close(f);
			return 0;
		}
		nox_script_xxx_t* cur = &nox_script_arr_xxx_1599636[ind];

		int n = nox_script_ncobj_readInt_505800(f);
		cur->field_0 = calloc(1, n + 1);
		if (!nox_script_ncobj_readString_505830(f, n, cur->field_0)) {
			nox_fs_close(f);
			return 0;
		} else if (strlen(cur->field_0) >= 1024) {
			return 0;
		}
		strcpy(buf, cur->field_0);
		unsigned char* v14 = strtok(buf, "%");
		unsigned char* v16 = cur->field_0;
		int v19 = 0;
		while (1) {
			unsigned char v15 = v14[0];
			bool v17 = v15 < v16[0];
			if (v15 != v16[0]) {
				v19 = -(int)v17 - ((int)v17 - 1);
				break;
			}
			if (!v15) {
				v19 = 0;
				break;
			}
			unsigned char v18 = v14[1];
			v17 = v18 < v16[1];
			if (v18 != v16[1]) {
				v19 = -(int)v17 - ((int)v17 - 1);
				break;
			}
			if (!v18) {
				v19 = 0;
				break;
			}
			v14 += 2;
			v16 += 2;
		}
		if (v19) {
			nox_sprintf(buf, "%%%s", strtok(0, "%"));
			cur->field_36 = calloc(1, strlen(buf) + 1);
			strcpy(cur->field_36, buf);

			cur->field_40 = atoi(strtok(0, "%"));
			cur->field_44 = atoi(strtok(0, "%"));
		} else {
			cur->field_36 = 0;
			cur->field_40 = 0;
			cur->field_44 = 0;
		}
		cur->stack_size = nox_script_ncobj_readInt_505800(f);
		cur->size_28 = nox_script_ncobj_readInt_505800(f);
		if (!nox_script_ncobj_readStringExpect_505870(f, "SYMB")) {
			nox_fs_close(f);
			return 0;
		}
		int cntY = nox_script_ncobj_readInt_505800(f);
		if (ind == 0) {
			cntY++;
		}
		cur->field_12 = cntY;
		nox_script_ncobj_readInt_505800(f);
		if (cntY) {
			cur->field_20 = calloc(1, sizeof(unsigned int) * cntY);
			cur->field_24 = calloc(1, sizeof(unsigned int) * cntY);
		} else {
			cur->field_20 = 0;
			cur->field_24 = 0;
		}
		int j1 = 0;
		if (ind == 0) {
			j1 = 1;
			nox_script_arr_xxx_1599636[0].field_20[0] = 0;
			nox_script_arr_xxx_1599636[0].field_24[0] = 0;
		}
		int sum = 0;
		for (int j = j1; j < cntY; ++j) {
			int v = nox_script_ncobj_readInt_505800(f);
			cur->field_20[j] = v;
			cur->field_24[j] = sum;
			sum += v;
		}
		cur->field_16 = sum;
		if (sum) {
			cur->field_28 = calloc(1, 4 * sum);
		} else {
			cur->field_28 = 0;
		}
		if (!nox_script_ncobj_readStringExpect_505870(f, "DATA")) {
			nox_fs_close(f);
			return 0;
		}
		n = nox_script_ncobj_readInt_505800(f);
		cur->data = calloc(1, n);
		if (nox_fs_fread(f, cur->data, n) != n) {
			nox_fs_close(f);
			return 0;
		}
	}
	if (!nox_script_ncobj_readStringExpect_505870(f, "DONE")) {
		nox_fs_close(f);
		return 0;
	}
	nox_fs_close(f);
	return 1;
}

//----- (005058F0) --------------------------------------------------------
void nox_script_freeEverything_5058F0() {
	if (nox_script_strings_xxx < nox_script_strings_cnt) {
		for (int i = nox_script_strings_xxx; i < nox_script_strings_cnt; i++) {
			free(nox_script_strings[i]);
			nox_script_strings[i] = 0;
		}
	}
	if (nox_script_strings_xxx > 0) {
		for (int i = 0; i < nox_script_strings_xxx; i++) {
			free(nox_script_strings[i]);
			nox_script_strings[i] = 0;
		}
	}
	nox_script_strings_xxx = 0;
	dword_5d4594_1599628 = 0;
	nox_script_strings_cnt = 0;

	if (nox_script_arr_xxx_1599636) {
		for (int i = 0; i < nox_script_count_xxx_1599640; i++) {
			if (nox_script_arr_xxx_1599636[i].field_0) {
				free(nox_script_arr_xxx_1599636[i].field_0);
			}
			if (nox_script_arr_xxx_1599636[i].field_36) {
				free(nox_script_arr_xxx_1599636[i].field_36);
			}
			if (nox_script_arr_xxx_1599636[i].field_20) {
				free(nox_script_arr_xxx_1599636[i].field_20);
			}
			if (nox_script_arr_xxx_1599636[i].field_24) {
				free(nox_script_arr_xxx_1599636[i].field_24);
			}
			if (nox_script_arr_xxx_1599636[i].field_28) {
				free(nox_script_arr_xxx_1599636[i].field_28);
			}
			if (nox_script_arr_xxx_1599636[i].data) {
				free(nox_script_arr_xxx_1599636[i].data);
			}
		}
		free(nox_script_arr_xxx_1599636);
		nox_script_arr_xxx_1599636 = 0;
	}
	nox_script_count_xxx_1599640 = 0;
}

//----- (00507290) --------------------------------------------------------
void nox_xxx_scriptRunFirst_507290() {
	nox_script_resetBuiltin();
	if (nox_script_arr_xxx_1599636) {
		char* f28 = nox_script_arr_xxx_1599636[1].field_28;
		*(unsigned int*)(f28 + 0) = -2;
		*(unsigned int*)(f28 + 4) = -1;
		*(unsigned int*)(f28 + 8) = 1;
		*(unsigned int*)(f28 + 12) = 0;
		if (!nox_xxx_gameIsSwitchToSolo_4DB240()) {
			nox_script_callByIndex_507310(1, 0, 0);
		}
	}
}

//----- (00507310) --------------------------------------------------------
void nox_script_callByIndex_507310(int index, void* a2, void* a3) {
	char buf[256]; // [esp+28h] [ebp-100h]

	nox_script_xxx_t* script = &nox_script_arr_xxx_1599636[index];

	nox_script_caller_3821964 = a2;
	nox_script_trigger_3821968 = a3;
	for (int i = 0; i < script->size_28; i++) {
		int v = nox_script_pop();
		script->field_28[i] = v;
	}
	int bstack = nox_script_stack_top;
	void* data = script->data;
	while (1) {
		int sa1 = 0;
		int sa2 = 0;
		int sa3 = 0;
		int sa4 = 0;
		int sa5 = 0;
		float sf1 = 0;
		float sf2 = 0;
		switch (nox_script_nextInt(&data)) {
		case 0:
		case 3: // get xxx int
			sa1 = nox_script_nextInt(&data);
			sa2 = nox_script_nextInt(&data);
			if (sa1) {
				if (nox_script_arr_xxx_1599636[1].field_24 && nox_script_arr_xxx_1599636[1].field_28) {
					sa2 = nox_script_arr_xxx_1599636[1].field_24[sa2];
					sa2 = nox_script_arr_xxx_1599636[1].field_28[sa2];
				} else {
					sa2 = 0;
				}
				nox_script_push(sa2);
			} else if (sa2 < 0) {
				sa2 = -sa2;
				sa2 = nox_script_arr_xxx_1599636[0].field_24[sa2];
				sa2 = *(unsigned int*)(*(unsigned int*)((int)a3 + 760) + 4 * sa2);
				nox_script_push(sa2);
			} else if (script->field_24 && script->field_28) {
				sa2 = script->field_24[sa2];
				sa2 = script->field_28[sa2];
				nox_script_push(sa2);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 1: // get xxx float
			sa1 = nox_script_nextInt(&data);
			sa2 = nox_script_nextInt(&data);
			if (sa1) {
				if (nox_script_arr_xxx_1599636[1].field_24 && nox_script_arr_xxx_1599636[1].field_28) {
					sa2 = nox_script_arr_xxx_1599636[1].field_24[sa2];
					sf1 = *(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					sf1 = 0;
				}
			} else if (sa2 < 0) {
				sa2 = -sa2;
				sa2 = nox_script_arr_xxx_1599636[0].field_24[sa2];
				sf1 = *(float*)(*(unsigned int*)((int)a3 + 760) + 4 * sa2);
			} else if (script->field_24 && script->field_28) {
				sa2 = script->field_24[sa2];
				sf1 = *(float*)((unsigned int)(script->field_28) + 4 * sa2);
			} else {
				sf1 = 0;
			}
			nox_script_pushf(sf1);
			continue;
		case 2:
			sa1 = nox_script_nextInt(&data);
			sa2 = nox_script_nextInt(&data);
			if (sa1) {
				sa3 = nox_script_arr_xxx_1599636[1].field_20[sa2];
				sa4 = nox_script_arr_xxx_1599636[1].field_24[sa2];
			} else if (sa2 < 0) {
				sa2 = -sa2;
				sa3 = nox_script_arr_xxx_1599636[0].field_20[sa2];
				sa4 = -nox_script_arr_xxx_1599636[0].field_24[sa2];
			} else if (script->field_20 && script->field_24) {
				sa3 = script->field_20[sa2];
				sa4 = script->field_24[sa2];
			} else {
				sa3 = 0;
				sa4 = 0; // soft fail
			}
			if (sa3 > 1) {
				nox_script_push(sa3);
			}
			nox_script_push(sa1);
			nox_script_push(sa4);
			continue;
		case 4:
		case 6: // static int
			sa1 = nox_script_nextInt(&data);
			nox_script_push(sa1);
			continue;
		case 5: // static float
			sf1 = nox_script_nextFloat(&data);
			nox_script_pushf(sf1);
			continue;
		case 7: // add int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 + sa1);
			continue;
		case 8: // add float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			sf1 += sf2;
			nox_script_pushf(sf1);
			continue;
		case 9: // sub int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 - sa1);
			continue;
		case 10: // sub float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			sf2 -= sf1;
			nox_script_pushf(sf2);
			continue;
		case 11: // mult int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa1 * sa2);
			continue;
		case 12: // mult float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			sf1 *= sf2;
			nox_script_pushf(sf1);
			continue;
		case 13: // div int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 / sa1);
			continue;
		case 14: // div float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			sf2 /= sf1;
			nox_script_pushf(sf2);
			continue;
		case 15: // mod int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 % sa1);
			continue;
		case 16: // bit mult int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 & sa1);
			continue;
		case 17: // bit or int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 | sa1);
			continue;
		case 18: // bit xor int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 ^ sa1);
			continue;
		case 19: // jump
			data = (unsigned int)(script->data) + 4 * nox_script_nextInt(&data);
			continue;
		case 20: // jump if
			sa1 = nox_script_nextInt(&data);
			if (nox_script_pop()) {
				data = (unsigned int)(script->data) + 4 * sa1;
			}
			continue;
		case 21: // jump if not
			sa1 = nox_script_nextInt(&data);
			if (!nox_script_pop()) {
				data = (unsigned int)(script->data) + 4 * sa1;
			}
			continue;
		case 22:
		case 24: // set xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] = sa1;
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) = sa1;
			} else if (script->field_28) {
				script->field_28[sa2] = sa1;
			}
			nox_script_push(sa1);
			continue;
		case 23: // set xxx float
			sf1 = nox_script_popf();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa2]) = sf1;
				}
			} else if (sa2 < 0) {
				*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) = sf1;
			} else if (script->field_28) {
				*(float*)(&script->field_28[sa2]) = sf1;
			}
			nox_script_pushf(sf1);
			continue;
		case 25: // mult xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] *= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) *= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] *= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 26: // mult xxx float
			sf1 = nox_script_popf();
			sa1 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]) *= sf1;
					nox_script_pushf(*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]));
				} else {
					nox_script_pushf(0); // soft fail
				}
			} else if (sa1 < 0) {
				*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1) *= sf1;
				nox_script_pushf(*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1));
			} else if (script->field_28) {
				*(float*)(&script->field_28[sa1]) *= sf1;
				nox_script_pushf(*(float*)(&script->field_28[sa1]));
			} else {
				nox_script_pushf(0); // soft fail
			}
			continue;
		case 27: // div xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] /= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) /= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] /= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 28: // div xxx float
			sf1 = nox_script_popf();
			sa1 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]) /= sf1;
					nox_script_pushf(*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]));
				} else {
					nox_script_pushf(0); // soft fail
				}
			} else if (sa1 < 0) {
				*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1) /= sf1;
				nox_script_pushf(*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1));
			} else if (script->field_28) {
				*(float*)(&script->field_28[sa1]) /= sf1;
				nox_script_pushf(*(float*)(script->field_28[sa1]));
			} else {
				nox_script_pushf(0); // soft fail
			}
			continue;
		case 29: // add xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] += sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) += sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] += sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 30: // add xxx float
			sf1 = nox_script_popf();
			sa1 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]) += sf1;
					nox_script_pushf(*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]));
				} else {
					nox_script_pushf(0); // soft fail
				}
			} else if (sa1 < 0) {
				*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1) += sf1;
				nox_script_pushf(*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1));
			} else if (script->field_28) {
				*(float*)(&script->field_28[sa1]) += sf1;
				nox_script_pushf(*(float*)(&script->field_28[sa1]));
			} else {
				nox_script_pushf(0); // soft fail
			}
			continue;
		case 31: // cat xxx string
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = nox_script_pop();
			if (sa3) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					sa4 = nox_script_arr_xxx_1599636[1].field_28[sa2];
				} else {
					sa4 = 0;
				}
			} else if (sa2 < 0) {
				sa4 = *(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2);
			} else {
				sa4 = script->field_28[sa2];
			}
			nox_sprintf(buf, "%s%s", nox_script_getString_512E40(sa4), nox_script_getString_512E40(sa1));
			sa4 = nox_script_addString_512E40(buf);
			if (sa3) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] = sa4;
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) = sa4;
			} else if (script->field_28) {
				script->field_28[sa2] = sa4;
			}
			nox_script_push(sa4);
			continue;
		case 32: // sub xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] -= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) -= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] -= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 33: // sub xxx float
			sf1 = nox_script_popf();
			sa1 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]) -= sf1;
					nox_script_pushf(*(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1]));
				} else {
					nox_script_pushf(0); // soft fail
				}
			} else if (sa1 < 0) {
				*(float*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1) -= sf1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa1));
			} else if (script->field_28) {
				*(float*)(&script->field_28[sa1]) -= sf1;
				nox_script_pushf(*(float*)((unsigned int)(script->field_28) + 4 * sa1));
			} else {
				nox_script_pushf(0); // soft fail
			}
			continue;
		case 34: // mod xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] %= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) %= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] %= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 35: // equal int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 == sa1);
			continue;
		case 36: // equal float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			nox_script_push(sf2 == sf1);
			continue;
		case 37: // equal string
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(strcmp(nox_script_getString_512E40(sa2), nox_script_getString_512E40(sa1)) == 0);
			continue;
		case 38: // left shift
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 << sa1);
			continue;
		case 39: // right shift
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 >> sa1);
			continue;
		case 40: // < int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 < sa1);
			continue;
		case 41: // < float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			nox_script_push(sf2 < sf1);
			continue;
		case 42: // < string ?
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = strcmp(nox_script_getString_512E40(sa2), nox_script_getString_512E40(sa1));
			if (sa3) {
				nox_script_push(-(sa3 < 0) - ((sa3 < 0) - 1) < 0);
			} else {
				nox_script_push(0);
			}
			continue;
		case 43: // > int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 > sa1);
			continue;
		case 44: // > float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			nox_script_push(sf2 > sf1);
			continue;
		case 45: // > string ?
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = strcmp(nox_script_getString_512E40(sa2), nox_script_getString_512E40(sa1));
			if (sa3) {
				nox_script_push(-(sa3 < 0) - ((sa3 < 0) - 1) > 0);
			} else {
				nox_script_push(0);
			}
			continue;
		case 46: // <= int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 <= sa1);
			continue;
		case 47: // <= float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			nox_script_push(sf2 <= sf1);
			continue;
		case 48: // <= string ?
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = strcmp(nox_script_getString_512E40(sa2), nox_script_getString_512E40(sa1));
			if (sa3) {
				nox_script_push(-(sa3 < 0) - ((sa3 < 0) - 1) <= 0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 49: // >= int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 >= sa1);
			continue;
		case 50: // >= float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			nox_script_push(sf2 >= sf1);
			continue;
		case 51: // >= string ?
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = strcmp(nox_script_getString_512E40(sa2), nox_script_getString_512E40(sa1));
			if (sa3) {
				nox_script_push(-(sa3 < 0) - ((sa3 < 0) - 1) >= 0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 52: // not equal int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 != sa1);
			continue;
		case 53: // not equal float
			sf1 = nox_script_popf();
			sf2 = nox_script_popf();
			nox_script_push(sf2 != sf1);
			continue;
		case 54: // not equal string
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(strcmp(nox_script_getString_512E40(sa2), nox_script_getString_512E40(sa1)) != 0);
			continue;
		case 55: // logical and
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 && sa1);
			continue;
		case 56: // logical or
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_script_push(sa2 || sa1);
			continue;
		case 57: // left shift xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] <<= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) <<= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] <<= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 58: // right shift xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] >>= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) >>= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] >>= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 59: // bit mult xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] &= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) &= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] &= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 60: // bit or xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] |= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) |= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] |= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 61: // bit xor xxx int
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			if (nox_script_pop()) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					nox_script_arr_xxx_1599636[1].field_28[sa2] ^= sa1;
					nox_script_push(nox_script_arr_xxx_1599636[1].field_28[sa2]);
				} else {
					nox_script_push(0); // soft fail
				}
			} else if (sa2 < 0) {
				*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2) ^= sa1;
				nox_script_push(*(unsigned int*)(*(unsigned int*)((int)a3 + 760) - 4 * sa2));
			} else if (script->field_28) {
				script->field_28[sa2] ^= sa1;
				nox_script_push(script->field_28[sa2]);
			} else {
				nox_script_push(0); // soft fail
			}
			continue;
		case 62: // not int
			sa1 = nox_script_pop();
			nox_script_push(sa1 == 0);
			continue;
		case 63: // invert int
			sa1 = nox_script_pop();
			nox_script_push(~sa1);
			continue;
		case 64: // negate int
			sa1 = nox_script_pop();
			nox_script_push(-sa1);
			continue;
		case 65: // negate float
			sf1 = -nox_script_popf();
			nox_script_pushf(sf1);
			continue;
		case 66:
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = nox_script_pop();
			sa4 = nox_script_pop();
			sa5 = 0;
			if (sa1 < 0 || sa1 >= sa4) {
				sa5 = 1;
			}
			if (sa3) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					sa4 = nox_script_arr_xxx_1599636[1].field_28[sa1 + sa2];
				} else {
					sa4 = 0;
				}
			} else if (sa2 < 0) {
				sa4 = *(unsigned int*)(*(unsigned int*)((int)a3 + 760) + 4 * (sa2 - sa1));
			} else if (script->field_28) {
				sa4 = script->field_28[sa1 + sa2];
			} else {
				sa4 = 0; // soft fail
			}
			nox_script_push(sa4);
			if (sa5) {
				break;
			}
			continue;
		case 67:
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = nox_script_pop();
			sa4 = nox_script_pop();
			sa5 = 0;
			if (sa1 < 0 || sa1 > sa4) {
				sa5 = 1;
			}
			if (sa3) {
				if (nox_script_arr_xxx_1599636[1].field_28) {
					sf1 = *(float*)(&nox_script_arr_xxx_1599636[1].field_28[sa1 + sa2]);
				} else {
					sf1 = 0;
				}
			} else if (sa2 < 0) {
				sf1 = *(float*)(*(unsigned int*)((int)a3 + 760) + 4 * (sa2 - sa1));
			} else if (script->field_28) {
				sf1 = *(float*)(&script->field_28[sa1 + sa2]);
			} else {
				sf1 = 0; // soft fail
			}
			nox_script_pushf(sf1);
			if (sa5) {
				break;
			}
			continue;
		case 68:
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			sa3 = nox_script_pop();
			sa4 = nox_script_pop();
			sa5 = 0;
			if (sa1 < 0 || sa1 > sa4) {
				sa5 = 1;
			}
			nox_script_push(sa3);
			if (sa2 < 0) {
				nox_script_push(sa2 - sa1);
			} else {
				nox_script_push(sa2 + sa1);
			}
			if (sa5) {
				break;
			}
			continue;
		case 69: // call builtin
			sa1 = nox_script_nextInt(&data);
			if (nox_script_callBuiltin_508B70(index, sa1) == 1) {
				break;
			}
			continue;
		case 70: // call script
			sa1 = nox_script_nextInt(&data);
			nox_script_callByIndex_507310(sa1, a2, a3);
			continue;
		case 73: // string cat
			sa1 = nox_script_pop();
			sa2 = nox_script_pop();
			nox_sprintf(buf, "%s%s", nox_script_getString_512E40(sa2), nox_script_getString_512E40(sa1));
			sa3 = nox_script_addString_512E40(buf);
			nox_script_push(sa3);
			continue;
		default:
			break;
		}
		if (nox_script_stack_top != script->stack_size + bstack) {
			if (script->stack_size) {
				if (nox_script_stack_top) {
					int v = nox_script_pop();
					nox_script_stack_top = bstack;
					nox_script_push(v);
				} else {
					nox_script_stack_top = bstack;
					nox_script_push(0);
				}
			} else {
				nox_script_stack_top = bstack;
			}
		}
		return;
	}
}

//----- (00508CB0) --------------------------------------------------------
int sub_508CB0(unsigned int* a1, int a2) {
	int v2;           // edi
	int result;       // eax
	int v4;           // ecx
	unsigned int* v5; // esi
	unsigned int* v6; // esi
	int v7;           // esi
	unsigned int* v8; // esi

	v2 = a1[189];
	if (!v2) {
		return 0;
	}
	if (a2 == 14) {
		if (nox_common_gameFlags_check_40A5C0(0x600000)) {
			result = v2;
		} else {
			result = nox_script_arr_xxx_1599636[a1[192]].field_0;
		}
		return result;
	}
	v4 = a1[2];
	if (v4 & 0x200) {
		v5 = (unsigned int*)a1[187];
		if (a2) {
			if (a2 != 1) {
				if (a2 == 2) {
					if (nox_common_gameFlags_check_40A5C0(0x600000)) {
						result = v2 + 384;
					} else {
						result = nox_script_arr_xxx_1599636[v5[8]].field_0;
					}
					return result;
				}
				return 0;
			}
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 256;
			} else {
				result = nox_script_arr_xxx_1599636[v5[6]].field_0;
			}
		} else if (nox_common_gameFlags_check_40A5C0(0x600000)) {
			result = v2 + 512;
		} else {
			result = nox_script_arr_xxx_1599636[v5[4]].field_0;
		}
	} else if (v4 & 2) {
		v6 = (unsigned int*)a1[187];
		switch (a2) {
		case 3:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 640;
			} else {
				result = nox_script_arr_xxx_1599636[v6[309]].field_0;
			}
			break;
		case 4:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 768;
			} else {
				result = nox_script_arr_xxx_1599636[v6[307]].field_0;
			}
			break;
		case 5:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 896;
			} else {
				result = nox_script_arr_xxx_1599636[v6[317]].field_0;
			}
			break;
		case 6:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1024;
			} else {
				result = nox_script_arr_xxx_1599636[v6[311]].field_0;
			}
			break;
		case 7:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1152;
			} else {
				result = nox_script_arr_xxx_1599636[v6[313]].field_0;
			}
			break;
		case 8:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1280;
			} else {
				result = nox_script_arr_xxx_1599636[v6[315]].field_0;
			}
			break;
		case 9:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1408;
			} else {
				result = nox_script_arr_xxx_1599636[v6[319]].field_0;
			}
			break;
		case 10:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1536;
			} else {
				result = nox_script_arr_xxx_1599636[v6[321]].field_0;
			}
			break;
		case 11:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1664;
			} else {
				result = nox_script_arr_xxx_1599636[v6[323]].field_0;
			}
			break;
		case 13:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1792;
			} else {
				result = nox_script_arr_xxx_1599636[v6[325]].field_0;
			}
			break;
		default:
			return 0;
		}
	} else if (v4 & 0x800) {
		v7 = a1[175];
		if (a2 != 12) {
			return 0;
		}
		if (nox_common_gameFlags_check_40A5C0(0x600000)) {
			result = v2 + 128;
		} else {
			result = nox_script_arr_xxx_1599636[*(unsigned int*)(v7 + 4)].field_0;
		}
	} else {
		if (!(v4 & 0x20000)) {
			return 0;
		}
		v8 = (unsigned int*)a1[187];
		switch (a2) {
		case 15:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1920;
			} else {
				result = nox_script_arr_xxx_1599636[v8[13]].field_0;
			}
			break;
		case 16:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 2048;
			} else {
				result = nox_script_arr_xxx_1599636[v8[15]].field_0;
			}
			break;
		case 17:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 2304;
			} else {
				result = nox_script_arr_xxx_1599636[v8[17]].field_0;
			}
			break;
		case 18:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 2176;
			} else {
				result = nox_script_arr_xxx_1599636[v8[19]].field_0;
			}
			break;
		default:
			return 0;
		}
	}
	return result;
}

//----- (0051ADF0) --------------------------------------------------------
void nox_xxx_scriptLeverReact_51ADF0() {
	uint32_t* v0; // esi
	int v1;       // edi
	int v2;       // ebx
	int v3;       // ebp

	v0 = *(uint32_t**)&nox_script_activatedList_2487236;
	if (nox_script_activatedList_2487236) {
		do {
			if (*v0 > nox_frame_xxx_2598000) {
				v0 = (uint32_t*)v0[6];
			} else {
				v1 = v0[1];
				v2 = v0[5];
				v3 = v0[4];
				if (nox_script_arr_xxx_1599636[v1].size_28) {
					nox_script_push(v0[2]);
				}
				v0 = (uint32_t*)nox_xxx_scriptAct_51AD90((int)v0);
				nox_script_callByIndex_507310(v1, v2, v3);
			}
		} while (v0);
	}
}

#ifndef NOX_CGO
//----- (00511B60) --------------------------------------------------------
nox_object_t* nox_server_scriptValToObjectPtr_511B60(int val) {
	if (val == -1) {
		nox_object_t* obj = nox_script_get_caller();
		if (!obj || (obj->field_4 & 0x20) != 0) {
			return 0;
		}
		return obj;
	}
	if (val == -2) {
		nox_object_t* obj = nox_script_get_trigger();
		if (!obj || (obj->field_4 & 0x20) != 0) {
			return 0;
		}
		return obj;
	}
	nox_object_t* obj1 = nox_xxx_script_511C50(val);
	if (obj1) {
		return obj1;
	}

	for (nox_object_t* obj = nox_server_getFirstObject_4DA790(); obj; obj = nox_server_getNextObject_4DA7A0(obj)) {
		if ((obj->field_4 & 0x20) == 0 && obj->script_id == val) {
			nox_xxx_scriptPrepareFoundUnit_511D70(obj);
			return obj;
		}
		for (nox_object_t* sub = obj->field_126; sub; sub = sub->field_124) {
			if ((sub->field_4 & 0x20) == 0 && sub->script_id == val) {
				nox_xxx_scriptPrepareFoundUnit_511D70(sub);
				return sub;
			}
		}
	}
	for (nox_object_t* obj = nox_server_getFirstObjectUninited_4DA870(); obj;
		 obj = nox_server_getNextObjectUninited_4DA880(obj)) {
		if ((obj->field_4 & 0x20) == 0 && obj->script_id == val) {
			nox_xxx_scriptPrepareFoundUnit_511D70(obj);
			return obj;
		}
	}
	return 0;
}
#endif // NOX_CGO

//----- (0051B0C0) --------------------------------------------------------
void sub_51B0C0() {
	int* v0; // esi

	v0 = *(int**)&nox_script_activatedList_2487236;
	if (nox_script_activatedList_2487236) {
		do {
			if (v0[4]) {
				v0[4] = nox_server_scriptValToObjectPtr_511B60(v0[4]);
			}
			if (v0[5]) {
				v0[5] = nox_server_scriptValToObjectPtr_511B60(v0[5]);
			}
			v0 = (int*)v0[6];
		} while (v0);
	}
}

#ifndef NOX_CGO
void nox_script_callOnEvent(const char* event, void* a1, void* a2) {
	int n = strlen(event);
	for (int i = 0; i < nox_script_count_xxx_1599640; i++) {
		if (!strncmp(event, nox_script_arr_xxx_1599636[i].field_0, n)) {
			nox_script_callByIndex_507310(i, a1, a2);
		}
	}
}
#endif // NOX_CGO
