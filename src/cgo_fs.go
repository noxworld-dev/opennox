package main

import "C"

var noxDataPath string

func setDataPath(path string) {
	noxDataPath = path
}

func getDataPath() string {
	return noxDataPath
}

//export nox_fs_root
func nox_fs_root() *C.char {
	return internCStr(getDataPath())
}
