package nox

/*
#include "common__telnet__telnetd.h"
*/
import "C"
import (
	"context"
	"strconv"

	"nox/v1/common/console"
	noxflags "nox/v1/common/flags"
)

func init() {
	noxConsole.Register(&console.Command{Token: "telnet", HelpID: "telnethelp", Flags: console.Server, Sub: []*console.Command{
		{Token: "on", HelpID: "telnetonhelp", Flags: console.Server, Func: cmdTelnetOn},
		{Token: "off", HelpID: "telnetoffhelp", Flags: console.Server, Func: cmdTelnetOff},
	}})
}

func cmdTelnetOff(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 0 {
		return false
	}
	if noxflags.HasGame(noxflags.GameModeCoop) {
		return true
	}
	C.nox_telnet_stop_579830()
	s := c.Strings().GetString("parsecmd.c:telnetoff")
	c.Print(console.ColorRed, s)
	return true
}

func cmdTelnetOn(ctx context.Context, c *console.Console, tokens []string) bool {
	n := len(tokens)
	if n > 1 {
		return false
	}
	if noxflags.HasGame(noxflags.GameModeCoop) {
		return true
	}
	if n == 0 {
		C.nox_telnet_start_5797F0(0)
	} else {
		v, _ := strconv.ParseUint(tokens[0], 10, 16)
		C.nox_telnet_start_5797F0(C.ushort(v))
	}
	port := int(C.nox_telnet_getPort_579850())
	s := c.Strings().GetString("parsecmd.c:telneton")
	c.Printf(console.ColorRed, s, port)
	return true
}
