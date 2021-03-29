package bag

import (
	"bufio"
	"errors"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"io"
)

func readPCX(r io.Reader, typ int) (image.Image, image.Point, error) {
	switch typ {
	case 3, 4, 5, 6:
		return readPCXSprite(r)
	default:
		return nil, image.Point{}, fmt.Errorf("unsupported type: %d", typ)
	}
}

func colorRGB15(cl uint16) color.RGBA {
	r := byte((cl & 0xfc00) >> 10)
	g := byte((cl & 0x03e0) >> 5)
	b := byte((cl & 0x001f) >> 0)
	r = byte((float64(r) / 31) * 0xff)
	g = byte((float64(g) / 31) * 0xff)
	b = byte((float64(b) / 31) * 0xff)
	return color.RGBA{
		R: r, G: g, B: b, A: 0xff,
	}
}

func colorRGBA16(cl uint16) color.RGBA {
	r := byte((cl >> 12) & 0xf)
	g := byte((cl >> 8) & 0xf)
	b := byte((cl >> 4) & 0xf)
	a := byte((cl >> 0) & 0xf)
	r = byte((float64(r) / 15) * 0xff)
	g = byte((float64(g) / 15) * 0xff)
	b = byte((float64(b) / 15) * 0xff)
	a = byte((float64(a) / 15) * 0xff)
	return color.RGBA{
		R: r, G: g, B: b, A: a,
	}
}

func colorDynamic(op byte, cl byte) color.RGBA {
	// TODO: store into a separate mask instead?
	return color.RGBA{
		R: cl, G: cl, B: cl, A: 0x80 | op,
	}
}

func readPCXSprite(r io.Reader) (image.Image, image.Point, error) {
	var b [17]byte
	_, err := io.ReadFull(r, b[:])
	if err != nil {
		return nil, image.Point{}, err
	}
	width := int(endiness.Uint32(b[0:]))
	height := int(endiness.Uint32(b[4:]))
	offsX := int(endiness.Uint32(b[8:]))
	offsY := int(endiness.Uint32(b[12:]))
	offs := image.Pt(offsX, offsY)
	// one byte ignored

	if width <= 0 || width > 1024 || height <= 0 || height > 1024 {
		return nil, offs, errors.New("invalid image size")
	}

	img := image.NewRGBA(image.Rect(0, 0, width, height))
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
			return img, offs, nil
		} else if err != nil {
			return img, offs, err
		}
		switch op {
		case 0: // end
			return img, offs, nil
		case 3: // begin
			// nop
		case 1: // skip N pixels
			n, err := br.ReadByte()
			if err == io.EOF {
				return img, offs, io.ErrUnexpectedEOF
			} else if err != nil {
				return img, offs, err
			}
			for i := 0; i < int(n); i++ {
				step()
			}
		case 2, 5: // read N pixels
			bn, err := br.ReadByte()
			if err == io.EOF {
				return img, offs, io.ErrUnexpectedEOF
			} else if err != nil {
				return img, offs, err
			}
			n := int(bn)
			if cap(buf) < n*2 {
				buf = make([]byte, n*2)
			} else {
				buf = buf[:n*2]
			}
			_, err = io.ReadFull(br, buf)
			if err != nil {
				return img, offs, err
			}
			if op == 2 { // RGB15
				for i := 0; i < n; i++ {
					cl := endiness.Uint16(buf[2*i:])
					img.SetRGBA(px, py, colorRGB15(cl))
					step()
				}
			} else { // RGBA16
				for i := 0; i < n; i++ {
					cl := endiness.Uint16(buf[2*i:])
					img.SetRGBA(px, py, colorRGBA16(cl))
					step()
				}
			}
		default: // dynamic color
			if (op & 4) < 4 {
				continue
			}
			n, err := br.ReadByte()
			if err == io.EOF {
				return img, offs, io.ErrUnexpectedEOF
			} else if err != nil {
				return img, offs, err
			}
			if cap(buf) < int(n) {
				buf = make([]byte, n)
			} else {
				buf = buf[:n]
			}
			_, err = io.ReadFull(br, buf)
			if err != nil {
				return img, offs, err
			}
			for i := 0; i < int(n); i++ {
				cl := buf[i]
				img.SetRGBA(px, py, colorDynamic(op, cl))
				step()
			}
		}
	}
}

func EncodePCX(img image.Image, pt image.Point) []byte {
	rect := img.Bounds()
	width := rect.Dx()
	height := rect.Dy()
	data := make([]byte, 17+width*height*4+2)
	endiness.PutUint32(data[0:], uint32(width))
	endiness.PutUint32(data[4:], uint32(height))
	endiness.PutUint32(data[8:], uint32(int32(pt.X)))
	endiness.PutUint32(data[12:], uint32(int32(pt.Y)))
	pixdata := data[17:]
	pixdata = pixdata[:0] // will append to it
	rgba, ok := img.(*image.RGBA)
	if !ok {
		rgba = image.NewRGBA(rect)
		draw.Draw(rgba, rect, img, rect.Min, draw.Src)
	}
	const (
		modeZero = iota + 1
		modeRGB15
		modeRGBA16
	)
	const (
		pixMax   = 0xff
		compress = false // TODO: figure out why this doesn't work
	)
	var (
		pbuf  [2]byte
		pmode = -1
		ni    = -1
	)
	addZero := func() {
		if compress && pmode == modeZero {
			if n := pixdata[ni]; n < pixMax {
				pixdata[ni]++
				return
			}
		}
		pmode = modeZero
		pixdata = append(pixdata, 1, 1)
		ni = len(pixdata) - 1
	}
	addRGB15 := func(p uint16) {
		endiness.PutUint16(pbuf[:], p)
		if compress && pmode == modeRGB15 {
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
	addRGBA16 := func(p uint16) {
		endiness.PutUint16(pbuf[:], p)
		if compress && pmode == modeRGBA16 {
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
	for y := 0; y < height; y++ {
		for x := 0; x < width; x++ {
			i := y*rgba.Stride + x*4
			r := rgba.Pix[i+0]
			g := rgba.Pix[i+1]
			b := rgba.Pix[i+2]
			a := rgba.Pix[i+3]
			if a == 0x00 {
				addZero()
			} else if a == 0xff {
				// RGB15
				rb := uint16(float32(r)/0xff*31) & 0x1f
				gb := uint16(float32(g)/0xff*31) & 0x1f
				bb := uint16(float32(b)/0xff*31) & 0x1f
				cl := (bb << 0) | (gb << 5) | (rb << 10)
				addRGB15(cl)
			} else {
				// RGBA16
				rb := uint16(float32(r)/0xff*15) & 0xf
				gb := uint16(float32(g)/0xff*15) & 0xf
				bb := uint16(float32(b)/0xff*15) & 0xf
				ab := uint16(float32(a)/0xff*15) & 0xf
				cl := (ab << 0) | (bb << 4) | (gb << 8) | (rb << 12)
				addRGBA16(cl)
			}
		}
	}
	pixdata = append(pixdata, 0, 0) // end
	return data[:17+len(pixdata)]
}
