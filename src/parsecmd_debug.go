package opennox

import (
	"context"

	"github.com/noxworld-dev/opennox-lib/console"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func init() {
	noxCmdShow.Register(&console.Command{
		Token:  "perfmon",
		HelpID: "showperfmonhelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
			noxPerfmon.Toggle()
			return true
		},
	})
}
