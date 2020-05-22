#include "../../proto.h"

//----- (004D1860) --------------------------------------------------------
int sub_4D1860_server()
{
    int v0; // esi
    int v1; // edi
    char* v2; // eax
    int i; // eax
    int j; // eax
    char* v5; // eax
    int v6; // esi
    char* v7; // ebx
    int* v8; // eax
    int* v9; // eax
    char* v10; // eax
    int v11; // eax
    __int16 v12; // ax
    int v13; // eax
    int* v14; // eax
    int k; // esi
    char* v17; // eax
    int v18; // eax
    int v19; // esi
    int v20; // edi
    int v21; // ebx
    int v22; // eax
    int v23; // ecx
    wchar_t* v24; // eax
    int l; // ebx
    char* v27; // eax
    int v28; // eax
    int v29; // esi
    char* v30; // eax
    int v31; // eax
    int v32; // eax
    char* v33; // eax
    int v34; // eax
    int v35; // eax
    float* v36; // esi
    char* v37; // eax
    double v38; // st7
    char* v39; // eax
    double v40; // st7
    char* v41; // eax
    int v42; // eax
    const char* v43; // edi
    int v44; // esi
    float2* v45; // edi
    int m; // ebx
    int n; // esi
    int v48; // edi
    int* v49; // eax
    int ii; // eax
    int jj; // eax
    int v52; // eax
    int v53; // eax
    int v54; // eax
    char* v55; // eax
    unsigned int v56; // esi
    char v57; // al
    int* v58; // [esp-1Ch] [ebp-68h]
    __int16 v59; // [esp-14h] [ebp-60h]
    __int16 v60; // [esp-14h] [ebp-60h]
    float2 v61; // [esp+0h] [ebp-4Ch]
    __int64 v62; // [esp+8h] [ebp-44h]
    int v63[15]; // [esp+10h] [ebp-3Ch]

    if (sub_40A5C0(2))
        sub_477610(10);
    sub_4D22B0();
    sub_4D9800(0, 1);
    v0 = 0;
    if (*(_DWORD*)& byte_5D4594[1599640] > 0)
    {
        v1 = 0;
        do
        {
            if (!strncmp("MapExit", *(const char**)(v1 + *(_DWORD*)& byte_5D4594[1599636]), 7u))
                sub_507310(v0, 0, 0);
            ++v0;
            v1 += 48;
        } while (v0 < *(int*)& byte_5D4594[1599640]);
    }
    v2 = sub_409B40();
    sub_500510(v2);
    sub_4D12E0(1);
    for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
        * (_DWORD*)(i + 16) |= 0x80000000;
    for (j = sub_4DA840(); j; j = sub_4DA850(j))
        * (_DWORD*)(j + 16) |= 0x80000000;
    if (sub_40A5C0(2048))
    {
        sub_424BD0();
        sub_4537F0();
    }
    if (sub_4DB240())
    {
        v5 = sub_4DB260();
        v6 = sub_4CF5F0(v5, 0);
    }
    else
    {
        v7 = sub_4165B0();
        if (sub_40A5C0(0x2000))
        {
            if (!v7[57])
            {
                strcpy((char*)v63, v7);
                v59 = *((_WORD*)v7 + 26);
                v8 = (int*)sub_459870();
                sub_57A1E0(v63, "user.rul", v8, 3, v59);
                v9 = (int*)sub_459870();
                sub_57AAA0("user.rul", v7, v9);
            }
            sub_424BD0();
            sub_4537F0();
        }
        v10 = sub_409B30();
        v6 = sub_4CF5F0(v10, 0);
        if (sub_40A5C0(0x2000) && !sub_40A5C0(128))
        {
            v11 = sub_40A8A0();
            v13 = 0;
            if (v11)
            {
                v12 = sub_40A5B0();
                if (sub_40A180(v12))
                    v13 = 1;
            }
            sub_40A1F0(v13);
            sub_40A250();
            v60 = sub_40A5B0();
            v58 = (int*)sub_459870();
            v14 = (int*)sub_416590(0);
            sub_57A1E0(v14, "user.rul", v58, 3, v60);
            sub_4D2230();
        }
    }
    if (!v6)
    {
        sub_4D15F0();
        return 0;
    }
    if (!sub_40A5C0(2048))
        sub_519EB0();
    sub_4DAC00();
    for (k = sub_4DA7C0(); k; k = sub_4DA7F0(k))
    {
        sub_4EF660(k);
        sub_4F7AB0(&v61, k);
        if (sub_40A5C0(128))
        {
            if (sub_417DD0())
            {
                if (!sub_417DA0(2) && !sub_40A5C0(0x8000))
                {
                    v17 = sub_418AB0(*(unsigned __int8*)(k + 52));
                    if (v17)
                        sub_4ED970(50.0, (float2*)(*((_DWORD*)v17 + 18) + 56), &v61);
                }
            }
        }
        sub_4E7010(k, &v61);
        if (!sub_40A5C0(512))
        {
            v18 = *(_DWORD*)(k + 748);
            *(_DWORD*)(*(_DWORD*)(v18 + 276) + 2136) = 0;
            *(_DWORD*)(*(_DWORD*)(v18 + 276) + 2140) = 0;
            *(_DWORD*)(*(_DWORD*)(v18 + 276) + 2144) = *(_DWORD*)& byte_5D4594[2598000];
            sub_4D8EF0(k);
        }
    }
    sub_50AFA0();
    sub_50B520();
    v19 = 0;
    v20 = 0;
    v21 = 0;
    *(_DWORD*)& byte_5D4594[1548528] = 0;
    *(_DWORD*)& byte_5D4594[1548532] = 0;
    if (!*(_DWORD*)& byte_5D4594[1548708])
        * (_DWORD*)& byte_5D4594[1548708] = sub_4E3AA0((CHAR*)& byte_587000[196512]);
    if (!*(_DWORD*)& byte_5D4594[1548712])
        * (_DWORD*)& byte_5D4594[1548712] = sub_4E3AA0((CHAR*)& byte_587000[196524]);
    v22 = sub_4DA790();
    if (!v22)
        goto LABEL_120;
    do
    {
        if (*(_DWORD*)(v22 + 8) & 0x10000000)
        {
            *(_DWORD*)(v22 + 136) = 0;
            *(_DWORD*)& byte_5D4594[1548532] = v22;
            ++v19;
        }
        v23 = *(unsigned __int16*)(v22 + 4);
        if ((unsigned __int16)v23 == *(_DWORD*)& byte_5D4594[1548712])
        ++v21;
        if (v23 == *(_DWORD*)& byte_5D4594[1548708])
            ++v20;
        v22 = sub_4DA7A0(v22);
    } while (v22);
    if (!v20)
    {
        LABEL_120:
        v24 = loadString_sub_40F1D0((char*)& byte_587000[196580], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 792);
        LABEL_61:
        sub_4D9FD0(0, v24);
        return 0;
    }
    if (sub_40A5C0(96) && v19 < 2)
    {
        v24 = loadString_sub_40F1D0((char*)& byte_587000[196644], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 799);
        goto LABEL_61;
    }
    if (sub_40A5C0(64) && v21 < 1)
    {
        v24 = loadString_sub_40F1D0((char*)& byte_587000[196700], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 806);
        goto LABEL_61;
    }
    if (sub_417DA0(4) || sub_40A5C0(0x8000))
        sub_417D00();
    for (l = sub_57C3E0(); l; l = sub_57C3F0(l))
    {
        if (!strcmp((const char*)l, "spring"))
        {
            v27 = strtok((char*)(l + 80), " ");
            v28 = atoi(v27);
            v29 = sub_4ED020(v28);
            v30 = strtok(0, " ");
            v31 = atoi(v30);
            v32 = sub_4ED020(v31);
            if (v29 && v32)
                sub_511590(v29, v32);
        }
        else if (!strcmp((const char*)l, "SentryGlobe"))
        {
            v33 = strtok((char*)(l + 80), " ");
            v34 = atoi(v33);
            v35 = sub_4ED020(v34);
            if (v35)
            {
                v36 = *(float**)(v35 + 748);
                v37 = strtok(0, " ");
                v38 = atof(v37) * *(double*)& byte_581450[10008];
                v36[1] = v38;
                *v36 = v38;
                v39 = strtok(0, " ");
                v40 = atof(v39);
                v62 = *(unsigned int*)& byte_5D4594[2649704];
                v36[2] = v40 * *(double*)& byte_581450[10000] / (double) * (unsigned int*)& byte_5D4594[2649704];
            }
        }
    }
    *(_DWORD*)& byte_5D4594[1548524] = 0;
    v41 = sub_409B40();
    sub_500510(v41);
    if (!sub_4DB240())
        sub_4FC570(1);
    sub_40A4D0(0x8000000);
    sub_43F140(500);
    v42 = sub_4DB240();
    sub_4DBA30(v42);
    sub_43F1A0();
    sub_40A540(0x8000000);
    sub_4FC580(1);
    if (*(_DWORD*)& byte_5D4594[1548664])
    {
        v43 = sub_579E30((const char*)& byte_5D4594[1548536]);
        if (v43)
        {
            v44 = sub_4DA7C0();
            if (v44)
            {
                v45 = (float2*)(v43 + 8);
                do
                {
                    sub_4E7010(v44, v45);
                    v44 = sub_4DA7F0(v44);
                } while (v44);
            }
        }
    }
    *(_DWORD*)& byte_5D4594[1548664] = 0;
    if (sub_4DCC00() == 1)
    {
        for (m = sub_4DA7C0(); m; m = sub_4DA7F0(m))
        {
            for (n = *(_DWORD*)(m + 516); n; n = *(_DWORD*)(n + 512))
            {
                if (sub_4E5B50(n))
                {
                    v48 = *(_DWORD*)(n + 748);
                    sub_4ED970(50.0, (float2*)(m + 56), &v61);
                    sub_4E7010(n, &v61);
                    *(_DWORD*)(v48 + 388) = 0;
                    sub_50A3A0(n);
                    *(_DWORD*)(n + 520) = 0;
                    *(_DWORD*)(v48 + 1196) = 0;
                    *(_DWORD*)(v48 + 1216) = 0;
                    *(_BYTE*)(v48 + 1129) = 0;
                    *(_DWORD*)v48 = -559023410;
                    v49 = sub_50A260(n, 3);
                    if (v49)
                    {
                        v49[1] = *(_DWORD*)(m + 56);
                        v49[2] = *(_DWORD*)(m + 60);
                        v49[3] = m;
                    }
                    if (*(_BYTE*)(n + 8) & 2 && *(_BYTE*)(n + 12) & 0x30)
                        sub_4E4A90(n, 0, *(_DWORD*)(n + 748) + 2076);
                }
                else if (*(_BYTE*)(m + 8) & 1 && sub_4E5B80(m))
                {
                    sub_4E81D0(m);
                }
            }
        }
        sub_4DCBF0(0);
    }
    for (ii = sub_4DA790(); ii; ii = sub_4DA7A0(ii))
        * (_DWORD*)(ii + 16) &= 0x7FFFFFFFu;
    for (jj = sub_4DA840(); jj; jj = sub_4DA850(jj))
        * (_DWORD*)(jj + 16) &= 0x7FFFFFFFu;
    if (sub_40A5C0(16) && sub_417DA0(4))
        sub_4D2160();
    if (sub_40A5C0(4096))
    {
        sub_51A930();
        v52 = sub_415FA0(0, 2);
        sub_51A920(v52);
        v53 = sub_4E3CC0();
        sub_4E3CD0(v53 + 1);
        v54 = sub_51A930();
        sub_51A1F0(v54);
        sub_4E3D50();
        sub_4E3DD0();
        sub_4F1F20();
        v55 = sub_409B30();
        sub_4D10F0(v55);
        sub_4D7520(1);
        v56 = (__int64)sub_419D40(&byte_587000[196800]);
        if (sub_4E3CC0() >= v56)
            sub_4D7520(0);
    }
    if (sub_40A5C0(2048) && !sub_4DCC80())
    {
        sub_4DB130("AUTOSAVE");
        sub_4DB170(1, 0, 30);
    }
    sub_4DCC70(0);
    if (sub_40A5C0(2048))
        sub_413980(30);
    if (sub_40A5C0(4096))
        sub_4D7140(*(_DWORD*)& byte_5D4594[2598000] + *(_DWORD*)& byte_5D4594[2649704]);
    else
        sub_4D7140(0);
    sub_416D40();
    sub_40A970();
    *(_DWORD*)& byte_5D4594[1548704] = 0;
    if (sub_40A5C0(4096))
    {
        sub_4D71E0(0);
        if (sub_4D72C0() == 1)
        {
            sub_4D72B0(0);
            v57 = sub_4D72C0();
            sub_4D7280(255, v57);
        }
    }
    sub_413850();
    return 1;
}
// 4D1A17: variable 'v11' is possibly undefined
// 4D1CBA: variable 'v25' is possibly undefined

//----- (004D2580) --------------------------------------------------------
int sub_4D2580_server()
{
    __int64 v0; // rax
    unsigned int v1; // edi
    int v2; // ebx
    unsigned int v3; // ebp
    unsigned int v4; // esi
    _DWORD* i; // esi
    char* v7; // ebp
    char* v8; // edi
    unsigned __int8 v9; // dl
    char* v10; // edi
    char* v11; // esi
    char* v12; // eax
    int v13; // esi
    wchar_t* v14; // eax
    wchar_t* v15; // eax
    char* v17; // eax
    int v18; // eax
    char* v20; // eax
    char* v21; // esi
    int v22; // ebx
    int v23; // ebp
    int v24; // edi
    int v25; // esi
    unsigned __int8* v26; // eax
    wchar_t* v27; // eax
    int v28; // eax
    int v29; // esi
    char* v30; // ebp
    const char* v31; // edi
    char* v33; // eax
    int v34; // eax
    wchar_t* v35; // [esp-10h] [ebp-50h]
    wchar_t* v36; // [esp-8h] [ebp-48h]
    char* v37; // [esp-4h] [ebp-44h]
    char v38[16]; // [esp+10h] [ebp-30h]
    char v39[32]; // [esp+20h] [ebp-20h]

    v0 = sub_416BB0();
    v1 = v0;
    v2 = 0;
    v3 = HIDWORD(v0);
    if (!*(_DWORD*)& byte_5D4594[2650652])
        goto LABEL_115;
    v4 = sub_40A6C0();
    if (sub_416650() && sub_41E2F0() == 8)
        v2 = 1;
    if (v4 == 1 || sub_40A5C0(8) || *(_DWORD*)& byte_5D4594[2598000] % v4 == 1)
        LABEL_115:
        sub_40EE90(1);
    sub_502100();
    sub_5524C0();
    sub_552460();
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x400000)
        sub_4D3580(1);
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x20000000)
    {
        *(_DWORD*)& v38[4] = (__PAIR64__(v3, v1) - *(_QWORD*)& byte_5D4594[1548684]) >> 32;
        if (__PAIR64__(v3, v1) - *(_QWORD*)& byte_5D4594[1548684] > 0x3E8)
        {
            sub_4D3130();
            *(_DWORD*)& byte_5D4594[1548684] = v1;
            *(_DWORD*)& byte_5D4594[1548688] = v3;
        }
    }
    if (!sub_40A5C0(2048))
        sub_578FC0();
    if (sub_40A5C0(8))
    {
        if (!*(_QWORD*)& byte_5D4594[1548676])
        {
            *(_QWORD*)& byte_5D4594[1548676] = sub_416BB0() + 10000;
            sub_4597E0(0);
            if (sub_43AF70() == 1)
            {
                if (!sub_40A5C0(128))
                {
                    sub_4263C0();
                    sub_40DF90();
                    sub_4264D0();
                }
                if (!sub_4165B0()[57])
                    sub_41D650();
            }
            sub_413D30((char*)& byte_587000[196872]);
            sub_46DCB0();
        }
        sub_4DEB30();
        sub_4DEB50();
        if ((unsigned __int64)sub_416BB0() > * (_QWORD*)& byte_5D4594[1548676] && !v2)
        {
            *(_DWORD*)& byte_5D4594[1548676] = 0;
            *(_DWORD*)& byte_5D4594[1548680] = 0;
            *(_DWORD*)& byte_5D4594[1548524] = 1;
            sub_416170(12);
            sub_40A540(8);
            for (i = (_DWORD*)sub_4DA7C0(); i; i = (_DWORD*)sub_4DA7F0((int)i))
            {
                sub_4EDA40(i);
                sub_4EF7D0((int)i, 1, 0);
            }
            sub_4DAC00();
            if (!sub_40A5C0(512))
            {
                v7 = sub_416590(0);
                if (v7[57])
                {
                    v38[0] = 0;
                    *(_DWORD*)& v38[1] = 0;
                    *(_DWORD*)& v38[5] = 0;
                    *(_DWORD*)& v38[9] = 0;
                    v8 = sub_409B80();
                    v9 = byte_587000[196884];
                    strcpy(v38, v8);
                    v10 = &v38[strlen(v38)];
                    *(_DWORD*)v10 = *(_DWORD*)& byte_587000[196880];
                    v10[4] = v9;
                    sub_409D70(v38);
                    v7[57] = 0;
                }
                else if (sub_4D0D70())
                {
                    sub_4D0A30();
                    v11 = sub_4D0CF0();
                    if (v11)
                    {
                        v12 = sub_409B30();
                        if (!_strcmpi(v11, v12))
                            v11 = sub_4D0CF0();
                        if (v11)
                            sub_409D70(v11);
                    }
                }
            }
        }
        goto LABEL_72;
    }
    if (*(_DWORD*)& byte_5D4594[1548524])
    {
        if (!sub_43AF70() || !v2)
        {
            sub_4EDD70();
            sub_417160();
            sub_4573B0();
            if (sub_417DA0(2) && !sub_40A5C0(49152) && sub_417DA0(4) && !sub_40A5C0(128))
                sub_4181F0(1);
            if (sub_40A5C0(4096) && sub_43AF70() == 1 && !sub_40A5C0(128))
                sub_4264D0();
            sub_40A4D0(0x8000000);
            sub_43F140(500);
            v13 = sub_4D1860_server();
            sub_43F1A0();
            sub_40A540(0x8000000);
            if (!v13)
            {
                v37 = sub_409B40();
                v14 = loadString_sub_40F1D0((char*)& byte_587000[196928], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1702);
                sub_4D9FD0(0, v14, v37);
                v36 = loadString_sub_40F1D0((char*)& byte_587000[196984], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1703);
                v15 = loadString_sub_40F1D0((char*)& byte_587000[197032], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1703);
                nullsub_4(0, v15, v36, 1);
                sub_43DDD0(0);
                return 0;
            }
            v17 = sub_409B40();
            nox_sprintf(v39, "%s.map", v17);
            v18 = sub_409B00();
            sub_4DEE00(v39, v18);
            if (sub_43AF70() == 1)
            {
                sub_416690();
                if (sub_40A5C0(128))
                {
                    if (sub_40A5C0(0x8000))
                        sub_419030(1);
                    sub_40A540(49152);
                    sub_4597E0(0);
                    goto LABEL_72;
                }
                sub_426060();
                sub_41D6C0();
                sub_4160D0(15);
            }
            sub_4597E0(0);
        }
        LABEL_72:
        if (*(_DWORD*)& byte_5D4594[2650636] & 0x600000)
            sub_4E76C0();
        if (sub_4DB1B0())
        {
            v20 = sub_417090(31);
            v21 = v20;
            if (v20)
            {
                if (*((_DWORD*)v20 + 514) && sub_4DCC10(*((_DWORD*)v20 + 514)) == 1)
                {
                    v22 = *((_DWORD*)v21 + 514);
                    v23 = 0;
                    v24 = (*(_DWORD*)(v22 + 16) >> 15) & 1;
                    if (!v24)
                    {
                        if (*(_DWORD*)& byte_5D4594[1599640] > 0)
                        {
                            v25 = 0;
                            do
                            {
                                if (!strncmp(
                                        "MapShutdown",
                                        *(const char**)(v25 + *(_DWORD*)& byte_5D4594[1599636]),
                                        0xBu))
                                    sub_507310(v23, 0, 0);
                                ++v23;
                                v25 += 48;
                            } while (v23 < *(int*)& byte_5D4594[1599640]);
                        }
                        sub_40A4D0(0x8000000);
                        v26 = sub_4DB160();
                        v23 = sub_4DB370((const char*)v26);
                        sub_40A540(0x8000000);
                        if (!v23 && sub_40A5C0(2))
                        {
                            v35 = loadString_sub_40F1D0((char*)& byte_587000[197104], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1931);
                            v27 = loadString_sub_40F1D0((char*)& byte_587000[197172], 0, "C:\\NoxPost\\src\\Server\\System\\server.c", 1930);
                            sub_449A10(0, (int)v27, (int)v35, 33, 0, 0);
                        }
                    }
                    v28 = sub_4DB1C0();
                    v29 = v28;
                    if (v24 || v23 != 1)
                    {
                        if (v28 && !v23)
                            sub_4E7010(v22, (float2*)(*(_DWORD*)(v28 + 700) + 80));
                    }
                    else if (v28)
                    {
                        v30 = *(char**)(v28 + 700);
                        v31 = (const char*)sub_4DB2A0(*(const char**)(v28 + 700));
                        if (v31)
                        {
                            sub_4DB220(1);
                            sub_4DB230(1);
                            sub_4DB270(v31);
                        }
                        sub_4D2450(v30);
                    }
                    sub_4DB170(0, v29, 0);
                }
            }
        }
        sub_4139C0();
        if (sub_446180())
            sub_446190();
        if (sub_446030()
            && *(_DWORD*)& byte_5D4594[2598000] > (unsigned int)(5 * *(_DWORD*)& byte_5D4594[2649704] + sub_446040()))
        {
            sub_446380();
        }
        if (!sub_413A50())
            ++* (_DWORD*)& byte_5D4594[2598000];
        sub_56F5C0();
        sub_4FC6D0();
        sub_4FC590();
        sub_4FC600();
        sub_4FC680();
        v33 = sub_417090(31);
        if (v33)
        {
            v34 = *((_DWORD*)v33 + 514);
            if (v34)
                sub_5003B0(v34);
        }
        if (sub_57AF20() && sub_57B140())
            sub_57B0A0();
        if (sub_4D6F50())
        {
            sub_4D6FD0();
            sub_4DCF20();
        }
        return 1;
    }
    sub_4D2DA0(__SPAIR64__(v3, v1));
    sub_4DEB30();
    sub_4DEB50();
    if (!sub_43DEA0())
    {
        if (!(byte_5D4594[2598000] & 1))
            sub_519990();
        sub_40B970();
        sub_40B790();
        if (!sub_413A50())
        {
            sub_51B100();
            sub_4EC720();
            if (sub_40A5C0(4096))
            {
                sub_50D890();
                sub_4E4170();
            }
            sub_4FCB70();
            sub_4FBEE0();
            sub_51ADF0();
            sub_506F30();
            sub_4E5E20();
        }
        sub_4DEC80();
        sub_4DAC00();
        if (sub_4160F0(0x10u, 10 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            sub_4E3C20();
            sub_4160D0(16);
        }
        if (sub_40A5C0(0x2000)
            && sub_43AF70() == 1
            && !sub_40A5C0(128)
            && sub_4160F0(0xFu, 60 * *(_DWORD*)& byte_5D4594[2649704]))
        {
            sub_4263C0();
            sub_4160D0(15);
        }
        goto LABEL_72;
    }
    return 1;
}
// 4D26F3: variable 'v5' is possibly undefined
// 4D2A52: variable 'v19' is possibly undefined
// 4D2CEB: variable 'v32' is possibly undefined
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);
// 46DCB0: using guessed type int sub_46DCB0(void);