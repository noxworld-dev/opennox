package nox

import (
	"context"
	"strings"

	"nox/v1/common/console"
	noxflags "nox/v1/common/flags"
)

var (
	consoleWaitSysOpPass bool
)

func init() {
	noxConsole.Register(&console.Command{
		Token:  "exec",
		HelpID: "exechelp",
		Flags:  console.Server,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) != 1 {
				return false
			}
			cur := console.CurCommand(ctx)
			if !noxflags.HasGame(noxflags.GameHost) {
				s := strMan.GetStringInFile("RemoteExec", "parsecmd.c")
				c.Printf(console.ColorRed, s, cur)
			}
			nox_xxx_netServerCmd_440950(1, cur)
			return true
		},
	})
	noxConsole.Register(&console.Command{
		Token:  "broadcast",
		HelpID: "broadcasthelp",
		Flags:  console.Server,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) == 0 {
				return false
			}
			cmd := strings.Join(tokens, " ")
			nox_xxx_netServerCmd_440950(5, cmd)
			return true
		},
	})
	noxConsole.Register(&console.Command{
		Token:  "watch",
		HelpID: "watchhelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			cmd := strings.Join(tokens, " ")
			if noxflags.HasGame(noxflags.GameHost) {
				pl := clientPlayer()
				nox_xxx_serverHandleClientConsole_443E90(pl, 4, cmd)
			} else {
				nox_xxx_netServerCmd_440950(4, cmd)
			}
			return true
		},
	})
	noxConsole.Register(&console.Command{
		Token:  "say",
		HelpID: "sayhelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) == 0 {
				return false
			}
			text := strings.TrimPrefix(console.CurCommand(ctx), "say ")
			nox_xxx_cmdSayDo_46A4B0(text, 0)
			return true
		},
	})
	noxConsole.Register(&console.Command{
		Token:  "sysop",
		HelpID: "nohelp",
		Flags:  console.ClientServer | console.NoHelp,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) == 0 {
				consoleWaitSysOpPass = true
				str := c.Strings().GetStringInFile("enterSysopPW", "parsecmd.c")
				c.Print(console.ColorRed, str)
			} else if console.IsClient(ctx) {
				s := strings.TrimPrefix(console.CurCommand(ctx), "sysop ")
				nox_xxx_netServerCmd_440950(2, s)
			}
			return true
		},
	})
}
