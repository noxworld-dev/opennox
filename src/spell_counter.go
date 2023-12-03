package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_cspellRemoveSpell_52BC90(obj *server.Object) {
	sobj := asObjectS(obj)
	s := obj.Server()
	if !obj.SubClass().AsMissile().Has(object.MissileMissileCounterSpell) {
		return
	}
	if obj.Flags().Has(object.FlagDestroyed) {
		return
	}
	s.Nox_xxx_netSendPointFx_522FF0(noxnet.MSG_FX_COUNTERSPELL_EXPLOSION, obj.PosVec)
	switch int(obj.TypeInd) {
	case s.Types.MagicID():
		sobj.Delete()
	case s.Types.DeathBallID():
		nox_xxx_deathBallCreateFragments_52BD30(obj)
		sobj.Delete()
	default:
		obj.CallCollide(0, 0)
		if !obj.Flags().Has(object.FlagDestroyed) {
			sobj.Delete()
		}
	}
}
