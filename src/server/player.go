package server

import (
	"fmt"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type classStatMult struct {
	// TODO: health and mana

	Strength float32
	Speed    float32
}

type serverPlayers struct {
	list []Player
	Mult struct {
		Warrior  classStatMult
		Wizard   classStatMult
		Conjurer classStatMult
	}
	Control  serverCtrlBuf
	HostUnit *Object
}

func (s *serverPlayers) init() {
	s.list, _ = alloc.Make([]Player{}, common.MaxPlayers)
	s.Mult.Warrior = classStatMult{
		Strength: 1,
		Speed:    1,
	}
	s.Mult.Wizard = classStatMult{
		Strength: 1,
		Speed:    1,
	}
	s.Mult.Conjurer = classStatMult{
		Strength: 1,
		Speed:    1,
	}
}

func (s *serverPlayers) ResetAll() {
	for i := range s.list {
		s.list[i] = Player{}
	}
}

func (s *serverPlayers) First() *Player {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() {
			return p
		}
	}
	return nil
}

func (s *serverPlayers) Next(it *Player) *Player {
	if it == nil {
		return nil
	}
	for i := it.Index() + 1; i < len(s.list); i++ {
		p := &s.list[i]
		if p.IsActive() {
			return p
		}
	}
	return nil
}

func (s *serverPlayers) Each(fnc func(it *Player) bool) {
	for it := s.First(); it != nil; it = s.Next(it) {
		if !fnc(it) {
			return
		}
	}
}

func (s *serverPlayers) EachReplaceable(fnc func(it *Player) bool) {
	for it := s.firstReplaceablePlayer(); it != nil; it = s.nextReplaceablePlayer(it) {
		if !fnc(it) {
			return
		}
	}
}

func (s *serverPlayers) firstReplaceablePlayer() *Player {
	for it := s.First(); it != nil; it = s.Next(it) {
		if it.Field3680&1 != 0 && it.Index() != -1 {
			return it
		}
	}
	return nil
}

func (s *serverPlayers) nextReplaceablePlayer(it *Player) *Player {
	for ; it != nil; it = s.Next(it) {
		if it.Field3680&1 != 0 && it.Index() != -1 {
			return it
		}
	}
	return nil
}

func (s *serverPlayers) ResetInd(ind ntype.PlayerInd) *Player {
	p := &s.list[ind]
	p.reset(ind)
	return p
}

func (s *serverPlayers) ByID(id int) *Player {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() && int(p.NetCodeVal) == id {
			return p
		}
	}
	return nil
}

func (s *serverPlayers) ByInd(i ntype.PlayerInd) *Player {
	if i < 0 || int(i) >= len(s.list) {
		return nil
	}
	p := &s.list[i]
	if !p.IsActive() {
		return nil
	}
	p.PlayerInd = byte(i)
	return p
}

func (s *serverPlayers) ByIndRaw(i ntype.PlayerInd) *Player {
	if i < 0 || int(i) >= len(s.list) {
		return nil
	}
	return &s.list[i]
}

func (s *serverPlayers) HasUnits() bool {
	for i := range s.list {
		p := &s.list[i]
		if p.PlayerUnit != nil {
			return true
		}
	}
	return false
}

func (s *serverPlayers) List() (out []*Player) {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() {
			out = append(out, p)
		}
	}
	return out
}

func (s *serverPlayers) Count() (n int) {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() {
			n++
		}
	}
	return n
}

func (s *serverPlayers) ListSlots() (out []*Player) {
	for i := range s.list {
		p := &s.list[i]
		out = append(out, p)
	}
	return out
}

func (s *serverPlayers) NewRaw(id int) *Player {
	if p := s.ByID(id); p != nil {
		return p
	}
	for i := range s.list {
		p := &s.list[i]
		if !p.IsActive() {
			p.reset(ntype.PlayerInd(i))
			p.NetCodeVal = uint32(id)
			return p
		}
	}
	return nil
}

func (s *serverPlayers) CheckName(pl *Player) {
	for i := 2; ; i++ {
		ok := true
		for _, pl2 := range s.List() {
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

var _ = [1]struct{}{}[8-unsafe.Sizeof(PlayerNetData{})]

type PlayerNetData struct {
	Field0 uint16
	Field2 uint16
	Frame4 uint32
}

var _ = [1]struct{}{}[76-unsafe.Sizeof(PlayerJournal{})]

type PlayerJournal struct {
	EntryBuf [64]byte       // 0, 0
	Next     *PlayerJournal // 1, 64
	Prev     *PlayerJournal // 2, 68
	Field3   uint16         // 3, 72
	Field4   uint16         // 4, 74, likely just padding
}

var (
	_ = [1]struct{}{}[4828-unsafe.Sizeof(Player{})]
	_ = [1]struct{}{}[2185-unsafe.Offsetof(Player{}.info)]
	_ = [1]struct{}{}[2282-unsafe.Offsetof(Player{}.field2282)]
	_ = [1]struct{}{}[3596-unsafe.Offsetof(Player{}.Frame3596)]
	_ = [1]struct{}{}[4580-unsafe.Offsetof(Player{}.Field4580)]
	_ = [1]struct{}{}[4800-unsafe.Offsetof(Player{}.data4800)]
)

var _ Obj = (*Player)(nil) // proxies Unit

type Player struct {
	Field0              uint32             // 0, 0
	Field4              uint32             // 1, 4
	Field8              uint16             // 2, 8
	Field10             uint16             // 2, 10
	Field12             uint16             // 3, 12
	field14             uint16             // 3, 14
	NetData16           [255]PlayerNetData // 4, 16
	PlayerUnit          *Object            // 514, 2056
	NetCodeVal          uint32             // 515, 2060
	PlayerInd           byte               // 516, 2064
	_                   [3]byte            // 516, 2065
	Field2068           uint32             // 517, 2068
	Field2072           [10]uint16         // 518, 2072
	Active              byte               // 523, 2092
	Field2096Buf        [12]byte           // 524, 2096
	Field2108           uint32             // 527, 2108
	SerialBuf           [22]byte           // 528, 2112
	field2134           byte
	Field2135           byte
	Lessons             int32  // 534, 2136
	Field2140           uint32 // 535, 2140
	Field2144           uint32 // 536, 2144
	field2148           uint32 // 537, 2148
	Field2152           uint32 // 538, 2152
	Field2156           uint32 // 539, 2156
	field2160           uint32 // 540, 2160
	GoldVal             uint32 // 541, 2164
	_                   [17]byte
	info                [97]byte    // 2185
	field2282           uint16      // 2282
	CursorVec           image.Point // 2284
	_                   [322]uint32
	Field3580           uint32
	Field3584           uint32
	Field3588           uint32
	Field3592           uint32
	Frame3596           uint32
	Field3600           uint32         // 900, 3600
	Field3604           uint32         // 901, 3604
	field3608           uint32         // 902, 3608
	field3612           uint32         // 903, 3612
	field3616           uint32         // 904, 3616
	field3620           uint32         // 905, 3620
	field3624           uint32         // 906, 3624
	CameraFollowObj     *Object        // 907, 3628
	Pos3632Vec          types.Pointf   // 908, 3632
	Obj3640             *Object        // 910, 3640
	Journal             *PlayerJournal // 911, 3644, pointer to journal
	SummonOrderAll      uint32         // 912, 3648
	field3652           uint32
	Field3656           uint32
	field3660           uint32
	field3664           uint32
	field3668           uint32
	Field3672           uint32 // 3672
	Field3676           byte   // 3676, TODO: status?
	_                   [3]byte
	Field3680           uint32 // 920, 3680, TODO: some flags?
	Level               uint8  // 921, 3684
	_                   [3]byte
	Field3688           uint32
	Field3692           uint32
	SpellLvl            [137]uint32 // 3696
	BeastScrollLvl      [41]uint32  // 4244
	_                   [43]uint32
	Field4580           unsafe.Pointer // 1145, 4580
	ProtUnitHPCur       uint32         // 1146, 4584
	ProtPlayerGold      uint32         // 1147, 4588
	ProtUnitHPMax       uint32         // 1148, 4592
	ProtUnitManaCur     uint32         // 1149, 4596
	ProtUnitManaMax     uint32         // 1150, 4600
	ProtUnitExperience  uint32         // 1151, 4604
	ProtUnitMass        uint32         // 1152, 4608
	ProtUnitBuffs       uint32         // 1153, 4612
	ProtPlayerClass     uint32         // 1154, 4616
	ProtPlayerField2235 uint32         // 1155, 4620
	ProtPlayerField2239 uint32         // 1156, 4624
	ProtPlayerOrigName  uint32         // 1157, 4628
	Prot4632            uint32         // 1158, 4632
	Prot4636            uint32         // 1159, 4636
	Prot4640            uint32         // 1160, 4640
	ProtPlayerLevel     uint32         // 1161, 4644
	Field4648           int32          // 1162, 4648
	field4652           uint32         // 1163, 4652
	field4656           uint32         // 1164, 4656
	field4660           uint32         // 1165, 4660
	field4664           uint32         // 1166, 4664
	field4668           uint32         // 1167, 4668
	field4672           uint32         // 1168, 4672
	field4676           uint32         // 1169, 4676
	field4680           uint32         // 1170, 4680
	field4684           uint32         // 1171, 4684
	field4688           uint32         // 1172, 4688
	field4692           uint32         // 1173, 4692
	field4696           uint32         // 1174, 4696
	Field4700           uint32         // 1175, 4700
	NameFinal           [28]uint16     // 4704, server-approved player name // TODO: size is a wild guess
	SaveNameBuf         [4]byte        // 1190, 4760
	field4764           uint32         // 1191, 4764
	field4768           uint32         // 1192, 4768
	field4772           uint32         // 1193, 4772
	field4776           uint32         // 1194, 4776
	field4780           uint32         // 1195, 4780
	field4784           uint32         // 1196, 4784
	field4788           uint32         // 1197, 4788
	Field4792           uint32         // 1198, 4792
	field4796           uint32         // 1199, 4796
	data4800            [7]uint32
}

func (p *Player) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *Player) String() string {
	return fmt.Sprintf("Player(%q)", p.Name())
}

func (p *Player) IsActive() bool {
	return p != nil && p.Active != 0
}

func (p *Player) Index() int {
	if p == nil {
		return -1
	}
	return int(p.PlayerInd)
}

func (p *Player) PlayerIndex() ntype.PlayerInd {
	if p == nil {
		return -1
	}
	return ntype.PlayerInd(p.PlayerInd)
}

func (p *Player) NetCode() int {
	if p == nil {
		return -1
	}
	return int(p.NetCodeVal)
}

func (p *Player) Gold() int {
	return int(p.GoldVal)
}

func (p *Player) CursorPos() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(p.CursorVec.X),
		Y: float32(p.CursorVec.Y),
	}
}

func (p *Player) SetCursorPos(pos image.Point) {
	p.CursorVec = pos
}

func (p *Player) Pos3632() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	return p.Pos3632Vec
}

func (p *Player) SetPos3632(pt types.Pointf) {
	p.Pos3632Vec = pt
}

func (p *Player) reset(ind ntype.PlayerInd) {
	*p = Player{
		PlayerInd:      byte(ind),
		Active:         1,
		SummonOrderAll: 4,
	}
}

func (p *Player) SObj() *Object {
	if p == nil {
		return nil
	}
	return p.PlayerUnit
}

func (p *Player) Info() *PlayerInfo {
	if p == nil {
		return nil
	}
	return (*PlayerInfo)(unsafe.Pointer(&p.info)) // inaccessible due to alignment issues
}

func (p *Player) OrigName() string {
	return p.Info().Name()
}

func (p *Player) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return p.Info().PlayerClass()
}

func (p *Player) SetName(v string) {
	alloc.StrCopy16(p.NameFinal[:], v)
}

func (p *Player) Name() string {
	return alloc.GoString16S(p.NameFinal[:])
}

func (p *Player) SaveName() string {
	return alloc.GoString(&p.SaveNameBuf[0])
}

func (p *Player) Serial() string {
	return alloc.GoStringS(p.SerialBuf[:])
}

func (p *Player) SetSerial(v string) {
	alloc.StrCopy(p.SerialBuf[:], v)
}

func (p *Player) Field2096() string {
	return alloc.GoStringS(p.Field2096Buf[:])
}

func (p *Player) SetField2096(v string) {
	alloc.StrCopy(p.Field2096Buf[:], v)
}

func (p *Player) CameraUnlock() { // nox_xxx_playerCameraUnlock_4E6040
	if p == nil {
		return
	}
	p.CameraFollowObj = nil
}

func (p *Player) CameraFollow(obj Obj) {
	if p == nil {
		return
	}
	p.CameraFollowObj = toObject(obj)
}

func (p *Player) CameraToggle(obj Obj) { // nox_xxx_playerCameraFollow_4E6060
	if p == nil {
		return
	}
	if p.CameraFollowObj == toObject(obj) {
		p.CameraUnlock()
	} else {
		p.CameraFollow(obj)
	}
}

func (p *Player) CameraTarget() *Object {
	if p == nil {
		return nil
	}
	return p.CameraFollowObj
}

func (p *Player) ObserveTarget() *Object { // nox_xxx_playerGetPossess_4DDF30
	if p == nil {
		return nil
	}
	if p.Field3680&2 == 0 {
		return nil
	}
	return p.CameraFollowObj
}

func (p *Player) Sub422140() {
	if p != nil {
		p.field3660 = 0xDEADFACE
		p.field3664 = 0xDEADFACE
	}
}

var (
	_ = [1]struct{}{}[97-unsafe.Sizeof(PlayerInfo{})]
	_ = [1]struct{}{}[0-unsafe.Offsetof(PlayerInfo{}.name)]
	_ = [1]struct{}{}[66-unsafe.Offsetof(PlayerInfo{}.playerClass)]
	_ = [1]struct{}{}[89-unsafe.Offsetof(PlayerInfo{}.nameSuff)]
)

type PlayerInfo struct {
	name        [50]byte // 2185 (+0) // TODO: size is a guess
	field2235   [4]byte  // 2235 (+50)
	field2239   [4]byte  // 2239 (+54)
	field2243   [4]byte  // 2243 (+58)
	field2247   [4]byte  // 2247 (+62)
	playerClass byte     // 562, 2251 (+66)
	isFemale    byte     // 562, 2252 (+67)
	field2253   [2]byte  // 2253 (+68)
	Field2255   byte     // 2255 (+70)
	field2256   [2]byte  // 2256 (+71)
	Field2258   byte     // 2258 (+73)
	field2259   [2]byte  // 2259 (+74)
	Field2261   byte     // 2261 (+76)
	field2262   [2]byte  // 2262 (+77)
	Field2264   byte     // 2264 (+79)
	field2265   [2]byte  // 2265 (+80)
	Field2267   byte     // 2267 (+82)
	Field2268   byte     // 2268 (+83)
	Field2269   byte     // 2269 (+84)
	Field2270   byte     // 2270 (+85)
	Field2271   byte     // 2271 (+86)
	Field2272   byte     // 2272 (+87)
	Field2273   byte     // 2273 (+88)
	nameSuff    [8]byte  // 2274 (+89)
}

func (p *PlayerInfo) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *PlayerInfo) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return player.Class(p.playerClass)
}

func (p *PlayerInfo) SetPlayerClass(v player.Class) {
	p.playerClass = byte(v)
}

func (p *PlayerInfo) IsFemale() bool {
	if p == nil {
		return false
	}
	return p.isFemale != 0
}

func (p *PlayerInfo) SetIsFemale(v byte) {
	p.isFemale = v
}

func (p *PlayerInfo) Name() string {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.name[0])), len(p.name)/2)
	return alloc.GoString16S(arr[:])
}

func (p *PlayerInfo) SetName(v string) {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.name[0])), len(p.name)/2)
	alloc.StrCopy16(arr, v)
}

func (p *PlayerInfo) NameSuff() string {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.nameSuff[0])), len(p.nameSuff)/2)
	return alloc.GoString16S(arr[:])
}

func (p *PlayerInfo) SetNameSuff(v string) {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.nameSuff[0])), len(p.nameSuff)/2)
	alloc.StrCopy16(arr, v)
}

func (p *PlayerInfo) Field2235() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2235))
}

func (p *PlayerInfo) Field2239() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2239))
}

func (p *PlayerInfo) Field2243() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2243))
}

func (p *PlayerInfo) Field2247() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2247))
}

func (p *PlayerInfo) Field2253() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2253))
}

func (p *PlayerInfo) Field2256() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2256))
}

func (p *PlayerInfo) Field2259() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2259))
}

func (p *PlayerInfo) Field2262() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2262))
}

func (p *PlayerInfo) Field2265() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2265))
}

func (p *PlayerInfo) SetField2235(v uint32) {
	*(*uint32)(unsafe.Pointer(&p.field2235)) = v
}

func (p *PlayerInfo) SetField2239(v uint32) {
	*(*uint32)(unsafe.Pointer(&p.field2239)) = v
}

func (p *PlayerInfo) SetField2253(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2253)) = v
}

func (p *PlayerInfo) SetField2256(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2256)) = v
}

func (p *PlayerInfo) SetField2259(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2259)) = v
}

func (p *PlayerInfo) SetField2262(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2262)) = v
}

func (p *PlayerInfo) SetField2265(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2265)) = v
}
