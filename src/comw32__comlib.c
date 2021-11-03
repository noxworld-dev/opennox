#include "GAME1.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "MixPatch.h"
#include "common__random.h"
#include "common__crypt.h"
#include "defs.h"

//----- (00552020) --------------------------------------------------------
int nox_xxx_netRecv_552020(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr_in* from) {
	int n = mix_recvfrom(s, buf, len, from);
	if (n != -1) {
		nox_net_struct_t* ns = nox_xxx_netStructByAddr_551E60(from);
		if (ns) {
			if (ns->xor_key) {
				nox_xxx_cryptXor_56FDD0(ns->xor_key, buf, n);
			}
		}
	}
	if (nox_common_gameFlags_check_40A5C0(1))
		return n;

	int r = nox_common_randomIntMinMax_415FF0(1, 99, "C:\\NoxPost\\src\\comw32\\comlib.c", 450);
	if (r >= *getMemIntPtr(0x5D4594, 2495940))
		return n;
	return 0;
}
