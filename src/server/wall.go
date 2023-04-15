package server

import (
	"fmt"
	"image"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"
	"github.com/noxworld-dev/opennox-lib/wall"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const WallGridSize = 256

type serverWalls struct {
	head     *Wall
	freeList *Wall
	byPos    []*Wall // index is wallArrayInd
	indexY   []*Wall
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
		if pos == it.GridPos() && it.Flags4&0x30 == 0 {
			return it
		}
	}
	return nil
}

func (s *serverWalls) GetWallAtGrid2(pos image.Point) *Wall {
	ind := wallArrayInd(pos)
	for it := s.byPos[ind]; it != nil; it = it.NextByPos16 {
		if pos == it.GridPos() && it.Flags4&0x20 == 0 {
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
		if it.Flags4&0x30 == 0 {
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

type Wall struct {
	Dir0        byte           // 0, 0
	Tile1       byte           // 0, 1
	Field2      byte           // 0, 2
	Field3      byte           // 0, 3
	Flags4      byte           // 1, 4
	X5          byte           // 1, 5
	Y6          byte           // 1, 6
	Health7     byte           // 1, 7
	Field8      uint32         // 2, 8
	Field12     uint32         // 3, 12
	NextByPos16 *Wall          // 4, 16
	Next20      *Wall          // 5, 20
	NextByY24   *Wall          // 6, 24
	Data28      unsafe.Pointer // 7, 28
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
