package nox

/*
#include "GAME1_3.h"
extern unsigned int dword_5d4594_251744;
*/
import "C"
import (
	noxflags "nox/v1/common/flags"
)

//export sub_413A00
func sub_413A00(a1 C.int) {
	if noxflags.HasGame(2048) {
		if a1 != 0 {
			noxflags.SetGame(0x40000)
		} else {
			if C.dword_5d4594_251744 == 0 {
				noxflags.UnsetGame(0x40000)
				nox_ticks_reset_416D40()
			}
		}
	}
}

//export sub_448640
func sub_448640() { C.sub_44A400() }
