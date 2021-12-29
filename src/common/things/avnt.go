package things

import "fmt"

func (f *Reader) skipAVNT() error {
	if err := f.skipBytes8(); err != nil {
		return err
	}
	for {
		v, err := f.readI8()
		if err != nil {
			return err
		}
		switch v {
		case 0:
			return nil
		case 1, 2, 3, 4, 5:
			if err := f.skip(1); err != nil {
				return err
			}
		case 6, 9, 10:
			if err := f.skip(2); err != nil {
				return err
			}
		case 7:
			for {
				v, err := f.readU8()
				if err != nil {
					return err
				} else if v == 0 {
					break
				}
				if err := f.skip(int(v)); err != nil {
					return err
				}
			}
		case 8:
			if err := f.skip(8); err != nil {
				return err
			}
		default:
			return fmt.Errorf("unknown AVNT type: %d", v)
		}
	}
}
