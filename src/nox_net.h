#ifndef NOX_NET_H
#define NOX_NET_H

#include <stdbool.h>
#include <stdint.h>

typedef int32_t nox_socket_t;

#define NOX_NET_EADDRINUSE 10048
#define NOX_NET_EWOULDBLOCK 10035

#define NOX_AF_INET 2

typedef uint32_t nox_net_in_addr;

struct nox_net_sockaddr {
	uint16_t sa_family;
	char sa_data[14];
};

struct nox_net_sockaddr_in {
	uint16_t sin_family;
	uint16_t sin_port;
	nox_net_in_addr sin_addr;
	char sin_zero[8];
};

char* nox_net_ip2str(nox_net_in_addr addr);

nox_socket_t nox_net_socket_udp_broadcast();

int nox_net_sendto(nox_socket_t sockfd, void* buffer, unsigned int length, struct nox_net_sockaddr_in* addr);

#endif // NOX_NET_H
