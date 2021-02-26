package main

/*
#cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo windows LDFLAGS: -lws2_32
#cgo linux LDFLAGS: -lm
#cgo CFLAGS: -DNOX_CGO
*/
import "C"
