package server

import (
	"errors"
	"fmt"
	"image"
	"math"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/types"
	"github.com/noxworld-dev/opennox-lib/wall"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const WallGridSize = 256

type serverWalls struct {
	defs    [80]WallDef
	defsCnt int

	head     *Wall
	freeList *Wall
	byPos    []*Wall // index is wallArrayInd
	indexY   []*Wall
}

func (s *serverWalls) ResetDefs() {
	s.defsCnt = 0
}

func (s *serverWalls) Defs() []WallDef {
	return s.defs[:s.defsCnt]
}

func (s *serverWalls) DefByInd(i int) *WallDef {
	if i < 0 || i >= s.defsCnt {
		return nil
	}
	return &s.defs[i]
}

func (s *serverWalls) ReadWall(f *binfile.MemFile) error {
	if s.defsCnt >= cap(s.defs) {
		return errors.New("too many wall definitions")
	}
	p := &s.defs[s.defsCnt]
	f.Skip(4)
	name, _ := f.ReadString8()
	alloc.StrCopyZero(p.Field0[:], name)
	p.Flags32 = f.ReadU32()
	p.Field36 = uint16(int16(f.ReadI32()))
	p.Field38 = uint16(int16(f.ReadI32()))
	p.Field40 = f.ReadU8()
	p.Health41 = f.ReadU8()
	v39 := f.ReadU64Align()
	p.BrickType42 = uint8(int8(v39))
	p.Brick43 = [8][64]byte{}
	for i := 0; i < int(p.BrickType42); i++ {
		if i >= len(p.Brick43) {
			return errors.New("too many wall sub defs")
		}
		v4, _ := f.ReadString8()
		alloc.StrCopyZero(p.Brick43[i][:], v4)
	}
	v45, _ := f.ReadString8()
	alloc.StrCopyZero(p.SoundOpen555[:], v45)
	v46, _ := f.ReadString8()
	alloc.StrCopyZero(p.SoundClose619[:], v46)
	v47, _ := f.ReadString8()
	alloc.StrCopyZero(p.Sound683[:], v47)
	p.Field749 = f.ReadU8()
	p.Sprite8432 = [4][15][16]unsafe.Pointer{}

	for dir := WallDirUp; dir <= WallDirLeftHalfArrowUp; dir++ {
		sz := f.ReadU64Align()
		for jj := 0; jj < int(sz); jj++ {
			for kk := 0; kk < 4; kk++ {
				p.Variations12272[kk][dir] = uint8(int8(sz))
				v1 := int(f.ReadI32())
				v2 := int(f.ReadI32())
				p.DrawOffs752[kk][dir][jj] = image.Pt(v1, v2)
				if f.ReadI32() == -1 {
					f.Skip(1)
					f.SkipString8()
				}
			}
		}
	}
	if f.ReadU32() != 0x454E4420 { // "END "
		return errors.New("expected section end")
	}
	s.defsCnt++
	return nil
}

func (s *serverWalls) DefIndByName(name string) int {
	if s.defsCnt <= 0 {
		return -1
	}
	for i := 0; i < s.defsCnt; i++ {
		p := &s.defs[i]
		if p.Name() == name {
			return i
		}
	}
	return -1
}

func (s *serverWalls) ResetSprites() {
	for i := range s.defs {
		p := &s.defs[i]
		p.Sprite8432 = [4][15][16]unsafe.Pointer{}
	}
}

func (s *serverWalls) Init() int {
	s.byPos, _ = alloc.Make([]*Wall{}, 32*WallGridSize)
	if s.byPos == nil {
		return 0
	}

	s.indexY, _ = alloc.Make([]*Wall{}, WallGridSize)
	if s.indexY == nil {
		return 0
	}
	s.head = nil
	for i := 0; i < 32*WallGridSize; i++ {
		ptr, _ := alloc.New(Wall{})
		if ptr == nil {
			return 0
		}
		ptr.Next20 = s.freeList
		s.freeList = ptr
	}
	s.Reset()
	return 1
}

func (s *serverWalls) Reset() {
	for i := 0; i < 32*WallGridSize; i++ {
		ptr := s.byPos[i]
		if ptr == nil {
			s.byPos[i] = nil
			continue
		}

		var next *Wall
		prev := s.freeList
		for it := ptr; it != nil; it = next {
			next = it.NextByPos16
			it.Next20 = prev
			s.freeList = it
			prev = it
		}
		s.byPos[i] = nil
	}
	s.head = nil
	for i := 0; i < WallGridSize; i++ {
		s.indexY[i] = nil
	}
}

func (s *serverWalls) Free() {
	for i := 0; i < 32*WallGridSize; i++ {
		var next *Wall
		for ptr := s.byPos[i]; ptr != nil; ptr = next {
			next = ptr.NextByPos16
			alloc.Free(ptr)
		}
	}
	var next *Wall
	for ptr := s.freeList; ptr != nil; ptr = next {
		next = ptr.Next20
		alloc.Free(ptr)
	}
	s.freeList = nil

	alloc.FreeSlice(s.byPos)
	s.byPos = nil

	alloc.FreeSlice(s.indexY)
	s.indexY = nil
}

func wallArrayInd(pos image.Point) uint16 {
	return (uint16(pos.Y) + (uint16(pos.X) << 8)) & 0x1FFF
}

func (s *serverWalls) GetWallAtGrid(pos image.Point) *Wall {
	if (byte(pos.X)+byte(pos.Y))&0x1 != 0 {
		return nil
	}
	ind := wallArrayInd(pos)
	for it := s.byPos[ind]; it != nil; it = it.NextByPos16 {
		if pos == it.GridPos() && !it.Flags4.HasAny(WallFlag5|WallFlag6) {
			return it
		}
	}
	return nil
}

func (s *serverWalls) GetWallAtGrid2(pos image.Point) *Wall {
	ind := wallArrayInd(pos)
	for it := s.byPos[ind]; it != nil; it = it.NextByPos16 {
		if pos == it.GridPos() && !it.Flags4.Has(WallFlag6) {
			return it
		}
	}
	return nil
}

func (s *serverWalls) GetWallAt(pos types.Pointf) *Wall {
	return s.GetWallAtGrid(wall.PosToGrid(pos))
}

func (s *serverWalls) IndexByY(y int) *Wall {
	if y < 0 || y >= WallGridSize {
		return nil
	}
	return s.indexY[y]
}

func (s *serverWalls) EachWallXxx(fnc func(it *Wall)) {
	var next *Wall
	for it := s.head; it != nil; it = next {
		next = it.Next20
		if !it.Flags4.HasAny(WallFlag5 | WallFlag6) {
			fnc(it)
		}
	}
}

func (s *serverWalls) GetWallNear(pos types.Pointf) *Wall {
	if w := s.GetWallAt(pos); w != nil {
		return w
	}
	// TODO: a better way
	pi := wall.PosToGrid(pos)
	try := []image.Point{
		{X: pi.X + 1, Y: pi.Y},
		{X: pi.X - 1, Y: pi.Y},
		{X: pi.X, Y: pi.Y + 1},
		{X: pi.X, Y: pi.Y - 1},
		{X: pi.X + 1, Y: pi.Y + 1},
		{X: pi.X + 1, Y: pi.Y - 1},
		{X: pi.X - 1, Y: pi.Y + 1},
		{X: pi.X - 1, Y: pi.Y - 1},
	}
	sort.Slice(try, func(i, j int) bool {
		p1, p2 := wall.GridToPos(try[i]), wall.GridToPos(try[j])
		d1 := p1.Sub(pos).Len()
		d2 := p2.Sub(pos).Len()
		return d1 < d2
	})
	for _, p := range try {
		if w := s.GetWallAtGrid(p); w != nil {
			return w
		}
	}
	return nil
}

func (s *serverWalls) addByPos(wl *Wall, pos image.Point) {
	ind := wallArrayInd(pos)
	wl.NextByPos16 = s.byPos[ind]
	s.byPos[ind] = wl
}

func (s *serverWalls) add(wl *Wall) {
	wl.Next20 = s.head
	s.head = wl
}

func (s *serverWalls) addByY(wl *Wall, y int) {
	var prev *Wall
	for it := s.indexY[y]; it != nil; it = it.NextByY24 {
		if wl.X5 < it.X5 {
			if prev != nil {
				prev.NextByY24 = wl
			} else {
				s.indexY[y] = wl
			}
			wl.NextByY24 = it
			return
		}
		prev = it
	}
	if prev != nil {
		prev.NextByY24 = wl
	} else {
		s.indexY[y] = wl
	}
	wl.NextByY24 = nil
}

func (s *serverWalls) getFree() *Wall {
	wl := s.freeList
	if wl == nil {
		return nil
	}
	s.freeList = wl.Next20
	return wl
}

func (s *serverWalls) CreateAtGrid(pos image.Point) *Wall {
	if pos.X < 0 || pos.X >= WallGridSize || pos.Y < 0 || pos.Y >= WallGridSize {
		return nil
	}
	if wl := s.GetWallAtGrid(pos); wl != nil {
		return wl
	}
	wl := s.getFree()
	if wl == nil {
		return nil
	}
	*wl = Wall{
		X5: byte(pos.X),
		Y6: byte(pos.Y),
	}
	s.add(wl)
	s.addByPos(wl, pos)
	s.addByY(wl, pos.Y)
	return wl
}

func (s *serverWalls) findByPos(pos image.Point) (cur, prev *Wall) {
	ind := wallArrayInd(pos)
	for it := s.byPos[ind]; it != nil; it = it.NextByPos16 {
		if it.X5 == byte(pos.X) && it.Y6 == byte(pos.Y) {
			return it, prev
		}
		prev = it
	}
	return nil, prev
}

func (s *serverWalls) deleteByPos(pos image.Point) (*Wall, bool) {
	wl, prev := s.findByPos(pos)
	if wl == nil {
		return nil, false
	}
	if prev != nil {
		prev.NextByPos16 = wl.NextByPos16
	} else {
		ind := wallArrayInd(pos)
		s.byPos[ind] = wl.NextByPos16
	}
	return wl, true
}

func (s *serverWalls) findByY(pos image.Point) (cur, prev *Wall) {
	for it := s.indexY[pos.Y]; it != nil; it = it.NextByY24 {
		if it.X5 == byte(pos.X) && it.Y6 == byte(pos.Y) {
			return it, prev
		}
		prev = it
	}
	return nil, prev
}

func (s *serverWalls) deleteByY(pos image.Point, wl *Wall) {
	if _, prev := s.findByY(pos); prev != nil {
		prev.NextByY24 = wl.NextByY24
	} else {
		s.indexY[pos.Y] = wl.NextByY24
	}
}

func (s *serverWalls) find(wl *Wall) (cur, prev *Wall) {
	for it := s.head; it != nil; it = it.NextByY24 {
		if it == wl {
			return it, prev
		}
		prev = it
	}
	return nil, prev
}

func (s *serverWalls) delete(wl *Wall) {
	if _, prev := s.find(wl); prev != nil {
		prev.Next20 = wl.Next20
	} else {
		s.head = wl.Next20
	}
}

func (s *serverWalls) DeleteAtGrid(pos image.Point) {
	wl, ok := s.deleteByPos(pos)
	if !ok {
		return
	}
	s.delete(wl)
	s.deleteByY(pos, wl)
	wl.Next20 = s.freeList
	s.freeList = wl
}

func ParseWallDir(name string) (WallDir, bool) {
	for i, v := range wallDirNames {
		if v == name {
			return WallDir(i), true
		}
	}
	return 0, false
}

type WallDir byte

func (d WallDir) String() string {
	if int(d) >= len(wallDirNames) {
		return fmt.Sprintf("WallDir(%d)", int(d))
	}
	return wallDirNames[d]
}

const (
	WallDirUp = WallDir(iota)
	WallDirDown
	WallDirCross
	WallDirTNorthWest
	WallDirTNorthEast
	WallDirTSouthEast
	WallDirTSouthWest
	WallDirArrowDown
	WallDirArrowLeft
	WallDirArrowUp
	WallDirArrowRight
	WallDirWindowUp
	WallDirWindowDown
	WallDirRightHalfArrowUp
	WallDirLeftHalfArrowUp
)

var wallDirNames = []string{
	"UP", "DOWN", "CROSS", "TNORTHWEST", "TNORTHEAST",
	"TSOUTHEAST", "TSOUTHWEST", "ARROWDOWN", "ARROWLEFT", "ARROWUP",
	"ARROWRIGHT", "WINDOWUP", "WINDOWDOWN", "RIGHTHALFARROWUP", "LEFTHALFARROWUP",
}

type WallDef struct {
	Field0          [32]byte                  // 0, 0
	Flags32         uint32                    // 8, 32
	Field36         uint16                    // 9, 36
	Field38         uint16                    // 9, 38
	Field40         byte                      // 10, 40
	Health41        byte                      // 10, 41
	BrickType42     byte                      // 10, 42
	Brick43         [8][64]byte               // 10, 43
	SoundOpen555    [64]byte                  // 138, 555
	SoundClose619   [64]byte                  // 154, 619
	Sound683        [64]byte                  // 170, 683
	Field747        byte                      // 186, 747
	Field748        byte                      // 187, 748
	Field749        byte                      // 187, 749
	Field750        byte                      // 187, 750
	Field751        byte                      // 187, 751
	DrawOffs752     [4][15][16]image.Point    // 188, 752
	Sprite8432      [4][15][16]unsafe.Pointer // 2108, 8432, TODO: noxrender.ImageHandle
	Variations12272 [4][15]byte               // 3068, 12272
}

func (w *WallDef) Name() string {
	return alloc.GoStringS(w.Field0[:])
}

func (w *WallDef) BrickObject(i int) string {
	name := "Brick0"
	if s := alloc.GoStringS(w.Brick43[i][:]); s != "" {
		name = s
	}
	return name
}

func (w *WallDef) BreakSound() string {
	name := "WallDestroyed"
	if s := alloc.GoStringS(w.Sound683[:]); s != "" {
		name = s
	}
	return name
}

func (w *WallDef) OpenSound() string {
	name := "SecretWallOpen"
	if s := alloc.GoStringS(w.SoundOpen555[:]); s != "" {
		name = s
	}
	return name
}

func (w *WallDef) CloseSound() string {
	name := "SecretWallClose"
	if s := alloc.GoStringS(w.SoundClose619[:]); s != "" {
		name = s
	}
	return name
}

func (w *WallDef) Variations(a2 int, a3 int) byte {
	return w.Variations12272[a3][a2]
}

func (w *WallDef) Sprite(a2 int, a3 int, a4 int) unsafe.Pointer {
	return w.Sprite8432[a4][a2][a3]
}

func (w *WallDef) DrawOffset(a2 int, a3 int, a4 int) image.Point {
	return w.DrawOffs752[a4][a2][a3]
}

type WallFlags byte

func (f WallFlags) Has(f2 WallFlags) bool {
	return f&f2 != 0
}

func (f WallFlags) HasAny(f2 WallFlags) bool {
	return f&f2 != 0
}

const (
	WallFlag1     = WallFlags(0x1)
	WallFlagFront = WallFlags(0x2)
	WallFlag3     = WallFlags(0x4)
	WallFlag4     = WallFlags(0x8)
	WallFlag5     = WallFlags(0x10)
	WallFlag6     = WallFlags(0x20)
	WallFlag7     = WallFlags(0x40)
)

type Wall struct {
	Dir0        byte           // 0, 0
	Tile1       byte           // 0, 1
	Field2      byte           // 0, 2
	Field3      byte           // 0, 3
	Flags4      WallFlags      // 1, 4
	X5          byte           // 1, 5
	Y6          byte           // 1, 6
	Health7     byte           // 1, 7
	Field8      uint32         // 2, 8
	Field12     uint32         // 3, 12
	NextByPos16 *Wall          // 4, 16
	Next20      *Wall          // 5, 20
	NextByY24   *Wall          // 6, 24
	Data28      unsafe.Pointer // 7, 28, TODO: *Object ?
	Field32     uint32         // 8, 32
}

func (w *Wall) C() unsafe.Pointer {
	return unsafe.Pointer(w)
}

func (w *Wall) String() string {
	if w == nil {
		return "Wall(nil)"
	}
	pos := w.GridPos()
	return fmt.Sprintf("Wall(%d, %d)", pos.X, pos.Y)
}

func (w *Wall) WallScriptID() int {
	p := w.GridPos()
	return (p.X << 16) | p.Y
}

func (w *Wall) GridPos() image.Point {
	x := int(w.X5)
	y := int(w.Y6)
	return image.Point{
		X: x,
		Y: y,
	}
}

func (w *Wall) ScriptID() int {
	p := w.GridPos()
	return (p.X << 16) | p.Y
}

func (w *Wall) Pos() types.Pointf {
	p := w.GridPos()
	return wall.GridToPos(p)
}

// IsEnabled checks if the wall is closed.
func (w *Wall) IsEnabled() bool {
	if w == nil {
		return false
	}
	v3 := *(*byte)(unsafe.Add(w.Data28, 21))
	return v3 == 1 || v3 == 2
}

func (s *serverDoors) SetKeyHolder(v *Object) {
	if v != nil {
		s.keyHolder = v
		s.keyHolderSet = true
	} else {
		s.keyHolderSet = false
	}
}

func (s *Server) Sub_57B500(pos image.Point, flags byte) int8 {
	if pos.X < 0 || pos.X >= WallGridSize || pos.Y < 0 || pos.Y >= WallGridSize {
		return -1
	}
	wl := s.Walls.GetWallAtGrid2(pos)
	if wl == nil {
		return -1
	}
	if !wl.Flags4.Has(WallFlag5) {
		if flags&0x40 == 0 && wl.Flags4.Has(WallFlag7) || wl.Flags4.Has(WallFlag3) && int32(*(*uint8)(unsafe.Add(wl.Data28, 22))) > 11 {
			return -1
		}
		return int8(wl.Dir0)
	}
	if flags&0x10 == 0 {
		return -1
	}
	obj := asObjectP(wl.Data28)
	if obj == nil {
		return -1
	}
	ud := obj.UpdateData // TODO: which one? door?
	if flags&0x8 != 0 {
		if *(*uint8)(unsafe.Add(ud, 1)) == 0 {
			return -1
		}
		if s.Doors.keyHolderSet && s.DoorCheckKey(s.Doors.keyHolder, obj) {
			s.Doors.keyHolderSet = false
			return -1
		}
	}
	if int32(int8(flags)) >= 0 && obj.SubClass().Has(0x4) {
		return -1
	}
	ang := *(*uint32)(unsafe.Add(ud, 12))
	if ang != *(*uint32)(unsafe.Add(ud, 4)) {
		return -1
	}
	dp := doorWallTable[ang]
	if dp.X > 0 && dp.Y > 0 {
		return 1
	} else if dp.X < 0 && dp.Y < 0 {
		return 1
	} else if dp.X < 0 && dp.Y > 0 {
		return 0
	} else if dp.X > 0 && dp.Y < 0 {
		return 0
	}
	return -1
}

var doorWallTable = []image.Point{
	{X: -23, Y: -23}, {X: -18, Y: -27}, {X: -12, Y: -30}, {X: -6, Y: -31},
	{X: 0, Y: -32}, {X: 6, Y: -31}, {X: 12, Y: -30}, {X: 18, Y: -27},
	{X: 23, Y: -23}, {X: 27, Y: -18}, {X: 30, Y: -12}, {X: 31, Y: -6},
	{X: 32, Y: 0}, {X: 31, Y: 6}, {X: 30, Y: 12}, {X: 27, Y: 18},
	{X: 23, Y: 23}, {X: 18, Y: 27}, {X: 12, Y: 30}, {X: 6, Y: 31},
	{X: 0, Y: 32}, {X: -6, Y: 31}, {X: -12, Y: 30}, {X: -18, Y: 27},
	{X: -23, Y: 23}, {X: -27, Y: 18}, {X: -30, Y: 12}, {X: -31, Y: 6},
	{X: -32, Y: 0}, {X: -31, Y: -6}, {X: -30, Y: -12}, {X: -27, Y: -18},
}

func (s *Server) MapTraceRay9(p1, p2 types.Pointf) bool { // nox_xxx_traceRay_5374B0
	return s.MapTraceRay(p1, p2, MapTraceFlag1|MapTraceFlag4)
}

func (s *Server) MapTraceRay(p1, p2 types.Pointf, flags MapTraceFlags) bool {
	return s.MapTraceRayAt(p1, p2, nil, nil, flags)
}

func (s *Server) MapTraceRayAt(p1, p2 types.Pointf, outPos *types.Pointf, outGrid *image.Point, flags MapTraceFlags) bool {
	wx1 := int(p1.X / common.GridStep)
	wy1 := int(p1.Y / common.GridStep)
	if wx1 < 0 || wx1 >= 256 || wy1 < 0 || wy1 >= 256 {
		return false
	}
	wx2 := int(p2.X / common.GridStep)
	wy2 := int(p2.Y / common.GridStep)
	if wx1 == wx2 {
		step := +1
		if p2.Y < p1.Y {
			step = -1
		}
		if wy1 == wy2+step {
			return true
		}
		for yi := wy1; yi != wy2+step; yi += step {
			pi := image.Pt(wx1, yi)
			if a4a := s.mapTraceRayImpl(pi, p1, p2, flags); len(a4a) != 0 {
				if outPos != nil {
					*outPos = a4a[0]
				}
				if outGrid != nil {
					*outGrid = pi
				}
				return false
			}
		}
		return true
	}
	if wy1 == wy2 {
		step := +1
		if p2.X < p1.X {
			step = -1
		}
		if wx1 == wx2+step {
			return true
		}
		for xi := wx1; xi != wx2+step; xi += step {
			pi := image.Pt(xi, wy1)
			if a4a := s.mapTraceRayImpl(pi, p1, p2, flags); len(a4a) != 0 {
				if outPos != nil {
					*outPos = a4a[0]
				}
				if outGrid != nil {
					*outGrid = pi
				}
				return false
			}
		}
		return true
	}
	dx := p2.X - p1.X
	dy := p2.Y - p1.Y
	if math.Abs(float64(dy)) >= math.Abs(float64(dx)) {
		x1 := p1.X
		x2 := p2.X
		mulX := float32(+1.0)
		if x1 >= x2 {
			x1, x2 = x2, x1
			mulX = -1.0
		}
		stepY := +1.0
		if p1.Y >= p2.Y {
			stepY = -1.0
		}
		slope := dy / dx
		var xnext float32
		for x := p1.X; mulX*x <= mulX*p2.X; x = xnext + 0.1*mulX {
			xi := int(math.Trunc(float64(x / common.GridStep)))
			xmin := float32(xi+0) * common.GridStep
			xmax := float32(xi+1) * common.GridStep
			if mulX <= 0 {
				xmax, xmin = xmin, xmax
			}
			xnext = xmax
			y1 := p1.Y + (xmin-p1.X)*slope
			if (stepY > 0 && y1 < p1.Y) || (stepY < 0 && y1 > p1.Y) {
				y1 = p1.Y
			}
			y2 := p1.Y + (xmax-p1.X)*slope
			if (stepY > 0 && y2 > p2.Y) || (stepY < 0 && y2 < p2.Y) {
				y2 = p2.Y
			}
			yi1 := int(math.Trunc(float64(y1/common.GridStep)) - stepY)
			yi2 := int(math.Trunc(float64(y2/common.GridStep)) + stepY)
			ddy := 1
			if yi1 >= yi2 {
				ddy = -1
			}
			for yi := yi1; yi != yi2+ddy; yi += ddy {
				pi := image.Pt(xi, yi)
				if a4a := s.mapTraceRayImpl(pi, p1, p2, flags); len(a4a) != 0 {
					if outPos != nil {
						*outPos = a4a[0]
					}
					if outGrid != nil {
						*outGrid = pi
					}
					return false
				}
			}
		}
		return true
	} else {
		y1 := p1.Y
		y2 := p2.Y
		mulY := float32(+1.0)
		if p1.Y >= p2.Y {
			y1, y2 = y2, y1
			mulY = -1.0
		}
		stepX := +1.0
		if p1.X >= p2.X {
			stepX = -1.0
		}
		slope := dx / dy
		var ynext float32
		for y := p1.Y; mulY*y <= mulY*p2.Y; y = ynext + 0.1*mulY {
			yi := int(math.Trunc(float64(y / common.GridStep)))
			ymin := float32(yi+0) * common.GridStep
			ymax := float32(yi+1) * common.GridStep
			if mulY <= 0 {
				ymin, ymax = ymax, ymin
			}
			ynext = ymax
			x1 := p1.X + (ymin-p1.Y)*slope
			if (stepX > 0 && x1 < p1.X) || (stepX < 0 && x1 > p1.X) {
				x1 = p1.X
			}
			x2 := p1.X + (ymax-p1.Y)*slope
			if (stepX > 0 && x2 > p2.X) || (stepX < 0 && x2 < p2.X) {
				x2 = p2.X
			}
			xi1 := int(math.Trunc(float64(x1/common.GridStep)) - stepX)
			xi2 := int(math.Trunc(float64(x2/common.GridStep)) + stepX)
			ddy := 1
			if xi1 >= xi2 {
				ddy = -1
			}
			for xi := xi1; xi != xi2+ddy; xi += ddy {
				pi := image.Pt(xi, yi)
				if out := s.mapTraceRayImpl(pi, p1, p2, flags); len(out) != 0 {
					if outPos != nil {
						*outPos = out[0]
					}
					if outGrid != nil {
						*outGrid = pi
					}
					return false
				}
			}
		}
		return true
	}
}

func (s *Server) mapTraceRayImpl(pi image.Point, p1, p2 types.Pointf, flags MapTraceFlags) []types.Pointf {
	if pi.X < 0 || pi.X >= WallGridSize || pi.Y < 0 || pi.Y >= WallGridSize {
		return nil
	}
	if flags.Has(MapTraceFlag4) {
		v7 := float32(pi.X)*common.GridStep + 11.5 - p1.X
		v8 := float32(pi.Y)*common.GridStep + 11.5 - p1.Y
		if v8*v8+v7*v7 < 3600.0 {
			flags |= MapTraceFlag3
		}
	}
	v30 := byte(^flags&MapTraceFlag3) << 4
	if flags.Has(MapTraceFlag1) {
		v30 |= 0x10
	}
	tflag := s.Sub_57B500(pi, v30)
	if tflag == -1 {
		return nil
	}
	var wl *Wall
	if flags.Has(MapTraceFlag1) {
		wl = s.Walls.GetWallAtGrid2(pi)
	} else {
		wl = s.Walls.GetWallAtGrid(pi)
	}
	if wl == nil || flags.Has(MapTraceFlag8) && wl.Flags4.Has(WallFlag3) && *(*byte)(unsafe.Add(wl.Data28, 20))&0x2 != 0 {
		return nil
	}
	flags2 := s.Walls.DefByInd(int(wl.Tile1)).Flags32
	if flags2&0x2 != 0 || flags.Has(MapTraceFlag7) && flags2&0x1 == 0 {
		return nil
	}
	x1 := p1.X
	x2 := p2.X
	if p1.X >= p2.X {
		x1, x2 = x2, x1
	}
	y1 := p1.Y
	y2 := p2.Y
	if p1.Y >= p2.Y {
		y1, y2 = y2, y1
	}
	a2a := types.Pointf{
		X: float32(common.GridStep * pi.X),
		Y: float32(common.GridStep * pi.Y),
	}
	var left types.Pointf
	if tflag != 0 {
		left = sub_57CD30(p1, p2, a2a)
	}
	var right types.Pointf
	if tflag != 1 {
		right = sub_57CD70(p1, p2, a2a.Add(types.Pointf{X: common.GridStep}))
	}
	var out []types.Pointf
	if t := noxMapTable313272[2*int(tflag)+0]; t.Field0 != 0 &&
		a2a.X+t.Field4 <= left.X &&
		a2a.X+t.Field8 >= left.X &&
		left.X >= x1 && left.X <= x2 &&
		left.Y >= y1 && left.Y <= y2 {
		out = append(out, left)
	}
	if t := noxMapTable313272[2*int(tflag)+1]; t.Field0 != 0 &&
		a2a.X+t.Field4 <= right.X &&
		a2a.X+t.Field8 >= right.X &&
		right.X >= x1 && right.X <= x2 &&
		right.Y >= y1 && right.Y <= y2 {
		out = append(out, right)
	}
	if len(out) == 2 {
		dxl := p1.X - left.X
		dxr := p1.X - right.X
		dyl := p1.Y - left.Y
		dyr := p1.Y - right.Y
		if dyr*dyr+dxr*dxr < dyl*dyl+dxl*dxl {
			out[0], out[1] = out[1], out[0]
		}
	}
	return out
}

var noxMapTable313272 = []struct {
	Field0 byte
	Field4 float32
	Field8 float32
}{
	{Field0: 0, Field4: 0, Field8: 0},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 0, Field4: 0, Field8: 0},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 11.5, Field8: 23},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 11.5},
	{Field0: 1, Field4: 0, Field8: 11.5},
}

func sub_57CD30(p1, p2, c types.Pointf) types.Pointf {
	dx := p2.X - p1.X
	dy := p2.Y - p1.Y
	v := ((c.Y-p1.Y)*dx - (c.X-p1.X)*dy) / (dy - dx)
	return c.Add(types.Pointf{X: v, Y: v})
}

func sub_57CD70(p1, p2, a2 types.Pointf) types.Pointf {
	dx := p2.X - p1.X
	dy := p2.Y - p1.Y
	v := ((a2.Y-p1.Y)*dx - (a2.X-p1.X)*dy) / (-dy - dx)
	return a2.Add(types.Pointf{X: -v, Y: v})
}
