package ai

import (
	"fmt"

	"nox/v1/common/log"
)

var (
	Log = log.New("ai")
)

type ActionType uint32

func (t ActionType) String() string {
	if s := actionNames[t]; s != "" {
		return s
	}
	return fmt.Sprintf("ai.Action(%d)", int(t))
}

func (t ActionType) IsCondition() bool { // nox_xxx_monsterActionIsCondition_50A010
	return t >= DEPENDENCY_OR && t <= DEPENDENCY_NOT_MOVED
}

const (
	ACTION_IDLE                           = ActionType(0)
	ACTION_WAIT                           = ActionType(1)
	ACTION_WAIT_RELATIVE                  = ActionType(2)
	ACTION_ESCORT                         = ActionType(3)
	ACTION_GUARD                          = ActionType(4)
	ACTION_HUNT                           = ActionType(5)
	ACTION_RETREAT                        = ActionType(6)
	ACTION_MOVE_TO                        = ActionType(7)
	ACTION_FAR_MOVE_TO                    = ActionType(8)
	ACTION_DODGE                          = ActionType(9)
	ACTION_ROAM                           = ActionType(10)
	ACTION_PICKUP_OBJECT                  = ActionType(11)
	ACTION_DROP_OBJECT                    = ActionType(12)
	ACTION_FIND_OBJECT                    = ActionType(13)
	ACTION_RETREAT_TO_MASTER              = ActionType(14)
	ACTION_FIGHT                          = ActionType(15)
	ACTION_MELEE_ATTACK                   = ActionType(16)
	ACTION_MISSILE_ATTACK                 = ActionType(17)
	ACTION_CAST_SPELL_ON_OBJECT           = ActionType(18)
	ACTION_CAST_SPELL_ON_LOCATION         = ActionType(19)
	ACTION_CAST_DURATION_SPELL            = ActionType(20)
	ACTION_BLOCK_ATTACK                   = ActionType(21)
	ACTION_BLOCK_FINISH                   = ActionType(22)
	ACTION_WEAPON_BLOCK                   = ActionType(23)
	ACTION_FLEE                           = ActionType(24)
	ACTION_FACE_LOCATION                  = ActionType(25)
	ACTION_FACE_OBJECT                    = ActionType(26)
	ACTION_FACE_ANGLE                     = ActionType(27)
	ACTION_SET_ANGLE                      = ActionType(28)
	ACTION_RANDOM_WALK                    = ActionType(29)
	ACTION_DYING                          = ActionType(30)
	ACTION_DEAD                           = ActionType(31)
	ACTION_REPORT                         = ActionType(32)
	ACTION_MORPH_INTO_CHEST               = ActionType(33)
	ACTION_MORPH_BACK_TO_SELF             = ActionType(34)
	ACTION_GET_UP                         = ActionType(35)
	ACTION_CONFUSED                       = ActionType(36)
	ACTION_MOVE_TO_HOME                   = ActionType(37)
	ACTION_INVALID                        = ActionType(38)
	DEPENDENCY_OR                         = ActionType(40)
	DEPENDENCY_TIME                       = ActionType(41)
	DEPENDENCY_ALIVE                      = ActionType(42)
	DEPENDENCY_UNDER_ATTACK               = ActionType(43)
	DEPENDENCY_NOT_UNDER_ATTACK           = ActionType(44)
	DEPENDENCY_CAN_SEE                    = ActionType(45)
	DEPENDENCY_CANNOT_SEE                 = ActionType(46)
	DEPENDENCY_BLOCKED_LINE_OF_FIRE       = ActionType(47)
	DEPENDENCY_OBJECT_AT_VISIBLE_LOCATION = ActionType(48)
	DEPENDENCY_OBJECT_FARTHER_THAN        = ActionType(49)
	DEPENDENCY_OBJECT_CLOSER_THAN         = ActionType(50)
	DEPENDENCY_LOCATION_FARTHER_THAN      = ActionType(51)
	DEPENDENCY_LOCATION_CLOSER_THAN       = ActionType(52)
	DEPENDENCY_VISIBLE_ENEMY              = ActionType(53)
	DEPENDENCY_VISIBLE_FRIEND             = ActionType(54)
	DEPENDENCY_VISIBLE_FOOD               = ActionType(55)
	DEPENDENCY_NO_VISIBLE_ENEMY           = ActionType(56)
	DEPENDENCY_NO_VISIBLE_FRIEND          = ActionType(57)
	DEPENDENCY_NO_VISIBLE_FOOD            = ActionType(58)
	DEPENDENCY_NO_INTERESTING_SOUND       = ActionType(59)
	DEPENDENCY_NO_NEW_ENEMY               = ActionType(60)
	DEPENDENCY_UNINTERRUPTABLE            = ActionType(61)
	DEPENDENCY_IS_ENCHANTED               = ActionType(62)
	DEPENDENCY_ENEMY_CLOSER_THAN          = ActionType(63)
	DEPENDENCY_NOT_HEALTHY                = ActionType(64)
	DEPENDENCY_WAIT_FOR_STAMINA           = ActionType(65)
	DEPENDENCY_ENEMY_FARTHER_THAN         = ActionType(66)
	DEPENDENCY_UNDER_CURSOR               = ActionType(67)
	DEPENDENCY_NOT_CORNERED               = ActionType(68)
	DEPENDENCY_LOCATION_IS_SAFE           = ActionType(69)
	DEPENDENCY_NOT_FRUSTRATED             = ActionType(70)
	DEPENDENCY_NOT_MOVED                  = ActionType(71)
)

var actionNames = map[ActionType]string{
	ACTION_IDLE:                           "ACTION_IDLE",
	ACTION_WAIT:                           "ACTION_WAIT",
	ACTION_WAIT_RELATIVE:                  "ACTION_WAIT_RELATIVE",
	ACTION_ESCORT:                         "ACTION_ESCORT",
	ACTION_GUARD:                          "ACTION_GUARD",
	ACTION_HUNT:                           "ACTION_HUNT",
	ACTION_RETREAT:                        "ACTION_RETREAT",
	ACTION_MOVE_TO:                        "ACTION_MOVE_TO",
	ACTION_FAR_MOVE_TO:                    "ACTION_FAR_MOVE_TO",
	ACTION_DODGE:                          "ACTION_DODGE",
	ACTION_ROAM:                           "ACTION_ROAM",
	ACTION_PICKUP_OBJECT:                  "ACTION_PICKUP_OBJECT",
	ACTION_DROP_OBJECT:                    "ACTION_DROP_OBJECT",
	ACTION_FIND_OBJECT:                    "ACTION_FIND_OBJECT",
	ACTION_RETREAT_TO_MASTER:              "ACTION_RETREAT_TO_MASTER",
	ACTION_FIGHT:                          "ACTION_FIGHT",
	ACTION_MELEE_ATTACK:                   "ACTION_MELEE_ATTACK",
	ACTION_MISSILE_ATTACK:                 "ACTION_MISSILE_ATTACK",
	ACTION_CAST_SPELL_ON_OBJECT:           "ACTION_CAST_SPELL_ON_OBJECT",
	ACTION_CAST_SPELL_ON_LOCATION:         "ACTION_CAST_SPELL_ON_LOCATION",
	ACTION_CAST_DURATION_SPELL:            "ACTION_CAST_DURATION_SPELL",
	ACTION_BLOCK_ATTACK:                   "ACTION_BLOCK_ATTACK",
	ACTION_BLOCK_FINISH:                   "ACTION_BLOCK_FINISH",
	ACTION_WEAPON_BLOCK:                   "ACTION_WEAPON_BLOCK",
	ACTION_FLEE:                           "ACTION_FLEE",
	ACTION_FACE_LOCATION:                  "ACTION_FACE_LOCATION",
	ACTION_FACE_OBJECT:                    "ACTION_FACE_OBJECT",
	ACTION_FACE_ANGLE:                     "ACTION_FACE_ANGLE",
	ACTION_SET_ANGLE:                      "ACTION_SET_ANGLE",
	ACTION_RANDOM_WALK:                    "ACTION_RANDOM_WALK",
	ACTION_DYING:                          "ACTION_DYING",
	ACTION_DEAD:                           "ACTION_DEAD",
	ACTION_REPORT:                         "ACTION_REPORT",
	ACTION_MORPH_INTO_CHEST:               "ACTION_MORPH_INTO_CHEST",
	ACTION_MORPH_BACK_TO_SELF:             "ACTION_MORPH_BACK_TO_SELF",
	ACTION_GET_UP:                         "ACTION_GET_UP",
	ACTION_CONFUSED:                       "ACTION_CONFUSED",
	ACTION_MOVE_TO_HOME:                   "ACTION_MOVE_TO_HOME",
	ACTION_INVALID:                        "ACTION_INVALID",
	DEPENDENCY_OR:                         "DEPENDENCY_OR",
	DEPENDENCY_TIME:                       "DEPENDENCY_TIME",
	DEPENDENCY_ALIVE:                      "DEPENDENCY_ALIVE",
	DEPENDENCY_UNDER_ATTACK:               "DEPENDENCY_UNDER_ATTACK",
	DEPENDENCY_NOT_UNDER_ATTACK:           "DEPENDENCY_NOT_UNDER_ATTACK",
	DEPENDENCY_CAN_SEE:                    "DEPENDENCY_CAN_SEE",
	DEPENDENCY_CANNOT_SEE:                 "DEPENDENCY_CANNOT_SEE",
	DEPENDENCY_BLOCKED_LINE_OF_FIRE:       "DEPENDENCY_BLOCKED_LINE_OF_FIRE",
	DEPENDENCY_OBJECT_AT_VISIBLE_LOCATION: "DEPENDENCY_OBJECT_AT_VISIBLE_LOCATION",
	DEPENDENCY_OBJECT_FARTHER_THAN:        "DEPENDENCY_OBJECT_FARTHER_THAN",
	DEPENDENCY_OBJECT_CLOSER_THAN:         "DEPENDENCY_OBJECT_CLOSER_THAN",
	DEPENDENCY_LOCATION_FARTHER_THAN:      "DEPENDENCY_LOCATION_FARTHER_THAN",
	DEPENDENCY_LOCATION_CLOSER_THAN:       "DEPENDENCY_LOCATION_CLOSER_THAN",
	DEPENDENCY_VISIBLE_ENEMY:              "DEPENDENCY_VISIBLE_ENEMY",
	DEPENDENCY_VISIBLE_FRIEND:             "DEPENDENCY_VISIBLE_FRIEND",
	DEPENDENCY_VISIBLE_FOOD:               "DEPENDENCY_VISIBLE_FOOD",
	DEPENDENCY_NO_VISIBLE_ENEMY:           "DEPENDENCY_NO_VISIBLE_ENEMY",
	DEPENDENCY_NO_VISIBLE_FRIEND:          "DEPENDENCY_NO_VISIBLE_FRIEND",
	DEPENDENCY_NO_VISIBLE_FOOD:            "DEPENDENCY_NO_VISIBLE_FOOD",
	DEPENDENCY_NO_INTERESTING_SOUND:       "DEPENDENCY_NO_INTERESTING_SOUND",
	DEPENDENCY_NO_NEW_ENEMY:               "DEPENDENCY_NO_NEW_ENEMY",
	DEPENDENCY_UNINTERRUPTABLE:            "DEPENDENCY_UNINTERRUPTABLE",
	DEPENDENCY_IS_ENCHANTED:               "DEPENDENCY_IS_ENCHANTED",
	DEPENDENCY_ENEMY_CLOSER_THAN:          "DEPENDENCY_ENEMY_CLOSER_THAN",
	DEPENDENCY_NOT_HEALTHY:                "DEPENDENCY_NOT_HEALTHY",
	DEPENDENCY_WAIT_FOR_STAMINA:           "DEPENDENCY_WAIT_FOR_STAMINA",
	DEPENDENCY_ENEMY_FARTHER_THAN:         "DEPENDENCY_ENEMY_FARTHER_THAN",
	DEPENDENCY_UNDER_CURSOR:               "DEPENDENCY_UNDER_CURSOR",
	DEPENDENCY_NOT_CORNERED:               "DEPENDENCY_NOT_CORNERED",
	DEPENDENCY_LOCATION_IS_SAFE:           "DEPENDENCY_LOCATION_IS_SAFE",
	DEPENDENCY_NOT_FRUSTRATED:             "DEPENDENCY_NOT_FRUSTRATED",
	DEPENDENCY_NOT_MOVED:                  "DEPENDENCY_NOT_MOVED",
}
