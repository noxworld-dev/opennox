package legacy

/*
#include <defs.h>
char sub_501C00(float* a1, nox_object_t* a2);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_xxx_getSevenDwords3_501940
func nox_xxx_getSevenDwords3_501940(i int32) int32 {
	return GetServer().S().Audio.Field12(sound.ID(i))
}

//export nox_xxx_aud_501960
func nox_xxx_aud_501960(a1 int32, a2p *nox_object_t, a3 int, a4 int32) {
	GetServer().AudioEventObj(sound.ID(a1), asObjectS(a2p), a3, uint32(a4))
}

//export nox_xxx_audCreate_501A30
func nox_xxx_audCreate_501A30(a1 int32, cpos *C.float2, a3 int, a4 int32) {
	GetServer().AudioEventPos(sound.ID(a1), *(*types.Pointf)(unsafe.Pointer(cpos)), a3, uint32(a4))
}

//export nox_xxx_netUpdateRemotePlr_501CA0_B
func nox_xxx_netUpdateRemotePlr_501CA0_B(a1p *nox_object_t, v2 unsafe.Pointer, v18 int8) {
	GetServer().NetUpdateRemotePlrAudioEvents(asObjectS(a1p), v2, v18)
}

//export nox_xxx_utilFindSound_40AF50
func nox_xxx_utilFindSound_40AF50(name *C.char) int {
	return int(sound.ByName(GoString(name)))
}

//export nox_xxx_getSndName_40AF80
func nox_xxx_getSndName_40AF80(id int) *C.char {
	return internCStr(sound.ID(id).String())
}

func Sub_501C00(p types.Pointf, obj *server.Object) int {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
	return int(C.sub_501C00((*C.float)(unsafe.Pointer(cp)), asObjectC(obj)))
}
