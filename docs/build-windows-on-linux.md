# Building for Windows on Linux

This is the main build procedure for Windows version cross-compiled on Linux.

For building on Windows, see [this page](./build-windows.md).

## Installing Go compiler

### Fastest way

```
sudo snap install --classic go
```

### Longer way

See [official docs](https://golang.org/doc/install).

## Installing C cross-compiler

```
sudo dpkg --add-architecture i386
sudo apt update
sudo apt install gcc-multilib gcc-mingw-w64
```

## Installing other dependencies

### SDL for MinGW

```
cd /tmp
curl -so ./sdl2.tar.gz https://www.libsdl.org/release/SDL2-devel-2.0.14-mingw.tar.gz
tar -xzf ./sdl2.tar.gz
sudo mv ./SDL2-2.0.14/i686-w64-mingw32/include/* /usr/i686-w64-mingw32/include/
sudo mv ./SDL2-2.0.14/i686-w64-mingw32/lib/* /usr/i686-w64-mingw32/lib/
```

### OpenAL

```
cd /tmp
curl -so openal.zip https://openal-soft.org/openal-binaries/openal-soft-1.21.1-bin.zip
unzip ./openal.zip
sudo mv ./openal-soft-1.21.1-bin/include/* /usr/i686-w64-mingw32/include/
sudo mv ./openal-soft-1.21.1-bin/libs/Win32/* /usr/i686-w64-mingw32/lib/
sudo ln -s ./libOpenAL32.dll.a /usr/i686-w64-mingw32/lib/libOpenAL.dll.a
```

## Building

```
make build-client-win
```

This should produce `opennox.exe` and `opennox-hd.exe` binaries.
