package server

import "C"
import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type audioEventObj struct {
	ID   sound.ID
	Obj  *Object
	Kind int
	Code uint32
}

type audioEventPos struct {
	ID   sound.ID
	Pos  types.Pointf
	Kind int
	Code uint32
}

type OnSoundFunc func(id sound.ID, kind int, obj *Object, pos types.Pointf)

type serverAudio struct {
	s          *Server
	alloc      alloc.ClassT[AudioEvent]
	inited     bool
	head       *AudioEvent
	bySound    [1024]audioEvent2
	bitmap     [32]uint32
	onSound    []OnSoundFunc
	delayedObj []audioEventObj
	delayedPos []audioEventPos
	// inAudio indicates that the server is currently accepting audio events.
	//
	// If this flag is set, all audio events will be added directly to the list.
	// And if not, we will queue them for the next frame.
	inAudio bool
}

type AudioEvent struct {
	next0  *AudioEvent
	Sound  sound.ID
	Pos    types.Pointf
	Obj    *Object
	Kind   int
	Code   uint32
	list28 *AudioEvent
	Perc   int
}

type audioEvent2 struct {
	MaxDist int
	Flags   uint32
	Field8  uint32
	Field12 uint32
	Field16 uint32
	Field20 int
	Field24 *AudioEvent
}

func (s *serverAudio) Init(srv *Server) {
	if s.inited {
		return
	}
	s.s = srv
	s.alloc = alloc.NewClassT("AudEvent", AudioEvent{}, 128)
	for i := range s.bySound[:len(s.bySound)-1] {
		p := &s.bySound[i]
		p.MaxDist = 600
		p.Field8 = 0
		p.Field12 = 0
		p.Field16 = 0
		p.Field20 = 0
		p.Field24 = nil
	}
	s.inited = true
}

func (s *serverAudio) Free() {
	if s.inited {
		s.alloc.Free()
		s.head = nil
		s.onSound = nil
		s.inAudio = false
		s.delayedObj = nil
		s.delayedPos = nil
		s.inited = false
	}
}

func (s *serverAudio) Reset() {
	s.alloc.FreeAllObjects()
	s.head = nil
	s.inAudio = true
	// Replay events queued outside the audio loop.
	for _, a := range s.delayedObj {
		s.EventObj(a.ID, a.Obj, a.Kind, a.Code)
	}
	s.delayedObj = s.delayedObj[:0]
	for _, a := range s.delayedPos {
		s.EventPos(a.ID, a.Pos, a.Kind, a.Code)
	}
	s.delayedPos = s.delayedPos[:0]
}

func (s *serverAudio) OnSound(fnc OnSoundFunc) {
	s.onSound = append(s.onSound, fnc)
}

func (s *serverAudio) ResetBitmap() {
	s.bitmap = [32]uint32{}
	s.inAudio = false
}

func (s *serverAudio) Flags(id sound.ID) int {
	return int(s.bySound[id].Flags)
}

func (s *serverAudio) MaxDist(id sound.ID) int {
	return s.bySound[id].MaxDist
}

func (s *serverAudio) Field12(id sound.ID) int32 {
	return int32(s.bySound[id].Field12)
}

func (s *serverAudio) Field20(id sound.ID) int {
	return s.bySound[id].Field20
}

func (s *serverAudio) newAudioEventObj(id sound.ID, iobj Obj, kind int, code uint32) {
	obj := toObject(iobj)
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || obj == nil || s.Field12(id) <= 0 {
		return
	}
	p := s.alloc.NewObject()
	if p == nil {
		return
	}
	p.Sound = id
	if obj.Flags().Has(object.FlagDestroyed) {
		p.Obj = nil
	} else {
		p.Obj = obj
	}
	p.Pos = obj.Pos()
	p.Kind = kind
	p.Code = code
	p.next0 = s.head
	s.head = p
}

func (s *serverAudio) newAudioEventPos(id sound.ID, pos types.Pointf, kind int, code uint32) {
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || s.Field12(id) <= 0 {
		return
	}
	p := s.alloc.NewObject()
	if p == nil {
		return
	}
	p.Sound = id
	p.Pos = pos
	p.Obj = nil
	p.Kind = kind
	p.Code = code
	p.next0 = s.head
	s.head = p
}

func (s *serverAudio) AddAudio(p *AudioEvent, perc int) {
	if !s.bitmapHas(p.Sound) {
		s.setBitmap(p.Sound)
		s.bySound[p.Sound].Field24 = nil
	}
	p.Perc = perc
	s.addToList(&s.bySound[p.Sound], p)
}

func (s *serverAudio) setBitmap(id sound.ID) {
	s.bitmap[id/32] |= 1 << (id % 32)
}

func (s *serverAudio) bitmapHas(id sound.ID) bool {
	return s.bitmap[id/32]&(1<<(id%32)) != 0
}

func (s *serverAudio) addToList(a1 *audioEvent2, a2 *AudioEvent) {
	if a1.Field24 == nil {
		a2.list28 = a1.Field24
		a1.Field24 = a2
		return
	}
	result := a1.Field24
	v3 := a1.Field24
	v8 := a1.Field24

	v5 := a2.Perc
	for v4 := 1; ; {
		v6 := result.Perc
		v7 := v5 - v6
		if v7 < 0 {
			v7 = -v7
		}
		if v7 >= 5 {
			if v5 > v6 {
				break
			}
		} else if s.bySound[a2.Sound].Field16&0x10 != 0 {
			break
		}
		v4++
		if v4 > a1.Field20 {
			return
		}
		v3 = result
		result = result.list28
		if result == nil {
			break
		}
	}
	a2.list28 = result
	if result == v8 {
		a1.Field24 = a2
	} else {
		v3.list28 = a2
	}
}

func (s *serverAudio) EachEvent(fnc func(ev *AudioEvent)) {
	for it := s.head; it != nil; it = it.next0 {
		fnc(it)
	}
}

func (s *serverAudio) EachEventBitmap(fnc func(ev *AudioEvent)) {
	for i := 0; i < 32; i++ {
		mask := s.bitmap[i]
		if mask == 0 {
			continue
		}
		for j := 0; j < 32; j++ {
			if mask&(1<<j) == 0 {
				continue
			}
			p := &s.bySound[32*i+j]
			cnt := p.Field20
			for it := p.Field24; it != nil; it = it.list28 {
				cnt--
				if cnt < 0 {
					break
				}
				fnc(it)
			}
		}
	}
}

func (s *serverAudio) ReadAUD(f File) bool {
	n := int(f.ReadU32())
	if n <= 0 {
		return true
	}
	for i := 0; i < n; i++ {
		if !s.readAUDRec(f) {
			return false
		}
	}
	return false
}

func (s *serverAudio) readAUDRec(f File) bool {
	name, err := f.ReadString8()
	if err != nil {
		return false
	}
	snd := sound.ByName(name)
	if snd == 0 || !s.inited {
		f.Skip(9)
		for {
			n := int(f.ReadU8())
			if n == 0 {
				break
			}
			f.Skip(n)
		}
		return true
	}
	v6 := f.ReadU16()
	v7 := f.ReadU8()
	v8 := f.ReadI16()
	v17 := f.ReadU8()
	f.Skip(3)

	p := &s.bySound[snd]
	if v8 > 0 {
		p.MaxDist = 15 * int(v8)
	}
	p.Flags = uint32(v6)
	p.Field8 = uint32(v7)
	p.Field20 = int(v17)
	for {
		n := int(f.ReadU8())
		if n == 0 {
			break
		}
		f.Skip(n)
		p.Field12++
	}
	p.Field16 = 2
	return true
}

func (s *serverAudio) ReadAVNT(f File) bool {
	upd := s.inited
	name, err := f.ReadString8()
	if err != nil {
		return false
	}
	snd := sound.ByName(name)
	var p *audioEvent2
	if snd == 0 {
		upd = false
	} else {
		p = &s.bySound[snd]
	}
	for {
		typ := f.ReadU8()
		if typ == 0 {
			return true
		}
		switch typ {
		case 1, 5:
			f.Skip(1)
		case 2:
			v := f.ReadU8()
			if upd {
				p.Field16 = uint32(v)
			}
		case 3:
			v := f.ReadU8()
			if upd {
				p.Field8 = uint32(v)
			}
		case 4:
			v := f.ReadU8()
			if upd {
				p.Field20 = int(v)
			}
		case 6:
			f.Skip(2)
		case 7:
			for {
				n := f.ReadU8()
				if n == 0 {
					break
				}
				f.Skip(int(n))
				p.Field12++
			}
		case 8:
			f.Skip(8)
		case 9:
			v := f.ReadU16()
			if upd {
				p.MaxDist = 15 * int(v)
			}
		case 10:
			v := f.ReadU16()
			if upd {
				p.Flags = uint32(v)
			}
		default:
			return false
		}
	}
}

func (s *serverAudio) EventObj(id sound.ID, iobj Obj, kind int, code uint32) {
	obj := toObject(iobj)
	if !s.inAudio {
		s.delayedObj = append(s.delayedObj, audioEventObj{
			ID: id, Obj: obj, Kind: kind, Code: code,
		})
		return
	}
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || obj == nil || s.Field12(id) <= 0 {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassPlayer) && s.s.Players.CheckXxx(obj) {
		return
	}
	s.newAudioEventObj(id, obj, kind, code)
	for _, fnc := range s.onSound {
		fnc(id, kind, obj, obj.Pos())
	}
}

func (s *serverAudio) EventPos(id sound.ID, pos types.Pointf, kind int, code uint32) {
	if !s.inAudio {
		s.delayedPos = append(s.delayedPos, audioEventPos{
			ID: id, Pos: pos, Kind: kind, Code: code,
		})
		return
	}
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || s.Field12(id) <= 0 {
		return
	}
	s.newAudioEventPos(id, pos, kind, code)
	for _, fnc := range s.onSound {
		fnc(id, kind, nil, pos)
	}
}
