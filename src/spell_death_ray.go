package opennox

/*
int nox_xxx_gameSetWallsDamage_4E25A0(int a1);
*/
import "C"
import (
	"image"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"
)

func castDeathRay(spellID things.SpellID, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int {
	if a5 == nil || a4 == nil {
		return 0
	}
	pos4 := a4.Pos()
	pos16 := types.Pointf{X: a5.Arg1, Y: a5.Arg2}
	if !nox_xxx_traceRay_5374B0(&pos4, &pos16) {
		if a4.Class().Has(object.ClassPlayer) && a3.Class().Has(object.ClassPlayer) {
			nox_xxx_netInformTextMsg_4DA0F0(a3.ControllingPlayer().Index(), 0, 2)
		}
		return 0
	}
	C.nox_xxx_gameSetWallsDamage_4E25A0(0)
	dmg := int(gamedataFloat("DeathRayDamage"))
	rin := float32(gamedataFloat("DeathRayInRadius"))
	rout := float32(gamedataFloat("DeathRayOutRadius"))
	nox_xxx_mapDamageUnitsAround_4E25B0(pos16, rout, rin, dmg, 16, a3, 0)
	nox_xxx_sendDeathRayCast_523250(pos4.Point(), pos16.Point())
	snd := noxServer.SpellDefByInd(spellID).GetAudio(0)
	nox_xxx_aud_501960(snd, a4, 0, 0)
	nox_xxx_sMakeScorch_537AF0(pos16, 1)
	return 1
}

func nox_xxx_sendDeathRayCast_523250(p1, p2 image.Point) {
	nox_xxx_netSendRayFx_5232F0(noxnet.MSG_FX_DEATH_RAY, p1, p2)
}
