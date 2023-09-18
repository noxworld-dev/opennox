package legacy

/*
#include "client__gui__window.h"
extern unsigned int nox_client_translucentFrontWalls_805844;
extern unsigned int nox_client_highResFrontWalls_80820;
extern unsigned int nox_client_highResFloors_154952;
extern unsigned int nox_client_fadeObjects_80836;
extern unsigned int nox_client_renderBubbles_80844;
extern unsigned int dword_5d4594_1193156;
extern unsigned int dword_5d4594_1301812;
extern unsigned int dword_5d4594_1301816;
extern unsigned int dword_5d4594_1301808;
extern unsigned int dword_5d4594_1301796;
int nox_xxx_tileSetDrawFn_481420();
*/
import "C"
import "unsafe"

//export nox_client_advVideoOpts_New_4CB590
func nox_client_advVideoOpts_New_4CB590(par *nox_window) int {
	GetClient().NewGUIAdvOptsOn(asWindow(par))
	return 1
}

//export nox_client_advVideoOptsLoad_4CB330
func nox_client_advVideoOptsLoad_4CB330() {
	GetClient().GUIAdvVideoOptsLoad()
}

func Sub_49B3C0() {
	C.dword_5d4594_1301812 = 0
	C.dword_5d4594_1301816 = 0
	C.dword_5d4594_1301808 = 0
	C.dword_5d4594_1301796 = 0
}

func Set_dword_5d4594_1193156(v int) {
	C.dword_5d4594_1193156 = C.uint(v)
}

func Get_nox_client_fadeObjects_80836_ptr() *uint32 {
	return (*uint32)(unsafe.Pointer(&C.nox_client_fadeObjects_80836))
}

func Get_nox_client_translucentFrontWalls_805844_ptr() *uint32 {
	return (*uint32)(unsafe.Pointer(&C.nox_client_translucentFrontWalls_805844))
}

func Get_nox_client_highResFrontWalls_80820_ptr() *uint32 {
	return (*uint32)(unsafe.Pointer(&C.nox_client_highResFrontWalls_80820))
}

func Get_nox_client_highResFloors_154952_ptr() *uint32 {
	return (*uint32)(unsafe.Pointer(&C.nox_client_highResFloors_154952))
}
