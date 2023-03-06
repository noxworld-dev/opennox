package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_unitDefGetCount_4E3AC0() int {
	return noxServer.ObjectTypesCount()
}

func nox_xxx_newObjectWithTypeInd_4E3450(ind int) *server.Object {
	s := noxServer
	return s.NewObject(s.ObjectTypeByInd(ind)).SObj()
}

func nox_xxx_objectTypeByIndHealthData(ind int) unsafe.Pointer {
	t := noxServer.ObjectTypeByInd(ind)
	if t == nil {
		return nil
	}
	return t.Health().C()
}

func sub_4E4C50(item *server.Object) int {
	if item == nil {
		return 0
	}
	typ := noxServer.ObjectTypeByInd(int(item.TypeInd))
	if typ == nil {
		return 0
	}
	return int(typ.InitDataSize)
}

func sub_4F40A0(obj *server.Object) int8 {
	if obj == nil {
		return 0
	}
	if obj.ID() != "" {
		return -1
	}
	if obj.InvFirstItem != nil {
		return -1
	}
	if obj.Field129 != nil {
		return -1
	}
	if byte(obj.Field13) != 0 {
		return -1
	}
	typ := noxServer.ObjectTypeByInd(int(obj.TypeInd))
	if (obj.Flags()^typ.Flags())&0x11408162 != 0 {
		return -1
	}
	if (byte(obj.Field5)^byte(typ.Field9))&0x5E != 0 {
		return -1
	}
	if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
		v3 := alloc.GoString((*byte)(obj.Field189))
		if v3 != "" {
			return -1
		}
	} else if noxflags.HasGame(noxflags.GameHost) && obj.Field192 != -1 {
		return -1
	}
	return 0
}

func sub_4E4C90(obj *server.Object, a2 uint) int {
	typ := noxServer.ObjectTypeByInd(int(obj.TypeInd))
	switch a2 {
	case 0x1:
		return bool2int(obj.Field33 != 0)
	case 0x2:
		health := obj.HealthData
		if health == nil {
			return 0
		}
		if typ == nil || typ.Health() == nil {
			return 0
		}
		return bool2int(typ.Health().Cur != health.Cur)
	case 0x4:
		return bool2int(((obj.Flags()^typ.Flags())>>24)&1 != 0)
	case 0x8:
		return bool2int(typ.Field9 != obj.Field5)
	case 0x40:
		return bool2int(obj.ZVal != 0.0)
	case 0x80:
		return bool2int(obj.Buffs != 0)
	case 0x200:
		return bool2int(obj.Class()&0x13001000 != 0)
	case 0x400:
		return bool2int(obj.Class()&2 != 0 && obj.SubClass()&0x30 != 0)
	default:
		return 0
	}
}

func sub_4E3B80(ind int) bool {
	return noxServer.ObjectTypeByInd(ind).Icon != -1
}

func (s *Server) FreeObjectTypes() {
	s.Server.FreeObjectTypes()
	nox_xxx_free_42BF80()
}

func (s *Server) newObjectByTypeInd(ind int) *Object { // nox_xxx_newObjectWithTypeInd_4E3450
	typ := s.ObjectTypeByInd(ind)
	if typ == nil {
		return nil
	}
	return s.NewObject(typ)
}

func (s *Server) NewObjectByTypeID(id string) *server.Object { // nox_xxx_newObjectByTypeID_4E3810
	typ := s.ObjectTypeByID(id)
	if typ == nil {
		return nil
	}
	return s.NewObject(typ).SObj()
}

var _ = [1]struct{}{}[20-unsafe.Sizeof(server.HealthData{})]

func nox_xxx_objectUnkUpdateCoords_4E7290(obj *Object) {
	obj.SObj().UpdateCollider(obj.PosVec)
}

func (s *Server) NewObject(t *server.ObjectType) *Object {
	obj := asObjectS(s.Objs.NewObject(t))
	if noxflags.HasGame(noxflags.GameFlag22|noxflags.GameFlag23) && (obj.Class().HasAny(0x20A02) || obj.Xfer == legacy.Get_nox_xxx_XFerInvLight_4F5AA0() || obj.Weight != 0xff) {
		obj.Field189, _ = alloc.Malloc(2572)
	}
	if t.Create != nil {
		legacy.Nox_call_objectType_new_go(t.Create, obj.SObj())
	}
	if !noxflags.HasGame(noxflags.GameFlag22) {
		obj.ScriptIDVal = int(s.NextObjectScriptID())
	}
	if obj.Class().Has(object.ClassSimple) {
		s.Objs.CreatedSimple++
	} else if obj.Class().Has(object.ClassImmobile) {
		s.Objs.CreatedImmobile++
	}
	v8 := s.Objs.Alive + 1
	s.Objs.Created++
	s.Objs.Alive++
	if s.Objs.Alive > s.Objs.MaxAlive {
		s.Objs.MaxAlive = v8
	}
	return obj
}

func (s *Server) createObject(t *server.ObjectType, p types.Pointf) script.Object {
	obj := s.NewObject(t)
	if obj == nil {
		return nil
	}
	s.CreateObjectAt(obj, nil, p)
	if obj.Class().HasAny(object.MaskUnits) {
		return obj
	}
	return obj
}
