#include "light16.h"

#include "../io/win95/dxvideo.h"
#include "../../proto.h"

extern int nox_win_width;
extern int nox_win_height;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

//----- (00485880) --------------------------------------------------------
signed int __cdecl sub_485880(_DWORD* a1, int* a2, int a3, signed int a4, char* a5)
{
	signed int result; // eax
	int v6; // esi
	int v7; // edi
	const void* v8; // edx
	char* v9; // esi
	int v10; // eax
	void* v11; // edi
	int v12; // ecx
	int v13; // ebx
	int v14; // edx
	int v15; // ebp
	int v16; // eax
	int v17; // esi
	int v18; // esi
	int v19; // ecx
	unsigned int v20; // [esp+10h] [ebp-Ch]
	int v21; // [esp+14h] [ebp-8h]
	int v22; // [esp+18h] [ebp-4h]
	signed int v23; // [esp+20h] [ebp+4h]

	result = *(_DWORD*)& byte_5D4594[3798820];
	v6 = a1[1] - *(_DWORD*)& byte_5D4594[3798824];
	v7 = *a1 - *(_DWORD*)& byte_5D4594[3798820];
	if (v7 >= 0 && v6 >= 0 && v7 < *(int*)& byte_5D4594[3798800] && v6 < *(int*)& byte_5D4594[3798808])
	{
		v8 = *(const void**)& byte_5D4594[3798796];
		result = *(_DWORD*)& byte_5D4594[3798844];
		v9 = (char*)(v7
		             + *(_DWORD*)& byte_5D4594[3798796]
		             + *(_DWORD*)& byte_5D4594[3798836]
		             + *(_DWORD*)& byte_5D4594[3798804] * (*(_DWORD*)& byte_5D4594[3798840] + v6));
		v21 = *(_DWORD*)& byte_5D4594[3798796];
		v20 = *(_DWORD*)& byte_5D4594[3798844];
		v22 = *(_DWORD*)& byte_5D4594[3798844] - *(_DWORD*)& byte_5D4594[3798796];
		*(_DWORD*)& byte_5D4594[1193184] = v9;
		*(_DWORD*)& byte_5D4594[1193180] = a5;
		if ((unsigned int)v9 >= *(int*)& byte_5D4594[3798844])
		{
			v9 -= *(_DWORD*)& byte_5D4594[3798844] - *(_DWORD*)& byte_5D4594[3798796];
			*(_DWORD*)& byte_5D4594[1193184] = v9;
		}
		if (byte_5D4594[2650637] & 8)
		{
			if ((unsigned int)& v9[a4] < *(int*)& byte_5D4594[3798844])
			{
				qmemcpy(a5, v9, a4);
			}
			else
			{
				v10 = *(_DWORD*)& byte_5D4594[3798844] - (_DWORD)v9;
				qmemcpy(a5, v9, *(_DWORD*)& byte_5D4594[3798844] - (_DWORD)v9);
				v11 = (void*)(*(_DWORD*)& byte_5D4594[1193180] + v10);
				result = a4 - v10;
				qmemcpy(v11, v8, result);
			}
		}
		else
		{
			v12 = *a1 - 23 * *a2 - *(_DWORD*)& byte_5D4594[2650676];
			v13 = 12 * a3;
			v14 = *(_DWORD*)& byte_5D4594[280 * *a2 + 2598288 + 12 * a3];
			*(_DWORD*)& byte_5D4594[1193176] = v14;
			v15 = *(_DWORD*)& byte_5D4594[4 * ((*(int*)& byte_5D4594[280 * *a2 + 2598568 + 12 * a3] - v14) >> 8) + 2615304];
			if (v12 <= 0)
			{
				v23 = 23;
				v16 = 23;
			}
			else
			{
				v16 = 23 - v12;
				*(_DWORD*)& byte_5D4594[1193176] = v12 * v15 + v14;
				v23 = 23 - v12;
			}
			if (v16 <= a4)
				goto LABEL_18;
			v23 = a4;
			while (1)
			{
				v16 = v23;
				LABEL_18:
				if ((unsigned int)& v9[v16] <= v20)
				{
					sub_485AE0(v16, v15);
				}
				else
				{
					v17 = (int)& v9[v16 - v20];
					sub_485AE0(v17, v15);
					*(_DWORD*)& byte_5D4594[1193184] = v21;
					sub_485AE0(v23 - v17, v15);
				}
				if (*(int*)& byte_5D4594[1193184] >= v20)
					* (_DWORD*)& byte_5D4594[1193184] -= v22;
				result = a4 - v23;
				a4 -= v23;
				if (a4 <= 0)
					break;
				v23 = 23;
				if (result < 23)
					v23 = result;
				v18 = *a2 + 1;
				v19 = v18;
				*a2 = v18;
				v9 = *(char**)& byte_5D4594[1193184];
				*(_DWORD*)& byte_5D4594[1193176] = *(_DWORD*)& byte_5D4594[280 * v19 + 2598288 + v13];
				v15 = *(_DWORD*)& byte_5D4594[4
				                              * ((*(int*)& byte_5D4594[280 * *a2 + 2598568 + v13]
				                                  - *(int*)& byte_5D4594[1193176]) >> 8)
				                              + 2615304];
			}
		}
	}
	return result;
}

//----- (00481470) --------------------------------------------------------
int __cdecl sub_481470(int2* a1)
{
	unsigned __int16 v1; // dx
	int v2; // eax
	int v3; // esi
	int v4; // ebx
	int v5; // ecx
	int result;

	LOBYTE(v1) = 0;
	v2 = a1->field_4 + 45 * a1->field_0;
	HIBYTE(v1) = byte_5D4594[v2 + 2616332];
	v3 = v1;
	v4 = *(_DWORD*)& byte_5D4594[4 * (((byte_5D4594[v2 + 2616333] << 8) - v1) >> 8) + 2615304];
	v5 = 0;
	do
	{
		v5 += 12;
		*(_DWORD*)& byte_5D4594[280 * a1->field_0 + 2598276 + v5] = v3;
		v3 += v4;
	} while (v5 < 276);
	result = 35 * a1->field_0;
	*(_DWORD*)& byte_5D4594[280 * a1->field_0 + 2598284] = a1->field_4;
	return result;
}

//----- (00484F90) --------------------------------------------------------
void __cdecl sub_484F90(int a1)
{
	int v1; // ebx
	int v2; // eax
	double v3; // st7
	int v4; // ecx
	int v5; // edx
	int v6; // eax
	int v7; // ecx
	int v8; // ebp
	int v9; // edi
	int v10; // esi
	int v11; // eax
	int v12; // ecx
	int v13; // edx
	int v14; // esi
	double v15; // st7
	unsigned __int8* v16; // ebp
	int v17; // edi
	double v18; // st6
	double v19; // st5
	double v20; // st6
	double v21; // st6
	int v22; // edi
	int v23; // esi
	int v24; // eax
	int v25; // ebp
	int v26; // eax
	int v27; // ebx
	float v28; // [esp+0h] [ebp-50h]
	float v29; // [esp+0h] [ebp-50h]
	float v30; // [esp+0h] [ebp-50h]
	float v31; // [esp+0h] [ebp-50h]
	float a5; // [esp+14h] [ebp-3Ch]
	int a5a; // [esp+14h] [ebp-3Ch]
	int v34; // [esp+18h] [ebp-38h]
	int2 v35; // [esp+1Ch] [ebp-34h]
	int2 a3; // [esp+24h] [ebp-2Ch]
	float v37; // [esp+2Ch] [ebp-24h]
	float v38; // [esp+30h] [ebp-20h]
	float v39; // [esp+34h] [ebp-1Ch]
	int2 a1a; // [esp+38h] [ebp-18h]
	int a4; // [esp+40h] [ebp-10h]
	int v42; // [esp+44h] [ebp-Ch]
	int2 a2; // [esp+48h] [ebp-8h]
	int v44; // [esp+54h] [ebp+4h]
	int v45; // [esp+54h] [ebp+4h]

	v1 = a1;
	if (sub_45A840((_DWORD*)a1)
	    || *(_DWORD*)(a1 + 112) & 0x80000
	       && (v2 = *(_DWORD*)(a1 + 120), v2 & 0x1000000)
	       && v2 & 4
	       && *(_DWORD*)(a1 + 144) > 0)
	{
		if (!sub_57AF20()
		    || a1 == *(_DWORD*)& byte_5D4594[2614252]
		    || *(int(__cdecl * *)(int*, int))(a1 + 300) == nox_thing_glow_orb_draw)
		{
			if (*(_DWORD*)(a1 + 120) & 0x20000000 && *(_DWORD*)& byte_5D4594[3801780] == 1)
			{
				a5 = sub_416090(0.89999998, 1.1) * *(float*)(a1 + 140);
				v3 = (double)sub_484C60(a5);
			}
			else
			{
				v3 = (double) * (int*)(a1 + 144);
				a5 = *(float*)(a1 + 140);
			}
			*(float*)& v44 = v3;
			if (a5 > (double) * (float*)& byte_587000[154968])
			{
				if (a5 <= 31.0)
					v37 = a5;
				else
					v37 = 31.0;
				v4 = *(_DWORD*)(v1 + 16);
				v5 = *(_DWORD*)(v1 + 168);
				v6 = *(_DWORD*)(v1 + 12) - *(_DWORD*)& byte_5D4594[2650676];
				v39 = a5 * a5;
				v7 = v4 - *(_DWORD*)& byte_5D4594[2650680];
				a4 = v6;
				v42 = v7;
				if (v5 == 0xFFFF)
				{
					v38 = *(float*)& v44 * *(float*)& v44;
					v28 = ((double)a4 - *(float*)& v44) * 0.043478262 + 0.5;
					v8 = nox_float2int(v28);
					a5a = v8;
					if (v8 < 0)
					{
						a5a = 0;
						v8 = 0;
					}
					v29 = ((double)a4 + *(float*)& v44) * 0.043478262 + 0.5;
					v9 = nox_float2int(v29);
					v34 = v9;
					if (v9 > 56)
					{
						v34 = 56;
						v9 = 56;
					}
					v30 = ((double)v42 - *(float*)& v44) * 0.043478262 + 0.5;
					v10 = nox_float2int(v30);
					if (v10 < 0)
						v10 = 0;
					v31 = ((double)v42 + *(float*)& v44) * 0.043478262 + 0.5;
					v11 = nox_float2int(v31);
					v35.field_0 = v11;
					if (v11 > 44)
					{
						v35.field_0 = 44;
						v11 = 44;
					}
					a3.field_0 = v10;
					v12 = 23 * v10;
					a2.field_4 = 23 * v10;
					if (v10 <= v11)
					{
						v13 = 23 * v8;
						a1a.field_0 = 23 * v8;
						do
						{
							if (v8 <= v9)
							{
								v14 = a4 - v13;
								v45 = a4 - v13;
								v15 = (double)(v42 - v12) * (double)(v42 - v12);
								v16 = &byte_5D4594[40 * v8 + 2616332 + 5 * v8 + a3.field_0];
								v17 = v9 - a5a + 1;
								do
								{
									v18 = (double)v45 * (double)v45 + v15;
									if (v18 <= v38)
									{
										v19 = (*(float*)& byte_587000[154996] + v37)
										      / (*(float*)& byte_587000[154992] * *(float*)& byte_587000[154972] * v18 / v39 + 1.0);
										if (v19 > * (float*)& byte_587000[154996])
										{
											v20 = v19 - *(float*)& byte_587000[154996];
											if (*(_DWORD*)(v1 + 172))
												v21 = (double)* v16 - v20;
											else
												v21 = v20 + (double)* v16;
											if (v21 >= 0.0)
											{
												if (v21 > 31.0)
													v21 = 31.0;
											}
											else
											{
												v21 = 0.0;
											}
											v12 = a2.field_4;
											v13 = a1a.field_0;
											v14 -= 23;
											*v16 = (__int64)v21;
											v45 = v14;
										}
										else
										{
											v14 -= 23;
											v45 = v14;
										}
									}
									else
									{
										v14 -= 23;
										v45 = v14;
									}
									v16 += 45;
									--v17;
								} while (v17);
								v8 = a5a;
								v9 = v34;
								v11 = v35.field_0;
							}
							v12 += 23;
							a2.field_4 = v12;
							++a3.field_0;
						} while (a3.field_0 <= v11);
					}
				}
				else
				{
					a1a.field_0 = (v6 << 16) / 23;
					a1a.field_4 = (v7 << 16) / 23;
					v22 = (int)((__int64) * (float*)& v44 << 16) / 23;
					v23 = sub_4C1C60(
							v22,
							16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(*(_WORD*)(v1 + 164) + 0x4000) >> 4) + 2661964]);
					v24 = sub_4C1C60(v22, 16 * *(_DWORD*)& byte_5D4594[4 * (*(unsigned __int16*)(v1 + 164) >> 4) + 2661964]);
					a3.field_0 = a1a.field_0 + v23;
					LOWORD(v23) = *(_WORD*)(v1 + 164) + *(_WORD*)(v1 + 166);
					a3.field_4 = a1a.field_4 + v24;
					v25 = sub_4C1C60(v22, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v23 + 0x4000) >> 4) + 2661964]);
					v26 = sub_4C1C60(v22, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)v23 >> 4) + 2661964]);
					LOWORD(v23) = *(_WORD*)(v1 + 164) - *(_WORD*)(v1 + 166);
					a2.field_4 = a1a.field_4 + v26;
					a2.field_0 = a1a.field_0 + v25;
					v27 = sub_4C1C60(v22, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v23 + 0x4000) >> 4) + 2661964]);
					v35.field_4 = a1a.field_4
					              + sub_4C1C60(v22, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)v23 >> 4) + 2661964]);
					v35.field_0 = a1a.field_0 + v27;
					sub_4854D0(&a1a, &a2, &a3, (int)& a4, a5);
					sub_4854D0(&a1a, &a3, &v35, (int)& a4, a5);
				}
			}
		}
	}
}

//----- (00484E60) --------------------------------------------------------
void __cdecl sub_484E60(int a1)
{
	_DWORD* v1; // esi
	unsigned __int8 v2; // al
	int v3; // edx
	int v4; // eax
	int v5; // eax
	int v6; // ecx
	int v7; // edx
	int v8; // [esp+8h] [ebp-18h]
	int v9; // [esp+Ch] [ebp-14h]
	int4 v10; // [esp+10h] [ebp-10h]

	v1 = (_DWORD*)a1;
	*(_DWORD*)& byte_5D4594[2650676] = 46 * ((*(_DWORD*)(a1 + 16) + 11) / 46 - 1) - 11;
	*(_DWORD*)& byte_5D4594[2650680] = 46 * ((*(_DWORD*)(a1 + 20) + 11) / 46) - 57;
	if (byte_5D4594[2650637] & 8)
	{
		memset(&byte_5D4594[2616332], 0x1Fu, 0xA04u);
		byte_5D4594[2618896] = 31;
	}
	else
	{
		if (sub_57AF20())
		{
			v8 = 50;
			a1 = 50;
			v9 = 50;
		}
		else
		{
			sub_434A10(&v9, &v8, &a1);
		}
		v2 = sub_434AA0(v9, v8, a1);
		LOBYTE(v3) = v2 >> 3;
		BYTE1(v3) = v2 >> 3;
		v4 = v3 << 16;
		LOWORD(v4) = v3;
		memset32(&byte_5D4594[2616332], v4, 0x281u);
		byte_5D4594[2618896] = v3;
		v5 = v1[4];
		v10.field_0 = v5 - 100;
		v6 = v1[5];
		v10.field_4 = v6 - 100;
		v7 = v1[9];
		v10.field_8 = v1[8] + v5 + 100;
		v10.field_C = v7 + v6 + 100;
		sub_49AB00(&v10, (void(__cdecl*)(int, int))sub_484F90, (int)v1);
	}
}

//----- (00485740) --------------------------------------------------------
char* __cdecl sub_485740(_DWORD* a1)
{
	int v1; // ecx
	int v2; // esi
	int v3; // ebx
	int v4; // ebp
	int v5; // edi
	int v6; // esi
	int v7; // ebx
	int v8; // ecx
	char* result; // eax
	int v10; // [esp+10h] [ebp-4h]

	if (byte_5D4594[2650637] & 8)
		return (char*)& byte_587000[155000];
	v1 = *a1 - *(_DWORD*)& byte_5D4594[2650676];
	v2 = a1[1] - *(_DWORD*)& byte_5D4594[2650680];
	v3 = v1 / 23;
	v4 = v2 / 23;
	if (v1 / 23 < 0 || v4 < 0 || v3 > 56 || v4 > 44)
		return (char*)& byte_587000[155000];
	v5 = v1 % 23;
	v10 = v2 % 23;
	v6 = 5 * v3 + v4 + 40 * v3;
	v7 = byte_5D4594[v6 + 2616332];
	v8 = v1 % 23 * (byte_5D4594[v6 + 2616377] - v7);
	result = (char*)& byte_5D4594[1193164];
	*(_DWORD*)& byte_5D4594[1193172] = 8
	                                   * (v7
	                                      + v8 / 23
	                                      + v10
	                                        * (byte_5D4594[v6 + 2616333]
	                                           + v5 * (byte_5D4594[v6 + 2616378] - byte_5D4594[v6 + 2616333]) / 23
	                                           - (v7
	                                              + v8 / 23))
	                                        / 23);
	*(_DWORD*)& byte_5D4594[1193168] = *(_DWORD*)& byte_5D4594[1193172];
	*(_DWORD*)& byte_5D4594[1193164] = *(_DWORD*)& byte_5D4594[1193172];
	return result;
}

//----- (00484B70) --------------------------------------------------------
__int16 __cdecl sub_484B70(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
	int v8; // eax

	v8 = sub_47D380(a7, a8);
	if (v8)
		LOWORD(v8) = sub_47D2C0(a1, a2, a3);
	return v8;
}

//----- (00430D60) --------------------------------------------------------
int sub_430D60()
{
	int result; // eax

	result = 0;
	*(_DWORD*)& byte_5D4594[3805484] = sub_485880;
	*(_DWORD*)& byte_587000[80800] = 0;
	*(_DWORD*)& byte_5D4594[805836] = 0;
	*(_DWORD*)& byte_5D4594[3807124] = 0;
	*(_DWORD*)& byte_5D4594[3807148] = sub_481470;
	*(_DWORD*)& byte_5D4594[3807132] = sub_484E60;
	*(_DWORD*)& byte_5D4594[3807156] = sub_485740;
	*(_DWORD*)& byte_5D4594[3807128] = sub_484B70;
	return result;
}

//----- (00484BD0) --------------------------------------------------------
double sub_484BD0()
{
	return *(float*)& byte_587000[154968];
}

//----- (004C1C70) --------------------------------------------------------
int __fastcall sub_4C1C70(int a1, int a2)
{
	return ((__int64)a1 << 16) / a2;
}

//----- (004695E0) --------------------------------------------------------
int __cdecl sub_4695E0(int a1, int a2, int* a3, int a4, int a5)
{
	int v5; // ebx
	int v6; // esi
	int v7; // edi
	int v8; // eax
	unsigned __int8* v9; // ecx
	int v10; // esi
	int v11; // edi
	int result; // eax

	v5 = a4;
	if (a5)
		v5 = -a4;
	v6 = sub_4C1C60(v5, *a3) << 8;
	v7 = sub_4C1C60(v5, a3[1]) << 8;
	v8 = sub_4C1C60(v5, a3[2]);
	v9 = &byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618924];
	v10 = *(_DWORD*)& byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618924] + v6;
	v11 = *(_DWORD*)& byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618928] + v7;
	result = *(_DWORD*)& byte_5D4594[12 * (a2 + 40 * a1 + 5 * a1) + 2618932] + (v8 << 8);
	if (v10 <= 16711680)
	{
		if (v10 < 0)
			v10 = 0;
	}
	else
	{
		v10 = 16711680;
	}
	if (v11 <= 16711680)
	{
		if (v11 < 0)
			v11 = 0;
	}
	else
	{
		v11 = 16711680;
	}
	if (result <= 16711680)
	{
		if (result < 0)
			result = 0;
		*((_DWORD*)v9 + 1) = v11;
		*(_DWORD*)v9 = v10;
		*((_DWORD*)v9 + 2) = result;
	}
	else
	{
		*((_DWORD*)v9 + 1) = v11;
		*(_DWORD*)v9 = v10;
		result = 16711680;
		*((_DWORD*)v9 + 2) = 16711680;
	}
	return result;
}

//----- (004697C0) --------------------------------------------------------
int __cdecl sub_4697C0(int* a1, int* a2, int2* a3, signed int a4, int* a5)
{
	int result; // eax
	int* v6; // edi
	int v7; // esi
	int v8; // edx
	int v9; // ebp
	int* v10; // ecx
	char* v11; // eax
	int v12; // edi
	int v13; // eax
	int v14; // esi
	int v15; // ebx
	int v16; // eax
	unsigned int v17; // eax
	int v18; // [esp+10h] [ebp-10h]
	char* i; // [esp+14h] [ebp-Ch]
	int j; // [esp+18h] [ebp-8h]
	unsigned int v21; // [esp+1Ch] [ebp-4h]
	int* v22; // [esp+24h] [ebp+4h]
	signed int v23; // [esp+28h] [ebp+8h]
	int v24; // [esp+30h] [ebp+10h]

	result = *a1;
	v6 = a2;
	v7 = *a1 + a1[1];
	v18 = *a1 + a1[1];
	if (*a1 < *a2)
		result = *a2;
	if (v7 > a2[1] + *a2)
	{
		v18 = a2[1] + *a2;
		v7 = a2[1] + *a2;
	}
	if (v7 - result > 1)
	{
		v23 = *(_DWORD*)& byte_587000[142308];
		if ((unsigned int)a4 <= *(int*)& byte_587000[142308])
			v23 = a4;
		v21 = (a4 >> 16) * (a4 >> 16);
		v8 = 23 * result - a3->field_4;
		v24 = 23 * result - a3->field_4;
		v9 = result;
		if (result < v7)
		{
			v10 = &v6[result + 2];
			v11 = (char*)((char*)a1 - (char*)v6);
			v12 = *(_DWORD*)& byte_587000[142316];
			v22 = v10;
			for (i = v11; ; v11 = i)
			{
				v13 = *(int*)((char*)v10 + (_DWORD)v11);
				v14 = 23 * v13 - a3->field_0;
				v15 = v13;
				if (v13 < *v10)
				{
					v16 = v8 * v8;
					for (j = v8 * v8; ; v16 = j)
					{
						v17 = sub_4C1C70(v12 + v23, 66 * *(_DWORD*)& byte_587000[142312] * (v16 + v14 * v14) / v21 + 0x10000);
						v12 = *(_DWORD*)& byte_587000[142316];
						if (v17 > * (int*)& byte_587000[142316])
						{
							sub_4695E0(v15, v9, a5, 8 * (v17 - *(_DWORD*)& byte_587000[142316]), 0);
							v12 = *(_DWORD*)& byte_587000[142316];
						}
						v14 += 23;
						if (++v15 >= *v22)
							break;
					}
					v8 = v24;
					v10 = v22;
				}
				result = v18;
				v8 += 23;
				++v9;
				++v10;
				v24 = v8;
				v22 = v10;
				if (v9 >= v18)
					break;
			}
		}
	}
	return result;
}

//----- (004696B0) --------------------------------------------------------
int __cdecl sub_4696B0(int2* a1, int2* a2, int2* a3, int2* a4, signed int a5, int* a6)
{
	int v6; // edx
	int v7; // edi
	int2* v8; // edi
	int2* v9; // ebx
	int2* v10; // esi
	int result; // eax
	int v12; // ecx
	char v13[184]; // [esp+10h] [ebp-228h]
	char v14[184]; // [esp+C8h] [ebp-170h]
	char v15[184]; // [esp+180h] [ebp-B8h]

	v6 = a1->field_4;
	v7 = a2->field_4;
	if (v6 > v7)
	{
		v10 = a3;
		if (v7 <= a3->field_4)
		{
			v9 = a2;
			v8 = a1;
			goto LABEL_9;
		}
		v9 = a3;
	}
	else
	{
		v8 = a3;
		if (v6 <= a3->field_4)
		{
			v9 = a1;
			v10 = a2;
			goto LABEL_9;
		}
		v9 = a3;
	}
	v10 = a1;
	v8 = a2;
	LABEL_9:
	sub_484DC0(v9, v10, (int*)v15);
	sub_484DC0(v9, v8, (int*)v14);
	sub_4697C0((int*)v15, (int*)v14, a4, a5, a6);
	result = v10->field_4;
	v12 = v8->field_4;
	if (result >= v12)
	{
		if (result > v12)
		{
			sub_484DC0(v8, v10, (int*)v13);
			result = sub_4697C0((int*)v15, (int*)v13, a4, a5, a6);
		}
	}
	else
	{
		sub_484DC0(v10, v8, (int*)v13);
		result = sub_4697C0((int*)v13, (int*)v14, a4, a5, a6);
	}
	return result;
}

//----- (00469140) --------------------------------------------------------
void __cdecl sub_469140(int arg0)
{
	int v1; // esi
	int v2; // eax
	signed int v3; // ebp
	int v4; // edi
	int v5; // ecx
	int v6; // eax
	int v7; // ebx
	int v8; // ebp
	signed int v9; // eax
	int v10; // edx
	int v11; // ebp
	int v12; // edi
	int v13; // eax
	int v14; // edx
	unsigned int v15; // eax
	unsigned int v16; // eax
	__int16 v17; // cx
	int v18; // edi
	int v19; // ebx
	int v20; // eax
	int v21; // ecx
	int v22; // edi
	int v23; // eax
	int v24; // eax
	int v25; // eax
	int* v26; // esi
	float v27; // [esp+0h] [ebp-68h]
	float v28; // [esp+0h] [ebp-68h]
	int v29; // [esp+14h] [ebp-54h]
	signed int v30; // [esp+18h] [ebp-50h]
	int v31; // [esp+1Ch] [ebp-4Ch]
	signed int v32; // [esp+20h] [ebp-48h]
	signed int v33; // [esp+24h] [ebp-44h]
	int i; // [esp+2Ch] [ebp-3Ch]
	unsigned int v35; // [esp+30h] [ebp-38h]
	unsigned int v36; // [esp+34h] [ebp-34h]
	int2 a1; // [esp+38h] [ebp-30h]
	int2 a4; // [esp+40h] [ebp-28h]
	int v39; // [esp+4Ch] [ebp-1Ch]
	int2 a3; // [esp+50h] [ebp-18h]
	int2 a2; // [esp+58h] [ebp-10h]
	int2 v42; // [esp+60h] [ebp-8h]
	int v43; // [esp+6Ch] [ebp+4h]
	int v44; // [esp+6Ch] [ebp+4h]
	int v45; // [esp+6Ch] [ebp+4h]

	v1 = arg0;
	if (sub_45A840((_DWORD*)arg0)
	    || *(_DWORD*)(arg0 + 112) & 0x80000
	       && (v2 = *(_DWORD*)(arg0 + 120), v2 & 0x1000000)
	       && *(_DWORD*)(arg0 + 144) > 0
	       && v2 & 4)
	{
		if (!sub_57AF20()
		    || arg0 == *(_DWORD*)& byte_5D4594[2614252]
		    || *(int(__cdecl * *)(int*, int))(arg0 + 300) == nox_thing_glow_orb_draw)
		{
			v3 = *(_DWORD*)(arg0 + 148);
			v4 = *(_DWORD*)(arg0 + 144);
			if (*(_DWORD*)(arg0 + 120) & 0x20000000)
			{
				v3 += sub_415FF0(0, *(_DWORD*)(arg0 + 148) >> 18, "C:\\NoxPost\\src\\Client\\Light\\Light16.c", 267) << 16;
				v27 = (double)v3 * 0.000015258789;
				v4 = sub_484C60(v27);
			}
			v28 = sub_484BD0() * 65536.0;
			if (v3 > nox_float2int(v28))
			{
				v33 = *(_DWORD*)& byte_587000[142320];
				if ((unsigned int)v3 <= *(int*)& byte_587000[142320])
					v33 = v3;
				v5 = *(_DWORD*)(arg0 + 12) - *(_DWORD*)& byte_5D4594[2650676];
				v36 = (v3 >> 16) * (v3 >> 16);
				v6 = *(_DWORD*)(arg0 + 168);
				v7 = *(_DWORD*)(arg0 + 16) - *(_DWORD*)& byte_5D4594[2650680];
				a4.field_0 = *(_DWORD*)(arg0 + 12) - *(_DWORD*)& byte_5D4594[2650676];
				a4.field_4 = v7;
				if (v6 == 0xFFFF)
				{
					v35 = v4 * v4;
					v43 = (v5 - v4) / 23;
					if (v43 < 0)
						v43 = 0;
					v30 = (v5 + v4) / 0x17u;
					if (v30 > 56)
						v30 = 56;
					v8 = (v7 - v4) / 23;
					if (v8 < 0)
						v8 = 0;
					v9 = (v7 + v4) / 0x17u;
					v32 = (v7 + v4) / 0x17u;
					if (v9 > 44)
					{
						v32 = 44;
						v9 = 44;
					}
					v31 = v8;
					v10 = 23 * v8;
					v39 = 23 * v8;
					if (v8 <= v9)
					{
						v11 = *(_DWORD*)& byte_587000[142328];
						v12 = 23 * v43;
						while (1)
						{
							v13 = v7 - v10;
							v29 = v43;
							if (v43 <= v30)
							{
								v14 = v13 * v13;
								for (i = v13 * v13; ; v14 = i)
								{
									v15 = v14 + (v5 - v12) * (v5 - v12);
									if (v15 <= v35)
									{
										v16 = sub_4C1C70(v33 + v11, 66 * v15 * *(_DWORD*)& byte_587000[142324] / v36 + 0x10000);
										v11 = *(_DWORD*)& byte_587000[142328];
										if (v16 > * (int*)& byte_587000[142328])
										{
											sub_4695E0(
													v29,
													v31,
													(int*)(v1 + 152),
													8 * (v16 - *(_DWORD*)& byte_587000[142328]),
													*(_DWORD*)(v1 + 172));
											v7 = a4.field_4;
											v5 = a4.field_0;
											v11 = *(_DWORD*)& byte_587000[142328];
										}
										else
										{
											v7 = a4.field_4;
											v5 = a4.field_0;
										}
										v12 += 23;
									}
									else
									{
										v12 += 23;
									}
									if (++v29 > v30)
										break;
								}
							}
							v39 += 23;
							if (++v31 > v32)
								break;
							v12 = 23 * v43;
							v10 = v39;
						}
					}
				}
				else
				{
					a1.field_0 = (v5 << 16) / 23;
					v17 = *(_WORD*)(arg0 + 164);
					v18 = v4 << 16;
					a1.field_4 = (v7 << 16) / 23;
					v19 = v18 / 23;
					v20 = sub_4C1C60(
							v18 / 23,
							16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v17 + 0x4000) >> 4) + 2661964]);
					v21 = v18 / 23;
					v22 = v20;
					v23 = sub_4C1C60(v21, 16 * *(_DWORD*)& byte_5D4594[4 * (*(unsigned __int16*)(arg0 + 164) >> 4) + 2661964]);
					a3.field_0 = a1.field_0 + v22;
					LOWORD(v22) = *(_WORD*)(arg0 + 164) + *(_WORD*)(arg0 + 166);
					a3.field_4 = a1.field_4 + v23;
					v44 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v22 + 0x4000) >> 4) + 2661964]);
					v24 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)v22 >> 4) + 2661964]);
					LOWORD(v22) = *(_WORD*)(v1 + 164) - *(_WORD*)(v1 + 166);
					a2.field_0 = a1.field_0 + v44;
					a2.field_4 = a1.field_4 + v24;
					v45 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)(v22 + 0x4000) >> 4) + 2661964]);
					v25 = sub_4C1C60(v19, 16 * *(_DWORD*)& byte_5D4594[4 * ((unsigned __int16)v22 >> 4) + 2661964]);
					v26 = (int*)(v1 + 152);
					v42.field_0 = a1.field_0 + v45;
					v42.field_4 = a1.field_4 + v25;
					sub_4696B0(&a1, &a2, &a3, &a4, v3, v26);
					sub_4696B0(&a1, &a3, &v42, &a4, v3, v26);
				}
			}
		}
	}
}

//----- (00468F80) --------------------------------------------------------
void __cdecl sub_468F80(int a1)
{
	_DWORD* v1; // esi
	int v2; // ecx
	unsigned __int8* v3; // edi
	bool v4; // cc
	int v5; // ecx
	int v6; // eax
	int v7; // edx
	int v8; // edx
	int v9; // ecx
	unsigned __int8* v10; // edi
	int v11; // eax
	int v12; // ebx
	int v13; // edx
	int v14; // eax
	int v15; // ecx
	int v16; // edx
	int4 v17; // [esp+Ch] [ebp-24h]
	int v18; // [esp+1Ch] [ebp-14h]
	int v19; // [esp+20h] [ebp-10h]
	int v20; // [esp+24h] [ebp-Ch]
	int v21; // [esp+28h] [ebp-8h]
	int v22; // [esp+2Ch] [ebp-4h]

	v1 = (_DWORD*)a1;
	*(_DWORD*)& byte_5D4594[2650676] = 46 * ((*(_DWORD*)(a1 + 16) + 11) / 46 - 1) - 11;
	*(_DWORD*)& byte_5D4594[2650680] = 46 * ((*(_DWORD*)(a1 + 20) + 11) / 46) - 57;
	if (byte_5D4594[2650637] & 8)
	{
		v2 = 2464;
		v3 = &byte_5D4594[2618924];
		do
		{
			*(_DWORD*)v3 = 16711680;
			*((_DWORD*)v3 + 1) = 16711680;
			*((_DWORD*)v3 + 2) = 16711680;
			*((_DWORD*)v3 + 3) = 16711680;
			*((_DWORD*)v3 + 4) = 16711680;
			*((_DWORD*)v3 + 5) = 16711680;
			*((_DWORD*)v3 + 6) = 16711680;
			*((_DWORD*)v3 + 7) = 16711680;
			*((_DWORD*)v3 + 8) = 16711680;
			*((_DWORD*)v3 + 9) = 16711680;
			*((_DWORD*)v3 + 10) = 16711680;
			*((_DWORD*)v3 + 11) = 16711680;
			*((_DWORD*)v3 + 12) = 16711680;
			*((_DWORD*)v3 + 13) = 16711680;
			*((_DWORD*)v3 + 14) = 16711680;
			*((_DWORD*)v3 + 15) = 16711680;
			*((_DWORD*)v3 + 16) = 16711680;
			*((_DWORD*)v3 + 17) = 16711680;
			*((_DWORD*)v3 + 18) = 16711680;
			*((_DWORD*)v3 + 19) = 16711680;
			*((_DWORD*)v3 + 20) = 16711680;
			v3 += 84;
			v4 = v2 <= 7;
			v2 -= 7;
		} while (!v4);
	}
	else
	{
		sub_434A10(&a1, &v22, &v21);
		if (sub_57AF20())
		{
			v5 = 50;
			v6 = 50;
			v7 = 50;
			v22 = 50;
			v21 = 50;
			a1 = 50;
		}
		else
		{
			v6 = v21;
			v5 = v22;
			v7 = a1;
		}
		v8 = v7 << 16;
		v20 = v6 << 16;
		v19 = v5 << 16;
		v18 = v8;
		v9 = 2464;
		v10 = &byte_5D4594[2618924];
		v11 = v8;
		v12 = v19;
		v13 = v20;
		do
		{
			*(_DWORD*)v10 = v11;
			*((_DWORD*)v10 + 1) = v12;
			*((_DWORD*)v10 + 2) = v13;
			*((_DWORD*)v10 + 3) = v11;
			*((_DWORD*)v10 + 4) = v12;
			*((_DWORD*)v10 + 5) = v13;
			*((_DWORD*)v10 + 6) = v11;
			*((_DWORD*)v10 + 7) = v12;
			*((_DWORD*)v10 + 8) = v13;
			*((_DWORD*)v10 + 9) = v11;
			*((_DWORD*)v10 + 10) = v12;
			*((_DWORD*)v10 + 11) = v13;
			*((_DWORD*)v10 + 12) = v11;
			*((_DWORD*)v10 + 13) = v12;
			*((_DWORD*)v10 + 14) = v13;
			*((_DWORD*)v10 + 15) = v11;
			*((_DWORD*)v10 + 16) = v12;
			*((_DWORD*)v10 + 17) = v13;
			*((_DWORD*)v10 + 18) = v11;
			*((_DWORD*)v10 + 19) = v12;
			*((_DWORD*)v10 + 20) = v13;
			v10 += 84;
			v4 = v9 <= 7;
			v9 -= 7;
		} while (!v4);
		v14 = v1[4];
		v17.field_0 = v14 - 100;
		v15 = v1[5];
		v17.field_4 = v15 - 100;
		v16 = v1[9];
		v17.field_8 = v1[8] + v14 + 100;
		v17.field_C = v16 + v15 + 100;
		sub_49AB00(&v17, (void(__cdecl*)(int, int))sub_469140, (int)v1);
	}
}

//----- (00430CC0) --------------------------------------------------------
BOOL sub_430CC0()
{
	BOOL result; // eax

	*(_DWORD*)& byte_5D4594[3807124] = 1;
	*(_DWORD*)& byte_5D4594[3807128] = sub_480EF0;
	*(_DWORD*)& byte_5D4594[3807132] = sub_468F80;
	*(_DWORD*)& byte_5D4594[3807148] = sub_4814F0;
	*(_DWORD*)& byte_5D4594[3807156] = sub_469920;
	result = sub_430D40();
	*(_DWORD*)& byte_587000[80800] = result;
	if (result)
	{
		*(_DWORD*)& byte_5D4594[805836] = 1;
		*(_DWORD*)& byte_5D4594[3805484] = sub_480950;
		*(_DWORD*)& byte_5D4594[3805492] = sub_4805A0;
	}
	else
	{
		*(_DWORD*)& byte_5D4594[805836] = 0;
		*(_DWORD*)& byte_5D4594[3805484] = sub_480BE0;
		*(_DWORD*)& byte_5D4594[3805492] = sub_480860;
	}
	return result;
}

//----- (00430BA0) --------------------------------------------------------
int nox_init_floor_buf() {
	if (*(_DWORD*)& byte_5D4594[3801780] == 1)
		sub_430CC0();
	else
		sub_430D60();
	if (!sub_430DB0(nox_backbuffer_width, nox_backbuffer_height))
	{
		printf("VideoInit: error initializing floor buffer\n");
		return 0;
	}
	return 1;
}

//----- (00431040) --------------------------------------------------------
int __cdecl sub_431040(int a1, int a2, int a3)
{
	nox_win_width = a2;
	nox_win_height = a3;
	*(_DWORD*)& byte_587000[80848] = 0;
	int result = sub_4800F0();
	if (!result)
	{
		return 0;
	}
	return nox_init_floor_buf();
}

int sub_430BA0()
{
	sub_430EC0();
	int result = sub_47FD70();
	printf("%s: %d\n", __FUNCTION__, result);
	if (!result)
	{
		return 0;
	}
	return nox_init_floor_buf();
}
