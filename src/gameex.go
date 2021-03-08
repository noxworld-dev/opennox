package main

/*
extern unsigned int dword_587000_87404;
*/
import "C"

//export startInvalidIpChecker
func startInvalidIpChecker() C.int {
	if C.dword_587000_87404 != 0 {
		return 0
	}
	// FIXME
	// go func() { C.invalidIpChecker() }()
	return 1
}
