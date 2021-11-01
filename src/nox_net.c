//+build none

#define _NOX_IN_NET_C
#include "nox_net.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#ifndef _WIN32
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#else // _WIN32
#include <winsock2.h>
#endif // _WIN32

bool debugNet = 0;
bool nox_net_no_xor = 0;

char* nox_net_ip2str(nox_net_in_addr compat_addr) {
	struct in_addr addr;
	addr.s_addr = compat_addr;
	return inet_ntoa(addr);
}

int nox_net_init() {
	debugNet = getenv("NOX_DEBUG_NET") != 0;
	nox_net_no_xor = getenv("NOX_NET_NO_XOR") != 0;
#ifdef _WIN32
	struct WSAData WSAData;
	return WSAStartup(0x101u, &WSAData);
#else  // !_WIN32
	return 0;
#endif // _WIN32
}

int nox_net_stop() {
#ifdef _WIN32
	return WSACleanup();
#else  // !_WIN32
	return 0;
#endif // _WIN32
}

int last_socket_error = 0;
int nox_net_last_error() { return last_socket_error; }
int nox_net_error(nox_socket_t sockfd) { return last_socket_error; }

int nox_net_socket(int domain, int type, int protocol) {
#ifdef __EMSCRIPTEN__
	static int fd = 1024;
	return fd++;
#else
	return socket(domain, type, protocol);
#endif
}

nox_socket_t nox_net_socket_tcp() { return nox_net_socket(AF_INET, SOCK_STREAM, 0); }

nox_socket_t nox_net_socket_udp() { return nox_net_socket(AF_INET, SOCK_DGRAM, 0); }

void nox_net_close(nox_socket_t s) { close(s); }

void nox_net_shutdown(nox_socket_t s) {
#ifdef _WIN32
	shutdown(s, SD_BOTH);
#else  // !_WIN32
	shutdown(s, SHUT_RDWR);
#endif // _WIN32
}

nox_socket_t nox_net_accept(nox_socket_t sockfd, struct nox_net_sockaddr_in* addr) {
	struct sockaddr_in std_addr;
	unsigned int std_len = sizeof(struct sockaddr_in);
	nox_socket_t ret = accept(sockfd, &std_addr, &std_len);
	if (addr) {
		addr->sin_family = NOX_AF_INET;
		addr->sin_port = std_addr.sin_port;
		addr->sin_addr = std_addr.sin_addr.s_addr;
		memset(addr->sin_zero, 0, 8);
	}
	return ret;
}

int nox_net_send(nox_socket_t sockfd, void* buffer, unsigned int length) { return send(sockfd, buffer, length, 0); }

int nox_net_recv(nox_socket_t sockfd, void* buffer, unsigned int length) { return recv(sockfd, buffer, length, 0); }

// TODO: some better way to hook it for WASM
#ifdef __EMSCRIPTEN__
void build_server_info(void* arg);
#endif // __EMSCRIPTEN__

int nox_net_sendto(nox_socket_t sockfd, void* buffer, unsigned int length, struct nox_net_sockaddr_in* addr) {
#ifdef __EMSCRIPTEN__
	unsigned int dest = addr->sin_addr;
	unsigned char* p = buffer;

	// broadcast packet
	if (dest == 0xffffffff) {
		if (p[2] == 12) {
			EM_ASM_({network.isready() && network.listServers($0, $1)}, *(unsigned int*)(p + 8), sockfd);
		}
		return length;
	}

	return EM_ASM_INT(
		{
			network.sendto($3, $2, $4, Module.HEAPU8.slice($0, $0 + $1));
			return $1;
		},
		buffer, length, dest, sockfd, ntohs(addr->sin_port));
#else  // __EMSCRIPTEN__
	struct sockaddr_in std_addr;
	std_addr.sin_family = AF_INET;
	std_addr.sin_port = addr->sin_port;
	std_addr.sin_addr.s_addr = addr->sin_addr;
	memset(std_addr.sin_zero, 0, 8);
	return sendto(sockfd, buffer, length, 0, &std_addr, 16);
#endif // __EMSCRIPTEN__
}

int nox_net_recvfrom(nox_socket_t sockfd, void* buffer, unsigned int length, struct nox_net_sockaddr_in* addr) {
#ifdef __EMSCRIPTEN__
	int ret;
	ret = EM_ASM_INT(({
						 const[remote, port, data] = network.recvfrom($4);
						 if (remote == = null)
							 return -1;
						 const length = Math.min(data.length, $1);
						 Module.HEAPU8.set(new Uint8Array(data, 0, length), $0);
						 if ($2) {
							 Module.HEAPU32[$2 >> 2] = remote;
						 }
						 if ($3) {
							 Module.HEAPU8[$3] = port >> 8;
							 Module.HEAPU8[$3 + 1] = port >> 0;
						 }
						 return length;
					 }),
					 buffer, length, addr ? &addr->sin_addr : NULL, addr ? &addr->sin_port : NULL, sockfd);
	if (addr)
		addr->sin_family = AF_INET;
	return ret;
#else  // !__EMSCRIPTEN__
	struct sockaddr_in std_addr;
	unsigned int std_len = sizeof(struct sockaddr_in);
	int ret = recvfrom(sockfd, buffer, length, 0, &std_addr, &std_len);
	if (addr) {
		addr->sin_family = NOX_AF_INET;
		addr->sin_port = std_addr.sin_port;
		addr->sin_addr = std_addr.sin_addr.s_addr;
		memset(addr->sin_zero, 0, 8);
	}
	return ret;
#endif // __EMSCRIPTEN__
}

int nox_net_bind(nox_socket_t sockfd, struct nox_net_sockaddr_in* addr) {
	int ret;
#ifdef __EMSCRIPTEN__
	static long updater = -1;

	EM_ASM_({ network.bind($0); }, sockfd);

	if (updater == -1)
		updater = emscripten_set_interval(build_server_info, 1000, NULL);

	ret = 0;
#else  // !__EMSCRIPTEN__
	struct sockaddr_in std_addr;
	std_addr.sin_family = AF_INET;
	std_addr.sin_port = addr->sin_port;
	std_addr.sin_addr.s_addr = addr->sin_addr;
	memset(std_addr.sin_zero, 0, 8);

	ret = bind(sockfd, &std_addr, 16);
#endif // __EMSCRIPTEN__
	if (ret >= 0)
		return ret;

	switch (errno) {
	case EADDRINUSE:
		last_socket_error = NOX_NET_EADDRINUSE;
		break;
	default:
		abort();
		break;
	}

	return -1;
}

int nox_net_setsockopt(nox_socket_t s, int level, int opt, const void* value, unsigned int len) {
#ifdef __EMSCRIPTEN__
	return 0;
#else
	return setsockopt(s, level, opt, value, len);
#endif
}

nox_socket_t nox_net_socket_udp_broadcast() {
	nox_socket_t sock = nox_net_socket(AF_INET, SOCK_DGRAM, 0);
	if (sock <= 0) {
		return sock;
	}
#ifndef __EMSCRIPTEN__
	int32_t optval = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &optval, 4) == -1) {
		close(sock);
		return -1;
	}
#endif // __EMSCRIPTEN__
	return sock;
}

int nox_net_recv_available(nox_socket_t s, unsigned int* out) {
#ifdef __EMSCRIPTEN__
	*out = EM_ASM_INT({ return network.available($0); }, s);
	return 0;
#else // !__EMSCRIPTEN__
#ifdef _WIN32
	return ioctlsocket(s, FIONREAD, out);
#else  // !_WIN32
	return ioctl(s, FIONREAD, out);
#endif // _WIN32
#endif // __EMSCRIPTEN__
}

int nox_net_non_blocking(nox_socket_t s, int enabled) {
	int ret = 0;
#ifndef __EMSCRIPTEN__
#ifdef _WIN32
	ret = ioctlsocket(s, FIONBIO, &enabled);
#else  // !_WIN32
	ret = ioctl(s, FIONBIO, &enabled);
#endif // _WIN32
#endif // __EMSCRIPTEN__
	return ret;
}
