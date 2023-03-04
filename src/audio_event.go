package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) AudioEventObj(id sound.ID, iobj server.Obj, kind int, code uint32) {
	obj := toObjectS(iobj)
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || obj == nil || s.Audio.Field12(id) <= 0 {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassPlayer) && legacy.Sub_419E60(obj.SObj()) != 0 {
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

func (s *Server) NetUpdateRemotePlrAudioEvents(obj *server.Object, v2 unsafe.Pointer, v18 int8) {
	s.Audio.ResetBitmap()
	var tm *server.Team
	if server.Nox_xxx_servObjectHasTeam_419130(asObjectS(obj).TeamPtr()) {
		tm = s.Teams.ByYyy(byte(obj.Field13))
	}
	s.Audio.EachEvent(func(it *server.AudioEvent) {
		if it.Kind == 1 {
			tm2 := s.Teams.ByYyy(byte(it.Code))
			if tm == nil || tm2 == nil || tm != tm2 {
				return
			}
		} else if it.Kind == 2 {
			if obj.NetCode != it.Code {
				return
			}
		}
		v12 := int32(legacy.Sub_501C00(it.Pos, it.Obj))
		if v12 == int32(v18) || v12 == 0 {
			if int32(*(*uint8)(unsafe.Add(v2, 188))) != 0 || it.Sound < sound.SoundSpellPhonemeUp || it.Sound > sound.SoundSpellPhonemeUpLeft || obj.SObj() != it.Obj {
				fade := s.ai.soundFadePerc(it.Sound, it.Pos, *(*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 3632))) / 2
				if fade > 0 {
					if s.Audio.Field20(it.Sound) != 0 {
						s.Audio.AddAudio(it, fade)
					} else {
						netSendAudioEvent(asObjectS(obj), it, int16(fade))
					}
				}
			}
		}
	})
	s.netSendAudioEvents(asObjectS(obj))
}

func (s *Server) netSendAudioEvents(obj *Object) {
	s.Audio.EachEventBitmap(func(it *server.AudioEvent) {
		netSendAudioEvent(obj.AsUnit(), it, int16(it.Perc))
	})
}
