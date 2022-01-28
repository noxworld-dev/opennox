# Coding guideline

## Use pure C, not C++

The codebase is still not completely understood. Doing it manually requires too much effort, so instead, we use C parser to analyze the code and refactor based on this information. 

C++ is insanely complicated as a language, thus it's very hard to find a good and extensible parser and analyzer which can extract the information we need.

So for now all the code in this port must be in plain C, **no C++ is allowed**, with the exception of *non-critical* and *self-contained* code, e.g. movie playback.

Furthermore, `#include` of such code must be surrounded by defines which allow easy disabling of such a code in a way that does not affect the main codebase.

## Use open standards

Nox was originally written for Windows, DirectX and other proprietary technologies.

In this port we aim to build a **cross-platform Nox version**.

Thus, we mainly use CMake and GCC for the build, SDL2 for graphics and OpenAL for audio. This ensures that we can run on Windows, Linux, Mac and even the browser (WASM).

If another external library is needed, such library MUST be open source under such a license which does not encumber the original code (no copyleft license are allowed). Examples of allowed licenses are MIT, BSD, MPL. Examples of disallowed licenses are GPL (including LGPL) and any commercial licenses.

## Keep the code close to the original

When reading the codebase, it may be tempting to rewrite code: remove unnecessary calls, unused functions, or slightly change the logic.

However, this may change the Nox behavior which can make it deviate from the original in unexpected ways.

There may be other not so obvious reasons to avoid these kinds of changes: unused code may help the analysis, original variables can be used by mods (direct memory access), etc.

So the rule of thumb is to keep the code and data structures as close as possible to the original.

See [Cleanup/Refactoring guide](docs/refactoring.md) before making any changes to the codebase.

## Keep it compatible

The codebase must be **compatible with the latest released Nox** version (1.2b): it must still support reading original Nox files, speak its network protocols, etc.

This doesn't imply that the code may not be _extended_ to support new functionality, e.g. new mod APIs, new file formats, new network protocols, etc. But these extensions should be written in such a way that they do not enter in conflict with the original Nox codebase, i.e. they should allow graceful degradation in case if it isn't supported by the original clients or servers.

## Keep it compilable and runnable

Before committing a change into `dev` please make sure that the code is AT LEAST compilable and runnable. The project is complicated, so we can't ask for testing for any possible regressions, but it should pass at least some basic checks.

The code in the `master` branch should be compilable, runnable, (mostly) regression-checked and working on ALL supported platforms:

- Linux + GCC
- Windows + MinGW
- Windows + VS2017
- WASM
- (others may be added)

## Pull Request guidelines

The large majority of current work(this is subject to change) is renaming of functions and variables, restoration of data structures, and restoration of code flow from assembly-like to more C-like.

The former of these typically touches many files in multiple locations without making any logical changes, while the latter two can introduce subtle changes in logic and the generated machine code.

Given the general lack of clarity in the code, it is often necessary to review existing commits when looking for newly introduced issues, which often involves undoing changes within the commit in order to find the cause of any given issue.

Mixing renames with restorations into the same commit makes the process of looking for issues unnecessarily tedious.

It is thus advised to create separate commits for renames and for restoration of code flow or data structures whenever possible.

## Code style guide
[The code style guide]() is subject to change as the project evolves.
