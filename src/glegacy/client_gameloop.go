//go:build !server

package legacy

import "github.com/noxworld-dev/opennox/v1/client/noxrender"

func Sub_43CEB0() {
	sub_43CEB0()
}
func Sub_40A710(a1 int) uint32 {
	return uint32(sub_40A710(int(a1)))
}
func Nox_client_screenParticlesDraw_431720(vp *noxrender.Viewport) {
	nox_client_screenParticlesDraw_431720((*nox_draw_viewport_t)(vp.C()))
}
func Nox_client_newScreenParticle_431540(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 int) {
	nox_client_newScreenParticle_431540(int(a1), int(a2), int(a3), int(a4), int(a5), int(a6), char(a7), char(a8), char(a9), char(a10))
}
