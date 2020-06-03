#include "memfile.h"
#include "proto.h"
#include <string.h>

//----- (0040ABF0) --------------------------------------------------------
nox_memfile* nox_memfile_load(const char* path, int a2) {
	nox_memfile* nf = (nox_memfile*)nox_malloc(sizeof(nox_memfile));
	if (!nf) {
		return 0;
	}
	FILE* f = sub_408CC0_fopen(path, 0);
	if (!f) {
		nox_memfile_free(nf);
		return 0;
	}
	if (!sub_408D40(f, a2)) {
		nox_memfile_free(nf);
		sub_408D90(f);
		return 0;
	}
	sub_409050(f, 0, 2);
	nf->size = sub_409390();
	sub_409050(f, 0, 0);
	nf->data = (char*)nox_malloc(nf->size);
	if (nf->data == 0) {
		nox_memfile_free(nf);
		sub_408D90(f);
		return 0;
	}
	int csize = nf->size;
	int x1 = sub_408E40_fread(nf->data, 1, nf->size, f);
	if (x1 != csize) {
		nox_memfile_free(nf);
		sub_408D90(f);
		return 0;
	}
	nf->cur = nf->data;
	nf->end = nf->data + csize;
	sub_408D90(f);
	return nf;
}

//----- (0040ACA0) --------------------------------------------------------
void nox_memfile_free(nox_memfile* f) {
	if (f->data) {
		free(f->data);
		f->data = NULL;
	}
	free(f);
}

uint8_t nox_memfile_read_u8(nox_memfile* f) {
	if (!f->data)
		return 0;
	uint8_t v = *(uint8_t*)f->cur;
	f->cur++;
	return v;
}

uint32_t nox_memfile_read_u32(nox_memfile* f) {
	if (!f->data)
		return 0;
	uint32_t v = *(uint32_t*)f->cur;
	f->cur += 4;
	return v;
}

//----- (0040ACC0) --------------------------------------------------------
unsigned int nox_memfile_read(void* dst, unsigned int sz, int cnt, nox_memfile* f) {
	unsigned int n = cnt * sz;
	if (f->cur + n > f->end)
		n = f->end - f->cur;
	memcpy(dst, f->cur, n);
	f->cur += n;
	return n / sz;
}