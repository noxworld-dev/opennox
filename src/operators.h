#ifndef NOX_SUBFUNCS_H
#define NOX_SUBFUNCS_H

#undef LOBYTE
#undef HIBYTE
#define LOBYTE(x) (((uint8_t*)(&x))[0])
#define SLOBYTE(x) (((signed char*)(&x))[0])
#define BYTE1(x) (((uint8_t*)(&x))[1])
#define SBYTE1(x) (((signed char*)(&x))[1])
#define BYTE2(x) (((uint8_t*)(&x))[2])
#define HIBYTE(x) (((uint8_t*)(&x))[sizeof(x) - 1])
#define BYTE4(x) (((uint8_t*)(&x))[4])

#undef LOWORD
#undef HIWORD
#define LOWORD(x) (((uint16_t*)(&x))[0])
#define SLOWORD(x) (((short*)(&x))[0])
#define HIWORD(x) (((uint16_t*)(&x))[1])
#define SHIWORD(x) (((short*)(&x))[1])
#define WORD2(x) (((uint16_t*)(&x))[2])
#define SWORD2(x) (((short*)(&x))[2])

#undef LODWORD
#undef HIDWORD
#define LODWORD(x) (((uint32_t*)(&x))[0])
#define SLODWORD(x) (((int*)(&x))[0])
#define HIDWORD(x) (((uint32_t*)(&x))[1])
#define SHIDWORD(x) (((int*)(&x))[1])

#define __PAIR64__(x, y) ((((uint64_t)(x)) << 32) | ((uint32_t)(y)))
#define __SPAIR64__(x, y) ((long long)((((uint64_t)(x)) << 32) | ((uint32_t)(y))))

#endif // NOX_SUBFUNCS_H
