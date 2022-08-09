package opennox

/*
#include "server__script__script.h"
#include "server__script__internal.h"
#include "GAME4_1.h" // for nox_xxx_scriptPrepareFoundUnit_511D70 and nox_xxx_script_511C50
extern int nox_script_count_xxx_1599640;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern nox_script_xxx_t* nox_script_arr_xxx_1599636;
extern unsigned int dword_5d4594_3821636;
extern unsigned int dword_5d4594_3821640;
extern unsigned int nox_xxx_wallSounds_2386840;
int sub_516570();
int sub_43DA80();
void sub_43DAD0();
void sub_43D9B0(int a1, int a2);
int nox_xxx_destroyEveryChatMB_528D60();
*/
import "C"
import (
	"encoding/binary"
	"image"
	"image/color"
	"math"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	nox_script_objTelekinesisHand  int
	nox_script_objCinemaRemove     []int
	noxScriptFXNames               = make(map[string]noxnet.Op)
	nox_xxx_imagCasterUnit_1569664 *Unit
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
				s.scriptPushU32(it.arg)
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

func (s *Server) scriptPushU32(v uint32) {
	C.nox_script_push(C.int(v))
}

func (s *Server) scriptPushI32(v int32) {
	C.nox_script_push(C.int(v))
}

func (s *Server) scriptPushF32(v float32) {
	C.nox_script_push(C.int(math.Float32bits(v)))
}

func (s *Server) scriptPushBool(v bool) {
	C.nox_script_push(C.int(bool2int(v)))
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
	scripts := unsafe.Slice((*C.nox_script_xxx_t)(unsafe.Pointer(C.nox_script_arr_xxx_1599636)), int(C.nox_script_count_xxx_1599640))
	for i := range scripts {
		sc := &scripts[i]
		name := GoString(sc.field_0)
		if strings.HasPrefix(name, string(event)) {
			C.nox_script_callByIndex_507310(C.int(i), nil, nil)
		}
	}
}

//export nox_xxx_netGetUnitCodeServ_578AC0
func nox_xxx_netGetUnitCodeServ_578AC0(cobj *nox_object_t) C.uint {
	return C.uint(noxServer.nox_xxx_netGetUnitCodeServ(asObjectC(cobj)))
}

//export nox_server_scriptValToObjectPtr_511B60
func nox_server_scriptValToObjectPtr_511B60(val C.int) *C.nox_object_t {
	return noxServer.nox_server_scriptValToObjectPtr(int(val)).CObj()
}

func (s *Server) nox_xxx_netGetUnitCodeServ(p noxObject) int {
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

func (s *Server) noxScriptPopI32() int32 {
	return int32(C.nox_script_pop())
}

func (s *Server) noxScriptPopU32() uint32 {
	return uint32(C.nox_script_pop())
}

func (s *Server) noxScriptPopF32() float32 {
	return math.Float32frombits(uint32(C.nox_script_pop()))
}

func (s *Server) noxScriptPopBool() bool {
	return C.nox_script_pop() != 0
}

func (s *Server) noxScriptPopString() string {
	return GoString(C.nox_script_getString_512E40(C.nox_script_pop()))
}

func (s *Server) noxScriptPopObject() *Object {
	return s.nox_server_scriptValToObjectPtr(int(C.nox_script_pop()))
}

func nox_script_builtinGetF40() int { return int(C.dword_5d4594_3821636) }
func nox_script_builtinGetF44() int { return int(C.dword_5d4594_3821640) }

func (s *Server) noxScriptPopPointf() types.Pointf {
	y := s.noxScriptPopF32()
	x := s.noxScriptPopF32()
	return types.Pointf{X: x, Y: y}
}

//export nox_script_StartGame_516C20
func nox_script_StartGame_516C20() C.int {
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	return 0
}

//export nox_script_EndGame_516E10
func nox_script_EndGame_516E10() C.int {
	s := noxServer
	v := int(s.noxScriptPopI32())
	noxScriptEndGame(v)
	return 0
}

//export nox_script_UnBlind_515200
func nox_script_UnBlind_515200() C.int {
	C.nox_gameDisableMapDraw_5d4594_2650672 = 0
	noxClient.r.FadeOutScreen(25, false, nil)
	return 0
}

//export nox_script_Blind_515220
func nox_script_Blind_515220() C.int {
	noxClient.r.FadeInScreen(25, false, fadeDisableGameDraw)
	return 0
}

//export nox_script_WideScreen_515240
func nox_script_WideScreen_515240() C.int {
	s := noxServer
	s.CinemaPlayers(s.noxScriptPopI32() == 1)
	return 0
}

//export nox_script_StopAllFades_516C10
func nox_script_StopAllFades_516C10() C.int {
	nox_video_stopAllFades_44E040()
	return 0
}

func noxScriptEndGame(v int) {
	dword_587000_311372 = v
	dword_5d4594_2516476 |= 1 << v
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	sub_413960()
	sub_477530(false)
	nox_client_quit_4460C0()
}

//export sub_5165D0
func sub_5165D0() {
	s := noxServer
	*memmap.PtrUint32(0x5D4594, 2386828) = s.noxScriptPopU32() - 1
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

//export nox_script_Effect_514210
func nox_script_Effect_514210() C.int {
	s := noxServer
	pos2 := s.noxScriptPopPointf()
	pos := s.noxScriptPopPointf()
	name := "MSG_FX_" + strings.ToUpper(s.noxScriptPopString())
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
		noxnet.MSG_FX_ENERGY_BOLT,
		noxnet.MSG_FX_PLASMA,
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
		nox_xxx_netSendFxGreenBolt_523790(dpos.Add(pos.Point()), dpos.Add(pos2.Point()), 30)
	case noxnet.MSG_FX_VAMPIRISM:
		nox_xxx_netSendVampFx_523270(fx, dpos.Add(pos.Point()), dpos.Add(pos2.Point()), 100)
	}
	return 0
}

//export nox_script_ForceAutosave_516400
func nox_script_ForceAutosave_516400() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		sub_4DB130("AUTOSAVE")
		sub_4DB170(1, 0, 0)
	}
	return 0
}

//export nox_script_Music_516430
func nox_script_Music_516430() C.int {
	s := noxServer
	v0 := s.noxScriptPopU32()
	v3 := s.noxScriptPopU32()
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43D9B0(C.int(v3), C.int(v0))
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		buf[1] = byte(v3)
		buf[2] = byte(v0)
		s.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
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

//export nox_script_CastLocation2_515130
func nox_script_CastLocation2_515130() C.int {
	s := noxServer
	targPos := s.noxScriptPopPointf()
	srcPos := s.noxScriptPopPointf()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	nox_xxx_imagCasterUnit_1569664.SetPos(srcPos)
	nox_xxx_imagCasterUnit_1569664.direction1 = C.ushort(nox_xxx_math_509ED0(targPos.Sub(srcPos)))
	s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, nil, targPos)
	return 0
}

//export nox_script_CastLocationObject_515060
func nox_script_CastLocationObject_515060() C.int {
	s := noxServer
	targ := s.noxScriptPopObject()
	srcPos := s.noxScriptPopPointf()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	if targ == nil {
		return 0
	}
	nox_xxx_imagCasterUnit_1569664.SetPos(srcPos)
	nox_xxx_imagCasterUnit_1569664.direction1 = C.ushort(nox_xxx_math_509ED0(targ.Pos().Sub(srcPos)))
	s.castSpellBy(sp, nox_xxx_imagCasterUnit_1569664, targ, targ.Pos())
	return 0
}

//export nox_script_CastObject2_514F10
func nox_script_CastObject2_514F10() C.int {
	s := noxServer
	targID := s.noxScriptPopU32()
	caster := s.noxScriptPopObject().AsUnit()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	if caster == nil {
		return 0
	}
	if caster.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		return 0
	}
	targ := s.nox_server_scriptValToObjectPtr(int(targID))
	if targ == nil {
		return 0
	}
	caster.direction1 = C.ushort(nox_xxx_math_509ED0(targ.Pos().Sub(caster.Pos())))
	s.castSpellBy(sp, caster, targ, targ.Pos())
	return 0
}

//export nox_script_CastObjectLocation_514FC0
func nox_script_CastObjectLocation_514FC0() C.int {
	s := noxServer
	targPos := s.noxScriptPopPointf()
	caster := s.noxScriptPopObject().AsUnit()
	sp := spell.ParseID(s.noxScriptPopString())
	if !sp.Valid() {
		return 0
	}
	if caster == nil {
		return 0
	}
	caster.direction1 = C.ushort(nox_xxx_math_509ED0(targPos.Sub(caster.Pos())))
	s.castSpellBy(sp, caster, nil, targPos)
	return 0
}

//export nox_script_SetCallback_516970
func nox_script_SetCallback_516970() C.int {
	s := noxServer
	fnc := C.int(s.noxScriptPopU32())
	ev := s.noxScriptPopU32()
	u := s.noxScriptPopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassMonster) {
		return 0
	}
	ud := u.updateDataMonster()
	switch ev {
	case 3: // Enemy sighted
		ud.script_enemy_sighted_cb = fnc
	case 4: // Looking for enemy
		ud.script_looking_for_enemy_cb = fnc
	case 5: // Death
		ud.script_death_cb = fnc
	case 6: // Change focus
		ud.script_change_focus_cb = fnc
	case 7: // Is hit
		ud.script_is_hit_cb = fnc
	case 8: // Retreat
		ud.script_retreat_cb = fnc
	case 9: // Collision
		ud.script_collision_cb = fnc
	case 10: // Enemy heard
		ud.script_hear_enemy_cb = fnc
	case 11: // End of waypoint
		ud.script_end_of_waypoint_cb = fnc
	case 13: // Lost sight of enemy
		ud.script_lost_enemy_cb = fnc
	}
	return 0
}

//export nox_script_printToCaller_512B10
func nox_script_printToCaller_512B10() C.int {
	s := noxServer
	strID := s.noxScriptPopString()
	if c := asObject(C.nox_script_get_caller()).AsUnit(); c != nil && c.Class().Has(object.ClassPlayer) {
		str := s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
		nox_xxx_netSendLineMessage_4D9EB0(c, str)
	}
	return 0
}

//export nox_script_printToAll_512B60
func nox_script_printToAll_512B60() C.int {
	s := noxServer
	strID := s.noxScriptPopString()
	str := s.Strings().GetStringInFile(strman.ID(strID), "CScrFunc.c")
	PrintToPlayers(str)
	return 0
}

//export nox_script_ChangeScore_516E30
func nox_script_ChangeScore_516E30() C.int {
	s := noxServer
	val := int(s.noxScriptPopU32())
	u := s.noxScriptPopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassPlayer) {
		return 0
	}
	if val <= 0 {
		nox_xxx_playerSubLessons_4D8EC0(u, -val)
	} else {
		nox_xxx_changeScore_4D8E90(u, val)
	}

	if tm := s.teamByYyy(u.team()); tm != nil {
		s.teamChangeLessons(tm, val+int(tm.lessons))
	}
	nox_xxx_netReportLesson_4D8EF0(u)
	return 0
}

//export nox_script_GetScore_516EA0
func nox_script_GetScore_516EA0() C.int {
	s := noxServer
	u := s.noxScriptPopObject().AsUnit()
	if u == nil || !u.Class().Has(object.ClassPlayer) {
		s.scriptPushU32(0)
		return 0
	}
	pl := u.ControllingPlayer()
	s.scriptPushI32(int32(pl.lessons))
	return 0
}

//export nox_script_DeathScreen_516680
func nox_script_DeathScreen_516680() C.int {
	*memmap.PtrUint32(0x5D4594, 2386832) = 0
	sub_5165D0()
	return 0
}

//export nox_script_MusicPushEvent_5164A0
func nox_script_MusicPushEvent_5164A0() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DA80()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_PUSH_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

//export nox_script_MusicPopEvent_5164E0
func nox_script_MusicPopEvent_5164E0() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43DAD0()
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_POP_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

//export nox_script_ClearMusic_516520
func nox_script_ClearMusic_516520() C.int {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		C.sub_43D9B0(0, 0)
	} else {
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_MUSIC_EVENT)
		noxServer.nox_xxx_netSendPacket1_4E5390(255, buf[:3], 0, 1)
	}
	return 0
}

//export nox_script_Frozen_516920
func nox_script_Frozen_516920() C.int {
	s := noxServer
	val := s.noxScriptPopBool()
	if u := s.noxScriptPopObject().AsUnit(); u != nil {
		u.Freeze(val)
	}
	return 0
}

//export nox_script_NoWallSound_516960
func nox_script_NoWallSound_516960() C.int {
	s := noxServer
	C.nox_xxx_wallSounds_2386840 = C.uint(s.noxScriptPopU32())
	return 0
}

//export nox_script_ClearMessages_516BC0
func nox_script_ClearMessages_516BC0() C.int {
	s := noxServer
	if u := s.noxScriptPopObject().AsUnit(); u != nil {
		nox_xxx_netScriptMessageKill_4D9760(u)
	}
	return 0
}

//export nox_script_IsAttackedBy_5161C0
func nox_script_IsAttackedBy_5161C0() C.int {
	s := noxServer
	obj2 := s.noxScriptPopObject()
	obj1 := s.noxScriptPopObject()
	val := obj1 != nil && obj2 != nil && obj1.isEnemyTo(obj2)
	s.scriptPushBool(val)
	return 0
}

//export nox_script_Pop2_74_514BA0
func nox_script_Pop2_74_514BA0() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_RemoveChat_514BB0
func nox_script_RemoveChat_514BB0() C.int {
	s := noxServer
	if u := s.noxScriptPopObject().AsUnit(); u != nil {
		nox_xxx_netKillChat_528D00(u)
	}
	return 0
}

//export nox_script_NoChatAll_514BD0
func nox_script_NoChatAll_514BD0() C.int {
	C.nox_xxx_destroyEveryChatMB_528D60()
	return 0
}

//export nox_script_CancelTimer_5141F0
func nox_script_CancelTimer_5141F0() C.int {
	s := noxServer
	act := s.noxScriptPopU32()
	ok := s.nox_script_activatorCancel(act)
	s.scriptPushBool(ok)
	return 0
}

//export nox_script_fn58_513F10
func nox_script_fn58_513F10() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_fn59_513F20
func nox_script_fn59_513F20() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_fn5A_513F30
func nox_script_fn5A_513F30() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_fn5B_513F40
func nox_script_fn5B_513F40() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_Fn5C_513F50
func nox_script_Fn5C_513F50() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_Fn5D_513F60
func nox_script_Fn5D_513F60() C.int {
	s := noxServer
	s.noxScriptPopU32()
	s.noxScriptPopU32()
	return 0
}

//export nox_script_builtin_513C60
func nox_script_builtin_513C60() C.int { return 0 }

//export nox_script_randomFloat_512D70
func nox_script_randomFloat_512D70() C.int {
	s := noxServer
	max := float64(s.noxScriptPopF32())
	min := float64(s.noxScriptPopF32())
	val := noxRndCounter1.FloatClamp(min, max)
	s.scriptPushF32(float32(val))
	return 0
}

//export nox_script_randomInt_512DB0
func nox_script_randomInt_512DB0() C.int {
	s := noxServer
	max := int(s.noxScriptPopU32())
	min := int(s.noxScriptPopU32())
	val := noxRndCounter1.IntClamp(min, max)
	s.scriptPushI32(int32(val))
	return 0
}

//export nox_script_timerSecSpecial_512DE0
func nox_script_timerSecSpecial_512DE0() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	arg := s.noxScriptPopU32()
	dt := s.noxScriptPopU32()
	s.scriptPushU32(s.newScriptTimer(int(dt*gameFPS()), fnc, arg))
	return 0
}

//export nox_script_specialTimer_512E10
func nox_script_specialTimer_512E10() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	arg := s.noxScriptPopU32()
	df := int(s.noxScriptPopU32())
	s.scriptPushU32(s.newScriptTimer(df, fnc, arg))
	return 0
}

//export nox_script_returnOne_512C10
func nox_script_returnOne_512C10() C.int { return 1 }

//export nox_script_getObject2_5129C0
func nox_script_getObject2_5129C0() C.int {
	s := noxServer
	_ = s.noxScriptPopObject()
	return 0
}

//export nox_script_getObject3_5129E0
func nox_script_getObject3_5129E0() C.int {
	s := noxServer
	_ = s.noxScriptPopObject()
	return 0
}

//export nox_script_deleteObject_5128B0
func nox_script_deleteObject_5128B0() C.int {
	s := noxServer
	if obj := s.noxScriptPopObject(); obj != nil {
		obj.Delete()
	}
	return 0
}

//export nox_script_secondTimer_512320
func nox_script_secondTimer_512320() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	dt := s.noxScriptPopU32()
	s.scriptPushU32(s.newScriptTimer(int(dt*gameFPS()), fnc, 0))
	return 0
}

//export nox_script_frameTimer_512350
func nox_script_frameTimer_512350() C.int {
	s := noxServer
	fnc := s.noxScriptPopU32()
	df := int(s.noxScriptPopU32())
	s.scriptPushU32(s.newScriptTimer(df, fnc, 0))
	return 0
}
