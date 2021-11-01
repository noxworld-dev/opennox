//+build safe

void* nox_memcpy_go(void* dst, void* src, unsigned int size);
void* nox_memcpy(void* dst, const void* src, unsigned int size) { return nox_memcpy_go(dst, src, size); }

int nox_memcmp_go(void* ptr1, void* ptr2, unsigned int size);
int nox_memcmp(const void* ptr1, const void* ptr2, unsigned int size) { return nox_memcmp_go(ptr1, ptr2, size); }

unsigned int nox_strlen_go(char* ptr);
unsigned int nox_strlen(const char* ptr) { return nox_strlen_go(ptr); }

char* nox_strcpy_go(char* dst, char* src);
char* nox_strcpy(char* dst, const char* src) { return nox_strcpy_go(dst, src); }

char* nox_strcat_go(char* dst, char* src);
char* nox_strcat(char* dst, const char* src) { return nox_strcat_go(dst, src); }

int nox_strcmp_go(char* str1, char* str2);
int nox_strcmp(const char* str1, const char* str2) { return nox_strcmp_go(str1, str2); }
