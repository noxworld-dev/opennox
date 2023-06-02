package legacy

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
func nox_xxx_aud_501960(a1 int32, a2p *server.Object, a3 int32, a4 int32) {
	GetServer().AudioEventObj(sound.ID(a1), asObjectS(a2p), int(a3), uint32(a4))
}

// nox_xxx_audCreate_501A30
func nox_xxx_audCreate_501A30(a1 int32, cpos *float2, a3 int32, a4 int32) {
	GetServer().AudioEventPos(sound.ID(a1), *(*types.Pointf)(unsafe.Pointer(cpos)), int(a3), uint32(a4))
}

// nox_xxx_netUpdateRemotePlr_501CA0_B
func nox_xxx_netUpdateRemotePlr_501CA0_B(a1p *server.Object, v2 unsafe.Pointer, v18 int8) {
	GetServer().NetUpdateRemotePlrAudioEvents(asObjectS(a1p), v2, v18)
}

// nox_xxx_utilFindSound_40AF50
func nox_xxx_utilFindSound_40AF50(name *byte) int32 {
	return int32(sound.ByName(GoString(name)))
}

// nox_xxx_getSndName_40AF80
func nox_xxx_getSndName_40AF80(id int32) *byte {
	return internCStr(sound.ID(id).String())
}

func Sub_419E60(obj *server.Object) int32 {
	return int32(sub_419E60(asObjectC(obj)))
}

func Sub_501C00(p types.Pointf, obj *server.Object) int32 {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = p
	return int32(sub_501C00((*float32)(unsafe.Pointer(cp)), asObjectC(obj)))
}
