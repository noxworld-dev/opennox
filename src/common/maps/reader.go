package maps

import (
	"bytes"
	"encoding/binary"
	"errors"
	"fmt"
	"io"

	"nox/v1/common/crypt"
)

type Reader struct {
	cr       *crypt.Reader
	r        io.Reader
	err      error
	limited  bool
	crc      uint32
	wallOffX uint32
	wallOffY uint32
	info     *Info
	walls    *wallMap
	floor    *floorMap
}

func NewReader(r io.Reader) (*Reader, error) {
	cr, err := crypt.NewReader(r, crypt.MapKey)
	if err != nil {
		return nil, err
	}
	rd := &Reader{cr: cr, r: cr}
	if err := rd.readHeader(); err != nil {
		return nil, err
	}
	return rd, nil
}

func (r *Reader) Info() *Info {
	return r.info
}

func (r *Reader) error() error {
	return r.err
}

// readBytes reads bytes to completely fill the buffer.
// Read error must be checked with error method.
func (r *Reader) readBytes(p []byte) {
	if r.error() != nil {
		return
	}
	_, err := io.ReadFull(r.r, p)
	if err != nil {
		r.err = err
	}
}

// readAlignedBytes reads bytes to completely fill the buffer. Read operation will be aligned with the crypt block size.
// Read error must be checked with error method.
func (r *Reader) readAlignedBytes(p []byte) {
	if r.error() != nil {
		return
	}
	if r.limited {
		r.err = errors.New("trying to align a limited reader")
		return
	}
	n, err := r.cr.ReadAligned(p)
	if err != nil {
		r.err = err
		return
	} else if n != len(p) {
		r.err = io.ErrUnexpectedEOF
		return
	}
}

func (r *Reader) readU8() byte {
	var b [1]byte
	r.readBytes(b[:])
	return b[0]
}

func (r *Reader) readU16() uint16 {
	var b [2]byte
	r.readBytes(b[:])
	return binary.LittleEndian.Uint16(b[:])
}

func (r *Reader) readU32() uint32 {
	var b [4]byte
	r.readBytes(b[:])
	return binary.LittleEndian.Uint32(b[:])
}

func (r *Reader) readU64() uint64 {
	var b [8]byte
	r.readBytes(b[:])
	return binary.LittleEndian.Uint64(b[:])
}

func (r *Reader) readI32() int32 {
	return int32(r.readU32())
}

func (r *Reader) readAlignedU32() uint32 {
	var b [4]byte
	r.readAlignedBytes(b[:])
	return binary.LittleEndian.Uint32(b[:])
}

func (r *Reader) readStringFixed(max int) string {
	b := make([]byte, max)
	r.readBytes(b)
	if r.error() != nil {
		return ""
	}
	i := bytes.IndexByte(b, 0)
	if i >= 0 {
		b = b[:i]
	}
	return string(b)
}

func (r *Reader) readString8() string {
	n := r.readU8()
	if r.error() != nil {
		return ""
	}
	return r.readStringFixed(int(n))
}

func (r *Reader) readAlignedString8() string {
	if r.error() != nil {
		return ""
	}
	if r.limited {
		r.err = errors.New("trying to align a limited reader")
		return ""
	}
	s := r.readString8()
	if r.error() != nil {
		return ""
	}
	if err := r.cr.Align(); err != nil {
		r.err = err
	}
	return s
}

func (r *Reader) readHeader() error {
	magic := r.readU32()
	if err := r.error(); err != nil {
		return fmt.Errorf("cannot read magic: %w", err)
	}
	switch magic {
	case 0xFADEBEEF:
		// nop
	case 0xFADEFACE:
		r.crc = r.readAlignedU32()
		if err := r.error(); err != nil {
			return fmt.Errorf("cannot read crc: %w", err)
		}
	default:
		return fmt.Errorf("unsupported magic: 0x%x", magic)
	}
	r.wallOffX = r.readU32()
	r.wallOffY = r.readU32()
	if err := r.error(); err != nil {
		return fmt.Errorf("cannot read wall offset: %w", err)
	}
	return nil
}

func (r *Reader) ReadInfo() (*Info, error) {
	sect, err := r.nextSection()
	if err != nil {
		return nil, err
	} else if sect != "MapInfo" {
		return nil, fmt.Errorf("unexpected section: %q", sect)
	}
	err = r.readMapInfo()
	return r.info, err
}

func (r *Reader) nextSection() (string, error) {
	if r.limited {
		if _, err := io.Copy(io.Discard, r.r); err != nil {
			return "", err
		}
		r.limited = false
		r.err = nil
		r.r = r.cr
	}
	sect := r.readAlignedString8()
	if err := r.error(); err != nil {
		return "", err
	}
	size := r.readU64()
	if err := r.error(); err != nil {
		return sect, err
	}
	r.r = io.LimitReader(r.cr, int64(size))
	r.limited = true
	return sect, nil
}

func (r *Reader) ReadSections() error {
	for {
		sect, err := r.nextSection()
		if err != nil {
			return err
		}
		switch sect {
		case "MapInfo":
			err = r.readMapInfo()
		case "WallMap":
			err = r.readWallMap()
		case "FloorMap":
			err = r.readFloorMap()
		//case "SecretWalls":
		//	err = r.readSecretWalls()
		default:
			return fmt.Errorf("unhandled section: %q", sect)
		}
		if err != nil {
			return err
		}
	}
}

func (r *Reader) readMapInfo() error {
	vers := r.readU16()
	if err := r.error(); err != nil {
		return fmt.Errorf("cannot read info version: %w", err)
	}
	r.info = &Info{Format: int(vers)}
	if vers > 3 {
		return fmt.Errorf("unsupported version: %d", vers)
	}
	if vers >= 1 {
		for _, f := range []struct {
			p   *string
			max int
		}{
			{&r.info.Summary, 64},
			{&r.info.Description, 512},
			{&r.info.Version, 16},
			{&r.info.Author, 64},
			{&r.info.Email, 192},
			{&r.info.Author2, 64},
			{&r.info.Email2, 192},
			{&r.info.Field7, 128},
			{&r.info.Copyright, 128},
			{&r.info.Date, 32},
		} {
			s := r.readStringFixed(f.max)
			if err := r.error(); err != nil {
				return err
			}
			*f.p = s
		}
		r.info.Flags = r.readU32()
		if err := r.error(); err != nil {
			return fmt.Errorf("cannot read info: %w", err)
		}
		if vers == 2 {
			r.info.MinPlayers = r.readU8()
			r.info.MaxPlayers = r.readU8()
			if err := r.error(); err != nil {
				return fmt.Errorf("cannot read info: %w", err)
			}
		} else {
			r.info.MinPlayers = 2
			r.info.MaxPlayers = 16
		}
	}
	if vers < 3 {
		return nil
	}
	r.info.QuestIntro = r.readString8()
	r.info.QuestGraphics = r.readString8()
	if err := r.error(); err != nil {
		return err
	}
	return nil
}

type gridData struct {
	prefix uint16
	var1   uint32
	var2   uint32
	var3   uint32
	var4   uint32
}

type WallPos struct {
	X, Y byte
}

type wallMap struct {
	grid gridData
	loc  map[WallPos]*Wall
	list []*Wall
}

type Wall struct {
	Pos      WallPos
	Dir      byte
	Material byte
	Variant  byte
	Minimap  byte
	Modified byte
}

func (r *Reader) readMapGrid() (*gridData, error) {
	grid := new(gridData)
	grid.prefix = r.readU16()
	grid.var1 = r.readU32()
	grid.var2 = r.readU32()
	grid.var3 = r.readU32()
	grid.var4 = r.readU32()
	if err := r.error(); err != nil {
		return nil, err
	}
	return grid, nil
}

func (r *Reader) readWallMap() error {
	grid, err := r.readMapGrid()
	if err != nil {
		return err
	}
	r.walls = &wallMap{
		grid: *grid,
		loc:  make(map[WallPos]*Wall),
	}
	for {
		w, err := r.readWall()
		if err != nil {
			return err
		} else if w == nil {
			break
		}
		r.walls.list = append(r.walls.list, w)
		r.walls.loc[w.Pos] = w
	}
	return nil
}

func (r *Reader) readWall() (*Wall, error) {
	x := r.readU8()
	if err := r.error(); err != nil {
		return nil, err
	} else if x == 0xff {
		return nil, nil
	}
	y := r.readU8()
	if err := r.error(); err != nil {
		return nil, err
	} else if y == 0xff {
		return nil, nil
	}
	w := &Wall{Pos: WallPos{X: x, Y: y}}
	w.Dir = r.readU8()
	//w.Dir &= 0x7f // TODO: check in the engine
	w.Material = r.readU8()
	w.Variant = r.readU8()
	w.Minimap = r.readU8()
	w.Modified = r.readU8()
	if err := r.error(); err != nil {
		return nil, err
	}
	return w, nil
}

type FloorPos struct {
	X, Y uint16
}

type floorMap struct {
	grid gridData
}

func (r *Reader) readFloorMap() error {
	grid, err := r.readMapGrid()
	if err != nil {
		return err
	} else if grid.prefix <= 3 {
		return fmt.Errorf("unsupported floor map: 0x%x", grid.prefix)
	}
	r.floor = &floorMap{
		grid: *grid,
	}
	for {
		tl, tr, err := r.readTilePair()
		if err != nil {
			return err
		} else if tl == nil && tr == nil {
			break
		}
	}
	return nil
}

type Edge struct {
	Image   byte
	Variant uint16
	Edge    byte
	Dir     byte
}

func (r *Reader) readEdge() (*Edge, error) {
	e := new(Edge)
	e.Image = r.readU8()
	e.Variant = r.readU16()
	e.Edge = r.readU8()
	e.Dir = r.readU8()
	if err := r.error(); err != nil {
		return nil, err
	}
	return e, nil
}

type Tile struct {
	Pos     FloorPos
	Image   byte
	Variant uint16
	Field4  uint16
	Edges   []*Edge
}

func (r *Reader) readTile() (*Tile, error) {
	t := new(Tile)
	t.Image = r.readU8()
	t.Variant = r.readU16()
	// TODO: check in the engine what this is
	t.Field4 = r.readU16()
	n := r.readU8()
	if err := r.error(); err != nil {
		return nil, err
	}
	t.Edges = make([]*Edge, 0, n)
	for i := 0; i < int(n); i++ {
		e, err := r.readEdge()
		if err != nil {
			return nil, err
		}
		t.Edges = append(t.Edges, e)
	}
	return t, nil
}

func (r *Reader) readTilePair() (tl, tr *Tile, _ error) {
	x := r.readU8()
	if err := r.error(); err != nil {
		return nil, nil, err
	} else if x == 0xff {
		return nil, nil, nil
	}
	y := r.readU8()
	if err := r.error(); err != nil {
		return nil, nil, err
	} else if y == 0xff {
		return nil, nil, nil
	}
	hasR := x&0x80 != 0
	hasL := y&0x80 != 0
	x &= 0x7c
	y &= 0x7c
	if hasR {
		var err error
		tr, err = r.readTile()
		if err != nil {
			return nil, nil, err
		}
		tr.Pos = FloorPos{X: 2*uint16(x) + 1, Y: 2*uint16(y) - 1}
	}
	if hasL {
		var err error
		tl, err = r.readTile()
		if err != nil {
			return nil, nil, err
		}
		tl.Pos = FloorPos{X: 2 * uint16(x), Y: 2 * uint16(y)}
	}
	if !hasL && !hasR {
		return nil, nil, errors.New("invalid tile pair flags")
	}
	return tl, tr, nil
}

//type SecretWall struct {
//
//}
//
//func (r *Reader) readSecretWalls() error {
//
//}
