package log

import (
	"log"
	"os"
)

func New(name string) *log.Logger {
	return log.New(os.Stderr, "["+name+"]: ", log.LstdFlags|log.Lmsgprefix)
}

func Printf(format string, args ...interface{}) {
	log.Printf(format, args...)
}

func Println(args ...interface{}) {
	log.Println(args...)
}
