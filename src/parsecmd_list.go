package opennox

import "C"
import (
	"context"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/object"
)

func init() {
	noxCmdList.Register(&console.Command{
		Token:  "staffs",
		HelpID: "liststaffshelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return cmdListObjectsWithClass(c, object.ClassWand)
		},
	})
	noxCmdList.Register(&console.Command{
		Token:  "armor",
		HelpID: "listarmorhelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return cmdListObjectsWithClass(c, object.ClassArmor)
		},
	})
	noxCmdList.Register(&console.Command{
		Token:  "weapons",
		HelpID: "listweaponshelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return cmdListObjectsWithClass(c, object.ClassWeapon)
		},
	})
	noxCmdList.Register(&console.Command{
		Token:  "food",
		HelpID: "listfoodhelp",
		Help:   "list food: List all food items.",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return cmdListObjectsWithClass(c, object.ClassFood)
		},
	})
	noxCmdList.Register(&console.Command{
		Token:  "monsters",
		HelpID: "listmonstershelp",
		Help:   "list monsters: List all monsters.",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return cmdListObjectsWithClass(c, object.ClassMonster)
		},
	})
}

func cmdListObjectsWithClass(c *console.Console, class object.Class) bool {
	allowed := c.Strings().GetStringInFile("allowed", "parsecmd.c")
	disallowed := c.Strings().GetStringInFile("disallowed", "parsecmd.c")
	for _, typ := range noxServer.getObjectTypes() {
		if !typ.Class().Has(class) {
			continue
		}
		if !class.HasAny(object.ClassWand | object.ClassArmor | object.ClassWeapon) {
			c.Printf(console.ColorRed, "%d\t%s", typ.Ind(), typ.ID())
		} else {
			allow := allowed
			if noxServer.getObjectTypeByInd(typ.Ind()).allowed == 0 {
				allow = disallowed
			}
			// TODO: print full name via sub_415E80/sub_4159F0/sub_4159F0
			c.Printf(console.ColorRed, "%d\t%s\t%s", typ.Ind(), typ.ID(), allow)
		}
	}
	return true
}
