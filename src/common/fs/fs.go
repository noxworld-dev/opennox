package fs

import "os"

func Open(path string) (*os.File, error) {
	return os.Open(Normalize(path))
}

func Create(path string) (*os.File, error) {
	return os.Create(Normalize(path))
}
