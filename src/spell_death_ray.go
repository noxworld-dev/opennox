package opennox

/*
#include "defs.h"
void nox_xxx_sprite_45A110_drawable(nox_drawable* a1);
*/
import "C"
import (
	"image"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
)

var (
	spellDRayVioletSpark int
)

func castDeathRay(spellID spell.ID, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int {
	s := noxServer
	if a5 == nil || a4 == nil {
		return 0
	}
	pos4 := a4.Pos()
	pos16 := a5.Pos
	if !s.MapTraceRay9(pos4, pos16) {
		if a4.Class().Has(object.ClassPlayer) && a3.Class().Has(object.ClassPlayer) {
			nox_xxx_netInformTextMsg_4DA0F0(a3.ControllingPlayer().Index(), 0, 2)
		}
		return 0
	}
	dmg := int(gamedataFloat("DeathRayDamage"))
	rin := float32(gamedataFloat("DeathRayInRadius"))
	rout := float32(gamedataFloat("DeathRayOutRadius"))
	s.nox_xxx_mapDamageUnitsAround(pos16, rout, rin, dmg, 16, a3, nil, false)
	nox_xxx_sendDeathRayCast_523250(pos4.Point(), pos16.Point())
	snd := s.SpellDefByInd(spellID).GetAudio(0)
	s.AudioEventObj(snd, a4, 0, 0)
	nox_xxx_sMakeScorch_537AF0(pos16, 1)
	return 1
}

func nox_xxx_sendDeathRayCast_523250(p1, p2 image.Point) {
	nox_xxx_netSendRayFx_5232F0(noxnet.MSG_FX_DEATH_RAY, p1, p2)
}

//export nox_client_onDeathRay
func nox_client_onDeathRay(p1x, p1y, p2x, p2y C.int) {
	clientFXDeathRay(image.Pt(int(p1x), int(p1y)), image.Pt(int(p2x), int(p2y)))
}

func clientFXDeathRay(p1, p2 image.Point) {
	if !nox_client_isConnected() {
		return
	}
	dx := p2.X - p1.X
	dy := p2.Y - p1.Y
	dist := int(math.Sqrt(float64(dx*dx+dy*dy))) + 1
	if dist < 0 {
		return
	}
	if spellDRayVioletSpark == 0 {
		spellDRayVioletSpark = nox_things.IndByID("VioletSpark")
	}
	for i := 0; i < dist/2+1; i++ {
		pos := p1.Add(image.Point{
			X: (2 * dx * i) / dist,
			Y: (2 * dy * i) / dist,
		})
		dr := nox_xxx_spriteLoadAdd_45A360_drawable(int(spellDRayVioletSpark), pos)
		if dr == nil {
			continue
		}
		r1 := randomIntMinMax(0, 255)
		r2 := randomIntMinMax(1, 200)
		expire := randomIntMinMax(20, 40)
		z := randomIntMinMax(15, 30)
		vz := randomIntMinMax(-4, 4)
		dr.Field_108 = uint32(pos.X) << 12
		dr.Field_109 = uint32(pos.Y) << 12
		dr.Field_74_4 = byte(r1)
		dr.Field_110 = uint32(r2)
		dr.Field_111 = noxServer.Frame()
		*(*uint32)(unsafe.Pointer(&dr.Field_112_0)) = noxServer.Frame() + uint32(expire)
		dr.ZVal = uint16(z)
		dr.VelZ = int8(vz)
		C.nox_xxx_sprite_45A110_drawable((*nox_drawable)(dr.C()))
	}
}
