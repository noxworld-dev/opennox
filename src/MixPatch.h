#ifndef NOX_MIXPATCH_H
#define NOX_MIXPATCH_H

#include "proto.h"

extern __int16 asc_9800B0[526];

void init_data_mix();

BOOL __stdcall GameEx_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
void OnLibraryNotice(int, ...);
int __stdcall MixRecvFromReplacer(SOCKET s, char* buf, int len, int flags, struct sockaddr* from, int* fromlen); // idb
void OnLibraryNotice_stub(int a1, ...);

void __cdecl sub_980523(_DWORD* a1);
_DWORD* __cdecl sub_9805EB(_DWORD* a1);

int __stdcall mix_recvfrom(SOCKET s, char* buf, int len, int flags, struct sockaddr* from, int* fromlen);

#endif // NOX_MIXPATCH_H
