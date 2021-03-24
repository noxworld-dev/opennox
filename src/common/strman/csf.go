package strman

import (
	"encoding/binary"
	"fmt"
	"io"
	"strings"
	"unicode/utf16"

	"nox/common/fs"
)

func (sm *StringManager) ReadCSF(path string) error {
	f, err := fs.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()

	var buf [24]byte
	if _, err := io.ReadFull(f, buf[:]); err != nil {
		return fmt.Errorf("cannot read header: %w", err)
	}
	if magic := reverse4s(buf[0:4]); magic != "CSF " {
		return fmt.Errorf("invalid file header: %q", magic)
	}
	vers := binary.LittleEndian.Uint32(buf[4:8])
	cntEnt := binary.LittleEndian.Uint32(buf[8:12])
	cntVar := binary.LittleEndian.Uint32(buf[12:16])
	if vers < 2 {
		sm.lang = 0
		_, err = f.Seek(20, io.SeekStart)
	} else {
		sm.lang = int(binary.LittleEndian.Uint32(buf[20:24]))
		_, err = f.Seek(24, io.SeekStart)
	}
	sm.entries = make([]Entry, 0, cntEnt)
	variants := make([]Variant, 0, cntVar)
	for {
		_, err := io.ReadFull(f, buf[:12])
		if err == io.EOF {
			break
		} else if err != nil {
			return err
		}
		if sect := reverse4s(buf[:4]); sect != "LBL " {
			return fmt.Errorf("invalid section header: %q", sect)
		}
		varN := int(binary.LittleEndian.Uint32(buf[4:8]))
		var name []byte
		if sz := binary.LittleEndian.Uint32(buf[8:12]); sz > 0 {
			name = make([]byte, sz)
			if _, err := io.ReadFull(f, name); err != nil {
				return err
			}
		}
		i := len(sm.entries)
		sm.entries = append(sm.entries, Entry{ID: ID(name)})
		ent := &sm.entries[i]
		vi := len(variants)
		for j := 0; j < varN; j++ {
			if _, err := io.ReadFull(f, buf[:8]); err != nil {
				return err
			}
			sect := strings.ToLower(reverse4s(buf[:4]))
			switch sect {
			default:
				return fmt.Errorf("invalid section: %q", sect)
			case "str ", "strw":
			}
			var wstr []byte
			if wsz := binary.LittleEndian.Uint32(buf[4:8]); wsz > 0 {
				wstr = make([]byte, wsz*2)
				if _, err := io.ReadFull(f, wstr); err != nil {
					return err
				}
			}
			str := bytes2utf16(wstr)
			invertUTF16(str)
			str = filterSpaces(str)
			r := Variant{Str: string(utf16.Decode(str))}
			if sect == "strw" {
				if _, err := io.ReadFull(f, buf[:4]); err != nil {
					return err
				}
				if sz := binary.LittleEndian.Uint32(buf[0:4]); sz > 0 {
					str := make([]byte, sz)
					if _, err := io.ReadFull(f, str); err != nil {
						return err
					}
					r.Str2 = string(str)
				}
			}
			variants = append(variants, r)
		}
		ent.Vals = variants[vi : vi+varN : vi+varN]
	}
	return sm.indexEntries()
}
