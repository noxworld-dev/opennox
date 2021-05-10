#!/bin/bash
set -e
export GOARCH=386
export CGO_ENABLED=1
export CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)"
go build -v -o noxg
go build -v -tags server -o nox-server
go build -v -o noxtools ./cmd/noxtools
