package log

import (
	"io"
	"log"
	"os"
)

var (
	output io.Writer = os.Stderr
	writer io.Writer
	closer io.Closer
	deflog = log.New(global{}, "", log.LstdFlags|log.Lmsgprefix)
)

type global struct{}

func (global) Write(p []byte) (int, error) {
	if output == nil {
		return len(p), nil
	}
	n, err := output.Write(p)
	if writer != nil {
		n, err = writer.Write(p)
	}
	return n, err
}

type Logger = log.Logger

func New(name string) *log.Logger {
	return log.New(global{}, "["+name+"]: ", log.LstdFlags|log.Lmsgprefix)
}

func Printf(format string, args ...interface{}) {
	deflog.Printf(format, args...)
}

func Println(args ...interface{}) {
	deflog.Println(args...)
}

func WriteToFile(path string) error {
	Close()
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	writer = f
	closer = f
	return nil
}

func SetOutput(w io.Writer) {
	output = w
}

func Close() {
	if closer != nil {
		_ = closer.Close()
		closer = nil
	}
}
