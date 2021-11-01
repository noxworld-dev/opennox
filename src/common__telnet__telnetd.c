#include "common__telnet__telnetd.h"
#include "client__system__parsecmd.h" // for nox_server_parseCmdText_443C80
#include "GAME1.h"
#include "common__log.h"
#include "common__strman.h"
#ifndef _WIN32
#include <sys/socket.h>
#include <arpa/inet.h>
#else // _WIN32
#include <winsock2.h>
#endif // _WIN32
extern unsigned int nox_frame_xxx_2598000;

#define NOX_TELNET_SOCK_MAX 4
#define NOX_TELNET_SOCK_BUF 1024

typedef struct {
	nox_socket_t sock;
	unsigned char data[NOX_TELNET_SOCK_BUF];
	unsigned short field_1028; // 1028
	unsigned short field_1030; // 1030
	unsigned short field_1032; // 1032
	unsigned short field_1034; // 1034
	nox_net_in_addr addr; // 1036
	unsigned int field_1040;
} nox_telnet_sock_t;

nox_socket_t nox_telnet_listener = -1;
nox_telnet_sock_t nox_telnet_socks_2516484[NOX_TELNET_SOCK_MAX] = {0};
unsigned char nox_telnet_send_buf[NOX_TELNET_SOCK_BUF] = {0}; // size is a guess
unsigned char nox_telnet_recv_buf[NOX_TELNET_SOCK_BUF] = {0};
unsigned char nox_telnet_line_buf[NOX_TELNET_SOCK_BUF] = {0}; // size is a guess
unsigned int nox_telnet_listening = 0;
unsigned short nox_telnet_port = 0;
unsigned short nox_telnet_conns = 0;
int nox_telnet_err = 0;

const char* nox_telnet_prompt = "> ";

//----- (00579740) --------------------------------------------------------
bool nox_telnet_isActive_579740() { return nox_telnet_conns != 0; }

//----- (005797E0) --------------------------------------------------------
bool nox_telnet_isListening_5797E0() { return nox_telnet_listening == 1; }

//----- (00578F20) --------------------------------------------------------
void nox_telnet_setErr_578F20(int e) {
	nox_telnet_err = e;
}

//----- (00579850) --------------------------------------------------------
unsigned short nox_telnet_getPort_579850() { return nox_telnet_port; }

//----- (00578FF0) --------------------------------------------------------
void nox_telnet_accept_578FF0() {
	struct nox_net_sockaddr_in addr;
	addr.sin_family = NOX_AF_INET;
	addr.sin_port = 0;
	addr.sin_addr = 0;
	memset(addr.sin_zero, 0, 8);

	// find a free socket struct in the buffer
	int ind = -1;
	for (int i = 0; i < NOX_TELNET_SOCK_MAX; i++) {
		if (nox_telnet_socks_2516484[i].sock == -1) {
			ind = i;
			break;
		}
	}
	if (ind < 0) {
		return;
	}
	nox_telnet_sock_t* cur = &nox_telnet_socks_2516484[ind];

	// accept the connection
	cur->sock = nox_net_accept(nox_telnet_listener, &addr);
	if (cur->sock == -1) {
		if (nox_net_error(nox_telnet_listener) != NOX_NET_EWOULDBLOCK) {
			nox_telnet_setErr_578F20(-4);
		}
		return;
	}
	cur->addr = addr.sin_addr;
	if (nox_net_non_blocking(cur->sock, 1) == -1) {
		nox_telnet_setErr_578F20(-5);
	}
	++nox_telnet_conns;

	// log the connection
	wchar_t* stel = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 142);
	wchar_t* sstart = nox_strman_loadString_40F1D0("ConnectionStarted", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 142);
	char* saddr = nox_net_ip2str(cur->addr);
	nox_xxx_networkLog_printf_413D30("%S: %S %s", stel, sstart, saddr);

	// password prompt
	char buf[128];
	wchar_t* spwd = nox_strman_loadString_40F1D0("Password", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 146);
	nox_sprintf(buf, "%S", spwd);
	nox_net_send(cur->sock, buf, strlen(buf));

	cur->field_1040 |= 1;
}

//----- (00578F30) --------------------------------------------------------
void nox_telnet_shutdown_578F30() {
	if (nox_telnet_listener != -1) {
		nox_net_shutdown(nox_telnet_listener);
		nox_net_close(nox_telnet_listener);
		nox_telnet_listener = -1;
	}
	nox_telnet_conns = 0;
	for (int i = 0; i < NOX_TELNET_SOCK_MAX; i++) {
		nox_telnet_sock_t* cur = &nox_telnet_socks_2516484[i];
		if (cur->sock != -1) {
			nox_net_shutdown(nox_telnet_listener); // TODO: shouldn't it be cur->sock?
			nox_net_close(cur->sock);
		}
		cur->sock = -1;
		cur->data[0] = 0;
		cur->field_1028 = 0;
		cur->field_1030 = 0;
		cur->field_1032 = 0;
		cur->field_1040 = 0;
	}
}

//----- (00579350) --------------------------------------------------------
void nox_telnet_closeInd_579350(int i) {
	nox_telnet_sock_t* cur = &nox_telnet_socks_2516484[i];
	if (cur->sock != -1) {
		nox_net_close(cur->sock);
		--nox_telnet_conns;
	}
	cur->sock = -1;
	cur->data[0] = 0;
	cur->field_1028 = 0;
	cur->field_1030 = 0;
	cur->field_1032 = 0;
	cur->field_1040 = 0;
}

//----- (00579750) --------------------------------------------------------
void nox_telnet_broadcast_579750(wchar_t* str) {
	if (!str) {
		return;
	}
	char* buf = nox_telnet_send_buf;
	for (int i = 0; i < NOX_TELNET_SOCK_MAX; i++) {
		nox_telnet_sock_t* cur = &nox_telnet_socks_2516484[i];
		if (cur->sock == -1 || (cur->field_1040 & 1) != 0) {
			continue;
		}
		nox_sprintf(buf, "%S", str);
		char* v2 = &buf[strlen(buf)];
		v2[0] = '\r';
		v2[1] = '\n';
		v2[2] = 0;
		nox_net_send(cur->sock, buf, strlen(buf));
	}
}

//----- (00578E10) --------------------------------------------------------
int nox_telnet_listen_578E10() {
	struct nox_net_sockaddr_in addr;
	addr.sin_family = NOX_AF_INET;
	addr.sin_port = htons(nox_telnet_port);
	addr.sin_addr = 0;
	memset(addr.sin_zero, 0, 8);

	nox_telnet_listener = nox_net_socket_tcp();
	if (nox_telnet_listener == -1) {
		return -1;
	}
	if (nox_net_bind(nox_telnet_listener, &addr) == -1) {
		return -2;
	}
	if (nox_net_non_blocking(nox_telnet_listener, 1) == -1) {
		nox_telnet_setErr_578F20(-5);
		return -5;
	}
	if (listen(nox_telnet_listener, 1) == -1) {
		nox_net_error(nox_telnet_listener);
		nox_telnet_setErr_578F20(-3);
	}
	nox_telnet_conns = 0;
	for (int i = 0; i < NOX_TELNET_SOCK_MAX; i++) {
		nox_telnet_sock_t* cur = &nox_telnet_socks_2516484[i];
		cur->sock = -1;
		cur->data[0] = 0;
		cur->field_1028 = 0;
		cur->field_1030 = 0;
		cur->field_1032 = 0;
		cur->field_1040 = 0;
	}
	return 0;
}

//----- (00579700) --------------------------------------------------------
int nox_telnet_checkLine_579700(nox_telnet_sock_t* cur) {
	if (!cur)
		return 0;
	int v1 = cur->field_1028;
	int v2 = cur->field_1030;
	if (v1 == v2)
		return 0;
	while (cur->data[v1] != '\n') {
		++v1;
		if (v1 == 1024)
			v1 = 0;
		if (v1 == v2)
			return 0;
	}
	return 1;
}

//----- (005793B0) --------------------------------------------------------
char* nox_telnet_recv_5793B0(nox_telnet_sock_t* cur, int ind) {
	unsigned int argp = 0;
	if (nox_net_recv_available(cur->sock, &argp) == -1 || (int)(argp + cur->field_1032) > 1024)
		return 0;
	int res = nox_net_recv(cur->sock, nox_telnet_recv_buf, sizeof(nox_telnet_recv_buf));
	if (res != -1) {
		int n = res;
		if (!n) {
			nox_telnet_closeInd_579350(ind);
			char* saddr = nox_net_ip2str(cur->addr);
			wchar_t* sterm = nox_strman_loadString_40F1D0("ConnectionTerminated", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 211);
			wchar_t* stel = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 211);
			nox_xxx_networkLog_printf_413D30("%S: %S %s", stel, sterm, saddr);
			return 0;
		}
		if (cur->field_1040 & 1) {
			int end = n;
			if (n > 0) {
				for (int i = 0; i < n; i++) {
					unsigned char c = nox_telnet_recv_buf[i];
					if (c == '\n' || c == '\r') {
						--end;
					}
				}
			}
			memset(nox_telnet_line_buf, '*', end);
			nox_telnet_line_buf[end] = 0;
			nox_net_send(cur->sock, nox_telnet_line_buf, end);
		} else {
			nox_net_send(cur->sock, nox_telnet_recv_buf, n);
		}
		int v11 = cur->field_1030;
		unsigned char* b = &cur->data[v11];
		if (v11 + n < 1024) {
			memcpy(b, nox_telnet_recv_buf, n);
			cur->field_1030 += n;
		} else {
			unsigned int v14 = 1024 - v11;
			unsigned int v13 = v14;
			memcpy(b, nox_telnet_recv_buf, v14);
			cur->field_1030 = 0;
			int v15 = n - v14;
			if (v15 > 0) {
				memcpy(cur->data, nox_telnet_recv_buf, 4 * ((unsigned int)v15 >> 2) + (((uint8_t)n - (uint8_t)v13) & 3));
			}
			cur->field_1030 = n - v13;
		}
		cur->field_1032 += n;
	} else if (nox_net_error(cur->sock) != NOX_NET_EWOULDBLOCK) {
		nox_telnet_closeInd_579350(ind);
		char* saddr = nox_net_ip2str(cur->addr);
		wchar_t* sterm = nox_strman_loadString_40F1D0("ConnectionTerminated", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 273);
		wchar_t* stel = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 273);
		nox_xxx_networkLog_printf_413D30("%S: %S %s", stel, sterm, saddr);
		return 0;
	}
	if (!nox_telnet_checkLine_579700(cur)) {
		return 0;
	}
	int i = cur->field_1028;
	int j = 0;
	while (1) {
		if (i == 1024) {
			i = 0;
		}
		switch (cur->data[i]) {
			case '\b': // BS
			case 0x7F: // DEL
				if (j <= 0) {
					++i;
					break;
				}
				--j;
				++i;
				continue;
			case '\n': // LF
				nox_telnet_line_buf[j] = 0;
				cur->field_1032 -= j + 1;
				cur->field_1028 = i + 1;
				return nox_telnet_line_buf;
			case '\r': // CR
				++i;
				break;
			default:
				nox_telnet_line_buf[j] = cur->data[i];
				++j;
				++i;
				break;
		}
	}
}

//----- (005797F0) --------------------------------------------------------
void nox_telnet_start_5797F0(unsigned short port) {
	if (nox_telnet_listening != 1) {
		if (port <= 1024) {
			port = 18500;
		}
		nox_telnet_port = port;
		nox_telnet_listen_578E10();
		nox_telnet_listening = 1;
	}
}

//----- (00579830) --------------------------------------------------------
void nox_telnet_stop_579830() {
	if (nox_telnet_listening) {
		nox_telnet_shutdown_578F30();
		nox_telnet_listening = 0;
	}
}

//----- (00579190) --------------------------------------------------------
void nox_telnet_handle_579190() {
	wchar_t buf[128];
	for (int i = 0; i < NOX_TELNET_SOCK_MAX; i++) {
		nox_telnet_sock_t* cur = &nox_telnet_socks_2516484[i];
		if (cur->sock == -1) {
			continue;
		}
		char* b = nox_telnet_recv_5793B0(cur, i);
		if (!b) {
			continue;
		}
		if (!*b) {
			nox_net_send(cur->sock, nox_telnet_prompt, strlen(nox_telnet_prompt));
			continue;
		}
		if (strlen(b) >= 127) {
			b[127] = 0;
		}
		nox_swprintf(buf, L"%S", b);
		if (cur->field_1040 & 1) {
			wchar_t* pass = nox_xxx_sysopGetPass_40A630();
			cur->field_1040 &= 0xFFFFFFFE;
			if (nox_wcscmp(pass, (const wchar_t*)getMemAt(0x5D4594, 2523748)) && _nox_wcsicmp(buf, pass)) {
				char* saddr = nox_net_ip2str(cur->addr);
				wchar_t* bpass = nox_strman_loadString_40F1D0("BadPassword", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 371);
				wchar_t* stel = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 371);
				nox_xxx_networkLog_printf_413D30("%S: %S %s", stel, bpass, saddr);
				nox_telnet_closeInd_579350(i);
				continue;
			}
			nox_net_send(cur->sock, "\r\n", 2);
			char* saddr = nox_net_ip2str(cur->addr);
			wchar_t* succ = nox_strman_loadString_40F1D0("LoginSuccessful", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 381);
			wchar_t* stel = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 381);
			nox_xxx_networkLog_printf_413D30("%S: %S %s", stel, succ, saddr);
		} else {
			nox_server_parseCmdText_443C80(buf, 0);
		}
		nox_net_send(cur->sock, nox_telnet_prompt, strlen(nox_telnet_prompt));
	}
}

//----- (00578FC0) --------------------------------------------------------
void nox_telnet_tick_578FC0() {
	if (nox_telnet_listening) {
		nox_telnet_accept_578FF0();
		if (nox_telnet_conns > 0) {
			if ((unsigned char)nox_frame_xxx_2598000 & 1) {
				nox_telnet_handle_579190();
			}
		}
	}
}
