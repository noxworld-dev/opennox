//+build none

#include "client__io__win95__video.h"
#include "common__strman.h"

#include "common/fs/nox_fs.h"
#include "client__io__console.h"

extern uint8_t* nox_pixbuffer_3798780;
extern int nox_backbuffer_pitch_3801808;
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
	FILE* file = nox_fs_create_text(path);
	if (!file) {
		v2 = nox_strman_loadString_40F1D0("BadOpen", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Video.c", 375);
		return sub_4517A0(v2, path);
	}
	nox_fs_fprintf(file, "P3\n#Nox Bitmap data\n640 480 256\n");
	v4 = nox_pixbuffer_3798780;
	for (int v5 = nox_backbuffer_height; v5 > 0; v5--) {
		for (int v7 = 0; v7 < nox_backbuffer_width; v7++) {
			if (v7 != 0 && (v7 % 60) == 0) {
				nox_fs_fprintf(file, "\n");
}
			nox_fs_fprintf(file, "%d %d %d ", getMemByte(0x973F18, 5288 + 3 * *(unsigned char*)(v7 + v4)),
					getMemByte(0x973F18, 5289 + 3 * *(unsigned char*)(v7 + v4)),
					getMemByte(0x973F18, 5290 + 3 * *(unsigned char*)(v7 + v4)));
		}
		v4 += nox_backbuffer_pitch_3801808;
	}
	v8 = nox_strman_loadString_40F1D0("SnapshotWritten", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Video.c", 399);
	sub_4517A0(v8, path);
	nox_fs_close(file);
	return 0;
}
