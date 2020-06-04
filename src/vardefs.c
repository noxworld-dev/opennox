#include "client/shell/wolapi/wolchat.h"
#include "client/system/parsecmd.h"
#include "common/object/modifier.h"
#include "server/object/die/die.h"
#include "server/object/pickdrop/pickup.h"
#include "server/system/cscrfunc.h"

#include "client/gui/gamewin/psscript.h"
#include "common/wolapi/wolstate.h"

#include "client/drawable/update/dball.h"
#include "client/drawable/update/drainup.h"
#include "client/drawable/update/healup.h"
#include "client/drawable/update/manabomb.h"
#include "client/drawable/update/mmislup.h"
#include "client/drawable/update/mtailup.h"
#include "client/drawable/update/sparklup.h"
#include "client/drawable/update/telwake.h"
#include "client/drawable/update/vortexup.h"

#include "proto.h"

void sub_57F634();
void nullsub_45();
void nullsub_46();
void nullsub_47();
void nullsub_48();
void nullsub_62();
void nullsub_65();
void nullsub_66();
void nullsub_67();
void nullsub_68();
void nullsub_69();
void nullsub_70();
_DWORD dword_5d4594_3798784 = 0;
_DWORD dword_5d4594_1599636 = 0;
_DWORD dword_5d4594_3799540 = 0;
_DWORD dword_5d4594_4668 = 0;
_DWORD dword_5d4594_1046492 = 0;
_DWORD dword_587000_133480 = &byte_5D4594[1049220];
_DWORD dword_5d4594_830224 = 0;
_DWORD dword_5d4594_814980 = 0;
_DWORD dword_5d4594_3804664 = 0;
_DWORD dword_5d4594_1045516 = 0;
_DWORD dword_5d4594_3804656 = 0;
_DWORD dword_5d4594_3804672 = 0;
_DWORD dword_5d4594_1045684 = 0;
_DWORD dword_5d4594_1307784 = 0;
_DWORD dword_5d4594_3798844 = 0;
_DWORD dword_5d4594_2650652 = 0;
_DWORD dword_5d4594_1217448 = 0;
_DWORD dword_5d4594_1320940 = 0;
_DWORD dword_5d4594_815004 = 0;
_DWORD dword_5d4594_815012 = 0;
_DWORD dword_5d4594_1062480 = 0;
_DWORD dword_5d4594_832484 = 0;
_DWORD dword_5d4594_3798796 = 0;
_DWORD dword_5d4594_825760 = 0;
_DWORD dword_587000_80828 = 0x1;
_DWORD dword_5d4594_810632 = 0;
_DWORD dword_5d4594_787148 = 0;
_DWORD dword_5d4594_2386944 = 0;
_DWORD dword_5d4594_1064916 = 0;
_DWORD dword_5d4594_3801780 = 0;
_DWORD dword_5d4594_2516348 = 0;
_DWORD dword_5d4594_3799536 = 0;
_DWORD dword_5d4594_1063116 = 0;
_DWORD dword_5d4594_1090120 = 0;
_DWORD dword_5d4594_2516328 = 0;
_DWORD dword_5d4594_1189584 = 0;
_DWORD dword_5d4594_1049504 = 0;
_DWORD dword_5d4594_1046868 = 0;
_DWORD dword_5d4594_1082856 = 0;
_DWORD dword_5d4594_1193380 = 0;
_DWORD dword_587000_26048 = 0x9;
_DWORD dword_5d4594_3799624 = 0;
_DWORD dword_5d4594_1316972 = 0;
_DWORD dword_5d4594_1123524 = 0;
_DWORD dword_5d4594_1064192 = 0;
_DWORD dword_5d4594_1045604 = 0;
_DWORD dword_5d4594_2386176 = 0;
_DWORD dword_587000_197424 = 0xffffffff;
_DWORD dword_5d4594_1064816 = 0;
_DWORD dword_5d4594_529316 = 0;
