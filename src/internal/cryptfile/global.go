package cryptfile

var global *CryptFile

func Global() *CryptFile {
	return global
}

func SetGlobal(cf *CryptFile) {
	global = cf
}

func OpenGlobal(path string, cmode Mode, key int) error {
	Close()
	cf, err := OpenFile(path, cmode, key)
	if err != nil {
		return err
	}
	SetGlobal(cf)
	return nil
}

func Close() error {
	if global == nil {
		return nil
	}
	err := global.Close()
	SetGlobal(nil)
	return err
}
