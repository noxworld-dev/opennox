#include "cdecode.h"

#include "../../common/system/team.h"
#include "../../proto.h"
#include "../draw/animdraw.h"
#include "../draw/drawrays.h"
#include "../draw/fx.h"
#include "../gui/chathelp.h"
#include "../gui/gui_ctf.h"
#include "../gui/guibrief.h"
#include "../gui/guidlg.h"
#include "../gui/guifb.h"
#include "../gui/guigen.h"
#include "../gui/guiggovr.h"
#include "../gui/guiinv.h"
#include "../gui/guijourn.h"
#include "../gui/guimsg.h"
#include "../gui/guishop.h"
#include "../gui/guitrade.h"
#include "../gui/servopts/playrlst.h"
#include "../shell/noxworld.h"
#include "inform.h"
extern _DWORD dword_5d4594_2618900;
extern _DWORD dword_5d4594_1200776;
extern _DWORD dword_5d4594_1200796;
extern _DWORD dword_5d4594_1200768;
extern _DWORD dword_587000_312796;
extern _DWORD dword_587000_54276;
extern _DWORD dword_587000_312812;
extern _DWORD dword_587000_312828;
extern _DWORD dword_587000_312824;
extern _DWORD dword_587000_312792;
extern _DWORD dword_587000_312808;
extern _DWORD dword_5d4594_1556112;
extern _DWORD dword_5d4594_2614264;
extern _DWORD dword_587000_80832;
extern _DWORD dword_587000_312788;
extern _DWORD dword_5d4594_1200804;
extern _DWORD dword_587000_80836;
extern _DWORD dword_587000_312784;
extern _DWORD dword_587000_312800;
extern _DWORD dword_587000_312816;
extern _DWORD dword_587000_312804;
extern _DWORD dword_587000_312820;
extern _DWORD dword_5d4594_2650672;
extern _DWORD dword_587000_80828;
extern _DWORD dword_5d4594_2650652;

//----- (0048EA70) --------------------------------------------------------
int __cdecl sub_48EA70(int a1, unsigned int a2, int a3) {
	unsigned int v3;          // ebp
	unsigned int v4;          // ebx
	__int64 v5;               // rax
	int k;                    // ecx
	char v7;                  // cl
	int v8;                   // esi
	int v9;                   // edi
	int v10;                  // ebx
	unsigned __int16 v11;     // ax
	unsigned int v12;         // esi
	int v13;                  // eax
	int v14;                  // esi
	unsigned __int8* v15;     // ebp
	int v16;                  // eax
	int v17;                  // esi
	int v18;                  // eax
	int v19;                  // esi
	int v20;                  // eax
	int v21;                  // esi
	int v22;                  // esi
	int v24;                  // eax
	int v25;                  // esi
	int v26;                  // esi
	_DWORD* v27;              // esi
	unsigned __int8 v28;      // al
	int v29;                  // esi
	unsigned __int8 v30;      // bl
	unsigned int v31;         // eax
	int v32;                  // ecx
	int v33;                  // eax
	unsigned int v34;         // esi
	char* v35;                // ebx
	char* j;                  // esi
	char* v37;                // ebx
	wchar_t* v38;             // eax
	char* v39;                // eax
	unsigned int v40;         // edx
	wchar_t* v41;             // eax
	int v42;                  // eax
	char* v43;                // eax
	int v44;                  // eax
	int v45;                  // esi
	int v46;                  // esi
	int v47;                  // eax
	unsigned int v48;         // eax
	int v49;                  // eax
	int v50;                  // esi
	int v51;                  // esi
	int v52;                  // eax
	unsigned int v53;         // eax
	int v54;                  // eax
	int v55;                  // esi
	int v56;                  // eax
	int v57;                  // eax
	int v58;                  // esi
	int v59;                  // eax
	int v60;                  // esi
	int v61;                  // esi
	int v62;                  // eax
	int v63;                  // esi
	int v64;                  // eax
	int v65;                  // esi
	char v66;                 // cl
	int v67;                  // eax
	int v68;                  // eax
	int v69;                  // eax
	int v70;                  // esi
	int v71;                  // eax
	int v72;                  // esi
	_DWORD* v73;              // esi
	int v74;                  // eax
	int v75;                  // eax
	unsigned int v76;         // eax
	int v77;                  // eax
	int v78;                  // esi
	int v79;                  // edi
	int v80;                  // esi
	int* v81;                 // ebx
	int v82;                  // eax
	int v83;                  // esi
	int v84;                  // eax
	int v85;                  // esi
	int v86;                  // esi
	char v87;                 // al
	int v88;                  // eax
	int v89;                  // esi
	int v90;                  // eax
	int v91;                  // esi
	int v92;                  // eax
	int v93;                  // esi
	int v94;                  // eax
	int v95;                  // esi
	int v96;                  // eax
	int v97;                  // esi
	int v98;                  // eax
	int v99;                  // esi
	int v100;                 // ebx
	int v101;                 // eax
	int v102;                 // esi
	int v103;                 // eax
	int v104;                 // esi
	int v105;                 // eax
	int v106;                 // edi
	int v107;                 // esi
	char* v108;               // ebx
	int v109;                 // eax
	int v110;                 // esi
	_DWORD* v111;             // esi
	_DWORD* v112;             // eax
	int v113;                 // ecx
	_DWORD* v114;             // ebx
	int v115;                 // eax
	int v116;                 // edx
	unsigned int v117;        // ecx
	unsigned __int16 v118;    // ax
	char* v119;               // esi
	int v120;                 // eax
	int v121;                 // esi
	int v122;                 // eax
	int v123;                 // esi
	int v124;                 // eax
	int v125;                 // esi
	char* v126;               // ebx
	char* v127;               // esi
	wchar_t* v128;            // eax
	unsigned int v129;        // eax
	int v130;                 // esi
	int v132;                 // eax
	int v133;                 // esi
	int v134;                 // esi
	int v135;                 // ebx
	int v137;                 // eax
	int v138;                 // esi
	int v139;                 // esi
	int v140;                 // eax
	int v141;                 // esi
	char* v142;               // esi
	wchar_t* v143;            // eax
	char* v144;               // esi
	_DWORD* v145;             // eax
	wchar_t* v146;            // eax
	int v147;                 // eax
	wchar_t* v148;            // eax
	wchar_t* v149;            // eax
	int v150;                 // esi
	wchar_t* v151;            // eax
	int v152;                 // eax
	int v153;                 // edi
	char* v154;               // ebx
	wchar_t* v155;            // eax
	wchar_t* v156;            // eax
	wchar_t* v157;            // eax
	wchar_t* v158;            // eax
	wchar_t* v159;            // eax
	char* v160;               // ebx
	wchar_t* v161;            // eax
	_DWORD* v162;             // esi
	wchar_t* v163;            // eax
	int v164;                 // esi
	wchar_t* v165;            // eax
	wchar_t* v166;            // eax
	wchar_t* v167;            // eax
	wchar_t* v168;            // eax
	wchar_t* v169;            // eax
	wchar_t* v170;            // eax
	wchar_t* v171;            // eax
	char* v172;               // ebx
	wchar_t* v173;            // eax
	_DWORD* v174;             // esi
	wchar_t* v175;            // eax
	int v176;                 // esi
	wchar_t* v177;            // eax
	int v178;                 // eax
	int v179;                 // esi
	int v180;                 // eax
	int v181;                 // esi
	int v182;                 // eax
	int v183;                 // esi
	unsigned int v184;        // eax
	unsigned int v185;        // esi
	unsigned __int16 v186;    // ax
	unsigned __int16 v187;    // cx
	_DWORD* v188;             // eax
	int v189;                 // eax
	int v190;                 // esi
	unsigned __int16 v191;    // ax
	unsigned __int16 v192;    // cx
	unsigned int v193;        // eax
	unsigned int v194;        // esi
	_DWORD* v195;             // eax
	int v196;                 // eax
	int v197;                 // esi
	int v198;                 // eax
	int v199;                 // ebx
	int v200;                 // eax
	wchar_t* v201;            // eax
	int v202;                 // edi
	wchar_t* v203;            // eax
	wchar_t* v204;            // eax
	wchar_t* v205;            // eax
	char* v206;               // eax
	char* v207;               // esi
	int v208;                 // eax
	int v209;                 // eax
	int v210;                 // esi
	char* v211;               // ebx
	wchar_t* v212;            // ebx
	wchar_t* v213;            // eax
	int v214;                 // eax
	int v215;                 // esi
	char* v216;               // ebx
	wchar_t* v217;            // eax
	_DWORD* v218;             // eax
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
	_DWORD* v232;             // esi
	char v233;                // al
	int v234;                 // esi
	int v235;                 // eax
	int v236;                 // eax
	int v237;                 // esi
	_DWORD* v238;             // eax
	int v239;                 // ebx
	int v240;                 // edi
	int v241;                 // esi
	int v242;                 // edi
	int v243;                 // edi
	int v244;                 // ebx
	int v245;                 // eax
	_DWORD* v246;             // esi
	char v247;                // al
	__int16 v248;             // ax
	int v249;                 // esi
	bool v250;                // zf
	int v251;                 // ecx
	unsigned int v252;        // ebx
	int v253;                 // edi
	int v254;                 // esi
	int v255;                 // eax
	int v256;                 // esi
	int v257;                 // eax
	int v258;                 // ecx
	int v259;                 // eax
	int v260;                 // edi
	int v261;                 // eax
	int v262;                 // esi
	int v263;                 // eax
	int v264;                 // eax
	int v265;                 // eax
	int v266;                 // eax
	int v267;                 // eax
	int v268;                 // eax
	int v269;                 // eax
	int v270;                 // eax
	wchar_t* v271;            // eax
	char* v272;               // esi
	_DWORD* v273;             // edi
	unsigned int v274;        // eax
	unsigned int v275;        // esi
	int v276;                 // ebx
	int v277;                 // esi
	_DWORD* v278;             // ebx
	int v279;                 // esi
	wchar_t* v280;            // esi
	unsigned int v281;        // eax
	unsigned int v282;        // esi
	int v283;                 // eax
	int v284;                 // eax
	unsigned __int16 v285;    // ax
	unsigned __int16 v286;    // bx
	int v287;                 // ebx
	char* v288;               // edi
	_BYTE* v289;              // esi
	wchar_t* v290;            // eax
	int v291;                 // eax
	int v292;                 // esi
	int v293;                 // eax
	int v294;                 // eax
	int v295;                 // esi
	int v296;                 // esi
	int v297;                 // eax
	int v298;                 // esi
	char* v299;               // esi
	char* v300;               // eax
	int v301;                 // eax
	_DWORD* v302;             // eax
	char* v303;               // esi
	wchar_t* v304;            // eax
	wchar_t* v305;            // eax
	char* v306;               // esi
	wchar_t* v307;            // eax
	wchar_t* v308;            // eax
	char* v309;               // esi
	wchar_t* v310;            // eax
	wchar_t* v311;            // eax
	wchar_t* v312;            // eax
	wchar_t* v314;            // [esp-Ch] [ebp-175Ch]
	char v315;                // [esp-8h] [ebp-1758h]
	unsigned __int8 v316;     // [esp-8h] [ebp-1758h]
	int v317;                 // [esp-4h] [ebp-1754h]
	int v318;                 // [esp-4h] [ebp-1754h]
	unsigned __int16 v319;    // [esp-4h] [ebp-1754h]
	int v320;                 // [esp+0h] [ebp-1750h]
	int v321;                 // [esp+0h] [ebp-1750h]
	int v322;                 // [esp+0h] [ebp-1750h]
	char v323;                // [esp+0h] [ebp-1750h]
	size_t v324;              // [esp+0h] [ebp-1750h]
	char v325;                // [esp+0h] [ebp-1750h]
	char v326;                // [esp+0h] [ebp-1750h]
	int v327;                 // [esp+0h] [ebp-1750h]
	float v328;               // [esp+4h] [ebp-174Ch]
	int v329;                 // [esp+4h] [ebp-174Ch]
	int v330;                 // [esp+4h] [ebp-174Ch]
	int v331;                 // [esp+4h] [ebp-174Ch]
	float v332;               // [esp+4h] [ebp-174Ch]
	int v333;                 // [esp+4h] [ebp-174Ch]
	wchar_t* v334;            // [esp+4h] [ebp-174Ch]
	wchar_t* v335;            // [esp+4h] [ebp-174Ch]
	wchar_t* v336;            // [esp+4h] [ebp-174Ch]
	int v337;                 // [esp+4h] [ebp-174Ch]
	int v338;                 // [esp+4h] [ebp-174Ch]
	int v339;                 // [esp+4h] [ebp-174Ch]
	float v340;               // [esp+4h] [ebp-174Ch]
	int v341;                 // [esp+4h] [ebp-174Ch]
	char v342;                // [esp+4h] [ebp-174Ch]
	char* v343;               // [esp+4h] [ebp-174Ch]
	size_t v344;              // [esp+4h] [ebp-174Ch]
	int v345;                 // [esp+4h] [ebp-174Ch]
	char v346;                // [esp+4h] [ebp-174Ch]
	char v347;                // [esp+4h] [ebp-174Ch]
	int v348;                 // [esp+4h] [ebp-174Ch]
	int v349;                 // [esp+4h] [ebp-174Ch]
	int v350;                 // [esp+4h] [ebp-174Ch]
	int v351;                 // [esp+4h] [ebp-174Ch]
	int v352;                 // [esp+4h] [ebp-174Ch]
	int v353;                 // [esp+4h] [ebp-174Ch]
	wchar_t* v354;            // [esp+4h] [ebp-174Ch]
	BOOL v355;                // [esp+18h] [ebp-1738h]
	unsigned int v356;        // [esp+18h] [ebp-1738h]
	int v357;                 // [esp+18h] [ebp-1738h]
	int* v358;                // [esp+18h] [ebp-1738h]
	char v359;                // [esp+1Fh] [ebp-1731h]
	int v360;                 // [esp+20h] [ebp-1730h]
	int i;                    // [esp+24h] [ebp-172Ch]
	int v362;                 // [esp+28h] [ebp-1728h]
	int v363;                 // [esp+2Ch] [ebp-1724h]
	unsigned int v364;        // [esp+30h] [ebp-1720h]
	char v365[6];             // [esp+34h] [ebp-171Ch]
	char v366[5];             // [esp+3Ch] [ebp-1714h]
	int v367;                 // [esp+44h] [ebp-170Ch]
	int v368;                 // [esp+48h] [ebp-1708h]
	unsigned int v369;        // [esp+4Ch] [ebp-1704h]
	int v370;                 // [esp+50h] [ebp-1700h]
	int v371;                 // [esp+54h] [ebp-16FCh]
	int v372;                 // [esp+58h] [ebp-16F8h]
	unsigned int v373;        // [esp+5Ch] [ebp-16F4h]
	int v374;                 // [esp+60h] [ebp-16F0h]
	int v375;                 // [esp+64h] [ebp-16ECh]
	int v376;                 // [esp+68h] [ebp-16E8h]
	int2 v377;                // [esp+6Ch] [ebp-16E4h]
	int2 v378;                // [esp+74h] [ebp-16DCh]
	int2 v379;                // [esp+7Ch] [ebp-16D4h]
	int2 v380;                // [esp+84h] [ebp-16CCh]
	unsigned __int8 v381[20]; // [esp+8Ch] [ebp-16C4h]
	int v382[8];              // [esp+A0h] [ebp-16B0h]
	int v383[5];              // [esp+C0h] [ebp-1690h]
	int v384[2];              // [esp+D4h] [ebp-167Ch]
	char v385[20];            // [esp+DCh] [ebp-1674h]
	wchar_t v386[20];         // [esp+F0h] [ebp-1660h]
	wchar_t v387[20];         // [esp+118h] [ebp-1638h]
	wchar_t v388[64];         // [esp+140h] [ebp-1610h]
	wchar_t v389[128];        // [esp+1C0h] [ebp-1590h]
	wchar_t v390[128];        // [esp+2C0h] [ebp-1490h]
	wchar_t v391[128];        // [esp+3C0h] [ebp-1390h]
	wchar_t v392[128];        // [esp+4C0h] [ebp-1290h]
	wchar_t v393[128];        // [esp+5C0h] [ebp-1190h]
	wchar_t v394[128];        // [esp+6C0h] [ebp-1090h]
	wchar_t v395[64];         // [esp+7C0h] [ebp-F90h]
	wchar_t v396[64];         // [esp+840h] [ebp-F10h]
	wchar_t v397[100];        // [esp+8C0h] [ebp-E90h]
	wchar_t v398[128];        // [esp+988h] [ebp-DC8h]
	wchar_t v399[100];        // [esp+A88h] [ebp-CC8h]
	wchar_t v400[256];        // [esp+B50h] [ebp-C00h]
	wchar_t v401[128];        // [esp+D50h] [ebp-A00h]
	wchar_t v402[128];        // [esp+E50h] [ebp-900h]
	wchar_t v403[256];        // [esp+F50h] [ebp-800h]
	wchar_t v404[256];        // [esp+1150h] [ebp-600h]
	wchar_t v405[256];        // [esp+1350h] [ebp-400h]
	wchar_t v406[256];        // [esp+1550h] [ebp-200h]

	if (a3) {
		// dhexdump((_BYTE*)a2, a3);
	}

	v3 = a2;
	v4 = a3 + a2;
	v364 = 0;
	v369 = a3 + a2;
	sub_470A80();
	if (a2 >= a3 + a2)
		return 1;
	while (1) {
		v7 = *(_BYTE*)v3;
		LOBYTE(v375) = *(_BYTE*)v3;
		v8 = (unsigned __int8)v375;
		switch ((unsigned __int8)v375) {
		case 0x21u:
			break;
		case 0x27u:
		case 0x28u:
		case 0x2Au:
			v9 = 1;
			if (v7 == 40) {
				*(_DWORD*)&byte_5D4594[2598000] = *(_DWORD*)(v3 + 1);
				*(_DWORD*)&byte_5D4594[1200800] = *(_DWORD*)&byte_5D4594[2598000];
				v364 = *(_DWORD*)&byte_5D4594[2598000];
				*(_DWORD*)&byte_5D4594[1200808] = *(unsigned __int16*)&byte_5D4594[2598000] >> 14;
				if (*(_DWORD*)&byte_5D4594[2618908])
					sub_417530(*(int*)&byte_5D4594[2618908], 64);
				sub_43C650();
				v3 += 5;
				break;
			} else if (v7 != 39) {
				v14 = *(unsigned __int16*)(v373 + 1);
				if ((unsigned __int16)v14 <
				    (unsigned int)(*(_DWORD*)&byte_5D4594[1200800] + sub_43C790()))
					*(_DWORD*)&byte_5D4594[2598000] = v14;
				v3 += 5;
				break;
			}
			v373 = v3;
			if (*(_DWORD*)&byte_5D4594[2618908] && *(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 3680) & 0x40)
				return 1;
			v10 = *(_DWORD*)&byte_5D4594[2598000];
			v11 = *(_WORD*)(v3 + 1);
			v12 = v11 + (*(_DWORD*)&byte_5D4594[2598000] & 0xFFFF0000);
			v13 = v11 >> 14;
			if (v13 != *(_DWORD*)&byte_5D4594[1200808]) {
				if (v13 == ((byte_5D4594[1200808] + 1) & 3)) {
					*(_DWORD*)&byte_5D4594[1200808] = v13;
					if (!v13)
						v12 += 0x10000;
				} else {
					v9 = 0;
				}
			}
			if (v12 < *(int*)&byte_5D4594[2598000])
				v9 = 0;
			if (!nox_common_gameFlags_check_40A5C0(1) && v9 == 1) {
				*(_DWORD*)&byte_5D4594[2598000] = v12;
				*(_DWORD*)&byte_5D4594[1200800] = v12;
			}
			v364 = v12;
			if (!nox_common_gameFlags_check_40A5C0(1) && !v9) {
				--dword_5d4594_2618900;
				++*(_DWORD*)&byte_5D4594[2649824];
				return 1;
			}
			if (*(_DWORD*)&byte_5D4594[2598000] > (unsigned int)(v10 + 1))
				dword_5d4594_2618900 += *(_DWORD*)&byte_5D4594[2598000] - v10;
			sub_43C650();
			v3 += 3;
			break;
		case 0x2Bu:
			k = dword_5d4594_1200804;
			if (*(_DWORD*)(v3 + 37) > *(int*)&dword_5d4594_1200804) {
				sub_40A360(*(_DWORD*)(v3 + 37));
				sub_467DF0(1);
				sub_409D70((char*)(v3 + 1));
				sub_409B10(*(_DWORD*)(v3 + 33));
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					nox_common_gameFlags_unset_40A540(8);
					if (dword_5d4594_2650652)
						sub_41D6C0();
				}
				sub_40A4D0(0x800000);
				dword_5d4594_1200804 = *(_DWORD*)&byte_5D4594[2598000];
				sub_43C720(0);
				sub_49C7A0();
				sub_4597E0(0);
				sub_44A400();
				sub_413850();
			}
			v3 += 41;
			break;
		case 0x2Cu:
			v42 = sub_578B30(*(_WORD*)(v3 + 1));
			*(_DWORD*)&byte_5D4594[2616328] = v42;
			v43 = sub_416F60(v42);
			if (v43) {
				*((_DWORD*)v43 + 517) = *(_DWORD*)(v3 + 3);
				*(_DWORD*)&byte_5D4594[2618908] = v43;
			}
			if (!nox_common_gameFlags_check_40A5C0(1))
				sub_57B920(&byte_5D4594[1198020]);
			dword_5d4594_1200804 = 0;
			v3 += 7;
			dword_5d4594_2618900 = 0;
			*(_DWORD*)&byte_5D4594[2649824] = 0;
			dword_5d4594_2614264 = 0;
			*(_DWORD*)&byte_5D4594[1200832] = 0;
			sub_4169D0(0);
			break;
		case 0x2Du:
			v209 = sub_578B30(*(_WORD*)(v3 + 1));
			v210 = v209;
			v360 = v209;
			v211 = sub_416F60(v209);
			if (v211) {
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					*((_DWORD*)v211 + 515) = v210;
					*((_DWORD*)v211 + 534) = *(__int16*)(v3 + 100);
					*((_DWORD*)v211 + 535) = *(unsigned __int16*)(v3 + 102);
					*(_DWORD*)v211 = *(_DWORD*)(v3 + 104);
					*((_DWORD*)v211 + 1) = *(_DWORD*)(v3 + 108);
					*((_DWORD*)v211 + 538) = *(unsigned __int8*)(v3 + 116);
					*((_DWORD*)v211 + 539) = *(unsigned __int8*)(v3 + 117);
					strcpy(v211 + 2096, (const char*)(v3 + 119));
					*((_DWORD*)v211 + 920) |= *(_DWORD*)(v3 + 112);
					qmemcpy(v211 + 2185, (const void*)(v3 + 3), 0x61u);
					nox_swprintf((wchar_t*)v211 + 2352, L"%s%s", v211 + 2185, v211 + 2274);
					if (dword_5d4594_2650652) {
						*((_DWORD*)v211 + 527) = 0;
						sub_41D670((int)(v211 + 2096));
					}
					sub_461460((int)v211);
					v210 = v360;
				}
				v212 = (wchar_t*)(v211 + 4704);
				sub_457140(v210, v212);
				sub_455920((int)v212);
				v213 = loadString_sub_40F1D0((char*)&byte_587000[159072], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4661);
				nox_swprintf(v399, v213, v212);
				if (sub_4356B0() == 3)
					sub_445490(v399);
				if (v210 == *(_DWORD*)&byte_5D4594[2616328] &&
				    nox_wcscmp((const wchar_t*)&byte_5D4594[2661908], v212))
					*(_DWORD*)&byte_5D4594[1200832] = 1;
				OnLibraryNotice(263, v211);
			}
			v3 += 129;
			break;
		case 0x2Eu:
			if (nox_client_isConnected_43C700()) {
				v214 = sub_578B30(*(_WORD*)(v3 + 1));
				v215 = v214;
				v216 = sub_417040(v214);
				if (v216) {
					sub_456DF0(v215);
					sub_455950((wchar_t*)v216 + 2352);
					v217 =
					    loadString_sub_40F1D0((char*)&byte_587000[159128], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4744);
					nox_swprintf(v397, v217, v216 + 4704);
					*((_DWORD*)v216 + 523) = 0;
					v218 = sub_418C80(v215);
					v219 = (int)v218;
					OnLibraryNotice(264, v216 + 4704);
					if (v218 && sub_419130((int)v218))
						sub_419570(v219, v215);
				} else {
					v220 =
					    loadString_sub_40F1D0((char*)&byte_587000[159180], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4757);
					nox_swprintf(v397, v220);
				}
				if (sub_4356B0() == 3)
					sub_445490(v397);
			}
			v3 += 3;
			break;
		case 0x2Fu:
			sub_578B30(*(_WORD*)(v3 + 1));
			if (nox_client_isConnected_43C700()) {
				if (*(_DWORD*)&nox_common_engineFlags & 0x10000000)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 3), *(unsigned __int16*)(v3 + 1),
							 *(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
				if ((_DWORD)v5) {
					k = *(_DWORD*)&byte_5D4594[2598000];
					*(_DWORD*)(v5 + 288) = *(_DWORD*)&byte_5D4594[2598000];
				}
			}
			v3 += 9;
			break;
		case 0x30u:
			sub_578B30(*(_WORD*)(v3 + 1));
			if (!nox_client_isConnected_43C700()) {
				v3 += 11;
				break;
			}
			if (*(_DWORD*)&nox_common_engineFlags & 0x10000000)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (*(_WORD*)(v3 + 3) || *(_WORD*)(v3 + 1)) {
				LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 3), *(unsigned __int16*)(v3 + 1),
							 *(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
				v29 = v5;
				if ((_DWORD)v5) {
					*(_DWORD*)(v5 + 288) = *(_DWORD*)&byte_5D4594[2598000];
					sub_45AB80(v5, *(unsigned __int8*)(v3 + 10));
					LOBYTE(v5) = (*(_BYTE*)(v3 + 9) >> 4) & 7;
					*(_BYTE*)(v29 + 297) = v5;
					if ((unsigned __int8)v5 > 3u)
						*(_BYTE*)(v29 + 297) = v5 + 1;
					v30 = *(_BYTE*)(v3 + 9) & 0xF;
					*(_BYTE*)(v3 + 9) = v30;
					if (*(_DWORD*)(v29 + 276) != v30) {
						*(_DWORD*)(v29 + 316) = *(_DWORD*)&byte_5D4594[2598000];
						HIDWORD(v5) = *(unsigned __int8*)(v3 + 9);
						*(_DWORD*)(v29 + 276) = HIDWORD(v5);
					}
				}
				k = *(_DWORD*)&byte_5D4594[2616328];
				if (*(unsigned __int16*)(v3 + 1) == *(_DWORD*)&byte_5D4594[2616328] && sub_416120(9u))
					sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
			} else {
				sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
				sub_4160D0(9);
			}
			v3 += 11;
			break;
		case 0x31u:
			v44 = sub_578B30(*(_WORD*)(v3 + 1));
			v45 = v44;
			if (!nox_client_isConnected_43C700()) {
				v3 += 3;
				break;
			}
			if (*(_DWORD*)&nox_common_engineFlags & 0x10000000)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v45) : sub_45A6F0(v45);
			v46 = v5;
			if (!(_DWORD)v5) {
				v3 += 3;
				break;
			}
			if (*(int(__cdecl**)(int*, int))(v5 + 300) == nox_thing_animate_draw) {
				v47 = *(_DWORD*)(v5 + 304);
				if (v47) {
					if (*(_DWORD*)(v47 + 12) == 1) {
						v3 += 3;
						break;
					}
				}
			}
			v48 = sub_578B70(*(unsigned __int16*)(v3 + 1));
			v331 = v46;
			if (!v48)
				goto LABEL_210;
			sub_45A9A0(v46);
			v3 += 3;
			break;
		case 0x32u:
			v49 = sub_578B30(*(_WORD*)(v3 + 1));
			v50 = v49;
			if (!nox_client_isConnected_43C700()) {
				v3 += 3;
				break;
			}
			if (*(_DWORD*)&nox_common_engineFlags & 0x10000000)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v50) : sub_45A6F0(v50);
			v51 = v5;
			if (!(_DWORD)v5) {
				v3 += 3;
				break;
			}
			if (*(int(__cdecl**)(int*, int))(v5 + 300) == nox_thing_animate_draw) {
				v52 = *(_DWORD*)(v5 + 304);
				if (v52) {
					if (*(_DWORD*)(v52 + 12) == 1) {
						v3 += 3;
						break;
					}
				}
			}
			if (v51 == *(_DWORD*)&byte_5D4594[2614252]) {
				v3 += 3;
				break;
			}
			v53 = sub_578B70(*(unsigned __int16*)(v3 + 1));
			goto LABEL_208;
		case 0x33u:
			v54 = sub_578B30(*(_WORD*)(v3 + 1));
			v55 = v54;
			if (!nox_client_isConnected_43C700()) {
				v3 += 3;
				break;
			}
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v55) : sub_45A6F0(v55);
			v51 = v5;
			if (!(_DWORD)v5) {
				v3 += 3;
				break;
			}
			k = 1;
			*(_DWORD*)(v5 + 484) = 1;
			*(_DWORD*)(v5 + 480) = 1;
			*(_DWORD*)(v5 + 488) = 1;
			if (dword_587000_80836) {
				if ((_DWORD)v5 != *(_DWORD*)&byte_5D4594[2614252])
					sub_49B950((_DWORD*)v5, *(int*)&byte_5D4594[2649704]);
			} else if (*(int(__cdecl**)(int*, int))(v5 + 300) != nox_thing_animate_draw ||
				   (v56 = *(_DWORD*)(v5 + 304)) == 0 || *(_DWORD*)(v56 + 12) != 1) {
				if (v51 != *(_DWORD*)&byte_5D4594[2614252]) {
					v53 = sub_578B70(*(unsigned __int16*)(v3 + 1));
				LABEL_208:
					v331 = v51;
					if (v53)
						sub_45A9A0(v51);
					else
					LABEL_210:
						sub_45A4E0_drawable(v331);
				}
			}
			v3 += 3;
			break;
		case 0x34u:
			v57 = sub_578B30(*(_WORD*)(v3 + 1));
			v58 = v57;
			if (nox_client_isConnected_43C700())
				sub_4959F0(v58);
			v3 += 3;
			break;
		case 0x35u:
			v59 = sub_578B30(*(_WORD*)(v3 + 1));
			v60 = v59;
			if (nox_client_isConnected_43C700())
				sub_495A20(v60);
			v3 += 3;
			break;
		case 0x36u:
			if (nox_client_isConnected_43C700())
				sub_4959B0();
			++v3;
			break;
		case 0x37u:
			v62 = sub_578B30(*(_WORD*)(v3 + 1));
			v63 = v62;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
					LODWORD(v5) = sub_45A720(v63);
				else
					LODWORD(v5) = sub_45A6F0(v63);
				if ((_DWORD)v5)
					*(_DWORD*)(v5 + 120) |= 0x1000000u;
			}
			v3 += 3;
			break;
		case 0x38u:
			v64 = sub_578B30(*(_WORD*)(v3 + 1));
			v65 = v64;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
					LODWORD(v5) = sub_45A720(v65);
				else
					LODWORD(v5) = sub_45A6F0(v65);
				if ((_DWORD)v5) {
					if (*(_DWORD*)(v5 + 112) & 0x40000)
						*(_DWORD*)(v5 + 300) = 0;
					*(_DWORD*)(v5 + 120) &= 0xFEFFFFFF;
				}
			}
			v3 += 3;
			break;
		case 0x39u:
			v16 = sub_578B30(*(_WORD*)(v3 + 1));
			v17 = v16;
			if (!nox_client_isConnected_43C700())
				goto LABEL_764;
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v17) : sub_45A6F0(v17);
			if (!(_DWORD)v5)
				goto LABEL_764;
			sub_45AB80(v5, *(unsigned __int8*)(v3 + 3));
			v3 += 4;
			break;
		case 0x3Au:
			if (nox_client_isConnected_43C700() && !nox_common_gameFlags_check_40A5C0(1))
				sub_410520(*(_WORD*)(v3 + 1));
			v3 += 3;
			break;
		case 0x3Bu:
			if (nox_client_isConnected_43C700()) {
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					LODWORD(v5) = sub_410550(*(_WORD*)(v3 + 1));
					if ((_DWORD)v5) {
						if (*(_BYTE*)(v5 + 4) & 4) {
							v67 = *(_DWORD*)(v5 + 28);
							*(_BYTE*)(v67 + 22) = 23;
							*(_BYTE*)(v67 + 21) = 3;
						}
					}
				}
			}
			v3 += 3;
			break;
		case 0x3Cu:
			if (nox_client_isConnected_43C700()) {
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					LODWORD(v5) = sub_410550(*(_WORD*)(v3 + 1));
					if ((_DWORD)v5) {
						if (*(_BYTE*)(v5 + 4) & 4) {
							v68 = *(_DWORD*)(v5 + 28);
							if (v68) {
								*(_BYTE*)(v68 + 22) = 0;
								*(_BYTE*)(v68 + 21) = 1;
							}
						}
					}
				}
			}
			v3 += 3;
			break;
		case 0x3Du:
			if (!nox_client_isConnected_43C700())
				goto LABEL_916;
			LODWORD(v5) = nox_server_getWallAtPoint_410580(*(unsigned __int8*)(v3 + 4), *(unsigned __int8*)(v3 + 5));
			if (!(_DWORD)v5) {
				LODWORD(v5) = sub_410250(*(unsigned __int8*)(v3 + 4), *(unsigned __int8*)(v3 + 5));
				if (!(_DWORD)v5)
					goto LABEL_916;
			}
			v66 = *(_BYTE*)(v3 + 1);
			v3 += 6;
			*(_BYTE*)(v5 + 1) = v66;
			*(_BYTE*)v5 = *(_BYTE*)(v3 - 4);
			*(_BYTE*)(v5 + 2) = *(_BYTE*)(v3 - 3);
			break;
		case 0x3Eu:
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = nox_server_getWallAtPoint_410580(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
				if ((_DWORD)v5)
					sub_410430(*(unsigned __int8*)(v5 + 5), *(unsigned __int8*)(v5 + 6));
			}
			v3 += 3;
			break;
		case 0x41u:
			sub_578B30(*(_WORD*)(v3 + 1));
			if (!nox_client_isConnected_43C700())
				goto LABEL_764;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (!sub_4951F0(*(unsigned __int16*)(v3 + 1)))
				goto LABEL_764;
			sub_495150(*(unsigned __int16*)(v3 + 1), 2 * *(unsigned __int8*)(v3 + 3));
			v3 += 4;
			break;
		case 0x42u:
			sub_578B30(*(_WORD*)(v3 + 1));
			if (nox_client_isConnected_43C700() && (nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			sub_49A650(*(unsigned __int16*)(v3 + 1), *(_WORD*)(v3 + 3));
			v3 += 5;
			break;
		case 0x43u:
			if (nox_client_isConnected_43C700())
				sub_470CB0(*(__int16*)(v3 + 1));
			v3 += 3;
			break;
		case 0x44u:
			v92 = sub_578B30(*(_WORD*)(v3 + 1));
			v93 = v92;
			if (!nox_client_isConnected_43C700())
				goto LABEL_1149;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			sub_4675E0(v93, *(_WORD*)(v3 + 3), *(_WORD*)(v3 + 5));
			v3 += 7;
			break;
		case 0x45u:
			v96 = sub_578B30(*(_WORD*)(v3 + 1));
			v97 = v96;
			if (!nox_client_isConnected_43C700())
				goto LABEL_1163;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (v97 != *(_DWORD*)&byte_5D4594[2616328])
				goto LABEL_1163;
			sub_470D10(*(unsigned __int16*)(v3 + 3));
			v3 += 5;
			break;
		case 0x47u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_966;
			sub_470D20(*(unsigned __int8*)(v3 + 1), *(int*)&byte_587000[157092]);
			v3 += 2;
			break;
		case 0x48u:
			v98 = sub_578B30(*(_WORD*)(v3 + 1));
			v99 = *(_DWORD*)&byte_5D4594[2618908];
			v100 = v98;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				if (v100 == *(_DWORD*)&byte_5D4594[2616328]) {
					v101 = nox_common_gameFlags_check_40A5C0(1);
					if (!v101 && v99) {
						*(_DWORD*)(v99 + 2247) = *(unsigned __int16*)(v3 + 3);
						*(_DWORD*)(v99 + 2243) = *(unsigned __int16*)(v3 + 5);
						LOWORD(v101) = *(_WORD*)(v3 + 9);
						v332 = (double)v101;
						*(_DWORD*)(v99 + 2235) = nox_float2int(v332);
						*(_DWORD*)(v99 + 2239) = *(unsigned __int16*)(v3 + 11);
						*(_WORD*)(v99 + 3652) = *(_WORD*)(v3 + 7);
						*(_BYTE*)(v99 + 3684) = *(_BYTE*)(v3 + 13);
					}
					sub_467460();
				}
			}
			v3 += 14;
			break;
		case 0x49u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_1163;
			sub_467450(*(_DWORD*)(v3 + 1));
			v3 += 5;
			break;
		case 0x4Au:
			v102 = *(_DWORD*)(v3 + 1);
			if (!nox_client_isConnected_43C700())
				goto LABEL_1163;
			sub_467490(v102);
			v3 += 5;
			break;
		case 0x4Bu:
			v103 = sub_578B30(*(_WORD*)(v3 + 1));
			v104 = v103;
			if (!nox_client_isConnected_43C700())
				goto LABEL_1163;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			*(_DWORD*)v381 = 0;
			*(_WORD*)&v381[16] = -1;
			*(_DWORD*)&v381[4] = 0;
			*(_WORD*)&v381[18] = -1;
			*(_DWORD*)&v381[8] = 0;
			*(_DWORD*)&v381[12] = 0;
			if (sub_461660(v104, *(unsigned __int16*)(v3 + 3), v381))
				goto LABEL_1163;
			sub_461630(v104);
			v3 += 5;
			break;
		case 0x4Cu:
			v105 = sub_578B30(*(_WORD*)(v3 + 1));
			v106 = v105;
			if (!nox_client_isConnected_43C700())
				goto LABEL_735;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			v107 = 0;
			v108 = v385;
			do {
				*(_DWORD*)v108 = sub_413330(*(unsigned __int8*)(v107++ + v3 + 5));
				v108 += 4;
			} while (v107 < 4);
			*(_WORD*)&v385[16] = -1;
			*(_WORD*)&v385[18] = -1;
			if (sub_461660(v106, *(unsigned __int16*)(v3 + 3), v385))
				goto LABEL_735;
			sub_461630(v106);
			v3 += 9;
			break;
		case 0x4Du:
			v109 = sub_578B30(*(_WORD*)(v3 + 1));
			v110 = v109;
			if (!nox_client_isConnected_43C700())
				goto LABEL_1163;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			sub_461A80(v110);
			v3 += 5;
			break;
		case 0x4Eu:
			v124 = sub_578B30(*(_WORD*)(v3 + 1));
			v125 = v124;
			v126 = sub_416590(0);
			if (nox_client_isConnected_43C700()) {
				v127 = sub_417040(v125);
				if (v127) {
					if (!nox_common_gameFlags_check_40A5C0(1)) {
						*((_DWORD*)v127 + 534) = *(_DWORD*)(v3 + 3);
						*((_DWORD*)v127 + 535) = *(_DWORD*)(v3 + 7);
						*((_DWORD*)v127 + 536) = *(_DWORD*)&byte_5D4594[2598000];
					}
					if (nox_common_gameFlags_check_40A5C0(1024)) {
						k = *(_DWORD*)(v3 + 7);
						if (k >= *((unsigned __int16*)v126 + 27)) {
							v128 = loadString_sub_40F1D0(
							    (char*)&byte_587000[157264], 0,
							    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3452);
							nox_swprintf(v395, v128, v127 + 4704);
							sub_452D80(312, 100);
							sub_445490(v395);
						}
					}
				}
			}
			v3 += 11;
			break;
		case 0x4Fu:
		case 0x50u:
			LODWORD(v5) = nox_client_isConnected_43C700();
			if (!(_DWORD)v5)
				goto LABEL_442;
			LOWORD(v5) = *(_WORD*)(v3 + 1);
			v367 = -1;
			*(_WORD*)(v3 + 1) = v5 & 0x7FFF;
			if ((((unsigned int)v5 >> 15) & 1) == 1) {
				sub_417AA0(*(_BYTE*)v3, *(unsigned __int16*)(v3 + 1), *(_DWORD*)(v3 + 3), (int)&v367);
				v3 += 7;
			} else {
				sub_49A3D0(*(_BYTE*)v3, *(unsigned __int16*)(v3 + 1), *(_DWORD*)(v3 + 3), (int)&v367);
			LABEL_442:
				v3 += 7;
			}
			break;
		case 0x51u:
		case 0x52u:
			LODWORD(v5) = nox_client_isConnected_43C700();
			if (!(_DWORD)v5)
				goto LABEL_437;
			LOWORD(v5) = *(_WORD*)(v3 + 1);
			v116 = *(_DWORD*)(v3 + 3);
			v117 = v5;
			v118 = v5 & 0x7FFF;
			*(_WORD*)(v3 + 1) = v118;
			v333 = v3 + 7;
			if (((v117 >> 15) & 1) == 1) {
				sub_417AA0(*(_BYTE*)v3, v118, v116, v333);
				v3 += 11;
			} else {
				sub_49A3D0(*(_BYTE*)v3, v118, v116, v333);
			LABEL_437:
				v3 += 11;
			}
			break;
		case 0x53u:
		case 0x54u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_1149;
			sub_417B80(*(_BYTE*)v3, *(unsigned __int16*)(v3 + 1), *(_DWORD*)(v3 + 3));
			v3 += 7;
			break;
		case 0x55u:
			v140 = sub_578B30(*(_WORD*)(v3 + 1));
			v141 = v140;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				v142 = sub_417040(v141);
				if (v142) {
					if (!nox_common_gameFlags_check_40A5C0(1) &&
					    *(_DWORD*)&byte_5D4594[2598000] > *((_DWORD*)v142 + 540)) {
						HIWORD(v5) = 0;
						*((_DWORD*)v142 + 538) = *(unsigned __int16*)(v3 + 3);
						WORD2(v5) = *(_WORD*)(v3 + 5);
						*((_DWORD*)v142 + 539) = WORD2(v5);
						*((_DWORD*)v142 + 540) = *(_DWORD*)&byte_5D4594[2598000];
					}
					k = *((_DWORD*)v142 + 539) - 1;
					if (*((_DWORD*)v142 + 538) == k) {
						v143 = loadString_sub_40F1D0(
						    (char*)&byte_587000[157316], 0,
						    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3729);
						nox_swprintf(v406, v143, v142 + 4704);
						sub_445490(v406);
					}
				}
			}
			v3 += 7;
			break;
		case 0x56u:
			v144 = sub_418AB0(*(unsigned __int16*)(v3 + 1));
			if (!nox_client_isConnected_43C700())
				goto LABEL_602;
			HIDWORD(v5) = *(_DWORD*)(v3 + 4);
			if (HIDWORD(v5) <= *(int*)&dword_5d4594_1200804)
				goto LABEL_602;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			sub_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1))
				sub_40A4D0(8);
			sub_435570();
			if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000))
				sub_470510();
			v145 = sub_418C80(*(int*)&byte_5D4594[2616328]);
			if (v145 && sub_419180((int)v145, *(_BYTE*)(v3 + 1))) {
				v146 = loadString_sub_40F1D0((char*)&byte_587000[157372], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3776);
				nox_swprintf(v400, v146);
				v147 = 0;
			} else {
				v148 = loadString_sub_40F1D0((char*)&byte_587000[157420], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3781);
				nox_swprintf(v400, v148, v144);
				v149 = loadString_sub_40F1D0((char*)&byte_587000[157472], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3782);
				nox_swprintf(v400, v149, v400);
				v147 = 1;
			}
			sub_435700(v400, v147);
			sub_4597E0(0);
			v3 += 8;
			break;
		case 0x57u:
			v172 = sub_418AB0(*(unsigned __int16*)(v3 + 1));
			if (!nox_client_isConnected_43C700())
				goto LABEL_602;
			k = dword_5d4594_1200804;
			if (*(_DWORD*)(v3 + 4) <= *(int*)&dword_5d4594_1200804)
				goto LABEL_602;
			v393[0] = 0;
			if (*(_BYTE*)(v3 + 3) == 1) {
				v173 = loadString_sub_40F1D0((char*)&byte_587000[158612], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4055);
				nox_swprintf(v393, v173);
			}
			sub_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1))
				sub_40A4D0(8);
			sub_435570();
			if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000))
				sub_470510();
			v174 = sub_418C80(*(int*)&byte_5D4594[2616328]);
			if (v172) {
				v175 = loadString_sub_40F1D0((char*)&byte_587000[158672], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4071);
				nox_swprintf(v398, v175, v172);
				if (!v174 || !sub_419180((int)v174, v172[57])) {
					v176 = 1;
					goto LABEL_600;
				}
			} else {
				v177 = loadString_sub_40F1D0((char*)&byte_587000[158724], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4083);
				nox_swprintf(v398, v177);
			}
			v176 = 0;
		LABEL_600:
			nox_wcscat(v393, v398);
			sub_435700(v393, v176);
			goto LABEL_601;
		case 0x58u:
			v150 = 1;
			v389[0] = 0;
			v392[0] = 0;
			v391[0] = 0;
			if (!nox_client_isConnected_43C700())
				goto LABEL_602;
			HIDWORD(v5) = *(_DWORD*)(v3 + 4);
			if (HIDWORD(v5) <= *(int*)&dword_5d4594_1200804)
				goto LABEL_602;
			v391[0] = 0;
			if (*(_BYTE*)(v3 + 3) == 1) {
				v151 = loadString_sub_40F1D0((char*)&byte_587000[157524], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3823);
				nox_swprintf(v391, v151);
			}
			sub_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1))
				sub_40A4D0(8);
			if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000))
				sub_470510();
			sub_435570();
			if (*(_WORD*)(v3 + 1)) {
				v152 = sub_578B30(*(_WORD*)(v3 + 1));
				v372 = v152;
			}
			v153 = v372;
			v154 = sub_417040(v372);
			if (!nox_common_gameFlags_check_40A5C0(1024)) {
				if (*(_WORD*)(v3 + 1)) {
					if (!v154)
						goto LABEL_559;
					if (!*(_BYTE*)(v3 + 3))
						sub_4947E0((int)v154);
					if (v153 != *(_DWORD*)&byte_5D4594[2616328]) {
						v159 = loadString_sub_40F1D0(
						    (char*)&byte_587000[157884], 0,
						    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3899);
						nox_swprintf(v389, v159, v154 + 4704);
						v150 = 1;
						goto LABEL_559;
					}
					if (!v154[2252]) {
						v314 = loadString_sub_40F1D0(
						    (char*)&byte_587000[157932], 0,
						    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3905);
						nox_swprintf(v389, v314);
						goto LABEL_558;
					}
					v155 =
					    loadString_sub_40F1D0((char*)&byte_587000[157988], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3907);
				} else {
					v155 =
					    loadString_sub_40F1D0((char*)&byte_587000[157836], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3884);
				}
			LABEL_557:
				nox_swprintf(v389, v155);
				goto LABEL_558;
			}
			if (!*(_WORD*)(v3 + 1)) {
				v155 = loadString_sub_40F1D0((char*)&byte_587000[157584], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3847);
				goto LABEL_557;
			}
			v156 = loadString_sub_40F1D0((char*)&byte_587000[157632], 0,
						     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3852);
			nox_swprintf(v389, v156);
			if (v153 == *(_DWORD*)&byte_5D4594[2616328]) {
				v334 = loadString_sub_40F1D0((char*)&byte_587000[157684], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3855);
				v157 = loadString_sub_40F1D0((char*)&byte_587000[157732], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3855);
				nox_swprintf(v392, v157, v334);
				nox_wcscat(v389, v392);
			LABEL_558:
				v150 = 0;
				goto LABEL_559;
			}
			if (v154) {
				v158 = loadString_sub_40F1D0((char*)&byte_587000[157784], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3863);
				nox_swprintf(v392, v158, v154 + 4704);
				if (!*(_BYTE*)(v3 + 3))
					sub_4947E0((int)v154);
			}
			nox_wcscat(v389, v392);
			v150 = 1;
		LABEL_559:
			nox_wcscat(v391, v389);
			sub_435700(v391, v150);
		LABEL_601:
			sub_4597E0(0);
		LABEL_602:
			v3 += 8;
			break;
		case 0x59u:
			v160 = sub_418AB0(*(unsigned __int16*)(v3 + 1));
			if (!nox_client_isConnected_43C700())
				goto LABEL_602;
			k = dword_5d4594_1200804;
			if (*(_DWORD*)(v3 + 4) <= *(int*)&dword_5d4594_1200804)
				goto LABEL_602;
			v394[0] = 0;
			if (*(_BYTE*)(v3 + 3) == 1) {
				v161 = loadString_sub_40F1D0((char*)&byte_587000[158048], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3945);
				nox_swprintf(v394, v161);
			}
			sub_452D80(309, 100);
			if (!nox_common_gameFlags_check_40A5C0(1))
				sub_40A4D0(8);
			sub_435570();
			if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000))
				sub_470510();
			v162 = sub_418C80(*(int*)&byte_5D4594[2616328]);
			if (nox_common_gameFlags_check_40A5C0(1024)) {
				if (!v160) {
					v163 =
					    loadString_sub_40F1D0((char*)&byte_587000[158108], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3964);
					nox_swprintf(v390, v163);
					v164 = 0;
					goto LABEL_585;
				}
				v165 = loadString_sub_40F1D0((char*)&byte_587000[158156], 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3969);
				nox_swprintf(v390, v165);
				if (v162 && sub_419180((int)v162, v160[57])) {
					v335 =
					    loadString_sub_40F1D0((char*)&byte_587000[158208], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3973);
					v166 =
					    loadString_sub_40F1D0((char*)&byte_587000[158260], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3973);
					nox_swprintf(v388, v166, v335);
					nox_wcscat(v390, v388);
					v164 = 0;
				} else {
					v336 =
					    loadString_sub_40F1D0((char*)&byte_587000[158312], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3980);
					v167 =
					    loadString_sub_40F1D0((char*)&byte_587000[158360], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3980);
					nox_swprintf(v388, v167, v336);
					nox_swprintf(v396, v388, v160);
					nox_wcscat(v390, v396);
					v164 = 1;
				}
				if (!*(_BYTE*)(v3 + 3))
					goto LABEL_584;
			} else {
				if (!v160) {
					v168 =
					    loadString_sub_40F1D0((char*)&byte_587000[158412], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 3999);
					nox_swprintf(v390, v168);
					v164 = 0;
					goto LABEL_585;
				}
				if (v162 && sub_419180((int)v162, v160[57])) {
					v169 =
					    loadString_sub_40F1D0((char*)&byte_587000[158460], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4006);
					nox_swprintf(v390, v169);
					v164 = 0;
				} else {
					v170 =
					    loadString_sub_40F1D0((char*)&byte_587000[158516], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4011);
					nox_swprintf(v388, v170, v160);
					v171 =
					    loadString_sub_40F1D0((char*)&byte_587000[158564], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4012);
					nox_swprintf(v390, v171, v388);
					v164 = 1;
				}
				if (!*(_BYTE*)(v3 + 3)) {
				LABEL_584:
					sub_4948B0((int)v160);
					goto LABEL_585;
				}
			}
		LABEL_585:
			nox_wcscat(v394, v390);
			sub_435700(v394, v164);
			goto LABEL_601;
		case 0x5Au:
			v132 = sub_578B30(*(_WORD*)(v3 + 1));
			v133 = v132;
			if (!nox_client_isConnected_43C700())
				goto LABEL_1149;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v133) : sub_45A6F0(v133);
			v134 = v5;
			if (!(_DWORD)v5)
				goto LABEL_1149;
			LODWORD(v5) = sub_4356C0(v5, 15);
			HIDWORD(v5) = *(_DWORD*)(v3 + 3);
			v135 = v5;
			*(_DWORD*)(v134 + 124) = HIDWORD(v5);
			if (v134 == *(_DWORD*)&byte_5D4594[2614252])
				sub_467410(*(_DWORD*)(v3 + 3));
			if (v135 != 1 || sub_4356C0(v134, 15) ||
			    v134 == *(_DWORD*)&byte_5D4594[2614252] && sub_467430() & 8)
				goto LABEL_1149;
			nox_thing* v136 = nox_get_thing(*(_DWORD*)(v134 + 108));
			sub_484D70_light_intensity(v134 + 136, v136->light_intensity);
			v3 += 7;
			break;
		case 0x5Bu:
			if (nox_client_isConnected_43C700()) {
				LOBYTE(v129) = sub_467430();
				v130 = (v129 >> 3) & 1;
				sub_467420(*(_BYTE*)(v3 + 1));
				if (v130 == 1 && !(sub_467430() & 8) && *(_DWORD*)&byte_5D4594[2614252] &&
				    !sub_4356C0(*(int*)&byte_5D4594[2614252], 15)) {
					nox_thing* v131 =
					    nox_get_thing(*(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 108));
					sub_484D70_light_intensity(*(_DWORD*)&byte_5D4594[2614252] + 136,
								   v131->light_intensity);
				}
			}
			v3 += 2;
			break;
		case 0x5Cu:
			v88 = sub_578B30(*(_WORD*)(v3 + 1));
			v89 = v88;
			if (!nox_client_isConnected_43C700())
				goto LABEL_902;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v89) : sub_45A6F0(v89);
			if ((_DWORD)v5) {
				sub_484BE0((_DWORD*)(v5 + 136), *(unsigned __int8*)(v3 + 3),
					   *(unsigned __int8*)(v3 + 4), *(unsigned __int8*)(v3 + 5));
				v3 += 6;
			} else {
			LABEL_902:
				v3 += 6;
			}
			break;
		case 0x5Du:
			v84 = sub_578B30(*(_WORD*)(v3 + 1));
			v85 = v84;
			if (!nox_client_isConnected_43C700())
				goto LABEL_948;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v85) : sub_45A6F0(v85);
			if (!(_DWORD)v5)
				goto LABEL_948;
			sub_484D70_light_intensity(v5 + 136, *(float*)(v3 + 3));
			v3 += 7;
			break;
		case 0x5Eu:
			v178 = sub_578B30(*(_WORD*)(v3 + 1));
			v179 = v178;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) =
				    sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v179) : sub_45A6F0(v179);
				if ((_DWORD)v5) {
					WORD2(v5) = *(unsigned __int8*)(v3 + 3);
					*(_WORD*)(v5 + 104) = WORD2(v5);
				}
			}
			v3 += 4;
			break;
		case 0x5Fu:
			v180 = sub_578B30(*(_WORD*)(v3 + 1));
			v181 = v180;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) =
				    sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v181) : sub_45A6F0(v181);
				if ((_DWORD)v5) {
					WORD2(v5) = *(unsigned __int8*)(v3 + 3);
					HIDWORD(v5) = -HIDWORD(v5);
					*(_WORD*)(v5 + 104) = WORD2(v5);
				}
			}
			v3 += 4;
			break;
		case 0x60u:
			v120 = sub_578B30(*(_WORD*)(v3 + 1));
			v121 = v120;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				sub_462040(v121);
			}
			v3 += 3;
			break;
		case 0x61u:
			v122 = sub_578B30(*(_WORD*)(v3 + 1));
			v123 = v122;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				sub_4624D0(v123);
			}
			v3 += 3;
			break;
		case 0x64u:
			v182 = sub_578B30(*(_WORD*)(v3 + 1));
			v183 = v182;
			if (!nox_client_isConnected_43C700())
				goto LABEL_638;
			sub_467930(v183, *(unsigned __int8*)(v3 + 3), *(unsigned __int8*)(v3 + 4));
			v3 += 5;
			break;
		case 0x65u:
			v71 = sub_578B30(*(_WORD*)(v3 + 1));
			v72 = v71;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
					LODWORD(v5) = sub_45A720(v72);
				else
					LODWORD(v5) = sub_45A6F0(v72);
				v73 = (_DWORD*)v5;
				if ((_DWORD)v5) {
					v74 = *(_DWORD*)(v5 + 280);
					v73[70] = *(_DWORD*)(v3 + 3);
					k = v73[28];
					if (k & 0x20000) {
						if (!(v74 & 0x400)) {
							HIDWORD(v5) = v73[70] & 0x400;
							if (HIDWORD(v5) == 1024)
								sub_4BC720((int)v73);
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
			v3 += 7;
			break;
		case 0x66u:
			if (nox_client_isConnected_43C700() && *(_DWORD*)&byte_5D4594[2614252]) {
				HIDWORD(v5) = *(_DWORD*)(v3 + 1);
				*(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 120) = HIDWORD(v5);
			}
			v3 += 5;
			break;
		case 0x67u:
			v77 = sub_578B30(*(_WORD*)(v3 + 1));
			v78 = v77;
			if (nox_client_isConnected_43C700()) {
				if ((nox_common_engineFlags & 0x8000) != 0)
					sub_578B70(*(unsigned __int16*)(v3 + 1));
				if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
					LODWORD(v5) = sub_45A720(v78);
				else
					LODWORD(v5) = sub_45A6F0(v78);
				if ((_DWORD)v5) {
					v79 = v5 + 432;
					if ((_DWORD)v5 != (_DWORD)-432) {
						v80 = 0;
						v81 = (int*)(v5 + 432);
						do {
							*v81 = sub_413330(*(unsigned __int8*)(v80++ + v3 + 3));
							++v81;
						} while (v80 < 4);
						*(_WORD*)(v79 + 16) = -1;
						*(_WORD*)(v79 + 18) = -1;
					}
				}
			}
			v3 += 7;
			break;
		case 0x68u:
			v82 = sub_578B30(*(_WORD*)(v3 + 1));
			v83 = v82;
			if (!nox_client_isConnected_43C700())
				goto LABEL_1057;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (v83 == *(_DWORD*)&byte_5D4594[2616328]) {
				LOBYTE(k) = *(_BYTE*)(v3 + 7);
				sub_467470(k, *(float*)(v3 + 3));
				v3 += 8;
			} else {
			LABEL_1057:
				v3 += 8;
			}
			break;
		case 0x69u:
			if (nox_client_isConnected_43C700()) {
				v285 = *(_WORD*)(v3 + 1);
				v286 = v285;
				v285 &= 0x7FFFu;
				*(_WORD*)(v3 + 1) = v285;
				v287 = v286 >> 15;
				v288 = nox_npc_by_id(v285);
				if (v288) {
					LODWORD(v5) = nox_init_npc(v288, *(unsigned __int16*)(v3 + 1));
				} else {
					LODWORD(v5) = nox_new_npc(*(unsigned __int16*)(v3 + 1));
					v288 = (char*)v5;
				}
				if (v288) {
					k = (int)(v288 + 8);
					v289 = (_BYTE*)(v3 + 4);
					v358 = (int*)(v288 + 8);
					v360 = 6;
					do {
						BYTE4(v5) = v289[1];
						LOBYTE(v5) = *v289;
						LOBYTE(k) = *(v289 - 1);
						v289 += 3;
						*v358 = sub_4344A0(k, v5, SHIDWORD(v5));
						k = (int)(v358 + 1);
						LODWORD(v5) = v360 - 1;
						v250 = v360 == 1;
						++v358;
						--v360;
					} while (!v250);
					*((_DWORD*)v288 + 328) = v287;
				}
			}
			v3 += 21;
			break;
		case 0x6Au:
			v119 = sub_417040(*(unsigned __int16*)(v3 + 1));
			if (!v119)
				goto LABEL_1070;
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				sub_417530((int)v119, 1059);
				sub_4174F0((int)v119, *(_DWORD*)(v3 + 3) & 0x423);
			}
			if (*(_DWORD*)&nox_common_engineFlags & 0x40000 ||
			    (HIDWORD(v5) = *(unsigned __int16*)(v3 + 1),
			     WORD2(v5) != *(_DWORD*)&byte_5D4594[2616328])) {
			LABEL_1070:
				v3 += 7;
			} else {
				if (v119[3680] & 1) {
					dword_587000_80828 = 0;
				} else if (dword_587000_80832 == 1) {
					dword_587000_80828 = 1;
				}
				sub_470C40((*((_DWORD*)v119 + 920) >> 10) & 1);
				v3 += 7;
			}
			break;
		case 0x6Bu:
			v69 = sub_578B30(*(_WORD*)(v3 + 1));
			v70 = v69;
			if (!nox_client_isConnected_43C700())
				goto LABEL_948;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v70) : sub_45A6F0(v70);
			if (!(_DWORD)v5)
				goto LABEL_948;
			sub_45AB80(v5, *(_DWORD*)(v3 + 3));
			v3 += 7;
			break;
		case 0x6Cu:
			v184 = sub_578B30(*(_WORD*)(v3 + 1));
			v185 = v184;
			if (!nox_client_isConnected_43C700())
				goto LABEL_638;
			v186 = *(_WORD*)(v3 + 3);
			v187 = v186;
			v186 &= 0x7FFFu;
			*(_WORD*)(v3 + 3) = v186;
			sub_4C2E50(*(unsigned __int16*)(v3 + 1), v186, v187 & 0x8000);
			if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
				v188 = sub_45A720(v185);
			else
				v188 = sub_45A6F0(v185);
			if (v188 || (v188 = sub_48E970(*(unsigned __int16*)(v3 + 3), v185, 0, 0)) != 0)
				sub_459DD0((int)v188, 1);
			sub_495060(*(unsigned __int16*)(v3 + 1), 0, 0);
			v3 += 5;
			break;
		case 0x6Du:
			v189 = sub_578B30(*(_WORD*)(v3 + 1));
			v190 = v189;
			if (!nox_client_isConnected_43C700()) {
				v3 += 3;
				break;
			}
			v191 = *(_WORD*)(v3 + 1);
			v192 = v191;
			v191 &= 0x7FFFu;
			*(_WORD*)(v3 + 1) = v191;
			sub_4C3140(v191, (void*)(v192 & 0x8000));
			sub_4950C0(*(unsigned __int16*)(v3 + 1));
			v337 = v190;
			if (!sub_578B70(*(unsigned __int16*)(v3 + 1)))
				goto LABEL_642;
			LODWORD(v5) = sub_45A720(v190);
			goto LABEL_643;
		case 0x6Eu:
			if (!nox_client_isConnected_43C700())
				goto LABEL_1163;
			sub_467440(*(_DWORD*)(v3 + 1));
			v3 += 5;
			break;
		case 0x6Fu:
			v139 = 0;
			if (nox_client_isConnected_43C700()) {
				if (*(_BYTE*)(v3 + 3) & 0x80)
					v139 = 1;
				sub_45CFE0(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2),
					   *(_BYTE*)(v3 + 3) & 0x7F, v139);
			}
			v3 += 4;
			break;
		case 0x70u:
			sub_49BB80(*(_BYTE*)(v3 + 1));
			v3 += 2;
			break;
		case 0x71u:
			sub_467CA0();
			++v3;
			break;
		case 0x7Cu:
			v236 = sub_578B30(*(_WORD*)(v3 + 8));
			v237 = v236;
			if (nox_client_isConnected_43C700()) {
				if (sub_578B70(*(unsigned __int16*)(v3 + 8)))
					v238 = sub_45A720(v237);
				else
					v238 = sub_45A6F0(v237);
				HIWORD(k) = 0;
				v382[0] = (int)v238;
				LOWORD(k) = *(_WORD*)(v3 + 2);
				HIWORD(v5) = 0;
				v382[5] = (unsigned __int16)k;
				WORD2(v5) = *(_WORD*)(v3 + 4);
				v382[6] = WORD2(v5);
				v382[7] = *(unsigned __int16*)(v3 + 6);
				switch (*(unsigned __int8*)(v3 + 1)) {
				case 0u:
					sub_4AEEA0((unsigned __int8**)v382);
					break;
				case 1u:
					sub_4AEF80(v382);
					break;
				case 2u:
					sub_4AF0F0((unsigned __int8**)v382);
					break;
				case 3u:
					sub_4AF2A0((unsigned __int8**)v382);
					break;
				case 4u:
					sub_4AF3D0(v382);
					break;
				case 5u:
					sub_4AF450(v382);
					break;
				case 6u:
					sub_4AF5A0(v382);
					break;
				}
			}
			v3 += 14;
			break;
		case 0x7Du:
		case 0x8Cu:
		case 0x8Du:
		case 0x8Eu:
			if (!nox_client_isConnected_43C700())
				goto LABEL_732;
			sub_49BDD0((unsigned __int8*)v3);
			HIWORD(k) = 0;
			v379.field_0 = *(unsigned __int16*)(v3 + 1);
			v379.field_4 = *(unsigned __int16*)(v3 + 3);
			LOWORD(k) = *(_WORD*)(v3 + 5);
			HIWORD(v5) = 0;
			v377.field_0 = (unsigned __int16)k;
			WORD2(v5) = *(_WORD*)(v3 + 7);
			v377.field_4 = WORD2(v5);
			LOBYTE(v5) = *(_BYTE*)v3;
			if (*(_BYTE*)v3 == (_BYTE)-116 || (_BYTE)v5 == (_BYTE)-114) {
				sub_4999D0(*(int*)&dword_5d4594_1200776, &v379, &v377);
			} else if ((_BYTE)v5 == 125) {
				sub_499710(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7), 10,
					   *(int*)&dword_5d4594_1200776);
				v3 += 9;
				break;
			}
		LABEL_732:
			v3 += 9;
			break;
		case 0x7Eu:
			if (nox_client_isConnected_43C700()) {
				sub_4B7C40(*(_WORD*)(v3 + 5), (unsigned __int16*)(v3 + 1), *(_WORD*)(v3 + 7),
					   *(_BYTE*)(v3 + 9), *(_WORD*)(v3 + 10));
				v3 += 12;
			} else {
			LABEL_1130:
				v3 += 12;
			}
			break;
		case 0x7Fu:
			if (nox_client_isConnected_43C700())
				sub_4B7EE0(*(_WORD*)(v3 + 1));
			v3 += 3;
			break;
		case 0x80u:
			if (nox_client_isConnected_43C700())
				sub_4B8090(*(unsigned __int16*)(v3 + 1), *(unsigned __int8*)(v3 + 3));
			goto LABEL_764;
		case 0x81u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_797;
			sub_499610(*(int*)&dword_5d4594_1200776, 50, 1000, 30, *(__int16*)(v3 + 1),
				   *(__int16*)(v3 + 3));
			v3 += 5;
			break;
		case 0x82u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_797;
			sub_499610(*(int*)&byte_5D4594[1200780], 25, 500, 25, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
			v3 += 5;
			break;
		case 0x83u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_797;
			sub_499610(*(int*)&byte_5D4594[1200784], 25, 500, 25, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
			v3 += 5;
			break;
		case 0x84u:
			if (nox_client_isConnected_43C700())
				sub_499610(*(int*)&dword_5d4594_1200796, 25, 500, 25, *(__int16*)(v3 + 1),
					   *(__int16*)(v3 + 3));
		LABEL_797:
			v3 += 5;
			break;
		case 0x85u:
		case 0x86u:
		case 0x87u:
		case 0x88u:
		case 0x89u:
		case 0x8Au:
		case 0x8Bu:
		case 0xA3u:
			if (nox_client_isConnected_43C700()) {
				k = 0;
				switch (v8) {
				case 133:
					v257 = *(_DWORD*)&byte_5D4594[1200872];
					if (!*(_DWORD*)&byte_5D4594[1200872]) {
						v257 = sub_44CFC0((CHAR*)&byte_587000[160152]);
						*(_DWORD*)&byte_5D4594[1200872] = v257;
					}
					v258 = *(__int16*)(v3 + 3);
					goto LABEL_858;
				case 134:
					v257 = *(_DWORD*)&byte_5D4594[1200876];
					if (!*(_DWORD*)&byte_5D4594[1200876]) {
						v257 = sub_44CFC0((CHAR*)&byte_587000[160164]);
						*(_DWORD*)&byte_5D4594[1200876] = v257;
					}
					v258 = *(__int16*)(v3 + 3);
					goto LABEL_858;
				case 135:
					v257 = *(_DWORD*)&byte_5D4594[1200880];
					if (!*(_DWORD*)&byte_5D4594[1200880]) {
						v257 = sub_44CFC0((CHAR*)&byte_587000[160180]);
						*(_DWORD*)&byte_5D4594[1200880] = v257;
					}
					v258 = *(__int16*)(v3 + 3);
					goto LABEL_858;
				case 136:
					v257 = *(_DWORD*)&byte_5D4594[1200884];
					if (!*(_DWORD*)&byte_5D4594[1200884]) {
						v257 = sub_44CFC0((CHAR*)&byte_587000[160200]);
						*(_DWORD*)&byte_5D4594[1200884] = v257;
					}
					v258 = *(__int16*)(v3 + 3);
					goto LABEL_858;
				case 137:
					v257 = *(_DWORD*)&byte_5D4594[1200888];
					if (!*(_DWORD*)&byte_5D4594[1200888]) {
						v257 = sub_44CFC0((CHAR*)&byte_587000[160216]);
						*(_DWORD*)&byte_5D4594[1200888] = v257;
					}
					goto LABEL_857;
				case 138:
					if (!*(_DWORD*)&byte_5D4594[1200900]) {
						*(_DWORD*)&byte_5D4594[1200900] =
						    sub_44CFC0((CHAR*)&byte_587000[160244]);
						*(_DWORD*)&byte_5D4594[1200896] =
						    sub_44CFC0((CHAR*)&byte_587000[160252]);
					}
					v259 = sub_45A360_drawable(*(int*)&byte_5D4594[1200900], *(__int16*)(v3 + 1),
								   *(__int16*)(v3 + 3));
					if (v259) {
						*(_WORD*)(v259 + 104) = 20;
						sub_45A110_drawable((_DWORD*)v259);
					}
					v260 = 6;
					do {
						v341 = *(__int16*)(v3 + 3) +
						       sub_415FF0(-15, 15,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5711);
						v261 = sub_415FF0(-15, 15,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5710);
						v262 = sub_45A360_drawable(*(int*)&byte_5D4594[1200896],
									   *(__int16*)(v3 + 1) + v261, v341);
						if (v262) {
							*(_WORD*)(v262 + 104) = sub_415FF0(
							    5, 25, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5712);
							sub_45A110_drawable((_DWORD*)v262);
						}
						--v260;
					} while (v260);
					goto LABEL_868;
				case 139:
					v257 = *(_DWORD*)&byte_5D4594[1200892];
					if (!*(_DWORD*)&byte_5D4594[1200892]) {
						v257 = sub_44CFC0((CHAR*)&byte_587000[160232]);
						*(_DWORD*)&byte_5D4594[1200892] = v257;
					}
				LABEL_857:
					v258 = *(__int16*)(v3 + 3) + 2;
				LABEL_858:
					LODWORD(v5) = sub_45A360_drawable(v257, *(__int16*)(v3 + 1), v258);
					if (!(_DWORD)v5)
						goto LABEL_868;
					sub_45A110_drawable((_DWORD*)v5);
					v3 += 5;
					break;
				case 163:
					v340 = sub_419D40(&byte_587000[159972]);
					v252 = nox_float2int(v340);
					v357 = 150;
					v253 = v252 >> 2;
					for (i = v252 >> 2;; v253 = i) {
						v254 = v253 + sub_415FF0(0, v252,
									 "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
									 5536);
						if (v254 > (int)v252)
							v254 = v252;
						v255 = sub_415FF0(0, 255,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5541);
						LODWORD(v5) = sub_45A360_drawable(
						    *(int*)&byte_5D4594[1200784],
						    *(__int16*)(v3 + 1) +
							v254 * *(int*)&byte_587000[8 * v255 + 192088] / 16,
						    *(__int16*)(v3 + 3) +
							v254 * *(int*)&byte_587000[8 * v255 + 192092] / 16);
						v256 = v5;
						if ((_DWORD)v5) {
							*(_DWORD*)(v5 + 432) = *(_DWORD*)(v5 + 12) << 12;
							*(_DWORD*)(v5 + 436) = *(_DWORD*)(v5 + 16) << 12;
							*(_BYTE*)(v5 + 299) = 0;
							*(_DWORD*)(v5 + 440) = 0;
							*(_DWORD*)(v5 + 448) =
							    *(_DWORD*)&byte_5D4594[2598000] +
							    sub_415FF0(30, 40,
								       "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
								       5562);
							*(_DWORD*)(v256 + 444) = *(_DWORD*)&byte_5D4594[2598000];
							*(_WORD*)(v256 + 104) = 0;
							*(_BYTE*)(v256 + 296) = sub_415FF0(
							    4, 10, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5568);
							sub_45A110_drawable((_DWORD*)v256);
						}
						if (!--v357)
							break;
					}
					v3 += 5;
					break;
				default:
					goto LABEL_868;
				}
			} else {
			LABEL_868:
				v3 += 5;
			}
			break;
		case 0x8Fu:
		case 0x90u:
		case 0x91u:
			if (nox_client_isConnected_43C700())
				sub_49BDD0((unsigned __int8*)v3);
		LABEL_735:
			v3 += 9;
			break;
		case 0x93u:
			if (!*(_DWORD*)&byte_5D4594[1200852]) {
				*(_DWORD*)&byte_5D4594[1200852] = sub_44CFC0((CHAR*)&byte_587000[159532]);
				*(_DWORD*)&byte_5D4594[1200856] = sub_44CFC0((CHAR*)&byte_587000[159540]);
				*(_DWORD*)&byte_5D4594[1197380] = sub_44CFC0((CHAR*)&byte_587000[159556]);
			}
			if (!nox_client_isConnected_43C700())
				goto LABEL_916;
			v378.field_0 = *(__int16*)(v3 + 1);
			v378.field_4 = *(__int16*)(v3 + 3);
			sub_49A150(&v378, *(int*)&byte_5D4594[1200852], *(_BYTE*)(v3 + 5));
			v235 = *(_DWORD*)&byte_5D4594[1197380];
			if (*(_BYTE*)(v3 + 5) <= 0xAAu)
				v235 = *(_DWORD*)&byte_5D4594[1200856];
			LODWORD(v5) = sub_45A360_drawable(v235, *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
			goto LABEL_829;
		case 0x94u:
			if (nox_client_isConnected_43C700()) {
				v241 = *(unsigned __int16*)(v3 + 5) - *(unsigned __int16*)(v3 + 1);
				v242 = *(unsigned __int16*)(v3 + 7) - *(unsigned __int16*)(v3 + 3);
				LODWORD(v5) = nox_double2int(sqrt((double)(v241 * v241 + v242 * v242))) + 1;
				v371 = v5;
				if ((int)v5 >= 0) {
					v360 = 0;
					v363 = 0;
					i = 2 * v242;
					v374 = 2 * v241;
					v356 = (unsigned int)(v5 + 2) >> 1;
					do {
						v243 = *(unsigned __int16*)(v3 + 1) + v363 / v371;
						v244 = *(unsigned __int16*)(v3 + 3) + v360 / v371;
						v245 = sub_45A360_drawable(*(int*)&dword_5d4594_1200796, v243, v244);
						v362 = v245;
						if (v245) {
							v246 = (_DWORD*)(v245 + 432);
							if (v245 != -432) {
								*(_DWORD*)(v245 + 432) = v243 << 12;
								*(_DWORD*)(v245 + 436) = v244 << 12;
								v247 = sub_415FF0(
								    0, 255,
								    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
								    5393);
								*(_BYTE*)(v362 + 299) = v247;
								v246[2] = sub_415FF0(
								    1, 200,
								    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
								    5396);
								v246[4] =
								    *(_DWORD*)&byte_5D4594[2598000] +
								    sub_415FF0(
									20, 40,
									"C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
									5399);
								v246[3] = *(_DWORD*)&byte_5D4594[2598000];
							}
							v248 = sub_415FF0(
							    15, 30, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5405);
							v249 = v362;
							*(_WORD*)(v362 + 104) = v248;
							*(_BYTE*)(v249 + 296) = sub_415FF0(
							    -4, 4, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5406);
							sub_45A110_drawable((_DWORD*)v249);
						}
						k = i;
						HIDWORD(v5) = i + v360;
						v250 = v356 == 1;
						v363 += v374;
						v360 += i;
						--v356;
					} while (!v250);
				}
			}
			v3 += 9;
			break;
		case 0x95u:
			if (nox_client_isConnected_43C700()) {
				sub_4C5020(v3);
				if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4987) < 25) {
					if (*(_DWORD*)&byte_5D4594[2614252]) {
						v225 = *(unsigned __int16*)(v3 + 5) -
						       *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 12);
						v226 = nox_double2int(sqrt(
						    (double)(v225 * v225 +
							     (*(unsigned __int16*)(v3 + 7) -
							      *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 16)) *
								 (*(unsigned __int16*)(v3 + 7) -
								  *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 16)))));
						if (v226 < 600)
							sub_452D80(297, 100 * (600 - v226) / 600);
					}
				}
				if (!sub_413A50()) {
					v227 = *(unsigned __int16*)(v3 + 5) - *(unsigned __int16*)(v3 + 1);
					v228 = *(unsigned __int16*)(v3 + 7) - *(unsigned __int16*)(v3 + 3);
					v229 = nox_double2int(sqrt((double)(v227 * v227 + v228 * v228)));
					if (!v229)
						v229 = 1;
					v230 = *(unsigned __int16*)(v3 + 5) - 4 * v227 / v229;
					v231 = *(unsigned __int16*)(v3 + 7) - 4 * v228 / v229;
					LODWORD(v5) = sub_45A360_drawable(*(int*)&dword_5d4594_1200796, v230, v231);
					v362 = v5;
					if ((_DWORD)v5) {
						v232 = (_DWORD*)(v5 + 432);
						if ((_DWORD)v5 != (_DWORD)-432) {
							*(_DWORD*)(v5 + 432) = v230 << 12;
							*(_DWORD*)(v5 + 436) = v231 << 12;
							v233 = sub_415FF0(
							    0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5024);
							*(_BYTE*)(v362 + 299) = v233;
							v232[2] = sub_415FF0(
							    1, 1500, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5027);
							v232[4] =
							    *(_DWORD*)&byte_5D4594[2598000] +
							    sub_415FF0(5, 20,
								       "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
								       5030);
							v232[3] = *(_DWORD*)&byte_5D4594[2598000];
						}
						v234 = v362;
						*(_WORD*)(v362 + 104) = 22;
						*(_BYTE*)(v234 + 296) = sub_415FF0(
						    -4, 4, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5037);
						sub_45A110_drawable((_DWORD*)v234);
					}
				}
			}
			v3 += 9;
			break;
		case 0x96u:
			if (nox_client_isConnected_43C700()) {
				if (!*(_DWORD*)&byte_5D4594[1200860])
					*(_DWORD*)&byte_5D4594[1200860] = sub_44CFC0((CHAR*)&byte_587000[159568]);
				v239 = 5;
				do {
					LODWORD(v5) = sub_45A360_drawable(*(int*)&byte_5D4594[1200860],
									  *(__int16*)(v3 + 1), *(__int16*)(v3 + 3));
					v240 = v5;
					if ((_DWORD)v5) {
						if ((_DWORD)v5 != (_DWORD)-432) {
							*(_DWORD*)(v5 + 432) = *(_DWORD*)(v5 + 12) << 12;
							*(_DWORD*)(v5 + 436) = *(_DWORD*)(v5 + 16) << 12;
							*(_BYTE*)(v5 + 299) = sub_415FF0(
							    0, 255, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5338);
							*(_DWORD*)(v240 + 440) = sub_415FF0(
							    1333, 4000, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
							    5341);
							*(_DWORD*)(v240 + 448) =
							    *(_DWORD*)&byte_5D4594[2598000] +
							    sub_415FF0(5, 20,
								       "C:\\NoxPost\\src\\Client\\Network\\cdecode.c",
								       5344);
							*(_DWORD*)(v240 + 444) = *(_DWORD*)&byte_5D4594[2598000];
						}
						*(_WORD*)(v240 + 104) = 20;
						*(_BYTE*)(v240 + 296) = sub_415FF0(
						    -5, 5, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 5351);
						sub_45A110_drawable((_DWORD*)v240);
					}
					--v239;
				} while (v239);
			}
			v3 += 5;
			break;
		case 0x97u:
			if (nox_client_isConnected_43C700())
				sub_4355B0(*(unsigned __int8*)(v3 + 1) / 3);
			v3 += 2;
			break;
		case 0x98u:
			if (!*(_DWORD*)&byte_5D4594[1200844])
				*(_DWORD*)&byte_5D4594[1200844] = sub_44CFC0((CHAR*)&byte_587000[159192]);
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) =
				    sub_45A360_drawable(
					*(int*)&byte_5D4594[1200844],
					*(unsigned __int16*)(v3 + 1) +
					    (*(unsigned __int16*)(v3 + 5) - *(unsigned __int16*)(v3 + 1)) / 2,
					*(unsigned __int16*)(v3 + 3) +
					    (*(unsigned __int16*)(v3 + 7) - *(unsigned __int16*)(v3 + 3)) / 2) +
				    432;
				*(_BYTE*)v5 = 0;
				*(_DWORD*)(v5 + 5) = *(_DWORD*)(v3 + 1);
				HIDWORD(v5) = *(_DWORD*)(v3 + 5);
				*(_DWORD*)(v5 + 9) = HIDWORD(v5);
				k = *(unsigned __int16*)(v3 + 9);
				*(_DWORD*)(v5 + 1) = k;
			}
			v3 += 11;
			break;
		case 0x9Au:
			if (nox_client_isConnected_43C700())
				sub_473920();
			v3 += 5;
			break;
		case 0x9Bu:
		case 0x9Cu:
		case 0x9Du:
			if (nox_client_isConnected_43C700())
				sub_4A9D00((unsigned __int8*)v3);
			v3 += 3;
			break;
		case 0x9Eu:
			LOBYTE(v376) = *(_BYTE*)(v3 + 1);
			switch ((unsigned __int8)v376) {
			case 1u:
			case 2u:
			case 3u:
			case 4u:
			case 5u:
			case 6u:
			case 7u:
				if (nox_client_isConnected_43C700())
					sub_49C160(v3);
				goto LABEL_1070;
			case 8u:
			case 9u:
			case 0xAu:
			case 0xBu:
			case 0xCu:
			case 0xDu:
			case 0xEu:
				if (!nox_client_isConnected_43C700())
					goto LABEL_1070;
				sub_49C450(v3);
				v3 += 7;
				break;
			default:
				return 0;
			}
			break;
		case 0x9Fu:
			v297 = sub_578B30(*(_WORD*)(v3 + 1));
			v298 = v297;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) =
				    sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v298) : sub_45A6F0(v298);
				if ((_DWORD)v5) {
					LODWORD(v5) = v5 + 432;
					*(_DWORD*)v5 = *(_DWORD*)&byte_5D4594[2598000];
					i = *(char*)(v3 + 4);
					*(float*)(v5 + 8) = (double)i;
					k = *(unsigned __int8*)(v3 + 3);
					i = *(unsigned __int8*)(v3 + 3);
					*(float*)(v5 + 4) = (double)i;
					HIDWORD(v5) = *(unsigned __int8*)(v3 + 5);
					i = *(unsigned __int8*)(v3 + 5);
					*(float*)(v5 + 12) = (double)i;
				}
			}
			v3 += 6;
			break;
		case 0xA0u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_1163;
			sub_499880((__int16*)(v3 + 1));
			v3 += 5;
			break;
		case 0xA1u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_916;
			if (!*(_DWORD*)&byte_5D4594[1200864]) {
				*(_DWORD*)&byte_5D4594[1200864] = sub_44CFC0((CHAR*)&byte_587000[159940]);
				*(_DWORD*)&byte_5D4594[1200868] = sub_44CFC0((CHAR*)&byte_587000[159956]);
			}
			v251 = *(__int16*)(v3 + 1);
			v339 = *(__int16*)(v3 + 3);
			if (*(_BYTE*)(v3 + 5) == 1) {
				LODWORD(v5) = sub_45A360_drawable(*(int*)&byte_5D4594[1200864], v251 + 15, v339);
				if ((_DWORD)v5) {
					sub_45A110_drawable((_DWORD*)v5);
					v3 += 6;
					break;
				}
			} else {
				LODWORD(v5) = sub_45A360_drawable(*(int*)&byte_5D4594[1200868], v251 - 3, v339);
			LABEL_829:
				if ((_DWORD)v5) {
					sub_45A110_drawable((_DWORD*)v5);
					v3 += 6;
					break;
				}
			}
		LABEL_916:
			v3 += 6;
			break;
		case 0xA2u:
			if (nox_client_isConnected_43C700()) {
				if (!*(_DWORD*)&byte_5D4594[1200848])
					*(_DWORD*)&byte_5D4594[1200848] = sub_44CFC0((CHAR*)&byte_587000[159204]);
				v221 = *(unsigned __int16*)(v3 + 9);
				k = v221 & 0xFFFC;
				if (k <= 28)
					v222 = v221 >> 2;
				else
					v222 = 7;
				v223 = v222 + 1;
				if (v222 + 1 > 0) {
					do {
						LOBYTE(v368) = sub_415FF0(
						    6, 12, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4957);
						v323 = v368;
						v318 = sub_415FF0(-20, 20,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4961);
						v224 = sub_415FF0(-20, 20,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4960);
						sub_499490(*(int*)&byte_5D4594[1200848], (_WORD*)(v3 + 1), v224, v318,
							   v323, 0);
						--v223;
					} while (v223);
				}
			}
			v3 += 11;
			break;
		case 0xA4u:
			v15 = (unsigned __int8*)(sub_494A60((unsigned __int8*)(v3 + 1), a1, v384) + v3 + 1);
			if ((unsigned int)v15 >= v4)
				return 1;
			while (1) {
				LODWORD(v5) = sub_494C30(v15, a1, v384);
				if ((int)v5 <= 0)
					break;
				v15 += v5;
				if ((unsigned int)v15 >= v4)
					return 1;
			}
			if ((int)v5 < 0)
				LODWORD(v5) = -(int)v5;
			v3 = (unsigned int)&v15[v5];
			break;
		case 0xA6u:
		case 0xA7u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_651;
			v338 = *(char*)(v3 + 1);
			v321 = (*(unsigned __int16*)(v3 + 2) >> 9) & 0x7E;
			v317 = *(_WORD*)(v3 + 2) & 0x3FF;
			if (*(char*)v3 == -89) {
				sub_452E10(v317, v321, v338);
				v3 += 4;
			} else {
				sub_452DC0(v317, v321, v338);
			LABEL_651:
				v3 += 4;
			}
			break;
		case 0xA8u:
			v198 = sub_578B30(*(_WORD*)(v3 + 1));
			v199 = v198;
			memset(&byte_5D4594[1197384], 0, 0x27Cu);
			v200 = *(unsigned __int8*)(v3 + 3);
			if (v200 & 8) {
				v201 = loadString_sub_40F1D0((char*)(v3 + 11), 0,
							     "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4486);
				nox_wcscpy((wchar_t*)&byte_5D4594[1197384], v201);
				v202 = 1;
			} else if (v200 & 2) {
				if (v200 & 1) {
					v203 =
					    loadString_sub_40F1D0((char*)&byte_587000[158812], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4493);
					nox_swprintf((wchar_t*)&byte_5D4594[1197384], L"%s: %S", v203, v3 + 11);
				} else {
					nox_swprintf((wchar_t*)&byte_5D4594[1197384], L"%S", v3 + 11);
				}
				v202 = 1;
			} else {
				if (v200 & 1) {
					v204 =
					    loadString_sub_40F1D0((char*)&byte_587000[158892], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4506);
					nox_swprintf((wchar_t*)&byte_5D4594[1197384], L"%s: %s", v204, v3 + 11);
				} else {
					nox_wcscpy((wchar_t*)&byte_5D4594[1197384], (const wchar_t*)(v3 + 11));
				}
				v202 = 2;
			}
			if (!nox_client_isConnected_43C700())
				goto LABEL_693;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (*(_BYTE*)(v3 + 3) & 0x10) {
				if (sub_4356B0() == 3) {
					nox_wcscpy((wchar_t*)&byte_5D4594[1200068],
						   (const wchar_t*)&byte_5D4594[1197384]);
					v205 =
					    loadString_sub_40F1D0((char*)&byte_587000[158964], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 4536);
					sub_449A10(0, (int)v205, (int)&byte_5D4594[1200068], 33, 0, 0);
					k = v202 * *(unsigned __int8*)(v3 + 8);
					v3 += k + 11;
					break;
				}
			} else if (*(_WORD*)(v3 + 1)) {
				if (sub_4356B0() == 3) {
					v206 = sub_417040(*(unsigned __int16*)(v3 + 1));
					v207 = v206;
					if (v206) {
						if (!sub_57A160((int)v206)) {
							sub_450C00(0xFu, (wchar_t*)&byte_587000[158984], v207 + 4704,
								   &byte_5D4594[1197384]);
							sub_48D880(v3, (wchar_t*)&byte_5D4594[1197384]);
							k = v202 * *(unsigned __int8*)(v3 + 8);
							v3 += k + 11;
							break;
						}
					} else {
						sub_48D880(v3, (wchar_t*)&byte_5D4594[1197384]);
						if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
							LODWORD(v5) = sub_45A720(v199);
						else
							LODWORD(v5) = sub_45A6F0(v199);
						if ((_DWORD)v5) {
							v322 = *(unsigned __int16*)(v3 + 1);
							v208 = nox_get_thing_pretty_name(*(_DWORD*)(v5 + 108));
							sub_450C00(6u, (wchar_t*)&byte_587000[159000], v208, v322,
								   &byte_5D4594[1197384]);
						}
					}
				}
			} else if (sub_4356B0() == 3) {
				sub_445490((wchar_t*)&byte_5D4594[1197384]);
				k = v202 * *(unsigned __int8*)(v3 + 8);
				v3 += k + 11;
				break;
			}
		LABEL_693:
			k = v202 * *(unsigned __int8*)(v3 + 8);
			v3 += k + 11;
			break;
		case 0xA9u:
			v3 += sub_4C9BF0(v3);
			break;
		case 0xAAu:
			v61 = nox_common_gameFlags_check_40A5C0(1) ? 5 : 1;
			if (nox_client_isConnected_43C700()) {
				v366[0] = -85;
				if (nox_common_gameFlags_check_40A5C0(1))
					*(_DWORD*)&v366[1] = *(_DWORD*)(v3 + 1);
				else
					*(_DWORD*)&v366[1] = v364;
				sub_40EBC0(a1, 0, v366, 5);
			}
			v3 += v61;
			break;
		case 0xABu:
			if (nox_client_isConnected_43C700()) {
				sub_4E55A0(a1, *(_DWORD*)(v3 + 1));
			}
			v3 += 5;
			break;
		case 0xAEu:
			v3 += 3;
			break;
		case 0xAFu:
			dword_5d4594_1200768 = 0;
			v34 = *(_DWORD*)(v3 + 1);
			if (sub_40A350() < v34) {
				sub_40A340(v34);
				nox_common_gameFlags_check_40A5C0(1024);
				v355 = nox_common_gameFlags_check_40A5C0(32);
				v360 = nox_common_gameFlags_check_40A5C0(32);
				v363 = nox_common_gameFlags_check_40A5C0(4096);
				if (!nox_common_gameFlags_check_40A5C0(1)) {
					nox_common_gameFlags_unset_40A540(524272);
					sub_40A4D0(*(_DWORD*)(v3 + 9));
					sub_409E40(*(_DWORD*)(v3 + 13));
					sub_409AE0(*(_DWORD*)(v3 + 5));
					sub_409F80(*(unsigned __int8*)(v3 + 17));
					v35 = sub_416590(0);
					if (v35[56] != *(_BYTE*)(v3 + 19) ||
					    *((_WORD*)v35 + 27) != *(unsigned __int8*)(v3 + 18))
						dword_5d4594_1200768 = 1;
					*((_WORD*)v35 + 27) = *(unsigned __int8*)(v3 + 18);
					v35[56] = *(_BYTE*)(v3 + 19);
					if ((signed char)*(_BYTE*)(v3 + 9) >= 0) {
						*((_WORD*)v35 + 26) = *(_WORD*)(v3 + 9);
						strcpy(v35, sub_409B40());
					}
					if (v355 || !nox_common_gameFlags_check_40A5C0(32)) {
						if (!nox_common_gameFlags_check_40A5C0(32))
							sub_455C10();
					} else {
						sub_455A50(2);
					}
					if (v360 || !nox_common_gameFlags_check_40A5C0(64)) {
						if (!nox_common_gameFlags_check_40A5C0(64))
							sub_456050();
					} else {
						sub_455F60();
					}
					if (v363 == 1 && !nox_common_gameFlags_check_40A5C0(4096)) {
						for (j = sub_416EA0(); j; j = sub_416EE0((int)j))
							sub_417680((int)j, 255);
					}
					if (!nox_common_gameFlags_check_40A5C0(0x20000) && sub_4356B0() == 3) {
						sub_43DDD0(0);
						sub_43DE60();
					}
				}
			}
			v3 += 20;
			break;
		case 0xB0u:
			if (!nox_common_gameFlags_check_40A5C0(1)) {
				v37 = sub_416590(0);
				strncpy(v37 + 9, (const char*)(v3 + 1), 0xFu);
				if (memcmp(&byte_5D4594[1200732], (const void*)(v3 + 17), 0x14u))
					dword_5d4594_1200768 = 1;
				if (*(_DWORD*)&byte_5D4594[1200752] != *(_DWORD*)(v3 + 37) ||
				    *(_DWORD*)&byte_5D4594[1200756] != *(_DWORD*)(v3 + 41)) {
					dword_5d4594_1200768 = 1;
				}
				qmemcpy(v37 + 24, (const void*)(v3 + 17), 0x14u);
				sub_4540E0((int)(v37 + 24));
				*((_DWORD*)v37 + 11) = *(_DWORD*)(v3 + 37);
				*((_DWORD*)v37 + 12) = *(_DWORD*)(v3 + 41);
				if (*(_DWORD*)(v3 + 45)) {
					sub_40A1F0(1);
					sub_40A310(*(_DWORD*)(v3 + 45));
				} else {
					sub_40A1F0(0);
				}
				qmemcpy(&byte_5D4594[1200708], v37, 0x3Au);
				if (nox_client_isConnected_43C700() && dword_5d4594_1200768) {
					v38 =
					    loadString_sub_40F1D0((char*)&byte_587000[157156], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 1429);
					sub_445490(v38);
					sub_452D80(310, 100);
				}
			}
			v3 += 49;
			break;
		case 0xB1u:
			v39 = sub_416590(*(unsigned __int8*)(v3 + 1));
			LOBYTE(v40) = v39[52];
			LOBYTE(v4) = *(_BYTE*)(v3 + 54);
			qmemcpy(v39, (const void*)(v3 + 2), 0x3Au);
			if (((v40 >> 5) & 1) != ((v4 >> 5) & 1))
				sub_4573A0();
			if (!sub_4169C0()) {
				if (!sub_459DA0()) {
					if (*(_BYTE*)(v3 + 1) == 1)
						sub_4165F0(1, 0);
					if (nox_common_gameFlags_check_40A5C0(128)) {
						if (*(_DWORD*)&byte_5D4594[1200832]) {
							v330 = *(_DWORD*)&byte_5D4594[2618908] + 4704;
							v41 = loadString_sub_40F1D0(
							    (char*)&byte_587000[157212], 0,
							    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 1470);
							nox_swprintf(v401, v41, v330);
							sub_445490(v401);
							*(_DWORD*)&byte_5D4594[1200832] = 0;
						}
						if (dword_587000_54276)
							sub_49C560();
					}
				}
				sub_4169D0(1);
			}
			sub_459C30();
			v3 += 60;
			break;
		case 0xB2u:
			v18 = sub_578B30(*(_WORD*)(v3 + 1));
			v19 = v18;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) =
				    sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v19) : sub_45A6F0(v19);
				if ((_DWORD)v5)
					*(_BYTE*)(v5 + 299) = *(_BYTE*)(v3 + 3);
			}
			v3 += 4;
			break;
		case 0xB3u:
			v20 = sub_578B30(*(_WORD*)(v3 + 1));
			v21 = v20;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) =
				    sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v21) : sub_45A6F0(v21);
				v22 = v5;
				if ((_DWORD)v5) {
					sub_45A990_drawable(v5);
					v328 = (double)(16 * *(unsigned __int8*)(v3 + 3) / 10);
					sub_484D70_light_intensity(v22 + 136, v328);
					sub_45AB80(v22, 8 * *(unsigned __int8*)(v3 + 3) / 50);
					if (*(_DWORD*)(v22 + 308) == 8)
						*(_DWORD*)(v22 + 308) = 7;
				}
			}
			v3 += 4;
			break;
		case 0xB4u:
			v24 = sub_578B30(*(_WORD*)(v3 + 1));
			v25 = v24;
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) =
				    sub_578B70(*(unsigned __int16*)(v3 + 1)) ? sub_45A720(v25) : sub_45A6F0(v25);
				v26 = v5;
				if ((_DWORD)v5) {
					if (*(_BYTE*)(v3 + 3)) {
						*(_DWORD*)(v5 + 112) |= 0x80000u;
						sub_484D70_light_intensity(v5 + 136, 41.958);
					} else {
						*(_DWORD*)(v5 + 112) &= 0xFFF7FFFF;
						sub_484D70_light_intensity(v5 + 136, 0.0);
					}
					sub_45AB80(v26, *(unsigned __int8*)(v3 + 3));
					*(_DWORD*)(v26 + 288) = *(_DWORD*)&byte_5D4594[2598000];
				}
			}
			v3 += 4;
			break;
		case 0xB5u:
			if (nox_client_isConnected_43C700() &&
			    (v329 = *(unsigned __int16*)(v3 + 7), v320 = *(unsigned __int16*)(v3 + 5),
			     v31 = sub_578B30(*(_WORD*)(v3 + 1)),
			     LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 3), v31, v320, v329), (_DWORD)v5)) {
				*(_WORD*)(v5 + 508) = *(_WORD*)(v3 + 9);
				*(float*)(v5 + 468) = (double)*(char*)(v3 + 12) * 0.0625;
				*(float*)(v5 + 472) = (double)*(char*)(v3 + 13) * 0.0625;
				*(float*)(v5 + 476) = (double)*(char*)(v3 + 11) * 0.0625;
				*(_DWORD*)(v5 + 316) = *(_DWORD*)&byte_5D4594[2598000];
				*(_DWORD*)(v5 + 324) = *(unsigned __int16*)(v3 + 5);
				v32 = *(unsigned __int16*)(v3 + 7);
				*(_DWORD*)(v5 + 460) = sub_4CA540;
				*(_DWORD*)(v5 + 328) = v32;
				sub_49BC80_drawable((_DWORD*)v5);
			}
			v3 += 14;
			break;
		case 0xB8u:
			if (!sub_4ABAD0((char*)(v3 + 8), *(_DWORD*)(v3 + 4))) {
				sub_43CAB0();
				sub_4AB560(0);
				sub_4AB570(0);
			}
			v3 += 88;
			break;
		case 0xB9u:
			sub_4AB7C0(*(_WORD*)(v3 + 2), (void*)(v3 + 6), *(unsigned __int16*)(v3 + 4));
			k = *(unsigned __int16*)(v3 + 4);
			v3 += k + 6;
			break;
		case 0xBAu:
			sub_4AB720();
			sub_4AB560(0);
			sub_4AB570(0);
			v3 += 2;
			break;
		case 0xBDu:
			if (nox_client_isConnected_43C700()) {
				if (*(_BYTE*)(v3 + 1) == 1)
					v290 =
					    loadString_sub_40F1D0((char*)&byte_587000[160420], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 6351);
				else
					v290 =
					    loadString_sub_40F1D0((char*)&byte_587000[160472], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 6356);
				sub_450C00(6u, v290);
			}
			v3 += 2;
			break;
		case 0xC2u:
			v263 = *(unsigned __int8*)(v3 + 1);
			switch (v263) {
			case 0:
				v342 = *(_BYTE*)(v3 + 136);
				v324 = *(_DWORD*)(v3 + 4);
				v315 = *(_BYTE*)(v3 + 2);
				v264 = sub_43C750();
				sub_40B5D0(v264, v315, (const char*)(v3 + 8), v324, v342);
				v3 += 140;
				break;
			case 1:
				BYTE4(v5) = *(_BYTE*)(v3 + 3);
				v343 = (char*)HIDWORD(v5);
				v325 = *(_BYTE*)(v3 + 2);
				v265 = sub_43C750();
				sub_40BFF0(v265, v325, v343);
				v3 += 4;
				break;
			case 2:
				v365[0] = -62;
				v365[1] = 3;
				v365[2] = *(_BYTE*)(v3 + 2);
				*(_WORD*)&v365[4] = *(_WORD*)(v3 + 4);
				v266 = sub_43C750();
				sub_552640(v266, v365, 6, 3);
				v344 = *(unsigned __int16*)(v3 + 6);
				v319 = *(_WORD*)(v3 + 4);
				v316 = *(_BYTE*)(v3 + 2);
				v267 = sub_43C750();
				sub_40B250(v267, v316, v319, (const void*)(v3 + 8), v344);
				HIDWORD(v5) = *(unsigned __int16*)(v3 + 6);
				v3 += WORD2(v5) + 8;
				break;
			case 3:
				v345 = *(unsigned __int16*)(v3 + 4);
				v326 = *(_BYTE*)(v3 + 2);
				v268 = sub_43C750();
				sub_40BF60(v268, v326, v345);
				v3 += 6;
				break;
			case 4:
				v346 = *(_BYTE*)(v3 + 2);
				v269 = sub_43C750();
				sub_40C030(v269, v346);
				v3 += 3;
				break;
			case 5:
				LOBYTE(k) = *(_BYTE*)(v3 + 3);
				sub_40B720(k, *(_BYTE*)(v3 + 2));
				v3 += 4;
				break;
			case 6:
				LOBYTE(v263) = *(_BYTE*)(v3 + 3);
				v347 = *(_BYTE*)(v3 + 2);
				v327 = v263;
				v270 = sub_43C750();
				sub_40C070(v270, v327, v347);
				v3 += 4;
				break;
			default:
				return 0;
			}
			break;
		case 0xC3u:
			sub_578B30(*(_WORD*)(v3 + 1));
			if (*(_DWORD*)&nox_common_engineFlags & 0x10000000)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (*(_WORD*)(v3 + 3) || *(_WORD*)(v3 + 1)) {
				v27 = sub_48E970(*(unsigned __int16*)(v3 + 3), *(unsigned __int16*)(v3 + 1),
						 *(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
				if (v27) {
					v27[72] = *(_DWORD*)&byte_5D4594[2598000];
					sub_45AB80((int)v27, *(unsigned __int8*)(v3 + 10));
					v28 = (*(_BYTE*)(v3 + 9) >> 4) & 7;
					*((_BYTE*)v27 + 297) = v28;
					if (v28 > 3u)
						*((_BYTE*)v27 + 297) = v28 + 1;
					if (v27[69] != *(unsigned __int8*)(v3 + 11)) {
						v27[79] = *(_DWORD*)&byte_5D4594[2598000];
						k = *(unsigned __int8*)(v3 + 11);
						v27[69] = k;
					}
				}
				HIDWORD(v5) = *(unsigned __int16*)(v3 + 1);
				if (WORD2(v5) == *(_DWORD*)&byte_5D4594[2616328] && sub_416120(8u))
					sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
				v3 += 12;
			} else {
				sub_435600(*(unsigned __int16*)(v3 + 5), *(unsigned __int16*)(v3 + 7));
				sub_4160D0(8);
				v3 += 12;
			}
			break;
		case 0xC4u:
			switch (*(unsigned __int8*)(v3 + 1)) {
			case 0u:
				if (!nox_client_isConnected_43C700())
					goto LABEL_888;
				qmemcpy(v386, (const void*)(v3 + 18), 2 * *(unsigned __int8*)(v3 + 15));
				v386[*(unsigned __int8*)(v3 + 15)] = 0;
				if (*(_BYTE*)(v3 + 17)) {
					v271 = sub_418C20(*(unsigned __int8*)(v3 + 16));
					nox_swprintf(v386, v271);
				}
				v272 = sub_418AB0(*(_DWORD*)(v3 + 2));
				if (!v272) {
					v272 = sub_4186D0(*(_BYTE*)(v3 + 2));
					if (!v272)
						goto LABEL_888;
				}
				sub_418800((wchar_t*)v272, v386, 0);
				sub_418830((int)v272, *(_DWORD*)(v3 + 6));
				sub_419090((int)v272, *(_DWORD*)(v3 + 10));
				v272[56] = *(_BYTE*)(v3 + 16);
				sub_457230(v386);
				if (!(*(_BYTE*)(v3 + 14) & 1))
					goto LABEL_888;
				v273 = sub_418C80(*(int*)&byte_5D4594[2616328]);
				if (!v273)
					goto LABEL_888;
				if (nox_common_gameFlags_check_40A5C0(1)) {
					sub_4191D0(v272[57], (int)v273, 1, *(int*)&byte_5D4594[2616328], 1);
					HIDWORD(v5) = *(unsigned __int8*)(v3 + 15);
					v3 += 2 * HIDWORD(v5) + 18;
				} else {
					sub_419900((int)v272, (int)v273, *(__int16*)&byte_5D4594[2616328]);
				LABEL_888:
					HIDWORD(v5) = *(unsigned __int8*)(v3 + 15);
					v3 += 2 * HIDWORD(v5) + 18;
				}
				break;
			case 1u:
				v274 = sub_578B30(*(_WORD*)(v3 + 6));
				v275 = v274;
				if (nox_client_isConnected_43C700()) {
					if (sub_578B70(*(unsigned __int16*)(v3 + 6)))
						LODWORD(v5) = sub_45A720(v275);
					else
						LODWORD(v5) = sub_45A6F0(v275);
					if (!(_DWORD)v5)
						LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 8), v275, 0, 0);
					v276 = v5 + 24;
					if ((_DWORD)v5 != (_DWORD)-24) {
						LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
						v277 = v5;
						if ((_DWORD)v5) {
							sub_4191D0(*(_BYTE*)(v5 + 57), v276, 0,
								   *(unsigned __int16*)(v3 + 6), 0);
							sub_4571A0(*(unsigned __int16*)(v3 + 6),
								   *(unsigned __int8*)(v277 + 57));
						}
					}
				}
				v3 += 10;
				break;
			case 2u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_418C80(*(_DWORD*)(v3 + 2));
					if ((_DWORD)v5) {
						sub_419570(v5, *(_DWORD*)(v3 + 2));
						sub_4571A0(*(_DWORD*)(v3 + 2), 0);
					}
				}
				goto LABEL_902;
			case 3u:
				if (nox_client_isConnected_43C700()) {
					v278 = sub_418C80(*(unsigned __int16*)(v3 + 6));
					if (v278) {
						LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
						v279 = v5;
						if ((_DWORD)v5) {
							if (sub_4196D0((int)v278, v5, *(unsigned __int16*)(v3 + 6), 0))
								sub_4571A0(*(unsigned __int16*)(v3 + 6),
									   *(unsigned __int8*)(v279 + 57));
						}
					}
				}
				goto LABEL_908;
			case 4u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
					if ((_DWORD)v5)
						sub_418CD0((wchar_t*)v5, (wchar_t*)(v3 + 6));
				}
				v3 += 46;
				break;
			case 5u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
					if ((_DWORD)v5)
						sub_418D80(v5);
				}
				goto LABEL_916;
			case 6u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2));
					v280 = (wchar_t*)v5;
					if ((_DWORD)v5) {
						nox_wcscpy(v387, (const wchar_t*)v5);
						sub_418F20(v280, 0);
						sub_456EA0(v387);
					}
				}
				goto LABEL_920;
			case 7u:
				if (nox_client_isConnected_43C700()) {
					sub_419030(0);
					sub_456FA0();
				}
				v3 += 2;
				break;
			case 8u:
				if (nox_client_isConnected_43C700() &&
				    (LODWORD(v5) = sub_418AB0(*(_DWORD*)(v3 + 2)), (_DWORD)v5)) {
					sub_419090(v5, *(_DWORD*)(v3 + 6));
					v3 += 10;
				} else {
				LABEL_908:
					v3 += 10;
				}
				break;
			case 9u:
				if (nox_client_isConnected_43C700())
					sub_417D00();
				v3 += 2;
				break;
			case 0xCu:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 2));
					if ((_DWORD)v5)
						*(_BYTE*)(v5 + 2282) = *(_BYTE*)(v3 + 4);
				}
				v3 += 5;
				break;
			}
			break;
		case 0xC5u:
			sub_43B6E0();
			++v3;
			break;
		case 0xC6u:
			sub_43B750();
			++v3;
			break;
		case 0xC7u:
			v359 = -56;
			v33 = sub_43C750();
			sub_552640(v33, &v359, 1, 2);
			sub_446380();
			++v3;
			break;
		case 0xC9u:
			switch (*(unsigned __int8*)(v3 + 1)) {
			case 1u:
				if (nox_client_isConnected_43C700())
					sub_4C1590();
				v3 += 2;
				break;
			case 2u:
				if (nox_client_isConnected_43C700())
					sub_479280();
				v3 += 2;
				break;
			case 3u:
				if (nox_client_isConnected_43C700())
					sub_4C1BC0(v3);
				v3 += 3;
				break;
			case 4u:
				if (nox_client_isConnected_43C700())
					sub_4C1790(v3);
				v3 += 15;
				break;
			case 5u:
				if (!nox_client_isConnected_43C700())
					goto LABEL_1133;
				sub_4C15D0(v3);
				v3 += 4;
				break;
			case 6u:
				if (!nox_client_isConnected_43C700()) {
					v3 += 14;
					break;
				}
				sub_4C1B50(v3);
				v3 += 14;
				break;
			case 7u:
				if (nox_client_isConnected_43C700())
					sub_4C1BF0();
				v3 += 2;
				break;
			case 8u:
				if (nox_client_isConnected_43C700())
					sub_479300(*(unsigned __int16*)(v3 + 2), *(unsigned __int16*)(v3 + 4),
						   *(_DWORD*)(v3 + 6), *(_DWORD*)(v3 + 10), v3 + 14);
				v3 += 18;
				break;
			case 9u:
				if (!nox_client_isConnected_43C700())
					goto LABEL_1133;
				sub_479480(*(unsigned __int16*)(v3 + 2));
				v3 += 4;
				break;
			case 0xCu:
				if (nox_client_isConnected_43C700())
					sub_4C1320(v3);
				v3 += 52;
				break;
			case 0xDu:
				if (nox_client_isConnected_43C700())
					sub_478FD0((const wchar_t*)(v3 + 4), (char*)(v3 + 54),
						   *(unsigned __int16*)(v3 + 2));
				v3 += 86;
				break;
			case 0x1Bu:
				if (!nox_client_isConnected_43C700())
					goto LABEL_1133;
				sub_479520(*(unsigned __int16*)(v3 + 2));
				v3 += 4;
				break;
			case 0x1Du:
				if (nox_client_isConnected_43C700())
					sub_4795E0(*(unsigned __int16*)(v3 + 2), *(_DWORD*)(v3 + 4));
				goto LABEL_1057;
			case 0x1Fu:
				if (!nox_client_isConnected_43C700())
					goto LABEL_1057;
				sub_479740(*(unsigned __int16*)(v3 + 2), *(_DWORD*)(v3 + 4));
				v3 += 8;
				break;
			default:
				return 0;
			}
			break;
		case 0xCAu:
			if (nox_client_isConnected_43C700()) {
				if (*(short*)(v3 + 1) == -8531)
					sub_48E940();
				else
					sub_48E8E0(*(unsigned __int16*)(v3 + 1));
			}
			v3 += 3;
			break;
		case 0xCBu:
			if (nox_client_isConnected_43C700())
				sub_445450();
			++v3;
			break;
		case 0xCCu:
			if (nox_client_isConnected_43C700())
				sub_48D5A0(v3);
			k = *(unsigned __int8*)(v3 + 3);
			v3 += k + 4;
			break;
		case 0xCDu:
			v86 = 0;
			if (nox_client_isConnected_43C700()) {
				v87 = *(_BYTE*)(v3 + 2);
				LOBYTE(v370) = *(_BYTE*)(v3 + 2) & 0x7F;
				if (v87 < 0)
					v86 = 1;
				sub_4611E0(*(unsigned __int8*)(v3 + 1), (unsigned __int8)v370, (char*)v86);
			}
			v3 += 3;
			break;
		case 0xCEu:
			if (nox_client_isConnected_43C700())
				sub_461090(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
			v3 += 3;
			break;
		case 0xCFu:
			if (nox_client_isConnected_43C700())
				sub_461120(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
			v3 += 3;
			break;
		case 0xD0u:
			if (*(_BYTE*)(v3 + 1) == 3) {
				if (nox_client_isConnected_43C700()) {
					sub_479D30((wchar_t*)(v3 + 34), *(_DWORD*)(v3 + 98), (char*)(v3 + 2),
						   (const char*)(v3 + 102), *(_BYTE*)(v3 + 134));
					if (*(_DWORD*)&byte_5D4594[2618908])
						sub_4174F0(*(int*)&byte_5D4594[2618908], 512);
				}
				v3 += 135;
			} else if (*(_BYTE*)(v3 + 1) == 4) {
				if (nox_client_isConnected_43C700()) {
					sub_47A1F0();
					if (*(_DWORD*)&byte_5D4594[2618908])
						sub_417530(*(int*)&byte_5D4594[2618908], 512);
				}
			LABEL_966:
				v3 += 2;
			}
			break;
		case 0xD1u:
			if (nox_client_isConnected_43C700())
				sub_45D140(*(unsigned __int8*)(v3 + 1), *(_BYTE*)(v3 + 2) & 0x7F);
			v3 += 3;
			break;
		case 0xD2u:
			v281 = sub_578B30(*(_WORD*)(v3 + 1));
			v282 = v281;
			if (!nox_client_isConnected_43C700())
				goto LABEL_948;
			if (sub_578B70(*(unsigned __int16*)(v3 + 1))) {
				v283 = sub_578B30(*(_WORD*)(v3 + 1));
				LODWORD(v5) = sub_45A720(v283);
			} else {
				v284 = sub_578B30(*(_WORD*)(v3 + 1));
				LODWORD(v5) = sub_45A6F0(v284);
			}
			if (*(_BYTE*)(v3 + 5) == 1) {
				if ((_DWORD)v5 ||
				    (LODWORD(v5) = sub_48E970(*(unsigned __int16*)(v3 + 3), v282, 0, 0), (_DWORD)v5)) {
					sub_459DD0(v5, *(_BYTE*)(v3 + 6));
					v3 += 7;
					break;
				}
			} else if ((_DWORD)v5) {
				sub_459E30(v5, *(_BYTE*)(v3 + 6));
			}
		LABEL_948:
			v3 += 7;
			break;
		case 0xD3u:
			if (!nox_client_isConnected_43C700())
				goto LABEL_112;
			if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v3 + 9)) >= 0x1E) {
				v359 = -44;
				sub_4E53C0(31, &v359, 1, 0, 1);
			LABEL_112:
				v3 += 13;
			} else {
				if (*(_DWORD*)(v3 + 1)) {
					sub_40A1F0(1);
					v5 = sub_40A310(*(_DWORD*)(v3 + 5));
				} else {
					sub_40A1F0(0);
				}
				v3 += 13;
			}
			break;
		case 0xD5u:
			v296 = *(_DWORD*)&byte_5D4594[2618908];
			switch (*(_BYTE*)(v3 + 1)) {
			case 1:
				if (nox_client_isConnected_43C700()) {
					if (v296)
						sub_427490(v296, (char*)(v3 + 2), *(_WORD*)(v3 + 66));
					sub_469BC0();
				}
				v3 += 68;
				break;
			case 2:
				if (nox_client_isConnected_43C700()) {
					if (v296)
						sub_427590(v296, (const char*)(v3 + 2));
					sub_469BC0();
				}
				v3 += 68;
				break;
			case 3:
				if (nox_client_isConnected_43C700() && v296)
					sub_4276B0(v296, (const char*)(v3 + 2), *(_WORD*)(v3 + 66));
				v3 += 68;
				break;
			}
			break;
		case 0xD6u:
			if (nox_client_isConnected_43C700())
				nox_client_lockScreenBriefing_450160(*(unsigned __int8*)(v3 + 1),
								     *(unsigned __int8*)(v3 + 2), 0);
			v3 += 3;
			break;
		case 0xD7u:
			LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 1));
			if ((_DWORD)v5) {
				LOWORD(k) = *(_WORD*)(v3 + 3);
				*(_WORD*)(v5 + 2148) = k;
			}
			v3 += 5;
			break;
		case 0xD8u:
			if (nox_client_isConnected_43C700()) {
				sub_455D80(*(_BYTE*)(v3 + 2), *(_BYTE*)(v3 + 1));
				sub_4705F0(*(_BYTE*)(v3 + 1), *(_BYTE*)(v3 + 3), *(_WORD*)(v3 + 4));
				v3 += 6;
			} else {
			LABEL_920:
				v3 += 6;
			}
			break;
		case 0xD9u:
			if (nox_client_isConnected_43C700()) {
				sub_456140(*(_BYTE*)(v3 + 1));
				sub_470650(*(_BYTE*)(v3 + 1), *(_WORD*)(v3 + 2));
			}
			v3 += 4;
			break;
		case 0xDAu:
			v137 = sub_578B30(*(_WORD*)(v3 + 1));
			v138 = v137;
			if (nox_client_isConnected_43C700()) {
				if (sub_4951F0(v138))
					sub_4950F0(v138, *(_BYTE*)(v3 + 3));
				nox_npc_set_328(v138, *(unsigned __int8*)(v3 + 3));
				v3 += 4;
			} else {
			LABEL_764:
				v3 += 4;
			}
			break;
		case 0xDBu:
			v193 = sub_578B30(*(_WORD*)(v3 + 1));
			v194 = v193;
			if (nox_client_isConnected_43C700()) {
				if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
					v195 = sub_45A720(v194);
				else
					v195 = sub_45A6F0(v194);
				if (v195 || (v195 = sub_48E970(*(unsigned __int16*)(v3 + 3), v194, 0, 0)) != 0)
					sub_459DD0((int)v195, 1);
				sub_495060(v194, 0, 0);
			}
		LABEL_638:
			v3 += 5;
			break;
		case 0xDCu:
			v196 = sub_578B30(*(_WORD*)(v3 + 1));
			v197 = v196;
			if (!nox_client_isConnected_43C700()) {
				v3 += 3;
				break;
			}
			sub_4950C0(*(unsigned __int16*)(v3 + 1));
			v337 = v197;
			if (sub_578B70(*(unsigned __int16*)(v3 + 1)))
				LODWORD(v5) = sub_45A720(v197);
			else
			LABEL_642:
				LODWORD(v5) = sub_45A6F0(v337);
		LABEL_643:
			if ((_DWORD)v5)
				sub_459E30(v5, 1);
			v3 += 3;
			break;
		case 0xDDu:
			v90 = sub_578B30(*(_WORD*)(v3 + 1));
			v91 = v90;
			if (!nox_client_isConnected_43C700())
				goto LABEL_1149;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (v91 == *(_DWORD*)&byte_5D4594[2616328]) {
				sub_470C80(*(unsigned __int16*)(v3 + 3), *(unsigned __int16*)(v3 + 5));
				v3 += 7;
			} else if (sub_4951F0(*(unsigned __int16*)(v3 + 1))) {
				sub_495120(*(unsigned __int16*)(v3 + 1), *(_WORD*)(v3 + 3), *(_WORD*)(v3 + 5));
				v3 += 7;
			} else {
			LABEL_1149:
				v3 += 7;
			}
			break;
		case 0xDEu:
			v94 = sub_578B30(*(_WORD*)(v3 + 1));
			v95 = v94;
			if (!nox_client_isConnected_43C700())
				goto LABEL_948;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (v95 != *(_DWORD*)&byte_5D4594[2616328])
				goto LABEL_948;
			sub_470CE0(*(unsigned __int16*)(v3 + 3), *(unsigned __int16*)(v3 + 5));
			v3 += 7;
			break;
		case 0xDFu:
			sub_460EB0(*(_DWORD*)(v3 + 1), *(_BYTE*)(v3 + 5));
			v3 += 6;
			break;
		case 0xE0u:
			v291 = sub_578B30(*(_WORD*)(v3 + 1));
			v292 = v291;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			if (*(_WORD*)(v3 + 1))
				sub_467750(v292, *(_BYTE*)(v3 + 3));
			else
				sub_467750(0, *(_BYTE*)(v3 + 3));
			v3 += 4;
			break;
		case 0xE1u:
			v293 = sub_578B30(*(_WORD*)(v3 + 1));
			sub_467740(v293);
			v3 += 3;
			break;
		case 0xE2u:
			v294 = sub_578B30(*(_WORD*)(v3 + 1));
			v295 = v294;
			if ((nox_common_engineFlags & 0x8000) != 0)
				sub_578B70(*(unsigned __int16*)(v3 + 1));
			LODWORD(v5) = sub_478080(v295);
			if ((_DWORD)v5 || (LODWORD(v5) = sub_4676D0(v295), (_DWORD)v5) ||
			    (!sub_578B70(*(unsigned __int16*)(v3 + 1)) ? (LODWORD(v5) = sub_45A6F0(v295))
								       : (LODWORD(v5) = sub_45A720(v295)),
			     (_DWORD)v5)) {
				k = *(unsigned __int8*)(v3 + 3);
				*(_DWORD*)(v5 + 432) = k;
			}
			v3 += 4;
			break;
		case 0xE4u:
			if (nox_client_isConnected_43C700()) {
				if (*(_BYTE*)(v3 + 1) == 1) {
					if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000)) {
						dword_5d4594_2650672 = 0;
						sub_42EE00();
						sub_413A00(1);
						sub_44DB30(25, *(_BYTE*)(v3 + 2) == 1, sub_44E020);
					}
				} else if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000)) {
					nox_client_screenFadeTimeout_44DAB0(25, *(_BYTE*)(v3 + 2) == 1, sub_44E000);
				}
			}
			v3 += 3;
			break;
		case 0xE5u:
			if (nox_client_isConnected_43C700())
				sub_43D9B0(*(unsigned __int8*)(v3 + 1), *(unsigned __int8*)(v3 + 2));
			v3 += 3;
			break;
		case 0xE6u:
			if (nox_client_isConnected_43C700())
				sub_43DA80();
			v3 += 3;
			break;
		case 0xE7u:
			if (nox_client_isConnected_43C700())
				sub_43DAD0();
			v3 += 3;
			break;
		case 0xE8u:
			if (nox_client_isConnected_43C700()) {
				LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 1));
				v111 = (_DWORD*)v5;
				if ((_DWORD)v5) {
					if ((_DWORD)v5 == *(_DWORD*)&byte_5D4594[2618908]) {
						sub_4BFE40();
						sub_478000();
					}
					v112 = sub_45A6F0(*(unsigned __int16*)(v3 + 1));
					if (v112)
						sub_459E30((int)v112, 3);
					if (!nox_common_gameFlags_check_40A5C0(4096)) {
						v111[1] = 0;
						LODWORD(v5) = v111 + 582;
						v113 = 27;
						do {
							v114 = (_DWORD*)v5;
							LODWORD(v5) = v5 + 24;
							*(_DWORD*)(v5 - 4) = 0;
							v5 = (unsigned int)v5;
							*v114 = 0;
							--v113;
							v114[1] = 0;
							v114[2] = 0;
							v114[3] = 0;
						} while (v113);
						for (k = 0; k < 624; k += 24) {
							v115 = *(_DWORD*)((char*)v111 + k + 2972);
							if (!(v115 & 0xC0D)) {
								HIDWORD(v5) = ~v115 & *v111;
								*v111 = HIDWORD(v5);
								*(_DWORD*)((char*)v111 + k + 2972) = 0;
								*(_DWORD*)((char*)v111 + k + 2976) = 0;
								*(_DWORD*)((char*)v111 + k + 2980) = 0;
								*(_DWORD*)((char*)v111 + k + 2984) = 0;
								*(_DWORD*)((char*)v111 + k + 2988) = 0;
							}
						}
					}
				}
			}
			v3 += 3;
			break;
		case 0xE9u:
			if (nox_client_isConnected_43C700()) {
				if (nox_common_gameFlags_check_40A5C0(0x2000)) {
					k = *(unsigned __int16*)(v3 + 1);
					if ((unsigned __int16)k == *(_DWORD*)&byte_5D4594[2616328])
						sub_45A670(*(_DWORD*)(v3 + 3));
				}
				if (*(_BYTE*)(v3 + 8) & 1) {
					LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 1));
					if ((_DWORD)v5)
						sub_417680(v5, *(_BYTE*)(v3 + 7));
				}
			}
			v3 += 9;
			break;
		case 0xEAu:
			if (nox_common_gameFlags_check_40A5C0(0x2000)) {
				sub_45A670(*(_DWORD*)(v3 + 1));
				v3 += 5;
			} else {
			LABEL_1163:
				v3 += 5;
			}
			break;
		case 0xEBu:
			if (!nox_client_isConnected_43C700()) {
				v3 += 2;
				break;
			}
			sub_4610D0(*(_BYTE*)(v3 + 1));
			v3 += 2;
			break;
		case 0xECu:
			if (nox_client_isConnected_43C700()) {
				sub_43C7A0(*(unsigned __int8*)(v3 + 1));
			}
			v3 += 2;
			break;
		case 0xEDu:
			if (nox_client_isConnected_43C700()) {
				sub_4C1CA0(*(unsigned __int8*)(v3 + 1));
			}
			v3 += 2;
			break;
		case 0xEEu:
			if (*(_BYTE*)(v3 + 1) == 6) {
				sub_48D4B0(*(unsigned __int8*)(v3 + 2));
				v3 += 3;
				break;
			} else if (*(_BYTE*)(v3 + 1) == 7) {
				sub_48D4A0();
				v3 += 2;
				break;
			}
			return 0;
		case 0xEFu:
			if (byte_5D4594[2661958]) {
				if (byte_5D4594[2661958] == 1) {
					dword_587000_312816 = *(_DWORD*)(v3 + 1);
					dword_587000_312820 = *(_DWORD*)(v3 + 5);
					dword_587000_312824 = *(_DWORD*)(v3 + 9);
					dword_587000_312828 = *(_DWORD*)(v3 + 13);
					sub_57B200();
					v3 += 17;
					break;
				} else if (byte_5D4594[2661958] == 2) {
					dword_587000_312800 = *(_DWORD*)(v3 + 1);
					dword_587000_312804 = *(_DWORD*)(v3 + 5);
					dword_587000_312808 = *(_DWORD*)(v3 + 9);
					dword_587000_312812 = *(_DWORD*)(v3 + 13);
					sub_57B200();
					v3 += 17;
					break;
				}
			} else {
				dword_587000_312784 = *(_DWORD*)(v3 + 1);
				dword_587000_312788 = *(_DWORD*)(v3 + 5);
				dword_587000_312792 = *(_DWORD*)(v3 + 9);
				dword_587000_312796 = *(_DWORD*)(v3 + 13);
			}
			sub_57B200();
			v3 += 17;
			break;
		case 0xF0u:
			switch (*(unsigned __int8*)(v3 + 1)) {
			case 0u:
				if (nox_client_isConnected_43C700() == 1) {
					if (nox_common_gameFlags_check_40A5C0(1)) {
						sub_460380();
						sub_460E60();
						sub_41CC00((char*)&byte_5D4594[2660688]);
						sub_41A480((char*)&byte_5D4594[2660688]);
					}
					sub_470AA0(1);
					sub_48D4A0();
					sub_4721D0();
					sub_4705B0();
				}
				goto LABEL_1085;
			case 1u:
				if (nox_client_isConnected_43C700() == 1) {
					sub_452D80(1008, 100);
					v299 = sub_417040(*(unsigned __int16*)(v3 + 2));
					if (v299) {
						if (!nox_common_gameFlags_check_40A5C0(1))
							*((_DWORD*)v299 + 1198) = 1;
					}
				}
				v3 += 4;
				break;
			case 2u:
				if (nox_client_isConnected_43C700() == 1)
					sub_49B4B0((unsigned __int16*)v3);
				v3 += 14;
				break;
			case 4u:
				if (nox_client_isConnected_43C700()) {
					v300 = sub_417040(*(unsigned __int16*)(v3 + 3));
					if (v300)
						v300[4816] = *(_BYTE*)(v3 + 2);
					HIDWORD(v5) = *(unsigned __int16*)(v3 + 3);
					if (WORD2(v5) == *(_DWORD*)&byte_5D4594[2616328])
						sub_463420(*(unsigned __int8*)(v3 + 2));
				}
				v3 += 5;
				break;
			case 5u:
			case 6u:
			case 7u:
			case 8u:
			case 9u:
			case 0xAu:
				nox_client_isConnected_43C700();
				v3 += 4;
				break;
			case 0xBu:
				nox_client_isConnected_43C700();
				v3 += 16;
				break;
			case 0xCu:
				if (nox_client_isConnected_43C700())
					sub_450770(v3);
				dword_5d4594_1556112 = 0;
				v3 += 90;
				break;
			case 0xDu:
				if (nox_client_isConnected_43C700())
					sub_450980(v3, *(_BYTE*)(v3 + 4) & 1);
				goto LABEL_1119;
			case 0xEu:
				if (nox_client_isConnected_43C700())
					nox_client_showQuestBriefing_450A30(v3, 1);
			LABEL_1119:
				dword_5d4594_1556112 = 0;
				v3 += 69;
				break;
			case 0xFu:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_45A720(*(unsigned __int16*)(v3 + 2));
					if ((_DWORD)v5)
						*(_BYTE*)(v5 + 432) = 0;
				}
				v3 += 4;
				break;
			case 0x10u:
				if (!*(_DWORD*)&byte_5D4594[1200904])
					*(_DWORD*)&byte_5D4594[1200904] = sub_44CFC0((CHAR*)&byte_587000[160484]);
				if (nox_client_isConnected_43C700()) {
					v301 = sub_45A360_drawable(*(int*)&byte_5D4594[1200904],
								   *(unsigned __int16*)(v3 + 6),
								   *(unsigned __int16*)(v3 + 8));
					*(_BYTE*)(v301 + 432) = 0;
					*(_DWORD*)(v301 + 437) = *(_DWORD*)(v3 + 2);
					*(_DWORD*)(v301 + 441) = *(_DWORD*)(v3 + 6);
					*(_DWORD*)(v301 + 433) = *(unsigned __int16*)(v3 + 10);
					sub_49B950((_DWORD*)v301, *(unsigned __int16*)(v3 + 10));
				}
				goto LABEL_1130;
			case 0x11u:
				if (nox_client_isConnected_43C700())
					sub_45D320(*(unsigned __int16*)(v3 + 2));
				goto LABEL_1133;
			case 0x12u:
				if (!nox_client_isConnected_43C700())
					goto LABEL_1133;
				sub_45D4A0(*(unsigned __int16*)(v3 + 2));
				v3 += 4;
				break;
			case 0x13u:
				if (!nox_client_isConnected_43C700())
					goto LABEL_1133;
				sub_45D400(*(unsigned __int16*)(v3 + 2));
				v3 += 4;
				break;
			case 0x14u:
				if (nox_client_isConnected_43C700() != 1 || sub_470580()) {
				LABEL_1085:
					v3 += 2;
				} else {
					sub_4705B0();
					v3 += 2;
				}
				break;
			case 0x15u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 6));
					if ((_DWORD)v5) {
						HIDWORD(v5) = *(_DWORD*)(v3 + 2);
						*(_DWORD*)(v5 + 4820) = HIDWORD(v5);
					}
				}
				v3 += 8;
				break;
			case 0x16u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 3));
					if ((_DWORD)v5)
						*(_BYTE*)(v5 + 4824) = *(_BYTE*)(v3 + 2);
				}
				v3 += 5;
				break;
			case 0x17u:
				if (nox_client_isConnected_43C700()) {
					LODWORD(v5) = sub_417040(*(unsigned __int16*)(v3 + 3));
					if ((_DWORD)v5)
						*(_BYTE*)(v5 + 4825) = *(_BYTE*)(v3 + 2);
				}
				v3 += 5;
				break;
			case 0x18u:
				if (nox_client_isConnected_43C700() == 1)
					sub_4BFBB0((_DWORD*)*(unsigned __int8*)(v3 + 2));
				v3 += 3;
				break;
			case 0x19u:
				if (!*(_DWORD*)&byte_5D4594[1200908]) {
					*(_DWORD*)&byte_5D4594[1200908] = sub_44CFC0((CHAR*)&byte_587000[160496]);
					*(_DWORD*)&byte_5D4594[1200912] = sub_44CFC0((CHAR*)&byte_587000[160508]);
				}
				v302 = (_DWORD*)sub_45A360_drawable(*(int*)&byte_5D4594[1200912], *(__int16*)(v3 + 2),
								    *(__int16*)(v3 + 4));
				if (v302)
					sub_45A110_drawable(v302);
				if (nox_client_isConnected_43C700()) {
					v380.field_0 = *(__int16*)(v3 + 2);
					v380.field_4 = *(__int16*)(v3 + 4);
					sub_49A150(&v380, *(int*)&byte_5D4594[1200908], *(_BYTE*)(v3 + 6));
				}
				goto LABEL_1149;
			case 0x1Au:
				if (nox_client_isConnected_43C700())
					sub_499610(*(int*)&byte_5D4594[1200788], 25, 500, 25, *(__int16*)(v3 + 2),
						   *(__int16*)(v3 + 4));
				v3 += 6;
				break;
			case 0x1Cu:
				if (nox_client_isConnected_43C700())
					sub_41D1A0(*(unsigned __int8*)(v3 + 2));
				v3 += 3;
				break;
			case 0x1Du:
				if (nox_client_isConnected_43C700()) {
					sub_465DE0(*(unsigned __int16*)(v3 + 2));
					v3 += 4;
				} else {
				LABEL_1133:
					v3 += 4;
				}
				break;
			case 0x1Eu:
				v303 = sub_417040(*(unsigned __int16*)(v3 + 3));
				if (nox_client_isConnected_43C700() && v303) {
					if (v303 == *(char**)&byte_5D4594[2618908]) {
						v348 = sub_424930(*(unsigned __int8*)(v3 + 2));
						v304 = loadString_sub_40F1D0(
						    (char*)&byte_587000[160560], 0,
						    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8112);
						nox_swprintf(v405, v304, v348);
					} else {
						v349 = sub_424930(*(unsigned __int8*)(v3 + 2));
						v305 = loadString_sub_40F1D0(
						    (char*)&byte_587000[160624], 0,
						    "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8115);
						nox_swprintf(v405, v305, v303 + 4704, v349);
					}
					sub_445490(v405);
				}
				goto LABEL_1163;
			case 0x1Fu:
				v306 = sub_417040(*(unsigned __int16*)(v3 + 3));
				if (!nox_client_isConnected_43C700() || !v306)
					goto LABEL_1163;
				if (v306 == *(char**)&byte_5D4594[2618908]) {
					v350 = sub_427240(*(unsigned __int8*)(v3 + 2));
					v307 =
					    loadString_sub_40F1D0((char*)&byte_587000[160696], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8145);
					nox_swprintf(v403, v307, v350);
				} else {
					v351 = sub_427240(*(unsigned __int8*)(v3 + 2));
					v308 =
					    loadString_sub_40F1D0((char*)&byte_587000[160760], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8148);
					nox_swprintf(v403, v308, v306 + 4704, v351);
				}
				sub_445490(v403);
				v3 += 5;
				break;
			case 0x20u:
				v309 = sub_417040(*(unsigned __int16*)(v3 + 3));
				if (!nox_client_isConnected_43C700() || !v309)
					goto LABEL_1163;
				if (v309 == *(char**)&byte_5D4594[2618908]) {
					v352 = sub_425260(*(unsigned __int8*)(v3 + 2));
					v310 =
					    loadString_sub_40F1D0((char*)&byte_587000[160832], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8178);
					nox_swprintf(v404, v310, v352);
				} else {
					v353 = sub_425260(*(unsigned __int8*)(v3 + 2));
					v311 =
					    loadString_sub_40F1D0((char*)&byte_587000[160896], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8181);
					nox_swprintf(v404, v311, v309 + 4704, v353);
				}
				sub_445490(v404);
				v3 += 5;
				break;
			case 0x21u:
				if (nox_client_isConnected_43C700()) {
					v383[0] = (int)&byte_587000[160948];
					v383[1] = (int)&byte_587000[160988];
					v383[2] = (int)&byte_587000[161028];
					v383[3] = (int)&byte_587000[161068];
					v383[4] = (int)&byte_587000[161112];
					v354 =
					    loadString_sub_40F1D0((char*)v383[*(unsigned __int8*)(v3 + 51)], 0,
								  "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8217);
					v312 = loadString_sub_40F1D0(
					    (char*)(v3 + 2), 0, "C:\\NoxPost\\src\\Client\\Network\\cdecode.c", 8216);
					nox_swprintf(v402, v312, v354);
					sub_445490(v402);
				}
				v3 += 52;
				break;
			default:
				return 0;
			}
			break;
		default:
			return 0;
		}
		v4 = v369;
		if (v3 >= v369)
			return 1;
	}
}
