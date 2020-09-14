#include "client/draw/debugdraw.h"
#include "client/draw/staticdraw.h"
#include "client/drawable/drawable.h"

#include "client/gui/gadgets/listbox.h"
#include "client/gui/guibook.h"
#include "client/gui/guicurs.h"
#include "client/gui/guishop.h"
#include "client/gui/servopts/guiserv.h"
#include "client/gui/tooltip.h"

#include "client/draw/drawwin.h"

#include "proto.h"

extern _DWORD dword_587000_149360;
extern _DWORD dword_5d4594_1098456;
extern _DWORD dword_5d4594_1193180;
extern _DWORD dword_5d4594_1097212;
extern _DWORD dword_5d4594_1193352;
extern _DWORD dword_5d4594_1096636;
extern _DWORD dword_5d4594_1097216;
extern _DWORD dword_5d4594_3799500;
extern _DWORD dword_5d4594_3807116;
extern _DWORD dword_5d4594_1098620;
extern _DWORD dword_587000_151528;
extern _DWORD dword_5d4594_1123520;
extern _DWORD dword_5d4594_1193188;
extern _DWORD dword_5d4594_1097196;
extern _DWORD dword_5d4594_1193176;
extern _DWORD dword_5d4594_1098596;
extern _DWORD dword_5d4594_1193336;
extern _DWORD dword_587000_80840;
extern _DWORD dword_5d4594_1097192;
extern _DWORD dword_5d4594_3799452;
extern _DWORD dword_5d4594_1098600;
extern _DWORD dword_5d4594_3807152;
extern _DWORD dword_5d4594_1098616;
extern _DWORD dword_5d4594_1193672;
extern _DWORD dword_5d4594_3807136;
extern _DWORD dword_5d4594_1098604;
extern _DWORD dword_587000_154968;
extern _DWORD dword_5d4594_1193624;
extern _DWORD dword_5d4594_1193664;
extern _DWORD dword_5d4594_1193524;
extern _DWORD dword_5d4594_3805484;
extern _DWORD dword_5d4594_3804684;
extern _DWORD dword_5d4594_1193156;
extern _DWORD dword_5d4594_3807140;
extern _DWORD dword_5d4594_1097208;
extern _DWORD dword_5d4594_3799552;
extern _DWORD dword_5d4594_1193648;
extern _DWORD dword_5d4594_1193668;
extern _DWORD dword_5d4594_1096644;
extern _DWORD dword_5d4594_787144;
extern _DWORD dword_587000_80832;
extern _DWORD dword_5d4594_1097188;
extern _DWORD dword_587000_154960;
extern _DWORD dword_5d4594_3799476;
extern _DWORD dword_5d4594_3799468;
extern _DWORD dword_587000_154948;
extern _DWORD dword_5d4594_3807160;
extern _DWORD dword_5d4594_1098592;
extern _DWORD dword_5d4594_1193184;
extern _DWORD dword_5d4594_1189600;
extern _DWORD dword_5d4594_823776;
extern _DWORD dword_5d4594_3804680;
extern BYTE* nox_pixbuffer_3798780;
extern _DWORD dword_5d4594_1098580;
extern _DWORD dword_5d4594_2650680;
extern _DWORD nox_client_lockHighResFloors_1193152;
extern _DWORD dword_5d4594_805836;
extern _DWORD dword_5d4594_3799508;
extern _DWORD dword_5d4594_3798812;
extern _DWORD dword_5d4594_3798800;
extern _DWORD dword_5d4594_1193584;
extern int nox_pitch_3801808;
extern _DWORD dword_5d4594_3798828;
extern _QWORD qword_581450_9552;
extern _QWORD qword_581450_9544;
extern _DWORD dword_5d4594_1098624;
extern _DWORD dword_5d4594_2650676;
extern _DWORD dword_5d4594_3798156;
extern _DWORD dword_5d4594_1189596;
extern _DWORD dword_5d4594_1189592;
extern _DWORD dword_5d4594_3801804;
extern _DWORD dword_5d4594_3798816;
extern _DWORD dword_5d4594_1096640;
extern _DWORD nox_client_highResFloors_154952;
extern _DWORD dword_5d4594_3798808;
extern _DWORD dword_5d4594_3799492;
extern _DWORD dword_5d4594_3798832;
extern _DWORD dword_5d4594_1193384;
extern _DWORD dword_5d4594_1123532;
extern _DWORD dword_5d4594_1193348;
extern _DWORD dword_5d4594_3799524;
extern _DWORD dword_5d4594_3679320;
extern _DWORD dword_5d4594_1193360;
extern _DWORD nox_client_texturedFloors_154956;
extern _DWORD nox_client_highResFrontWalls_80820;
extern _DWORD dword_5d4594_3798836;
extern _DWORD dword_5d4594_1107036;
extern _DWORD dword_5d4594_251568;
extern _DWORD dword_5d4594_3799484;
extern _DWORD dword_5d4594_251572;
extern _DWORD dword_5d4594_1098628;
extern _DWORD dword_5d4594_3798804;
extern _DWORD dword_5d4594_1098576;
extern _DWORD dword_5d4594_1193516;
extern _DWORD dword_5d4594_3798820;
extern _DWORD dword_5d4594_3798824;
extern _DWORD dword_587000_155144;
extern _DWORD dword_5d4594_3798840;
extern _DWORD dword_5d4594_1123524;
extern _DWORD dword_5d4594_3799624;
extern _DWORD dword_587000_26048;
extern _DWORD dword_5d4594_1193380;
extern _DWORD dword_5d4594_1189584;
extern _DWORD dword_5d4594_3801780;
extern _DWORD nox_client_renderGUI_80828;
extern _DWORD dword_5d4594_3798796;
extern _DWORD dword_5d4594_3798844;
extern _DWORD dword_5d4594_3804672;
extern _DWORD dword_5d4594_3804656;
extern _DWORD dword_5d4594_3804664;
extern BYTE** nox_pixbuffer_rows_3798784;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_video_renderTargetFlags;
extern int nox_video_pauseThreadedDrawCursor;
extern int nox_video_drawCursorThreadOk;
extern int nox_video_allowCursorDrawThread;
extern int nox_video_windowsPlatformVersion;
extern int nox_video_cursorDrawIsThreaded;
extern int nox_client_mouseCursorType;
extern HANDLE* nox_video_cursorDrawThreadHandle;

extern nox_drawable** nox_drawable_list_3;
extern int nox_drawable_list_3_size;

extern nox_drawable** nox_drawable_list_4;
extern int nox_drawable_list_4_size;

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;

extern obj_5D4594_2650668_t** ptr_5D4594_2650668;

BYTE** nox_pixbuffer_rows_3798776 = 0;
BYTE* nox_pixbuffer_3798788 = 0;

void(__cdecl *func_587000_154940)(int2*, _DWORD, _DWORD) = sub_4815E0;
int (__cdecl *func_587000_154944)(int, int) = sub_481900;

//----- (00475F10) --------------------------------------------------------
int __cdecl sub_475F10(_DWORD* a1) {
	int* v1;    // ebp
	int result; // eax
	bool i;     // zf
	int v4;     // esi
	int v5;     // eax

	v1 = nox_drawable_list_3;
	result = nox_drawable_list_3_size - 1;
	for (i = nox_drawable_list_3_size-- == 0; !i; --nox_drawable_list_3_size) {
		v4 = *v1;
		++v1;
		sub_4746C0(a1, v4);
		if (sub_4984B0_drawable(v4)) {
			*(_DWORD*)(v4 + 484) = 1;
			(*(void(__cdecl**)(_DWORD*, int))(v4 + 300))(a1, v4);
			if (*(_BYTE*)(v4 + 280) & 0x40)
				sub_4C4F40(a1, v4);
			sub_474E60(a1, v4);
			sub_495BB0((_DWORD*)v4, a1);
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS))
				nox_thing_debug_draw(a1, v4);
			v5 = *(_DWORD*)(v4 + 480);
			*(_DWORD*)(v4 + 132) = 0;
			if (!v5 && !*(_DWORD*)(v4 + 488))
				*(_DWORD*)(v4 + 340) = *getMemU32Ptr(0x5D4594, 2598000);
		}
		result = nox_drawable_list_3_size - 1;
		i = nox_drawable_list_3_size == 0;
	}
	return result;
}

//----- (00475FE0) --------------------------------------------------------
int __cdecl sub_475FE0(_DWORD* a1) {
	int* v1;    // ebp
	int result; // eax
	bool i;     // zf
	int v4;     // esi
	int v5;     // eax

	v1 = nox_drawable_list_4;
	result = nox_drawable_list_4_size - 1;
	for (i = nox_drawable_list_4_size-- == 0; !i; --nox_drawable_list_4_size) {
		v4 = *v1;
		++v1;
		if (sub_4984B0_drawable(v4)) {
			*(_DWORD*)(v4 + 484) = 1;
			(*(void(__cdecl**)(_DWORD*, int))(v4 + 300))(a1, v4);
			if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS))
				nox_thing_debug_draw(a1, v4);
			v5 = *(_DWORD*)(v4 + 480);
			*(_DWORD*)(v4 + 132) = 0;
			if (!v5 && !*(_DWORD*)(v4 + 488))
				*(_DWORD*)(v4 + 340) = *getMemU32Ptr(0x5D4594, 2598000);
		}
		result = nox_drawable_list_4_size - 1;
		i = nox_drawable_list_4_size == 0;
	}
	return result;
}

//----- (00476080) --------------------------------------------------------
int __cdecl sub_476080(unsigned __int8* a1) {
	int v1;     // esi
	int v2;     // ecx
	int result; // eax
	int v4;     // edx
	int v5;     // ecx

	if (!*getMemU32Ptr(0x5D4594, 2614252))
		return 23 * a1[6] + 11;
	switch (*a1) {
	case 0u:
	case 3u:
	case 0xBu:
		v1 = -23;
		v2 = 23 * a1[5] + 22;
		result = 23 * a1[6];
		goto LABEL_5;
	case 1u:
	case 4u:
	case 0xCu:
		v1 = 23;
		v2 = 23 * a1[5];
		result = 23 * a1[6];
	LABEL_5:
		v4 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 12) - v2;
		v5 = v1 * (*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 16) - result) - 23 * v4;
		if (v1 < 0)
			v5 = 23 * v4 - v1 * (*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 16) - result);
		if (v5 < 0)
			result += 22;
		break;
	default:
		result = 23 * a1[6] + 11;
		break;
	}
	return result;
}

//----- (00476160) --------------------------------------------------------
int __cdecl sub_476160(const void* a1, const void* a2) {
	int v2;     // esi
	int result; // eax

	if ((signed char)*(_BYTE*)(*(_DWORD*)a1 + 112) >= 0)
		v2 = *(_DWORD*)(*(_DWORD*)a1 + 16) + *(__int16*)(*(_DWORD*)a1 + 104);
	else
		v2 = sub_4761B0(*(_DWORD*)a1);
	if ((signed char)*(_BYTE*)(*(_DWORD*)a2 + 112) >= 0)
		result = v2 - (*(_DWORD*)(*(_DWORD*)a2 + 16) + *(__int16*)(*(_DWORD*)a2 + 104));
	else
		result = v2 - sub_4761B0(*(_DWORD*)a2);
	return result;
}

//----- (004761B0) --------------------------------------------------------
int __cdecl sub_4761B0(int a1) {
	int result; // eax
	int v2;     // edx
	int v3;     // ecx
	int v4;     // edx

	if (!*getMemU32Ptr(0x5D4594, 2614252))
		return *(_DWORD*)(a1 + 16) + *(int*)getMemAt(0x587000, 8 * *(unsigned __int8*)(a1 + 299) + 196188) / 2;
	result = *(_DWORD*)(a1 + 16);
	v2 = 8 * *(unsigned __int8*)(a1 + 299);
	v3 = (*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 16) - result) * *(int*)getMemAt(0x587000, v2 + 196184) -
		 (*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 12) - *(_DWORD*)(a1 + 12)) * *(int*)getMemAt(0x587000, v2 + 196188);
	if (*(int*)getMemAt(0x587000, v2 + 196184) < 0)
		v3 = (*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 12) - *(_DWORD*)(a1 + 12)) *
				 *(int*)getMemAt(0x587000, 8 * *(unsigned __int8*)(a1 + 299) + 196188) -
			 (*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 16) - result) *
				 *(int*)getMemAt(0x587000, 8 * *(unsigned __int8*)(a1 + 299) + 196184);
	v4 = result + *(int*)getMemAt(0x587000, 8 * *(unsigned __int8*)(a1 + 299) + 196188);
	if (v3 >= 0) {
		if (v4 <= result)
			result += *(int*)getMemAt(0x587000, 8 * *(unsigned __int8*)(a1 + 299) + 196188);
	} else if (v4 > result) {
		result += *(int*)getMemAt(0x587000, 8 * *(unsigned __int8*)(a1 + 299) + 196188);
	}
	return result;
}

//----- (00476240) --------------------------------------------------------
int __cdecl sub_476240(const void* a1, const void* a2) {
	int v2; // esi

	v2 = sub_476080(*(unsigned __int8**)a1);
	return v2 - sub_476080(*(unsigned __int8**)a2);
}

//----- (00476270) --------------------------------------------------------
int __cdecl sub_476270(_DWORD* a1) {
	_DWORD* v1;  // esi
	int v2;      // ebp
	int v3;      // ebx
	int v4;      // edi
	int v5;      // ebx
	int v6;      // ebx
	int v7;      // edi
	float* v8;   // eax
	int v9;      // edi
	int v10;     // ebx
	int v11;     // edi
	int v12;     // ebx
	int v13;     // ebp
	__int64 v14; // rax
	int v15;     // ecx
	int v16;     // edx
	int v17;     // ebx
	int v18;     // edi
	__int16 v19; // ax
	int v21;     // [esp-8h] [ebp-30h]
	int v22;     // [esp-4h] [ebp-2Ch]
	float* v23;  // [esp+10h] [ebp-18h]
	int v24;     // [esp+14h] [ebp-14h]
	float* v25;  // [esp+18h] [ebp-10h]
	int v26;     // [esp+18h] [ebp-10h]
	int v27;     // [esp+20h] [ebp-8h]
	int v28;     // [esp+20h] [ebp-8h]
	int v29;     // [esp+24h] [ebp-4h]
	int i;       // [esp+2Ch] [ebp+4h]
	int v31;     // [esp+2Ch] [ebp+4h]

	v27 = sub_50CB00();
	v24 = sub_50D210();
	v1 = a1;
	v23 = (float*)sub_50CB10();
	if (v27 >= 2) {
		v2 = 1;
		v3 = 0;
		for (i = 0;; v3 = i) {
			v4 = *v1 + (unsigned __int64)(__int64)v23[2 * v3] - v1[4];
			v25 = &v23[2 * v3 + 1];
			v5 = v1[1] + (unsigned __int64)(__int64)*v25 - v1[5];
			if (i == v24) {
				nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2650644));
			} else if (v23[2 * i] < 0.0 || *v25 < 0.0) {
				nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2650684));
			} else {
				nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2589772));
			}
			nox_client_drawBorderLines_49CC70(v4 - 1, v5 - 1, 3, 3);
			nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2618904));
			nox_client_drawAddPoint_49F500(v4, v5);
			v6 = *v1 + (unsigned __int64)(__int64)v23[2 * v2] - v1[4];
			v7 = v1[1] + (unsigned __int64)(__int64)v23[2 * v2 + 1] - v1[5];
			nox_client_drawAddPoint_49F500(v6, v7);
			nox_client_drawLineFromPoints_49E4B0();
			i = v2++;
			if (v2 >= v27)
				break;
		}
		nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2589772));
		nox_client_drawBorderLines_49CC70(v6 - 1, v7 - 1, 3, 3);
	}
	v8 = (float*)sub_50CD30();
	v9 = *v1 + (unsigned __int64)(__int64)*v8 - v1[4];
	v10 = v1[1] + (unsigned __int64)(__int64)v8[1] - v1[5];
	nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2523948));
	nox_client_drawBorderLines_49CC70(v9 - 2, v10 - 2, 5, 5);
	v11 = v1[4];
	v12 = v1[5];
	v26 = (__int64)((double)(v11 / 23) + 0.5);
	v13 = (__int64)((double)(v12 / 23) + 0.5);
	v28 = (__int64)((double)((nox_win_width + v11) / 23) + 0.5);
	v14 = (__int64)((double)((nox_win_height + v12) / 23) + 0.5);
	v15 = v14;
	v29 = v14;
	if (v13 > (int)v14)
		return v14;
	v16 = 23 * v13;
	v31 = 23 * v13;
	do {
		LODWORD(v14) = v26;
		v17 = v26;
		if (v26 > v28)
			goto LABEL_37;
		v18 = 23 * v26;
		do {
			if (sub_57B500(v17, v13, 64) == -1) {
				v19 = sub_50AB50(v17, v13);
				if (v19 & 0x40) {
					sub_434430(0, 255, 0);
				} else if (v19 & 2) {
					sub_434430(0, 255, 255);
				} else {
					if (v19 & 1) {
						sub_434430(0, 100, 100);
						goto LABEL_34;
					}
					if (v19 & 0x3C) {
						v22 = 255;
					LABEL_32:
						v21 = 0;
					LABEL_33:
						sub_434430(255, v21, v22);
						goto LABEL_34;
					}
					if (v19 & 0x400) {
						v22 = 0;
						goto LABEL_32;
					}
					if (v19 & 0x200) {
						v22 = 0;
						v21 = 255;
						goto LABEL_33;
					}
					if (!(v19 & 0x100))
						goto LABEL_35;
					sub_434430(100, 100, 0);
				}
			} else {
				sub_434430(0, 0, 255);
			}
		LABEL_34:
			nox_client_drawBorderLines_49CC70(v18 - v1[4], v31 - v1[5], 23, 23);
		LABEL_35:
			LODWORD(v14) = v28;
			++v17;
			v18 += 23;
		} while (v17 <= v28);
		v15 = v29;
		v16 = v31;
	LABEL_37:
		++v13;
		v16 += 23;
		v31 = v16;
	} while (v13 <= v15);
	return v14;
}

//----- (004765F0) --------------------------------------------------------
int __cdecl sub_4765F0(int a1) {
	int result; // eax
	int v2;     // eax

	*getMemU32Ptr(0x5D4594, 1096440) = nox_client_highResFloors_154952;
	result = *getMemU32Ptr(0x5D4594, 2614252);
	*getMemU32Ptr(0x5D4594, 1096444) = nox_client_highResFrontWalls_80820;
	if (*getMemU32Ptr(0x5D4594, 2614252) && !nox_client_lockHighResFloors_1193152) {
		v2 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 276);
		if ((v2 == 3 || v2 == 6 || v2 == 45) && (*(int*)(a1 + 16) - *(int*)getMemAt(0x5D4594, 1096556) >= 4 ||
												 *(int*)(a1 + 20) - *(int*)getMemAt(0x5D4594, 1096560) >= 4)) {
			nox_client_highResFloors_154952 = 0;
			nox_client_highResFrontWalls_80820 = 0;
		}
		result = *(_DWORD*)(a1 + 16);
		*getMemU32Ptr(0x5D4594, 1096556) = *(_DWORD*)(a1 + 16);
		*getMemU32Ptr(0x5D4594, 1096560) = *(_DWORD*)(a1 + 20);
	}
	return result;
}

//----- (00476680) --------------------------------------------------------
int sub_476680() {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1096440);
	nox_client_highResFloors_154952 = *getMemU32Ptr(0x5D4594, 1096440);
	nox_client_highResFrontWalls_80820 = *getMemU32Ptr(0x5D4594, 1096444);
	return result;
}

//----- (004766A0) --------------------------------------------------------
int __cdecl sub_4766A0(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 65) {
		if (a1 > 100)
			result = 100;
		dword_587000_149360 = result;
	} else {
		result = 65;
		dword_587000_149360 = 65;
	}
	return result;
}

//----- (004766D0) --------------------------------------------------------
int sub_4766D0() { return dword_587000_149360; }

//----- (004766E0) --------------------------------------------------------
void sub_4766E0() { sub_476700(0, 2); }

//----- (004766F0) --------------------------------------------------------
void sub_4766F0() { sub_476700(0, -2); }

//----- (00476700) --------------------------------------------------------
void __cdecl sub_476700(int a1, int a2) {
	int v2;        // ebx
	char* v3;      // edi
	int v4;        // ebp
	int v5;        // ecx
	int v6;        // edx
	int v7;        // eax
	int v8;        // ebx
	signed int v9; // eax
	int v10;       // eax
	int v11;       // eax
	int v12;       // eax
	int v13;       // ecx

	v2 = a2;
	v3 = sub_437250();
	v4 = *((_DWORD*)v3 + 8);
	if (a2) {
		do {
			v5 = v2 + 100 * (nox_backbuffer_width - 2 * *(_DWORD*)v3) / nox_backbuffer_width;
			v6 = v5 * nox_backbuffer_width / 100;
			if (v2 >= 0)
				++v2;
			else
				--v2;
			v7 = v6 - v4;
			if (v6 - v4 < 0)
				v7 = v4 - v6;
		} while (v7 < 4);
	} else {
		v5 = a1;
	}
	if (v5 >= 40) {
		if (v5 > 100)
			v5 = 100;
	} else {
		v5 = 40;
	}
	dword_587000_149360 = v5;
	v8 = v5 * nox_backbuffer_height / 100;
	v9 = ((nox_backbuffer_width - v5 * nox_backbuffer_width / 100) / 2) & 0xFFFFFFFC;
	*(_DWORD*)v3 = v9;
	if (v9 < 0)
		*((_DWORD*)v3 + 2) = 0;
	v10 = (nox_backbuffer_height - v8) / 2;
	*((_DWORD*)v3 + 1) = v10;
	if (v10 < 0)
		*((_DWORD*)v3 + 3) = 0;
	v11 = nox_backbuffer_width - *(_DWORD*)v3 + 2;
	LOBYTE(v11) = v11 & 0xFC;
	*((_DWORD*)v3 + 2) = v11;
	if (v11 >= nox_backbuffer_width)
		*((_DWORD*)v3 + 2) = nox_backbuffer_width - 1;
	v12 = nox_backbuffer_height - *((_DWORD*)v3 + 1) - 1;
	*((_DWORD*)v3 + 3) = v12;
	if (v12 >= nox_backbuffer_height)
		*((_DWORD*)v3 + 3) = nox_backbuffer_height - 1;
	v13 = *((_DWORD*)v3 + 3) - *((_DWORD*)v3 + 1) + 1;
	*((_DWORD*)v3 + 8) = *((_DWORD*)v3 + 2) - *(_DWORD*)v3 + 1;
	*((_DWORD*)v3 + 9) = v13;
	dword_5d4594_1193188 = 1;
	dword_5d4594_3799524 = 1;
}

//----- (00476850) --------------------------------------------------------
void __cdecl sub_476850(int a1, unsigned __int8* a2) {
	int v2;           // eax
	int* v3;          // eax
	int v4;           // edi
	int v5;           // ecx
	_DWORD* v6;       // eax
	int v7;           // ebx
	int v8;           // ebp
	int v9;           // eax
	int v10;          // ecx
	int v11;          // edx
	unsigned int v12; // edi
	_BYTE* v13;       // eax
	unsigned int v14; // esi
	char* v15;        // edx
	unsigned int v16; // ebx
	int v17;          // ecx
	int v18;          // ecx
	unsigned int v19; // ebp
	unsigned int v20; // ebx
	int v21;          // edx
	_BYTE* v22;       // esi
	char* v23;        // edi
	_BYTE* v24;       // esi
	int v25;          // [esp+10h] [ebp-18h]
	int v26;          // [esp+14h] [ebp-14h]
	int i;            // [esp+14h] [ebp-14h]
	unsigned int v28; // [esp+18h] [ebp-10h]
	int v29;          // [esp+1Ch] [ebp-Ch]
	int v30;          // [esp+20h] [ebp-8h]
	unsigned int v31; // [esp+30h] [ebp+8h]

	if (*((int(__cdecl**)(int*, int))a2 + 75) == nox_thing_static_draw) {
		if (*((_DWORD*)a2 + 28) & 0x40000 && !(*((_DWORD*)a2 + 30) & 0x1000000))
			return;
		v2 = *(_DWORD*)(*((_DWORD*)a2 + 76) + 4);
	} else {
		v2 = *(_DWORD*)(*(_DWORD*)(*((_DWORD*)a2 + 76) + 4) + 4 * *((_DWORD*)a2 + 77));
	}
	v3 = (int*)(*(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492)(v2);
	if (v3) {
		v4 = *v3;
		v5 = v3[1];
		v6 = v3 + 2;
		v26 = v5;
		v7 = dword_5d4594_3798820;
		v8 = *v6 + *((_DWORD*)a2 + 3) - *a2;
		v9 = (int)(v6 + 2);
		v30 = v4;
		v10 = *(_DWORD*)(v9 - 4) + *((_DWORD*)a2 + 4) - *((__int16*)a2 + 53) - *((__int16*)a2 + 52) - a2[1];
		if (v8 < *(int*)&dword_5d4594_3798820 || v8 + v4 >= *(int*)&dword_5d4594_3798820 + dword_5d4594_3798800 ||
			v10 < *(int*)&dword_5d4594_3798824 || v10 + v26 >= *(int*)&dword_5d4594_3798824 + dword_5d4594_3798808) {
			*((_DWORD*)a2 + 86) = 0;
		} else {
			v11 = dword_587000_154948;
			if (*(int*)&dword_587000_154948 <= 0) {
				*((_DWORD*)a2 + 86) = 0;
				v7 = dword_5d4594_3798820;
				v11 = dword_587000_154948;
			}
			if (v11 - *((int*)a2 + 86) > 1 || v11 <= 0) {
				v12 = dword_5d4594_3798844;
				v13 = (_BYTE*)(v9 + 1);
				v28 = dword_5d4594_3798844;
				v25 = dword_5d4594_3798844 - dword_5d4594_3798796;
				v14 = v8 + dword_5d4594_3798796 + dword_5d4594_3798836 +
					  dword_5d4594_3798804 * (v10 + dword_5d4594_3798840 - dword_5d4594_3798824) - v7;
				v31 = v14;
				if (v14 >= *(int*)&dword_5d4594_3798844) {
					v14 -= v25;
					v31 = v14;
				}
				if (v26) {
					v29 = v26;
					do {
						v15 = (char*)v14;
						for (i = v30; i > 0; i -= v19) {
							v16 = (unsigned __int8)v13[1];
							v17 = *v13 & 0xF;
							v13 += 2;
							v18 = v17 - 1;
							v19 = v16;
							if (v18) {
								if (v18 == 1) {
									if ((unsigned int)v15 >= v12 || (unsigned int)&v15[v16] < v12) {
										memcpy(v15, v13, 4 * (v16 >> 2));
										v24 = &v13[4 * (v16 >> 2)];
										v23 = &v15[4 * (v16 >> 2)];
										v13 += v16;
										v15 += v16;
										memcpy(v23, v24, v16 & 3);
										v14 = v31;
										v12 = v28;
									} else {
										v20 = (unsigned int)&v15[v16 - v12];
										v19 -= v20;
										memcpy(v15, v13, v19);
										v21 = dword_5d4594_3798796;
										v22 = &v13[v19];
										v13 += v20 + v19;
										memcpy(*(void**)&dword_5d4594_3798796, v22, v20);
										v15 = (char*)(v20 + v21);
										v14 = v31;
										v12 = v28;
									}
								}
							} else {
								v15 += v16;
								if ((unsigned int)v15 >= v12)
									v15 -= v25;
							}
						}
						v14 += dword_5d4594_3798804;
						v31 = v14;
						if (v14 >= v12) {
							v14 -= v25;
							v31 = v14;
						}
						--v29;
					} while (v29);
				}
			} else {
				*((_DWORD*)a2 + 86) = v11;
			}
		}
	}
}

//----- (00476AE0) --------------------------------------------------------
int(__cdecl* __cdecl sub_476AE0(int a1, unsigned __int8* a2))(int* a1, int a2) {
	unsigned __int8* v2;                            // ebx
	int result;                                     // eax
	int(__cdecl * result2)(int*, int);              // eax
	int v4;                                         // eax
	int v5;                                         // edi
	int v6;                                         // ecx
	int v7;                                         // ebp
	char* v8;                                       // esi
	int v9;                                         // edx
	int v10;                                        // ecx
	unsigned int v11;                               // edi
	_BYTE* v12;                                     // esi
	int v13;                                        // ebx
	int v14;                                        // edx
	unsigned int v15;                               // ecx
	unsigned int v16;                               // ebx
	int v17;                                        // ecx
	int v18;                                        // eax
	int v19;                                        // eax
	int v20;                                        // ebp
	int v21;                                        // edi
	int v22;                                        // ebp
	int v23;                                        // ebx
	int v24;                                        // esi
	int v25;                                        // [esp+10h] [ebp-1Ch]
	int v26;                                        // [esp+14h] [ebp-18h]
	int v27;                                        // [esp+18h] [ebp-14h]
	int v28;                                        // [esp+18h] [ebp-14h]
	unsigned int v29;                               // [esp+1Ch] [ebp-10h]
	int v30;                                        // [esp+20h] [ebp-Ch]
	int v31;                                        // [esp+24h] [ebp-8h]
	int v32;                                        // [esp+28h] [ebp-4h]
	void(__cdecl * v33)(unsigned int, _BYTE*, int); // [esp+34h] [ebp+8h]

	v2 = a2;
	result2 = (int(__cdecl*)(int*, int)) * ((_DWORD*)a2 + 75);
	if (result2 == nox_thing_static_draw) {
		if (*((_DWORD*)a2 + 28) & 0x40000 && !(*((_DWORD*)a2 + 30) & 0x1000000))
			return result2;
		v4 = *(_DWORD*)(*((_DWORD*)a2 + 76) + 4);
	} else {
		v4 = *(_DWORD*)(*(_DWORD*)(*((_DWORD*)a2 + 76) + 4) + 4 * *((_DWORD*)a2 + 77));
	}
	result = (int)(*(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492)(v4);
	if (result) {
		if (dword_5d4594_3799624 == 1 || (v33 = sub_476DA0, !nox_client_texturedFloors_154956)) {
			v33 = sub_476D70;
		}
		v5 = *(_DWORD*)result;
		v6 = *((_DWORD*)result + 1);
		v27 = *((_DWORD*)result + 1);
		v7 = *((_DWORD*)result + 2) + *((_DWORD*)v2 + 3) - *v2;
		v8 = (char*)result + 16;
		result =
			(int)(*((_DWORD*)result + 3) + *((_DWORD*)v2 + 4) - *((__int16*)v2 + 53) - *((__int16*)v2 + 52) - v2[1]);
		v31 = v5;
		if (v7 < *(int*)&dword_5d4594_3798820 || v7 + v5 >= *(int*)&dword_5d4594_3798820 + dword_5d4594_3798800 ||
			(v9 = dword_5d4594_3798824, (int)result < *(int*)&dword_5d4594_3798824) ||
			(int)result + v6 >= *(int*)&dword_5d4594_3798824 + dword_5d4594_3798808) {
			*((_DWORD*)v2 + 86) = 0;
		} else {
			v10 = dword_587000_154948;
			if (*(int*)&dword_587000_154948 <= 0) {
				*((_DWORD*)v2 + 86) = 0;
				v9 = dword_5d4594_3798824;
				v10 = dword_587000_154948;
			}
			if (v10 - *((int*)v2 + 86) > 1 || v10 <= 0) {
				v11 = dword_5d4594_3798844;
				v12 = v8 + 1;
				v29 = dword_5d4594_3798844;
				v26 = dword_5d4594_3798844 - dword_5d4594_3798796;
				v13 = dword_5d4594_3798804 * ((_DWORD)result + dword_5d4594_3798840 - v9);
				v14 = v7 + dword_5d4594_3798836 - dword_5d4594_3798820;
				v15 = v13 + dword_5d4594_3798796 + 2 * v14;
				v25 = v13 + dword_5d4594_3798796 + 2 * v14;
				if (v15 >= *(int*)&dword_5d4594_3798844) {
					v15 -= v26;
					v25 = v15;
				}
				result = (int)(v27 - 1);
				if (v27) {
					v30 = v27;
					do {
						v16 = v15;
						v28 = v31;
						if (v31 > 0) {
							do {
								v17 = (unsigned __int8)v12[1];
								v18 = *v12 & 0xF;
								v12 += 2;
								v19 = v18 - 1;
								v32 = v17;
								v20 = 2 * v17;
								if (v19) {
									if (v19 == 1) {
										if (v16 >= v11 || v16 + v20 < v11) {
											v33(v16, v12, 2 * v17);
											v12 += v20;
											v16 += v20;
										} else {
											v21 = v16 + v20 - v29;
											v22 = v29 - v16;
											v33(v16, v12, v29 - v16);
											v23 = dword_5d4594_3798796;
											v24 = (int)&v12[v22];
											v33(dword_5d4594_3798796, (_BYTE*)v24, v21);
											v12 = (_BYTE*)(v21 + v24);
											v16 = v21 + v23;
											v11 = v29;
										}
									}
								} else {
									v16 += v20;
									if (v16 >= v11)
										v16 -= v26;
								}
								v28 -= v32;
							} while (v28 > 0);
							v15 = v25;
						}
						v15 += dword_5d4594_3798804;
						v25 = v15;
						if (v15 >= v11) {
							v15 -= v26;
							v25 = v15;
						}
						result = (int)--v30;
					} while (v30);
				}
			} else {
				*((_DWORD*)v2 + 86) = v10;
			}
		}
	}
	return result;
}

//----- (00476D70) --------------------------------------------------------
__int16 __cdecl sub_476D70(_DWORD* a1, int* a2, unsigned int a3) {
	_DWORD* v3;    // edi
	signed int v4; // ecx
	int* v5;       // esi
	int v6;        // eax

	v3 = a1;
	v4 = a3 >> 2;
	v5 = a2;
	if (a3 >> 2) {
		do {
			v6 = *v5;
			++v5;
			*v3 = v6;
			++v3;
		} while (v4-- > 1);
	}
	if (a3 & 3) {
		LOWORD(v6) = *(_WORD*)v5;
		*(_WORD*)v3 = *(_WORD*)v5;
	}
	return v6;
}

//----- (00476DA0) --------------------------------------------------------
void __cdecl sub_476DA0(unsigned int* a1, _DWORD* a2, unsigned int a3) {
	unsigned int* v3; // edi
	signed int v4;    // ecx
	_DWORD* v5;       // esi

	v3 = a1;
	v4 = a3 >> 2;
	v5 = a2;
	if (a3 >> 2) {
		do {
			*v3 = ((*v5 & 0xFFC0FFC0) >> 1) | *v5 & 0x1F001F;
			++v5;
			++v3;
		} while (v4-- > 1);
	}
	if (a3 & 3) {
		*(_WORD*)v3 = ((unsigned __int16)(*(_WORD*)v5 & 0xFFC0) >> 1) | *(_WORD*)v5 & 0x1F;
	}
}

//----- (00476E00) --------------------------------------------------------
int __cdecl sub_476E00(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 4 * a1 + 1096596) = *getMemU32Ptr(0x5D4594, 2598000);
	return result;
}

//----- (00476E20) --------------------------------------------------------
_DWORD* sub_476E20() {
	int v0;     // esi
	char* v1;   // eax
	_DWORD* v2; // esi

	v0 = 0;
	while (1) {
		v1 = sub_42F970(*(const char**)getMemAt(0x587000, v0 + 151272));
		*getMemU32Ptr(0x5D4594, v0 + 1096564) = v1;
		if (!v1)
			break;
		v0 += 4;
		if (v0 >= 32) {
			v2 = nox_window_new(0, 64, (nox_win_width - 100) / 2, (nox_win_height - 100) / 2, 1, 1, 0);
			nox_window_set_all_funcs(v2, 0, sub_476E90, 0);
			return v2;
		}
	}
	return 0;
}

//----- (00476E90) --------------------------------------------------------
int sub_476E90() {
	unsigned __int8* v0; // edi
	int v1;              // esi

	v0 = getMemAt(0x587000, 151208);
	v1 = 0;
	do {
		if (*getMemU32Ptr(0x5D4594, v1 + 1096596)) {
			nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x5D4594, v1 + 1096564), nox_win_width / 2 + *(_DWORD*)v0 - 16,
										  *((_DWORD*)v0 + 1) + nox_win_height / 2 - 41);
			if ((unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - *getMemU32Ptr(0x5D4594, v1 + 1096596)) > 3)
				*getMemU32Ptr(0x5D4594, v1 + 1096596) = 0;
		}
		v0 += 8;
		v1 += 4;
	} while ((int)v0 < (int)getMemAt(0x587000, 151272));
	return 1;
}

//----- (00476F10) --------------------------------------------------------
int __cdecl sub_476F10_drawable(nox_drawable* dr) {
	int a1 = dr;
	int result; // eax

	result = a1;
	if (dword_5d4594_1096640 == a1)
		dword_5d4594_1096640 = 0;
	if (dword_5d4594_1096644 == a1)
		dword_5d4594_1096644 = 0;
	return result;
}

//----- (00476F40) --------------------------------------------------------
unsigned int sub_476F40() {
	unsigned int result; // eax

	if (dword_5d4594_1096640)
		result = sub_578B00(*(int*)&dword_5d4594_1096640);
	else
		result = 0;
	return result;
}

//----- (00476F60) --------------------------------------------------------
int sub_476F60() {
	int result; // eax

	if (dword_5d4594_1096640)
		result = *(_DWORD*)(dword_5d4594_1096640 + 128);
	else
		result = 0;
	return result;
}

//----- (00476F80) --------------------------------------------------------
int sub_476F80() { return dword_5d4594_1096640; }

//----- (00476F90) --------------------------------------------------------
int sub_476F90() { return dword_5d4594_1096644; }

//----- (00476FA0) --------------------------------------------------------
void sub_476FA0() {
	int2* v0; // esi
	int2 v1;  // [esp+8h] [ebp-18h]
	int4 v2;  // [esp+10h] [ebp-10h]

	if (!*getMemU32Ptr(0x5D4594, 1096632))
		*getMemU32Ptr(0x5D4594, 1096632) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 151432));
	v0 = nox_client_getMousePos_4309F0();
	sub_437250();
	v1 = *v0;
	sub_473970(&v1, &v1);
	dword_5d4594_1096640 = 0;
	dword_5d4594_1096644 = 0;
	*getMemU32Ptr(0x5D4594, 1096628) = 0;
	v2.field_0 = v1.field_0 - 96;
	v2.field_8 = v1.field_0 + 96;
	v2.field_C = v1.field_4 + 96;
	v2.field_4 = v1.field_4 - 96;
	dword_5d4594_1096636 = 0;
	sub_49AB00(&v2, sub_477050, (int)&v1);
}

//----- (00477050) --------------------------------------------------------
void __cdecl sub_477050(int arg0, int a2) {
	int v2;    // esi
	int v3;    // eax
	int v4;    // eax
	int v5;    // ecx
	char* v6;  // eax
	int v7;    // eax
	float v8;  // ebp
	int v9;    // edi
	int v10;   // ebx
	int v11;   // eax
	int v12;   // edx
	int v13;   // edi
	int v14;   // ebx
	float v15; // eax
	int v16;   // edx
	int v17;   // eax
	int v18;   // edi
	int v19;   // ebx
	int v20;   // eax
	int v21;   // ecx
	int v22;   // edi
	float v23; // [esp+0h] [ebp-24h]
	float v24; // [esp+0h] [ebp-24h]
	float v25; // [esp+0h] [ebp-24h]
	float v26; // [esp+0h] [ebp-24h]
	float2 a3; // [esp+14h] [ebp-10h]
	float2 a1; // [esp+1Ch] [ebp-8h]
	int v29;   // [esp+28h] [ebp+4h]

	if (!*getMemU32Ptr(0x5D4594, 1096648))
		*getMemU32Ptr(0x5D4594, 1096648) = sub_44CFC0((CHAR*)getMemAt(0x587000, 151440));
	v2 = arg0;
	if (arg0 != *getMemU32Ptr(0x5D4594, 2614252)) {
		v3 = *(_DWORD*)(arg0 + 120);
		if ((v3 & 0x8000) == 0 && (!sub_4356C0(arg0, 0) || sub_4356C0(*(int*)getMemAt(0x5D4594, 2614252), 21))) {
			v4 = *(_DWORD*)(arg0 + 112);
			if (!(v4 & 2) || (v5 = *(_DWORD*)(arg0 + 116), !(v5 & 0x4000))) {
				if (v4 & 0x80400206 || *(_DWORD*)(arg0 + 108) == *getMemU32Ptr(0x5D4594, 1096648)) {
					if (sub_4984B0_drawable(arg0)) {
						if (!(*(_BYTE*)(arg0 + 112) & 4) ||
							(v6 = sub_417040(*(_DWORD*)(arg0 + 128))) != 0 && !(v6[3680] & 1)) {
							v7 = *(_DWORD*)(arg0 + 112);
							if ((!(v7 & 0x400000) || (*(_BYTE*)(arg0 + 116) & 0x80)) &&
								(!(v7 & 2) || *(_DWORD*)(arg0 + 276) != 10)) {
								v23 = (double)*(int*)(arg0 + 16) - *(float*)(arg0 + 100) -
									  (double)*(__int16*)(arg0 + 104);
								v29 = nox_float2int(v23);
								v24 = (double)*(int*)(v2 + 16) - *(float*)(v2 + 96) - (double)*(__int16*)(v2 + 104);
								v8 = COERCE_FLOAT(nox_float2int(v24));
								a3.field_0 = v8;
								if (*(_DWORD*)(v2 + 44) == 2) {
									v25 = *(float*)(v2 + 48) * *(float*)(v2 + 48);
									LODWORD(a3.field_0) = nox_float2int(v25);
									v17 = nox_float2int(*(float*)(v2 + 48));
									v18 = *(_DWORD*)(v2 + 12);
									v19 = *(_DWORD*)(v2 + 12) - v17;
									v20 = v18 + nox_float2int(*(float*)(v2 + 48));
									v21 = *(_DWORD*)(a2 + 4);
									if (v21 <= SLODWORD(v8)) {
										v8 = *(float*)&v29;
										if (v21 >= v29) {
											if (*(int*)a2 <= v19 || *(int*)a2 >= v20)
												return;
											goto LABEL_38;
										}
									}
									v15 = a3.field_0;
									v16 = (*(_DWORD*)a2 - v18) * (*(_DWORD*)a2 - v18) +
										  (v21 - LODWORD(v8)) * (v21 - LODWORD(v8));
								} else {
									if (*(_DWORD*)(v2 + 44) != 3)
										return;
									a1.field_0 = (double)*(int*)(v2 + 12);
									a1.field_4 = (double)SLODWORD(a3.field_0);
									a3.field_0 = (double)*(int*)a2;
									a3.field_4 = (double)*(int*)(a2 + 4);
									if (sub_57B850(&a1, (float*)(v2 + 44), &a3) ||
										(a1.field_4 = (double)v29, sub_57B850(&a1, (float*)(v2 + 44), &a3)) ||
										(v9 = *(_DWORD*)(v2 + 12) + nox_float2int(*(float*)(v2 + 72)),
										 v10 = v29 + nox_float2int(*(float*)(v2 + 76)),
										 v11 = LODWORD(v8) + nox_float2int(*(float*)(v2 + 76)), *(_DWORD*)a2 > v9) &&
											*(_DWORD*)a2 < *(int*)(v2 + 12) && (v12 = *(_DWORD*)(a2 + 4), v12 > v10) &&
											v12 < v11) {
									LABEL_38:
										v26 = (double)*(__int16*)(v2 + 104) + (double)*(int*)(v2 + 16) +
											  *(float*)(v2 + 96);
										v22 = nox_float2int(v26);
										if (v22 > *(int*)getMemAt(0x5D4594, 1096628)) {
											*getMemU32Ptr(0x5D4594, 1096628) = v22;
											dword_5d4594_1096640 = v2;
										}
										if (v2 != *getMemU32Ptr(0x5D4594, 2614252) &&
											v22 > *(int*)&dword_5d4594_1096636 && sub_57B400(v2)) {
											if (*getMemU32Ptr(0x5D4594, 2618908) &&
												*(_BYTE*)(*getMemU32Ptr(0x5D4594, 2618908) + 2251) == 1 &&
												*(_DWORD*)(v2 + 108) == *getMemU32Ptr(0x5D4594, 1096632)) {
												if (!dword_5d4594_1096644) {
													dword_5d4594_1096644 = v2;
													dword_5d4594_1096636 = 0;
												}
											} else {
												dword_5d4594_1096636 = v22;
												dword_5d4594_1096644 = v2;
											}
										}
										return;
									}
									v13 = *(_DWORD*)(v2 + 12) + nox_float2int(*(float*)(v2 + 80));
									v14 = v29 + nox_float2int(*(float*)(v2 + 84));
									LODWORD(v15) = LODWORD(v8) + nox_float2int(*(float*)(v2 + 84));
									if (*(int*)a2 < *(int*)(v2 + 12))
										return;
									if (*(int*)a2 >= v13)
										return;
									v16 = *(_DWORD*)(a2 + 4);
									if (v16 <= v14)
										return;
								}
								if (v16 >= SLODWORD(v15))
									return;
								goto LABEL_38;
							}
						}
					}
				}
			}
		}
	}
}

//----- (00477470) --------------------------------------------------------
void __cdecl nox_video_drawCursorSelectCircle2_477470(_DWORD* a1, int a2, int a3) {
	int v3;   // ebx
	int v4;   // ebx
	int v5;   // esi
	int v6;   // edi
	float v7; // [esp+0h] [ebp-14h]

	if (a3) {
		if (*(_DWORD*)(a3 + 44) == 2) {
			v4 = nox_float2int(*(float*)(a3 + 48));
		} else {
			if (*(_DWORD*)(a3 + 44) != 3) {
				v3 = 6;
			LABEL_8:
				v5 = *a1 + *(_DWORD*)(a3 + 12) - a1[4];
				v6 = *(_DWORD*)(a3 + 16) + a1[1] - a1[5];
				nox_client_drawSetColor_434460(a2);
				nox_client_drawEnableAlpha_434560(1);
				nox_client_drawSetAlpha_434580(0x80u);
				nox_video_drawCircle_4B0B90(v5, v6, v3 - 1);
				nox_video_drawCircle_4B0B90(v5, v6, v3 + 1);
				nox_client_drawEnableAlpha_434560(0);
				nox_video_drawCircle_4B0B90(v5, v6, v3);
				return;
			}
			v7 = *(float*)(a3 + 60) + *(float*)(a3 + 56);
			v4 = nox_float2int(v7) / 2;
		}
		v3 = v4 + 6;
		goto LABEL_8;
	}
}

//----- (00477530) --------------------------------------------------------
unsigned __int8 __cdecl sub_477530(int a1) {
	unsigned __int8 result; // al

	if (a1 == 1) {
		*getMemU32Ptr(0x5D4594, 1096652) = sub_45ACA0(0);
		*getMemU32Ptr(0x5D4594, 1096664) = sub_467C10();
		*getMemU32Ptr(0x5D4594, 1096660) = sub_4574D0();
		nox_client_renderGUI_80828 = 0;
		*getMemU32Ptr(0x5D4594, 1096656) = sub_473670();
		if (*getMemU32Ptr(0x5D4594, 1096656) == 1)
			sub_473610();
		sub_4512B0();
		sub_446780();
		sub_4AD9B0(1);
		sub_4C35B0(1);
		sub_46D6F0();
		result = sub_460660();
		*getMemU32Ptr(0x5D4594, 1096672) = 1;
	} else {
		*getMemU32Ptr(0x5D4594, 1096672) = 0;
		if (*getMemU32Ptr(0x5D4594, 1096652))
			sub_45AD70(0);
		if (*getMemU32Ptr(0x5D4594, 1096664))
			sub_467BB0();
		if (*getMemU32Ptr(0x5D4594, 1096660))
			sub_457500();
		result = getMemByte(0x5D4594, 1096656);
		if (*getMemU32Ptr(0x5D4594, 1096656))
			result = sub_473610();
		if (dword_587000_80832 == 1)
			nox_client_renderGUI_80828 = 1;
	}
	return result;
}

//----- (00477600) --------------------------------------------------------
int sub_477600() { return *getMemU32Ptr(0x5D4594, 1096672); }

//----- (00477610) --------------------------------------------------------
int __cdecl nox_client_setCursorType_477610(int a1) {
	int result; // eax

	result = a1;
	nox_client_mouseCursorType = a1;
	return result;
}

//----- (00477620) --------------------------------------------------------
int nox_client_getCursorType_477620() { return nox_client_mouseCursorType; }

//----- (00477630) --------------------------------------------------------
int sub_477630() { return dword_587000_151528; }

//----- (00477640) --------------------------------------------------------
int __cdecl sub_477640(int a1, int a2) {
	int result; // eax

	result = a1;
	dword_5d4594_1097192 = a1;
	dword_5d4594_1097196 = a2;
	return result;
}

//----- (00477660) --------------------------------------------------------
int sub_477660() {
	int result; // eax

	result = 0;
	dword_5d4594_1097192 = 0;
	dword_5d4594_1097196 = 0;
	return result;
}

//----- (00477670) --------------------------------------------------------
int sub_477670() { return dword_5d4594_1097196; }

//----- (00477680) --------------------------------------------------------
int sub_477680() { return dword_5d4594_1097188; }

//----- (00477690) --------------------------------------------------------
int __cdecl sub_477690(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1097188 = a1;
	return result;
}

//----- (004776A0) --------------------------------------------------------
void sub_4776A0() { dword_5d4594_1097188 = 0; }

//----- (004776B0) --------------------------------------------------------
void __cdecl sub_4776B0(wchar_t* a1) {
	if (a1) {
		if ((int)nox_wcslen(a1) >= 256) {
			nox_wcsncpy((wchar_t*)getMemAt(0x5D4594, 1096676), a1, 0xFFu);
			*getMemU16Ptr(0x5D4594, 1097186) = 0;
		} else {
			nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1096676), a1);
		}
	} else {
		*getMemU16Ptr(0x5D4594, 1096676) = 0;
	}
}

//----- (00477710) --------------------------------------------------------
char* sub_477710() {
	char* result; // eax

	memset(getMemAt(0x5D4594, 1097220), 0, 0x44u);
	*getMemU32Ptr(0x5D4594, 1097220) = sub_42FA20("CursorSelect");
	*getMemU32Ptr(0x5D4594, 1097224) = sub_42FA20("CursorGrab");
	*getMemU32Ptr(0x5D4594, 1097228) = sub_42FA20("CursorPickup");
	*getMemU32Ptr(0x5D4594, 1097232) = sub_42FA20("CursorTrade");
	*getMemU32Ptr(0x5D4594, 1097240) = sub_42FA20("CursorTarget");
	*getMemU32Ptr(0x5D4594, 1097236) = sub_42FA20("CursorTalk");
	*getMemU32Ptr(0x5D4594, 1097244) = sub_42FA20("CursorIdentify");
	*getMemU32Ptr(0x5D4594, 1097248) = sub_42FA20("CursorIdentifyNo");
	*getMemU32Ptr(0x5D4594, 1097252) = sub_42FA20("CursorRepair");
	*getMemU32Ptr(0x5D4594, 1097256) = sub_42FA20("CursorCreateGame");
	*getMemU32Ptr(0x5D4594, 1097260) = sub_42FA20("CursorBusy");
	*getMemU32Ptr(0x5D4594, 1097264) = sub_42FA20("CursorBuy");
	*getMemU32Ptr(0x5D4594, 1097268) = sub_42FA20("CursorSell");
	*getMemU32Ptr(0x5D4594, 1097272) = sub_42FA20("CursorUse");
	*getMemU32Ptr(0x5D4594, 1097276) = sub_42FA20("CursorMove");
	*getMemU32Ptr(0x5D4594, 1097280) = sub_42FA20("CursorPickupFar");
	result = sub_42FA20("CursorCaution");
	*getMemU32Ptr(0x5D4594, 1097284) = result;
	return result;
}

//----- (00477830) --------------------------------------------------------
char* nox_client_drawCursorAndTooltips_477830() {
	int2* v0;     // edi
	char* v1;     // eax
	int v2;       // eax
	char* result; // eax
	int v4;       // esi
	int v5;       // edi
	int v6;       // eax
	int v7;       // [esp+Ch] [ebp-3Ch]
	int v8;       // [esp+10h] [ebp-38h]
	int v9[13];   // [esp+14h] [ebp-34h]

	if (!*getMemU32Ptr(0x5D4594, 1097220))
		sub_477710();
	v0 = nox_client_getMousePos_4309F0();
	v9[0] = 0;
	v9[1] = 0;
	v9[2] = nox_win_width;
	v9[3] = nox_win_height;
	v9[8] = nox_win_width;
	v9[9] = nox_win_height;
	v9[4] = 0;
	v9[5] = 0;
	*getMemU32Ptr(0x5D4594, 1097204) = 0;
	dword_5d4594_1097208 = sub_43F320(0) + 4;
	if (dword_5d4594_1097188) // Dragging item
	{
		*(_DWORD*)(dword_5d4594_1097188 + 12) = v0->field_0;
		*(_DWORD*)(dword_5d4594_1097188 + 16) = v0->field_4;
		(*(void(__cdecl**)(int*, _DWORD))(dword_5d4594_1097188 + 300))(v9, dword_5d4594_1097188);
	}
	if (dword_5d4594_1097192) // Player is dragging spell or ability
	{
		v1 = sub_417040(*(int*)getMemAt(0x5D4594, 2616328));
		if (!v1 || v1[2251]) {
			v2 = sub_424A90(*(int*)&dword_5d4594_1097192); // Spell icon
			if (v2) {
				nox_client_drawImageAt_47D2C0(v2, v0->field_0 - 15, v0->field_4 - 15);
				goto LABEL_12;
			}
		} else {
			v2 = sub_425310(*(int*)&dword_5d4594_1097192, 0); // Ability icon
			if (v2) {
				nox_client_drawImageAt_47D2C0(v2, v0->field_0 - 15, v0->field_4 - 15);
				goto LABEL_12;
			}
		}
	}
LABEL_12:
	result = (char*)nox_video_cursorDrawImpl_477A30(*(int*)getMemAt(0x5D4594, 2523948), v0->field_0, v0->field_4);
	if (*getMemU16Ptr(0x5D4594, 1096676) && dword_587000_80840 == 1) {
		sub_43F840(0, (unsigned __int16*)getMemAt(0x5D4594, 1096676), &v8, &v7, 0);
		v4 = v0->field_0 - *getMemU32Ptr(0x5D4594, 1097204);
		v5 = v0->field_4 - dword_5d4594_1097208;
		v6 = v7 + 4;
		v7 += 4;
		if (v4 + v8 + 4 >= nox_win_width)
			v4 -= v8;
		if (v4 < 0)
			v4 = 0;
		if (v5 + v6 < nox_win_height) {
			if (v5 < 0)
				v5 = 0;
		} else {
			v5 = nox_win_height - v6;
		}
		nox_client_drawRectFilledAlpha_49CF10(v4, v5, v8 + 4, v6);
		sub_434390(*(int*)getMemAt(0x5D4594, 2589772));
		sub_43FAF0(0, getMemAt(0x5D4594, 1096676), v4 + 2, v5 + 2, 0, 0);
		result = *(char**)&dword_5d4594_3799468;
		if (dword_5d4594_3799468) {
			result = sub_437250();
			if (v4 < *(int*)result || v4 + v8 + 4 > *((_DWORD*)result + 2) || v5 < *((_DWORD*)result + 1) ||
				v7 + v5 > *((_DWORD*)result + 3)) {
				dword_5d4594_3799524 = 1;
			}
		}
	}
	return result;
}

//----- (00477EA0) --------------------------------------------------------
int sub_477EA0() {
	int2* v0; // eax
	int v1;   // edi
	int v2;   // esi

	v0 = nox_client_getMousePos_4309F0();
	v1 = v0->field_0;
	v2 = v0->field_4 + 22;
	nox_video_cursorDrawImpl_477A30(*(int*)getMemAt(0x5D4594, 2650656), v0->field_0, v2);
	sub_477EF0(*(int*)getMemAt(0x5D4594, 2614248), --v1, v2);
	return sub_477EF0(*(int*)getMemAt(0x5D4594, 2614248), v1 + 2, v2);
}

//----- (00477EF0) --------------------------------------------------------
int __cdecl sub_477EF0(int a1, int a2, int a3) {
	if (nox_client_mouseCursorType == 2)
		return sub_4C32A0(a2, a3, 5 - *getMemU32Ptr(0x5D4594, 2598000) % 5u, a1);
	nox_client_drawSetColor_434460(a1);
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawAddPoint_49F500(a2 - 4, a3 - 4);
	sub_49F570(8, 8);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(a2 + 4, a3 - 4);
	sub_49F570(-8, 8);
	nox_client_drawLineFromPoints_49E4B0();
	return nox_client_drawEnableAlpha_434560(0);
}

//----- (00477F80) --------------------------------------------------------
void sub_477F80() {
	char* v0; // eax

	if (!nox_video_cursorDrawIsThreaded) {
		if (dword_5d4594_3799468) {
			v0 = sub_437250();
			if (*(int*)&dword_5d4594_1097212 < *(int*)v0 || *(int*)&dword_5d4594_1097212 + 64 >= *((int*)v0 + 2) ||
				*(int*)&dword_5d4594_1097216 < *((int*)v0 + 1) ||
				*(int*)&dword_5d4594_1097216 + 64 >= *((int*)v0 + 3)) {
				nox_client_drawSetColor_434460(*(int*)getMemAt(0x5D4594, 2650656));
				nox_client_drawRectFilledOpaque_49CE30(dword_5d4594_1097212 + 32, dword_5d4594_1097216 + 32, 64, 64);
			}
		}
	}
}

//----- (00477FF0) --------------------------------------------------------
int sub_477FF0() { return sub_4BE7B0(*(int*)getMemAt(0x5D4594, 1097260)); }

//----- (00478000) --------------------------------------------------------
int sub_478000() {
	int result; // eax
	int v1;     // eax

	sub_467CD0();
	result = dword_5d4594_1097196;
	if (dword_5d4594_1097196) {
		v1 = sub_46AE00();
		sub_46ADE0(v1);
		result = sub_477660();
	}
	return result;
}

//----- (00478030) --------------------------------------------------------
int sub_478030() { return dword_5d4594_1098624; }

//----- (00478040) --------------------------------------------------------
int sub_478040() {
	__int16 v2; // [esp+0h] [ebp-2h]

	if (!dword_5d4594_1098624)
		return 0;
	v2 = 4809;
	sub_40EBC0(31, 0, &v2, 2);
	sub_467680();
	return 1;
}

//----- (00478080) --------------------------------------------------------
int __cdecl sub_478080(int a1) {
	char* v1;   // eax
	int result; // eax

	if (dword_5d4594_1098624 && (v1 = sub_4780A0(a1)) != 0)
		result = *(_DWORD*)v1;
	else
		result = 0;
	return result;
}

//----- (004780A0) --------------------------------------------------------
char* __cdecl sub_4780A0(int a1) {
	int v1;              // ebp
	unsigned __int8* v2; // edi
	int v3;              // esi
	unsigned __int8* v4; // edx
	int v5;              // eax
	unsigned __int8* v6; // ecx

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1098644);
	while (1) {
		v3 = 0;
		v4 = v2;
		do {
			if (*((_DWORD*)v4 - 1)) {
				v5 = 0;
				v6 = v4;
				while (*(_DWORD*)v6 != a1) {
					++v5;
					v6 += 4;
					if (v5 >= 32)
						goto LABEL_7;
				}
				return (char*)getMemAt(0x5D4594, 140 * (v1 + 10 * v3) + 1098636);
			}
		LABEL_7:
			++v3;
			v4 += 1400;
		} while (v3 < 6);
		v2 += 140;
		++v1;
		if ((int)v2 < (int)getMemAt(0x5D4594, 1100044))
			continue;
		return 0;
	}
}

//----- (00478110) --------------------------------------------------------
int sub_478110() {
	_DWORD* v0;          // eax
	int result;          // eax
	_DWORD* v2;          // eax
	unsigned __int8* v3; // edx
	unsigned __int8* v4; // eax
	int v5;              // ecx
	_DWORD* v6;          // esi
	int v7;              // [esp+4h] [ebp-8h]
	int v8;              // [esp+8h] [ebp-4h]

	*getMemU32Ptr(0x5D4594, 1098500) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1098504) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1098524) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1098492) = 0;
	*getMemU32Ptr(0x5D4594, 1098496) = 0;
	*getMemU32Ptr(0x5D4594, 1098528) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1098508) = 0;
	*getMemU32Ptr(0x5D4594, 1098512) = 0;
	v0 = nox_new_window_from_file("Shop.wnd", sub_478480);
	dword_5d4594_1098576 = v0;
	if (!v0)
		return 0;
	nox_window_set_all_funcs(v0, sub_478650, sub_478970, 0);
	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3806);
	sub_46B070((int)v2, sub_478E50);
	v3 = getMemAt(0x5D4594, 1098636);
	do {
		v4 = v3;
		v5 = 6;
		do {
			*(_DWORD*)v4 = 0;
			v4 += 1400;
			--v5;
		} while (v5);
		v3 += 140;
	} while ((int)v3 < (int)getMemAt(0x5D4594, 1100036));
	sub_478F10();
	nox_window_get_size(*(int*)&dword_5d4594_1098576, &v8, &v7);
	nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_1098576, nox_win_width - v8, nox_win_height - v7);
	nox_window_set_hidden(*(int*)&dword_5d4594_1098576, 1);
	sub_46ABB0(*(int*)&dword_5d4594_1098576, 0);
	*getMemU32Ptr(0x5D4594, 1098400) = sub_42F970("ShopBase");
	*getMemU32Ptr(0x5D4594, 1098404) = sub_42F970("ShopTradeMode");
	*getMemU32Ptr(0x5D4594, 1098408) = sub_42F970("ShopIdentifyMode");
	*getMemU32Ptr(0x5D4594, 1098412) = sub_42F970("ShopRepairMode");
	*getMemU32Ptr(0x5D4594, 1098416) = sub_42F970("ShopRepairMode");
	*getMemU32Ptr(0x5D4594, 1098420) = sub_42F970("ShopExitMode");
	*getMemU32Ptr(0x5D4594, 1098424) = sub_42F970("ShopInventoryBar1");
	*getMemU32Ptr(0x5D4594, 1098428) = sub_42F970("ShopInventoryBar2");
	*getMemU32Ptr(0x5D4594, 1098432) = sub_42F970("ShopInventorySlider");
	*getMemU32Ptr(0x5D4594, 1098436) = sub_42F970("ShopInventorySliderSelected");
	*getMemU32Ptr(0x5D4594, 1098448) = sub_42F970("ShopInventoryUp");
	*getMemU32Ptr(0x5D4594, 1098452) = sub_42F970("ShopInventoryUpSelected");
	*getMemU32Ptr(0x5D4594, 1098440) = sub_42F970("ShopInventorydown");
	*getMemU32Ptr(0x5D4594, 1098444) = sub_42F970("ShopInventorydownSelected");
	dword_5d4594_1098456 = sub_42F970("ShopTextBorder");
	*getMemU32Ptr(0x5D4594, 1098460) = sub_42F970("ShopkeeperPic");
	*getMemU32Ptr(0x5D4594, 1098464) = sub_42F970("ShopkeeperWarriorPic");
	*getMemU32Ptr(0x5D4594, 1098468) = sub_42F970("ShopkeeperConjurerPic");
	*getMemU32Ptr(0x5D4594, 1098472) = sub_42F970("ShopkeeperWizardPic");
	*getMemU32Ptr(0x5D4594, 1098476) = sub_42F970("ShopkeeperLandOfTheDeadPic");
	*getMemU32Ptr(0x5D4594, 1098480) = sub_42F970("ShopkeeperMagicShopPic");
	dword_5d4594_1098580 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3807);
	*getMemU32Ptr(0x5D4594, 1098584) = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3808);
	*getMemU32Ptr(0x5D4594, 1098588) = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3809);
	v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3806);
	nox_client_wndGetPosition_46AA60(v6, getMemAt(0x5D4594, 1098380), getMemAt(0x5D4594, 1098384));
	nox_window_get_size((int)v6, getMemAt(0x5D4594, 1098388), getMemAt(0x5D4594, 1098392));
	*getMemU32Ptr(0x5D4594, 1098388) += *getMemU32Ptr(0x5D4594, 1098380);
	*getMemU32Ptr(0x5D4594, 1098392) += *getMemU32Ptr(0x5D4594, 1098384);
	*(_DWORD*)(*(_DWORD*)(dword_5d4594_1098580 + 400) + 8) = 16;
	*(_DWORD*)(*(_DWORD*)(dword_5d4594_1098580 + 400) + 12) = 12;
	sub_46AE40(*(_DWORD*)(dword_5d4594_1098580 + 400), 0, -15);
	sub_4B5700(*(int*)&dword_5d4594_1098580, 0, 0, *(int*)getMemAt(0x5D4594, 1098432), *(int*)getMemAt(0x5D4594, 1098436),
			   *(int*)getMemAt(0x5D4594, 1098436));
	result = 1;
	dword_5d4594_1098592 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1098580 + 32) + 4);
	return result;
}

//----- (00478480) --------------------------------------------------------
int __cdecl sub_478480(int a1, int a2, int* a3, int a4) {
	int result; // eax
	int v5;     // esi
	int v7;     // ecx
	int v8;     // ecx

	if (a2 != 16391) {
		if (a2 == 16393) {
			dword_5d4594_1107036 = dword_5d4594_1098592 - a4;
			return 0;
		}
		return 0;
	}
	if (sub_45D9B0())
		return 0;
	v5 = sub_46B0A0(a3);
	sub_452D80(766, 100);
	switch (v5) {
	case 3801:
		if (!dword_5d4594_1098624)
			return 0;
		sub_478040();
		result = 0;
		break;
	case 3802:
		if (!dword_5d4594_1098624)
			return 0;
		if (dword_5d4594_1098628 == 4)
			sub_467680();
		nox_client_setCursorType_477610(12);
		dword_5d4594_1098628 = 3;
		if (sub_467C80())
			return 0;
		sub_467BB0();
		result = 0;
		break;
	case 3803:
		if (!dword_5d4594_1098624)
			return 0;
		sub_467650();
		dword_5d4594_1098628 = 4;
		result = 0;
		break;
	case 3804:
		if (dword_5d4594_1098624) {
			if (dword_5d4594_1098628 == 4)
				sub_467680();
			nox_client_setCursorType_477610(11);
			dword_5d4594_1098628 = 2;
		}
		return 0;
	case 3808:
		if (*(int*)&dword_5d4594_1107036 - 50 >= 0)
			v8 = dword_5d4594_1107036 - 50 - (dword_5d4594_1107036 - 50) % 50;
		else
			v8 = 0;
		dword_5d4594_1107036 = v8;
		nox_window_call_field_94(*(int*)&dword_5d4594_1098580, 16394, dword_5d4594_1098592 - v8, 0);
		result = 0;
		break;
	case 3809:
		if (*(int*)&dword_5d4594_1107036 + 50 <= *(int*)&dword_5d4594_1098592) {
			v7 = dword_5d4594_1107036 + 50 - (dword_5d4594_1107036 + 50) % 50;
			dword_5d4594_1107036 = dword_5d4594_1107036 + 50 - (dword_5d4594_1107036 + 50) % 50;
		} else {
			v7 = dword_5d4594_1098592;
			dword_5d4594_1107036 = dword_5d4594_1098592;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1098580, 16394, dword_5d4594_1098592 - v7, 0);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}
// 478585: variable 'v6' is possibly undefined

//----- (00478650) --------------------------------------------------------
int __cdecl sub_478650(int a1, int a2, unsigned int a3) {
	int v4;  // eax
	int2 v5; // [esp+0h] [ebp-8h]

	v5.field_0 = (unsigned __int16)a3;
	v5.field_4 = a3 >> 16;
	if (!sub_45D9B0()) {
		switch (a2) {
		case 5:
			v4 = sub_4281F0(&v5, (int4*)getMemAt(0x5D4594, 1098380));
			if (v4) {
				if (dword_5d4594_1098628 == 2)
					sub_478730(&v5.field_0);
			}
			break;
		case 19:
			if (dword_5d4594_1098628 == 2) {
				nox_window_call_field_94(*(int*)&dword_5d4594_1098576, 16391, *(int*)getMemAt(0x5D4594, 1098584), 0);
				return 1;
			}
			break;
		case 20:
			if (dword_5d4594_1098628 == 2) {
				nox_window_call_field_94(*(int*)&dword_5d4594_1098576, 16391, *(int*)getMemAt(0x5D4594, 1098588), 0);
				return 1;
			}
			break;
		default:
			return 0;
		}
	}
	return 1;
}
// 478703: variable 'v4' is possibly undefined

//----- (00478850) --------------------------------------------------------
void __cdecl sub_478850(int a1, __int16 a2, int a3, int a4) {
	if (a4) {
		if (a4 == 1)
			sub_478880(a3, a2);
		else
			sub_4788F0(a3, a4);
	}
}

//----- (00478970) --------------------------------------------------------
int sub_478970() {
	int result; // eax
	int2 a1;    // [esp+0h] [ebp-8h]

	a1.field_0 = nox_win_width - NOX_DEFAULT_WIDTH;
	a1.field_4 = nox_win_height - NOX_DEFAULT_HEIGHT;
	nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1098400), nox_win_width - NOX_DEFAULT_WIDTH,
								  nox_win_height - NOX_DEFAULT_HEIGHT);
	if (dword_5d4594_1098628 == 2) {
		nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1098404), a1.field_0, a1.field_4);
		sub_478C80();
		result = 1;
	} else if (dword_5d4594_1098628 == 3) {
		nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1098408), a1.field_0, a1.field_4);
		sub_478B10(&a1);
		result = 1;
	} else if (dword_5d4594_1098628 == 1) {
		nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1098412), a1.field_0, a1.field_4);
		sub_478A70(&a1);
		result = 1;
	} else {
		if (dword_5d4594_1098628 == 4) {
			nox_client_drawImageAt_47D2C0(*(int*)getMemAt(0x5D4594, 1098416), a1.field_0, a1.field_4);
			sub_478BC0(&a1.field_0);
		}
		result = 1;
	}
	return result;
}

//----- (00478A70) --------------------------------------------------------
int __cdecl sub_478A70(int2* a1) {
	_DWORD* v1; // esi
	int result; // eax
	int v3;     // [esp+4h] [ebp-10h]
	int v4;     // [esp+8h] [ebp-Ch]
	int v5;     // [esp+Ch] [ebp-8h]
	int v6;     // [esp+10h] [ebp-4h]

	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3806);
	nox_client_wndGetPosition_46AA60(v1, &v5, &v6);
	nox_window_get_size((int)v1, &v4, &v3);
	sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
	nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1098456, a1->field_0, a1->field_4);
	result = dword_5d4594_1098604;
	if (dword_5d4594_1098604)
		result = sub_43FAF0(0, *(_WORD**)&dword_5d4594_1098604, v5 + 8, v6 + 8, v4 - 16, v3 - 16);
	return result;
}

//----- (00478C80) --------------------------------------------------------
int sub_478C80() {
	int v0;              // edi
	int v1;              // ebx
	unsigned __int8* v2; // esi
	int v3;              // edi
	int v4;              // ebp
	int v6;              // [esp+10h] [ebp-58h]
	unsigned __int8* v7; // [esp+14h] [ebp-54h]
	unsigned int v8;     // [esp+18h] [ebp-50h]
	int v9;              // [esp+1Ch] [ebp-4Ch]
	int v10;             // [esp+20h] [ebp-48h]
	wchar_t v11[32];     // [esp+28h] [ebp-40h]

	v8 = sub_4674A0();
	sub_49F7F0();
	nox_client_copyRect_49F6F0(*(int*)getMemAt(0x5D4594, 1098380), *(int*)getMemAt(0x5D4594, 1098384),
							   *getMemU32Ptr(0x5D4594, 1098388) - *getMemU32Ptr(0x5D4594, 1098380),
							   *getMemU32Ptr(0x5D4594, 1098392) - *getMemU32Ptr(0x5D4594, 1098384));
	v0 = *getMemU32Ptr(0x5D4594, 1098380);
	v10 = *getMemU32Ptr(0x5D4594, 1098380);
	v1 = *getMemU32Ptr(0x5D4594, 1098384) - dword_5d4594_1107036;
	v2 = getMemAt(0x5D4594, 1098640);
	v9 = sub_43F320(0);
	v6 = 0;
	v7 = getMemAt(0x5D4594, 1098640);
	do {
		if (v1 > *(int*)getMemAt(0x5D4594, 1098384) - 50) {
			nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x5D4594, 4 * (v6 % 2) + 1098424), v0, v1);
			v3 = v0 + 5;
			v4 = 6;
			do {
				if (*(_DWORD*)v2) {
					*(_DWORD*)(*((_DWORD*)v2 - 1) + 12) = v3 + 20;
					*(_DWORD*)(*((_DWORD*)v2 - 1) + 16) = v1 + 25;
					(*(void(__cdecl**)(unsigned __int8*, _DWORD))(*((_DWORD*)v2 - 1) + 300))(getMemAt(0x5D4594, 1098492),
																							 *((_DWORD*)v2 - 1));
					if (v8 < *((_DWORD*)v2 + 33))
						nox_client_drawRectFilledAlpha_49CF10(v3 - 5, v1, 50, 50);
					if (*(_DWORD*)v2 > 1u) {
						nox_swprintf(v11, L"%d", *(_DWORD*)v2);
						sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
						sub_43FAF0(0, v11, v3, v1 + 5, 320, 0);
					}
					nox_swprintf(v11, L"%d", *((_DWORD*)v2 + 33));
					sub_434390(*(int*)getMemAt(0x5D4594, 2589772));
					sub_43FAF0(0, v11, v3, v1 - v9 + 45, 320, 0);
				}
				v3 += 50;
				v2 += 1400;
				--v4;
			} while (v4);
			v2 = v7;
			v0 = v10;
		}
		v1 += 50;
		if (v1 >= *(int*)getMemAt(0x5D4594, 1098392))
			break;
		v2 += 140;
		++v6;
		v7 = v2;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 1100040));
	return sub_49F860();
}

//----- (00478E50) --------------------------------------------------------
int __cdecl sub_478E50(int a1, int a2, unsigned int a3) {
	int v3;       // ecx
	int v4;       // edx
	int v5;       // edx
	wchar_t** v6; // eax
	wchar_t* v7;  // eax

	if (dword_5d4594_1098628 == 2) {
		v3 = ((unsigned __int16)a3 - *getMemU32Ptr(0x5D4594, 1098380)) / 50;
		v4 = (int)((a3 >> 16) - *getMemU32Ptr(0x5D4594, 1098384) + dword_5d4594_1107036) / 50;
		if (v3 >= 6)
			v3 = 5;
		if (v4 >= 10)
			v4 = 9;
		v5 = 35 * (v4 + 10 * v3);
		v6 = (wchar_t**)getMemAt(0x5D4594, 4 * v5 + 1098636);
		if (*getMemU32Ptr(0x5D4594, 4 * v5 + 1098640)) {
			*((_DWORD*)*v6 + 32) = v6[2];
			v7 = sub_4BF050(*v6);
			sub_4776B0(v7);
		}
	}
	return 1;
}

//----- (00478F10) --------------------------------------------------------
_DWORD* sub_478F10() {
	unsigned __int8* v0; // esi
	int v1;              // ebx
	void* v2;            // edi
	_DWORD* result;      // eax
	unsigned __int8* v4; // [esp+10h] [ebp-4h]

	v4 = getMemAt(0x5D4594, 1098636);
	do {
		v0 = v4;
		v1 = 6;
		do {
			if (*(_DWORD*)v0)
				sub_45A4B0(*(_QWORD**)v0);
			*(_DWORD*)v0 = 0;
			v2 = v0 + 8;
			*((_DWORD*)v0 + 1) = 0;
			v0 += 1400;
			memset(v2, 0, 0x80u);
			*((_DWORD*)v0 - 316) = 0;
			--v1;
		} while (v1);
		result = v4 + 140;
		v4 += 140;
	} while ((int)v4 < (int)getMemAt(0x5D4594, 1100036));
	dword_5d4594_1107036 = 0;
	return result;
}

//----- (00478F80) --------------------------------------------------------
int sub_478F80() {
	int result; // eax

	sub_478F10();
	sub_44D8F0();
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1098576);
	result = 0;
	dword_5d4594_1098576 = 0;
	dword_5d4594_1098624 = 0;
	dword_5d4594_1098628 = 1;
	dword_5d4594_1098596 = 0;
	dword_5d4594_1098600 = 0;
	dword_5d4594_1098604 = 0;
	*getMemU32Ptr(0x5D4594, 1098608) = 0;
	dword_5d4594_1098616 = 0;
	return result;
}

//----- (004790F0) --------------------------------------------------------
char* __cdecl sub_4790F0(int a1) {
	_DWORD* v1;   // esi
	char* result; // eax

	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3805);
	if (!*getMemU32Ptr(0x5D4594, 1107040)) {
		*getMemU32Ptr(0x5D4594, 1098396) = sub_44CFC0((CHAR*)getMemAt(0x587000, 152868));
		*getMemU32Ptr(0x5D4594, 1098560) = sub_44CFC0((CHAR*)getMemAt(0x587000, 152880));
		*getMemU32Ptr(0x5D4594, 1098556) = sub_44CFC0((CHAR*)getMemAt(0x587000, 152904));
		*getMemU32Ptr(0x5D4594, 1098564) = sub_44CFC0((CHAR*)getMemAt(0x587000, 152928));
		*getMemU32Ptr(0x5D4594, 1098572) = sub_44CFC0((CHAR*)getMemAt(0x587000, 152952));
		*getMemU32Ptr(0x5D4594, 1098568) = sub_44CFC0((CHAR*)getMemAt(0x587000, 152976));
		*getMemU32Ptr(0x5D4594, 1098484) = sub_44CFC0((CHAR*)getMemAt(0x587000, 152996));
		*getMemU32Ptr(0x5D4594, 1097292) = sub_44CFC0((CHAR*)getMemAt(0x587000, 153016));
		*getMemU32Ptr(0x5D4594, 1107040) = 1;
	}
	if (a1 == *getMemU32Ptr(0x5D4594, 1098396)) {
		result = sub_42F970("ShopKeeperPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098560)) {
		result = sub_42F970("ShopKeeperWarriorPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098556)) {
		result = sub_42F970("ShopKeeperConjurerPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098564)) {
		result = sub_42F970("ShopKeeperWizardPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098572)) {
		result = sub_42F970("ShopKeeperLandOfTheDeadPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098568)) {
		result = sub_42F970("ShopKeeperMagicShopPic");
		v1[15] = result;
	} else if (a1 == *getMemU32Ptr(0x5D4594, 1098484)) {
		result = sub_42F970("ShopKeeperPurplePic");
		v1[15] = result;
	} else {
		if (a1 == *getMemU32Ptr(0x5D4594, 1097292))
			result = sub_42F970("ShopKeeperBrownPic");
		else
			result = sub_42F970("ShopKeeperPic");
		v1[15] = result;
	}
	return result;
}

//----- (00479280) --------------------------------------------------------
int sub_479280() {
	int result; // eax

	result = dword_5d4594_1098624;
	if (dword_5d4594_1098624) {
		sub_467680();
		dword_5d4594_1098624 = 0;
		dword_5d4594_1098628 = 0;
		sub_478F10();
		sub_44D8F0();
		nox_window_set_hidden(*(int*)&dword_5d4594_1098576, 1);
		sub_46ABB0(*(int*)&dword_5d4594_1098576, 0);
		sub_467C10();
		nox_client_setCursorType_477610(0);
		result = nox_client_renderGUI_80828;
		if (!nox_client_renderGUI_80828 && *getMemU32Ptr(0x5D4594, 1098612) == 1)
			nox_client_renderGUI_80828 = 1;
	}
	return result;
}

//----- (00479300) --------------------------------------------------------
_DWORD* __cdecl sub_479300(int a1, int a2, int a3, __int16 a4, int a5) {
	_DWORD* result; // eax
	_DWORD* v6;     // ebx
	int* v7;        // edi
	int i;          // esi

	result = sub_4793C0(a1);
	v6 = result;
	if (result) {
		if (!*result) {
			result = nox_new_drawable_for_thing(a1);
			*v6 = result;
			if (!result)
				return result;
			result[30] |= 0x40000000u;
			*(_WORD*)(*v6 + 294) = a4;
			*(_WORD*)(*v6 + 292) = a4;
			if (*(_DWORD*)(*v6 + 112) & 0x13001000) {
				v7 = (int*)(*v6 + 432);
				for (i = 0; i < 4; ++i) {
					if (*(char*)(i + a5) == -1)
						*v7 = 0;
					else
						*v7 = sub_413330(*(unsigned __int8*)(i + a5));
					++v7;
				}
			}
			v6[1] = 0;
		}
		v6[v6[1] + 2] = a2;
		result = (_DWORD*)(v6[1] + 1);
		v6[34] = a3;
		v6[1] = result;
	}
	return result;
}

//----- (004793C0) --------------------------------------------------------
char* __cdecl sub_4793C0(int a1) {
	int v1;              // ebx
	unsigned __int8* v2; // esi
	int v3;              // ecx
	unsigned __int8* v4; // eax

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1098636);
	while (1) {
		v3 = 0;
		v4 = v2;
		do {
			if (*((_DWORD*)v4 + 1) && *(_DWORD*)(*(_DWORD*)v4 + 108) == a1 &&
				!(*(_DWORD*)(*(_DWORD*)v4 + 112) & 0x4000000)) {
				return (char*)getMemAt(0x5D4594, 140 * (v1 + 10 * v3) + 1098636);
			}
			++v3;
			v4 += 1400;
		} while (v3 < 6);
		v2 += 140;
		++v1;
		if ((int)v2 < (int)getMemAt(0x5D4594, 1100036))
			continue;
		break;
	}
	return sub_479430();
}

//----- (00479430) --------------------------------------------------------
char* sub_479430() {
	int v0;              // esi
	unsigned __int8* v1; // edx
	int v2;              // eax
	unsigned __int8* v3; // ecx

	v0 = 0;
	v1 = getMemAt(0x5D4594, 1098640);
	while (1) {
		v2 = 0;
		v3 = v1;
		do {
			if (!*(_DWORD*)v3)
				return (char*)getMemAt(0x5D4594, 140 * (v0 + 10 * v2) + 1098636);
			++v2;
			v3 += 1400;
		} while (v2 < 6);
		v1 += 140;
		++v0;
		if ((int)v1 < (int)getMemAt(0x5D4594, 1100040))
			continue;
		break;
	}
	return 0;
}

//----- (00479480) --------------------------------------------------------
char* __cdecl sub_479480(int a1) {
	char* result; // eax
	char* v2;     // esi

	result = sub_4780A0(a1);
	v2 = result;
	if (result) {
		sub_4794D0((int)result, a1);
		result = (char*)(*((_DWORD*)v2 + 1) - 1);
		*((_DWORD*)v2 + 1) = result;
		if (!result) {
			result = (char*)sub_45A4B0(*(_QWORD**)v2);
			*(_DWORD*)v2 = 0;
			*((_DWORD*)v2 + 34) = 0;
		}
	}
	return result;
}

//----- (004794D0) --------------------------------------------------------
int __cdecl sub_4794D0(int a1, int a2) {
	int result; // eax
	_DWORD* i;  // ecx
	_DWORD* v4; // ecx
	int v5;     // edx

	result = 0;
	for (i = (_DWORD*)(a1 + 8); *i != a2; ++i) {
		if (++result >= 32)
			return result;
	}
	if (result < 31) {
		v4 = (_DWORD*)(a1 + 4 * result + 8);
		v5 = 31 - result;
		do {
			result = v4[1];
			*v4 = result;
			++v4;
			--v5;
		} while (v5);
	}
	*(_DWORD*)(a1 + 132) = 0;
	return result;
}

//----- (00479590) --------------------------------------------------------
int sub_479590() { return dword_5d4594_1098628; }

//----- (004795A0) --------------------------------------------------------
void __cdecl sub_4795A0(int a1) {
	if (dword_5d4594_1098628 == 4) {
		if (a1 != 4)
			sub_467680();
		dword_5d4594_1098628 = a1;
	} else {
		dword_5d4594_1098628 = a1;
	}
}

//----- (00479690) --------------------------------------------------------
int __cdecl sub_479690(int a1, __int16 a2, __int16 a3, int a4) {
	int result; // eax

	result = a4;
	dword_5d4594_1098616 = 0;
	if (a4) {
		if (a4 == 1)
			result = sub_4796D0(a2);
		else
			result = sub_479700(a3, a4);
	}
	return result;
}

//----- (004796D0) --------------------------------------------------------
int __cdecl sub_4796D0(__int16 a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 24;
	*(_WORD*)&v2[2] = a1;
	return sub_40EBC0(31, 0, v2, 4);
}

//----- (00479700) --------------------------------------------------------
int __cdecl sub_479700(__int16 a1, char a2) {
	char v3[5]; // [esp+0h] [ebp-8h]

	v3[0] = -55;
	v3[1] = 25;
	*(_WORD*)&v3[2] = a1;
	v3[4] = a2;
	return sub_40EBC0(31, 0, v3, 5);
}

//----- (00479810) --------------------------------------------------------
void sub_479810() { dword_5d4594_1098620 = 0; }

//----- (00479820) --------------------------------------------------------
int __cdecl sub_479820(int a1, __int16 a2) {
	int result; // eax

	result = sub_479840(a2);
	dword_5d4594_1098620 = 0;
	return result;
}

//----- (00479840) --------------------------------------------------------
int __cdecl sub_479840(__int16 a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 26;
	*(_WORD*)&v2[2] = a1;
	return sub_40EBC0(31, 0, v2, 4);
}

//----- (00479870) --------------------------------------------------------
BOOL sub_479870() { return dword_5d4594_1098628 == 2; }

//----- (00479880) --------------------------------------------------------
bool __cdecl sub_479880(_DWORD* a1) { return sub_4281F0((int2*)a1, (int4*)getMemAt(0x5D4594, 1098380)); }

//----- (004798A0) --------------------------------------------------------
int __cdecl sub_4798A0(_DWORD* a1) {
	int v1;              // eax
	int v2;              // ecx
	int v3;              // edx
	int v4;              // edx
	unsigned __int8* v5; // eax

	v1 = sub_4281F0((int2*)a1, (int4*)getMemAt(0x5D4594, 1098380));
	if (!v1)
		return 0;
	v2 = (*a1 - *getMemU32Ptr(0x5D4594, 1098380)) / 50;
	v3 = (a1[1] - *getMemU32Ptr(0x5D4594, 1098384) + dword_5d4594_1107036) / 50;
	if (v2 >= 6)
		v2 = 5;
	if (v3 >= 10)
		v3 = 9;
	v4 = 35 * (v3 + 10 * v2);
	v5 = getMemAt(0x5D4594, 4 * v4 + 1098636);
	if (!*getMemU32Ptr(0x5D4594, 4 * v4 + 1098640))
		return 0;
	*(_DWORD*)(*(_DWORD*)v5 + 128) = *((_DWORD*)v5 + 2);
	return *(_DWORD*)v5;
}
// 4798B5: variable 'v1' is possibly undefined

//----- (00479950) --------------------------------------------------------
int sub_479950() {
	void* v2; // [esp+0h] [ebp-4h]

	if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1123524) == 1)
		return 0;
	*getMemU8Ptr(0x5D4594, 1123516) = 0;
	LOWORD(v2) = 720;
	BYTE2(v2) = 0;
	sub_40EBC0(31, 0, &v2, 3);
	return 1;
}

//----- (004799A0) --------------------------------------------------------
int sub_4799A0() {
	int result;  // eax
	_DWORD* v1;  // edi
	_DWORD* v2;  // ebp
	_DWORD* v3;  // eax
	int v4;      // esi
	_DWORD* v5;  // ebx
	char* v6;    // eax
	_DWORD* v7;  // eax
	char* v8;    // [esp-18h] [ebp-1Ch]
	char* v9;    // [esp-14h] [ebp-18h]
	_DWORD* v10; // [esp+0h] [ebp-4h]

	*getMemU32Ptr(0x5D4594, 1107052) = sub_4344A0(240, 128, 64);
	result = nox_new_window_from_file("Dialog.wnd", sub_479B00);
	dword_5d4594_1123524 = result;
	if (result) {
		sub_46B300(result, sub_479BE0);
		sub_46B340(*(int*)&dword_5d4594_1123524, sub_479CB0);
		sub_46B070(*(int*)&dword_5d4594_1123524, sub_479D00);
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1123524, 3904);
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1123524, 3903);
		v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1123524, 3902);
		v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1123524, 3901);
		v4 = (int)v3;
		v5 = (_DWORD*)v3[8];
		v9 = sub_42F970("UISliderLit");
		v8 = sub_42F970("UISliderLit");
		v6 = sub_42F970("UISlider");
		sub_4B5700((int)v1, 0, 0, (int)v6, (int)v8, (int)v9);
		sub_46B280((int)v1, v4);
		sub_46B280((int)v2, v4);
		sub_46B280((int)v10, v4);
		v5[9] = v1;
		v5[7] = v2;
		v5[8] = v10;
		v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1123524, 3906);
		sub_46B340((int)v7, sub_479C40);
		sub_46ABB0(*(int*)&dword_5d4594_1123524, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1123524, 1);
		dword_5d4594_1123520 = 0;
		result = 1;
	}
	return result;
}

//----- (00479B00) --------------------------------------------------------
int __cdecl sub_479B00(int a1, int a2, int* a3, int a4) {
	int v3;     // esi
	int result; // eax

	if (a2 != 16391)
		return 0;
	v3 = sub_46B0A0(a3);
	if (sub_45D9B0())
		return 0;
	sub_452D80(766, 100);
	switch (v3) {
	case 3906:
		sub_479950();
		result = 0;
		break;
	case 3907:
		sub_44D900(*(int*)getMemAt(0x5D4594, 1115312), 100);
		result = 0;
		break;
	case 3908:
		*getMemU8Ptr(0x5D4594, 1123516) = 1;
		LOWORD(a2) = 720;
		BYTE2(a2) = 1;
		sub_40EBC0(31, 0, &a2, 3);
		result = 0;
		break;
	case 3909:
		*getMemU8Ptr(0x5D4594, 1123516) = 2;
		BYTE2(a2) = 2;
		LOWORD(a2) = 720;
		sub_40EBC0(31, 0, &a2, 3);
		return 0;
	default:
		return 0;
	}
	return result;
}
// 479B4D: variable 'v4' is possibly undefined

//----- (00479BE0) --------------------------------------------------------
int __cdecl sub_479BE0(_DWORD* a1, int a2, unsigned int a3, int a4) {
	switch (a2) {
	case 5:
	case 6:
	case 7:
	case 9:
	case 10:
	case 11:
	case 13:
	case 14:
	case 15:
		sub_46AAB0(a1, (unsigned __int16)a3, a3 >> 16);
		break;
	default:
		return 1;
	}
	return 1;
}

//----- (00479C40) --------------------------------------------------------
int __cdecl sub_479C40(_DWORD* a1, int a2) {
	char v2;   // bl
	int yTop;  // [esp+8h] [ebp-8h]
	int xLeft; // [esp+Ch] [ebp-4h]

	v2 = sub_430B40_get_mouse_prev_seq();
	if (!sub_44D930() && (v2 & 0x7Fu) < 0x1E && v2 & 8) {
		nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
		sub_49CD30(xLeft, yTop, a1[2], a1[3] - 2, *(int*)getMemAt(0x5D4594, 1107052), 4);
	}
	return sub_4A81D0((int)a1, a2);
}

//----- (00479CB0) --------------------------------------------------------
int __cdecl sub_479CB0(int a1, int a2) {
	int v2; // esi
	int v4; // [esp+4h] [ebp-8h]
	int v5; // [esp+8h] [ebp-4h]

	v2 = *(_DWORD*)(a2 + 24);
	nox_client_wndGetPosition_46AA60(*(_DWORD**)&dword_5d4594_1123524, &v4, &v5);
	nox_client_drawImageAt_47D2C0(v2, nox_win_width - NOX_DEFAULT_WIDTH, nox_win_height - NOX_DEFAULT_HEIGHT);
	return 1;
}

//----- (00479D00) --------------------------------------------------------
int sub_479D00() { return 1; }

//----- (00479D10) --------------------------------------------------------
int sub_479D10() {
	int result; // eax

	sub_46C4E0(*(_DWORD**)&dword_5d4594_1123524);
	result = 0;
	dword_5d4594_1123524 = 0;
	dword_5d4594_1123520 = 0;
	return result;
}

//----- (0047A1F0) --------------------------------------------------------
int sub_47A1F0() {
	_DWORD* v0; // eax
	int result; // eax

	v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1123524, 3901);
	nox_window_call_field_94((int)v0, 16399, 0, 0);
	sub_46ABB0(*(int*)&dword_5d4594_1123524, 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_1123524, 1);
	sub_44D8F0();
	result = nox_client_renderGUI_80828;
	dword_5d4594_1123520 = 0;
	if (!nox_client_renderGUI_80828 && *getMemU32Ptr(0x587000, 153436) == 1)
		nox_client_renderGUI_80828 = 1;
	return result;
}

//----- (0047A260) --------------------------------------------------------
int sub_47A260() { return dword_5d4594_1123520; }

//----- (0047A270) --------------------------------------------------------
int sub_47A270() {
	int result; // eax

	sub_47D150();
	if (!dword_5d4594_3801780)
		return 0;
	sub_47A310((LPCSTR)getMemAt(0x587000, 153712));
	sub_47A650();
	result = (int)malloc(336 * dword_5d4594_1123532);
	dword_5d4594_1189584 = result;
	if (result) {
		result = (int)malloc(0x12C000u);
		*getMemU32Ptr(0x5D4594, 1189588) = result;
		if (result) {
			result = (int)malloc(0x12C000u);
			dword_5d4594_1189592 = result;
			if (result) {
				result = (int)malloc(0x12C000u);
				dword_5d4594_1189596 = result;
				if (result) {
					sub_47A650();
					result = 1;
				}
			}
		}
	}
	return result;
}

//----- (0047A310) --------------------------------------------------------
DWORD __cdecl sub_47A310(LPCSTR lpPathName) {
	DWORD result;                          // eax
	char* v3;                              // edx
	const char* v4;                        // ebp
	HANDLE v5;                             // ebx
	char* v6;                              // edx
	char* v7;                              // edx
	int v8;                                // [esp+10h] [ebp-348h]
	HANDLE v9;                             // [esp+14h] [ebp-344h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+18h] [ebp-340h]
	CHAR Buffer[512];                      // [esp+158h] [ebp-200h]

	dword_5d4594_1189600 = 0;
	v8 = 0;
	if (SetCurrentDirectoryA(lpPathName) || (result = GetLastError()) == 0) {
		GetCurrentDirectoryA(0x200u, Buffer);
		v3 = (char*)getMemAt(0x5D4594, 512 * (dword_5d4594_1189600)++ + 1124048);
		strcpy(v3, Buffer);
		if (*(int*)&dword_5d4594_1189600 <= 0) {
		LABEL_27:
			SetCurrentDirectoryA(Buffer);
			result = SetCurrentDirectoryA((LPCSTR)getMemAt(0x587000, 153752));
		} else {
			v4 = (const char*)getMemAt(0x5D4594, 1124048);
			while (SetCurrentDirectoryA(v4) || !GetLastError()) {
				v5 = FindFirstFileA((LPCSTR)getMemAt(0x587000, 153724), &FindFileData);
				v9 = v5;
				if (v5 != (HANDLE)-1) {
					if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
						strcmp(FindFileData.cFileName, "..")) {
						v6 = (char*)getMemAt(0x5D4594, 512 * dword_5d4594_1189600 + 1124048);
						strcpy(v6, v4);
						if (v4[strlen(v4) - 1] != 92)
							*(_WORD*)&v6[strlen(v6)] = *getMemU16Ptr(0x587000, 153736);
						strcat(v6, FindFileData.cFileName);
						if (strlen(v6) >= 0x200)
							nox_exit(1);
						if (++*(int*)&dword_5d4594_1189600 >= 128)
							nox_exit(1);
					}
					while (FindNextFileA(v5, &FindFileData)) {
						if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
							strcmp(FindFileData.cFileName, "..")) {
							v7 = (char*)getMemAt(0x5D4594, 512 * dword_5d4594_1189600 + 1124048);
							strcpy(v7, v4);
							if (v4[strlen(v4) - 1] != 92)
								*(_WORD*)&v7[strlen(v7)] = *getMemU16Ptr(0x587000, 153748);
							strcat(v7, FindFileData.cFileName);
							if (strlen(v7) >= 0x200)
								nox_exit(1);
							if (++*(int*)&dword_5d4594_1189600 >= 128)
								nox_exit(1);
							v5 = v9;
						}
					}
					FindClose(v5);
				}
				v4 += 512;
				if (++v8 >= *(int*)&dword_5d4594_1189600)
					goto LABEL_27;
			}
			SetCurrentDirectoryA(Buffer);
			result = SetCurrentDirectoryA((LPCSTR)getMemAt(0x587000, 153720));
		}
	}
	return result;
}

//----- (0047A650) --------------------------------------------------------
int sub_47A650() {
	int result;                            // eax
	const char* v1;                        // ebx
	__int16 v2;                            // dx
	char* v3;                              // edi
	unsigned __int8 v4;                    // al
	HANDLE v5;                             // esi
	HANDLE v6;                             // [esp+8h] [ebp-24Ch]
	int v7;                                // [esp+Ch] [ebp-248h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-244h]
	char FileName[260];                    // [esp+150h] [ebp-104h]

	result = dword_5d4594_1189600;
	dword_5d4594_1123532 = 0;
	v7 = 0;
	if (dword_5d4594_1189600 > 0) {
		v1 = (const char*)getMemAt(0x5D4594, 1124048);
		do {
			v2 = *getMemU16Ptr(0x587000, 153760);
			strcpy(FileName, v1);
			v3 = &FileName[strlen(FileName)];
			v4 = getMemByte(0x587000, 153762);
			*(_DWORD*)v3 = *getMemU32Ptr(0x587000, 153756);
			*((_WORD*)v3 + 2) = v2;
			v3[6] = v4;
			v5 = FindFirstFileA(FileName, &FindFileData);
			v6 = v5;
			if (v5 != (HANDLE)-1) {
				if (dword_5d4594_1189584) {
					strcpy((char*)(dword_5d4594_1189584 + 336 * dword_5d4594_1123532), v1);
					strcpy((char*)(336 * dword_5d4594_1123532 + dword_5d4594_1189584 + 260), FindFileData.cFileName);
					*(_DWORD*)(336 * dword_5d4594_1123532 + dword_5d4594_1189584 + 324) = 0;
				}
				++dword_5d4594_1123532;
				for (; FindNextFileA(v5, &FindFileData); ++dword_5d4594_1123532) {
					if (dword_5d4594_1189584) {
						strcpy((char*)(dword_5d4594_1189584 + 336 * dword_5d4594_1123532), v1);
						strcpy((char*)(336 * dword_5d4594_1123532 + dword_5d4594_1189584 + 260),
							   FindFileData.cFileName);
						v5 = v6;
						*(_DWORD*)(336 * dword_5d4594_1123532 + dword_5d4594_1189584 + 324) = 0;
					}
				}
				FindClose(v5);
			}
			result = v7 + 1;
			v1 += 512;
			++v7;
		} while (v7 < *(int*)&dword_5d4594_1189600);
	}
	return result;
}
// 47A650: using guessed type CHAR FileName[260];

//----- (0047A8C0) --------------------------------------------------------
char* __cdecl sub_47A8C0(const char* a1, char* a2) {
	int v2;       // edi
	int i;        // esi
	char* result; // eax

	if (!dword_5d4594_1189584)
		return 0;
	v2 = 0;
	if (*(int*)&dword_5d4594_1123532 <= 0)
		return 0;
	for (i = 0; _strcmpi((const char*)(i + dword_5d4594_1189584 + 260), a2); i += 336) {
		if (++v2 >= *(int*)&dword_5d4594_1123532)
			return 0;
	}
	result = (char*)(336 * v2 + dword_5d4594_1189584 + 324);
	if (!*(_DWORD*)result) {
		if (sub_47A960(a1, v2))
			return (char*)(336 * v2 + dword_5d4594_1189584 + 324);
		return 0;
	}
	return result;
}

//----- (0047A960) --------------------------------------------------------
int __cdecl sub_47A960(const char* a1, int a2) {
	int v3;              // ebp
	FILE* v4;            // edi
	bool v5;             // zf
	int v6;              // eax
	char* v8;            // eax
	int v9;              // esi
	unsigned __int8 v10; // dl
	char* v11;           // edi
	unsigned __int8 v12; // dl
	char* v13;           // edi
	void* v14;           // eax
	char v15[160];       // [esp+0h] [ebp-348h]
	const char* v16;     // [esp+A0h] [ebp-2A8h]
	int v18;             // [esp+B8h] [ebp-290h]
	int v19;             // [esp+BCh] [ebp-28Ch]
	char v20[68];        // [esp+C0h] [ebp-288h]
	char v21[68];        // [esp+104h] [ebp-244h]
	CHAR Buffer[512];    // [esp+148h] [ebp-200h]

	GetCurrentDirectoryA(0x200u, Buffer);
	v3 = 336 * a2;
	if (!SetCurrentDirectoryA((LPCSTR)(dword_5d4594_1189584 + 336 * a2)) && GetLastError())
		return 0;
	v4 = fopen((const char*)(dword_5d4594_1189584 + v3 + 260), "rb");
	if (sub_4C57C0(v4, *(int*)getMemAt(0x5D4594, 1189588), &v19, &v18)) {
		fclose(v4);
		switch ((unsigned __int8)a1 & 0x3F) {
		case 0:
			*(_DWORD*)(dword_5d4594_1189584 + v3 + 324) = malloc(3 * v18 * v19);
			v5 = sub_47AD60(v19, v18, *(_WORD**)(dword_5d4594_1189584 + v3 + 324)) == 0;
			v6 = dword_5d4594_1189584;
			if (v5)
				goto LABEL_6;
			*(_WORD*)(dword_5d4594_1189584 + v3 + 332) = 0;
			*(_BYTE*)(dword_5d4594_1189584 + v3 + 334) = -128;
			break;
		case 1:
			*(_DWORD*)(dword_5d4594_1189584 + v3 + 324) = malloc(3 * v18 * v19);
			v5 = sub_47AF30(v19, v18, *(unsigned __int8**)(dword_5d4594_1189584 + v3 + 324)) == 0;
			v6 = dword_5d4594_1189584;
			if (v5) {
			LABEL_6:
				free(*(LPVOID*)(v6 + v3 + 324));
				SetCurrentDirectoryA(Buffer);
				return 0;
			}
			*(_WORD*)(dword_5d4594_1189584 + v3 + 332) = 0;
			*(_BYTE*)(dword_5d4594_1189584 + v3 + 334) = -127;
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			v8 = strrchr((const char*)(dword_5d4594_1189584 + v3 + 260), 46);
			v9 = (int)&v8[-v3];
			strncpy(v21, (const char*)(dword_5d4594_1189584 + v3 + 260), (size_t)&v8[-v3 - dword_5d4594_1189584 - 260]);
			v15[v9 - dword_5d4594_1189584] = 0;
			if ((_BYTE)a1 == 5 || (_BYTE)a1 == 6) {
				v10 = getMemByte(0x587000, 153772);
				strcpy(v20, v21);
				v11 = &v20[strlen(v20)];
				*(_DWORD*)v11 = *getMemU32Ptr(0x587000, 153768);
				v16 = v20;
				v11[4] = v10;
				v4 = fopen(v16, "rb");
				if (v4) {
					if (!sub_4C57C0(v4, *(int*)&dword_5d4594_1189596, &v19, &v18))
						goto LABEL_26;
				}
			}
			if ((_BYTE)a1 == 4 || (_BYTE)a1 == 6) {
				v12 = getMemByte(0x587000, 153784);
				strcpy(v20, v21);
				v13 = &v20[strlen(v20)];
				*(_DWORD*)v13 = *getMemU32Ptr(0x587000, 153780);
				v16 = v20;
				v13[4] = v12;
				v4 = fopen(v16, "rb");
				if (v4) {
					if (!sub_4C57C0(v4, *(int*)&dword_5d4594_1189592, &v19, &v18)) {
					LABEL_26:
						fclose(v4);
						SetCurrentDirectoryA(Buffer);
						return 0;
					}
				}
			}
			v14 = malloc(3 * v18 * v19);
			v16 = a1;
			*(_DWORD*)(dword_5d4594_1189584 + v3 + 324) = v14;
			if (!sub_47B7F0(v19, v18, *(_DWORD*)(dword_5d4594_1189584 + v3 + 324), (unsigned __int8)v16)) {
				free(*(LPVOID*)(dword_5d4594_1189584 + v3 + 324));
				SetCurrentDirectoryA(Buffer);
				return 0;
			}
			*(_WORD*)(dword_5d4594_1189584 + v3 + 332) = 0;
			*(_BYTE*)(dword_5d4594_1189584 + v3 + 334) = (unsigned __int8)a1 | 0x80;
			break;
		default:
			break;
		}
	}
	fclose(v4);
	SetCurrentDirectoryA(Buffer);
	return 1;
}
// 47A960: using guessed type char var_348[160];
// 47A960: using guessed type char var_288[68];

//----- (0047AD60) --------------------------------------------------------
int __cdecl sub_47AD60(int a1, int a2, _WORD* a3) {
	int v3;      // edi
	int v4;      // edx
	int i;       // esi
	int v6;      // ecx
	int v7;      // eax
	__int16 v8;  // ax
	int v9;      // esi
	int v10;     // edi
	int v11;     // edx
	int v12;     // ecx
	int v13;     // eax
	__int16 v14; // ax
	__int16 v15; // bx
	int v17;     // [esp+0h] [ebp-4h]
	int v18;     // [esp+8h] [ebp+4h]

	v17 = 0;
	if (a1 != 46 || a2 != 46)
		return 0;
	v3 = 819200;
	v4 = 1;
	for (i = 23; i > 0; --i) {
		v6 = 0;
		if (v4 > 0) {
			v17 += v4;
			do {
				v7 = i + v3;
				if (dword_5d4594_3799624 == 2)
					v8 = 8 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + i + v3 + v6 - 409600) & 0xF8 |
							  (32 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v7 + v6 - 819200) & 0xF8)));
				else
					v8 = 4 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + i + v3 + v6 - 409600) & 0xF8 |
							  (32 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v7 + v6 - 819200) & 0xF8)));
				*a3 = (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + i + v3 + v6++) >> 3) | v8;
				++a3;
			} while (v6 < v4);
		}
		v4 += 2;
		v3 += 640;
	}
	v9 = 1;
	v10 = 833920;
	v11 = 45;
	v18 = 23;
	do {
		v12 = 0;
		if (v11 > 0) {
			v17 += v11;
			do {
				v13 = v10 + v9;
				if (dword_5d4594_3799624 == 2)
					v14 = 8 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v10 + v9 + v12 - 409600) & 0xF8 |
							   (32 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v13 + v12 - 819200) & 0xF8)));
				else
					v14 = 4 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v10 + v9 + v12 - 409600) & 0xF8 |
							   (32 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v13 + v12 - 819200) & 0xF8)));
				++a3;
				v15 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v10 + v9 + v12++) >> 3;
				*(a3 - 1) = v15 | v14;
			} while (v12 < v11);
		}
		++v9;
		v11 -= 2;
		v10 += 640;
		--v18;
	} while (v18);
	return 1;
}

//----- (0047AF30) --------------------------------------------------------
int __cdecl sub_47AF30(int a1, int a2, unsigned __int8* a3) {
	int v3;               // edx
	int v4;               // eax
	int v5;               // ecx
	int v6;               // eax
	int v7;               // eax
	int v8;               // edi
	int v9;               // edx
	int v10;              // eax
	int v11;              // ebp
	int v12;              // eax
	int v13;              // edx
	int v14;              // ecx
	int v15;              // eax
	int i;                // esi
	int v17;              // esi
	int v18;              // edi
	int v19;              // eax
	int v20;              // ebp
	int v21;              // eax
	int v22;              // esi
	int v23;              // edi
	int v24;              // ecx
	int v25;              // esi
	int v26;              // ecx
	int j;                // edi
	int v28;              // esi
	int v29;              // edi
	unsigned __int8* v30; // eax
	int v31;              // ecx
	int v32;              // ebx
	int v33;              // ebp
	int v34;              // edx
	int v35;              // ecx
	int v36;              // ebx
	int v37;              // ecx
	int v38;              // edx
	int v39;              // ecx
	__int16 v40;          // cx
	int v41;              // edx
	_WORD* v42;           // eax
	int v43;              // ecx
	int v44;              // ebx
	char v45;             // cl
	int v46;              // ebx
	int v47;              // ecx
	__int16 v48;          // cx
	_BYTE* v49;           // ebx
	int v50;              // eax
	_BYTE* v51;           // ebx
	int v52;              // eax
	_BYTE* v53;           // ebp
	_WORD* v54;           // eax
	bool v55;             // zf
	int v56;              // ebp
	int v57;              // ecx
	int v58;              // edx
	int v59;              // ecx
	__int16 v60;          // cx
	int v61;              // edx
	_WORD* v62;           // eax
	int v63;              // ecx
	int v64;              // ebx
	int v65;              // ecx
	__int16 v66;          // cx
	_BYTE* v67;           // ebx
	int v68;              // eax
	_BYTE* v69;           // ebx
	int v70;              // eax
	_BYTE* v71;           // ebp
	_WORD* v72;           // eax
	bool v73;             // cc
	int v75;              // [esp+0h] [ebp-20h]
	int v76;              // [esp+0h] [ebp-20h]
	int v77;              // [esp+4h] [ebp-1Ch]
	unsigned __int8 v78;  // [esp+8h] [ebp-18h]
	int v79;              // [esp+8h] [ebp-18h]
	unsigned __int8 v80;  // [esp+Ch] [ebp-14h]
	__int16 v81;          // [esp+10h] [ebp-10h]
	int v82;              // [esp+14h] [ebp-Ch]
	int v83;              // [esp+14h] [ebp-Ch]
	__int16 v84;          // [esp+18h] [ebp-8h]
	int v85;              // [esp+1Ch] [ebp-4h]
	char v86;             // [esp+24h] [ebp+4h]
	_BYTE* v87;           // [esp+24h] [ebp+4h]
	_BYTE* v88;           // [esp+24h] [ebp+4h]
	char v89;             // [esp+25h] [ebp+5h]
	char v90;             // [esp+26h] [ebp+6h]
	int v91;              // [esp+28h] [ebp+8h]
	int v92;              // [esp+28h] [ebp+8h]
	int v93;              // [esp+28h] [ebp+8h]
	int v94;              // [esp+28h] [ebp+8h]
	int v95;              // [esp+28h] [ebp+8h]
	int v96;              // [esp+2Ch] [ebp+Ch]
	int v97;              // [esp+2Ch] [ebp+Ch]

	HIWORD(v4) = 0;
	if (a1 != 46 || a2 != 46)
		return 0;
	HIWORD(v5) = *getMemU16Ptr(0x5D4594, 1189590);
	v86 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 1);
	v89 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 409601);
	v90 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 819201);
	LOWORD(v4) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 1) & 0xF8;
	LOWORD(v3) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 409601) & 0xF8;
	if (dword_5d4594_3799624 == 2)
		v6 = 8 * (v3 | (32 * v4));
	else
		v6 = 4 * (v3 | (32 * v4));
	LOWORD(v5) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 819201) >> 3;
	v7 = v5 | v6;
	v81 = v7;
	v8 = *getMemU32Ptr(0x5D4594, 1189588) + 819200;
	LOWORD(v7) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 409600) & 0xF8;
	v78 = -1;
	LOWORD(v3) = **(_BYTE**)getMemAt(0x5D4594, 1189588) & 0xF8;
	v9 = 32 * v3;
	v10 = v9 | v7;
	LOWORD(v9) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 819200) >> 3;
	v11 = 1;
	v12 = v9 | (4 * v10);
	v13 = 0;
	v84 = v12;
	v91 = 0;
	v14 = 0;
	v15 = 23;
	while (v15 > 0) {
		for (i = 0; i < v11; ++i) {
			if (v86 != *(_BYTE*)(v8 + v15 + i - 819200) || v89 != *(_BYTE*)(v8 + v15 + i - 409600) ||
				v90 != *(_BYTE*)(v8 + v15 + i)) {
				v13 = 1;
				v78 = v14;
				v91 = 1;
				break;
			}
			v13 = v91;
		}
		++v14;
		--v15;
		v11 += 2;
		v8 += 640;
		if (v13)
			goto LABEL_27;
	}
	v17 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v14 + 6400) << 7);
	v18 = 91 - 2 * v14;
	do {
		if (v14 >= 46)
			break;
		v19 = 0;
		if (v18 > 0) {
			while (v86 == *(_BYTE*)(v19 + v17 + v14 - 819222) && v89 == *(_BYTE*)(v14 + v17 + v19 - 409622) &&
				   v90 == *(_BYTE*)(v14 + v17 + v19 - 22)) {
				if (++v19 >= v18)
					goto LABEL_26;
			}
			v78 = v14;
			v13 = 1;
		}
	LABEL_26:
		++v14;
		v18 -= 2;
		v17 += 640;
	} while (!v13);
LABEL_27:
	v20 = 0;
	v80 = -1;
	v92 = 0;
	v21 = 45;
	v22 = *getMemU32Ptr(0x5D4594, 1189588) + 848000;
	v23 = 1;
	while (v23 <= 45) {
		v24 = 0;
		if (v23 > 0) {
			while (v86 == *(_BYTE*)(v24 + v22 + v21 - 819222) && v89 == *(_BYTE*)(v22 + v24 + v21 - 409622) &&
				   v90 == *(_BYTE*)(v22 + v24 + v21 - 22)) {
				if (++v24 >= v23) {
					v20 = v92;
					goto LABEL_36;
				}
			}
			v20 = 1;
			v80 = v21;
			v92 = 1;
		}
	LABEL_36:
		--v21;
		v23 += 2;
		v22 -= 640;
		if (v20)
			goto LABEL_48;
	}
	v93 = 2 * v21 + 1;
	v25 = 23 - v21;
	v26 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v21 + 6400) << 7);
	do {
		if (v21 < 0)
			break;
		for (j = 0; j < v93; ++j) {
			if (v86 != *(_BYTE*)(v26 + v25 + j - 819200) || v89 != *(_BYTE*)(v26 + v25 + j - 409600) ||
				v90 != *(_BYTE*)(v26 + v25 + j)) {
				v80 = v21;
				v20 = 1;
				break;
			}
		}
		--v21;
		++v25;
		v26 -= 640;
		v93 -= 2;
	} while (!v20);
LABEL_48:
	v28 = 2;
	*a3 = v78;
	v29 = 2;
	a3[1] = v80;
	v30 = a3 + 2;
	if (v80 >= 0x17u)
		v31 = 22;
	else
		v31 = v80;
	v32 = v78;
	v77 = v78;
	if (v78 <= v31) {
		v82 = 2 * v78 + 1;
		v33 = 23 - v78;
		v34 = (5 * v78 + 6400) << 7;
		v35 = v31 - v78 + 1;
		v75 = (5 * v78 + 6400) << 7;
		v36 = v35 + v78;
		v79 = 23 - v78;
		v85 = v35;
		v77 = v36;
		while (1) {
			v37 = v34 + v33 - 819200;
			v38 = v34 + v33 - 409600;
			LOWORD(v37) = *(_BYTE*)(v37 + *getMemU32Ptr(0x5D4594, 1189588)) & 0xF8;
			LOWORD(v38) = *(_BYTE*)(v38 + *getMemU32Ptr(0x5D4594, 1189588)) & 0xF8;
			if (dword_5d4594_3799624 == 2)
				v39 = 8 * (v38 | (32 * v37));
			else
				v39 = 4 * (v38 | (32 * v37));
			v40 = (*(_BYTE*)(v33 + v75 + *getMemU32Ptr(0x5D4594, 1189588)) >> 3) | v39;
			if (v40 == v81) {
				v41 = 1;
				v28 += 2;
				*v30 = 1;
				v87 = v30 + 1;
				v30 += 2;
				v94 = 1;
				v29 += 2;
			} else if (v40 == v84) {
				*v30 = 3;
				v87 = v30 + 1;
				v30 += 2;
				v28 += 2;
				v94 = 3;
				v41 = 1;
				v29 += 2;
			} else {
				*v30 = 2;
				v42 = v30 + 1;
				v87 = v42;
				v42 = (_WORD*)((char*)v42 + 1);
				v28 += 4;
				v94 = 2;
				*v42 = v40;
				v30 = (unsigned __int8*)(v42 + 1);
				v41 = 1;
				v29 += 3;
			}
			v43 = 1;
			v96 = 1;
			if (v82 > 1) {
				v44 = v75;
				while (1) {
					v45 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v44 + v33 - 819200 + v43);
					v46 = *getMemU32Ptr(0x5D4594, 1189588) + v75 + v33 - 409600;
					LOWORD(v43) = v45 & 0xF8;
					LOWORD(v46) = *(_BYTE*)(v46 + v96) & 0xF8;
					v47 = dword_5d4594_3799624 == 2 ? 8 * (v46 | (32 * v43)) : 4 * (v46 | (32 * v43));
					v48 = (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v75 + v79 + v96) >> 3) | v47;
					if (v48 == v81) {
						if (v94 == 1) {
							++v41;
						} else {
							v49 = v87;
							v50 = (int)(v30 + 1);
							v87 = (_BYTE*)v50;
							v30 = (unsigned __int8*)(v50 + 1);
							*v49 = v41;
							*(v30 - 2) = 1;
							v28 += 2;
							v94 = 1;
							v41 = 1;
							v29 += 2;
						}
					} else if (v48 == v84) {
						if (v94 == 3) {
							++v41;
						} else {
							v51 = v87;
							v52 = (int)(v30 + 1);
							v87 = (_BYTE*)v52;
							v30 = (unsigned __int8*)(v52 + 1);
							*v51 = v41;
							*(v30 - 2) = 3;
							v28 += 2;
							v94 = 3;
							v41 = 1;
							v29 += 2;
						}
					} else if (v94 == 2) {
						*(_WORD*)v30 = v48;
						v30 += 2;
						++v41;
						v28 += 2;
						++v29;
					} else {
						v53 = v87;
						v54 = v30 + 1;
						v87 = v54;
						v54 = (_WORD*)((char*)v54 + 1);
						*v53 = v41;
						*((_BYTE*)v54 - 2) = 2;
						*v54 = v48;
						v30 = (unsigned __int8*)(v54 + 1);
						v28 += 4;
						v94 = 2;
						v41 = 1;
						v29 += 3;
					}
					if (++v96 >= v82)
						break;
					v44 = v75;
					v33 = v79;
					v43 = v96;
				}
				v33 = v79;
			}
			v32 = v77;
			--v33;
			*v87 = v41;
			v82 += 2;
			v55 = v85 == 1;
			v79 = v33;
			v75 += 640;
			--v85;
			if (v55)
				break;
			v34 = v75;
		}
	}
	if (v32 <= v80) {
		v56 = (5 * v32 + 6400) << 7;
		v76 = (5 * v32 + 6400) << 7;
		v83 = 91 - 2 * v32;
		do {
			v57 = *getMemU32Ptr(0x5D4594, 1189588) + v56 - 819200;
			v58 = *getMemU32Ptr(0x5D4594, 1189588) + v56 - 409600;
			LOWORD(v57) = *(_BYTE*)(v57 + v32 - 22) & 0xF8;
			LOWORD(v58) = *(_BYTE*)(v58 + v32 - 22) & 0xF8;
			if (dword_5d4594_3799624 == 2)
				v59 = 8 * (v58 | (32 * v57));
			else
				v59 = 4 * (v58 | (32 * v57));
			v60 = (*(_BYTE*)(v56 + *getMemU32Ptr(0x5D4594, 1189588) + v32 - 22) >> 3) | v59;
			if (v60 == v81) {
				*v30 = 1;
				v61 = 1;
				v88 = v30 + 1;
				v30 += 2;
				v28 += 2;
				v95 = 1;
				v29 += 2;
			} else if (v60 == v84) {
				*v30 = 3;
				v88 = v30 + 1;
				v30 += 2;
				v28 += 2;
				v95 = 3;
				v61 = 1;
				v29 += 2;
			} else {
				*v30 = 2;
				v62 = v30 + 1;
				v88 = v62;
				v62 = (_WORD*)((char*)v62 + 1);
				v28 += 4;
				v95 = 2;
				*v62 = v60;
				v30 = (unsigned __int8*)(v62 + 1);
				v61 = 1;
				v29 += 3;
			}
			v97 = 1;
			if (v83 > 1) {
				do {
					v63 = v97 + *getMemU32Ptr(0x5D4594, 1189588) + v56 - 819200;
					LOBYTE(v63) = *(_BYTE*)(v63 + v32 - 22);
					v64 = v97 + *getMemU32Ptr(0x5D4594, 1189588) + v76 - 409600;
					LOWORD(v63) = v63 & 0xF8;
					LOWORD(v64) = *(_BYTE*)(v64 + v77 - 22) & 0xF8;
					if (dword_5d4594_3799624 == 2)
						v65 = 8 * (v64 | (32 * v63));
					else
						v65 = 4 * (v64 | (32 * v63));
					v66 = (*(_BYTE*)(v97 + *getMemU32Ptr(0x5D4594, 1189588) + v76 + v77 - 22) >> 3) | v65;
					if (v66 == v81) {
						if (v95 == 1) {
							++v61;
						} else {
							v67 = v88;
							v68 = (int)(v30 + 1);
							v88 = (_BYTE*)v68;
							v30 = (unsigned __int8*)(v68 + 1);
							*v67 = v61;
							*(v30 - 2) = 1;
							v28 += 2;
							v95 = 1;
							v61 = 1;
							v29 += 2;
						}
					} else if (v66 == v84) {
						if (v95 == 3) {
							++v61;
						} else {
							v69 = v88;
							v70 = (int)(v30 + 1);
							v88 = (_BYTE*)v70;
							v30 = (unsigned __int8*)(v70 + 1);
							*v69 = v61;
							*(v30 - 2) = 3;
							v28 += 2;
							v95 = 3;
							v61 = 1;
							v29 += 2;
						}
					} else if (v95 == 2) {
						*(_WORD*)v30 = v66;
						v30 += 2;
						++v61;
						v28 += 2;
						++v29;
					} else {
						v71 = v88;
						v72 = v30 + 1;
						v88 = v72;
						v72 = (_WORD*)((char*)v72 + 1);
						*v71 = v61;
						*((_BYTE*)v72 - 2) = 2;
						*v72 = v66;
						v30 = (unsigned __int8*)(v72 + 1);
						v28 += 4;
						v95 = 2;
						v61 = 1;
						v29 += 3;
					}
					v56 = v76;
					v73 = v97 + 1 < v83;
					v32 = v77;
					++v97;
				} while (v73);
			}
			++v32;
			v56 += 640;
			v77 = v32;
			*v88 = v61;
			v76 = v56;
			v83 -= 2;
		} while (v32 <= v80);
	}
	return 1;
}
// 47AF8E: variable 'v3' is possibly undefined

//----- (0047B7F0) --------------------------------------------------------
int __cdecl sub_47B7F0(int a1, int a2, int a3, unsigned __int8 a4) {
	int v4;               // esi
	int v5;               // ebp
	unsigned __int8 v6;   // bl
	int i;                // edx
	int v8;               // edi
	int v9;               // edi
	int v10;              // edi
	int v11;              // ebp
	int v12;              // eax
	int v13;              // ecx
	int j;                // edi
	int v15;              // edx
	int v16;              // edx
	int v17;              // edx
	int v18;              // ebx
	int v19;              // ebp
	int v20;              // edi
	unsigned __int8* v21; // ecx
	int v22;              // edx
	int v23;              // edx
	int v24;              // edx
	int v25;              // eax
	int v26;              // ebp
	int v27;              // edi
	unsigned __int8* v28; // ecx
	int v29;              // edx
	int v30;              // edx
	int v31;              // edx
	int v32;              // eax
	unsigned __int8* v34; // esi
	int v35;              // edi
	int v36;              // ebp
	int v37;              // eax
	int v38;              // ecx
	_BYTE* v39;           // ecx
	__int16 v40;          // dx
	__int16 v41;          // dx
	_WORD* v42;           // esi
	int v43;              // edx
	int v44;              // edx
	int v45;              // ecx
	bool v46;             // zf
	int v47;              // esi
	__int16 v48;          // dx
	__int16 v49;          // dx
	_WORD* v50;           // esi
	_BYTE* v51;           // ecx
	char v52;             // cl
	_BYTE* v53;           // esi
	int v54;              // ecx
	__int16 v55;          // cx
	__int16 v56;          // dx
	__int16 v57;          // dx
	_WORD* v58;           // esi
	int v59;              // ecx
	int v60;              // esi
	char v61;             // dl
	_BYTE* v62;           // esi
	__int16 v63;          // dx
	__int16 v64;          // dx
	_WORD* v65;           // esi
	int v66;              // ecx
	char v67;             // dl
	_WORD* v68;           // esi
	int v69;              // ecx
	int v70;              // edx
	int v71;              // ebx
	_BYTE* v72;           // edx
	int v73;              // esi
	int v74;              // esi
	int v75;              // ecx
	int v76;              // ebx
	int v77;              // edx
	int v78;              // ecx
	_WORD* v79;           // esi
	_BYTE* v80;           // edx
	int v81;              // esi
	int v82;              // ecx
	char v83;             // cl
	_BYTE* v84;           // esi
	int v85;              // ecx
	char v86;             // dl
	char v87;             // dl
	_WORD* v88;           // esi
	int v89;              // esi
	char v90;             // dl
	_BYTE* v91;           // esi
	int v92;              // esi
	int v93;              // esi
	int v94;              // edx
	int v95;              // ecx
	int v96;              // ebx
	int v97;              // edx
	_WORD* v98;           // esi
	_BYTE* v99;           // ecx
	int v100;             // esi
	int v101;             // [esp+10h] [ebp-74h]
	int v102;             // [esp+10h] [ebp-74h]
	int v103;             // [esp+10h] [ebp-74h]
	int v104;             // [esp+14h] [ebp-70h]
	int v105;             // [esp+14h] [ebp-70h]
	int v106;             // [esp+18h] [ebp-6Ch]
	int v107;             // [esp+1Ch] [ebp-68h]
	int v108;             // [esp+1Ch] [ebp-68h]
	int v109;             // [esp+20h] [ebp-64h]
	unsigned __int8 v110; // [esp+24h] [ebp-60h]
	unsigned __int8 v111; // [esp+24h] [ebp-60h]
	unsigned __int8 v112; // [esp+24h] [ebp-60h]
	unsigned __int8 v113; // [esp+24h] [ebp-60h]
	int v114;             // [esp+28h] [ebp-5Ch]
	unsigned __int8 v115; // [esp+28h] [ebp-5Ch]
	unsigned __int8 v116; // [esp+28h] [ebp-5Ch]
	unsigned __int8 v117; // [esp+28h] [ebp-5Ch]
	unsigned __int8 v118; // [esp+28h] [ebp-5Ch]
	int v119;             // [esp+30h] [ebp-54h]
	int v120;             // [esp+30h] [ebp-54h]
	unsigned __int8 v121; // [esp+30h] [ebp-54h]
	unsigned __int8 v122; // [esp+30h] [ebp-54h]
	int v123;             // [esp+34h] [ebp-50h]
	int v124;             // [esp+38h] [ebp-4Ch]
	int v125;             // [esp+3Ch] [ebp-48h]
	__int16 v126;         // [esp+60h] [ebp-24h]
	__int16 v127;         // [esp+64h] [ebp-20h]
	unsigned __int8 v128; // [esp+68h] [ebp-1Ch]
	unsigned __int8 v129; // [esp+69h] [ebp-1Bh]
	unsigned __int8 v130; // [esp+6Ah] [ebp-1Ah]
	int v131;             // [esp+88h] [ebp+4h]
	int v132;             // [esp+88h] [ebp+4h]
	int v133;             // [esp+88h] [ebp+4h]
	int v134;             // [esp+88h] [ebp+4h]
	int v135;             // [esp+88h] [ebp+4h]
	int v136;             // [esp+88h] [ebp+4h]
	int v137;             // [esp+88h] [ebp+4h]
	int v138;             // [esp+88h] [ebp+4h]
	_BYTE* v139;          // [esp+8Ch] [ebp+8h]
	_BYTE* v140;          // [esp+8Ch] [ebp+8h]
	_BYTE* v141;          // [esp+8Ch] [ebp+8h]
	_BYTE* v142;          // [esp+8Ch] [ebp+8h]
	int v143;             // [esp+90h] [ebp+Ch]
	int v144;             // [esp+90h] [ebp+Ch]
	int v145;             // [esp+90h] [ebp+Ch]
	int v146;             // [esp+90h] [ebp+Ch]
	int v147;             // [esp+94h] [ebp+10h]
	int v148;             // [esp+94h] [ebp+10h]
	int v149;             // [esp+94h] [ebp+10h]
	int v150;             // [esp+94h] [ebp+10h]

	v114 = -1;
	v4 = *getMemU32Ptr(0x5D4594, 1189588) + 819200;
	v128 = **(_BYTE**)getMemAt(0x5D4594, 1189588);
	v129 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 409600);
	v130 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 819200);
	v5 = 0;
	v6 = **(_BYTE**)getMemAt(0x5D4594, 1189588);
	v124 = 0;
	do {
		if (v124 >= a2)
			break;
		for (i = 0; i < a1; ++i) {
			v8 = *(unsigned __int8*)(v4 + i - 819200);
			if (v128 <= v8 + 5 && v6 >= v8 - 5) {
				v9 = *(unsigned __int8*)(v4 + i - 409600);
				if (v129 <= v9 + 5 && v129 >= v9 - 5) {
					v10 = *(unsigned __int8*)(v4 + i);
					if (v130 <= v10 + 5 && v130 >= v10 - 5)
						continue;
				}
			}
			v5 = 1;
			v114 = v124;
			break;
		}
		v4 += 640;
		++v124;
	} while (!v5);
	v11 = 0;
	v123 = -1;
	v12 = a2 - 1;
	v13 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * (a2 - 1) + 6400) << 7);
	do {
		if (v12 < 0)
			break;
		for (j = 0; j < a1; ++j) {
			v15 = *(unsigned __int8*)(v13 + j - 819200);
			if (v6 > v15 + 5 || v6 < v15 - 5 || (v16 = *(unsigned __int8*)(v13 + j - 409600), v129 > v16 + 5) ||
				v129 < v16 - 5 || (v17 = *(unsigned __int8*)(v13 + j), v130 > v17 + 5) || v130 < v17 - 5) {
				v6 = **(_BYTE**)getMemAt(0x5D4594, 1189588);
				v123 = v12;
				v11 = 1;
				break;
			}
			v6 = **(_BYTE**)getMemAt(0x5D4594, 1189588);
		}
		--v12;
		v13 -= 640;
	} while (!v11);
	v18 = -1;
	v119 = 0;
	v19 = 0;
	do {
		if (v19 >= a1)
			break;
		v20 = v114;
		v21 = (unsigned __int8*)(v19 + *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v114 + 6400) << 7));
		while (v20 <= v123) {
			v22 = *(v21 - 819200);
			if (v128 > v22 + 5 || v128 < v22 - 5 || (v23 = *(v21 - 409600), v129 > v23 + 5) || v129 < v23 - 5 ||
				(v24 = *v21, v130 > v24 + 5) || v130 < v24 - 5) {
				v25 = 1;
				v18 = v19;
				v119 = 1;
				goto LABEL_40;
			}
			++v20;
			v21 += 640;
		}
		v25 = v119;
	LABEL_40:
		++v19;
	} while (!v25);
	v106 = v18;
	v109 = -1;
	v120 = 0;
	v26 = a1 - 1;
	do {
		if (v26 < 0)
			break;
		v27 = v114;
		v28 = (unsigned __int8*)(v26 + *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v114 + 6400) << 7));
		while (v27 <= v123) {
			v29 = *(v28 - 819200);
			if (v128 > v29 + 5 || v128 < v29 - 5 || (v30 = *(v28 - 409600), v129 > v30 + 5) || v129 < v30 - 5 ||
				(v31 = *v28, v130 > v31 + 5) || v130 < v31 - 5) {
				v32 = 1;
				v109 = v26;
				v120 = 1;
				goto LABEL_54;
			}
			++v27;
			v28 += 640;
		}
		v32 = v120;
	LABEL_54:
		--v26;
	} while (!v32);
	if (v114 == -1) {
		*(_DWORD*)a3 = 0;
		*(_DWORD*)(a3 + 4) = 0;
		*(_DWORD*)(a3 + 8) = 0;
		*(_DWORD*)(a3 + 12) = 0;
		*(_BYTE*)(a3 + 16) = 0;
		*(_BYTE*)(a3 + 17) = 0;
		*(_BYTE*)(a3 + 18) = 0;
		return 1;
	}
	*(_DWORD*)a3 = v109 - v18 + 1;
	v34 = (unsigned __int8*)(a3 + 17);
	*(_DWORD*)(a3 + 4) = v123 - v114 + 1;
	v35 = 17;
	*(_DWORD*)(a3 + 8) = v18;
	*(_DWORD*)(a3 + 12) = v114;
	*(_BYTE*)(a3 + 16) = a4 | 0x80;
	v36 = 17;
	if (a4 == 4 || a4 == 6)
		sub_47D090(a1, a2);
	v37 = v114;
	if (v114 > v123)
		goto LABEL_208;
	v38 = a4 - 3;
	v125 = a4 - 3;
	while (1) {
		switch (v38) {
		case 0:
			v110 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v110 + 5 || v128 < v110 - 5 ||
				(v107 = (5 * v37 + 3200) << 7, v131 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v18),
				 v129 > v131 + 5) ||
				v129 < v131 - 5 ||
				(v104 = (5 * v37 + 6400) << 7, v132 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v104 + v18),
				 v130 > v132 + 5) ||
				v130 < v132 - 5) {
				v104 = (5 * v37 + 6400) << 7;
				v107 = (5 * v37 + 3200) << 7;
				if (dword_5d4594_3799624 == 2)
					v40 = 8 * ((32 * (v110 & 0xF8)) |
							   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
				else
					v40 = 4 * ((32 * (v110 & 0xF8)) |
							   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
				v41 = (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) >> 3) | v40;
				*v34 = 2;
				v42 = v34 + 1;
				v35 += 4;
				v39 = v42;
				v42 = (_WORD*)((char*)v42 + 1);
				v147 = 2;
				v133 = 1;
				*v42 = v41;
				v34 = (unsigned __int8*)(v42 + 1);
				v139 = v39;
				v36 += 3;
			} else {
				v35 += 2;
				*v34 = 1;
				v147 = 1;
				v133 = 1;
				v39 = v34 + 1;
				v34 += 2;
				v139 = v39;
				v36 += 2;
			}
			v143 = v18 + 1;
			if (v18 + 1 > v109)
				goto LABEL_97;
			while (1) {
				v115 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v143);
				if (v128 > v115 + 5 || v128 < v115 - 5)
					goto LABEL_88;
				v43 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v143);
				if (v129 > v43 + 5 || v129 < v43 - 5 ||
					(v44 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v104 + v143), v130 > v44 + 5) ||
					v130 < v44 - 5) {
					v39 = v139;
				LABEL_88:
					if (dword_5d4594_3799624 == 2)
						v48 = 8 *
							  ((32 * (v115 & 0xF8)) | *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v143) & 0xF8);
					else
						v48 = 4 *
							  ((32 * (v115 & 0xF8)) | *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v107 + v143) & 0xF8);
					v49 = (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v104 + v143) >> 3) | v48;
					if (v147 == 1) {
						v50 = v34 + 1;
						*v39 = v133;
						*((_BYTE*)v50 - 1) = 2;
						v39 = v50;
						v50 = (_WORD*)((char*)v50 + 1);
						v35 += 4;
						v147 = 2;
						*v50 = v49;
						v34 = (unsigned __int8*)(v50 + 1);
						v139 = v39;
						v133 = 1;
						v36 += 3;
					} else {
						if (++v133 == 254) {
							*v39 = -3;
							*v34 = 2;
							v35 += 2;
							v39 = v34 + 1;
							v34 += 2;
							v133 = 1;
							v139 = v39;
							v36 += 2;
						}
						*(_WORD*)v34 = v49;
						v34 += 2;
						v35 += 2;
						++v36;
					}
					goto LABEL_96;
				}
				if (v147 != 1)
					break;
				v45 = v133 + 1;
				v133 = v45;
				v46 = v45 == 254;
				v39 = v139;
				if (v46) {
					*v139 = -3;
					*v34 = 1;
					v47 = (int)(v34 + 1);
				LABEL_85:
					v39 = (_BYTE*)v47;
					v34 = (unsigned __int8*)(v47 + 1);
					v35 += 2;
					v133 = 1;
					v139 = v39;
					v36 += 2;
				}
			LABEL_96:
				if (++v143 > v109) {
				LABEL_97:
					*v39 = v133;
					goto LABEL_206;
				}
			}
			v47 = (int)(v34 + 1);
			v147 = 1;
			*v139 = v133;
			*(_BYTE*)(v47 - 1) = 1;
			goto LABEL_85;
		case 1:
			v101 = 640 * v37;
			v111 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v111 + 5 || v128 < v111 - 5 ||
				v129 > *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) + 5 ||
				v129 < *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) - 5 ||
				v130 > *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) + 5 ||
				v130 < *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) - 5) {
				v52 = *(_BYTE*)(v101 + dword_5d4594_1189592 + v18);
				if (v52 == -1) {
					HIBYTE(v55) = 0;
					if (dword_5d4594_3799624 == 2)
						v56 = 8 * ((32 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18) & 0xF8)) |
								   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
					else
						v56 = 4 * ((32 * (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18) & 0xF8)) |
								   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) & 0xF8);
					LOBYTE(v55) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) >> 3;
					v57 = v55 | v56;
					*v34 = 2;
					v58 = v34 + 1;
					v148 = 2;
					v51 = v58;
					v58 = (_WORD*)((char*)v58 + 1);
					v134 = 1;
					v140 = v51;
					*v58 = v57;
					v34 = (unsigned __int8*)(v58 + 1);
					v35 += 4;
				} else {
					v134 = 1;
					*v34 = (16 * v52) | 4;
					v53 = v34 + 1;
					v54 = *(unsigned __int8*)(dword_5d4594_1189592 + v101 + v18);
					v18 = v106;
					v148 = (16 * v54) | 4;
					v51 = v53++;
					v140 = v51;
					*v53 = *(_BYTE*)(v101 + *getMemU32Ptr(0x5D4594, 1189588) + v106);
					v34 = v53 + 1;
					v35 += 3;
				}
				v36 += 3;
			} else {
				v35 += 2;
				*v34 = 1;
				v148 = 1;
				v134 = 1;
				v51 = v34 + 1;
				v34 += 2;
				v140 = v51;
				v36 += 2;
			}
			v144 = v18 + 1;
			if (v18 + 1 > v109)
				goto LABEL_141;
			do {
				v116 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v101 + v144);
				if (v128 <= v116 + 5 && v128 >= v116 - 5) {
					if (v129 <=
							*(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) + 5 &&
						v129 >=
							*(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) - 5 &&
						v130 <=
							*(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v144) + 5 &&
						v130 >=
							*(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v144) - 5) {
						if (v148 == 1) {
							v59 = v134 + 1;
							v134 = v59;
							v46 = v59 == 254;
							v51 = v140;
							if (!v46)
								goto LABEL_140;
							*v140 = -3;
							*v34 = 1;
							v60 = (int)(v34 + 1);
						} else {
							v60 = (int)(v34 + 1);
							v148 = 1;
							*v140 = v134;
							*(_BYTE*)(v60 - 1) = 1;
						}
						v51 = (_BYTE*)v60;
						v34 = (unsigned __int8*)(v60 + 1);
						v35 += 2;
						v134 = 1;
						v140 = v51;
						v36 += 2;
						goto LABEL_140;
					}
					v51 = v140;
				}
				v61 = *(_BYTE*)(v101 + dword_5d4594_1189592 + v144);
				if (v61 == -1) {
					if (dword_5d4594_3799624 == 2)
						v63 = 8 * ((32 * (v116 & 0xF8)) |
								   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) & 0xF8);
					else
						v63 = 4 * ((32 * (v116 & 0xF8)) |
								   *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v144) & 0xF8);
					v64 = (*(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v144) >> 3) | v63;
					if (v148 != 2) {
						v65 = v34 + 1;
						*v51 = v134;
						*((_BYTE*)v65 - 1) = 2;
						v51 = v65;
						v65 = (_WORD*)((char*)v65 + 1);
						v35 += 4;
						v140 = v51;
						*v65 = v64;
						v34 = (unsigned __int8*)(v65 + 1);
						v148 = 2;
						v134 = 1;
						v36 += 3;
						goto LABEL_140;
					}
					if (++v134 == 254) {
						*v51 = -3;
						*v34 = 2;
						v35 += 2;
						v51 = v34 + 1;
						v34 += 2;
						v134 = 1;
						v140 = v51;
						v36 += 2;
					}
					*(_WORD*)v34 = v64;
					v34 += 2;
					v35 += 2;
				} else {
					v121 = (16 * v61) | 4;
					if (v148 != v121) {
						v148 = v121;
						*v51 = v134;
						*v34 = v121;
						v62 = v34 + 1;
						v51 = v62++;
						v35 += 3;
						*v62 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v101 + v144);
						v34 = v62 + 1;
						v134 = 1;
						v140 = v51;
						v36 += 3;
						goto LABEL_140;
					}
					if (++v134 == 254) {
						*v51 = -3;
						*v34 = v121;
						v51 = v34 + 1;
						v34 += 2;
						v35 += 2;
						v134 = 1;
						v140 = v51;
						v36 += 2;
					}
					++v34;
					++v35;
					*(v34 - 1) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v101 + v144);
				}
				++v36;
			LABEL_140:
				++v144;
			} while (v144 <= v109);
		LABEL_141:
			*v51 = v134;
		LABEL_206:
			v18 = v106;
		LABEL_207:
			if (++v37 <= v123) {
				v38 = v125;
				continue;
			}
		LABEL_208:
			*v34 = 0;
			v34[1] = 0;
			return 1;
		case 2:
			v102 = 640 * v37;
			v112 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v112 + 5 || v128 < v112 - 5 ||
				(v108 = (5 * v37 + 3200) << 7, v135 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v18),
				 v129 > v135 + 5) ||
				v129 < v135 - 5 ||
				(v105 = (5 * v37 + 6400) << 7, v136 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v105 + v18),
				 v130 > v136 + 5) ||
				v130 < v136 - 5) {
				v108 = (5 * v37 + 3200) << 7;
				v66 = (5 * v37 + 6400) << 7;
				v105 = v66;
				v35 += 4;
				LOBYTE(v66) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v66 + v18);
				v18 = v106;
				v149 = 5;
				v137 = 1;
				v126 = (*(_BYTE*)(v102 + dword_5d4594_1189596 + v106) >> 4) | v66 & 0xF0;
				v67 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v106);
				*v34 = 5;
				v68 = v34 + 1;
				v141 = v68;
				v68 = (_WORD*)((char*)v68 + 1);
				*v68 = (16 * ((16 * (v112 & 0xF0)) | v67 & 0xF0)) | v126;
				v34 = (unsigned __int8*)(v68 + 1);
				v36 += 3;
			} else {
				v35 += 2;
				*v34 = 1;
				v141 = v34 + 1;
				v34 += 2;
				v149 = 1;
				v137 = 1;
				v36 += 2;
			}
			v69 = v18 + 1;
			v145 = v18 + 1;
			if (v18 + 1 <= v109) {
				do {
					v117 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v102 + v69);
					if (v128 > v117 + 5 || v128 < v117 - 5 ||
						(v70 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v145), v129 > v70 + 5) ||
						v129 < v70 - 5 ||
						(v71 = *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + v105 + v145), v130 > v71 + 5) ||
						v130 < v71 - 5) {
						v75 = *getMemU32Ptr(0x5D4594, 1189588) + v105;
						v76 = *getMemU32Ptr(0x5D4594, 1189588) + v108;
						HIWORD(v77) = HIWORD(v145);
						LOWORD(v75) = (*(_BYTE*)(dword_5d4594_1189596 + v102 + v145) >> 4) |
									  *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v105 + v145) & 0xF0;
						LOWORD(v76) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v108 + v145) & 0xF0;
						LOWORD(v77) = v117 & 0xF0;
						v78 = (16 * ((16 * v77) | v76)) | v75;
						if (v149 == 5) {
							if (++v137 == 254) {
								v80 = v141;
								v81 = (int)(v34 + 1);
								v141 = (_BYTE*)v81;
								v34 = (unsigned __int8*)(v81 + 1);
								*v80 = -3;
								*(v34 - 2) = 5;
								v35 += 2;
								v137 = 1;
								v36 += 2;
							}
							*(_WORD*)v34 = v78;
							v34 += 2;
							v35 += 2;
							++v36;
						} else {
							v79 = v34 + 1;
							v35 += 4;
							*v141 = v137;
							*((_BYTE*)v79 - 1) = 5;
							v141 = v79;
							v79 = (_WORD*)((char*)v79 + 1);
							v149 = 2;
							v137 = 1;
							*v79 = v78;
							v34 = (unsigned __int8*)(v79 + 1);
							v36 += 3;
						}
					} else if (v149 == 1) {
						if (++v137 == 254) {
							v72 = v141;
							v73 = (int)(v34 + 1);
							v141 = (_BYTE*)v73;
							v34 = (unsigned __int8*)(v73 + 1);
							*v72 = -3;
							*(v34 - 2) = 1;
							v35 += 2;
							v137 = 1;
							v36 += 2;
						}
					} else {
						v74 = (int)(v34 + 1);
						v35 += 2;
						*v141 = v137;
						*(_BYTE*)(v74 - 1) = 1;
						v141 = (_BYTE*)v74;
						v34 = (unsigned __int8*)(v74 + 1);
						v149 = 1;
						v137 = 1;
						v36 += 2;
					}
					v69 = ++v145;
				} while (v145 <= v109);
				v18 = v106;
			}
			*v141 = v137;
			goto LABEL_207;
		case 3:
			v103 = 640 * v37;
			v113 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + 640 * v37 + v18);
			if (v128 > v113 + 5 || v128 < v113 - 5 ||
				v129 > *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) + 5 ||
				v129 < *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v18) - 5 ||
				v130 > *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) + 5 ||
				v130 < *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18) - 5) {
				v83 = *(_BYTE*)(v103 + dword_5d4594_1189592 + v18);
				v35 += 4;
				if (v83 == -1) {
					v150 = 5;
					v86 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v18);
					v18 = v106;
					v127 = (*(_BYTE*)(v103 + dword_5d4594_1189596 + v106) >> 4) | v86 & 0xF0;
					v87 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v106);
					*v34 = 5;
					v88 = v34 + 1;
					v142 = v88;
					v88 = (_WORD*)((char*)v88 + 1);
					v82 = 1;
					*v88 = (16 * ((16 * (v113 & 0xF0)) | v87 & 0xF0)) | v127;
					v34 = (unsigned __int8*)(v88 + 1);
					v138 = 1;
					v36 += 3;
				} else {
					*v34 = (16 * v83) | 6;
					v84 = v34 + 1;
					v85 = *(unsigned __int8*)(dword_5d4594_1189592 + v103 + v18);
					v142 = v84++;
					*v84 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v106);
					v18 = v106;
					++v84;
					v150 = (16 * v85) | 6;
					v82 = 1;
					*v84 = *(_BYTE*)(v103 + dword_5d4594_1189596 + v106);
					v34 = v84 + 1;
					v138 = 1;
					v36 += 4;
				}
			} else {
				v82 = 1;
				v35 += 2;
				*v34 = 1;
				v142 = v34 + 1;
				v34 += 2;
				v150 = 1;
				v138 = 1;
				v36 += 2;
			}
			v146 = v18 + 1;
			if (v18 + 1 > v109)
				goto LABEL_205;
			while (1) {
				v118 = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v146);
				if (v128 > v118 + 5 || v128 < v118 - 5)
					goto LABEL_192;
				if (v129 > *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v146) + 5 ||
					v129 < *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7) + v146) - 5 ||
					v130 > *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v146) + 5 ||
					v130 < *(unsigned __int8*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v146) - 5) {
					break;
				}
				if (v150 != 1) {
					v89 = (int)(v34 + 1);
					v150 = 1;
					*v142 = v138;
					*(_BYTE*)(v89 - 1) = 1;
					goto LABEL_189;
				}
				v82 = ++v138;
				if (v138 == 254) {
					v89 = (int)(v34 + 1);
					*v142 = -3;
					*(_BYTE*)(v89 - 1) = 1;
				LABEL_189:
					v82 = 1;
					v142 = (_BYTE*)v89;
					v34 = (unsigned __int8*)(v89 + 1);
					v35 += 2;
					v138 = 1;
					v36 += 2;
				}
			LABEL_204:
				if (++v146 > v109) {
				LABEL_205:
					*v142 = v82;
					goto LABEL_206;
				}
			}
			v82 = v138;
		LABEL_192:
			v90 = *(_BYTE*)(v103 + dword_5d4594_1189592 + v146);
			if (v90 == -1) {
				HIWORD(v94) = *getMemU16Ptr(0x5D4594, 1189590);
				HIWORD(v95) = HIWORD(v146);
				v96 = *getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 3200) << 7);
				LOWORD(v94) = (*(_BYTE*)(dword_5d4594_1189596 + v103 + v146) >> 4) |
							  *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + ((5 * v37 + 6400) << 7) + v146) & 0xF0;
				LOWORD(v96) = *(_BYTE*)(v96 + v146) & 0xF0;
				LOWORD(v95) = v118 & 0xF0;
				v97 = (16 * ((16 * v95) | v96)) | v94;
				if (v150 == 5) {
					v82 = ++v138;
					if (v138 == 254) {
						v99 = v142;
						v100 = (int)(v34 + 1);
						v142 = (_BYTE*)v100;
						v34 = (unsigned __int8*)(v100 + 1);
						*v99 = -3;
						*(v34 - 2) = 5;
						v82 = 1;
						v35 += 2;
						v138 = 1;
						v36 += 2;
					}
					*(_WORD*)v34 = v97;
					v34 += 2;
					v35 += 2;
					goto LABEL_203;
				}
				v98 = v34 + 1;
				v35 += 4;
				*v142 = v138;
				*((_BYTE*)v98 - 1) = 5;
				v142 = v98;
				v98 = (_WORD*)((char*)v98 + 1);
				v82 = 1;
				v150 = 5;
				*v98 = v97;
				v34 = (unsigned __int8*)(v98 + 1);
				v138 = 1;
				v36 += 3;
			} else {
				v122 = (16 * v90) | 6;
				if (v150 == v122) {
					v138 = ++v82;
					if (v82 == 254) {
						v92 = (int)(v34 + 1);
						v35 += 2;
						*v142 = -3;
						*(_BYTE*)(v92 - 1) = v122;
						v82 = 1;
						v142 = (_BYTE*)v92;
						v34 = (unsigned __int8*)(v92 + 1);
						v138 = 1;
						v36 += 2;
					}
					v93 = (int)(v34 + 1);
					*(_BYTE*)(v93 - 1) = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v146);
					v34 = (unsigned __int8*)(v93 + 1);
					++v35;
					*(v34 - 1) = *(_BYTE*)(dword_5d4594_1189596 + v103 + v146);
				LABEL_203:
					++v36;
					goto LABEL_204;
				}
				v150 = v122;
				v91 = v34 + 1;
				v35 += 4;
				*v142 = v82;
				*(v91 - 1) = v122;
				v142 = v91++;
				v82 = 1;
				*v91++ = *(_BYTE*)(*getMemU32Ptr(0x5D4594, 1189588) + v103 + v146);
				v138 = 1;
				*v91 = *(_BYTE*)(dword_5d4594_1189596 + v103 + v146);
				v34 = v91 + 1;
				v36 += 4;
			}
			goto LABEL_204;
		default:
			goto LABEL_207;
		}
	}
}

//----- (0047D090) --------------------------------------------------------
int __cdecl sub_47D090(int a1, int a2) {
	int result;          // eax
	int v3;              // ecx
	int v4;              // edi
	int v5;              // esi
	int v6;              // ebp
	char v7;             // dl
	unsigned __int8* v8; // eax
	int v9;              // [esp+0h] [ebp-4h]
	int v10;             // [esp+Ch] [ebp+8h]

	result = a2;
	if (a2 > 0) {
		v3 = dword_5d4594_1189592;
		v4 = 0;
		v9 = a2;
		do {
			v5 = 0;
			if (a1 > 0) {
				v6 = v4;
				do {
					v7 = 0;
					v8 = getMemAt(0x587000, 153689);
					v10 = 0;
					do {
						if (*(_BYTE*)(v3 + v6) == *(v8 - 1) && *(_BYTE*)(v4 + v3 + 819200 + v5 - 409600) == *v8 &&
							*(_BYTE*)(v4 + v3 + 819200 + v5) == v8[1]) {
							*(_BYTE*)(v3 + v6) = v7;
							v3 = dword_5d4594_1189592;
							v10 = 1;
						}
						v8 += 3;
						++v7;
					} while ((int)v8 < (int)getMemAt(0x587000, 153710));
					if (!v10) {
						*(_BYTE*)(v4 + v3 + v5) = -1;
						v3 = dword_5d4594_1189592;
					}
					++v5;
					++v6;
				} while (v5 < a1);
			}
			v4 += 640;
			result = --v9;
		} while (v9);
	}
	return result;
}

//----- (0047D150) --------------------------------------------------------
LPVOID sub_47D150() {
	LPVOID result; // eax
	char* v1;      // ecx
	int v2;        // edi
	int v3;        // esi

	if (*getMemU32Ptr(0x5D4594, 1189588)) {
		free(*(LPVOID*)getMemAt(0x5D4594, 1189588));
		*getMemU32Ptr(0x5D4594, 1189588) = 0;
	}
	if (dword_5d4594_1189592) {
		free(*(LPVOID*)&dword_5d4594_1189592);
		dword_5d4594_1189592 = 0;
	}
	result = *(LPVOID*)&dword_5d4594_1189596;
	if (dword_5d4594_1189596) {
		free(*(LPVOID*)&dword_5d4594_1189596);
		dword_5d4594_1189596 = 0;
	}
	v1 = *(char**)&dword_5d4594_1189584;
	if (dword_5d4594_1189584) {
		v2 = 0;
		if (dword_5d4594_1123532 > 0) {
			v3 = 0;
			do {
				if (*(_DWORD*)&v1[v3 + 324]) {
					free(*(LPVOID*)&v1[v3 + 324]);
					v1 = *(char**)&dword_5d4594_1189584;
				}
				++v2;
				v3 += 336;
			} while (v2 < *(int*)&dword_5d4594_1123532);
		}
		free(v1);
		dword_5d4594_1189584 = 0;
	}
	return result;
}

//----- (0047D200) --------------------------------------------------------
int sub_47D200() {
	if (dword_5d4594_3801780) {
		if (dword_5d4594_3801780 == 1) {
			if (dword_5d4594_3801804)
				dword_5d4594_3799500 = sub_4C7670;
			else
				dword_5d4594_3799500 = sub_4C7440;
		}
	} else {
		dword_5d4594_3799500 = sub_4C5EB0;
	}
	dword_5d4594_3799484 = 0;
	*getMemU32Ptr(0x5D4594, 3799480) = 0;
	*getMemU32Ptr(0x5D4594, 3799440) = 0;
	dword_5d4594_3799476 = 0;
	dword_5d4594_3799452 = 0;
	*getMemU32Ptr(0x5D4594, 3799472) = 0;
	*getMemU32Ptr(0x5D4594, 3799532) = 0;
	*getMemU32Ptr(0x5D4594, 3799436) = 0;
	*getMemU32Ptr(0x5D4594, 3799464) = 0;
	*getMemU32Ptr(0x5D4594, 3799460) = 0;
	*getMemU32Ptr(0x5D4594, 3799528) = 0;
	*getMemU32Ptr(0x5D4594, 3799448) = 0;
	*getMemU32Ptr(0x5D4594, 3799548) = 0;
	*getMemU32Ptr(0x5D4594, 3799496) = 0;
	dword_5d4594_3799524 = 0;
	dword_5d4594_3799468 = 0;
	dword_5d4594_3799552 = 0;
	dword_5d4594_3799508 = 0;
	dword_5d4594_3799492 = sub_42FB30;
	return 1;
}

//----- (0047D2C0) --------------------------------------------------------
__int16 __cdecl nox_client_drawImageAt_47D2C0(int a1, int a2, int a3) {
	__int16 result; // ax

	if (dword_5d4594_3799452) {
		sub_49F7F0();
		sub_49F780(*(int*)getMemAt(0x5D4594, 3799480), *(int*)getMemAt(0x5D4594, 3799440));
		sub_49F6D0(1);
	}
	(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3799500)(a1, a2, a3);
	if (dword_5d4594_3799452) {
		sub_49F860();
		dword_5d4594_3799452 = 0;
	}
	result = *getMemU16Ptr(0x5D4594, 3799496);
	dword_5d4594_3799484 = 0;
	*getMemU32Ptr(0x5D4594, 3799548) = 0;
	if (*getMemU32Ptr(0x5D4594, 3799496) && a1) {
		if (*getMemU32Ptr(0x5D4594, 3799520) != *(__int16*)(a1 + 4) ||
			*getMemU32Ptr(0x5D4594, 3799512) != *(__int16*)(a1 + 6)) {
			dword_5d4594_3799524 = 1;
		}
		*(_WORD*)(a1 + 4) = *getMemU16Ptr(0x5D4594, 3799520);
		result = *getMemU16Ptr(0x5D4594, 3799512);
		*(_WORD*)(a1 + 6) = *getMemU16Ptr(0x5D4594, 3799512);
	}
	return result;
}

//----- (0047D370) --------------------------------------------------------
int __cdecl sub_47D370(int a1) {
	int result; // eax

	result = a1;
	if (a1 < 0)
		result = 0;
	dword_5d4594_3799484 = result;
	return result;
}

//----- (0047D380) --------------------------------------------------------
int __cdecl sub_47D380(int a1, int a2) {
	int v2; // eax
	int v3; // ecx
	int v4; // edx
	int v5; // esi

	v2 = a1;
	v3 = a2;
	if (a1 > a2) {
		v2 = a2;
		v3 = a1;
	}
	v4 = ptr_5D4594_3799572->data[1];
	if (v2 >= v4) {
		if (v2 >= ptr_5D4594_3799572->data[3])
			return 0;
	} else {
		v2 = ptr_5D4594_3799572->data[1];
	}
	v5 = ptr_5D4594_3799572->data[3];
	if (v3 < v5) {
		if (v3 < v4)
			return 0;
	} else {
		v3 = ptr_5D4594_3799572->data[3];
	}
	if (v2 == v3)
		return 0;
	if (v2 != v4 || v3 != v5) {
		*getMemU32Ptr(0x5D4594, 3799480) = v2;
		*getMemU32Ptr(0x5D4594, 3799440) = v3;
		dword_5d4594_3799452 = 1;
	}
	return 1;
}

//----- (0047D3F0) --------------------------------------------------------
int __cdecl sub_47D3F0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 3799472) = a1;
	return result;
}

//----- (0047D400) --------------------------------------------------------
int __cdecl sub_47D400(int a1, char a2) {
	int result; // eax

	result = a1;
	dword_5d4594_3799552 = a1;
	dword_5d4594_3799508 = a2 & 1;
	return result;
}

//----- (0047D420) --------------------------------------------------------
int __cdecl sub_47D420(int a1, int a2, int a3, int a4, int a5, int a6) {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 3799548) = 1;
	*getMemU32Ptr(0x5D4594, 3799532) = a1 << 16;
	*getMemU32Ptr(0x5D4594, 3799436) = a2 << 16;
	*getMemU32Ptr(0x5D4594, 3799464) = a3 << 16;
	result = a4 << 16;
	*getMemU32Ptr(0x5D4594, 3799460) = a4 << 16;
	*getMemU32Ptr(0x5D4594, 3799528) = a5 << 16;
	*getMemU32Ptr(0x5D4594, 3799448) = a6 << 16;
	return result;
}

//----- (0047D480) --------------------------------------------------------
int __cdecl sub_47D480(int* a1, int a2) {
	int result; // eax

	switch (*(_BYTE*)(a2 + 10) & 0x3F) {
	case 2:
	case 7:
		sub_47D4E0(a1);
		result = 1;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
		sub_47D530(a1);
		goto LABEL_4;
	default:
	LABEL_4:
		result = 1;
		break;
	}
	return result;
}

//----- (0047D4E0) --------------------------------------------------------
__int16 __cdecl sub_47D4E0(_DWORD* a1) {
	int v1;         // ecx
	_WORD* v2;      // edi
	__int16 result; // ax

	v1 = *a1 * a1[1];
	v2 = (_WORD*)((char*)a1 + 17);
	do {
		result = *v2 & 0x1F | (2 * *v2) & 0xFFC0;
		*v2 = result;
		++v2;
	} while (v1-- > 1);
	return result;
}

//----- (0047D530) --------------------------------------------------------
char __cdecl sub_47D530(int* a1) {
	__int16* v1; // esi
	int v2;      // ecx
	__int16 v3;  // ax
	int v4;      // edx
	int v5;      // edi
	bool v6;     // cc
	int v8;      // [esp+Ch] [ebp-8h]
	int v9;      // [esp+10h] [ebp-4h]

	v8 = *a1;
	v9 = a1[1];
	v1 = (__int16*)((char*)a1 + 17);
LABEL_2:
	while (1) {
		v2 = v8;
		do {
			while (1) {
				v3 = *v1;
				++v1;
				LOBYTE(v3) = v3 & 0xF;
				v4 = HIBYTE(v3);
				if ((_BYTE)v3 != 2)
					break;
				v5 = HIBYTE(v3);
				do {
					v3 = *v1 & 0x1F | (2 * (*v1 & 0x7FE0));
					*v1 = v3;
					++v1;
					v6 = v5-- <= 1;
				} while (!v6);
				v6 = v2 <= v4;
				v2 -= v4;
				if (v6) {
					v6 = v9-- <= 1;
					if (!v6)
						goto LABEL_2;
					return v3;
				}
			}
			if ((_BYTE)v3 == 4)
				goto LABEL_13;
			if ((_BYTE)v3 == 5 || (_BYTE)v3 == 6) {
				v1 = (__int16*)((char*)v1 + HIBYTE(v3));
			LABEL_13:
				v1 = (__int16*)((char*)v1 + HIBYTE(v3));
			}
			v6 = v2 <= HIBYTE(v3);
			v2 -= HIBYTE(v3);
		} while (!v6);
		v6 = v9-- <= 1;
		if (!v6)
			continue;
		return v3;
	}
}

//----- (0047D5B0) --------------------------------------------------------
int(__cdecl* __cdecl sub_47D5B0(int a1))(_DWORD) {
	int(__cdecl * result)(_DWORD); // eax

	result = *(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492;
	dword_5d4594_3799492 = a1;
	return result;
}

//----- (0047D5C0) --------------------------------------------------------
int __cdecl sub_47D5C0(int a1, _DWORD* a2, _DWORD* a3, _DWORD* a4, _DWORD* a5) {
	_DWORD* v5; // eax
	_DWORD* v6; // eax
	_DWORD* v7; // eax

	if (a4)
		*a4 = 0;
	if (a5)
		*a5 = 0;
	if (!a1)
		return 0;
	v5 = (_DWORD*)(*(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492)(a1);
	if (!v5)
		return 0;
	if (a4)
		*a4 = *v5;
	v6 = v5 + 1;
	if (a5)
		*a5 = *v6;
	v7 = v6 + 1;
	if (a2)
		*a2 += *v7;
	if (a3)
		*a3 += v7[1];
	return 1;
}

//----- (0047DBC0) --------------------------------------------------------
unsigned __int8 sub_47DBC0() { return getMemByte(0x5D4594, 1193128); }

//----- (0047DBD0) --------------------------------------------------------
void sub_47DBD0() {
	unsigned __int8* v0; // ecx
	int result;          // eax

	v0 = getMemAt(0x5D4594, 1191574);
	result = 0;
	do {
		*((_WORD*)v0 - 1) = 0;
		*(_WORD*)v0 = 0;
		*((_WORD*)v0 + 1) = 0;
		v0 += 6;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1193110));
	strcpy((char*)getMemAt(0x5D4594, 1192838), "\b");
	*getMemU16Ptr(0x5D4594, 1192840) = *getMemU16Ptr(0x5D4594, 1192838);
	*getMemU16Ptr(0x5D4594, 1191656) = *getMemU16Ptr(0x5D4594, 1192838);
	*getMemU16Ptr(0x5D4594, 1191658) = *getMemU16Ptr(0x5D4594, 1192838);
	*getMemU8Ptr(0x5D4594, 1193144) = 0;
	*getMemU16Ptr(0x5D4594, 1192772) = 0;
	*getMemU16Ptr(0x5D4594, 1192774) = 0;
	*getMemU16Ptr(0x5D4594, 1192776) = 0;
	*getMemU16Ptr(0x5D4594, 1192820) = 0;
	*getMemU16Ptr(0x5D4594, 1192822) = 0;
	*getMemU16Ptr(0x5D4594, 1192824) = 0;
	*getMemU16Ptr(0x5D4594, 1192790) = 0;
	*getMemU16Ptr(0x5D4594, 1192792) = 0;
	*getMemU16Ptr(0x5D4594, 1192794) = 0;
	*getMemU16Ptr(0x5D4594, 1192802) = 0;
	*getMemU16Ptr(0x5D4594, 1192804) = 0;
	*getMemU16Ptr(0x5D4594, 1192806) = 0;
	*getMemU16Ptr(0x5D4594, 1192766) = 0;
	*getMemU16Ptr(0x5D4594, 1192768) = 0;
	*getMemU16Ptr(0x5D4594, 1192770) = 0;
	*getMemU16Ptr(0x5D4594, 1192814) = 0;
	*getMemU16Ptr(0x5D4594, 1192816) = 0;
	*getMemU16Ptr(0x5D4594, 1192818) = 0;
	*getMemU16Ptr(0x5D4594, 1192778) = 0;
	*getMemU16Ptr(0x5D4594, 1192780) = 0;
	*getMemU16Ptr(0x5D4594, 1192782) = 0;
	*getMemU16Ptr(0x5D4594, 1192826) = 0;
	*getMemU16Ptr(0x5D4594, 1192828) = 0;
	*getMemU16Ptr(0x5D4594, 1192830) = 0;
	*getMemU16Ptr(0x5D4594, 1192832) = 0;
	*getMemU16Ptr(0x5D4594, 1192834) = 0;
	*getMemU16Ptr(0x5D4594, 1192836) = 0;
	*getMemU16Ptr(0x5D4594, 1192842) = 0;
	*getMemU16Ptr(0x5D4594, 1191660) = 0;
	*getMemU16Ptr(0x5D4594, 1191578) = 0;
	*getMemU16Ptr(0x5D4594, 1191580) = 0;
	*getMemU16Ptr(0x5D4594, 1191582) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191662), "\t");
	*getMemU16Ptr(0x5D4594, 1191664) = *getMemU16Ptr(0x5D4594, 1191662);
	*getMemU16Ptr(0x5D4594, 1191666) = 0;
	*getMemU16Ptr(0x5D4594, 1191920) = 0;
	*getMemU16Ptr(0x5D4594, 1191922) = 0;
	*getMemU16Ptr(0x5D4594, 1191924) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191740), "\n");
	*getMemU16Ptr(0x5D4594, 1191742) = *getMemU16Ptr(0x5D4594, 1191740);
	*getMemU16Ptr(0x5D4594, 1191744) = 0;
	*getMemU16Ptr(0x5D4594, 1192676) = 0;
	*getMemU16Ptr(0x5D4594, 1192678) = 0;
	*getMemU16Ptr(0x5D4594, 1192680) = 0;
	*getMemU16Ptr(0x5D4594, 1192514) = 0;
	*getMemU16Ptr(0x5D4594, 1192516) = 0;
	*getMemU16Ptr(0x5D4594, 1192518) = 0;
	*getMemU16Ptr(0x5D4594, 1191896) = 0;
	*getMemU16Ptr(0x5D4594, 1191898) = 0;
	*getMemU16Ptr(0x5D4594, 1191900) = 0;
	*getMemU16Ptr(0x5D4594, 1191908) = 0;
	*getMemU16Ptr(0x5D4594, 1191910) = 0;
	*getMemU16Ptr(0x5D4594, 1191912) = 0;
	*getMemU16Ptr(0x5D4594, 1191746) = 0;
	*getMemU16Ptr(0x5D4594, 1191748) = 0;
	*getMemU16Ptr(0x5D4594, 1191750) = 0;
	*getMemU16Ptr(0x5D4594, 1191824) = 0;
	*getMemU16Ptr(0x5D4594, 1191826) = 0;
	*getMemU16Ptr(0x5D4594, 1191828) = 0;
	*getMemU16Ptr(0x5D4594, 1191986) = 0;
	*getMemU16Ptr(0x5D4594, 1191988) = 0;
	*getMemU16Ptr(0x5D4594, 1191990) = 0;
	*getMemU16Ptr(0x5D4594, 1191992) = 0;
	*getMemU16Ptr(0x5D4594, 1191994) = 0;
	*getMemU16Ptr(0x5D4594, 1191996) = 0;
	*getMemU16Ptr(0x5D4594, 1192670) = 0;
	*getMemU16Ptr(0x5D4594, 1192672) = 0;
	*getMemU16Ptr(0x5D4594, 1192674) = 0;
	*getMemU16Ptr(0x5D4594, 1191926) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192046), "1");
	*getMemU16Ptr(0x5D4594, 1192048) = *getMemU16Ptr(0x5D4594, 1192046);
	*getMemU16Ptr(0x5D4594, 1191928) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192052), "2");
	*getMemU16Ptr(0x5D4594, 1192054) = *getMemU16Ptr(0x5D4594, 1192052);
	*getMemU16Ptr(0x5D4594, 1191930) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192058), "3");
	*getMemU16Ptr(0x5D4594, 1192060) = *getMemU16Ptr(0x5D4594, 1192058);
	*getMemU16Ptr(0x5D4594, 1191932) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192022), "4");
	*getMemU16Ptr(0x5D4594, 1192024) = *getMemU16Ptr(0x5D4594, 1192022);
	*getMemU16Ptr(0x5D4594, 1191934) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192028), "5");
	*getMemU16Ptr(0x5D4594, 1192030) = *getMemU16Ptr(0x5D4594, 1192028);
	*getMemU16Ptr(0x5D4594, 1191936) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192034), "6");
	*getMemU16Ptr(0x5D4594, 1192036) = *getMemU16Ptr(0x5D4594, 1192034);
	*getMemU16Ptr(0x5D4594, 1191938) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191998), "7");
	*getMemU16Ptr(0x5D4594, 1192000) = *getMemU16Ptr(0x5D4594, 1191998);
	*getMemU16Ptr(0x5D4594, 1191940) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192004), "8");
	*getMemU16Ptr(0x5D4594, 1192006) = *getMemU16Ptr(0x5D4594, 1192004);
	*getMemU16Ptr(0x5D4594, 1191942) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192010), "9");
	*getMemU16Ptr(0x5D4594, 1192012) = *getMemU16Ptr(0x5D4594, 1192010);
	*getMemU16Ptr(0x5D4594, 1191944) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1191914), " ");
	*getMemU16Ptr(0x5D4594, 1191916) = *getMemU16Ptr(0x5D4594, 1191914);
	*getMemU16Ptr(0x5D4594, 1191946) = 0;
	*getMemU16Ptr(0x5D4594, 1191948) = 0;
	*getMemU16Ptr(0x5D4594, 1191950) = 0;
	*getMemU16Ptr(0x5D4594, 1191952) = 0;
	*getMemU16Ptr(0x5D4594, 1191954) = 0;
	*getMemU16Ptr(0x5D4594, 1191956) = 0;
	*getMemU16Ptr(0x5D4594, 1191958) = 0;
	*getMemU16Ptr(0x5D4594, 1191960) = 0;
	*getMemU16Ptr(0x5D4594, 1191962) = 0;
	*getMemU16Ptr(0x5D4594, 1191964) = 0;
	*getMemU16Ptr(0x5D4594, 1191966) = 0;
	*getMemU16Ptr(0x5D4594, 1191968) = 0;
	*getMemU16Ptr(0x5D4594, 1191970) = 0;
	*getMemU16Ptr(0x5D4594, 1191972) = 0;
	*getMemU16Ptr(0x5D4594, 1191974) = 0;
	*getMemU16Ptr(0x5D4594, 1191976) = 0;
	*getMemU16Ptr(0x5D4594, 1191978) = 0;
	*getMemU16Ptr(0x5D4594, 1191980) = 0;
	*getMemU16Ptr(0x5D4594, 1191982) = 0;
	*getMemU16Ptr(0x5D4594, 1191984) = 0;
	*getMemU16Ptr(0x5D4594, 1192094) = 0;
	*getMemU16Ptr(0x5D4594, 1192096) = 0;
	*getMemU16Ptr(0x5D4594, 1192098) = 0;
	*getMemU16Ptr(0x5D4594, 1192100) = 0;
	*getMemU16Ptr(0x5D4594, 1192102) = 0;
	*getMemU16Ptr(0x5D4594, 1192104) = 0;
	*getMemU16Ptr(0x5D4594, 1192050) = 0;
	*getMemU16Ptr(0x5D4594, 1192056) = 0;
	*getMemU16Ptr(0x5D4594, 1192062) = 0;
	*getMemU16Ptr(0x5D4594, 1192026) = 0;
	*getMemU16Ptr(0x5D4594, 1192032) = 0;
	*getMemU16Ptr(0x5D4594, 1192038) = 0;
	*getMemU16Ptr(0x5D4594, 1192002) = 0;
	*getMemU16Ptr(0x5D4594, 1192008) = 0;
	*getMemU16Ptr(0x5D4594, 1192014) = 0;
	strcpy((char*)getMemAt(0x5D4594, 1192064), "0");
	*getMemU16Ptr(0x5D4594, 1192066) = *getMemU16Ptr(0x5D4594, 1192064);
	*getMemU16Ptr(0x5D4594, 1192068) = 0;
	*getMemU16Ptr(0x5D4594, 1191918) = 0;
	switch (dword_587000_26048) {
	case 0:
	case 4:
	case 6:
	case 7:
	case 8:
	case 9:
		strcpy((char*)getMemAt(0x5D4594, 1192508), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192510), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192016), "-");
		*getMemU16Ptr(0x5D4594, 1192018) = *getMemU16Ptr(0x5D4594, 1192016);
		*getMemU16Ptr(0x5D4594, 1192020) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192040), "+");
		*getMemU16Ptr(0x5D4594, 1192042) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1192044) = 0;
		*getMemU16Ptr(0x5D4594, 1192512) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192658), "/");
		*getMemU16Ptr(0x5D4594, 1192660) = *getMemU16Ptr(0x5D4594, 1192658);
		*getMemU16Ptr(0x5D4594, 1192662) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192070), ".");
		*getMemU16Ptr(0x5D4594, 1192072) = *getMemU16Ptr(0x5D4594, 1192070);
		*getMemU16Ptr(0x5D4594, 1192074) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191902), "*");
		*getMemU16Ptr(0x5D4594, 1191904) = *getMemU16Ptr(0x5D4594, 1191902);
		*getMemU16Ptr(0x5D4594, 1191906) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191752), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191754), "A");
		*getMemU16Ptr(0x5D4594, 1191756) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191860), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191862), "B");
		*getMemU16Ptr(0x5D4594, 1191864) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191848), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191850), "C");
		*getMemU16Ptr(0x5D4594, 1191852) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191764), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191766), "D");
		*getMemU16Ptr(0x5D4594, 1191768) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191680), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191682), "E");
		*getMemU16Ptr(0x5D4594, 1191684) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191770), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191772), "F");
		*getMemU16Ptr(0x5D4594, 1191774) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191776), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191778), "G");
		*getMemU16Ptr(0x5D4594, 1191780) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191782), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191784), "H");
		*getMemU16Ptr(0x5D4594, 1191786) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191710), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191712), "I");
		*getMemU16Ptr(0x5D4594, 1191714) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191788), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191790), "J");
		*getMemU16Ptr(0x5D4594, 1191792) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191794), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191796), "K");
		*getMemU16Ptr(0x5D4594, 1191798) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191800), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191802), "L");
		*getMemU16Ptr(0x5D4594, 1191804) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191872), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191874), "M");
		*getMemU16Ptr(0x5D4594, 1191876) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191866), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191868), "N");
		*getMemU16Ptr(0x5D4594, 1191870) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191716), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191718), "O");
		*getMemU16Ptr(0x5D4594, 1191720) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191722), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191724), "P");
		*getMemU16Ptr(0x5D4594, 1191726) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191668), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191670), "Q");
		*getMemU16Ptr(0x5D4594, 1191672) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191686), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191688), "R");
		*getMemU16Ptr(0x5D4594, 1191690) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191758), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191760), "S");
		*getMemU16Ptr(0x5D4594, 1191762) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191692), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191694), "T");
		*getMemU16Ptr(0x5D4594, 1191696) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191704), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191706), "U");
		*getMemU16Ptr(0x5D4594, 1191708) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191854), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191856), "V");
		*getMemU16Ptr(0x5D4594, 1191858) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191674), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191676), "W");
		*getMemU16Ptr(0x5D4594, 1191678) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191842), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191844), "X");
		*getMemU16Ptr(0x5D4594, 1191846) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191698), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191700), "Y");
		*getMemU16Ptr(0x5D4594, 1191702) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191836), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191838), "Z");
		*getMemU16Ptr(0x5D4594, 1191840) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191584), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191586), "!");
		*getMemU16Ptr(0x5D4594, 1191588) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191590), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191592), "@");
		*getMemU16Ptr(0x5D4594, 1191594) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191596), "3");
		strcpy((char*)getMemAt(0x5D4594, 1191598), "#");
		*getMemU16Ptr(0x5D4594, 1191600) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191602), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191604), "$");
		*getMemU16Ptr(0x5D4594, 1191606) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191608), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191610), "%");
		*getMemU16Ptr(0x5D4594, 1191612) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191614), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191616), "^");
		*getMemU16Ptr(0x5D4594, 1191618) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191620), "7");
		strcpy((char*)getMemAt(0x5D4594, 1191622), "&");
		*getMemU16Ptr(0x5D4594, 1191624) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191626), "8");
		*getMemU16Ptr(0x5D4594, 1191628) = *getMemU16Ptr(0x5D4594, 1191902);
		*getMemU16Ptr(0x5D4594, 1191630) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191632), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191634), "(");
		*getMemU16Ptr(0x5D4594, 1191636) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191638), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191640), ")");
		*getMemU16Ptr(0x5D4594, 1191642) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191878), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191880), "<");
		*getMemU16Ptr(0x5D4594, 1191882) = 0;
		*getMemU16Ptr(0x5D4594, 1191884) = *getMemU16Ptr(0x5D4594, 1192070);
		strcpy((char*)getMemAt(0x5D4594, 1191886), ">");
		*getMemU16Ptr(0x5D4594, 1191888) = 0;
		*getMemU16Ptr(0x5D4594, 1191890) = *getMemU16Ptr(0x5D4594, 1192658);
		strcpy((char*)getMemAt(0x5D4594, 1191892), "?");
		*getMemU16Ptr(0x5D4594, 1191894) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191728), "[");
		strcpy((char*)getMemAt(0x5D4594, 1191730), "{");
		*getMemU16Ptr(0x5D4594, 1191732) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191734), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191736), "}");
		*getMemU16Ptr(0x5D4594, 1191738) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191806), ";");
		strcpy((char*)getMemAt(0x5D4594, 1191808), ":");
		*getMemU16Ptr(0x5D4594, 1191810) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191812), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191814), "\"");
		*getMemU16Ptr(0x5D4594, 1191816) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191818), "`");
		strcpy((char*)getMemAt(0x5D4594, 1191820), "~");
		*getMemU16Ptr(0x5D4594, 1191822) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191830), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1191832), "|");
		*getMemU16Ptr(0x5D4594, 1191834) = 0;
		*getMemU16Ptr(0x5D4594, 1191644) = *getMemU16Ptr(0x5D4594, 1192016);
		strcpy((char*)getMemAt(0x5D4594, 1191646), "_");
		*getMemU16Ptr(0x5D4594, 1191648) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191650), "=");
		*getMemU16Ptr(0x5D4594, 1191652) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1191654) = 0;
		break;
	case 1:
		strcpy((char*)getMemAt(0x5D4594, 1192508), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192510), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192016), "-");
		*getMemU16Ptr(0x5D4594, 1192018) = *getMemU16Ptr(0x5D4594, 1192016);
		*getMemU16Ptr(0x5D4594, 1192020) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192040), "+");
		*getMemU16Ptr(0x5D4594, 1192042) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1192044) = 0;
		*getMemU16Ptr(0x5D4594, 1192512) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192658), "/");
		*getMemU16Ptr(0x5D4594, 1192660) = *getMemU16Ptr(0x5D4594, 1192658);
		*getMemU16Ptr(0x5D4594, 1192662) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192070), ".");
		*getMemU16Ptr(0x5D4594, 1192072) = *getMemU16Ptr(0x5D4594, 1192070);
		*getMemU16Ptr(0x5D4594, 1192074) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191902), "*");
		*getMemU16Ptr(0x5D4594, 1191904) = *getMemU16Ptr(0x5D4594, 1191902);
		*getMemU16Ptr(0x5D4594, 1191906) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191752), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191754), "A");
		*getMemU16Ptr(0x5D4594, 1191756) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191860), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191862), "B");
		*getMemU16Ptr(0x5D4594, 1191864) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191848), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191850), "C");
		*getMemU16Ptr(0x5D4594, 1191852) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191764), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191766), "D");
		*getMemU16Ptr(0x5D4594, 1191768) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191680), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191682), "E");
		*getMemU16Ptr(0x5D4594, 1191684) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191770), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191772), "F");
		*getMemU16Ptr(0x5D4594, 1191774) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191776), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191778), "G");
		*getMemU16Ptr(0x5D4594, 1191780) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191782), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191784), "H");
		*getMemU16Ptr(0x5D4594, 1191786) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191710), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191712), "I");
		*getMemU16Ptr(0x5D4594, 1191714) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191788), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191790), "J");
		*getMemU16Ptr(0x5D4594, 1191792) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191794), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191796), "K");
		*getMemU16Ptr(0x5D4594, 1191798) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191800), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191802), "L");
		*getMemU16Ptr(0x5D4594, 1191804) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191872), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191874), "M");
		*getMemU16Ptr(0x5D4594, 1191876) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191866), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191868), "N");
		*getMemU16Ptr(0x5D4594, 1191870) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191716), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191718), "O");
		*getMemU16Ptr(0x5D4594, 1191720) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191722), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191724), "P");
		*getMemU16Ptr(0x5D4594, 1191726) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191668), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191670), "Q");
		*getMemU16Ptr(0x5D4594, 1191672) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191686), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191688), "R");
		*getMemU16Ptr(0x5D4594, 1191690) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191758), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191760), "S");
		*getMemU16Ptr(0x5D4594, 1191762) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191692), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191694), "T");
		*getMemU16Ptr(0x5D4594, 1191696) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191704), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191706), "U");
		*getMemU16Ptr(0x5D4594, 1191708) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191854), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191856), "V");
		*getMemU16Ptr(0x5D4594, 1191858) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191674), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191676), "W");
		*getMemU16Ptr(0x5D4594, 1191678) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191842), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191844), "X");
		*getMemU16Ptr(0x5D4594, 1191846) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191698), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191700), "Y");
		*getMemU16Ptr(0x5D4594, 1191702) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191836), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191838), "Z");
		*getMemU16Ptr(0x5D4594, 1191840) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191584), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191586), "!");
		*getMemU16Ptr(0x5D4594, 1191588) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191590), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191592), "\"");
		*getMemU16Ptr(0x5D4594, 1191594) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191596), "3");
		*getMemU16Ptr(0x5D4594, 1191598) = 163;
		*getMemU16Ptr(0x5D4594, 1191600) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191602), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191604), "$");
		*getMemU16Ptr(0x5D4594, 1191606) = 8364;
		strcpy((char*)getMemAt(0x5D4594, 1191608), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191610), "%");
		*getMemU16Ptr(0x5D4594, 1191612) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191614), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191616), "^");
		*getMemU16Ptr(0x5D4594, 1191618) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191620), "7");
		strcpy((char*)getMemAt(0x5D4594, 1191622), "&");
		*getMemU16Ptr(0x5D4594, 1191624) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191626), "8");
		*getMemU16Ptr(0x5D4594, 1191628) = *getMemU16Ptr(0x5D4594, 1191902);
		*getMemU16Ptr(0x5D4594, 1191630) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191632), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191634), "(");
		*getMemU16Ptr(0x5D4594, 1191636) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191638), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191640), ")");
		*getMemU16Ptr(0x5D4594, 1191642) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191878), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191880), "<");
		*getMemU16Ptr(0x5D4594, 1191882) = 0;
		*getMemU16Ptr(0x5D4594, 1191884) = *getMemU16Ptr(0x5D4594, 1192070);
		strcpy((char*)getMemAt(0x5D4594, 1191886), ">");
		*getMemU16Ptr(0x5D4594, 1191888) = 0;
		*getMemU16Ptr(0x5D4594, 1191890) = *getMemU16Ptr(0x5D4594, 1192658);
		strcpy((char*)getMemAt(0x5D4594, 1191892), "?");
		*getMemU16Ptr(0x5D4594, 1191894) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191728), "[");
		strcpy((char*)getMemAt(0x5D4594, 1191730), "{");
		*getMemU16Ptr(0x5D4594, 1191732) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191734), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191736), "}");
		*getMemU16Ptr(0x5D4594, 1191738) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191806), ";");
		strcpy((char*)getMemAt(0x5D4594, 1191808), ":");
		*getMemU16Ptr(0x5D4594, 1191810) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191812), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191814), "@");
		*getMemU16Ptr(0x5D4594, 1191816) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191818), "`");
		*getMemU16Ptr(0x5D4594, 1191820) = 172;
		*getMemU16Ptr(0x5D4594, 1191822) = 166;
		strcpy((char*)getMemAt(0x5D4594, 1191830), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191832), "~");
		*getMemU16Ptr(0x5D4594, 1191834) = 0;
		*getMemU16Ptr(0x5D4594, 1191644) = *getMemU16Ptr(0x5D4594, 1192016);
		strcpy((char*)getMemAt(0x5D4594, 1191646), "_");
		*getMemU16Ptr(0x5D4594, 1191648) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191650), "=");
		*getMemU16Ptr(0x5D4594, 1191652) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1191654) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192088), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1192090), "|");
		*getMemU16Ptr(0x5D4594, 1192092) = 0;
		*getMemU8Ptr(0x5D4594, 1193144) = -72;
		break;
	case 2:
		strcpy((char*)getMemAt(0x5D4594, 1192508), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192510), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192016), "-");
		*getMemU16Ptr(0x5D4594, 1192018) = *getMemU16Ptr(0x5D4594, 1192016);
		*getMemU16Ptr(0x5D4594, 1192020) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192040), "+");
		*getMemU16Ptr(0x5D4594, 1192042) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1192044) = 0;
		*getMemU16Ptr(0x5D4594, 1192512) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192658), "/");
		*getMemU16Ptr(0x5D4594, 1192660) = *getMemU16Ptr(0x5D4594, 1192658);
		*getMemU16Ptr(0x5D4594, 1192662) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192070), ",");
		*getMemU16Ptr(0x5D4594, 1192072) = *getMemU16Ptr(0x5D4594, 1192070);
		*getMemU16Ptr(0x5D4594, 1192074) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191902), "*");
		*getMemU16Ptr(0x5D4594, 1191904) = *getMemU16Ptr(0x5D4594, 1191902);
		*getMemU16Ptr(0x5D4594, 1191906) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191752), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191754), "A");
		*getMemU16Ptr(0x5D4594, 1191756) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191860), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191862), "B");
		*getMemU16Ptr(0x5D4594, 1191864) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191848), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191850), "C");
		*getMemU16Ptr(0x5D4594, 1191852) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191764), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191766), "D");
		*getMemU16Ptr(0x5D4594, 1191768) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191680), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191682), "E");
		*getMemU16Ptr(0x5D4594, 1191684) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191770), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191772), "F");
		*getMemU16Ptr(0x5D4594, 1191774) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191776), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191778), "G");
		*getMemU16Ptr(0x5D4594, 1191780) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191782), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191784), "H");
		*getMemU16Ptr(0x5D4594, 1191786) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191710), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191712), "I");
		*getMemU16Ptr(0x5D4594, 1191714) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191788), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191790), "J");
		*getMemU16Ptr(0x5D4594, 1191792) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191794), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191796), "K");
		*getMemU16Ptr(0x5D4594, 1191798) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191800), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191802), "L");
		*getMemU16Ptr(0x5D4594, 1191804) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191872), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191874), "M");
		strcpy((char*)getMemAt(0x5D4594, 1191876), "\xb5"); // µ
		strcpy((char*)getMemAt(0x5D4594, 1191866), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191868), "N");
		*getMemU16Ptr(0x5D4594, 1191870) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191716), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191718), "O");
		*getMemU16Ptr(0x5D4594, 1191720) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191722), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191724), "P");
		*getMemU16Ptr(0x5D4594, 1191726) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191668), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191670), "Q");
		strcpy((char*)getMemAt(0x5D4594, 1191672), "@");
		strcpy((char*)getMemAt(0x5D4594, 1191686), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191688), "R");
		*getMemU16Ptr(0x5D4594, 1191690) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191758), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191760), "S");
		*getMemU16Ptr(0x5D4594, 1191762) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191692), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191694), "T");
		*getMemU16Ptr(0x5D4594, 1191696) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191704), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191706), "U");
		*getMemU16Ptr(0x5D4594, 1191708) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191854), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191856), "V");
		*getMemU16Ptr(0x5D4594, 1191858) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191674), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191676), "W");
		*getMemU16Ptr(0x5D4594, 1191678) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191842), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191844), "X");
		*getMemU16Ptr(0x5D4594, 1191846) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191698), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191700), "Z");
		*getMemU16Ptr(0x5D4594, 1191702) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191836), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191838), "Y");
		*getMemU16Ptr(0x5D4594, 1191840) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191584), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191586), "!");
		*getMemU16Ptr(0x5D4594, 1191588) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191590), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191592), "\"");
		*getMemU16Ptr(0x5D4594, 1191594) = 178;
		strcpy((char*)getMemAt(0x5D4594, 1191596), "3");
		*getMemU16Ptr(0x5D4594, 1191598) = 167;
		*getMemU16Ptr(0x5D4594, 1191600) = 179;
		strcpy((char*)getMemAt(0x5D4594, 1191602), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191604), "$");
		*getMemU16Ptr(0x5D4594, 1191606) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191608), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191610), "%");
		*getMemU16Ptr(0x5D4594, 1191612) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191614), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191616), "&");
		*getMemU16Ptr(0x5D4594, 1191618) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191620), "7");
		*getMemU16Ptr(0x5D4594, 1191622) = *getMemU16Ptr(0x5D4594, 1192658);
		strcpy((char*)getMemAt(0x5D4594, 1191624), "{");
		strcpy((char*)getMemAt(0x5D4594, 1191626), "8");
		strcpy((char*)getMemAt(0x5D4594, 1191628), "(");
		strcpy((char*)getMemAt(0x5D4594, 1191630), "[");
		strcpy((char*)getMemAt(0x5D4594, 1191632), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191634), ")");
		strcpy((char*)getMemAt(0x5D4594, 1191636), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191638), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191640), "=");
		strcpy((char*)getMemAt(0x5D4594, 1191642), "}");
		*getMemU16Ptr(0x5D4594, 1191878) = *getMemU16Ptr(0x5D4594, 1192070);
		strcpy((char*)getMemAt(0x5D4594, 1191880), ";");
		*getMemU16Ptr(0x5D4594, 1191882) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191884), ".");
		strcpy((char*)getMemAt(0x5D4594, 1191886), ":");
		*getMemU16Ptr(0x5D4594, 1191888) = 0;
		*getMemU16Ptr(0x5D4594, 1191890) = *getMemU16Ptr(0x5D4594, 1192016);
		strcpy((char*)getMemAt(0x5D4594, 1191892), "_");
		*getMemU16Ptr(0x5D4594, 1191894) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191728), "\xfc"); // ü
		strcpy((char*)getMemAt(0x5D4594, 1191730), "\xdc"); // Ü
		*getMemU16Ptr(0x5D4594, 1191732) = 0;
		*getMemU16Ptr(0x5D4594, 1191734) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1191736) = *getMemU16Ptr(0x5D4594, 1191902);
		strcpy((char*)getMemAt(0x5D4594, 1191738), "~");
		strcpy((char*)getMemAt(0x5D4594, 1191806), "\xf6"); // ö
		strcpy((char*)getMemAt(0x5D4594, 1191808), "\xd6"); // Ö
		*getMemU16Ptr(0x5D4594, 1191810) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191812), "\xe4"); // ä
		strcpy((char*)getMemAt(0x5D4594, 1191814), "\xc4"); // Ä
		*getMemU16Ptr(0x5D4594, 1191816) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191818), "^");
		strcpy((char*)getMemAt(0x5D4594, 1191820), "\xb0"); // °
		*getMemU16Ptr(0x5D4594, 1191822) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191830), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191832), "'");
		*getMemU16Ptr(0x5D4594, 1191834) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191644), "\xdf"); // ß
		strcpy((char*)getMemAt(0x5D4594, 1191646), "?");
		strcpy((char*)getMemAt(0x5D4594, 1191648), "\\");
		*getMemU16Ptr(0x5D4594, 1191650) = 180;
		strcpy((char*)getMemAt(0x5D4594, 1191652), "`");
		*getMemU16Ptr(0x5D4594, 1191654) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192088), "<");
		strcpy((char*)getMemAt(0x5D4594, 1192090), ">");
		strcpy((char*)getMemAt(0x5D4594, 1192092), "|");
		*getMemU8Ptr(0x5D4594, 1193144) = -72;
		break;
	case 3:
		strcpy((char*)getMemAt(0x5D4594, 1192508), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192510), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192016), "-");
		*getMemU16Ptr(0x5D4594, 1192018) = *getMemU16Ptr(0x5D4594, 1192016);
		*getMemU16Ptr(0x5D4594, 1192020) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192040), "+");
		*getMemU16Ptr(0x5D4594, 1192042) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1192044) = 0;
		*getMemU16Ptr(0x5D4594, 1192512) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192658), "/");
		*getMemU16Ptr(0x5D4594, 1192660) = *getMemU16Ptr(0x5D4594, 1192658);
		*getMemU16Ptr(0x5D4594, 1192662) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192070), ".");
		*getMemU16Ptr(0x5D4594, 1192072) = *getMemU16Ptr(0x5D4594, 1192070);
		*getMemU16Ptr(0x5D4594, 1192074) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191902), "*");
		*getMemU16Ptr(0x5D4594, 1191904) = *getMemU16Ptr(0x5D4594, 1191902);
		*getMemU16Ptr(0x5D4594, 1191906) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191752), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191754), "Q");
		*getMemU16Ptr(0x5D4594, 1191756) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191860), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191862), "B");
		*getMemU16Ptr(0x5D4594, 1191864) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191848), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191850), "C");
		*getMemU16Ptr(0x5D4594, 1191852) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191764), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191766), "D");
		*getMemU16Ptr(0x5D4594, 1191768) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191680), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191682), "E");
		*getMemU16Ptr(0x5D4594, 1191684) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191770), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191772), "F");
		*getMemU16Ptr(0x5D4594, 1191774) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191776), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191778), "G");
		*getMemU16Ptr(0x5D4594, 1191780) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191782), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191784), "H");
		*getMemU16Ptr(0x5D4594, 1191786) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191710), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191712), "I");
		*getMemU16Ptr(0x5D4594, 1191714) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191788), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191790), "J");
		*getMemU16Ptr(0x5D4594, 1191792) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191794), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191796), "K");
		*getMemU16Ptr(0x5D4594, 1191798) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191800), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191802), "L");
		*getMemU16Ptr(0x5D4594, 1191804) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191872), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191874), "?");
		*getMemU16Ptr(0x5D4594, 1191876) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191866), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191868), "N");
		*getMemU16Ptr(0x5D4594, 1191870) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191716), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191718), "O");
		*getMemU16Ptr(0x5D4594, 1191720) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191722), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191724), "P");
		*getMemU16Ptr(0x5D4594, 1191726) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191668), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191670), "A");
		*getMemU16Ptr(0x5D4594, 1191672) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191686), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191688), "R");
		*getMemU16Ptr(0x5D4594, 1191690) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191758), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191760), "S");
		*getMemU16Ptr(0x5D4594, 1191762) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191692), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191694), "T");
		*getMemU16Ptr(0x5D4594, 1191696) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191704), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191706), "U");
		*getMemU16Ptr(0x5D4594, 1191708) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191854), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191856), "V");
		*getMemU16Ptr(0x5D4594, 1191858) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191674), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191676), "Z");
		*getMemU16Ptr(0x5D4594, 1191678) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191842), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191844), "X");
		*getMemU16Ptr(0x5D4594, 1191846) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191698), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191700), "Y");
		*getMemU16Ptr(0x5D4594, 1191702) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191836), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191838), "W");
		*getMemU16Ptr(0x5D4594, 1191840) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191584), "&");
		strcpy((char*)getMemAt(0x5D4594, 1191586), "1");
		*getMemU16Ptr(0x5D4594, 1191588) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191590), "\xe9"); // é
		strcpy((char*)getMemAt(0x5D4594, 1191592), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191594), "~");
		strcpy((char*)getMemAt(0x5D4594, 1191596), "\"");
		strcpy((char*)getMemAt(0x5D4594, 1191598), "3");
		strcpy((char*)getMemAt(0x5D4594, 1191600), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191602), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191604), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191606), "{");
		strcpy((char*)getMemAt(0x5D4594, 1191608), "(");
		strcpy((char*)getMemAt(0x5D4594, 1191610), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191612), "[");
		*getMemU16Ptr(0x5D4594, 1191614) = *getMemU16Ptr(0x5D4594, 1192016);
		strcpy((char*)getMemAt(0x5D4594, 1191616), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191618), "|");
		strcpy((char*)getMemAt(0x5D4594, 1191620), "\xe8"); // è
		strcpy((char*)getMemAt(0x5D4594, 1191622), "7");
		strcpy((char*)getMemAt(0x5D4594, 1191624), "`");
		strcpy((char*)getMemAt(0x5D4594, 1191626), "_");
		strcpy((char*)getMemAt(0x5D4594, 1191628), "8");
		strcpy((char*)getMemAt(0x5D4594, 1191630), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1191632), "\xe7"); // ç
		strcpy((char*)getMemAt(0x5D4594, 1191634), "9");
		*getMemU16Ptr(0x5D4594, 1191636) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191638), "\xe0"); // à
		strcpy((char*)getMemAt(0x5D4594, 1191640), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191642), "@");
		strcpy((char*)getMemAt(0x5D4594, 1191878), ";");
		*getMemU16Ptr(0x5D4594, 1191880) = *getMemU16Ptr(0x5D4594, 1192070);
		*getMemU16Ptr(0x5D4594, 1191882) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191884), ":");
		*getMemU16Ptr(0x5D4594, 1191886) = *getMemU16Ptr(0x5D4594, 1192658);
		*getMemU16Ptr(0x5D4594, 1191888) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191890), "!");
		*getMemU16Ptr(0x5D4594, 1191892) = 167;
		*getMemU16Ptr(0x5D4594, 1191894) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191728), "^");
		*getMemU16Ptr(0x5D4594, 1191730) = 168;
		*getMemU16Ptr(0x5D4594, 1191732) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191734), "$");
		*getMemU16Ptr(0x5D4594, 1191736) = 163;
		*getMemU16Ptr(0x5D4594, 1191738) = 164;
		strcpy((char*)getMemAt(0x5D4594, 1191806), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191808), "M");
		*getMemU16Ptr(0x5D4594, 1191810) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191812), "\xf9"); // ù
		strcpy((char*)getMemAt(0x5D4594, 1191814), "%");
		*getMemU16Ptr(0x5D4594, 1191816) = 0;
		*getMemU16Ptr(0x5D4594, 1191818) = 178;
		*getMemU16Ptr(0x5D4594, 1191820) = 0;
		*getMemU16Ptr(0x5D4594, 1191822) = 0;
		*getMemU16Ptr(0x5D4594, 1191830) = *getMemU16Ptr(0x5D4594, 1191902);
		strcpy((char*)getMemAt(0x5D4594, 1191832), "\xb5"); // µ
		*getMemU16Ptr(0x5D4594, 1191834) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191644), ")");
		strcpy((char*)getMemAt(0x5D4594, 1191646), "\xb0"); // °
		strcpy((char*)getMemAt(0x5D4594, 1191648), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191650), "=");
		*getMemU16Ptr(0x5D4594, 1191652) = *getMemU16Ptr(0x5D4594, 1192040);
		strcpy((char*)getMemAt(0x5D4594, 1191654), "}");
		goto LABEL_9;
	case 5:
		strcpy((char*)getMemAt(0x5D4594, 1192508), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192510), "\n");
		strcpy((char*)getMemAt(0x5D4594, 1192016), "-");
		*getMemU16Ptr(0x5D4594, 1192018) = *getMemU16Ptr(0x5D4594, 1192016);
		*getMemU16Ptr(0x5D4594, 1192020) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192040), "+");
		*getMemU16Ptr(0x5D4594, 1192042) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1192044) = 0;
		*getMemU16Ptr(0x5D4594, 1192512) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192658), "/");
		*getMemU16Ptr(0x5D4594, 1192660) = *getMemU16Ptr(0x5D4594, 1192658);
		*getMemU16Ptr(0x5D4594, 1192662) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1192070), ".");
		*getMemU16Ptr(0x5D4594, 1192072) = *getMemU16Ptr(0x5D4594, 1192070);
		*getMemU16Ptr(0x5D4594, 1192074) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191902), "*");
		*getMemU16Ptr(0x5D4594, 1191904) = *getMemU16Ptr(0x5D4594, 1191902);
		*getMemU16Ptr(0x5D4594, 1191906) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191752), "a");
		strcpy((char*)getMemAt(0x5D4594, 1191754), "A");
		*getMemU16Ptr(0x5D4594, 1191756) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191860), "b");
		strcpy((char*)getMemAt(0x5D4594, 1191862), "B");
		*getMemU16Ptr(0x5D4594, 1191864) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191848), "c");
		strcpy((char*)getMemAt(0x5D4594, 1191850), "C");
		*getMemU16Ptr(0x5D4594, 1191852) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191764), "d");
		strcpy((char*)getMemAt(0x5D4594, 1191766), "D");
		*getMemU16Ptr(0x5D4594, 1191768) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191680), "e");
		strcpy((char*)getMemAt(0x5D4594, 1191682), "E");
		*getMemU16Ptr(0x5D4594, 1191684) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191770), "f");
		strcpy((char*)getMemAt(0x5D4594, 1191772), "F");
		*getMemU16Ptr(0x5D4594, 1191774) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191776), "g");
		strcpy((char*)getMemAt(0x5D4594, 1191778), "G");
		*getMemU16Ptr(0x5D4594, 1191780) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191782), "h");
		strcpy((char*)getMemAt(0x5D4594, 1191784), "H");
		*getMemU16Ptr(0x5D4594, 1191786) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191710), "i");
		strcpy((char*)getMemAt(0x5D4594, 1191712), "I");
		*getMemU16Ptr(0x5D4594, 1191714) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191788), "j");
		strcpy((char*)getMemAt(0x5D4594, 1191790), "J");
		*getMemU16Ptr(0x5D4594, 1191792) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191794), "k");
		strcpy((char*)getMemAt(0x5D4594, 1191796), "K");
		*getMemU16Ptr(0x5D4594, 1191798) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191800), "l");
		strcpy((char*)getMemAt(0x5D4594, 1191802), "L");
		*getMemU16Ptr(0x5D4594, 1191804) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191872), "m");
		strcpy((char*)getMemAt(0x5D4594, 1191874), "M");
		*getMemU16Ptr(0x5D4594, 1191876) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191866), "n");
		strcpy((char*)getMemAt(0x5D4594, 1191868), "N");
		*getMemU16Ptr(0x5D4594, 1191870) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191716), "o");
		strcpy((char*)getMemAt(0x5D4594, 1191718), "O");
		*getMemU16Ptr(0x5D4594, 1191720) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191722), "p");
		strcpy((char*)getMemAt(0x5D4594, 1191724), "P");
		*getMemU16Ptr(0x5D4594, 1191726) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191668), "q");
		strcpy((char*)getMemAt(0x5D4594, 1191670), "Q");
		*getMemU16Ptr(0x5D4594, 1191672) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191686), "r");
		strcpy((char*)getMemAt(0x5D4594, 1191688), "R");
		*getMemU16Ptr(0x5D4594, 1191690) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191758), "s");
		strcpy((char*)getMemAt(0x5D4594, 1191760), "S");
		*getMemU16Ptr(0x5D4594, 1191762) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191692), "t");
		strcpy((char*)getMemAt(0x5D4594, 1191694), "T");
		*getMemU16Ptr(0x5D4594, 1191696) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191704), "u");
		strcpy((char*)getMemAt(0x5D4594, 1191706), "U");
		*getMemU16Ptr(0x5D4594, 1191708) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191854), "v");
		strcpy((char*)getMemAt(0x5D4594, 1191856), "V");
		*getMemU16Ptr(0x5D4594, 1191858) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191674), "w");
		strcpy((char*)getMemAt(0x5D4594, 1191676), "W");
		*getMemU16Ptr(0x5D4594, 1191678) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191842), "x");
		strcpy((char*)getMemAt(0x5D4594, 1191844), "X");
		*getMemU16Ptr(0x5D4594, 1191846) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191698), "y");
		strcpy((char*)getMemAt(0x5D4594, 1191700), "Y");
		*getMemU16Ptr(0x5D4594, 1191702) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191836), "z");
		strcpy((char*)getMemAt(0x5D4594, 1191838), "Z");
		*getMemU16Ptr(0x5D4594, 1191840) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191584), "1");
		strcpy((char*)getMemAt(0x5D4594, 1191586), "!");
		*getMemU16Ptr(0x5D4594, 1191588) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191590), "2");
		strcpy((char*)getMemAt(0x5D4594, 1191592), "\"");
		*getMemU16Ptr(0x5D4594, 1191594) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191596), "3");
		*getMemU16Ptr(0x5D4594, 1191598) = 163;
		*getMemU16Ptr(0x5D4594, 1191600) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191602), "4");
		strcpy((char*)getMemAt(0x5D4594, 1191604), "$");
		*getMemU16Ptr(0x5D4594, 1191606) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191608), "5");
		strcpy((char*)getMemAt(0x5D4594, 1191610), "%");
		*getMemU16Ptr(0x5D4594, 1191612) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191614), "6");
		strcpy((char*)getMemAt(0x5D4594, 1191616), "&");
		*getMemU16Ptr(0x5D4594, 1191618) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191620), "7");
		*getMemU16Ptr(0x5D4594, 1191622) = *getMemU16Ptr(0x5D4594, 1192658);
		*getMemU16Ptr(0x5D4594, 1191624) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191626), "8");
		strcpy((char*)getMemAt(0x5D4594, 1191628), "(");
		*getMemU16Ptr(0x5D4594, 1191630) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191632), "9");
		strcpy((char*)getMemAt(0x5D4594, 1191634), ")");
		*getMemU16Ptr(0x5D4594, 1191636) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191638), "0");
		strcpy((char*)getMemAt(0x5D4594, 1191640), "=");
		*getMemU16Ptr(0x5D4594, 1191642) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191878), ",");
		strcpy((char*)getMemAt(0x5D4594, 1191880), ";");
		*getMemU16Ptr(0x5D4594, 1191882) = 0;
		*getMemU16Ptr(0x5D4594, 1191884) = *getMemU16Ptr(0x5D4594, 1192070);
		strcpy((char*)getMemAt(0x5D4594, 1191886), ":");
		*getMemU16Ptr(0x5D4594, 1191888) = 0;
		*getMemU16Ptr(0x5D4594, 1191890) = *getMemU16Ptr(0x5D4594, 1192016);
		strcpy((char*)getMemAt(0x5D4594, 1191892), "_");
		*getMemU16Ptr(0x5D4594, 1191894) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191728), "\xe8"); // è
		strcpy((char*)getMemAt(0x5D4594, 1191730), "\xe9"); // é
		strcpy((char*)getMemAt(0x5D4594, 1191732), "[");
		*getMemU16Ptr(0x5D4594, 1191734) = *getMemU16Ptr(0x5D4594, 1192040);
		*getMemU16Ptr(0x5D4594, 1191736) = *getMemU16Ptr(0x5D4594, 1191902);
		strcpy((char*)getMemAt(0x5D4594, 1191738), "]");
		strcpy((char*)getMemAt(0x5D4594, 1191806), "\xf2"); // ò
		strcpy((char*)getMemAt(0x5D4594, 1191808), "\xe7"); // ç
		strcpy((char*)getMemAt(0x5D4594, 1191810), "@");
		strcpy((char*)getMemAt(0x5D4594, 1191812), "\xe0"); // à
		strcpy((char*)getMemAt(0x5D4594, 1191814), "\xb0"); // °
		strcpy((char*)getMemAt(0x5D4594, 1191816), "#");
		strcpy((char*)getMemAt(0x5D4594, 1191818), "\\");
		strcpy((char*)getMemAt(0x5D4594, 1191820), "|");
		*getMemU16Ptr(0x5D4594, 1191822) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191830), "\xf9"); // ù
		*getMemU16Ptr(0x5D4594, 1191832) = 167;
		*getMemU16Ptr(0x5D4594, 1191834) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191644), "'");
		strcpy((char*)getMemAt(0x5D4594, 1191646), "?");
		*getMemU16Ptr(0x5D4594, 1191648) = 0;
		strcpy((char*)getMemAt(0x5D4594, 1191650), "\xec"); // ì
		strcpy((char*)getMemAt(0x5D4594, 1191652), "^");
		*getMemU16Ptr(0x5D4594, 1191654) = 0;
	LABEL_9:
		strcpy((char*)getMemAt(0x5D4594, 1192088), "<");
		strcpy((char*)getMemAt(0x5D4594, 1192090), ">");
		*getMemU16Ptr(0x5D4594, 1192092) = 0;
		*getMemU8Ptr(0x5D4594, 1193144) = -72;
		break;
	}
}

//----- (0047FCE0) --------------------------------------------------------
int __stdcall sub_47FCE0(_DWORD* a1, int a2) {
	int v2;              // edx
	unsigned __int8* v3; // eax
	int v4;              // eax
	int v5;              // esi

	v2 = 0;
	if (*(int*)&dword_5d4594_3804684 <= 0) {
	LABEL_8:
		v4 = 16 * dword_5d4594_3804684;
		v5 = dword_5d4594_3804684 + 1;
		*getMemU32Ptr(0x5D4594, v4 + 3805516) = a1[3];
		*getMemU32Ptr(0x5D4594, v4 + 3805520) = a1[2];
		*getMemU32Ptr(0x5D4594, v4 + 3805524) = a1[21];
		*getMemU32Ptr(0x5D4594, v4 + 3805528) = a1[26];
		dword_5d4594_3804684 = v5;
	} else {
		v3 = getMemAt(0x5D4594, 3805520);
		while (*((_DWORD*)v3 - 1) != a1[3] || *(_DWORD*)v3 != a1[2] || *((_DWORD*)v3 + 1) != a1[21] ||
			   *((_DWORD*)v3 + 2) != a1[26]) {
			++v2;
			v3 += 16;
			if (v2 >= *(int*)&dword_5d4594_3804684)
				goto LABEL_8;
		}
	}
	return 1;
}

// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (0047FEF0) --------------------------------------------------------
int sub_47FEF0() {
	unsigned __int8* v0; // eax
	int result;          // eax
	unsigned __int8* v2; // eax

	if (dword_5d4594_3799624 == 2) {
		*getMemU32Ptr(0x5D4594, 3807144) = sub_480250;
		*getMemU32Ptr(0x5D4594, 3804676) = sub_480220;
		v0 = getMemAt(0x5D4594, 2598060);
		do {
			*((_WORD*)v0 - 16) = 31744;
			*(_WORD*)v0 = 992;
			*((_WORD*)v0 + 16) = 31;
			*((_WORD*)v0 - 12) = -2048;
			*((_WORD*)v0 + 4) = -1024;
			*((_WORD*)v0 + 20) = -2048;
			*((_WORD*)v0 - 8) = -2048;
			*((_WORD*)v0 + 8) = 2016;
			*((_WORD*)v0 + 24) = 31;
			*((_WORD*)v0 - 4) = 248;
			*((_WORD*)v0 + 12) = 252;
			*((_WORD*)v0 + 28) = 248;
			v0 += 2;
		} while ((int)v0 < (int)getMemAt(0x5D4594, 2598068));
		*getMemU32Ptr(0x5D4594, 2598128) = 0;
		*getMemU32Ptr(0x5D4594, 2598160) = 0;
		*getMemU32Ptr(0x5D4594, 2598132) = 0;
		*getMemU32Ptr(0x5D4594, 2598136) = 0;
		*getMemU32Ptr(0x5D4594, 2598168) = 0;
		*getMemU32Ptr(0x5D4594, 2598144) = 0;
		*getMemU32Ptr(0x5D4594, 2598176) = 0;
		*getMemU32Ptr(0x5D4594, 2598152) = 0;
		*getMemU32Ptr(0x5D4594, 2598184) = 0;
		*getMemU32Ptr(0x5D4594, 2598124) = 7;
		*getMemU32Ptr(0x5D4594, 2598156) = 2;
		*getMemU32Ptr(0x5D4594, 2598164) = 5;
		*getMemU32Ptr(0x5D4594, 2598140) = 8;
		*getMemU32Ptr(0x5D4594, 2598172) = 3;
		*getMemU32Ptr(0x5D4594, 2598148) = 8;
		*getMemU32Ptr(0x5D4594, 2598180) = 3;
		dword_5d4594_3807160 = sub_480EB0;
		result = 1;
	} else if (dword_5d4594_3799624 == 1) {
		*getMemU32Ptr(0x5D4594, 3807144) = sub_4801E0;
		*getMemU32Ptr(0x5D4594, 3804676) = sub_4801B0;
		v2 = getMemAt(0x5D4594, 2598060);
		do {
			*((_WORD*)v2 - 16) = 31744;
			*(_WORD*)v2 = 992;
			*((_WORD*)v2 + 16) = 31;
			*((_WORD*)v2 - 12) = -2048;
			*((_WORD*)v2 + 4) = -2048;
			*((_WORD*)v2 + 20) = -2048;
			*((_WORD*)v2 - 8) = 31744;
			*((_WORD*)v2 + 8) = 992;
			*((_WORD*)v2 + 24) = 31;
			*((_WORD*)v2 - 4) = 248;
			*((_WORD*)v2 + 12) = 248;
			*((_WORD*)v2 + 28) = 248;
			v2 += 2;
		} while ((int)v2 < (int)getMemAt(0x5D4594, 2598068));
		*getMemU32Ptr(0x5D4594, 2598128) = 0;
		*getMemU32Ptr(0x5D4594, 2598156) = 2;
		*getMemU32Ptr(0x5D4594, 2598160) = 0;
		*getMemU32Ptr(0x5D4594, 2598136) = 0;
		*getMemU32Ptr(0x5D4594, 2598168) = 0;
		*getMemU32Ptr(0x5D4594, 2598144) = 0;
		*getMemU32Ptr(0x5D4594, 2598172) = 2;
		*getMemU32Ptr(0x5D4594, 2598176) = 0;
		*getMemU32Ptr(0x5D4594, 2598152) = 0;
		*getMemU32Ptr(0x5D4594, 2598180) = 2;
		*getMemU32Ptr(0x5D4594, 2598184) = 0;
		*getMemU32Ptr(0x5D4594, 2598124) = 7;
		*getMemU32Ptr(0x5D4594, 2598132) = 1;
		*getMemU32Ptr(0x5D4594, 2598164) = 6;
		*getMemU32Ptr(0x5D4594, 2598140) = 7;
		*getMemU32Ptr(0x5D4594, 2598148) = 7;
		dword_5d4594_3807160 = memcpy;
		result = 1;
	} else {
		result = 0;
	}
	return result;
}

//----- (004800F0) --------------------------------------------------------
int sub_4800F0() {
	int result; // eax
	int v2;     // [esp-10h] [ebp-10h]
	int v3;     // [esp-Ch] [ebp-Ch]
	int v4;     // [esp-8h] [ebp-8h]
	int v5;     // [esp-4h] [ebp-4h]

	sub_48A210(sub_47FCE0);
	v5 = (dword_5d4594_3804680 != 0) + 20;
	v4 = dword_5d4594_3804680 != 0 ? 16 : 8;
	v3 = nox_win_height;
	v2 = nox_win_width;
	if (sub_444930(getWindowHandle_sub_401FD0(), v2, v3, v4, v5)) {
		sub_440900();
		sub_47FEF0();
		sub_49F6D0(1);
		sub_437290();
		dword_5d4594_3804680 = dword_5d4594_3801780;
		*getMemU32Ptr(0x5D4594, 3805488) = nox_pitch_3801808 * nox_backbuffer_height;
		*getMemU32Ptr(0x5D4594, 3807124) = dword_5d4594_3801780 == 1;
		sub_430B50(0, 0, 639, 479);
		sub_4453A0_poll_events();
		result = 1;
	} else {
		MessageBoxA(0, (LPCSTR)getMemAt(0x587000, 154896), (LPCSTR)getMemAt(0x587000, 154880), 0);
		result = 0;
	}
	return result;
}

//----- (004801B0) --------------------------------------------------------
char __cdecl sub_4801B0(_BYTE* a2, _BYTE* a3) {
	unsigned int v2; // edx
	unsigned int v3; // eax
	char result;     // al

	HIWORD(v3) = HIWORD(a3);
	*a2 = 8 * *a3;
	LOWORD(v2) = *(_WORD*)a3;
	a2[1] = (v2 >> 2) & 0xF8;
	LOWORD(v3) = *(_WORD*)a3;
	result = (v3 >> 7) & 0xF8;
	a2[2] = result;
	return result;
}
// 4801C2: variable 'v2' is possibly undefined

//----- (004801E0) --------------------------------------------------------
_WORD* __cdecl sub_4801E0(_BYTE* a1, _WORD* a2) {
	_WORD* result; // eax

	result = a2;
	*a2 = (*a1 >> 3) | (4 * (a1[1] & 0xF8 | (32 * (a1[2] & 0xF8))));
	return result;
}

//----- (00480220) --------------------------------------------------------
_BYTE* __cdecl sub_480220(_BYTE* a1, _BYTE* a2) {
	unsigned int v2; // edx
	_BYTE* result;   // eax

	result = a2;
	*a1 = 8 * *a2;
	LOWORD(v2) = *(_WORD*)a2;
	a1[1] = (v2 >> 3) & 0xFC;
	a1[2] = a2[1] & 0xF8;
	return result;
}
// 480232: variable 'v2' is possibly undefined

//----- (00480250) --------------------------------------------------------
_WORD* __cdecl sub_480250(_BYTE* a1, _WORD* a2) {
	_WORD* result; // eax

	result = a2;
	*a2 = (*a1 >> 3) | (8 * (a1[1] & 0xFC | (32 * (a1[2] & 0xF8))));
	return result;
}

unsigned int __cdecl sub_480290(__m64* a1, int a2, int a3, unsigned int* a4, unsigned int* a5) {
	DebugBreak();
	return 0;
}
#if 0
//----- (00480290) --------------------------------------------------------
unsigned int __cdecl sub_480290(__m64 * a1, int a2, int a3, unsigned int* a4, unsigned int* a5)
{
    unsigned int result; // eax
    __m64* v6; // esi
    __m64 v7; // mm3
    __m64 v8; // mm4
    __m64 v9; // mm3
    __m64 v10; // mm5
    __m64 v11; // mm4
    __m64 v12; // mm6
    __m64 v13; // mm3
    __m64 v14; // mm5
    int v15; // ecx
    __m64 v16; // mm6
    __m64 v17; // mm7
    __m64 v18; // mm1
    __m64 v19; // mm2
    __m64 v20; // mm7
    __m64 v21; // mm3
    __m64 v22; // mm6
    __m64 v23; // mm6
    __m64 v24; // mm4
    __m64 v25; // mm5
    int v26; // edi
    __m64 v27; // mm2
    __m64 v28; // mm6
    __m64 v29; // mm3
    __m64 v30; // mm1
    __m64 v31; // mm0
    __m64* v32; // esi
    __m64 v33; // mm1
    __m64 v34; // mm2
    __m64 v35; // mm4
    __m64 v36; // mm0
    __m64 v37; // mm5
    __m64 v38; // mm0
    bool v39; // zf
    __m64 v40; // mm2
    __m64 v41; // mm6
    __m64 v42; // mm1
    __m64 v43; // mm0
    __m64 v44; // mm1
    __m64 v45; // mm2
    __m64 v46; // mm0
    bool v47; // cc
    __m64* v48; // esi
    __m64 v49; // mm3
    __m64 v50; // mm3
    __m64 v51; // mm4
    __m64 v52; // mm3
    __m64 v53; // mm5
    __m64 v54; // mm4
    __m64 v55; // mm5
    __m64 v56; // mm4
    __m64 v57; // mm5
    __m64 v58; // mm2
    __m64 v59; // mm1
    __m64 v60; // mm0
    __m64 v61; // mm2
    __m64 v62; // mm0
    bool v63; // cc
    int v64; // ecx
    __m64 v65; // [esp+Ch] [ebp-18h]
    __m64 v66; // [esp+14h] [ebp-10h]
    __m64 v67; // [esp+1Ch] [ebp-8h]

    result = (unsigned int)a4;
    if (a5[2] | a5[1] | *a5)
    {
        v6 = a1;
        v7 = _mm_cvtsi32_si64(*a5);
        v8 = _mm_cvtsi32_si64(a5[1]);
        v9 = _m_punpcklwd(v7, v7);
        v10 = _mm_cvtsi32_si64(a5[2]);
        v11 = _m_punpcklwd(v8, v8);
        v12 = _mm_cvtsi32_si64(*a4);
        v13 = _m_punpckldq(v9, v9);
        v14 = _m_punpcklwd(v10, v10);
        v15 = a3;
        v16 = _m_punpcklwd(v12, v12);
        v17 = _mm_cvtsi32_si64(a4[1]);
        v18 = _m_punpckldq(v11, v11);
        v65 = _m_psllwi(v13, 2u);
        v19 = _m_punpckldq(v14, v14);
        v20 = _m_punpcklwd(v17, v17);
        v21 = _m_paddw(_m_pmullw(v13, *(__m64*) getMemAt(0x587000, 154916)), _m_punpckldq(v16, v16));
        v22 = _mm_cvtsi32_si64(a4[2]);
        v23 = _m_punpcklwd(v22, v22);
        v66 = _m_psllwi(v18, 2u);
        v67 = _m_psllwi(v19, 2u);
        v24 = _m_paddw(_m_pmullw(v18, *(__m64*) getMemAt(0x587000, 154916)), _m_punpckldq(v20, v20));
        v25 = _m_paddw(_m_pmullw(v19, *(__m64*) getMemAt(0x587000, 154916)), _m_punpckldq(v23, v23));
        v26 = a2 - 8;
        while (1)
        {
            v27 = (__m64)v6->m64_u64;
            v28 = v21;
            v29 = _m_paddw(v21, v65);
            v30 = _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
            v31 = _m_pmullw(
                _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
                _m_psrlwi(v28, 8u));
            v32 = v6 + 1;
            v33 = _m_psrlw(
                _m_pand(_m_pmullw(v30, _m_psrlwi(v24, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
                *(__m64*) getMemAt(0x5D4594, 2598164));
            v34 = _m_pmullw(_m_psllwi(_m_pand(v27, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v25, 8u));
            v35 = _m_paddw(v24, v66);
            v36 = _m_por(_m_psrlw(_m_pand(v31, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)), v33);
            if ((int)v32 >= *(int*)& dword_5d4594_3798844)
                v32 = (__m64*)((char*)v32 + *(_DWORD*)& dword_5d4594_3798796 - *(_DWORD*)& dword_5d4594_3798844);
            v37 = _m_paddw(v25, v67);
            v26 += 8;
            v38 = _m_por(v36, _m_psrlwi(_m_pand(v34, *(__m64*) getMemAt(0x5D4594, 2598100)), 0xBu));
            v39 = v15 == 4;
            v47 = v15 < 4;
            v15 -= 4;
            if (v47)
                break;
            *(__m64*)v26 = v38;
            if (v39)
                return result;
            v40 = (__m64)v32->m64_u64;
            v41 = v29;
            v21 = _m_paddw(v29, v65);
            v42 = _m_psrlw(_m_pand((__m64)v32->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
            v43 = _m_pmullw(
                _m_psrlw(_m_pand((__m64)v32->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
                _m_psrlwi(v41, 8u));
            v6 = v32 + 1;
            v44 = _m_psrlw(
                _m_pand(_m_pmullw(v42, _m_psrlwi(v35, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
                *(__m64*) getMemAt(0x5D4594, 2598164));
            v45 = _m_pmullw(_m_psllwi(_m_pand(v40, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v37, 8u));
            v24 = _m_paddw(v35, v66);
            v46 = _m_por(_m_psrlw(_m_pand(v43, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)), v44);
            if ((int)v6 >= *(int*)& dword_5d4594_3798844)
                v6 = (__m64*)((char*)v6 + *(_DWORD*)& dword_5d4594_3798796 - *(_DWORD*)& dword_5d4594_3798844);
            v25 = _m_paddw(v37, v67);
            v26 += 8;
            v38 = _m_por(v46, _m_psrlwi(_m_pand(v45, *(__m64*) getMemAt(0x5D4594, 2598100)), 0xBu));
            v47 = v15 < 4;
            v15 -= 4;
            if (v47)
                break;
            *(__m64*)v26 = v38;
            if (v47)
                return result;
        }
    }
    else
    {
        v48 = a1;
        v49 = _mm_cvtsi32_si64(*a4);
        v50 = _m_punpcklwd(v49, v49);
        v26 = a2 - 8;
        v51 = _mm_cvtsi32_si64(a4[1]);
        v52 = _m_punpckldq(v50, v50);
        v53 = _mm_cvtsi32_si64(a4[2]);
        v54 = _m_punpcklwd(v51, v51);
        v15 = a3;
        v55 = _m_punpcklwd(v53, v53);
        v56 = _m_punpckldq(v54, v54);
        v57 = _m_punpckldq(v55, v55);
        while (1)
        {
            v58 = (__m64)v48->m64_u64;
            v59 = _m_psrlw(_m_pand((__m64)v48->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
            v60 = _m_pmullw(
                _m_psrlw(_m_pand((__m64)v48->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
                _m_psrlwi(v52, 8u));
            ++v48;
            v61 = _m_pmullw(_m_psllwi(_m_pand(v58, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v57, 8u));
            v62 = _m_por(
                _m_psrlw(_m_pand(v60, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)),
                _m_psrlw(
                    _m_pand(_m_pmullw(v59, _m_psrlwi(v56, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
                    *(__m64*) getMemAt(0x5D4594, 2598164)));
            if ((int)v48 >= *(int*)& dword_5d4594_3798844)
                v48 = (__m64*)((char*)v48 + *(_DWORD*)& dword_5d4594_3798796 - *(_DWORD*)& dword_5d4594_3798844);
            v26 += 8;
            v38 = _m_por(v62, _m_psrlwi(_m_pand(v61, *(__m64*) getMemAt(0x5D4594, 2598100)), 0xBu));
            v63 = v15 < 4;
            v15 -= 4;
            if (v63)
                break;
            *(__m64*)v26 = v38;
            if (v63)
                return result;
        }
    }
    result = _mm_cvtsi64_si32(v38);
    *(_WORD*)v26 = result;
    v64 = v15 + 3;
    if (v64)
    {
        result >>= 16;
        *(_WORD*)(v26 + 2) = result;
        if (v64 != 1)
        {
            result = _mm_cvtsi64_si32(_m_psrlqi(v38, 0x20u));
            *(_WORD*)(v26 + 4) = result;
        }
    }
    return result;
}
#endif

__int16 __cdecl sub_4805A0(int a1, __m64* a2, int a3, unsigned int* a4, unsigned int* a5) {
	DebugBreak();
	return 0;
}
#if 0
//----- (004805A0) --------------------------------------------------------
__int16 __cdecl sub_4805A0(int a1, __m64 * a2, int a3, unsigned int* a4, unsigned int* a5)
{
    __int16 result; // ax
    __m64* v6; // esi
    __m64 v7; // mm3
    __m64 v8; // mm4
    __m64 v9; // mm3
    __m64 v10; // mm5
    __m64 v11; // mm4
    __m64 v12; // mm6
    __m64 v13; // mm3
    __m64 v14; // mm5
    int v15; // ecx
    __m64 v16; // mm6
    __m64 v17; // mm7
    __m64 v18; // mm1
    __m64 v19; // mm2
    __m64 v20; // mm7
    __m64 v21; // mm3
    __m64 v22; // mm6
    __m64 v23; // mm6
    __m64 v24; // mm4
    __m64 v25; // mm5
    __m64* v26; // edi
    __m64 v27; // mm2
    __m64 v28; // mm6
    __m64 v29; // mm1
    __m64 v30; // mm0
    __m64 v31; // mm1
    __m64 v32; // mm2
    __m64 v33; // mm0
    bool v34; // cc
    __int16* v35; // esi
    __m64 v36; // [esp+Ch] [ebp-20h]
    __m64 v37; // [esp+14h] [ebp-18h]
    __m64 v38; // [esp+1Ch] [ebp-10h]
    __m64 v39; // [esp+24h] [ebp-8h]

    result = (__int16)a4;
    v6 = a2;
    v7 = _mm_cvtsi32_si64(*a5);
    v8 = _mm_cvtsi32_si64(a5[1]);
    v9 = _m_punpcklwd(v7, v7);
    v10 = _mm_cvtsi32_si64(a5[2]);
    v11 = _m_punpcklwd(v8, v8);
    v12 = _mm_cvtsi32_si64(*a4);
    v13 = _m_punpckldq(v9, v9);
    v14 = _m_punpcklwd(v10, v10);
    v15 = a3;
    v16 = _m_punpcklwd(v12, v12);
    v17 = _mm_cvtsi32_si64(a4[1]);
    v18 = _m_punpckldq(v11, v11);
    v36 = _m_psllwi(v13, 2u);
    v19 = _m_punpckldq(v14, v14);
    v20 = _m_punpcklwd(v17, v17);
    v21 = _m_paddw(_m_pmullw(v13, *(__m64*) getMemAt(0x587000, 154924)), _m_punpckldq(v16, v16));
    v22 = _mm_cvtsi32_si64(a4[2]);
    v23 = _m_punpcklwd(v22, v22);
    v37 = _m_psllwi(v18, 2u);
    v38 = _m_psllwi(v19, 2u);
    v24 = _m_paddw(_m_pmullw(v18, *(__m64*) getMemAt(0x587000, 154924)), _m_punpckldq(v20, v20));
    v25 = _m_paddw(_m_pmullw(v19, *(__m64*) getMemAt(0x587000, 154924)), _m_punpckldq(v23, v23));
    v26 = (__m64*)(a1 - 8);
    while (1)
    {
        v27 = (__m64)v6->m64_u64;
        v28 = v21;
        v21 = _m_paddw(v21, v36);
        v29 = _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
        v30 = _m_pmullw(
            _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
            _m_psrlwi(v28, 8u));
        ++v6;
        v31 = _m_psrlw(
            _m_pand(_m_pmullw(v29, _m_psrlwi(v24, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
            *(__m64*) getMemAt(0x5D4594, 2598164));
        v24 = _m_paddw(v24, v37);
        v32 = _m_pand(
            _m_pmullw(_m_psllwi(_m_pand(v27, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v25, 8u)),
            *(__m64*) getMemAt(0x5D4594, 2598100));
        v25 = _m_paddw(v25, v38);
        ++v26;
        v33 = _m_por(
            _m_por(_m_psrlw(_m_pand(v30, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)), v31),
            _m_psrlwi(v32, 0xBu));
        if (v15 < 4)
            break;
        v26->m64_u64 = (unsigned __int64)v33;
        v34 = v15 <= 4;
        v15 -= 4;
        if (v34)
            goto LABEL_7;
    }
    v39 = v33;
    v35 = (__int16*)& v39;
    do
    {
        result = *v35;
        ++v35;
        LOWORD(v26->m64_i32[0]) = result;
        v26 = (__m64*)((char*)v26 + 2);
        v34 = v15-- <= 1;
    } while (!v34);
LABEL_7:
    _m_femms();
    return result;
}
#endif

__int16 __cdecl sub_480700(int a1, __m64* a2, int a3, unsigned int* a4, unsigned int* a5) {
	DebugBreak();
	return 0;
}

#if 0
//----- (00480700) --------------------------------------------------------
__int16 __cdecl sub_480700(int a1, __m64 * a2, int a3, unsigned int* a4, unsigned int* a5)
{
    __int16 result; // ax
    __m64* v6; // esi
    __m64 v7; // mm3
    __m64 v8; // mm4
    __m64 v9; // mm3
    __m64 v10; // mm5
    __m64 v11; // mm4
    __m64 v12; // mm6
    __m64 v13; // mm3
    __m64 v14; // mm5
    int v15; // ecx
    __m64 v16; // mm6
    __m64 v17; // mm7
    __m64 v18; // mm1
    __m64 v19; // mm2
    __m64 v20; // mm7
    __m64 v21; // mm3
    __m64 v22; // mm6
    __m64 v23; // mm6
    __m64 v24; // mm4
    __m64 v25; // mm5
    __m64* v26; // edi
    __m64 v27; // mm2
    __m64 v28; // mm6
    __m64 v29; // mm1
    __m64 v30; // mm0
    __m64 v31; // mm1
    __m64 v32; // mm2
    __m64 v33; // mm0
    bool v34; // cc
    __int16* v35; // esi
    __m64 v36; // [esp+Ch] [ebp-20h]
    __m64 v37; // [esp+14h] [ebp-18h]
    __m64 v38; // [esp+1Ch] [ebp-10h]
    __m64 v39; // [esp+24h] [ebp-8h]

    result = (__int16)a4;
    v6 = a2;
    v7 = _mm_cvtsi32_si64(*a5);
    v8 = _mm_cvtsi32_si64(a5[1]);
    v9 = _m_punpcklwd(v7, v7);
    v10 = _mm_cvtsi32_si64(a5[2]);
    v11 = _m_punpcklwd(v8, v8);
    v12 = _mm_cvtsi32_si64(*a4);
    v13 = _m_punpckldq(v9, v9);
    v14 = _m_punpcklwd(v10, v10);
    v15 = a3;
    v16 = _m_punpcklwd(v12, v12);
    v17 = _mm_cvtsi32_si64(a4[1]);
    v18 = _m_punpckldq(v11, v11);
    v36 = _m_psllwi(v13, 2u);
    v19 = _m_punpckldq(v14, v14);
    v20 = _m_punpcklwd(v17, v17);
    v21 = _m_paddw(_m_pmullw(v13, *(__m64*) getMemAt(0x587000, 154932)), _m_punpckldq(v16, v16));
    v22 = _mm_cvtsi32_si64(a4[2]);
    v23 = _m_punpcklwd(v22, v22);
    v37 = _m_psllwi(v18, 2u);
    v38 = _m_psllwi(v19, 2u);
    v24 = _m_paddw(_m_pmullw(v18, *(__m64*) getMemAt(0x587000, 154932)), _m_punpckldq(v20, v20));
    v25 = _m_paddw(_m_pmullw(v19, *(__m64*) getMemAt(0x587000, 154932)), _m_punpckldq(v23, v23));
    v26 = (__m64*)(a1 - 8);
    while (1)
    {
        v27 = (__m64)v6->m64_u64;
        v28 = v21;
        v21 = _m_paddw(v21, v36);
        v29 = _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 3804404)), *(__m64*) getMemAt(0x5D4594, 3804452));
        v30 = _m_pmullw(
            _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 3804396)), *(__m64*) getMemAt(0x5D4594, 3804444)),
            _m_psrlwi(v28, 8u));
        ++v6;
        v31 = _m_psrlw(
            _m_pand(_m_pmullw(v29, _m_psrlwi(v24, 8u)), *(__m64*) getMemAt(0x5D4594, 3804428)),
            *(__m64*) getMemAt(0x5D4594, 3804500));
        v24 = _m_paddw(v24, v37);
        v32 = _m_pand(
            _m_pmullw(
                _m_psllw(_m_pand(v27, *(__m64*) getMemAt(0x5D4594, 3804412)), *(__m64*) getMemAt(0x5D4594, 3804460)),
                _m_psrlwi(v25, 8u)),
            *(__m64*) getMemAt(0x5D4594, 3804436));
        v25 = _m_paddw(v25, v38);
        ++v26;
        v33 = _m_por(
            _m_por(_m_psrlw(_m_pand(v30, *(__m64*) getMemAt(0x5D4594, 3804420)), *(__m64*) getMemAt(0x5D4594, 3804492)), v31),
            _m_psrlw(v32, *(__m64*) getMemAt(0x5D4594, 3804508)));
        if (v15 < 4)
            break;
        v26->m64_u64 = (unsigned __int64)v33;
        v34 = v15 <= 4;
        v15 -= 4;
        if (v34)
            goto LABEL_7;
    }
    v39 = v33;
    v35 = (__int16*)& v39;
    do
    {
        result = *v35;
        ++v35;
        LOWORD(v26->m64_i32[0]) = result;
        v26 = (__m64*)((char*)v26 + 2);
        v34 = v15-- <= 1;
    } while (!v34);
LABEL_7:
    _m_femms();
    return result;
}
#endif

//----- (00480860) --------------------------------------------------------
void __cdecl sub_480860(WORD* a1, WORD* a2, int a3, int* a4, int* a5) {
	WORD* dword_975384 = dword_5d4594_3804656;
	WORD* dword_97538C = dword_5d4594_3804664;
	WORD* dword_975394 = dword_5d4594_3804672;
	WORD dword_975260 = *getMemU16Ptr(0x5D4594, 3804364);
	WORD dword_975264 = *getMemU16Ptr(0x5D4594, 3804368);
	WORD dword_975268 = *getMemU16Ptr(0x5D4594, 3804372);
	WORD dword_97526C = *getMemU16Ptr(0x5D4594, 3804376);
	WORD dword_975270 = *getMemU16Ptr(0x5D4594, 3804380);
	WORD dword_975274 = *getMemU16Ptr(0x5D4594, 3804384);

	while (a3 > 0) {
		*a1 = (dword_97538C[((a4[2] * ((*a2 & dword_975268) << dword_975274)) >> 16) & 0xFF] |
			   dword_975384[((a4[1] * ((*a2 & dword_975264) >> dword_975270)) >> 16) & 0xFF] |
			   dword_975394[((a4[0] * ((*a2 & dword_975260) >> dword_97526C)) >> 16) & 0xFF]);
		a4[0] += a5[0];
		a4[1] += a5[1];
		a4[2] += a5[2];
		++a1;
		++a2;
		--a3;
	}
}

//----- (00480950) --------------------------------------------------------
int __cdecl sub_480950(int* a1, int* a2, int a3, int a4, int a5) {
	int v5;          // ecx
	int result;      // eax
	int v7;          // edx
	unsigned int v8; // eax
	int v9;          // edi
	int v10;         // ecx
	int v11;         // edx
	int* v12;        // eax
	int v13;         // edi
	int v14;         // ebx
	int v15;         // edx
	int v16;         // ebp
	int v17;         // edi
	__m64* v18;      // ebx
	int v19;         // eax
	int v20;         // eax
	int v21[3];      // [esp+10h] [ebp-18h]
	int v22[3];      // [esp+1Ch] [ebp-Ch]
	__m64* v23;      // [esp+2Ch] [ebp+4h]

	v5 = *a1;
	result = a1[1] - dword_5d4594_3798824;
	v7 = *a1 - dword_5d4594_3798820;
	if (v7 >= 0 && result >= 0 && v7 < *(int*)&dword_5d4594_3798800 && result < *(int*)&dword_5d4594_3798808) {
		v8 = dword_5d4594_3798804 * (dword_5d4594_3798840 + result) + dword_5d4594_3798796 +
			 2 * (dword_5d4594_3798836 + v7);
		if (v8 >= *(int*)&dword_5d4594_3798844)
			v8 += dword_5d4594_3798796 - dword_5d4594_3798844;
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_12)) {
			if (2 * a4 + v8 < *(int*)&dword_5d4594_3798844) {
				result = (*(int(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3807160)(a5, v8, 2 * a4);
			} else {
				v9 = dword_5d4594_3798844 - v8;
				(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3807160)(a5, v8, dword_5d4594_3798844 - v8);
				result = (*(int(__cdecl**)(_DWORD, _DWORD, _DWORD)) &
						  dword_5d4594_3807160)(a5 + v9, dword_5d4594_3798796, 2 * a4 - v9);
			}
		} else {
			v23 = (__m64*)v8;
			v10 = v5 - 23 * *a2 - dword_5d4594_2650676;
			v11 = 12 * a3 + 280 * *a2;
			v12 = (int*)getMemAt(0x5D4594, v11 + 2598288);
			v13 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v11 + 2598568) - *(int*)getMemAt(0x5D4594, v11 + 2598288)) >> 8) + 2615304);
			v22[0] =
				*getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v11 + 2598568) - *(int*)getMemAt(0x5D4594, v11 + 2598288)) >>
											8) +
									   2615304);
			v14 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v11 + 2598572) - *(int*)getMemAt(0x5D4594, v11 + 2598292)) >> 8) + 2615304);
			v22[1] =
				*getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v11 + 2598572) - *(int*)getMemAt(0x5D4594, v11 + 2598292)) >>
											8) +
									   2615304);
			v15 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v11 + 2598576) - *(int*)getMemAt(0x5D4594, v11 + 2598296)) >> 8) + 2615304);
			v22[2] = v15;
			v21[0] = *v12;
			v16 = v12[1];
			v21[1] = v12[1];
			v21[2] = v12[2];
			if (v10 <= 0) {
				v17 = 23;
			} else {
				v21[2] += v10 * v15;
				v21[0] += v10 * v13;
				v21[1] = v10 * v14 + v16;
				v17 = 23 - v10;
			}
			if (v17 > a4)
				v17 = a4;
			v18 = v23;
			while (1) {
				sub_480290(v18, a5, v17, (unsigned int*)v21, (unsigned int*)v22);
				v18 = (__m64*)((char*)v18 + 2 * v17);
				a5 += 2 * v17;
				if ((unsigned int)v18 >= *(int*)&dword_5d4594_3798844)
					v18 =
						(__m64*)((char*)v18 - 2 * ((*(int*)&dword_5d4594_3798844 - *(int*)&dword_5d4594_3798796) >> 1));
				result = a4 - v17;
				a4 -= v17;
				if (a4 <= 0)
					break;
				v17 = 23;
				if (result < 23)
					v17 = result;
				v19 = *a2 + 1;
				*a2 = v19;
				v20 = 12 * a3 + 280 * v19;
				v21[0] = *getMemU32Ptr(0x5D4594, v20 + 2598288);
				v21[1] = *getMemU32Ptr(0x5D4594, v20 + 2598292);
				v21[2] = *getMemU32Ptr(0x5D4594, v20 + 2598296);
				v22[0] = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v20 + 2598568) - *(int*)getMemAt(0x5D4594, v20 + 2598288)) >> 8) +
							  2615304);
				v22[1] = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v20 + 2598572) - *(int*)getMemAt(0x5D4594, v20 + 2598292)) >> 8) +
							  2615304);
				v22[2] = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v20 + 2598576) - *(int*)getMemAt(0x5D4594, v20 + 2598296)) >> 8) +
							  2615304);
			}
		}
	}
	return result;
}

//----- (00480BE0) --------------------------------------------------------
void __cdecl sub_480BE0(_DWORD* a1, int* a2, int a3, int a4, int a5) {
	_BYTE* v6; // ebp
	int v7;    // edi
	int v9;    // ecx
	int v10;   // eax
	int v11;   // esi
	int v12;   // edi
	int v13;   // ebx
	int v16;   // ecx
	int v17;   // edi
	int v18;   // eax
	int v21;   // [esp+14h] [ebp-10h]
	int v22;   // [esp+18h] [ebp-Ch]
	int v23;   // [esp+1Ch] [ebp-8h]
	int v24;   // [esp+20h] [ebp-4h]
	int v25;   // [esp+28h] [ebp+4h]
	int v26;   // [esp+30h] [ebp+Ch]
	// void(__cdecl * maprgb)(const BYTE*, WORD*);
	BYTE* x1 = *(_BYTE**)&dword_5d4594_3798844;
	BYTE* x2 = *(_BYTE**)&dword_5d4594_3798796;

	v6 = (_BYTE*)(dword_5d4594_3798804 * (dword_5d4594_3798840 + a1[1] - dword_5d4594_3798824) + dword_5d4594_3798796 +
				  2 * (dword_5d4594_3798836 + *a1 - dword_5d4594_3798820));
	if (v6 >= x1)
		v6 += x2 - x1;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_12)) {
		if ((unsigned int)&v6[2 * a4] < x1) {
			(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3807160)(a5, v6, 2 * a4);
		} else {
			v7 = x1 - v6;
			(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3807160)(a5, v6, x1 - v6);
			(*(int(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3807160)(a5 + v7, dword_5d4594_3798796,
																			   2 * a4 - v7);
		}
	} else {
		v9 = *a1 - 23 * *a2 - dword_5d4594_2650676;
		v21 = 12 * a3;
		v10 = 12 * a3 + 280 * *a2;
		v11 = *getMemU32Ptr(0x5D4594, v10 + 2598288);
		v12 = *getMemU32Ptr(0x5D4594, v10 + 2598292);
		v13 = *getMemU32Ptr(0x5D4594, v10 + 2598296);
		v22 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v10 + 2598568) - v11) >> 8) + 2615304);
		v23 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v10 + 2598572) - v12) >> 8) + 2615304);
		v24 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v10 + 2598576) - v13) >> 8) + 2615304);
		if (v9 <= 0) {
			v25 = 23;
		} else {
			v12 += v9 * *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v10 + 2598572) - v12) >> 8) + 2615304);
			v11 += v9 * v22;
			v13 += v9 * v24;
			v25 = 23 - v9;
		}
		if (v25 > a4)
			v25 = a4;
		while (1) {
			for (v26 = v25; v26; --v26) {
				BYTE r, g, b;
				WORD x = *(_WORD*)v6;

#if 1
				r = (v13 * (x & 0x1Fu)) >> 13;
				g = (v12 * ((x >> 2) & 0xF8)) >> 16;
				b = (v11 * ((x >> 7) & 0xF8)) >> 16;
				*(WORD*)a5 = (r >> 3) | ((g & 0xF8) << 2) | ((b & 0xF8) << 7);
#else
				*(WORD*)a5 = x;
#endif
				// maprgb = *(void **)getMemAt(0x5D4594, 3807144);
				// maprgb(tmp, v20);

				v6 += 2;
				a5 += 2;
				if (v6 >= x1)
					v6 = x2;
				v11 += v22;
				v12 += v23;
				v13 += v24;
			}
			v16 = a4 - v25;
			a4 = v16;
			if (v16 <= 0)
				break;
			v25 = 23;
			if (v16 < 23)
				v25 = v16;
			v17 = *a2 + 1;
			*a2 = v17;
			v18 = v21 + 280 * v17;
			v11 = *getMemU32Ptr(0x5D4594, v18 + 2598288);
			v12 = *getMemU32Ptr(0x5D4594, v18 + 2598292);
			v13 = *getMemU32Ptr(0x5D4594, v18 + 2598296);
			v22 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v18 + 2598568) - v11) >> 8) + 2615304);
			v23 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v18 + 2598572) - v12) >> 8) + 2615304);
			v24 = *getMemU32Ptr(0x5D4594, 4 * ((*(int*)getMemAt(0x5D4594, v18 + 2598576) - v13) >> 8) + 2615304);
		}
	}
}

//----- (00480EB0) --------------------------------------------------------
_WORD* __cdecl sub_480EB0(_WORD* a1, __int16* a2, int a3) {
	__int16* v3; // esi
	_WORD* v4;   // edi
	int v5;      // ecx
	__int16 v6;  // ax

	v3 = a2;
	v4 = a1;
	v5 = a3;
	do {
		v6 = *v3;
		++v3;
		*v4 = v6 & 0x1F | (2 * v6) & 0xFFC0;
		++v4;
	} while (v5-- > 1);
	return v4;
}

//----- (00480EF0) --------------------------------------------------------
int* __cdecl sub_480EF0(int a1, int a2, int a3, int* a4, int* a5, int a6, int a7, int a8, int a9, int a10) {
	int* result;                                        // eax
	int v10;                                            // ebx
	char v11;                                           // cl
	int v12;                                            // esi
	int v13;                                            // edx
	int* v14;                                           // ebp
	int v15;                                            // edi
	char* v16;                                          // ebp
	int v17;                                            // ecx
	int v18;                                            // esi
	int v19;                                            // esi
	int v20;                                            // edx
	int v21;                                            // edx
	int v22;                                            // ecx
	int v23;                                            // edx
	int v24;                                            // eax
	int v25;                                            // ecx
	int v26;                                            // esi
	int v27;                                            // ecx
	int i;                                              // esi
	char v29;                                           // al
	unsigned int v30;                                   // ecx
	const void* v31;                                    // esi
	int v32;                                            // edi
	int j;                                              // esi
	char v34;                                           // al
	char v35;                                           // dl
	int v36;                                            // ecx
	int v37;                                            // esi
	unsigned __int8 v38;                                // dl
	char v39;                                           // al
	int v40;                                            // [esp+10h] [ebp-48h]
	int v41;                                            // [esp+14h] [ebp-44h]
	void(__cdecl * v42)(char*, char*, int, int*, int*); // [esp+18h] [ebp-40h]
	int v43;                                            // [esp+1Ch] [ebp-3Ch]
	int v44;                                            // [esp+20h] [ebp-38h]
	int2 v45;                                           // [esp+24h] [ebp-34h]
	int2 v46;                                           // [esp+2Ch] [ebp-2Ch]
	int v47;                                            // [esp+34h] [ebp-24h]
	int v48;                                            // [esp+38h] [ebp-20h]
	int v49;                                            // [esp+3Ch] [ebp-1Ch]
	int v50[3];                                         // [esp+40h] [ebp-18h]
	int v51[3];                                         // [esp+4Ch] [ebp-Ch]
	char* v52;                                          // [esp+60h] [ebp+8h]
	int v53;                                            // [esp+64h] [ebp+Ch]
	int v54;                                            // [esp+64h] [ebp+Ch]
	int v55;                                            // [esp+70h] [ebp+18h]
	int v56;                                            // [esp+74h] [ebp+1Ch]
	unsigned __int8 v57;                                // [esp+7Ch] [ebp+24h]
	unsigned __int8 v58;                                // [esp+7Ch] [ebp+24h]
	unsigned __int8 v59;                                // [esp+7Ch] [ebp+24h]
	unsigned __int8 v60;                                // [esp+7Ch] [ebp+24h]
	unsigned __int8 v61;                                // [esp+7Ch] [ebp+24h]

	result = (int*)a1;
	v10 = 0;
	v44 = 0;
	if (!result) {
		return 0;
	}
	v11 = *(_BYTE*)(a1 + 10);
	v45.field_4 = 0;
	v45.field_0 = 0;
	v46.field_4 = 0;
	v46.field_0 = 0;
	if ((v11 & 0x3F) != 3) {
		return result;
	}
	v42 = sub_480700;
	if (!dword_5d4594_3801804)
		v42 = sub_480860;
	result = (int*)sub_42FB30(a1);
	if (!result) {
		return result;
	}
	v12 = *result;
	v13 = result[1] - a9;
	v43 = *result;
	v40 = *result;
	v41 = v13;
	if (v13 <= 0) {
		return result;
	}
	v14 = result + 3;
	result = (int*)(result[2] + a2);
	v15 = *v14;
	v16 = (char*)v14 + 5;
	v17 = v15 + a3;
	v53 = v15 + a3;
	if (!((int)result <= *(int*)&dword_5d4594_3807116 && v17 <= *(int*)&dword_5d4594_3807152)) {
		return result;
	}
	if ((int)result < *(int*)&dword_5d4594_3807140) {
		if ((int)result + v12 < *(int*)&dword_5d4594_3807140)
			return result;
		v10 = *(int*)&dword_5d4594_3807140 - (int)result;
		v40 = v12 - (*(int*)&dword_5d4594_3807140 - (int)result);
		result = *(int**)&dword_5d4594_3807140;
	}
	if ((int)result + v40 > *(int*)&dword_5d4594_3807116)
		v40 = *(int*)&dword_5d4594_3807116 - (int)result;
	if (v17 < *(int*)&dword_5d4594_3807136) {
		if (v13 + v17 < *(int*)&dword_5d4594_3807136)
			return result;
		v18 = *(int*)&dword_5d4594_3807136 - v17;
		v17 = *(int*)&dword_5d4594_3807136;
		v13 -= v18;
		v53 = *(int*)&dword_5d4594_3807136;
		v41 = v13;
		v44 = v18;
	}
	if (v13 + v17 > *(int*)&dword_5d4594_3807152) {
		v13 = *(int*)&dword_5d4594_3807152 - v17;
		v41 = *(int*)&dword_5d4594_3807152 - v17;
	}
	if (!(v40 > 0 && v13 > 0)) {
		return result;
	}
	v19 = a6;
	if (a6 < v17)
		v19 = v17;
	if (v13 + v17 > v19)
		v41 = v19 - v17;
	if (a7 <= (int)result + v10) {
		v20 = 0;
	} else {
		v20 = a7 - v10 - (int)result;
		v10 = a7 - (int)result;
		v40 -= v20;
	}
	if (a8 < (int)result + v40 + v10)
		v40 = a8 - v10 - (int)result;
	if (v40 <= 0) {
		return result;
	}
	v21 = (int)nox_pixbuffer_rows_3798784[v17] + 2 * ((int)result + v20);
	v22 = a4[1];
	v52 = (char*)v21;
	v23 = *a4;
	v49 = a4[2] << 8;
	v23 <<= 8;
	v24 = (*a5 << 8) - v23;
	v47 = v23;
	v48 = v22 << 8;
	v25 = a5[1] << 8;
	v26 = a5[2] << 8;
	v50[0] = v24 / v43;
	v50[1] = (v25 - v48) / v43;
	v50[2] = (v26 - v49) / v43;
	if (v44 > 0) {
		v27 = v44;
		do {
			for (i = v43; i > 0; i -= v57) {
				v29 = *v16;
				v57 = v16[1];
				v16 += 2;
				LOBYTE(a1) = v29;
				if (v29 == 2)
					v16 += 2 * v57;
			}
			--v27;
		} while (v27);
	}
	v46.field_4 = v53;
	sub_473970(&v46, &v45);
	v30 = 0;
	v31 = 0;
	result = (int*)(v41 - 1);
	if (!v41) {
		return result;
	}
	v56 = v41;
	while (1) {
		v32 = 0;
		v54 = 0;
		v55 = 0;
		if (nox_client_highResFrontWalls_80820 || !(v45.field_4 & 1)) {
			if (v10 <= 0) {
				v35 = a1;
			} else {
				do {
					v35 = *v16;
					v59 = v16[1];
					v16 += 2;
					LOBYTE(a1) = v35;
					if (v35 == 2)
						v16 += 2 * v59;
					v32 += v59;
				} while (v32 < v10);
			}
			if (v32 <= v10) {
				v36 = v40;
			} else {
				v36 = v40;
				v37 = v40;
				if (v32 - v10 <= v40)
					v37 = v32 - v10;
				if (v35 == 2) {
					v51[0] = v47 + v10 * v50[0];
					v51[1] = v48 + v10 * v50[1];
					v51[2] = v49 + v10 * v50[2];
					v42(v52, &v16[-2 * (v32 - v10)], v37, v51, v50);
					v36 = v40;
					v54 = 2 * v37;
				}
				v55 = 0;
			}
			if (v32 < v36 + v10) {
				do {
					v38 = v16[1];
					LOBYTE(a1) = *v16;
					v16 += 2;
					v60 = v38;
					if ((_BYTE)a1 == 2) {
						if (v38 > v10 + v36 - v32) {
							v55 = v32 + v38 - v36 - v10;
							v60 = -(char)(v32 + -(char)v36 - v10);
						}
						v51[0] = v47 + v50[0] * v32;
						v51[2] = v49 + v50[2] * v32;
						v51[1] = v48 + v50[1] * v32;
						v42(&v52[2 * (v32 - v10)], v16, v60, v51, v50);
						v36 = v40;
						v16 += 2 * v60;
					}
					v32 += v60;
					v54 += 2 * v60;
				} while (v32 < v36 + v10);
				if (v55) {
					if ((_BYTE)a1 == 2)
						v16 += 2 * v55;
					v32 += v55;
				}
			}
			for (; v32 < v43; v32 += v61) {
				v39 = *v16;
				v61 = v16[1];
				v16 += 2;
				LOBYTE(a1) = v39;
				if (v39 == 2)
					v16 += 2 * v61;
			}
		} else {
			if (v31 && v30)
				memcpy(v52, v31, v30);
			for (j = v43; j > 0; j -= v58) {
				v34 = *v16;
				v58 = v16[1];
				v16 += 2;
				LOBYTE(a1) = v34;
				if (v34 == 2)
					v16 += 2 * v58;
			}
		}
		v31 = v52;
		v52 += nox_pitch_3801808;
		++v45.field_4;
		result = (int*)--v56;
		if (!v56)
			break;
		v30 = v54;
	}
	return result;
}

//----- (00481410) --------------------------------------------------------
void sub_481410() { dword_587000_154948 = -1; }

//----- (00481420) --------------------------------------------------------
int sub_481420() {
	int result; // eax

	result = nox_client_texturedFloors_154956;
	if (nox_client_texturedFloors_154956) {
		func_587000_154940 = sub_4815E0;
		func_587000_154944 = sub_481900;
	} else {
		func_587000_154940 = sub_481770;
		func_587000_154944 = nullsub_8;
	}
	dword_5d4594_1193188 = 1;
	return result;
}
// 481BE0: using guessed type void nullsub_8();

//----- (004814F0) --------------------------------------------------------
int __cdecl sub_4814F0(int2* a1) {
	int v1;              // eax
	int v2;              // ecx
	int v3;              // edx
	int v4;              // esi
	int v5;              // edi
	unsigned __int8* v6; // eax
	int result;          // eax
	int v8;              // [esp+10h] [ebp-Ch]
	int v9;              // [esp+14h] [ebp-8h]
	int v10;             // [esp+18h] [ebp-4h]

	v1 = 12 * (a1->field_4 + 45 * a1->field_0);
	v2 = *getMemU32Ptr(0x5D4594, v1 + 2618924) >> 8;
	v3 = *getMemU32Ptr(0x5D4594, v1 + 2618928) >> 8;
	v8 = *getMemU32Ptr(0x5D4594, 4 * (((*(int*)getMemAt(0x5D4594, v1 + 2618936) >> 8) - v2) >> 8) + 2615304);
	v4 = *getMemU32Ptr(0x5D4594, v1 + 2618932) >> 8;
	v9 = *getMemU32Ptr(0x5D4594, 4 * (((*(int*)getMemAt(0x5D4594, v1 + 2618940) >> 8) - v3) >> 8) + 2615304);
	v10 = *getMemU32Ptr(0x5D4594, 4 * (((*(int*)getMemAt(0x5D4594, v1 + 2618944) >> 8) - v4) >> 8) + 2615304);
	v5 = 0;
	do {
		v6 = getMemAt(0x5D4594, 280 * a1->field_0 + 2598288 + v5);
		v5 += 12;
		*(_DWORD*)v6 = v2;
		*((_DWORD*)v6 + 1) = v3;
		v3 += v9;
		*((_DWORD*)v6 + 2) = v4;
		v2 += v8;
		v4 += v10;
	} while (v5 < 276);
	result = 7 * a1->field_0;
	*getMemU32Ptr(0x5D4594, 280 * a1->field_0 + 2598284) = a1->field_4;
	return result;
}

//----- (004815E0) --------------------------------------------------------
char __cdecl sub_4815E0(_DWORD* a1, int a2) {
	unsigned int v2; // ebx
	int v3;          // eax
	char* v4;        // esi
	unsigned int v5; // edi
	int v6;          // eax
	int v7;          // edx
	unsigned int v8; // ebp
	signed int v9;   // eax
	char* v10;       // edi
	char* v11;       // esi
	char v12;        // cl
	char* v14;       // [esp+10h] [ebp+4h]
	int i;           // [esp+14h] [ebp+8h]

	v2 = dword_5d4594_3798804 * (dword_5d4594_3798840 + a1[1] - dword_5d4594_3798824) + dword_5d4594_3798796 +
		 ((dword_5d4594_3798836 + *a1 - dword_5d4594_3798820) << getMemByte(0x5D4594, 3807124));
	if (v2 >= *(int*)&dword_5d4594_3798844)
		v2 += dword_5d4594_3798796 - dword_5d4594_3798844;
	v3 = sub_42FB30(a2);
	v4 = (char*)v3;
	v14 = (char*)v3;
	if (v3) {
		v5 = dword_5d4594_3798844;
		if (v2 + *(int*)getMemAt(0x5D4594, 3799236) >= *(int*)&dword_5d4594_3798844) {
			v6 = 0;
			for (i = 0;; v6 = i) {
				v7 = *getMemU32Ptr(0x5D4594, v6 + 3799052) << getMemByte(0x5D4594, 3807124);
				v8 = *getMemU32Ptr(0x5D4594, v6 + 3799244) << getMemByte(0x5D4594, 3807124);
				if (v2 + v7 + v8 < v5) {
					memcpy((void*)(v7 + v2), v4, 4 * (v8 >> 2));
					v11 = &v4[4 * (v8 >> 2)];
					v10 = (char*)(v7 + v2 + 4 * (v8 >> 2));
					v12 = v8;
				} else {
					v9 = v5 - v7 - v2;
					if (v9 > 0) {
						memcpy((void*)(v7 + v2), v4, v9);
						memcpy(*(void**)&dword_5d4594_3798796, &v14[v9], v8 - v9);
						v5 = dword_5d4594_3798844;
						v2 += dword_5d4594_3798796 - dword_5d4594_3798844;
						goto LABEL_13;
					}
					v2 += dword_5d4594_3798796 - v5;
					memcpy((void*)(v7 + v2), v4, 4 * (v8 >> 2));
					v11 = &v4[4 * (v8 >> 2)];
					v10 = (char*)(v7 + v2 + 4 * (v8 >> 2));
					v12 = v8;
				}
				memcpy(v10, v11, v12 & 3);
				v5 = dword_5d4594_3798844;
			LABEL_13:
				v2 += dword_5d4594_3798804;
				v14 += v8;
				LOBYTE(v3) = i + 4;
				i += 4;
				if (i >= 184)
					return v3;
				v4 = v14;
			}
		} else {
			if (dword_5d4594_3799624)
				LOBYTE(v3) = sub_4831C0(v3, v2);
			else
				LOBYTE(v3) = sub_482910(v3, v2);
		}
	}
	return v3;
}

//----- (00481770) --------------------------------------------------------
char* __cdecl sub_481770(_DWORD* a1, int a2, unsigned __int16 a3) {
	int v3;             // ebp
	unsigned __int8 v4; // cl
	unsigned int v5;    // edx
	unsigned int v6;    // esi
	int v7;             // ebx
	int v8;             // eax
	int v9;             // edi
	int v10;            // ebx
	char* result;       // eax
	int v12;            // [esp+Ch] [ebp+Ch]

	if (!nox_client_texturedFloors_154956 && (getMemByte(0x5D4594, 60 * a3 + 2682246) & 1) == 1)
		dword_5d4594_1193156 = 1;
	v3 = *getMemU32Ptr(0x5D4594, 60 * a3 + 2682236);
	v4 = getMemByte(0x5D4594, 3807124);
	v5 = dword_5d4594_3798844;
	v6 = dword_5d4594_3798804 * (dword_5d4594_3798840 + a1[1] - dword_5d4594_3798824) + dword_5d4594_3798796 +
		 ((dword_5d4594_3798836 + *a1 - dword_5d4594_3798820) << getMemByte(0x5D4594, 3807124));
	if (v6 >= *(int*)&dword_5d4594_3798844)
		v6 += dword_5d4594_3798796 - dword_5d4594_3798844;
	if (v6 + *getMemU32Ptr(0x5D4594, 3799236) < *(int*)&dword_5d4594_3798844) {
		if (dword_5d4594_3799624)
			result = (char*)sub_484450(v3, v6);
		else
			result = (char*)sub_483FE0(v3, v6);
	} else {
		v7 = 0;
		v12 = 0;
		while (1) {
			v8 = *getMemU32Ptr(0x5D4594, v7 + 3799052) << v4;
			v9 = *getMemU32Ptr(0x5D4594, v7 + 3799244) << v4;
			if (v6 + v9 + v8 < v5) {
				result = (char*)sub_49D1C0(v6 + v8, v3, v9);
				v5 = dword_5d4594_3798844;
			} else {
				v10 = v5 - v8 - v6;
				if (v10 <= 0) {
					v6 += dword_5d4594_3798796 - v5;
					result = (char*)sub_49D1C0(v6 + v8, v3, v9);
					v5 = dword_5d4594_3798844;
					v7 = v12;
				} else {
					sub_49D1C0(v6 + v8, v3, v5 - v8 - v6);
					sub_49D1C0(*(int*)&dword_5d4594_3798796, v3, v9 - v10);
					v5 = dword_5d4594_3798844;
					v7 = v12;
					result = (char*)(dword_5d4594_3798796 - dword_5d4594_3798844);
					v6 += dword_5d4594_3798796 - dword_5d4594_3798844;
				}
			}
			v7 += 4;
			v6 += dword_5d4594_3798804;
			v12 = v7;
			if (v7 >= 184)
				break;
			v4 = getMemByte(0x5D4594, 3807124);
		}
	}
	return result;
}

//----- (00481900) --------------------------------------------------------
char __cdecl sub_481900(_DWORD* a1, _DWORD* a2) {
	int v2;              // ebx
	int v3;              // esi
	int v4;              // edx
	int v5;              // ebp
	int v6;              // eax
	int v7;              // edi
	int v8;              // edi
	int v9;              // eax
	_BYTE* v10;          // ebx
	int v11;             // ebp
	unsigned int v12;    // esi
	unsigned int v13;    // edi
	char* v14;           // ebp
	char* v15;           // edx
	int v16;             // ebx
	char* v17;           // edi
	unsigned int v18;    // ecx
	char* v19;           // esi
	unsigned int v20;    // eax
	int v22;             // eax
	int v24;             // [esp+10h] [ebp-1Ch]
	unsigned __int8 v25; // [esp+14h] [ebp-18h]
	char* v26;           // [esp+14h] [ebp-18h]
	char* v27;           // [esp+18h] [ebp-14h]
	int v28;             // [esp+1Ch] [ebp-10h]
	unsigned __int8 v29; // [esp+20h] [ebp-Ch]
	int v30;             // [esp+28h] [ebp-4h]
	unsigned int v31;    // [esp+30h] [ebp+4h]
	unsigned __int8 v32; // [esp+34h] [ebp+8h]
	char* v33;           // [esp+34h] [ebp+8h]
	int* addr;

	v2 = dword_5d4594_3798824;
	v3 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 60 * *a2 + 2682220) +
					4 * (a2[1] + *(unsigned __int16*)getMemAt(0x5D4594, 60 * *a2 + 2682234)));
	v4 = a2[2];
	v5 = dword_5d4594_3798836;
	addr =
		(*getMemU32Ptr(0x5D4594, 60 * v4 + 2678380) + 4 * (a2[3] + *(unsigned __int16*)getMemAt(0x5D4594, 60 * v4 + 2678394)));
	v6 = *(_DWORD*)addr;
	v7 = dword_5d4594_3798840;
	*getMemU32Ptr(0x5D4594, 4 * v4 + 2523980) = 1;
	v8 = dword_5d4594_3798804 * (v7 + a1[1] - v2) + dword_5d4594_3798796 +
		 ((v5 + *a1 - dword_5d4594_3798820) << getMemByte(0x5D4594, 3807124));
	v9 = sub_42FB30(v6);
	if (v9) {
		v32 = *(_BYTE*)v9;
		v25 = *(_BYTE*)(v9 + 1);
		v10 = (_BYTE*)(v9 + 2);
		v9 = sub_42FB30(v3);
		v11 = v9;
		if (v9) {
			v12 = dword_5d4594_3798844;
			v9 = v32;
			v13 = dword_5d4594_3798804 * v32 + v8;
			v31 = v13;
			v14 = (char*)((*getMemU32Ptr(0x5D4594, 4 * v32 + 3798860) << getMemByte(0x5D4594, 3807124)) + v11);
			v27 = v14;
			if (v13 >= *(int*)&dword_5d4594_3798844) {
				v13 += dword_5d4594_3798796 - dword_5d4594_3798844;
				v31 = v13;
			}
			v28 = v32;
			v30 = v25;
			if (v32 <= (int)v25) {
				do {
					v24 = *getMemU32Ptr(0x5D4594, 4 * v9 + 3799244);
					v26 = v14;
					v15 = (char*)(v13 + (*getMemU32Ptr(0x5D4594, 4 * v9 + 3799052) << getMemByte(0x5D4594, 3807124)));
					if (v24 > 0) {
						do {
							LOBYTE(v9) = *v10;
							v29 = v10[1];
							v33 = v10 + 2;
							v16 = v29 << getMemByte(0x5D4594, 3807124);
							switch ((_BYTE)v9) {
							case 2:
								if ((unsigned int)&v15[v16] < v12) {
									v19 = v33;
									v18 = v29 << getMemByte(0x5D4594, 3807124);
									v17 = v15;
								} else {
									memcpy(v15, v33, v12 - (_DWORD)v15);
									v17 = *(char**)&dword_5d4594_3798796;
									v18 = v16 - (v12 - (_DWORD)v15);
									v19 = &v33[v12 - (_DWORD)v15];
								}
								memcpy(v17, v19, v18);
								v12 = dword_5d4594_3798844;
								v13 = v31;
								v33 += v16;
								break;
							case 3:
								if ((unsigned int)&v15[v16] < v12) {
									memcpy(v15, v14, v16);
								} else {
									v20 = v12 - (_DWORD)v15;
									memcpy(v15, v14, v20);
									v14 = v26;
									memcpy(*(void**)&dword_5d4594_3798796, &v26[v20], v16 - v20);
								}
								v12 = dword_5d4594_3798844;
								v13 = v31;
								break;
							case 1:
								break;
							default:
								return v9;
							}
							v15 += v16;
							v22 = v24 - v29;
							v14 += v16;
							v24 -= v29;
							v26 = v14;
							if ((unsigned int)v15 >= v12)
								v15 += dword_5d4594_3798796 - v12;
							v10 = v33;
						} while (v22 > 0);
						v9 = v28;
					}
					v14 = &v27[*getMemU32Ptr(0x5D4594, 4 * v9 + 3799244) << getMemByte(0x5D4594, 3807124)];
					v13 += dword_5d4594_3798804;
					v27 += *getMemU32Ptr(0x5D4594, 4 * v9 + 3799244) << getMemByte(0x5D4594, 3807124);
					v31 = v13;
					if (v13 >= v12) {
						v13 += dword_5d4594_3798796 - v12;
						v31 = v13;
					}
					v28 = ++v9;
				} while (v9 <= v30);
			}
		}
	}
	return v9;
}

//----- (00481BF0) --------------------------------------------------------
void __cdecl sub_481BF0(int a1, int a2) {
	int i; // esi

	for (i = a2; i; i = *(_DWORD*)(i + 16))
		func_587000_154944(a1, i);
}
// 5ACD40: invalid function type has been ignored

#if 1
//----- (00481C20) --------------------------------------------------------
int __cdecl sub_481C20(int* a1) {
	int v1;               // esi
	int v2;               // edx
	int v3;               // esi
	int v4;               // eax
	bool v5;              // sf
	int v6;               // ecx
	int v7;               // edx
	int v8;               // eax
	int v9;               // edx
	int v10;              // esi
	int v11;              // ebx
	int v12;              // eax
	int v13;              // ecx
	int v14;              // esi
	int v15;              // edi
	int v16;              // edi
	int v17;              // esi
	bool v18;             // cc
	int v19;              // esi
	int v20;              // edi
	int v21;              // eax
	int v22;              // esi
	int v23;              // edi
	int v24;              // ecx
	int v25;              // eax
	int v26;              // ebx
	int v27;              // ecx
	int v28;              // esi
	char v29;             // al
	int v30;              // esi
	int v31;              // edi
	int v32;              // edi
	int v33;              // esi
	int result;           // eax
	unsigned __int8* v35; // ebx
	int v36;              // eax
	int v37;              // eax
	int v38;              // edx
	char* v39;            // esi
	unsigned int v40;     // eax
	int v41;              // eax
	char* v42;            // edi
	char* v43;            // edi
	char* v44;            // esi
	char v45;             // cl
	bool v46;             // zf
	int v47;              // eax
	unsigned __int8* v48; // eax
	int v49;              // ecx
	int v50;              // eax
	unsigned __int8* v51; // esi
	int v52;              // eax
	int* v53;             // ebx
	int v54;              // esi
	int v55;              // eax
	unsigned int v56;     // ecx
	unsigned int v57;     // eax
	int v58;              // eax
	int v59;              // edi
	int v60;              // edx
	int v61;              // esi
	int v62;              // [esp-8h] [ebp-54h]
	int v63;              // [esp-8h] [ebp-54h]
	int v64;              // [esp-8h] [ebp-54h]
	int v65;              // [esp-8h] [ebp-54h]
	int2 v66;             // [esp+Ch] [ebp-40h]
	int2 v67;             // [esp+14h] [ebp-38h]
	int2 v68;             // [esp+1Ch] [ebp-30h]
	int v69;              // [esp+24h] [ebp-28h]
	int v70;              // [esp+28h] [ebp-24h]
	int v71;              // [esp+2Ch] [ebp-20h]
	int v72;              // [esp+30h] [ebp-1Ch]
	int j;                // [esp+34h] [ebp-18h]
	unsigned int v74;     // [esp+38h] [ebp-14h]
	unsigned __int8* v75; // [esp+3Ch] [ebp-10h]
	int v76;              // [esp+40h] [ebp-Ch]
	int i;                // [esp+44h] [ebp-8h]
	unsigned __int8* v78; // [esp+48h] [ebp-4h]
	int v79;              // [esp+54h] [ebp+8h]
	int v80;              // [esp+54h] [ebp+8h]

	++dword_587000_154948;
	v1 = a1[4];
	v2 = *a1;
	v78 = (unsigned __int8*)(a1[5] - a1[1]);
	v3 = v1 - v2;
	v72 = v3;
	if (!nox_client_texturedFloors_154956) {
		if (dword_5d4594_1193156 != 1)
			goto LABEL_9;
		dword_587000_154960 = 0;
		nox_client_texturedFloors_154956 = 1;
		sub_481420();
	}
	if (dword_5d4594_1193156 == 1 && !dword_587000_154960 && !(*getMemU32Ptr(0x5D4594, 2598000) % 0x1Eu) &&
		!sub_482570(a1)) {
		dword_5d4594_1193156 = 0;
		nox_client_texturedFloors_154956 = dword_587000_154960;
		sub_481420();
	}
LABEL_9:
	if (dword_5d4594_1193188) {
		sub_4826A0(a1);
		dword_5d4594_1193188 = 0;
		goto LABEL_60;
	}
	if (v3 >= *(int*)&dword_5d4594_3798820 + 23) {
		v71 = nox_backbuffer_width + v3;
		if (nox_backbuffer_width + v3 <= *(int*)&dword_5d4594_3798800 + dword_5d4594_3798820 - 46 ||
			*(int*)&dword_5d4594_3798812 + *(int*)&dword_5d4594_3798828 - 1 >= 128) {
			goto LABEL_36;
		}
		if (v71 > *(int*)&dword_5d4594_3798800 + *(int*)&dword_5d4594_3798820) {
			sub_4826A0(a1);
			goto LABEL_36;
		}
		v7 = dword_5d4594_3798828 + 1;
		dword_5d4594_3798828 = v7;
		v8 = dword_5d4594_3798820 + 46;
		dword_5d4594_3798820 += 46;
		j = dword_5d4594_3798812 + v7 - 2;
		v9 = dword_5d4594_3798836 + 46;
		dword_5d4594_3798836 += 46;
		if (*(int*)&dword_5d4594_3798836 >= *(int*)&dword_5d4594_3798800) {
			dword_5d4594_3798836 = v9 - dword_5d4594_3798800;
			v10 = ++dword_5d4594_3798840;
			if (*(int*)&dword_5d4594_3798840 >= *(int*)&dword_5d4594_3798808)
				dword_5d4594_3798840 = v10 - dword_5d4594_3798808;
		}
		v4 = dword_5d4594_3798800 + v8 - 92;
	} else {
		if (*(int*)&dword_5d4594_3798828 <= 0)
			goto LABEL_36;
		if (v3 < *(int*)&dword_5d4594_3798820 - 23) {
			sub_4826A0(a1);
			goto LABEL_36;
		}
		v4 = dword_5d4594_3798820 - 46;
		j = --dword_5d4594_3798828;
		dword_5d4594_3798820 -= 46;
		dword_5d4594_3798836 -= 46;
		if (*(int*)&dword_5d4594_3798836 < 0) {
			v6 = *(int*)&dword_5d4594_3798840 - 1;
			v5 = *(int*)&dword_5d4594_3798840 - 1 < 0;
			dword_5d4594_3798836 += dword_5d4594_3798800;
			--*(int*)&dword_5d4594_3798840;
			if (v5)
				*(int*)&dword_5d4594_3798840 = *(int*)&dword_5d4594_3798808 + v6;
		}
	}
	v76 = v4;
	sub_481410();
	v11 = dword_5d4594_3798824;
	v74 = dword_5d4594_3798832;
	if (*(int*)&dword_5d4594_3798832 < *(int*)&dword_5d4594_3798832 + *(int*)&dword_5d4594_3798816) {
		v12 = 44 * dword_5d4594_3798832;
		for (i = 44 * dword_5d4594_3798832;; v12 = i) {
			HIWORD(v13) = *getMemU16Ptr(0x5D4594, 2650670);
			v14 = v12 + (_DWORD)(ptr_5D4594_2650668[j]);
			if (*(_BYTE*)v14 & 2) {
				LOWORD(v13) = *(_WORD*)(v14 + 24);
				v15 = *(unsigned __int16*)(v14 + 24);
				v62 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 60 * v15 + 2682220) +
								 4 * (*(_DWORD*)(v14 + 28) + *(unsigned __int16*)getMemAt(0x5D4594, 60 * v15 + 2682234)));
				v68.field_0 = v76;
				v68.field_4 = v11 + 23;
				func_587000_154940(&v68, v62, v13);
				*getMemU32Ptr(0x5D4594, 4 * v15 + 2649932) = 1;
				if (*(_DWORD*)(v14 + 40))
					sub_481BF0((int)&v68, *(_DWORD*)(v14 + 40));
			}
			if (*(_BYTE*)v14 & 1) {
				LOWORD(v13) = *(_WORD*)(v14 + 4);
				v16 = *(unsigned __int16*)(v14 + 4);
				v63 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 60 * v16 + 2682220) +
								 4 * (*(_DWORD*)(v14 + 8) + *(unsigned __int16*)getMemAt(0x5D4594, 60 * v16 + 2682234)));
				v68.field_0 = v76 + 23;
				v68.field_4 = v11;
				func_587000_154940(&v68, v63, v13);
				*getMemU32Ptr(0x5D4594, 4 * v16 + 2649932) = 1;
				v17 = *(_DWORD*)(v14 + 20);
				if (v17)
					sub_481BF0((int)&v68, v17);
			}
			v11 += 46;
			v18 = (int)++v74 < *(int*)&dword_5d4594_3798832 + dword_5d4594_3798816;
			i += 44;
			if (!v18)
				break;
		}
	}
LABEL_36:
	if ((int)v78 >= *(int*)&dword_5d4594_3798824 + 23) {
		if ((int)&v78[nox_backbuffer_height] <= *(int*)&dword_5d4594_3798824 + *(int*)&dword_5d4594_3798808)
			goto LABEL_60;
		v22 = dword_5d4594_3798832;
		if (*(int*)&dword_5d4594_3798832 + *(int*)&dword_5d4594_3798816 >= 128)
			goto LABEL_60;
		if ((int)&v78[nox_backbuffer_height] > *(int*)&dword_5d4594_3798824 + *(int*)&dword_5d4594_3798808 + 46) {
			sub_4826A0(a1);
			goto LABEL_60;
		}
		++dword_5d4594_3798832;
		v23 = dword_5d4594_3798824 + 46;
		v19 = dword_5d4594_3798816 + v22;
		v24 = dword_5d4594_3798840 + 46;
		dword_5d4594_3798824 += 46;
		dword_5d4594_3798840 += 46;
		if (*(int*)&dword_5d4594_3798840 >= *(int*)&dword_5d4594_3798808)
			dword_5d4594_3798840 = v24 - dword_5d4594_3798808;
		v76 = v23 + dword_5d4594_3798808 - 46;
	} else {
		if (*(int*)&dword_5d4594_3798832 <= 0)
			goto LABEL_60;
		if ((int)v78 < *(int*)&dword_5d4594_3798824 - 23) {
			sub_4826A0(a1);
			goto LABEL_60;
		}
		v19 = dword_5d4594_3798832 - 1;
		v20 = dword_5d4594_3798824 - 46;
		v21 = dword_5d4594_3798840 - 46;
		v5 = *(int*)&dword_5d4594_3798840 - 46 < 0;
		--dword_5d4594_3798832;
		dword_5d4594_3798824 -= 46;
		dword_5d4594_3798840 -= 46;
		if (v5)
			dword_5d4594_3798840 = dword_5d4594_3798808 + v21;
		v76 = v20;
	}
	sub_481410();
	v25 = dword_5d4594_3798828;
	v26 = dword_5d4594_3798820;
	i = dword_5d4594_3798828;
	j = dword_5d4594_3798812 + dword_5d4594_3798828 - 1;
	if (dword_5d4594_3798828 < j) {
		v27 = 44 * v19;
		v71 = 44 * v19;
		while (1) {
			v28 = ptr_5D4594_2650668[v25];
			v29 = *(_BYTE*)(v28 + v27);
			v30 = v27 + v28;
			if (v29 & 2) {
				LOWORD(v27) = *(_WORD*)(v30 + 24);
				v31 = *(unsigned __int16*)(v30 + 24);
				v64 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 60 * v31 + 2682220) +
								 4 * (*(_DWORD*)(v30 + 28) + *(unsigned __int16*)getMemAt(0x5D4594, 60 * v31 + 2682234)));
				v68.field_0 = v26;
				v68.field_4 = v76 + 23;
				func_587000_154940(&v68, v64, v27);
				*getMemU32Ptr(0x5D4594, 4 * v31 + 2649932) = 1;
				if (*(_DWORD*)(v30 + 40))
					sub_481BF0((int)&v68, *(_DWORD*)(v30 + 40));
			}
			if (*(_BYTE*)v30 & 1) {
				LOWORD(v27) = *(_WORD*)(v30 + 4);
				v32 = *(unsigned __int16*)(v30 + 4);
				v65 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 60 * v32 + 2682220) +
								 4 * (*(_DWORD*)(v30 + 8) + *(unsigned __int16*)getMemAt(0x5D4594, 60 * v32 + 2682234)));
				v68.field_0 = v26 + 23;
				v68.field_4 = v76;
				func_587000_154940(&v68, v65, v27);
				*getMemU32Ptr(0x5D4594, 4 * v32 + 2649932) = 1;
				v33 = *(_DWORD*)(v30 + 20);
				if (v33)
					sub_481BF0((int)&v68, v33);
			}
			v26 += 46;
			if (++i >= j)
				break;
			v27 = v71;
			v25 = i;
		}
	}
LABEL_60:
	v67.field_4 = (int)&v78[dword_5d4594_3679320];
	sub_4745F0(a1);
	if (nox_client_texturedFloors_154956) {
		v48 = getMemAt(0x5D4594, 2598284);
		do {
			*(_DWORD*)v48 = -1;
			v48 += 280;
		} while ((int)v48 < (int)getMemAt(0x5D4594, 2614244));
		v66.field_4 = (v67.field_4 - *(int*)&dword_5d4594_2650680) / 23;
		v49 = dword_5d4594_3679320;
		v50 = v67.field_4 - 23 * v66.field_4 - dword_5d4594_2650680;
		v78 = (unsigned __int8*)(v67.field_4 - 23 * v66.field_4 - dword_5d4594_2650680);
		v80 = dword_5d4594_3679320;
		if (*(int*)&dword_5d4594_3679320 < *(int*)&dword_5d4594_3798156) {
			v51 = getMemAt(0x5D4594, 128 * dword_5d4594_3679320 + 3682956);
			v76 = 4 * dword_5d4594_3679320 - 4;
			for (j = (int)getMemAt(0x5D4594, 128 * dword_5d4594_3679320 + 3682956);; v51 = (unsigned __int8*)j) {
				i = (_DWORD)nox_pixbuffer_rows_3798784[v49];
				if (v50 == 23) {
					v78 = 0;
					++v66.field_4;
				}
				v52 = *getMemU32Ptr(0x5D4594, v76 + 3679344);
				v53 = (int*)v51;
				if (nox_client_highResFloors_154952 || !(v67.field_4 & 1) || v51 == getMemAt(0x5D4594, 3682956)) {
					if (v52 > 0) {
						v71 = (unsigned int)(v52 + 1) >> 1;
						do {
							v58 = v53[1];
							v69 = *v53;
							v59 = v69 + v72;
							v53 += 2;
							v67.field_0 = v69 + v72;
							v60 = (v69 + v72 - *(int*)&dword_5d4594_2650676) / 23;
							v66.field_0 = v60;
							v70 = (v69 + v72 - *(int*)&dword_5d4594_2650676) / 23;
							v61 = dword_5d4594_2650676 + 23 * v60;
							v74 = v58 - v69;
							v75 = getMemAt(0x5D4594, 280 * v60 + 2598284);
							if (v61 < v58 + v72 + 23) {
								do {
									if (*(_DWORD*)v75 != v66.field_4) {
										(*(int(__cdecl**)(int2*)) getMemAt(0x5D4594, 3807148))(&v66);
										v59 = v67.field_0;
										v60 = v66.field_0;
									}
									v61 += 23;
									v75 += 280;
									v66.field_0 = ++v60;
								} while (v61 < (int)(v74 + v59 + 23));
							}
							v66.field_0 = v70;
							(*(void(__cdecl**)(int2*, int*, _DWORD, _DWORD, _DWORD)) &
							 dword_5d4594_3805484)(&v67, &v66.field_0, v78, v74, i + (v69 << getMemByte(0x5D4594, 3807124)));
							--v71;
						} while (v71);
					}
				} else if (v52 > 0) {
					v74 = (unsigned int)(v52 + 1) >> 1;
					do {
						v54 = *v53;
						v55 = v53[1];
						v53 += 2;
						v56 = (v55 - v54) << getMemByte(0x5D4594, 3807124);
						v57 = v74;
						memcpy((void*)(i + (v54 << getMemByte(0x5D4594, 3807124))),
								(const void*)((v54 << getMemByte(0x5D4594, 3807124)) + (_DWORD)nox_pixbuffer_rows_3798784[v76/4]),
								v56);
						v74 = v57 - 1;
					} while (v57 != 1);
				}
				++v78;
				v18 = ++v80 < *(int*)&dword_5d4594_3798156;
				j += 128;
				v76 += 4;
				++v67.field_4;
				if (!v18)
					break;
				v49 = v80;
				v50 = (int)v78;
			}
		}
		result = dword_5d4594_805836;
#if 0
        if (*(_DWORD*)& dword_5d4594_805836)
            _m_femms();
#endif
	} else {
		result = dword_5d4594_3679320;
		v79 = dword_5d4594_3679320;
		if (*(int*)&dword_5d4594_3679320 < *(int*)&dword_5d4594_3798156) {
			v78 = getMemAt(0x5D4594, 128 * dword_5d4594_3679320 + 3682956);
			do {
				v35 = v78;
				v36 = *getMemU32Ptr(0x5D4594, 4 * v79 + 3679340);
				i = nox_pixbuffer_rows_3798784[v79];
				if (v36 > 0) {
					j = (unsigned int)(v36 + 1) >> 1;
					do {
						v37 = *(_DWORD*)v35;
						v38 = *((_DWORD*)v35 + 1) - *(_DWORD*)v35;
						v67.field_0 = *(_DWORD*)v35 + v72;
						v71 = dword_5d4594_3798804 * (v67.field_4 + dword_5d4594_3798840 - dword_5d4594_3798824);
						v35 += 8;
						v39 =
							(char*)(dword_5d4594_3798804 * (v67.field_4 + dword_5d4594_3798840 - dword_5d4594_3798824) +
									dword_5d4594_3798796 +
									((v37 + v72 + dword_5d4594_3798836 - dword_5d4594_3798820)
									 << getMemByte(0x5D4594, 3807124)));
						if ((unsigned int)v39 >= *(int*)&dword_5d4594_3798844)
							v39 += dword_5d4594_3798796 - dword_5d4594_3798844;
						v76 = i + (v37 << getMemByte(0x5D4594, 3807124));
						v40 = v38 << getMemByte(0x5D4594, 3807124);
						if ((unsigned int)&v39[v38 << getMemByte(0x5D4594, 3807124)] < *(int*)&dword_5d4594_3798844) {
							v42 = (char*)v76;
							memcpy((void*)v76, v39, 4 * (v40 >> 2));
						} else {
							v71 = dword_5d4594_3798844 - (_DWORD)v39;
							v41 = dword_5d4594_3798844 - (_DWORD)v39;
							memcpy((void*)v76, v39, dword_5d4594_3798844 - (_DWORD)v39);
							v39 = *(char**)&dword_5d4594_3798796;
							v42 = (char*)(v41 + v76);
							v40 = (v38 << getMemByte(0x5D4594, 3807124)) - v41;
							memcpy(v42, *(const void**)&dword_5d4594_3798796, 4 * (v40 >> 2));
						}
						v44 = &v39[4 * (v40 >> 2)];
						v43 = &v42[4 * (v40 >> 2)];
						v45 = v40;
						v47 = j - 1;
						v46 = j == 1;
						memcpy(v43, v44, v45 & 3);
						j = v47;
					} while (!v46);
				}
				result = v79 + 1;
				v18 = ++v79 < *(int*)&dword_5d4594_3798156;
				v78 += 128;
				++v67.field_4;
			} while (v18);
		}
	}
	return result;
}
// 481F0B: variable 'v13' is possibly undefined
// 482142: variable 'v27' is possibly undefined
#endif

//----- (00482570) --------------------------------------------------------
int __cdecl sub_482570(_DWORD* a1) {
	int v1;     // esi
	int v2;     // ebx
	int v3;     // eax
	int v4;     // edx
	int i;      // ebp
	int v6;     // edi
	_DWORD* v7; // esi
	int v8;     // eax
	int v10;    // [esp+10h] [ebp-8h]
	int v11;    // [esp+14h] [ebp-4h]
	int v12;    // [esp+1Ch] [ebp+4h]

	v1 = a1[5] - a1[1];
	v2 = (a1[4] - *a1 - 11) / 46;
	if (v2 < 0)
		v2 = 0;
	v12 = dword_5d4594_3798812 + v2 - 1;
	if (v12 >= 128) {
		v12 = 127;
		v2 = 127 - dword_5d4594_3798812;
	}
	v3 = (v1 - 11) / 46 - 1;
	if (v3 < 0)
		v3 = 0;
	v4 = dword_5d4594_3798816 + v3;
	v10 = dword_5d4594_3798816 + v3;
	if (*(int*)&dword_5d4594_3798816 + v3 >= 128) {
		v10 = 127;
		v3 = 127 - dword_5d4594_3798816;
		v4 = 127;
	}
	v11 = v3;
	if (v3 >= v4)
		return 0;
	for (i = 44 * v3;; i += 44) {
		v6 = v2;
		if (v2 < v12)
			break;
	LABEL_19:
		if (++v11 >= v4)
			return 0;
	}
	v7 = &ptr_5D4594_2650668[v2];
	while (1) {
		v8 = i + *v7;
		if (*(_BYTE*)v8 & 1) {
			if ((getMemByte(0x5D4594, 60 * *(_DWORD*)(v8 + 4) + 2682246) & 1) == 1)
				return 1;
		}
		if (*(_BYTE*)v8 & 2 && (getMemByte(0x5D4594, 60 * *(_DWORD*)(v8 + 24) + 2682246) & 1) == 1)
			return 1;
		++v6;
		++v7;
		if (v6 >= v12) {
			v4 = v10;
			goto LABEL_19;
		}
	}
}

//----- (004826A0) --------------------------------------------------------
int __cdecl sub_4826A0(_DWORD* a1) {
	int v1;     // esi
	int v2;     // ebx
	int result; // eax
	int v4;     // ecx
	int v5;     // esi
	int v6;     // ebx
	int v7;     // ecx
	int v8;     // ebp
	int v9;     // eax
	int v10;    // ecx
	int v11;    // esi
	char v12;   // al
	int v13;    // esi
	int v14;    // edi
	int v15;    // edi
	int v16;    // esi
	bool v17;   // zf
	int v18;    // [esp-8h] [ebp-34h]
	int v19;    // [esp-8h] [ebp-34h]
	int v20;    // [esp+10h] [ebp-1Ch]
	int v21;    // [esp+14h] [ebp-18h]
	int v22;    // [esp+18h] [ebp-14h]
	int v23;    // [esp+1Ch] [ebp-10h]
	int2 v24;   // [esp+24h] [ebp-8h]
	int v25;    // [esp+30h] [ebp+4h]

	v1 = a1[4] - *a1;
	v2 = a1[5] - a1[1];
	dword_5d4594_3798836 = 0;
	dword_5d4594_3798840 = 0;
	sub_481410();
	memset(getMemAt(0x5D4594, 2649932), 0, 0x2C0u);
	memset(getMemAt(0x5D4594, 2523980), 0, 0x100u);
	v25 = (v1 - 11) / 46;
	if (v25 < 0)
		v25 = 0;
	v20 = dword_5d4594_3798812 + v25 - 1;
	if (v20 >= 128) {
		v20 = 127;
		v25 = 127 - dword_5d4594_3798812;
	}
	result = (v2 - 11) / 46 - 1;
	if (result < 0)
		result = 0;
	v4 = dword_5d4594_3798816 + result;
	if (*(int*)&dword_5d4594_3798816 + result >= 128) {
		v4 = 127;
		result = 127 - dword_5d4594_3798816;
	}
	v5 = v25;
	dword_5d4594_3798824 = 46 * result - 11;
	v6 = 46 * result - 57;
	dword_5d4594_3798828 = v25;
	dword_5d4594_3798820 = 46 * v25 - 11;
	dword_5d4594_3798832 = result;
	if (result < v4) {
		v21 = 44 * result;
		v23 = v4 - result;
		v7 = v20;
		do {
			v8 = 46 * v25 - 57;
			v6 += 46;
			v9 = v5;
			v22 = v5;
			if (v5 < v7) {
				do {
					HIWORD(v10) = *getMemU16Ptr(0x5D4594, 2650670);
					v8 += 46;
					v11 = ptr_5D4594_2650668[v9];
					v12 = *(_BYTE*)(v11 + v21);
					v13 = v21 + v11;
					if (v12) {
						if (v12 & 2) {
							LOWORD(v10) = *(_WORD*)(v13 + 24);
							v14 = *(unsigned __int16*)(v13 + 24);
							v18 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 60 * v14 + 2682220) +
											 4 * (*(_DWORD*)(v13 + 28) +
												  *(unsigned __int16*)getMemAt(0x5D4594, 60 * v14 + 2682234)));
							v24.field_0 = v8;
							v24.field_4 = v6 + 23;
							func_587000_154940(&v24, v18, v10);
							*getMemU32Ptr(0x5D4594, 4 * v14 + 2649932) = 1;
							if (*(_DWORD*)(v13 + 40))
								sub_481BF0((int)&v24, *(_DWORD*)(v13 + 40));
						}
						if (*(_BYTE*)v13 & 1) {
							LOWORD(v10) = *(_WORD*)(v13 + 4);
							v15 = *(unsigned __int16*)(v13 + 4);
							v19 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 60 * v15 + 2682220) +
											 4 * (*(_DWORD*)(v13 + 8) +
												  *(unsigned __int16*)getMemAt(0x5D4594, 60 * v15 + 2682234)));
							v24.field_0 = v8 + 23;
							v24.field_4 = v6;
							func_587000_154940(&v24, v19, v10);
							*getMemU32Ptr(0x5D4594, 4 * v15 + 2649932) = 1;
							v16 = *(_DWORD*)(v13 + 20);
							if (v16)
								sub_481BF0((int)&v24, v16);
						}
					}
					v7 = v20;
					v9 = ++v22;
				} while (v22 < v20);
				v5 = v25;
			}
			result = v23 - 1;
			v17 = v23 == 1;
			v21 += 44;
			--v23;
		} while (!v17);
	}
	return result;
}
// 4828A6: variable 'v10' is possibly undefined

//----- (00482910) --------------------------------------------------------
char __cdecl sub_482910(int a1, int a2) {
	int v2;      // edx
	int v3;      // edi
	int v4;      // edi
	int v5;      // edi
	int v6;      // edi
	int v7;      // edi
	int v8;      // edi
	int v9;      // edi
	int v10;     // edi
	int v11;     // edi
	int v12;     // edi
	int v13;     // edi
	int v14;     // edi
	int v15;     // edi
	int v16;     // edi
	int v17;     // edi
	int v18;     // edi
	int v19;     // edi
	int v20;     // edi
	int v21;     // edi
	int v22;     // edi
	int v23;     // edi
	int v24;     // edi
	int v25;     // edi
	int v26;     // edi
	int v27;     // edi
	int v28;     // edi
	int v29;     // edi
	int v30;     // edi
	int v31;     // edi
	int v32;     // edi
	int v33;     // edi
	int v34;     // edi
	int v35;     // edi
	int v36;     // edi
	int v37;     // edi
	int v38;     // edi
	int v39;     // edi
	int v40;     // edi
	int v41;     // edi
	int v42;     // edi
	int v43;     // edi
	int v44;     // edi
	int v45;     // edi
	int v46;     // edi
	char result; // al

	v2 = dword_5d4594_3798804;
	*(_BYTE*)(a2 + 23) = *(_BYTE*)a1;
	v3 = v2 + a2;
	*(_WORD*)(v3 + 22) = *(_WORD*)(a1 + 1);
	*(_BYTE*)(v3 + 24) = *(_BYTE*)(a1 + 3);
	v4 = v2 + v2 + a2;
	*(_BYTE*)(v4 + 21) = *(_BYTE*)(a1 + 4);
	*(_WORD*)(v4 + 22) = *(_WORD*)(a1 + 5);
	*(_WORD*)(v4 + 24) = *(_WORD*)(a1 + 7);
	v5 = v2 + v4;
	*(_DWORD*)(v5 + 20) = *(_DWORD*)(a1 + 9);
	*(_WORD*)(v5 + 24) = *(_WORD*)(a1 + 13);
	*(_BYTE*)(v5 + 26) = *(_BYTE*)(a1 + 15);
	v6 = v2 + v5;
	*(_BYTE*)(v6 + 19) = *(_BYTE*)(a1 + 16);
	*(_DWORD*)(v6 + 20) = *(_DWORD*)(a1 + 17);
	*(_DWORD*)(v6 + 24) = *(_DWORD*)(a1 + 21);
	v7 = v2 + v6;
	*(_WORD*)(v7 + 18) = *(_WORD*)(a1 + 25);
	*(_DWORD*)(v7 + 20) = *(_DWORD*)(a1 + 27);
	*(_DWORD*)(v7 + 24) = *(_DWORD*)(a1 + 31);
	*(_BYTE*)(v7 + 28) = *(_BYTE*)(a1 + 35);
	v8 = v2 + v7;
	*(_BYTE*)(v8 + 17) = *(_BYTE*)(a1 + 36);
	*(_WORD*)(v8 + 18) = *(_WORD*)(a1 + 37);
	*(_DWORD*)(v8 + 20) = *(_DWORD*)(a1 + 39);
	*(_DWORD*)(v8 + 24) = *(_DWORD*)(a1 + 43);
	*(_WORD*)(v8 + 28) = *(_WORD*)(a1 + 47);
	v9 = v2 + v8;
	*(_DWORD*)(v9 + 16) = *(_DWORD*)(a1 + 49);
	*(_DWORD*)(v9 + 20) = *(_DWORD*)(a1 + 53);
	*(_DWORD*)(v9 + 24) = *(_DWORD*)(a1 + 57);
	*(_WORD*)(v9 + 28) = *(_WORD*)(a1 + 61);
	*(_BYTE*)(v9 + 30) = *(_BYTE*)(a1 + 63);
	v10 = v2 + v9;
	*(_BYTE*)(v10 + 15) = *(_BYTE*)(a1 + 64);
	*(_DWORD*)(v10 + 16) = *(_DWORD*)(a1 + 65);
	*(_DWORD*)(v10 + 20) = *(_DWORD*)(a1 + 69);
	*(_DWORD*)(v10 + 24) = *(_DWORD*)(a1 + 73);
	*(_DWORD*)(v10 + 28) = *(_DWORD*)(a1 + 77);
	v11 = v2 + v10;
	*(_WORD*)(v11 + 14) = *(_WORD*)(a1 + 81);
	*(_DWORD*)(v11 + 16) = *(_DWORD*)(a1 + 83);
	*(_DWORD*)(v11 + 20) = *(_DWORD*)(a1 + 87);
	*(_DWORD*)(v11 + 24) = *(_DWORD*)(a1 + 91);
	*(_DWORD*)(v11 + 28) = *(_DWORD*)(a1 + 95);
	*(_BYTE*)(v11 + 32) = *(_BYTE*)(a1 + 99);
	v12 = v2 + v11;
	*(_BYTE*)(v12 + 13) = *(_BYTE*)(a1 + 100);
	*(_WORD*)(v12 + 14) = *(_WORD*)(a1 + 101);
	*(_DWORD*)(v12 + 16) = *(_DWORD*)(a1 + 103);
	*(_DWORD*)(v12 + 20) = *(_DWORD*)(a1 + 107);
	*(_DWORD*)(v12 + 24) = *(_DWORD*)(a1 + 111);
	*(_DWORD*)(v12 + 28) = *(_DWORD*)(a1 + 115);
	*(_WORD*)(v12 + 32) = *(_WORD*)(a1 + 119);
	v13 = v2 + v12;
	*(_DWORD*)(v13 + 12) = *(_DWORD*)(a1 + 121);
	*(_DWORD*)(v13 + 16) = *(_DWORD*)(a1 + 125);
	*(_DWORD*)(v13 + 20) = *(_DWORD*)(a1 + 129);
	*(_DWORD*)(v13 + 24) = *(_DWORD*)(a1 + 133);
	*(_DWORD*)(v13 + 28) = *(_DWORD*)(a1 + 137);
	*(_WORD*)(v13 + 32) = *(_WORD*)(a1 + 141);
	*(_BYTE*)(v13 + 34) = *(_BYTE*)(a1 + 143);
	v14 = v2 + v13;
	*(_BYTE*)(v14 + 11) = *(_BYTE*)(a1 + 144);
	*(_DWORD*)(v14 + 12) = *(_DWORD*)(a1 + 145);
	*(_DWORD*)(v14 + 16) = *(_DWORD*)(a1 + 149);
	*(_DWORD*)(v14 + 20) = *(_DWORD*)(a1 + 153);
	*(_DWORD*)(v14 + 24) = *(_DWORD*)(a1 + 157);
	*(_DWORD*)(v14 + 28) = *(_DWORD*)(a1 + 161);
	*(_DWORD*)(v14 + 32) = *(_DWORD*)(a1 + 165);
	v15 = v2 + v14;
	*(_WORD*)(v15 + 10) = *(_WORD*)(a1 + 169);
	*(_DWORD*)(v15 + 12) = *(_DWORD*)(a1 + 171);
	*(_DWORD*)(v15 + 16) = *(_DWORD*)(a1 + 175);
	*(_DWORD*)(v15 + 20) = *(_DWORD*)(a1 + 179);
	*(_DWORD*)(v15 + 24) = *(_DWORD*)(a1 + 183);
	*(_DWORD*)(v15 + 28) = *(_DWORD*)(a1 + 187);
	*(_DWORD*)(v15 + 32) = *(_DWORD*)(a1 + 191);
	*(_BYTE*)(v15 + 36) = *(_BYTE*)(a1 + 195);
	v16 = v2 + v15;
	*(_BYTE*)(v16 + 9) = *(_BYTE*)(a1 + 196);
	*(_WORD*)(v16 + 10) = *(_WORD*)(a1 + 197);
	*(_DWORD*)(v16 + 12) = *(_DWORD*)(a1 + 199);
	*(_DWORD*)(v16 + 16) = *(_DWORD*)(a1 + 203);
	*(_DWORD*)(v16 + 20) = *(_DWORD*)(a1 + 207);
	*(_DWORD*)(v16 + 24) = *(_DWORD*)(a1 + 211);
	*(_DWORD*)(v16 + 28) = *(_DWORD*)(a1 + 215);
	*(_DWORD*)(v16 + 32) = *(_DWORD*)(a1 + 219);
	*(_WORD*)(v16 + 36) = *(_WORD*)(a1 + 223);
	v17 = v2 + v16;
	*(_DWORD*)(v17 + 8) = *(_DWORD*)(a1 + 225);
	*(_DWORD*)(v17 + 12) = *(_DWORD*)(a1 + 229);
	*(_DWORD*)(v17 + 16) = *(_DWORD*)(a1 + 233);
	*(_DWORD*)(v17 + 20) = *(_DWORD*)(a1 + 237);
	*(_DWORD*)(v17 + 24) = *(_DWORD*)(a1 + 241);
	*(_DWORD*)(v17 + 28) = *(_DWORD*)(a1 + 245);
	*(_DWORD*)(v17 + 32) = *(_DWORD*)(a1 + 249);
	*(_WORD*)(v17 + 36) = *(_WORD*)(a1 + 253);
	*(_BYTE*)(v17 + 38) = *(_BYTE*)(a1 + 255);
	v18 = v2 + v17;
	*(_BYTE*)(v18 + 7) = *(_BYTE*)(a1 + 256);
	*(_DWORD*)(v18 + 8) = *(_DWORD*)(a1 + 257);
	*(_DWORD*)(v18 + 12) = *(_DWORD*)(a1 + 261);
	*(_DWORD*)(v18 + 16) = *(_DWORD*)(a1 + 265);
	*(_DWORD*)(v18 + 20) = *(_DWORD*)(a1 + 269);
	*(_DWORD*)(v18 + 24) = *(_DWORD*)(a1 + 273);
	*(_DWORD*)(v18 + 28) = *(_DWORD*)(a1 + 277);
	*(_DWORD*)(v18 + 32) = *(_DWORD*)(a1 + 281);
	*(_DWORD*)(v18 + 36) = *(_DWORD*)(a1 + 285);
	v19 = v2 + v18;
	*(_WORD*)(v19 + 6) = *(_WORD*)(a1 + 289);
	*(_DWORD*)(v19 + 8) = *(_DWORD*)(a1 + 291);
	*(_DWORD*)(v19 + 12) = *(_DWORD*)(a1 + 295);
	*(_DWORD*)(v19 + 16) = *(_DWORD*)(a1 + 299);
	*(_DWORD*)(v19 + 20) = *(_DWORD*)(a1 + 303);
	*(_DWORD*)(v19 + 24) = *(_DWORD*)(a1 + 307);
	*(_DWORD*)(v19 + 28) = *(_DWORD*)(a1 + 311);
	*(_DWORD*)(v19 + 32) = *(_DWORD*)(a1 + 315);
	*(_DWORD*)(v19 + 36) = *(_DWORD*)(a1 + 319);
	*(_BYTE*)(v19 + 40) = *(_BYTE*)(a1 + 323);
	v20 = v2 + v19;
	*(_BYTE*)(v20 + 5) = *(_BYTE*)(a1 + 324);
	*(_WORD*)(v20 + 6) = *(_WORD*)(a1 + 325);
	*(_DWORD*)(v20 + 8) = *(_DWORD*)(a1 + 327);
	*(_DWORD*)(v20 + 12) = *(_DWORD*)(a1 + 331);
	*(_DWORD*)(v20 + 16) = *(_DWORD*)(a1 + 335);
	*(_DWORD*)(v20 + 20) = *(_DWORD*)(a1 + 339);
	*(_DWORD*)(v20 + 24) = *(_DWORD*)(a1 + 343);
	*(_DWORD*)(v20 + 28) = *(_DWORD*)(a1 + 347);
	*(_DWORD*)(v20 + 32) = *(_DWORD*)(a1 + 351);
	*(_DWORD*)(v20 + 36) = *(_DWORD*)(a1 + 355);
	*(_WORD*)(v20 + 40) = *(_WORD*)(a1 + 359);
	v21 = v2 + v20;
	*(_DWORD*)(v21 + 4) = *(_DWORD*)(a1 + 361);
	*(_DWORD*)(v21 + 8) = *(_DWORD*)(a1 + 365);
	*(_DWORD*)(v21 + 12) = *(_DWORD*)(a1 + 369);
	*(_DWORD*)(v21 + 16) = *(_DWORD*)(a1 + 373);
	*(_DWORD*)(v21 + 20) = *(_DWORD*)(a1 + 377);
	*(_DWORD*)(v21 + 24) = *(_DWORD*)(a1 + 381);
	*(_DWORD*)(v21 + 28) = *(_DWORD*)(a1 + 385);
	*(_DWORD*)(v21 + 32) = *(_DWORD*)(a1 + 389);
	*(_DWORD*)(v21 + 36) = *(_DWORD*)(a1 + 393);
	*(_WORD*)(v21 + 40) = *(_WORD*)(a1 + 397);
	*(_BYTE*)(v21 + 42) = *(_BYTE*)(a1 + 399);
	v22 = v2 + v21;
	*(_BYTE*)(v22 + 3) = *(_BYTE*)(a1 + 400);
	*(_DWORD*)(v22 + 4) = *(_DWORD*)(a1 + 401);
	*(_DWORD*)(v22 + 8) = *(_DWORD*)(a1 + 405);
	*(_DWORD*)(v22 + 12) = *(_DWORD*)(a1 + 409);
	*(_DWORD*)(v22 + 16) = *(_DWORD*)(a1 + 413);
	*(_DWORD*)(v22 + 20) = *(_DWORD*)(a1 + 417);
	*(_DWORD*)(v22 + 24) = *(_DWORD*)(a1 + 421);
	*(_DWORD*)(v22 + 28) = *(_DWORD*)(a1 + 425);
	*(_DWORD*)(v22 + 32) = *(_DWORD*)(a1 + 429);
	*(_DWORD*)(v22 + 36) = *(_DWORD*)(a1 + 433);
	*(_DWORD*)(v22 + 40) = *(_DWORD*)(a1 + 437);
	v23 = v2 + v22;
	*(_WORD*)(v23 + 2) = *(_WORD*)(a1 + 441);
	*(_DWORD*)(v23 + 4) = *(_DWORD*)(a1 + 443);
	*(_DWORD*)(v23 + 8) = *(_DWORD*)(a1 + 447);
	*(_DWORD*)(v23 + 12) = *(_DWORD*)(a1 + 451);
	*(_DWORD*)(v23 + 16) = *(_DWORD*)(a1 + 455);
	*(_DWORD*)(v23 + 20) = *(_DWORD*)(a1 + 459);
	*(_DWORD*)(v23 + 24) = *(_DWORD*)(a1 + 463);
	*(_DWORD*)(v23 + 28) = *(_DWORD*)(a1 + 467);
	*(_DWORD*)(v23 + 32) = *(_DWORD*)(a1 + 471);
	*(_DWORD*)(v23 + 36) = *(_DWORD*)(a1 + 475);
	*(_DWORD*)(v23 + 40) = *(_DWORD*)(a1 + 479);
	*(_BYTE*)(v23 + 44) = *(_BYTE*)(a1 + 483);
	v24 = v2 + v23;
	*(_BYTE*)(v24 + 1) = *(_BYTE*)(a1 + 484);
	*(_WORD*)(v24 + 2) = *(_WORD*)(a1 + 485);
	*(_DWORD*)(v24 + 4) = *(_DWORD*)(a1 + 487);
	*(_DWORD*)(v24 + 8) = *(_DWORD*)(a1 + 491);
	*(_DWORD*)(v24 + 12) = *(_DWORD*)(a1 + 495);
	*(_DWORD*)(v24 + 16) = *(_DWORD*)(a1 + 499);
	*(_DWORD*)(v24 + 20) = *(_DWORD*)(a1 + 503);
	*(_DWORD*)(v24 + 24) = *(_DWORD*)(a1 + 507);
	*(_DWORD*)(v24 + 28) = *(_DWORD*)(a1 + 511);
	*(_DWORD*)(v24 + 32) = *(_DWORD*)(a1 + 515);
	*(_DWORD*)(v24 + 36) = *(_DWORD*)(a1 + 519);
	*(_DWORD*)(v24 + 40) = *(_DWORD*)(a1 + 523);
	*(_WORD*)(v24 + 44) = *(_WORD*)(a1 + 527);
	v25 = v2 + v24;
	*(_BYTE*)(v25 + 1) = *(_BYTE*)(a1 + 529);
	*(_WORD*)(v25 + 2) = *(_WORD*)(a1 + 530);
	*(_DWORD*)(v25 + 4) = *(_DWORD*)(a1 + 532);
	*(_DWORD*)(v25 + 8) = *(_DWORD*)(a1 + 536);
	*(_DWORD*)(v25 + 12) = *(_DWORD*)(a1 + 540);
	*(_DWORD*)(v25 + 16) = *(_DWORD*)(a1 + 544);
	*(_DWORD*)(v25 + 20) = *(_DWORD*)(a1 + 548);
	*(_DWORD*)(v25 + 24) = *(_DWORD*)(a1 + 552);
	*(_DWORD*)(v25 + 28) = *(_DWORD*)(a1 + 556);
	*(_DWORD*)(v25 + 32) = *(_DWORD*)(a1 + 560);
	*(_DWORD*)(v25 + 36) = *(_DWORD*)(a1 + 564);
	*(_DWORD*)(v25 + 40) = *(_DWORD*)(a1 + 568);
	*(_WORD*)(v25 + 44) = *(_WORD*)(a1 + 572);
	v26 = v2 + v25;
	*(_WORD*)(v26 + 2) = *(_WORD*)(a1 + 574);
	*(_DWORD*)(v26 + 4) = *(_DWORD*)(a1 + 576);
	*(_DWORD*)(v26 + 8) = *(_DWORD*)(a1 + 580);
	*(_DWORD*)(v26 + 12) = *(_DWORD*)(a1 + 584);
	*(_DWORD*)(v26 + 16) = *(_DWORD*)(a1 + 588);
	*(_DWORD*)(v26 + 20) = *(_DWORD*)(a1 + 592);
	*(_DWORD*)(v26 + 24) = *(_DWORD*)(a1 + 596);
	*(_DWORD*)(v26 + 28) = *(_DWORD*)(a1 + 600);
	*(_DWORD*)(v26 + 32) = *(_DWORD*)(a1 + 604);
	*(_DWORD*)(v26 + 36) = *(_DWORD*)(a1 + 608);
	*(_DWORD*)(v26 + 40) = *(_DWORD*)(a1 + 612);
	*(_BYTE*)(v26 + 44) = *(_BYTE*)(a1 + 616);
	v27 = v2 + v26;
	*(_BYTE*)(v27 + 3) = *(_BYTE*)(a1 + 617);
	*(_DWORD*)(v27 + 4) = *(_DWORD*)(a1 + 618);
	*(_DWORD*)(v27 + 8) = *(_DWORD*)(a1 + 622);
	*(_DWORD*)(v27 + 12) = *(_DWORD*)(a1 + 626);
	*(_DWORD*)(v27 + 16) = *(_DWORD*)(a1 + 630);
	*(_DWORD*)(v27 + 20) = *(_DWORD*)(a1 + 634);
	*(_DWORD*)(v27 + 24) = *(_DWORD*)(a1 + 638);
	*(_DWORD*)(v27 + 28) = *(_DWORD*)(a1 + 642);
	*(_DWORD*)(v27 + 32) = *(_DWORD*)(a1 + 646);
	*(_DWORD*)(v27 + 36) = *(_DWORD*)(a1 + 650);
	*(_DWORD*)(v27 + 40) = *(_DWORD*)(a1 + 654);
	v28 = v2 + v27;
	*(_DWORD*)(v28 + 4) = *(_DWORD*)(a1 + 658);
	*(_DWORD*)(v28 + 8) = *(_DWORD*)(a1 + 662);
	*(_DWORD*)(v28 + 12) = *(_DWORD*)(a1 + 666);
	*(_DWORD*)(v28 + 16) = *(_DWORD*)(a1 + 670);
	*(_DWORD*)(v28 + 20) = *(_DWORD*)(a1 + 674);
	*(_DWORD*)(v28 + 24) = *(_DWORD*)(a1 + 678);
	*(_DWORD*)(v28 + 28) = *(_DWORD*)(a1 + 682);
	*(_DWORD*)(v28 + 32) = *(_DWORD*)(a1 + 686);
	*(_DWORD*)(v28 + 36) = *(_DWORD*)(a1 + 690);
	*(_WORD*)(v28 + 40) = *(_WORD*)(a1 + 694);
	*(_BYTE*)(v28 + 42) = *(_BYTE*)(a1 + 696);
	v29 = v2 + v28;
	*(_BYTE*)(v29 + 5) = *(_BYTE*)(a1 + 697);
	*(_WORD*)(v29 + 6) = *(_WORD*)(a1 + 698);
	*(_DWORD*)(v29 + 8) = *(_DWORD*)(a1 + 700);
	*(_DWORD*)(v29 + 12) = *(_DWORD*)(a1 + 704);
	*(_DWORD*)(v29 + 16) = *(_DWORD*)(a1 + 708);
	*(_DWORD*)(v29 + 20) = *(_DWORD*)(a1 + 712);
	*(_DWORD*)(v29 + 24) = *(_DWORD*)(a1 + 716);
	*(_DWORD*)(v29 + 28) = *(_DWORD*)(a1 + 720);
	*(_DWORD*)(v29 + 32) = *(_DWORD*)(a1 + 724);
	*(_DWORD*)(v29 + 36) = *(_DWORD*)(a1 + 728);
	*(_WORD*)(v29 + 40) = *(_WORD*)(a1 + 732);
	v30 = v2 + v29;
	*(_WORD*)(v30 + 6) = *(_WORD*)(a1 + 734);
	*(_DWORD*)(v30 + 8) = *(_DWORD*)(a1 + 736);
	*(_DWORD*)(v30 + 12) = *(_DWORD*)(a1 + 740);
	*(_DWORD*)(v30 + 16) = *(_DWORD*)(a1 + 744);
	*(_DWORD*)(v30 + 20) = *(_DWORD*)(a1 + 748);
	*(_DWORD*)(v30 + 24) = *(_DWORD*)(a1 + 752);
	*(_DWORD*)(v30 + 28) = *(_DWORD*)(a1 + 756);
	*(_DWORD*)(v30 + 32) = *(_DWORD*)(a1 + 760);
	*(_DWORD*)(v30 + 36) = *(_DWORD*)(a1 + 764);
	*(_BYTE*)(v30 + 40) = *(_BYTE*)(a1 + 768);
	v31 = v2 + v30;
	*(_BYTE*)(v31 + 7) = *(_BYTE*)(a1 + 769);
	*(_DWORD*)(v31 + 8) = *(_DWORD*)(a1 + 770);
	*(_DWORD*)(v31 + 12) = *(_DWORD*)(a1 + 774);
	*(_DWORD*)(v31 + 16) = *(_DWORD*)(a1 + 778);
	*(_DWORD*)(v31 + 20) = *(_DWORD*)(a1 + 782);
	*(_DWORD*)(v31 + 24) = *(_DWORD*)(a1 + 786);
	*(_DWORD*)(v31 + 28) = *(_DWORD*)(a1 + 790);
	*(_DWORD*)(v31 + 32) = *(_DWORD*)(a1 + 794);
	*(_DWORD*)(v31 + 36) = *(_DWORD*)(a1 + 798);
	v32 = v2 + v31;
	*(_DWORD*)(v32 + 8) = *(_DWORD*)(a1 + 802);
	*(_DWORD*)(v32 + 12) = *(_DWORD*)(a1 + 806);
	*(_DWORD*)(v32 + 16) = *(_DWORD*)(a1 + 810);
	*(_DWORD*)(v32 + 20) = *(_DWORD*)(a1 + 814);
	*(_DWORD*)(v32 + 24) = *(_DWORD*)(a1 + 818);
	*(_DWORD*)(v32 + 28) = *(_DWORD*)(a1 + 822);
	*(_DWORD*)(v32 + 32) = *(_DWORD*)(a1 + 826);
	*(_WORD*)(v32 + 36) = *(_WORD*)(a1 + 830);
	*(_BYTE*)(v32 + 38) = *(_BYTE*)(a1 + 832);
	v33 = v2 + v32;
	*(_BYTE*)(v33 + 9) = *(_BYTE*)(a1 + 833);
	*(_WORD*)(v33 + 10) = *(_WORD*)(a1 + 834);
	*(_DWORD*)(v33 + 12) = *(_DWORD*)(a1 + 836);
	*(_DWORD*)(v33 + 16) = *(_DWORD*)(a1 + 840);
	*(_DWORD*)(v33 + 20) = *(_DWORD*)(a1 + 844);
	*(_DWORD*)(v33 + 24) = *(_DWORD*)(a1 + 848);
	*(_DWORD*)(v33 + 28) = *(_DWORD*)(a1 + 852);
	*(_DWORD*)(v33 + 32) = *(_DWORD*)(a1 + 856);
	*(_WORD*)(v33 + 36) = *(_WORD*)(a1 + 860);
	v34 = v2 + v33;
	*(_WORD*)(v34 + 10) = *(_WORD*)(a1 + 862);
	*(_DWORD*)(v34 + 12) = *(_DWORD*)(a1 + 864);
	*(_DWORD*)(v34 + 16) = *(_DWORD*)(a1 + 868);
	*(_DWORD*)(v34 + 20) = *(_DWORD*)(a1 + 872);
	*(_DWORD*)(v34 + 24) = *(_DWORD*)(a1 + 876);
	*(_DWORD*)(v34 + 28) = *(_DWORD*)(a1 + 880);
	*(_DWORD*)(v34 + 32) = *(_DWORD*)(a1 + 884);
	*(_BYTE*)(v34 + 36) = *(_BYTE*)(a1 + 888);
	v35 = v2 + v34;
	*(_BYTE*)(v35 + 11) = *(_BYTE*)(a1 + 889);
	*(_DWORD*)(v35 + 12) = *(_DWORD*)(a1 + 890);
	*(_DWORD*)(v35 + 16) = *(_DWORD*)(a1 + 894);
	*(_DWORD*)(v35 + 20) = *(_DWORD*)(a1 + 898);
	*(_DWORD*)(v35 + 24) = *(_DWORD*)(a1 + 902);
	*(_DWORD*)(v35 + 28) = *(_DWORD*)(a1 + 906);
	*(_DWORD*)(v35 + 32) = *(_DWORD*)(a1 + 910);
	v36 = v2 + v35;
	*(_DWORD*)(v36 + 12) = *(_DWORD*)(a1 + 914);
	*(_DWORD*)(v36 + 16) = *(_DWORD*)(a1 + 918);
	*(_DWORD*)(v36 + 20) = *(_DWORD*)(a1 + 922);
	*(_DWORD*)(v36 + 24) = *(_DWORD*)(a1 + 926);
	*(_DWORD*)(v36 + 28) = *(_DWORD*)(a1 + 930);
	*(_WORD*)(v36 + 32) = *(_WORD*)(a1 + 934);
	*(_BYTE*)(v36 + 34) = *(_BYTE*)(a1 + 936);
	v37 = v2 + v36;
	*(_BYTE*)(v37 + 13) = *(_BYTE*)(a1 + 937);
	*(_WORD*)(v37 + 14) = *(_WORD*)(a1 + 938);
	*(_DWORD*)(v37 + 16) = *(_DWORD*)(a1 + 940);
	*(_DWORD*)(v37 + 20) = *(_DWORD*)(a1 + 944);
	*(_DWORD*)(v37 + 24) = *(_DWORD*)(a1 + 948);
	*(_DWORD*)(v37 + 28) = *(_DWORD*)(a1 + 952);
	*(_WORD*)(v37 + 32) = *(_WORD*)(a1 + 956);
	v38 = v2 + v37;
	*(_WORD*)(v38 + 14) = *(_WORD*)(a1 + 958);
	*(_DWORD*)(v38 + 16) = *(_DWORD*)(a1 + 960);
	*(_DWORD*)(v38 + 20) = *(_DWORD*)(a1 + 964);
	*(_DWORD*)(v38 + 24) = *(_DWORD*)(a1 + 968);
	*(_DWORD*)(v38 + 28) = *(_DWORD*)(a1 + 972);
	*(_BYTE*)(v38 + 32) = *(_BYTE*)(a1 + 976);
	v39 = v2 + v38;
	*(_BYTE*)(v39 + 15) = *(_BYTE*)(a1 + 977);
	*(_DWORD*)(v39 + 16) = *(_DWORD*)(a1 + 978);
	*(_DWORD*)(v39 + 20) = *(_DWORD*)(a1 + 982);
	*(_DWORD*)(v39 + 24) = *(_DWORD*)(a1 + 986);
	*(_DWORD*)(v39 + 28) = *(_DWORD*)(a1 + 990);
	v40 = v2 + v39;
	*(_DWORD*)(v40 + 16) = *(_DWORD*)(a1 + 994);
	*(_DWORD*)(v40 + 20) = *(_DWORD*)(a1 + 998);
	*(_DWORD*)(v40 + 24) = *(_DWORD*)(a1 + 1002);
	*(_WORD*)(v40 + 28) = *(_WORD*)(a1 + 1006);
	*(_BYTE*)(v40 + 30) = *(_BYTE*)(a1 + 1008);
	v41 = v2 + v40;
	*(_BYTE*)(v41 + 17) = *(_BYTE*)(a1 + 1009);
	*(_WORD*)(v41 + 18) = *(_WORD*)(a1 + 1010);
	*(_DWORD*)(v41 + 20) = *(_DWORD*)(a1 + 1012);
	*(_DWORD*)(v41 + 24) = *(_DWORD*)(a1 + 1016);
	*(_WORD*)(v41 + 28) = *(_WORD*)(a1 + 1020);
	v42 = v2 + v41;
	*(_WORD*)(v42 + 18) = *(_WORD*)(a1 + 1022);
	*(_DWORD*)(v42 + 20) = *(_DWORD*)(a1 + 1024);
	*(_DWORD*)(v42 + 24) = *(_DWORD*)(a1 + 1028);
	*(_BYTE*)(v42 + 28) = *(_BYTE*)(a1 + 1032);
	v43 = v2 + v42;
	*(_BYTE*)(v43 + 19) = *(_BYTE*)(a1 + 1033);
	*(_DWORD*)(v43 + 20) = *(_DWORD*)(a1 + 1034);
	*(_DWORD*)(v43 + 24) = *(_DWORD*)(a1 + 1038);
	v44 = v2 + v43;
	*(_DWORD*)(v44 + 20) = *(_DWORD*)(a1 + 1042);
	*(_WORD*)(v44 + 24) = *(_WORD*)(a1 + 1046);
	*(_BYTE*)(v44 + 26) = *(_BYTE*)(a1 + 1048);
	v45 = v2 + v44;
	*(_BYTE*)(v45 + 21) = *(_BYTE*)(a1 + 1049);
	*(_WORD*)(v45 + 22) = *(_WORD*)(a1 + 1050);
	*(_WORD*)(v45 + 24) = *(_WORD*)(a1 + 1052);
	v46 = v2 + v45;
	*(_WORD*)(v46 + 22) = *(_WORD*)(a1 + 1054);
	result = *(_BYTE*)(a1 + 1056);
	*(_BYTE*)(v46 + 24) = result;
	*(_BYTE*)(v2 + v46 + 23) = *(_BYTE*)(a1 + 1057);
	return result;
}

//----- (004831C0) --------------------------------------------------------
__int16 __cdecl sub_4831C0(int a1, int a2) {
	int v2;         // edx
	int v3;         // edi
	int v4;         // edi
	int v5;         // edi
	int v6;         // edi
	int v7;         // edi
	int v8;         // edi
	int v9;         // edi
	int v10;        // edi
	int v11;        // edi
	int v12;        // edi
	int v13;        // edi
	int v14;        // edi
	int v15;        // edi
	int v16;        // edi
	int v17;        // edi
	int v18;        // edi
	int v19;        // edi
	int v20;        // edi
	int v21;        // edi
	int v22;        // edi
	int v23;        // edi
	int v24;        // edi
	int v25;        // edi
	int v26;        // edi
	int v27;        // edi
	int v28;        // edi
	int v29;        // edi
	int v30;        // edi
	int v31;        // edi
	int v32;        // edi
	int v33;        // edi
	int v34;        // edi
	int v35;        // edi
	int v36;        // edi
	int v37;        // edi
	int v38;        // edi
	int v39;        // edi
	int v40;        // edi
	int v41;        // edi
	int v42;        // edi
	int v43;        // edi
	int v44;        // edi
	int v45;        // edi
	int v46;        // edi
	__int16 result; // ax

	v2 = dword_5d4594_3798804;
	*(_WORD*)(a2 + 46) = *(_WORD*)a1;
	v3 = v2 + a2;
	*(_DWORD*)(v3 + 44) = *(_DWORD*)(a1 + 2);
	*(_WORD*)(v3 + 48) = *(_WORD*)(a1 + 6);
	v4 = v2 + v2 + a2;
	*(_WORD*)(v4 + 42) = *(_WORD*)(a1 + 8);
	*(_DWORD*)(v4 + 44) = *(_DWORD*)(a1 + 10);
	*(_DWORD*)(v4 + 48) = *(_DWORD*)(a1 + 14);
	v5 = v2 + v4;
	*(_DWORD*)(v5 + 40) = *(_DWORD*)(a1 + 18);
	*(_DWORD*)(v5 + 44) = *(_DWORD*)(a1 + 22);
	*(_DWORD*)(v5 + 48) = *(_DWORD*)(a1 + 26);
	*(_WORD*)(v5 + 52) = *(_WORD*)(a1 + 30);
	v6 = v2 + v5;
	*(_WORD*)(v6 + 38) = *(_WORD*)(a1 + 32);
	*(_DWORD*)(v6 + 40) = *(_DWORD*)(a1 + 34);
	*(_DWORD*)(v6 + 44) = *(_DWORD*)(a1 + 38);
	*(_DWORD*)(v6 + 48) = *(_DWORD*)(a1 + 42);
	*(_DWORD*)(v6 + 52) = *(_DWORD*)(a1 + 46);
	v7 = v2 + v6;
	*(_DWORD*)(v7 + 36) = *(_DWORD*)(a1 + 50);
	*(_DWORD*)(v7 + 40) = *(_DWORD*)(a1 + 54);
	*(_DWORD*)(v7 + 44) = *(_DWORD*)(a1 + 58);
	*(_DWORD*)(v7 + 48) = *(_DWORD*)(a1 + 62);
	*(_DWORD*)(v7 + 52) = *(_DWORD*)(a1 + 66);
	*(_WORD*)(v7 + 56) = *(_WORD*)(a1 + 70);
	v8 = v2 + v7;
	*(_WORD*)(v8 + 34) = *(_WORD*)(a1 + 72);
	*(_DWORD*)(v8 + 36) = *(_DWORD*)(a1 + 74);
	*(_DWORD*)(v8 + 40) = *(_DWORD*)(a1 + 78);
	*(_DWORD*)(v8 + 44) = *(_DWORD*)(a1 + 82);
	*(_DWORD*)(v8 + 48) = *(_DWORD*)(a1 + 86);
	*(_DWORD*)(v8 + 52) = *(_DWORD*)(a1 + 90);
	*(_DWORD*)(v8 + 56) = *(_DWORD*)(a1 + 94);
	v9 = v2 + v8;
	*(_DWORD*)(v9 + 32) = *(_DWORD*)(a1 + 98);
	*(_DWORD*)(v9 + 36) = *(_DWORD*)(a1 + 102);
	*(_DWORD*)(v9 + 40) = *(_DWORD*)(a1 + 106);
	*(_DWORD*)(v9 + 44) = *(_DWORD*)(a1 + 110);
	*(_DWORD*)(v9 + 48) = *(_DWORD*)(a1 + 114);
	*(_DWORD*)(v9 + 52) = *(_DWORD*)(a1 + 118);
	*(_DWORD*)(v9 + 56) = *(_DWORD*)(a1 + 122);
	*(_WORD*)(v9 + 60) = *(_WORD*)(a1 + 126);
	v10 = v2 + v9;
	*(_WORD*)(v10 + 30) = *(_WORD*)(a1 + 128);
	*(_DWORD*)(v10 + 32) = *(_DWORD*)(a1 + 130);
	*(_DWORD*)(v10 + 36) = *(_DWORD*)(a1 + 134);
	*(_DWORD*)(v10 + 40) = *(_DWORD*)(a1 + 138);
	*(_DWORD*)(v10 + 44) = *(_DWORD*)(a1 + 142);
	*(_DWORD*)(v10 + 48) = *(_DWORD*)(a1 + 146);
	*(_DWORD*)(v10 + 52) = *(_DWORD*)(a1 + 150);
	*(_DWORD*)(v10 + 56) = *(_DWORD*)(a1 + 154);
	*(_DWORD*)(v10 + 60) = *(_DWORD*)(a1 + 158);
	v11 = v2 + v10;
	*(_DWORD*)(v11 + 28) = *(_DWORD*)(a1 + 162);
	*(_DWORD*)(v11 + 32) = *(_DWORD*)(a1 + 166);
	*(_DWORD*)(v11 + 36) = *(_DWORD*)(a1 + 170);
	*(_DWORD*)(v11 + 40) = *(_DWORD*)(a1 + 174);
	*(_DWORD*)(v11 + 44) = *(_DWORD*)(a1 + 178);
	*(_DWORD*)(v11 + 48) = *(_DWORD*)(a1 + 182);
	*(_DWORD*)(v11 + 52) = *(_DWORD*)(a1 + 186);
	*(_DWORD*)(v11 + 56) = *(_DWORD*)(a1 + 190);
	*(_DWORD*)(v11 + 60) = *(_DWORD*)(a1 + 194);
	*(_WORD*)(v11 + 64) = *(_WORD*)(a1 + 198);
	v12 = v2 + v11;
	*(_WORD*)(v12 + 26) = *(_WORD*)(a1 + 200);
	*(_DWORD*)(v12 + 28) = *(_DWORD*)(a1 + 202);
	*(_DWORD*)(v12 + 32) = *(_DWORD*)(a1 + 206);
	*(_DWORD*)(v12 + 36) = *(_DWORD*)(a1 + 210);
	*(_DWORD*)(v12 + 40) = *(_DWORD*)(a1 + 214);
	*(_DWORD*)(v12 + 44) = *(_DWORD*)(a1 + 218);
	*(_DWORD*)(v12 + 48) = *(_DWORD*)(a1 + 222);
	*(_DWORD*)(v12 + 52) = *(_DWORD*)(a1 + 226);
	*(_DWORD*)(v12 + 56) = *(_DWORD*)(a1 + 230);
	*(_DWORD*)(v12 + 60) = *(_DWORD*)(a1 + 234);
	*(_DWORD*)(v12 + 64) = *(_DWORD*)(a1 + 238);
	v13 = v2 + v12;
	*(_DWORD*)(v13 + 24) = *(_DWORD*)(a1 + 242);
	*(_DWORD*)(v13 + 28) = *(_DWORD*)(a1 + 246);
	*(_DWORD*)(v13 + 32) = *(_DWORD*)(a1 + 250);
	*(_DWORD*)(v13 + 36) = *(_DWORD*)(a1 + 254);
	*(_DWORD*)(v13 + 40) = *(_DWORD*)(a1 + 258);
	*(_DWORD*)(v13 + 44) = *(_DWORD*)(a1 + 262);
	*(_DWORD*)(v13 + 48) = *(_DWORD*)(a1 + 266);
	*(_DWORD*)(v13 + 52) = *(_DWORD*)(a1 + 270);
	*(_DWORD*)(v13 + 56) = *(_DWORD*)(a1 + 274);
	*(_DWORD*)(v13 + 60) = *(_DWORD*)(a1 + 278);
	*(_DWORD*)(v13 + 64) = *(_DWORD*)(a1 + 282);
	*(_WORD*)(v13 + 68) = *(_WORD*)(a1 + 286);
	v14 = v2 + v13;
	*(_WORD*)(v14 + 22) = *(_WORD*)(a1 + 288);
	*(_DWORD*)(v14 + 24) = *(_DWORD*)(a1 + 290);
	*(_DWORD*)(v14 + 28) = *(_DWORD*)(a1 + 294);
	*(_DWORD*)(v14 + 32) = *(_DWORD*)(a1 + 298);
	*(_DWORD*)(v14 + 36) = *(_DWORD*)(a1 + 302);
	*(_DWORD*)(v14 + 40) = *(_DWORD*)(a1 + 306);
	*(_DWORD*)(v14 + 44) = *(_DWORD*)(a1 + 310);
	*(_DWORD*)(v14 + 48) = *(_DWORD*)(a1 + 314);
	*(_DWORD*)(v14 + 52) = *(_DWORD*)(a1 + 318);
	*(_DWORD*)(v14 + 56) = *(_DWORD*)(a1 + 322);
	*(_DWORD*)(v14 + 60) = *(_DWORD*)(a1 + 326);
	*(_DWORD*)(v14 + 64) = *(_DWORD*)(a1 + 330);
	*(_DWORD*)(v14 + 68) = *(_DWORD*)(a1 + 334);
	v15 = v2 + v14;
	*(_DWORD*)(v15 + 20) = *(_DWORD*)(a1 + 338);
	*(_DWORD*)(v15 + 24) = *(_DWORD*)(a1 + 342);
	*(_DWORD*)(v15 + 28) = *(_DWORD*)(a1 + 346);
	*(_DWORD*)(v15 + 32) = *(_DWORD*)(a1 + 350);
	*(_DWORD*)(v15 + 36) = *(_DWORD*)(a1 + 354);
	*(_DWORD*)(v15 + 40) = *(_DWORD*)(a1 + 358);
	*(_DWORD*)(v15 + 44) = *(_DWORD*)(a1 + 362);
	*(_DWORD*)(v15 + 48) = *(_DWORD*)(a1 + 366);
	*(_DWORD*)(v15 + 52) = *(_DWORD*)(a1 + 370);
	*(_DWORD*)(v15 + 56) = *(_DWORD*)(a1 + 374);
	*(_DWORD*)(v15 + 60) = *(_DWORD*)(a1 + 378);
	*(_DWORD*)(v15 + 64) = *(_DWORD*)(a1 + 382);
	*(_DWORD*)(v15 + 68) = *(_DWORD*)(a1 + 386);
	*(_WORD*)(v15 + 72) = *(_WORD*)(a1 + 390);
	v16 = v2 + v15;
	*(_WORD*)(v16 + 18) = *(_WORD*)(a1 + 392);
	*(_DWORD*)(v16 + 20) = *(_DWORD*)(a1 + 394);
	*(_DWORD*)(v16 + 24) = *(_DWORD*)(a1 + 398);
	*(_DWORD*)(v16 + 28) = *(_DWORD*)(a1 + 402);
	*(_DWORD*)(v16 + 32) = *(_DWORD*)(a1 + 406);
	*(_DWORD*)(v16 + 36) = *(_DWORD*)(a1 + 410);
	*(_DWORD*)(v16 + 40) = *(_DWORD*)(a1 + 414);
	*(_DWORD*)(v16 + 44) = *(_DWORD*)(a1 + 418);
	*(_DWORD*)(v16 + 48) = *(_DWORD*)(a1 + 422);
	*(_DWORD*)(v16 + 52) = *(_DWORD*)(a1 + 426);
	*(_DWORD*)(v16 + 56) = *(_DWORD*)(a1 + 430);
	*(_DWORD*)(v16 + 60) = *(_DWORD*)(a1 + 434);
	*(_DWORD*)(v16 + 64) = *(_DWORD*)(a1 + 438);
	*(_DWORD*)(v16 + 68) = *(_DWORD*)(a1 + 442);
	*(_DWORD*)(v16 + 72) = *(_DWORD*)(a1 + 446);
	v17 = v2 + v16;
	*(_DWORD*)(v17 + 16) = *(_DWORD*)(a1 + 450);
	*(_DWORD*)(v17 + 20) = *(_DWORD*)(a1 + 454);
	*(_DWORD*)(v17 + 24) = *(_DWORD*)(a1 + 458);
	*(_DWORD*)(v17 + 28) = *(_DWORD*)(a1 + 462);
	*(_DWORD*)(v17 + 32) = *(_DWORD*)(a1 + 466);
	*(_DWORD*)(v17 + 36) = *(_DWORD*)(a1 + 470);
	*(_DWORD*)(v17 + 40) = *(_DWORD*)(a1 + 474);
	*(_DWORD*)(v17 + 44) = *(_DWORD*)(a1 + 478);
	*(_DWORD*)(v17 + 48) = *(_DWORD*)(a1 + 482);
	*(_DWORD*)(v17 + 52) = *(_DWORD*)(a1 + 486);
	*(_DWORD*)(v17 + 56) = *(_DWORD*)(a1 + 490);
	*(_DWORD*)(v17 + 60) = *(_DWORD*)(a1 + 494);
	*(_DWORD*)(v17 + 64) = *(_DWORD*)(a1 + 498);
	*(_DWORD*)(v17 + 68) = *(_DWORD*)(a1 + 502);
	*(_DWORD*)(v17 + 72) = *(_DWORD*)(a1 + 506);
	*(_WORD*)(v17 + 76) = *(_WORD*)(a1 + 510);
	v18 = v2 + v17;
	*(_WORD*)(v18 + 14) = *(_WORD*)(a1 + 512);
	*(_DWORD*)(v18 + 16) = *(_DWORD*)(a1 + 514);
	*(_DWORD*)(v18 + 20) = *(_DWORD*)(a1 + 518);
	*(_DWORD*)(v18 + 24) = *(_DWORD*)(a1 + 522);
	*(_DWORD*)(v18 + 28) = *(_DWORD*)(a1 + 526);
	*(_DWORD*)(v18 + 32) = *(_DWORD*)(a1 + 530);
	*(_DWORD*)(v18 + 36) = *(_DWORD*)(a1 + 534);
	*(_DWORD*)(v18 + 40) = *(_DWORD*)(a1 + 538);
	*(_DWORD*)(v18 + 44) = *(_DWORD*)(a1 + 542);
	*(_DWORD*)(v18 + 48) = *(_DWORD*)(a1 + 546);
	*(_DWORD*)(v18 + 52) = *(_DWORD*)(a1 + 550);
	*(_DWORD*)(v18 + 56) = *(_DWORD*)(a1 + 554);
	*(_DWORD*)(v18 + 60) = *(_DWORD*)(a1 + 558);
	*(_DWORD*)(v18 + 64) = *(_DWORD*)(a1 + 562);
	*(_DWORD*)(v18 + 68) = *(_DWORD*)(a1 + 566);
	*(_DWORD*)(v18 + 72) = *(_DWORD*)(a1 + 570);
	*(_DWORD*)(v18 + 76) = *(_DWORD*)(a1 + 574);
	v19 = v2 + v18;
	*(_DWORD*)(v19 + 12) = *(_DWORD*)(a1 + 578);
	*(_DWORD*)(v19 + 16) = *(_DWORD*)(a1 + 582);
	*(_DWORD*)(v19 + 20) = *(_DWORD*)(a1 + 586);
	*(_DWORD*)(v19 + 24) = *(_DWORD*)(a1 + 590);
	*(_DWORD*)(v19 + 28) = *(_DWORD*)(a1 + 594);
	*(_DWORD*)(v19 + 32) = *(_DWORD*)(a1 + 598);
	*(_DWORD*)(v19 + 36) = *(_DWORD*)(a1 + 602);
	*(_DWORD*)(v19 + 40) = *(_DWORD*)(a1 + 606);
	*(_DWORD*)(v19 + 44) = *(_DWORD*)(a1 + 610);
	*(_DWORD*)(v19 + 48) = *(_DWORD*)(a1 + 614);
	*(_DWORD*)(v19 + 52) = *(_DWORD*)(a1 + 618);
	*(_DWORD*)(v19 + 56) = *(_DWORD*)(a1 + 622);
	*(_DWORD*)(v19 + 60) = *(_DWORD*)(a1 + 626);
	*(_DWORD*)(v19 + 64) = *(_DWORD*)(a1 + 630);
	*(_DWORD*)(v19 + 68) = *(_DWORD*)(a1 + 634);
	*(_DWORD*)(v19 + 72) = *(_DWORD*)(a1 + 638);
	*(_DWORD*)(v19 + 76) = *(_DWORD*)(a1 + 642);
	*(_WORD*)(v19 + 80) = *(_WORD*)(a1 + 646);
	v20 = v2 + v19;
	*(_WORD*)(v20 + 10) = *(_WORD*)(a1 + 648);
	*(_DWORD*)(v20 + 12) = *(_DWORD*)(a1 + 650);
	*(_DWORD*)(v20 + 16) = *(_DWORD*)(a1 + 654);
	*(_DWORD*)(v20 + 20) = *(_DWORD*)(a1 + 658);
	*(_DWORD*)(v20 + 24) = *(_DWORD*)(a1 + 662);
	*(_DWORD*)(v20 + 28) = *(_DWORD*)(a1 + 666);
	*(_DWORD*)(v20 + 32) = *(_DWORD*)(a1 + 670);
	*(_DWORD*)(v20 + 36) = *(_DWORD*)(a1 + 674);
	*(_DWORD*)(v20 + 40) = *(_DWORD*)(a1 + 678);
	*(_DWORD*)(v20 + 44) = *(_DWORD*)(a1 + 682);
	*(_DWORD*)(v20 + 48) = *(_DWORD*)(a1 + 686);
	*(_DWORD*)(v20 + 52) = *(_DWORD*)(a1 + 690);
	*(_DWORD*)(v20 + 56) = *(_DWORD*)(a1 + 694);
	*(_DWORD*)(v20 + 60) = *(_DWORD*)(a1 + 698);
	*(_DWORD*)(v20 + 64) = *(_DWORD*)(a1 + 702);
	*(_DWORD*)(v20 + 68) = *(_DWORD*)(a1 + 706);
	*(_DWORD*)(v20 + 72) = *(_DWORD*)(a1 + 710);
	*(_DWORD*)(v20 + 76) = *(_DWORD*)(a1 + 714);
	*(_DWORD*)(v20 + 80) = *(_DWORD*)(a1 + 718);
	v21 = v2 + v20;
	*(_DWORD*)(v21 + 8) = *(_DWORD*)(a1 + 722);
	*(_DWORD*)(v21 + 12) = *(_DWORD*)(a1 + 726);
	*(_DWORD*)(v21 + 16) = *(_DWORD*)(a1 + 730);
	*(_DWORD*)(v21 + 20) = *(_DWORD*)(a1 + 734);
	*(_DWORD*)(v21 + 24) = *(_DWORD*)(a1 + 738);
	*(_DWORD*)(v21 + 28) = *(_DWORD*)(a1 + 742);
	*(_DWORD*)(v21 + 32) = *(_DWORD*)(a1 + 746);
	*(_DWORD*)(v21 + 36) = *(_DWORD*)(a1 + 750);
	*(_DWORD*)(v21 + 40) = *(_DWORD*)(a1 + 754);
	*(_DWORD*)(v21 + 44) = *(_DWORD*)(a1 + 758);
	*(_DWORD*)(v21 + 48) = *(_DWORD*)(a1 + 762);
	*(_DWORD*)(v21 + 52) = *(_DWORD*)(a1 + 766);
	*(_DWORD*)(v21 + 56) = *(_DWORD*)(a1 + 770);
	*(_DWORD*)(v21 + 60) = *(_DWORD*)(a1 + 774);
	*(_DWORD*)(v21 + 64) = *(_DWORD*)(a1 + 778);
	*(_DWORD*)(v21 + 68) = *(_DWORD*)(a1 + 782);
	*(_DWORD*)(v21 + 72) = *(_DWORD*)(a1 + 786);
	*(_DWORD*)(v21 + 76) = *(_DWORD*)(a1 + 790);
	*(_DWORD*)(v21 + 80) = *(_DWORD*)(a1 + 794);
	*(_WORD*)(v21 + 84) = *(_WORD*)(a1 + 798);
	v22 = v2 + v21;
	*(_WORD*)(v22 + 6) = *(_WORD*)(a1 + 800);
	*(_DWORD*)(v22 + 8) = *(_DWORD*)(a1 + 802);
	*(_DWORD*)(v22 + 12) = *(_DWORD*)(a1 + 806);
	*(_DWORD*)(v22 + 16) = *(_DWORD*)(a1 + 810);
	*(_DWORD*)(v22 + 20) = *(_DWORD*)(a1 + 814);
	*(_DWORD*)(v22 + 24) = *(_DWORD*)(a1 + 818);
	*(_DWORD*)(v22 + 28) = *(_DWORD*)(a1 + 822);
	*(_DWORD*)(v22 + 32) = *(_DWORD*)(a1 + 826);
	*(_DWORD*)(v22 + 36) = *(_DWORD*)(a1 + 830);
	*(_DWORD*)(v22 + 40) = *(_DWORD*)(a1 + 834);
	*(_DWORD*)(v22 + 44) = *(_DWORD*)(a1 + 838);
	*(_DWORD*)(v22 + 48) = *(_DWORD*)(a1 + 842);
	*(_DWORD*)(v22 + 52) = *(_DWORD*)(a1 + 846);
	*(_DWORD*)(v22 + 56) = *(_DWORD*)(a1 + 850);
	*(_DWORD*)(v22 + 60) = *(_DWORD*)(a1 + 854);
	*(_DWORD*)(v22 + 64) = *(_DWORD*)(a1 + 858);
	*(_DWORD*)(v22 + 68) = *(_DWORD*)(a1 + 862);
	*(_DWORD*)(v22 + 72) = *(_DWORD*)(a1 + 866);
	*(_DWORD*)(v22 + 76) = *(_DWORD*)(a1 + 870);
	*(_DWORD*)(v22 + 80) = *(_DWORD*)(a1 + 874);
	*(_DWORD*)(v22 + 84) = *(_DWORD*)(a1 + 878);
	v23 = v2 + v22;
	*(_DWORD*)(v23 + 4) = *(_DWORD*)(a1 + 882);
	*(_DWORD*)(v23 + 8) = *(_DWORD*)(a1 + 886);
	*(_DWORD*)(v23 + 12) = *(_DWORD*)(a1 + 890);
	*(_DWORD*)(v23 + 16) = *(_DWORD*)(a1 + 894);
	*(_DWORD*)(v23 + 20) = *(_DWORD*)(a1 + 898);
	*(_DWORD*)(v23 + 24) = *(_DWORD*)(a1 + 902);
	*(_DWORD*)(v23 + 28) = *(_DWORD*)(a1 + 906);
	*(_DWORD*)(v23 + 32) = *(_DWORD*)(a1 + 910);
	*(_DWORD*)(v23 + 36) = *(_DWORD*)(a1 + 914);
	*(_DWORD*)(v23 + 40) = *(_DWORD*)(a1 + 918);
	*(_DWORD*)(v23 + 44) = *(_DWORD*)(a1 + 922);
	*(_DWORD*)(v23 + 48) = *(_DWORD*)(a1 + 926);
	*(_DWORD*)(v23 + 52) = *(_DWORD*)(a1 + 930);
	*(_DWORD*)(v23 + 56) = *(_DWORD*)(a1 + 934);
	*(_DWORD*)(v23 + 60) = *(_DWORD*)(a1 + 938);
	*(_DWORD*)(v23 + 64) = *(_DWORD*)(a1 + 942);
	*(_DWORD*)(v23 + 68) = *(_DWORD*)(a1 + 946);
	*(_DWORD*)(v23 + 72) = *(_DWORD*)(a1 + 950);
	*(_DWORD*)(v23 + 76) = *(_DWORD*)(a1 + 954);
	*(_DWORD*)(v23 + 80) = *(_DWORD*)(a1 + 958);
	*(_DWORD*)(v23 + 84) = *(_DWORD*)(a1 + 962);
	*(_WORD*)(v23 + 88) = *(_WORD*)(a1 + 966);
	v24 = v2 + v23;
	*(_WORD*)(v24 + 2) = *(_WORD*)(a1 + 968);
	*(_DWORD*)(v24 + 4) = *(_DWORD*)(a1 + 970);
	*(_DWORD*)(v24 + 8) = *(_DWORD*)(a1 + 974);
	*(_DWORD*)(v24 + 12) = *(_DWORD*)(a1 + 978);
	*(_DWORD*)(v24 + 16) = *(_DWORD*)(a1 + 982);
	*(_DWORD*)(v24 + 20) = *(_DWORD*)(a1 + 986);
	*(_DWORD*)(v24 + 24) = *(_DWORD*)(a1 + 990);
	*(_DWORD*)(v24 + 28) = *(_DWORD*)(a1 + 994);
	*(_DWORD*)(v24 + 32) = *(_DWORD*)(a1 + 998);
	*(_DWORD*)(v24 + 36) = *(_DWORD*)(a1 + 1002);
	*(_DWORD*)(v24 + 40) = *(_DWORD*)(a1 + 1006);
	*(_DWORD*)(v24 + 44) = *(_DWORD*)(a1 + 1010);
	*(_DWORD*)(v24 + 48) = *(_DWORD*)(a1 + 1014);
	*(_DWORD*)(v24 + 52) = *(_DWORD*)(a1 + 1018);
	*(_DWORD*)(v24 + 56) = *(_DWORD*)(a1 + 1022);
	*(_DWORD*)(v24 + 60) = *(_DWORD*)(a1 + 1026);
	*(_DWORD*)(v24 + 64) = *(_DWORD*)(a1 + 1030);
	*(_DWORD*)(v24 + 68) = *(_DWORD*)(a1 + 1034);
	*(_DWORD*)(v24 + 72) = *(_DWORD*)(a1 + 1038);
	*(_DWORD*)(v24 + 76) = *(_DWORD*)(a1 + 1042);
	*(_DWORD*)(v24 + 80) = *(_DWORD*)(a1 + 1046);
	*(_DWORD*)(v24 + 84) = *(_DWORD*)(a1 + 1050);
	*(_DWORD*)(v24 + 88) = *(_DWORD*)(a1 + 1054);
	v25 = v2 + v24;
	*(_WORD*)(v25 + 2) = *(_WORD*)(a1 + 1058);
	*(_DWORD*)(v25 + 4) = *(_DWORD*)(a1 + 1060);
	*(_DWORD*)(v25 + 8) = *(_DWORD*)(a1 + 1064);
	*(_DWORD*)(v25 + 12) = *(_DWORD*)(a1 + 1068);
	*(_DWORD*)(v25 + 16) = *(_DWORD*)(a1 + 1072);
	*(_DWORD*)(v25 + 20) = *(_DWORD*)(a1 + 1076);
	*(_DWORD*)(v25 + 24) = *(_DWORD*)(a1 + 1080);
	*(_DWORD*)(v25 + 28) = *(_DWORD*)(a1 + 1084);
	*(_DWORD*)(v25 + 32) = *(_DWORD*)(a1 + 1088);
	*(_DWORD*)(v25 + 36) = *(_DWORD*)(a1 + 1092);
	*(_DWORD*)(v25 + 40) = *(_DWORD*)(a1 + 1096);
	*(_DWORD*)(v25 + 44) = *(_DWORD*)(a1 + 1100);
	*(_DWORD*)(v25 + 48) = *(_DWORD*)(a1 + 1104);
	*(_DWORD*)(v25 + 52) = *(_DWORD*)(a1 + 1108);
	*(_DWORD*)(v25 + 56) = *(_DWORD*)(a1 + 1112);
	*(_DWORD*)(v25 + 60) = *(_DWORD*)(a1 + 1116);
	*(_DWORD*)(v25 + 64) = *(_DWORD*)(a1 + 1120);
	*(_DWORD*)(v25 + 68) = *(_DWORD*)(a1 + 1124);
	*(_DWORD*)(v25 + 72) = *(_DWORD*)(a1 + 1128);
	*(_DWORD*)(v25 + 76) = *(_DWORD*)(a1 + 1132);
	*(_DWORD*)(v25 + 80) = *(_DWORD*)(a1 + 1136);
	*(_DWORD*)(v25 + 84) = *(_DWORD*)(a1 + 1140);
	*(_DWORD*)(v25 + 88) = *(_DWORD*)(a1 + 1144);
	v26 = v2 + v25;
	*(_DWORD*)(v26 + 4) = *(_DWORD*)(a1 + 1148);
	*(_DWORD*)(v26 + 8) = *(_DWORD*)(a1 + 1152);
	*(_DWORD*)(v26 + 12) = *(_DWORD*)(a1 + 1156);
	*(_DWORD*)(v26 + 16) = *(_DWORD*)(a1 + 1160);
	*(_DWORD*)(v26 + 20) = *(_DWORD*)(a1 + 1164);
	*(_DWORD*)(v26 + 24) = *(_DWORD*)(a1 + 1168);
	*(_DWORD*)(v26 + 28) = *(_DWORD*)(a1 + 1172);
	*(_DWORD*)(v26 + 32) = *(_DWORD*)(a1 + 1176);
	*(_DWORD*)(v26 + 36) = *(_DWORD*)(a1 + 1180);
	*(_DWORD*)(v26 + 40) = *(_DWORD*)(a1 + 1184);
	*(_DWORD*)(v26 + 44) = *(_DWORD*)(a1 + 1188);
	*(_DWORD*)(v26 + 48) = *(_DWORD*)(a1 + 1192);
	*(_DWORD*)(v26 + 52) = *(_DWORD*)(a1 + 1196);
	*(_DWORD*)(v26 + 56) = *(_DWORD*)(a1 + 1200);
	*(_DWORD*)(v26 + 60) = *(_DWORD*)(a1 + 1204);
	*(_DWORD*)(v26 + 64) = *(_DWORD*)(a1 + 1208);
	*(_DWORD*)(v26 + 68) = *(_DWORD*)(a1 + 1212);
	*(_DWORD*)(v26 + 72) = *(_DWORD*)(a1 + 1216);
	*(_DWORD*)(v26 + 76) = *(_DWORD*)(a1 + 1220);
	*(_DWORD*)(v26 + 80) = *(_DWORD*)(a1 + 1224);
	*(_DWORD*)(v26 + 84) = *(_DWORD*)(a1 + 1228);
	*(_WORD*)(v26 + 88) = *(_WORD*)(a1 + 1232);
	v27 = v2 + v26;
	*(_WORD*)(v27 + 6) = *(_WORD*)(a1 + 1234);
	*(_DWORD*)(v27 + 8) = *(_DWORD*)(a1 + 1236);
	*(_DWORD*)(v27 + 12) = *(_DWORD*)(a1 + 1240);
	*(_DWORD*)(v27 + 16) = *(_DWORD*)(a1 + 1244);
	*(_DWORD*)(v27 + 20) = *(_DWORD*)(a1 + 1248);
	*(_DWORD*)(v27 + 24) = *(_DWORD*)(a1 + 1252);
	*(_DWORD*)(v27 + 28) = *(_DWORD*)(a1 + 1256);
	*(_DWORD*)(v27 + 32) = *(_DWORD*)(a1 + 1260);
	*(_DWORD*)(v27 + 36) = *(_DWORD*)(a1 + 1264);
	*(_DWORD*)(v27 + 40) = *(_DWORD*)(a1 + 1268);
	*(_DWORD*)(v27 + 44) = *(_DWORD*)(a1 + 1272);
	*(_DWORD*)(v27 + 48) = *(_DWORD*)(a1 + 1276);
	*(_DWORD*)(v27 + 52) = *(_DWORD*)(a1 + 1280);
	*(_DWORD*)(v27 + 56) = *(_DWORD*)(a1 + 1284);
	*(_DWORD*)(v27 + 60) = *(_DWORD*)(a1 + 1288);
	*(_DWORD*)(v27 + 64) = *(_DWORD*)(a1 + 1292);
	*(_DWORD*)(v27 + 68) = *(_DWORD*)(a1 + 1296);
	*(_DWORD*)(v27 + 72) = *(_DWORD*)(a1 + 1300);
	*(_DWORD*)(v27 + 76) = *(_DWORD*)(a1 + 1304);
	*(_DWORD*)(v27 + 80) = *(_DWORD*)(a1 + 1308);
	*(_DWORD*)(v27 + 84) = *(_DWORD*)(a1 + 1312);
	v28 = v2 + v27;
	*(_DWORD*)(v28 + 8) = *(_DWORD*)(a1 + 1316);
	*(_DWORD*)(v28 + 12) = *(_DWORD*)(a1 + 1320);
	*(_DWORD*)(v28 + 16) = *(_DWORD*)(a1 + 1324);
	*(_DWORD*)(v28 + 20) = *(_DWORD*)(a1 + 1328);
	*(_DWORD*)(v28 + 24) = *(_DWORD*)(a1 + 1332);
	*(_DWORD*)(v28 + 28) = *(_DWORD*)(a1 + 1336);
	*(_DWORD*)(v28 + 32) = *(_DWORD*)(a1 + 1340);
	*(_DWORD*)(v28 + 36) = *(_DWORD*)(a1 + 1344);
	*(_DWORD*)(v28 + 40) = *(_DWORD*)(a1 + 1348);
	*(_DWORD*)(v28 + 44) = *(_DWORD*)(a1 + 1352);
	*(_DWORD*)(v28 + 48) = *(_DWORD*)(a1 + 1356);
	*(_DWORD*)(v28 + 52) = *(_DWORD*)(a1 + 1360);
	*(_DWORD*)(v28 + 56) = *(_DWORD*)(a1 + 1364);
	*(_DWORD*)(v28 + 60) = *(_DWORD*)(a1 + 1368);
	*(_DWORD*)(v28 + 64) = *(_DWORD*)(a1 + 1372);
	*(_DWORD*)(v28 + 68) = *(_DWORD*)(a1 + 1376);
	*(_DWORD*)(v28 + 72) = *(_DWORD*)(a1 + 1380);
	*(_DWORD*)(v28 + 76) = *(_DWORD*)(a1 + 1384);
	*(_DWORD*)(v28 + 80) = *(_DWORD*)(a1 + 1388);
	*(_WORD*)(v28 + 84) = *(_WORD*)(a1 + 1392);
	v29 = v2 + v28;
	*(_WORD*)(v29 + 10) = *(_WORD*)(a1 + 1394);
	*(_DWORD*)(v29 + 12) = *(_DWORD*)(a1 + 1396);
	*(_DWORD*)(v29 + 16) = *(_DWORD*)(a1 + 1400);
	*(_DWORD*)(v29 + 20) = *(_DWORD*)(a1 + 1404);
	*(_DWORD*)(v29 + 24) = *(_DWORD*)(a1 + 1408);
	*(_DWORD*)(v29 + 28) = *(_DWORD*)(a1 + 1412);
	*(_DWORD*)(v29 + 32) = *(_DWORD*)(a1 + 1416);
	*(_DWORD*)(v29 + 36) = *(_DWORD*)(a1 + 1420);
	*(_DWORD*)(v29 + 40) = *(_DWORD*)(a1 + 1424);
	*(_DWORD*)(v29 + 44) = *(_DWORD*)(a1 + 1428);
	*(_DWORD*)(v29 + 48) = *(_DWORD*)(a1 + 1432);
	*(_DWORD*)(v29 + 52) = *(_DWORD*)(a1 + 1436);
	*(_DWORD*)(v29 + 56) = *(_DWORD*)(a1 + 1440);
	*(_DWORD*)(v29 + 60) = *(_DWORD*)(a1 + 1444);
	*(_DWORD*)(v29 + 64) = *(_DWORD*)(a1 + 1448);
	*(_DWORD*)(v29 + 68) = *(_DWORD*)(a1 + 1452);
	*(_DWORD*)(v29 + 72) = *(_DWORD*)(a1 + 1456);
	*(_DWORD*)(v29 + 76) = *(_DWORD*)(a1 + 1460);
	*(_DWORD*)(v29 + 80) = *(_DWORD*)(a1 + 1464);
	v30 = v2 + v29;
	*(_DWORD*)(v30 + 12) = *(_DWORD*)(a1 + 1468);
	*(_DWORD*)(v30 + 16) = *(_DWORD*)(a1 + 1472);
	*(_DWORD*)(v30 + 20) = *(_DWORD*)(a1 + 1476);
	*(_DWORD*)(v30 + 24) = *(_DWORD*)(a1 + 1480);
	*(_DWORD*)(v30 + 28) = *(_DWORD*)(a1 + 1484);
	*(_DWORD*)(v30 + 32) = *(_DWORD*)(a1 + 1488);
	*(_DWORD*)(v30 + 36) = *(_DWORD*)(a1 + 1492);
	*(_DWORD*)(v30 + 40) = *(_DWORD*)(a1 + 1496);
	*(_DWORD*)(v30 + 44) = *(_DWORD*)(a1 + 1500);
	*(_DWORD*)(v30 + 48) = *(_DWORD*)(a1 + 1504);
	*(_DWORD*)(v30 + 52) = *(_DWORD*)(a1 + 1508);
	*(_DWORD*)(v30 + 56) = *(_DWORD*)(a1 + 1512);
	*(_DWORD*)(v30 + 60) = *(_DWORD*)(a1 + 1516);
	*(_DWORD*)(v30 + 64) = *(_DWORD*)(a1 + 1520);
	*(_DWORD*)(v30 + 68) = *(_DWORD*)(a1 + 1524);
	*(_DWORD*)(v30 + 72) = *(_DWORD*)(a1 + 1528);
	*(_DWORD*)(v30 + 76) = *(_DWORD*)(a1 + 1532);
	*(_WORD*)(v30 + 80) = *(_WORD*)(a1 + 1536);
	v31 = v2 + v30;
	*(_WORD*)(v31 + 14) = *(_WORD*)(a1 + 1538);
	*(_DWORD*)(v31 + 16) = *(_DWORD*)(a1 + 1540);
	*(_DWORD*)(v31 + 20) = *(_DWORD*)(a1 + 1544);
	*(_DWORD*)(v31 + 24) = *(_DWORD*)(a1 + 1548);
	*(_DWORD*)(v31 + 28) = *(_DWORD*)(a1 + 1552);
	*(_DWORD*)(v31 + 32) = *(_DWORD*)(a1 + 1556);
	*(_DWORD*)(v31 + 36) = *(_DWORD*)(a1 + 1560);
	*(_DWORD*)(v31 + 40) = *(_DWORD*)(a1 + 1564);
	*(_DWORD*)(v31 + 44) = *(_DWORD*)(a1 + 1568);
	*(_DWORD*)(v31 + 48) = *(_DWORD*)(a1 + 1572);
	*(_DWORD*)(v31 + 52) = *(_DWORD*)(a1 + 1576);
	*(_DWORD*)(v31 + 56) = *(_DWORD*)(a1 + 1580);
	*(_DWORD*)(v31 + 60) = *(_DWORD*)(a1 + 1584);
	*(_DWORD*)(v31 + 64) = *(_DWORD*)(a1 + 1588);
	*(_DWORD*)(v31 + 68) = *(_DWORD*)(a1 + 1592);
	*(_DWORD*)(v31 + 72) = *(_DWORD*)(a1 + 1596);
	*(_DWORD*)(v31 + 76) = *(_DWORD*)(a1 + 1600);
	v32 = v2 + v31;
	*(_DWORD*)(v32 + 16) = *(_DWORD*)(a1 + 1604);
	*(_DWORD*)(v32 + 20) = *(_DWORD*)(a1 + 1608);
	*(_DWORD*)(v32 + 24) = *(_DWORD*)(a1 + 1612);
	*(_DWORD*)(v32 + 28) = *(_DWORD*)(a1 + 1616);
	*(_DWORD*)(v32 + 32) = *(_DWORD*)(a1 + 1620);
	*(_DWORD*)(v32 + 36) = *(_DWORD*)(a1 + 1624);
	*(_DWORD*)(v32 + 40) = *(_DWORD*)(a1 + 1628);
	*(_DWORD*)(v32 + 44) = *(_DWORD*)(a1 + 1632);
	*(_DWORD*)(v32 + 48) = *(_DWORD*)(a1 + 1636);
	*(_DWORD*)(v32 + 52) = *(_DWORD*)(a1 + 1640);
	*(_DWORD*)(v32 + 56) = *(_DWORD*)(a1 + 1644);
	*(_DWORD*)(v32 + 60) = *(_DWORD*)(a1 + 1648);
	*(_DWORD*)(v32 + 64) = *(_DWORD*)(a1 + 1652);
	*(_DWORD*)(v32 + 68) = *(_DWORD*)(a1 + 1656);
	*(_DWORD*)(v32 + 72) = *(_DWORD*)(a1 + 1660);
	*(_WORD*)(v32 + 76) = *(_WORD*)(a1 + 1664);
	v33 = v2 + v32;
	*(_WORD*)(v33 + 18) = *(_WORD*)(a1 + 1666);
	*(_DWORD*)(v33 + 20) = *(_DWORD*)(a1 + 1668);
	*(_DWORD*)(v33 + 24) = *(_DWORD*)(a1 + 1672);
	*(_DWORD*)(v33 + 28) = *(_DWORD*)(a1 + 1676);
	*(_DWORD*)(v33 + 32) = *(_DWORD*)(a1 + 1680);
	*(_DWORD*)(v33 + 36) = *(_DWORD*)(a1 + 1684);
	*(_DWORD*)(v33 + 40) = *(_DWORD*)(a1 + 1688);
	*(_DWORD*)(v33 + 44) = *(_DWORD*)(a1 + 1692);
	*(_DWORD*)(v33 + 48) = *(_DWORD*)(a1 + 1696);
	*(_DWORD*)(v33 + 52) = *(_DWORD*)(a1 + 1700);
	*(_DWORD*)(v33 + 56) = *(_DWORD*)(a1 + 1704);
	*(_DWORD*)(v33 + 60) = *(_DWORD*)(a1 + 1708);
	*(_DWORD*)(v33 + 64) = *(_DWORD*)(a1 + 1712);
	*(_DWORD*)(v33 + 68) = *(_DWORD*)(a1 + 1716);
	*(_DWORD*)(v33 + 72) = *(_DWORD*)(a1 + 1720);
	v34 = v2 + v33;
	*(_DWORD*)(v34 + 20) = *(_DWORD*)(a1 + 1724);
	*(_DWORD*)(v34 + 24) = *(_DWORD*)(a1 + 1728);
	*(_DWORD*)(v34 + 28) = *(_DWORD*)(a1 + 1732);
	*(_DWORD*)(v34 + 32) = *(_DWORD*)(a1 + 1736);
	*(_DWORD*)(v34 + 36) = *(_DWORD*)(a1 + 1740);
	*(_DWORD*)(v34 + 40) = *(_DWORD*)(a1 + 1744);
	*(_DWORD*)(v34 + 44) = *(_DWORD*)(a1 + 1748);
	*(_DWORD*)(v34 + 48) = *(_DWORD*)(a1 + 1752);
	*(_DWORD*)(v34 + 52) = *(_DWORD*)(a1 + 1756);
	*(_DWORD*)(v34 + 56) = *(_DWORD*)(a1 + 1760);
	*(_DWORD*)(v34 + 60) = *(_DWORD*)(a1 + 1764);
	*(_DWORD*)(v34 + 64) = *(_DWORD*)(a1 + 1768);
	*(_DWORD*)(v34 + 68) = *(_DWORD*)(a1 + 1772);
	*(_WORD*)(v34 + 72) = *(_WORD*)(a1 + 1776);
	v35 = v2 + v34;
	*(_WORD*)(v35 + 22) = *(_WORD*)(a1 + 1778);
	*(_DWORD*)(v35 + 24) = *(_DWORD*)(a1 + 1780);
	*(_DWORD*)(v35 + 28) = *(_DWORD*)(a1 + 1784);
	*(_DWORD*)(v35 + 32) = *(_DWORD*)(a1 + 1788);
	*(_DWORD*)(v35 + 36) = *(_DWORD*)(a1 + 1792);
	*(_DWORD*)(v35 + 40) = *(_DWORD*)(a1 + 1796);
	*(_DWORD*)(v35 + 44) = *(_DWORD*)(a1 + 1800);
	*(_DWORD*)(v35 + 48) = *(_DWORD*)(a1 + 1804);
	*(_DWORD*)(v35 + 52) = *(_DWORD*)(a1 + 1808);
	*(_DWORD*)(v35 + 56) = *(_DWORD*)(a1 + 1812);
	*(_DWORD*)(v35 + 60) = *(_DWORD*)(a1 + 1816);
	*(_DWORD*)(v35 + 64) = *(_DWORD*)(a1 + 1820);
	*(_DWORD*)(v35 + 68) = *(_DWORD*)(a1 + 1824);
	v36 = v2 + v35;
	*(_DWORD*)(v36 + 24) = *(_DWORD*)(a1 + 1828);
	*(_DWORD*)(v36 + 28) = *(_DWORD*)(a1 + 1832);
	*(_DWORD*)(v36 + 32) = *(_DWORD*)(a1 + 1836);
	*(_DWORD*)(v36 + 36) = *(_DWORD*)(a1 + 1840);
	*(_DWORD*)(v36 + 40) = *(_DWORD*)(a1 + 1844);
	*(_DWORD*)(v36 + 44) = *(_DWORD*)(a1 + 1848);
	*(_DWORD*)(v36 + 48) = *(_DWORD*)(a1 + 1852);
	*(_DWORD*)(v36 + 52) = *(_DWORD*)(a1 + 1856);
	*(_DWORD*)(v36 + 56) = *(_DWORD*)(a1 + 1860);
	*(_DWORD*)(v36 + 60) = *(_DWORD*)(a1 + 1864);
	*(_DWORD*)(v36 + 64) = *(_DWORD*)(a1 + 1868);
	*(_WORD*)(v36 + 68) = *(_WORD*)(a1 + 1872);
	v37 = v2 + v36;
	*(_WORD*)(v37 + 26) = *(_WORD*)(a1 + 1874);
	*(_DWORD*)(v37 + 28) = *(_DWORD*)(a1 + 1876);
	*(_DWORD*)(v37 + 32) = *(_DWORD*)(a1 + 1880);
	*(_DWORD*)(v37 + 36) = *(_DWORD*)(a1 + 1884);
	*(_DWORD*)(v37 + 40) = *(_DWORD*)(a1 + 1888);
	*(_DWORD*)(v37 + 44) = *(_DWORD*)(a1 + 1892);
	*(_DWORD*)(v37 + 48) = *(_DWORD*)(a1 + 1896);
	*(_DWORD*)(v37 + 52) = *(_DWORD*)(a1 + 1900);
	*(_DWORD*)(v37 + 56) = *(_DWORD*)(a1 + 1904);
	*(_DWORD*)(v37 + 60) = *(_DWORD*)(a1 + 1908);
	*(_DWORD*)(v37 + 64) = *(_DWORD*)(a1 + 1912);
	v38 = v2 + v37;
	*(_DWORD*)(v38 + 28) = *(_DWORD*)(a1 + 1916);
	*(_DWORD*)(v38 + 32) = *(_DWORD*)(a1 + 1920);
	*(_DWORD*)(v38 + 36) = *(_DWORD*)(a1 + 1924);
	*(_DWORD*)(v38 + 40) = *(_DWORD*)(a1 + 1928);
	*(_DWORD*)(v38 + 44) = *(_DWORD*)(a1 + 1932);
	*(_DWORD*)(v38 + 48) = *(_DWORD*)(a1 + 1936);
	*(_DWORD*)(v38 + 52) = *(_DWORD*)(a1 + 1940);
	*(_DWORD*)(v38 + 56) = *(_DWORD*)(a1 + 1944);
	*(_DWORD*)(v38 + 60) = *(_DWORD*)(a1 + 1948);
	*(_WORD*)(v38 + 64) = *(_WORD*)(a1 + 1952);
	v39 = v2 + v38;
	*(_WORD*)(v39 + 30) = *(_WORD*)(a1 + 1954);
	*(_DWORD*)(v39 + 32) = *(_DWORD*)(a1 + 1956);
	*(_DWORD*)(v39 + 36) = *(_DWORD*)(a1 + 1960);
	*(_DWORD*)(v39 + 40) = *(_DWORD*)(a1 + 1964);
	*(_DWORD*)(v39 + 44) = *(_DWORD*)(a1 + 1968);
	*(_DWORD*)(v39 + 48) = *(_DWORD*)(a1 + 1972);
	*(_DWORD*)(v39 + 52) = *(_DWORD*)(a1 + 1976);
	*(_DWORD*)(v39 + 56) = *(_DWORD*)(a1 + 1980);
	*(_DWORD*)(v39 + 60) = *(_DWORD*)(a1 + 1984);
	v40 = v2 + v39;
	*(_DWORD*)(v40 + 32) = *(_DWORD*)(a1 + 1988);
	*(_DWORD*)(v40 + 36) = *(_DWORD*)(a1 + 1992);
	*(_DWORD*)(v40 + 40) = *(_DWORD*)(a1 + 1996);
	*(_DWORD*)(v40 + 44) = *(_DWORD*)(a1 + 2000);
	*(_DWORD*)(v40 + 48) = *(_DWORD*)(a1 + 2004);
	*(_DWORD*)(v40 + 52) = *(_DWORD*)(a1 + 2008);
	*(_DWORD*)(v40 + 56) = *(_DWORD*)(a1 + 2012);
	*(_WORD*)(v40 + 60) = *(_WORD*)(a1 + 2016);
	v41 = v2 + v40;
	*(_WORD*)(v41 + 34) = *(_WORD*)(a1 + 2018);
	*(_DWORD*)(v41 + 36) = *(_DWORD*)(a1 + 2020);
	*(_DWORD*)(v41 + 40) = *(_DWORD*)(a1 + 2024);
	*(_DWORD*)(v41 + 44) = *(_DWORD*)(a1 + 2028);
	*(_DWORD*)(v41 + 48) = *(_DWORD*)(a1 + 2032);
	*(_DWORD*)(v41 + 52) = *(_DWORD*)(a1 + 2036);
	*(_DWORD*)(v41 + 56) = *(_DWORD*)(a1 + 2040);
	v42 = v2 + v41;
	*(_DWORD*)(v42 + 36) = *(_DWORD*)(a1 + 2044);
	*(_DWORD*)(v42 + 40) = *(_DWORD*)(a1 + 2048);
	*(_DWORD*)(v42 + 44) = *(_DWORD*)(a1 + 2052);
	*(_DWORD*)(v42 + 48) = *(_DWORD*)(a1 + 2056);
	*(_DWORD*)(v42 + 52) = *(_DWORD*)(a1 + 2060);
	*(_WORD*)(v42 + 56) = *(_WORD*)(a1 + 2064);
	v43 = v2 + v42;
	*(_WORD*)(v43 + 38) = *(_WORD*)(a1 + 2066);
	*(_DWORD*)(v43 + 40) = *(_DWORD*)(a1 + 2068);
	*(_DWORD*)(v43 + 44) = *(_DWORD*)(a1 + 2072);
	*(_DWORD*)(v43 + 48) = *(_DWORD*)(a1 + 2076);
	*(_DWORD*)(v43 + 52) = *(_DWORD*)(a1 + 2080);
	v44 = v2 + v43;
	*(_DWORD*)(v44 + 40) = *(_DWORD*)(a1 + 2084);
	*(_DWORD*)(v44 + 44) = *(_DWORD*)(a1 + 2088);
	*(_DWORD*)(v44 + 48) = *(_DWORD*)(a1 + 2092);
	*(_WORD*)(v44 + 52) = *(_WORD*)(a1 + 2096);
	v45 = v2 + v44;
	*(_WORD*)(v45 + 42) = *(_WORD*)(a1 + 2098);
	*(_DWORD*)(v45 + 44) = *(_DWORD*)(a1 + 2100);
	*(_DWORD*)(v45 + 48) = *(_DWORD*)(a1 + 2104);
	v46 = v2 + v45;
	*(_DWORD*)(v46 + 44) = *(_DWORD*)(a1 + 2108);
	result = *(_WORD*)(a1 + 2112);
	*(_WORD*)(v46 + 48) = result;
	*(_WORD*)(v2 + v46 + 46) = *(_WORD*)(a1 + 2114);
	return result;
}

//----- (00483FE0) --------------------------------------------------------
int __cdecl sub_483FE0(int a1, int a2) {
	int result; // eax
	int v3;     // edx
	int v4;     // edi
	int v5;     // edi
	int v6;     // edi
	int v7;     // edi
	int v8;     // edi
	int v9;     // edi
	int v10;    // edi
	int v11;    // edi
	int v12;    // edi
	int v13;    // edi
	int v14;    // edi
	int v15;    // edi
	int v16;    // edi
	int v17;    // edi
	int v18;    // edi
	int v19;    // edi
	int v20;    // edi
	int v21;    // edi
	int v22;    // edi
	int v23;    // edi
	int v24;    // edi
	int v25;    // edi
	int v26;    // edi
	int v27;    // edi
	int v28;    // edi
	int v29;    // edi
	int v30;    // edi
	int v31;    // edi
	int v32;    // edi
	int v33;    // edi
	int v34;    // edi
	int v35;    // edi
	int v36;    // edi
	int v37;    // edi
	int v38;    // edi
	int v39;    // edi
	int v40;    // edi
	int v41;    // edi
	int v42;    // edi
	int v43;    // edi
	int v44;    // edi
	int v45;    // edi
	int v46;    // edi
	int v47;    // edi

	result = a1;
	v3 = dword_5d4594_3798804;
	*(_BYTE*)(a2 + 23) = a1;
	v4 = v3 + a2;
	*(_WORD*)(v4 + 22) = a1;
	*(_BYTE*)(v4 + 24) = a1;
	v5 = v3 + v3 + a2;
	*(_BYTE*)(v5 + 21) = a1;
	*(_WORD*)(v5 + 22) = a1;
	*(_WORD*)(v5 + 24) = a1;
	v6 = v3 + v5;
	*(_DWORD*)(v6 + 20) = a1;
	*(_WORD*)(v6 + 24) = a1;
	*(_BYTE*)(v6 + 26) = a1;
	v7 = v3 + v6;
	*(_BYTE*)(v7 + 19) = a1;
	*(_DWORD*)(v7 + 20) = a1;
	*(_DWORD*)(v7 + 24) = a1;
	v8 = v3 + v7;
	*(_WORD*)(v8 + 18) = a1;
	*(_DWORD*)(v8 + 20) = a1;
	*(_DWORD*)(v8 + 24) = a1;
	*(_BYTE*)(v8 + 28) = a1;
	v9 = v3 + v8;
	*(_BYTE*)(v9 + 17) = a1;
	*(_WORD*)(v9 + 18) = a1;
	*(_DWORD*)(v9 + 20) = a1;
	*(_DWORD*)(v9 + 24) = a1;
	*(_WORD*)(v9 + 28) = a1;
	v10 = v3 + v9;
	*(_DWORD*)(v10 + 16) = a1;
	*(_DWORD*)(v10 + 20) = a1;
	*(_DWORD*)(v10 + 24) = a1;
	*(_WORD*)(v10 + 28) = a1;
	*(_BYTE*)(v10 + 30) = a1;
	v11 = v3 + v10;
	*(_BYTE*)(v11 + 15) = a1;
	*(_DWORD*)(v11 + 16) = a1;
	*(_DWORD*)(v11 + 20) = a1;
	*(_DWORD*)(v11 + 24) = a1;
	*(_DWORD*)(v11 + 28) = a1;
	v12 = v3 + v11;
	*(_WORD*)(v12 + 14) = a1;
	*(_DWORD*)(v12 + 16) = a1;
	*(_DWORD*)(v12 + 20) = a1;
	*(_DWORD*)(v12 + 24) = a1;
	*(_DWORD*)(v12 + 28) = a1;
	*(_BYTE*)(v12 + 32) = a1;
	v13 = v3 + v12;
	*(_BYTE*)(v13 + 13) = a1;
	*(_WORD*)(v13 + 14) = a1;
	*(_DWORD*)(v13 + 16) = a1;
	*(_DWORD*)(v13 + 20) = a1;
	*(_DWORD*)(v13 + 24) = a1;
	*(_DWORD*)(v13 + 28) = a1;
	*(_WORD*)(v13 + 32) = a1;
	v14 = v3 + v13;
	*(_DWORD*)(v14 + 12) = a1;
	*(_DWORD*)(v14 + 16) = a1;
	*(_DWORD*)(v14 + 20) = a1;
	*(_DWORD*)(v14 + 24) = a1;
	*(_DWORD*)(v14 + 28) = a1;
	*(_WORD*)(v14 + 32) = a1;
	*(_BYTE*)(v14 + 34) = a1;
	v15 = v3 + v14;
	*(_BYTE*)(v15 + 11) = a1;
	*(_DWORD*)(v15 + 12) = a1;
	*(_DWORD*)(v15 + 16) = a1;
	*(_DWORD*)(v15 + 20) = a1;
	*(_DWORD*)(v15 + 24) = a1;
	*(_DWORD*)(v15 + 28) = a1;
	*(_DWORD*)(v15 + 32) = a1;
	v16 = v3 + v15;
	*(_WORD*)(v16 + 10) = a1;
	*(_DWORD*)(v16 + 12) = a1;
	*(_DWORD*)(v16 + 16) = a1;
	*(_DWORD*)(v16 + 20) = a1;
	*(_DWORD*)(v16 + 24) = a1;
	*(_DWORD*)(v16 + 28) = a1;
	*(_DWORD*)(v16 + 32) = a1;
	*(_BYTE*)(v16 + 36) = a1;
	v17 = v3 + v16;
	*(_BYTE*)(v17 + 9) = a1;
	*(_WORD*)(v17 + 10) = a1;
	*(_DWORD*)(v17 + 12) = a1;
	*(_DWORD*)(v17 + 16) = a1;
	*(_DWORD*)(v17 + 20) = a1;
	*(_DWORD*)(v17 + 24) = a1;
	*(_DWORD*)(v17 + 28) = a1;
	*(_DWORD*)(v17 + 32) = a1;
	*(_WORD*)(v17 + 36) = a1;
	v18 = v3 + v17;
	*(_DWORD*)(v18 + 8) = a1;
	*(_DWORD*)(v18 + 12) = a1;
	*(_DWORD*)(v18 + 16) = a1;
	*(_DWORD*)(v18 + 20) = a1;
	*(_DWORD*)(v18 + 24) = a1;
	*(_DWORD*)(v18 + 28) = a1;
	*(_DWORD*)(v18 + 32) = a1;
	*(_WORD*)(v18 + 36) = a1;
	*(_BYTE*)(v18 + 38) = a1;
	v19 = v3 + v18;
	*(_BYTE*)(v19 + 7) = a1;
	*(_DWORD*)(v19 + 8) = a1;
	*(_DWORD*)(v19 + 12) = a1;
	*(_DWORD*)(v19 + 16) = a1;
	*(_DWORD*)(v19 + 20) = a1;
	*(_DWORD*)(v19 + 24) = a1;
	*(_DWORD*)(v19 + 28) = a1;
	*(_DWORD*)(v19 + 32) = a1;
	*(_DWORD*)(v19 + 36) = a1;
	v20 = v3 + v19;
	*(_WORD*)(v20 + 6) = a1;
	*(_DWORD*)(v20 + 8) = a1;
	*(_DWORD*)(v20 + 12) = a1;
	*(_DWORD*)(v20 + 16) = a1;
	*(_DWORD*)(v20 + 20) = a1;
	*(_DWORD*)(v20 + 24) = a1;
	*(_DWORD*)(v20 + 28) = a1;
	*(_DWORD*)(v20 + 32) = a1;
	*(_DWORD*)(v20 + 36) = a1;
	*(_BYTE*)(v20 + 40) = a1;
	v21 = v3 + v20;
	*(_BYTE*)(v21 + 5) = a1;
	*(_WORD*)(v21 + 6) = a1;
	*(_DWORD*)(v21 + 8) = a1;
	*(_DWORD*)(v21 + 12) = a1;
	*(_DWORD*)(v21 + 16) = a1;
	*(_DWORD*)(v21 + 20) = a1;
	*(_DWORD*)(v21 + 24) = a1;
	*(_DWORD*)(v21 + 28) = a1;
	*(_DWORD*)(v21 + 32) = a1;
	*(_DWORD*)(v21 + 36) = a1;
	*(_WORD*)(v21 + 40) = a1;
	v22 = v3 + v21;
	*(_DWORD*)(v22 + 4) = a1;
	*(_DWORD*)(v22 + 8) = a1;
	*(_DWORD*)(v22 + 12) = a1;
	*(_DWORD*)(v22 + 16) = a1;
	*(_DWORD*)(v22 + 20) = a1;
	*(_DWORD*)(v22 + 24) = a1;
	*(_DWORD*)(v22 + 28) = a1;
	*(_DWORD*)(v22 + 32) = a1;
	*(_DWORD*)(v22 + 36) = a1;
	*(_WORD*)(v22 + 40) = a1;
	*(_BYTE*)(v22 + 42) = a1;
	v23 = v3 + v22;
	*(_BYTE*)(v23 + 3) = a1;
	*(_DWORD*)(v23 + 4) = a1;
	*(_DWORD*)(v23 + 8) = a1;
	*(_DWORD*)(v23 + 12) = a1;
	*(_DWORD*)(v23 + 16) = a1;
	*(_DWORD*)(v23 + 20) = a1;
	*(_DWORD*)(v23 + 24) = a1;
	*(_DWORD*)(v23 + 28) = a1;
	*(_DWORD*)(v23 + 32) = a1;
	*(_DWORD*)(v23 + 36) = a1;
	*(_DWORD*)(v23 + 40) = a1;
	v24 = v3 + v23;
	*(_WORD*)(v24 + 2) = a1;
	*(_DWORD*)(v24 + 4) = a1;
	*(_DWORD*)(v24 + 8) = a1;
	*(_DWORD*)(v24 + 12) = a1;
	*(_DWORD*)(v24 + 16) = a1;
	*(_DWORD*)(v24 + 20) = a1;
	*(_DWORD*)(v24 + 24) = a1;
	*(_DWORD*)(v24 + 28) = a1;
	*(_DWORD*)(v24 + 32) = a1;
	*(_DWORD*)(v24 + 36) = a1;
	*(_DWORD*)(v24 + 40) = a1;
	*(_BYTE*)(v24 + 44) = a1;
	v25 = v3 + v24;
	*(_BYTE*)(v25 + 1) = a1;
	*(_WORD*)(v25 + 2) = a1;
	*(_DWORD*)(v25 + 4) = a1;
	*(_DWORD*)(v25 + 8) = a1;
	*(_DWORD*)(v25 + 12) = a1;
	*(_DWORD*)(v25 + 16) = a1;
	*(_DWORD*)(v25 + 20) = a1;
	*(_DWORD*)(v25 + 24) = a1;
	*(_DWORD*)(v25 + 28) = a1;
	*(_DWORD*)(v25 + 32) = a1;
	*(_DWORD*)(v25 + 36) = a1;
	*(_DWORD*)(v25 + 40) = a1;
	*(_WORD*)(v25 + 44) = a1;
	v26 = v3 + v25;
	*(_BYTE*)(v26 + 1) = a1;
	*(_WORD*)(v26 + 2) = a1;
	*(_DWORD*)(v26 + 4) = a1;
	*(_DWORD*)(v26 + 8) = a1;
	*(_DWORD*)(v26 + 12) = a1;
	*(_DWORD*)(v26 + 16) = a1;
	*(_DWORD*)(v26 + 20) = a1;
	*(_DWORD*)(v26 + 24) = a1;
	*(_DWORD*)(v26 + 28) = a1;
	*(_DWORD*)(v26 + 32) = a1;
	*(_DWORD*)(v26 + 36) = a1;
	*(_DWORD*)(v26 + 40) = a1;
	*(_WORD*)(v26 + 44) = a1;
	v27 = v3 + v26;
	*(_WORD*)(v27 + 2) = a1;
	*(_DWORD*)(v27 + 4) = a1;
	*(_DWORD*)(v27 + 8) = a1;
	*(_DWORD*)(v27 + 12) = a1;
	*(_DWORD*)(v27 + 16) = a1;
	*(_DWORD*)(v27 + 20) = a1;
	*(_DWORD*)(v27 + 24) = a1;
	*(_DWORD*)(v27 + 28) = a1;
	*(_DWORD*)(v27 + 32) = a1;
	*(_DWORD*)(v27 + 36) = a1;
	*(_DWORD*)(v27 + 40) = a1;
	*(_BYTE*)(v27 + 44) = a1;
	v28 = v3 + v27;
	*(_BYTE*)(v28 + 3) = a1;
	*(_DWORD*)(v28 + 4) = a1;
	*(_DWORD*)(v28 + 8) = a1;
	*(_DWORD*)(v28 + 12) = a1;
	*(_DWORD*)(v28 + 16) = a1;
	*(_DWORD*)(v28 + 20) = a1;
	*(_DWORD*)(v28 + 24) = a1;
	*(_DWORD*)(v28 + 28) = a1;
	*(_DWORD*)(v28 + 32) = a1;
	*(_DWORD*)(v28 + 36) = a1;
	*(_DWORD*)(v28 + 40) = a1;
	v29 = v3 + v28;
	*(_DWORD*)(v29 + 4) = a1;
	*(_DWORD*)(v29 + 8) = a1;
	*(_DWORD*)(v29 + 12) = a1;
	*(_DWORD*)(v29 + 16) = a1;
	*(_DWORD*)(v29 + 20) = a1;
	*(_DWORD*)(v29 + 24) = a1;
	*(_DWORD*)(v29 + 28) = a1;
	*(_DWORD*)(v29 + 32) = a1;
	*(_DWORD*)(v29 + 36) = a1;
	*(_WORD*)(v29 + 40) = a1;
	*(_BYTE*)(v29 + 42) = a1;
	v30 = v3 + v29;
	*(_BYTE*)(v30 + 5) = a1;
	*(_WORD*)(v30 + 6) = a1;
	*(_DWORD*)(v30 + 8) = a1;
	*(_DWORD*)(v30 + 12) = a1;
	*(_DWORD*)(v30 + 16) = a1;
	*(_DWORD*)(v30 + 20) = a1;
	*(_DWORD*)(v30 + 24) = a1;
	*(_DWORD*)(v30 + 28) = a1;
	*(_DWORD*)(v30 + 32) = a1;
	*(_DWORD*)(v30 + 36) = a1;
	*(_WORD*)(v30 + 40) = a1;
	v31 = v3 + v30;
	*(_WORD*)(v31 + 6) = a1;
	*(_DWORD*)(v31 + 8) = a1;
	*(_DWORD*)(v31 + 12) = a1;
	*(_DWORD*)(v31 + 16) = a1;
	*(_DWORD*)(v31 + 20) = a1;
	*(_DWORD*)(v31 + 24) = a1;
	*(_DWORD*)(v31 + 28) = a1;
	*(_DWORD*)(v31 + 32) = a1;
	*(_DWORD*)(v31 + 36) = a1;
	*(_BYTE*)(v31 + 40) = a1;
	v32 = v3 + v31;
	*(_BYTE*)(v32 + 7) = a1;
	*(_DWORD*)(v32 + 8) = a1;
	*(_DWORD*)(v32 + 12) = a1;
	*(_DWORD*)(v32 + 16) = a1;
	*(_DWORD*)(v32 + 20) = a1;
	*(_DWORD*)(v32 + 24) = a1;
	*(_DWORD*)(v32 + 28) = a1;
	*(_DWORD*)(v32 + 32) = a1;
	*(_DWORD*)(v32 + 36) = a1;
	v33 = v3 + v32;
	*(_DWORD*)(v33 + 8) = a1;
	*(_DWORD*)(v33 + 12) = a1;
	*(_DWORD*)(v33 + 16) = a1;
	*(_DWORD*)(v33 + 20) = a1;
	*(_DWORD*)(v33 + 24) = a1;
	*(_DWORD*)(v33 + 28) = a1;
	*(_DWORD*)(v33 + 32) = a1;
	*(_WORD*)(v33 + 36) = a1;
	*(_BYTE*)(v33 + 38) = a1;
	v34 = v3 + v33;
	*(_BYTE*)(v34 + 9) = a1;
	*(_WORD*)(v34 + 10) = a1;
	*(_DWORD*)(v34 + 12) = a1;
	*(_DWORD*)(v34 + 16) = a1;
	*(_DWORD*)(v34 + 20) = a1;
	*(_DWORD*)(v34 + 24) = a1;
	*(_DWORD*)(v34 + 28) = a1;
	*(_DWORD*)(v34 + 32) = a1;
	*(_WORD*)(v34 + 36) = a1;
	v35 = v3 + v34;
	*(_WORD*)(v35 + 10) = a1;
	*(_DWORD*)(v35 + 12) = a1;
	*(_DWORD*)(v35 + 16) = a1;
	*(_DWORD*)(v35 + 20) = a1;
	*(_DWORD*)(v35 + 24) = a1;
	*(_DWORD*)(v35 + 28) = a1;
	*(_DWORD*)(v35 + 32) = a1;
	*(_BYTE*)(v35 + 36) = a1;
	v36 = v3 + v35;
	*(_BYTE*)(v36 + 11) = a1;
	*(_DWORD*)(v36 + 12) = a1;
	*(_DWORD*)(v36 + 16) = a1;
	*(_DWORD*)(v36 + 20) = a1;
	*(_DWORD*)(v36 + 24) = a1;
	*(_DWORD*)(v36 + 28) = a1;
	*(_DWORD*)(v36 + 32) = a1;
	v37 = v3 + v36;
	*(_DWORD*)(v37 + 12) = a1;
	*(_DWORD*)(v37 + 16) = a1;
	*(_DWORD*)(v37 + 20) = a1;
	*(_DWORD*)(v37 + 24) = a1;
	*(_DWORD*)(v37 + 28) = a1;
	*(_WORD*)(v37 + 32) = a1;
	*(_BYTE*)(v37 + 34) = a1;
	v38 = v3 + v37;
	*(_BYTE*)(v38 + 13) = a1;
	*(_WORD*)(v38 + 14) = a1;
	*(_DWORD*)(v38 + 16) = a1;
	*(_DWORD*)(v38 + 20) = a1;
	*(_DWORD*)(v38 + 24) = a1;
	*(_DWORD*)(v38 + 28) = a1;
	*(_WORD*)(v38 + 32) = a1;
	v39 = v3 + v38;
	*(_WORD*)(v39 + 14) = a1;
	*(_DWORD*)(v39 + 16) = a1;
	*(_DWORD*)(v39 + 20) = a1;
	*(_DWORD*)(v39 + 24) = a1;
	*(_DWORD*)(v39 + 28) = a1;
	*(_BYTE*)(v39 + 32) = a1;
	v40 = v3 + v39;
	*(_BYTE*)(v40 + 15) = a1;
	*(_DWORD*)(v40 + 16) = a1;
	*(_DWORD*)(v40 + 20) = a1;
	*(_DWORD*)(v40 + 24) = a1;
	*(_DWORD*)(v40 + 28) = a1;
	v41 = v3 + v40;
	*(_DWORD*)(v41 + 16) = a1;
	*(_DWORD*)(v41 + 20) = a1;
	*(_DWORD*)(v41 + 24) = a1;
	*(_WORD*)(v41 + 28) = a1;
	*(_BYTE*)(v41 + 30) = a1;
	v42 = v3 + v41;
	*(_BYTE*)(v42 + 17) = a1;
	*(_WORD*)(v42 + 18) = a1;
	*(_DWORD*)(v42 + 20) = a1;
	*(_DWORD*)(v42 + 24) = a1;
	*(_WORD*)(v42 + 28) = a1;
	v43 = v3 + v42;
	*(_WORD*)(v43 + 18) = a1;
	*(_DWORD*)(v43 + 20) = a1;
	*(_DWORD*)(v43 + 24) = a1;
	*(_BYTE*)(v43 + 28) = a1;
	v44 = v3 + v43;
	*(_BYTE*)(v44 + 19) = a1;
	*(_DWORD*)(v44 + 20) = a1;
	*(_DWORD*)(v44 + 24) = a1;
	v45 = v3 + v44;
	*(_DWORD*)(v45 + 20) = a1;
	*(_WORD*)(v45 + 24) = a1;
	*(_BYTE*)(v45 + 26) = a1;
	v46 = v3 + v45;
	*(_BYTE*)(v46 + 21) = a1;
	*(_WORD*)(v46 + 22) = a1;
	*(_WORD*)(v46 + 24) = a1;
	v47 = v3 + v46;
	*(_WORD*)(v47 + 22) = a1;
	*(_BYTE*)(v47 + 24) = a1;
	*(_BYTE*)(v3 + v47 + 23) = a1;
	return result;
}

//----- (00484450) --------------------------------------------------------
int __cdecl sub_484450(int a1, int a2) {
	int result; // eax
	int v3;     // edx
	int v4;     // edi
	int v5;     // edi
	int v6;     // edi
	int v7;     // edi
	int v8;     // edi
	int v9;     // edi
	int v10;    // edi
	int v11;    // edi
	int v12;    // edi
	int v13;    // edi
	int v14;    // edi
	int v15;    // edi
	int v16;    // edi
	int v17;    // edi
	int v18;    // edi
	int v19;    // edi
	int v20;    // edi
	int v21;    // edi
	int v22;    // edi
	int v23;    // edi
	int v24;    // edi
	int v25;    // edi
	int v26;    // edi
	int v27;    // edi
	int v28;    // edi
	int v29;    // edi
	int v30;    // edi
	int v31;    // edi
	int v32;    // edi
	int v33;    // edi
	int v34;    // edi
	int v35;    // edi
	int v36;    // edi
	int v37;    // edi
	int v38;    // edi
	int v39;    // edi
	int v40;    // edi
	int v41;    // edi
	int v42;    // edi
	int v43;    // edi
	int v44;    // edi
	int v45;    // edi
	int v46;    // edi
	int v47;    // edi

	result = a1;
	v3 = dword_5d4594_3798804;
	*(_WORD*)(a2 + 46) = a1;
	v4 = v3 + a2;
	*(_DWORD*)(v4 + 44) = a1;
	*(_WORD*)(v4 + 48) = a1;
	v5 = v3 + v3 + a2;
	*(_WORD*)(v5 + 42) = a1;
	*(_DWORD*)(v5 + 44) = a1;
	*(_DWORD*)(v5 + 48) = a1;
	v6 = v3 + v5;
	*(_DWORD*)(v6 + 40) = a1;
	*(_DWORD*)(v6 + 44) = a1;
	*(_DWORD*)(v6 + 48) = a1;
	*(_WORD*)(v6 + 52) = a1;
	v7 = v3 + v6;
	*(_WORD*)(v7 + 38) = a1;
	*(_DWORD*)(v7 + 40) = a1;
	*(_DWORD*)(v7 + 44) = a1;
	*(_DWORD*)(v7 + 48) = a1;
	*(_DWORD*)(v7 + 52) = a1;
	v8 = v3 + v7;
	*(_DWORD*)(v8 + 36) = a1;
	*(_DWORD*)(v8 + 40) = a1;
	*(_DWORD*)(v8 + 44) = a1;
	*(_DWORD*)(v8 + 48) = a1;
	*(_DWORD*)(v8 + 52) = a1;
	*(_WORD*)(v8 + 56) = a1;
	v9 = v3 + v8;
	*(_WORD*)(v9 + 34) = a1;
	*(_DWORD*)(v9 + 36) = a1;
	*(_DWORD*)(v9 + 40) = a1;
	*(_DWORD*)(v9 + 44) = a1;
	*(_DWORD*)(v9 + 48) = a1;
	*(_DWORD*)(v9 + 52) = a1;
	*(_DWORD*)(v9 + 56) = a1;
	v10 = v3 + v9;
	*(_DWORD*)(v10 + 32) = a1;
	*(_DWORD*)(v10 + 36) = a1;
	*(_DWORD*)(v10 + 40) = a1;
	*(_DWORD*)(v10 + 44) = a1;
	*(_DWORD*)(v10 + 48) = a1;
	*(_DWORD*)(v10 + 52) = a1;
	*(_DWORD*)(v10 + 56) = a1;
	*(_WORD*)(v10 + 60) = a1;
	v11 = v3 + v10;
	*(_WORD*)(v11 + 30) = a1;
	*(_DWORD*)(v11 + 32) = a1;
	*(_DWORD*)(v11 + 36) = a1;
	*(_DWORD*)(v11 + 40) = a1;
	*(_DWORD*)(v11 + 44) = a1;
	*(_DWORD*)(v11 + 48) = a1;
	*(_DWORD*)(v11 + 52) = a1;
	*(_DWORD*)(v11 + 56) = a1;
	*(_DWORD*)(v11 + 60) = a1;
	v12 = v3 + v11;
	*(_DWORD*)(v12 + 28) = a1;
	*(_DWORD*)(v12 + 32) = a1;
	*(_DWORD*)(v12 + 36) = a1;
	*(_DWORD*)(v12 + 40) = a1;
	*(_DWORD*)(v12 + 44) = a1;
	*(_DWORD*)(v12 + 48) = a1;
	*(_DWORD*)(v12 + 52) = a1;
	*(_DWORD*)(v12 + 56) = a1;
	*(_DWORD*)(v12 + 60) = a1;
	*(_WORD*)(v12 + 64) = a1;
	v13 = v3 + v12;
	*(_WORD*)(v13 + 26) = a1;
	*(_DWORD*)(v13 + 28) = a1;
	*(_DWORD*)(v13 + 32) = a1;
	*(_DWORD*)(v13 + 36) = a1;
	*(_DWORD*)(v13 + 40) = a1;
	*(_DWORD*)(v13 + 44) = a1;
	*(_DWORD*)(v13 + 48) = a1;
	*(_DWORD*)(v13 + 52) = a1;
	*(_DWORD*)(v13 + 56) = a1;
	*(_DWORD*)(v13 + 60) = a1;
	*(_DWORD*)(v13 + 64) = a1;
	v14 = v3 + v13;
	*(_DWORD*)(v14 + 24) = a1;
	*(_DWORD*)(v14 + 28) = a1;
	*(_DWORD*)(v14 + 32) = a1;
	*(_DWORD*)(v14 + 36) = a1;
	*(_DWORD*)(v14 + 40) = a1;
	*(_DWORD*)(v14 + 44) = a1;
	*(_DWORD*)(v14 + 48) = a1;
	*(_DWORD*)(v14 + 52) = a1;
	*(_DWORD*)(v14 + 56) = a1;
	*(_DWORD*)(v14 + 60) = a1;
	*(_DWORD*)(v14 + 64) = a1;
	*(_WORD*)(v14 + 68) = a1;
	v15 = v3 + v14;
	*(_WORD*)(v15 + 22) = a1;
	*(_DWORD*)(v15 + 24) = a1;
	*(_DWORD*)(v15 + 28) = a1;
	*(_DWORD*)(v15 + 32) = a1;
	*(_DWORD*)(v15 + 36) = a1;
	*(_DWORD*)(v15 + 40) = a1;
	*(_DWORD*)(v15 + 44) = a1;
	*(_DWORD*)(v15 + 48) = a1;
	*(_DWORD*)(v15 + 52) = a1;
	*(_DWORD*)(v15 + 56) = a1;
	*(_DWORD*)(v15 + 60) = a1;
	*(_DWORD*)(v15 + 64) = a1;
	*(_DWORD*)(v15 + 68) = a1;
	v16 = v3 + v15;
	*(_DWORD*)(v16 + 20) = a1;
	*(_DWORD*)(v16 + 24) = a1;
	*(_DWORD*)(v16 + 28) = a1;
	*(_DWORD*)(v16 + 32) = a1;
	*(_DWORD*)(v16 + 36) = a1;
	*(_DWORD*)(v16 + 40) = a1;
	*(_DWORD*)(v16 + 44) = a1;
	*(_DWORD*)(v16 + 48) = a1;
	*(_DWORD*)(v16 + 52) = a1;
	*(_DWORD*)(v16 + 56) = a1;
	*(_DWORD*)(v16 + 60) = a1;
	*(_DWORD*)(v16 + 64) = a1;
	*(_DWORD*)(v16 + 68) = a1;
	*(_WORD*)(v16 + 72) = a1;
	v17 = v3 + v16;
	*(_WORD*)(v17 + 18) = a1;
	*(_DWORD*)(v17 + 20) = a1;
	*(_DWORD*)(v17 + 24) = a1;
	*(_DWORD*)(v17 + 28) = a1;
	*(_DWORD*)(v17 + 32) = a1;
	*(_DWORD*)(v17 + 36) = a1;
	*(_DWORD*)(v17 + 40) = a1;
	*(_DWORD*)(v17 + 44) = a1;
	*(_DWORD*)(v17 + 48) = a1;
	*(_DWORD*)(v17 + 52) = a1;
	*(_DWORD*)(v17 + 56) = a1;
	*(_DWORD*)(v17 + 60) = a1;
	*(_DWORD*)(v17 + 64) = a1;
	*(_DWORD*)(v17 + 68) = a1;
	*(_DWORD*)(v17 + 72) = a1;
	v18 = v3 + v17;
	*(_DWORD*)(v18 + 16) = a1;
	*(_DWORD*)(v18 + 20) = a1;
	*(_DWORD*)(v18 + 24) = a1;
	*(_DWORD*)(v18 + 28) = a1;
	*(_DWORD*)(v18 + 32) = a1;
	*(_DWORD*)(v18 + 36) = a1;
	*(_DWORD*)(v18 + 40) = a1;
	*(_DWORD*)(v18 + 44) = a1;
	*(_DWORD*)(v18 + 48) = a1;
	*(_DWORD*)(v18 + 52) = a1;
	*(_DWORD*)(v18 + 56) = a1;
	*(_DWORD*)(v18 + 60) = a1;
	*(_DWORD*)(v18 + 64) = a1;
	*(_DWORD*)(v18 + 68) = a1;
	*(_DWORD*)(v18 + 72) = a1;
	*(_WORD*)(v18 + 76) = a1;
	v19 = v3 + v18;
	*(_WORD*)(v19 + 14) = a1;
	*(_DWORD*)(v19 + 16) = a1;
	*(_DWORD*)(v19 + 20) = a1;
	*(_DWORD*)(v19 + 24) = a1;
	*(_DWORD*)(v19 + 28) = a1;
	*(_DWORD*)(v19 + 32) = a1;
	*(_DWORD*)(v19 + 36) = a1;
	*(_DWORD*)(v19 + 40) = a1;
	*(_DWORD*)(v19 + 44) = a1;
	*(_DWORD*)(v19 + 48) = a1;
	*(_DWORD*)(v19 + 52) = a1;
	*(_DWORD*)(v19 + 56) = a1;
	*(_DWORD*)(v19 + 60) = a1;
	*(_DWORD*)(v19 + 64) = a1;
	*(_DWORD*)(v19 + 68) = a1;
	*(_DWORD*)(v19 + 72) = a1;
	*(_DWORD*)(v19 + 76) = a1;
	v20 = v3 + v19;
	*(_DWORD*)(v20 + 12) = a1;
	*(_DWORD*)(v20 + 16) = a1;
	*(_DWORD*)(v20 + 20) = a1;
	*(_DWORD*)(v20 + 24) = a1;
	*(_DWORD*)(v20 + 28) = a1;
	*(_DWORD*)(v20 + 32) = a1;
	*(_DWORD*)(v20 + 36) = a1;
	*(_DWORD*)(v20 + 40) = a1;
	*(_DWORD*)(v20 + 44) = a1;
	*(_DWORD*)(v20 + 48) = a1;
	*(_DWORD*)(v20 + 52) = a1;
	*(_DWORD*)(v20 + 56) = a1;
	*(_DWORD*)(v20 + 60) = a1;
	*(_DWORD*)(v20 + 64) = a1;
	*(_DWORD*)(v20 + 68) = a1;
	*(_DWORD*)(v20 + 72) = a1;
	*(_DWORD*)(v20 + 76) = a1;
	*(_WORD*)(v20 + 80) = a1;
	v21 = v3 + v20;
	*(_WORD*)(v21 + 10) = a1;
	*(_DWORD*)(v21 + 12) = a1;
	*(_DWORD*)(v21 + 16) = a1;
	*(_DWORD*)(v21 + 20) = a1;
	*(_DWORD*)(v21 + 24) = a1;
	*(_DWORD*)(v21 + 28) = a1;
	*(_DWORD*)(v21 + 32) = a1;
	*(_DWORD*)(v21 + 36) = a1;
	*(_DWORD*)(v21 + 40) = a1;
	*(_DWORD*)(v21 + 44) = a1;
	*(_DWORD*)(v21 + 48) = a1;
	*(_DWORD*)(v21 + 52) = a1;
	*(_DWORD*)(v21 + 56) = a1;
	*(_DWORD*)(v21 + 60) = a1;
	*(_DWORD*)(v21 + 64) = a1;
	*(_DWORD*)(v21 + 68) = a1;
	*(_DWORD*)(v21 + 72) = a1;
	*(_DWORD*)(v21 + 76) = a1;
	*(_DWORD*)(v21 + 80) = a1;
	v22 = v3 + v21;
	*(_DWORD*)(v22 + 8) = a1;
	*(_DWORD*)(v22 + 12) = a1;
	*(_DWORD*)(v22 + 16) = a1;
	*(_DWORD*)(v22 + 20) = a1;
	*(_DWORD*)(v22 + 24) = a1;
	*(_DWORD*)(v22 + 28) = a1;
	*(_DWORD*)(v22 + 32) = a1;
	*(_DWORD*)(v22 + 36) = a1;
	*(_DWORD*)(v22 + 40) = a1;
	*(_DWORD*)(v22 + 44) = a1;
	*(_DWORD*)(v22 + 48) = a1;
	*(_DWORD*)(v22 + 52) = a1;
	*(_DWORD*)(v22 + 56) = a1;
	*(_DWORD*)(v22 + 60) = a1;
	*(_DWORD*)(v22 + 64) = a1;
	*(_DWORD*)(v22 + 68) = a1;
	*(_DWORD*)(v22 + 72) = a1;
	*(_DWORD*)(v22 + 76) = a1;
	*(_DWORD*)(v22 + 80) = a1;
	*(_WORD*)(v22 + 84) = a1;
	v23 = v3 + v22;
	*(_WORD*)(v23 + 6) = a1;
	*(_DWORD*)(v23 + 8) = a1;
	*(_DWORD*)(v23 + 12) = a1;
	*(_DWORD*)(v23 + 16) = a1;
	*(_DWORD*)(v23 + 20) = a1;
	*(_DWORD*)(v23 + 24) = a1;
	*(_DWORD*)(v23 + 28) = a1;
	*(_DWORD*)(v23 + 32) = a1;
	*(_DWORD*)(v23 + 36) = a1;
	*(_DWORD*)(v23 + 40) = a1;
	*(_DWORD*)(v23 + 44) = a1;
	*(_DWORD*)(v23 + 48) = a1;
	*(_DWORD*)(v23 + 52) = a1;
	*(_DWORD*)(v23 + 56) = a1;
	*(_DWORD*)(v23 + 60) = a1;
	*(_DWORD*)(v23 + 64) = a1;
	*(_DWORD*)(v23 + 68) = a1;
	*(_DWORD*)(v23 + 72) = a1;
	*(_DWORD*)(v23 + 76) = a1;
	*(_DWORD*)(v23 + 80) = a1;
	*(_DWORD*)(v23 + 84) = a1;
	v24 = v3 + v23;
	*(_DWORD*)(v24 + 4) = a1;
	*(_DWORD*)(v24 + 8) = a1;
	*(_DWORD*)(v24 + 12) = a1;
	*(_DWORD*)(v24 + 16) = a1;
	*(_DWORD*)(v24 + 20) = a1;
	*(_DWORD*)(v24 + 24) = a1;
	*(_DWORD*)(v24 + 28) = a1;
	*(_DWORD*)(v24 + 32) = a1;
	*(_DWORD*)(v24 + 36) = a1;
	*(_DWORD*)(v24 + 40) = a1;
	*(_DWORD*)(v24 + 44) = a1;
	*(_DWORD*)(v24 + 48) = a1;
	*(_DWORD*)(v24 + 52) = a1;
	*(_DWORD*)(v24 + 56) = a1;
	*(_DWORD*)(v24 + 60) = a1;
	*(_DWORD*)(v24 + 64) = a1;
	*(_DWORD*)(v24 + 68) = a1;
	*(_DWORD*)(v24 + 72) = a1;
	*(_DWORD*)(v24 + 76) = a1;
	*(_DWORD*)(v24 + 80) = a1;
	*(_DWORD*)(v24 + 84) = a1;
	*(_WORD*)(v24 + 88) = a1;
	v25 = v3 + v24;
	*(_WORD*)(v25 + 2) = a1;
	*(_DWORD*)(v25 + 4) = a1;
	*(_DWORD*)(v25 + 8) = a1;
	*(_DWORD*)(v25 + 12) = a1;
	*(_DWORD*)(v25 + 16) = a1;
	*(_DWORD*)(v25 + 20) = a1;
	*(_DWORD*)(v25 + 24) = a1;
	*(_DWORD*)(v25 + 28) = a1;
	*(_DWORD*)(v25 + 32) = a1;
	*(_DWORD*)(v25 + 36) = a1;
	*(_DWORD*)(v25 + 40) = a1;
	*(_DWORD*)(v25 + 44) = a1;
	*(_DWORD*)(v25 + 48) = a1;
	*(_DWORD*)(v25 + 52) = a1;
	*(_DWORD*)(v25 + 56) = a1;
	*(_DWORD*)(v25 + 60) = a1;
	*(_DWORD*)(v25 + 64) = a1;
	*(_DWORD*)(v25 + 68) = a1;
	*(_DWORD*)(v25 + 72) = a1;
	*(_DWORD*)(v25 + 76) = a1;
	*(_DWORD*)(v25 + 80) = a1;
	*(_DWORD*)(v25 + 84) = a1;
	*(_DWORD*)(v25 + 88) = a1;
	v26 = v3 + v25;
	*(_WORD*)(v26 + 2) = a1;
	*(_DWORD*)(v26 + 4) = a1;
	*(_DWORD*)(v26 + 8) = a1;
	*(_DWORD*)(v26 + 12) = a1;
	*(_DWORD*)(v26 + 16) = a1;
	*(_DWORD*)(v26 + 20) = a1;
	*(_DWORD*)(v26 + 24) = a1;
	*(_DWORD*)(v26 + 28) = a1;
	*(_DWORD*)(v26 + 32) = a1;
	*(_DWORD*)(v26 + 36) = a1;
	*(_DWORD*)(v26 + 40) = a1;
	*(_DWORD*)(v26 + 44) = a1;
	*(_DWORD*)(v26 + 48) = a1;
	*(_DWORD*)(v26 + 52) = a1;
	*(_DWORD*)(v26 + 56) = a1;
	*(_DWORD*)(v26 + 60) = a1;
	*(_DWORD*)(v26 + 64) = a1;
	*(_DWORD*)(v26 + 68) = a1;
	*(_DWORD*)(v26 + 72) = a1;
	*(_DWORD*)(v26 + 76) = a1;
	*(_DWORD*)(v26 + 80) = a1;
	*(_DWORD*)(v26 + 84) = a1;
	*(_DWORD*)(v26 + 88) = a1;
	v27 = v3 + v26;
	*(_DWORD*)(v27 + 4) = a1;
	*(_DWORD*)(v27 + 8) = a1;
	*(_DWORD*)(v27 + 12) = a1;
	*(_DWORD*)(v27 + 16) = a1;
	*(_DWORD*)(v27 + 20) = a1;
	*(_DWORD*)(v27 + 24) = a1;
	*(_DWORD*)(v27 + 28) = a1;
	*(_DWORD*)(v27 + 32) = a1;
	*(_DWORD*)(v27 + 36) = a1;
	*(_DWORD*)(v27 + 40) = a1;
	*(_DWORD*)(v27 + 44) = a1;
	*(_DWORD*)(v27 + 48) = a1;
	*(_DWORD*)(v27 + 52) = a1;
	*(_DWORD*)(v27 + 56) = a1;
	*(_DWORD*)(v27 + 60) = a1;
	*(_DWORD*)(v27 + 64) = a1;
	*(_DWORD*)(v27 + 68) = a1;
	*(_DWORD*)(v27 + 72) = a1;
	*(_DWORD*)(v27 + 76) = a1;
	*(_DWORD*)(v27 + 80) = a1;
	*(_DWORD*)(v27 + 84) = a1;
	*(_WORD*)(v27 + 88) = a1;
	v28 = v3 + v27;
	*(_WORD*)(v28 + 6) = a1;
	*(_DWORD*)(v28 + 8) = a1;
	*(_DWORD*)(v28 + 12) = a1;
	*(_DWORD*)(v28 + 16) = a1;
	*(_DWORD*)(v28 + 20) = a1;
	*(_DWORD*)(v28 + 24) = a1;
	*(_DWORD*)(v28 + 28) = a1;
	*(_DWORD*)(v28 + 32) = a1;
	*(_DWORD*)(v28 + 36) = a1;
	*(_DWORD*)(v28 + 40) = a1;
	*(_DWORD*)(v28 + 44) = a1;
	*(_DWORD*)(v28 + 48) = a1;
	*(_DWORD*)(v28 + 52) = a1;
	*(_DWORD*)(v28 + 56) = a1;
	*(_DWORD*)(v28 + 60) = a1;
	*(_DWORD*)(v28 + 64) = a1;
	*(_DWORD*)(v28 + 68) = a1;
	*(_DWORD*)(v28 + 72) = a1;
	*(_DWORD*)(v28 + 76) = a1;
	*(_DWORD*)(v28 + 80) = a1;
	*(_DWORD*)(v28 + 84) = a1;
	v29 = v3 + v28;
	*(_DWORD*)(v29 + 8) = a1;
	*(_DWORD*)(v29 + 12) = a1;
	*(_DWORD*)(v29 + 16) = a1;
	*(_DWORD*)(v29 + 20) = a1;
	*(_DWORD*)(v29 + 24) = a1;
	*(_DWORD*)(v29 + 28) = a1;
	*(_DWORD*)(v29 + 32) = a1;
	*(_DWORD*)(v29 + 36) = a1;
	*(_DWORD*)(v29 + 40) = a1;
	*(_DWORD*)(v29 + 44) = a1;
	*(_DWORD*)(v29 + 48) = a1;
	*(_DWORD*)(v29 + 52) = a1;
	*(_DWORD*)(v29 + 56) = a1;
	*(_DWORD*)(v29 + 60) = a1;
	*(_DWORD*)(v29 + 64) = a1;
	*(_DWORD*)(v29 + 68) = a1;
	*(_DWORD*)(v29 + 72) = a1;
	*(_DWORD*)(v29 + 76) = a1;
	*(_DWORD*)(v29 + 80) = a1;
	*(_WORD*)(v29 + 84) = a1;
	v30 = v3 + v29;
	*(_WORD*)(v30 + 10) = a1;
	*(_DWORD*)(v30 + 12) = a1;
	*(_DWORD*)(v30 + 16) = a1;
	*(_DWORD*)(v30 + 20) = a1;
	*(_DWORD*)(v30 + 24) = a1;
	*(_DWORD*)(v30 + 28) = a1;
	*(_DWORD*)(v30 + 32) = a1;
	*(_DWORD*)(v30 + 36) = a1;
	*(_DWORD*)(v30 + 40) = a1;
	*(_DWORD*)(v30 + 44) = a1;
	*(_DWORD*)(v30 + 48) = a1;
	*(_DWORD*)(v30 + 52) = a1;
	*(_DWORD*)(v30 + 56) = a1;
	*(_DWORD*)(v30 + 60) = a1;
	*(_DWORD*)(v30 + 64) = a1;
	*(_DWORD*)(v30 + 68) = a1;
	*(_DWORD*)(v30 + 72) = a1;
	*(_DWORD*)(v30 + 76) = a1;
	*(_DWORD*)(v30 + 80) = a1;
	v31 = v3 + v30;
	*(_DWORD*)(v31 + 12) = a1;
	*(_DWORD*)(v31 + 16) = a1;
	*(_DWORD*)(v31 + 20) = a1;
	*(_DWORD*)(v31 + 24) = a1;
	*(_DWORD*)(v31 + 28) = a1;
	*(_DWORD*)(v31 + 32) = a1;
	*(_DWORD*)(v31 + 36) = a1;
	*(_DWORD*)(v31 + 40) = a1;
	*(_DWORD*)(v31 + 44) = a1;
	*(_DWORD*)(v31 + 48) = a1;
	*(_DWORD*)(v31 + 52) = a1;
	*(_DWORD*)(v31 + 56) = a1;
	*(_DWORD*)(v31 + 60) = a1;
	*(_DWORD*)(v31 + 64) = a1;
	*(_DWORD*)(v31 + 68) = a1;
	*(_DWORD*)(v31 + 72) = a1;
	*(_DWORD*)(v31 + 76) = a1;
	*(_WORD*)(v31 + 80) = a1;
	v32 = v3 + v31;
	*(_WORD*)(v32 + 14) = a1;
	*(_DWORD*)(v32 + 16) = a1;
	*(_DWORD*)(v32 + 20) = a1;
	*(_DWORD*)(v32 + 24) = a1;
	*(_DWORD*)(v32 + 28) = a1;
	*(_DWORD*)(v32 + 32) = a1;
	*(_DWORD*)(v32 + 36) = a1;
	*(_DWORD*)(v32 + 40) = a1;
	*(_DWORD*)(v32 + 44) = a1;
	*(_DWORD*)(v32 + 48) = a1;
	*(_DWORD*)(v32 + 52) = a1;
	*(_DWORD*)(v32 + 56) = a1;
	*(_DWORD*)(v32 + 60) = a1;
	*(_DWORD*)(v32 + 64) = a1;
	*(_DWORD*)(v32 + 68) = a1;
	*(_DWORD*)(v32 + 72) = a1;
	*(_DWORD*)(v32 + 76) = a1;
	v33 = v3 + v32;
	*(_DWORD*)(v33 + 16) = a1;
	*(_DWORD*)(v33 + 20) = a1;
	*(_DWORD*)(v33 + 24) = a1;
	*(_DWORD*)(v33 + 28) = a1;
	*(_DWORD*)(v33 + 32) = a1;
	*(_DWORD*)(v33 + 36) = a1;
	*(_DWORD*)(v33 + 40) = a1;
	*(_DWORD*)(v33 + 44) = a1;
	*(_DWORD*)(v33 + 48) = a1;
	*(_DWORD*)(v33 + 52) = a1;
	*(_DWORD*)(v33 + 56) = a1;
	*(_DWORD*)(v33 + 60) = a1;
	*(_DWORD*)(v33 + 64) = a1;
	*(_DWORD*)(v33 + 68) = a1;
	*(_DWORD*)(v33 + 72) = a1;
	*(_WORD*)(v33 + 76) = a1;
	v34 = v3 + v33;
	*(_WORD*)(v34 + 18) = a1;
	*(_DWORD*)(v34 + 20) = a1;
	*(_DWORD*)(v34 + 24) = a1;
	*(_DWORD*)(v34 + 28) = a1;
	*(_DWORD*)(v34 + 32) = a1;
	*(_DWORD*)(v34 + 36) = a1;
	*(_DWORD*)(v34 + 40) = a1;
	*(_DWORD*)(v34 + 44) = a1;
	*(_DWORD*)(v34 + 48) = a1;
	*(_DWORD*)(v34 + 52) = a1;
	*(_DWORD*)(v34 + 56) = a1;
	*(_DWORD*)(v34 + 60) = a1;
	*(_DWORD*)(v34 + 64) = a1;
	*(_DWORD*)(v34 + 68) = a1;
	*(_DWORD*)(v34 + 72) = a1;
	v35 = v3 + v34;
	*(_DWORD*)(v35 + 20) = a1;
	*(_DWORD*)(v35 + 24) = a1;
	*(_DWORD*)(v35 + 28) = a1;
	*(_DWORD*)(v35 + 32) = a1;
	*(_DWORD*)(v35 + 36) = a1;
	*(_DWORD*)(v35 + 40) = a1;
	*(_DWORD*)(v35 + 44) = a1;
	*(_DWORD*)(v35 + 48) = a1;
	*(_DWORD*)(v35 + 52) = a1;
	*(_DWORD*)(v35 + 56) = a1;
	*(_DWORD*)(v35 + 60) = a1;
	*(_DWORD*)(v35 + 64) = a1;
	*(_DWORD*)(v35 + 68) = a1;
	*(_WORD*)(v35 + 72) = a1;
	v36 = v3 + v35;
	*(_WORD*)(v36 + 22) = a1;
	*(_DWORD*)(v36 + 24) = a1;
	*(_DWORD*)(v36 + 28) = a1;
	*(_DWORD*)(v36 + 32) = a1;
	*(_DWORD*)(v36 + 36) = a1;
	*(_DWORD*)(v36 + 40) = a1;
	*(_DWORD*)(v36 + 44) = a1;
	*(_DWORD*)(v36 + 48) = a1;
	*(_DWORD*)(v36 + 52) = a1;
	*(_DWORD*)(v36 + 56) = a1;
	*(_DWORD*)(v36 + 60) = a1;
	*(_DWORD*)(v36 + 64) = a1;
	*(_DWORD*)(v36 + 68) = a1;
	v37 = v3 + v36;
	*(_DWORD*)(v37 + 24) = a1;
	*(_DWORD*)(v37 + 28) = a1;
	*(_DWORD*)(v37 + 32) = a1;
	*(_DWORD*)(v37 + 36) = a1;
	*(_DWORD*)(v37 + 40) = a1;
	*(_DWORD*)(v37 + 44) = a1;
	*(_DWORD*)(v37 + 48) = a1;
	*(_DWORD*)(v37 + 52) = a1;
	*(_DWORD*)(v37 + 56) = a1;
	*(_DWORD*)(v37 + 60) = a1;
	*(_DWORD*)(v37 + 64) = a1;
	*(_WORD*)(v37 + 68) = a1;
	v38 = v3 + v37;
	*(_WORD*)(v38 + 26) = a1;
	*(_DWORD*)(v38 + 28) = a1;
	*(_DWORD*)(v38 + 32) = a1;
	*(_DWORD*)(v38 + 36) = a1;
	*(_DWORD*)(v38 + 40) = a1;
	*(_DWORD*)(v38 + 44) = a1;
	*(_DWORD*)(v38 + 48) = a1;
	*(_DWORD*)(v38 + 52) = a1;
	*(_DWORD*)(v38 + 56) = a1;
	*(_DWORD*)(v38 + 60) = a1;
	*(_DWORD*)(v38 + 64) = a1;
	v39 = v3 + v38;
	*(_DWORD*)(v39 + 28) = a1;
	*(_DWORD*)(v39 + 32) = a1;
	*(_DWORD*)(v39 + 36) = a1;
	*(_DWORD*)(v39 + 40) = a1;
	*(_DWORD*)(v39 + 44) = a1;
	*(_DWORD*)(v39 + 48) = a1;
	*(_DWORD*)(v39 + 52) = a1;
	*(_DWORD*)(v39 + 56) = a1;
	*(_DWORD*)(v39 + 60) = a1;
	*(_WORD*)(v39 + 64) = a1;
	v40 = v3 + v39;
	*(_WORD*)(v40 + 30) = a1;
	*(_DWORD*)(v40 + 32) = a1;
	*(_DWORD*)(v40 + 36) = a1;
	*(_DWORD*)(v40 + 40) = a1;
	*(_DWORD*)(v40 + 44) = a1;
	*(_DWORD*)(v40 + 48) = a1;
	*(_DWORD*)(v40 + 52) = a1;
	*(_DWORD*)(v40 + 56) = a1;
	*(_DWORD*)(v40 + 60) = a1;
	v41 = v3 + v40;
	*(_DWORD*)(v41 + 32) = a1;
	*(_DWORD*)(v41 + 36) = a1;
	*(_DWORD*)(v41 + 40) = a1;
	*(_DWORD*)(v41 + 44) = a1;
	*(_DWORD*)(v41 + 48) = a1;
	*(_DWORD*)(v41 + 52) = a1;
	*(_DWORD*)(v41 + 56) = a1;
	*(_WORD*)(v41 + 60) = a1;
	v42 = v3 + v41;
	*(_WORD*)(v42 + 34) = a1;
	*(_DWORD*)(v42 + 36) = a1;
	*(_DWORD*)(v42 + 40) = a1;
	*(_DWORD*)(v42 + 44) = a1;
	*(_DWORD*)(v42 + 48) = a1;
	*(_DWORD*)(v42 + 52) = a1;
	*(_DWORD*)(v42 + 56) = a1;
	v43 = v3 + v42;
	*(_DWORD*)(v43 + 36) = a1;
	*(_DWORD*)(v43 + 40) = a1;
	*(_DWORD*)(v43 + 44) = a1;
	*(_DWORD*)(v43 + 48) = a1;
	*(_DWORD*)(v43 + 52) = a1;
	*(_WORD*)(v43 + 56) = a1;
	v44 = v3 + v43;
	*(_WORD*)(v44 + 38) = a1;
	*(_DWORD*)(v44 + 40) = a1;
	*(_DWORD*)(v44 + 44) = a1;
	*(_DWORD*)(v44 + 48) = a1;
	*(_DWORD*)(v44 + 52) = a1;
	v45 = v3 + v44;
	*(_DWORD*)(v45 + 40) = a1;
	*(_DWORD*)(v45 + 44) = a1;
	*(_DWORD*)(v45 + 48) = a1;
	*(_WORD*)(v45 + 52) = a1;
	v46 = v3 + v45;
	*(_WORD*)(v46 + 42) = a1;
	*(_DWORD*)(v46 + 44) = a1;
	*(_DWORD*)(v46 + 48) = a1;
	v47 = v3 + v46;
	*(_DWORD*)(v47 + 44) = a1;
	*(_WORD*)(v47 + 48) = a1;
	*(_WORD*)(v3 + v47 + 46) = a1;
	return result;
}

//----- (00484BA0) --------------------------------------------------------
void __cdecl sub_484BA0(float a1) {
	if (a1 >= 1.0)
		*(float*)&dword_587000_154968 = a1;
	else
		dword_587000_154968 = 1065353216;
}

//----- (00484BE0) --------------------------------------------------------
_DWORD* __cdecl sub_484BE0(_DWORD* a1, int a2, int a3, int a4) {
	_DWORD* result; // eax

	result = a1;
	a1[4] = a2;
	*a1 = 2;
	a1[5] = a3;
	a1[6] = a4;
	return result;
}

//----- (00484C00) --------------------------------------------------------
__int64 __cdecl sub_484C00(int a1, int a2) {
	__int64 result; // rax

	result = (__int64)((double)a2 * 0.0027777778 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	*(_WORD*)(a1 + 28) = result;
	*(_DWORD*)(a1 + 32) = 0;
	return result;
}

//----- (00484C30) --------------------------------------------------------
__int64 __cdecl sub_484C30(int a1, int a2) {
	__int64 result; // rax

	result = (__int64)((double)a2 * 0.0027777778 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	*(_WORD*)(a1 + 30) = result;
	return result;
}

//----- (00484C60) --------------------------------------------------------
int __cdecl sub_484C60(float a1) {
	double v2; // st7

	if (a1 <= (double)*(float*)&dword_587000_154968)
		return 0;
	if (a1 <= 31.0)
		v2 = a1;
	else
		v2 = 31.0;
	return nox_double2int(sqrt(
		((*getMemFloatPtr(0x587000, 154980) + v2) / (*getMemFloatPtr(0x587000, 154980) + *(float*)&dword_587000_154968) + 1.0) *
		(a1 * a1 / (*getMemFloatPtr(0x587000, 154976) * *getMemFloatPtr(0x587000, 154972)))));
}

//----- (00484CE0) --------------------------------------------------------
int __cdecl sub_484CE0(int a1, float a2) {
	int result; // eax

	if (a2 > 63.0)
		a2 = 63.0;
	*(float*)(a1 + 4) = a2;
	result = sub_484C60(a2);
	*(_DWORD*)(a1 + 8) = result;
	return result;
}

//----- (00484D20) --------------------------------------------------------
int __cdecl sub_484D20(int a1, float a2) {
	int result; // eax

	if (a2 > 63.0)
		a2 = 63.0;
	*(_DWORD*)(a1 + 12) = (__int64)(a2 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	result = sub_484C60(a2);
	*(_DWORD*)(a1 + 8) = result;
	return result;
}

//----- (00484D70) --------------------------------------------------------
int __cdecl sub_484D70_light_intensity(int a1, float a2) {
	int result; // eax

	if (a2 > 63.0)
		a2 = 63.0;
	*(float*)(a1 + 4) = a2;
	*(_DWORD*)(a1 + 12) = (__int64)(a2 * *(double*)&qword_581450_9552 + *(double*)&qword_581450_9544);
	result = sub_484C60(a2);
	*(_DWORD*)(a1 + 8) = result;
	return result;
}

//----- (00484DC0) --------------------------------------------------------
int __cdecl sub_484DC0(int2* a1, int2* a2, int* a3) {
	int result; // eax
	int v4;     // ecx
	int v5;     // ebx
	int v6;     // ecx
	int v7;     // edi
	int v8;     // ebx
	int* v9;    // edx
	int v10;    // ecx

	result = (a1->field_4 + 0x8000) >> 16;
	*a3 = result;
	v4 = ((a2->field_4 + 0x8000) >> 16) - result + 1;
	a3[1] = v4;
	if (v4 > 0) {
		v5 = a1->field_0;
		result = (a2->field_0 - a1->field_0) / v4;
		v6 = *a3 + v4;
		if ((int)*a3 < 0) {
			a3[1] = v6;
			*a3 = 0;
		}
		if (v6 > 44) {
			a3[1] += 44 - v6;
			v6 = 44;
		}
		v7 = *a3;
		if ((int)*a3 < v6) {
			v8 = v5 + 0x8000;
			v9 = &a3[v7 + 2];
			v10 = v6 - v7;
			do {
				*v9 = v8 >> 16;
				if (v8 >> 16 < 0)
					*v9 = 0;
				if (*v9 >= 56)
					*v9 = 55;
				v8 += result;
				++v9;
				--v10;
			} while (v10);
		}
	}
	return result;
}
// 484F48: variable 'v3' is possibly undefined

//----- (004854D0) --------------------------------------------------------
int __cdecl sub_4854D0(int2* a1, int2* a2, int2* a3, int a4, float a5) {
	int v5;      // edx
	int v6;      // edi
	int2* v7;    // edi
	int2* v8;    // ebx
	int2* v9;    // esi
	int result;  // eax
	int v11;     // ecx
	int v12[46]; // [esp+10h] [ebp-228h]
	int v13[46]; // [esp+C8h] [ebp-170h]
	int v14[46]; // [esp+180h] [ebp-B8h]

	v5 = a1->field_4;
	v6 = a2->field_4;
	if (v5 > v6) {
		v9 = a3;
		if (v6 <= a3->field_4) {
			v8 = a2;
			v7 = a1;
			goto LABEL_9;
		}
		v8 = a3;
	} else {
		v7 = a3;
		if (v5 <= a3->field_4) {
			v8 = a1;
			v9 = a2;
			goto LABEL_9;
		}
		v8 = a3;
	}
	v9 = a1;
	v7 = a2;
LABEL_9:
	sub_484DC0(v8, v9, v14);
	sub_484DC0(v8, v7, v13);
	sub_4855D0((int)v14, (int)v13, a4, a5);
	result = v9->field_4;
	v11 = v7->field_4;
	if (result >= v11) {
		if (result > v11) {
			sub_484DC0(v7, v9, v12);
			result = sub_4855D0((int)v14, (int)v12, a4, a5);
		}
	} else {
		sub_484DC0(v9, v7, v12);
		result = sub_4855D0((int)v12, (int)v13, a4, a5);
	}
	return result;
}

//----- (004855D0) --------------------------------------------------------
int __cdecl sub_4855D0(int a1, int a2, int a3, float a4) {
	int v4;               // edx
	int v5;               // ecx
	int v6;               // ebp
	int result;           // eax
	double v8;            // st7
	int v9;               // ebx
	double v10;           // st6
	_DWORD* v11;          // edi
	int v12;              // esi
	double v13;           // st5
	double v14;           // st4
	unsigned __int8* v15; // ebx
	double v16;           // st2
	double v17;           // st2
	int v18;              // [esp+1Ch] [ebp+8h]
	int v19;              // [esp+24h] [ebp+10h]

	v4 = a2;
	v5 = *(_DWORD*)a1;
	v6 = *(_DWORD*)a1 + *(_DWORD*)(a1 + 4);
	if (*(_DWORD*)a1 < *(int*)a2)
		v5 = *(_DWORD*)a2;
	if (v6 > *(int*)(a2 + 4) + *(_DWORD*)a2)
		v6 = *(_DWORD*)(a2 + 4) + *(_DWORD*)a2;
	result = v6 - v5;
	if (v6 - v5 > 1) {
		v8 = a4 <= 31.0 ? a4 : 31.0;
		*(float*)&v18 = a4 * a4;
		result = 23 * v5 - *(_DWORD*)(a3 + 4);
		v9 = v5;
		v10 = (double)result;
		v19 = v5;
		if (v5 < v6) {
			v11 = (_DWORD*)(v4 + 4 * v5 + 8);
			result = a1 - v4;
			do {
				v12 = *(_DWORD*)((char*)v11 + result);
				v13 = (double)(int)(23 * v12 - *(_DWORD*)a3);
				if (v12 < *v11) {
					v14 = *getMemFloatPtr(0x587000, 154988) + v8;
					v15 = getMemAt(0x5D4594, 40 * v12 + 2616332 + 5 * v12 + v9);
					do {
						v16 = v14 / ((v13 * v13 + v10 * v10) * *getMemFloatPtr(0x587000, 154984) *
										 *getMemFloatPtr(0x587000, 154972) / *(float*)&v18 +
									 1.0);
						if (v16 > *getMemFloatPtr(0x587000, 154988)) {
							v17 = v16 - *getMemFloatPtr(0x587000, 154988) + (double)*v15;
							if (v17 > 31.0)
								v17 = 31.0;
							*v15 = (__int64)v17;
						}
						++v12;
						v13 = v13 + 23.0;
						v15 += 45;
					} while (v12 < *v11);
					v9 = v19;
					result = a1 - v4;
				}
				v10 = v10 + 23.0;
				++v9;
				++v11;
				v19 = v9;
			} while (v9 < v6);
		}
	}
	return result;
}

//----- (00485AE0) --------------------------------------------------------
unsigned int __cdecl sub_485AE0(int a1, int a2) {
	unsigned __int8* v2; // esi
	int v3;              // ecx
	_BYTE* v4;           // edi
	int v5;              // edx
	int v6;              // eax
	unsigned int result; // eax
	bool v8;             // cc

	v2 = *(unsigned __int8**)&dword_5d4594_1193184;
	v3 = a1;
	v4 = (_BYTE*)(dword_5d4594_1193180 - 1);
	v5 = dword_5d4594_1193176;
	do {
		v6 = *v2++ << 13;
		++v4;
		result = (unsigned int)(v5 + v6) >> 8;
		v5 += a2;
		v8 = v3-- <= 1;
		*v4 = getMemByte(0x5D4594, result + 2589804);
	} while (!v8);
	dword_5d4594_1193176 = v5;
	dword_5d4594_1193184 = v2;
	dword_5d4594_1193180 = v4 + 1;
	return result;
}

//----- (00485B30) --------------------------------------------------------
int __cdecl nox_thing_read_floor_485B30(int a1, char* a2) {
	int v2;              // esi
	_BYTE* v3;           // edi
	int v4;              // eax
	int v5;              // ebp
	const char* v6;      // edx
	int v7;              // ecx
	_BYTE* v9;           // edx
	int v10;             // edi
	int v11;             // ebx
	int* v12;            // eax
	int v13;             // ecx
	char* v14;           // eax
	char v15;            // cl
	int v16;             // [esp-4h] [ebp-40h]
	unsigned __int8 v17; // [esp+10h] [ebp-2Ch]
	int i;               // [esp+10h] [ebp-2Ch]
	unsigned __int8 v19; // [esp+14h] [ebp-28h]
	int v20;             // [esp+14h] [ebp-28h]
	const char* v21;     // [esp+18h] [ebp-24h]
	char v22[32];        // [esp+1Ch] [ebp-20h]
	unsigned __int8 v23; // [esp+40h] [ebp+4h]

	v2 = a1;
	v16 = a1;
	v3 = (_BYTE*)(*(_DWORD*)(a1 + 8) + 4);
	*(_DWORD*)(a1 + 8) = v3;
	LOBYTE(a1) = *v3;
	*(_DWORD*)(v2 + 8) = v3 + 1;
	nox_memfile_read(v22, 1u, (unsigned __int8)a1, v16);
	v4 = dword_5d4594_251568;
	v5 = 0;
	v22[(unsigned __int8)a1] = 0;
	if (v4 <= 0) {
	LABEL_5:
		v7 = a1;
	} else {
		v6 = (const char*)getMemAt(0x5D4594, 2682188);
		while (strcmp(v6, v22)) {
			++v5;
			v6 += 60;
			if (v5 >= *(int*)&dword_5d4594_251568)
				goto LABEL_5;
		}
		v7 = v5;
	}
	if (v5 == dword_5d4594_251568)
		return 0;
	v9 = (_BYTE*)(*(_DWORD*)(v2 + 8) + 12);
	*(_DWORD*)(v2 + 8) = v9;
	LOBYTE(v21) = *v9;
	*(_DWORD*)(v2 + 8) = v9 + 1;
	v19 = v9[1];
	*(_DWORD*)(v2 + 8) = v9 + 2;
	v17 = v9[2];
	*(_DWORD*)(v2 + 8) = v9 + 4;
	v10 = (unsigned __int8)v21 * v19 * v17;
	v20 = 15 * v7;
	*getMemU32Ptr(0x5D4594, 60 * v7 + 2682220) = malloc(4 * v10);
	v11 = 0;
	for (i = 0; v11 < v10;
		 *(_DWORD*)(*getMemU32Ptr(0x5D4594, 4 * v20 + 2682220) + 4 * v11 - 4) = sub_42FAA0(v13, v21, a2)) {
		v12 = *(int**)(v2 + 8);
		v13 = *v12;
		*(_DWORD*)(v2 + 8) = v12 + 1;
		*a2 = getMemByte(0x5D4594, 1193192);
		if (v13 == -1) {
			v14 = *(char**)(v2 + 8);
			v15 = *v14++;
			*(_DWORD*)(v2 + 8) = v14;
			LOBYTE(v21) = v15;
			v23 = *v14;
			*(_DWORD*)(v2 + 8) = v14 + 1;
			nox_memfile_read(a2, 1u, v23, v2);
			v13 = -1;
			a2[v23] = 0;
			v11 = i;
		}
		i = ++v11;
	}
	return 1;
}
// 485CB9: variable 'v21' is possibly undefined
// 485B30: using guessed type char var_20[32];

//----- (00485D40) --------------------------------------------------------
int __cdecl nox_thing_read_edge_485D40(int a1, char* a2) {
	int v2;              // esi
	_BYTE* v3;           // edi
	int v4;              // eax
	int v5;              // ebp
	const char* v6;      // ebx
	int v7;              // ebx
	int result;          // eax
	_BYTE* v9;           // edi
	char v10;            // cl
	unsigned __int8 v11; // dl
	int v12;             // eax
	unsigned __int8 v13; // di
	int v14;             // edi
	int v15;             // ebx
	int* v16;            // eax
	int v17;             // ecx
	char* v18;           // eax
	char v19;            // cl
	int* v20;            // eax
	int v21;             // ecx
	int v22;             // [esp-4h] [ebp-40h]
	int i;               // [esp+10h] [ebp-2Ch]
	int v24;             // [esp+14h] [ebp-28h]
	unsigned int v25;    // [esp+18h] [ebp-24h]
	char v26[64];        // [esp+1Ch] [ebp-20h]
	unsigned __int8 v27; // [esp+40h] [ebp+4h]

	v2 = a1;
	v22 = a1;
	v3 = (_BYTE*)(*(_DWORD*)(a1 + 8) + 4);
	*(_DWORD*)(a1 + 8) = v3;
	LOBYTE(a1) = *v3;
	*(_DWORD*)(v2 + 8) = v3 + 1;
	nox_memfile_read(v26, 1u, (unsigned __int8)a1, v22);
	v4 = dword_5d4594_251572;
	v5 = 0;
	v26[(unsigned __int8)a1] = 0;
	if (v4 <= 0) {
	LABEL_5:
		v7 = a1;
	} else {
		v6 = (const char*)getMemAt(0x5D4594, 2678348);
		while (strcmp(v6, v26)) {
			++v5;
			v6 += 60;
			if (v5 >= *(int*)&dword_5d4594_251572)
				goto LABEL_5;
		}
		v7 = v5;
	}
	if (v5 == dword_5d4594_251572)
		return 0;
	v9 = (_BYTE*)(*(_DWORD*)(v2 + 8) + 9);
	*(_DWORD*)(v2 + 8) = v9;
	v25 = *v9;
	*(_DWORD*)(v2 + 8) = v9 + 2;
	v10 = v9[2];
	*(_DWORD*)(v2 + 8) = v9 + 3;
	if (v10 == 1)
		return 0;
	v11 = v9[3];
	v12 = (int)(v9 + 4);
	*(_DWORD*)(v2 + 8) = v9 + 4;
	v13 = v9[4];
	*(_DWORD*)(v2 + 8) = v12 + 1;
	v14 = 2 * v25 * (v11 + v13);
	result = (int)malloc(5 * v14);
	memset((int*)result, 0, 5 * v14);
	v24 = 15 * v7;
	*getMemU32Ptr(0x5D4594, 60 * v7 + 2678380) = result;
	if (result) {
		v15 = 0;
		for (i = 0; v15 < v14;
			 *(_DWORD*)(*getMemU32Ptr(0x5D4594, 4 * v24 + 2678380) + 4 * v15 - 4) = sub_42FAA0(v17, v25, a2)) {
			v16 = *(int**)(v2 + 8);
			v17 = *v16;
			*(_DWORD*)(v2 + 8) = v16 + 1;
			*a2 = getMemByte(0x5D4594, 1193196);
			if (v17 == -1) {
				v18 = *(char**)(v2 + 8);
				v19 = *v18++;
				*(_DWORD*)(v2 + 8) = v18;
				LOBYTE(v25) = v19;
				v27 = *v18;
				*(_DWORD*)(v2 + 8) = v18 + 1;
				nox_memfile_read(a2, 1u, v27, v2);
				v17 = -1;
				a2[v27] = 0;
				v15 = i;
			}
			i = ++v15;
		}
		v20 = *(int**)(v2 + 8);
		v21 = *v20;
		*(_DWORD*)(v2 + 8) = v20 + 1;
		result = v21 == 1162757152;
	}
	return result;
}
// 485EEB: variable 'v25' is possibly undefined
// 485D40: using guessed type char var_20[32];

//----- (00485F80) --------------------------------------------------------
unsigned int sub_485F80() {
	int v0;               // esi
	int v1;               // eax
	int v2;               // edx
	int i;                // ecx
	int v4;               // edx
	int v5;               // edi
	int v6;               // ecx
	int v7;               // ebx
	unsigned __int8* v8;  // esi
	int j;                // ecx
	unsigned __int8* v12; // esi
	int k;                // ecx
	unsigned int result;  // eax

	v0 = 0;
	v1 = 0;
	v2 = 1;
	for (i = 23; i > 0; --i) {
		*getMemU32Ptr(0x5D4594, 4 * v1 + 3798860) = v0;
		*getMemU32Ptr(0x5D4594, 4 * v1 + 3799052) = i;
		*getMemU32Ptr(0x5D4594, 4 * v1 + 3799244) = v2;
		v0 += v2;
		++v1;
		v2 += 2;
	}
	if (v1 < 46) {
		v4 = 91 - 2 * v1;
		v5 = v1 - 22;
		v6 = 4 * v1;
		v7 = 46 - v1;
		do {
			*getMemU32Ptr(0x5D4594, v6 + 3798860) = v0;
			*getMemU32Ptr(0x5D4594, v6 + 3799052) = v5;
			*getMemU32Ptr(0x5D4594, v6 + 3799244) = v4;
			v0 += v4;
			++v5;
			v4 -= 2;
			v6 += 4;
			--v7;
		} while (v7);
	}
	v8 = getMemAt(0x5D4594, 2614284);
	for (j = -64768; j < 0; j += 256) {
		v8 += 4;
		*((_DWORD*)v8 - 1) = j / 22;
	}
	*getMemU32Ptr(0x5D4594, 2615300) = 0;
	v12 = getMemAt(0x5D4594, 2615304);
	for (k = 0; k < 0x10000; k += 256) {
		v12 += 4;
		*((_DWORD*)v12 - 1) = k / 22;
	}
	return result;
}

//----- (00486060) --------------------------------------------------------
int sub_486060() {
	int result; // eax

	dword_5d4594_1193188 = 1;
	result = 45 * dword_5d4594_3798804;
	*getMemU32Ptr(0x5D4594, 3799236) = 45 * dword_5d4594_3798804 + (46 << getMemByte(0x5D4594, 3807124));
	return result;
}

//----- (00486110) --------------------------------------------------------
void nox_free_pixbuffers_486110() {
	if (!*getMemU32Ptr(0x5D4594, 1193200)) {
		if (nox_pixbuffer_3798780) {
			free(nox_pixbuffer_3798780);
			nox_pixbuffer_3798780 = 0;
		}
		if (nox_pixbuffer_3798788) {
			free(nox_pixbuffer_3798788);
			nox_pixbuffer_3798788 = 0;
		}
	}
	if (nox_pixbuffer_rows_3798784) {
		free(nox_pixbuffer_rows_3798784);
		nox_pixbuffer_rows_3798784 = 0;
	}
	if (nox_pixbuffer_rows_3798776) {
		free(nox_pixbuffer_rows_3798776);
		nox_pixbuffer_rows_3798776 = 0;
	}
}

//----- (00486180) --------------------------------------------------------
int __cdecl sub_486180(void* a1) {
	int result; // eax

	nox_free_pixbuffers_486110();
	nox_pixbuffer_3798780 = a1;
	result = sub_486230();
	*getMemU32Ptr(0x5D4594, 1193200) = 1;
	return result;
}

//----- (004861A0) --------------------------------------------------------
void nox_pixbuffer_swap_4861A0() {
	BYTE* tmp = nox_pixbuffer_3798788;
	nox_pixbuffer_3798788 = nox_pixbuffer_3798780;
	nox_pixbuffer_3798780 = tmp;

	BYTE** tmp2 = nox_pixbuffer_rows_3798784;
	nox_pixbuffer_rows_3798784 = nox_pixbuffer_rows_3798776;
	nox_pixbuffer_rows_3798776 = tmp2;
}

//----- (004861D0) --------------------------------------------------------
int sub_4861D0() {
	if (*getMemU32Ptr(0x5D4594, 1193200))
		return 1;

	nox_pixbuffer_3798780 = calloc(nox_pitch_3801808 * nox_backbuffer_height, 1u);
	if (!nox_pixbuffer_3798780)
		return 0;

	if (!(nox_video_renderTargetFlags & 0x40))
		return 1;

	nox_pixbuffer_3798788 = calloc(nox_pitch_3801808 * nox_backbuffer_height, 1u);
	if (!nox_pixbuffer_3798788) {
		return 0;
	}
	return 1;
}

//----- (00486230) --------------------------------------------------------
int sub_486230() {
	nox_pixbuffer_rows_3798784 = malloc(sizeof(BYTE*) * nox_backbuffer_height);
	if (!nox_pixbuffer_rows_3798784)
		return 0;

	if (nox_backbuffer_height > 0) {
		BYTE **rows = nox_pixbuffer_rows_3798784;
		BYTE *pix = nox_pixbuffer_3798780;
		for (int y = 0; y < nox_backbuffer_height; y++) {
			rows[y] = &pix[y * nox_pitch_3801808];
		}
	}

	if (!(nox_video_renderTargetFlags & 0x40)) {
		return 1;
	}

	nox_pixbuffer_rows_3798776 = malloc(4 * nox_backbuffer_height);
	if (!nox_pixbuffer_rows_3798776)
		return 0;

	if (nox_backbuffer_height > 0) {
		BYTE** rows = nox_pixbuffer_rows_3798776;
		BYTE* pix = nox_pixbuffer_3798788;
		for (int y = 0; y < nox_backbuffer_height; y++) {
			rows[y] = &pix[y * nox_pitch_3801808];
		}
	}
	return 1;
}

//----- (004862E0) --------------------------------------------------------
int __cdecl sub_4862E0(int a3, int a4) {
	*(_DWORD*)a3 = 0;
	*(_QWORD*)(a3 + 24) = sub_416BB0();
	sub_486380((_DWORD*)a3, 0x3E8u, 0, 0x4000);
	sub_486320((_DWORD*)a3, a4);
	return sub_4863B0((unsigned int*)a3);
}

//----- (00486320) --------------------------------------------------------
_DWORD* __cdecl sub_486320(_DWORD* a1, int a2) {
	_DWORD* result; // eax

	result = a1;
	*a1 |= 1u;
	a1[2] = a2 << 16;
	return result;
}

//----- (00486340) --------------------------------------------------------
_DWORD* __cdecl sub_486340(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 |= 1u;
	return result;
}

//----- (00486350) --------------------------------------------------------
int __cdecl sub_486350(int a1, int a2) {
	__int64 v2; // rax
	int v3;     // ecx

	LODWORD(v2) = *(_DWORD*)(a1 + 8);
	v3 = *(_DWORD*)(a1 + 4);
	*(_DWORD*)a1 &= 0xFFFFFFFE;
	if ((_DWORD)v2 == v3) {
		v2 = sub_416BB0();
		*(_QWORD*)(a1 + 24) = v2;
	}
	*(_DWORD*)(a1 + 8) = a2 << 16;
	return v2;
}

//----- (00486380) --------------------------------------------------------
int __cdecl sub_486380(_DWORD* a1, unsigned int a2, int a3, int a4) {
	int result; // eax

	a1[4] = a2;
	a1[3] = (a4 << 16) / a2;
	result = a3;
	a1[5] = a3;
	return result;
}

//----- (004863B0) --------------------------------------------------------
int __cdecl sub_4863B0(unsigned int* a2) {
	signed int v1;        // ebx
	unsigned int v2;      // eax
	int result;           // eax
	__int64 v4;           // rax
	unsigned int v5;      // edi
	unsigned int v6;      // ebp
	unsigned int v7;      // ecx
	unsigned int v8;      // ecx
	unsigned int v9;      // edi
	unsigned __int64 v10; // kr00_8
	signed int v11;       // eax
	unsigned int v12;     // eax
	unsigned int v13;     // ecx
	unsigned int v14;     // eax
	unsigned int v15;     // ecx

	v1 = a2[2] - a2[1];
	if (!v1)
		return 0;
	if (*(_BYTE*)a2 & 1) {
		a2[1] = a2[2];
		v2 = *a2;
		LOBYTE(v2) = *a2 | 2;
		*a2 = v2;
		result = 1;
	} else {
		v4 = sub_416BB0();
		v5 = a2[6];
		v6 = a2[7];
		v7 = v4;
		a2[6] = v4;
		LODWORD(v4) = a2[5];
		a2[7] = HIDWORD(v4);
		v10 = __PAIR64__(HIDWORD(v4), v7) - __PAIR64__(v6, v5);
		v9 = (__PAIR64__(HIDWORD(v4), v7) - __PAIR64__(v6, v5)) >> 32;
		v8 = v10;
		if (__PAIR64__(v9, v10) > __PAIR64__(v4, a2[4]))
			v8 = a2[4];
		v11 = v8 * a2[3];
		if (v1 >= 0) {
			if (v11 <= v1) {
				v15 = v11 + a2[1];
				v14 = *a2;
				LOBYTE(v14) = *a2 | 2;
				a2[1] = v15;
			} else {
				a2[1] += v1;
				v14 = *a2;
				LOBYTE(v14) = *a2 | 2;
			}
			*a2 = v14;
			result = 1;
		} else {
			if (v11 <= -v1) {
				v13 = a2[1] - v11;
				v12 = *a2;
				LOBYTE(v12) = *a2 | 2;
				a2[1] = v13;
			} else {
				a2[1] += v1;
				v12 = *a2;
				LOBYTE(v12) = *a2 | 2;
			}
			*a2 = v12;
			result = 1;
		}
	}
	return result;
}

//----- (004864A0) --------------------------------------------------------
_DWORD* __cdecl sub_4864A0(_DWORD* a3) {
	sub_4862E0((int)a3, 0x4000);
	sub_4862E0((int)(a3 + 8), 100);
	sub_4862E0((int)(a3 + 16), 0x2000);
	sub_486380(a3 + 8, 0x3E8u, 0, 10);
	sub_486380(a3, 0x3E8u, 0, 0x4000);
	sub_486380(a3 + 16, 0x3E8u, 0, 0x4000);
	return sub_486320(a3, 0x4000);
}

//----- (00486520) --------------------------------------------------------
int __cdecl sub_486520(unsigned int* a2) {
	sub_4863B0(a2);
	sub_4863B0(a2 + 8);
	return sub_4863B0(a2 + 16);
}

//----- (00486550) --------------------------------------------------------
BOOL __cdecl sub_486550(_BYTE* a1) { return *a1 & 2 || a1[32] & 2 || a1[64] & 2; }

//----- (00486570) --------------------------------------------------------
int __cdecl sub_486570(unsigned int* a1, _DWORD* a2) {
	int v2; // eax

	sub_486320(a1, ((a2[1] >> 16) * (a1[1] >> 16)) >> 14);
	sub_4863B0(a1);
	sub_486320(a1 + 8, (int)((a2[9] >> 16) * (a1[9] >> 16)) / 100);
	sub_4863B0(a1 + 8);
	if (a2[17] >> 16 != 0x2000) {
		v2 = (a1[17] >> 16) + (a2[17] >> 16) - 0x2000;
		if (v2 >= 0) {
			if ((unsigned int)v2 > 0x4000)
				v2 = 0x4000;
		} else {
			v2 = 0;
		}
		sub_486320(a1 + 16, v2);
	}
	return sub_4863B0(a1 + 16);
}

//----- (00486620) --------------------------------------------------------
_DWORD* __cdecl sub_486620(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 &= 0xFFFFFFFD;
	a1[16] &= 0xFFFFFFFD;
	a1[8] &= 0xFFFFFFFD;
	return result;
}

//----- (00486640) --------------------------------------------------------
int __cdecl sub_486640(int a1, int a2) { return a2 * (*(_DWORD*)(a1 + 36) >> 16) / 100; }

//----- (00486670) --------------------------------------------------------
int __cdecl sub_486670(int a1, int a2) {
	int result; // eax

	result = a2;
	if (a2) {
		result = a2 - 1;
		if (a2 == 1) {
			*getMemU32Ptr(0x587000, 155052) = a1;
		} else {
			result = a2 - 2;
			if (a2 == 2) {
				result = a1;
				*getMemU32Ptr(0x587000, 155056) = a1;
			}
		}
	} else {
		*getMemU32Ptr(0x587000, 155048) = a1;
	}
	return result;
}

//----- (004866A0) --------------------------------------------------------
int __cdecl sub_4866A0(int a1) {
	switch (a1) {
	case 0:
		return *getMemU32Ptr(0x587000, 155048);
	case 1:
		return *getMemU32Ptr(0x587000, 155052);
	case 2:
		return *getMemU32Ptr(0x587000, 155056);
	}
	return 0x4000;
}

//----- (004866D0) --------------------------------------------------------
int __cdecl sub_4866D0(_DWORD* a1, int a2) { return *a1 + 36 * a2; }

//----- (004866F0) --------------------------------------------------------
char* __cdecl sub_4866F0(const char* a1, const char* a2) {
	char* v2;           // ebp
	char* v3;           // eax
	unsigned __int8 v4; // al
	char* v5;           // edi
	FILE* v6;           // ebx
	char* v7;           // eax
	char* v8;           // edi
	unsigned __int8 v9; // cl
	FILE* v10;          // eax
	void* v11;          // edi
	int v12;            // eax
	int v13;            // edi
	int v14;            // esi
	HANDLE v15;         // esi
	char v17[12];
	char v20[260];                         // [esp+1Ch] [ebp-244h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+120h] [ebp-140h]

	v2 = (char*)malloc(0x120u);
	memset(v2, 0, 0x120u);
	strcpy(v20, a1);
	v3 = strrchr(v20, 46);
	if (v3)
		*v3 = 0;
	v4 = getMemByte(0x587000, 155064);
	v5 = &v20[strlen(v20)];
	*(_DWORD*)v5 = *getMemU32Ptr(0x587000, 155060);
	v5[4] = v4;
	v6 = fopen(v20, "rb");
	if (!v6)
		goto LABEL_27;
	v7 = strrchr(v20, 46);
	if (v7)
		*v7 = 0;
	v8 = &v20[strlen(v20) + 1];
	v9 = getMemByte(0x587000, 155076);
	*(_DWORD*)--v8 = *getMemU32Ptr(0x587000, 155072);
	v8[4] = v9;
	v10 = fopen(v20, "rb");
	*((_DWORD*)v2 + 67) = v10;
	if (!v10 || sub_40ADD0_fread(v17, 0xCu, 1u, v6) != 1)
		goto LABEL_27;
	*((_DWORD*)v2 + 1) = *(_DWORD*)&v17[8];
	if (*(int*)&v17[8] <= 0)
		goto LABEL_14;
	v11 = malloc(36 * *(_DWORD*)&v17[8]);
	v12 = *((_DWORD*)v2 + 1);
	*(_DWORD*)v2 = v11;
	memset(v11, 0, 4 * ((unsigned int)(36 * v12) >> 2));
	if (*(_DWORD*)&v17[4] != 1) {
		if (sub_40ADD0_fread(*(char**)v2, 36 * *((_DWORD*)v2 + 1), 1u, v6) == 1)
			goto LABEL_14;
	LABEL_27:
		if (v2)
			sub_4869C0(v2);
		if (v6)
			fclose(v6);
		return 0;
	}
	v13 = 0;
	if (*((_DWORD*)v2 + 1) > 0) {
		v14 = 0;
		while (sub_40ADD0_fread((char*)(v14 + *(_DWORD*)v2), 0x20u, 1u, v6) == 1) {
			++v13;
			*(_DWORD*)(*(_DWORD*)v2 + v14 + 32) = 0;
			v14 += 36;
			if (v13 >= *((_DWORD*)v2 + 1))
				goto LABEL_14;
		}
		goto LABEL_27;
	}
LABEL_14:
	fclose(v6);
	qsort(*(void**)v2, *((_DWORD*)v2 + 1), 0x24u, (int(__cdecl*)(const void*, const void*))_strcmpi);
	*((_DWORD*)v2 + 69) = 0;
	if (a2) {
		strcpy(v2 + 8, a2);
		if (v2[strlen(v2 + 8) + 8] == 92)
			v2[strlen(v2 + 8) + 8] = 0;
		v15 = FindFirstFileA(v2 + 8, &FindFileData);
		if (v15 != (HANDLE)-1) {
			if (FindFileData.dwFileAttributes & 0x10) {
			LABEL_21:
				*((_DWORD*)v2 + 69) = 1;
			} else {
				while (FindNextFileA(v15, &FindFileData)) {
					if (FindFileData.dwFileAttributes & 0x10)
						goto LABEL_21;
				}
			}
			FindClose(v15);
		}
		if (v2[strlen(v2 + 8) + 8] != 92)
			*(_WORD*)&v2[strlen(v2 + 8) + 8] = *getMemU16Ptr(0x587000, 155084);
	}
	return v2;
}
// 4866F0: using guessed type char var_244[260];

//----- (004869C0) --------------------------------------------------------
void __cdecl sub_4869C0(LPVOID lpMem) {
	if (*((_DWORD*)lpMem + 67))
		fclose(*((FILE**)lpMem + 67));
	if (*((_DWORD*)lpMem + 68))
		fclose(*((FILE**)lpMem + 68));
	if (*(_DWORD*)lpMem)
		free(*(LPVOID*)lpMem);
	free(lpMem);
}

//----- (00486A10) --------------------------------------------------------
unsigned int __cdecl sub_486A10(int a1, void* a2) {
	void* v2;            // eax
	unsigned int result; // eax

	v2 = bsearch(a2, *(const void**)a1, *(_DWORD*)(a1 + 4), 0x24u, (int(__cdecl*)(const void*, const void*))_strcmpi);
	if (v2)
		result = ((unsigned int)v2 - *(_DWORD*)a1) / 0x24;
	else
		result = -1;
	return result;
}

//----- (00486A50) --------------------------------------------------------
char* __cdecl sub_486A50(_DWORD* a1, int a2) {
	char* result; // eax

	if (a2 < 0 || a2 >= a1[1])
		result = (char*)getMemAt(0x587000, 155088);
	else
		result = (char*)sub_4866D0(a1, a2);
	return result;
}

//----- (00486A80) --------------------------------------------------------
int __cdecl sub_486A80(_DWORD* a1, int a2) {
	int result; // eax

	if (a2 < 0 || a2 >= a1[1])
		result = 0;
	else
		result = *(_DWORD*)(*a1 + 36 * a2 + 20);
	return result;
}

//----- (00486AA0) --------------------------------------------------------
int __cdecl sub_486AA0(_DWORD* a1, int a2, _DWORD* a3) {
	_DWORD* v3; // eax
	int result; // eax

	v3 = (_DWORD*)sub_4866D0(a1, a2);
	*a3 = 4;
	a3[2] = v3[6];
	a3[3] = ((v3[7] & 1) != 0) + 1;
	a3[6] = v3[8];
	if (v3[7] & 8) {
		result = 2;
		a3[1] = 2;
		a3[4] = 2;
	} else {
		a3[1] = 0;
		result = ((v3[7] & 4) != 0) + 1;
		a3[4] = result;
	}
	return result;
}

//----- (00486B10) --------------------------------------------------------
int __cdecl sub_486B10(_DWORD* a1, int a2, _DWORD* a3) {
	int result; // eax
	int v4;     // edx

	result = sub_4866D0(a1, a2);
	v4 = a3[2];
	*(_DWORD*)(result + 28) = 0;
	*(_DWORD*)(result + 24) = v4;
	if (a3[3] == 2)
		*(_DWORD*)(result + 28) = 1;
	if (a3[4] == 2)
		*(_DWORD*)(result + 28) |= 4u;
	return result;
}

//----- (00486B60) --------------------------------------------------------
int __cdecl sub_486B60(int a1, int a2) {
	int v2;       // ebp
	FILE* v3;     // eax
	FILE* v6;     // eax
	FILE* v7;     // esi
	int v8;       // edi
	int v9;       // eax
	int v10;      // ecx
	int v12;      // [esp+10h] [ebp-12Ch]
	char v13[8];  // [esp+14h] [ebp-128h]
	char v14[16]; // [esp+1Ch] [ebp-120h]
	int v15[12];  // [esp+2Ch] [ebp-110h]

	v12 = 1;
	v2 = sub_4866D0((_DWORD*)a1, a2);
	sub_486E00(a1);
	v3 = *(FILE**)(a1 + 268);
	*(_DWORD*)(a1 + 280) = v3;
	*(_DWORD*)(a1 + 284) = *(_DWORD*)(v2 + 20);
	if (fseek(v3, *(_DWORD*)(v2 + 16), 0))
		v12 = 0;
	if (!*(_DWORD*)(v2 + 20))
		v12 = 0;
	if (!*(_DWORD*)(a1 + 276))
		return v12;
	strcpy((char*)&v15[3], (const char*)(a1 + 8));
	strcat((char*)&v15[3], (const char*)v2);
	strcat((char*)&v15[3], ".wav");
	v6 = fopen((const char*)&v15[3], "rb");
	v7 = v6;
	v8 = 0;
	*(_DWORD*)(a1 + 272) = v6;
	if (!v6)
		return v12;
	if (sub_40ADD0_fread((char*)v15, 0xCu, 1u, v6) != 1 || v15[0] != 1179011410 || v15[2] != 1163280727) {
		printf("error: '%s' is bad - cannot read\n", &v15[3]);
		if (*(_DWORD*)(a1 + 272)) {
			fclose(*(FILE**)(a1 + 272));
			*(_DWORD*)(a1 + 272) = 0;
		}
		return v12;
	}
	if (sub_40ADD0_fread(v13, 8u, 1u, v7) != 1)
		goto LABEL_18;
	while (1) {
		if (*(_DWORD*)v13 == 544501094) {
			sub_40ADD0_fread(v14, 0x10u, 1u, v7);
			fseek(v7, *(_DWORD*)&v13[4] - 16, 1);
			goto LABEL_15;
		}
		if (*(_DWORD*)v13 == 1635017060)
			break;
		fseek(v7, *(int*)&v13[4], 1);
	LABEL_15:
		if (sub_40ADD0_fread(v13, 8u, 1u, v7) != 1)
			goto LABEL_18;
	}
	v8 = *(_DWORD*)&v13[4];
LABEL_18:
	*(_DWORD*)(v2 + 28) = 2;
	if (*(unsigned __int16*)&v14[12] / (int)*(unsigned __int16*)&v14[2] == 2)
		*(_DWORD*)(v2 + 28) = 6;
	if (*(_WORD*)&v14[2] == 2) {
		v9 = *(_DWORD*)(v2 + 28);
		LOBYTE(v9) = v9 | 1;
		*(_DWORD*)(v2 + 28) = v9;
	}
	*(_DWORD*)(v2 + 24) = *(_DWORD*)&v14[4];
	v10 = *(_DWORD*)(a1 + 272);
	*(_DWORD*)(a1 + 284) = v8;
	*(_DWORD*)(a1 + 280) = v10;
	return 1;
}

//----- (00486DB0) --------------------------------------------------------
signed int __cdecl sub_486DB0(int a1, char* a2, signed int a3) {
	signed int result; // eax
	signed int v4;     // eax

	if (!*(_DWORD*)(a1 + 280))
		return 0;
	v4 = a3;
	if (a3 > *(int*)(a1 + 284))
		v4 = *(_DWORD*)(a1 + 284);
	if (v4 <= 0 || (result = sub_40ADD0_fread(a2, 1u, v4, *(FILE**)(a1 + 280)), result < 0))
		result = 0;
	*(_DWORD*)(a1 + 284) -= result;
	return result;
}

//----- (00486E00) --------------------------------------------------------
FILE* __cdecl sub_486E00(int a1) {
	FILE* result; // eax

	result = *(FILE**)(a1 + 272);
	*(_DWORD*)(a1 + 280) = 0;
	if (result) {
		result = (FILE*)fclose(result);
		*(_DWORD*)(a1 + 272) = 0;
	}
	return result;
}

//----- (00486E30) --------------------------------------------------------
int __cdecl sub_486E30(int a1, _DWORD* a2) {
	int result; // eax

	a2[33] = a1;
	++*(_DWORD*)(a1 + 192);
	++*(_DWORD*)(a1 + 212);
	sub_4258E0(a1 + 200, a2);
	result = *(_DWORD*)(a1 + 212) - 1;
	*(_DWORD*)(a1 + 212) = result;
	if (result < 0)
		*(_DWORD*)(a1 + 212) = 0;
	return result;
}

//----- (00486E90) --------------------------------------------------------
int __cdecl sub_486E90(int a1) {
	int v1;     // esi
	int result; // eax

	v1 = *(_DWORD*)(a1 + 132);
	sub_425920((_DWORD**)a1);
	--*(_DWORD*)(v1 + 192);
	++*(_DWORD*)(v1 + 212);
	sub_425920((_DWORD**)a1);
	result = *(_DWORD*)(v1 + 212) - 1;
	*(_DWORD*)(v1 + 212) = result;
	if (result < 0)
		*(_DWORD*)(v1 + 212) = 0;
	return result;
}

//----- (00486EF0) --------------------------------------------------------
void* sub_486EF0() {
	void* result; // eax
	int* v1;      // esi
	int i;        // edi

	result = *(void**)&dword_5d4594_1193336;
	if (dword_5d4594_1193336) {
		result = *(void**)&dword_587000_155144;
		if (!*(_DWORD*)(dword_587000_155144 + 24)) {
			v1 = *(int**)(dword_587000_155144 + 12);
			for (i = dword_587000_155144 + 12; v1 != (int*)i; v1 = (int*)*v1) {
				if (!(v1[3] & 2))
					result = (void*)((int(__cdecl*)(int*))v1[54])(v1);
			}
		}
	}
	return result;
}

//----- (00486F30) --------------------------------------------------------
int sub_486F30() {
	sub_425760(*(_DWORD**)&dword_587000_155144);
	sub_425760((_DWORD*)(dword_587000_155144 + 12));
	*(_DWORD*)(dword_587000_155144 + 24) = 0;
	*getMemU32Ptr(0x5D4594, 1193340) = dword_587000_155144 + 32;
	sub_4864A0((_DWORD*)(dword_587000_155144 + 32));
	dword_5d4594_1193336 = 1;
	return 0;
}

//----- (00486FA0) --------------------------------------------------------
_DWORD* __cdecl sub_486FA0(int a1) {
	_DWORD* result; // eax
	_DWORD* v2;     // edi
	int v3;         // eax

	result = sub_486FE0(a1);
	v2 = result;
	if (result) {
		v3 = *(_DWORD*)(a1 + 12);
		LOBYTE(v3) = v3 | 1;
		*(_DWORD*)(a1 + 12) = v3;
		sub_487050(v2);
		if (*(_BYTE*)(a1 + 8) & 2)
			*getMemU32Ptr(0x5D4594, 1193332) = 1;
		result = v2;
	}
	return result;
}

//----- (00486FE0) --------------------------------------------------------
_DWORD* __cdecl sub_486FE0(int a1) {
	_DWORD* v1; // esi

	v1 = malloc(0x58u);
	memset(v1, 0, 0x58u);
	sub_425770(v1);
	v1[4] = 0;
	v1[3] = a1;
	if (!(*(int(__cdecl**)(_DWORD*))(a1 + 20))(v1))
		return v1;
	if (v1)
		sub_487030(v1);
	return 0;
}

//----- (00487030) --------------------------------------------------------
void __cdecl sub_487030(LPVOID lpMem) {
	(*(void(__cdecl**)(LPVOID))(*((_DWORD*)lpMem + 3) + 24))(lpMem);
	*(_DWORD*)(*((_DWORD*)lpMem + 3) + 12) &= 0xFFFFFFFE;
	free(lpMem);
}

//----- (00487050) --------------------------------------------------------
_DWORD* __cdecl sub_487050(_DWORD* a1) { return sub_4258E0(*(int*)&dword_587000_155144, a1); }

//----- (00487070) --------------------------------------------------------
void __cdecl sub_487070(LPVOID lpMem) {
	sub_487090((_DWORD**)lpMem);
	sub_487030(lpMem);
	*getMemU32Ptr(0x5D4594, 1193332) = 0;
}

//----- (00487090) --------------------------------------------------------
_DWORD** __cdecl sub_487090(_DWORD** a1) { return sub_425920(a1); }

//----- (004870A0) --------------------------------------------------------
void sub_4870A0() {
	int* v1; // edi
	int* v2; // esi
	int* v3; // [esp+4h] [ebp-4h]

	v1 = sub_4870E0((int*)&v3);
	if (v1) {
		do {
			v2 = sub_487100(&v3);
			sub_487070(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004870E0) --------------------------------------------------------
int* __cdecl sub_4870E0(int* a1) {
	int* result; // eax

	result = sub_425890(*(int**)&dword_587000_155144);
	*a1 = (int)result;
	return result;
}

//----- (00487100) --------------------------------------------------------
int* __cdecl sub_487100(int** a1) {
	if (*a1)
		*a1 = sub_4258A0(*a1);
	return *a1;
}

//----- (00487120) --------------------------------------------------------
int sub_487120() {
	int v0;  // esi
	int* i;  // eax
	int* v3; // [esp+4h] [ebp-4h]

	v0 = 0;
	for (i = sub_4870E0((int*)&v3); i; i = sub_487100(&v3))
		v0 += i[5];
	return v0;
}

//----- (00487150) --------------------------------------------------------
_DWORD* __cdecl sub_487150(int a1, const void* a2) {
	int v2;     // edi
	_DWORD* v3; // esi
	_DWORD* v4; // eax
	int v6;     // [esp+8h] [ebp-4h]

	v2 = a1;
	if (a1 == -1)
		v2 = 0;
	sub_487360(v2, (int**)&a1, &v6);
	if (!a1)
		return 0;
	v3 = *(_DWORD**)(a1 + 4 * v6 + 24);
	if (!v3) {
		v4 = sub_4871C0(a1, v6, a2);
		v3 = v4;
		if (!v4)
			return 0;
		v4[47] = v2;
		sub_487310(v4);
	}
	++v3[4];
	return v3;
}

//----- (004871C0) --------------------------------------------------------
_DWORD* __cdecl sub_4871C0(int a1, int a2, const void* a3) {
	int v3;     // ebp
	_DWORD* v4; // esi

	v3 = *(_DWORD*)(a1 + 12);
	v4 = malloc(0x108u);
	memset(v4, 0, 0x108u);
	sub_425770(v4);
	v4[6] = a2;
	v4[5] = a1;
	v4[4] = 0;
	++*(_DWORD*)(a1 + 16);
	*(_DWORD*)(a1 + 4 * a2 + 24) = v4;
	v4[64] = *(_DWORD*)(v3 + 36);
	sub_425760(v4 + 50);
	sub_4864A0(v4 + 22);
	v4[53] = 0;
	v4[56] = 33;
	v4[60] = 0;
	v4[58] = 0;
	v4[62] = 0;
	v4[54] = sub_4873C0;
	v4[57] = 0;
	v4[61] = 0;
	v4[59] = 0;
	v4[63] = 0;
	nullsub_10(v4 + 15);
	nullsub_10(v4 + 8);
	if (a3)
		sub_487590((int)v4, a3);
	if (!(*(int(__cdecl**)(_DWORD*))(v3 + 28))(v4))
		return v4;
	if (v4)
		sub_4872C0(v4);
	return 0;
}
// 487CF0: using guessed type void __cdecl nullsub_10(_DWORD);

//----- (004872C0) --------------------------------------------------------
void __cdecl sub_4872C0(LPVOID lpMem) {
	int v1; // eax
	int v2; // ecx

	sub_487910((int)lpMem, -1);
	(*(void(__cdecl**)(LPVOID))(*(_DWORD*)(*((_DWORD*)lpMem + 5) + 12) + 32))(lpMem);
	*(_DWORD*)(*((_DWORD*)lpMem + 5) + 4 * *((_DWORD*)lpMem + 6) + 24) = 0;
	v1 = *((_DWORD*)lpMem + 5);
	v2 = *(_DWORD*)(v1 + 16) - 1;
	*(_DWORD*)(v1 + 16) = v2;
	if (v2 < 0)
		*(_DWORD*)(*((_DWORD*)lpMem + 5) + 16) = 0;
	free(lpMem);
}

//----- (00487310) --------------------------------------------------------
int __cdecl sub_487310(_DWORD* a1) {
	int result; // eax

	++*(_DWORD*)(dword_587000_155144 + 24);
	sub_4258E0(dword_587000_155144 + 12, a1);
	result = *(_DWORD*)(dword_587000_155144 + 24) - 1;
	*(_DWORD*)(dword_587000_155144 + 24) = result;
	if (result < 0)
		*(_DWORD*)(dword_587000_155144 + 24) = 0;
	return result;
}

//----- (00487360) --------------------------------------------------------
int* __cdecl sub_487360(int a1, int** a2, int* a3) {
	int* result; // eax
	int i;       // esi
	int v5;      // ecx
	int* v6;     // [esp+4h] [ebp-4h]

	result = sub_4870E0((int*)&v6);
	for (i = a1; result; result = sub_487100(&v6)) {
		v5 = result[5];
		if (i < v5)
			break;
		i -= v5;
	}
	*a2 = result;
	if (result) {
		result = a3;
		*a3 = i;
	} else {
		*a3 = -1;
	}
	return result;
}

//----- (004873C0) --------------------------------------------------------
int __cdecl sub_4873C0(int a3) {
	int v1;           // esi
	__int64 v3;       // rax
	unsigned int v4;  // ecx
	int v5;           // ebp
	bool v6;          // cf
	unsigned int v7;  // ebx
	unsigned int v8;  // ecx
	int v9;           // edi
	unsigned int v10; // eax
	_DWORD* v11;      // ebx
	int v12;          // edi
	int v13;          // ebp
	_DWORD* v14;      // esi
	int v15;          // [esp+10h] [ebp-Ch]
	int v16;          // [esp+18h] [ebp-4h]
	BOOL v17;         // [esp+20h] [ebp+4h]

	v1 = a3;
	if (*(_DWORD*)(a3 + 212))
		return -2146304000;
	v3 = sub_416BB0();
	v4 = *(_DWORD*)(a3 + 248);
	v5 = v3;
	v6 = (unsigned int)v3 < v4;
	v7 = v3 - v4;
	v8 = *(_DWORD*)(a3 + 224);
	v16 = HIDWORD(v3);
	v9 = HIDWORD(v3) - (v6 + *(_DWORD*)(a3 + 252));
	v10 = *(_DWORD*)(a3 + 228);
	if (__PAIR64__(v9, v7) >= __PAIR64__(v10, v8)) {
		*(_DWORD*)(a3 + 232) = v7;
		*(_DWORD*)(a3 + 236) = v9;
		if (*(_QWORD*)(a3 + 240) > 10 * __PAIR64__(v10, v8)) {
			*(_DWORD*)(a3 + 240) = 0;
			*(_DWORD*)(a3 + 244) = 0;
		}
		if (__PAIR64__(v9, v7) > *(_QWORD*)(a3 + 240)) {
			*(_DWORD*)(a3 + 240) = v7;
			*(_DWORD*)(a3 + 244) = v9;
		}
		v11 = (_DWORD*)(a3 + 88);
		v15 = a3 + 88;
		sub_486520((unsigned int*)(a3 + 88));
		if (*(_DWORD*)(a3 + 184))
			sub_486520(*(unsigned int**)(a3 + 184));
		if (!*(_DWORD*)(a3 + 184) || !(v17 = sub_486550(*(_BYTE**)(a3 + 184))))
			v17 = sub_486550((_BYTE*)(v1 + 88));
		*(_DWORD*)(v1 + 248) = v5;
		*(_DWORD*)(v1 + 252) = v16;
		v12 = *(_DWORD*)(v1 + 200);
		if (v12 != v1 + 200) {
			do {
				v13 = *(_DWORD*)v12;
				if (*(_BYTE*)(v12 + 124) & 1 && *(_DWORD*)(v12 + 288)) {
					if ((sub_486520((unsigned int*)(v12 + 16)), v17) || sub_486550((_BYTE*)(v12 + 16)) ||
						*(_DWORD*)(v12 + 116) && sub_486550(*(_BYTE**)(v12 + 116)) ||
						*(_DWORD*)(v12 + 112) && sub_486550(*(_BYTE**)(v12 + 112))) {
						sub_4BD840(v12);
						(*(void(__cdecl**)(int))(*(_DWORD*)(v12 + 172) + 32))(v12);
					}
				}
				v12 = v13;
			} while (v13 != v1 + 200);
			v11 = (_DWORD*)v15;
		}
		v14 = *(_DWORD**)(v1 + 184);
		if (v14)
			sub_486620(v14);
		sub_486620(v11);
	}
	return 0;
}

//----- (00487590) --------------------------------------------------------
int __cdecl sub_487590(int a1, const void* a2) {
	int result; // eax

	result = a1;
	memcpy((void*)(a1 + 60), a2, 0x1Cu);
	return result;
}

//----- (004875B0) --------------------------------------------------------
int* __cdecl sub_4875B0(int* a1) {
	int* result; // eax

	result = sub_425890((int*)(dword_587000_155144 + 12));
	*a1 = (int)result;
	return result;
}

//----- (004875D0) --------------------------------------------------------
int* __cdecl sub_4875D0(int** a1) {
	if (*a1)
		*a1 = sub_4258A0(*a1);
	return *a1;
}

//----- (004875F0) --------------------------------------------------------
int sub_4875F0() {
	int* v0;    // edi
	int* v1;    // esi
	int result; // eax
	int* v3;    // [esp+4h] [ebp-4h]

	++*(_DWORD*)(dword_587000_155144 + 24);
	v0 = sub_4875B0((int*)&v3);
	if (v0) {
		do {
			v1 = sub_4875D0(&v3);
			sub_487680(v0);
			v0 = v1;
		} while (v1);
	}
	result = *(_DWORD*)(dword_587000_155144 + 24) - 1;
	*(_DWORD*)(dword_587000_155144 + 24) = result;
	if (result < 0)
		*(_DWORD*)(dword_587000_155144 + 24) = 0;
	return result;
}

//----- (00487650) --------------------------------------------------------
void __cdecl sub_487650(_DWORD* lpMem) {
	int v2; // ecx

	v2 = lpMem[4] - 1;
	lpMem[4] = v2;
	if (v2 < 0)
		lpMem[4] = 0;
	sub_487680(lpMem);
}

//----- (00487680) --------------------------------------------------------
void __cdecl sub_487680(LPVOID lpMem) {
	sub_4876A0((_DWORD**)lpMem);
	sub_4872C0(lpMem);
}

//----- (004876A0) --------------------------------------------------------
void* __cdecl sub_4876A0(_DWORD** a1) {
	void* result; // eax

	++*(_DWORD*)(dword_587000_155144 + 24);
	sub_425920(a1);
	result = (void*)(*(_DWORD*)(dword_587000_155144 + 24) - 1);
	*(_DWORD*)(dword_587000_155144 + 24) = result;
	if ((int)result < 0) {
		result = *(void**)&dword_587000_155144;
		*(_DWORD*)(dword_587000_155144 + 24) = 0;
	}
	return result;
}

//----- (004876E0) --------------------------------------------------------
int sub_4876E0() { return -2147221504; }

//----- (004876F0) --------------------------------------------------------
_DWORD* __cdecl sub_4876F0(int a1, int a2) { return sub_486320((_DWORD*)(a1 + 88), a2); }

//----- (00487710) --------------------------------------------------------
int __cdecl sub_487710(int a1, int a2) { return sub_486350(a1 + 88, a2); }

//----- (00487730) --------------------------------------------------------
int __cdecl sub_487730(int a1) { return *(_DWORD*)(a1 + 196); }

//----- (00487740) --------------------------------------------------------
int __cdecl sub_487740(int a1) { return *(_DWORD*)(a1 + 192); }

//----- (00487750) --------------------------------------------------------
_DWORD* __cdecl sub_487750(int a1) {
	_DWORD* v1; // eax
	_DWORD* v2; // esi

	if (*(int*)(a1 + 192) >= *(int*)(a1 + 196))
		return 0;
	v1 = sub_4BD720(a1);
	v2 = v1;
	if (!v1)
		return 0;
	sub_486E30(a1, v1);
	return v2;
}

//----- (00487790) --------------------------------------------------------
int __cdecl sub_487790(int a1, int a2) {
	int v2; // esi
	int v3; // edi

	v2 = 0;
	if (sub_487750(a1)) {
		v3 = a2;
		do {
			++v2;
			--v3;
		} while (v3 && sub_487750(a1));
	}
	return v2;
}

//----- (004877D0) --------------------------------------------------------
int* __cdecl sub_4877D0(int a1, int* a2) {
	int* result; // eax

	result = sub_425890((int*)(a1 + 200));
	*a2 = (int)result;
	return result;
}

//----- (004877F0) --------------------------------------------------------
int* __cdecl sub_4877F0(int** a1) {
	if (*a1)
		*a1 = sub_4258A0(*a1);
	return *a1;
}

//----- (00487810) --------------------------------------------------------
int* __cdecl sub_487810(int a1, int a2) {
	unsigned int v2; // esi
	int v3;          // edi
	int* v4;         // ebp
	int* result;     // eax
	int v6;          // ecx
	unsigned int v7; // edx
	int v8;          // [esp+10h] [ebp-8h]
	int* v9;         // [esp+14h] [ebp-4h]

	v2 = -1;
	if (a2 == -1)
		a2 = 1;
	v3 = 127;
	v4 = 0;
	v8 = 127;
	v9 = 0;
	for (result = sub_4877D0(a1, &a1); result; result = sub_4877F0((int**)&a1)) {
		if (result[3] == a2) {
			if (!(result[31] & 0x15))
				return result;
			v6 = result[30];
			if (result[31] & 1) {
				if (v6 >= v3) {
					if (v6 == v3) {
						v7 = result[45];
						if (v7 < v2 && v2 - v7 >= 0x666) {
							v3 = result[30];
							v4 = result;
							v2 = result[45];
						}
					}
				} else {
					v2 = result[45];
					v3 = result[30];
					v4 = result;
				}
			} else if (v6 < v8) {
				v8 = result[30];
				v9 = result;
			}
		}
	}
	result = v9;
	if (!v9 || v8 > v3)
		result = v4;
	return result;
}

//----- (004878E0) --------------------------------------------------------
int* __cdecl sub_4878E0(int a1, int a2) {
	int* v2; // eax
	int* v3; // esi

	v2 = sub_487810(a1, 1);
	v3 = v2;
	if (v2)
		sub_4BDA10((int)v2, a2);
	return v3;
}

//----- (00487910) --------------------------------------------------------
int __cdecl sub_487910(int a1, int a2) {
	int* v2; // edi
	int v3;  // ebx
	int* v4; // esi

	v2 = sub_4877D0(a1, &a1);
	if (!v2)
		return 0;
	v3 = a2;
	do {
		v4 = sub_4877F0((int**)&a1);
		if (v3 == -1 || v2[3] == v3)
			sub_4BDA60(v2);
		v2 = v4;
	} while (v4);
	return 0;
}

//----- (00487970) --------------------------------------------------------
int* __cdecl sub_487970(int a1, int a2) {
	int* result; // eax
	int* v3;     // edi
	int v4;      // ebx
	int* v5;     // esi

	result = sub_4877D0(a1, &a1);
	v3 = result;
	if (result) {
		v4 = a2;
		do {
			result = sub_4877F0((int**)&a1);
			v5 = result;
			if (v4 == -1 || v3[3] == v4)
				result = (int*)sub_4BDA80((int)v3);
			v3 = v5;
		} while (v5);
	}
	return result;
}

//----- (004879C0) --------------------------------------------------------
int* __cdecl sub_4879C0(int a1, int a2) {
	int* result; // eax
	int v3;      // esi

	result = sub_4877D0(a1, &a1);
	if (result) {
		v3 = a2;
		do {
			if (result[31] & 1 && (v3 == -1 || result[3] == v3))
				sub_4BDAC0((int)result);
			result = sub_4877F0((int**)&a1);
		} while (result);
	}
	return result;
}

//----- (00487A10) --------------------------------------------------------
int* __cdecl sub_487A10(int a1, int a2) {
	int* result; // eax
	int v3;      // esi

	result = sub_4877D0(a1, &a1);
	if (result) {
		v3 = a2;
		do {
			if (result[31] & 4 && (v3 == -1 || result[3] == v3))
				sub_4BDAF0((int)result);
			result = sub_4877F0((int**)&a1);
		} while (result);
	}
	return result;
}

//----- (00487A60) --------------------------------------------------------
int __cdecl sub_487A60(int a1) { return (*(int(__cdecl**)(int))(a1 + 216))(a1); }

//----- (00487A70) --------------------------------------------------------
int __cdecl sub_487A70(_DWORD* a1, int(__cdecl* a2)(char*)) {
	int* v2;             // eax
	int i;               // edi
	unsigned __int8* v4; // esi
	int v5;              // ecx
	unsigned __int8* v6; // edx
	int* v8;             // [esp+Ch] [ebp-CCh]
	char v9[200];        // [esp+10h] [ebp-C8h]

	a2((char*)getMemAt(0x587000, 155148));
	nox_sprintf(v9, "%s (%d)\n", **(_DWORD**)(a1[5] + 12), a1[47]);
	a2(v9);
	nox_sprintf(v9, "si: %05d ms (%05d,%d) \n", a1[56], a1[58], a1[60]);
	a2(v9);
	nox_sprintf(v9, "Chan:TYPE: STATE :  SAMPLE  :PRI :VOL:\n");
	a2(v9);
	v2 = sub_4877D0((int)a1, (int*)&v8);
	for (i = 0; v2; v2 = sub_4877F0(&v8)) {
		if (v2[31] & 1) {
			v4 = getMemAt(0x587000, 155264);
		} else {
			v4 = getMemAt(0x587000, 155272);
			if (!(v2[31] & 4))
				v4 = getMemAt(0x587000, 155280);
		}
		v5 = v2[3];
		if (v5 < 4096) {
			v6 = getMemAt(0x587000, 155296);
			if (v5 != 1)
				v6 = getMemAt(0x587000, 155304);
		} else {
			v6 = getMemAt(0x587000, 155288);
		}
		nox_sprintf(v9, "#%2d :%s:%s:0x%08x:%4d:%3d:\n", i, v6, v4, v2[72], v2[30],
					(100 * ((unsigned int)v2[45] >> 16)) >> 14);
		a2(v9);
		++i;
	}
	return ((int(__cdecl*)(unsigned __int8*))a2)(getMemAt(0x587000, 155344));
}

//----- (00487BC0) --------------------------------------------------------
_DWORD* __cdecl sub_487BC0(size_t a1) {
	_DWORD* v1; // esi
	void* v2;   // eax

	v1 = malloc(0x1Cu);
	memset(v1, 0, 0x1Cu);
	sub_487C30(v1);
	v1[1] = a1;
	v2 = malloc(a1);
	*v1 = v2;
	if (v2)
		return v1;
	if (v1)
		sub_487C10(v1);
	return 0;
}

//----- (00487C10) --------------------------------------------------------
void __cdecl sub_487C10(LPVOID lpMem) {
	if (*(_DWORD*)lpMem)
		free(*(LPVOID*)lpMem);
	free(lpMem);
}

//----- (00487C30) --------------------------------------------------------
_DWORD* __cdecl sub_487C30(_DWORD* a1) {
	*a1 = 0;
	a1[1] = 0;
	a1[5] = 0;
	a1[6] = 0;
	return sub_425760(a1 + 2);
}

//----- (00487C50) --------------------------------------------------------
int __cdecl sub_487C50(int a1, _DWORD* a2) {
	int result; // eax

	sub_4258E0(a1 + 8, a2);
	result = a2[4] + *(_DWORD*)(a1 + 4);
	*(_DWORD*)(a1 + 4) = result;
	a2[5] = a1;
	return result;
}

//----- (00487C80) --------------------------------------------------------
int __cdecl sub_487C80(int a1) { return sub_425940((int*)(a1 + 8)); }

//----- (00487CB0) --------------------------------------------------------
int __cdecl sub_487CB0(int a1, int a2) { return a2 * *(_DWORD*)(a1 + 20) / 1000; }

//----- (00487CD0) --------------------------------------------------------
__int64 __cdecl sub_487CD0(int a1, int a2) { return 1000 * a2 / *(_DWORD*)(a1 + 20); }

//----- (00487D00) --------------------------------------------------------
int __cdecl sub_487D00(_DWORD* a1) {
	int v1;     // edx
	int result; // eax

	v1 = a1[1];
	result = a1[2] * a1[3] * a1[4];
	a1[5] = result;
	if (v1 == 1) {
		result >>= 2;
		a1[5] = result;
	}
	return result;
}

//----- (00487D30) --------------------------------------------------------
_DWORD* __cdecl sub_487D30(_DWORD* a1, int a2, int a3) {
	_DWORD* result; // eax

	a1[4] = a3;
	a1[3] = a2;
	result = sub_425770(a1);
	a1[5] = 0;
	return result;
}

//----- (00487D60) --------------------------------------------------------
int __cdecl sub_487D60(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 20) = 0;
	return result;
}

//----- (00487D70) --------------------------------------------------------
int __cdecl sub_487D70(_DWORD* a1, int a2, int a3, int a4) {
	int v4;              // esi
	int result;          // eax
	__int16 v6;          // ax
	unsigned __int16 v7; // ax
	unsigned __int8* v8; // eax
	unsigned __int16 v9; // di
	int v10;             // eax
	int v11;             // eax
	int v12;             // eax
	int v13;             // eax
	int v14;             // eax
	int v15;             // eax
	int v16;             // [esp-10h] [ebp-20h]
	int v17;             // [esp-10h] [ebp-20h]

	v4 = a1[8];
	switch (a2) {
	case 7:
		a1[9] |= 2u;
		sub_46B500((int)a1);
		return 1;
	case 8:
		v15 = a1[11];
		if (v15 & 0x100)
			nox_window_call_field_94(a1[13], 0x4000, (int)a1, 0);
		goto LABEL_41;
	case 17:
		v12 = a1[11];
		if (!(v12 & 0x100))
			goto LABEL_41;
		v16 = a1[13];
		a1[9] |= 2u;
		nox_window_call_field_94(v16, 16389, (int)a1, 0);
		sub_46B500((int)a1);
		result = 1;
		break;
	case 18:
		v13 = a1[11];
		if (v13 & 0x100) {
			v14 = a1[9];
			LOBYTE(v14) = v14 & 0xFD;
			v17 = a1[13];
			a1[9] = v14;
			nox_window_call_field_94(v17, 16390, (int)a1, 0);
			result = 1;
		} else {
		LABEL_41:
			result = 1;
		}
		break;
	case 21:
		switch (a3) {
		case 1:
		case 58:
		case 59:
		case 60:
		case 61:
		case 62:
		case 63:
		case 64:
		case 65:
		case 66:
		case 67:
		case 68:
		case 87:
		case 88:
		case 199:
		case 201:
		case 207:
		case 209:
			goto LABEL_42;
		case 14:
		case 211:
			if (a3 == 14)
				goto LABEL_13;
			if (dword_587000_26048 == 6)
				goto LABEL_19;
			if (dword_587000_26048 == 8)
				goto LABEL_17;
		LABEL_13:
			if (a4 != 2)
				goto LABEL_41;
			if (!*(_WORD*)(v4 + 1054)) {
				v6 = *(_WORD*)(v4 + 1052);
				if (!v6)
					goto LABEL_41;
				v7 = v6 - 1;
				*(_WORD*)(v4 + 1052) = v7;
				*(_WORD*)(v4 + 2 * v7) = 0;
				return 1;
			}
		LABEL_17:
			if (dword_587000_26048 != 6 && dword_587000_26048 != 8)
				goto LABEL_24;
		LABEL_19:
			if (!*(_DWORD*)(v4 + 1036) && !*(_DWORD*)(v4 + 1032) && !*(_DWORD*)(v4 + 1028)) {
				v8 = sub_57011C(*(_DWORD***)&dword_5d4594_1193348);
				nox_wcscpy((wchar_t*)(v4 + 512), (const wchar_t*)v8);
				*(_WORD*)(v4 + 1054) = nox_wcslen((const wchar_t*)(v4 + 512));
				if (!sub_5702B4(*(_DWORD***)&dword_5d4594_1193348))
					goto LABEL_41;
				sub_570392(*(_DWORD***)&dword_5d4594_1193348);
				nox_window_set_hidden(*(_DWORD*)(v4 + 1048), 1);
				return 1;
			}
		LABEL_24:
			v9 = sub_47F950(a3);
			if (!v9 || a4 != 2)
				goto LABEL_41;
			if (*(_DWORD*)(v4 + 1028)) {
				v10 = iswdigit(v9);
			} else {
				if (!*(_DWORD*)(v4 + 1032))
					goto LABEL_32;
				v10 = iswalnum(v9);
			}
			if (!v10)
				return 1;
		LABEL_32:
			v11 = *(unsigned __int16*)(v4 + 1052);
			if ((unsigned __int16)v11 >= *(__int16*)(v4 + 1040) - 1)
				goto LABEL_41;
			*(_WORD*)(v4 + 2 * v11) = v9;
			*(_WORD*)(v4 + 2 * (unsigned __int16)++*(_WORD*)(v4 + 1052)) = 0;
			result = 1;
			break;
		case 15:
		case 205:
		case 208:
			if (a4 != 2)
				goto LABEL_41;
			sub_46A8A0();
			return 1;
		case 28:
		case 156:
			if (a4 != 2 || *(_DWORD*)(v4 + 1044))
				goto LABEL_41;
			nox_window_call_field_94(a1[13], 16415, (int)a1, 0);
			return 1;
		case 200:
		case 203:
			if (a4 != 2)
				goto LABEL_41;
			sub_46A8B0();
			return 1;
		default:
			goto LABEL_17;
		}
		break;
	default:
	LABEL_42:
		result = 0;
		break;
	}
	return result;
}

//----- (00488160) --------------------------------------------------------
int __cdecl sub_488160(int a1, int a2) {
	int v2;            // edi
	int v3;            // edx
	int v4;            // ebx
	int v5;            // ecx
	int v6;            // kr04_4
	int v7;            // ebp
	wchar_t* v8;       // ecx
	signed __int16 v9; // ax
	size_t v10;        // edx
	size_t v11;        // eax
	__int16* v12;      // edi
	int i;             // ecx
	_DWORD* v14;       // eax
	int v15;           // eax
	int v16;           // ebx
	bool v17;          // zf
	int v19;           // [esp-28h] [ebp-260h]
	int v20;           // [esp-14h] [ebp-24Ch]
	int v21;           // [esp+10h] [ebp-228h]
	int v22;           // [esp+14h] [ebp-224h]
	wchar_t* v23;      // [esp+18h] [ebp-220h]
	int v24;           // [esp+1Ch] [ebp-21Ch]
	wchar_t* v25;      // [esp+20h] [ebp-218h]
	__int16* v26;      // [esp+24h] [ebp-214h]
	int yTop;          // [esp+28h] [ebp-210h]
	int xLeft;         // [esp+2Ch] [ebp-20Ch]
	int v29;           // [esp+30h] [ebp-208h]
	int v30;           // [esp+34h] [ebp-204h]
	__int16 v31[256];  // [esp+38h] [ebp-200h]

	v2 = a1;
	v3 = *(_DWORD*)(a2 + 20);
	v25 = *(wchar_t**)(a2 + 28);
	v23 = *(wchar_t**)(a1 + 32);
	v22 = 0;
	v24 = 0;
	*((_DWORD*)v23 + 261) = 0;
	v30 = v3;
	v26 = v31;
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	v4 = xLeft;
	v21 = *(_DWORD*)(a1 + 8);
	v5 = sub_43F320(*(_DWORD*)(a2 + 200));
	v6 = *(_DWORD*)(a1 + 12);
	v29 = v5;
	v7 = yTop + v6 / 2 - v5 / 2;
	if (((*(_DWORD*)(a1 + 4) >> 13) & 1) == 1)
		sub_43F670(1);
	if ((*(_DWORD*)(a1 + 4) >> 3) & 1) {
		if (*(_BYTE*)a2 & 2)
			v25 = *(wchar_t**)(a2 + 36);
	} else {
		v30 = *(_DWORD*)(a2 + 44);
	}
	if (*(_WORD*)(a2 + 72)) {
		sub_43F840(*(_DWORD*)(a2 + 200), (unsigned __int16*)(a2 + 72), &v22, 0, 0);
		sub_434390(*(_DWORD*)(a2 + 68));
		sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(a2 + 72), v4 + 2, v7, v21, 0);
		v4 += v22 + 6;
		v21 += -6 - v22;
	}
	v8 = v23;
	v9 = v23[521];
	if (v9 > 0 && v21 > v9) {
		v21 = v9;
		v4 = xLeft + *(_DWORD*)(a1 + 8) - v9;
	}
	if (v30 != 0x80000000) {
		nox_client_drawSetColor_434460(v30);
		nox_client_drawRectFilledOpaque_49CE30(v4 + 1, yTop + 1, v21 - 2, *(_DWORD*)(a1 + 12) - 2);
		v8 = v23;
	}
	if (v25 != (wchar_t*)0x80000000) {
		nox_client_drawSetColor_434460((int)v25);
		nox_client_drawBorderLines_49CC70(v4, yTop, v21, *(_DWORD*)(a1 + 12));
		v8 = v23;
	}
	if (*(_DWORD*)(a2 + 68) != 0x80000000) {
		if (*((_DWORD*)v8 + 256)) {
			v10 = nox_wcslen(v8);
			v11 = 0;
			if ((int)v10 > 0) {
				memset32(v31, 2752554, v10 >> 1);
				v12 = &v31[2 * (v10 >> 1)];
				for (i = v10 & 1; i; --i) {
					*v12 = 42;
					++v12;
				}
				v2 = a1;
				v11 = v10;
			}
			v31[v11] = 0;
		} else {
			nox_wcscpy((wchar_t*)v31, v8);
		}
		sub_43F840(*(_DWORD*)(a2 + 200), (unsigned __int16*)v31, &v22, 0, 0);
		v19 = *(_DWORD*)(a2 + 200);
		v25 = v23 + 256;
		sub_43F840(v19, v23 + 256, &v24, 0, 0);
		if (((*(_DWORD*)(v2 + 4) >> 14) & 1) == 1 && v24 + v22 > 0 && v21 >= 10 && v24 + v22 + 10 > v21) {
			do {
				v20 = *(_DWORD*)(a2 + 200);
				++v26;
				sub_43F840(v20, (unsigned __int16*)v26, &v22, 0, 0);
			} while (v24 + v22 + 10 > v21);
		}
		v14 = (_DWORD*)*((_DWORD*)v23 + 262);
		if (v14)
			nox_wnd_sub_46A9B0(v14, v4 + v22, v29 + v7);
		sub_434390(*(_DWORD*)(a2 + 68));
		sub_43FAF0(*(_DWORD*)(a2 + 200), v26, v4 + 5, v7, 0, 0);
		v15 = sub_4344A0(192, 0, 192);
		sub_434390(v15);
		sub_43FAF0(*(_DWORD*)(a2 + 200), v25, v4 + v22 + 5, v7, 0, 0);
		v16 = v4 + v22 + v24 + 5;
		if (v2 == sub_46B4F0()) {
			v17 = ((*getMemU8Ptr(0x5D4594, 1193344))++ & 8) == 0;
			if (!v17) {
				nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 68));
				nox_client_drawRectFilledOpaque_49CE30(v16, v7, 2, v29);
			}
		}
	}
	sub_43F670(0);
	return 1;
}
// 488160: using guessed type wchar_t var_200[256];

//----- (00488500) --------------------------------------------------------
_DWORD* __cdecl sub_488500(int a1, int a2, int a3, int a4, int a5, int a6, int a7, wchar_t* a8) {
	_DWORD* v8;     // esi
	bool v9;        // cc
	int* v10;       // ebx
	_DWORD* result; // eax
	_DWORD* v12;    // eax
	int v13;        // eax
	char v14[56];   // [esp+14h] [ebp-184h]
	char v15[332];  // [esp+4Ch] [ebp-14Ch]

	if (*(_BYTE*)(a7 + 8) & 0x80) {
		v8 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_488710);
		sub_488830((int)v8);
		if (!v8)
			return v8;
		if (!*(_DWORD*)(a7 + 16))
			*(_DWORD*)(a7 + 16) = v8;
		sub_46AF80_copy_window_part((int)v8, (const void*)a7);
		memset(a8, 0, 0x100u);
		memset(a8 + 256, 0, 0x100u);
		a8[526] = nox_wcslen(a8);
		v9 = (__int16)a8[520] < 256;
		a8[527] = 0;
		*((_DWORD*)a8 + 261) = 0;
		if (!v9)
			a8[520] = 256;
		v10 = (int*)malloc(0x420u);
		memcpy(v10, a8, 0x420u);
		v8[8] = v10;
		if (dword_587000_26048 != 8 && dword_587000_26048 != 6) {
			result = v8;
			v10[262] = 0;
			return result;
		}
		memset(v15, 0, sizeof(v15));
		*(_DWORD*)&v15[24] = 0;
		*(_DWORD*)&v15[28] = *(_DWORD*)(a7 + 68);
		*(_DWORD*)&v15[36] = 0x80000000;
		*(_DWORD*)&v15[52] = 0x80000000;
		*(_DWORD*)&v15[68] = *(_DWORD*)&v15[28];
		memset(v14, 0, sizeof(v14));
		*(_DWORD*)&v14[8] = 1;
		*(_DWORD*)&v14[12] = 1;
		*(_DWORD*)&v15[48] = 0;
		*(_WORD*)&v14[2] = 0x0a;
		*(_WORD*)&v14[0] = 0x80;
		*(_DWORD*)&v14[4] = 0;
		*(_DWORD*)&v14[16] = 0;
		*(_WORD*)&v15[72] = 0;
		*(_DWORD*)&v15[8] = 288;
		v12 = sub_4A4310(0, 17584, 0, a6, 110, 119, (int)v15, (__int16*)v14);
		v10[262] = (int)v12;
		if (v12) {
			sub_46AD80((int)v12, 128);
			sub_4A3C00(v10[262], *(_DWORD*)(v10[262] + 32));
			v13 = sub_4344A0(0, 0, 0);
			sub_46AFE0(v10[262], v13);
			return v8;
		}
	}
	return 0;
}

//----- (00488710) --------------------------------------------------------
int __cdecl sub_488710(int a1, unsigned int a2, wchar_t* a3, int a4) {
	int v3; // esi
	int v4; // eax
	int v6; // eax
	int v7; // eax

	v3 = *(_DWORD*)(a1 + 32);
	if (a2 > 0x401D) {
		if (a2 == 16414) {
			nox_wcsncpy((wchar_t*)v3, a3, 0xFFu);
			*(_WORD*)(v3 + 510) = 0;
			*(_WORD*)(v3 + 1052) = nox_wcslen((const wchar_t*)v3);
			*(_WORD*)(v3 + 512) = 0;
			*(_WORD*)(v3 + 1054) = 0;
		}
		return 0;
	}
	if (a2 == 16413)
		return *(_DWORD*)(a1 + 32);
	if (a2 == 2) {
		sub_46C4E0(*(_DWORD**)(v3 + 1048));
		free(*(LPVOID*)(a1 + 32));
		return 0;
	}
	if (a2 != 23)
		return 0;
	if (a3) {
		dword_5d4594_1193352 = a1;
		sub_5700CA(*(int***)&dword_5d4594_1193348, getWindowHandle_sub_401FD0());
		v6 = *(_DWORD*)(a1 + 36);
		LOBYTE(v6) = v6 | 6;
		*(_DWORD*)(a1 + 36) = v6;
	} else {
		sub_5700F6(*(int***)&dword_5d4594_1193348);
		dword_5d4594_1193352 = 0;
		v4 = *(_DWORD*)(a1 + 36);
		LOBYTE(v4) = v4 & 0xF9;
		*(_DWORD*)(a1 + 36) = v4;
		nox_window_set_hidden(*(_DWORD*)(v3 + 1048), 1);
		*(_WORD*)(v3 + 512) = 0;
		*(_WORD*)(v3 + 1054) = 0;
	}
	v7 = sub_46B0A0((int*)a1);
	nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v7);
	return 1;
}

//----- (00488830) --------------------------------------------------------
int __cdecl sub_488830(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_487D70, sub_488160, 0);
		else
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_487D70, sub_488870, 0);
	}
	return result;
}

//----- (00488870) --------------------------------------------------------
int __cdecl sub_488870(int a1, int a2) {
	int v2;           // edi
	int v3;           // ebp
	int v4;           // ecx
	int v5;           // kr04_4
	int v6;           // ebx
	int v7;           // eax
	size_t v8;        // edx
	size_t v9;        // eax
	__int16* v10;     // edi
	int i;            // ecx
	int v12;          // eax
	bool v13;         // zf
	int v15;          // [esp-14h] [ebp-244h]
	int xLeft;        // [esp+10h] [ebp-220h]
	int v17;          // [esp+14h] [ebp-21Ch]
	__int16* v18;     // [esp+18h] [ebp-218h]
	int v19;          // [esp+1Ch] [ebp-214h]
	wchar_t* v20;     // [esp+20h] [ebp-210h]
	int v21;          // [esp+24h] [ebp-20Ch]
	wchar_t* v22;     // [esp+28h] [ebp-208h]
	int v23;          // [esp+2Ch] [ebp-204h]
	__int16 v24[256]; // [esp+30h] [ebp-200h]

	v2 = a1;
	v20 = *(wchar_t**)(a2 + 24);
	v22 = *(wchar_t**)(a1 + 32);
	*((_DWORD*)v22 + 261) = 0;
	v18 = v24;
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &v21);
	v3 = *(_DWORD*)(a1 + 8);
	v4 = sub_43F320(*(_DWORD*)(a2 + 200));
	v5 = *(_DWORD*)(a1 + 12);
	v23 = v4;
	v6 = v21 + v5 / 2 - v4 / 2;
	if (((*(_DWORD*)(a1 + 4) >> 13) & 1) == 1)
		sub_43F670(1);
	if ((*(_DWORD*)(a1 + 4) >> 3) & 1)
		v7 = (int)v20;
	else
		v7 = *(_DWORD*)(a2 + 48);
	if (v7)
		nox_client_drawImageAt_47D2C0(v7, xLeft, v21);
	sub_434390(*(_DWORD*)(a2 + 68));
	if (*(_WORD*)(a2 + 72)) {
		sub_43F840(*(_DWORD*)(a2 + 200), (unsigned __int16*)(a2 + 72), &v17, 0, 0);
		sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(a2 + 72), xLeft + 2, v6, v3, 0);
		v3 += -6 - v17;
		xLeft += v17 + 6;
	}
	if (*(_DWORD*)(a2 + 68) != 0x80000000) {
		if (*((_DWORD*)v22 + 256)) {
			v8 = nox_wcslen(v22);
			v9 = 0;
			if ((int)v8 > 0) {
				memset32(v24, 2752554, v8 >> 1);
				v10 = &v24[2 * (v8 >> 1)];
				for (i = v8 & 1; i; --i) {
					*v10 = 42;
					++v10;
				}
				v2 = a1;
				v9 = v8;
			}
			v24[v9] = 0;
		} else {
			nox_wcscpy((wchar_t*)v24, v22);
		}
		sub_43F840(*(_DWORD*)(a2 + 200), (unsigned __int16*)v24, &v17, 0, 0);
		v20 = v22 + 256;
		sub_43F840(*(_DWORD*)(a2 + 200), v22 + 256, &v19, 0, 0);
		if (((*(_DWORD*)(v2 + 4) >> 14) & 1) == 1 && v17 + v19 > 0 && v17 + v19 + 10 > v3) {
			do {
				v15 = *(_DWORD*)(a2 + 200);
				++v18;
				sub_43F840(v15, (unsigned __int16*)v18, &v17, 0, 0);
			} while (v19 + v17 + 10 > v3);
		}
		sub_434390(*(_DWORD*)(a2 + 68));
		sub_43FAF0(*(_DWORD*)(a2 + 200), v18, xLeft + 5, v6, v3, 0);
		v12 = sub_4344A0(192, 0, 192);
		sub_434390(v12);
		sub_43FAF0(*(_DWORD*)(a2 + 200), v20, v17 + xLeft + 5, v6, v3, 0);
		xLeft += v17 + v19 + 5;
		if (v2 == sub_46B4F0()) {
			v13 = ((*getMemU8Ptr(0x5D4594, 1193344))++ & 8) == 0;
			if (!v13) {
				nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 68));
				nox_client_drawRectFilledOpaque_49CE30(xLeft, v6, 2, v23);
			}
		}
	}
	sub_43F670(0);
	return 1;
}
// 488870: using guessed type wchar_t var_200[256];

//----- (00488B60) --------------------------------------------------------
int sub_488B60() {
	int** v0; // eax

	v0 = (int**)operator_new(4u);
	if (v0) {
		dword_5d4594_1193348 = sub_56FFE0(v0);
		sub_570142(*(_DWORD***)&dword_5d4594_1193348, 11);
	} else {
		dword_5d4594_1193348 = 0;
		sub_570142(0, 11);
	}
	return 1;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00488BA0) --------------------------------------------------------
int sub_488BA0() {
	void* v0; // esi

	v0 = *(void**)&dword_5d4594_1193348;
	if (dword_5d4594_1193348) {
		sub_570070(*(int****)&dword_5d4594_1193348);
		operator_delete(v0);
	}
	dword_5d4594_1193348 = 0;
	return 1;
}

//----- (00488BD0) --------------------------------------------------------
void __cdecl sub_488BD0(unsigned __int16 a1) {
	int v2;              // esi
	int v3;              // eax
	unsigned __int8* v4; // eax

	if (dword_5d4594_1193348) {
		if (dword_5d4594_1193352) {
			v2 = *(_DWORD*)(dword_5d4594_1193352 + 32);
			if (dword_587000_26048 == 6 || dword_587000_26048 == 8) {
				if (!*(DWORD*)(v2 + 1036)) {
					if (!*(DWORD*)(v2 + 1032)) {
						if (!*(DWORD*)(v2 + 1028)) {
							*(_DWORD*)(v2 + 1044) = 1;
							switch (a1) {
							case 7u:
							case 8u:
							case 9u:
							case 0xBu:
							case 0xCu:
								break;
							case 0xAu:
							case 0xDu:
								*(_DWORD*)(v2 + 1044) = 0;
								break;
							default:
								v3 = *(unsigned __int16*)(v2 + 1052);
								if ((unsigned __int16)v3 < *(__int16*)(v2 + 1040) - 1) {
									*(_WORD*)(v2 + 2 * v3) = a1;
									*(_WORD*)(v2 + 2 * (unsigned __int16)++*(_WORD*)(v2 + 1052)) = 0;
								}
								v4 = sub_57011C(*(_DWORD***)&dword_5d4594_1193348);
								nox_wcscpy((wchar_t*)(v2 + 512), (const wchar_t*)v4);
								*(_WORD*)(v2 + 1054) = nox_wcslen((const wchar_t*)(v2 + 512));
								sub_570392(*(_DWORD***)&dword_5d4594_1193348);
								nox_window_set_hidden(*(_DWORD*)(v2 + 1048), 1);
								break;
							}
						}
					}
				}
			}
		}
	}
}

//----- (00488D00) --------------------------------------------------------
int __cdecl sub_488D00(int a1, int xLeft) {
	int v2;                 // esi
	unsigned __int16** v3;  // ebx
	int v4;                 // ecx
	int v5;                 // edi
	int v6;                 // ebp
	int v7;                 // eax
	int v8;                 // ebp
	unsigned __int16* v9;   // eax
	int v10;                // ecx
	size_t v11;             // eax
	const wchar_t* v12;     // ebp
	const wchar_t* v13;     // ebx
	wchar_t* v14;           // ebx
	wchar_t* v15;           // eax
	int v16;                // ebp
	wchar_t* v17;           // eax
	int v18;                // ebx
	int v19;                // ebp
	int v20;                // ebx
	const wchar_t* v22;     // [esp-4h] [ebp-40h]
	int v23;                // [esp+10h] [ebp-2Ch]
	wchar_t* v24;           // [esp+14h] [ebp-28h]
	int v25;                // [esp+18h] [ebp-24h]
	int v26;                // [esp+1Ch] [ebp-20h]
	int v27;                // [esp+20h] [ebp-1Ch]
	int yTop;               // [esp+24h] [ebp-18h]
	int v29;                // [esp+28h] [ebp-14h]
	size_t v30;             // [esp+2Ch] [ebp-10h]
	int v31;                // [esp+30h] [ebp-Ch]
	int v32;                // [esp+34h] [ebp-8h]
	unsigned __int16** v33; // [esp+38h] [ebp-4h]
	wchar_t* v34;           // [esp+40h] [ebp+4h]

	v2 = xLeft;
	v3 = *(unsigned __int16***)(a1 + 32);
	v4 = *(_DWORD*)(xLeft + 20);
	v25 = *(_DWORD*)(xLeft + 28);
	v27 = v25;
	v33 = v3;
	v26 = v4;
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	v5 = *(_DWORD*)(a1 + 8);
	v6 = yTop + *(int*)(a1 + 12) / 2;
	if ((*(_DWORD*)(a1 + 4) & 0x2000) == 0x2000)
		sub_43F670(1);
	if (*(_BYTE*)(a1 + 4) & 8) {
		if (*(_BYTE*)v2 & 2)
			v25 = *(_DWORD*)(v2 + 36);
		v7 = v26;
	} else {
		v7 = *(_DWORD*)(v2 + 44);
	}
	if (*(_BYTE*)v2 & 4)
		v27 = *(_DWORD*)(v2 + 52);
	if (v7 != 0x80000000) {
		nox_client_drawSetColor_434460(v7);
		nox_client_drawRectFilledOpaque_49CE30(xLeft + 1, yTop + 1, v5 - 2, *(_DWORD*)(a1 + 12) - 2);
	}
	if (v25 != 0x80000000) {
		nox_client_drawSetColor_434460(v25);
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v5, *(_DWORD*)(a1 + 12));
	}
	if (*v3 && *(_DWORD*)(v2 + 68) != 0x80000000) {
		sub_434390(*(_DWORD*)(v2 + 68));
		sub_43F840(*(_DWORD*)(v2 + 200), *v3, &v29, &v23, v5);
		v8 = v23 / -2 + v6;
		v9 = v3[1];
		v26 = v8;
		if (v9) {
			v10 = *(_DWORD*)(v2 + 200);
			if (v23 > *(int*)(v10 + 28)) {
				v22 = *v3;
				v32 = xLeft;
				v11 = nox_wcslen(v22);
				sub_4892D0(2 * v11 + 2);
				if (dword_5d4594_1193360) {
					v12 = *v3;
					v24 = *v3;
					while (1) {
						v25 = 0;
						v31 = 0;
						v13 = v12;
						v34 = (wchar_t*)v12;
						v30 = nox_wcslen(v12);
						while (1) {
							v14 = nox_wcschr(v13, 0x20u);
							if (!v14) {
								v25 = 1;
								v14 = (wchar_t*)&v12[v30];
							}
							v15 = v34;
							if (v34 <= v14) {
								while (*v15 != 10) {
									++v15;
									if (v15 > v14)
										goto LABEL_32;
								}
								v31 = 1;
								v14 = v15;
								if (v15 < &v12[v30])
									v25 = 0;
							}
						LABEL_32:
							v16 = v14 - v24;
							nox_wcsncpy(*(wchar_t**)&dword_5d4594_1193360, v24, v16);
							*(_WORD*)(dword_5d4594_1193360 + 2 * v16) = 0;
							sub_43F840(*(_DWORD*)(v2 + 200), *(unsigned __int16**)&dword_5d4594_1193360, 0, &v23, v5);
							if (v23 > *(int*)(*(_DWORD*)(v2 + 200) + 28))
								break;
							v34 = v14;
							v13 = v14 + 1;
							if (v25 || v31) {
								v17 = v24;
								goto LABEL_40;
							}
							v12 = v24;
						}
						v17 = v24;
						if (v34 == v24)
							v34 = v14;
						v25 = 0;
					LABEL_40:
						v18 = v34 - v17;
						nox_wcsncpy(*(wchar_t**)&dword_5d4594_1193360, v17, v18);
						*(_WORD*)(dword_5d4594_1193360 + 2 * v18) = 0;
						sub_43F840(*(_DWORD*)(v2 + 200), *(unsigned __int16**)&dword_5d4594_1193360, &v29, &v23, v5);
						xLeft = v32 + (v5 - v29) / 2;
						if (v33[2]) {
							sub_434390(v27);
							v19 = v26;
							v20 = v26 - 1;
							sub_43FAF0(*(_DWORD*)(v2 + 200), *(_WORD**)&dword_5d4594_1193360, xLeft - 1, v26 - 1, v5,
									   0);
							sub_43FAF0(*(_DWORD*)(v2 + 200), *(_WORD**)&dword_5d4594_1193360, xLeft + 1, v20, v5, 0);
							sub_43FAF0(*(_DWORD*)(v2 + 200), *(_WORD**)&dword_5d4594_1193360, xLeft - 1, v19 + 1, v5,
									   0);
							sub_43FAF0(*(_DWORD*)(v2 + 200), *(_WORD**)&dword_5d4594_1193360, xLeft + 1, v19 + 1, v5,
									   0);
							sub_434390(*(_DWORD*)(v2 + 68));
							sub_43FAF0(*(_DWORD*)(v2 + 200), *(_WORD**)&dword_5d4594_1193360, xLeft, v19, v5, 0);
						} else {
							sub_43FAF0(*(_DWORD*)(v2 + 200), *(_WORD**)&dword_5d4594_1193360, v32 + (v5 - v29) / 2, v26,
									   v5, 0);
							v19 = v26;
						}
						v26 = v23 + v19 + 1;
						if (v25)
							break;
						v24 = v34 + 1;
						v12 = v34 + 1;
					}
				}
			} else {
				xLeft += (v5 - v29) / 2;
				if (v3[2]) {
					sub_434390(v27);
					sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft - 1, v8 - 1, v5, 0);
					sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 1, v8 - 1, v5, 0);
					sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft - 1, v8 + 1, v5, 0);
					sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 1, v8 + 1, v5, 0);
					sub_434390(*(_DWORD*)(v2 + 68));
					sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft, v8, v5, 0);
				} else {
					sub_43FAF0(v10, *v3, xLeft, v8, v5, 0);
				}
			}
		} else if (v3[2]) {
			sub_434390(v27);
			sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 1, v8 - 1, v5, 0);
			sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 3, v8 - 1, v5, 0);
			sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 1, v8 + 1, v5, 0);
			sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 3, v8 + 1, v5, 0);
			sub_434390(*(_DWORD*)(v2 + 68));
			sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 2, v8, v5, 0);
		} else {
			sub_43FAF0(*(_DWORD*)(v2 + 200), *v3, xLeft + 2, v8, v5, 0);
		}
	}
	sub_43F670(0);
	return 1;
}

//----- (004892D0) --------------------------------------------------------
wchar_t* __cdecl sub_4892D0(int a1) {
	wchar_t* result; // eax

	result = (wchar_t*)a1;
	if (a1 > *(int*)getMemAt(0x5D4594, 1193364)) {
		*getMemU32Ptr(0x5D4594, 1193364) = a1;
		result = (wchar_t*)realloc(*(LPVOID*)&dword_5d4594_1193360, a1);
		dword_5d4594_1193360 = result;
	}
	return result;
}

//----- (00489300) --------------------------------------------------------
_DWORD* __cdecl sub_489300(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD* a7, _DWORD* a8) {
	int v8;      // ecx
	_DWORD* v9;  // esi
	_DWORD* v10; // edx

	v8 = a7[2];
	BYTE1(v8) &= 0xFBu;
	a7[2] = v8;
	if (!(v8 & 0x800))
		return 0;
	v9 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_489390);
	sub_4893E0((int)v9);
	if (v9) {
		if (!a7[4])
			a7[4] = v9;
		sub_46AF80_copy_window_part((int)v9, a7);
		v10 = malloc(0xCu);
		*v10 = *a8;
		v10[1] = a8[1];
		v10[2] = a8[2];
		v9[8] = v10;
	}
	return v9;
}

//----- (00489390) --------------------------------------------------------
int __cdecl sub_489390(int a1, int a2, int a3, int a4) {
	switch (a2) {
	case 2:
		free(*(LPVOID*)(a1 + 32));
		break;
	case 16385:
		if (a3) {
			**(_DWORD**)(a1 + 32) = a3;
			return 0;
		}
		break;
	case 16386:
		return **(_DWORD**)(a1 + 32);
	}
	return 0;
}

//----- (004893E0) --------------------------------------------------------
int __cdecl sub_4893E0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_489420, sub_488D00, 0);
		else
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_489420, sub_489550, 0);
	}
	return result;
}

//----- (00489420) --------------------------------------------------------
int __cdecl sub_489420(int a1, int a2, int a3, int a4) {
	int result; // eax

	if (a2 != 21)
		return 0;
	switch (a3) {
	case 15:
	case 205:
	case 208:
		if (a4 != 2)
			goto LABEL_7;
		sub_46A8A0();
		result = 1;
		break;
	case 200:
	case 203:
		if (a4 == 2)
			sub_46A8B0();
	LABEL_7:
		result = 1;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (00489550) --------------------------------------------------------
int __cdecl sub_489550(_DWORD* a1, _DWORD* a2) {
	_DWORD* v2;            // esi
	unsigned __int16** v3; // ebp
	_DWORD* v4;            // ebx
	int v5;                // eax
	int v6;                // edi
	int v7;                // eax
	int v8;                // eax
	int v9;                // ecx
	int v11;               // [esp+10h] [ebp-Ch]
	int v12;               // [esp+14h] [ebp-8h]
	int v13;               // [esp+18h] [ebp-4h]

	v2 = a1;
	v3 = (unsigned __int16**)a1[8];
	nox_client_wndGetPosition_46AA60(a1, &a1, &v11);
	v4 = a2;
	v12 = v2[2];
	v5 = sub_43F320(a2[50]);
	v6 = v11 + v2[3] / 2 - v5 / 2;
	if ((v2[1] & 0x2000) == 0x2000)
		sub_43F670(1);
	v7 = v4[6];
	if (v7)
		nox_client_drawImageAt_47D2C0(v7, (int)a1 + v2[24], v11 + v2[25]);
	if (v2[1] & 8)
		v8 = v4[8];
	else
		v8 = v4[12];
	if (v8)
		nox_client_drawImageAt_47D2C0(v8, (int)a1 + v2[24], v11 + v2[25]);
	if (*v3) {
		sub_434390(v4[17]);
		if (v3[1]) {
			sub_43F840(v4[50], *v3, &v13, 0, 0);
			v9 = v4[50];
			a1 = (_DWORD*)((char*)a1 + (v12 - v13) / 2);
			sub_43FAF0(v9, *v3, (int)a1, v6, v12, 0);
		} else {
			sub_43FAF0(v4[50], *v3, (int)a1 + 2, v6, v12, 0);
		}
	}
	sub_43F670(0);
	return 1;
}

//----- (004896C0) --------------------------------------------------------
int sub_4896C0() { return *getMemU32Ptr(0x5D4594, 1193356); }

//----- (004896D0) --------------------------------------------------------
int __cdecl sub_4896D0(int a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1193356);
	*getMemU32Ptr(0x5D4594, 1193356) = a1;
	return result;
}

//----- (004896E0) --------------------------------------------------------
int sub_4896E0() {
	if (dword_5d4594_1193360)
		free(*(LPVOID*)&dword_5d4594_1193360);
	return 1;
}

//----- (00489870) --------------------------------------------------------
int sub_489870() {
	int v0;              // eax
	unsigned __int8* v1; // esi
	_DWORD* v2;          // eax
	const wchar_t* v3;   // eax
	unsigned int v4;     // eax
	int v5;              // edx
	char v6;             // cl
	int v7;              // eax

	v0 = sub_43AF70();
	v1 = getMemAt(0x5D4594, 44 * v0 + 1193388);
	if (*getMemU32Ptr(0x5D4594, 4 * v0 + 1193372) == 2) {
		*(_DWORD*)v1 = (sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10028)[9] >> 2) & 1;
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10031);
		v3 = (const wchar_t*)nox_window_call_field_94((int)v2, 16413, 0, 0);
		*((_DWORD*)v1 + 4) = nox_wcstol(v3, 0, 10);
		*((_DWORD*)v1 + 1) = (sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10029)[9] >> 2) & 1;
		v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10030)[9];
		*((_DWORD*)v1 + 3) = 0;
		*((_DWORD*)v1 + 2) = (v4 >> 2) & 1;
		if (sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10015)[9] & 4) {
			v5 = *((_DWORD*)v1 + 3);
			LOBYTE(v5) = v5 | 0x80;
			*((_DWORD*)v1 + 3) = v5;
			v6 = *((_BYTE*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10016) + 36);
			v7 = *((_DWORD*)v1 + 3);
			if (v6 & 4)
				LOBYTE(v7) = v7 | 1;
			else
				LOBYTE(v7) = v7 | 2;
			*((_DWORD*)v1 + 3) = v7;
		}
		*((_DWORD*)v1 + 5) = (sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10014)[9] >> 2) & 1;
		*((_DWORD*)v1 + 10) = (sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10018)[9] >> 2) & 1;
	}
	return nox_window_set_hidden(*(int*)&dword_5d4594_1193380, 1);
}

//----- (004899C0) --------------------------------------------------------
BOOL __cdecl sub_4899C0(int a1) {
	int v1;              // eax
	int v2;              // edx
	int v3;              // eax
	unsigned __int8* v4; // ebp
	int v5;              // eax
	int v6;              // ebx
	unsigned int v7;     // eax
	char v9;             // al
	unsigned __int8 v10; // cl
	unsigned __int8 v11; // cl
	char v12;            // al
	int v13[15];         // [esp+Ch] [ebp-3Ch]
	unsigned __int8 v14; // [esp+4Ch] [ebp+4h]
	unsigned __int8 v15; // [esp+4Ch] [ebp+4h]

	v1 = sub_43AF70();
	v2 = 11 * v1;
	v3 = *getMemU32Ptr(0x5D4594, 4 * v1 + 1193372);
	v4 = getMemAt(0x5D4594, 4 * v2 + 1193388);
	if (!v3)
		return 1;
	v5 = v3 - 1;
	if (v5) {
		if (v5 == 1) {
			v6 = a1;
			if (*(_DWORD*)v4) {
				v7 = *(_DWORD*)(a1 + 96);
				if (v7 > *((_DWORD*)v4 + 4) && v7 != 9999)
					return 0;
			}
			if (*((_DWORD*)v4 + 1) && *(_BYTE*)(a1 + 100) & 0x10)
				return 0;
			if (*((_DWORD*)v4 + 2) && *(_BYTE*)(a1 + 100) & 0x20)
				return 0;
			v9 = *(_BYTE*)(a1 + 102);
			if (v9 < 0 && *((_DWORD*)v4 + 3) > (v9 & 0x7F))
				return 0;
			if (*((_DWORD*)v4 + 5)) {
				strcpy((char*)v13, (const char*)(a1 + 111));
				sub_57A1E0(v13, 0, 0, 5, *(_WORD*)(a1 + 163));
				v10 = 0;
				v14 = 0;
				while (v13[v14 + 6] == *(_DWORD*)(4 * v14 + v6 + 135)) {
					v14 = ++v10;
					if (v10 >= 5u) {
						v11 = 0;
						v15 = 0;
						while (*((_BYTE*)&v13[11] + v15) == *(_BYTE*)(v15 + v6 + 155)) {
							v15 = ++v11;
							if (v11 >= 4u) {
								if (v13[12] == *(_DWORD*)(v6 + 159))
									goto LABEL_26;
								return 0;
							}
						}
						return 0;
					}
				}
				return 0;
			}
		LABEL_26:
			if (*((_DWORD*)v4 + 10) && *(_DWORD*)(v6 + 48) != 66458)
				return 0;
		}
		return 1;
	}
	v12 = *(_BYTE*)(a1 + 100);
	if (v12 & 0x10)
		return 0;
	if (v12 & 0x20)
		return 0;
	return *(_DWORD*)(a1 + 48) == 66458;
}

//----- (00489B80) --------------------------------------------------------
_DWORD* __cdecl sub_489B80(int a1) {
	_DWORD* result;      // eax
	int v2;              // ebx
	unsigned __int8* v3; // edi
	_DWORD* v4;          // eax
	_DWORD* v5;          // eax
	_DWORD* v6;          // eax
	_DWORD* v7;          // eax
	_DWORD* v8;          // eax
	_DWORD* v9;          // eax
	_DWORD* v10;         // esi
	int v11;             // ebx
	int v12;             // ebx
	wchar_t v13[16];     // [esp+0h] [ebp-20h]

	result = nox_new_window_from_file("filter.wnd", sub_489E70);
	dword_5d4594_1193380 = result;
	if (result) {
		dword_5d4594_1193384 = sub_46B0C0(result, 10012);
		v2 = sub_43AF70();
		v3 = getMemAt(0x5D4594, 44 * v2 + 1193388);
		sub_46B120(*(_DWORD**)&dword_5d4594_1193380, a1);
		sub_46B120(*(_DWORD**)&dword_5d4594_1193384, *(int*)&dword_5d4594_1193380);
		sub_46B2C0(*(int*)&dword_5d4594_1193384, sub_489E70);
		if (*(_DWORD*)v3) {
			v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10028);
			v4[9] |= 4u;
		}
		nox_swprintf(v13, L"%d", *((_DWORD*)v3 + 4));
		v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10031);
		nox_window_call_field_94((int)v5, 16414, (int)v13, -1);
		if (*((_DWORD*)v3 + 1)) {
			v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10029);
			v6[9] |= 4u;
		}
		if (*((_DWORD*)v3 + 2)) {
			v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10030);
			v7[9] |= 4u;
		}
		if (*((_DWORD*)v3 + 3)) {
			v8 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10015);
			v8[9] |= 4u;
		}
		if (v3[12] & 2)
			v9 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10017);
		else
			v9 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10016);
		v10 = v9;
		v9[9] |= 4u;
		if (*((_DWORD*)v3 + 5)) {
			v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10014);
			v10[9] |= 4u;
		}
		if (*((_DWORD*)v3 + 10)) {
			v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10018);
			v10[9] |= 4u;
		}
		v11 = *getMemU32Ptr(0x5D4594, 4 * v2 + 1193372);
		if (v11) {
			v12 = v11 - 1;
			if (v12) {
				if (v12 == 1) {
					v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10026);
					sub_489DC0();
				}
			} else {
				v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10025);
				nox_window_set_hidden(*(int*)&dword_5d4594_1193384, 1);
			}
		} else {
			v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10024);
			nox_window_set_hidden(*(int*)&dword_5d4594_1193384, 1);
		}
		v10[9] |= 4u;
		result = *(_DWORD**)&dword_5d4594_1193380;
	}
	return result;
}

//----- (00489DC0) --------------------------------------------------------
void sub_489DC0() {
	_DWORD* v0; // eax
	_DWORD* v1; // eax

	nox_window_set_hidden(*(int*)&dword_5d4594_1193384, 0);
	if (sub_46B0C0(*(_DWORD**)&dword_5d4594_1193384, 10028)[9] & 4) {
		v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193384, 10031);
		sub_46ABB0((int)v0, 1);
	} else {
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193384, 10031);
		sub_46ABB0((int)v1, 0);
	}
	if (sub_46B0C0(*(_DWORD**)&dword_5d4594_1193384, 10015)[9] & 4)
		sub_46AD20(*(_DWORD**)&dword_5d4594_1193384, 10016, 10017, 1);
	else
		sub_46AD20(*(_DWORD**)&dword_5d4594_1193384, 10016, 10017, 0);
}

//----- (00489E70) --------------------------------------------------------
int __cdecl sub_489E70(int a1, int a2, int* a3, int a4) {
	int v3;     // ebx
	int v4;     // esi
	int result; // eax
	_DWORD* v6; // eax
	int v7;     // [esp-Ch] [ebp-10h]
	int v8;     // [esp-Ch] [ebp-10h]

	v3 = sub_43AF70();
	if (a2 == 23)
		return 1;
	if (a2 != 16391)
		return 0;
	v4 = sub_46B0A0(a3);
	sub_452D80(766, 100);
	switch (v4) {
	case 10015:
		sub_46AD20(*(_DWORD**)&dword_5d4594_1193380, 10016, 10017, ((unsigned int)~a3[9] >> 2) & 1);
		return 0;
	case 10024:
		v7 = dword_5d4594_1193384;
		*getMemU32Ptr(0x5D4594, 4 * v3 + 1193372) = 0;
		nox_window_set_hidden(v7, 1);
		result = 0;
		break;
	case 10025:
		v8 = dword_5d4594_1193384;
		*getMemU32Ptr(0x5D4594, 4 * v3 + 1193372) = 1;
		nox_window_set_hidden(v8, 1);
		result = 0;
		break;
	case 10026:
		*getMemU32Ptr(0x5D4594, 4 * v3 + 1193372) = 2;
		sub_489DC0();
		result = 0;
		break;
	case 10028:
		v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1193380, 10031);
		sub_46ABB0((int)v6, ((unsigned int)~a3[9] >> 2) & 1);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (00489FB0) --------------------------------------------------------
int sub_489FB0() {
	int result; // eax

	result = dword_5d4594_1193380;
	if (dword_5d4594_1193380) {
		sub_489870();
		sub_46ADE0(*(int*)&dword_5d4594_1193380);
		result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1193380);
		dword_5d4594_1193380 = 0;
	}
	return result;
}

//----- (00489FF0) --------------------------------------------------------
int __cdecl sub_489FF0(int a1, int a2, const void* a3) {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 4 * a1 + 1193372) = a2;
	result = 11 * a1;
	memcpy(getMemAt(0x5D4594, 44 * a1 + 1193388), a3, 0x2Cu);
	return result;
}

//----- (0048A020) --------------------------------------------------------
int __cdecl sub_48A020(int a1, _DWORD* a2) {
	*a2 = getMemAt(0x5D4594, 44 * a1 + 1193388);
	return *getMemU32Ptr(0x5D4594, 4 * a1 + 1193372);
}

//----- (0048A1D0) --------------------------------------------------------
int __cdecl nox_video_checkIsWinNT_48A1D0(int a1) {
	int v1; // eax

	if (nox_video_windowsPlatformVersion != 5) // Non-NT
	{
		v1 = *(_DWORD*)&nox_video_renderTargetFlags;
		if (a1)
			LOBYTE(v1) = nox_video_renderTargetFlags | 0x20;
		else
			LOBYTE(v1) = nox_video_renderTargetFlags & 0xDF;
		*(_DWORD*)&nox_video_renderTargetFlags = v1;
		sub_444D00();
	}
	return (*(_DWORD*)&nox_video_renderTargetFlags >> 5) & 1;
}

//----- (0048A210) --------------------------------------------------------
int __cdecl sub_48A210(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1193504) = a1;
	return result;
}

//----- (0048A5D0) --------------------------------------------------------
int sub_48A5D0() { return 0; }

//----- (0048B3E0) --------------------------------------------------------
int __cdecl sub_48B3E0(int a1) {
	int result; // eax

	result = dword_5d4594_1193672;
	dword_5d4594_1193672 = a1;
	return result;
}

//----- (0048B590) --------------------------------------------------------
void __cdecl sub_48B590(_DWORD* a1, _DWORD* a2, _DWORD* a3) {
	if (a1)
		*a1 = dword_5d4594_1193624;
	if (a2)
		*a2 = dword_5d4594_1193648;
	if (a3)
		*a3 = dword_5d4594_1193524;
}

//----- (0048B680) --------------------------------------------------------
void __cdecl sub_48B680(int a1) {
	if (a1 != ptr_5D4594_3799572->data[15]) {
		if (nox_video_cursorDrawIsThreaded)
			ptr_5D4594_3799572->data[15] = a1;
		else
			ptr_5D4594_3799572->data[14] = a1;
		sub_48BD90(1);
	}
}

//----- (0048B6B0) --------------------------------------------------------
int __cdecl sub_48B6B0(int a1, int a2, int a3) {
	int result;          // eax
	__int64 v4;          // rax
	unsigned __int64 v5; // rax
	unsigned __int64 v6; // rax

	if (!nox_video_cursorDrawIsThreaded)
		return sub_433CD0(a1, a2, a3);
	result = (unsigned __int8)a1;
	ptr_5D4594_3799572->data[34] = (unsigned __int8)a1;
	ptr_5D4594_3799572->data[35] = (unsigned __int8)a2;
	ptr_5D4594_3799572->data[36] = (unsigned __int8)a3;
	if (dword_5d4594_3801804) {
		v4 = (unsigned __int8)a1 | ((unsigned __int8)a1 << 16);
		HIDWORD(v4) = 0;
		v4 <<= 16;
		LODWORD(v4) = (unsigned __int8)a1 | (unsigned int)v4;
		v4 <<= 16;
		ptr_5D4594_3799572->data[28] = (unsigned __int8)a1 | (unsigned int)v4;
		ptr_5D4594_3799572->data[29] = HIDWORD(v4);
		v5 = ((unsigned __int8)a2 | (((unsigned __int8)a2 | ((unsigned __int64)(unsigned __int8)a2 << 16)) << 16))
			 << 16;
		ptr_5D4594_3799572->data[30] = (unsigned __int8)a2 | (unsigned int)v5;
		ptr_5D4594_3799572->data[31] = HIDWORD(v5);
		v6 = ((unsigned __int8)a3 | (((unsigned __int8)a3 | ((unsigned __int64)(unsigned __int8)a3 << 16)) << 16))
			 << 16;
		ptr_5D4594_3799572->data[32] = (unsigned __int8)a3 | (unsigned int)v6;
		result = ptr_5D4594_3799572;
		ptr_5D4594_3799572->data[33] = HIDWORD(v6);
	}
	return result;
}

//----- (0048B800) --------------------------------------------------------
int __cdecl sub_48B800(int a1) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	sub_434480(a1, (int)&v3, (int)&v2, (int)&a1);
	return sub_48B6B0(v3, v2, a1);
}

//----- (0048BD90) --------------------------------------------------------
void __cdecl sub_48BD90(int a1) {
	EnterCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
	if (!a1)
		SetRect((LPRECT)getMemAt(0x5D4594, 1193532), 0, 0, 0, 0);
	dword_5d4594_1193664 = 1;
	dword_5d4594_1193668 = 1;
	dword_5d4594_1193624 = 0;
	LeaveCriticalSection((LPCRITICAL_SECTION)getMemAt(0x5D4594, 3799596));
}

//----- (0048BE50) --------------------------------------------------------
int __cdecl sub_48BE50(int a1) {
	int result; // eax

	result = nox_video_drawCursorThreadOk;
	if (nox_video_drawCursorThreadOk) {
		result = nox_video_cursorDrawIsThreaded;
		if (nox_video_cursorDrawIsThreaded) {
			result = a1;
			nox_video_pauseThreadedDrawCursor = a1;
		}
	}
	return result;
}

//----- (0048BE70) --------------------------------------------------------
int nox_video_createCursorDrawThread_48BE70() {
	nox_video_allowCursorDrawThread = 1;
	nox_video_cursorDrawThreadHandle = _beginthread(nox_video_cursorThreadWorker_48BEB0, 0, 0);
	if (nox_video_cursorDrawThreadHandle != -1)
		return 1;
	nox_video_cursorDrawThreadHandle = 0;
	return 0;
}

//----- (0048BEB0) --------------------------------------------------------
int nox_video_cursorThreadWorker_48BEB0() {
	int result; // eax
	int2* v1;   // esi
	int v2;     // [esp-14h] [ebp-14h]
	int v3;     // [esp-10h] [ebp-10h]
	int v4;     // [esp-Ch] [ebp-Ch]

	while (nox_video_allowCursorDrawThread) {
		nox_sleep(33);
		if (!nox_video_pauseThreadedDrawCursor && nox_video_drawCursorThreadOk && dword_5d4594_823776 &&
			dword_5d4594_1193672 && *getMemU32Ptr(0x5D4594, 1193108) && dword_5d4594_787144 && !sub_430890()) {
			nox_client_readMouseBuffer_4306A0(0);
			v1 = nox_client_getMousePos_4309F0();
			if (nox_client_getCursorType_477620() == 10) {
				v4 = v1->field_4 - 64;
				v3 = v1->field_0 - 64;
				v2 = sub_477FF0();
				sub_48B3F0(v2, v3, v4);
			} else {
				sub_48B3F0(0, v1->field_0 - 64, v1->field_4 - 64);
			}
			nox_video_waitVBlankAndDrawCursorFromThread_48B5D0(1, 1);
		}
	}
	return result;
}

//----- (0048C0C0) --------------------------------------------------------
int __cdecl sub_48C0C0(int a1, _DWORD* a2, _DWORD* a3) {
	int result; // eax
	_DWORD* v4; // eax
	_DWORD* v5; // eax

	result = (*(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492)(a1);
	dword_5d4594_1193516 = result;
	if (result) {
		v4 = (_DWORD*)(result + 8);
		dword_5d4594_1193516 = v4;
		*a2 -= *v4;
		v5 = (_DWORD*)(dword_5d4594_1193516 + 4);
		dword_5d4594_1193516 = v5;
		*a3 -= *v5;
		result = 1;
	}
	return result;
}

//----- (0048C170) --------------------------------------------------------
void __cdecl sub_48C170(int4* a1, int4* a2) {
	if (nox_video_renderTargetFlags & 0x10) {
		a1->field_0 = *getMemU32Ptr(0x5D4594, 1193684) * a2->field_0 / nox_backbuffer_width;
		a1->field_8 = *getMemU32Ptr(0x5D4594, 1193684) * a2->field_8 / nox_backbuffer_width;
		a1->field_4 = *getMemU32Ptr(0x5D4594, 1193688) * a2->field_4 / nox_backbuffer_height;
		a1->field_C = *getMemU32Ptr(0x5D4594, 1193688) * a2->field_C / nox_backbuffer_height;
	} else {
		a1->field_0 = a2->field_0;
		a1->field_8 = a2->field_8;
		a1->field_4 = a2->field_4;
		a1->field_C = a2->field_C;
	}
}

//----- (0048C420) --------------------------------------------------------
char sub_48C420() {
	_BYTE* v0;          // esi
	_BYTE* v1;          // edi
	unsigned __int8 v2; // dl
	int v3;             // ecx
	int v4;             // eax
	int v6;             // edx
	int v7;             // edx

	v0 = *(_BYTE**)&dword_5d4594_1193516;
	v1 = *(_BYTE**)&dword_5d4594_1193584;
	v2 = getMemByte(0x5D4594, 1193520);
	v3 = *getMemU32Ptr(0x5D4594, 1193520) >> 2;
	if (*getMemU32Ptr(0x5D4594, 1193520) >> 2) {
		do {
			v4 = *(_DWORD*)v0;
			v0 += 4;
			*(_DWORD*)v1 = v4;
			v1 += 4;
		} while (v3-- > 1);
	}
	v6 = v2 & 3;
	if (v6) {
		LOBYTE(v4) = *v0++;
		*v1++ = v4;
		v7 = v6 - 1;
		if (v7) {
			LOBYTE(v4) = *v0++;
			*v1++ = v4;
			if (v7 != 1) {
				LOBYTE(v4) = *v0++;
				*v1++ = v4;
			}
		}
	}
	dword_5d4594_1193516 = v0;
	dword_5d4594_1193584 = v1;
	return v4;
}

//----- (0048C480) --------------------------------------------------------
__int16 sub_48C480() {
	int* v0;    // esi
	_DWORD* v1; // edi
	char v2;    // cf
	int v3;     // ecx
	int v4;     // eax

	v0 = *(int**)&dword_5d4594_1193516;
	v1 = *(_DWORD**)&dword_5d4594_1193584;
	v2 = getMemByte(0x5D4594, 1193520) & 1;
	v3 = *getMemU32Ptr(0x5D4594, 1193520) >> 1;
	if (*getMemU32Ptr(0x5D4594, 1193520) >> 1) {
		do {
			v4 = *v0;
			++v0;
			*v1 = v4;
			++v1;
		} while (v3-- > 1);
	}
	if (v2) {
		LOWORD(v4) = *(_WORD*)v0;
		v0 = (int*)((char*)v0 + 2);
		*(_WORD*)v1 = v4;
		v1 = (_DWORD*)((char*)v1 + 2);
	}
	dword_5d4594_1193516 = v0;
	dword_5d4594_1193584 = v1;
	return v4;
}
