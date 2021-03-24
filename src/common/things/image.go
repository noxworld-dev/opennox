package things

import (
	"encoding/json"
	"fmt"
	"io"
)

type Image struct {
	Name string     `json:"name"`
	Img  *ImageRef  `json:"img,omitempty"`
	Ani  *Animation `json:"ani,omitempty"`
}

type Animation struct {
	Field  byte       `json:"field"`
	Loop   bool       `json:"loop"`
	Frames []ImageRef `json:"frames"`
}

var (
	_ json.Marshaler   = &ImageRef{}
	_ json.Unmarshaler = &ImageRef{}
)

type ImageRef struct {
	Ind  int
	Ind2 int
	Name string
}

func (ii *ImageRef) MarshalJSON() ([]byte, error) {
	if ii.Ind != 0 {
		return json.Marshal(ii.Ind)
	}
	return json.Marshal(*ii)
}

func (ii *ImageRef) UnmarshalJSON(p []byte) error {
	*ii = ImageRef{}
	var ind int
	if err := json.Unmarshal(p, &ind); err == nil {
		ii.Ind = ind
		return nil
	}
	var v struct {
		Ind  int    `json:"ind,omitempty"`
		Name string `json:"name,omitempty"`
	}
	if err := json.Unmarshal(p, &v); err != nil {
		return err
	}
	ii.Ind2 = v.Ind
	ii.Name = v.Name
	return nil
}

func (f *File) readImageRef() (*ImageRef, error) {
	ind, err := f.readI32()
	if err != nil {
		return nil, err
	}
	if ind != -1 {
		return &ImageRef{Ind: int(ind)}, nil
	}
	ind2, err := f.readU8()
	if err != nil {
		return nil, err
	}
	name, err := f.readString8()
	if err != nil {
		return nil, err
	}
	return &ImageRef{Ind2: int(ind2), Name: name}, nil
}

func (f *File) skipImageRefs8() error {
	n, err := f.readU8()
	if err != nil {
		return err
	}
	for i := 0; i < int(n); i++ {
		if err := f.skipImageRef(); err != nil {
			return err
		}
	}
	return nil
}

func (f *File) skipImageRef() error {
	ind, err := f.readI32()
	if err != nil {
		return err
	}
	if ind != -1 {
		return nil
	}
	if err := f.skip(1); err != nil {
		return err
	}
	return f.skipBytes8()
}

func (f *File) readImage() (*Image, error) {
	name, err := f.readString8()
	if err != nil {
		return nil, err
	}
	typ, err := f.readI8()
	if err != nil {
		return nil, err
	}
	img := &Image{
		Name: name,
	}
	switch typ {
	default:
		return nil, fmt.Errorf("invalid image type: %d", typ)
	case 1:
		iind, err := f.readImageRef()
		if err != nil {
			return nil, err
		}
		img.Img = iind
		return img, nil
	case 2:
		frames, err := f.readU8()
		if err != nil {
			return nil, err
		}
		ani := &Animation{Frames: make([]ImageRef, 0, frames)}
		img.Ani = ani
		v2, err := f.readU8()
		if err != nil {
			return nil, err
		}
		ani.Field = v2
		loop, err := f.readString8()
		if err != nil {
			return nil, err
		}
		switch loop {
		default:
			return nil, fmt.Errorf("unsupported anim type: %q", loop)
		case "Loop":
			ani.Loop = true
		case "OneShot":
			ani.Loop = false
		}
		for i := 0; i < int(frames); i++ {
			fr, err := f.readImageRef()
			if err != nil {
				return nil, err
			}
			ani.Frames = append(ani.Frames, *fr)
		}
		return img, nil
	}
}

func (f *File) readImages() ([]Image, error) {
	n, err := f.readU32()
	if err != nil {
		return nil, err
	}
	out := make([]Image, 0, n)
	for i := 0; i < int(n); i++ {
		img, err := f.readImage()
		if err != nil {
			return out, err
		}
		out = append(out, *img)
	}
	return out, nil
}

func (f *File) ReadImages() ([]Image, error) {
	if err := f.seek(0, io.SeekStart); err != nil {
		return nil, err
	}
	var out []Image
	for {
		ok, err := f.skipUntil("IMAG")
		if !ok {
			return out, err
		}
		list, err := f.readImages()
		if err != nil {
			return out, err
		}
		out = append(out, list...)
	}
}

func (f *File) skipIMAG() error {
	n, err := f.readU32()
	if err != nil {
		return err
	}
	for i := 0; i < int(n); i++ {
		if err := f.skipBytes8(); err != nil {
			return err
		}
		typ, err := f.readI8()
		if err != nil {
			return err
		}
		switch typ {
		default:
			return fmt.Errorf("invalid image type: %d", typ)
		case 1:
			if err := f.skipImageRef(); err != nil {
				return err
			}
		case 2:
			frames, err := f.readU8()
			if err != nil {
				return err
			}
			if err := f.skip(1); err != nil {
				return err
			}
			if err := f.skipBytes8(); err != nil {
				return err
			}
			for j := 0; j < int(frames); j++ {
				if err := f.skipImageRef(); err != nil {
					return err
				}
			}
		}
	}
	return nil
}
