package nox

import (
	"nox/v1/client/system/parsecmd"
	"nox/v1/common/things"
)

func init() {
	noxCmdList.Sub = append(noxCmdList.Sub,
		&parsecmd.Command{Token: "spells", HelpID: "listspellshelp", Flags: parsecmd.ClientServer, Func: func(c *parsecmd.Console, tokens []string) bool {
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
				c.Printf(parsecmd.ColorRed, "%3d\t%-40.40s\t%-40.40q\tcost: %-3d\t%-8s", ind, id, title, mana, astr)
			}
			return true
		}},
	)
}
