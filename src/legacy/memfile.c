#include "memfile.h"
#include "common__binfile.h"
#include <stdlib.h>
#include <string.h>

int8_t nox_memfile_read_i8(nox_memfile* f) {
	if (!f->data)
		return 0;
	int8_t v = *(int8_t*)f->cur;
	f->cur++;
	return v;
}

uint8_t nox_memfile_read_u8(nox_memfile* f) {
	if (!f->data)
		return 0;
	uint8_t v = *(uint8_t*)f->cur;
	f->cur++;
	return v;
}

int16_t nox_memfile_read_i16(nox_memfile* f) {
	if (!f->data)
		return 0;
	int16_t v = *(int16_t*)f->cur;
	f->cur += 2;
	return v;
}

uint16_t nox_memfile_read_u16(nox_memfile* f) {
	if (!f->data)
		return 0;
	uint16_t v = *(uint16_t*)f->cur;
	f->cur += 2;
	return v;
}

int32_t nox_memfile_read_i32(nox_memfile* f) {
	if (!f->data)
		return 0;
	int32_t v = *(int32_t*)f->cur;
	f->cur += 4;
	return v;
}

uint32_t nox_memfile_read_u32(nox_memfile* f) {
	if (!f->data)
		return 0;
	uint32_t v = *(uint32_t*)f->cur;
	f->cur += 4;
	return v;
}

void nox_memfile_skip(nox_memfile* f, int n) {
	if (!f->data)
		return;
	f->cur += n;
}

//----- (0040ACC0) --------------------------------------------------------
unsigned int nox_memfile_read(void* dst, const unsigned int sz, const int cnt, nox_memfile* f) {
	unsigned int n = cnt * sz;
	if (f->cur + n > f->end)
		n = f->end - f->cur;
	memcpy(dst, f->cur, n);
	f->cur += n;
	return n / sz;
}

//----- (0040AD60) --------------------------------------------------------
unsigned int nox_memfile_read64align_40AD60(char* dest, int sz, int cnt, nox_memfile* f) {
	const size_t cur_offset = f->cur - f->data;
	const uint8_t over = cur_offset % 8;

	char buf[8];
	if (over) {
		nox_memfile_read(&buf, 8 - over, 1, f);
	}

	unsigned int result = nox_memfile_read(&buf, 8, 1, f);
	if (result != 1) {
		return result;
	}

	memcpy(dest, &buf, cnt * sz);
	return 1;
}
