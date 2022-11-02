package opennox

import (
	"encoding/binary"
)

type Activator struct {
	frame     uint32
	callback  int
	arg       uint32
	id        uint32
	trigger   *Object
	caller    *Object
	triggerID uint32
	callerID  uint32
	next      *Activator
	prev      *Activator
}

func (s *noxScript) actNextHandle() uint32 {
	s.activators.lastID++
	id := s.activators.lastID
	if s.activators.lastID > 32000 {
		id = 1
		s.activators.lastID = 1
	}
	return id
}

func (s *noxScript) actAppend(act *Activator) {
	var last *Activator
	for it := s.activators.head; it != nil; it = it.next {
		last = it
	}
	if last != nil {
		last.next = act
		act.prev = last
	} else {
		s.activators.head = act
		act.prev = nil
	}
}

func (s *noxScript) actCancel(id uint32) bool {
	for it := s.activators.head; it != nil; it = it.next {
		if it.id == id {
			s.actDoneNext(it)
			return true
		}
	}
	return false
}

func (s *noxScript) actCancelAll() {
	s.activators.head = nil
}

func (s *noxScript) newScriptTimer(df int, callback int, arg uint32) uint32 {
	act := &Activator{
		id:       s.actNextHandle(),
		frame:    s.s.Frame() + uint32(df),
		callback: callback, arg: arg,
	}
	s.actAppend(act)
	return act.id
}

func (s *noxScript) actClearObj(obj *Object) {
	for it := s.activators.head; it != nil; {
		if it.trigger == obj {
			it = s.actDoneNext(it)
		} else {
			if it.caller == obj {
				it.caller = nil
			}
			it = it.next
		}
	}
}

func (s *noxScript) actSave() int {
	var buf [4]byte
	binary.LittleEndian.PutUint16(buf[:], 1)
	cryptFileReadWrite(buf[:2])
	binary.LittleEndian.PutUint32(buf[:], s.s.Frame())
	cryptFileReadWrite(buf[:4])

	cnt := 0
	for it := s.activators.head; it != nil; it = it.next {
		cnt++
	}
	binary.LittleEndian.PutUint32(buf[:], uint32(cnt))
	cryptFileReadWrite(buf[:4])
	for it := s.activators.head; it != nil; it = it.next {
		binary.LittleEndian.PutUint32(buf[:], it.frame)
		cryptFileReadWrite(buf[:4])
		binary.LittleEndian.PutUint32(buf[:], uint32(it.callback))
		cryptFileReadWrite(buf[:4])
		binary.LittleEndian.PutUint32(buf[:], it.arg)
		cryptFileReadWrite(buf[:4])
		oid := 0
		if it.trigger != nil {
			oid = it.trigger.ScriptID
		}
		binary.LittleEndian.PutUint32(buf[:], uint32(oid))
		cryptFileReadWrite(buf[:4])
		oid = 0
		if it.caller != nil {
			oid = it.caller.ScriptID
		}
		binary.LittleEndian.PutUint32(buf[:], uint32(oid))
		cryptFileReadWrite(buf[:4])
	}
	return 1
}

func (s *noxScript) actLoad() int {
	var buf [4]byte
	cryptFileReadWrite(buf[:2])
	vers := binary.LittleEndian.Uint16(buf[:])
	if vers > 1 || vers <= 0 {
		return 0
	}
	cryptFileReadWrite(buf[:4])
	saveFrame := binary.LittleEndian.Uint32(buf[:])
	cryptFileReadWrite(buf[:4])
	cnt := int(binary.LittleEndian.Uint32(buf[:]))
	for i := 0; i < cnt; i++ {
		cryptFileReadWrite(buf[:4])
		frame := binary.LittleEndian.Uint32(buf[:])
		cryptFileReadWrite(buf[:4])
		callback := binary.LittleEndian.Uint32(buf[:])
		cryptFileReadWrite(buf[:4])
		arg := binary.LittleEndian.Uint32(buf[:])
		cryptFileReadWrite(buf[:4])
		trigger := binary.LittleEndian.Uint32(buf[:])
		cryptFileReadWrite(buf[:4])
		caller := binary.LittleEndian.Uint32(buf[:])

		act := &Activator{
			id:       s.actNextHandle(),
			frame:    s.s.Frame() + (frame - saveFrame),
			callback: int(callback), arg: arg,
			triggerID: trigger, callerID: caller,
		}
		s.actAppend(act)
	}
	return 1
}

func (s *noxScript) actRun() {
	scripts := s.scripts()
	for it := s.activators.head; it != nil; {
		if it.frame > s.s.Frame() {
			it = it.next
		} else {
			callback := it.callback
			caller := it.caller
			trigger := it.trigger
			if scripts[callback].size_28 != 0 {
				s.PushU32(it.arg)
			}
			it = s.actDoneNext(it)
			s.callByIndex(callback, caller, trigger)
		}
	}
}

func (s *noxScript) actResolveObjs() {
	for it := s.activators.head; it != nil; it = it.next {
		if it.triggerID != 0 {
			it.trigger = s.scriptToObject(int(it.triggerID))
			it.triggerID = 0
		}
		if it.callerID != 0 {
			it.caller = s.scriptToObject(int(it.callerID))
			it.callerID = 0
		}
	}
}

func (s *noxScript) actDoneNext(act *Activator) *Activator {
	next := act.next
	if next != nil {
		next.prev = act.prev
	}
	if prev := act.prev; prev != nil {
		prev.next = next
	}

	if act == s.activators.head {
		s.activators.head = next
	}
	*act = Activator{}
	return next
}
