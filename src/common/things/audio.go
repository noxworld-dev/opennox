package things

func (f *Reader) skipAUD() error {
	n, err := f.readI32()
	if err != nil {
		return err
	}
	if n <= 0 {
		return nil
	}
	for i := 0; i < int(n); i++ {
		if err := f.skipBytes8(); err != nil {
			return err
		}
		if err := f.skip(9); err != nil {
			return err
		}
		for {
			sz, err := f.readU8()
			if err != nil {
				return err
			} else if sz == 0 {
				break
			}
			if err := f.skip(int(sz)); err != nil {
				return err
			}
		}
	}
	return nil // yes, there's no END
}
