package alloc

import (
	"encoding/json"
	"os"
	"sync"
	"sync/atomic"
	"unsafe"

	"nox/v1/common/memmap"
)

var (
	logEnable uint32 // atomic
	logOnce   sync.Once
	logMu     sync.Mutex
	logFile   *os.File
	logSeen   = make(map[memlog]struct{})
	logEnc    *json.Encoder
)

func init() {
	if os.Getenv("NOX_MEMLOG") == "1" {
		EnableMemlog(true)
	}
}

func EnableMemlog(enable bool) {
	var vi uint32
	if enable {
		vi = 1
	}
	atomic.StoreUint32(&logEnable, vi)
}

func ensureLog() {
	logOnce.Do(func() {
		f, err := os.Create("memlog.json")
		if err != nil {
			panic(err)
		}
		logFile = f
		logEnc = json.NewEncoder(f)
	})
}

const (
	memlogRead   = "read"
	memlogWrite  = "write"
	memlogString = "str"
)

type memlog struct {
	Type string  `json:"type"`
	Kind string  `json:"kind,omitempty"`
	Base uintptr `json:"base"`
	Off  uintptr `json:"off"`
	Size uintptr `json:"size"`
}

func logMem(ptr unsafe.Pointer, size uintptr, typ, kind string) {
	b, off := memmap.BlobByPtr(ptr)
	if b == nil {
		return
	}
	m := memlog{
		Type: typ,
		Kind: kind,
		Base: b.Addr,
		Off:  off,
		Size: size,
	}
	ensureLog()
	var err error
	logMu.Lock()
	if _, ok := logSeen[m]; !ok {
		err = logEnc.Encode(m)
		logSeen[m] = struct{}{}
	}
	logMu.Unlock()
	if err != nil {
		panic(err)
	}
}

func logMemRead(ptr unsafe.Pointer, size uintptr) {
	if atomic.LoadUint32(&logEnable) == 0 {
		return
	}
	logMem(ptr, size, memlogRead, "")
}

func logMemWrite(ptr unsafe.Pointer, size uintptr) {
	if atomic.LoadUint32(&logEnable) == 0 {
		return
	}
	logMem(ptr, size, memlogWrite, "")
}

func logMemReadString(ptr unsafe.Pointer, size uintptr) {
	if atomic.LoadUint32(&logEnable) == 0 {
		return
	}
	logMem(ptr, size, memlogRead, memlogString)
}

func logMemWriteString(ptr unsafe.Pointer, size uintptr) {
	if atomic.LoadUint32(&logEnable) == 0 {
		return
	}
	logMem(ptr, size, memlogWrite, memlogString)
}
