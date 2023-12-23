# Building for Linux

This is the main build procedure for Linux version.

## Installing Go compiler

Your Go installation must be at least version 1.21.

If you have the supported version in your repository, you can install Go from there (`golang` package).

Otherwise, use Snap version
```bash
sudo snap install --classic go
```
or see [official docs](https://golang.org/doc/install) for manual installation.

## Installing C compiler

```bash
sudo apt install gcc-multilib
```

## Installing other dependencies

```bash
sudo dpkg --add-architecture i386
sudo apt update
sudo apt install libsdl2-dev:i386 libopenal-dev:i386
```

## Building

```bash
cd src
go run ./internal/noxbuild
```

This should produce `opennox`, `opennox-hd` and `opennox-server` binaries.
