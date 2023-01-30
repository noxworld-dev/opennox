package legacy

/*
#include "defs.h"
*/
import "C"
import (
	"strconv"
	"time"
	"unsafe"
)

//export nox_itoa
func nox_itoa(val C.int, s *C.char, radix int) *C.char {
	str := strconv.FormatInt(int64(val), radix)
	buf := unsafe.Slice((*byte)(unsafe.Pointer(s)), len(str)+1)
	i := copy(buf, str)
	buf[i] = 0
	return s
}

//export noxGetLocalTime
func noxGetLocalTime(p *C.noxSYSTEMTIME) {
	tm := time.Now()
	p.wYear = C.ushort(tm.Year())
	p.wMonth = C.ushort(tm.Month())
	p.wDayOfWeek = C.ushort(tm.Weekday())
	p.wDay = C.ushort(tm.Day())
	p.wHour = C.ushort(tm.Hour())
	p.wMinute = C.ushort(tm.Minute())
	p.wSecond = C.ushort(tm.Second())
	p.wMilliseconds = C.ushort(tm.Nanosecond() / 1e6)
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
