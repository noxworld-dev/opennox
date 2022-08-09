#include <float.h>
#include <math.h>
#include <time.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__system__parsecmd.h"
#include "common__binfile.h"
#include "common__random.h"
#include "common__strman.h"

#include "client__gui__guiinv.h"
#include "client__shell__mainmenu.h"
#include "common__system__group.h"
#include "common__system__team.h"
#include "comw32__comlib.h"

#include "MixPatch.h"
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__magic__speltree.h"
#include "nox_net.h"
#include "operators.h"

extern uint32_t dword_5d4594_2496988;
extern uint32_t dword_5d4594_2516352;
extern uint32_t dword_5d4594_2523888;
extern uint32_t dword_5d4594_2496472;
extern uint32_t dword_5d4594_2523904;
extern uint32_t dword_5d4594_2516380;
extern uint32_t dword_5d4594_2523804;
extern uint32_t dword_5d4594_2516372;
extern uint32_t dword_5d4594_2523764;
extern uint32_t dword_5d4594_2513932;
extern uint32_t dword_5d4594_2523760;
extern uint32_t nox_xxx_warriorMaxSpeed_587000_312796;
extern uint32_t nox_xxx_conjurerSpeed_587000_312812;
extern uint32_t nox_xxx_wizardSpeed_587000_312828;
extern uint32_t nox_xxx_wizardStrength_587000_312824;
extern uint32_t nox_xxx_warriorMaxStrength_587000_312792;
extern uint32_t dword_5d4594_2523776;
extern uint32_t nox_xxx_conjurerStrength_587000_312808;
extern void* nox_alloc_groupInfo_2523892;
extern uint32_t dword_5d4594_2516356;
extern void* nox_alloc_debugData_2523908;
extern void* nox_alloc_itemGroupElem_2523896;
extern uint32_t nox_xxx_warriorMaxMana_587000_312788;
extern uint32_t nox_xxx_warriorMaxHealth_587000_312784;
extern uint32_t nox_xxx_conjurerMaxHealth_587000_312800;
extern uint32_t nox_xxx_wizardMaxHealth_587000_312816;
extern uint32_t nox_xxx_conjurerMaxMana_587000_312804;
extern uint32_t dword_5d4594_3844304;
extern uint32_t nox_xxx_wizardMaximumMana_587000_312820;
extern uint64_t qword_581450_9544;
extern uint32_t dword_5d4594_2523780;
extern uint32_t dword_5d4594_2495920;
extern uint32_t dword_5d4594_2516344;
extern uint32_t nox_server_mapGroupsHead_2523900;
extern uint32_t dword_5d4594_2523756;
extern uint32_t nox_xxx_waypointsHead_2523752;
extern uint32_t dword_5d4594_2516328;
extern uint32_t dword_5d4594_2516348;
extern uint32_t dword_5d4594_2650652;
extern nox_alloc_class* nox_alloc_gQueue_3844300;
extern unsigned int nox_frame_xxx_2598000;

nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX] = {0};
nox_net_struct2_t nox_net_struct2_arr[NOX_NET_STRUCT_MAX] = {0};
void* dword_5d4594_2523912 = 0;
uint32_t dword_5d4594_3843632 = 0;

nox_net_struct_t* nox_xxx_makeNewNetStruct_553000(nox_net_struct_arg_t* arg);
void nox_xxx_netStructFree_5531C0(nox_net_struct_t* ns);

//----- (00553D60) --------------------------------------------------------
int nox_xxx_netHandlerDefXxx_553D60(unsigned int a1, char* a2, int a3, void* a4) { return 0; }
//----- (00553D70) --------------------------------------------------------
int nox_xxx_netHandlerDefYyy_553D70(unsigned int a1, char* a2, int a3, void* a4) { return 0; }

//----- (005528B0) --------------------------------------------------------
int nox_xxx_netSendReadPacket_5528B0(unsigned int a1, char a2) {
	unsigned int v2;  // ecx
	unsigned int v5;  // eax
	int v7;           // edi
	uint32_t v10;     // eax
	int v11;          // eax
	unsigned int v12; // eax
	char* v13;        // eax
	int v14;          // ebp
	unsigned int v15; // [esp+10h] [ebp-Ch]
	unsigned int v18; // [esp+20h] [ebp+4h]

	v2 = a1;
	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return -3;
	}
	if (ns->id == -1) {
		if (ns->field_19) {
			SetEvent(ns->field_34);
			return 0;
		}
		v5 = 0;
		v18 = NOX_NET_STRUCT_MAX;
	} else {
		v5 = a1;
		v18 = a1 + 1;
		v2 = ns->id;
	}
	v15 = v2;
	v7 = v18;
	for (int j = v5; j < v18; j++) {
		nox_net_struct_t* ns2 = nox_net_struct_arr[j];
		if (!ns2 || ns2->id != v15) {
			continue;
		}
		nox_xxx_netSend_5552D0(j, 0, 0);
		v10 = WaitForSingleObject(ns2->mutex_yyy, 0x3E8u);
		v7 = v10;
		if (v10 == -1 || v10 == 258) {
			return -16;
		}
		if (!(a2 & 1)) {
			v11 = ns2->func_xxx(j, ns2->data_2_xxx, (int)(ns2->data_2_end) - (int)(ns2->data_2_xxx), ns2->data_3);
			v7 = v11;
			if (v11 > 0) {
				v12 = v11 + (uint32_t)(ns2->data_2_xxx);
				if (v12 < ns2->data_2_end) {
					ns2->data_2_xxx = v12;
				}
			}
		}
		v13 = ns2->data_2_base;
		v14 = (uint32_t)(ns2->data_2_xxx) - (uint32_t)v13;
		if (v14 > 2) {
			v7 = nox_xxx_sendto_551F90(ns->sock, v13, v14, &ns2->addr);
			if (v7 == -1) {
				return -1;
			}
			sub_553F40(v14, 1);
			nox_xxx_netCountData_554030(v14, j);
			ns2->data_2_xxx = ns2->data_2_yyy;
		}
		if (!ReleaseMutex(ns2->mutex_yyy)) {
			ReleaseMutex(ns2->mutex_yyy);
		}
	}
	return v7;
}

//----- (00552A80) --------------------------------------------------------
int nox_xxx_servNetInitialPackets_552A80(unsigned int id, char flags) {
	struct nox_net_sockaddr_in to;
	char buf[256];

	if (id >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[id];
	if (!ns) {
		return -3;
	}
	nox_net_struct_t* ns2 = ns;
	unsigned int argp = 0;
	if (flags & 1) {
		if (nox_net_recv_available(ns->sock, &argp) == -1) {
			return -1;
		}
		if (!argp) {
			return -1;
		}
	} else {
		argp = 1;
	}
	char v26 = 1;
	while (1) {
		int n = nox_xxx_netRecv_552020(ns->sock, ns->data_1_xxx, (int)(ns->data_1_end) - (int)(ns->data_1_xxx), &to);
		if (n == -1) {
			return -1;
		}
		sub_553FC0(n, 1);
		if (n < 3) {
			ns->data_1_yyy = ns->data_1_base;
			ns->data_1_xxx = ns->data_1_base;
			if (!(flags & 1) || (flags & 4)) {
				return n;
			}
			argp = 0;
			if (nox_net_recv_available(ns->sock, &argp) == -1) {
				return -1;
			} else if (!argp) {
				return n;
			}
			continue;
		}
		unsigned char* v7 = ns->data_1_yyy;
		ns->data_1_xxx = &ns->data_1_xxx[n];
		unsigned int id2 = v7[0];
		unsigned char v9 = v7[1];
		unsigned char op = v7[2];
		if (debugNet) {
			printf("servNetInitialPackets: op=%d\n", op);
		}
		if (op == 12) {
			// received a lobby info request from the client
			if (!nox_xxx_check_flag_aaa_43AF70()) {
				// send server info packet
				n = nox_server_makeServerInfoPacket_554040(ns->data_1_yyy,
														   (int)(ns->data_1_xxx) - (int)(ns->data_1_yyy), buf);
				if (n > 0) {
					n = nox_net_sendto(ns->sock, buf, n, &to);
					sub_553F40(n, 1);
				}
			}
			ns->data_1_yyy = ns->data_1_base;
			ns->data_1_xxx = ns->data_1_base;
			if (!(flags & 1) || (flags & 4)) {
				return n;
			}
			argp = 0;
			if (nox_net_recv_available(ns->sock, &argp) == -1) {
				return -1;
			} else if (!argp) {
				return n;
			}
			continue;
		}
		if (op >= 14 && op <= 20) {
			v26 = 1;
		} else {
			if (id2 == 255) {
				if (v26 != 1) {
					goto LABEL_48;
				}
			} else {
				v26 = 0;
				if (!sub_551E00(id2 & 127, (int)&to)) {
					goto LABEL_48;
				}
				v26 = 1;
			}
			if (ns->id == -1) {
				ns2 = nox_net_struct_arr[id2 & 127];
			}
			if ((id2 & NOX_NET_STRUCT_MAX) == 0) {
				if (!ns2) {
					goto LABEL_48;
				}
				if (v9 != ns2->field_28_1) {
					sub_5551F0(id2, v9, 1);
					sub_555360(id2, v9, 1);
					ns2->field_28_1 = v9;
					bool v20 = 0;
					if (nox_xxx_netRead2Xxx_551EB0(id, id2, v9, ns->data_1_yyy,
												   (int)(ns->data_1_xxx) - (int)(ns->data_1_yyy)) == 1) {
						v20 = 0;
					} else {
						v20 = 1;
					}
					buf[0] = 38;
					buf[1] = ns2->field_28_1;
					ns->func_yyy(id2, buf, 2, ns2->data_3);
					if (!v20) {
						goto LABEL_48;
					}
				}
			} else if (id2 == 255) {
				if (op == 0) {
					memcpy(buf, &to, sizeof(to));
					n = nox_xxx_netBigSwitch_553210(id, ns->data_1_yyy, (int)(ns->data_1_xxx) - (int)(ns->data_1_yyy),
													(int)buf);
					if (n > 0) {
						n = nox_xxx_sendto_551F90(ns->sock, buf, n, &to);
						sub_553F40(n, 1);
					}
					goto LABEL_48;
				}
			} else {
				ns->data_1_yyy[0] &= 127;
				id2 = ns->data_1_yyy[0];
				if (!ns2) {
					goto LABEL_48;
				}
				if (ns2->data_2_base[1] != v9) {
					goto LABEL_48;
				}
				ns2->data_2_base[1]++;
				if (nox_xxx_netRead2Xxx_551EB0(id, id2, v9, ns->data_1_yyy,
											   (int)(ns->data_1_xxx) - (int)(ns->data_1_yyy)) == 1) {
					goto LABEL_48;
				}
			}
		}
		if (op < 32) {
			memcpy(buf, &to, sizeof(to));
			n = nox_xxx_netBigSwitch_553210(id, ns->data_1_yyy, (int)(ns->data_1_xxx) - (int)(ns->data_1_yyy),
											(int)buf);
			if (n > 0) {
				n = nox_xxx_sendto_551F90(ns->sock, buf, n, &to);
				sub_553F40(n, 1);
			}
		} else {
			if (ns2 && !(flags & 2)) {
				ns->func_yyy(id2, &ns->data_1_yyy[2], n - 2, ns2->data_3);
			}
		}
	LABEL_48:
		ns->data_1_yyy = ns->data_1_base;
		ns->data_1_xxx = ns->data_1_base;
		if (!(flags & 1) || (flags & 4)) {
			return n;
		}
		argp = 0;
		if (nox_net_recv_available(ns->sock, &argp) == -1) {
			return -1;
		} else if (!argp) {
			return n;
		}
	}
	// unreachable
}

//----- (00552E70) --------------------------------------------------------
int sub_552E70(unsigned int a1) {
	unsigned int v3; // esi
	unsigned int v4; // edi
	unsigned int v5; // ebp
	char v9[5];      // [esp+0h] [ebp-8h]

	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return -3;
	}
	if (ns->id == -1) {
		v3 = 0;
		v4 = NOX_NET_STRUCT_MAX;
		v5 = a1;
	} else {
		v5 = ns->id;
		v3 = a1;
		v4 = a1 + 1;
	}
	v9[0] = 6;
	for (; v3 < v4; v3++) {
		nox_net_struct_t* ns2 = nox_net_struct_arr[v3];
		if (ns2 && ns2->id == v5) {
			int v8 = dword_5d4594_2495920;
			ns2->field_22 = dword_5d4594_2495920;
			ns2->field_23 = dword_5d4594_2495920;
			*(uint32_t*)&v9[1] = v8;
			nox_xxx_netSendSock_552640(v3, v9, 5, NOX_NET_SEND_FLAG2);
		}
	}
	return 0;
}

//----- (00553210) --------------------------------------------------------
int nox_xxx_netBigSwitch_553210(unsigned int id, unsigned char* packet, int packetSz, int a4) {
	int out = a4;
	int pid = (char)packet[0];
	char p1 = packet[1];

	unsigned char* packetEnd = &packet[packetSz];

	unsigned char v74[8];
	*(uint32_t*)&v74[0] = *(uint32_t*)(a4 + 0);
	*(uint32_t*)&v74[4] = *(uint32_t*)(a4 + 4);
	int v75 = *(uint32_t*)(a4 + 8);
	int v76 = *(uint32_t*)(a4 + 12);

	if (packetSz <= 2) {
		return 0;
	}
	unsigned char* packetCur = &packet[2];

	if (id > NOX_NET_STRUCT_MAX) {
		printf("nox_net_struct_arr overflow (1): %d\n", (int)(id));
		abort();
	}
	nox_net_struct_t* ns1 = nox_net_struct_arr[id];
	unsigned int pidb = pid;
	while (2) {
		int op = packetCur[0];
		packetCur = &packetCur[1];
		if (debugNet) {
			printf("nox_xxx_netBigSwitch_553210: op=%d [%d]\n", op, packetSz);
		}
		switch (op) {
		case 0: {
			if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(8)) {
				return 0;
			}
			*(uint8_t*)(out + 0) = 0;
			*(uint8_t*)(out + 1) = p1;
			if (ns1->field_21 >= nox_xxx_servGetPlrLimit_409FA0() + (unsigned int)getMemByte(0x5D4594, 2500076) - 1) {
				*(uint8_t*)(out + 2) = 2;
				return 3;
			}
			if (pid != -1) {
				// pid in the request must be -1 (0xff); fail if it's not
				*(uint8_t*)(out + 2) = 2;
				return 3;
			}
			for (int i = 0; i < NOX_NET_STRUCT_MAX; i++) {
				nox_net_struct_t* ns9 = nox_net_struct_arr[i];
				if (!ns9) {
					pid = i;
					break;
				}
				if (*(uint16_t*)&v74[2] == ns9->addr.sin_port && *(uint32_t*)&v74[4] == ns9->addr.sin_addr) {
					printf("%d %d\n", *(uint16_t*)&v74[2], *(uint32_t*)&v74[4]);
					*(uint8_t*)(out + 2) = 4; // already joined?
					return 3;
				}
			}
			if (pid == -1) {
				*(uint8_t*)(out + 2) = 2;
				return 3;
			}
			nox_net_struct_arg_t narg;
			memset(&narg, 0, sizeof(nox_net_struct_arg_t));
			narg.data_3_size = 4;
			narg.data_size = (int)(ns1->data_2_end) - (int)(ns1->data_2_base);
			nox_net_struct_t* ns10 = nox_xxx_makeNewNetStruct_553000(&narg);
			nox_net_struct_arr[pid] = ns10;
			if (!ns10) {
				// cannot allocate - fail
				*(uint8_t*)(out + 2) = 2;
				return 3;
			}
			ns1->field_21++;
			ns10->data_2_base[0] = id;
			int v62 = ns10->data_2_base;
			char v63 = *(uint8_t*)(v62 + 1);
			if (v63 == p1) {
				*(uint8_t*)(v62 + 1) = v63 + 1;
			}
			ns10->id = id;
			ns10->sock = ns1->sock;
			ns10->func_xxx = ns1->func_xxx;
			ns10->func_yyy = ns1->func_yyy;
			memset(getMemAt(0x5D4594, 2508788 + 32 * id), 0, 32);
			*getMemU32Ptr(0x5D4594, 2508816 + 32 * id) = 1;
			char key = nox_common_randomInt_415FA0(1, 255);
			if (nox_net_no_xor) {
				key = 0;
			}
			ns10->xor_key = 0; // send this packet without xor encoding

			int v66 = &ns10->addr;
			*(uint64_t*)v66 = *(uint64_t*)v74;
			*(uint32_t*)(v66 + 8) = v75;
			*(uint32_t*)(v66 + 12) = v76;

			*(uint8_t*)(out + 0) = 31;
			*(uint8_t*)(out + 1) = p1;
			*(uint8_t*)(out + 2) = 1;
			*(uint32_t*)(out + 3) = pid;
			*(uint8_t*)(out + 7) = key;
			char v67 = nox_xxx_netSendSock_552640(pid, out, 8, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);

			ns10->xor_key = key;
			ns10->field_38 = 1;
			ns10->data_39[0] = v67;
			ns10->field_40 = nox_frame_xxx_2598000;
			return 0;
		}
		case 1: {
			int v11 = *(uint32_t*)packetCur;
			uint8_t* v12 = ns1->data_2_base;
			uint8_t* v13 = packetCur + 4;
			ns1->id = v11;
			*v12 = v11;
			packetCur = v13 + 1;
			ns1->xor_key = (uint8_t)*v13;
			dword_5d4594_3844304 = 1;
			if ((unsigned int)packetCur >= packetEnd) {
				return 0;
			}
			break;
		}
		case 2:
			ns1->id = -18;
			dword_5d4594_3844304 = 1;
			if ((unsigned int)packetCur >= packetEnd) {
				return 0;
			}
			break;
		case 3: // ack?
			ns1->id = -12;
			dword_5d4594_3844304 = 1;
			if ((unsigned int)packetCur >= packetEnd) {
				return 0;
			}
			break;
		case 4:
			ns1->id = -13;
			dword_5d4594_3844304 = 1;
			if ((unsigned int)packetCur >= packetEnd) {
				return 0;
			}
			break;
		case 5:
			*(uint8_t*)(out + 0) = ns1->xor_key;
			*(uint8_t*)(out + 2) = 7;
			*(uint32_t*)(out + 3) = *(uint32_t*)packetCur;
			return 7;
		case 6: {
			if (pidb > NOX_NET_STRUCT_MAX) {
				printf("nox_net_struct_arr overflow (2): %d\n", (int)(pidb));
				abort();
			}
			nox_net_struct_t* ns2 = nox_net_struct_arr[pidb];
			nox_net_struct_t* ns3 = nox_net_struct_arr[pid];
			uint8_t a2b3 = 37;
			ns1->func_yyy(pid, &a2b3, 1, ns3->data_3);
			int v18 = 0;
			if (ns1->id == -1) {
				*(uint8_t*)(out + 0) = ns2->id;
				v18 = ns2->data_2_base;
			} else {
				*(uint8_t*)(out + 0) = ns1->id;
				v18 = ns1->data_2_base;
			}
			*(uint8_t*)(out + 1) = *(uint8_t*)(v18 + 1);
			*getMemU32Ptr(0x5D4594, 2508792 + 32 * pid) = *(uint32_t*)packetCur;
			*(uint8_t*)(out + 2) = 8;
			*(uint32_t*)(out + 3) = *(uint32_t*)packetCur;
			return 7;
		}
		case 7: {
			if (pidb > NOX_NET_STRUCT_MAX) {
				printf("nox_net_struct_arr overflow (2): %d\n", (int)(pidb));
				abort();
			}
			nox_net_struct_t* ns4 = nox_net_struct_arr[pidb];
			if (!ns4->field_25) {
				return 0;
			}
			int v31 = dword_5d4594_2495920 - (int)(ns4->field_26) - (int)(ns4->field_24);
			int v32 = -1;
			if (v31 >= 1) {
				v32 = 256000 / v31;
			}
			*(uint8_t*)(out + 0) = 35;
			*(uint32_t*)(out + 1) = v32;
			if (ns1->id == -1) {
				ns1->func_yyy(pid, out, 5, ns4->data_3);
			} else {
				ns1->func_yyy(pid, out, 5, ns1->data_3);
			}
			return 0;
		}
		case 8: {
			if (pidb > NOX_NET_STRUCT_MAX) {
				printf("nox_net_struct_arr overflow (2): %d\n", (int)(pidb));
				abort();
			}
			nox_net_struct_t* ns5 = nox_net_struct_arr[pidb];
			if (*(uint32_t*)packetCur != ns5->field_22) {
				return 0;
			}
			ns5->field_24 = dword_5d4594_2495920 - ns5->field_23;
			*(uint8_t*)(out + 0) = 36;
			*(uint32_t*)(out + 1) = ns5->field_24;
			int v19 = 0;
			if (ns1->id == -1) {
				v19 = ns5->data_3;
			} else {
				v19 = ns1->data_3;
			}
			ns1->func_yyy(pid, out, 5, v19);
			*(uint8_t*)(out + 0) = ns1->data_2_base[0];
			*(uint8_t*)(out + 1) = ns5->data_2_base[1];
			*(uint8_t*)(out + 2) = 9;
			*(uint32_t*)(out + 3) = dword_5d4594_2495920;
			return 7;
		}
		case 9: {
			int v21 = 32 * pid;
			int v22 = *(uint32_t*)packetCur - *getMemU32Ptr(0x5D4594, 2508792 + 32 * pid);
			if (v22 <= 0 || v22 >= 1000) {
				return 0;
			}
			int v23 = *getMemU32Ptr(0x5D4594, 2508788 + 32 * pid);
			int v24 = v23 + 8 * pid;
			int v25 = 5;
			*getMemU32Ptr(0x5D4594, 2508796 + 4 * v24) = v22;
			int v26 = (v23 + 1) % 5;
			int v27 = v26;
			if (!v26) {
				unsigned char* v28 = getMemAt(0x5D4594, 2508796 + v21);
				do {
					int v29 = *(uint32_t*)v28;
					v28 += 4;
					v26 += v29;
					--v25;
				} while (v25);
				*getMemU32Ptr(0x5D4594, 2508816 + v21) = v26 / 5;
			}
			*getMemU32Ptr(0x5D4594, 2508788 + v21) = v27;
			return 0;
		}
		case 10: {
			if (pid == 255) {
				return 0;
			}
			nox_net_struct_t* ns6 = nox_net_struct_arr[pid];
			if (ns6->field_38 == 1) {
				return 0;
			}
			uint8_t a2b2 = 34;
			ns1->func_yyy(pid, &a2b2, 1, ns6->data_3);
			memset(getMemAt(0x5D4594, 2508788 + 32 * id), 0, 0x20u);
			int* v69 = nox_xxx_findPlayerID_5541D0(pid);
			if (v69) {
				sub_425920((uint32_t**)v69);
				free(v69);
				--*getMemU8Ptr(0x5D4594, 2500076);
			}
			nox_xxx_netStructReadPackets_5545B0(pid);
			return 0;
		}
		case 11: {
			nox_net_struct_t* ns7 = nox_net_struct_arr[pid];
			uint8_t a2b = 33;
			ns1->func_yyy(pid, &a2b, 1, ns7->data_3);
			sub_554A50(id);
			return 0;
		}
		case 14: // join game request?
		{
			int v43 = 0;
			char* v78 = sub_416640();
			nox_xxx_cliGamedataGet_416590(0);
			bool a4a = 0;
			*(uint8_t*)(out + 0) = 0;
			*(uint8_t*)(out + 1) = p1;
			// TODO: This code is disabled because it causes issues with players reconnecting to the server.
			//       For some reason the player record gets stuck in the server's player list, so this check fails.

			//			if (!nox_xxx_check_flag_aaa_43AF70()) {
			//				char* v45 = nox_common_playerInfoGetFirst_416EA0();
			//				while (v45) {
			//					if (v45[2135] == packet[98]) {
			//						if (!strcmp(v45 + 2112, (const char*)packet + 56)) {
			//							*(uint8_t*)(out + 2) = 19;
			//							*(uint8_t*)(out + 3) = 12;
			//							return 4;
			//						}
			//						v43 = 0;
			//					}
			//					v45 = nox_common_playerInfoGetNext_416EE0((int)v45);
			//				}
			//			}
			if (*((uint32_t*)packet + 20) != NOX_CLIENT_VERS_CODE) {
				*(uint8_t*)(out + 2) = 19;
				*(uint8_t*)(out + 3) = 13;
				return 4;
			}
			if (ns1->field_21 >= (unsigned int)(nox_xxx_servGetPlrLimit_409FA0() - 1)) {
				a4a = 1;
			}
			if (sub_40A740()) {
				int v46 = nox_xxx_countObserverPlayers_425BF0();
				if (!*((uint32_t*)packet + 21)) {
					if (v46 >= (unsigned char)v78[53]) {
						*(uint8_t*)(out + 2) = 19;
						*(uint8_t*)(out + 3) = 11;
						return 4;
					}
				} else if (nox_server_teamByXxx_418AE0(*((uint32_t*)packet + 21))) {
					if (v46 > 0) {
						v43 = 1;
					}
				} else {
					if ((unsigned char)sub_417DE0() >= (unsigned char)v78[52]) {
						if (v46 >= (unsigned char)v78[53]) {
							*(uint8_t*)(out + 2) = 19;
							*(uint8_t*)(out + 3) = 11;
							return 4;
						}
					} else if (v46 > 0) {
						v43 = 1;
					}
				}
			}
			if (a4a) {
				if (!v43 || !*(uint32_t*)(v78 + 54)) {
					*(uint8_t*)(out + 2) = 19;
					*(uint8_t*)(out + 3) = 11;
					return 4;
				}
				for (char* i = nox_xxx_firstReplaceablePlayer_425C40(); i;
					 i = nox_xxx_nextReplaceablePlayer_425C70((int)i)) {
					if (!nox_xxx_findPlayerID_5541D0((unsigned char)i[2064] + 1)) {
						nox_xxx_playerCallDisconnect_4DEAB0((unsigned char)i[2064], 4);
						uint32_t* v50 = calloc(1, 0x10u);
						v50[3] = (unsigned char)i[2064] + 1;
						nox_common_list_append_4258E0((int)getMemAt(0x5D4594, 2495908), v50);
						++*getMemU8Ptr(0x5D4594, 2500076);
						*(uint8_t*)(out + 2) = 21;
						return 3;
					}
				}
			}
			if (v78[100] & 0x10) {
				int* v48 = sub_4168E0();
				if (!v48) {
					*(uint8_t*)(out + 2) = 19;
					*(uint8_t*)(out + 3) = 4;
					return 4;
				}
				while (_nox_wcsicmp((const wchar_t*)v48 + 6, (const wchar_t*)(packet + 4))) {
					v48 = sub_4168F0(v48);
					if (!v48) {
						*(uint8_t*)(out + 2) = 19;
						*(uint8_t*)(out + 3) = 4;
						return 4;
					}
				}
			} else {
				for (int* j = sub_416900(); j; j = sub_416910(j)) {
					if (!strcmp((const char*)j + 72, "0")) {
						if (!_nox_wcsicmp((const wchar_t*)j + 6, (const wchar_t*)packet + 2)) {
							*(uint8_t*)(out + 2) = 19;
							*(uint8_t*)(out + 3) = 5;
							return 4;
						}
					} else if (!_strcmpi((const char*)j + 72, (const char*)packet + 56)) {
						*(uint8_t*)(out + 2) = 19;
						*(uint8_t*)(out + 3) = 5;
						return 4;
					}
				}
			}
			char* v35 = v78;
			char v52 = v78[100];
			if (v52 && (unsigned char)(1 << packet[54]) & (unsigned char)v52) {
				*(uint8_t*)(out + 2) = 19;
				*(uint8_t*)(out + 3) = 7;
				return 4;
			}
			if (v52 & 0x20) {
				*(uint8_t*)(out + 2) = 15;
				return 3;
			}
			if (*(short*)(v78 + 105) == -1 && *(short*)(v35 + 107) == -1) {
				*(uint8_t*)(out + 2) = 20; // OK
				return 3;
			}
			int id53 = sub_553D10();
			if (id53 < 0) {
				*(uint8_t*)(out + 2) = 20; // OK
				return 3;
			}
			nox_net_struct2_t* nx = &nox_net_struct2_arr[id53];
			nx->field_0 = 1;
			nx->field_1_1 = 0;
			nx->field_1_0 = 0;
			*(uint64_t*)(&nx->addr) = *(uint64_t*)v74;
			*((uint32_t*)(&nx->addr) + 1) = v75;
			*((uint32_t*)(&nx->addr) + 2) = v76;
			return nox_xxx_makePacketTime_552340(id53, out);
		}
		case 17: {
			char* v33 = sub_416640();
			char* v35 = v33;
			*(uint8_t*)(out + 0) = 0;
			*(uint8_t*)(out + 1) = p1;
			if (nox_wcscmp((const wchar_t*)(packet + 4), (const wchar_t*)v33 + 39)) {
				*(uint8_t*)(out + 2) = 19;
				*(uint8_t*)(out + 3) = 6;
				return 4;
			}
			if (*(short*)(v35 + 105) == -1 && *(short*)(v35 + 107) == -1) {
				*(uint8_t*)(out + 2) = 20;
				return 3;
			}
			int id53 = sub_553D10();
			if (id53 < 0) {
				*(uint8_t*)(out + 2) = 20;
				return 3;
			}
			nox_net_struct2_t* nx1 = &nox_net_struct2_arr[id53];
			nx1->field_0 = 1;
			nx1->field_1_1 = 0;
			nx1->field_1_0 = 0;
			*(uint64_t*)(&nx1->addr) = *(uint64_t*)v74;
			*((uint32_t*)(&nx1->addr) + 1) = v75;
			*((uint32_t*)(&nx1->addr) + 2) = v76;
			return nox_xxx_makePacketTime_552340(id53, out);
		}
		case 18: {
			int v39 = nox_platform_get_ticks() - *((uint32_t*)packet + 1);
			int id40 = sub_553D30((int)v74);
			if (id40 < 0) {
				return 0;
			}
			nox_net_struct2_t* nx1 = &nox_net_struct2_arr[id40];
			if (*((unsigned char*)packet + 3) != nx1->field_1_1) {
				return 0;
			}
			nx1->field_6[nx1->field_1_1] = v39;
			nx1->field_1_1++;
			if (nx1->field_1_1 >= 10) {
				return 0;
			}
			return nox_xxx_makePacketTime_552340(id40, out);
		}
		case 31: {
			if (pidb > NOX_NET_STRUCT_MAX) {
				printf("nox_net_struct_arr overflow (2): %d\n", (int)(pidb));
				abort();
			}
			nox_net_struct_t* ns8 = nox_net_struct_arr[pidb];
			uint8_t v14 = packetCur[0];
			uint8_t v15 = ns8->field_28_1;
			packetCur = &packetCur[1];
			uint8_t a4b = v14;
			printf("foo 0x%x 0x%x\n", v14, v15);
			if (v14 != v15) {
				sub_5551F0(pid, a4b, 1);
				sub_555360(pid, a4b, 1);
				ns8->field_28_1 = a4b;
				*(uint8_t*)(out + 0) = 38;
				*(uint8_t*)(out + 1) = ns8->field_28_1;
				ns1->func_yyy(pid, out, 2, ns8->data_3);
			}
			if ((unsigned int)packetCur >= packetEnd) {
				return 0;
			}
			break;
		}
		default:
			return 0;
		}
	}
}

//----- (00553D10) --------------------------------------------------------
int sub_553D10() {
	for (int i = 0; i < NOX_NET_STRUCT_MAX; i++) {
		if (!nox_net_struct2_arr[i].field_0) {
			return i;
		}
	}
	return -1;
}

//----- (00553D30) --------------------------------------------------------
int sub_553D30(int a1) {
	for (int i = 0; i < NOX_NET_STRUCT_MAX; i++) {
		nox_net_struct2_t* nx = &nox_net_struct2_arr[i];
		if (nx->addr.sin_addr == *(uint32_t*)(a1 + 4) && nx->addr.sin_port == *(uint16_t*)(a1 + 2)) {
			return i;
		}
	}
	return -1;
}

//----- (00553F40) --------------------------------------------------------
void sub_553F40(int a1, int a2) {
	*getMemU32Ptr(0x5D4594, 2495952) += a1;
	*getMemU32Ptr(0x5D4594, 2495956) += a2;
	*getMemU32Ptr(0x5D4594, 2496992 + 4 * *getMemU32Ptr(0x5D4594, 2497504)) = a1;
	*getMemU32Ptr(0x5D4594, 2497508 + 4 * *getMemU32Ptr(0x5D4594, 2498020)) = a2;
	*getMemU32Ptr(0x5D4594, 2497504) = (dword_5d4594_2496472 + 1) % 128;
	*getMemU32Ptr(0x5D4594, 2498020) = (dword_5d4594_2496988 + 1) % 128;
}

//----- (00553FC0) --------------------------------------------------------
void sub_553FC0(int a1, int a2) {
	int v2; // edx
	int v3; // eax

	*getMemU32Ptr(0x5D4594, 2495944) += a1;
	*getMemU32Ptr(0x5D4594, 2495948) += a2;
	v2 = dword_5d4594_2496472;
	*getMemU32Ptr(0x5D4594, 2495960 + 4 * dword_5d4594_2496472) = a1;
	v3 = dword_5d4594_2496988;
	*getMemU32Ptr(0x5D4594, 2496476 + 4 * dword_5d4594_2496988) = a2;
	dword_5d4594_2496472 = (v2 + 1) % 128;
	dword_5d4594_2496988 = (v3 + 1) % 128;
}

//----- (00554030) --------------------------------------------------------
void nox_xxx_netCountData_554030(int a1, int a2) { *getMemU32Ptr(0x5D4594, 2498024 + 4 * a2) += a1; }

//----- (00554040) --------------------------------------------------------
unsigned int nox_server_makeServerInfoPacket_554040(const char* inBuf, int inSz, char* out) {
	char buf[72];

	char* v3 = sub_416640();
	char* game = nox_xxx_cliGamedataGet_416590(0);
	if (!sub_43AF30() || sub_4D6F30()) {
		return 0;
	}
	char playerLimit = nox_xxx_servGetPlrLimit_409FA0();
	char playerCount = nox_common_playerInfoCount_416F40();
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		--playerCount;
		--playerLimit;
	}
	char* srvName = nox_xxx_serverOptionsGetServername_40A4C0();
	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 13;
	buf[3] = playerCount;
	buf[4] = playerLimit;
	buf[5] = v3[101] & 0xF;
	buf[6] = ((unsigned char)v3[101]) >> 4;
	*(uint32_t*)&buf[7] = *((uint32_t*)game + 11);
	strcpy(&buf[10], nox_xxx_mapGetMapName_409B40());
	buf[19] = v3[102] | sub_43BE50_get_video_mode_id();
	buf[20] = v3[100];
	buf[21] = v3[100] & 0x10;
	*(uint32_t*)&buf[24] = *((uint32_t*)v3 + 12);
	unsigned int gameFlags = nox_common_gameFlags_getVal_40A5B0();
	if (nox_xxx_isQuest_4D6F50()) {
		gameFlags = (gameFlags & 0xFFFFFF7Fu) | 0x1000u;
		*(uint16_t*)&buf[68] = nox_game_getQuestStage_4E3CC0();
	}
	*(uint32_t*)&buf[28] = gameFlags;
	*(uint32_t*)&buf[32] = *((uint32_t*)game + 12);
	*(uint16_t*)&buf[36] = *(uint16_t*)(v3 + 105);
	*(uint16_t*)&buf[38] = *(uint16_t*)(v3 + 107);
	*(uint32_t*)&buf[40] = *((uint32_t*)v3 + 11);
	*(uint32_t*)&buf[44] = *(uint32_t*)(&inBuf[8]); // timestamp of the packet
	memcpy(&buf[48], game + 24, 20);
	memcpy(&out[0], buf, 72);
	strcpy(&out[72], srvName);
	return 72 + strlen(srvName) + 1;
}

//----- (005541D0) --------------------------------------------------------
int* nox_xxx_findPlayerID_5541D0(int a1) {
	int* result; // eax

	result = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 2495908));
	if (!result) {
		return 0;
	}
	while (result[3] != a1) {
		result = nox_common_list_getNextSafe_4258A0(result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00554200) --------------------------------------------------------
int nox_xxx_net_getIP_554200(unsigned int a1) {
	if (a1 > NOX_NET_STRUCT_MAX) {
		return 0;
	}
	if (!a1) {
		return dword_5d4594_3843632;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return 0;
	}
	return ns->addr.sin_addr;
}

//----- (00554230) --------------------------------------------------------
char* sub_554230() { return (char*)getMemAt(0x973F18, 44216); }

unsigned int sub_554290() {
	unsigned int v0;     // edi
	int v1;              // ebx
	char* v2;            // esi
	unsigned int v3;     // eax
	unsigned int result; // eax

	v0 = -1;
	v1 = 0;
	v2 = nox_common_playerInfoGetFirst_416EA0();
	if (!v2) {
		goto LABEL_13;
	}
	do {
		if (v2[2064] != 31 && sub_554240((unsigned char)v2[2064]) > 0) {
			v3 = sub_554240((unsigned char)v2[2064]);
			if (v3 < v0) {
				v0 = v3;
			}
			++v1;
		}
		v2 = nox_common_playerInfoGetNext_416EE0((int)v2);
	} while (v2);
	if (v1) {
		result = v0;
	} else {
	LABEL_13:
		result = 0;
	}
	return result;
}

int sub_554300() {
	int v0;     // ebx
	int v1;     // edi
	char* v2;   // esi
	int result; // eax

	v0 = 0;
	v1 = 0;
	v2 = nox_common_playerInfoGetFirst_416EA0();
	if (!v2) {
		goto LABEL_11;
	}
	do {
		if (v2[2064] != 31 && (int)sub_554240((unsigned char)v2[2064]) > 0) {
			v0 += sub_554240((unsigned char)v2[2064]);
			++v1;
		}
		v2 = nox_common_playerInfoGetNext_416EE0((int)v2);
	} while (v2);
	if (v1) {
		result = v0 / v1;
	} else {
	LABEL_11:
		result = 0;
	}
	return result;
}

//----- (00554240) --------------------------------------------------------
int sub_554240(int a1) {
	char* v1;   // eax
	int result; // eax

	if (a1 != 31) {
		return *getMemU32Ptr(0x5D4594, 2508848 + 32 * a1);
	}
	v1 = sub_416640();
	switch (*(uint32_t*)(v1 + 66)) {
	case 1:
		result = sub_554290();
		break;
	case 2:
		result = sub_554300();
		break;
	case 3:
		result = *(uint32_t*)(v1 + 70);
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (005549F0) --------------------------------------------------------
int sub_5549F0(unsigned int a1) {
	char v2; // [esp+7h] [ebp-1h]

	v2 = 10;
	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	if (nox_net_struct_arr[a1]) {
		nox_xxx_netSendReadPacket_5528B0(a1, 0);
		nox_xxx_netSendSock_552640(a1, &v2, 1, 0);
		nox_xxx_netSendReadPacket_5528B0(a1, 0);
		sub_554A50(a1);
	}
	return 0;
}

//----- (00554A50) --------------------------------------------------------
int sub_554A50(unsigned int a1) {
	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (ns) {
		nox_net_close(ns->sock);
		OnLibraryNotice_259(ns);
		nox_xxx_netStructFree_5531C0(nox_net_struct_arr[a1]);
		nox_net_struct_arr[a1] = 0;
		nox_net_stop();
	}
	return 0;
}

//----- (00555130) --------------------------------------------------------
int sub_555130(unsigned int a1, const void* a2, signed int a3) {
	uint32_t* v5; // eax

	if (a3 > *getMemIntPtr(0x5D4594, 2512884)) {
		return -1;
	}
	if (!a2) {
		return -1;
	}
	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return -3;
	}
	v5 = nox_alloc_class_new_obj_zero(nox_alloc_gQueue_3844300);
	if (!v5) {
		return -1;
	}
	*v5 = ns->field_29;
	ns->field_29 = v5;
	v5[3] = 1;
	*((uint8_t*)v5 + 20) = ns->data_2_base[0] | 0x80;
	*((uint8_t*)v5 + 21) = ns->field_28_0++;
	v5[4] = a3 + 2;
	memcpy((char*)v5 + 22, a2, a3);
	return *((unsigned char*)v5 + 21);
}

//----- (005551F0) --------------------------------------------------------
int sub_5551F0(unsigned int a1, char a2, int a3) {
	int* i; // eax

	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return -3;
	}
	for (i = ns->field_29; i; i = (int*)*i) {
		if (a3) {
			if (*((uint8_t*)i + 21) == a2) {
				i[3] = 1;
				continue;
			}
		} else if (i[1] <= (int)dword_5d4594_2495920) {
			i[3] = 1;
			continue;
		}
	}
	return 0;
}

//----- (00555250) --------------------------------------------------------
int sub_555250(unsigned int a1, uint32_t* a2) {
	int v3;     // eax
	int v4;     // ecx
	int result; // eax

	if (a1 >= NOX_NET_STRUCT_MAX) {
		return 0;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return 0;
	}
	v3 = ns->field_29;
	if (!v3) {
		return 0;
	}
	v4 = *(uint32_t*)(v3 + 16);
	result = v3 + 22;
	*a2 = v4;
	dword_5d4594_2513932 = *(uint32_t*)(result - 22);
	return result;
}

//----- (00555290) --------------------------------------------------------
int sub_555290(unsigned int a1, uint32_t* a2) {
	int result; // eax

	if (!dword_5d4594_2513932 || a1 >= NOX_NET_STRUCT_MAX || !nox_net_struct_arr[a1]) {
		return 0;
	}
	result = dword_5d4594_2513932 + 22;
	*a2 = *(uint32_t*)(dword_5d4594_2513932 + 16);
	dword_5d4594_2513932 = *(uint32_t*)(result - 22);
	return result;
}

//----- (005552D0) --------------------------------------------------------
int nox_xxx_netSend_5552D0(unsigned int a1, char a2, int a3) {
	int* i; // esi
	int v6; // eax

	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return -3;
	}
	for (i = ns->field_29; i; i = (int*)*i) {
		if (a3) {
			if (*((uint8_t*)i + 21) == a2) {
				goto LABEL_10;
			}
		} else if (i[3]) {
		LABEL_10:
			v6 = i[4];
			i[3] = 0;
			i[1] = dword_5d4594_2495920 + 2000;
			if (nox_xxx_sendto_551F90(ns->sock, (char*)i + 20, v6, &ns->addr) == -1) {
				return 0;
			}
			continue;
		}
	}
	return 0;
}

//----- (00555360) --------------------------------------------------------
int sub_555360(unsigned int a1, unsigned char a2, int a3) {
	char* v5;     // esi
	uint64_t* v6; // eax
	uint32_t* v7; // ecx
	char v8[24];  // [esp+4h] [ebp-18h]

	if (a1 >= NOX_NET_STRUCT_MAX) {
		return -3;
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		return -3;
	}
	*(uint32_t*)v8 = ns->field_29;
	v5 = v8;
	while (*(uint32_t*)v5) {
		if (a3) {
			if (a3 == 1) {
				if (a2 < 0x20u || a2 > 0xE0u) {
					if (*(uint8_t*)(*(uint32_t*)v5 + 21) < (char)a2) {
						goto LABEL_17;
					}
				} else if (*(uint8_t*)(*(uint32_t*)v5 + 21) < a2) {
					goto LABEL_17;
				}
			} else if (a3 == 2) {
			LABEL_17:
				v6 = *(uint64_t**)v5;
				v7 = ns->field_29;
				if (*(uint32_t**)v5 == v7) {
					ns->field_29 = *v7;
				}
				*(uint32_t*)v5 = **(uint32_t**)v5;
				*(uint32_t*)v6 = 0;
				nox_alloc_class_free_obj_first(nox_alloc_gQueue_3844300, v6);
				continue;
			}
		} else if (*(uint8_t*)(*(uint32_t*)v5 + 21) == a2) {
			goto LABEL_17;
		}
		v5 = *(char**)v5;
	}
	return 0;
}

//----- (0056F1C0) --------------------------------------------------------
int sub_56F1C0() {
	int v0;     // eax
	int result; // eax

	v0 = time(0);
	sub_56FF00(v0);
	dword_5d4594_2516352 = 0;
	dword_5d4594_2516348 = nox_frame_xxx_2598000;
	dword_5d4594_2516344 = 0;
	*getMemU16Ptr(0x587000, 311204) = 0;
	dword_5d4594_2516356 = 657757279;
	dword_5d4594_2516348 ^= nox_xxx_protect_56F240();
	dword_5d4594_2516328 = ~dword_5d4594_2516348;
	*getMemU32Ptr(0x5D4594, 2516340) = nox_xxx_protectionCreateInt_56F400(0);
	sub_56F250();
	result = nox_xxx_protectionCreateInt_56F400(1);
	*getMemU32Ptr(0x5D4594, 2516332) = result;
	return result;
}

//----- (0056F240) --------------------------------------------------------
int nox_xxx_protect_56F240() { return sub_56FF80(1, -1); }

//----- (0056F250) --------------------------------------------------------
int sub_56F250() {
	int v0;     // esi
	int result; // eax

	v0 = 7;
	do {
		result = nox_xxx_protectionCreateStructForInt_56F280(*(int*)&dword_5d4594_2516356, 0);
		--v0;
		++dword_5d4594_2516356;
	} while (v0);
	return result;
}

//----- (0056F280) --------------------------------------------------------
int nox_xxx_protectionCreateStructForInt_56F280(int a1, int a2) {
	uint32_t* v2; // eax
	int v3;       // ecx
	int v4;       // ecx

	v2 = calloc(1u, 0x10u);
	if (!v2) {
		return 0;
	}
	v2[3] = 0;
	v2[2] = 0;
	v3 = a1 ^ dword_5d4594_2516348;
	*v2 = a1 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v3;
	v2[1] = a2;
	v4 = a2 ^ dword_5d4594_2516348;
	v2[1] = a2 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v4;
	return sub_56F2F0(v2);
}

//----- (0056F2F0) --------------------------------------------------------
int sub_56F2F0(uint32_t* a1) {
	int v1;     // esi
	short v2;   // di
	int result; // eax
	short i;    // ax
	int v5;     // eax

	v1 = dword_5d4594_2516344;
	v2 = 0;
	if (*getMemU16Ptr(0x587000, 311204)) {
		for (i = nox_common_randomInt_415FA0(0, *getMemU16Ptr(0x587000, 311204) - 1); v1; ++v2) {
			if (v2 == i) {
				break;
			}
			v1 = *(uint32_t*)(v1 + 8);
		}
		a1[3] = *(uint32_t*)(v1 + 12);
		if (!dword_5d4594_2516348) {
			nullsub_31(1);
		}
		a1[2] = v1;
		*(uint32_t*)(v1 + 12) = a1;
		v5 = a1[3];
		if (v5) {
			*(uint32_t*)(v5 + 8) = a1;
			++*getMemU16Ptr(0x587000, 311204);
		} else {
			++*getMemU16Ptr(0x587000, 311204);
			dword_5d4594_2516344 = a1;
		}
		result = 1;
	} else {
		++*getMemU16Ptr(0x587000, 311204);
		dword_5d4594_2516352 = a1;
		dword_5d4594_2516344 = a1;
		result = 1;
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056F3B0) --------------------------------------------------------
uint32_t* sub_56F3B0() {
	uint32_t* result; // eax
	uint32_t* v1;     // esi

	result = *(uint32_t**)&dword_5d4594_2516344;
	if (dword_5d4594_2516344) {
		do {
			v1 = (uint32_t*)result[2];
			free(result);
			result = v1;
		} while (v1);
	}
	dword_5d4594_2516328 = 0;
	*getMemU16Ptr(0x587000, 311204) = 0;
	dword_5d4594_2516348 = 0;
	dword_5d4594_2516352 = 0;
	dword_5d4594_2516344 = 0;
	return result;
}

//----- (0056F400) --------------------------------------------------------
int nox_xxx_protectionCreateInt_56F400(int a1) {
	if (nox_xxx_protectionCreateStructForInt_56F280(dword_5d4594_2516356, a1)) {
		return (dword_5d4594_2516356)++;
	}
	nullsub_31(1);
	return 0;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056F480) --------------------------------------------------------
int nox_xxx_protectionCreateStructForFloat_56F480(int a1, float val) {
	int a2 = *(int*)&val;
	uint32_t* v2; // eax
	int v3;       // ecx
	int v4;       // ecx

	v2 = calloc(1u, 0x10u);
	if (!v2) {
		return 0;
	}
	v2[3] = 0;
	v2[2] = 0;
	v3 = a1 ^ dword_5d4594_2516348;
	*v2 = a1 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v3;
	v2[1] = a2;
	v4 = a2 ^ dword_5d4594_2516348;
	v2[1] = a2 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v4;
	return sub_56F2F0(v2);
}

//----- (0056F4F0) --------------------------------------------------------
int sub_56F4F0(int* a1) {
	int result; // eax

	result = sub_56F510(*a1);
	if (result) {
		*a1 = 0;
	}
	return result;
}

//----- (0056F510) --------------------------------------------------------
int sub_56F510(int a1) {
	uint32_t* v1; // eax
	int v2;       // ecx
	int v3;       // ecx
	int v4;       // ecx
	int v5;       // ecx

	v1 = sub_56F590(a1);
	if (!v1) {
		return 0;
	}
	v2 = v1[3];
	if (v2) {
		*(uint32_t*)(v2 + 8) = v1[2];
	} else {
		dword_5d4594_2516344 = v1[2];
	}
	v3 = v1[2];
	if (v3) {
		*(uint32_t*)(v3 + 12) = v1[3];
	} else {
		dword_5d4594_2516352 = v1[3];
	}
	v4 = *v1 ^ dword_5d4594_2516328;
	dword_5d4594_2516328 = v4;
	v5 = v1[1] ^ v4;
	--*getMemU16Ptr(0x587000, 311204);
	dword_5d4594_2516328 = v5;
	free(v1);
	return 1;
}

//----- (0056F590) --------------------------------------------------------
uint32_t* sub_56F590(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)&dword_5d4594_2516344;
	if (dword_5d4594_2516344) {
		while (*result != (a1 ^ dword_5d4594_2516348)) {
			result = (uint32_t*)result[2];
			if (!result) {
				goto LABEL_4;
			}
		}
	} else {
	LABEL_4:
		nullsub_31(1);
		result = 0;
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056F5C0) --------------------------------------------------------
int nox_xxx_protectData_56F5C0() {
	int v0;          // ebx
	int v1;          // edi
	int v2;          // ebx
	int v3;          // edi
	unsigned int v4; // eax
	int i;           // ebp
	int v6;          // esi
	int v7;          // eax
	int* v8;         // eax
	int* v9;         // eax
	int v10;         // ecx
	int v11;         // ebp
	bool v12;        // zf
	int result;      // eax
	int* v14;        // [esp-14h] [ebp-14h]

	if (!dword_5d4594_2516348) {
		nullsub_31(1);
	}
	v0 = nox_frame_xxx_2598000;
	v1 = dword_5d4594_2516348;
	v2 = nox_xxx_protect_56F240() ^ v0;
	v3 = v2 ^ v1;
	dword_5d4594_2516328 = ~v2;
	v4 = *getMemU16Ptr(0x587000, 311204);
	for (i = 0; i < (*getMemU16Ptr(0x587000, 311204) >> 2); v4 = *getMemU16Ptr(0x587000, 311204)) {
		v6 = nox_common_randomInt_415FA0(0, v4 >> 1);
		v7 = nox_common_randomInt_415FA0((*getMemU16Ptr(0x587000, 311204) >> 1) + 1,
										 *getMemU16Ptr(0x587000, 311204) - 1);
		if (v6 != v7) {
			v14 = sub_56F6F0(v7);
			v8 = sub_56F6F0(v6);
			sub_56F720(v8, v14);
		}
		++i;
	}
	v9 = *(int**)&dword_5d4594_2516344;
	dword_5d4594_2516348 = 0;
	if (dword_5d4594_2516344) {
		do {
			v10 = v3 ^ *v9;
			v11 = v3 ^ v9[1];
			*v9 = v10;
			v9[1] = v11;
			dword_5d4594_2516328 ^= v10;
			dword_5d4594_2516328 ^= v9[1];
			v9 = (int*)v9[2];
		} while (v9);
	}
	result = v2 ^ dword_5d4594_2516348;
	v12 = v2 == dword_5d4594_2516348;
	++*getMemU32Ptr(0x5D4594, 2516364);
	dword_5d4594_2516348 ^= v2;
	if (v12) {
		nullsub_31(1);
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056F6F0) --------------------------------------------------------
uint32_t* sub_56F6F0(int a1) {
	uint32_t* result; // eax
	int v2;           // ecx

	result = *(uint32_t**)&dword_5d4594_2516344;
	v2 = 0;
	if (dword_5d4594_2516344) {
		while (v2 != a1) {
			result = (uint32_t*)result[2];
			++v2;
			if (!result) {
				goto LABEL_4;
			}
		}
	} else {
	LABEL_4:
		nullsub_31(1);
		result = 0;
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056F720) --------------------------------------------------------
void sub_56F720(int* a1, int* a2) {
	int v2; // edx
	int v3; // esi

	if (!a1 || !a2) {
		nullsub_31(1);
		return;
	}
	v2 = *a1;
	v3 = a1[1];
	*a1 = *a2;
	a1[1] = a2[1];
	*a2 = v2;
	a2[1] = v3;
	++*getMemU32Ptr(0x5D4594, 2516360);
	if (!dword_5d4594_2516348) {
		nullsub_31(1);
	}
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056F780) --------------------------------------------------------
uint32_t* sub_56F780(int a1, int a2) {
	uint32_t* result; // eax
	int v3;           // ecx

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = a2 ^ dword_5d4594_2516348;
			result[1] = a2 ^ dword_5d4594_2516348;
			dword_5d4594_2516328 ^= v3;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056F7D0) --------------------------------------------------------
uint32_t* nox_xxx_playerResetProtectionCRC_56F7D0(int a1, int a2) {
	uint32_t* result; // eax
	int v3;           // ecx

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = a2 ^ dword_5d4594_2516348;
			result[1] = a2 ^ dword_5d4594_2516348;
			dword_5d4594_2516328 ^= v3;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056F820) --------------------------------------------------------
uint32_t* sub_56F820(int a1, unsigned char a2) {
	uint32_t* result; // eax
	int v3;           // ecx

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ a2;
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056F870) --------------------------------------------------------
uint32_t* nox_xxx_protectPlayerHPMana_56F870(int a1, unsigned short a2) {
	uint32_t* result; // eax
	int v3;           // ecx

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ a2;
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056F8C0) --------------------------------------------------------
uint32_t* sub_56F8C0(int a1, float a2) {
	uint32_t* result; // eax
	uint32_t* v3;     // esi
	int v4;           // eax

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		v3 = result;
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v4 = dword_5d4594_2516348 ^ (unsigned long long)(long long)a2;
			v3[1] = v4;
			dword_5d4594_2516328 ^= v4;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056F920) --------------------------------------------------------
uint32_t* sub_56F920(int a1, int a2) {
	uint32_t* result; // eax
	int v3;           // ecx

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ (a2 + (dword_5d4594_2516348 ^ result[1]));
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056F9E0) --------------------------------------------------------
uint32_t* nox_xxx_protectMana_56F9E0(int a1, short a2) {
	uint32_t* result; // eax
	int v3;           // ecx

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ (a2 + (dword_5d4594_2516348 ^ result[1]));
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056FA40) --------------------------------------------------------
uint32_t* sub_56FA40(int a1, float a2) {
	uint32_t* result; // eax
	uint32_t* v3;     // esi
	int v4;           // eax

	result = (uint32_t*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		v3 = result;
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v4 = dword_5d4594_2516348 ^
				 (unsigned long long)(long long)((double)(unsigned int)(dword_5d4594_2516348 ^ result[1]) + a2);
			v3[1] = v4;
			dword_5d4594_2516328 ^= v4;
			result = (uint32_t*)nox_xxx_protectData_56F5C0();
		}
	}
	return result;
}

//----- (0056FAC0) --------------------------------------------------------
int nox_xxx_protectionStringCRC_56FAC0(int* a1, unsigned int a2) {
	int* v2;        // ecx
	int result;     // eax
	unsigned int i; // edx
	int v5;         // esi

	v2 = a1;
	result = 0;
	for (i = a2 >> 2; i; --i) {
		v5 = *v2;
		++v2;
		result ^= v5;
	}
	return result;
}

//----- (0056FAE0) --------------------------------------------------------
int nox_xxx_protectionStringCRCLen_56FAE0(int* a1, unsigned int a2) {
	int result; // eax

	result = 0;
	if (a1) {
		result = nox_xxx_protectionStringCRC_56FAC0(a1, a2);
	}
	return result;
}

//----- (0056FB00) --------------------------------------------------------
int sub_56FB00(int* a1, unsigned int a2, int a3) {
	uint32_t* v3; // esi

	if (a3 >= 657757279) {
		v3 = sub_56F590(a3);
		if (v3 && (dword_5d4594_2516348 ^ nox_xxx_protectionStringCRCLen_56FAE0(a1, a2)) == v3[1]) {
			return 1;
		}
		nullsub_31(1);
	}
	return 0;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056FB60) --------------------------------------------------------
int sub_56FB60(nox_object_t* item) {
	int result; // eax
	int v2;     // ebx
	int v3;     // ebx
	int v4;     // ebx
	int* v5;    // edi
	int v6;     // eax
	int* v7;    // eax

	result = 0;
	if (item) {
		v2 = sub_4E4C00(item);
		v3 = (unsigned short)nox_xxx_unitGetHP_4EE780(item) ^ v2;
		v4 = sub_4E4C10(item) ^ v3;
		v5 = (int*)nox_object_getInitData_4E4C30(item);
		v6 = sub_4E4C50(item);
		if (v5 && v6 > 0) {
			v4 ^= nox_xxx_protectionStringCRC_56FAC0(v5, v6);
		}
		v7 = (int*)sub_4E4C80(item);
		if (v7) {
			if (strlen((const char*)v7)) {
				v4 ^= nox_xxx_protectionStringCRC_56FAC0(v7, strlen((const char*)v7));
			}
		}
		result = v4;
	}
	return result;
}

//----- (0056FBF0) --------------------------------------------------------
int nox_xxx_protect_56FBF0(int a1, nox_object_t* item) {
	int result;   // eax
	uint32_t* v3; // eax
	uint32_t* v4; // esi
	int v5;       // ecx

	result = a1;
	if (a1 >= 657757279) {
		v3 = sub_56F590(a1);
		v4 = v3;
		if (v3) {
			dword_5d4594_2516328 ^= v3[1];
			v5 = sub_56FB60(item) ^ v3[1];
			v4[1] = v5;
			result = v5 ^ dword_5d4594_2516328;
			dword_5d4594_2516328 ^= v5;
		} else {
			nullsub_31(1);
		}
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056FC50) --------------------------------------------------------
int nox_xxx_protect_56FC50(int a1, const nox_object_t* object) {
	int* a2 = object;
	int result;   // eax
	uint32_t* v3; // eax
	uint32_t* v4; // esi
	int v5;       // ecx

	result = a1;
	if (a1 >= 657757279) {
		v3 = sub_56F590(a1);
		v4 = v3;
		if (v3) {
			dword_5d4594_2516328 ^= v3[1];
			v5 = sub_56FB60(a2) ^ v3[1];
			v4[1] = v5;
			result = v5 ^ dword_5d4594_2516328;
			dword_5d4594_2516328 ^= v5;
		} else {
			nullsub_31(1);
		}
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056FCB0) --------------------------------------------------------
int sub_56FCB0(int a1, int a2) {
	int result; // eax

	result = 0;
	if (a2) {
		result = 1 << (a1 % 32);
	}
	return result;
}

//----- (0056FCE0) --------------------------------------------------------
int nox_xxx_playerAwardSpellProtectionCRC_56FCE0(int a1, int a2, int a3) {
	int result;   // eax
	uint32_t* v4; // eax
	uint32_t* v5; // esi

	result = a1;
	if (a1 >= 657757279) {
		v4 = sub_56F590(a1);
		v5 = v4;
		if (v4) {
			dword_5d4594_2516328 ^= v4[1];
			result = dword_5d4594_2516348 ^ (dword_5d4594_2516348 ^ v4[1] | sub_56FCB0(a2, a3));
			v5[1] = result;
			dword_5d4594_2516328 ^= result;
		} else {
			nullsub_31(1);
		}
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056FD50) --------------------------------------------------------
int nox_xxx_playerApplyProtectionCRC_56FD50(int a1, void* a2p, int a3) {
	int a2 = a2p;
	int v3;       // ebp
	uint32_t* v4; // eax
	int v5;       // esi
	int* v6;      // edi
	uint32_t* v8; // [esp+8h] [ebp+4h]

	v3 = 0;
	if (a1 >= 657757279) {
		v4 = sub_56F590(a1);
		v8 = v4;
		if (v4) {
			v5 = 1;
			if (a3 > 1) {
				v6 = (int*)(a2 + 4);
				do {
					v3 |= sub_56FCB0(v5++, *v6);
					++v6;
				} while (v5 < a3);
				v4 = v8;
			}
			if ((v3 ^ dword_5d4594_2516348) == v4[1]) {
				return 1;
			}
		}
		nullsub_31(1);
	}
	return 0;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (0056FE30) --------------------------------------------------------
double nox_xxx_unkDoubleSmth_56FE30() {
	double v0; // st7

	*getMemU64Ptr(0x5D4594, 2516412) = *getMemU64Ptr(0x5D4594, 2516404);
	*getMemU64Ptr(0x5D4594, 2516404) = *getMemU64Ptr(0x5D4594, 2516396);
	*getMemU32Ptr(0x5D4594, 2516396) = *getMemU32Ptr(0x5D4594, 2516388);
	*getMemU32Ptr(0x5D4594, 2516400) = *getMemU32Ptr(0x5D4594, 2516392);
	v0 = *getMemDoublePtr(0x5D4594, 2516388) * *getMemDoublePtr(0x581450, 11376) +
		 *getMemDoublePtr(0x5D4594, 2516404) * *getMemDoublePtr(0x581450, 11368) +
		 *getMemDoublePtr(0x5D4594, 2516412) * *getMemDoublePtr(0x581450, 11360) +
		 *getMemDoublePtr(0x5D4594, 2516412) * *getMemDoublePtr(0x581450, 11352) + *getMemDoublePtr(0x5D4594, 2516420);
	floor(v0);
	*getMemDoublePtr(0x5D4594, 2516388) = v0 - v0;
	*getMemDoublePtr(0x5D4594, 2516420) = v0 * *getMemDoublePtr(0x581450, 11344);
	return *getMemDoublePtr(0x5D4594, 2516388);
}

//----- (0056FF00) --------------------------------------------------------
void sub_56FF00(int a1) {
	int v1;            // eax
	unsigned char* v2; // ecx
	unsigned int v3;   // eax
	int v4;            // esi

	v1 = a1;
	if (!a1) {
		v1 = -1;
	}
	v2 = getMemAt(0x5D4594, 2516388);
	do {
		v2 += 8;
		v3 = (((v1 << 13) ^ (unsigned int)v1) >> 17) ^ (v1 << 13) ^ v1;
		v1 = (32 * v3) ^ v3;
		*((double*)v2 - 1) = (double)(unsigned int)v1 * *getMemDoublePtr(0x581450, 11344);
	} while ((int)v2 < (int)getMemAt(0x5D4594, 2516428));
	v4 = 19;
	do {
		nox_xxx_unkDoubleSmth_56FE30();
		--v4;
	} while (v4);
	dword_5d4594_2516380 = 0;
	*getMemU32Ptr(0x5D4594, 2516376) = 99;
	dword_5d4594_2516372 = 100;
}

//----- (0056FF80) --------------------------------------------------------
int sub_56FF80(int a1, int a2) {
	long long v2; // rax
	int result;   // eax

	*getMemU32Ptr(0x5D4594, 2516376) = a2;
	dword_5d4594_2516380 = a1;
	dword_5d4594_2516372 = a2 - a1 + 1;
	v2 = (long long)(nox_xxx_unkDoubleSmth_56FE30() * (double)*(unsigned int*)&dword_5d4594_2516372);
	if ((unsigned int)v2 < *(int*)&dword_5d4594_2516372) {
		result = dword_5d4594_2516380 + v2;
	} else {
		result = dword_5d4594_2516372 + dword_5d4594_2516380;
	}
	return result;
}

//----- (00578B00) --------------------------------------------------------
unsigned int nox_xxx_netGetUnitCodeCli_578B00(int a1) {
	unsigned int result; // eax

	if (!a1) {
		return 0;
	}
	result = *(uint32_t*)(a1 + 128);
	if (result >= 0x8000) {
		return 0;
	}
	if (*(uint32_t*)(a1 + 112) & 0x20400000) {
		BYTE1(result) |= 0x80u;
	}
	return result;
}

//----- (00578B30) --------------------------------------------------------
int nox_xxx_netClearHighBit_578B30(short a1) { return a1 & 0x7FFF; }

//----- (00578B40) --------------------------------------------------------
int nox_xxx_packetDynamicUnitCode_578B40(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if ((a1 & 0x8000) == 0x8000) {
		BYTE1(result) &= 0x7Fu;
		v2 = nox_xxx_netGetUnitByExtent_4ED020(result);
		if (v2) {
			result = *(uint32_t*)(v2 + 36);
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (00578B70) --------------------------------------------------------
unsigned int nox_xxx_netTestHighBit_578B70(unsigned int a1) { return (a1 >> 15) & 1; }

//----- (00578B80) --------------------------------------------------------
uint32_t* sub_578B80() {
	uint32_t* v0; // eax
	uint32_t* v2; // esi
	int v3;       // eax

	v0 = operator_new(0x18u);
	if (!v0) {
		return 0;
	}
	v2 = v0;
	*v0 = operator_new(0x10000u);
	v2[1] = 0;
	sub_57DF00(v2 + 2);
	v2[5] = operator_new(0x10000u);
	v3 = 0;
	do {
		v3 += 2;
		*(uint16_t*)(v3 + v2[5] - 2) = -1;
	} while (v3 < 0x10000);
	return v2;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (00578BA0) --------------------------------------------------------
unsigned int sub_578BA0(unsigned int a1) { return (a1 >> 1) + a1 + 32; }

//----- (00578BB0) --------------------------------------------------------
int sub_578BB0(void** a1, int a2, unsigned char* a3, int a4) { return sub_57D1C0(a1, a2, a3, a4); }

//----- (00578BD0) --------------------------------------------------------
void sub_578BD0(void* lpMem) {
	if (lpMem) {
		sub_57D150((void**)lpMem);
		operator_delete(lpMem);
	}
}

//----- (00578BF0) --------------------------------------------------------
uint32_t* sub_578BF0() {
	uint32_t* v0;     // eax
	uint32_t* result; // eax

	v0 = operator_new(0x98u);
	if (v0) {
		result = sub_57E9A0(v0);
	} else {
		result = 0;
	}
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (00578C10) --------------------------------------------------------
int nox_xxx_nxzDecompress_578C10(uint32_t* a1, uint8_t* a2, uint32_t* a3, unsigned int a4, uint32_t* a5) {
	return nox_xxx_nxzDecompressImpl_57EA80(a1, a2, a3, a4, a5);
}

//----- (00578C40) --------------------------------------------------------
void sub_578C40(void* lpMem) {
	if (lpMem) {
		sub_57EA00((void**)lpMem);
		operator_delete(lpMem);
	}
}

//----- (00579860) --------------------------------------------------------
void* nox_xxx_waypointGetList_579860() { return *(void**)&nox_xxx_waypointsHead_2523752; }

//----- (00579870) --------------------------------------------------------
int nox_xxx_waypointNext_579870(int a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 484);
	} else {
		result = 0;
	}
	return result;
}

//----- (00579890) --------------------------------------------------------
int sub_579890() { return dword_5d4594_2523756; }

//----- (005798A0) --------------------------------------------------------
int sub_5798A0(int a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 484);
	} else {
		result = 0;
	}
	return result;
}

//----- (005798C0) --------------------------------------------------------
unsigned int nox_xxx_waypoint_5798C0() {
	uint32_t* v0;        // ecx
	unsigned int result; // eax

	v0 = *(uint32_t**)&nox_xxx_waypointsHead_2523752;
	result = 1;
	if (nox_xxx_waypointsHead_2523752) {
		do {
			if (result <= *v0) {
				result = *v0 + 1;
			}
			v0 = (uint32_t*)v0[121];
		} while (v0);
	}
	return result;
}

//----- (005798F0) --------------------------------------------------------
uint32_t* nox_xxx_waypointNew_5798F0(float a1, float a2) {
	uint32_t* v2;    // esi
	unsigned int v3; // eax
	int v4;          // edx

	v2 = calloc(1u, 0x204u);
	v3 = nox_xxx_waypoint_5798C0();
	v4 = v2[120];
	*v2 = v3;
	*((float*)v2 + 2) = a1;
	*((float*)v2 + 3) = a2;
	v2[120] = v4 | 1;
	v2[121] = nox_xxx_waypointsHead_2523752;
	if (nox_xxx_waypointsHead_2523752) {
		*(uint32_t*)(nox_xxx_waypointsHead_2523752 + 488) = v2;
	}
	nox_xxx_waypointsHead_2523752 = v2;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_waypointMapRegister_5179B0((int)v2);
	}
	return v2;
}

//----- (00579970) --------------------------------------------------------
float* nox_xxx_waypointNewNotMap_579970(int a1, float a2, float a3) {
	float* result; // eax
	int v4;        // ecx

	result = (float*)calloc(1u, 0x204u);
	*(uint32_t*)result = a1;
	result[3] = a3;
	v4 = *((uint32_t*)result + 120) | 1;
	result[2] = a2;
	*((uint32_t*)result + 120) = v4;
	result[121] = *(float*)&dword_5d4594_2523756;
	dword_5d4594_2523756 = result;
	return result;
}

//----- (005799C0) --------------------------------------------------------
char* nox_xxx_waypoint_5799C0() {
	int v0; // esi
	int v1; // edi

	v0 = dword_5d4594_2523756;
	if (dword_5d4594_2523756) {
		do {
			v1 = *(uint32_t*)(v0 + 484);
			*(uint32_t*)(v0 + 484) = nox_xxx_waypointsHead_2523752;
			if (nox_xxx_waypointsHead_2523752) {
				*(uint32_t*)(nox_xxx_waypointsHead_2523752 + 488) = v0;
			}
			nox_xxx_waypointsHead_2523752 = v0;
			if (nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_waypointMapRegister_5179B0(v0);
			}
			v0 = v1;
		} while (v1);
	}
	dword_5d4594_2523756 = 0;
	return sub_579A30();
}

//----- (00579A30) --------------------------------------------------------
char* sub_579A30() {
	char* result; // eax
	char* i;      // esi
	int v2;       // eax
	char* v3;     // ecx
	char v4;      // dl
	char* j;      // eax
	int v6;       // edi
	uint8_t* v7;  // ecx

	result = (char*)nox_xxx_waypointGetList_579860();
	for (i = result; result; i = result) {
		i[477] = 0;
		v2 = 0;
		if (i[476]) {
			v3 = i + 96;
			do {
				v4 = *v3;
				v3 += 8;
				i[477] |= v4;
				++v2;
			} while (v2 < (unsigned char)i[476]);
		}
		for (j = (char*)nox_xxx_waypointGetList_579860(); j; j = (char*)nox_xxx_waypointNext_579870((int)j)) {
			v6 = 0;
			if (j[476]) {
				v7 = j + 96;
				do {
					if (*((char**)v7 - 1) == i) {
						i[477] |= *v7;
					}
					++v6;
					v7 += 8;
				} while (v6 < (unsigned char)j[476]);
			}
		}
		result = (char*)nox_xxx_waypointNext_579870((int)i);
	}
	return result;
}

//----- (00579AD0) --------------------------------------------------------
float* sub_579AD0(float a1, float a2) {
	int v2;    // ecx
	int v3;    // edx
	double v4; // st7
	double v5; // st6
	double v6; // st5
	float i;   // [esp+0h] [ebp-4h]

	v2 = nox_xxx_waypointsHead_2523752;
	v3 = 0;
	for (i = 100.0; v2; v2 = *(uint32_t*)(v2 + 484)) {
		v4 = *(float*)(v2 + 8) - a1;
		v5 = *(float*)(v2 + 12) - a2;
		v6 = v5 * v5 + v4 * v4;
		if (v6 < i) {
			i = v6;
			v3 = v2;
		}
	}
	return (float*)v3;
}

//----- (00579C40) --------------------------------------------------------
uint32_t* nox_server_getWaypointById_579C40(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)&nox_xxx_waypointsHead_2523752;
	if (!nox_xxx_waypointsHead_2523752) {
		return 0;
	}
	while (*result != a1) {
		result = (uint32_t*)result[121];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00579C60) --------------------------------------------------------
int sub_579C60(int a1) {
	int result; // eax

	result = dword_5d4594_2523756;
	if (!dword_5d4594_2523756) {
		return 0;
	}
	while (*(uint32_t*)(result + 4) != a1) {
		result = *(uint32_t*)(result + 484);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00579C80) --------------------------------------------------------
uint32_t* sub_579C80(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)&dword_5d4594_2523756;
	if (!dword_5d4594_2523756) {
		return 0;
	}
	while (*result != a1) {
		result = (uint32_t*)result[121];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00579CA0) --------------------------------------------------------
int sub_579CA0() {
	uint32_t* v0; // eax
	uint32_t* v1; // esi
	int v2;       // ebp
	int* v3;      // ebx
	int* v4;      // edi
	int v5;       // eax

	v0 = *(uint32_t**)&dword_5d4594_2523756;
	if (dword_5d4594_2523756) {
		do {
			v0[1] = *v0;
			v0 = (uint32_t*)v0[121];
		} while (v0);
		v0 = *(uint32_t**)&dword_5d4594_2523756;
	}
	v1 = v0;
	if (!v0) {
		return 1;
	}
	while (1) {
		v2 = 0;
		if (*((uint8_t*)v1 + 476)) {
			break;
		}
	LABEL_9:
		v1 = (uint32_t*)v1[121];
		if (!v1) {
			return 1;
		}
	}
	v3 = v1 + 23;
	v4 = v1 + 87;
	while (1) {
		v5 = sub_579C60(*v4);
		*v3 = v5;
		if (!v5) {
			return 0;
		}
		++v2;
		++v4;
		v3 += 2;
		if (v2 >= *((unsigned char*)v1 + 476)) {
			goto LABEL_9;
		}
	}
}

//----- (00579D20) --------------------------------------------------------
int sub_579D20() {
	unsigned int v0;  // eax
	unsigned int* v1; // ecx
	unsigned int v2;  // edx
	unsigned int* v3; // esi
	int v4;           // ebx
	int* v5;          // ebp
	int* v6;          // edi
	int v7;           // eax
	char v9;          // [esp+0h] [ebp-4h]

	v0 = nox_xxx_waypoint_5798C0();
	v1 = *(unsigned int**)&dword_5d4594_2523756;
	if (dword_5d4594_2523756) {
		do {
			v2 = *v1;
			*v1 = v0;
			v1[1] = v2;
			v1 = (unsigned int*)v1[121];
			++v0;
		} while (v1);
		v1 = *(unsigned int**)&dword_5d4594_2523756;
	}
	v3 = v1;
	if (!v1) {
		return 1;
	}
	do {
		v4 = 0;
		v9 = 0;
		if (*((uint8_t*)v3 + 476)) {
			v5 = (int*)(v3 + 23);
			v6 = (int*)(v3 + 87);
			do {
				v7 = sub_579C60(*v6);
				*v5 = v7;
				if (v7) {
					v5 += 2;
					++v9;
				}
				++v4;
				++v6;
			} while (v4 < *((unsigned char*)v3 + 476));
		}
		*((uint8_t*)v3 + 476) = v9;
		v3 = (unsigned int*)v3[121];
	} while (v3);
	return 1;
}

//----- (00579DD0) --------------------------------------------------------
void nox_xxx_waypointDeleteAll_579DD0() {
	uint32_t* v0; // esi
	uint32_t* v1; // edi

	v0 = *(uint32_t**)&nox_xxx_waypointsHead_2523752;
	if (nox_xxx_waypointsHead_2523752) {
		do {
			v1 = (uint32_t*)v0[121];
			if (nox_common_gameFlags_check_40A5C0(1)) {
				sub_517A70((int)v0);
			}
			free(v0);
			v0 = v1;
		} while (v1);
	}
	nox_xxx_waypointsHead_2523752 = 0;
	dword_5d4594_2523756 = 0;
	dword_5d4594_2523760 = 0;
}

//----- (00579E30) --------------------------------------------------------
const char* nox_xxx_waypointByName_579E30(const char* a1) {
	const char* i; // esi

	for (i = (const char*)nox_xxx_waypointGetList_579860(); i; i = (const char*)nox_xxx_waypointNext_579870((int)i)) {
		if (nox_server_strcmpWithoutMapname_4DA3F0(i + 16, a1)) {
			break;
		}
	}
	return i;
}

//----- (00579E70) --------------------------------------------------------
uint32_t* sub_579E70() {
	uint32_t* result; // eax

	result = calloc(1u, 0x204u);
	if (result) {
		result[120] |= 0x1000000u;
	}
	return result;
}

//----- (00579E90) --------------------------------------------------------
void sub_579E90(int a1) {
	*(uint32_t*)(a1 + 480) |= 0x1000000u;
	*(uint32_t*)(a1 + 484) = dword_5d4594_2523756;
	if (dword_5d4594_2523756) {
		*(uint32_t*)(dword_5d4594_2523756 + 488) = a1;
	}
	dword_5d4594_2523756 = a1;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_waypointMapRegister_5179B0(a1);
	}
}

//----- (00579EE0) --------------------------------------------------------
int sub_579EE0(int a1, unsigned char a2) { return (a2 & *(uint8_t*)(a1 + 477)) != 0; }

//----- (00579F00) --------------------------------------------------------
int nox_xxx_waypoint_579F00(uint32_t* a1, int a2) {
	int v2;     // ebp
	int v3;     // esi
	uint8_t* i; // esi
	int v5;     // edi
	void* v6;   // esi
	float* v7;  // edx
	float v8;   // eax
	float v9;   // ecx
	float v10;  // edx
	float4 v12; // [esp+10h] [ebp-10h]

	v2 = 0;
	if (nox_common_gameFlags_check_40A5C0(32)) {
		if (a2) {
			v3 = nox_server_getFirstObject_4DA790();
			if (v3) {
				while (!(*(uint32_t*)(v3 + 8) & 0x10000000) || nox_xxx_servCompareTeams_419150(a2 + 48, v3 + 48)) {
					v3 = nox_server_getNextObject_4DA7A0(v3);
					if (!v3) {
						goto LABEL_9;
					}
				}
				v2 = v3;
			}
		}
	}
LABEL_9:
	dword_5d4594_2523760 = 0;
	for (i = nox_xxx_waypointGetList_579860(); i; i = (uint8_t*)nox_xxx_waypointNext_579870((int)i)) {
		if (sub_579EE0((int)i, 0x80u) && i[480] & 1) {
			++dword_5d4594_2523760;
		}
	}
	if (!dword_5d4594_2523760) {
		return 0;
	}
	v5 = nox_common_randomInt_415FA0(0, dword_5d4594_2523760 - 1);
	v6 = nox_xxx_waypointGetList_579860();
	if (!v6) {
		return 0;
	}
	while (1) {
		if (!sub_579EE0((int)v6, 0x80u)) {
			goto LABEL_24;
		}
		if (!(*((uint8_t*)v6 + 480) & 1)) {
			goto LABEL_24;
		}
		if (nox_common_gameFlags_check_40A5C0(32)) {
			if (v2) {
				if (a2) {
					v7 = *(float**)(v2 + 748);
					v12.field_0 = *v7;
					v8 = *((float*)v6 + 3);
					v9 = v7[1];
					v10 = *((float*)v6 + 2);
					v12.field_4 = v9;
					v12.field_8 = v10;
					v12.field_C = v8;
					if (nox_xxx_mapTraceRay_535250(&v12, 0, 0, 9) == 1) {
						goto LABEL_24;
					}
				}
			}
		}
		if (!v5) {
			break;
		}
		--v5;
	LABEL_24:
		v6 = (void*)nox_xxx_waypointNext_579870((int)v6);
		if (!v6) {
			return 0;
		}
	}
	*a1 = *((uint32_t*)v6 + 2);
	a1[1] = *((uint32_t*)v6 + 3);
	return 1;
}

//----- (0057A160) --------------------------------------------------------
int nox_xxx_playerCanTalkMB_57A160(int a1) {
	int result; // eax

	if (a1 && nox_common_gameFlags_check_40A5C0(2)) {
		result = (*(uint32_t*)(a1 + 3680) >> 3) & 1;
	} else {
		result = 0;
	}
	return result;
}

//----- (0057A190) --------------------------------------------------------
int nox_xxx_giant_57A190(int a1) {
	int result; // eax

	if (a1) {
		result = (*(uint32_t*)(a1 + 3680) >> 2) & 1;
	} else {
		result = 0;
	}
	return result;
}

//----- (0057A1B0) --------------------------------------------------------
char* sub_57A1B0(short a1) {
	int v1;            // ecx
	unsigned char* v2; // eax

	v1 = 0;
	v2 = getMemAt(0x587000, 312212);
	while ((a1 & 0x17F0) != *(uint32_t*)v2) {
		v2 += 8;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 312268)) {
			return 0;
		}
	}
	return *(char**)getMemAt(0x587000, 312208 + 8 * v1);
}

//----- (0057A1E0) --------------------------------------------------------
char sub_57A1E0(int* a1, const char* a2, int* a3, char a4, short a5) {
	int* v5;           // esi
	int v6;            // ebx
	unsigned char v7;  // dl
	char* v8;          // edi
	int v9;            // ecx
	int v10;           // eax
	char* v11;         // edi
	unsigned char v12; // cl
	char result;       // al
	char v14[256];     // [esp+14h] [ebp-200h]
	char v15[256];     // [esp+114h] [ebp-100h]

	v5 = a3;
	v6 = a5 & 0x17F0;
	if (a3) {
		sub_57ADF0(a3);
	}
	a1[6] = -1;
	a1[7] = -1;
	a1[8] = -1;
	a1[9] = -1;
	a1[10] = -1;
	a1[11] = -1;
	a1[12] = -1;
	if (a4 & 3) {
		v15[0] = 0;
		strcpy(v14, "maps\\");
		strncat(v14, (const char*)a1, 8u);
		*(uint16_t*)&v14[strlen(v14)] = *getMemU16Ptr(0x587000, 312376);
		if (a4 & 2) {
			strcpy(v15, v14);
			if (a2) {
				strcat(v15, a2);
			} else {
				v7 = getMemByte(0x587000, 312388);
				v8 = &v15[strlen(v15) + 1];
				v9 = *getMemU32Ptr(0x587000, 312384);
				*(uint32_t*)--v8 = *getMemU32Ptr(0x587000, 312380);
				*((uint32_t*)v8 + 1) = v9;
				v8[8] = v7;
			}
			v10 = sub_57A3F0(v15, (int)a1, (int)a3, v6);
			v5 = a3;
		} else {
			v10 = 0;
		}
		if (a4 & 1 && !v10) {
			strncat(v14, (const char*)a1, 8u);
			v11 = &v14[strlen(v14) + 1];
			v12 = getMemByte(0x587000, 312396);
			*(uint32_t*)--v11 = *getMemU32Ptr(0x587000, 312392);
			v11[4] = v12;
			sub_57A3F0(v14, (int)a1, (int)v5, v6);
		}
	}
	if (dword_5d4594_2650652 && a4 & 4) {
		sub_57A3F0((char*)getMemAt(0x587000, 312400), (int)a1, (int)v5, v6);
	}
	result = a5;
	if (a5 & 0x40) {
		result = sub_453FA0((int)(a1 + 6), 132, 0);
	}
	return result;
}
// 57A1E0: using guessed type char var_100[256];

//----- (0057A3F0) --------------------------------------------------------
int sub_57A3F0(char* a1, int a2, int a3, int a4) {
	FILE* v4;        // eax
	FILE* v5;        // esi
	char* v6;        // eax
	char v8[256];    // [esp+4h] [ebp-300h]
	wchar_t v9[256]; // [esp+104h] [ebp-200h]

	dword_5d4594_2523764 = 6128;
	v4 = nox_fs_open_text(a1);
	v5 = v4;
	if (!v4) {
		return 0;
	}
	if (!nox_fs_feof(v4)) {
		do {
			memset(v8, 0, sizeof(v8));
			nox_fs_fgets(v5, v8, 256);
			v6 = strchr(v8, 10);
			if (v6) {
				*v6 = 0;
			}
			if (v8[0]) {
				nox_swprintf(v9, L"%S", v8);
				sub_57A4D0(v9, a2, a3, a4);
			}
		} while (!nox_fs_feof(v5));
	}
	nox_fs_close(v5);
	return 1;
}

//----- (0057A4D0) --------------------------------------------------------
void sub_57A4D0(wchar_t* a1, int a2, int a3, int a4) {
	unsigned char v4;      // bl
	int v5;                // edi
	const wchar_t* result; // eax
	const wchar_t* v7;     // esi
	int v8;                // ecx
	const wchar_t* v9;     // eax
	wchar_t* v10;          // esi
	unsigned char v11;     // [esp+10h] [ebp-284h]
	int v12[32];           // [esp+14h] [ebp-280h]
	wchar_t v13[256];      // [esp+94h] [ebp-200h]

	v4 = 0;
	v5 = 0;
	v11 = 0;
	sub_416580();
	result = nox_wcscpy(v13, a1);
	if (true) { // TODO: was if (v13)
		if (v13[0] == 34) {
			result = nox_wcstok(&v13[1], L"\"\n\r");
			v7 = result;
			v5 = 1;
		} else {
			result = nox_wcstok(v13, L" \n\t\r");
			v7 = result;
		}
		if (v7) {
			do {
				v8 = v11;
				v11 = ++v4;
				v12[v8] = (int)v7;
				v9 = &v7[nox_wcslen(v7) + 1];
				if (v5) {
					++v9;
				}
				if (*v9 == 34) {
					result = nox_wcstok((wchar_t*)v9 + 1, L"\"\n\r");
					v7 = result;
					v5 = 1;
				} else {
					result = nox_wcstok(0, L" \n\t\r");
					v7 = result;
					v5 = 0;
				}
			} while (v7);
			if (v4) {
				result = (const wchar_t*)sub_57A620(v4, (const wchar_t**)v12, a2, a4);
				if (!result) {
					if (a3) {
						v10 = (wchar_t*)calloc(1, 0x20Cu);
						nox_wcscpy(v10 + 6, a1);
						nox_common_list_append_4258E0(a3, v10);
					}
				}
			}
		}
	}
}
// 57A4D0: using guessed type int var_280[32];

//----- (0057A620) --------------------------------------------------------
int sub_57A620(unsigned char a1, const wchar_t** a2, int a3, int a4) {
	const wchar_t** v4;  // ebp
	unsigned char v5;    // dl
	int v6;              // esi
	unsigned short* v8;  // eax
	int v9;              // eax
	int v10;             // ebx
	unsigned char v11;   // cl
	int v12;             // eax
	unsigned short* v13; // eax
	int v14;             // esi
	int v15;             // ecx
	char v16[100];       // [esp+10h] [ebp-64h]
	unsigned char v17;   // [esp+7Ch] [ebp+8h]
	unsigned char v18;   // [esp+7Ch] [ebp+8h]

	v4 = a2;
	nox_sprintf(v16, "%S", *a2);
	v5 = 0;
	v17 = 0;
	do {
		if (!strcmp(*(const char**)getMemAt(0x587000, 312208 + 8 * v17), v16)) {
			dword_5d4594_2523764 = *getMemU32Ptr(0x587000, 312212 + 8 * v17);
			return a4 == dword_5d4594_2523764;
		}
		v17 = ++v5;
	} while (v5 < 7u);
	if (!(dword_5d4594_2523764 & a4) || _nox_wcsicmp(*v4, L"set") || a1 <= 1u) {
		return 0;
	}
	if (_nox_wcsicmp(v4[1], L"spell")) {
		if (_nox_wcsicmp(v4[1], L"weapon")) {
			if (_nox_wcsicmp(v4[1], L"armor")) {
				return 0;
			}
			if (a1 != 4) {
				return 0;
			}
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				return 0;
			}
			nox_sprintf(v16, "%S", v4[2]);
			v13 = (unsigned short*)sub_415EC0(v16);
			if (!v13) {
				return 0;
			}
			v14 = sub_415D10((char*)*v13);
			if (!v14) {
				return 0;
			}
			if (_nox_wcsicmp(v4[3], L"off")) {
				v15 = v14 | *(uint32_t*)(a3 + 48);
			} else {
				v15 = ~v14 & *(uint32_t*)(a3 + 48);
			}
			*(uint32_t*)(a3 + 48) = v15;
		} else {
			if (a1 != 4) {
				return 0;
			}
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				return 0;
			}
			nox_sprintf(v16, "%S", v4[2]);
			v8 = (unsigned short*)sub_415A30(v16);
			if (!v8) {
				return 0;
			}
			v9 = nox_xxx_ammoCheck_415880((char*)*v8);
			v10 = v9;
			if (!v9) {
				return 0;
			}
			v11 = 0;
			v18 = 0;
			if (v9 > 0) {
				do {
					v12 = v10 >> 8;
					if (v10 >> 8 > 0) {
						v10 >>= 8;
					}
					++v11;
				} while (v12 > 0);
				v18 = v11;
			}
			if (_nox_wcsicmp(v4[3], L"off")) {
				*(uint8_t*)(v18 + a3 + 43) |= v10;
			} else {
				*(uint8_t*)(v18 + a3 + 43) &= ~(uint8_t)v10;
			}
		}
	} else {
		if (a1 != 4) {
			return 0;
		}
		nox_sprintf(v16, "%S", v4[2]);
		v6 = nox_xxx_spellNameToN_4243F0(v16);
		if (!v6) {
			v6 = nox_xxx_spellByTitle_424960((wchar_t*)v4[2]);
			if (!v6) {
				return 0;
			}
		}
		if (!nox_xxx_spellIsValid_424B50(v6)) {
			return 0;
		}
		if (nox_xxx_spellFlags_424A70(v6) & 0x7000000) {
			if (!_nox_wcsicmp(v4[3], L"off")) {
				sub_453FA0(a3 + 24, v6, 0);
			}
		}
	}
	if (a4 == dword_5d4594_2523764) {
		return 1;
	}
	return 0;
}

//----- (0057A950) --------------------------------------------------------
int sub_57A950(char* a1) {
	char v2[256]; // [esp+Ch] [ebp-100h]

	strcpy(v2, "maps\\");
	strncat(v2, a1, 256-6);
	v2[strlen(v2)-4] = 0;
	*(uint16_t*)&v2[strlen(v2)] = *getMemU16Ptr(0x587000, 312564);
	strcat(v2, a1);
	return sub_4D0550(v2);
}

//----- (0057A9F0) --------------------------------------------------------
int sub_57A9F0(const char* a1, const char* a2) {
	char FileName[256]; // [esp+Ch] [ebp-100h]

	strcpy(FileName, "maps\\");
	strcat(FileName, a1);
	*(uint16_t*)&FileName[strlen(FileName)] = *getMemU16Ptr(0x587000, 312576);
	strcat(FileName, a2);
	return nox_fs_remove(FileName);
}

//----- (0057AAA0) --------------------------------------------------------
char sub_57AAA0(const char* a1, char* a2, int* a3) {
	FILE* v3;           // eax
	FILE* v4;           // ebp
	int* i;             // esi
	char* v6;           // eax
	int v7;             // esi
	int v8;             // edi
	char* v9;           // eax
	int v10;            // esi
	int v11;            // edi
	char* v12;          // eax
	int v13;            // ebx
	int v14;            // esi
	char* v15;          // edi
	char* v16;          // eax
	int v18;            // [esp+10h] [ebp-27Ch]
	char v19[24];       // [esp+14h] [ebp-278h]
	char v20[36];       // [esp+2Ch] [ebp-260h]
	char v21[24];       // [esp+50h] [ebp-23Ch]
	char v22[36];       // [esp+68h] [ebp-224h]
	char v23[256];      // [esp+8Ch] [ebp-200h]
	char FileName[256]; // [esp+18Ch] [ebp-100h]

	LOBYTE(v3) = a2[52];
	if ((char)v3 >= 0) {
		strcpy(FileName, "maps\\");
		strncat(FileName, a2, 8u);
		*(uint16_t*)&FileName[strlen(FileName)] = *getMemU16Ptr(0x587000, 312588);
		strcat(FileName, a1);
		v3 = nox_fs_create_text(FileName);
		v4 = v3;
		if (v3) {
			if (dword_5d4594_2650652) {
				strcpy(v21, a2);
				strcpy(v19, a2);
				sub_57A1E0((int*)v21, 0, 0, 4, *((uint16_t*)a2 + 26));
				sub_57A1E0((int*)v19, 0, 0, 3, *((uint16_t*)a2 + 26));
			}
			if (a3) {
				for (i = nox_common_list_getFirstSafe_425890(a3); i; i = nox_common_list_getNextSafe_4258A0(i)) {
					nox_sprintf(v23, "%S\n", i + 3);
					nox_fs_fputs(v4, v23);
				}
			}
			v6 = sub_57A1B0(*((uint16_t*)a2 + 26));
			nox_fs_fputs(v4, v6);
			nox_fs_fputs(v4, "\n");
			v7 = 1;
			v8 = 136;
			do {
				if (nox_xxx_spellIsValid_424B50(v7) && !sub_454000((int)(a2 + 24), v7) &&
					nox_xxx_spellFlags_424A70(v7) & 0x7000000 &&
					(!dword_5d4594_2650652 || sub_454000((int)v22, v7) || !sub_454000((int)v20, v7))) {
					v9 = nox_xxx_spellNameByN_424870(v7);
					nox_sprintf(v23, "%s %s \"%s\" %s\n", getMemAt(0x587000, 312616), getMemAt(0x587000, 312608), v9,
								getMemAt(0x587000, 312604));
					nox_fs_fputs(v4, v23);
				}
				++v7;
				--v8;
			} while (v8);
			v10 = 1;
			v11 = 26;
			do {
				if (!(v10 & *((uint32_t*)a2 + 12))) {
					v12 = sub_415E40((char*)v10);
					if (v12) {
						nox_sprintf(v23, "%s %s \"%s\" %s\n", getMemAt(0x587000, 312648), getMemAt(0x587000, 312640),
									v12, getMemAt(0x587000, 312636));
						nox_fs_fputs(v4, v23);
					}
				}
				v10 *= 2;
				--v11;
			} while (v11);
			v13 = 1;
			v14 = 1;
			v18 = 27;
			v15 = a2 + 44;
			do {
				if (!((unsigned char)v13 & (unsigned char)*v15)) {
					v16 = sub_4159B0((char*)v14);
					if (v16) {
						nox_sprintf(v23, "%s %s \"%s\" %s\n", getMemAt(0x587000, 312680), getMemAt(0x587000, 312672),
									v16, getMemAt(0x587000, 312668));
						nox_fs_fputs(v4, v23);
					}
				}
				if (v13 == 128) {
					v13 = 1;
					++v15;
				} else {
					v13 *= 2;
				}
				v14 *= 2;
				--v18;
			} while (v18);
			LOBYTE(v3) = 0;
			nox_fs_close(v4);
		}
	}
	return (char)v3;
}

//----- (0057ADF0) --------------------------------------------------------
int* sub_57ADF0(int* a1) {
	int* result; // eax
	int* v2;     // esi
	int* v3;     // edi

	result = nox_common_list_getFirstSafe_425890(a1);
	v2 = result;
	if (result) {
		do {
			v3 = nox_common_list_getNextSafe_4258A0(v2);
			sub_425920((uint32_t**)v2);
			free(v2);
			v2 = v3;
		} while (v3);
	}
	return result;
}

//----- (0057AE30) --------------------------------------------------------
int sub_57AE30(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 312208);
	while (strcmp(*v2, a1)) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 312264)) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 312212 + 8 * v1);
}

//----- (0057AEA0) --------------------------------------------------------
int nox_xxx_playerCheckSpellClass_57AEA0(int a1, int a2) {
	int v2;     // eax
	int result; // eax
	int v4;     // ecx

	v2 = nox_xxx_spellFlags_424A70(a2);
	if (a1 == 1) {
		v4 = 0x2000000;
	} else {
		if (a1 != 2) {
			return 9;
		}
		v4 = 0x4000000;
	}
	if (v2 & 0x1000000 || v4 & v2) {
		result = 0;
	} else {
		result = 9;
	}
	return result;
}

//----- (0057AEE0) --------------------------------------------------------
int sub_57AEE0(int a1, int a2) { return a1 < 75 || a1 > 114 || nox_xxx_countControlledCreatures_500D10(a2) <= 4; }

//----- (0057AF20) --------------------------------------------------------
int nox_xxx_get_57AF20() { return dword_5d4594_2523804; }

//----- (0057B0A0) --------------------------------------------------------
void sub_57B0A0() {
	int result;   // eax
	uint32_t* v1; // ecx

	result = dword_5d4594_2523804;
	if (!result) {
		return;
	}
	v1 = *(uint32_t**)&dword_5d4594_2523780;
	if (dword_5d4594_2523780 && (!*getMemU32Ptr(0x5D4594, 2523772) || *getMemU32Ptr(0x5D4594, 2523772) == 1)) {
		nox_xxx_netSendPointFx_522FF0(154, (float2*)(dword_5d4594_2523780 + 56));
		v1 = *(uint32_t**)&dword_5d4594_2523780;
	}
	if (dword_5d4594_2523776) {
		nox_xxx_delayedDeleteObject_4E5CC0(*(int*)&dword_5d4594_2523776);
		v1 = *(uint32_t**)&dword_5d4594_2523780;
	}
	dword_5d4594_2523776 = 0;
	if (v1) {
		nox_xxx_playerSetState_4FA020(v1, 13);
	}
	dword_5d4594_2523780 = 0;
	if (!sub_45D9B0()) {
		sub_413A00(0);
	}
	dword_5d4594_2523804 = 0;
}

//----- (0057B180) --------------------------------------------------------
long long nox_xxx___Getcvt_57B180() { return *getMemU64Ptr(0x5D4594, 2523788); }

//----- (0057B190) --------------------------------------------------------
int sub_57B190(unsigned short a1, unsigned short a2) {
	int result; // eax
	double v3;  // st7
	double v4;  // st6

	if (!a2) {
		return 4;
	}
	if (a1 == a2) {
		return 0;
	}
	v3 = (double)a1;
	v4 = (double)a2;
	if (v3 >= v4 * *(double*)&qword_581450_9544) {
		return 1;
	}
	result = 2;
	if (v3 < v4 * *getMemDoublePtr(0x581450, 9608)) {
		result = 3;
	}
	return result;
}

//----- (0057B200) --------------------------------------------------------
void nox_xxx_loadBaseValues_57B200() {
	*getMemFloatPtr(0x5D4594, 2523812) = nox_xxx_gamedataGetFloat_419D40("BaseHealth");
	*getMemFloatPtr(0x5D4594, 2523816) = nox_xxx_gamedataGetFloat_419D40("BaseMana");
	*getMemFloatPtr(0x5D4594, 2523824) = nox_xxx_gamedataGetFloat_419D40("BaseStrength");
	*getMemFloatPtr(0x5D4594, 2523820) = nox_xxx_gamedataGetFloat_419D40("BaseSpeed");
	*getMemFloatPtr(0x5D4594, 2523828) =
		nox_xxx_gamedataGetFloat_419D40("WarriorMaxHealth") * *(float*)&nox_xxx_warriorMaxHealth_587000_312784;
	*getMemFloatPtr(0x5D4594, 2523832) =
		nox_xxx_gamedataGetFloat_419D40("WarriorMaxMana") * *(float*)&nox_xxx_warriorMaxMana_587000_312788;
	*getMemFloatPtr(0x5D4594, 2523840) =
		nox_xxx_gamedataGetFloat_419D40("WarriorMaxStrength") * *(float*)&nox_xxx_warriorMaxStrength_587000_312792;
	*getMemFloatPtr(0x5D4594, 2523836) =
		nox_xxx_gamedataGetFloat_419D40("WarriorMaxSpeed") * *(float*)&nox_xxx_warriorMaxSpeed_587000_312796;
	*getMemFloatPtr(0x5D4594, 2523860) =
		nox_xxx_gamedataGetFloat_419D40("ConjurerMaxHealth") * *(float*)&nox_xxx_conjurerMaxHealth_587000_312800;
	*getMemFloatPtr(0x5D4594, 2523864) =
		nox_xxx_gamedataGetFloat_419D40("ConjurerMaxMana") * *(float*)&nox_xxx_conjurerMaxMana_587000_312804;
	*getMemFloatPtr(0x5D4594, 2523872) =
		nox_xxx_gamedataGetFloat_419D40("ConjurerMaxStrength") * *(float*)&nox_xxx_conjurerStrength_587000_312808;
	*getMemFloatPtr(0x5D4594, 2523868) =
		nox_xxx_gamedataGetFloat_419D40("ConjurerMaxSpeed") * *(float*)&nox_xxx_conjurerSpeed_587000_312812;
	*getMemFloatPtr(0x5D4594, 2523844) =
		nox_xxx_gamedataGetFloat_419D40("WizardMaxHealth") * *(float*)&nox_xxx_wizardMaxHealth_587000_312816;
	*getMemFloatPtr(0x5D4594, 2523848) =
		nox_xxx_gamedataGetFloat_419D40("WizardMaxMana") * *(float*)&nox_xxx_wizardMaximumMana_587000_312820;
	*getMemFloatPtr(0x5D4594, 2523856) =
		nox_xxx_gamedataGetFloat_419D40("WizardMaxStrength") * *(float*)&nox_xxx_wizardStrength_587000_312824;
	*getMemFloatPtr(0x5D4594, 2523852) =
		nox_xxx_gamedataGetFloat_419D40("WizardMaxSpeed") * *(float*)&nox_xxx_wizardSpeed_587000_312828;
}

//----- (0057B350) --------------------------------------------------------
float* sub_57B350() { return getMemFloatPtr(0x5D4594, 2523812); }

//----- (0057B360) --------------------------------------------------------
float* nox_xxx_plrGetMaxVarsPtr_57B360(int a1) { return getMemFloatPtr(0x5D4594, 2523828 + 16 * a1); }

//----- (0057B370) --------------------------------------------------------
char sub_57B370(int a1, unsigned char a2, int a3) {
	uint32_t* v3; // eax
	char result;  // al

	if (!(a1 & 0x3001010)) {
		return -1;
	}
	if (a1 & 0x1001000) {
		v3 = nox_xxx_getProjectileClassById_413250(a3);
		goto LABEL_4;
	}
	if (a1 & 0x2000000) {
		v3 = nox_xxx_equipClothFindDefByTT_413270(a3);
	LABEL_4:
		if (v3) {
			result = *((uint8_t*)v3 + 62);
		} else {
			result = 0;
		}
		return result;
	}
	if (a1 & 0x10) {
		result = ~(a2 >> 5) | 0xFE;
	} else {
		result = a3;
	}
	return result;
}

//----- (0057B3D0) --------------------------------------------------------
int nox_cheat_allowall = 0;

int nox_xxx_playerClassCanUseItem_57B3D0(nox_object_t* item, char a2) {
	if (nox_cheat_allowall) {
		return 1;
	}
	return ((unsigned char)(1 << a2) & (unsigned char)sub_57B370(item->obj_class, item->obj_subclass,
																 *(unsigned short*)&item->typ_ind)) != 0;
}

//----- (0057B400) --------------------------------------------------------
int nox_xxx_client_57B400(int a1) {
	int v1; // eax

	v1 = *getMemU32Ptr(0x5D4594, 2523876);
	if (!*getMemU32Ptr(0x5D4594, 2523876)) {
		v1 = nox_xxx_getTTByNameSpriteMB_44CFC0("Glyph");
		*getMemU32Ptr(0x5D4594, 2523876) = v1;
	}
	if (!*getMemU32Ptr(0x8531A0, 2576)) {
		return 0;
	}
	if (*(uint32_t*)(a1 + 108) != v1 || *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2251) == 1) {
		return 1;
	}
	return 0;
}

//----- (0057B450) --------------------------------------------------------
int sub_57B450(nox_drawable* a1p) {
	int* a1 = a1p;
	int v1;           // eax
	unsigned char v2; // bl

	v1 = *getMemU32Ptr(0x5D4594, 2523880);
	if (!*getMemU32Ptr(0x5D4594, 2523880)) {
		v1 = nox_xxx_getTTByNameSpriteMB_44CFC0("Glyph");
		*getMemU32Ptr(0x5D4594, 2523880) = v1;
	}
	if (!a1 || !*getMemU32Ptr(0x852978, 8) || !*getMemU32Ptr(0x8531A0, 2576) ||
		a1[27] == v1 && *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2251) != 1) {
		return 0;
	}
	if (nox_cheat_allowall) {
		return 1;
	}
	v2 = 1 << *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2251);
	return (v2 & (unsigned char)sub_57B370(a1[28], a1[29], a1[27])) != 0;
}

//----- (0057B4D0) --------------------------------------------------------
int sub_57B4D0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		*getMemU32Ptr(0x5D4594, 2523884) = a1;
		dword_5d4594_2523888 = 1;
	} else {
		dword_5d4594_2523888 = 0;
	}
	return result;
}

//----- (0057B500) --------------------------------------------------------
char sub_57B500(int a1, int a2, char a3) {
	int v3;      // eax
	char v4;     // cl
	int v5;      // esi
	int v6;      // edi
	char result; // al
	int v8;      // eax
	int v9;      // ecx
	bool v10;    // sf
	bool v11;    // cc

	if (a1 < 0) {
		return -1;
	}
	if (a1 >= 256) {
		return -1;
	}
	if (a2 < 0) {
		return -1;
	}
	if (a2 >= 256) {
		return -1;
	}
	v3 = nox_xxx_wall_4105E0(a1, a2);
	if (!v3) {
		return -1;
	}
	v4 = *(uint8_t*)(v3 + 4);
	if (v4 & 0x10) {
		if (!(a3 & 0x10)) {
			return -1;
		}
		v5 = *(uint32_t*)(v3 + 28);
		if (!v5) {
			return -1;
		}
		v6 = *(uint32_t*)(v5 + 748);
		if (a3 & 8) {
			if (!*(uint8_t*)(v6 + 1)) {
				return -1;
			}
			if (dword_5d4594_2523888 && nox_xxx_doorGetSomeKey_4E8910(*getMemIntPtr(0x5D4594, 2523884), v5)) {
				dword_5d4594_2523888 = 0;
				return -1;
			}
		}
		if (a3 >= 0 && *(uint8_t*)(v5 + 12) & 4) {
			return -1;
		}
		v8 = *(uint32_t*)(v6 + 12);
		if (v8 != *(uint32_t*)(v6 + 4)) {
			return -1;
		}
		v9 = *getMemIntPtr(0x587000, 196184 + 8 * v8);
		v10 = v9 < 0;
		v11 = v9 <= 0;
		if (v9 > 0) {
			if (*getMemIntPtr(0x587000, 196188 + 8 * v8) > 0) {
				return 1;
			}
			v10 = v9 < 0;
			v11 = v9 <= 0;
		}
		if (v10) {
			if (*getMemIntPtr(0x587000, 196188 + 8 * v8) < 0) {
				return 1;
			}
			v11 = v9 <= 0;
			if (v9 < 0) {
				if (*getMemIntPtr(0x587000, 196188 + 8 * v8) > 0) {
					return 0;
				}
				v11 = v9 <= 0;
			}
		}
		if (v11 || *getMemIntPtr(0x587000, 196188 + 8 * v8) >= 0) {
			return -1;
		}
		result = 0;
	} else {
		if (!(a3 & 0x40) && v4 & 0x40 || v4 & 4 && *(uint8_t*)(*(uint32_t*)(v3 + 28) + 22) > 0xBu) {
			return -1;
		}
		result = *(uint8_t*)v3;
	}
	return result;
}

//----- (0057B630) --------------------------------------------------------
char sub_57B630(int a1, int a2, int a3) {
	int v3;   // eax
	char v4;  // cl
	int v5;   // eax
	int v6;   // esi
	int v7;   // ecx
	int v8;   // edx
	bool v9;  // sf
	bool v10; // cc
	char v11; // bl
	int v13;  // ecx

	if (a2 >= 0 && a2 < 256 && (a3 >= 0 || a3 < 256)) {
		v3 = nox_xxx_wall_4105E0(a2, a3);
		if (v3) {
			v4 = *(uint8_t*)(v3 + 4);
			if (v4 & 0x10) {
				v5 = *(uint32_t*)(v3 + 28);
				if (v5) {
					v6 = *(uint32_t*)(v5 + 748);
					v7 = *(uint32_t*)(v6 + 12);
					if (v7 == *(int*)(v6 + 4)) {
						v8 = *getMemIntPtr(0x587000, 196184 + 8 * v7);
						v9 = v8 < 0;
						v10 = v8 <= 0;
						if (v8 > 0) {
							if (*getMemIntPtr(0x587000, 196188 + 8 * v7) > 0) {
								v11 = 1;
								goto LABEL_22;
							}
							v9 = v8 < 0;
							v10 = v8 <= 0;
						}
						if (v9) {
							if (*getMemIntPtr(0x587000, 196188 + 8 * v7) < 0) {
								v11 = 1;
								goto LABEL_22;
							}
							v10 = v8 <= 0;
							if (v8 < 0) {
								if (*getMemIntPtr(0x587000, 196188 + 8 * v7) > 0) {
								LABEL_21:
									v11 = 0;
								LABEL_22:
									if (*(uint32_t*)(v5 + 508)) {
										if (nox_common_randomInt_415FA0(0, 100) >= 50) {
											return v11;
										}
									} else if (*(uint8_t*)(v6 + 1) && !nox_xxx_doorGetSomeKey_4E8910(a1, v5)) {
										return v11;
									}
									return -1;
								}
								v10 = v8 <= 0;
							}
						}
						if (!v10 && *getMemIntPtr(0x587000, 196188 + 8 * v7) < 0) {
							goto LABEL_21;
						}
					}
				}
			} else if (!(*(uint32_t*)(a1 + 16) & 0x4000) || !(v4 & 0x40)) {
				if (!(v4 & 4)) {
					return *(uint8_t*)v3;
				}
				v13 = *(uint32_t*)(v3 + 28);
				if (!(*(uint8_t*)(v13 + 20) & 2) && *(uint8_t*)(v13 + 22) <= 0xBu) {
					return *(uint8_t*)v3;
				}
			}
		}
	}
	return -1;
}

//----- (0057B770) --------------------------------------------------------
float2* sub_57B770(float2* a1, float2* a2) {
	float2* result; // eax
	long double v3; // st5
	long double v4; // st7
	double v5;      // st6
	long double v6; // st5
	float v7;       // [esp+0h] [ebp-18h]
	float v8;       // [esp+4h] [ebp-14h]
	float v9;       // [esp+Ch] [ebp-Ch]
	float v10;      // [esp+10h] [ebp-8h]
	float v11;      // [esp+20h] [ebp+8h]

	result = a2;
	v9 = a2->field_0;
	v3 = sqrt(a2->field_0 * a2->field_0 + a2->field_4 * a2->field_4);
	v4 = v3 + 0.1;
	v5 = -a2->field_4;
	v6 = (a1->field_0 * a2->field_0 + a1->field_4 * a2->field_4) / (v3 + 0.1);
	v11 = (a2->field_0 * a1->field_4 + v5 * a1->field_0) / v4;
	v7 = v6 * result->field_0 / v4;
	v8 = v6 * result->field_4 / v4;
	v10 = v11 * v5 / v4;
	a1->field_0 = v10 - v7;
	a1->field_4 = v11 * v9 / v4 - v8;
	return result;
}

//----- (0057B810) --------------------------------------------------------
int nox_xxx_collideReflect_57B810(float* a1, int a2) {
	int result; // eax
	double v3;  // st7
	int v4;     // ecx

	result = a2;
	v3 = *(float*)a2;
	if (a1[1] * *a1 <= 0.0) {
		v4 = *(uint32_t*)(a2 + 4);
		*(float*)(a2 + 4) = *(float*)a2;
		*(uint32_t*)a2 = v4;
	} else {
		*(float*)a2 = -*(float*)(a2 + 4);
		*(float*)(a2 + 4) = -v3;
	}
	return result;
}

//----- (0057B850) --------------------------------------------------------
int nox_xxx_map_57B850(float2* a1, float* a2, float2* a3) {
	int result; // eax
	float v4;   // [esp+0h] [ebp-10h]
	float v5;   // [esp+4h] [ebp-Ch]
	float v6;   // [esp+8h] [ebp-8h]
	float v7;   // [esp+Ch] [ebp-4h]

	v4 = a2[5] + a1->field_0;
	v5 = a2[6] + a1->field_4;
	result = 0;
	if ((v5 - v4 + a3->field_0 - a3->field_4) * 0.70709997 < 0.0 &&
		(a2[8] + a1->field_4 - (a2[7] + a1->field_0) + a3->field_0 - a3->field_4) * 0.70709997 > 0.0) {
		v6 = a2[9] + a1->field_0;
		v7 = a2[10] + a1->field_4;
		if ((v7 + v6 - a3->field_0 - a3->field_4) * 0.70709997 > 0.0 &&
			(v5 + v4 - a3->field_0 - a3->field_4) * 0.70709997 < 0.0) {
			result = 1;
		}
	}
	return result;
}

//----- (0057B920) --------------------------------------------------------
int sub_57B920(void* a1) {
	int result; // eax

	result = 0;
	memset(a1, 0, 0x7F8u);
	return result;
}

//----- (0057B930) --------------------------------------------------------
char sub_57B930(int a1, int a2, int a3, unsigned int a4) {
	int v4; // eax
	int v5; // edx

	v4 = (unsigned char)a2;
	v5 = (unsigned char)a2;
	if ((unsigned char)a2 == 255 || !(uint8_t)a2) {
		v4 = 1;
		v5 = 1;
	}
	while (*(unsigned short*)(a1 + 8 * v4) != a2 || *(unsigned short*)(a1 + 8 * v4 + 2) != a3) {
		if (++v4 == 255) {
			v4 = 1;
		}
		if (v4 == v5) {
			goto LABEL_11;
		}
	}
	if (*(uint32_t*)(a1 + 8 * v4 + 4) >= a4) {
		return v4;
	}
LABEL_11:
	LOBYTE(v4) = -1;
	return v4;
}

//----- (0057B9A0) --------------------------------------------------------
char nox_xxx_cliGenerateAlias_57B9A0(int a1, int a2, int a3, unsigned int a4) {
	int v4; // eax
	int v5; // edx

	v4 = (unsigned char)a2;
	v5 = (unsigned char)a2;
	if ((unsigned char)a2 == 255 || !(uint8_t)a2) {
		v4 = 1;
		v5 = 1;
	}
	while ((*(unsigned short*)(a1 + 8 * v4) != a2 || *(unsigned short*)(a1 + 8 * v4 + 2) != a3) &&
		   *(uint32_t*)(a1 + 8 * v4 + 4) >= a4) {
		if (++v4 == 255) {
			v4 = 1;
		}
		if (v4 == v5) {
			LOBYTE(v4) = -1;
			return v4;
		}
	}
	return v4;
}

//----- (0057BA10) --------------------------------------------------------
int sub_57BA10(int a1, short a2, short a3, int a4) {
	int result; // eax

	result = a1;
	*(uint16_t*)a1 = a2;
	*(uint16_t*)(a1 + 2) = a3;
	*(uint32_t*)(a1 + 4) = a4;
	return result;
}

//----- (0057BA30) --------------------------------------------------------
int sub_57BA30(int2* a1, int2* a2, int4* a3) {
	int v3;     // eax
	int v4;     // edx
	int v5;     // ebx
	int v6;     // edx
	int v7;     // ebp
	int v8;     // ebx
	int result; // eax
	int v10;    // edx
	int v11;    // edi
	int v12;    // [esp+10h] [ebp-4h]

	v12 = 0;
	while (1) {
		if (a1->field_0 >= a3->field_0) {
			v3 = a1->field_0 <= a3->field_8 ? 0 : 4;
		} else {
			v3 = 8;
		}
		v4 = a1->field_4;
		v5 = a3->field_4;
		if (v4 >= v5) {
			if (v4 > a3->field_C) {
				LOBYTE(v3) = v3 | 1;
			}
		} else {
			LOBYTE(v3) = v3 | 2;
		}
		if (a2->field_0 >= a3->field_0) {
			v6 = a2->field_0 <= a3->field_8 ? 0 : 4;
		} else {
			v6 = 8;
		}
		v7 = a2->field_4;
		if (v7 >= v5) {
			if (v7 > a3->field_C) {
				v6 |= 1u;
			}
		} else {
			v6 |= 2u;
		}
		if (v6 & v3) {
			result = 0;
			goto LABEL_30;
		}
		if (!v3) {
			break;
		}
	LABEL_20:
		if (v3 & 1) {
			a1->field_0 += (a3->field_C - a1->field_4) * (a2->field_0 - a1->field_0) / (a2->field_4 - a1->field_4);
			a1->field_4 = a3->field_C;
		} else if (v3 & 2) {
			a1->field_0 += (a3->field_4 - a1->field_4) * (a2->field_0 - a1->field_0) / (a2->field_4 - a1->field_4);
			a1->field_4 = a3->field_4;
		} else if (v3 & 4) {
			a1->field_4 += (a3->field_8 - a1->field_0) * (a2->field_4 - a1->field_4) / (a2->field_0 - a1->field_0);
			a1->field_0 = a3->field_8;
		} else if (v3 & 8) {
			a1->field_4 += (a2->field_4 - a1->field_4) * (a3->field_0 - a1->field_0) / (a2->field_0 - a1->field_0);
			a1->field_0 = a3->field_0;
		}
	}
	if (v6) {
		v3 = a1->field_0;
		v8 = a1->field_4;
		*a1 = *a2;
		a2->field_0 = v3;
		a2->field_4 = v8;
		LOBYTE(v3) = v6;
		v12 = !v12;
		goto LABEL_20;
	}
	result = 1;
LABEL_30:
	if (v12) {
		v10 = a1->field_0;
		v11 = a1->field_4;
		*a1 = *a2;
		a2->field_0 = v10;
		a2->field_4 = v11;
	}
	return result;
}

//----- (0057BC50) --------------------------------------------------------
int nox_xxx_mapNxzDecompress_57BC50(char* a1, char* a2) {
	FILE* v2;     // eax
	FILE* v3;     // edi
	int v4;       // esi
	char* v5;     // esi
	char* v6;     // ebx
	char* v7;     // eax
	char* v8;     // ebp
	uint32_t* v9; // edi
	FILE* v10;    // esi
	size_t v12;   // [esp+10h] [ebp-8h]
	size_t v13;   // [esp+14h] [ebp-4h]

	v12 = 0;
	if (!a1) {
		return 0;
	}
	if (!a2) {
		return 0;
	}
	v2 = nox_fs_open(a1);
	v3 = v2;
	if (!v2) {
		return 0;
	}
	v4 = nox_fs_fsize(v3);
	v5 = (char*)(v4 - 4);
	nox_binfile_fread_raw_40ADD0((char*)&v12, 1u, 4u, v3);
	v6 = (char*)calloc(1, (size_t)v5);
	v7 = (char*)calloc(1, v12);
	v8 = v7;
	if (!v6 || !v7) {
		return 0;
	}
	nox_binfile_fread_raw_40ADD0(v6, 1u, (size_t)v5, v3);
	nox_fs_close(v3);
	a1 = v5;
	v13 = v12;
	v9 = sub_578BF0();
	if (nox_xxx_nxzDecompress_578C10(v9, &v8[v12 - v13], &v13, (unsigned int)&v5[v6 - a1], &a1)) {
		while ((int)a1 > 0 && nox_xxx_nxzDecompress_578C10(v9, &v8[v12 - v13], &v13, (unsigned int)&v5[v6 - a1], &a1)) {
			;
		}
	}
	sub_578C40(v9);
	v10 = nox_fs_create(a2);
	if (!v10) {
		return 0;
	}
	nox_fs_fwrite(v10, v8, v12);
	nox_fs_close(v10);
	free(v6);
	free(v8);
	return 1;
}

//----- (0057BDD0) --------------------------------------------------------
int nox_xxx_mapFile_57BDD0(void* lpMem, int a2) {
	size_t v2;        // ebx
	FILE* v3;         // eax
	FILE* v4;         // esi
	char* v5;         // edi
	unsigned int v6;  // eax
	void* v7;         // eax
	void** v8;        // ebp
	size_t v9;        // eax
	size_t i;         // esi
	unsigned int v11; // eax
	FILE* v12;        // eax
	FILE* v13;        // esi
	size_t v15;       // [esp+Ch] [ebp-4h]
	void* lpMema;     // [esp+14h] [ebp+4h]

	v2 = 0;
	v15 = 0;
	if (!lpMem) {
		return 0;
	}
	if (!a2) {
		return 0;
	}
	v3 = nox_fs_open(lpMem);
	v4 = v3;
	if (!v3) {
		return 0;
	}
	v15 = nox_fs_fsize(v4);
	v5 = (char*)calloc(1, v15);
	v6 = sub_578BA0(v15);
	v7 = calloc(1, v6);
	lpMema = v7;
	if (!v5 || !v7) {
		return 0;
	}
	nox_binfile_fread_raw_40ADD0(v5, 1u, v15, v4);
	nox_fs_close(v4);
	v8 = (void**)sub_578B80();
	v9 = v15;
	for (i = 0; i < v15; i += 500000) {
		v11 = v9 - i;
		if (v11 > 0x7A120) {
			v11 = 500000;
		}
		v2 += sub_578BB0(v8, (int)lpMema + v2, (unsigned char*)&v5[i], v11);
		v9 = v15;
	}
	sub_578BD0(v8);
	v12 = nox_fs_create(a2);
	v13 = v12;
	if (!v12) {
		return 0;
	}
	nox_fs_fwrite(v12, &v15, 4);
	nox_fs_fwrite(v13, lpMema, v2);
	nox_fs_close(v13);
	free(v5);
	free(lpMema);
	return 1;
}

//----- (0057BF80) --------------------------------------------------------
unsigned int sub_57BF80() {
	unsigned int v0; // esi
	int i;           // eax
	unsigned int v2; // ecx

	v0 = 0;
	for (i = nox_server_getFirstMapGroup_57C080(); i; i = nox_server_getNextMapGroup_57C090(i)) {
		v2 = *(uint32_t*)(i + 4);
		if (v2 >= v0) {
			v0 = v2 + 1;
		}
	}
	return v0;
}

//----- (0057BFB0) --------------------------------------------------------
int nox_xxx_allocGroupRelatedArrays_57BFB0() {
	dword_5d4594_2523904 = 0;
	char* result = nox_new_alloc_class("ItemGroupInfo", 96, 512);
	nox_alloc_groupInfo_2523892 = result;
	if (!result) {
		return 0;
	}
	nox_alloc_itemGroupElem_2523896 = nox_new_alloc_class("ItemGroupElement", 16, 5000);
	return nox_alloc_itemGroupElem_2523896 != 0;
}

//----- (0057C000) --------------------------------------------------------
void sub_57C000() {
	dword_5d4594_2523904 = 0;
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_itemGroupElem_2523896);
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_groupInfo_2523892);
	nox_server_mapGroupsHead_2523900 = 0;
}

//----- (0057C030) --------------------------------------------------------
int sub_57C030() {
	dword_5d4594_2523904 = 0;
	if (nox_alloc_groupInfo_2523892) {
		nox_free_alloc_class(*(void**)&nox_alloc_groupInfo_2523892);
		nox_alloc_groupInfo_2523892 = 0;
	}
	if (nox_alloc_itemGroupElem_2523896) {
		nox_free_alloc_class(*(void**)&nox_alloc_itemGroupElem_2523896);
		nox_alloc_itemGroupElem_2523896 = 0;
	}
	nox_server_mapGroupsHead_2523900 = 0;
	return 1;
}

//----- (0057C080) --------------------------------------------------------
int nox_server_getFirstMapGroup_57C080() { return nox_server_mapGroupsHead_2523900; }

//----- (0057C090) --------------------------------------------------------
int nox_server_getNextMapGroup_57C090(int a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 88);
	} else {
		result = 0;
	}
	return result;
}

//----- (0057C0A0) --------------------------------------------------------
int nox_server_scriptGetGroup_57C0A0(int a1) {
	int result; // eax

	result = nox_server_mapGroupsHead_2523900;
	if (!nox_server_mapGroupsHead_2523900) {
		return 0;
	}
	while (*(uint32_t*)(result + 4) != a1) {
		result = *(uint32_t*)(result + 88);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (0057C0C0) --------------------------------------------------------
int nox_server_mapLoadAddGroup_57C0C0(char* a1, int a2, char a3) {
	int result; // eax
	int v4;     // esi
	int v5;     // ecx

	result = (int)sub_57C330();
	v4 = result;
	if (result) {
		*(uint32_t*)(result + 4) = a2;
		*(uint8_t*)result = a3;
		strncpy((char*)(result + 8), a1, 0x4Cu);
		*(uint8_t*)(v4 + 83) = 0;
		*(uint32_t*)(v4 + 84) = 0;
		v5 = nox_server_mapGroupsHead_2523900;
		*(uint32_t*)(v4 + 92) = 0;
		*(uint32_t*)(v4 + 88) = v5;
		if (nox_server_mapGroupsHead_2523900) {
			*(uint32_t*)(nox_server_mapGroupsHead_2523900 + 92) = v4;
		}
		nox_server_mapGroupsHead_2523900 = v4;
		result = 1;
	}
	return result;
}

//----- (0057C130) --------------------------------------------------------
int sub_57C130(uint32_t* a1, int a2) {
	int result; // eax
	char* v3;   // esi
	char v4;    // bl
	int v5;     // edx
	int v6;     // ecx

	if (!a1) {
		return 0;
	}
	v3 = *(char**)&nox_server_mapGroupsHead_2523900;
	if (!nox_server_mapGroupsHead_2523900) {
		return 0;
	}
	while (*((uint32_t*)v3 + 1) != a2) {
		v3 = (char*)*((uint32_t*)v3 + 22);
		if (!v3) {
			return 0;
		}
	}
	if (!v3) {
		return 0;
	}
	v4 = *v3;
	result = (int)sub_57C360();
	if (result) {
		if (v4 && v4 != 1 && v4 != 3) {
			if (v4 != 2) {
				nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_itemGroupElem_2523896, (uint64_t*)result);
				return 0;
			}
			*(uint32_t*)result = *a1;
			*(uint32_t*)(result + 4) = a1[1];
		} else {
			*(uint32_t*)result = *a1;
		}
		v5 = *((uint32_t*)v3 + 21);
		*(uint32_t*)(result + 12) = 0;
		*(uint32_t*)(result + 8) = v5;
		v6 = *((uint32_t*)v3 + 21);
		if (v6) {
			*(uint32_t*)(v6 + 12) = result;
		}
		*((uint32_t*)v3 + 21) = result;
		result = 1;
	}
	return result;
}

//----- (0057C280) --------------------------------------------------------
void* nox_server_scriptGetMapGroupByName_57C280(const char* a1, int a2) {
	int i; // esi

	for (i = nox_server_getFirstMapGroup_57C080(); i; i = nox_server_getNextMapGroup_57C090(i)) {
		if (a2 == nox_server_scriptGetGroupId_57C2D0((int**)i) &&
			nox_server_strcmpWithoutMapname_4DA3F0((const char*)(i + 8), a1)) {
			break;
		}
	}
	return i;
}

//----- (0057C330) --------------------------------------------------------
void* sub_57C330() {
	void* v0;     // esi
	void* result; // eax

	v0 = 0;
	if (!nox_common_gameFlags_check_40A5C0(2097153) ||
		(result = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_groupInfo_2523892), (v0 = result) != 0)) {
		result = v0;
	}
	return result;
}

//----- (0057C360) --------------------------------------------------------
void* sub_57C360() { return nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_itemGroupElem_2523896); }

//----- (0057C370) --------------------------------------------------------
void sub_57C370(uint64_t* a1) { nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_groupInfo_2523892, a1); }

//----- (0057C390) --------------------------------------------------------
void sub_57C390(uint64_t* a1) { nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_itemGroupElem_2523896, a1); }

//----- (0057C3B0) --------------------------------------------------------
int nox_server_addNewMapGroup_57C3B0(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)(a1 + 92) = 0;
	*(uint32_t*)(a1 + 88) = nox_server_mapGroupsHead_2523900;
	if (nox_server_mapGroupsHead_2523900) {
		*(uint32_t*)(nox_server_mapGroupsHead_2523900 + 92) = a1;
	}
	nox_server_mapGroupsHead_2523900 = a1;
	return result;
}

//----- (0057C3E0) --------------------------------------------------------
void* nox_xxx_getDebugData_57C3E0() { return dword_5d4594_2523912; }

//----- (0057C3F0) --------------------------------------------------------
void* nox_xxx_nextDebugObject_57C3F0(void* a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)((uint32_t)a1 + 336);
	} else {
		result = 0;
	}
	return result;
}

//----- (0057C410) --------------------------------------------------------
int nox_xxx_allocDebugDataArray_57C410() {
	nox_alloc_debugData_2523908 = nox_new_alloc_class("DebugData", 344, 256);
	return nox_alloc_debugData_2523908 != 0;
}

//----- (0057C440) --------------------------------------------------------
void sub_57C440() {
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_debugData_2523908);
	dword_5d4594_2523912 = 0;
}

//----- (0057C460) --------------------------------------------------------
int sub_57C460() {
	if (nox_alloc_debugData_2523908) {
		nox_free_alloc_class(*(void**)&nox_alloc_debugData_2523908);
		nox_alloc_debugData_2523908 = 0;
	}
	dword_5d4594_2523912 = 0;
	return 1;
}

//----- (0057C490) --------------------------------------------------------
int sub_57C490(const char* a1) {
	int v1; // edi

	v1 = dword_5d4594_2523912;
	if (!dword_5d4594_2523912) {
		return 0;
	}
	while (strcmp(a1, (const char*)v1)) {
		v1 = *(uint32_t*)(v1 + 336);
		if (!v1) {
			return 0;
		}
	}
	return v1 + 80;
}

//----- (0057C500) --------------------------------------------------------
int sub_57C500(const char* a1, const char* a2) {
	char* v2; // edx

	v2 = (char*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_debugData_2523908);
	if (!v2) {
		return 0;
	}
	strcpy(v2, a1);
	strcpy(v2 + 80, a2);
	*((uint32_t*)v2 + 85) = 0;
	*((uint32_t*)v2 + 84) = dword_5d4594_2523912;
	if (dword_5d4594_2523912) {
		*(uint32_t*)((uint32_t)dword_5d4594_2523912 + 340) = v2;
	}
	dword_5d4594_2523912 = v2;
	return 1;
}

//----- (0057C790) --------------------------------------------------------
void sub_57C790(float4* a1, float2* a2, float2* a3, float a4) {
	double v4; // st5
	double v5; // st7
	double v6; // st6
	double v7; // st7
	float v8;  // [esp+0h] [ebp-10h]
	float v9;  // [esp+4h] [ebp-Ch]
	float v10; // [esp+8h] [ebp-8h]
	float v11; // [esp+14h] [ebp+4h]
	float v12; // [esp+18h] [ebp+8h]
	float v13; // [esp+20h] [ebp+10h]

	v8 = a1->field_8 - a1->field_0;
	v4 = a1->field_C - a1->field_4;
	v9 = v4;
	v5 = v4 * (a2->field_4 - a1->field_4) + v8 * (a2->field_0 - a1->field_0);
	v6 = a4 * a4;
	v10 = v5 * v8 / v6;
	a3->field_0 = v10 + a1->field_0;
	a3->field_4 = v5 * v9 / v6 + a1->field_4;
	if (a1->field_0 >= (double)a1->field_8) {
		v12 = a1->field_0;
		v13 = a1->field_8;
	} else {
		v13 = a1->field_0;
		v12 = a1->field_8;
	}
	if (a1->field_4 >= (double)a1->field_C) {
		v7 = a1->field_C;
		v11 = a1->field_4;
	} else {
		v7 = a1->field_4;
		v11 = a1->field_C;
	}
	if (a3->field_0 >= (double)v13) {
		if (a3->field_0 > (double)v12) {
			a3->field_0 = v12;
		}
	} else {
		a3->field_0 = v13;
	}
	if (v7 <= a3->field_4) {
		if (a3->field_4 > (double)v11) {
			a3->field_4 = v11;
		}
	} else {
		a3->field_4 = v7;
	}
}

//----- (0057C8A0) --------------------------------------------------------
int nox_xxx_mathPointOnTheLine_57C8A0(float4* a1, float2* a2, float2* a3) {
	float4* v3; // ecx
	float2* v4; // edx
	double v5;  // st7
	double v6;  // st6
	double v7;  // st6
	double v8;  // st7
	float v10;  // [esp+0h] [ebp-Ch]
	float v11;  // [esp+0h] [ebp-Ch]
	float v12;  // [esp+8h] [ebp-4h]
	float v13;  // [esp+8h] [ebp-4h]
	float v14;  // [esp+10h] [ebp+4h]
	float v15;  // [esp+10h] [ebp+4h]
	float v16;  // [esp+14h] [ebp+8h]
	float v17;  // [esp+18h] [ebp+Ch]

	v3 = a1;
	v4 = a3;
	v5 = a1->field_8 - a1->field_0;
	v6 = a1->field_C - a1->field_4;
	v12 = v6;
	v10 = v6 * v12 + v5 * v5;
	v7 = (a2->field_4 - a1->field_4) * v12 + (a2->field_0 - a1->field_0) * v5;
	v14 = v7;
	v13 = v14 * v12 / v10;
	a3->field_0 = v5 * v7 / v10 + v3->field_0;
	v15 = v13 + v3->field_4;
	a3->field_4 = v15;
	if (v3->field_0 >= (double)v3->field_8) {
		v8 = v3->field_8;
		v16 = v3->field_0;
	} else {
		v8 = v3->field_0;
		v16 = v3->field_8;
	}
	if (v3->field_4 >= (double)v3->field_C) {
		v11 = v3->field_4;
		v17 = v3->field_C;
	} else {
		v17 = v3->field_4;
		v11 = v3->field_C;
	}
	return v8 <= v4->field_0 && v4->field_0 <= (double)v16 && v15 >= (double)v17 && v15 <= (double)v11;
}

//----- (0057CDB0) --------------------------------------------------------
int sub_57CDB0(int2* a1, float* a2, float2* a3) {
	int2* v3;   // esi
	char v4;    // bl
	int result; // eax
	float2* v6; // eax
	float2* v7; // eax
	float2* v8; // eax
	char v9;    // [esp+10h] [ebp+4h]

	v3 = a1;
	v9 = sub_57F2A0((float2*)a2, a1->field_0, a1->field_4);
	v4 = sub_57F1D0((float2*)a2 + 1);
	switch (sub_57B500(v3->field_0, v3->field_4, 64)) {
	case 0:
		if (v9 != 1 && v9) {
			goto LABEL_44;
		}
		a3->field_0 = -0.70709997;
		a3->field_4 = -0.70709997;
		return 1;
	case 1:
		if (v9 == 1 || v9 == 2) {
			goto LABEL_43;
		}
		a3->field_0 = -0.70709997;
		a3->field_4 = 0.70709997;
		return 1;
	case 2:
		switch (v9) {
		case 0:
			goto LABEL_40;
		case 1:
			v6 = a3;
			if (!(v4 & 1)) {
				goto LABEL_23;
			}
			a3->field_0 = -0.70709997;
			a3->field_4 = -0.70709997;
			result = 1;
			break;
		case 2:
			goto LABEL_30;
		case 3:
			goto LABEL_35;
		default:
			return 1;
		}
		return result;
	case 3:
		if (!v9) {
			goto LABEL_40;
		}
		if (v9 != 1) {
			goto LABEL_44;
		}
		goto LABEL_25;
	case 4:
		if (v9 == 1) {
			goto LABEL_25;
		}
		if (v9 == 2) {
			goto LABEL_30;
		}
		a3->field_0 = -0.70709997;
		a3->field_4 = 0.70709997;
		return 1;
	case 5:
		if (v9 == 2) {
			goto LABEL_30;
		}
		if (v9 == 3) {
			goto LABEL_35;
		}
		a3->field_0 = -0.70709997;
		a3->field_4 = -0.70709997;
		return 1;
	case 6:
		if (!v9) {
			goto LABEL_40;
		}
		if (v9 == 3) {
			goto LABEL_35;
		}
		v6 = a3;
	LABEL_23:
		v6->field_0 = 0.70709997;
		v6->field_4 = -0.70709997;
		return 1;
	case 7:
		if (v9 == 1) {
		LABEL_25:
			v7 = a3;
			if (!(v4 & 1)) {
				goto LABEL_38;
			}
			goto LABEL_26;
		}
		v8 = a3;
		if (v4 & 1) {
			goto LABEL_45;
		}
		a3->field_0 = -0.70709997;
		a3->field_4 = 0.70709997;
		return 1;
	case 8:
		if (v9 == 2) {
		LABEL_30:
			v8 = a3;
			a3->field_0 = 0.70709997;
			if (v4 & 1) {
				goto LABEL_46;
			}
			a3->field_4 = -0.70709997;
			result = 1;
		} else {
			v8 = a3;
			a3->field_0 = -0.70709997;
			if (!(v4 & 1)) {
				goto LABEL_46;
			}
			a3->field_4 = -0.70709997;
			result = 1;
		}
		return result;
	case 9:
		if (v9 == 3) {
		LABEL_35:
			v8 = a3;
			if (!(v4 & 4)) {
				goto LABEL_45;
			}
			a3->field_0 = -0.70709997;
			a3->field_4 = 0.70709997;
			result = 1;
		} else {
			v7 = a3;
			if (v4 & 4) {
			LABEL_38:
				v7->field_0 = 0.70709997;
				v7->field_4 = -0.70709997;
				result = 1;
			} else {
			LABEL_26:
				v7->field_0 = -0.70709997;
				v7->field_4 = -0.70709997;
				result = 1;
			}
		}
		return result;
	case 0xA:
		if (v9) {
			if (v4 & 2) {
			LABEL_43:
				a3->field_0 = 0.70709997;
				a3->field_4 = -0.70709997;
				return 1;
			}
		LABEL_44:
			v8 = a3;
		LABEL_45:
			v8->field_0 = 0.70709997;
		} else {
		LABEL_40:
			v8 = a3;
			a3->field_0 = -0.70709997;
			if (!(v4 & 2)) {
				a3->field_4 = -0.70709997;
				return 1;
			}
		}
	LABEL_46:
		v8->field_4 = 0.70709997;
		return 1;
	default:
		return 0;
	}
}

//----- (0057D150) --------------------------------------------------------
void sub_57D150(void** this) {
	void** v1; // esi

	v1 = this;
	operator_delete(this[5]);
	sub_57DF70(v1 + 2);
	operator_delete(*v1);
}

//----- (0057D1C0) --------------------------------------------------------
int sub_57D1C0(void** this, int a2, unsigned char* a3, int a4) {
	void** v4;           // ebx
	void* v5;            // ecx
	int v6;              // eax
	unsigned char* v7;   // esi
	int v8;              // ecx
	int v9;              // eax
	int v10;             // edx
	int v11;             // edi
	int v12;             // ebp
	uint16_t* v13;       // ecx
	unsigned int v14;    // eax
	int v15;             // esi
	uint16_t* v16;       // eax
	int v17;             // ecx
	int v18;             // eax
	int v19;             // ebp
	int v20;             // eax
	unsigned char* i;    // eax
	int v22;             // ecx
	int v23;             // ecx
	int v24;             // eax
	int v25;             // edx
	int v26;             // eax
	int v27;             // ecx
	unsigned char* v28;  // eax
	int v29;             // edx
	int v30;             // eax
	unsigned char v31;   // cl
	int v32;             // eax
	int v33;             // esi
	int v34;             // esi
	char* v35;           // eax
	int v36;             // eax
	int v37;             // esi
	int v38;             // ecx
	unsigned char* v39;  // edx
	unsigned char* v40;  // edi
	unsigned char* v41;  // eax
	unsigned int v42;    // ecx
	int v43;             // edx
	int v44;             // eax
	int v45;             // edi
	int v46;             // edx
	int v47;             // edi
	int v48;             // eax
	char* v49;           // edi
	unsigned char* v50;  // esi
	unsigned int v51;    // eax
	char* v52;           // edi
	unsigned char* v53;  // esi
	char v54;            // cl
	int v55;             // esi
	int v56;             // ecx
	int v57;             // ebp
	unsigned char* v58;  // edx
	int v59;             // ecx
	int v60;             // esi
	unsigned char* v61;  // eax
	unsigned int v62;    // ebp
	int v63;             // ecx
	int v64;             // eax
	int v65;             // esi
	int v66;             // ecx
	int v67;             // edx
	int v68;             // edi
	signed int v69;      // ebp
	int v70;             // eax
	int v71;             // esi
	int v72;             // ecx
	unsigned char* v73;  // edi
	unsigned char* v74;  // eax
	unsigned int v75;    // ecx
	int v76;             // edx
	int v77;             // eax
	int v78;             // edi
	int v79;             // edx
	int v80;             // eax
	char* v81;           // edi
	unsigned char* v82;  // esi
	unsigned int v83;    // eax
	char* v84;           // edi
	int v85;             // ebp
	unsigned char* v86;  // edx
	int v87;             // esi
	int v88;             // ecx
	unsigned char* v89;  // edi
	unsigned char* v90;  // eax
	unsigned int v91;    // ebp
	int v92;             // ecx
	int v93;             // eax
	int v94;             // edi
	int v95;             // eax
	int v96;             // ecx
	int v97;             // edx
	int v98;             // edi
	signed int v99;      // ebp
	int v100;            // eax
	unsigned char* v101; // esi
	int v102;            // edi
	int v103;            // edx
	unsigned char* v104; // edi
	unsigned int v105;   // ecx
	int v106;            // edi
	unsigned char* v107; // edx
	int v108;            // ebp
	signed int v110;     // [esp+10h] [ebp-5Ch]
	int v111;            // [esp+14h] [ebp-58h]
	int v112;            // [esp+18h] [ebp-54h]
	int v113;            // [esp+18h] [ebp-54h]
	int v114;            // [esp+18h] [ebp-54h]
	int v115;            // [esp+18h] [ebp-54h]
	int v116;            // [esp+18h] [ebp-54h]
	int v117;            // [esp+1Ch] [ebp-50h]
	unsigned char* v118; // [esp+20h] [ebp-4Ch]
	int v119;            // [esp+24h] [ebp-48h]
	int v120;            // [esp+24h] [ebp-48h]
	int v121;            // [esp+24h] [ebp-48h]
	unsigned short v122; // [esp+24h] [ebp-48h]
	int v123;            // [esp+24h] [ebp-48h]
	int v124;            // [esp+24h] [ebp-48h]
	int v125;            // [esp+28h] [ebp-44h]
	int v126;            // [esp+2Ch] [ebp-40h]
	int v127;            // [esp+30h] [ebp-3Ch]
	short v128;          // [esp+34h] [ebp-38h]
	int v129;            // [esp+38h] [ebp-34h]
	int v130;            // [esp+38h] [ebp-34h]
	int v131;            // [esp+38h] [ebp-34h]
	int v132;            // [esp+38h] [ebp-34h]
	void* v133;          // [esp+3Ch] [ebp-30h]
	int v134;            // [esp+40h] [ebp-2Ch]
	int v135[10];        // [esp+44h] [ebp-28h]
	int v136;            // [esp+70h] [ebp+4h]
	unsigned char* v137; // [esp+70h] [ebp+4h]
	unsigned char* v138; // [esp+78h] [ebp+Ch]
	unsigned char* v139; // [esp+78h] [ebp+Ch]
	unsigned char* v140; // [esp+78h] [ebp+Ch]
	int v141;            // [esp+78h] [ebp+Ch]
	unsigned char* v142; // [esp+78h] [ebp+Ch]
	unsigned char* v143; // [esp+78h] [ebp+Ch]

	v4 = this;
	v5 = this[2];
	v135[0] = (int)(v4 + 2);
	v135[2] = (int)(v4 + 3);
	v135[4] = a2;
	v135[3] = a2;
	v6 = 0;
	v135[1] = (int)v5;
	v135[5] = 0;
	v135[6] = 0;
	v135[9] = 0;
	v136 = 0;
	v118 = &a3[a4];
	if ((unsigned int)a4 >= 5) {
		v7 = a3;
		if (a3 < a3 + 5) {
			do {
				v8 = *v7++;
				v6 = __ROL4__(v8 ^ v6, 5);
			} while (v7 < a3 + 5);
			v136 = v6;
		}
	}
	v9 = a4;
	v111 = a4;
	if (a4 < 5) {
		goto LABEL_144;
	}
	v10 = v136;
	while (2) {
		v11 = 0;
		v126 = v9 - 5;
		if (v9 - 5 >= 64) {
			v126 = 64;
		}
		v110 = 0;
		v125 = 0;
		while (1) {
			HIWORD(v15) = 0;
			v12 = 0;
			v13 = v4[5];
			v14 = (unsigned int)(214013 * v10 + 2531011) >> 17;
			LOWORD(v15) = v13[v14];
			v16 = &v13[v14];
			v17 = (unsigned int)v4[1] & 0xFFFF;
			v117 = v17;
			*v16 = v17;
			if ((unsigned short)v15 == 0xFFFF || v15 == v17) {
				goto LABEL_62;
			}
			v18 = (unsigned short)(v17 - v15);
			v19 = v18;
			if (v18 >= v111 - v11) {
				v19 = v111 - v11;
			}
			if (v19 >= 521) {
				v18 = 521;
			} else if (v18 >= v111 - v11) {
				v18 = v111 - v11;
			}
			v112 = v18;
			v138 = &a3[v11];
			v119 = 0x10000 - v15;
			if (0x10000 - v15 < v18) {
				v22 = v15;
				if (v15 >= 0x10000) {
				LABEL_33:
					v23 = 0;
					if (v18 + v15 - 0x10000 <= 0) {
					LABEL_23:
						v12 = v18;
						goto LABEL_24;
					}
					while (*((uint8_t*)*v4 + v23) == v138[v119 + v23]) {
						v18 = v112;
						if (++v23 >= v112 + v15 - 0x10000) {
							goto LABEL_23;
						}
					}
					v12 = v119 + v23;
				} else {
					while (*((uint8_t*)*v4 + v22) == v138[v22 - v15]) {
						if (++v22 >= 0x10000) {
							v10 = v136;
							goto LABEL_33;
						}
					}
					v10 = v136;
					v12 = v22 - v15;
				}
			} else {
				v12 = 0;
				if (v18 <= 0) {
					goto LABEL_23;
				}
				while (*((uint8_t*)*v4 + v15 + v12) == a3[v11 + v12]) {
					v18 = v112;
					if (++v12 >= v112) {
						goto LABEL_23;
					}
				}
			}
		LABEL_24:
			if ((unsigned short)(v15 + v12) == v117) {
				v20 = v111 + -v12 - v11;
				if (521 - v12 < v20) {
					v20 = 521 - v12;
				}
				v120 = v20;
				v113 = 0;
				if (v20 > 0) {
					for (i = &a3[v11]; *i == i[v12]; ++i) {
						if (++v113 >= v120) {
							break;
						}
					}
				}
				v12 += v113;
			}
			if (v12 >= 3) {
				v114 = 521 - v12;
				if (521 - v12 >= v11) {
					v114 = v11;
				}
				v24 = (unsigned short)((char*)v4[1] - v15);
				if (v114 >= v24 - v12) {
					v121 = (unsigned short)((char*)v4[1] - v15) - v12;
				} else {
					v121 = v114;
				}
				v25 = 0x10000 - v24;
				if (v121 < 0x10000 - v24) {
					v25 = v114;
					if (v114 < v24 - v12) {
					LABEL_53:
						v26 = 0;
						if (v25 <= 0) {
							goto LABEL_152;
						}
						v122 = v15 - 1;
						v139 = v138 - 1;
						do {
							if (*((uint8_t*)*v4 + v122) != *v139) {
								break;
							}
							++v26;
							--v122;
							--v139;
						} while (v26 < v114);
						if (v26 <= 0) {
						LABEL_152:
							v10 = v136;
						} else {
							v11 -= v26;
							v27 = (int)v4[1] - v26;
							LOWORD(v15) = v15 - v26;
							v12 += v26;
							v4[1] = (void*)v27;
							v28 = &a3[v11];
							LOWORD(v117) = v27;
							v10 = 0;
							if (v28 < v28 + 5) {
								do {
									v29 = *v28++ ^ v10;
									v10 = __ROL4__(v29, 5);
								} while (v28 < &a3[v11 + 5]);
							}
							v136 = v10;
							v125 = 1;
						}
						goto LABEL_62;
					}
					v25 = (unsigned short)((char*)v4[1] - v15) - v12;
				}
				v114 = v25;
				goto LABEL_53;
			}
		LABEL_62:
			v30 = v110;
			if (v110 >= 4) {
				v115 = v11;
				if (v12 <= v110) {
					v4[1] = v133;
					v137 = &a3[v127];
					v55 = __ROL4__(v134 ^ a3[v127 + 5] ^ __ROL4__(a3[v127], 25), 5);
					sub_57E4C0((uint32_t**)v135, (unsigned int)a3, v127, v110 - 4,
							   (unsigned short)((uint16_t)v133 - v128));
					v56 = &v118[-v127] - a3;
					v57 = v110 - 2;
					if (v110 - 2 >= v56 - 2) {
						v57 = v56 - 2;
					}
					v58 = &a3[v127];
					v59 = (int)v4[1] + 2;
					v141 = (int)v4[1] + 2;
					if (v57 > 0) {
						if (v57 <= 1024) {
							v64 = __ROL4__(v55 ^ v137[6] ^ __ROL4__(v137[1], 25), 5);
							v65 = 0;
							v130 = (int)(v137 + 7);
							while (1) {
								*((uint16_t*)v4[5] + ((unsigned int)(214013 * v64 + 2531011) >> 17)) = v65 + v59;
								v66 = *(unsigned char*)(v130 + v65);
								v67 = __ROL4__(*(unsigned char*)(v130 + v65++ - 5), 25);
								v64 = __ROL4__(v64 ^ v66 ^ v67, 5);
								if (v65 >= v57) {
									break;
								}
								LOWORD(v59) = v141;
							}
							v58 = &a3[v127];
							v136 = v64;
						} else {
							v60 = 0;
							v61 = &v137[v57 + 2];
							v62 = (unsigned int)(v61 + 5);
							if (v61 < v61 + 5) {
								do {
									v63 = *v61++;
									v60 = __ROL4__(v63 ^ v60, 5);
								} while ((unsigned int)v61 < v62);
							}
							v136 = v60;
						}
					} else {
						v136 = 0;
					}
					v68 = (unsigned int)v4[1] & 0xFFFF;
					if (v68 + v110 <= 0x10000) {
						v69 = v110;
						memcpy((char*)*v4 + v68, v58, v110);
					} else {
						memcpy((char*)*v4 + v68, v58, 0x10000 - v68);
						v69 = v110;
						memcpy(*v4, &v58[0x10000 - v68], v110 - (0x10000 - v68));
					}
					v4[1] = (char*)v4[1] + v69;
					a3 += v69 + v127;
					goto LABEL_143;
				}
				sub_57E4C0((uint32_t**)v135, (unsigned int)a3, v11, v12 - 4, (unsigned short)(v117 - v15));
				v36 = &v118[-v11] - a3 - 1;
				if (v12 - 1 < v36) {
					v36 = v12 - 1;
				}
				v37 = 0;
				v38 = (int)v4[1] + 1;
				v39 = &a3[v11];
				v123 = v36;
				v129 = (int)v4[1] + 1;
				v140 = &a3[v11];
				v40 = &a3[v11];
				if (v36 > 0) {
					if (v36 <= 1024) {
						v44 = __ROL4__(v136 ^ v40[5] ^ __ROL4__(*v40, 25), 5);
						v45 = (int)(v40 + 1);
						if (v123 > 0) {
							while (1) {
								*((uint16_t*)v4[5] + ((unsigned int)(214013 * v44 + 2531011) >> 17)) = v37 + v38;
								v46 =
									v44 ^ *(unsigned char*)(v45 + 5 + v37) ^ __ROL4__(*(unsigned char*)(v45 + v37), 25);
								++v37;
								v44 = __ROL4__(v46, 5);
								if (v37 >= v123) {
									break;
								}
								LOWORD(v38) = v129;
							}
						}
						v136 = v44;
					} else {
						v41 = &v40[v36 + 1];
						v42 = (unsigned int)(v41 + 5);
						if (v41 < v41 + 5) {
							do {
								v43 = *v41++;
								v37 = __ROL4__(v43 ^ v37, 5);
							} while ((unsigned int)v41 < v42);
						}
						v136 = v37;
					}
					v39 = v140;
				} else {
					v136 = 0;
				}
				v47 = (unsigned int)v4[1] & 0xFFFF;
				if (v47 + v12 > 0x10000) {
					v48 = 0x10000 - v47;
					memcpy((char*)*v4 + v47, v39, 0x10000 - v47);
					v49 = (char*)*v4;
					v50 = &v140[v48];
					v51 = v12 - v48;
					memcpy(*v4, v50, 4 * (v51 >> 2));
					v53 = &v50[4 * (v51 >> 2)];
					v52 = &v49[4 * (v51 >> 2)];
					v54 = v51;
				LABEL_118:
					memcpy(v52, v53, v54 & 3);
					v4[1] = (char*)v4[1] + v12;
					a3 += v115 + v12;
					goto LABEL_143;
				}
			LABEL_117:
				v84 = (char*)*v4 + v47;
				memcpy(v84, v39, 4 * ((unsigned int)v12 >> 2));
				v53 = &v39[4 * ((unsigned int)v12 >> 2)];
				v52 = &v84[4 * ((unsigned int)v12 >> 2)];
				v54 = v12;
				goto LABEL_118;
			}
			if (v12 < 4) {
				goto LABEL_66;
			}
			if (v125) {
				v115 = v11;
				sub_57E4C0((uint32_t**)v135, (unsigned int)a3, v11, v12 - 4, (unsigned short)(v117 - v15));
				v70 = &v118[-v11] - a3 - 1;
				if (v12 - 1 < v70) {
					v70 = v12 - 1;
				}
				v71 = 0;
				v72 = (int)v4[1] + 1;
				v39 = &a3[v11];
				v124 = v70;
				v131 = (int)v4[1] + 1;
				v142 = &a3[v11];
				v73 = &a3[v11];
				if (v70 > 0) {
					if (v70 <= 1024) {
						v77 = __ROL4__(v136 ^ v73[5] ^ __ROL4__(*v73, 25), 5);
						v78 = (int)(v73 + 1);
						if (v124 > 0) {
							while (1) {
								*((uint16_t*)v4[5] + ((unsigned int)(214013 * v77 + 2531011) >> 17)) = v71 + v72;
								v79 =
									v77 ^ *(unsigned char*)(v78 + 5 + v71) ^ __ROL4__(*(unsigned char*)(v78 + v71), 25);
								++v71;
								v77 = __ROL4__(v79, 5);
								if (v71 >= v124) {
									break;
								}
								LOWORD(v72) = v131;
							}
						}
						v136 = v77;
					} else {
						v74 = &v73[v70 + 1];
						v75 = (unsigned int)(v74 + 5);
						if (v74 < v74 + 5) {
							do {
								v76 = *v74++;
								v71 = __ROL4__(v76 ^ v71, 5);
							} while ((unsigned int)v74 < v75);
						}
						v136 = v71;
					}
					v39 = v142;
				} else {
					v136 = 0;
				}
				v47 = (unsigned int)v4[1] & 0xFFFF;
				if (v47 + v12 > 0x10000) {
					v80 = 0x10000 - v47;
					memcpy((char*)*v4 + v47, v39, 0x10000 - v47);
					v81 = (char*)*v4;
					v82 = &v142[v80];
					v83 = v12 - v80;
					memcpy(*v4, v82, 4 * (v83 >> 2));
					v53 = &v82[4 * (v83 >> 2)];
					v52 = &v81[4 * (v83 >> 2)];
					v54 = v83;
					goto LABEL_118;
				}
				goto LABEL_117;
			}
			v30 = v12;
			v110 = v12;
			v128 = v15;
			v127 = v11;
			v133 = v4[1];
			v134 = v10;
		LABEL_66:
			if (v11 + 1 > v126) {
				break;
			}
			v31 = a3[v11];
			v32 = a3[v11 + 5];
			v33 = a3[v11++];
			v34 = v32 ^ __ROL4__(v33, 25);
			v35 = (char*)v4[1];
			v10 = __ROL4__(v10 ^ v34, 5);
			v4[1] = v35 + 1;
			v136 = v10;
			*((uint8_t*)*v4 + (unsigned short)v35) = v31;
		}
		v116 = v11;
		if (v30 < 4) {
			if (v11 + 5 >= v111 && v111 <= 64) {
				v100 = v111 - v11;
				v101 = &a3[v11];
				v102 = (unsigned int)v4[1] & 0xFFFF;
				if (v102 + v100 <= 0x10000) {
					v105 = v100;
					v104 = (unsigned char*)*v4 + v102;
				} else {
					v103 = 0x10000 - v102;
					memcpy((char*)*v4 + v102, v101, 0x10000 - v102);
					v104 = (unsigned char*)*v4;
					v105 = v100 - v103;
					v101 += v103;
				}
				memcpy(v104, v101, v105);
				v4[1] = (char*)v4[1] + v100;
				v11 = v111;
			}
			sub_57E3F0((uint32_t**)v135, (unsigned int)a3, v11);
			a3 += v11;
		} else {
			sub_57E4C0((uint32_t**)v135, (unsigned int)a3, v11, v110 - 4, (unsigned short)((char*)v4[1] - v128));
			v85 = v110 - 1;
			if (v110 - 1 >= &v118[-v11] - a3 - 1) {
				v85 = &v118[-v11] - a3 - 1;
			}
			v86 = &a3[v11];
			v87 = 0;
			v88 = (int)v4[1] + 1;
			v132 = (int)v4[1] + 1;
			v143 = &a3[v11];
			v89 = &a3[v11];
			if (v85 > 0) {
				if (v85 <= 1024) {
					v93 = v136 ^ v89[5] ^ __ROL4__(*v86, 25);
					v94 = (int)(v89 + 1);
					v95 = __ROL4__(v93, 5);
					while (1) {
						*((uint16_t*)v4[5] + ((unsigned int)(214013 * v95 + 2531011) >> 17)) = v87 + v88;
						v96 = *(unsigned char*)(v94 + 5 + v87);
						v97 = __ROL4__(*(unsigned char*)(v94 + v87++), 25);
						v95 = __ROL4__(v95 ^ v96 ^ v97, 5);
						if (v87 >= v85) {
							break;
						}
						LOWORD(v88) = v132;
					}
					v86 = v143;
					v136 = v95;
				} else {
					v90 = &v86[v85 + 1];
					v91 = (unsigned int)(v90 + 5);
					if (v90 < v90 + 5) {
						do {
							v92 = *v90++;
							v87 = __ROL4__(v92 ^ v87, 5);
						} while ((unsigned int)v90 < v91);
					}
					v136 = v87;
				}
			} else {
				v136 = 0;
			}
			v98 = (unsigned int)v4[1] & 0xFFFF;
			if (v98 + v110 <= 0x10000) {
				v99 = v110;
				memcpy((char*)*v4 + v98, v86, v110);
			} else {
				memcpy((char*)*v4 + v98, v86, 0x10000 - v98);
				v99 = v110;
				memcpy(*v4, &v86[0x10000 - v98], v110 - (0x10000 - v98));
			}
			v4[1] = (char*)v4[1] + v99;
			a3 += v116 + v99;
		}
	LABEL_143:
		v9 = v118 - a3;
		v111 = v118 - a3;
		if (v118 - a3 >= 5) {
			v10 = v136;
			continue;
		}
		break;
	}
LABEL_144:
	if (v111) {
		v106 = (unsigned int)v4[1] & 0xFFFF;
		if (v106 + v111 <= 0x10000) {
			v108 = v111;
			memcpy((char*)*v4 + v106, a3, v111);
			v107 = a3;
		} else {
			v107 = a3;
			memcpy((char*)*v4 + v106, a3, 0x10000 - v106);
			v108 = v111;
			memcpy(*v4, &a3[0x10000 - v106], v111 - (0x10000 - v106));
		}
		v4[1] = (char*)v4[1] + v108;
		sub_57E3F0((uint32_t**)v135, (unsigned int)v107, v108);
	}
	return sub_57E7D0((uint32_t**)v135);
}
// 57D736: variable 'v133' is possibly undefined
// 57D739: variable 'v127' is possibly undefined
// 57D75C: variable 'v134' is possibly undefined
// 57D764: variable 'v128' is possibly undefined

//----- (0057DD90) --------------------------------------------------------
uint32_t* sub_57DD90(uint32_t* this) {
	uint32_t* v1; // esi
	void* v2;     // eax

	v1 = this;
	v2 = operator_new(0x224u);
	*v1 = v2;
	memset(v2, 0, 0x224u);
	return v1;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0057DDC0) --------------------------------------------------------
void sub_57DDC0(void** this) { operator_delete(*this); }

//----- (0057DDE0) --------------------------------------------------------
unsigned int sub_57DDE0(int a1, int a2) {
	int v2;              // ecx
	int v3;              // esi
	int i;               // ebx
	int v5;              // eax
	int v6;              // edx
	int v7;              // edi
	int v8;              // esi
	unsigned int result; // eax
	int v10;             // [esp+10h] [ebp-8h]
	int v11;             // [esp+14h] [ebp-4h]
	int v12;             // [esp+1Ch] [ebp+4h]

	v2 = a1;
	v3 = a2;
	for (i = 40; i > 0; i /= 3) {
		v5 = i + 1;
		v11 = i + 1;
		if (i + 1 <= v3) {
			do {
				v6 = 4 * v5;
				v10 = v5;
				v12 = *(uint32_t*)(4 * v5 + v2);
				if (v5 > i) {
					v7 = 4 * i;
					do {
						v8 = *(short*)(v6 - v7 + v2 + 2) - SHIWORD(v12);
						if (!v8) {
							v8 = *(short*)(v6 - v7 + v2) - (short)v12;
						}
						if (v8 >= 0) {
							break;
						}
						*(uint32_t*)(v6 + v2) = *(uint32_t*)(v6 - v7 + v2);
						v6 -= v7;
						v10 -= i;
					} while (v10 > i);
					v5 = v11;
				}
				++v5;
				*(uint32_t*)(v2 + 4 * v10) = v12;
				v3 = a2;
				v11 = v5;
			} while (v5 <= a2);
		}
		result = (unsigned int)(i / 3) >> 31;
	}
	return result;
}

//----- (0057DEA0) --------------------------------------------------------
int sub_57DEA0(uint32_t* this, uint16_t* a2) {
	uint16_t* v2; // esi
	int v3;       // ebx
	int i;        // eax
	short* v5;    // edi
	short v6;     // dx

	v2 = a2;
	v3 = 0;
	for (i = 0; i < 274; ++i) {
		*v2 = i;
		v2 += 2;
		*(v2 - 1) = *(uint16_t*)(*this + 2 * i);
		v5 = (short*)(*this + 2 * i);
		v6 = *v5;
		v3 += v6;
		*v5 = v6 >> 1;
	}
	sub_57DDE0((int)(a2 - 2), 274);
	return v3;
}

//----- (0057DF00) --------------------------------------------------------
uint32_t* sub_57DF00(uint32_t* this) {
	uint32_t* v1;      // ebx
	unsigned char* v2; // eax
	unsigned char* v3; // edi
	uint32_t* result;  // eax

	v1 = this;
	sub_57DD90(this);
	v1[1] = 4096;
	v2 = (unsigned char*)operator_new(0x448u);
	v3 = v2;
	v1[2] = v2;
	result = v1;
	memcpy(v3, getMemAt(0x587000, 313544), 0x448u);
	return result;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0057DF70) --------------------------------------------------------
void sub_57DF70(void** this) {
	void** v1; // esi

	v1 = this;
	operator_delete(this[2]);
	sub_57DDC0(v1);
}

//----- (0057DFC0) --------------------------------------------------------
int sub_57DFC0(uint32_t* this, int* a2) {
	uint32_t* v2;   // esi
	int v3;         // eax
	int v4;         // ecx
	int v5;         // edi
	int v6;         // ebp
	int v7;         // esi
	int v8;         // ebx
	int v9;         // eax
	int v10;        // edx
	int v11;        // eax
	char* v12;      // edx
	int v13;        // eax
	int* v14;       // edx
	int v15;        // edx
	int v16;        // ebx
	int v17;        // esi
	char* v18;      // eax
	int v19;        // ecx
	int v20;        // esi
	int v21;        // eax
	int v22;        // ecx
	int v23;        // eax
	char* v24;      // ecx
	int v25;        // ecx
	int v26;        // eax
	int* v27;       // edi
	int v28;        // ecx
	int* v29;       // eax
	int v30;        // ecx
	int* v31;       // eax
	int v32;        // ebx
	int v33;        // esi
	int v34;        // ecx
	int v35;        // edi
	int result;     // eax
	int v37;        // edx
	short v38;      // di
	int v39;        // esi
	char* v40;      // ecx
	int v41;        // eax
	short v42;      // bp
	int* v43;       // [esp+10h] [ebp-46Ch]
	int v44;        // [esp+10h] [ebp-46Ch]
	int v45;        // [esp+10h] [ebp-46Ch]
	int v46;        // [esp+14h] [ebp-468h]
	int v47;        // [esp+14h] [ebp-468h]
	int* v48;       // [esp+14h] [ebp-468h]
	int v49;        // [esp+18h] [ebp-464h]
	int v50;        // [esp+18h] [ebp-464h]
	int v51;        // [esp+18h] [ebp-464h]
	int v52;        // [esp+1Ch] [ebp-460h]
	int v53;        // [esp+1Ch] [ebp-460h]
	int v54;        // [esp+1Ch] [ebp-460h]
	int v55;        // [esp+20h] [ebp-45Ch]
	int v56;        // [esp+24h] [ebp-458h]
	int v57;        // [esp+24h] [ebp-458h]
	int v58;        // [esp+28h] [ebp-454h]
	int v59;        // [esp+2Ch] [ebp-450h]
	char v60[1100]; // [esp+30h] [ebp-44Ch]

	v2 = this;
	*(uint32_t*)v60 = this;
	v3 = sub_57DEA0(this, &v60[4]);
	v4 = 0;
	v5 = 0;
	v6 = 16;
	v56 = v3;
	v2[1] = 4096;
	v55 = 0;
	v46 = 0;
	v52 = 16;
	v43 = a2 - 1;
	while (1) {
		v7 = 0;
		v58 = 0;
		v8 = 0;
		v59 = (v56 - v55) / v6;
		while (1) {
			v49 = 0;
			v9 = 1 << v4;
			if (v5 + (1 << v4) + v7 > 274) {
				v49 = 1;
				v9 = 274 - v5;
			}
			if (v7 < v9) {
				v10 = v7 + v5;
				v11 = v9 - v7;
				v7 += v11;
				v12 = &v60[4 * v10 + 6];
				do {
					v8 += *(short*)v12;
					v12 += 4;
					--v11;
				} while (v11);
				v6 = v52;
			}
			if (v49 || v4 >= 8 || v8 > v59) {
				break;
			}
			v58 = v8;
			++v4;
		}
		if (v4 && abs32(v58 - v59) <= abs32(v8 - v59)) {
			v8 = v58;
			--v4;
		}
		v13 = v46;
		if (v6 < 16) {
			v14 = v43;
			do {
				if (v4 >= *v14) {
					break;
				}
				v14[1] = *v14;
				--v13;
				--v14;
			} while (v13 > 0);
		}
		a2[v13] = v4;
		v55 += v8;
		++v43;
		v5 += 1 << v4;
		--v6;
		++v46;
		v52 = v6;
		if (v6 <= 2) {
			break;
		}
		v4 = 0;
	}
	v15 = 0;
	v16 = 0;
	v17 = 0;
	v44 = 0;
	v47 = 0;
	v50 = 0x7FFFFFFF;
	v53 = 0;
	if (v5 < 274) {
		v18 = &v60[4 * v5 + 6];
		v19 = 274 - v5;
		do {
			v17 += *(short*)v18;
			v18 += 4;
			--v19;
		} while (v19);
		v53 = v17;
	}
	v20 = 0;
	v21 = 1;
	if (v5 + 1 <= 274) {
		do {
			if (v15 < v21) {
				v22 = v15 + v5;
				v23 = v21 - v15;
				v15 += v23;
				v24 = &v60[4 * v22 + 6];
				do {
					v16 += *(short*)v24;
					v24 += 4;
					--v23;
				} while (v23);
			}
			v25 = 0;
			v26 = 274 - v15 - v5;
			if (v26 > 1) {
				do {
					++v25;
				} while (1 << v25 < v26);
			}
			if (v20 <= 8 && v25 <= 8) {
				if (v16 * v20 + v25 * (v53 - v16) >= v50) {
					break;
				}
				v50 = v16 * v20 + v25 * (v53 - v16);
				v44 = v20;
				v47 = v25;
			}
			v21 = 1 << ++v20;
		} while (v5 + (1 << v20) + v15 <= 274);
	}
	v27 = a2;
	v28 = 14;
	v29 = a2 + 13;
	do {
		if (v44 >= *v29) {
			break;
		}
		v29[1] = *v29;
		--v28;
		--v29;
	} while (v28 > 0);
	a2[v28] = v44;
	v30 = 15;
	v31 = a2 + 14;
	do {
		if (v47 >= *v31) {
			break;
		}
		v31[1] = *v31;
		--v30;
		--v31;
	} while (v30 > 0);
	a2[v30] = v47;
	v32 = 0;
	v33 = 0;
	v51 = 0;
	v45 = 0;
	v48 = a2;
	do {
		v34 = *v27;
		v35 = 1 << *v27;
		result = 274 - v32;
		v57 = v35;
		if (v35 < 274 - v32) {
			result = v35;
		}
		v37 = 0;
		v54 = result;
		if (result > 0) {
			v38 = v34 + 4;
			v39 = v33 << v34;
			v40 = &v60[4 * v32 + 4];
			do {
				v41 = *(short*)v40;
				v40 += 4;
				*(uint16_t*)(*(uint32_t*)(*(uint32_t*)v60 + 8) + 4 * v41) = v38;
				v42 = v37++ | v39;
				*(uint16_t*)(*(uint32_t*)(*(uint32_t*)v60 + 8) + 4 * v41 + 2) = v42;
				result = v54;
			} while (v37 < v54);
			v35 = v57;
			v33 = v45;
			v32 = v51;
		}
		v32 += v35;
		++v33;
		v27 = v48 + 1;
		v51 = v32;
		v45 = v33;
		++v48;
	} while (v33 < 16);
	return result;
}

//----- (0057E2C0) --------------------------------------------------------
int sub_57E2C0(uint32_t** this) {
	uint32_t** v1;     // esi
	uint32_t* v2;      // edi
	unsigned int v3;   // ebp
	int v4;            // eax
	int v5;            // edx
	unsigned short v6; // bx
	int v7;            // ebp
	uint32_t* v8;      // edx
	uint8_t* v9;       // ebx
	int v10;           // ecx
	uint32_t* v11;     // eax
	int v12;           // edi
	char* v13;         // ebx
	uint32_t* v14;     // edx
	int v15;           // eax
	char v16;          // cl
	int v17;           // eax
	int v18;           // ebp
	unsigned int v19;  // ecx
	int v20;           // ecx
	uint8_t* v21;      // eax
	unsigned int v22;  // ecx
	uint32_t* v23;     // eax
	int v24;           // ecx
	int result;        // eax
	int v26;           // [esp+10h] [ebp-44h]
	char v27[64];      // [esp+14h] [ebp-40h]

	v1 = this;
	*this[2] = 2;
	if ((int)--*this[2] <= 0) {
		sub_57E2C0(this);
	}
	++*((uint16_t*)v1[1] + 272);
	v2 = v1[6];
	v3 = (unsigned int)v1[5];
	v4 = (*v1)[2];
	v5 = *(short*)(v4 + 1088);
	v6 = *(uint16_t*)(v4 + 1090);
	v1[6] = (uint32_t*)((char*)v2 + v5);
	v7 = (v6 << (32 - (uint8_t)v2 - v5)) | v3;
	v1[5] = (uint32_t*)v7;
	if ((int)v2 + v5 >= 16) {
		*(uint8_t*)v1[3] = HIBYTE(v7);
		v8 = v1[5];
		v9 = (char*)v1[3] + 1;
		v1[3] = v9;
		*v9 = BYTE2(v8);
		v10 = (int)(v1[6] - 4);
		v11 = (uint32_t*)((uint32_t)v1[5] << 16);
		v1[3] = (uint32_t*)((char*)v1[3] + 1);
		v1[6] = (uint32_t*)v10;
		v1[5] = v11;
	}
	sub_57DFC0(*v1, (int*)v27);
	v12 = 0;
	v13 = v27;
	v26 = 16;
	do {
		v14 = v1[6];
		v15 = *(uint32_t*)v13 - v12;
		v12 = *(uint32_t*)v13;
		v16 = 32 - (uint8_t)v14 - ++v15;
		v17 = (int)v14 + v15;
		v18 = 1 << v16;
		v19 = (unsigned int)v1[5];
		v1[6] = (uint32_t*)v17;
		v20 = v18 | v19;
		v1[5] = (uint32_t*)v20;
		if (v17 >= 16) {
			*(uint8_t*)v1[3] = HIBYTE(v20);
			v21 = (char*)v1[3] + 1;
			v22 = (unsigned int)v1[5] >> 16;
			v1[3] = v21;
			*v21 = v22;
			v23 = v1[5];
			v24 = (int)(v1[6] - 4);
			v1[3] = (uint32_t*)((char*)v1[3] + 1);
			v1[6] = (uint32_t*)v24;
			v1[5] = (uint32_t*)((uint32_t)v23 << 16);
		}
		v13 += 4;
		result = --v26;
	} while (v26);
	return result;
}

//----- (0057E3F0) --------------------------------------------------------
unsigned int sub_57E3F0(uint32_t** this, unsigned int a2, int a3) {
	unsigned char* v3;   // ebx
	unsigned int result; // eax
	uint32_t** v5;       // esi
	bool v6;             // cf
	unsigned short v7;   // di
	int v8;              // eax
	uint32_t* v9;        // edi
	int v10;             // edx
	unsigned short v11;  // bp
	int v12;             // edx
	uint32_t* v13;       // edx
	uint8_t* v14;        // ebp
	int v15;             // ecx
	uint32_t* v16;       // eax
	unsigned int v17;    // [esp+Ch] [ebp+4h]

	v3 = (unsigned char*)a2;
	result = a2 + a3;
	v5 = this;
	v6 = a2 < a2 + a3;
	v17 = a2 + a3;
	if (v6) {
		do {
			v7 = *v3;
			if ((int)--*v5[2] <= 0) {
				sub_57E2C0(v5);
			}
			v8 = v7;
			++*((uint16_t*)v5[1] + v7);
			v9 = v5[6];
			v10 = (*v5)[2];
			v11 = *(uint16_t*)(v10 + 4 * v8 + 2);
			v12 = *(short*)(v10 + 4 * v8);
			v5[5] = (uint32_t*)((v11 << (32 - (uint8_t)v9 - v12)) | (unsigned int)v5[5]);
			v5[6] = (uint32_t*)((char*)v9 + v12);
			if ((int)v9 + v12 >= 16) {
				*(uint8_t*)v5[3] = (unsigned int)v5[5] >> 24;
				v13 = v5[5];
				v14 = (char*)v5[3] + 1;
				v5[3] = v14;
				*v14 = BYTE2(v13);
				v15 = (int)(v5[6] - 4);
				v16 = (uint32_t*)((uint32_t)v5[5] << 16);
				v5[3] = (uint32_t*)((char*)v5[3] + 1);
				v5[6] = (uint32_t*)v15;
				v5[5] = v16;
			}
			result = v17;
			++v3;
		} while ((unsigned int)v3 < v17);
	}
	return result;
}

//----- (0057E4C0) --------------------------------------------------------
int sub_57E4C0(uint32_t** this, unsigned int a2, int a3, unsigned int a4, unsigned int a5) {
	uint32_t** v5;      // esi
	unsigned short v6;  // di
	int v7;             // eax
	uint32_t* v8;       // edi
	unsigned int v9;    // ebp
	int v10;            // ecx
	int v11;            // edx
	unsigned short v12; // bx
	unsigned short v13; // bp
	unsigned int v14;   // ebx
	int v15;            // edi
	int v16;            // ecx
	uint32_t* v17;      // edx
	int v18;            // eax
	int v19;            // ebp
	unsigned int v20;   // edi
	int v21;            // ecx
	int v22;            // eax
	unsigned char* v23; // ebx
	unsigned short v24; // bp
	uint32_t* v25;      // edx
	int v26;            // eax
	unsigned int v27;   // edi
	int v28;            // ebx
	int v29;            // eax
	uint32_t* v30;      // ecx
	uint8_t* v31;       // ebx
	int v32;            // ecx
	uint32_t* v33;      // eax
	int v34;            // edx
	unsigned int v35;   // eax
	uint32_t* v36;      // edi
	unsigned int v37;   // ebp
	int v38;            // edx
	int v39;            // ebp
	uint32_t* v40;      // edx
	uint8_t* v41;       // ebp
	int v42;            // edx
	uint32_t* v43;      // ecx
	uint32_t* v44;      // edx
	int v45;            // edi
	int result;         // eax
	uint32_t* v47;      // edi
	char v48;           // cl
	int v49;            // edx
	unsigned int v50;   // ecx
	uint32_t* v51;      // edx
	uint8_t* v52;       // ebx
	int v53;            // ecx

	v5 = this;
	sub_57E3F0(this, a2, a3);
	if (a4 >= 8) {
		if (a4 >= 0x26) {
			v23 = getMemAt(0x587000, 314640 + 12 * ((a4 - 38) >> 5));
			v24 = *getMemU16Ptr(0x587000, 314640 + 12 * ((a4 - 38) >> 5)) + 4;
			if ((int)--*v5[2] <= 0) {
				sub_57E2C0(v5);
			}
			++*((uint16_t*)v5[1] + v24);
			sub_57F160((int)v5, *(short*)((*v5)[2] + 4 * v24), *(unsigned short*)((*v5)[2] + 4 * v24 + 2));
			v25 = v5[6];
			v26 = *((uint32_t*)v23 + 1) + 4;
			v27 = (unsigned int)v5[5];
			v28 = (((uint8_t)a4 - 38) & 0x1F | (16 * *((unsigned short*)v23 + 4))) << (32 - (uint8_t)v25 - v26);
			v29 = (int)v25 + v26;
			v5[6] = (uint32_t*)v29;
			v5[5] = (uint32_t*)(v28 | v27);
			if (v29 >= 16) {
				goto LABEL_14;
			}
		} else {
			v13 = *getMemU16Ptr(0x587000, 314640 + 12 * ((a4 - 8) >> 1));
			v14 = (a4 - 8) & 1 | *getMemU16Ptr(0x587000, 314648 + 12 * ((a4 - 8) >> 1));
			v15 = *getMemU32Ptr(0x587000, 314644 + 12 * ((a4 - 8) >> 1));
			if ((int)--*v5[2] <= 0) {
				sub_57E2C0(v5);
			}
			++*((uint16_t*)v5[1] + v13);
			v16 = (*v5)[2];
			v17 = v5[6];
			v18 = v15 + *(short*)(v16 + 4 * v13);
			v19 = *(unsigned short*)(v16 + 4 * v13 + 2) << v15;
			v20 = (unsigned int)v5[5];
			v21 = 32 - (uint32_t)v17 - v18;
			v22 = (int)v17 + v18;
			v5[6] = (uint32_t*)v22;
			v5[5] = (uint32_t*)(((v14 | v19) << v21) | v20);
			if (v22 >= 16) {
				goto LABEL_14;
			}
		}
	} else {
		v6 = a4 + 256;
		if ((int)--*v5[2] <= 0) {
			sub_57E2C0(v5);
		}
		v7 = v6;
		++*((uint16_t*)v5[1] + v6);
		v8 = v5[6];
		v9 = (unsigned int)v5[5];
		v10 = (*v5)[2];
		v11 = *(short*)(v10 + 4 * v7);
		v12 = *(uint16_t*)(v10 + 4 * v7 + 2);
		v5[6] = (uint32_t*)((char*)v8 + v11);
		v5[5] = (uint32_t*)((v12 << (32 - (uint8_t)v8 - v11)) | v9);
		if ((int)v8 + v11 >= 16) {
		LABEL_14:
			*(uint8_t*)v5[3] = (unsigned int)v5[5] >> 24;
			v30 = v5[5];
			v31 = (char*)v5[3] + 1;
			v5[3] = v31;
			*v31 = BYTE2(v30);
			v32 = (int)(v5[6] - 4);
			v33 = (uint32_t*)((uint32_t)v5[5] << 16);
			v5[3] = (uint32_t*)((char*)v5[3] + 1);
			v5[6] = (uint32_t*)v32;
			v5[5] = v33;
			goto LABEL_15;
		}
	}
LABEL_15:
	v34 = *getMemU32Ptr(0x587000, 314824 + 8 * (a5 >> 9)) + 9;
	v35 = a5 & 0x1FF | (*getMemU16Ptr(0x587000, 314828 + 8 * (a5 >> 9)) << 9);
	if (v34 <= 16) {
		v47 = v5[6];
		v48 = 32 - (uint8_t)v47 - v34;
		v49 = (int)v47 + v34;
		result = v35 << v48;
		v50 = (unsigned int)v5[5];
		v5[6] = (uint32_t*)v49;
		v5[5] = (uint32_t*)(result | v50);
		if (v49 < 16) {
			return result;
		}
		goto LABEL_21;
	}
	v36 = v5[6];
	v37 = (unsigned int)v5[5];
	v38 = *getMemU32Ptr(0x587000, 314824 + 8 * (a5 >> 9)) - 7;
	v5[6] = (uint32_t*)((char*)v36 + v38);
	v39 = (v35 >> 16 << (32 - (uint8_t)v36 - v38)) | v37;
	v5[5] = (uint32_t*)v39;
	if ((int)v36 + v38 >= 16) {
		*(uint8_t*)v5[3] = HIBYTE(v39);
		v40 = v5[5];
		v41 = (char*)v5[3] + 1;
		v5[3] = v41;
		*v41 = BYTE2(v40);
		v42 = (int)(v5[6] - 4);
		v43 = (uint32_t*)((uint32_t)v5[5] << 16);
		v5[3] = (uint32_t*)((char*)v5[3] + 1);
		v5[6] = (uint32_t*)v42;
		v5[5] = v43;
	}
	v44 = v5[6];
	v45 = ((unsigned short)v35 << (16 - (uint8_t)v44)) | (unsigned int)v5[5];
	result = (int)(v44 + 4);
	v5[5] = (uint32_t*)v45;
	v5[6] = v44 + 4;
	if ((int)(v44 + 4) >= 16) {
	LABEL_21:
		*(uint8_t*)v5[3] = (unsigned int)v5[5] >> 24;
		v51 = v5[5];
		v52 = (char*)v5[3] + 1;
		v5[3] = v52;
		*v52 = BYTE2(v51);
		v53 = (int)(v5[6] - 4);
		result = (uint32_t)v5[5] << 16;
		v5[3] = (uint32_t*)((char*)v5[3] + 1);
		v5[6] = (uint32_t*)v53;
		v5[5] = (uint32_t*)result;
	}
	return result;
}

//----- (0057E7D0) --------------------------------------------------------
int sub_57E7D0(uint32_t** this) {
	uint32_t** v1; // esi
	uint32_t* v2;  // edi
	int v3;        // edx
	uint32_t* v4;  // ecx
	uint8_t* v5;   // ebx
	int v6;        // ecx
	uint32_t* v7;  // eax
	uint32_t* v8;  // edi
	int v9;        // ebx

	v1 = this;
	if ((int)--*this[2] <= 0) {
		sub_57E2C0(this);
	}
	++*((uint16_t*)v1[1] + 273);
	v2 = v1[6];
	v3 = *(short*)((*v1)[2] + 1092);
	v1[5] = (uint32_t*)((*(unsigned short*)((*v1)[2] + 1094) << (32 - (uint8_t)v2 - v3)) | (unsigned int)v1[5]);
	v1[6] = (uint32_t*)((char*)v2 + v3);
	if ((int)v2 + v3 >= 16) {
		*(uint8_t*)v1[3] = (unsigned int)v1[5] >> 24;
		v4 = v1[5];
		v5 = (char*)v1[3] + 1;
		v1[3] = v5;
		*v5 = BYTE2(v4);
		v6 = (int)(v1[6] - 4);
		v7 = (uint32_t*)((uint32_t)v1[5] << 16);
		v1[3] = (uint32_t*)((char*)v1[3] + 1);
		v1[6] = (uint32_t*)v6;
		v1[5] = v7;
	}
	if ((int)v1[6] > 0) {
		do {
			*(uint8_t*)v1[3] = (unsigned int)v1[5] >> 24;
			v8 = v1[5];
			v9 = (int)(v1[6] - 2);
			v1[3] = (uint32_t*)((char*)v1[3] + 1);
			v1[6] = (uint32_t*)v9;
			v1[5] = (uint32_t*)((uint32_t)v8 << 8);
		} while (v9 > 0);
	}
	return (char*)v1[3] - (char*)v1[4];
}

//----- (0057E8A0) --------------------------------------------------------
uint32_t* sub_57E8A0(uint32_t* this) {
	uint32_t* v1;      // ebx
	unsigned char* v2; // eax

	v1 = this;
	sub_57DD90(this);
	v2 = (unsigned char*)operator_new(0x224u);
	v1[33] = v2;
	memcpy(v2, getMemAt(0x587000, 315976), 0x224u);
	memcpy(v1 + 1, getMemAt(0x587000, 315848), 0x80u);
	return v1;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0057E910) --------------------------------------------------------
void sub_57E910(void** this) {
	void** v1; // esi

	v1 = this;
	operator_delete(this[33]);
	sub_57DDC0(v1);
}

//----- (0057E9A0) --------------------------------------------------------
uint32_t* sub_57E9A0(uint32_t* this) {
	uint32_t* v1; // esi

	v1 = this;
	*this = operator_new(0x10000u);
	v1[1] = 0;
	sub_57E8A0(v1 + 2);
	v1[37] = 0;
	v1[36] = 0;
	return v1;
}
// 5667CB: using guessed type void * operator_new(unsigned int);

//----- (0057EA00) --------------------------------------------------------
void sub_57EA00(void** this) {
	void** v1; // esi
	void** v2; // ecx
	void** v4; // [esp+4h] [ebp-10h]

	v1 = this;
	v4 = this;
	v2 = 0;
	if (v4) {
		v2 = v1 + 2;
	}
	sub_57E910(v2);
	operator_delete(*v1);
}

//----- (0057EA80) --------------------------------------------------------
int nox_xxx_nxzDecompressImpl_57EA80(uint32_t* this, uint8_t* a2, uint32_t* a3, unsigned int a4, uint32_t* a5) {
	unsigned char* v5; // ebp
	uint32_t* v6;      // ebx
	unsigned int v7;   // edx
	int v8;            // esi
	int v9;            // eax
	int v10;           // ecx
	unsigned int v11;  // eax
	int v12;           // esi
	int v13;           // eax
	int v14;           // edi
	int v15;           // edx
	int v16;           // ecx
	int v17;           // eax
	int v18;           // ecx
	int v19;           // eax
	char* v20;         // ecx
	short v21;         // si
	int v22;           // edi
	uint32_t* v23;     // edx
	int v24;           // esi
	int v25;           // ecx
	int v26;           // eax
	int v27;           // esi
	int v28;           // eax
	int v29;           // edi
	int v30;           // esi
	int v31;           // esi
	int v32;           // ecx
	int v33;           // edx
	int v34;           // esi
	int v35;           // ecx
	unsigned int v36;  // eax
	int v37;           // esi
	int v38;           // edi
	int v39;           // eax
	int v40;           // ecx
	unsigned int v41;  // eax
	int v42;           // edi
	int v43;           // eax
	int v44;           // edx
	uint8_t* v45;      // edi
	int v46;           // ebp
	int v47;           // eax
	int v48;           // ecx
	int v49;           // esi
	int v50;           // esi
	int v51;           // edx
	const void* v52;   // esi
	unsigned int v53;  // ecx
	int v54;           // esi
	int v55;           // edi
	uint8_t* v56;      // ebp
	int v57;           // edi
	int v58;           // edx
	void* v59;         // edi
	unsigned int v60;  // ecx
	uint8_t* v61;      // esi
	int v63;           // [esp+10h] [ebp-464h]
	int i;             // [esp+10h] [ebp-464h]
	int v65;           // [esp+10h] [ebp-464h]
	int v66;           // [esp+14h] [ebp-460h]
	int v67;           // [esp+14h] [ebp-460h]
	uint8_t* v68;      // [esp+14h] [ebp-460h]
	unsigned int v69;  // [esp+18h] [ebp-45Ch]
	int v70;           // [esp+1Ch] [ebp-458h]
	int v71;           // [esp+1Ch] [ebp-458h]
	uint8_t* v72;      // [esp+20h] [ebp-454h]
	unsigned int v73;  // [esp+24h] [ebp-450h]
	uint8_t* v74;      // [esp+28h] [ebp-44Ch]
	char v75[1096];    // [esp+2Ch] [ebp-448h]

	v5 = (unsigned char*)a4;
	v6 = this;
	v7 = a4 + *a5;
	v74 = a2;
	v73 = a4;
	v69 = a4 + *a5;
	v72 = &a2[*a3];
	this[37] = 0;
	if (a4 >= v7) {
		return 0;
	}
	while (1) {
		v8 = v6[37];
		if (v8 < 4) {
			if ((unsigned int)v5 >= v7) {
				v9 = -1;
				v6[37] = 0;
				v63 = -1;
				goto LABEL_9;
			}
			v10 = (*v5++ << (24 - v8)) | v6[36];
			v6[36] = v10;
			a4 = (unsigned int)v5;
			v6[37] = v8 + 8;
		}
		v11 = v6[36];
		v6[36] = 16 * v11;
		v63 = v11 >> 28;
		v6[37] -= 4;
		v9 = v11 >> 28;
	LABEL_9:
		v12 = v6[2 * v9 + 3];
		if (!v12) {
			v13 = *(short*)(v6[35] + 2 * v6[2 * v9 + 4]);
			goto LABEL_18;
		}
		v14 = v6[37];
		if (v14 >= v12) {
			goto LABEL_15;
		}
		if ((unsigned int)v5 < v7) {
			v16 = (*v5++ << (24 - v14)) | v6[36];
			v6[36] = v16;
			a4 = (unsigned int)v5;
			v6[37] = v14 + 8;
		LABEL_15:
			v15 = v6[36] >> (32 - v12);
			v6[36] <<= v12;
			v6[37] -= v12;
			v9 = v63;
			goto LABEL_16;
		}
		v6[37] = 0;
		v15 = -1;
	LABEL_16:
		v17 = v15 + v6[2 * v9 + 4];
		if (v17 >= 274) {
			return 0;
		}
		v13 = *(short*)(v6[35] + 2 * v17);
	LABEL_18:
		++*(uint16_t*)(v6[2] + 2 * v13);
		// _dprintf("decompress: %d", v13);
		if (v13 < 256) {
			if (a2 < v72) {
				*a2++ = v13;
				v18 = v6[1];
				v6[1] = v18 + 1;
				*(uint8_t*)((unsigned short)v18 + *v6) = v13;
				goto LABEL_73;
			}
			return 0;
		}
		if (v13 == 272) {
			sub_57DEA0(v6 + 2, v75);
			v19 = 0;
			v20 = v75;
			do {
				v21 = *(uint16_t*)v20;
				v20 += 4;
				*(uint16_t*)(v19 + v6[35]) = v21;
				v19 += 2;
			} while (v19 < 548);
			v22 = 0;
			v23 = v6 + 4;
			v70 = 0;
			v66 = 16;
			while (1) {
				for (i = 0;; ++i) {
					v24 = v6[37];
					if (v24 >= 1) {
						goto LABEL_29;
					}
					if ((unsigned int)v5 >= v69) {
						break;
					}
					v25 = (*v5++ << (24 - v24)) | v6[36];
					v6[36] = v25;
					v6[37] = v24 + 8;
				LABEL_29:
					v26 = v6[36] >> 31;
					v27 = v6[37] - 1;
					v6[36] *= 2;
					v6[37] = v27;
					if (v26) {
						goto LABEL_32;
					}
				}
				v6[37] = 0;
			LABEL_32:
				v22 += i;
				*(v23 - 1) = v22;
				*v23 = v70;
				v23 += 2;
				v70 += 1 << v22;
				if (!--v66) {
					a4 = (unsigned int)v5;
					goto LABEL_73;
				}
			}
		}
		if (v13 == 273) {
			break;
		}
		if (v13 < 264) {
			v28 = v13 - 256;
			goto LABEL_43;
		}
		v29 = *getMemU32Ptr(0x587000, 314416 + 8 * v13);
		v30 = v6[37];
		if (v30 >= v29) {
			goto LABEL_41;
		}
		if ((unsigned int)v5 < v69) {
			v32 = (*v5++ << (24 - v30)) | v6[36];
			v6[36] = v32;
			a4 = (unsigned int)v5;
			v6[37] = v30 + 8;
		LABEL_41:
			v31 = v6[36] >> (32 - v29);
			v33 = v6[36] << v29;
			v6[37] -= v29;
			v6[36] = v33;
			goto LABEL_42;
		}
		v6[37] = 0;
		v31 = -1;
	LABEL_42:
		v28 = v31 + *getMemU32Ptr(0x587000, 314420 + 8 * v13);
	LABEL_43:
		v34 = v6[37];
		v67 = v28;
		if (v34 < 3) {
			if ((unsigned int)v5 >= v69) {
				v6[37] = 0;
				v71 = -1;
				goto LABEL_48;
			}
			v35 = (*v5++ << (24 - v34)) | v6[36];
			v6[36] = v35;
			a4 = (unsigned int)v5;
			v6[37] = v34 + 8;
		}
		v36 = v6[36];
		v6[36] = 8 * v36;
		v71 = v36 >> 29;
		v6[37] -= 3;
	LABEL_48:
		v65 = 0;
		v37 = *getMemU32Ptr(0x587000, 316592 + 8 * v71) + 9;
		if (v37 <= 8) {
			goto LABEL_55;
		}
		v38 = v6[37];
		v37 = *getMemU32Ptr(0x587000, 316592 + 8 * v71) + 1;
		if (v38 >= 8) {
			goto LABEL_53;
		}
		if ((unsigned int)v5 < v69) {
			v40 = (*v5++ << (24 - v38)) | v6[36];
			v6[36] = v40;
			a4 = (unsigned int)v5;
			v6[37] = v38 + 8;
		LABEL_53:
			v41 = v6[36];
			v6[36] = v41 << 8;
			v6[37] -= 8;
			v39 = v41 >> 24;
			goto LABEL_54;
		}
		v6[37] = 0;
		v39 = -1;
	LABEL_54:
		v65 = v39 << v37;
	LABEL_55:
		v42 = v6[37];
		if (v42 >= v37) {
			goto LABEL_59;
		}
		if ((unsigned int)v5 < v69) {
			v6[36] |= *v5 << (24 - v42);
			a4 = (unsigned int)(v5 + 1);
			v6[37] = v42 + 8;
		LABEL_59:
			v43 = v6[36] >> (32 - v37);
			v44 = v6[36] << v37;
			v6[37] -= v37;
			v6[36] = v44;
			goto LABEL_60;
		}
		v6[37] = 0;
		v43 = -1;
	LABEL_60:
		v45 = a2;
		v46 = (*getMemU32Ptr(0x587000, 316596 + 8 * v71) << 9) + (v65 | v43);
		v47 = v67 + 4;
		v68 = &a2[v67 + 4];
		// _dprintf("length: %d, distance: %d", v47, v46);
		if (v68 > v72) {
			return 0;
		}
		v48 = v6[1] - v46;
		if (v47 >= v46) {
			v50 = (unsigned short)v48;
			if ((unsigned short)v48 + v46 <= 0x10000) {
				v53 = v46;
				v52 = (const void*)(*v6 + v50);
			} else {
				v51 = 0x10000 - (unsigned short)v48;
				memcpy(a2, (const void*)(*v6 + (unsigned short)v48), 0x10000 - (unsigned short)v48);
				v52 = (const void*)*v6;
				v53 = v46 - v51;
				v45 = &a2[v51];
			}
			memcpy(v45, v52, v53);
			v54 = 0;
			v55 = v47 - v46;
			if (v47 - v46 > 0) {
				v56 = &a2[v46];
				do {
					++v54;
					v56[v54 - 1] = a2[v54 - 1];
				} while (v54 < v55);
			}
		} else {
			v49 = (unsigned short)v48;
			if (v49 + v47 <= 0x10000) {
				memcpy(a2, (const void*)(*v6 + v49), v47);
			} else {
				memcpy(a2, (const void*)(*v6 + v49), 0x10000 - v49);
				memcpy(&a2[0x10000 - v49], (const void*)*v6, v47 - (0x10000 - v49));
			}
		}
		v57 = v6[1] & 0xFFFF;
		if (v57 + v47 <= 0x10000) {
			v61 = a2;
			v60 = v47;
			v59 = (void*)(*v6 + v57);
		} else {
			v58 = 0x10000 - v57;
			memcpy((void*)(*v6 + v57), a2, 0x10000 - v57);
			v59 = (void*)*v6;
			v60 = v47 - v58;
			v61 = &a2[v58];
		}
		v5 = (unsigned char*)a4;
		memcpy(v59, v61, v60);
		v6[1] += v47;
		a2 = v68;
	LABEL_73:
		if ((unsigned int)v5 >= v69) {
			return 0;
		}
		v7 = v69;
	}
	if (a3) {
		*a3 += v74 - a2;
	}
	if (a5) {
		*a5 += v73 - (uint32_t)v5;
	}
	return 1;
}

//----- (0057F160) --------------------------------------------------------
uint32_t* sub_57F160(int this, int a2, int a3) {
	uint32_t* result; // eax
	int v4;           // edx
	uint8_t* v5;      // ecx
	int v6;           // edx
	int v7;           // ecx
	int v8;           // edx

	result = (uint32_t*)this;
	v4 = *(uint32_t*)(this + 24);
	*(uint32_t*)(this + 20) |= a3 << (32 - v4 - a2);
	*(uint32_t*)(this + 24) = v4 + a2;
	if (v4 + a2 >= 16) {
		**(uint8_t**)(this + 12) = *(uint32_t*)(this + 20) >> 24;
		v5 = (uint8_t*)(*(uint32_t*)(this + 12) + 1);
		v6 = result[5] >> 16;
		result[3] = v5;
		*v5 = v6;
		v7 = result[5];
		v8 = result[6] - 16;
		++result[3];
		result[6] = v8;
		result[5] = v7 << 16;
	}
	return result;
}

//----- (0057F1D0) --------------------------------------------------------
char sub_57F1D0(float2* a1) {
	char v1;          // bl
	int v2;           // edi
	double v3;        // st7
	double v4;        // st6
	double v5;        // st7
	unsigned char v7; // [esp+Ch] [ebp-4h]

	v1 = 0;
	v2 = nox_float2int(a1->field_0);
	v7 = nox_float2int(a1->field_4) % 23;
	v3 = (double)(unsigned char)(v2 % 23);
	if (v3 >= 11.5) {
		v4 = (double)v7;
		if (v4 >= 11.5) {
			v1 = 4;
		}
		if (v4 <= 11.5) {
			v1 |= 1u;
		}
	}
	if (v3 <= 11.5) {
		v5 = (double)v7;
		if (v5 >= 11.5) {
			v1 |= 8u;
		}
		if (v5 <= 11.5) {
			v1 |= 2u;
		}
	}
	return v1;
}

//----- (0057F2A0) --------------------------------------------------------
int sub_57F2A0(float2* a1, int a2, int a3) {
	int v3;     // esi
	int v4;     // eax
	int result; // eax
	int v6;     // eax
	float v7;   // [esp+0h] [ebp-Ch]
	float v8;   // [esp+0h] [ebp-Ch]

	v7 = a1->field_0 - (double)(23 * a2);
	v3 = nox_float2int(v7);
	v8 = a1->field_4 - (double)(23 * a3);
	v4 = nox_float2int(v8);
	if (v3 <= v4) {
		LOBYTE(v4) = 22 - v3 <= v4;
		v6 = v4 - 1;
		LOBYTE(v6) = v6 & 0xFD;
		result = v6 + 3;
	} else {
		LOBYTE(v4) = 22 - v3 <= v4;
		result = v4 + 1;
	}
	return result;
}

void nullsub_10(uint32_t a1) {}

int sub_42CC50(void** this) { return sub_42C770(this); }

void nox_xxx_j_resetNPCRenderData_49A2E0(void) { nox_alloc_npcs(); }

int nox_xxx_j_inventoryNameSignInit_467460(void) { return nox_xxx_inventoryNameSignInit_4671E0(); }

void nox_alloc_npcs_2() { nox_alloc_npcs(); }

int nullsub_8(int a1, int a2) { return 0; }
void nullsub_27(uint32_t a1) {}
void nullsub_28(uint32_t a1) {}
void nullsub_30(uint32_t a1) {}
void nullsub_36(void) {}
void nullsub_29(void) {}
void nullsub_35(uint32_t a1, uint32_t a2) {}
void nullsub_34(uint32_t a1, uint32_t a2, uint32_t a3) {}
void nullsub_24(uint32_t a1) {}
void nullsub_31(uint32_t a1) {}
void nullsub_22(void) {}
void nullsub_9(uint32_t a1) {}
void nox_xxx_j_allocHitArray_511840(void) { nox_xxx_allocHitArray_5486D0(); }

