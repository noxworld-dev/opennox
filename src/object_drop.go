package opennox

import (
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectDrop("AudEventDrop", nox_objectDropAudEvent_4EE2F0)
}

func nox_objectDropAudEvent_4EE2F0(obj1 *server.Object, obj2 *server.Object, a3 *types.Pointf) int {
	s := noxServer
	if obj1 == nil || obj2 == nil || a3 == nil {
		return 0
	}
	ok := legacy.Nox_xxx_dropDefault_4ED290(obj1, obj2, a3)
	if ok == 0 {
		return ok
	}
	if snd := s.DropSound(obj2.TypeInd); snd != 0 {
		s.AudioEventObj(snd, obj1, 0, 0)
	}
	return ok
}
