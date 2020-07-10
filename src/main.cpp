#include <cstdio>
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#include <dbghelp.h>
#include <Psapi.h>
#else
#include "windows.h"
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

extern "C" const char* progname;
const char* progname;


#ifdef _WIN32

#ifdef RUNTIME_MEM_TRACK

extern "C" extern unsigned __int8 byte_581450[23472];
extern "C" extern unsigned __int8 byte_587000[316820];
extern "C" extern unsigned __int8 byte_5D4594[3844309];

unsigned char* beginAddr = 0;
unsigned char* endAddr = 0;

void EnsureRW() {
	LPVOID addr = 0;
	BOOL res = 0;
	DWORD err = 0;
	DWORD oldProt;

	addr = byte_581450;
	res = VirtualProtect(addr, sizeof(byte_581450), PAGE_READWRITE, &oldProt);
	err = GetLastError();

	addr = byte_587000;
	res = VirtualProtect(addr, sizeof(byte_587000), PAGE_READWRITE, &oldProt);
	err = GetLastError();

	addr = byte_5D4594;
	res = VirtualProtect(addr, sizeof(byte_5D4594), PAGE_READWRITE, &oldProt);
	err = GetLastError();
}

extern "C" void EnsurePageGuard() {
	//return;
	LPVOID addr = 0;
	BOOL res = 0;
	DWORD err = 0;
	DWORD oldProt;

	addr = byte_581450;
	res = VirtualProtect(addr, sizeof(byte_581450), PAGE_READONLY | PAGE_GUARD, &oldProt);
	err = GetLastError();

	addr = byte_587000;
	res = VirtualProtect(addr, sizeof(byte_587000), PAGE_READONLY | PAGE_GUARD, &oldProt);
	err = GetLastError();

	addr = byte_5D4594;
	res = VirtualProtect(addr, sizeof(byte_5D4594), PAGE_READONLY | PAGE_GUARD, &oldProt);
	err = GetLastError();
}

DWORD dumpAddr;
int dumpMode;
CONTEXT dumpCtx;

void PreDump(DWORD addr, int mode, CONTEXT* ctx)
{
	dumpAddr = addr;
	dumpMode = mode;
	memmove(&dumpCtx, ctx, sizeof(CONTEXT));
}

void DumpInfo(DWORD addr, int mode, CONTEXT* ctx) {
	HANDLE process = GetCurrentProcess();
	HANDLE thread = GetCurrentThread();
	char symbolBuffer[sizeof(IMAGEHLP_SYMBOL) + 260];
	PIMAGEHLP_SYMBOL symbol = (PIMAGEHLP_SYMBOL)symbolBuffer;
	memset(symbolBuffer, 0, sizeof(IMAGEHLP_SYMBOL) + 260);
	symbol->SizeOfStruct = (sizeof IMAGEHLP_SYMBOL) + 260;
	symbol->MaxNameLength = 254;
	STACKFRAME frame;
	memset(&frame, 0, sizeof(frame));
	frame.AddrPC.Offset = ctx->Eip;
	frame.AddrPC.Mode = AddrModeFlat;
	frame.AddrFrame.Offset = ctx->Ebp;
	frame.AddrFrame.Mode = AddrModeFlat;
	frame.AddrStack.Offset = ctx->Esp;
	frame.AddrStack.Mode = AddrModeFlat;

	DWORD displ;
	BOOL res = FALSE;
	while (StackWalk(IMAGE_FILE_MACHINE_I386, process, thread, &frame, ctx, NULL, SymFunctionTableAccess,
		SymGetModuleBase, NULL))
	{
		//es = SymGetSymFromAddr(process, frame.AddrPC.Offset, &displ, symbol);
		if (frame.AddrPC.Offset >= (DWORD)beginAddr && frame.AddrPC.Offset <= (DWORD)endAddr) {
			break;
		}
	}
	SymGetSymFromAddr(process, frame.AddrPC.Offset, &displ, symbol);
	symbol->Name[254] = 0;
	IMAGEHLP_LINE line;
	memset(&line, 0, sizeof(IMAGEHLP_LINE));
	line.SizeOfStruct = sizeof(IMAGEHLP_LINE);
	SymGetLineFromAddr(process, frame.AddrPC.Offset, &displ, &line);

	printf("%s: %s:%i: ", symbol->Name, line.FileName, line.LineNumber);

	/*BOOL res = SymGetSymFromAddr(process, frame.AddrPC.Offset, &displ, symbol);
	while (res == FALSE || ctx->Eip < (DWORD)beginAddr || ctx->Eip > (DWORD)endAddr)
	{
		BOOL res2 = StackWalk(IMAGE_FILE_MACHINE_I386, process, thread, &frame, ctx, NULL, SymFunctionTableAccess, SymGetModuleBase,
				  NULL);
		res = SymGetSymFromAddr(process, frame.AddrPC.Offset, &displ, symbol);
		if (res2 == FALSE)
		{
			break;
		}
	}

	IMAGEHLP_LINE line;
	res = SymGetLineFromAddr(process, frame.AddrPC.Offset, &displ, &line);*/

	//printf("%s: %s:%s", symbol->Name, line.FileName, line.LineNumber);

	if (mode == 1)
	{
		printf("Read memory 0x%08x from EIP 0x%08x\n", addr, ctx->Eip);
	}
	else if (mode == 2)
	{
		printf("Write memory 0x%08x from EIP 0x%08x\n", addr, ctx->Eip);
	}
	else if (mode == 3)
	{
		printf("ERROR memory 0x%08x from EIP 0x%08x\n", addr, ctx->Eip);
	}
}

LONG __stdcall MemoryLoggerFilter(_EXCEPTION_POINTERS* pEp) {
	CONTEXT* ctx = pEp->ContextRecord;
	ULONG_PTR* info = pEp->ExceptionRecord->ExceptionInformation;
	UINT_PTR addr = info[1];

	if (pEp->ExceptionRecord->ExceptionCode == STATUS_SINGLE_STEP ||
		(addr >= (DWORD)&byte_581450 && addr <= ((DWORD)&byte_581450 + sizeof(byte_581450))) ||
		(addr >= (DWORD)&byte_587000 && addr <= ((DWORD)&byte_587000 + sizeof(byte_587000))) ||
		(addr >= (DWORD)&byte_5D4594 && addr <= ((DWORD)&byte_5D4594 + sizeof(byte_5D4594)))
		)
	{

		switch (pEp->ExceptionRecord->ExceptionCode) {
		case STATUS_GUARD_PAGE_VIOLATION:
			// printf("Read memory 0x%08x from EIP 0x%08x\n", addr, ctx->Eip);
			//DumpInfo(addr, 1, ctx);
			PreDump(addr, 1, ctx);
			ctx->EFlags |= 0x100;
			return EXCEPTION_CONTINUE_EXECUTION;
		case STATUS_ACCESS_VIOLATION:
			// printf("Write memory 0x%08x from EIP 0x%08x\n", addr, ctx->Eip);
			//DumpInfo(addr, 2, ctx);
			PreDump(addr, 2, ctx);
			EnsureRW();
			ctx->EFlags |= 0x100;
			return EXCEPTION_CONTINUE_EXECUTION;
		case STATUS_SINGLE_STEP:
			ctx->EFlags &= ~0x100;
			EnsurePageGuard();
			DumpInfo(dumpAddr, dumpMode, &dumpCtx);
			return EXCEPTION_CONTINUE_EXECUTION;
		default:
			break;
		}
	}
	else
	{
		//DumpInfo(addr, 3, ctx);
	}
	ctx->EFlags &= ~0x100;
	EnsurePageGuard();
	return EXCEPTION_CONTINUE_SEARCH;
}

#endif

#endif

#if defined(__EMSCRIPTEN__)
extern "C" int main()
#elif defined(_WIN32)
int main(int argc, char* argv[])
#else
extern "C" int main(int argc, char* argv[])
#endif
{
	char cmdline[256];

#ifdef __EMSCRIPTEN__
	EM_ASM({
		var params = (new URL(document.location)).searchParams;
		var lang = params.get('lang') || 'en';
		if (lang != 'en' && lang != 'ko') {
			window.alert('Unknown language: ' + lang);
			return;
		}
		try {
			FS.unlink('/assets/default.fnt');
		} catch (err) {
		}
		try {
			FS.unlink('/assets/nox.csf');
		} catch (err) {
		}
		FS.symlink('/assets/' + lang + '/default.fnt', '/assets/default.fnt');
		FS.symlink('/assets/' + lang + '/nox.csf', '/assets/nox.csf');
	});

	EM_ASM(FS.syncfs(false, function(err){}););

	progname = "nox.js";
	strcpy(cmdline, "nox.js -noskip -nolimit -nothread -sleep");

	if (chdir("assets")) {
		fprintf(stderr, "Failed to enter Nox directory.\n");
		return 1;
	}
#else
	progname = argv[0];
	strcpy(cmdline, argv[0]);

	for (int i = 1; i < argc; i++)
		sprintf(cmdline + strlen(cmdline), " %s", argv[i]);
#endif

#ifdef _WIN32
#ifdef RUNTIME_MEM_TRACK
	BOOL res = SymInitialize(GetCurrentProcess(), NULL, TRUE);
	DWORD symOptions = SymGetOptions();
	symOptions |= SYMOPT_LOAD_LINES;
	symOptions |= SYMOPT_FAIL_CRITICAL_ERRORS;
	symOptions |= SYMOPT_DEBUG;
	symOptions = SymSetOptions(symOptions);

	HMODULE modules[1];
	DWORD needcb;
	MODULEINFO mod;

	EnumProcessModules(GetCurrentProcess(), modules, sizeof(HMODULE), &needcb);
	GetModuleInformation(GetCurrentProcess(), modules[0], &mod, sizeof(mod));
	beginAddr = (unsigned char*)mod.lpBaseOfDll;
	endAddr = (unsigned char*)((DWORD)mod.lpBaseOfDll + mod.SizeOfImage);
	//SetUnhandledExceptionFilter(&MemoryLoggerFilter);
	AddVectoredExceptionHandler(1, &MemoryLoggerFilter);
	//__try {
#endif
#endif

		return WinMain(NULL, NULL, cmdline, 0);

#ifdef _WIN32
	//} __except (MemoryLoggerFilter(GetExceptionInformation())) {
	//}
#endif
}
