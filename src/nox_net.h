#ifndef NOX_NET_H
#define NOX_NET_H

#include <stdbool.h>
#include <stdint.h>

typedef int32_t nox_socket_t;

#define NOX_NET_EADDRINUSE 10048
#define NOX_NET_EWOULDBLOCK 10035

#define NOX_AF_INET 2

#ifndef _NOX_IN_NET_C
extern bool debugNet;
extern bool nox_net_no_xor;
#endif // _NOX_IN_NET_C

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

int nox_net_init();
int nox_net_stop();

nox_socket_t nox_net_socket_tcp();
nox_socket_t nox_net_socket_udp();
nox_socket_t nox_net_socket_udp_broadcast();
void nox_net_close(nox_socket_t sockfd);
void nox_net_shutdown(nox_socket_t sockfd);
int nox_net_last_error();
int nox_net_error(nox_socket_t sockfd);

int nox_net_bind(nox_socket_t sockfd, struct nox_net_sockaddr_in* addr);

nox_socket_t nox_net_accept(nox_socket_t sockfd, struct nox_net_sockaddr_in* addr);
int nox_net_send(nox_socket_t sockfd, void* buffer, unsigned int length);
int nox_net_recv(nox_socket_t sockfd, void* buffer, unsigned int length);
int nox_net_sendto(nox_socket_t sockfd, void* buffer, unsigned int length, struct nox_net_sockaddr_in* addr);
int nox_net_recvfrom(nox_socket_t sockfd, void* buffer, unsigned int length, struct nox_net_sockaddr_in* addr);
int nox_net_recv_available(nox_socket_t s, unsigned int* out);
int nox_net_non_blocking(nox_socket_t s, int enabled);

#endif // NOX_NET_H
