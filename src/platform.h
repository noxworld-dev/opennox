#ifndef NOX_PLATFORM_H
#define NOX_PLATFORM_H

int nox_rand();
void nox_srand(unsigned int seed);
void nox_srand_time();

unsigned int nox_get_ticks();
void nox_sleep(unsigned int ms);

#endif // NOX_PLATFORM_H
