package legacy

/*
#include <defs.h>
char sub_501C00(float* a1, nox_object_t* a2);
int sub_419E60(nox_object_t* a1);
*/

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

// nox_xxx_getSevenDwords3_501940
func nox_xxx_getSevenDwords3_501940(i int32) int32 {
	return GetServer().S().Audio.Field12(sound.ID(i))
}

// nox_xxx_aud_501960
func nox_xxx_aud_501960(a1 int32, a2p *nox_object_t, a3 int, a4 int32) {
	GetServer().AudioEventObj(sound.ID(a1), asObjectS(a2p), a3, uint32(a4))
}

// nox_xxx_audCreate_501A30
func nox_xxx_audCreate_501A30(a1 int32, cpos *float2, a3 int, a4 int32) {
	GetServer().AudioEventPos(sound.ID(a1), *(*types.Pointf)(unsafe.Pointer(cpos)), a3, uint32(a4))
}

// nox_xxx_netUpdateRemotePlr_501CA0_B
func nox_xxx_netUpdateRemotePlr_501CA0_B(a1p *nox_object_t, v2 unsafe.Pointer, v18 int8) {
	GetServer().NetUpdateRemotePlrAudioEvents(asObjectS(a1p), v2, v18)
}

// nox_xxx_utilFindSound_40AF50
func nox_xxx_utilFindSound_40AF50(name *char) int {
	return int(sound.ByName(GoString(name)))
}

// nox_xxx_getSndName_40AF80
func nox_xxx_getSndName_40AF80(id int) *char {
	return internCStr(sound.ID(id).String())
}

func Sub_419E60(obj *server.Object) int {
	return int(sub_419E60(asObjectC(obj)))
}

func Sub_501C00(p types.Pointf, obj *server.Object) int {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
	return int(sub_501C00((*float)(unsafe.Pointer(cp)), asObjectC(obj)))
}
