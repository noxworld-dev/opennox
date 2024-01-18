package client

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

var _ = [1]struct{}{}[40-unsafe.Sizeof(PlayerEquipAnimation{})]

type PlayerEquipAnimation struct {
	Size   uint32                    // 0, 0
	Frames [9]*noxrender.ImageHandle // 1, 4; [1][]noxrender.ImageHandle
}

var _ = [1]struct{}{}[264-unsafe.Sizeof(PlayerAnimation{})]

type PlayerAnimation struct {
	Base   AnimationVector                               // 0, 0
	Naked  *PlayerEquipAnimation                         // 12, 48
	Armor  [server.PlayerArmorCnt]*PlayerEquipAnimation  // 13, 52
	Weapon [server.PlayerWeaponCnt]*PlayerEquipAnimation // 39, 156
}

func (a *PlayerAnimation) FramesSlice(ptr *noxrender.ImageHandle) []noxrender.ImageHandle {
	return unsafe.Slice(ptr, a.Base.Cnt40)
}

var _ = [1]struct{}{}[14524-unsafe.Sizeof(PlayerDrawData{})]

type PlayerDrawData struct {
	Size uint32                         // 0, 0
	Anim [playerAnimCnt]PlayerAnimation // 1, 4
}

const (
	playerAnimCnt = 55
)

var playerAnimations = [playerAnimCnt]string{
	"IDLE",
	"DIE",
	"DEAD",
	"JUMP",
	"WALK",
	"WALK_AND_DRAG",
	"RUN",
	"RUNNING_JUMP",
	"PICKUP",
	"DODGE_LEFT",
	"DODGE_RIGHT",
	"ELECTROCUTED",
	"FALL",
	"TRIP",
	"GET_UP",
	"LAUGH",
	"POINT",
	"SIT",
	"SLEEP",
	"TALK",
	"TAUNT",
	"CAST_SPELL",
	"CONCENTRATE",
	"PUNCH_LEFT",
	"PUNCH_RIGHT",
	"PUNCH_RIGHT_HOOK",
	"MACE_STRIKE",
	"SWORD_STRIKE",
	"LONG_SWORD_STRIKE",
	"STAFF_STRIKE",
	"STAFF_BLOCK",
	"STAFF_SPELL_BLAST",
	"STAFF_THRUST",
	"SHOOT_BOW",
	"SHOOT_CROSSBOW",
	"AXE_STRIKE",
	"GREAT_SWORD_PARRY",
	"GREAT_SWORD_STRIKE",
	"GREAT_SWORD_IDLE",
	"HAMMER_STRIKE",
	"RAISE_SHIELD",
	"RECOIL_FORWARD",
	"RECOIL_BACKWARD",
	"RECOIL_SHIELD",
	"CHAKRAM_STRIKE",
	"BERSERKER_CHARGE",
	"WARCRY",
	"GREAT_SWORD_BLOCK_LEFT",
	"GREAT_SWORD_BLOCK_RIGHT",
	"GREAT_SWORD_BLOCK_DOWN",
	"ELECTRIC_ZAP",
	"DUST",
	"RECOIL",
	"SNEAK",
	"HARPOONTHROW",
}

var playerAnimationsArmor = [server.PlayerArmorCnt]string{
	0:  "STREET_SNEAKERS",
	1:  "MEDIEVAL_CLOAK",
	2:  "STREET_PANTS",
	3:  "MEDIEVAL_PANTS",
	4:  "LEATHER_LEGGINGS",
	5:  "CHAIN_LEGGINGS",
	6:  "LEATHER_BOOTS",
	7:  "LEATHER_ARMORED_BOOTS",
	8:  "PLATE_BOOTS",
	9:  "PLATE_LEGGINGS",
	10: "STREET_SHIRT",
	11: "MEDIEVAL_SHIRT",
	12: "LEATHER_ARMBANDS",
	13: "PLATE_ARMS",
	14: "WIZARD_ROBE",
	15: "LEATHER_TUNIC",
	16: "CHAIN_TUNIC",
	17: "PLATE_BREAST",
	18: "CHAIN_COIF",
	19: "WIZARD_HELM",
	20: "CONJURER_HELM",
	21: "LEATHER_HELM",
	22: "PLATE_HELM",
	23: "ORNATE_HELM",
	24: "ROUND_SHIELD",
	25: "KITE_SHIELD",
}

var playerAnimationsWeapons = [server.PlayerWeaponCnt]string{
	"FLAG",
	"QUIVER",
	"BOW",
	"CROSSBOW",
	"ARROW",
	"BOLT",
	"CHAKRAM",
	"SHURIKEN",
	"SWORD",
	"LONG_SWORD",
	"GREAT_SWORD",
	"MACE",
	"AXE",
	"OGRE_AXE",
	"HAMMER",
	"STAFF",
	"STAFF_SULPHOROUS_FLARE",
	"STAFF_SULPHOROUS_SHOWER",
	"STAFF_LIGHTNING",
	"STAFF_FIREBALL",
	"STAFF_TRIPLE_FIREBALL",
	"STAFF_FORCE_OF_NATURE",
	"STAFF_DEATH_RAY",
	"STAFF_OBLIVION_HALBERD",
	"STAFF_OBLIVION_HEART",
	"STAFF_OBLIVION_WIERDLING",
	"STAFF_OBLIVION_ORB",
}
