package legacy

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectUse("ConsumeUse", nox_xxx_useConsume_53EE10, 4)
	server.RegisterObjectUse("ConsumeConfuseUse", nox_xxx_useCiderConfuse_53EF00, 4)
	server.RegisterObjectUse("FireWandUse", nox_xxx_useFireWand_53F670, 0)
	server.RegisterObjectUse("CastUse", nox_xxx_useCast_53ED90, 4)
	server.RegisterObjectUse("EnchantUse", nox_xxx_useEnchant_53ED60, 8)
	server.RegisterObjectUse("MushroomUse", nox_xxx_useMushroom_53ECE0, 0)
	server.RegisterObjectUse("ReadUse", nox_xxx_useRead_53F7C0, 260)
	server.RegisterObjectUse("WarpReadUse", sub_53F830, 260)
	server.RegisterObjectUse("WandUse", nox_xxx_useLesserFireballStaff_53F290, 116)
	server.RegisterObjectUse("WandCastUse", nox_xxx_useWandCastSpell_53F4F0, 116)
	server.RegisterObjectUse("SpellRewardUse", nox_xxx_useSpellReward_53F9E0, 1)
	server.RegisterObjectUse("AbilityRewardUse", nox_xxx_useAbilityReward_53FAE0, 1)
	server.RegisterObjectUse("FieldGuideUse", sub_53F930, 64)
	server.RegisterObjectUse("PotionUse", nox_xxx_usePotion_53EF70, 4)

	server.RegisterObjectUseParse("ConsumeUse", wrapObjectUseParseC(sub_536390))
	server.RegisterObjectUseParse("ConsumeConfuseUse", wrapObjectUseParseC(sub_536390))
	server.RegisterObjectUseParse("CastUse", wrapObjectUseParseC(sub_536180))
	server.RegisterObjectUseParse("EnchantUse", wrapObjectUseParseC(sub_536130))
	server.RegisterObjectUseParse("WandUse", wrapObjectUseParseC(sub_536260))
	server.RegisterObjectUseParse("WandCastUse", wrapObjectUseParseC(sub_5361B0))
	server.RegisterObjectUseParse("PotionUse", wrapObjectUseParseC(sub_5363C0))
}

func wrapObjectUseParseC(ptr unsafe.Pointer) server.ObjectParseFunc {
	return func(objt *server.ObjectType, args []string) error {
		if Nox_call_objectType_parseUse_go(ptr, strings.Join(args, " "), objt.UseData) == 0 {
			return fmt.Errorf("cannot parse use data for %q", objt.ID())
		}
		return nil
	}
}

func Nox_call_objectType_parseUse_go(a1 unsafe.Pointer, a2 string, a3 unsafe.Pointer) int {
	cstr := CString(a2)
	defer StrFree(cstr)
	return int(asFuncT[func(*char, unsafe.Pointer) int32](uintptr(a1))(cstr, a3))
}
