package opennox

/*
#include "GAME1.h"
int sub_4AD840();
*/
import "C"
import (
	"context"
	"strings"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

func init() {
	noxCmdSet.Register(&console.Command{
		Token:  "armor",
		HelpID: "setarmorhelp",
		Flags:  console.Server,
		Func:   noxCmdSetArmor,
	})
	noxCmdSet.Register(&console.Command{
		Token:  "staff",
		HelpID: "setstaffhelp",
		Flags:  console.Server | console.Cheat,
		Func:   noxCmdSetStaff,
	})
	noxCmdSet.Register(&console.Command{
		Token:  "weapon",
		HelpID: "setweaponhelp",
		Flags:  console.Server,
		Func:   noxCmdSetWeapon,
	})
}

func noxCmdSetArmor(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 2 {
		return false
	}
	s := noxServer
	id := tokens[0]
	if noxflags.HasGame(noxflags.GameModeChat) {
		str := c.Strings().GetStringInFile("NotInChat", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return true
	}
	t := sub_415EF0(id)
	if t == nil {
		t = sub415EC0(id)
	}
	if t == nil {
		str := c.Strings().GetStringInFile("invalidarmor", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return false
	}
	switch strings.ToLower(tokens[1]) {
	case "on":
		if !s.getObjectTypeByInd(t.Ind()).Allowed() {
			s.enableObject(t)
			nox_server_gameSettingsUpdated_40A670()
			str := c.Strings().GetStringInFile("armorEnabled", "parsecmd.c")
			c.Printf(console.ColorRed, str, id)
		}
		return true
	case "off":
		if s.getObjectTypeByInd(t.Ind()).Allowed() {
			s.disableObject(t)
			s.deleteAllObjectsOfType(t)
			nox_server_gameSettingsUpdated_40A670()
			str := c.Strings().GetStringInFile("armorDisabled", "parsecmd.c")
			c.Printf(console.ColorRed, str, id)
		}
		return true
	}
	return false
}

func noxCmdSetStaff(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 2 {
		return false
	}
	s := noxServer
	id := tokens[0]
	t := s.getObjectTypeByID(id)
	if t == nil {
		str := c.Strings().GetStringInFile("invalidstaff", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return false
	}
	switch strings.ToLower(tokens[1]) {
	case "on":
		s.enableObject(t)
		str := c.Strings().GetStringInFile("staffEnabled", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return true
	case "off":
		s.disableObject(t)
		str := c.Strings().GetStringInFile("staffDisabled", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return true
	}
	return false
}

func noxCmdSetWeapon(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 2 {
		return false
	}
	s := noxServer
	id := tokens[0]
	if noxflags.HasGame(noxflags.GameModeChat) {
		str := c.Strings().GetStringInFile("NotInChat", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return true
	}
	if strings.ToLower(id) == "respawn" {
		switch sw := strings.ToLower(tokens[1]); sw {
		case "on":
			C.sub_409E70(2)
			str := c.Strings().GetStringInFile("weaponsrespawn", "parsecmd.c")
			c.Printf(console.ColorRed, str, sw)
			C.sub_4AD840()
			return true
		case "off":
			C.sub_409E70(2)
			str := c.Strings().GetStringInFile("weaponsrespawn", "parsecmd.c")
			c.Printf(console.ColorRed, str, sw)
			C.sub_4AD840()
			return true
		}
		return false
	}
	t := sub_415A60(id)
	if t == nil {
		t = sub415A30(id)
	}
	if t == nil {
		str := c.Strings().GetStringInFile("invalidweapon", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return false
	}
	switch strings.ToLower(tokens[1]) {
	case "on":
		if s.getObjectTypeByInd(t.Ind()).Allowed() {
			return true
		}
		s.enableObject(t)
		nox_server_gameSettingsUpdated_40A670()
		str := c.Strings().GetStringInFile("weaponEnabled", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return true
	case "off":
		if !s.getObjectTypeByInd(t.Ind()).Allowed() || C.nox_xxx_ammoCheck_415880(C.ushort(t.Ind())) == 1 {
			return true
		}
		s.disableObject(t)
		s.deleteAllObjectsOfType(t)
		nox_server_gameSettingsUpdated_40A670()
		str := c.Strings().GetStringInFile("weaponDisabled", "parsecmd.c")
		c.Printf(console.ColorRed, str, id)
		return true
	}
	return false
}

func sub_415A60(id string) *ObjectType {
	v1 := C.sub_415960(internWStr(id))
	if v1 == 0 {
		return nil
	}
	v2 := C.sub_415840(v1)
	if v2 == 0 {
		return nil
	}
	return noxServer.getObjectTypeByInd(int(v2))
}

func sub415A30(a1 string) *ObjectType {
	v1 := C.sub_415910(internCStr(a1))
	if v1 == 0 {
		return nil
	}
	v2 := C.sub_415840(v1)
	if v2 == 0 {
		return nil
	}
	return noxServer.getObjectTypeByInd(int(v2))
}

func sub_415EF0(id string) *ObjectType {
	v1 := C.sub_415DA0(internWStr(id))
	if v1 == 0 {
		return nil
	}
	v2 := C.sub_415CD0(v1)
	if v2 == 0 {
		return nil
	}
	return noxServer.getObjectTypeByInd(int(v2))
}

func sub415EC0(id string) *ObjectType {
	v1 := C.sub_415DF0(internCStr(id))
	if v1 == 0 {
		return nil
	}
	v2 := C.sub_415CD0(v1)
	if v2 == 0 {
		return nil
	}
	return noxServer.getObjectTypeByInd(int(v2))
}
