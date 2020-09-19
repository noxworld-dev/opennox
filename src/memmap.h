#ifndef NOX_MEMMAP_H
#define NOX_MEMMAP_H
#include <stdint.h>

// unknown element size; assumes int
#define MEMLOG_UNK_SIZE sizeof(int)

// direct memory access used by mods; accesses mapped variables
#define MEMACCESS(x) *((_DWORD*)getMem(x))
uint8_t* getMem(uintptr_t addr);

// direct memory access that was yet to be refactored

#ifndef NOX_LOG_MEM

// generic
void* mem_getPtr(uintptr_t base, uintptr_t off);
void* mem_getPtrSize(uintptr_t base, uintptr_t off, uintptr_t size);

// specific
#define MEM_FUNC_PTR(T, NAME) T* NAME(uintptr_t base, uintptr_t off);
MEM_FUNC_PTR(uint8_t, mem_getU8Ptr)
MEM_FUNC_PTR( int8_t, mem_getI8Ptr)
MEM_FUNC_PTR(uint16_t, mem_getU16Ptr)
MEM_FUNC_PTR( int16_t, mem_getI16Ptr)
MEM_FUNC_PTR(uint32_t, mem_getU32Ptr)
MEM_FUNC_PTR( int32_t, mem_getI32Ptr)
MEM_FUNC_PTR(uint64_t, mem_getU64Ptr)
MEM_FUNC_PTR( int64_t, mem_getI64Ptr)
MEM_FUNC_PTR(float, mem_getFloatPtr)
MEM_FUNC_PTR(double, mem_getDoublePtr)

// public interface; same regardless of NOX_LOG_MEM
#define getMemAt mem_getPtr
#define getMemAt mem_getPtr
#define getMemU8Ptr mem_getU8Ptr
#define getMemI8Ptr mem_getI8Ptr
#define getMemU16Ptr mem_getU16Ptr
#define getMemI16Ptr mem_getI16Ptr
#define getMemU32Ptr mem_getU32Ptr
#define getMemI32Ptr mem_getI32Ptr
#define getMemU64Ptr mem_getU64Ptr
#define getMemI64Ptr mem_getI64Ptr
#define getMemFloatPtr mem_getFloatPtr
#define getMemDoublePtr mem_getDoublePtr

#else // NOX_LOG_MEM

// generic
void* mem_getPtr(const char* fnc, uintptr_t base, uintptr_t off);
void* mem_getPtrSize(const char* fnc, uintptr_t base, uintptr_t off, uintptr_t size);

// internal api to help debug issues
void maybeLogRead(const char* fnc, void* ptr, int sz);
void maybeLogWrite(const char* fnc, void* ptr, int sz);

// specific
#define MEM_FUNC_PTR(T, NAME) T* NAME(const char* fnc, uintptr_t base, uintptr_t off);
MEM_FUNC_PTR(uint8_t, mem_getU8Ptr)
MEM_FUNC_PTR( int8_t, mem_getI8Ptr)
MEM_FUNC_PTR(uint16_t, mem_getU16Ptr)
MEM_FUNC_PTR( int16_t, mem_getI16Ptr)
MEM_FUNC_PTR(uint32_t, mem_getU32Ptr)
MEM_FUNC_PTR( int32_t, mem_getI32Ptr)
MEM_FUNC_PTR(uint64_t, mem_getU64Ptr)
MEM_FUNC_PTR( int64_t, mem_getI64Ptr)
MEM_FUNC_PTR(float, mem_getFloatPtr)
MEM_FUNC_PTR(double, mem_getDoublePtr)

// public interface; same regardless of NOX_LOG_MEM
#define getMemAt(x, y) mem_getPtr(__func__, x, y)
#define getMemU8Ptr(x, y) mem_getU8Ptr(__func__, x, y)
#define getMemI8Ptr(x, y) mem_getI8Ptr(__func__, x, y)
#define getMemU16Ptr(x, y) mem_getU16Ptr(__func__, x, y)
#define getMemI16Ptr(x, y) mem_getI16Ptr(__func__, x, y)
#define getMemU32Ptr(x, y) mem_getU32Ptr(__func__, x, y)
#define getMemI32Ptr(x, y) mem_getI32Ptr(__func__, x, y)
#define getMemU64Ptr(x, y) mem_getU64Ptr(__func__, x, y)
#define getMemI64Ptr(x, y) mem_getI64Ptr(__func__, x, y)
#define getMemFloatPtr(x, y) mem_getFloatPtr(__func__, x, y)
#define getMemDoublePtr(x, y) mem_getDoublePtr(__func__, x, y)

// memory tracking for stdlib functions
#include <stdio.h>

#ifndef NOX_IN_MEMMAP
#define memset(x, y, z) nox_memset(__func__, x, y, z)
#define memcpy(x, y, z) nox_memcpy(__func__, x, y, z)
#define strlen(x) nox_strlen(__func__, x)
#define strcpy(x, y) nox_strcpy(__func__, x, y)
#define fread(x, y, z, f) nox_fread(__func__, x, y, z, f)
#define fwrite(x, y, z, f) nox_fwrite(__func__, x, y, z, f)
#endif // NOX_IN_MEMMAP

void nox_memset(const char* fnc, void* ptr, int v, int sz);
void nox_memcpy(const char* fnc, void* dst, void* src, int sz);
int nox_strlen(const char* fnc, const char* src);
int nox_strcpy(const char* fnc, char* dst, const char* src);
size_t nox_fread(const char* fnc, void* ptr, size_t size, size_t count, FILE* stream);
size_t nox_fwrite(const char* fnc, void* ptr, size_t size, size_t count, FILE* stream);

#endif // NOX_LOG_MEM

// common helpers
#define getMemByte(base, off) (*getMemU8Ptr(base, off))
#define getMemIntPtr getMemI32Ptr
#define getMemUintPtr getMemU32Ptr

#endif // NOX_MEMMAP_H