package main

import (
	"nox/v1/server/script"
)

var (
	scriptEvents struct {
		byObject map[uintptr]*objectHandlers
	}
)

func clearScriptTriggers() {
	scriptEvents.byObject = nil
}

func (obj *Object) getHandlers() *objectHandlers {
	return scriptEvents.byObject[obj.UniqueKey()]
}

func (obj *Object) getOrNewHandlers() *objectHandlers {
	if h := scriptEvents.byObject[obj.UniqueKey()]; h != nil {
		return h
	}
	if scriptEvents.byObject == nil {
		scriptEvents.byObject = make(map[uintptr]*objectHandlers)
	}
	h := &objectHandlers{obj: obj}
	scriptEvents.byObject[obj.UniqueKey()] = h
	return h
}

func (u *Unit) OnUnitDeath(fnc func(u script.Unit)) {
	h := u.getOrNewHandlers()
	h.onDeath = append(h.onDeath, fnc)
}

func (u *Unit) OnUnitIdle(fnc func(u script.Unit)) {
	h := u.getOrNewHandlers()
	h.onIdle = append(h.onIdle, fnc)
}

func (u *Unit) OnUnitDone(fnc func(u script.Unit)) {
	h := u.getOrNewHandlers()
	h.onDone = append(h.onDone, fnc)
}

func (u *Unit) OnUnitAttack(fnc func(u, targ script.Unit)) {
	h := u.getOrNewHandlers()
	h.onAttack = append(h.onAttack, fnc)
}

func (u *Unit) OnUnitSeeEnemy(fnc func(u, targ script.Unit)) {
	h := u.getOrNewHandlers()
	h.onSeeEnemy = append(h.onSeeEnemy, fnc)
}

func (u *Unit) OnUnitLostEnemy(fnc func(u, targ script.Unit)) {
	h := u.getOrNewHandlers()
	h.onLostEnemy = append(h.onLostEnemy, fnc)
}

type objectHandlers struct {
	obj         *Object
	onDeath     []func(u script.Unit)
	onIdle      []func(u script.Unit)
	onDone      []func(u script.Unit)
	onAttack    []func(u, targ script.Unit)
	onSeeEnemy  []func(u, targ script.Unit)
	onLostEnemy []func(u, targ script.Unit)
}

func callOnMonsterDead(obj *Unit) {
	scriptLog.Printf("dead: %s", obj)
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onDeath {
		fnc(obj)
	}
}

func callOnMonsterIdle(obj *Unit) {
	scriptLog.Printf("idle: %s", obj)
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onIdle {
		fnc(obj)
	}
}

func callOnMonsterDone(obj *Unit) {
	scriptLog.Printf("done: %s", obj)
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onDone {
		fnc(obj)
	}
}

func callOnMonsterAttack(obj, targ *Unit) {
	scriptLog.Printf("attack: %s -> %s", obj, targ)
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onAttack {
		fnc(obj, targ)
	}
}

func callOnMonsterSeeEnemy(obj, targ *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onSeeEnemy {
		fnc(obj, targ)
	}
}

func callOnMonsterLostEnemy(obj, targ *Unit) {
	h := obj.getHandlers()
	if h == nil {
		return
	}
	for _, fnc := range h.onLostEnemy {
		fnc(obj, targ)
	}
}

func callOnPolygonPlayerEnter(obj *Unit) {
	scriptLog.Printf("player enter: %s", obj)
}

func callOnTriggerActivated(trig *Object, obj *Unit) {
	scriptLog.Printf("trigger enter: %s -> %s", obj, trig)
}

func callOnTriggerDeactivated(trig *Object) {
	scriptLog.Printf("trigger leave: %s", trig)
}
