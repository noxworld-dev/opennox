#ifndef NOX_PORT_CLIENT_SYSTEM_CTRLEVNT
#define NOX_PORT_CLIENT_SYSTEM_CTRLEVNT

#include "defs.h"

#define NOX_KEYEVENT_MAX 137
typedef struct nox_keybind_t {
	const char*  name;
	unsigned int key;
	const char*    title_id;
	const wchar_t* title;
} nox_keybind_t;

#define NOX_BINDEVENT_MAX 41
typedef struct nox_bindevent_t {
	const char* name;
	unsigned int key;
	const wchar_t* title;
} nox_bindevent_t;

char* nox_xxx_keybind_nameByKey(unsigned int key);
unsigned int nox_xxx_keybind_keyByName(const char* name);
char*  nox_xxx_keybind_nameByTitle_42E960(wchar_t* title);
wchar_t* nox_xxx_keybind_titleByKey_42EA00(unsigned int a1);
wchar_t* nox_xxx_keybind_titleByKeyZero_42EA00(unsigned int a1);
void nox_xxx_bindevent_initStrings_42EAE0();
void nox_xxx_clientControl_42D6B0(nox_mouse_state_t* mouse, int a4);
void nox_ctrlevent_action_42E670(nox_ctrlevent_code code, _DWORD data);
void nox_ctrlevent_action_42E780(nox_ctrlevent_code code, _DWORD data);
int nox_ctrlevent_has_data_42D440(nox_ctrlevent_code code);
unsigned __int8 nox_ctrlevent_data_size_42D450(nox_ctrlevent_code code);

#endif // NOX_PORT_CLIENT_SYSTEM_CTRLEVNT
