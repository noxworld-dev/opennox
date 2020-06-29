#include "../proto.h"

//----- (00552020) --------------------------------------------------------
int __cdecl sub_552020(SOCKET s, char* buf, int len, int flags, struct sockaddr* from, int* fromlen) {
	int v6;     // esi
	_BYTE* v7;  // eax
	char v8;    // al
	int result; // eax

	v6 = mix_recvfrom(s, buf, len, flags, from, fromlen);
	if (v6 != -1) {
		v7 = sub_551E60((int)from);
		if (v7) {
			v8 = v7[148];
			if (v8)
				sub_56FDD0(v8, buf, v6);
		}
	}
	if (nox_common_gameFlags_check_40A5C0(1))
		result = v6;
	else
		result = sub_415FF0(1, 99, "C:\\NoxPost\\src\\comw32\\comlib.c", 450) < *(int*)&byte_5D4594[2495940] ? 0 : v6;
	return result;
}