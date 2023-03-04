# Building for Windows

This is the main build procedure for Windows version.

Note that this build mode requires GCC for Windows (MinGW), since MSVC compiler cannot be used with Go.

For cross-compilation from Linux to Windows (including WSL), see [this page](./build-windows-on-linux.md).

## Installing Go compiler

See [official docs](https://go.dev/dl/).

To check that installation was successful, open `cmd.exe` and write `go version`.
It should print the version you installed.

## Installing MSYS2, MinGW and other dependencies

1. Install [MSYS2](https://www.msys2.org/).
2. Run MSYS2 shell (search for `MSYS2 MSYS` shortcut in Start menu).
3. Update default packages: `pacman -Syu`. Confirm by typing `Y`, when asked. 
   If it asks for a restart and closes after the update, reopen the shell and update again.
4. Install dependencies: `pacman -S --needed git base-devel mingw-w64-i686-toolchain mingw-w64-i686-SDL2 mingw-w64-i686-openal`
   (confirm by selection with Enter, then confirms installation with typing `Y`).
5. Add Go compiler to MSYS2 `PATH` variable: `echo 'export PATH="/c/Program Files/Go/bin/:$PATH"' >> ~/.bashrc`
6. Restart the shell again to apply `PATH` changes.
7. Check if Go compiler is detected: `go version`.

## Downloading the project

### As a ZIP file

Download [the latest source](https://github.com/noxworld-dev/opennox/archive/refs/heads/dev.zip) and extract it to some directory.

We will assume the project is unpacked to `C:\Dev\opennox` for this guide. Prefer path without spaces and non-English characters.

### Using Git

1. Install [Git for Windows](https://gitforwindows.org).
   Click "next" for all the steps - defaults are good already.
2. Install [TortoiseGit](https://tortoisegit.org/download/).
   When asked for a name and email, either fill it in, or skip by checking the box.
   It's only used when sending changes to the project.
3. Create a directory for projects, let's say `C:\Dev\`.
4. Right click on empty space in the new folder, select "Git Clone...".
5. Paste the project URL: `https://github.com/noxworld-dev/opennox.git`.
6. Check the "Branch" box, write `dev` to the field.
7. Click OK, wait for the project to download.

## Building

Run MINGW32 shell (search for `MSYS2 MINGW32` or `MSYS2 MinGW x86` shortcut in Start menu).

NOTE: This is a different shell shortcut, not the one used for updates!

Assuming OpenNox was downloaded into `C:\Dev\opennox`:

```bash
cd /c/Dev/opennox/src
go run ./internal/noxbuild
```

You should see that the project dependencies are being downloaded and compiled.

During this process you way see a lot of scary warnings. Don't panic! This is normal.

Build may take a while, especially when building for the first time. Be patient.

If you hit issues, see troubleshooting section below.

Once finished, it should produce `opennox.exe`, `opennox-hd.exe` and `opennox-server.exe` binaries in `C:\Dev\opennox\src`.

### Troubleshooting

#### gcc not found

Make sure you start the `MSYS2 MINGW32` shell, not `MSYS2 MSYS` (or any other).

#### Cannot find OpenAL32

1. Go to MSYS2 installation directory (`C:\msys64` by default).
2. Open folder `mingw32\lib`.
3. Find files `libopenal.a` and `libopenal.dll.a`.
4. Make a copy of both files with a new names: `libopenal32.a` and `libopenal32.dll.a`.
5. Rebuild the project.

#### Following builds are still slow

First, `noxbuild` builds all binaries: legacy, HD and server.

You can set it to build only one of them. For example, for HD version only:

```
go run ./internal/noxbuild client-hd
```

For legacy only:

```
go run ./internal/noxbuild client
```

This should make it much faster, but it may still take a few minutes, unfortunately.

## Running

You also need a few DLLs for these binaries to work.

1. Create new folder for OpenNox, let's say `C:\Games\OpenNox`.
2. Copy following binaries from `C:\Dev\opennox\src`:
   - `opennox.exe`
   - `opennox-hd.exe`
   - `opennox-server.exe`
3. Copy following DLLs from `C:\msys64\mingw32\bin`:
   - `libgcc_s_dw2-1.dll`
   - `libopenal-1.dll`
   - `libstdc++-6.dll`
   - `libwinpthread-1.dll`
   - `SDL2.dll`
4. Run `opennox.exe` or `opennox-hd.exe`.
   - If it complains about more DDLs - copy them from MSYS.
   - If it says that Nox directory not found - it works!
     Check [this guide](https://mod.io/g/nox/r/how-to-install-opennox-windows) to set Nox game path.
