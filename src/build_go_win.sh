#!/bin/bash
set -e
CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)" CGO_ENABLED=1 GOARCH=386 GOOS=windows CXX_FOR_TARGET=i686-w64-mingw32-g++ CC_FOR_TARGET=i686-w64-mingw32-gcc CC=i686-w64-mingw32-gcc go build -o noxg.exe
