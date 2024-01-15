//go:build 386

package nxz

import (
	"math"
	"unsafe"
)

func sub_57DDE0(a1 int32, a2 int32) uint32 {
	var (
		v2     int32
		v3     int32
		i      int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		result uint32
		v10    int32
		v11    int32
		v12    int32
	)
	v2 = a1
	v3 = a2
	for i = 40; i > 0; i /= 3 {
		v5 = i + 1
		v11 = i + 1
		if i+1 <= v3 {
			for {
				v6 = v5 * 4
				v10 = v5
				v12 = int32(*(*uint32)(unsafe.Pointer(uintptr(v5*4 + v2))))
				if v5 > i {
					v7 = i * 4
					for {
						v8 = int32(*(*int16)(unsafe.Pointer(uintptr(v6 - v7 + v2 + 2)))) - int32(*(*int16)(unsafe.Add(unsafe.Pointer((*int16)(unsafe.Pointer(&v12))), unsafe.Sizeof(int16(0))*1)))
						if v8 == 0 {
							v8 = int32(*(*int16)(unsafe.Pointer(uintptr(v6 - v7 + v2)))) - int32(int16(v12))
						}
						if v8 >= 0 {
							break
						}
						*(*uint32)(unsafe.Pointer(uintptr(v6 + v2))) = *(*uint32)(unsafe.Pointer(uintptr(v6 - v7 + v2)))
						v6 -= v7
						v10 -= i
						if v10 <= i {
							break
						}
					}
					v5 = v11
				}
				v5++
				*(*uint32)(unsafe.Pointer(uintptr(v2 + v10*4))) = uint32(v12)
				v3 = a2
				v11 = v5
				if v5 > a2 {
					break
				}
			}
		}
		result = uint32(i/3) >> 31
	}
	return result
}
func sub_57DEA0(this *uint32, a2 *uint16) int32 {
	var (
		v2 *uint16
		v3 int32
		i  int32
		v5 *int16
		v6 int16
	)
	v2 = a2
	v3 = 0
	for i = 0; i < tableSize; i++ {
		*v2 = uint16(int16(i))
		v2 = (*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*2))
		*((*uint16)(unsafe.Add(unsafe.Pointer(v2), -int(unsafe.Sizeof(uint16(0))*1)))) = *(*uint16)(unsafe.Pointer(uintptr(*this + uint32(i*2))))
		v5 = (*int16)(unsafe.Pointer(uintptr(*this + uint32(i*2))))
		v6 = *v5
		v3 += int32(v6)
		*v5 = int16(int32(v6) >> 1)
	}
	sub_57DDE0(int32(uintptr(unsafe.Pointer((*uint16)(unsafe.Add(unsafe.Pointer(a2), -int(unsafe.Sizeof(uint16(0))*2)))))), tableSize)
	return v3
}
func sub_57DFC0(this *uint32, a2 *int32) int32 {
	var (
		v2     *uint32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    *byte
		v13    int32
		v14    *int32
		v15    int32
		v16    int32
		v17    int32
		v18    *byte
		v19    int32
		v20    int32
		v21    int32
		v22    int32
		v23    int32
		v24    *byte
		v25    int32
		v26    int32
		v27    *int32
		v28    int32
		v29    *int32
		v30    int32
		v31    *int32
		v32    int32
		v33    int32
		v34    int32
		v35    int32
		result int32
		v37    int32
		v38    int16
		v39    int32
		v40    *byte
		v41    int32
		v42    int16
		v43    *int32
		v44    int32
		v45    int32
		v46    int32
		v47    int32
		v48    *int32
		v49    int32
		v50    int32
		v51    int32
		v52    int32
		v53    int32
		v54    int32
		v55    int32
		v56    int32
		v57    int32
		v58    int32
		v59    int32
		v60    [1100]byte
	)
	v2 = this
	*(*uint32)(unsafe.Pointer(&v60[0])) = uint32(uintptr(unsafe.Pointer(this)))
	v3 = sub_57DEA0(this, (*uint16)(unsafe.Pointer(&v60[4])))
	v4 = 0
	v5 = 0
	v6 = 16
	v56 = v3
	*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = 4096
	v55 = 0
	v46 = 0
	v52 = 16
	v43 = (*int32)(unsafe.Add(unsafe.Pointer(a2), -int(4*1)))
	for {
		v7 = 0
		v58 = 0
		v8 = 0
		v59 = (v56 - v55) / v6
		for {
			v49 = 0
			v9 = 1 << v4
			if v5+(1<<v4)+v7 > tableSize {
				v49 = 1
				v9 = tableSize - v5
			}
			if v7 < v9 {
				v10 = v7 + v5
				v11 = v9 - v7
				v7 += v11
				v12 = &v60[v10*4+6]
				for {
					v8 += int32(*(*int16)(unsafe.Pointer(v12)))
					v12 = (*byte)(unsafe.Add(unsafe.Pointer(v12), 4))
					v11--
					if v11 == 0 {
						break
					}
				}
				v6 = v52
			}
			if v49 != 0 || v4 >= 8 || v8 > v59 {
				break
			}
			v58 = v8
			v4++
		}
		if v4 != 0 && abs(int64(v58-v59)) <= abs(int64(v8-v59)) {
			v8 = v58
			v4--
		}
		v13 = v46
		if v6 < 16 {
			v14 = v43
			for {
				if v4 >= *v14 {
					break
				}
				*(*int32)(unsafe.Add(unsafe.Pointer(v14), 4*1)) = *v14
				v13--
				v14 = (*int32)(unsafe.Add(unsafe.Pointer(v14), -int(4*1)))
				if v13 <= 0 {
					break
				}
			}
		}
		*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v13))) = v4
		v55 += v8
		v43 = (*int32)(unsafe.Add(unsafe.Pointer(v43), 4*1))
		v5 += 1 << v4
		v6--
		v46++
		v52 = v6
		if v6 <= 2 {
			break
		}
		v4 = 0
	}
	v15 = 0
	v16 = 0
	v17 = 0
	v44 = 0
	v47 = 0
	v50 = math.MaxInt32
	v53 = 0
	if v5 < tableSize {
		v18 = &v60[v5*4+6]
		v19 = tableSize - v5
		for {
			v17 += int32(*(*int16)(unsafe.Pointer(v18)))
			v18 = (*byte)(unsafe.Add(unsafe.Pointer(v18), 4))
			v19--
			if v19 == 0 {
				break
			}
		}
		v53 = v17
	}
	v20 = 0
	v21 = 1
	if v5+1 <= tableSize {
		for {
			if v15 < v21 {
				v22 = v15 + v5
				v23 = v21 - v15
				v15 += v23
				v24 = &v60[v22*4+6]
				for {
					v16 += int32(*(*int16)(unsafe.Pointer(v24)))
					v24 = (*byte)(unsafe.Add(unsafe.Pointer(v24), 4))
					v23--
					if v23 == 0 {
						break
					}
				}
			}
			v25 = 0
			v26 = tableSize - v15 - v5
			if v26 > 1 {
				for {
					v25++
					if 1<<v25 >= v26 {
						break
					}
				}
			}
			if v20 <= 8 && v25 <= 8 {
				if v16*v20+v25*(v53-v16) >= v50 {
					break
				}
				v50 = v16*v20 + v25*(v53-v16)
				v44 = v20
				v47 = v25
			}
			v21 = 1 << func() int32 {
				p := &v20
				*p++
				return *p
			}()
			if v5+(1<<v20)+v15 > tableSize {
				break
			}
		}
	}
	v27 = a2
	v28 = 14
	v29 = (*int32)(unsafe.Add(unsafe.Pointer(a2), 4*13))
	for {
		if v44 >= *v29 {
			break
		}
		*(*int32)(unsafe.Add(unsafe.Pointer(v29), 4*1)) = *v29
		v28--
		v29 = (*int32)(unsafe.Add(unsafe.Pointer(v29), -int(4*1)))
		if v28 <= 0 {
			break
		}
	}
	*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v28))) = v44
	v30 = 15
	v31 = (*int32)(unsafe.Add(unsafe.Pointer(a2), 4*14))
	for {
		if v47 >= *v31 {
			break
		}
		*(*int32)(unsafe.Add(unsafe.Pointer(v31), 4*1)) = *v31
		v30--
		v31 = (*int32)(unsafe.Add(unsafe.Pointer(v31), -int(4*1)))
		if v30 <= 0 {
			break
		}
	}
	*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v30))) = v47
	v32 = 0
	v33 = 0
	v51 = 0
	v45 = 0
	v48 = a2
	for {
		v34 = *v27
		v35 = 1 << *v27
		result = tableSize - v32
		v57 = v35
		if v35 < tableSize-v32 {
			result = v35
		}
		v37 = 0
		v54 = result
		if result > 0 {
			v38 = int16(v34 + 4)
			v39 = v33 << v34
			v40 = &v60[v32*4+4]
			for {
				v41 = int32(*(*int16)(unsafe.Pointer(v40)))
				v40 = (*byte)(unsafe.Add(unsafe.Pointer(v40), 4))
				*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(&v60[0])) + 8))) + uint32(v41*4)))) = uint16(v38)
				v42 = int16(func() int32 {
					p := &v37
					x := *p
					*p++
					return x
				}() | v39)
				*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(&v60[0])) + 8))) + uint32(v41*4) + 2))) = uint16(v42)
				result = v54
				if v37 >= v54 {
					break
				}
			}
			v35 = v57
			v33 = v45
			v32 = v51
		}
		v32 += v35
		v33++
		v27 = (*int32)(unsafe.Add(unsafe.Pointer(v48), 4*1))
		v51 = v32
		v45 = v33
		v48 = (*int32)(unsafe.Add(unsafe.Pointer(v48), 4*1))
		if v33 >= 16 {
			break
		}
	}
	return result
}
func sub_57E2C0(this **uint32) int32 {
	var (
		v1     **uint32
		v2     *uint32
		v3     uint32
		v4     int32
		v5     int32
		v6     uint16
		v7     int32
		v8     *uint32
		v9     *uint8
		v10    int32
		v11    *uint32
		v12    int32
		v13    *byte
		v14    *uint32
		v15    int32
		v16    int8
		v17    int32
		v18    int32
		v19    uint32
		v20    int32
		v21    *uint8
		v22    uint32
		v23    *uint32
		v24    int32
		result int32
		v26    int32
		v27    [64]byte
	)
	v1 = this
	**(**uint32)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof((*uint32)(nil))*2)) = 2
	if int32(func() uint32 {
		p := *(**uint32)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof((*uint32)(nil))*2))
		*p--
		return *p
	}()) <= 0 {
		sub_57E2C0(this)
	}
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*1))))), unsafe.Sizeof(uint16(0))*272)))++
	v2 = *(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))
	v3 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)))))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(*v1), 4*2)))
	v5 = int32(*(*int16)(unsafe.Pointer(uintptr(v4 + 1088))))
	v6 = *(*uint16)(unsafe.Pointer(uintptr(v4 + 1090)))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v2))), v5))))
	v7 = int32(uint32(int32(v6)<<(32-int32(uint8(uintptr(unsafe.Pointer(v2))))-v5)) | v3)
	*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(v7)))
	if int32(uintptr(unsafe.Pointer(v2)))+v5 >= 16 {
		*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)))) = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v7))), 4-1))
		v8 = *(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))
		v9 = (*uint8)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3))))), 1))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer(v9))
		*v9 = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v8))), 2))
		v10 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*4))))))
		v11 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))))) << 16)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v10)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)) = v11
	}
	sub_57DFC0(*v1, (*int32)(unsafe.Pointer(&v27[0])))
	v12 = 0
	v13 = &v27[0]
	v26 = 16
	for {
		v14 = *(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))
		v15 = int32(*(*uint32)(unsafe.Pointer(v13)) - uint32(v12))
		v12 = int32(*(*uint32)(unsafe.Pointer(v13)))
		v16 = int8(32 - int32(uint8(uintptr(unsafe.Pointer(v14)))) - func() int32 {
			p := &v15
			*p++
			return *p
		}())
		v17 = int32(uintptr(unsafe.Pointer(v14))) + v15
		v18 = 1 << int32(v16)
		v19 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)))))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v17)))
		v20 = int32(uint32(v18) | v19)
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(v20)))
		if v17 >= 16 {
			*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)))) = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v20))), 4-1))
			v21 = (*uint8)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3))))), 1))
			v22 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))))) >> 16
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer(v21))
			*v21 = uint8(v22)
			v23 = *(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))
			v24 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*4))))))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v24)))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(v23))) << 16)))
		}
		v13 = (*byte)(unsafe.Add(unsafe.Pointer(v13), 4))
		result = func() int32 {
			p := &v26
			*p--
			return *p
		}()
		if v26 == 0 {
			break
		}
	}
	return result
}
func sub_57E7D0(this **uint32) int32 {
	var (
		v1 **uint32
		v2 *uint32
		v3 int32
		v4 *uint32
		v5 *uint8
		v6 int32
		v7 *uint32
		v8 *uint32
		v9 int32
	)
	v1 = this
	if int32(func() uint32 {
		p := *(**uint32)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof((*uint32)(nil))*2))
		*p--
		return *p
	}()) <= 0 {
		sub_57E2C0(this)
	}
	*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*1))))), unsafe.Sizeof(uint16(0))*273)))++
	v2 = *(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))
	v3 = int32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(*v1), 4*2)) + 1092))))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(uint32(int32(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(*v1), 4*2)) + 1094))))<<(32-int32(uint8(uintptr(unsafe.Pointer(v2))))-v3)) | uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))))))))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v2))), v3))))
	if int32(uintptr(unsafe.Pointer(v2)))+v3 >= 16 {
		*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)))) = uint8(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))))) >> 24)
		v4 = *(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))
		v5 = (*uint8)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3))))), 1))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer(v5))
		*v5 = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v4))), 2))
		v6 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*4))))))
		v7 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))))) << 16)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v6)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)) = v7
	}
	if int32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))))) > 0 {
		for {
			*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)))) = uint8(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))))) >> 24)
			v8 = *(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5))
			v9 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*2))))))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v9)))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(v8))) << 8)))
			if v9 <= 0 {
				break
			}
		}
	}
	return int32(uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*3)))))) - uintptr(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof((*uint32)(nil))*4)))))))
}
func sub_57E3F0(this **uint32, a2 uint32, a3 int32) uint32 {
	var (
		v3     *uint8
		result uint32
		v5     **uint32
		v6     bool
		v7     uint16
		v8     int32
		v9     *uint32
		v10    int32
		v11    uint16
		v12    int32
		v13    *uint32
		v14    *uint8
		v15    int32
		v16    *uint32
		v17    uint32
	)
	v3 = (*uint8)(unsafe.Pointer(uintptr(a2)))
	result = a2 + uint32(a3)
	v5 = this
	v6 = a2 < a2+uint32(a3)
	v17 = a2 + uint32(a3)
	if v6 {
		for {
			v7 = uint16(*v3)
			if int32(func() uint32 {
				p := *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*2))
				*p--
				return *p
			}()) <= 0 {
				sub_57E2C0(v5)
			}
			v8 = int32(v7)
			*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*1))))), unsafe.Sizeof(uint16(0))*uintptr(v7))))++
			v9 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))
			v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(*v5), 4*2)))
			v11 = *(*uint16)(unsafe.Pointer(uintptr(v10 + v8*4 + 2)))
			v12 = int32(*(*int16)(unsafe.Pointer(uintptr(v10 + v8*4))))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(uint32(int32(v11)<<(32-int32(uint8(uintptr(unsafe.Pointer(v9))))-v12)) | uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))))))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v9))), v12))))
			if int32(uintptr(unsafe.Pointer(v9)))+v12 >= 16 {
				*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)))) = uint8(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))) >> 24)
				v13 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))
				v14 = (*uint8)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))
				*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer(v14))
				*v14 = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v13))), 2))
				v15 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*4))))))
				v16 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))) << 16)))
				*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
				*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v15)))
				*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = v16
			}
			result = v17
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))
			if uint32(uintptr(unsafe.Pointer(v3))) >= v17 {
				break
			}
		}
	}
	return result
}
func sub_57F160(this int32, a2 int32, a3 int32) *uint32 {
	var (
		result *uint32
		v4     int32
		v5     *uint8
		v6     int32
		v7     int32
		v8     int32
	)
	result = (*uint32)(unsafe.Pointer(uintptr(this)))
	v4 = int32(*(*uint32)(unsafe.Pointer(uintptr(this + 24))))
	*(*uint32)(unsafe.Pointer(uintptr(this + 20))) |= uint32(a3 << (32 - v4 - a2))
	*(*uint32)(unsafe.Pointer(uintptr(this + 24))) = uint32(v4 + a2)
	if v4+a2 >= 16 {
		**(**uint8)(unsafe.Pointer(uintptr(this + 12))) = uint8(*(*uint32)(unsafe.Pointer(uintptr(this + 20))) >> 24)
		v5 = (*uint8)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(this + 12))) + 1)))
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*5)) >> 16)
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3)) = uint32(uintptr(unsafe.Pointer(v5)))
		*v5 = uint8(int8(v6))
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*5)))
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*6)) - 16)
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3))++
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*6)) = uint32(v8)
		*(*uint32)(unsafe.Add(unsafe.Pointer(result), 4*5)) = uint32(v7 << 16)
	}
	return result
}
func sub_57E4C0(this **uint32, a2 uint32, a3 int32, a4 uint32, a5 uint32) int32 {
	var (
		v5     **uint32
		v6     uint16
		v7     int32
		v8     *uint32
		v9     uint32
		v10    int32
		v11    int32
		v12    uint16
		v13    uint16
		v14    uint32
		v15    int32
		v16    int32
		v17    *uint32
		v18    int32
		v19    int32
		v20    uint32
		v21    int32
		v22    int32
		v23    *uint8
		v24    uint16
		v25    *uint32
		v26    int32
		v27    uint32
		v28    int32
		v29    int32
		v30    *uint32
		v31    *uint8
		v32    int32
		v33    *uint32
		v34    int32
		v35    uint32
		v36    *uint32
		v37    uint32
		v38    int32
		v39    int32
		v40    *uint32
		v41    *uint8
		v42    int32
		v43    *uint32
		v44    *uint32
		v45    int32
		result int32
		v47    *uint32
		v48    int8
		v49    int32
		v50    uint32
		v51    *uint32
		v52    *uint8
		v53    int32
	)
	v5 = this
	sub_57E3F0(this, a2, a3)
	if a4 >= 8 {
		if a4 >= 0x26 {
			v23 = (*uint8)(unsafe.Pointer(&nxzTable7[(a4-38)>>5]))
			v24 = uint16(nxzTable7[(a4-38)>>5][0] + 4)
			if int32(func() uint32 {
				p := *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*2))
				*p--
				return *p
			}()) <= 0 {
				sub_57E2C0(v5)
			}
			*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*1))))), unsafe.Sizeof(uint16(0))*uintptr(v24))))++
			sub_57F160(int32(uintptr(unsafe.Pointer(v5))), int32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(*v5), 4*2)) + uint32(int32(v24)*4))))), int32(*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(*v5), 4*2)) + uint32(int32(v24)*4) + 2)))))
			v25 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))
			v26 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v23))), 4*1))) + 4)
			v27 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)))))
			v28 = ((int32(uint8(a4))-38)&0x1F | int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v23))), unsafe.Sizeof(uint16(0))*4))))*16) << (32 - int32(uint8(uintptr(unsafe.Pointer(v25)))) - v26)
			v29 = int32(uintptr(unsafe.Pointer(v25))) + v26
			*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v29)))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(uint32(v28) | v27)))
			if v29 >= 16 {
				goto LABEL_14
			}
		} else {
			v13 = uint16(nxzTable7[(a4-8)>>1][0])
			v14 = (a4-8)&1 | nxzTable7[(a4-8)>>1][2]
			v15 = int32(nxzTable7[(a4-8)>>1][1])
			if int32(func() uint32 {
				p := *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*2))
				*p--
				return *p
			}()) <= 0 {
				sub_57E2C0(v5)
			}
			*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*1))))), unsafe.Sizeof(uint16(0))*uintptr(v13))))++
			v16 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(*v5), 4*2)))
			v17 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))
			v18 = v15 + int32(*(*int16)(unsafe.Pointer(uintptr(v16 + int32(v13)*4))))
			v19 = int32(*(*uint16)(unsafe.Pointer(uintptr(v16 + int32(v13)*4 + 2)))) << v15
			v20 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)))))
			v21 = int32(32 - uint32(uintptr(unsafe.Pointer(v17))) - uint32(v18))
			v22 = int32(uintptr(unsafe.Pointer(v17))) + v18
			*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v22)))
			*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(((v14 | uint32(v19)) << uint32(v21)) | v20)))
			if v22 >= 16 {
				goto LABEL_14
			}
		}
		goto LABEL_15
	} else {
		v6 = uint16(a4 + 256)
		if int32(func() uint32 {
			p := *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*2))
			*p--
			return *p
		}()) <= 0 {
			sub_57E2C0(v5)
		}
		v7 = int32(v6)
		*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*1))))), unsafe.Sizeof(uint16(0))*uintptr(v6))))++
		v8 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))
		v9 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)))))
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(*v5), 4*2)))
		v11 = int32(*(*int16)(unsafe.Pointer(uintptr(v10 + v7*4))))
		v12 = *(*uint16)(unsafe.Pointer(uintptr(v10 + v7*4 + 2)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v8))), v11))))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(uint32(int32(v12)<<(32-int32(uint8(uintptr(unsafe.Pointer(v8))))-v11)) | v9)))
		if int32(uintptr(unsafe.Pointer(v8)))+v11 >= 16 {
			goto LABEL_14
		}
		goto LABEL_15
	}
LABEL_14:
	*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)))) = uint8(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))) >> 24)
	v30 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))
	v31 = (*uint8)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer(v31))
	*v31 = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v30))), 2))
	v32 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*4))))))
	v33 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))) << 16)))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v32)))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = v33
LABEL_15:
	v34 = int32(nxzTable5[a5>>9][0] + 9)
	v35 = a5&0x1FF | nxzTable5[a5>>9][1]<<9
	if v34 <= 16 {
		v47 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))
		v48 = int8(32 - int32(uint8(uintptr(unsafe.Pointer(v47)))) - v34)
		v49 = int32(uintptr(unsafe.Pointer(v47))) + v34
		result = int32(v35 << uint32(v48))
		v50 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)))))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v49)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(uint32(result) | v50)))
		if v49 < 16 {
			return result
		}
		goto LABEL_21
	}
	v36 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))
	v37 = uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)))))
	v38 = int32(nxzTable5[a5>>9][0] - 7)
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(v36))), v38))))
	v39 = int32((v35 >> 16 << uint32(32-int32(uint8(uintptr(unsafe.Pointer(v36))))-v38)) | v37)
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(v39)))
	if int32(uintptr(unsafe.Pointer(v36)))+v38 >= 16 {
		*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)))) = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v39))), 4-1))
		v40 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))
		v41 = (*uint8)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer(v41))
		*v41 = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v40))), 2))
		v42 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*4))))))
		v43 = (*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))) << 16)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v42)))
		*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = v43
	}
	v44 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))
	v45 = int32(uint32(int32(uint16(v35))<<(16-int32(uint8(uintptr(unsafe.Pointer(v44)))))) | uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))))
	result = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v44), 4*4)))))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(v45)))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Add(unsafe.Pointer(v44), 4*4))
	if int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v44), 4*4))))) < 16 {
		return result
	}
LABEL_21:
	*(*uint8)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)))) = uint8(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))) >> 24)
	v51 = *(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))
	v52 = (*uint8)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer(v52))
	*v52 = *(*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Pointer(&v51))), 2))
	v53 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6))), -int(4*4))))))
	result = int32(uint32(uintptr(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5))))) << 16)
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3)) = (*uint32)(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(unsafe.Pointer(*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*3))))), 1))))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*6)) = (*uint32)(unsafe.Pointer(uintptr(v53)))
	*(**uint32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint32)(nil))*5)) = (*uint32)(unsafe.Pointer(uintptr(result)))
	return result
}
func nxz_compress(a1p unsafe.Pointer, a2p *uint8, a3p *uint8, a4p int32) int32 {
	var (
		this *unsafe.Pointer = (*unsafe.Pointer)(a1p)
		a2   int32           = int32(uintptr(unsafe.Pointer(a2p)))
		a3   *uint8          = a3p
		a4   int32           = a4p
		v4   *unsafe.Pointer
		v5   unsafe.Pointer
		v6   int32
		v7   *uint8
		v8   int32
		v9   int32
		v10  int32
		v11  int32
		v12  int32
		v13  *uint16
		v14  uint32
		v15  int32
		v16  *uint16
	)
	_ = v16
	var v17 int32
	var v18 int32
	var v19 int32
	var v20 int32
	var i *uint8
	var v22 int32
	var v23 int32
	var v24 int32
	var v25 int32
	var v26 int32
	var v27 int32
	var v28 *uint8
	var v29 int32
	var v30 int32
	var v31 uint8
	var v32 int32
	var v33 int32
	var v34 int32
	var v35 *byte
	var v36 int32
	var v37 int32
	var v38 int32
	var v39 *uint8
	var v40 *uint8
	var v41 *uint8
	var v42 uint32
	var v43 int32
	var v44 int32
	var v45 int32
	var v46 int32
	var v47 int32
	var v48 int32
	var v49 *byte
	var v50 *uint8
	var v51 uint32
	var v52 *byte
	var v53 *uint8
	var v54 int8
	var v55 int32
	var v56 int32
	var v57 int32
	var v58 *uint8
	var v59 int32
	var v60 int32
	var v61 *uint8
	var v62 uint32
	var v63 int32
	var v64 int32
	var v65 int32
	var v66 int32
	var v67 int32
	var v68 int32
	var v69 int32
	var v70 int32
	var v71 int32
	var v72 int32
	var v73 *uint8
	var v74 *uint8
	var v75 uint32
	var v76 int32
	var v77 int32
	var v78 int32
	var v79 int32
	var v80 int32
	var v81 *byte
	var v82 *uint8
	var v83 uint32
	var v84 *byte
	var v85 int32
	var v86 *uint8
	var v87 int32
	var v88 int32
	var v89 *uint8
	var v90 *uint8
	var v91 uint32
	var v92 int32
	var v93 int32
	var v94 int32
	var v95 int32
	var v96 int32
	var v97 int32
	var v98 int32
	var v99 int32
	var v100 int32
	var v101 *uint8
	var v102 int32
	var v103 int32
	var v104 *uint8
	var v105 uint32
	var v106 int32
	var v107 *uint8
	var v108 int32
	var v110 int32
	var v111 int32
	var v112 int32
	var v113 int32
	var v114 int32
	var v115 int32
	var v116 int32
	var v117 int32
	var v118 *uint8
	var v119 int32
	var v120 int32
	var v121 int32
	var v122 uint16
	var v123 int32
	var v124 int32
	var v125 int32
	var v126 int32
	var v127 int32
	var v128 int16
	var v129 int32
	var v130 int32
	var v131 int32
	var v132 int32
	var v133 unsafe.Pointer
	var v134 int32
	var v135 [10]int32
	var v136 int32
	var v137 *uint8
	var v138 *uint8
	var v139 *uint8
	var v140 *uint8
	var v141 int32
	var v142 *uint8
	var v143 *uint8
	v4 = this
	v5 = *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(this), unsafe.Sizeof(unsafe.Pointer(nil))*2))
	v135[0] = int32(uintptr(unsafe.Pointer((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*2)))))
	v135[2] = int32(uintptr(unsafe.Pointer((*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*3)))))
	v135[4] = a2
	v135[3] = a2
	v6 = 0
	v135[1] = int32(uintptr(v5))
	v135[5] = 0
	v135[6] = 0
	v135[9] = 0
	v136 = 0
	v118 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), a4))
	if uint32(a4) >= 5 {
		v7 = a3
		if uintptr(unsafe.Pointer(a3)) < uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(a3), 5)))) {
			for {
				v8 = int32(*func() *uint8 {
					p := &v7
					x := *p
					*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
					return x
				}())
				v6 = int32(__ROL4__(uint32(v8^v6), 5))
				if uintptr(unsafe.Pointer(v7)) >= uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(a3), 5)))) {
					break
				}
			}
			v136 = v6
		}
	}
	v9 = a4
	v111 = a4
	if a4 < 5 {
		goto LABEL_144
	}
	v10 = v136
	for 2 != 0 {
		v11 = 0
		v126 = v9 - 5
		if v9-5 >= 64 {
			v126 = 64
		}
		v110 = 0
		v125 = 0
		for {
			*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v15))), unsafe.Sizeof(uint16(0))*1)) = 0
			v12 = 0
			v13 = (*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*5)))
			v14 = (uint32(v10)*214013 + 2531011) >> 17
			*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v15))), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(uint16(0))*uintptr(v14)))
			v16 = (*uint16)(unsafe.Add(unsafe.Pointer(v13), unsafe.Sizeof(uint16(0))*uintptr(v14)))
			v17 = int32(uint32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) & math.MaxUint16)
			v117 = v17
			*v16 = uint16(int16(v17))
			if int32(uint16(int16(v15))) == math.MaxUint16 || v15 == v17 {
				goto LABEL_62
			}
			v18 = int32(uint16(int16(v17 - v15)))
			v19 = v18
			if v18 >= v111-v11 {
				v19 = v111 - v11
			}
			if v19 >= 521 {
				v18 = 521
			} else if v18 >= v111-v11 {
				v18 = v111 - v11
			}
			v112 = v18
			v138 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
			v119 = int32(0x10000 - uint32(v15))
			if 0x10000-uint32(v15) < uint32(v18) {
				v22 = v15
				if uint32(v15) < 0x10000 {
					for int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(*v4)), v22)))) == int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v138), v22-v15))) {
						if uint32(func() int32 {
							p := &v22
							*p++
							return *p
						}()) >= 0x10000 {
							v10 = v136
							goto LABEL_33
						}
					}
					v10 = v136
					v12 = v22 - v15
					goto LABEL_24
				}
			LABEL_33:
				v23 = 0
				if uint32(v18+v15)-0x10000 <= 0 {
					v12 = v18
					goto LABEL_24
				}
				for int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(*v4)), v23)))) == int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v138), v119+v23))) {
					v18 = v112
					if uint32(func() int32 {
						p := &v23
						*p++
						return *p
					}()) >= uint32(v112+v15)-0x10000 {
						v12 = v18
						goto LABEL_24
					}
				}
				v12 = v119 + v23
			} else {
				v12 = 0
				if v18 <= 0 {
					v12 = v18
					goto LABEL_24
				}
				for int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(*v4)), v15))), v12)))) == int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), v11+v12))) {
					v18 = v112
					if func() int32 {
						p := &v12
						*p++
						return *p
					}() >= v112 {
						v12 = v18
						goto LABEL_24
					}
				}
			}
		LABEL_24:
			if int32(uint16(int16(v15+v12))) == v117 {
				v20 = v111 + (-v12) - v11
				if 521-v12 < v20 {
					v20 = 521 - v12
				}
				v120 = v20
				v113 = 0
				if v20 > 0 {
					for i = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11)); int32(*i) == int32(*(*uint8)(unsafe.Add(unsafe.Pointer(i), v12))); i = (*uint8)(unsafe.Add(unsafe.Pointer(i), 1)) {
						if func() int32 {
							p := &v113
							*p++
							return *p
						}() >= v120 {
							break
						}
					}
				}
				v12 += v113
			}
			if v12 >= 3 {
				v114 = 521 - v12
				if 521-v12 >= v11 {
					v114 = v11
				}
				v24 = int32(uint16(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), -v15))))))
				if v114 >= v24-v12 {
					v121 = int32(uint16(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), -v15)))))) - v12
				} else {
					v121 = v114
				}
				v25 = int32(0x10000 - uint32(v24))
				if uint32(v121) < 0x10000-uint32(v24) {
					v25 = v114
					if v114 < v24-v12 {
						goto LABEL_53
					}
					v25 = int32(uint16(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), -v15)))))) - v12
				}
				v114 = v25
			LABEL_53:
				v26 = 0
				if v25 <= 0 {
					v10 = v136
					goto LABEL_62
				}
				v122 = uint16(int16(v15 - 1))
				v139 = (*uint8)(unsafe.Add(unsafe.Pointer(v138), -1))
				for {
					if int32(*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(*v4)), v122)))) != int32(*v139) {
						break
					}
					v26++
					v122--
					v139 = (*uint8)(unsafe.Add(unsafe.Pointer(v139), -1))
					if v26 >= v114 {
						break
					}
				}
				if v26 <= 0 {
					v10 = v136
				} else {
					v11 -= v26
					v27 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) - v26
					*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v15))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v15 - v26))
					v12 += v26
					*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Pointer(uintptr(v27))
					v28 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
					*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v117))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v27))
					v10 = 0
					if uintptr(unsafe.Pointer(v28)) < uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v28), 5)))) {
						for {
							v29 = int32(*func() *uint8 {
								p := &v28
								x := *p
								*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
								return x
							}()) ^ v10
							v10 = int32(__ROL4__(uint32(v29), 5))
							if uintptr(unsafe.Pointer(v28)) >= uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(a3), v11+5)))) {
								break
							}
						}
					}
					v136 = v10
					v125 = 1
				}
				goto LABEL_62
			}
		LABEL_62:
			v30 = v110
			if v110 >= 4 {
				v115 = v11
				if v12 <= v110 {
					*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = v133
					v137 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v127))
					v55 = int32(__ROL4__(uint32(v134^int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), v127+5))))^__ROL4__(uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), v127))), 25), 5))
					sub_57E4C0((**uint32)(unsafe.Pointer(&v135[0])), uint32(uintptr(unsafe.Pointer(a3))), v127, uint32(v110-4), uint32(uint16(int16(int32(uint16(uintptr(v133)))-int32(v128)))))
					v56 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v118), -v127)))) - uintptr(unsafe.Pointer(a3)))
					v57 = v110 - 2
					if v110-2 >= v56-2 {
						v57 = v56 - 2
					}
					v58 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v127))
					v59 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 2
					v141 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 2
					if v57 > 0 {
						if v57 <= 1024 {
							v64 = int32(__ROL4__(uint32(v55^int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v137), 6))))^__ROL4__(uint32(*(*uint8)(unsafe.Add(unsafe.Pointer(v137), 1))), 25), 5))
							v65 = 0
							v130 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v137), 7)))))
							for {
								*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*5)))), unsafe.Sizeof(uint16(0))*uintptr((uint32(v64)*214013+2531011)>>17)))) = uint16(int16(v65 + v59))
								v66 = int32(*(*uint8)(unsafe.Pointer(uintptr(v130 + v65))))
								v67 = int32(__ROL4__(uint32(*(*uint8)(unsafe.Pointer(uintptr(v130 + func() int32 {
									p := &v65
									x := *p
									*p++
									return x
								}() - 5)))), 25))
								v64 = int32(__ROL4__(uint32(v64^v66^v67), 5))
								if v65 >= v57 {
									break
								}
								*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v59))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v141))
							}
							v58 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v127))
							v136 = v64
						} else {
							v60 = 0
							v61 = (*uint8)(unsafe.Add(unsafe.Pointer(v137), v57+2))
							v62 = uint32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v61), 5)))))
							if uintptr(unsafe.Pointer(v61)) < uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v61), 5)))) {
								for {
									v63 = int32(*func() *uint8 {
										p := &v61
										x := *p
										*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
										return x
									}())
									v60 = int32(__ROL4__(uint32(v63^v60), 5))
									if uint32(uintptr(unsafe.Pointer(v61))) >= v62 {
										break
									}
								}
							}
							v136 = v60
						}
					} else {
						v136 = 0
					}
					v68 = int32(uint32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) & math.MaxUint16)
					if uint32(v68+v110) <= 0x10000 {
						v69 = v110
						memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v68), unsafe.Pointer(v58), int(v110))
					} else {
						memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v68), unsafe.Pointer(v58), int(0x10000-uint32(v68)))
						v69 = v110
						memcpy(*v4, unsafe.Add(unsafe.Pointer(v58), 0x10000-uint32(v68)), int(uint32(v110)-(0x10000-uint32(v68))))
					}
					*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), v69)
					a3 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v69+v127))
					goto LABEL_143
				}
				sub_57E4C0((**uint32)(unsafe.Pointer(&v135[0])), uint32(uintptr(unsafe.Pointer(a3))), v11, uint32(v12-4), uint32(uint16(int16(v117-v15))))
				v36 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v118), -v11))))-uintptr(unsafe.Pointer(a3))) - 1
				if v12-1 < v36 {
					v36 = v12 - 1
				}
				v37 = 0
				v38 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 1
				v39 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
				v123 = v36
				v129 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 1
				v140 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
				v40 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
				if v36 > 0 {
					if v36 <= 1024 {
						v44 = int32(__ROL4__(uint32(v136^int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v40), 5))))^__ROL4__(uint32(*v40), 25), 5))
						v45 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v40), 1)))))
						if v123 > 0 {
							for {
								*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*5)))), unsafe.Sizeof(uint16(0))*uintptr((uint32(v44)*214013+2531011)>>17)))) = uint16(int16(v37 + v38))
								v46 = int32(uint32(v44^int32(*(*uint8)(unsafe.Pointer(uintptr(v45 + 5 + v37))))) ^ __ROL4__(uint32(*(*uint8)(unsafe.Pointer(uintptr(v45 + v37)))), 25))
								v37++
								v44 = int32(__ROL4__(uint32(v46), 5))
								if v37 >= v123 {
									break
								}
								*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v38))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v129))
							}
						}
						v136 = v44
					} else {
						v41 = (*uint8)(unsafe.Add(unsafe.Pointer(v40), v36+1))
						v42 = uint32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v41), 5)))))
						if uintptr(unsafe.Pointer(v41)) < uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v41), 5)))) {
							for {
								v43 = int32(*func() *uint8 {
									p := &v41
									x := *p
									*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
									return x
								}())
								v37 = int32(__ROL4__(uint32(v43^v37), 5))
								if uint32(uintptr(unsafe.Pointer(v41))) >= v42 {
									break
								}
							}
						}
						v136 = v37
					}
					v39 = v140
				} else {
					v136 = 0
				}
				v47 = int32(uint32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) & math.MaxUint16)
				if uint32(v47+v12) > 0x10000 {
					v48 = int32(0x10000 - uint32(v47))
					memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v47), unsafe.Pointer(v39), int(0x10000-uint32(v47)))
					v49 = (*byte)(*v4)
					v50 = (*uint8)(unsafe.Add(unsafe.Pointer(v140), v48))
					v51 = uint32(v12 - v48)
					memcpy(*v4, unsafe.Pointer(v50), int((v51>>2)*4))
					v53 = (*uint8)(unsafe.Add(unsafe.Pointer(v50), (v51>>2)*4))
					v52 = (*byte)(unsafe.Add(unsafe.Pointer(v49), (v51>>2)*4))
					v54 = int8(uint8(v51))
				} else {
					v84 = (*byte)(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v47))
					memcpy(unsafe.Pointer(v84), unsafe.Pointer(v39), int((uint32(v12)>>2)*4))
					v53 = (*uint8)(unsafe.Add(unsafe.Pointer(v39), (uint32(v12)>>2)*4))
					v52 = (*byte)(unsafe.Add(unsafe.Pointer(v84), (uint32(v12)>>2)*4))
					v54 = int8(v12)
				}
				memcpy(unsafe.Pointer(v52), unsafe.Pointer(v53), int(int32(v54)&3))
				*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), v12)
				a3 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v115+v12))
				goto LABEL_143
			}
			if v12 < 4 {
				goto LABEL_66
			}
			if v125 != 0 {
				v115 = v11
				sub_57E4C0((**uint32)(unsafe.Pointer(&v135[0])), uint32(uintptr(unsafe.Pointer(a3))), v11, uint32(v12-4), uint32(uint16(int16(v117-v15))))
				v70 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v118), -v11))))-uintptr(unsafe.Pointer(a3))) - 1
				if v12-1 < v70 {
					v70 = v12 - 1
				}
				v71 = 0
				v72 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 1
				v39 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
				v124 = v70
				v131 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 1
				v142 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
				v73 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
				if v70 > 0 {
					if v70 <= 1024 {
						v77 = int32(__ROL4__(uint32(v136^int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v73), 5))))^__ROL4__(uint32(*v73), 25), 5))
						v78 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v73), 1)))))
						if v124 > 0 {
							for {
								*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*5)))), unsafe.Sizeof(uint16(0))*uintptr((uint32(v77)*214013+2531011)>>17)))) = uint16(int16(v71 + v72))
								v79 = int32(uint32(v77^int32(*(*uint8)(unsafe.Pointer(uintptr(v78 + 5 + v71))))) ^ __ROL4__(uint32(*(*uint8)(unsafe.Pointer(uintptr(v78 + v71)))), 25))
								v71++
								v77 = int32(__ROL4__(uint32(v79), 5))
								if v71 >= v124 {
									break
								}
								*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v72))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v131))
							}
						}
						v136 = v77
					} else {
						v74 = (*uint8)(unsafe.Add(unsafe.Pointer(v73), v70+1))
						v75 = uint32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v74), 5)))))
						if uintptr(unsafe.Pointer(v74)) < uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v74), 5)))) {
							for {
								v76 = int32(*func() *uint8 {
									p := &v74
									x := *p
									*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
									return x
								}())
								v71 = int32(__ROL4__(uint32(v76^v71), 5))
								if uint32(uintptr(unsafe.Pointer(v74))) >= v75 {
									break
								}
							}
						}
						v136 = v71
					}
					v39 = v142
				} else {
					v136 = 0
				}
				v47 = int32(uint32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) & math.MaxUint16)
				if uint32(v47+v12) > 0x10000 {
					v80 = int32(0x10000 - uint32(v47))
					memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v47), unsafe.Pointer(v39), int(0x10000-uint32(v47)))
					v81 = (*byte)(*v4)
					v82 = (*uint8)(unsafe.Add(unsafe.Pointer(v142), v80))
					v83 = uint32(v12 - v80)
					memcpy(*v4, unsafe.Pointer(v82), int((v83>>2)*4))
					v53 = (*uint8)(unsafe.Add(unsafe.Pointer(v82), (v83>>2)*4))
					v52 = (*byte)(unsafe.Add(unsafe.Pointer(v81), (v83>>2)*4))
					v54 = int8(uint8(v83))
				} else {
					v84 = (*byte)(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v47))
					memcpy(unsafe.Pointer(v84), unsafe.Pointer(v39), int((uint32(v12)>>2)*4))
					v53 = (*uint8)(unsafe.Add(unsafe.Pointer(v39), (uint32(v12)>>2)*4))
					v52 = (*byte)(unsafe.Add(unsafe.Pointer(v84), (uint32(v12)>>2)*4))
					v54 = int8(v12)
				}
				memcpy(unsafe.Pointer(v52), unsafe.Pointer(v53), int(int32(v54)&3))
				*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), v12)
				a3 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v115+v12))
				goto LABEL_143
			}
			v30 = v12
			v110 = v12
			v128 = int16(v15)
			v127 = v11
			v133 = *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1))
			v134 = v10
		LABEL_66:
			if v11+1 > v126 {
				break
			}
			v31 = *(*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
			v32 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), v11+5)))
			v33 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(a3), func() int32 {
				p := &v11
				x := *p
				*p++
				return x
			}())))
			v34 = int32(uint32(v32) ^ __ROL4__(uint32(v33), 25))
			v35 = (*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))
			v10 = int32(__ROL4__(uint32(v10^v34), 5))
			*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Add(unsafe.Pointer(v35), 1)
			v136 = v10
			*((*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(*v4)), uint16(uintptr(unsafe.Pointer(v35)))))) = v31
		}
		v116 = v11
		if v30 < 4 {
			if v11+5 >= v111 && v111 <= 64 {
				v100 = v111 - v11
				v101 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
				v102 = int32(uint32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) & math.MaxUint16)
				if uint32(v102+v100) <= 0x10000 {
					v105 = uint32(v100)
					v104 = (*uint8)(unsafe.Add(unsafe.Pointer((*uint8)(*v4)), v102))
				} else {
					v103 = int32(0x10000 - uint32(v102))
					memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v102), unsafe.Pointer(v101), int(0x10000-uint32(v102)))
					v104 = (*uint8)(*v4)
					v105 = uint32(v100 - v103)
					v101 = (*uint8)(unsafe.Add(unsafe.Pointer(v101), v103))
				}
				memcpy(unsafe.Pointer(v104), unsafe.Pointer(v101), int(v105))
				*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), v100)
				v11 = v111
			}
			sub_57E3F0((**uint32)(unsafe.Pointer(&v135[0])), uint32(uintptr(unsafe.Pointer(a3))), v11)
			a3 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
		} else {
			sub_57E4C0((**uint32)(unsafe.Pointer(&v135[0])), uint32(uintptr(unsafe.Pointer(a3))), v11, uint32(v110-4), uint32(uint16(uintptr(unsafe.Pointer((*byte)(unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), -v128)))))))
			v85 = v110 - 1
			if v110-1 >= int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v118), -v11))))-uintptr(unsafe.Pointer(a3)))-1 {
				v85 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v118), -v11))))-uintptr(unsafe.Pointer(a3))) - 1
			}
			v86 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
			v87 = 0
			v88 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 1
			v132 = int32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) + 1
			v143 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
			v89 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v11))
			if v85 > 0 {
				if v85 <= 1024 {
					v93 = int32(uint32(v136^int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v89), 5)))) ^ __ROL4__(uint32(*v86), 25))
					v94 = int32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v89), 1)))))
					v95 = int32(__ROL4__(uint32(v93), 5))
					for {
						*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*5)))), unsafe.Sizeof(uint16(0))*uintptr((uint32(v95)*214013+2531011)>>17)))) = uint16(int16(v87 + v88))
						v96 = int32(*(*uint8)(unsafe.Pointer(uintptr(v94 + 5 + v87))))
						v97 = int32(__ROL4__(uint32(*(*uint8)(unsafe.Pointer(uintptr(v94 + func() int32 {
							p := &v87
							x := *p
							*p++
							return x
						}())))), 25))
						v95 = int32(__ROL4__(uint32(v95^v96^v97), 5))
						if v87 >= v85 {
							break
						}
						*(*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(&v88))), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(v132))
					}
					v86 = v143
					v136 = v95
				} else {
					v90 = (*uint8)(unsafe.Add(unsafe.Pointer(v86), v85+1))
					v91 = uint32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v90), 5)))))
					if uintptr(unsafe.Pointer(v90)) < uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v90), 5)))) {
						for {
							v92 = int32(*func() *uint8 {
								p := &v90
								x := *p
								*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
								return x
							}())
							v87 = int32(__ROL4__(uint32(v92^v87), 5))
							if uint32(uintptr(unsafe.Pointer(v90))) >= v91 {
								break
							}
						}
					}
					v136 = v87
				}
			} else {
				v136 = 0
			}
			v98 = int32(uint32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) & math.MaxUint16)
			if uint32(v98+v110) <= 0x10000 {
				v99 = v110
				memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v98), unsafe.Pointer(v86), int(v110))
			} else {
				memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v98), unsafe.Pointer(v86), int(0x10000-uint32(v98)))
				v99 = v110
				memcpy(*v4, unsafe.Add(unsafe.Pointer(v86), 0x10000-uint32(v98)), int(uint32(v110)-(0x10000-uint32(v98))))
			}
			*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), v99)
			a3 = (*uint8)(unsafe.Add(unsafe.Pointer(a3), v116+v99))
		}
	LABEL_143:
		v9 = int32(uintptr(unsafe.Pointer(v118)) - uintptr(unsafe.Pointer(a3)))
		v111 = int32(uintptr(unsafe.Pointer(v118)) - uintptr(unsafe.Pointer(a3)))
		if int32(uintptr(unsafe.Pointer(v118))-uintptr(unsafe.Pointer(a3))) >= 5 {
			v10 = v136
			continue
		}
		break
	}
LABEL_144:
	if v111 != 0 {
		v106 = int32(uint32(uintptr(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))) & math.MaxUint16)
		if uint32(v106+v111) <= 0x10000 {
			v108 = v111
			memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v106), unsafe.Pointer(a3), int(v111))
			v107 = a3
		} else {
			v107 = a3
			memcpy(unsafe.Add(unsafe.Pointer((*byte)(*v4)), v106), unsafe.Pointer(a3), int(0x10000-uint32(v106)))
			v108 = v111
			memcpy(*v4, unsafe.Add(unsafe.Pointer(a3), 0x10000-uint32(v106)), int(uint32(v111)-(0x10000-uint32(v106))))
		}
		*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)) = unsafe.Add(unsafe.Pointer((*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(unsafe.Pointer(nil))*1)))), v108)
		sub_57E3F0((**uint32)(unsafe.Pointer(&v135[0])), uint32(uintptr(unsafe.Pointer(v107))), v108)
	}
	return sub_57E7D0((**uint32)(unsafe.Pointer(&v135[0])))
}
