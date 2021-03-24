package things

import "fmt"

func (f *File) skipSPEL() error {
	n, err := f.readU32()
	if err != nil {
		return err
	} else if n <= 0 {
		return nil
	}
	for i := 0; i < int(n); i++ {
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err = f.skip(1 + 2); err != nil {
			return err
		}
		sz, err := f.readU8()
		if err != nil {
			return err
		}
		for j := 0; j < int(sz); j++ {
			v, err := f.readU8()
			if err != nil {
				return err
			} else if v >= 9 {
				return fmt.Errorf("invalid spell code: %d", v)
			}
		}
		for k := 0; k < 2; k++ {
			if err := f.skipImageRef(); err != nil {
				return err
			}
		}
		if err = f.skip(4); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes16(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skipBytes8(); err != nil {
			return err
		}
	}
	return nil // no END here
}
