package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) NetUpdateRemotePlrAudioEvents(obj *server.Object, v2 unsafe.Pointer, v18 int8) {
	s.Audio.ResetBitmap()
	var tm *server.Team
	if obj.HasTeam() {
		tm = s.Teams.ByID(obj.TeamVal.ID)
	}
	s.Audio.EachEvent(func(it *server.AudioEvent) {
		if it.Kind == 1 {
			tm2 := s.Teams.ByID(server.TeamID(it.Code))
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
						s.netSendAudioEvent(asObjectS(obj), it, int16(fade))
					}
				}
			}
		}
	})
	s.netSendAudioEvents(asObjectS(obj))
}

func (s *Server) netSendAudioEvents(obj *Object) {
	s.Audio.EachEventBitmap(func(it *server.AudioEvent) {
		s.netSendAudioEvent(obj, it, int16(it.Perc))
	})
}
