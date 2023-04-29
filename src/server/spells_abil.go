package server

import (
	"strconv"
	"unsafe"
)

type ExecAbilityClass struct {
	Abil   Ability           // 0, 0
	Frame  uint32            // 2, 8
	Active uint32            // 3, 12
	Next   *ExecAbilityClass // 4, 16
	Prev   *ExecAbilityClass // 5, 20
}

type unitAbilities struct {
	Cooldowns [AbilityMax]int
	ExecList  *ExecAbilityClass
}

type serverAbilities struct {
	s      *Server
	ByUnit map[*Object]*unitAbilities
}

func (a *serverAbilities) init(s *Server) {
	a.s = s
}

func (a *serverAbilities) Reset() {
	a.ByUnit = make(map[*Object]*unitAbilities)
}

func (a *serverAbilities) GetFor(obj Obj) *unitAbilities {
	if obj == nil {
		return nil
	}
	u := obj.SObj()
	d := a.ByUnit[u]
	if d != nil {
		return d
	}
	d = new(unitAbilities)
	a.ByUnit[u] = d
	return d
}

func (a *serverAbilities) IsActive(u *Object, abil Ability) bool {
	ad, ok := a.ByUnit[u]
	if !ok {
		return false
	}
	for it := ad.ExecList; it != nil; it = it.Next {
		if it.Abil == abil {
			return true
		}
	}
	return false
}

func (a *serverAbilities) IsActiveVal(u *Object, abil Ability) bool {
	ad, ok := a.ByUnit[u]
	if !ok {
		return false
	}
	for it := ad.ExecList; it != nil; it = it.Next {
		if it.Abil == abil {
			return it.Active != 0
		}
	}
	return false
}

func (a *serverAbilities) IsAnyActive(u *Object) bool {
	ad, ok := a.ByUnit[u]
	if !ok {
		return false
	}
	return ad.ExecList != nil
}

func (a *serverAbilities) Sub4FC070(u *Object, abil Ability, dt int) {
	ad, ok := a.ByUnit[u]
	if !ok {
		return
	}
	for it := ad.ExecList; it != nil; it = it.Next {
		if it.Abil == abil {
			it.Frame = a.s.Frame() + uint32(dt)
			break
		}
	}
}

func (a *serverAbilities) Sub4FC030(u *Object, abil Ability) int {
	ad, ok := a.ByUnit[u]
	if !ok {
		return -1
	}
	for it := ad.ExecList; it != nil; it = it.Next {
		if it.Abil == abil {
			return int(it.Frame - a.s.Frame())
		}
	}
	return -1
}

func (a *serverAbilities) Sub4FC440(u *Object, abil Ability) {
	ad, ok := a.ByUnit[u]
	if !ok {
		return
	}
	for it := ad.ExecList; it != nil; it = it.Next {
		if it.Abil == abil {
			it.Active = 0
			break
		}
	}
}

func (a *serverAbilities) GetCooldown(a1 unsafe.Pointer, abil Ability) int {
	pl := a.s.Players.ByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return 0
	}
	ad, ok := a.ByUnit[pl.PlayerUnit]
	if !ok {
		return 0
	}
	return ad.Cooldowns[abil]
}

func (a *serverAbilities) SetCooldown(a1 unsafe.Pointer, abil Ability, cd int) {
	pl := a.s.Players.ByID(int(*(*int32)(unsafe.Add(a1, 36))))
	if pl == nil {
		return
	}
	ad, ok := a.ByUnit[pl.PlayerUnit]
	if !ok {
		return
	}
	ad.Cooldowns[abil] = cd
}

func (a *serverAbilities) DisableAbilityAaa(u *Object, abil Ability) {
	if u == nil {
		return
	}
	if !abil.Valid() {
		return
	}
	ad, ok := a.ByUnit[u]
	if !ok {
		return
	}
	var next *ExecAbilityClass
	for it := ad.ExecList; it != nil; it = next {
		next = it.Next
		if it.Abil == abil {
			if next != nil {
				next.Prev = it.Prev
			}
			if prev := it.Prev; prev != nil {
				prev.Next = it.Next
			} else {
				ad.ExecList = it.Next
			}
			*it = ExecAbilityClass{}
		}
	}
}

type Ability int32

func (a Ability) String() string {
	if a >= 0 && int(a) < len(AbilityNames) {
		return AbilityNames[a]
	}
	return "Ability(" + strconv.Itoa(int(a)) + ")"
}

func (a Ability) Valid() bool {
	return a > AbilityInvalid && a < AbilityMax
}

const (
	AbilityInvalid = Ability(iota)
	AbilityBerserk
	AbilityWarcry
	AbilityHarpoon
	AbilityTreadLightly
	AbilityInfravis
	AbilityMax
)

var AbilityNames = []string{
	"ABILITY_INVALID", "ABILITY_BERSERKER_CHARGE", "ABILITY_WARCRY",
	"ABILITY_HARPOON", "ABILITY_TREAD_LIGHTLY", "ABILITY_EYE_OF_THE_WOLF",
}
