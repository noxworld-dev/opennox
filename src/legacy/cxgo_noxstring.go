package legacy

import (
	"math"
	"reflect"
	"unicode"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/gotranspile/cxgo/runtime/stdio"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func nox_itow(val int32, s *wchar2_t, radix int32) *wchar2_t {
	var (
		tmp [32]byte
		i   uint32
	)
	nox_itoa(val, &tmp[0], radix)
	for i = 0; tmp[i] != 0; i++ {
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(s), unsafe.Sizeof(wchar2_t(0))*uintptr(i))) = wchar2_t(tmp[i])
	}
	*(*wchar2_t)(unsafe.Add(unsafe.Pointer(s), unsafe.Sizeof(wchar2_t(0))*uintptr(i))) = 0
	return s
}
func nox_vsnwprintf(buffer *wchar2_t, count uint32, format *wchar2_t, ap libc.ArgList) int32 {
	var (
		i   int32 = 0
		j   int32
		out int32 = 0
		ch  wchar2_t
	)
	if count == 0 {
		buffer = nil
	}
	for (func() wchar2_t {
		ch = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(format), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
			p := &i
			x := *p
			*p++
			return x
		}())))
		return ch
	}()) != 0 {
		var (
			flag      int8  = 0
			width     int32 = -1
			precision int32 = -1
		)
		if ch != '%' {
			for {
				if buffer != nil && uint32(out) < count {
					*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}()))) = ch
				} else {
					out++
				}
				if true {
					break
				}
			}
			continue
		}
		ch = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(format), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
			p := &i
			x := *p
			*p++
			return x
		}())))
		switch ch {
		case '+', '-', '0':
			flag = int8(uint8(ch))
			ch = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(format), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
				p := &i
				x := *p
				*p++
				return x
			}())))
		}
		for ch >= '0' && ch <= '9' {
			if width < 0 {
				width = 0
			}
			width = width*10 + int32(ch) - '0'
			ch = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(format), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
				p := &i
				x := *p
				*p++
				return x
			}())))
		}
		if ch == '.' {
			ch = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(format), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
				p := &i
				x := *p
				*p++
				return x
			}())))
			precision = 0
			for ch >= '0' && ch <= '9' {
				precision = precision*10 + int32(ch) - '0'
				ch = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(format), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
					p := &i
					x := *p
					*p++
					return x
				}())))
			}
		}
		switch ch {
		case 'c':
			var c wchar2_t = wchar2_t(int16(ap.Arg().(int32)))
			for {
				if buffer != nil && uint32(out) < count {
					*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}()))) = c
				} else {
					out++
				}
				if true {
					break
				}
			}
		case 's':
			var (
				null [7]wchar2_t = [7]wchar2_t{'(', 'n', 'u', 'l', 'l', ')', 0}
				pwch *wchar2_t   = ap.Arg().(*wchar2_t)
			)
			if pwch == nil {
				pwch = &null[0]
			}
			for j = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(pwch), unsafe.Sizeof(wchar2_t(0))*uintptr(j))) != 0; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}()))) = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(pwch), unsafe.Sizeof(wchar2_t(0))*uintptr(j)))
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case 'S':
			var pcch *byte = ap.Arg().(*byte)
			if pcch == nil {
				pcch = internCStr("(null)")
			}
			for j = 0; *(*byte)(unsafe.Add(unsafe.Pointer(pcch), j)) != 0; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}()))) = wchar2_t(*(*byte)(unsafe.Add(unsafe.Pointer(pcch), j)) & math.MaxUint8)
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case 'd', 'i':
			var (
				tmp  [32]byte
				len_ int32
			)
			len_ = int32(libc.StrLen(nox_itoa(ap.Arg().(int32), &tmp[0], 10)))
			for j = 0; j < width-(func() int32 {
				if precision > 0 {
					return precision
				}
				return len_
			}()); j++ {
				if int32(flag) == '0' {
					for {
						if buffer != nil && uint32(out) < count {
							*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}()))) = '0'
						} else {
							out++
						}
						if true {
							break
						}
					}
				} else {
					for {
						if buffer != nil && uint32(out) < count {
							*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}()))) = ' '
						} else {
							out++
						}
						if true {
							break
						}
					}
				}
			}
			for j = 0; j < precision-len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}()))) = '0'
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
			for j = 0; j < len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}()))) = wchar2_t(tmp[j])
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case 'X', 'x', 'o', 'u':
			var (
				tmp  [32]byte
				len_ int32
			)
			len_ = int32(libc.StrLen(nox_itoa(int32(ap.Arg().(uint32)), &tmp[0], func() int32 {
				if ch == 'u' {
					return 10
				}
				if ch == 'o' {
					return 8
				}
				return 16
			}())))
			for j = 0; j < width-(func() int32 {
				if precision > 0 {
					return precision
				}
				return len_
			}()); j++ {
				if int32(flag) == '0' {
					for {
						if buffer != nil && uint32(out) < count {
							*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}()))) = '0'
						} else {
							out++
						}
						if true {
							break
						}
					}
				} else {
					for {
						if buffer != nil && uint32(out) < count {
							*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}()))) = ' '
						} else {
							out++
						}
						if true {
							break
						}
					}
				}
			}
			for j = 0; j < precision-len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}()))) = '0'
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
			for j = 0; j < len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}()))) = wchar2_t(int16(func() rune {
							if ch == 'X' {
								return unicode.ToUpper(rune(tmp[j]))
							}
							return rune(tmp[j])
						}()))
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case 'f':
			var (
				tmp             [32]byte
				tmp2            [32]byte
				val             float64
				len_            int32
				final_precision int32
			)
			if precision > 0 {
				final_precision = precision
			} else {
				final_precision = 5
			}
			stdio.Snprintf(&tmp[0], 32, "%%.%df", final_precision)
			val = ap.Arg().(float64)
			stdio.Snprintf(&tmp2[0], 32, libc.GoString(&tmp[0]), val)
			len_ = int32(libc.StrLen(&tmp2[0]))
			for j = 0; j < len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}()))) = wchar2_t(tmp2[j])
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case '%':
			for {
				if buffer != nil && uint32(out) < count {
					*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}()))) = '%'
				} else {
					out++
				}
				if true {
					break
				}
			}
		case '!':
			for {
				if buffer != nil && uint32(out) < count {
					*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}()))) = '!'
				} else {
					out++
				}
				if true {
					break
				}
			}
		default:
			stdio.Printf("Unhandled format character: '%c'", ch)
			panic("abort")
		}
	}
	for {
		if buffer != nil && uint32(out) < count {
			*(*wchar2_t)(unsafe.Add(unsafe.Pointer(buffer), unsafe.Sizeof(wchar2_t(0))*uintptr(func() int32 {
				p := &out
				x := *p
				*p++
				return x
			}()))) = 0
		} else {
			out++
		}
		if true {
			break
		}
	}
	return out - 1
}
func asPtr(v any) unsafe.Pointer {
	switch v := v.(type) {
	case nil:
		return nil
	case unsafe.Pointer:
		return nil
	case uintptr:
		return unsafe.Pointer(v)
	case uint32:
		return unsafe.Pointer(uintptr(v))
	case int32:
		return unsafe.Pointer(uintptr(v))
	default:
		return reflect.ValueOf(v).UnsafePointer()
	}
}
func nox_vsnprintf(buffer *byte, count uint32, format *byte, ap libc.ArgList) int32 {
	var (
		i   int32 = 0
		j   int32
		out int32 = 0
		ch  int8
	)
	if count == 0 {
		buffer = nil
	}
	for int32(func() int8 {
		ch = int8(*(*byte)(unsafe.Add(unsafe.Pointer(format), func() int32 {
			p := &i
			x := *p
			*p++
			return x
		}())))
		return ch
	}()) != 0 {
		var (
			flag      int8  = 0
			width     int32 = -1
			precision int32 = -1
		)
		if int32(ch) != '%' {
			for {
				if buffer != nil && uint32(out) < count {
					*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}())) = byte(ch)
				} else {
					out++
				}
				if true {
					break
				}
			}
			continue
		}
		ch = int8(*(*byte)(unsafe.Add(unsafe.Pointer(format), func() int32 {
			p := &i
			x := *p
			*p++
			return x
		}())))
		switch ch {
		case '+', '-', '0':
			flag = ch
			ch = int8(*(*byte)(unsafe.Add(unsafe.Pointer(format), func() int32 {
				p := &i
				x := *p
				*p++
				return x
			}())))
		}
		for int32(ch) >= '0' && int32(ch) <= '9' {
			if width < 0 {
				width = 0
			}
			width = width*10 + int32(ch) - '0'
			ch = int8(*(*byte)(unsafe.Add(unsafe.Pointer(format), func() int32 {
				p := &i
				x := *p
				*p++
				return x
			}())))
		}
		if int32(ch) == '.' {
			ch = int8(*(*byte)(unsafe.Add(unsafe.Pointer(format), func() int32 {
				p := &i
				x := *p
				*p++
				return x
			}())))
			precision = 0
			for int32(ch) >= '0' && int32(ch) <= '9' {
				precision = precision*10 + int32(ch) - '0'
				ch = int8(*(*byte)(unsafe.Add(unsafe.Pointer(format), func() int32 {
					p := &i
					x := *p
					*p++
					return x
				}())))
			}
		}
		switch ch {
		case 'c':
			var c int8 = int8(ap.Arg().(int32))
			for {
				if buffer != nil && uint32(out) < count {
					*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}())) = byte(c)
				} else {
					out++
				}
				if true {
					break
				}
			}
		case 's':
			var pcch *byte = (*byte)(asPtr(ap.Arg()))
			if pcch == nil {
				pcch = internCStr("(null)")
			}
			for j = 0; *(*byte)(unsafe.Add(unsafe.Pointer(pcch), j)) != 0; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}())) = *(*byte)(unsafe.Add(unsafe.Pointer(pcch), j))
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case 'S':
			var (
				null [7]wchar2_t = [7]wchar2_t{'(', 'n', 'u', 'l', 'l', ')', 0}
				pwch *wchar2_t   = ap.Arg().(*wchar2_t)
			)
			if pwch == nil {
				pwch = &null[0]
			}
			for j = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(pwch), unsafe.Sizeof(wchar2_t(0))*uintptr(j))) != 0; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}())) = byte(*(*wchar2_t)(unsafe.Add(unsafe.Pointer(pwch), unsafe.Sizeof(wchar2_t(0))*uintptr(j))))
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case 'd', 'i':
			var (
				tmp  [32]byte
				len_ int32
			)
			len_ = int32(libc.StrLen(nox_itoa(ap.Arg().(int32), &tmp[0], 10)))
			for j = 0; j < width-(func() int32 {
				if precision > 0 {
					return precision
				}
				return len_
			}()); j++ {
				if int32(flag) == '0' {
					for {
						if buffer != nil && uint32(out) < count {
							*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}())) = '0'
						} else {
							out++
						}
						if true {
							break
						}
					}
				} else {
					for {
						if buffer != nil && uint32(out) < count {
							*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}())) = ' '
						} else {
							out++
						}
						if true {
							break
						}
					}
				}
			}
			for j = 0; j < precision-len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}())) = '0'
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
			for j = 0; j < len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}())) = tmp[j]
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case 'X', 'x', 'o', 'u':
			var (
				tmp  [32]byte
				len_ int32
			)
			len_ = int32(libc.StrLen(nox_itoa(int32(ap.Arg().(uint32)), &tmp[0], func() int32 {
				if int32(ch) == 'u' {
					return 10
				}
				if int32(ch) == 'o' {
					return 8
				}
				return 16
			}())))
			for j = 0; j < width-(func() int32 {
				if precision > 0 {
					return precision
				}
				return len_
			}()); j++ {
				if int32(flag) == '0' {
					for {
						if buffer != nil && uint32(out) < count {
							*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}())) = '0'
						} else {
							out++
						}
						if true {
							break
						}
					}
				} else {
					for {
						if buffer != nil && uint32(out) < count {
							*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
								p := &out
								x := *p
								*p++
								return x
							}())) = ' '
						} else {
							out++
						}
						if true {
							break
						}
					}
				}
			}
			for j = 0; j < precision-len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}())) = '0'
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
			for j = 0; j < len_; j++ {
				for {
					if buffer != nil && uint32(out) < count {
						*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
							p := &out
							x := *p
							*p++
							return x
						}())) = byte(int8(func() rune {
							if int32(ch) == 'X' {
								return unicode.ToUpper(rune(tmp[j]))
							}
							return rune(tmp[j])
						}()))
					} else {
						out++
					}
					if true {
						break
					}
				}
			}
		case '%':
			for {
				if buffer != nil && uint32(out) < count {
					*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}())) = '%'
				} else {
					out++
				}
				if true {
					break
				}
			}
		case '!':
			for {
				if buffer != nil && uint32(out) < count {
					*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
						p := &out
						x := *p
						*p++
						return x
					}())) = '!'
				} else {
					out++
				}
				if true {
					break
				}
			}
		default:
			stdio.Printf("Unhandled format character: '%c'", ch)
			panic("abort")
		}
	}
	for {
		if buffer != nil && uint32(out) < count {
			*(*byte)(unsafe.Add(unsafe.Pointer(buffer), func() int32 {
				p := &out
				x := *p
				*p++
				return x
			}())) = 0
		} else {
			out++
		}
		if true {
			break
		}
	}
	return out - 1
}
func nox_vsprintf(str *byte, format *byte, ap libc.ArgList) int32 {
	return nox_vsnprintf(str, math.MaxInt32, format, ap)
}
func nox_sprintf(str *byte, format *byte, _rest ...interface{}) int32 {
	var (
		ret int32
		ap  libc.ArgList
	)
	ap.Start(format, _rest)
	ret = nox_vsprintf(str, format, ap)
	ap.End()
	return ret
}
func nox_wcscat(dest *wchar2_t, src *wchar2_t) *wchar2_t {
	var ret *wchar2_t = dest
	for *dest != 0 {
		dest = (*wchar2_t)(unsafe.Add(unsafe.Pointer(dest), unsafe.Sizeof(wchar2_t(0))*1))
	}
	for *src != 0 {
		*func() *wchar2_t {
			p := &dest
			x := *p
			*p = (*wchar2_t)(unsafe.Add(unsafe.Pointer(*p), unsafe.Sizeof(wchar2_t(0))*1))
			return x
		}() = *func() *wchar2_t {
			p := &src
			x := *p
			*p = (*wchar2_t)(unsafe.Add(unsafe.Pointer(*p), unsafe.Sizeof(wchar2_t(0))*1))
			return x
		}()
	}
	*dest = 0
	return ret
}
func nox_wcschr(nox_wcs *wchar2_t, wc wchar2_t) *wchar2_t {
	var result uint32
	for result = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(nox_wcs), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) != 0; result++ {
		if *(*wchar2_t)(unsafe.Add(unsafe.Pointer(nox_wcs), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) == wc {
			return (*wchar2_t)(unsafe.Add(unsafe.Pointer(nox_wcs), unsafe.Sizeof(wchar2_t(0))*uintptr(result)))
		}
	}
	return nil
}
func nox_wcscmp(s1 *wchar2_t, s2 *wchar2_t) int32 {
	if s1 == s2 {
		return 0
	}
	if s1 == nil {
		return -1
	}
	if s2 == nil {
		return +1
	}
	var result uint32
	for result = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(s1), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) != 0 && *(*wchar2_t)(unsafe.Add(unsafe.Pointer(s1), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) == *(*wchar2_t)(unsafe.Add(unsafe.Pointer(s2), unsafe.Sizeof(wchar2_t(0))*uintptr(result))); result++ {
	}
	return int32(*(*wchar2_t)(unsafe.Add(unsafe.Pointer(s1), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) - *(*wchar2_t)(unsafe.Add(unsafe.Pointer(s2), unsafe.Sizeof(wchar2_t(0))*uintptr(result))))
}
func nox_wcscpy(dest *wchar2_t, src *wchar2_t) *wchar2_t {
	var result uint32
	for result = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(src), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) != 0; result++ {
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(dest), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(src), unsafe.Sizeof(wchar2_t(0))*uintptr(result)))
	}
	*(*wchar2_t)(unsafe.Add(unsafe.Pointer(dest), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) = 0
	return dest
}
func nox_wcslen(nox_wcs *wchar2_t) uint32 {
	var result uint32
	for result = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(nox_wcs), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) != 0; result++ {
	}
	return result
}
func nox_wcsncpy(dest *wchar2_t, src *wchar2_t, n uint32) *wchar2_t {
	var result uint32
	for result = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(src), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) != 0 && result < n; result++ {
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(dest), unsafe.Sizeof(wchar2_t(0))*uintptr(result))) = *(*wchar2_t)(unsafe.Add(unsafe.Pointer(src), unsafe.Sizeof(wchar2_t(0))*uintptr(result)))
	}
	for result < n {
		*(*wchar2_t)(unsafe.Add(unsafe.Pointer(dest), unsafe.Sizeof(wchar2_t(0))*uintptr(func() uint32 {
			p := &result
			x := *p
			*p++
			return x
		}()))) = 0
	}
	return dest
}
func nox_wcsspn(nox_wcs *wchar2_t, accept *wchar2_t) uint32 {
	var i uint32
	for i = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(nox_wcs), unsafe.Sizeof(wchar2_t(0))*uintptr(i))) != 0; i++ {
		if nox_wcschr(accept, *(*wchar2_t)(unsafe.Add(unsafe.Pointer(nox_wcs), unsafe.Sizeof(wchar2_t(0))*uintptr(i)))) == nil {
			break
		}
	}
	return i
}
func nox_wcstok(str *wchar2_t, delim *wchar2_t) *wchar2_t {
	var (
		next *wchar2_t
		i    uint32
	)
	if str == nil {
		str = next
	}
	if str == nil {
		return nil
	}
	for *str != 0 {
		if nox_wcschr(delim, *str) == nil {
			break
		}
		str = (*wchar2_t)(unsafe.Add(unsafe.Pointer(str), unsafe.Sizeof(wchar2_t(0))*1))
	}
	if *str == 0 {
		next = nil
		return nil
	}
	for i = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(str), unsafe.Sizeof(wchar2_t(0))*uintptr(i))) != 0; i++ {
		if nox_wcschr(delim, *(*wchar2_t)(unsafe.Add(unsafe.Pointer(str), unsafe.Sizeof(wchar2_t(0))*uintptr(i)))) != nil {
			*(*wchar2_t)(unsafe.Add(unsafe.Pointer(str), unsafe.Sizeof(wchar2_t(0))*uintptr(i))) = 0
			next = (*wchar2_t)(unsafe.Add(unsafe.Pointer(str), unsafe.Sizeof(wchar2_t(0))*uintptr(i+1)))
			return str
		}
	}
	next = (*wchar2_t)(unsafe.Add(unsafe.Pointer(str), unsafe.Sizeof(wchar2_t(0))*uintptr(i)))
	return str
}
func _nox_wcsicmp(string1 *wchar2_t, string2 *wchar2_t) int32 {
	var i uint32
	for i = 0; *(*wchar2_t)(unsafe.Add(unsafe.Pointer(string1), unsafe.Sizeof(wchar2_t(0))*uintptr(i))) != 0 && unicode.ToLower(rune(*(*wchar2_t)(unsafe.Add(unsafe.Pointer(string1), unsafe.Sizeof(wchar2_t(0))*uintptr(i))))) == unicode.ToLower(rune(*(*wchar2_t)(unsafe.Add(unsafe.Pointer(string2), unsafe.Sizeof(wchar2_t(0))*uintptr(i))))); i++ {
	}
	return int32(unicode.ToLower(rune(*(*wchar2_t)(unsafe.Add(unsafe.Pointer(string1), unsafe.Sizeof(wchar2_t(0))*uintptr(i))))) - unicode.ToLower(rune(*(*wchar2_t)(unsafe.Add(unsafe.Pointer(string2), unsafe.Sizeof(wchar2_t(0))*uintptr(i))))))
}
func nox_strcmpi(string1 *byte, string2 *byte) int32 {
	var i uint32
	for i = 0; *(*byte)(unsafe.Add(unsafe.Pointer(string1), i)) != 0 && unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string1), i)))) == unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string2), i)))); i++ {
	}
	return int32(unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string1), i)))) - unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string2), i)))))
}
func nox_strnicmp(string1 *byte, string2 *byte, sz int32) int32 {
	var i uint32
	for i = 0; i < uint32(sz) && *(*byte)(unsafe.Add(unsafe.Pointer(string1), i)) != 0 && unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string1), i)))) == unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string2), i)))); i++ {
	}
	if i >= uint32(sz) {
		return 1
	}
	return int32(unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string1), i)))) - unicode.ToLower(rune(*(*byte)(unsafe.Add(unsafe.Pointer(string2), i)))))
}
func nox_wcstol(nptr *wchar2_t, endptr **wchar2_t, base int32) int32 {
	var (
		result int32
		i      uint32
		len_   uint32 = nox_wcslen(nptr)
		tmp    *byte
		ptr    *byte
	)
	tmp = (*byte)(alloc.Calloc1(int(len_+1), 1))
	for i = 0; i < len_; i++ {
		if *(*wchar2_t)(unsafe.Add(unsafe.Pointer(nptr), unsafe.Sizeof(wchar2_t(0))*uintptr(i))) < 0x80 {
			*(*byte)(unsafe.Add(unsafe.Pointer(tmp), i)) = byte(*(*wchar2_t)(unsafe.Add(unsafe.Pointer(nptr), unsafe.Sizeof(wchar2_t(0))*uintptr(i))))
		} else {
			*(*byte)(unsafe.Add(unsafe.Pointer(tmp), i)) = math.MaxInt8
		}
	}
	*(*byte)(unsafe.Add(unsafe.Pointer(tmp), i)) = 0
	result = strtol(tmp, &ptr, base)
	if endptr != nil {
		*endptr = (*wchar2_t)(unsafe.Add(unsafe.Pointer(nptr), unsafe.Sizeof(wchar2_t(0))*uintptr(int32(uintptr(unsafe.Pointer(ptr))-uintptr(unsafe.Pointer(tmp))))))
	}
	alloc.Free(tmp)
	return result
}
func nox_swprintf(str *wchar2_t, fmt *wchar2_t, _rest ...interface{}) int32 {
	var (
		len_ int32
		ap   libc.ArgList
	)
	ap.Start(fmt, _rest)
	len_ = nox_vsnwprintf(str, 0x3FFFFFFF, fmt, ap)
	ap.End()
	return len_
}
func nox_vswprintf(str *wchar2_t, fmt *wchar2_t, ap libc.ArgList) int32 {
	return nox_vsnwprintf(str, 0x3FFFFFFF, fmt, ap)
}
