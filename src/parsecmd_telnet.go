package main

/*
#include "common__telnet__telnetd.h"
*/
import "C"
import (
	"strconv"

	"nox/client/system/parsecmd"
	noxflags "nox/common/flags"
)

func init() {
	parseCmd.Register(&parsecmd.Command{Token: "telnet", HelpID: "telnethelp", Flags: parsecmd.Server, Sub: []*parsecmd.Command{
		{Token: "on", HelpID: "telnetonhelp", Flags: parsecmd.Server, Func: cmdTelnetOn},
		{Token: "off", HelpID: "telnetoffhelp", Flags: parsecmd.Server, Func: cmdTelnetOff},
	}})
}

func cmdTelnetOff(tokens []string) bool {
	if len(tokens) != 0 {
		return false
	}
	if noxflags.HasGame(noxflags.GameSolo) {
		return true
	}
	C.nox_telnet_stop_579830()
	s := strMan.GetString("parsecmd.c:telnetoff")
	consolePrintf(parsecmd.ColorRed, s)
	return true
}

func cmdTelnetOn(tokens []string) bool {
	n := len(tokens)
	if n > 1 {
		return false
	}
	if noxflags.HasGame(noxflags.GameSolo) {
		return true
	}
	if n == 0 {
		C.nox_telnet_start_5797F0(0)
	} else {
		v, _ := strconv.ParseUint(tokens[0], 10, 16)
		C.nox_telnet_start_5797F0(C.ushort(v))
	}
	port := int(C.nox_telnet_getPort_579850())
	s := strMan.GetString("parsecmd.c:telneton")
	consolePrintf(parsecmd.ColorRed, s, port)
	return true
}
