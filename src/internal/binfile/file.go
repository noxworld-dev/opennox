package binfile

import (
	"bufio"
	"io"
	"os"
	"unsafe"
)

func FileSize(f io.Seeker) (int64, error) {
	cur, err := f.Seek(0, io.SeekCurrent)
	if err != nil {
		return 0, err
	}
	size, err := f.Seek(0, io.SeekEnd)
	if err != nil {
		return 0, err
	}
	_, err = f.Seek(cur, io.SeekStart)
	if err != nil {
		return 0, err
	}
	return size, nil
}

func NewFile(f *os.File) *File {
	return &File{File: f}
}

func NewTextFile(f *os.File) *File {
	return &File{File: f, text: true}
}

type File struct {
	Handle unsafe.Pointer
	*os.File
	buf  *bufio.Reader
	Err  error
	text bool
	Bin  *Binfile
}

func (f *File) enableBuffer() {
	if f.buf != nil {
		return
	}
	f.buf = bufio.NewReader(f.File)
}

func (f *File) Size() (int64, error) {
	size, err := FileSize(f)
	if err != nil {
		f.Err = err
	}
	return size, err
}

func (f *File) Seek(off int64, whence int) (int64, error) {
	if f.buf != nil {
		if whence == io.SeekCurrent {
			off -= int64(f.buf.Buffered())
		}
		f.buf = nil
	}
	n, err := f.File.Seek(off, whence)
	f.Err = err
	return n, err
}

func (f *File) Read(p []byte) (int, error) {
	if f.buf != nil {
		n, err := f.buf.Read(p)
		f.Err = err
		return n, err
	}
	n, err := f.File.Read(p)
	f.Err = err
	return n, err
}

func (f *File) Write(p []byte) (int, error) {
	if f.buf != nil {
		panic("TODO: write on a buffered file")
	}
	n, err := f.File.Write(p)
	f.Err = err
	return n, err
}

func (f *File) WriteString(p string) (int, error) {
	if f.buf != nil {
		panic("TODO: write on a buffered file")
	}
	n, err := f.File.WriteString(p)
	f.Err = err
	return n, err
}

func (f *File) Close() error {
	if f.buf != nil {
		f.buf = nil
	}
	if f.Bin != nil {
		if err := f.Bin.close(); err != nil {
			_ = f.File.Close()
			return err
		}
	}
	return f.File.Close()
}

func (f *File) ReadString() ([]byte, error) {
	f.enableBuffer()
	var (
		out []byte
		end bool
	)
	for {
		b, err := f.buf.ReadByte()
		f.Err = err
		if err == io.EOF {
			end = true
			break
		} else if err != nil {
			return nil, err
		}
		out = append(out, b)
		if b == '\n' {
			break
		}
	}
	if n := len(out); n >= 2 && out[n-2] == '\r' && out[n-1] == '\n' {
		out[n-2] = '\n'
		out = out[:n-1]
	}
	if end {
		return out, io.EOF
	}
	return out, nil
}
