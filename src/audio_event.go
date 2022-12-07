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

var (
	dword_5d4594_1599064 bool
	dword_5d4594_1599060 *audioEvent
	dword_5d4594_1599056 alloc.ClassT[audioEvent]
	arr_5d4594_1570284   [1024]audioEvent2
	arr_5d4594_1598928   [32]uint32
)

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

func nox_xxx_allocAudEventArray_501860() {
	if dword_5d4594_1599064 {
		return
	}
	dword_5d4594_1599056 = alloc.NewClassT("AudEvent", audioEvent{}, 128)
	for i := range arr_5d4594_1570284[:len(arr_5d4594_1570284)-1] {
		p := &arr_5d4594_1570284[i]
		p.Field0 = 600
		p.Field8 = 0
		p.Field12 = 0
		p.Field16 = 0
		p.Field20 = 0
		p.Field24 = nil
	}
	dword_5d4594_1599064 = true
}

func sub_5018D0() {
	if dword_5d4594_1599064 {
		dword_5d4594_1599056.Free()
		dword_5d4594_1599060 = nil
		dword_5d4594_1599064 = false
	}
}

func sub_502100() {
	dword_5d4594_1599056.FreeAllObjects()
	dword_5d4594_1599060 = nil
}

func getSoundFlags(ind sound.ID) int {
	return int(arr_5d4594_1570284[ind].Field4)
}

//export nox_xxx_getSevenDwords3_501940
func nox_xxx_getSevenDwords3_501940(i int32) int32 {
	return int32(arr_5d4594_1570284[i].Field12)
}

//export nox_xxx_aud_501960
func nox_xxx_aud_501960(a1 int32, a2p *nox_object_t, a3 int32, a4 int32) {
	nox_xxx_aud501960(sound.ID(a1), asObjectC(a2p), a3, uint32(a4))
}
func nox_xxx_aud501960(id sound.ID, a2 noxObject, a3 int32, a4 uint32) {
	obj := toObject(a2)
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || a2 == nil || nox_xxx_getSevenDwords3_501940(int32(id)) <= 0 {
		return
	}
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassPlayer) && C.sub_419E60(a2.CObj()) != 0 {
		return
	}
	p := dword_5d4594_1599056.NewObject()
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
		noxServer.ai.NewSound(id, obj, obj.Pos())
	}
	p.Next0 = dword_5d4594_1599060
	dword_5d4594_1599060 = p
}

//export nox_xxx_audCreate_501A30
func nox_xxx_audCreate_501A30(a1 int32, cpos *C.float2, a3 int32, a4 int32) {
	nox_xxx_audCreate501A30(sound.ID(a1), *(*types.Pointf)(unsafe.Pointer(cpos)), a3, uint32(a4))
}
func nox_xxx_audCreate501A30(id sound.ID, pos types.Pointf, a3 int32, a4 uint32) {
	if noxflags.HasGame(noxflags.GameFlag20) {
		return
	}
	if id == 0 || nox_xxx_getSevenDwords3_501940(int32(id)) <= 0 {
		return
	}
	p := dword_5d4594_1599056.NewObject()
	if p == nil {
		return
	}
	p.Sound4 = id
	p.Pos8 = pos
	p.Obj16 = nil
	p.Field20 = a3
	p.Field24 = a4
	if a3 != 2 {
		noxServer.ai.NewSound(id, nil, pos)
	}
	p.Next0 = dword_5d4594_1599060
	dword_5d4594_1599060 = p
}

func sub_501E80() {
	arr_5d4594_1598928 = [32]uint32{}
}

//export nox_xxx_netUpdateRemotePlr_501CA0_B
func nox_xxx_netUpdateRemotePlr_501CA0_B(a1p *nox_object_t, v2 unsafe.Pointer, v18 int8) {
	s := noxServer
	obj := asObjectC(a1p)
	sub_501E80()
	var tm *Team
	if nox_xxx_servObjectHasTeam_419130(obj.teamPtr()) {
		tm = s.teamByYyy(byte(obj.Field13))
	}
	cp, free := alloc.New(types.Pointf{})
	defer free()
	for it := dword_5d4594_1599060; it != nil; it = it.Next0 {
		v10 := it.Field20
		if v10 == 1 {
			tm2 := s.teamByYyy(byte(it.Field24))
			if tm == nil || tm2 == nil || tm != tm2 {
				continue
			}
		} else if v10 == 2 && obj.NetCode != it.Field24 {
			continue
		}
		*cp = it.Pos8
		v12 := int32(C.sub_501C00((*C.float)(unsafe.Pointer(cp)), it.Obj16))
		if v12 == int32(v18) || v12 == 0 {
			if int32(*(*uint8)(unsafe.Add(v2, 188))) != 0 || it.Sound4 < sound.SoundSpellPhonemeUp || it.Sound4 > sound.SoundSpellPhonemeUpLeft || obj.CObj() != it.Obj16 {
				fade := s.ai.soundFadePerc(it.Sound4, it.Pos8, *(*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 3632))) / 2
				if fade > 0 {
					if arr_5d4594_1570284[it.Sound4].Field20 != 0 {
						sub_501EA0(it, fade)
					} else {
						sub_501FD0(obj.AsUnit(), it, int16(fade))
					}
				}
			}
		}
	}
	sub_502060(obj)
}

func sub_501EA0(p *audioEvent, perc int) {
	if !sub_501EF0(p.Sound4) {
		sub_501F10(p.Sound4)
		arr_5d4594_1570284[p.Sound4].Field24 = nil
	}
	p.Perc32 = perc
	sub_501F30(&arr_5d4594_1570284[p.Sound4], p)
}

func sub_501F10(a1 sound.ID) {
	arr_5d4594_1598928[a1/32] |= 1 << (a1 % 32)
}

func sub_501EF0(a1 sound.ID) bool {
	return arr_5d4594_1598928[a1/32]&(1<<(a1%32)) != 0
}

func sub_501F30(a1 *audioEvent2, a2 *audioEvent) {
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
		} else if arr_5d4594_1570284[a2.Sound4].Field16&0x10 != 0 {
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

func sub_502060(obj *Object) {
	for i := 0; i < 32; i++ {
		mask := arr_5d4594_1598928[i]
		if mask == 0 {
			continue
		}
		for j := 0; j < 32; j++ {
			if mask&(1<<j) == 0 {
				continue
			}
			p := &arr_5d4594_1570284[32*i+j]
			cnt := p.Field20
			for it := p.Field24; it != nil; it = it.Field28 {
				cnt--
				if cnt < 0 {
					break
				}
				sub_501FD0(obj.AsUnit(), it, int16(it.Perc32))
			}
		}
	}
}
