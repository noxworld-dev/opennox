#include "server__network__sdecode.h"

#include "client__network__cdecode.h"
#include "client__system__parsecmd.h"
#include "common__system__team.h"
#include "proto.h"
#include "server__system__trade.h"
#include "server__network__mapsend.h"

//----- (0051BAD0) --------------------------------------------------------
int  nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode(int a1, unsigned __int8* a2, signed int a3) {
	unsigned __int8* v4;                   // esi
	char* v5;                              // eax
	char* v6;                              // eax
	int v7;                                // edx
	int v8;                                // ebx
	int v9;                                // ebp
	int* v10;                              // edi
	char* v11;                             // ecx
	unsigned __int16 v12;                  // ax
	int v13;                               // ecx
	int v14;                               // ecx
	int v15;                               // edi
	int v16;                               // eax
	int v17;                               // edi
	int v18;                               // eax
	int v19;                               // edi
	int v20;                               // eax
	unsigned __int16 v21;                  // dx
	int v22;                               // edi
	int v23;                               // ebx
	int v24;                               // edi
	int v26;                               // edi
	int v27;                               // eax
	int v28;                               // edi
	int v29;                               // eax
	void( * v30)(int, int, _DWORD); // ecx
	int v31;                               // edi
	int v32;                               // eax
	BOOL v33;                              // edi
	int v34;                               // edi
	int v35;                               // eax
	int* v36;                              // edi
	int v37;                               // ebx
	_DWORD* v38;                           // eax
	int v39;                               // ecx
	int v40;                               // ebx
	int v41;                               // eax
	wchar_t* v42;                          // eax
	wchar_t* v43;                          // eax
	int v44;                               // eax
	int v45;                               // edi
	char* v49;                             // ebp
	int v51;                               // eax
	char* v52;                             // eax
	int v53;                               // edi
	char* v54;                             // eax
	char* v55;                             // edi
	int v56;                               // eax
	int v57;                               // eax
	int v58;                               // edi
	int v59;                               // eax
	int v60;                               // ebx
	int v61;                               // edi
	unsigned __int8 v62;                   // al
	_DWORD* v63;                           // eax
	int v64;                               // eax
	int v65;                               // eax
	int v66;                               // eax
	int v67;                               // edi
	int* v68;                              // edi
	int v69;                               // eax
	int v70;                               // edi
	int v71;                               // eax
	_DWORD* v72;                           // eax
	int v73;                               // eax
	int v74;                               // eax
	int v75;                               // eax
	int v76;                               // eax
	int v77;                               // eax
	int v78;                               // eax
	unsigned __int8 v79;                   // al
	int v80;                               // eax
	int v81;                               // ecx
	unsigned int v82;                      // [esp-8h] [ebp-65Ch]
	float v83;                             // [esp+0h] [ebp-654h]
	float v84;                             // [esp+4h] [ebp-650h]
	int v85;                               // [esp+18h] [ebp-63Ch]
	char* v86;                             // [esp+1Ch] [ebp-638h]
	char v87[2];                           // [esp+22h] [ebp-632h]
	char v88[4];                           // [esp+24h] [ebp-630h]
	char* v89;                             // [esp+28h] [ebp-62Ch]
	char v90[6];                           // [esp+2Ch] [ebp-628h]
	unsigned __int8* v91;                  // [esp+34h] [ebp-620h]
	char v92[5];                           // [esp+38h] [ebp-61Ch]
	int v93;                               // [esp+40h] [ebp-614h]
	float2 v94;                            // [esp+44h] [ebp-610h]
	float2 v96;                            // [esp+4Ch] [ebp-608h]
	wchar_t v97[256];                      // [esp+54h] [ebp-600h]
	CHAR FileName[1024];                   // [esp+254h] [ebp-400h]

	// mix patch
	int vU101[2]; // ebp

	if (a3) {
		//	OutputDebugStringA("S -> ");
		//    dhexdump((_BYTE*)a2, a3);
	}

	if (a3 <= 0) {
		*((_DWORD*)nox_common_playerInfoFromNum_417090(a1) + 899) = *getMemU32Ptr(0x5D4594, 2598000);
		return 1;
	}
	v4 = a2;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_22)) {
		v5 = nox_common_playerInfoFromNum_417090(a1);
		nox_xxx_replayWriteMSgMB_4D3450((int)v5, a2, a3);
	}
	switch (*a2) {
	case 0x20u:
		if (!nox_xxx_playerNew_4DD320(a1, (int)(a2 + 1)))
			nox_xxx_netStructReadPackets_5545B0(a1 + 1);
		return 1;
	case 0x22u:
		nox_xxx_playerForceDisconnect_4DE7C0(a1);
		return 1;
	case 0x25u:
		*((_DWORD*)nox_common_playerInfoFromNum_417090(a1) + 899) = *getMemU32Ptr(0x5D4594, 2598000);
		return 1;
	}
	v91 = &a2[a3];
	v6 = nox_common_playerInfoFromNum_417090(a1);
	v8 = (int)v6;
	v89 = v6;
	if (!v6)
		return 1;
	v93 = *((_DWORD*)v6 + 514);
	v9 = v93;
	if (!v93)
		return 1;
	v10 = *(int**)(v93 + 748);
	v85 = *(_DWORD*)(v93 + 748);
	if (a2 >= v91) {
		*(_DWORD*)(v8 + 3596) = *getMemU32Ptr(0x5D4594, 2598000);
		return 1;
	}
	while (v4 < v91) {
		v11 = 0;
		switch (*v4) {
		case 0x26u:
			v4 += 2;
			break;
		case 0x29u:
			nox_xxx_netNeedTimestampStatus_4174F0(v8, 64);
			++v4;
			break;
		case 0x3Fu:
			v4 += nox_xxx_playerSaveInput_51A960(*(unsigned __int8*)(v10[69] + 2064), v4 + 1) + 1;
			break;
		case 0x40u:
			v84 = (double)*(unsigned __int16*)(v4 + 5);
			v83 = (double)*(unsigned __int16*)(v4 + 3);
			nox_xxx_playerSetCustomWP_4F79A0(v9, SLODWORD(v83), SLODWORD(v84));
			v4 += 7;
			break;
		case 0x72u:
			v19 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			v7 = *(_DWORD*)(v85 + 276);
			if (!(*(_BYTE*)(v7 + 3680) & 3) && !*(_DWORD*)(v85 + 280) && !*(_DWORD*)(v85 + 284) &&
				!(*(_BYTE*)(v9 + 16) & 2)) {
				v20 = nox_xxx_equipedItemByCode_4F7920(v9, v19);
				if (v20) {
					v21 = *(_WORD*)(v4 + 5);
					v94.field_0 = (double)*(unsigned __int16*)(v4 + 3);
					v94.field_4 = (double)v21;
					nox_xxx_drop_4ED810(v9, v20, &v94);
				}
			}
			v10 = (int*)v85;
			v4 += 7;
			break;
		case 0x73u:
			v22 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			if (!nox_xxx_gameGet_4DB1B0()) {
				v7 = *(_DWORD*)(v85 + 276);
				if (!((*(_BYTE*)(v7 + 3680) & 3) || (*(_DWORD*)(v85 + 280)) || (*(_DWORD*)(v85 + 284)) || (*(_BYTE*)(v9 + 16) & 2))) {
					v23 = nox_server_getObjectFromNetCode_4ECCB0(v22);
					if (v23) {
						v24 = 0;
						for (int i = nox_xxx_inventoryGetFirst_4E7980(v9); i; i = nox_xxx_inventoryGetNext_4E7990(i))
							v24 += *(unsigned __int8 *) (i + 488);
						if (v24 + *(unsigned __int8 *) (v23 + 488) <= *(unsigned __int16 *) (v9 + 490)) {
							// nox_xxx_inventoryServPlace_4F36F0(v9, v23, 1, 1);
							vU101[0] = v9;
							vU101[1] = v23;
							OnLibraryNotice(420, vU101, v9, v23);
						} else {
							nox_xxx_netPriMsgToPlayer_4DA2C0(v9, "pickup.c:CarryingTooMuch", 0);
						}
					}
				}
			}
			v8 = (int)v89;
			v10 = (int*)v85;
			v4 += 3;
			break;
		case 0x74u:
			v26 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			if (!nox_xxx_gameGet_4DB1B0()) {
				v7 = *(_DWORD *) (v85 + 276);
				if (!(*(_BYTE *) (v7 + 3680) & 3)) {
					v27 = nox_xxx_equipedItemByCode_4F7920(v9, v26);
					if (v27) {
						nox_xxx_useByNetCode_53F8E0(v9, v27);
					}
				}
			}
			v10 = (int*)v85;
			v4 += 3;
			break;
		case 0x75u:
			v15 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			if (!nox_xxx_gameGet_4DB1B0()) {
				v7 = v85;
				if (!(*(_BYTE *) (*(_DWORD *) (v85 + 276) + 3680) & 3)) {
					v16 = nox_xxx_equipedItemByCode_4F7920(v9, v15);
					if (v16) {
						nox_xxx_playerTryEquip_4F2F70((_DWORD *) v9, v16);
					}
				}
			}
			v10 = (int*)v85;
			v4 += 3;
			break;
		case 0x76u:
			v17 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			if (!(*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 3)) {
				v18 = nox_xxx_equipedItemByCode_4F7920(v9, v17);
				if (v18) {
					v7 = v85;
					if (!(*(_BYTE *) (v85 + 88) == 1 && *(_DWORD *) (v18 + 8) & 0x1000000 &&
						  *(_BYTE *) (v18 + 12) & 8)) {
						nox_xxx_playerTryDequip_4F2FB0((_DWORD *) v9, v18);
					}
				}
			}
			v10 = (int*)v85;
			v4 += 3;
			break;
		case 0x78u:
			v31 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			v7 = v85;
			if (!(*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 1)) {
				if (*(_WORD*)(v4 + 1)) {
					v32 = nox_server_getObjectFromNetCode_4ECCB0(v31);
					if (v32)
						nox_xxx_orderUnit_533900(v9, v32, v4[3]);
				} else {
					nox_xxx_orderUnit_533900(v9, 0, v4[3]);
				}
			}
			v10 = (int*)v85;
			v4 += 4;
			break;
		case 0x79u:
			v34 = 1;
			if (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 1) {
				nox_xxx_netPriMsgToPlayer_4DA2C0(v9, "GeneralPrint:NoSpellWarningGeneral", 0);
				v34 = 0;
			}
			if (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 2) {
				nox_xxx_netPriMsgToPlayer_4DA2C0(v9, "GeneralPrint:ConjureNoSpellWarning1", 0);
				v34 = 0;
			}
			if (!nox_common_gameFlags_check_40A5C0(2048)) {
				v35 = *(_DWORD*)(v9 + 16);
				if (v35 & 0x4000)
					v34 = 0;
			}
			if (!nox_common_gameFlags_check_40A5C0(128) && v34) {
				v36 = (int*)(v4 + 1);
				v37 = 0;
				v38 = v4 + 1;
				v39 = 5;
				while (v39) {
					if (*v38)
						++v37;
					++v38;
					--v39;
				}
				if ((v37 != 1 || !nox_xxx_spellDefHasFlags_424A50(*v36, 32) || !*(_DWORD*)(v85 + 288) ||
					 nox_xxx_unitIsEnemyTo_5330C0(v9, *(_DWORD*)(v85 + 288)) || nox_common_gameFlags_check_40A5C0(4096)) &&
					!nox_xxx_spellByBookInsert_4FE340(v9, (int*)(v4 + 1), v37, 3, v4[21]) && v37 == 1) {
					v40 = 5;
					while (v40) {
						if (*v36)
							nox_xxx_netReportSpellStat_4D9630(*(unsigned __int8*)(*(_DWORD*)(v85 + 276) + 2064), *v36, 0);
						++v36;
						--v40;
					}
				}
			}
			v8 = (int)v89;
			v10 = (int*)v85;
			v4 += 22;
			break;
		case 0x7Au:
			v33 = (*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 3) == 0;
			if (!nox_common_gameFlags_check_40A5C0(128) && v33)
				nox_xxx_playerExecuteAbil_4FBB70(v9, v4[1]);
			v10 = (int*)v85;
			v4 += 2;
			break;
		case 0x7Bu:
			v28 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			v7 = v85;
			if (!(*(_BYTE*)(*(_DWORD*)(v85 + 276) + 3680) & 3) && !*(_DWORD*)(v85 + 280) &&
				!*(_DWORD*)(v85 + 284)) {
				v29 = nox_server_getObjectFromNetCode_4ECCB0(v28);
				if (v29) {
					v30 = *(void(**)(int, int, _DWORD))(v29 + 696);
					if (v30)
						v30(v29, v9, 0);
				}
			}
			v10 = (int*)v85;
			v4 += 3;
			break;
		case 0xA5u:
			*(_WORD*)(v8 + 8 * v4[1] + 16) = *((_WORD*)v4 + 1);
			*(_WORD*)(v8 + 8 * v4[1] + 18) = *((_WORD*)v4 + 2);
			v14 = v4[1];
			v7 = *(_DWORD*)(v4 + 6);
			v4 += 10;
			*(_DWORD*)(v8 + 8 * v14 + 20) = v7;
			break;
		case 0xA8u:
			if (v4[3] & 2) {
				nox_swprintf(v97, L"%S", v4 + 11);
				v44 = 1;
			} else {
				nox_wcscpy(v97, (const wchar_t*)(v4 + 11));
				v44 = 2;
			}
			v45 = v44 * v4[8] + 11;
			if (!nox_xxx_giant_57A190(v8)) {
				if (!(v4[3] & 1)) {
					for (char* j = nox_common_playerInfoGetFirst_416EA0(); j; j = nox_common_playerInfoGetNext_416EE0((int) j)) {
						if (nox_common_gameFlags_check_40A5C0(2) && j[2064] == 31) {
							nox_xxx_netOnPacketRecvCli_48EA70(31, (unsigned int) v4, v45);
						} else {
							nox_xxx_netSendSock_552640((unsigned __int8) j[2064] + 1, v4, v45, 0);
							nox_xxx_netSendReadPacket_5528B0((unsigned __int8) j[2064] + 1, 1);
						}
					}
				} else {
					_DWORD* v47 = nox_xxx_objGetTeamByNetCode_418C80(*(unsigned __int16 *) (v4 + 1));
					if (v47) {
						if (nox_xxx_servObjectHasTeam_419130((int) v47)) {
							v86 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned __int8 *) v47 + 4));
							if (v86) {
								for (int j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j; j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
									v49 = nox_common_playerInfoGetByID_417040(*(_DWORD *) (j + 36));
									if (v49 && nox_xxx_teamCompare2_419180(j + 48, v86[57])) {
										if (nox_common_gameFlags_check_40A5C0(2) &&
											*(_DWORD *) (j + 36) == *getMemU32Ptr(0x5D4594, 2616328)) {
											nox_xxx_netOnPacketRecvCli_48EA70((unsigned __int8) v49[2064], (unsigned int) v4, v45);
										} else {
											nox_xxx_netSendSock_552640((unsigned __int8) v49[2064] + 1, v4, v45, 0);
											nox_xxx_netSendReadPacket_5528B0((unsigned __int8) v49[2064] + 1, 1);
										}
									}
								}
							}
						}
					}
				}
			}
			v9 = v93;
			v8 = (int)v89;
			v4 += v45;
			v10 = (int*)v85;
			break;
		case 0xAAu:
			v13 = v10[69];
			*(_DWORD*)&v92[1] = *(_DWORD*)(v4 + 1);
			v92[0] = -85;
			nox_xxx_netAddToMsgListCli_40EBC0(*(unsigned __int8*)(v13 + 2064), 1, v92, 5);
			v4 += 5;
			break;
		case 0xABu:
			sub_4E55A0(*(_BYTE*)(v10[69] + 2064), *(_DWORD*)(v4 + 1));
			v4 += 5;
			break;
		case 0xACu:
			v12 = *(_WORD*)(v4 + 1);
			v4 += 5;
			*(_DWORD*)(v8 + 2284) = v12;
			*(_DWORD*)(v8 + 2288) = *((unsigned __int16*)v4 - 1);
			break;
		case 0xADu:
			nox_xxx_netPlayerIncomingServ_4DDF60(*(unsigned __int8*)(v8 + 2064));
			++v4;
			break;
		case 0xAEu:
			nox_xxx_playerDisconnFinish_4DE530(*(unsigned __int8*)(v8 + 2064), 2);
			++v4;
			break;
		case 0xB6u:
			nox_xxx_playerGoObserver_4E6860(v8, 1, 1);
			v51 = *(_DWORD*)(v8 + 2056);
			if (v51)
				nox_xxx_netChangeTeamMb_419570(v51 + 48, *(_DWORD*)(v8 + 2060));
			nox_xxx_netMapSend_519D20(*(unsigned __int8*)(v8 + 2064));
			++v4;
			break;
		case 0xB7u:
			nox_xxx_netMapSendCancelMap_519DE0_net_mapsend(*(unsigned __int8*)(v8 + 2064));
			++v4;
			break;
		case 0xBBu:
			nox_xxx_serverHandleClientConsole_443E90(v8, v4[1], (wchar_t*)(v4 + 5));
			v4 += 2 * v4[4] + 7;
			break;
		case 0xBCu:
			v87[0] = -67;
			v42 = nox_xxx_sysopGetPass_40A630();
			if (!*v42 || _nox_wcsicmp((const wchar_t*)(v4 + 1), v42)) {
				v87[1] = 0;
			} else {
				v87[1] = 1;
				if (!sub_4D12A0(*(unsigned __int8*)(v8 + 2064))) {
					sub_4D1210(*(unsigned __int8*)(v8 + 2064));
					v43 = nox_strman_loadString_40F1D0("sysopAccessGranted", 0,
												"C:\\NoxPost\\src\\Server\\Network\\sdecode.c", 735);
					nox_xxx_consoleVPrint_450C00(6u, v43, v8 + 4704);
				}
			}
			nox_xxx_netSendPacket0_4E5420(*(unsigned __int8*)(v8 + 2064), v87, 2, 0, 1);
			v4 += 21;
			break;
		case 0xBEu:
			++v4;
			break;
		case 0xBFu:
			*(_BYTE*)(v8 + 3676) = 3;
			sub_519E80(*(unsigned __int8*)(v8 + 2064));
			++v4;
			break;
		case 0xC0u:
			nox_xxx_gameServerReadyMB_4DD180(*(unsigned __int8*)(v8 + 2064));
			++v4;
			break;
		case 0xC1u:
			if (nox_common_gameFlags_check_40A5C0(4096) && *(_BYTE*)(v8 + 2064) != 31 && *(_DWORD*)(v8 + 2092) &&
				*(_DWORD*)(v8 + 2056) && v10[138] == 1) {
				nox_xxx_playerCallDisconnect_4DEAB0(*(unsigned __int8*)(v8 + 2064), 2);
				v4 += 3;
			} else {
				v52 = nox_common_get_data_path_409E10();
				nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v52);
				if (nox_xxx_playerSaveToFile_41A140(FileName, *(unsigned __int8*)(v8 + 2064)))
					sub_41CFA0(FileName, *(unsigned __int8*)(v8 + 2064));
				DeleteFileA(FileName);
				v4 += 3;
			}
			break;
		case 0xC2u:
			switch (v4[1]) {
			case 0u:
				sub_40B5D0(*(unsigned __int8*)(v8 + 2064) + 1, v4[2], (const char*)v4 + 8, *((_DWORD*)v4 + 1),
						   v4[136]);
				v4 += 140;
				break;
			case 1u:
				LOBYTE(v11) = v4[3];
				sub_40BFF0(*(unsigned __int8*)(v8 + 2064) + 1, v4[2], v11);
				v4 += 4;
				break;
			case 2u:
				v90[0] = -62;
				v90[1] = 3;
				v90[2] = v4[2];
				v82 = *(unsigned __int8*)(v8 + 2064) + 1;
				*(_WORD*)&v90[4] = *((_WORD*)v4 + 2);
				nox_xxx_netSendSock_552640(v82, v90, 6, 3);
				sub_40B250(*(unsigned __int8*)(v8 + 2064) + 1, v4[2], *((_WORD*)v4 + 2), v4 + 8,
						   *((unsigned __int16*)v4 + 3));
				v4 += *((unsigned __int16*)v4 + 3) + 8;
				break;
			case 3u:
				sub_40BF60(*(unsigned __int8*)(v8 + 2064) + 1, v4[2], *((unsigned __int16*)v4 + 2));
				v4 += 6;
				break;
			case 4u:
				sub_40C030(*(unsigned __int8*)(v8 + 2064) + 1, v4[2]);
				v4 += 3;
				break;
			case 5u:
				LOBYTE(v7) = v4[3];
				sub_40B720(v7, v4[2]);
				v4 += 4;
				break;
			case 6u:
				LOBYTE(v11) = v4[3];
				sub_40C070(*(unsigned __int8*)(v8 + 2064) + 1, (int)v11, v4[2]);
				v4 += 4;
				break;
			default:
				break;
			}
			break;
		case 0xC4u:
			if (v4[1] == 10) {
				v55 = nox_xxx_clientGetTeamColor_418AB0(*(_DWORD*)(v4 + 2));
				if (v55) {
					v56 = nox_server_getObjectFromNetCode_4ECCB0(*((unsigned __int16*)v4 + 3));
					nox_xxx_createAtImpl_4191D0(v55[57], v56 + 48, 1, *((unsigned __int16*)v4 + 3), 1);
				}
				v10 = (int*)v85;
				v4 += 10;
			} else if (v4[1] == 11) {
				v53 = nox_server_getObjectFromNetCode_4ECCB0(*((unsigned __int16*)v4 + 3));
				if (v53) {
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						nox_xxx_mapFindPlayerStart_4F7AB0(&v96, v53);
						nox_xxx_unitMove_4E7010(v53, &v96);
					}
					v54 = nox_xxx_clientGetTeamColor_418AB0(*(_DWORD*)(v4 + 2));
					if (v54)
						sub_4196D0(v53 + 48, (int)v54, *((unsigned __int16*)v4 + 3), 1);
				}
				v10 = (int*)v85;
				v4 += 10;
			}
			break;
		case 0xC8u:
			sub_446070();
			++v4;
			break;
		case 0xD0u:
			if (v4[1] == 1) {
				if (nox_xxx_gameGet_4DB1B0() || (v7 = v10[69], *(_BYTE*)(v7 + 3680) & 3) ||
					(v57 = nox_server_getObjectFromNetCode_4ECCB0(*((unsigned __int16*)v4 + 1))) == 0) {
					v4 += 4;
				} else {
					nox_xxx_script_forcedialog_548CD0(v9, v57);
					v4 += 4;
				}
			} else if (v4[1] == 2) {
				nox_xxx_scriptDialog_548D30(v9, v4[2]);
				v4 += 3;
			}
			break;
		case 0xD4u:
			v41 = sub_40A220();
			nox_xxx_netTimerStatus_4D8F50(a1, v41);
			++v4;
			break;
		case 0xE0u:
			v58 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			if (*(_WORD*)(v4 + 1)) {
				v59 = nox_server_getObjectFromNetCode_4ECCB0(v58);
				sub_53AB90(v9, v59);
			} else {
				sub_53AB90(v9, 0);
			}
			v10 = (int*)v85;
			v4 += 3;
			break;
		case 0xE2u:
			v60 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned __int16*)(v4 + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
				nox_xxx_netTestHighBit_578B70(*(unsigned __int16*)(v4 + 1));
			v61 = nox_xxx_equipedItemByCode_4F7920(v9, v60);
			if (v61 || (v61 = sub_510DE0(v9, v60)) != 0 || (v61 = nox_server_getObjectFromNetCode_4ECCB0(v60)) != 0) {
				v88[0] = -30;
				*(_WORD*)&v88[1] = nox_xxx_netGetUnitCodeServ_578AC0((_DWORD*)v61);
				v62 = v4[3];
				if (v62 == 1) {
					v88[3] = **(_BYTE**)(v61 + 736);
				} else if (v62 == 2) {
					v88[3] = nox_xxx_guide_427010(*(const char**)(v61 + 736));
				} else {
					v88[3] = **(_BYTE**)(v61 + 736);
				}
				nox_xxx_netSendPacket0_4E5420(*(unsigned __int8*)(*(_DWORD*)(v85 + 276) + 2064), v88, 4, 0, 1);
			}
			v8 = (int)v89;
			v10 = (int*)v85;
			v4 += 4;
			break;
		case 0xE3u:
			switch (v4[1]) {
			case 1u:
				nox_xxx_playerSetState_4FA020((_DWORD*)v9, 26);
				v4 += 2;
				break;
			case 2u:
				nox_xxx_playerSetState_4FA020((_DWORD*)v9, 25);
				v4 += 2;
				break;
			case 4u:
				nox_xxx_playerSetState_4FA020((_DWORD*)v9, 27);
				v4 += 2;
				break;
			default:
				break;
			}
			break;
		case 0xEEu:
			switch (v4[1]) {
			case 0u:;
				int c1 = 0;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					c1 = 3;
				}
				sub_506870(c1, v9, (wchar_t *) v4 + 1);
				v4 += 52;
				break;
			case 1u:
				sub_506870(1, v9, (wchar_t*)v4 + 1);
				v4 += 52;
				break;
			case 2u:;
				int c2 = 0;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					c2 = 3;
				}
				sub_506C90(c2, v9, (wchar_t *) v4 + 1);
				v4 += 52;
				break;
			case 3u:
				sub_506C90(1, v9, (wchar_t*)v4 + 1);
				v4 += 52;
				break;
			case 4u:
				sub_506870(2, v9, 0);
				v4 += 2;
				break;
			case 5u:
				sub_506C90(2, v9, 0);
				v4 += 2;
				break;
			default:
				return 0;
			}
			// fallthrough
		case 0xC9u:
			switch (v4[1]) {
			case 0xEu:
				if (v10[70])
					sub_50F3A0((_DWORD*)v10[70]);
				v4 += 2;
				break;
			case 0xFu:
				v67 = nox_xxx_packetDynamicUnitCode_578B40(*((unsigned __int16*)v4 + 1));
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
					nox_xxx_netTestHighBit_578B70(*((unsigned __int16*)v4 + 1));
				v68 = (int*)nox_xxx_equipedItemByCode_4F7920(v9, v67);
				if (v68) {
					v69 = *(_DWORD*)(v85 + 280);
					if (v69) {
						if (nox_xxx_tradeP2PAddOffer2_50F820_trade(v69, v9, *(float*)&v68) == 1)
							sub_4ED0C0(v9, v68);
					}
				}
				v10 = (int*)v85;
				v4 += 4;
				break;
			case 0x10u:
				v70 = nox_xxx_packetDynamicUnitCode_578B40(*((unsigned __int16*)v4 + 1));
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG))
					nox_xxx_netTestHighBit_578B70(*((unsigned __int16*)v4 + 1));
				v71 = *(_DWORD*)(v85 + 280);
				if (v71) {
					nox_xxx_tradeP2PAddOfferMB_50FE20(v71, v70);
				}
				v10 = (int*)v85;
				v4 += 4;
				break;
			case 0x11u:
				v66 = v10[70];
				if (v66)
					nox_xxx_tradeAccept_50F5A0(v66, v9);
				v4 += 2;
				break;
			case 0x12u:
				if (v10[70])
					nox_xxx_shopExit_50F4C0((_DWORD*)v10[70]);
				v4 += 2;
				break;
			case 0x15u:
				if (!nox_xxx_gameGet_4DB1B0() && !(*(_BYTE*)(v10[69] + 3680) & 3)) {
					v64 = nox_xxx_packetDynamicUnitCode_578B40(*((unsigned __int16*)v4 + 1));
					v65 = nox_server_getObjectFromNetCode_4ECCB0(v64);
					if (v65) {
						if (*(_BYTE*)(v65 + 12) & 8)
							nox_xxx_servShopStart_50EF10_trade(v9, v65);
					}
				}
				v4 += 4;
				break;
			case 0x16u:
				v72 = (_DWORD*)v10[70];
				if (v72)
					sub_5100C0_trade(v9, v72, *((unsigned __int16*)v4 + 1));
				v4 += 4;
				break;
			case 0x17u:
				v73 = v10[70];
				if (v73)
					sub_510640_trade(v9, v73, *((unsigned __int16*)v4 + 1), (float*)v4[4]);
				v4 += 5;
				break;
			case 0x18u:
				v74 = v10[70];
				if (v74) {
					sub_510BE0_trade((int*)v9, v74, (_DWORD*)*((unsigned __int16*)v4 + 1));
				}
				v4 += 4;
				break;
			case 0x19u:
				v76 = v10[70];
				if (v76) {
					sub_510D10((int*)v9, v76, *((unsigned __int16*)v4 + 1), v4[4]);
				}
				v4 += 5;
				break;
			case 0x1Au:
				v75 = v10[70];
				if (v75) {
					sub_510AE0((int*)v9, v75, (_DWORD*)*((unsigned __int16*)v4 + 1));
				}
				v4 += 4;
				break;
			case 0x1Cu:
				v77 = v10[70];
				if (v77) {
					sub_5109C0_trade((int*)v9, v77, (_DWORD*)*((unsigned __int16*)v4 + 1));
				}
				v4 += 4;
				break;
			case 0x1Eu:
				v78 = v10[70];
				if (v78) {
					sub_5108D0(v9, v78, *((unsigned __int16*)v4 + 1));
				}
				v4 += 4;
				break;
			default:
				return 0;
			}
			break;
		case 0xF0u:
			v79 = v4[1];
			if (v79 == 3) {
				v80 = v10[69];
				v81 = *(_DWORD*)(v80 + 2056);
				if (v81) {
					v7 = *(_DWORD*)(v81 + 16);
					if ((v7 & 0x8000) != 0) {
						v10[137] = 0;
						nox_xxx_playerRespawn_4F7EF0(*(_DWORD*)(v80 + 2056));
					}
				}
			} else {
				if (v79 != 27)
					break;
				sub_4DD0B0(v9);
			}
			v4 += 2;
			break;
		case 0xF1u:
			v63 = (_DWORD*)nox_xxx_equipedItemByCode_4F7920(v9, *(unsigned __int16*)(v4 + 1));
			if (v63) {
				nox_xxx_drop_4ED790(v9, v63, (float2*)(v9 + 56));
				nox_xxx_netPriMsgToPlayer_4DA2C0(v9, "pickup.c:CarryingTooMuch", 0);
			}
			v4 += 3;
			break;
		default:
			return 0;
		}
	}
	*(_DWORD*)(v8 + 3596) = *getMemU32Ptr(0x5D4594, 2598000);
	return 1;
}
// 51C788: variable 'v7' is possibly undefined
