package opennox

/*
#include "GAME1.h"
#include "GAME1_1.h"
*/
import "C"
import (
	"context"
	"fmt"
	"strings"

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/maps"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var noxMapsIgnoreMode = false

var noxCmdSetMaps = &console.Command{
	Token: "maps",
	Help:  "set map-related variables",
	Flags: console.Server | console.Cheat,
}

func init() {
	noxConsole.Register(&console.Command{
		Token:  "load",
		HelpID: "loadhelp",
		Flags:  console.Server | console.Cheat,
		Func:   noxCmdLoad,
	})
	noxCmdSet.Register(noxCmdSetMaps)
	noxCmdSetMaps.Register(&console.Command{
		Token: "allow.all",
		Help:  "ignore all map mode checks when using load command",
		Flags: console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(allow bool) {
				noxMapsIgnoreMode = allow
				if allow {
					c.Print(console.ColorLightYellow, "any map can be loaded now")
					c.Print(console.ColorLightRed, "the game and the menu may act weirdly in this mode")
				} else {
					c.Print(console.ColorLightYellow, "maps loading will check game mode")
				}
			})
		},
	})
}

func noxCmdLoad(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	if !noxMapsIgnoreMode && noxflags.HasGame(noxflags.GameModeQuest) {
		c.Printf(console.ColorRed, "Switching maps is not allowed in Quest")
		return true
	}
	name := tokens[0]
	if len(name) != 0 && name[0] != '#' {
		if err := nox_common_checkMapFile(name); err != nil {
			c.Printf(console.ColorRed, "Error checking map file %q: %v", name, err)
			return true
		}
	}
	mode := nox_xxx_mapGetTypeMB_4CFFA0(memmap.PtrOff(0x973F18, 2408))
	if noxflags.HasGame(noxflags.GameOnline) {
		if !noxMapsIgnoreMode && (mode == 0 || mode.Has(noxflags.GameModeSolo10)) {
			c.Printf(console.ColorRed, "Switching maps to Solo is not allowed")
			return true
		}
		if noxflags.HasGame(noxflags.GameModeChat) {
			if mode.Has(noxflags.GameModeCTF|noxflags.GameModeFlagBall) && nox_xxx_getTeamCounter_417DD0() != 2 {
				C.nox_xxx_wndGuiTeamCreate_4185B0()
			}
		} else if !noxflags.GetGame().Has(mode) {
			v6 := strMan.GetStringInFile("NoMapLoadNewMode", "parsecmd.c")
			nox_xxx_printCentered_445490(v6)
			return true
		}
	} else {
		if !noxMapsIgnoreMode && !mode.Has(noxflags.GameModeSolo10) {
			c.Printf(console.ColorRed, "Switching to non-Solo maps is not allowed")
			return true
		}
	}
	fname := name
	if !strings.HasSuffix(fname, maps.Ext) {
		fname = name + maps.Ext
	} else {
		fname = name
	}
	if fname == "" || fname[0] != '#' {
		if _, err := ifs.Stat(datapath.Maps(name, fname)); err != nil {
			str := strMan.GetStringInFile("CannotAccessMap", "parsecmd.c")
			nox_xxx_printCentered_445490(fmt.Sprintf(str, fname))
			return true
		}
	}
	nox_xxx_mapLoadOrSaveMB_4DCC70(1)
	noxServer.switchMap(fname)
	C.sub_41D650()
	str := strMan.GetStringInFile("maploaded", "parsecmd.c")
	nox_xxx_printCentered_445490(fmt.Sprintf(str, fname))
	return true
}
