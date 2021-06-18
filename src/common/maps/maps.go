package maps

import (
	"io"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"nox/v1/common/fs"
	"nox/v1/common/log"
)

var (
	Log = log.New("map")
)

const (
	Dir           = "maps"
	Ext           = ".map"
	SoloPrefixWar = "war"
	SoloPrefixWiz = "wiz"
	SoloPrefixCon = "con"
)

type MapItem struct {
	Field6 int
	Info
}

type MapList []Info

func (m *MapList) Sort() {
	list := *m
	sort.Slice(list, func(i, j int) bool {
		return list[i].Filename < list[j].Filename
	})
	*m = list
}

type MapItemList []MapItem

func (m *MapItemList) Sort() {
	list := *m
	sort.Slice(list, func(i, j int) bool {
		return list[i].Filename < list[j].Filename
	})
	*m = list
}

type ScanOptions struct {
	Solo bool // don't skip solo maps
}

func Scan(path string, opts *ScanOptions) (MapList, error) {
	if opts == nil {
		opts = &ScanOptions{}
	}
	dir, err := fs.Open(path)
	if err != nil {
		return nil, err
	}
	defer dir.Close()

	var (
		list MapList
		last error
	)
	for {
		page, err := dir.ReadDir(100)
		if err == io.EOF {
			break
		} else if err != nil {
			return list, err
		}
		for _, fi := range page {
			if !fi.IsDir() {
				continue
			}
			name := fi.Name()
			lname := strings.ToLower(name)
			if !opts.Solo && strings.HasPrefix(lname, SoloPrefixWar) || strings.HasPrefix(lname, SoloPrefixWiz) || strings.HasPrefix(lname, SoloPrefixCon) {
				continue
			}
			info, err := ReadMapInfo(filepath.Join(path, name))
			if os.IsNotExist(err) {
				continue
			} else if err != nil {
				Log.Printf("invalid map file: %q: %v", name, err)
				last = err
				continue
			}
			list = append(list, *info)
		}
	}
	list.Sort()
	return list, last
}

type Info struct {
	Filename      string `json:"name"`
	Size          int    `json:"size"`
	Format        int    `json:"format,omitempty"`
	Summary       string `json:"summary,omitempty"`        // 0 [64]
	Description   string `json:"description,omitempty"`    // 64 [512]
	Version       string `json:"version,omitempty"`        // 576 [16]
	Author        string `json:"author,omitempty"`         // 592 [64]
	Email         string `json:"email,omitempty"`          // 656 [64]
	Author2       string `json:"author_2,omitempty"`       // 720 [128]
	Email2        string `json:"email_2,omitempty"`        // 848 [128]
	Field7        string `json:",omitempty"`               // 976 [256]
	Copyright     string `json:"copyright,omitempty"`      // 1232 [128]
	Date          string `json:"date_str,omitempty"`       // 1360 [32]
	Flags         uint32 `json:"flags,omitempty"`          // 1392
	MinPlayers    byte   `json:"min_players,omitempty"`    // 1396
	MaxPlayers    byte   `json:"max_players,omitempty"`    // 1397
	QuestIntro    string `json:"quest_intro,omitempty"`    // 1398
	QuestGraphics string `json:"quest_graphics,omitempty"` // 1430
}

func ReadMapInfo(dir string) (*Info, error) {
	name := filepath.Base(dir)
	path := filepath.Join(dir, name+Ext)
	rc, err := fs.Open(path)
	if err != nil {
		return nil, err
	}
	defer rc.Close()

	fi, err := rc.Stat()
	if err != nil {
		return nil, err
	}

	r, err := NewReader(rc)
	if err != nil {
		return nil, err
	}

	info, err := r.ReadInfo()
	if info != nil {
		info.Filename = name
		info.Size = int(fi.Size())
	}
	return info, err
}
