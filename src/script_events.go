package nox

import (
	"nox/v1/server/script"
)

type scriptEvents struct {
	byObject      map[uintptr]*objectHandlers
	onPlayerJoin  []func(p script.Player)
	onPlayerLeave []func(p script.Player)
}

func (s *Server) clearScriptTriggers() {
	s.scriptEvents.byObject = nil
	s.scriptEvents.onPlayerJoin = nil
	s.scriptEvents.onPlayerLeave = nil
}

func (s *Server) OnPlayerJoin(fnc func(p script.Player)) {
	s.scriptEvents.onPlayerJoin = append(s.scriptEvents.onPlayerJoin, fnc)
}

func (s *Server) OnPlayerLeave(fnc func(p script.Player)) {
	s.scriptEvents.onPlayerLeave = append(s.scriptEvents.onPlayerLeave, fnc)
}

func (s *Server) callOnPlayerJoin(p *Player) {
	scriptLog.Printf("player join: %s", p)
	for _, fnc := range s.scriptEvents.onPlayerJoin {
		fnc(p)
	}
}

func (s *Server) callOnPlayerLeave(p *Player) {
	scriptLog.Printf("player leave: %s", p)
	for _, fnc := range s.scriptEvents.onPlayerLeave {
		fnc(p)
	}
}

func (obj *Object) getHandlers() *objectHandlers {
	return obj.getServer().scriptEvents.byObject[obj.UniqueKey()]
}

func (obj *Object) getOrNewHandlers() *objectHandlers {
	s := obj.getServer()
	if h := s.scriptEvents.byObject[obj.UniqueKey()]; h != nil {
		return h
	}
	if s.scriptEvents.byObject == nil {
		s.scriptEvents.byObject = make(map[uintptr]*objectHandlers)
	}
	h := &objectHandlers{obj: obj}
	s.scriptEvents.byObject[obj.UniqueKey()] = h
	return h
}

func (u *Unit) OnUnitDeath(fnc func()) {
	h := u.getOrNewHandlers()
	h.onDeath = append(h.onDeath, fnc)
}

func (u *Unit) OnUnitIdle(fnc func()) {
	h := u.getOrNewHandlers()
	h.onIdle = append(h.onIdle, fnc)
}

func (u *Unit) OnUnitDone(fnc func()) {
	h := u.getOrNewHandlers()
	h.onDone = append(h.onDone, fnc)
}

func (u *Unit) OnUnitAttack(fnc func(targ script.Unit)) {
	h := u.getOrNewHandlers()
	h.onAttack = append(h.onAttack, fnc)
}

func (u *Unit) OnUnitSeeEnemy(fnc func(targ script.Unit)) {
	h := u.getOrNewHandlers()
	h.onSeeEnemy = append(h.onSeeEnemy, fnc)
}

func (u *Unit) OnUnitLostEnemy(fnc func(targ script.Unit)) {
	h := u.getOrNewHandlers()
	h.onLostEnemy = append(h.onLostEnemy, fnc)
}

func (obj *Object) OnTriggerActivate(fnc func(u script.Object)) {
	h := obj.getOrNewHandlers()
	h.onTrigActivate = append(h.onTrigActivate, fnc)
}

func (obj *Object) OnTriggerDeactivate(fnc func()) {
	h := obj.getOrNewHandlers()
	h.onTrigDeactivate = append(h.onTrigDeactivate, fnc)
}

type objectHandlers struct {
	obj              *Object
	onDeath          []func()
	onIdle           []func()
	onDone           []func()
	onAttack         []func(targ script.Unit)
	onSeeEnemy       []func(targ script.Unit)
	onLostEnemy      []func(targ script.Unit)
	onTrigActivate   []func(obj script.Object)
	onTrigDeactivate []func()
}

func callOnMonsterDead(obj *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onDeath {
		fnc()
	}
}

func callOnMonsterIdle(obj *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onIdle {
		fnc()
	}
}

func callOnMonsterDone(obj *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onDone {
		fnc()
	}
}

func callOnMonsterAttack(obj, targ *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onAttack {
		fnc(targ)
	}
}

func callOnMonsterSeeEnemy(obj, targ *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onSeeEnemy {
		fnc(targ)
	}
}

func callOnMonsterLostEnemy(obj, targ *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onLostEnemy {
		fnc(targ)
	}
}

func callOnPolygonPlayerEnter(obj *Unit) {
	scriptLog.Printf("player enter: %s", obj)
}

func callOnTriggerActivated(trig *Object, obj *Object) {
	h := trig.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onTrigActivate {
		fnc(obj)
	}
}

func callOnTriggerDeactivated(trig *Object) {
	h := trig.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onTrigDeactivate {
		fnc()
	}
}
