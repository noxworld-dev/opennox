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

	NOX_SERVER_XXX_SIZE = 256
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
	fnc     unsafe.Pointer
	field_4 int32
	name    [12]byte
}
type obj_5D4594_2650668_t struct {
	field_0   uint8
	field_0_1 uint8
	field_0_2 uint16
	field_1   int32
	field_2   int32
	field_3   int32
	field_4   int32
	field_5   unsafe.Pointer
	field_6   int32
	field_7   int32
	field_8   int32
	field_9   int32
	field_10  unsafe.Pointer
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
	field_0   uint32
	text      [256]wchar2_t
	field_129 uint32
	field_130 uint32
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
	live  byte
	_     [3]byte
	id    int32
	data8 [327]uint32
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
type nox_server_xxx struct {
	field_0  uint32
	field_4  uint32
	field_8  uint16
	field_10 uint16
}

func nox_gui_console_Printf_450C00(cl byte, format *wchar2_t, args ...any) {
	// since legacy code still calls it, we redirect into global printer instead of GUI printer
	var buf bytes.Buffer
	stdio.FprintfGo(&buf, GoWString(format), args...)
	GetConsole().Print(console.Color(cl), buf.String())
}
