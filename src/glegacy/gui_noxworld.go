package legacy

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "MixPatch.h"
*/

import (
	"unsafe"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	Nox_client_refreshServerList_4378B0 func()
	Sub_438770_waitList                 func()
	Nox_xxx_createSocketLocal           func(port int) error
	Sub_554D10                          func() int
	Sub_4373A0                          func()
)

var _ = [1]struct{}{}[100-unsafe.Offsetof(Nox_gui_server_ent_t{}.StatusVal)]
var _ = [1]struct{}{}[168-unsafe.Offsetof(Nox_gui_server_ent_t{}.Field_42)]
var _ = [1]struct{}{}[172-unsafe.Sizeof(Nox_gui_server_ent_t{})] // FIXME: should be 169

type Nox_gui_server_ent_t struct {
	Field_0       uint32   // 0, 0
	Field_1       uint32   // 1, 4
	Sort_key      int32    // 2, 8
	AddrBuf       [16]byte // 3, 12
	Field_7       int32    // 7, 28
	Field_8       uint32   // 8, 32
	Field_9       uint32   // 9, 36, TODO: server index?
	Field_10      uint32   // 10, 40
	Field_11_0    int16    // 11, 44
	Field_11_2    int16    // 11, 46
	VersionVal    uint32   // 12, 48
	Field_13      uint32   // 13, 52
	Field_14      uint32   // 14, 56
	Field_15      uint32   // 15, 60
	Field_16      uint32   // 16, 64
	Field_17      uint32   // 17, 68
	Field_18      uint32   // 18, 72
	Field_19      uint32   // 19, 76
	Field_20      uint32   // 20, 80
	Field_21      uint32   // 21, 84
	Field_22      uint32   // 22, 88
	Field_23      uint32   // 23, 92
	PingVal       int32    // 24, 96
	StatusVal     byte     // 25, 100
	Field_25_1    byte     // 25, 101
	Field_25_2    byte     // 25, 102
	PlayersVal    byte     // 25, 103
	MaxPlayersVal byte     // 26, 104
	Field_26_1    [2]byte  // 26, 105
	Field_26_3    [2]byte  // 26, 107
	PortVal       [2]byte  // 27, 109
	MapNameBuf    [9]byte  // 27, 111
	ServerNameBuf [15]byte // 30, 120
	Field_33_3    [20]byte // 33, 135
	Field_38_3    [4]byte  // 38, 155
	Field_39_3    [4]byte  // 39, 159
	FlagsVal      [2]byte  // 40, 163
	QuestLevelVal [2]byte  // 41, 165
	Field_41_3    byte     // 41, 167
	Field_42      byte     // 42, 168
}

func (s *Nox_gui_server_ent_t) C() *nox_gui_server_ent_t {
	return (*nox_gui_server_ent_t)(unsafe.Pointer(s))
}

func (s *Nox_gui_server_ent_t) Players() int {
	if s == nil {
		return 0
	}
	return int(s.PlayersVal)
}

func (s *Nox_gui_server_ent_t) MaxPlayers() int {
	if s == nil {
		return 0
	}
	return int(s.MaxPlayersVal)
}

func (s *Nox_gui_server_ent_t) Ping() int {
	if s == nil {
		return 0
	}
	return int(s.PingVal)
}

func (s *Nox_gui_server_ent_t) Version() uint32 {
	if s == nil {
		return 0
	}
	return s.VersionVal
}

func (s *Nox_gui_server_ent_t) SetVersion(v uint32) {
	s.VersionVal = v
}

func (s *Nox_gui_server_ent_t) Status() int {
	if s == nil {
		return 0
	}
	return int(s.StatusVal)
}

func (s *Nox_gui_server_ent_t) QuestLevel() int {
	if s == nil {
		return 0
	}
	return int(*(*uint16)(unsafe.Pointer(&s.QuestLevelVal)))
}

func (s *Nox_gui_server_ent_t) SetQuestLevel(v uint16) {
	*(*uint16)(unsafe.Pointer(&s.QuestLevelVal)) = v
}

func (s *Nox_gui_server_ent_t) Addr() string {
	if s == nil {
		return ""
	}
	return alloc.GoStringS(s.AddrBuf[:])
}

func (s *Nox_gui_server_ent_t) SetAddr(v string) {
	alloc.StrCopyZero(s.AddrBuf[:], v)
}

func (s *Nox_gui_server_ent_t) Port() int {
	if s == nil {
		return 0
	}
	return int(*(*uint16)(unsafe.Pointer(&s.PortVal)))
}

func (s *Nox_gui_server_ent_t) SetPort(v uint16) {
	*(*uint16)(unsafe.Pointer(&s.PortVal)) = v // port
}

func (s *Nox_gui_server_ent_t) ServerName() string {
	if s == nil {
		return ""
	}
	return alloc.GoStringS(s.ServerNameBuf[:])
}

func (s *Nox_gui_server_ent_t) SetServerName(v string) {
	alloc.StrCopy(s.ServerNameBuf[:], v)
}

func (s *Nox_gui_server_ent_t) MapName() string {
	if s == nil {
		return ""
	}
	return alloc.GoStringS(s.MapNameBuf[:])
}

func (s *Nox_gui_server_ent_t) SetMapName(v string) {
	alloc.StrCopyZero(s.MapNameBuf[:], v)
}

func (s *Nox_gui_server_ent_t) Flags() noxflags.GameFlag {
	if s == nil {
		return 0
	}
	return noxflags.GameFlag(*(*uint16)(unsafe.Pointer(&s.FlagsVal))) // flags
}

func (s *Nox_gui_server_ent_t) SetFlags(v noxflags.GameFlag) {
	*(*uint16)(unsafe.Pointer(&s.FlagsVal)) = uint16(v) // flags
}

// nox_client_refreshServerList_4378B0
func nox_client_refreshServerList_4378B0() { Nox_client_refreshServerList_4378B0() }

// sub_438770_waitList
func sub_438770_waitList() { Sub_438770_waitList() }

// nox_xxx_createSocketLocal_554B40
func nox_xxx_createSocketLocal_554B40(port uint16) int {
	if err := Nox_xxx_createSocketLocal(int(port)); err != nil {
		return -1
	}
	return 0
}

// sub_554D10
func sub_554D10() int { return Sub_554D10() }

// sub_4373A0
func sub_4373A0() { Sub_4373A0() }

func Sub_4A0410(addr string, port int) bool {
	cstr := CString(addr)
	defer StrFree(cstr)
	v := sub_4A0410(cstr, short(port))
	return v != 0
}

func Sub_43B6D0() int {
	return int(sub_43B6D0())
}

func Sub_43AF80() int {
	return int(sub_43AF80())
}

func Sub_4379C0() {
	sub_4379C0()
}

func Sub_4A0360() {
	sub_4A0360()
}
func Sub_49FFA0(a1 int) {
	sub_49FFA0(int(a1))
}
func Sub_437860(a1 int, a2 int) int {
	return int(sub_437860(int(a1), int(a2)))
}
func Nox_xxx_checkSomeFlagsOnJoin_4899C0(a1 *Nox_gui_server_ent_t) int {
	return int(nox_xxx_checkSomeFlagsOnJoin_4899C0(a1.C()))
}
func Nox_wol_servers_addResult_4A0030(a1 *Nox_gui_server_ent_t) {
	nox_wol_servers_addResult_4A0030(a1.C())
}
func Sub_4375C0(a1 int) {
	sub_4375C0(int(a1))
}
