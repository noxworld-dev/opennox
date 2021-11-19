package nox

/*
#include <stdint.h>
void* nox_xxx_FontLoadFile_43F3B0(char* a1);
void nox_xxx_FontDestroy_43F2E0();

extern uint32_t dword_5d4594_816440;
extern uint32_t dword_5d4594_816444;
extern uint32_t dword_5d4594_816452;
extern unsigned int dword_5d4594_816456;
extern unsigned int dword_5d4594_816460;
extern void* nox_draw_defaultFont_816492;
*/
import "C"
import (
	"fmt"
	"strings"
	"unsafe"

	"golang.org/x/image/font"
	"golang.org/x/image/font/opentype"

	"nox/v1/client/noxfont"
	"nox/v1/common/datapath"
	"nox/v1/common/fs"
	"nox/v1/common/memmap"
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
	noxFontByName = make(map[string]*fontFile)
	noxFontByPtr  = make(map[unsafe.Pointer]*fontFile)
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
		fnt, err := loadFont(datapath.Path(fname), f.Size)
		if err != nil {
			return err
		}
		f.Font = fnt
		f.Ptr = C.nox_xxx_FontLoadFile_43F3B0(internCStr(fname + noxfont.Ext))
		if f.Ptr == nil {
			return fmt.Errorf("failed to level legacy font: %q", f.Name)
		}
		noxFontByPtr[f.Ptr] = f
	}
	nox_xxx_fontLoadMB_43F1C0()
	return nil
}

func nox_xxx_fontLoadMB_43F1C0() {
	C.dword_5d4594_816440 = 1
	C.dword_5d4594_816444 = 0
	C.dword_5d4594_816452 = 0
	C.dword_5d4594_816456 = 64
	C.dword_5d4594_816460 = 0
	v1 := unsafe.Slice((*uint32)(memmap.PtrOff(0x5D4594, 816464)), 5)
	for i := range v1 {
		v1[i] = 0
	}
	*memmap.PtrUint32(0x5D4594, 816484) = 1
	C.nox_draw_defaultFont_816492 = guiFontPtrByName(noxfont.DefaultName)
}

func nox_xxx_FontDestroy_43F2E0() {
	C.nox_xxx_FontDestroy_43F2E0()
}

func loadFont(path string, size int) (font.Face, error) {
	if f, err := fs.Open(path + ".ttf"); err == nil {
		fnt, err := opentype.ParseReaderAt(f)
		if err != nil {
			return nil, err
		}
		face, err := opentype.NewFace(fnt, &opentype.FaceOptions{
			Size: float64(size), DPI: 72,
			Hinting: font.HintingNone,
		})
		if err != nil {
			return nil, err
		}
		return face, nil
	}
	f, err := fs.Open(path + noxfont.Ext)
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

func guiFontPtrByName(name string) unsafe.Pointer {
	name = strings.ToLower(name)
	f := noxFontByName[name]
	if f == nil {
		guiLog.Printf("font not found: %q", name)
		return nil
	}
	return f.Ptr
}

func fontFaceByPtr(ptr unsafe.Pointer) font.Face {
	if ptr == nil {
		return nil
	}
	return noxFontByPtr[ptr].Font
}
