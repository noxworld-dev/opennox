#ifndef NOX_PORT_CLIENT_SYSTEM_CTRLEVNT
#define NOX_PORT_CLIENT_SYSTEM_CTRLEVNT

#include "common__savegame.h"
#include "defs.h"
#include "static_assert.h"

#ifndef NOX_CGO

#define NOX_KEYEVENT_MAX 137
typedef struct nox_keybind_t {
	const char* name;
	unsigned int key;
	const char* title_id;
	const wchar_t* title;
} nox_keybind_t;

#define NOX_BINDEVENT_MAX 41
typedef struct nox_bindevent_t {
	const char* name;
	unsigned int key;
	const wchar_t* title;
} nox_bindevent_t;

void nox_xxx_bindevent_initStrings_42EAE0();
#endif // NOX_CGO

#define NOX_CTRLEVENT_KEYS_NUM 8
typedef struct nox_ctrlevent_key_t nox_ctrlevent_key_t;
typedef struct nox_ctrlevent_key_t {
	unsigned int keys[NOX_CTRLEVENT_KEYS_NUM];    // 0, 0
	unsigned int keys_cnt;                        // 8, 32
	unsigned int field_9[NOX_CTRLEVENT_KEYS_NUM]; // 9, 36
	unsigned int field_9_cnt;                     // 17, 68
	nox_ctrlevent_key_t* field_18;                // 18, 72
	nox_ctrlevent_key_t* field_19;                // 19, 76
	nox_ctrlevent_key_t* field_20;                // 20, 80
	nox_ctrlevent_key_t* field_21;                // 21, 84
	unsigned char field_22_0;                     // 22, 88
	unsigned char field_22_1;                     // 22, 89
	unsigned short field_22_2;                    // 22, 90
	unsigned int frame;                           // 23, 92, // TODO: game frame
} nox_ctrlevent_key_t;
_Static_assert(sizeof(nox_ctrlevent_key_t) == 96, "wrong size of nox_ctrlevent_key_t structure!");

char* nox_xxx_keybind_nameByKey(unsigned int key);
unsigned int nox_xxx_keybind_keyByName(char* name);
char* nox_xxx_keybind_nameByTitle_42E960(wchar_t* title);
wchar_t* nox_xxx_keybind_titleByKey_42EA00(unsigned int a1);
wchar_t* nox_xxx_keybind_titleByKeyZero_42EA00(unsigned int a1);
char* nox_xxx_bindevent_bindNameByKey(unsigned int key);
unsigned int nox_xxx_bindevent_bindKeyByName(char* name);
char* nox_xxx_bindevent_bindNameByTitle_42EA40(wchar_t* title);
void nox_xxx_clientControl_42D6B0(nox_mouse_state_t* mouse, int a4);
void nox_ctrlevent_action_42E670(nox_ctrlevent_code code, uint32_t data);
void nox_ctrlevent_action_42E780(nox_ctrlevent_code code, uint32_t data);
int nox_ctrlevent_has_data_42D440(nox_ctrlevent_code code);
unsigned char nox_ctrlevent_data_size_42D450(nox_ctrlevent_code code);
nox_ctrlevent_key_t* nox_xxx_getBindKeysBuf_42CD70();

char* nox_xxx_netGetBuffSize_42CD50(uint8_t* a1);
void sub_42CD90();
void nox_client_writeConfigHotkeys_42CDF0(FILE* a1);
int nox_client_parseConfigHotkeysLine_42CF50(char* a1);
int nox_xxx_keyCheckWarrorKeys_42D460(nox_ctrlevent_code code);
int nox_xxx_keyCanPauseMode_42D4B0(nox_ctrlevent_code code);
void nox_xxx_netBuf_42D510();
void sub_42E8C0(int a1);
wchar_t* sub_42E8E0(int a1, int a2);
int nox_xxx_playerSaveInput_51A960(int a1, unsigned char* a2);
int sub_51AAA0(int a1, int a2, int a3);

#endif // NOX_PORT_CLIENT_SYSTEM_CTRLEVNT
