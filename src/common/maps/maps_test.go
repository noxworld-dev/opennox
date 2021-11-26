package maps_test

import (
	"bytes"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/maps"
	"nox/v1/common/noxtest"
	"nox/v1/server/script/noxscript"
)

var casesMapInfo = []maps.Info{
	{
		Filename:    "con01a",
		Size:        167256,
		Format:      2,
		Summary:     "Second Warrior Mission ",
		Description: "Town of Ix\t",
		Author:      "Bryan Hansen/John Lee",
		Email:       "bhansen@westwood.com",
		Date:        "Friday, January 7 2000",
		Flags:       0x3,
		MinPlayers:  2,
		MaxPlayers:  16,
	},
	{
		Filename:    "estate",
		Size:        59064,
		Format:      2,
		Summary:     "Death Match suitable for 2 - 8 players",
		Description: "Outdoor woodland setting for killer Deathmatches",
		Version:     "2.1",
		Author:      "Bryan Hansen",
		Copyright:   "Copyright 1999 Westwood Studios.  All rights reserved.",
		Date:        "Monday, January 3 2000",
		Flags:       0x34,
		MinPlayers:  2,
		MaxPlayers:  8,
	},
	{
		Filename:      "g_castle",
		Size:          475264,
		Format:        3,
		Author:        "John Lee/Bryan Hansen",
		Author2:       "Phil Robb",
		Date:          "Monday, July 17 2000",
		Flags:         0x2,
		MinPlayers:    2,
		MaxPlayers:    16,
		QuestIntro:    "QIntro.dat:GauntletCastleText",
		QuestGraphics: "WizardChapterBegin2",
	},
	{
		Filename:      "g_mines",
		Size:          652432,
		Format:        3,
		Author:        "John Lee",
		Author2:       "Phil Robb",
		Date:          "Tuesday, July 18 2000",
		Flags:         0x2,
		MinPlayers:    2,
		MaxPlayers:    16,
		QuestIntro:    "QIntro.dat:GauntletMinesText",
		QuestGraphics: "WarriorChapterBegin8",
	},
	{
		Filename:    "so_brin",
		Size:        12368,
		Format:      2,
		Summary:     "Brin Social Map",
		Description: "Social map set in Brin Farm",
		Author:      "Jeremiah Cohn",
		Date:        "Monday, January 3 2000",
		Flags:       0x80000000,
		MinPlayers:  2,
		MaxPlayers:  16,
	},
}

func TestReadFileInfo(t *testing.T) {
	path := noxtest.DataPath(t, maps.Dir)
	for _, m := range casesMapInfo {
		t.Run(m.Filename, func(t *testing.T) {
			info, err := maps.ReadMapInfo(filepath.Join(path, m.Filename))
			require.NoError(t, err)
			require.Equal(t, m, *info)
		})
	}
}

func TestReadFile(t *testing.T) {
	path := noxtest.DataPath(t, maps.Dir)
	for _, m := range casesMapInfo {
		t.Run(m.Filename, func(t *testing.T) {
			mp, err := maps.ReadMap(filepath.Join(path, m.Filename))
			require.NoError(t, err)
			for _, s := range mp.Unknown {
				t.Logf("unknwon section: %q [%d]", s.Name, len(s.Data))
			}
			if mp.Script != nil {
				if len(mp.Script.Data) == 0 {
					t.Logf("script [%d]", len(mp.Script.Data))
				} else {
					sc, err := noxscript.ReadScript(bytes.NewReader(mp.Script.Data))
					require.NoError(t, err)
					t.Logf("script [%d]: %d funcs, %d strings", len(mp.Script.Data), len(sc.Funcs), len(sc.Strings))
				}
			}
		})
	}
}
