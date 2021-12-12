package nox

import (
	"context"

	"nox/v1/common/console"
	"nox/v1/common/things"
)

func init() {
	noxCmdList.Register(&console.Command{
		Token:  "spells",
		HelpID: "listspellshelp",
		Flags:  console.ClientServer,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			const (
				allow    = "ok"
				disallow = "X"
				invalid  = "INVALID"
			)
			for i, sp := range SpellDefs() {
				mana := sp.ManaCost()
				title := sp.Title()
				ind := i + 1
				id := things.SpellIDByIndex(ind)
				astr := disallow
				if !sp.Valid() {
					astr = invalid
				} else if sp.Allowed() {
					astr = allow
				}
				c.Printf(console.ColorRed, "%3d\t%-40.40s\t%-40.40q\tcost: %-3d\t%-8s", ind, id, title, mana, astr)
			}
			return true
		},
	})
}
