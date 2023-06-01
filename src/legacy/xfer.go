package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_xfer_saveObj51DF90        func(cf *cryptfile.CryptFile, a1p *server.Object) int
	Nox_xxx_XFerDefault4F49A0         func(cf *cryptfile.CryptFile, v1 *server.Object, a2 unsafe.Pointer) error
	Nox_xxx_XFer_ReadShopItem_52A840  func(a1 unsafe.Pointer, a2 int)
	Nox_xxx_XFer_WriteShopItem_52A5F0 func(a1 unsafe.Pointer)
)

func init() {
	server.RegisterObjectXfer("DefaultXfer", ccall.FuncAddr(nox_xxx_XFerDefault_4F49A0))
	server.RegisterObjectXfer("SpellPagePedestalXfer", ccall.FuncAddr(nox_xxx_XFerSpellPagePedistal_4F4A20))
	server.RegisterObjectXfer("SpellRewardXfer", ccall.FuncAddr(nox_xxx_XFerSpellReward_4F5F30))
	server.RegisterObjectXfer("AbilityRewardXfer", ccall.FuncAddr(nox_xxx_XFerAbilityReward_4F6240))
	server.RegisterObjectXfer("FieldGuideXfer", ccall.FuncAddr(nox_xxx_XFerFieldGuide_4F6390))
	server.RegisterObjectXfer("ReadableXfer", ccall.FuncAddr(nox_xxx_XFerReadable_4F4AB0))
	server.RegisterObjectXfer("ExitXfer", ccall.FuncAddr(nox_xxx_XFerExit_4F4B90))
	server.RegisterObjectXfer("DoorXfer", ccall.FuncAddr(nox_xxx_XFerDoor_4F4CB0))
	server.RegisterObjectXfer("TriggerXfer", ccall.FuncAddr(nox_xxx_unitTriggerXfer_4F4E50))
	server.RegisterObjectXfer("MonsterXfer", ccall.FuncAddr(nox_xxx_XFerMonster_528DB0))
	server.RegisterObjectXfer("HoleXfer", ccall.FuncAddr(nox_xxx_XFerHole_4F51D0))
	server.RegisterObjectXfer("TransporterXfer", ccall.FuncAddr(nox_xxx_XFerTransporter_4F5300))
	server.RegisterObjectXfer("ElevatorXfer", ccall.FuncAddr(nox_xxx_XFerElevator_4F53D0))
	server.RegisterObjectXfer("ElevatorShaftXfer", ccall.FuncAddr(nox_xxx_XFerElevatorShaft_4F54A0))
	server.RegisterObjectXfer("MoverXfer", ccall.FuncAddr(nox_xxx_XFerMover_4F5730))
	server.RegisterObjectXfer("GlyphXfer", ccall.FuncAddr(nox_xxx_XFerGlyph_4F5890))
	server.RegisterObjectXfer("InvisibleLightXfer", ccall.FuncAddr(nox_xxx_XFerInvLight_4F5AA0))
	server.RegisterObjectXfer("SentryXfer", ccall.FuncAddr(nox_xxx_XFerSentry_4F5E50))
	server.RegisterObjectXfer("WeaponXfer", ccall.FuncAddr(nox_xxx_XFerWeapon_4F64A0))
	server.RegisterObjectXfer("ArmorXfer", ccall.FuncAddr(nox_xxx_XFerArmor_4F6860))
	server.RegisterObjectXfer("TeamXfer", ccall.FuncAddr(nox_xxx_XFerTeam_4F6D20))
	server.RegisterObjectXfer("GoldXfer", ccall.FuncAddr(nox_xxx_XFerGold_4F6EC0))
	server.RegisterObjectXfer("AmmoXfer", ccall.FuncAddr(nox_xxx_XFerAmmo_4F6B20))
	server.RegisterObjectXfer("NPCXfer", ccall.FuncAddr(nox_xxx_XFerNPC_52ADE0))
	server.RegisterObjectXfer("ObeliskXfer", ccall.FuncAddr(nox_xxx_XFerObelisk_4F6F60))
	server.RegisterObjectXfer("ToxicCloudXfer", ccall.FuncAddr(nox_xxx_XFerToxicCloud_4F70A0))
	server.RegisterObjectXfer("MonsterGeneratorXfer", ccall.FuncAddr(nox_xxx_XFerMonsterGen_4F7130))
	server.RegisterObjectXfer("RewardMarkerXfer", ccall.FuncAddr(nox_xxx_XFerRewardMarker_4F74D0))
}

// nox_xxx_xfer_saveObj_51DF90
func nox_xxx_xfer_saveObj_51DF90(a1 *nox_object_t) int {
	return Nox_xxx_xfer_saveObj51DF90(cryptfile.Global(), asObjectS(a1))
}

// nox_xxx_XFerDefault_4F49A0
func nox_xxx_XFerDefault_4F49A0(a1p *nox_object_t, a2 unsafe.Pointer) int {
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

func Get_nox_xxx_XFerFieldGuide_4F6390() unsafe.Pointer {
	return ccall.FuncAddr(nox_xxx_XFerFieldGuide_4F6390)
}

func Get_nox_xxx_XFerAbilityReward_4F6240() unsafe.Pointer {
	return ccall.FuncAddr(nox_xxx_XFerAbilityReward_4F6240)
}
func Nox_xxx_mapReadWriteObjData_4F4530(a1 *server.Object, a2 int) int {
	return int(nox_xxx_mapReadWriteObjData_4F4530(asObjectC(a1), int32(a2)))
}
func Nox_xxx_xfer_4F3E30(a1 int, a2 *server.Object, a3 uint32) int {
	return int(nox_xxx_xfer_4F3E30(uint16(a1), asObjectC(a2), int32(a3)))
}
