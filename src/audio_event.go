package opennox

/*
#include <defs.h>
char sub_501C00(float* a1, nox_object_t* a2);
int sub_419E60(nox_object_t* a1);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_xxx_getSevenDwords3_501940
func nox_xxx_getSevenDwords3_501940(i int32) int32 {
	return noxServer.Audio.Field12(sound.ID(i))
}

//export nox_xxx_aud_501960
func nox_xxx_aud_501960(a1 int32, a2p *nox_object_t, a3 int, a4 int32) {
	noxServer.AudioEventObj(sound.ID(a1), asObjectC(a2p), a3, uint32(a4))
}

//export nox_xxx_audCreate_501A30
func nox_xxx_audCreate_501A30(a1 int32, cpos *C.float2, a3 int, a4 int32) {
	noxServer.AudioEventPos(sound.ID(a1), *(*types.Pointf)(unsafe.Pointer(cpos)), a3, uint32(a4))
}

//export nox_xxx_netUpdateRemotePlr_501CA0_B
func nox_xxx_netUpdateRemotePlr_501CA0_B(a1p *nox_object_t, v2 unsafe.Pointer, v18 int8) {
	noxServer.netUpdateRemotePlrAudioEvents(asObjectC(a1p), v2, v18)
}

//export nox_xxx_utilFindSound_40AF50
func nox_xxx_utilFindSound_40AF50(name *C.char) C.int {
	return C.int(sound.ByName(GoString(name)))
}

//export nox_xxx_getSndName_40AF80
func nox_xxx_getSndName_40AF80(id C.int) *C.char {
	return internCStr(sound.ID(id).String())
}

func (s *Server) AudioEventObj(id sound.ID, iobj noxObject, kind int, code uint32) {
	obj := toObject(iobj)
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || obj == nil || s.Audio.Field12(id) <= 0 {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassPlayer) && C.sub_419E60(iobj.CObj()) != 0 {
		return
	}
	s.Audio.NewAudioEventObj(id, obj, kind, code)
	if kind != 2 {
		s.ai.NewSound(id, obj, obj.Pos())
	}
}

func (s *Server) AudioEventPos(id sound.ID, pos types.Pointf, kind int, code uint32) {
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || s.Audio.Field12(id) <= 0 {
		return
	}
	s.Audio.NewAudioEventPos(id, pos, kind, code)
	if kind != 2 {
		s.ai.NewSound(id, nil, pos)
	}
}

func (s *Server) netUpdateRemotePlrAudioEvents(obj *Object, v2 unsafe.Pointer, v18 int8) {
	s.Audio.ResetBitmap()
	var tm *Team
	if nox_xxx_servObjectHasTeam_419130(obj.teamPtr()) {
		tm = s.teamByYyy(byte(obj.Field13))
	}
	cp, free := alloc.New(types.Pointf{})
	defer free()
	s.Audio.EachEvent(func(it *server.AudioEvent) {
		if it.Kind == 1 {
			tm2 := s.teamByYyy(byte(it.Code))
			if tm == nil || tm2 == nil || tm != tm2 {
				return
			}
		} else if it.Kind == 2 {
			if obj.NetCode != it.Code {
				return
			}
		}
		*cp = it.Pos
		v12 := int32(C.sub_501C00((*C.float)(unsafe.Pointer(cp)), asObjectS(it.Obj).CObj()))
		if v12 == int32(v18) || v12 == 0 {
			if int32(*(*uint8)(unsafe.Add(v2, 188))) != 0 || it.Sound < sound.SoundSpellPhonemeUp || it.Sound > sound.SoundSpellPhonemeUpLeft || obj.SObj() != it.Obj {
				fade := s.ai.soundFadePerc(it.Sound, it.Pos, *(*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 3632))) / 2
				if fade > 0 {
					if s.Audio.Field20(it.Sound) != 0 {
						s.Audio.AddAudio(it, fade)
					} else {
						netSendAudioEvent(obj.AsUnit(), it, int16(fade))
					}
				}
			}
		}
	})
	s.netSendAudioEvents(obj)
}

func (s *Server) netSendAudioEvents(obj *Object) {
	s.Audio.EachEventBitmap(func(it *server.AudioEvent) {
		netSendAudioEvent(obj.AsUnit(), it, int16(it.Perc))
	})
}
