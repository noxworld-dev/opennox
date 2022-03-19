# Building for Windows (C only, MinGW)

This is a legacy build mode that excludes Go dependencies and uses MinGW instead of MSVC.

Note that it will also exclude a lot of new features implemented in the [main version](./build-windows.md).
Since you already have to go through installing MinGW, you might go a small step further
and build the [main version](./build-windows.md) that includes more features.

For building with MSVC, see [this page](./build-windows-legacy-msvc.md).

## Installing MinGW compiler and other dependencies

_TODO: provide a clear guideline_

In the meantime, you can try using [MSYS2](https://www.msys2.org/) to install MinGW-w64, SDL and OpenAL.

Or install [Mingw-w64](http://mingw-w64.org/doku.php) directly and roughly follow the [install dependencies](./build-windows-on-linux.md)
adjusting the steps for Windows.

## Building

_TODO: provide a clear guideline_

In the meantime, you could roughly follow [this section](./build-linux-legacy.md).
