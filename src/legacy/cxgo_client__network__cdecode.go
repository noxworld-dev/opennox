package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nox_client_fadeObjects_80836 uint32 = 1

func nox_xxx_netOnPacketRecvCli_48EA70_switch(a1 int32, op int32, data *uint8, sz int32) int32 {
	var (
		old *uint8 = data
		v5  int64
		k   int32
		v15 *uint8
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v24 int32
		v25 int32
		v26 int32
		v27 *uint32
		v28 uint8
		v29 int32
		v30 uint8
		v31 uint32
		v32 int32
		v33 int32
	)
	_ = v33
	var v34 uint32
	var v35 *byte
	var j *byte
	var v37 *byte
	var v38 *wchar2_t
	var v39 *byte
	var v40 uint32
	var v41 *wchar2_t
	var v42 int32
	_ = v42
	var v43 *byte
	_ = v43
	var v44 int32
	var v45 int32
	var v46 int32
	var v47 int32
	var v48 uint32
	var v49 int32
	var v50 int32
	var v51 int32
	var v52 int32
	var v53 uint32
	var v54 int32
	var v55 int32
	var v56 int32
	var v57 int32
	var v58 int32
	var v59 int32
	var v60 int32
	var v62 int32
	var v63 int32
	var v64 int32
	var v65 int32
	var v66 int8
	var v67 int32
	var v68 int32
	var v69 int32
	var v70 int32
	var v71 int32
	var v72 int32
	var v73 *uint32
	var v74 int32
	var v75 int32
	var v76 uint32
	var v77 int32
	var v78 int32
	var v79 int32
	var v80 int32
	var v81 *int32
	var v82 int32
	var v83 int32
	var v84 int32
	var v85 int32
	var v86 int32
	var v87 int8
	var v88 int32
	var v89 int32
	var v90 int32
	var v91 int32
	var v92 int32
	var v93 int32
	var v94 int32
	var v95 int32
	var v96 int32
	var v97 int32
	var v98 int32
	var v99 int32
	var v100 int32
	var v101 int32
	var v102 int32
	var v103 int32
	var v104 int32
	var v105 int32
	var v106 int32
	var v107 int32
	var v108 *byte
	var v109 int32
	var v110 int32
	var v111 *uint32
	var v112 *uint32
	var v113 int32
	var v114 *uint32
	var v115 int32
	var v116 int32
	var v117 uint32
	var v118 uint16
	var v119 *byte
	var v120 int32
	var v121 int32
	var v122 int32
	var v123 int32
	var v124 int32
	var v125 int32
	var v126 *byte
	var v127 *byte
	var v128 *wchar2_t
	var v129 uint32
	var v130 int32
	var v132 int32
	var v133 int32
	var v134 int32
	var v135 int32
	var v137 int32
	var v138 int32
	var v139 int32
	var v140 int32
	var v141 int32
	var v142 *byte
	var v143 *wchar2_t
	var v144 *byte
	var v145 *uint32
	var v146 *wchar2_t
	var v147 int32
	var v148 *wchar2_t
	var v149 *wchar2_t
	var v150 int32
	var v151 *wchar2_t
	var v152 int32
	var v153 int32
	var v154 *byte
	var v155 *wchar2_t
	var v156 *wchar2_t
	var v157 *wchar2_t
	var v158 *wchar2_t
	var v159 *wchar2_t
	var v160 *byte
	var v161 *wchar2_t
	var v162 *uint32
	var v163 *wchar2_t
	var v164 int32
	var v165 *wchar2_t
	var v166 *wchar2_t
	var v167 *wchar2_t
	var v168 *wchar2_t
	var v169 *wchar2_t
	var v170 *wchar2_t
	var v171 *wchar2_t
	var v172 *byte
	var v173 *wchar2_t
	var v174 *uint32
	var v175 *wchar2_t
	var v176 int32
	var v177 *wchar2_t
	var v178 int32
	var v179 int32
	var v180 int32
	var v181 int32
	var v182 int32
	var v183 int32
	var v184 uint32
	var v185 uint32
	var v186 uint16
	var v187 uint16
	var v188 *uint32
	var v189 int32
	var v190 int32
	var v191 uint16
	var v192 uint16
	var v193 uint32
	var v194 uint32
	var v195 *uint32
	var v196 int32
	var v197 int32
	var v198 int32
	var v199 int32
	var v200 int32
	var v201 *wchar2_t
	var v202 int32
	var v203 *wchar2_t
	var v204 *wchar2_t
	var v205 *wchar2_t
	var v206 *byte
	var v207 *byte
	var v208 int32
	var v213 *wchar2_t
	_ = v213
	var v214 int32
	_ = v214
	var v215 int32
	_ = v215
	var v216 *byte
	_ = v216
	var v217 *wchar2_t
	_ = v217
	var v218 *uint32
	_ = v218
	var v219 int32
	_ = v219
	var v220 *wchar2_t
	_ = v220
	var v221 uint32
	var v222 int32
	var v223 int32
	var v224 int32
	var v225 int32
	var v226 int32
	var v227 int32
	var v228 int32
	var v229 int32
	var v230 int32
	var v231 int32
	var v232 *uint32
	var v233 int8
	var v234 int32
	var v235 int32
	var v236 int32
	_ = v236
	var v237 int32
	_ = v237
	var v239 int32
	var v240 int32
	var v241 int32
	_ = v241
	var v242 int32
	_ = v242
	var v243 int32
	_ = v243
	var v244 int32
	_ = v244
	var v245 int32
	_ = v245
	var v246 *uint32
	_ = v246
	var v247 int8
	_ = v247
	var v248 int16
	_ = v248
	var v249 int32
	_ = v249
	var v250 bool
	var v251 int32
	var v252 uint32
	var v253 int32
	var v254 int32
	var v255 int32
	var v256 int32
	var v257 int32
	var v258 int32
	var v259 int32
	var v260 int32
	var v261 int32
	var v262 int32
	var v263 int32
	_ = v263
	var v264 int32
	_ = v264
	var v265 int32
	_ = v265
	var v266 int32
	_ = v266
	var v267 int32
	_ = v267
	var v268 int32
	_ = v268
	var v269 int32
	_ = v269
	var v270 int32
	_ = v270
	var v271 *wchar2_t
	var v272 *byte
	var v273 *uint32
	var v274 uint32
	var v275 uint32
	var v276 int32
	var v277 int32
	var v278 *uint32
	var v279 int32
	var v280 *wchar2_t
	var v281 uint32
	var v282 uint32
	var v283 int32
	var v284 int32
	var v285 uint16
	var v286 uint16
	var v287 int32
	var v288 *byte
	var v289 *uint8
	var v290 *wchar2_t
	var v291 int32
	var v292 int32
	var v293 int32
	var v294 int32
	var v295 int32
	var v296 int32
	var v297 int32
	var v298 int32
	var v299 *byte
	var v300 *byte
	var v301 int32
	var v302 *uint32
	var v303 *byte
	var v304 *wchar2_t
	var v305 *wchar2_t
	var v306 *byte
	var v307 *wchar2_t
	var v308 *wchar2_t
	var v309 *byte
	var v310 *wchar2_t
	var v311 *wchar2_t
	var v312 *wchar2_t
	var v314 *wchar2_t
	var v315 int8
	_ = v315
	var v316 uint8
	_ = v316
	var v317 int32
	var v318 int32
	var v319 uint16
	_ = v319
	var v320 int32
	var v321 int32
	var v322 int32
	var v323 int8
	var v324 uint32
	_ = v324
	var v325 int8
	_ = v325
	var v326 int8
	_ = v326
	var v327 int32
	_ = v327
	var v328 float32
	var v329 int32
	var v330 int32
	var v331 int32
	var v332 float32
	var v334 *wchar2_t
	var v335 *wchar2_t
	var v336 *wchar2_t
	var v337 int32
	var v338 int32
	var v339 int32
	var v340 float32
	var v341 int32
	var v342 int8
	_ = v342
	var v343 *byte
	_ = v343
	var v344 uint32
	_ = v344
	var v345 int32
	_ = v345
	var v346 int8
	_ = v346
	var v347 int8
	_ = v347
	var v348 int32
	var v349 int32
	var v350 int32
	var v351 int32
	var v352 int32
	var v353 int32
	var v354 *wchar2_t
	var v355 int32
	var v356 uint32
	_ = v356
	var v357 int32
	var v358 *int32
	var v359 int8
	var v360 int32
	var i int32
	var v362 int32
	var v363 int32
	var v365 [6]byte
	_ = v365
	var v367 int32
	var v368 int32
	var v370 int32
	var v371 int32
	_ = v371
	var v372 int32 = 0
	var v374 int32
	_ = v374
	var v376 int32
	var v377 Point32
	var v378 Point32
	var v379 Point32
	var v380 Point32
	var v381 [20]uint8
	var v382 [8]int32
	_ = v382
	var v383 [5]int32
	var v384 [2]int32
	var v385 [20]byte
	var v386 [20]wchar2_t
	var v387 [20]wchar2_t
	var v388 [64]wchar2_t
	var v389 [128]wchar2_t
	var v390 [128]wchar2_t
	var v391 [128]wchar2_t
	var v392 [128]wchar2_t
	var v393 [128]wchar2_t
	var v394 [128]wchar2_t
	var v395 [64]wchar2_t
	var v396 [64]wchar2_t
	var v397 [100]wchar2_t
	_ = v397
	var v398 [128]wchar2_t
	var v400 [256]wchar2_t
	var v401 [128]wchar2_t
	var v402 [128]wchar2_t
	var v403 [256]wchar2_t
	var v404 [256]wchar2_t
	var v405 [256]wchar2_t
	var v406 [256]wchar2_t
	var end *uint8 = (*uint8)(unsafe.Add(unsafe.Pointer(data), sz))
	switch op {
	case 47:
		nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)))))))
			if uint32(int32(v5)) != 0 {
				k = int32(gameFrame())
				*(*uint32)(unsafe.Add(v5, 288)) = gameFrame()
			}
		}
		return 9
	case 48:
		nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_client_isConnected_43C700() == 0 {
			return 11
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))) != 0 || int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)))))))
			v29 = int32(v5)
			if uint32(int32(v5)) != 0 {
				*(*uint32)(unsafe.Add(v5, 288)) = gameFrame()
				nox_xxx_spriteSetFrameMB_45AB80(int32(v5), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 10)))))
				*((*uint8)(unsafe.Pointer(&v5))) = uint8(int8((int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 9)))) >> 4) & 7))
				*(*uint8)(unsafe.Add(v29, 297)) = uint8(int8(v5))
				if int32(uint8(int8(v5))) > 3 {
					*(*uint8)(unsafe.Add(v29, 297)) = uint8(int8(v5 + 1))
				}
				v30 = uint8(int8(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 9)))) & 0xF))
				*((*uint8)(unsafe.Add(unsafe.Pointer(data), 9))) = v30
				if *(*uint32)(unsafe.Add(v29, 276)) != uint32(v30) {
					*(*uint32)(unsafe.Add(v29, 316)) = gameFrame()
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 9))))
					*(*uint32)(unsafe.Add(v29, 276)) = *(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))
				}
			}
			k = int32(nox_player_netCode_85319C)
			if uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) == nox_player_netCode_85319C && sub_416120(9) {
				nox_xxx_cliUpdateCameraPos_435600(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))))
			}
		} else {
			nox_xxx_cliUpdateCameraPos_435600(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))))
			nox_xxx_setKeybTimeout_4160D0(9)
		}
		return 11
	case 49:
		v44 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v45 = v44
		if nox_client_isConnected_43C700() == 0 {
			return 3
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v45))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v45))
		}())))
		v46 = int32(v5)
		if uint32(int32(v5)) == 0 {
			return 3
		}
		if *(*unsafe.Pointer)(unsafe.Add(v5, 300)) == ccall.FuncAddr(nox_thing_animate_draw) {
			v47 = int32(*(*uint32)(unsafe.Add(v5, 304)))
			if v47 != 0 {
				if *(*uint32)(unsafe.Add(v47, 12)) == 1 {
					return 3
				}
			}
		}
		v48 = nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v331 = v46
		if v48 == 0 {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(v331))
			return 3
		}
		nox_xxx_cliDestroyObj_45A9A0(v46)
		return 3
	case 50:
		v49 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v50 = v49
		if nox_client_isConnected_43C700() == 0 {
			return 3
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v50))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v50))
		}())))
		v51 = int32(v5)
		if uint32(int32(v5)) == 0 {
			return 3
		}
		if *(*unsafe.Pointer)(unsafe.Add(v5, 300)) == ccall.FuncAddr(nox_thing_animate_draw) {
			v52 = int32(*(*uint32)(unsafe.Add(v5, 304)))
			if v52 != 0 {
				if *(*uint32)(unsafe.Add(v52, 12)) == 1 {
					return 3
				}
			}
		}
		if uint32(v51) == *memmap.PtrUint32(0x852978, 8) {
			return 3
		}
		v53 = nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v331 = v51
		if v53 != 0 {
			nox_xxx_cliDestroyObj_45A9A0(v51)
		} else {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(v331))
		}
		return 3
	case 51:
		v54 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v55 = v54
		if nox_client_isConnected_43C700() == 0 {
			return 3
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v55))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v55))
		}())))
		v51 = int32(v5)
		if uint32(int32(v5)) == 0 {
			return 3
		}
		k = 1
		*(*uint32)(unsafe.Add(v5, 484)) = 1
		*(*uint32)(unsafe.Add(v5, 480)) = 1
		*(*uint32)(unsafe.Add(v5, 488)) = 1
		if nox_client_fadeObjects_80836 != 0 {
			if uint32(int32(v5)) != *memmap.PtrUint32(0x852978, 8) {
				nox_xxx_spriteTransparentDecay_49B950((*client.Drawable)(v5), int32(gameFPS()))
			}
		} else if *(*unsafe.Pointer)(unsafe.Add(v5, 300)) != ccall.FuncAddr(nox_thing_animate_draw) || (func() int32 {
			v56 = int32(*(*uint32)(unsafe.Add(v5, 304)))
			return v56
		}()) == 0 || *(*uint32)(unsafe.Add(v56, 12)) != 1 {
			if uint32(v51) != *memmap.PtrUint32(0x852978, 8) {
				v53 = nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
				v331 = v51
				if v53 != 0 {
					nox_xxx_cliDestroyObj_45A9A0(v51)
				} else {
					nox_xxx_spriteDeleteStatic_45A4E0_drawable((*client.Drawable)(v331))
				}
				return 3
			}
		}
		return 3
	case 52:
		v57 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v58 = v57
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx_cliAddObjFriend_4959F0(v58)
		}
		return 3
	case 53:
		v59 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v60 = v59
		if nox_client_isConnected_43C700() != 0 {
			sub_495A20(v60)
		}
		return 3
	case 54:
		if nox_client_isConnected_43C700() != 0 {
			sub_4959B0()
		}
		return 1
	case 55:
		v62 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v63 = v62
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v63)))))
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v63)))))
			}
			if uint32(int32(v5)) != 0 {
				*(*uint32)(unsafe.Add(v5, 120)) |= 0x1000000
			}
		}
		return 3
	case 56:
		v64 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v65 = v64
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v65)))))
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v65)))))
			}
			if uint32(int32(v5)) != 0 {
				if *(*uint32)(unsafe.Add(v5, 112))&0x40000 != 0 {
					*(*uint32)(unsafe.Add(v5, 300)) = 0
				}
				*(*uint32)(unsafe.Add(v5, 120)) &= 0xFEFFFFFF
			}
		}
		return 3
	case 57:
		v16 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v17 = v16
		if nox_client_isConnected_43C700() == 0 {
			return 4
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v17))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v17))
		}())))
		if uint32(int32(v5)) == 0 {
			return 4
		}
		nox_xxx_spriteSetFrameMB_45AB80(int32(v5), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))))
		return 4
	case 58:
		if nox_client_isConnected_43C700() != 0 && !noxflags.HasGame(1) {
			nox_xxx_wallDestroyedByWallid_410520(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		return 3
	case 59:
		if nox_client_isConnected_43C700() != 0 {
			if !noxflags.HasGame(1) {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(sub_410550(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
				if uint32(int32(v5)) != 0 {
					if int32(*(*uint8)(unsafe.Add(v5, 4)))&4 != 0 {
						v67 = int32(*(*uint32)(unsafe.Add(v5, 28)))
						*(*uint8)(unsafe.Add(v67, 22)) = 23
						*(*uint8)(unsafe.Add(v67, 21)) = 3
					}
				}
			}
		}
		return 3
	case 60:
		if nox_client_isConnected_43C700() != 0 {
			if !noxflags.HasGame(1) {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(sub_410550(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
				if uint32(int32(v5)) != 0 {
					if int32(*(*uint8)(unsafe.Add(v5, 4)))&4 != 0 {
						v68 = int32(*(*uint32)(unsafe.Add(v5, 28)))
						if v68 != 0 {
							*(*uint8)(unsafe.Add(v68, 22)) = 0
							*(*uint8)(unsafe.Add(v68, 21)) = 1
						}
					}
				}
			}
		}
		return 3
	case 61:
		if nox_client_isConnected_43C700() == 0 {
			return 6
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(nox_server_getWallAtGrid_410580(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 4)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5)))))))
		if uint32(int32(v5)) == 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(nox_xxx_wallCreateAt_410250(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 4)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5)))))))
			if uint32(int32(v5)) == 0 {
				return 6
			}
		}
		v66 = int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))
		data = (*uint8)(unsafe.Add(unsafe.Pointer(data), 6))
		*(*uint8)(unsafe.Add(v5, 1)) = uint8(v66)
		*(*uint8)(v5) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), -4)))
		*(*uint8)(unsafe.Add(v5, 2)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), -3)))
		return 6
	case 62:
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(nox_server_getWallAtGrid_410580(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))))
			if uint32(int32(v5)) != 0 {
				nox_xxx_mapDelWallAtPt_410430(int32(*(*uint8)(unsafe.Add(v5, 5))), int32(*(*uint8)(unsafe.Add(v5, 6))))
			}
		}
		return 3
	case 65:
		nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_client_isConnected_43C700() == 0 {
			return 4
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if nox_xxx_unitSpriteCheckAlly_4951F0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) == 0 {
			return 4
		}
		sub_495150(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int16(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))*2))
		return 4
	case 66:
		nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_client_isConnected_43C700() != 0 && nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		nox_xxx_cliAddHealthChange_49A650(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))
		return 5
	case 67:
		if nox_client_isConnected_43C700() != 0 {
			sub_470CB0(int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		return 3
	case 68:
		v92 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v93 = v92
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		sub_4675E0(v93, int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))))
		return 7
	case 69:
		v96 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v97 = v96
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if uint32(v97) != nox_player_netCode_85319C {
			return 5
		}
		nox_xxx_cliSetMana_470D10(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))
		return 5
	case 71:
		if nox_client_isConnected_43C700() == 0 {
			return 2
		}
		sub_470D20(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), *memmap.PtrInt32(0x587000, 157092))
		return 2
	case 72:
		v98 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v99 = int32(*memmap.PtrUint32(0x8531A0, 2576))
		v100 = v98
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			if uint32(v100) == nox_player_netCode_85319C {
				v101 = bool2int32(noxflags.HasGame(1))
				if v101 == 0 && v99 != 0 {
					*(*uint32)(unsafe.Add(v99, 2247)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))
					*(*uint32)(unsafe.Add(v99, 2243)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5)))
					*(*uint16)(unsafe.Add(unsafe.Pointer(&v101), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 9))
					v332 = float32(float64(v101))
					*(*uint32)(unsafe.Add(v99, 2235)) = uint32(int32(v332))
					*(*uint32)(unsafe.Add(v99, 2239)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 11)))
					*(*uint16)(unsafe.Add(v99, 3652)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))
					*(*uint8)(unsafe.Add(v99, 3684)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 13)))
				}
				nox_xxx_j_inventoryNameSignInit_467460()
			}
		}
		return 14
	case 73:
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		sub_467450(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 1))))
		return 5
	case 74:
		v102 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 1)))
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		sub_467490(v102)
		return 5
	case 75:
		v103 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v104 = v103
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Pointer(&v381[0])) = 0
		*(*uint16)(unsafe.Pointer(&v381[16])) = math.MaxUint16
		*(*uint32)(unsafe.Pointer(&v381[4])) = 0
		*(*uint16)(unsafe.Pointer(&v381[18])) = math.MaxUint16
		*(*uint32)(unsafe.Pointer(&v381[8])) = 0
		*(*uint32)(unsafe.Pointer(&v381[12])) = 0
		if nox_xxx_spritePickup_461660(v104, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), unsafe.Pointer(&v381[0])) != 0 {
			return 5
		}
		nox_xxx_send2ServInvenFail_461630(int16(v104))
		return 5
	case 76:
		v105 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v106 = v105
		if nox_client_isConnected_43C700() == 0 {
			return 9
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		v107 = 0
		v108 = &v385[0]
		for {
			*(*uint32)(unsafe.Pointer(v108)) = uint32(uintptr(nox_xxx_modifGetDescById_413330(int32(*((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(data), func() int32 {
				p := &v107
				x := *p
				*p++
				return x
			}()), 5)))))))
			v108 = (*byte)(unsafe.Add(unsafe.Pointer(v108), 4))
			if v107 >= 4 {
				break
			}
		}
		*(*uint16)(unsafe.Pointer(&v385[16])) = math.MaxUint16
		*(*uint16)(unsafe.Pointer(&v385[18])) = math.MaxUint16
		if nox_xxx_spritePickup_461660(v106, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), unsafe.Pointer(&v385[0])) != 0 {
			return 9
		}
		nox_xxx_send2ServInvenFail_461630(int16(v106))
		return 9
	case 77:
		v109 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v110 = v109
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		sub_461A80(v110)
		return 5
	case 78:
		v124 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v125 = v124
		v126 = nox_xxx_cliGamedataGet_416590(0)
		if nox_client_isConnected_43C700() != 0 {
			v127 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(v125)))
			if v127 != nil {
				if !noxflags.HasGame(1) {
					*((*uint32)(unsafe.Add(unsafe.Pointer(v127), 4*534))) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v127), 4*535))) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 7))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v127), 4*536))) = gameFrame()
				}
				if noxflags.HasGame(1024) {
					k = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 7)))
					if k >= int32(*((*uint16)(unsafe.Add(unsafe.Pointer(v126), unsafe.Sizeof(uint16(0))*27)))) {
						v128 = nox_strman_loadString_40F1D0(internCStr("Eliminated"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3452)
						nox_swprintf(&v395[0], v128, (*byte)(unsafe.Add(unsafe.Pointer(v127), 4704)))
						nox_xxx_clientPlaySoundSpecial_452D80(312, 100)
						nox_xxx_printCentered_445490(&v395[0])
					}
				}
			}
		}
		return 11
	case 79, 80:
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))
		v367 = -1
		*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)) = uint16(int16(v5 & math.MaxInt16))
		if ((uint32(int32(v5)) >> 15) & 1) == 1 {
			nox_xxx_clientEquipWeaponArmor_417AA0(int8(*data), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))), unsafe.Pointer(&v367))
		} else {
			nox_xxx_clientEquip_49A3D0(int8(*data), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))), unsafe.Pointer(&v367))
		}
		return 7
	case 81, 82:
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(nox_client_isConnected_43C700())
		if uint32(int32(v5)) == 0 {
			return 11
		}
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))
		v116 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3)))
		v117 = uint32(int32(v5))
		v118 = uint16(int16(v5 & math.MaxInt16))
		*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)) = v118
		v333 := unsafe.Add(unsafe.Pointer(data), 7)
		if ((v117 >> 15) & 1) == 1 {
			nox_xxx_clientEquipWeaponArmor_417AA0(int8(*data), int32(v118), v116, v333)
		} else {
			nox_xxx_clientEquip_49A3D0(int8(*data), int32(v118), v116, v333)
		}
		return 11
	case 83, 84:
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		sub_417B80(int8(*data), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))))
		return 7
	case 85:
		v140 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v141 = v140
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			v142 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(v141)))
			if v142 != nil {
				if !noxflags.HasGame(1) && gameFrame() > *((*uint32)(unsafe.Add(unsafe.Pointer(v142), 4*540))) {
					*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*1)) = 0
					*((*uint32)(unsafe.Add(unsafe.Pointer(v142), 4*538))) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))
					*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v142), 4*539))) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2)))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v142), 4*540))) = gameFrame()
				}
				k = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v142), 4*539))) - 1)
				if *((*uint32)(unsafe.Add(unsafe.Pointer(v142), 4*538))) == uint32(k) {
					v143 = nox_strman_loadString_40F1D0(internCStr("SH_NearVictory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3729)
					nox_swprintf(&v406[0], v143, (*byte)(unsafe.Add(unsafe.Pointer(v142), 4704)))
					nox_xxx_printCentered_445490(&v406[0])
				}
			}
		}
		return 7
	case 86:
		v144 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_client_isConnected_43C700() == 0 {
			return 8
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 4))
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))) <= dword_5d4594_1200804 {
			return 8
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		nox_xxx_clientPlaySoundSpecial_452D80(309, 100)
		if !noxflags.HasGame(1) {
			nox_xxx_setGameFlags_40A4D0(8)
		}
		nox_xxx_initTime_435570()
		if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			sub_470510()
		}
		v145 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
		if v145 != nil && nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Pointer(v145)), *((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
			v146 = nox_strman_loadString_40F1D0(internCStr("TeamWon"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3776)
			nox_swprintf(&v400[0], v146)
			v147 = 0
		} else {
			v148 = nox_strman_loadString_40F1D0(internCStr("teamformat"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3781)
			nox_swprintf(&v400[0], v148, v144)
			v149 = nox_strman_loadString_40F1D0(internCStr("FB_Victory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3782)
			nox_swprintf(&v400[0], v149, &v400[0])
			v147 = 1
		}
		sub_435700(&v400[0], v147)
		nox_xxx_guiServerOptionsHide_4597E0(0)
		return 8
	case 87:
		v172 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_client_isConnected_43C700() == 0 {
			return 8
		}
		k = int32(dword_5d4594_1200804)
		if *(*uint32)(unsafe.Add(unsafe.Pointer(data), 4)) <= dword_5d4594_1200804 {
			return 8
		}
		v393[0] = 0
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) == 1 {
			v173 = nox_strman_loadString_40F1D0(internCStr("TimeLimitReached"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4055)
			nox_swprintf(&v393[0], v173)
		}
		nox_xxx_clientPlaySoundSpecial_452D80(309, 100)
		if !noxflags.HasGame(1) {
			nox_xxx_setGameFlags_40A4D0(8)
		}
		nox_xxx_initTime_435570()
		if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			sub_470510()
		}
		v174 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
		if v172 != nil {
			v175 = nox_strman_loadString_40F1D0(internCStr("CTF_Victory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4071)
			nox_swprintf(&v398[0], v175, v172)
			if v174 == nil || nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Pointer(v174)), *(*byte)(unsafe.Add(unsafe.Pointer(v172), 57))) == 0 {
				v176 = 1
				goto LABEL_600
			}
		} else {
			v177 = nox_strman_loadString_40F1D0(internCStr("CTF_Tie"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4083)
			nox_swprintf(&v398[0], v177)
		}
		v176 = 0
	LABEL_600:
		nox_wcscat(&v393[0], &v398[0])
		sub_435700(&v393[0], v176)
		nox_xxx_guiServerOptionsHide_4597E0(0)
		return 8
	case 88:
		v150 = 1
		v389[0] = 0
		v392[0] = 0
		v391[0] = 0
		if nox_client_isConnected_43C700() == 0 {
			return 8
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 4))
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))) <= dword_5d4594_1200804 {
			return 8
		}
		v391[0] = 0
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) == 1 {
			v151 = nox_strman_loadString_40F1D0(internCStr("TimeLimitReached"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3823)
			nox_swprintf(&v391[0], v151)
		}
		nox_xxx_clientPlaySoundSpecial_452D80(309, 100)
		if !noxflags.HasGame(1) {
			nox_xxx_setGameFlags_40A4D0(8)
		}
		if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			sub_470510()
		}
		nox_xxx_initTime_435570()
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
			v152 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			v372 = v152
		}
		v153 = v372
		v154 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(v372)))
		if !noxflags.HasGame(1024) {
			if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
				if v154 == nil {
					goto LABEL_559
				}
				if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) == 0 {
					sub_4947E0(int32(uintptr(unsafe.Pointer(v154))))
				}
				if uint32(v153) != nox_player_netCode_85319C {
					v159 = nox_strman_loadString_40F1D0(internCStr("DM_Loss"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3899)
					nox_swprintf(&v389[0], v159, (*byte)(unsafe.Add(unsafe.Pointer(v154), 4704)))
					v150 = 1
					goto LABEL_559
				}
				if *(*byte)(unsafe.Add(unsafe.Pointer(v154), 2252)) == 0 {
					v314 = nox_strman_loadString_40F1D0(internCStr("DM_MaleVictory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3905)
					nox_swprintf(&v389[0], v314)
					v150 = 0
					nox_wcscat(&v391[0], &v389[0])
					sub_435700(&v391[0], v150)
					nox_xxx_guiServerOptionsHide_4597E0(0)
					return 8
				}
				v155 = nox_strman_loadString_40F1D0(internCStr("DM_FemaleVictory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3907)
			} else {
				v155 = nox_strman_loadString_40F1D0(internCStr("DM_Tie"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3884)
			}
			nox_swprintf(&v389[0], v155)
			v150 = 0
			nox_wcscat(&v391[0], &v389[0])
			sub_435700(&v391[0], v150)
			nox_xxx_guiServerOptionsHide_4597E0(0)
			return 8
		}
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) == 0 {
			v155 = nox_strman_loadString_40F1D0(internCStr("HL_Tie"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3847)
			nox_swprintf(&v389[0], v155)
			v150 = 0
			nox_wcscat(&v391[0], &v389[0])
			sub_435700(&v391[0], v150)
			nox_xxx_guiServerOptionsHide_4597E0(0)
			return 8
		}
		v156 = nox_strman_loadString_40F1D0(internCStr("HL_Header"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3852)
		nox_swprintf(&v389[0], v156)
		if uint32(v153) == nox_player_netCode_85319C {
			v334 = nox_strman_loadString_40F1D0(internCStr("HL_You"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3855)
			v157 = nox_strman_loadString_40F1D0(internCStr("HL_Victory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3855)
			nox_swprintf(&v392[0], v157, v334)
			nox_wcscat(&v389[0], &v392[0])
			v150 = 0
		} else {
			if v154 != nil {
				v158 = nox_strman_loadString_40F1D0(internCStr("HL_Victory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3863)
				nox_swprintf(&v392[0], v158, (*byte)(unsafe.Add(unsafe.Pointer(v154), 4704)))
				if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) == 0 {
					sub_4947E0(int32(uintptr(unsafe.Pointer(v154))))
				}
			}
			nox_wcscat(&v389[0], &v392[0])
			v150 = 1
		}
	LABEL_559:
		nox_wcscat(&v391[0], &v389[0])
		sub_435700(&v391[0], v150)
		nox_xxx_guiServerOptionsHide_4597E0(0)
		return 8
	case 89:
		v160 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if nox_client_isConnected_43C700() == 0 {
			return 8
		}
		k = int32(dword_5d4594_1200804)
		if *(*uint32)(unsafe.Add(unsafe.Pointer(data), 4)) <= dword_5d4594_1200804 {
			return 8
		}
		v394[0] = 0
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) == 1 {
			v161 = nox_strman_loadString_40F1D0(internCStr("TimeLimitReached"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3945)
			nox_swprintf(&v394[0], v161)
		}
		nox_xxx_clientPlaySoundSpecial_452D80(309, 100)
		if !noxflags.HasGame(1) {
			nox_xxx_setGameFlags_40A4D0(8)
		}
		nox_xxx_initTime_435570()
		if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
			sub_470510()
		}
		v162 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
		if noxflags.HasGame(1024) {
			if v160 == nil {
				v163 = nox_strman_loadString_40F1D0(internCStr("HL_Tie"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3964)
				nox_swprintf(&v390[0], v163)
				v164 = 0
				goto LABEL_585
			}
			v165 = nox_strman_loadString_40F1D0(internCStr("HL_Header"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3969)
			nox_swprintf(&v390[0], v165)
			if v162 != nil && nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Pointer(v162)), *(*byte)(unsafe.Add(unsafe.Pointer(v160), 57))) != 0 {
				v335 = nox_strman_loadString_40F1D0(internCStr("HL_YourTeam"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3973)
				v166 = nox_strman_loadString_40F1D0(internCStr("HL_Victory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3973)
				nox_swprintf(&v388[0], v166, v335)
				nox_wcscat(&v390[0], &v388[0])
				v164 = 0
			} else {
				v336 = nox_strman_loadString_40F1D0(internCStr("Team"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3980)
				v167 = nox_strman_loadString_40F1D0(internCStr("HL_Victory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3980)
				nox_swprintf(&v388[0], v167, v336)
				nox_swprintf(&v396[0], &v388[0], v160)
				nox_wcscat(&v390[0], &v396[0])
				v164 = 1
			}
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) == 0 {
				sub_4948B0(int32(uintptr(unsafe.Pointer(v160))))
				goto LABEL_585
			}
		} else {
			if v160 == nil {
				v168 = nox_strman_loadString_40F1D0(internCStr("DM_Tie"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 3999)
				nox_swprintf(&v390[0], v168)
				v164 = 0
				goto LABEL_585
			}
			if v162 != nil && nox_xxx_teamCompare2_419180((*server.ObjectTeam)(unsafe.Pointer(v162)), *(*byte)(unsafe.Add(unsafe.Pointer(v160), 57))) != 0 {
				v169 = nox_strman_loadString_40F1D0(internCStr("DM_TeamVictory"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4006)
				nox_swprintf(&v390[0], v169)
				v164 = 0
			} else {
				v170 = nox_strman_loadString_40F1D0(internCStr("Team"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4011)
				nox_swprintf(&v388[0], v170, v160)
				v171 = nox_strman_loadString_40F1D0(internCStr("DM_Loss"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4012)
				nox_swprintf(&v390[0], v171, &v388[0])
				v164 = 1
			}
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) == 0 {
				sub_4948B0(int32(uintptr(unsafe.Pointer(v160))))
				goto LABEL_585
			}
		}
	LABEL_585:
		nox_wcscat(&v394[0], &v390[0])
		sub_435700(&v394[0], v164)
		nox_xxx_guiServerOptionsHide_4597E0(0)
		return 8
	case 90:
		v132 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v133 = v132
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v133))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v133))
		}())))
		v134 = int32(v5)
		if uint32(int32(v5)) == 0 {
			return 7
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(bool2int32(nox_client_drawable_testBuff_4356C0((*client.Drawable)(v5), 15)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))
		v135 = int32(v5)
		*(*uint32)(unsafe.Add(v134, 124)) = *(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))
		if uint32(v134) == *memmap.PtrUint32(0x852978, 8) {
			sub_467410(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))))
		}
		if v135 != 1 || nox_client_drawable_testBuff_4356C0((*client.Drawable)(v134), 15) || uint32(v134) == *memmap.PtrUint32(0x852978, 8) && int32(sub_467430())&8 != 0 {
			return 7
		}
		var v136 *client.ObjectType = nox_get_thing(int32(*(*uint32)(unsafe.Add(v134, 108))))
		nox_xxx_spriteChangeIntensity_484D70_light_intensity(v134+136, v136.LightIntensity)
		return 7
	case 91:
		if nox_client_isConnected_43C700() != 0 {
			*((*uint8)(unsafe.Pointer(&v129))) = sub_467430()
			v130 = int32((v129 >> 3) & 1)
			sub_467420(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))))
			if v130 == 1 && (int32(sub_467430())&8) == 0 && *memmap.PtrUint32(0x852978, 8) != 0 && !nox_client_drawable_testBuff_4356C0((*client.Drawable)(*memmap.PtrPtr(0x852978, 8)), 15) {
				var v131 *client.ObjectType = nox_get_thing(int32(*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 108))))
				nox_xxx_spriteChangeIntensity_484D70_light_intensity(int32(*memmap.PtrUint32(0x852978, 8)+136), v131.LightIntensity)
			}
		}
		return 2
	case 92:
		v88 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v89 = v88
		if nox_client_isConnected_43C700() == 0 {
			return 6
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v89))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v89))
		}())))
		if uint32(int32(v5)) != 0 {
			nox_xxx_spriteChangeLightColor_484BE0((*uint32)(unsafe.Add(v5, 136)), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 4)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5)))))
		}
		return 6
	case 93:
		v84 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v85 = v84
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v85))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v85))
		}())))
		if uint32(int32(v5)) == 0 {
			return 7
		}
		nox_xxx_spriteChangeIntensity_484D70_light_intensity(int32(v5+136), *(*float32)(unsafe.Add(unsafe.Pointer(data), 3)))
		return 7
	case 94:
		v178 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v179 = v178
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
				if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
					return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v179))
				}
				return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v179))
			}())))
			if uint32(int32(v5)) != 0 {
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2)) = uint16(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
				*(*uint16)(unsafe.Add(v5, 104)) = *(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2))
			}
		}
		return 4
	case 95:
		v180 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v181 = v180
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
				if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
					return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v181))
				}
				return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v181))
			}())))
			if uint32(int32(v5)) != 0 {
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2)) = uint16(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = -(*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)))
				*(*uint16)(unsafe.Add(v5, 104)) = *(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2))
			}
		}
		return 4
	case 96:
		v120 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v121 = v120
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			sub_462040(v121)
		}
		return 3
	case 97:
		v122 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v123 = v122
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			sub_4624D0(v123)
		}
		return 3
	case 100:
		v182 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v183 = v182
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		sub_467930(v183, int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 4)))))
		return 5
	case 101:
		v71 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v72 = v71
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v72)))))
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v72)))))
			}
			v73 = (*uint32)(v5)
			if uint32(int32(v5)) != 0 {
				v74 = int32(*(*uint32)(unsafe.Add(v5, 280)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*70)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))
				k = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*28)))
				if uint32(k)&0x20000 != 0 {
					if (v74 & 0x400) == 0 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*70)) & 0x400
						if (*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))) == 1024 {
							sub_4BC720(unsafe.Pointer(v73))
						}
					}
					v75 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*70)))
					if v75&0x800 != 0 {
						k = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*28)) & 0xFFF7FFFF)
						v76 = *(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*30)) & 0xDFFFFFFF
						*(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*28)) = uint32(k)
						*(*uint32)(unsafe.Add(unsafe.Pointer(v73), 4*30)) = v76
					}
				}
			}
		}
		return 7
	case 102:
		if nox_client_isConnected_43C700() != 0 && *memmap.PtrUint32(0x852978, 8) != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 1))
			*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 120)) = *(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))
		}
		return 5
	case 103:
		v77 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v78 = v77
		if nox_client_isConnected_43C700() != 0 {
			if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
				nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v78)))))
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v78)))))
			}
			if uint32(int32(v5)) != 0 {
				v79 = int32(v5 + 432)
				if uint32(int32(v5)) != 4294966864 {
					v80 = 0
					v81 = (*int32)(unsafe.Add(v5, 432))
					for {
						*v81 = int32(uintptr(nox_xxx_modifGetDescById_413330(int32(*((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(data), func() int32 {
							p := &v80
							x := *p
							*p++
							return x
						}()), 3)))))))
						v81 = (*int32)(unsafe.Add(unsafe.Pointer(v81), 4*1))
						if v80 >= 4 {
							break
						}
					}
					*(*uint16)(unsafe.Add(v79, 16)) = math.MaxUint16
					*(*uint16)(unsafe.Add(v79, 18)) = math.MaxUint16
				}
			}
		}
		return 7
	case 104:
		v82 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v83 = v82
		if nox_client_isConnected_43C700() == 0 {
			return 8
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if uint32(v83) == nox_player_netCode_85319C {
			*((*uint8)(unsafe.Pointer(&k))) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 7)))
			sub_467470(k, *(*float32)(unsafe.Add(unsafe.Pointer(data), 3)))
		}
		return 8
	case 105:
		if nox_client_isConnected_43C700() != 0 {
			v285 = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))
			v286 = v285
			v285 &= math.MaxInt16
			*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)) = v285
			v287 = int32(v286) >> 15
			v288 = (*byte)(unsafe.Pointer(nox_npc_by_id(int32(v285))))
			if v288 != nil {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(nox_init_npc((*nox_npc)(unsafe.Pointer(v288)), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_new_npc(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))))
				v288 = (*byte)(v5)
			}
			if v288 != nil {
				k = int32(uintptr(unsafe.Add(unsafe.Pointer(v288), 8)))
				v289 = (*uint8)(unsafe.Add(unsafe.Pointer(data), 4))
				v358 = (*int32)(unsafe.Add(unsafe.Pointer(v288), 8))
				v360 = 6
				for {
					*(*uint8)(unsafe.Add(unsafe.Pointer(&v5), 4)) = *(*uint8)(unsafe.Add(unsafe.Pointer(v289), 1))
					*((*uint8)(unsafe.Pointer(&v5))) = *v289
					*((*uint8)(unsafe.Pointer(&k))) = *((*uint8)(unsafe.Add(unsafe.Pointer(v289), -1)))
					v289 = (*uint8)(unsafe.Add(unsafe.Pointer(v289), 3))
					*v358 = int32(nox_color_rgb_4344A0(k, int32(v5), *(*int32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))))
					k = int32(uintptr(unsafe.Add(unsafe.Pointer(v358), 4*1)))
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(v360 - 1)
					v250 = v360 == 1
					v358 = (*int32)(unsafe.Add(unsafe.Pointer(v358), 4*1))
					v360--
					if v250 {
						break
					}
				}
				*((*uint32)(unsafe.Add(unsafe.Pointer(v288), 4*328))) = uint32(v287)
			}
		}
		return 21
	case 106:
		v119 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))))
		if v119 == nil {
			return 7
		}
		if !noxflags.HasGame(1) {
			nox_xxx_playerUnsetStatus_417530((*server.Player)(unsafe.Pointer(v119)), 1059)
			nox_xxx_netNeedTimestampStatus_4174F0((*server.Player)(unsafe.Pointer(v119)), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))&0x423))
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || (func() bool {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))
			return uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2))) != nox_player_netCode_85319C
		}()) {
			return 7
		}
		nox_client_onClientStatusA(int32(*(*byte)(unsafe.Add(unsafe.Pointer(v119), 3680))))
		sub_470C40(int32((*((*uint32)(unsafe.Add(unsafe.Pointer(v119), 4*920))) >> 10) & 1))
		return 7
	case 107:
		v69 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v70 = v69
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v70))
			}
			return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v70))
		}())))
		if uint32(int32(v5)) == 0 {
			return 7
		}
		nox_xxx_spriteSetFrameMB_45AB80(int32(v5), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3))))
		return 7
	case 108:
		v184 = uint32(nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
		v185 = v184
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		v186 = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))
		v187 = v186
		v186 &= math.MaxInt16
		*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)) = v186
		nox_xxx_cliSummonCreat_4C2E50(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(v186), int32(v187)&0x8000)
		if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
			v188 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v185).C())
		} else {
			v188 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v185).C())
		}
		if v188 != nil || (func() *uint32 {
			v188 = nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), v185, 0, 0)
			return v188
		}()) != nil {
			sub_459DD0((*client.Drawable)(unsafe.Pointer(v188)), 1)
		}
		sub_495060(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), 0, 0)
		return 5
	case 109:
		v189 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v190 = v189
		if nox_client_isConnected_43C700() == 0 {
			return 3
		}
		v191 = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))
		v192 = v191
		v191 &= math.MaxInt16
		*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)) = v191
		nox_xxx_cliSummonOnDieOrBanish_4C3140(int32(v191), unsafe.Pointer(uintptr(int32(v192)&0x8000)))
		sub_4950C0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v337 = v190
		if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) == 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v337)))))
			if uint32(int32(v5)) != 0 {
				nox_xxx_cliRemoveHealthbar_459E30((*client.Drawable)(v5), 1)
			}
			return 3
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v190)))))
		if uint32(int32(v5)) != 0 {
			nox_xxx_cliRemoveHealthbar_459E30((*client.Drawable)(v5), 1)
		}
		return 3
	case 110:
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		sub_467440(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 1))))
		return 5
	case 111:
		v139 = 0
		if nox_client_isConnected_43C700() != 0 {
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))&0x80 != 0 {
				v139 = 1
			}
			nox_xxx_netSpellRewardCli_45CFE0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))&math.MaxInt8, v139)
		}
		return 4
	case 125, 140, 141, 142:
		if nox_client_isConnected_43C700() == 0 {
			goto LABEL_732
		}
		nox_xxx_netDrawRays_49BDD0(data)
		*(*uint16)(unsafe.Add(unsafe.Pointer(&k), unsafe.Sizeof(uint16(0))*1)) = 0
		v379.X = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))
		v379.Y = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))
		*(*uint16)(unsafe.Add(unsafe.Pointer(&k), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*1)) = 0
		v377.X = int32(uint16(int16(k)))
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))
		v377.Y = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2)))
		*((*uint8)(unsafe.Pointer(&v5))) = *data
		if int32(*data) == 140 || int32(uint8(int8(v5))) == 142 {
			nox_xxx_makeLightningParticles_4999D0(int32(dword_5d4594_1200776), &v379, &v377)
		} else if int32(uint8(int8(v5))) == 125 {
			nox_xxx_drawEnergyBolt_499710(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))), 10, int32(dword_5d4594_1200776))
		}
	LABEL_732:
		return 9
	case 0x7E:
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx_netHandleSummonPacket_4B7C40(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), (*uint16)(unsafe.Add(unsafe.Pointer(data), 1)), *(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)), *((*uint8)(unsafe.Add(unsafe.Pointer(data), 9))), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 10))))
		}
		return 12
	case math.MaxInt8:
		if nox_client_isConnected_43C700() != 0 {
			sub_4B7EE0(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		return 3
	case 0x80:
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx_fxShield_4B8090(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))))
		}
		return 4
	case 0x81:
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		nox_xxx_makePointFxCli_499610(int32(dword_5d4594_1200776), 50, 1000, 30, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3))))
		return 5
	case 0x82:
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		nox_xxx_makePointFxCli_499610(*memmap.PtrInt32(0x5D4594, 1200780), 25, 500, 25, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3))))
		return 5
	case 0x83:
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		nox_xxx_makePointFxCli_499610(*memmap.PtrInt32(0x5D4594, 1200784), 25, 500, 25, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3))))
		return 5
	case 0x84:
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx_makePointFxCli_499610(int32(dword_5d4594_1200796), 25, 500, 25, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3))))
		}
		return 5
	case 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0xA3:
		if nox_client_isConnected_43C700() != 0 {
			k = 0
			switch op {
			case 133:
				v257 = int32(*memmap.PtrUint32(0x5D4594, 1200872))
				if *memmap.PtrUint32(0x5D4594, 1200872) == 0 {
					v257 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("FireBoom"))
					*memmap.PtrUint32(0x5D4594, 1200872) = uint32(v257)
				}
				v258 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v257, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), v258))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
				}
				return 5
			case 134:
				v257 = int32(*memmap.PtrUint32(0x5D4594, 1200876))
				if *memmap.PtrUint32(0x5D4594, 1200876) == 0 {
					v257 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("MediumFireBoom"))
					*memmap.PtrUint32(0x5D4594, 1200876) = uint32(v257)
				}
				v258 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v257, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), v258))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
				}
				return 5
			case 135:
				v257 = int32(*memmap.PtrUint32(0x5D4594, 1200880))
				if *memmap.PtrUint32(0x5D4594, 1200880) == 0 {
					v257 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("CounterspellBoom"))
					*memmap.PtrUint32(0x5D4594, 1200880) = uint32(v257)
				}
				v258 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v257, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), v258))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
				}
				return 5
			case 136:
				v257 = int32(*memmap.PtrUint32(0x5D4594, 1200884))
				if *memmap.PtrUint32(0x5D4594, 1200884) == 0 {
					v257 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ThinFireBoom"))
					*memmap.PtrUint32(0x5D4594, 1200884) = uint32(v257)
				}
				v258 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v257, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), v258))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
				}
				return 5
			case 137:
				v257 = int32(*memmap.PtrUint32(0x5D4594, 1200888))
				if *memmap.PtrUint32(0x5D4594, 1200888) == 0 {
					v257 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("TeleportPoof"))
					*memmap.PtrUint32(0x5D4594, 1200888) = uint32(v257)
				}
				v258 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3))) + 2
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v257, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), v258))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
				}
				return 5
			case 138:
				if *memmap.PtrUint32(0x5D4594, 1200900) == 0 {
					*memmap.PtrUint32(0x5D4594, 1200900) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Smoke")))
					*memmap.PtrUint32(0x5D4594, 1200896) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Puff")))
				}
				v259 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200900), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))))))
				if v259 != 0 {
					*(*uint16)(unsafe.Add(v259, 104)) = 20
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v259))
				}
				v260 = 6
				for {
					v341 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3))) + nox_common_randomIntMinMax_415FF0(-15, 15, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5711)
					v261 = nox_common_randomIntMinMax_415FF0(-15, 15, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5710)
					v262 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200896), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1)))+v261, v341))))
					if v262 != 0 {
						*(*uint16)(unsafe.Add(v262, 104)) = uint16(int16(nox_common_randomIntMinMax_415FF0(5, 25, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5712)))
						nox_xxx_sprite_45A110_drawable((*client.Drawable)(v262))
					}
					v260--
					if v260 == 0 {
						break
					}
				}
				return 5
			case 139:
				v257 = int32(*memmap.PtrUint32(0x5D4594, 1200892))
				if *memmap.PtrUint32(0x5D4594, 1200892) == 0 {
					v257 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("DamagePoof"))
					*memmap.PtrUint32(0x5D4594, 1200892) = uint32(v257)
				}
				v258 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3))) + 2
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v257, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), v258))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
				}
				return 5
			case 163:
				v340 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ManaBombOutRadius")))
				v252 = uint32(int32(v340))
				v357 = 150
				v253 = int32(v252 >> 2)
				for i = int32(v252 >> 2); ; v253 = i {
					v254 = v253 + nox_common_randomIntMinMax_415FF0(0, int32(v252), internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5536)
					if v254 > int32(v252) {
						v254 = int32(v252)
					}
					v255 = nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5541)
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200784), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1)))+v254**memmap.PtrInt32(0x587000, uintptr(v255*8)+192088)/16, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))+v254**memmap.PtrInt32(0x587000, uintptr(v255*8)+192092)/16))))
					v256 = int32(v5)
					if uint32(int32(v5)) != 0 {
						*(*uint32)(unsafe.Add(v5, 432)) = *(*uint32)(unsafe.Add(v5, 12)) << 12
						*(*uint32)(unsafe.Add(v5, 436)) = *(*uint32)(unsafe.Add(v5, 16)) << 12
						*(*uint8)(unsafe.Add(v5, 299)) = 0
						*(*uint32)(unsafe.Add(v5, 440)) = 0
						*(*uint32)(unsafe.Add(v5, 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(30, 40, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5562))
						*(*uint32)(unsafe.Add(v256, 444)) = gameFrame()
						*(*uint16)(unsafe.Add(v256, 104)) = 0
						*(*uint8)(unsafe.Add(v256, 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(4, 10, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5568)))
						nox_xxx_sprite_45A110_drawable((*client.Drawable)(v256))
					}
					if func() int32 {
						p := &v357
						*p--
						return *p
					}() == 0 {
						break
					}
				}
				return 5
			default:
				return 5
			}
		} else {
			return 5
		}
		return -1
	case 0x8F, 0x90, 0x91:
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx_netDrawRays_49BDD0(data)
		}
		return 9
	case 0x93:
		if *memmap.PtrUint32(0x5D4594, 1200852) == 0 {
			*memmap.PtrUint32(0x5D4594, 1200852) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Spark")))
			*memmap.PtrUint32(0x5D4594, 1200856) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("MediumFireBoom")))
			*memmap.PtrUint32(0x5D4594, 1197380) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("FireBoom")))
		}
		if nox_client_isConnected_43C700() == 0 {
			return 6
		}
		v378.X = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1)))
		v378.Y = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))
		sub_49A150(&v378, *memmap.PtrInt32(0x5D4594, 1200852), *((*uint8)(unsafe.Add(unsafe.Pointer(data), 5))))
		v235 = int32(*memmap.PtrUint32(0x5D4594, 1197380))
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5)))) <= 0xAA {
			v235 = int32(*memmap.PtrUint32(0x5D4594, 1200856))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(v235, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))))))
		if uint32(int32(v5)) != 0 {
			nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
		}
		return 6
	case 0x95:
		if nox_client_isConnected_43C700() != 0 {
			sub_4C5020(unsafe.Pointer(data))
			if nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4987) < 25 {
				if *memmap.PtrUint32(0x852978, 8) != 0 {
					v225 = int32(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))) - *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 12)))
					v226 = int32(math.Sqrt(float64(uint32(v225*v225) + (uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)))-*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 16)))*(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)))-*(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 16))))))
					if v226 < 600 {
						nox_xxx_clientPlaySoundSpecial_452D80(297, (600-v226)*100/600)
					}
				}
			}
			if nox_xxx_checkGameFlagPause_413A50() == 0 {
				v227 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))) - int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))
				v228 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))) - int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))
				v229 = int32(math.Sqrt(float64(v227*v227 + v228*v228)))
				if v229 == 0 {
					v229 = 1
				}
				v230 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))) - v227*4/v229
				v231 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))) - v228*4/v229
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(int32(dword_5d4594_1200796), v230, v231))))
				v362 = int32(v5)
				if uint32(int32(v5)) != 0 {
					v232 = (*uint32)(unsafe.Add(v5, 432))
					if uint32(int32(v5)) != 4294966864 {
						*(*uint32)(unsafe.Add(v5, 432)) = uint32(v230 << 12)
						*(*uint32)(unsafe.Add(v5, 436)) = uint32(v231 << 12)
						v233 = int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5024))
						*(*uint8)(unsafe.Add(v362, 299)) = uint8(v233)
						*(*uint32)(unsafe.Add(unsafe.Pointer(v232), 4*2)) = uint32(nox_common_randomIntMinMax_415FF0(1, 1500, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5027))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v232), 4*4)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(5, 20, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5030))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v232), 4*3)) = gameFrame()
					}
					v234 = v362
					*(*uint16)(unsafe.Add(v362, 104)) = 22
					*(*uint8)(unsafe.Add(v234, 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(-4, 4, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5037)))
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v234))
				}
			}
		}
		return 9
	case 0x96:
		if nox_client_isConnected_43C700() != 0 {
			if *memmap.PtrUint32(0x5D4594, 1200860) == 0 {
				*memmap.PtrUint32(0x5D4594, 1200860) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueSpark")))
			}
			v239 = 5
			for {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200860), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))))))
				v240 = int32(v5)
				if uint32(int32(v5)) != 0 {
					if uint32(int32(v5)) != 4294966864 {
						*(*uint32)(unsafe.Add(v5, 432)) = *(*uint32)(unsafe.Add(v5, 12)) << 12
						*(*uint32)(unsafe.Add(v5, 436)) = *(*uint32)(unsafe.Add(v5, 16)) << 12
						*(*uint8)(unsafe.Add(v5, 299)) = uint8(int8(nox_common_randomIntMinMax_415FF0(0, math.MaxUint8, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5338)))
						*(*uint32)(unsafe.Add(v240, 440)) = uint32(nox_common_randomIntMinMax_415FF0(1333, 4000, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5341))
						*(*uint32)(unsafe.Add(v240, 448)) = gameFrame() + uint32(nox_common_randomIntMinMax_415FF0(5, 20, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5344))
						*(*uint32)(unsafe.Add(v240, 444)) = gameFrame()
					}
					*(*uint16)(unsafe.Add(v240, 104)) = 20
					*(*uint8)(unsafe.Add(v240, 296)) = uint8(int8(nox_common_randomIntMinMax_415FF0(-5, 5, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 5351)))
					nox_xxx_sprite_45A110_drawable((*client.Drawable)(v240))
				}
				v239--
				if v239 == 0 {
					break
				}
			}
		}
		return 5
	case 0x97:
		if nox_client_isConnected_43C700() != 0 {
			sub_4355B0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))) / 3)
		}
		return 2
	case 0x98:
		if *memmap.PtrUint32(0x5D4594, 1200844) == 0 {
			*memmap.PtrUint32(0x5D4594, 1200844) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenZap")))
		}
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200844), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))+(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5)))-int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))/2, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))+(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)))-int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))/2)), unsafe.Sizeof(client.Drawable{})*432)))
			*(*uint8)(v5) = 0
			*(*uint32)(unsafe.Add(v5, 5)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 1))
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 5))
			*(*uint32)(unsafe.Add(v5, 9)) = *(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))
			k = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 9)))
			*(*uint32)(unsafe.Add(v5, 1)) = uint32(k)
		}
		return 11
	case 0x9A:
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx____setargv_11_473920()
		}
		return 5
	case 0x9B, 0x9C, 0x9D:
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx_mapGenClientText_4A9D00(data)
		}
		return 3
	case 0x9E:
		*((*uint8)(unsafe.Pointer(&v376))) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))
		switch uint8(int8(v376)) {
		case 1, 2, 3, 4, 5, 6, 7:
			if nox_client_isConnected_43C700() != 0 {
				nox_xxx_clientAddRayEffect_49C160(unsafe.Pointer(data))
			}
			return 7
		case 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE:
			if nox_client_isConnected_43C700() == 0 {
				return 7
			}
			nox_xxx_clientRemoveRayEffect_49C450(unsafe.Pointer(data))
			return 7
		default:
			return -1
		}
	case 0x9F:
		v297 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v298 = v297
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
				if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
					return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v298))
				}
				return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v298))
			}())))
			if uint32(int32(v5)) != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(int32(v5 + 432))
				*(*uint32)(v5) = gameFrame()
				i = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 4)))
				*(*float32)(unsafe.Add(v5, 8)) = float32(float64(i))
				k = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
				i = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
				*(*float32)(unsafe.Add(v5, 4)) = float32(float64(i))
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5))))
				i = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5))))
				*(*float32)(unsafe.Add(v5, 12)) = float32(float64(i))
			}
		}
		return 6
	case 0xA0:
		if nox_client_isConnected_43C700() == 0 {
			return 5
		}
		nox_xxx_fxDrawTurnUndead_499880((*int16)(unsafe.Add(unsafe.Pointer(data), 1)))
		return 5
	case 0xA1:
		if nox_client_isConnected_43C700() == 0 {
			return 6
		}
		if *memmap.PtrUint32(0x5D4594, 1200864) == 0 {
			*memmap.PtrUint32(0x5D4594, 1200864) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ArrowTrap1Smoke")))
			*memmap.PtrUint32(0x5D4594, 1200868) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("ArrowTrap2Smoke")))
		}
		v251 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1)))
		v339 = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 3)))
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5)))) == 1 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200864), v251+15, v339))))
			if uint32(int32(v5)) != 0 {
				nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
				return 6
			}
		} else {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200868), v251-3, v339))))
			if uint32(int32(v5)) != 0 {
				nox_xxx_sprite_45A110_drawable((*client.Drawable)(v5))
			}
			return 6
		}
		return 6
	case 0xA2:
		if nox_client_isConnected_43C700() != 0 {
			if *memmap.PtrUint32(0x5D4594, 1200848) == 0 {
				*memmap.PtrUint32(0x5D4594, 1200848) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("HealOrb")))
			}
			v221 = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 9)))
			k = int32(v221 & 0xFFFC)
			if k <= 28 {
				v222 = int32(v221 >> 2)
			} else {
				v222 = 7
			}
			v223 = v222 + 1
			if v222+1 > 0 {
				for {
					*((*uint8)(unsafe.Pointer(&v368))) = uint8(int8(nox_common_randomIntMinMax_415FF0(6, 12, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4957)))
					v323 = int8(v368)
					v318 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4961)
					v224 = nox_common_randomIntMinMax_415FF0(-20, 20, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4960)
					sub_499490(*memmap.PtrInt32(0x5D4594, 1200848), (*uint16)(unsafe.Add(unsafe.Pointer(data), 1)), v224, v318, v323, 0)
					v223--
					if v223 == 0 {
						break
					}
				}
			}
		}
		return 11
	case 0xA4:
		v15 = (*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(data), nox_xxx_netCliProcUpdateStream_494A60((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)), a1, (*uint32)(unsafe.Pointer(&v384[0])))), 1))
		if uintptr(unsafe.Pointer(v15)) >= uintptr(unsafe.Pointer(end)) {
			return 0
		}
		for {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netCliUpdateStream2_494C30(v15, a1, &v384[0]))))
			if int32(v5) <= 0 {
				break
			}
			v15 = (*uint8)(unsafe.Add(unsafe.Pointer(v15), v5))
			if uintptr(unsafe.Pointer(v15)) >= uintptr(unsafe.Pointer(end)) {
				return 0
			}
		}
		if int32(v5) < 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(-int32(v5))
		}
		return int32(uint32(uintptr(unsafe.Add(unsafe.Pointer(v15), v5))) - uint32(uintptr(unsafe.Pointer(old))))
	case 0xA6, 0xA7:
		if nox_client_isConnected_43C700() == 0 {
			goto LABEL_651
		}
		v338 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))
		v321 = (int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))) >> 9) & 0x7E
		v317 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))) & 0x3FF
		if *data == 167 {
			sub_452E10(v317, v321, v338)
			return 4
		}
		sub_452DC0(v317, v321, v338)
	LABEL_651:
		return 4
	case 0xA8:
		v198 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v199 = v198
		libc.MemSet(memmap.PtrOff(0x5D4594, 1197384), 0, 0x27C)
		v200 = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
		if v200&8 != 0 {
			v201 = nox_strman_loadString_40F1D0((*uint8)(unsafe.Add(unsafe.Pointer(data), 11)), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4486)
			nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)), v201)
			v202 = 1
		} else if v200&2 != 0 {
			if v200&1 != 0 {
				v203 = nox_strman_loadString_40F1D0(internCStr("Guirank.c:team"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4493)
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)), internWStr("%s: %S"), v203, (*uint8)(unsafe.Add(unsafe.Pointer(data), 11)))
			} else {
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)), internWStr("%S"), (*uint8)(unsafe.Add(unsafe.Pointer(data), 11)))
			}
			v202 = 1
		} else {
			if v200&1 != 0 {
				v204 = nox_strman_loadString_40F1D0(internCStr("Guirank.c:team"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4506)
				nox_swprintf((*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)), internWStr("%s: %s"), v204, (*uint8)(unsafe.Add(unsafe.Pointer(data), 11)))
			} else {
				nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)), (*wchar2_t)(unsafe.Add(unsafe.Pointer(data), 11)))
			}
			v202 = 2
		}
		if nox_client_isConnected_43C700() == 0 {
			goto LABEL_693
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))&0x10 != 0 {
			if nox_xxx_gameGetPlayState_4356B0() == 3 {
				nox_wcscpy((*wchar2_t)(memmap.PtrOff(0x5D4594, 1200068)), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)))
				v205 = nox_strman_loadString_40F1D0(internCStr("guiserv.c:Notice"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 4536)
				nox_xxx_dialogMsgBoxCreate_449A10(nil, v205, (*wchar2_t)(memmap.PtrOff(0x5D4594, 1200068)), 33, nil, nil)
				k = v202 * int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 8))))
				return k + 11
			}
		} else if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
			if nox_xxx_gameGetPlayState_4356B0() == 3 {
				v206 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))))
				v207 = v206
				if v206 != nil {
					if nox_xxx_playerCanTalkMB_57A160(int32(uintptr(unsafe.Pointer(v206)))) == 0 {
						nox_gui_console_Printf_450C00(NOX_CONSOLE_YELLOW, (*wchar2_t)(memmap.PtrOff(0x587000, 158984)), (*byte)(unsafe.Add(unsafe.Pointer(v207), 4704)), memmap.PtrOff(0x5D4594, 1197384))
						nox_xxx_createTextBubble_48D880(unsafe.Pointer(data), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)))
						k = v202 * int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 8))))
						return k + 11
					}
				} else {
					nox_xxx_createTextBubble_48D880(unsafe.Pointer(data), (*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)))
					if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v199)))))
					} else {
						*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v199)))))
					}
					if uint32(int32(v5)) != 0 {
						v322 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))
						v208 = int32(uintptr(unsafe.Pointer(nox_get_thing_pretty_name(int32(*(*uint32)(unsafe.Add(v5, 108)))))))
						nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (*wchar2_t)(memmap.PtrOff(0x587000, 159000)), v208, v322, memmap.PtrOff(0x5D4594, 1197384))
					}
				}
			}
		} else if nox_xxx_gameGetPlayState_4356B0() == 3 {
			nox_xxx_printCentered_445490((*wchar2_t)(memmap.PtrOff(0x5D4594, 1197384)))
			k = v202 * int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 8))))
			return k + 11
		}
	LABEL_693:
		k = v202 * int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 8))))
		return k + 11
	case 169:
		return nox_client_handlePacketInform_4C9BF0(unsafe.Pointer(data))
	case 171:
		if nox_client_isConnected_43C700() != 0 {
			nox_net_importantACK_4E55A0(a1, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		return 5
	case 0xAE:
		return 3
	case 0xAF:
		dword_5d4594_1200768 = 0
		v34 = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 1))
		if uint32(nox_xxx_get3512_40A350()) < v34 {
			nox_xxx_set3512_40A340(int32(v34))
			noxflags.HasGame(1024)
			v355 = bool2int32(noxflags.HasGame(32))
			v360 = bool2int32(noxflags.HasGame(32))
			v363 = bool2int32(noxflags.HasGame(4096))
			if !noxflags.HasGame(1) {
				nox_common_gameFlags_unset_40A540(524272)
				nox_xxx_setGameFlags_40A4D0(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 9)))
				sub_409E40(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 13))))
				nox_client_setVersion_409AE0(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 5)))
				nox_xxx_servSetPlrLimit_409F80(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 17)))))
				v35 = nox_xxx_cliGamedataGet_416590(0)
				if *(*byte)(unsafe.Add(unsafe.Pointer(v35), 56)) != *((*uint8)(unsafe.Add(unsafe.Pointer(data), 19))) || int32(*((*uint16)(unsafe.Add(unsafe.Pointer(v35), unsafe.Sizeof(uint16(0))*27)))) != int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 18)))) {
					dword_5d4594_1200768 = 1
				}
				*((*uint16)(unsafe.Add(unsafe.Pointer(v35), unsafe.Sizeof(uint16(0))*27))) = uint16(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 18))))
				*(*byte)(unsafe.Add(unsafe.Pointer(v35), 56)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 19)))
				if int32(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 9))))) >= 0 {
					*((*uint16)(unsafe.Add(unsafe.Pointer(v35), unsafe.Sizeof(uint16(0))*26))) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 9))
					libc.StrCpy(v35, nox_xxx_mapGetMapName_409B40())
				}
				if v355 != 0 || !noxflags.HasGame(32) {
					if !noxflags.HasGame(32) {
						sub_455C10()
					}
				} else {
					sub_455A50(2)
				}
				if v360 != 0 || !noxflags.HasGame(64) {
					if !noxflags.HasGame(64) {
						sub_456050()
					}
				} else {
					sub_455F60()
				}
				if v363 == 1 && !noxflags.HasGame(4096) {
					for j = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0())); j != nil; j = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(j))))) {
						nox_xxx_cliPlayerRespawn_417680(unsafe.Pointer(j), -1)
					}
				}
				if !noxflags.HasGame(0x20000) && nox_xxx_gameGetPlayState_4356B0() == 3 {
					nox_game_exit_xxx2()
				}
			}
		}
		return 20
	case 0xB0:
		if !noxflags.HasGame(1) {
			v37 = nox_xxx_cliGamedataGet_416590(0)
			libc.StrNCpy((*byte)(unsafe.Add(unsafe.Pointer(v37), 9)), (*uint8)(unsafe.Add(unsafe.Pointer(data), 1)), 0xF)
			if libc.MemCmp(memmap.PtrOff(0x5D4594, 1200732), unsafe.Add(unsafe.Pointer(data), 17), 0x14) != 0 {
				dword_5d4594_1200768 = 1
			}
			if *memmap.PtrUint32(0x5D4594, 1200752) != *(*uint32)(unsafe.Add(unsafe.Pointer(data), 37)) || *memmap.PtrUint32(0x5D4594, 1200756) != *(*uint32)(unsafe.Add(unsafe.Pointer(data), 41)) {
				dword_5d4594_1200768 = 1
			}
			alloc.Memcpy(unsafe.Add(unsafe.Pointer(v37), 24), unsafe.Add(unsafe.Pointer(data), 17), 0x14)
			sub_4540E0(unsafe.Add(unsafe.Pointer(v37), 24))
			*((*uint32)(unsafe.Add(unsafe.Pointer(v37), 4*11))) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 37))
			*((*uint32)(unsafe.Add(unsafe.Pointer(v37), 4*12))) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 41))
			if *(*uint32)(unsafe.Add(unsafe.Pointer(data), 45)) != 0 {
				sub_40A1F0(1)
				sub_40A310(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 45))))
			} else {
				sub_40A1F0(0)
			}
			alloc.Memcpy(memmap.PtrOff(0x5D4594, 1200708), unsafe.Pointer(v37), 0x3A)
			if nox_client_isConnected_43C700() != 0 && dword_5d4594_1200768 != 0 {
				v38 = nox_strman_loadString_40F1D0(internCStr("OptionsChanged"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 1429)
				nox_xxx_printCentered_445490(v38)
				nox_xxx_clientPlaySoundSpecial_452D80(310, 100)
			}
		}
		return 49
	case 0xB1:
		v39 = nox_xxx_cliGamedataGet_416590(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))))
		*((*uint8)(unsafe.Pointer(&v40))) = *(*byte)(unsafe.Add(unsafe.Pointer(v39), 52))
		var v4b int32 = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 54))))
		alloc.Memcpy(unsafe.Pointer(v39), unsafe.Add(unsafe.Pointer(data), 2), 0x3A)
		if ((v40 >> 5) & 1) != uint32((v4b>>5)&1) {
			sub_4573A0()
		}
		if sub_4169C0() == 0 {
			if sub_459DA0() == 0 {
				if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))) == 1 {
					sub_4165F0(1, 0)
				}
				if noxflags.HasGame(128) {
					if dword_5d4594_1200832 != 0 {
						v330 = int32(*memmap.PtrUint32(0x8531A0, 2576) + 4704)
						v41 = nox_strman_loadString_40F1D0(internCStr("NameChange"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 1470)
						nox_swprintf(&v401[0], v41, v330)
						nox_xxx_printCentered_445490(&v401[0])
						dword_5d4594_1200832 = 0
					}
					if nox_server_sanctuaryHelp_54276 != 0 {
						nox_xxx_cliShowHelpGui_49C560()
					}
				}
			}
			nox_xxx_cliSetSettingsAcquired_4169D0(1)
		}
		sub_459C30()
		return 60
	case 0xB2:
		v18 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v19 = v18
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
				if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
					return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v19))
				}
				return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v19))
			}())))
			if uint32(int32(v5)) != 0 {
				*(*uint8)(unsafe.Add(v5, 299)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))
			}
		}
		return 4
	case 0xB3:
		v20 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v21 = v20
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
				if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
					return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v21))
				}
				return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v21))
			}())))
			v22 = int32(v5)
			if uint32(int32(v5)) != 0 {
				nox_xxx_spriteSetActiveMB_45A990_drawable(v5)
				v328 = float32(float64(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) * 16 / 10))
				nox_xxx_spriteChangeIntensity_484D70_light_intensity(v22+136, v328)
				nox_xxx_spriteSetFrameMB_45AB80(v22, int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))*8/50)
				if *(*uint32)(unsafe.Add(v22, 308)) == 8 {
					*(*uint32)(unsafe.Add(v22, 308)) = 7
				}
			}
		}
		return 4
	case 0xB4:
		v24 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v25 = v24
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(func() *client.Drawable {
				if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
					return nox_xxx_netSpriteByCodeStatic_45A720(uint32(v25))
				}
				return nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v25))
			}())))
			v26 = int32(v5)
			if uint32(int32(v5)) != 0 {
				if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))) != 0 {
					*(*uint32)(unsafe.Add(v5, 112)) |= 0x80000
					nox_xxx_spriteChangeIntensity_484D70_light_intensity(int32(v5+136), 41.958)
				} else {
					*(*uint32)(unsafe.Add(v5, 112)) &= 0xFFF7FFFF
					nox_xxx_spriteChangeIntensity_484D70_light_intensity(int32(v5+136), 0.0)
				}
				nox_xxx_spriteSetFrameMB_45AB80(v26, int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))))
				*(*uint32)(unsafe.Add(v26, 288)) = gameFrame()
			}
		}
		return 4
	case 0xB5:
		if nox_client_isConnected_43C700() != 0 && (func() uint32 {
			v329 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)))
			v320 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5)))
			v31 = uint32(nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), v31, v320, v329))))
			return uint32(int32(v5))
		}()) != 0 {
			*(*uint16)(unsafe.Add(v5, 508)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 9))
			*(*float32)(unsafe.Add(v5, 468)) = float32(float64(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 12))) * 0.0625)
			*(*float32)(unsafe.Add(v5, 472)) = float32(float64(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 13))) * 0.0625)
			*(*float32)(unsafe.Add(v5, 476)) = float32(float64(*(*uint8)(unsafe.Add(unsafe.Pointer(data), 11))) * 0.0625)
			*(*uint32)(unsafe.Add(v5, 316)) = gameFrame()
			*(*uint32)(unsafe.Add(v5, 324)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5)))
			v32 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7)))
			*(*uint32)(unsafe.Add(v5, 460)) = uint32(uintptr(ccall.FuncAddr(nox_xxx_sprite_4CA540)))
			*(*uint32)(unsafe.Add(v5, 328)) = uint32(v32)
			nox_xxx_spriteToList_49BC80_drawable((*client.Drawable)(v5))
		}
		return 14
	case 0xBD:
		if nox_client_isConnected_43C700() != 0 {
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))) == 1 {
				v290 = nox_strman_loadString_40F1D0(internCStr("sysopAccess"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 6351)
			} else {
				v290 = nox_strman_loadString_40F1D0(internCStr("invalidPass"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 6356)
			}
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v290)
		}
		return 2
	case 0xC3:
		nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))) != 0 || int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
			v27 = nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))))
			if v27 != nil {
				*(*uint32)(unsafe.Add(unsafe.Pointer(v27), 4*72)) = gameFrame()
				nox_xxx_spriteSetFrameMB_45AB80(unsafe.Pointer(v27), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 10)))))
				v28 = uint8(int8((int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 9)))) >> 4) & 7))
				*((*uint8)(unsafe.Add(unsafe.Pointer(v27), 297))) = v28
				if int32(v28) > 3 {
					*((*uint8)(unsafe.Add(unsafe.Pointer(v27), 297))) = uint8(int8(int32(v28) + 1))
				}
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v27), 4*69)) != uint32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 11)))) {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v27), 4*79)) = gameFrame()
					k = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 11))))
					*(*uint32)(unsafe.Add(unsafe.Pointer(v27), 4*69)) = uint32(k)
				}
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))
			if uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2))) == nox_player_netCode_85319C && sub_416120(8) {
				nox_xxx_cliUpdateCameraPos_435600(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))))
			}
			return 12
		}
		nox_xxx_cliUpdateCameraPos_435600(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 7))))
		nox_xxx_setKeybTimeout_4160D0(8)
		return 12
	case 0xC4:
		switch *((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))) {
		case 0:
			if nox_client_isConnected_43C700() == 0 {
				goto LABEL_888
			}
			alloc.Memcpy(unsafe.Pointer(&v386[0]), unsafe.Add(unsafe.Pointer(data), 18), uintptr(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 15))))*2))
			v386[*((*uint8)(unsafe.Add(unsafe.Pointer(data), 15)))] = 0
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 17)))) != 0 {
				v271 = nox_server_teamTitle_418C20(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 16)))))
				nox_swprintf(&v386[0], v271)
			}
			v272 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2))))))
			if v272 == nil {
				v272 = (*byte)(unsafe.Pointer(nox_xxx_teamCreate_4186D0(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))))
				if v272 == nil {
					goto LABEL_888
				}
			}
			sub_418800((*wchar2_t)(unsafe.Pointer(v272)), &v386[0], 0)
			sub_418830(unsafe.Pointer(v272), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 6))))
			nox_xxx_netChangeTeamID_419090(unsafe.Pointer(v272), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 10))))
			*(*byte)(unsafe.Add(unsafe.Pointer(v272), 56)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 16)))
			sub_457230(&v386[0])
			if (int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 14)))) & 1) == 0 {
				goto LABEL_888
			}
			v273 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
			if v273 == nil {
				goto LABEL_888
			}
			if noxflags.HasGame(1) {
				nox_xxx_createAtImpl_4191D0(*(*byte)(unsafe.Add(unsafe.Pointer(v272), 57)), unsafe.Pointer(v273), 1, int32(nox_player_netCode_85319C), 1)
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 15))))
				return int32((*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)))*2 + 18)
			}
			sub_419900(unsafe.Pointer(v272), unsafe.Pointer(v273), int16(uint16(nox_player_netCode_85319C)))
		LABEL_888:
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 15))))
			return int32((*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)))*2 + 18)
		case 1:
			v274 = uint32(nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6)))))
			v275 = v274
			if nox_client_isConnected_43C700() != 0 {
				if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6)))) != 0 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(v275))))
				} else {
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(v275))))
				}
				if uint32(int32(v5)) == 0 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 8))), v275, 0, 0))))
				}
				v276 = int32(v5 + 24)
				if uint32(int32(v5)) != 4294967272 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2)))))))
					v277 = int32(v5)
					if uint32(int32(v5)) != 0 {
						nox_xxx_createAtImpl_4191D0(*(*uint8)(unsafe.Add(v5, 57)), v276, 0, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6))), 0)
						sub_4571A0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6))), int32(*(*uint8)(unsafe.Add(v277, 57))))
					}
				}
			}
			return 10
		case 2:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_objGetTeamByNetCode_418C80(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2))))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_netChangeTeamMb_419570(v5, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2))))
					sub_4571A0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2))), 0)
				}
			}
			return 6
		case 3:
			if nox_client_isConnected_43C700() != 0 {
				v278 = nox_xxx_objGetTeamByNetCode_418C80(uint32(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6)))))
				if v278 != nil {
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2)))))))
					v279 = int32(v5)
					if uint32(int32(v5)) != 0 {
						if sub_4196D0(unsafe.Pointer(v278), v5, int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6))), 0) != 0 {
							sub_4571A0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6))), int32(*(*uint8)(unsafe.Add(v279, 57))))
						}
					}
				}
			}
			return 10
		case 4:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2)))))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_teamRenameMB_418CD0((*wchar2_t)(v5), (*wchar2_t)(unsafe.Add(unsafe.Pointer(data), 6)))
				}
			}
			return 46
		case 5:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2)))))))
				if uint32(int32(v5)) != 0 {
					sub_418D80(int32(v5))
				}
			}
			return 6
		case 6:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2)))))))
				v280 = (*wchar2_t)(v5)
				if uint32(int32(v5)) != 0 {
					nox_wcscpy(&v387[0], (*wchar2_t)(v5))
					sub_418F20((*server.Team)(unsafe.Pointer(v280)), 0)
					sub_456EA0(&v387[0])
				}
			}
			return 6
		case 7:
			if nox_client_isConnected_43C700() != 0 {
				nox_server_teamsZzz_419030(0)
				sub_456FA0()
			}
			return 2
		case 8:
			if nox_client_isConnected_43C700() != 0 && (func() uint32 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 2)))))))
				return uint32(int32(v5))
			}()) != 0 {
				nox_xxx_netChangeTeamID_419090(int32(v5), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 6))))
				return 10
			}
			return 10
		case 9:
			if nox_client_isConnected_43C700() != 0 {
				nox_server_teamsResetYyy_417D00()
			}
			return 2
		case 0xC:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2)))))))
				if uint32(int32(v5)) != 0 {
					*(*uint8)(unsafe.Add(v5, 2282)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 4)))
				}
			}
			return 5
		}
		return -1
	case 0xC5:
		sub_43B6E0()
		return 1
	case 0xC6:
		sub_43B750()
		return 1
	case 0xC9:
		switch *((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))) {
		case 1:
			if nox_client_isConnected_43C700() != 0 {
				sub_4C1590()
			}
			return 2
		case 2:
			if nox_client_isConnected_43C700() != 0 {
				sub_479280()
			}
			return 2
		case 3:
			if nox_client_isConnected_43C700() != 0 {
				sub_4C1BC0(unsafe.Pointer(data))
			}
			return 3
		case 4:
			if nox_client_isConnected_43C700() != 0 {
				nox_xxx_tradeClientAddItem_4C1790(unsafe.Pointer(data))
			}
			return 15
		case 5:
			if nox_client_isConnected_43C700() == 0 {
				return 4
			}
			sub_4C15D0(unsafe.Pointer(data))
			return 4
		case 6:
			if nox_client_isConnected_43C700() == 0 {
				return 14
			}
			sub_4C1B50(unsafe.Pointer(data))
			return 14
		case 7:
			if nox_client_isConnected_43C700() != 0 {
				nox_xxx_prepareP2PTrade_4C1BF0()
			}
			return 2
		case 8:
			if nox_client_isConnected_43C700() != 0 {
				sub_479300(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 4))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 6))), int16(uint16(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 10)))), int32(uintptr(unsafe.Add(unsafe.Pointer(data), 14))))
			}
			return 18
		case 9:
			if nox_client_isConnected_43C700() == 0 {
				return 4
			}
			sub_479480(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
			return 4
		case 0xC:
			if nox_client_isConnected_43C700() != 0 {
				nox_xxx_netP2PStartTrade_4C1320(unsafe.Pointer(data))
			}
			return 52
		case 0xD:
			if nox_client_isConnected_43C700() != 0 {
				nox_xxx_cliStartShopDlg_478FD0((*wchar2_t)(unsafe.Add(unsafe.Pointer(data), 4)), (*uint8)(unsafe.Add(unsafe.Pointer(data), 54)), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
			}
			return 86
		case 0x1B:
			if nox_client_isConnected_43C700() == 0 {
				return 4
			}
			sub_479520(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
			return 4
		case 0x1D:
			if nox_client_isConnected_43C700() != 0 {
				sub_4795E0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 4))))
			}
			return 8
		case 0x1F:
			if nox_client_isConnected_43C700() == 0 {
				return 8
			}
			sub_479740(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))), *(*uint32)(unsafe.Add(unsafe.Pointer(data), 4)))
			return 8
		default:
			return -1
		}
		return -1
	case 0xCA:
		if nox_client_isConnected_43C700() != 0 {
			if int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 1))) == -8531 {
				sub_48E940()
			} else {
				sub_48E8E0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			}
		}
		return 3
	case 0xCB:
		if nox_client_isConnected_43C700() != 0 {
			sub_445450()
		}
		return 1
	case 0xCC:
		if nox_client_isConnected_43C700() != 0 {
			sub_48D5A0(unsafe.Pointer(data))
		}
		k = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
		return k + 4
	case 0xCD:
		v86 = 0
		if nox_client_isConnected_43C700() != 0 {
			v87 = int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2))))
			*((*uint8)(unsafe.Pointer(&v370))) = uint8(int8(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))) & math.MaxInt8))
			if int32(v87) < 0 {
				v86 = 1
			}
			nox_xxx_netAbilityRewardCli_4611E0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(uint8(int8(v370))), (*byte)(v86))
		}
		return 3
	case 0xCE:
		if nox_client_isConnected_43C700() != 0 {
			sub_461090(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
		}
		return 3
	case 0xCF:
		if nox_client_isConnected_43C700() != 0 {
			sub_461120(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
		}
		return 3
	case 0xD1:
		if nox_client_isConnected_43C700() != 0 {
			nox_xxx_netGuideRewardCli_45D140(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2))))&math.MaxInt8)
		}
		return 3
	case 0xD2:
		v281 = uint32(nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
		v282 = v281
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
			v283 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v283)))))
		} else {
			v284 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v284)))))
		}
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5)))) == 1 {
			if uint32(int32(v5)) != 0 || (func() uint32 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), v282, 0, 0))))
				return uint32(int32(v5))
			}()) != 0 {
				sub_459DD0((*client.Drawable)(v5), *((*uint8)(unsafe.Add(unsafe.Pointer(data), 6))))
				return 7
			}
		} else if uint32(int32(v5)) != 0 {
			nox_xxx_cliRemoveHealthbar_459E30((*client.Drawable)(v5), *((*uint8)(unsafe.Add(unsafe.Pointer(data), 6))))
		}
		return 7
	case 0xD3:
		if nox_client_isConnected_43C700() == 0 {
			return 13
		}
		if (gameFrame() - *(*uint32)(unsafe.Add(unsafe.Pointer(data), 9))) >= 0x1E {
			v359 = -44
			nox_xxx_netClientSend2_4E53C0(31, unsafe.Pointer(&v359), 1, 1)
			return 13
		}
		if *(*uint32)(unsafe.Add(unsafe.Pointer(data), 1)) != 0 {
			sub_40A1F0(1)
			v5 = sub_40A310(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 5))))
		} else {
			sub_40A1F0(0)
		}
		return 13
	case 0xD5:
		v296 = int32(*memmap.PtrUint32(0x8531A0, 2576))
		switch *((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))) {
		case 1:
			if nox_client_isConnected_43C700() != 0 {
				if v296 != 0 {
					nox_xxx_journalEntryAdd_427490((*server.Player)(v296), (*uint8)(unsafe.Add(unsafe.Pointer(data), 2)), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 66))))
				}
				nox_xxx_cliBuildJournalString_469BC0()
			}
			return 68
		case 2:
			if nox_client_isConnected_43C700() != 0 {
				if v296 != 0 {
					nox_xxx_journalEntryRemove_427590((*server.Player)(v296), (*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))
				}
				nox_xxx_cliBuildJournalString_469BC0()
			}
			return 68
		case 3:
			if nox_client_isConnected_43C700() != 0 && v296 != 0 {
				nox_xxx_journalUpdateEntry_4276B0((*server.Player)(v296), (*uint8)(unsafe.Add(unsafe.Pointer(data), 2)), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 66))))
			}
			return 68
		}
		return -1
	case 0xD6:
		if nox_client_isConnected_43C700() != 0 {
			nox_client_lockScreenBriefing_450160(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))), 0)
		}
		return 3
	case 0xD7:
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))))
		if uint32(int32(v5)) != 0 {
			*(*uint16)(unsafe.Add(unsafe.Pointer(&k), unsafe.Sizeof(uint16(0))*0)) = *(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))
			*(*uint16)(unsafe.Add(v5, 2148)) = uint16(int16(k))
		}
		return 5
	case 0xD8:
		if nox_client_isConnected_43C700() != 0 {
			sub_455D80(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2))), int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))))
			sub_4705F0(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 4))))
		}
		return 6
	case 0xD9:
		if nox_client_isConnected_43C700() != 0 {
			sub_456140(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))
			sub_470650(int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
		}
		return 4
	case 0xDA:
		v137 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v138 = v137
		if nox_client_isConnected_43C700() != 0 {
			if nox_xxx_unitSpriteCheckAlly_4951F0(v138) != 0 {
				sub_4950F0(v138, int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))))
			}
			nox_npc_set_328(v138, int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))))
		}
		return 4
	case 0xDB:
		v193 = uint32(nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))
		v194 = v193
		if nox_client_isConnected_43C700() != 0 {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
				v195 = (*uint32)(nox_xxx_netSpriteByCodeStatic_45A720(v194).C())
			} else {
				v195 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(v194).C())
			}
			if v195 != nil || (func() *uint32 {
				v195 = nox_xxx_spriteCreate_48E970(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), v194, 0, 0)
				return v195
			}()) != nil {
				sub_459DD0((*client.Drawable)(unsafe.Pointer(v195)), 1)
			}
			sub_495060(int32(v194), 0, 0)
		}
		return 5
	case 0xDC:
		v196 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v197 = v196
		if nox_client_isConnected_43C700() == 0 {
			return 3
		}
		sub_4950C0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v337 = v197
		if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v197)))))
		} else {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v337)))))
		}
		if uint32(int32(v5)) != 0 {
			nox_xxx_cliRemoveHealthbar_459E30((*client.Drawable)(v5), 1)
		}
		return 3
	case 0xDD:
		v90 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v91 = v90
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if uint32(v91) == nox_player_netCode_85319C {
			nox_xxx_cliSetTotalHealth_470C80(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))))
			return 7
		} else if nox_xxx_unitSpriteCheckAlly_4951F0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) != 0 {
			sub_495120(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))))
			return 7
		}
		return 7
	case 0xDE:
		v94 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v95 = v94
		if nox_client_isConnected_43C700() == 0 {
			return 7
		}
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if uint32(v95) != nox_player_netCode_85319C {
			return 7
		}
		nox_xxx_cliSetManaAndMax_470CE0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 5))))
		return 7
	case 0xDF:
		sub_460EB0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 1))), int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 5)))))
		return 6
	case 0xE0:
		v291 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v292 = v291
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))) != 0 {
			sub_467750(v292, int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))))
		} else {
			sub_467750(0, int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3)))))
		}
		return 4
	case 0xE1:
		v293 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		sub_467740(v293)
		return 3
	case 0xE2:
		v294 = nox_xxx_netClearHighBit_578B30(int16(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		v295 = v294
		if nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG) {
			nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(sub_478080(v295))
		if uint32(int32(v5)) != 0 || (func() uint32 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(sub_4676D0(v295))
			return uint32(int32(v5))
		}()) != 0 || (func() uint32 {
			if nox_xxx_netTestHighBit_578B70(uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))) == 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(v295)))))
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(v295)))))
			}
			return uint32(int32(v5))
		}()) != 0 {
			k = int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 3))))
			*(*uint32)(unsafe.Add(v5, 432)) = uint32(k)
		}
		return 4
	case 0xE4:
		if nox_client_isConnected_43C700() != 0 {
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))) == 1 {
				if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
					nox_gameDisableMapDraw_5d4594_2650672 = 0
					sub_413A00(1)
					clientPacketFade(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))) == 1, true)
				}
			} else if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
				clientPacketFade(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))) == 1, false)
			}
		}
		return 3
	case 0xE5:
		if nox_client_isConnected_43C700() != 0 {
			sub_43D9B0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
		}
		return 3
	case 0xE6:
		if nox_client_isConnected_43C700() != 0 {
			sub_43DA80()
		}
		return 3
	case 0xE7:
		if nox_client_isConnected_43C700() != 0 {
			sub_43DAD0()
		}
		return 3
	case 0xE8:
		if nox_client_isConnected_43C700() != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))))
			v111 = (*uint32)(v5)
			if uint32(int32(v5)) != 0 {
				if uint32(int32(v5)) == *memmap.PtrUint32(0x8531A0, 2576) {
					sub_4BFE40()
					sub_478000()
				}
				v112 = (*uint32)(nox_xxx_netSpriteByCodeDynamic_45A6F0(uint32(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1))))).C())
				if v112 != nil {
					nox_xxx_cliRemoveHealthbar_459E30((*client.Drawable)(unsafe.Pointer(v112)), 3)
				}
				if !noxflags.HasGame(4096) {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v111), 4*1)) = 0
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Add(unsafe.Pointer(v111), 4*582)))
					v113 = 27
					for {
						v114 = (*uint32)(v5)
						*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(int32(v5 + 24))
						*(*uint32)(unsafe.Pointer(uintptr(v5 - 4))) = 0
						v5 = int64(uint32(int32(v5)))
						*v114 = 0
						v113--
						*(*uint32)(unsafe.Add(unsafe.Pointer(v114), 4*1)) = 0
						*(*uint32)(unsafe.Add(unsafe.Pointer(v114), 4*2)) = 0
						*(*uint32)(unsafe.Add(unsafe.Pointer(v114), 4*3)) = 0
						if v113 == 0 {
							break
						}
					}
					for k = 0; k < 624; k += 24 {
						v115 = int32(*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v111), k), 2972)))
						if (v115 & 0xC0D) == 0 {
							*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(^v115) & *v111
							*v111 = *(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))
							*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v111), k), 2972)) = 0
							*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v111), k), 2976)) = 0
							*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v111), k), 2980)) = 0
							*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v111), k), 2984)) = 0
							*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v111), k), 2988)) = 0
						}
					}
				}
			}
		}
		return 3
	case 0xE9:
		if nox_client_isConnected_43C700() != 0 {
			if noxflags.HasGame(0x2000) {
				k = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))
				if uint32(uint16(int16(k))) == nox_player_netCode_85319C {
					sub_45A670(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 3)))
				}
			}
			if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 8))))&1 != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 1)))))))
				if uint32(int32(v5)) != 0 {
					nox_xxx_cliPlayerRespawn_417680(int32(v5), int8(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 7)))))
				}
			}
		}
		return 9
	case 0xEA:
		if noxflags.HasGame(0x2000) {
			sub_45A670(*(*uint32)(unsafe.Add(unsafe.Pointer(data), 1)))
			return 5
		}
		return 5
	case 0xEB:
		if nox_client_isConnected_43C700() == 0 {
			return 2
		}
		sub_4610D0(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))))
		return 2
	case 0xEC:
		if nox_client_isConnected_43C700() != 0 {
			sub_43C7A0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))))
		}
		return 2
	case 0xED:
		if nox_client_isConnected_43C700() != 0 {
			sub_4C1CA0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))))
		}
		return 2
	case 0xEE:
		if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))) == 6 {
			sub_48D4B0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
			return 3
		} else if int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 1)))) == 7 {
			sub_48D4A0()
			return 2
		}
		return -1
	case 0xEF:
		nox_client_onClassStats(data, 17)
		return 17
	case 0xF0:
		switch *((*uint8)(unsafe.Add(unsafe.Pointer(data), 1))) {
		case 0:
			if nox_client_isConnected_43C700() == 1 {
				if noxflags.HasGame(1) {
					Sub_460380()
					nox_xxx_cliPrepareGameplay1_460E60()
					sub_41CC00((*byte)(memmap.PtrOff(0x85B3FC, 10984)))
					nox_xxx_plrLoad_41A480((*byte)(memmap.PtrOff(0x85B3FC, 10984)))
				}
				nox_xxx_cliShowHideTubes_470AA0(1)
				sub_48D4A0()
				Nox_xxx_cliPrepareGameplay2_4721D0()
				sub_4705B0()
			}
			return 2
		case 1:
			if nox_client_isConnected_43C700() == 1 {
				nox_xxx_clientPlaySoundSpecial_452D80(1008, 100)
				v299 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))))
				if v299 != nil {
					if !noxflags.HasGame(1) {
						*((*uint32)(unsafe.Add(unsafe.Pointer(v299), 4*1198))) = 1
					}
				}
			}
			return 4
		case 2:
			if nox_client_isConnected_43C700() == 1 {
				sub_49B4B0((*uint16)(unsafe.Pointer(data)))
			}
			return 14
		case 4:
			if nox_client_isConnected_43C700() != 0 {
				v300 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))))
				if v300 != nil {
					*(*byte)(unsafe.Add(unsafe.Pointer(v300), 4816)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))
				if uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(&v5), unsafe.Sizeof(uint16(0))*2))) == nox_player_netCode_85319C {
					sub_463420(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
				}
			}
			return 5
		case 5, 6, 7, 8, 9, 0xA:
			nox_client_isConnected_43C700()
			return 4
		case 0xB:
			nox_client_isConnected_43C700()
			return 16
		case 0xC:
			if nox_client_isConnected_43C700() != 0 {
				nox_xxx_clientQuestWinScreen_450770(int32(uintptr(unsafe.Pointer(data))))
			}
			nox_client_gui_flag_1556112 = 0
			return 90
		case 0xD:
			if nox_client_isConnected_43C700() != 0 {
				nox_client_showQuestBriefing2_450980(int32(uintptr(unsafe.Pointer(data))), int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 4))))&1)
			}
			nox_client_gui_flag_1556112 = 0
			return 69
		case 0xE:
			if nox_client_isConnected_43C700() != 0 {
				nox_client_showQuestBriefing_450A30(int32(uintptr(unsafe.Pointer(data))), 1)
			}
			nox_client_gui_flag_1556112 = 0
			return 69
		case 0xF:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_xxx_netSpriteByCodeStatic_45A720(uint32(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))))))
				if uint32(int32(v5)) != 0 {
					*(*uint8)(unsafe.Add(v5, 432)) = 0
				}
			}
			return 4
		case 0x10:
			if *memmap.PtrUint32(0x5D4594, 1200904) == 0 {
				*memmap.PtrUint32(0x5D4594, 1200904) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenZap")))
			}
			if nox_client_isConnected_43C700() != 0 {
				v301 = int32(uintptr(unsafe.Pointer(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200904), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6))), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 8)))))))
				*(*uint8)(unsafe.Add(v301, 432)) = 0
				*(*uint32)(unsafe.Add(v301, 437)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 2))
				*(*uint32)(unsafe.Add(v301, 441)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 6))
				*(*uint32)(unsafe.Add(v301, 433)) = uint32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 10)))
				nox_xxx_spriteTransparentDecay_49B950((*client.Drawable)(v301), int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 10))))
			}
			return 12
		case 0x11:
			if nox_client_isConnected_43C700() != 0 {
				sub_45D320(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
			}
			return 4
		case 0x12:
			if nox_client_isConnected_43C700() == 0 {
				return 4
			}
			nox_xxx_clientQuestDisableAbility_45D4A0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
			return 4
		case 0x13:
			if nox_client_isConnected_43C700() == 0 {
				return 4
			}
			sub_45D400(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
			return 4
		case 0x14:
			if nox_client_isConnected_43C700() != 1 || sub_470580() != 0 {
				return 2
			}
			sub_4705B0()
			return 2
		case 0x15:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 6)))))))
				if uint32(int32(v5)) != 0 {
					*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1)) = *(*uint32)(unsafe.Add(unsafe.Pointer(data), 2))
					*(*uint32)(unsafe.Add(v5, 4820)) = *(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*1))
				}
			}
			return 8
		case 0x16:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))))))
				if uint32(int32(v5)) != 0 {
					*(*uint8)(unsafe.Add(v5, 4824)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))
				}
			}
			return 5
		case 0x17:
			if nox_client_isConnected_43C700() != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v5), 4*0)) = uint32(uintptr(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3)))))))
				if uint32(int32(v5)) != 0 {
					*(*uint8)(unsafe.Add(v5, 4825)) = *((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))
				}
			}
			return 5
		case 0x18:
			if nox_client_isConnected_43C700() == 1 {
				sub_4BFBB0((*uint32)(unsafe.Pointer(uintptr(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))))
			}
			return 3
		case 0x19:
			if *memmap.PtrUint32(0x5D4594, 1200908) == 0 {
				*memmap.PtrUint32(0x5D4594, 1200908) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("GreenSpark")))
				*memmap.PtrUint32(0x5D4594, 1200912) = uint32(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("FireBoom")))
			}
			v302 = (*uint32)(nox_xxx_spriteLoadAdd_45A360_drawable(*memmap.PtrInt32(0x5D4594, 1200912), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 2))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 4)))).C())
			if v302 != nil {
				nox_xxx_sprite_45A110_drawable((*client.Drawable)(unsafe.Pointer(v302)))
			}
			if nox_client_isConnected_43C700() != 0 {
				v380.X = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 2)))
				v380.Y = int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 4)))
				sub_49A150(&v380, *memmap.PtrInt32(0x5D4594, 1200908), *((*uint8)(unsafe.Add(unsafe.Pointer(data), 6))))
			}
			return 7
		case 0x1A:
			if nox_client_isConnected_43C700() != 0 {
				nox_xxx_makePointFxCli_499610(*memmap.PtrInt32(0x5D4594, 1200788), 25, 500, 25, int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 2))), int32(*(*int16)(unsafe.Add(unsafe.Pointer(data), 4))))
			}
			return 6
		case 0x1C:
			if nox_client_isConnected_43C700() != 0 {
				sub_41D1A0(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
			}
			return 3
		case 0x1D:
			if nox_client_isConnected_43C700() != 0 {
				sub_465DE0(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 2))))
				return 4
			}
			return 4
		case 0x1E:
			v303 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))))
			if nox_client_isConnected_43C700() != 0 && v303 != nil {
				if v303 == *(**byte)(memmap.PtrOff(0x8531A0, 2576)) {
					v348 = int32(uintptr(unsafe.Pointer(nox_xxx_spellTitle_424930(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2))))))))
					v304 = nox_strman_loadString_40F1D0(internCStr("plyrspel.c:AwardSpell"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8112)
					nox_swprintf(&v405[0], v304, v348)
				} else {
					v349 = int32(uintptr(unsafe.Pointer(nox_xxx_spellTitle_424930(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2))))))))
					v305 = nox_strman_loadString_40F1D0(internCStr("plyrspel.c:AwardSpellToOther"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8115)
					nox_swprintf(&v405[0], v305, (*byte)(unsafe.Add(unsafe.Pointer(v303), 4704)), v349)
				}
				nox_xxx_printCentered_445490(&v405[0])
			}
			return 5
		case 0x1F:
			v306 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))))
			if nox_client_isConnected_43C700() == 0 || v306 == nil {
				return 5
			}
			if v306 == *(**byte)(memmap.PtrOff(0x8531A0, 2576)) {
				v350 = nox_xxx_guiCreatureGetName_427240(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
				v307 = nox_strman_loadString_40F1D0(internCStr("PlyrGide.c:AwardGuide"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8145)
				nox_swprintf(&v403[0], v307, v350)
			} else {
				v351 = nox_xxx_guiCreatureGetName_427240(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)))))
				v308 = nox_strman_loadString_40F1D0(internCStr("PlyrGide.c:AwardGuideToOther"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8148)
				nox_swprintf(&v403[0], v308, (*byte)(unsafe.Add(unsafe.Pointer(v306), 4704)), v351)
			}
			nox_xxx_printCentered_445490(&v403[0])
			return 5
		case 0x20:
			v309 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(data), 3))))))
			if nox_client_isConnected_43C700() == 0 || v309 == nil {
				return 5
			}
			if v309 == *(**byte)(memmap.PtrOff(0x8531A0, 2576)) {
				v352 = int32(uintptr(unsafe.Pointer(nox_xxx_abilityGetName_0_425260(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2))))))))
				v310 = nox_strman_loadString_40F1D0(internCStr("ComAblty.c:AwardAbility"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8178)
				nox_swprintf(&v404[0], v310, v352)
			} else {
				v353 = int32(uintptr(unsafe.Pointer(nox_xxx_abilityGetName_0_425260(int32(*((*uint8)(unsafe.Add(unsafe.Pointer(data), 2))))))))
				v311 = nox_strman_loadString_40F1D0(internCStr("ComAblty.c:AwardAbilityToOther"), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8181)
				nox_swprintf(&v404[0], v311, (*byte)(unsafe.Add(unsafe.Pointer(v309), 4704)), v353)
			}
			nox_xxx_printCentered_445490(&v404[0])
			return 5
		case 0x21:
			if nox_client_isConnected_43C700() != 0 {
				v383[0] = int32(uintptr(memmap.PtrOff(0x587000, 160948)))
				v383[1] = int32(uintptr(memmap.PtrOff(0x587000, 160988)))
				v383[2] = int32(uintptr(memmap.PtrOff(0x587000, 161028)))
				v383[3] = int32(uintptr(memmap.PtrOff(0x587000, 161068)))
				v383[4] = int32(uintptr(memmap.PtrOff(0x587000, 161112)))
				v354 = nox_strman_loadString_40F1D0((*byte)(unsafe.Pointer(uintptr(v383[*((*uint8)(unsafe.Add(unsafe.Pointer(data), 51)))]))), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8217)
				v312 = nox_strman_loadString_40F1D0((*uint8)(unsafe.Add(unsafe.Pointer(data), 2)), nil, internCStr("C:\\NoxPost\\src\\Client\\Network\\cdecode.c"), 8216)
				nox_swprintf(&v402[0], v312, v354)
				nox_xxx_printCentered_445490(&v402[0])
			}
			return 52
		default:
			return -1
		}
		return -1
	default:
		return -1
	}
}
