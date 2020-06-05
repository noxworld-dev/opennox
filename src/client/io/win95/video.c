#include "video.h"

#include "../../../proto.h"
#include "../console.h"

extern _DWORD dword_5d4594_3798780;
extern _DWORD dword_5d4594_3801808;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

extern int screenshot_num;

int sub_430F00_screenshot() {
	wchar_t* v2; // eax
	int v4;      // ebx
	wchar_t* v8; // eax

	char path[100];
	nox_sprintf(path, "sshot%03d.ppm", screenshot_num);
	++screenshot_num;
	FILE* file = fopen(path, "w");
	if (!file) {
		v2 = loadString_sub_40F1D0((char*)&byte_587000[80968], 0,
					   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Video.c", 375);
		return sub_4517A0(v2, path);
	}
	fprintf(file, "P3\n#Nox Bitmap data\n640 480 256\n");
	v4 = dword_5d4594_3798780;
	for (int v5 = nox_backbuffer_height; v5 > 0; v5--) {
		for (int v7 = 0; v7 < nox_backbuffer_width; v7++) {
			if (v7 != 0 && (v7 % 60) == 0)
				fprintf(file, "\n");
			fprintf(file, "%d %d %d ", byte_5D4594[3 * *(unsigned __int8*)(v7 + v4) + 3804716],
				byte_5D4594[3 * *(unsigned __int8*)(v7 + v4) + 3804717],
				byte_5D4594[3 * *(unsigned __int8*)(v7 + v4) + 3804718]);
		}
		v4 += dword_5d4594_3801808;
	}
	v8 = loadString_sub_40F1D0((char*)&byte_587000[81068], 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Video.c", 399);
	sub_4517A0(v8, path);
	return fclose(file);
}
