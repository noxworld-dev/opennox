extern __int16 asc_9800B0[526];
extern int dword_980858[3]; // weak

void init_data_mix();

BOOL __stdcall GameEx_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
_DWORD* OnLibraryNotice(int, ...);
int __stdcall MixRecvFromReplacer(SOCKET s, char* buf, int len, int flags, struct sockaddr* from, int* fromlen); // idb
int OnLibraryNotice_stub(int a1, ...);

void __cdecl sub_980523(int a1);
int __cdecl sub_9805EB(int a1);

int __stdcall mix_recvfrom(SOCKET s, char* buf, int len, int flags, struct sockaddr* from, int* fromlen);
