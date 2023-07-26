package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/server"
)

var dword_5d4594_1046492 *gui.Window
var nox_xxx_aClosewoodengat_587000_133480 unsafe.Pointer
var nox_wol_wnd_world_814980 *gui.Window
var dword_5d4594_1045516 *gui.Window
var dword_5d4594_1045684 *gui.Window
var dword_5d4594_1307784 unsafe.Pointer
var dword_5d4594_2650652 uint32
var dword_5d4594_1217448 int32
var dword_5d4594_1320940 *gui.Window
var dword_5d4594_815004 *gui.Window
var nox_wol_wnd_gameList_815012 *gui.Window
var dword_5d4594_1062480 *nox_inventory_cell_t
var dword_5d4594_832484 uint32
var dword_5d4594_2516348 uint32
var dword_5d4594_1063116 unsafe.Pointer
var dword_5d4594_1090120 uint32
var dword_5d4594_2516328 uint32
var dword_5d4594_1049504 *gui.Window
var dword_5d4594_1046868 uint32
var dword_5d4594_1193380 *gui.Window
var dword_5d4594_1316972 *gui.Window
var dword_5d4594_1123524 *gui.Window
var dword_5d4594_1045604 *gui.Window
var dword_5d4594_529316 unsafe.Pointer
var dword_5d4594_1309820 *gui.Window
var dword_5d4594_1062508 *gui.Window
var dword_5d4594_1049864 uint32
var dword_5d4594_1062512 int32
var dword_5d4594_1217464 int32
var dword_5d4594_1599656 uint32
var dword_5d4594_1049500 *gui.Window
var dword_5d4594_3798840 int32
var dword_5d4594_1309812 *gui.Window
var dword_587000_155144 unsafe.Pointer
var dword_5d4594_1047516 unsafe.Pointer
var dword_5d4594_1308084 *gui.Window
var dword_5d4594_815000 *gui.Window
var dword_5d4594_3798824 int32
var dword_5d4594_3798820 int32
var dword_5d4594_1049508 *gui.Window
var dword_5d4594_1049796_inventory_click_column_index int32
var dword_5d4594_1098576 *gui.Window
var dword_5d4594_1321040 *gui.Window
var dword_587000_87412 int32 = -1
var dword_5d4594_1548476 int32
var dword_5d4594_2660652 uint32
var dword_5d4594_1045636 *gui.Window
var dword_5d4594_3798804 int32
var dword_5d4594_832476 uint32
var dword_5d4594_1570272 uint32
var dword_5d4594_1305684 *gui.Window
var dword_5d4594_1321228 *gui.Window
var nox_game_createOrJoin_815048 uint32
var dword_5d4594_1063636 unsafe.Pointer
var nox_xxx_polygonNextIdx_587000_60352 uint32 = 0x1
var dword_5d4594_1062456 *gui.Window
var dword_5d4594_816348 uint32
var nox_gameDisableMapDraw_5d4594_2650672 uint32
var dword_5d4594_1098628 uint32
var dword_5d4594_529340 uint32
var nox_xxx_minimap_587000_149232 uint32 = 0x456
var dword_5d4594_1046872 uint32
var dword_5d4594_1046496 *gui.Window
var dword_5d4594_1523028 *gui.Window
var dword_5d4594_1316708 *gui.Window
var dword_5d4594_251572 int32
var dword_5d4594_1303452 *gui.Window
var dword_5d4594_2386224 uint32
var dword_5d4594_815016 *gui.Window
var dword_5d4594_2386152 uint32
var dword_5d4594_1197312 *gui.Window
var dword_5d4594_831236 *gui.Window
var dword_5d4594_1047540 int32
var dword_5d4594_814984 unsafe.Pointer
var dword_5d4594_1320964 uint32
var dword_5d4594_1049800_inventory_click_row_index int32
var dword_5d4594_1309720 *gui.Window
var dword_5d4594_1569752 unsafe.Pointer
var dword_5d4594_1046936 int32
var nox_xxx_lightningTarget_5d4594_2487908 uint32
var dword_5d4594_1107036 uint32
var dword_5d4594_3798836 int32
var dword_5d4594_815028 *gui.Window
var dword_5d4594_1301848 unsafe.Pointer
var dword_5d4594_1316712 unsafe.Pointer
var dword_5d4594_1313800 *client.Drawable
var dword_5d4594_1321232 *gui.Window
var dword_5d4594_815024 *gui.Window
var nox_client_highResFrontWalls_80820 uint32 = 0x1
var dword_5d4594_1045528 *gui.Window
var dword_5d4594_1313796 *client.Drawable
var dword_5d4594_815020 *gui.Window
var dword_5d4594_1305680 *gui.Window
var dword_5d4594_815032 *gui.Window
var dword_5d4594_1193360 unsafe.Pointer
var dword_5d4594_1049520 *gui.Window
var dword_5d4594_1309748 *gui.Window
var dword_5d4594_1045464 *gui.Window
var dword_5d4594_1045484 *gui.Window
var dword_5d4594_1049856 uint32
var dword_5d4594_1064856 *gui.Window
var nox_xxx_aNox_cfg_0_587000_132132 uint32 = 0x1
var dword_5d4594_1217456 unsafe.Pointer
var dword_5d4594_1193348 unsafe.Pointer
var dword_5d4594_1047520 uint32
var dword_5d4594_534808 unsafe.Pointer
var dword_5d4594_1197324 int32
var dword_5d4594_1599576 uint32
var dword_5d4594_1599596 uint32
var dword_5d4594_1045480 *gui.Window
var dword_5d4594_2487556 unsafe.Pointer
var dword_5d4594_1523024 *gui.Window
var dword_5d4594_2516344 uint32
var dword_5d4594_1046508 *gui.Window
var dword_5d4594_1193384 *gui.Window
var dword_5d4594_1045536 *gui.Window
var nox_wol_servers_sorting_166704 uint32 = 0x6
var dword_5d4594_371692 uint32
var dword_5d4594_3798832 int32
var dword_5d4594_1197320 *gui.Window
var nox_alloc_pixelSpan_1301844 *nox_alloc_class
var dword_5d4594_3798808 int32
var dword_5d4594_1062524 *gui.Window
var dword_5d4594_3835396 uint32
var dword_5d4594_1062528 *gui.Window
var dword_5d4594_1522604 *gui.Window
var dword_5d4594_3798816 int32
var dword_5d4594_1045532 *gui.Window
var dword_5d4594_528256 uint32
var dword_5d4594_1568024 unsafe.Pointer
var dword_5d4594_1308088 *gui.Window
var dword_5d4594_826028 *gui.Window
var dword_5d4594_2487524 uint32
var dword_5d4594_1522612 *gui.Window
var dword_5d4594_1045468 *gui.Window
var nox_xxx_lightningTargetArrayIndex_5d4594_2487904 uint32
var dword_587000_127004 unsafe.Pointer
var nox_alloc_visitNode_2386184 unsafe.Pointer
var nox_wol_server_result_cnt_815088 uint32
var dword_5d4594_1046924 *ImageRef
var nox_xxx_polygonNextAngle_587000_60356 uint32 = 0x1
var dword_5d4594_1217460 int32
var dword_5d4594_1307716 *gui.Window
var dword_587000_93156 uint32 = 0x1
var dword_5d4594_2523780 unsafe.Pointer
var dword_5d4594_2650676 uint32
var dword_5d4594_1321252 *gui.Window
var dword_5d4594_1522632 *gui.Window
var dword_5d4594_531648 unsafe.Pointer
var dword_5d4594_1045432 uint32
var dword_5d4594_815044 uint32
var nox_wnd_briefing_831232 *gui.Window
var dword_5d4594_2487712 uint32
var nox_alloc_tradeItems_2386496 unsafe.Pointer
var dword_5d4594_2386180 uint32
var dword_5d4594_2386212 uint32
var dword_5d4594_1319060 *gui.Window
var dword_5d4594_1047548 uint32
var dword_5d4594_816340 uint32
var dword_5d4594_1049512 *gui.Window
var dword_5d4594_1047932 uint32
var dword_5d4594_816368 uint32
var dword_5d4594_1062476 *gui.Window
var dword_5d4594_1090276 *gui.Window
var dword_5d4594_1049496 uint32
var dword_587000_93164 unsafe.Pointer
var dword_5d4594_1098624 uint32
var dword_5d4594_1569672 uint32
var dword_5d4594_1197316 *gui.Window
var dword_5d4594_2386576 *server.Object
var dword_5d4594_1569756 uint32
var dword_5d4594_1320968 *client.Drawable
var dword_5d4594_2488604 unsafe.Pointer
var qword_581450_9544 float64 = 0.5
var qword_5d4594_1567940 uint64 = 0
var qword_581450_10256 float64 = 0.01
var qword_581450_9552 float64 = 65536
var qword_581450_9512 float64 = 1
var qword_5d4594_815068 uint64 = 0
var qword_5d4594_814956 uint64 = 0
var qword_581450_10176 float64 = 0.10000000149011612
var dword_5d4594_1316408 uint32
var dword_587000_292492 uint32 = 0x42C80000
var nox_client_translucentFrontWalls_805844 uint32
var dword_5d4594_1309732 *gui.Window
var dword_5d4594_1321204 unsafe.Pointer
var dword_5d4594_2386500 uint32
var dword_5d4594_2649712 uint32
var dword_5d4594_1046532 *gui.Window
var dword_5d4594_3798828 uint32
var dword_5d4594_1309728 *gui.Window
var dword_5d4594_1309836 *gui.Window
var dword_5d4594_1320992 uint32
var dword_5d4594_1047552 uint32
var dword_587000_60044 int32 = -1
var dword_5d4594_251560 unsafe.Pointer
var dword_5d4594_3484 uint32
var nox_alloc_screenParticles_806044 unsafe.Pointer
var dword_5d4594_528252 uint32
var dword_5d4594_1309828 *gui.Window
var dword_587000_122852 unsafe.Pointer
var dword_5d4594_1301776 unsafe.Pointer
var dword_5d4594_251564 *breakableWall
var nox_xxx_screenWidth_587000_184452 uint32 = 0x32
var dword_5d4594_1550916 *mapgenRoom
var dword_5d4594_2487540 int32
var dword_587000_81128 unsafe.Pointer
var dword_5d4594_3798800 int32
var dword_5d4594_3798812 uint32
var dword_5d4594_1046952 *gui.Window
var dword_5d4594_832536 *client.Drawable
var dword_587000_87408 uint32 = 0x1
var dword_5d4594_814988 uint32
var dword_5d4594_2487560 *mapgenRoom
var dword_5d4594_1062516 int32
var dword_5d4594_1316492 uint32
var dword_5d4594_2491616 uint32
var dword_5d4594_251744 uint32
var dword_5d4594_1313792 *client.Drawable
var dword_5d4594_2487248 uint32
var dword_5d4594_1046516 *gui.Window
var nox_xxx_warriorMaxHealth_587000_312784 float32 = 1.0
var nox_xxx_warriorMaxMana_587000_312788 float32 = 1.0
var nox_xxx_conjurerMaxHealth_587000_312800 float32 = 1.0
var nox_xxx_conjurerMaxMana_587000_312804 float32 = 1.0
var nox_xxx_wizardMaxHealth_587000_312816 float32 = 1.0
var nox_xxx_wizardMaximumMana_587000_312820 float32 = 1.0
var dword_5d4594_2487532 unsafe.Pointer
var nox_server_connectionType_3596 uint32
var dword_5d4594_830872 unsafe.Pointer
var dword_5d4594_1200804 uint32
var dword_5d4594_1049484 uint32
var dword_5d4594_1599712 uint32
var dword_5d4594_1321216 *gui.Window
var dword_5d4594_2386160 uint32
var dword_5d4594_1193712 *gui.Window
var dword_5d4594_1319232 *gui.Window
var dword_5d4594_1046656 int32
var dword_5d4594_832532 *client.Drawable
var dword_5d4594_2650680 uint32
var dword_5d4594_588120 unsafe.Pointer
var dword_5d4594_1047512 int32
var dword_5d4594_588084 unsafe.Pointer
var dword_5d4594_1321044 *gui.Window
var dword_5d4594_816372 uint32
var dword_5d4594_832492 *client.Drawable
var dword_5d4594_1046504 *gui.Window
var dword_5d4594_1045508 *gui.Window
var dword_5d4594_825744 *gui.Window
var dword_5d4594_1217452 uint32
var dword_5d4594_1319264 uint32
var dword_5d4594_1046928 *ImageRef
var dword_5d4594_1098580 *gui.Window
var dword_5d4594_831224 uint32
var nox_xxx_energyBoltTarget_5d4594_2487880 uint32
var dword_5d4594_832504 *client.Drawable
var dword_5d4594_1203864 unsafe.Pointer
var dword_5d4594_832508 *client.Drawable
var dword_5d4594_1090100 unsafe.Pointer
var dword_5d4594_3835356 uint32
var nox_client_renderBubbles_80844 uint32 = 0x1
var dword_5d4594_814996 unsafe.Pointer
var dword_5d4594_1049532 *gui.Window
var nox_alloc_chat_1197364 unsafe.Pointer
var dword_5d4594_1046520 *gui.Window
var dword_5d4594_832516 *client.Drawable
var nox_xxx_aNox_cfg_0_587000_132136 int32 = -1
var dword_5d4594_832496 *client.Drawable
var dword_5d4594_832512 *client.Drawable
var dword_5d4594_832524 *client.Drawable
var dword_5d4594_823776 uint32
var dword_5d4594_1045688 *gui.Window
var dword_5d4594_832528 *client.Drawable
var dword_5d4594_832500 *client.Drawable
var dword_5d4594_832520 *client.Drawable
var dword_5d4594_1046636 int32
var dword_5d4594_1046500 uint32
var dword_587000_136184 uint32 = 0xFFFFFF1F
var dword_5d4594_1098592 uint32
var dword_5d4594_1321032 *gui.Window
var dword_5d4594_251720 uint32
var dword_5d4594_1320932 unsafe.Pointer
var dword_5d4594_1197332 uint32
var dword_5d4594_1319056 uint32
var dword_5d4594_1047528 int32
var dword_5d4594_830864 uint32
var dword_5d4594_608316 uint32
var dword_5d4594_1046948 *gui.Window
var dword_5d4594_1046528 *gui.Window
var dword_5d4594_741364 int32
var dword_5d4594_1046932 int32
var dword_5d4594_1321224 *gui.Window
var dword_5d4594_588068 unsafe.Pointer
var dword_587000_122848 uint32 = 0x1
var dword_5d4594_1045460 uint32
var dword_5d4594_831220 uint32
var dword_5d4594_1203840 uint32
var dword_5d4594_826032 *gui.Window
var dword_5d4594_2487708 uint32
var nox_xxx_waypointCounterMB_587000_154948 uint32 = math.MaxUint32
var dword_5d4594_1548700 *server.Player
var dword_5d4594_741332 uint32
var dword_5d4594_1565616 uint32
var dword_5d4594_816356 uint32
var dword_5d4594_1203836 uint32
var dword_5d4594_1301780 unsafe.Pointer
var dword_5d4594_1064864 unsafe.Pointer
var dword_5d4594_1096252 uint32
var dword_5d4594_741356 int32
var dword_5d4594_1197356 unsafe.Pointer
var dword_5d4594_1045436 unsafe.Pointer
var dword_5d4594_1321800 int32
var dword_5d4594_1197336 uint32
var dword_5d4594_1197352 unsafe.Pointer
var dword_5d4594_826036 unsafe.Pointer
var dword_5d4594_1064860 *gui.Window
var dword_5d4594_1046536 *gui.Window
var dword_5d4594_1062468 *gui.Window
var dword_5d4594_1523036 *gui.Window
var dword_5d4594_1197328 int32
var dword_5d4594_1090044 uint32
var dword_5d4594_1305748 uint32
var nox_alloc_respawn_1568020 *nox_alloc_class
var nox_alloc_monsterList_2386220 unsafe.Pointer
var nox_xxx_lightningClosestTargetDistance_5d4594_2487912 uint32
var dword_5d4594_1567928 uint32
var dword_5d4594_1307720 int32
var dword_5d4594_2386920 uint32
var dword_5d4594_2386564 uint32
var nox_alloc_magicWall_1569748 unsafe.Pointer
var dword_5d4594_1550912 *mapgenRoom
var dword_5d4594_1062488 uint32
var dword_5d4594_2516356 uint32
var dword_5d4594_1047936 int32
var dword_5d4594_1321208 uint32
var dword_5d4594_2487620 uint32
var dword_5d4594_1309824 *gui.Window
var dword_5d4594_531656 uint32
var nox_alloc_tradeSession_2386492 unsafe.Pointer
var dword_5d4594_1096288 unsafe.Pointer
var dword_5d4594_3835352 uint32
var dword_5d4594_1046956 *gui.Window
var dword_587000_145664 uint32 = 0x1
var dword_5d4594_1316704 uint32
var dword_5d4594_825736 uint32
var dword_5d4594_1313540 uint32
var dword_5d4594_1096284 uint32
var dword_5d4594_2487624 uint32
var dword_5d4594_1309832 *gui.Window
var dword_5d4594_2487576 uint32
var dword_5d4594_1309756 *gui.Window
var dword_5d4594_831084 uint32
var dword_5d4594_1309736 *gui.Window
var nox_client_gui_flag_1556112 uint32
var dword_5d4594_1301812 uint32
var nox_alloc_friendList_1203860 unsafe.Pointer
var dword_5d4594_2660032 uint32
var dword_5d4594_1090040 uint32
var dword_5d4594_3835348 uint32
var dword_5d4594_1045692 *gui.Window
var dword_5d4594_1046640 int32
var dword_5d4594_1320972 unsafe.Pointer
var dword_5d4594_1096260 uint32
var dword_5d4594_529336 uint32
var dword_5d4594_1308124 *gui.Window
var dword_5d4594_2487652 uint32
var dword_5d4594_2523776 *server.Object
var dword_5d4594_3835388 uint32
var dword_5d4594_1046648 uint32
var dword_5d4594_831276 float32
var dword_5d4594_1301816 uint32
var dword_5d4594_2491552 uint32
var dword_5d4594_1045588 *gui.Window
var dword_5d4594_1599616 uint32
var dword_5d4594_1319236 *gui.Window
var dword_5d4594_815056 uint32
var dword_5d4594_1308128 *gui.Window
var nox_client_connError_814552 uint32
var dword_5d4594_10984 uint32
var dword_587000_145668 uint32 = 0x6
var dword_587000_180480 uint32 = 0x0
var dword_587000_230092 uint32 = 0x6
var dword_5d4594_1197372 unsafe.Pointer
var dword_5d4594_251716 uint32
var dword_5d4594_251708 uint32
var dword_5d4594_1063120 uint32
var dword_5d4594_1046540 *gui.Window
var dword_5d4594_1062496 uint32
var nox_alloc_vote_1599652 unsafe.Pointer
var dword_5d4594_1049804 uint32
var dword_5d4594_1090112 uint32
var dword_5d4594_3807140 int32
var dword_5d4594_2487676 uint32
var dword_5d4594_1049696 unsafe.Pointer
var dword_5d4594_1316476 uint32
var dword_5d4594_2488652 uint32
var nox_alloc_spawn_2386216 unsafe.Pointer
var dword_5d4594_2487672 uint32
var nox_alloc_magicEnt_1569668 unsafe.Pointer
var dword_5d4594_814992 uint32
var dword_587000_66116 int32 = 0x1D
var dword_5d4594_2487564 uint32
var dword_5d4594_3804684 int32
var dword_5d4594_830972 unsafe.Pointer
var dword_5d4594_1308120 *gui.Window
var dword_5d4594_2488608 unsafe.Pointer
var dword_5d4594_1568868 uint32
var dword_5d4594_1090108 uint32
var dword_5d4594_1308108 *gui.Window
var dword_5d4594_3835312 uint32
var dword_5d4594_1197308 uint32
var dword_5d4594_1045584 *gui.Window
var dword_5d4594_814548 uint32
var dword_5d4594_1308132 *gui.Window
var dword_5d4594_2386228 uint32
var dword_5d4594_1308100 *gui.Window
var nox_server_sanctuaryHelp_54276 uint32 = 0x1
var dword_5d4594_1045424 unsafe.Pointer
var nox_alloc_pendingOwn_2386916 unsafe.Pointer
var dword_5d4594_1313740 uint32
var dword_587000_237036 uint32 = 0x1
var dword_5d4594_1062492 *client.Drawable
var dword_5d4594_1098604 *wchar2_t
var nox_server_needInitNetCodeCache uint32 = 0x1
var dword_5d4594_1308116 *gui.Window
var dword_5d4594_1319248 uint32
var dword_5d4594_3807136 int32
var dword_5d4594_1046944 *gui.Window
var dword_5d4594_2487584 uint32
var dword_5d4594_251712 uint32
var dword_5d4594_531652 uint32
var dword_5d4594_2487948 uint32
var nox_alloc_healthChange_1301772 *nox_alloc_class
var dword_5d4594_1522596 unsafe.Pointer
var dword_5d4594_1049536 uint32
var dword_5d4594_1098616 uint32
var dword_5d4594_3807152 int32
var dword_5d4594_1049996 noxrender.ImageHandle
var dword_5d4594_1305788 uint32
var dword_5d4594_1098600 *wchar2_t
var dword_5d4594_2523760 uint32
var dword_5d4594_1064868 uint32
var dword_5d4594_1320988 uint32
var dword_5d4594_1599696 uint32
var dword_587000_261388 uint32 = 0x42480000
var dword_5d4594_1200768 uint32
var dword_5d4594_1523032 *gui.Window
var dword_5d4594_831256 uint32
var dword_5d4594_1316436 uint32
var dword_587000_145672 uint32 = math.MaxUint32
var dword_5d4594_1046864 uint32
var dword_5d4594_1523044 *gui.Window
var dword_5d4594_1046356 noxrender.ImageHandle
var dword_5d4594_3799452 uint32
var dword_5d4594_1096280 uint32
var dword_5d4594_1316472 uint32
var dword_5d4594_1062560 int32
var dword_5d4594_2491544 uint32
var dword_587000_183456 int32 = 0x67
var nox_xxx_lightningOwner_5d4594_2487900 uint32
var dword_5d4594_1096256 uint32
var dword_5d4594_1046524 uint32
var dword_5d4594_2523764 uint32
var dword_5d4594_2487244 *server.Waypoint
var dword_5d4594_1090280 uint32
var dword_5d4594_1200796 uint32
var dword_5d4594_1313536 uint32
var dword_5d4594_1308152 *gui.Window
var dword_5d4594_1098596 *wchar2_t
var dword_5d4594_1047524 uint32
var dword_5d4594_1563096 uint32
var dword_5d4594_1062564 int32
var dword_5d4594_1308144 *gui.Window
var dword_5d4594_1049524 unsafe.Pointer
var dword_5d4594_1316484 uint32
var dword_5d4594_1320936 unsafe.Pointer
var dword_5d4594_1045552 *gui.Window
var dword_587000_234176 uint32 = 0x41380000
var dword_5d4594_1096264 uint32
var dword_5d4594_831076 uint32
var dword_5d4594_1321024 noxrender.ImageHandle
var dword_5d4594_1523048 *gui.Window
var dword_5d4594_1308140 *gui.Window
var dword_5d4594_1203832 uint32
var dword_5d4594_831244 uint32
var dword_5d4594_2516372 uint32
var dword_5d4594_1565632 uint32
var dword_5d4594_1045520 *gui.Window
var dword_5d4594_1319268 uint32
var dword_5d4594_1321520 uint32
var dword_5d4594_526276 uint32
var dword_5d4594_1062556 int32
var dword_5d4594_1049992 noxrender.ImageHandle
var dword_587000_171388 uint32 = 0x1
var dword_5d4594_2489460 uint32
var dword_5d4594_816412 *gui.Window
var dword_5d4594_1308148 *gui.Window
var dword_5d4594_1062484 uint32
var dword_5d4594_528260 uint32
var dword_5d4594_1090284 uint32
var dword_5d4594_1301796 uint32
var dword_5d4594_2487932 uint32
var dword_5d4594_2487628 uint32
var dword_5d4594_1045544 *gui.Window
var dword_5d4594_1548480 uint32
var nox_xxx_lightningSteps_587000_178216 uint32 = 0x8
var dword_5d4594_1045428 unsafe.Pointer
var dword_5d4594_2487536 int32
var dword_5d4594_2523804 uint32
var dword_587000_126996 uint32 = 0x1
var dword_5d4594_2487568 uint32
var dword_5d4594_1045540 *gui.Window
var dword_5d4594_2487580 uint32
var dword_5d4594_1556856 *server.Object
var dword_5d4594_1046360 noxrender.ImageHandle
var dword_5d4594_1049976 noxrender.ImageHandle
var dword_5d4594_1193188 uint32
var dword_5d4594_1565628 uint32
var dword_5d4594_816444 uint32
var nox_server_sendMotd_108752 uint32 = 0x1
var dword_5d4594_1096276 uint32
var dword_5d4594_3835392 uint32
var dword_5d4594_1123520 uint32
var dword_5d4594_2488720 uint32
var dword_5d4594_1567988 uint32
var dword_5d4594_1308112 *gui.Window
var dword_5d4594_832480 uint32
var dword_5d4594_1568308 uint32
var dword_587000_129656 uint32 = 0x1
var dword_5d4594_1091364 uint32
var dword_5d4594_599496 uint32
var dword_5d4594_2516380 uint32
var dword_5d4594_1599644 uint32
var dword_5d4594_1563276 uint32
var nox_server_resetQuestMinVotes_229988 uint32 = 0x6
var dword_5d4594_1062520 int32
var dword_5d4594_831260 uint32
var dword_5d4594_1049516 *gui.Window
var dword_5d4594_1090292 uint32
var dword_5d4594_527660 uint32
var dword_5d4594_2489160 uint32
var dword_5d4594_1522968 int32
var dword_5d4594_2490508 uint32
var dword_5d4594_1316456 uint32
var dword_5d4594_1045640 uint32
var dword_5d4594_528264 uint32
var dword_5d4594_1098620 uint32
var dword_5d4594_1200776 uint32
var dword_5d4594_1045548 *gui.Window
var dword_5d4594_1316412 uint32
var dword_5d4594_3807116 int32
var dword_5d4594_815100 uint32
var dword_5d4594_1321036 uint32
var dword_5d4594_1049808 uint32
var dword_5d4594_1568300 uint32
var dword_5d4594_1563320 uint32
var dword_5d4594_1313692 uint32
var dword_5d4594_1599688 uint32
var dword_5d4594_2386164 uint32
var nox_server_kickQuestPlayerMinVotes_229992 uint32 = 0x5
var dword_5d4594_1523040 *gui.Window
var dword_5d4594_1096272 uint32
var dword_5d4594_1096636 int32
var dword_5d4594_1522956 uint32
var dword_587000_183460 int32 = 0x26
var dword_5d4594_1303508 unsafe.Pointer
var dword_5d4594_1568288 uint32
var dword_5d4594_2491704 uint32
var dword_5d4594_1320948 uint32
var dword_5d4594_1568280 uint32
var dword_5d4594_1556144 uint32
var dword_5d4594_1050008 *ImageRef
var dword_5d4594_3835372 uint32
var dword_5d4594_1556136 uint32
var dword_5d4594_2386168 uint32
var dword_5d4594_527656 uint32
var dword_5d4594_741652 uint32
var dword_5d4594_1308096 *gui.Window
var dword_5d4594_600116 libc.Time
var dword_5d4594_2487884 uint32
var dword_5d4594_1313564 uint32
var dword_5d4594_1568028 uint32
var dword_5d4594_815052 uint32
var dword_5d4594_1548524 uint32
var dword_5d4594_2386560 uint32
var dword_5d4594_1556316 uint32
var dword_5d4594_741648 uint32
var dword_5d4594_1556128 uint32
var dword_5d4594_2386548 uint32
var dword_5d4594_2491592 uint32
var dword_5d4594_1090828 uint32
var dword_5d4594_815096 uint32
var dword_5d4594_529332 uint32
var dword_5d4594_1313816 uint32
var dword_5d4594_1193352 *gui.Window
var dword_5d4594_2488724 uint32
var dword_5d4594_1548532 unsafe.Pointer
var dword_5d4594_1045580 *gui.Window
var dword_5d4594_1313532 uint32
var dword_5d4594_805820 uint32
var dword_5d4594_1308104 *gui.Window
var dword_5d4594_2489436 uint32
var dword_5d4594_1320944 uint32
var nox_xxx_normalWndBits_587000_172880 uint32 = 0x8
var dword_5d4594_527988 uint32
var dword_5d4594_2491588 uint32
var dword_5d4594_1316448 uint32
var dword_5d4594_1313880 float32
var dword_5d4594_2491676 uint32
var dword_5d4594_1308136 *gui.Window
var dword_5d4594_1569656 uint32
var dword_5d4594_831240 *byte
var dword_5d4594_1301808 uint32
var dword_5d4594_1599708 uint32
var dword_587000_292488 uint32 = 0x42200000
var dword_5d4594_1321196 uint32
var dword_5d4594_815748 uint32
var dword_5d4594_1045556 *gui.Window
var dword_5d4594_1045420 unsafe.Pointer
var dword_5d4594_739392 uint32
var dword_5d4594_2488728 uint32
var dword_5d4594_1567960 uint32
var dword_5d4594_1049844 uint32
var dword_5d4594_3835364 uint32
var dword_5d4594_1313788 uint32
var dword_5d4594_1304328 uint32
var dword_5d4594_1047536 int32
var dword_5d4594_2516352 uint32
var dword_5d4594_1549844 int32
var dword_5d4594_1313804 uint32
var nox_xxx_respawnAllow_587000_205200 uint32 = 0x1
var dword_5d4594_2386172 uint32
var dword_5d4594_1046652 uint32
var dword_5d4594_2487632 uint32
var dword_5d4594_3835360 uint32
var dword_5d4594_1098456 noxrender.ImageHandle
var dword_5d4594_1062552 int32
var nox_xxx_aSpellphoneme_3_587000_123008 uint32 = 0x1
var dword_5d4594_811904 uint32
var dword_5d4594_2491580 uint32
var dword_5d4594_1200832 uint32
var dword_5d4594_1319260 uint32
var nox_alloc_hit_2491548 unsafe.Pointer
var dword_5d4594_2488656 uint32
var dword_5d4594_2386552 uint32
var dword_5d4594_3835368 uint32
var dword_5d4594_527712 uint32
var nox_xxx_useAudio_587000_80772 uint32 = 0x5
var dword_5d4594_1307792 uint32
var dword_5d4594_830272 uint32
var dword_5d4594_2386836 uint32
var dword_5d4594_2490504 uint32
var dword_5d4594_1316452 uint32
var dword_5d4594_1049692 unsafe.Pointer
var dword_5d4594_1045596 *gui.Window
var dword_5d4594_2488620 uint32
var dword_5d4594_1047532 int32
var dword_5d4594_1045576 *gui.Window
var dword_5d4594_2487656 uint32
var dword_587000_122956 uint32 = 0x1
var dword_5d4594_2491716 uint32
var dword_587000_180476 uint32 = 0x0
var dword_5d4594_1046852 int32
var array_5D4594_1049872 [9]*client.Drawable
