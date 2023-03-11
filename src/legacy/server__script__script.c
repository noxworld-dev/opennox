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

//----- (004F5580) --------------------------------------------------------
char* nox_script_callbackName(int h);
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
				char* name = nox_script_callbackName(v4);
				if (name) {
					v5 = strlen(name);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(name, v5);
					goto LABEL_16;
				}
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
