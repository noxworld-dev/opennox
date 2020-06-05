#include "client/drawable/drawable.h"
#include "common/system/settings.h"
#include "common/system/team.h"

#include "client/gui/gadgets/listbox.h"
#include "client/gui/gamewin/gamewin.h"
#include "client/gui/gui_ctf.h"
#include "client/gui/guibook.h"
#include "client/gui/guibrief.h"
#include "client/gui/guicon.h"
#include "client/gui/guisave.h"
#include "client/gui/guispell.h"
#include "client/gui/servopts/access.h"
#include "client/gui/servopts/general.h"
#include "client/gui/servopts/guiserv.h"
#include "client/gui/servopts/playrlst.h"
#include "common/gamemech/pausefx.h"

#include "client/audio/audevent.h"

#include "proto.h"

extern _DWORD dword_5d4594_1045460;
extern _DWORD dword_587000_122848;
extern _DWORD dword_5d4594_1046932;
extern _DWORD dword_5d4594_1046528;
extern _DWORD dword_5d4594_1046948;
extern _DWORD dword_5d4594_830864;
extern _DWORD dword_5d4594_1047528;
extern _DWORD dword_5d4594_1046636;
extern _DWORD dword_5d4594_832520;
extern _DWORD dword_5d4594_832500;
extern _DWORD dword_5d4594_832528;
extern _DWORD dword_5d4594_1045688;
extern _DWORD dword_5d4594_823776;
extern _DWORD dword_5d4594_832524;
extern _DWORD dword_5d4594_832512;
extern _DWORD dword_5d4594_832496;
extern _DWORD dword_587000_132136;
extern _DWORD dword_5d4594_832516;
extern _DWORD dword_5d4594_1046520;
extern _DWORD dword_5d4594_1049532;
extern _DWORD dword_5d4594_832508;
extern _DWORD dword_5d4594_832504;
extern _DWORD dword_5d4594_831224;
extern _DWORD dword_5d4594_1046928;
extern _DWORD dword_5d4594_1045508;
extern _DWORD dword_5d4594_1046504;
extern _DWORD dword_5d4594_832492;
extern _DWORD dword_5d4594_1047512;
extern _DWORD dword_5d4594_832532;
extern _DWORD dword_5d4594_1046656;
extern _DWORD dword_587000_80824;
extern _DWORD dword_5d4594_1049484;
extern _DWORD dword_5d4594_830872;
extern _DWORD dword_5d4594_1046516;
extern _DWORD dword_5d4594_839888;
extern _DWORD dword_5d4594_832536;
extern _DWORD dword_5d4594_1046952;
extern _DWORD dword_587000_81128;
extern _DWORD dword_587000_122852;
extern _DWORD dword_5d4594_1046532;
extern _QWORD qword_581450_9568;
extern _DWORD dword_5d4594_1049496;
extern _DWORD dword_5d4594_1047932;
extern _DWORD dword_5d4594_1049512;
extern _DWORD dword_5d4594_831232;
extern _DWORD dword_5d4594_1045432;
extern _DWORD dword_5d4594_1046924;
extern _DWORD dword_587000_127004;
extern _DWORD dword_5d4594_1045468;
extern _DWORD dword_5d4594_833720;
extern _DWORD dword_5d4594_1045532;
extern _DWORD dword_5d4594_1045536;
extern _DWORD dword_5d4594_1046508;
extern _DWORD dword_5d4594_833712;
extern _DWORD dword_5d4594_1045480;
extern _DWORD dword_5d4594_1047520;
extern _DWORD dword_587000_132132;
extern _DWORD dword_5d4594_3799524;
extern _DWORD dword_5d4594_1045484;
extern _DWORD dword_5d4594_1045464;
extern _DWORD dword_5d4594_1049520;
extern _DWORD dword_5d4594_1045528;
extern _DWORD dword_5d4594_831088;
extern _DWORD dword_5d4594_1046936;
extern _DWORD dword_5d4594_1047540;
extern _DWORD dword_5d4594_831236;
extern _DWORD dword_5d4594_1046496;
extern _DWORD dword_5d4594_1046872;
extern _DWORD dword_5d4594_2650672;
extern _DWORD dword_5d4594_833716;
extern _DWORD dword_5d4594_815132;
extern _DWORD dword_5d4594_1045636;
extern _DWORD dword_5d4594_1049508;
extern _DWORD dword_5d4594_1047516;
extern _DWORD dword_5d4594_1049500;
extern _DWORD dword_5d4594_1045604;
extern _DWORD dword_587000_26048;
extern _DWORD dword_5d4594_1046868;
extern _DWORD dword_5d4594_1049504;
extern _DWORD dword_587000_80828;
extern _DWORD dword_5d4594_832484;
extern _DWORD dword_5d4594_1045684;
extern _DWORD dword_5d4594_1045516;
extern _DWORD dword_587000_133480;
extern _DWORD dword_5d4594_1046492;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

extern nox_thing* nox_things_head;
extern nox_thing** nox_things_array;
extern int nox_things_count;

nox_window* nox_win_unk1 = 0;

nox_alloc_class* nox_alloc_drawable = 0;

nox_drawable* nox_drawable_head_unk1 = 0;
nox_drawable* nox_drawable_head_unk2 = 0;
nox_drawable* nox_drawable_head_unk3 = 0;
nox_drawable* nox_drawable_head_unk4 = 0;
int nox_drawable_count = 0;

extern nox_parse_thing_funcs_t nox_parse_thing_funcs[];
extern int nox_parse_thing_funcs_cnt;

//----- (0044CCA0) --------------------------------------------------------
int sub_44CCA0() {
	int result; // eax

	result = 0;
	memset(&byte_5D4594[830616], 0, 0x6Cu);
	memset(&byte_5D4594[830724], 0, 0x6Cu);
	memset(&byte_5D4594[830296], 0, 0x6Cu);
	return result;
}

//----- (0044CCD0) --------------------------------------------------------
size_t sub_44CCD0() {
	int i;         // esi
	size_t result; // eax

	for (i = 0; i < 108; i += 4) {
		result = *(_DWORD*)&byte_5D4594[i + 830616];
		if (result) {
			result = (size_t)nox_calloc(1u, 8 * result);
			*(_DWORD*)&byte_5D4594[i + 830296] = result;
		} else {
			*(_DWORD*)&byte_5D4594[i + 830296] = 0;
		}
		*(_DWORD*)&byte_5D4594[i + 830724] = 0;
	}
	return result;
}

//----- (0044CD10) --------------------------------------------------------
CHAR* __cdecl sub_44CD10(CHAR* a1) {
	CHAR* result; // eax

	result = a1;
	if (a1) {
		result = (CHAR*)sub_44CD30(a1);
		if ((int)result >= 0)
			++*(_DWORD*)&byte_5D4594[4 * (_DWORD)result + 830616];
	}
	return result;
}

//----- (0044CD30) --------------------------------------------------------
int __cdecl sub_44CD30(CHAR* a1) {
	int result; // eax
	int v2;     // eax

	if (!a1)
		return -1;
	v2 = toupper(*a1);
	if (v2 < 65 || v2 > 90)
		result = 26;
	else
		result = v2 - 65;
	return result;
}

//----- (0044CD60) --------------------------------------------------------
void __cdecl sub_44CD60(nox_thing* a1, int a2) {
	if (!a1)
		return;

	int v2 = sub_44CD30(a1->name);
	if (v2 < 0)
		return;

	int v3 = *(_DWORD*)&byte_5D4594[4 * v2 + 830296];
	if (!v3)
		return;

	int v4 = *(_DWORD*)&byte_5D4594[4 * v2 + 830724];
	*(_DWORD*)(v3 + 8 * v4) = a1;
	*(_DWORD*)(v3 + 8 * v4 + 4) = a2;
	++*(_DWORD*)&byte_5D4594[4 * v2 + 830724];
}

//----- (0044CDB0) --------------------------------------------------------
void sub_44CDB0() {
	int i;         // esi
	signed int v1; // eax

	for (i = 0; i < 108; i += 4) {
		v1 = *(_DWORD*)&byte_5D4594[i + 830616];
		if (v1 > 1)
			qsort(*(void**)&byte_5D4594[i + 830296], v1, 8u, sub_44CDE0);
	}
}

//----- (0044CDE0) --------------------------------------------------------
int __cdecl sub_44CDE0(const void* a1, const void* a2) { return _strcmpi(**(const char***)a1, **(const char***)a2); }

//----- (0044CE00) --------------------------------------------------------
int __cdecl nox_parse_thing(nox_memfile* f, char* a2, nox_thing* obj) {
	char* v3;            // ebx
	unsigned __int8* v4; // eax
	char* v5;            // edi
	char* v8;            // eax
	unsigned __int8 v10; // [esp+18h] [ebp+8h]

	v3 = a2;
	while (1) {
		v10 = nox_memfile_read_u8(f);
		if (!v10)
			return 1;
		nox_memfile_read(v3, 1u, v10, f);
		v3[v10] = 0;
		v5 = strtok(v3, " \t\n\r");
		for (int i = 0; i < nox_parse_thing_funcs_cnt; i++) {
			nox_parse_thing_funcs_t* v6 = &nox_parse_thing_funcs[i];
			if (strcmp(v5, v6->name) == 0) {
				v8 = strtok(0, "=");
				if (v8)
					memmove(v3, v8 + 1, strlen(v8 + 1) + 1);
				v6->parse_func(obj, f, v3);
				break;
			}
		}
	}
}

//----- (0044CEF0) --------------------------------------------------------
char* __cdecl nox_get_thing_name(int i) {
	if (i < 1 || i >= nox_things_count)
		return 0;
	return nox_things_array[i]->name;
}

//----- (0044CF10) --------------------------------------------------------
nox_thing* __cdecl nox_get_thing(int i) {
	if (i < 1 || i >= nox_things_count)
		return 0;
	return nox_things_array[i];
}

//----- (0044CF30) --------------------------------------------------------
wchar_t* __cdecl nox_get_thing_pretty_name(int i) {
	if (i < 1 || i >= nox_things_count)
		return 0;
	return nox_things_array[i]->pretty_name;
}

//----- (0044CF60) --------------------------------------------------------
wchar_t* __cdecl nox_get_thing_desc(int i) {
	if (i < 1 || i >= nox_things_count)
		return 0;
	return nox_things_array[i]->desc;
}

//----- (0044CF90) --------------------------------------------------------
int __cdecl nox_get_thing_pretty_image(int i) {
	if (i < 1 || i >= nox_things_count)
		return 0;
	return nox_things_array[i]->pretty_image;
}

//----- (0044CFC0) --------------------------------------------------------
int __cdecl sub_44CFC0(CHAR* a1) { return sub_44CFD0(a1); }

//----- (0044CFD0) --------------------------------------------------------
int __cdecl sub_44CFD0(CHAR* a1) {
	int v1;         // eax
	signed int v2;  // ecx
	const void* v3; // eax
	_DWORD* v4;     // eax
	int result;     // eax

	if (a1 && (v1 = sub_44CD30(a1), v1 >= 0) && (v2 = *(_DWORD*)&byte_5D4594[4 * v1 + 830616], v2 >= 0) &&
	    (v3 = *(const void**)&byte_5D4594[4 * v1 + 830296]) != 0 &&
	    (v4 = bsearch(a1, v3, v2, 8u, sub_44D020)) != 0) {
		result = v4[1];
	} else {
		result = 0;
	}
	return result;
}

//----- (0044D020) --------------------------------------------------------
int __cdecl sub_44D020(const void* a1, const void* a2) { return _strcmpi((const char*)a1, **(const char***)a2); }

//----- (0044D040) --------------------------------------------------------
int __cdecl sub_44D040(int i) {
	nox_thing* obj = nox_get_thing(i);
	if (!obj)
		return 0;
	return (obj->pri_class >> 22) & 1;
}

//----- (0044D060) --------------------------------------------------------
BOOL __cdecl sub_44D060(int a1) {
	int v1; // eax

	v1 = nox_get_thing(a1);
	return v1 && *(_DWORD*)(v1 + 32) & 0x400000 && *(_BYTE*)(v1 + 36) & 0x18;
}

//----- (0044D090) --------------------------------------------------------
int __cdecl sub_44D090(int a1) {
	int result; // eax

	result = nox_get_thing(a1);
	if (result)
		result = (*(_DWORD*)(result + 32) & 0x20400000) != 0;
	return result;
}

//----- (0044D0C0) --------------------------------------------------------
int __cdecl nox_drawable_link_thing(nox_drawable* a1, int i) {
	void* v2;   // esi
	_DWORD* v3; // ebx
	_DWORD* v4; // ebp
	int v6;     // ecx
	float v9;   // [esp+4h] [ebp+4h]

	if (i < 1 || i >= nox_things_count)
		return 0;
	v2 = a1;
	memset(a1, 0, sizeof(nox_drawable));
	a1->field_27 = i;
	v3 = &a1->field_34;
	v4 = &a1->field_38;
	int v5 = &(nox_things_array[i]->hwidth);
	*((_BYTE*)&a1->field_0) = *(_BYTE*)v5;
	*((_BYTE*)&a1->field_0 + 1) = *(_BYTE*)(v5 + 1);
	*(_WORD*)((char*)a1 + 104 + 2) = *(_WORD*)(v5 + 10);
	a1->field_28 = *(_DWORD*)(v5 + 20);
	a1->field_29 = *(_DWORD*)(v5 + 24);
	a1->flags = *(_DWORD*)(v5 + 28);
	a1->field_70 = *(_DWORD*)(v5 + 72);
	*(_BYTE*)((char*)a1 + 298) = *(_BYTE*)(v5 + 2);
	a1->draw_func = *(_DWORD*)(v5 + 76); // nox_thing->draw_func
	a1->field_76 = *(_DWORD*)(v5 + 80);
	a1->field_77 = *(_DWORD*)(v5 + 84);
	a1->field_116 = *(_DWORD*)(v5 + 88);
	a1->field_123 = *(_DWORD*)(v5 + 92);
	a1->field_34 = *(unsigned __int8*)(v5 + 3);
	a1->field_42 = *(_DWORD*)(v5 + 4);
	a1->field_38 = *(_DWORD*)(v5 + 36);
	a1->field_39 = *(_DWORD*)(v5 + 40);
	a1->field_40 = *(_DWORD*)(v5 + 44);
	a1->field_41_0 = *(_WORD*)(v5 + 12);
	a1->field_41_1 = *(_WORD*)(v5 + 14);

	a1->shape.kind = *(unsigned __int8*)(v5 + 8);
	a1->shape.circle_r = *(float*)(v5 + 52);
	a1->shape.circle_r2 = *(float*)(v5 + 52) * *(float*)(v5 + 52);
	a1->shape.box_w = *(float*)(v5 + 64);
	a1->shape.box_h = *(float*)(v5 + 68);
	if (a1->shape.kind == NOX_SHAPE_BOX)
		nox_shape_box_calc(&a1->shape);

	a1->field_24 = *(float*)(v5 + 56);
	a1->field_25 = *(float*)(v5 + 60);
	v9 = *(float*)(v5 + 32);
	if (v9 >= *(double*)&qword_581450_9568) {
		*(_DWORD*)((char*)v2 + 172) = 0;
	} else {
		v9 = -v9;
		*(_DWORD*)((char*)v2 + 172) = 1;
	}
	*(float*)((char*)v2 + 140) = v9;
	if (v9 != 0.0) {
		sub_484D70_light_intensity((char*)v2 + 136, v9);
		if (!*v3) {
			*v3 = 1;
			*v4 = 255;
			*(_DWORD*)((char*)v2 + 156) = 255;
			*(_DWORD*)((char*)v2 + 160) = 255;
		}
	}
	if (*(_DWORD*)((char*)v2 + 112) & 0x13001000) {
		*(_DWORD*)((char*)v2 + 432) = 0;
		*(_DWORD*)((char*)v2 + 436) = 0;
		*(_DWORD*)((char*)v2 + 440) = 0;
		*(_DWORD*)((char*)v2 + 444) = 0;
		*(_WORD*)((char*)v2 + 448) = -1;
		*(_WORD*)((char*)v2 + 450) = -1;
	}
	nox_thing* v7 = nox_things_array[i];
	if (v7->lifetime)
		sub_49B950((_DWORD*)v2, v7->lifetime);
	return 1;
}

//----- (0044D2C0) --------------------------------------------------------
void sub_44D2C0() {
	for (nox_thing* cur = nox_things_head; cur; cur = cur->next) {
		if (cur->shape_kind == NOX_SHAPE_BOX) {
			double r = cur->shape_r;

			nox_shape s;
			s.kind = NOX_SHAPE_BOX;
			s.circle_r = r;
			s.circle_r2 = r * r;
			nox_shape_box_calc(&s);
		}
	}
}

//----- (0044D310) --------------------------------------------------------
nox_thing* nox_get_things_head() { return nox_things_head; }

//----- (0044D320) --------------------------------------------------------
int __cdecl sub_44D320(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 108);
	else
		result = 0;
	return result;
}

//----- (0044D330) --------------------------------------------------------
int __cdecl sub_44D330(CHAR* a1) { return sub_44D340(a1); }

//----- (0044D340) --------------------------------------------------------
int __cdecl sub_44D340(CHAR* a1) {
	int v1;        // eax
	signed int v2; // ecx
	int* v3;       // eax
	int result;    // eax

	if (a1 && (v1 = sub_44CD30(a1), v1 >= 0) && (v2 = *(_DWORD*)&byte_5D4594[4 * v1 + 830616], v2 >= 0) &&
	    (v3 = (int*)bsearch(a1, *(const void**)&byte_5D4594[4 * v1 + 830296], v2, 8u, sub_44D020)) != 0) {
		result = *v3;
	} else {
		result = 0;
	}
	return result;
}

//----- (0044D390) --------------------------------------------------------
int nox_get_things_count() { return nox_things_count; }

//----- (0044D3A0) --------------------------------------------------------
void sub_44D3A0() {
	if (*(_DWORD*)&byte_5D4594[831076]) {
		switch (dword_5d4594_830864) {
		case 0:
			if (dword_5d4594_830872 && dword_587000_122848) {
				if (!sub_44D660(*(const char**)&dword_5d4594_830872))
					goto LABEL_29;
				if (!*(_DWORD*)&byte_587000[122856] || !*(_DWORD*)&byte_587000[93160] ||
				    *(_DWORD*)&byte_5D4594[831084])
					goto LABEL_16;
				*(_DWORD*)&byte_5D4594[831084] = 1;
				sub_43DBD0();
				dword_5d4594_830864 = 1;
			} else if (*(_DWORD*)&byte_5D4594[831084]) {
				sub_43DBE0();
				*(_DWORD*)&byte_5D4594[831084] = 0;
			}
			break;
		case 1:
			if (!sub_43DC40())
			LABEL_16:
				dword_5d4594_830864 = 2;
			break;
		case 2:
			sub_486320(&byte_5D4594[830876], 0x4000);
			if (!sub_44D7E0(*(int*)&byte_5D4594[830868])) {
				dword_5d4594_830864 = 0;
				goto LABEL_29;
			}
			dword_5d4594_830864 = 3;
			*(_DWORD*)&byte_5D4594[830972] = dword_5d4594_830872;
			*(_DWORD*)&byte_5D4594[830860] = *(_DWORD*)&byte_5D4594[830868];
			break;
		case 3:
			if (!dword_587000_122848 || !*(_DWORD*)&byte_5D4594[830972] ||
			    dword_5d4594_830872 != *(_DWORD*)&byte_5D4594[830972] ||
			    !dword_5d4594_831088 || AIL_stream_status(dword_5d4594_831088) == 2) {
				dword_5d4594_830864 = 4;
				sub_486350((int)&byte_5D4594[830876], 0);
			}
			break;
		case 4:
			if (!dword_5d4594_831088 || AIL_stream_status(dword_5d4594_831088) == 2 ||
			    !(*(_DWORD*)&byte_5D4594[830880] & 0xFFFF0000)) {
				sub_44D640();
				dword_5d4594_830864 = 0;
				if (*(_DWORD*)&byte_5D4594[831084]) {
					sub_43DBE0();
					*(_DWORD*)&byte_5D4594[831084] = 0;
				}
				if (*(_DWORD*)&byte_5D4594[830972] == dword_5d4594_830872)
				LABEL_29:
					dword_5d4594_830872 = 0;
			}
			break;
		default:
			break;
		}
		sub_486520((unsigned int*)&byte_5D4594[830980]);
		sub_486520((unsigned int*)&byte_5D4594[830876]);
		if (dword_5d4594_831088 &&
		    (**(_BYTE**)&dword_587000_81128 & 2 || byte_5D4594[830876] & 2 || byte_5D4594[830980] & 2)) {
			sub_44D5C0(*(int*)&dword_5d4594_831088, *(int*)&byte_5D4594[830860]);
		}
	}
}
// 58141C: using guessed type int __stdcall AIL_stream_status(_DWORD);

//----- (0044D5C0) --------------------------------------------------------
void __cdecl sub_44D5C0(int a1, int a2) {
	unsigned int v2; // eax

	if (a1) {
		v2 = (*(_DWORD*)(dword_587000_81128 + 4) >> 16) *
		     ((*(unsigned __int16*)&byte_5D4594[830882] *
		       ((a2 * (unsigned int)*(unsigned __int16*)&byte_5D4594[830986]) >> 14)) >>
		      14);
		*(_DWORD*)&byte_5D4594[830876] &= 0xFFFFFFFD;
		**(_DWORD**)&dword_587000_122852 &= 0xFFFFFFFD;
		AIL_set_stream_volume(a1, (int)(127 * (v2 >> 14)) / 100);
	}
}
// 581430: using guessed type int __stdcall AIL_set_stream_volume(_DWORD, _DWORD);

//----- (0044D640) --------------------------------------------------------
int sub_44D640() {
	int result; // eax

	result = dword_5d4594_831088;
	if (dword_5d4594_831088) {
		AIL_close_stream(dword_5d4594_831088);
		dword_5d4594_831088 = 0;
	}
	return result;
}
// 581418: using guessed type int __stdcall AIL_close_stream(_DWORD);

//----- (0044D660) --------------------------------------------------------
BOOL __cdecl sub_44D660(const char* a1) {
	unsigned __int8 v1; // dl
	char* v2;           // edi
	int v3;             // eax
	char* v4;           // eax
	unsigned int v5;    // kr08_4
	char v7[540];       // [esp+Ch] [ebp-21Ch]

	sub_44D640();
	strcpy(v7, "dialog\\");
	*(_DWORD*)&byte_587000[122856] = 0;
	strcat(v7, a1);
	if (!strchr(v7, 46)) {
		v1 = byte_587000[122872];
		v2 = &v7[strlen(v7)];
		*(_DWORD*)v2 = *(_DWORD*)&byte_587000[122868];
		v2[4] = v1;
	}
	v3 = AIL_open_stream(*(_DWORD*)&byte_5D4594[831092], v7, 51200);
	dword_5d4594_831088 = v3;
	if (v3)
		return v3 != 0;
	v4 = sub_413890();
	if (!v4) {
		v3 = dword_5d4594_831088;
		return v3 != 0;
	}
	*(_DWORD*)&byte_587000[122856] = 1;
	strncpy(&v7[40], v4, 0x1F4u);
	v7[539] = 0;
	v5 = strlen(&v7[40]) + 1;
	if (v5 != 1 && v7[v5 + 38] != 92)
		*(_WORD*)&v7[strlen(&v7[40]) + 40] = *(_WORD*)&byte_587000[122876];
	strcat(&v7[40], v7);
	dword_5d4594_831088 = AIL_open_stream(*(_DWORD*)&byte_5D4594[831092], &v7[40], 51200);
	return dword_5d4594_831088 != 0;
}
// 581408: using guessed type int __stdcall AIL_open_stream(_DWORD, _DWORD, _DWORD);

//----- (0044D7E0) --------------------------------------------------------
int __cdecl sub_44D7E0(int a1) {
	if (!dword_5d4594_831088)
		return 0;
	sub_44D5C0(*(int*)&dword_5d4594_831088, a1);
	AIL_start_stream(dword_5d4594_831088);
	return 1;
}
// 581410: using guessed type int __stdcall AIL_start_stream(_DWORD);

//----- (0044D8C0) --------------------------------------------------------
void sub_44D8C0() {
	if (*(_DWORD*)&byte_5D4594[831076]) {
		sub_44D8F0();
		sub_44D640();
		sub_44D3A0();
		*(_DWORD*)&byte_5D4594[831076] = 0;
	}
}

//----- (0044D8F0) --------------------------------------------------------
int sub_44D8F0() {
	int result; // eax

	result = 0;
	dword_5d4594_830872 = 0;
	*(_DWORD*)&byte_5D4594[830972] = 0;
	return result;
}

//----- (0044D900) --------------------------------------------------------
int __cdecl sub_44D900(int a1, int a2) {
	int v2; // eax

	if (dword_587000_122848 && a1) {
		v2 = a2;
		if (a2 > 100)
			v2 = 100;
		dword_5d4594_830872 = a1;
		*(_DWORD*)&byte_5D4594[830868] = v2;
	}
	return 1;
}

//----- (0044D930) --------------------------------------------------------
int sub_44D930() {
	if (!dword_587000_122848)
		return 0;
	if (dword_5d4594_830872 || dword_5d4594_831088)
		return 1;
	return 0;
}

//----- (0044D960) --------------------------------------------------------
void sub_44D960() { dword_587000_122848 = 0; }

//----- (0044D970) --------------------------------------------------------
int sub_44D970() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[831092];
	if (*(_DWORD*)&byte_5D4594[831092])
		dword_587000_122848 = 1;
	return result;
}

//----- (0044D990) --------------------------------------------------------
int sub_44D990() { return dword_587000_122848; }

//----- (0044D9A0) --------------------------------------------------------
int sub_44D9A0() {
	if (*(_DWORD*)&byte_5D4594[823772]) {
		return 1;
	}
	sub_44D9D0();
	return 1;
}

//----- (0044D9D0) --------------------------------------------------------
void sub_44D9D0() {
	struc_36* arr = (struc_36*)&byte_5D4594[831108];
	for (int i = 0; i < 4; i++) {
		arr[i].fields[0] = 0;
	}
}

//----- (0044D9F0) --------------------------------------------------------
int __cdecl sub_44D9F0(int a1) {
	int v1;               // ebx
	unsigned __int8* v2;  // edi
	int v3;               // ebp
	unsigned __int8* v4;  // esi
	int result;           // eax
	int (*result2)(void); // eax

	v1 = 1;
	if (a1)
		v1 = 5;
	*(_DWORD*)&byte_5D4594[831100] = clock();
	v2 = &byte_5D4594[831112];
	v3 = 4;
	do {
		v4 = v2 - 4;
		result = (int)(*((_DWORD*)v2 - 1) & 5);
		if (result == v1) {
			(*((void(__cdecl**)(unsigned __int8*))v2 + 5))(v2 - 4);
			result = *(int*)v2;
			if (*(int*)v2 <= 0) {
				if (!(*v4 & 2)) {
					result2 = (int (*)(void)) * ((_DWORD*)v2 + 4);
					*(_DWORD*)v4 &= ~v1;
					if (result2)
						result = result2();
				}
			} else {
				result--;
				*(_DWORD*)v2 = result;
			}
		}
		v2 += 28;
		--v3;
	} while (v3);
	return result;
}

//----- (0044DA60) --------------------------------------------------------
int __cdecl sub_44DA60(int a1) {
	if (sub_44DFD0(sub_44DD70)) {
		return 1;
	}
	struc_36* obj = sub_44DF50();
	if (!obj)
		return 0;
	int v1 = 3;
	if (a1)
		v1 = 7;
	obj->fields[0] = v1;
	obj->fields[1] = 0;
	obj->fields[2] = 0;
	obj->fields[3] = 0;
	obj->field_5 = 0;
	obj->field_6 = sub_44DDC0;
	return 1;
}

//----- (0044DAB0) --------------------------------------------------------
int __cdecl nox_client_screenFadeTimeout_44DAB0(int a1, int a2, void (*a3)(void)) {
	if (dword_5d4594_2650672 == 1) {
		if (a3)
			a3();
		return 1;
	}
	sub_44DF90(sub_44DD20);
	struc_36* obj = sub_44DF50();
	if (!obj)
		return 0;

	int v3 = 1;
	if (a2)
		v3 = 5;
	obj->fields[0] = v3;
	obj->fields[1] = a1;
	obj->fields[2] = 0;
	obj->fields[3] = 16711680 / a1;
	obj->field_5 = a3;
	obj->field_6 = sub_44DD20;
	return 1;
}

//----- (0044DB30) --------------------------------------------------------
int __cdecl sub_44DB30(int a1, int a2, void (*a3)(void)) {
	sub_44DF90(sub_44DD70);
	struc_36* obj = sub_44DF50();
	if (!obj) {
		return 0;
	}
	int v3 = 1;
	if (a2)
		v3 = 5;
	obj->fields[0] = v3;
	obj->fields[1] = a1;
	obj->fields[2] = 0;
	obj->fields[3] = 16711680 / a1;
	obj->field_5 = a3;
	obj->field_6 = sub_44DD70;
	sub_44DF90(sub_44DDC0);
	return 1;
}

//----- (0044DBA0) --------------------------------------------------------
int __cdecl sub_44DBA0(int a1, int a2, void (*a3)(void)) {
	struc_36* obj = sub_44DF50();
	if (!obj) {
		return 0;
	}
	int v3 = 1;
	if (a2)
		v3 = 5;
	obj->fields[0] = v3;
	obj->fields[1] = a1;
	obj->fields[2] = 0;
	obj->fields[3] = 16711680 / a1;
	obj->field_5 = a3;
	obj->field_6 = sub_44DDF0;
	return 1;
}

//----- (0044DBF0) --------------------------------------------------------
int __cdecl sub_44DBF0(int a1, int a2, void (*a3)(void)) {
	struc_36* obj = sub_44DF50();
	if (!obj) {
		return 0;
	}
	int v3 = 1;
	if (a2)
		v3 = 5;
	obj->fields[0] = v3;
	obj->fields[1] = a1;
	obj->fields[2] = 0;
	obj->fields[3] = 16711680 / a1;
	obj->field_5 = a3;
	obj->field_6 = sub_44DE30;
	return 1;
}

//----- (0044DC40) --------------------------------------------------------
int __cdecl sub_44DC40(int a1, int a2) {
	struc_36* obj = sub_44DF50();
	if (!obj) {
		return 0;
	}
	int v4 = a1 * nox_backbuffer_height / 100;
	obj->fields[0] = 3;
	obj->fields[1] = a2;
	obj->fields[2] = 0;
	obj->fields[3] = (v4 << 16) / a2;
	obj->field_5 = 0;
	obj->field_6 = sub_44DE80;
	return 1;
}

//----- (0044DCA0) --------------------------------------------------------
int __cdecl sub_44DCA0(int a1, int a2) {
	struc_36* obj = sub_44DF50();
	if (!obj) {
		return 0;
	}
	int v4 = a1 * nox_backbuffer_height / 100;
	v4 <<= 16;
	obj->fields[0] = 1;
	obj->fields[1] = a2;
	obj->fields[2] = v4;
	obj->fields[3] = v4 / a2;
	obj->fields[4] = 0;
	obj->field_5 = 0;
	obj->field_6 = sub_44DEE0;
	return 1;
}

//----- (0044DD00) --------------------------------------------------------
BOOL sub_44DD00() { return sub_44DFD0(sub_44DE80) != 0; }

//----- (0044DD20) --------------------------------------------------------
int __cdecl sub_44DD20(int a1) {
	int result; // eax

	sub_433F10(*(int*)(a1 + 8) >> 16, *(int*)(a1 + 8) >> 16, *(int*)(a1 + 8) >> 16);
	nox_client_drawRectFadingScreen_49D0F0(0, 0, nox_backbuffer_width, nox_backbuffer_height);
	result = *(_DWORD*)(a1 + 12);
	*(_DWORD*)(a1 + 8) += result;
	return result;
}

//----- (0044DD70) --------------------------------------------------------
int __cdecl sub_44DD70(int a1) {
	int v1;             // esi
	int result;         // eax
	unsigned __int8 v3; // [esp+8h] [ebp+4h]

	v1 = a1;
	v3 = -1 - (*(int*)(a1 + 8) >> 16);
	sub_433F10(v3, v3, v3);
	nox_client_drawRectFadingScreen_49D0F0(0, 0, nox_backbuffer_width, nox_backbuffer_height);
	result = *(_DWORD*)(v1 + 12) + *(_DWORD*)(v1 + 8);
	*(_DWORD*)(v1 + 8) = result;
	return result;
}

//----- (0044DDC0) --------------------------------------------------------
void sub_44DDC0() {
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
	nox_client_drawRectFilledOpaque_49CE30(0, 0, nox_backbuffer_width, nox_backbuffer_height);
}

//----- (0044DDF0) --------------------------------------------------------
int4* __cdecl sub_44DDF0(int a1) {
	int v1; // edx

	v1 = *(_DWORD*)(a1 + 12) + *(_DWORD*)(a1 + 8);
	*(_DWORD*)(a1 + 8) = v1;
	sub_433F10(BYTE2(v1), BYTE2(v1), BYTE2(v1));
	return sub_49D050(0, 0, nox_backbuffer_width, nox_backbuffer_height);
}

//----- (0044DE30) --------------------------------------------------------
int4* __cdecl sub_44DE30(int a1) {
	int v1; // edx

	v1 = *(_DWORD*)(a1 + 12) + *(_DWORD*)(a1 + 8);
	*(_DWORD*)(a1 + 8) = v1;
	sub_433F10(-1 - BYTE2(v1), -1 - BYTE2(v1), -1 - BYTE2(v1));
	return sub_49D050(0, 0, nox_backbuffer_width, nox_backbuffer_height);
}

//----- (0044DE80) --------------------------------------------------------
void __cdecl sub_44DE80(_DWORD* a1) {
	int v1; // esi

	if (a1[1])
		a1[2] += a1[3];
	v1 = a1[2] >> 16;
	sub_434430(0, 0, 0);
	nox_client_drawRectFilledOpaque_49CE30(0, 0, nox_backbuffer_width, v1);
	nox_client_drawRectFilledOpaque_49CE30(0, nox_backbuffer_height - v1, nox_backbuffer_width, v1);
}

//----- (0044DEE0) --------------------------------------------------------
void __cdecl sub_44DEE0(_DWORD* a1) {
	int v1; // ecx
	int v2; // esi

	if (!a1[4]) {
		sub_44DF90(sub_44DE80);
		a1[4] = 1;
	}
	v1 = a1[2] - a1[3];
	a1[2] = v1;
	v2 = v1 >> 16;
	sub_434430(0, 0, 0);
	nox_client_drawRectFilledOpaque_49CE30(0, 0, nox_backbuffer_width, v2);
	nox_client_drawRectFilledOpaque_49CE30(0, nox_backbuffer_height - v2, nox_backbuffer_width, v2);
}

//----- (0044DF50) --------------------------------------------------------
struc_36* sub_44DF50() {
	struc_36* it = (struc_36*)&byte_5D4594[831108];
	int v1 = 0;
	while (it->fields[0] & 1) {
		it++;
		if (++v1 >= 4)
			return 0;
	}
	return it;
}

//----- (0044DF70) --------------------------------------------------------
char* sub_44DF70() {
	struc_36* arr = (struc_36*)&byte_5D4594[831108];
	for (int i = 0; i < 4; i++) {
		int v2 = arr->fields[0];
		arr++;
		*((_DWORD*)arr - 7) = v2 & 0xFFFFFFFE;
	}
	return arr;
}

//----- (0044DF90) --------------------------------------------------------
int __cdecl sub_44DF90(int a1) {
	void (*v4)(void); // eax

	int result = 0;
	struc_36* it = (struc_36*)&byte_5D4594[831108];
	for (int i = 0; i < 4; i++) {
		if (it->fields[0] & 1 && it->field_6 == a1) {
			v4 = it->field_5;
			it->fields[0] &= 0xFFFFFFFE;
			if (v4)
				v4();
			result = 1;
		}
		it++;
	}
	return result;
}

//----- (0044DFD0) --------------------------------------------------------
int __cdecl sub_44DFD0(int a1) {
	struc_36* it = (struc_36*)&byte_5D4594[831108];
	int v2 = 0;
	while (!(it->fields[0] & 1) || it->field_6 != a1) {
		it++;
		if (++v2 >= 4)
			return 0;
	}
	return it != 0;
}

//----- (0044E000) --------------------------------------------------------
void sub_44E000() {
	if (!sub_44DFD0(sub_44DD70))
		dword_5d4594_2650672 = 1;
}

//----- (0044E020) --------------------------------------------------------
void sub_44E020() {
	if (!sub_44DFD0(sub_44DD20))
		sub_413A00(0);
}

//----- (0044E040) --------------------------------------------------------
void sub_44E040() {
	sub_44E070();
	sub_44E090();
	sub_44DF90(sub_44DDC0);
	dword_5d4594_2650672 = 0;
	sub_413A00(0);
}

//----- (0044E070) --------------------------------------------------------
int sub_44E070() {
	sub_44DF90(sub_44DD70);
	return sub_44DF90(sub_44DE30);
}

//----- (0044E090) --------------------------------------------------------
int sub_44E090() {
	sub_44DF90(sub_44DD20);
	return sub_44DF90(sub_44DDF0);
}

//----- (0044E0B0) --------------------------------------------------------
int __cdecl sub_44E0B0(int a1) {
	sub_44E070();
	sub_44E090();
	dword_5d4594_2650672 = 1;
	return sub_44DA60(a1);
}

//----- (0044E0D0) --------------------------------------------------------
BOOL sub_44E0D0() {
	if (sub_44DFD0(sub_44DD70))
		return 1;
	if (sub_44DFD0(sub_44DD20))
		return 1;
	return dword_5d4594_2650672 != 0;
}

//----- (0044E110) --------------------------------------------------------
_DWORD* sub_44E110() {
	_DWORD* v0;     // eax
	int v1;         // eax
	_DWORD* v2;     // eax
	int v3;         // eax
	_DWORD* v4;     // eax
	int v5;         // eax
	_DWORD* v6;     // eax
	int v7;         // eax
	_DWORD* v8;     // eax
	int v9;         // eax
	_DWORD* v10;    // eax
	int v11;        // eax
	_DWORD* v12;    // eax
	int v13;        // eax
	_DWORD* v14;    // eax
	int v15;        // eax
	_DWORD* v16;    // eax
	int v17;        // eax
	_DWORD* v18;    // eax
	int v19;        // eax
	_DWORD* v20;    // eax
	int v21;        // eax
	_DWORD* result; // eax
	int v23;        // eax

	if (!dword_5d4594_832484)
		dword_5d4594_832484 = sub_43F360((char*)&byte_587000[123044]);
	v0 = *(_DWORD**)&dword_5d4594_832496;
	if (!dword_5d4594_832496) {
		v1 = sub_44CFC0((CHAR*)&byte_587000[123052]);
		v0 = nox_new_drawable_for_thing(v1);
		dword_5d4594_832496 = v0;
	}
	v0[30] |= 0x1000000u;
	v2 = *(_DWORD**)&dword_5d4594_832492;
	if (!dword_5d4594_832492) {
		v3 = sub_44CFC0((CHAR*)&byte_587000[123068]);
		v2 = nox_new_drawable_for_thing(v3);
		dword_5d4594_832492 = v2;
	}
	v2[30] |= 0x1000000u;
	v4 = *(_DWORD**)&dword_5d4594_832500;
	if (!dword_5d4594_832500) {
		v5 = sub_44CFC0((CHAR*)&byte_587000[123088]);
		v4 = nox_new_drawable_for_thing(v5);
		dword_5d4594_832500 = v4;
	}
	v4[30] |= 0x1000000u;
	v6 = *(_DWORD**)&dword_5d4594_832504;
	if (!dword_5d4594_832504) {
		v7 = sub_44CFC0((CHAR*)&byte_587000[123096]);
		v6 = nox_new_drawable_for_thing(v7);
		dword_5d4594_832504 = v6;
	}
	v6[30] |= 0x1000000u;
	v8 = *(_DWORD**)&dword_5d4594_832508;
	if (!dword_5d4594_832508) {
		v9 = sub_44CFC0((CHAR*)&byte_587000[123108]);
		v8 = nox_new_drawable_for_thing(v9);
		dword_5d4594_832508 = v8;
	}
	v8[30] |= 0x1000000u;
	v10 = *(_DWORD**)&dword_5d4594_832512;
	if (!dword_5d4594_832512) {
		v11 = sub_44CFC0((CHAR*)&byte_587000[123120]);
		v10 = nox_new_drawable_for_thing(v11);
		dword_5d4594_832512 = v10;
	}
	v10[30] |= 0x1000000u;
	v12 = *(_DWORD**)&dword_5d4594_832516;
	if (!dword_5d4594_832516) {
		v13 = sub_44CFC0((CHAR*)&byte_587000[123128]);
		v12 = nox_new_drawable_for_thing(v13);
		dword_5d4594_832516 = v12;
	}
	v12[30] |= 0x1000000u;
	v14 = *(_DWORD**)&dword_5d4594_832520;
	if (!dword_5d4594_832520) {
		v15 = sub_44CFC0((CHAR*)&byte_587000[123144]);
		v14 = nox_new_drawable_for_thing(v15);
		dword_5d4594_832520 = v14;
	}
	v14[30] |= 0x1000000u;
	v16 = *(_DWORD**)&dword_5d4594_832524;
	if (!dword_5d4594_832524) {
		v17 = sub_44CFC0((CHAR*)&byte_587000[123160]);
		v16 = nox_new_drawable_for_thing(v17);
		dword_5d4594_832524 = v16;
	}
	v16[30] |= 0x1000000u;
	v18 = *(_DWORD**)&dword_5d4594_832528;
	if (!dword_5d4594_832528) {
		v19 = sub_44CFC0((CHAR*)&byte_587000[123176]);
		v18 = nox_new_drawable_for_thing(v19);
		dword_5d4594_832528 = v18;
	}
	v18[30] |= 0x1000000u;
	v20 = *(_DWORD**)&dword_5d4594_832532;
	if (!dword_5d4594_832532) {
		v21 = sub_44CFC0((CHAR*)&byte_587000[123188]);
		v20 = nox_new_drawable_for_thing(v21);
		dword_5d4594_832532 = v20;
	}
	v20[30] |= 0x1000000u;
	result = *(_DWORD**)&dword_5d4594_832536;
	if (!dword_5d4594_832536) {
		v23 = sub_44CFC0((CHAR*)&byte_587000[123200]);
		result = nox_new_drawable_for_thing(v23);
		dword_5d4594_832536 = result;
	}
	result[30] |= 0x1000000u;
	return result;
}

//----- (0044E320) --------------------------------------------------------
void sub_44E320() {
	int v0; // eax

	sub_46ADE0(*(int*)&dword_5d4594_831236);
	sub_46B500(0);
	nox_window_set_hidden(*(int*)&dword_5d4594_831236, 1);
	sub_450580();
	sub_43DDA0();
	dword_5d4594_2650672 = 0;
	if (*(_DWORD*)&byte_5D4594[831220] == 255) {
		if (dword_5d4594_815132 == 1) {
			sub_4505E0();
			sub_4A2500();
			sub_578E00();
		}
	} else if (byte_5D4594[832472] & 5) {
		nox_client_lockScreenBriefing_450160(254, 1, 2);
		return;
	}
	v0 = nox_client_getIntroScreenDuration_44E3B0();
	sub_44DB30(v0, 1, sub_44E3C0);
}

//----- (0044E3B0) --------------------------------------------------------
int nox_client_getIntroScreenDuration_44E3B0() { return 25; }

//----- (0044E3C0) --------------------------------------------------------
int sub_44E3C0() {
	sub_450580();
	*(_DWORD*)&byte_5D4594[831260] = 0;
	return sub_413A00(0);
}

//----- (0044E3E0) --------------------------------------------------------
int sub_44E3E0() {
	int result; // eax

	result = dword_5d4594_831224;
	*(_DWORD*)&byte_5D4594[831248] = 1;
	if (dword_5d4594_831224) {
		result = sub_44D900(*(int*)&byte_5D4594[831240], 100);
		*(_DWORD*)&byte_5D4594[831244] = 1;
	}
	return result;
}

//----- (0044E560) --------------------------------------------------------
_DWORD* sub_44E560() {
	_DWORD* result; // eax
	_DWORD* v1;     // eax

	*(_DWORD*)&byte_5D4594[831284] = (nox_win_width - NOX_DEFAULT_WIDTH) / 2;
	*(_DWORD*)&byte_5D4594[831288] = (nox_win_height - NOX_DEFAULT_HEIGHT) / 2;
	result = nox_window_new(0, 56, 0, 0, nox_win_width, nox_win_height, sub_44E6E0);
	dword_5d4594_831236 = result;
	if (result) {
		sub_46B300((int)result, nox_client_wndQuestBriefProc_44E630);
		*(_DWORD*)(dword_5d4594_831236 + 56) = *(_DWORD*)&byte_5D4594[2650656];
		result = nox_new_window_from_file("Briefing.wnd", 0);
		dword_5d4594_831232 = result;
		if (result) {
			sub_46B120(result, *(int*)&dword_5d4594_831236);
			sub_46A9B0(*(_DWORD**)&dword_5d4594_831232, *(int*)&byte_5D4594[831284],
				   *(int*)&byte_5D4594[831288]);
			v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_831232, 1010);
			sub_46B340((int)v1, sub_44E6F0);
			sub_44E410();
			result = *(_DWORD**)&dword_5d4594_831236;
		}
	}
	return result;
}

//----- (0044E630) --------------------------------------------------------
int __cdecl nox_client_wndQuestBriefProc_44E630(int a1, int a2, int a3, int a4) {
	int v2; // eax

	if (*(_DWORD*)&byte_5D4594[831248] && a2 != 18 && a2 != 17 && sub_41D1B0() != 1) {
		sub_450580();
		if (*(_DWORD*)&byte_5D4594[831220]) {
			if (*(_DWORD*)&byte_5D4594[831220] == 255) {
				dword_5d4594_2650672 = 0;
				v2 = nox_client_getIntroScreenDuration_44E3B0();
				nox_client_screenFadeTimeout_44DAB0(v2, 1, sub_44E320);
				dword_5d4594_2650672 = 1;
			}
		} else {
			sub_46ADE0(*(int*)&dword_5d4594_831236);
			sub_46B500(0);
			*(_DWORD*)&byte_5D4594[831256] = 1;
			sub_46D580();
		}
		sub_46B300(*(int*)&dword_5d4594_831236, 0);
	}
	return 1;
}

//----- (0044E6E0) --------------------------------------------------------
BOOL __cdecl sub_44E6E0(int a1, int a2, int a3, int a4) { return a2 == 23; }

//----- (0044E6F0) --------------------------------------------------------
int __cdecl sub_44E6F0(_DWORD* a1, int xLeft) {
	int v2; // eax
	int v3; // eax

	*(float*)&byte_5D4594[831276] = *(float*)&byte_5D4594[831276] - sub_44E8B0();
	v2 = nox_float2int(*(float*)&byte_5D4594[831276]);
	sub_46A9B0(a1, 0, v2);
	nox_client_copyRect_49F6F0(*(int*)&byte_5D4594[831284], *(int*)&byte_5D4594[831288], NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT);
	if (byte_5D4594[832472] & 1) {
		sub_44E8E0((int)a1, xLeft);
	} else if (byte_5D4594[832472] & 2) {
		sub_44F0F0((int)a1, xLeft);
	} else if (byte_5D4594[832472] & 4) {
		sub_44F300((int)a1, xLeft);
	} else {
		sub_488D00((int)a1, xLeft);
	}
	nox_client_copyRect_49F6F0(0, 0, nox_backbuffer_width, nox_backbuffer_height);
	if ((__int64)*(float*)&byte_5D4594[831276] <= *(int*)&byte_5D4594[831280] &&
	    *(_DWORD*)&byte_5D4594[831244] == 1 && !sub_44D930() &&
	    (unsigned __int64)(sub_416BB0() - *(_QWORD*)&byte_5D4594[831292]) > 0x3A98 &&
	    (*(_DWORD*)&byte_5D4594[832488] == 1 || !(byte_5D4594[832472] & 5))) {
		if (byte_5D4594[832472] & 2 && *(_DWORD*)&byte_5D4594[832480])
			sub_452D80(582, 100);
		sub_450580();
		if (*(_DWORD*)&byte_5D4594[831220]) {
			dword_5d4594_2650672 = 0;
			v3 = nox_client_getIntroScreenDuration_44E3B0();
			nox_client_screenFadeTimeout_44DAB0(v3, 1, sub_44E320);
			dword_5d4594_2650672 = 1;
		} else if (!*(_DWORD*)&byte_5D4594[831256]) {
			sub_46ADE0(*(int*)&dword_5d4594_831236);
			*(_DWORD*)&byte_5D4594[831256] = 1;
			sub_46D580();
			sub_46B300(*(int*)&dword_5d4594_831236, 0);
		}
		sub_46B340((int)a1, sub_44E8D0);
	}
	return 1;
}

//----- (0044E8B0) --------------------------------------------------------
double sub_44E8B0() {
	double result; // st7

	if (*(_DWORD*)&byte_5D4594[831220] == 255)
		result = 1.0;
	else
		result = 0.0;
	return result;
}

//----- (0044E8D0) --------------------------------------------------------
int sub_44E8D0() { return 1; }

// called both for quest and solo games chapter intro/briefing
//----- (00450160) --------------------------------------------------------
int __cdecl nox_client_lockScreenBriefing_450160(int a1, int a2, char a3) {
	int v3;                 // ebx
	int v4;                 // edi
	_DWORD* v5;             // esi
	int v6;                 // edi
	char* v7;               // eax
	char* v8;               // eax
	char* v9;               // eax
	int v10;                // edi
	int v11;                // eax
	int v12;                // eax
	int result;             // eax
	int v14;                // [esp+Ch] [ebp-4h]
	unsigned __int16** v15; // [esp+14h] [ebp+4h]

	v3 = a1;
	*(_DWORD*)&byte_5D4594[831260] = 1;
	*(_DWORD*)&byte_5D4594[831244] = 1;
	v14 = *(_DWORD*)&byte_5D4594[2618908];
	*(_DWORD*)&byte_5D4594[832488] = 0;
	*(_DWORD*)&byte_5D4594[832472] = 0;
	*(_DWORD*)&byte_5D4594[831256] = 0;
	byte_5D4594[831252] = a1 + 1; // 254/255 for quest, 0 for solo
	if (*(_DWORD*)&byte_5D4594[2618908])
		v4 = *(unsigned __int8*)(*(_DWORD*)&byte_5D4594[2618908] + 2251);
	else
		v4 = a2; // chapter
	sub_46A8C0(*(int*)&dword_5d4594_831236);
	sub_46ADC0(*(int*)&dword_5d4594_831236);
	sub_46B500(*(int*)&dword_5d4594_831236);
	sub_46B300(*(int*)&dword_5d4594_831236, nox_client_wndQuestBriefProc_44E630);
	v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_831232, 1010);
	sub_46B340((int)v5, sub_44E6F0);
	*(_DWORD*)&byte_5D4594[831220] = a2;
	v15 = (unsigned __int16**)v5[8];
	if (v3 == 255) {
		sub_46AE60(*(int*)&dword_5d4594_831232, 0);
		nox_window_call_field_94((int)v5, 16385, *(int*)&byte_5D4594[831268], 0);
		sub_46AD80((int)v5, 0x2000);
		*(_DWORD*)&byte_5D4594[831240] = sub_578D80();
		v6 = 24;
		*(_DWORD*)&byte_5D4594[831220] = 255;
	} else if (v3 == 254) {
		nox_server_currentMapGetFilename_409B30();
		v7 = sub_42F970("GauntletStartMines");
		sub_46AE60(*(int*)&dword_5d4594_831232, (int)v7);
		nox_window_call_field_94((int)v5, 16385, (int)&byte_5D4594[832540], 0);
		v6 = 0;
		if (a3 & 1) {
			*(_DWORD*)&byte_5D4594[832472] = 1;
			v8 = sub_42F970("MenuSystemBG");
			sub_46AE60(*(int*)&dword_5d4594_831232, (int)v8);
			sub_431510();
			sub_45ACA0(1);
		} else if (a3 & 4) {
			*(_DWORD*)&byte_5D4594[832472] = 4;
			v9 = sub_42F970("GauntletInstructionBackground");
			sub_46AE60(*(int*)&dword_5d4594_831232, (int)v9);
			sub_431510();
			sub_45ACA0(1);
		} else {
			*(_DWORD*)&byte_5D4594[832472] = 2;
			sub_46AE60(*(int*)&dword_5d4594_831232, *(int*)&byte_5D4594[832460]);
			if (*(_DWORD*)&byte_5D4594[832464])
				nox_window_call_field_94((int)v5, 16385, *(int*)&byte_5D4594[832464], 0);
			sub_431510();
			sub_45ACA0(1);
		}
		sub_446780();
		*(_DWORD*)&byte_5D4594[831240] = 0;
		*(_DWORD*)&byte_5D4594[831244] = 1;
		dword_5d4594_831224 = 0;
	} else {
		v10 = 32 * (v3 + v4 + 10 * v4);
		if (a2) {
			sub_46AE60(*(int*)&dword_5d4594_831232, *(_DWORD*)&byte_5D4594[v10 + 831300]);
			nox_window_call_field_94((int)v5, 16385, *(_DWORD*)&byte_5D4594[v10 + 831304], 0);
			v11 = *(_DWORD*)&byte_5D4594[v10 + 831308];
			v6 = *(_DWORD*)&byte_5D4594[v10 + 831312];
		} else {
			sub_46AE60(*(int*)&dword_5d4594_831232, *(_DWORD*)&byte_5D4594[v10 + 831316]);
			nox_window_call_field_94((int)v5, 16385, *(_DWORD*)&byte_5D4594[v10 + 831320], 0);
			v11 = *(_DWORD*)&byte_5D4594[v10 + 831324];
			v6 = *(_DWORD*)&byte_5D4594[v10 + 831328];
		}
		*(_DWORD*)&byte_5D4594[831240] = v11;
	}
	sub_43F840(v5[59], *v15, 0, &byte_5D4594[831280], NOX_DEFAULT_HEIGHT);
	sub_46AB20(v5, NOX_DEFAULT_WIDTH, *(int*)&byte_5D4594[831280]);
	if (v3 == 255) {
		*(_DWORD*)&byte_5D4594[831276] = 1140457472;
		*(_DWORD*)&byte_5D4594[831280] = -20 - *(_DWORD*)&byte_5D4594[831280];
	} else {
		*(_DWORD*)&byte_5D4594[831280] = (480 - *(_DWORD*)(v5[59] + 8) - *(int*)&byte_5D4594[831280]) / 2;
		*(float*)&byte_5D4594[831276] = (double)*(int*)&byte_5D4594[831280];
	}
	sub_431290();
	dword_5d4594_831224 = 0;
	if (a2 || v3 == 255) {
		if (v3 != 254)
			dword_5d4594_831224 = 1;
	} else if (v3 != 254) {
		if (*(_DWORD*)(v14 + 4 * v3 + 4408)) {
			sub_46ADE0(*(int*)&dword_5d4594_831236);
			*(_DWORD*)&byte_5D4594[831256] = 1;
			sub_46D580();
			sub_46B300(*(int*)&dword_5d4594_831236, 0);
		} else {
			dword_5d4594_831224 = 1;
			*(_DWORD*)(v14 + 4 * v3 + 4408) = 1;
		}
	}
	sub_43DD70(v6, 50);
	*(_QWORD*)&byte_5D4594[831292] = sub_416BB0();
	*(_DWORD*)&byte_5D4594[831248] = 0;
	v12 = nox_client_getIntroScreenDuration_44E3B0();
	sub_44DB30(v12, 1, sub_44E3E0);
	result = dword_5d4594_831224;
	if (dword_5d4594_831224)
		*(_DWORD*)&byte_5D4594[831244] = 0;
	return result;
}

//----- (00450560) --------------------------------------------------------
int sub_450560() { return *(_DWORD*)&byte_5D4594[831260]; }

//----- (00450570) --------------------------------------------------------
int sub_450570() { return *(_DWORD*)&byte_5D4594[831220]; }

//----- (00450580) --------------------------------------------------------
int sub_450580() {
	int result; // eax

	sub_44D8F0();
	result = 0;
	*(_DWORD*)&byte_5D4594[832488] = 1;
	dword_5d4594_831224 = 0;
	*(_DWORD*)&byte_5D4594[831292] = 0;
	*(_DWORD*)&byte_5D4594[831296] = 0;
	return result;
}

//----- (004505B0) --------------------------------------------------------
int sub_4505B0() {
	int v0;     // eax
	int result; // eax

	sub_450580();
	dword_5d4594_2650672 = 0;
	v0 = nox_client_getIntroScreenDuration_44E3B0();
	result = nox_client_screenFadeTimeout_44DAB0(v0, 1, sub_44E320);
	dword_5d4594_2650672 = 1;
	return result;
}

//----- (004505E0) --------------------------------------------------------
int sub_4505E0() {
	int result; // eax

	if (dword_5d4594_831236) {
		sub_46C4E0(*(_DWORD**)&dword_5d4594_831236);
		dword_5d4594_831236 = 0;
		dword_5d4594_831232 = 0;
	}
	*(_DWORD*)&byte_5D4594[831260] = 0;
	dword_5d4594_832484 = 0;
	if (dword_5d4594_832504)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832504);
	dword_5d4594_832504 = 0;
	if (dword_5d4594_832492)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832492);
	dword_5d4594_832492 = 0;
	if (dword_5d4594_832500)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832500);
	dword_5d4594_832500 = 0;
	if (dword_5d4594_832496)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832496);
	dword_5d4594_832496 = 0;
	if (dword_5d4594_832508)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832508);
	dword_5d4594_832508 = 0;
	if (dword_5d4594_832512)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832512);
	dword_5d4594_832512 = 0;
	if (dword_5d4594_832516)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832516);
	dword_5d4594_832516 = 0;
	if (dword_5d4594_832520)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832520);
	dword_5d4594_832520 = 0;
	if (dword_5d4594_832524)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832524);
	dword_5d4594_832524 = 0;
	if (dword_5d4594_832528)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832528);
	dword_5d4594_832528 = 0;
	if (dword_5d4594_832532)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_832532);
	result = dword_5d4594_832536;
	dword_5d4594_832532 = 0;
	if (dword_5d4594_832536)
		result = sub_45A4B0(*(_QWORD**)&dword_5d4594_832536);
	dword_5d4594_832536 = 0;
	return result;
}

//----- (00450750) --------------------------------------------------------
unsigned __int8 sub_450750() { return byte_5D4594[831252]; }

//----- (00450760) --------------------------------------------------------
char __cdecl sub_450760(char a1) {
	char result; // al

	result = a1;
	byte_5D4594[831252] = a1;
	return result;
}

//----- (00450960) --------------------------------------------------------
int __cdecl sub_450960(const void* a1, const void* a2) {
	unsigned int v2; // eax
	unsigned int v3; // ecx
	int result;      // eax

	v2 = *((_DWORD*)a1 + 3);
	v3 = *((_DWORD*)a2 + 3);
	if (v2 == v3)
		result = 0;
	else
		result = v2 < v3 ? 1 : -1;
	return result;
}

//----- (00450AD0) --------------------------------------------------------
char* __cdecl sub_450AD0(char* a1) {
	char* result; // eax

	result = a1;
	if (!a1)
		result = sub_42F970("WarriorChapterBegin8");
	*(_DWORD*)&byte_5D4594[832460] = result;
	return result;
}

//----- (00450AF0) --------------------------------------------------------
int __cdecl sub_450AF0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[832464] = a1;
	return result;
}

//----- (00450B00) --------------------------------------------------------
int __cdecl sub_450B00(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[832468] = a1;
	return result;
}

//----- (00450B10) --------------------------------------------------------
int sub_450B10() { return *(_DWORD*)&byte_5D4594[832468]; }

//----- (00450B70) --------------------------------------------------------
int sub_450B70() { return nox_window_call_field_94(*(int*)&dword_5d4594_833720, 16399, 0, 0); }

//----- (00450B90) --------------------------------------------------------
int __cdecl sub_450B90(unsigned __int8 a1, int a2) {
	if (*(_DWORD*)&byte_5D4594[833724])
		nox_window_call_field_94(*(int*)&dword_5d4594_833720, 16397, a2, a1);
	if (sub_579740())
		sub_579750(a2);
	return 1;
}

//----- (00450BE0) --------------------------------------------------------
void sub_450BE0() { *(_DWORD*)&byte_5D4594[833724] = 1; }

//----- (00450BF0) --------------------------------------------------------
void sub_450BF0() { *(_DWORD*)&byte_5D4594[833724] = 0; }

//----- (00450C00) --------------------------------------------------------
int sub_450C00(unsigned __int8 a1, wchar_t* a2, ...) {
	va_list va; // [esp+Ch] [ebp+Ch]

	va_start(va, a2);
	nox_vswprintf((wchar_t*)&byte_5D4594[832680], a2, va);
	return sub_450B90(a1, (int)&byte_5D4594[832680]);
}

//----- (00450C70) --------------------------------------------------------
int sub_450C70() {
	int v0;                   // esi
	wchar_t* v1;              // eax
	int result;               // eax
	char v3[56];              // [esp+Ch] [ebp-5A4h]
	char v4[332];             // [esp+44h] [ebp-56Ch]
	unsigned __int8 v5[1056]; // [esp+190h] [ebp-420h]

	v0 = *(_DWORD*)&byte_5D4594[2650660];
	*(_DWORD*)&byte_5D4594[833704] = nox_win_width - 1;
	*(_DWORD*)&byte_5D4594[833708] = nox_win_height / 2;
	dword_5d4594_833712 = nox_window_new(0, 56, 0, 0, nox_win_width - 1, nox_win_height / 2, 0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_833712, sub_450E80, sub_450E90, 0);
	*(_DWORD*)(dword_5d4594_833712 + 56) = *(_DWORD*)&byte_5D4594[2650656];
	memset(v4, 0, sizeof(v4));
	*(_DWORD*)&v4[36] = 0x80000000;
	*(_DWORD*)&v4[52] = 0x80000000;
	*(_DWORD*)&v4[24] = 0;
	memset(v3, 0, sizeof(v3));
	*(_DWORD*)&v4[48] = 0;
	*(_DWORD*)&v4[28] = v0;
	*(_DWORD*)&v4[68] = v0;
	*(_WORD*)&v3[2] = 0x0a;
	*(_WORD*)&v3[0] = 0x80;
	*(_DWORD*)&v3[4] = 1;
	*(_DWORD*)&v3[8] = 1;
	*(_DWORD*)&v3[12] = 1;
	*(_DWORD*)&v3[16] = 0;
	v1 = sub_401020();
	nox_wcsncpy((wchar_t*)&v4[72], v1, 0x40u);
	*(_WORD*)&v4[198] = 0;
	*(_DWORD*)&v4[8] = 32;
	dword_5d4594_833720 =
	    sub_4A4310(*(int*)&dword_5d4594_833712, 1152, 0, 0, *(int*)&byte_5D4594[833704],
		       *(_DWORD*)&byte_5D4594[833708] - 20, (int)v4, (__int16*)v3);
	*(_DWORD*)&v4[44] = v0;
	*(_DWORD*)&v4[28] = v0;
	*(_DWORD*)&v4[36] = v0;
	*(_DWORD*)&v4[52] = v0;
	*(_DWORD*)&v4[68] = v0;
	*(_WORD*)&v5[1042] = *(_WORD*)&byte_5D4594[833704];
	nox_wcscpy((wchar_t*)v5, (const wchar_t*)&byte_5D4594[833736]);
	*(_WORD*)&v5[1040] = 128;
	*(_DWORD*)&v5[1024] = 0;
	*(_DWORD*)&v5[1028] = 0;
	*(_DWORD*)&v5[1032] = 0;
	*(_DWORD*)&v5[1036] = 0;
	nox_wcscpy((wchar_t*)&v4[72], (const wchar_t*)&byte_5D4594[833740]);
	*(_DWORD*)&v4[8] = 128;
	dword_5d4594_833716 =
	    sub_488500(*(int*)&dword_5d4594_833712, 16393, 0, *(_DWORD*)&byte_5D4594[833708] - 20,
		       *(int*)&byte_5D4594[833704], 20, (int)v4, (wchar_t*)v5);
	sub_46B300(*(int*)&dword_5d4594_833716, sub_450F40);
	result = dword_5d4594_833712;
	*(_DWORD*)&byte_5D4594[833728] = 0;
	*(_DWORD*)&byte_5D4594[833732] = 0;
	*(_WORD*)&byte_5D4594[832552] = 0;
	return result;
}

//----- (00450E80) --------------------------------------------------------
int sub_450E80() { return 0; }

//----- (00450E90) --------------------------------------------------------
int __cdecl sub_450E90(int a1, int a2) {
	int xLeft; // [esp+4h] [ebp-8h]
	int yTop;  // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if (*(_BYTE*)(a1 + 4) & 0x80) {
		nox_client_drawImageAt_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
		return 1;
	}
	if (*(_DWORD*)(a2 + 20) != 0x80000000) {
		if (dword_587000_80824) {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
			return 1;
		}
		nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 20));
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
	}
	return 1;
}

//----- (00450F40) --------------------------------------------------------
int __cdecl sub_450F40(_DWORD* a1, int a2, int a3, int a4) {
	_DWORD* v4; // eax

	if (a2 != 21)
		return sub_487D70(a1, a2, a3, a4);
	v4 = sub_42CD70();
	if (v4) {
		while (v4[9] != 11 || a3 != *v4) {
			v4 = (_DWORD*)v4[19];
			if (!v4)
				goto LABEL_6;
		}
		if (a4 == 2) {
			sub_451350();
			return 1;
		}
		return 1;
	}
LABEL_6:
	if (a3 == 1) {
		if (a4 == 2)
			sub_49B7A0();
	} else {
		if (a3 != 28)
			return sub_487D70(a1, a2, a3, a4);
		if (a4 == 2) {
			sub_450FD0();
			return 1;
		}
	}
	return 1;
}

//----- (00451100) --------------------------------------------------------
int sub_451100() {
	int v0;     // ecx
	_DWORD* v1; // eax
	int v2;     // edx
	int v3;     // edx
	int v4;     // edx
	int v5;     // edx
	int result; // eax

	v0 = *(_DWORD*)&byte_5D4594[2650660];
	if (dword_5d4594_833712)
		*(_DWORD*)(dword_5d4594_833712 + 56) = *(_DWORD*)&byte_5D4594[2650656];
	if (dword_5d4594_833720) {
		v1 = *(_DWORD**)(dword_5d4594_833720 + 32);
		*(_DWORD*)(dword_5d4594_833720 + 56) = 0x80000000;
		*(_DWORD*)(dword_5d4594_833720 + 80) = 0x80000000;
		*(_DWORD*)(dword_5d4594_833720 + 64) = v0;
		*(_DWORD*)(dword_5d4594_833720 + 72) = v0;
		*(_DWORD*)(dword_5d4594_833720 + 88) = 0x80000000;
		*(_DWORD*)(dword_5d4594_833720 + 104) = v0;
		v2 = v1[9];
		if (v2) {
			*(_DWORD*)(v2 + 56) = *(_DWORD*)&byte_5D4594[2650656];
			*(_DWORD*)(v1[9] + 80) = *(_DWORD*)&byte_5D4594[2650656];
			*(_DWORD*)(v1[9] + 64) = v0;
			*(_DWORD*)(v1[9] + 72) = *(_DWORD*)&byte_5D4594[2650656];
			*(_DWORD*)(v1[9] + 88) = v0;
			v3 = *(_DWORD*)(v1[9] + 400);
			if (v3) {
				*(_DWORD*)(v3 + 56) = *(_DWORD*)&byte_5D4594[2650656];
				*(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 80) = *(_DWORD*)&byte_5D4594[2650656];
				*(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 64) = v0;
				*(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 72) = *(_DWORD*)&byte_5D4594[2650656];
				*(_DWORD*)(*(_DWORD*)(v1[9] + 400) + 88) = *(_DWORD*)&byte_5D4594[2650656];
			}
		}
		v4 = v1[7];
		if (v4) {
			*(_DWORD*)(v4 + 56) = *(_DWORD*)&byte_5D4594[2650656];
			*(_DWORD*)(v1[7] + 80) = *(_DWORD*)&byte_5D4594[2650656];
			*(_DWORD*)(v1[7] + 64) = v0;
			*(_DWORD*)(v1[7] + 72) = *(_DWORD*)&byte_5D4594[2523948];
			*(_DWORD*)(v1[7] + 88) = v0;
			*(_DWORD*)(v1[7] + 104) = v0;
		}
		v5 = v1[8];
		if (v5) {
			*(_DWORD*)(v5 + 56) = *(_DWORD*)&byte_5D4594[2650656];
			*(_DWORD*)(v1[8] + 80) = *(_DWORD*)&byte_5D4594[2650656];
			*(_DWORD*)(v1[8] + 64) = v0;
			*(_DWORD*)(v1[8] + 72) = *(_DWORD*)&byte_5D4594[2523948];
			*(_DWORD*)(v1[8] + 88) = v0;
			*(_DWORD*)(v1[8] + 104) = v0;
		}
	}
	result = dword_5d4594_833716;
	if (dword_5d4594_833716) {
		*(_DWORD*)(dword_5d4594_833716 + 56) = *(_DWORD*)&byte_5D4594[2650656];
		*(_DWORD*)(dword_5d4594_833716 + 80) = v0;
		*(_DWORD*)(dword_5d4594_833716 + 64) = v0;
		*(_DWORD*)(dword_5d4594_833716 + 72) = v0;
		*(_DWORD*)(dword_5d4594_833716 + 88) = v0;
		result = dword_5d4594_833716;
		*(_DWORD*)(dword_5d4594_833716 + 104) = v0;
	}
	return result;
}

//----- (004512B0) --------------------------------------------------------
int sub_4512B0() {
	if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_833712))
		return 0;
	if (sub_46B4F0() == dword_5d4594_833716)
		sub_46B500(0);
	nox_window_set_hidden(*(int*)&dword_5d4594_833712, 1);
	*(_DWORD*)(dword_5d4594_833712 + 4) &= 0xFFFFFFF7;
	*(_DWORD*)(dword_5d4594_833716 + 4) &= 0xFFFFFFF7;
	*(_DWORD*)(dword_5d4594_833720 + 4) &= 0xFFFFFFF7;
	*(_DWORD*)(dword_5d4594_833716 + 36) &= 0xFFFFFFFB;
	*(_DWORD*)(dword_5d4594_833716 + 36) &= 0xFFFFFFFD;
	dword_5d4594_3799524 = 1;
	return 1;
}

//----- (00451410) --------------------------------------------------------
int sub_451410() { return ((unsigned __int8)~sub_46ADA0(*(int*)&dword_5d4594_833712) >> 4) & 1; }

//----- (00451430) --------------------------------------------------------
void sub_451430() {
	int v0; // eax

	if (nox_win_height == NOX_DEFAULT_HEIGHT || nox_win_width == NOX_DEFAULT_WIDTH) {
		v0 = sub_43F320(0);
		if (*(_DWORD*)&byte_5D4594[839884]) {
			if (dword_5d4594_839888) {
				*(_DWORD*)&byte_5D4594[839884] = 0;
				dword_5d4594_839888 = 0;
			} else {
				*(_DWORD*)&byte_5D4594[839884] = 320;
				dword_5d4594_839888 = nox_win_height - 21 * v0;
			}
		} else if (dword_5d4594_839888) {
			*(_DWORD*)&byte_5D4594[839884] = 320;
			dword_5d4594_839888 = 0;
		} else {
			dword_5d4594_839888 = nox_win_height - 21 * v0;
		}
	}
}

//----- (004514F0) --------------------------------------------------------
int sub_4514F0() {
	int result;          // eax
	int v1;              // edi
	int v2;              // esi
	unsigned __int8* v3; // ebx

	result = dword_5d4594_823776;
	if (dword_5d4594_823776) {
		v1 = sub_43F320(0);
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
		nox_client_drawRectFilledOpaque_49CE30(*(int*)&byte_5D4594[839884], *(int*)&dword_5d4594_839888, 320, 21 * v1);
		nox_client_drawSetColor_434460(1);
		nox_client_drawBorderLines_49CC70(*(int*)&byte_5D4594[839884], *(int*)&dword_5d4594_839888, 320, 21 * v1);
		sub_434390(1);
		result = dword_5d4594_839888;
		v2 = dword_5d4594_839888 + 20 * v1;
		if (v2 > 0) {
			v3 = &byte_5D4594[835800];
			do {
				if ((int)v3 >= (int)&byte_5D4594[835880])
					break;
				result = sub_43FAF0(0, *(_WORD**)v3, *(_DWORD*)&byte_5D4594[839884] + 4, v2, 316, 0);
				v2 -= v1;
				v3 += 4;
			} while (v2 > 0);
		}
	}
	return result;
}

// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00451850) --------------------------------------------------------
int __cdecl sub_451850(int a2, int a3) {
	int v2;              // edi
	unsigned __int8* v3; // esi
	int result;          // eax

	v2 = 0;
	v3 = &byte_5D4594[840712];
	do {
		sub_451920((_DWORD*)v3 - 21);
		*(_DWORD*)v3 = sub_40AF80(v2);
		v3 += 200;
		++v2;
	} while ((int)v3 < (int)&byte_5D4594[1045312]);
	*(_DWORD*)&byte_5D4594[1045420] = a3;
	*(_DWORD*)&byte_5D4594[1045428] = a2;
	if (a3) {
		*(_DWORD*)&byte_5D4594[1045424] = sub_4BD340(a3, 0x100000, 200, 0x2000);
		*(_DWORD*)&byte_5D4594[1045436] = sub_4BD280(200, 576);
	}
	if (!*(_DWORD*)&byte_5D4594[1045424] || !*(_DWORD*)&byte_5D4594[1045420] || !*(_DWORD*)&byte_5D4594[1045428] ||
	    !*(_DWORD*)&byte_5D4594[1045436]) {
		return 0;
	}
	sub_425760(&byte_5D4594[840612]);
	sub_4864A0(&byte_5D4594[1045228]);
	result = 1;
	*(_DWORD*)(*(_DWORD*)&byte_5D4594[1045428] + 184) = &byte_5D4594[1045228];
	dword_5d4594_1045432 = 1;
	return result;
}

//----- (00451920) --------------------------------------------------------
int __cdecl sub_451920(_DWORD* a2) {
	*a2 = 0;
	a2[1] = 0;
	a2[2] = 0;
	a2[14] = 0;
	a2[15] = 0;
	a2[19] = 0;
	a2[20] = 0;
	a2[12] = 1;
	a2[48] = 0;
	a2[18] = 0;
	a2[17] = 0;
	a2[25] = 0;
	a2[26] = 0;
	a2[16] = 600;
	return sub_4862E0((int)(a2 + 4), 0x4000);
}

//----- (00451970) --------------------------------------------------------
void sub_451970() {
	sub_4521F0();
	sub_452230();
	if (*(_DWORD*)&byte_5D4594[1045424]) {
		sub_4BD3C0(*(LPVOID*)&byte_5D4594[1045424]);
		*(_DWORD*)&byte_5D4594[1045424] = 0;
	}
	if (*(_DWORD*)&byte_5D4594[1045436]) {
		sub_4BD2D0(*(LPVOID*)&byte_5D4594[1045436]);
		*(_DWORD*)&byte_5D4594[1045436] = 0;
	}
	dword_5d4594_1045432 = 0;
}

//----- (004519C0) --------------------------------------------------------
int sub_4519C0() {
	int result;          // eax
	int v1;              // esi
	int v2;              // eax
	int v3;              // ebp
	int v4;              // eax
	unsigned __int8* v5; // edi
	unsigned __int8* v6; // esi
	unsigned __int8* v7; // edi
	int v8;              // eax
	int v9;              // eax
	int v10;             // eax

	result = dword_5d4594_1045432;
	if (dword_5d4594_1045432) {
		result = *(_DWORD*)&byte_5D4594[1045448];
		if (!*(_DWORD*)&byte_5D4594[1045448]) {
			*(_DWORD*)&byte_5D4594[1045448] = 1;
			sub_486520(*(unsigned int**)&dword_587000_127004);
			v1 = *(_DWORD*)&byte_5D4594[840612];
			++*(_DWORD*)&byte_5D4594[1045440];
			if (*(unsigned __int8**)&byte_5D4594[840612] != &byte_5D4594[840612]) {
				do {
					v2 = *(_DWORD*)(v1 + 36);
					if (*(_DWORD*)(v2 + 100) != *(_DWORD*)&byte_5D4594[1045440]) {
						sub_425760((_DWORD*)(v2 + 88));
						*(_DWORD*)(*(_DWORD*)(v1 + 36) + 52) = 0;
						*(_DWORD*)(*(_DWORD*)(v1 + 36) + 100) = *(_DWORD*)&byte_5D4594[1045440];
					}
					sub_486520((unsigned int*)(v1 + 184));
					if (*(_DWORD*)(v1 + 28) != 4)
						sub_451BE0(v1);
					v1 = *(_DWORD*)v1;
				} while ((unsigned __int8*)v1 != &byte_5D4594[840612]);
				v1 = *(_DWORD*)&byte_5D4594[840612];
				if (*(unsigned __int8**)&byte_5D4594[840612] != &byte_5D4594[840612]) {
					do {
						sub_452510(v1);
						v1 = *(_DWORD*)v1;
					} while ((unsigned __int8*)v1 != &byte_5D4594[840612]);
					v1 = *(_DWORD*)&byte_5D4594[840612];
				}
			}
			v3 = 0;
			sub_452010();
			if ((unsigned __int8*)v1 == &byte_5D4594[840612])
				goto LABEL_35;
			do {
				v4 = *(_DWORD*)(v1 + 176);
				v5 = *(unsigned __int8**)v1;
				if (!v4 || v1 != *(_DWORD*)(v4 + 152))
					sub_4523D0((_DWORD*)v1);
				if (*(_BYTE*)(v1 + 24) & 1) {
					sub_451FE0(v1);
				} else {
					v3 += (unsigned int)(33 * (*(_DWORD*)(*(_DWORD*)(v1 + 36) + 20) >> 16)) >> 14;
					sub_452050((_DWORD*)v1);
				}
				v1 = (int)v5;
			} while (v5 != &byte_5D4594[840612]);
			if (v3 <= 100)
			LABEL_35:
				sub_486350((int)&byte_5D4594[1045228], 0x4000);
			else
				sub_486350((int)&byte_5D4594[1045228], 0x190000u / v3);
			result = sub_486520((unsigned int*)&byte_5D4594[1045228]);
			v6 = *(unsigned __int8**)&byte_5D4594[840612];
			if (*(unsigned __int8**)&byte_5D4594[840612] != &byte_5D4594[840612]) {
				do {
					v7 = *(unsigned __int8**)v6;
					result = *((_DWORD*)v6 + 7);
					if (result == 1) {
						sub_451DC0((int)v6);
						v8 = sub_451CA0(v6);
						*((_DWORD*)v6 + 74) = v8;
						if (!v8) {
							do {
								if (!sub_452120((int)v6))
									break;
								v7 = *(unsigned __int8**)v6;
								sub_451DC0((int)v6);
								v9 = sub_451CA0(v6);
								*((_DWORD*)v6 + 74) = v9;
							} while (!v9);
						}
						v10 = sub_451CA0(v6);
						*((_DWORD*)v6 + 74) = v10;
						if (!v10 || (result = sub_452490(v6)) == 0) {
							sub_4523D0(v6);
							result = sub_451FE0((int)v6);
						}
					}
					v6 = v7;
				} while (v7 != &byte_5D4594[840612]);
			}
			*(_DWORD*)&byte_5D4594[1045448] = 0;
		}
	}
	return result;
}

//----- (00451BE0) --------------------------------------------------------
int __cdecl sub_451BE0(int a1) {
	int v1;          // eax
	int v2;          // edi
	unsigned int v3; // ebx
	_DWORD* v4;      // esi
	int v5;          // eax
	int v6;          // eax
	_DWORD* v7;      // ebx
	int result;      // eax
	int v9;          // esi
	_DWORD* v10;     // esi

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 36);
	v3 = *(_DWORD*)(a1 + 188) >> 16;
	v4 = *(_DWORD**)(v2 + 88);
	if (v4 != (_DWORD*)(v2 + 88)) {
		do {
			v5 = (v4[44] >> 16) - v3;
			if (v5 < 0)
				v5 = v3 - (v4[44] >> 16);
			if (v5 >= (*(_DWORD*)(v2 + 20) >> 16) / 10) {
				if (v4[44] >> 16 < v3)
					break;
			} else {
				v6 = v4[4];
				if (*(_BYTE*)(v2 + 4) & 0x10) {
					if (v6)
						break;
				} else if (!v6) {
					break;
				}
			}
			v4 = (_DWORD*)*v4;
		} while (v4 != (_DWORD*)(v2 + 88));
		v1 = a1;
	}
	v7 = (_DWORD*)(v1 + 12);
	sub_425770((_DWORD*)(v1 + 12));
	sub_4258E0((int)v4, v7);
	result = *(_DWORD*)(v2 + 56);
	v9 = *(_DWORD*)(v2 + 52) + 1;
	*(_DWORD*)(v2 + 52) = v9;
	if (result) {
		if (v9 > result) {
			v10 = (_DWORD*)(*(_DWORD*)(v2 + 92) - 12);
			sub_425920(*(_DWORD***)(v2 + 92));
			sub_4523D0(v10);
			result = *(_DWORD*)(v2 + 52) - 1;
			*(_DWORD*)(v2 + 52) = result;
		}
	}
	return result;
}

//----- (00451CA0) --------------------------------------------------------
int __cdecl sub_451CA0(_DWORD* a1) {
	int v1;     // ecx
	int v3;     // eax
	_DWORD* v4; // ecx

	v1 = a1[42];
	a1[108] = v1;
	if (!v1)
		return 0;
	v3 = 0;
	if (v1 > 0) {
		v4 = a1 + 76;
		do {
			*v4 = v3++;
			++v4;
		} while (v3 < a1[108]);
	}
	a1[43] = -1;
	return sub_451CF0(a1);
}

//----- (00451F30) --------------------------------------------------------
int __cdecl sub_451F30(int a1, int a2) {
	int v2;     // edx
	int result; // eax

	*(_DWORD*)(a1 + 4 * *(_DWORD*)(a1 + 168) + 40) =
	    sub_4BD470(*(_DWORD***)&byte_5D4594[1045424], *(__int16*)(*(_DWORD*)(a1 + 36) + 2 * a2 + 128));
	v2 = *(_DWORD*)(a1 + 168);
	result = *(_DWORD*)(a1 + 4 * v2 + 40);
	if (result) {
		sub_4BD650(*(_DWORD*)(a1 + 4 * v2 + 40));
		result = *(_DWORD*)(a1 + 168) + 1;
		*(_DWORD*)(a1 + 168) = result;
	}
	return result;
}

//----- (00451F90) --------------------------------------------------------
int __cdecl sub_451F90(int a1) {
	int v1;     // edi
	int result; // eax
	int* v3;    // esi

	v1 = 0;
	result = *(_DWORD*)(a1 + 168);
	if (result <= 0) {
		*(_DWORD*)(a1 + 168) = 0;
	} else {
		v3 = (int*)(a1 + 40);
		do {
			sub_4BD660(*v3);
			*v3 = 0;
			result = *(_DWORD*)(a1 + 168);
			++v1;
			++v3;
		} while (v1 < result);
		*(_DWORD*)(a1 + 168) = 0;
	}
	return result;
}

//----- (00451FE0) --------------------------------------------------------
int __cdecl sub_451FE0(int a1) {
	sub_425920((_DWORD**)a1);
	*(_DWORD*)(a1 + 280) = 0;
	return sub_4BD300(*(_DWORD**)&byte_5D4594[1045436], a1);
}

//----- (00452010) --------------------------------------------------------
int sub_452010() {
	unsigned __int8* v0; // esi
	int v1;              // ebx
	int v2;              // edi

	v0 = &byte_5D4594[839892];
	v1 = 6;
	do {
		v2 = 10;
		do {
			sub_425760(v0);
			v0 += 12;
			--v2;
		} while (v2);
		--v1;
	} while (v1);
	return ++*(_DWORD*)&byte_5D4594[1045444];
}

//----- (00452050) --------------------------------------------------------
_DWORD* __cdecl sub_452050(_DWORD* a1) {
	_DWORD* v1;          // esi
	int v2;              // edi
	unsigned int v3;     // ebx
	unsigned __int8* v4; // ebp
	_DWORD* result;      // eax
	_DWORD** v6;         // esi
	_DWORD** v7;         // esi
	_DWORD* v8;          // esi

	v1 = (_DWORD*)a1[9];
	v2 = v1[12] + a1[75];
	v3 = (a1[47] >> 16) / 0x666u;
	v4 = &byte_5D4594[120 * v2 + 839892];
	if (v1[26] == *(_DWORD*)&byte_5D4594[1045444]) {
		result = (_DWORD*)v1[27];
		if (v2 <= (int)result) {
			if ((_DWORD*)v2 == result && v3 > v1[31]) {
				v1[31] = v3;
				v7 = (_DWORD**)(v1 + 28);
				sub_425920(v7);
				result = sub_4258E0((int)&v4[12 * v3], v7);
			}
		} else {
			v1[27] = v2;
			v1[31] = v3;
			v6 = (_DWORD**)(v1 + 28);
			sub_425920(v6);
			result = sub_4258E0((int)&v4[12 * v3], v6);
		}
	} else {
		v1[26] = *(_DWORD*)&byte_5D4594[1045444];
		v1[27] = v2;
		v1[31] = v3;
		v8 = v1 + 28;
		sub_425770(v8);
		result = sub_4258E0((int)&v4[12 * v3], v8);
	}
	return result;
}

//----- (00452120) --------------------------------------------------------
int* __cdecl sub_452120(int a1) {
	int v1;              // ebp
	int* result;         // eax
	int* v3;             // ebx
	unsigned __int8* v4; // esi
	unsigned __int8* v5; // edi

	v1 = 0;
	result = sub_4521A0(*(_DWORD*)(a1 + 300) + *(_DWORD*)(*(_DWORD*)(a1 + 36) + 48));
	v3 = result;
	if (result) {
		sub_452190((int)result);
		v4 = *(unsigned __int8**)&byte_5D4594[840612];
		if (*(unsigned __int8**)&byte_5D4594[840612] != &byte_5D4594[840612]) {
			do {
				v5 = *(unsigned __int8**)v4;
				if (*((int**)v4 + 9) == v3) {
					sub_4523D0(v4);
					sub_451FE0((int)v4);
					v1 = 1;
				}
				v4 = v5;
			} while (v5 != &byte_5D4594[840612]);
		}
		result = (int*)v1;
	}
	return result;
}

//----- (00452190) --------------------------------------------------------
_DWORD** __cdecl sub_452190(int a1) { return sub_425920((_DWORD**)(a1 + 112)); }

//----- (004521A0) --------------------------------------------------------
int* __cdecl sub_4521A0(int a1) {
	int v1;              // ebp
	unsigned __int8* v2; // ebx
	int v3;              // edi
	int* v4;             // esi
	int* v5;             // eax

	v1 = 0;
	v2 = &byte_5D4594[839892];
	if (a1 > 0) {
		while (1) {
			v3 = 0;
			v4 = (int*)v2;
			do {
				v5 = sub_425890(v4);
				if (v5)
					return v5 - 28;
				++v3;
				v4 += 3;
			} while (v3 < 10);
			++v1;
			v2 += 120;
			if (v1 < a1)
				continue;
			break;
		}
	}
	return 0;
}

//----- (004521F0) --------------------------------------------------------
int sub_4521F0() {
	int result;          // eax
	unsigned __int8* v1; // esi
	unsigned __int8* v2; // edi

	result = dword_5d4594_1045432;
	if (dword_5d4594_1045432) {
		v1 = *(unsigned __int8**)&byte_5D4594[840612];
		if (*(unsigned __int8**)&byte_5D4594[840612] != &byte_5D4594[840612]) {
			do {
				v2 = *(unsigned __int8**)v1;
				sub_4523D0(v1);
				result = sub_451FE0((int)v1);
				v1 = v2;
			} while (v2 != &byte_5D4594[840612]);
		}
	}
	return result;
}

//----- (00452230) --------------------------------------------------------
int***** sub_452230() {
	int***** result; // eax
	int**** v1;      // esi

	result = *(int******)&dword_5d4594_1045432;
	if (dword_5d4594_1045432) {
		result = *(int******)&byte_5D4594[840612];
		if (*(unsigned __int8**)&byte_5D4594[840612] != &byte_5D4594[840612]) {
			do {
				v1 = *result;
				if ((_BYTE)result[6] & 1)
					sub_451FE0((int)result);
				result = (int*****)v1;
			} while (v1 != (int****)&byte_5D4594[840612]);
		}
	}
	return result;
}

//----- (00452270) --------------------------------------------------------
char* __cdecl sub_452270(int a1) {
	char* result; // eax

	if (dword_5d4594_1045432 && a1 >= 0 && a1 < 1023)
		result = (char*)&byte_5D4594[200 * a1 + 840628];
	else
		result = 0;
	return result;
}

//----- (004522A0) --------------------------------------------------------
int __cdecl sub_4522A0(int a1) {
	int result; // eax

	if (dword_5d4594_1045432)
		result = *(_DWORD*)(a1 + 64);
	else
		result = 0;
	return result;
}

//----- (004522C0) --------------------------------------------------------
int __cdecl sub_4522C0(int a1) {
	int result; // eax

	if (dword_5d4594_1045432)
		result = *(_DWORD*)(a1 + 8);
	else
		result = 0;
	return result;
}

//----- (004522E0) --------------------------------------------------------
char* __cdecl sub_4522E0(int a1) {
	char* result; // eax

	if (dword_5d4594_1045432)
		result = *(char**)(a1 + 84);
	else
		result = (char*)&byte_587000[127128];
	return result;
}

//----- (00452300) --------------------------------------------------------
_DWORD* __cdecl sub_452300(_DWORD* a1) {
	_DWORD* v1; // esi

	if (!dword_5d4594_1045432)
		return 0;
	if (!*(_DWORD*)&byte_587000[126996])
		return 0;
	if (!*a1)
		return 0;
	v1 = sub_4BD2E0(*(_DWORD***)&byte_5D4594[1045436]);
	if (!v1) {
		sub_452230();
		v1 = sub_4BD2E0(*(_DWORD***)&byte_5D4594[1045436]);
		if (!v1)
			return 0;
	}
	memset(v1, 0, 0x240u);
	v1[9] = a1;
	sub_425770(v1);
	v1[7] = 0;
	v1[75] = 0;
	v1[142] = 0;
	v1[108] = 0;
	v1[42] = 0;
	sub_4864A0(v1 + 46);
	sub_4258E0((int)&byte_5D4594[840612], v1);
	v1[70] = (*(_DWORD*)&byte_587000[127000])++;
	return v1;
}

//----- (004523D0) --------------------------------------------------------
int __cdecl sub_4523D0(_DWORD* a1) {
	int result; // eax

	if (!(a1[6] & 1)) {
		sub_452410((int)a1);
		sub_451F90((int)a1);
		a1[7] = 4;
		a1[70] = 0;
		result = a1[6];
		LOBYTE(result) = result | 1;
		a1[6] = result;
	}
	return result;
}

//----- (00452410) --------------------------------------------------------
int __cdecl sub_452410(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 176);
	if (result && a1 == *(_DWORD*)(result + 152)) {
		if (*(_BYTE*)(a1 + 24) & 2)
			sub_4BDA80(*(_DWORD*)(a1 + 176));
		sub_4BDB30(*(_DWORD*)(a1 + 176));
		*(_DWORD*)(*(_DWORD*)(a1 + 176) + 152) = 0;
		*(_DWORD*)(*(_DWORD*)(a1 + 176) + 148) = 0;
		result = *(_DWORD*)(a1 + 176);
		*(_DWORD*)(result + 140) = 0;
		*(_DWORD*)(*(_DWORD*)(a1 + 176) + 144) = 0;
		*(_DWORD*)(*(_DWORD*)(a1 + 176) + 112) = 0;
		*(_DWORD*)(a1 + 176) = 0;
	}
	return result;
}

//----- (00452490) --------------------------------------------------------
int __cdecl sub_452490(_DWORD* a1) {
	int v1; // eax
	int v3; // edi
	int v4; // eax

	v1 = a1[44];
	if (a1 != *(_DWORD**)(v1 + 152))
		return 0;
	v3 = a1[74];
	sub_4BDB90((_DWORD*)v1, (_DWORD*)a1[74]);
	a1[7] = 3;
	v4 = a1[6];
	LOBYTE(v4) = v4 | 2;
	a1[6] = v4;
	a1[74] = 0;
	if (!sub_4BDB40(a1[44]))
		return 1;
	a1[7] = 1;
	a1[74] = v3;
	a1[6] &= 0xFFFFFFFD;
	return 0;
}

//----- (00452510) --------------------------------------------------------
int __cdecl sub_452510(int a3) {
	int v1;              // eax
	int v2;              // eax
	unsigned __int64 v3; // rax

	if (!*(_DWORD*)&byte_587000[126996])
		*(_DWORD*)(a3 + 28) = 4;
	while (1) {
		v1 = *(_DWORD*)(a3 + 28);
		if (!v1)
			break;
		v2 = v1 - 2;
		if (v2) {
			LODWORD(v3) = v2 - 2;
			if (!(_DWORD)v3)
				LODWORD(v3) = sub_4523D0((_DWORD*)a3);
			return v3;
		}
		v3 = sub_416BB0();
		if (v3 <= *(_QWORD*)(a3 + 288))
			return v3;
		*(_DWORD*)(a3 + 28) = *(_DWORD*)(a3 + 32);
	}
	LODWORD(v3) = sub_452580((_DWORD*)a3);
	if (!(_DWORD)v3)
		LODWORD(v3) = sub_4523D0((_DWORD*)a3);
	return v3;
}

//----- (00452690) --------------------------------------------------------
__int64 __cdecl sub_452690(int a3, __int64 a4, int a5) {
	__int64 result; // rax

	*(_DWORD*)(a3 + 32) = a5;
	result = a4 + sub_416BB0();
	*(_QWORD*)(a3 + 288) = result;
	*(_DWORD*)(a3 + 28) = 2;
	return result;
}

//----- (004526D0) --------------------------------------------------------
int __cdecl sub_4526D0(int a1) {
	*(_DWORD*)(*(_DWORD*)(a1 + 152) + 28) = 4;
	return 0;
}

//----- (004526F0) --------------------------------------------------------
int __cdecl sub_4526F0(int a1) {
	_DWORD* v1; // esi
	int v2;     // eax

	v1 = *(_DWORD**)(a1 + 152);
	v1[6] &= 0xFFFFFFFD;
	v2 = 4;
	if (v1[7] != 4) {
		if (v1[74] || v1[142])
			v2 = 1;
		else
			v1[71] = 0;
		if (v1[71]) {
			sub_452690((int)v1, (unsigned int)v1[71], v2);
			v1[71] = 0;
			return 0;
		}
		v1[7] = v2;
	}
	return 0;
}

//----- (00452810) --------------------------------------------------------
int* __cdecl sub_452810(int a1, char a2) {
	int* v2; // esi
	int* v3; // eax

	v2 = 0;
	if (*(_DWORD*)&byte_5D4594[1045428]) {
		v3 = sub_487810(*(int*)&byte_5D4594[1045428], 1);
		v2 = v3;
		if (v3) {
			if (v3[31] & 0x15 && v3[30] > a1)
				return 0;
			sub_4BDA80((int)v3);
			v2[29] = dword_587000_127004;
			v2[30] = a1;
			if (a2 & 1)
				v2[32] = -1;
			else
				v2[32] = 0;
			sub_486320(v2 + 4, 0x4000);
		}
	}
	return v2;
}

//----- (00452890) --------------------------------------------------------
BOOL __cdecl sub_452890(int a1, void* a2) {
	int v2;               // esi
	unsigned __int8* v3;  // eax
	int v4;               // eax
	char* v5;             // ebx
	char* v6;             // eax
	char v7;              // dl
	char* v8;             // eax
	int v9;               // ebp
	unsigned __int8* v10; // eax
	__int16 v11;          // ax
	int v12;              // ecx
	int* v13;             // eax
	int v14;              // ecx
	__int16 v15;          // cx
	__int16 v16;          // cx
	int v17;              // edx
	char* v18;            // eax
	char v19;             // cl
	BOOL result;          // eax
	int v21;              // [esp-4h] [ebp-30h]
	_WORD* v22;           // [esp+10h] [ebp-1Ch]
	unsigned __int8 v23;  // [esp+18h] [ebp-14h]
	unsigned __int8 v24;  // [esp+1Ch] [ebp-10h]
	unsigned __int8 v25;  // [esp+20h] [ebp-Ch]
	unsigned __int8 v26;  // [esp+24h] [ebp-8h]
	unsigned __int8 v27;  // [esp+28h] [ebp-4h]
	unsigned __int8 v28;  // [esp+30h] [ebp+4h]
	unsigned __int8 v29;  // [esp+30h] [ebp+4h]

	v2 = a1;
	v3 = *(unsigned __int8**)(a1 + 8);
	v21 = a1;
	v28 = *v3;
	*(_DWORD*)(v21 + 8) = v3 + 1;
	nox_memfile_read(a2, 1u, v28, v21);
	*((_BYTE*)a2 + v28) = 0;
	v4 = sub_40AF50(a2);
	if (v4 && (v5 = sub_452270(v4)) != 0) {
		while (1) {
			v6 = *(char**)(v2 + 8);
			v7 = *v6;
			v8 = v6 + 1;
			*(_DWORD*)(v2 + 8) = v8;
			switch (v7) {
			case 0:
				*(_DWORD*)v5 = 1;
				result = v7 == 0;
				break;
			case 1:
				v23 = *v8;
				*(_DWORD*)(v2 + 8) = v8 + 1;
				*((_DWORD*)v5 + 12) = v23;
				continue;
			case 2:
				v26 = *v8;
				*(_DWORD*)(v2 + 8) = v8 + 1;
				*((_DWORD*)v5 + 1) = v26;
				continue;
			case 3:
				v27 = *v8;
				*(_DWORD*)(v2 + 8) = v8 + 1;
				sub_4862E0((int)(v5 + 16), 163 * v27);
				continue;
			case 4:
				v24 = *v8;
				*(_DWORD*)(v2 + 8) = v8 + 1;
				*((_DWORD*)v5 + 14) = v24;
				continue;
			case 5:
				v25 = *v8;
				*(_DWORD*)(v2 + 8) = v8 + 1;
				*((_DWORD*)v5 + 15) = v25;
				continue;
			case 6:
				v17 = *v8;
				*(_DWORD*)(v2 + 8) = v8 + 1;
				*((_DWORD*)v5 + 19) = v17;
				v18 = *(char**)(v2 + 8);
				v19 = *v18;
				*(_DWORD*)(v2 + 8) = v18 + 1;
				*((_DWORD*)v5 + 20) = v19;
				continue;
			case 7:
				v9 = 0;
				v22 = v5 + 128;
				while (1) {
					v10 = *(unsigned __int8**)(v2 + 8);
					v29 = *v10;
					*(_DWORD*)(v2 + 8) = v10 + 1;
					if (!v29)
						break;
					nox_memfile_read(a2, 1u, v29, v2);
					*((_BYTE*)a2 + v29) = 0;
					if (v9 < 32) {
						v11 = sub_486A10(*(int*)&byte_5D4594[1045420], a2);
						*v22 = v11;
						if (v11 != -1) {
							++v9;
							++v22;
						}
					}
				}
				*((_DWORD*)v5 + 48) = v9;
				continue;
			case 8:
				v12 = *(_DWORD*)v8;
				*(_DWORD*)(v2 + 8) = v8 + 4;
				*((_DWORD*)v5 + 17) = v12;
				v13 = *(int**)(v2 + 8);
				v14 = *v13;
				*(_DWORD*)(v2 + 8) = v13 + 1;
				*((_DWORD*)v5 + 18) = v14;
				continue;
			case 9:
				v15 = *(_WORD*)v8;
				*(_DWORD*)(v2 + 8) = v8 + 2;
				if (v15 > 0)
					*((_DWORD*)v5 + 16) = 15 * v15;
				continue;
			case 0xA:
				v16 = *(_WORD*)v8;
				*(_DWORD*)(v2 + 8) = v8 + 2;
				*((_DWORD*)v5 + 2) = v16;
				continue;
			default:
				result = 0;
				break;
			}
			break;
		}
	} else {
		sub_452B30(v2);
		result = 1;
	}
	return result;
}

//----- (00452B00) --------------------------------------------------------
BOOL __cdecl sub_452B00(int a1) {
	*(_DWORD*)(a1 + 8) += **(unsigned __int8**)(a1 + 8) + 1;
	return sub_452B30(a1);
}

//----- (00452B30) --------------------------------------------------------
BOOL __cdecl sub_452B30(int a1) {
	int v1;              // eax
	char* v2;            // ecx
	char v3;             // bl
	unsigned __int8* v4; // ecx
	unsigned __int8 v5;  // dl
	int v6;              // ecx
	BOOL result;         // eax
	char v8;             // [esp+Ch] [ebp+4h]

	v1 = a1;
	while (1) {
		v2 = *(char**)(v1 + 8);
		v3 = *v2;
		v8 = *v2;
		*(_DWORD*)(v1 + 8) = v2 + 1;
		switch (v8) {
		case 0:
			result = v3 == 0;
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			*(_DWORD*)(v1 + 8) = v2 + 2;
			continue;
		case 6:
		case 9:
		case 0xA:
			*(_DWORD*)(v1 + 8) = v2 + 3;
			continue;
		case 7:
			while (1) {
				v4 = *(unsigned __int8**)(v1 + 8);
				v5 = *v4;
				v6 = (int)(v4 + 1);
				*(_DWORD*)(v1 + 8) = v6;
				if (!v5)
					break;
				*(_DWORD*)(v1 + 8) = v6 + v5;
			}
			continue;
		case 8:
			*(_DWORD*)(v1 + 8) = v2 + 9;
			continue;
		default:
			result = 0;
			break;
		}
		break;
	}
	return result;
}

//----- (00452BD0) --------------------------------------------------------
int __cdecl sub_452BD0(int a1, char* a2) {
	int v2;               // esi
	char* v3;             // ebx
	char* v4;             // eax
	int v5;               // edi
	int v6;               // eax
	char* v7;             // edi
	__int16* v8;          // eax
	__int16 v9;           // cx
	unsigned __int8* v10; // eax
	__int16* v11;         // eax
	__int16 v12;          // cx
	char* v13;            // eax
	char v14;             // cl
	char* v15;            // eax
	char v16;             // cl
	char* v17;            // eax
	int v18;              // edx
	char* v19;            // eax
	char v20;             // cl
	int result;           // eax
	char* v22;            // ecx
	char v23;             // al
	int v24;              // ebp
	char* v25;            // eax
	__int16 v26;          // ax
	char* v27;            // eax
	char v28;             // cl
	int v29;              // eax
	unsigned __int8 v30;  // [esp+10h] [ebp+4h]
	_WORD* v31;           // [esp+10h] [ebp+4h]
	char* v32;            // [esp+14h] [ebp+8h]

	v2 = a1;
	v3 = a2;
	v4 = *(char**)(a1 + 8);
	v5 = *v4;
	*(_DWORD*)(a1 + 8) = v4 + 1;
	nox_memfile_read(a2, 1u, v5, a1);
	a2[v5] = 0;
	v6 = sub_40AF50(a2);
	if (v6 && (v7 = sub_452270(v6)) != 0) {
		v8 = *(__int16**)(a1 + 8);
		v9 = *v8;
		*(_DWORD*)(a1 + 8) = v8 + 1;
		*((_DWORD*)v7 + 1) = 2;
		*((_DWORD*)v7 + 2) = v9;
		v10 = *(unsigned __int8**)(a1 + 8);
		v30 = *v10;
		*(_DWORD*)(v2 + 8) = v10 + 1;
		sub_4862E0((int)(v7 + 16), 163 * v30);
		v11 = *(__int16**)(v2 + 8);
		v12 = *v11;
		*(_DWORD*)(v2 + 8) = v11 + 1;
		if (v12 > 0)
			*((_DWORD*)v7 + 16) = 15 * v12;
		v13 = *(char**)(v2 + 8);
		v14 = *v13;
		*(_DWORD*)(v2 + 8) = v13 + 1;
		*((_DWORD*)v7 + 14) = v14;
		v15 = *(char**)(v2 + 8);
		v16 = *v15;
		*(_DWORD*)(v2 + 8) = v15 + 1;
		*((_DWORD*)v7 + 19) = v16;
		v17 = *(char**)(v2 + 8);
		v18 = *v17;
		*(_DWORD*)(v2 + 8) = v17 + 1;
		*((_DWORD*)v7 + 20) = v18;
		v19 = *(char**)(v2 + 8);
		v20 = *v19;
		*(_DWORD*)(v2 + 8) = v19 + 1;
		*((_DWORD*)v7 + 12) = v20;
		if (v20 < 3) {
			v32 = 0;
			v31 = v7 + 128;
			while (1) {
				v22 = *(char**)(v2 + 8);
				v23 = *v22;
				*(_DWORD*)(v2 + 8) = v22 + 1;
				if (!v23)
					break;
				v24 = v23;
				nox_memfile_read(v3, 1u, v23, v2);
				v3[v24] = 0;
				v25 = strrchr(v3, 46);
				if (v25)
					*v25 = 0;
				v26 = sub_486A10(*(int*)&byte_5D4594[1045420], v3);
				*v31 = v26;
				if (v26 != -1) {
					++v32;
					++v31;
				}
			}
			*(_DWORD*)v7 = 1;
			*((_DWORD*)v7 + 48) = v32;
			result = 1;
		} else {
			result = 0;
		}
	} else {
		for (*(_DWORD*)(a1 + 8) += 9;; *(_DWORD*)(a1 + 8) = v29 + v28) {
			v27 = *(char**)(a1 + 8);
			v28 = *v27;
			v29 = (int)(v27 + 1);
			*(_DWORD*)(a1 + 8) = v29;
			if (!v28)
				break;
		}
		result = 1;
	}
	return result;
}

//----- (00452D80) --------------------------------------------------------
_DWORD* __cdecl sub_452D80(int a1, int a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // esi

	result = sub_452270(a1);
	if (result) {
		result = sub_452300(result);
		v3 = result;
		if (result) {
			sub_452EE0((int)result, a2);
			result = (_DWORD*)sub_452510((int)v3);
		}
	}
	return result;
}

//----- (00452DC0) --------------------------------------------------------
_DWORD* __cdecl sub_452DC0(int a1, int a2, int a3) {
	_DWORD* result; // eax
	_DWORD* v4;     // esi

	result = sub_452270(a1);
	if (result) {
		result = sub_452300(result);
		v4 = result;
		if (result) {
			sub_452EE0((int)result, a2);
			sub_452F80((int)v4, a3);
			result = (_DWORD*)sub_452510((int)v4);
		}
	}
	return result;
}

//----- (00452E10) --------------------------------------------------------
_DWORD* __cdecl sub_452E10(int a1, int a2, int a3) {
	_DWORD* result; // eax
	_DWORD* v4;     // esi

	result = sub_452270(a1);
	if (result) {
		result = sub_452300(result);
		v4 = result;
		if (result) {
			sub_452EE0((int)result, a2);
			sub_452F80((int)v4, a3);
			v4[75] = 2;
			result = (_DWORD*)sub_452510((int)v4);
		}
	}
	return result;
}

//----- (00452E60) --------------------------------------------------------
_DWORD* __cdecl sub_452E60(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 = 0;
	a1[1] = 0;
	return result;
}

//----- (00452E80) --------------------------------------------------------
_DWORD* __cdecl sub_452E80(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 = 0;
	return result;
}

//----- (00452E90) --------------------------------------------------------
int __cdecl sub_452E90(_DWORD* a1, int a2) {
	int result; // eax

	result = a2;
	*a1 = a2;
	if (a2) {
		a1[1] = *(_DWORD*)(a2 + 280);
		result = *(_DWORD*)(a2 + 36);
		a1[2] = result;
	}
	return result;
}

//----- (00452EB0) --------------------------------------------------------
int __cdecl sub_452EB0(int* a1) {
	int result; // eax

	result = *a1;
	if (*a1 && (a1[2] != *(_DWORD*)(result + 36) || a1[1] != *(_DWORD*)(result + 280))) {
		result = 0;
		*a1 = 0;
	}
	return result;
}

//----- (00452EE0) --------------------------------------------------------
int __cdecl sub_452EE0(int a1, int a2) {
	int v2; // eax

	v2 = sub_452F10(a1, a2);
	sub_486320((_DWORD*)(a1 + 184), v2);
	return sub_4863B0((unsigned int*)(a1 + 184));
}

//----- (00452F10) --------------------------------------------------------
unsigned int __cdecl sub_452F10(int a1, int a2) {
	int v2; // ecx

	v2 = a2;
	if (a2 <= 100) {
		if (a2 < 0)
			v2 = 0;
	} else {
		v2 = 100;
	}
	return (unsigned int)(163 * v2 * (*(_DWORD*)(*(_DWORD*)(a1 + 36) + 20) >> 16)) >> 14;
}

//----- (00452F50) --------------------------------------------------------
int __cdecl sub_452F50(int a1, int a2) {
	int v2; // eax

	v2 = sub_452F10(a1, a2);
	return sub_486350(a1 + 184, v2);
}

//----- (00452F80) --------------------------------------------------------
_DWORD* __cdecl sub_452F80(int a1, int a2) {
	int v2; // eax

	v2 = sub_452FA0(a2);
	return sub_486320((_DWORD*)(a1 + 248), v2);
}

//----- (00452FA0) --------------------------------------------------------
int __cdecl sub_452FA0(int a1) {
	int v1; // eax

	v1 = a1;
	if (a1 <= 50) {
		if (a1 < -50)
			v1 = -50;
	} else {
		v1 = 50;
	}
	return (v1 * 8192) / 50 + 8192;
}

//----- (00452FE0) --------------------------------------------------------
int __cdecl sub_452FE0(int a1, int a2) {
	int v2; // eax

	v2 = sub_452FA0(a2);
	return sub_486350(a1 + 248, v2);
}

//----- (00453000) --------------------------------------------------------
int __cdecl sub_453000(_DWORD* a1, unsigned int a2, int a3) {
	sub_486380(a1 + 46, a2, a3, 0x4000);
	sub_486380(a1 + 54, a2, a3, 0x4000);
	return sub_486380(a1 + 62, a2, a3, 0x4000);
}

//----- (00453050) --------------------------------------------------------
void sub_453050() { *(_DWORD*)&byte_587000[126996] = 0; }

//----- (00453060) --------------------------------------------------------
void sub_453060() { *(_DWORD*)&byte_587000[126996] = 1; }

//----- (00453070) --------------------------------------------------------
int sub_453070() { return *(_DWORD*)&byte_587000[126996]; }

//----- (00453080) --------------------------------------------------------
BOOL __cdecl sub_453080(char a1) {
	BOOL result; // eax

	if (dword_5d4594_1045460)
		result = sub_453690(1 << a1);
	else
		result = sub_453660(1 << a1);
	return result;
}

//----- (004532E0) --------------------------------------------------------
_DWORD* sub_4532E0() {
	int v0;         // esi
	int v1;         // edi
	int v2;         // ebx
	_DWORD* result; // eax

	v0 = sub_43F320(*(_DWORD*)(dword_5d4594_1045464 + 236)) + 1;
	sub_46AB20(*(_DWORD**)&dword_5d4594_1045464, *(_DWORD*)(dword_5d4594_1045464 + 8), 15 * v0 + 2);
	v1 = 1520;
	v2 = *(_DWORD*)(dword_5d4594_1045464 + 20) + v0 + 2;
	do {
		result = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045468, v1);
		result[5] = v2;
		v2 += v0;
		++v1;
	} while (v1 < 1534);
	return result;
}

//----- (00453350) --------------------------------------------------------
int __cdecl sub_453350(int a1, int a2) {
	int result; // eax
	int xLeft;  // [esp+4h] [ebp-8h]
	int yTop;   // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if ((signed char)*(_BYTE*)(a1 + 4) >= 0) {
		if (*(_DWORD*)(a2 + 20) != 0x80000000)
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
		result = 1;
	} else {
		nox_client_drawImageAt_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
		result = 1;
	}
	return result;
}

//----- (004533D0) --------------------------------------------------------
int __cdecl sub_4533D0(int a1, int a2, int a3, int a4) {
	int v3;       // esi
	int v5;       // eax
	int v6;       // eax
	int v7;       // edx
	int v8;       // ecx
	int v9;       // edx
	int v10;      // ecx
	wchar_t* v11; // [esp-4h] [ebp-Ch]

	if (a2 == 0x4000) {
		if ((_DWORD*)a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_1045468, 1513) ||
		    (_DWORD*)a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_1045468, 1514)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1045464, 0x4000, a3, 0);
		LABEL_35:
			sub_453750();
		}
		return 0;
	}
	if (a2 != 16391)
		return 0;
	v3 = sub_46B0A0((int*)a3);
	switch (v3) {
	case 1513:
	case 1514:
		nox_window_call_field_94(*(int*)&dword_5d4594_1045464, 0x4000, a3, 0);
		goto LABEL_35;
	case 1515:
		if (dword_5d4594_1045460)
			*(_DWORD*)&byte_5D4594[1045456] = -1;
		else
			*(_DWORD*)&byte_5D4594[1045452] = -1;
		goto LABEL_6;
	case 1516:
		if (dword_5d4594_1045460)
			*(_DWORD*)&byte_5D4594[1045456] = 0;
		else
			*(_DWORD*)&byte_5D4594[1045452] = 0;
	LABEL_6:
		sub_453750();
		goto LABEL_7;
	case 1520:
	case 1521:
	case 1522:
	case 1523:
	case 1524:
	case 1525:
	case 1526:
	case 1527:
	case 1528:
	case 1529:
	case 1530:
	case 1531:
	case 1532:
	case 1533:
		v5 = sub_4A4800(*(_DWORD*)(dword_5d4594_1045464 + 32));
		v11 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1045464, 16406, v5 + v3 - 1520, 0);
		if (dword_5d4594_1045460)
			v6 = sub_415DA0(v11);
		else
			v6 = sub_415960(v11);
		if (*(_BYTE*)(a3 + 36) & 4) {
			if (dword_5d4594_1045460) {
				sub_453640(&byte_5D4594[1045456], v6, 0);
			} else {
				v7 = 0;
				if (v6 > 0) {
					do {
						v8 = v6 >> 8;
						if (v6 >> 8 > 0)
							v6 >>= 8;
						++v7;
					} while (v8 > 0);
				}
				sub_453620(&byte_5D4594[v7 + 1045451], v6, 0);
			}
		} else if (dword_5d4594_1045460) {
			sub_453640(&byte_5D4594[1045456], v6, 1);
		} else {
			v9 = 0;
			if (v6 > 0) {
				do {
					v10 = v6 >> 8;
					if (v6 >> 8 > 0)
						v6 >>= 8;
					++v9;
				} while (v10 > 0);
			}
			sub_453620(&byte_5D4594[v9 + 1045451], v6, 1);
		}
	LABEL_7:
		sub_459D50(1);
		break;
	default:
		break;
	}
	sub_452D80(766, 100);
	return 0;
}

//----- (004535E0) --------------------------------------------------------
int* __cdecl sub_4535E0(int* a1) {
	int* result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1045452] = *a1;
	return result;
}

//----- (004535F0) --------------------------------------------------------
int __cdecl sub_4535F0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1045456] = a1;
	return result;
}

//----- (00453600) --------------------------------------------------------
char* sub_453600() { return (char*)&byte_5D4594[1045452]; }

//----- (00453610) --------------------------------------------------------
int sub_453610() { return *(_DWORD*)&byte_5D4594[1045456]; }

//----- (00453620) --------------------------------------------------------
_BYTE* __cdecl sub_453620(_BYTE* a1, char a2, int a3) {
	_BYTE* result; // eax

	result = a1;
	if (a3)
		*a1 |= a2;
	else
		*a1 &= ~a2;
	return result;
}

//----- (00453640) --------------------------------------------------------
_DWORD* __cdecl sub_453640(_DWORD* a1, int a2, int a3) {
	_DWORD* result; // eax

	result = a1;
	if (a3)
		*a1 |= a2;
	else
		*a1 &= ~a2;
	return result;
}

//----- (00453660) --------------------------------------------------------
BOOL __cdecl sub_453660(int a1) {
	int v1; // ecx
	int v2; // edx
	int v3; // eax

	v1 = a1;
	v2 = 0;
	if (a1 > 0) {
		do {
			v3 = v1 >> 8;
			if (v1 >> 8 > 0)
				v1 >>= 8;
			++v2;
		} while (v3 > 0);
	}
	return ((unsigned __int8)v1 & byte_5D4594[v2 + 1045451]) != 0;
}

//----- (00453690) --------------------------------------------------------
BOOL __cdecl sub_453690(int a1) { return (a1 & *(_DWORD*)&byte_5D4594[1045456]) != 0; }

//----- (004536B0) --------------------------------------------------------
int __cdecl sub_4536B0(_DWORD* a1) {
	int v1;     // ebx
	int v2;     // edi
	_DWORD* v3; // esi
	int v4;     // ebp
	int result; // eax

	v1 = 1;
	*a1 = -1;
	v2 = 1;
	v3 = a1;
	v4 = 27;
	do {
		result = sub_415840((char*)v2);
		if (result) {
			result = sub_4E3BA0(result);
			if (!result) {
				result = (unsigned __int8)~(_BYTE)v1;
				*(_BYTE*)v3 &= ~(_BYTE)v1;
			}
		}
		if (v1 == 128) {
			v1 = 1;
			v3 = (_DWORD*)((char*)v3 + 1);
		} else {
			v1 *= 2;
		}
		v2 *= 2;
		--v4;
	} while (v4);
	return result;
}

//----- (00453710) --------------------------------------------------------
int sub_453710() {
	int v0; // edi
	int v1; // esi
	int v2; // ebx
	int v3; // eax

	v0 = -1;
	v1 = 1;
	v2 = 26;
	do {
		v3 = sub_415CD0((char*)v1);
		if (v3 && !sub_4E3BA0(v3))
			v0 &= ~v1;
		v1 *= 2;
		--v2;
	} while (v2);
	return v0;
}

//----- (00453750) --------------------------------------------------------
char sub_453750() {
	int v0;    // esi
	int i;     // ebx
	_DWORD* j; // edi
	bool v3;   // zf
	int v4;    // eax

	v0 = sub_4A4800(*(_DWORD*)(dword_5d4594_1045464 + 32));
	for (i = 1520; i <= 1533; ++i) {
		for (j = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045468, i); (1 << v0) & 0x33; ++v0)
			;
		if (v0 >= *(int*)&byte_5D4594[4 * dword_5d4594_1045460 + 1045472]) {
			LOBYTE(v4) = nox_window_set_hidden((int)j, 1);
		} else {
			nox_window_set_hidden((int)j, 0);
			v3 = !sub_453080(v0);
			v4 = j[9];
			if (v3)
				LOBYTE(v4) = v4 & 0xFB;
			else
				LOBYTE(v4) = v4 | 4;
			j[9] = v4;
		}
		++v0;
	}
	return v4;
}

//----- (004537F0) --------------------------------------------------------
int sub_4537F0() {
	int v0;     // esi
	int v1;     // edi
	int v2;     // eax
	int v3;     // eax
	int v4;     // esi
	int v5;     // edi
	int result; // eax
	int v7;     // eax

	v0 = 1;
	v1 = 26;
	do {
		v2 = sub_415CD0((char*)v0);
		if (v2) {
			v3 = sub_4E3B70(v2);
			sub_4E3BF0(v3);
		}
		v0 *= 2;
		--v1;
	} while (v1);
	v4 = 1;
	v5 = 27;
	do {
		result = sub_415840((char*)v4);
		if (result) {
			v7 = sub_4E3B70(result);
			result = sub_4E3BF0(v7);
		}
		v4 *= 2;
		--v5;
	} while (v5);
	return result;
}

//----- (00453B00) --------------------------------------------------------
_DWORD* sub_453B00() {
	int v0;         // esi
	int v1;         // edi
	int v2;         // ebx
	_DWORD* result; // eax

	v0 = sub_43F320(*(_DWORD*)(dword_5d4594_1045480 + 236)) + 1;
	sub_46AB20(*(_DWORD**)&dword_5d4594_1045480, *(_DWORD*)(dword_5d4594_1045480 + 8), 15 * v0 + 2);
	sub_46AB20(*(_DWORD**)&dword_5d4594_1045508, *(_DWORD*)(dword_5d4594_1045508 + 8), 15 * v0 + 2);
	v1 = 1120;
	v2 = *(_DWORD*)(dword_5d4594_1045480 + 20) + v0 + 2;
	do {
		result = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, v1);
		result[5] = v2;
		v2 += v0;
		++v1;
	} while (v1 < 1134);
	return result;
}

//----- (00453B80) --------------------------------------------------------
int __cdecl sub_453B80(int a1, int a2) {
	int result; // eax
	int xLeft;  // [esp+4h] [ebp-8h]
	int yTop;   // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if ((signed char)*(_BYTE*)(a1 + 4) >= 0) {
		if (*(_DWORD*)(a2 + 20) != 0x80000000)
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
		result = 1;
	} else {
		nox_client_drawImageAt_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
		result = 1;
	}
	return result;
}

//----- (00453F70) --------------------------------------------------------
void __cdecl sub_453F70(const void* a1) { qmemcpy(&byte_5D4594[1045488], a1, 0x14u); }

//----- (00453F90) --------------------------------------------------------
char* sub_453F90() { return (char*)&byte_5D4594[1045488]; }

//----- (00453FA0) --------------------------------------------------------
int __cdecl sub_453FA0(int a1, int a2, int a3) {
	bool v3;            // sf
	char v4;            // cl
	int result;         // eax
	unsigned __int8 v6; // [esp+8h] [ebp+8h]

	v4 = a2 & 0x1F;
	v3 = (a2 & 0x8000001F & 0x80000000) != 0;
	v6 = a2 / 32;
	if (v3)
		v4 = ((v4 - 1) | 0xE0) + 1;
	result = 1 << v4;
	if (a3) {
		*(_DWORD*)(a1 + 4 * v6) |= result;
	} else {
		result = ~result;
		*(_DWORD*)(a1 + 4 * v6) &= result;
	}
	return result;
}

//----- (00454000) --------------------------------------------------------
BOOL __cdecl sub_454000(int a1, int a2) { return (*(_DWORD*)(a1 + 4 * ((a2 / 32) & 0xFF)) & (1 << (a2 % 32))) != 0; }

//----- (00454040) --------------------------------------------------------
int __cdecl sub_454040(_DWORD* a1) {
	int v1;             // esi
	int v2;             // edi
	int result;         // eax
	unsigned __int8 v4; // [esp+Ch] [ebp-4h]

	v1 = 1;
	*a1 = -1;
	v4 = 0;
	v2 = 1;
	a1[1] = -1;
	a1[2] = -1;
	a1[3] = -1;
	a1[4] = -1;
	do {
		if (v1 == 0x80000000) {
			v1 = 1;
			++v4;
		} else {
			v1 *= 2;
		}
		result = sub_424B50(v2);
		if (result) {
			result = sub_424A70(v2);
			if (result & 0x7000000) {
				result = sub_424B70(v2);
				if (!result) {
					result = (int)&a1[v4];
					*(_DWORD*)result = ~v1 & a1[v4];
				}
			}
		}
		++v2;
	} while (v2 < 137);
	return result;
}

//----- (004540E0) --------------------------------------------------------
int __cdecl sub_4540E0(int a1) {
	int v1;     // esi
	int result; // eax

	v1 = 1;
	do {
		if (sub_454000(a1, v1))
			result = sub_424B90(v1);
		else
			result = sub_424BB0(v1);
		++v1;
	} while (v1 < 137);
	return result;
}

//----- (00454120) --------------------------------------------------------
char sub_454120() {
	int v0;     // ebp
	int v1;     // ebx
	_DWORD* v2; // esi
	int v3;     // edi
	int v4;     // ecx
	bool v5;    // zf
	int v6;     // eax
	int v8;     // [esp+10h] [ebp-4h]

	v8 = *(_DWORD*)(dword_5d4594_1045480 + 32);
	v0 = 1120;
	v1 = 524 * sub_4A4800(v8);
	do {
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045484, v0);
		v3 = 0;
		v4 = *(_DWORD*)(v8 + 24);
		if (v4 + v1 != -4 && *(_WORD*)(v4 + v1 + 4)) {
			v3 = sub_424960((wchar_t*)(v4 + v1 + 4));
			nox_window_set_hidden((int)v2, 0);
		} else {
			nox_window_set_hidden((int)v2, 1);
		}
		v1 += 524;
		if (v3) {
			v5 = !sub_454000((int)&byte_5D4594[1045488], v3);
			v6 = v2[9];
			if (!v5) {
				LOBYTE(v6) = v6 | 4;
				goto LABEL_11;
			}
		} else {
			v6 = v2[9];
		}
		LOBYTE(v6) = v6 & 0xFB;
	LABEL_11:
		++v0;
		v2[9] = v6;
	} while (v0 <= 1133);
	return v6;
}

//----- (004541D0) --------------------------------------------------------
int __cdecl sub_4541D0(int a1) {
	int v2;      // esi
	_DWORD* v3;  // ebx
	char* v4;    // ebp
	char* v5;    // esi
	_DWORD* v6;  // edi
	_DWORD* v7;  // ebx
	_DWORD* v8;  // edi
	_DWORD* v9;  // ebx
	_DWORD* v10; // edi
	_DWORD* v11; // eax
	_DWORD* v12; // [esp+0h] [ebp-4h]
	_DWORD* v13; // [esp+0h] [ebp-4h]
	int v14;     // [esp+0h] [ebp-4h]
	_DWORD* v15; // [esp+8h] [ebp+4h]
	_DWORD* v16; // [esp+8h] [ebp+4h]
	_DWORD* v17; // [esp+8h] [ebp+4h]

	if (dword_5d4594_1045516)
		return 0;
	v2 = dword_587000_26048;
	if (sub_43F320(0) > 10)
		v2 = 2;
	dword_5d4594_1045516 =
	    nox_new_window_from_file(*(const char**)&byte_587000[4 * v2 + 127824], sub_454BA0);
	sub_43FE20(100);
	sub_416640();
	sub_46B120(*(_DWORD**)&dword_5d4594_1045516, a1);
	*(_DWORD*)&byte_5D4594[1045520] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10102);
	*(_DWORD*)&byte_5D4594[1045524] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10103);
	dword_5d4594_1045532 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10109);
	dword_5d4594_1045528 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10105);
	dword_5d4594_1045536 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10200);
	*(_DWORD*)&byte_5D4594[1045540] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10111);
	*(_DWORD*)&byte_5D4594[1045544] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10112);
	*(_DWORD*)&byte_5D4594[1045548] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10113);
	*(_DWORD*)&byte_5D4594[1045556] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10104);
	*(_DWORD*)&byte_5D4594[1045560] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10125);
	*(_DWORD*)&byte_5D4594[1045564] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10127);
	*(_DWORD*)&byte_5D4594[1045568] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10129);
	*(_DWORD*)&byte_5D4594[1045572] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10131);
	*(_DWORD*)&byte_5D4594[1045576] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10126);
	*(_DWORD*)&byte_5D4594[1045580] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10128);
	*(_DWORD*)&byte_5D4594[1045584] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10130);
	*(_DWORD*)&byte_5D4594[1045588] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10132);
	*(_DWORD*)&byte_5D4594[1045552] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10123);
	*(_DWORD*)&byte_5D4594[1045592] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10133);
	v3 = *(_DWORD**)(dword_5d4594_1045532 + 32);
	v4 = sub_42F970("UISlider");
	v5 = sub_42F970("UISliderLit");
	v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10190);
	v15 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10188);
	v12 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10189);
	*(_DWORD*)(v6[100] + 8) = 16;
	*(_DWORD*)(v6[100] + 12) = 10;
	sub_4B5700((int)v6, 0, 0, (int)v4, (int)v5, (int)v5);
	sub_46B280((int)v6, *(int*)&dword_5d4594_1045532);
	sub_46B280((int)v15, *(int*)&dword_5d4594_1045532);
	sub_46B280((int)v12, *(int*)&dword_5d4594_1045532);
	v3[9] = v6;
	v3[7] = v15;
	v3[8] = v12;
	v7 = *(_DWORD**)(dword_5d4594_1045528 + 32);
	v8 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10187);
	v16 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10185);
	v13 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10186);
	*(_DWORD*)(v8[100] + 8) = 16;
	*(_DWORD*)(v8[100] + 12) = 10;
	sub_4B5700((int)v8, 0, 0, (int)v4, (int)v5, (int)v5);
	sub_46B280((int)v8, *(int*)&dword_5d4594_1045528);
	sub_46B280((int)v16, *(int*)&dword_5d4594_1045528);
	sub_46B280((int)v13, *(int*)&dword_5d4594_1045528);
	v7[9] = v8;
	v7[7] = v16;
	v7[8] = v13;
	v9 = *(_DWORD**)(dword_5d4594_1045536 + 32);
	v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10203);
	v17 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10201);
	v11 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10202);
	*(_DWORD*)(v10[100] + 8) = 16;
	v14 = (int)v11;
	*(_DWORD*)(v10[100] + 12) = 10;
	sub_4B5700((int)v10, 0, 0, (int)v4, (int)v5, (int)v5);
	sub_46B280((int)v10, *(int*)&dword_5d4594_1045536);
	sub_46B280((int)v17, *(int*)&dword_5d4594_1045536);
	sub_46B280(v14, *(int*)&dword_5d4594_1045536);
	v9[9] = v10;
	v9[7] = v17;
	v9[8] = v14;
	sub_454740();
	sub_454640();
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_46B340(*(int*)&dword_5d4594_1045516, sub_454A90);
	sub_46A8A0();
	return dword_5d4594_1045516;
}

//----- (00454A90) --------------------------------------------------------
int __cdecl sub_454A90(int a1, int a2) {
	_WORD* v2; // eax
	int v3;    // eax
	char v4;   // cl
	int xLeft; // [esp+8h] [ebp-8h]
	int yTop;  // [esp+Ch] [ebp-4h]

	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if ((signed char)*(_BYTE*)(a1 + 4) >= 0) {
		if (*(_DWORD*)(a2 + 20) != 0x80000000)
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
	} else {
		nox_client_drawImageAt_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
	}
	if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045540] + 4) & 8) {
		v2 = (_WORD*)nox_window_call_field_94(*(int*)&byte_5D4594[1045540], 16413, 0, 0);
		if (v2 && *v2) {
			if (!(*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045544] + 4) & 8))
				sub_46ABB0(*(int*)&byte_5D4594[1045544], 1);
		} else if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045544] + 4) & 8) {
			sub_46ABB0(*(int*)&byte_5D4594[1045544], 0);
		}
	}
	v3 = nox_window_call_field_94(*(int*)&byte_5D4594[1045596], 16404, 0, 0);
	v4 = *(_BYTE*)(*(_DWORD*)&byte_5D4594[1045548] + 4);
	if (v3 < 0) {
		if (v4 & 8)
			sub_46ABB0(*(int*)&byte_5D4594[1045548], 0);
	} else if (!(v4 & 8)) {
		sub_46ABB0(*(int*)&byte_5D4594[1045548], 1);
		return 1;
	}
	return 1;
}

//----- (00454BA0) --------------------------------------------------------
int __cdecl sub_454BA0(int a1, int a2, int* a3, int a4) {
	int v4;               // eax
	int result;           // eax
	char* v6;             // eax
	int v7;               // esi
	char* v8;             // esi
	const wchar_t* v9;    // eax
	char* v10;            // esi
	const wchar_t* v11;   // eax
	char* v12;            // esi
	const wchar_t* v13;   // eax
	char* v14;            // esi
	const wchar_t* v15;   // eax
	char* v16;            // eax
	char v17;             // dl
	_DWORD* v18;          // esi
	_DWORD* v19;          // eax
	_DWORD* v20;          // eax
	char* v21;            // esi
	wchar_t* v22;         // esi
	int v23;              // esi
	int v24;              // esi
	char* v25;            // eax
	int* v26;             // eax
	int* v27;             // ebp
	int v28;              // eax
	wchar_t* v29;         // eax
	wchar_t* v30;         // edi
	char* v31;            // eax
	char* v32;            // esi
	int* v33;             // eax
	int* v34;             // edi
	int v35;              // eax
	wchar_t* v36;         // eax
	char* v37;            // eax
	char* v38;            // esi
	char* v39;            // ebp
	const wchar_t* v40;   // eax
	wchar_t* v41;         // esi
	int v42;              // ebx
	int v43;              // ebp
	_DWORD* v44;          // esi
	const wchar_t* v45;   // eax
	wchar_t* v46;         // edi
	int v47;              // ebx
	WCHAR WideCharStr[8]; // [esp+10h] [ebp-10h]
	char* v49;            // [esp+28h] [ebp+8h]
	char* v50;            // [esp+30h] [ebp+10h]
	char* v51;            // [esp+30h] [ebp+10h]

	switch (a2) {
	case 16387:
		v43 = a4;
		v44 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, a4);
		v51 = sub_416630();
		v49 = sub_416640();
		if (!v44 || (unsigned __int16)a3 == 1)
			goto LABEL_101;
		v45 = (const wchar_t*)nox_window_call_field_94((int)v44, 16413, 0, 0);
		v46 = (wchar_t*)v45;
		if (!v45 || !*v45 || (v47 = nox_wcstol(v45, 0, 10), v47 < 0))
			v47 = 0;
		switch (v43) {
		case 10104:
			nox_wcscpy((wchar_t*)v49 + 39, v46);
			goto LABEL_101;
		case 10126:
			if (v47 > 14) {
				LOBYTE(v47) = 14;
				_itow(14, WideCharStr, 10);
				nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
			}
			v51[1] = v47 | v51[1] & 0xF0;
			result = 0;
			break;
		case 10128:
			if (v47 > 14) {
				LOBYTE(v47) = 14;
				_itow(14, WideCharStr, 10);
				nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
			}
			v51[1] = (16 * v47) | v51[1] & 0xF;
			result = 0;
			break;
		case 10130:
			*(_WORD*)(v51 + 5) = v47;
			result = 0;
			break;
		case 10132:
			*(_WORD*)(v51 + 7) = v47;
			result = 0;
			break;
		case 10133:
			if (v47 <= 32) {
				if (v47 < 1) {
					v47 = 1;
					_itow(1, WideCharStr, 10);
					nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
				}
			} else {
				v47 = 32;
				_itow(32, WideCharStr, 10);
				nox_window_call_field_94((int)v44, 16414, (int)WideCharStr, -1);
			}
			sub_409F80(v47);
			result = 0;
			v51[4] = v47;
			break;
		case 10136:
			sub_40A610(v46);
			result = 0;
			break;
		default:
			goto LABEL_101;
		}
		break;
	case 16391:
		v7 = sub_46B0A0(a3);
		sub_452D80(766, 100);
		switch (v7) {
		case 10102:
			v16 = sub_416630();
			v17 = *v16 ^ 0x10;
			*v16 = v17;
			if (v17 & 0x10) {
				v20 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10206);
				sub_46ABB0((int)v20, 1);
			} else {
				v18 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10206);
				sub_46ABB0((int)v18, 0);
				v18[9] &= 0xFFFFFFFB;
				v19 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10207);
				v19[9] |= 4u;
				nox_window_set_hidden(*(int*)&dword_5d4594_1045532, 1);
				sub_46ACE0(*(_DWORD**)&dword_5d4594_1045516, 10188, 10190, 1);
				nox_window_set_hidden(*(int*)&dword_5d4594_1045528, 0);
				sub_46ACE0(*(_DWORD**)&dword_5d4594_1045516, 10185, 10187, 0);
			}
			return 0;
		case 10103:
			v21 = sub_416630();
			sub_46ABB0(*(int*)&byte_5D4594[1045556],
				   ((unsigned int)~*(_DWORD*)(*(_DWORD*)&byte_5D4594[1045524] + 36) >> 2) & 1);
			*v21 ^= 0x20u;
			return 0;
		case 10112:
			v22 = (wchar_t*)nox_window_call_field_94(*(int*)&byte_5D4594[1045540], 16413, 0, 0);
			if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1045528))
				sub_4168A0(v22);
			else
				sub_416770(0, v22, 0);
			nox_window_call_field_94(*(int*)&byte_5D4594[1045540], 16414, (int)&byte_5D4594[1045600], 0);
			return 0;
		case 10113:
			sub_416640();
			if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045520] + 36) & 4) {
				v23 = nox_window_call_field_94(*(int*)&dword_5d4594_1045532, 16404, 0, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1045532, 16398, v23, 0);
				sub_416860(v23);
			} else {
				v24 = nox_window_call_field_94(*(int*)&dword_5d4594_1045528, 16404, 0, 0);
				nox_window_call_field_94(*(int*)&dword_5d4594_1045528, 16398, v24, 0);
				sub_416820(v24);
			}
			return 0;
		case 10124:
			v25 = sub_416630();
			v25[2] ^= 0x80u;
			return 0;
		case 10125:
			v8 = sub_416630();
			if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045560] + 36) & 4) {
				sub_46ABB0(*(int*)&byte_5D4594[1045576], 0);
				v8[1] |= 0xFu;
				return 0;
			}
			sub_46ABB0(*(int*)&byte_5D4594[1045576], 1);
			v9 = (const wchar_t*)nox_window_call_field_94(*(int*)&byte_5D4594[1045576], 16413, 0, 0);
			if (!*v9)
				goto LABEL_101;
			v8[1] = v8[1] & 0xF0 | nox_wcstol(v9, 0, 10);
			return 0;
		case 10127:
			v10 = sub_416630();
			if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045564] + 36) & 4) {
				sub_46ABB0(*(int*)&byte_5D4594[1045580], 0);
				v10[1] |= 0xF0u;
				return 0;
			}
			sub_46ABB0(*(int*)&byte_5D4594[1045580], 1);
			v11 = (const wchar_t*)nox_window_call_field_94(*(int*)&byte_5D4594[1045580], 16413, 0, 0);
			if (!*v11)
				goto LABEL_101;
			v10[1] = v10[1] & 0xF | nox_wcstol(v11, 0, 10);
			return 0;
		case 10129:
			v12 = sub_416630();
			if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045568] + 36) & 4) {
				sub_46ABB0(*(int*)&byte_5D4594[1045584], 0);
				*(_WORD*)(v12 + 5) = -1;
				return 0;
			}
			sub_46ABB0(*(int*)&byte_5D4594[1045584], 1);
			v13 = (const wchar_t*)nox_window_call_field_94(*(int*)&byte_5D4594[1045584], 16413, 0, 0);
			if (!*v13)
				goto LABEL_101;
			*(_WORD*)(v12 + 5) = nox_wcstol(v13, 0, 10);
			return 0;
		case 10131:
			v14 = sub_416630();
			if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1045572] + 36) & 4) {
				sub_46ABB0(*(int*)&byte_5D4594[1045588], 0);
				*(_WORD*)(v14 + 7) = -1;
				return 0;
			}
			sub_46ABB0(*(int*)&byte_5D4594[1045588], 1);
			v15 = (const wchar_t*)nox_window_call_field_94(*(int*)&byte_5D4594[1045588], 16413, 0, 0);
			if (!*v15)
				goto LABEL_101;
			*(_WORD*)(v14 + 7) = nox_wcstol(v15, 0, 10);
			result = 0;
			break;
		case 10191:
			v33 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16404, 0, 0);
			v34 = v33;
			v35 = *v33;
			if (v35 < 0)
				goto LABEL_101;
			do {
				v36 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16406, v35, 0);
				v37 = sub_4170D0(v36);
				v38 = v37;
				if (v37 && v37[2064] != 31) {
					if (nox_common_gameFlags_check_40A5C0(4096))
						sub_4DCFB0(*((_DWORD*)v38 + 514));
					else
						sub_4DEAB0((unsigned __int8)v38[2064], 4);
				}
				v35 = v34[1];
				++v34;
			} while (v35 >= 0);
			return 0;
		case 10192:
			v26 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16404, 0, 0);
			v27 = v26;
			v28 = *v26;
			if (v28 < 0)
				goto LABEL_101;
			do {
				v29 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16406, v28, 0);
				v30 = v29;
				v31 = sub_4170D0(v29);
				v32 = v31;
				if (v31 && v31[2064] != 31) {
					if (nox_common_gameFlags_check_40A5C0(4096))
						sub_4DCFB0(*((_DWORD*)v32 + 514));
					else
						sub_4DEB00((unsigned __int8)v32[2064]);
					sub_416770(0, v30, v32 + 2112);
				}
				v28 = v27[1];
				++v27;
			} while (v28 >= 0);
			return 0;
		case 10206:
			nox_window_set_hidden(*(int*)&dword_5d4594_1045532, 0);
			sub_46ACE0(*(_DWORD**)&dword_5d4594_1045516, 10188, 10190, 0);
			nox_window_set_hidden(*(int*)&dword_5d4594_1045528, 1);
			sub_46ACE0(*(_DWORD**)&dword_5d4594_1045516, 10185, 10187, 1);
			*(_DWORD*)&byte_5D4594[1045596] = dword_5d4594_1045532;
			return 0;
		case 10207:
			nox_window_set_hidden(*(int*)&dword_5d4594_1045532, 1);
			sub_46ACE0(*(_DWORD**)&dword_5d4594_1045516, 10188, 10190, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_1045528, 0);
			sub_46ACE0(*(_DWORD**)&dword_5d4594_1045516, 10185, 10187, 0);
			*(_DWORD*)&byte_5D4594[1045596] = dword_5d4594_1045528;
			return 0;
		default:
			goto LABEL_101;
		}
		break;
	case 16400:
		v4 = sub_46B0A0(a3) - 10123;
		if (v4) {
			if (v4 != 77)
				goto LABEL_101;
			if (sub_455770())
				sub_46AD20(*(_DWORD**)&dword_5d4594_1045516, 10191, 10192, 1);
			else
				sub_46AD20(*(_DWORD**)&dword_5d4594_1045516, 10191, 10192, 0);
			result = 0;
		} else {
			v6 = sub_416640();
			v6[100] ^= 1 << a4;
			result = 0;
		}
		break;
	case 16415:
		v39 = sub_416630();
		v50 = sub_416640();
		v40 = (const wchar_t*)nox_window_call_field_94((int)a3, 16413, 0, 0);
		v41 = (wchar_t*)v40;
		if (!v40 || !*v40 || (v42 = nox_wcstol(v40, 0, 10), v42 < 0))
			v42 = 0;
		switch (sub_46B0A0(a3)) {
		case 10104:
			nox_wcscpy((wchar_t*)v50 + 39, v41);
			goto LABEL_101;
		case 10126:
			if (v42 > 14) {
				LOBYTE(v42) = 14;
				_itow(14, WideCharStr, 10);
				nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
			}
			result = 0;
			v39[1] = v42 | v39[1] & 0xF0;
			break;
		case 10128:
			if (v42 > 14) {
				LOBYTE(v42) = 14;
				_itow(14, WideCharStr, 10);
				nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
			}
			result = 0;
			v39[1] = (16 * v42) | v39[1] & 0xF;
			break;
		case 10130:
			*(_WORD*)(v39 + 5) = v42;
			result = 0;
			break;
		case 10132:
			*(_WORD*)(v39 + 7) = v42;
			result = 0;
			break;
		case 10133:
			if (v42 <= 32) {
				if (v42 < 1) {
					v42 = 1;
					_itow(1, WideCharStr, 10);
					nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
				}
			} else {
				v42 = 32;
				_itow(32, WideCharStr, 10);
				nox_window_call_field_94((int)a3, 16414, (int)WideCharStr, -1);
			}
			sub_409F80(v42);
			v39[4] = v42;
			result = 0;
			break;
		case 10136:
			sub_40A610(v41);
			result = 0;
			break;
		default:
			goto LABEL_101;
		}
		break;
	default:
	LABEL_101:
		result = 0;
		break;
	}
	return result;
}

//----- (00455770) --------------------------------------------------------
int sub_455770() {
	int* v0;     // eax
	int* v1;     // esi
	int v2;      // eax
	wchar_t* v3; // eax
	char* v4;    // eax

	v0 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16404, 0, 0);
	v1 = v0;
	v2 = *v0;
	if (v2 < 0)
		return 0;
	while (1) {
		v3 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16406, v2, 0);
		v4 = sub_4170D0(v3);
		if (v4) {
			if (v4[2064] != 31)
				break;
		}
		v2 = v1[1];
		++v1;
		if (v2 < 0)
			return 0;
	}
	return 1;
}

//----- (004557D0) --------------------------------------------------------
int __cdecl sub_4557D0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = dword_5d4594_1045516;
		if (dword_5d4594_1045516)
			result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1045516);
	}
	dword_5d4594_1045516 = 0;
	return result;
}

//----- (00455800) --------------------------------------------------------
int* sub_455800() {
	int* result;           // eax
	int v1;                // eax
	int* i;                // esi
	int* j;                // esi
	WCHAR WideCharStr[10]; // [esp+4h] [ebp-48h]
	wchar_t v5[26];        // [esp+18h] [ebp-34h]

	result = *(int**)&dword_5d4594_1045516;
	if (dword_5d4594_1045516) {
		v1 = sub_409FA0();
		_itow(v1, WideCharStr, 10);
		nox_window_call_field_94(*(int*)&byte_5D4594[1045592], 16414, (int)WideCharStr, 0);
		result = (int*)nox_common_gameFlags_check_40A5C0(1);
		if (result) {
			sub_416640();
			nox_window_call_field_94(*(int*)&dword_5d4594_1045528, 16399, 0, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1045532, 16399, 0, 0);
			for (i = sub_4168E0(); i; i = sub_4168F0(i))
				nox_window_call_field_94(*(int*)&dword_5d4594_1045532, 16397, (int)(i + 3), -1);
			result = sub_416900();
			for (j = result; result; j = result) {
				if (*((_BYTE*)j + 72)) {
					nox_window_call_field_94(*(int*)&dword_5d4594_1045528, 16397, (int)(j + 3), -1);
				} else {
					nox_swprintf(v5, L"*%s", j + 3);
					nox_window_call_field_94(*(int*)&dword_5d4594_1045528, 16397, (int)v5, -1);
				}
				result = sub_416910(j);
			}
		}
	}
	return result;
}

//----- (00455920) --------------------------------------------------------
int __cdecl sub_455920(int a1) {
	int result; // eax
	_DWORD* v2; // eax

	result = dword_5d4594_1045516;
	if (dword_5d4594_1045516) {
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045516, 10200);
		result = nox_window_call_field_94((int)v2, 16397, a1, 3);
	}
	return result;
}

//----- (00455950) --------------------------------------------------------
void __cdecl sub_455950(wchar_t* a1) {
	int v1; // eax

	if (dword_5d4594_1045516) {
		v1 = sub_4559B0(a1);
		if (v1 != -1) {
			nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16398, v1, 0);
			if (!sub_455770())
				sub_46AD20(*(_DWORD**)&dword_5d4594_1045516, 10191, 10192, 0);
		}
	}
}

//----- (004559B0) --------------------------------------------------------
int __cdecl sub_4559B0(wchar_t* a1) {
	int v1;            // esi
	int v2;            // ebx
	const wchar_t* v3; // eax

	v1 = 0;
	v2 = *(_DWORD*)(dword_5d4594_1045536 + 32);
	if (*(short*)(v2 + 44) <= 0)
		return -1;
	while (1) {
		v3 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1045536, 16406, v1, 0);
		if (!nox_wcscmp(v3, a1))
			break;
		if (++v1 >= *(__int16*)(v2 + 44))
			return -1;
	}
	return v1;
}

//----- (00455A00) --------------------------------------------------------
int __cdecl sub_455A00(int a1) {
	int result; // eax

	if (a1 && *(_DWORD*)&byte_5D4594[1045608] && sub_46ADA0(*(int*)&dword_5d4594_1045604) & 0x10)
		result = sub_46A8C0(*(int*)&dword_5d4594_1045604);
	else
		result = nox_window_set_hidden(*(int*)&dword_5d4594_1045604, 1);
	return result;
}

//----- (00455A50) --------------------------------------------------------
char __cdecl sub_455A50(char a1) {
	_DWORD* v1; // edi
	int v2;     // eax
	int v3;     // esi
	int v4;     // edx

	v1 = 0;
	sub_418C80(*(int*)&byte_5D4594[2616328]);
	if (!(dword_5d4594_1045604 || (v2 = sub_455C30()) != 0)) {
		return v2;
	}
	int cur_w, cur_h, cur_d;
	sub_43BEB0_get_video_mode(&cur_w, &cur_h, &cur_d);

	int max_w, max_h;
	sub_430C50_get_video_max(&max_w, &max_h);

	if (cur_w > max_w)
		cur_w = max_w;
	if (cur_h > max_h)
		cur_h = max_h;

	*(_DWORD*)&byte_5D4594[1045612] = 0;
	*(_DWORD*)&byte_5D4594[1045616] = 0;
	*(_DWORD*)&byte_5D4594[1045620] = 0;
	*(_DWORD*)&byte_5D4594[1045608] = 1;
	*(_DWORD*)&byte_5D4594[1045624] = 0;
	sub_46ACE0(*(_DWORD**)&dword_5d4594_1045604, 8811, 8826, 1);
	v3 = 0;
	byte_5D4594[1045628] = a1;
	if (a1) {
		do {
			v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045604, v3 + 8811);
			nox_window_set_hidden((int)v1, 0);
			++v3;
		} while (v3 < byte_5D4594[1045628]);
	}
	if (byte_5D4594[1045628] <= 4u)
		v4 = cur_w - *(_DWORD*)(*(int*)&dword_5d4594_1045604 + 8) / 2;
	else
		v4 = cur_w - *(_DWORD*)(dword_5d4594_1045604 + 8);
	*(_DWORD*)(dword_5d4594_1045604 + 16) = v4 - 91;
	*(_DWORD*)(dword_5d4594_1045604 + 24) =
	    *(_DWORD*)(dword_5d4594_1045604 + 8) + *(_DWORD*)(dword_5d4594_1045604 + 16);
	LOBYTE(v2) = byte_5D4594[1045628];
	if (byte_5D4594[1045628] <= 8u) {
		if (byte_5D4594[1045628] <= 4u) {
			if (!v1) {
				*(_DWORD*)&byte_5D4594[1045608] = 0;
				return v2;
			}
			*(_DWORD*)(dword_5d4594_1045604 + 20) = cur_h - 40 * byte_5D4594[1045628];
		} else {
			*(_DWORD*)(dword_5d4594_1045604 + 20) =
			    cur_h - *(int*)(dword_5d4594_1045604 + 12) / 2;
		}
	} else {
		*(_DWORD*)(dword_5d4594_1045604 + 20) =
		    cur_h - *(_DWORD*)(dword_5d4594_1045604 + 12);
	}
	*(_DWORD*)(dword_5d4594_1045604 + 28) =
	    *(_DWORD*)(dword_5d4594_1045604 + 12) + *(_DWORD*)(dword_5d4594_1045604 + 20);
	LOBYTE(v2) = sub_46A8C0(*(int*)&dword_5d4594_1045604);
	return v2;
}

//----- (00455C10) --------------------------------------------------------
int sub_455C10() {
	*(_DWORD*)&byte_5D4594[1045608] = 0;
	return sub_455A00(0);
}

//----- (00455CD0) --------------------------------------------------------
int __cdecl sub_455CD0(_BYTE* a1, _DWORD* a2) {
	_BYTE* v2;          // esi
	int v3;             // eax
	_BYTE* v5;          // [esp-Ch] [ebp-18h]
	int v6;             // [esp+4h] [ebp-8h]
	int v7;             // [esp+8h] [ebp-4h]
	unsigned __int8 v8; // [esp+10h] [ebp+4h]

	v2 = a1;
	v5 = a1;
	v8 = *a1 - 107;
	nox_client_wndGetPosition_46AA60(v5, &v6, &v7);
	if (byte_5D4594[v8 + 1045612] == 1) {
		v3 = a2[8];
		if (v3) {
		LABEL_8:
			nox_client_drawImageAt_47D2C0(v3, v6, v7);
			goto LABEL_9;
		}
	} else if (byte_5D4594[v8 + 1045612] == 2) {
		v3 = a2[12];
		if (v3)
			goto LABEL_8;
	} else {
		v3 = a2[6];
		if (v3)
			goto LABEL_8;
	}
LABEL_9:
	if (v2[4] & 0x20 && *(_DWORD*)&byte_5D4594[1045632])
		nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1045632], v6 - 4, v7 - 4);
	return 1;
}

//----- (00455E70) --------------------------------------------------------
int __cdecl sub_455E70(unsigned __int8 a1) {
	_DWORD* v2; // eax
	_DWORD* v3; // eax

	for (int i = 0; i < byte_5D4594[1045628]; i++) {
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045604, i + 8811);
		sub_46AD80((int)v2, 32);
	}
	v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045604, a1 + 8810);
	return sub_46AD60((int)v3, 32);
}

//----- (00455EE0) --------------------------------------------------------
int sub_455EE0() {
	int result; // eax

	result = dword_5d4594_1045604;
	if (dword_5d4594_1045604)
		result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1045604);
	dword_5d4594_1045604 = 0;
	*(_DWORD*)&byte_5D4594[1045608] = 0;
	return result;
}

//----- (00455F10) --------------------------------------------------------
int __cdecl sub_455F10(int a1) {
	int result; // eax

	if (a1 && *(_DWORD*)&byte_5D4594[1045640] && sub_46ADA0(*(int*)&dword_5d4594_1045636) & 0x10)
		result = sub_46A8C0(*(int*)&dword_5d4594_1045636);
	else
		result = nox_window_set_hidden(*(int*)&dword_5d4594_1045636, 1);
	return result;
}

//----- (00455F60) --------------------------------------------------------
int sub_455F60() {
	int result; // eax
	int v1;     // ecx
	int v2;     // [esp+0h] [ebp-14h]
	int v3;     // [esp+4h] [ebp-10h]
	int v4;     // [esp+8h] [ebp-Ch]
	int v5;     // [esp+Ch] [ebp-8h]
	int v6;     // [esp+10h] [ebp-4h]

	sub_418C80(*(int*)&byte_5D4594[2616328]);
	if (dword_5d4594_1045636 || (result = sub_456070()) != 0) {
		sub_43BEB0_get_video_mode(&v3, &v2, &v6);
		sub_430C50_get_video_max(&v4, &v5);
		v1 = v3;
		if (v3 > v4) {
			v1 = v4;
			v3 = v4;
		}
		if (v2 > v5)
			v2 = v5;
		*(_DWORD*)&byte_5D4594[1045640] = 1;
		*(_DWORD*)(dword_5d4594_1045636 + 16) =
		    v1 - *(_DWORD*)(dword_5d4594_1045636 + 8) / 3 - 91;
		*(_DWORD*)(dword_5d4594_1045636 + 24) =
		    *(_DWORD*)(dword_5d4594_1045636 + 8) + *(_DWORD*)(dword_5d4594_1045636 + 16);
		*(_DWORD*)(dword_5d4594_1045636 + 20) = v2 - 120;
		*(_DWORD*)(dword_5d4594_1045636 + 28) =
		    *(_DWORD*)(dword_5d4594_1045636 + 12) + *(_DWORD*)(dword_5d4594_1045636 + 20);
		byte_5D4594[1045644] = 0;
		result = sub_46A8C0(*(int*)&dword_5d4594_1045636);
	}
	return result;
}

//----- (00456050) --------------------------------------------------------
int sub_456050() {
	*(_DWORD*)&byte_5D4594[1045640] = 0;
	return sub_455F10(0);
}

//----- (00456070) --------------------------------------------------------
int sub_456070() {
	if (!dword_5d4594_1045636) {
		dword_5d4594_1045636 = nox_new_window_from_file("gui_fb.wnd", 0);
		nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1045636, 0, sub_4560D0, 0);
		if (!dword_5d4594_1045636)
			return 0;
		sub_455F10(0);
		*(_DWORD*)&byte_5D4594[1045648] = sub_42F970("FlagTeamBorder");
	}
	return 1;
}

//----- (004560D0) --------------------------------------------------------
int __cdecl sub_4560D0(int a1, int a2) {
	int v2; // eax
	int v4; // [esp+4h] [ebp-8h]
	int v5; // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &v4, &v5);
	v2 = *(_DWORD*)(a2 + 24);
	if (v2)
		nox_client_drawImageAt_47D2C0(v2, v4, v5);
	if (*(_BYTE*)(a1 + 4) & 0x20 && *(_DWORD*)&byte_5D4594[1045648])
		nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1045648], v4 - 4, v5 - 4);
	return 1;
}

//----- (00456240) --------------------------------------------------------
int sub_456240() {
	int result; // eax

	result = dword_5d4594_1045636;
	if (dword_5d4594_1045636)
		result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1045636);
	dword_5d4594_1045636 = 0;
	*(_DWORD*)&byte_5D4594[1045640] = 0;
	return result;
}

//----- (00456500) --------------------------------------------------------
int sub_456500() {
	_DWORD* v0; // ebp
	_DWORD* v1; // ebx
	char* i;    // esi
	char* j;    // esi
	_DWORD* v4; // edi
	int result; // eax

	v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10501);
	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10502);
	nox_window_call_field_94((int)v0, 16399, 0, 0);
	nox_window_call_field_94((int)v1, 16399, 0, 0);
	sub_46ABB0(*(int*)&dword_5d4594_1045688, 0);
	sub_46ABB0(*(int*)&byte_5D4594[1045692], 0);
	for (i = sub_418B10(); i; i = sub_418B60((int)i))
		sub_457230((wchar_t*)i);
	for (j = sub_416EA0(); j; j = sub_416EE0((int)j)) {
		if (j[2064] != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000)) {
			sub_457140(*((_DWORD*)j + 515), (wchar_t*)j + 2352);
			v4 = sub_418C80(*((_DWORD*)j + 515));
			if (sub_419130((int)v4))
				sub_4571A0(*((_DWORD*)j + 515), *((unsigned __int8*)v4 + 4));
		}
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_46ABB0((int)v0, 0);
		result = sub_46ABB0((int)v1, 0);
	} else {
		sub_46ABB0((int)v0, 1);
		result = sub_46ABB0((int)v1, 1);
	}
	return result;
}

//----- (00456640) --------------------------------------------------------
int __cdecl sub_456640(int a1, int a2) {
	_DWORD* v2; // eax
	_DWORD* v3; // eax
	_DWORD* v4; // esi
	_DWORD* v5; // eax
	_DWORD* v6; // eax
	_DWORD* v7; // eax
	int xLeft;  // [esp+4h] [ebp-8h]
	int yTop;   // [esp+8h] [ebp-4h]

	sub_418C80(*(int*)&byte_5D4594[2616328]);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if ((signed char)*(_BYTE*)(a1 + 4) >= 0) {
		if (*(_DWORD*)(a2 + 20) != 0x80000000)
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
	} else {
		nox_client_drawImageAt_47D2C0(*(_DWORD*)(a2 + 24), xLeft, yTop);
	}
	if (nox_common_gameFlags_check_40A5C0(1) && !nox_common_gameFlags_check_40A5C0(0x8000) && !sub_40A740()) {
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10502);
		if (nox_window_call_field_94((int)v2, 16404, 0, 0) < 0) {
			v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10503);
			sub_46ABB0((int)v6, 0);
		} else {
			v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10501);
			v4 = (_DWORD*)nox_window_call_field_94((int)v3, 16404, 0, 0);
			v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10503);
			sub_46ABB0((int)v5, *v4 >= 0);
		}
	}
	v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10502);
	if (nox_window_call_field_94((int)v7, 16404, 0, 0) < 0) {
		sub_46ABB0(*(int*)&dword_5d4594_1045688, 0);
		sub_46ABB0(*(int*)&byte_5D4594[1045692], 0);
	}
	return 1;
}

//----- (00456BB0) --------------------------------------------------------
char __cdecl sub_456BB0(int a1) {
	_DWORD* v1; // eax
	int v2;     // esi
	int v3;     // edi
	_DWORD* v4; // esi
	float2 v6;  // [esp+8h] [ebp-8h]

	LOBYTE(v1) = byte_5D4594[2618908];
	if (!*(_DWORD*)&byte_5D4594[2618908] || !(*(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 4) & 1) &&
						    !(*(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 3680) & 1)) {
		v2 = nox_common_gameFlags_check_40A5C0(1);
		v1 = sub_418C80(*(int*)&byte_5D4594[2616328]);
		v3 = (int)v1;
		if (v1) {
			if (sub_419130((int)v1)) {
				if (!v2) {
					sub_419960(a1, v3, *(__int16*)&byte_5D4594[2616328]);
					LOBYTE(v1) = byte_5D4594[1045696] + 1;
					++*(_DWORD*)&byte_5D4594[1045696];
					return (char)v1;
				}
				sub_4196D0(v3, a1, *(int*)&byte_5D4594[2616328], 1);
				v1 = (_DWORD*)nox_common_gameFlags_check_40A5C0(128);
				if (!v1) {
					v1 = sub_417040(*(int*)&byte_5D4594[2616328]);
					v4 = v1;
					if (v1) {
						sub_4F7AB0(&v6, v1[514]);
						sub_4E7010(v4[514], &v6);
						LOBYTE(v1) = byte_5D4594[1045696] + 1;
						++*(_DWORD*)&byte_5D4594[1045696];
						return (char)v1;
					}
				}
			} else {
				if (v2) {
					sub_4191D0(*(_BYTE*)(a1 + 57), v3, v2, *(int*)&byte_5D4594[2616328], 1);
					LOBYTE(v1) = byte_5D4594[1045696] + 1;
					++*(_DWORD*)&byte_5D4594[1045696];
					return (char)v1;
				}
				LOBYTE(v1) = sub_419900(a1, v3, *(__int16*)&byte_5D4594[2616328]);
			}
			++*(_DWORD*)&byte_5D4594[1045696];
			return (char)v1;
		}
	}
	return (char)v1;
}

//----- (00456D00) --------------------------------------------------------
wchar_t* __cdecl sub_456D00(int a1, wchar_t* a2) {
	_DWORD* v2;        // eax
	const wchar_t* v3; // eax
	wchar_t* v4;       // eax
	wchar_t v6[56];    // [esp+0h] [ebp-70h]

	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10502);
	v3 = (const wchar_t*)nox_window_call_field_94((int)v2, 16406, a1, 0);
	nox_wcscpy(v6, v3);
	v4 = nox_wcstok(v6, L"\t\n\r");
	return nox_wcscpy(a2, v4);
}

//----- (00456D60) --------------------------------------------------------
int* __cdecl sub_456D60(int a1) {
	int* v1;     // esi
	int* v2;     // edi
	int* result; // eax
	int* v4;     // esi
	int* v5;     // edi

	if (a1 && dword_5d4594_1045684)
		sub_46C4E0(*(_DWORD**)&dword_5d4594_1045684);
	v1 = sub_425890((int*)&byte_5D4594[1045652]);
	if (v1) {
		do {
			v2 = sub_4258A0(v1);
			sub_425920((_DWORD**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
	result = sub_425890((int*)&byte_5D4594[1045668]);
	v4 = result;
	if (result) {
		do {
			v5 = sub_4258A0(v4);
			sub_425920((_DWORD**)v4);
			free(v4);
			v4 = v5;
		} while (v5);
	}
	dword_5d4594_1045684 = 0;
	return result;
}

//----- (00456DF0) --------------------------------------------------------
int __cdecl sub_456DF0(int a1) {
	int result; // eax
	int v2;     // esi
	_DWORD* v3; // eax

	result = dword_5d4594_1045684;
	if (dword_5d4594_1045684) {
		result = sub_456E40(a1, 1);
		v2 = result;
		if (result != -1) {
			v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10501);
			result = nox_window_call_field_94((int)v3, 16398, v2, 0);
		}
	}
	return result;
}

//----- (00456E40) --------------------------------------------------------
int __cdecl sub_456E40(int a1, int a2) {
	int* v2; // esi
	int v3;  // edi

	v2 = sub_425890((int*)&byte_5D4594[1045652]);
	v3 = 0;
	if (!v2)
		return -1;
	while (v2[15] != a1) {
		v2 = sub_4258A0(v2);
		++v3;
		if (!v2)
			return -1;
	}
	if (a2) {
		sub_425920((_DWORD**)v2);
		free(v2);
	}
	return v3;
}

//----- (00456EA0) --------------------------------------------------------
int __cdecl sub_456EA0(wchar_t* a1) {
	int result; // eax
	_DWORD* v2; // edi
	int v3;     // eax
	int v4;     // esi

	result = dword_5d4594_1045684;
	if (dword_5d4594_1045684) {
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10502);
		v3 = sub_456F10(a1, 1);
		v4 = v3;
		if (v3 != -1) {
			sub_4258C0((_DWORD**)&byte_5D4594[1045668], v3);
			nox_window_call_field_94((int)v2, 16404, 0, 0);
			nox_window_call_field_94((int)v2, 16398, v4, 0);
		}
		result = sub_456500();
	}
	return result;
}

//----- (00456F10) --------------------------------------------------------
int __cdecl sub_456F10(wchar_t* a1, int a2) {
	int* v2;        // esi
	int v3;         // ebx
	wchar_t* v4;    // eax
	wchar_t v6[56]; // [esp+Ch] [ebp-70h]

	v2 = sub_425890((int*)&byte_5D4594[1045668]);
	v3 = 0;
	if (!v2)
		return -1;
	while (1) {
		nox_wcscpy(v6, (const wchar_t*)v2 + 6);
		v4 = nox_wcstok(v6, L" \t\n\r");
		if (!_nox_wcsicmp(v4, a1))
			break;
		v2 = sub_4258A0(v2);
		++v3;
		if (!v2)
			return -1;
	}
	if (a2) {
		sub_425920((_DWORD**)v2);
		free(v2);
	}
	return v3;
}

//----- (00456FA0) --------------------------------------------------------
int sub_456FA0() {
	int result; // eax
	int* v1;    // esi
	int* v2;    // edi

	result = dword_5d4594_1045684;
	if (dword_5d4594_1045684) {
		v1 = sub_425890((int*)&byte_5D4594[1045668]);
		if (v1) {
			do {
				v2 = sub_4258A0(v1);
				sub_425920((_DWORD**)v1);
				free(v1);
				v1 = v2;
			} while (v2);
		}
		sub_46ABB0(*(int*)&dword_5d4594_1045688, 0);
		sub_46ABB0(*(int*)&byte_5D4594[1045692], 0);
		result = sub_456500();
	}
	return result;
}

//----- (00457120) --------------------------------------------------------
unsigned __int8 __cdecl sub_457120(int a1) { return byte_587000[8 * (*(unsigned __int8*)(a1 + 56) % 10) + 128968]; }

//----- (00457140) --------------------------------------------------------
int __cdecl sub_457140(int a1, wchar_t* a2) {
	int result;  // eax
	wchar_t* v3; // esi
	_DWORD* v4;  // eax

	result = dword_5d4594_1045684;
	if (dword_5d4594_1045684) {
		v3 = (wchar_t*)nox_malloc(0x48u);
		sub_425770(v3);
		sub_4258E0((int)&byte_5D4594[1045652], v3);
		nox_wcscpy(v3 + 6, a2);
		*((_DWORD*)v3 + 15) = a1;
		v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10501);
		result = nox_window_call_field_94((int)v4, 16397, (int)a2, 3);
	}
	return result;
}

//----- (004571A0) --------------------------------------------------------
int __cdecl sub_4571A0(int a1, int a2) {
	int result; // eax
	int v3;     // ebp
	int v4;     // esi
	int v5;     // edi
	int* i;     // eax

	result = dword_5d4594_1045684;
	if (dword_5d4594_1045684) {
		v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1045684, 10501)[8];
		result = sub_456E40(a1, 0);
		v4 = result;
		if (result != -1) {
			v5 = 3;
			if (a2) {
				for (i = sub_425890((int*)&byte_5D4594[1045668]); i; i = sub_4258A0(i)) {
					if (i[15] == a2)
						v5 = *((unsigned __int8*)i + 64);
				}
			}
			result = *(_DWORD*)(v3 + 24);
			*(_DWORD*)(result + 524 * v4 + 516) = **(_DWORD**)&byte_5D4594[4 * v5 + 2649836];
		}
	}
	return result;
}

//----- (00457350) --------------------------------------------------------
int* __cdecl sub_457350(unsigned __int8 a1, unsigned __int8 a2) {
	int* result; // eax

	for (result = sub_425890((int*)&byte_5D4594[1045668]); result; result = sub_4258A0(result)) {
		if (result[15] == a1)
			result[15] = a2;
	}
	return result;
}

//----- (004573A0) --------------------------------------------------------
int sub_4573A0() {
	int result; // eax

	result = dword_5d4594_1045684;
	if (dword_5d4594_1045684)
		result = sub_456500();
	return result;
}

//----- (004573B0) --------------------------------------------------------
void sub_4573B0() { *(_DWORD*)&byte_5D4594[1045696] = 0; }

//----- (004573C0) --------------------------------------------------------
int __cdecl sub_4573C0(__int16 a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	if (!*(_DWORD*)&byte_5D4594[1046548])
		sub_457410();
	v1 = 0;
	if (!*(_DWORD*)&byte_587000[129668])
		return *(_DWORD*)&byte_587000[129680];
	for (i = &byte_587000[129668]; (a1 & 0x17F0) != *((_DWORD*)i + 1); i += 12) {
		v3 = *((_DWORD*)i + 3);
		++v1;
		if (!v3)
			return *(_DWORD*)&byte_587000[129680];
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 129668];
}

//----- (00457460) --------------------------------------------------------
int __cdecl sub_457460(int a1) {
	WCHAR WideCharStr[16]; // [esp+4h] [ebp-20h]

	_itow(*(unsigned __int16*)(a1 + 54), WideCharStr, 10);
	nox_window_call_field_94(*(int*)&dword_5d4594_1046516, 16414, (int)WideCharStr, 0);
	_itow(*(unsigned __int8*)(a1 + 56), WideCharStr, 10);
	return nox_window_call_field_94(*(int*)&dword_5d4594_1046520, 16414, (int)WideCharStr, 0);
}

//----- (004574D0) --------------------------------------------------------
int sub_4574D0() {
	if (!dword_5d4594_1046492)
		return 0;
	sub_4597E0(0);
	dword_5d4594_1046492 = 0;
	return 1;
}

//----- (00457A10) --------------------------------------------------------
char* sub_457A10() {
	_DWORD* v0;          // eax
	_DWORD* v1;          // esi
	int v2;              // edi
	int v3;              // eax
	char* result;        // eax
	unsigned __int8* v5; // ebx
	int v6;              // edi
	int v7;              // edx
	int v8;              // [esp+8h] [ebp-4h]

	v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10120);
	v1 = v0;
	v2 = 0;
	v3 = 6 * (sub_43F320(v0[59]) + 1);
	v1[7] = v1[5] + v3 + 2;
	v1[3] = v3 + 2;
	result = *(char**)&byte_587000[129664];
	if (*(_DWORD*)&byte_587000[129664]) {
		v5 = &byte_587000[129664];
		do {
			sub_43F840(v1[59], *((unsigned __int16**)v5 + 1), &v8, 0, 0);
			if (v8 > v2)
				v2 = v8;
			result = (char*)*((_DWORD*)v5 + 3);
			v5 += 12;
		} while (result);
	}
	v6 = v2 + 7;
	v7 = v1[6] - v6;
	v1[2] = v6;
	v1[4] = v7;
	return result;
}

//----- (00457B60) --------------------------------------------------------
int __cdecl sub_457B60(int a1) {
	char* v1;              // eax
	_DWORD* v2;            // eax
	char* v3;              // eax
	unsigned __int16 v4;   // di
	char* v5;              // esi
	_DWORD* v6;            // eax
	unsigned __int16 v7;   // ax
	unsigned __int8 v8;    // al
	_DWORD* v9;            // eax
	_DWORD* v10;           // eax
	_DWORD* v11;           // edi
	int v12;               // eax
	_DWORD* v13;           // edi
	int v14;               // eax
	_DWORD* v15;           // edi
	int v16;               // eax
	unsigned int v17;      // ecx
	WCHAR WideCharStr[16]; // [esp+0h] [ebp-E8h]
	wchar_t v20[100];      // [esp+20h] [ebp-C8h]

	sub_416640();
	v1 = sub_40A4C0();
	nox_swprintf(v20, L"%S", v1);
	nox_window_call_field_94(*(int*)&byte_5D4594[1046512], 16414, (int)v20, 0);
	sub_459CD0();
	if (nox_common_gameFlags_check_40A5C0(128))
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10122);
	else
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10119);
	nox_window_set_hidden((int)v2, 1);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		sub_46ABB0(*(int*)&dword_5d4594_1046508, 1);
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v3 = sub_416590(1);
			v4 = *((_WORD*)v3 + 26) & 0x17F0;
			sub_458230(v4, v3, 1);
			v5 = sub_4165B0();
			*((_WORD*)v5 + 26) = v4 | *((_WORD*)v5 + 26) & 0xE80F;
			if (sub_40A740()) {
				sub_46ABB0(*(int*)&dword_5d4594_1046508, 0);
			} else if (sub_417DA0(4)) {
				v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046508, 10330);
				v6[9] |= 4u;
			} else {
				sub_46AD20(*(_DWORD**)&dword_5d4594_1046508, 10331, 10333, 0);
			}
		} else {
			if (sub_417DA0(4))
				sub_46AD20(*(_DWORD**)&dword_5d4594_1046508, 10330, 10331, 0);
			else
				sub_46AD20(*(_DWORD**)&dword_5d4594_1046508, 10330, 10333, 0);
			v5 = (char*)a1;
			sub_458230(*(unsigned __int16*)(a1 + 52), (char*)a1, 0);
		}
		v7 = sub_40A020(*((_WORD*)v5 + 26));
		_itow(v7, WideCharStr, 10);
		nox_window_call_field_94(*(int*)&dword_5d4594_1046516, 16414, (int)WideCharStr, 0);
		v8 = sub_40A180(*((_WORD*)v5 + 26));
		_itow(v8, WideCharStr, 10);
		nox_window_call_field_94(*(int*)&dword_5d4594_1046520, 16414, (int)WideCharStr, 0);
		sub_4580E0((int)v5);
	} else {
		v9 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10161);
		sub_46ABB0((int)v9, 0);
		sub_46ABB0(*(int*)&byte_5D4594[1046536], 0);
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1046536] + 4) |= 8u;
		sub_46ABB0(*(int*)&dword_5d4594_1046504, 1);
		sub_46AD20(*(_DWORD**)&dword_5d4594_1046504, 10134, 10135, 0);
		sub_46ACE0(*(_DWORD**)&dword_5d4594_1046492, 10141, 10141, 1);
		v5 = (char*)a1;
		sub_458230(*(unsigned __int16*)(a1 + 52), (char*)a1, 0);
		_itow(*(unsigned __int16*)(a1 + 54), WideCharStr, 10);
		nox_window_call_field_94(*(int*)&dword_5d4594_1046516, 16414, (int)WideCharStr, 0);
		_itow(*(unsigned __int8*)(a1 + 56), WideCharStr, 10);
		nox_window_call_field_94(*(int*)&dword_5d4594_1046520, 16414, (int)WideCharStr, 0);
		if (sub_43AF70() == 1) {
			v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10210);
			nox_window_set_hidden((int)v10, 0);
			sub_457FE0();
		}
	}
	v11 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046508, 10331);
	if (sub_417DA0(2)) {
		v12 = v11[9];
		LOBYTE(v12) = v12 | 4;
		v11[9] = v12;
	}
	v13 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046508, 10333);
	if (sub_417DA0(1)) {
		v14 = v13[9];
		LOBYTE(v14) = v14 | 4;
		v13[9] = v14;
	}
	v15 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10119);
	v16 = sub_4573C0(*((_WORD*)v5 + 26));
	nox_window_call_field_94((int)v15, 16385, v16, 0);
	sub_459880((int)v5);
	LOWORD(v17) = *((_WORD*)v5 + 26);
	return sub_457F30((v17 >> 12) & 1);
}
// 457F15: variable 'v17' is possibly undefined

//----- (00457F30) --------------------------------------------------------
int __cdecl sub_457F30(int a1) {
	int v1;     // esi
	_DWORD* v2; // eax
	_DWORD* v3; // eax
	_DWORD* v4; // esi
	_DWORD* v5; // eax

	v1 = a1 != 1;
	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046504, 10152);
	sub_46ABB0((int)v2, v1);
	v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046504, 10141);
	sub_46ABB0((int)v3, v1);
	sub_46ABB0(*(int*)&dword_5d4594_1046516, v1);
	sub_46ABB0(*(int*)&dword_5d4594_1046520, v1);
	if (a1 == 1) {
		v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10122);
		if (!wndIsShown_sub_46ACC0((int)v4))
			nox_window_set_hidden((int)v4, 1);
	}
	v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10183);
	return nox_window_set_hidden((int)v5, a1);
}

// 458291: variable 'v5' is possibly undefined

//----- (00458500) --------------------------------------------------------
int __cdecl sub_458500(_DWORD* a1, int a2) {
	int2* v1;   // edi
	_DWORD* v2; // esi
	int xLeft;  // [esp+8h] [ebp-8h]
	int v5;     // [esp+Ch] [ebp-4h]

	v1 = nox_client_getMousePos_4309F0();
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &v5);
	nox_client_drawRectFilledAlpha_49CF10(xLeft, v5 + 25, a1[2], a1[3] - 25);
	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10120);
	if (!wndIsShown_sub_46ACC0((int)v2) && !sub_46AAB0(v2, v1->field_0, v1->field_4)) {
		sub_46ADE0((int)v2);
		nox_window_set_hidden((int)v2, 1);
	}
	return 1;
}

//----- (00458590) --------------------------------------------------------
int __cdecl sub_458590(int a1, int a2, int a3, int a4) {
	if (a2 == 21) {
		if (a3 != 1)
			return 0;
		if (a4 == 2) {
			sub_452D80(231, 100);
			sub_4597E0(0);
		}
	}
	return 1;
}

// 458F5A: variable 'v34' is possibly undefined

//----- (00459150) --------------------------------------------------------
char sub_459150() {
	char* v0;            // ebp
	int i;               // edi
	char* v2;            // esi
	int v3;              // ebx
	wchar_t* v4;         // eax
	char* v5;            // eax
	const char* v6;      // edi
	char* v7;            // eax
	int v8;              // ebx
	char* v9;            // esi
	unsigned __int8 v10; // dl
	char* v11;           // edi
	char* v12;           // eax
	char* v13;           // eax
	int* v14;            // eax
	int* v16;            // [esp-Ch] [ebp-2Ch]
	int* v17;            // [esp-4h] [ebp-24h]
	__int16 v18;         // [esp-4h] [ebp-24h]
	char v19[16];        // [esp+10h] [ebp-10h]

	v0 = sub_4165B0();
	if (v0[52] & 0x60) {
		for (i = sub_417DD0(); i < 2; ++i) {
			v2 = sub_4186D0(0);
			v3 = (i != 0) + 1;
			if (sub_40A740()) {
				sub_418800((wchar_t*)v2, (wchar_t*)&byte_5D4594[1046564], 0);
			} else {
				v4 = sub_418C20(v3);
				sub_418800((wchar_t*)v2, v4, 1);
			}
			v2[56] = v3;
			sub_4184D0((wchar_t*)v2);
		}
		sub_417D50(4);
	}
	LOBYTE(v5) = v0[57];
	if ((_BYTE)v5) {
		v5 = sub_409B80();
		v6 = v5;
	} else {
		v6 = v0;
	}
	if (*v6) {
		v7 = sub_409B40();
		v8 = _strcmpi(v6, v7);
		sub_4165F0(1, 0);
		v9 = sub_4165D0(0);
		sub_40A440(v9 + 9);
		if (!((*((_WORD*)v9 + 26) >> 8) & 0x10)) {
			sub_409FB0_settings(*((_WORD*)v9 + 26), *((_WORD*)v9 + 27));
			sub_40A040_settings(*((_WORD*)v9 + 26), v9[56]);
		}
		if (v8 && sub_43AF70() == 1) {
			if (!nox_common_gameFlags_check_40A5C0(128)) {
				sub_4263C0();
				sub_40DF90();
				sub_4264D0();
				sub_416150(15, 0);
			}
			if (!v9[57])
				sub_41D650();
		}
		if (nox_common_gameFlags_check_40A5C0(128)) {
			nox_common_gameFlags_unset_40A540(49152);
			sub_40A4D0(*((_WORD*)v9 + 26) & 0xC000);
		}
		v9[57] = 0;
		if (v8) {
			v19[0] = 0;
			*(_DWORD*)&v19[1] = 0;
			*(_DWORD*)&v19[5] = 0;
			*(_DWORD*)&v19[9] = 0;
			v10 = byte_587000[131672];
			strcpy(v19, v6);
			v11 = &v19[strlen(v19)];
			*(_DWORD*)v11 = *(_DWORD*)&byte_587000[131668];
			v11[4] = v10;
			sub_4D2450(v19);
			sub_416690();
			sub_4165D0(1);
			LOBYTE(v5) = (unsigned int)sub_4597E0(0);
		} else {
			sub_424BD0();
			sub_4537F0();
			v17 = (int*)sub_459870();
			v12 = sub_416590(1);
			sub_57AAA0("user.rul", v12, v17);
			v13 = nox_server_currentMapGetFilename_409B30();
			sub_57A950(v13);
			v18 = nox_common_gameFlags_getVal_40A5B0();
			v16 = (int*)sub_459870();
			v14 = (int*)sub_416590(0);
			sub_57A1E0(v14, "user.rul", v16, 3, v18);
			LOBYTE(v5) = (unsigned int)sub_4597E0(0);
		}
	}
	return (char)v5;
}

//----- (004593B0) --------------------------------------------------------
int __cdecl sub_4593B0(int a1) {
	_DWORD* v1; // esi
	_DWORD* v2; // ebx
	_DWORD* v3; // edi
	int result; // eax

	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10163);
	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10161);
	v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10162);
	if (a1) {
		if (a1 == 1) {
			v1[15] = *(_DWORD*)&byte_5D4594[1046360];
			v3[15] = *(_DWORD*)&byte_5D4594[1046356];
			if (dword_5d4594_1046532) {
				sub_456D60(1);
				dword_5d4594_1046532 = 0;
			}
			if (*(_DWORD*)&byte_5D4594[1046540]) {
				sub_4AD820();
				*(_DWORD*)&byte_5D4594[1046540] = 0;
			}
			dword_5d4594_1046528 = sub_4541D0(*(int*)&dword_5d4594_1046492);
			result = sub_459560(10161);
		} else {
			result = a1 - 2;
			if (a1 == 2) {
				v1[15] = *(_DWORD*)&byte_5D4594[1046360];
				if (nox_common_gameFlags_check_40A5C0(1))
					v2[15] = *(_DWORD*)&byte_5D4594[1046360];
				else
					v2[21] = *(_DWORD*)&byte_5D4594[1046360];
				if (dword_5d4594_1046528) {
					sub_4557D0(1);
					dword_5d4594_1046528 = 0;
				}
				if (*(_DWORD*)&byte_5D4594[1046540]) {
					sub_4AD820();
					*(_DWORD*)&byte_5D4594[1046540] = 0;
				}
				dword_5d4594_1046532 = sub_456270(*(int*)&dword_5d4594_1046492);
				result = sub_459560(10162);
			}
		}
	} else {
		if (nox_common_gameFlags_check_40A5C0(1))
			v2[15] = *(_DWORD*)&byte_5D4594[1046356];
		else
			v2[21] = *(_DWORD*)&byte_5D4594[1046356];
		v3[15] = *(_DWORD*)&byte_5D4594[1046356];
		if (dword_5d4594_1046532) {
			sub_456D60(1);
			dword_5d4594_1046532 = 0;
		} else if (dword_5d4594_1046528) {
			sub_4557D0(1);
			dword_5d4594_1046528 = 0;
		}
		*(_DWORD*)&byte_5D4594[1046540] = sub_4AD320(*(int*)&dword_5d4594_1046492);
		result = sub_459560(10163);
	}
	return result;
}

//----- (00459560) --------------------------------------------------------
int __cdecl sub_459560(int a1) {
	_DWORD* v1; // ebx
	int v2;     // esi
	_DWORD* v3; // edi
	_DWORD* v4; // eax
	_DWORD* v5; // edi
	_DWORD* v6; // edi
	_DWORD* v7; // edi

	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, a1);
	v2 = v1[99];
	switch (a1) {
	case 10161:
		v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10163);
		sub_46B120(v6, 0);
		sub_46B120(v6, v2);
		v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10162);
		goto LABEL_7;
	case 10162:
		v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10163);
		sub_46B120(v5, 0);
		sub_46B120(v5, v2);
		v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10161);
		goto LABEL_7;
	case 10163:
		v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10162);
		sub_46B120(v3, 0);
		sub_46B120(v3, v2);
		v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10161);
	LABEL_7:
		v7 = v4;
		sub_46B120(v4, 0);
		sub_46B120(v7, v2);
		break;
	}
	sub_46B120(v1, 0);
	return sub_46B120(v1, v2);
}

//----- (00459650) --------------------------------------------------------
int __cdecl sub_459650(wchar_t* a1) {
	int v1;              // edi
	const wchar_t** v2;  // eax
	unsigned __int8* v3; // esi
	int v4;              // ecx

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[129668])
		return 0;
	v2 = (const wchar_t**)&byte_587000[129668];
	v3 = &byte_587000[129668];
	while (nox_wcscmp(*v2, a1)) {
		v4 = *((_DWORD*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const wchar_t**)v3;
		if (!v4)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 129672];
}

//----- (004596A0) --------------------------------------------------------
int sub_4596A0() {
	_DWORD* v0; // edi
	int result; // eax
	int* v2;    // esi

	v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10120);
	nox_window_call_field_94((int)v0, 16399, 0, 0);
	result = *(_DWORD*)&byte_587000[129668];
	if (*(_DWORD*)&byte_587000[129668]) {
		v2 = (int*)&byte_587000[129668];
		do {
			if (v2[1] != 4096)
				nox_window_call_field_94((int)v0, 16397, *v2, -1);
			result = v2[3];
			v2 += 3;
		} while (result);
	}
	return result;
}

//----- (00459700) --------------------------------------------------------
int sub_459700() {
	char* v0;          // esi
	int v1;            // eax
	int v2;            // edi
	const wchar_t* v3; // eax
	wchar_t v5[256];   // [esp+8h] [ebp-200h]

	sub_416580();
	v0 = sub_4165B0();
	v1 = nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16404, 0, 0);
	v2 = v1;
	v3 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16406, v1, 0);
	nox_wcscpy(v5, v3);
	nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16398, v2, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16402, v2, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16397, (int)v5, -1);
	nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16403, v2, 0);
	sub_57A9F0(v0, "user.rul");
	sub_57A1E0((int*)v0, "user.rul", 0, 5, *((_WORD*)v0 + 26));
	sub_459880((int)v0);
	return sub_459D50(1);
}

//----- (004597E0) --------------------------------------------------------
int* __cdecl sub_4597E0(int a1) {
	int v1;      // eax
	int* result; // eax

	if (dword_5d4594_1046492) {
		v1 = sub_46B4F0();
		if (nox_window_is_child(*(int*)&dword_5d4594_1046492, v1))
			sub_46B500(0);
		sub_46C4E0(*(_DWORD**)&dword_5d4594_1046492);
		dword_5d4594_1046492 = 0;
		sub_456D60(0);
		sub_4BE610();
		dword_5d4594_1046532 = 0;
		sub_4557D0(0);
		dword_5d4594_1046528 = 0;
		sub_4AD820();
		*(_DWORD*)&byte_5D4594[1046536] = 0;
	}
	result = (int*)a1;
	if (a1) {
		result = sub_57ADF0((int*)&byte_5D4594[1045956]);
		*(_DWORD*)&byte_587000[129656] = 1;
	}
	return result;
}

//----- (00459870) --------------------------------------------------------
char* sub_459870() { return (char*)&byte_5D4594[1045956]; }

//----- (00459A40) --------------------------------------------------------
int __cdecl sub_459A40(char* a1) {
	char v2[100];    // [esp+0h] [ebp-12Ch]
	wchar_t v3[100]; // [esp+64h] [ebp-C8h]

	strncpy(v2, a1, 0xFu);
	v2[15] = 0;
	nox_swprintf(v3, L"%S", v2);
	return nox_window_call_field_94(*(int*)&byte_5D4594[1046512], 16414, (int)v3, 0);
}

//----- (00459AA0) --------------------------------------------------------
char* __cdecl sub_459AA0(int a1) {
	int v1;            // eax
	const wchar_t* v2; // eax
	const wchar_t* v3; // eax
	char* result;      // eax
	int v5;            // eax
	const char* v6;    // edi
	char v7[100];      // [esp+Ch] [ebp-64h]

	v1 = nox_window_call_field_94(*(int*)&byte_5D4594[1046512], 16413, 0, 0);
	nox_sprintf(v7, "%S", v1);
	strncpy((char*)(a1 + 9), v7, 0xFu);
	*(_WORD*)(a1 + 52) = sub_459C10();
	qmemcpy((void*)(a1 + 24), sub_453F90(), 0x14u);
	*(_DWORD*)(a1 + 44) = *(_DWORD*)sub_453600();
	*(_DWORD*)(a1 + 48) = sub_453610();
	v2 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1046516, 16413, 0, 0);
	if (*v2)
		*(_WORD*)(a1 + 54) = nox_wcstol(v2, 0, 10);
	v3 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1046520, 16413, 0, 0);
	if (*v3)
		*(_BYTE*)(a1 + 56) = nox_wcstol(v3, 0, 10);
	*(_BYTE*)(a1 + 57) = (sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10122)[9] >> 2) & 1;
	result = (char*)nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16404, 0, 0);
	if ((int)result >= 0 && (v5 = nox_window_call_field_94(*(int*)&dword_5d4594_1046496, 16406, (int)result, 0),
				 nox_sprintf(v7, "%S", v5), (result = strtok(v7, "\t")) != 0)) {
		v6 = result;
		result = 0;
		strcpy((char*)a1, v6);
	} else {
		*(_BYTE*)a1 = 0;
	}
	return result;
}

//----- (00459C10) --------------------------------------------------------
int sub_459C10() {
	wchar_t* v0; // eax

	v0 = (wchar_t*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10119);
	return sub_459650(v0 + 54);
}

//----- (00459C30) --------------------------------------------------------
int sub_459C30() {
	char* v0;   // esi
	int result; // eax
	_DWORD* v2; // edi
	int v3;     // eax

	v0 = sub_416590(1);
	sub_453F70(v0 + 24);
	sub_4535E0((int*)v0 + 11);
	sub_4535F0(*((_DWORD*)v0 + 12));
	result = dword_5d4594_1046492;
	if (dword_5d4594_1046492) {
		sub_459880((int)v0);
		sub_4BDF70((int*)v0);
		sub_458230(*((unsigned __int16*)v0 + 26), v0, 0);
		sub_457460((int)v0);
		if (sub_43AF70() == 1)
			sub_457FE0();
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1046492, 10119);
		v3 = sub_4573C0(*((_WORD*)v0 + 26));
		result = nox_window_call_field_94((int)v2, 16385, v3, 0);
	}
	return result;
}

//----- (00459D50) --------------------------------------------------------
int __cdecl sub_459D50(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1046544] = a1;
	return result;
}

//----- (00459D60) --------------------------------------------------------
int sub_459D60() { return *(_DWORD*)&byte_5D4594[1046544]; }

//----- (00459D70) --------------------------------------------------------
int sub_459D70() {
	int v0; // eax

	v0 = -(dword_5d4594_1046492 != 0);
	LOBYTE(v0) = v0 & 0xFE;
	return v0 + 2;
}

//----- (00459D80) --------------------------------------------------------
int __cdecl sub_459D80(int a1) {
	int result; // eax

	result = dword_5d4594_1046492;
	if (dword_5d4594_1046492)
		result = nox_window_set_hidden(*(int*)&dword_5d4594_1046492, a1);
	return result;
}

//----- (00459DA0) --------------------------------------------------------
BOOL sub_459DA0() { return dword_5d4594_1046492 != 0; }

//----- (00459DB0) --------------------------------------------------------
BOOL __cdecl sub_459DB0(int a1) { return *(_DWORD*)(a1 + 112) & 0x400000 && *(_BYTE*)(a1 + 116) & 8; }

//----- (00459DD0) --------------------------------------------------------
int __cdecl sub_459DD0(int a1, char a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	result = a1;
	v3 = *(_DWORD*)(a1 + 120);
	*(_BYTE*)(a1 + 284) |= a2;
	if (v3 >= 0) {
		v4 = *(_DWORD*)&byte_5D4594[1046596];
		*(_DWORD*)(a1 + 412) = 0;
		*(_DWORD*)(a1 + 408) = v4;
		if (*(_DWORD*)&byte_5D4594[1046596])
			*(_DWORD*)(*(_DWORD*)&byte_5D4594[1046596] + 412) = a1;
		*(_DWORD*)&byte_5D4594[1046596] = a1;
		*(_DWORD*)(a1 + 120) |= 0x80000000;
	}
	return result;
}

//----- (00459E30) --------------------------------------------------------
int __cdecl sub_459E30(int a1, char a2) {
	int result; // eax
	bool v3;    // zf
	int v4;     // ecx
	int v5;     // ecx

	result = a1;
	if (*(int*)(a1 + 120) < 0) {
		v3 = ((unsigned __int8)~a2 & *(_BYTE*)(a1 + 284)) == 0;
		*(_BYTE*)(a1 + 284) &= ~a2;
		if (v3) {
			v4 = *(_DWORD*)(a1 + 408);
			if (v4)
				*(_DWORD*)(v4 + 412) = *(_DWORD*)(a1 + 412);
			v5 = *(_DWORD*)(a1 + 412);
			if (v5)
				*(_DWORD*)(v5 + 408) = *(_DWORD*)(a1 + 408);
			else
				*(_DWORD*)&byte_5D4594[1046596] = *(_DWORD*)(a1 + 408);
			*(_DWORD*)(a1 + 120) &= 0x7FFFFFFFu;
		}
	}
	return result;
}

//----- (00459EB0) --------------------------------------------------------
int sub_459EB0() { return *(_DWORD*)&byte_5D4594[1046596]; }

//----- (00459EC0) --------------------------------------------------------
int __cdecl sub_459EC0(int a1) { return *(_DWORD*)(a1 + 408); }

//----- (00459ED0) --------------------------------------------------------
int __cdecl sub_459ED0_drawable(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 416) = *(_DWORD*)&byte_5D4594[1046600];
	*(_DWORD*)(a1 + 420) = 0;
	if (*(_DWORD*)&byte_5D4594[1046600])
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1046600] + 420) = a1;
	*(_DWORD*)&byte_5D4594[1046600] = a1;
	return result;
}

//----- (00459F00) --------------------------------------------------------
int __cdecl sub_459F00(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // ecx

	result = a1;
	v2 = *(_DWORD*)(a1 + 416);
	if (v2)
		*(_DWORD*)(v2 + 420) = *(_DWORD*)(a1 + 420);
	v3 = *(_DWORD*)(a1 + 420);
	if (v3) {
		result = *(_DWORD*)(a1 + 416);
		*(_DWORD*)(v3 + 416) = result;
	} else {
		*(_DWORD*)&byte_5D4594[1046600] = *(_DWORD*)(a1 + 416);
	}
	return result;
}

//----- (00459F40) --------------------------------------------------------
int __cdecl sub_459F40_drawable(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 424) = *(_DWORD*)&byte_5D4594[1046576];
	*(_DWORD*)(a1 + 428) = 0;
	if (*(_DWORD*)&byte_5D4594[1046576])
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1046576] + 428) = a1;
	*(_DWORD*)&byte_5D4594[1046576] = a1;
	return result;
}

//----- (00459F70) --------------------------------------------------------
_DWORD* __cdecl sub_459F70(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // ecx

	result = a1;
	v2 = a1[106];
	if (v2) {
		*(_DWORD*)(v2 + 428) = a1[107];
	} else if (!a1[107] && *(_DWORD**)&byte_5D4594[1046576] != a1) {
		return result;
	}
	v3 = a1[107];
	if (v3)
		*(_DWORD*)(v3 + 424) = a1[106];
	else
		*(_DWORD*)&byte_5D4594[1046576] = a1[106];
	a1[106] = 0;
	a1[107] = 0;
	result = (_DWORD*)sub_452EB0(a1 + 124);
	if (result)
		result = (_DWORD*)sub_4523D0(result);
	return result;
}

//----- (0045A000) --------------------------------------------------------
int sub_45A000() { return *(_DWORD*)&byte_5D4594[1046600]; }

//----- (0045A010) --------------------------------------------------------
int __cdecl sub_45A010(int a1) { return *(_DWORD*)(a1 + 416); }

//----- (0045A020) --------------------------------------------------------
int nox_get_drawable_count() { return nox_drawable_count; }

//----- (0045A030) --------------------------------------------------------
int sub_45A030() { return nox_drawable_head_unk2; }

//----- (0045A040) --------------------------------------------------------
int __cdecl sub_45A040(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 360);
	else
		result = 0;
	return result;
}

//----- (0045A060) --------------------------------------------------------
int sub_45A060() { return nox_drawable_head_unk1; }

//----- (0045A070) --------------------------------------------------------
int __cdecl sub_45A070(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 368);
	else
		result = 0;
	return result;
}

//----- (0045A090) --------------------------------------------------------
int sub_45A090() { return *(_DWORD*)&byte_5D4594[1046576]; }

//----- (0045A0A0) --------------------------------------------------------
int __cdecl sub_45A0A0(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 424);
	else
		result = 0;
	return result;
}

//----- (0045A0C0) --------------------------------------------------------
int sub_45A0C0() {
	int result; // eax

	result = nox_drawable_head_unk1;
	if (!result)
		return 0;
	while (!(*(_DWORD*)(result + 120) & 0x2000000)) {
		result = *(_DWORD*)(result + 368);
		if (!result)
			return 0;
	}
	return result;
}

//----- (0045A0E0) --------------------------------------------------------
int __cdecl sub_45A0E0(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 368);
	if (!result)
		return 0;
	while (!(*(_DWORD*)(result + 120) & 0x2000000)) {
		result = *(_DWORD*)(result + 368);
		if (!result)
			return 0;
	}
	return result;
}

//----- (0045A110) --------------------------------------------------------
_DWORD* __cdecl sub_45A110_drawable(nox_drawable* a1) {
	_DWORD* result; // eax

	result = a1;
	a1->field_98 = 0;
	a1->field_97 = nox_drawable_head_unk3;
	if (nox_drawable_head_unk3)
		nox_drawable_head_unk3->field_98 = a1;
	else
		nox_drawable_head_unk4 = a1;
	nox_drawable_head_unk3 = a1;
	a1->flags |= 0x400000u;
	return result;
}

//----- (0045A160) --------------------------------------------------------
void __cdecl sub_45A160_drawable(nox_drawable* a1) {
	if (!(a1->flags & 0x400000))
		return;

	nox_drawable* v2 = a1->field_98;
	if (v2)
		v2->field_97 = a1->field_97;
	else
		nox_drawable_head_unk3 = a1->field_97;

	nox_drawable* v3 = a1->field_97;
	if (v3)
		v3->field_98 = a1->field_98;
	else
		nox_drawable_head_unk4 = a1->field_98;

	a1->flags &= 0xFFBFFFFF;
}

//----- (0045A1D0) --------------------------------------------------------
BOOL __cdecl nox_alloc_drawable_init(int cnt) {
	nox_alloc_drawable = nox_new_alloc_class("drawableClass", sizeof(nox_drawable), cnt);
	return nox_alloc_drawable != 0;
}

//----- (0045A200) --------------------------------------------------------
void nox_drawable_free() {
	nox_free_alloc_class(nox_alloc_drawable);
	nox_alloc_drawable = 0;
	nox_drawable_head_unk2 = 0;
	nox_drawable_head_unk1 = 0;
	nox_drawable_head_unk3 = 0;
	nox_drawable_head_unk4 = 0;
	nox_drawable_count = 0;
}

//----- (0045A360) --------------------------------------------------------
nox_drawable* __cdecl sub_45A360_drawable(int thingInd, int a2, int a3) {
	nox_drawable* dr = nox_new_drawable_for_thing(thingInd);
	if (!dr)
		return 0;
	sub_452E60(&dr->field_31);
	if (dr->field_116)
		sub_49BC80_drawable(dr);
	if (dr->flags & 0x200000)
		sub_49BAB0_drawable(dr);
	if (dr->field_123)
		sub_459F40_drawable(dr);
	dr->field_3 = a2;
	dr->field_8 = a2;
	dr->field_4 = a3;
	dr->field_9 = a3;
	dr->field_80 = *(_DWORD*)&byte_5D4594[2598000];
	dr->field_92 = nox_drawable_head_unk1;
	dr->field_93 = 0;
	if (nox_drawable_head_unk1)
		nox_drawable_head_unk1->field_93 = dr;
	nox_drawable_head_unk1 = dr;
	sub_49AA00_drawable(dr);
	if (dr->flags & 0x10000) {
		nox_drawable* v6 = nox_drawable_head_unk2;
		dr->field_91 = 0;
		dr->field_90 = v6;
		if (v6)
			v6->field_91 = dr;
		nox_drawable_head_unk2 = dr;
	}
	if (*(_BYTE*)((char*)dr + 112) & 4)
		sub_459ED0_drawable(dr);
	dr->flags |= 0x1000000u;
	sub_45A990_drawable(dr);
	dr->field_120 = 0;
	dr->field_121 = 0;
	sub_45A480_drawable(dr);
	return dr;
}

//----- (0045A480) --------------------------------------------------------
void __cdecl sub_45A480_drawable(int a1) {
	int v1; // ecx

	if (*(_DWORD*)(a1 + 112) & 0x1000000 && *(_BYTE*)(a1 + 116) & 0xC0) {
		v1 = *(_DWORD*)(a1 + 120);
		if (v1 & 0x4000)
			sub_495F70(a1);
	}
}

//----- (0045A4B0) --------------------------------------------------------
int __cdecl sub_45A4B0(_QWORD* a1) {
	sub_495B00((int)a1);
	sub_414330(nox_alloc_drawable, a1);
	return --nox_drawable_count;
}

//----- (0045A4E0) --------------------------------------------------------
void __cdecl sub_45A4E0_drawable(nox_drawable* dr) {
	if (dr->field_93)
		dr->field_93->field_92 = dr->field_92;
	else
		nox_drawable_head_unk1 = dr->field_92;

	if (dr->field_92)
		dr->field_92->field_93 = dr->field_93;

	sub_49A9B0_drawable(dr);
	sub_476F10_drawable(dr);

	if (dr->flags & 0x10000) {
		if (dr->field_91)
			dr->field_91->field_90 = dr->field_90;
		else
			nox_drawable_head_unk2 = dr->field_90;

		if (dr->field_90)
			dr->field_90->field_91 = dr->field_91;
	}

	sub_45A160_drawable(dr);
	sub_49BCD0(dr);
	sub_49BAF0(dr);
	sub_49BA10(dr);
	sub_459E30(dr, 3);
	sub_459F70(dr);

	if (*(_BYTE*)(&dr->field_28) & 0x4)
		sub_459F00(dr);

	if (sub_419130(&dr->field_6))
		sub_419570(&dr->field_6, dr->field_32);

	sub_45A4B0(dr);
}

//----- (0045A5E0) --------------------------------------------------------
void __cdecl sub_45A5E0(int a1) {
	int v1; // esi
	int v2; // edi

	v1 = nox_drawable_head_unk1;
	if (v1) {
		do {
			v2 = *(_DWORD*)(v1 + 368);
			if (!(*(_BYTE*)(v1 + 112) & 4) || !a1 || !sub_45A630(v1))
				sub_45A4E0_drawable(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (0045A630) --------------------------------------------------------
int __cdecl sub_45A630(int a1) {
	char* v1; // eax

	v1 = sub_416EA0();
	if (!v1)
		return 0;
	while (*(_DWORD*)(a1 + 128) != *((_DWORD*)v1 + 515)) {
		v1 = sub_416EE0((int)v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (0045A670) --------------------------------------------------------
void __cdecl sub_45A670(unsigned int a1) {
	int result; // eax
	_DWORD* v2; // esi
	_DWORD* v3; // edi

	result = *(_DWORD*)&byte_5D4594[1046604];
	if (!*(_DWORD*)&byte_5D4594[1046604]) {
		result = sub_44CFC0((CHAR*)&byte_587000[132084]);
		*(_DWORD*)&byte_5D4594[1046604] = result;
	}
	v2 = nox_drawable_head_unk1;
	if (!v2)
		return;
	do {
		int result = v2[28];
		v3 = (_DWORD*)v2[92];
		if (!(result & 0x20400006)) {
			if (!sub_49C520((int)v2)) {
				if (v2[27] != *(_DWORD*)&byte_5D4594[1046604] && v2[80] < a1)
					sub_45A4E0_drawable((int)v2);
			}
		}
		v2 = v3;
	} while (v3);
}

//----- (0045A6F0) --------------------------------------------------------
_DWORD* __cdecl sub_45A6F0(int a1) {
	_DWORD* result; // eax

	result = nox_drawable_head_unk1;
	if (!result)
		return 0;
	while (result[28] & 0x20400000 || result[32] != a1) {
		result = (_DWORD*)result[92];
		if (!result)
			return 0;
	}
	return result;
}

//----- (0045A720) --------------------------------------------------------
_DWORD* __cdecl sub_45A720(int a1) {
	_DWORD* result; // eax

	result = nox_drawable_head_unk1;
	if (!result)
		return 0;
	while (!(result[28] & 0x20400000) || result[32] != a1) {
		result = (_DWORD*)result[92];
		if (!result)
			return 0;
	}
	return result;
}

//----- (0045A750) --------------------------------------------------------
int sub_45A750() {
	int result; // eax
	_DWORD* v1; // edi
	int v2;     // ecx
	int v3;     // edx
	int v4;     // ebp
	int v5;     // edx
	int v6;     // esi
	int v7;     // ecx
	int v8;     // ebx
	int v9;     // eax
	int v10;    // [esp+4h] [ebp-4h]

	result = *(_DWORD*)&byte_5D4594[2614252];
	v1 = nox_drawable_head_unk1;
	v10 = *(_DWORD*)&byte_5D4594[2614252];
	if (v1) {
		do {
			if (v1[28] & 0x300000) {
				v2 = v1[8];
				if (v2) {
					v4 = v1[3];
					v5 = v1[4];
					v6 = (v1[3] - v2) >> 1;
					v7 = v6;
					if (v6 < 0)
						v7 = -v6;
					if (v7 > 1)
						v4 = v1[3] + v6;
					v8 = (v1[4] - v1[9]) >> 1;
					v9 = v8;
					if (v8 < 0)
						v9 = -v8;
					if (v9 > 1)
						v5 = v1[4] + v8;
					result = v6;
					if (v6 < 0)
						result = -v6;
					if (result <= 10) {
						result = (v1[4] - v1[9]) >> 1;
						if (v8 < 0)
							result = -v8;
						if (result <= 10) {
							v1[72] = *(_DWORD*)&byte_5D4594[2598000];
							sub_49AA90(v1, v4, v5);
							result = v10;
							if (v1 == (_DWORD*)v10) {
								if (v6 < 0)
									v6 = -v6;
								if (v6 > 1)
									goto LABEL_30;
								if (v8 < 0)
									v8 = -v8;
								if (v8 > 1)
								LABEL_30:
									result = sub_435600(v1[3], v1[4]);
							}
						}
					}
				} else {
					v3 = v1[4];
					v1[8] = v1[3];
					v1[9] = v3;
				}
			}
			v1 = (_DWORD*)v1[92];
		} while (v1);
	}
	return result;
}

//----- (0045A840) --------------------------------------------------------
int __cdecl sub_45A840(_DWORD* a1) {
	int result; // eax
	int v2;     // eax
	int v3;     // eax

	if (sub_4356C0((int)a1, 23)) {
		sub_484BE0(a1 + 34, 128, 128, 255);
		sub_484D70_light_intensity((int)(a1 + 34), 300.0);
		result = 1;
	} else if (sub_4356C0((int)a1, 15) || a1 == *(_DWORD**)&byte_5D4594[2614252] && sub_467430() & 8) {
		sub_484BE0(a1 + 34, 255, 255, 255);
		sub_484D70_light_intensity((int)(a1 + 34), 200.0);
		result = 1;
	} else {
		v2 = a1[28];
		if (!(v2 & 2) || v2 & 0x80000) {
			result = 0;
		} else if (a1[69] == 10) {
			sub_484D70_light_intensity((int)(a1 + 34), 0.0);
			result = 1;
		} else {
			sub_484BE0(a1 + 34, 255, 255, 255);
			v3 = a1[29];
			if (v3 & 1) {
				sub_484D70_light_intensity((int)(a1 + 34), 25.0);
				result = 1;
			} else if (v3 & 2) {
				sub_484D70_light_intensity((int)(a1 + 34), 35.0);
				result = 1;
			} else {
				if (v3 & 4)
					sub_484D70_light_intensity((int)(a1 + 34), 45.0);
				result = 1;
			}
		}
	}
	return result;
}

//----- (0045A990) --------------------------------------------------------
int __cdecl sub_45A990_drawable(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 120) |= 4u;
	return result;
}

//----- (0045A9A0) --------------------------------------------------------
int __cdecl sub_45A9A0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 120) &= 0xFFFFFFFB;
	return result;
}

//----- (0045A9B0) --------------------------------------------------------
int* __cdecl sub_45A9B0(int a1, int a2) {
	int v2;      // esi
	int v3;      // ebp
	char* v4;    // eax
	char* v5;    // edi
	int* result; // eax
	int v7;      // edi
	int v8;      // ebx
	int v9;      // eax
	int v10;     // esi
	__int64 v11; // rax
	int v12;     // eax
	int* v13;    // esi
	int* v14;    // edi
	int* v15;    // edi
	int v16;     // [esp+Ch] [ebp-Ch]
	char* v17;   // [esp+10h] [ebp-8h]
	int* v18;    // [esp+14h] [ebp-4h]

	v2 = a1;
	v3 = 0;
	v16 = 0;
	v4 = sub_452270(*(_DWORD*)(a1 + 492));
	v5 = v4;
	v17 = v4;
	result = (int*)sub_437250();
	v18 = result;
	if (v5 && result) {
		if (*(_DWORD*)(a1 + 120) & 0x1000000 && !(*(_BYTE*)(a1 + 280) & 0xC)) {
			v7 = *(_DWORD*)(a2 + 12) - *(_DWORD*)(a1 + 12);
			v8 = *(_DWORD*)(a2 + 16) - *(_DWORD*)(a1 + 16);
			v9 = sub_4522A0((int)v17);
			v10 = v9;
			if (v7 < v9 && v8 < v9 && v9 > 0) {
				v11 = (__int64)sqrt((double)(v8 * v8 + v7 * v7 + 1));
				if ((int)v11 < v10) {
					v12 = 100 * (v10 - (int)v11) / v10;
					v3 = v12;
					if (v12 <= 100) {
						if (v12 < 0)
							v3 = 0;
					} else {
						v3 = 100;
					}
					v16 = 50 * (*(int*)(a1 + 12) - v18[6] - *v18) / (nox_win_width / 2);
				}
			}
			v2 = a1;
		}
		v13 = (int*)(v2 + 496);
		result = (int*)sub_452EB0(v13);
		v14 = result;
		if (v3) {
			if (result) {
				sub_452FE0((int)result, v16);
				result = (int*)sub_452F50((int)v14, v3);
			} else {
				result = sub_452300(v17);
				v15 = result;
				if (result) {
					sub_452EE0((int)result, v3);
					sub_452F80((int)v15, v16);
					result = (int*)sub_452E90(v13, (int)v15);
				}
			}
		} else if (result) {
			result = (int*)sub_4523D0(result);
		}
	}
	return result;
}

//----- (0045AB40) --------------------------------------------------------
int sub_45AB40() {
	int result; // eax
	int i;      // esi

	result = sub_45A090();
	for (i = result; result; i = result) {
		if (*(_DWORD*)(i + 492))
			sub_45A9B0(i, *(int*)&byte_5D4594[2614252]);
		result = sub_45A0A0(i);
	}
	return result;
}

//----- (0045AB80) --------------------------------------------------------
int __cdecl sub_45AB80(int a1, int a2) {
	int result; // eax

	result = a1;
	if (!(*(_BYTE*)(a1 + 112) & 2) || !(*(_DWORD*)(a1 + 116) & 0x40000) || *(_DWORD*)(a1 + 276) != 8) {
		*(_DWORD*)(a1 + 312) = *(_DWORD*)(a1 + 308);
		*(_DWORD*)(a1 + 308) = a2;
	}
	return result;
}

//----- (0045ABC0) --------------------------------------------------------
int __cdecl sub_45ABC0(const void* a1, const void* a2) {
	int v2;            // edi
	const wchar_t* v3; // esi
	const wchar_t* v4; // eax
	int result;        // eax
	int v6;            // [esp-4h] [ebp-Ch]

	v2 = *(_DWORD*)a2;
	if (dword_5d4594_1046868 == 1) {
		v3 = (const wchar_t*)sub_427240(*(_DWORD*)a1);
		v4 = (const wchar_t*)sub_427240(v2);
	} else {
		v6 = *(_DWORD*)a1;
		if (*(_BYTE*)(dword_5d4594_1047516 + 2251)) {
			v3 = (const wchar_t*)sub_424930(v6);
			v4 = (const wchar_t*)sub_424930(v2);
		} else {
			v3 = (const wchar_t*)sub_425260(v6);
			v4 = (const wchar_t*)sub_425260(v2);
		}
	}
	if (v3 && v4)
		result = _nox_wcsicmp(v3, v4);
	else
		result = 0;
	return result;
}

//----- (0045AC40) --------------------------------------------------------
int sub_45AC40() {
	int result; // eax

	*(_DWORD*)&byte_5D4594[1046880] = sub_4344A0(15, 15, 15);
	result = sub_4344A0(115, 100, 100);
	*(_DWORD*)&byte_5D4594[1046884] = result;
	return result;
}

//----- (0045AC70) --------------------------------------------------------
unsigned int sub_45AC70() {
	unsigned int result; // eax

	if (wndIsShown_sub_46ACC0(nox_win_unk1))
		result = sub_45AD70(0);
	else
		result = sub_45ACA0(0);
	return result;
}

//----- (0045ACA0) --------------------------------------------------------
int __cdecl sub_45ACA0(int a1) {
	int v1; // eax
	int v2; // ecx

	if (wndIsShown_sub_46ACC0(nox_win_unk1) || dword_5d4594_1047520 == 1)
		return 0;
	*(_DWORD*)&byte_5D4594[1046864] = 0;
	dword_5d4594_3799524 = 1;
	dword_5d4594_1046868 = dword_5d4594_1046872 != 0;
	v1 = sub_46AE00();
	v2 = nox_win_unk1;
	if (v1 == nox_win_unk1) {
		sub_46ADE0(nox_win_unk1);
		v2 = nox_win_unk1;
	}
	nox_window_set_hidden(v2, 1);
	sub_452D80(787, 100);
	if (a1) {
		dword_587000_132132 = 1;
		dword_5d4594_1046936 = 0;
		nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 1);
	}
	if (sub_477670() == 1)
		sub_477660();
	return 1;
}

//----- (0045ADF0) --------------------------------------------------------
int __cdecl sub_45ADF0(int a1) {
	int v1; // edi
	int i;  // esi
	int v3; // eax
	int k;  // esi
	int v5; // eax
	int j;  // esi
	int v7; // eax
	int v9; // [esp+Ch] [ebp-4h]

	v1 = 0;
	dword_5d4594_1046656 = sub_43F320(0) + 2;
	*(_DWORD*)&byte_5D4594[1047508] = 0;
	dword_5d4594_1047512 = 0;
	v9 = 2 * (141 / dword_5d4594_1046656) - 2;
	if (dword_5d4594_1046868 == 1) {
		for (i = sub_427300(); i; i = sub_427320(i)) {
			if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) ||
			    *(_DWORD*)(dword_5d4594_1047516 + 4 * i + 4244)) {
				if (sub_4D70C0(i)) {
					v3 = *(_DWORD*)&byte_5D4594[1047508];
					v1 = 1;
					*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1047508] + 1046960] = i;
					*(_DWORD*)&byte_5D4594[1047508] = v3 + 1;
				}
			}
		}
	} else if (a1) {
		for (j = sub_424AD0(); j; j = sub_424AF0(j)) {
			if (j != 34 && !sub_57AEA0(a1, j) &&
			    (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) ||
			     *(_DWORD*)(dword_5d4594_1047516 + 4 * j + 3696))) {
				if (sub_424A50(j, 86016))
					++dword_5d4594_1047512;
				if (!sub_424A50(j, 0x2000)) {
					v7 = *(_DWORD*)&byte_5D4594[1047508];
					v1 = 1;
					*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1047508] + 1046960] = j;
					*(_DWORD*)&byte_5D4594[1047508] = v7 + 1;
				}
			}
		}
	} else {
		for (k = sub_425330(); k; k = sub_425350(k)) {
			if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) ||
			    *(_DWORD*)(dword_5d4594_1047516 + 4 * k + 3696)) {
				v5 = *(_DWORD*)&byte_5D4594[1047508];
				v1 = 1;
				*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1047508] + 1046960] = k;
				*(_DWORD*)&byte_5D4594[1047508] = v5 + 1;
			}
		}
	}
	*(_DWORD*)&byte_5D4594[1046940] = (*(_DWORD*)&byte_5D4594[1047508] - dword_5d4594_1047512) / v9 + 1;
	qsort(&byte_5D4594[1046960], *(_DWORD*)&byte_5D4594[1047508] - dword_5d4594_1047512, 4u, sub_45ABC0);
	return v1;
}

//----- (0045B010) --------------------------------------------------------
unsigned int __cdecl sub_45B010(int a1) {
	unsigned int result; // eax

	result = sub_446360();
	if (!result) {
		result = sub_4AE3D0();
		if (!result) {
			if (a1 || (result = sub_57AF20()) == 0) {
				*(_DWORD*)&byte_5D4594[1046864] = 1;
				dword_5d4594_1046868 = dword_5d4594_1046872 != 0;
				sub_46A8C0(nox_win_unk1);
				result = (unsigned int)sub_452D80(786, 100);
			}
		}
	}
	return result;
}

//----- (0045B070) --------------------------------------------------------
int __cdecl sub_45B070(int a1, int a2) {
	if (dword_5d4594_1047520 == 1)
		return 1;
	if (a2 == 10) {
		sub_45AC70();
		return 1;
	}
	if (*(_DWORD*)&byte_5D4594[2614252] && !sub_478030() && !sub_47A260() &&
	    (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) == 2) {
		return 1;
	}
	if (a2 != 5)
		return 0;
	nox_window_set_hidden(*(int*)&byte_5D4594[1046944], 0);
	if (dword_587000_132132) {
		if (dword_5d4594_1046936 + 1 < *(int*)&byte_5D4594[1046940]) {
			++dword_5d4594_1046936;
		} else {
			dword_5d4594_1046932 = 0;
			dword_587000_132132 = 0;
			nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 0);
		}
		if (dword_5d4594_1046872)
			**(_DWORD**)(dword_5d4594_1046924 + 96) = sub_45B200;
		else
			**(_DWORD**)(dword_5d4594_1046924 + 96) = sub_45B1F0;
		dword_5d4594_1046868 = 2;
		*(_DWORD*)(*(_DWORD*)(dword_5d4594_1046924 + 96) + 12) = sub_430B40_get_mouse_prev_seq();
	LABEL_23:
		sub_452D80(788, 100);
		return 1;
	}
	if (dword_5d4594_1046932 < *(int*)&byte_5D4594[1047508] - dword_5d4594_1047512 - 1) {
		++dword_5d4594_1046932;
		if (dword_5d4594_1046872)
			**(_DWORD**)(dword_5d4594_1046924 + 96) = sub_45B200;
		else
			**(_DWORD**)(dword_5d4594_1046924 + 96) = sub_45B1F0;
		dword_5d4594_1046868 = 2;
		*(_DWORD*)(*(_DWORD*)(dword_5d4594_1046924 + 96) + 12) = sub_430B40_get_mouse_prev_seq();
		goto LABEL_23;
	}
	return 1;
}

//----- (0045B1F0) --------------------------------------------------------
int sub_45B1F0() {
	int result; // eax

	result = 0;
	dword_5d4594_1046868 = 0;
	dword_5d4594_1046872 = 0;
	return result;
}

//----- (0045B200) --------------------------------------------------------
int sub_45B200() {
	int result; // eax

	result = 1;
	dword_5d4594_1046868 = 1;
	dword_5d4594_1046872 = 1;
	return result;
}

//----- (0045B210) --------------------------------------------------------
int __cdecl sub_45B210(int a1, int a2) {
	if (dword_5d4594_1047520 == 1)
		return 1;
	if (a2 == 10) {
		sub_45AC70();
		return 1;
	}
	if (*(_DWORD*)&byte_5D4594[2614252] && !sub_478030() && !sub_47A260() &&
	    (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) == 2) {
		return 1;
	}
	if (a2 != 5)
		return 0;
	nox_window_set_hidden(*(int*)&dword_5d4594_1046948, 0);
	if (!dword_587000_132132) {
		if (*(int*)&dword_5d4594_1046932 < *(int*)&byte_5D4594[1047508] - *(int*)&dword_5d4594_1047512) {
			if (*(int*)&dword_5d4594_1046932 <= 0) {
				dword_587000_132132 = 1;
				dword_5d4594_1046936 = *(_DWORD*)&byte_5D4594[1046940] - 1;
				nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 1);
			} else {
				--dword_5d4594_1046932;
			}
		} else {
			dword_587000_132132 = 1;
			dword_5d4594_1046936 = 0;
			nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 1);
		}
	LABEL_18:
		if (dword_5d4594_1046872)
			**(_DWORD**)(dword_5d4594_1046928 + 96) = sub_45B200;
		else
			**(_DWORD**)(dword_5d4594_1046928 + 96) = sub_45B1F0;
		dword_5d4594_1046868 = 3;
		*(_DWORD*)(*(_DWORD*)(dword_5d4594_1046928 + 96) + 12) = sub_430B40_get_mouse_prev_seq();
		sub_452D80(788, 100);
		return 1;
	}
	if (dword_5d4594_1046936) {
		--dword_5d4594_1046936;
		goto LABEL_18;
	}
	return 1;
}

//----- (0045B360) --------------------------------------------------------
int __cdecl sub_45B360(_DWORD* a1, unsigned int a2) {
	int v2; // esi

	v2 = 0;
	if (dword_5d4594_1047520 == 1 || *(_DWORD*)&byte_5D4594[2614252] && !sub_478030() && !sub_47A260() &&
							(*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) == 2) {
		return 1;
	}
	if (a2 != 5) {
		if (a2 <= 5 || a2 > 7)
			return 0;
		return 1;
	}
	if (*a1 == 1310) {
		if (dword_5d4594_1046872) {
			dword_5d4594_1046868 = 0;
			dword_5d4594_1046872 = 0;
			if (!sub_45ADF0(*(unsigned __int8*)(dword_5d4594_1047516 + 2251))) {
				dword_5d4594_1046868 = 1;
				dword_5d4594_1046872 = 1;
				sub_45ADF0(*(unsigned __int8*)(dword_5d4594_1047516 + 2251));
				sub_452D80(925, 100);
				return 1;
			}
			v2 = 1;
		}
		if (!dword_587000_132132 || dword_5d4594_1046936 || v2 == 1) {
			dword_587000_132132 = 1;
			dword_5d4594_1046936 = 0;
			sub_452D80(788, 100);
			dword_5d4594_1046868 = 3;
			*(_DWORD*)(*(_DWORD*)(dword_5d4594_1046928 + 96) + 12) =
			    sub_430B40_get_mouse_prev_seq();
			**(_DWORD**)(dword_5d4594_1046928 + 96) = sub_45B1F0;
			nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_1046948, 0);
			sub_46ADE0(nox_win_unk1);
			sub_477660();
		}
		return 1;
	}
	if (*a1 != 1320)
		return 1;
	if (dword_5d4594_1046872 != 1) {
		dword_5d4594_1046868 = 1;
		dword_5d4594_1046872 = 1;
		if (!sub_45ADF0(*(unsigned __int8*)(dword_5d4594_1047516 + 2251))) {
			dword_5d4594_1046868 = 0;
			dword_5d4594_1046872 = 0;
			sub_45ADF0(*(unsigned __int8*)(dword_5d4594_1047516 + 2251));
			sub_452D80(925, 100);
			return 1;
		}
		v2 = 1;
	}
	if (dword_587000_132132 && !dword_5d4594_1046936 && v2 != 1)
		return 1;
	dword_587000_132132 = 1;
	dword_5d4594_1046936 = 0;
	sub_452D80(788, 100);
	if (v2 == 1) {
		dword_5d4594_1046868 = 2;
		*(_DWORD*)(*(_DWORD*)(dword_5d4594_1046924 + 96) + 12) = sub_430B40_get_mouse_prev_seq();
		**(_DWORD**)(dword_5d4594_1046924 + 96) = sub_45B200;
	} else {
		dword_5d4594_1046868 = 3;
		*(_DWORD*)(*(_DWORD*)(dword_5d4594_1046928 + 96) + 12) = sub_430B40_get_mouse_prev_seq();
		**(_DWORD**)(dword_5d4594_1046928 + 96) = sub_45B200;
	}
	nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_1046948, 0);
	sub_46ADE0(nox_win_unk1);
	sub_477660();
	return 1;
}

//----- (0045B5F0) --------------------------------------------------------
int __cdecl sub_45B5F0(int a1, unsigned int a2, unsigned int a3) {
	int v3;        // ebp
	int v4;        // edi
	int v5;        // esi
	int result;    // eax
	bool v7;       // sf
	signed int v8; // ebp
	int v9;        // eax
	int v10;       // ecx
	char v11;      // al
	int v12;       // eax
	int v13;       // eax
	int v14;       // [esp+10h] [ebp-4h]

	v3 = a3 >> 16;
	v4 = (unsigned __int16)a3;
	if (dword_5d4594_1047520 == 1 || *(_DWORD*)&byte_5D4594[2614252] && !sub_478030() && !sub_47A260() &&
							(*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) == 2) {
		return 1;
	}
	if (!dword_587000_132132) {
		if (a2 >= 5) {
			if (a2 <= 8)
				return 1;
			if (a2 == 11) {
			LABEL_47:
				sub_45AC70();
				return 1;
			}
		}
		return 0;
	}
	dword_5d4594_1046656 = sub_43F320(0) + 2;
	v5 = 141 / dword_5d4594_1046656 - 1;
	sub_46AA20(a1, &v14, &a3);
	switch (a2) {
	case 5u:
		if (*(_DWORD*)&byte_5D4594[2614252] && (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) == 2)
			return 1;
		*(_DWORD*)&byte_5D4594[1047536] = v3;
		v7 = (int)(-19 - a3 + v3) < 0;
		v8 = -19 - a3 + v3;
		*(_DWORD*)&byte_5D4594[1047532] = v4;
		if (v7) {
			dword_587000_132136 = -1;
			return 1;
		}
		v9 = v8 / *(int*)&dword_5d4594_1046656;
		if (v8 / *(int*)&dword_5d4594_1046656 >= v5)
			goto LABEL_14;
		if (v4 - v14 > 145)
			v9 += v5;
		dword_587000_132136 = 2 * v5 * dword_5d4594_1046936 + v9;
		sub_46ADC0(a1);
		v10 = dword_587000_132136;
		if (dword_587000_132136 >= *(int*)&byte_5D4594[1047508] - dword_5d4594_1047512)
			goto LABEL_14;
		v11 = *(_BYTE*)(dword_5d4594_1047516 + 2251);
		if (!v11 && !dword_5d4594_1046868) {
			dword_5d4594_1047528 =
			    *(_DWORD*)&byte_5D4594[4 * dword_587000_132136 + 1046960];
			sub_477640(*(int*)&dword_5d4594_1047528, 1);
			sub_452D80(793, 100);
			return 1;
		}
		if (v11 != 2 || dword_5d4594_1046868 != 1) {
			if (dword_5d4594_1046868)
				return 1;
			dword_5d4594_1047528 =
			    *(_DWORD*)&byte_5D4594[4 * dword_587000_132136 + 1046960];
			sub_477640(*(int*)&dword_5d4594_1047528, 1);
			sub_452D80(793, 100);
			result = 1;
		} else {
			if (!*(_DWORD*)(dword_5d4594_1047516 + 4232)) {
				if (!nox_common_gameFlags_check_40A5C0(0x2000) ||
				    nox_common_gameFlags_check_40A5C0(4096)) {
					sub_46ADE0(a1);
					sub_45B930(*(int*)&dword_587000_132136);
					dword_5d4594_1047528 = 0;
				LABEL_14:
					dword_587000_132136 = -1;
					return 1;
				}
				v10 = dword_587000_132136;
			}
			dword_5d4594_1047528 = *(_DWORD*)&byte_5D4594[4 * v10 + 1046960] + 74;
			sub_477640(*(int*)&dword_5d4594_1047528, 1);
			sub_452D80(793, 100);
			result = 1;
		}
		break;
	case 6u:
	case 7u:
		if ((int)dword_587000_132136 >= 0) {
			v12 = *(_DWORD*)&byte_5D4594[1047532] - v4;
			if (*(int*)&byte_5D4594[1047532] - v4 < 0)
				v12 = v4 - *(_DWORD*)&byte_5D4594[1047532];
			if (v12 >= 5)
				goto LABEL_52;
			v13 = *(_DWORD*)&byte_5D4594[1047536] - v3;
			if (*(int*)&byte_5D4594[1047536] - v3 < 0)
				v13 = v3 - *(_DWORD*)&byte_5D4594[1047536];
			if (v13 >= 5)
			LABEL_52:
				sub_45DCA0(*(int*)&dword_5d4594_1047528, 0, v4, v3, 0);
			else
				sub_45B930(*(int*)&dword_587000_132136);
		}
		if (sub_46AE00())
			sub_46ADE0(a1);
		sub_477660();
		return 1;
	case 8u:
		return 1;
	case 0xBu:
		goto LABEL_47;
	default:
		return 0;
	}
	return result;
}

//----- (0045B930) --------------------------------------------------------
int __cdecl sub_45B930(int a1) {
	dword_587000_132132 = 0;
	dword_5d4594_1046932 = a1;
	dword_5d4594_1046936 = 99;
	if (dword_5d4594_1046872)
		**(_DWORD**)(dword_5d4594_1046924 + 96) = sub_45B200;
	else
		**(_DWORD**)(dword_5d4594_1046924 + 96) = sub_45B1F0;
	dword_5d4594_1046868 = 2;
	*(_DWORD*)(*(_DWORD*)(dword_5d4594_1046924 + 96) + 12) = sub_430B40_get_mouse_prev_seq();
	sub_452D80(788, 100);
	nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 0);
	nox_window_set_hidden(*(int*)&byte_5D4594[1046944], 0);
	return nox_window_set_hidden(*(int*)&dword_5d4594_1046948, 0);
}

int sub_45BD30(int a1, int a2) { return 1; }

//----- (0045B9D0) --------------------------------------------------------
int sub_45B9D0() {
	int result; // eax
	_DWORD* v1; // esi
	_DWORD* v2; // esi
	char* v3;   // eax
	char* v4;   // eax

	dword_5d4594_1047516 = *(_DWORD*)&byte_5D4594[2618908];
	result = sub_42F970("ArrowNW");
	*(_DWORD*)&byte_5D4594[1046888] = result;
	if (!result)
		return 0;

	result = sub_42F970("ArrowN");
	*(_DWORD*)&byte_5D4594[1046892] = result;
	if (!result)
		return 0;

	result = sub_42F970("ArrowNE");
	*(_DWORD*)&byte_5D4594[1046896] = result;
	if (!result)
		return 0;

	result = sub_42F970("ArrowW");
	*(_DWORD*)&byte_5D4594[1046900] = result;
	if (!result)
		return 0;

	result = sub_42F970("ArrowE");
	*(_DWORD*)&byte_5D4594[1046908] = result;
	if (!result)
		return 0;

	result = sub_42F970("ArrowSW");
	*(_DWORD*)&byte_5D4594[1046912] = result;
	if (!result)
		return 0;

	result = sub_42F970("ArrowS");
	*(_DWORD*)&byte_5D4594[1046916] = result;
	if (!result)
		return 0;

	result = sub_42F970("ArrowSE");
	*(_DWORD*)&byte_5D4594[1046920] = result;
	if (!result)
		return 0;

	result = sub_42F970("BookOfKnowledge");
	*(_DWORD*)&byte_5D4594[1046856] = result;
	if (!result)
		return 0;

	result = sub_42F970("GuideTabLit");
	*(_DWORD*)&byte_5D4594[1046660] = result;
	if (!result)
		return 0;

	result = sub_42F970("SpellTabLit");
	*(_DWORD*)&byte_5D4594[1046644] = result;
	if (!result)
		return 0;

	result = sub_42FA20("BookPageForward");
	dword_5d4594_1046924 = result;
	if (!result)
		return 0;

	**(_DWORD**)(result + 96) = sub_45B1F0;
	result = sub_42FA20("BookPageBackward");
	dword_5d4594_1046928 = result;
	if (!result)
		return 0;

	**(_DWORD**)(result + 96) = sub_45B1F0;
	nox_win_unk1 = nox_window_new(0, 1196, 5, nox_win_height - 323, 285, 168, 0);
	nox_window_set_all_funcs(nox_win_unk1, sub_45B5F0, sub_45BD40, 0);
	nox_window_set_hidden(nox_win_unk1, 1);
	result = nox_window_new(nox_win_unk1, 8, 257, 15, 27, 40, 0);
	v1 = (_DWORD*)result;
	if (!result)
		return 0;

	nox_window_set_all_funcs((_DWORD*)result, sub_45B360, sub_45BD30, sub_45CF00);
	*v1 = 1320;
	result = nox_window_new(nox_win_unk1, 8, 253, 61, 27, 40, 0);
	v2 = (_DWORD*)result;
	if (!result)
		return 0;

	nox_window_set_all_funcs((_DWORD*)result, sub_45B360, sub_45BD30, sub_45CF00);
	*v2 = 1310;
	*(_DWORD*)&byte_5D4594[1046944] = nox_window_new(nox_win_unk1, 136, 24, 138, 20, 20, 0);
	nox_window_set_all_funcs(*(_DWORD**)&byte_5D4594[1046944], sub_45B210, 0, 0);
	v3 = sub_42F970("ArrowW");
	sub_46AE60(*(int*)&byte_5D4594[1046944], (int)v3);
	dword_5d4594_1046948 = nox_window_new(nox_win_unk1, 136, 233, 138, 20, 20, 0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1046948, sub_45B070, 0, 0);
	v4 = sub_42F970("ArrowE");
	sub_46AE60(*(int*)&dword_5d4594_1046948, (int)v4);
	dword_5d4594_1046952 = nox_window_new(nox_win_unk1, 8, 63, 19, 30, 30, 0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1046952, sub_45CC10, sub_45CB30, 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_1046952, 1);
	*(_DWORD*)&byte_5D4594[1046956] = nox_window_new(0, 40, 0, 0, 30, 30, 0);
	nox_window_set_all_funcs(*(_DWORD**)&byte_5D4594[1046956], 0, sub_45C7D0, 0);
	nox_window_set_hidden(*(int*)&byte_5D4594[1046956], 1);
	dword_5d4594_1046868 = 0;
	dword_5d4594_1046872 = 0;
	dword_587000_132132 = 1;
	dword_5d4594_1046936 = 0;

	return 1;
}

//----- (0045CB30) --------------------------------------------------------
int __cdecl sub_45CB30(_DWORD* a1) {
	int v1; // eax
	int v2; // esi
	int v4; // [esp+4h] [ebp-8h]
	int v5; // [esp+8h] [ebp-4h]

	if (dword_5d4594_1046868) {
		if (dword_5d4594_1046868 != 1 || *(_BYTE*)(dword_5d4594_1047516 + 2251) != 2 ||
		    !*(_DWORD*)(dword_5d4594_1047516 + 4232) &&
			(!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096))) {
			return 1;
		}
		v1 = sub_424A90(*(_DWORD*)&byte_5D4594[4 * dword_5d4594_1046932 + 1046960] + 74);
	} else if (*(_BYTE*)(dword_5d4594_1047516 + 2251)) {
		v1 = sub_424A90(*(_DWORD*)&byte_5D4594[4 * dword_5d4594_1046932 + 1046960]);
	} else {
		v1 = sub_425310(*(_DWORD*)&byte_5D4594[4 * dword_5d4594_1046932 + 1046960], 0);
	}
	v2 = v1;
	if (v1) {
		nox_client_wndGetPosition_46AA60(a1, &v5, &v4);
		nox_client_drawImageAt_47D2C0(v2, v5, v4);
	}
	return 1;
}

//----- (0045CC10) --------------------------------------------------------
int __cdecl sub_45CC10(_DWORD* a1, int a2, unsigned int a3) {
	int result; // eax
	int v4;     // ebp
	char v5;    // al
	char v6;    // al

	if (*(_DWORD*)&byte_5D4594[2614252] && (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) == 2)
		return 1;
	v4 = a3 >> 16;
	if (dword_5d4594_1046868 == 1) {
		v5 = *(_BYTE*)(dword_5d4594_1047516 + 2251);
		if (v5 == 1 || !v5 ||
		    !nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) &&
			!*(_DWORD*)(dword_5d4594_1047516 + 4232)) {
			return 0;
		}
	}
	switch (a2) {
	case 5:
		if (sub_46AE00() || dword_5d4594_1047540)
			goto LABEL_44;
		v6 = *(_BYTE*)(dword_5d4594_1047516 + 2251);
		if (!v6 && !dword_5d4594_1046868) {
			dword_5d4594_1047540 =
			    *(_DWORD*)&byte_5D4594[4 * dword_5d4594_1046932 + 1046960];
			sub_477640(*(int*)&dword_5d4594_1047540, 1);
		LABEL_22:
			sub_46ADC0((int)a1);
			sub_452D80(793, 100);
			return 1;
		}
		if (v6 == 2 && dword_5d4594_1046868 == 1) {
			dword_5d4594_1047540 =
			    *(_DWORD*)&byte_5D4594[4 * dword_5d4594_1046932 + 1046960] + 74;
			sub_477640(*(int*)&dword_5d4594_1047540, 1);
			goto LABEL_22;
		}
		if (dword_5d4594_1046868)
			goto LABEL_44;
		dword_5d4594_1047540 = *(_DWORD*)&byte_5D4594[4 * dword_5d4594_1046932 + 1046960];
		if (!sub_424A50(*(int*)&dword_5d4594_1047540, 86016)) {
			sub_477640(*(int*)&dword_5d4594_1047540, 1);
			goto LABEL_22;
		}
		dword_5d4594_1047540 = 0;
		return 1;
	case 6:
	case 7:
		if (!dword_5d4594_1047540)
			goto LABEL_44;
		if (!sub_46AAB0(a1, (unsigned __int16)a3, v4)) {
			if (sub_460650()) {
				sub_45D9D0(*(int*)&dword_5d4594_1047540);
			} else if (sub_4611A0()) {
				sub_4611B0();
			} else {
				sub_45DCA0(*(int*)&dword_5d4594_1047540, 0, (unsigned __int16)a3, v4, 0);
			}
		LABEL_42:
			dword_5d4594_1047540 = 0;
			sub_46ADE0((int)a1);
			goto LABEL_43;
		}
		if (*(_BYTE*)(dword_5d4594_1047516 + 2251)) {
			if (sub_460650()) {
				sub_45DF60(0, 0);
				dword_5d4594_1047540 = 0;
				sub_46ADE0((int)a1);
				sub_477660();
				return 1;
			}
			if (!sub_424A50(*(int*)&dword_5d4594_1047540, 1536)) {
				sub_45DF60(*(int*)&dword_5d4594_1047540, 0);
				sub_477660();
				return 1;
			}
			if (sub_45DF60(*(int*)&dword_5d4594_1047540, 1))
				goto LABEL_42;
		} else {
			if (sub_4611A0()) {
				sub_45DFC0(0);
				dword_5d4594_1047540 = 0;
				sub_46ADE0((int)a1);
				sub_477660();
				return 1;
			}
			if (sub_45DFC0(*(int*)&dword_5d4594_1047540))
				goto LABEL_42;
		}
	LABEL_43:
		sub_477660();
	LABEL_44:
		result = 1;
		break;
	case 8:
		goto LABEL_44;
	default:
		return 0;
	}
	return result;
}

//----- (0045CFA0) --------------------------------------------------------
int sub_45CFA0() {
	int result; // eax

	if (dword_587000_132132)
		result = 0;
	else
		result = *(_DWORD*)&byte_5D4594[4 * dword_5d4594_1046932 + 1046960];
	return result;
}

//----- (0045CFC0) --------------------------------------------------------
int sub_45CFC0() { return ((unsigned __int8)~sub_46ADA0(nox_win_unk1) >> 4) & 1; }

//----- (0045CFE0) --------------------------------------------------------
void __cdecl sub_45CFE0(int a1, int a2, int a3, int a4) {
	int v4;               // ebx
	int v5;               // ebp
	int v6;               // esi
	int* v7;              // edi
	int v8;               // eax
	int v9;               // esi
	unsigned __int8* v10; // eax
	int v11;              // [esp+14h] [ebp+4h]

	v4 = *(_DWORD*)&byte_5D4594[2618908];
	if (!*(_DWORD*)&byte_5D4594[2618908])
		return;
	v5 = a1;
	if (sub_57AEA0(*(unsigned __int8*)(*(_DWORD*)&byte_5D4594[2618908] + 2251), a1) == 9)
		return;
	*(_DWORD*)(v4 + 4 * a1 + 3696) = a2;
	if (sub_424A50(a1, 4096)) {
		v11 = 0x2000;
		goto LABEL_9;
	}
	if (sub_424A50(a1, 0x4000)) {
		v11 = 0x8000;
		goto LABEL_9;
	}
	if (sub_424A50(a1, 0x10000)) {
		v11 = 0x20000;
	LABEL_9:
		v6 = 1;
		v7 = (int*)(v4 + 3700);
		do {
			if (sub_424A50(v6, v11) && sub_424B50(v6))
				*v7 = a2;
			++v6;
			++v7;
		} while (v6 < 137);
	}
	dword_5d4594_1046868 = 0;
	dword_5d4594_1046872 = 0;
	sub_45ADF0(*(unsigned __int8*)(v4 + 2251));
	if (v5 == 34) {
		v8 = 1;
		if (*(_DWORD*)(v4 + 3832) != 1 || !a3)
			v8 = 0;
		sub_460EC0(v8);
	} else if (a3) {
		v9 = 0;
		v10 = &byte_5D4594[1046960];
		do {
			if (*(_DWORD*)v10 == v5)
				break;
			v10 += 4;
			++v9;
		} while ((int)v10 < (int)&byte_5D4594[1047508]);
		if (v9 != 137) {
			sub_45ACA0(0);
			sub_45B930(v9);
			sub_45B010(0);
			sub_499CF0((int*)2, v5, a4);
		}
	}
}

//----- (0045D140) --------------------------------------------------------
void __cdecl sub_45D140(int a1, int a2) {
	int v2;              // edx
	unsigned __int8* v3; // esi
	_DWORD* v4;          // ecx
	int v5;              // eax
	int* v6;             // ecx
	int v7;              // eax
	int v8;              // esi
	unsigned __int8* v9; // eax

	v2 = *(_DWORD*)&byte_5D4594[2618908];
	if (*(_DWORD*)&byte_5D4594[2618908]) {
		v3 = &byte_587000[132124];
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[2618908] + 4 * a1 + 4244) = 1;
		if (*(_DWORD*)&byte_587000[132124]) {
			do {
				v4 = *(_DWORD**)v3;
				if (a1 == **(_DWORD**)v3) {
					v5 = v4[1];
					v6 = v4 + 1;
					if (v5) {
						do {
							++v6;
							*(_DWORD*)(v2 + 4 * v5 + 4244) = 1;
							v5 = *v6;
						} while (*v6);
					}
				}
				v7 = *((_DWORD*)v3 + 1);
				v3 += 4;
			} while (v7);
		}
		dword_5d4594_1046868 = 1;
		dword_5d4594_1046872 = 1;
		sub_45ADF0(*(unsigned __int8*)(v2 + 2251));
		if (a2) {
			v8 = 0;
			v9 = &byte_5D4594[1046960];
			do {
				if (*(_DWORD*)v9 == a1)
					break;
				v9 += 4;
				++v8;
			} while ((int)v9 < (int)&byte_5D4594[1047124]);
			if (v8 != 41) {
				sub_45ACA0(0);
				sub_45B930(v8);
				sub_45B010(0);
				sub_499CF0((int*)4, a1, 0);
			}
		}
	}
}

//----- (0045D200) --------------------------------------------------------
int* __cdecl sub_45D200(int* a1, int a2, int2* a3) {
	int* result; // eax
	int v4;      // ecx
	int v5;      // ecx

	sub_45AD70(1);
	sub_46A9B0(nox_win_unk1, a3->field_0, a3->field_4);
	result = a1;
	if (a1 == (int*)2 || a1 == (int*)4) {
		v5 = 0;
		result = (int*)&byte_5D4594[1046960];
		do {
			if (*result == a2)
				break;
			++result;
			++v5;
		} while ((int)result < (int)&byte_5D4594[1047508]);
		if (v5 != 137)
			result = (int*)sub_45B930(v5);
	} else if (a1 == (int*)3) {
		v4 = 0;
		result = (int*)&byte_5D4594[1046960];
		do {
			if (*result == a2)
				break;
			++result;
			++v4;
		} while ((int)result < (int)&byte_5D4594[1046984]);
		if (v4 != 6)
			result = (int*)sub_45B930(v4);
	}
	return result;
}

//----- (0045D290) --------------------------------------------------------
char* __cdecl sub_45D290(int a1, char* a2, int a3) {
	char* result; // eax
	int v4;       // esi

	result = sub_417040(*(int*)&byte_5D4594[2616328]);
	if (result) {
		dword_5d4594_1046868 = 0;
		dword_5d4594_1046872 = 0;
		sub_45ADF0((unsigned __int8)result[2251]);
		result = a2;
		if (a2) {
			v4 = 0;
			result = (char*)&byte_5D4594[1046960];
			do {
				if (*(_DWORD*)result == a1)
					break;
				result += 4;
				++v4;
			} while ((int)result < (int)&byte_5D4594[1046984]);
			if (v4 != 6) {
				sub_45ACA0(0);
				sub_45B930(v4);
				sub_45B010(0);
				result = (char*)a3;
				if (a3)
					result = (char*)sub_499CF0((int*)3, a1, a3);
			}
		}
	}
	return result;
}

//----- (0045D320) --------------------------------------------------------
int __cdecl sub_45D320(int a1) {
	int v1;     // ebx
	int result; // eax
	int v3;     // ebp
	int v4;     // esi
	_DWORD* v5; // edi

	v1 = *(_DWORD*)&byte_5D4594[2618908];
	result = sub_45ACA0(1);
	if (v1) {
		*(_DWORD*)(v1 + 4 * a1 + 3696) = 0;
		sub_461360(a1);
		if (sub_424A50(a1, 4096)) {
			v3 = 0x2000;
		} else if (sub_424A50(a1, 0x4000)) {
			v3 = 0x8000;
		} else {
			if (!sub_424A50(a1, 0x10000))
				return sub_45ADF0(*(unsigned __int8*)(v1 + 2251));
			v3 = 0x20000;
		}
		v4 = 1;
		v5 = (_DWORD*)(v1 + 3700);
		do {
			if (sub_424A50(v4, v3)) {
				if (sub_424B50(v4)) {
					*v5 = 0;
					sub_461360(v4);
				}
			}
			++v4;
			++v5;
		} while (v4 < 137);
		return sub_45ADF0(*(unsigned __int8*)(v1 + 2251));
	}
	return result;
}

//----- (0045D400) --------------------------------------------------------
int __cdecl sub_45D400(int a1) {
	int v1;              // edi
	int result;          // eax
	unsigned __int8* v3; // ebp
	_DWORD* v4;          // esi
	int v5;              // eax
	_DWORD* i;           // esi
	int v7;              // eax

	v1 = *(_DWORD*)&byte_5D4594[2618908];
	result = sub_45ACA0(1);
	if (v1) {
		*(_DWORD*)(v1 + 4 * a1 + 4244) = 0;
		sub_461360(a1 + 74);
		v3 = &byte_587000[132124];
		if (*(_DWORD*)&byte_587000[132124]) {
			do {
				v4 = *(_DWORD**)v3;
				if (a1 == **(_DWORD**)v3) {
					v5 = v4[1];
					for (i = v4 + 1; v5; ++i) {
						*(_DWORD*)(v1 + 4 * v5 + 4244) = 0;
						sub_461360(*i + 74);
						v5 = i[1];
					}
				}
				v7 = *((_DWORD*)v3 + 1);
				v3 += 4;
			} while (v7);
		}
		result = sub_45ADF0(*(unsigned __int8*)(v1 + 2251));
	}
	return result;
}

//----- (0045D4A0) --------------------------------------------------------
char* __cdecl sub_45D4A0(int a1) {
	char* result; // eax

	sub_45ACA0(1);
	sub_4611E0(a1, 0, 0);
	if (dword_5d4594_1047516)
		*(_DWORD*)(dword_5d4594_1047516 + 4 * a1 + 3696) = 0;
	sub_461360(a1);
	result = sub_417040(*(int*)&byte_5D4594[2616328]);
	if (result)
		result = (char*)sub_45ADF0((unsigned __int8)result[2251]);
	return result;
}

//----- (0045D500) --------------------------------------------------------
int __cdecl sub_45D500(int a1) {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[1046864];
	if (a1) {
		if (*(_DWORD*)&byte_5D4594[1046864])
			result = nox_window_set_hidden(nox_win_unk1, 0);
	} else if (*(_DWORD*)&byte_5D4594[1046864]) {
		result = sub_47A260();
		if (!result)
			result = nox_window_set_hidden(nox_win_unk1, 1);
	}
	return result;
}

//----- (0045D550) --------------------------------------------------------
_DWORD* __cdecl sub_45D550(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	if (a1)
		result = (_DWORD*)nox_client_wndGetPosition_46AA60(*(_DWORD**)&dword_5d4594_1046952, a1, a1 + 1);
	return result;
}

//----- (0045D570) --------------------------------------------------------
int __cdecl sub_45D570(int a1, int a2) {
	int result; // eax
	double v3;  // st7
	int2 a4;    // [esp+Ch] [ebp-10h]
	int2 a3;    // [esp+14h] [ebp-8h]

	result = dword_5d4594_1047520;
	if (dword_5d4594_1047520 != 1) {
		sub_4606B0();
		*(_DWORD*)&byte_5D4594[1046612] = sub_45E180();
		if (a1 != 2 || (result = sub_424A50(a2, 86016)) == 0) {
			result = sub_4612D0(a2);
			if (result != 1) {
				if (a1 == 2 || a1 == 4) {
					result = sub_461250();
				} else {
					if (a1 != 3)
						return result;
					result = sub_4612A0();
				}
				*(_DWORD*)&byte_5D4594[1046852] = result;
				if (result != -1) {
					dword_5d4594_1047520 = 1;
					if (a1 == 2 || a1 == 3) {
						dword_5d4594_1046868 = 0;
						dword_5d4594_1046872 = 0;
					} else {
						dword_5d4594_1046868 = 1;
						dword_5d4594_1046872 = 1;
					}
					sub_45D550(&byte_5D4594[1046844]);
					*(float*)&dword_5d4594_1046636 = (double)*(int*)&byte_5D4594[1046844];
					*(float*)&byte_5D4594[1046640] = (double)*(int*)&byte_5D4594[1046848];
					sub_46A9B0(*(_DWORD**)&byte_5D4594[1046956], *(int*)&byte_5D4594[1046844],
						   *(int*)&byte_5D4594[1046848]);
					sub_461320(*(int*)&byte_5D4594[1046852], &byte_5D4594[1046668]);
					a3.field_0 = 400;
					a4.field_4 = 400;
					*(_DWORD*)&byte_5D4594[1047524] = a2;
					*(_DWORD*)&byte_5D4594[1046652] = a1 == 3;
					*(_DWORD*)&byte_5D4594[1046676] = a1;
					dword_587000_80828 = 1;
					a3.field_4 = -500;
					a4.field_0 = 350;
					*(_DWORD*)&byte_5D4594[1046680] = 0;
					sub_4BEDE0((int2*)&byte_5D4594[1046844], (int2*)&byte_5D4594[1046668], &a3, &a4,
						   19, 0.0, sub_45D7D0, 0);
					*(_DWORD*)&byte_5D4594[1046628] = 0;
					*(float*)&byte_5D4594[1046620] =
					    *(float*)&byte_5D4594[1046692] - *(float*)&byte_5D4594[1046684];
					*(float*)&byte_5D4594[1046624] =
					    *(float*)&byte_5D4594[1046696] - *(float*)&byte_5D4594[1046688];
					sub_509F20((float2*)&byte_5D4594[1046620]);
					if (nox_win_width < 1000) {
						if (nox_win_width < 750)
							v3 = 6.0;
						else
							v3 = 8.0;
					} else {
						v3 = 10.0;
					}
					*(float*)&byte_5D4594[1046620] = *(float*)&byte_5D4594[1046620] * v3;
					*(float*)&byte_5D4594[1046624] = *(float*)&byte_5D4594[1046624] * v3;
					nox_window_set_hidden(*(int*)&byte_5D4594[1046956], 0);
					sub_46A8C0(*(int*)&byte_5D4594[1046956]);
					if (nox_common_gameFlags_check_40A5C0(2048))
						sub_57AF30(0, a1);
					*(_DWORD*)&byte_5D4594[1046648] = sub_430B40_get_mouse_prev_seq();
					if (!nox_common_gameFlags_check_40A5C0(2048) || sub_446360() == 1 ||
					    (result = sub_4DB1B0(), result == 1))
						result = sub_45D870();
				}
			}
		}
	}
	return result;
}

//----- (0045D7D0) --------------------------------------------------------
int __cdecl sub_45D7D0(int* a1, int* a2) {
	int result; // eax
	double v3;  // st7

	result = *(_DWORD*)&byte_5D4594[1046680];
	if (*(int*)&byte_5D4594[1046680] < 20) {
		result = *(_DWORD*)&byte_5D4594[1046680] + 1;
		*(float*)&byte_5D4594[8 * result + 1046676] = (double)*a1;
		*(float*)&byte_5D4594[8 * result + 1046680] = (double)a1[1];
		*(float*)&byte_5D4594[8 * result + 1046684] = (double)*a2;
		v3 = (double)a2[1];
		*(_DWORD*)&byte_5D4594[1046680] = result;
		*(float*)&byte_5D4594[8 * result + 1046688] = v3;
	}
	return result;
}

//----- (0045D810) --------------------------------------------------------
int sub_45D810() {
	int result; // eax

	result = dword_5d4594_1047520;
	if (dword_5d4594_1047520) {
		dword_5d4594_1047520 = 0;
		nox_window_set_hidden(*(int*)&byte_5D4594[1046956], 1);
		*(_DWORD*)&byte_5D4594[1046648] = 0;
		sub_45E110(*(int*)&byte_5D4594[1046612]);
		result = nox_common_gameFlags_check_40A5C0(2048);
		if (result) {
			sub_57B0A0();
			result = sub_413A00(0);
		}
	}
	return result;
}

//----- (0045D9B0) --------------------------------------------------------
int sub_45D9B0() { return dword_5d4594_1047520; }

//----- (0045D9C0) --------------------------------------------------------
BOOL sub_45D9C0() { return *(_DWORD*)&byte_5D4594[1047916] != 0; }

//----- (0045D9D0) --------------------------------------------------------
int __cdecl sub_45D9D0(int a1) {
	if (*(_DWORD*)&byte_5D4594[1047916])
		return 0;
	*(_DWORD*)&byte_5D4594[1047916] = a1;
	byte_5D4594[1047920] = 0;
	sub_4160D0(5);
	*(_DWORD*)&byte_5D4594[1047928] = 0;
	*(_DWORD*)&byte_5D4594[1047924] = 0;
	return 1;
}

//----- (0045DA10) --------------------------------------------------------
int __cdecl sub_45DA10(int a1) {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[1047916])
		return 0;
	*(_DWORD*)&byte_5D4594[1047916] = a1;
	byte_5D4594[1047920] = 0;
	sub_4160D0(5);
	result = 1;
	*(_DWORD*)&byte_5D4594[1047924] = 1;
	return result;
}

//----- (0045DA50) --------------------------------------------------------
void __cdecl sub_45DA50(int a1) {
	if (*(_DWORD*)&byte_5D4594[2618908]) {
		if (!sub_4372B0()) {
			if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251)) {
				sub_45DB20((char*)(*(_DWORD*)(dword_587000_133480 + 204) + 8 * a1), 1,
					   *(_BYTE*)(*(_DWORD*)(dword_587000_133480 + 204) + 8 * a1 + 4) &
					       1);
				sub_45DAD0(a1);
			} else {
				sub_45DAF0(*(_DWORD*)(*(_DWORD*)(dword_587000_133480 + 204) + 8 * a1));
				sub_45DAD0(a1);
			}
		}
	}
}

//----- (0045DAD0) --------------------------------------------------------
void __cdecl sub_45DAD0(int a1) {
	*(_DWORD*)&byte_587000[133484] = a1;
	*(_DWORD*)&byte_5D4594[1049540] = *(_DWORD*)&byte_5D4594[2598000];
}

//----- (0045DAF0) --------------------------------------------------------
int __cdecl sub_45DAF0(int a1) {
	int result; // eax
	__int16 v3; // [esp+0h] [ebp-2h]

	result = sub_477600();
	if (!result) {
		result = a1;
		if (a1) {
			HIBYTE(v3) = a1;
			LOBYTE(v3) = 122;
			result = sub_40EBC0(31, 0, &v3, 2);
		}
	}
	return result;
}

//----- (0045DB20) --------------------------------------------------------
int __cdecl sub_45DB20(char* a1, int a2, char a3) {
	int result;  // eax
	int v4;      // ecx
	char* v5;    // eax
	char v6[22]; // [esp+0h] [ebp-18h]

	result = sub_477600();
	if (!result && *(_DWORD*)a1) {
		v4 = 0;
		v6[0] = 121;
		v5 = &v6[1];
		do {
			if (v4 >= a2)
				*(_DWORD*)v5 = 0;
			else
				*(_DWORD*)v5 = *(_DWORD*)&v5[a1 - &v6[1]];
			++v4;
			v5 += 4;
		} while (v4 < 5);
		v6[21] = a3;
		result = sub_40EBC0(31, 0, v6, 22);
	}
	return result;
}

//----- (0045DB90) --------------------------------------------------------
int sub_45DB90() {
	int result; // eax

	result = 0;
	memset(&byte_5D4594[1049544], 0, 0x88u);
	byte_5D4594[1049680] = 0;
	return result;
}

//----- (0045DBB0) --------------------------------------------------------
void sub_45DBB0() {
	if (*(_DWORD*)&byte_5D4594[1047916]) {
		sub_45DB20((char*)&byte_5D4594[1047916], 1, byte_5D4594[1047924]);
		*(_DWORD*)&byte_5D4594[1047916] = 0;
	}
}

//----- (0045DBE0) --------------------------------------------------------
void* __cdecl sub_45DBE0(void* a1, int a2, int a3) {
	void* result; // eax

	sub_45DC40(*(int*)&dword_587000_133480, a2, a3);
	result = a1;
	if (a1 == (void*)2) {
		if (a2 && (result = (void*)sub_424A50(a2, 1536)) != 0) {
			*(_BYTE*)(*(_DWORD*)(dword_587000_133480 + 204) + 8 * a3 + 4) = 1;
		} else {
			result = *(void**)&dword_587000_133480;
			*(_BYTE*)(*(_DWORD*)(dword_587000_133480 + 204) + 8 * a3 + 4) = 0;
		}
	}
	return result;
}

//----- (0045DC40) --------------------------------------------------------
_DWORD* __cdecl sub_45DC40(int a1, int a2, int a3) {
	wchar_t* v3;    // eax
	_DWORD* result; // eax

	*(_DWORD*)(*(_DWORD*)(a1 + 204) + 8 * a3) = a2;
	if (*(_DWORD*)(a1 + 4 * a3 + 212)) {
		v3 = (wchar_t*)sub_424930(a2);
		sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 4 * a3 + 212) + 36), v3);
	}
	result = *(_DWORD**)&byte_5D4594[2618908];
	if (*(_DWORD*)&byte_5D4594[2618908])
		result = sub_452D80(794, 100);
	return result;
}

//----- (0045DCA0) --------------------------------------------------------
int __cdecl sub_45DCA0(int a1, char a2, int a3, int a4, int* a5) {
	unsigned __int16 v5;  // si
	int v6;               // edi
	int* v7;              // esi
	int v8;               // eax
	int v9;               // ebx
	int v10;              // ecx
	int v11;              // edi
	unsigned __int16 v13; // [esp+10h] [ebp-8h]
	unsigned __int16 v14; // [esp+14h] [ebp-4h]

	v5 = 0;
	v14 = 137;
	v13 = 0;
	if ((wndIsShown_sub_46ACC0(*(int*)&byte_5D4594[1048148]) ||
	     !sub_45DEB0((int*)&byte_5D4594[1047940], a1, a3, a4)) &&
	    a5 != (int*)&byte_5D4594[1047940]) {
		v6 = *(_DWORD*)&byte_5D4594[1049476] != 0 ? 0 : 4;
		v7 = (int*)&byte_5D4594[256 * v6 + 1048196];
		while (1) {
			v8 = sub_45DE60((int)v7, a3, a4);
			v9 = v8;
			if (v8 >= 0) {
				v10 = v7[51];
				v14 = *(_WORD*)(v10 + 8 * v8);
				v13 = *(unsigned __int8*)(v10 + 8 * v8 + 4);
			}
			if (sub_45DEB0(v7, a1, a3, a4))
				break;
			v7 += 64;
			++v6;
			if ((int)v7 >= (int)&byte_5D4594[1049476])
				goto LABEL_16;
		}
		if (sub_477670() == 1) {
			v11 = v6 << 8;
			*(_BYTE*)(*(_DWORD*)&byte_5D4594[v11 + 1048400] + 8 * v9 + 4) = sub_424A50(a1, 1536);
		} else {
			v11 = v6 << 8;
			*(_BYTE*)(*(_DWORD*)&byte_5D4594[v11 + 1048400] + 8 * v9 + 4) = a2;
		}
		sub_45DDF0((int)&byte_5D4594[v11 + 1048196]);
	LABEL_16:
		v5 = v13;
	}
	return v5 | (v14 << 16);
}

//----- (0045DDF0) --------------------------------------------------------
int __cdecl sub_45DDF0(int a1) {
	int i;      // esi
	int result; // eax

	for (i = 0; i < 5; ++i)
		result = sub_45DE10(i, a1);
	return result;
}

//----- (0045DE10) --------------------------------------------------------
int __cdecl sub_45DE10(int a1, int a2) {
	int v2;     // eax
	char v3;    // bl
	_DWORD* v4; // eax
	int result; // eax

	v2 = *(_DWORD*)(a2 + 204);
	v3 = *(_BYTE*)(v2 + 8 * a1 + 4);
	v4 = (_DWORD*)(v2 + 8 * a1);
	if (v3 & 1 && *v4)
		result = sub_46AE10(*(_DWORD*)(a2 + 4 * a1 + 232), 1);
	else
		result = sub_46AE10(*(_DWORD*)(a2 + 4 * a1 + 232), 0);
	return result;
}

//----- (0045DE60) --------------------------------------------------------
int __cdecl sub_45DE60(int a1, int a2, int a3) {
	int v3;     // esi
	_DWORD** i; // edi

	v3 = 0;
	for (i = (_DWORD**)(a1 + 212); !sub_46AAB0(*i, a2, a3); ++i) {
		if (++v3 >= 5)
			return -1;
	}
	return v3;
}

//----- (0045DF60) --------------------------------------------------------
int __cdecl sub_45DF60(int a1, char a2) {
	int result; // eax

	if (a1) {
		sub_452D80(766, 100);
		if (!(a2 & 1) || sub_424A50(a1, 0x2000)) {
			*(_DWORD*)&byte_5D4594[1047556] = a1;
			*(_DWORD*)&byte_5D4594[1047928] = 1;
			result = 0;
		} else {
			sub_45DA10(a1);
			result = 1;
		}
	} else {
		*(_DWORD*)&byte_5D4594[1047928] = 0;
		result = 0;
	}
	return result;
}

//----- (0045DFC0) --------------------------------------------------------
int __cdecl sub_45DFC0(int a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // eax

	if (a1) {
		v2 = *(_DWORD*)&byte_5D4594[24 * a1 + 1047768];
		if (v2) {
			dword_5d4594_1047932 = 0;
			*(_DWORD*)&byte_5D4594[1047936] = 0;
			sub_45DAF0(a1);
			sub_452D80(766, 100);
			result = v2;
		} else {
			v3 = *(_DWORD*)&byte_5D4594[24 * a1 + 1047764];
			dword_5d4594_1047932 = 1;
			*(_DWORD*)&byte_5D4594[1047936] = v3;
			sub_452D80(766, 100);
			result = 0;
		}
	} else {
		dword_5d4594_1047932 = 0;
		*(_DWORD*)&byte_5D4594[1047936] = 0;
		result = 0;
	}
	return result;
}

// 45E040: using guessed type int var_14[5];

//----- (0045E110) --------------------------------------------------------
int __cdecl sub_45E110(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 0 && a1 < 5 && !*(_DWORD*)&byte_5D4594[1049476] && !dword_5d4594_1049496) {
		*(_BYTE*)(dword_587000_133480 + 200) = a1;
		*(_DWORD*)(dword_587000_133480 + 204) =
		    dword_587000_133480 + 40 * *(unsigned __int8*)(dword_587000_133480 + 200);
		if (*(_DWORD*)&byte_5D4594[2618908])
			sub_452D80(798, 100);
		result = sub_45DDF0(*(int*)&dword_587000_133480);
	}
	return result;
}

//----- (0045E180) --------------------------------------------------------
int sub_45E180() { return *(unsigned __int8*)(dword_587000_133480 + 200); }

//----- (0045EF30) --------------------------------------------------------
int sub_45EF30() { return 1; }

//----- (0045EF40) --------------------------------------------------------
int sub_45EF40() { return 0; }

//----- (0045EF50) --------------------------------------------------------
int __cdecl sub_45EF50(int a1, int a2, unsigned int a3) {
	int* v3;             // esi
	int v4;              // ebx
	_DWORD* v5;          // eax
	unsigned __int16 v7; // di
	int v8;              // ebp
	_DWORD* v9;          // ecx
	int v10;             // eax
	int v11;             // ecx
	unsigned int v12;    // eax
	int v13;             // eax
	int2 v14;            // [esp+10h] [ebp-8h]
	int v15;             // [esp+24h] [ebp+Ch]

	v3 = *(int**)(a1 + 368);
	if (!*(_DWORD*)&byte_5D4594[2614252] || (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) != 2) {
		v4 = 0;
		v5 = v3 + 53;
		do {
			if (a1 == *v5)
				break;
			++v4;
			++v5;
		} while (v4 < 5);
		if (v4 == 5)
			return 0;
		v7 = a3;
		v8 = 8 * v4;
		v15 = a3 >> 16;
		v9 = (_DWORD*)(8 * v4 + v3[51]);
		v14.field_0 = 8 * v4 + v3[51];
		switch (a2) {
		case 5:
			if (!*v9 || *(_DWORD*)&byte_5D4594[1047928] || dword_5d4594_1047932 ||
			    sub_57AF20() ||
			    *(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251) && !sub_424B70(*(_DWORD*)v14.field_0)) {
				return 1;
			}
			sub_46ADC0(a1);
			sub_477640(*(_DWORD*)v14.field_0, 2);
			*(_DWORD*)&byte_5D4594[1049692] = v3;
			*(_DWORD*)&byte_5D4594[1049696] = v3[51];
			sub_452D80(793, 100);
			return 1;
		case 6:
		case 7:
			if (!sub_46AE00())
				return 1;
			if (sub_57AF20())
				goto LABEL_51;
			v10 = sub_45DE60((int)v3, v7, v15);
			if (dword_5d4594_1047932) {
				if (v10 < 0)
					sub_4611B0();
				dword_5d4594_1047932 = 0;
				goto LABEL_51;
			}
			if (*(_DWORD*)&byte_5D4594[1047928]) {
				if (v10 < 0)
					sub_45D9D0(*(int*)&byte_5D4594[1047556]);
				*(_DWORD*)&byte_5D4594[1047928] = 0;
				goto LABEL_52;
			}
			if (v10 < 0) {
				v12 = sub_45DCA0(*(_DWORD*)(v8 + v3[51]), *(_BYTE*)(v8 + v3[51] + 4), v7, v15, v3);
				if (v12 >> 16 == 137) {
					v14.field_0 = v7;
					v14.field_4 = v15;
					v13 = sub_4281F0(&v14, (int4*)&byte_587000[133656]);
					if (v13 || *(_DWORD*)&byte_5D4594[1049696] &&
						       *(_DWORD*)&byte_5D4594[1049696] != v3[51])
						goto LABEL_51;
					*(_DWORD*)(v3[51] + 8 * v4) = 0;
					*(_BYTE*)(v3[51] + v8 + 4) = 0;
					if (v3 == (int*)&byte_5D4594[1047940])
						goto LABEL_51;
				} else {
					*(_DWORD*)(v3[51] + 8 * v4) = v12 >> 16;
					*(_BYTE*)(v3[51] + v8 + 4) = v12;
					if (v3 == (int*)&byte_5D4594[1047940])
						goto LABEL_51;
				}
			} else {
				if (*(_DWORD*)&byte_5D4594[1049692]) {
					if (*(int**)&byte_5D4594[1049692] == v3 &&
					    *(_DWORD*)&byte_5D4594[1049692] == dword_587000_133480) {
						if (*(_DWORD*)&byte_5D4594[1049696]) {
							v11 = v3[51];
							if (*(_DWORD*)&byte_5D4594[1049696] != v11) {
								sub_45F390(*(int*)&byte_5D4594[1049696], v11, v4, v10);
								sub_452D80(794, 100);
								sub_45DDF0((int)v3);
								goto LABEL_51;
							}
						}
					}
				}
				if (v10 == v4) {
					dword_5d4594_1049532 = a1;
					if (!*(_DWORD*)&byte_5D4594[2618908] || v3 == (int*)&byte_5D4594[1047940])
						goto LABEL_53;
					if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251)) {
						if (sub_424B70(*(_DWORD*)v14.field_0)) {
							sub_45DF60(*(_DWORD*)v14.field_0, *(_BYTE*)(v14.field_0 + 4));
							sub_45DAD0(v4);
						}
					} else {
						sub_45DFC0(*(_DWORD*)v14.field_0);
						sub_45DAD0(v4);
					}
				LABEL_51:
					if (*(_DWORD*)&byte_5D4594[1047928])
						goto LABEL_54;
				LABEL_52:
					if (dword_5d4594_1047932)
						goto LABEL_54;
				LABEL_53:
					sub_46ADE0(a1);
					dword_5d4594_1049532 = 0;
				LABEL_54:
					sub_477660();
					return 1;
				}
				sub_45F300((int)v3, v4, v10);
				sub_452D80(794, 100);
				if (v3 == (int*)&byte_5D4594[1047940])
					goto LABEL_51;
			}
			sub_45DDF0((int)v3);
			goto LABEL_51;
		case 8:
		case 12:
		case 16:
			return 0;
		default:
			return 1;
		}
	}
	return 1;
}
// 45F261: variable 'v13' is possibly undefined

//----- (0045F300) --------------------------------------------------------
wchar_t* __cdecl sub_45F300(int a1, int a2, int a3) {
	int v3;      // eax
	int v4;      // ecx
	int v5;      // edx
	_DWORD* v6;  // eax
	wchar_t* v7; // eax
	wchar_t* v8; // eax

	v3 = *(_DWORD*)(a1 + 204);
	v4 = *(_DWORD*)(v3 + 8 * a2);
	v5 = *(_DWORD*)(v3 + 8 * a2 + 4);
	*(_DWORD*)(v3 + 8 * a2) = *(_DWORD*)(8 * a3 + v3);
	*(_DWORD*)(v3 + 8 * a2 + 4) = *(_DWORD*)(8 * a3 + v3 + 4);
	v6 = (_DWORD*)(*(_DWORD*)(a1 + 204) + 8 * a3);
	*v6 = v4;
	v6[1] = v5;
	v7 = (wchar_t*)sub_424930(*(_DWORD*)(*(_DWORD*)(a1 + 204) + 8 * a2));
	sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 4 * a2 + 212) + 36), v7);
	v8 = (wchar_t*)sub_424930(*(_DWORD*)(8 * a3 + *(_DWORD*)(a1 + 204)));
	return sub_46B000((wchar_t*)(*(_DWORD*)(a1 + 4 * a3 + 212) + 36), v8);
}

//----- (0045F390) --------------------------------------------------------
wchar_t* __cdecl sub_45F390(int a1, int a2, int a3, int a4) {
	int v4;      // edi
	int v5;      // ebx
	wchar_t* v6; // eax

	v4 = *(_DWORD*)(a2 + 8 * a4);
	v5 = *(_DWORD*)(a2 + 8 * a4 + 4);
	*(_DWORD*)(a2 + 8 * a4) = *(_DWORD*)(a1 + 8 * a3);
	*(_DWORD*)(a2 + 8 * a4 + 4) = *(_DWORD*)(a1 + 8 * a3 + 4);
	*(_DWORD*)(a1 + 8 * a3) = v4;
	*(_DWORD*)(a1 + 8 * a3 + 4) = v5;
	v6 = (wchar_t*)sub_424930(*(_DWORD*)(a2 + 8 * a4));
	return sub_46B000((wchar_t*)(*(_DWORD*)(dword_587000_133480 + 4 * a4 + 212) + 36), v6);
}

//----- (0045F450) --------------------------------------------------------
int __cdecl sub_45F450(int a1, unsigned int a2) {
	if (a2 >= 5) {
		if (a2 <= 6)
			return 1;
		if (a2 == 7) {
			sub_45AC70();
			return 1;
		}
	}
	return 0;
}

//----- (0045F500) --------------------------------------------------------
int __cdecl sub_45F500(int a1, int a2) { return (*(_DWORD*)(*(_DWORD*)(a2 + 4 * a1 + 232) + 36) >> 1) & 1; }

//----- (0045F520) --------------------------------------------------------
int __cdecl sub_45F520(int a1, unsigned int a2) {
	int v2; // ebx
	int v3; // esi
	int v4; // eax
	int v5; // edi
	int v6; // eax

	v2 = (unsigned __int16)(*(_DWORD*)(a1 + 368) >> 16) << 8;
	v3 = *(unsigned __int16*)(a1 + 368);
	v4 = *(_DWORD*)&byte_5D4594[v2 + 1048400];
	v5 = v4 + 8 * v3;
	v6 = *(_DWORD*)(v4 + 8 * v3);
	if (!v6)
		return 0;
	if (a2 != 5) {
		if (a2 > 5 && a2 <= 7)
			return 1;
		return 0;
	}
	if (sub_424A50(v6, 2098176)) {
		sub_452D80(925, 100);
	} else {
		*(_BYTE*)(v5 + 4) ^= 1u;
		sub_45DE10(v3, (int)&byte_5D4594[v2 + 1048196]);
		sub_452D80(921, 100);
	}
	return 1;
}

//----- (0045F5D0) --------------------------------------------------------
int __cdecl sub_45F5D0(_DWORD* a1) {
	int v1;      // esi
	__int16* v2; // esi
	int v4;      // [esp+4h] [ebp-4h]

	v1 = a1[92];
	nox_client_wndGetPosition_46AA60(a1, &v4, &a1);
	v2 = (__int16*)sub_42E8E0(v1 + 28, 1);
	if (v2) {
		sub_434390(*(int*)&byte_5D4594[2523948]);
		sub_43F6E0(*(int*)&byte_5D4594[1049684], v2, v4, (int)a1);
	}
	return 1;
}

//----- (0045F630) --------------------------------------------------------
int __cdecl sub_45F630(int a1, unsigned int a2) {
	int v2; // esi

	v2 = *(_DWORD*)(a1 + 368);
	if ((!*(_DWORD*)&byte_5D4594[2614252] || (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2614252] + 120) & 2) != 2) &&
	    !sub_4AE3D0()) {
		if (a2 == 5) {
			switch (v2) {
			case 0:
				*(_DWORD*)(dword_5d4594_1049508 + 60) = 0;
				sub_460540();
				break;
			case 1:
				*(_DWORD*)(dword_5d4594_1049508 + 60) = 0;
				sub_4604F0();
				break;
			case 2:
				*(_DWORD*)(dword_5d4594_1049508 + 60) = 0;
				sub_460920();
				break;
			case 3:
				sub_4603F0();
				break;
			case 4:
				sub_4603A0();
				break;
			default:
				break;
			}
			*(_DWORD*)&byte_5D4594[1049700] = 2;
			*(_DWORD*)&byte_5D4594[1049704] = v2;
		} else if (a2 <= 5 || a2 > 7) {
			return 0;
		}
	}
	return 1;
}

//----- (0045F6F0) --------------------------------------------------------
int __cdecl sub_45F6F0(_DWORD* a1) {
	_DWORD* v1; // esi
	int v2;     // edi
	char* v3;   // eax
	int v4;     // ecx
	int v5;     // esi
	int v6;     // eax
	int v8;     // [esp+8h] [ebp-4h]

	v1 = a1;
	v2 = a1[92];
	nox_client_wndGetPosition_46AA60(a1, &a1, &v8);
	v3 = (char*)a1 + v1[24];
	v4 = v1[25] + v8;
	a1 = (_DWORD*)((char*)a1 + v1[24]);
	v8 = v4;
	if (*(int*)&byte_5D4594[1049700] <= 0 || *(int*)&byte_5D4594[1049704] != v2) {
		v5 = v1[15];
		if (v5)
			nox_client_drawImageAt_47D2C0(v5, (int)v3, v4);
	} else {
		nox_client_drawImageAt_47D2C0(v1[19], (int)v3, v4);
		if (!--*(_DWORD*)&byte_5D4594[1049700] && *(_DWORD*)&byte_5D4594[1049704] <= 2)
			*(_DWORD*)(dword_5d4594_1049508 + 60) =
			    *(_DWORD*)(dword_5d4594_1049508 + 76);
	}
	v6 = sub_45CFC0();
	sub_46AE10(*(int*)&byte_5D4594[1049524], v6);
	return 1;
}

//----- (0045F7A0) --------------------------------------------------------
int __cdecl sub_45F7A0(_DWORD* a1, unsigned int a2, unsigned int a3) {
	int result; // eax

	if (a2 < 5)
		goto LABEL_18;
	if (a2 <= 6)
		return 1;
	if (a2 != 7) {
	LABEL_18:
		sub_46AE10(*(int*)&dword_5d4594_1049504, 0);
		return 0;
	}
	if (*(_DWORD*)&byte_5D4594[1047928]) {
		if (!sub_46AAB0(a1, (unsigned __int16)a3, a3 >> 16))
			sub_45E040();
		sub_46ADE0((int)a1);
		dword_5d4594_1049532 = 0;
		*(_DWORD*)&byte_5D4594[1047928] = 0;
		return 1;
	}
	sub_46AE10(*(int*)&dword_5d4594_1049504, 1);
	if (!*(_DWORD*)&byte_5D4594[2618908])
		return 1;
	if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251) == 1 && sub_45F890()) {
		sub_46ADC0((int)a1);
		dword_5d4594_1049532 = a1;
		*(_DWORD*)&byte_5D4594[1047928] = 1;
		result = 1;
	} else {
		sub_45E040();
		result = 1;
	}
	return result;
}

//----- (0045F890) --------------------------------------------------------
int sub_45F890() {
	int* v0; // esi
	int v1;  // edi

	v0 = *(int**)&byte_5D4594[1048144];
	v1 = 0;
	while (!*v0 || (sub_424A70(*v0) & 8) != 8) {
		++v1;
		v0 += 2;
		if (v1 >= 3)
			return 0;
	}
	return 1;
}

//----- (0045F8D0) --------------------------------------------------------
BOOL __cdecl sub_45F8D0(int a1, int a2, int a3, int a4) { return a2 != 8 && a2 != 12 && a2 != 16; }

//----- (0045F8F0) --------------------------------------------------------
int sub_45F8F0() {
	sub_45F900();
	return 1;
}

//----- (0045F900) --------------------------------------------------------
_DWORD* sub_45F900() {
	_DWORD* result; // eax
	int i;          // edi
	int v2;         // ecx
	int v3;         // eax
	int v4;         // esi

	result = *(_DWORD**)&dword_587000_133480;
	if (dword_587000_133480) {
		if (dword_5d4594_1049496) {
			result = (_DWORD*)sub_430B40_get_mouse_prev_seq();
			if (*(_DWORD**)&byte_5D4594[1049492] == result)
				return result;
			dword_5d4594_1049496 = 0;
		} else {
			result = (_DWORD*)sub_430B40_get_mouse_prev_seq();
			if (*(_DWORD**)&byte_5D4594[1049492] != result)
				return result;
			dword_5d4594_1049496 = 1;
		}
		for (i = 0; i < 5; ++i) {
			v2 = *(_DWORD*)(dword_587000_133480 + 204);
			v3 = *(_DWORD*)(v2 + 8 * i);
			v4 = v2 + 8 * i;
			if (v3) {
				if (!sub_424A50(v3, 2098176)) {
					*(_BYTE*)(v4 + 4) ^= 1u;
					sub_45DE10(i, *(int*)&dword_587000_133480);
				}
			}
		}
		sub_45DDF0(*(int*)&dword_587000_133480);
		result = sub_452D80(921, 100);
	}
	return result;
}

//----- (0045FB90) --------------------------------------------------------
int __cdecl sub_45FB90(int a1, unsigned int a2, int a3, int a4) {
	if (a2 >= 5) {
		if (a2 <= 6)
			return 1;
		if (a2 == 7) {
			if (!wndIsShown_sub_46ACC0(a1))
				sub_461060();
			return 1;
		}
	}
	return 0;
}

//----- (00460000) --------------------------------------------------------
int sub_460000() {
	int v0;     // edx
	int v1;     // eax
	int result; // eax

	v0 = *(_DWORD*)(dword_5d4594_1049504 + 20);
	v1 = *(_DWORD*)(dword_5d4594_1049504 + 20) - *(_DWORD*)&byte_5D4594[1049536];
	if (v1 >= 0) {
		if (v1 <= 0) {
			if (*(_DWORD*)&byte_5D4594[1049536] > nox_win_height) {
				sub_460070();
				*(_DWORD*)&byte_5D4594[1049536] = nox_win_height - 74;
			}
			result = 1;
		} else {
			sub_46A9B0(*(_DWORD**)&dword_5d4594_1049504, *(_DWORD*)(dword_5d4594_1049504 + 16),
				   v0 - 1);
			result = 1;
		}
	} else {
		sub_46A9B0(*(_DWORD**)&dword_5d4594_1049504, *(_DWORD*)(dword_5d4594_1049504 + 16), v0 + 1);
		result = 1;
	}
	return result;
}

//----- (004601F0) --------------------------------------------------------
int __cdecl sub_4601F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
	int v7;               // esi
	char* v8;             // eax
	int v9;               // ebx
	unsigned __int8* v10; // ebp
	int* v11;             // edi
	_DWORD* v12;          // eax
	int v13;              // eax
	int result;           // eax
	int v15;              // [esp+Ch] [ebp+4h]

	v7 = a1;
	*(_DWORD*)(a1 + 208) = nox_window_new(0, 1224, a2 - 10, a3 - 15, 199, 59, 0);
	v8 = sub_42F970("QuickBarBase");
	sub_46AE60(*(_DWORD*)(a1 + 208), (int)v8);
	sub_46AE40(*(_DWORD*)(a1 + 208), -61, -18);
	sub_46B300(*(_DWORD*)(a1 + 208), sub_45F8D0);
	v9 = a5 + 10;
	if (a4 > 0) {
		v10 = &byte_587000[133488];
		v11 = (int*)(a1 + 212);
		v15 = a4;
		do {
			v12 = nox_window_new(*(_DWORD*)(v7 + 208), 1032, v9, 15, 34, 34, 0);
			*v11 = (int)v12;
			nox_window_set_all_funcs(v12, a6, a7, 0);
			v13 = *v11;
			++v11;
			v10 += 4;
			*(_DWORD*)(v13 + 368) = v7;
			v9 += *((_DWORD*)v10 - 1);
			--v15;
		} while (v15);
	}
	result = *(unsigned __int8*)(v7 + 200);
	*(_DWORD*)(v7 + 204) = v7 + 40 * result;
	return result;
}

//----- (004602F0) --------------------------------------------------------
void* sub_4602F0() {
	int v0;              // ebp
	unsigned __int8* v1; // esi
	int v2;              // edi
	_DWORD* v3;          // ecx
	_BYTE* v4;           // eax
	int v5;              // edx
	unsigned __int8* v6; // edx
	unsigned __int8* v7; // eax
	int v8;              // ecx
	void* result;        // eax

	sub_4606B0();
	v0 = 0;
	v1 = &byte_5D4594[1048196];
	do {
		v2 = 5;
		v3 = (_DWORD*)(dword_587000_133480 + v0);
		v4 = v1 + 4;
		v5 = dword_587000_133480 + v0 - (_DWORD)v1;
		do {
			*v3 = 0;
			v4[v5] = 0;
			*((_DWORD*)v4 - 1) = 0;
			*v4 = 0;
			v3 += 2;
			v4 += 8;
			--v2;
		} while (v2);
		v1 += 256;
		v0 += 40;
	} while ((int)v1 < (int)&byte_5D4594[1049476]);
	v6 = &byte_5D4594[1047940];
	do {
		v7 = v6;
		v8 = 3;
		do {
			*(_DWORD*)v7 = 0;
			v7[4] = 0;
			v7 += 8;
			--v8;
		} while (v8);
		v6 += 40;
	} while ((int)v6 < (int)&byte_5D4594[1048060]);
	result = *(void**)&dword_587000_133480;
	if (*(_DWORD*)(dword_587000_133480 + 232))
		result = (void*)sub_45DDF0(*(int*)&dword_587000_133480);
	return result;
}

//----- (00460380) --------------------------------------------------------
void* sub_460380() {
	unsigned __int8* v0; // eax

	v0 = &byte_5D4594[1047804];
	do {
		*(_DWORD*)v0 = 0;
		v0 += 24;
	} while ((int)v0 < (int)&byte_5D4594[1047924]);
	return sub_4602F0();
}

//----- (004603A0) --------------------------------------------------------
_DWORD* sub_4603A0() {
	if (byte_5D4594[1048140] == 2)
		byte_5D4594[1048140] = 0;
	else
		++byte_5D4594[1048140];
	*(_DWORD*)&byte_5D4594[1048144] = &byte_5D4594[40 * byte_5D4594[1048140] + 1047940];
	return sub_452D80(798, 100);
}

//----- (004603F0) --------------------------------------------------------
_DWORD* sub_4603F0() {
	if (byte_5D4594[1048140])
		--byte_5D4594[1048140];
	else
		byte_5D4594[1048140] = 2;
	*(_DWORD*)&byte_5D4594[1048144] = &byte_5D4594[40 * byte_5D4594[1048140] + 1047940];
	return sub_452D80(798, 100);
}

//----- (00460440) --------------------------------------------------------
_DWORD* sub_460440() {
	_DWORD* result; // eax

	if (sub_4160F0(6u, *(_DWORD*)&byte_5D4594[2649704] >> 1)) {
		LOBYTE(result) = 0;
		*(_DWORD*)&byte_5D4594[1049708] = 0;
	} else {
		result = (_DWORD*)++*(_DWORD*)&byte_5D4594[1049708];
		if (*(int*)&byte_5D4594[1049708] >= 3) {
			byte_5D4594[1048140] = 2;
			return result;
		}
	}
	byte_5D4594[1048140] = (unsigned __int8)result;
	*(_DWORD*)&byte_5D4594[1048144] = &byte_5D4594[40 * (unsigned __int8)result + 1047940];
	sub_4160D0(6);
	return sub_452D80(798, 100);
}

//----- (004604B0) --------------------------------------------------------
int __cdecl sub_4604B0(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 0 && a1 < 3) {
		byte_5D4594[1048140] = a1;
		result = 5 * (unsigned __int8)a1;
		*(_DWORD*)&byte_5D4594[1048144] = &byte_5D4594[40 * (unsigned __int8)a1 + 1047940];
	}
	return result;
}

//----- (004604E0) --------------------------------------------------------
int sub_4604E0() { return byte_5D4594[1048140]; }

//----- (004604F0) --------------------------------------------------------
int sub_4604F0() {
	int result; // eax
	int v1;     // eax

	result = *(_DWORD*)&byte_5D4594[1049476];
	if (!*(_DWORD*)&byte_5D4594[1049476]) {
		result = dword_5d4594_1049496;
		if (!dword_5d4594_1049496) {
			result = sub_57AF20();
			if (!result) {
				sub_45DAD0(-1);
				v1 = *(unsigned __int8*)(dword_587000_133480 + 200) + 1;
				if (v1 > 4)
					v1 = 0;
				result = sub_45E110(v1);
			}
		}
	}
	return result;
}

//----- (00460540) --------------------------------------------------------
int sub_460540() {
	int result; // eax
	int v1;     // eax

	result = *(_DWORD*)&byte_5D4594[1049476];
	if (!*(_DWORD*)&byte_5D4594[1049476]) {
		result = dword_5d4594_1049496;
		if (!dword_5d4594_1049496) {
			result = sub_57AF20();
			if (!result) {
				sub_45DAD0(-1);
				v1 = *(unsigned __int8*)(dword_587000_133480 + 200) - 1;
				if (v1 < 0)
					v1 = 4;
				result = sub_45E110(v1);
			}
		}
	}
	return result;
}

//----- (00460590) --------------------------------------------------------
void sub_460590() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[1049476];
	if (!*(_DWORD*)&byte_5D4594[1049476]) {
		result = dword_5d4594_1049496;
		if (!dword_5d4594_1049496) {
			if (sub_4160F0(7u, *(_DWORD*)&byte_5D4594[2649704] >> 1)) {
				LOBYTE(result) = 0;
				*(_DWORD*)&byte_5D4594[1049712] = 0;
			} else {
				result = ++*(_DWORD*)&byte_5D4594[1049712];
				if (*(int*)&byte_5D4594[1049712] >= 5) {
					*(_BYTE*)(dword_587000_133480 + 200) = 4;
					return;
				}
			}
			*(_BYTE*)(dword_587000_133480 + 200) = result;
			*(_DWORD*)(dword_587000_133480 + 204) =
			    dword_587000_133480 +
			    40 * *(unsigned __int8*)(dword_587000_133480 + 200);
			sub_4160D0(7);
			sub_452D80(798, 100);
			sub_45DDF0(*(int*)&dword_587000_133480);
		}
	}
}

//----- (00460630) --------------------------------------------------------
void sub_460630() {
	if (!*(_DWORD*)&byte_5D4594[1049476]) {
		int result = sub_430B40_get_mouse_prev_seq();
		*(_DWORD*)&byte_5D4594[1049492] = result;
	}
}

//----- (00460650) --------------------------------------------------------
int sub_460650() { return *(_DWORD*)&byte_5D4594[1047928]; }

//----- (00460660) --------------------------------------------------------
int sub_460660() {
	int result; // eax

	result = dword_5d4594_1049532;
	if (dword_5d4594_1049532 || *(_DWORD*)&byte_5D4594[1047928] || dword_5d4594_1047932) {
		sub_46ADE0(*(int*)&dword_5d4594_1049532);
		dword_5d4594_1049532 = 0;
		*(_DWORD*)&byte_5D4594[1047928] = 0;
		dword_5d4594_1047932 = 0;
		result = 1;
	}
	return result;
}

//----- (004606B0) --------------------------------------------------------
int sub_4606B0() {
	unsigned __int8* v0; // ebp
	int v1;              // ecx
	unsigned __int8* v2; // ebx
	int* v3;             // edi
	_BYTE* v4;           // esi
	int v6;              // [esp+0h] [ebp-Ch]
	int v7;              // [esp+4h] [ebp-8h]
	int v8;              // [esp+8h] [ebp-4h]

	if (*(_DWORD*)&byte_5D4594[1049476] != 1)
		return 0;
	v6 = 0;
	v0 = &byte_5D4594[1048196];
	do {
		v1 = (int)&v0[-v6 - dword_587000_133480];
		v2 = v0;
		v3 = (int*)(v0 + 232);
		v4 = (_BYTE*)(v6 + dword_587000_133480 + 4);
		v8 = (int)&v0[-v6 - dword_587000_133480];
		v7 = 5;
		while (1) {
			*((_DWORD*)v4 - 1) = *(_DWORD*)v2;
			*v4 = v4[v1];
			nox_window_set_hidden(*v3, 1);
			++v3;
			v2 += 8;
			v4 += 8;
			if (!--v7)
				break;
			v1 = v8;
		}
		nox_window_set_hidden(*((_DWORD*)v0 + 52), 1);
		v0 += 256;
		v6 += 40;
	} while ((int)v0 < (int)&byte_5D4594[1049220]);
	*(_BYTE*)(dword_587000_133480 + 200) = byte_5D4594[1047908];
	*(_DWORD*)(dword_587000_133480 + 204) =
	    dword_587000_133480 + 40 * *(unsigned __int8*)(dword_587000_133480 + 200);
	sub_45DDF0(*(int*)&dword_587000_133480);
	nox_window_set_hidden(*(int*)&dword_5d4594_1049512, 0);
	sub_452D80(800, 100);
	*(_DWORD*)&byte_5D4594[1049476] = 0;
	return 1;
}

//----- (00460920) --------------------------------------------------------
_DWORD* sub_460920() {
	unsigned __int8* v0; // ebx
	int* v1;             // ebp
	unsigned __int8* v2; // esi
	_DWORD* v3;          // edi
	int v4;              // eax
	_DWORD* result;      // eax
	int v6;              // [esp+0h] [ebp-Ch]
	int v7;              // [esp+4h] [ebp-8h]
	int i;               // [esp+8h] [ebp-4h]

	if (*(_DWORD*)&byte_5D4594[1049476])
		return (_DWORD*)sub_4606B0();
	result = *(_DWORD**)&dword_5d4594_1049496;
	if (!dword_5d4594_1049496) {
		result = (_DWORD*)sub_57AF20();
		if (!result) {
			result = *(_DWORD**)&byte_5D4594[1049476];
			if (!*(_DWORD*)&byte_5D4594[1049476]) {
				if (dword_5d4594_1049484 == 1)
					sub_461010();
				v6 = 0;
				v0 = &byte_5D4594[1048428];
				do {
					v1 = (int*)v0;
					v2 = v0 - 228;
					v3 = (_DWORD*)(v6 + dword_587000_133480);
					v7 = 5;
					v4 = v6 + dword_587000_133480 - (_DWORD)(v0 - 232);
					for (i = v6 + dword_587000_133480 - (_DWORD)(v0 - 232);; v4 = i) {
						*((_DWORD*)v2 - 1) = *v3;
						*v2 = v2[v4];
						nox_window_set_hidden(*v1, 0);
						++v1;
						v3 += 2;
						v2 += 8;
						if (!--v7)
							break;
					}
					nox_window_set_hidden(*((_DWORD*)v0 - 6), 0);
					sub_45DDF0((int)(v0 - 232));
					v0 += 256;
					v6 += 40;
				} while ((int)v0 < (int)&byte_5D4594[1049452]);
				*(_DWORD*)&byte_5D4594[1047912] =
				    *(unsigned __int8*)(dword_587000_133480 + 200);
				*(_BYTE*)(dword_587000_133480 + 200) = 4;
				*(_DWORD*)(dword_587000_133480 + 204) =
				    dword_587000_133480 +
				    40 * *(unsigned __int8*)(dword_587000_133480 + 200);
				sub_45DDF0(*(int*)&dword_587000_133480);
				nox_window_set_hidden(*(int*)&dword_5d4594_1049512, 1);
				result = sub_452D80(799, 100);
				*(_DWORD*)&byte_5D4594[1049476] = 1;
			}
		}
	}
	return result;
}

//----- (00460940) --------------------------------------------------------
int __thiscall sub_460940(void* this) {
	int result; // eax
	void* v2;   // [esp+0h] [ebp-4h]

	v2 = this;
	if (!*(_DWORD*)&byte_5D4594[3803300] && sub_461450() == 1) {
		sub_461400();
		sub_461440(0);
	}
	if (*(_DWORD*)&byte_5D4594[2618908])
		LOBYTE(v2) = *(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251);
	else
		LOBYTE(v2) = sub_431770()[66];
	sub_426AC0_file3_fread(&v2, 1u);
	if (!(_BYTE)v2) {
		result = sub_460A10(*(int*)&dword_587000_133480, 5, 5, 0);
		if (!result)
			return result;
		return 1;
	}
	result = sub_460A10(*(int*)&dword_587000_133480, 5, 5, (char)v2);
	if (result) {
		result = sub_460A10((int)&byte_5D4594[1047940], 3, 3, (char)v2);
		if (result) {
			if (*(_DWORD*)(dword_587000_133480 + 232))
				sub_45DDF0(*(int*)&dword_587000_133480);
			return 1;
		}
	}
	return result;
}

//----- (00460A10) --------------------------------------------------------
int __cdecl sub_460A10(int a1, int a2, int a3, char a4) {
	int v4;        // esi
	int v5;        // ebp
	char* v6;      // eax
	bool v7;       // zf
	size_t v9;     // [esp-14h] [ebp-120h]
	int v10;       // [esp+0h] [ebp-10Ch]
	int v11;       // [esp+4h] [ebp-108h]
	int v12;       // [esp+8h] [ebp-104h]
	char v13[256]; // [esp+Ch] [ebp-100h]

	if (a2 <= 0)
		return 1;
	v4 = a1;
	v11 = a1;
	v12 = a2;
	do {
		v5 = a3;
		if (a3 > 0) {
			do {
				if (*(_DWORD*)&byte_5D4594[3803300] == 1) {
					sub_426AC0_file3_fread(&v10, 1u);
					sub_426AC0_file3_fread(v13, (unsigned __int8)v10);
					v13[(unsigned __int8)v10] = 0;
					if (a4)
						*(_DWORD*)v4 = sub_4243F0(v13);
					else
						*(_DWORD*)v4 = sub_424D80(v13);
				} else {
					if (a4) {
						LOBYTE(v10) = strlen(sub_424870(*(_DWORD*)v4));
						sub_426AC0_file3_fread(&v10, 1u);
						v9 = (unsigned __int8)v10;
						v6 = sub_424870(*(_DWORD*)v4);
					} else {
						LOBYTE(v10) = strlen(sub_425250(*(_DWORD*)v4));
						sub_426AC0_file3_fread(&v10, 1u);
						v9 = (unsigned __int8)v10;
						v6 = sub_425250(*(_DWORD*)v4);
					}
					sub_426AC0_file3_fread(v6, v9);
				}
				sub_426AC0_file3_fread((_BYTE*)(v4 + 4), 1u);
				v4 += 8;
				--v5;
			} while (v5);
		}
		v4 = v11 + 40;
		v7 = v12 == 1;
		v11 += 40;
		--v12;
	} while (!v7);
	return 1;
}
// 460A10: using guessed type char var_100[256];

//----- (00460B90) --------------------------------------------------------
int __cdecl sub_460B90(int a1) {
	int i;      // esi
	int result; // eax
	int j;      // esi

	if (a1) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1049500, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049504, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049520, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049508, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049512, 0);
		for (i = 232; i < 252; i += 4) {
			nox_window_set_hidden(*(_DWORD*)(i + dword_587000_133480 - 20), 0);
			nox_window_set_hidden(*(_DWORD*)(i + dword_587000_133480), 0);
			if (dword_5d4594_1049484) {
				nox_window_set_hidden(*(_DWORD*)&byte_5D4594[i + 1047920], 0);
				nox_window_set_hidden(*(_DWORD*)&byte_5D4594[i + 1047940], 0);
				nox_window_set_hidden(*(int*)&dword_5d4594_1049512, 1);
			}
		}
		if (dword_5d4594_1049484)
			nox_window_set_hidden(*(int*)&byte_5D4594[1048148], 0);
		result = nox_window_set_hidden(*(_DWORD*)(dword_587000_133480 + 208), 0);
	} else {
		if (*(_DWORD*)&byte_5D4594[1049476])
			sub_460920();
		nox_window_set_hidden(*(int*)&dword_5d4594_1049500, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049504, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049520, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049508, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1049512, 1);
		for (j = 232; j < 252; j += 4) {
			nox_window_set_hidden(*(_DWORD*)(j + dword_587000_133480 - 20), 1);
			nox_window_set_hidden(*(_DWORD*)(j + dword_587000_133480), 1);
		}
		nox_window_set_hidden(*(_DWORD*)(dword_587000_133480 + 208), 1);
		result = nox_window_set_hidden(*(int*)&byte_5D4594[1048148], 1);
	}
	return result;
}
