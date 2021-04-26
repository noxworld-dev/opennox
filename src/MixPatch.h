#ifndef NOX_MIXPATCH_H
#define NOX_MIXPATCH_H

#include "proto.h"

extern __int16 asc_9800B0[526];

void init_data_mix();

BOOL __stdcall GameEx_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
void OnLibraryNotice_256();
void OnLibraryNotice_257();
void OnLibraryNotice_258();
void OnLibraryNotice_259(DWORD arg1);
void OnLibraryNotice_260(DWORD arg1, DWORD arg2, DWORD arg3);
void OnLibraryNotice_261();
void OnLibraryNotice_262(DWORD arg1);
void OnLibraryNotice_263(DWORD arg1);
void OnLibraryNotice_264(DWORD arg1);
void OnLibraryNotice_265(unsigned int arg1, unsigned int arg2, unsigned int arg3);
void OnLibraryNotice_417(DWORD arg1);
void OnLibraryNotice_418();
void OnLibraryNotice_420(DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4);
int __stdcall MixRecvFromReplacer(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from); // idb
void OnLibraryNotice_stub(int a1, ...);

void  sub_980523(_DWORD* a1);
_DWORD*  sub_9805EB(_DWORD* a1);

int __stdcall mix_recvfrom(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from);

#endif // NOX_MIXPATCH_H
