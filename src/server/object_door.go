package server

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

type serverDoors struct {
	flagXxx bool

	keyHolder    *Object
	keyHolderSet bool
}

func (s *serverDoors) Sub_4D72C0() bool {
	return s.flagXxx
}

func (s *serverDoors) Sub_4D72B0(a1 bool) {
	s.flagXxx = a1
}

func (s *Server) PlayersHaveSilverKey() bool {
	var found *Object
	for pl := s.Players.First(); pl != nil; pl = s.Players.Next(pl) {
		if !pl.IsActive() {
			continue
		}
		u := pl.PlayerUnit
		if u == nil {
			continue
		}
		cnt := 0
		for it := u.FirstItem(); it != nil; it = it.NextItem() {
			if int(it.TypeInd) == s.Types.SilverKeyID() {
				cnt++
			}
		}
		if cnt > 0 {
			found = u.SObj()
		}
	}
	if found == nil {
		return false
	}
	for it := found.FirstItem(); it != nil; it = it.NextItem() {
		if int(it.TypeInd) == s.Types.SilverKeyID() {
			return true
		}
	}
	return false
}

func (s *Server) DoorCheckKey(u, door *Object) bool {
	ud2 := door.UpdateData
	if *(*uint8)(unsafe.Add(ud2, 1)) == 5 {
		return false
	}
	if door.ObjOwner != nil {
		return false
	}
	var found *Object
	for it := u.FirstItem(); it != nil; it = it.NextItem() {
		if !it.Class().Has(object.ClassKey) {
			continue
		}
		tname := s.Types.ByInd(int(it.TypeInd)).ID()
		exp := ""
		switch *(*uint8)(unsafe.Add(ud2, 1)) {
		case 1:
			exp = "SilverKey"
		case 2:
			exp = "GoldKey"
		case 3:
			exp = "RubyKey"
		case 4:
			exp = "SapphireKey"
		}
		if exp != "" && tname == exp {
			found = it
			break
		}
	}
	if found == nil && u.Class().Has(object.ClassPlayer) && noxflags.HasGame(noxflags.GameModeQuest) &&
		s.Doors.Sub_4D72C0() && *(*uint8)(unsafe.Add(ud2, 1)) == 1 {
		return s.PlayersHaveSilverKey()
	}
	return found != nil
}
