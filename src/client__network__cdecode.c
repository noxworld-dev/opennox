#include <math.h>

#include "client__network__cdecode.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "MixPatch.h"
#include "client__draw__fx.h"
#include "client__gui__guiinv.h"
#include "client__gui__guishop.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "common__magic__speltree.h"
#include "common__net_list.h"
#include "common__random.h"
#include "common__strman.h"
#include "common__system__team.h"
#include "defs.h"
#include "operators.h"

#include "client__draw__animdraw.h"
#include "client__draw__drawrays.h"
#include "client__draw__fx.h"
#include "client__gui__chathelp.h"
#include "client__gui__gui_ctf.h"
#include "client__gui__guibrief.h"
#include "client__gui__guicon.h"
#include "client__gui__guidlg.h"
#include "client__gui__guigen.h"
#include "client__gui__guiggovr.h"
#include "client__gui__guiinv.h"
#include "client__gui__guijourn.h"
#include "client__gui__guimsg.h"
#include "client__gui__guishop.h"
#include "client__gui__guitrade.h"
#include "client__gui__servopts__playrlst.h"
#include "client__network__inform.h"
#include "client__shell__noxworld.h"
extern uint32_t dword_5d4594_1200832;
extern uint32_t dword_5d4594_1200776;
extern uint32_t dword_5d4594_1200796;
extern uint32_t dword_5d4594_1200768;
extern uint32_t nox_server_sanctuaryHelp_54276;
extern uint32_t nox_client_gui_flag_1556112;
extern uint32_t nox_xxx_xxxRenderGUI_587000_80832;
extern uint32_t dword_5d4594_1200804;
extern uint32_t nox_gameDisableMapDraw_5d4594_2650672;
extern uint32_t nox_client_renderGUI_80828;
extern uint32_t dword_5d4594_2650652;
extern uint32_t nox_player_netCode_85319C;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;

void noxOnCliPacketDebug(int op, unsigned char* data, int sz);
int nox_client_getFadeDuration();

void nox_client_onMapDownloadStart(char* a1, unsigned int a2);
void nox_client_onMapDownloadPart(unsigned short a1, void* a2, size_t a3);
void nox_client_onMapDownloadAbort();

void clientPacketFade(bool a1, int fnc);
void nox_client_onDeathRay(int p1x, int p1y, int p2x, int p2y);
void nox_client_onParticleFx(int code, nox_drawable* a1, int a2, int a3, int a4);
void nox_client_onClassStats(unsigned char* data, int sz);
void nox_client_onJoinData();
void sub_456140(unsigned char a1);

uint32_t nox_client_fadeObjects_80836 = 1;
uint32_t nox_perfmon_latePackets_2618900 = 0;

//----- (0048EA70) --------------------------------------------------------
void sub_470A80();
int nox_xxx_netOnPacketRecvCli_48EA70(int a1, unsigned char* data, int sz) {
	long long v5;           // rax
	int k;                  // ecx
	int v9;                 // edi
	int v10;                // ebx
	unsigned short v11;     // ax
	unsigned int v12;       // esi
	int v13;                // eax
	int v14;                // esi
	unsigned char* v15;     // ebp
	int v16;                // eax
	int v17;                // esi
	int v18;                // eax
	int v19;                // esi
	int v20;                // eax
	int v21;                // esi
	int v22;                // esi
	int v24;                // eax
	int v25;                // esi
	int v26;                // esi
	uint32_t* v27;          // esi
	unsigned char v28;      // al
	int v29;                // esi
	unsigned char v30;      // bl
	unsigned int v31;       // eax
	int v32;                // ecx
	int v33;                // eax
	unsigned int v34;       // esi
	char* v35;              // ebx
	char* j;                // esi
	char* v37;              // ebx
	wchar_t* v38;           // eax
	char* v39;              // eax
	unsigned int v40;       // edx
	wchar_t* v41;           // eax
	int v42;                // eax
	char* v43;              // eax
	int v44;                // eax
	int v45;                // esi
	int v46;                // esi
	int v47;                // eax
	unsigned int v48;       // eax
	int v49;                // eax
	int v50;                // esi
	int v51;                // esi
	int v52;                // eax
	unsigned int v53;       // eax
	int v54;                // eax
	int v55;                // esi
	int v56;                // eax
	int v57;                // eax
	int v58;                // esi
	int v59;                // eax
	int v60;                // esi
	int v62;                // eax
	int v63;                // esi
	int v64;                // eax
	int v65;                // esi
	char v66;               // cl
	int v67;                // eax
	int v68;                // eax
	int v69;                // eax
	int v70;                // esi
	int v71;                // eax
	int v72;                // esi
	uint32_t* v73;          // esi
	int v74;                // eax
	int v75;                // eax
	unsigned int v76;       // eax
	int v77;                // eax
	int v78;                // esi
	int v79;                // edi
	int v80;                // esi
	int* v81;               // ebx
	int v82;                // eax
	int v83;                // esi
	int v84;                // eax
	int v85;                // esi
	int v86;                // esi
	char v87;               // al
	int v88;                // eax
	int v89;                // esi
	int v90;                // eax
	int v91;                // esi
	int v92;                // eax
	int v93;                // esi
	int v94;                // eax
	int v95;                // esi
	int v96;                // eax
	int v97;                // esi
	int v98;                // eax
	int v99;                // esi
	int v100;               // ebx
	int v101;               // eax
	int v102;               // esi
	int v103;               // eax
	int v104;               // esi
	int v105;               // eax
	int v106;               // edi
	int v107;               // esi
	char* v108;             // ebx
	int v109;               // eax
	int v110;               // esi
	uint32_t* v111;         // esi
	uint32_t* v112;         // eax
	int v113;               // ecx
	uint32_t* v114;         // ebx
	int v115;               // eax
	int v116;               // edx
	unsigned int v117;      // ecx
	unsigned short v118;    // ax
	char* v119;             // esi
	int v120;               // eax
	int v121;               // esi
	int v122;               // eax
	int v123;               // esi
	int v124;               // eax
	int v125;               // esi
	char* v126;             // ebx
	char* v127;             // esi
	wchar_t* v128;          // eax
	unsigned int v129;      // eax
	int v130;               // esi
	int v132;               // eax
	int v133;               // esi
	int v134;               // esi
	int v135;               // ebx
	int v137;               // eax
	int v138;               // esi
	int v139;               // esi
	int v140;               // eax
	int v141;               // esi
	char* v142;             // esi
	wchar_t* v143;          // eax
	char* v144;             // esi
	uint32_t* v145;         // eax
	wchar_t* v146;          // eax
	int v147;               // eax
	wchar_t* v148;          // eax
	wchar_t* v149;          // eax
	int v150;               // esi
	wchar_t* v151;          // eax
	int v152;               // eax
	int v153;               // edi
	char* v154;             // ebx
	wchar_t* v155;          // eax
	wchar_t* v156;          // eax
	wchar_t* v157;          // eax
	wchar_t* v158;          // eax
	wchar_t* v159;          // eax
	char* v160;             // ebx
	wchar_t* v161;          // eax
	uint32_t* v162;         // esi
	wchar_t* v163;          // eax
	int v164;               // esi
	wchar_t* v165;          // eax
	wchar_t* v166;          // eax
	wchar_t* v167;          // eax
	wchar_t* v168;          // eax
	wchar_t* v169;          // eax
	wchar_t* v170;          // eax
	wchar_t* v171;          // eax
	char* v172;             // ebx
	wchar_t* v173;          // eax
	uint32_t* v174;         // esi
	wchar_t* v175;          // eax
	int v176;               // esi
	wchar_t* v177;          // eax
	int v178;               // eax
	int v179;               // esi
	int v180;               // eax
	int v181;               // esi
	int v182;               // eax
	int v183;               // esi
	unsigned int v184;      // eax
	unsigned int v185;      // esi
	unsigned short v186;    // ax
	unsigned short v187;    // cx
	uint32_t* v188;         // eax
	int v189;               // eax
	int v190;               // esi
	unsigned short v191;    // ax
	unsigned short v192;    // cx
	unsigned int v193;      // eax
	unsigned int v194;      // esi
	uint32_t* v195;         // eax
	int v196;               // eax
	int v197;               // esi
	int v198;               // eax
	int v199;               // ebx
	int v200;               // eax
	wchar_t* v201;          // eax
	int v202;               // edi
	wchar_t* v203;          // eax
	wchar_t* v204;          // eax
	wchar_t* v205;          // eax
	char* v206;             // eax
	char* v207;             // esi
	int v208;               // eax
	wchar_t* v213;            // eax
	int v214;                 // eax
	int v215;                 // esi
	char* v216;               // ebx
	wchar_t* v217;            // eax
	uint32_t* v218;             // eax
	int v219;                 // edi
	wchar_t* v220;            // eax
	unsigned int v221;        // eax
	int v222;                 // eax
	int v223;                 // esi
	int v224;                 // eax
	int v225;                 // eax
	int v226;                 // eax
	int v227;                 // esi
	int v228;                 // ebx
	int v229;                 // ecx
	int v230;                 // edi
	int v231;                 // ebx
	uint32_t* v232;             // esi
	char v233;                // al
	int v234;                 // esi
	int v235;                 // eax
	int v236;                 // eax
	int v237;                 // esi
	int v239;                 // ebx
	int v240;                 // edi
	int v241;                 // esi
	int v242;                 // edi
	int v243;                 // edi
	int v244;                 // ebx
	int v245;                 // eax
	uint32_t* v246;             // esi
	char v247;                // al
	short v248;             // ax
	int v249;               // esi
	bool v250;              // zf
	int v251;               // ecx
	unsigned int v252;      // ebx
	int v253;               // edi
	int v254;               // esi
	int v255;               // eax
	int v256;               // esi
	int v257;               // eax
	int v258;               // ecx
	int v259;               // eax
	int v260;               // edi
	int v261;               // eax
	int v262;               // esi
	int v263;               // eax
	int v264;               // eax
	int v265;               // eax
	int v266;               // eax
	int v267;               // eax
	int v268;               // eax
	int v269;               // eax
	int v270;               // eax
	wchar_t* v271;          // eax
	char* v272;             // esi
	uint32_t* v273;         // edi
	unsigned int v274;      // eax
	unsigned int v275;      // esi
	int v276;               // ebx
	int v277;               // esi
	uint32_t* v278;         // ebx
	int v279;               // esi
	wchar_t* v280;          // esi
	unsigned int v281;      // eax
	unsigned int v282;      // esi
	int v283;               // eax
	int v284;               // eax
	unsigned short v285;    // ax
	unsigned short v286;    // bx
	int v287;               // ebx
	char* v288;             // edi
	uint8_t* v289;          // esi
	wchar_t* v290;          // eax
	int v291;               // eax
	int v292;               // esi
	int v293;               // eax
	int v294;               // eax
	int v295;               // esi
	int v296;               // esi
	int v297;               // eax
	int v298;               // esi
	char* v299;             // esi
	char* v300;             // eax
	int v301;               // eax
	uint32_t* v302;         // eax
	char* v303;             // esi
	wchar_t* v304;          // eax
	wchar_t* v305;          // eax
	char* v306;             // esi
	wchar_t* v307;          // eax
	wchar_t* v308;          // eax
	char* v309;             // esi
	wchar_t* v310;          // eax
	wchar_t* v311;          // eax
	wchar_t* v312;          // eax
	wchar_t* v314;          // [esp-Ch] [ebp-175Ch]
	char v315;              // [esp-8h] [ebp-1758h]
	unsigned char v316;     // [esp-8h] [ebp-1758h]
	int v317;               // [esp-4h] [ebp-1754h]
	int v318;               // [esp-4h] [ebp-1754h]
	unsigned short v319;    // [esp-4h] [ebp-1754h]
	int v320;               // [esp+0h] [ebp-1750h]
	int v321;               // [esp+0h] [ebp-1750h]
	int v322;               // [esp+0h] [ebp-1750h]
	char v323;              // [esp+0h] [ebp-1750h]
	size_t v324;            // [esp+0h] [ebp-1750h]
	char v325;              // [esp+0h] [ebp-1750h]
	char v326;              // [esp+0h] [ebp-1750h]
	int v327;               // [esp+0h] [ebp-1750h]
	float v328;             // [esp+4h] [ebp-174Ch]
	int v329;               // [esp+4h] [ebp-174Ch]
	int v330;               // [esp+4h] [ebp-174Ch]
	int v331;               // [esp+4h] [ebp-174Ch]
	float v332;             // [esp+4h] [ebp-174Ch]
	int v333;               // [esp+4h] [ebp-174Ch]
	wchar_t* v334;          // [esp+4h] [ebp-174Ch]
	wchar_t* v335;          // [esp+4h] [ebp-174Ch]
	wchar_t* v336;          // [esp+4h] [ebp-174Ch]
	int v337;               // [esp+4h] [ebp-174Ch]
	int v338;               // [esp+4h] [ebp-174Ch]
	int v339;               // [esp+4h] [ebp-174Ch]
	float v340;             // [esp+4h] [ebp-174Ch]
	int v341;               // [esp+4h] [ebp-174Ch]
	char v342;              // [esp+4h] [ebp-174Ch]
	char* v343;             // [esp+4h] [ebp-174Ch]
	size_t v344;            // [esp+4h] [ebp-174Ch]
	int v345;               // [esp+4h] [ebp-174Ch]
	char v346;              // [esp+4h] [ebp-174Ch]
	char v347;              // [esp+4h] [ebp-174Ch]
	int v348;               // [esp+4h] [ebp-174Ch]
	int v349;               // [esp+4h] [ebp-174Ch]
	int v350;               // [esp+4h] [ebp-174Ch]
	int v351;               // [esp+4h] [ebp-174Ch]
	int v352;               // [esp+4h] [ebp-174Ch]
	int v353;               // [esp+4h] [ebp-174Ch]
	wchar_t* v354;          // [esp+4h] [ebp-174Ch]
	int v355;               // [esp+18h] [ebp-1738h]
	unsigned int v356;      // [esp+18h] [ebp-1738h]
	int v357;               // [esp+18h] [ebp-1738h]
	int* v358;              // [esp+18h] [ebp-1738h]
	char v359;              // [esp+1Fh] [ebp-1731h]
	int v360;               // [esp+20h] [ebp-1730h]
	int i;                  // [esp+24h] [ebp-172Ch]
	int v362;               // [esp+28h] [ebp-1728h]
	int v363;               // [esp+2Ch] [ebp-1724h]
	unsigned int v364;      // [esp+30h] [ebp-1720h]
	char v365[6];           // [esp+34h] [ebp-171Ch]
	int v367;               // [esp+44h] [ebp-170Ch]
	int v368;               // [esp+48h] [ebp-1708h]
	int v370;               // [esp+50h] [ebp-1700h]
	int v371;               // [esp+54h] [ebp-16FCh]
	int v372 = 0;           // [esp+58h] [ebp-16F8h]
	unsigned int v373 = 0;  // [esp+5Ch] [ebp-16F4h]
	int v374;               // [esp+60h] [ebp-16F0h]
	int v376;               // [esp+68h] [ebp-16E8h]
	int2 v377;              // [esp+6Ch] [ebp-16E4h]
	int2 v378;              // [esp+74h] [ebp-16DCh]
	int2 v379;              // [esp+7Ch] [ebp-16D4h]
	int2 v380;              // [esp+84h] [ebp-16CCh]
	unsigned char v381[20]; // [esp+8Ch] [ebp-16C4h]
	int v382[8];            // [esp+A0h] [ebp-16B0h]
	int v383[5];            // [esp+C0h] [ebp-1690h]
	int v384[2];            // [esp+D4h] [ebp-167Ch]
	char v385[20];          // [esp+DCh] [ebp-1674h]
	wchar_t v386[20];       // [esp+F0h] [ebp-1660h]
	wchar_t v387[20];       // [esp+118h] [ebp-1638h]
	wchar_t v388[64];       // [esp+140h] [ebp-1610h]
	wchar_t v389[128];      // [esp+1C0h] [ebp-1590h]
	wchar_t v390[128];      // [esp+2C0h] [ebp-1490h]
	wchar_t v391[128];      // [esp+3C0h] [ebp-1390h]
	wchar_t v392[128];      // [esp+4C0h] [ebp-1290h]
	wchar_t v393[128];      // [esp+5C0h] [ebp-1190h]
	wchar_t v394[128];      // [esp+6C0h] [ebp-1090h]
	wchar_t v395[64];       // [esp+7C0h] [ebp-F90h]
	wchar_t v396[64];       // [esp+840h] [ebp-F10h]
	wchar_t v397[100];      // [esp+8C0h] [ebp-E90h]
	wchar_t v398[128];      // [esp+988h] [ebp-DC8h]
	wchar_t v400[256];        // [esp+B50h] [ebp-C00h]
	wchar_t v401[128];        // [esp+D50h] [ebp-A00h]
	wchar_t v402[128];        // [esp+E50h] [ebp-900h]
	wchar_t v403[256];        // [esp+F50h] [ebp-800h]
	wchar_t v404[256];        // [esp+1150h] [ebp-600h]
	wchar_t v405[256];        // [esp+1350h] [ebp-400h]
	wchar_t v406[256];        // [esp+1550h] [ebp-200h]

	unsigned char* end = data + sz;
	v364 = 0;
	sub_470A80();
	if (data >= data + sz) {
		return 1;
	}
	while (data < end) {
		unsigned char* old = data;
		int op = data[0];
		switch (op) {
		case 33: // MSG_XXX_STOP
			break;
		case 39: // MSG_TIMESTAMP
		case 40: // MSG_FULL_TIMESTAMP
		case 42: // MSG_SIMULATED_TIMESTAMP
			v9 = 1;
			if (op == 40) {
				nox_frame_xxx_2598000 = *(uint32_t*)(data + 1);
				*getMemU32Ptr(0x5D4594, 1200800) = nox_frame_xxx_2598000;
				v364 = nox_frame_xxx_2598000;
				*getMemU32Ptr(0x5D4594, 1200808) = (unsigned short)nox_frame_xxx_2598000 >> 14;
				if (*getMemU32Ptr(0x8531A0, 2576)) {
					nox_xxx_playerUnsetStatus_417530(*getMemIntPtr(0x8531A0, 2576), 64);
				}
				sub_43C650();
				data += 5;
				break;
			} else if (op != 39) {
				v14 = *(unsigned short*)(v373 + 1);
				if ((unsigned short)v14 < (unsigned int)(*getMemU32Ptr(0x5D4594, 1200800) + sub_43C790())) {
					nox_frame_xxx_2598000 = v14;
				}
				data += 5;
				break;
			}
			v373 = data;
			if (*getMemU32Ptr(0x8531A0, 2576) && *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 0x40) {
				return 1;
			}
			v10 = nox_frame_xxx_2598000;
			v11 = *(uint16_t*)(data + 1);
			v12 = v11 + (nox_frame_xxx_2598000 & 0xFFFF0000);
			v13 = v11 >> 14;
			if (v13 != *getMemU32Ptr(0x5D4594, 1200808)) {
				if (v13 == ((getMemByte(0x5D4594, 1200808) + 1) & 3)) {
					*getMemU32Ptr(0x5D4594, 1200808) = v13;
					if (!v13) {
						v12 += 0x10000;
					}
				} else {
					v9 = 0;
				}
			}
			if (v12 < nox_frame_xxx_2598000) {
				v9 = 0;
			}
			if (!nox_common_gameFlags_check_40A5C0(1) && v9 == 1) {
				nox_frame_xxx_2598000 = v12;
				*getMemU32Ptr(0x5D4594, 1200800) = v12;
			}
			v364 = v12;
			if (!nox_common_gameFlags_check_40A5C0(1) && !v9) {
				--nox_perfmon_latePackets_2618900;
				++*getMemU32Ptr(0x85B3FC, 120);
				return 1;
			}
			if (nox_frame_xxx_2598000 > (unsigned int)(v10 + 1)) {
				nox_perfmon_latePackets_2618900 += nox_frame_xxx_2598000 - v10;
			}
			sub_43C650();
			data += 3;
			break;
		case 43: // MSG_USE_MAP
			k = dword_5d4594_1200804;
			if (*(uint32_t*)(data + 37) > *(int*)&dword_5d4594_1200804) {
				nox_xxx_setMapCRC_40A360(*(uint32_t*)(data + 37));
				nox_xxx_gameClearAll_467DF0(1);
				nox_xxx_gameSetMapPath_409D70((char*)(data + 1));
				nox_xxx_mapSetCrcMB_409B10(*(uint32_t*)(data + 33));
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					nox_common_gameFlags_unset_40A540(8);
					if (dword_5d4594_2650652) {
						sub_41D6C0();
					}
				}
				nox_xxx_setGameFlags_40A4D0(0x800000);
				dword_5d4594_1200804 = nox_frame_xxx_2598000;
				nox_xxx_gameSetCliConnected_43C720(0);
				sub_49C7A0();
				nox_xxx_guiServerOptionsHide_4597E0(0);
				sub_44A400();
			}
			data += 41;
			break;
		case 44: // MSG_JOIN_DATA
			v42 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			nox_player_netCode_85319C = v42;
			v43 = nox_common_playerInfoNew_416F60(v42);
			if (v43) {
				*((uint32_t*)v43 + 517) = *(uint32_t*)(data + 3);
				*getMemU32Ptr(0x8531A0, 2576) = v43;
			}
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				sub_57B920(getMemAt(0x5D4594, 1198020));
			}
			dword_5d4594_1200804 = 0;
			nox_perfmon_latePackets_2618900 = 0;
			*getMemU32Ptr(0x85B3FC, 120) = 0;
			nox_client_onJoinData();
			dword_5d4594_1200832 = 0;
			nox_xxx_cliSetSettingsAcquired_4169D0(0);
			data += 7;
			break;
		case 45:; // MSG_NEW_PLAYER
			int playerID = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			nox_playerInfo* pl = nox_common_playerInfoNew_416F60(playerID);
			if (!pl) {
				data += 129;
				break;
			}
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				pl->netCode = playerID;
				pl->lessons = *(short*)(data + 100);
				pl->field_2140 = *(unsigned short*)(data + 102);
				pl->field_0 = *(uint32_t*)(data + 104);
				pl->field_4 = *(uint32_t*)(data + 108);
				pl->field_2152 = *(unsigned char*)(data + 116);
				pl->field_2156 = *(unsigned char*)(data + 117);
				strcpy(pl->field_2096, (const char*)(data + 119));
				pl->field_3680 |= *(uint32_t*)(data + 112);
				memcpy(&pl->info, (const void*)(data + 3), 97);
				nox_swprintf(pl->name_final, L"%s%s", pl->info.name, pl->info.name_suff);
				if (dword_5d4594_2650652) {
					pl->field_2108 = 0;
					sub_41D670(pl->field_2096);
				}
				nox_xxx_playerInitColors_461460(pl);
			}
			sub_457140(playerID, pl->name_final);
			sub_455920(pl->name_final);
			v213 = nox_strman_loadString_40F1D0("PlayerJoined", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4661);
			wchar_t fnameBuf[100];
			nox_swprintf(fnameBuf, v213, pl->name_final);
			if (nox_xxx_gameGetPlayState_4356B0() == 3) {
				nox_xxx_printCentered_445490(fnameBuf);
			}
			if (playerID == nox_player_netCode_85319C && nox_wcscmp(getMemAt(0x85B3FC, 12204), pl->name_final)) {
				dword_5d4594_1200832 = 1;
			}
			OnLibraryNotice_263(pl);
			data += 129;
			break;
		case 46: // MSG_PLAYER_QUIT
			if (nox_client_isConnected_43C700()) {
				v214 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
				v215 = v214;
				v216 = nox_common_playerInfoGetByID_417040(v214);
				if (v216) {
					sub_456DF0(v215);
					sub_455950((wchar_t*)v216 + 2352);
					v217 = nox_strman_loadString_40F1D0("PlayerLeft", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
														4744);
					nox_swprintf(v397, v217, v216 + 4704);
					*((uint32_t*)v216 + 523) = 0;
					v218 = nox_xxx_objGetTeamByNetCode_418C80(v215);
					v219 = (int)v218;
					OnLibraryNotice_264(v216 + 4704);
					if (v218 && nox_xxx_servObjectHasTeam_419130((int)v218)) {
						nox_xxx_netChangeTeamMb_419570(v219, v215);
					}
				} else {
					v220 = nox_strman_loadString_40F1D0("UnknownLeft", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4757);
					nox_swprintf(v397, v220);
				}
				if (nox_xxx_gameGetPlayState_4356B0() == 3) {
					nox_xxx_printCentered_445490(v397);
				}
			}
			data += 3;
			break;
		case 47: // MSG_SIMPLE_OBJ
			nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				LODWORD(v5) = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 3), *(unsigned short*)(data + 1),
														  *(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
				if ((uint32_t)v5) {
					k = nox_frame_xxx_2598000;
					*(uint32_t*)(v5 + 288) = nox_frame_xxx_2598000;
				}
			}
			data += 9;
			break;
		case 48: // MSG_COMPLEX_OBJ
			nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			if (!nox_client_isConnected_43C700()) {
				data += 11;
				break;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (*(uint16_t*)(data + 3) || *(uint16_t*)(data + 1)) {
				LODWORD(v5) = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 3), *(unsigned short*)(data + 1),
														  *(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
				v29 = v5;
				if ((uint32_t)v5) {
					*(uint32_t*)(v5 + 288) = nox_frame_xxx_2598000;
					nox_xxx_spriteSetFrameMB_45AB80(v5, *(unsigned char*)(data + 10));
					LOBYTE(v5) = (*(uint8_t*)(data + 9) >> 4) & 7;
					*(uint8_t*)(v29 + 297) = v5;
					if ((unsigned char)v5 > 3u) {
						*(uint8_t*)(v29 + 297) = v5 + 1;
					}
					v30 = *(uint8_t*)(data + 9) & 0xF;
					*(uint8_t*)(data + 9) = v30;
					if (*(uint32_t*)(v29 + 276) != v30) {
						*(uint32_t*)(v29 + 316) = nox_frame_xxx_2598000;
						HIDWORD(v5) = *(unsigned char*)(data + 9);
						*(uint32_t*)(v29 + 276) = HIDWORD(v5);
					}
				}
				k = nox_player_netCode_85319C;
				if (*(unsigned short*)(data + 1) == nox_player_netCode_85319C && sub_416120(9u)) {
					nox_xxx_cliUpdateCameraPos_435600(*(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
				}
			} else {
				nox_xxx_cliUpdateCameraPos_435600(*(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
				nox_xxx_setKeybTimeout_4160D0(9);
			}
			data += 11;
			break;
		case 49: // MSG_DESTROY_OBJECT
			v44 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v45 = v44;
			if (!nox_client_isConnected_43C700()) {
				data += 3;
				break;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v45)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v45);
			v46 = v5;
			if (!(uint32_t)v5) {
				data += 3;
				break;
			}
			if (*(int (**)(int*, int))(v5 + 300) == nox_thing_animate_draw) {
				v47 = *(uint32_t*)(v5 + 304);
				if (v47) {
					if (*(uint32_t*)(v47 + 12) == 1) {
						data += 3;
						break;
					}
				}
			}
			v48 = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			v331 = v46;
			if (!v48) {
				goto LABEL_210;
			}
			nox_xxx_cliDestroyObj_45A9A0(v46);
			data += 3;
			break;
		case 50: // MSG_OBJECT_OUT_OF_SIGHT
			v49 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v50 = v49;
			if (!nox_client_isConnected_43C700()) {
				data += 3;
				break;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v50)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v50);
			v51 = v5;
			if (!(uint32_t)v5) {
				data += 3;
				break;
			}
			if (*(int (**)(int*, int))(v5 + 300) == nox_thing_animate_draw) {
				v52 = *(uint32_t*)(v5 + 304);
				if (v52) {
					if (*(uint32_t*)(v52 + 12) == 1) {
						data += 3;
						break;
					}
				}
			}
			if (v51 == *getMemU32Ptr(0x852978, 8)) {
				data += 3;
				break;
			}
			v53 = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			goto LABEL_208;
		case 51: // MSG_OBJECT_IN_SHADOWS
			v54 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v55 = v54;
			if (!nox_client_isConnected_43C700()) {
				data += 3;
				break;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v55)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v55);
			v51 = v5;
			if (!(uint32_t)v5) {
				data += 3;
				break;
			}
			k = 1;
			*(uint32_t*)(v5 + 484) = 1;
			*(uint32_t*)(v5 + 480) = 1;
			*(uint32_t*)(v5 + 488) = 1;
			if (nox_client_fadeObjects_80836) {
				if ((uint32_t)v5 != *getMemU32Ptr(0x852978, 8)) {
					nox_xxx_spriteTransparentDecay_49B950((uint32_t*)v5, (int)nox_gameFPS);
				}
			} else if (*(int (**)(int*, int))(v5 + 300) != nox_thing_animate_draw ||
					   (v56 = *(uint32_t*)(v5 + 304)) == 0 || *(uint32_t*)(v56 + 12) != 1) {
				if (v51 != *getMemU32Ptr(0x852978, 8)) {
					v53 = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				LABEL_208:
					v331 = v51;
					if (v53) {
						nox_xxx_cliDestroyObj_45A9A0(v51);
					} else {
					LABEL_210:
						nox_xxx_spriteDeleteStatic_45A4E0_drawable(v331);
					}
				}
			}
			data += 3;
			break;
		case 52: // MSG_OBJECT_FRIEND_ADD
			v57 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v58 = v57;
			if (nox_client_isConnected_43C700()) {
				nox_xxx_cliAddObjFriend_4959F0(v58);
			}
			data += 3;
			break;
		case 53: // MSG_OBJECT_FRIEND_REMOVE
			v59 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v60 = v59;
			if (nox_client_isConnected_43C700()) {
				sub_495A20(v60);
			}
			data += 3;
			break;
		case 54: // MSG_RESET_FRIENDS
			if (nox_client_isConnected_43C700()) {
				sub_4959B0();
			}
			++data;
			break;
		case 55: // MSG_ENABLE_OBJECT
			v62 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v63 = v62;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
					LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v63);
				} else {
					LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v63);
				}
				if ((uint32_t)v5) {
					*(uint32_t*)(v5 + 120) |= 0x1000000u;
				}
			}
			data += 3;
			break;
		case 56: // MSG_DISABLE_OBJECT
			v64 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v65 = v64;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
					LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v65);
				} else {
					LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v65);
				}
				if ((uint32_t)v5) {
					if (*(uint32_t*)(v5 + 112) & 0x40000) {
						*(uint32_t*)(v5 + 300) = 0;
					}
					*(uint32_t*)(v5 + 120) &= 0xFEFFFFFF;
				}
			}
			data += 3;
			break;
		case 57: // MSG_DRAW_FRAME
			v16 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v17 = v16;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_764;
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v17)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v17);
			if (!(uint32_t)v5) {
				goto LABEL_764;
			}
			nox_xxx_spriteSetFrameMB_45AB80(v5, *(unsigned char*)(data + 3));
			data += 4;
			break;
		case 58: // MSG_DESTROY_WALL
			if (nox_client_isConnected_43C700() && !nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_wallDestroyedByWallid_410520(*(uint16_t*)(data + 1));
			}
			data += 3;
			break;
		case 59: // MSG_OPEN_WALL
			if (nox_client_isConnected_43C700()) {
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					LODWORD(v5) = sub_410550(*(uint16_t*)(data + 1));
					if ((uint32_t)v5) {
						if (*(uint8_t*)(v5 + 4) & 4) {
							v67 = *(uint32_t*)(v5 + 28);
							*(uint8_t*)(v67 + 22) = 23;
							*(uint8_t*)(v67 + 21) = 3;
						}
					}
				}
			}
			data += 3;
			break;
		case 60: // MSG_CLOSE_WALL
			if (nox_client_isConnected_43C700()) {
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					LODWORD(v5) = sub_410550(*(uint16_t*)(data + 1));
					if ((uint32_t)v5) {
						if (*(uint8_t*)(v5 + 4) & 4) {
							v68 = *(uint32_t*)(v5 + 28);
							if (v68) {
								*(uint8_t*)(v68 + 22) = 0;
								*(uint8_t*)(v68 + 21) = 1;
							}
						}
					}
				}
			}
			data += 3;
			break;
		case 61: // MSG_CHANGE_OR_ADD_WALL_MAGIC
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_916;
			}
			LODWORD(v5) = nox_server_getWallAtGrid_410580(*(unsigned char*)(data + 4), *(unsigned char*)(data + 5));
			if (!(uint32_t)v5) {
				LODWORD(v5) = nox_xxx_wallCreateAt_410250(*(unsigned char*)(data + 4), *(unsigned char*)(data + 5));
				if (!(uint32_t)v5) {
					goto LABEL_916;
				}
			}
			v66 = *(uint8_t*)(data + 1);
			data += 6;
			*(uint8_t*)(v5 + 1) = v66;
			*(uint8_t*)v5 = *(uint8_t*)(data - 4);
			*(uint8_t*)(v5 + 2) = *(uint8_t*)(data - 3);
			break;
		case 62: // MSG_REMOVE_WALL_MAGIC
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_server_getWallAtGrid_410580(*(unsigned char*)(data + 1), *(unsigned char*)(data + 2));
				if ((uint32_t)v5) {
					nox_xxx_mapDelWallAtPt_410430(*(unsigned char*)(v5 + 5), *(unsigned char*)(v5 + 6));
				}
			}
			data += 3;
			break;
		case 65: // MSG_REPORT_HEALTH
			nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_764;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (!nox_xxx_unitSpriteCheckAlly_4951F0(*(unsigned short*)(data + 1))) {
				goto LABEL_764;
			}
			sub_495150(*(unsigned short*)(data + 1), 2 * *(unsigned char*)(data + 3));
			data += 4;
			break;
		case 66: // MSG_REPORT_HEALTH_DELTA
			nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			if (nox_client_isConnected_43C700() && nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			nox_xxx_cliAddHealthChange_49A650(*(unsigned short*)(data + 1), *(uint16_t*)(data + 3));
			data += 5;
			break;
		case 67: // MSG_REPORT_PLAYER_HEALTH
			if (nox_client_isConnected_43C700()) {
				sub_470CB0(*(short*)(data + 1));
			}
			data += 3;
			break;
		case 68: // MSG_REPORT_ITEM_HEALTH
			v92 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v93 = v92;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1149;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			sub_4675E0(v93, *(uint16_t*)(data + 3), *(uint16_t*)(data + 5));
			data += 7;
			break;
		case 69: // MSG_REPORT_MANA
			v96 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v97 = v96;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1163;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (v97 != nox_player_netCode_85319C) {
				goto LABEL_1163;
			}
			nox_xxx_cliSetMana_470D10(*(unsigned short*)(data + 3));
			data += 5;
			break;
		case 71: // MSG_REPORT_STAMINA
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_966;
			}
			sub_470D20(*(unsigned char*)(data + 1), *getMemIntPtr(0x587000, 157092));
			data += 2;
			break;
		case 72: // MSG_REPORT_STATS
			v98 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v99 = *getMemU32Ptr(0x8531A0, 2576);
			v100 = v98;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				if (v100 == nox_player_netCode_85319C) {
					v101 = nox_common_gameFlags_check_40A5C0(1);
					if (!v101 && v99) {
						*(uint32_t*)(v99 + 2247) = *(unsigned short*)(data + 3);
						*(uint32_t*)(v99 + 2243) = *(unsigned short*)(data + 5);
						LOWORD(v101) = *(uint16_t*)(data + 9);
						v332 = (double)v101;
						*(uint32_t*)(v99 + 2235) = nox_float2int(v332);
						*(uint32_t*)(v99 + 2239) = *(unsigned short*)(data + 11);
						*(uint16_t*)(v99 + 3652) = *(uint16_t*)(data + 7);
						*(uint8_t*)(v99 + 3684) = *(uint8_t*)(data + 13);
					}
					nox_xxx_j_inventoryNameSignInit_467460();
				}
			}
			data += 14;
			break;
		case 73: // MSG_REPORT_ARMOR_VALUE
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1163;
			}
			sub_467450(*(uint32_t*)(data + 1));
			data += 5;
			break;
		case 74: // MSG_REPORT_GOLD
			v102 = *(uint32_t*)(data + 1);
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1163;
			}
			sub_467490(v102);
			data += 5;
			break;
		case 75: // MSG_REPORT_PICKUP
			v103 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v104 = v103;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1163;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			*(uint32_t*)v381 = 0;
			*(uint16_t*)&v381[16] = -1;
			*(uint32_t*)&v381[4] = 0;
			*(uint16_t*)&v381[18] = -1;
			*(uint32_t*)&v381[8] = 0;
			*(uint32_t*)&v381[12] = 0;
			if (nox_xxx_spritePickup_461660(v104, *(unsigned short*)(data + 3), v381)) {
				goto LABEL_1163;
			}
			nox_xxx_send2ServInvenFail_461630(v104);
			data += 5;
			break;
		case 76: // MSG_REPORT_MODIFIABLE_PICKUP
			v105 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v106 = v105;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_735;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			v107 = 0;
			v108 = v385;
			do {
				*(uint32_t*)v108 = nox_xxx_modifGetDescById_413330(*(unsigned char*)(v107++ + data + 5));
				v108 += 4;
			} while (v107 < 4);
			*(uint16_t*)&v385[16] = -1;
			*(uint16_t*)&v385[18] = -1;
			if (nox_xxx_spritePickup_461660(v106, *(unsigned short*)(data + 3), v385)) {
				goto LABEL_735;
			}
			nox_xxx_send2ServInvenFail_461630(v106);
			data += 9;
			break;
		case 77: // MSG_REPORT_DROP
			v109 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v110 = v109;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1163;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			sub_461A80(v110);
			data += 5;
			break;
		case 78: // MSG_REPORT_LESSON
			v124 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v125 = v124;
			v126 = nox_xxx_cliGamedataGet_416590(0);
			if (nox_client_isConnected_43C700()) {
				v127 = nox_common_playerInfoGetByID_417040(v125);
				if (v127) {
					if (!nox_common_gameFlags_check_40A5C0(1)) {
						*((uint32_t*)v127 + 534) = *(uint32_t*)(data + 3);
						*((uint32_t*)v127 + 535) = *(uint32_t*)(data + 7);
						*((uint32_t*)v127 + 536) = nox_frame_xxx_2598000;
					}
					if (nox_common_gameFlags_check_40A5C0(1024)) {
						k = *(uint32_t*)(data + 7);
						if (k >= *((unsigned short*)v126 + 27)) {
							v128 = nox_strman_loadString_40F1D0("Eliminated", 0,
																"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3452);
							nox_swprintf(v395, v128, v127 + 4704);
							nox_xxx_clientPlaySoundSpecial_452D80(312, 100);
							nox_xxx_printCentered_445490(v395);
						}
					}
				}
			}
			data += 11;
			break;
		case 79: // MSG_REPORT_MUNDANE_ARMOR_EQUIP
		case 80: // MSG_REPORT_MUNDANE_WEAPON_EQUIP
			if (!nox_client_isConnected_43C700()) {
				data += 7;
				break;
			}
			LOWORD(v5) = *(uint16_t*)(data + 1);
			v367 = -1;
			*(uint16_t*)(data + 1) = v5 & 0x7FFF;
			if ((((unsigned int)v5 >> 15) & 1) == 1) {
				nox_xxx_clientEquipWeaponArmor_417AA0(*(uint8_t*)data, *(unsigned short*)(data + 1),
													  *(uint32_t*)(data + 3), (int)&v367);
			} else {
				nox_xxx_clientEquip_49A3D0(*(uint8_t*)data, *(unsigned short*)(data + 1), *(uint32_t*)(data + 3),
										   (int)&v367);
			}
			data += 7;
			break;
		case 81: // MSG_REPORT_MODIFIABLE_WEAPON_EQUIP
		case 82: // MSG_REPORT_MODIFIABLE_ARMOR_EQUIP
			LODWORD(v5) = nox_client_isConnected_43C700();
			if (!(uint32_t)v5) {
				goto LABEL_437;
			}
			LOWORD(v5) = *(uint16_t*)(data + 1);
			v116 = *(uint32_t*)(data + 3);
			v117 = v5;
			v118 = v5 & 0x7FFF;
			*(uint16_t*)(data + 1) = v118;
			v333 = data + 7;
			if (((v117 >> 15) & 1) == 1) {
				nox_xxx_clientEquipWeaponArmor_417AA0(*(uint8_t*)data, v118, v116, v333);
			} else {
				nox_xxx_clientEquip_49A3D0(*(uint8_t*)data, v118, v116, v333);
			}
		LABEL_437:
			data += 11;
			break;
		case 83: // MSG_REPORT_ARMOR_DEQUIP
		case 84: // MSG_REPORT_WEAPON_DEQUIP
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1149;
			}
			sub_417B80(*(uint8_t*)data, *(unsigned short*)(data + 1), *(uint32_t*)(data + 3));
			data += 7;
			break;
		case 85: // MSG_REPORT_TREASURE_COUNT
			v140 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v141 = v140;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				v142 = nox_common_playerInfoGetByID_417040(v141);
				if (v142) {
					if (!nox_common_gameFlags_check_40A5C0(1) && nox_frame_xxx_2598000 > *((uint32_t*)v142 + 540)) {
						HIWORD(v5) = 0;
						*((uint32_t*)v142 + 538) = *(unsigned short*)(data + 3);
						WORD2(v5) = *(uint16_t*)(data + 5);
						*((uint32_t*)v142 + 539) = WORD2(v5);
						*((uint32_t*)v142 + 540) = nox_frame_xxx_2598000;
					}
					k = *((uint32_t*)v142 + 539) - 1;
					if (*((uint32_t*)v142 + 538) == k) {
						v143 = nox_strman_loadString_40F1D0("SH_NearVictory", 0,
															"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3729);
						nox_swprintf(v406, v143, v142 + 4704);
						nox_xxx_printCentered_445490(v406);
					}
				}
			}
			data += 7;
			break;
		case 86: // MSG_REPORT_FLAG_BALL_WINNER
			v144 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned short*)(data + 1));
			if (!nox_client_isConnected_43C700()) {
				data += 8;
				break;
			}
			HIDWORD(v5) = *(uint32_t*)(data + 4);
			if (HIDWORD(v5) <= *(int*)&dword_5d4594_1200804) {
				data += 8;
				break;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			nox_xxx_clientPlaySoundSpecial_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_setGameFlags_40A4D0(8);
			}
			nox_xxx_initTime_435570();
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				sub_470510();
			}
			v145 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
			if (v145 && nox_xxx_teamCompare2_419180((int)v145, *(uint8_t*)(data + 1))) {
				v146 = nox_strman_loadString_40F1D0("TeamWon", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3776);
				nox_swprintf(v400, v146);
				v147 = 0;
			} else {
				v148 =
					nox_strman_loadString_40F1D0("teamformat", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3781);
				nox_swprintf(v400, v148, v144);
				v149 =
					nox_strman_loadString_40F1D0("FB_Victory", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3782);
				nox_swprintf(v400, v149, v400);
				v147 = 1;
			}
			sub_435700(v400, v147);
			nox_xxx_guiServerOptionsHide_4597E0(0);
			data += 8;
			break;
		case 87: // MSG_REPORT_FLAG_WINNER
			v172 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned short*)(data + 1));
			if (!nox_client_isConnected_43C700()) {
				data += 8;
				break;
			}
			k = dword_5d4594_1200804;
			if (*(uint32_t*)(data + 4) <= *(int*)&dword_5d4594_1200804) {
				data += 8;
				break;
			}
			v393[0] = 0;
			if (*(uint8_t*)(data + 3) == 1) {
				v173 = nox_strman_loadString_40F1D0("TimeLimitReached", 0,
													"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4055);
				nox_swprintf(v393, v173);
			}
			nox_xxx_clientPlaySoundSpecial_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_setGameFlags_40A4D0(8);
			}
			nox_xxx_initTime_435570();
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				sub_470510();
			}
			v174 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
			if (v172) {
				v175 = nox_strman_loadString_40F1D0("CTF_Victory", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
													4071);
				nox_swprintf(v398, v175, v172);
				if (!v174 || !nox_xxx_teamCompare2_419180((int)v174, v172[57])) {
					v176 = 1;
					goto LABEL_600;
				}
			} else {
				v177 = nox_strman_loadString_40F1D0("CTF_Tie", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4083);
				nox_swprintf(v398, v177);
			}
			v176 = 0;
		LABEL_600:
			nox_wcscat(v393, v398);
			sub_435700(v393, v176);
			nox_xxx_guiServerOptionsHide_4597E0(0);
			data += 8;
			break;
		case 88: // MSG_REPORT_DEATHMATCH_WINNER
			v150 = 1;
			v389[0] = 0;
			v392[0] = 0;
			v391[0] = 0;
			if (!nox_client_isConnected_43C700()) {
				data += 8;
				break;
			}
			HIDWORD(v5) = *(uint32_t*)(data + 4);
			if (HIDWORD(v5) <= *(int*)&dword_5d4594_1200804) {
				data += 8;
				break;
			}
			v391[0] = 0;
			if (*(uint8_t*)(data + 3) == 1) {
				v151 = nox_strman_loadString_40F1D0("TimeLimitReached", 0,
													"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3823);
				nox_swprintf(v391, v151);
			}
			nox_xxx_clientPlaySoundSpecial_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_setGameFlags_40A4D0(8);
			}
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				sub_470510();
			}
			nox_xxx_initTime_435570();
			if (*(uint16_t*)(data + 1)) {
				v152 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
				v372 = v152;
			}
			v153 = v372;
			v154 = nox_common_playerInfoGetByID_417040(v372);
			if (!nox_common_gameFlags_check_40A5C0(1024)) {
				if (*(uint16_t*)(data + 1)) {
					if (!v154) {
						goto LABEL_559;
					}
					if (!*(uint8_t*)(data + 3)) {
						sub_4947E0((int)v154);
					}
					if (v153 != nox_player_netCode_85319C) {
						v159 = nox_strman_loadString_40F1D0("DM_Loss", 0,
															"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3899);
						nox_swprintf(v389, v159, v154 + 4704);
						v150 = 1;
						goto LABEL_559;
					}
					if (!v154[2252]) {
						v314 = nox_strman_loadString_40F1D0("DM_MaleVictory", 0,
															"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3905);
						nox_swprintf(v389, v314);
						goto LABEL_558;
					}
					v155 = nox_strman_loadString_40F1D0("DM_FemaleVictory", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3907);
				} else {
					v155 =
						nox_strman_loadString_40F1D0("DM_Tie", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3884);
				}
			LABEL_557:
				nox_swprintf(v389, v155);
				goto LABEL_558;
			}
			if (!*(uint16_t*)(data + 1)) {
				v155 = nox_strman_loadString_40F1D0("HL_Tie", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3847);
				goto LABEL_557;
			}
			v156 = nox_strman_loadString_40F1D0("HL_Header", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3852);
			nox_swprintf(v389, v156);
			if (v153 == nox_player_netCode_85319C) {
				v334 = nox_strman_loadString_40F1D0("HL_You", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3855);
				v157 =
					nox_strman_loadString_40F1D0("HL_Victory", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3855);
				nox_swprintf(v392, v157, v334);
				nox_wcscat(v389, v392);
			LABEL_558:
				v150 = 0;
			} else {
				if (v154) {
					v158 = nox_strman_loadString_40F1D0("HL_Victory", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
														3863);
					nox_swprintf(v392, v158, v154 + 4704);
					if (!*(uint8_t*)(data + 3)) {
						sub_4947E0((int)v154);
					}
				}
				nox_wcscat(v389, v392);
				v150 = 1;
			}
		LABEL_559:
			nox_wcscat(v391, v389);
			sub_435700(v391, v150);
			nox_xxx_guiServerOptionsHide_4597E0(0);
			data += 8;
			break;
		case 89: // MSG_REPORT_DEATHMATCH_TEAM_WINNER
			v160 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned short*)(data + 1));
			if (!nox_client_isConnected_43C700()) {
				data += 8;
				break;
			}
			k = dword_5d4594_1200804;
			if (*(uint32_t*)(data + 4) <= *(int*)&dword_5d4594_1200804) {
				data += 8;
				break;
			}
			v394[0] = 0;
			if (*(uint8_t*)(data + 3) == 1) {
				v161 = nox_strman_loadString_40F1D0("TimeLimitReached", 0,
													"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3945);
				nox_swprintf(v394, v161);
			}
			nox_xxx_clientPlaySoundSpecial_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_setGameFlags_40A4D0(8);
			}
			nox_xxx_initTime_435570();
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				sub_470510();
			}
			v162 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
			if (nox_common_gameFlags_check_40A5C0(1024)) {
				if (!v160) {
					v163 =
						nox_strman_loadString_40F1D0("HL_Tie", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3964);
					nox_swprintf(v390, v163);
					v164 = 0;
					goto LABEL_585;
				}
				v165 =
					nox_strman_loadString_40F1D0("HL_Header", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3969);
				nox_swprintf(v390, v165);
				if (v162 && nox_xxx_teamCompare2_419180((int)v162, v160[57])) {
					v335 = nox_strman_loadString_40F1D0("HL_YourTeam", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3973);
					v166 = nox_strman_loadString_40F1D0("HL_Victory", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
														3973);
					nox_swprintf(v388, v166, v335);
					nox_wcscat(v390, v388);
					v164 = 0;
				} else {
					v336 =
						nox_strman_loadString_40F1D0("Team", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3980);
					v167 = nox_strman_loadString_40F1D0("HL_Victory", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
														3980);
					nox_swprintf(v388, v167, v336);
					nox_swprintf(v396, v388, v160);
					nox_wcscat(v390, v396);
					v164 = 1;
				}
				if (!*(uint8_t*)(data + 3)) {
					goto LABEL_584;
				}
			} else {
				if (!v160) {
					v168 =
						nox_strman_loadString_40F1D0("DM_Tie", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3999);
					nox_swprintf(v390, v168);
					v164 = 0;
					goto LABEL_585;
				}
				if (v162 && nox_xxx_teamCompare2_419180((int)v162, v160[57])) {
					v169 = nox_strman_loadString_40F1D0("DM_TeamVictory", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4006);
					nox_swprintf(v390, v169);
					v164 = 0;
				} else {
					v170 =
						nox_strman_loadString_40F1D0("Team", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4011);
					nox_swprintf(v388, v170, v160);
					v171 = nox_strman_loadString_40F1D0("DM_Loss", 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
														4012);
					nox_swprintf(v390, v171, v388);
					v164 = 1;
				}
				if (!*(uint8_t*)(data + 3)) {
				LABEL_584:
					sub_4948B0((int)v160);
					goto LABEL_585;
				}
			}
		LABEL_585:
			nox_wcscat(v394, v390);
			sub_435700(v394, v164);
			nox_xxx_guiServerOptionsHide_4597E0(0);
			data += 8;
			break;
		case 90: // MSG_REPORT_ENCHANTMENT
			v132 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v133 = v132;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1149;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v133)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v133);
			v134 = v5;
			if (!(uint32_t)v5) {
				goto LABEL_1149;
			}
			LODWORD(v5) = nox_client_drawable_testBuff_4356C0(v5, 15);
			HIDWORD(v5) = *(uint32_t*)(data + 3);
			v135 = v5;
			*(uint32_t*)(v134 + 124) = HIDWORD(v5);
			if (v134 == *getMemU32Ptr(0x852978, 8)) {
				sub_467410(*(uint32_t*)(data + 3));
			}
			if (v135 != 1 || nox_client_drawable_testBuff_4356C0(v134, 15) ||
				v134 == *getMemU32Ptr(0x852978, 8) && sub_467430() & 8) {
				goto LABEL_1149;
			}
			nox_thing* v136 = nox_get_thing(*(uint32_t*)(v134 + 108));
			nox_xxx_spriteChangeIntensity_484D70_light_intensity(v134 + 136, v136->light_intensity);
			data += 7;
			break;
		case 91: // MSG_REPORT_ITEM_ENCHANTMENT
			if (nox_client_isConnected_43C700()) {
				LOBYTE(v129) = sub_467430();
				v130 = (v129 >> 3) & 1;
				sub_467420(*(uint8_t*)(data + 1));
				if (v130 == 1 && !(sub_467430() & 8) && *getMemU32Ptr(0x852978, 8) &&
					!nox_client_drawable_testBuff_4356C0(*getMemIntPtr(0x852978, 8), 15)) {
					nox_thing* v131 = nox_get_thing(*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 108));
					nox_xxx_spriteChangeIntensity_484D70_light_intensity(*getMemU32Ptr(0x852978, 8) + 136,
																		 v131->light_intensity);
				}
			}
			data += 2;
			break;
		case 92: // MSG_REPORT_LIGHT_COLOR
			v88 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v89 = v88;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_902;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v89)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v89);
			if ((uint32_t)v5) {
				nox_xxx_spriteChangeLightColor_484BE0((uint32_t*)(v5 + 136), *(unsigned char*)(data + 3),
													  *(unsigned char*)(data + 4), *(unsigned char*)(data + 5));
				data += 6;
			} else {
			LABEL_902:
				data += 6;
			}
			break;
		case 93: // MSG_REPORT_LIGHT_INTENSITY
			v84 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v85 = v84;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_948;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v85)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v85);
			if (!(uint32_t)v5) {
				goto LABEL_948;
			}
			nox_xxx_spriteChangeIntensity_484D70_light_intensity(v5 + 136, *(float*)(data + 3));
			data += 7;
			break;
		case 94: // MSG_REPORT_Z_PLUS
			v178 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v179 = v178;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
								  ? nox_xxx_netSpriteByCodeStatic_45A720(v179)
								  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v179);
				if ((uint32_t)v5) {
					WORD2(v5) = *(unsigned char*)(data + 3);
					*(uint16_t*)(v5 + 104) = WORD2(v5);
				}
			}
			data += 4;
			break;
		case 95: // MSG_REPORT_Z_MINUS
			v180 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v181 = v180;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
								  ? nox_xxx_netSpriteByCodeStatic_45A720(v181)
								  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v181);
				if ((uint32_t)v5) {
					WORD2(v5) = *(unsigned char*)(data + 3);
					HIDWORD(v5) = -HIDWORD(v5);
					*(uint16_t*)(v5 + 104) = WORD2(v5);
				}
			}
			data += 4;
			break;
		case 96: // MSG_REPORT_EQUIP
			v120 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v121 = v120;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				sub_462040(v121);
			}
			data += 3;
			break;
		case 97: // MSG_REPORT_DEQUIP
			v122 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v123 = v122;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				sub_4624D0(v123);
			}
			data += 3;
			break;
		case 100: // MSG_REPORT_CHARGES
			v182 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v183 = v182;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_638;
			}
			sub_467930(v183, *(unsigned char*)(data + 3), *(unsigned char*)(data + 4));
			data += 5;
			break;
		case 101: // MSG_REPORT_X_STATUS
			v71 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v72 = v71;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
					LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v72);
				} else {
					LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v72);
				}
				v73 = (uint32_t*)v5;
				if ((uint32_t)v5) {
					v74 = *(uint32_t*)(v5 + 280);
					v73[70] = *(uint32_t*)(data + 3);
					k = v73[28];
					if (k & 0x20000) {
						if (!(v74 & 0x400)) {
							HIDWORD(v5) = v73[70] & 0x400;
							if (HIDWORD(v5) == 1024) {
								sub_4BC720((int)v73);
							}
						}
						v75 = v73[70];
						if (v75 & 0x800) {
							k = v73[28] & 0xFFF7FFFF;
							v76 = v73[30] & 0xDFFFFFFF;
							v73[28] = k;
							v73[30] = v76;
						}
					}
				}
			}
			data += 7;
			break;
		case 102: // MSG_REPORT_PLAYER_STATUS
			if (nox_client_isConnected_43C700() && *getMemU32Ptr(0x852978, 8)) {
				HIDWORD(v5) = *(uint32_t*)(data + 1);
				*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 120) = HIDWORD(v5);
			}
			data += 5;
			break;
		case 103: // MSG_REPORT_MODIFIER
			v77 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v78 = v77;
			if (nox_client_isConnected_43C700()) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
					nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
				}
				if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
					LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v78);
				} else {
					LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v78);
				}
				if ((uint32_t)v5) {
					v79 = v5 + 432;
					if ((uint32_t)v5 != (uint32_t)-432) {
						v80 = 0;
						v81 = (int*)(v5 + 432);
						do {
							*v81 = nox_xxx_modifGetDescById_413330(*(unsigned char*)(v80++ + data + 3));
							++v81;
						} while (v80 < 4);
						*(uint16_t*)(v79 + 16) = -1;
						*(uint16_t*)(v79 + 18) = -1;
					}
				}
			}
			data += 7;
			break;
		case 104: // MSG_REPORT_STAT_MODIFIER
			v82 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v83 = v82;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1057;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (v83 == nox_player_netCode_85319C) {
				LOBYTE(k) = *(uint8_t*)(data + 7);
				sub_467470(k, *(float*)(data + 3));
				data += 8;
			} else {
			LABEL_1057:
				data += 8;
			}
			break;
		case 105: // MSG_REPORT_NPC
			if (nox_client_isConnected_43C700()) {
				v285 = *(uint16_t*)(data + 1);
				v286 = v285;
				v285 &= 0x7FFFu;
				*(uint16_t*)(data + 1) = v285;
				v287 = v286 >> 15;
				v288 = nox_npc_by_id(v285);
				if (v288) {
					LODWORD(v5) = nox_init_npc(v288, *(unsigned short*)(data + 1));
				} else {
					LODWORD(v5) = nox_new_npc(*(unsigned short*)(data + 1));
					v288 = (char*)v5;
				}
				if (v288) {
					k = (int)(v288 + 8);
					v289 = (uint8_t*)(data + 4);
					v358 = (int*)(v288 + 8);
					v360 = 6;
					do {
						BYTE4(v5) = v289[1];
						LOBYTE(v5) = *v289;
						LOBYTE(k) = *(v289 - 1);
						v289 += 3;
						*v358 = nox_color_rgb_4344A0(k, v5, SHIDWORD(v5));
						k = (int)(v358 + 1);
						LODWORD(v5) = v360 - 1;
						v250 = v360 == 1;
						++v358;
						--v360;
					} while (!v250);
					*((uint32_t*)v288 + 328) = v287;
				}
			}
			data += 21;
			break;
		case 106: // MSG_REPORT_CLIENT_STATUS
			v119 = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 1));
			if (!v119) {
				goto LABEL_1070;
			}
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				nox_xxx_playerUnsetStatus_417530((int)v119, 1059);
				nox_xxx_netNeedTimestampStatus_4174F0((int)v119, *(uint32_t*)(data + 3) & 0x423);
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) ||
				(HIDWORD(v5) = *(unsigned short*)(data + 1), WORD2(v5) != nox_player_netCode_85319C)) {
			LABEL_1070:
				data += 7;
			} else {
				if (v119[3680] & 1) {
					nox_client_renderGUI_80828 = 0;
				} else if (nox_xxx_xxxRenderGUI_587000_80832 == 1) {
					nox_client_renderGUI_80828 = 1;
				}
				sub_470C40((*((uint32_t*)v119 + 920) >> 10) & 1);
				data += 7;
			}
			break;
		case 107: // MSG_REPORT_ANIMATION_FRAME
			v69 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v70 = v69;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_948;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
							  ? nox_xxx_netSpriteByCodeStatic_45A720(v70)
							  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v70);
			if (!(uint32_t)v5) {
				goto LABEL_948;
			}
			nox_xxx_spriteSetFrameMB_45AB80(v5, *(uint32_t*)(data + 3));
			data += 7;
			break;
		case 108: // MSG_REPORT_ACQUIRE_CREATURE
			v184 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v185 = v184;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_638;
			}
			v186 = *(uint16_t*)(data + 3);
			v187 = v186;
			v186 &= 0x7FFFu;
			*(uint16_t*)(data + 3) = v186;
			nox_xxx_cliSummonCreat_4C2E50(*(unsigned short*)(data + 1), v186, v187 & 0x8000);
			if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
				v188 = nox_xxx_netSpriteByCodeStatic_45A720(v185);
			} else {
				v188 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v185);
			}
			if (v188 || (v188 = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 3), v185, 0, 0)) != 0) {
				sub_459DD0((int)v188, 1);
			}
			sub_495060(*(unsigned short*)(data + 1), 0, 0);
			data += 5;
			break;
		case 109: // MSG_REPORT_LOSE_CREATURE
			v189 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v190 = v189;
			if (!nox_client_isConnected_43C700()) {
				data += 3;
				break;
			}
			v191 = *(uint16_t*)(data + 1);
			v192 = v191;
			v191 &= 0x7FFFu;
			*(uint16_t*)(data + 1) = v191;
			nox_xxx_cliSummonOnDieOrBanish_4C3140(v191, (void*)(v192 & 0x8000));
			sub_4950C0(*(unsigned short*)(data + 1));
			v337 = v190;
			if (!nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
				goto LABEL_642;
			}
			LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v190);
			goto LABEL_643;
		case 110: // MSG_REPORT_EXPERIENCE
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1163;
			}
			sub_467440(*(uint32_t*)(data + 1));
			data += 5;
			break;
		case 111: // MSG_REPORT_SPELL_AWARD
			v139 = 0;
			if (nox_client_isConnected_43C700()) {
				if (*(uint8_t*)(data + 3) & 0x80) {
					v139 = 1;
				}
				nox_xxx_netSpellRewardCli_45CFE0(*(unsigned char*)(data + 1), *(unsigned char*)(data + 2),
												 *(uint8_t*)(data + 3) & 0x7F, v139);
			}
			data += 4;
			break;
		case 112: // MSG_REPORT_SPELL_START
			sub_49BB80(*(uint8_t*)(data + 1));
			data += 2;
			break;
		case 113: // MSG_REPORT_INVENTORY_LOADED
			sub_467CA0();
			++data;
			break;
		case 124: // MSG_FX_PARTICLEFX
			v236 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 8));
			v237 = v236;
			if (nox_client_isConnected_43C700()) {
				nox_drawable* dr = 0;
				if (nox_xxx_netTestHighBit_578B70(*(uint16_t*)(data + 8))) {
					dr = nox_xxx_netSpriteByCodeStatic_45A720(v237);
				} else {
					dr = nox_xxx_netSpriteByCodeDynamic_45A6F0(v237);
				}
				nox_client_onParticleFx(*(unsigned char*)(data + 1), dr, *(uint16_t*)(data + 2), *(uint16_t*)(data + 4), *(uint16_t*)(data + 6));
			}
			data += 14;
			break;
		case 125: // MSG_FX_PLASMA
		case 140: // MSG_FX_LIGHTNING
		case 141: // MSG_FX_ENERGY_BOLT
		case 142: // MSG_FX_CHAIN_LIGHTNING_BOLT
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_732;
			}
			nox_xxx_netDrawRays_49BDD0((unsigned char*)data);
			HIWORD(k) = 0;
			v379.field_0 = *(unsigned short*)(data + 1);
			v379.field_4 = *(unsigned short*)(data + 3);
			LOWORD(k) = *(uint16_t*)(data + 5);
			HIWORD(v5) = 0;
			v377.field_0 = (unsigned short)k;
			WORD2(v5) = *(uint16_t*)(data + 7);
			v377.field_4 = WORD2(v5);
			LOBYTE(v5) = *(uint8_t*)data;
			if (*(uint8_t*)data == 140 || (uint8_t)v5 == 142) {
				nox_xxx_makeLightningParticles_4999D0(*(int*)&dword_5d4594_1200776, &v379, &v377);
			} else if ((uint8_t)v5 == 125) {
				nox_xxx_drawEnergyBolt_499710(*(unsigned short*)(data + 5), *(unsigned short*)(data + 7), 10,
											  *(int*)&dword_5d4594_1200776);
			}
		LABEL_732:
			data += 9;
			break;
		case 0x7Eu: // MSG_FX_SUMMON
			if (nox_client_isConnected_43C700()) {
				nox_xxx_netHandleSummonPacket_4B7C40(*(uint16_t*)(data + 5), (unsigned short*)(data + 1),
													 *(uint16_t*)(data + 7), *(uint8_t*)(data + 9),
													 *(uint16_t*)(data + 10));
			}
		LABEL_1130:
			data += 12;
			break;
		case 0x7Fu: // MSG_FX_SUMMON_CANCEL
			if (nox_client_isConnected_43C700()) {
				sub_4B7EE0(*(uint16_t*)(data + 1));
			}
			data += 3;
			break;
		case 0x80u: // MSG_FX_SHIELD
			if (nox_client_isConnected_43C700()) {
				nox_xxx_fxShield_4B8090(*(unsigned short*)(data + 1), *(unsigned char*)(data + 3));
			}
			goto LABEL_764;
		case 0x81u: // MSG_FX_BLUE_SPARKS
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_797;
			}
			nox_xxx_makePointFxCli_499610(*(int*)&dword_5d4594_1200776, 50, 1000, 30, *(short*)(data + 1),
										  *(short*)(data + 3));
			data += 5;
			break;
		case 0x82u: // MSG_FX_YELLOW_SPARKS
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_797;
			}
			nox_xxx_makePointFxCli_499610(*getMemIntPtr(0x5D4594, 1200780), 25, 500, 25, *(short*)(data + 1),
										  *(short*)(data + 3));
			data += 5;
			break;
		case 0x83u: // MSG_FX_CYAN_SPARKS
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_797;
			}
			nox_xxx_makePointFxCli_499610(*getMemIntPtr(0x5D4594, 1200784), 25, 500, 25, *(short*)(data + 1),
										  *(short*)(data + 3));
			data += 5;
			break;
		case 0x84u: // MSG_FX_VIOLET_SPARKS
			if (nox_client_isConnected_43C700()) {
				nox_xxx_makePointFxCli_499610(*(int*)&dword_5d4594_1200796, 25, 500, 25, *(short*)(data + 1),
											  *(short*)(data + 3));
			}
		LABEL_797:
			data += 5;
			break;
		case 0x85u: // MSG_FX_EXPLOSION
		case 0x86u: // MSG_FX_LESSER_EXPLOSION
		case 0x87u: // MSG_FX_COUNTERSPELL_EXPLOSION
		case 0x88u: // MSG_FX_THIN_EXPLOSION
		case 0x89u: // MSG_FX_TELEPORT
		case 0x8Au: // MSG_FX_SMOKE_BLAST
		case 0x8Bu: // MSG_FX_DAMAGE_POOF
		case 0xA3u: // MSG_FX_MANA_BOMB_CANCEL
			if (nox_client_isConnected_43C700()) {
				k = 0;
				switch (op) {
				case 133:
					v257 = *getMemU32Ptr(0x5D4594, 1200872);
					if (!*getMemU32Ptr(0x5D4594, 1200872)) {
						v257 = nox_xxx_getTTByNameSpriteMB_44CFC0("FireBoom");
						*getMemU32Ptr(0x5D4594, 1200872) = v257;
					}
					v258 = *(short*)(data + 3);
					goto LABEL_858;
				case 134:
					v257 = *getMemU32Ptr(0x5D4594, 1200876);
					if (!*getMemU32Ptr(0x5D4594, 1200876)) {
						v257 = nox_xxx_getTTByNameSpriteMB_44CFC0("MediumFireBoom");
						*getMemU32Ptr(0x5D4594, 1200876) = v257;
					}
					v258 = *(short*)(data + 3);
					goto LABEL_858;
				case 135:
					v257 = *getMemU32Ptr(0x5D4594, 1200880);
					if (!*getMemU32Ptr(0x5D4594, 1200880)) {
						v257 = nox_xxx_getTTByNameSpriteMB_44CFC0("CounterspellBoom");
						*getMemU32Ptr(0x5D4594, 1200880) = v257;
					}
					v258 = *(short*)(data + 3);
					goto LABEL_858;
				case 136:
					v257 = *getMemU32Ptr(0x5D4594, 1200884);
					if (!*getMemU32Ptr(0x5D4594, 1200884)) {
						v257 = nox_xxx_getTTByNameSpriteMB_44CFC0("ThinFireBoom");
						*getMemU32Ptr(0x5D4594, 1200884) = v257;
					}
					v258 = *(short*)(data + 3);
					goto LABEL_858;
				case 137:
					v257 = *getMemU32Ptr(0x5D4594, 1200888);
					if (!*getMemU32Ptr(0x5D4594, 1200888)) {
						v257 = nox_xxx_getTTByNameSpriteMB_44CFC0("TeleportPoof");
						*getMemU32Ptr(0x5D4594, 1200888) = v257;
					}
					goto LABEL_857;
				case 138:
					if (!*getMemU32Ptr(0x5D4594, 1200900)) {
						*getMemU32Ptr(0x5D4594, 1200900) = nox_xxx_getTTByNameSpriteMB_44CFC0("Smoke");
						*getMemU32Ptr(0x5D4594, 1200896) = nox_xxx_getTTByNameSpriteMB_44CFC0("Puff");
					}
					v259 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1200900), *(short*)(data + 1),
																 *(short*)(data + 3));
					if (v259) {
						*(uint16_t*)(v259 + 104) = 20;
						nox_xxx_sprite_45A110_drawable((uint32_t*)v259);
					}
					v260 = 6;
					do {
						v341 = *(short*)(data + 3) + nox_common_randomIntMinMax_415FF0(
														 -15, 15, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5711);
						v261 = nox_common_randomIntMinMax_415FF0(-15, 15,
																 "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5710);
						v262 = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1200896),
																	 *(short*)(data + 1) + v261, v341);
						if (v262) {
							*(uint16_t*)(v262 + 104) = nox_common_randomIntMinMax_415FF0(
								5, 25, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5712);
							nox_xxx_sprite_45A110_drawable((uint32_t*)v262);
						}
						--v260;
					} while (v260);
					goto LABEL_868;
				case 139:
					v257 = *getMemU32Ptr(0x5D4594, 1200892);
					if (!*getMemU32Ptr(0x5D4594, 1200892)) {
						v257 = nox_xxx_getTTByNameSpriteMB_44CFC0("DamagePoof");
						*getMemU32Ptr(0x5D4594, 1200892) = v257;
					}
				LABEL_857:
					v258 = *(short*)(data + 3) + 2;
				LABEL_858:
					LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(v257, *(short*)(data + 1), v258);
					if (!(uint32_t)v5) {
						goto LABEL_868;
					}
					nox_xxx_sprite_45A110_drawable((uint32_t*)v5);
					data += 5;
					break;
				case 163:
					v340 = nox_xxx_gamedataGetFloat_419D40("ManaBombOutRadius");
					v252 = nox_float2int(v340);
					v357 = 150;
					v253 = v252 >> 2;
					for (i = v252 >> 2;; v253 = i) {
						v254 = v253 + nox_common_randomIntMinMax_415FF0(
										  0, v252, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5536);
						if (v254 > (int)v252) {
							v254 = v252;
						}
						v255 = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
																 5541);
						LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(
							*getMemIntPtr(0x5D4594, 1200784),
							*(short*)(data + 1) + v254 * *getMemIntPtr(0x587000, 192088 + 8 * v255) / 16,
							*(short*)(data + 3) + v254 * *getMemIntPtr(0x587000, 192092 + 8 * v255) / 16);
						v256 = v5;
						if ((uint32_t)v5) {
							*(uint32_t*)(v5 + 432) = *(uint32_t*)(v5 + 12) << 12;
							*(uint32_t*)(v5 + 436) = *(uint32_t*)(v5 + 16) << 12;
							*(uint8_t*)(v5 + 299) = 0;
							*(uint32_t*)(v5 + 440) = 0;
							*(uint32_t*)(v5 + 448) = nox_frame_xxx_2598000 +
													 nox_common_randomIntMinMax_415FF0(
														 30, 40, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5562);
							*(uint32_t*)(v256 + 444) = nox_frame_xxx_2598000;
							*(uint16_t*)(v256 + 104) = 0;
							*(uint8_t*)(v256 + 296) = nox_common_randomIntMinMax_415FF0(
								4, 10, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5568);
							nox_xxx_sprite_45A110_drawable((uint32_t*)v256);
						}
						if (!--v357) {
							break;
						}
					}
					data += 5;
					break;
				default:
					goto LABEL_868;
				}
			} else {
			LABEL_868:
				data += 5;
			}
			break;
		case 0x8Fu: // MSG_FX_DRAIN_MANA
		case 0x90u: // MSG_FX_CHARM
		case 0x91u: // MSG_FX_GREATER_HEAL
			if (nox_client_isConnected_43C700()) {
				nox_xxx_netDrawRays_49BDD0((unsigned char*)data);
			}
		LABEL_735:
			data += 9;
			break;
		case 0x93u: // MSG_FX_SPARK_EXPLOSION
			if (!*getMemU32Ptr(0x5D4594, 1200852)) {
				*getMemU32Ptr(0x5D4594, 1200852) = nox_xxx_getTTByNameSpriteMB_44CFC0("Spark");
				*getMemU32Ptr(0x5D4594, 1200856) = nox_xxx_getTTByNameSpriteMB_44CFC0("MediumFireBoom");
				*getMemU32Ptr(0x5D4594, 1197380) = nox_xxx_getTTByNameSpriteMB_44CFC0("FireBoom");
			}
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_916;
			}
			v378.field_0 = *(short*)(data + 1);
			v378.field_4 = *(short*)(data + 3);
			sub_49A150(&v378, *getMemIntPtr(0x5D4594, 1200852), *(uint8_t*)(data + 5));
			v235 = *getMemU32Ptr(0x5D4594, 1197380);
			if (*(uint8_t*)(data + 5) <= 0xAAu) {
				v235 = *getMemU32Ptr(0x5D4594, 1200856);
			}
			LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(v235, *(short*)(data + 1), *(short*)(data + 3));
			goto LABEL_829;
		case 0x94u: // MSG_FX_DEATH_RAY
			nox_client_onDeathRay(*(unsigned short*)(data + 1), *(unsigned short*)(data + 3), *(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
			data += 9;
			break;
		case 0x95u: // MSG_FX_SENTRY_RAY
			if (nox_client_isConnected_43C700()) {
				sub_4C5020(data);
				if (nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4987) <
					25) {
					if (*getMemU32Ptr(0x852978, 8)) {
						v225 = *(unsigned short*)(data + 5) - *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 12);
						v226 = nox_double2int(
							sqrt((double)(v225 * v225 + (*(unsigned short*)(data + 7) -
														 *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16)) *
															(*(unsigned short*)(data + 7) -
															 *(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 16)))));
						if (v226 < 600) {
							nox_xxx_clientPlaySoundSpecial_452D80(297, 100 * (600 - v226) / 600);
						}
					}
				}
				if (!nox_xxx_checkGameFlagPause_413A50()) {
					v227 = *(unsigned short*)(data + 5) - *(unsigned short*)(data + 1);
					v228 = *(unsigned short*)(data + 7) - *(unsigned short*)(data + 3);
					v229 = nox_double2int(sqrt((double)(v227 * v227 + v228 * v228)));
					if (!v229) {
						v229 = 1;
					}
					v230 = *(unsigned short*)(data + 5) - 4 * v227 / v229;
					v231 = *(unsigned short*)(data + 7) - 4 * v228 / v229;
					LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(*(int*)&dword_5d4594_1200796, v230, v231);
					v362 = v5;
					if ((uint32_t)v5) {
						v232 = (uint32_t*)(v5 + 432);
						if ((uint32_t)v5 != (uint32_t)-432) {
							*(uint32_t*)(v5 + 432) = v230 << 12;
							*(uint32_t*)(v5 + 436) = v231 << 12;
							v233 = nox_common_randomIntMinMax_415FF0(
								0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5024);
							*(uint8_t*)(v362 + 299) = v233;
							v232[2] = nox_common_randomIntMinMax_415FF0(
								1, 1500, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5027);
							v232[4] = nox_frame_xxx_2598000 +
									  nox_common_randomIntMinMax_415FF0(
										  5, 20, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5030);
							v232[3] = nox_frame_xxx_2598000;
						}
						v234 = v362;
						*(uint16_t*)(v362 + 104) = 22;
						*(uint8_t*)(v234 + 296) = nox_common_randomIntMinMax_415FF0(
							-4, 4, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5037);
						nox_xxx_sprite_45A110_drawable((uint32_t*)v234);
					}
				}
			}
			data += 9;
			break;
		case 0x96u: // MSG_FX_RICOCHET
			if (nox_client_isConnected_43C700()) {
				if (!*getMemU32Ptr(0x5D4594, 1200860)) {
					*getMemU32Ptr(0x5D4594, 1200860) = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueSpark");
				}
				v239 = 5;
				do {
					LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1200860),
																		*(short*)(data + 1), *(short*)(data + 3));
					v240 = v5;
					if ((uint32_t)v5) {
						if ((uint32_t)v5 != (uint32_t)-432) {
							*(uint32_t*)(v5 + 432) = *(uint32_t*)(v5 + 12) << 12;
							*(uint32_t*)(v5 + 436) = *(uint32_t*)(v5 + 16) << 12;
							*(uint8_t*)(v5 + 299) = nox_common_randomIntMinMax_415FF0(
								0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5338);
							*(uint32_t*)(v240 + 440) = nox_common_randomIntMinMax_415FF0(
								1333, 4000, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5341);
							*(uint32_t*)(v240 + 448) = nox_frame_xxx_2598000 +
													   nox_common_randomIntMinMax_415FF0(
														   5, 20, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5344);
							*(uint32_t*)(v240 + 444) = nox_frame_xxx_2598000;
						}
						*(uint16_t*)(v240 + 104) = 20;
						*(uint8_t*)(v240 + 296) = nox_common_randomIntMinMax_415FF0(
							-5, 5, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5351);
						nox_xxx_sprite_45A110_drawable((uint32_t*)v240);
					}
					--v239;
				} while (v239);
			}
			data += 5;
			break;
		case 0x97u: // MSG_FX_JIGGLE
			if (nox_client_isConnected_43C700()) {
				sub_4355B0(*(unsigned char*)(data + 1) / 3);
			}
			data += 2;
			break;
		case 0x98u: // MSG_FX_GREEN_BOLT
			if (!*getMemU32Ptr(0x5D4594, 1200844)) {
				*getMemU32Ptr(0x5D4594, 1200844) = nox_xxx_getTTByNameSpriteMB_44CFC0("GreenZap");
			}
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(
								  *getMemIntPtr(0x5D4594, 1200844),
								  *(unsigned short*)(data + 1) +
									  (*(unsigned short*)(data + 5) - *(unsigned short*)(data + 1)) / 2,
								  *(unsigned short*)(data + 3) +
									  (*(unsigned short*)(data + 7) - *(unsigned short*)(data + 3)) / 2) +
							  432;
				*(uint8_t*)v5 = 0;
				*(uint32_t*)(v5 + 5) = *(uint32_t*)(data + 1);
				HIDWORD(v5) = *(uint32_t*)(data + 5);
				*(uint32_t*)(v5 + 9) = HIDWORD(v5);
				k = *(unsigned short*)(data + 9);
				*(uint32_t*)(v5 + 1) = k;
			}
			data += 11;
			break;
		case 0x9Au: // MSG_FX_WHITE_FLASH
			if (nox_client_isConnected_43C700()) {
				nox_xxx____setargv_11_473920();
			}
			data += 5;
			break;
		case 0x9Bu: // MSG_FX_GENERATING_MAP
		case 0x9Cu: // MSG_FX_ASSEMBLING_MAP
		case 0x9Du: // MSG_FX_POPULATING_MAP
			if (nox_client_isConnected_43C700()) {
				nox_xxx_mapGenClientText_4A9D00((unsigned char*)data);
			}
			data += 3;
			break;
		case 0x9Eu: // MSG_FX_DURATION_SPELL
			LOBYTE(v376) = *(uint8_t*)(data + 1);
			switch ((unsigned char)v376) {
			case 1u:
			case 2u:
			case 3u:
			case 4u:
			case 5u:
			case 6u:
			case 7u:
				if (nox_client_isConnected_43C700()) {
					nox_xxx_clientAddRayEffect_49C160(data);
				}
				goto LABEL_1070;
			case 8u:
			case 9u:
			case 0xAu:
			case 0xBu:
			case 0xCu:
			case 0xDu:
			case 0xEu:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_1070;
				}
				nox_xxx_clientRemoveRayEffect_49C450(data);
				data += 7;
				break;
			default:
				return 0;
			}
			break;
		case 0x9Fu: // MSG_FX_DELTAZ_SPELL_START
			v297 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v298 = v297;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
								  ? nox_xxx_netSpriteByCodeStatic_45A720(v298)
								  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v298);
				if ((uint32_t)v5) {
					LODWORD(v5) = v5 + 432;
					*(uint32_t*)v5 = nox_frame_xxx_2598000;
					i = *(char*)(data + 4);
					*(float*)(v5 + 8) = (double)i;
					k = *(unsigned char*)(data + 3);
					i = *(unsigned char*)(data + 3);
					*(float*)(v5 + 4) = (double)i;
					HIDWORD(v5) = *(unsigned char*)(data + 5);
					i = *(unsigned char*)(data + 5);
					*(float*)(v5 + 12) = (double)i;
				}
			}
			data += 6;
			break;
		case 0xA0u: // MSG_FX_TURN_UNDEAD
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1163;
			}
			nox_xxx_fxDrawTurnUndead_499880((short*)(data + 1));
			data += 5;
			break;
		case 0xA1u: // MSG_FX_ARROW_TRAP
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_916;
			}
			if (!*getMemU32Ptr(0x5D4594, 1200864)) {
				*getMemU32Ptr(0x5D4594, 1200864) = nox_xxx_getTTByNameSpriteMB_44CFC0("ArrowTrap1Smoke");
				*getMemU32Ptr(0x5D4594, 1200868) = nox_xxx_getTTByNameSpriteMB_44CFC0("ArrowTrap2Smoke");
			}
			v251 = *(short*)(data + 1);
			v339 = *(short*)(data + 3);
			if (*(uint8_t*)(data + 5) == 1) {
				LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1200864), v251 + 15, v339);
				if ((uint32_t)v5) {
					nox_xxx_sprite_45A110_drawable((uint32_t*)v5);
					data += 6;
					break;
				}
			} else {
				LODWORD(v5) = nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1200868), v251 - 3, v339);
			LABEL_829:
				if ((uint32_t)v5) {
					nox_xxx_sprite_45A110_drawable((uint32_t*)v5);
					data += 6;
					break;
				}
			}
		LABEL_916:
			data += 6;
			break;
		case 0xA2u: // MSG_FX_VAMPIRISM
			if (nox_client_isConnected_43C700()) {
				if (!*getMemU32Ptr(0x5D4594, 1200848)) {
					*getMemU32Ptr(0x5D4594, 1200848) = nox_xxx_getTTByNameSpriteMB_44CFC0("HealOrb");
				}
				v221 = *(unsigned short*)(data + 9);
				k = v221 & 0xFFFC;
				if (k <= 28) {
					v222 = v221 >> 2;
				} else {
					v222 = 7;
				}
				v223 = v222 + 1;
				if (v222 + 1 > 0) {
					do {
						LOBYTE(v368) = nox_common_randomIntMinMax_415FF0(
							6, 12, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4957);
						v323 = v368;
						v318 = nox_common_randomIntMinMax_415FF0(-20, 20,
																 "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4961);
						v224 = nox_common_randomIntMinMax_415FF0(-20, 20,
																 "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4960);
						sub_499490(*getMemIntPtr(0x5D4594, 1200848), (uint16_t*)(data + 1), v224, v318, v323, 0);
						--v223;
					} while (v223);
				}
			}
			data += 11;
			break;
		case 0xA4u: // MSG_UPDATE_STREAM
			v15 = (unsigned char*)(nox_xxx_netCliProcUpdateStream_494A60((unsigned char*)(data + 1), a1, v384) + data +
								   1);
			if ((unsigned int)v15 >= end) {
				return 1;
			}
			while (1) {
				LODWORD(v5) = nox_xxx_netCliUpdateStream2_494C30(v15, a1, v384);
				if ((int)v5 <= 0) {
					break;
				}
				v15 += v5;
				if ((unsigned int)v15 >= end) {
					return 1;
				}
			}
			if ((int)v5 < 0) {
				LODWORD(v5) = -(int)v5;
			}
			data = (unsigned int)&v15[v5];
			break;
		case 0xA6u: // MSG_AUDIO_EVENT
		case 0xA7u: // MSG_AUDIO_PLAYER_EVENT
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_651;
			}
			v338 = *(char*)(data + 1);
			v321 = (*(unsigned short*)(data + 2) >> 9) & 0x7E;
			v317 = *(uint16_t*)(data + 2) & 0x3FF;
			if (*(char*)data == -89) {
				sub_452E10(v317, v321, v338);
				data += 4;
			} else {
				sub_452DC0(v317, v321, v338);
			LABEL_651:
				data += 4;
			}
			break;
		case 0xA8u: // MSG_TEXT_MESSAGE
			v198 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v199 = v198;
			memset(getMemAt(0x5D4594, 1197384), 0, 0x27Cu);
			v200 = *(unsigned char*)(data + 3);
			if (v200 & 8) {
				v201 = nox_strman_loadString_40F1D0((char*)(data + 11), 0,
													"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4486);
				nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1197384), v201);
				v202 = 1;
			} else if (v200 & 2) {
				if (v200 & 1) {
					v203 = nox_strman_loadString_40F1D0("Guirank.c:team", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4493);
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1197384), L"%s: %S", v203, data + 11);
				} else {
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1197384), L"%S", data + 11);
				}
				v202 = 1;
			} else {
				if (v200 & 1) {
					v204 = nox_strman_loadString_40F1D0("Guirank.c:team", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4506);
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1197384), L"%s: %s", v204, data + 11);
				} else {
					nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1197384), (const wchar_t*)(data + 11));
				}
				v202 = 2;
			}
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_693;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (*(uint8_t*)(data + 3) & 0x10) {
				if (nox_xxx_gameGetPlayState_4356B0() == 3) {
					nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1200068), (const wchar_t*)getMemAt(0x5D4594, 1197384));
					v205 = nox_strman_loadString_40F1D0("guiserv.c:Notice", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4536);
					nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v205, (int)getMemAt(0x5D4594, 1200068), 33, 0, 0);
					k = v202 * *(unsigned char*)(data + 8);
					data += k + 11;
					break;
				}
			} else if (*(uint16_t*)(data + 1)) {
				if (nox_xxx_gameGetPlayState_4356B0() == 3) {
					v206 = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 1));
					v207 = v206;
					if (v206) {
						if (!nox_xxx_playerCanTalkMB_57A160((int)v206)) {
							nox_gui_console_Printf_450C00(NOX_CONSOLE_YELLOW, (wchar_t*)getMemAt(0x587000, 158984),
														  v207 + 4704, getMemAt(0x5D4594, 1197384));
							nox_xxx_createTextBubble_48D880(data, (wchar_t*)getMemAt(0x5D4594, 1197384));
							k = v202 * *(unsigned char*)(data + 8);
							data += k + 11;
							break;
						}
					} else {
						nox_xxx_createTextBubble_48D880(data, (wchar_t*)getMemAt(0x5D4594, 1197384));
						if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
							LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v199);
						} else {
							LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v199);
						}
						if ((uint32_t)v5) {
							v322 = *(unsigned short*)(data + 1);
							v208 = nox_get_thing_pretty_name(*(uint32_t*)(v5 + 108));
							nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 159000), v208,
														  v322, getMemAt(0x5D4594, 1197384));
						}
					}
				}
			} else if (nox_xxx_gameGetPlayState_4356B0() == 3) {
				nox_xxx_printCentered_445490((wchar_t*)getMemAt(0x5D4594, 1197384));
				k = v202 * *(unsigned char*)(data + 8);
				data += k + 11;
				break;
			}
		LABEL_693:
			k = v202 * *(unsigned char*)(data + 8);
			data += k + 11;
			break;
		case 169: // MSG_INFORM
			data += nox_client_handlePacketInform_4C9BF0(data);
			break;
		case 170:; // MSG_IMPORTANT
			int n = nox_common_gameFlags_check_40A5C0(1) ? 5 : 1;
			if (nox_client_isConnected_43C700()) {
				char v366[5];
				v366[0] = -85;
				if (nox_common_gameFlags_check_40A5C0(1)) {
					*(uint32_t*)&v366[1] = *(uint32_t*)(data + 1);
				} else {
					*(uint32_t*)&v366[1] = v364;
				}
				nox_netlist_addToMsgListCli_40EBC0(a1, 0, v366, 5);
			}
			data += n;
			break;
		case 171: // MSG_IMPORTANT_ACK
			if (nox_client_isConnected_43C700()) {
				sub_4E55A0(a1, *(uint32_t*)(data + 1));
			}
			data += 5;
			break;
		case 0xAEu: // MSG_OUTGOING_CLIENT
			data += 3;
			break;
		case 0xAFu: // MSG_GAME_SETTINGS
			dword_5d4594_1200768 = 0;
			v34 = *(uint32_t*)(data + 1);
			if (nox_xxx_get3512_40A350() < v34) {
				nox_xxx_set3512_40A340(v34);
				nox_common_gameFlags_check_40A5C0(1024);
				v355 = nox_common_gameFlags_check_40A5C0(32);
				v360 = nox_common_gameFlags_check_40A5C0(32);
				v363 = nox_common_gameFlags_check_40A5C0(4096);
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					nox_common_gameFlags_unset_40A540(524272);
					nox_xxx_setGameFlags_40A4D0(*(uint32_t*)(data + 9));
					sub_409E40(*(uint32_t*)(data + 13));
					nox_client_setVersion_409AE0(*(uint32_t*)(data + 5));
					nox_xxx_servSetPlrLimit_409F80(*(unsigned char*)(data + 17));
					v35 = nox_xxx_cliGamedataGet_416590(0);
					if (v35[56] != *(uint8_t*)(data + 19) || *((uint16_t*)v35 + 27) != *(unsigned char*)(data + 18)) {
						dword_5d4594_1200768 = 1;
					}
					*((uint16_t*)v35 + 27) = *(unsigned char*)(data + 18);
					v35[56] = *(uint8_t*)(data + 19);
					if ((signed char)*(uint8_t*)(data + 9) >= 0) {
						*((uint16_t*)v35 + 26) = *(uint16_t*)(data + 9);
						strcpy(v35, nox_xxx_mapGetMapName_409B40());
					}
					if (v355 || !nox_common_gameFlags_check_40A5C0(32)) {
						if (!nox_common_gameFlags_check_40A5C0(32)) {
							sub_455C10();
						}
					} else {
						sub_455A50(2);
					}
					if (v360 || !nox_common_gameFlags_check_40A5C0(64)) {
						if (!nox_common_gameFlags_check_40A5C0(64)) {
							sub_456050();
						}
					} else {
						sub_455F60();
					}
					if (v363 == 1 && !nox_common_gameFlags_check_40A5C0(4096)) {
						for (j = nox_common_playerInfoGetFirst_416EA0(); j;
							 j = nox_common_playerInfoGetNext_416EE0((int)j)) {
							nox_xxx_cliPlayerRespawn_417680((int)j, 255);
						}
					}
					if (!nox_common_gameFlags_check_40A5C0(0x20000) && nox_xxx_gameGetPlayState_4356B0() == 3) {
						nox_game_exit_xxx2();
					}
				}
			}
			data += 20;
			break;
		case 0xB0u: // MSG_GAME_SETTINGS_2
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				v37 = nox_xxx_cliGamedataGet_416590(0);
				strncpy(v37 + 9, (const char*)(data + 1), 0xFu);
				if (memcmp(getMemAt(0x5D4594, 1200732), (const void*)(data + 17), 0x14u)) {
					dword_5d4594_1200768 = 1;
				}
				if (*getMemU32Ptr(0x5D4594, 1200752) != *(uint32_t*)(data + 37) ||
					*getMemU32Ptr(0x5D4594, 1200756) != *(uint32_t*)(data + 41)) {
					dword_5d4594_1200768 = 1;
				}
				memcpy(v37 + 24, (const void*)(data + 17), 0x14u);
				sub_4540E0((int)(v37 + 24));
				*((uint32_t*)v37 + 11) = *(uint32_t*)(data + 37);
				*((uint32_t*)v37 + 12) = *(uint32_t*)(data + 41);
				if (*(uint32_t*)(data + 45)) {
					sub_40A1F0(1);
					sub_40A310(*(uint32_t*)(data + 45));
				} else {
					sub_40A1F0(0);
				}
				memcpy(getMemAt(0x5D4594, 1200708), v37, 0x3Au);
				if (nox_client_isConnected_43C700() && dword_5d4594_1200768) {
					v38 = nox_strman_loadString_40F1D0("OptionsChanged", 0,
													   "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 1429);
					nox_xxx_printCentered_445490(v38);
					nox_xxx_clientPlaySoundSpecial_452D80(310, 100);
				}
			}
			data += 49;
			break;
		case 0xB1u: // MSG_UPDATE_GUI_GAME_SETTINGS
			v39 = nox_xxx_cliGamedataGet_416590(*(unsigned char*)(data + 1));
			LOBYTE(v40) = v39[52];
			int v4b = *(uint8_t*)(data + 54);
			memcpy(v39, (const void*)(data + 2), 0x3Au);
			if (((v40 >> 5) & 1) != ((v4b >> 5) & 1)) {
				sub_4573A0();
			}
			if (!sub_4169C0()) {
				if (!sub_459DA0()) {
					if (*(uint8_t*)(data + 1) == 1) {
						sub_4165F0(1, 0);
					}
					if (nox_common_gameFlags_check_40A5C0(128)) {
						if (dword_5d4594_1200832) {
							v330 = *getMemU32Ptr(0x8531A0, 2576) + 4704;
							v41 = nox_strman_loadString_40F1D0("NameChange", 0,
															   "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 1470);
							nox_swprintf(v401, v41, v330);
							nox_xxx_printCentered_445490(v401);
							dword_5d4594_1200832 = 0;
						}
						if (nox_server_sanctuaryHelp_54276) {
							nox_xxx_cliShowHelpGui_49C560();
						}
					}
				}
				nox_xxx_cliSetSettingsAcquired_4169D0(1);
			}
			sub_459C30();
			data += 60;
			break;
		case 0xB2u: // MSG_DOOR_ANGLE
			v18 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v19 = v18;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
								  ? nox_xxx_netSpriteByCodeStatic_45A720(v19)
								  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v19);
				if ((uint32_t)v5) {
					*(uint8_t*)(v5 + 299) = *(uint8_t*)(data + 3);
				}
			}
			data += 4;
			break;
		case 0xB3u: // MSG_OBELISK_CHARGE
			v20 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v21 = v20;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
								  ? nox_xxx_netSpriteByCodeStatic_45A720(v21)
								  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v21);
				v22 = v5;
				if ((uint32_t)v5) {
					nox_xxx_spriteSetActiveMB_45A990_drawable(v5);
					v328 = (double)(16 * *(unsigned char*)(data + 3) / 10);
					nox_xxx_spriteChangeIntensity_484D70_light_intensity(v22 + 136, v328);
					nox_xxx_spriteSetFrameMB_45AB80(v22, 8 * *(unsigned char*)(data + 3) / 50);
					if (*(uint32_t*)(v22 + 308) == 8) {
						*(uint32_t*)(v22 + 308) = 7;
					}
				}
			}
			data += 4;
			break;
		case 0xB4u: // MSG_PENTAGRAM_ACTIVATE
			v24 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v25 = v24;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
								  ? nox_xxx_netSpriteByCodeStatic_45A720(v25)
								  : nox_xxx_netSpriteByCodeDynamic_45A6F0(v25);
				v26 = v5;
				if ((uint32_t)v5) {
					if (*(uint8_t*)(data + 3)) {
						*(uint32_t*)(v5 + 112) |= 0x80000u;
						nox_xxx_spriteChangeIntensity_484D70_light_intensity(v5 + 136, 41.958);
					} else {
						*(uint32_t*)(v5 + 112) &= 0xFFF7FFFF;
						nox_xxx_spriteChangeIntensity_484D70_light_intensity(v5 + 136, 0.0);
					}
					nox_xxx_spriteSetFrameMB_45AB80(v26, *(unsigned char*)(data + 3));
					*(uint32_t*)(v26 + 288) = nox_frame_xxx_2598000;
				}
			}
			data += 4;
			break;
		case 0xB5u: // MSG_CLIENT_PREDICT_LINEAR
			if (nox_client_isConnected_43C700() &&
				(v329 = *(unsigned short*)(data + 7), v320 = *(unsigned short*)(data + 5),
				 v31 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1)),
				 LODWORD(v5) = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 3), v31, v320, v329),
				 (uint32_t)v5)) {
				*(uint16_t*)(v5 + 508) = *(uint16_t*)(data + 9);
				*(float*)(v5 + 468) = (double)*(char*)(data + 12) * 0.0625;
				*(float*)(v5 + 472) = (double)*(char*)(data + 13) * 0.0625;
				*(float*)(v5 + 476) = (double)*(char*)(data + 11) * 0.0625;
				*(uint32_t*)(v5 + 316) = nox_frame_xxx_2598000;
				*(uint32_t*)(v5 + 324) = *(unsigned short*)(data + 5);
				v32 = *(unsigned short*)(data + 7);
				*(uint32_t*)(v5 + 460) = nox_xxx_sprite_4CA540;
				*(uint32_t*)(v5 + 328) = v32;
				nox_xxx_spriteToList_49BC80_drawable((uint32_t*)v5);
			}
			data += 14;
			break;
		case 0xB8u: // MSG_MAP_SEND_START
			nox_client_onMapDownloadStart((char*)(data + 8), *(uint32_t*)(data + 4));
			data += 88;
			break;
		case 0xB9u: // MSG_MAP_SEND_PACKET
			nox_client_onMapDownloadPart(*(uint16_t*)(data + 2), (void*)(data + 6), *(unsigned short*)(data + 4));
			k = *(unsigned short*)(data + 4);
			data += k + 6;
			break;
		case 0xBAu: // MSG_MAP_SEND_ABORT
			nox_client_onMapDownloadAbort();
			data += 2;
			break;
		case 0xBDu: // MSG_SYSOP_RESULT
			if (nox_client_isConnected_43C700()) {
				if (*(uint8_t*)(data + 1) == 1) {
					v290 = nox_strman_loadString_40F1D0("sysopAccess", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 6351);
				} else {
					v290 = nox_strman_loadString_40F1D0("invalidPass", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 6356);
				}
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v290);
			}
			data += 2;
			break;
		case 0xC2u: // MSG_XFER_MSG
			v263 = *(unsigned char*)(data + 1);
			switch (v263) {
			case 0:
				v342 = *(uint8_t*)(data + 136);
				v324 = *(uint32_t*)(data + 4);
				v315 = *(uint8_t*)(data + 2);
				v264 = nox_xxx_netGet_43C750();
				sub_40B5D0(v264, v315, (const char*)(data + 8), v324, v342);
				data += 140;
				break;
			case 1:
				BYTE4(v5) = *(uint8_t*)(data + 3);
				v343 = (char*)HIDWORD(v5);
				v325 = *(uint8_t*)(data + 2);
				v265 = nox_xxx_netGet_43C750();
				sub_40BFF0(v265, v325, v343);
				data += 4;
				break;
			case 2:
				v365[0] = -62;
				v365[1] = 3;
				v365[2] = *(uint8_t*)(data + 2);
				*(uint16_t*)&v365[4] = *(uint16_t*)(data + 4);
				v266 = nox_xxx_netGet_43C750();
				nox_xxx_netSendSock_552640(v266, v365, 6, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
				v344 = *(unsigned short*)(data + 6);
				v319 = *(uint16_t*)(data + 4);
				v316 = *(uint8_t*)(data + 2);
				v267 = nox_xxx_netGet_43C750();
				sub_40B250(v267, v316, v319, (const void*)(data + 8), v344);
				HIDWORD(v5) = *(unsigned short*)(data + 6);
				data += WORD2(v5) + 8;
				break;
			case 3:
				v345 = *(unsigned short*)(data + 4);
				v326 = *(uint8_t*)(data + 2);
				v268 = nox_xxx_netGet_43C750();
				sub_40BF60(v268, v326, v345);
				data += 6;
				break;
			case 4:
				v346 = *(uint8_t*)(data + 2);
				v269 = nox_xxx_netGet_43C750();
				sub_40C030(v269, v346);
				data += 3;
				break;
			case 5:
				LOBYTE(k) = *(uint8_t*)(data + 3);
				sub_40B720(k, *(uint8_t*)(data + 2));
				data += 4;
				break;
			case 6:
				LOBYTE(v263) = *(uint8_t*)(data + 3);
				v347 = *(uint8_t*)(data + 2);
				v327 = v263;
				v270 = nox_xxx_netGet_43C750();
				sub_40C070(v270, v327, v347);
				data += 4;
				break;
			default:
				return 0;
			}
			break;
		case 0xC3u: // MSG_PLAYER_OBJ
			nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (*(uint16_t*)(data + 3) || *(uint16_t*)(data + 1)) {
				v27 = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 3), *(unsigned short*)(data + 1),
												  *(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
				if (v27) {
					v27[72] = nox_frame_xxx_2598000;
					nox_xxx_spriteSetFrameMB_45AB80((int)v27, *(unsigned char*)(data + 10));
					v28 = (*(uint8_t*)(data + 9) >> 4) & 7;
					*((uint8_t*)v27 + 297) = v28;
					if (v28 > 3u) {
						*((uint8_t*)v27 + 297) = v28 + 1;
					}
					if (v27[69] != *(unsigned char*)(data + 11)) {
						v27[79] = nox_frame_xxx_2598000;
						k = *(unsigned char*)(data + 11);
						v27[69] = k;
					}
				}
				HIDWORD(v5) = *(unsigned short*)(data + 1);
				if (WORD2(v5) == nox_player_netCode_85319C && sub_416120(8u)) {
					nox_xxx_cliUpdateCameraPos_435600(*(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
				}
				data += 12;
			} else {
				nox_xxx_cliUpdateCameraPos_435600(*(unsigned short*)(data + 5), *(unsigned short*)(data + 7));
				nox_xxx_setKeybTimeout_4160D0(8);
				data += 12;
			}
			break;
		case 0xC4u: // MSG_TEAM_MSG
			switch (*(unsigned char*)(data + 1)) {
			case 0u:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_888;
				}
				memcpy(v386, (const void*)(data + 18), 2 * *(unsigned char*)(data + 15));
				v386[*(unsigned char*)(data + 15)] = 0;
				if (*(uint8_t*)(data + 17)) {
					v271 = nox_server_teamTitle_418C20(*(unsigned char*)(data + 16));
					nox_swprintf(v386, v271);
				}
				v272 = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
				if (!v272) {
					v272 = nox_xxx_teamCreate_4186D0(*(uint8_t*)(data + 2));
					if (!v272) {
						goto LABEL_888;
					}
				}
				sub_418800((wchar_t*)v272, v386, 0);
				sub_418830((int)v272, *(uint32_t*)(data + 6));
				nox_xxx_netChangeTeamID_419090((int)v272, *(uint32_t*)(data + 10));
				v272[56] = *(uint8_t*)(data + 16);
				sub_457230(v386);
				if (!(*(uint8_t*)(data + 14) & 1)) {
					goto LABEL_888;
				}
				v273 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
				if (!v273) {
					goto LABEL_888;
				}
				if (nox_common_gameFlags_check_40A5C0(1)) {
					nox_xxx_createAtImpl_4191D0(v272[57], (int)v273, 1, nox_player_netCode_85319C, 1);
					HIDWORD(v5) = *(unsigned char*)(data + 15);
					data += 2 * HIDWORD(v5) + 18;
				} else {
					sub_419900((int)v272, (int)v273, nox_player_netCode_85319C);
				LABEL_888:
					HIDWORD(v5) = *(unsigned char*)(data + 15);
					data += 2 * HIDWORD(v5) + 18;
				}
				break;
			case 1u:
				v274 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 6));
				v275 = v274;
				if (nox_client_isConnected_43C700()) {
					if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 6))) {
						LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v275);
					} else {
						LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v275);
					}
					if (!(uint32_t)v5) {
						LODWORD(v5) = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 8), v275, 0, 0);
					}
					v276 = v5 + 24;
					if ((uint32_t)v5 != (uint32_t)-24) {
						LODWORD(v5) = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
						v277 = v5;
						if ((uint32_t)v5) {
							nox_xxx_createAtImpl_4191D0(*(uint8_t*)(v5 + 57), v276, 0, *(unsigned short*)(data + 6), 0);
							sub_4571A0(*(unsigned short*)(data + 6), *(unsigned char*)(v277 + 57));
						}
					}
				}
				data += 10;
				break;
			case 2u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(data + 2));
					if ((uint32_t)v5) {
						nox_xxx_netChangeTeamMb_419570(v5, *(uint32_t*)(data + 2));
						sub_4571A0(*(uint32_t*)(data + 2), 0);
					}
				}
				goto LABEL_902;
			case 3u:
				if (nox_client_isConnected_43C700()) {
					v278 = nox_xxx_objGetTeamByNetCode_418C80(*(unsigned short*)(data + 6));
					if (v278) {
						LODWORD(v5) = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
						v279 = v5;
						if ((uint32_t)v5) {
							if (sub_4196D0((int)v278, v5, *(unsigned short*)(data + 6), 0)) {
								sub_4571A0(*(unsigned short*)(data + 6), *(unsigned char*)(v279 + 57));
							}
						}
					}
				}
				goto LABEL_908;
			case 4u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
					if ((uint32_t)v5) {
						nox_xxx_teamRenameMB_418CD0((wchar_t*)v5, (wchar_t*)(data + 6));
					}
				}
				data += 46;
				break;
			case 5u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
					if ((uint32_t)v5) {
						sub_418D80(v5);
					}
				}
				goto LABEL_916;
			case 6u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2));
					v280 = (wchar_t*)v5;
					if ((uint32_t)v5) {
						nox_wcscpy(v387, (const wchar_t*)v5);
						sub_418F20(v280, 0);
						sub_456EA0(v387);
					}
				}
				goto LABEL_920;
			case 7u:
				if (nox_client_isConnected_43C700()) {
					nox_server_teamsZzz_419030(0);
					sub_456FA0();
				}
				data += 2;
				break;
			case 8u:
				if (nox_client_isConnected_43C700() &&
					(LODWORD(v5) = nox_xxx_clientGetTeamColor_418AB0(*(uint32_t*)(data + 2)), (uint32_t)v5)) {
					nox_xxx_netChangeTeamID_419090(v5, *(uint32_t*)(data + 6));
					data += 10;
				} else {
				LABEL_908:
					data += 10;
				}
				break;
			case 9u:
				if (nox_client_isConnected_43C700()) {
					nox_server_teamsResetYyy_417D00();
				}
				data += 2;
				break;
			case 0xCu:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 2));
					if ((uint32_t)v5) {
						*(uint8_t*)(v5 + 2282) = *(uint8_t*)(data + 4);
					}
				}
				data += 5;
				break;
			}
			break;
		case 0xC5u: // MSG_KICK_NOTIFICATION
			sub_43B6E0();
			++data;
			break;
		case 0xC6u: // MSG_TIMEOUT_NOTIFICATION
			sub_43B750();
			++data;
			break;
		case 0xC7u: // MSG_SERVER_QUIT
			v359 = 0xC8u; // MSG_SERVER_QUIT_ACK
			v33 = nox_xxx_netGet_43C750();
			nox_xxx_netSendSock_552640(v33, &v359, 1, NOX_NET_SEND_FLAG2);
			sub_446380();
			++data;
			break;
		case 0xC9u: // MSG_SERVER_QUIT_ACK
			switch (*(unsigned char*)(data + 1)) {
			case 1u:
				if (nox_client_isConnected_43C700()) {
					sub_4C1590();
				}
				data += 2;
				break;
			case 2u:
				if (nox_client_isConnected_43C700()) {
					sub_479280();
				}
				data += 2;
				break;
			case 3u:
				if (nox_client_isConnected_43C700()) {
					sub_4C1BC0(data);
				}
				data += 3;
				break;
			case 4u:
				if (nox_client_isConnected_43C700()) {
					nox_xxx_tradeClientAddItem_4C1790(data);
				}
				data += 15;
				break;
			case 5u:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_1133;
				}
				sub_4C15D0(data);
				data += 4;
				break;
			case 6u:
				if (!nox_client_isConnected_43C700()) {
					data += 14;
					break;
				}
				sub_4C1B50(data);
				data += 14;
				break;
			case 7u:
				if (nox_client_isConnected_43C700()) {
					nox_xxx_prepareP2PTrade_4C1BF0();
				}
				data += 2;
				break;
			case 8u:
				if (nox_client_isConnected_43C700()) {
					sub_479300(*(unsigned short*)(data + 2), *(unsigned short*)(data + 4), *(uint32_t*)(data + 6),
							   *(uint32_t*)(data + 10), data + 14);
				}
				data += 18;
				break;
			case 9u:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_1133;
				}
				sub_479480(*(unsigned short*)(data + 2));
				data += 4;
				break;
			case 0xCu:
				if (nox_client_isConnected_43C700()) {
					nox_xxx_netP2PStartTrade_4C1320(data);
				}
				data += 52;
				break;
			case 0xDu:
				if (nox_client_isConnected_43C700()) {
					nox_xxx_cliStartShopDlg_478FD0((const wchar_t*)(data + 4), (char*)(data + 54),
												   *(unsigned short*)(data + 2));
				}
				data += 86;
				break;
			case 0x1Bu:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_1133;
				}
				sub_479520(*(unsigned short*)(data + 2));
				data += 4;
				break;
			case 0x1Du:
				if (nox_client_isConnected_43C700()) {
					sub_4795E0(*(unsigned short*)(data + 2), *(uint32_t*)(data + 4));
				}
				goto LABEL_1057;
			case 0x1Fu:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_1057;
				}
				sub_479740(*(unsigned short*)(data + 2), *(uint32_t*)(data + 4));
				data += 8;
				break;
			default:
				return 0;
			}
			break;
		case 0xCAu: // MSG_CHAT_KILL
			if (nox_client_isConnected_43C700()) {
				if (*(short*)(data + 1) == -8531) {
					sub_48E940();
				} else {
					sub_48E8E0(*(unsigned short*)(data + 1));
				}
			}
			data += 3;
			break;
		case 0xCBu: // MSG_MESSAGES_KILL
			if (nox_client_isConnected_43C700()) {
				sub_445450();
			}
			++data;
			break;
		case 0xCCu: // MSG_SEQ_IMPORTANT
			if (nox_client_isConnected_43C700()) {
				sub_48D5A0(data);
			}
			k = *(unsigned char*)(data + 3);
			data += k + 4;
			break;
		case 0xCDu: // MSG_REPORT_ABILITY_AWARD
			v86 = 0;
			if (nox_client_isConnected_43C700()) {
				v87 = *(uint8_t*)(data + 2);
				LOBYTE(v370) = *(uint8_t*)(data + 2) & 0x7F;
				if (v87 < 0) {
					v86 = 1;
				}
				nox_xxx_netAbilityRewardCli_4611E0(*(unsigned char*)(data + 1), (unsigned char)v370, (char*)v86);
			}
			data += 3;
			break;
		case 0xCEu: // MSG_REPORT_ABILITY_STATE
			if (nox_client_isConnected_43C700()) {
				sub_461090(*(unsigned char*)(data + 1), *(unsigned char*)(data + 2));
			}
			data += 3;
			break;
		case 0xCFu: // MSG_REPORT_ACTIVE_ABILITIES
			if (nox_client_isConnected_43C700()) {
				sub_461120(*(unsigned char*)(data + 1), *(unsigned char*)(data + 2));
			}
			data += 3;
			break;
		case 0xD0u: // MSG_DIALOG
			if (*(uint8_t*)(data + 1) == 3) {
				if (nox_client_isConnected_43C700()) {
					sub_479D30((wchar_t*)(data + 34), *(uint32_t*)(data + 98), (char*)(data + 2),
							   (const char*)(data + 102), *(uint8_t*)(data + 134));
					if (*getMemU32Ptr(0x8531A0, 2576)) {
						nox_xxx_netNeedTimestampStatus_4174F0(*getMemIntPtr(0x8531A0, 2576), 512);
					}
				}
				data += 135;
			} else if (*(uint8_t*)(data + 1) == 4) {
				if (nox_client_isConnected_43C700()) {
					sub_47A1F0();
					if (*getMemU32Ptr(0x8531A0, 2576)) {
						nox_xxx_playerUnsetStatus_417530(*getMemIntPtr(0x8531A0, 2576), 512);
					}
				}
			LABEL_966:
				data += 2;
			}
			break;
		case 0xD1u: // MSG_REPORT_GUIDE_AWARD
			if (nox_client_isConnected_43C700()) {
				nox_xxx_netGuideRewardCli_45D140(*(unsigned char*)(data + 1), *(uint8_t*)(data + 2) & 0x7F);
			}
			data += 3;
			break;
		case 0xD2u: // MSG_INTERESTING_ID
			v281 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v282 = v281;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_948;
			}
			if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
				v283 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
				LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v283);
			} else {
				v284 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
				LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v284);
			}
			if (*(uint8_t*)(data + 5) == 1) {
				if ((uint32_t)v5 ||
					(LODWORD(v5) = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 3), v282, 0, 0),
					 (uint32_t)v5)) {
					sub_459DD0(v5, *(uint8_t*)(data + 6));
					data += 7;
					break;
				}
			} else if ((uint32_t)v5) {
				nox_xxx_cliRemoveHealthbar_459E30(v5, *(uint8_t*)(data + 6));
			}
		LABEL_948:
			data += 7;
			break;
		case 0xD3u: // MSG_TIMER_STATUS
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_112;
			}
			if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(data + 9)) >= 0x1E) {
				v359 = -44;
				nox_xxx_netClientSend2_4E53C0(31, &v359, 1, 0, 1);
			LABEL_112:
				data += 13;
			} else {
				if (*(uint32_t*)(data + 1)) {
					sub_40A1F0(1);
					v5 = sub_40A310(*(uint32_t*)(data + 5));
				} else {
					sub_40A1F0(0);
				}
				data += 13;
			}
			break;
		case 0xD5u: // MSG_JOURNAL_MSG
			v296 = *getMemU32Ptr(0x8531A0, 2576);
			switch (*(uint8_t*)(data + 1)) {
			case 1:
				if (nox_client_isConnected_43C700()) {
					if (v296) {
						nox_xxx_journalEntryAdd_427490(v296, (char*)(data + 2), *(uint16_t*)(data + 66));
					}
					nox_xxx_cliBuildJournalString_469BC0();
				}
				data += 68;
				break;
			case 2:
				if (nox_client_isConnected_43C700()) {
					if (v296) {
						nox_xxx_journalEntryRemove_427590(v296, (const char*)(data + 2));
					}
					nox_xxx_cliBuildJournalString_469BC0();
				}
				data += 68;
				break;
			case 3:
				if (nox_client_isConnected_43C700() && v296) {
					nox_xxx_journalUpdateEntry_4276B0(v296, (const char*)(data + 2), *(uint16_t*)(data + 66));
				}
				data += 68;
				break;
			}
			break;
		case 0xD6u: // MSG_CHAPTER_END
			if (nox_client_isConnected_43C700()) {
				nox_client_lockScreenBriefing_450160(*(unsigned char*)(data + 1), *(unsigned char*)(data + 2), 0);
			}
			data += 3;
			break;
		case 0xD7u: // MSG_REPORT_ALL_LATENCY
			LODWORD(v5) = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 1));
			if ((uint32_t)v5) {
				LOWORD(k) = *(uint16_t*)(data + 3);
				*(uint16_t*)(v5 + 2148) = k;
			}
			data += 5;
			break;
		case 0xD8u: // MSG_REPORT_FLAG_STATUS
			if (nox_client_isConnected_43C700()) {
				sub_455D80(*(uint8_t*)(data + 2), *(uint8_t*)(data + 1));
				sub_4705F0(*(uint8_t*)(data + 1), *(uint8_t*)(data + 3), *(uint16_t*)(data + 4));
				data += 6;
			} else {
			LABEL_920:
				data += 6;
			}
			break;
		case 0xD9u: // MSG_REPORT_BALL_STATUS
			if (nox_client_isConnected_43C700()) {
				sub_456140(*(uint8_t*)(data + 1));
				sub_470650(*(uint8_t*)(data + 1), *(uint16_t*)(data + 2));
			}
			data += 4;
			break;
		case 0xDAu: // MSG_REPORT_OBJECT_POISON
			v137 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v138 = v137;
			if (nox_client_isConnected_43C700()) {
				if (nox_xxx_unitSpriteCheckAlly_4951F0(v138)) {
					sub_4950F0(v138, *(uint8_t*)(data + 3));
				}
				nox_npc_set_328(v138, *(unsigned char*)(data + 3));
				data += 4;
			} else {
			LABEL_764:
				data += 4;
			}
			break;
		case 0xDBu: // MSG_REPORT_MONITOR_CREATURE
			v193 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v194 = v193;
			if (nox_client_isConnected_43C700()) {
				if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
					v195 = nox_xxx_netSpriteByCodeStatic_45A720(v194);
				} else {
					v195 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v194);
				}
				if (v195 || (v195 = nox_xxx_spriteCreate_48E970(*(unsigned short*)(data + 3), v194, 0, 0)) != 0) {
					sub_459DD0((int)v195, 1);
				}
				sub_495060(v194, 0, 0);
			}
		LABEL_638:
			data += 5;
			break;
		case 0xDCu: // MSG_REPORT_UNMONITOR_CREATURE
			v196 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v197 = v196;
			if (!nox_client_isConnected_43C700()) {
				data += 3;
				break;
			}
			sub_4950C0(*(unsigned short*)(data + 1));
			v337 = v197;
			if (nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))) {
				LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v197);
			} else {
			LABEL_642:
				LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v337);
			}
		LABEL_643:
			if ((uint32_t)v5) {
				nox_xxx_cliRemoveHealthbar_459E30(v5, 1);
			}
			data += 3;
			break;
		case 0xDDu: // MSG_REPORT_TOTAL_HEALTH
			v90 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v91 = v90;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_1149;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (v91 == nox_player_netCode_85319C) {
				nox_xxx_cliSetTotalHealth_470C80(*(unsigned short*)(data + 3), *(unsigned short*)(data + 5));
				data += 7;
			} else if (nox_xxx_unitSpriteCheckAlly_4951F0(*(unsigned short*)(data + 1))) {
				sub_495120(*(unsigned short*)(data + 1), *(uint16_t*)(data + 3), *(uint16_t*)(data + 5));
				data += 7;
			} else {
			LABEL_1149:
				data += 7;
			}
			break;
		case 0xDEu: // MSG_REPORT_TOTAL_HEALTH
			v94 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v95 = v94;
			if (!nox_client_isConnected_43C700()) {
				goto LABEL_948;
			}
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (v95 != nox_player_netCode_85319C) {
				goto LABEL_948;
			}
			nox_xxx_cliSetManaAndMax_470CE0(*(unsigned short*)(data + 3), *(unsigned short*)(data + 5));
			data += 7;
			break;
		case 0xDFu: // MSG_REPORT_SPELL_STAT
			sub_460EB0(*(uint32_t*)(data + 1), *(uint8_t*)(data + 5));
			data += 6;
			break;
		case 0xE0u: // MSG_REPORT_SECONDARY_WEAPON
			v291 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v292 = v291;
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			if (*(uint16_t*)(data + 1)) {
				sub_467750(v292, *(uint8_t*)(data + 3));
			} else {
				sub_467750(0, *(uint8_t*)(data + 3));
			}
			data += 4;
			break;
		case 0xE1u: // MSG_REPORT_LAST_QUIVER
			v293 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			sub_467740(v293);
			data += 3;
			break;
		case 0xE2u: // MSG_INFO_BOOK_DATA
			v294 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(data + 1));
			v295 = v294;
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG)) {
				nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1));
			}
			LODWORD(v5) = sub_478080(v295);
			if ((uint32_t)v5 || (LODWORD(v5) = sub_4676D0(v295), (uint32_t)v5) ||
				(!nox_xxx_netTestHighBit_578B70(*(unsigned short*)(data + 1))
					 ? (LODWORD(v5) = nox_xxx_netSpriteByCodeDynamic_45A6F0(v295))
					 : (LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(v295)),
				 (uint32_t)v5)) {
				k = *(unsigned char*)(data + 3);
				*(uint32_t*)(v5 + 432) = k;
			}
			data += 4;
			break;
		case 0xE4: // MSG_FADE_BEGIN
			if (nox_client_isConnected_43C700()) {
				if (*(uint8_t*)(data + 1) == 1) {
					if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
						nox_gameDisableMapDraw_5d4594_2650672 = 0;
						sub_413A00(1);
						clientPacketFade(*(uint8_t*)(data + 2) == 1, 1);
					}
				} else if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
					clientPacketFade(*(uint8_t*)(data + 2) == 1, 0);
				}
			}
			data += 3;
			break;
		case 0xE5u: // MSG_MUSIC_EVENT
			if (nox_client_isConnected_43C700()) {
				sub_43D9B0(*(unsigned char*)(data + 1), *(unsigned char*)(data + 2));
			}
			data += 3;
			break;
		case 0xE6u: // MSG_MUSIC_PUSH_EVENT
			if (nox_client_isConnected_43C700()) {
				sub_43DA80();
			}
			data += 3;
			break;
		case 0xE7u: // MSG_MUSIC_POP_EVENT
			if (nox_client_isConnected_43C700()) {
				sub_43DAD0();
			}
			data += 3;
			break;
		case 0xE8u: // MSG_PLAYER_DIED
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 1));
				v111 = (uint32_t*)v5;
				if ((uint32_t)v5) {
					if ((uint32_t)v5 == *getMemU32Ptr(0x8531A0, 2576)) {
						sub_4BFE40();
						sub_478000();
					}
					v112 = nox_xxx_netSpriteByCodeDynamic_45A6F0(*(unsigned short*)(data + 1));
					if (v112) {
						nox_xxx_cliRemoveHealthbar_459E30((int)v112, 3);
					}
					if (!nox_common_gameFlags_check_40A5C0(4096)) {
						v111[1] = 0;
						LODWORD(v5) = v111 + 582;
						v113 = 27;
						do {
							v114 = (uint32_t*)v5;
							LODWORD(v5) = v5 + 24;
							*(uint32_t*)(v5 - 4) = 0;
							v5 = (unsigned int)v5;
							*v114 = 0;
							--v113;
							v114[1] = 0;
							v114[2] = 0;
							v114[3] = 0;
						} while (v113);
						for (k = 0; k < 624; k += 24) {
							v115 = *(uint32_t*)((char*)v111 + k + 2972);
							if (!(v115 & 0xC0D)) {
								HIDWORD(v5) = ~v115 & *v111;
								*v111 = HIDWORD(v5);
								*(uint32_t*)((char*)v111 + k + 2972) = 0;
								*(uint32_t*)((char*)v111 + k + 2976) = 0;
								*(uint32_t*)((char*)v111 + k + 2980) = 0;
								*(uint32_t*)((char*)v111 + k + 2984) = 0;
								*(uint32_t*)((char*)v111 + k + 2988) = 0;
							}
						}
					}
				}
			}
			data += 3;
			break;
		case 0xE9u: // MSG_PLAYER_RESPAWN
			if (nox_client_isConnected_43C700()) {
				if (nox_common_gameFlags_check_40A5C0(0x2000)) {
					k = *(unsigned short*)(data + 1);
					if ((unsigned short)k == nox_player_netCode_85319C) {
						sub_45A670(*(uint32_t*)(data + 3));
					}
				}
				if (*(uint8_t*)(data + 8) & 1) {
					LODWORD(v5) = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 1));
					if ((uint32_t)v5) {
						nox_xxx_cliPlayerRespawn_417680(v5, *(uint8_t*)(data + 7));
					}
				}
			}
			data += 9;
			break;
		case 0xEAu: // MSG_FORGET_DRAWABLES
			if (nox_common_gameFlags_check_40A5C0(0x2000)) {
				sub_45A670(*(uint32_t*)(data + 1));
				data += 5;
			} else {
			LABEL_1163:
				data += 5;
			}
			break;
		case 0xEBu: // MSG_RESET_ABILITIES
			if (!nox_client_isConnected_43C700()) {
				data += 2;
				break;
			}
			sub_4610D0(*(uint8_t*)(data + 1));
			data += 2;
			break;
		case 0xECu: // MSG_RATE_CHANGE
			if (nox_client_isConnected_43C700()) {
				sub_43C7A0(*(unsigned char*)(data + 1));
			}
			data += 2;
			break;
		case 0xEDu: // MSG_REPORT_CREATURE_CMD
			if (nox_client_isConnected_43C700()) {
				sub_4C1CA0(*(unsigned char*)(data + 1));
			}
			data += 2;
			break;
		case 0xEEu: // MSG_VOTE
			if (*(uint8_t*)(data + 1) == 6) {
				sub_48D4B0(*(unsigned char*)(data + 2));
				data += 3;
				break;
			} else if (*(uint8_t*)(data + 1) == 7) {
				sub_48D4A0();
				data += 2;
				break;
			}
			return 0;
		case 0xEFu: // MSG_STAT_MULTIPLIERS
			nox_client_onClassStats(data, 17);
			data += 17;
			break;
		case 0xF0u: // MSG_GAUNTLET
			switch (*(unsigned char*)(data + 1)) {
			case 0u:
				if (nox_client_isConnected_43C700() == 1) {
					if (nox_common_gameFlags_check_40A5C0(1)) {
						sub_460380();
						nox_xxx_cliPrepareGameplay1_460E60();
						sub_41CC00((char*)getMemAt(0x85B3FC, 10984));
						nox_xxx_plrLoad_41A480((char*)getMemAt(0x85B3FC, 10984));
					}
					nox_xxx_cliShowHideTubes_470AA0(1);
					sub_48D4A0();
					nox_xxx_cliPrepareGameplay2_4721D0();
					sub_4705B0();
				}
				goto LABEL_1085;
			case 1u:
				if (nox_client_isConnected_43C700() == 1) {
					nox_xxx_clientPlaySoundSpecial_452D80(1008, 100);
					v299 = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 2));
					if (v299) {
						if (!nox_common_gameFlags_check_40A5C0(1)) {
							*((uint32_t*)v299 + 1198) = 1;
						}
					}
				}
				data += 4;
				break;
			case 2u:
				if (nox_client_isConnected_43C700() == 1) {
					sub_49B4B0((unsigned short*)data);
				}
				data += 14;
				break;
			case 4u:
				if (nox_client_isConnected_43C700()) {
					v300 = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 3));
					if (v300) {
						v300[4816] = *(uint8_t*)(data + 2);
					}
					HIDWORD(v5) = *(unsigned short*)(data + 3);
					if (WORD2(v5) == nox_player_netCode_85319C) {
						sub_463420(*(unsigned char*)(data + 2));
					}
				}
				data += 5;
				break;
			case 5u:
			case 6u:
			case 7u:
			case 8u:
			case 9u:
			case 0xAu:
				nox_client_isConnected_43C700();
				data += 4;
				break;
			case 0xBu:
				nox_client_isConnected_43C700();
				data += 16;
				break;
			case 0xCu:
				if (nox_client_isConnected_43C700()) {
					nox_xxx_clientQuestWinScreen_450770(data);
				}
				nox_client_gui_flag_1556112 = 0;
				data += 90;
				break;
			case 0xDu:
				if (nox_client_isConnected_43C700()) {
					nox_client_showQuestBriefing2_450980(data, *(uint8_t*)(data + 4) & 1);
				}
				nox_client_gui_flag_1556112 = 0;
				data += 69;
				break;
			case 0xEu: // quest start briefing
				if (nox_client_isConnected_43C700()) {
					nox_client_showQuestBriefing_450A30(data, 1);
				}
				nox_client_gui_flag_1556112 = 0;
				data += 69;
				break;
			case 0xFu:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_xxx_netSpriteByCodeStatic_45A720(*(unsigned short*)(data + 2));
					if ((uint32_t)v5) {
						*(uint8_t*)(v5 + 432) = 0;
					}
				}
				data += 4;
				break;
			case 0x10u:
				if (!*getMemU32Ptr(0x5D4594, 1200904)) {
					*getMemU32Ptr(0x5D4594, 1200904) = nox_xxx_getTTByNameSpriteMB_44CFC0("GreenZap");
				}
				if (nox_client_isConnected_43C700()) {
					v301 = nox_xxx_spriteLoadAdd_45A360_drawable(
						*getMemIntPtr(0x5D4594, 1200904), *(unsigned short*)(data + 6), *(unsigned short*)(data + 8));
					*(uint8_t*)(v301 + 432) = 0;
					*(uint32_t*)(v301 + 437) = *(uint32_t*)(data + 2);
					*(uint32_t*)(v301 + 441) = *(uint32_t*)(data + 6);
					*(uint32_t*)(v301 + 433) = *(unsigned short*)(data + 10);
					nox_xxx_spriteTransparentDecay_49B950((uint32_t*)v301, *(unsigned short*)(data + 10));
				}
				goto LABEL_1130;
			case 0x11u:
				if (nox_client_isConnected_43C700()) {
					sub_45D320(*(unsigned short*)(data + 2));
				}
				goto LABEL_1133;
			case 0x12u:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_1133;
				}
				nox_xxx_clientQuestDisableAbility_45D4A0(*(unsigned short*)(data + 2));
				data += 4;
				break;
			case 0x13u:
				if (!nox_client_isConnected_43C700()) {
					goto LABEL_1133;
				}
				sub_45D400(*(unsigned short*)(data + 2));
				data += 4;
				break;
			case 0x14u:
				if (nox_client_isConnected_43C700() != 1 || sub_470580()) {
				LABEL_1085:
					data += 2;
				} else {
					sub_4705B0();
					data += 2;
				}
				break;
			case 0x15u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 6));
					if ((uint32_t)v5) {
						HIDWORD(v5) = *(uint32_t*)(data + 2);
						*(uint32_t*)(v5 + 4820) = HIDWORD(v5);
					}
				}
				data += 8;
				break;
			case 0x16u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 3));
					if ((uint32_t)v5) {
						*(uint8_t*)(v5 + 4824) = *(uint8_t*)(data + 2);
					}
				}
				data += 5;
				break;
			case 0x17u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 3));
					if ((uint32_t)v5) {
						*(uint8_t*)(v5 + 4825) = *(uint8_t*)(data + 2);
					}
				}
				data += 5;
				break;
			case 0x18u:
				if (nox_client_isConnected_43C700() == 1) {
					sub_4BFBB0((uint32_t*)*(unsigned char*)(data + 2));
				}
				data += 3;
				break;
			case 0x19u:
				if (!*getMemU32Ptr(0x5D4594, 1200908)) {
					*getMemU32Ptr(0x5D4594, 1200908) = nox_xxx_getTTByNameSpriteMB_44CFC0("GreenSpark");
					*getMemU32Ptr(0x5D4594, 1200912) = nox_xxx_getTTByNameSpriteMB_44CFC0("FireBoom");
				}
				v302 = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1200912),
																		*(short*)(data + 2), *(short*)(data + 4));
				if (v302) {
					nox_xxx_sprite_45A110_drawable(v302);
				}
				if (nox_client_isConnected_43C700()) {
					v380.field_0 = *(short*)(data + 2);
					v380.field_4 = *(short*)(data + 4);
					sub_49A150(&v380, *getMemIntPtr(0x5D4594, 1200908), *(uint8_t*)(data + 6));
				}
				goto LABEL_1149;
			case 0x1Au:
				if (nox_client_isConnected_43C700()) {
					nox_xxx_makePointFxCli_499610(*getMemIntPtr(0x5D4594, 1200788), 25, 500, 25, *(short*)(data + 2),
												  *(short*)(data + 4));
				}
				data += 6;
				break;
			case 0x1Cu:
				if (nox_client_isConnected_43C700()) {
					sub_41D1A0(*(unsigned char*)(data + 2));
				}
				data += 3;
				break;
			case 0x1Du:
				if (nox_client_isConnected_43C700()) {
					sub_465DE0(*(unsigned short*)(data + 2));
					data += 4;
				} else {
				LABEL_1133:
					data += 4;
				}
				break;
			case 0x1Eu:
				v303 = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 3));
				if (nox_client_isConnected_43C700() && v303) {
					if (v303 == *(char**)getMemAt(0x8531A0, 2576)) {
						v348 = nox_xxx_spellTitle_424930(*(unsigned char*)(data + 2));
						v304 = nox_strman_loadString_40F1D0("plyrspel.c:AwardSpell", 0,
															"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8112);
						nox_swprintf(v405, v304, v348);
					} else {
						v349 = nox_xxx_spellTitle_424930(*(unsigned char*)(data + 2));
						v305 = nox_strman_loadString_40F1D0("plyrspel.c:AwardSpellToOther", 0,
															"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8115);
						nox_swprintf(v405, v305, v303 + 4704, v349);
					}
					nox_xxx_printCentered_445490(v405);
				}
				goto LABEL_1163;
			case 0x1Fu:
				v306 = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 3));
				if (!nox_client_isConnected_43C700() || !v306) {
					goto LABEL_1163;
				}
				if (v306 == *(char**)getMemAt(0x8531A0, 2576)) {
					v350 = nox_xxx_guiCreatureGetName_427240(*(unsigned char*)(data + 2));
					v307 = nox_strman_loadString_40F1D0("PlyrGide.c:AwardGuide", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8145);
					nox_swprintf(v403, v307, v350);
				} else {
					v351 = nox_xxx_guiCreatureGetName_427240(*(unsigned char*)(data + 2));
					v308 = nox_strman_loadString_40F1D0("PlyrGide.c:AwardGuideToOther", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8148);
					nox_swprintf(v403, v308, v306 + 4704, v351);
				}
				nox_xxx_printCentered_445490(v403);
				data += 5;
				break;
			case 0x20u:
				v309 = nox_common_playerInfoGetByID_417040(*(unsigned short*)(data + 3));
				if (!nox_client_isConnected_43C700() || !v309) {
					goto LABEL_1163;
				}
				if (v309 == *(char**)getMemAt(0x8531A0, 2576)) {
					v352 = nox_xxx_abilityGetName_0_425260(*(unsigned char*)(data + 2));
					v310 = nox_strman_loadString_40F1D0("ComAblty.c:AwardAbility", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8178);
					nox_swprintf(v404, v310, v352);
				} else {
					v353 = nox_xxx_abilityGetName_0_425260(*(unsigned char*)(data + 2));
					v311 = nox_strman_loadString_40F1D0("ComAblty.c:AwardAbilityToOther", 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8181);
					nox_swprintf(v404, v311, v309 + 4704, v353);
				}
				nox_xxx_printCentered_445490(v404);
				data += 5;
				break;
			case 0x21u:
				if (nox_client_isConnected_43C700()) {
					v383[0] = (int)getMemAt(0x587000, 160948);
					v383[1] = (int)getMemAt(0x587000, 160988);
					v383[2] = (int)getMemAt(0x587000, 161028);
					v383[3] = (int)getMemAt(0x587000, 161068);
					v383[4] = (int)getMemAt(0x587000, 161112);
					v354 = nox_strman_loadString_40F1D0((char*)v383[*(unsigned char*)(data + 51)], 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8217);
					v312 = nox_strman_loadString_40F1D0((char*)(data + 2), 0,
														"C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8216);
					nox_swprintf(v402, v312, v354);
					nox_xxx_printCentered_445490(v402);
				}
				data += 52;
				break;
			default:
				return 0;
			}
			break;
		default:
			return 0;
		}
		noxOnCliPacketDebug(op, old, data - old);
	}
	return 1;
}
