package nox

/*
static int go_call_int_void_func(int (*fnc)(void)) { return fnc(); }
static int go_call_int_voidPtr_func(int (*fnc)(void*), void* a1) { return fnc(a1); }
static void go_call_void2_func(void (*fnc)(void)) { fnc(); }
*/
import "C"
import "unsafe"

func cgoCallIntVoidFunc(fnc unsafe.Pointer) int {
	return int(C.go_call_int_void_func((*[0]byte)(fnc)))
}

func cgoCallIntVoidPtrFunc(fnc unsafe.Pointer, a1 unsafe.Pointer) int {
	return int(C.go_call_int_voidPtr_func((*[0]byte)(fnc), a1))
}

func cgoCallVoid2Func(fnc unsafe.Pointer) {
	C.go_call_void2_func((*[0]byte)(fnc))
}
