package opennox

/*
#include <defs.h>
char sub_501C00(float* a1, nox_object_t* a2);
int sub_419E60(nox_object_t* a1);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

//export nox_xxx_getSevenDwords3_501940
func nox_xxx_getSevenDwords3_501940(i int32) int32 {
	return noxServer.audio.Field12(sound.ID(i))
}

//export nox_xxx_aud_501960
func nox_xxx_aud_501960(a1 int32, a2p *nox_object_t, a3 int32, a4 int32) {
	noxServer.AudioEventObj(sound.ID(a1), asObjectC(a2p), a3, uint32(a4))
}

//export nox_xxx_audCreate_501A30
func nox_xxx_audCreate_501A30(a1 int32, cpos *C.float2, a3 int32, a4 int32) {
	noxServer.AudioEventPos(sound.ID(a1), *(*types.Pointf)(unsafe.Pointer(cpos)), a3, uint32(a4))
}

//export nox_xxx_netUpdateRemotePlr_501CA0_B
func nox_xxx_netUpdateRemotePlr_501CA0_B(a1p *nox_object_t, v2 unsafe.Pointer, v18 int8) {
	noxServer.netUpdateRemotePlrAudioEvents(asObjectC(a1p), v2, v18)
}

//export nox_xxx_utilFindSound_40AF50
func nox_xxx_utilFindSound_40AF50(name *C.char) C.int {
	return C.int(sound.ByName(GoString(name)))
}

//export nox_xxx_getSndName_40AF80
func nox_xxx_getSndName_40AF80(id C.int) *C.char {
	return internCStr(sound.ID(id).String())
}

type serverAudio struct {
	alloc   alloc.ClassT[audioEvent]
	inited  bool
	head    *audioEvent
	bySound [1024]audioEvent2
	bitmap  [32]uint32
}

var _ = [1]struct{}{}[36-unsafe.Sizeof(audioEvent{})]

type audioEvent struct {
	Next0   *audioEvent
	Sound4  sound.ID
	Pos8    types.Pointf
	Obj16   *nox_object_t
	Field20 int32
	Field24 uint32
	Field28 *audioEvent
	Perc32  int
}

var _ = [1]struct{}{}[28-unsafe.Sizeof(audioEvent2{})]

type audioEvent2 struct {
	Field0  uint32
	Field4  uint32
	Field8  uint32
	Field12 uint32
	Field16 uint32
	Field20 int
	Field24 *audioEvent
}

func (s *serverAudio) Init() {
	if s.inited {
		return
	}
	s.alloc = alloc.NewClassT("AudEvent", audioEvent{}, 128)
	for i := range s.bySound[:len(s.bySound)-1] {
		p := &s.bySound[i]
		p.Field0 = 600
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
		s.inited = false
	}
}

func (s *serverAudio) Reset() {
	s.alloc.FreeAllObjects()
	s.head = nil
}

func (s *serverAudio) Flags(id sound.ID) int {
	return int(s.bySound[id].Field4)
}

func (s *serverAudio) Field12(id sound.ID) int32 {
	return int32(s.bySound[id].Field12)
}

func (s *Server) AudioEventObj(id sound.ID, iobj noxObject, a3 int32, a4 uint32) {
	obj := toObject(iobj)
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || obj == nil || s.audio.Field12(id) <= 0 {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassPlayer) && C.sub_419E60(iobj.CObj()) != 0 {
		return
	}
	p := s.audio.alloc.NewObject()
	if p == nil {
		return
	}
	p.Sound4 = id
	if obj.Flags().Has(object.FlagDestroyed) {
		p.Obj16 = nil
	} else {
		p.Obj16 = obj.CObj()
	}
	p.Pos8 = obj.Pos()
	p.Field20 = a3
	p.Field24 = a4
	if a3 != 2 {
		s.ai.NewSound(id, obj, obj.Pos())
	}
	p.Next0 = s.audio.head
	s.audio.head = p
}

func (s *Server) AudioEventPos(id sound.ID, pos types.Pointf, a3 int32, a4 uint32) {
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || s.audio.Field12(id) <= 0 {
		return
	}
	p := s.audio.alloc.NewObject()
	if p == nil {
		return
	}
	p.Sound4 = id
	p.Pos8 = pos
	p.Obj16 = nil
	p.Field20 = a3
	p.Field24 = a4
	if a3 != 2 {
		s.ai.NewSound(id, nil, pos)
	}
	p.Next0 = s.audio.head
	s.audio.head = p
}

func (s *serverAudio) resetBitmap() {
	s.bitmap = [32]uint32{}
}

func (s *Server) netUpdateRemotePlrAudioEvents(obj *Object, v2 unsafe.Pointer, v18 int8) {
	s.audio.resetBitmap()
	var tm *Team
	if nox_xxx_servObjectHasTeam_419130(obj.teamPtr()) {
		tm = s.teamByYyy(byte(obj.Field13))
	}
	cp, free := alloc.New(types.Pointf{})
	defer free()
	for it := s.audio.head; it != nil; it = it.Next0 {
		if it.Field20 == 1 {
			tm2 := s.teamByYyy(byte(it.Field24))
			if tm == nil || tm2 == nil || tm != tm2 {
				continue
			}
		} else if it.Field20 == 2 {
			if obj.NetCode != it.Field24 {
				continue
			}
		}
		*cp = it.Pos8
		v12 := int32(C.sub_501C00((*C.float)(unsafe.Pointer(cp)), it.Obj16))
		if v12 == int32(v18) || v12 == 0 {
			if int32(*(*uint8)(unsafe.Add(v2, 188))) != 0 || it.Sound4 < sound.SoundSpellPhonemeUp || it.Sound4 > sound.SoundSpellPhonemeUpLeft || obj.CObj() != it.Obj16 {
				fade := s.ai.soundFadePerc(it.Sound4, it.Pos8, *(*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 3632))) / 2
				if fade > 0 {
					if s.audio.bySound[it.Sound4].Field20 != 0 {
						s.audio.addAudio(it, fade)
					} else {
						netSendAudioEvent(obj.AsUnit(), it, int16(fade))
					}
				}
			}
		}
	}
	s.netSendAudioEvents(obj)
}

func (s *serverAudio) addAudio(p *audioEvent, perc int) {
	if !s.bitmapHas(p.Sound4) {
		s.setBitmap(p.Sound4)
		s.bySound[p.Sound4].Field24 = nil
	}
	p.Perc32 = perc
	s.addToList(&s.bySound[p.Sound4], p)
}

func (s *serverAudio) setBitmap(id sound.ID) {
	s.bitmap[id/32] |= 1 << (id % 32)
}

func (s *serverAudio) bitmapHas(id sound.ID) bool {
	return s.bitmap[id/32]&(1<<(id%32)) != 0
}

func (s *serverAudio) addToList(a1 *audioEvent2, a2 *audioEvent) {
	if a1.Field24 == nil {
		a2.Field28 = a1.Field24
		a1.Field24 = a2
		return
	}
	result := a1.Field24
	v3 := a1.Field24
	v8 := a1.Field24

	v5 := a2.Perc32
	for v4 := 1; ; {
		v6 := result.Perc32
		v7 := v5 - v6
		if v7 < 0 {
			v7 = -v7
		}
		if v7 >= 5 {
			if v5 > v6 {
				break
			}
		} else if s.bySound[a2.Sound4].Field16&0x10 != 0 {
			break
		}
		v4++
		if v4 > a1.Field20 {
			return
		}
		v3 = result
		result = result.Field28
		if result == nil {
			break
		}
	}
	a2.Field28 = result
	if result == v8 {
		a1.Field24 = a2
	} else {
		v3.Field28 = a2
	}
}

func (s *Server) netSendAudioEvents(obj *Object) {
	for i := 0; i < 32; i++ {
		mask := s.audio.bitmap[i]
		if mask == 0 {
			continue
		}
		for j := 0; j < 32; j++ {
			if mask&(1<<j) == 0 {
				continue
			}
			p := &s.audio.bySound[32*i+j]
			cnt := p.Field20
			for it := p.Field24; it != nil; it = it.Field28 {
				cnt--
				if cnt < 0 {
					break
				}
				netSendAudioEvent(obj.AsUnit(), it, int16(it.Perc32))
			}
		}
	}
}

func (s *serverAudio) readAUD(f *MemFile) bool {
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

func (s *serverAudio) readAUDRec(f *MemFile) bool {
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
		p.Field0 = 15 * uint32(v8)
	}
	p.Field4 = uint32(v6)
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

func (s *serverAudio) readAVNT(f *MemFile) bool {
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
				p.Field0 = 15 * uint32(v)
			}
		case 10:
			v := f.ReadU16()
			if upd {
				p.Field4 = uint32(v)
			}
		default:
			return false
		}
	}
}
