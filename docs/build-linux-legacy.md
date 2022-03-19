# Building for Linux (C only)

This is a legacy build mode that excludes Go dependencies.

Note that it will also exclude a lot of new features implemented in the [main version](./build-linux.md).

## Installing C compiler

```
sudo apt install gcc cmake build-essential
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
mkdir cmake-build-manual
cd cmake-build-manual
cmake ..
make -j 4
mv out nox
```

This should produce `nox` binary.
