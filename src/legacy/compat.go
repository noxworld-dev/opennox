package legacy

import (
	"math"
	"strconv"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/platform"
)

const FLT_MIN = math.SmallestNonzeroFloat32 // FIXME: check

const MAX_PATH = 260

const (
	FILE_ATTRIBUTE_DIRECTORY = 0x10
	FILE_ATTRIBUTE_NORMAL    = 0x80
)

func strtol(a1 *byte, a2 **byte, a3 int32) int32 {
	panic("FIXME")
}

type FILETIME struct {
	dwLowDateTime  uint32
	dwHighDateTime uint32
}

type noxSYSTEMTIME struct {
	wYear         uint16
	wMonth        uint16
	wDayOfWeek    uint16
	wDay          uint16
	wHour         uint16
	wMinute       uint16
	wSecond       uint16
	wMilliseconds uint16
}

type HANDLE = uintptr
type HSTREAM = uintptr
type HSAMPLE = uintptr

type LPWIN32_FIND_DATAA = *WIN32_FIND_DATAA

// nox_itoa
func nox_itoa(val int32, s *byte, radix int32) *byte {
	str := strconv.FormatInt(int64(val), int(radix))
	buf := unsafe.Slice(s, len(str)+1)
	i := copy(buf, str)
	buf[i] = 0
	return s
}

// noxGetLocalTime
func noxGetLocalTime(p *noxSYSTEMTIME) {
	tm := time.Now()
	if env.IsE2E() {
		tm = time.Date(2022, 1, 1, 0, 0, 0, 0, time.UTC).Add(platform.Ticks())
	}
	p.wYear = uint16(tm.Year())
	p.wMonth = uint16(tm.Month())
	p.wDayOfWeek = uint16(tm.Weekday())
	p.wDay = uint16(tm.Day())
	p.wHour = uint16(tm.Hour())
	p.wMinute = uint16(tm.Minute())
	p.wSecond = uint16(tm.Second())
	p.wMilliseconds = uint16(tm.Nanosecond() / 1e6)
}

var _ = [1]struct{}{}[16-unsafe.Sizeof(SYSTEMTIME{})]

type SYSTEMTIME struct {
	Year         uint16
	Month        uint16
	DayOfWeek    uint16
	Day          uint16
	Hour         uint16
	Minute       uint16
	Second       uint16
	Milliseconds uint16
}

func (ts *SYSTEMTIME) Time() time.Time {
	if ts == nil {
		return time.Time{}
	}
	return time.Date(
		int(ts.Year), time.Month(ts.Month), int(ts.Day),
		int(ts.Hour), int(ts.Minute), int(ts.Second),
		int(ts.Milliseconds)*int(time.Millisecond),
		time.Local,
	)
}
