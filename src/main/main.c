#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include "../windows_compat.h"
#endif
#include "../common/fs/nox_fs.h"

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#if defined(__EMSCRIPTEN__)
extern int main()
#elif defined(_WIN32)
int main(int argc, char* argv[])
#else
extern int main(int argc, char* argv[])
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

	nox_fs_set_progname("nox.js");
	strcpy(cmdline, "nox.js -noskip -nolimit -nothread -sleep");

	if (chdir("assets")) {
		fprintf(stderr, "Failed to enter Nox directory.\n");
		return 1;
	}
#else // !__EMSCRIPTEN__
	nox_fs_set_progname(argv[0]);
	strcpy(cmdline, argv[0]);

	for (int i = 1; i < argc; i++)
		sprintf(cmdline + strlen(cmdline), " %s", argv[i]);
#endif // __EMSCRIPTEN__

	return WinMain(cmdline);
}
