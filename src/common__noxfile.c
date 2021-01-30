#include "common__noxfile.h"

int dword_5d4594_3612 = 0;

int sub_4312C0();
//----- (0040ADD0) --------------------------------------------------------
int nox_xxx_fileBinRead_40ADD0_fread(char* buf, size_t size, size_t count, FILE* file) {

	int left = count * size;
	if (dword_5d4594_3612)
		return fread(buf, size, count, file);
	dword_5d4594_3612 = 1;
	if (left == 0) {
		dword_5d4594_3612 = 0;
		return 0;
	}
	unsigned int total = 0;
	int result;
	while (1) {
		sub_4312C0();
		size_t n = left;
		if (left > 204800)
			n = 204800;
		result = fread(buf, 1, n, file);
		if (result < 0)
			break;
		total += result;
		if (result == n) {
			left -= result;
			buf += result;
			if (left > 0)
				continue;
		}
		result = total / size;
		break;
	}
	dword_5d4594_3612 = 0;
	return result;
}