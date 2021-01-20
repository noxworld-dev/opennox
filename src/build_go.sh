#!/bin/bash
set -e
CGO_CFLAGS_ALLOW="(-fshort-wchar)|(-fno-strict-aliasing)|(-fno-strict-overflow)" CGO_ENABLED=1 GOARCH=386 go build -o nox_go 2>&1 | tee build_go.log
