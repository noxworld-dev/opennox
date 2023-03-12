//go:build !server

package opennox

import (
	"image"
	"image/color"
	"math"
	"sort"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (c *Client) nox_xxx_client_435F80_draw() bool {
	mpos := c.Inp.GetMousePos()
	if nox_xxx_serverIsClosing446180() {
		sub_446190()
	}
	if c.keyBindingsCheckActive() == 0 && !noxflags.HasGame(noxflags.GameFlag4) {
		nox_xxx_setContinueMenuOrHost_43DDD0(0)
		return false
	}
	legacy.Sub_437100()
	if legacy.Sub_478030() == 0 && nox_xxx_guiCursor_477600() == 0 {
		legacy.Sub_470DE0()
	}
	ctrlEvent.nox_xxx_input_42D220(c.Inp)
	if c.inDraw1 {
		c.inDraw1 = false
	}
	legacy.Nox_xxx_clientEnumHover_476FA0()
	if !c.clientSendInput(common.MaxPlayers - 1) {
		return true
	}
	vp := c.Viewport()
	ipos := vp.ToWorldPos(mpos)
	if !c.clientSendInputMouse(common.MaxPlayers-1, ipos) {
		return true
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		legacy.Sub_40B970()
		legacy.Sub_40B790()
	}
	if noxflags.HasGame(noxflags.GameHost) {
		legacy.Nox_xxx_spriteDeleteSomeList_49C4B0()
		if c.nox_netlist_receiveCli_494E90(common.MaxPlayers-1) == 0 {
			return true
		}
	} else {
		sub_43CCA0()
	}
	legacy.Sub_49BD70(vp)
	legacy.Sub_49BBC0()
	legacy.Nox_xxx_polygonDrawColor_421B80()
	if nox_client_isConnected() {
		legacy.Nox_xxx_cliToggleObsWindow_4357A0()
	}
	c.nox_xxx_clientDrawAll_436100_draw()
	c.sub_49BB40()
	c.sub_49BA70()
	c.maybeScreenshot()
	if memmap.Uint32(0x5D4594, 826068) != 0 {
		legacy.Nox_xxx_motd_4467F0()
	}
	if legacy.Sub_42EBA0() == 1 {
		legacy.Sub_42EB90(0)
		legacy.Nox_xxx_consoleEsc_49B7A0()
	}
	legacy.Sub_49B6E0()
	return memmap.Uint32(0x587000, 85720) != 0
}

func (c *Client) nox_xxx_clientDrawAll_436100_draw() {
	v0 := platformTicks()
	isTick := false
	if int(v0-memmap.Uint64(0x5D4594, 814532)) >= int(memmap.Int32(0x587000, 85748)) {
		isTick = true
		nox_ticks_reset_416D40()
	}
	if !(memmap.Uint32(0x587000, 85724) == 0 || isTick || !noxflags.HasGame(noxflags.GameHost) || nox_ticks_getNext() >= 0 ||
		nox_client_gui_flag_815132 != 0 || nox_xxx_checkGameFlagPause_413A50() || noxflags.HasEngine(noxflags.EngineNoRendering)) {
		noxflags.SetEngine(noxflags.EnginePause)
		return
	}
	noxflags.UnsetEngine(noxflags.EnginePause)
	*memmap.PtrUint64(0x5D4594, 814532) = v0
	*memmap.PtrUint32(0x5D4594, 811916) = c.srv.Frame()
	vp := c.Viewport()
	if memmap.Uint32(0x587000, 85744) != 0 {
		vp.Size.Y = vp.Size.X * nox_win_height / nox_win_width
		sx := (nox_win_width - vp.Size.X) / 2
		sy := (nox_win_height - vp.Size.Y) / 2
		vp.Screen.Min.X = sx
		vp.Screen.Min.Y = sy
		vp.Screen.Max.X = sx + vp.Size.X - 1
		vp.Screen.Max.Y = sy + vp.Size.Y - 1
	}
	legacy.Sub_430B50(vp.Screen.Min.X, vp.Screen.Min.Y, vp.Screen.Max.X, vp.Screen.Max.Y)
	if id := legacy.ClientPlayerNetCode(); id != 0 {
		*memmap.PtrPtr(0x852978, 8) = c.Objs.ByNetCodeDynamic(id).C()
	}
	if noxflags.HasEngine(noxflags.EngineNoRendering) {
		legacy.Nox_xxx_clientDrawAll_436100_draw_A()
	} else if memmap.Uint32(0x852978, 8) != 0 && nox_client_isConnected() {
		c.nox_xxx_drawAllMB_475810_draw(vp)
		legacy.Nox_xxx_drawMinimapAndLines_4738E0()
	} else {
		c.r.ClearScreen(color.Black)
	}
	c.DrawPerfmon(noxPerfmon)
	if legacy.Get_dword_5d4594_811904() != 0 {
		legacy.Sub_436F50()
	}
	if noxflags.HasGame(noxflags.GameFlag4) {
		v13 := platformTicks() - memmap.Uint64(0x5D4594, 811908)
		if v13 > 10000 && !noxflags.HasGame(noxflags.GameHost) {
			noxflags.UnsetGame(noxflags.GameFlag4)
		}
	}
	if noxflags.HasGame(noxflags.GameFlag4) {
		legacy.Nox_xxx_clientDrawAll_436100_draw_B()
	}
	if memmap.Uint32(0x587000, 85744) != 0 {
		legacy.Sub_430B50(0, 0, nox_win_width-1, nox_win_height-1)
		c.r.ClearScreen(color.Black)
		*memmap.PtrUint32(0x587000, 85744) = 0
	}
}

func (c *Client) sub_468F80(vp *noxrender.Viewport) {
	// TODO: values here are similar to lightGridW and lightGridH
	c.tiles.noxTilesGpx = (2*common.GridStep)*((int(vp.World.Min.X)+11)/(2*common.GridStep)-1) - 11
	c.tiles.noxTilesGpy = (2*common.GridStep)*((int(vp.World.Min.Y)+11)/(2*common.GridStep)) - 57
	legacy.Set_dword_5d4594_2650676(c.tiles.noxTilesGpx)
	legacy.Set_dword_5d4594_2650680(c.tiles.noxTilesGpy)
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		for i := 0; i < lightGridW; i++ {
			for j := 0; j < lightGridH; j++ {
				c.tiles.nox_arr2_853BC0[i][j].R = 255 << 16
				c.tiles.nox_arr2_853BC0[i][j].G = 255 << 16
				c.tiles.nox_arr2_853BC0[i][j].B = 255 << 16
			}
		}
	} else {
		cl := c.r.Data().GetLightColor()
		if legacy.Nox_xxx_get_57AF20() != 0 {
			cl = noxrender.RGB{R: 50, G: 50, B: 50}
		}
		for i := 0; i < lightGridW; i++ {
			for j := 0; j < lightGridH; j++ {
				c.tiles.nox_arr2_853BC0[i][j].R = cl.R << 16
				c.tiles.nox_arr2_853BC0[i][j].G = cl.G << 16
				c.tiles.nox_arr2_853BC0[i][j].B = cl.B << 16
			}
		}
		const add = 100
		padd := image.Pt(add, add)
		rect := image.Rectangle{
			Min: vp.World.Min.Sub(padd),
			Max: vp.World.Min.Add(vp.Size).Add(padd),
		}
		c.Objs.EachInRect(rect, c.nox_xxx_cliLight16_469140)
	}
}

func (c *Client) nox_xxx_drawAllMB_475810_draw(vp *noxrender.Viewport) {
	r := c.r
	c.nox_xxx_drawAllMB_475810_draw_A(vp)
	if vp.Field12 < 0 {
		vp.Field12 = -1 - vp.Field12
	} else if vp.Field12 > 0 {
		vp.Field12 = 1 - vp.Field12
	}
	partViewportOff = vp.ToWorldPos(image.Pt(0, 0))
	xmin := int(vp.World.Min.X) / common.GridStep
	ymin := int(vp.World.Min.Y) / common.GridStep
	nox_wallsYyy = nox_wallsYyy[:0]
	legacy.Nox_xxx_drawBlack_496150(vp)
	c.nox_xxx_drawBlack_496150_B()
	disableDraw := false
	if legacy.AsDrawableP(*memmap.PtrPtr(0x852978, 8)).HasEnchant(server.ENCHANT_BLINDED) || legacy.Get_nox_gameDisableMapDraw_5d4594_2650672() != 0 {
		disableDraw = true
	}
	if legacy.Get_nox_client_gui_flag_1556112() != 0 || disableDraw {
		r.ClearScreen(color.Black)
		r.SetRectFullScreen()
		c.GUI.ValYYY = 1
		return
	}
	if memmap.Uint32(0x5D4594, 1096520) != 0 {
		r.ClearScreen(color.White)
		*memmap.PtrUint32(0x5D4594, 1096520) = 0
		r.SetRectFullScreen()
		c.GUI.ValYYY = 1
		return
	}
	c.sub_468F80(vp)
	v10 := legacy.Nox_xxx_drawAllMB_475810_draw_B(vp) != 0
	c.sub_4765F0(vp)
	c.sub_4754F0(vp)
	if v10 {
		c.nox_xxx_tileDrawMB_481C20(vp)
		c.sub_4C5500(vp)
	} else {
		r.ClearScreen(color.Black)
	}
	c.sub_475F10(vp)
	c.nox_client_queueWallsDraw(vp, xmin, ymin)
	c.nox_client_drawBackWalls(vp)
	c.sub_475FE0(vp)
	legacy.Nox_video_drawCursorSelectCircle_4773C0(vp)
	c.nox_xxx_drawAllMB_475810_draw_E(vp)
	r.partfx.Draw()
	legacy.Sub_4C5060(vp)
	c.nox_client_maybeDrawFrontWalls(vp)
	r.DrawFade(false)
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		drawDebugAI(vp)
	}
	legacy.Sub_45AB40()
	r.SetRectFullScreen()
	*memmap.PtrUint32(0x973F18, 68) = 1
	c.sub_476680()
}

func (c *Client) sub_4765F0(vp *noxrender.Viewport) {
	c.savedHighResFloors = legacy.Get_nox_client_highResFloors_154952()
	c.savedHighResFrontWalls = legacy.Get_nox_client_highResFrontWalls_80820()
	if *memmap.PtrUint32(0x852978, 8) != 0 && !nox_client_lockHighResFloors_1193152 {
		v2 := *(*int32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 276))
		if (v2 == 3 || v2 == 6 || v2 == 45) && (vp.World.Min.X-c.val1096556 >= 4 || vp.World.Min.Y-c.val1096560 >= 4) {
			legacy.Set_nox_client_highResFloors_154952(0)
			legacy.Set_nox_client_highResFrontWalls_80820(0)
		}
		c.val1096556 = vp.World.Min.X
		c.val1096560 = vp.World.Min.Y
	}
}

func (c *Client) sub_476680() {
	legacy.Set_nox_client_highResFloors_154952(c.savedHighResFloors)
	legacy.Set_nox_client_highResFrontWalls_80820(c.savedHighResFrontWalls)
}

func (c *Client) sub_4C5500(vp *noxrender.Viewport) {
	sxmin := vp.Screen.Min.X
	symin := vp.Screen.Min.Y
	v16 := legacy.Sub_49F6D0(0)
	c.r.Data().SetColor2(nox_color_black_2650656)

	if ymin := c.tiles.dword_5d4594_3679320; symin < ymin { // top tile cutoff
		c.r.DrawRectFilledOpaque(sxmin, symin, vp.Size.X, ymin-symin, nox_color_black_2650656)
	}

	for yval := c.tiles.dword_5d4594_3679320; yval < c.tiles.dword_5d4594_3798156; yval++ {
		cur := &c.tiles.nox_arr_957820[yval]
		lxs := sxmin
		lxe := cur.arr[0]
		ptr2i := cur.arr[1:]
		if pv := c.tiles.nox_arr_956A00[yval]; pv > 0 {
			for i := 0; i < (pv+1)/2; i++ {
				c.r.DrawLineHorizontal(lxs, yval, lxe, nox_color_black_2650656)
				lxs = ptr2i[0]
				lxe = ptr2i[1]
				ptr2i = ptr2i[2:]
			}
		}
		c.r.DrawLineHorizontal(lxs, yval, sxmin+vp.Size.X, nox_color_black_2650656)
	}
	if ymax := c.tiles.dword_5d4594_3798156; vp.Size.Y+symin > ymax { // bottom tile cutoff
		c.r.DrawRectFilledOpaque(sxmin, ymax, vp.Size.X, vp.Size.Y+symin-ymax, nox_color_black_2650656)
	}
	legacy.Sub_49F6D0(v16)
	if noxflags.HasEngine(noxflags.EngineSoftShadowEdge) {
		legacy.Sub_498AE0()
	}
}

func (c *Client) nox_client_queueWallsDraw(vp *noxrender.Viewport, xmin, ymin int) { // nox_xxx_drawAllMB_475810_draw_C
	xmax := xmin + int(vp.Size.X)/common.GridStep + 2
	ymax := ymin + int(vp.Size.Y)/common.GridStep + 4
	for y := ymin; y <= ymax; y++ {
		for x := xmin; x <= xmax; x++ {
			wl := noxServer.getWallAtGrid(image.Point{X: x, Y: y})
			if wl == nil {
				continue
			}
			if memmap.Uint8(0x85B3FC, 43076+12332*uintptr(wl.tile()))&4 == 0 {
				if wl.field4()&2 != 0 {
					nox_frontWalls = append(nox_frontWalls, wl)
				} else {
					nox_backWalls = append(nox_backWalls, wl)
				}
			}
		}
	}
}

func nox_xxx_drawWalls_473C10(vp *noxrender.Viewport, p *Wall) {
	legacy.Nox_xxx_drawWalls_473C10(vp, p.C())
}

func (c *Client) nox_client_drawBackWalls(vp *noxrender.Viewport) {
	for _, v20 := range nox_backWalls {
		nox_xxx_drawWalls_473C10(vp, v20)
	}
	nox_backWalls = nox_backWalls[:0]
}

func (c *Client) nox_client_maybeDrawFrontWalls(vp *noxrender.Viewport) { // nox_client_maybeDrawFrontWalls_475810_F
	if nox_client_drawFrontWalls_80812 {
		for _, wl := range nox_frontWalls {
			nox_xxx_drawWalls_473C10(vp, wl)
		}
	} else {
		for _, wl := range nox_frontWalls {
			*(*byte)(wl.field(3)) = 0
			*(*byte)(wl.field(4)) &= 0xFC
		}
	}
	nox_frontWalls = nox_frontWalls[:0]
}

func (c *Client) sub_475F10(vp *noxrender.Viewport) {
	for _, dr := range nox_drawable_list_3 {
		c.drawCreatureBackEffects(vp, dr)
		if legacy.Nox_xxx_client_4984B0_drawable(dr) == 0 {
			continue
		}
		dr.Field_121 = 1
		legacy.CallDrawFunc(dr, vp)
		if dr.Flags70()&0x40 != 0 {
			legacy.Nox_xxx_drawShinySpot_4C4F40(vp, dr)
		}
		c.drawCreatureFrontEffects(vp, dr)
		legacy.Sub_495BB0(dr, vp)
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			nox_thing_debug_draw(vp, dr)
		}
		dr.Field_33 = 0
		if dr.Field_120 == 0 && dr.Field_122 == 0 {
			dr.Field_85 = c.srv.Frame()
		}
	}
	nox_drawable_list_3 = nox_drawable_list_3[:0]
}

func (c *Client) sub_475FE0(vp *noxrender.Viewport) {
	for _, dr := range nox_drawable_list_4 {
		if legacy.Nox_xxx_client_4984B0_drawable(dr) != 0 {
			dr.Field_121 = 1
			legacy.CallDrawFunc(dr, vp)
			if noxflags.HasEngine(noxflags.EngineShowExtents) {
				nox_thing_debug_draw(vp, dr)
			}
			dr.Field_33 = 0
			if dr.Field_120 == 0 && dr.Field_122 == 0 {
				dr.Field_85 = c.srv.Frame()
			}
		}
	}
	nox_drawable_list_4 = nox_drawable_list_4[:0]
}

func (c *Client) sub_476160(a1, a2 *client.Drawable) bool {
	var v1 int
	if int8(byte(a1.Flags28Val)) >= 0 {
		v1 = a1.Pos().Y + a1.Z()
	} else {
		v1 = legacy.Sub_4761B0(a1)
	}
	var v2 int
	if int8(byte(a1.Flags28Val)) >= 0 {
		v2 = a2.Pos().Y + a2.Z()
	} else {
		v2 = legacy.Sub_4761B0(a2)
	}
	return v1-v2 < 0
}

func (c *Client) nox_xxx_drawAllMB_475810_draw_E(vp *noxrender.Viewport) {
	sort.Slice(nox_drawable_objects_queue, func(i, j int) bool {
		a, b := nox_drawable_objects_queue[i], nox_drawable_objects_queue[j]
		return c.sub_476160(a, b)
	})
	sort.Slice(nox_wallsYyy, func(i, j int) bool {
		a, b := nox_wallsYyy[i], nox_wallsYyy[j]
		return legacy.Sub_476080(a.C()) < legacy.Sub_476080(b.C())
	})
	objects := nox_drawable_objects_queue
	walls := nox_wallsYyy
	sy := math.MaxInt32
	if len(objects) > 0 {
		sy = objects[0].Pos().Y
	}
	wy := math.MaxInt32
	if len(walls) > 0 {
		wy = legacy.Sub_476080(walls[0].C())
	}
LOOP:
	for len(objects) > 0 || len(walls) > 0 {
		if sy >= wy {
			if len(walls) != 0 {
				nox_xxx_drawWalls_473C10(vp, walls[0])
				walls = walls[1:]
				if len(walls) != 0 {
					wy = legacy.Sub_476080(walls[0].C())
					continue
				}
			}
			wy = math.MaxInt32
			continue
		}
		if len(objects) == 0 {
			sy = math.MaxInt32
			continue
		}
		dr := objects[0]
		objects = objects[1:]
		if len(objects) > 0 {
			sy = objects[0].Pos().Y
		} else {
			sy = math.MaxInt32
		}
		if dr.Field_27 == memmap.Uint32(0x5D4594, 1096448) && noxServer.Teams.First() != nil {
			for v25 := c.Objs.FirstPlayerList(); v25 != nil; v25 = v25.Field104() {
				if v25.HasEnchant(server.ENCHANT_CROWN) {
					continue LOOP
				}
			}
		}
		v26 := dr.Flags28()
		if !((v26&6 == 0) || c.srv.Frame()-dr.Field_72 <= 5) {
			if v26&2 != 0 {
				v27 := dr.Field_69
				if !(v27 == 9 || v27 == 10) {
					continue
				}
			} else if *memmap.PtrPtr(0x852978, 8) != dr.C() {
				continue
			}
		}
		c.drawCreatureBackEffects(vp, dr)
		if legacy.CallDrawFunc(dr, vp) == 0 {
			continue
		}
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			nox_thing_debug_draw(vp, dr)
		}
		dr.Field_33 = 0
		if dr.Flags70()&0x40 != 0 {
			legacy.Nox_xxx_drawShinySpot_4C4F40(vp, dr)
		}
		c.drawCreatureFrontEffects(vp, dr)
		legacy.Sub_495BB0(dr, vp)
		if dr.Field_120 == 0 && dr.Field_122 == 0 {
			dr.Field_85 = c.srv.Frame()
		}
		if legacy.Sub_459DB0(dr) != 0 {
			c.Objs.MinimapAdd(dr, 1)
		}
		if dr.Flags28()&0x20006 != 0 {
			legacy.Sub_49A6A0(vp, dr)
		}
	}
	nox_drawable_objects_queue = nox_drawable_objects_queue[:0]
}

func (c *Client) sub_4754F0(vp *noxrender.Viewport) {
	rect := image.Rectangle{
		Min: vp.World.Min,
		Max: vp.World.Min.Add(vp.Size).Add(image.Pt(0, 128)),
	}
	nox_drawable_objects_queue = nox_drawable_objects_queue[:0]
	nox_drawable_list_3 = nox_drawable_list_3[:0]
	nox_drawable_list_2 = nox_drawable_list_2[:0]
	nox_drawable_list_4 = nox_drawable_list_4[:0]
	nox_backWalls = nox_backWalls[:0]
	nox_frontWalls = nox_frontWalls[:0]
	c.Objs.EachInRect(rect, c.nox_xxx_spriteAddQueue_475560_draw)
}

func (c *Client) nox_xxx_spriteAddQueue_475560_draw(dr *client.Drawable) {
	if legacy.Nox_xxx_sprite_4756E0_drawable(dr) != 0 {
		nox_drawable_list_2 = append(nox_drawable_list_2, dr)
		return
	}
	if legacy.Nox_xxx_sprite_475740_drawable(dr) != 0 {
		nox_drawable_list_3 = append(nox_drawable_list_3, dr)
		return
	}
	if legacy.Nox_xxx_sprite_4757A0_drawable(dr) != 0 {
		nox_drawable_list_4 = append(nox_drawable_list_4, dr)
		return
	}
	if legacy.Sub_4757D0_drawable(dr) != 0 {
		if legacy.Get_nox_client_fadeObjects_80836() != 0 || dr.C() == *memmap.PtrPtr(0x852978, 8) || legacy.Nox_xxx_client_4984B0_drawable(dr) != 0 {
			if dr.Field_122 == 0 {
				if legacy.Nox_xxx_client_4984B0_drawable(dr) != 0 {
					dr.Field_121 = 1
					dr.Field_120 = 0
				} else {
					if dr.Field_121 == 0 || (dr.Flags28Val&0x6 != 0) {
						return
					}
					dr.Field_120 = 1
				}
			}
			if (dr.Field_120 != 0 || dr.Field_122 != 0) && (c.srv.Frame()-dr.Field_85) > c.srv.TickRate() {
				dr.Field_120 = 0
			} else {
				nox_drawable_objects_queue = append(nox_drawable_objects_queue, dr)
			}
		}
	}
}

func (c *Client) nox_xxx_drawAllMB_475810_draw_A(vp *noxrender.Viewport) {
	if *memmap.PtrUint32(0x5D4594, 1096448) == 0 {
		*memmap.PtrUint32(0x5D4594, 1096448) = uint32(c.Things.IndByID("Crown"))
	}
	c.sub_477F80()
	*memmap.PtrUint32(0x973F18, 68) = 0
	r := c.r
	if vp.Screen.Min.X != 0 {
		c.GUI.ValXXX = 1
		x := vp.Screen.Max.X + 1
		y := vp.Screen.Max.Y
		r.SetRectFullScreen()
		if c.GUI.ValYYY != 0 {
			rect := r.PixBufferRect()
			cl := color.Black
			r.DrawRectFilledOpaque(0, 0, rect.Dx(), vp.Screen.Min.Y, cl)
			r.DrawRectFilledOpaque(0, y, rect.Dx(), rect.Dy()-y, cl)
			r.DrawRectFilledOpaque(0, vp.Screen.Min.Y, vp.Screen.Min.X, y-vp.Screen.Min.Y, cl)
			r.DrawRectFilledOpaque(x, vp.Screen.Min.Y, rect.Dx()-x, y-vp.Screen.Min.Y, cl)
			c.GUI.ValYYY = 0
		}
		r.DrawBorder(vp.Screen.Min.X-2, vp.Screen.Min.Y-2, x-vp.Screen.Min.X+4, y-vp.Screen.Min.Y+4, nox_color_gray2)
	} else {
		c.GUI.ValXXX = 0
	}
	r.setClipRects(vp.Screen.Min, vp.Size)
}

const (
	dword_587000_142328 = 0x40000
	dword_587000_142316 = 0x40000
)

func sub_467430() byte {
	return memmap.Uint8(0x5D4594, 1062536)
}

func (c *Client) drawableUpdateLight(dr *client.Drawable) bool {
	if dr.HasEnchant(server.ENCHANT_INVULNERABLE) {
		dr.SetLightColor(128, 128, 255)
		dr.SetLightIntensity(300.0)
		return true
	} else if dr.HasEnchant(server.ENCHANT_LIGHT) || dr.C() == *memmap.PtrPtr(0x852978, 8) && sub_467430()&8 != 0 {
		dr.SetLightColor(255, 255, 255)
		dr.SetLightIntensity(200.0)
		return true
	} else if dr.Flags28()&0x2 == 0 || dr.Flags28()&0x80000 != 0 {
		return false
	} else if dr.Field_69 == 10 {
		dr.SetLightIntensity(0.0)
		return true
	}
	dr.SetLightColor(255, 255, 255)
	if dr.Flags29()&0x1 != 0 {
		dr.SetLightIntensity(25.0)
	} else if dr.Flags29()&0x2 != 0 {
		dr.SetLightIntensity(35.0)
	} else if dr.Flags29()&0x4 != 0 {
		dr.SetLightIntensity(45.0)
	}
	return true
}

func (c *Client) nox_xxx_cliLight16_469140(dr *client.Drawable) {
	if !(c.drawableUpdateLight(dr) || dr.Flags28()&0x80000 != 0 && dr.Flags30()&0x1000000 != 0 && dr.LightIntensityRad > 0 && dr.Flags30()&0x4 != 0) {
		return
	}
	if !(legacy.Nox_xxx_get_57AF20() == 0 || dr.C() == *memmap.PtrPtr(0x852978, 8) || dr.DrawFuncPtr == legacy.Get_nox_thing_glow_orb_draw()) {
		return
	}
	intens := int(dr.LightIntensityU16)
	rad := int(dr.LightIntensityRad)
	if dr.Flags30()&0x20000000 != 0 {
		intens += randomIntMinMax(0, int(dr.LightIntensityU16)>>18) << 16
		rad = client.LightRadius(float32(intens) / 0x10000)
	}
	if intens <= int(lightMinIntensity*0x10000) {
		return
	}
	intens2 := intens
	if max := int(memmap.Int32(0x587000, 142320)); intens2 > max {
		intens2 = max
	}
	pos := dr.Pos()
	xx := pos.X - c.tiles.noxTilesGpx
	yy := pos.Y - c.tiles.noxTilesGpy
	a4 := image.Pt(xx, yy)
	if dr.Field_42 == 0xFFFF {
		dlimit := rad * rad

		xmin := (xx - rad) / common.GridStep
		if xmin < 0 {
			xmin = 0
		}

		xmax := (xx + rad) / common.GridStep
		if xmax > lightGridW-1 {
			xmax = lightGridW - 1
		}

		ymin := (yy - rad) / common.GridStep
		if ymin < 0 {
			ymin = 0
		}

		ymax := (yy + rad) / common.GridStep
		if ymax > lightGridH-1 {
			ymax = lightGridH - 1
		}

		v36 := (intens >> 16) * (intens >> 16)
		for y := ymin; y <= ymax; y++ {
			dy := yy - common.GridStep*y
			dy2 := dy * dy
			for x := xmin; x <= xmax; x++ {
				dx := xx - common.GridStep*x
				dx2 := dx * dx
				if dist := dx2 + dy2; dist <= dlimit {
					intens3 := sub_4C1C70(intens2+dword_587000_142328, 66*dist*int(memmap.Uint32(0x587000, 142324))/v36+0x10000)
					if intens3 > dword_587000_142328 {
						c.sub_4695E0(x, y, (*int32)(unsafe.Pointer(&dr.LightColorR)), 8*(intens3-dword_587000_142328), dr.Field_43 != 0)
					}
					xx = a4.X
					yy = a4.Y
				}
			}
		}
	} else {
		a1 := image.Pt(
			(xx<<16)/common.GridStep,
			(yy<<16)/common.GridStep,
		)
		v19 := (rad << 16) / common.GridStep
		v22 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(uint16(dr.Field_41_0+0x4000)>>4))))
		v23 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(uint16(dr.Field_41_0)>>4))))

		v22b := uint16(dr.Field_41_0) + uint16(dr.Field_41_1)
		a3 := a1.Add(image.Pt(v22, v23))
		v44 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr((v22b+0x4000)>>4))))
		v24 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(v22b>>4))))

		v22b = uint16(dr.Field_41_0) + uint16(dr.Field_41_1)
		a2 := a1.Add(image.Pt(v44, v24))
		v45 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr((v22b+0x4000)>>4))))
		v25 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(v22b>>4))))

		v42 := a1.Add(image.Pt(v45, v25))
		c.sub_4696B0(a1, a2, a3, a4, intens, (*int32)(unsafe.Pointer(&dr.LightColorR)))
		c.sub_4696B0(a1, a3, v42, a4, intens, (*int32)(unsafe.Pointer(&dr.LightColorR)))
	}
}

func sub_4C1C60(a1, a2 int) int {
	return int((int64(a1) * int64(a2)) >> 16)
}

func (c *Client) sub_4695E0(a1, a2 int, pcl *int32, a4 int, flip bool) {
	v5 := a4
	if flip {
		v5 = -a4
	}
	a3 := unsafe.Slice(pcl, 3)
	v6 := sub_4C1C60(v5, int(a3[0])) << 8
	v7 := sub_4C1C60(v5, int(a3[1])) << 8
	v8 := sub_4C1C60(v5, int(a3[2])) << 8

	ptr := &c.tiles.nox_arr2_853BC0[a1][a2]

	var res noxrender.RGB
	res.R = v6 + ptr.R
	res.G = v7 + ptr.G
	res.B = v8 + ptr.B

	if res.R <= 0xFF0000 {
		if res.R < 0 {
			res.R = 0
		}
	} else {
		res.R = 0xFF0000
	}
	if res.G <= 0xFF0000 {
		if res.G < 0 {
			res.G = 0
		}
	} else {
		res.G = 0xFF0000
	}
	if res.B <= 0xFF0000 {
		if res.B < 0 {
			res.B = 0
		}
	} else {
		res.B = 0xFF0000
	}
	*ptr = res
}

func (c *Client) nox_xxx_tileDrawMB_481C20(vp *noxrender.Viewport) {
	legacy.Inc_nox_xxx_waypointCounterMB_587000_154948()
	dp := vp.ToWorldPos(image.Pt(0, 0))
	if !nox_client_texturedFloors_154956 && legacy.Get_dword_5d4594_1193156() == 1 {
		nox_client_texturedFloors2_154960 = false
		nox_client_texturedFloors_154956 = true
		nox_xxx_tileSetDrawFn_481420()
	}
	if legacy.Get_dword_5d4594_1193156() == 1 && !nox_client_texturedFloors2_154960 && c.srv.Frame()%30 == 0 && legacy.Nox_xxx_tileCheckRedrawMB_482570(vp) == 0 {
		legacy.Set_dword_5d4594_1193156(0)
		nox_client_texturedFloors_154956 = nox_client_texturedFloors2_154960
		nox_xxx_tileSetDrawFn_481420()
	}
	if legacy.Get_dword_5d4594_1193188() != 0 {
		legacy.Nox_xxx_tileDrawImpl_4826A0(vp)
		legacy.Set_dword_5d4594_1193188(0)
	} else {
		legacy.Nox_xxx_tileDrawMB_481C20_A(vp, dp.X)
		legacy.Nox_xxx_tileDrawMB_481C20_B(vp, dp.Y)
	}
	if nox_client_texturedFloors_154956 {
		c.nox_xxx_tileDrawMB_481C20_C_textured(vp, dp)
	} else {
		c.nox_xxx_tileDrawMB_481C20_C_solid(vp, dp)
	}
}

func (c *Client) Sub4C5630(a1 int, a2 int, a3 int) int {
	if a3 < 0 || a3 >= len(c.tiles.nox_arr_956A00) { // TODO: figure out why overflow happens on high-res
		return 0
	}
	v4 := c.tiles.nox_arr_956A00[a3]
	if v4 <= 0 {
		return 0
	}
	cur := &c.tiles.nox_arr_957820[a3]
	for i := 0; i < v4; i += 2 {
		if a1 <= cur.arr[i+1] && a2 >= cur.arr[i+0] {
			return 1
		}
	}
	return 0
}

func (c *Client) sub_4C5430(a1 int, a2 int) {
	v2 := c.tiles.nox_arr_956A00[a2]
	if v2 >= 32 {
		return
	}
	v3 := 0
	if v2 > 0 {
		cur := &c.tiles.nox_arr_957820[a2]
		for ; v3 < v2; v3++ {
			if a1 < cur.arr[v3] {
				break
			}
		}
	}
	if v3 != v2 && v2-1 >= v3 {
		for v5 := v2 - v3; v5 != 0; v5-- {
			c.tiles.nox_arr_957820[a2].arr[v5+v3] = c.tiles.nox_arr_957820[a2].arr[v5+v3-1]
		}
	}
	c.tiles.nox_arr_956A00[a2] = v2 + 1
	c.tiles.nox_arr_957820[a2].arr[v3] = a1
	if a2 < c.tiles.dword_5d4594_3679320 {
		c.tiles.dword_5d4594_3679320 = a2
	}
	if a2 > c.tiles.dword_5d4594_3798156 {
		c.tiles.dword_5d4594_3798156 = a2
	}
}

func (c *Client) nox_xxx_drawBlack_496150_B() {
	legacy.Sub_4989A0()
	c.sub_4C52E0(memmap.PtrInt32(0x5D4594, 1203876), int(legacy.Get_dword_5d4594_1217464()))
}

func (c *Client) sub_4C52E0(a1 *int32, sz int) {
	arr := unsafe.Slice(a1, 2*sz)
	c.tiles.nox_arr_956A00 = [noxMaxHeight + 150]int{}
	c.tiles.dword_5d4594_3679320 = nox_win_height
	c.tiles.dword_5d4594_3798156 = 0
	if sz <= 0 {
		return
	}
	for i := 0; i < sz; i++ {
		v7 := int(arr[2*i+0])
		var (
			v8  int
			v9  int
			v10 int
		)
		if i == sz-1 {
			v8 = int(arr[0])
			v9 = int(arr[2*i+1])
			v10 = int(arr[1])
		} else {
			v8 = int(arr[2*(i+1)+0])
			v9 = int(arr[2*i+1])
			v10 = int(arr[2*(i+1)+1])
		}
		if v9 == v10 {
			continue
		}
		if v7 == v8 {
			if v10 < v9 {
				for ; v10 < v9; v10++ {
					c.sub_4C5430(v7, v10)
				}
			} else if v10 > v9 {
				for ; v9 < v10; v9++ {
					c.sub_4C5430(v7, v9)
				}
			}
			continue
		}
		var (
			v17 int
			v11 int
			v18 int
			v12 int
		)
		if v9 <= v10 {
			v17 = int(arr[2*i+0])
			v11 = v9
			v18 = v10
			if v8 <= v7 {
				v12 = -1
			} else {
				v12 = 1
			}
		} else {
			v17 = v8
			v11 = v10
			v18 = v9
			if v8 <= v7 {
				v12 = 1
			} else {
				v12 = -1
			}
		}
		if v11 >= v18 {
			continue
		}
		v15 := 0
		v14 := v18 - v11
		var v13 int
		if v8-v7 >= 0 {
			v13 = v8 - v7
		} else {
			v13 = v7 - v8
		}
		for ; v11 < v18; v11++ {
			c.sub_4C5430(v17, v11)
			v15 += v13
			for ; v15 >= v14; v17 += v12 {
				v15 -= v14
			}
		}
	}
}

func (c *Client) Sub4C42A0(a1, a2 image.Point, a3 *int, a4 *int) int32 {
	v4 := a1.Y
	v5 := a2.Y
	if v4 == v5 {
		if v4 < 0 || v4 >= len(c.tiles.nox_arr_956A00) || c.tiles.nox_arr_956A00[v4] == 0 {
			return 0
		}
		v47 := a1.X
		v54 := a2.X
		var (
			v51 float32
			v7  float64
		)
		if a1.X > v54 {
			v51 = float32(float64(v54))
			v7 = float64(v47)
		} else {
			v51 = float32(float64(v47))
			v7 = float64(v54)
		}
		v43 := float32(v7)
		if v4 < 0 {
			return 0
		}
		if v4 >= nox_win_height {
			v4 = nox_win_height - 1
		}
		if float64(v51) < 0.0 {
			v51 = 0.0
		}
		v8 := float64(nox_win_width)
		if float64(v51) > v8 {
			v51 = float32(v8)
		}
		v9 := c.tiles.nox_arr_956A00[v4]
		for v10 := 0; v10 < v9; v10 += 2 {
			v11it := c.tiles.nox_arr_957820[v4].arr[v10 : v10+2]
			v12 := v11it[0]
			v13 := v11it[1]
			if float64(v11it[0]) > float64(v51) {
				if *a3 < v12 {
					*a3 = v12
				}
				if float64(v13) < float64(v43) && *a4 > v13 {
					*a4 = v13
				}
				return 1
			}
			if float64(v51) <= float64(v13) && float64(v43) > float64(v13) {
				if *a4 > v13 {
					*a4 = v13
				}
				return 1
			}
			if float64(v43) <= float64(v13) {
				return 1
			}
		}
		*a4 = 0
		return 1
	}
	v48 := a1.X
	v56 := a2.X
	var (
		v15 int
		v16 int
		v50 int
		v52 float32
		v17 float64
	)
	if a1.X > v56 {
		v15 = v5
		v16 = a1.Y
		v50 = v5
		v52 = float32(float64(v56))
		v17 = float64(v48)
	} else {
		v15 = a1.Y
		v16 = v5
		v50 = a1.Y
		v52 = float32(float64(v48))
		v17 = float64(v56)
	}
	v44 := float32(v17)
	v18 := v16 - v15
	v57 := v16 - v15
	var v46 int
	if v16-v15 >= 0 {
		v46 = 1
	} else {
		v18 = v15 - v16
		v57 = v15 - v16
		v46 = -1
	}
	v49 := float32(float64(v44-v52) / float64(v57))
	v19 := nox_win_height
	if v15 < 0 {
		v15 = 0
		v52 = float32(float64(v52) - float64(v50)*float64(v49))
	} else if v15 >= nox_win_height {
		if v16 >= nox_win_height {
			return 0
		}
		v58 := v15 - nox_win_height + 1
		v15 = nox_win_height - 1
		v52 = float32(float64(v58)*float64(v49) + float64(v52))
		if *a3 < int(v52) {
			*a3 = int(v52)
		}
	}
	if v16 >= 0 {
		if v16 >= v19 {
			v59 := v19 - v16 + v18 - 1
			v44 = float32(float64(v59)*float64(v49) + float64(v52))
			if *a4 > int(v44) {
				*a4 = int(v44)
			}
			v18 = v59
		}
	} else {
		v18 += v16
	}
	if float64(v52) < 0.0 {
		v52 = 0.0
		v15 -= int(0.0)
	}
	if float64(v44) > float64(nox_win_width) {
		v18 -= int(float32(float64(v44) - float64(nox_win_width)))
	}
	v23 := c.tiles.nox_arr_956A00[v15]

	ok25 := true
	for i := 0; i < v23; i += 2 {
		v26it := c.tiles.nox_arr_957820[v15].arr[i : i+2]
		if !(float64(v26it[0]) > float64(v52) || float64(v26it[1]+2) < float64(v52)) {
			ok25 = false
			break
		}
	}
	v28 := v46 + v15
	v29 := v18 - 1
	v53 := v49 + v52
	if ok25 {
		if v29 == 0 {
			return 0
		}
		if v29 > 0 {
		loop1:
			for {
				if n := c.tiles.nox_arr_956A00[v28]; n > 0 {
					for j := 0; j < n; j += 2 {
						v34 := c.tiles.nox_arr_957820[v28].arr[j : j+2]
						if float64(v34[0]) <= float64(v53) && float64(v34[1]+2) >= float64(v53) {
							if *a3 < int(v53)-1 {
								*a3 = int(v53) - 1
							}
							break loop1
						}
					}
				}
				v28 += v46
				v53 = v49 + v53
				v29--
				if v29 == 0 {
					return 0
				} else if v29 < 0 {
					break
				}
			}
		}
	}
	if v29 <= 0 {
		return 1
	}
	si := v28
	for {
		v37 := c.tiles.nox_arr_956A00[si]
		if v37 <= 0 {
			if *a4 > int(v53) {
				*a4 = int(v53)
			}
			return 1
		}
		v40 := c.tiles.nox_arr_957820[si].arr[:]
		for v39 := 0; ; {
			if float64(v40[0]) <= float64(v53) && float64(v40[1]+2) >= float64(v53) {
				break
			}
			v39 += 2
			v40 = v40[2:]
			if v39 >= v37 {
				if *a4 > int(v53) {
					*a4 = int(v53)
				}
				return 1
			}
		}
		v29--
		si += v46
		v53 = v49 + v53
		if v29 <= 0 {
			return 1
		}
	}
}

func (c *Client) nox_xxx_tileDrawMB_481C20_C_solid(vp *noxrender.Viewport, dp image.Point) {
	c.sub4745F0(vp)
	y := c.tiles.dword_5d4594_3679320
	if y >= c.tiles.dword_5d4594_3798156 {
		return
	}
	v67_4 := dp.Y + y
	v78a := c.tiles.nox_arr_957820[y:]
	for y < c.tiles.dword_5d4594_3798156 {
		it := v78a[0].arr[:]
		v36 := c.tiles.nox_arr_956A00[y]
		pixrow := noxPixBuffer.img.Row(y)
		if v36 > 0 {
			for j := (v36 + 1) / 2; j != 0; j-- {
				v37 := it[0]
				sz := it[1] - it[0]
				it = it[2:]
				v39i := (c.tiles.dword_5d4594_3798804/2)*(v67_4+int(legacy.Get_dword_5d4594_3798840())-int(legacy.Get_dword_5d4594_3798824())) + (v37 + dp.X + int(legacy.Get_dword_5d4594_3798836()) - int(legacy.Get_dword_5d4594_3798820()))
				if v39i >= len(c.tiles.noxTileBuf) {
					v39i -= len(c.tiles.noxTileBuf)
				}
				src := c.tiles.noxTileBuf[v39i:]
				dst := pixrow[v37:]
				if sz < len(c.tiles.noxTileBuf) {
					copy(dst[:sz], src[:sz])
				} else {
					n1 := len(c.tiles.noxTileBuf) - v39i
					copy(dst[:n1], src[:n1])
					src = c.tiles.noxTileBuf[:]
					n2 := sz - n1
					copy(dst[n1:n1+n2], src[:n2])
				}
			}
		}
		y++
		v78a = v78a[1:]
		v67_4++
	}
}

func (c *Client) nox_xxx_tileDrawMB_481C20_C_textured(vp *noxrender.Viewport, dp image.Point) {
	r := c.r

	sy := c.tiles.dword_5d4594_3679320
	ymax := c.tiles.dword_5d4594_3798156
	gpx := c.tiles.noxTilesGpx
	gpy := c.tiles.noxTilesGpy
	var v67 image.Point
	v67.Y = dp.Y + sy
	c.sub4745F0(vp)
	for i := range c.tiles.nox_arr_84EB20 {
		c.tiles.nox_arr_84EB20[i].Y = -1
	}
	var v66 image.Point
	v66.Y = (v67.Y - gpy) / common.GridStep
	v78 := v67.Y - common.GridStep*v66.Y - gpy
	pix := r.PixBuffer()
	for yy := sy; yy < ymax; yy++ {
		src := c.tiles.nox_arr_957820[yy:]
		if v78 == common.GridStep {
			v78 = 0
			v66.Y++
		}
		cur := &src[0]
		vv := c.tiles.nox_arr_956A00[yy]
		if legacy.Get_nox_client_highResFloors_154952() != 0 || v67.Y&1 == 0 || yy == 0 {
			// high-res or each second row on low-res
			if vv > 0 {
				it := cur.arr[:]
				for jj := 0; jj < (vv+1)/2; jj++ {
					v1 := int(it[0])
					v2 := int(it[1])
					it = it[2:]

					v67.X = v1 + dp.X
					v66.X = (v1 + dp.X - gpx) / common.GridStep
					for kk := gpx + common.GridStep*v66.X; kk < v2+dp.X+common.GridStep; kk += common.GridStep {
						if c.tiles.nox_arr_84EB20[v66.X].Y != v66.Y {
							c.noxTileUpdateLightXxx(v66)
						}
						v66.X++
					}
					v66.X = (v1 + dp.X - gpx) / common.GridStep
					ind := pix.PixOffset(v1, yy)
					v66.X = c.noxTileDrawTextured(v67, v66.X, v78, v2-v1, pix.Pix[ind:])
				}
			}
		} else {
			// low-res floors basically skip each second row (interlacing) and then duplicate result from the first row
			if vv > 0 {
				it := cur.arr[:]
				for jj := (vv + 1) / 2; jj != 0; jj-- {
					v1 := it[0]
					v2 := it[1]
					it = it[2:]

					ind := pix.PixOffset(v1, yy)
					ind2 := pix.PixOffset(v1, yy-1)
					copy(pix.Pix[ind:], pix.Pix[ind2:ind2+(v2-v1)])
				}
			}
		}
		v78++
		v67.Y++
	}
}

func (c *Client) noxTileDrawTextured(a1 image.Point, a2 int, a3, sz int, dst []uint16) int {
	buf := c.tiles.noxTileBuf

	bi := (c.tiles.dword_5d4594_3798804/2)*(int(legacy.Get_dword_5d4594_3798840())+a1.Y-int(legacy.Get_dword_5d4594_3798824())) + (int(legacy.Get_dword_5d4594_3798836()) + a1.X - int(legacy.Get_dword_5d4594_3798820()))
	if bi >= len(buf) {
		bi -= len(buf)
	}
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		if bi+sz < len(buf) {
			copy(dst[:sz], buf[bi:bi+sz])
		} else {
			sz1 := len(buf) - bi
			sz2 := sz - sz1
			copy(dst[:sz1], buf[bi:bi+sz1])
			copy(dst[sz1:sz1+sz2], buf[:sz2])
		}
		return a2
	}
	mul := a1.X - common.GridStep*a2 - c.tiles.noxTilesGpx
	c1 := c.tiles.nox_arr_84EB20[a2].Cl[a3]
	c2 := c.tiles.nox_arr_84EB20[a2+1].Cl[a3]
	lr := c.tiles.nox_light_8529A0[255+(c2.R-c1.R)>>8]
	lg := c.tiles.nox_light_8529A0[255+(c2.G-c1.G)>>8]
	lb := c.tiles.nox_light_8529A0[255+(c2.B-c1.B)>>8]
	var csz int
	if mul <= 0 {
		csz = common.GridStep
	} else {
		c1.R += mul * lr
		c1.G += mul * lg
		c1.B += mul * lb
		csz = common.GridStep - mul
	}
	if csz > sz {
		csz = sz
	}
	for {
		bi = bi % len(buf)
		_ = dst[csz:]
		_ = buf[bi:]
		for i := 0; i < csz; i++ {
			cl := buf[bi%len(buf)]
			r := uint16((uint32(c1.R)*uint32((cl>>7)&0xF8))>>16) & 0xF8
			g := uint16((uint32(c1.G)*uint32((cl>>2)&0xF8))>>16) & 0xF8
			b := uint16((uint32(c1.B)*uint32((cl>>0)&0x1F))>>13) & 0xF8
			dst[i] = (r << 7) | (g << 2) | (b >> 3)

			bi++
			c1.R += lr
			c1.G += lg
			c1.B += lb
		}
		dst = dst[csz:]
		sz -= csz
		if sz <= 0 {
			break
		}
		csz = common.GridStep
		if sz < common.GridStep {
			csz = sz
		}
		a2++
		c1 = c.tiles.nox_arr_84EB20[a2].Cl[a3]
		c2 = c.tiles.nox_arr_84EB20[a2+1].Cl[a3]
		lr = c.tiles.nox_light_8529A0[255+(c2.R-c1.R)>>8]
		lg = c.tiles.nox_light_8529A0[255+(c2.G-c1.G)>>8]
		lb = c.tiles.nox_light_8529A0[255+(c2.B-c1.B)>>8]
	}
	return a2
}

func (c *Client) sub_4696B0(a1, a2, a3, a4 image.Point, a5 int, pcl *int32) {
	var v8, v9, v10 image.Point
	if a1.Y > a2.Y {
		if a2.Y <= a3.Y {
			v9 = a2
			v10 = a3
			v8 = a1
		} else {
			v9 = a3
			v10 = a1
			v8 = a2
		}
	} else {
		if a1.Y <= a3.Y {
			v9 = a1
			v10 = a2
			v8 = a3
		} else {
			v9 = a3
			v10 = a1
			v8 = a2
		}
	}
	var v13, v14, v15 [2 * common.GridStep]int
	sub_484DC0(v9, v10, v15[:])
	sub_484DC0(v9, v8, v14[:])
	c.sub_4697C0(v15[:], v14[:], a4, a5, pcl)
	if v10.Y < v8.Y {
		sub_484DC0(v10, v8, v13[:])
		c.sub_4697C0(v13[:], v14[:], a4, a5, pcl)
	} else if v10.Y > v8.Y {
		sub_484DC0(v8, v10, v13[:])
		c.sub_4697C0(v15[:], v13[:], a4, a5, pcl)
	}
}

func (c *Client) sub_4697C0(a1, a2 []int, a3 image.Point, a4 int, a5 *int32) {
	v0 := a1[0]
	v7 := a1[0] + a1[1]
	if a1[0] < a2[0] {
		v0 = a2[0]
	}
	if v7 > a2[1]+a2[0] {
		v7 = a2[1] + a2[0]
	}
	if v7-v0 <= 1 {
		return
	}
	v23 := a4
	if max := int(memmap.Int32(0x587000, 142308)); v23 > max {
		v23 = max
	}
	if v0 >= v7 {
		return
	}
	v21 := (a4 >> 16) * (a4 >> 16)
	v8 := common.GridStep*v0 - a3.Y
	v12 := dword_587000_142316
	for ii := v0; ii < v7; ii++ {
		v10 := &a2[ii+2]
		v13 := a1[ii+2]
		v14 := common.GridStep*v13 - a3.X
		if v13 < *v10 {
			v16 := v8 * v8
			for jj := v13; jj < *v10; jj++ {
				v17 := sub_4C1C70(v12+v23, 66*int(memmap.Uint32(0x587000, 142312))*(v16+v14*v14)/v21+0x10000)
				v12 = dword_587000_142316
				if v17 > dword_587000_142316 {
					c.sub_4695E0(jj, ii, a5, 8*(v17-dword_587000_142316), false)
					v12 = dword_587000_142316
				}
				v14 += common.GridStep
			}
		}
		v0 = v7
		v8 += common.GridStep
	}
}

func sub_484DC0(a1, a2 image.Point, a3 []int) {
	a3[0] = (a1.Y + 0x8000) >> 16
	a3[1] = ((a2.Y + 0x8000) >> 16) - a3[0] + 1
	if a3[1] <= 0 {
		return
	}
	dn := (a2.X - a1.X) / a3[1]
	v6 := a3[0] + a3[1]
	if int(a3[0]) < 0 {
		a3[0] = 0
		a3[1] = v6
	}
	if v6 > 44 {
		a3[1] += 44 - v6
		v6 = 44
	}
	v7 := a3[0]
	if v7 >= v6 {
		return
	}
	v8 := a1.X + 0x8000
	v9 := a3[v7+2:]
	for v10 := v6 - v7; v10 != 0; v10-- {
		v9[0] = v8 >> 16
		if v8>>16 < 0 {
			v9[0] = 0
		}
		if v9[0] >= 56 {
			v9[0] = 55
		}
		v8 += dn
		v9 = v9[1:]
	}
}

func sub_4C1C70(a1, a2 int) int {
	return int((uint64(a1) << 16) / uint64(a2))
}
