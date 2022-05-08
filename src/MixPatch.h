#ifndef NOX_MIXPATCH_H
#define NOX_MIXPATCH_H

#include "defs.h"

void init_data_mix();

void OnLibraryNotice_257();
void OnLibraryNotice_259(uint32_t arg1);
void OnLibraryNotice_260(uint32_t arg1, uint32_t arg2, uint32_t arg3);
void OnLibraryNotice_261();
void OnLibraryNotice_263(uint32_t arg1);
void OnLibraryNotice_264(uint32_t arg1);
void OnLibraryNotice_265(unsigned int arg1, unsigned int arg2, int arg3);
void OnKeyboardEvent(nox_keyboard_btn_t* ev);
void OnLibraryNotice_418();
void OnLibraryNotice_420(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4);
int MixRecvFromReplacer(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from); // idb
void OnLibraryNotice_stub(int a1, ...);

void sub_980523(nox_object_t* a1);
nox_object_t* sub_9805EB(nox_object_t* a1);

int mix_recvfrom(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from);

#endif // NOX_MIXPATCH_H
