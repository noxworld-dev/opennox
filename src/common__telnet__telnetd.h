#ifndef NOX_PORT_COMMON_TELNET_TELNETD
#define NOX_PORT_COMMON_TELNET_TELNETD

#include <stdbool.h>
#include <stddef.h>

void nox_telnet_tick_578FC0();
bool nox_telnet_isActive_579740();
bool nox_telnet_isListening_5797E0();
void nox_telnet_broadcast_579750(wchar_t* str);
void nox_telnet_start_5797F0(unsigned short port);
void nox_telnet_stop_579830();
unsigned short nox_telnet_getPort_579850();

#endif // NOX_PORT_COMMON_TELNET_TELNETD
