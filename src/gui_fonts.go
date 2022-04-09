package opennox

/*
#include <stdint.h>

extern uint32_t dword_5d4594_816444;
*/
import "C"
import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"unsafe"

	"golang.org/x/image/font"
	"golang.org/x/image/font/opentype"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxfont"

	"github.com/noxworld-dev/opennox/v1/common/alloc/handles"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

type fontFile struct {
	Name    string
	File    string
	FileAlt string
	Size    int
	Font    font.Face
	Ptr     unsafe.Pointer
}

var (
	noxFontFiles = []fontFile{
		{Name: noxfont.DefaultName, File: noxfont.DefaultFile, Size: 10},
		{Name: noxfont.LargeName, File: noxfont.LargeFile, FileAlt: noxfont.DefaultFile, Size: 16},
		{Name: noxfont.NumbersName, File: noxfont.NumbersFile, Size: 7},
		{Name: noxfont.SmallName, File: noxfont.SmallFile, Size: 9},
	}
	noxFontByName  = make(map[string]*fontFile)
	noxFontByPtr   = make(map[unsafe.Pointer]*fontFile)
	noxFontDefault font.Face
)

func loadGameFonts() error {
	for i := range noxFontFiles {
		f := &noxFontFiles[i]
		noxFontByName[f.Name] = f
		fname := f.File
		switch strMan.Lang() {
		case 6, 8:
			if f.FileAlt != "" {
				fname = f.FileAlt
			}
		}
		fnt, err := loadFont(datapath.Data(fname), f.Size)
		if err != nil {
			return fmt.Errorf("cannot load font: %w", err)
		}
		f.Font = fnt
		f.Ptr = handles.NewPtr()
		noxFontByPtr[f.Ptr] = f
	}
	nox_xxx_fontLoadMB_43F1C0()
	return nil
}

func nox_xxx_fontLoadMB_43F1C0() {
	C.dword_5d4594_816444 = 0
	v1 := unsafe.Slice((*uint32)(memmap.PtrOff(0x5D4594, 816464)), 5)
	for i := range v1 {
		v1[i] = 0
	}
	noxFontDefault = guiFontByName(noxfont.DefaultName)
}

func nox_xxx_FontDestroy_43F2E0() {
	for i := range noxFontFiles {
		f := &noxFontFiles[i]
		if f.Font != nil {
			f.Font.Close()
			f.Font = nil
		}
		f.Ptr = nil
	}
}

func loadFont(path string, size int) (font.Face, error) {
	f, err := ifs.Open(path + ".ttf")
	if os.IsNotExist(err) {
		f, err = ifs.Open(path + ".otf")
	}
	if err == nil {
		fnt, err := opentype.ParseReaderAt(f)
		if err != nil {
			_ = f.Close()
			return nil, fmt.Errorf("%s: %w", filepath.Base(f.Name()), err)
		}
		face, err := opentype.NewFace(fnt, &opentype.FaceOptions{
			Size: float64(size), DPI: 72,
			Hinting: font.HintingNone,
		})
		if err != nil {
			_ = f.Close()
			return nil, err
		}
		// not closing the file, since it's still used by the font
		return face, nil
	}
	f, err = ifs.Open(path + noxfont.Ext)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	fnt, err := noxfont.Decode(f)
	if err != nil {
		return nil, err
	}
	return fnt, nil
}

//export nox_xxx_guiFontPtrByName_43F360
func nox_xxx_guiFontPtrByName_43F360(cname *C.char) unsafe.Pointer {
	name := GoString(cname)
	return guiFontPtrByName(name)
}

func guiFontByName(name string) font.Face {
	name = strings.ToLower(name)
	f := noxFontByName[name]
	if f == nil {
		guiLog.Printf("font not found: %q", name)
		return nil
	}
	return f.Font
}

func guiFontPtrByName(name string) unsafe.Pointer {
	name = strings.ToLower(name)
	f := noxFontByName[name]
	if f == nil {
		guiLog.Printf("font not found: %q", name)
		return nil
	}
	return f.Ptr
}

func asFont(ptr unsafe.Pointer) font.Face {
	if ptr == nil {
		return nil
	}
	fnt := noxFontByPtr[ptr]
	if fnt == nil {
		return nil
	}
	return fnt.Font
}
