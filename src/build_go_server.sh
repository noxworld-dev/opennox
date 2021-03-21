#!/bin/bash
set -e
GOPRIVATE=github.com/noxworld-dev/xwis CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)" CGO_ENABLED=1 GOARCH=386 go build -v -tags server -o nox_server
