#!/bin/bash
set -e
export GOOS=windows
export GOARCH=386
export CGO_ENABLED=1
export CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)"
export CXX_FOR_TARGET=i686-w64-mingw32-g++
export CC_FOR_TARGET=i686-w64-mingw32-gcc
export CC=i686-w64-mingw32-gcc

GIT_SHA="$(git rev-parse --short HEAD)"
VERSION="$(git name-rev --tags --name-only $(git rev-parse HEAD))"
if [ "$VERSION" = "undefined" ]; then
  VERSION="v1.4.x"
fi
NOX_LDFLAGS="-X 'main.Commit=$GIT_SHA' -X 'main.Version=$VERSION'"

go build -v -ldflags="-H windowsgui $NOX_LDFLAGS" -o noxg.exe
go build -v -ldflags="$NOX_LDFLAGS" -tags server -o nox-server.exe
go build -v -ldflags="$NOX_LDFLAGS" -o noxtools.exe ./cmd/noxtools
echo "Build complete: $VERSION ($GIT_SHA)"
