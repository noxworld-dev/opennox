#ifndef NOX_PORT_CLIENT_SYSTEM_CTRLEVNT
#define NOX_PORT_CLIENT_SYSTEM_CTRLEVNT

#include "../../defs.h"

char* nox_xxx_bindevent_42EAE0();
void nox_xxx_clientControl_42D6B0(nox_mouse_state_t* mouse, int a4);
void nox_ctrlevent_action_42E670(nox_ctrlevent_code code, _DWORD data);
void nox_ctrlevent_action_42E780(nox_ctrlevent_code code, _DWORD data);
int nox_ctrlevent_has_data_42D440(nox_ctrlevent_code code);
unsigned __int8 nox_ctrlevent_data_size_42D450(nox_ctrlevent_code code);

#endif // NOX_PORT_CLIENT_SYSTEM_CTRLEVNT