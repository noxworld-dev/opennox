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
	Field0    uint32                // 0, 0 (36)
	group     int32                 // 1, 4 (40)
	Style     StyleFlags            // 2, 8 (44)
	Status    StatusFlags           // 3, 12 (48)
	Window    *Window               // 4, 16 (52)
	bgColor   uint32                // 5, 20 (56)
	bgImage   noxrender.ImageHandle // 6, 24 (60)
	enColor   uint32                // 7, 28 (64)
	enImage   noxrender.ImageHandle // 8, 32 (68)
	hlColor   uint32                // 9, 36 (72)
	hlImage   noxrender.ImageHandle // 10, 40 (76)
	disColor  uint32                // 11, 44 (80)
	disImage  noxrender.ImageHandle // 12, 48 (84)
	selColor  uint32                // 13, 52 (88)
	selImage  noxrender.ImageHandle // 14, 56 (92)
	imgPt     image.Point           // 15, 60 (96)
	textColor uint32                // 17, 68 (104)
	text      [64]uint16            // 18, 72 (108)
	font      unsafe.Pointer        // 50, 200 (236)
	tooltip   [64]uint16            // 51, 204 (240)
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
	return int(d.group)
}

func (d *WindowData) SetGroup(v int) {
	d.group = int32(v)
}

func (d *WindowData) Text() string {
	n := alloc.StrLenS(d.text[:])
	return string(utf16.Decode(d.text[:n]))
}

func (d *WindowData) Tooltip() string {
	n := alloc.StrLenS(d.tooltip[:])
	return string(utf16.Decode(d.tooltip[:n]))
}

func (d *WindowData) SetText(s string) {
	alloc.StrCopyZero16(d.text[:], s)
}

func (d *WindowData) SetTooltip(sm *strman.StringManager, s string) {
	n := alloc.StrCopyZero16(d.tooltip[:], s)
	if n >= len(d.tooltip) && sm != nil {
		alloc.StrCopyZero16(d.tooltip[:], sm.GetStringInFile("TooltipTooLong", "gamewin.c"))
	}
}

func (d *WindowData) BackgroundColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.bgColor >> 16)
}

func (d *WindowData) SetBackgroundColor(cl color.Color) {
	d.bgColor = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) EnabledColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.enColor >> 16)
}

func (d *WindowData) SetEnabledColor(cl color.Color) {
	d.enColor = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) DisabledColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.disColor >> 16)
}

func (d *WindowData) SetDisabledColor(cl color.Color) {
	d.disColor = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) HighlightColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.hlColor >> 16)
}

func (d *WindowData) SetHighlightColor(cl color.Color) {
	d.hlColor = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) SelectedColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.selColor >> 16)
}

func (d *WindowData) SetSelectedColor(cl color.Color) {
	d.selColor = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) TextColor() noxcolor.Color16 {
	return noxcolor.RGBA5551(d.textColor >> 16)
}

func (d *WindowData) SetTextColor(cl color.Color) {
	d.textColor = noxcolor.ToRGBA5551Color(cl).Color32()
}

func (d *WindowData) BackgroundImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.bgImage)
}

func (d *WindowData) SetBackgroundImage(p *noxrender.Image) {
	d.bgImage = p.C()
}

func (d *WindowData) EnabledImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.enImage)
}

func (d *WindowData) SetEnabledImage(p *noxrender.Image) {
	d.enImage = p.C()
}

func (d *WindowData) DisabledImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.disImage)
}

func (d *WindowData) SetDisabledImage(p *noxrender.Image) {
	d.disImage = p.C()
}

func (d *WindowData) HighlightImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.hlImage)
}

func (d *WindowData) SetHighlightImage(p *noxrender.Image) {
	d.hlImage = p.C()
}

func (d *WindowData) SelectedImage() *noxrender.Image {
	return d.gui().r.Bag.AsImage(d.selImage)
}

func (d *WindowData) SetSelectedImage(p *noxrender.Image) {
	d.selImage = p.C()
}

func (d *WindowData) FontC() unsafe.Pointer {
	return d.font
}

func (d *WindowData) SetFont(font unsafe.Pointer) {
	d.font = font
}

func (d *WindowData) ImagePoint() image.Point {
	return d.imgPt
}

func (d *WindowData) SetImagePoint(p image.Point) {
	d.imgPt = p
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
	return d.gui().r.Fonts.AsFont(d.font)
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
