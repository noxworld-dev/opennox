package ccall

/*
#include <stdint.h>

static void go_call_void2_func(void (*fnc)(void)) { fnc(); }

static void go_call_void_uint_func(void (*fnc)(unsigned int), unsigned int a1) { fnc(a1); }

static void go_call_void_uptr_func(void (*fnc)(uintptr_t), uintptr_t a1) { fnc(a1); }
static void go_call_void_uptr2_func(void (*fnc)(uintptr_t, uintptr_t), uintptr_t a1, uintptr_t a2) { fnc(a1, a2); }
static void go_call_void_uptr3_func(void (*fnc)(uintptr_t, uintptr_t, uintptr_t), uintptr_t a1, uintptr_t a2, uintptr_t a3) { fnc(a1, a2, a3); }
static void go_call_void_uptr4_func(void (*fnc)(uintptr_t, uintptr_t, uintptr_t, uintptr_t), uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4) { fnc(a1, a2, a3, a4); }
static void go_call_void_uptr5_func(void (*fnc)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t), uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) { fnc(a1, a2, a3, a4, a5); }
static void go_call_void_uptr6_func(void (*fnc)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t), uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5, uintptr_t a6) { fnc(a1, a2, a3, a4, a5, a6); }

static int go_call_int_void_func(int (*fnc)(void)) { return fnc(); }
static int go_call_int_voidPtr_func(int (*fnc)(void*), void* a1) { return fnc(a1); }
*/
import "C"
import "unsafe"

func CallVoid(fnc unsafe.Pointer) {
	C.go_call_void2_func((*[0]byte)(fnc))
}

func CallVoidUint(fnc unsafe.Pointer, a1 uint32) {
	C.go_call_void_uint_func((*[0]byte)(fnc), C.uint(a1))
}

func CallVoidPtr(fnc unsafe.Pointer, a1 unsafe.Pointer) {
	C.go_call_void_uptr_func((*[0]byte)(fnc), C.uintptr_t(uintptr(a1)))
}

func CallVoidPtr2(fnc unsafe.Pointer, a1, a2 unsafe.Pointer) {
	C.go_call_void_uptr2_func((*[0]byte)(fnc), C.uintptr_t(uintptr(a1)), C.uintptr_t(uintptr(a2)))
}

func CallVoidPtr3(fnc unsafe.Pointer, a1, a2, a3 unsafe.Pointer) {
	C.go_call_void_uptr3_func((*[0]byte)(fnc), C.uintptr_t(uintptr(a1)), C.uintptr_t(uintptr(a2)), C.uintptr_t(uintptr(a3)))
}

func CallVoidPtr4(fnc unsafe.Pointer, a1, a2, a3, a4 unsafe.Pointer) {
	C.go_call_void_uptr4_func((*[0]byte)(fnc), C.uintptr_t(uintptr(a1)), C.uintptr_t(uintptr(a2)), C.uintptr_t(uintptr(a3)), C.uintptr_t(uintptr(a4)))
}

func CallVoidPtr5(fnc unsafe.Pointer, a1, a2, a3, a4, a5 unsafe.Pointer) {
	C.go_call_void_uptr5_func((*[0]byte)(fnc), C.uintptr_t(uintptr(a1)), C.uintptr_t(uintptr(a2)), C.uintptr_t(uintptr(a3)), C.uintptr_t(uintptr(a4)), C.uintptr_t(uintptr(a5)))
}

func CallVoidPtr6(fnc unsafe.Pointer, a1, a2, a3, a4, a5, a6 unsafe.Pointer) {
	C.go_call_void_uptr6_func((*[0]byte)(fnc), C.uintptr_t(uintptr(a1)), C.uintptr_t(uintptr(a2)), C.uintptr_t(uintptr(a3)), C.uintptr_t(uintptr(a4)), C.uintptr_t(uintptr(a5)), C.uintptr_t(uintptr(a6)))
}

func CallVoidUPtr(fnc unsafe.Pointer, a1 uintptr) {
	C.go_call_void_uptr_func((*[0]byte)(fnc), C.uintptr_t(a1))
}

func CallVoidUPtr2(fnc unsafe.Pointer, a1, a2 uintptr) {
	C.go_call_void_uptr2_func((*[0]byte)(fnc), C.uintptr_t(a1), C.uintptr_t(a2))
}

func CallVoidUPtr3(fnc unsafe.Pointer, a1, a2, a3 uintptr) {
	C.go_call_void_uptr3_func((*[0]byte)(fnc), C.uintptr_t(a1), C.uintptr_t(a2), C.uintptr_t(a3))
}

func CallVoidUPtr4(fnc unsafe.Pointer, a1, a2, a3, a4 uintptr) {
	C.go_call_void_uptr4_func((*[0]byte)(fnc), C.uintptr_t(a1), C.uintptr_t(a2), C.uintptr_t(a3), C.uintptr_t(a4))
}

func CallVoidUPtr5(fnc unsafe.Pointer, a1, a2, a3, a4, a5 uintptr) {
	C.go_call_void_uptr5_func((*[0]byte)(fnc), C.uintptr_t(a1), C.uintptr_t(a2), C.uintptr_t(a3), C.uintptr_t(a4), C.uintptr_t(a5))
}

func CallVoidUPtr6(fnc unsafe.Pointer, a1, a2, a3, a4, a5, a6 uintptr) {
	C.go_call_void_uptr6_func((*[0]byte)(fnc), C.uintptr_t(a1), C.uintptr_t(a2), C.uintptr_t(a3), C.uintptr_t(a4), C.uintptr_t(a5), C.uintptr_t(a6))
}

func CallIntVoid(fnc unsafe.Pointer) int {
	return int(C.go_call_int_void_func((*[0]byte)(fnc)))
}

func CallIntVoidPtr(fnc unsafe.Pointer, a1 unsafe.Pointer) int {
	return int(C.go_call_int_voidPtr_func((*[0]byte)(fnc), a1))
}
