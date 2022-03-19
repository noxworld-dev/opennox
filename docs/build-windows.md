# Building for Windows

This is the main build procedure for Windows version.

Note that this build mode requires GCC for Windows (MinGW), since MSVC compiler cannot be used with Go.

For cross-compilation from Linux to Windows (including WSL), see [this page](./build-windows-on-linux.md).

## Installing Go compiler

See [official docs](https://golang.org/doc/install).

## Installing MSYS2, MinGW and other dependencies

1. Install [MSYS2](https://www.msys2.org/).
2. Run MSYS2 shell (search for `MSYS2 MSYS` shortcut in Start menu).
3. Update default packages: `pacman -Syu`.
4. Install dependencies: `pacman -S --needed git base-devel mingw-w64-i686-toolchain mingw-w64-i686-SDL2 mingw-w64-i686-openal`
   (confirm by selection with Enter, then confirms installation with typing `Y`).
5. Add Go compiler to MSYS2 `PATH` variable: `echo 'export PATH="/c/Program Files/Go/bin/:$PATH"' >> .bashrc`

## Building

Run MinGW x86 shell (search for `MSYS2 MinGW x86` shortcut in Start menu).

Assuming OpenNox was cloned into `C:\Dev\opennox`:

```bash
cd /c/Dev/opennox/src
go run ./internal/noxbuild
```

This should produce `opennox.exe`, `opennox-hd.exe` and `opennox-server.exe` binaries.
