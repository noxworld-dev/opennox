package opennox

/*
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "common__net_list.h"
#include "defs.h"
extern unsigned int dword_5d4594_1046492;
extern unsigned int dword_5d4594_2650652;
extern unsigned int nox_player_netCode_85319C;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
void nox_xxx_WideScreenDo_515240(bool enable);
static void nox_xxx_printToAll_4D9FD0_go(int a1, wchar_t* str) {
	nox_xxx_printToAll_4D9FD0(a1, str);
}

extern float nox_xxx_warriorMaxHealth_587000_312784;
extern float nox_xxx_warriorMaxMana_587000_312788;

extern float nox_xxx_conjurerMaxHealth_587000_312800;
extern float nox_xxx_conjurerMaxMana_587000_312804;

extern float nox_xxx_wizardMaxHealth_587000_312816;
extern float nox_xxx_wizardMaximumMana_587000_312820;

*/
import "C"
import (
	"encoding"
	"encoding/binary"
	"fmt"
	"image"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_xxx_playerSpell_4FB2A0_magic_plyrspel
func nox_xxx_playerSpell_4FB2A0_magic_plyrspel(up *nox_object_t) {
	noxServer.playerSpell(asUnitC(up))
}

//export nox_xxx_updateSpellRelated_424830
func nox_xxx_updateSpellRelated_424830(p unsafe.Pointer, ph C.int) unsafe.Pointer {
	return unsafe.Pointer((*phonemeLeaf)(p).Next(spell.Phoneme(ph)))
}

//export nox_common_playerInfoGetFirst_416EA0
func nox_common_playerInfoGetFirst_416EA0() *C.nox_playerInfo {
	return noxServer.playerFirst().C()
}

//export nox_common_playerInfoGetNext_416EE0
func nox_common_playerInfoGetNext_416EE0(it *C.nox_playerInfo) *C.nox_playerInfo {
	return noxServer.playerNext(asPlayer(it)).C()
}

//export nox_common_playerInfoCount_416F40
func nox_common_playerInfoCount_416F40() C.int {
	return C.int(noxServer.cntPlayers())
}

//export nox_common_playerInfoGetByID_417040
func nox_common_playerInfoGetByID_417040(id C.int) *C.nox_playerInfo {
	return noxServer.getPlayerByID(int(id)).C()
}

//export nox_common_playerInfoFromNum_417090
func nox_common_playerInfoFromNum_417090(ind C.int) *C.nox_playerInfo {
	return noxServer.getPlayerByInd(int(ind)).C()
}

//export nox_common_playerInfoFromNumRaw
func nox_common_playerInfoFromNumRaw(ind C.int) *C.nox_playerInfo {
	return noxServer.players.list[ind].C()
}

//export nox_xxx_playerDisconnByPlrID_4DEB00
func nox_xxx_playerDisconnByPlrID_4DEB00(id C.int) {
	if p := noxServer.getPlayerByInd(int(id)); p != nil {
		p.Disconnect(4)
	}
}

//export nox_xxx_playerCallDisconnect_4DEAB0
func nox_xxx_playerCallDisconnect_4DEAB0(ind C.int, v C.char) *C.char {
	noxServer.getPlayerByInd(int(ind)).Disconnect(int(v))
	return nil
}

//export nox_xxx_playerCameraUnlock_4E6040
func nox_xxx_playerCameraUnlock_4E6040(cplayer *nox_object_t) {
	asUnitC(cplayer).ControllingPlayer().CameraUnlock()
}

//export nox_xxx_playerCameraFollow_4E6060
func nox_xxx_playerCameraFollow_4E6060(cplayer, cunit *nox_object_t) {
	asUnitC(cplayer).ControllingPlayer().CameraToggle(asObjectC(cunit))
}

//export nox_xxx_playerGetPossess_4DDF30
func nox_xxx_playerGetPossess_4DDF30(cplayer *nox_object_t) *nox_object_t {
	return asUnitC(cplayer).ControllingPlayer().ObserveTarget().CObj()
}

//export nox_xxx_playerGoObserver_4E6860
func nox_xxx_playerGoObserver_4E6860(pl *C.nox_playerInfo, a2 C.int, a3 C.int) C.int {
	return C.int(bool2int(asPlayer(pl).GoObserver(a2 != 0, a3 != 0)))
}

//export nox_xxx_playerObserveClear_4DDEF0
func nox_xxx_playerObserveClear_4DDEF0(cplayer *nox_object_t) {
	asUnitC(cplayer).observeClear()
}

type classStatMult struct {
	// TODO: health and mana

	strength float32
	speed    float32
}

type serverPlayers struct {
	list []Player
	mult struct {
		warrior  classStatMult
		wizard   classStatMult
		conjurer classStatMult
	}
}

func (s *Server) initPlayers() {
	p, _ := alloc.Calloc(common.MaxPlayers, unsafe.Sizeof(Player{}))
	s.players.list = unsafe.Slice((*Player)(p), common.MaxPlayers)
	s.players.mult.warrior = classStatMult{
		strength: 1,
		speed:    1,
	}
	s.players.mult.wizard = classStatMult{
		strength: 1,
		speed:    1,
	}
	s.players.mult.conjurer = classStatMult{
		strength: 1,
		speed:    1,
	}
}

func clientPlayer() *Player {
	return noxServer.getPlayerByID(clientPlayerNetCode())
}

func clientPlayerNetCode() int {
	return int(C.nox_player_netCode_85319C)
}

func clientSetPlayerNetCode(id int) {
	C.nox_player_netCode_85319C = C.uint(id)
}

func (s *Server) resetAllPlayers() {
	for i := range s.players.list {
		s.players.list[i] = Player{}
	}
}

func (s *Server) playerFirst() *Player {
	for i := range s.players.list {
		p := &s.players.list[i]
		if p.IsActive() {
			return p
		}
	}
	return nil
}

func (s *Server) playerNext(it *Player) *Player {
	if it == nil {
		return nil
	}
	for i := it.Index() + 1; i < len(s.players.list); i++ {
		p := &s.players.list[i]
		if p.IsActive() {
			return p
		}
	}
	return nil
}

func (s *Server) firstReplaceablePlayer() *Player {
	for it := s.playerFirst(); it != nil; it = s.playerNext(it) {
		if it.field_3680&1 != 0 && it.Index() != -1 {
			return it
		}
	}
	return nil
}

func (s *Server) nextReplaceablePlayer(it *Player) *Player {
	for ; it != nil; it = s.playerNext(it) {
		if it.field_3680&1 != 0 && it.Index() != -1 {
			return it
		}
	}
	return nil
}

func (s *Server) playerResetInd(ind int) *Player {
	p := &s.players.list[ind]
	p.Reset(ind)
	return p
}

func (s *Server) newPlayerInfo(id int) *Player {
	if p := s.getPlayerByID(id); p != nil {
		return p
	}
	for i := range s.players.list {
		p := &s.players.list[i]
		if !p.IsActive() {
			p.Reset(i)
			p.netCode = C.uint(id)
			return p
		}
	}
	return nil
}

func (p *Player) Reset(ind int) {
	*p = Player{
		playerInd:  C.uchar(ind),
		active:     1,
		field_3648: 4,
	}
}

func getPlayerClass() player.Class {
	return player.Class(memmap.Uint8(0x85B3FC, 12254))
}

func asPlayer(p *C.nox_playerInfo) *Player {
	return (*Player)(p)
}

func asPlayerS(p *server.Player) *Player {
	return (*Player)(unsafe.Pointer(p))
}

func BlindPlayers(blind bool) {
	noxServer.nox_xxx_netMsgFadeBegin_4D9800(!blind, false)
}

func PrintToPlayers(text string) {
	cstr, free := CWString(text)
	defer free()
	C.nox_xxx_printToAll_4D9FD0_go(0, cstr)
}

func HostPlayer() *Player {
	// TODO: better way
	for _, p := range noxServer.getPlayers() {
		if p.IsHost() {
			return p
		}
	}
	return nil
}

var _ noxObject = (*Player)(nil) // proxies Unit

type PlayerInfo C.nox_playerInfo2

func (p *PlayerInfo) field(off uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(unsafe.Pointer(p)) + off)
}

func (p *PlayerInfo) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return player.Class(p.playerClass)
}

func (p *PlayerInfo) IsFemale() bool {
	if p == nil {
		return false
	}
	return p.isFemale != 0
}

func (p *PlayerInfo) Name() string {
	return GoWStringN(&p.name[0], 33) // TODO: size is a guess
}

func (p *PlayerInfo) SetName(v string) {
	WStrCopy(&p.name[0], 25, v)
}

func (p *PlayerInfo) NameSuff() string {
	return GoWStringN((*C.wchar_t)(p.field(89)), 4)
}

func (p *PlayerInfo) SetNameSuff(v string) {
	WStrCopy((*C.wchar_t)(p.field(89)), 4, v)
}

func (p *PlayerInfo) Field2235() uint32 {
	return *(*uint32)(p.field(50))
}

func (p *PlayerInfo) Field2239() uint32 {
	return *(*uint32)(p.field(54))
}

func (p *PlayerInfo) SetField2235(v uint32) {
	*(*uint32)(p.field(50)) = v
}

func (p *PlayerInfo) SetField2239(v uint32) {
	*(*uint32)(p.field(54)) = v
}

func (p *PlayerInfo) SetField2256(v uint16) {
	*(*uint16)(p.field(71)) = v
}

func (p *PlayerInfo) SetField2262(v uint16) {
	*(*uint16)(p.field(77)) = v
}

type Player C.nox_playerInfo

func (p *Player) getServer() *Server {
	return noxServer // TODO: attach to object
}

func (p *Player) field(off uintptr) unsafe.Pointer {
	return unsafe.Add(unsafe.Pointer(p), off)
}

func (p *Player) net16() *[255]playerNetData {
	return (*[255]playerNetData)(unsafe.Pointer(&p.netData16[0]))
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

func (p *Player) CursorPos() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(p.cursor_x),
		Y: float32(p.cursor_y),
	}
}

func (p *Player) setCursorPos(pos image.Point) {
	p.cursor_x = C.int(pos.X)
	p.cursor_y = C.int(pos.Y)
}

func (p *Player) pos3632() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(p.pos_x_3632),
		Y: float32(p.pos_y_3636),
	}
}

func (p *Player) setPos3632(pt types.Pointf) {
	p.pos_x_3632 = C.float(pt.X)
	p.pos_y_3636 = C.float(pt.Y)
}

func (p *Player) OrigName() string {
	return p.Info().Name()
}

func (p *Player) SetName(v string) {
	WStrCopy(&p.name_final[0], 28, v) // TODO: size is a wild guess
}

func (p *Player) Name() string {
	return GoWStringN(&p.name_final[0], 28) // TODO: size is a wild guess
}

func (p *Player) saveName() string {
	return GoString(&p.field_4760[0])
}

func (p *Player) Serial() string {
	return GoStringN(&p.serial[0], 22)
}

func (p *Player) SetSerial(v string) {
	StrCopy(&p.serial[0], 22, v)
}

func (p *Player) Field2096() string {
	return GoStringN(&p.field_2096[0], 12)
}

func (p *Player) SetField2096(v string) {
	StrCopy(&p.field_2096[0], 12, v)
}

func (p *Player) String() string {
	return fmt.Sprintf("Player(%q)", p.Name())
}

func (p *Player) Gold() int {
	return int(p.gold)
}

func (p *Player) IsHost() bool {
	// TODO: better way
	return p.UnitC() == HostPlayerUnit()
}

func (p *Player) Print(text string) {
	nox_xxx_netSendLineMessage_4D9EB0(p.UnitC(), text)
}

func (p *Player) Blind(blind bool) {
	C.nox_xxx_netMsgFadeBeginPlayer(C.int(p.Index()), C.int(bool2int(!blind)), 0)
}

func (p *Player) Cinema(v bool) {
	// TODO: only works for everyone for now
	p.getServer().CinemaPlayers(v)
}

func (p *Player) CObj() *nox_object_t {
	u := p.UnitC()
	if u == nil {
		return nil
	}
	return u.CObj()
}

func (p *Player) SObj() *server.Object {
	u := p.UnitC()
	if u == nil {
		return nil
	}
	return u.SObj()
}

func (p *Player) AsObject() *Object {
	u := p.UnitC()
	if u == nil {
		return nil
	}
	return u.AsObject()
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

func (p *Player) S() *server.Player {
	return (*server.Player)(unsafe.Pointer(p))
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

func (p *Player) Info() *PlayerInfo {
	if p == nil {
		return nil
	}
	return (*PlayerInfo)(p.field(2185)) // inaccessible due to alignment issues
}

func (p *Player) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return p.Info().PlayerClass()
}

func (p *Player) Disconnect(v int) {
	if !p.IsActive() {
		return
	}
	C.nox_xxx_playerDisconnFinish_4DE530(C.int(p.Index()), C.char(v))
	C.nox_xxx_playerForceDisconnect_4DE7C0(C.int(p.Index()))
	p.getServer().nox_xxx_netStructReadPackets2_4DEC50(p.Index())
}

func (p *Player) CameraTarget() *Object {
	if p == nil {
		return nil
	}
	return asObjectC(p.camera_follow)
}

func (p *Player) ObserveTarget() *Object { // nox_xxx_playerGetPossess_4DDF30
	if p == nil {
		return nil
	}
	if p.field_3680&2 == 0 {
		return nil
	}
	return asObjectC(p.camera_follow)
}

func (p *Player) CameraUnlock() { // nox_xxx_playerCameraUnlock_4E6040
	if p == nil {
		return
	}
	p.camera_follow = nil
}

func (p *Player) CameraFollow(obj noxObject) {
	if p == nil {
		return
	}
	p.camera_follow = toCObj(obj)
}

func (p *Player) CameraToggle(obj noxObject) { // nox_xxx_playerCameraFollow_4E6060
	if p == nil {
		return
	}
	if p.camera_follow == toCObj(obj) {
		p.CameraUnlock()
	} else {
		p.CameraFollow(toObject(obj))
	}
}

func (p *Player) GoObserver(notify, keepPlayer bool) bool { // nox_xxx_playerGoObserver_4E6860
	if p == nil {
		return true
	}
	u := p.UnitC()
	if u == nil {
		return true
	}
	s := u.getServer()
	if !keepPlayer && s.abilities.IsAnyActive(u) {
		return false
	}
	if u.Update == unsafe.Pointer(C.nox_xxx_updatePlayerMonsterBot_4FAB20) {
		return false
	}
	ud := u.UpdateDataPlayer()
	if noxflags.HasGame(noxflags.GameModeKOTR | noxflags.GameModeCTF | noxflags.GameModeFlagBall) {
		crown := s.ObjectTypeID("Crown")
		ball := s.ObjectTypeID("GameBall")
		for it := u.FirstOwned516(); it != nil; it = it.NextOwned512() {
			typ := int(it.TypeInd)
			if typ == crown {
				u.CallDrop(it, u.Pos())
			} else if typ == ball {
				it.Obj130 = nil
				it.ObjFlags &= 0xFFFFFFBF
				it.SetOwner(nil)
				sub_4E8290(1, 0)
			} else if it.Class().Has(object.ClassFlag) {
				u.forceDropAt(it, u.Pos())
			}
		}
	}
	if p.ObserveTarget() != nil {
		u.observeClear()
	}
	C.nox_xxx_netNeedTimestampStatus_4174F0(p.C(), 1)
	v10 := C.nox_xxx_gamePlayIsAnyPlayers_40A8A0() != 0
	if !v10 && !noxflags.HasGame(noxflags.GameModeQuest) {
		C.sub_40A1F0(0)
		C.nox_xxx_playerForceSendLessons_416E50(1)
		nox_server_teamsResetYyy_417D00()
		C.sub_40A970()
	}
	nox_xxx_netInformTextMsg_4DA0F0(p.Index(), 12, bool2int(notify))
	u.ApplyEnchant(server.ENCHANT_INVISIBLE, 0, 5)
	u.ObjFlags |= uint32(object.FlagNoCollide)
	p.setPos3632(u.Pos())
	p.CameraUnlock()
	if noxflags.HasGame(noxflags.GameModeCoop) {
		p.field_3672 = 1
		p.camera_follow = nil
	} else if noxflags.HasGame(noxflags.GameModeFlagBall) {
		if !keepPlayer {
			p.leaveMonsterObserver()
		}
	}
	C.nox_xxx_playerRemoveSpawnedStuff_4E5AD0(u.CObj())
	ud.Field61 = 0
	_ = nox_xxx_updatePlayerObserver_4E62F0
	u.Update = C.nox_xxx_updatePlayerObserver_4E62F0
	C.sub_4D7E50(u.CObj())
	return true
}

func (p *Player) leaveMonsterObserver() {
	u := p.UnitC()
	if u == nil {
		return
	}
	var targ *Object
	if p.ObserveTarget() != nil {
		targ = asObjectC(C.nox_xxx_playerObserverFindGoodSlave0_4E6280(p.C()))
		if targ == nil {
			u.observeClear()
			return
		}
	} else {
		targ = asObjectC(C.sub_4E6150(p.C()))
	}
	p.CameraFollow(targ)
}

func (u *Unit) observeClear() {
	pl := u.ControllingPlayer()
	if pl.field_3680&2 != 0 {
		C.nox_xxx_playerUnsetStatus_417530(pl.C(), 2)
		pl.CameraUnlock()
		_ = nox_xxx_updatePlayer_4F8100
		u.Update = C.nox_xxx_updatePlayer_4F8100
	}
}

func (s *Server) cntPlayers() (n int) {
	for i := range s.players.list {
		p := &s.players.list[i]
		if p.IsActive() {
			n++
		}
	}
	return n
}

func (s *Server) getAllPlayerStructs() (out []*Player) {
	for i := range s.players.list {
		p := &s.players.list[i]
		out = append(out, p)
	}
	return out
}

func (s *Server) getPlayers() (out []*Player) {
	for i := range s.players.list {
		p := &s.players.list[i]
		if p.IsActive() {
			out = append(out, p)
		}
	}
	return out
}

func (s *Server) getPlayerUnits() (out []*Unit) {
	for _, p := range s.getPlayers() {
		if u := p.UnitC(); u != nil {
			out = append(out, u)
		}
	}
	return out
}

func (s *Server) getPlayerByInd(i int) *Player {
	if i < 0 || i >= len(s.players.list) {
		return nil
	}
	p := &s.players.list[i]
	if !p.IsActive() {
		return nil
	}
	p.playerInd = C.uchar(i)
	return p
}

func (s *Server) getPlayerByID(id int) *Player {
	for i := range s.players.list {
		p := &s.players.list[i]
		if p.IsActive() && int(p.netCode) == id {
			return p
		}
	}
	return nil
}

func (s *Server) hasPlayerUnits() bool {
	for i := range s.players.list {
		p := &s.players.list[i]
		if p.UnitC() != nil {
			return true
		}
	}
	return false
}

func nox_xxx_netNewPlayerMakePacket_4DDA90(buf []byte, pl *Player) {
	buf[0] = byte(noxnet.MSG_NEW_PLAYER)
	binary.LittleEndian.PutUint16(buf[1:], uint16(pl.NetCode()))
	binary.LittleEndian.PutUint16(buf[100:], uint16(pl.lessons))
	binary.LittleEndian.PutUint16(buf[102:], uint16(pl.field_2140))
	binary.LittleEndian.PutUint32(buf[104:], uint32(pl.field_0))
	binary.LittleEndian.PutUint32(buf[108:], uint32(pl.field_4))
	buf[116] = byte(pl.field_2152)
	buf[117] = byte(pl.field_2156)
	buf[118] = byte(bool2int(pl.field_3676 == 3))
	binary.LittleEndian.PutUint32(buf[112:], uint32(pl.field_3680)&0x423)
	StrCopyBytes(buf[119:], pl.Field2096())
	*(*PlayerInfo)(unsafe.Pointer(&buf[3])) = *pl.Info()
}

func sub_422140(pl *Player) {
	if pl != nil {
		pl.field_3660 = 0xDEADFACE
		pl.field_3664 = 0xDEADFACE
	}
}

func sub_459D70() int {
	var v0 uint32
	if C.dword_5d4594_1046492 != 0 {
		v0 = math.MaxInt32
	} else {
		v0 = 0
	}
	v0 &= 0xFFFFFFFE
	return int(v0 + 2)
}

func (s *Server) nox_xxx_playerCheckName_4DDA00(pl *Player) {
	for i := 2; ; i++ {
		ok := true
		for _, pl2 := range s.getPlayers() {
			if pl.Index() == pl2.Index() {
				continue
			}
			if pl.Name() == pl2.Name() {
				ok = false
				break
			}
		}
		if ok {
			return
		}
		pl.Info().SetNameSuff(fmt.Sprintf(" %d", i))
		pl.SetName(fmt.Sprintf("%s %d", pl.OrigName(), i))
	}
}

func sub_4E4F30(a1 int) {
	*memmap.PtrUint16(0x5D4594, 1565524+2*uintptr(a1)) = 0
}

var (
	_ encoding.BinaryMarshaler   = &PlayerOpts{}
	_ encoding.BinaryUnmarshaler = &PlayerOpts{}
)

type PlayerOpts struct {
	Info      PlayerInfo
	Screen    image.Point
	Serial    string
	Field2096 string
	Field2068 int
	Field2072 string
	Byte152   byte
}

func (p *PlayerOpts) UnmarshalBinary(data []byte) error {
	*p = PlayerOpts{}
	if len(data) < 153 {
		return fmt.Errorf("cannot unmarshal player opts: message too short: %d < %d", len(data), 153)
	}
	p.Info = *(*PlayerInfo)(unsafe.Pointer(&data[0])) // TODO: set fields individually
	p.Screen = image.Point{
		X: int(binary.LittleEndian.Uint32(data[97:101])),
		Y: int(binary.LittleEndian.Uint32(data[101:105])),
	}
	p.Serial = GoStringS(data[105:128])
	p.Field2096 = GoStringS(data[128:138])
	p.Field2068 = int(binary.LittleEndian.Uint32(data[138:142]))
	p.Field2072 = GoWStringBytes(data[142:152])
	p.Byte152 = data[152]
	return nil
}

func (p *PlayerOpts) MarshalBinary() ([]byte, error) {
	data := make([]byte, 153)
	*(*PlayerInfo)(unsafe.Pointer(&data[0])) = p.Info // TODO: set fields individually
	binary.LittleEndian.PutUint32(data[97:101], uint32(p.Screen.X))
	binary.LittleEndian.PutUint32(data[101:105], uint32(p.Screen.Y))
	StrCopyBytes(data[105:128], p.Serial)
	StrCopyBytes(data[128:138], p.Field2096)
	binary.LittleEndian.PutUint32(data[138:142], uint32(p.Field2068))
	WStrCopyBytes(data[142:152], p.Field2072)
	data[152] = p.Byte152
	return data, nil
}

func (s *Server) newPlayerFromPacket(ind int, data []byte) int {
	var opts PlayerOpts
	if err := opts.UnmarshalBinary(data); err != nil {
		panic(err)
	}
	return s.newPlayer(ind, &opts)
}

func (s *Server) newPlayer(ind int, opts *PlayerOpts) int {
	v2 := opts.Byte152
	opts.Byte152 &= 0x7F
	v3 := v2 >> 7
	if ind != common.MaxPlayers-1 {
		if !noxflags.HasGame(noxflags.GameModeQuest) && v3 == 1 {
			return 0
		}
		if noxflags.HasGame(noxflags.GameModeQuest) && v3 == 0 {
			return 0
		}
	}
	v5 := sub_416640()
	netlist.ResetByInd(ind, netlist.Kind1)
	C.nox_xxx_playerResetImportantCtr_4E4F40(C.int(ind))
	sub_4E4F30(ind)

	var ptyp string
	if opts.Info.IsFemale() {
		ptyp = "PlayerFemale"
	} else if memmap.Uint32(0x5D4594, 1563280) != 0 {
		ptyp = "Player"
	} else {
		ptyp = "NewPlayer"
	}
	punit := s.newObjectByTypeID(ptyp).AsUnit()
	if punit == nil {
		return 0
	}
	if ind != common.MaxPlayers-1 {
		if v5[100] != 0 {
			if (1<<opts.Info.PlayerClass())&v5[100] != 0 {
				return 0
			}
		}
	}
	pl := s.playerResetInd(ind)
	if int8(v5[102]) >= 0 {
		pl.field_10 = C.ushort(opts.Screen.X / 2)
		pl.field_12 = C.ushort(opts.Screen.Y / 2)
	} else {
		if nox_win_width >= opts.Screen.X {
			pl.field_10 = C.ushort(opts.Screen.X / 2)
			pl.field_12 = C.ushort(opts.Screen.Y / 2)
		} else {
			pl.field_10 = C.ushort(nox_win_width / 2)
			pl.field_12 = C.ushort(nox_win_height / 2)
		}
	}
	pl.SetSerial(opts.Serial)
	pl.field_2135 = C.uchar(opts.Byte152)
	WStrCopy(&pl.field_2072[0], 10, opts.Field2072)
	pl.SetField2096(opts.Field2096)
	pl.field_2068 = C.uint(opts.Field2068)
	if pl.field_2068 != 0 {
		v12 := unsafe.Pointer(C.sub_425A70(C.int(pl.field_2068)))
		if v12 == nil {
			v12 = unsafe.Pointer(C.sub_425AD0(C.int(pl.field_2068), &pl.field_2072[0]))
		}
		C.sub_425B30(v12, C.int(ind))
	}
	pl.frame_3596 = C.uint(s.Frame())
	pl.field_3676 = 2
	pl.field_3680 = 0
	info := pl.Info()
	*info = opts.Info
	info.SetNameSuff("")
	pl.SetName(pl.OrigName())
	s.nox_xxx_playerCheckName_4DDA00(pl)
	C.nox_xxx_playerInitColors_461460(pl.C())
	pl.playerUnit = punit.CObj()
	pl.field_2152 = 0
	pl.netCode = C.uint(punit.NetCode)
	pl.field_2156 = C.uint(C.nox_xxx_scavengerTreasureMax_4D1600())
	udata := punit.UpdateDataPlayer()
	h := punit.HealthData
	udata.Player = pl.S()
	pl.prot_unit_hp_cur = C.uint(protectUint16(h.Cur))
	pl.prot_unit_hp_max = C.uint(protectUint16(h.Max))
	pl.prot_unit_mana_cur = C.uint(protectUint16(udata.ManaCur))
	pl.prot_unit_mana_max = C.uint(protectUint16(udata.ManaMax))
	pl.prot_unit_experience = C.uint(protectFloat32(punit.Experience))
	pl.prot_unit_mass = C.uint(protectFloat32(punit.Mass))
	pl.prot_unit_buffs = C.uint(protectInt(int(punit.Buffs)))
	pl.prot_player_class = C.uint(protectInt(int(pl.PlayerClass())))
	pl.prot_player_field_2235 = C.uint(protectUint32(pl.Info().Field2235()))
	pl.prot_player_field_2239 = C.uint(protectUint32(pl.Info().Field2239()))
	pl.prot_player_orig_name = C.uint(protectUint32(protectWStr(pl.OrigName())))
	pl.prot_4632 = C.uint(protectInt(0))
	pl.prot_4636 = C.uint(protectInt(0))
	pl.prot_4640 = C.uint(protectInt(0))
	pl.prot_player_gold = C.uint(protectInt(int(pl.gold)))
	pl.prot_player_level = C.uint(protectInt(int(pl.field_3684))) // level
	pl.field_4648 = -1
	pl.field_4700 = 1
	if C.dword_5d4594_2650652 != 0 {
		C.sub_41D670(internCStr(pl.Field2096()))
	}
	C.nox_xxx_netNotifyRate_4D7F10(C.int(ind))
	if noxflags.HasGame(noxflags.GameModeQuest) {
		pl.GoObserver(false, true)
	} else if noxflags.HasGame(noxflags.GameModeSolo10) {
		C.nox_xxx_netReportPlayerStatus_417630(pl.C())
	} else if pl.Index() == common.MaxPlayers-1 && noxflags.HasEngine(noxflags.EngineNoRendering) {
		pl.GoObserver(false, true)
	} else if noxflags.HasGame(noxflags.GameModeChat) {
		if C.sub_40A740() != 0 {
			if C.sub_40AA70(pl.C()) == 0 {
				pl.GoObserver(false, true)
			}
		} else if checkGameplayFlags(4) {
			C.sub_4DF3C0(pl.C())
		}
	} else if !noxflags.HasGame(noxflags.GameModeCoop) {
		pl.GoObserver(true, true)
	}
	s.sendSettings(punit)
	if pl.Index() == common.MaxPlayers-1 {
		C.nox_xxx_host_player_unit_3843628 = punit.CObj()
	}
	var v30 [132]byte
	nox_xxx_netNewPlayerMakePacket_4DDA90(v30[:], pl)
	s.nox_xxx_netSendPacket_4E5030(ind|0x80, v30[:129], 0, 0, 0)
	pl.field_3676 = 2
	if false && !noxflags.HasGame(noxflags.GameModeChat) {
		C.sub_425F10(pl.C())
	}
	s.createObjectAt(punit, nil, types.Pointf{X: 2944.0, Y: 2944.0})
	s.objectsNewAdd()
	var p28 types.Pointf
	if noxflags.HasGame(noxflags.GameModeQuest) {
		if p, ok := s.sub_4E8210(punit); !ok {
			p28 = s.nox_xxx_mapFindPlayerStart_4F7AB0(punit)
		} else {
			p28 = p
		}
	} else {
		p28 = s.nox_xxx_mapFindPlayerStart_4F7AB0(punit)
	}
	punit.SetPos(p28)
	sub_422140(pl)
	if ind != common.MaxPlayers-1 {
		if sub_459D70() == 2 {
			v24 := nox_xxx_cliGamedataGet_416590(1)
			C.nox_xxx_netGuiGameSettings_4DD9B0(1, unsafe.Pointer(&v24[0]), C.int(pl.Index()))
		} else {
			v29, v29free := alloc.Make([]byte{}, 60)
			defer v29free()
			C.sub_459AA0(unsafe.Pointer(&v29[0]))
			C.nox_xxx_netGuiGameSettings_4DD9B0(1, unsafe.Pointer(&v29[0]), C.int(pl.Index()))
		}
	}
	if noxflags.HasGame(noxflags.GameFlag15 | noxflags.GameFlag16) {
		if (pl.field_3680 & 1) == 0 {
			C.sub_509C30(pl.C())
		}
	}
	if !noxflags.HasGame(noxflags.GameModeCoop) {
		if noxflags.HasGame(noxflags.GameModeQuest) {
			C.nox_game_sendQuestStage_4D6960(C.int(ind))
			return int(punit.NetCode)
		}
		var buf [3]byte
		buf[0] = byte(noxnet.MSG_FADE_BEGIN)
		buf[1] = 1
		buf[2] = 1
		s.nox_xxx_netSendPacket_4E5030(ind, buf[:], 0, 0, 0)
	}
	s.callOnPlayerJoin(pl)
	return int(punit.NetCode)
}

func (s *Server) sub_4E8210(u *Unit) (types.Pointf, bool) {
	var (
		max uint32
		v2  unsafe.Pointer
	)
	for _, u2 := range s.getPlayerUnits() {
		ptr := u2.UpdateDataPlayer()
		ptr2 := ptr.Field77
		if ptr2 == nil {
			continue
		}
		if val := **(**uint32)(unsafe.Add(ptr2, 700)); val > max {
			max = val
			v2 = ptr2
		}
	}
	if v2 == nil {
		return types.Pointf{}, false
	}
	ud := u.UpdateDataPlayer()
	ud.Field77 = v2
	out := s.randomReachablePointAround(60.0, asPointf(unsafe.Add(v2, 7*8)))
	return out, true
}

func nox_xxx_plrSetSpellType_4F9B90(u *Unit) {
	ud := u.UpdateDataPlayer()
	ud.SpellPhonemeLeaf = unsafe.Pointer(getPhonemeTree())
	ud.SpellCastStart = noxServer.Frame()
}

func (s *Server) playerSpell(u *Unit) {
	ok2 := true
	ud := u.UpdateDataPlayer()
	pl := asPlayerS(ud.Player)
	var a1 int
	if u != nil {
		a1 = 1
	}
	if leaf := (*phonemeLeaf)(ud.SpellPhonemeLeaf); leaf == getPhonemeTree() {
		ok2 = false
	} else if leaf != nil && leaf.Ind != 0 {
		spellInd := spell.ID(leaf.Ind)
		if !noxflags.HasGame(noxflags.GameModeQuest) {
			targ := asObjectS(ud.CursorObj)
			if s.spellHasFlags(spellInd, things.SpellOffensive) {
				if targ != nil && !u.isEnemyTo(targ) {
					return
				}
			}
		}
		if pl.spell_lvl[spellInd] != 0 || spellInd == spell.SPELL_GLYPH {
			ok2 = false
			a1 = int(C.sub_4FD0E0(u.CObj(), C.int(spellInd)))
			if a1 == 0 {
				a1 = int(C.nox_xxx_checkPlrCantCastSpell_4FD150(u.CObj(), C.int(spellInd), 0))
			}
			if a1 != 0 {
				nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 0, a1)
				s.AudioEventObj(sound.SoundPermanentFizzle, u, 0, 0)
			} else {
				mana := int(C.sub_4FCF90(u.CObj(), C.int(spellInd), 1))
				if mana < 0 {
					a1 = 11
					nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 0, a1)
					s.AudioEventObj(sound.SoundManaEmpty, u, 0, 0)
				} else {
					arg, v14free := alloc.New(spellAcceptArg{})
					defer v14free()
					arg.Obj = pl.obj_3640
					if noxflags.HasGame(noxflags.GameModeQuest) && s.spellHasFlags(spellInd, things.SpellOffensive) {
						if pl.obj_3640 != nil && !u.isEnemyTo(asObjectC(pl.obj_3640)) {
							arg.Obj = nil
						}
					}
					arg.Pos = pl.CursorPos()
					if s.nox_xxx_castSpellByUser4FDD20(spellInd, u, arg) {
						nox_xxx_netInformTextMsg_4DA0F0(pl.Index(), 1, int(spellInd))
					} else {
						sub_4FD030(u, mana)
						a1 = 8
					}
				}
			}
		}
	}
	if ud.Field22_0 == 2 {
		nox_xxx_playerSetState_4FA020(u, 13)
	}
	if ok2 {
		v13 := s.Strings().GetStringInFile("SpellUnknown", "plyrspel.c")
		nox_xxx_netSendLineMessage_4D9EB0(u, v13)
	} else if a1 != 0 {
		v4 := (*phonemeLeaf)(ud.SpellPhonemeLeaf)
		nox_xxx_netReportSpellStat_4D9630(pl.Index(), spell.ID(v4.Ind), 0)
	} else {
		v4 := (*phonemeLeaf)(ud.SpellPhonemeLeaf)
		if !s.spellHasFlags(spell.ID(v4.Ind), things.SpellFlagUnk21) {
			nox_xxx_netReportSpellStat_4D9630(pl.Index(), spell.ID(v4.Ind), 15)
		}
	}
}

func sub_4FD030(a1 *Unit, a2 int) {
	if a1.Class().Has(object.ClassPlayer) {
		C.nox_xxx_playerManaAdd_4EEB80(a1.CObj(), C.short(a2))
	}
}

func nox_xxx_playerSubLessons_4D8EC0(u *Unit, val int) {
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	pl := u.ControllingPlayer()
	pl.lessons -= C.int(val)
}

func nox_xxx_changeScore_4D8E90(u *Unit, val int) {
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	pl := u.ControllingPlayer()
	pl.lessons += C.int(val)
}

func nox_xxx_loadBaseValues_57B200() {
	*memmap.PtrFloat32(0x5D4594, 2523812) = float32(gamedataFloat("BaseHealth"))
	*memmap.PtrFloat32(0x5D4594, 2523816) = float32(gamedataFloat("BaseMana"))
	*memmap.PtrFloat32(0x5D4594, 2523824) = float32(gamedataFloat("BaseStrength"))
	*memmap.PtrFloat32(0x5D4594, 2523820) = float32(gamedataFloat("BaseSpeed"))
	*memmap.PtrFloat32(0x5D4594, 2523828) = float32(gamedataFloat("WarriorMaxHealth")) * float32(C.nox_xxx_warriorMaxHealth_587000_312784)
	*memmap.PtrFloat32(0x5D4594, 2523832) = float32(gamedataFloat("WarriorMaxMana")) * float32(C.nox_xxx_warriorMaxMana_587000_312788)
	*memmap.PtrFloat32(0x5D4594, 2523840) = float32(gamedataFloat("WarriorMaxStrength")) * noxServer.players.mult.warrior.strength
	*memmap.PtrFloat32(0x5D4594, 2523836) = float32(gamedataFloat("WarriorMaxSpeed")) * noxServer.players.mult.warrior.speed
	*memmap.PtrFloat32(0x5D4594, 2523860) = float32(gamedataFloat("ConjurerMaxHealth")) * float32(C.nox_xxx_conjurerMaxHealth_587000_312800)
	*memmap.PtrFloat32(0x5D4594, 2523864) = float32(gamedataFloat("ConjurerMaxMana")) * float32(C.nox_xxx_conjurerMaxMana_587000_312804)
	*memmap.PtrFloat32(0x5D4594, 2523872) = float32(gamedataFloat("ConjurerMaxStrength")) * noxServer.players.mult.conjurer.strength
	*memmap.PtrFloat32(0x5D4594, 2523868) = float32(gamedataFloat("ConjurerMaxSpeed")) * noxServer.players.mult.conjurer.speed
	*memmap.PtrFloat32(0x5D4594, 2523844) = float32(gamedataFloat("WizardMaxHealth")) * float32(C.nox_xxx_wizardMaxHealth_587000_312816)
	*memmap.PtrFloat32(0x5D4594, 2523848) = float32(gamedataFloat("WizardMaxMana")) * float32(C.nox_xxx_wizardMaximumMana_587000_312820)
	*memmap.PtrFloat32(0x5D4594, 2523856) = float32(gamedataFloat("WizardMaxStrength")) * noxServer.players.mult.wizard.strength
	*memmap.PtrFloat32(0x5D4594, 2523852) = float32(gamedataFloat("WizardMaxSpeed")) * noxServer.players.mult.wizard.speed
}

func sub_4D6B10(a1 bool) {
	C.nox_xxx_warriorMaxHealth_587000_312784 = C.float(memmap.Float32(0x5D4594, 1556076))
	C.nox_xxx_warriorMaxMana_587000_312788 = C.float(memmap.Float32(0x5D4594, 1556084))
	noxServer.players.mult.warrior.strength = memmap.Float32(0x5D4594, 1556064)
	noxServer.players.mult.warrior.speed = memmap.Float32(0x5D4594, 1556072)
	C.nox_xxx_conjurerMaxHealth_587000_312800 = C.float(memmap.Float32(0x5D4594, 1556060))
	C.nox_xxx_conjurerMaxMana_587000_312804 = C.float(memmap.Float32(0x5D4594, 1556096))
	noxServer.players.mult.conjurer.strength = memmap.Float32(0x5D4594, 1550932)
	noxServer.players.mult.conjurer.speed = memmap.Float32(0x5D4594, 1556080)
	C.nox_xxx_wizardMaxHealth_587000_312816 = C.float(memmap.Float32(0x5D4594, 1556088))
	C.nox_xxx_wizardMaximumMana_587000_312820 = C.float(memmap.Float32(0x5D4594, 1556068))
	noxServer.players.mult.wizard.strength = memmap.Float32(0x5D4594, 1556100)
	noxServer.players.mult.wizard.speed = memmap.Float32(0x5D4594, 1556092)
	nox_xxx_loadBaseValues_57B200()
	for _, it := range noxServer.getPlayerUnits() {
		C.nox_xxx_plrReadVals_4EEDC0(it.CObj(), 0)
		if a1 {
			nox_xxx_netStatsMultiplier_4D9C20(it.CObj())
		}
	}
}

func sub_4D6A60() {
	C.nox_xxx_warriorMaxHealth_587000_312784 = 3
	C.nox_xxx_warriorMaxMana_587000_312788 = 1
	noxServer.players.mult.warrior.strength = 1
	noxServer.players.mult.warrior.speed = 1
	C.nox_xxx_conjurerMaxHealth_587000_312800 = 3
	C.nox_xxx_conjurerMaxMana_587000_312804 = 3
	noxServer.players.mult.conjurer.strength = 1
	noxServer.players.mult.conjurer.speed = 1
	C.nox_xxx_wizardMaxHealth_587000_312816 = 3
	C.nox_xxx_wizardMaximumMana_587000_312820 = 3
	noxServer.players.mult.wizard.strength = 1
	noxServer.players.mult.wizard.speed = 1
	nox_xxx_loadBaseValues_57B200()
	for _, it := range noxServer.getPlayerUnits() {
		C.nox_xxx_plrReadVals_4EEDC0(it.CObj(), 0)
		nox_xxx_netStatsMultiplier_4D9C20(it.CObj())
	}
}

func sub_4D6BE0() {
	*memmap.PtrFloat32(0x5D4594, 1556076) = float32(C.nox_xxx_warriorMaxHealth_587000_312784)
	*memmap.PtrFloat32(0x5D4594, 1556084) = float32(C.nox_xxx_warriorMaxMana_587000_312788)
	*memmap.PtrFloat32(0x5D4594, 1556064) = noxServer.players.mult.warrior.strength
	*memmap.PtrFloat32(0x5D4594, 1556072) = noxServer.players.mult.warrior.speed
	*memmap.PtrFloat32(0x5D4594, 1556060) = float32(C.nox_xxx_conjurerMaxHealth_587000_312800)
	*memmap.PtrFloat32(0x5D4594, 1556096) = float32(C.nox_xxx_conjurerMaxMana_587000_312804)
	*memmap.PtrFloat32(0x5D4594, 1550932) = noxServer.players.mult.conjurer.strength
	*memmap.PtrFloat32(0x5D4594, 1556080) = noxServer.players.mult.conjurer.speed
	*memmap.PtrFloat32(0x5D4594, 1556088) = float32(C.nox_xxx_wizardMaxHealth_587000_312816)
	*memmap.PtrFloat32(0x5D4594, 1556068) = float32(C.nox_xxx_wizardMaximumMana_587000_312820)
	*memmap.PtrFloat32(0x5D4594, 1556100) = noxServer.players.mult.wizard.strength
	*memmap.PtrFloat32(0x5D4594, 1556092) = noxServer.players.mult.wizard.speed
}

//export nox_client_onClassStats
func nox_client_onClassStats(cbuf *C.uchar, sz C.int) {
	data := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(sz))
	switch player.Class(memmap.Uint8(0x85B3FC, 12254)) {
	case player.Warrior:
		C.nox_xxx_warriorMaxHealth_587000_312784 = C.float(math.Float32frombits(binary.LittleEndian.Uint32(data[1:])))
		C.nox_xxx_warriorMaxMana_587000_312788 = C.float(math.Float32frombits(binary.LittleEndian.Uint32(data[5:])))
		noxServer.players.mult.warrior.strength = math.Float32frombits(binary.LittleEndian.Uint32(data[9:]))
		noxServer.players.mult.warrior.speed = math.Float32frombits(binary.LittleEndian.Uint32(data[13:]))
	case player.Wizard:
		C.nox_xxx_wizardMaxHealth_587000_312816 = C.float(math.Float32frombits(binary.LittleEndian.Uint32(data[1:])))
		C.nox_xxx_wizardMaximumMana_587000_312820 = C.float(math.Float32frombits(binary.LittleEndian.Uint32(data[5:])))
		noxServer.players.mult.wizard.strength = math.Float32frombits(binary.LittleEndian.Uint32(data[9:]))
		noxServer.players.mult.wizard.speed = math.Float32frombits(binary.LittleEndian.Uint32(data[13:]))
	case player.Conjurer:
		C.nox_xxx_conjurerMaxHealth_587000_312800 = C.float(math.Float32frombits(binary.LittleEndian.Uint32(data[1:])))
		C.nox_xxx_conjurerMaxMana_587000_312804 = C.float(math.Float32frombits(binary.LittleEndian.Uint32(data[5:])))
		noxServer.players.mult.conjurer.strength = math.Float32frombits(binary.LittleEndian.Uint32(data[9:]))
		noxServer.players.mult.conjurer.speed = math.Float32frombits(binary.LittleEndian.Uint32(data[13:]))
	}
	nox_xxx_loadBaseValues_57B200()
}

//export nox_xxx_playerObserveMonster_4DDE80
func nox_xxx_playerObserveMonster_4DDE80(cplayer, cunit *nox_object_t) {
	pu := asUnitC(cplayer)
	ud := pu.UpdateDataPlayer()
	pl := asPlayerS(ud.Player)

	targ := asObjectC(cunit)

	if pl.field_3680&0x1 != 0 {
		C.nox_xxx_playerLeaveObserver_0_4E6AA0(pl.C())
	}
	if pl.field_3680&0x2 != 0 {
		pu.observeClear()
	}
	C.nox_xxx_netNeedTimestampStatus_4174F0(pl.C(), 2)
	pl.CameraFollow(targ)
	_ = nox_xxx_updatePlayerObserver_4E62F0
	pu.Update = C.nox_xxx_updatePlayerObserver_4E62F0
}

func (s *Server) nox_xxx_playerLeaveObsByObserved_4E60A0(obj noxObject) {
	cobj := toCObj(obj)
	for pl := s.playerFirst(); pl != nil; pl = s.playerNext(pl) {
		if pl.CameraTarget().CObj() == cobj {
			pl.leaveMonsterObserver()
		}
	}
}
