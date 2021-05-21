package maps

import (
	"bufio"
	"bytes"
	"encoding/binary"
	"fmt"
	"io"
	"log"
	"os"
	"path/filepath"
	"sort"
	"strings"

	"nox/v1/common/crypt"
	"nox/v1/common/fs"
)

var (
	Log = log.New(os.Stderr, "[map]: ", log.LstdFlags|log.Lmsgprefix)
)

const (
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
	Field11       byte   `json:",omitempty"`               // 1396
	Field12       byte   `json:",omitempty"`               // 1397
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

	r, err := crypt.NewReader(rc, crypt.MapKey)
	if err != nil {
		return nil, err
	}
	var buf [32]byte
	if _, err := io.ReadFull(r, buf[:4]); err != nil {
		return nil, fmt.Errorf("cannot read magic: %w", err)
	}
	magic := binary.LittleEndian.Uint32(buf[:4])
	var crc uint32
	switch magic {
	case 0xFADEBEEF:
		// nop
	case 0xFADEFACE:
		if n, err := r.ReadAligned(buf[:4]); err != nil {
			return nil, fmt.Errorf("cannot read crc: %w", err)
		} else if n != 4 {
			err = io.ErrUnexpectedEOF
			return nil, fmt.Errorf("cannot read crc: %w", err)
		}
		crc = binary.LittleEndian.Uint32(buf[:4])
	default:
		return nil, fmt.Errorf("invalid magic: 0x%x", magic)
	}
	_ = crc
	if _, err := io.ReadFull(r, buf[:32]); err != nil {
		return nil, fmt.Errorf("cannot read header: %w", err)
	}
	info, err := ReadInfo(r)
	if info != nil {
		info.Filename = name
		info.Size = int(fi.Size())
	}
	return info, err
}

func ReadInfo(r io.Reader) (*Info, error) {
	var buf [512]byte
	br := bufio.NewReader(r)
	if _, err := io.ReadFull(br, buf[:2]); err != nil {
		return nil, fmt.Errorf("cannot read info version: %w", err)
	}
	vers := binary.LittleEndian.Uint16(buf[:2])
	info := &Info{Format: int(vers)}
	if vers > 3 {
		return info, fmt.Errorf("unsupported version: %d", vers)
	}
	readString := func(p *string, buf []byte) error {
		if _, err := io.ReadFull(br, buf); err != nil {
			return fmt.Errorf("cannot read info: %w", err)
		}
		i := bytes.IndexByte(buf, 0)
		if i >= 0 {
			buf = buf[:i]
		}
		*p = string(buf)
		return nil
	}
	readString8 := func(p *string) error {
		if _, err := io.ReadFull(br, buf[:1]); err != nil {
			return fmt.Errorf("cannot read info: %w", err)
		}
		n := buf[0]
		str := make([]byte, n)
		if _, err := io.ReadFull(br, str); err != nil {
			return fmt.Errorf("cannot read info: %w", err)
		}
		*p = string(str)
		return nil
	}
	if vers >= 1 {
		for _, f := range []struct {
			p   *string
			max int
		}{
			{&info.Summary, 64},
			{&info.Description, 512},
			{&info.Version, 16},
			{&info.Author, 64},
			{&info.Email, 64},
			{&info.Author2, 128},
			{&info.Email2, 128},
			{&info.Field7, 256},
			{&info.Copyright, 128},
			{&info.Date, 32},
		} {
			if err := readString(f.p, buf[:f.max]); err != nil {
				return info, err
			}
		}
		if _, err := io.ReadFull(br, buf[:4]); err != nil {
			return nil, fmt.Errorf("cannot read info: %w", err)
		}
		info.Flags = binary.LittleEndian.Uint32(buf[:4])
		if vers == 2 {
			if _, err := io.ReadFull(br, buf[:2]); err != nil {
				return nil, fmt.Errorf("cannot read info: %w", err)
			}
			info.Field11 = buf[0]
			info.Field12 = buf[1]
		} else {
			info.Field11 = 2
			info.Field12 = 16
		}
	}
	if vers < 3 {
		return info, nil
	}
	if err := readString8(&info.QuestIntro); err != nil {
		return nil, err
	}
	if err := readString8(&info.QuestGraphics); err != nil {
		return nil, err
	}
	return info, nil
}
