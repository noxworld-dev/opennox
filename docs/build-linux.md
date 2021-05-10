# Building for Linux

This is the main build procedure for Linux version.

## Installing Go compiler

### Fastest way

```
sudo snap install --classic go
```

### Longer way

See [official docs](https://golang.org/doc/install).

## Installing C compiler

```
sudo apt install gcc
```

## Installing other dependencies

```
sudo dpkg --add-architecture i386
sudo apt update
sudo apt install libsdl2-dev:i386 libopenal-dev:i386
```

## Building

```
cd src
./build_go.sh
```

This should produce `noxg` and `nox-server` binaries.
