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
  VERSION="v1.8.x"
fi
NOX_LDFLAGS="-X 'main.Commit=$GIT_SHA' -X 'main.Version=$VERSION'"
NOX_LDFLAGS_GUI="-H windowsgui -X 'main.Commit=$GIT_SHA' -X 'main.Version=$VERSION'"
NOX_GCFLAGS="-trimpath=$(pwd)"
NOX_ASMFLAGS="-trimpath=$(pwd)"

go build -v -ldflags="${NOX_LDFLAGS_GUI}" -gcflags="${NOX_GCFLAGS}" -asmflags="${NOX_ASMFLAGS}" -o opennox.exe ./cmd/opennox
go build -v -ldflags="${NOX_LDFLAGS_GUI}" -gcflags="${NOX_GCFLAGS}" -asmflags="${NOX_ASMFLAGS}" -tags highres -o opennox-hd.exe ./cmd/opennox
go build -v -ldflags="${NOX_LDFLAGS}" -gcflags="${NOX_GCFLAGS}" -asmflags="${NOX_ASMFLAGS}" -tags server -o opennox-server.exe ./cmd/opennox
go build -v -ldflags="${NOX_LDFLAGS}" -gcflags="${NOX_GCFLAGS}" -asmflags="${NOX_ASMFLAGS}" -o noxtools.exe ./cmd/noxtools
echo "Build complete: $VERSION ($GIT_SHA)"
