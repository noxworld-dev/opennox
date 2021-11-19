package bag

import (
	"bufio"
	"bytes"
	"encoding/binary"
	"fmt"
	"io"
	"path"
	"strings"

	"nox/v1/common/fs"
	"nox/v1/common/noximage/pcx"
	"nox/v1/common/nxz"
)

var endiness = binary.LittleEndian

type File struct {
	idx io.ReadSeeker
	bag io.ReadSeeker
	br  *bufio.Reader
	c   []io.Closer

	is8bit  bool
	hasComp bool
	size    uint32
	psz1    uint32
	hdr2    uint32
	segCnt  uint32
	cnt2    uint32

	segm []*Segment
	imgs []*ImageRec
}

func OpenWithIndex(path, ipath string) (*File, error) {
	if ipath == "" {
		ipath = strings.TrimSuffix(path, ".bag") + ".idx"
	}
	idx, err := fs.Open(ipath)
	if err != nil {
		return nil, err
	}
	bg := &File{idx: idx, c: []io.Closer{idx}}
	if err := bg.readHeader(); err != nil {
		_ = idx.Close()
		return nil, err
	}
	bag, err := fs.Open(path)
	if err != nil {
		bg.Close()
		return nil, err
	}
	bg.bag = bag
	bg.c = append(bg.c, bag)
	bg.br = bufio.NewReader(bg.idx)
	return bg, nil
}

func Open(path string) (*File, error) {
	return OpenWithIndex(path, "")
}

func (f *File) Close() error {
	for _, c := range f.c {
		_ = c.Close()
	}
	f.c = nil
	return nil
}

type Segment struct {
	f         *File
	data      []byte
	Index     int         `json:"ind"`
	BagOffset int         `json:"bag_offset"`
	Size      int         `json:"size"`
	SizeComp  int         `json:"size_compressed"`
	ImagesInd int         `json:"images_ind"`
	ImagesCnt int         `json:"images_cnt"`
	Images    []*ImageRec `json:"images,omitempty"`
}

type ImageRec struct {
	s       *Segment
	SegmInd uint16 `json:"segment_ind"`
	Offset  uint32 `json:"segment_offset"`
	Index   int    `json:"image_index"`
	Name    string `json:"name"`
	Size    uint32 `json:"size"`
	Field1  uint32
	Type    uint16 `json:"type"`
}

func (f *File) readHeader() error {
	var b [24]byte
	_, err := io.ReadFull(f.idx, b[:])
	if err != nil {
		return err
	}
	magic := endiness.Uint32(b[0:])
	switch magic {
	default:
		return fmt.Errorf("invalid magic: %x", magic)
	case 0xFAEDBCEB:
		f.hasComp = true
	case 0xFAEDBCEA:
		f.hasComp = false
	}
	f.size = endiness.Uint32(b[4:])
	f.segCnt = endiness.Uint32(b[8:])
	f.psz1 = endiness.Uint32(b[12:])
	f.hdr2 = endiness.Uint32(b[16:])
	f.cnt2 = endiness.Uint32(b[20:])
	return nil
}

func (f *File) skip(n int) error {
	_, err := f.br.Discard(n)
	return err
}

func (f *File) read(p []byte) error {
	_, err := io.ReadFull(f.br, p)
	return err
}

func (f *File) readU8() (byte, error) {
	b, err := f.br.ReadByte()
	if err == io.EOF {
		return 0, io.ErrUnexpectedEOF
	} else if err != nil {
		return 0, err
	}
	return b, nil
}

func (f *File) readU32() (uint32, error) {
	var b [4]byte
	if err := f.read(b[:]); err != nil {
		return 0, err
	}
	return endiness.Uint32(b[:]), nil
}

func (f *File) readI32() (int32, error) {
	v, err := f.readU32()
	if err != nil {
		return 0, err
	}
	return int32(v), nil
}

func (f *File) readString8() (string, error) {
	n, err := f.readU8()
	if err != nil {
		return "", err
	}
	b := make([]byte, n)
	if err = f.read(b); err != nil {
		return "", err
	}
	return string(bytes.TrimRight(b, "\x00")), nil
}

func (f *File) ReadAll() error {
	return f.ensureImages()
}

func (f *File) Segments() ([]*Segment, error) {
	if f.segm == nil {
		if err := f.readAll(); err != nil {
			return nil, err
		}
	}
	return f.segm, nil
}

func (f *File) ensureImages() error {
	if f.imgs != nil {
		return nil
	}
	return f.readAll()
}

func (f *File) Images() ([]*ImageRec, error) {
	if err := f.ensureImages(); err != nil {
		return nil, err
	}
	return f.imgs, nil
}

func normalizeImageName(name string) string {
	name = strings.ToLower(name)
	if ext := path.Ext(name); ext != "" {
		name = strings.TrimSuffix(name, ext)
	}
	return name
}

func (f *File) ImageByName(name string) (*ImageRec, error) {
	if err := f.ensureImages(); err != nil {
		return nil, err
	}
	name = normalizeImageName(name)
	for _, img := range f.imgs {
		if normalizeImageName(img.Name) == name {
			return img, nil
		}
	}
	return nil, nil
}

func (f *File) readAll() error {
	offs := uint32(0)
	imgInd := uint32(0)
	for i := 0; i < int(f.segCnt); i++ {
		if err := f.skip(4); err != nil {
			return err
		}
		size, err := f.readU32()
		if err != nil {
			return err
		}
		sizeComp := size
		if f.hasComp {
			sizeComp, err = f.readU32()
			if err != nil {
				return err
			}
		}
		cnt, err := f.readI32()
		if err != nil {
			return err
		}
		seg := &Segment{
			f:         f,
			Index:     i,
			BagOffset: int(offs),
			Size:      int(size),
			SizeComp:  int(sizeComp),
			ImagesInd: int(imgInd),
			ImagesCnt: int(cnt),
		}
		f.segm = append(f.segm, seg)
		offs += sizeComp
		if cnt == -1 {
			cnt = 1
		}
		if cnt > 0 {
			soff := uint32(0)
			for j := 0; j < int(cnt); j++ {
				img := &ImageRec{
					s:       seg,
					SegmInd: uint16(i),
				}
				f.imgs = append(f.imgs, img)

				name, err := f.readString8()
				if err != nil {
					return err
				}
				img.Name = name
				typ, err := f.readU8()
				if err != nil {
					return err
				}
				img.Type = uint16(typ)
				len16, err := f.readU32()
				if err != nil {
					return err
				}
				len8, err := f.readU32()
				if err != nil {
					return err
				}
				leng := len16
				if f.is8bit {
					leng = len8
				}
				img.Index = int(imgInd)
				img.Offset = soff
				img.Size = leng
				soff += leng
				seg.Images = append(seg.Images, img)
				imgInd++
			}
		}
	}
	return nil
}

func (seg *Segment) open() (io.Reader, error) {
	if seg.data != nil {
		return bytes.NewReader(seg.data), nil
	}
	f := seg.f
	_, err := f.bag.Seek(int64(seg.BagOffset), io.SeekStart)
	if err != nil {
		return nil, err
	}
	var segr io.Reader = io.LimitReader(f.bag, int64(seg.SizeComp))
	if seg.Size != seg.SizeComp {
		// compressed
		segr = nxz.NewReader(segr)
	}
	data := make([]byte, seg.Size)
	_, err = io.ReadFull(segr, data)
	if err != nil {
		return nil, err
	}
	seg.data = data
	return bytes.NewReader(data), nil
}

func (img *ImageRec) open() (io.Reader, error) {
	r, err := img.s.open()
	if err != nil {
		return nil, err
	}
	if img.Offset > 0 {
		_, err := io.CopyN(io.Discard, r, int64(img.Offset))
		if err != nil {
			return nil, err
		}
	}
	return io.LimitReader(r, int64(img.Size)), nil
}

func (img *ImageRec) Raw() ([]byte, error) {
	r, err := img.open()
	if err != nil {
		return nil, err
	}
	buf := make([]byte, img.Size)
	_, err = io.ReadFull(r, buf)
	return buf, err
}

func (img *ImageRec) Decode() (*pcx.Image, error) {
	r, err := img.open()
	if err != nil {
		return nil, err
	}
	return pcx.Decode(r, byte(img.Type))
}

func (img *ImageRec) DecodeHeader() (*pcx.ImageMeta, error) {
	r, err := img.open()
	if err != nil {
		return nil, err
	}
	return pcx.DecodeHeader(r, byte(img.Type))
}
