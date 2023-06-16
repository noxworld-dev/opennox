package legacy

import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func Sub_460D40() bool {
	return dword_5d4594_1049508 != 0
}

func Sub_4D7140(a1 uint32) {
	dword_5d4594_1556144 = a1
}

func Sub_43AF30() uint32 {
	return dword_5d4594_815052
}

func Get_nox_player_netCode_85319C() uint32 {
	return nox_player_netCode_85319C
}
func Get_nox_wol_server_result_cnt_815088() int {
	return int(nox_wol_server_result_cnt_815088)
}
func Get_dword_5d4594_815044() int {
	return int(dword_5d4594_815044)
}
func Get_dword_587000_87412() int {
	return int(dword_587000_87412)
}
func Get_dword_5d4594_815000() *gui.Window {
	return AsWindowP(dword_5d4594_815000)
}
func Get_dword_587000_87408() int {
	return int(dword_587000_87408)
}
func Get_nox_game_createOrJoin_815048() int {
	return int(nox_game_createOrJoin_815048)
}
func Get_dword_5d4594_814996() *gui.Window {
	return AsWindowP(dword_5d4594_814996)
}
func Get_dword_5d4594_814984() *gui.Window {
	return AsWindowP(dword_5d4594_814984)
}
func Get_dword_5d4594_2488604() unsafe.Pointer {
	return dword_5d4594_2488604
}
func Get_dword_5d4594_528252() int {
	return int(dword_5d4594_528252)
}
func Get_dword_5d4594_528260() int {
	return int(dword_5d4594_528260)
}
func Get_dword_5d4594_1569656() int {
	return int(dword_5d4594_1569656)
}
func Get_dword_587000_122852() unsafe.Pointer {
	return dword_587000_122852
}
func Get_dword_587000_93164() unsafe.Pointer {
	return dword_587000_93164
}
func Get_nox_client_translucentFrontWalls_805844() int {
	return int(nox_client_translucentFrontWalls_805844)
}
func Get_nox_client_highResFrontWalls_80820() int {
	return int(nox_client_highResFrontWalls_80820)
}
func Get_nox_client_highResFloors_154952() int {
	return int(nox_client_highResFloors_154952)
}
func Get_nox_client_fadeObjects_80836() int {
	return int(nox_client_fadeObjects_80836)
}
func Get_nox_client_renderBubbles_80844() int {
	return int(nox_client_renderBubbles_80844)
}
func Get_nox_server_sanctuaryHelp_54276() int {
	return int(nox_server_sanctuaryHelp_54276)
}
func Get_nox_server_sendMotd_108752() int {
	return int(nox_server_sendMotd_108752)
}
func Get_nox_server_connectionType_3596() int {
	return int(nox_server_connectionType_3596)
}
func Get_nox_server_resetQuestMinVotes_229988() int {
	return int(nox_server_resetQuestMinVotes_229988)
}
func Get_nox_server_kickQuestPlayerMinVotes_229992() int {
	return int(nox_server_kickQuestPlayerMinVotes_229992)
}
func Get_dword_5d4594_816340() int {
	return int(dword_5d4594_816340)
}
func Get_dword_587000_93156() int {
	return int(dword_587000_93156)
}
func Get_dword_5d4594_816348() int {
	return int(dword_5d4594_816348)
}
func Get_dword_5d4594_811904() int {
	return int(dword_5d4594_811904)
}
func Get_dword_5d4594_1193156() int {
	return int(dword_5d4594_1193156)
}
func Get_dword_5d4594_1193188() int {
	return int(dword_5d4594_1193188)
}
func Get_dword_5d4594_1217464() int {
	return int(dword_5d4594_1217464)
}
func Set_dword_5d4594_1217464(v int) {
	dword_5d4594_1217464 = uint32(v)
}
func Get_dword_5d4594_3798840() int {
	return int(dword_5d4594_3798840)
}
func Get_dword_5d4594_3798824() int {
	return int(dword_5d4594_3798824)
}
func Get_dword_5d4594_3798836() int {
	return int(dword_5d4594_3798836)
}
func Get_dword_5d4594_3798820() int {
	return int(dword_5d4594_3798820)
}
func Get_nox_alloc_chat_1197364() unsafe.Pointer {
	return nox_alloc_chat_1197364
}
func Get_dword_5d4594_2660032() int {
	return int(dword_5d4594_2660032)
}
func Get_dword_5d4594_1090048() *gui.Window {
	return dword_5d4594_1090048
}
func Get_dword_5d4594_1090120() int {
	return int(dword_5d4594_1090120)
}
func Get_dword_5d4594_1090100() *gui.Window {
	return AsWindowP(dword_5d4594_1090100)
}
func Get_dword_5d4594_814624() unsafe.Pointer {
	return dword_5d4594_814624
}
func Get_dword_5d4594_251560() unsafe.Pointer {
	return dword_5d4594_251560
}
func Get_dword_5d4594_2489460() int {
	return int(dword_5d4594_2489460)
}
func Get_gameex_flags() uint32 {
	return gameex_flags
}
func Get_gameex_flags_ptr() *uint32 {
	return &gameex_flags
}
func Get_dword_5d4594_1064868() int {
	return int(dword_5d4594_1064868)
}
func Get_dword_5d4594_1316972() *gui.Window {
	return AsWindowP(dword_5d4594_1316972)
}
func Get_dword_5d4594_1599588() unsafe.Pointer {
	return dword_5d4594_1599588
}
func Get_dword_5d4594_1599592() unsafe.Pointer {
	return dword_5d4594_1599592
}
func Get_dword_5d4594_1599540() unsafe.Pointer {
	return dword_5d4594_1599540
}
func Get_dword_5d4594_1599476() int {
	return int(dword_5d4594_1599476)
}
func Get_dword_5d4594_1599548() unsafe.Pointer {
	return dword_5d4594_1599548
}
func Get_dword_5d4594_1599556() unsafe.Pointer {
	return dword_5d4594_1599556
}
func Get_dword_5d4594_1599532() unsafe.Pointer {
	return dword_5d4594_1599532
}
func Get_dword_5d4594_1200804() int {
	return int(dword_5d4594_1200804)
}
func Get_nox_gameDisableMapDraw_5d4594_2650672() int {
	return int(nox_gameDisableMapDraw_5d4594_2650672)
}
func Get_dword_5d4594_528256() int {
	return int(dword_5d4594_528256)
}
func Get_dword_5d4594_527988() int {
	return int(dword_5d4594_527988)
}
func Get_nox_alloc_screenParticles_806044() unsafe.Pointer {
	return nox_alloc_screenParticles_806044
}
func Get_dword_5d4594_251744() int {
	return int(dword_5d4594_251744)
}
func Get_dword_5d4594_830236() *gui.Window {
	return AsWindowP(dword_5d4594_830236)
}
func Get_dword_5d4594_830232() *gui.Window {
	return AsWindowP(dword_5d4594_830232)
}
func Get_dword_5d4594_831260() int {
	return int(dword_5d4594_831260)
}
func Get_dword_5d4594_831220() int {
	return int(dword_5d4594_831220)
}
func Get_nox_color_black_2650656() uint32 {
	return nox_color_black_2650656
}
func Get_nox_color_white_2523948() uint32 {
	return nox_color_white_2523948
}
func Get_nox_color_violet_2598268() uint32 {
	return nox_color_violet_2598268
}
func Get_nox_color_red_2589776() uint32 {
	return nox_color_red_2589776
}
func Get_nox_color_green_2614268() uint32 {
	return nox_color_green_2614268
}
func Get_nox_color_cyan_2649820() uint32 {
	return nox_color_cyan_2649820
}
func Get_nox_color_blue_2650684() uint32 {
	return nox_color_blue_2650684
}
func Get_nox_color_orange_2614256() uint32 {
	return nox_color_orange_2614256
}
func Get_nox_color_yellow_2589772() uint32 {
	return nox_color_yellow_2589772
}
func Get_nox_color_black_2650656_ptr() *uint32 {
	return &nox_color_black_2650656
}
func Get_nox_color_white_2523948_ptr() *uint32 {
	return &nox_color_white_2523948
}
func Get_nox_color_violet_2598268_ptr() *uint32 {
	return &nox_color_violet_2598268
}
func Get_nox_color_red_2589776_ptr() *uint32 {
	return &nox_color_red_2589776
}
func Get_nox_color_green_2614268_ptr() *uint32 {
	return &nox_color_green_2614268
}
func Get_nox_color_cyan_2649820_ptr() *uint32 {
	return &nox_color_cyan_2649820
}
func Get_nox_color_blue_2650684_ptr() *uint32 {
	return &nox_color_blue_2650684
}
func Get_nox_color_orange_2614256_ptr() *uint32 {
	return &nox_color_orange_2614256
}
func Get_nox_color_yellow_2589772_ptr() *uint32 {
	return &nox_color_yellow_2589772
}
func Get_dword_5d4594_823776() int {
	return int(dword_5d4594_823776)
}
func Get_dword_5d4594_831236() *gui.Window {
	return AsWindowP(dword_5d4594_831236)
}
func Get_dword_5d4594_1049844() int {
	return int(dword_5d4594_1049844)
}
func Get_dword_5d4594_3799452() int {
	return int(dword_5d4594_3799452)
}
func Get_dword_5d4594_1321236() *gui.Window {
	return dword_5d4594_1321236
}
func Get_dword_5d4594_1321240() *gui.Window {
	return dword_5d4594_1321240
}
func Get_dword_5d4594_1321244() *gui.Window {
	return dword_5d4594_1321244
}
func Get_dword_5d4594_1321248() *gui.Window {
	return dword_5d4594_1321248
}
func Get_dword_5d4594_1522616() *gui.Window {
	return dword_5d4594_1522616
}
func Get_dword_5d4594_1522620() *gui.Window {
	return dword_5d4594_1522620
}
func Get_dword_5d4594_1522624() *gui.Window {
	return dword_5d4594_1522624
}
func Get_dword_5d4594_1522628() *gui.Window {
	return dword_5d4594_1522628
}
func Get_dword_5d4594_1062452() *gui.Window {
	return dword_5d4594_1062452
}
func Get_dword_5d4594_2516356() int {
	return int(dword_5d4594_2516356)
}
func Get_dword_5d4594_1548524() int {
	return int(dword_5d4594_1548524)
}
func Get_dword_587000_155144() unsafe.Pointer {
	return dword_587000_155144
}
func Get_nox_alloc_magicEnt_1569668() unsafe.Pointer {
	return nox_alloc_magicEnt_1569668
}
func Get_nox_client_gui_flag_1556112() int {
	return int(nox_client_gui_flag_1556112)
}

func Set_dword_5d4594_1599628(v int) {
	dword_5d4594_1599628 = uint32(v)
}

func Sub_41E2F0() int {
	return int(dword_5d4594_527988)
}

func Get_nox_wol_wnd_world_814980() *gui.Window {
	return nox_wol_wnd_world_814980
}

func Get_dword_5d4594_815004() *gui.Window {
	return dword_5d4594_815004
}

func Nox_xxx_get_57AF20() int {
	return int(dword_5d4594_2523804)
}

func Set_nox_xxx_wallSounds_2386840(v int) {
	nox_xxx_wallSounds_2386840 = uint32(v)
}
func Set_dword_5d4594_1599644(v int) {
	dword_5d4594_1599644 = uint32(v)
}
func Set_dword_5d4594_1599480(v uint32) {
	dword_5d4594_1599480 = v
}
func Set_dword_5d4594_1599476(v int) {
	dword_5d4594_1599476 = uint32(v)
}
func Set_dword_5d4594_1599540(v unsafe.Pointer) {
	dword_5d4594_1599540 = v
}
func Set_dword_5d4594_1599532(v unsafe.Pointer) {
	dword_5d4594_1599532 = v
}
func Set_dword_5d4594_1599556(v unsafe.Pointer) {
	dword_5d4594_1599556 = v
}
func Set_dword_5d4594_1599548(v unsafe.Pointer) {
	dword_5d4594_1599548 = v
}
func Get_dword_5d4594_2386836() int {
	return int(dword_5d4594_2386836)
}
func Set_dword_5d4594_2386836(v int) {
	dword_5d4594_2386836 = uint32(v)
}
func Set_dword_5d4594_2386848(v int) {
	dword_5d4594_2386848 = int32(v)
}
func Set_dword_5d4594_2386852(v int) {
	dword_5d4594_2386852 = uint32(v)
}
func Set_dword_5d4594_815104(v int) {
	dword_5d4594_815104 = int32(v)
}
func Set_nox_wol_server_result_cnt_815088(v int) {
	nox_wol_server_result_cnt_815088 = uint32(v)
}
func Set_qword_5d4594_815068(v uint64) {
	qword_5d4594_815068 = v
}
func Set_nox_client_connError_814552(v int) {
	nox_client_connError_814552 = uint32(v)
}
func Set_dword_5d4594_815056(v int) {
	dword_5d4594_815056 = uint32(v)
}
func Set_nox_game_createOrJoin_815048(v int) {
	nox_game_createOrJoin_815048 = uint32(v)
}
func Set_dword_5d4594_527988(v int) {
	dword_5d4594_527988 = uint32(v)
}
func Set_dword_5d4594_10984(v int) {
	dword_5d4594_10984 = uint32(v)
}
func Set_nox_alloc_screenParticles_806044(v unsafe.Pointer) {
	nox_alloc_screenParticles_806044 = v
}
func Set_nox_screenParticles_head(v unsafe.Pointer) {
	nox_screenParticles_head = (*Nox_screenParticle)(v)
}
func Set_dword_5d4594_806052(v unsafe.Pointer) {
	dword_5d4594_806052 = (*Nox_screenParticle)(v)
}
func Set_dword_5d4594_830236(v unsafe.Pointer) {
	dword_5d4594_830236 = v
}
func Set_nox_gameDisableMapDraw_5d4594_2650672(v int) {
	nox_gameDisableMapDraw_5d4594_2650672 = uint32(v)
}
func Set_dword_5d4594_831224(v int) {
	dword_5d4594_831224 = uint32(v)
}
func Set_dword_5d4594_1563096(v bool) {
	dword_5d4594_1563096 = uint32(bool2int(v))
}
func Set_dword_5d4594_830872(v int) {
	dword_5d4594_830872 = uint32(v)
}
func Set_dword_5d4594_830972(v int) {
	dword_5d4594_830972 = uint32(v)
}
func Set_nox_win_width(v int) {
	nox_win_width = int32(v)
}
func Set_nox_win_height(v int) {
	nox_win_height = int32(v)
}
func Set_dword_5d4594_823776(v int) {
	dword_5d4594_823776 = uint32(v)
}
func Set_nox_draw_curDrawData_3799572(v *noxrender.RenderData) {
	nox_draw_curDrawData_3799572 = (*noxrender.RenderData)(v.C())
}
func Set_nox_color_black_2650656(v uint32) {
	nox_color_black_2650656 = v
}
func Set_nox_color_white_2523948(v uint32) {
	nox_color_white_2523948 = v
}
func Set_nox_color_violet_2598268(v uint32) {
	nox_color_violet_2598268 = v
}
func Set_nox_color_red_2589776(v uint32) {
	nox_color_red_2589776 = v
}
func Set_nox_color_green_2614268(v uint32) {
	nox_color_green_2614268 = v
}
func Set_nox_color_cyan_2649820(v uint32) {
	nox_color_cyan_2649820 = v
}
func Set_nox_color_blue_2650684(v uint32) {
	nox_color_blue_2650684 = v
}
func Set_nox_color_orange_2614256(v uint32) {
	nox_color_orange_2614256 = v
}
func Set_nox_color_yellow_2589772(v uint32) {
	nox_color_yellow_2589772 = v
}
func Set_dword_5d4594_1305748(v int) {
	dword_5d4594_1305748 = uint32(v)
}
func Set_nox_pixbuffer_rows_3798784(v unsafe.Pointer) {
	nox_pixbuffer_rows_3798784 = (**byte)(v)
}
func Set_dword_5d4594_1193188(v int) {
	dword_5d4594_1193188 = uint32(v)
}
func Set_dword_5d4594_2649712(v uint32) {
	dword_5d4594_2649712 = v
}
func Set_dword_5d4594_1548524(v int) {
	dword_5d4594_1548524 = uint32(v)
}
func Set_nox_client_gui_flag_1556112(v int) {
	nox_client_gui_flag_1556112 = uint32(v)
}
func Set_dword_5d4594_3798812(v int) {
	dword_5d4594_3798812 = uint32(v)
}
func Set_dword_5d4594_3798800(v int) {
	dword_5d4594_3798800 = uint32(v)
}
func Set_dword_5d4594_3798816(v int) {
	dword_5d4594_3798816 = uint32(v)
}
func Set_dword_5d4594_3798808(v int) {
	dword_5d4594_3798808 = uint32(v)
}
func Set_dword_5d4594_3798804(v int) {
	dword_5d4594_3798804 = uint32(v)
}
func Set_dword_5d4594_3798820(v int) {
	dword_5d4594_3798820 = uint32(v)
}
func Set_dword_5d4594_3798824(v int) {
	dword_5d4594_3798824 = uint32(v)
}
func Set_dword_5d4594_3798828(v int) {
	dword_5d4594_3798828 = uint32(v)
}
func Set_dword_5d4594_3798832(v int) {
	dword_5d4594_3798832 = uint32(v)
}
func Set_dword_5d4594_3798836(v int) {
	dword_5d4594_3798836 = uint32(v)
}
func Set_dword_5d4594_3798840(v int) {
	dword_5d4594_3798840 = uint32(v)
}
func Set_nox_video_tileBuf_ptr_3798796(v unsafe.Pointer) {
	nox_video_tileBuf_ptr_3798796 = v
}
func Set_nox_video_tileBuf_end_3798844(v unsafe.Pointer) {
	nox_video_tileBuf_end_3798844 = v
}
func Set_func_587000_154940(v func(a1 *uint32, a2 int32, a3 int32) int8) {
	func_587000_154940 = v
}
func Set_func_587000_154944(v func(a1 *uint32, a2 *uint32) int8) {
	func_587000_154944 = v
}
func Set_dword_5d4594_3799452(v int) {
	dword_5d4594_3799452 = uint32(v)
}
func Set_nox_alloc_chat_1197364(v unsafe.Pointer) {
	nox_alloc_chat_1197364 = v
}
func Set_dword_587000_145664(v int) {
	dword_587000_145664 = uint32(v)
}
func Set_dword_587000_145668(v int) {
	dword_587000_145668 = uint32(v)
}
func Set_dword_5d4594_1090120(v int) {
	dword_5d4594_1090120 = uint32(v)
}
func Set_dword_5d4594_251744(v int) {
	dword_5d4594_251744 = uint32(v)
}
func Set_dword_5d4594_816340(v int) {
	dword_5d4594_816340 = uint32(v)
}
func Set_dword_5d4594_816348(v int) {
	dword_5d4594_816348 = uint32(v)
}
func Set_dword_5d4594_2489460(v int) {
	dword_5d4594_2489460 = uint32(v)
}
func Set_dword_5d4594_1548532(v unsafe.Pointer) {
	dword_5d4594_1548532 = v
}
func Set_dword_5d4594_831260(v int) {
	dword_5d4594_831260 = uint32(v)
}
func Set_nox_client_translucentFrontWalls_805844(v int) {
	nox_client_translucentFrontWalls_805844 = uint32(v)
}
func Set_nox_client_highResFrontWalls_80820(v int) {
	nox_client_highResFrontWalls_80820 = uint32(v)
}
func Set_nox_client_highResFloors_154952(v int) {
	nox_client_highResFloors_154952 = uint32(v)
}
func Set_nox_client_fadeObjects_80836(v int) {
	nox_client_fadeObjects_80836 = uint32(v)
}
func Set_nox_client_renderBubbles_80844(v int) {
	nox_client_renderBubbles_80844 = uint32(v)
}
func Set_nox_server_sanctuaryHelp_54276(v int) {
	nox_server_sanctuaryHelp_54276 = uint32(v)
}
func Set_nox_server_sendMotd_108752(v int) {
	nox_server_sendMotd_108752 = uint32(v)
}
func Set_nox_server_connectionType_3596(v int) {
	nox_server_connectionType_3596 = uint32(v)
}
func Set_nox_server_resetQuestMinVotes_229988(v int) {
	nox_server_resetQuestMinVotes_229988 = uint32(v)
}
func Set_nox_server_kickQuestPlayerMinVotes_229992(v int) {
	nox_server_kickQuestPlayerMinVotes_229992 = uint32(v)
}
func Set_dword_5d4594_1308156(v unsafe.Pointer) {
	dword_5d4594_1308156 = v
}
func Set_dword_5d4594_1308160(v unsafe.Pointer) {
	dword_5d4594_1308160 = v
}
func Set_dword_5d4594_1308164(v unsafe.Pointer) {
	dword_5d4594_1308164 = v
}
func Set_dword_5d4594_2650676(v int) {
	dword_5d4594_2650676 = uint32(v)
}
func Set_dword_5d4594_2650680(v int) {
	dword_5d4594_2650680 = uint32(v)
}
func Set_qword_5d4594_814956(v uint64) {
	qword_5d4594_814956 = v
}
func Set_dword_5d4594_1200804(v uint32) {
	dword_5d4594_1200804 = v
}
func Set_nox_player_netCode_85319C(v uint32) {
	nox_player_netCode_85319C = v
}
func Set_dword_5d4594_1200832(v int) {
	dword_5d4594_1200832 = uint32(v)
}
func Set_nox_alloc_magicEnt_1569668(v unsafe.Pointer) {
	nox_alloc_magicEnt_1569668 = v
}
func Set_dword_5d4594_1569672(v int) {
	dword_5d4594_1569672 = uint32(v)
}
func Inc_nox_xxx_waypointCounterMB_587000_154948() {
	nox_xxx_waypointCounterMB_587000_154948++
}
func Inc_dword_5d4594_2516356() {
	dword_5d4594_2516356++
}
func Inc_dword_5d4594_2386848() {
	dword_5d4594_2386848++
}
func Inc_nox_wol_server_result_cnt_815088() {
	nox_wol_server_result_cnt_815088++
}
func Set_dword_5d4594_1599588(v unsafe.Pointer) {
	dword_5d4594_1599588 = v
}
func Set_dword_5d4594_1599592(v unsafe.Pointer) {
	dword_5d4594_1599592 = v
}
func Get_dword_5d4594_1599592_ptr() *uint32 {
	return &dword_5d4594_2649712
}
func Get_nox_xxx_resetMapInit_1569652() int {
	return int(nox_xxx_resetMapInit_1569652)
}
func Get_dword_5d4594_1123524() *gui.Window {
	return AsWindowP(dword_5d4594_1123524)
}
func Set_dword_5d4594_1123520(v int) {
	dword_5d4594_1123520 = uint32(v)
}
func Get_dword_5d4594_826036() *byte {
	return (*byte)(dword_5d4594_826036)
}
