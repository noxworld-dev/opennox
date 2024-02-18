package client

import (
	"image/color"
	"unsafe"
)

type clientDrawablesExt struct {
	c         *clientDrawables
	byPtr     map[unsafe.Pointer]*DrawableExt
	byNetCode map[int]*DrawableExtData
}

func (c *clientDrawablesExt) init(cli *clientDrawables) {
	c.c = cli
	c.byPtr = make(map[unsafe.Pointer]*DrawableExt)
	c.byNetCode = make(map[int]*DrawableExtData)
}

func (c *clientDrawablesExt) free() {
	c.byPtr = nil
	c.byNetCode = nil
}

func (c *clientDrawablesExt) GetByNetCode(code int) *DrawableExtData {
	return c.byNetCode[code&0x7FFF]
}

func (c *clientDrawablesExt) SetByNetCode(code int) *DrawableExtData {
	netcode := code & 0x7FFF
	data := c.byNetCode[netcode]
	if data == nil {
		data = new(DrawableExtData)
		c.byNetCode[netcode] = data
		if dr := c.c.ByNetCode(uint16(code)); dr != nil {
			dr.SetExt().Data = data
		}
	}
	return data
}

func (c *clientDrawablesExt) Attach(dr *Drawable) {
	data := c.GetByNetCode(int(dr.NetCode32))
	if data == nil {
		return
	}
	ext := dr.SetExt()
	ext.Data = data
}

func (c *clientDrawablesExt) Delete(dr *Drawable) {
	delete(c.byNetCode, int(dr.NetCode32&0x7FFF))
}

func (s *Drawable) GetExt() *DrawableExt {
	if s == nil {
		return nil
	}
	return s.Client().Objs.Ext.byPtr[unsafe.Pointer(s)]
}

func (s *Drawable) SetExt() *DrawableExt {
	if s == nil {
		return nil
	}
	cli := s.Client()
	p := cli.Objs.Ext.byPtr[unsafe.Pointer(s)]
	if p == nil {
		p = new(DrawableExt)
		cli.Objs.Ext.byPtr[unsafe.Pointer(s)] = p
	}
	return p
}

type DrawableExt struct {
	Field99 **Drawable
	Data    *DrawableExtData
}

type DrawableExtData struct {
	DisplayName      string
	DisplayNameColor color.Color
}
