//go:build !server

package legacy

import "github.com/noxworld-dev/opennox/v1/client/noxrender"

func Sub_43CEB0() {
	sub_43CEB0()
}
func Sub_40A710(a1 int) uint32 {
	return uint32(sub_40A710(int32(a1)))
}
func Nox_client_screenParticlesDraw_431720(vp *noxrender.Viewport) {
	nox_client_screenParticlesDraw_431720((*nox_draw_viewport_t)(vp.C()))
}
func Nox_client_newScreenParticle_431540(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 int) {
	nox_client_newScreenParticle_431540(int32(a1), int32(a2), int32(a3), int32(a4), int32(a5), int32(a6), int8(a7), int8(a8), int8(a9), int8(a10))
}
