package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_xfer_saveObj51DF90        func(cf *cryptfile.CryptFile, a1p *server.Object) int
	Nox_xxx_XFerDefault4F49A0         func(cf *cryptfile.CryptFile, v1 *server.Object, a2 unsafe.Pointer) error
	Nox_xxx_XFer_ReadShopItem_52A840  func(a1 unsafe.Pointer, a2 int)
	Nox_xxx_XFer_WriteShopItem_52A5F0 func(a1 unsafe.Pointer)
)

func init() {
	server.RegisterObjectXfer("DefaultXfer", nox_xxx_XFerDefault_4F49A0)
	server.RegisterObjectXfer("SpellPagePedestalXfer", nox_xxx_XFerSpellPagePedistal_4F4A20)
	server.RegisterObjectXfer("SpellRewardXfer", nox_xxx_XFerSpellReward_4F5F30)
	server.RegisterObjectXfer("AbilityRewardXfer", Nox_xxx_XFerAbilityReward_4F6240)
	server.RegisterObjectXfer("FieldGuideXfer", Nox_xxx_XFerFieldGuide_4F6390)
	server.RegisterObjectXfer("ReadableXfer", nox_xxx_XFerReadable_4F4AB0)
	server.RegisterObjectXfer("ExitXfer", nox_xxx_XFerExit_4F4B90)
	server.RegisterObjectXfer("DoorXfer", nox_xxx_XFerDoor_4F4CB0)
	server.RegisterObjectXfer("TriggerXfer", nox_xxx_unitTriggerXfer_4F4E50)
	server.RegisterObjectXfer("MonsterXfer", nox_xxx_XFerMonster_528DB0)
	server.RegisterObjectXfer("HoleXfer", nox_xxx_XFerHole_4F51D0)
	server.RegisterObjectXfer("TransporterXfer", nox_xxx_XFerTransporter_4F5300)
	server.RegisterObjectXfer("ElevatorXfer", nox_xxx_XFerElevator_4F53D0)
	server.RegisterObjectXfer("ElevatorShaftXfer", nox_xxx_XFerElevatorShaft_4F54A0)
	server.RegisterObjectXfer("MoverXfer", nox_xxx_XFerMover_4F5730)
	server.RegisterObjectXfer("GlyphXfer", nox_xxx_XFerGlyph_4F5890)
	server.RegisterObjectXfer("InvisibleLightXfer", Nox_xxx_XFerInvLight_4F5AA0)
	server.RegisterObjectXfer("SentryXfer", nox_xxx_XFerSentry_4F5E50)
	server.RegisterObjectXfer("WeaponXfer", nox_xxx_XFerWeapon_4F64A0)
	server.RegisterObjectXfer("ArmorXfer", nox_xxx_XFerArmor_4F6860)
	server.RegisterObjectXfer("TeamXfer", nox_xxx_XFerTeam_4F6D20)
	server.RegisterObjectXfer("GoldXfer", nox_xxx_XFerGold_4F6EC0)
	server.RegisterObjectXfer("AmmoXfer", nox_xxx_XFerAmmo_4F6B20)
	server.RegisterObjectXfer("NPCXfer", nox_xxx_XFerNPC_52ADE0)
	server.RegisterObjectXfer("ObeliskXfer", nox_xxx_XFerObelisk_4F6F60)
	server.RegisterObjectXfer("ToxicCloudXfer", nox_xxx_XFerToxicCloud_4F70A0)
	server.RegisterObjectXfer("MonsterGeneratorXfer", nox_xxx_XFerMonsterGen_4F7130)
	server.RegisterObjectXfer("RewardMarkerXfer", nox_xxx_XFerRewardMarker_4F74D0)
}

// nox_xxx_xfer_saveObj_51DF90
func nox_xxx_xfer_saveObj_51DF90(a1 *server.Object) int {
	return Nox_xxx_xfer_saveObj51DF90(cryptfile.Global(), asObjectS(a1))
}

// nox_xxx_XFerDefault_4F49A0
func nox_xxx_XFerDefault_4F49A0(a1p *server.Object, a2 unsafe.Pointer) int {
	if err := Nox_xxx_XFerDefault4F49A0(cryptfile.Global(), asObjectS(a1p), a2); err != nil {
		mapLog.Println("nox_xxx_XFerDefault_4F49A0:", err)
		return 0
	}
	return 1
}

// nox_xxx_XFer_ReadShopItem_52A840
func nox_xxx_XFer_ReadShopItem_52A840(a1 unsafe.Pointer, a2 int32) {
	Nox_xxx_XFer_ReadShopItem_52A840(a1, int(a2))
}

// nox_xxx_XFer_WriteShopItem_52A5F0
func nox_xxx_XFer_WriteShopItem_52A5F0(a1 unsafe.Pointer) {
	Nox_xxx_XFer_WriteShopItem_52A5F0(a1)
}
