#ifndef NOX_NET_H
#define NOX_NET_H

#include <stdint.h>

typedef uint32_t nox_net_in_addr;

char* nox_net_ip2str(nox_net_in_addr addr);

#endif // NOX_NET_H
