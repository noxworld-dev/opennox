#include "speltree.h"

#include "../../proto.h"

//----- (00424460) --------------------------------------------------------
int __cdecl sub_424460(int a1, void* a2)
{
    unsigned __int8* v2; // eax
    int v3; // ebx
    int v4; // eax
    int result; // eax
    unsigned __int8* v6; // ebp
    _WORD* v7; // ecx
    unsigned __int8* v8; // edi
    unsigned __int8 v9; // dl
    int* v10; // edi
    unsigned __int8* v11; // edx
    unsigned __int8 v12; // cl
    int** v13; // edi
    int* v14; // eax
    int* v15; // eax
    int v16; // edi
    char* v17; // eax
    char v18; // cl
    int* v19; // eax
    int v20; // edi
    char* v21; // eax
    char v22; // cl
    int* v23; // eax
    int v24; // ecx
    unsigned __int8* v25; // eax
    __int16* v26; // eax
    int v27; // edi
    unsigned __int8* v28; // eax
    unsigned __int8 v29; // cl
    int v30; // edi
    unsigned __int8* v31; // eax
    unsigned __int8* v32; // eax
    unsigned __int8 v33; // [esp+10h] [ebp-138h]
    unsigned __int8 v34; // [esp+10h] [ebp-138h]
    unsigned __int8 v35; // [esp+10h] [ebp-138h]
    unsigned __int8 v36; // [esp+10h] [ebp-138h]
    unsigned __int8 v37; // [esp+10h] [ebp-138h]
    unsigned __int8 v38; // [esp+10h] [ebp-138h]
    const char* v39; // [esp+14h] [ebp-134h]
    unsigned __int8 v40; // [esp+1Ch] [ebp-12Ch]
    int v41; // [esp+20h] [ebp-128h]
    int v42; // [esp+24h] [ebp-124h]
    char v43[256]; // [esp+28h] [ebp-120h]
    char v44[32]; // [esp+128h] [ebp-20h]

    v2 = *(unsigned __int8**)(a1 + 8);
    v33 = *v2;
    *(_DWORD*)(a1 + 8) = v2 + 1;
    nox_memfile_read(a2, 1u, v33, a1);
    v3 = 0;
    *((_BYTE*)a2 + v33) = 0;
    v4 = sub_4243F0((const char*)a2);
    v41 = v4;
    if (!v4)
        return 0;
    v6 = &byte_5D4594[80 * v4 + 588124];
    v40 = 0;
    v39 = 0;
    v6[62] = **(_BYTE * *)(a1 + 8);
    v7 = (_WORD*)(*(_DWORD*)(a1 + 8) + 1);
    *(_DWORD*)(a1 + 8) = v7;
    *((_WORD*)v6 + 32) = *v7;
    v8 = (unsigned __int8*)(*(_DWORD*)(a1 + 8) + 2);
    *(_DWORD*)(a1 + 8) = v8;
    v9 = *v8;
    *(_DWORD*)(a1 + 8) = v8 + 1;
    v6[61] = v9;
    v10 = *(int**)& byte_587000[66120];
    v42 = v9;
    if ((int)v9 > 0)
    {
        do
        {
            v11 = *(unsigned __int8**)(a1 + 8);
            v12 = *v11;
            *(_DWORD*)(a1 + 8) = v11 + 1;
            if (v12 >= 9u)
                return 0;
            v44[v40++] = v12;
            v13 = (int**)& v10[v12 + 1];
            if (*v13)
            {
                v10 = *v13;
            }
            else
            {
                v14 = (int*)nox_calloc(1u, 0x28u);
                *v13 = v14;
                if (!v14)
                    return 0;
                *v14 = 0;
                v10 = *v13;
                v4 = v41;
            }
        } while ((int)++v39 < v42);
    }
    *v10 = v4;
    v15 = *(int**)(a1 + 8);
    v16 = *v15;
    *(_DWORD*)(a1 + 8) = v15 + 1;
    *((_DWORD*)v6 + 2) = 0;
    v43[0] = byte_5D4594[599124];
    if (v16 == -1)
    {
        v17 = *(char**)(a1 + 8);
        v18 = *v17++;
        *(_DWORD*)(a1 + 8) = v17;
        LOBYTE(v39) = v18;
        v34 = *v17;
        *(_DWORD*)(a1 + 8) = v17 + 1;
        nox_memfile_read(v43, 1u, v34, a1);
        v43[v34] = 0;
        v16 = -1;
    }
    if (nox_common_mapflags_check(2))
        * ((_DWORD*)v6 + 2) = sub_42FAA0(v16, v39, v43);
    v19 = *(int**)(a1 + 8);
    v20 = *v19;
    *(_DWORD*)(a1 + 8) = v19 + 1;
    *((_DWORD*)v6 + 3) = 0;
    v43[0] = byte_5D4594[599128];
    if (v20 == -1)
    {
        v21 = *(char**)(a1 + 8);
        v22 = *v21++;
        *(_DWORD*)(a1 + 8) = v21;
        LOBYTE(v39) = v22;
        v35 = *v21;
        *(_DWORD*)(a1 + 8) = v21 + 1;
        nox_memfile_read(v43, 1u, v35, a1);
        v43[v35] = 0;
        v20 = -1;
    }
    if (nox_common_mapflags_check(2))
        * ((_DWORD*)v6 + 3) = sub_42FAA0(v20, v39, v43);
    v23 = *(int**)(a1 + 8);
    v24 = *v23;
    *(_DWORD*)(a1 + 8) = v23 + 1;
    *((_DWORD*)v6 + 4) = v24;
    v25 = *(unsigned __int8**)(a1 + 8);
    v36 = *v25;
    *(_DWORD*)(a1 + 8) = v25 + 1;
    nox_memfile_read(v43, 1u, v36, a1);
    v43[v36] = 0;
    *(_DWORD*)v6 = loadString_sub_40F1D0(v43, 0, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c", 481);
    v26 = *(__int16**)(a1 + 8);
    v27 = *v26;
    *(_DWORD*)(a1 + 8) = v26 + 1;
    nox_memfile_read(v43, 1u, v27, a1);
    v43[v27] = 0;
    *((_DWORD*)v6 + 1) = loadString_sub_40F1D0(v43, 0, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c", 488);
    v28 = *(unsigned __int8**)(a1 + 8);
    v29 = *v28;
    *(_DWORD*)(a1 + 8) = v28 + 1;
    v30 = v29;
    nox_memfile_read(v43, 1u, v29, a1);
    v43[v30] = 0;
    *((_DWORD*)v6 + 17) = sub_40AF50(v43);
    v31 = *(unsigned __int8**)(a1 + 8);
    v37 = *v31;
    *(_DWORD*)(a1 + 8) = v31 + 1;
    nox_memfile_read(v43, 1u, v37, a1);
    v43[v37] = 0;
    *((_DWORD*)v6 + 18) = sub_40AF50(v43);
    v32 = *(unsigned __int8**)(a1 + 8);
    v38 = *v32;
    *(_DWORD*)(a1 + 8) = v32 + 1;
    nox_memfile_read(v43, 1u, v38, a1);
    v43[v38] = 0;
    *((_DWORD*)v6 + 19) = sub_40AF50(v43);
    if ((int)v40 > 0)
    {
        qmemcpy(v6 + 28, v44, v40);
        v3 = v40;
    }
    result = 1;
    v6[v3 + 28] = 4;
    *((_DWORD*)v6 + 5) = 1;
    *((_DWORD*)v6 + 6) = 1;
    return result;
}
