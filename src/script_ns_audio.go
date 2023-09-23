package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/audio"
	"github.com/noxworld-dev/opennox-lib/noxnet"

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
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		buf[1] = byte(music)
		buf[2] = byte(volume)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
}

func (s noxScriptNS) MusicPushEvent() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_43DA80()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_PUSH_EVENT)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
}

func (s noxScriptNS) MusicPopEvent() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_43DAD0()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_POP_EVENT)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
}

func (s noxScriptNS) MusicEvent() {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Sub_43D9B0(0, 0)
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		s.s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
}
