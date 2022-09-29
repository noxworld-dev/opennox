#ifndef NOX_PORT_GAME1_3
#define NOX_PORT_GAME1_3

#include "defs.h"

void nox_client_xxx_switchChatMap_43B510();
void sub_43B670();
int sub_43B6D0();
unsigned short* sub_43BC10(wchar_t* a1, unsigned char a2);
int nox_sprintAddrPort_43BC80(const char* addr, unsigned short port, char* dst);
int sub_43BDB0();
void nox_game_decStateInd_43BDC0();
void nox_game_addStateCode_43BDD0(int a1);
int nox_game_getStateCode_43BE10();
int sub_43BE30();
void sub_43BE40(int a1);
int sub_43BE50_get_video_mode_id();
wchar_t* get_video_mode_string(int v1);
void nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(int* w, int* h, int* d);
int nox_game_switchStates_43C0A0();
void nox_game_checkStateWol_43C260();
void nox_game_checkStateMenu_43C2F0();
void nox_gui_freeAnimation_43C570(nox_gui_animation* p);
nox_gui_animation* nox_gui_makeAnimation_43C5B0(nox_window* win, int x1, int y1, int x2, int y2, int in_dx, int in_dy,
												int out_dx, int out_dy);
int sub_43C650();
int sub_43C6E0();
int nox_client_isConnected_43C700();
int sub_43C710();
void nox_xxx_gameSetCliConnected_43C720(int a1);
int nox_xxx_netGet_43C750();
int sub_43C790();
int sub_43C7A0(int a1);
int nox_xxx_netHandleCliPacket_43C860(int a1, unsigned char* a2, int a3, void* a4);
int sub_43CC80();
void sub_43CEB0();
int sub_43CF40();
int sub_43CF70();
void sub_43D2D0();
void sub_43D3C0(int a1, int a2);
void sub_43D440();
void sub_43D650();
void sub_43D680();
void sub_43D6A0();
int nox_xxx_musicStartPlay_43D6C0(int* a1);
int sub_43D8E0();
void sub_43D990();
void sub_43D9B0(int a1, int a2);
void sub_43D9E0(int4* a1);
int sub_43DA80();
void sub_43DAD0();
int sub_43DB20();
int sub_43DB30(int a1);
char* sub_43DB40(int a1);
int sub_43DB60();
void sub_43DBA0();
int sub_43DBD0();
int sub_43DBE0();
void sub_43DC00();
int sub_43DC10();
int sub_43DC30();
int sub_43DC40();
int sub_43DD10(int* a1);
void sub_43DD70(int a1, int a2);
void nox_game_SetCliDrawFunc(void* a1);
int sub_43DE40(void* a1);
void nox_game_exit_xxx2();
uint32_t* nox_xxx_gui_43E1A0(int a1);
int sub_43E8C0(int a1);
void sub_43E8E0(int a1);
void sub_43E910(int a1);
int sub_43E940(void* a1);
void sub_43E9F0();
int sub_43EA20(void* a1);
int sub_43EC10();
int sub_43EC30(void* a1);
int sub_43ECB0(void* a1);
int sub_43ED00(uint32_t* a1);
int sub_43EE00(void* a1);
int sub_43EFD0(void* a1);
int sub_43F010(void* a1);
int sub_43F030(int a1);
int sub_43F050();
int sub_43F060(uint32_t* a1);
int sub_43F0D0();
int sub_43F0E0(uint32_t* a1);
int sub_43F130();
int nox_xxx_guiFontHeightMB_43F320(void* a1);
void* nox_xxx_guiFontPtrByName_43F360(char* a1);
void nox_draw_enableTextSmoothing_43F670(int a1);
int nox_xxx_drawString_43F6E0(void* a1, wchar_t* a2, int a3, int a4);
int nox_draw_drawStringHL_43F730(void* a1, wchar_t* a2, int a3, int a4);
int nox_xxx_drawStringStyle_43F7B0(void* a1, wchar_t* a2, int a3, int a4);
int nox_xxx_drawGetStringSize_43F840(void* a1, wchar_t* a2, int* a3, int* a4, int a5);
int nox_draw_getFontAdvance_43F9E0(void* a1, wchar_t* a2, int a3);
int nox_xxx_bookGetStringSize_43FA80(void* a1, wchar_t* a2, int* a3, int* a4, int a5);
int nox_xxx_drawStringWrap_43FAF0(void* a1, wchar_t* str, int a3, int a4, int a5, int a6);
int nox_xxx_drawStringWrapHL_43FD00(void* a1, wchar_t* a2, int a3, int a4, int a5, int a6);
int nox_xxx_bookDrawString_43FA80_43FD80(void* a1, wchar_t* a2, int a3, int a4, int a5, int a6);
int nox_draw_setTabWidth_43FE20(int a1);
void nox_client_clearScreen_440900();
void nox_xxx_netServerCmd_440950_empty();
void sub_4417E0(wchar_t* a1, const char* a2);
int nox_xxx_doExecrul_4438A0(int a1);
wchar_t* sub_445450();
int nox_xxx_drawMessageLines_445530();
int nox_xxx_guiChatMode_4456E0(int* a1);
int nox_xxx_guiChatShowHide_445730(int a1);
int sub_445770();
void nox_xxx_quitDialogYes_445B20();
int nox_xxx_quitDialogNo_445B30();
void sub_445BA0();
int nox_xxx_wndDrawQuitMenu_445BC0(uint32_t* a1);
void sub_445C20();
uint32_t* sub_445FF0();
void sub_446060();
void sub_4460A0(int a1);
void nox_client_quit_4460C0();
int nox_xxx_serverIsClosing_446180();
unsigned int nox_gui_xxx_check_446360();
void sub_446380();
int nox_motd_4463E0(int a1);
void* sub_446490(int a1);
void* sub_4464D0(int a1, uint32_t* a2);
int sub_4464F0(int a1, uint32_t* a2);
void sub_446520(int a1, const void* a2, int a3);
int sub_446580(int a1);
int nox_xxx_guiMotdLoad_4465C0();
int sub_4466C0(int a1, int a2, int a3, int a4);
char* sub_4466F0(char* a1, uint8_t* a2);
uint8_t* nox_xxx_motdAddSomeTextMB_446730(uint8_t* a1);
int sub_446780();
void nox_xxx_motd_4467F0();
int sub_446950();
wchar_t* sub_4469D0(int a1);
int sub_446A90();
char* sub_446BC0(int a1);
int sub_446C10(int a1, int a2);
int sub_446C70();
int sub_446C90();
wchar_t* sub_446CC0(int a1);
void sub_446D50();
void sub_446D80(char* a1);
char* sub_446E20(char* a1, uint8_t* a2);
wchar_t* sub_446E60();
char* sub_446EB0();
char* sub_446F40(int a1);
const wchar_t* sub_4471A0(const char* a1, int a2, int a3, int a4);
const wchar_t* sub_447250(const char* a1, int a2, int a3, int a4);
int sub_447310(int a1, int a2);
void sub_447380(const char* a1, char* a2);
unsigned int sub_447410(char* a1);
int sub_4475E0();
void sub_447600();
int sub_447BD0();
int sub_447BF0(uint32_t* a1, int a2, unsigned int a3, int a4);
int sub_447C70(int a1, int a2, int a3, int a4);
int sub_447CC0(int a1, unsigned int a2, int* a3, int a4);
int sub_448140(int yTop);
int sub_448240(uint32_t* a1, uint8_t* a2);
int sub_4482D0(int a1, int a2, int a3, int a4, uint16_t* a5);
int sub_448340(int a1, unsigned int a2);
void sub_448380();
int sub_4483A0(int a1, int a2);
int sub_448450();
int sub_448490();
void sub_4484D0(wchar_t* a1, int a2, int a3);
int sub_448550(int a1);
void sub_448570(const char* a1, char a2, int a3);
int sub_448620(int a1);
int sub_448650(uint8_t* a1, wchar_t* a2);
int sub_448680(wchar_t* a1, char* a2);
int sub_448F00(uint32_t* a1, int a2, int a3, int a4);
int sub_448F60(uint32_t* a1, int a2, int a3, int a4);
int sub_448FC0(int a1, int a2);
int sub_449280();
int sub_4493D0(int a1, int a2, int* a3, int a4);
void sub_4494A0();
int nox_xxx_guiServerListLoad_449530();
int sub_449E00(wchar_t* a1);
int sub_449E30(wchar_t* a1);
int sub_449E60(char a1);
void sub_449EA0(int a1);
void sub_44A360(int a1);
void sub_44A400();
int sub_44A4A0();
void sub_44A4B0();
int sub_44A4E0();
char* sub_44A520(int a1);
int sub_44AA40();
int sub_44AA70();
int sub_44AAC0();
int sub_44AAD0(uint32_t* a1, int a2, int a3, int a4);
int sub_44AB30(int a1, unsigned int a2, int* a3, int a4);
int sub_44AF70();
uint32_t* sub_44AFB0(int a1, int a2, int a3);
void nox_xxx____setargv_4_44B000();
int sub_44B0F0(int a1, int a2, int* a3, int a4);
int sub_44B940(uint32_t* a1, int a2, nox_memfile* f);
int nox_xxx_parse_Armor_44BA60(const char* a1);
int sub_44BAC0(const char* a1);
int sub_44BB20(const char* a1);

void sub_446AD0(int (*fnc)(void));
void* nox_xxx_dialogMsgBoxCreate_449A10(nox_window* win, wchar_t* a2, wchar_t* text, int a4, void* a5, void* a6);

#endif // NOX_PORT_GAME1_3
