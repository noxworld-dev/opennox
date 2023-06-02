package opennox

import (
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectPickup("AudEventPickup", nox_objectPickupAudEvent_4F3D50)
}

func nox_objectPickupAudEvent_4F3D50(obj1 *server.Object, obj2 *server.Object, a3 int, a4 int) int {
	s := noxServer
	if obj1 == nil || obj2 == nil {
		return 0
	}
	ok := legacy.Nox_xxx_pickupDefault_4F31E0(obj1, obj2, a3, a4)
	if ok == 0 {
		return ok
	}
	if snd := s.PickupSound(obj2.TypeInd); snd != 0 {
		s.AudioEventObj(snd, obj1, 0, 0)
	}
	return ok
}
