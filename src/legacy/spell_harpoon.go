package legacy

/*
#include "GAME4_3.h"
#include "GAME5_2.h"
*/
import "C"
import "github.com/noxworld-dev/opennox/v1/server"

var (
	Nox_xxx_harpoonBreakForPlr_537520 func(u *server.Object)
	Nox_xxx_collideHarpoon_4EB6A0     func(a1c *server.Object, a2c *server.Object)
	Nox_xxx_updateHarpoon_54F380      func(a1c *server.Object)
)

//export nox_xxx_harpoonBreakForPlr_537520
func nox_xxx_harpoonBreakForPlr_537520(u *nox_object_t) {
	Nox_xxx_harpoonBreakForPlr_537520(asObjectS(u))
}

//export nox_xxx_collideHarpoon_4EB6A0
func nox_xxx_collideHarpoon_4EB6A0(a1c *nox_object_t, a2c *nox_object_t) {
	Nox_xxx_collideHarpoon_4EB6A0(asObjectS(a1c), asObjectS(a2c))
}

//export nox_xxx_updateHarpoon_54F380
func nox_xxx_updateHarpoon_54F380(a1c *nox_object_t) { Nox_xxx_updateHarpoon_54F380(asObjectS(a1c)) }
func Nox_xxx_damageToMap_534BC0(a1 int, a2 int, a3 int, a4 int, a5 *server.Object) {
	C.nox_xxx_damageToMap_534BC0(C.int(a1), C.int(a2), C.int(a3), C.int(a4), asObjectC(a5))
}
func Nox_xxx_soundDefaultDamageSound_532E20(a1 *server.Object, a2 *server.Object) {
	C.nox_xxx_soundDefaultDamageSound_532E20(asObjectC(a1), asObjectC(a2))
}
