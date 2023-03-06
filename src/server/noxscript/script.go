package noxscript

import (
	"strconv"

	"github.com/noxworld-dev/noxscript/ns/asm"
	"github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/player"
)

func init() {
	Register(asm.BuiltinStopScript, nsAbort)
	Register(asm.BuiltinIntToString, nsIntToString)
	Register(asm.BuiltinFloatToString, nsFloatToString)
	Register(asm.BuiltinRandom, nsRandomInt)
	Register(asm.BuiltinRandomFloat, nsRandomFloat)
	Register(asm.BuiltinDistance, nsDistance)

	Register(asm.BuiltinEndGame, nsEndGame)
	Register(asm.BuiltinImmediateBlind, nsImmediateBlind)
	Register(asm.BuiltinChangeScore, nsChangeScore)
	Register(asm.BuiltinGetScore, nsGetScore)
	Register(asm.BuiltinWideScreen, nsWideScreen)
	Register(asm.BuiltinAutoSave, nsAutoSave)
	Register(asm.BuiltinDeathScreen, nsDeathScreen)
	Register(asm.BuiltinStartupScreen, nsStartupScreen)
	Register(asm.BuiltinPrint, nsPrint)
	Register(asm.BuiltinPrintToAll, nsPrintToAll)
	Register(asm.BuiltinBlind, nsBlind)
	Register(asm.BuiltinUnBlind, nsUnBlind)
	Register(asm.BuiltinJournalEntry, nsJournalEntry)
}

func nsAbort(_ VM) int { return 1 }

func nsIntToString(s VM) int {
	v := int(s.PopI32())
	s.PushString(strconv.Itoa(v))
	return 0
}

func nsFloatToString(s VM) int {
	v := float64(s.PopF32())
	s.PushString(strconv.FormatFloat(v, 'f', -1, 32))
	return 0
}

func nsRandomFloat(s VM) int {
	max := s.PopF32()
	min := s.PopF32()
	val := s.NoxScript().RandomFloat(min, max)
	s.PushF32(val)
	return 0
}

func nsRandomInt(s VM) int {
	max := int(s.PopU32())
	min := int(s.PopU32())
	val := s.NoxScript().Random(min, max)
	s.PushI32(int32(val))
	return 0
}

func nsEndGame(s VM) int {
	v := player.Class(s.PopI32())
	s.NoxScript().EndGame(v)
	return 0
}

func nsImmediateBlind(s VM) int {
	s.NoxScript().ImmediateBlind()
	return 0
}

func nsChangeScore(s VM) int {
	val := int(s.PopU32())
	u := s.PopObjectNS()
	if u == nil {
		return 0
	}
	u.ChangeScore(val)
	return 0
}

func nsGetScore(s VM) int {
	u := s.PopObjectNS()
	if u == nil {
		s.PushU32(0)
		return 0
	}
	v := u.GetScore()
	s.PushI32(int32(v))
	return 0
}

func nsWideScreen(s VM) int {
	s.NoxScript().WideScreen(s.PopBool())
	return 0
}

func nsAutoSave(s VM) int {
	s.NoxScript().AutoSave()
	return 0
}

func nsDistance(s VM) int {
	p2 := s.PopPointf()
	p1 := s.PopPointf()
	s.PushF32(float32(p2.Sub(p1).Len()))
	return 0
}

func nsDeathScreen(s VM) int {
	s.NoxScript().DeathScreen(int(s.PopU32()))
	return 0
}

func nsStartupScreen(s VM) int {
	s.NoxScript().StartupScreen(int(s.PopU32()))
	return 0
}

func nsPrint(s VM) int {
	strID := s.PopString()
	s.NoxScript().Print(strID)
	return 0
}

func nsPrintToAll(s VM) int {
	strID := s.PopString()
	s.NoxScript().PrintToAll(strID)
	return 0
}

func nsUnBlind(s VM) int {
	s.NoxScript().UnBlind()
	return 0
}

func nsBlind(s VM) int {
	s.NoxScript().Blind()
	return 0
}

func nsJournalEntry(s VM) int {
	typ := ns.EntryType(s.PopI32())
	msg := s.PopString()
	obj := s.PopObjectNS()
	s.NoxScript().JournalEntry(obj, msg, typ)
	return 0
}
