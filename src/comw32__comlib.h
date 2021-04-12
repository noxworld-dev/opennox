#ifndef NOX_PORT_COMW32_COMLIB
#define NOX_PORT_COMW32_COMLIB

#ifndef _WIN32
#include <sys/socket.h>
#else
#include <winsock.h>
#endif

#include "defs.h"

int  nox_xxx_netRecv_552020(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from); // idb

#endif // NOX_PORT_COMW32_COMLIB
