#ifndef NOX_PORT_GAME2
#define NOX_PORT_GAME2

#include "defs.h"

char* nox_get_thing_name(int i);
nox_thing* nox_get_thing(int i);
wchar_t* nox_get_thing_pretty_name(int i);
wchar_t* nox_get_thing_desc(int i);
int nox_get_thing_pretty_image(int i);
int nox_xxx_getTTByNameSpriteMB_44CFC0(char* a1);
int sub_44D040(int i);
int sub_44D060(int a1);
int sub_44D090(int a1);
int nox_drawable_link_thing(nox_drawable* a1, int i);
nox_thing* sub_44D330(char* a1);
void sub_44D3A0();
void sub_44D5C0(int a1, int a2);
void sub_44D640();
int sub_44D660(char* a1);
int sub_44D7E0(int a1);
void sub_44D8C0();
void sub_44D8F0();
int nox_xxx_playDialogFile_44D900(char* a1, int a2);
int sub_44D930();
void sub_44D960();
int sub_44D970();
int sub_44D990();
void nox_video_stopAllFades_44E040();
int nox_video_inFadeTransition_44E0D0();
uint32_t* sub_44E110();
void sub_44E320();
int nox_client_getIntroScreenDuration_44E3B0();
int nox_xxx_playGMCAPsmth_44E3E0();
uint32_t* sub_44E560();
int nox_client_wndQuestBriefProc_44E630(int a1, int a2, int a3, int a4);
int nox_xxx_wndProc_44E6E0(int a1, int a2, int a3, int a4);
int sub_44E6F0(uint32_t* a1, int xLeft);
double sub_44E8B0();
int sub_44E8D0();
int nox_client_lockScreenBriefing_450160(int a1, int a2, char a3);
void sub_450580();
int sub_4505E0();
unsigned char sub_450750();
char sub_450760(char a1);
int sub_450960(const void* a1, const void* a2);
char* sub_450AD0(char* a1);
int sub_450AF0(int a1);
void nox_gui_setQuestStage_450B00(int a1);
int nox_gui_getQuestStage_450B10();
int sub_451920(uint32_t* a2);
void sub_451970();
int sub_451BE0(int a1);
int sub_451CA0(uint32_t* a1);
int sub_451F30(int a1, int a2);
int sub_451F90(int a1);
int sub_451FE0(int a1);
int sub_452010();
void sub_452050(uint32_t* a1);
int* sub_452120(int a1);
void sub_452190(int a1);
int* sub_4521A0(int a1);
int sub_4521F0();
int***** sub_452230();
char* nox_xxx_draw_452270(int a1);
int sub_4522A0(int a1);
uint32_t* nox_xxx_draw_452300(uint32_t* a1);
int sub_4523D0(void* a1);
int sub_452410(int a1);
int sub_452490(uint32_t* a1);
void sub_452510(int a3);
long long sub_452690(int a3, long long a4, int a5);
int sub_4526D0(int a1);
int sub_4526F0(int a1);
int* sub_452810(int a1, char a2);
int nox_thing_read_AVNT_452890(nox_memfile* a1, void* a2);
int nox_thing_skip_AVNT_452B00(nox_memfile* f);
int nox_thing_skip_AVNT_inner_452B30(nox_memfile* f);
int sub_452BD0(int a1, char* a2);
void nox_xxx_clientPlaySoundSpecial_452D80(int a1, int a2);
void sub_452DC0(int a1, int a2, int a3);
void sub_452E10(int a1, int a2, int a3);
int sub_452E90(uint32_t* a1, int a2);
int sub_452EB0(int* a1);
int sub_452EE0(int a1, int a2);
unsigned int sub_452F10(int a1, int a2);
int sub_452F50(int a1, int a2);
uint32_t* sub_452F80(int a1, int a2);
int sub_452FA0(int a1);
int sub_452FE0(int a1, int a2);
void sub_453050();
void nox_xxx____setargv_9_453060();
int sub_453070();
int sub_453080(char a1);
uint32_t* sub_4532E0();
int sub_453350(int a1, int a2);
int sub_4533D0(int a1, int a2, int a3, int a4);
int* sub_4535E0(int* a1);
int sub_4535F0(int a1);
char* sub_453600();
int sub_453610();
uint8_t* sub_453620(uint8_t* a1, char a2, int a3);
uint32_t* sub_453640(uint32_t* a1, int a2, int a3);
int sub_453660(int a1);
int sub_453690(int a1);
int sub_4536B0(uint32_t* a1);
int sub_453710();
char sub_453750();
uint32_t* sub_453B00();
int sub_453B80(int a1, int a2);
void sub_453F70(const void* a1);
char* sub_453F90();
int sub_453FA0(int a1, int a2, int a3);
int sub_454000(int a1, int a2);
int sub_454040(uint32_t* a1);
int sub_4540E0(int a1);
char sub_454120();
int nox_xxx_guiServerAccessLoad_4541D0(int a1);
int sub_454A90(int a1, int a2);
int nox_xxx_windowAccessProc_454BA0(int a1, int a2, int* a3, int a4);
int sub_455770();
int sub_4557D0(int a1);
int* sub_455800();
int sub_455920(wchar_t* a1);
void sub_455950(wchar_t* a1);
int sub_4559B0(wchar_t* a1);
int sub_455A00(int a1);
char sub_455A50(char a1);
int sub_455C10();
int sub_455CD0(uint8_t* a1, uint32_t* a2);
int sub_455E70(unsigned char a1);
int sub_455EE0();
int sub_455F10(int a1);
int sub_455F60();
int sub_456050();
int sub_456070();
int sub_4560D0(int a1, int a2);
int sub_456240();
int sub_456500();
int sub_456640(int a1, int a2);
char sub_456BB0(int a1);
wchar_t* sub_456D00(int a1, wchar_t* a2);
int* sub_456D60(int a1);
int sub_456E40(int a1, int a2);
int sub_456EA0(wchar_t* a1);
int sub_456F10(wchar_t* a1, int a2);
int sub_456FA0();
unsigned char sub_457120(int a1);
int sub_457140(int a1, wchar_t* a2);
int sub_4571A0(int a1, int a2);
int sub_4573A0();
void sub_4573B0();
int sub_457460(int a1);
int nox_xxx_guiServerOptionsTryHide_4574D0();
int sub_457B60(int a1);
int sub_457F30(int a1);
int nox_xxx_windowServerOptionsDrawProc_458500(uint32_t* a1, int a2);
int nox_xxx_guiServerOptionsProc_458590(int a1, int a2, int a3, int a4);
char sub_459150();
int sub_4593B0(int a1);
int sub_459560(int a1);
int sub_459700();
int* nox_xxx_guiServerOptionsHide_4597E0(int a1);
char* sub_459870();
int sub_459A40(char* a1);
char* sub_459AA0(void* a1);
int sub_459C30();
int sub_459D50(int a1);
int sub_459D60();
int sub_459D80(int a1);
int sub_459DA0();
int sub_459DB0(nox_drawable* dr);
void sub_459DD0(nox_drawable* dr, unsigned char a2);
void nox_xxx_cliRemoveHealthbar_459E30(nox_drawable* dr, unsigned char a2);
nox_drawable* nox_xxx_cliFirstMinimapObj_459EB0();
int nox_xxx_cliNextMinimapObj_459EC0(int a1);
nox_drawable* nox_xxx_cliGetSpritePlayer_45A000();
nox_drawable* sub_45A010(nox_drawable* dr);
nox_drawable* nox_xxx_sprite_45A030();
int sub_45A040(int a1);
nox_drawable* sub_45A060();
nox_drawable* nox_drawable_next_45A070(nox_drawable* a1);
nox_drawable* sub_45A090();
int sub_45A0A0(int a1);
void nox_xxx_sprite_45A110_drawable(nox_drawable* a1);
nox_drawable* nox_xxx_spriteLoadAdd_45A360_drawable(int thingInd, int a2, int a3);
void nox_xxx_spriteDeleteStatic_45A4E0_drawable(nox_drawable* dr);
void nox_xxx_spriteDeleteAll_45A5E0(int a1);
void sub_45A670(unsigned int a1);
nox_drawable* nox_xxx_netSpriteByCodeDynamic_45A6F0(int a1);
nox_drawable* nox_xxx_netSpriteByCodeStatic_45A720(int a1);
int nox_xxx_spriteSetActiveMB_45A990_drawable(int a1);
int nox_xxx_cliDestroyObj_45A9A0(int a1);
int* sub_45A9B0(int a1, int a2);
int sub_45AB40();
int nox_xxx_spriteSetFrameMB_45AB80(int a1, int a2);
int nox_xxx_guiSpellSortFn_45ABC0(const void* a1, const void* a2);
int nox_xxx_bookSetColor_45AC40();
void nox_client_toggleSpellbook_45AC70();
int nox_xxx_bookHideMB_45ACA0(int a1);
int nox_xxx_guiSpellSortList_45ADF0(int a1);
void nox_xxx_book_45B010(int a1);
int nox_xxx_bookWndProc_45B070(int a1, int a2);
int nox_xxx_bookClickSpell_45B1F0();
int nox_xxx_bookClickCreature_45B200();
int nox_xxx_book_45B210(int a1, int a2);
int nox_xxx_bookChildWndProcMB_45B360(uint32_t* a1, unsigned int a2);
int nox_xxx_bookListWndProc_45B5F0(int a1, unsigned int a2, unsigned int a3);
int nox_xxx_bookMoveToPage_45B930(int a1);
int nox_xxx_bookInit_45B9D0();
int nox_xxx_bookDrawIconFn_45CB30(uint32_t* a1);
int nox_xxx_bookWndFn_45CC10(uint32_t* a1, int a2, unsigned int a3);
int sub_45CFC0();
void nox_xxx_netSpellRewardCli_45CFE0(int a1, int a2, int a3, int a4);
void nox_xxx_netGuideRewardCli_45D140(int a1, int a2);
int* nox_xxx_bookSetForward_45D200(int* a1, int a2, int2* a3);
void nox_xxx_abilityReward_45D290(int a1, char* a2, int a3);
int sub_45D320(int a1);
int sub_45D400(int a1);
char* nox_xxx_clientQuestDisableAbility_45D4A0(int a1);
int sub_45D500(int a1);
uint32_t* sub_45D550(uint32_t* a1);
void nox_xxx_bookFillAll_45D570(int a1, int a2);
int sub_45D7D0(int* a1, int* a2);
void sub_45D810();
int sub_45D9B0();
int nox_xxx_guiSpellTargetClickSet_45D9D0(int a1);
int nox_xxx_guiSpell_45DA10(int a1);
void nox_client_invokeSpellSlot_45DA50(int a1);
void nox_xxx_clientStoreLastButton_45DAD0(int a1);
int nox_xxx_clientSendAbil_45DAF0(int a1);
int nox_xxx_clientSendSpell_45DB20(char* a1, int a2, char a3);
int sub_45DB90();
void nox_xxx_guiSpellTargetClickCheckSend_45DBB0();
void* nox_xxx_book_45DBE0(void* a1, int a2, int a3);
void nox_xxx_spellKeyPackSetSpell_45DC40(int a1, int a2, int a3);
int nox_xxx_bookSpellDrop_45DCA0(int a1, char a2, int a3, int a4, int* a5);
int nox_xxx_updateSpellIcons_45DDF0(int a1);
int nox_xxx_updateSpellIconDir_45DE10(int a1, int a2);
int nox_xxx_spellBoxPointToWnd_45DE60(int a1, int a2, int a3);
int nox_xxx_guiSpellSetCursor_45DF60(int a1, char a2);
int sub_45DFC0(int a1);
int nox_xxx_clientUpdateButtonRow_45E110(int a1);
int nox_xxx_buttonsGetSelectedRow_45E180();
int nox_xxx_quickbarButtonBookDraw_45EF30();
int sub_45EF40();
int nox_xxx_quickBarWnd_45EF50(int a1, int a2, unsigned int a3);
void nox_xxx_clientSwapQuickbarKeys_45F300(int a1, int a2, int a3);
void sub_45F390(int a1, int a2, int a3, int a4);
int nox_xxx_quickbarButtonBookWnd_45F450(int a1, unsigned int a2);
int sub_45F500(int a1, int a2);
int sub_45F520(int a1, unsigned int a2);
int sub_45F5D0(uint32_t* a1);
int nox_xxx_quickbarTrapUpDownProc_45F630(int a1, unsigned int a2);
int nox_xxx_quickbarTrapUpDownDraw_45F6F0(uint32_t* a1);
int nox_xxx_quickbarTrapButtonProc_45F7A0(uint32_t* a1, unsigned int a2, unsigned int a3);
int sub_45F890();
int nox_xxx_quickbar_45F8D0(int a1, int a2, int a3, int a4);
int sub_45F8F0();
void sub_45F900();
int nox_xxx_quickbarTrapProc_45FB90(int a1, unsigned int a2, int a3, int a4);
int nox_xxx_quickbarDrawFn_460000();
int nox_xxx_quickBarInitWindow_4601F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void* sub_4602F0();
void* sub_460380();
void nox_client_trapSetNext_4603A0();
void nox_client_trapSetPrev_4603F0();
int nox_client_trapSetSelect_4604B0(int a1);
int sub_4604E0();
int nox_client_spellSetNext_4604F0();
int nox_client_spellSetPrev_460540();
void nox_client_spellSetSelect_460590();
void sub_460630();
int nox_xxx_guiSpell_460650();
int sub_460660();
int nox_xxx_quickBarClose_4606B0();
void sub_460920();
int sub_460940(void* this);
int sub_460A10(int a1, int a2, int a3, char a4);
int sub_460B90(int a1);

void nox_video_fadeInScreen_44DAB0(int a1, int a2, void* a3);
void nox_video_fadeOutScreen_44DB30(int a1, int a2, void* a3);

#endif // NOX_PORT_GAME2