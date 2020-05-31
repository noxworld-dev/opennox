# Hacking guideline

## Use pure C, not C++

The codebase is still not completely understood. Doing it manually requires too much effort, so instead, we use C parser to analyze the code and refactor based on this information. 

C++ is insanely complicated as a language, thus it's very hard to find a good and extensible parser and analyzer which can extract the information we need.

So for now all the code in this port must be in plain C, **no C++ is allowed**. An exception is only done for *non-critical* and *self-contained* code, e.g. movie playback.

## Use open standards

Nox was originally written for Windows, DirectX and other proprietary technologies.

In this port we aim to build a **cross-platform Nox version**.

Thus, we mainly use CMake and GCC for the build, SDL2 for graphics and OpenAL for audio. This ensures that we can run on Windows, Linux, Mac and even the browser (WASM).

## Keep the code close to the original

When reading the codebase it may be tempting to rewrite stuff: remove unnecessary calls, unused functions or slightly change the logic.

However, this may change the Nox behavior which can make it deviate from the original in unexpected ways.

There may be others not so obvious reasons to avoid thsse kind of changes: unused code may help the analysis, original variables can be used by mods (direct memory access), etc.

So the rule of thumb is to keep the code and data structures as close as possible to the original.

## Keep it compatible

The codebase must be **compatible with the original Nox** version: it must still support reading original Nox files, speak its network protocols, etc.

This doesn't imply that the code may not be _extended_ to support new functionality, e.g. new mod APIs, new file formats, new network protocols, etc.