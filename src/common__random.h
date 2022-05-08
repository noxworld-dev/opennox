#ifndef NOX_PORT_COMMON_RANDOM
#define NOX_PORT_COMMON_RANDOM

int nox_xxx_replayWriteRndCounter_415F30(int fd);
int nox_xxx_replayReadeRndCounter_415F50(int fd);
int nox_common_randomInt_415FA0(int a1, int a2);
int nox_common_randomIntMinMax_415FF0(int min, int max, const char* file, int line);
double nox_common_randomFloat_416030(float a1, float a2);
double nox_common_randomFloatXxx_416090(float a1, float a2);

#endif // NOX_PORT_COMMON_RANDOM
