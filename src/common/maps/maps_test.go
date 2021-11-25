package maps

import (
	"io"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/fs"
	"nox/v1/common/noxtest"
)

var casesMapInfo = []Info{
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
	path := noxtest.DataPath(t, Dir)
	for _, m := range casesMapInfo {
		t.Run(m.Filename, func(t *testing.T) {
			info, err := ReadMapInfo(filepath.Join(path, m.Filename))
			require.NoError(t, err)
			require.Equal(t, m, *info)
		})
	}
}

func TestReadFile(t *testing.T) {
	path := noxtest.DataPath(t, Dir)
	for _, m := range casesMapInfo {
		t.Run(m.Filename, func(t *testing.T) {
			f, err := fs.Open(filepath.Join(path, m.Filename, m.Filename+Ext))
			require.NoError(t, err)
			defer f.Close()
			r, err := NewReader(f)
			require.NoError(t, err)
			err = r.ReadSections()
			off, _ := f.Seek(0, io.SeekCurrent)
			require.NoError(t, err, "off: %d (0x%x)", off, off)
		})
	}
}
