package nxz

import (
	"math"
	"unsafe"
)

func sub57DDE0(a1 int32, a2 int32) uint32 {
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
func sub57DEA0(this *uint32, a2 *uint16) int32 {
	var (
		v2 *uint16
		v3 int32
		i  int32
		v5 *int16
		v6 int16
	)
	v2 = a2
	v3 = 0
	for i = 0; i < 274; i++ {
		*v2 = uint16(int16(i))
		v2 = (*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*2))
		*((*uint16)(unsafe.Add(unsafe.Pointer(v2), -int(unsafe.Sizeof(uint16(0))*1)))) = *(*uint16)(unsafe.Pointer(uintptr(*this + uint32(i*2))))
		v5 = (*int16)(unsafe.Pointer(uintptr(*this + uint32(i*2))))
		v6 = *v5
		v3 += int32(v6)
		*v5 = int16(int32(v6) >> 1)
	}
	sub57DDE0(int32(uintptr(unsafe.Pointer((*uint16)(unsafe.Add(unsafe.Pointer(a2), -int(unsafe.Sizeof(uint16(0))*2)))))), 274)
	return v3
}
func nxz_decompress(this *Decoder, a2p *uint8, a3p *int32, a4p *uint8, a5p *int32) int32 {
	var (
		a2  *uint8  = a2p
		a3  *uint32 = (*uint32)(unsafe.Pointer(a3p))
		a4  uint32  = uint32(uintptr(unsafe.Pointer(a4p)))
		a5  *uint32 = (*uint32)(unsafe.Pointer(a5p))
		v5  *uint8
		v7  uint32
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
		v20 *byte
		v21 int16
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
		v69 uint32
		v70 int32
		v71 int32
		v72 *uint8
		v73 uint32
		v74 *uint8
		v75 [1096]byte
	)
	v5 = (*uint8)(unsafe.Pointer(uintptr(a4)))
	var v6 unsafe.Pointer = unsafe.Pointer(this)
	v7 = a4 + *a5
	v74 = a2
	v73 = a4
	v69 = a4 + *a5
	v72 = (*uint8)(unsafe.Add(unsafe.Pointer(a2), *a3))
	*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(this))), 4*37)) = 0
	if a4 >= v7 {
		return 0
	}
	for {
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)))
		if v8 < 4 {
			if uint32(uintptr(unsafe.Pointer(v5))) >= v7 {
				v9 = -1
				*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = 0
				v63 = -1
				goto LABEL_9
			}
			v10 = int32(uint32(int32(*func() *uint8 {
				p := &v5
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v8)) | *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v10)
			a4 = uint32(uintptr(unsafe.Pointer(v5)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v8 + 8)
		}
		v11 = *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36))
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = v11 * 16
		v63 = int32(v11 >> 28)
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) -= 4
		v9 = int32(v11 >> 28)
	LABEL_9:
		v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*uintptr(v9*2+3))))
		if v12 == 0 {
			v13 = int32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*35)) + *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*uintptr(v9*2+4)))*2))))
			goto LABEL_18
		}
		v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)))
		if v14 >= v12 {
			goto LABEL_15
		}
		if uint32(uintptr(unsafe.Pointer(v5))) < v7 {
			v16 = int32(uint32(int32(*func() *uint8 {
				p := &v5
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v14)) | *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v16)
			a4 = uint32(uintptr(unsafe.Pointer(v5)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v14 + 8)
		LABEL_15:
			v15 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) >> uint32(32-v12))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) <<= uint32(v12)
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) -= uint32(v12)
			v9 = v63
			goto LABEL_16
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = 0
		v15 = -1
	LABEL_16:
		v17 = int32(uint32(v15) + *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*uintptr(v9*2+4))))
		if v17 >= 274 {
			return 0
		}
		v13 = int32(*(*int16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*35)) + uint32(v17*2)))))
	LABEL_18:
		*(*uint16)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*2)) + uint32(v13*2))))++
		if v13 < 256 {
			if uintptr(unsafe.Pointer(a2)) < uintptr(unsafe.Pointer(v72)) {
				*func() *uint8 {
					p := &a2
					x := *p
					*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
					return x
				}() = uint8(int8(v13))
				v18 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*1)))
				*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*1)) = uint32(v18 + 1)
				*(*uint8)(unsafe.Pointer(uintptr(uint32(uint16(int16(v18))) + *((*uint32)(v6))))) = uint8(int8(v13))
				goto LABEL_73
			}
			return 0
		}
		if v13 == 272 {
			sub57DEA0((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*2)), (*uint16)(unsafe.Pointer(&v75[0])))
			v19 = 0
			v20 = &v75[0]
			for {
				v21 = int16(*(*uint16)(unsafe.Pointer(v20)))
				v20 = (*byte)(unsafe.Add(unsafe.Pointer(v20), 4))
				*(*uint16)(unsafe.Pointer(uintptr(uint32(v19) + *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*35))))) = uint16(v21)
				v19 += 2
				if v19 >= 548 {
					break
				}
			}
			v22 = 0
			v23 = (*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*4))
			v70 = 0
			v66 = 16
			for {
				for i = 0; ; i++ {
					v24 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)))
					if v24 >= 1 {
						goto LABEL_29
					}
					if uint32(uintptr(unsafe.Pointer(v5))) >= v69 {
						break
					}
					v25 = int32(uint32(int32(*func() *uint8 {
						p := &v5
						x := *p
						*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
						return x
					}())<<(24-v24)) | *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)))
					*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v25)
					*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v24 + 8)
				LABEL_29:
					v26 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) >> 31)
					v27 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) - 1)
					*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) *= 2
					*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v27)
					if v26 != 0 {
						goto LABEL_32
					}
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = 0
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
					a4 = uint32(uintptr(unsafe.Pointer(v5)))
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
		v30 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)))
		if v30 >= v29 {
			goto LABEL_41
		}
		if uint32(uintptr(unsafe.Pointer(v5))) < v69 {
			v32 = int32(uint32(int32(*func() *uint8 {
				p := &v5
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v30)) | *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v32)
			a4 = uint32(uintptr(unsafe.Pointer(v5)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v30 + 8)
		LABEL_41:
			v31 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) >> uint32(32-v29))
			v33 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) << uint32(v29))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) -= uint32(v29)
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v33)
			goto LABEL_42
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = 0
		v31 = -1
	LABEL_42:
		v28 = int32(uint32(v31) + nxz_table_1[v13].v2)
	LABEL_43:
		v34 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)))
		v67 = v28
		if v34 < 3 {
			if uint32(uintptr(unsafe.Pointer(v5))) >= v69 {
				*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = 0
				v71 = -1
				goto LABEL_48
			}
			v35 = int32(uint32(int32(*func() *uint8 {
				p := &v5
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v34)) | *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v35)
			a4 = uint32(uintptr(unsafe.Pointer(v5)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v34 + 8)
		}
		v36 = *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36))
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = v36 * 8
		v71 = int32(v36 >> 29)
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) -= 3
	LABEL_48:
		v65 = 0
		v37 = int32(nxz_table_2[v71+1].v1 + 9)
		if v37 <= 8 {
			goto LABEL_55
		}
		v38 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)))
		v37 = int32(nxz_table_2[v71+1].v1 + 1)
		if v38 >= 8 {
			goto LABEL_53
		}
		if uint32(uintptr(unsafe.Pointer(v5))) < v69 {
			v40 = int32(uint32(int32(*func() *uint8 {
				p := &v5
				x := *p
				*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
				return x
			}())<<(24-v38)) | *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v40)
			a4 = uint32(uintptr(unsafe.Pointer(v5)))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v38 + 8)
		LABEL_53:
			v41 = *(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = v41 << 8
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) -= 8
			v39 = int32(v41 >> 24)
			goto LABEL_54
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = 0
		v39 = -1
	LABEL_54:
		v65 = v39 << v37
	LABEL_55:
		v42 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)))
		if v42 >= v37 {
			goto LABEL_59
		}
		if uint32(uintptr(unsafe.Pointer(v5))) < v69 {
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) |= uint32(int32(*v5) << (24 - v42))
			a4 = uint32(uintptr(unsafe.Pointer((*uint8)(unsafe.Add(unsafe.Pointer(v5), 1)))))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = uint32(v42 + 8)
		LABEL_59:
			v43 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) >> uint32(32-v37))
			v44 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) << uint32(v37))
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) -= uint32(v37)
			*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*36)) = uint32(v44)
			goto LABEL_60
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*37)) = 0
		v43 = -1
	LABEL_60:
		v45 = a2
		v46 = int32((nxz_table_2[v71+1].v2 << 9) + uint32(v65|v43))
		v47 = v67 + 4
		v68 = (*uint8)(unsafe.Add(unsafe.Pointer(a2), v67+4))
		if uintptr(unsafe.Pointer(v68)) > uintptr(unsafe.Pointer(v72)) {
			return 0
		}
		v48 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*1)) - uint32(v46))
		if v47 >= v46 {
			v50 = int32(uint16(int16(v48)))
			if uint32(int32(uint16(int16(v48)))+v46) <= 0x10000 {
				v53 = uint32(v46)
				v52 = unsafe.Pointer(uintptr(*((*uint32)(v6)) + uint32(v50)))
			} else {
				v51 = int32(0x10000 - uint32(uint16(int16(v48))))
				memcpy(unsafe.Pointer(a2), unsafe.Pointer(uintptr(*((*uint32)(v6))+uint32(uint16(int16(v48))))), int(0x10000-uint32(uint16(int16(v48)))))
				v52 = unsafe.Pointer(uintptr(*((*uint32)(v6))))
				v53 = uint32(v46 - v51)
				v45 = (*uint8)(unsafe.Add(unsafe.Pointer(a2), v51))
			}
			memcpy(unsafe.Pointer(v45), v52, int(v53))
			v54 = 0
			v55 = v47 - v46
			if v47-v46 > 0 {
				v56 = (*uint8)(unsafe.Add(unsafe.Pointer(a2), v46))
				for {
					v54++
					*(*uint8)(unsafe.Add(unsafe.Pointer(v56), v54-1)) = *(*uint8)(unsafe.Add(unsafe.Pointer(a2), v54-1))
					if v54 >= v55 {
						break
					}
				}
			}
		} else {
			v49 = int32(uint16(int16(v48)))
			if uint32(v49+v47) <= 0x10000 {
				memcpy(unsafe.Pointer(a2), unsafe.Pointer(uintptr(*((*uint32)(v6))+uint32(v49))), int(v47))
			} else {
				memcpy(unsafe.Pointer(a2), unsafe.Pointer(uintptr(*((*uint32)(v6))+uint32(v49))), int(0x10000-uint32(v49)))
				memcpy(unsafe.Add(unsafe.Pointer(a2), 0x10000-uint32(v49)), unsafe.Pointer(uintptr(*((*uint32)(v6)))), int(uint32(v47)-(0x10000-uint32(v49))))
			}
		}
		v57 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*1)) & math.MaxUint16)
		if uint32(v57+v47) <= 0x10000 {
			v61 = a2
			v60 = uint32(v47)
			v59 = unsafe.Pointer(uintptr(*((*uint32)(v6)) + uint32(v57)))
		} else {
			v58 = int32(0x10000 - uint32(v57))
			memcpy(unsafe.Pointer(uintptr(*((*uint32)(v6))+uint32(v57))), unsafe.Pointer(a2), int(0x10000-uint32(v57)))
			v59 = unsafe.Pointer(uintptr(*((*uint32)(v6))))
			v60 = uint32(v47 - v58)
			v61 = (*uint8)(unsafe.Add(unsafe.Pointer(a2), v58))
		}
		v5 = (*uint8)(unsafe.Pointer(uintptr(a4)))
		memcpy(v59, unsafe.Pointer(v61), int(v60))
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(v6)), 4*1)) += uint32(v47)
		a2 = v68
	LABEL_73:
		if uint32(uintptr(unsafe.Pointer(v5))) >= v69 {
			return 0
		}
		v7 = v69
	}
	if a3 != nil {
		*a3 += uint32(int32(uintptr(unsafe.Pointer(v74)) - uintptr(unsafe.Pointer(a2))))
	}
	if a5 != nil {
		*a5 += v73 - uint32(uintptr(unsafe.Pointer(v5)))
	}
	return 1
}
