#ifndef NOX_MEMFILE_H
#define NOX_MEMFILE_H

#include <stdint.h>

typedef struct {
	char* data; // 0, 0x0, 0
	int size;   // 1, 0x4, 4
	char* cur;  // 2, 0x8, 8
	char* end;  // 3, 0xC, 12
} nox_memfile;

int8_t nox_memfile_read_i8(nox_memfile* f);
uint8_t nox_memfile_read_u8(nox_memfile* f);
int16_t nox_memfile_read_i16(nox_memfile* f);
uint16_t nox_memfile_read_u16(nox_memfile* f);
int32_t nox_memfile_read_i32(nox_memfile* f);
uint32_t nox_memfile_read_u32(nox_memfile* f);
void nox_memfile_skip(nox_memfile* f, int n);
unsigned int nox_memfile_read(void* dst, unsigned int sz, int cnt, nox_memfile* f);
unsigned int nox_memfile_read64align_40AD60(char* dest, int sz, int cnt, nox_memfile* f);

#endif // NOX_MEMFILE_H
