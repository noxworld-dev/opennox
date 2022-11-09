#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "MixPatch.h"
#include "client__gui__guicon.h"
#include "client__gui__window.h"
#include "client__network__cdecode.h"
#include "client__system__ctrlevnt.h"
#include "client__system__parsecmd.h"
#include "common__magic__speltree.h"
#include "common__net_list.h"
#include "common__strman.h"
#include "common__system__team.h"
#include "defs.h"
#include "operators.h"

#include "common/fs/nox_fs.h"
#include "server__network__mapsend.h"
#include "server__network__playback.h"
#include "server__system__trade.h"

extern uint32_t nox_player_netCode_85319C;
//----- (0051BAD0) --------------------------------------------------------
int nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode_switch(int a1, unsigned char* data, int dsz, nox_playerInfo* v8p, nox_object_t* unitp, void* v10p) {
	int v8 = v8p;
	int unit = unitp;
	int* v10 = v10p;
	int v85 = v10;
	int v7;                          // edx
	char* v11 = 0;                       // ecx
	unsigned short v12;              // ax
	int v13;                         // ecx
	int v14;                         // ecx
	int v15;                         // edi
	int v16;                         // eax
	int v17;                         // edi
	int v18;                         // eax
	int v19;                         // edi
	int v20;                         // eax
	unsigned short v21;              // dx
	int v22;                         // edi
	int v23;                         // ebx
	int v24;                         // edi
	int v26;                         // edi
	int v27;                         // eax
	int v28;                         // edi
	int v29;                         // eax
	void (*v30)(int, int, uint32_t); // ecx
	int v31;                         // edi
	int v32;                         // eax
	int v33;                         // edi
	int v34;                         // edi
	int v35;                         // eax
	int* v36;                        // edi
	int v37;                         // ebx
	uint32_t* v38;                   // eax
	int v39;                         // ecx
	int v40;                         // ebx
	int v41;                         // eax
	wchar_t* v42;                    // eax
	wchar_t* v43;                    // eax
	int v44;                         // eax
	int v45;                         // edi
	char* v49;                       // ebp
	int v51;                         // eax
	char* v52;                       // eax
	int v53;                         // edi
	char* v54;                       // eax
	char* v55;                       // edi
	int v56;                         // eax
	int v57;                         // eax
	int v58;                         // edi
	int v59;                         // eax
	int v60;                         // ebx
	int v61;                         // edi
	unsigned char v62;               // al
	uint32_t* v63;                   // eax
	int v64;                         // eax
	int v65;                         // eax
	int v66;                         // eax
	int v67;                         // edi
	int* v68;                        // edi
	int v69;                         // eax
	int v70;                         // edi
	int v71;                         // eax
	uint32_t* v72;                   // eax
	int v73;                         // eax
	int v74;                         // eax
	int v75;                         // eax
	int v76;                         // eax
	int v77;                         // eax
	int v78;                         // eax
	unsigned char v79;               // al
	int v80;                         // eax
	int v81;                         // ecx
	unsigned int v82;                // [esp-8h] [ebp-65Ch]
	float v83;                       // [esp+0h] [ebp-654h]
	float v84;                       // [esp+4h] [ebp-650h]
	char* v86;                       // [esp+1Ch] [ebp-638h]
	char v87[2];                     // [esp+22h] [ebp-632h]
	char v88[4];                     // [esp+24h] [ebp-630h]
	char v90[6];                     // [esp+2Ch] [ebp-628h]
	char v92[5];                     // [esp+38h] [ebp-61Ch]
	float2 v94;                      // [esp+44h] [ebp-610h]
	float2 v96;                      // [esp+4Ch] [ebp-608h]
	wchar_t v97[256];                // [esp+54h] [ebp-600h]
	char FileName[1024];             // [esp+254h] [ebp-400h]

	int op = data[0];
	switch (op) {
	case 0x40u: // MSG_PLAYER_SET_WAYPOINT
		v84 = (double)*(unsigned short*)(data + 5);
		v83 = (double)*(unsigned short*)(data + 3);
		nox_xxx_playerSetCustomWP_4F79A0(unit, SLODWORD(v83), SLODWORD(v84));
		return 7;
	case 0x72u: // MSG_TRY_DROP
		v19 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		v7 = *(uint32_t*)(v85 + 276);
		if (!(*(uint8_t*)(v7 + 3680) & 3) && !*(uint32_t*)(v85 + 280) && !*(uint32_t*)(v85 + 284) &&
			!(*(uint8_t*)(unit + 16) & 2)) {
			v20 = nox_xxx_equipedItemByCode_4F7920(unit, v19);
			if (v20) {
				v21 = *(uint16_t*)(data + 5);
				v94.field_0 = (double)*(unsigned short*)(data + 3);
				v94.field_4 = (double)v21;
				nox_xxx_drop_4ED810(unit, v20, &v94);
			}
		}
		v10 = (int*)v85;
		return 7;
	case 0x73u: // MSG_TRY_GET
		v22 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		if (!nox_xxx_gameGet_4DB1B0()) {
			v7 = *(uint32_t*)(v85 + 276);
			if (!((*(uint8_t*)(v7 + 3680) & 3) || (*(uint32_t*)(v85 + 280)) || (*(uint32_t*)(v85 + 284)) ||
				  (*(uint8_t*)(unit + 16) & 2))) {
				v23 = nox_server_getObjectFromNetCode_4ECCB0(v22);
				if (v23) {
					v24 = 0;
					for (int i = nox_xxx_inventoryGetFirst_4E7980(unit); i;
						 i = nox_xxx_inventoryGetNext_4E7990(i)) {
						v24 += *(unsigned char*)(i + 488);
					}
					if (v24 + *(unsigned char*)(v23 + 488) <= *(unsigned short*)(unit + 490)) {
						// nox_xxx_inventoryServPlace_4F36F0(unit, v23, 1, 1);
						OnLibraryNotice_420(unit, v23, unit, v23);
					} else {
						nox_xxx_netPriMsgToPlayer_4DA2C0(unit, "pickup.c:CarryingTooMuch", 0);
					}
				}
			}
		}
		v10 = (int*)v85;
		return 3;
	case 0x74u: // MSG_TRY_USE
		v26 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		if (!nox_xxx_gameGet_4DB1B0()) {
			v7 = *(uint32_t*)(v85 + 276);
			if (!(*(uint8_t*)(v7 + 3680) & 3)) {
				v27 = nox_xxx_equipedItemByCode_4F7920(unit, v26);
				if (v27) {
					nox_xxx_useByNetCode_53F8E0(unit, v27);
				}
			}
		}
		v10 = (int*)v85;
		return 3;
	case 0x75u: // MSG_TRY_EQUIP
		v15 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		if (!nox_xxx_gameGet_4DB1B0()) {
			v7 = v85;
			if (!(*(uint8_t*)(*(uint32_t*)(v85 + 276) + 3680) & 3)) {
				v16 = nox_xxx_equipedItemByCode_4F7920(unit, v15);
				if (v16) {
					nox_xxx_playerTryEquip_4F2F70((uint32_t*)unit, v16);
				}
			}
		}
		v10 = (int*)v85;
		return 3;
	case 0x76u: // MSG_TRY_DEQUIP
		v17 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		if (!(*(uint8_t*)(*(uint32_t*)(v85 + 276) + 3680) & 3)) {
			v18 = nox_xxx_equipedItemByCode_4F7920(unit, v17);
			if (v18) {
				v7 = v85;
				if (!(*(uint8_t*)(v85 + 88) == 1 && *(uint32_t*)(v18 + 8) & 0x1000000 &&
					  *(uint8_t*)(v18 + 12) & 8)) {
					nox_xxx_playerTryDequip_4F2FB0((uint32_t*)unit, (const nox_object_t*)v18);
				}
			}
		}
		v10 = (int*)v85;
		return 3;
	case 0x78: // MSG_TRY_CREATURE_COMMAND
		v31 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		v7 = v85;
		if (!(*(uint8_t*)(*(uint32_t*)(v85 + 276) + 3680) & 1)) {
			if (*(uint16_t*)(data + 1)) {
				v32 = nox_server_getObjectFromNetCode_4ECCB0(v31);
				if (v32) {
					nox_xxx_orderUnit_533900(unit, v32, data[3]);
				}
			} else {
				nox_xxx_orderUnit_533900(unit, 0, data[3]);
			}
		}
		v10 = (int*)v85;
		return 4;
	case 0x79u: // MSG_TRY_SPELL
		v34 = 1;
		if (*(uint8_t*)(*(uint32_t*)(v85 + 276) + 3680) & 1) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(unit, "GeneralPrint:NoSpellWarningGeneral", 0);
			v34 = 0;
		}
		if (*(uint8_t*)(*(uint32_t*)(v85 + 276) + 3680) & 2) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(unit, "GeneralPrint:ConjureNoSpellWarning1", 0);
			v34 = 0;
		}
		if (!nox_common_gameFlags_check_40A5C0(2048)) {
			v35 = *(uint32_t*)(unit + 16);
			if (v35 & 0x4000) {
				v34 = 0;
			}
		}
		if (!nox_common_gameFlags_check_40A5C0(128) && v34) {
			v36 = (int*)(data + 1);
			v37 = 0;
			v38 = data + 1;
			v39 = 5;
			while (v39) {
				if (*v38) {
					++v37;
				}
				++v38;
				--v39;
			}
			if ((v37 != 1 || !nox_xxx_spellHasFlags_424A50(*v36, 32) || !*(uint32_t*)(v85 + 288) ||
				 nox_xxx_unitIsEnemyTo_5330C0(unit, *(uint32_t*)(v85 + 288)) ||
				 nox_common_gameFlags_check_40A5C0(4096)) &&
				!nox_xxx_spellByBookInsert_4FE340(unit, (int*)(data + 1), v37, 3, data[21]) && v37 == 1) {
				v40 = 5;
				while (v40) {
					if (*v36) {
						nox_xxx_netReportSpellStat_4D9630(*(unsigned char*)(*(uint32_t*)(v85 + 276) + 2064), *v36,
														  0);
					}
					++v36;
					--v40;
				}
			}
		}
		v10 = (int*)v85;
		return 22;
	case 0x7Bu: // MSG_TRY_COLLIDE
		v28 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		v7 = v85;
		if (!(*(uint8_t*)(*(uint32_t*)(v85 + 276) + 3680) & 3) && !*(uint32_t*)(v85 + 280) &&
			!*(uint32_t*)(v85 + 284)) {
			v29 = nox_server_getObjectFromNetCode_4ECCB0(v28);
			if (v29) {
				v30 = *(void (**)(int, int, uint32_t))(v29 + 696);
				if (v30) {
					v30(v29, unit, 0);
				}
			}
		}
		v10 = (int*)v85;
		return 3;
	case 0xA5u: // MSG_NEW_ALIAS
		*(uint16_t*)(v8 + 8 * data[1] + 16) = *((uint16_t*)data + 1);
		*(uint16_t*)(v8 + 8 * data[1] + 18) = *((uint16_t*)data + 2);
		v14 = data[1];
		v7 = *(uint32_t*)(data + 6);
		*(uint32_t*)(v8 + 8 * v14 + 20) = v7;
		return 10;
	case 0xA8u: // MSG_TEXT_MESSAGE
		if (data[3] & 2) {
			nox_swprintf(v97, L"%S", data + 11);
			v44 = 1;
		} else {
			nox_wcscpy(v97, (const wchar_t*)(data + 11));
			v44 = 2;
		}
		v45 = v44 * data[8] + 11;
		if (!nox_xxx_giant_57A190(v8)) {
			if (!(data[3] & 1)) {
				for (char* j = nox_common_playerInfoGetFirst_416EA0(); j;
					 j = nox_common_playerInfoGetNext_416EE0((int)j)) {
					if (nox_common_gameFlags_check_40A5C0(2) && j[2064] == 31) {
						nox_xxx_netOnPacketRecvCli_48EA70(31, (unsigned int)data, v45);
					} else {
						nox_xxx_netSendSock_552640((unsigned char)j[2064] + 1, data, v45, 0);
						nox_xxx_netSendReadPacket_5528B0((unsigned char)j[2064] + 1, 1);
					}
				}
			} else {
				uint32_t* v47 = nox_xxx_objGetTeamByNetCode_418C80(*(unsigned short*)(data + 1));
				if (v47) {
					if (nox_xxx_servObjectHasTeam_419130((int)v47)) {
						v86 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v47 + 4));
						if (v86) {
							for (int j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j;
								 j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
								v49 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(j + 36));
								if (v49 && nox_xxx_teamCompare2_419180(j + 48, v86[57])) {
									if (nox_common_gameFlags_check_40A5C0(2) &&
										*(uint32_t*)(j + 36) == nox_player_netCode_85319C) {
										nox_xxx_netOnPacketRecvCli_48EA70((unsigned char)v49[2064],
																		  (unsigned int)data, v45);
									} else {
										nox_xxx_netSendSock_552640((unsigned char)v49[2064] + 1, data, v45, 0);
										nox_xxx_netSendReadPacket_5528B0((unsigned char)v49[2064] + 1, 1);
									}
								}
							}
						}
					}
				}
			}
		}
		return v45;
	case 0xB6u: // MSG_REQUEST_MAP
		nox_xxx_playerGoObserver_4E6860(v8, 1, 1);
		v51 = *(uint32_t*)(v8 + 2056);
		if (v51) {
			nox_xxx_netChangeTeamMb_419570(v51 + 48, *(uint32_t*)(v8 + 2060));
		}
		nox_xxx_netMapSend_519D20(*(unsigned char*)(v8 + 2064));
		return 1;
	case 0xBCu: // MSG_SYSOP_PW
		v87[0] = 0xBDu; // MSG_SYSOP_RESULT
		v42 = nox_xxx_sysopGetPass_40A630();
		if (!*v42 || _nox_wcsicmp((const wchar_t*)(data + 1), v42)) {
			v87[1] = 0;
		} else {
			v87[1] = 1;
			if (!sub_4D12A0(*(unsigned char*)(v8 + 2064))) {
				sub_4D1210(*(unsigned char*)(v8 + 2064));
				v43 = nox_strman_loadString_40F1D0("sysopAccessGranted", 0,
												   "C:\\NoxPost\\src\\Server\\Network\\sdecode.c", 735);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v43, v8 + 4704);
			}
		}
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(v8 + 2064), v87, 2, 0, 1);
		return 21;
	case 0xC1u: // MSG_REQUEST_SAVE_PLAYER
		if (nox_common_gameFlags_check_40A5C0(4096) && *(uint8_t*)(v8 + 2064) != 31 && *(uint32_t*)(v8 + 2092) &&
			*(uint32_t*)(v8 + 2056) && v10[138] == 1) {
			nox_xxx_playerCallDisconnect_4DEAB0(*(unsigned char*)(v8 + 2064), 2);
		} else {
			v52 = nox_fs_root();
			nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v52);
			if (nox_xxx_playerSaveToFile_41A140(FileName, *(unsigned char*)(v8 + 2064))) {
				sub_41CFA0(FileName, *(unsigned char*)(v8 + 2064));
			}
			nox_fs_remove(FileName);
		}
		return 3;
	case 0xC2u: // MSG_XFER_MSG
		switch (data[1]) {
		case 0u:
			sub_40B5D0(*(unsigned char*)(v8 + 2064) + 1, data[2], (const char*)data + 8, *((uint32_t*)data + 1),
					   data[136]);
			return 140;
		case 1u:
			LOBYTE(v11) = data[3];
			sub_40BFF0(*(unsigned char*)(v8 + 2064) + 1, data[2], v11);
			return 4;
		case 2u:
			v90[0] = -62;
			v90[1] = 3;
			v90[2] = data[2];
			v82 = *(unsigned char*)(v8 + 2064) + 1;
			*(uint16_t*)&v90[4] = *((uint16_t*)data + 2);
			nox_xxx_netSendSock_552640(v82, v90, 6, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
			sub_40B250(*(unsigned char*)(v8 + 2064) + 1, data[2], *((uint16_t*)data + 2), data + 8,
					   *((unsigned short*)data + 3));
			return *((unsigned short*)data + 3) + 8;
		case 3u:
			sub_40BF60(*(unsigned char*)(v8 + 2064) + 1, data[2], *((unsigned short*)data + 2));
			return 6;
		case 4u:
			sub_40C030(*(unsigned char*)(v8 + 2064) + 1, data[2]);
			return 3;
		case 5u:
			LOBYTE(v7) = data[3];
			sub_40B720(v7, data[2]);
			return 4;
		case 6u:
			LOBYTE(v11) = data[3];
			sub_40C070(*(unsigned char*)(v8 + 2064) + 1, (int)v11, data[2]);
			return 4;
		default:
			return -1;
		}
	case 0xC4u: // MSG_TEAM_MSG
		if (data[1] == 10) {
			v55 = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
			if (v55) {
				v56 = nox_server_getObjectFromNetCode_4ECCB0(*((unsigned short*)data + 3));
				nox_xxx_createAtImpl_4191D0(v55[57], v56 + 48, 1, *((unsigned short*)data + 3), 1);
			}
			v10 = (int*)v85;
			return 10;
		} else if (data[1] == 11) {
			v53 = nox_server_getObjectFromNetCode_4ECCB0(*((unsigned short*)data + 3));
			if (v53) {
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_mapFindPlayerStart_4F7AB0(&v96, v53);
					nox_xxx_unitMove_4E7010(v53, &v96);
				}
				v54 = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
				if (v54) {
					sub_4196D0(v53 + 48, (int)v54, *((unsigned short*)data + 3), 1);
				}
			}
			v10 = (int*)v85;
			return 10;
		} else {
			return -1;
		}
	case 0xD0u: // MSG_DIALOG
		if (data[1] == 1) {
			if (nox_xxx_gameGet_4DB1B0() || (v7 = v10[69], *(uint8_t*)(v7 + 3680) & 3) ||
				(v57 = nox_server_getObjectFromNetCode_4ECCB0(*((unsigned short*)data + 1))) == 0) {
			} else {
				nox_xxx_script_forcedialog_548CD0(unit, v57);
			}
			return 4;
		} else if (data[1] == 2) {
			nox_xxx_scriptDialog_548D30(unit, data[2]);
			return 3;
		} else {
			return -1;
		}
	case 0xD4u: // MSG_REQUEST_TIMER_STATUS
		v41 = sub_40A220();
		nox_xxx_netTimerStatus_4D8F50(a1, v41);
		return 1;
	case 0xE0u: // MSG_REPORT_SECONDARY_WEAPON
		v58 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		if (*(uint16_t*)(data + 1)) {
			v59 = nox_server_getObjectFromNetCode_4ECCB0(v58);
			sub_53AB90(unit, v59);
		} else {
			sub_53AB90(unit, 0);
		}
		v10 = (int*)v85;
		return 3;
	case 0xE2u: // MSG_INFO_BOOK_DATA
		v60 = nox_xxx_packetDynamicUnitCode_578B40(*(unsigned short*)(data + 1));
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
			nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
		}
		v61 = nox_xxx_equipedItemByCode_4F7920(unit, v60);
		if (v61 || (v61 = sub_510DE0(unit, v60)) != 0 || (v61 = nox_server_getObjectFromNetCode_4ECCB0(v60)) != 0) {
			v88[0] = -30;
			*(uint16_t*)&v88[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)v61);
			v62 = data[3];
			if (v62 == 1) {
				v88[3] = **(uint8_t**)(v61 + 736);
			} else if (v62 == 2) {
				v88[3] = nox_xxx_guide_427010(*(const char**)(v61 + 736));
			} else {
				v88[3] = **(uint8_t**)(v61 + 736);
			}
			nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v85 + 276) + 2064), v88, 4, 0, 1);
		}
		v10 = (int*)v85;
		return 4;
	case 0xE3u: // MSG_SOCIAL
		switch (data[1]) {
		case 1u:
			nox_xxx_playerSetState_4FA020((uint32_t*)unit, 26);
			break;
		case 2u:
			nox_xxx_playerSetState_4FA020((uint32_t*)unit, 25);
			break;
		case 4u:
			nox_xxx_playerSetState_4FA020((uint32_t*)unit, 27);
			break;
		default:
			break;
		}
		return 2;
	case 0xEEu: // MSG_VOTE
		switch (data[1]) {
		case 0u:;
			int c1 = 0;
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				c1 = 3;
			}
			sub_506870(c1, unit, (wchar_t*)data + 1);
			return 52;
		case 1u:
			sub_506870(1, unit, (wchar_t*)data + 1);
			return 52;
		case 2u:;
			int c2 = 0;
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				c2 = 3;
			}
			sub_506C90(c2, unit, (wchar_t*)data + 1);
			return 52;
		case 3u:
			sub_506C90(1, unit, (wchar_t*)data + 1);
			return 52;
		case 4u:
			sub_506870(2, unit, 0);
			return 2;
		case 5u:
			sub_506C90(2, unit, 0);
			return 2;
		default:
			return -1;
		}
	case 0xC9u: // MSG_TRADE
		switch (data[1]) {
		case 0xEu:
			if (v10[70]) {
				sub_50F3A0((uint32_t*)v10[70]);
			}
			return 2;
		case 0xFu:
			v67 = nox_xxx_packetDynamicUnitCode_578B40(*((unsigned short*)data + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*((unsigned short*)data + 1));
			}
			v68 = (int*)nox_xxx_equipedItemByCode_4F7920(unit, v67);
			if (v68) {
				v69 = *(uint32_t*)(v85 + 280);
				if (v69) {
					if (nox_xxx_tradeP2PAddOffer2_50F820_trade(v69, unit, *(float*)&v68) == 1) {
						sub_4ED0C0(unit, v68);
					}
				}
			}
			v10 = (int*)v85;
			return 4;
		case 0x10u:
			v70 = nox_xxx_packetDynamicUnitCode_578B40(*((unsigned short*)data + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*((unsigned short*)data + 1));
			}
			v71 = *(uint32_t*)(v85 + 280);
			if (v71) {
				nox_xxx_tradeP2PAddOfferMB_50FE20(v71, v70);
			}
			v10 = (int*)v85;
			return 4;
		case 0x11u:
			v66 = v10[70];
			if (v66) {
				nox_xxx_tradeAccept_50F5A0(v66, unit);
			}
			return 2;
		case 0x12u:
			if (v10[70]) {
				nox_xxx_shopExit_50F4C0((uint32_t*)v10[70]);
			}
			return 2;
		case 0x15u:
			if (!nox_xxx_gameGet_4DB1B0() && !(*(uint8_t*)(v10[69] + 3680) & 3)) {
				v64 = nox_xxx_packetDynamicUnitCode_578B40(*((unsigned short*)data + 1));
				v65 = nox_server_getObjectFromNetCode_4ECCB0(v64);
				if (v65) {
					if (*(uint8_t*)(v65 + 12) & 8) {
						nox_xxx_servShopStart_50EF10_trade(unit, v65);
					}
				}
			}
			return 4;
		case 0x16u:
			v72 = (uint32_t*)v10[70];
			if (v72) {
				sub_5100C0_trade(unit, v72, *((unsigned short*)data + 1));
			}
			return 4;
		case 0x17u:
			v73 = v10[70];
			if (v73) {
				sub_510640_trade(unit, v73, *((unsigned short*)data + 1), (float*)data[4]);
			}
			return 5;
		case 0x18u:
			v74 = v10[70];
			if (v74) {
				sub_510BE0_trade((int*)unit, v74, (uint32_t*)*((unsigned short*)data + 1));
			}
			return 4;
		case 0x19u:
			v76 = v10[70];
			if (v76) {
				sub_510D10((int*)unit, v76, *((unsigned short*)data + 1), data[4]);
			}
			return 5;
		case 0x1Au:
			v75 = v10[70];
			if (v75) {
				sub_510AE0((int*)unit, v75, (uint32_t*)*((unsigned short*)data + 1));
			}
			return 4;
		case 0x1Cu:
			v77 = v10[70];
			if (v77) {
				sub_5109C0_trade((int*)unit, v77, (uint32_t*)*((unsigned short*)data + 1));
			}
			return 4;
		case 0x1Eu:
			v78 = v10[70];
			if (v78) {
				sub_5108D0(unit, v78, *((unsigned short*)data + 1));
			}
			return 4;
		default:
			return -1;
		}
	case 0xF0u: // MSG_GAUNTLET
		v79 = data[1];
		if (v79 == 3) {
			v80 = v10[69];
			v81 = *(uint32_t*)(v80 + 2056);
			if (v81) {
				v7 = *(uint32_t*)(v81 + 16);
				if ((v7 & 0x8000) != 0) {
					v10[137] = 0;
					nox_xxx_playerRespawn_4F7EF0(*(uint32_t*)(v80 + 2056));
				}
			}
		} else {
			if (v79 != 27) {
				return -1;
			}
			sub_4DD0B0(unit);
		}
		return 2;
	case 0xF1u: // MSG_INVENTORY_FAIL
		v63 = (uint32_t*)nox_xxx_equipedItemByCode_4F7920(unit, *(unsigned short*)(data + 1));
		if (v63) {
			nox_xxx_drop_4ED790(unit, v63, (float2*)(unit + 56));
			nox_xxx_netPriMsgToPlayer_4DA2C0(unit, "pickup.c:CarryingTooMuch", 0);
		}
		return 3;
	default:
		return -1;
	}
}
