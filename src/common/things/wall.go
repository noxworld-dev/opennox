package things

func (f *File) skipWALL() error {
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
