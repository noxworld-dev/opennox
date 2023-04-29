package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

const summonLimit = 4

var (
	cheatSummonNoLimit = false
)

func nox_xxx_checkSummonedCreaturesLimit_500D70(u *server.Object, ind int) bool {
	if cheatSummonNoLimit {
		return true
	}
	sz := nox_xxx_guideGetUnitSize_427460(ind)
	return nox_xxx_countControlledCreatures_500D10(u)+sz <= summonLimit
}

func nox_xxx_guideGetUnitSize_427460(ind int) int {
	return int(memmap.Uint8(0x5D4594, 740100+28*uintptr(ind)))
}

func nox_xxx_countControlledCreatures_500D10(u *server.Object) int {
	cnt := 0
	for it := u.FirstOwned516(); it != nil; it = it.NextOwned512() {
		if legacy.Nox_xxx_creatureIsMonitored_500CC0(u, it) != 0 {
			cnt += monsterSummonSize(it)
		}
	}
	return cnt
}

func monsterSummonSize(u *server.Object) int {
	cl := u.SubClass().AsMonster()
	switch {
	case cl.Has(object.MonsterSmall):
		return 1
	case cl.Has(object.MonsterMedium):
		return 2
	case cl.Has(object.MonsterLarge):
		return 4
	default:
		return 4
	}
}

func sub_57AEE0(sp spell.ID, u *server.Object) bool {
	return sp < spell.SPELL_SUMMON_BAT || sp > spell.SPELL_SUMMON_URCHIN_SHAMAN || nox_xxx_countControlledCreatures_500D10(u) <= 4
}

func nox_xxx_unitDoSummonAt_5016C0(typID int, pos types.Pointf, owner *server.Object, dir server.Dir16) *server.Object {
	s := noxServer
	obj := s.Objs.NewObject(s.Types.ByInd(typID)).SObj()
	if obj == nil {
		return obj
	}
	s.CreateObjectAt(obj, owner, pos)
	ud := obj.UpdateDataMonster()
	obj.Direction1 = dir
	obj.Direction2 = dir
	ud.StatusFlags |= object.MonStatusSummoned
	if owner == nil {
		return obj
	}
	if !owner.Class().Has(object.ClassPlayer) {
		legacy.Nox_xxx_orderUnit_533900(owner, obj, 4)
		ud.AIAction340 = uint32(ai.ACTION_INVALID)
		return obj
	}
	pl := owner.ControllingPlayer()
	legacy.Nox_xxx_orderUnit_533900(owner, obj, pl.SummonOrderAll)
	ud.AIAction340 = uint32(ai.ACTION_INVALID)
	obj.ObjSubClass |= uint32(object.MonsterMonitor)
	legacy.Nox_xxx_netReportAcquireCreature_4D91A0(pl.Index(), obj)
	legacy.Nox_xxx_netMarkMinimapObject_417190(pl.Index(), obj, 1)
	legacy.Nox_xxx_netSendSimpleObject2_4DF360(pl.Index(), obj)
	if owner.HasTeam() {
		legacy.Nox_xxx_createAtImpl_4191D0(byte(owner.Field13), owner.TeamPtr(), 1, obj.NetCode, 0)
	}
	obj.ObjSubClass |= uint32(object.MonsterMigrate)
	return obj
}
