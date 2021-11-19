package bag

import (
	"bufio"
	"bytes"
	"fmt"
	"image"
	"image/draw"
	"io"
	"os"
	"path/filepath"
	"strings"

	"nox/v1/common/noximage/pcx"
	"nox/v1/common/nxz"
)

// Decompress video.bag file and update video.idx.
func Decompress(path, ipath string) error {
	rb, err := newReplacer(path, ipath)
	if err != nil {
		return err
	}
	defer rb.Close()
	if err = rb.Decompress(); err != nil {
		return err
	}
	return rb.Replace()
}

type Replacement struct {
	ImageInd int
	Image    image.Image
	Point    *image.Point
}

func asRGBA(img image.Image) *image.RGBA {
	if rgba, ok := img.(*image.RGBA); ok {
		return rgba
	}
	rgba := image.NewRGBA(img.Bounds())
	draw.Draw(rgba, rgba.Rect, img, img.Bounds().Min, draw.Src)
	return rgba
}

// ReplaceSprites changes one or more sprites in the video.bag and video.idx.
func ReplaceSprites(path, ipath string, list []Replacement) error {
	rb, err := newReplacer(path, ipath)
	if err != nil {
		return err
	}
	defer rb.Close()
	if err = rb.ReplaceSprites(list); err != nil {
		return err
	}
	return rb.Replace()
}

type replacer struct {
	bag *os.File
	idx *os.File

	nbag *os.File
	nidx *os.File
}

func newReplacer(path, ipath string) (*replacer, error) {
	if ipath == "" {
		ipath = strings.TrimSuffix(path, ".bag") + ".idx"
	}
	var err error
	rb := new(replacer)

	// open input files
	rb.bag, err = os.Open(path)
	if err != nil {
		_ = rb.Close()
		return nil, err
	}
	rb.idx, err = os.Open(ipath)
	if err != nil {
		_ = rb.Close()
		return nil, err
	}

	// temporary files for the output
	rb.nbag, err = os.CreateTemp(filepath.Dir(path), "video.*.bag")
	if err != nil {
		_ = rb.Close()
		return nil, err
	}
	rb.nidx, err = os.CreateTemp(filepath.Dir(path), "video.*.idx")
	if err != nil {
		_ = rb.Close()
		return nil, err
	}
	return rb, nil
}

func (rb *replacer) Close() error {
	if rb.bag != nil {
		_ = rb.bag.Close()
	}
	if rb.idx != nil {
		_ = rb.idx.Close()
	}
	if rb.nbag != nil {
		_ = rb.nbag.Close()
		_ = os.Remove(rb.nbag.Name())
		rb.nbag = nil
	}
	if rb.nidx != nil {
		_ = rb.nidx.Close()
		_ = os.Remove(rb.nidx.Name())
		rb.nidx = nil
	}
	return nil
}

// Replace old files with the new ones.
func (rb *replacer) Replace() error {
	// close everything
	err := rb.nbag.Close()
	if err != nil {
		return err
	}
	err = rb.nidx.Close()
	if err != nil {
		return err
	}
	_ = rb.bag.Close()
	_ = rb.idx.Close()

	// replace old files with the new ones
	err = os.Rename(rb.nbag.Name(), rb.bag.Name())
	if err != nil {
		return err
	}
	rb.nbag = nil

	err = os.Rename(rb.nidx.Name(), rb.idx.Name())
	if err != nil {
		return err
	}
	rb.nidx = nil
	return nil
}

// Decompress video.bag file and update video.idx.
func (rb *replacer) Decompress() error {
	var hdr [24]byte
	_, err := io.ReadFull(rb.idx, hdr[:])
	if err != nil {
		return fmt.Errorf("cannot read header: %w", err)
	}
	segCnt := int(endiness.Uint32(hdr[8:]))
	if _, err = rb.nidx.Write(hdr[:]); err != nil {
		return err
	}

	br := bufio.NewReader(rb.idx)

	offsOld := int64(0)
	var ibuf []byte
	for i := 0; i < segCnt; i++ {
		// read section header
		var shdr [16]byte
		_, err = io.ReadFull(br, shdr[:])
		if err != nil {
			return fmt.Errorf("cannot read section %d: %w", i, err)
		}
		size := int64(endiness.Uint32(shdr[4:]))
		sizeComp := int64(endiness.Uint32(shdr[8:]))
		cnt := int(int32(endiness.Uint32(shdr[12:])))
		if cnt == -1 {
			cnt = 1
		}
		// seek to section start in the bag file
		_, err = rb.bag.Seek(offsOld, io.SeekStart)
		if err != nil {
			return fmt.Errorf("cannot read section data %d: %w", i, err)
		}
		var rbag io.Reader = rb.bag
		if size != sizeComp {
			// decompress and change the header accordingly
			rbag = nxz.NewReader(rbag)
			endiness.PutUint32(shdr[8:], uint32(size))
		}
		// copy and possibly decompress data
		_, err = io.CopyN(rb.nbag, rbag, size)
		if err != nil {
			return fmt.Errorf("cannot copy section data %d: %w", i, err)
		}
		// write the new section header
		if _, err = rb.nidx.Write(shdr[:]); err != nil {
			return err
		}

		for j := 0; j < cnt; j++ {
			// length of the image name
			bn, err := br.ReadByte()
			if err == io.EOF {
				return io.ErrUnexpectedEOF
			} else if err != nil {
				return err
			}
			n := int(bn)
			// now we know the length of the image record
			if sz := 1 + n + 9; cap(ibuf) < sz {
				ibuf = make([]byte, 1+n+9)
			} else {
				ibuf = ibuf[:sz]
			}
			ibuf[0] = bn
			_, err = io.ReadFull(br, ibuf[1:])
			if err != nil {
				return fmt.Errorf("cannot read image %d,%d: %w", i, j, err)
			}
			// write it back
			if _, err = rb.nidx.Write(ibuf[:]); err != nil {
				return err
			}
		}
		offsOld += sizeComp
	}

	// now we know the size of the index, so we can jump back to update it
	size, err := rb.nidx.Seek(0, io.SeekEnd)
	if err != nil {
		return err
	}
	var szbuf [4]byte
	endiness.PutUint32(szbuf[:], uint32(size))
	_, err = rb.nidx.WriteAt(szbuf[:], 4)
	if err != nil {
		return err
	}
	return nil
}

// ReplaceSprites changes one or more sprites in the video.bag and video.idx.
func (rb *replacer) ReplaceSprites(list []Replacement) error {
	byImgInd := make(map[int]Replacement)
	for _, r := range list {
		byImgInd[r.ImageInd] = r
	}

	var hdr [24]byte
	_, err := io.ReadFull(rb.idx, hdr[:])
	if err != nil {
		return fmt.Errorf("cannot read header: %w", err)
	}
	segCnt := int(endiness.Uint32(hdr[8:]))
	if _, err = rb.nidx.Write(hdr[:]); err != nil {
		return err
	}

	br := bufio.NewReader(rb.idx)

	offsOld := int64(0)
	imgInd := 0
	var ibuf []byte
	sind := bytes.NewBuffer(nil)
	for i := 0; i < segCnt; i++ {
		// read section header
		var shdr [16]byte
		_, err = io.ReadFull(br, shdr[:])
		if err != nil {
			return fmt.Errorf("cannot read section %d: %w", i, err)
		}
		size := int64(endiness.Uint32(shdr[4:]))
		sizeComp := int64(endiness.Uint32(shdr[8:]))
		cnt := int(int32(endiness.Uint32(shdr[12:])))
		if cnt == -1 {
			cnt = 1
		}
		// seek to section start in the bag file
		_, err = rb.bag.Seek(offsOld, io.SeekStart)
		if err != nil {
			return fmt.Errorf("cannot read section data %d: %w", i, err)
		}
		offsOld += sizeComp

		var rbag io.Reader = rb.bag
		if size != sizeComp {
			// decompress and change the header accordingly
			rbag = nxz.NewReader(rbag)
		}
		sind.Reset()

		imgOff := int64(0)
		for j := 0; j < cnt; j++ {
			// length of the image name
			bn, err := br.ReadByte()
			if err == io.EOF {
				return io.ErrUnexpectedEOF
			} else if err != nil {
				return err
			}
			n := int(bn)
			// now we know the length of the image record
			if sz := 1 + n + 9; cap(ibuf) < sz {
				ibuf = make([]byte, 1+n+9)
			} else {
				ibuf = ibuf[:sz]
			}
			ibuf[0] = bn
			_, err = io.ReadFull(br, ibuf[1:])
			if err != nil {
				return fmt.Errorf("cannot read image %d,%d: %w", i, j, err)
			}
			isize := int64(endiness.Uint32(ibuf[len(ibuf)-8:]))
			if rp, ok := byImgInd[imgInd]; ok {
				ityp := ibuf[len(ibuf)-9]
				switch ityp {
				default:
					return fmt.Errorf("unsupported type for %d,%d: %d", i, j, ityp)
				case 3, 4, 5, 6:
				}
				out := &pcx.Image{
					ImageMeta: pcx.ImageMeta{
						Type: ityp,
					},
					RGBA: *asRGBA(rp.Image),
				}
				skip := isize
				if rp.Point != nil {
					out.Point = *rp.Point
				} else {
					var phdr [17]byte
					_, err := io.ReadFull(rbag, phdr[:])
					if err != nil {
						return err
					}
					offsX := int(endiness.Uint32(phdr[8:]))
					offsY := int(endiness.Uint32(phdr[12:]))
					out.Point = image.Pt(offsX, offsY)
					skip -= int64(len(phdr))
				}
				// skip image data from the source
				_, err = io.CopyN(io.Discard, rbag, skip)
				if err != nil {
					return fmt.Errorf("cannot copy section data %d: %w", i, err)
				}
				// encode new image
				idata := pcx.Encode(out)
				isize = int64(len(idata))
				// write new image to the bag file
				_, err = rb.nbag.Write(idata)
				if err != nil {
					return fmt.Errorf("cannot copy image data %d: %w", i, err)
				}
				// update the image size in the header
				endiness.PutUint32(ibuf[len(ibuf)-8:], uint32(isize))
				// write the image record
				if _, err = sind.Write(ibuf[:]); err != nil {
					return err
				}
			} else {
				// write it back unchanged
				if _, err = sind.Write(ibuf[:]); err != nil {
					return err
				}
				// copy image data
				_, err = io.CopyN(rb.nbag, rbag, isize)
				if err != nil {
					return fmt.Errorf("cannot copy section data %d: %w", i, err)
				}
			}

			imgInd++
			imgOff += isize
		}
		// update section size in the index
		size = imgOff
		endiness.PutUint32(shdr[4:], uint32(size))
		endiness.PutUint32(shdr[8:], uint32(size))
		// write the new section header
		if _, err = rb.nidx.Write(shdr[:]); err != nil {
			return err
		}
		// write the section images from the buffer
		if _, err = sind.WriteTo(rb.nidx); err != nil {
			return err
		}
	}

	// now we know the size of the index, so we can jump back to update it
	size, err := rb.nidx.Seek(0, io.SeekEnd)
	if err != nil {
		return err
	}
	var szbuf [4]byte
	endiness.PutUint32(szbuf[:], uint32(size))
	_, err = rb.nidx.WriteAt(szbuf[:], 4)
	if err != nil {
		return err
	}
	return nil
}
