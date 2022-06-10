package opennox

/*
#include "server__script__script.h"
#include "server__script__internal.h"
#include "GAME4_1.h" // for nox_xxx_scriptPrepareFoundUnit_511D70 and nox_xxx_script_511C50
extern int nox_script_count_xxx_1599640;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern nox_script_xxx_t* nox_script_arr_xxx_1599636;
extern uint32_t dword_587000_311372;
extern unsigned int dword_5d4594_3821636;
extern unsigned int dword_5d4594_3821640;
int sub_516570();
*/
import "C"
import (
	"encoding/binary"
	"image"
	"image/color"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	nox_script_objTelekinesisHand int
	nox_script_objCinemaRemove    []int
	noxScriptFXNames              = make(map[string]noxnet.Op)
)

func init() {
	for fx := noxnet.MSG_FX_PARTICLEFX; fx <= noxnet.MSG_FX_MANA_BOMB_CANCEL; fx++ {
		noxScriptFXNames[fx.String()] = fx
	}
}

type activators struct {
	lastID uint32
	head   *Activator
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

func (s *Server) nox_script_activatorNextHandle_51AD20() uint32 {
	s.activators.lastID++
	id := s.activators.lastID
	if s.activators.lastID > 32000 {
		id = 1
		s.activators.lastID = 1
	}
	return id
}

//export nox_script_activatorCancel_51AD60
func nox_script_activatorCancel_51AD60(id C.int) C.bool {
	return C.bool(noxServer.nox_script_activatorCancel(uint32(id)))
}

func (s *Server) nox_script_activatorCancel(id uint32) bool {
	for it := s.activators.head; it != nil; it = it.next {
		if it.id == id {
			s.nox_script_activatorDoneNext_51AD90(it)
			return true
		}
	}
	return false
}

//export nox_script_activatorCancelAll_51AC60
func nox_script_activatorCancelAll_51AC60() {
	noxServer.activators.head = nil
}

func (s *Server) newScriptTimer(df int, callback, arg uint32) uint32 {
	act := &Activator{
		id:       s.nox_script_activatorNextHandle_51AD20(),
		frame:    gameFrame() + uint32(df),
		callback: callback, arg: arg,
	}
	s.nox_script_activator_append(act)
	return act.id
}

//export nox_script_activatorTimer_51ACA0
func nox_script_activatorTimer_51ACA0(df, callback, arg C.int) {
	id := noxServer.newScriptTimer(int(df), uint32(callback), uint32(arg))
	noxServer.nox_script_push(id)
}

func (s *Server) nox_script_activatorClearObj(obj *Object) {
	for it := s.activators.head; it != nil; {
		if it.trigger == obj {
			it = s.nox_script_activatorDoneNext_51AD90(it)
		} else {
			if it.caller == obj {
				it.caller = nil
			}
			it = it.next
		}
	}
}

//export nox_script_activatorClearObj_51AE60
func nox_script_activatorClearObj_51AE60(obj *C.nox_object_t) {
	noxServer.nox_script_activatorClearObj(asObjectC(obj))
}

func (s *Server) nox_script_activator_append(act *Activator) {
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

//export nox_script_activatorSave_51AEA0
func nox_script_activatorSave_51AEA0() C.int {
	return C.int(noxServer.nox_script_activatorSave())
}

func (s *Server) nox_script_activatorSave() int {
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

//export nox_script_activatorLoad_51AF80
func nox_script_activatorLoad_51AF80() C.int {
	return C.int(noxServer.nox_script_activatorLoad())
}

func (s *Server) nox_script_activatorLoad() int {
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
			id:       s.nox_script_activatorNextHandle_51AD20(),
			frame:    gameFrame() + (frame - saveFrame),
			callback: callback, arg: arg,
			triggerID: trigger, callerID: caller,
		}
		s.nox_script_activator_append(act)
	}
	return 1
}

func (s *Server) nox_script_activatorRun_51ADF0() {
	scripts := unsafe.Slice((*C.nox_script_xxx_t)(unsafe.Pointer(C.nox_script_arr_xxx_1599636)), int(C.nox_script_count_xxx_1599640))
	for it := s.activators.head; it != nil; {
		if it.frame > gameFrame() {
			it = it.next
		} else {
			callback := it.callback
			caller := it.caller
			trigger := it.trigger
			if scripts[callback].size_28 != 0 {
				s.nox_script_push(it.arg)
			}
			it = s.nox_script_activatorDoneNext_51AD90(it)
			C.nox_script_callByIndex_507310(C.int(callback), unsafe.Pointer(caller.CObj()), unsafe.Pointer(trigger.CObj()))
		}
	}
}

//export nox_script_activatorResolveObjs_51B0C0
func nox_script_activatorResolveObjs_51B0C0() {
	noxServer.nox_script_activatorResolveObjs()
}

func (s *Server) nox_script_activatorResolveObjs() { // nox_script_activatorResolveObjs_51B0C0
	for it := s.activators.head; it != nil; it = it.next {
		if it.triggerID != 0 {
			it.trigger = s.nox_server_scriptValToObjectPtr(int(it.triggerID))
			it.triggerID = 0
		}
		if it.callerID != 0 {
			it.caller = s.nox_server_scriptValToObjectPtr(int(it.callerID))
			it.callerID = 0
		}
	}
}

func (s *Server) nox_script_activatorDoneNext_51AD90(act *Activator) *Activator {
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

func (s *Server) nox_script_push(v uint32) {
	C.nox_script_push(C.int(v))
}

//export nox_script_callOnEvent
func nox_script_callOnEvent(cevent *C.char, a1, a2 unsafe.Pointer) {
	if a1 != nil || a2 != nil { // these are never set to anything
		panic("unexpected argument to nox_script_callOnEvent")
	}
	event := script.EventType(GoString(cevent))
	noxServer.scriptOnEvent(event)
}

func (s *Server) noxscriptOnEvent(event script.EventType) {
	for i := 0; i < int(C.nox_script_count_xxx_1599640); i++ {
		sc := (*C.nox_script_xxx_t)(unsafe.Add(unsafe.Pointer(C.nox_script_arr_xxx_1599636), unsafe.Sizeof(C.nox_script_xxx_t{})*uintptr(i)))
		name := GoString(sc.field_0)
		if strings.HasPrefix(name, string(event)) {
			C.nox_script_callByIndex_507310(C.int(i), nil, nil)
		}
	}
}

//export nox_server_scriptValToObjectPtr_511B60
func nox_server_scriptValToObjectPtr_511B60(val C.int) *C.nox_object_t {
	return noxServer.nox_server_scriptValToObjectPtr(int(val)).CObj()
}

func (s *Server) nox_server_scriptValToObjectPtr(val int) *Object {
	if val == -1 {
		obj := asObject(C.nox_script_get_caller())
		if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
			return nil
		}
		return obj
	}
	if val == -2 {
		obj := asObject(C.nox_script_get_trigger())
		if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
			return nil
		}
		return obj
	}
	if obj := asObjectC(C.nox_xxx_script_511C50(C.int(val))); obj != nil {
		return obj
	}

	for obj := s.firstServerObject(); obj != nil; obj = obj.Next() {
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
	for obj := s.firstServerObjectUninited(); obj != nil; obj = obj.Next() {
		if !obj.Flags().Has(object.FlagDestroyed) && obj.ScriptID() == val {
			C.nox_xxx_scriptPrepareFoundUnit_511D70(obj.CObj())
			return obj
		}
	}
	return nil
}

func noxScriptPopI32() int32 {
	return int32(C.nox_script_pop())
}

func noxScriptPopU32() uint32 {
	return uint32(C.nox_script_pop())
}

func noxScriptPopF32() float32 {
	return math.Float32frombits(uint32(C.nox_script_pop()))
}

func noxScriptPopString() string {
	return GoString(C.nox_script_getString_512E40(C.nox_script_pop()))
}

func nox_script_builtinGetF40() int { return int(C.dword_5d4594_3821636) }
func nox_script_builtinGetF44() int { return int(C.dword_5d4594_3821640) }

func noxScriptPopPointf() types.Pointf {
	y := noxScriptPopF32()
	x := noxScriptPopF32()
	return types.Pointf{X: x, Y: y}
}

//export nox_script_StartGame_516C20
func nox_script_StartGame_516C20() C.int {
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	return 0
}

//export nox_script_EndGame_516E10
func nox_script_EndGame_516E10() C.int {
	v := int(noxScriptPopI32())
	noxScriptEndGame(v)
	return 0
}

//export nox_script_UnBlind_515200
func nox_script_UnBlind_515200() C.int {
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	noxrend.FadeOutScreen(25, false, nil)
	return 0
}

//export nox_script_Blind_515220
func nox_script_Blind_515220() C.int {
	noxrend.FadeInScreen(25, false, fadeDisableGameDraw)
	return 0
}

//export nox_script_WideScreen_515240
func nox_script_WideScreen_515240() C.int {
	noxServer.CinemaPlayers(noxScriptPopI32() == 1)
	return 0
}

//export nox_script_StopAllFades_516C10
func nox_script_StopAllFades_516C10() C.int {
	nox_video_stopAllFades_44E040()
	return 0
}

func noxScriptEndGame(v int) {
	C.dword_587000_311372 = C.uint(v)
	*memmap.PtrUint8(0x5D4594, 2516476) |= 1 << v
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	sub_413960()
	sub_477530(false)
	nox_client_quit_4460C0()
}

//export sub_5165D0
func sub_5165D0() {
	*memmap.PtrUint32(0x5D4594, 2386828) = noxScriptPopU32() - 1
	sub_413A00(1)
	noxrend.FadeInScreen(25, true, func() {
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
		if noxrend.FadeOutCinema(perc, fadeOutDur, color.Black) {
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
	inFade := noxrend.CheckFade(noxrender.FadeInCinemaKey)
	if noxrend.FadeInCinema(perc, fadeInDur, color.Black) {
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
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_WALL, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_MANA_BOMB, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_LIGHTNING, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_CHAIN_LIGHTNING, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_DRAIN_MANA, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_FORCE_OF_NATURE, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_GREATER_HEAL, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_CHANNEL_LIFE, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_CHARM, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_BLINK, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_SWAP, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_TURN_UNDEAD, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_PLASMA, it)
			nox_xxx_spellCancelDurSpell_4FEB10(things.SPELL_SUMMON_BAT, it)
		}
	}
}

//export nox_script_Effect_514210
func nox_script_Effect_514210() C.int {
	pos2 := noxScriptPopPointf()
	pos := noxScriptPopPointf()
	name := "MSG_FX_" + strings.ToUpper(noxScriptPopString())
	dpos := image.Point{
		X: nox_script_builtinGetF40(),
		Y: nox_script_builtinGetF44(),
	}
	pos = pos.Add(types.Point2f(dpos))

	switch fx := noxScriptFXNames[name]; fx {
	case noxnet.MSG_FX_BLUE_SPARKS,
		noxnet.MSG_FX_YELLOW_SPARKS,
		noxnet.MSG_FX_CYAN_SPARKS,
		noxnet.MSG_FX_VIOLET_SPARKS,
		noxnet.MSG_FX_EXPLOSION,
		noxnet.MSG_FX_LESSER_EXPLOSION,
		noxnet.MSG_FX_COUNTERSPELL_EXPLOSION,
		noxnet.MSG_FX_THIN_EXPLOSION,
		noxnet.MSG_FX_TELEPORT,
		noxnet.MSG_FX_SMOKE_BLAST,
		noxnet.MSG_FX_DAMAGE_POOF,
		noxnet.MSG_FX_RICOCHET,
		noxnet.MSG_FX_WHITE_FLASH,
		noxnet.MSG_FX_TURN_UNDEAD,
		noxnet.MSG_FX_MANA_BOMB_CANCEL:
		nox_xxx_netSendPointFx_522FF0(fx, pos)
	case noxnet.MSG_FX_LIGHTNING,
		noxnet.MSG_FX_DRAIN_MANA,
		noxnet.MSG_FX_CHARM,
		noxnet.MSG_FX_GREATER_HEAL,
		noxnet.MSG_FX_DEATH_RAY,
		noxnet.MSG_FX_SENTRY_RAY:
		nox_xxx_netSendRayFx_5232F0(fx, dpos.Add(pos.Point()), dpos.Add(pos2.Point()))
	case noxnet.MSG_FX_SPARK_EXPLOSION:
		nox_xxx_netSparkExplosionFx_5231B0(pos, byte(pos2.X))
	case noxnet.MSG_FX_JIGGLE:
		nox_xxx_earthquakeSend_4D9110(pos, int(pos2.X))
	case noxnet.MSG_FX_GREEN_BOLT:
		// TODO: fix coordinates
		nox_xxx_netSendFxGreenBolt_523790(image.Point{}, image.Point{}, 30)
	case noxnet.MSG_FX_VAMPIRISM:
		nox_xxx_netSendVampFx_523270(fx, dpos.Add(pos.Point()), dpos.Add(pos2.Point()), 100)
	}
	return 0
}
