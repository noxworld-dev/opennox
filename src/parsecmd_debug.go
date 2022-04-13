package opennox

import (
	"context"

	"github.com/noxworld-dev/opennox-lib/console"
)

func init() {
	noxCmdShow.Register(&console.Command{
		Token:  "perfmon",
		HelpID: "showperfmonhelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			clientPlaySoundSpecial(921, 100)
			noxPerfmon.Toggle()
			return true
		},
	})
}
