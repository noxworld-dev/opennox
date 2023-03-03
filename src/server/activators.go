package server

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
)

type serverActivators struct {
	lastID uint32
	head   *activator
}

type activator struct {
	frame     uint32
	id        uint32
	triggerID uint32
	callerID  uint32
	arg       ActivatorArgs
	next      *activator
	prev      *activator
}

type ActivatorArgs struct {
	Callback int    // identifier of a callback function
	Arg      uint32 // optional argument to the callback
	Trigger  *Object
	Caller   *Object
}

func (s *serverActivators) nextID() uint32 {
	s.lastID++
	id := s.lastID
	if s.lastID > 32000 {
		id = 1
		s.lastID = 1
	}
	return id
}

func (s *serverActivators) append(act *activator) {
	var last *activator
	for it := s.head; it != nil; it = it.next {
		last = it
	}
	if last != nil {
		last.next = act
		act.prev = last
	} else {
		s.head = act
		act.prev = nil
	}
}

func (s *serverActivators) doneAndNext(act *activator) *activator {
	next := act.next
	if next != nil {
		next.prev = act.prev
	}
	if prev := act.prev; prev != nil {
		prev.next = next
	}

	if act == s.head {
		s.head = next
	}
	*act = activator{}
	return next
}

func (s *serverActivators) Cancel(id uint32) bool {
	for it := s.head; it != nil; it = it.next {
		if it.id == id {
			s.doneAndNext(it)
			return true
		}
	}
	return false
}

func (s *serverActivators) CancelAll() {
	s.head = nil
}

func (s *serverActivators) ClearOnObject(obj *Object) {
	for it := s.head; it != nil; {
		if it.arg.Trigger == obj {
			it = s.doneAndNext(it)
		} else {
			if it.arg.Caller == obj {
				it.arg.Caller = nil
			}
			it = it.next
		}
	}
}

func (s *serverActivators) ResolveObjs(resolve func(id int) *Object) {
	for it := s.head; it != nil; it = it.next {
		if it.triggerID != 0 {
			it.arg.Trigger = resolve(int(it.triggerID))
			it.triggerID = 0
		}
		if it.callerID != 0 {
			it.arg.Caller = resolve(int(it.callerID))
			it.callerID = 0
		}
	}
}

func (s *serverActivators) newTimer(deadline uint32, callback int, arg uint32) uint32 {
	act := &activator{
		id:    s.nextID(),
		frame: deadline,
		arg:   ActivatorArgs{Callback: callback, Arg: arg},
	}
	s.append(act)
	return act.id
}

func (s *serverActivators) save(curFrame uint32, cf *cryptfile.CryptFile) int {
	var buf [4]byte
	binary.LittleEndian.PutUint16(buf[:], 1)
	cf.ReadWrite(buf[:2])
	binary.LittleEndian.PutUint32(buf[:], curFrame)
	cf.ReadWrite(buf[:4])

	cnt := 0
	for it := s.head; it != nil; it = it.next {
		cnt++
	}
	binary.LittleEndian.PutUint32(buf[:], uint32(cnt))
	cf.ReadWrite(buf[:4])
	for it := s.head; it != nil; it = it.next {
		binary.LittleEndian.PutUint32(buf[:], it.frame)
		cf.ReadWrite(buf[:4])
		binary.LittleEndian.PutUint32(buf[:], uint32(it.arg.Callback))
		cf.ReadWrite(buf[:4])
		binary.LittleEndian.PutUint32(buf[:], it.arg.Arg)
		cf.ReadWrite(buf[:4])
		oid := 0
		if it.arg.Trigger != nil {
			oid = it.arg.Trigger.ScriptIDVal
		}
		binary.LittleEndian.PutUint32(buf[:], uint32(oid))
		cf.ReadWrite(buf[:4])
		oid = 0
		if it.arg.Caller != nil {
			oid = it.arg.Caller.ScriptIDVal
		}
		binary.LittleEndian.PutUint32(buf[:], uint32(oid))
		cf.ReadWrite(buf[:4])
	}
	return 1
}

func (s *serverActivators) load(curFrame uint32, cf *cryptfile.CryptFile) int {
	var buf [4]byte
	cf.ReadWrite(buf[:2])
	vers := binary.LittleEndian.Uint16(buf[:])
	if vers > 1 || vers <= 0 {
		return 0
	}
	cf.ReadWrite(buf[:4])
	saveFrame := binary.LittleEndian.Uint32(buf[:])
	cf.ReadWrite(buf[:4])
	cnt := int(binary.LittleEndian.Uint32(buf[:]))
	for i := 0; i < cnt; i++ {
		cf.ReadWrite(buf[:4])
		frame := binary.LittleEndian.Uint32(buf[:])
		cf.ReadWrite(buf[:4])
		callback := binary.LittleEndian.Uint32(buf[:])
		cf.ReadWrite(buf[:4])
		arg := binary.LittleEndian.Uint32(buf[:])
		cf.ReadWrite(buf[:4])
		trigger := binary.LittleEndian.Uint32(buf[:])
		cf.ReadWrite(buf[:4])
		caller := binary.LittleEndian.Uint32(buf[:])

		act := &activator{
			id:    s.nextID(),
			frame: curFrame + (frame - saveFrame),
			arg: ActivatorArgs{
				Callback: int(callback), Arg: arg,
			},
			// These are loaded later when ResolveObjs is called.
			triggerID: trigger, callerID: caller,
		}
		s.append(act)
	}
	return 1
}

func (s *serverActivators) EachTriggered(curFrame uint32, fnc func(it ActivatorArgs)) {
	for it := s.head; it != nil; {
		if it.frame > curFrame {
			it = it.next
		} else {
			args := it.arg
			it = s.doneAndNext(it)
			fnc(args)
		}
	}
}

func (s *Server) NewTimer(df int, callback int, arg uint32) uint32 {
	return s.Activators.newTimer(s.Frame()+uint32(df), callback, arg)
}

func (s *Server) SaveActivators(cf *cryptfile.CryptFile) int {
	return s.Activators.save(s.Frame(), cf)
}

func (s *Server) LoadActivators(cf *cryptfile.CryptFile) int {
	return s.Activators.load(s.Frame(), cf)
}
