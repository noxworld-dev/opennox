package noxscript

import (
	asm "github.com/noxworld-dev/opennox-lib/script/noxscript/noxasm"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns/audio"
)

func init() {
	Register(asm.BuiltinAudioEvent, nsAudioEvent)
	Register(asm.BuiltinMusic, nsMusic)
	Register(asm.BuiltinMusicPushEvent, nsMusicPushEvent)
	Register(asm.BuiltinMusicPopEvent, nsMusicPopEvent)
	Register(asm.BuiltinMusicEvent, nsMusicEvent)
}

func nsAudioEvent(s VM) int {
	wp := s.PopWaypointNS()
	snd := audio.Name(s.PopString())
	if wp != nil {
		s.NoxScript().AudioEvent(snd, wp)
	}
	return 0
}

func nsMusic(s VM) int {
	a2 := int(s.PopU32())
	a1 := int(s.PopU32())
	s.NoxScript().Music(a1, a2)
	return 0
}

func nsMusicPushEvent(s VM) int {
	s.NoxScript().MusicPushEvent()
	return 0
}

func nsMusicPopEvent(s VM) int {
	s.NoxScript().MusicPopEvent()
	return 0
}

func nsMusicEvent(s VM) int {
	s.NoxScript().MusicEvent()
	return 0
}
