package opennox

/*
#include "server__script__script.h"
#include "server__script__internal.h"
#include "GAME4_1.h" // for nox_xxx_scriptPrepareFoundUnit_511D70 and nox_xxx_script_511C50
extern int nox_script_count_xxx_1599640;
extern void* nox_script_caller_3821964;
extern void* nox_script_trigger_3821968;
extern nox_script_xxx_t* nox_script_arr_xxx_1599636;
extern unsigned int dword_5d4594_3821636;
extern unsigned int dword_5d4594_3821640;
int sub_516570();
int nox_xxx_gameIsSwitchToSolo_4DB240();
size_t nox_script_readWriteWww_5417C0(FILE* a1, FILE* a2, FILE* a3);
*/
import "C"
import (
	"image/color"
	"math"
	"os"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

//export nox_script_builtinGetF40
func nox_script_builtinGetF40() C.int {
	return C.int(noxServer.noxScript.builtinGetF40())
}

//export nox_script_builtinGetF44
func nox_script_builtinGetF44() C.int {
	return C.int(noxServer.noxScript.builtinGetF44())
}

//export nox_script_activatorCancelAll_51AC60
func nox_script_activatorCancelAll_51AC60() {
	noxServer.noxScript.actCancelAll()
}

//export nox_script_activatorClearObj_51AE60
func nox_script_activatorClearObj_51AE60(obj *C.nox_object_t) {
	noxServer.noxScript.actClearObj(asObjectC(obj))
}

//export nox_script_activatorSave_51AEA0
func nox_script_activatorSave_51AEA0() C.int {
	return C.int(noxServer.noxScript.actSave())
}

//export nox_script_activatorLoad_51AF80
func nox_script_activatorLoad_51AF80() C.int {
	return C.int(noxServer.noxScript.actLoad())
}

//export nox_script_activatorResolveObjs_51B0C0
func nox_script_activatorResolveObjs_51B0C0() {
	noxServer.noxScript.actResolveObjs()
}

//export nox_xxx_netGetUnitCodeServ_578AC0
func nox_xxx_netGetUnitCodeServ_578AC0(cobj *nox_object_t) C.uint {
	return C.uint(noxServer.getUnitNetCode(asObjectC(cobj)))
}

//export nox_server_scriptValToObjectPtr_511B60
func nox_server_scriptValToObjectPtr_511B60(val C.int) *C.nox_object_t {
	return noxServer.noxScript.scriptToObject(int(val)).CObj()
}

//export nox_script_push
func nox_script_push(v C.int) {
	noxServer.noxScript.PushI32(int32(v))
}

//export nox_script_pop
func nox_script_pop() C.int {
	return C.int(noxServer.noxScript.PopI32())
}

//export nox_script_saveStack
func nox_script_saveStack() C.int {
	return C.int(noxServer.noxScript.saveStack())
}

//export nox_script_resetStack
func nox_script_resetStack() {
	noxServer.noxScript.resetStack()
}

//export nox_script_adjustStack
func nox_script_adjustStack(prev, sz C.int) {
	noxServer.noxScript.adjustStack(int(prev), int(sz))
}

//export nox_script_callOnEvent
func nox_script_callOnEvent(cevent *C.char, a1, a2 unsafe.Pointer) {
	if a1 != nil || a2 != nil { // these are never set to anything
		panic("unexpected argument to nox_script_callOnEvent")
	}
	event := script.EventType(GoString(cevent))
	noxServer.scriptOnEvent(event)
}

var (
	nox_script_objTelekinesisHand  int
	nox_script_objCinemaRemove     []int
	nox_xxx_imagCasterUnit_1569664 *Unit
)

type noxScript struct {
	s        *Server
	fxNames  map[string]noxnet.Op
	f40      int
	f44      int
	nameSuff string
	vm       struct {
		stack []uint32
	}
	activators struct {
		lastID uint32
		head   *Activator
	}
	panic noxScriptPanic
}

func (s *noxScript) Init(srv *Server) {
	s.s = srv
	s.fxNames = make(map[string]noxnet.Op)
	for fx := noxnet.MSG_FX_PARTICLEFX; fx <= noxnet.MSG_FX_MANA_BOMB_CANCEL; fx++ {
		s.fxNames[fx.String()] = fx
	}
}

var _ = [1]struct{}{}[48-unsafe.Sizeof(noxScriptCode{})]

type noxScriptCode struct {
	name       *C.char        // 0, 0
	stack_size uint32         // 1, 4
	size_28    uint32         // 2, 8
	field_12   uint32         // 3, 12; len field_20 and field_24
	field_16   uint32         // 4, 16
	field_20   *uint32        // 5, 20
	field_24   *uint32        // 6, 24
	field_28   *uint32        // 7, 28
	data       unsafe.Pointer // 8, 32
	suff       *C.char        // 9, 36
	field_40   uint32         // 10, 40
	field_44   uint32         // 11, 44
}

func (s *noxScript) scripts() []noxScriptCode {
	if C.nox_script_arr_xxx_1599636 == nil {
		return nil
	}
	return unsafe.Slice((*noxScriptCode)(unsafe.Pointer(C.nox_script_arr_xxx_1599636)), int(C.nox_script_count_xxx_1599640))
}

func (s *noxScript) callByIndex(fnc int, caller, trigger noxObject) {
	C.nox_script_callByIndex_507310(C.int(fnc), unsafe.Pointer(toCObj(caller)), unsafe.Pointer(toCObj(trigger)))
}

func (s *noxScript) Caller() *Object {
	return asObject(C.nox_script_caller_3821964)
}

func (s *noxScript) Trigger() *Object {
	return asObject(C.nox_script_trigger_3821968)
}

func (s *noxScript) resetStack() {
	s.vm.stack = s.vm.stack[:0]
}

func (s *noxScript) saveStack() int {
	return len(s.vm.stack)
}

func (s *noxScript) adjustStack(prev, sz int) {
	if n := len(s.vm.stack); n != prev+sz {
		if sz != 0 {
			if n != 0 {
				v := s.PopU32()
				s.vm.stack = s.vm.stack[:prev]
				s.PushU32(v)
			} else {
				s.vm.stack = s.vm.stack[:prev]
				s.PushU32(0)
			}
		} else {
			s.vm.stack = s.vm.stack[:prev]
		}
	}
}

func (s *noxScript) stackAt(i int) uint32 {
	if i < 0 || i >= len(s.vm.stack) {
		return 0
	}
	return s.vm.stack[i]
}

func (s *noxScript) PushU32(v uint32) {
	s.vm.stack = append(s.vm.stack, v)
}

func (s *noxScript) PushI32(v int32) {
	s.vm.stack = append(s.vm.stack, uint32(v))
}

func (s *noxScript) PushF32(v float32) {
	s.vm.stack = append(s.vm.stack, math.Float32bits(v))
}

func (s *noxScript) PushBool(v bool) {
	s.vm.stack = append(s.vm.stack, uint32(bool2int(v)))
}

func (s *noxScript) PopI32() int32 {
	n := len(s.vm.stack)
	if n == 0 {
		return 0
	}
	v := s.vm.stack[n-1]
	s.vm.stack = s.vm.stack[:n-1]
	return int32(v)
}

func (s *noxScript) PopU32() uint32 {
	n := len(s.vm.stack)
	if n == 0 {
		return 0
	}
	v := s.vm.stack[n-1]
	s.vm.stack = s.vm.stack[:n-1]
	return v
}

func (s *noxScript) PopF32() float32 {
	return math.Float32frombits(s.PopU32())
}

func (s *noxScript) PopBool() bool {
	return s.PopU32() != 0
}

func (s *noxScript) PopString() string {
	return GoString(C.nox_script_getString_512E40(C.int(s.PopU32())))
}

func (s *noxScript) PopObject() *Object {
	return s.scriptToObject(int(nox_script_pop()))
}

func (s *noxScript) PopPointf() types.Pointf {
	y := s.PopF32()
	x := s.PopF32()
	return types.Pointf{X: x, Y: y}
}

func (s *noxScript) nox_xxx_scriptRunFirst_507290() {
	s.resetBuiltin()
	if scripts := s.scripts(); len(scripts) >= 2 {
		sc := unsafe.Slice((*int32)(unsafe.Pointer(scripts[1].field_28)), 4)
		sc[0] = -2
		sc[1] = -1
		sc[2] = 1
		sc[3] = 0
		if nox_xxx_gameIsSwitchToSolo_4DB240() == 0 {
			s.callByIndex(1, nil, nil)
		}
	} else {
		scriptLog.Printf("noxscript: no init function")
	}
}

func (s *noxScript) OnEvent(event script.EventType) {
	scripts := s.scripts()
	for i := range scripts {
		sc := &scripts[i]
		name := GoString(sc.name)
		if strings.HasPrefix(name, string(event)) {
			s.callByIndex(i, nil, nil)
		}
	}
}

func (s *Server) getUnitNetCode(p noxObject) int {
	obj := toObject(p)
	if obj == nil {
		return 0
	}
	if obj.net_code >= 0x8000 {
		return 0
	}
	ext := int(obj.extent)
	if ext >= 0x8000 {
		return 0
	}
	if !obj.Class().HasAny(object.ClassClientPersist | object.ClassImmobile) {
		return int(obj.net_code)
	}
	ext |= 0x8000
	return ext
}

func (s *noxScript) scriptToObject(val int) *Object {
	if val == -1 {
		obj := s.Caller()
		if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
			return nil
		}
		return obj
	}
	if val == -2 {
		obj := s.Trigger()
		if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
			return nil
		}
		return obj
	}
	if obj := asObjectC(C.nox_xxx_script_511C50(C.int(val))); obj != nil {
		return obj
	}

	for obj := s.s.firstServerObject(); obj != nil; obj = obj.Next() {
		if !obj.Flags().Has(object.FlagDestroyed) && obj.ScriptID() == val {
			C.nox_xxx_scriptPrepareFoundUnit_511D70(obj.CObj())
			return obj
		}
		for sub := obj.FirstItem(); sub != nil; sub = sub.NextItem() {
			if !sub.Flags().Has(object.FlagDestroyed) && sub.ScriptID() == val {
				C.nox_xxx_scriptPrepareFoundUnit_511D70(sub.CObj())
				return sub
			}
		}
	}
	for obj := s.s.firstServerObjectUninited(); obj != nil; obj = obj.Next() {
		if !obj.Flags().Has(object.FlagDestroyed) && obj.ScriptID() == val {
			C.nox_xxx_scriptPrepareFoundUnit_511D70(obj.CObj())
			return obj
		}
	}
	return nil
}

func (s *noxScript) resetBuiltin() {
	s.f40 = 0
	s.f44 = 0
	s.nameSuff = ""
}

func (s *noxScript) builtinGetF40() int { return s.f40 }
func (s *noxScript) builtinGetF44() int { return s.f44 }

func (s *noxScript) scriptNameSuff(i int) string {
	scripts := s.scripts()
	return GoString(scripts[i].suff)
}

func (s *noxScript) scriptField40(i int) int {
	scripts := s.scripts()
	return int(scripts[i].field_40)
}

func (s *noxScript) scriptField44(i int) int {
	scripts := s.scripts()
	return int(scripts[i].field_44)
}

func (s *noxScript) noxScriptEndGame(v int) {
	dword_587000_311372 = v
	dword_5d4594_2516476 |= 1 << v
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	sub_413960()
	sub_477530(false)
	nox_client_quit_4460C0()
}

//export sub_5165D0
func sub_5165D0() {
	s := &noxServer.noxScript
	*memmap.PtrUint32(0x5D4594, 2386828) = s.PopU32() - 1
	sub_413A00(1)
	noxClient.r.FadeInScreen(25, true, func() {
		C.sub_516570()
	})
}

func (s *Server) CinemaPlayers(enable bool) {
	if nox_script_objTelekinesisHand == 0 {
		nox_script_objTelekinesisHand = s.getObjectTypeID("TelekinesisHand")
	}
	const (
		perc       = 0.16
		fadeOutDur = 30
		fadeInDur  = 10
	)
	if !enable {
		if noxClient.r.FadeOutCinema(perc, fadeOutDur, color.Black) {
			sub_477530(false)
		}
		for it := s.firstServerObject(); it != nil; it = it.Next() {
			if it.objTypeInd() == nox_script_objTelekinesisHand {
				if f := it.Flags(); f.Has(object.FlagNoCollide) {
					it.SetFlags(f &^ object.FlagNoCollide)
				}
			}
		}
		return
	}
	inFade := noxClient.r.CheckFade(noxrender.FadeInCinemaKey)
	if noxClient.r.FadeInCinema(perc, fadeInDur, color.Black) {
		sub_477530(true)
	}
	if inFade {
		return
	}
	if len(nox_script_objCinemaRemove) == 0 {
		for _, name := range []string{
			"ToxicCloud", "SmallToxicCloud", "Meteor", "SmallFist", "MediumFist", "LargeFist", "Pixie",
		} {
			nox_script_objCinemaRemove = append(nox_script_objCinemaRemove, s.getObjectTypeID(name))
		}
	}

	var next *Object
	for it := firstServerObjectUpdatable2(); it != nil; it = next {
		next = it.Next()
		if it.objTypeInd() != int(memmap.Uint32(0x5D4594, 2386900)) {
			it.Delete()
		}
	}

	next = nil
	for it := s.firstServerObject(); it != nil; it = next {
		next = it.Next()
		if it.OwnerC() != nil {
			for _, id := range nox_script_objCinemaRemove {
				if it.objTypeInd() == id {
					it.Delete()
					break
				}
			}
		} else {
			if it.objTypeInd() == nox_script_objTelekinesisHand {
				if f := it.Flags(); !f.Has(object.FlagNoCollide) {
					it.SetFlags(f | object.FlagNoCollide)
				}
			}
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_WALL, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_MANA_BOMB, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_LIGHTNING, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_CHAIN_LIGHTNING, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_DRAIN_MANA, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_FORCE_OF_NATURE, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_GREATER_HEAL, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_CHANNEL_LIFE, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_CHARM, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_BLINK, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_SWAP, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_TURN_UNDEAD, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_PLASMA, it)
			nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_SUMMON_BAT, it)
		}
	}
}

//export nox_setImaginaryCaster
func nox_setImaginaryCaster() C.int {
	s := noxServer
	nox_xxx_imagCasterUnit_1569664 = s.newObjectByTypeID("ImaginaryCaster").AsUnit()
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return 0
	}
	nox_xxx_createAt_4DAA50(nox_xxx_imagCasterUnit_1569664, nil, types.Pointf{X: 128 * common.GridStep, Y: 128 * common.GridStep})
	return 1
}

//export nox_script_readWriteZzz_541670
func nox_script_readWriteZzz_541670(cpath, cpath2, cdst *C.char) C.int {
	if cpath == nil {
		return 0
	}
	if cpath2 == nil {
		return 0
	}
	if cdst == nil {
		return 0
	}
	path, path2, dst := GoString(cpath), GoString(cpath2), GoString(cdst)
	f1, err := ifs.Open(path)
	if err != nil {
		return 0
	}
	defer f1.Close()

	f2, err := ifs.Open(path2)
	if err != nil {
		return 0
	}
	defer f2.Close()

	v6, _ := fileSize(f1)
	if v6 == 0 {
		ifs.Remove(dst)
		ifs.Rename(path2, dst)
		return 1
	}

	v7, _ := fileSize(f2)
	if v7 == 0 {
		ifs.Remove(dst)
		ifs.Rename(path, dst)
		return 1
	}

	df, err := ifs.OpenFile(dst, os.O_RDWR)
	if err != nil {
		return 0
	}
	defer df.Close()
	C.nox_script_readWriteWww_5417C0(newFileHandle(&File{File: f1}), newFileHandle(&File{File: f2}), newFileHandle(&File{File: df}))
	return 1
}
