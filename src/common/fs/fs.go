package fs

import (
	"io"
	"os"
)

func ProgName() string {
	return Denormalize(os.Args[0])
}

func Open(path string) (*os.File, error) {
	return os.Open(Normalize(path))
}

func Create(path string) (*os.File, error) {
	return os.Create(Normalize(path))
}

func Remove(path string) error {
	return os.Remove(Normalize(path))
}

func Workdir() (string, error) {
	path, err := os.Getwd()
	if err != nil {
		return "", err
	}
	return Denormalize(path), nil
}

func Chdir(path string) error {
	return os.Chdir(Normalize(path))
}

func Copy(src, dst string) error {
	r, err := Open(src)
	if err != nil {
		return err
	}
	defer r.Close()
	w, err := Create(dst)
	if err != nil {
		return err
	}
	defer w.Close()
	_, err = io.Copy(w, r)
	if err != nil {
		return err
	}
	return w.Close()
}

func Rename(src, dst string) error {
	src = Normalize(src)
	dst = Normalize(dst)
	return os.Rename(src, dst)
}
