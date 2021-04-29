package memmap

import (
	"fmt"
	"sync/atomic"
)

var runtimeCheck uint32 // atomic

func SetRuntimeChecks(enabled bool) {
	v := 0
	if enabled {
		v = 1
	}
	atomic.StoreUint32(&runtimeCheck, uint32(v))
}

func checkAddr(addr uintptr) {
	if v := VariableByAddr(addr); v != nil {
		blob, off := RelativeAddr(addr)
		panic(fmt.Errorf("intersection with %s at (0x%X, %d)", v.Name, blob, off))
	}
}
