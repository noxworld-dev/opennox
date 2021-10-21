#include <stdlib.h>
#include <string.h>

#include "common__crypt.h"
#include "common__binfile.h"
#include "common/fs/nox_fs.h"
#include "memmap.h"

FILE* nox_file_3 = 0;

int dword_973f18_3872 = 0;
int dword_5d4594_739996 = 0;
int dword_5d4594_740000 = 0;
int dword_5d4594_740004 = 0;
int dword_5d4594_740072 = 0;

//----- (0056FDD0) --------------------------------------------------------
#ifndef NOX_CGO
void nox_xxx_cryptXor_56FDD0(char key, unsigned char* p, int n) {
	if (!p) {
		return;
	}
	for (int i = 0; i < n; i++) {
		p[i] ^= key;
	}
}

//----- (0056FE00) --------------------------------------------------------
void nox_xxx_cryptXorDst_56FE00(char key, unsigned char* src, int n, unsigned char* dst) {
	if (!src || !n || !dst) {
		return;
	}
	for (int i = 0; i < n; i++) {
		dst[i] = key ^ src[i];
	}
}
#endif // NOX_CGO

//----- (00426A40) --------------------------------------------------------
int nox_xxx_cryptGet_426A40() { return dword_5d4594_740000; }
int nox_xxx_cryptGetXxx() { return dword_973f18_3872; }

//----- (00426A50) --------------------------------------------------------
void nox_xxx_cryptSetTypeMB_426A50(int a1) {
	dword_5d4594_740004 = a1;
}

//----- (00426910) --------------------------------------------------------
int nox_xxx_cryptOpen_426910(char* a1, int a2, int a3) {
	int v3;     // eax
	int result; // eax

	if (nox_file_3) {
		nox_xxx_cryptClose_4269F0();
	}
	nox_xxx_cryptSetTypeMB_426A50(0);
	dword_973f18_3872 = a2;
	dword_5d4594_740000 = a3 == -1;
	dword_5d4594_739996 = -1;
	if (a2 == 1) {
		v3 = 0;
	} else if (a2 == 2) {
		dword_973f18_3872 = 0;
		v3 = 2;
	} else {
		v3 = 1;
	}
	result = nox_binfile_open_408CC0(a1, v3);
	nox_file_3 = result;
	if (result) {
		result = nox_binfile_cryptSet_408D40(result, a3);
		if (result) {
			if (a2 == 2 && nox_binfile_fseek_409050(nox_file_3, 0, SEEK_END)) {
				result = 0;
			} else {
				dword_5d4594_740072 = 0;
				memset(getMemAt(0x5D4594, 740040), 0, 4*8);
				memset(getMemAt(0x5D4594, 740008), 0, 4*8);
				result = 1;
			}
		}
	}
	return result;
}

//----- (004268E0) --------------------------------------------------------
int nox_xxx_file_4268E0() { return nox_binfile_yyy_409110(nox_file_3); }

//----- (004269F0) --------------------------------------------------------
void nox_xxx_cryptClose_4269F0() {
	if (nox_file_3) {
		nox_binfile_close_408D90(nox_file_3);
		nox_xxx_cryptSetTypeMB_426A50(0);
		nox_file_3 = 0;
	}
}

//----- (00426A60) --------------------------------------------------------
FILE* nox_xxx_mapgenGetSomeFile_426A60() { return nox_file_3; }

//----- (00426AA0) --------------------------------------------------------
int sub_426AA0(int a1) { return nox_binfile_fseek_409050(nox_file_3, a1, SEEK_CUR); }

//----- (00426BD0) --------------------------------------------------------
int sub_426BD0(unsigned char* a1, int a2) {
	int result;        // eax
	unsigned int v3;   // ecx
	unsigned char* v4; // esi
	int i;             // edi
	int v6;            // edx

	result = nox_file_3;
	if (nox_file_3) {
		v3 = dword_5d4594_739996;
		v4 = a1;
		for (i = a2; i; dword_5d4594_739996 = v3) {
			v6 = *v4++;
			result = *getMemU32Ptr(0x581450, 7288 + 4 * (v6 ^ (unsigned char)v3));
			v3 = result ^ (v3 >> 8);
			--i;
		}
		dword_5d4594_739996 = ~v3;
	}
	return result;
}

//----- (00426AC0) --------------------------------------------------------
size_t nox_xxx_fileReadWrite_426AC0_file3_fread(unsigned char* a1, size_t a2) {
	unsigned char* v2;   // ebx
	size_t v3;     // esi
	size_t result; // eax
	size_t v5;     // esi

	if (dword_973f18_3872) {
		if (dword_5d4594_740004) {
			v5 = nox_fs_fread(nox_file_3, a1, a2) / a2;
			nox_xxx_cryptXor_56FDD0(126, a1, a2);
		} else {
			v5 = nox_binfile_fread_408E40(a1, a2, 1, nox_file_3);
		}
		if (v5) {
			sub_426BD0(a1, a2);
		}
		result = v5;
	} else {
		sub_426BD0(a1, a2);
		if (dword_5d4594_740004) {
			v2 = calloc(a2, 1u);
			if (v2) {
				memcpy(v2, a1, a2);
				nox_xxx_cryptXor_56FDD0(126, v2, a2);
				v3 = nox_fs_fwrite(nox_file_3, v2, a2) / a2;
				free(v2);
				result = v3;
			} else {
				result = 0;
			}
		} else {
			result = nox_binfile_zzz_409200(a1, a2, 1, nox_file_3);
		}
	}
	return result;
}

//----- (00426C20) --------------------------------------------------------
void nox_xxx_fileCryptReadCrcMB_426C20(unsigned char* a1, size_t a2) {
	if (dword_973f18_3872 == 1) {
		if (dword_5d4594_740004) {
			nox_fs_fread(nox_file_3, a1, a2);
			nox_xxx_cryptXor_56FDD0(126, a1, a2);
		} else if (nox_xxx_cryptGet_426A40()) {
			nox_binfile_fread_408E40(a1, a2, 1, nox_file_3);
		} else {
			nox_binfile_skip2nextboundary_408FE0(a1, a2, 1, nox_file_3);
		}
	}
}

//----- (00426C90) --------------------------------------------------------
void nox_xxx_crypt_426C90() {
	void* v2; // eax
	int v3;   // eax
	int v4;   // ecx
	void* v5; // [esp+0h] [ebp-4h]

	if (!dword_973f18_3872) {
		if (dword_5d4594_740004) {
			v2 = (void*)nox_fs_ftell(nox_file_3);
			*getMemU32Ptr(0x5D4594, 740008 + 4*dword_5d4594_740072) = v2;
			v5 = v2;
			nox_xxx_cryptXor_56FDD0(126, &v5, 4);
			nox_fs_fwrite(nox_file_3, &v5, 4);
			++dword_5d4594_740072;
		} else {
			*getMemU32Ptr(0x5D4594, 740040 + 4 * dword_5d4594_740072) = nox_binfile_yyy_409110(nox_file_3);
			v3 = nox_binfile_ftell_426A50();
			v4 = dword_5d4594_740072;
			*getMemU32Ptr(0x5D4594, 740008 + 4*dword_5d4594_740072) = v3;
			dword_5d4594_740072 = v4 + 1;
		}
	}
}

//----- (004268F0) --------------------------------------------------------
void sub_4268F0(int a1) { nox_binfile_kkk_409190(nox_file_3, *(int*)&dword_5d4594_739996, a1); }

//----- (00426D40) --------------------------------------------------------
void nox_xxx_crypt_426D40() {
	int v1;   // edi
	int v2;   // eax
	void* v3; // esi
	int v5;   // eax
	void* v6; // [esp+0h] [ebp-4h]

	--dword_5d4594_740072;
	if (dword_973f18_3872) {
		return;
	}
	if (dword_5d4594_740004) {
		v1 = nox_fs_ftell(nox_file_3);
		v2 = *getMemU32Ptr(0x5D4594, 740008 + 4*dword_5d4594_740072);
		v3 = (void*)(v1 - v2 - 4);
		nox_fs_fseek_start(nox_file_3, v2);
		v6 = v3;
		nox_xxx_cryptXor_56FDD0(126, &v6, 4);
		nox_fs_fwrite(nox_file_3, &v6, 4);
		nox_fs_fseek_start(nox_file_3, v1);
	} else {
		v5 = nox_binfile_ftell_426A50();
		v3 = (void*)(v5 - *getMemU32Ptr(0x5D4594, 740008 + 4*dword_5d4594_740072));
		nox_binfile_kkk_409190(nox_file_3, v5 - *getMemU32Ptr(0x5D4594, 740008 + 4*dword_5d4594_740072),
							   *getMemU32Ptr(0x5D4594, 740040 + 4 * dword_5d4594_740072));
	}
}
