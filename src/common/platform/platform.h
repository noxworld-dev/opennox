#ifndef NOX_PLATFORM_H
#define NOX_PLATFORM_H

int nox_platform_rand();
void nox_platform_srand(unsigned int seed);
void nox_platform_srand_time();
unsigned int nox_platform_time_seed();

unsigned int nox_platform_get_ticks();
void nox_platform_sleep(unsigned int ms);

#endif // NOX_PLATFORM_H
