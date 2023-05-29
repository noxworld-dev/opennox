package legacy

/*
#include "defs.h"
*/

import (
	"strconv"
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/env"
	"github.com/noxworld-dev/opennox-lib/platform"
)

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
	p.wYear = ushort(tm.Year())
	p.wMonth = ushort(tm.Month())
	p.wDayOfWeek = ushort(tm.Weekday())
	p.wDay = ushort(tm.Day())
	p.wHour = ushort(tm.Hour())
	p.wMinute = ushort(tm.Minute())
	p.wSecond = ushort(tm.Second())
	p.wMilliseconds = ushort(tm.Nanosecond() / 1e6)
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
