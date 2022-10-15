#ifndef NOX_PORT_SERVER_NETWORK_PLAYBACK
#define NOX_PORT_SERVER_NETWORK_PLAYBACK

#include "defs.h"

int nox_xxx_replayStartSave_4D3370(char* a1);
void nox_xxx_replayStopSave_4D33B0();
int nox_xxx_replayFileOpen_4D34C0(char* a1);
void nox_xxx_replayStopReadMB_4D3530();
void nox_xxx_replay_4D3860(void* a1);
int nox_xxx_replayStartReadingOrSaving_4D38D0();
void nox_xxx_replayWriteFrame_4D39B0();
int nox_xxx_replayTickMB_4D3580_net_playback(int a1);

#endif // NOX_PORT_SERVER_NETWORK_PLAYBACK
