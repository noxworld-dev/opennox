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

func ReadMap(dir string) (*Map, error) {
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
	err = r.ReadSections()
	m := r.Map()
	if m != nil {
		m.Info.Filename = name
		m.Info.Size = int(fi.Size())
	}
	return m, err
}
