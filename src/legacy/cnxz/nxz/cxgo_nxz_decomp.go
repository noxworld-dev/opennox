package nxz

import (
	"math"
	"unsafe"
)

func sub57DDE0(a1 *int16, a2 int32) {
	v2 := a1
	v3 := a2
	for i := int32(40); i > 0; i /= 3 {
		v5 := i + 1
		v11 := i + 1
		if i+1 <= v3 {
			for {
				v6 := v5 * 4
				v10 := v5
				v12 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), v5*4)))
				if v5 > i {
					v7 := i * 4
					for {
						v8 := int32(*(*int16)(unsafe.Add(unsafe.Pointer(v2), uintptr(v6-v7)+2))) - int32(*(*int16)(unsafe.Add(unsafe.Pointer(&v12), unsafe.Sizeof(int16(0))*1)))
						if v8 == 0 {
							v8 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(v2), uintptr(v6-v7)))) - int32(int16(v12))
						}
						if v8 >= 0 {
							break
						}
						*(*uint32)(unsafe.Add(unsafe.Pointer(v2), uintptr(v6))) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), uintptr(v6-v7)))
						v6 -= v7
						v10 -= i
						if v10 <= i {
							break
						}
					}
					v5 = v11
				}
				v5++
				*(*uint32)(unsafe.Add(unsafe.Pointer(v2), uintptr(v10*4))) = uint32(v12)
				v3 = a2
				v11 = v5
				if v5 > a2 {
					break
				}
			}
		}
	}
}
func sub57DEA0(d *decoderData, arr []decoderRec) int {
	it := arr
	n := 0
	for i := range d.field0.field0 {
		p := &d.field0.field0[i]
		it[0] = decoderRec{ind0: int16(i), val2: *p}
		it = it[1:]
		n += int(*p)
		*p /= 2
	}
	sub57DDE0((*int16)(unsafe.Add(unsafe.Pointer(&arr[0]), -4)), tableSize3)
	return n
}
func nxz_decompress(dec *Decoder, dst []byte, dstSz *int, src []byte, srcSz *int) int {
	var (
		v8  int32
		v9  int32
		v10 int32
		v11 uint32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v22 int32
		v23 *uint32
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 int32
		v31 int32
		v32 int32
		v33 int32
		v34 int32
		v35 int32
		v36 uint32
		v37 int32
		v38 int32
		v39 int32
		v40 int32
		v41 uint32
		v42 int32
		v43 int32
		v44 int32
		v45 *uint8
		v46 int32
		v47 int32
		v48 int32
		v49 int32
		v50 int32
		v51 int32
		v52 unsafe.Pointer
		v53 uint32
		v54 int32
		v55 int32
		v56 *uint8
		v57 int32
		v58 int32
		v59 unsafe.Pointer
		v60 uint32
		v61 *uint8
		v63 int32
		i   int32
		v65 int32
		v66 int32
		v67 int32
		v68 *uint8
		v70 int32
		v71 int32
		v75 [tableSize3]decoderRec
	)
	dstPtr := &dst[0]
	srcPtr := &src[0]
	srcPtr2 := srcPtr
	decP := unsafe.Pointer(dec)
	srcPtrEnd := unsafe.Add(unsafe.Pointer(srcPtr), *srcSz)
	dstBase := dstPtr
	srcBase := srcPtr
	srcPtrEnd2 := srcPtrEnd
	dstPtrEnd := unsafe.Add(unsafe.Pointer(dstPtr), *dstSz)
	dec.field148 = 0
	if uintptr(unsafe.Pointer(srcPtr)) >= uintptr(srcPtrEnd) {
		return 0
	}
	for {
		v8 = int32(dec.field148)
		if v8 < 4 {
			if uintptr(unsafe.Pointer(srcPtr2)) >= uintptr(srcPtrEnd) {
				v9 = -1
				dec.field148 = 0
				v63 = -1
				goto LABEL_9
			}
			v10 = int32(uint32(int32(*func() *uint8 {
				p := &srcPtr2
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v8)) | dec.field144)
			dec.field144 = uint32(v10)
			srcPtr = srcPtr2
			dec.field148 = uint32(v8 + 8)
		}
		v11 = dec.field144
		dec.field144 = v11 * 16
		v63 = int32(v11 >> 28)
		dec.field148 -= 4
		v9 = int32(v11 >> 28)
	LABEL_9:
		v12 = int32(*(*uint32)(unsafe.Add(decP, 4*uintptr(v9*2+3))))
		if v12 == 0 {
			v13 = int32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(decP, 4*35)) + *(*uint32)(unsafe.Add(decP, 4*uintptr(v9*2+4)))*2))))
			goto LABEL_18
		}
		v14 = int32(dec.field148)
		if v14 >= v12 {
			v15 = int32(dec.field144 >> uint32(32-v12))
			dec.field144 <<= uint32(v12)
			dec.field148 -= uint32(v12)
			v9 = v63
		} else if uintptr(unsafe.Pointer(srcPtr2)) < uintptr(srcPtrEnd) {
			v16 = int32(uint32(int32(*func() *uint8 {
				p := &srcPtr2
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v14)) | dec.field144)
			dec.field144 = uint32(v16)
			srcPtr = srcPtr2
			dec.field148 = uint32(v14 + 8)
			v15 = int32(dec.field144 >> uint32(32-v12))
			dec.field144 <<= uint32(v12)
			dec.field148 -= uint32(v12)
			v9 = v63
		} else {
			dec.field148 = 0
			v15 = -1
		}
		v17 = int32(uint32(v15) + *(*uint32)(unsafe.Add(decP, 4*uintptr(v9*2+4))))
		if v17 >= tableSize3 {
			return 0
		}
		v13 = int32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(decP, 4*35)) + uint32(v17*2)))))
	LABEL_18:
		*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(decP, 4*2)) + uint32(v13*2))))++
		if v13 < 256 {
			if uintptr(unsafe.Pointer(dstPtr)) >= uintptr(unsafe.Pointer(dstPtrEnd)) {
				return 0
			}
			*func() *uint8 {
				p := &dstPtr
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}() = uint8(int8(v13))
			v18 = int32(dec.field4)
			dec.field4 = uint32(v18 + 1)
			*(*uint8)(unsafe.Pointer(uintptr(uint32(uint16(int16(v18))) + *((*uint32)(decP))))) = uint8(int8(v13))
			goto LABEL_73
		}
		if v13 == 272 {
			sub57DEA0(&dec.data8, v75[:])
			v19 = 0
			v20 := v75[:]
			for {
				v21 := v20[0]
				v20 = v20[1:]
				*(*int16)(unsafe.Add(unsafe.Pointer(dec.data8.field132), uintptr(uint32(v19)))) = v21.ind0
				v19 += 2
				if v19 >= 548 {
					break
				}
			}
			v22 = 0
			v23 = (*uint32)(unsafe.Add(decP, 4*4))
			v70 = 0
			v66 = 16
			for {
				for i = 0; ; i++ {
					v24 = int32(dec.field148)
					if v24 >= 1 {
						goto LABEL_29
					}
					if uintptr(unsafe.Pointer(srcPtr2)) >= uintptr(srcPtrEnd2) {
						break
					}
					v25 = int32(uint32(int32(*func() *uint8 {
						p := &srcPtr2
						x := *p
						*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
						return x
					}())<<(24-v24)) | dec.field144)
					dec.field144 = uint32(v25)
					dec.field148 = uint32(v24 + 8)
				LABEL_29:
					v26 = int32(dec.field144 >> 31)
					v27 = int32(dec.field148 - 1)
					dec.field144 *= 2
					dec.field148 = uint32(v27)
					if v26 != 0 {
						goto LABEL_32
					}
				}
				dec.field148 = 0
			LABEL_32:
				v22 += i
				*((*uint32)(unsafe.Add(unsafe.Pointer(v23), -int(4*1)))) = uint32(v22)
				*v23 = uint32(v70)
				v23 = (*uint32)(unsafe.Add(unsafe.Pointer(v23), 4*2))
				v70 += 1 << v22
				if func() int32 {
					p := &v66
					*p--
					return *p
				}() == 0 {
					srcPtr = srcPtr2
					goto LABEL_73
				}
			}
		}
		if v13 == 273 {
			break
		}
		if v13 < 264 {
			v28 = v13 - 256
			goto LABEL_43
		}
		v29 = int32(nxz_table_1[v13].v1)
		v30 = int32(dec.field148)
		if v30 >= v29 {
			v31 = int32(dec.field144 >> uint32(32-v29))
			v33 = int32(dec.field144 << uint32(v29))
			dec.field148 -= uint32(v29)
			dec.field144 = uint32(v33)
		} else if uintptr(unsafe.Pointer(srcPtr2)) < uintptr(srcPtrEnd2) {
			v32 = int32(uint32(int32(*func() *uint8 {
				p := &srcPtr2
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v30)) | dec.field144)
			dec.field144 = uint32(v32)
			srcPtr = srcPtr2
			dec.field148 = uint32(v30 + 8)
			v31 = int32(dec.field144 >> uint32(32-v29))
			v33 = int32(dec.field144 << uint32(v29))
			dec.field148 -= uint32(v29)
			dec.field144 = uint32(v33)
		} else {
			dec.field148 = 0
			v31 = -1
		}
		v28 = int32(uint32(v31) + nxz_table_1[v13].v2)
	LABEL_43:
		v34 = int32(dec.field148)
		v67 = v28
		if v34 < 3 {
			if uintptr(unsafe.Pointer(srcPtr2)) >= uintptr(srcPtrEnd2) {
				dec.field148 = 0
				v71 = -1
				goto LABEL_48
			}
			v35 = int32(uint32(int32(*func() *uint8 {
				p := &srcPtr2
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v34)) | dec.field144)
			dec.field144 = uint32(v35)
			srcPtr = srcPtr2
			dec.field148 = uint32(v34 + 8)
		}
		v36 = dec.field144
		dec.field144 = v36 * 8
		v71 = int32(v36 >> 29)
		dec.field148 -= 3
	LABEL_48:
		v65 = 0
		v37 = int32(nxz_table_2[v71+1].v1 + 9)
		if v37 <= 8 {
			goto LABEL_55
		}
		v38 = int32(dec.field148)
		v37 = int32(nxz_table_2[v71+1].v1 + 1)
		if v38 >= 8 {
			v41 = dec.field144
			dec.field144 = v41 << 8
			dec.field148 -= 8
			v39 = int32(v41 >> 24)
		} else if uintptr(unsafe.Pointer(srcPtr2)) < uintptr(srcPtrEnd2) {
			v40 = int32(uint32(int32(*func() *uint8 {
				p := &srcPtr2
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v38)) | dec.field144)
			dec.field144 = uint32(v40)
			srcPtr = srcPtr2
			dec.field148 = uint32(v38 + 8)
			v41 = dec.field144
			dec.field144 = v41 << 8
			dec.field148 -= 8
			v39 = int32(v41 >> 24)
		} else {
			dec.field148 = 0
			v39 = -1
		}
		v65 = v39 << v37
	LABEL_55:
		v42 = int32(dec.field148)
		if v42 >= v37 {
			v43 = int32(dec.field144 >> uint32(32-v37))
			v44 = int32(dec.field144 << uint32(v37))
			dec.field148 -= uint32(v37)
			dec.field144 = uint32(v44)
		} else if uintptr(unsafe.Pointer(srcPtr2)) < uintptr(srcPtrEnd2) {
			dec.field144 |= uint32(int32(*srcPtr2) << (24 - v42))
			srcPtr = (*byte)(unsafe.Add(unsafe.Pointer(srcPtr2), 1))
			dec.field148 = uint32(v42 + 8)
			v43 = int32(dec.field144 >> uint32(32-v37))
			v44 = int32(dec.field144 << uint32(v37))
			dec.field148 -= uint32(v37)
			dec.field144 = uint32(v44)
		} else {
			dec.field148 = 0
			v43 = -1
		}
		v45 = dstPtr
		v46 = int32((nxz_table_2[v71+1].v2 << 9) + uint32(v65|v43))
		v47 = v67 + 4
		v68 = (*uint8)(unsafe.Add(unsafe.Pointer(dstPtr), v67+4))
		if uintptr(unsafe.Pointer(v68)) > uintptr(unsafe.Pointer(dstPtrEnd)) {
			return 0
		}
		v48 = int32(dec.field4 - uint32(v46))
		if v47 >= v46 {
			v50 = int32(uint16(int16(v48)))
			if uint32(int32(uint16(int16(v48)))+v46) <= 0x10000 {
				v53 = uint32(v46)
				v52 = unsafe.Pointer(uintptr(*((*uint32)(decP)) + uint32(v50)))
			} else {
				v51 = int32(0x10000 - uint32(uint16(int16(v48))))
				memcpy(unsafe.Pointer(dstPtr), unsafe.Pointer(uintptr(*((*uint32)(decP))+uint32(uint16(int16(v48))))), int(0x10000-uint32(uint16(int16(v48)))))
				v52 = unsafe.Pointer(dec.buf0)
				v53 = uint32(v46 - v51)
				v45 = (*uint8)(unsafe.Add(unsafe.Pointer(dstPtr), v51))
			}
			memcpy(unsafe.Pointer(v45), v52, int(v53))
			v54 = 0
			v55 = v47 - v46
			if v47-v46 > 0 {
				v56 = (*uint8)(unsafe.Add(unsafe.Pointer(dstPtr), v46))
				for {
					v54++
					*(*uint8)(unsafe.Add(unsafe.Pointer(v56), v54-1)) = *(*uint8)(unsafe.Add(unsafe.Pointer(dstPtr), v54-1))
					if v54 >= v55 {
						break
					}
				}
			}
		} else {
			v49 = int32(uint16(int16(v48)))
			if uint32(v49+v47) <= 0x10000 {
				memcpy(unsafe.Pointer(dstPtr), unsafe.Pointer(uintptr(*((*uint32)(decP))+uint32(v49))), int(v47))
			} else {
				memcpy(unsafe.Pointer(dstPtr), unsafe.Pointer(uintptr(*((*uint32)(decP))+uint32(v49))), int(0x10000-uint32(v49)))
				memcpy(unsafe.Add(unsafe.Pointer(dstPtr), 0x10000-uint32(v49)), unsafe.Pointer(dec.buf0), int(uint32(v47)-(0x10000-uint32(v49))))
			}
		}
		v57 = int32(dec.field4 & math.MaxUint16)
		if uint32(v57+v47) <= 0x10000 {
			v61 = dstPtr
			v60 = uint32(v47)
			v59 = unsafe.Pointer(uintptr(*((*uint32)(decP)) + uint32(v57)))
		} else {
			v58 = int32(0x10000 - uint32(v57))
			memcpy(unsafe.Pointer(uintptr(*((*uint32)(decP))+uint32(v57))), unsafe.Pointer(dstPtr), int(0x10000-uint32(v57)))
			v59 = unsafe.Pointer(dec.buf0)
			v60 = uint32(v47 - v58)
			v61 = (*uint8)(unsafe.Add(unsafe.Pointer(dstPtr), v58))
		}
		srcPtr2 = srcPtr
		memcpy(v59, unsafe.Pointer(v61), int(v60))
		dec.field4 += uint32(v47)
		dstPtr = v68
	LABEL_73:
		if uintptr(unsafe.Pointer(srcPtr2)) >= uintptr(srcPtrEnd2) {
			return 0
		}
		srcPtrEnd = srcPtrEnd2
	}
	if dstSz != nil {
		*dstSz += int(uintptr(unsafe.Pointer(dstBase)) - uintptr(unsafe.Pointer(dstPtr)))
	}
	if srcSz != nil {
		*srcSz += int(uintptr(unsafe.Pointer(srcBase)) - uintptr(unsafe.Pointer(srcPtr2)))
	}
	return 1
}
