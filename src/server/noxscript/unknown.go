package noxscript

import "github.com/noxworld-dev/noxscript/ns/asm"

func init() {
	Register(asm.BuiltinUnused1f, nsUnused1f)
	Register(asm.BuiltinUnused20, nsUnused20)
	Register(asm.BuiltinUnused50, nsUnused50)
	Register(asm.BuiltinUnused58, nsUnused58)
	Register(asm.BuiltinUnused59, nsUnused59)
	Register(asm.BuiltinUnused5a, nsUnused5a)
	Register(asm.BuiltinUnused5b, nsUnused5b)
	Register(asm.BuiltinUnused5c, nsUnused5c)
	Register(asm.BuiltinUnused5d, nsUnused5d)
	Register(asm.BuiltinUnused74, nsUnused74)
	Register(asm.BuiltinUnknownc4, nsUnknownc4)
}

func nsUnused1f(s VM) int {
	a1 := int(s.PopI32())
	s.NoxScript().Unused1f(a1)
	return 0
}

func nsUnused20(s VM) int {
	a1 := int(s.PopI32())
	s.NoxScript().Unused20(a1)
	return 0
}

func nsUnused50(s VM) int {
	s.NoxScript().Unused50()
	return 0
}

func nsUnused58(s VM) int {
	a2 := int(s.PopI32())
	a1 := int(s.PopI32())
	s.NoxScript().Unused58(a1, a2)
	return 0
}

func nsUnused59(s VM) int {
	a2 := int(s.PopI32())
	a1 := int(s.PopI32())
	s.NoxScript().Unused59(a1, a2)
	return 0
}

func nsUnused5a(s VM) int {
	a2 := int(s.PopI32())
	a1 := int(s.PopI32())
	s.NoxScript().Unused5a(a1, a2)
	return 0
}

func nsUnused5b(s VM) int {
	a2 := int(s.PopI32())
	a1 := int(s.PopI32())
	s.NoxScript().Unused5b(a1, a2)
	return 0
}

func nsUnused5c(s VM) int {
	a2 := int(s.PopI32())
	a1 := int(s.PopI32())
	s.NoxScript().Unused5c(a1, a2)
	return 0
}

func nsUnused5d(s VM) int {
	a2 := int(s.PopI32())
	a1 := int(s.PopI32())
	s.NoxScript().Unused5d(a1, a2)
	return 0
}

func nsUnused74(s VM) int {
	a2 := int(s.PopI32())
	a1 := int(s.PopI32())
	s.NoxScript().Unused74(a1, a2)
	return 0
}

func nsUnknownc4(s VM) int {
	s.NoxScript().Unknownc4()
	return 0
}
