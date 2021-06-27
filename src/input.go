package main

import (
	"nox/v1/common/log"
)

var (
	inputSeq           uint
	nox_input_prev_seq uint
	inputLog           = log.New("input")
)

func nextInputSeq() uint {
	v := inputSeq
	inputSeq++
	return v
}
