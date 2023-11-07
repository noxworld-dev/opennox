package server

import (
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/audio"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func (s NoxScriptNS) AudioEvent(audio audio.Name, p ns.Positioner) {
	if p == nil {
		return
	}
	snd := sound.ByName(string(audio))
	s.s.Audio.EventPos(snd, p.Pos(), 0, 0)
}
