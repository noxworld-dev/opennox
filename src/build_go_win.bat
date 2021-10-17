@echo off
echo Building Nox for Win/i386, please be patient...
if not exist "C:\TDM-GCC-32\" (
     echo "Error: TDM-GCC (i686) installation folder wasn't found."
     exit
)
set CGO_CFLAGS_ALLOW=.*
set CGO_ENABLED=1
set GOARCH=386
set GOOS=windows
set CXX_FOR_TARGET=g++
set CC_FOR_TARGET=gcc
set CC=gcc
set CGO_CFLAGS=-D_TDM -g -O2
set PATH=%PATH%;C:\TDM-GCC-32\bin;C:\TDM-GCC-32\mingw32\bin
go build -v -ldflags "-H windowsgui" -o opennox.exe ./cmd/opennox
go build -v -ldflags "-H windowsgui" -tags highres -o opennox-hd.exe ./cmd/opennox
go build -v -tags server -o opennox-server.exe ./cmd/opennox
go build -v -o noxtools.exe ./cmd/noxtools
pause
