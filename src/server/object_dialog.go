package server

import "strings"

var dialogTypes = []struct {
	Name  string
	Flags DialogFlags
}{
	{Name: "NORMAL", Flags: 0x0},
	{Name: "YESNO", Flags: 0x1},
	{Name: "NEXT", Flags: 0x2},
	{Name: "YESNONEXT", Flags: 0x3},
}

type DialogFlags uint32

func ParseDialogFlags(name string) DialogFlags {
	name = strings.ToUpper(name)
	for _, v := range dialogTypes {
		if v.Name == name {
			return v.Flags
		}
	}
	return 0
}
