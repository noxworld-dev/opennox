#include <stdio.h>

int fscanf_go0(FILE* f, const char* fmt) { return fscanf(f, fmt); }
int fscanf_go1(FILE* f, const char* fmt, void* a1) { return fscanf(f, fmt, a1); }
