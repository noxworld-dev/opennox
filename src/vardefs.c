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
_DWORD dword_5d4594_1309820 = 0;
_DWORD dword_5d4594_1062508 = 0;
_DWORD dword_5d4594_1049864 = 0;
_DWORD dword_5d4594_829480 = 0;
_DWORD dword_5d4594_1062512 = 0;
_DWORD dword_5d4594_1217464 = 0;
_DWORD dword_5d4594_830248 = 0;
_DWORD dword_5d4594_1599656 = 0;
_DWORD dword_5d4594_1049500 = 0;
_DWORD dword_5d4594_3798840 = 0;
_DWORD dword_5d4594_1309812 = 0;
_DWORD dword_5d4594_754036 = 0;
_DWORD dword_587000_155144 = &byte_5D4594[1193204];
_DWORD dword_5d4594_741676 = 0;
_DWORD dword_5d4594_1047516 = 0;
_DWORD dword_5d4594_1308084 = 0;
_DWORD dword_5d4594_815000 = 0;
_DWORD dword_5d4594_3798824 = 0;
_DWORD dword_5d4594_1307780 = 0;
_DWORD dword_5d4594_3798820 = 0;
_DWORD dword_5d4594_1193516 = 0;
_DWORD dword_5d4594_1090048 = 0;
_DWORD dword_5d4594_816364 = 0;
_DWORD dword_5d4594_1049508 = 0;
_DWORD dword_5d4594_1049796 = 0;
_DWORD dword_5d4594_829492 = 0;
_DWORD dword_5d4594_1098576 = 0;
_DWORD dword_5d4594_1321040 = 0;
_DWORD dword_5d4594_2487236 = 0;
_DWORD dword_5d4594_3799432 = 0;
_DWORD dword_5d4594_830124 = 0;
_DWORD dword_587000_87412 = 0xffffffff;
_DWORD dword_5d4594_1548476 = 0;
_DWORD dword_5d4594_2660652 = 0;
_DWORD dword_5d4594_1045636 = 0;
_DWORD dword_587000_87404 = 0x2;
_DWORD dword_5d4594_3798804 = 0;
_DWORD dword_5d4594_832476 = 0;
_DWORD dword_5d4594_1570272 = 0;
_DWORD dword_5d4594_1305684 = 0;
_DWORD dword_5d4594_2386940 = 0;
_DWORD dword_5d4594_2523752 = 0;
_DWORD dword_5d4594_815132 = 0;
_DWORD dword_5d4594_1321228 = 0;
_DWORD dword_5d4594_815048 = 0;
_DWORD dword_5d4594_829488 = 0;
_DWORD dword_5d4594_1063636 = 0;
_DWORD dword_587000_197428 = 0xffffffff;
_DWORD dword_587000_60352 = 0x1;
_DWORD dword_5d4594_833716 = 0;
_DWORD dword_5d4594_1319228 = 0;
_DWORD dword_5d4594_10956 = 0;
_DWORD dword_5d4594_1062456 = 0;
_DWORD dword_5d4594_816348 = 0;
_DWORD dword_5d4594_2650672 = 0;
_DWORD dword_5d4594_3798696 = 0;
_DWORD dword_5d4594_2523756 = 0;
_DWORD dword_5d4594_1307764 = 0;
_DWORD dword_5d4594_1098628 = 0;
_DWORD dword_5d4594_529340 = 0;
_DWORD dword_587000_149232 = 0x456;
_DWORD dword_5d4594_1046872 = 0;
_DWORD dword_5d4594_1046496 = 0;
_DWORD dword_5d4594_830108 = 0;
_DWORD dword_5d4594_1523028 = 0;
_DWORD dword_5d4594_1316708 = 0;
_DWORD dword_5d4594_1064888 = 0;
_DWORD dword_5d4594_3798636 = 0;
_DWORD dword_5d4594_251572 = 0;
_DWORD dword_5d4594_1556860 = 0;
_DWORD dword_5d4594_1303452 = 0;
_DWORD dword_5d4594_2386224 = 0;
_DWORD dword_5d4594_815016 = 0;
_DWORD dword_5d4594_2386152 = 0;
_DWORD dword_5d4594_1311144 = 0;
_DWORD dword_5d4594_1569728 = 0;
_DWORD dword_5d4594_1197312 = 0;
_DWORD dword_5d4594_831236 = 0;
_DWORD dword_5d4594_3799484 = 0;
_DWORD dword_5d4594_1064296 = 0;
_DWORD dword_5d4594_1047540 = 0;
_DWORD dword_5d4594_814984 = 0;
_DWORD dword_5d4594_1320964 = 0;
_DWORD dword_5d4594_2523900 = 0;
_DWORD dword_5d4594_1049800 = 0;
_DWORD dword_5d4594_251568 = 0;
_DWORD dword_5d4594_1309720 = 0;
_DWORD dword_5d4594_1569752 = 0;
_DWORD dword_5d4594_1321244 = 0;
_DWORD dword_5d4594_1046936 = 0;
_DWORD dword_5d4594_2487908 = 0;
_DWORD dword_5d4594_831088 = 0;
_DWORD dword_5d4594_1107036 = 0;
_DWORD dword_5d4594_1321248 = 0;
_DWORD dword_5d4594_1599640 = 0;
_DWORD dword_5d4594_3798836 = 0;
_DWORD dword_5d4594_1565512 = 0;
_DWORD dword_5d4594_815028 = 0;
_DWORD dword_5d4594_816456 = 0;
_DWORD dword_5d4594_1301848 = 0;
_DWORD dword_5d4594_829508 = 0;
_DWORD dword_5d4594_1316712 = 0;
_DWORD dword_5d4594_1313800 = 0;
_DWORD dword_5d4594_1321232 = 0;
_DWORD dword_5d4594_815024 = 0;
_DWORD dword_5d4594_830104 = 0;
_DWORD dword_587000_80820 = 0x1;
_DWORD dword_5d4594_1045528 = 0;
_DWORD dword_5d4594_787156 = 0;
_DWORD dword_5d4594_1301792 = 0;
_DWORD dword_587000_154956 = 0x1;
_DWORD dword_5d4594_1313796 = 0;
_DWORD dword_5d4594_1522624 = 0;
_DWORD dword_5d4594_815020 = 0;
_DWORD dword_5d4594_1305680 = 0;
_DWORD dword_5d4594_810640 = 0;
_DWORD dword_5d4594_815032 = 0;
_DWORD dword_5d4594_1311148 = 0;
_DWORD dword_5d4594_787164 = 0;
_DWORD dword_5d4594_816440 = 0;
_DWORD dword_5d4594_1301800 = 0;
_DWORD dword_5d4594_1193360 = 0;
_DWORD dword_5d4594_1522628 = 0;
_DWORD dword_5d4594_3679320 = 0;
_DWORD dword_5d4594_1049520 = 0;
_DWORD dword_5d4594_1309748 = 0;
_DWORD dword_5d4594_816432 = 0;
_DWORD dword_5d4594_1599540 = 0;
_DWORD dword_5d4594_251548 = 0;
_DWORD dword_5d4594_1556844 = 0;
_DWORD dword_5d4594_1045464 = 0;
_DWORD dword_5d4594_1045484 = 0;
_DWORD dword_5d4594_1049856 = 0;
_DWORD dword_5d4594_1064856 = 0;
_DWORD dword_5d4594_823692 = 0;
_DWORD dword_5d4594_3799524 = 0;
_DWORD dword_5d4594_1522600 = 0;
_DWORD dword_587000_132132 = 0x1;
_DWORD dword_5d4594_754056 = 0;
_DWORD dword_5d4594_1217456 = 0;
_DWORD dword_5d4594_1193348 = 0;
_DWORD dword_5d4594_1047520 = 0;
_DWORD dword_5d4594_3798632 = 0;
_DWORD dword_5d4594_534808 = 0;
_DWORD dword_5d4594_1197324 = 0;
_DWORD dword_5d4594_3821640 = 0;
_DWORD dword_5d4594_1599576 = 0;
_DWORD dword_5d4594_3821636 = 0;
_DWORD dword_5d4594_1599596 = 0;
_DWORD dword_5d4594_1045480 = 0;
_DWORD dword_5d4594_3807156 = 0;
_DWORD dword_5d4594_816452 = 0;
_DWORD dword_5d4594_2487556 = 0;
_DWORD dword_5d4594_833712 = 0;
_DWORD dword_5d4594_1307776 = 0;
_DWORD dword_5d4594_1599588 = 0;
_DWORD dword_5d4594_1064912 = 0;
_DWORD dword_5d4594_3798640 = 0;
_DWORD dword_5d4594_1523024 = 0;
_DWORD dword_5d4594_2618912 = 0;
_DWORD dword_5d4594_2516344 = 0;
_DWORD dword_5d4594_1046508 = 0;
_DWORD dword_5d4594_1123532 = 0;
_DWORD dword_5d4594_1193384 = 0;
_DWORD dword_5d4594_1045536 = 0;
_DWORD dword_587000_166704 = 0x6;
_DWORD dword_5d4594_1319256 = 0;
_DWORD dword_5d4594_251540 = 0;
_DWORD dword_5d4594_371692 = 0;
_DWORD dword_5d4594_3798832 = 0;
_DWORD dword_5d4594_1197320 = 0;
_DWORD dword_5d4594_3799492 = 0;
_DWORD dword_5d4594_1301844 = 0;
_DWORD dword_5d4594_3798808 = 0;
_DWORD dword_5d4594_1062524 = 0;
_DWORD dword_5d4594_3835396 = 0;
_DWORD dword_5d4594_1062528 = 0;
_DWORD dword_5d4594_2388648 = 0;
_DWORD dword_587000_154952 = 0x1;
_DWORD dword_5d4594_1312480 = 0;
_DWORD dword_5d4594_1522604 = 0;
_DWORD dword_5d4594_1096640 = 0;
_DWORD dword_5d4594_3798816 = 0;
_DWORD dword_5d4594_1045532 = 0;
_DWORD dword_5d4594_528256 = 0;
_DWORD dword_5d4594_1568024 = 0;
_DWORD dword_5d4594_1599564 = 0;
_DWORD dword_5d4594_1308088 = 0;
_DWORD dword_5d4594_3801804 = 0;
_DWORD dword_5d4594_816492 = 0;
_DWORD dword_5d4594_826028 = 0;
_DWORD dword_5d4594_2487524 = 0;
_DWORD dword_5d4594_1189592 = 0;
_DWORD dword_5d4594_1522612 = 0;
_DWORD dword_5d4594_814624 = 0;
_DWORD dword_5d4594_1599660 = 0;
_DWORD dword_5d4594_829484 = 0;
_DWORD dword_5d4594_3821964 = 0;
_DWORD dword_5d4594_1096516 = 0;
_DWORD dword_5d4594_833720 = 0;
_DWORD dword_5d4594_1045468 = 0;
_DWORD dword_5d4594_2487904 = 0;
_DWORD dword_587000_127004 = &byte_5D4594[1045324];
_DWORD dword_5d4594_2386184 = 0;
_DWORD dword_5d4594_815088 = 0;
_DWORD dword_5d4594_2495920 = 0;
_DWORD dword_5d4594_1046924 = 0;
_DWORD dword_5d4594_1312484 = 0;
_DWORD dword_5d4594_1189596 = 0;
_DWORD dword_5d4594_3798156 = 0;
_DWORD dword_587000_60356 = 0x1;
_DWORD dword_5d4594_3624 = 0;
_DWORD dword_5d4594_1217460 = 0;
_DWORD dword_5d4594_1307716 = 0;
_DWORD dword_587000_93156 = 0x1;
_DWORD dword_5d4594_830140 = 0;
_DWORD dword_5d4594_2523780 = 0;
_DWORD dword_5d4594_2650676 = 0;
_DWORD dword_5d4594_1321252 = 0;
_DWORD dword_5d4594_1522632 = 0;
_DWORD dword_5d4594_531648 = 0;
_DWORD dword_5d4594_787208 = 0;
_DWORD dword_5d4594_1045432 = 0;
_DWORD dword_5d4594_815044 = 0;
_DWORD dword_5d4594_831232 = 0;
_DWORD dword_5d4594_787152 = 0;
_DWORD dword_5d4594_816488 = 0;
_DWORD dword_5d4594_2487712 = 0;
_DWORD dword_5d4594_2386496 = 0;
_DWORD dword_5d4594_529328 = 0;
_DWORD dword_5d4594_2386180 = 0;
_DWORD dword_5d4594_3843628 = 0;
_DWORD dword_5d4594_2386212 = 0;
_DWORD dword_5d4594_3798720 = 0;
_DWORD dword_5d4594_1319060 = 0;
_DWORD dword_5d4594_1047548 = 0;
_DWORD dword_5d4594_816340 = 0;
_DWORD dword_5d4594_1049512 = 0;
_DWORD dword_5d4594_1311140 = 0;
_DWORD dword_5d4594_3799544 = 0;
_DWORD dword_587000_264364 = 0x41b80000;
_DWORD dword_5d4594_1047932 = 0;
_DWORD dword_5d4594_2523912 = 0;
_DWORD dword_5d4594_816368 = 0;
_DWORD dword_5d4594_1062476 = 0;
_DWORD dword_5d4594_1090276 = 0;
_DWORD dword_5d4594_830116 = 0;
_DWORD dword_5d4594_1049496 = 0;
_DWORD dword_587000_93164 = &byte_5D4594[816244];
_DWORD dword_5d4594_1098624 = 0;
_DWORD dword_5d4594_1569672 = 0;
_DWORD dword_5d4594_3632 = 0;
_DWORD dword_5d4594_1321240 = 0;
_DWORD dword_5d4594_1197316 = 0;
_DWORD dword_5d4594_1599624 = 0;
_DWORD dword_5d4594_2386576 = 0;
_DWORD dword_5d4594_830148 = 0;
_DWORD dword_5d4594_1569756 = 0;
_DWORD dword_5d4594_1320968 = 0;
_DWORD dword_5d4594_2488604 = 0;
_QWORD qword_581450_9544 = 0x3fe0000000000000;
_QWORD qword_581450_9568 = 0x0;
_QWORD qword_5d4594_1567940 = 0;
_QWORD qword_581450_10256 = 0x3f847ae147ae147b;
_QWORD qword_581450_10392 = 0xbf847ae147ae147b;
_QWORD qword_581450_9552 = 0x40f0000000000000;
_QWORD qword_581450_9512 = 0x3ff0000000000000;
_QWORD qword_5d4594_815068 = 0;
_QWORD qword_5d4594_814956 = 0;
_QWORD qword_581450_10176 = 0x3fb99999a0000000;
_QWORD qword_5d4594_815724 = 0;
_DWORD dword_5d4594_1316408 = 0;
_DWORD dword_5d4594_1522620 = 0;
_DWORD dword_5d4594_2488660 = 0;
_DWORD dword_587000_292492 = 0x42c80000;
_DWORD dword_5d4594_805844 = 0;
_DWORD dword_5d4594_251608 = 0;
_DWORD dword_5d4594_1309732 = 0;
_DWORD dword_5d4594_251600 = 0;
_DWORD dword_5d4594_1321204 = 0;
_DWORD dword_5d4594_1599632 = 0;
_DWORD dword_5d4594_2386500 = 0;
_DWORD dword_5d4594_2649712 = 0;
_DWORD dword_5d4594_1307204 = 0;
_DWORD dword_5d4594_741284 = 0;
_DWORD dword_587000_312820 = 0x3f800000;
_DWORD dword_5d4594_1046532 = 0;
_DWORD dword_5d4594_3798828 = 0;
_DWORD dword_5d4594_1309728 = 0;
_DWORD dword_5d4594_1312460 = 0;
_DWORD dword_5d4594_1309836 = 0;
_DWORD dword_5d4594_1320992 = 0;
_DWORD dword_5d4594_1599476 = 0;
_DWORD dword_5d4594_1321236 = 0;
_DWORD dword_5d4594_1047552 = 0;
_DWORD dword_587000_60044 = 0xffffffff;
_DWORD dword_5d4594_251560 = 0;
_DWORD dword_5d4594_2513920 = 0;
_DWORD dword_5d4594_3484 = 0;
_DWORD dword_5d4594_806044 = 0;
_DWORD dword_5d4594_528252 = 0;
_DWORD dword_5d4594_754040 = 0;
_DWORD dword_5d4594_1309828 = 0;
_DWORD dword_5d4594_1307308 = 0;
_DWORD dword_587000_122852 = &byte_5D4594[830980];
_DWORD dword_5d4594_1301776 = 0;
_DWORD dword_5d4594_1301836 = 0;
_DWORD dword_5d4594_251564 = 0;
_DWORD dword_587000_184452 = 0x32;
_DWORD dword_5d4594_1301832 = 0;
_DWORD dword_5d4594_3801808 = 0;
_DWORD dword_5d4594_1550916 = 0;
_DWORD dword_5d4594_2487540 = 0;
_DWORD dword_587000_81128 = &byte_5D4594[805884];
_DWORD dword_587000_80812 = 0x1;
_DWORD dword_5d4594_2386572 = 0;
_DWORD dword_5d4594_251700 = 0;
_DWORD dword_5d4594_1193584 = 0;
_DWORD dword_5d4594_1599532 = 0;
_DWORD dword_5d4594_3798800 = 0;
_DWORD dword_5d4594_1522892 = 0;
_DWORD dword_5d4594_1307744 = 0;
_DWORD dword_5d4594_3798812 = 0;
_DWORD dword_5d4594_251552 = 0;
_DWORD dword_5d4594_1046952 = 0;
_DWORD dword_5d4594_832536 = 0;
_DWORD dword_5d4594_4808 = 0;
_DWORD dword_5d4594_3799508 = 0;
_DWORD dword_587000_87408 = 0x1;
_DWORD dword_5d4594_839888 = 0;
_DWORD dword_5d4594_806048 = 0;
_DWORD dword_5d4594_3844304 = 0;
_DWORD dword_5d4594_814988 = 0;
_DWORD dword_5d4594_816460 = 0;
_DWORD dword_5d4594_805836 = 0;
_DWORD dword_5d4594_2487560 = 0;
_DWORD dword_5d4594_251556 = 0;
_DWORD dword_587000_312804 = 0x3f800000;
_DWORD dword_5d4594_251504 = 0;
_DWORD dword_5d4594_1599480 = 0;
_DWORD dword_5d4594_1062516 = 0;
_DWORD dword_5d4594_1301828 = 0;
_DWORD dword_5d4594_1599548 = 0;
_DWORD dword_5d4594_1316492 = 0;
_DWORD dword_5d4594_2491616 = 0;
_DWORD dword_5d4594_251744 = 0;
_DWORD dword_5d4594_815708 = 0;
_DWORD dword_587000_312816 = 0x3f800000;
_DWORD dword_5d4594_3821968 = 0;
_DWORD dword_587000_312800 = 0x3f800000;
_DWORD dword_5d4594_251508 = 0;
_DWORD dword_5d4594_1313792 = 0;
_DWORD dword_5d4594_810636 = 0;
_DWORD dword_5d4594_529324 = 0;
_DWORD dword_5d4594_1569664 = 0;
_DWORD dword_5d4594_3804668 = 0;
_DWORD dword_5d4594_2487248 = 0;
_DWORD dword_5d4594_1046516 = 0;
_DWORD dword_5d4594_1307768 = 0;
_DWORD dword_5d4594_2487984 = 0;
_DWORD dword_5d4594_1309780 = 0;
_DWORD dword_587000_311480 = 0xffffffff;
_DWORD dword_5d4594_1193152 = 0;
_DWORD dword_587000_312784 = 0x3f800000;
_DWORD dword_5d4594_1563660 = 0;
_DWORD dword_5d4594_1599692 = 0;
_DWORD dword_5d4594_2487532 = 0;
_DWORD dword_5d4594_1309716 = 0;
_DWORD dword_5d4594_1064900 = 0;
_DWORD dword_5d4594_805984 = 0;
_DWORD dword_5d4594_815040 = 0;
_DWORD dword_5d4594_3596 = 0;
_DWORD dword_5d4594_1522616 = 0;
_DWORD dword_587000_80836 = 0x1;
_DWORD dword_5d4594_815212 = 0;
_DWORD dword_5d4594_2386924 = 0;
_DWORD dword_5d4594_830872 = 0;
_DWORD dword_5d4594_1096508 = 0;
_DWORD dword_5d4594_1309740 = 0;
_DWORD dword_5d4594_1312472 = 0;
_DWORD dword_5d4594_1200804 = 0;
_DWORD dword_5d4594_1049484 = 0;
_DWORD dword_5d4594_1599712 = 0;
_DWORD dword_587000_312788 = 0x3f800000;
_DWORD dword_587000_80824 = 0x1;
_DWORD dword_5d4594_1321216 = 0;
_DWORD dword_5d4594_787172 = 0;
_DWORD dword_5d4594_2386160 = 0;
_DWORD dword_5d4594_1193712 = 0;
_DWORD dword_587000_173332 = 0x1;
_DWORD dword_5d4594_1319232 = 0;
_DWORD dword_5d4594_1046656 = 0;
_DWORD dword_5d4594_3798716 = 0;
_DWORD dword_5d4594_3620 = 0;
_DWORD dword_5d4594_832532 = 0;
_DWORD dword_5d4594_2650680 = 0;
_DWORD dword_5d4594_588120 = 0;
_DWORD dword_5d4594_805852 = 0;
_DWORD dword_5d4594_1047512 = 0;
_DWORD dword_5d4594_588084 = 0;
_DWORD dword_5d4594_2487848 = 0;
_DWORD dword_5d4594_1321044 = 0;
_DWORD dword_5d4594_816372 = 0;
_DWORD dword_5d4594_832492 = 0;
_DWORD dword_5d4594_1046504 = 0;
_DWORD dword_5d4594_1045508 = 0;
_DWORD dword_5d4594_825744 = 0;
_DWORD dword_587000_154940 = &sub_4815E0;
_DWORD dword_5d4594_1217452 = 0;
_DWORD dword_5d4594_1193704 = 0;
_DWORD dword_5d4594_1319264 = 0;
_DWORD dword_5d4594_829504 = 0;
_DWORD dword_5d4594_251496 = 0;
_DWORD dword_5d4594_2487852 = 0;
_DWORD dword_5d4594_1046928 = 0;
_DWORD dword_5d4594_830264 = 0;
_DWORD dword_5d4594_1098580 = 0;
_DWORD dword_5d4594_831224 = 0;
_DWORD dword_5d4594_2487880 = 0;
_DWORD dword_5d4594_1522932 = 0;
_DWORD dword_5d4594_1309708 = 0;
_DWORD dword_5d4594_3798780 = 0;
_DWORD dword_5d4594_3804680 = 0;
_DWORD dword_5d4594_832504 = 0;
_DWORD dword_5d4594_830276 = 0;
_DWORD dword_5d4594_1203864 = 0;
_DWORD dword_5d4594_832508 = 0;
_DWORD dword_5d4594_1090100 = 0;
_DWORD dword_5d4594_3835356 = 0;
_DWORD dword_587000_80844 = 0x1;
_DWORD dword_5d4594_814996 = 0;
_DWORD dword_5d4594_1049532 = 0;
_DWORD dword_5d4594_1096512 = 0;
_DWORD dword_5d4594_1197364 = 0;
_DWORD dword_5d4594_1046520 = 0;
_DWORD dword_5d4594_829512 = 0;
_DWORD dword_5d4594_832516 = 0;
_DWORD dword_587000_132136 = 0xffffffff;
_DWORD dword_5d4594_806052 = 0;
_DWORD dword_5d4594_832496 = 0;
_DWORD dword_5d4594_832512 = 0;
_DWORD dword_5d4594_2386188 = 0;
_DWORD dword_5d4594_832524 = 0;
_DWORD dword_5d4594_1309776 = 0;
_DWORD dword_5d4594_811104 = 0;
_DWORD dword_5d4594_2523896 = 0;
_DWORD dword_5d4594_1599556 = 0;
_DWORD dword_5d4594_1599592 = 0;
_DWORD dword_5d4594_2487980 = 0;
_DWORD dword_5d4594_823776 = 0;
_DWORD dword_5d4594_1045688 = 0;
_DWORD dword_5d4594_3798648 = 0;
_DWORD dword_5d4594_832528 = 0;
_DWORD dword_5d4594_832500 = 0;
_DWORD dword_5d4594_832520 = 0;
_DWORD dword_5d4594_829516 = 0;
_DWORD dword_5d4594_787212 = 0;
_DWORD dword_5d4594_1307736 = 0;
_DWORD dword_5d4594_1046636 = 0;
_DWORD dword_5d4594_1046500 = 0;
_DWORD dword_5d4594_1599060 = 0;
_DWORD dword_5d4594_1189600 = 0;
_DWORD dword_5d4594_1193184 = 0;
_DWORD dword_587000_136184 = 0xffffff1f;
_DWORD dword_5d4594_1098592 = 0;
_DWORD dword_5d4594_2487552 = 0;
_DWORD dword_5d4594_1321032 = 0;
_DWORD dword_5d4594_251720 = 0;
_DWORD dword_5d4594_1301840 = 0;
_DWORD dword_5d4594_1307748 = 0;
_DWORD dword_5d4594_1320932 = 0;
_DWORD dword_5d4594_1197332 = 0;
_DWORD dword_5d4594_1319056 = 0;
_DWORD dword_5d4594_1047528 = 0;
_DWORD dword_587000_202404 = 0x41f00000;
_DWORD dword_5d4594_830864 = 0;
_DWORD dword_5d4594_1096500 = 0;
_DWORD dword_5d4594_608316 = 0;
_DWORD dword_5d4594_1064824 = 0;
_DWORD dword_5d4594_823700 = 0;
_DWORD dword_5d4594_3807160 = 0;
_DWORD dword_5d4594_1312476 = 0;
_DWORD dword_5d4594_3798776 = 0;
_DWORD dword_5d4594_1046948 = 0;
_DWORD dword_5d4594_1046528 = 0;
_DWORD dword_5d4594_741364 = 0;
_DWORD dword_5d4594_1309784 = 0;
_DWORD dword_5d4594_1046932 = 0;
_DWORD dword_5d4594_1321224 = 0;
_DWORD dword_5d4594_588068 = 0;
_DWORD dword_587000_122848 = 0x1;
_DWORD dword_5d4594_1045460 = 0;
_DWORD dword_5d4594_831220 = 0;
_DWORD dword_5d4594_2513916 = 0;
_DWORD dword_587000_173328 = 0x1;
_DWORD dword_5d4594_830244 = 0;
_DWORD dword_5d4594_3799556 = 0;
_DWORD dword_5d4594_741292 = 0;
_DWORD dword_5d4594_2523744 = 0;
_DWORD dword_5d4594_1203840 = 0;
_DWORD dword_5d4594_826032 = 0;
_DWORD dword_5d4594_2487708 = 0;
_DWORD dword_587000_154948 = 0xffffffff;
_DWORD dword_5d4594_1548700 = 0;
_DWORD dword_5d4594_3799468 = 0;
_DWORD dword_5d4594_741332 = 0;
_DWORD dword_5d4594_1093136 = 0;
_DWORD dword_5d4594_3799476 = 0;
_DWORD dword_5d4594_1565616 = 0;
_DWORD dword_5d4594_816356 = 0;
_DWORD dword_5d4594_1203836 = 0;
_DWORD dword_587000_154960 = 0x1;
_DWORD dword_5d4594_1301780 = 0;
_DWORD dword_5d4594_1064864 = 0;
_DWORD dword_5d4594_1096252 = 0;
_DWORD dword_5d4594_1563344 = 0;
_DWORD dword_5d4594_741356 = 0;
_DWORD dword_5d4594_1303468 = 0;
_DWORD dword_5d4594_2487240 = 0;
_DWORD dword_5d4594_1064820 = 0;
_DWORD dword_5d4594_2523908 = 0;
_DWORD dword_5d4594_1197356 = 0;
_DWORD dword_5d4594_829520 = 0;
_DWORD dword_5d4594_2388640 = 0;
_DWORD dword_5d4594_1097188 = 0;
_DWORD dword_5d4594_1045436 = 0;
_DWORD dword_5d4594_1321800 = 0;
_DWORD dword_5d4594_527684 = 0;
_DWORD dword_5d4594_1197336 = 0;
_DWORD dword_5d4594_1197352 = 0;
_DWORD dword_5d4594_826036 = 0;
_DWORD dword_5d4594_1064860 = 0;
_DWORD dword_587000_173336 = 0x1;
_DWORD dword_5d4594_3798788 = 0;
_DWORD dword_587000_93196 = 0x1;
_DWORD dword_5d4594_1046536 = 0;
_DWORD dword_5d4594_1062468 = 0;
_DWORD dword_587000_80832 = 0x1;
_DWORD dword_5d4594_1523036 = 0;
_DWORD dword_5d4594_839884 = 0;
_DWORD dword_5d4594_1303472 = 0;
_DWORD dword_5d4594_1197328 = 0;
_DWORD dword_5d4594_1090044 = 0;
_DWORD dword_5d4594_1305748 = 0;
_DWORD dword_5d4594_1046624 = 0;
_DWORD dword_5d4594_1308164 = 0;
_DWORD dword_5d4594_1096496 = 0;
_DWORD dword_5d4594_815704 = 0;
_DWORD dword_5d4594_816448 = 0;
_DWORD dword_5d4594_1568020 = 0;
_DWORD dword_5d4594_2386192 = 0;
_DWORD dword_5d4594_2386220 = 0;
_DWORD dword_5d4594_2487912 = 0;
_DWORD dword_5d4594_252276 = 0;
_DWORD dword_5d4594_2489432 = 0;
_DWORD dword_5d4594_1567928 = 0;
_DWORD dword_5d4594_1307720 = 0;
_DWORD dword_5d4594_1048144 = 0;
_DWORD dword_5d4594_787144 = 0;
_DWORD dword_5d4594_2386568 = 0;
_DWORD dword_587000_311372 = 0xffffffff;
_DWORD dword_5d4594_2386920 = 0;
_DWORD dword_5d4594_1062452 = 0;
_DWORD dword_5d4594_1046576 = 0;
_DWORD dword_5d4594_2386564 = 0;
_DWORD dword_5d4594_1093156 = 0;
_DWORD dword_5d4594_830292 = 0;
_DWORD dword_5d4594_1563664 = 0;
_DWORD dword_5d4594_1569748 = 0;
_DWORD dword_5d4594_1550912 = 0;
_DWORD dword_5d4594_1062488 = 0;
_DWORD dword_5d4594_2516356 = 0;
_DWORD dword_5d4594_1047936 = 0;
_DWORD dword_5d4594_1321208 = 0;
_DWORD dword_5d4594_2487620 = 0;
_DWORD dword_5d4594_1308092 = 0;
_DWORD dword_5d4594_1309824 = 0;
_DWORD dword_5d4594_1308160 = 0;
_DWORD dword_5d4594_3799488 = 0;
_DWORD dword_5d4594_2614264 = 0;
_DWORD dword_5d4594_531656 = 0;
_DWORD dword_5d4594_2386492 = 0;
_DWORD dword_5d4594_1096288 = 0;
_DWORD dword_5d4594_3835352 = 0;
_DWORD dword_5d4594_1046956 = 0;
_DWORD dword_5d4594_1307292 = 0;
_DWORD dword_5d4594_2523892 = 0;
_DWORD dword_587000_145664 = 0x1;
_DWORD dword_5d4594_787180 = 0;
_DWORD dword_5d4594_787200 = 0;
_DWORD dword_5d4594_1316704 = 0;
_DWORD dword_5d4594_1307732 = 0;
_DWORD dword_5d4594_3679316 = 0;
_DWORD dword_5d4594_1082864 = 0;
_DWORD dword_587000_93200 = 0x1;
_DWORD dword_5d4594_825736 = 0;
_DWORD dword_5d4594_1313540 = 0;
_DWORD dword_5d4594_1096284 = 0;
_DWORD dword_5d4594_2487624 = 0;
_DWORD dword_5d4594_1309832 = 0;
_DWORD dword_5d4594_2487576 = 0;
_DWORD dword_5d4594_1096644 = 0;
_DWORD dword_5d4594_3616 = 0;
_DWORD dword_5d4594_1309756 = 0;
_DWORD dword_5d4594_831084 = 0;
_DWORD dword_5d4594_825768 = 0;
_DWORD dword_5d4594_811372 = 0;
_DWORD dword_587000_111668 = 0x1;
_DWORD dword_5d4594_1309736 = 0;
_DWORD dword_5d4594_754044 = 0;
_DWORD dword_5d4594_1556112 = 0;
_DWORD dword_5d4594_1301812 = 0;
_DWORD dword_5d4594_1203860 = 0;
_DWORD dword_5d4594_2660032 = 0;
_DWORD dword_5d4594_1090040 = 0;
_DWORD dword_5d4594_3835348 = 0;
_DWORD dword_5d4594_1308 = 0;
_DWORD dword_5d4594_1045692 = 0;
_DWORD dword_5d4594_1046640 = 0;
_DWORD dword_5d4594_371264 = 0;
_DWORD dword_5d4594_1096504 = 0;
_DWORD dword_5d4594_1320972 = 0;
_DWORD dword_5d4594_1309768 = 0;
_DWORD dword_5d4594_830132 = 0;
_DWORD dword_5d4594_1563092 = 0;
_DWORD dword_5d4594_787184 = 0;
_DWORD dword_5d4594_1565516 = 0;
_DWORD dword_5d4594_1046596 = 0;
_DWORD dword_5d4594_1193668 = 0;
_DWORD dword_5d4594_1096260 = 0;
_DWORD dword_5d4594_529336 = 0;
_DWORD dword_5d4594_1308124 = 0;
_DWORD dword_587000_312808 = 0x3f800000;
_DWORD dword_5d4594_2487652 = 0;
_DWORD dword_5d4594_2523776 = 0;
_DWORD dword_5d4594_741248 = 0;
_DWORD dword_5d4594_741252 = 0;
_DWORD dword_5d4594_3835388 = 0;
_DWORD dword_5d4594_1046648 = 0;
_DWORD dword_5d4594_1599064 = 0;
_DWORD dword_5d4594_831276 = 0;
_DWORD dword_5d4594_808568 = 0;
_DWORD dword_587000_145540 = 0x1;
_DWORD dword_5d4594_2386156 = 0;
_DWORD dword_5d4594_816376 = 0;
_DWORD dword_5d4594_1301816 = 0;
_DWORD dword_5d4594_2491552 = 0;
_DWORD dword_5d4594_528272 = 0;
_DWORD dword_5d4594_1045588 = 0;
_DWORD dword_5d4594_1599616 = 0;
_DWORD dword_5d4594_1319236 = 0;
_DWORD dword_5d4594_811100 = 0;
_DWORD dword_5d4594_815056 = 0;
_DWORD dword_5d4594_1308128 = 0;
_DWORD dword_5d4594_830208 = 0;
_DWORD dword_5d4594_1305800 = 0;
_DWORD dword_5d4594_1556148 = 0;
_DWORD dword_5d4594_1569724 = 0;
_DWORD dword_587000_312792 = 0x3f800000;
_DWORD dword_5d4594_1090176 = 0;
_DWORD dword_5d4594_1568260 = 0;
_DWORD dword_5d4594_814552 = 0;
_DWORD dword_5d4594_10984 = 0;
_DWORD dword_587000_145668 = 0x6;
_DWORD dword_587000_312824 = 0x3f800000;
_DWORD dword_5d4594_3798728 = 0;
_DWORD dword_587000_180480 = 0x0;
_DWORD dword_587000_230092 = 0x6;
_DWORD dword_5d4594_1197372 = 0;
_DWORD dword_5d4594_251716 = 0;
_DWORD dword_5d4594_251708 = 0;
_DWORD dword_5d4594_1193648 = 0;
_DWORD dword_5d4594_1063120 = 0;
_DWORD dword_5d4594_1046540 = 0;
_DWORD dword_5d4594_1062496 = 0;
_DWORD dword_5d4594_1599652 = 0;
_DWORD dword_5d4594_1049804 = 0;
_DWORD dword_5d4594_3799552 = 0;
_DWORD dword_5d4594_1090112 = 0;
_DWORD dword_5d4594_740004 = 0;
_DWORD dword_5d4594_1309764 = 0;
_DWORD dword_5d4594_1569644 = 0;
_DWORD dword_5d4594_1097208 = 0;
_DWORD dword_5d4594_3807140 = 0;
_DWORD dword_5d4594_831092 = 0;
_DWORD dword_5d4594_2487676 = 0;
_DWORD dword_5d4594_1556852 = 0;
_DWORD dword_5d4594_741256 = 0;
_DWORD dword_5d4594_1049696 = 0;
_DWORD dword_587000_312828 = 0x3f800000;
_DWORD dword_5d4594_1301824 = 0;
_DWORD dword_5d4594_1316476 = 0;
_DWORD dword_587000_80800 = 0x1;
_DWORD dword_5d4594_816092 = 0;
_DWORD dword_5d4594_825752 = 0;
_DWORD dword_5d4594_2488652 = 0;
_DWORD dword_5d4594_2386216 = 0;
_DWORD dword_5d4594_2487672 = 0;
_DWORD dword_5d4594_1569668 = 0;
_DWORD dword_5d4594_1308156 = 0;
_DWORD dword_587000_312812 = 0x3f800000;
_DWORD dword_5d4594_1193156 = 0;
_DWORD dword_5d4594_814992 = 0;
_DWORD dword_587000_66116 = 0x1d;
_DWORD dword_5d4594_1563052 = 0;
_DWORD dword_5d4594_2487564 = 0;
_DWORD dword_5d4594_3804684 = 0;
_DWORD dword_5d4594_830972 = 0;
_DWORD dword_5d4594_1308120 = 0;
_DWORD dword_5d4594_2488608 = 0;
_DWORD dword_5d4594_1568868 = 0;
_DWORD dword_5d4594_1090108 = 0;
_DWORD dword_5d4594_1308108 = 0;
_DWORD dword_5d4594_3835312 = 0;
_DWORD dword_5d4594_1197308 = 0;
_DWORD dword_5d4594_1045584 = 0;
_DWORD dword_5d4594_814548 = 0;
_DWORD dword_5d4594_1303536 = 0;
_DWORD dword_5d4594_1082860 = 0;
_DWORD dword_5d4594_3798644 = 0;
_DWORD dword_5d4594_1308132 = 0;
_DWORD dword_5d4594_2386228 = 0;
_DWORD dword_5d4594_1308100 = 0;
_DWORD dword_587000_54276 = 0x1;
_DWORD dword_5d4594_1045424 = 0;
_DWORD dword_5d4594_3805484 = 0;
_DWORD dword_5d4594_1193524 = 0;
_DWORD dword_5d4594_2386916 = 0;
_DWORD dword_5d4594_2488640 = 0;
_DWORD dword_5d4594_3798712 = 0;
_DWORD dword_5d4594_741244 = 0;
_DWORD dword_5d4594_1193664 = 0;
_DWORD dword_5d4594_1280 = 0;
_DWORD dword_5d4594_830204 = 0;
_DWORD dword_5d4594_1313740 = 0;
_DWORD dword_587000_237036 = 0x1;
_DWORD dword_587000_93944 = 0xffffffff;
_DWORD dword_5d4594_823684 = 0;
_DWORD dword_5d4594_1062492 = 0;
_DWORD dword_5d4594_1193624 = 0;
_DWORD dword_587000_154968 = 0x3f800000;
_DWORD dword_5d4594_1098604 = 0;
_DWORD dword_587000_205696 = 0x1;
_DWORD dword_5d4594_1046600 = 0;
_DWORD dword_5d4594_1308116 = 0;
_DWORD dword_5d4594_1319248 = 0;
_DWORD dword_587000_312796 = 0x3f800000;
_DWORD dword_5d4594_3807136 = 0;
_DWORD dword_5d4594_1193672 = 0;
_DWORD dword_5d4594_1046944 = 0;
_DWORD dword_5d4594_1556848 = 0;
_DWORD dword_5d4594_2487584 = 0;
_DWORD dword_5d4594_251712 = 0;
_DWORD dword_5d4594_371756 = 0;
_DWORD dword_5d4594_1522608 = 0;
_DWORD dword_5d4594_531652 = 0;
_DWORD dword_5d4594_2487948 = 0;
_DWORD dword_5d4594_1301772 = 0;
_DWORD dword_5d4594_1522596 = 0;
_DWORD dword_5d4594_1049536 = 0;
_DWORD dword_5d4594_1098616 = 0;
_DWORD dword_5d4594_1304 = 0;
_DWORD dword_5d4594_3807152 = 0;
_DWORD dword_5d4594_830256 = 0;
_DWORD dword_5d4594_1049996 = 0;
_DWORD dword_5d4594_1305788 = 0;
_DWORD dword_5d4594_1098600 = 0;
_DWORD dword_5d4594_1563088 = 0;
_DWORD dword_5d4594_2523760 = 0;
_DWORD dword_5d4594_1064868 = 0;
_DWORD dword_5d4594_1565520 = 0;
_DWORD dword_5d4594_1320988 = 0;
_DWORD dword_5d4594_811072 = 0;
_DWORD dword_5d4594_1599696 = 0;
_DWORD dword_587000_261388 = 0x42480000;
_DWORD dword_5d4594_251704 = 0;
_DWORD dword_5d4594_823708 = 0;
_DWORD dword_5d4594_830120 = 0;
_DWORD dword_5d4594_1084040 = 0;
_DWORD dword_5d4594_1200768 = 0;
_DWORD dword_5d4594_1523032 = 0;
_DWORD dword_5d4594_831256 = 0;
_DWORD dword_5d4594_1316436 = 0;
_DWORD dword_587000_145672 = 0xffffffff;
_DWORD dword_5d4594_1046864 = 0;
_DWORD dword_5d4594_1523044 = 0;
_DWORD dword_5d4594_1046356 = 0;
_DWORD dword_5d4594_3799452 = 0;
_DWORD dword_5d4594_2386840 = 0;
_DWORD dword_5d4594_833732 = 0;
_DWORD dword_5d4594_2513932 = 0;
_DWORD dword_5d4594_1096280 = 0;
_DWORD dword_5d4594_1316472 = 0;
_DWORD dword_5d4594_1569652 = 0;
_DWORD dword_5d4594_1062560 = 0;
_DWORD dword_5d4594_2491544 = 0;
_DWORD dword_587000_183456 = 0x67;
_DWORD dword_5d4594_1097192 = 0;
_DWORD dword_5d4594_740072 = 0;
_DWORD dword_5d4594_830216 = 0;
_DWORD dword_587000_249172 = 0xffffffff;
_DWORD dword_587000_80840 = 0x1;
_DWORD dword_5d4594_2487900 = 0;
_DWORD dword_5d4594_1064896 = 0;
_DWORD dword_5d4594_2489420 = 0;
_DWORD dword_5d4594_1565612 = 0;
_DWORD dword_5d4594_1096256 = 0;
_DWORD dword_5d4594_1046524 = 0;
_DWORD dword_587000_142328 = 0x40000;
_DWORD dword_5d4594_2523764 = 0;
_DWORD dword_5d4594_534816 = 0;
_DWORD dword_5d4594_1193336 = 0;
_DWORD dword_5d4594_2489428 = 0;
_DWORD dword_5d4594_2487244 = 0;
_DWORD dword_5d4594_1090280 = 0;
_DWORD dword_5d4594_1200796 = 0;
_DWORD dword_5d4594_1313536 = 0;
_DWORD dword_5d4594_1308152 = 0;
_DWORD dword_5d4594_1098596 = 0;
_DWORD dword_5d4594_1047524 = 0;
_DWORD dword_5d4594_1311936 = 0;
_DWORD dword_5d4594_1563096 = 0;
_DWORD dword_5d4594_1062564 = 0;
_DWORD dword_5d4594_1309696 = 0;
_DWORD dword_5d4594_1308144 = 0;
_DWORD dword_5d4594_829500 = 0;
_DWORD dword_5d4594_833728 = 0;
_DWORD dword_5d4594_1090140 = 0;
_DWORD dword_5d4594_1049524 = 0;
_DWORD dword_5d4594_1305720 = 0;
_DWORD dword_5d4594_1316484 = 0;
_DWORD dword_5d4594_1320936 = 0;
_DWORD dword_5d4594_741680 = 0;
_DWORD dword_5d4594_1309704 = 0;
_DWORD dword_5d4594_808564 = 0;
_DWORD dword_5d4594_1193176 = 0;
_DWORD dword_5d4594_1045552 = 0;
_DWORD dword_587000_234176 = 0x41380000;
_DWORD dword_5d4594_1096264 = 0;
_DWORD dword_5d4594_1097196 = 0;
_DWORD dword_5d4594_831076 = 0;
_DWORD dword_5d4594_1321024 = 0;
_DWORD dword_5d4594_1523048 = 0;
_DWORD dword_5d4594_1308140 = 0;
_DWORD dword_5d4594_1203832 = 0;
_DWORD dword_5d4594_831244 = 0;
_DWORD dword_5d4594_2516372 = 0;
_DWORD dword_5d4594_1548704 = 0;
_DWORD dword_5d4594_1565632 = 0;
_DWORD dword_5d4594_1045520 = 0;
_DWORD dword_5d4594_1319268 = 0;
_DWORD dword_5d4594_1321520 = 0;
_DWORD dword_5d4594_741260 = 0;
_DWORD dword_5d4594_526276 = 0;
_DWORD dword_5d4594_1548732 = 0;
_DWORD dword_5d4594_1062556 = 0;
_DWORD dword_5d4594_1305712 = 0;
_DWORD dword_5d4594_1049992 = 0;
_DWORD dword_587000_171388 = 0x1;
_DWORD dword_587000_142316 = 0x40000;
_DWORD dword_5d4594_1082868 = 0;
_DWORD dword_5d4594_810628 = 0;
_DWORD dword_5d4594_3798708 = 0;
_DWORD dword_5d4594_754144 = 0;
_DWORD dword_5d4594_1090436 = 0;
_DWORD dword_5d4594_1563044 = 0;
_DWORD dword_5d4594_2489460 = 0;
_DWORD dword_5d4594_805860 = 0;
_DWORD dword_5d4594_816412 = 0;
_DWORD dword_5d4594_1308148 = 0;
_DWORD dword_5d4594_1062484 = 0;
_DWORD dword_5d4594_528260 = 0;
_DWORD dword_5d4594_1090284 = 0;
_DWORD dword_5d4594_1301796 = 0;
_DWORD dword_5d4594_2487932 = 0;
_DWORD dword_5d4594_1305700 = 0;
_DWORD dword_5d4594_2487628 = 0;
_DWORD dword_5d4594_3592 = 0;
_DWORD dword_5d4594_1045544 = 0;
_DWORD dword_5d4594_1548480 = 0;
_DWORD dword_587000_178216 = 0x8;
_DWORD dword_5d4594_251480 = 0;
_DWORD dword_5d4594_739996 = 0;
_DWORD dword_5d4594_1045428 = 0;
_DWORD dword_5d4594_2487536 = 0;
_DWORD dword_5d4594_2523804 = 0;
_DWORD dword_587000_126996 = 0x1;
_DWORD dword_5d4594_1305716 = 0;
_DWORD dword_5d4594_787224 = 0;
_DWORD dword_5d4594_2487568 = 0;
_DWORD dword_5d4594_1045540 = 0;
_DWORD dword_5d4594_2487580 = 0;
_DWORD dword_5d4594_1309772 = 0;
_DWORD dword_5d4594_829544 = 0;
_DWORD dword_5d4594_1556856 = 0;
_DWORD dword_5d4594_1046360 = 0;
_DWORD dword_5d4594_1049976 = 0;
_DWORD dword_5d4594_830260 = 0;
_DWORD dword_5d4594_1563080 = 0;
_DWORD dword_5d4594_1563084 = 0;
_DWORD dword_5d4594_1193188 = 0;
_DWORD dword_5d4594_1064828 = 0;
_DWORD dword_5d4594_830228 = 0;
_DWORD dword_5d4594_830136 = 0;
_DWORD dword_5d4594_1565628 = 0;
_DWORD dword_5d4594_816444 = 0;
_DWORD dword_5d4594_1548736 = 0;
_DWORD dword_587000_108752 = 0x1;
_DWORD dword_5d4594_1096276 = 0;
_DWORD dword_5d4594_3835392 = 0;
_DWORD dword_5d4594_1123520 = 0;
_DWORD dword_5d4594_2488720 = 0;
_DWORD dword_5d4594_1567988 = 0;
_DWORD dword_5d4594_1599068 = 0;
_DWORD dword_5d4594_1308112 = 0;
_DWORD dword_5d4594_832480 = 0;
_DWORD dword_5d4594_1568308 = 0;
_DWORD dword_5d4594_830192 = 0;
_DWORD dword_5d4594_1548664 = 0;
_DWORD dword_587000_66120 = &byte_5D4594[599084];
_DWORD dword_5d4594_1193576 = 0;
_DWORD dword_587000_129656 = 0x1;
_DWORD dword_587000_151528 = 0x11;
_DWORD dword_5d4594_1091364 = 0;
_DWORD dword_5d4594_1193132 = 0;
_DWORD dword_5d4594_2386928 = 0;
_DWORD dword_5d4594_599496 = 0;
_DWORD dword_5d4594_2516380 = 0;
_DWORD dword_5d4594_1599644 = 0;
_DWORD dword_5d4594_1563276 = 0;
_DWORD dword_5d4594_1082916 = 0;
_DWORD dword_587000_229988 = 0x6;
_DWORD dword_5d4594_741296 = 0;
_DWORD dword_5d4594_1062520 = 0;
_DWORD dword_5d4594_831260 = 0;
_DWORD dword_5d4594_3679312 = 0;
_DWORD dword_5d4594_1049516 = 0;
_DWORD dword_5d4594_2487992 = 0;
_DWORD dword_5d4594_1090292 = 0;
_DWORD dword_5d4594_3798676 = 0;
_DWORD dword_5d4594_527660 = 0;
_DWORD dword_5d4594_2489160 = 0;
_DWORD dword_5d4594_1522968 = 0;
_DWORD dword_587000_201380 = 0x3b9aca00;
_DWORD dword_5d4594_2490508 = 0;
_DWORD dword_5d4594_1316456 = 0;
_DWORD dword_5d4594_1045640 = 0;
_DWORD dword_5d4594_830112 = 0;
_DWORD dword_5d4594_528264 = 0;
_DWORD dword_5d4594_1098620 = 0;
_DWORD dword_5d4594_1569736 = 0;
_DWORD dword_5d4594_1200776 = 0;
_DWORD dword_5d4594_1045548 = 0;
_DWORD dword_5d4594_1316412 = 0;
_DWORD dword_5d4594_3807116 = 0;
_DWORD dword_5d4594_815100 = 0;
_DWORD dword_5d4594_1321036 = 0;
_DWORD dword_5d4594_1064300 = 0;
_DWORD dword_5d4594_3798680 = 0;
_DWORD dword_5d4594_1049808 = 0;
_DWORD dword_5d4594_1568300 = 0;
_DWORD dword_5d4594_1569660 = 0;
_DWORD dword_5d4594_2386872 = 0;
_DWORD dword_5d4594_2386948 = 0;
_DWORD dword_5d4594_1563320 = 0;
_DWORD dword_5d4594_1313692 = 0;
_DWORD dword_5d4594_3799500 = 0;
_DWORD dword_5d4594_3798684 = 0;
_DWORD dword_5d4594_823696 = 0;
_DWORD dword_5d4594_1599688 = 0;
_DWORD dword_5d4594_2386164 = 0;
_DWORD dword_5d4594_1307724 = 0;
_DWORD dword_587000_229992 = 0x5;
_DWORD dword_5d4594_805872 = 0;
_DWORD dword_5d4594_1523040 = 0;
_DWORD dword_5d4594_1096432 = 0;
_DWORD dword_5d4594_1046512 = 0;
_DWORD dword_587000_145548 = 0xffffffff;
_DWORD dword_5d4594_1096272 = 0;
_DWORD dword_5d4594_1097216 = 0;
_DWORD dword_5d4594_1096636 = 0;
_DWORD dword_5d4594_1522956 = 0;
_DWORD dword_587000_183460 = 0x26;
_DWORD dword_5d4594_1599628 = 0;
_DWORD dword_5d4594_1303508 = 0;
_DWORD dword_5d4594_2523904 = 0;
_DWORD dword_5d4594_1568288 = 0;
_DWORD dword_5d4594_1306860 = 0;
_DWORD dword_5d4594_2491704 = 0;
_DWORD dword_5d4594_1320948 = 0;
_DWORD dword_5d4594_787192 = 0;
_DWORD dword_5d4594_1568280 = 0;
_DWORD dword_5d4594_1556144 = 0;
_DWORD dword_587000_60068 = 0x1;
_DWORD dword_5d4594_1050008 = 0;
_DWORD dword_5d4594_1311924 = 0;
_DWORD dword_5d4594_3835372 = 0;
_DWORD dword_5d4594_1556136 = 0;
_DWORD dword_5d4594_2386168 = 0;
_DWORD dword_587000_109280 = 0xffffffff;
_DWORD dword_5d4594_251728 = 0;
_DWORD dword_5d4594_527656 = 0;
_DWORD dword_5d4594_1046548 = 0;
_DWORD dword_5d4594_741652 = 0;
_DWORD dword_5d4594_1308096 = 0;
_DWORD dword_5d4594_600116 = 0;
_DWORD dword_5d4594_805980 = 0;
_DWORD dword_5d4594_2496472 = 0;
_DWORD dword_5d4594_2618900 = 0;
_DWORD dword_5d4594_2487884 = 0;
_DWORD dword_5d4594_1313564 = 0;
_DWORD dword_5d4594_1568028 = 0;
_DWORD dword_5d4594_815052 = 0;
_DWORD dword_5d4594_2386860 = 0;
_DWORD dword_5d4594_1548524 = 0;
_DWORD dword_587000_154944 = &sub_481900;
_DWORD dword_5d4594_815060 = 0;
_DWORD dword_5d4594_2386560 = 0;
_DWORD dword_5d4594_1556316 = 0;
_DWORD dword_5d4594_830236 = 0;
_DWORD dword_5d4594_741648 = 0;
_DWORD dword_5d4594_1556128 = 0;
_DWORD dword_5d4594_2386548 = 0;
_DWORD dword_587000_60064 = 0x1;
_DWORD dword_5d4594_3798672 = 0;
_DWORD dword_5d4594_3801748 = 0;
_DWORD dword_5d4594_2491592 = 0;
_DWORD dword_5d4594_1090828 = 0;
_DWORD dword_5d4594_815096 = 0;
_DWORD dword_5d4594_529332 = 0;
_DWORD dword_5d4594_1313816 = 0;
_DWORD dword_5d4594_1193352 = 0;
_DWORD dword_5d4594_2488724 = 0;
_DWORD dword_5d4594_1548532 = 0;
_DWORD dword_5d4594_1045580 = 0;
_DWORD dword_5d4594_1567956 = 0;
_DWORD dword_5d4594_1313532 = 0;
_DWORD dword_5d4594_805820 = 0;
_DWORD dword_5d4594_1308104 = 0;
_DWORD dword_5d4594_1193568 = 0;
_DWORD dword_5d4594_2489436 = 0;
_DWORD dword_5d4594_10988 = 0;
_DWORD dword_5d4594_1320944 = 0;
_DWORD dword_587000_172880 = 0x8;
_DWORD dword_5d4594_823772 = 0;
_DWORD dword_5d4594_527988 = 0;
_DWORD dword_5d4594_1097212 = 0;
_DWORD dword_5d4594_2491588 = 0;
_DWORD dword_5d4594_3612 = 0;
_DWORD dword_5d4594_1046604 = 0;
_DWORD dword_5d4594_1316448 = 0;
_DWORD dword_5d4594_1193180 = 0;
_DWORD dword_5d4594_2523888 = 0;
_DWORD dword_5d4594_1563064 = 0;
_DWORD dword_5d4594_1313880 = 0;
_DWORD dword_5d4594_811896 = 0;
_DWORD dword_5d4594_830252 = 0;
_DWORD dword_5d4594_2491676 = 0;
