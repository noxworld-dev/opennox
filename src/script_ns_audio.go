package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/audio"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

func (s noxScriptNS) AudioEvent(audio audio.Name, p ns.Positioner) {
	if p == nil {
		return
	}
	snd := sound.ByName(string(audio))
	s.s.Audio.EventPos(snd, p.Pos(), 0, 0)
}

func (s noxScriptNS) Music(music int, volume int) {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_43D9B0(music, volume)
	} else {
		s.s.NetMusic(music, volume)
	}
}

func (s noxScriptNS) MusicPushEvent() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_43DA80()
	} else {
		s.s.NetMusicPushEvent()
	}
}

func (s noxScriptNS) MusicPopEvent() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_43DAD0()
	} else {
		s.s.NetMusicPopEvent()
	}
}

func (s noxScriptNS) MusicEvent() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_43D9B0(0, 0)
	} else {
		s.s.NetMusicEvent()
	}
}
