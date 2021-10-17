package nox

/*
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "defs.h"
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern nox_playerInfo nox_playerinfo_arr[NOX_PLAYERINFO_MAX];
extern nox_object_t* nox_xxx_host_player_unit_3843628;
void nox_xxx_WideScreenDo_515240(bool enable);
static void nox_xxx_netSendLineMessage_go(nox_object_t* a1, wchar_t* str) {
	nox_xxx_netSendLineMessage_4D9EB0(a1, str);
}
static void nox_xxx_printToAll_4D9FD0_go(int a1, wchar_t* str) {
	nox_xxx_printToAll_4D9FD0(a1, str);
}
*/
import "C"
import (
	"fmt"
	"unsafe"

	"nox/v1/common/memmap"
	"nox/v1/common/player"
	"nox/v1/common/types"
	"nox/v1/server/script"
)

const NOX_PLAYERINFO_MAX = C.NOX_PLAYERINFO_MAX

//export nox_xxx_playerDisconnByPlrID_4DEB00
func nox_xxx_playerDisconnByPlrID_4DEB00(id C.int) {
	if p := getPlayerByInd(int(id)); p != nil {
		p.Disconnect(4)
	}
}

//export nox_xxx_playerCallDisconnect_4DEAB0
func nox_xxx_playerCallDisconnect_4DEAB0(ind C.int, v C.char) *C.char {
	getPlayerByInd(int(ind)).Disconnect(int(v))
	return nil
}

func getPlayerClass() player.Class {
	return player.Class(memmap.Uint8(0x85B3FC, 12254))
}

func newPlayer(ind int, data unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_playerNew_4DD320(C.int(ind), data))
}

func asPlayer(p *C.nox_playerInfo) *Player {
	return (*Player)(p)
}

func BlindPlayers(blind bool) {
	nox_xxx_netMsgFadeBegin_4D9800(!blind, false)
}

func CinemaPlayers(cinema bool) {
	C.nox_xxx_WideScreenDo_515240(C.bool(cinema))
}

func PrintToPlayers(text string) {
	cstr, free := CWString(text)
	defer free()
	C.nox_xxx_printToAll_4D9FD0_go(0, cstr)
}

func HostPlayer() *Player {
	// TODO: better way
	for _, p := range getPlayers() {
		if p.IsHost() {
			return p
		}
	}
	return nil
}

var _ noxObject = (*Player)(nil) // proxies Unit

type Player C.nox_playerInfo

func (p *Player) field(off uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(unsafe.Pointer(p)) + off)
}

func (p *Player) Pos() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	u := p.Unit()
	if u == nil {
		return types.Pointf{}
	}
	return u.Pos()
}

func (p *Player) SetPos(pos types.Pointf) {
	if p == nil {
		return
	}
	u := p.Unit()
	if u == nil {
		return
	}
	u.SetPos(pos)
}

func (p *Player) OrigName() string {
	return GoWStringP(p.field(2185))
}

func (p *Player) Name() string {
	return GoWStringP(p.field(4704))
}

func (p *Player) String() string {
	return fmt.Sprintf("Player(%q)", p.Name())
}

func (p *Player) IsHost() bool {
	// TODO: better way
	return p.UnitC() == HostPlayerUnit()
}

func (p *Player) Print(text string) {
	cstr, free := CWString(text)
	defer free()
	C.nox_xxx_netSendLineMessage_go(p.UnitC().CObj(), cstr)
}

func (p *Player) Blind(blind bool) {
	C.nox_xxx_netMsgFadeBeginPlayer(C.int(p.Index()), C.int(bool2int(!blind)), 0)
}

func (p *Player) Cinema(v bool) {
	// TODO: only works for everyone for now
	CinemaPlayers(v)
}

func (p *Player) CObj() *nox_object_t {
	u := p.UnitC()
	if u == nil {
		return nil
	}
	return u.CObj()
}

func (p *Player) GetObject() script.Object {
	u := p.Unit()
	if u == nil {
		return nil
	}
	return u
}

func (p *Player) Unit() script.Unit {
	if p == nil {
		return nil
	}
	return p.UnitC()
}

func HostPlayerUnit() *Unit {
	return asUnit(unsafe.Pointer(C.nox_xxx_host_player_unit_3843628))
}

func (p *Player) C() *C.nox_playerInfo {
	return (*C.nox_playerInfo)(p)
}

func (p *Player) Index() int {
	if p == nil {
		return -1
	}
	return int(p.playerInd)
}

func (p *Player) NetCode() int {
	if p == nil {
		return -1
	}
	return int(p.netCode)
}

func (p *Player) IsActive() bool {
	return p != nil && p.active != 0
}

func (p *Player) UnitC() *Unit {
	if p == nil {
		return nil
	}
	return asUnitC(p.playerUnit)
}

func (p *Player) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return player.Class(p.playerClass)
}

func (p *Player) Disconnect(v int) {
	if !p.IsActive() {
		return
	}
	C.nox_xxx_playerDisconnFinish_4DE530(C.int(p.Index()), C.char(v))
	C.nox_xxx_playerForceDisconnect_4DE7C0(C.int(p.Index()))
	nox_xxx_netStructReadPackets2_4DEC50(p.Index())
}

func (p *Player) GoObserver(notify, keepPlayer bool) bool {
	if p == nil {
		return true
	}
	return C.nox_xxx_playerGoObserver_4E6860(p.C(), C.int(bool2int(notify)), C.int(bool2int(keepPlayer))) != 0
}

func cntPlayers() (n int) { // nox_common_playerInfoCount_416F40
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.IsActive() {
			n++
		}
	}
	return n
}

func getAllPlayerStructs() (out []*Player) {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		out = append(out, p)
	}
	return out
}

func getPlayers() (out []*Player) {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.IsActive() {
			out = append(out, p)
		}
	}
	return out
}

func getPlayerUnits() (out []*Unit) {
	for _, p := range getPlayers() {
		if u := p.UnitC(); u != nil {
			out = append(out, u)
		}
	}
	return out
}

func getPlayerByInd(i int) *Player { // nox_common_playerInfoFromNum_417090
	if i < 0 || i >= NOX_PLAYERINFO_MAX {
		return nil
	}
	p := asPlayer(&C.nox_playerinfo_arr[i])
	if !p.IsActive() {
		return nil
	}
	p.playerInd = C.uchar(i)
	return p
}

func getPlayerByID(id int) *Player { // nox_common_playerInfoGetByID_417040
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.IsActive() && int(p.netCode) == id {
			return p
		}
	}
	return nil
}

func hasPlayerUnits() bool {
	for i := 0; i < NOX_PLAYERINFO_MAX; i++ {
		p := asPlayer(&C.nox_playerinfo_arr[i])
		if p.UnitC() != nil {
			return true
		}
	}
	return false
}
