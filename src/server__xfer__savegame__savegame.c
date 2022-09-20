#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_2.h"
#include "client__gui__guicon.h"
#include "client__gui__window.h"
#include "common/fs/nox_fs.h"
#include "common__strman.h"
#include "operators.h"
#include "server__system__server.h"

#ifdef _WIN32
#include <io.h>
#else
#include "windows_compat.h"
#endif

bool nox_xxx_saveMakeFolder_0_4DB1D0();
bool nox_client_makeSaveMapDir_4DB5A0(char* a1, char* a2);
int nox_xxx_saveMakePlayerLocation_4DB600(void* a1);

//----- (004DB6A0) --------------------------------------------------------
void nox_xxx_monstersAllBelongToHost_4DB6A0() {
	char* v0; // eax
	char* v1; // edi
	int v2;   // ebx
	int v3;   // esi
	int v4;   // ebp
	int v5;   // eax

	v0 = nox_common_playerInfoFromNum_417090(31);
	v1 = v0;
	if (v0 && *((uint32_t*)v0 + 514)) {
		if (!*getMemU32Ptr(0x5D4594, 1563124)) {
			*getMemU32Ptr(0x5D4594, 1563124) = nox_xxx_getNameId_4E3AA0("SaveGameLocation");
		}
		v2 = nox_server_getFirstObject_4DA790();
		if (v2) {
			while (*(unsigned short*)(v2 + 4) != *getMemU32Ptr(0x5D4594, 1563124)) {
				v2 = nox_server_getNextObject_4DA7A0(v2);
				if (!v2) {
					return;
				}
			}
			v3 = *(uint32_t*)(v2 + 516);
			if (v3) {
				do {
					v4 = *(uint32_t*)(v3 + 512);
					nox_xxx_unitSetOwner_4EC290(*((uint32_t*)v1 + 514), v3);
					if (*(uint8_t*)(v3 + 8) & 2) {
						if (*(uint8_t*)(*(uint32_t*)(v3 + 748) + 1440) & 0x80) {
							v5 = *(uint32_t*)(v3 + 12);
							LOBYTE(v5) = v5 | 0x80;
							*(uint32_t*)(v3 + 12) = v5;
							nox_xxx_netReportAcquireCreature_4D91A0((unsigned char)v1[2064], v3);
							nox_xxx_netMarkMinimapObject_417190((unsigned char)v1[2064], v3, 1);
						}
					}
					v3 = v4;
				} while (v4);
			}
			*(uint32_t*)(v2 + 44) = 0;
			nox_xxx_delayedDeleteObject_4E5CC0(v2);
		}
	}
}
