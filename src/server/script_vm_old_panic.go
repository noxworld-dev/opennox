package server

import (
	"encoding/binary"

	"github.com/noxworld-dev/noxscript/ns/asm"
)

type noxScriptPanic struct {
	enabled bool
}

func (s *NoxScriptVM) panicCompilerCheck(fnc asm.Builtin) bool {
	// ===[ Panic's compiler detection ]===
	// it usually triggers on a2=973231
	// 0x587000 + 245900 + 3892924 -> 0x979748 -> 0x5D4594 + 3821996 + 8 -> nox_script_stack[2]

	off := 0x587000 + 245900 + 4*uintptr(fnc)
	stackOff := int64(off) - 0x5D4594 + 3821996

	if stackOff < 0 || stackOff+4 > 4096 || stackOff%4 != 0 {
		return false // disallow other type of stack manipulations
	}
	stackInd := int(stackOff / 4)
	// function address we need to jump to
	// basically points to the following uint32 on the stack
	if s.stackAt(stackInd) != 0x97974c {
		return false
	}
	stackInd++

	stackExp := []byte{
		0x56, // push   esi
		// -> 0x5D4594 + 1558936 + 356 (safe location in a string buffer?)
		0xbe, 0x90, 0x10, 0x75, 0x00, // mov    esi,0x751090
		// inject two functions there, see in replaced functions
		0xc7, 0x06, 0x68, 0x50, 0x72, 0x50, // mov    uint32_t PTR [esi],0x50725068
		0xc7, 0x46, 0x04, 0x00, 0x68, 0x30, 0x72, // mov    uint32_t PTR [esi+0x4],0x72306800
		0xc7, 0x46, 0x08, 0x50, 0x00, 0xff, 0x54, // mov    uint32_t PTR [esi+0x8],0x54ff0050
		0xc7, 0x46, 0x0c, 0x24, 0x04, 0xff, 0x30, // mov    uint32_t PTR [esi+0xc],0x30ff0424
		0xc7, 0x46, 0x10, 0xff, 0x54, 0x24, 0x04, // mov    uint32_t PTR [esi+0x10],0x42454ff
		0xc7, 0x46, 0x14, 0x83, 0xc4, 0x0c, 0x31, // mov    uint32_t PTR [esi+0x14],0x310cc483
		0xc7, 0x46, 0x18, 0xc0, 0xc3, 0x90, 0x90, // mov    uint32_t PTR [esi+0x18],0x9090c3c0
		0xc7, 0x46, 0x1c, 0x56, 0x68, 0x50, 0x72, // mov    uint32_t PTR [esi+0x1c],0x72506856
		0xc7, 0x46, 0x20, 0x50, 0x00, 0xff, 0x14, // mov    uint32_t PTR [esi+0x20],0x14ff0050
		0xc7, 0x46, 0x24, 0x24, 0x8b, 0xf0, 0xff, // mov    uint32_t PTR [esi+0x24],0xfff08b24
		0xc7, 0x46, 0x28, 0x14, 0x24, 0x89, 0x30, // mov    uint32_t PTR [esi+0x28],0x30892414
		0xc7, 0x46, 0x2c, 0x83, 0xc4, 0x04, 0x5e, // mov    uint32_t PTR [esi+0x2c],0x5e04c483
		0xc7, 0x46, 0x30, 0xc3, 0x90, 0x90, 0x90, // mov    uint32_t PTR [esi+0x30],0x909090c3
		// override opcode 185 from nox_script_builtin_516850 to new func 1
		0x89, 0x35, 0x70, 0x33, 0x5c, 0x00, // mov    uint32_t PTR ds:0x5c3370,esi
		// override opcode 89 from nsUnused59 to new func 2
		0xc7, 0x5, 0xf0, 0x31, 0x5c, 0x00, 0xac, // mov    uint32_t PTR ds:0x5c31f0,0x7510ac
		0x10, 0x75, 0x00, //
		0x5e,       // pop    esi
		0xc3,       // ret
		0x90, 0x90, // nop x2
	}
	len4 := len(stackExp) / 4
	if stackInd+len4 >= 1024 {
		return false // we expect all items of the body to fit
	}
	// check that the exploit code is exactly the one we expect
	for i := 0; i < len4; i++ {
		if binary.LittleEndian.Uint32(stackExp[4*i:]) != s.stackAt(stackInd+i) {
			return false
		}
	}
	// TODO: must set it back when the map script shutdowns
	s.panic.enabled = true
	ScriptLog.Printf("noxscript: enabled Panic's compiler API\n")
	return true
}

func (s *NoxScriptVM) panicBuiltinRead() int {
	// Panic's replacement for nox_script_builtin_516850 (opcode 185)
	//
	//  0x68, 0x50, 0x72, 0x50, 0x00, // push   0x507250 // nox_script_pop
	//  0x68, 0x30, 0x72, 0x50, 0x00, // push   0x507230 // nox_script_push
	//  0xff, 0x54, 0x24, 0x04,       // call   uint32_t PTR [esp+0x4] // eax = nox_script_pop()
	//  0xff, 0x30,                   // push   uint32_t PTR [eax]
	//  0xff, 0x54, 0x24, 0x04,       // call   uint32_t PTR [esp+0x4] // nox_script_push(*eax)
	//  0x83, 0xc4, 0x0c,             // add    esp,0xc
	//  0x31, 0xc0,                   // xor    eax,eax
	//  0xc3,                         // ret
	addr := s.PopU32()
	ScriptLog.Printf("noxscript: mem read [0x%x]\n", addr)
	val := uint32(0) // TODO: read via memmap
	s.PushU32(val)
	return 0
}

func (s *NoxScriptVM) panicBuiltinWrite() int {
	// Panic's replacement for nsUnused59 (opcode 89)
	//
	//  0x56,                         // push   esi
	//  0x68, 0x50, 0x72, 0x50, 0x00, // push   0x507250               // nox_script_pop
	//  0xff, 0x14, 0x24,             // call   uint32_t PTR [esp]     //
	//  0x8b, 0xf0,                   // mov    esi,eax                // esi = nox_script_pop()
	//  0xff, 0x14, 0x24,             // call   uint32_t PTR [esp]     // eax = nox_script_pop()
	//  0x89, 0x30,                   // mov    uint32_t PTR [eax],esi // *eax = esi
	//  0x83, 0xc4, 0x04,             // add    esp,0x4
	//  0x5e,                         // pop    esi
	//  0xc3,                         // ret
	val := s.PopU32()
	addr := s.PopU32()
	ScriptLog.Printf("noxscript: mem write [0x%x] = %d\n", addr, val)
	// TODO: write via memmap
	return 0
}

func (s *NoxScriptVM) PanicScriptCall(fi asm.Builtin) (int, bool) {
	if !s.panic.enabled {
		return 0, false
	}
	switch fi {
	case 185:
		val := s.panicBuiltinRead()
		return val, true
	case 89:
		val := s.panicBuiltinWrite()
		return val, true
	}
	return 0, false
}
