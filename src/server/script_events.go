package server

import "github.com/noxworld-dev/opennox-lib/script"

type OnChatFunc func(t *Team, p *Player, obj *Object, msg string) string

type scriptEvents struct {
	byObject      map[uintptr]*objectHandlers
	onFrame       []func()
	onMapEvent    map[script.EventType][]func()
	onPlayerJoin  []func(p script.Player)
	onPlayerLeave []func(p script.Player)
	onChat        []OnChatFunc
}

func (s *Server) ClearScriptTriggers() {
	ScriptLog.Printf("reset all hooks")
	s.ScriptEvents.byObject = nil
	s.ScriptEvents.onFrame = nil
	s.ScriptEvents.onMapEvent = nil
	s.ScriptEvents.onPlayerJoin = nil
	s.ScriptEvents.onPlayerLeave = nil
	s.ScriptEvents.onChat = nil
}

func (s *Server) OnPlayerJoin(fnc func(p script.Player)) {
	s.ScriptEvents.onPlayerJoin = append(s.ScriptEvents.onPlayerJoin, fnc)
}

func (s *Server) OnPlayerLeave(fnc func(p script.Player)) {
	s.ScriptEvents.onPlayerLeave = append(s.ScriptEvents.onPlayerLeave, fnc)
}

func (s *Server) OnChat(fnc OnChatFunc) {
	s.ScriptEvents.onChat = append(s.ScriptEvents.onChat, fnc)
}

func (s *Server) OnScriptFrame(fnc func()) {
	s.ScriptEvents.onFrame = append(s.ScriptEvents.onFrame, fnc)
}

func (s *Server) OnMapEvent(typ script.EventType, fnc func()) {
	if s.ScriptEvents.onMapEvent == nil {
		s.ScriptEvents.onMapEvent = make(map[script.EventType][]func())
	}
	s.ScriptEvents.onMapEvent[typ] = append(s.ScriptEvents.onMapEvent[typ], fnc)
}

func (s *Server) CallOnPlayerJoin(p script.Player) {
	ScriptLog.Printf("player join: %s", p)
	for _, fnc := range s.ScriptEvents.onPlayerJoin {
		fnc(p)
	}
}

func (s *Server) CallOnPlayerLeave(p script.Player) {
	ScriptLog.Printf("player leave: %s", p)
	for _, fnc := range s.ScriptEvents.onPlayerLeave {
		fnc(p)
	}
}

func (s *Server) CallOnChat(t *Team, p *Player, obj *Object, msg string) string {
	for _, fnc := range s.ScriptEvents.onChat {
		msg = fnc(t, p, obj, msg)
		if msg == "" {
			break
		}
	}
	return msg
}

func (s *Server) callOnScriptFrame() {
	for _, fnc := range s.ScriptEvents.onFrame {
		func() {
			defer func() {
				if r := recover(); r != nil {
					ScriptLog.Printf("panic in OnFrame: %v", r)
				}
			}()
			fnc()
		}()
	}
}

func (s *Server) CallOnMapEvent(typ script.EventType) {
	for _, fnc := range s.ScriptEvents.onMapEvent[typ] {
		func() {
			defer func() {
				if r := recover(); r != nil {
					ScriptLog.Printf("panic in OnEvent(%s): %v", string(typ), r)
				}
			}()
			fnc()
		}()
	}
}

func (obj *Object) getHandlers() *objectHandlers {
	return &obj.GetExt().objectHandlers
}

func (obj *Object) getOrNewHandlers() *objectHandlers {
	return &obj.SetExt().objectHandlers
}

func (obj *Object) OnUnitDeath(fnc func()) {
	h := obj.getOrNewHandlers()
	h.onDeath = append(h.onDeath, fnc)
}

func (obj *Object) OnUnitIdle(fnc func()) {
	h := obj.getOrNewHandlers()
	h.onIdle = append(h.onIdle, fnc)
}

func (obj *Object) OnUnitDone(fnc func()) {
	h := obj.getOrNewHandlers()
	h.onDone = append(h.onDone, fnc)
}

func (obj *Object) OnUnitAttack(fnc func(targ script.Unit)) {
	h := obj.getOrNewHandlers()
	h.onAttack = append(h.onAttack, fnc)
}

func (obj *Object) OnUnitSeeEnemy(fnc func(targ script.Unit)) {
	h := obj.getOrNewHandlers()
	h.onSeeEnemy = append(h.onSeeEnemy, fnc)
}

func (obj *Object) OnUnitLostEnemy(fnc func(targ script.Unit)) {
	h := obj.getOrNewHandlers()
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
	onDeath          []func()
	onIdle           []func()
	onDone           []func()
	onAttack         []func(targ script.Unit)
	onSeeEnemy       []func(targ script.Unit)
	onLostEnemy      []func(targ script.Unit)
	onTrigActivate   []func(obj script.Object)
	onTrigDeactivate []func()
}

func (obj *Object) CallOnMonsterDead() {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onDeath {
		fnc()
	}
}

func (obj *Object) CallOnMonsterIdle() {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onIdle {
		fnc()
	}
}

func (obj *Object) CallOnMonsterDone() {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onDone {
		fnc()
	}
}

func (obj *Object) CallOnMonsterAttack(targ script.Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onAttack {
		fnc(targ)
	}
}

func (obj *Object) CallOnMonsterSeeEnemy(targ script.Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onSeeEnemy {
		fnc(targ)
	}
}

func (obj *Object) CallOnMonsterLostEnemy(targ script.Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onLostEnemy {
		fnc(targ)
	}
}

func (obj *Object) CallOnPolygonPlayerEnter() {
	ScriptLog.Printf("player enter: %s", obj)
}

func (obj *Object) CallOnTriggerActivated(obj2 script.Object) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onTrigActivate {
		fnc(obj2)
	}
}

func (obj *Object) CallOnTriggerDeactivated() {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onTrigDeactivate {
		fnc()
	}
}
