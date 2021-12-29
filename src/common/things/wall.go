package things

import (
	"image"
	"io"
)

type Wall struct {
	Name       string `json:"name"`
	Unk1       uint32
	Unk2       uint32
	Unk3       uint32
	Unk4       uint16
	OpenSound  string            `json:"open_sound,omitempty"`
	CloseSound string            `json:"close_sound,omitempty"`
	BreakSound string            `json:"break_sound,omitempty"`
	Directions [15]WallDirection `json:"directions,omitempty"`
}

type WallDirection struct {
	Variants []WallVariant `json:"variants,omitempty"`
}

type WallVariant struct {
	Images [4]WallImage `json:"images,omitempty"`
}

type WallImage struct {
	Pt  image.Point `json:"pt,omitempty"`
	Img ImageRef    `json:"img"`
}

func (f *Reader) ReadWalls() ([]Wall, error) {
	if err := f.seek(0, io.SeekStart); err != nil {
		return nil, err
	}
	var out []Wall
	for {
		ok, err := f.skipUntil("WALL")
		if !ok {
			return out, err
		}
		page, err := f.readWALL()
		if err != nil {
			return out, err
		}
		out = append(out, page...)
	}
}

func (f *Reader) skipWALL() error {
	if err := f.skip(4); err != nil {
		return err
	}
	if err := f.skipBytes8(); err != nil {
		return err
	}
	if err := f.skip(3*4 + 2*1); err != nil {
		return err
	}
	v1, err := f.readU64align()
	if err != nil {
		return err
	}
	if byte(v1) > 0 {
		for i := 0; i < int(byte(v1)); i++ {
			if err := f.skipBytes8(); err != nil {
				return err
			}
		}
	}
	for i := 0; i < 3; i++ {
		if err := f.skipBytes8(); err != nil {
			return err
		}
	}
	if err := f.skip(1); err != nil {
		return err
	}
	for i := 0; i < 15; i++ {
		v2, err := f.readU64align()
		if err != nil {
			return err
		}
		for j := 0; j < int(byte(v2)); j++ {
			for k := 0; k < 4; k++ {
				if err := f.skip(2 * 4); err != nil {
					return err
				}
				if err := f.skipImageRef(); err != nil {
					return err
				}
			}
		}
	}
	return f.checkEND()
}

func (f *Reader) readWALL() ([]Wall, error) {
	n, err := f.readU32()
	if err != nil {
		return nil, err
	}
	out := make([]Wall, 0, n)
	for wi := 0; wi < int(n); wi++ {
		name, err := f.readString8()
		if err != nil {
			return nil, err
		}
		unk1, err := f.readU32()
		if err != nil {
			return nil, err
		}
		unk2, err := f.readU32()
		if err != nil {
			return nil, err
		}
		unk3, err := f.readU32()
		if err != nil {
			return nil, err
		}
		unk4, err := f.readU16()
		if err != nil {
			return nil, err
		}
		dnum, err := f.readU64align()
		if err != nil {
			return nil, err
		}
		debris := make([]string, 0, int(dnum))
		for i := 0; i < int(dnum); i++ {
			s, err := f.readString8()
			if err != nil {
				return nil, err
			}
			debris = append(debris, s)
		}
		sopen, err := f.readString8()
		if err != nil {
			return nil, err
		}
		sclose, err := f.readString8()
		if err != nil {
			return nil, err
		}
		sbreak, err := f.readString8()
		if err != nil {
			return nil, err
		}
		_, err = f.readU8() // variations count hint
		if err != nil {
			return nil, err
		}
		wall := Wall{
			Name:       name,
			Unk1:       unk1,
			Unk2:       unk2,
			Unk3:       unk3,
			Unk4:       unk4,
			OpenSound:  sopen,
			CloseSound: sclose,
			BreakSound: sbreak,
		}
		for i := 0; i < 15; i++ {
			vn, err := f.readU64align()
			if err != nil {
				return nil, err
			}
			vars := make([]WallVariant, 0, int(vn))
			for j := 0; j < int(vn); j++ {
				var vari WallVariant
				for k := 0; k < 4; k++ {
					x, err := f.readI32()
					if err != nil {
						return nil, err
					}
					y, err := f.readI32()
					if err != nil {
						return nil, err
					}
					ref, err := f.readImageRef()
					if err != nil {
						return nil, err
					}
					vari.Images[k] = WallImage{
						Pt:  image.Pt(int(x), int(y)),
						Img: *ref,
					}
				}
				vars = append(vars, vari)
			}
			wall.Directions[i] = WallDirection{Variants: vars}
		}
		out = append(out, wall)
	}
	return out, f.checkEND()
}
