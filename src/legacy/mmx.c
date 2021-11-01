//+build none

//----- (004445C0) --------------------------------------------------------
void nox_setProfiledMode_4445C0() {
	int v0;  // ebx
	int v4;  // ebx
	int v5;  // ebp
	int v9;  // [esp+10h] [ebp-Ch]
	int v10; // [esp+14h] [ebp-8h]
	int v11; // [esp+18h] [ebp-4h]

#if 0
    signed int v1; // eax
    int v2; // esi
    int v3; // eax
    if (nox_xxx_testCPUID2_444D90())
    {
        v1 = sub_444DD0();
        v2 = v1;
        if (v1)
        {
            v3 = v1 + 5;
            if (v2 + 5 <= 450)
            {
                if (v3 <= 300)
                {
                    if (v3 <= 266)
                        v0 = v3 <= 200 ? 0 : 0xC8;
                    else
                        v0 = 266;
                }
                else
                {
                    v0 = 300;
                }
            }
            else
            {
                v0 = 450;
            }
        }
        else
        {
            v0 = 0;
        }
        if (!nox_xxx____crtGetStringTypeA_0_444830() && v2 < 550)
            v0 = 200;
    }
    else
#endif
	{ v0 = 0; }
	*getMemU32Ptr(0x587000, 80808) = 1;
	*getMemU32Ptr(0x587000, 80816) = 1;
	nox_client_showTooltips_80840 = 1;
	nox_client_renderGUI_80828 = 1;
	nox_xxx_xxxRenderGUI_587000_80832 = 1;
	if (v0 <= 266) {
		if (v0 != 266) {
			if (!v0) {
				v4 = 8;
				v5 = 75;
				nox_client_drawFrontWalls_80812 = 0;
				goto LABEL_21;
			}
			if (v0 == 200) {
				v4 = 8;
				v5 = 85;
				nox_client_drawFrontWalls_80812 = 1;
			LABEL_21:
				nox_client_translucentFrontWalls_805844 = 0;
				nox_client_highResFrontWalls_80820 = 0;
				nox_client_highResFloors_154952 = 0;
				nox_client_lockHighResFloors_1193152 = 0;
				nox_client_texturedFloors_154956 = 1;
				nox_client_translucentConsole_80824 = 0;
				nox_client_renderGlow_805852 = 0;
				nox_client_fadeObjects_80836 = 0;
				nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
				nox_client_renderBubbles_80844 = 0;
				goto LABEL_30;
			}
			goto LABEL_29;
		}
		v4 = 8;
		goto LABEL_27;
	}
	if (v0 == 300) {
		v4 = 16;
	LABEL_27:
		v5 = 100;
		nox_client_drawFrontWalls_80812 = 1;
		nox_client_translucentFrontWalls_805844 = 1;
		nox_client_highResFrontWalls_80820 = 1;
		nox_client_highResFloors_154952 = 1;
		nox_client_lockHighResFloors_1193152 = 0;
		nox_client_texturedFloors_154956 = 1;
		nox_client_translucentConsole_80824 = 0;
		goto LABEL_28;
	}
	if (v0 == 450) {
		v4 = 16;
		v5 = 100;
		nox_client_drawFrontWalls_80812 = 1;
		nox_client_translucentFrontWalls_805844 = 1;
		nox_client_highResFrontWalls_80820 = 1;
		nox_client_highResFloors_154952 = 1;
		nox_client_lockHighResFloors_1193152 = 1;
		nox_client_texturedFloors_154956 = 1;
		nox_client_translucentConsole_80824 = 1;
	LABEL_28:
		nox_client_renderGlow_805852 = 1;
		nox_client_fadeObjects_80836 = 1;
		nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
		nox_client_renderBubbles_80844 = 1;
		goto LABEL_30;
	}
LABEL_29:
	v4 = v9;
	v5 = v9;
LABEL_30:
	nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v11, &v10, &v9);
	v4 = 16; // 8 bit not supported
	nox_xxx_tileSetDrawFn_481420();
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE))
		nox_xxx_gameResizeScreen_43BEF0_set_video_mode(NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, v4);
	nox_video_setCutSize_4766A0(v5);
	if (nox_common_gameFlags_check_40A5C0(0x10000000))
		nox_draw_setCutSize_476700(v5, 0);
	nox_profiled_805856 = 1;
}

#if 0
//----- (00444830) --------------------------------------------------------
BOOL nox_xxx____crtGetStringTypeA_0_444830()
{
    unsigned __int8 v11[40]; // [esp+Ch] [ebp-28h]

    _EAX = 0;
    __asm { cpuid }
    _EAX = 0;
    __asm { cpuid }
    return strcmp("GenuineIntel", (const char*)v11) == 0;
}
#endif

#if 0
//----- (00444D90) --------------------------------------------------------
BOOL nox_xxx_testCPUID2_444D90()
{
    unsigned int v0; // edx
    unsigned int v1; // et0
    unsigned int v2; // ebx
    unsigned int v3; // et0

    v0 = 0;
    v1 = __readeflags();
    v2 = v1;
    __writeeflags(v1 ^ 0x200000);
    v3 = __readeflags();
    if (v3 != v2)
    {
        _EAX = 0;
        __asm { cpuid }
        v0 = 0;
        if (BYTE1(_EAX) != 5)
        {
            if (_EAX)
            {
                _EAX = 1;
                __asm { cpuid }
                v0 = 0x800000 & _EDX;
            }
        }
    }
    return v0 != 0;
}

//----- (00444DD0) --------------------------------------------------------
signed int sub_444DD0()
{
    int v0; // ecx
    int v1; // eax
    unsigned int v2; // ebx
    unsigned __int64 v3; // rax
    unsigned __int64 v4; // rax
    unsigned int v5; // esi
    DWORD v6; // edi
    int v7; // eax
    unsigned int v8; // ecx
    signed int result; // eax
    LARGE_INTEGER Frequency; // [esp+4h] [ebp-30h]
    LARGE_INTEGER PerformanceCount; // [esp+Ch] [ebp-28h]
    LARGE_INTEGER v12; // [esp+14h] [ebp-20h]
    int v13; // [esp+1Ch] [ebp-18h]
    int v14; // [esp+20h] [ebp-14h]
    int v15; // [esp+24h] [ebp-10h]
    unsigned int v16; // [esp+28h] [ebp-Ch]
    int v17; // [esp+2Ch] [ebp-8h]
    int v18; // [esp+30h] [ebp-4h]

    if (!QueryPerformanceFrequency(&Frequency))
        return 0;
    v0 = 0;
    v1 = 0;
    v2 = 0;
    v16 = 0;
    v18 = 0;
    while (1)
    {
        v17 = v0;
        ++v18;
        v15 = v1;
        QueryPerformanceCounter(&PerformanceCount);
        v12 = PerformanceCount;
        do
            QueryPerformanceCounter(&v12);
        while (v12.LowPart - PerformanceCount.LowPart < 0x32);
        v3 = __rdtsc();
        v13 = v3;
        PerformanceCount = v12;
        do
            QueryPerformanceCounter(&v12);
        while (v12.LowPart - PerformanceCount.LowPart < 0x3E8);
        v4 = __rdtsc();
        v14 = v4;
        v5 = v4 - v13;
        v2 += v4 - v13;
        v6 = (100000 * v12.LowPart - 100000 * PerformanceCount.LowPart) / (Frequency.LowPart / 0xA);
        v16 += v6;
        if (v6 % Frequency.LowPart > Frequency.LowPart >> 1)
            ++v6;
        v0 = v5 / v6;
        if (v5 % v6 > v6 >> 1)
            ++v0;
        v7 = v0 + v15 + v17;
        if (v18 >= 3
            && (v18 >= 20
                || (unsigned int)(3 * v0 - v7) <= 3 && (unsigned int)(3 * v17 - v7) <= 3 && (unsigned int)(3 * v15 - v7) <= 3))
        {
            break;
        }
        v1 = v17;
    }
    v8 = 10 * v2 / v16;
    if (100 * v2 / v16 - 10 * v8 >= 6)
        ++v8;
    result = v2 / v16;
    if (v8 - 10 * (v2 / v16) >= 6)
        ++result;
    if (result < 0)
        result = 0;
    return result;
}
#endif

#if 0
//----- (00480290) --------------------------------------------------------
unsigned int  sub_480290(__m64 * a1, int a2, int a3, unsigned int* a4, unsigned int* a5)
{
    unsigned int result; // eax
    __m64* v6; // esi
    __m64 v7; // mm3
    __m64 v8; // mm4
    __m64 v9; // mm3
    __m64 v10; // mm5
    __m64 v11; // mm4
    __m64 v12; // mm6
    __m64 v13; // mm3
    __m64 v14; // mm5
    int v15; // ecx
    __m64 v16; // mm6
    __m64 v17; // mm7
    __m64 v18; // mm1
    __m64 v19; // mm2
    __m64 v20; // mm7
    __m64 v21; // mm3
    __m64 v22; // mm6
    __m64 v23; // mm6
    __m64 v24; // mm4
    __m64 v25; // mm5
    int v26; // edi
    __m64 v27; // mm2
    __m64 v28; // mm6
    __m64 v29; // mm3
    __m64 v30; // mm1
    __m64 v31; // mm0
    __m64* v32; // esi
    __m64 v33; // mm1
    __m64 v34; // mm2
    __m64 v35; // mm4
    __m64 v36; // mm0
    __m64 v37; // mm5
    __m64 v38; // mm0
    bool v39; // zf
    __m64 v40; // mm2
    __m64 v41; // mm6
    __m64 v42; // mm1
    __m64 v43; // mm0
    __m64 v44; // mm1
    __m64 v45; // mm2
    __m64 v46; // mm0
    bool v47; // cc
    __m64* v48; // esi
    __m64 v49; // mm3
    __m64 v50; // mm3
    __m64 v51; // mm4
    __m64 v52; // mm3
    __m64 v53; // mm5
    __m64 v54; // mm4
    __m64 v55; // mm5
    __m64 v56; // mm4
    __m64 v57; // mm5
    __m64 v58; // mm2
    __m64 v59; // mm1
    __m64 v60; // mm0
    __m64 v61; // mm2
    __m64 v62; // mm0
    bool v63; // cc
    int v64; // ecx
    __m64 v65; // [esp+Ch] [ebp-18h]
    __m64 v66; // [esp+14h] [ebp-10h]
    __m64 v67; // [esp+1Ch] [ebp-8h]

    result = (unsigned int)a4;
    if (a5[2] | a5[1] | *a5)
    {
        v6 = a1;
        v7 = _mm_cvtsi32_si64(*a5);
        v8 = _mm_cvtsi32_si64(a5[1]);
        v9 = _m_punpcklwd(v7, v7);
        v10 = _mm_cvtsi32_si64(a5[2]);
        v11 = _m_punpcklwd(v8, v8);
        v12 = _mm_cvtsi32_si64(*a4);
        v13 = _m_punpckldq(v9, v9);
        v14 = _m_punpcklwd(v10, v10);
        v15 = a3;
        v16 = _m_punpcklwd(v12, v12);
        v17 = _mm_cvtsi32_si64(a4[1]);
        v18 = _m_punpckldq(v11, v11);
        v65 = _m_psllwi(v13, 2u);
        v19 = _m_punpckldq(v14, v14);
        v20 = _m_punpcklwd(v17, v17);
        v21 = _m_paddw(_m_pmullw(v13, *(__m64*) getMemAt(0x587000, 154916)), _m_punpckldq(v16, v16));
        v22 = _mm_cvtsi32_si64(a4[2]);
        v23 = _m_punpcklwd(v22, v22);
        v66 = _m_psllwi(v18, 2u);
        v67 = _m_psllwi(v19, 2u);
        v24 = _m_paddw(_m_pmullw(v18, *(__m64*) getMemAt(0x587000, 154916)), _m_punpckldq(v20, v20));
        v25 = _m_paddw(_m_pmullw(v19, *(__m64*) getMemAt(0x587000, 154916)), _m_punpckldq(v23, v23));
        v26 = a2 - 8;
        while (1)
        {
            v27 = (__m64)v6->m64_u64;
            v28 = v21;
            v29 = _m_paddw(v21, v65);
            v30 = _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
            v31 = _m_pmullw(
                _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
                _m_psrlwi(v28, 8u));
            v32 = v6 + 1;
            v33 = _m_psrlw(
                _m_pand(_m_pmullw(v30, _m_psrlwi(v24, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
                *(__m64*) getMemAt(0x5D4594, 2598164));
            v34 = _m_pmullw(_m_psllwi(_m_pand(v27, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v25, 8u));
            v35 = _m_paddw(v24, v66);
            v36 = _m_por(_m_psrlw(_m_pand(v31, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)), v33);
            if ((int)v32 >= *(int*)& dword_5d4594_3798844)
                v32 = (__m64*)((char*)v32 + *(_DWORD*)& dword_5d4594_3798796 - *(_DWORD*)& dword_5d4594_3798844);
            v37 = _m_paddw(v25, v67);
            v26 += 8;
            v38 = _m_por(v36, _m_psrlwi(_m_pand(v34, *(__m64*) getMemAt(0x5D4594, 2598100)), 0xBu));
            v39 = v15 == 4;
            v47 = v15 < 4;
            v15 -= 4;
            if (v47)
                break;
            *(__m64*)v26 = v38;
            if (v39)
                return result;
            v40 = (__m64)v32->m64_u64;
            v41 = v29;
            v21 = _m_paddw(v29, v65);
            v42 = _m_psrlw(_m_pand((__m64)v32->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
            v43 = _m_pmullw(
                _m_psrlw(_m_pand((__m64)v32->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
                _m_psrlwi(v41, 8u));
            v6 = v32 + 1;
            v44 = _m_psrlw(
                _m_pand(_m_pmullw(v42, _m_psrlwi(v35, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
                *(__m64*) getMemAt(0x5D4594, 2598164));
            v45 = _m_pmullw(_m_psllwi(_m_pand(v40, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v37, 8u));
            v24 = _m_paddw(v35, v66);
            v46 = _m_por(_m_psrlw(_m_pand(v43, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)), v44);
            if ((int)v6 >= *(int*)& dword_5d4594_3798844)
                v6 = (__m64*)((char*)v6 + *(_DWORD*)& dword_5d4594_3798796 - *(_DWORD*)& dword_5d4594_3798844);
            v25 = _m_paddw(v37, v67);
            v26 += 8;
            v38 = _m_por(v46, _m_psrlwi(_m_pand(v45, *(__m64*) getMemAt(0x5D4594, 2598100)), 0xBu));
            v47 = v15 < 4;
            v15 -= 4;
            if (v47)
                break;
            *(__m64*)v26 = v38;
            if (v47)
                return result;
        }
    }
    else
    {
        v48 = a1;
        v49 = _mm_cvtsi32_si64(*a4);
        v50 = _m_punpcklwd(v49, v49);
        v26 = a2 - 8;
        v51 = _mm_cvtsi32_si64(a4[1]);
        v52 = _m_punpckldq(v50, v50);
        v53 = _mm_cvtsi32_si64(a4[2]);
        v54 = _m_punpcklwd(v51, v51);
        v15 = a3;
        v55 = _m_punpcklwd(v53, v53);
        v56 = _m_punpckldq(v54, v54);
        v57 = _m_punpckldq(v55, v55);
        while (1)
        {
            v58 = (__m64)v48->m64_u64;
            v59 = _m_psrlw(_m_pand((__m64)v48->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
            v60 = _m_pmullw(
                _m_psrlw(_m_pand((__m64)v48->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
                _m_psrlwi(v52, 8u));
            ++v48;
            v61 = _m_pmullw(_m_psllwi(_m_pand(v58, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v57, 8u));
            v62 = _m_por(
                _m_psrlw(_m_pand(v60, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)),
                _m_psrlw(
                    _m_pand(_m_pmullw(v59, _m_psrlwi(v56, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
                    *(__m64*) getMemAt(0x5D4594, 2598164)));
            if ((int)v48 >= *(int*)& dword_5d4594_3798844)
                v48 = (__m64*)((char*)v48 + *(_DWORD*)& dword_5d4594_3798796 - *(_DWORD*)& dword_5d4594_3798844);
            v26 += 8;
            v38 = _m_por(v62, _m_psrlwi(_m_pand(v61, *(__m64*) getMemAt(0x5D4594, 2598100)), 0xBu));
            v63 = v15 < 4;
            v15 -= 4;
            if (v63)
                break;
            *(__m64*)v26 = v38;
            if (v63)
                return result;
        }
    }
    result = _mm_cvtsi64_si32(v38);
    *(_WORD*)v26 = result;
    v64 = v15 + 3;
    if (v64)
    {
        result >>= 16;
        *(_WORD*)(v26 + 2) = result;
        if (v64 != 1)
        {
            result = _mm_cvtsi64_si32(_m_psrlqi(v38, 0x20u));
            *(_WORD*)(v26 + 4) = result;
        }
    }
    return result;
}
#endif

#if 0
//----- (004805A0) --------------------------------------------------------
__int16  sub_4805A0(int a1, __m64 * a2, int a3, unsigned int* a4, unsigned int* a5)
{
    __int16 result; // ax
    __m64* v6; // esi
    __m64 v7; // mm3
    __m64 v8; // mm4
    __m64 v9; // mm3
    __m64 v10; // mm5
    __m64 v11; // mm4
    __m64 v12; // mm6
    __m64 v13; // mm3
    __m64 v14; // mm5
    int v15; // ecx
    __m64 v16; // mm6
    __m64 v17; // mm7
    __m64 v18; // mm1
    __m64 v19; // mm2
    __m64 v20; // mm7
    __m64 v21; // mm3
    __m64 v22; // mm6
    __m64 v23; // mm6
    __m64 v24; // mm4
    __m64 v25; // mm5
    __m64* v26; // edi
    __m64 v27; // mm2
    __m64 v28; // mm6
    __m64 v29; // mm1
    __m64 v30; // mm0
    __m64 v31; // mm1
    __m64 v32; // mm2
    __m64 v33; // mm0
    bool v34; // cc
    __int16* v35; // esi
    __m64 v36; // [esp+Ch] [ebp-20h]
    __m64 v37; // [esp+14h] [ebp-18h]
    __m64 v38; // [esp+1Ch] [ebp-10h]
    __m64 v39; // [esp+24h] [ebp-8h]

    result = (__int16)a4;
    v6 = a2;
    v7 = _mm_cvtsi32_si64(*a5);
    v8 = _mm_cvtsi32_si64(a5[1]);
    v9 = _m_punpcklwd(v7, v7);
    v10 = _mm_cvtsi32_si64(a5[2]);
    v11 = _m_punpcklwd(v8, v8);
    v12 = _mm_cvtsi32_si64(*a4);
    v13 = _m_punpckldq(v9, v9);
    v14 = _m_punpcklwd(v10, v10);
    v15 = a3;
    v16 = _m_punpcklwd(v12, v12);
    v17 = _mm_cvtsi32_si64(a4[1]);
    v18 = _m_punpckldq(v11, v11);
    v36 = _m_psllwi(v13, 2u);
    v19 = _m_punpckldq(v14, v14);
    v20 = _m_punpcklwd(v17, v17);
    v21 = _m_paddw(_m_pmullw(v13, *(__m64*) getMemAt(0x587000, 154924)), _m_punpckldq(v16, v16));
    v22 = _mm_cvtsi32_si64(a4[2]);
    v23 = _m_punpcklwd(v22, v22);
    v37 = _m_psllwi(v18, 2u);
    v38 = _m_psllwi(v19, 2u);
    v24 = _m_paddw(_m_pmullw(v18, *(__m64*) getMemAt(0x587000, 154924)), _m_punpckldq(v20, v20));
    v25 = _m_paddw(_m_pmullw(v19, *(__m64*) getMemAt(0x587000, 154924)), _m_punpckldq(v23, v23));
    v26 = (__m64*)(a1 - 8);
    while (1)
    {
        v27 = (__m64)v6->m64_u64;
        v28 = v21;
        v21 = _m_paddw(v21, v36);
        v29 = _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598060)), *(__m64*) getMemAt(0x5D4594, 2598156));
        v30 = _m_pmullw(
            _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) getMemAt(0x5D4594, 2598028)), *(__m64*) getMemAt(0x5D4594, 2598124)),
            _m_psrlwi(v28, 8u));
        ++v6;
        v31 = _m_psrlw(
            _m_pand(_m_pmullw(v29, _m_psrlwi(v24, 8u)), *(__m64*) getMemAt(0x5D4594, 2598068)),
            *(__m64*) getMemAt(0x5D4594, 2598164));
        v24 = _m_paddw(v24, v37);
        v32 = _m_pand(
            _m_pmullw(_m_psllwi(_m_pand(v27, *(__m64*) getMemAt(0x5D4594, 2598092)), 3u), _m_psrlwi(v25, 8u)),
            *(__m64*) getMemAt(0x5D4594, 2598100));
        v25 = _m_paddw(v25, v38);
        ++v26;
        v33 = _m_por(
            _m_por(_m_psrlw(_m_pand(v30, *(__m64*) getMemAt(0x5D4594, 2598036)), *(__m64*) getMemAt(0x5D4594, 2598132)), v31),
            _m_psrlwi(v32, 0xBu));
        if (v15 < 4)
            break;
        v26->m64_u64 = (unsigned __int64)v33;
        v34 = v15 <= 4;
        v15 -= 4;
        if (v34)
            goto LABEL_7;
    }
    v39 = v33;
    v35 = (__int16*)& v39;
    do
    {
        result = *v35;
        ++v35;
        LOWORD(v26->m64_i32[0]) = result;
        v26 = (__m64*)((char*)v26 + 2);
        v34 = v15-- <= 1;
    } while (!v34);
LABEL_7:
    _m_femms();
    return result;
}
#endif

#if 0
//----- (00480700) --------------------------------------------------------
__int16  sub_480700(int a1, __m64 * a2, int a3, unsigned int* a4, unsigned int* a5)
{
    __int16 result; // ax
    __m64* v6; // esi
    __m64 v7; // mm3
    __m64 v8; // mm4
    __m64 v9; // mm3
    __m64 v10; // mm5
    __m64 v11; // mm4
    __m64 v12; // mm6
    __m64 v13; // mm3
    __m64 v14; // mm5
    int v15; // ecx
    __m64 v16; // mm6
    __m64 v17; // mm7
    __m64 v18; // mm1
    __m64 v19; // mm2
    __m64 v20; // mm7
    __m64 v21; // mm3
    __m64 v22; // mm6
    __m64 v23; // mm6
    __m64 v24; // mm4
    __m64 v25; // mm5
    __m64* v26; // edi
    __m64 v27; // mm2
    __m64 v28; // mm6
    __m64 v29; // mm1
    __m64 v30; // mm0
    __m64 v31; // mm1
    __m64 v32; // mm2
    __m64 v33; // mm0
    bool v34; // cc
    __int16* v35; // esi
    __m64 v36; // [esp+Ch] [ebp-20h]
    __m64 v37; // [esp+14h] [ebp-18h]
    __m64 v38; // [esp+1Ch] [ebp-10h]
    __m64 v39; // [esp+24h] [ebp-8h]

    result = (__int16)a4;
    v6 = a2;
    v7 = _mm_cvtsi32_si64(*a5);
    v8 = _mm_cvtsi32_si64(a5[1]);
    v9 = _m_punpcklwd(v7, v7);
    v10 = _mm_cvtsi32_si64(a5[2]);
    v11 = _m_punpcklwd(v8, v8);
    v12 = _mm_cvtsi32_si64(*a4);
    v13 = _m_punpckldq(v9, v9);
    v14 = _m_punpcklwd(v10, v10);
    v15 = a3;
    v16 = _m_punpcklwd(v12, v12);
    v17 = _mm_cvtsi32_si64(a4[1]);
    v18 = _m_punpckldq(v11, v11);
    v36 = _m_psllwi(v13, 2u);
    v19 = _m_punpckldq(v14, v14);
    v20 = _m_punpcklwd(v17, v17);
    v21 = _m_paddw(_m_pmullw(v13, *(__m64*) getMemAt(0x587000, 154932)), _m_punpckldq(v16, v16));
    v22 = _mm_cvtsi32_si64(a4[2]);
    v23 = _m_punpcklwd(v22, v22);
    v37 = _m_psllwi(v18, 2u);
    v38 = _m_psllwi(v19, 2u);
    v24 = _m_paddw(_m_pmullw(v18, *(__m64*) getMemAt(0x587000, 154932)), _m_punpckldq(v20, v20));
    v25 = _m_paddw(_m_pmullw(v19, *(__m64*) getMemAt(0x587000, 154932)), _m_punpckldq(v23, v23));
    v26 = (__m64*)(a1 - 8);
    while (1)
    {
        v27 = (__m64)v6->m64_u64;
        v28 = v21;
        v21 = _m_paddw(v21, v36);
        v29 = _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
        v30 = _m_pmullw(
            _m_psrlw(_m_pand((__m64)v6->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
            _m_psrlwi(v28, 8u));
        ++v6;
        v31 = _m_psrlw(
            _m_pand(_m_pmullw(v29, _m_psrlwi(v24, 8u)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 64)),
            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 136));
        v24 = _m_paddw(v24, v37);
        v32 = _m_pand(
            _m_pmullw(
                _m_psllw(_m_pand(v27, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                _m_psrlwi(v25, 8u)),
            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 72));
        v25 = _m_paddw(v25, v38);
        ++v26;
        v33 = _m_por(
            _m_por(_m_psrlw(_m_pand(v30, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 56)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 128)), v31),
            _m_psrlw(v32, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 144)));
        if (v15 < 4)
            break;
        v26->m64_u64 = (unsigned __int64)v33;
        v34 = v15 <= 4;
        v15 -= 4;
        if (v34)
            goto LABEL_7;
    }
    v39 = v33;
    v35 = (__int16*)& v39;
    do
    {
        result = *v35;
        ++v35;
        LOWORD(v26->m64_i32[0]) = result;
        v26 = (__m64*)((char*)v26 + 2);
        v34 = v15-- <= 1;
    } while (!v34);
LABEL_7:
    _m_femms();
    return result;
}
#endif

#if 0
//----- (0049D540) --------------------------------------------------------
int  sub_49D540(int a1, int a2, int a3, int a4)
{
    __m64 v4; // mm0
    __m64 v5; // mm1
    __m64 v6; // mm2
    int* v7; // esi
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    __m64 v13; // mm4
    __m64 v14; // mm5
    __m64 v15; // mm3
    bool v16; // cc
    int v17; // ecx
    __m64 v18; // [esp+Ch] [ebp-8h]
    __m64 v19; // [esp+Ch] [ebp-8h]

    v18.m64_i32[0] = *(_DWORD*)(&obj_5D4594_3800716.data[61]);
    v18.m64_i32[1] = *(_DWORD*)(&obj_5D4594_3800716.data[61]);
    v4 = _m_psrlw(_m_pand(v18, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80));
    v5 = _m_psrlw(_m_pand(v18, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
    v6 = _m_psllw(_m_pand(v18, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96));
    v7 = (int*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v7;
        ++v7;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_psrlw(_m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80));
            v13 = _m_psrlw(_m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
            v14 = _m_psllw(_m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96));
            v15 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(_m_paddw(v12, _m_psrlwi(_m_psubw(v4, v12), 1u)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                    _m_pand(
                        _m_psllw(_m_paddw(v13, _m_psrlwi(_m_psubw(v5, v13), 1u)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40))),
                _m_psrlw(_m_paddw(v14, _m_psrlwi(_m_psubw(v6, v14), 1u)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)));
            v16 = v9 < 4;
            v9 -= 4;
            if (v16)
                break;
            v11->m64_u64 = (unsigned __int64)v15;
            ++v11;
            if (v16)
            {
                v16 = a4-- <= 1;
                if (!v16)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v19 = v15;
        LOWORD(v11->m64_i32[0]) = v19.m64_i16[0];
        v17 = v9 + 3;
        if (v17)
        {
            HIWORD(v11->m64_i32[0]) = v19.m64_i16[1];
            if (v17 != 1)
                LOWORD(v11->m64_i32[1]) = v19.m64_i16[2];
        }
        v16 = a4-- <= 1;
        if (!v16)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}
#endif

#if 0
//----- (0049D770) --------------------------------------------------------
void  sub_49D770(int a1, int a2, unsigned int a3, int a4)
{
    _DWORD* v4; // esi
    __m64 v5; // mm1
    int v6; // edx
    int v7; // ebx
    unsigned int v8; // eax
    signed int v9; // ecx
    __m64* v10; // edi
    bool v11; // cc
    signed int v12; // ecx
    __m64* v13; // edi
    signed int v14; // ecx
    __m64* v15; // edi
    signed int v16; // ecx
    __m64* v17; // edi

    if (a4 > 0 && (int)a3 > 0)
    {
        v4 = (_DWORD*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
        v5 = *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 152);
        v6 = _mm_cvtsi64_si32(*(__m64*) ((_BYTE*)byte_5D4594_3804364 + 152));
        v7 = 2 * a1;
        v8 = a3 >> 1;
        if (a3 & 1)
        {
            if (v8 & 1)
            {
                do
                {
                    v14 = a3 >> 2;
                    v15 = (__m64*)(v7 + *v4);
                    do
                    {
                        v15->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v15->m64_u64, v5), 1u);
                        ++v15;
                        v11 = v14-- <= 1;
                    } while (!v11);
                    v15->m64_i32[0] = ((unsigned int)v6 & v15->m64_i32[0]) >> 1;
                    HIWORD(v15->m64_i32[0]) = (unsigned __int16)(v6 & HIWORD(v15->m64_i32[0])) >> 1;
                    ++v4;
                    v11 = a4-- <= 1;
                } while (!v11);
            }
            else
            {
                do
                {
                    v12 = a3 >> 2;
                    v13 = (__m64*)(v7 + *v4);
                    do
                    {
                        v13->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v13->m64_u64, v5), 1u);
                        ++v13;
                        v11 = v12-- <= 1;
                    } while (!v11);
                    LOWORD(v13->m64_i32[0]) = (unsigned __int16)(v6 & LOWORD(v13->m64_i32[0])) >> 1;
                    ++v4;
                    v11 = a4-- <= 1;
                } while (!v11);
            }
        }
        else if (v8 & 1)
        {
            do
            {
                v9 = a3 >> 2;
                v10 = (__m64*)(v7 + *v4);
                do
                {
                    v10->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v10->m64_u64, v5), 1u);
                    ++v10;
                    v11 = v9-- <= 1;
                } while (!v11);
                v10->m64_i32[0] = ((unsigned int)v6 & v10->m64_i32[0]) >> 1;
                ++v4;
                v11 = a4-- <= 1;
            } while (!v11);
        }
        else
        {
            do
            {
                v16 = a3 >> 2;
                v17 = (__m64*)(v7 + *v4);
                do
                {
                    v17->m64_u64 = (unsigned __int64)_m_psrlwi(_m_pand((__m64)v17->m64_u64, v5), 1u);
                    ++v17;
                    v11 = v16-- <= 1;
                } while (!v11);
                ++v4;
                v11 = a4-- <= 1;
            } while (!v11);
        }
        _m_femms();
    }
}
#endif

#if 0
//----- (0049D9A0) --------------------------------------------------------
int  sub_49D9A0(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    __m64 v5; // mm0
    __m64 v6; // mm1
    __m64 v7; // mm2
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    bool v13; // cc
    int v14; // ecx
    __m64 v15; // [esp+Ch] [ebp-8h]

    v4 = (int*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
    v5 = *(__m64*)(&obj_5D4594_3800716.data[48]);
    v6 = *(__m64*)(&obj_5D4594_3800716.data[50]);
    v7 = *(__m64*)(&obj_5D4594_3800716.data[52]);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v4;
        ++v4;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(
                            _m_paddusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                                v5),
                            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                    _m_pand(
                        _m_psllw(
                            _m_paddusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)),
                                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                                v6),
                            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40))),
                _m_psrlw(
                    _m_paddusb(
                        _m_psllw(
                            _m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)),
                            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                        v7),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)));
            v13 = v9 < 4;
            v9 -= 4;
            if (v13)
                break;
            v11->m64_u64 = (unsigned __int64)v12;
            ++v11;
            if (v13)
            {
                v13 = a4-- <= 1;
                if (!v13)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v15 = v12;
        LOWORD(v11->m64_i32[0]) = v15.m64_i16[0];
        v14 = v9 + 3;
        if (v14)
        {
            HIWORD(v11->m64_i32[0]) = v15.m64_i16[1];
            if (v14 != 1)
                LOWORD(v11->m64_i32[1]) = v15.m64_i16[2];
        }
        v13 = a4-- <= 1;
        if (!v13)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}

#endif

#if 0
//----- (0049DC70) --------------------------------------------------------
int  sub_49DC70(int a1, int a2, int a3, int a4)
{
    int* v4; // esi
    __m64 v5; // mm0
    __m64 v6; // mm1
    __m64 v7; // mm2
    int result; // eax
    int v9; // ecx
    int v10; // edi
    __m64* v11; // edi
    __m64 v12; // mm3
    bool v13; // cc
    int v14; // ecx
    __m64 v15; // [esp+Ch] [ebp-8h]

    v4 = (int*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2);
    v5 = *(__m64*)(&obj_5D4594_3800716.data[48]);
    v6 = *(__m64*)(&obj_5D4594_3800716.data[50]);
    v7 = *(__m64*)(&obj_5D4594_3800716.data[52]);
    result = 2 * a1;
LABEL_2:
    while (1)
    {
        v9 = a3;
        v10 = *v4;
        ++v4;
        v11 = (__m64*)(result + v10);
        while (1)
        {
            v12 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(
                            _m_psubusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                                v5),
                            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                    _m_pand(
                        _m_psllw(
                            _m_psubusb(
                                _m_psrlw(
                                    _m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)),
                                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                                v6),
                            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40))),
                _m_psrlw(
                    _m_psubusb(
                        _m_psllw(
                            _m_pand((__m64)v11->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)),
                            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                        v7),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)));
            v13 = v9 < 4;
            v9 -= 4;
            if (v13)
                break;
            v11->m64_u64 = (unsigned __int64)v12;
            ++v11;
            if (v13)
            {
                v13 = a4-- <= 1;
                if (!v13)
                    goto LABEL_2;
                goto LABEL_11;
            }
        }
        v15 = v12;
        LOWORD(v11->m64_i32[0]) = v15.m64_i16[0];
        v14 = v9 + 3;
        if (v14)
        {
            HIWORD(v11->m64_i32[0]) = v15.m64_i16[1];
            if (v14 != 1)
                LOWORD(v11->m64_i32[1]) = v15.m64_i16[2];
        }
        v13 = a4-- <= 1;
        if (!v13)
            continue;
        break;
    }
LABEL_11:
    _m_femms();
    return result;
}
#endif

#if 0
//----- (0049F210) --------------------------------------------------------
__int16  sub_49F210(int a1, int a2, int a3)
{
    int v3; // ecx
    int v4; // edx
    int v5; // eax
    int v6; // edi
    int v7; // esi
    int v8; // ecx
    int v9; // ecx
    __m64 v10; // mm4
    __m64 v11; // mm4
    __m64 v12; // mm5
    __m64 v13; // mm6
    __m64* v14; // edi
    __m64 v15; // mm4
    __m64 v16; // mm0
    __m64 v17; // mm1
    __m64 v18; // mm2
    __m64 v19; // mm0
    char v20; // cc
    _WORD* v21; // edi
    int v22; // ecx
    _WORD* v23; // edi
    __m64 v25; // [esp+Ch] [ebp-8h]

    v3 = a3;
    v4 = a1;
    if (a1 > a3)
    {
        LOWORD(v5) = a1;
        v4 = a3;
        v3 = a1;
    }
    if (ptr_5D4594_3799572->data[0])
    {
        v6 = ptr_5D4594_3799572->data[7];
        if (v4 > v6)
            return v5;
        v7 = ptr_5D4594_3799572->data[5];
        if (v3 < v7)
            return v5;
        v5 = ptr_5D4594_3799572->data[6];
        if (a2 < v5)
            return v5;
        v5 = ptr_5D4594_3799572->data[8];
        if (a2 > v5)
            return v5;
        if (v4 < v7)
            v4 = ptr_5D4594_3799572->data[5];
        if (v3 > v6)
            v3 = ptr_5D4594_3799572->data[7];
    }
    v8 = v3 - v4;
    v20 = (v8 + 1 < 0) ^ __OFADD__(1, v8) | (v8 == -1);
    v9 = v8 + 1;
    if (!v20)
    {
        v10 = _mm_cvtsi32_si64(ptr_5D4594_3799572->data[61]);
        v11 = _m_por(_m_psllqi(v10, 0x20u), v10);
        v12 = _m_psrlw(_m_pand(v11, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
        v13 = _m_psllw(_m_pand(v11, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96));
        v14 = (__m64*)(*(_DWORD*)(*(_DWORD*)& nox_pixbuffer_rows_3798784 + 4 * a2) + 2 * v4);
        v15 = _m_psrlw(_m_pand(v11, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80));
        while (1)
        {
            v16 = _m_psrlw(_m_pand((__m64)v14->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80));
            v17 = _m_psrlw(_m_pand((__m64)v14->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
            v18 = _m_psllw(_m_pand((__m64)v14->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96));
            v19 = _m_por(
                _m_por(
                    _m_pand(
                        _m_psllw(_m_paddw(v16, _m_psrlwi(_m_psubw(v15, v16), 1u)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                    _m_pand(
                        _m_psllw(_m_paddw(v17, _m_psrlwi(_m_psubw(v12, v17), 1u)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40))),
                _m_psrlw(_m_paddw(v18, _m_psrlwi(_m_psubw(v13, v18), 1u)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)));
            v20 = v9 < 4;
            v9 -= 4;
            if (v20)
                break;
            v14->m64_u64 = (unsigned __int64)v19;
            ++v14;
            if (v20)
                goto LABEL_20;
        }
        v25 = v19;
        LOWORD(v5) = v25.m64_i16[0];
        LOWORD(v14->m64_i32[0]) = v25.m64_i16[0];
        v21 = (_WORD*)((char*)v14->m64_i32 + 2);
        v22 = v9 + 3;
        if (v22)
        {
            LOWORD(v5) = v25.m64_i16[1];
            *v21 = v25.m64_i16[1];
            v23 = v21 + 1;
            if (v22 != 1)
            {
                LOWORD(v5) = v25.m64_i16[2];
                *v23 = v25.m64_i16[2];
            }
        }
    }
LABEL_20:
    _m_femms();
    return v5;
}
#endif

#if 0
//----- (004C82C0) --------------------------------------------------------
__int16 sub_4C82C0()
{
    int v0; // ecx
    __m64* v1; // esi
    __m64* v2; // edi
    __m64 v3; // mm7
    __m64 v4; // mm0
    __m64 v5; // mm1
    __m64 v6; // mm2
    __m64 v7; // mm0
    bool v8; // cc
    __int16 result; // ax
    int v10; // ecx
    __m64 v11; // [esp+Ch] [ebp-8h]

    v0 = *getMemU32Ptr(0x5D4594, 3799456);
    v1 = *(__m64 * *) getMemAt(0x5D4594, 3799444);
    v2 = *(__m64 * *) & dword_5d4594_3799540;
    v3 = *(__m64*)(&ptr_5D4594_3799572->data[260]);
    while (1)
    {
        v4 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80));
        v5 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
        v6 = _m_psllw(_m_pand((__m64)v2->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96));
        v7 = _m_por(
            _m_por(
                _m_pand(
                    _m_psrlw(
                        _m_paddw(
                            _m_psllwi(v4, 8u),
                            _m_pmullw(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                                    v4),
                                v3)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 104)),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                _m_pand(
                    _m_psrlw(
                        _m_paddw(
                            _m_psllwi(v5, 8u),
                            _m_pmullw(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)),
                                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                                    v5),
                                v3)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 112)),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40))),
            _m_psrlw(
                _m_paddw(
                    _m_psllwi(v6, 8u),
                    _m_pmullw(
                        _m_psubw(
                            _m_psllw(
                                _m_pand((__m64)v1->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)),
                                *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                            v6),
                        v3)),
                *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 120)));
        v8 = v0 < 4;
        v0 -= 4;
        if (v8)
            break;
        v2->m64_u64 = (unsigned __int64)v7;
        ++v1;
        ++v2;
        if (v8)
            goto LABEL_8;
    }
    v11 = v7;
    result = v11.m64_i16[0];
    LOWORD(v2->m64_i32[0]) = v11.m64_i16[0];
    v1 = (__m64*)((char*)v1 + 2);
    v2 = (__m64*)((char*)v2 + 2);
    v10 = v0 + 3;
    if (v10)
    {
        result = v11.m64_i16[1];
        LOWORD(v2->m64_i32[0]) = v11.m64_i16[1];
        v1 = (__m64*)((char*)v1 + 2);
        v2 = (__m64*)((char*)v2 + 2);
        if (v10 != 1)
        {
            result = v11.m64_i16[2];
            LOWORD(v2->m64_i32[0]) = v11.m64_i16[2];
            v1 = (__m64*)((char*)v1 + 2);
            v2 = (__m64*)((char*)v2 + 2);
        }
    }
LABEL_8:
    *getMemU32Ptr(0x5D4594, 3799444) = v1;
    *(_DWORD*)& dword_5d4594_3799540 = v2;
    return result;
}
#endif

#if 0
//----- (004C8570) --------------------------------------------------------
__int16 sub_4C8570()
{
    int v0; // ecx
    __m64* v1; // esi
    __m64* v2; // edi
    __m64 v3; // mm0
    __m64 v4; // mm1
    __m64 v5; // mm2
    __m64 v6; // mm0
    bool v7; // cc
    __int16 result; // ax
    int v9; // ecx
    __m64 v10; // [esp+Ch] [ebp-8h]

    v0 = *getMemU32Ptr(0x5D4594, 3799456);
    v1 = *(__m64 * *) getMemAt(0x5D4594, 3799444);
    v2 = *(__m64 * *) & dword_5d4594_3799540;
    while (1)
    {
        v3 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80));
        v4 = _m_psrlw(_m_pand((__m64)v2->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
        v5 = _m_psllw(_m_pand((__m64)v2->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96));
        v6 = _m_por(
            _m_por(
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v3,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                                    v3),
                                1u)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v4,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlw(
                                        _m_pand((__m64)v1->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)),
                                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                                    v4),
                                1u)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40))),
            _m_psrlw(
                _m_paddw(
                    v5,
                    _m_psrlwi(
                        _m_psubw(
                            _m_psllw(
                                _m_pand((__m64)v1->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)),
                                *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                            v5),
                        1u)),
                *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)));
        v7 = v0 < 4;
        v0 -= 4;
        if (v7)
            break;
        v2->m64_u64 = (unsigned __int64)v6;
        ++v1;
        ++v2;
        if (v7)
            goto LABEL_8;
    }
    v10 = v6;
    result = v10.m64_i16[0];
    LOWORD(v2->m64_i32[0]) = v10.m64_i16[0];
    v1 = (__m64*)((char*)v1 + 2);
    v2 = (__m64*)((char*)v2 + 2);
    v9 = v0 + 3;
    if (v9)
    {
        result = v10.m64_i16[1];
        LOWORD(v2->m64_i32[0]) = v10.m64_i16[1];
        v1 = (__m64*)((char*)v1 + 2);
        v2 = (__m64*)((char*)v2 + 2);
        if (v9 != 1)
        {
            result = v10.m64_i16[2];
            LOWORD(v2->m64_i32[0]) = v10.m64_i16[2];
            v1 = (__m64*)((char*)v1 + 2);
            v2 = (__m64*)((char*)v2 + 2);
        }
    }
LABEL_8:
    *getMemU32Ptr(0x5D4594, 3799444) = v1;
    *(_DWORD*)& dword_5d4594_3799540 = v2;
    return result;
}
#endif

#if 0
//----- (004C8760) --------------------------------------------------------
__int32 sub_4C8760()
{
    __m64 v0; // mm6
    __m64 v1; // mm5
    __m64 v2; // mm4
    __m64 v3; // mm3
    __m64* v4; // edi
    __m64* v5; // esi
    int v6; // ecx
    bool v7; // cc
    __m64 v8; // mm0
    __int32 result; // eax
    int v10; // ecx
    __m64 v11; // [esp+Ch] [ebp-8h]

    v0 = *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40);
    v1 = *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32);
    v2 = *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88);
    v3 = *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80);
    v4 = *(__m64 * *) & dword_5d4594_3799540;
    v5 = *(__m64 * *) getMemAt(0x5D4594, 3799444);
    v6 = *getMemU32Ptr(0x5D4594, 3799456);
    while (1)
    {
        v7 = v6 < 4;
        v6 -= 4;
        v8 = _m_por(
            _m_por(
                _m_pand(
                    _m_psrlw(
                        _m_pmullw(_m_psrlw(_m_pand((__m64)v5->m64_u64, v1), v3), *(__m64*)(&obj_5D4594_3800716.data[18])),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 104)),
                    v1),
                _m_psrlw(
                    _m_pmullw(
                        _m_psllw(_m_pand((__m64)v5->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                        *(__m64*)(&obj_5D4594_3800716.data[22])),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 120))),
            _m_pand(
                _m_psrlw(
                    _m_pmullw(_m_psrlw(_m_pand((__m64)v5->m64_u64, v0), v2), *(__m64*)(&obj_5D4594_3800716.data[20])),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 112)),
                v0));
        if (v7)
            break;
        ++v5;
        v4->m64_u64 = (unsigned __int64)v8;
        ++v4;
        if (v7)
            goto LABEL_8;
    }
    v11 = v8;
    result = v11.m64_i32[0];
    LOWORD(v4->m64_i32[0]) = v11.m64_i16[0];
    v5 = (__m64*)((char*)v5 + 2);
    v4 = (__m64*)((char*)v4 + 2);
    v10 = v6 + 3;
    if (v10)
    {
        result = *(__int32*)((char*)v11.m64_i32 + 2);
        LOWORD(v4->m64_i32[0]) = v11.m64_i16[1];
        v5 = (__m64*)((char*)v5 + 2);
        v4 = (__m64*)((char*)v4 + 2);
        if (v10 != 1)
        {
            result = v11.m64_i32[1];
            v5 = (__m64*)((char*)v5 + 2);
            LOWORD(v4->m64_i32[0]) = v11.m64_i16[2];
            v4 = (__m64*)((char*)v4 + 2);
        }
    }
LABEL_8:
    *getMemU32Ptr(0x5D4594, 3799444) = v5;
    *(_DWORD*)& dword_5d4594_3799540 = v4;
    return result;
}
#endif

#if 0
//----- (004C8C00) --------------------------------------------------------
__int16 sub_4C8C00()
{
    int v0; // ecx
    __m64 v1; // mm5
    __m64 v2; // mm6
    __m64 v3; // mm7
    __m64* v4; // esi
    __m64* v5; // edi
    bool v6; // cc
    __m64 v7; // mm0
    __m64 v8; // mm1
    __m64 v9; // mm2
    __m64 v10; // mm0
    __int16 result; // ax
    int v12; // ecx
    __m64 v13; // [esp+Ch] [ebp-8h]

    v0 = *getMemU32Ptr(0x5D4594, 3799456);
    v1 = *(__m64*)(&ptr_5D4594_3799572->data[18]);
    v2 = *(__m64*)(&ptr_5D4594_3799572->data[20]);
    v3 = *(__m64*)(&ptr_5D4594_3799572->data[22]);
    v4 = *(__m64 * *) getMemAt(0x5D4594, 3799444);
    v5 = *(__m64 * *) & dword_5d4594_3799540;
    while (1)
    {
        v6 = v0 < 4;
        v0 -= 4;
        v7 = _m_psrlw(_m_pand((__m64)v5->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80));
        v8 = _m_psrlw(_m_pand((__m64)v5->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88));
        v9 = _m_psllw(_m_pand((__m64)v5->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)), *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96));
        v10 = _m_por(
            _m_por(
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v7,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlwi(
                                        _m_pmullw(
                                            _m_psrlw(
                                                _m_pand((__m64)v4->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                                                *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                                            v1),
                                        8u),
                                    v7),
                                1u)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 80)),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 32)),
                _m_pand(
                    _m_psllw(
                        _m_paddw(
                            v8,
                            _m_psrlwi(
                                _m_psubw(
                                    _m_psrlwi(
                                        _m_pmullw(
                                            _m_psrlw(
                                                _m_pand((__m64)v4->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40)),
                                                *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                                            v2),
                                        8u),
                                    v8),
                                1u)),
                        *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 88)),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 40))),
            _m_pand(
                _m_psrlw(
                    _m_paddw(
                        v9,
                        _m_psrlwi(
                            _m_psubw(
                                _m_psrlwi(
                                    _m_pmullw(
                                        _m_psllw(
                                            _m_pand((__m64)v4->m64_u64, *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)),
                                            *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                                        v3),
                                    8u),
                                v9),
                            1u)),
                    *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 96)),
                *(__m64*) ((_BYTE*)byte_5D4594_3804364 + 48)));
        if (v6)
            break;
        v5->m64_u64 = (unsigned __int64)v10;
        ++v4;
        ++v5;
        if (v6)
            goto LABEL_8;
    }
    v13 = v10;
    result = v13.m64_i16[0];
    LOWORD(v5->m64_i32[0]) = v13.m64_i16[0];
    v4 = (__m64*)((char*)v4 + 2);
    v5 = (__m64*)((char*)v5 + 2);
    v12 = v0 + 3;
    if (v12)
    {
        result = v13.m64_i16[1];
        LOWORD(v5->m64_i32[0]) = v13.m64_i16[1];
        v4 = (__m64*)((char*)v4 + 2);
        v5 = (__m64*)((char*)v5 + 2);
        if (v12 != 1)
        {
            result = v13.m64_i16[2];
            v4 = (__m64*)((char*)v4 + 2);
            LOWORD(v5->m64_i32[0]) = v13.m64_i16[2];
            v5 = (__m64*)((char*)v5 + 2);
        }
    }
LABEL_8:
    *getMemU32Ptr(0x5D4594, 3799444) = v4;
    *(_DWORD*)& dword_5d4594_3799540 = v5;
    return result;
}
#endif
