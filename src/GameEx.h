#include "DG_dynarr.h"
#include "defs.h"
#include "proto.h"

#ifdef _WIN32
typedef intptr_t INT_PTR;
typedef INT_PTR LSTATUS;

#include <mmreg.h>
#include <windows.h>
#else
#pragma GCC poison fgetwln fgetws fputwc fputws fwprintf fwscanf mbrtowc mbsnrtowcs mbsrtowcs putwc putwchar swprintf  \
	swscanf vfwprintf vfwscanf vswprintf vswscanf vwprintf vwscanf wcrtomb wcscat wcschr wcscmp wcscoll wcscpy wcscspn \
		wcsftime wcsftime wcslcat wcslcpy wcslen wcsncat wcsncmp wcsncpy wcsnrtombs wcspbrk wcsrchr wcsrtombs wcsspn   \
			wcsstr wcstod wcstof wcstok wcstol wcstold wcstoll wcstoul wcstoull wcswidth wcsxfrm wcwidth wmemchr       \
				wmemcmp wmemcpy wmemmove wmemset wprintf wscanf
#include "windows.h"
#endif

typedef struct keyCodeStruct {
	unsigned __int8 keyCode;
	char keyName[12];
} keyCodeStruct;

typedef struct smallPlayerStruct {
	char string[18];
} smallPlayerStruct;

DA_TYPEDEF(smallPlayerStruct, smallPlayerStructVector);
DA_TYPEDEF(int, intArray);

//-------------------------------------------------------------------------
// Function declarations

#define __thiscall __cdecl // Test compile in C mode
#define __usercall __cdecl // Test compile in C mode

// BOOL __stdcall GameEx_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
// void __thiscall ExceptionDestructor(void *this);
// void *__thiscall BadAllocException(void *this, char a2);
// _DWORD *__thiscall LogicExceptionCreator(_DWORD *this, _DWORD *a2);
// void __thiscall LogicErrorException2(void **this);
// int __thiscall unknown_libname_3(_DWORD *this);
// _DWORD *__thiscall LogicLengthErrorException(void *this, char a2);
// _DWORD *__thiscall LengthErrorExceptionCreator(_DWORD *this, int a2);
// std::exception *__thiscall CopyConstructor(std::exception *this, struct std::exception *a2);
unsigned __int8 __cdecl KeyCodeMatcher(char* a1);
int __cdecl GameExCfgSaver();
const char* __usercall SomeStringSearcher(const char* result, const char* a2, char* a3);
char GameExCfgLoader();
int __cdecl sendtoWrapper(char* buf, int len, int smth);
void __cdecl notifyThisIsServeronly(int ptr, __int16 shortval, BOOL boolval); // idb
int __usercall DestroyNoxWindow();
int __usercall copyServerMatchData(char* a1);
char __cdecl getPlayerClassFromObjPtr(int a1);
int __usercall playerInfoStructsToVector(smallPlayerStructVector* vector);
char __cdecl playerInfoStructParser_0(char* a1); // idb
char __usercall playerInfoStructParser_1(int a1, int a2, int* a3);
char __cdecl mix_MouseKeyboardWeaponRoll(int playerObj, char a2); // idb
char __cdecl playerDropATrap(int playerObj);             // idb
HANDLE __usercall GameIpParser(int a1, int a2, int a3);
unsigned int __usercall pingAllServersInGameIp(int ebx0, int edi0, int a1, int a2, int a3);
signed int __usercall inputNewIp_(int a1, int ebx0, int a2, int a3, int a4);
void playErrSoundClient();
unsigned int invalidIpChecker(unsigned int interval, void* param);
HANDLE __usercall startInvalidIpChecker();
int __cdecl modifyWndInputHandler(int a1, int a2, int a3, int a4);
// int __stdcall MixRecvFromReplacer(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen); //
// idb _DWORD *OnLibraryNotice(int, ...);
// int __thiscall ExceptMsg(int this, void *Src);
// void **SomeAllocatorVectorMB();
// _DWORD *__usercall addToVector_(_DWORD *a1, int a2);
// _DWORD *__stdcall CreateVector(_DWORD *a1);
// _DWORD *__usercall VectorGetFirstElement(_DWORD *a1, _DWORD *a2);
// _DWORD *__usercall VectorGetLastElement(_DWORD *a1, _DWORD *a2);
// _DWORD *__userpurge InsertIntoVector_(int *a1, int a2);
// bool __usercall CompareVectorValues(_DWORD *a1, _DWORD *a2, int a4);
// void SomeDeallocator();
// _DWORD *__thiscall AllocAndMemset_(int this, _DWORD *a2, unsigned int a3, void *a4);
// _DWORD *__userpurge SomeVectorFunc(int ebx0, int esi0, _DWORD *a1, int a2, void *a3, _BYTE *Src);
// _DWORD *__userpurge SomeVectorFunc_0(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5);
// _DWORD *__userpurge PossibleVectorSub(_DWORD *a1, _DWORD *a2, int esi0, int a3, unsigned int a4, int a5, unsigned int
// a6); _DWORD *__fastcall SomeStringCopier_(int a1, int a2, void *Src, rsize_t MaxCount); _DWORD *__thiscall
// MemMover(_DWORD *this, unsigned int a2, unsigned int a3); char *__stdcall SomeVectorFunc_1(int a1, int a2, void
// *Src); void __fastcall __noreturn VectorException(int a1, int a2, int a3, int a4); void *__fastcall
// SomeAllocator_0(unsigned int a1); char *__thiscall SomeVectorProcedure(_DWORD *this, int a2, int a3, int a4); void
// __fastcall __noreturn VectorException_0(int a1, int a2, int a3, int a4); void *__fastcall SomeAllocator_1(unsigned
// int a1); std::exception *__thiscall CopyConstructor2(std::exception *this, struct std::exception *a2); _BYTE
// *__thiscall Copier(_DWORD *this, void *Dst, rsize_t MaxCount); void *__stdcall SomeAllocator_2(char *a1);
int __usercall getFlagValueFromFlagIndex(signed int a1);
// int __usercall PossibleVectorSub_1(int a1, int a2, int a3);
// char *__usercall SomeVectorFunc_2(int a1, char *a2, const void *a3);
// int __usercall SomeVectorFunc_3(int result, int a2, int a3);
// std::exception *__thiscall AllocException(std::exception *this, struct std::exception *a2);
// int __usercall SomeVectorFunc_4(int result, int a2, int a3);
// int __usercall SomeVectorFunc_5(int a1, int a2, int a3);
// int __usercall SomeVectorFunc_6(int result, int a2, int a3);
// void __cdecl __security_check_cookie(char a1);
// _DWORD *__thiscall ExceptionCreator(_DWORD *this);
// std::exception *__thiscall std::exception::exception(std::exception *this, const char *const *a2);
// std::exception *__thiscall std::exception::exception(std::exception *this, const char *const *a2, int a3);
// std::exception *__thiscall std::exception::exception(std::exception *this, const struct std::exception *a2);
// void __thiscall SomeOtherException(void *this);
// const char *__thiscall exception::what(exception *__hidden this); idb
// void *__thiscall SomeException(void *this, char a2);
// void __cdecl operator delete(void *); idb
// errno_t __cdecl memcpy_s(void *Dst, rsize_t DstSize, const void *Src, rsize_t MaxCount);
// errno_t __cdecl memmove_s(void *Dst, rsize_t DstSize, const void *Src, rsize_t MaxCount);
// void __cdecl operator delete[](void *); idb
// void __thiscall SomeOtherTypeInfo(struct type_info *this);
// void *__thiscall SomeTypeInfo(void *this, char a2);
// BOOL __thiscall type_info::operator==(const char *this, int a2);
// std::bad_alloc *__thiscall std::bad_alloc::bad_alloc(std::bad_alloc *this);
// void *__cdecl operator new(size_t); idb
// void *__cdecl operator new[](unsigned int); idb
// int __cdecl InitPointers_1(int a1);
// BOOL __usercall _invoke_watson(int a1, int a2, int a3);
// int __usercall _invalid_parameter(int a1, int a2, int a3);
// int __usercall _invalid_parameter_noinfo(int a1, int a2, int a3);
// int __cdecl _onexit_nolock(int a1);
// _onexit_t __cdecl _onexit(_onexit_t);
// int __cdecl atexit(void (__cdecl *)());
// char *__cdecl strstr(const char *, const char *);
// void __cdecl __noreturn _endthreadex(DWORD dwExitCode); idb
// void __noreturn _callthreadstartex();
// void __stdcall __noreturn _threadstartex(LPVOID lpThreadParameter);
// HANDLE __usercall _beginthreadex(int a1, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, int a4, int
// a5, DWORD dwCreationFlags, LPDWORD lpThreadId); _LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate
// *this, struct localeinfo_struct *a2); int __cdecl _mbstowcs_l_helper(LPWSTR lpWideCharStr, LPCSTR lpMultiByteStr, int
// cchWideChar, struct localeinfo_struct *); idb size_t __cdecl mbstowcs(wchar_t *, const char *, size_t); signed int
// __stdcall _CRT_INIT(int a1, int a2, int a3); BOOL __usercall __DllMainCRTStartup(int a1, int a2, HINSTANCE hinstDLL);
// BOOL __stdcall DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);
// BOOL __usercall __noreturn __report_gsfailure(int a1, int a2, int a3, int a4, int a5, int a6, char a7);
// errno_t __cdecl strcpy_s(char *Dst, rsize_t SizeInBytes, const char *Src);
// int __cdecl V6_HeapAlloc(unsigned int a1);
// void *__cdecl malloc(size_t);
// size_t __cdecl strlen(const char *);
// void __cdecl free(void *);
// void *__cdecl memset(void *, int, size_t);
// void *__cdecl memcpy(void *, const void *, size_t);
// signed int __cdecl _get_errno_from_oserr(int a1);
// int *__cdecl _errno();
// unsigned int *__cdecl __doserrno();
// int *__cdecl _dosmaperr(unsigned int a1);
// void *__cdecl memcpy_0(void *, const void *, size_t);
// void __cdecl type_info::_Type_info_dtor(struct type_info *); idb
// int __cdecl strcmp(const char *, const char *);
// int __cdecl InitPointers(int a1);
// BOOL __cdecl _callnewh(int a1);
// void __stdcall __noreturn _CxxThrowException(int a1, _BYTE *a2);
// void InternalStateChanger();
// int __cdecl _encode_pointer(int a1);
// int _encoded_null(void); weak
// int __cdecl _decode_pointer(int a1);
// DWORD __stdcall __crtTlsAlloc(int a1);
// int __stdcall __fls_getvalue(int a1);
// int ThreadStartStatus();
// void *__set_flsgetvalue();
// int __stdcall __fls_setvalue(int a1, int a2);
// int _mtterm(void); weak
// int __cdecl _initptd(int a1, int a2);
// DWORD *_getptd_noexit();
// DWORD *_getptd();
// void __stdcall _freefls(void *a1);
// DWORD __cdecl _freeptd(void *a1);
// signed int _mtinit();
// void *__cdecl _malloc_crt(size_t a1);
// int __cdecl _calloc_crt(size_t a1, int a2);
// void *__cdecl _realloc_crt(void *a1, size_t a2);
// size_t __cdecl _msize(void *);
// HMODULE __cdecl _crt_waiting_on_module_handle(LPCWSTR lpModuleName);
// int __cdecl _amsg_exit(int a1);
// HMODULE __cdecl __crtCorExitProcess(int a1);
// void __cdecl __noreturn __crtExitProcess(UINT uExitCode); idb
// int _lockexit(void); weak
// int _unlockexit();
// int (*__usercall _initterm(int (*result)(void), unsigned int a2))(void);
// int __cdecl _initterm_e(int (**a1)(void), unsigned int a2);
// int __cdecl _cinit(int a1);
// int (*__cdecl doexit(UINT uExitCode, int a2, int a3))(void);
// void __cdecl __noreturn _exit(int);
// void __cdecl _cexit();
// void (__cdecl __noreturn *_init_pointers())(UINT uExitCode);
// void __cdecl _SEH_prolog4(int a1, int a2);
// int __cdecl SEH_10006CE0(int, PVOID TargetFrame, int); idb
// char *__cdecl strchr(const char *, int);
// BOOL __cdecl _ValidateImageBase(int a1);
// int __cdecl _FindPESection(int a1, unsigned int a2);
// BOOL __cdecl _IsNonwritableInCurrentImage(int a1);
// int __cdecl nullsub_1(_DWORD); weak
// DWORD *__cdecl _XcptFilter(int a1, DWORD a2);
// DWORD *__cdecl __CppXcptFilter(int a1, DWORD a2);
// signed int __usercall CPtoLCID(int a1);
// void __usercall setSBCS(_DWORD *a1);
// void __usercall setSBUpLow(int a1);
// volatile LONG *__updatetmbcinfo();
// UINT __usercall getSystemCP(int a1);
// signed int __cdecl _setmbcp_nolock(int a1, _DWORD *a2);
// int __cdecl _setmbcp(int);
// int __initmbctable();
// void __cdecl __freetlocinfo(void *a1);
// LONG __cdecl __addlocaleref(volatile LONG *lpAddend);
// volatile LONG *__cdecl __removelocaleref(volatile LONG *lpAddend);
// volatile LONG *__usercall _updatetlocinfoEx_nolock(volatile LONG **a1, volatile LONG *a2);
// DWORD __updatetlocinfo();
// int __cdecl _isleadbyte_l(int C, _locale_t Locale);
// signed int _ioinit();
// void _ioterm();
// signed int _setenvp();
// int *__usercall parse_cmdline(char *a1, _DWORD *a2, int *a3, int a4, _DWORD *a5);
// signed int _setargv();
// CHAR *__crtGetEnvironmentStringsA();
// int (*CrtInit())(void);
// void __cdecl cLibInit(); idb
// HANDLE __cdecl _heap_init(int a1);
// BOOL _heap_term();
// DWORD __security_init_cookie();
// signed int _mtinitlocks();
// void _mtdeletelocks();
// void __cdecl _unlock(int a1);
// signed int __cdecl _mtinitlocknum(int a1);
// void __cdecl _lock(int a1);
// char *__cdecl __sbh_find_block(int a1);
// _DWORD *__cdecl __sbh_free_block(_DWORD *a1, int a2);
// _DWORD __cdecl __sbh_alloc_block(_DWORD); weak
// _DWORD __cdecl _NMSG_WRITE(_DWORD); weak
// int _FF_MSGBANNER(void); weak
// void *__cdecl _VEC_memzero(void *arg0, int arg4, size_t arg8);
// int _get_sse2_info(void); weak
// int sse2StatusSetup();
// void *__cdecl _VEC_memcpy(void *arg0, const void *arg4, size_t arg8);
// int __fastcall _EH4_CallFilterFunc(_DWORD, _DWORD); weak
// int __fastcall _EH4_TransferToHandler(_DWORD, _DWORD); weak
// int __thiscall _EH4_GlobalUnwind(PVOID TargetFrame); idb
// _DWORD __stdcall _EH4_LocalUnwind(_DWORD, _DWORD); weak
// int __cdecl _calloc_impl(size_t, int, int); idb
// void *__cdecl realloc(void *, size_t);
// int _initp_misc_cfltcvt_tab(void); weak
// void __cdecl __noreturn terminate(); idb
// int __cdecl _initp_eh_hooks(_DWORD); weak
// _DWORD __cdecl _initp_misc_winsig(_DWORD); weak
// int PointerDecoder();
// int __cdecl InitPointers_3(int a1);
// int __cdecl InitPointers_2(int a1);
// int __cdecl InitPointers_0(int a1);
// int __cdecl __crtInitCritSecAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount); idb
// int __cdecl __crtLCMapStringA(struct localeinfo_struct *, LCID Locale, DWORD dwMapFlags, LPCSTR lpMultiByteStr, char
// *cbMultiByte, LPWSTR lpDestStr, char *cchDest, UINT CodePage, int); idb int __cdecl __crtGetStringTypeA(struct
// localeinfo_struct *, DWORD dwInfoType, LPCSTR lpMultiByteStr, char *cbMultiByte, LPWORD lpCharType, UINT CodePage,
// LCID Locale, int); idb _DWORD __cdecl __free_lc_time(_DWORD); weak _DWORD __cdecl __free_lconv_num(_DWORD); weak
// _DWORD __cdecl __free_lconv_mon(_DWORD); weak
// int __cdecl _ismbblead(unsigned int);
// int __cdecl SomeWndPointerGetter(int a1, int a2, int a3);
// _DWORD *__thiscall OutOfRangeExceptionCreator(_DWORD *this, int a2);
// void __thiscall SomeLogicErrorExceptionDestructor(void **this);
// void *__thiscall OutOfRangeException(void *this, char a2);
// void __cdecl __noreturn StringExceptionCreator_0(int a1, int a2);
// void __noreturn StringExceptionCreator();
// std::exception *__thiscall CopyConstructor3(std::exception *this, struct std::exception *a2);
// _DWORD __cdecl sub_1000B1A6(_DWORD, _DWORD); weak
// _DWORD __cdecl __CxxFrameHandler3(struct EHExceptionRecord *, struct EHRegistrationNode *, struct _CONTEXT *, void
// *); weak std::exception *__thiscall BadException_0(std::exception *this, char *a2); void __thiscall
// ExceptionDestructor2(void *this); void *__thiscall BadException(void *this, char a2); void __cdecl
// __DestructExceptionObject(_DWORD *a1); std::exception *__thiscall BadException_1(std::exception *this, struct
// std::exception *a2); int AllocAndDestructSet(); void __cdecl vectorDestructor(); idb void __cdecl BadAllocExcept();
// idb HANDLE __stdcall CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES
// lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile); BOOL __stdcall
// WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED
// lpOverlapped); BOOL __stdcall CloseHandle(HANDLE hObject); DWORD __stdcall GetFileSize(HANDLE hFile, LPDWORD
// lpFileSizeHigh); BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD
// lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped); BOOL __stdcall TerminateProcess(HANDLE hProcess, UINT uExitCode);
// HANDLE __stdcall GetCurrentProcess();
// LONG __stdcall UnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo);
// LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER
// lpTopLevelExceptionFilter); BOOL __stdcall IsDebuggerPresent(); void __stdcall __noreturn ExitThread(DWORD
// dwExitCode); DWORD __stdcall GetCurrentThreadId(); DWORD __stdcall GetLastError(); HANDLE __stdcall
// CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
// LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId); int __stdcall MultiByteToWideChar(UINT CodePage,
// DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar); LPSTR __stdcall
// GetCommandLineA(); LPVOID __stdcall HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes); BOOL __stdcall
// HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem); void __stdcall RaiseException(DWORD dwExceptionCode, DWORD
// dwExceptionFlags, DWORD nNumberOfArguments, const ULONG_PTR *lpArguments); HMODULE __stdcall GetModuleHandleW(LPCWSTR
// lpModuleName); FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName); LPVOID __stdcall
// TlsGetValue(DWORD dwTlsIndex); DWORD __stdcall TlsAlloc(); BOOL __stdcall TlsSetValue(DWORD dwTlsIndex, LPVOID
// lpTlsValue); BOOL __stdcall TlsFree(DWORD dwTlsIndex); LONG __stdcall InterlockedIncrement(volatile LONG *lpAddend);
// void __stdcall SetLastError(DWORD dwErrCode);
// LONG __stdcall InterlockedDecrement(volatile LONG *lpAddend);
// SIZE_T __stdcall HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
// void __stdcall __noreturn ExitProcess(UINT uExitCode);
// BOOL __stdcall GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo);
// UINT __stdcall GetACP();
// UINT __stdcall GetOEMCP();
// BOOL __stdcall IsValidCodePage(UINT CodePage);
// UINT __stdcall SetHandleCount(UINT uNumber);
// HANDLE __stdcall GetStdHandle(DWORD nStdHandle);
// DWORD __stdcall GetFileType(HANDLE hFile);
// void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
// void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
// DWORD __stdcall GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
// BOOL __stdcall FreeEnvironmentStringsA(LPCH);
// LPCH __stdcall GetEnvironmentStrings();
// BOOL __stdcall FreeEnvironmentStringsW(LPWCH);
// int __stdcall WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR
// lpMultiByteStr, int cbMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar); LPWCH __stdcall
// GetEnvironmentStringsW(); HANDLE __stdcall HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
// BOOL __stdcall HeapDestroy(HANDLE hHeap);
// BOOL __stdcall VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
// BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);
// DWORD __stdcall GetCurrentProcessId();
// void __stdcall GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
// void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
// void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
// HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName);
// BOOL __stdcall CharToOemW(LPCWSTR pSrc, LPSTR pDst);
// int __stdcall sendto(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen);
// unsigned int __stdcall inet_addr(const char *cp);
// int __stdcall recvfrom(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen);
