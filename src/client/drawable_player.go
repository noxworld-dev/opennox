package client

import "unsafe"

var _ = [1]struct{}{}[40-unsafe.Sizeof(PlayerEquipAnimation{})]

type PlayerEquipAnimation struct {
	Size    uint32 // 0, 0
	Field4  uint32 // 1, 4
	Field8  uint32 // 2, 8
	Field12 uint32 // 3, 12
	Field16 uint32 // 4, 16
	Field20 uint32 // 5, 20
	Field24 uint32 // 6, 24
	Field28 uint32 // 7, 28
	Field32 uint32 // 8, 32
	Field36 uint32 // 9, 36
}

var _ = [1]struct{}{}[264-unsafe.Sizeof(PlayerAnimation{})]

type PlayerAnimation struct {
	Base   AnimationVector                            // 0, 0
	Naked  *PlayerEquipAnimation                      // 12, 48
	Armor  [playerAnimArmorCnt]*PlayerEquipAnimation  // 13, 52
	Weapon [playerAnimWeaponCnt]*PlayerEquipAnimation // 39, 156
}

var _ = [1]struct{}{}[14524-unsafe.Sizeof(PlayerDrawData{})]

type PlayerDrawData struct {
	Size uint32                         // 0, 0
	Anim [playerAnimCnt]PlayerAnimation // 1, 4
}

const (
	playerAnimCnt       = 55
	playerAnimArmorCnt  = 26
	playerAnimWeaponCnt = 27
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

var playerAnimationsArmor = [playerAnimArmorCnt]string{
	"STREET_SNEAKERS", "MEDIEVAL_CLOAK", "STREET_PANTS", "MEDIEVAL_PANTS",
	"LEATHER_LEGGINGS", "CHAIN_LEGGINGS", "LEATHER_BOOTS", "LEATHER_ARMORED_BOOTS",
	"PLATE_BOOTS", "PLATE_LEGGINGS", "STREET_SHIRT", "MEDIEVAL_SHIRT",
	"LEATHER_ARMBANDS", "PLATE_ARMS", "WIZARD_ROBE", "LEATHER_TUNIC",
	"CHAIN_TUNIC", "PLATE_BREAST", "CHAIN_COIF", "WIZARD_HELM",
	"CONJURER_HELM", "LEATHER_HELM", "PLATE_HELM", "ORNATE_HELM",
	"ROUND_SHIELD", "KITE_SHIELD",
}

var playerAnimationsWeapons = [playerAnimWeaponCnt]string{
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
