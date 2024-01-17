package legacy

import (
	"bytes"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/stdio"
	"github.com/noxworld-dev/opennox-lib/console"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/server"
)

const (
	NOX_CLIENT_VERS_CODE = 0x0001039A // FIXME: highres support
	NOX_MAX_WIDTH        = 1024       // FIXME: highres support
	NOX_MAX_HEIGHT       = 768        // FIXME: highres support
)

const (
	NOX_DEFAULT_WIDTH  = 640
	NOX_DEFAULT_HEIGHT = 480

	NOX_INVENTORY_ROW_COUNT = 21
	NOX_INVENTORY_COL_COUNT = 4
	NOX_INVENTORY_CELLS_MAX = NOX_INVENTORY_ROW_COUNT * NOX_INVENTORY_COL_COUNT

	NOX_PLAYER_MAX_LEVEL = 10

	NOX_PLAYERINFO_MAX = 32

	NOX_SPELLS_MAX = 137
)

const (
	NOX_CONSOLE_RED    = byte(console.ColorRed)
	NOX_CONSOLE_WHITE  = byte(console.ColorWhite)
	NOX_CONSOLE_YELLOW = byte(console.ColorYellow)
)

const (
	NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING = noxflags.EngineNoRendering
	NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING    = noxflags.EngineNoFloorRendering
	NOX_ENGINE_FLAG_ENABLE_SHOW_AI             = noxflags.EngineShowAI
	NOX_ENGINE_FLAG_GODMODE                    = noxflags.EngineGodMode
	NOX_ENGINE_FLAG_REPLAY_READ                = noxflags.EngineReplayRead
	NOX_ENGINE_FLAG_ADDITIONAL_NETWORK_TEST    = noxflags.EngineAddNetworkTest
	NOX_ENGINE_FLAG_ENABLE_NET_DEBUG           = noxflags.EngineNetDebug
	NOX_ENGINE_FLAG_9                          = noxflags.EngineFlag9
)

const (
	NOX_GUI_ANIM_OUT_DONE = gui.AnimOutDone
	NOX_GUI_ANIM_OUT      = gui.AnimOut
	NOX_GUI_ANIM_IN       = gui.AnimIn
)

type nox_player_polygon_check_data struct {
	field_0 [35]int32
}
type nox_playerInfo_journal struct {
	entry   [64]byte
	next    *nox_playerInfo_journal
	prev    *nox_playerInfo_journal
	field_3 uint16
	field_4 uint16
}
type pixel8888 struct {
	field_0 int8
	field_1 int8
	field_2 int8
	field_3 int8
}
type obj_5D4594_754088_t struct {
	Fnc     unsafe.Pointer
	Field_4 int32
	Name    [12]byte
}
type obj_5D4594_2650668_t2 struct {
	Field0  int32
	Field4  int32
	Field8  int32
	Field12 int32
	Field16 unsafe.Pointer
}
type obj_5D4594_2650668_t struct {
	Field0  uint8
	Field1  uint8
	Field2  uint16
	Field4  obj_5D4594_2650668_t2
	Field24 obj_5D4594_2650668_t2
}
type nox_parse_thing_draw_funcs_t struct {
	name      string
	draw      client.ObjectDrawFunc
	kind      uint32
	parse_fnc func(*client.ObjectType, *binfile.MemFile, *byte) bool
}
type nox_inventory_cell_t struct {
	field_0   *client.Drawable
	field_4   uint32
	data_4    [30]uint32
	field_128 uint32
	field_132 uint32
	field_136 uint32
	field_140 uint8
	field_141 uint8
	field_142 uint8
	field_143 uint8
	field_144 uint32
}
type nox_scrollListBox_item struct {
	field_0   uint32        // 0, 0
	text      [256]wchar2_t // 1, 4
	field_129 uint32        // 129, 516
	field_130 uint32        // 130, 520
}

func (it *nox_scrollListBox_item) Text() string {
	return GoWString(&it.text[0])
}

type nox_scrollListBox_data struct {
	count       uint16
	line_height uint16
	field_1     uint32
	field_2     uint32
	field_3     uint32
	field_4     uint32
	field_5     uint32
	items       *nox_scrollListBox_item
	field_7     *gui.Window
	field_8     *gui.Window
	field_9     *gui.Window
	field_10    uint32
	field_11_0  uint16
	field_11_1  uint16
	field_12    *uint32 // used as uint32 when field_4 == 0
	field_13_0  uint16
	field_13_1  uint16
}

func (d *nox_scrollListBox_data) Items() []nox_scrollListBox_item {
	if d == nil || d.items == nil || d.count == 0 {
		return nil
	}
	return unsafe.Slice(d.items, d.count)
}

type nox_staticText_data struct {
	text   *wchar2_t
	center uint32
	glow   uint32
}
type nox_npc struct {
	live      byte
	_         [3]byte
	id        int32
	color8    [6]uint32 // 2, 8
	field32   uint32    // 8, 32
	field36   uint32    // 9, 36
	field40   uint32    // 10, 40
	field44   uint32    // 11, 44
	field48   uint32    // 12, 48
	field52   uint32    // 13, 52
	field56   uint32    // 14, 56
	field60   uint32    // 15, 60
	field64   uint32    // 16, 64
	field68   uint32    // 17, 68
	field72   uint32    // 18, 72
	field76   uint32    // 19, 76
	field80   uint32    // 20, 80
	field84   uint32    // 21, 84
	field88   uint32    // 22, 88
	field92   uint32    // 23, 92
	field96   uint32    // 24, 96
	field100  uint32    // 25, 100
	field104  uint32    // 26, 104
	field108  uint32    // 27, 108
	field112  uint32    // 28, 112
	field116  uint32    // 29, 116
	field120  uint32    // 30, 120
	field124  uint32    // 31, 124
	field128  uint32    // 32, 128
	field132  uint32    // 33, 132
	field136  uint32    // 34, 136
	field140  uint32    // 35, 140
	field144  uint32    // 36, 144
	field148  uint32    // 37, 148
	field152  uint32    // 38, 152
	field156  uint32    // 39, 156
	field160  uint32    // 40, 160
	field164  uint32    // 41, 164
	field168  uint32    // 42, 168
	field172  uint32    // 43, 172
	field176  uint32    // 44, 176
	field180  uint32    // 45, 180
	field184  uint32    // 46, 184
	field188  uint32    // 47, 188
	field192  uint32    // 48, 192
	field196  uint32    // 49, 196
	field200  uint32    // 50, 200
	field204  uint32    // 51, 204
	field208  uint32    // 52, 208
	field212  uint32    // 53, 212
	field216  uint32    // 54, 216
	field220  uint32    // 55, 220
	field224  uint32    // 56, 224
	field228  uint32    // 57, 228
	field232  uint32    // 58, 232
	field236  uint32    // 59, 236
	field240  uint32    // 60, 240
	field244  uint32    // 61, 244
	field248  uint32    // 62, 248
	field252  uint32    // 63, 252
	field256  uint32    // 64, 256
	field260  uint32    // 65, 260
	field264  uint32    // 66, 264
	field268  uint32    // 67, 268
	field272  uint32    // 68, 272
	field276  uint32    // 69, 276
	field280  uint32    // 70, 280
	field284  uint32    // 71, 284
	field288  uint32    // 72, 288
	field292  uint32    // 73, 292
	field296  uint32    // 74, 296
	field300  uint32    // 75, 300
	field304  uint32    // 76, 304
	field308  uint32    // 77, 308
	field312  uint32    // 78, 312
	field316  uint32    // 79, 316
	field320  uint32    // 80, 320
	field324  uint32    // 81, 324
	field328  uint32    // 82, 328
	field332  uint32    // 83, 332
	field336  uint32    // 84, 336
	field340  uint32    // 85, 340
	field344  uint32    // 86, 344
	field348  uint32    // 87, 348
	field352  uint32    // 88, 352
	field356  uint32    // 89, 356
	field360  uint32    // 90, 360
	field364  uint32    // 91, 364
	field368  uint32    // 92, 368
	field372  uint32    // 93, 372
	field376  uint32    // 94, 376
	field380  uint32    // 95, 380
	field384  uint32    // 96, 384
	field388  uint32    // 97, 388
	field392  uint32    // 98, 392
	field396  uint32    // 99, 396
	field400  uint32    // 100, 400
	field404  uint32    // 101, 404
	field408  uint32    // 102, 408
	field412  uint32    // 103, 412
	field416  uint32    // 104, 416
	field420  uint32    // 105, 420
	field424  uint32    // 106, 424
	field428  uint32    // 107, 428
	field432  uint32    // 108, 432
	field436  uint32    // 109, 436
	field440  uint32    // 110, 440
	field444  uint32    // 111, 444
	field448  uint32    // 112, 448
	field452  uint32    // 113, 452
	field456  uint32    // 114, 456
	field460  uint32    // 115, 460
	field464  uint32    // 116, 464
	field468  uint32    // 117, 468
	field472  uint32    // 118, 472
	field476  uint32    // 119, 476
	field480  uint32    // 120, 480
	field484  uint32    // 121, 484
	field488  uint32    // 122, 488
	field492  uint32    // 123, 492
	field496  uint32    // 124, 496
	field500  uint32    // 125, 500
	field504  uint32    // 126, 504
	field508  uint32    // 127, 508
	field512  uint32    // 128, 512
	field516  uint32    // 129, 516
	field520  uint32    // 130, 520
	field524  uint32    // 131, 524
	field528  uint32    // 132, 528
	field532  uint32    // 133, 532
	field536  uint32    // 134, 536
	field540  uint32    // 135, 540
	field544  uint32    // 136, 544
	field548  uint32    // 137, 548
	field552  uint32    // 138, 552
	field556  uint32    // 139, 556
	field560  uint32    // 140, 560
	field564  uint32    // 141, 564
	field568  uint32    // 142, 568
	field572  uint32    // 143, 572
	field576  uint32    // 144, 576
	field580  uint32    // 145, 580
	field584  uint32    // 146, 584
	field588  uint32    // 147, 588
	field592  uint32    // 148, 592
	field596  uint32    // 149, 596
	field600  uint32    // 150, 600
	field604  uint32    // 151, 604
	field608  uint32    // 152, 608
	field612  uint32    // 153, 612
	field616  uint32    // 154, 616
	field620  uint32    // 155, 620
	field624  uint32    // 156, 624
	field628  uint32    // 157, 628
	field632  uint32    // 158, 632
	field636  uint32    // 159, 636
	field640  uint32    // 160, 640
	field644  uint32    // 161, 644
	field648  uint32    // 162, 648
	field652  uint32    // 163, 652
	field656  uint32    // 164, 656
	field660  uint32    // 165, 660
	field664  uint32    // 166, 664
	field668  uint32    // 167, 668
	field672  uint32    // 168, 672
	field676  uint32    // 169, 676
	field680  uint32    // 170, 680
	field684  uint32    // 171, 684
	field688  uint32    // 172, 688
	field692  uint32    // 173, 692
	field696  uint32    // 174, 696
	field700  uint32    // 175, 700
	field704  uint32    // 176, 704
	field708  uint32    // 177, 708
	field712  uint32    // 178, 712
	field716  uint32    // 179, 716
	field720  uint32    // 180, 720
	field724  uint32    // 181, 724
	field728  uint32    // 182, 728
	field732  uint32    // 183, 732
	field736  uint32    // 184, 736
	field740  uint32    // 185, 740
	field744  uint32    // 186, 744
	field748  uint32    // 187, 748
	field752  uint32    // 188, 752
	field756  uint32    // 189, 756
	field760  uint32    // 190, 760
	field764  uint32    // 191, 764
	field768  uint32    // 192, 768
	field772  uint32    // 193, 772
	field776  uint32    // 194, 776
	field780  uint32    // 195, 780
	field784  uint32    // 196, 784
	field788  uint32    // 197, 788
	field792  uint32    // 198, 792
	field796  uint32    // 199, 796
	field800  uint32    // 200, 800
	field804  uint32    // 201, 804
	field808  uint32    // 202, 808
	field812  uint32    // 203, 812
	field816  uint32    // 204, 816
	field820  uint32    // 205, 820
	field824  uint32    // 206, 824
	field828  uint32    // 207, 828
	field832  uint32    // 208, 832
	field836  uint32    // 209, 836
	field840  uint32    // 210, 840
	field844  uint32    // 211, 844
	field848  uint32    // 212, 848
	field852  uint32    // 213, 852
	field856  uint32    // 214, 856
	field860  uint32    // 215, 860
	field864  uint32    // 216, 864
	field868  uint32    // 217, 868
	field872  uint32    // 218, 872
	field876  uint32    // 219, 876
	field880  uint32    // 220, 880
	field884  uint32    // 221, 884
	field888  uint32    // 222, 888
	field892  uint32    // 223, 892
	field896  uint32    // 224, 896
	field900  uint32    // 225, 900
	field904  uint32    // 226, 904
	field908  uint32    // 227, 908
	field912  uint32    // 228, 912
	field916  uint32    // 229, 916
	field920  uint32    // 230, 920
	field924  uint32    // 231, 924
	field928  uint32    // 232, 928
	field932  uint32    // 233, 932
	field936  uint32    // 234, 936
	field940  uint32    // 235, 940
	field944  uint32    // 236, 944
	field948  uint32    // 237, 948
	field952  uint32    // 238, 952
	field956  uint32    // 239, 956
	field960  uint32    // 240, 960
	field964  uint32    // 241, 964
	field968  uint32    // 242, 968
	field972  uint32    // 243, 972
	field976  uint32    // 244, 976
	field980  uint32    // 245, 980
	field984  uint32    // 246, 984
	field988  uint32    // 247, 988
	field992  uint32    // 248, 992
	field996  uint32    // 249, 996
	field1000 uint32    // 250, 1000
	field1004 uint32    // 251, 1004
	field1008 uint32    // 252, 1008
	field1012 uint32    // 253, 1012
	field1016 uint32    // 254, 1016
	field1020 uint32    // 255, 1020
	field1024 uint32    // 256, 1024
	field1028 uint32    // 257, 1028
	field1032 uint32    // 258, 1032
	field1036 uint32    // 259, 1036
	field1040 uint32    // 260, 1040
	field1044 uint32    // 261, 1044
	field1048 uint32    // 262, 1048
	field1052 uint32    // 263, 1052
	field1056 uint32    // 264, 1056
	field1060 uint32    // 265, 1060
	field1064 uint32    // 266, 1064
	field1068 uint32    // 267, 1068
	field1072 uint32    // 268, 1072
	field1076 uint32    // 269, 1076
	field1080 uint32    // 270, 1080
	field1084 uint32    // 271, 1084
	field1088 uint32    // 272, 1088
	field1092 uint32    // 273, 1092
	field1096 uint32    // 274, 1096
	field1100 uint32    // 275, 1100
	field1104 uint32    // 276, 1104
	field1108 uint32    // 277, 1108
	field1112 uint32    // 278, 1112
	field1116 uint32    // 279, 1116
	field1120 uint32    // 280, 1120
	field1124 uint32    // 281, 1124
	field1128 uint32    // 282, 1128
	field1132 uint32    // 283, 1132
	field1136 uint32    // 284, 1136
	field1140 uint32    // 285, 1140
	field1144 uint32    // 286, 1144
	field1148 uint32    // 287, 1148
	field1152 uint32    // 288, 1152
	field1156 uint32    // 289, 1156
	field1160 uint32    // 290, 1160
	field1164 uint32    // 291, 1164
	field1168 uint32    // 292, 1168
	field1172 uint32    // 293, 1172
	field1176 uint32    // 294, 1176
	field1180 uint32    // 295, 1180
	field1184 uint32    // 296, 1184
	field1188 uint32    // 297, 1188
	field1192 uint32    // 298, 1192
	field1196 uint32    // 299, 1196
	field1200 uint32    // 300, 1200
	field1204 uint32    // 301, 1204
	field1208 uint32    // 302, 1208
	field1212 uint32    // 303, 1212
	field1216 uint32    // 304, 1216
	field1220 uint32    // 305, 1220
	field1224 uint32    // 306, 1224
	field1228 uint32    // 307, 1228
	field1232 uint32    // 308, 1232
	field1236 uint32    // 309, 1236
	field1240 uint32    // 310, 1240
	field1244 uint32    // 311, 1244
	field1248 uint32    // 312, 1248
	field1252 uint32    // 313, 1252
	field1256 uint32    // 314, 1256
	field1260 uint32    // 315, 1260
	field1264 uint32    // 316, 1264
	field1268 uint32    // 317, 1268
	field1272 uint32    // 318, 1272
	field1276 uint32    // 319, 1276
	field1280 uint32    // 320, 1280
	field1284 uint32    // 321, 1284
	field1288 uint32    // 322, 1288
	field1292 uint32    // 323, 1292
	field1296 uint32    // 324, 1296
	field1300 uint32    // 325, 1300
	field1304 uint32    // 326, 1304
	field1308 uint32    // 327, 1308
	field1312 uint32    // 328, 1312
}
type obj_412ae0_t struct {
	field_0  *byte
	field_1  uint32
	field_2  *wchar2_t
	field_3  *wchar2_t
	field_4  *wchar2_t
	field_5  int32
	field_6  uint32
	field_7  int32
	field_8  int32
	field_9  uint32
	field_10 unsafe.Pointer
	field_11 float32
	field_12 int32
	field_13 unsafe.Pointer
	field_14 float32
	field_15 int32
	field_16 unsafe.Pointer
	field_17 float32
	field_18 int32
	field_19 unsafe.Pointer
	field_20 float32
	field_21 int32
	field_22 unsafe.Pointer
	field_23 float32
	field_24 int32
	field_25 unsafe.Pointer
	field_26 float32
	field_27 int32
	field_28 unsafe.Pointer
	field_29 unsafe.Pointer
	field_30 float32
	field_31 int32
	field_32 float32
	field_33 int32
	field_34 *obj_412ae0_t
	field_35 *obj_412ae0_t
}
type nox_window_yyy struct {
	Win    *gui.Window
	Field4 uint32
	Field8 uint32
	Color1 uint32
	Color2 uint32
}
type nox_gui_server_ent_t struct {
	field_0     uint32
	field_1     uint32
	sort_key    int32
	addr        [16]byte
	field_7     int32
	field_8     uint32
	field_9     uint32
	field_10    uint32
	field_11_0  int16
	field_11_2  int16
	version     uint32
	field_13    uint32
	field_14    uint32
	field_15    uint32
	field_16    uint32
	field_17    uint32
	field_18    uint32
	field_19    uint32
	field_20    uint32
	field_21    uint32
	field_22    uint32
	field_23    uint32
	ping        int32
	status      uint8
	field_25_1  uint8
	field_25_2  uint8
	players     uint8
	max_players uint8
	field_26_1  uint16
	field_26_3  uint16
	port        uint16
	map_name    [9]byte
	server_name [15]byte
	field_33_3  [20]uint8
	field_38_3  uint32
	field_39_3  uint32
	flags       uint16
	quest_level uint16
	field_41_3  uint8
	field_42    uint8
}
type nox_dblLinkedList struct {
	value *server.Object
	next  *nox_dblLinkedList
	prev  *nox_dblLinkedList
}
type nox_server_netCodeCacheStruct struct {
	firstFreeObject *nox_dblLinkedList
	lastFreeObject  *nox_dblLinkedList
	objArray        [16]nox_dblLinkedList
	firstUsedObject *nox_dblLinkedList
	lastUsedObject  *nox_dblLinkedList
}
type JournalVal struct {
	Field0   [128]byte   // 0, 0, TODO: size
	Field128 uint32      // 32, 128
	Type132  uint32      // 33, 132
	Value136 uint32      // 34, 136
	Next140  *JournalVal // 35, 140
	Prev144  *JournalVal // 36, 144
}

func nox_gui_console_Printf_450C00(cl byte, format *wchar2_t, args ...any) {
	// since legacy code still calls it, we redirect into global printer instead of GUI printer
	var buf bytes.Buffer
	stdio.FprintfGo(&buf, GoWString(format), args...)
	GetConsole().Print(console.Color(cl), buf.String())
}
