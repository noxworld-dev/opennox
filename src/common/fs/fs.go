package fs

import (
	"io"
	"io/fs"
	"os"
	"path/filepath"
)

func Stat(path string) (os.FileInfo, error) {
	return os.Stat(Normalize(path))
}

type DirEntry = fs.DirEntry

func WalkDir(path string, fnc fs.WalkDirFunc) error {
	return filepath.WalkDir(Normalize(path), fnc)
}

func Open(path string) (*os.File, error) {
	return os.Open(Normalize(path))
}

func Create(path string) (*os.File, error) {
	return os.Create(Normalize(path))
}

func OpenFile(path string, flag int) (*os.File, error) {
	return os.OpenFile(Normalize(path), flag, 0644)
}

func Mkdir(path string) error {
	err := os.Mkdir(Normalize(path), 0777)
	if os.IsExist(err) {
		err = nil
	}
	return err
}

func MkdirAll(path string) error {
	return os.MkdirAll(Normalize(path), 0777)
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
