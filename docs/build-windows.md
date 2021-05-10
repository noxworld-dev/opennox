# Building for Windows

This is the main build procedure for Windows version.

Note that this build mode requires GCC for Windows (MinGW), since MSVC compiler cannot be used with Go.

For cross-compilation from Linux to Windows, see [this page](./build-windows-on-linux.md).

## Installing Go compiler

See [official docs](https://golang.org/doc/install).

## Installing MinGW compiler and other dependencies

_TODO: provide a clear guideline_

In the meantime, you can try using [MSYS2](https://www.msys2.org/) to install MinGW-w64, SDL and OpenAL.

Or install [Mingw-w64](http://mingw-w64.org/doku.php) directly and roughly follow the [install dependencies](./build-windows-on-linux.md)
adjusting the steps for Windows.

## Building

```
chdir src
build_go_win.bat
```

This should produce `noxg.exe` and `nox-server.exe` binaries.
