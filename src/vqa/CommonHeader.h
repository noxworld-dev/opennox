#pragma once
#include <SDL2/SDL.h>

#include <array>

#include <cassert>
#include <climits>
#include <cstdint>
#include <list>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef unsigned char byte;
typedef unsigned long dword;

using namespace std;

// Expose a few functions in the platform.c for C++.
extern "C" unsigned int nox_get_ticks();
extern "C" void nox_sleep(unsigned int ms);
