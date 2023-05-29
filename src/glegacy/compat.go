package legacy

import (
	"strconv"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/platform"
)

const MAX_PATH = 260

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

// nox_itoa
func nox_itoa(val int, s *char, radix int) *char {
	str := strconv.FormatInt(int64(val), radix)
	buf := unsafe.Slice((*byte)(unsafe.Pointer(s)), len(str)+1)
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
