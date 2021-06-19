#!/bin/bash
set -e
export GOARCH=386
export CGO_ENABLED=1
export CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)"

GIT_SHA="$(git rev-parse --short HEAD)"
VERSION="$(git name-rev --tags --name-only $(git rev-parse HEAD))"
if [ "$VERSION" = "undefined" ]; then
  VERSION="v1.7.x"
fi
NOX_LDFLAGS="-X 'main.Commit=$GIT_SHA' -X 'main.Version=$VERSION'"

go build -v -ldflags="$NOX_LDFLAGS" -o opennox
go build -v -ldflags="$NOX_LDFLAGS" -tags server -o opennox-server
go build -v -ldflags="$NOX_LDFLAGS" -o noxtools ./cmd/noxtools
echo "Build complete: $VERSION ($GIT_SHA)"
