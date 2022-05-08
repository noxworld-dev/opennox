#ifndef NOX_PLATFORM_H
#define NOX_PLATFORM_H

int nox_platform_rand();
void nox_platform_srand(unsigned int seed);
void nox_platform_srand_time();

unsigned int nox_platform_get_ticks();

#endif // NOX_PLATFORM_H
