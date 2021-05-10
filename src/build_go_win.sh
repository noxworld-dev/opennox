#!/bin/bash
set -e
export GOOS=windows
export GOARCH=386
export CGO_ENABLED=1
export CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)"
export CXX_FOR_TARGET=i686-w64-mingw32-g++
export CC_FOR_TARGET=i686-w64-mingw32-gcc
export CC=i686-w64-mingw32-gcc
go build -v -ldflags "-H windowsgui" -o noxg.exe
go build -v -tags server -o nox-server.exe
