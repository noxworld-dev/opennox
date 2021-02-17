#include "common__random.h"
#include "proto.h"

//----- (00552020) --------------------------------------------------------
int  sub_552020(SOCKET s, char* buf, int len, int flags, struct sockaddr_in* from, int* fromlen) {
	int v6;     // esi
	int result; // eax

	v6 = mix_recvfrom(s, buf, len, flags, from, fromlen);
	if (v6 != -1) {
		nox_net_struct_t* ns = nox_xxx_netStructByAddr_551E60(from);
		if (ns) {
			char v8 = ns->data_37[0];
			if (v8)
				nox_xxx_cryptXor_56FDD0(v8, buf, v6);
		}
	}
	if (nox_common_gameFlags_check_40A5C0(1))
		result = v6;
	else
		result = nox_common_randomIntMinMax_415FF0(1, 99, "C:\\NoxPost\\src\\comw32\\comlib.c", 450) < *getMemIntPtr(0x5D4594, 2495940) ? 0 : v6;
	return result;
}
