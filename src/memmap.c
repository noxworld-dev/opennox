// must be before any includes
#define NOX_IN_MEMMAP
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// unknown element size; assumes int
#define MEMLOG_UNK_SIZE sizeof(int)

extern unsigned char byte_581450[23472];
extern unsigned char byte_5D4594[3844309];
extern unsigned char byte_587000[316820];
extern unsigned int mix_dword_980858[3];

typedef struct mem_blob {
	uintptr_t base;
	uintptr_t size;
	unsigned char* ptr;
} mem_blob;

mem_blob blobs[] = { // keep them sorted!
#if 0
	{0x563002, sizeof(byte_563002), byte_563002},
	{0x563006, sizeof(byte_563006), byte_563006},
#endif
	{0x581450, sizeof(byte_581450), byte_581450},
	{0x587000, sizeof(byte_587000), byte_587000},
	{0x5D4594, sizeof(byte_5D4594), byte_5D4594},
	{0x980858, sizeof(mix_dword_980858), mix_dword_980858},
};

size_t blobs_cnt = sizeof(blobs) / sizeof(mem_blob);

#ifndef NOX_CGO_MEMMAP
void* mem_getPtrSize(uintptr_t base, uintptr_t off, uintptr_t size) {
	switch (base) {
	case 0x581450:
		return &byte_581450[off];
	case 0x587000:
		return &byte_587000[off];
	case 0x5D4594:
		return &byte_5D4594[off];
	case 0x980858:
		return &((char*)mix_dword_980858)[off];
	}
	fprintf(stderr, "Invalid memory access! Requested = %x+%d[%d]\n", base, off, size);
	abort();
	return 0;
}
#else // NOX_CGO
void* mem_getPtrSize(uintptr_t base, uintptr_t off, uintptr_t size);
#endif // NOX_CGO

// defined in the header, emits the signature; we need an implementation now
#undef MEM_FUNC_PTR

#ifndef NOX_CGO_MEMMAP
void* mem_getPtr(uintptr_t base, uintptr_t off) { return mem_getPtrSize(base, off, MEMLOG_UNK_SIZE); }
#endif // NOX_CGO
#define MEM_FUNC_PTR(T, NAME, SIZE) T* NAME(uintptr_t base, uintptr_t off) { return (T*)mem_getPtrSize(base, off, SIZE); }

MEM_FUNC_PTR(uint8_t, mem_getU8Ptr, 1)
MEM_FUNC_PTR( int8_t, mem_getI8Ptr, 1)
MEM_FUNC_PTR(uint16_t, mem_getU16Ptr, 2)
MEM_FUNC_PTR( int16_t, mem_getI16Ptr, 2)
MEM_FUNC_PTR(uint32_t, mem_getU32Ptr, 4)
MEM_FUNC_PTR( int32_t, mem_getI32Ptr, 4)
MEM_FUNC_PTR(uint64_t, mem_getU64Ptr, 8)
MEM_FUNC_PTR( int64_t, mem_getI64Ptr, 8)
MEM_FUNC_PTR(float, mem_getFloatPtr, 4)
MEM_FUNC_PTR(double, mem_getDoublePtr, 8)
