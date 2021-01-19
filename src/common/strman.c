#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wctype.h>
#include "strman.h"
#include "random.h"
#include "noxfile.h"
#include "../noxstring.h"

#ifdef _MSC_VER // not _WIN32, because mingw has it
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif

typedef struct nox_strman_lang_t {
	const char* name;
	const char* slug;
	const char* sym;
	unsigned int code;
} nox_strman_lang_t;

nox_strman_lang_t nox_strman_lang[] = {
	{"US", "us", "e", NOX_LANG_US},
	{"UK", "uk", "e", NOX_LANG_UK},
	{"German", "ge", "g", NOX_LANG_GE},
	{"French", "fr", "f", NOX_LANG_FR},
	{"Spanish", "sp", "s", NOX_LANG_SP},
	{"Italian", "it", "i", NOX_LANG_IT},
	{"Japanese", "ja", "j", NOX_LANG_JA},
	{"Korean", "ko", "k", NOX_LANG_KO},
	{"Jabberwocky", "jb", "e", NOX_LANG_UNK},
};
int nox_strman_lang_cnt = sizeof(nox_strman_lang) / sizeof(nox_strman_lang_t);

nox_strman_lang_t nox_strman_lang_cur = {"Unknown", 0, 0, NOX_LANG_UNK};
int nox_strman_get_lang_code() {
	return nox_strman_lang_cur.code;
}

nox_missing_string* missing_strings = 0;
nox_string_entry* string_entries = 0;
size_t string_entries_cnt = 0;

int nox_string_str_cnt = 0;
wchar_t** nox_string_wstr_arr = 0;
char** nox_string_str_arr = 0;

FILE* nox_strman_file = 0;

int dword_5d4594_251512 = 0;
int dword_5d4594_251480 = 0;
int dword_5d4594_251492 = 0;
int dword_5d4594_251484 = 0;
int dword_5d4594_251516 = 0;
char nox_strman_path_buf[1024] = {0};
char nox_strman_name_buf[1024] = {0};
char file_buffer[4096] = {0};
wchar_t file_buffer_w[4096 * 2] = {0};
char strman_buf_1[4096] = {0};
char strman_buf_2[4096] = {0}; // TODO: size is a guess
char strman_buf_3[8192] = {0}; // TODO: size is a guess

//----- (00410150) --------------------------------------------------------
void nox_xxx____setargv_1_410150() {
	dword_5d4594_251516 = 1;
}

//----- (0040F1D0) --------------------------------------------------------
const wchar_t* nox_strman_loadString_40F1D0(const char* name, char** strOut, const char* srcFile, int srcLine) {
	if (strOut) {
		*strOut = 0;
	}
	if (!string_entries) {
		return L"***FATAL*** String Manager failed to initilaized properly";
	}
	char* fullStringName = name;
	const char* srcFilename;
	if (strchr(name, ':')) {
		srcFilename = srcFile;
	} else {
		unsigned int separatorPos = strlen(srcFile) - 1;
		if (srcFile[separatorPos] != '\\') {
			char ch;
			do {
				ch = srcFile[--separatorPos];
			} while (ch != '\\');
		}
		srcFilename = &srcFile[separatorPos + 1];
		sprintf(nox_strman_name_buf, "%s:%s", srcFilename, name);
		fullStringName = nox_strman_name_buf;
	}
	const nox_string_entry* entry =
			bsearch(fullStringName, string_entries, string_entries_cnt, sizeof(nox_string_entry), strcasecmp);
	if (!entry) {
		nox_missing_string* v12 = (nox_missing_string*)malloc(sizeof(nox_missing_string));
		nox_swprintf(v12->data, L"MISSING:'%S'", fullStringName, srcFilename, srcLine);
		v12->next = missing_strings;
		missing_strings = v12;

		return v12->data;
	}

	const int variantCnt = *(unsigned char*)(&entry->data[49]);
	int variant;
	if (variantCnt <= 1u) {
		variant = 0;
	} else {
		variant = nox_common_randomInt_415FA0(0, variantCnt - 1);
	}
	const int ind = variant + entry->field_50;
	if (strOut) {
		*strOut = nox_string_str_arr[ind];
	}
	return nox_string_wstr_arr[ind];
}

//----- (00410020) --------------------------------------------------------
void nox_strman_free_410020() {
	if (nox_string_wstr_arr) {
		for (int i = 0; i < nox_string_str_cnt; ++i) {
			if (nox_string_wstr_arr[i]) {
				free(nox_string_wstr_arr[i]);
			}
		}
		free(nox_string_wstr_arr);
	}
	if (nox_string_str_arr) {
		for (int j = 0; j < nox_string_str_cnt; ++j) {
			if (nox_string_str_arr[j]) {
				free(nox_string_str_arr[j]);
			}
		}
		free(nox_string_str_arr);
	}
	if (string_entries)
		free(string_entries);

	nox_missing_string* v4 = missing_strings;
	while (v4) {
		nox_missing_string* v5 = v4->next;
		free(v4);
		v4 = v5;
	}

	missing_strings = 0;
	dword_5d4594_251512 = 0;
}

//----- (0040F5C0) --------------------------------------------------------
char sub_40F5C0(unsigned char* a1) {
	unsigned char v1;   // al
	unsigned char* i;  // edi
	int v3;    // eax
	unsigned char* v4; // edi
	unsigned char* j;  // esi
	unsigned char* k;  // esi

	v1 = *a1;
	for (i = a1; v1; v1 = *++i) {
		if (!iswspace(v1))
			break;
	}
	v3 = *i;
	v4 = i + 1;
	*a1 = v3;
	for (j = a1 + 1; v3; ++v4) {
		v3 = *v4;
		*j++ = *v4;
	}
	for (k = j - 2; k > a1; --k) {
		v3 = *k;
		if (!*k)
			break;
		v3 = iswspace((char)v3);
		if (!v3)
			break;
	}
	k[1] = 0;
	return v3;
}

//----- (0040F640) --------------------------------------------------------
char sub_40F640(FILE* a1, char* a2, char* a3, unsigned char* a4, int cnt) {
	char* v6;   // ebp
	bool v7;    // esi
	char* v8;   // edi
	char v9;    // bl
	unsigned char* v10; // esi
	char v11;   // bl
	char v12;   // al
	int v14;    // [esp+10h] [ebp-8h]
	int v15;    // [esp+14h] [ebp-4h]

	v6 = a2;
	v7 = 0;
	v8 = a3;
	v14 = 0;
	v15 = 0;
	while (cnt) {
		int v5 = cnt;
		if (!v6) {
			v5 = getc(a1);
			v9 = v5;
		} else {
			v9 = *v6++;
			if (!v9) {
				v6 = 0;
				v5 = getc(a1);
				v9 = v5;
			}
		}
		switch ((unsigned char)v9) {
			case 0xff:
				return v5;
			case 10:
				v7 = 0;
				v9 = 32;
				break;
			case 92:
				v7 = !v7;
				break;
			default:
				if (v9 == 34 && !v7) {
					goto LABEL_18;
				}
				v7 = 0;
				break;
		}
		if (iswspace(v9))
			v9 = 32;
		*v8++ = v9;
		cnt--;
	}
	LABEL_18:
	v10 = a4;
	*v8 = 0;
	while (1) {
		if (!v6) {
			v12 = getc(a1);
			v11 = v12;
		} else {
			v11 = *v6++;
			if (!v11) {
				v6 = 0;
				v12 = getc(a1);
				v11 = v12;
			}
		}
		if (v11 == 10)
			break;
		if (v11 == -1)
			break;
		if (!v14 && !iswspace(v11) && v11 != 61) {
			v14 = 1;
		}
		if (v14 == 1) {
			if ((v11 < 97 || v11 > 122) && (v11 < 65 || v11 > 90) && (v11 < 48 || v11 > 57) && v11 != 95) {
				v14 = 2;
			} else {
				*v10++ = v11;
				++v15;
			}
		}
	}
	int v5 = v15;
	*v10 = 0;
	if (v15) {
		v5 = *(v10 - 1);
		if ((char)v5 >= 48 && (char)v5 <= 57) {
			*v10 = 101;
			v10[1] = 0;
		}
	}
	return v5;
}

//----- (0040F4E0) --------------------------------------------------------
int sub_40F4E0() {
	string_entries_cnt = 0;
	nox_string_str_cnt = 0;
	while (fgets(file_buffer, sizeof(file_buffer) - 1, nox_strman_file)) {
		sub_40F5C0(file_buffer);
		if (file_buffer[0] == '"') {
			unsigned int n = strlen((const char*)file_buffer);
			file_buffer[n + 0] = '\n';
			file_buffer[n + 1] = 0;
			sub_40F640(nox_strman_file, (char*)file_buffer + 1, strman_buf_1, strman_buf_2, 4096);
			nox_string_str_cnt++;
			continue;
		}
		if (!strcasecmp(file_buffer, "END")) {
			++dword_5d4594_251492;
		}
	}
	nox_string_str_cnt += 1000;
	string_entries_cnt += 500;
	return 1;
}

//----- (0040F7A0) --------------------------------------------------------
int strman_read_csf_header_40F7A0(const char* path) {
	FILE* file = fopen(path, "rb");
	if (!file)
		return 0;
	int ok = 0;
	unsigned int buf[6];
	if (nox_xxx_fileBinRead_40ADD0_fread((char*)buf, 24, 1, file) == 1 && buf[0] == 0x43534620) { // "CSF "
		nox_string_str_cnt = buf[3];
		string_entries_cnt = buf[2];
		nox_strman_lang_cur.code = (int)buf[1] < 2 ? 0 : buf[5];
		ok = 1;
	}
	fclose(file);
	return ok;
}

//----- (0040FFE0) --------------------------------------------------------
void sub_40FFE0(char* a1, char* a2) {
	char* v2; // edx
	char* v3; // esi
	int v4;   // edi
	char v5;  // al
	char v6;  // cl

	v2 = a2;
	v3 = a1;
	v4 = 1;
	while (v3 < v2) {
		v5 = *v3;
		v6 = *v2;
		if (v4) {
			if (v5 >= 65 && v5 <= 90 && v6 >= 97 && v6 <= 122) {
				v5 += 32;
				v6 -= 32;
			}
			v4 = 0;
		}
		*v2-- = v5;
		*v3++ = v6;
	}
}

//----- (0040FE00) --------------------------------------------------------
wchar_t* sub_40FE00(wchar_t* a1, char* a2) {
	int v2;              // ebp
	char* v3;            // ecx
	unsigned char* v4; // esi
	unsigned char v5;  // bl
	unsigned char* v6; // edi
	unsigned char i;   // al
	unsigned char* v8; // edi
	unsigned char v9;  // cl
	wchar_t* result;       // eax

	v2 = 0;
	if (!dword_5d4594_251516) {
		v8 = a2;
		goto LABEL_28;
	}
	v3 = 0;
	v4 = strman_buf_3;
	v5 = *a2;
	v6 = a2 + 1;
	if (!*a2)
		goto LABEL_26;
	do {
		if ((char)v5 >= 97 && (char)v5 <= 122 || (char)v5 >= 65 && (char)v5 <= 90) {
			if (!v3)
				v3 = (char*)v4;
			*v4 = v5;
			++v4;
			goto LABEL_23;
		}
		if (v3) {
			sub_40FFE0(v3, (char*)v4 - 1);
			v3 = 0;
		}
		*v4++ = v5;
		if (v5 == 92) {
			*v4++ = *v6++;
			goto LABEL_23;
		}
		if (v5 == 37) {
			for (i = *v6++; i; ++v6) {
				if ((char)i >= 97 && (char)i <= 122)
					break;
				if ((char)i >= 65 && (char)i <= 90)
					break;
				*v4 = i;
				i = *v6;
				++v4;
			}
			*v4 = i;
			++v4;
		}
		LABEL_23:
		v5 = *v6++;
	} while (v5);
	if (v3)
		sub_40FFE0(v3, (char*)v4 - 1);
	LABEL_26:
	*v4 = 0;
	v8 = strman_buf_3;
	LABEL_28:
	v9 = *v8;
	result = a1;
	if (*v8) {
		while (v2 != 1) {
			if (v9 == 92) {
				v2 = 1;
			} else {
				LABEL_38:
				*result = v9;
				++result;
			}
			LABEL_40:
			v9 = *++v8;
			if (!v9)
				goto LABEL_41;
		}
		v2 = 0;
		switch (v9) {
			case 0u:
				return result;
			case 34u:
				*result = 34;
				++result;
				goto LABEL_40;
			case 39u:
				*result = 39;
				++result;
				goto LABEL_40;
			case 63u:
				*result = 63;
				++result;
				goto LABEL_40;
			case 92u:
				*result = 92;
				++result;
				goto LABEL_40;
			case 110u:
				*result = 10;
				++result;
				goto LABEL_40;
			case 116u:
				*result = 9;
				++result;
				goto LABEL_40;
			default:
				goto LABEL_38;
		}
	} else {
		LABEL_41:
		*result = 0;
	}
	return result;
}

//----- (0040FB60) --------------------------------------------------------
void sub_40FB60(wchar_t* a1) {
	wchar_t* v1;    // ecx
	wchar_t result; // ax

	v1 = a1;
	result = *a1;
	wchar_t v2 = -1; // dx
	bool v4 = 1;     // esi
	while (result) {
		if (result == ' ') {
			if (v2 != ' ' && !v4) {
				*v1 = result;
				++v1;
				v2 = result;
				v4 = 0;
			}
		} else {
			if (result != '\n' && result != '\t') {
				*v1 = result;
				++v1;
				v2 = result;
				v4 = 0;
			} else {
				if (v2 == ' ')
					--v1;
				*v1 = result;
				v2 = result;
				v4 = 1;
				++v1;
			}
		}
		++a1;
		result = *a1;
	}
	if (v2 == ' ')
		--v1;
	*v1 = 0;
}

//----- (0040FBE0) --------------------------------------------------------
int sub_40FBE0() {
	unsigned int v2; // kr08_4
	int v3;          // ebx
	int v8;          // eax

	int v0 = 0;
	int v1 = 0;
	int v10 = 0;
	int v11 = 0;
	do {
		LABEL_2:
		if (!fgets(file_buffer, sizeof(file_buffer), nox_strman_file))
			return 1;
		sub_40F5C0(file_buffer);
	} while (*(unsigned short*)file_buffer == 0x2F2F || !file_buffer[0]);
	strcpy((char*)(string_entries[v1].data), (const char*)file_buffer);
	v2 = strlen((const char*)file_buffer) + 1;
	if ((int)(v2 - 1) > *(int*)&dword_5d4594_251480)
		dword_5d4594_251480 = v2 - 1;
	string_entries[v1].field_50 = v0;
	v3 = 0;
	int v4 = v0;

	while (fgets(file_buffer, sizeof(file_buffer) - 1, nox_strman_file)) {
		sub_40F5C0(file_buffer);
		if (file_buffer[0] == '"') {
			int v5 = strlen((const char*)file_buffer);
			file_buffer[v5 + 0] = 10;
			file_buffer[v5 + 1] = 0;
			sub_40F640(nox_strman_file, (char*)file_buffer + 1, strman_buf_1, strman_buf_2, 4096);
			sub_40FE00(file_buffer_w, strman_buf_1);
			sub_40FB60(file_buffer_w);
			int v6 = nox_wcslen((const wchar_t*)file_buffer_w);
			nox_string_wstr_arr[v4] = calloc(v6 + 1, sizeof(wchar_t));
			nox_wcscpy(nox_string_wstr_arr[v4], (const wchar_t*)file_buffer_w);
			int v7 = strlen(strman_buf_2) + 1;
			if (v7 > 1) {
				nox_string_str_arr[v4] = calloc(v7, 1);
				strcpy(nox_string_str_arr[v4], strman_buf_2);
			}
			++v3;
			++v4;
		} else if (!strcasecmp(file_buffer, "END")) {
			*(unsigned char*)(&string_entries[v10].data[49]) = v3;
			v10++;
			v8 = v3 + v11;
			v1 = v10;
			v11 = v8;
			v0 = v8;
			goto LABEL_2;
		}
	}
	return 0;
}

//----- (0040F830) --------------------------------------------------------
int sub_40F830(const char* path) {
	int v7;               // ecx
	int v8;               // eax
	int v11;              // ecx
	unsigned char* v12; // eax
	size_t v13;           // eax
	int v16;              // [esp+10h] [ebp-28h]
	int v19;              // [esp+1Ch] [ebp-1Ch]

	FILE* file = fopen(path, "rb");
	if (!file)
		return 0;

	char hbuf[20];
	if (nox_xxx_fileBinRead_40ADD0_fread(hbuf, 20, 1, file) != 1) {
		fclose(file);
		return 0;
	}
	if (*(int*)&hbuf[4] < 2) {
		fseek(file, 20, SEEK_SET);
	} else {
		fseek(file, 24, SEEK_SET);
	}

	int i = 0;
	int previ = 0;
	int v18 = 0;
	while (nox_xxx_fileBinRead_40ADD0_fread((char*)&v16, 4, 1, file) == 1) {
		if (v16 != 0x4C424C20) { // "LBL "
			fclose(file);
			return 0;
		}
		int v17 = 0;
		int sz = 0;
		nox_xxx_fileBinRead_40ADD0_fread((char*)&v17, 4, 1, file);
		nox_xxx_fileBinRead_40ADD0_fread((char*)&sz, 4, 1, file);
		if (sz > 0) {
			nox_xxx_fileBinRead_40ADD0_fread(file_buffer, sz, 1, file);
		}
		file_buffer[sz] = 0;
		strcpy(string_entries[i].data, file_buffer);
		if (sz > *(int*)&dword_5d4594_251480)
			dword_5d4594_251480 = sz;
		v7 = v18;
		v19 = 0;
		*(unsigned char*)(&string_entries[i].data[49]) = v17;
		string_entries[i].field_50 = v18;
		v8 = v17;
		if (v17 > 0) {
			int v9 = v7;
			while (1) {
				nox_xxx_fileBinRead_40ADD0_fread((char*)&v16, 4, 1, file);
				if (v16 != 0x53545220 && v16 != 0x53545257 && v16 != 0x53747220 &&
					v16 != 0x53747257) // "STR ", "STRW", "Str ", "StrW"
				{
					fclose(file);
					return 0;
				}
				int sz = 0;
				nox_xxx_fileBinRead_40ADD0_fread((char*)&sz, 4, 1, file);
				if (sz > 0) {
					nox_xxx_fileBinRead_40ADD0_fread((char*)file_buffer_w, 2 * sz, 1, file);
				}
				file_buffer_w[sz] = 0;
				if (v16 == 0x53747220 || v16 == 0x53747257) // "Str " || "StrW"
				{
					v11 = *(unsigned int*)&file_buffer_w[0];
					v12 = file_buffer_w;
					if (*(unsigned short*)&file_buffer_w[0]) {
						do {
							v11 = ~v11;
							*(unsigned short*)v12 = v11;
							*((unsigned short*)&v11) = *((unsigned short*)v12 + 1);
							v12 += 2;
						} while ((unsigned short)v11);
					}
				}
				sub_40FB60(file_buffer_w);
				v13 = nox_wcslen((const wchar_t*)file_buffer_w);
				nox_string_wstr_arr[v9] = calloc(v13 + 1, 2);
				nox_wcscpy(nox_string_wstr_arr[v9], (const wchar_t*)file_buffer_w);
				if (v16 == 0x53545257 || v16 == 0x53747257) // "STRW" || "StrW"
				{
					int sz = 0;
					nox_xxx_fileBinRead_40ADD0_fread((char*)&sz, 4, 1, file);
					if (sz > 0) {
						nox_xxx_fileBinRead_40ADD0_fread(file_buffer, sz, 1, file);
					}
					file_buffer[sz] = 0;
					if (sz > 0) {
						nox_string_str_arr[v9] = calloc(sz + 1, 1);
						strcpy(nox_string_str_arr[v9], (const char*)file_buffer);
					}
				}
				v8 = v17;
				v9++;
				if (++v19 >= v17) {
					i = previ;
					break;
				}
			}
		}
		i++;
		previ = i;
		v18 += v8;
	}
	fclose(file);
	return 1;
}

//----- (0040F300) --------------------------------------------------------
int nox_strman_readfile(const char* path) {
	if (dword_5d4594_251512)
		return 1;
	dword_5d4594_251512 = 1;
	dword_5d4594_251480 = 0;
	if (!path || !path[0])
		return 0;

	// copy path to a buffer
	strcpy(nox_strman_path_buf, path);
	// trim file extension
	char* ext = strchr(nox_strman_path_buf, '.');
	if (ext) {
		*ext = 0;
	}
	// append correct extension
	ext = &nox_strman_path_buf[strlen(nox_strman_path_buf)];
	strcpy(ext, ".csf");
	ext[4] = 0;

	int v6 = 0;
	if (dword_5d4594_251484 == 0 || (nox_strman_file = fopen(path, "r")) == 0) {
		if (!strman_read_csf_header_40F7A0(nox_strman_path_buf))
			return 0;
		v6 = 1;
	} else {
		if (!sub_40F4E0()) {
			fclose(nox_strman_file);
			return 0;
		}
		fclose(nox_strman_file);
		v6 = 0;
	}
	if (!nox_string_str_cnt)
		return 0;
	if (!string_entries_cnt)
		return 0;
	string_entries = (nox_string_entry*)calloc(string_entries_cnt, sizeof(nox_string_entry));
	if (!string_entries)
		return 0;
	nox_string_wstr_arr = calloc(nox_string_str_cnt, sizeof(wchar_t*));
	if (!nox_string_wstr_arr)
		return 0;
	nox_string_str_arr = calloc(nox_string_str_cnt, sizeof(char*));
	if (!nox_string_str_arr)
		return 0;
	if (v6) {
		sub_40F830(nox_strman_path_buf);
	} else {
		nox_strman_file = fopen(path, "r");
		if (!nox_strman_file)
			return 0;
		if (!sub_40FBE0()) {
			fclose(nox_strman_file);
			return 0;
		}
		fclose(nox_strman_file);
	}
	qsort(string_entries, string_entries_cnt, sizeof(nox_string_entry), strcasecmp);
	return 1;
}
