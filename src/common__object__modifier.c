#include "cdrom.h"
#include "client__gui__window.h"
#include "common__strman.h"

//----- (00411B90) --------------------------------------------------------
int  nox_xxx_parseWeapDescription_411B90(const char* a1, char* a2, obj_412ae0_t* obj) {
	// a1 is of the form "= modifier.db:SomethingDesc".
	// Parse out the string name (after the separators " =\n\r\t")
	const char* stringName = strtok(a2, " =\n\r\t");
	if (!stringName) {
		return 0;
	}

	// POST_CLEANUP: Why load the string twice?
	const wchar_t* str1 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 418);
	const size_t str1len = nox_wcslen(str1);
	obj->field_2 = malloc(2 * str1len + 2);
	if (!obj->field_2) {
		return 0;
	}

	const wchar_t* str2 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 426);
	nox_wcsncpy(obj->field_2, str2, str1len);
	obj->field_2[str1len] = 0;

	return 1;
}

//----- (00412100) --------------------------------------------------------
int  nox_xxx_parseEnchDesc_412100_parse_desc(const char* a1, char* a2, obj_412ae0_t* obj) {
	// a1 is of the form "= modifier.db:SomethingDesc".
	// Parse out the string name (after the separators " =\n\r\t")
	const char* stringName = strtok(a2, " =\n\r\t");
	if (!stringName) {
		return 0;
	}

	const wchar_t* str1 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 733);
	const size_t str1len = nox_wcslen(str1);
	obj->field_2 = malloc(2 * str1len + 2);
	if (!obj->field_2) {
		return 0;
	}

	const wchar_t* str2 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 741);
	nox_wcsncpy(obj->field_2, str2, str1len);
	obj->field_2[str1len] = 0;

	return 1;
}

//----- (004121B0) --------------------------------------------------------
int  nox_xxx_parseEnchDescSecondary_4121B0_parse_second_desc(const char* a1, char* a2, obj_412ae0_t* obj) {
	// a1 is of the form "= modifier.db:SomethingDesc".
	// Parse out the string name (after the separators " =\n\r\t")
	const char* stringName = strtok(a2, " =\n\r\t");
	if (!stringName) {
		return 0;
	}

	const wchar_t* str1 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 767);
	const size_t str1len = nox_wcslen(str1);
	obj->field_3 = malloc(2 * str1len + 2);
	if (!obj->field_3) {
		return 0;
	}

	const wchar_t* str2 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 775);
	nox_wcsncpy(obj->field_3, str2, str1len);
	obj->field_3[str1len] = 0;

	return 1;
}

//----- (00412260) --------------------------------------------------------
int  nox_xxx_parseIdentifyDesc_412260_parse_ident_desc(const char* a1, char* a2, obj_412ae0_t* obj) {
	// a1 is of the form "= modifier.db:SomethingDesc".
	// Parse out the string name (after the separators " =\n\r\t")
	const char* stringName = strtok(a2, " =\n\r\t");
	if (!stringName) {
		return 0;
	}

	const wchar_t* str1 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 801);
	const size_t str1len = nox_wcslen(str1);
	obj->field_4 = malloc(2 * str1len + 2);
	if (!obj->field_4) {
		return 0;
	}

	const wchar_t* str2 = nox_strman_loadString_40F1D0(stringName, 0, "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 809);
	nox_wcsncpy(obj->field_4, str2, str1len);
	obj->field_4[str1len] = 0;

	return 1;
}

//----- (00413480) --------------------------------------------------------
wchar_t*  sub_413480(char a1) {
	int v1;              // ecx
	unsigned char* v2; // eax

	v1 = 0;
	v2 = getMemAt(0x587000, 27332);
	while (a1 != *v2) {
		v2 += 20;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 27452)) {
			return 0;
}
	}
	return nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 27344 + 20 * v1), 0,
								 "C:\\NoxPost\\src\\common\\Object\\Modifier.c", 2087);
}
