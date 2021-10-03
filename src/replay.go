package nox

/*
#include "server__network__playback.h"
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/alloc"
)

func nox_xxx_replayStopSave_4D33B0() {
	C.nox_xxx_replayStopSave_4D33B0()
}

func nox_xxx_replayStopReadMB_4D3530() {
	C.nox_xxx_replayStopReadMB_4D3530()
}

func nox_xxx_replay_4D3860(pi *PlayerOpts) error {
	if getEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE) {
		data, err := pi.MarshalBinary()
		if err != nil {
			return err
		}
		cdata, cfree := alloc.Bytes(uintptr(len(data)))
		defer cfree()
		copy(cdata, data)
		C.nox_xxx_replay_4D3860(unsafe.Pointer(&cdata[0]))
		return nil
	}
	if getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ) {
		cdata, cfree := alloc.Bytes(153)
		defer cfree()
		C.nox_xxx_replay_4D3860(unsafe.Pointer(&cdata[0]))
		if err := pi.UnmarshalBinary(cdata); err != nil {
			return err
		}
		return nil
	}
	return nil
}

func nox_xxx_replayStartReadingOrSaving_4D38D0() int {
	return int(C.nox_xxx_replayStartReadingOrSaving_4D38D0())
}

func nox_xxx_replayWriteSomeInt_4D39B0() {
	C.nox_xxx_replayWriteSomeInt_4D39B0()
}

func nox_xxx_replayTickMB_4D3580_net_playback(v int) int {
	return int(C.nox_xxx_replayTickMB_4D3580_net_playback(C.int(v)))
}
