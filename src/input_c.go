package opennox

import (
	"image"
	"sync"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/client/seat"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/input"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var (
	inputKeyTimeoutsOld = make(map[byte]uint32)
	inputKeyTimeoutsNew = make(map[keybind.Event]uint32)
)

func sub_416120(key byte) bool {
	return inputKeyTimeoutsOld[key] != noxServer.Frame()
}

func sub_416170(key int) int {
	delete(inputKeyTimeoutsOld, byte(key))
	return key
}

func sub_416150(key, ts int) int {
	if ts == 0 {
		delete(inputKeyTimeoutsOld, byte(key))
	} else {
		inputKeyTimeoutsOld[byte(key)] = uint32(ts)
	}
	return key
}

func inputClearKeyTimeouts() {
	inputKeyTimeoutsOld = make(map[byte]uint32)
	inputKeyTimeoutsNew = make(map[keybind.Event]uint32)
}

func nox_xxx_guiSpellTest_45D9C0() bool {
	return memmap.Uint32(0x5D4594, 1047916) != 0
}

func inputKeyCheckTimeoutLegacy(key byte, dt uint32) bool {
	return int(noxServer.Frame())-int(inputKeyTimeoutsOld[key]) > int(dt)
}

func inputSetKeyTimeoutLegacy(key byte) {
	inputKeyTimeoutsOld[key] = noxServer.Frame()
}

func inputKeyCheckTimeout(ev keybind.Event, dt uint32) bool {
	return int(noxServer.Frame())-int(inputKeyTimeoutsNew[ev]) > int(dt)
}

func inputSetKeyTimeout(ev keybind.Event) {
	inputKeyTimeoutsNew[ev] = noxServer.Frame()
}

func nox_xxx_guiCursor_477600() uint32 {
	return memmap.Uint32(0x5D4594, 1096672)
}

func nox_client_setMousePos_430B10(x, y int) {
	noxClient.ChangeMousePos(image.Pt(x, y), true)
}

var keybindTitles struct {
	sync.Once
	byTitle map[string]keybind.Key
}

func nox_xxx_keybind_nameByTitle_42E960(title string) keybind.Key {
	keybindTitles.Do(func() {
		keybindTitles.byTitle = make(map[string]keybind.Key)
		for _, k := range keybind.ListKeys() {
			keybindTitles.byTitle[k.Title(noxClient.Strings())] = k
		}
	})
	return keybindTitles.byTitle[title]
}

func nox_xxx_bindevent_bindNameByTitle_42EA40(title string) *keybind.BindEvent {
	return keyBinding.EventByTitle(title)
}

func sub_4C3CB0() {
	ctrlEvent.Reset()
	nox_common_readcfgfile("default.cfg", true)
	sub_4C3B70()
}

func sub_4CBF40() {
	ctrlEvent.Reset()
	nox_common_readcfgfile("default.cfg", true)
	sub_4CBBF0()
}

func sub_4C3B70() {
	win36 := legacy.Get_dword_5d4594_1321236()
	win40 := legacy.Get_dword_5d4594_1321240()
	win44 := legacy.Get_dword_5d4594_1321244()
	win48 := legacy.Get_dword_5d4594_1321248()
	win36.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	win40.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	win44.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	win48.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	for _, ev := range keyBinding.Events() {
		if ev.Event == keybind.EventToggleQuitMenu {
			continue
		}
		win40.Func94(&WindowEvent0x400d{Str: ev.Title, Val: -1})
		win36.Func94(&WindowEvent0x400d{Str: " ", Val: -1})
		v2 := ctrlEvent.Sub_42E8E0_go(ev.Event, 1)
		v3 := ctrlEvent.Sub_42E8E0_go(ev.Event, 2)
		if v2 != "" {
			win44.Func94(&WindowEvent0x400d{Str: v2, Val: -1})
		} else {
			win44.Func94(&WindowEvent0x400d{Str: " ", Val: -1})
		}
		if v3 != "" && v2 != v3 {
			win48.Func94(&WindowEvent0x400d{Str: v3, Val: -1})
		} else {
			win48.Func94(&WindowEvent0x400d{Str: " ", Val: -1})
		}
	}
}

func sub_4CBBF0() {
	win16 := legacy.Get_dword_5d4594_1522616()
	win20 := legacy.Get_dword_5d4594_1522620()
	win24 := legacy.Get_dword_5d4594_1522624()
	win28 := legacy.Get_dword_5d4594_1522628()
	win16.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	win20.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	win24.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	win28.Func94(gui.AsWindowEvent(0x400F, 0, 0))
	for _, ev := range keyBinding.Events() {
		if ev.Event == keybind.EventToggleQuitMenu {
			continue
		}
		win20.Func94(&WindowEvent0x400d{Str: ev.Title, Val: -1})
		win16.Func94(&WindowEvent0x400d{Str: " ", Val: -1})
		v2 := ctrlEvent.Sub_42E8E0_go(ev.Event, 1)
		v3 := ctrlEvent.Sub_42E8E0_go(ev.Event, 2)
		if v2 != "" {
			win24.Func94(&WindowEvent0x400d{Str: v2, Val: -1})
		} else {
			win24.Func94(&WindowEvent0x400d{Str: " ", Val: -1})
		}
		if v3 != "" && v2 != v3 {
			win28.Func94(&WindowEvent0x400d{Str: v3, Val: -1})
		} else {
			win28.Func94(&WindowEvent0x400d{Str: " ", Val: -1})
		}
	}
}

func (c *Client) nox_client_processInput_4308A0() {
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeQuest) && c.Inp.SeqDelay() > 2700 {
		if !noxflags.HasGame(noxflags.GameHost) {
			nox_xxx_netServerCmd_440950(0, alloc.GoString16((*uint16)(memmap.PtrOff(0x587000, 80784))))
			return
		}
		if p := getCurPlayer(); p != nil {
			nox_xxx_serverHandleClientConsole_443E90(p, 0, alloc.GoString16((*uint16)(memmap.PtrOff(0x587000, 80792))))
		}
	}
}

func nox_input_reset_430140(a1 int) {
	noxClient.ResetInput()
}

func nox_xxx_freeKeyboard_430210() {
	noxClient.inDraw1 = false
}

func nox_xxx_initInput_430190() error {
	inputInitMouse()
	legacy.Sub_42EBB0(2, ccall.FuncAddr(legacy.Nox_input_reset_430140), 0, "Input")
	return nil
}

func (c *CtrlEventHandler) nox_xxx_input_42D220(inp *input.Handler) {
	first := c.nox_xxx_input_42D220_A(inp)
	for it1 := first; it1 != nil; it1 = it1.field20 {
		if !it1.flag22 {
			continue
		}
		for _, k1 := range it1.keys {
			for it2 := first; it2 != nil; it2 = it2.field20 {
				if !it2.flag22 || it2 != it1 {
					continue
				}
				for j := 0; j >= len(it2.keys); j++ {
					if k1 == it2.keys[j] {
						if len(it1.keys) >= len(it2.keys) {
							it2.flag22 = false
						} else {
							it1.flag22 = false
						}
						break
					}
				}
			}
		}
	}
	var res *CtrlEventBinding
	for it := first; it != nil; it = it.field20 {
		if it.flag22 {
			it.field21 = res
			it.frame = noxServer.Frame()
			res = it
		}
	}
	c.nox_xxx_clientControl_42D6B0(inp.GetMousePos(), res)
	c.writeToNetBuffer()
}

func (c *CtrlEventHandler) nox_xxx_input_42D220_A(inp *input.Handler) *CtrlEventBinding {
	var res *CtrlEventBinding
	for it := c.bindings; it != nil; it = it.next {
		li := -1
		for i, key := range it.keys {
			if key.IsKeyboard() {
				if noxClient.GUI.Focused() != nil || legacy.Sub_46A4A0() != 0 {
					break
				}
				if inp.IsReleased(key) {
					break
				}
			} else if key.IsMouse() {
				if inp.MouseAction(key, it.events[0]) {
					break
				}
			} else if key.IsJoystick() && (c.flags750956 || (1<<uint32(key))&memmap.Uint32(0x5D4594, 747844) == 0) {
				break
			}
			li = i + 1
		}
		if li == len(it.keys) {
			it.field20 = res
			it.flag22 = true
			res = it
		}
	}
	return res
}

func loadRect(p unsafe.Pointer) image.Rectangle {
	rp := (*[4]int32)(p)
	return image.Rect(
		int(rp[0]), int(rp[1]),
		int(rp[2]), int(rp[3]),
	)
}

func (c *Client) nox_xxx_cursorUpdate_46B740_sprites(v63 bool, v66 []int) {
	if gameGetPlayState() != 3 {
		return
	}
	if memmap.Uint32(0x5D4594, 1064940) != 0 {
		return
	}
	if legacy.Nox_xxx_playerAnimCheck_4372B0() != 0 {
		return
	}
	if nox_xxx_checkGameFlagPause_413A50() {
		return
	}
	if nox_xxx_guiCursor_477600() != 0 {
		return
	}
	if legacy.Nox_xxx_clientIsObserver_4372E0() != 0 {
		return
	}
	v42 := legacy.Sub_4675B0()
	if v42 == 5 {
		c.Nox_client_setCursorType(gui.CursorIdentify)
		return
	}
	if v42 == 6 {
		c.Nox_client_setCursorType(gui.CursorRepair)
		return
	}
	sprite := legacy.Nox_xxx_clientGetSpriteAtCursor_476F90()
	if sprite == nil {
		if legacy.Sub_479590() == 2 {
			c.Nox_client_setCursorType(gui.CursorBuy)
		} else if legacy.Sub_479590() == 3 {
			c.Nox_client_setCursorType(gui.CursorSell)
		}
		return
	}
	var v65 image.Point
	if sprite.Flags28()&0x400006 == 0 || legacy.Nox_xxx_sprite_4C3220(sprite) != 0 || sprite.Flags28()&2 != 0 && sprite.Flags29()&8 != 0 || sprite.Flags28()&2 != 0 && sprite.Flags70()&0x10 != 0 {
		v46 := legacy.Get_dword_5d4594_1062452()
		for v47 := c.GUI.Last(); v47 != nil; v47 = v47.Prev() {
			if v47.Flags.Has(gui.StatusHidden) {
				continue
			}
			mpos := c.Inp.GetMousePos()
			if v47.PointIn(mpos) {
				if v47 == v46 {
					v65 = mpos
					rect50 := loadRect(memmap.PtrOff(0x587000, 136384))
					if v65.In(rect50) {
						v63 = true
						break
					}
					rect52 := loadRect(memmap.PtrOff(0x587000, 136400))
					if v65.In(rect52) {
						v63 = true
						break
					}
				}
				if v47 != nil && legacy.Nox_xxx_wnd_46C2A0(v47) != 1 {
					return
				}
				break
			}
		}

		v65 = c.Viewport().World.Max
		sp := sprite.Pos()
		c1 := v65.X - sp.X
		c2 := v65.Y - sp.Y
		v54 := c1*c1 + c2*c2
		if sprite.Flags28()&0x80000000 == 0 || c.dragndropGetItem() != nil {
			if v54 < 125*125 {
				if p := getCurPlayer(); p != nil {
					if p.Field3680&0x200 == 0 && legacy.Sub_478030() == 0 {
						if sprite.Flags28()&2 != 0 && sprite.Flags70()&0x10 != 0 {
							c.Nox_client_setCursorType(gui.CursorTalk)
						} else if sprite.Flags28()&2 != 0 && sprite.Flags29()&8 != 0 {
							c.Nox_client_setCursorType(gui.CursorShop)
						}
					}
				}
			}
		} else {
			if v63 {
				v55 := legacy.Nox_xxx_clientAskInfoMb_4BF050(sprite)
				legacy.Nox_xxx_cursorSetTooltip_4776B0(v55)
			}
			if v54 >= 75*75 {
				c.Nox_client_setCursorType(gui.CursorPickupFar)
			} else {
				if noxflags.HasGame(noxflags.GameModeCoop|noxflags.GameModeQuest) || legacy.Sub_57B450(sprite) != 0 {
					c.Nox_client_setCursorType(gui.CursorPickup)
				} else {
					c.Nox_client_setCursorType(gui.CursorCaution)
				}
				v56 := legacy.Nox_client_mousePriKey_430AF0()
				if v66[v56] == legacy.Nox_xxx_cursor_430B00() {
					legacy.Nox_xxx_clientPickup_46C140(sprite)
					v66[v56] = 0
				}
			}
		}
	} else {
		mimic := memmap.Uint32(0x5D4594, 1064944)
		if mimic == 0 {
			mimic = uint32(c.Things.IndByID("Mimic"))
			*memmap.PtrUint32(0x5D4594, 1064944) = mimic
		}
		if sprite.Flags28()&0x400000 != 0 && sprite.Flags29()&0x80 != 0 && sprite.Flags70()&0xC == 0 || uint32(sprite.Field_27) == mimic && sprite.AnimInd == 0 {
			v65 = c.Viewport().World.Max
			sp := sprite.Pos()
			c1 := v65.X - sp.X
			c2 := v65.Y - sp.Y
			if c1*c1+c2*c2 < 75*75 && sprite.Flags30()&0x1000000 != 0 && sprite.Flags70()&0xC == 0 {
				c.Nox_client_setCursorType(gui.CursorUse)
			}
		}
	}
}

func (c *Client) nox_xxx_cursorUpdate_46B740() {
	var v0 *gui.Window
	var v1 *gui.Window
	var v23 *gui.Window
	var v61 *gui.Window
	v63 := false
	v64 := 0

	var states [4]int
	states[input.NOX_MOUSE_LEFT] = int(c.Inp.GetMouseState(seat.MouseButtonLeft))
	states[input.NOX_MOUSE_RIGHT] = int(c.Inp.GetMouseState(seat.MouseButtonRight))
	states[input.NOX_MOUSE_MIDDLE] = int(c.Inp.GetMouseState(seat.MouseButtonMiddle))
	states[3] = c.Inp.GetMouseWheel()

	mpos := c.Inp.GetMousePos()
	legacy.Nox_xxx_cursorSetTooltip_4776B0("")
	if nox_client_gui_flag_815132 != 0 || nox_xxx_guiCursor_477600() != 0 {
		c.Nox_client_setCursorType(gui.CursorSelect)
	} else {
		c.Nox_client_setCursorType(gui.CursorMoveArrow)
	}
	if c.GUI.Captured() != nil {
		c.Nox_client_setCursorType(gui.CursorSelect)
		c.GUI.WinYYY = nil
		child := c.GUI.Captured().ChildByPos(mpos)
		v1 = child
		for btn, v9 := range states {
			if v9 == 0 {
				if btn == int(input.NOX_MOUSE_LEFT) && c.Inp.IsMousePressed(seat.MouseButtonLeft) {
					child.Func93(&gui.WindowMouseState{State: input.NOX_MOUSE_LEFT_PRESSED, Pos: mpos})
				}
				continue
			}
			if child == nil {
				if gui.EventRespBool(c.GUI.Captured().Func93(&gui.WindowMouseState{State: input.MouseStateCode(v9), Pos: mpos})) {
					states[btn] = 0
				}
				continue
			}
			for v10 := child; v10 != nil; v10 = v10.Parent() {
				if gui.EventRespBool(v10.Func93(&gui.WindowMouseState{State: input.MouseStateCode(v9), Pos: mpos})) {
					states[btn] = 0
					break
				}
				if v10 == c.GUI.Captured() {
					break
				}
			}
		}
	} else if c.GUI.WinYYY != nil {
		c.Nox_client_setCursorType(gui.CursorSelect)
		switch input.MouseStateCode(states[input.NOX_MOUSE_LEFT]) {
		case 0, input.NOX_MOUSE_LEFT_PRESSED:
			if c.GUI.WinYYY.Flags.Has(4) && legacy.Sub_45D9B0() == 0 {
				dp := c.Inp.GetMouseRel()
				off := c.GUI.WinYYY.Offs()
				end := c.GUI.WinYYY.End()
				if par := c.GUI.WinYYY.Parent(); par != nil {
					psz := par.Size()
					if off.X+dp.X >= 0 {
						if dp.X+end.X > psz.X {
							dp.X = psz.X - end.X
						}
						v1 = nil
					} else {
						dp.X = -off.X
					}
					if off.Y+dp.Y >= 0 {
						if dp.Y+end.Y > psz.Y {
							dp.Y = psz.Y - end.Y
						}
					} else {
						dp.Y = -off.Y
					}
				}
				off = off.Add(dp)
				if off.X < 0 {
					off.X = 0
				}
				if off.Y < 0 {
					off.Y = 0
				}
				c.GUI.WinYYY.SetOffs(off)

				vsz := videoGetWindowSize()
				sz := c.GUI.WinYYY.Size()
				end = off.Add(sz)
				if end.X > vsz.X {
					end.X = vsz.X
				}
				if end.Y > vsz.Y {
					end.Y = vsz.Y
				}
				c.GUI.WinYYY.SetEnd(end)
				c.GUI.WinYYY.SetOffs(end.Sub(sz))
			}
			c.GUI.WinYYY.Func93(&gui.WindowMouseState{State: input.NOX_MOUSE_LEFT_PRESSED, Pos: mpos})
			states[input.NOX_MOUSE_LEFT] = 0
		case input.NOX_MOUSE_LEFT_DRAG_END:
			c.GUI.WinYYY.Flags &= 0xFFFFFFFE
			if c.GUI.WinYYY.ChildByPos(mpos) != nil {
				c.GUI.WinYYY.Func93(&gui.WindowMouseState{State: input.NOX_MOUSE_LEFT_DRAG_END, Pos: mpos})
			} else if c.GUI.WinYYY.Flags.Has(4) {
				c.GUI.WinYYY.Func93(&gui.WindowMouseState{State: input.NOX_MOUSE_LEFT_DRAG_END, Pos: mpos})
			}
			v64 = 1
			states[input.NOX_MOUSE_LEFT] = 0
		case input.NOX_MOUSE_LEFT_UP:
			c.GUI.WinYYY.Focus()
			c.GUI.WinYYY.Func93(&gui.WindowMouseState{State: input.NOX_MOUSE_LEFT_UP, Pos: mpos})
			v64 = 1
			states[input.NOX_MOUSE_LEFT] = 0
		default:
			states[input.NOX_MOUSE_LEFT] = 0
		}
	} else {
		if wa := c.GUI.StackHead(); wa != nil {
			v23 = wa.ChildByPos(mpos)
			goto LABEL_98
		}
		for v24 := c.GUI.Last(); v24 != nil; v24 = v24.Prev() {
			if !v24.Flags.Has(0x20) {
				continue
			}
			if v24.Flags.Has(0x10) {
				continue
			}
			if v24.PointIn(mpos) {
				v28 := legacy.Sub_46B630(v24, mpos.X, mpos.Y)
				if v0 == nil && (v28.TooltipFuncPtr.Ptr() != nil || v28.DrawData().Tooltip() != "") {
					v0 = v28
				}
				if v24.Flags.Has(8) {
					v61 = v0
					v1 = v24.ChildByPos(mpos)
					if v1 == nil {
						break
					}
					goto LABEL_99
				}
			}
		}
		for v29 := c.GUI.Last(); v29 != nil; v29 = v29.Prev() {
			if v29.Flags.Has(0x70) {
				continue
			}
			if v29.PointIn(mpos) {
				v32 := legacy.Sub_46B630(v29, mpos.X, mpos.Y)
				if v0 == nil && (v32.TooltipFuncPtr.Ptr() != nil || v32.DrawData().Tooltip() != "") {
					v0 = v32
				}
				if v29.Flags.Has(8) {
					v61 = v0
					v1 = v29.ChildByPos(mpos)
					if v1 == nil {
						break
					}
					goto LABEL_99
				}
			}
		}
		for v1 = c.GUI.Last(); v1 != nil; v1 = v1.Prev() {
			if !v1.Flags.Has(0x40) {
				continue
			}
			if v1.Flags.Has(0x10) {
				continue
			}
			if v1.PointIn(mpos) {
				v36 := legacy.Sub_46B630(v1, mpos.X, mpos.Y)
				if v0 == nil && (v36.TooltipFuncPtr.Ptr() != nil || v36.DrawData().Tooltip() != "") {
					v0 = v36
				}
				if v1.Flags.Has(8) {
					break
				}
			}
		}
		v61 = v0
		v23 = v1.ChildByPos(mpos)
	LABEL_98:
		v1 = v23
		if v23 == nil {
			goto LABEL_113
		}
	LABEL_99:
		v61 = v1
		if v1.Flags.Has(0x200) {
			v1 = nil
		} else if v1 != nil {
			c.Nox_client_setCursorType(gui.CursorSelect)
			for i, v39 := range states {
				if v39 == 0 {
					continue
				}
				win40 := v1
				// TODO: looks similar to Window.Focus, but doesn't check flags and uses different global
				if gui.EventRespBool(win40.Func93(&gui.WindowMouseState{State: input.MouseStateCode(v39), Pos: mpos})) {
					if i == 0 && states[0] == 5 {
						c.GUI.WinYYY = win40
					}
					states[i] = 0
				} else {
					for {
						win40 = win40.Parent()
						if win40 == nil {
							break
						}
						if gui.EventRespBool(win40.Func93(&gui.WindowMouseState{State: input.MouseStateCode(v39), Pos: mpos})) {
							if i == 0 && states[0] == 5 {
								c.GUI.WinYYY = win40
							}
							states[i] = 0
							break
						}
					}
				}
			}
			v0 = v61
		}
	LABEL_113:
		if v0 == nil && legacy.Nox_xxx_wnd_46C2A0(v1) != 0 {
			v0 = v1
		}
		if c.Inp.GetDistSlow() {
			if v0 != nil {
				if v0.TooltipFuncPtr.Ptr() != nil {
					sx := uint16(mpos.X)
					sy := uint16(mpos.Y)
					spos := uintptr(uint32(sx) | (uint32(sy) << 16))
					v0.TooltipFunc(spos)
				} else if str := v0.DrawData().Tooltip(); str != "" {
					legacy.Nox_xxx_cursorSetTooltip_4776B0(str)
				}
			} else {
				v63 = true
			}
		}
	}
	if c.GUI.WinYYY == nil && v1 != c.GUI.ActiveXXX {
		if c.GUI.Captured() != nil {
			if c.GUI.Captured().IsChild(c.GUI.ActiveXXX) {
				c.GUI.ActiveXXX.Func93(&gui.WindowMouseUnk{Event: 18, Pos: mpos})
			}
		} else if c.GUI.ActiveXXX != nil {
			c.GUI.ActiveXXX.Func93(&gui.WindowMouseUnk{Event: 18, Pos: mpos})
		}
		if v1 != nil {
			v1.Func93(&gui.WindowMouseUnk{Event: 17, Pos: mpos})
		}
		c.GUI.ActiveXXX = v1
	}
	c.nox_xxx_cursorUpdate_46B740_sprites(v63, states[:])
	c.Inp.SetMouseState(seat.MouseButtonLeft, input.MouseStateCode(states[input.NOX_MOUSE_LEFT]))
	c.Inp.SetMouseState(seat.MouseButtonRight, input.MouseStateCode(states[input.NOX_MOUSE_RIGHT]))
	c.Inp.SetMouseState(seat.MouseButtonMiddle, input.MouseStateCode(states[input.NOX_MOUSE_MIDDLE]))
	c.Inp.SetMouseWheel(states[3])
	if v64 == 1 {
		c.GUI.WinYYY = nil
	}
	c.GUI.FreeDestroyed()
}
