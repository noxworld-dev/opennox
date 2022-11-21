package opennox

/*
static int go_call_int_void_func(int (*fnc)(void)) { return fnc(); }
static void go_call_void_ptr_func(void (*fnc)(void*), void* a1) { fnc(a1); }
static void go_call_void_ptr2_func(void (*fnc)(void*, void*), void* a1, void* a2) { fnc(a1, a2); }
static void go_call_void_uint_func(void (*fnc)(unsigned int), unsigned int a1) { fnc(a1); }
static int go_call_int_voidPtr_func(int (*fnc)(void*), void* a1) { return fnc(a1); }
static void go_call_void2_func(void (*fnc)(void)) { fnc(); }
*/
import "C"
import "unsafe"

func cgoCallIntVoidFunc(fnc unsafe.Pointer) int {
	return int(C.go_call_int_void_func((*[0]byte)(fnc)))
}

func cgoCallVoidPtrFunc(fnc unsafe.Pointer, a1 unsafe.Pointer) {
	C.go_call_void_ptr_func((*[0]byte)(fnc), a1)
}

func cgoCallVoidPtr2Func(fnc unsafe.Pointer, a1, a2 unsafe.Pointer) {
	C.go_call_void_ptr2_func((*[0]byte)(fnc), a1, a2)
}

func cgoCallVoidUintFunc(fnc unsafe.Pointer, a1 uint32) {
	C.go_call_void_uint_func((*[0]byte)(fnc), C.uint(a1))
}

func cgoCallIntVoidPtrFunc(fnc unsafe.Pointer, a1 unsafe.Pointer) int {
	return int(C.go_call_int_voidPtr_func((*[0]byte)(fnc), a1))
}

func cgoCallVoid2Func(fnc unsafe.Pointer) {
	C.go_call_void2_func((*[0]byte)(fnc))
}
