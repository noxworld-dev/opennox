package opennox

import (
	"errors"
	"fmt"
	"image"
	"image/color"
	"io"
	"math"
	"os"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/noxscript/ns/asm"
	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/noxscript"
)

func nox_script_indexByEvent(name string) int {
	return noxServer.noxScript.scriptIndexByName(name)
}

func nox_script_getString_512E40(i int) (string, bool) {
	s := &noxServer.noxScript
	if i < 0 || i >= len(s.vm.strings) {
		return "", false
	}
	return s.vm.strings[i], true
}

func nox_script_callbackName(h int) string {
	return noxServer.noxScript.scriptNameByIndex(h)
}

func nox_server_mapRWScriptData_504F90(cf *cryptfile.CryptFile, _ unsafe.Pointer) error {
	if cf.ReadOnly() {
		return nox_server_mapRWScriptData_504F90_Read(cf)
	}
	return nox_server_mapRWScriptData_504F90_Write(cf)
}

func nox_server_mapRWScriptData_504F90_Read(cf *cryptfile.CryptFile) error {
	s := noxServer
	if vers, err := cf.ReadU16(); err != nil {
		return err
	} else if vers > 1 {
		return fmt.Errorf("unsupported script data vers: %v", vers)
	}
	if has, err := cf.ReadU8(); err != nil {
		return err
	} else if has == 0 {
		return nil
	}
	funcs := s.noxScript.Funcs()
	vars := funcs[1].Locals()
	for i := range vars {
		v, err := cf.ReadU32()
		if err != nil {
			return err
		}
		vars[i] = v
	}
	return s.LoadActivators(cf)
}

func nox_server_mapRWScriptData_504F90_Write(cf *cryptfile.CryptFile) error {
	s := noxServer
	funcs := s.noxScript.Funcs()
	cf.WriteU16(1)
	has := byte(0)
	if len(funcs) != 0 && noxflags.HasGame(noxflags.GameHost) && !noxflags.HasGame(noxflags.GameFlag23) {
		has = 1
	}
	cf.WriteU8(has)
	if has == 0 {
		return nil
	}
	vars := funcs[1].Locals()
	for _, v := range vars {
		cf.WriteU32(v)
	}
	return s.SaveActivators(cf)
}

func nox_script_objCallbackName_508CB0(obj *server.Object, event int) (string, bool) {
	s := noxServer
	sd := obj.Field189
	if sd == nil {
		return "", false
	}
	funcs := s.noxScript.Funcs()
	switch event {
	case 14:
		if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
			return alloc.GoString((*byte)(sd)), true
		}
		return funcs[obj.Field192].Name(), true
	}
	cl := obj.Class()
	switch {
	default:
		return "", false
	case cl.Has(object.ClassTrigger):
		ud := unsafe.Slice((*uint32)(obj.UpdateData), 9)
		switch event {
		case 0:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 512))), true
			}
			return funcs[ud[4]].Name(), true
		case 1:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 256))), true
			}
			return funcs[ud[6]].Name(), true
		case 2:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 384))), true
			}
			return funcs[ud[8]].Name(), true
		}
		return "", false
	case cl.Has(object.ClassMonster):
		ud := obj.UpdateDataMonster()
		switch ns4.ObjectEvent(event) {
		case ns4.EventEnemySighted:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 640))), true
			}
			return funcs[ud.ScriptEnemySighted.Func].Name(), true
		case ns4.EventLookingForEnemy:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 768))), true
			}
			return funcs[ud.ScriptLookingForEnemy.Func].Name(), true
		case ns4.EventDeath:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 896))), true
			}
			return funcs[ud.ScriptDeath.Func].Name(), true
		case ns4.EventChangeFocus:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1024))), true
			}
			return funcs[ud.ScriptChangeFocus.Func].Name(), true
		case ns4.EventIsHit:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1152))), true
			}
			return funcs[ud.ScriptIsHit.Func].Name(), true
		case ns4.EventRetreat:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1280))), true
			}
			return funcs[ud.ScriptRetreat.Func].Name(), true
		case ns4.EventCollision:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1408))), true
			}
			return funcs[ud.ScriptCollision.Func].Name(), true
		case ns4.EventEnemyHeard:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1536))), true
			}
			return funcs[ud.ScriptHearEnemy.Func].Name(), true
		case ns4.EventEndOfWaypoint:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1664))), true
			}
			return funcs[ud.ScriptEndOfWaypoint.Func].Name(), true
		case ns4.EventLostEnemy:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1792))), true
			}
			return funcs[ud.ScriptLostEnemy.Func].Name(), true
		}
		return "", false
	case cl.Has(object.ClassHole):
		switch event {
		case 12:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 128))), true
			}
			cd := obj.CollideData
			ind := *(*uint32)(unsafe.Add(cd, 4))
			return funcs[ind].Name(), true
		}
		return "", false
	case cl.Has(object.ClassMonsterGenerator):
		ud := unsafe.Slice((*uint32)(obj.UpdateData), 20)
		switch event {
		case 15:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 1920))), true
			}
			return funcs[ud[13]].Name(), true
		case 16:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 2048))), true
			}
			return funcs[ud[15]].Name(), true
		case 17:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 2304))), true
			}
			return funcs[ud[17]].Name(), true
		case 18:
			if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
				return alloc.GoString((*byte)(unsafe.Add(sd, 2176))), true
			}
			return funcs[ud[19]].Name(), true
		}
		return "", false
	}
}

func (s *noxScript) ReadScript(r io.Reader) error {
	scr, err := asm.ReadScript(r)
	if err != nil {
		return err
	}
	s.vm.strings = scr.Strings
	s.vm.funcs = nil
	if len(scr.Funcs) != 0 {
		s.vm.funcs = make([]ScriptFunc, 0, len(scr.Funcs))
	}
	for _, fnc := range scr.Funcs {
		cur := ScriptFunc{FuncDef: fnc}
		if len(fnc.Name) >= 1024 {
			return fmt.Errorf("function name too long: %d", len(fnc.Name))
		}
		if fnc.VarsSz != 0 {
			cur.Values = make([]uint32, fnc.VarsSz)
		}
		s.vm.funcs = append(s.vm.funcs, cur)
	}
	return nil
}

func sub_511E60() {
	if legacy.Get_dword_5d4594_2386836() == 0 {
		legacy.Set_dword_5d4594_2386836(noxServer.Types.IndByID("Mover"))
	}
	noxServer.noxScript.Reset()
	noxServer.Activators.CancelAll()
	*memmap.PtrUint32(0x5D4594, 2386844) = 0
	legacy.Set_dword_5d4594_2386848(0)
	legacy.Set_dword_5d4594_2386852(0)
}

func (s *noxScript) Reset() {
	for i := range s.vm.strings {
		s.vm.strings[i] = ""
	}
	s.vm.strings = s.vm.strings[:0]
	legacy.Set_dword_5d4594_1599628(0)
	s.vm.funcs = nil
}

var (
	nox_script_objTelekinesisHand  int
	nox_script_objCinemaRemove     []int
	nox_xxx_imagCasterUnit_1569664 *Object
)

var _ noxscript.VM = (*noxScript)(nil)

type nsCallback struct {
	Name string
	Fnc  func() error
}

type noxScript struct {
	s  *Server
	vm struct {
		strings   []string
		funcs     []ScriptFunc
		stack     []uint32
		dpos      image.Point // pos delta added when calling builtins
		nameSuff  string      // name suffix added when calling builtins
		caller    *server.Object
		trigger   *server.Object
		callbacks []noxScriptCallback
	}
	timers  script.Timers
	virtual struct {
		last  int
		funcs map[int]nsCallback
	}
	panic noxScriptPanic
}

func (s *noxScript) Init(srv *Server) {
	s.s = srv
	s.resetVirtualFuncs()
}

func (s *noxScript) resetVirtualFuncs() {
	s.virtual.last = math.MaxInt32
	s.virtual.funcs = make(map[int]nsCallback)
}

func (s *noxScript) FuncsCnt() int {
	return len(s.vm.funcs)
}

func (s *noxScript) Funcs() []ScriptFunc {
	return s.vm.funcs
}

func (s *noxScript) AsValue(val any) uint32 {
	switch val := val.(type) {
	case nil:
		return 0
	case bool:
		if val {
			return 1
		}
		return 0
	case int:
		return uint32(int32(val))
	case int32:
		return uint32(val)
	case uint32:
		return val
	case float32:
		return math.Float32bits(val)
	case ns4.Handle:
		return uint32(val.ScriptID())
	}
	panic(fmt.Errorf("unsupported type: %T", val))
}

func (s *noxScript) AsFuncIndex(defname string, fnc ns4.Func) int {
	switch fnc := fnc.(type) {
	case nil:
		return -1
	case int:
		if fnc < 0 || fnc >= s.FuncsCnt() {
			return -1
		}
		return fnc
	case string:
		return s.scriptIndexByName(fnc)
	case func():
		return s.addVirtual(defname, func() (gerr error) {
			defer func() {
				if r := recover(); r != nil {
					if e, ok := r.(error); ok {
						gerr = e
					} else {
						gerr = fmt.Errorf("panic in %s: %v", defname, r)
					}
				}
			}()
			fnc()
			return nil
		})
	default:
		panic(fmt.Errorf("unsupported function type: %T", fnc))
	}
}

type ScriptFunc struct {
	asm.FuncDef
	Values []uint32
}

func (s *ScriptFunc) Name() string {
	return s.FuncDef.Name
}

func (s *ScriptFunc) Args() []uint32 {
	sz := s.FuncDef.Args
	if sz == 0 {
		return nil
	}
	return s.Values[:sz]
}

func (s *ScriptFunc) Locals() []uint32 {
	return s.Values
}

// addVirtual assigns a virtual function index for NoxScript.
func (s *noxScript) addVirtual(name string, fnc func() error) int {
	// Are we conflicting with the original NoxScript func indexes?
	if s.virtual.last-1 <= s.FuncsCnt() {
		panic("no more space for virtual script func handles")
	}
	id := s.virtual.last
	s.virtual.last--
	s.virtual.funcs[id] = nsCallback{Name: name, Fnc: fnc}
	return id
}

// scriptIndexByName looks up NoxScript function ID (handle).
// It returns -1 if the function was not found.
//
// Originally only compiled NoxScript from the map was considered,
// in which case returned handle is just an index into the functions slice.
//
// Since new runtimes were introduced, this function will now return "virtual"
// function indexes, which are set really large to avoid collisions, for functions
// from the new runtimes. CallByIndex and ScriptCallback will recognize them later.
func (s *noxScript) scriptIndexByName(name string) int {
	// Prefer map scripts from new script runtimes.
	for _, vm := range s.s.vms.vms {
		fnc, err := script.GetVMSymbol[func()](vm, name)
		if err != nil {
			// Pretend we found it, but return an error on all calls instead.
			return s.addVirtual(name, func() error {
				return err
			})
		}
		if fnc != nil {
			// Found, returning virtual handle.
			return s.addVirtual(name, func() error {
				fnc()
				return nil
			})
		}
	}
	for i, f := range s.vm.funcs {
		if f.Name() == name {
			return i
		}
	}
	return -1
}

func (s *noxScript) scriptNameByIndex(h int) string {
	if cb, ok := s.virtual.funcs[h]; ok {
		return cb.Name
	}
	return s.Funcs()[h].Name()
}

func (s *noxScript) Caller() *server.Object {
	return s.vm.caller
}

func (s *noxScript) Trigger() *server.Object {
	return s.vm.trigger
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
	if v {
		s.vm.stack = append(s.vm.stack, 1)
	} else {
		s.vm.stack = append(s.vm.stack, 0)
	}
}

func (s *noxScript) AddString(str string) uint32 {
	i := len(s.vm.strings)
	s.vm.strings = append(s.vm.strings, str)
	return uint32(i)
}

func (s *noxScript) PushString(str string) {
	s.vm.stack = append(s.vm.stack, s.AddString(str))
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

func (s *noxScript) GetString(i uint32) string {
	if i < 0 || i >= uint32(len(s.vm.strings)) {
		return ""
	}
	return s.vm.strings[i]
}

func (s *noxScript) PopString() string {
	return s.GetString(s.PopU32())
}

func (s *noxScript) PopPoint() image.Point {
	y := s.PopI32()
	x := s.PopI32()
	return image.Point{X: int(x), Y: int(y)}
}

func (s *noxScript) PopPointf() types.Pointf {
	y := s.PopF32()
	x := s.PopF32()
	return types.Pointf{X: x, Y: y}
}

func (s *noxScript) PopObject() *server.Object {
	return s.ScriptToObject(int(s.PopI32()))
}

func (s *noxScript) PopGroup() *server.MapGroup {
	return s.s.MapGroups.GroupByInd(int(s.PopI32()))
}

func (s *noxScript) nox_xxx_scriptRunFirst_507290() {
	s.resetBuiltin()
	if scripts := s.Funcs(); len(scripts) >= 2 {
		sc := scripts[1].Values
		tv := int32(-2)
		sc[0] = uint32(tv)
		tv = int32(-1)
		sc[1] = uint32(tv)
		sc[2] = 1
		sc[3] = 0
		if !nox_xxx_gameIsSwitchToSolo_4DB240() {
			if err := s.CallByIndex(1, nil, nil); err != nil {
				scriptLog.Println(err)
			}
		}
	} else {
		scriptLog.Printf("noxscript: no init function")
	}
}

func (s *noxScript) OnEvent(event script.EventType) {
	scripts := s.Funcs()
	for i := range scripts {
		sc := &scripts[i]
		name := sc.Name()
		if strings.HasPrefix(name, string(event)) {
			if err := s.CallByIndex(i, nil, nil); err != nil {
				scriptLog.Println(err)
			}
		}
	}
}

func (s *Server) GetUnitNetCode(p server.Obj) int {
	obj := toObject(p)
	if obj == nil {
		return 0
	}
	if obj.NetCode >= 0x8000 {
		return 0
	}
	ext := int(obj.Extent)
	if ext >= 0x8000 {
		return 0
	}
	if !obj.Class().HasAny(object.ClassClientPersist | object.ClassImmobile) {
		return int(obj.NetCode)
	}
	ext |= 0x8000
	return ext
}

func (s *noxScript) ScriptToObject(val int) *server.Object {
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
	if obj := legacy.Nox_xxx_script_511C50(val); obj != nil {
		return obj
	}

	for obj := s.s.Objs.List; obj != nil; obj = obj.Next() {
		if !obj.Flags().Has(object.FlagDestroyed) && obj.ScriptIDVal == val {
			legacy.Nox_xxx_scriptPrepareFoundUnit_511D70(obj)
			return obj
		}
		for sub := obj.FirstItem(); sub != nil; sub = sub.NextItem() {
			if !sub.Flags().Has(object.FlagDestroyed) && sub.ScriptIDVal == val {
				legacy.Nox_xxx_scriptPrepareFoundUnit_511D70(sub)
				return sub
			}
		}
	}
	for obj := s.s.Objs.Pending; obj != nil; obj = obj.Next() {
		if !obj.Flags().Has(object.FlagDestroyed) && obj.ScriptIDVal == val {
			legacy.Nox_xxx_scriptPrepareFoundUnit_511D70(obj)
			return obj
		}
	}
	return nil
}

func (s *noxScript) resetBuiltin() {
	s.vm.dpos = image.Point{}
	s.vm.nameSuff = ""
}

func (s *noxScript) NameSuff() string {
	return s.vm.nameSuff
}

func (s *noxScript) DPos() image.Point {
	return s.vm.dpos
}

func (s *noxScript) DPosf() types.Pointf {
	return types.Point2f(s.vm.dpos)
}

func noxScriptEndGame(v int) {
	dword_587000_311372 = v
	dword_5d4594_2516476 |= 1 << v
	nox_xxx_cliPlayMapIntro_44E0B0(1)
	sub_413960()
	sub_477530(false)
	nox_client_quit_4460C0()
}

func noxScriptStartupScreen(v int) {
	legacy.Nox_script_StartupScreen_516600_A()
	sub5165D0(v)
}

func sub5165D0(which int) {
	*memmap.PtrUint32(0x5D4594, 2386828) = uint32(which - 1)
	sub_413A00(1)
	noxClient.r.FadeInScreen(25, true, func() {
		legacy.Sub_516570()
	})
}

func (s *Server) CinemaPlayers(enable bool) {
	if nox_script_objTelekinesisHand == 0 {
		nox_script_objTelekinesisHand = s.Types.IndByID("TelekinesisHand")
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
		for it := s.FirstServerObject(); it != nil; it = it.Next() {
			if int(it.TypeInd) == nox_script_objTelekinesisHand {
				if f := it.Flags(); f.Has(object.FlagNoCollide) {
					it.ObjFlags = uint32(f &^ object.FlagNoCollide)
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
			nox_script_objCinemaRemove = append(nox_script_objCinemaRemove, s.Types.IndByID(name))
		}
	}

	var next *server.Object
	for it := s.Objs.UpdatableList2; it != nil; it = next {
		next = it.Next()
		if int(it.TypeInd) != int(memmap.Uint32(0x5D4594, 2386900)) {
			asObjectS(it).Delete()
		}
	}

	next = nil
	for it := s.FirstServerObject(); it != nil; it = next {
		next = it.Next()
		if asObjectS(it).OwnerC() != nil {
			for _, id := range nox_script_objCinemaRemove {
				if int(it.TypeInd) == id {
					asObjectS(it).Delete()
					break
				}
			}
		} else {
			if int(it.TypeInd) == nox_script_objTelekinesisHand {
				if f := it.Flags(); !f.Has(object.FlagNoCollide) {
					it.ObjFlags = uint32(f | object.FlagNoCollide)
				}
			}
			s.spells.duration.CancelFor(spell.SPELL_WALL, it)
			s.spells.duration.CancelFor(spell.SPELL_MANA_BOMB, it)
			s.spells.duration.CancelFor(spell.SPELL_LIGHTNING, it)
			s.spells.duration.CancelFor(spell.SPELL_CHAIN_LIGHTNING, it)
			s.spells.duration.CancelFor(spell.SPELL_DRAIN_MANA, it)
			s.spells.duration.CancelFor(spell.SPELL_FORCE_OF_NATURE, it)
			s.spells.duration.CancelFor(spell.SPELL_GREATER_HEAL, it)
			s.spells.duration.CancelFor(spell.SPELL_CHANNEL_LIFE, it)
			s.spells.duration.CancelFor(spell.SPELL_CHARM, it)
			s.spells.duration.CancelFor(spell.SPELL_BLINK, it)
			s.spells.duration.CancelFor(spell.SPELL_SWAP, it)
			s.spells.duration.CancelFor(spell.SPELL_TURN_UNDEAD, it)
			s.spells.duration.CancelFor(spell.SPELL_PLASMA, it)
			s.spells.duration.CancelFor(spell.SPELL_SUMMON_BAT, it)
		}
	}
}

func nox_setImaginaryCaster() int {
	s := noxServer
	nox_xxx_imagCasterUnit_1569664 = asObjectS(s.NewObjectByTypeID("ImaginaryCaster"))
	if nox_xxx_imagCasterUnit_1569664 == nil {
		return 0
	}
	s.CreateObjectAt(nox_xxx_imagCasterUnit_1569664, nil, types.Pointf{X: 128 * common.GridStep, Y: 128 * common.GridStep})
	return 1
}

func nox_script_readWriteZzz_541670(cpath, cpath2, cdst *byte) int {
	if cpath == nil {
		return 0
	}
	if cpath2 == nil {
		return 0
	}
	if cdst == nil {
		return 0
	}
	path, path2, dst := alloc.GoString(cpath), alloc.GoString(cpath2), alloc.GoString(cdst)
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

	v6, _ := binfile.FileSize(f1)
	if v6 == 0 {
		ifs.Remove(dst)
		ifs.Rename(path2, dst)
		return 1
	}

	v7, _ := binfile.FileSize(f2)
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
	legacy.Nox_script_readWriteWww_5417C0(binfile.NewFile(f1), binfile.NewFile(f2), binfile.NewFile(df))
	return 1
}

func (s *noxScript) actRun() {
	scripts := s.Funcs()
	s.s.Activators.EachTriggered(s.s.Frame(), func(it server.ActivatorArgs) {
		// TODO: support arguments for virtual funcs
		if it.Callback < len(scripts) && scripts[it.Callback].FuncDef.Args != 0 {
			s.PushU32(it.Arg)
		}
		if err := s.CallByIndex(it.Callback, it.Caller, it.Trigger); err != nil {
			scriptLog.Println(err)
		}
	})
}

func (s *noxScript) ActResolveObjs() {
	s.s.Activators.ResolveObjs(func(id int) *server.Object {
		return s.ScriptToObject(id).SObj()
	})
}

func (s *noxScript) NoxScript() ns4.Implementation {
	return s.s.NoxScript()
}

func (s *noxScript) PopWallGroupNS() ns4.WallGroupObj {
	g := s.PopGroup()
	if g == nil || mapGroupType(g) != server.MapGroupWalls {
		return nil
	}
	return nsWallGroup{s.s, g}
}

func (s *noxScript) PopWaypointNS() ns4.WaypointObj {
	wp := s.s.getWaypointByInd(int(s.PopI32()))
	if wp == nil {
		return nil
	}
	return wp
}

func (s *noxScript) PopWpGroupNS() ns4.WaypointGroupObj {
	g := s.PopGroup()
	if g == nil || mapGroupType(g) != server.MapGroupWaypoints {
		return nil
	}
	return nsWpGroup{s.s, g}
}

func (s *noxScript) PopObjectNS() ns4.Obj {
	obj := s.ScriptToObject(int(s.PopI32()))
	if obj == nil {
		return nil
	}
	return nsObj{s.s, asObjectS(obj)}
}

func (s *noxScript) PopObjGroupNS() ns4.ObjGroup {
	g := s.PopGroup()
	if g == nil || mapGroupType(g) != server.MapGroupObjects {
		return nil
	}
	return nsObjGroup{s.s, g}
}

func (s *noxScript) PushHandleNS(obj ns4.Handle) {
	if obj == nil {
		s.PushI32(0)
	} else {
		s.PushI32(int32(obj.ScriptID()))
	}
}

type noxScriptCallback struct {
	Block   *server.ScriptCallback
	Caller  *server.Object
	Trigger *server.Object
}

func (s *noxScript) scriptPushCallback(b *server.ScriptCallback, caller, trigger *server.Object) {
	s.vm.callbacks = append(s.vm.callbacks, noxScriptCallback{
		Block: b, Caller: caller, Trigger: trigger,
	})
}

func (s *noxScript) scriptPopCallback(b *server.ScriptCallback, caller, trigger *server.Object) {
	for i := 0; i < len(s.vm.callbacks); i++ {
		it := &s.vm.callbacks[i]
		if it.Block == b && it.Caller == caller && it.Trigger == trigger {
			s.vm.callbacks = append(s.vm.callbacks[:i], s.vm.callbacks[i+1:]...)
		}
	}
}

func (s *noxScript) ScriptCallback(b *server.ScriptCallback, caller, trigger *server.Object, eventCode server.ScriptEventType) unsafe.Pointer {
	s.scriptCallByEvent(eventCode, asObjectS(caller), asObjectS(trigger))
	*memmap.PtrUint32(0x5D4594, 1599076) = 0
	flags := b.Flags
	if flags&0x1 != 0 {
		return nil
	}
	sind := int(b.Func)
	if cb, ok := s.virtual.funcs[sind]; ok && cb.Fnc != nil {
		s.vm.caller = caller
		s.vm.trigger = trigger
		if err := cb.Fnc(); err != nil {
			scriptLog.Printf("ScriptCallback: %s: %v", cb.Name, err)
		}
		*memmap.PtrUint32(0x5D4594, 1599076) = 0
		return memmap.PtrOff(0x5D4594, 1599076)
	}
	if sind == -1 {
		return nil
	}
	if flags&0x2 != 0 {
		b.Flags |= 0x1
	}
	if s.saveStack() != 0 {
		s.scriptPushCallback(b, caller, trigger)
		return memmap.PtrOff(0x5D4594, 1599076)
	}
	if err := s.CallByIndex(sind, caller, trigger); err != nil {
		scriptLog.Println(err)
	}
	scripts := s.Funcs()
	if scripts[sind].Return != 0 {
		*memmap.PtrUint32(0x5D4594, 1599076) = s.PopU32()
	}
	s.resetStack()
	// TODO: Previously, the code was tracking how many temp strings were added,
	//       and removed them here. Instead, we can do interning + GC to achieve the same effect.
	s.scriptPopCallback(b, caller, trigger)
	if len(s.vm.callbacks) > 0 {
		s.ScriptCallback(s.vm.callbacks[0].Block, s.vm.callbacks[0].Caller, s.vm.callbacks[0].Trigger, 0)
	}
	return memmap.PtrOff(0x5D4594, 1599076)
}

func (s *noxScript) CallByIndex(index int, caller, trigger *server.Object) error {
	if cb, ok := s.virtual.funcs[index]; ok && cb.Fnc != nil {
		s.vm.caller = caller
		s.vm.trigger = trigger
		return cb.Fnc()
	}
	if len(s.vm.funcs) == 0 {
		return errors.New("no map script functions")
	}
	scripts := s.Funcs()
	if index < 0 || index >= len(scripts) {
		return fmt.Errorf("invalid function index: %d (%x)", index, index)
	}
	sc := scripts[index]

	s.vm.caller = caller
	s.vm.trigger = trigger

	args := sc.Args()
	for i := range args {
		args[i] = s.PopU32()
	}
	bstack := s.saveStack()
	code := sc.Code
	readUint := func() uint32 {
		v := code[0]
		code = code[1:]
		return v
	}
	readInt := func() int32 {
		return int32(readUint())
	}
	readFloat := func() float32 {
		return math.Float32frombits(readUint())
	}
	// TODO: varOffPtr and varPtr are very similar; maybe they are the same, and it's a bug?
	varOffPtr := func(isGlobal bool, vari int32) *uint32 {
		if isGlobal {
			if len(scripts[1].Vars) != 0 && len(scripts[1].Values) != 0 {
				off := scripts[1].Vars[vari].Offs
				return &scripts[1].Values[off]
			}
		} else if vari < 0 {
			off := scripts[1].Vars[-vari].Offs
			return trigger.ScriptVarPtr(off)
		} else if len(sc.Vars) != 0 && len(sc.Values) != 0 {
			off := sc.Vars[vari].Offs
			return &sc.Values[off]
		}
		return nil
	}
	varPtr := func(isGlobal bool, vari int32) *uint32 {
		if isGlobal {
			if len(scripts[1].Values) != 0 {
				return &scripts[1].Values[vari]
			}
		} else if vari < 0 {
			return trigger.ScriptVarPtr(int(-vari))
		} else if len(sc.Values) != 0 {
			return &sc.Values[vari]
		}
		return nil
	}
	varIndPtr := func(isGlobal bool, vari int32, i int32) *uint32 {
		if isGlobal {
			if len(scripts[1].Values) != 0 {
				return &scripts[1].Values[vari+i]
			}
		} else if vari < 0 {
			return trigger.ScriptVarPtr(int(vari - i))
		} else if len(sc.Values) != 0 {
			return &sc.Values[vari+i]
		}
		return nil
	}
	for {
		op := asm.Op(readUint())
		switch op {
		case asm.OpLoadVarInt, asm.OpLoadVarString:
			isGlobal := readInt() != 0
			vari := readInt()
			ptr := varOffPtr(isGlobal, vari)
			if ptr != nil {
				s.PushI32(int32(*ptr))
			} else {
				s.PushI32(0)
			}
			continue
		case asm.OpLoadVarFloat:
			isGlobal := readInt() != 0
			vari := readInt()
			ptr := varOffPtr(isGlobal, vari)
			if ptr != nil {
				s.PushF32(math.Float32frombits(*ptr))
			} else {
				s.PushF32(0)
			}
			continue
		case asm.OpLoadVarPtr:
			isGlobal := readInt() != 0
			vari := readInt()
			var sz, off int32
			if isGlobal {
				def := &scripts[1].Vars[vari]
				sz = int32(def.Size)
				off = int32(def.Offs)
			} else if vari < 0 {
				def := &scripts[1].Vars[-vari]
				sz = int32(def.Size)
				off = int32(-def.Offs) // TODO: this doesn't look right
			} else if len(sc.Vars) != 0 {
				def := &sc.Vars[vari]
				sz = int32(def.Size)
				off = int32(def.Offs)
			} else {
				sz = 0
				off = 0
			}
			if sz > 1 {
				s.PushI32(sz)
			}
			s.PushBool(isGlobal)
			s.PushI32(off)
			continue
		case asm.OpPushInt, asm.OpPushString:
			v := readInt()
			s.PushI32(v)
			continue
		case asm.OpPushFloat:
			v := readFloat()
			s.PushF32(v)
			continue
		case asm.OpIntAdd:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs + rhs)
			continue
		case asm.OpFloatAdd:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs + rhs)
			continue
		case asm.OpIntSub:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs - rhs)
			continue
		case asm.OpFloatSub:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs - rhs)
			continue
		case asm.OpIntMul:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs * rhs)
			continue
		case asm.OpFloatMul:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs * rhs)
			continue
		case asm.OpIntDiv:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs / rhs)
			continue
		case asm.OpFloatDiv:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushF32(lhs / rhs)
			continue
		case asm.OpIntMod:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs % rhs)
			continue
		case asm.OpIntAnd:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs & rhs)
			continue
		case asm.OpIntOr:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs | rhs)
			continue
		case asm.OpIntXOr:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs ^ rhs)
			continue
		case asm.OpJump:
			jmpi := readInt()
			code = sc.Code[jmpi:]
			continue
		case asm.OpJumpIf:
			jmpi := readInt()
			if s.PopBool() {
				code = sc.Code[jmpi:]
			}
			continue
		case asm.OpJumpIfNot:
			jmpi := readInt()
			if !s.PopBool() {
				code = sc.Code[jmpi:]
			}
			continue
		case asm.OpStoreInt, asm.OpStoreString:
			rhs := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				*ptr = uint32(rhs)
			}
			s.PushI32(rhs)
			continue
		case asm.OpStoreFloat:
			val := s.PopF32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				*ptr = math.Float32bits(val)
			}
			s.PushF32(val)
			continue
		case asm.OpStoreIntMul, asm.OpStoreIntDiv, asm.OpStoreIntAdd, asm.OpStoreIntSub, asm.OpStoreIntMod,
			asm.OpStoreIntLSh, asm.OpStoreIntRSh, asm.OpStoreIntAnd, asm.OpStoreIntOr, asm.OpStoreIntXOr:
			rhs := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				lhs := int32(*ptr)
				switch op {
				case asm.OpStoreIntMul:
					lhs *= rhs
				case asm.OpStoreIntDiv:
					lhs /= rhs
				case asm.OpStoreIntAdd:
					lhs += rhs
				case asm.OpStoreIntSub:
					lhs -= rhs
				case asm.OpStoreIntMod:
					lhs %= rhs
				case asm.OpStoreIntLSh:
					lhs <<= rhs
				case asm.OpStoreIntRSh:
					lhs >>= rhs
				case asm.OpStoreIntAnd:
					lhs &= rhs
				case asm.OpStoreIntOr:
					lhs |= rhs
				case asm.OpStoreIntXOr:
					lhs ^= rhs
				}
				*ptr = uint32(lhs)
				s.PushI32(lhs)
			} else {
				s.PushI32(0)
			}
			continue
		case asm.OpStoreFloatMul, asm.OpStoreFloatDiv, asm.OpStoreFloatAdd, asm.OpStoreFloatSub:
			rhs := s.PopF32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				lhs := math.Float32frombits(*ptr)
				switch op {
				case asm.OpStoreFloatMul:
					lhs *= rhs
				case asm.OpStoreFloatDiv:
					lhs /= rhs
				case asm.OpStoreFloatAdd:
					lhs += rhs
				case asm.OpStoreFloatSub:
					lhs -= rhs
				}
				*ptr = math.Float32bits(lhs)
				s.PushF32(lhs)
			} else {
				s.PushF32(0)
			}
			continue
		case asm.OpStoreStringAdd:
			dval := s.PopString()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			ptr := varPtr(isGlobal, vari)
			if ptr != nil {
				val := s.GetString(*ptr)
				val += dval
				*ptr = s.AddString(val)
				s.PushU32(*ptr)
			} else {
				s.PushU32(0)
			}
			continue
		case asm.OpIntEq:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs == rhs)
			continue
		case asm.OpFloatEq:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs == rhs)
			continue
		case asm.OpStringEq:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs == rhs)
			continue
		case asm.OpIntLSh:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs << rhs)
			continue
		case asm.OpIntRSh:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushI32(lhs >> rhs)
			continue
		case asm.OpIntLt:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs < rhs)
			continue
		case asm.OpFloatLt:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs < rhs)
			continue
		case asm.OpStringLt:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs < rhs)
			continue
		case asm.OpIntGt:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs > rhs)
			continue
		case asm.OpFloatGt:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs > rhs)
			continue
		case asm.OpStringGt:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs > rhs)
			continue
		case asm.OpIntLte:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs <= rhs)
			continue
		case asm.OpFloatLte:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs <= rhs)
			continue
		case asm.OpStringLte:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs <= rhs)
			continue
		case asm.OpIntGte:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs >= rhs)
			continue
		case asm.OpFloatGte:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs >= rhs)
			continue
		case asm.OpStringGte:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs >= rhs)
			continue
		case asm.OpIntNeq:
			rhs := s.PopI32()
			lhs := s.PopI32()
			s.PushBool(lhs != rhs)
			continue
		case asm.OpFloatNeq:
			rhs := s.PopF32()
			lhs := s.PopF32()
			s.PushBool(lhs != rhs)
			continue
		case asm.OpStringNeq:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushBool(lhs != rhs)
			continue
		case asm.OpBoolAnd:
			rhs := s.PopBool()
			lhs := s.PopBool()
			s.PushBool(lhs && rhs)
			continue
		case asm.OpBoolOr:
			rhs := s.PopBool()
			lhs := s.PopBool()
			s.PushBool(lhs || rhs)
			continue
		case asm.OpBoolNot:
			x := s.PopBool()
			s.PushBool(!x)
			continue
		case asm.OpIntNot:
			x := s.PopI32()
			s.PushI32(^x)
			continue
		case asm.OpIntNeg:
			x := s.PopI32()
			s.PushI32(-x)
			continue
		case asm.OpFloatNeg:
			x := -s.PopF32()
			s.PushF32(x)
			continue
		case asm.OpIndexInt:
			i := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			sz := s.PopI32()
			failed := i < 0 || i >= sz
			ptr := varIndPtr(isGlobal, vari, i)
			var val int32
			if ptr != nil {
				val = int32(*ptr)
			}
			s.PushI32(val)
			if failed {
				return fmt.Errorf("noxscript: index out of bounds: [%d:%d]", i, sz)
			}
			continue
		case asm.OpIndexFloat:
			i := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			sz := s.PopI32()
			failed := i < 0 || i >= sz
			ptr := varIndPtr(isGlobal, vari, i)
			var val float32
			if ptr != nil {
				val = math.Float32frombits(*ptr)
			}
			s.PushF32(val)
			if failed {
				return fmt.Errorf("noxscript: index out of bounds: [%d:%d]", i, sz)
			}
			continue
		case asm.OpIndexPtr:
			i := s.PopI32()
			vari := s.PopI32()
			isGlobal := s.PopBool()
			sz := s.PopI32()
			failed := i < 0 || i > sz
			s.PushBool(isGlobal)
			if vari < 0 {
				s.PushI32(vari - i)
			} else {
				s.PushI32(vari + i)
			}
			if failed {
				return fmt.Errorf("noxscript: index out of bounds: [%d:%d]", i, sz)
			}
			continue
		case asm.OpCallBuiltin:
			fi := asm.Builtin(readInt())
			if err := s.callBuiltin(index, fi); err != nil {
				return fmt.Errorf("in %q: %w", sc.Name(), err)
			}
		case asm.OpCallScript:
			ind := int(readInt())
			if err := s.CallByIndex(ind, caller, trigger); err != nil {
				return fmt.Errorf("in %q: %w", sc.Name(), err)
			}
		case asm.OpStringAdd:
			rhs := s.PopString()
			lhs := s.PopString()
			s.PushString(lhs + rhs)
		default:
			s.adjustStack(bstack, sc.Return)
			return nil
		}
	}
}
