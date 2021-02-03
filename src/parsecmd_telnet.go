package main

/*
#include "common__telnet__telnetd.h"
*/
import "C"
import (
	"strconv"

	"nox/client/system/parsecmd"
)

func init() {
	parseCmd.Register(parsecmd.Command{Token: "telnet", HelpID: "telnethelp", Flags: parsecmd.Server, Sub: []parsecmd.Command{
		{Token: "on", HelpID: "telnetonhelp", Flags: parsecmd.Server, Func: cmdTelnetOn},
		{Token: "off", HelpID: "telnetoffhelp", Flags: parsecmd.Server, Func: cmdTelnetOff},
	}})
}

func cmdTelnetOff(_ int, tokens []string) bool {
	if len(tokens) != 2 {
		return false
	}
	if getGameFlag(2048) {
		return true
	}
	C.nox_telnet_stop_579830()
	s := strMan.GetString("parsecmd.c:telnetoff")
	consolePrintf(parsecmd.ColorRed, s)
	return true
}

func cmdTelnetOn(_ int, tokens []string) bool {
	n := len(tokens)
	if n < 2 || n > 3 {
		return false
	}
	if getGameFlag(2048) {
		return true
	}
	if n == 2 {
		C.nox_telnet_start_5797F0(0)
	} else {
		v, _ := strconv.ParseUint(tokens[n-1], 10, 16)
		C.nox_telnet_start_5797F0(C.ushort(v))
	}
	port := int(C.nox_telnet_getPort_579850())
	s := strMan.GetString("parsecmd.c:telneton")
	consolePrintf(parsecmd.ColorRed, s, port)
	return true
}
