package memmap

import (
	"bytes"
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
		panic(fmt.Errorf("intersection with %s (%+d) at (0x%X, %d)", v.Name, addr-v.Addr, blob, off))
	}
}

// ValidateZeros checks if mapped regions are still set to zero as they should be.
func ValidateZeros() {
	for _, v := range Variables() {
		b := v.Blob()
		off := v.Addr - b.Addr
		data := b.Data[off:]
		zero := b.Initial[off:]
		data = data[:v.Size]
		zero = zero[:v.Size]
		if !bytes.Equal(data, zero) {
			panic(fmt.Errorf("found non-nil data for %s at (0x%X, %d)", v.Name, b.Addr, off))
		}
	}
}
