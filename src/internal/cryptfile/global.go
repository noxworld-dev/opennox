package cryptfile

var global *CryptFile

func Global() *CryptFile {
	return global
}

func OpenGlobal(path string, cmode int, key int) error {
	Close()
	cf, err := OpenFile(path, cmode, key)
	if err != nil {
		return err
	}
	global = cf
	return nil
}

func Close() error {
	if global == nil {
		return nil
	}
	err := global.Close()
	global = nil
	return err
}
