package legacy

import (
	"image"
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cmath"
	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var dword_5d4594_1217444_vec Point32
var dword_5d4594_1217452 int
var dword_5d4594_1217456 []*SightStructXxx
var dword_5d4594_1217460 int32
var dword_5d4594_1217464 int32

var dword_5d4594_1522584 *SightStructXxx
var dword_5d4594_1522588 uint32
var dword_5d4594_1522592 *SightStructXxx
var dword_5d4594_1522596 *SightStructXxx

var arr_5d4594_1322584 [100000]int16

// [-1].X = 1203868
// [-1].Y = 1203872
// [0].X = 1203876
// [0].Y = 1203880
// [1].X = 1203884
// [1].Y = 1203888
var arr_5d4594_1203876 = memmap.PtrT[[1024]Point32](0x5D4594, 1203876) // TODO: size is a guess

var arr_5d4594_1213348 = memmap.PtrT[[1024]uint32](0x5D4594, 1213348)
var arr_5d4594_1212324 = memmap.PtrT[[1024]byte](0x5D4594, 1212324)

// [-1].X = 1212060
// [-1].Y = 1212064
// [0].X = 1212068
// [0].Y = 1212072
// [1].X = 1212076
// [1].Y = 1212080
var arr_5d4594_1212068 [32]Point32

func Get_dword_5d4594_1217464() int {
	return int(dword_5d4594_1217464)
}
func Set_dword_5d4594_1217464(v int) {
	dword_5d4594_1217464 = int32(v)
}
func sub_4CAE60() {
	var v1 *SightStructXxx
	dword_5d4594_1522584 = nil
	for it := dword_5d4594_1522592; it != nil; it = it.Field8 {
		it.Field16 = v1
		v1 = it
		dword_5d4594_1522584 = it
	}
}

func nox_xxx_drawBlack_496150(a1 *noxrender.Viewport) {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v15 uint8
		v16 *uint8
		v17 bool
		v18 int32
		v20 int32
		v21 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 int32
		v31 int32
		v32 int32
		v33 int32
		v35 float64
		v36 int32
		v37 int32
		v39 int32
		v40 int32
		v41 int32
		v42 int32
		v43 float64
		v44 float64
		v45 int32
		v46 int32
		v47 int32
		v48 int32
		v49 int32
		v50 int32
		v51 int32
		v52 int32
		v53 int32
		v54 int32
		v55 uint8
		v56 uint8
		v57 int32
		v58 int32
		v59 int32
		v60 int32
		v61 int32
		v62 int32
		v63 int32
		v64 int32
		v65 int32
		v66 int32
		v68 int32
		v69 int32
		v70 int32
		v71 int32
		v72 int32
		v73 uint32
		v74 int32
		v75 int32
		v76 int32
		a4  types.Pointf
		v78 types.Pointf
		v79 int32
		v80 int32
		a1a Point32
		a2  Point32
		v83 float4
		a3  float4
		v86 float4
	)
	sub_4CAE60()
	dword_5d4594_1217464 = 0
	dword_5d4594_1217460 = 0
	v1 = int32(a1.World.Min.X)
	v2 = int32(a1.World.Min.Y)
	v3 = int32(a1.Size.X)
	v79 = v1 / 23
	v80 = v2 / 23
	v74 = (v3+v1)/23 - v1/23
	v4 = int32((a1.Size.Y+int(v2))/23 - int(v2/23))
	dword_5d4594_1217444_vec.X = v1 + v3/2
	dword_5d4594_1217444_vec.Y = int32(uint32(a1.World.Min.Y + a1.Field12 + a1.Size.Y/2))
	sub_498030(a1)
	sub_497260(a1)
	if v4 < 0 {
		goto LABEL_32
	}
	v5 = v80
	v6 = v74
	v71 = v80
	v70 = v80 * 23
	v75 = v4 + 1
	for {
		v7 = (int32(uint8(int8(v5))) + int32(uint8(int8(v79)))) & 1
		if v7 > v6 {
			goto LABEL_31
		}
		v8 = v7 + v79
		v69 = (v7 + v79) * 23
		v73 = uint32(v6-v7+2) >> 1
		for {
			wl := nox_server_getWallAtGrid_410580(v8, v5)
			if wl != nil {
				v10 := uint8(sub_57B500(v8, v5, 64))
				if int32(v10) != math.MaxUint8 {
					v11 := int32(wl.Tile1)
					v12 := uint8(wl.Flags4)
					if nox_xxx_wallFlags(v11)&1 != 0 {
						if int32(v12)&0x40 != 0 {
							if (dword_5d4594_1217444_vec.X-v69-11)*(dword_5d4594_1217444_vec.X-v69-11)+(dword_5d4594_1217444_vec.Y-v70-11)*(dword_5d4594_1217444_vec.Y-v70-11) < 3600 {
								v5 = v71
								wl.Flags4 = server.WallFlags(uint8(int8(int32(v12) | 1)))
								goto LABEL_29
							}
							v5 = v71
						}
						if int32(v10) != 0 {
							if int32(v10) == 1 {
								nox_xxx_drawBlackofWall_497C40(v8, v5, 6)
							} else {
								v16 = (*uint8)(memmap.PtrOff(0x587000, uintptr(v10)+161764))
								if int32(*v16)&2 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 2)
								}
								if int32(*v16)&1 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 1)
								}
								if int32(*v16)&8 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 8)
								}
								if int32(*v16)&4 != 0 {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 4)
								}
							}
						} else {
							nox_xxx_drawBlackofWall_497C40(v8, v5, 9)
						}
					} else {
						v13 := uint8(int8(int32(v12) | 1))
						v14 := int32(wl.Y6)
						wl.Flags4 = server.WallFlags(v13)
						if v14*23 <= dword_5d4594_1217444_vec.Y {
							v15 = uint8(int8(int32(v13) & 0xFD))
						} else {
							v15 = uint8(int8(int32(v13) | 2))
						}
						wl.Flags4 = server.WallFlags(v15)
						if nox_xxx_wallFlags(v11)&4 != 0 {
							nox_xxx_drawList1096512_Append_4754C0(wl)
						}
					}
				}
			}
		LABEL_29:
			v8 += 2
			v17 = v73 == 1
			v69 += 46
			v73--
			if v17 {
				break
			}
		}
		v6 = v74
	LABEL_31:
		v5++
		v17 = v75 == 1
		v70 += 23
		v71 = v5
		v75--
		if v17 {
			break
		}
	}
LABEL_32:
	sub_498110()
	v72 = 0
	a3.field_0 = float32(float64(dword_5d4594_1217444_vec.X))
	a3.field_4 = float32(float64(dword_5d4594_1217444_vec.Y))
	if dword_5d4594_1217460 <= 0 {
		v51 = dword_5d4594_1217464
	} else {
		for {
			v18 = 0
			v19 := dword_5d4594_1217456[v72]
			switch v19.Field56 {
			case 0:
				v20 = (v19.Field40 * 25736) / 75000
				a3.field_8 = float32(float64(int32(dword_5d4594_1217444_vec.X + int32(sub_414BD0(6434-v20)))))
				a3.field_C = float32(float64(int32(dword_5d4594_1217444_vec.Y + int32(sub_414BD0(v20)))))
				sub_4CA960(&v19.Field24, int8(v19.Field36), &a3, &a4)
				v21 = (v19.Field44 * 25736) / 75000
				a3.field_8 = float32(float64(int32(dword_5d4594_1217444_vec.X + int32(sub_414BD0(6434-v21)))))
				a3.field_C = float32(float64(int32(dword_5d4594_1217444_vec.Y + int32(sub_414BD0(v21)))))
				sub_4CA960(&v19.Field24, int8(v19.Field36), &a3, &v78)
				v22p := nox_server_getWallAtGrid_410580(v19.Field24.X, v19.Field24.Y)
				v23 := v22p
				v23.Field12 = 1
				v23.Flags4 |= 1
				if float64(v78.X) < float64(a4.X) {
					v23.Flags4 |= 2
				}
				v23.Field3 |= v19.Field36
				v18 = v19.Field24.X + (v19.Field24.Y << 8)
			case 1:
				a4.X = float32(float64(dword_5d4594_1217444_vec.X + sub_414C50((v19.Field40*25736)/75000-19302)*int32(a1.Size.Y/2)/4096))
				a4.Y = float32(float64(a1.World.Min.Y))
				v18 = 0
				v78.X = float32(float64(dword_5d4594_1217444_vec.X + sub_414C50((v19.Field44*25736)/75000-19302)*int32(a1.Size.Y/2)/4096))
				v78.Y = float32(float64(a1.World.Min.Y))
			case 2:
				v25 = int32(a1.Size.Y)
				v26 = dword_5d4594_1217444_vec.X - int32(sub_414C50((v19.Field40*25736)/75000-6434)*(v25/2)/4096)
				v27 = int32(a1.World.Min.Y + int(v25) - 1)
				v28 = int32(a1.Size.Y)
				a4.X = float32(float64(v26))
				a4.Y = float32(float64(v27))
				v29 = sub_414C50((v19.Field44*25736)/75000 - 6434)
				v76 = int32(a1.World.Min.Y + int(v28) - 1)
				v78.X = float32(float64(dword_5d4594_1217444_vec.X - v29*(v28/2)/4096))
				v78.Y = float32(float64(v76))
				v18 = 0
			case 3:
				v32 = v19.Field40 * 25736
				a4.X = float32(float64(a1.World.Min.X))
				a4.Y = float32(float64(dword_5d4594_1217444_vec.Y - sub_414C50((v32)/75000-12868)*int32(a1.Size.X/2)/4096))
				v33 = v19.Field44 * 25736
				v78.X = float32(float64(a1.World.Min.X))
				v18 = 0
				v78.Y = float32(float64(dword_5d4594_1217444_vec.Y - sub_414C50((v33)/75000-12868)*int32(a1.Size.X/2)/4096))
			case 4:
				v30 = int32(a1.Size.X)
				v68 = (v19.Field40 * 25736) / 75000
				a4.X = float32(float64(a1.Size.X + a1.World.Min.X - 1))
				a4.Y = float32(float64(int32(dword_5d4594_1217444_vec.Y + int32(sub_414C50(v68)*(v30/2)/4096))))
				v31 = (v19.Field44 * 25736) / 75000
				v78.X = float32(float64(a1.World.Min.X + int(v30) - 1))
				v78.Y = float32(float64(int32(dword_5d4594_1217444_vec.Y + int32(sub_414C50(v31)*int32(a1.Size.X/2)/4096))))
				v18 = 0
			case 6:
				v34 := v19.Field20
				v35 = float64(v34.PosVec.X)
				v34.Field_33 = 1
				v86.field_0 = float32(v35)
				v86.field_4 = float32(float64(v34.PosVec.Y))
				v86.field_8 = float32(float64(v34.PosVec.X + int(*memmap.PtrInt32(0x587000, uintptr(int32(v34.Field_74_4)*8)+196184))))
				v86.field_C = float32(float64(v34.PosVec.Y + int(*memmap.PtrInt32(0x587000, uintptr(int32(v34.Field_74_4)*8)+196188))))
				v36 = (v19.Field40 * 25736) / 75000
				a3.field_8 = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v36)))
				a3.field_C = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v36)))
				if sub_497180(&a3, &v86, &a4) == 0 {
					a4 = types.Pointf{X: v86.field_0, Y: v86.field_4}
				}
				v37 = (v19.Field44 * 25736) / 75000
				a3.field_8 = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v37)))
				a3.field_C = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v37)))
				if sub_497180(&a3, &v86, &v78) == 0 {
					v78 = types.Pointf{X: v86.field_8, Y: v86.field_C}
				}
				v18 = int32(v34.NetCode32)
			case 7:
				v19.Field20.Field_33 = 1
				v38 := v19.Field20
				v39 = dword_5d4594_1217444_vec.X - int32(v38.PosVec.X)
				v40 = int32(v38.PosVec.Y - int(dword_5d4594_1217444_vec.Y))
				v83.field_0 = float32(float64(v40 + int32(v19.Field20.PosVec.X)))
				v83.field_4 = float32(float64(v39 + int32(v19.Field20.PosVec.Y)))
				v83.field_8 = float32(float64(v19.Field20.PosVec.X - int(v40)))
				v83.field_C = float32(float64(v19.Field20.PosVec.Y - int(v39)))
				v41 = (v19.Field40 * 25736) / 75000
				a3.field_8 = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v41)))
				a3.field_C = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v41)))
				if sub_497180(&a3, &v83, &a4) == 0 {
					a4 = types.Ptf(v83.field_0, v83.field_4)
				}
				v42 = (v19.Field44 * 25736) / 75000
				a3.field_8 = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v42)))
				a3.field_C = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v42)))
				if sub_497180(&a3, &v83, &v78) != 0 {
					v18 = int32(v19.Field20.NetCode32)
					break
				}
				v78 = types.Pointf{X: v83.field_8, Y: v83.field_C}
				v18 = int32(v19.Field20.NetCode32)
			case 8, 9, 0xA, 0xB, 0xD, 0xE:
				v19.Field20.Field_33 = 1
				switch v19.Field56 {
				case 8:
					v83.field_0 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.LeftTop))
					v83.field_4 = float32(float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.LeftBottom))
					v83.field_8 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.LeftBottom2))
					v43 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.LeftTop2)
					v83.field_C = float32(v43)
				case 9:
					v83.field_0 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.LeftTop))
					v44 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.LeftBottom)
					v83.field_4 = float32(v44)
					v83.field_8 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.RightTop))
					v43 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.RightBottom)
					v83.field_C = float32(v43)
				case 0xA:
					v83.field_0 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.RightBottom2))
					v83.field_4 = float32(float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.RightTop2))
					v83.field_8 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.LeftBottom2))
					v43 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.LeftTop2)
					v83.field_C = float32(v43)
				case 0xB:
					v83.field_0 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.RightBottom2))
					v44 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.RightTop2)
					v83.field_4 = float32(v44)
					v83.field_8 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.RightTop))
					v43 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.RightBottom)
					v83.field_C = float32(v43)
				case 0xD:
					v83.field_0 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.LeftTop))
					v83.field_4 = float32(float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.LeftBottom))
					v83.field_8 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.RightBottom2))
					v43 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.RightTop2)
					v83.field_C = float32(v43)
				case 0xE:
					v83.field_0 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.LeftBottom2))
					v44 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.LeftTop2)
					v83.field_4 = float32(v44)
					v83.field_8 = float32(float64(v19.Field20.PosVec.X) + float64(v19.Field20.Shape.Box.RightTop))
					v43 = float64(v19.Field20.PosVec.Y) + float64(v19.Field20.Shape.Box.RightBottom)
					v83.field_C = float32(v43)
				default:
				}
				v45 = (v19.Field40 * 25736) / 75000
				a3.field_8 = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v45)))
				a3.field_C = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v45)))
				if sub_497180(&a3, &v83, &a4) == 0 {
					a4 = types.Pointf{X: v83.field_0, Y: v83.field_4}
				}
				v46 = (v19.Field44 * 25736) / 75000
				a3.field_8 = float32(float64(dword_5d4594_1217444_vec.X + sub_414BD0(6434-v46)))
				a3.field_C = float32(float64(dword_5d4594_1217444_vec.Y + sub_414BD0(v46)))
				if sub_497180(&a3, &v83, &v78) == 0 {
					v78 = types.Pointf{X: v83.field_8, Y: v83.field_C}
					v18 = int32(v19.Field20.NetCode32)
					break
				}
				v18 = int32(v19.Field20.NetCode32)
			default:
			}
			a1a.X = int32(a1.Screen.Min.X - a1.World.Min.X + int(int32(a4.X)))
			a1a.Y = int32(a1.Screen.Min.Y - a1.World.Min.Y + int(int32(a4.Y)))
			a2.X = int32(a1.Screen.Min.X - a1.World.Min.X + int(int32(v78.X)))
			a2.Y = int32(a1.Screen.Min.Y - a1.World.Min.Y + int(int32(v78.Y)))
			if sub_57BA30(&a1a, &a2, &a1.Screen) != 0 {
				v47 = dword_5d4594_1217464
				v48 = a1a.Y
				arr_5d4594_1203876[dword_5d4594_1217464].X = a1a.X
				v49 = a2.X
				arr_5d4594_1203876[dword_5d4594_1217464].Y = v48
				v50 = a2.Y
				arr_5d4594_1213348[v47] = uint32(v18)
				arr_5d4594_1212324[v47] = v19.Field56
				v47++
				dword_5d4594_1217464 = v47
				arr_5d4594_1203876[v47].X = v49
				arr_5d4594_1203876[v47].Y = v50
				arr_5d4594_1213348[v47] = uint32(v18)
				arr_5d4594_1212324[v47] = v19.Field56
				v51 = v47 + 1
				dword_5d4594_1217464 = v51
			} else {
				v51 = dword_5d4594_1217464
			}
			v72++
			if v72 >= dword_5d4594_1217460 {
				break
			}
		}
	}
	v52 = v51 - 1
	v53 = 0
	dword_5d4594_1217464 = v52
	v54 = v52 - 1
	for v53 < v52 {
		v55 = arr_5d4594_1212324[v54]
		if int32(v55) != 0 {
			v56 = arr_5d4594_1212324[v53]
			if int32(v56) == 0 {
				if int32(v55) == 6 || arr_5d4594_1212324[v53] == 6 {
					v63 = arr_5d4594_1203876[v54].X
					if arr_5d4594_1203876[v53].X-v63 >= 0 {
						v64 = arr_5d4594_1203876[v53].X - int32(v63)
					} else {
						v64 = int32(v63) - arr_5d4594_1203876[v53].X
					}
					v65 = arr_5d4594_1203876[v54].Y
					if arr_5d4594_1203876[v53].Y-v65 >= 0 {
						v66 = arr_5d4594_1203876[v53].Y - int32(v65)
					} else {
						v66 = int32(v65) - arr_5d4594_1203876[v53].Y
					}
					if v64 <= 4 && v66 <= 4 {
						v54 = func() int32 {
							p := &v53
							x := *p
							*p++
							return x
						}()
						continue
					}
				}
				arr_5d4594_1212324[v54] = 12
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			if int32(v56) != int32(v55) {
				arr_5d4594_1212324[v54] = 12
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			if arr_5d4594_1213348[v53] == arr_5d4594_1213348[v54] {
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			v57 = arr_5d4594_1203876[v54].X
			v58 = arr_5d4594_1203876[v53].X - int32(v57)
			if v58 < 0 {
				v59 = int32(v57) - arr_5d4594_1203876[v53].X
			} else {
				v59 = v58
			}
		} else {
			if arr_5d4594_1212324[v53] != 0 {
				if int32(v55) == 6 || arr_5d4594_1212324[v53] == 6 {
					v63 = arr_5d4594_1203876[v54].X
					if arr_5d4594_1203876[v53].X-v63 >= 0 {
						v64 = arr_5d4594_1203876[v53].X - int32(v63)
					} else {
						v64 = int32(v63) - arr_5d4594_1203876[v53].X
					}
					v65 = arr_5d4594_1203876[v54].Y
					if arr_5d4594_1203876[v53].Y-v65 >= 0 {
						v66 = arr_5d4594_1203876[v53].Y - int32(v65)
					} else {
						v66 = int32(v65) - arr_5d4594_1203876[v53].Y
					}
					if v64 <= 4 && v66 <= 4 {
						v54 = func() int32 {
							p := &v53
							x := *p
							*p++
							return x
						}()
						continue
					}
				}
				arr_5d4594_1212324[v54] = 12
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			if arr_5d4594_1213348[v54] == arr_5d4594_1213348[v53] {
				v54 = func() int32 {
					p := &v53
					x := *p
					*p++
					return x
				}()
				continue
			}
			v60 = arr_5d4594_1203876[v54].X
			v58 = arr_5d4594_1203876[v53].X - int32(v60)
			if v58 < 0 {
				v59 = int32(v60) - arr_5d4594_1203876[v53].X
			} else {
				v59 = v58
			}
		}
		v61 = arr_5d4594_1203876[v54].Y
		if arr_5d4594_1203876[v53].Y-v61 >= 0 {
			v62 = arr_5d4594_1203876[v53].Y - int32(v61)
		} else {
			v62 = int32(v61) - arr_5d4594_1203876[v53].Y
		}
		if v59 <= 4 && v62 <= 4 {
			v54 = func() int32 {
				p := &v53
				x := *p
				*p++
				return x
			}()
		} else {
			arr_5d4594_1212324[v54] = 12
			v54 = func() int32 {
				p := &v53
				x := *p
				*p++
				return x
			}()
		}
	}
}

func nox_xxx_client_4984B0_drawable(dr *client.Drawable) int32 {
	if dr.DrawFunc.Ptr() == nil {
		return 0
	}
	if dr.C() == *memmap.PtrPtr(0x852978, 8) {
		return 1
	}
	var v42, v43, v6 int32
	if int8(byte(dr.Flags28())) >= 0 {
		v42 = int32(dr.PosVec.X)
		v43 = int32(dr.PosVec.Y)
		v6 = int32(dr.PosVec.X)
	} else {
		if (dr.Flags29() & 4) == 0 {
			return int32(dr.Field_33)
		}
		v3 := int32(dr.PosVec.X)
		v4 := int32(dr.Field_74_4) * 8
		v5 := *memmap.PtrInt32(0x587000, uintptr(v4)+196184)
		v6 = v3 + v5/2
		v42 = v3 + v5/2
		v43 = int32(dr.PosVec.Y + int(uint32(*memmap.PtrInt32(0x587000, uintptr(v4)+196188)/2)))
	}
	if dr.ObjFlags&0x10000 != 0 {
		return int32(dr.Field_33)
	}
	vp := nox_draw_getViewport_437250()
	v7 := int32(vp.World.Min.X - vp.Screen.Min.X)
	v8 := int32(vp.World.Min.Y - vp.Screen.Min.Y)
	v44 := v7
	v45 := v8
	v37 := v6 - v7
	var a1a int4
	a1a.field_0 = int32(vp.Screen.Min.X + vp.Size.X/2)
	a1a.field_4 = int32(vp.Screen.Min.Y + vp.Field12 + vp.Size.Y/2)
	a1a.field_8 = v6 - v7
	a1a.field_C = v43 - v8
	if dword_5d4594_1217464 <= 0 {
		return 1
	}
	v9 := arr_5d4594_1203876[dword_5d4594_1217464-1]
	ok := false
	for v31 := int32(0); v31 < dword_5d4594_1217464; v31++ {
		p := arr_5d4594_1203876[v31]
		var a2 int4
		a2.field_0 = v9.X
		a2.field_4 = v9.Y
		a2.field_8 = p.X
		a2.field_C = p.Y
		if sub_427C80(&a1a, &a2) != 0 {
			ok = true
			break
		}
		v9 = p
	}
	if !ok {
		return 1
	}
	var v13, v14, v15, v16 int32
	if dr.Shape.Kind == 2 {
		v12 := int32(dr.Shape.Circle.R)
		if int32(*(*uint16)(unsafe.Add(dr.C(), 2))) != 0 {
			v35 := int32(*(*uint16)(unsafe.Add(dr.C(), 6)))
			v13 = v6 - (int32(*(*uint16)(unsafe.Add(dr.C(), 4))) >> 1) - v7
			v14 = v43 + v12 + int32(dr.ZVal) - v35 - v8 - int32(dr.ZSizeMin)
			v15 = v13 + int32(*(*uint16)(unsafe.Add(dr.C(), 4)))
			v16 = v14 + v35
		} else {
			v13 = v6 - v12 - v7
			v14 = v43 - v12 - v8 - int32(dr.ZSizeMax)
			v15 = v42 + v12 - v44
			v16 = v43 + v12 + int32(dr.ZVal) - v45 - int32(dr.ZSizeMin)
		}
	} else if int32(*(*uint16)(unsafe.Add(dr.C(), 2))) != 0 {
		v13 = v6 - (int32(*(*uint16)(unsafe.Add(dr.C(), 4))) >> 1) - v7
		v16 = int32(dr.Shape.Box.RightTop2) + v43 + int32(dr.ZVal) - v8
		v14 = v16 - int32(*(*uint16)(unsafe.Add(dr.C(), 6)))
		v15 = v13 + int32(*(*uint16)(unsafe.Add(dr.C(), 4)))
	} else {
		v13 = v37 + int32(dr.Shape.Box.LeftBottom2)
		v17 := v43 - v8 - int32(dr.ZSizeMax)
		v14 = int32(dr.Shape.Box.LeftBottom) + v17
		v15 = v37 + int32(dr.Shape.Box.RightTop)
		v16 = int32(dr.Shape.Box.RightTop2) + v43 + int32(dr.ZVal) - v45
	}
	v32 := 0
	v51 := 0
	v41 := v13
	v38 := v14
	v40 := v15
	v36 := v16
	if int(v13) < vp.Screen.Min.X || int(v13) > vp.Screen.Max.X {
		v32 = 1
	} else {
		v51 = 1
	}
	if int(v14) < vp.Screen.Min.Y || int(v14) > vp.Screen.Max.Y {
		v32++
	} else {
		v51++
	}
	if int(v15) < vp.Screen.Min.X || int(v15) > vp.Screen.Max.X {
		v32++
	} else {
		v51++
	}
	if int(v16) < vp.Screen.Min.Y || int(v16) > vp.Screen.Max.Y {
		v32++
	} else {
		v51++
	}
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(dr), 2))) != 0 {
		if v15-v13 > 6 {
			v13 += 3
			v15 -= 3
		}
		if v16-v14 >= 22 {
			v14 += 11
			v16 -= 11
		}
	}
	if v51 == 0 || v32 == 0 {
		return 0
	}
	var v48 int4
	v48.field_0 = a1a.field_0
	v48.field_4 = a1a.field_4
	if int(v41) < vp.Screen.Min.X {
		v48.field_8 = v15
		a1a.field_8 = v15
		a1a.field_C = v14
		v48.field_C = v16
	} else if int(v40) > vp.Screen.Max.X {
		v48.field_8 = v13
		a1a.field_8 = v13
		a1a.field_C = v14
		v48.field_C = v16
	}
	if int(v38) < vp.Screen.Min.Y {
		a1a.field_8 = v13
		v48.field_C = v16
		a1a.field_C = v16
		v48.field_8 = v15
	} else if int(v36) > vp.Screen.Max.Y {
		a1a.field_8 = v13
		v48.field_C = v14
		a1a.field_C = v14
		v48.field_8 = v15
	}
	v18 := dword_5d4594_1217464
	v20 := arr_5d4594_1203876[dword_5d4594_1217464-1]
	if dword_5d4594_1217464 > 0 {
		for v19 := int32(0); v19 < dword_5d4594_1217464; v19++ {
			p := arr_5d4594_1203876[v19]
			var a2 int4
			a2.field_0 = v20.X
			a2.field_4 = v20.Y
			a2.field_8 = p.X
			a2.field_C = p.Y
			if sub_427C80(&a1a, &a2) != 0 {
				return 0
			}
			v18 = dword_5d4594_1217464
			v20 = p
		}
	}
	if v18 <= 0 {
		return 1
	}
	v25 := arr_5d4594_1203876[v18-1]
	for i := int32(0); i < dword_5d4594_1217464; i++ {
		p := arr_5d4594_1203876[i]
		var a2 int4
		a2.field_0 = v25.X
		a2.field_4 = v25.Y
		a2.field_8 = p.X
		a2.field_C = p.Y
		if sub_427C80(&v48, &a2) != 0 {
			return 0
		}
		v25 = p
	}
	return 1
}

func sub_498AE0() {
	nox_client_drawEnableAlpha_434560(1)
	nox_set_color_rgb_434430(0, 0, 0)
	v0 := dword_5d4594_1217464
	v1 := int32(0)
	for i := dword_5d4594_1217464 - 1; v1 < v0; v1++ {
		if arr_5d4594_1212324[i] == 12 {
			sub_498B50(arr_5d4594_1203876[i].X, arr_5d4594_1203876[i].Y, arr_5d4594_1203876[v1].X, arr_5d4594_1203876[v1].Y)
			v0 = dword_5d4594_1217464
		}
		i = v1
	}
	nox_client_drawEnableAlpha_434560(0)
}

func sub_498C20(a1 *Point32, a2 *Point32, a3 int32) int32 {
	var (
		v3  *Point32
		v4  *Point32
		v5  int8
		v6  int8
		v7  int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v21 float32
		v22 float32
		v23 float32
		v24 float32
		v25 float32
		v26 float32
		v27 float32
		v28 float32
		v29 float32 = 0
		v30 float32
		v31 int32 = 0
		a1a Point32
		v37 int8
		v38 int8
		v39 float32
	)
	v3 = a1
	if a1 == nil {
		return 0
	}
	v4 = a2
	if a2 == nil {
		return 0
	}
	if a3 == 0 {
		return 0
	}
	dword_5d4594_1217452 = 0
	v5 = sub_4990D0(a1, a2)
	v6 = v5
	v37 = v5
	if int32(v5) == 0 {
		return 0
	}
	if int32(v5) != 4 && int32(v5) != 8 {
		v29 = float32(float64(a2.Y-v3.Y) / float64(a2.X-v3.X))
		v27 = float32(float64(v3.X) * float64(v29))
		v31 = v3.Y - int32(v27)
	}
	v7 = dword_5d4594_1217464
	if dword_5d4594_1217464 > 0 {
		for v32 := int32(0); ; {
			a2a := arr_5d4594_1203876[v32]
			var a3a Point32
			if v32 == v7-1 {
				a3a = arr_5d4594_1203876[0]
			} else {
				a3a = arr_5d4594_1203876[v32+1]
			}
			v38 = sub_4990D0(&a2a, &a3a)
			if int32(v38) != 0 && ((int32(v6)&1) == 0 || a2a.X <= v3.X || a2a.X <= v4.X || a3a.X <= v3.X || a3a.X <= v4.X) && ((int32(v37)&2) == 0 || a2a.X >= v3.X || a2a.X >= v4.X || a3a.X >= v3.X) {
				if (int32(v37)&4) == 0 || (func() bool {
					v11 = v3.Y
					return a2a.Y <= v11
				}()) || (func() bool {
					v12 = a2.Y
					return a2a.Y <= v12
				}()) || a3a.Y <= v11 || a3a.Y <= v12 {
					if (int32(v37)&8) == 0 || (func() bool {
						v13 = v3.Y
						return a2a.Y >= v13
					}()) || (func() bool {
						v14 = a2.Y
						return a2a.Y >= v14
					}()) || a3a.Y >= v13 || a3a.Y >= v14 {
						if a2a.X == a3a.X {
							if int32(v37) == 4 || int32(v37) == 8 {
								goto LABEL_65
							}
							if int32(v37) != 1 && int32(v37) != 2 {
								a1a.X = a2a.X
								v26 = float32(float64(a2a.X) * float64(v29))
								a1a.Y = v31 + int32(v26)
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									sub_499130(a1a)
								}
								goto LABEL_65
							}
							a1a.Y = v3.X
							a1a.X = a2a.X
							if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
								sub_499130(a1a)
								goto LABEL_65
							}
						} else {
							v28 = float32(float64(a3a.Y-a2a.Y) / float64(a3a.X-a2a.X))
							v21 = float32(float64(a2a.X) * float64(v28))
							v15 = int32(v21)
							v16 = a2a.Y - v15
							if int32(v37) == 4 || int32(v37) == 8 {
								if int32(v38) == 1 || int32(v38) == 2 {
									a1a.X = v3.X
									a1a.Y = a2a.X
									if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
										sub_499130(a1a)
									}
								} else {
									a1a.X = v3.X
									v22 = float32(float64(a1a.X) * float64(v28))
									a1a.Y = v16 + int32(v22)
									if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
										sub_499130(a1a)
									}
								}
							}
							if int32(v37) == 1 || int32(v37) == 2 {
								if int32(v38) == 1 || int32(v38) == 2 {
									goto LABEL_65
								}
								v25 = float32(float64(v31-v16) / float64(v28))
								v17 = int32(v25)
								v18 = v3.Y
								a1a.X = v17
								a1a.Y = v18
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									sub_499130(a1a)
								}
								goto LABEL_65
							}
							if v29 != v28 {
								v39 = float32(float64(v31 - v16))
								v30 = v28 - v29
								v23 = v39 / v30
								a1a.X = int32(v23)
								v24 = v39 * v28 / v30
								a1a.Y = v16 + int32(v24)
								if sub_499160(&a1a, &a2a, &a3a) != 0 && sub_499160(&a1a, v3, a2) != 0 {
									sub_499130(a1a)
									goto LABEL_65
								}
							}
						}
					}
				}
			}
		LABEL_65:
			v7 = dword_5d4594_1217464
			v32++
			if v32 >= dword_5d4594_1217464 {
				break
			}
			v6 = v37
			v4 = a2
		}
	}
	sub_4991E0(v3)
	return int32(dword_5d4594_1217452)
}

func sub_4992B0(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
	)
	result = 0
	v7 = 0
	v8 = 0
	if dword_5d4594_1217464 <= 0 {
		return result
	}
	v3 = dword_5d4594_1217464*8 - 8
	for v8 < dword_5d4594_1217464 {
		v4 = arr_5d4594_1203876[v3/8].X
		v5 = arr_5d4594_1203876[v3/8].Y
		v6 = arr_5d4594_1203876[v8].Y
		if v6 > a2 {
			if v5 > a2 {
				v3 = func() int32 {
					p := &v8
					x := *p
					*p++
					return x
				}() * 8
				continue
			}
		} else if a2 < v5 {
			goto LABEL_8
		}
		if a2 >= v6 {
			v3 = func() int32 {
				p := &v8
				x := *p
				*p++
				return x
			}() * 8
			continue
		}
	LABEL_8:
		if a1 >= arr_5d4594_1203876[v8].X+(a2-v6)*(v4-arr_5d4594_1203876[v8].X)/(v5-v6) {
			result = v7
		} else {
			result = bool2int32(v7 == 0)
			v7 = bool2int32(v7 == 0)
		}
		v3 = func() int32 {
			p := &v8
			x := *p
			*p++
			return x
		}() * 8
	}
	return result
}

func sub_498130(a1 *SightStructXxx) {
	for i := sub_498290(a1); i < dword_5d4594_1217460; i++ {
		v2 := dword_5d4594_1217456[i]
		if v2.Field40 > a1.Field44 {
			break
		}
		sub_498380(a1, dword_5d4594_1217456[i])
		if int32(a1.Field48) == 0 || a1.Field44-a1.Field40 < 0 {
			sub_4CAE40(a1)
			return
		}
		if int32(v2.Field48) == 0 || v2.Field44-v2.Field40 < 0 {
			if sub_4982E0(v2) <= i {
				i--
			}
			sub_4CAE40(v2)
		}
	}
	sub_4981D0(a1)
}
func sub_4981D0(a1 *SightStructXxx) {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	v1 = dword_5d4594_1217460 - 1
	v2 = 0
	for v2 <= v1 {
		v3 = (v1 + v2) / 2
		if dword_5d4594_1217456[v3].Field40 >= a1.Field40 {
			v1 = v3 - 1
		} else {
			v2 = v3 + 1
		}
	}
	sub_498220(a1, v2)
}
func sub_498220(a1 *SightStructXxx, a2 int32) {
	if a2 < dword_5d4594_1217460 {
		libc.MemMove(unsafe.Pointer(&dword_5d4594_1217456[a2+1]), unsafe.Pointer(&dword_5d4594_1217456[a2]), int((uint32(dword_5d4594_1217460)+uint32(a2)*0x3FFFFFFF)*4))
	}
	dword_5d4594_1217456[a2] = a1
	dword_5d4594_1217460++
}
func sub_498290(a1 *SightStructXxx) int32 {
	var (
		v1 int32
		v2 int32
		v3 int32
	)
	v1 = 0
	v2 = dword_5d4594_1217460 - 1
	if dword_5d4594_1217460-1 < 0 {
		return 0
	}
	for {
		v3 = (v2 + v1) / 2
		if dword_5d4594_1217456[v3].Field44 >= a1.Field40 {
			v2 = v3 - 1
		} else {
			v1 = v3 + 1
		}
		if v1 > v2 {
			break
		}
	}
	if v2 >= 0 {
		return v2
	} else {
		return 0
	}
}
func sub_4982E0(a1 *SightStructXxx) int32 {
	v1 := sub_498330(a1)
	libc.MemMove(unsafe.Pointer(&dword_5d4594_1217456[v1]), unsafe.Pointer(&dword_5d4594_1217456[v1+1]), int((dword_5d4594_1217460+int32(v1+1)*0x3FFFFFFF)*4))
	dword_5d4594_1217460--
	return v1
}
func sub_498330(a1 *SightStructXxx) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		result int32
		v5     int32
	)
	v1 = a1.Field40
	v2 = 0
	v3 = dword_5d4594_1217460 - 1
	for {
		result = (v3 + v2) / 2
		v5 = dword_5d4594_1217456[result].Field40
		if v5 == v1 {
			break
		}
		if v5 >= v1 {
			v3 = (v3 + v2) / 2
		} else {
			v2 = result + 1
		}
		if v2 > v3 {
			panic(-1)
		}
	}
	return result
}
func sub_498110() {
	for result := sub_4CAEB0(); result != nil; result = sub_4CAEB0() {
		sub_498130(result)
	}
}
func sub_4CAEB0() *SightStructXxx {
	result := dword_5d4594_1522596
	if dword_5d4594_1522596 != nil {
		dword_5d4594_1522596 = dword_5d4594_1522596.Field12
	}
	return result
}
func sub_4CAE90(a1 *SightStructXxx) {
	a1.Field12 = dword_5d4594_1522596
	dword_5d4594_1522596 = a1
}
func sub_496120() int32 {
	if dword_5d4594_1217456 != nil {
		alloc.FreeSlice(dword_5d4594_1217456)
		dword_5d4594_1217456 = nil
	}
	return 1
}
func sub_4960B0() int32 {
	dword_5d4594_1217456, _ = alloc.Make([]*SightStructXxx{}, uintptr(nox_win_width*4/23*(nox_win_height/23)/2))
	if dword_5d4594_1217456 == nil {
		return 0
	}
	sub_4CA860()
	return 1
}
func sub_4CA860() {
	ca := *memmap.PtrFloat64(0x581450, 9960)
	cb := *memmap.PtrFloat64(0x581450, 9952)
	for i := range arr_5d4594_1322584 {
		v1 := int64(math.Atan2(float64(i)*ca, 1.0)*cb + qword_581450_9544)
		arr_5d4594_1322584[i] = int16(v1)
	}
}
func sub_4CAED0(a1 *SightStructXxx) *SightStructXxx {
	p := sub_4CADD0()
	p.Field24 = a1.Field24
	p.Field32 = a1.Field32
	p.Field36 = a1.Field36
	p.Field40 = a1.Field40
	p.Field44 = a1.Field44
	p.Field48 = a1.Field48
	p.Field56 = a1.Field56
	p.Field20 = a1.Field20
	return p
}

type SightStructXxx struct {
	Field0  uint32           // 0, 0
	Field4  uint32           // 1, 4
	Field8  *SightStructXxx  // 2, 8
	Field12 *SightStructXxx  // 3, 12
	Field16 *SightStructXxx  // 4, 16
	Field20 *client.Drawable // 5, 20
	Field24 Point32          // 6, 24
	Field32 int32            // 8, 32
	Field36 byte             // 9, 36
	Field37 byte             // 9, 37
	Field38 uint16           // 9, 38
	Field40 int32            // 10, 40
	Field44 int32            // 11, 44
	Field48 byte             // 12, 48
	Field49 byte             // 12, 49
	Field50 uint16           // 12, 50
	Field52 uint32           // 13, 52
	Field56 byte             // 14, 56
	Field57 byte             // 14, 57
	Field58 uint16           // 14, 58
}

func sub_4CADD0() *SightStructXxx {
	result := dword_5d4594_1522584
	if dword_5d4594_1522584 == nil {
		for i := 0; i < 10; i++ {
			p, _ := alloc.New(SightStructXxx{})
			p.Field16 = dword_5d4594_1522584
			dword_5d4594_1522584 = p
			p.Field8 = dword_5d4594_1522592
			dword_5d4594_1522592 = p
		}
		dword_5d4594_1522588 += 10
		result = dword_5d4594_1522584
	}
	dword_5d4594_1522584 = result.Field16
	return result
}
func nox_xxx_drawBlackofWall_497C40(a1 int32, a2 int32, a3 int8) {
	v21 := a1 * 23
	v22 := a2 * 23
	v3 := a1*23 + 11
	v4 := a2*23 + 11
	v5 := sub_4CADD0()
	v5.Field24.X = a1
	v5.Field24.Y = a2
	v5.Field36 = uint8(a3)
	v5.Field48 = 1
	v5.Field56 = 0
	var v6, v7, v8, v9, v23 int32
	var v24 int32 // FIXME: uninitialized!
	switch a3 {
	case 1:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X + 5
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y - 5
		v8 = v3
		v9 = a2 * 23
		v23 = v21 + 23
	case 2:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X - 5
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y - 5
		v8 = v3
		v9 = a2 * 23
		v23 = a1 * 23
	case 4:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X + 5
		v10 := 5
		v8 = v3
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y + int32(v10)
		v23 = v21 + 23
		v9 = v22 + 23
	case 6:
		v8 = a1 * 23
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y
		v4 = a2 * 23
		v6 = int32(v3) - dword_5d4594_1217444_vec.X
		v23 = v21 + 23
		v9 = v22 + 23
	case 8:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X - 5
		v23 = a1 * 23
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y + 5
		v8 = v3
		v9 = v22 + 23
	case 9:
		v6 = int32(v3) - dword_5d4594_1217444_vec.X
		v7 = int32(v4) - dword_5d4594_1217444_vec.Y
		v4 = a2 * 23
		v8 = v21 + 23
		v23 = a1 * 23
		v9 = v22 + 23
	default:
		v6 = a1
		v7 = a1
		v4 = v24
		v8 = v23
		v9 = v24
	}
	v5.Field32 = v6*v6 + v7*v7
	v11 := sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, int32(v8)-dword_5d4594_1217444_vec.X)
	v5.Field40 = v11
	if v11 < 0 {
		for {
			v12 := v5.Field40
			v5.Field40 = v12 + 75000
			if v5.Field40 >= 0 {
				break
			}
		}
	}
	if v5.Field40 >= 75000 {
		for {
			v13 := v5.Field40 - 75000
			v5.Field40 = v13
			if v13 < 75000 {
				break
			}
		}
	}
	v14 := sub_4CA8B0(int32(v9)-dword_5d4594_1217444_vec.Y, int32(v23)-dword_5d4594_1217444_vec.X)
	v5.Field44 = v14
	if v14 < 0 {
		for {
			v15 := v5.Field44
			v5.Field44 = v15 + 75000
			if v15+75000 >= 0 {
				break
			}
		}
	}
	if v5.Field44 >= 75000 {
		for {
			v16 := v5.Field44 - 75000
			v5.Field44 = v16
			if v16 < 75000 {
				break
			}
		}
	}
	v17 := v5.Field44
	v18 := v5.Field40
	if v17 < v18 {
		v5.Field40 = v17
		v5.Field44 = v18
	}
	if v5.Field44-v5.Field40 < 37500 {
		sub_4CAE90(v5)
		return
	}
	v19 := sub_4CAED0(v5)
	v19.Field40 = 0
	v19.Field44 = v5.Field40
	v5.Field40 = v5.Field44
	v5.Field44 = 74999
	sub_4CAE90(v19)
	sub_4CAE90(v5)
}
func sub_4974B0(a1 *client.Drawable) {
	var (
		v3  int32
		v4  float64
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v14 float32
		v15 int32
	)
	v1 := a1
	if (a1.Flags29() & 4) == 0 {
		v2 := sub_4CADD0()
		v2.Field48 = 1
		v2.Field56 = 6
		v2.Field20 = a1
		v3 = int32(a1.Field_74_4) * 8
		v4 = float64(int32(dword_5d4594_1217444_vec.X - int32(*memmap.PtrInt32(0x587000, uintptr(v3)+196184)/2) - int32(a1.PosVec.X)))
		v15 = dword_5d4594_1217444_vec.Y - int32(*memmap.PtrInt32(0x587000, uintptr(v3)+196188)/2) - int32(a1.PosVec.Y)
		v14 = float32(float64(v15)*float64(v15) + v4*v4)
		v2.Field32 = int32(v14)
		v5 = sub_4CA8B0(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y)), int32(v1.PosVec.X-int(dword_5d4594_1217444_vec.X)))
		v2.Field40 = v5
		if v5 < 0 {
			for {
				v6 = v2.Field40
				v2.Field40 = v6 + 75000
				if v6+75000 >= 0 {
					break
				}
			}
		}
		if v2.Field40 >= 75000 {
			for {
				v7 = v2.Field40 - 75000
				v2.Field40 = v7
				if v7 < 75000 {
					break
				}
			}
		}
		v8 = sub_4CA8B0(int32(v1.PosVec.Y+int(int32(*memmap.PtrInt32(0x587000, uintptr(int32(v1.Field_74_4)*8)+196188)))-int(dword_5d4594_1217444_vec.Y)), int32(v1.PosVec.X+int(int32(*memmap.PtrInt32(0x587000, uintptr(int32(v1.Field_74_4)*8)+196184)))-int(dword_5d4594_1217444_vec.X)))
		v2.Field44 = v8
		if v8 < 0 {
			for {
				v9 = v2.Field44
				v2.Field44 = v9 + 75000
				if v9+75000 >= 0 {
					break
				}
			}
		}
		if v2.Field44 >= 75000 {
			for {
				v10 = v2.Field44 - 75000
				v2.Field44 = v10
				if v10 < 75000 {
					break
				}
			}
		}
		v11 = v2.Field44
		v12 = v2.Field40
		if v11 < v12 {
			v2.Field40 = v11
			v2.Field44 = v12
		}
		if float64(int32(v2.Field44-v2.Field40)) >= 37500.0 {
			v13 := sub_4CAED0(v2)
			v13.Field40 = 0
			v13.Field44 = v2.Field40
			v2.Field40 = v2.Field44
			v2.Field44 = 74999
			sub_4CAE90(v13)
		}
		sub_4CAE90(v2)
	}
}
func sub_497650(a1 *client.Drawable) {
	var (
		v4  int32
		v5  float64
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v21 float32
		v22 int32
		v23 float32
		v24 float32
	)
	v1 := sub_4CADD0()
	v2 := a1
	v3 := v1
	v1.Field48 = 1
	v1.Field56 = 7
	v1.Field20 = a1
	v4 = int32(a1.PosVec.Y)
	v24 = float32(float64(int32(a1.PosVec.X - int(dword_5d4594_1217444_vec.X))))
	v5 = float64(int32(int32(v4) - dword_5d4594_1217444_vec.Y))
	v23 = float32(v5)
	v21 = float32(v5*float64(v23) + float64(v24*v24))
	v6 = int32(v21)
	v3.Field32 = v6
	v7 = int32(int64(math.Sqrt(float64(v6))))
	v22 = int32(v24)
	v8 = int32(v23)
	v9 = sub_4CA8B0(v8, v22)
	v10 = int32(v2.Shape.Circle.R)
	v11 = sub_4CA8B0(v10, v7)
	v3.Field40 = v11 + v9
	if v11+v9 < 0 {
		for {
			v12 = v3.Field40
			v3.Field40 = v12 + 75000
			if v12+75000 >= 0 {
				break
			}
		}
	}
	if v3.Field40 >= 75000 {
		for {
			v13 = v3.Field40 - 75000
			v3.Field40 = v13
			if v13 < 75000 {
				break
			}
		}
	}
	v14 = v9 - v11
	v3.Field44 = v14
	if v14 < 0 {
		for {
			v15 = v3.Field44
			v3.Field44 = v15 + 75000
			if v15+75000 >= 0 {
				break
			}
		}
	}
	if v3.Field44 >= 75000 {
		for {
			v16 = v3.Field44 - 75000
			v3.Field44 = v16
			if v16 < 75000 {
				break
			}
		}
	}
	v17 = v3.Field44
	v18 = v3.Field40
	if v17 < v18 {
		v3.Field40 = v17
		v3.Field44 = v18
	}
	if float64(v3.Field44-v3.Field40) < 37500.0 {
		sub_4CAE90(v3)
		return
	}
	v19 := sub_4CAED0(v3)
	v19.Field40 = 0
	v19.Field44 = v3.Field40
	v3.Field40 = v3.Field44
	v3.Field44 = 74999
	sub_4CAE90(v19)
	sub_4CAE90(v3)
}
func sub_4977C0(a1 *client.Drawable) {
	var (
		v2     float64
		v3     float64
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		result int32
		v12    float64
		v13    int32
		v14    float64
		v15    int32
		v16    float64
		v17    int32
		v18    float64
		v19    int32
		v20    float64
		v21    int32
		v22    float64
		v23    int32
		v24    float32
		v25    float32
		v26    float32
		v27    float32
		v28    float32
		v29    float32
		v30    int32
		v31    int32
		v32    int32
		v33    int32
		v34    float32
		v35    float32
		v36    float32
		v37    float32
		v38    [8]float32
		v39    float32
		v40    int32
	)
	v1 := a1
	v2 = float64(a1.PosVec.X)
	v38[0] = float32(v2 + float64(a1.Shape.Box.LeftTop))
	v3 = float64(a1.PosVec.Y)
	v39 = float32(v3)
	v38[1] = float32(v3 + float64(v1.Shape.Box.LeftBottom))
	v38[2] = float32(v2 + float64(v1.Shape.Box.LeftBottom2))
	v38[3] = v39 + v1.Shape.Box.LeftTop2
	v38[4] = float32(v2 + float64(v1.Shape.Box.RightTop))
	v38[5] = v39 + v1.Shape.Box.RightBottom
	v38[6] = float32(v2 + float64(v1.Shape.Box.RightBottom2))
	v38[7] = v39 + v1.Shape.Box.RightTop2
	v30 = int32(int32(v38[0])) - dword_5d4594_1217444_vec.X
	v4 = int32(v38[1])
	v5 = sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, v30)
	v31 = int32(int32(v38[2])) - dword_5d4594_1217444_vec.X
	v6 = int32(v38[3])
	v7 = sub_4CA8B0(int32(v6)-dword_5d4594_1217444_vec.Y, v31)
	v32 = int32(int32(v38[4])) - dword_5d4594_1217444_vec.X
	v8 = int32(v38[5])
	v9 = sub_4CA8B0(int32(v8)-dword_5d4594_1217444_vec.Y, v32)
	v33 = int32(int32(v38[6])) - dword_5d4594_1217444_vec.X
	v10 = int32(v38[7])
	v40 = sub_4CA8B0(int32(v10)-dword_5d4594_1217444_vec.Y, v33)
	result = int32(uint8(sub_497B80(&v38, &dword_5d4594_1217444_vec))) - 1
	switch result {
	case 0:
		v35 = float32(float64(v38[5]+v38[1]) * 0.5)
		v14 = float64(v38[4]+v38[0])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v25 = float32((float64(v35)-float64(dword_5d4594_1217444_vec.Y))*(float64(v35)-float64(dword_5d4594_1217444_vec.Y)) + v14*v14)
		v15 = int32(v25)
		sub_497F60(v5, v9, 9, v15, v1)
	case 1:
		v37 = float32(float64(v38[7]+v38[3]) * 0.5)
		v18 = float64(v38[6]+v38[2])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v27 = float32((float64(v37)-float64(dword_5d4594_1217444_vec.Y))*(float64(v37)-float64(dword_5d4594_1217444_vec.Y)) + v18*v18)
		v19 = int32(v27)
		sub_497F60(v40, v7, 10, v19, v1)
	case 3:
		v34 = float32(float64(v38[3]+v38[1]) * 0.5)
		v12 = float64(v38[2]+v38[0])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v24 = float32((float64(v34)-float64(dword_5d4594_1217444_vec.Y))*(float64(v34)-float64(dword_5d4594_1217444_vec.Y)) + v12*v12)
		v13 = int32(v24)
		sub_497F60(v5, v7, 8, v13, v1)
	case 4, 9:
		v22 = float64(int32(v1.PosVec.X - int(dword_5d4594_1217444_vec.X)))
		v29 = float32(float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y)))*float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y))) + v22*v22)
		v23 = int32(v29)
		sub_497F60(v7, v9, 14, v23, v1)
	case 5, 8:
		v20 = float64(int32(v1.PosVec.X - int(dword_5d4594_1217444_vec.X)))
		v28 = float32(float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y)))*float64(int32(v1.PosVec.Y-int(dword_5d4594_1217444_vec.Y))) + v20*v20)
		v21 = int32(v28)
		sub_497F60(v5, v40, 13, v21, v1)
	case 7:
		v36 = float32(float64(v38[7]+v38[5]) * 0.5)
		v16 = float64(v38[6]+v38[4])*0.5 - float64(dword_5d4594_1217444_vec.X)
		v26 = float32((float64(v36)-float64(dword_5d4594_1217444_vec.Y))*(float64(v36)-float64(dword_5d4594_1217444_vec.Y)) + v16*v16)
		v17 = int32(v26)
		sub_497F60(v40, v9, 11, v17, v1)
	}
}
func sub_498030(a1 *noxrender.Viewport) {
	v1 := int32(a1.World.Min.X)
	v2 := int32(a1.World.Min.Y)
	v3 := int32(a1.Size.X + int(uint32(v1)))
	v4 := int32(a1.Size.Y + int(uint32(v2)))
	v9 := sub_4CA8B0(int32(v2)-dword_5d4594_1217444_vec.Y, int32(v1)-dword_5d4594_1217444_vec.X)
	v5 := sub_4CA8B0(int32(v2)-dword_5d4594_1217444_vec.Y, int32(v3)-dword_5d4594_1217444_vec.X)
	v6 := sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, int32(v3)-dword_5d4594_1217444_vec.X)
	v7 := sub_4CA8B0(int32(v4)-dword_5d4594_1217444_vec.Y, int32(v1)-dword_5d4594_1217444_vec.X)
	sub_497F60(v9, v5, 1, math.MaxInt32, nil)
	sub_497F60(v5, v6, 4, math.MaxInt32, nil)
	sub_497F60(v6, v7, 2, math.MaxInt32, nil)
	sub_497F60(v7, v9, 3, math.MaxInt32, nil)
}

func sub_497B80(a1 *[8]float32, a2 *Point32) int8 {
	v2 := a2
	v4 := int8(0)
	v9 := float32(float64(a2.X))
	v7 := float32(float64(v2.Y))
	v5 := float64(a1[5]+a1[4]-v9-v7) * 0.70709997
	v8 := float32(float64(a1[1]+a1[0]-v9-v7) * 0.70709997)
	if float64(a1[1]-a1[0]+v9-v7)*0.70709997 <= 0.0 {
		if float64(a1[3]-a1[2]+v9-v7)*0.70709997 < 0.0 {
			v4 = 2
		}
	} else {
		v4 = 1
	}
	if v5 < 0.0 {
		return int8(int32(v4) | 8)
	}
	if float64(v8) > 0.0 {
		v4 |= 4
	}
	return v4
}

func sub_4CA8B0(a1 int32, a2 int32) int32 {
	v2 := a2
	if a2 == 0 {
		if a1 <= 0 {
			return 56250
		}
		return 18750
	}
	v4 := a1
	var v6 int32
	if a2 >= 0 {
		if a1 >= 0 {
			v6 = 1
		} else {
			v6 = 4
			v4 = -v4
		}
	} else {
		if a1 >= 0 {
			v6 = 2
		} else {
			v4 = -a1
			v6 = 3
		}
		v2 = -a2
	}
	v5 := v4 * 1000 / v2
	if v5 >= 100000 {
		v5 = 99999
	}
	result := int32(arr_5d4594_1322584[v5])
	switch v6 {
	case 2:
		return 37500 - result
	case 3:
		result += 37500
	case 4:
		result = 75000 - result
	}
	return result
}
func sub_4CA960(a1 *Point32, a2 int8, a3 *float4, a4 *types.Pointf) {
	var (
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		a1a Point32
	)
	v4 = a1.Y
	a1a.X = a1.X * 23
	a1a.Y = v4 * 23
	switch a2 {
	case 1:
		v6 = 11
		sub_4CAA90(&a1a, a3, a4, v6, 23)
	case 2:
		v5 = 11
		sub_4CAC30(&a1a, a3, a4, 0, v5)
	case 4:
		v8 = 11
		sub_4CAC30(&a1a, a3, a4, v8, 23)
	case 6:
		sub_4CAC30(&a1a, a3, a4, 0, 23)
	case 8:
		v7 = 11
		sub_4CAA90(&a1a, a3, a4, 0, v7)
	case 9:
		sub_4CAA90(&a1a, a3, a4, 0, 23)
	default:
		return
	}
}
func sub_4CAA90(a1 *Point32, a2 *float4, a3 *types.Pointf, a4 int32, a5 int32) {
	var (
		v5  int32
		v6  int32
		v7  float64
		v8  int32
		v9  float64
		v11 float64
		v13 float64
		v14 float64
		v15 float64
		v16 float64
		v17 float64
		v18 float32
		v19 float32
		v20 float32
		v21 float64
		v22 float32
		v23 float32
	)
	v5 = a5 + a1.X
	v6 = a1.Y - a5 + 22
	v22 = float32(float64(a1.X + a4))
	v7 = float64(v5)
	v23 = float32(v7)
	v18 = float32(v7 + float64(v6))
	v8 = int32(v18)
	if a2.field_8 == a2.field_0 {
		v9 = float64(a2.field_8)
		a3.X = a2.field_8
		a3.Y = float32(float64(v8) - v9)
	} else {
		v11 = float64(a2.field_C)
		if v11 == float64(a2.field_4) {
			a3.Y = a2.field_C
			a3.X = float32(float64(v8) - v11)
		} else {
			v13 = (v11 - float64(a2.field_4)) / float64(a2.field_8-a2.field_0)
			if v13 == -1.0 {
				v13 = -0.99000001
			}
			v14 = float64(v8)
			v20 = float32(v14)
			v15 = float64(float32((v14 - (float64(a2.field_4) - v13*float64(a2.field_0))) / (v13 + qword_581450_9512)))
			v16 = cmath.Modf(v15, &v21)
			v19 = float32(v16)
			v17 = float64(float32(v21))
			a3.X = float32(v17)
			if float64(v19) <= qword_581450_9544 {
				if float64(v19) < *memmap.PtrFloat64(0x581450, 9968) {
					a3.X = float32(v17 - 1.0)
				}
			} else {
				a3.X = float32(v17 + 1.0)
			}
			if float64(a3.X) >= float64(v22) {
				if float64(a3.X) > float64(v23) {
					a3.X = v23
				}
				a3.Y = v20 - a3.X
			} else {
				a3.X = v22
				a3.Y = v20 - a3.X
			}
		}
	}
}

func sub_497260(a1 *noxrender.Viewport) {
	var (
		v4  float64
		v5  float64
		v6  int32
		v7  float64
		v8  float64
		v9  float64
		v10 float64
		v11 float32
		v12 float32
		v13 float32
		v14 float32
		v15 float32
		v16 float32
		v17 float32
		v18 float32
		v19 float32
		v20 float32
		v21 float32
		v22 float32
	)
	result := nox_xxx_sprite_45A030()
	v2 := result
	if result == nil {
		return
	}
	v3 := a1
	for {
		v2.Field_33 = 0
		if !nox_client_drawable_testBuff_4356C0(v2, 0) {
			if int8(byte(v2.Flags28())) >= 0 {
				v6 = int32(v2.Shape.Kind)
				if v6 == 2 {
					v7 = float64(v2.PosVec.X)
					v8 = float64(v2.PosVec.Y)
					if v7-float64(v2.Shape.Circle.R) < float64(v3.World.Min.X+v3.Size.X) {
						v21 = float32(v7)
						v15 = v21 + v2.Shape.Circle.R
						if float64(v3.World.Min.X) < float64(v15) {
							v12 = float32(v8 - float64(v2.Shape.Circle.R))
							if float64(v3.World.Min.Y+v3.Size.Y) > float64(v12) {
								v18 = float32(v8 + float64(v2.Shape.Circle.R))
								if float64(v3.World.Min.Y) < float64(v18) {
									sub_497650(v2)
								}
							}
						}
					}
				} else if v6 == 3 {
					v9 = float64(v2.PosVec.X)
					v10 = float64(v2.PosVec.Y)
					if v9+float64(v2.Shape.Box.LeftBottom2) < float64(v3.World.Min.X+v3.Size.X) {
						v22 = float32(v9)
						v16 = v22 + v2.Shape.Box.RightTop
						if float64(v3.World.Min.X) < float64(v16) {
							v13 = float32(v10 + float64(v2.Shape.Box.LeftBottom))
							if float64(v3.World.Min.Y+v3.Size.Y) > float64(v13) {
								v19 = float32(v10 + float64(v2.Shape.Box.RightTop2))
								if float64(v3.World.Min.Y) < float64(v19) {
									sub_4977C0(v2)
								}
							}
						}
					}
				}
			} else {
				v4 = float64(v2.PosVec.X)
				v5 = float64(v2.PosVec.Y)
				if v4-32.0 < float64(v3.World.Min.X+v3.Size.X) {
					v20 = float32(v4)
					v14 = float32(float64(v20) + 32.0)
					if float64(v3.World.Min.X) < float64(v14) {
						v11 = float32(v5 - 32.0)
						if float64(v3.World.Min.Y+v3.Size.Y) > float64(v11) {
							v17 = float32(v5 + 32.0)
							if float64(v3.World.Min.Y) < float64(v17) {
								sub_4974B0(v2)
							}
						}
					}
				}
			}
		}
		result = sub_45A040(v2)
		v2 = result
		if result == nil {
			break
		}
	}
}

func sub_498B50(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v12    int32
		v13    int32
		result int32
		v15    uint8
		v16    int32
		v17    int32
		v18    int32
	)
	v4 = a3
	v5 = a1
	v6 = a2
	v7 = a2 - a4
	v8 = a1 - a3
	v9 = a1 - a3
	v10 = a4 - a2
	if a1-a3 < 0 {
		v8 = a3 - a1
	}
	if v7 < 0 {
		v7 = a4 - a2
	}
	if v8 <= v7 {
		v16 = 0
		if v10 < 0 {
			v17 = 1
		} else {
			v17 = -1
		}
	} else {
		v17 = 0
		v11 := uint32(bool2int32(v9 < 0) - 1)
		v11 &= 0xFFFFFFFE
		v16 = int32(v11 + 1)
	}
	v15 = 208
	v12 = a4 - v6
	v13 = v4 - v5
	v18 = 10
	for {
		nox_client_drawSetAlpha_434580(v15)
		v15 -= 20
		nox_client_drawAddPoint_49F500(v5, v6)
		nox_client_drawAddPoint_49F500(v5+v13, v12+v6)
		nox_client_drawLineFromPoints_49E4B0()
		v5 += v17
		v6 += v16
		result = func() int32 {
			p := &v18
			*p--
			return *p
		}()
		if v18 == 0 {
			break
		}
	}
	return result
}
func sub_499130(a1 Point32) {
	if dword_5d4594_1217452 >= len(arr_5d4594_1212068) {
		return
	}
	arr_5d4594_1212068[dword_5d4594_1217452] = a1
	dword_5d4594_1217452++
}
func sub_499290(a1 int32) Point32 {
	return arr_5d4594_1212068[a1]
}
func sub_4991E0(a1 *Point32) {
	v1 := dword_5d4594_1217452
	if dword_5d4594_1217452 > 0 {
		v2 := a1
		v3 := 1
		v12 := 1
		for {
			v4 := &arr_5d4594_1212068[v3-1]
			v5 := v4.Y - v2.Y
			v6 := (v4.X-v2.X)*(v4.X-v2.X) + int32(v5*v5)
			if v3 < v1 {
				for i := 0; i < v1-v3; i++ {
					v7 := &arr_5d4594_1212068[v3+i]
					v8 := v7.Y - v2.Y
					v9 := (v7.X-v2.X)*(v7.X-v2.X) + int32(v8*v8)
					if v9 < v6 {
						v10 := int32(v4.Y)
						v6 = v9
						v11 := v4.X
						v4.X = v7.X
						v4.Y = v7.Y
						v7.X = v11
						v7.Y = v10
					}
				}
				v1 = dword_5d4594_1217452
				v3 = v12
			}
			v3++
			v12 = v3
			if v3-1 >= v1 {
				break
			}
		}
	}
}
func sub_4990D0(a1 *Point32, a2 *Point32) int8 {
	if a1.X <= a2.X {
		if a1.X >= a2.X {
			v7 := int32(a1.Y)
			v8 := int32(a2.Y)
			if v7 <= v8 {
				if v7 >= v8 {
					return 0
				} else {
					return 8
				}
			} else {
				return 4
			}
		} else {
			v5 := int32(a1.Y)
			v6 := int32(a2.Y)
			if v5 <= v6 {
				if v5 < v6 {
					return 10
				}
			} else {
				return 6
			}
			return 2
		}
	} else {
		v2 := int32(a1.Y)
		v3 := int32(a2.Y)
		if v2 <= v3 {
			if v2 < v3 {
				return 9
			}
		} else {
			return 5
		}
		return 1
	}
}
func sub_499160(a1 *Point32, a2 *Point32, a3 *Point32) int32 {
	var (
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		result int32
	)
	v3 = a3.X
	if a3.X > a2.X {
		v4 = a3.Y
		if v4 > a2.Y {
			v3 = a3.X
			v6 = a2.X
			v4 = a2.Y
			v5 = a3.Y
		} else {
			v6 = a2.X
			v5 = a2.Y
		}
	} else {
		v4 = a2.Y
		if a3.Y > v4 {
			v6 = a3.X
			v3 = a2.X
			v5 = a3.Y
		} else {
			v5 = a2.Y
			v6 = a3.X
			v4 = a3.Y
			v3 = a2.X
		}
	}
	result = 0
	if !(a1.X >= v6 && a1.X <= v3) {
		return result
	}
	v7 = a1.Y
	if v7 >= v4 && v7 <= v5 {
		result = 1
	}
	return result
}
func sub_497F60(a1 int32, a2 int32, a3 int8, a4 int32, a5 *client.Drawable) {
	v5 := sub_4CADD0()
	v5.Field56 = uint8(a3)
	v5.Field32 = a4
	v5.Field48 = 1
	v5.Field20 = a5
	if a2 >= a1 {
		v5.Field40 = a1
		v5.Field44 = a2
	} else {
		v5.Field40 = a2
		v5.Field44 = a1
	}
	if v5.Field40 < 0 {
		for {
			v6 := int32(v5.Field40)
			v5.Field40 = v6 + 75000
			if v6+75000 >= 0 {
				break
			}
		}
	}
	if v5.Field40 >= 75000 {
		for {
			v7 := int32(v5.Field40 - 75000)
			v5.Field40 = v7
			if v7 < 75000 {
				break
			}
		}
	}
	if v5.Field44 < 0 {
		for {
			v8 := int32(v5.Field44)
			v5.Field44 = v8 + 75000
			if v8+75000 >= 0 {
				break
			}
		}
	}
	if v5.Field44 >= 75000 {
		for {
			v9 := int32(v5.Field44 - 75000)
			v5.Field44 = v9
			if v9 < 75000 {
				break
			}
		}
	}
	if v5.Field44-v5.Field40 < 37500 {
		sub_4CAE90(v5)
		return
	}
	v10 := sub_4CAED0(v5)
	v10.Field40 = 0
	v10.Field44 = v5.Field40
	v5.Field40 = v5.Field44
	v5.Field44 = 74999
	sub_4CAE90(v10)
	sub_4CAE90(v5)
}

func sub_4CAC30(a1 *Point32, a2 *float4, a3 *types.Pointf, a4 int32, a5 int32) {
	var (
		v5  int32
		v6  int32
		v7  int32
		v8  float64
		v9  float64
		v10 float64
		v11 float64
		v12 float64
		v13 float32
		v14 float32
		v15 float32
		v16 float64
		v17 float32
		v18 float32
	)
	v5 = a4 + a1.Y
	v6 = a5 + a1.X
	v17 = float32(float64(a1.X + a4))
	v18 = float32(float64(v6))
	v13 = float32(float64(v5) - float64(v17))
	v7 = int32(v13)
	if a2.field_8 == a2.field_0 {
		a3.X = a2.field_8
		a3.Y = float32(float64(v7) + float64(a2.field_8))
	} else if a2.field_C == a2.field_4 {
		a3.X = float32(float64(a2.field_C) - float64(v7))
		a3.Y = a2.field_C
	} else {
		v8 = float64((a2.field_C - a2.field_4) / (a2.field_8 - a2.field_0))
		if v8 == 1.0 {
			v8 = 0.99000001
		}
		v9 = float64(v7)
		v15 = float32(v9)
		v10 = float64(float32((v9 - (float64(a2.field_4) - v8*float64(a2.field_0))) / (v8 - qword_581450_9512)))
		v11 = cmath.Modf(v10, &v16)
		v14 = float32(v11)
		v12 = float64(float32(v16))
		a3.X = float32(v12)
		if float64(v14) <= qword_581450_9544 {
			if float64(v14) < *memmap.PtrFloat64(0x581450, 9968) {
				a3.X = float32(v12 - 1.0)
			}
		} else {
			a3.X = float32(v12 + 1.0)
		}
		if float64(a3.X) >= float64(v17) {
			if float64(a3.X) > float64(v18) {
				a3.X = v18
			}
			a3.Y = v15 + a3.X
		} else {
			a3.X = v17
			a3.Y = v15 + a3.X
		}
	}
}
func sub_414C50(a1 int32) int32 {
	var (
		v1     int32
		v2     int32
		result int32
	)
	v1 = sub_414BD0(a1)
	v2 = sub_414BD0(6434 - a1)
	if v2 != 0 {
		result = (v1 << 12) / v2
	} else {
		result = bool2int32(v1 <= 0) + math.MaxInt32
	}
	return result
}
func sub_414BD0(a1 int32) int32 {
	v1 := a1
	if a1 < 0 {
		v1 = a1 + ((25735-a1)/0x6488)*25736
	}
	if v1 >= 25736 {
		v1 %= 0x6488
	}
	return memmap.Int32(0x85B3FC, uintptr(((v1<<12)/25736)*4+12260))
}
func sub_57BA30(a1 *Point32, a2 *Point32, a3 *image.Rectangle) int32 {
	v12 := false
	for {
		var v3b byte
		if int(a1.X) >= a3.Min.X {
			if int(a1.X) <= a3.Max.X {
				v3b = 0
			} else {
				v3b = 4
			}
		} else {
			v3b = 8
		}
		v4 := int(a1.Y)
		v5 := a3.Min.Y
		if v4 >= v5 {
			if v4 > a3.Max.Y {
				v3b |= 1
			}
		} else {
			v3b |= 2
		}
		var v6b byte
		if int(a2.X) >= a3.Min.X {
			if int(a2.X) <= a3.Max.X {
				v6b = 0
			} else {
				v6b = 4
			}
		} else {
			v6b = 8
		}
		v7 := int(a2.Y)
		if v7 >= v5 {
			if v7 > a3.Max.Y {
				v6b |= 1
			}
		} else {
			v6b |= 2
		}
		if v6b&v3b != 0 {
			if !v12 {
				return 0
			}
			v10 := a1.X
			v11 := a1.Y
			*a1 = *a2
			a2.X = v10
			a2.Y = v11
			return 0
		}
		if v3b == 0 {
			if v6b != 0 {
				v3a := a1.X
				v8 := a1.Y
				*a1 = *a2
				a2.X = v3a
				a2.Y = v8
				v3b = v6b
				v12 = !v12
			} else {
				if !v12 {
					return 1
				}
				v10 := a1.X
				v11 := a1.Y
				*a1 = *a2
				a2.X = v10
				a2.Y = v11
				return 1
			}
		}
		if v3b&1 != 0 {
			a1.X += int32(a3.Max.Y-int(a1.Y)) * (a2.X - a1.X) / (a2.Y - a1.Y)
			a1.Y = int32(a3.Max.Y)
		} else if v3b&2 != 0 {
			a1.X += int32(a3.Min.Y-int(a1.Y)) * (a2.X - a1.X) / (a2.Y - a1.Y)
			a1.Y = int32(a3.Min.Y)
		} else if v3b&4 != 0 {
			a1.Y += int32(a3.Max.X-int(a1.X)) * (a2.Y - a1.Y) / (a2.X - a1.X)
			a1.X = int32(a3.Max.X)
		} else if v3b&8 != 0 {
			a1.Y += int32(a3.Min.X-int(a1.X)) * (a2.Y - a1.Y) / (a2.X - a1.X)
			a1.X = int32(a3.Min.X)
		}
	}
}
func sub_498380(a1 *SightStructXxx, a2 *SightStructXxx) {
	var (
		v6  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 bool
		v13 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
	)
	v2 := int32(a1.Field40)
	v3 := int32(a2.Field44)
	if v3 < v2 {
		return
	}
	v4 := int32(a2.Field40)
	v5 := int32(a1.Field44)
	if v4 > v5 {
		return
	}
	if v4 < v2 {
		if v3 <= v5 {
			if a1.Field32 >= a2.Field32 {
				v6 = a1.Field44
				a1.Field40 = v3 + 1
				if v3+1 > v6 {
					a1.Field48 = 0
				}
			} else {
				a2.Field44 = v2 - 1
			}
			return
		}
		if a1.Field32 < a2.Field32 {
			v7 := sub_4CAED0(a2)
			v8 = v7.Field44
			v9 = a1.Field44 + 1
			v7.Field40 = v9
			if v9 > v8 {
				v7.Field48 = 0
			}
			v10 = a1.Field40 - 1
			v11 = a2.Field40
			a2.Field44 = v10
			if v11 > v10 {
				a2.Field48 = 0
			}
			sub_4CAE90(v7)
			return
		}
		a1.Field48 = 0
		return
	}
	v12 = v3 <= v5
	v13 = a1.Field32
	if v12 {
		if v13 >= a2.Field32 {
			v14 := sub_4CAED0(a1)
			v15 = v14.Field44
			v16 = a2.Field44 + 1
			v14.Field40 = v16
			if v16 > v15 {
				v14.Field48 = 0
			}
			v17 = a2.Field40 - 1
			v18 = a1.Field40
			a1.Field44 = v17
			if v18 > v17 {
				a1.Field48 = 0
			}
			sub_4CAE90(v14)
		} else {
			a2.Field48 = 0
		}
	} else {
		if v13 >= a2.Field32 {
			v21 = v4 - 1
			v22 = a1.Field40
			a1.Field44 = v21
			if v22 <= v21 {
				return
			}
			a1.Field48 = 0
			return
		}
		v19 = a2.Field44
		v20 = v5 + 1
		a2.Field40 = v20
		if v20 > v19 {
			a2.Field48 = 0
		}
	}
}
func sub_4CAE40(a1 *SightStructXxx) {
	a1.Field16 = dword_5d4594_1522584
	dword_5d4594_1522584 = a1
}
func sub_427C80(a1 *int4, a2 *int4) int32 {
	v2 := a1.field_0
	v3 := a1.field_4
	v4 := a1.field_8
	v19 := a1.field_C
	v5 := a2.field_0
	v21 := a2.field_4
	v17 := a2.field_C
	v6 := a2.field_8
	v7 := v4 - v2
	v8 := a2.field_0 - v6
	v20 := a2.field_0
	var v22 int32
	if v4-v2 >= 0 {
		v6 = a2.field_8
		v22 = v2
	} else {
		v22 = v4
		v4 = v2
	}
	if v8 <= 0 {
		if v4 < v5 || v6 < v22 {
			return 0
		}
	} else if v4 < v6 || v5 < v22 {
		return 0
	}
	v10 := v19
	v11 := v21 - v17
	v18 := v19 - v3
	var v23 int32
	if v19-v3 >= 0 {
		v23 = v3
	} else {
		v23 = v19
		v10 = v3
	}
	if v11 <= 0 {
		if v10 < v21 || v17 < v23 {
			return 0
		}
	} else {
		if v10 < v17 {
			return 0
		}
		if v21 < v23 {
			return 0
		}
	}
	v12 := v2 - v20
	v13 := v3 - v21
	v14 := v11*(v2-v20) - v8*(v3-v21)
	v15 := v8*v18 - v7*v11
	if v15 <= 0 {
		if v14 > 0 || v14 < v15 {
			return 0
		}
	} else {
		if v14 < 0 {
			return 0
		}
		if v14 > v15 {
			return 0
		}
	}
	v16 := v7*v13 - v18*v12
	if v15 <= 0 {
		if v16 <= 0 && v16 >= v15 {
			return 1
		}
		return 0
	}
	if v16 < 0 {
		return 0
	}
	if v16 > v15 {
		return 0
	}
	return 1
}
