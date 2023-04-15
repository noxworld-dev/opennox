package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_4E4C90(obj *server.Object, a2 uint) bool {
	s := asObjectS(obj).getServer()
	typ := s.Types.ByInd(int(obj.TypeInd))
	switch a2 {
	case 0x1:
		return obj.Field33 != 0
	case 0x2:
		health := obj.HealthData
		if health == nil {
			return false
		}
		if typ == nil || typ.Health() == nil {
			return false
		}
		return typ.Health().Cur != health.Cur
	case 0x4:
		return ((obj.Flags()^typ.Flags())>>24)&0x1 != 0
	case 0x8:
		return typ.Field9 != obj.Field5
	case 0x40:
		return obj.ZVal != 0.0
	case 0x80:
		return obj.Buffs != 0
	case 0x200:
		return obj.Class().HasAny(object.ClassFlag | object.ClassWeapon | object.ClassArmor | object.ClassWand)
	case 0x400:
		return obj.Class().Has(object.ClassMonster) &&
			obj.SubClass().AsMonster().HasAny(object.MonsterNPC|object.MonsterFemaleNPC)
	default:
		return false
	}
}

func sub_4E3B80(ind int) bool {
	return noxServer.Types.ByInd(ind).Icon != -1
}

func (s *Server) FreeObjectTypes() {
	s.Server.FreeObjectTypes()
	nox_xxx_free_42BF80()
}

var _ = [1]struct{}{}[20-unsafe.Sizeof(server.HealthData{})]

func (s *Server) createObject(t *server.ObjectType, p types.Pointf) script.Object {
	obj := s.Objs.NewObject(t)
	if obj == nil {
		return nil
	}
	s.CreateObjectAt(obj, nil, p)
	if obj.Class().HasAny(object.MaskUnits) {
		return asObjectS(obj)
	}
	return asObjectS(obj)
}
