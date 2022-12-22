package ccall

/*
static void go_call_void2_func(void (*fnc)(void)) { fnc(); }

static void go_call_void_uint_func(void (*fnc)(unsigned int), unsigned int a1) { fnc(a1); }

static void go_call_void_ptr_func(void (*fnc)(void*), void* a1) { fnc(a1); }
static void go_call_void_ptr2_func(void (*fnc)(void*, void*), void* a1, void* a2) { fnc(a1, a2); }
static void go_call_void_ptr3_func(void (*fnc)(void*, void*, void*), void* a1, void* a2, void* a3) { fnc(a1, a2, a3); }
static void go_call_void_ptr4_func(void (*fnc)(void*, void*, void*, void*), void* a1, void* a2, void* a3, void* a4) { fnc(a1, a2, a3, a4); }
static void go_call_void_ptr5_func(void (*fnc)(void*, void*, void*, void*, void*), void* a1, void* a2, void* a3, void* a4, void* a5) { fnc(a1, a2, a3, a4, a5); }
static void go_call_void_ptr6_func(void (*fnc)(void*, void*, void*, void*, void*, void*), void* a1, void* a2, void* a3, void* a4, void* a5, void* a6) { fnc(a1, a2, a3, a4, a5, a6); }

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
	C.go_call_void_ptr_func((*[0]byte)(fnc), a1)
}

func CallVoidPtr2(fnc unsafe.Pointer, a1, a2 unsafe.Pointer) {
	C.go_call_void_ptr2_func((*[0]byte)(fnc), a1, a2)
}

func CallVoidPtr3(fnc unsafe.Pointer, a1, a2, a3 unsafe.Pointer) {
	C.go_call_void_ptr3_func((*[0]byte)(fnc), a1, a2, a3)
}

func CallVoidPtr4(fnc unsafe.Pointer, a1, a2, a3, a4 unsafe.Pointer) {
	C.go_call_void_ptr4_func((*[0]byte)(fnc), a1, a2, a3, a4)
}

func CallVoidPtr5(fnc unsafe.Pointer, a1, a2, a3, a4, a5 unsafe.Pointer) {
	C.go_call_void_ptr5_func((*[0]byte)(fnc), a1, a2, a3, a4, a5)
}

func CallVoidPtr6(fnc unsafe.Pointer, a1, a2, a3, a4, a5, a6 unsafe.Pointer) {
	C.go_call_void_ptr6_func((*[0]byte)(fnc), a1, a2, a3, a4, a5, a6)
}

func CallIntVoid(fnc unsafe.Pointer) int {
	return int(C.go_call_int_void_func((*[0]byte)(fnc)))
}

func CallIntVoidPtr(fnc unsafe.Pointer, a1 unsafe.Pointer) int {
	return int(C.go_call_int_voidPtr_func((*[0]byte)(fnc), a1))
}
