#ifndef NOX_MEMMAP_H
#define NOX_MEMMAP_H
#include <stdint.h>

// generic
extern void* mem_getPtr(uintptr_t base, uintptr_t off);
extern void* mem_getPtrSize(uintptr_t base, uintptr_t off, uintptr_t size);

// specific
#define MEM_FUNC_PTR(T, NAME) extern T* NAME(uintptr_t base, uintptr_t off);
MEM_FUNC_PTR(uint8_t, mem_getU8Ptr)
MEM_FUNC_PTR(int8_t, mem_getI8Ptr)
MEM_FUNC_PTR(uint16_t, mem_getU16Ptr)
MEM_FUNC_PTR(int16_t, mem_getI16Ptr)
MEM_FUNC_PTR(uint32_t, mem_getU32Ptr)
MEM_FUNC_PTR(int32_t, mem_getI32Ptr)
MEM_FUNC_PTR(uint64_t, mem_getU64Ptr)
MEM_FUNC_PTR(int64_t, mem_getI64Ptr)
MEM_FUNC_PTR(float, mem_getFloatPtr)
MEM_FUNC_PTR(double, mem_getDoublePtr)

// public interface
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

// common helpers
#define getMemByte(base, off) (*getMemU8Ptr(base, off))
#define getMemIntPtr getMemI32Ptr
#define getMemUintPtr getMemU32Ptr

#endif // NOX_MEMMAP_H
