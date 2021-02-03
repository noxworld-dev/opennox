#include "common__system__group.h"

#include "client__gui__guicon.h"
#include "proto.h"

//----- (0057C2D0) --------------------------------------------------------
int __cdecl nox_server_scriptGetGroupId_57C2D0(int** a1) {
	int** v1;    // eax
	char v2;     // cl
	wchar_t* v4; // eax

	v1 = a1;
	v2 = *(_BYTE*)a1; // Group type
	if (*(_BYTE*)a1) {
		while (v2 != 1 && v2 != 2) {
			if (v2 != 3 || !v1) {
				v4 = nox_strman_loadString_40F1D0("Undefined", 0, "C:\\NoxPost\\src\\Common\\System\\Group.c",
										   358);
				sub_450C30(6u, (int)v4);
				return 0;
			}
			v1 = (int**)nox_server_scriptGetGroup_57C0A0(*v1[21]);
			v2 = *(_BYTE*)v1;
			if (!*(_BYTE*)v1)
				return *(unsigned __int8*)v1;
		}
	}
	return *(unsigned __int8*)v1;
}
