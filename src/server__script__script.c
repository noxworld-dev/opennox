#include <string.h>
#include <stdbool.h>

#include "server__script__script.h"
#include "server__script__builtin.h"
#include "nox_fs.h"
#include "proto.h"

extern unsigned int dword_5d4594_2487236;
extern unsigned int dword_5d4594_1599628;


typedef struct nox_script_xxx_t {
	char* field_0; // 0, 0
	unsigned int field_4; // 1, 4
	int field_8; // 2, 8
	unsigned int field_12; // 3, 12; len field_20 and field_24
	unsigned int field_16; // 4, 16
	unsigned int* field_20; // 5, 20
	unsigned int* field_24; // 6, 24
	void* field_28; // 7, 28; float[]?
	void* data; // 8, 32
	char* field_36; // 9, 36
	unsigned int field_40; // 10, 40
	unsigned int field_44; // 11, 44
} nox_script_xxx_t;
_Static_assert(sizeof(nox_script_xxx_t) == 48, "wrong size of nox_script_xxx_t structure!");

nox_script_xxx_t* nox_script_arr_xxx_1599636 = 0;
int nox_script_count_xxx_1599640 = 0;

unsigned int dword_5d4594_3821964 = 0;
unsigned int dword_5d4594_3821968 = 0;

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

//----- (00507250) --------------------------------------------------------
int nox_script_pop() {
	int i = nox_script_stack_top;
	if (nox_script_stack_top > 0) {
		i = --nox_script_stack_top;
	}
	return nox_script_stack[i];
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
int  nox_script_indexByEvent(const char* a1) {
	if (nox_script_count_xxx_1599640 <= 0)
		return -1;
	for (int i = 0; i < nox_script_count_xxx_1599640; i++) {
		if (!strcmp(nox_script_arr_xxx_1599636[i].field_0, a1)) {
			return i;
		}
	}
	return -1;
}

//----- (00512E40) --------------------------------------------------------
int nox_script_addString_512E40(char* s) {
	if (nox_script_strings_cnt >= 1024)
		return nox_script_strings_cnt - 1;
	char* cstr = _strdup(s);
	int i = nox_script_strings_cnt;
	nox_script_strings[i] = cstr;
	nox_script_strings_cnt++;
	return i;
}

const char* nox_script_getString_512E40(int i) {
	if (i < 0 || i >= nox_script_strings_cnt)
		return 0;
	return nox_script_strings[i];
}

const char* nox_script_getField36(int i) {
	return nox_script_arr_xxx_1599636[i].field_36;
}

unsigned int nox_script_getField40(int i) {
	return nox_script_arr_xxx_1599636[i].field_40;
}

unsigned int nox_script_getField44(int i) {
	return nox_script_arr_xxx_1599636[i].field_44;
}

//----- (004F5580) --------------------------------------------------------
int  nox_xxx_xferReadScriptHandler_4F5580(int a1, char* a2) {
	bool v3;       // zf
	int v4;        // eax
	size_t v5;     // [esp+Ch] [ebp-408h]
	int v6;        // [esp+10h] [ebp-404h]
	char v7[1024]; // [esp+14h] [ebp-400h]

	v6 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 2u);
	if ((__int16)v6 > 1)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
		if (v5 >= 0x400)
			return 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(v7, v5);
		v3 = v5 == 0;
		v7[v5] = 0;
		if (!v3) {
			if (nox_common_gameFlags_check_40A5C0(6291456))
				strcpy(a2, v7);
			else
				*(unsigned int*)(a1 + 4) = nox_script_indexByEvent(v7);
		}
	} else {
		if (nox_common_gameFlags_check_40A5C0(6291456)) {
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
				nox_xxx_fileReadWrite_426AC0_file3_fread(nox_script_arr_xxx_1599636[*(unsigned int*)(a1 + 4)].field_0, v5);
				goto LABEL_16;
			}
		}
		v5 = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
	}
LABEL_16:
	nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)a1, 4u);
	return 1;
}
// 4F5580: using guessed type char var_400[1024];

//----- (00502490) --------------------------------------------------------
unsigned __int8*  nox_xxx_scriptCallByEventBlock_502490(int* a1, int a2, int a3) {
	*getMemU32Ptr(0x5D4594, 1599076) = 0;
	int v3 = a1[0];
	if (*a1 & 1)
		return 0;

	int v4 = a1[1];
	if (v4 == -1)
		return 0;

	if (v3 & 2) {
		LOBYTE(v3) = v3 | 1;
		a1[0] = v3;
	}
	if (nox_script_stack_top) {
		sub_5025A0((int)a1, a2, a3);
		return getMemAt(0x5D4594, 1599076);
	}
	nox_script_callByIndex_507310(v4, a2, a3);
	if (nox_script_arr_xxx_1599636[a1[1]].field_4) {
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
	if (*getMemU32Ptr(0x5D4594, 1599468) > 0)
		nox_xxx_scriptCallByEventBlock_502490(*(int**)getMemAt(0x5D4594, 1599084), *getMemIntPtr(0x5D4594, 1599088), *getMemIntPtr(0x5D4594, 1599092));
	return getMemAt(0x5D4594, 1599076);
}

//----- (00504F90) --------------------------------------------------------
int nox_server_mapRWScriptData_504F90() {
	int result; // eax
	char v1;    // [esp+3h] [ebp-5h]
	int v2;     // [esp+4h] [ebp-4h]

	v2 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v2, 2u);
	if ((__int16)v2 > 1)
		return 0;
	v1 = 0;
	if (nox_script_arr_xxx_1599636 && nox_common_gameFlags_check_40A5C0(1) && !nox_common_gameFlags_check_40A5C0(0x400000))
		v1 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v1, 1u);
	if (!v1)
		return 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(nox_script_arr_xxx_1599636[1].field_28, 4 * nox_script_arr_xxx_1599636[1].field_16);
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		result = sub_51AF80();
		if (!result)
			return result;
		return 1;
	}
	result = sub_51AEA0();
	if (result)
		return 1;
	return result;
}

//----- (00505800) --------------------------------------------------------
int nox_script_ncobj_readInt_505800(FILE* f) {
	int val;
	int n = fread(&val, 4, 1, f);
	return n == 1 ? val : 0;
}

//----- (00505830) --------------------------------------------------------
bool nox_script_ncobj_readString_505830(FILE* f, int sz, char* dst) {
	int n = fread(dst, 1, sz, f);
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
	if (!f)
		return 0;
	if (!nox_script_ncobj_readStringExpect_505870(f, "SCRIPT03")) {
		fclose(f);
		return 0;
	}
	if (!nox_script_ncobj_readStringExpect_505870(f, "STRG")) {
		fclose(f);
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
				fclose(f);
				return 0;
			}
		}
	}
	if (!nox_script_ncobj_readStringExpect_505870(f, "CODE")) {
		fclose(f);
		return 0;
	}
	nox_script_count_xxx_1599640 = nox_script_ncobj_readInt_505800(f);
	if (nox_script_count_xxx_1599640 < 0)
		nox_script_count_xxx_1599640 = 0;
	if (nox_script_count_xxx_1599640) {
		nox_script_arr_xxx_1599636 = calloc(1, sizeof(nox_script_xxx_t) * nox_script_count_xxx_1599640);
	}
	char buf[1024];
	for (int ind = 0; ind < nox_script_count_xxx_1599640; ind++) {
		if (!nox_script_ncobj_readStringExpect_505870(f, "FUNC")) {
			fclose(f);
			return 0;
		}
		nox_script_xxx_t* cur = &nox_script_arr_xxx_1599636[ind];

		int n = nox_script_ncobj_readInt_505800(f);
		cur->field_0 = calloc(1, n + 1);
		if (!nox_script_ncobj_readString_505830(f, n, cur->field_0)) {
			fclose(f);
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
		cur->field_4 = nox_script_ncobj_readInt_505800(f);
		cur->field_8 = nox_script_ncobj_readInt_505800(f);
		if (!nox_script_ncobj_readStringExpect_505870(f, "SYMB")) {
			fclose(f);
			return 0;
		}
		int cntY = nox_script_ncobj_readInt_505800(f);
		if (ind == 0)
			cntY++;
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
			fclose(f);
			return 0;
		}
		n = nox_script_ncobj_readInt_505800(f);
		cur->data = calloc(1, n);
		if (fread(cur->data, 1, n, f) != n) {
			fclose(f);
			return 0;
		}
	}
	if (!nox_script_ncobj_readStringExpect_505870(f, "DONE")) {
		fclose(f);
		return 0;
	}
	fclose(f);
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
		if (!nox_xxx_gameIsSwitchToSolo_4DB240())
			nox_script_callByIndex_507310(1, 0, 0);
	}
}

//----- (00507310) --------------------------------------------------------
void nox_script_callByIndex_507310(int index, int a2, int a3) {
	int v3;         // ebx
	int v6;         // esi
	int v7;         // ecx
	int v8;         // edx
	int v9;         // esi
	int v10;        // eax
	int v11;        // esi
	int v12;        // eax
	double v13;     // st7
	int v14;        // edi
	int v15;        // eax
	int v16;        // ecx
	int v17;        // esi
	int v18;        // eax
	int v19;        // eax
	int v20;        // esi
	int v21;        // eax
	double v22;     // st7
	int v23;        // esi
	int v24;        // eax
	int v25;        // eax
	int v26;        // esi
	int v27;        // eax
	int v28;        // esi
	int v29;        // eax
	int v30;        // esi
	int v31;        // eax
	int v32;        // esi
	int v33;        // eax
	int v34;        // esi
	int v35;        // eax
	int v36;        // esi
	int v37;        // eax
	int v38;        // esi
	int v39;        // eax
	char v40;       // si
	int v41;        // eax
	char v42;       // si
	int v43;        // eax
	int v44;        // esi
	int v45;        // esi
	int v46;        // edi
	int v47;        // esi
	float v48;      // edi
	int v49;        // esi
	int v50;        // edi
	int v51;        // esi
	int v52;        // esi
	int v53;        // edx
	double v54;     // st7
	float* v55;     // eax
	int v56;        // eax
	double v57;     // st7
	float* v58;     // eax
	int v59;        // ecx
	float* v60;     // eax
	double v61;     // st7
	int v62;        // ebp
	int v63;        // edi
	int v64;        // ebx
	int v65;        // esi
	int v66;        // eax
	int v67;        // eax
	int v68;        // edi
	int v69;        // esi
	int v70;        // esi
	int v71;        // ecx
	float* v72;     // eax
	double v73;     // st7
	int v74;        // edi
	int v75;        // esi
	int v76;        // edx
	int v77;        // eax
	int v78;        // edi
	int v79;        // esi
	int v80;        // esi
	int v81;        // esi
	int v82;        // edi
	int v83;        // esi
	int v84;        // esi
	char v85;       // di
	int v86;        // esi
	char v87;       // di
	int v88;        // esi
	int v89;        // edi
	int v90;        // esi
	int v91;        // edi
	int v92;        // esi
	int v93;        // edi
	int v94;        // esi
	int v95;        // esi
	int v96;        // eax
	int v97;        // esi
	int v98;        // esi
	int v99;        // eax
	int v100;       // esi
	int v101;       // kr00_4
	int v102;       // esi
	int v103;       // eax
	int v104;       // esi
	int v105;       // kr04_4
	int v106;       // esi
	int v107;       // eax
	int v108;       // esi
	int v109;       // kr08_4
	int v110;       // esi
	int v111;       // eax
	int v112;       // esi
	int v113;       // kr0C_4
	int v114;       // esi
	int v115;       // eax
	int v116;       // esi
	int v117;       // esi
	int v118;       // esi
	int v119;       // edi
	int v120;       // esi
	int v121;       // ebx
	int v122;       // eax
	int v123;       // esi
	int v124;       // esi
	int v126;       // eax
	int v127;       // edi
	int v128;       // esi
	int v129;       // ebx
	int v130;       // eax
	int v131;       // esi
	int v132;       // edi
	int v133;       // ebx
	int v134;       // eax
	int v135;       // eax
	int v136;       // eax
	int v137;       // eax
	int v138;       // eax
	int v139;       // eax
	int v140;       // [esp+10h] [ebp-118h]
	float v141;     // [esp+10h] [ebp-118h]
	float v142;     // [esp+10h] [ebp-118h]
	int v143;       // [esp+10h] [ebp-118h]
	float v144;     // [esp+10h] [ebp-118h]
	int v145;       // [esp+10h] [ebp-118h]
	float v146;     // [esp+10h] [ebp-118h]
	float v147;     // [esp+10h] [ebp-118h]
	float v148;     // [esp+10h] [ebp-118h]
	float v149;     // [esp+10h] [ebp-118h]
	float v150;     // [esp+10h] [ebp-118h]
	float v151;     // [esp+10h] [ebp-118h]
	float v152;     // [esp+10h] [ebp-118h]
	float v153;     // [esp+10h] [ebp-118h]
	float v154;     // [esp+10h] [ebp-118h]
	float v155;     // [esp+10h] [ebp-118h]
	float v156;     // [esp+10h] [ebp-118h]
	float v157;     // [esp+10h] [ebp-118h]
	int v158;       // [esp+10h] [ebp-118h]
	float v159;     // [esp+10h] [ebp-118h]
	int v160;       // [esp+18h] [ebp-110h]
	int v161;       // [esp+1Ch] [ebp-10Ch]
	int v163;       // [esp+24h] [ebp-104h]
	char v164[256]; // [esp+28h] [ebp-100h]

	v3 = a3;
	dword_5d4594_3821964 = a2;
	dword_5d4594_3821968 = a3;
	v6 = 0;
	v7 = nox_script_arr_xxx_1599636[index].field_8;
	v161 = 0;
	if (v7 > 0) {
		do {
			*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * ++v6 - 4) = nox_script_pop();
		} while (v6 < nox_script_arr_xxx_1599636[index].field_8);
	}
	v8 = nox_script_arr_xxx_1599636[index].data;
	v163 = nox_script_stack_top;
	v160 = v8;
	while (1) {
		switch (nox_script_nextInt((int**)&v160)) {
		case 0:
		case 3:
			v9 = nox_script_nextInt((int**)&v160);
			v10 = nox_script_nextInt((int**)&v160);
			if (v9) {
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) +
									  4 * *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[1].field_24) + 4 * v10)));
			} else if (v10 < 0) {
				nox_script_push(
					*(unsigned int*)(*(unsigned int*)(v3 + 760) + 4 * *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[0].field_24) - 4 * v10)));
			} else {
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) +
									  4 * *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_24) + 4 * v10)));
			}
			continue;
		case 1:
			v11 = nox_script_nextInt((int**)&v160);
			v12 = nox_script_nextInt((int**)&v160);
			if (v11) {
				v13 = *(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) +
								4 * *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[1].field_24) + 4 * v12));
			} else if (v12 < 0) {
				v13 = *(float*)(*(unsigned int*)(v3 + 760) + 4 * *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[0].field_24) - 4 * v12));
			} else {
				v13 = *(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) +
								4 * *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_24) + 4 * v12));
			}
			*(float*)&v140 = v13;
			nox_script_push(v140);
			continue;
		case 2:
			v14 = nox_script_nextInt((int**)&v160);
			v15 = nox_script_nextInt((int**)&v160);
			if (v14) {
				v16 = *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[1].field_20) + 4 * v15);
				v17 = *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[1].field_24) + 4 * v15);
			} else if (v15 < 0) {
				v18 = 4 * v15;
				v16 = *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[0].field_20) - v18);
				v17 = -*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[0].field_24) - v18);
			} else {
				v16 = *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_20) + 4 * v15);
				v17 = *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_24) + 4 * v15);
			}
			if (v16 > 1)
				nox_script_push(v16);
			nox_script_push(v14);
			nox_script_push(v17);
			continue;
		case 4:
		case 6:
			v19 = nox_script_nextInt((int**)&v160);
			nox_script_push(v19);
			continue;
		case 5:
			v141 = nox_script_nextFloat((float**)&v160);
			nox_script_push(SLODWORD(v141));
			continue;
		case 7:
			v20 = nox_script_pop();
			v21 = nox_script_pop();
			nox_script_push(v21 + v20);
			continue;
		case 8:
			v142 = COERCE_FLOAT(nox_script_pop());
			v22 = COERCE_FLOAT(nox_script_pop()) + v142;
			*(float*)&v143 = v22;
			nox_script_push(v143);
			continue;
		case 9:
			v26 = nox_script_pop();
			v27 = nox_script_pop();
			nox_script_push(v27 - v26);
			continue;
		case 10:
			v144 = COERCE_FLOAT(nox_script_pop());
			*(float*)&v145 = COERCE_FLOAT(nox_script_pop()) - v144;
			nox_script_push(v145);
			continue;
		case 11:
			v28 = nox_script_pop();
			v29 = nox_script_pop();
			nox_script_push(v28 * v29);
			continue;
		case 12:
			v146 = COERCE_FLOAT(nox_script_pop());
			v22 = COERCE_FLOAT(nox_script_pop()) * v146;
			*(float*)&v143 = v22;
			nox_script_push(v143);
			continue;
		case 13:
			v30 = nox_script_pop();
			v31 = nox_script_pop();
			nox_script_push(v31 / v30);
			continue;
		case 14:
			v147 = COERCE_FLOAT(nox_script_pop());
			v13 = COERCE_FLOAT(nox_script_pop()) / v147;
			*(float*)&v140 = v13;
			nox_script_push(v140);
			continue;
		case 15:
			v32 = nox_script_pop();
			v33 = nox_script_pop();
			nox_script_push(v33 % v32);
			continue;
		case 16:
			v34 = nox_script_pop();
			v35 = nox_script_pop();
			nox_script_push(v35 & v34);
			continue;
		case 17:
			v36 = nox_script_pop();
			v37 = nox_script_pop();
			nox_script_push(v37 | v36);
			continue;
		case 18:
			v38 = nox_script_pop();
			v39 = nox_script_pop();
			nox_script_push(v39 ^ v38);
			continue;
		case 19:
			v160 = (unsigned int)(nox_script_arr_xxx_1599636[index].data) + 4 * nox_script_nextInt((int**)&v160);
			continue;
		case 20:
			v44 = nox_script_nextInt((int**)&v160);
			if (nox_script_pop())
				v160 = (unsigned int)(nox_script_arr_xxx_1599636[index].data) + 4 * v44;
			continue;
		case 21:
			v45 = nox_script_nextInt((int**)&v160);
			if (!nox_script_pop())
				v160 = (unsigned int)(nox_script_arr_xxx_1599636[index].data) + 4 * v45;
			continue;
		case 22:
		case 24:
			v46 = nox_script_pop();
			v47 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v47) = v46;
				nox_script_push(v46);
			} else {
				if (v47 < 0)
					*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v47) = v46;
				else
					*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v47) = v46;
				nox_script_push(v46);
			}
			continue;
		case 23:
			v48 = COERCE_FLOAT(nox_script_pop());
			v49 = nox_script_pop();
			if (nox_script_pop()) {
				*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v49) = v48;
				nox_script_push(SLODWORD(v48));
			} else {
				if (v49 < 0)
					*(float*)(*(unsigned int*)(v3 + 760) - 4 * v49) = v48;
				else
					*(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v49) = v48;
				nox_script_push(SLODWORD(v48));
			}
			continue;
		case 25:
			v74 = nox_script_pop();
			v75 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v75) *= v74;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v75));
			} else if (v75 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v75) *= v74;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v75));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v75) *= v74;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v75));
			}
			continue;
		case 26:
			v150 = COERCE_FLOAT(nox_script_pop());
			v52 = nox_script_pop();
			if (nox_script_pop()) {
				v76 = (char*)(nox_script_arr_xxx_1599636[1].field_28);
				v54 = v150 * *(float*)(v76 + 4 * v52);
				v55 = (float*)(v76 + 4 * v52);
				*v55 = v54;
				nox_script_push(COERCE_INT(*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v52)));
			} else if (v52 >= 0) {
				v77 = nox_script_arr_xxx_1599636[index].field_28;
				v57 = v150 * *(float*)(v77 + 4 * v52);
				v58 = (float*)(v77 + 4 * v52);
				*v58 = v57;
				nox_script_push(COERCE_INT(*(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v52)));
			} else {
				v59 = 4 * v52;
				v60 = (float *) (*(unsigned int *) (v3 + 760) - 4 * v52);
				v61 = v150 * *v60;
				*v55 = v54;
				nox_script_push(COERCE_INT(*(float*)((unsigned int)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v52)));
			}
			continue;
		case 27:
			v78 = nox_script_pop();
			v79 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v79) /= v78;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v79));
			} else if (v79 < 0) {
				v80 = 4 * v79;
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - v80) /= v78;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - v80));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v79) /= v78;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v79));
			}
			continue;
		case 28:
			v151 = COERCE_FLOAT(nox_script_pop());
			v81 = nox_script_pop();
			if (nox_script_pop()) {
				*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v81) =
					*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v81) / v151;
				v13 = *(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v81);
				*(float*)&v140 = v13;
				nox_script_push(v140);
			} else if (v81 >= 0) {
				*(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v81) =
					*(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v81) / v151;
				v13 = *(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v81);
				*(float*)&v140 = v13;
				nox_script_push(v140);
			} else {
				v71 = 4 * v81;
				v72 = (float*)(*(unsigned int*)(v3 + 760) - 4 * v81);
				v73 = *v72 / v151;
				*v72 = v73;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - v71));
			}
			continue;
		case 29:
			v50 = nox_script_pop();
			v51 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v51) += v50;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v51));
			} else if (v51 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v51) += v50;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v51));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v51) += v50;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v51));
			}
			continue;
		case 30:
			v148 = COERCE_FLOAT(nox_script_pop());
			v52 = nox_script_pop();
			if (nox_script_pop()) {
				v53 = (char*)(nox_script_arr_xxx_1599636[1].field_28);
				v54 = v148 + *(float*)(v53 + 4 * v52);
				v55 = (float*)(v53 + 4 * v52);
				*v55 = v54;
				nox_script_push(COERCE_INT(*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v52)));
			} else if (v52 < 0) {
				v59 = 4 * v52;
				v60 = (float*)(*(unsigned int*)(v3 + 760) - 4 * v52);
				v61 = v148 + *v60;
				*v60 = v61;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - v59));
			} else {
				v56 = nox_script_arr_xxx_1599636[index].field_28;
				v57 = v148 + *(float*)(v56 + 4 * v52);
				v58 = (float*)(v56 + 4 * v52);
				*v58 = v57;
				nox_script_push(COERCE_INT(*(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v52)));
			}
			continue;
		case 31:
			v62 = nox_script_pop();
			v63 = nox_script_pop();
			v64 = nox_script_pop();
			if (v64) {
				v65 = 4 * v63;
				v66 = *(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v63);
			} else {
				v65 = 4 * v63;
				if (v63 < 0)
					v66 = *(unsigned int*)(*(unsigned int*)(a3 + 760) - 4 * v63);
				else
					v66 = *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v63);
			}
			nox_sprintf(v164, "%s%s", nox_script_strings[v66],
						nox_script_strings[v62]);
			v67 = nox_script_addString_512E40(v164);
			if (v64) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + v65) = v67;
			} else if (v63 < 0) {
				*(unsigned int *) (*(unsigned int *) (a3 + 760) - v65) = v67;
			} else {
				*(unsigned int *) (*(unsigned int *) (nox_script_arr_xxx_1599636[index].field_28) + v65) = v67;
			}
			nox_script_push(v67);
			v3 = a3;
			continue;
		case 32:
			v68 = nox_script_pop();
			v69 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v69) -= v68;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v69));
			} else if (v69 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v69) -= v68;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v69));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v69) -= v68;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v69));
			}
			continue;
		case 33:
			v149 = COERCE_FLOAT(nox_script_pop());
			v70 = nox_script_pop();
			if (nox_script_pop()) {
				*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v70) =
					*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v70) - v149;
				v13 = *(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v70);
				*(float*)&v140 = v13;
				nox_script_push(v140);
			} else if (v70 >= 0) {
				*(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v70) =
					*(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v70) - v149;
				v13 = *(float*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v70);
				*(float*)&v140 = v13;
				nox_script_push(v140);
			} else {
				v71 = 4 * v70;
				v72 = (float*)(*(unsigned int*)(v3 + 760) - 4 * v70);
				v73 = *v72 - v149;
				*v72 = v73;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - v71));
			}
			continue;
		case 34:
			v82 = nox_script_pop();
			v83 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v83) %= v82;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v83));
			} else if (v83 < 0) {
				v84 = 4 * v83;
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - v84) %= v82;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - v84));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v83) %= v82;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v83));
			}
			continue;
		case 35:
			v95 = nox_script_pop();
			v96 = nox_script_pop();
			nox_script_push(v96 == v95);
			continue;
		case 36:
			v152 = COERCE_FLOAT(nox_script_pop());
			if (COERCE_FLOAT(nox_script_pop()) != v152) {
				nox_script_push(0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 37:
			v97 = nox_script_pop();
			if (!strcmp(nox_script_strings[nox_script_pop()],
						nox_script_strings[v97]))
				nox_script_push(1);
			else
				nox_script_push(0);
			continue;
		case 38:
			v40 = nox_script_pop();
			v41 = nox_script_pop();
			nox_script_push(v41 << v40);
			continue;
		case 39:
			v42 = nox_script_pop();
			v43 = nox_script_pop();
			nox_script_push(v43 >> v42);
			continue;
		case 40:
			v98 = nox_script_pop();
			v99 = nox_script_pop();
			nox_script_push(v99 < v98);
			continue;
		case 41:
			v153 = COERCE_FLOAT(nox_script_pop());
			if (COERCE_FLOAT(nox_script_pop()) >= (double)v153) {
				nox_script_push(0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 42:
			v100 = nox_script_pop();
			v101 = strcmp(nox_script_strings[nox_script_pop()],
						  nox_script_strings[v100]);
			if (v101)
				nox_script_push(-(v101 < 0) - ((v101 < 0) - 1) < 0);
			else
				nox_script_push(0);
			continue;
		case 43:
			v102 = nox_script_pop();
			v103 = nox_script_pop();
			nox_script_push(v103 > v102);
			continue;
		case 44:
			v154 = COERCE_FLOAT(nox_script_pop());
			if (COERCE_FLOAT(nox_script_pop()) <= (double)v154) {
				nox_script_push(0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 45:
			v104 = nox_script_pop();
			v105 = strcmp(nox_script_strings[nox_script_pop()],
						  nox_script_strings[v104]);
			if (v105)
				nox_script_push(-(v105 < 0) - ((v105 < 0) - 1) > 0);
			else
				nox_script_push(0);
			continue;
		case 46:
			v106 = nox_script_pop();
			v107 = nox_script_pop();
			nox_script_push(v107 <= v106);
			continue;
		case 47:
			v155 = COERCE_FLOAT(nox_script_pop());
			if (COERCE_FLOAT(nox_script_pop()) > (double)v155) {
				nox_script_push(0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 48:
			v108 = nox_script_pop();
			v109 = strcmp(nox_script_strings[nox_script_pop()],
						  nox_script_strings[v108]);
			if (v109)
				nox_script_push(-(v109 < 0) - ((v109 < 0) - 1) <= 0);
			else
				nox_script_push(1);
			continue;
		case 49:
			v110 = nox_script_pop();
			v111 = nox_script_pop();
			nox_script_push(v111 >= v110);
			continue;
		case 50:
			v156 = COERCE_FLOAT(nox_script_pop());
			if (COERCE_FLOAT(nox_script_pop()) < (double)v156) {
				nox_script_push(0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 51:
			v112 = nox_script_pop();
			v113 = strcmp(nox_script_strings[nox_script_pop()],
						  nox_script_strings[v112]);
			if (v113)
				nox_script_push(-(v113 < 0) - ((v113 < 0) - 1) >= 0);
			else
				nox_script_push(1);
			continue;
		case 52:
			v114 = nox_script_pop();
			v115 = nox_script_pop();
			nox_script_push(v115 != v114);
			continue;
		case 53:
			v157 = COERCE_FLOAT(nox_script_pop());
			if (COERCE_FLOAT(nox_script_pop()) == v157) {
				nox_script_push(0);
			} else {
				nox_script_push(1);
			}
			continue;
		case 54:
			v116 = nox_script_pop();
			if (!strcmp(nox_script_strings[nox_script_pop()],
						nox_script_strings[v116]))
				nox_script_push(0);
			else
				nox_script_push(1);
			continue;
		case 55:
			v117 = nox_script_pop();
			if (nox_script_pop() && v117)
				nox_script_push(1);
			else
				nox_script_push(0);
			continue;
		case 56:
			v118 = nox_script_pop();
			if (nox_script_pop() || v118)
				nox_script_push(1);
			else
				nox_script_push(0);
			continue;
		case 57:
			v85 = nox_script_pop();
			v86 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v86) <<= v85;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v86));
			} else if (v86 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v86) <<= v85;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v86));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v86) <<= v85;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v86));
			}
			continue;
		case 58:
			v87 = nox_script_pop();
			v88 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v88) >>= v87;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v88));
			} else if (v88 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v88) >>= v87;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v88));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v88) >>= v87;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v88));
			}
			continue;
		case 59:
			v89 = nox_script_pop();
			v90 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v90) &= v89;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v90));
			} else if (v90 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v90) &= v89;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v90));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v90) &= v89;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v90));
			}
			continue;
		case 60:
			v93 = nox_script_pop();
			v94 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v94) |= v93;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v94));
			} else if (v94 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v94) |= v93;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v94));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v94) |= v93;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v94));
			}
			continue;
		case 61:
			v91 = nox_script_pop();
			v92 = nox_script_pop();
			if (nox_script_pop()) {
				*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v92) ^= v91;
				nox_script_push(*(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * v92));
			} else if (v92 < 0) {
				*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v92) ^= v91;
				nox_script_push(*(unsigned int*)(*(unsigned int*)(v3 + 760) - 4 * v92));
			} else {
				*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v92) ^= v91;
				nox_script_push(*(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * v92));
			}
			continue;
		case 62:
			v135 = nox_script_pop();
			nox_script_push(v135 == 0);
			continue;
		case 63:
			v136 = nox_script_pop();
			nox_script_push(~v136);
			continue;
		case 64:
			v137 = nox_script_pop();
			nox_script_push(-v137);
			continue;
		case 65:
			v159 = -COERCE_FLOAT(nox_script_pop());
			nox_script_push(SLODWORD(v159));
			continue;
		case 66:
			v119 = nox_script_pop();
			v120 = nox_script_pop();
			v121 = nox_script_pop();
			v122 = nox_script_pop();
			if (v119 < 0 || v119 >= v122)
				v161 = 1;
			if (v121) {
				v123 = *(unsigned int*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * (v119 + v120));
			} else if (v120 < 0) {
				v123 = *(unsigned int*)(*(unsigned int*)(a3 + 760) + 4 * (v120 - v119));
			} else {
				v123 = *(unsigned int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * (v119 + v120));
			}
			nox_script_push(v123);
			if (v161) {
				break;
			}
			v3 = a3;
			continue;
		case 67:
			v127 = nox_script_pop();
			v128 = nox_script_pop();
			v129 = nox_script_pop();
			v130 = nox_script_pop();
			if (v127 < 0 || v127 > v130)
				v161 = 1;
			if (v129) {
				nox_script_push(COERCE_INT(*(float*)((char*)(nox_script_arr_xxx_1599636[1].field_28) + 4 * (v127 + v128))));
			} else {
				if (v128 < 0)
					v158 = *(int*)(*(unsigned int*)(a3 + 760) + 4 * (v128 - v127));
				else
					v158 = *(int*)((unsigned int)(nox_script_arr_xxx_1599636[index].field_28) + 4 * (v127 + v128));
				nox_script_push(v158);
			}
			if (v161) {
				break;
			}
			v3 = a3;
			continue;
		case 68:
			v131 = nox_script_pop();
			v132 = nox_script_pop();
			v133 = nox_script_pop();
			v134 = nox_script_pop();
			if (v131 < 0 || v131 > v134)
				v161 = 1;
			nox_script_push(v133);
			if (v132 < 0)
				nox_script_push(v132 - v131);
			else
				nox_script_push(v132 + v131);
			if (v161) {
				break;
			}
			v3 = a3;
			continue;
		case 69:
			v138 = nox_script_nextInt((int**)&v160);
			if (nox_script_callBuiltin_508B70(index, v138) == 1) {
				break;
			}
			continue;
		case 70:
			v139 = nox_script_nextInt((int**)&v160);
			nox_script_callByIndex_507310(v139, a2, v3);
			continue;
		case 73:
			v23 = nox_script_pop();
			v24 = nox_script_pop();
			nox_sprintf(v164, "%s%s", nox_script_strings[v24],
						nox_script_strings[v23]);
			v25 = nox_script_addString_512E40(v164);
			nox_script_push(v25);
			continue;
		default:
			break;
		}
		v124 = v163;
		if (nox_script_stack_top != (int)(nox_script_arr_xxx_1599636[index].field_4) + v163) {
			if (nox_script_arr_xxx_1599636[index].field_4) {
				if (nox_script_stack_top) {
					v126 = nox_script_pop();
					nox_script_stack_top = v124;
					nox_script_push(v126);
				} else {
					nox_script_stack_top = v163;
					nox_script_push(0);
				}
			} else {
				nox_script_stack_top = v163;
			}
		}
		return;
	}
}

//----- (00508CB0) --------------------------------------------------------
int  sub_508CB0(unsigned int* a1, int a2) {
	int v2;     // edi
	int result; // eax
	int v4;     // ecx
	unsigned int* v5; // esi
	unsigned int* v6; // esi
	int v7;     // esi
	unsigned int* v8; // esi

	v2 = a1[189];
	if (!v2)
		return 0;
	if (a2 == 14) {
		if (nox_common_gameFlags_check_40A5C0(6291456))
			result = v2;
		else
			result = nox_script_arr_xxx_1599636[a1[192]].field_0;
		return result;
	}
	v4 = a1[2];
	if (v4 & 0x200) {
		v5 = (unsigned int*)a1[187];
		if (a2) {
			if (a2 != 1) {
				if (a2 == 2) {
					if (nox_common_gameFlags_check_40A5C0(6291456))
						result = v2 + 384;
					else
						result = nox_script_arr_xxx_1599636[v5[8]].field_0;
					return result;
				}
				return 0;
			}
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 256;
			else
				result = nox_script_arr_xxx_1599636[v5[6]].field_0;
		} else if (nox_common_gameFlags_check_40A5C0(6291456)) {
			result = v2 + 512;
		} else {
			result = nox_script_arr_xxx_1599636[v5[4]].field_0;
		}
	} else if (v4 & 2) {
		v6 = (unsigned int*)a1[187];
		switch (a2) {
		case 3:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 640;
			else
				result = nox_script_arr_xxx_1599636[v6[309]].field_0;
			break;
		case 4:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 768;
			else
				result = nox_script_arr_xxx_1599636[v6[307]].field_0;
			break;
		case 5:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 896;
			else
				result = nox_script_arr_xxx_1599636[v6[317]].field_0;
			break;
		case 6:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1024;
			else
				result = nox_script_arr_xxx_1599636[v6[311]].field_0;
			break;
		case 7:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1152;
			else
				result = nox_script_arr_xxx_1599636[v6[313]].field_0;
			break;
		case 8:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1280;
			else
				result = nox_script_arr_xxx_1599636[v6[315]].field_0;
			break;
		case 9:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1408;
			else
				result = nox_script_arr_xxx_1599636[v6[319]].field_0;
			break;
		case 10:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1536;
			else
				result = nox_script_arr_xxx_1599636[v6[321]].field_0;
			break;
		case 11:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1664;
			else
				result = nox_script_arr_xxx_1599636[v6[323]].field_0;
			break;
		case 13:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1792;
			else
				result = nox_script_arr_xxx_1599636[v6[325]].field_0;
			break;
		default:
			return 0;
		}
	} else if (v4 & 0x800) {
		v7 = a1[175];
		if (a2 != 12)
			return 0;
		if (nox_common_gameFlags_check_40A5C0(6291456))
			result = v2 + 128;
		else
			result = nox_script_arr_xxx_1599636[*(unsigned int*)(v7 + 4)].field_0;
	} else {
		if (!(v4 & 0x20000))
			return 0;
		v8 = (unsigned int*)a1[187];
		switch (a2) {
		case 15:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 1920;
			else
				result = nox_script_arr_xxx_1599636[v8[13]].field_0;
			break;
		case 16:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 2048;
			else
				result = nox_script_arr_xxx_1599636[v8[15]].field_0;
			break;
		case 17:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 2304;
			else
				result = nox_script_arr_xxx_1599636[v8[17]].field_0;
			break;
		case 18:
			if (nox_common_gameFlags_check_40A5C0(6291456))
				result = v2 + 2176;
			else
				result = nox_script_arr_xxx_1599636[v8[19]].field_0;
			break;
		default:
			return 0;
		}
	}
	return result;
}

//----- (0051ADF0) --------------------------------------------------------
void nox_xxx_scriptLeverReact_51ADF0() {
	_DWORD* v0; // esi
	int v1;     // edi
	int v2;     // ebx
	int v3;     // ebp

	v0 = *(_DWORD**)&dword_5d4594_2487236;
	if (dword_5d4594_2487236) {
		do {
			if (*v0 > *getMemIntPtr(0x5D4594, 2598000)) {
				v0 = (_DWORD*)v0[6];
			} else {
				v1 = v0[1];
				v2 = v0[5];
				v3 = v0[4];
				if (nox_script_arr_xxx_1599636[v1].field_8)
					nox_script_push(v0[2]);
				v0 = (_DWORD*)nox_xxx_scriptAct_51AD90((int)v0);
				nox_script_callByIndex_507310(v1, v2, v3);
			}
		} while (v0);
	}
}

//----- (00511B60) --------------------------------------------------------
int  nox_server_scriptValToObjectPtr_511B60(int a1) {
	int result; // eax
	int v2;     // edi
	int v3;     // esi

	if (a1 == -1) {
		result = dword_5d4594_3821964;
		if (dword_5d4594_3821964 && !(*(_BYTE*)(dword_5d4594_3821964 + 16) & 0x20))
			return result;
		return 0;
	}
	if (a1 != -2) {
		result = nox_xxx_script_511C50(a1);
		if (result)
			return result;
		v2 = nox_server_getFirstObject_4DA790();
		if (v2) {
			while (1) {
				if (!(*(_BYTE*)(v2 + 16) & 0x20) && *(_DWORD*)(v2 + 44) == a1) {
					nox_xxx_scriptPrepareFoundUnit_511D70(v2);
					return v2;
				}
				v3 = *(_DWORD*)(v2 + 504);
				if (v3)
					break;
				LABEL_17:
				v2 = nox_server_getNextObject_4DA7A0(v2);
				if (!v2)
					goto LABEL_18;
			}
			while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 44) != a1) {
				v3 = *(_DWORD*)(v3 + 496);
				if (!v3)
					goto LABEL_17;
			}
		} else {
			LABEL_18:
			v3 = nox_server_getFirstObjectUninited_4DA870();
			if (!v3)
				return 0;
			while (*(_BYTE*)(v3 + 16) & 0x20 || *(_DWORD*)(v3 + 44) != a1) {
				result = nox_server_getNextObjectUninited_4DA880(v3);
				v3 = result;
				if (!result)
					return result;
			}
		}
		nox_xxx_scriptPrepareFoundUnit_511D70(v3);
		return v3;
	}
	result = dword_5d4594_3821968;
	if (!dword_5d4594_3821968 || *(_BYTE*)(dword_5d4594_3821968 + 16) & 0x20)
		return 0;
	return result;
}

//----- (0051B0C0) --------------------------------------------------------
void sub_51B0C0() {
	int* v0; // esi

	v0 = *(int**)&dword_5d4594_2487236;
	if (dword_5d4594_2487236) {
		do {
			if (v0[4])
				v0[4] = nox_server_scriptValToObjectPtr_511B60(v0[4]);
			if (v0[5])
				v0[5] = nox_server_scriptValToObjectPtr_511B60(v0[5]);
			v0 = (int*)v0[6];
		} while (v0);
	}
}

void nox_script_callOnEvent(const char* event, int a1, int a2) {
	int n = strlen(event);
	for (int i = 0; i < nox_script_count_xxx_1599640; i++) {
		if (!strncmp(event, nox_script_arr_xxx_1599636[i].field_0, n))
			nox_script_callByIndex_507310(i, a1, a2);
	}
}
