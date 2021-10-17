//go:build server
// +build server

package nox

import "C"
import (
	"unsafe"

	"nox/v1/common/types"
)

//export sub_444D00
func sub_444D00() {
}

//export nox_video_showMovieFrame
func nox_video_showMovieFrame(s unsafe.Pointer) {
}

func resetRenderer(sz types.Size, _ bool) error {
	return nil
}

//export nox_video_setBackBufferPtrs_48A190
func nox_video_setBackBufferPtrs_48A190() {
}

func nox_video_copyBackBuffer_4AD2A0() {
}
func copyPixBuffer() {
}
