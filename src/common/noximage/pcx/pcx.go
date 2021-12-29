package pcx

import (
	"bufio"
	"encoding/binary"
	"fmt"
	"image"
	"image/color"
	"io"

	noxcolor "nox/v1/common/color"
	"nox/v1/common/noximage"
	"nox/v1/common/types"
)

var endiness = binary.LittleEndian

var _ image.Image = (*Image)(nil)

type ImageMeta struct {
	Type  byte        `json:"type,omitempty"`
	Point image.Point `json:"point"`
}

type Image struct {
	image.RGBA
	ImageMeta
	Mask *image.RGBA
}

func Decode(r io.Reader, typ byte) (*Image, error) {
	switch typ {
	case 3, 4, 5, 6:
		return readSprite(r, typ)
	default:
		return nil, fmt.Errorf("unsupported type: %d", typ)
	}
}

func DecodeHeader(r io.Reader, typ byte) (*ImageMeta, types.Size, error) {
	switch typ {
	case 3, 4, 5, 6:
		meta, sz, err := readSpriteHeader(r, typ)
		return meta, sz, err
	default:
		return nil, types.Size{}, fmt.Errorf("unsupported type: %d", typ)
	}
}

func colorDynamicColor(op byte, cl byte) color.RGBA {
	// TODO: make a separate color type
	return color.RGBA{
		R: cl, G: cl, B: cl, A: 0xff,
	}
}

func colorDynamicMask(op byte, cl byte) color.RGBA {
	// TODO: make a separate color type
	return color.RGBA{
		R: op, G: cl, B: 0, A: 0xff,
	}
}

func readSpriteHeader(r io.Reader, typ byte) (*ImageMeta, noximage.Size, error) {
	var b [17]byte
	_, err := io.ReadFull(r, b[:])
	if err != nil {
		return nil, noximage.Size{}, err
	}
	width := int(endiness.Uint32(b[0:]))
	height := int(endiness.Uint32(b[4:]))
	offsX := int(endiness.Uint32(b[8:]))
	offsY := int(endiness.Uint32(b[12:]))
	offs := image.Pt(offsX, offsY)
	// one byte ignored
	if width <= 0 || width > 1024 || height <= 0 || height > 1024 {
		return nil, noximage.Size{}, fmt.Errorf("invalid image size: %dx%d", width, height)
	}
	return &ImageMeta{
			Type:  typ,
			Point: offs,
		}, noximage.Size{
			W: width,
			H: height,
		}, nil
}

func readSprite(r io.Reader, typ byte) (*Image, error) {
	meta, sz, err := readSpriteHeader(r, typ)
	if err != nil {
		return nil, err
	}
	width := sz.W
	height := sz.H

	img := &Image{
		RGBA:      *image.NewRGBA(image.Rect(0, 0, width, height)),
		ImageMeta: *meta,
	}
	br := bufio.NewReader(r)

	var buf []byte
	px := 0
	py := 0
	step := func() {
		if px+1 >= width {
			px = 0
			py++
		} else {
			px++
		}
	}
	for {
		op, err := br.ReadByte()
		if err == io.EOF {
			return img, nil
		} else if err != nil {
			return img, err
		}
		switch op {
		case 0: // end
			return img, nil
		case 3: // begin
			// nop
		case 1: // skip N pixels
			n, err := br.ReadByte()
			if err == io.EOF {
				return img, io.ErrUnexpectedEOF
			} else if err != nil {
				return img, err
			}
			for i := 0; i < int(n); i++ {
				step()
			}
		case 2, 5: // read N pixels
			bn, err := br.ReadByte()
			if err == io.EOF {
				return img, io.ErrUnexpectedEOF
			} else if err != nil {
				return img, err
			}
			n := int(bn)
			if cap(buf) < n*2 {
				buf = make([]byte, n*2)
			} else {
				buf = buf[:n*2]
			}
			_, err = io.ReadFull(br, buf)
			if err != nil {
				return img, err
			}
			if op == 2 { // RGB555
				for i := 0; i < n; i++ {
					cl := noxcolor.RGB555(endiness.Uint16(buf[2*i:]))
					img.SetRGBA(px, py, cl.RGBA32())
					step()
				}
			} else { // RGBA4444
				for i := 0; i < n; i++ {
					cl := noxcolor.RGBA4444(endiness.Uint16(buf[2*i:]))
					img.SetRGBA(px, py, cl.RGBA32())
					step()
				}
			}
		default: // dynamic color
			if (op & 4) < 4 {
				continue
			}
			n, err := br.ReadByte()
			if err == io.EOF {
				return img, io.ErrUnexpectedEOF
			} else if err != nil {
				return img, err
			}
			if cap(buf) < int(n) {
				buf = make([]byte, n)
			} else {
				buf = buf[:n]
			}
			_, err = io.ReadFull(br, buf)
			if err != nil {
				return img, err
			}
			if img.Mask == nil {
				img.Mask = image.NewRGBA(img.Rect)
			}
			for i := 0; i < int(n); i++ {
				cl := buf[i]
				img.SetRGBA(px, py, colorDynamicColor(op, cl))
				img.Mask.SetRGBA(px, py, colorDynamicMask(op, cl))
				step()
			}
		}
	}
}

func Encode(img *Image) []byte {
	rect := img.Bounds()
	width := rect.Dx()
	height := rect.Dy()
	data := make([]byte, 17+width*height*4+2)
	endiness.PutUint32(data[0:], uint32(width))
	endiness.PutUint32(data[4:], uint32(height))
	endiness.PutUint32(data[8:], uint32(int32(img.Point.X)))
	endiness.PutUint32(data[12:], uint32(int32(img.Point.Y)))
	if img.Type == 0 {
		data[16] = 0x3
	} else {
		data[16] = img.Type
	}
	pixdata := data[17:]
	pixdata = pixdata[:0] // will append to it
	rgba := &img.RGBA
	mask := img.Mask
	const (
		modeZero = iota + 1
		modeRGB15
		modeRGBA16
		modeMask
	)
	const (
		pixMax = 0xfd
	)
	var (
		pbuf  [2]byte
		pmode = -1
		ni    = -1
	)
	addZero := func() {
		if pmode == modeZero {
			if n := pixdata[ni]; n < pixMax {
				pixdata[ni]++
				return
			}
		}
		pmode = modeZero
		pixdata = append(pixdata, 1, 1)
		ni = len(pixdata) - 1
	}
	addRGB15 := func(p noxcolor.RGB555) {
		endiness.PutUint16(pbuf[:], uint16(p))
		if pmode == modeRGB15 {
			if n := pixdata[ni]; n < pixMax {
				pixdata[ni]++
				pixdata = append(pixdata, pbuf[0], pbuf[1])
				return
			}
		}
		pmode = modeRGB15
		pixdata = append(pixdata, 2, 1, pbuf[0], pbuf[1])
		ni = len(pixdata) - 3
	}
	addRGBA16 := func(p noxcolor.RGBA4444) {
		endiness.PutUint16(pbuf[:], uint16(p))
		if pmode == modeRGBA16 {
			if n := pixdata[ni]; n < pixMax {
				pixdata[ni]++
				pixdata = append(pixdata, pbuf[0], pbuf[1])
				return
			}
		}
		pmode = modeRGBA16
		pixdata = append(pixdata, 5, 1, pbuf[0], pbuf[1])
		ni = len(pixdata) - 3
	}
	addMask := func(op, cl byte) {
		md := modeMask + int(op)
		if pmode == md {
			if n := pixdata[ni]; n < pixMax {
				pixdata[ni]++
				pixdata = append(pixdata, cl)
				return
			}
		}
		pmode = md
		pixdata = append(pixdata, op, 1, cl)
		ni = len(pixdata) - 2
	}
	for y := 0; y < height; y++ {
		pmode = 0 // compression resets on each row
		for x := 0; x < width; x++ {
			if mask != nil {
				i := y*mask.Stride + x*4
				op := mask.Pix[i+0]
				cl := mask.Pix[i+1]
				// b is unused
				a := mask.Pix[i+3]
				if a != 0 {
					addMask(op, cl)
					continue
				}
			}
			i := y*rgba.Stride + x*4
			r := rgba.Pix[i+0]
			g := rgba.Pix[i+1]
			b := rgba.Pix[i+2]
			a := rgba.Pix[i+3]
			if a == 0x00 {
				addZero()
			} else if a == 0xff {
				// RGB555
				addRGB15(noxcolor.ToRGB555(r, g, b))
			} else {
				// RGBA4444
				addRGBA16(noxcolor.ToRGBA4444(r, g, b, a))
			}
		}
	}
	pixdata = append(pixdata, 0, 0) // end
	return data[:17+len(pixdata)]
}
