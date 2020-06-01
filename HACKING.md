# Hacking guideline

## Use pure C, not C++

The codebase is still not completely understood. Doing it manually requires too much effort, so instead, we use C parser to analyze the code and refactor based on this information. 

C++ is insanely complicated as a language, thus it's very hard to find a good and extensible parser and analyzer which can extract the information we need.

So for now all the code in this port must be in plain C, **no C++ is allowed**. An exception is only done for *non-critical* and *self-contained* code, e.g. movie playback.

Furthemore, includes of such code must be surrounded by defines which allow easy disabling of such a code in a way that do not affect the main codebase.

## Use open standards

Nox was originally written for Windows, DirectX and other proprietary technologies.

In this port we aim to build a **cross-platform Nox version**.

Thus, we mainly use CMake and GCC for the build, SDL2 for graphics and OpenAL for audio. This ensures that we can run on Windows, Linux, Mac and even the browser (WASM).

If a need for another external library is needed, such library MUST be open source under such a license which does not encumbers the original code (no copyleft license are allowed). Examples of allowed licenses are MIT, BSD, MPL, examples of disallowed licenses are GPL (including LGPL) and any commercial licenses.

## Keep the code close to the original

When reading the codebase it may be tempting to rewrite stuff: remove unnecessary calls, unused functions or slightly change the logic.

However, this may change the Nox behavior which can make it deviate from the original in unexpected ways.

There may be others not so obvious reasons to avoid thsse kind of changes: unused code may help the analysis, original variables can be used by mods (direct memory access), etc.

So the rule of thumb is to keep the code and data structures as close as possible to the original.

When renaming a procedure name, stick to the naming scheme aka `<module>_<component>_<action>_<original_address>`. Example: when renaming a procedure named `sub_112233`, it should be named as `nox_network_playerinfo_112233`, where `nox` is the module (another possible module name is `mix` or `unimod`), `network` is the component, `playerinfo` is the action, and `112233` is the original HEX address of the procedure in the original Nox binary.

## Keep it compatible

The codebase must be **compatible with the original Nox** version: it must still support reading original Nox files, speak its network protocols, etc.

This doesn't imply that the code may not be _extended_ to support new functionality, e.g. new mod APIs, new file formats, new network protocols, etc. But theese extensions should be written in such a way that they do not enter in conflict with the original Nox codebase, i.e. they should allow graceful degradation in case if it isn't supported by the original clients or servers.

## Keep it compilable and runnable

Before commiting a change into `dev` please make sure that the code is AT LEAST compilable and runnable. The project is complicated, so we can't ask for testing for any possible regressions, but it should pass at least some basic checks.

The code in the `master` branch should be compilable, runnable, (mostly) regression-checked and working on ALL supported platforms:

- Linux + GCC
- Windows + MinGW
- Windows + VS2017
- WASM
- (others may be added)
