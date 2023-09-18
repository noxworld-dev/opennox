#include <stdbool.h>
#include <string.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "common/fs/nox_fs.h"
#include "common__crypt.h"
#include "operators.h"
#include "server__script__builtin.h"
#include "server__script__internal.h"
#include "server__script__script.h"
#include "server__script__activator.h"

extern unsigned int dword_5d4594_1599628;

_Static_assert(sizeof(nox_script_xxx_t) == 48, "wrong size of nox_script_xxx_t structure!");

nox_script_xxx_t* nox_script_arr_xxx_1599636 = 0;
int nox_script_count_xxx_1599640 = 0;

char* nox_script_strings[1024] = {0};
unsigned int nox_script_strings_xxx = 0;
unsigned int nox_script_strings_cnt = 0;

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
	if (nox_crypt_IsReadOnly() == 1) {
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
				v5 = strlen(nox_script_arr_xxx_1599636[v4].name);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(nox_script_arr_xxx_1599636[*(unsigned int*)(a1 + 4)].name,
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
	if (nox_crypt_IsReadOnly()) {
		result = nox_script_activatorLoad_51AF80();
		if (!result) {
			return result;
		}
		return 1;
	}
	result = nox_script_activatorSave_51AEA0();
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
		cur->name = calloc(1, n + 1);
		if (!nox_script_ncobj_readString_505830(f, n, cur->name)) {
			nox_fs_close(f);
			return 0;
		} else if (strlen(cur->name) >= 1024) {
			return 0;
		}
		strcpy(buf, cur->name);
		unsigned char* v14 = strtok(buf, "%");
		unsigned char* v16 = cur->name;
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
			cur->suff = calloc(1, strlen(buf) + 1);
			strcpy(cur->suff, buf);

			cur->field_40 = atoi(strtok(0, "%"));
			cur->field_44 = atoi(strtok(0, "%"));
		} else {
			cur->suff = 0;
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
			if (nox_script_arr_xxx_1599636[i].name) {
				free(nox_script_arr_xxx_1599636[i].name);
			}
			if (nox_script_arr_xxx_1599636[i].suff) {
				free(nox_script_arr_xxx_1599636[i].suff);
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
			result = nox_script_arr_xxx_1599636[a1[192]].name;
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
						result = nox_script_arr_xxx_1599636[v5[8]].name;
					}
					return result;
				}
				return 0;
			}
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 256;
			} else {
				result = nox_script_arr_xxx_1599636[v5[6]].name;
			}
		} else if (nox_common_gameFlags_check_40A5C0(0x600000)) {
			result = v2 + 512;
		} else {
			result = nox_script_arr_xxx_1599636[v5[4]].name;
		}
	} else if (v4 & 2) {
		v6 = (unsigned int*)a1[187];
		switch (a2) {
		case 3:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 640;
			} else {
				result = nox_script_arr_xxx_1599636[v6[309]].name;
			}
			break;
		case 4:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 768;
			} else {
				result = nox_script_arr_xxx_1599636[v6[307]].name;
			}
			break;
		case 5:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 896;
			} else {
				result = nox_script_arr_xxx_1599636[v6[317]].name;
			}
			break;
		case 6:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1024;
			} else {
				result = nox_script_arr_xxx_1599636[v6[311]].name;
			}
			break;
		case 7:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1152;
			} else {
				result = nox_script_arr_xxx_1599636[v6[313]].name;
			}
			break;
		case 8:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1280;
			} else {
				result = nox_script_arr_xxx_1599636[v6[315]].name;
			}
			break;
		case 9:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1408;
			} else {
				result = nox_script_arr_xxx_1599636[v6[319]].name;
			}
			break;
		case 10:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1536;
			} else {
				result = nox_script_arr_xxx_1599636[v6[321]].name;
			}
			break;
		case 11:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1664;
			} else {
				result = nox_script_arr_xxx_1599636[v6[323]].name;
			}
			break;
		case 13:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 1792;
			} else {
				result = nox_script_arr_xxx_1599636[v6[325]].name;
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
			result = nox_script_arr_xxx_1599636[*(unsigned int*)(v7 + 4)].name;
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
				result = nox_script_arr_xxx_1599636[v8[13]].name;
			}
			break;
		case 16:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 2048;
			} else {
				result = nox_script_arr_xxx_1599636[v8[15]].name;
			}
			break;
		case 17:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 2304;
			} else {
				result = nox_script_arr_xxx_1599636[v8[17]].name;
			}
			break;
		case 18:
			if (nox_common_gameFlags_check_40A5C0(0x600000)) {
				result = v2 + 2176;
			} else {
				result = nox_script_arr_xxx_1599636[v8[19]].name;
			}
			break;
		default:
			return 0;
		}
	}
	return result;
}
