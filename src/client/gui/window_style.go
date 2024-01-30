package gui

import (
	"image"
	"image/color"
	"unicode/utf16"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/strman"
	"golang.org/x/image/font"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

func NewWindowData() (*WindowData, func()) {
	d, free := alloc.New(WindowData{})
	d.SetHighlightColor(noxcolor.RGB5551Color(255, 255, 255))
	d.SetTextColor(noxcolor.RGB5551Color(200, 200, 200))
	d.SetEnabledColor(color.Transparent)
	d.SetDisabledColor(color.Transparent)
	d.SetSelectedColor(color.Transparent)
	d.SetBackgroundColor(color.Transparent)
	return d, free
}

type WindowData struct {
	Field0       uint32                // 0, 0 (36)
	GroupVal     int32                 // 1, 4 (40)
	Style        StyleFlags            // 2, 8 (44)
	Status       StatusFlags           // 3, 12 (48)
	Window       *Window               // 4, 16 (52)
	BgColorVal   uint32                // 5, 20 (56)
	BgImageHnd   noxrender.ImageHandle // 6, 24 (60)
	EnColorVal   uint32                // 7, 28 (64)
	EnImageHnd   noxrender.ImageHandle // 8, 32 (68)
	HlColorVal   uint32                // 9, 36 (72)
	HlImageHnd   noxrender.ImageHandle // 10, 40 (76)
	DisColorVal  uint32                // 11, 44 (80)
	DisImageHnd  noxrender.ImageHandle // 12, 48 (84)
	SelColorVal  uint32                // 13, 52 (88)
	SelImageHnd  noxrender.ImageHandle // 14, 56 (92)
	ImgPtVal     image.Point           // 15, 60 (96)
	TextColorVal uint32                // 17, 68 (104)
	TextBuf      [64]uint16            // 18, 72 (108)
	FontPtr      unsafe.Pointer        // 50, 200 (236)
	TooltipBuf   [64]uint16            // 51, 204 (240)
}

func (d *WindowData) C() unsafe.Pointer {
	return unsafe.Pointer(d)
}

func (d *WindowData) Field0Set(flag uint32, v bool) {
	if v {
		d.Field0 |= flag
	} else {
		d.Field0 &^= flag
	}
}

func (d *WindowData) Group() int {
	return int(d.GroupVal)
}

func (d *WindowData) SetGroup(v int) {
	d.GroupVal = int32(v)
}

func (d *WindowData) Text() string {
	n := alloc.StrLenS(d.TextBuf[:])
	return string(utf16.Decode(d.TextBuf[:n]))
}

func (d *WindowData) Tooltip() string {
	n := alloc.StrLenS(d.TooltipBuf[:])
	return string(utf16.Decode(d.TooltipBuf[:n]))
}

func (d *WindowData) SetText(s string) {
	alloc.StrCopyZero16(d.TextBuf[:], s)
}

func (d *WindowData) SetTooltip(sm *strman.StringManager, s string) {
	n := alloc.StrCopyZero16(d.TooltipBuf[:], s)
	if n >= len(d.TooltipBuf) && sm != nil {
		alloc.StrCopyZero16(d.TooltipBuf[:], sm.GetStringInFile("TooltipTooLong", "gamewin.c"))
	}
}

func (d *WindowData) BackgroundColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.BgColorVal >> 16)
}

func (d *WindowData) SetBackgroundColor(cl color.Color) {
	d.BgColorVal = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) EnabledColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.EnColorVal >> 16)
}

func (d *WindowData) SetEnabledColor(cl color.Color) {
	d.EnColorVal = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) DisabledColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.DisColorVal >> 16)
}

func (d *WindowData) SetDisabledColor(cl color.Color) {
	d.DisColorVal = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) HighlightColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.HlColorVal >> 16)
}

func (d *WindowData) SetHighlightColor(cl color.Color) {
	d.HlColorVal = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) SelectedColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.SelColorVal >> 16)
}

func (d *WindowData) SetSelectedColor(cl color.Color) {
	d.SelColorVal = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) TextColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.TextColorVal >> 16)
}

func (d *WindowData) SetTextColor(cl color.Color) {
	d.TextColorVal = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) BackgroundImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.BgImageHnd)
}

func (d *WindowData) SetBackgroundImage(p *noxrender.Image) {
	d.BgImageHnd = p.C()
}

func (d *WindowData) EnabledImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.EnImageHnd)
}

func (d *WindowData) SetEnabledImage(p *noxrender.Image) {
	d.EnImageHnd = p.C()
}

func (d *WindowData) DisabledImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.DisImageHnd)
}

func (d *WindowData) SetDisabledImage(p *noxrender.Image) {
	d.DisImageHnd = p.C()
}

func (d *WindowData) HighlightImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.HlImageHnd)
}

func (d *WindowData) SetHighlightImage(p *noxrender.Image) {
	d.HlImageHnd = p.C()
}

func (d *WindowData) SelectedImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.SelImageHnd)
}

func (d *WindowData) SetSelectedImage(p *noxrender.Image) {
	d.SelImageHnd = p.C()
}

func (d *WindowData) FontC() unsafe.Pointer {
	return d.FontPtr
}

func (d *WindowData) SetFont(font unsafe.Pointer) {
	d.FontPtr = font
}

func (d *WindowData) ImagePoint() image.Point {
	return d.ImgPtVal
}

func (d *WindowData) SetImagePoint(p image.Point) {
	d.ImgPtVal = p
}

func (d *WindowData) SetDefaults(def StyleDefaults) {
	d.SetEnabledColor(def.EnabledColor)
	d.SetHighlightColor(def.HighlightColor)
	d.SetDisabledColor(def.DisabledColor)
	d.SetBackgroundColor(def.BackgroundColor)
	d.SetSelectedColor(def.SelectedColor)
	d.SetTextColor(def.TextColor)
}

func (d *WindowData) Font() font.Face {
	return d.gui().r.Fonts.AsFont(d.FontPtr)
}

type Borders struct {
	CornerUL        *noxrender.Image
	CornerUR        *noxrender.Image
	CornerLL        *noxrender.Image
	CornerLR        *noxrender.Image
	Horizontal      *noxrender.Image
	HorizontalShort *noxrender.Image
	Vertical        *noxrender.Image
	VerticalShort   *noxrender.Image
}
