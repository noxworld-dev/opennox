package opennox

/*
#include "server__script__script.h"
#include "server__script__internal.h"
#include "GAME4_1.h" // for nox_xxx_scriptPrepareFoundUnit_511D70 and nox_xxx_script_511C50
extern int nox_script_count_xxx_1599640;
extern nox_script_xxx_t* nox_script_arr_xxx_1599636;
extern unsigned int dword_5d4594_3821636;
extern unsigned int dword_5d4594_3821640;
int sub_516570();
*/
import "C"
import (
	"encoding/binary"
	"image/color"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

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
	s          *Server
	fxNames    map[string]noxnet.Op
	activators struct {
		lastID uint32
		head   *Activator
	}
}

func (s *noxScript) Init(srv *Server) {
	s.s = srv
	s.fxNames = make(map[string]noxnet.Op)
	for fx := noxnet.MSG_FX_PARTICLEFX; fx <= noxnet.MSG_FX_MANA_BOMB_CANCEL; fx++ {
		s.fxNames[fx.String()] = fx
	}
}

type Activator struct {
	frame     uint32
	callback  uint32
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

func (s *noxScript) newScriptTimer(df int, callback, arg uint32) uint32 {
	act := &Activator{
		id:       s.actNextHandle(),
		frame:    gameFrame() + uint32(df),
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
	binary.LittleEndian.PutUint32(buf[:], gameFrame())
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
			oid = it.trigger.ScriptID()
		}
		binary.LittleEndian.PutUint32(buf[:], uint32(oid))
		cryptFileReadWrite(buf[:4])
		oid = 0
		if it.caller != nil {
			oid = it.caller.ScriptID()
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
			frame:    gameFrame() + (frame - saveFrame),
			callback: callback, arg: arg,
			triggerID: trigger, callerID: caller,
		}
		s.actAppend(act)
	}
	return 1
}

func (s *noxScript) scripts() []C.nox_script_xxx_t {
	return unsafe.Slice((*C.nox_script_xxx_t)(unsafe.Pointer(C.nox_script_arr_xxx_1599636)), int(C.nox_script_count_xxx_1599640))
}

func (s *noxScript) actRun() {
	scripts := s.scripts()
	for it := s.activators.head; it != nil; {
		if it.frame > gameFrame() {
			it = it.next
		} else {
			callback := it.callback
			caller := it.caller
			trigger := it.trigger
			if scripts[callback].size_28 != 0 {
				s.PushU32(it.arg)
			}
			it = s.actDoneNext(it)
			C.nox_script_callByIndex_507310(C.int(callback), unsafe.Pointer(caller.CObj()), unsafe.Pointer(trigger.CObj()))
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

func (s *noxScript) PushU32(v uint32) {
	C.nox_script_push(C.int(v))
}

func (s *noxScript) PushI32(v int32) {
	C.nox_script_push(C.int(v))
}

func (s *noxScript) PushF32(v float32) {
	C.nox_script_push(C.int(math.Float32bits(v)))
}

func (s *noxScript) PushBool(v bool) {
	C.nox_script_push(C.int(bool2int(v)))
}

func (s *noxScript) OnEvent(event script.EventType) {
	scripts := s.scripts()
	for i := range scripts {
		sc := &scripts[i]
		name := GoString(sc.field_0)
		if strings.HasPrefix(name, string(event)) {
			C.nox_script_callByIndex_507310(C.int(i), nil, nil)
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

func (s *noxScript) Caller() *Object {
	return asObject(C.nox_script_get_caller())
}

func (s *noxScript) Trigger() *Object {
	return asObject(C.nox_script_get_trigger())
}

func (s *noxScript) PopI32() int32 {
	return int32(C.nox_script_pop())
}

func (s *noxScript) PopU32() uint32 {
	return uint32(C.nox_script_pop())
}

func (s *noxScript) PopF32() float32 {
	return math.Float32frombits(uint32(C.nox_script_pop()))
}

func (s *noxScript) PopBool() bool {
	return C.nox_script_pop() != 0
}

func (s *noxScript) PopString() string {
	return GoString(C.nox_script_getString_512E40(C.nox_script_pop()))
}

func (s *noxScript) PopObject() *Object {
	return s.scriptToObject(int(C.nox_script_pop()))
}

func (s *noxScript) PopPointf() types.Pointf {
	y := s.PopF32()
	x := s.PopF32()
	return types.Pointf{X: x, Y: y}
}

func (s *noxScript) builtinGetF40() int { return int(C.dword_5d4594_3821636) }
func (s *noxScript) builtinGetF44() int { return int(C.dword_5d4594_3821640) }

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
