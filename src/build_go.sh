#!/bin/bash
set -e
CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)" CGO_ENABLED=1 GOARCH=386 go build -v -o nox_go
