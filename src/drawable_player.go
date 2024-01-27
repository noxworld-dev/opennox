package opennox

import (
	"fmt"
	"image"
	"image/color"
	"slices"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	client.RegisterDraw("PlayerDraw", legacy.Get_nox_thing_player_draw(), 6, parsePlayerDraw)
}

func parsePlayerDraw(obj *client.ObjectType, f *binfile.MemFile, str string, buf []byte) error {
	dd, _ := alloc.New(client.PlayerDrawData{})
	dd.Size = uint32(unsafe.Sizeof(client.PlayerDrawData{}))
	tok := f.ReadU32()
	if tok == 0x454E4420 { // "END "
		return fmt.Errorf("unexpected end of player anim")
	}
loop:
	for {
		attr, _ := f.ReadString8()
		aind := slices.Index(server.PlayerAnimNames[:], attr)
		if aind < 0 {
			return fmt.Errorf("unsupported player animation: %q", attr)
		}
		panim := &dd.Anim[aind]
		if err := nox_xxx_loadVectorAnimated_44B8B0(&panim.Base, f); err != nil {
			return err
		}
		for {
			tok = f.ReadU32()
			if tok == 0x454E4420 { // "END "
				obj.DrawFunc = legacy.Get_nox_thing_player_draw()
				obj.DrawData = unsafe.Pointer(dd)
				return nil
			}
			if tok == 0x53544154 {
				continue loop
			}
			attr, _ = f.ReadString8()
			if attr == "NAKED" {
				p, _ := alloc.New(client.PlayerEquipAnimation{})
				panim.Naked = p
				if err := parsePlayerEquipAnim(p, int(panim.Base.Cnt40), f); err != nil {
					return err
				}
			} else if ind := slices.Index(server.PlayerArmorNames[:], attr); ind >= 0 {
				p, _ := alloc.New(client.PlayerEquipAnimation{})
				panim.Armor[ind] = p
				if err := parsePlayerEquipAnim(p, int(panim.Base.Cnt40), f); err != nil {
					return err
				}
			} else if ind = slices.Index(server.PlayerWeaponNames[:], attr); ind >= 0 {
				p, _ := alloc.New(client.PlayerEquipAnimation{})
				panim.Weapon[ind] = p
				if err := parsePlayerEquipAnim(p, int(panim.Base.Cnt40), f); err != nil {
					return err
				}
			} else {
				return fmt.Errorf("unsupported player animation: %q", attr)
			}
		}
	}
}

func parsePlayerEquipAnim(ani *client.PlayerEquipAnimation, cnt int, f *binfile.MemFile) error {
	ani.Size = uint32(unsafe.Sizeof(client.PlayerEquipAnimation{}))
	for i := 0; i < 8; i++ {
		k := i
		if i >= 4 {
			k = i + 1
		}
		arr, _ := alloc.Make([]noxrender.ImageHandle{}, cnt)
		ani.Frames[k] = &arr[0]
		for j := 0; j < cnt; j++ {
			ind := int(f.ReadI32())
			var (
				typ   byte
				name2 string
			)
			if ind == -1 {
				typ = f.ReadU8()
				name2, _ = f.ReadString8()
			}
			arr[j] = noxClient.r.Bag.ImageRef(ind, typ, name2).C()
		}
	}
	return nil
}

func (c *Client) DrawPlayer(vp *noxrender.Viewport, dr *client.Drawable) int {
	pl := c.Server.Players.ByID(int(dr.NetCode32))
	if pl == nil {
		return 1
	}
	v30 := false
	if pl2 := getCurPlayer(); pl2 != nil && pl2.Field3680&0x1 != 0 {
		v30 = true
	}
	var (
		sameTeam = false
		tm       *server.Team
	)
	if legacy.ClientPlayerNetCode() == int(dr.NetCode32) {
		if t := nox_xxx_objGetTeamByNetCode_418C80(legacy.ClientPlayerNetCode()); t != nil {
			tm = c.Server.Teams.ByID(t.ID)
		}
	} else {
		if pl.Field3680&0x1 != 0 {
			return 1
		}
		if t1 := nox_xxx_objGetTeamByNetCode_418C80(legacy.ClientPlayerNetCode()); t1 != nil {
			if t2 := nox_xxx_objGetTeamByNetCode_418C80(int(dr.NetCode32)); t2 != nil {
				sameTeam = t1.SameAs(t2)
				tm = c.Server.Teams.ByID(t2.ID)
			}
		}
	}
	if pl.WeaponEquip&0x1 != 0 {
		c.DrawFlagOn(vp, dr, &pl.Weapon)
	}
	var colors [6]noxcolor.RGBA5551
	for i, v := range [6]uint32{
		// Despite the names, the layout in the Player structure is not sequential!
		pl.Color0, pl.Color1, pl.Color2, pl.Color3, pl.Color4, pl.Color5,
	} {
		colors[i] = noxcolor.RGBA5551(v)
	}
	c.EnchantColorize(dr, pl.Field3680&0x400 != 0, colors[:])
	for i, cl := range colors {
		c.r.Data().SetMaterial(i+1, cl)
	}
	img, panim, fi := c.sub_4B8FA0(dr)
	if img == nil {
		return 0
	}
	legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, img)
	c.DrawArmorAndWeapon(vp, dr, pl, panim, fi)
	for i := range colors {
		c.r.Data().SetMaterial(i+1, nox_color_white_2523948)
	}
	if !(v30 || !dr.HasEnchant(0) || int(dr.NetCode32) == legacy.ClientPlayerNetCode() || c.ClientPlayerUnit() != nil && (c.ClientPlayerUnit().HasEnchant(server.ENCHANT_INFRAVISION) || sameTeam)) {
		return 1
	}
	c.DrawPlayerName(vp, dr, tm, pl.Name())
	c.DrawEnchantsTop(vp, dr)
	if !(dr != c.ClientPlayerUnit() && legacy.Nox_xxx_playerGet_470A90() != 0) {
		return 1
	}
	if noxflags.HasGame(noxflags.GameModeQuest) {
		c.drawOtherPlayerHP(vp, dr, int(pl.Field2282&0xff), (pl.Field3680>>10)&1 != 0)
	}
	return 1
}

func hasChatBubble(dr *client.Drawable) bool {
	return legacy.Nox_xxx_netCode2ChatBubble_48D850(int(dr.NetCode32)) != 0
}

func (c *Client) sub_4B8FA0(dr *client.Drawable) (noxrender.ImageHandle, *client.PlayerAnimation, int) {
	dd := (*client.PlayerDrawData)(dr.DrawData)
	var aind int32
	if dr.AnimInd != 0 || !hasChatBubble(dr) {
		if dr.AnimInd != 4 {
			aind = int32(dr.AnimInd)
		} else if !dr.HasEnchant(server.ENCHANT_SNEAK) {
			aind = int32(dr.AnimInd)
		} else {
			aind = 53
		}
	} else {
		aind = 19
	}
	panim := &dd.Anim[aind]
	if panim.Base.Cnt40 == 0 {
		return nil, nil, -1
	}
	ind := c.getAnimFrameInd(dr, &panim.Base)
	if ind < 0 {
		return nil, nil, -1
	}
	arr := panim.FramesSlice(panim.Naked.Frames[dr.AnimDir])
	if ind >= len(arr) {
		ind = len(arr) - 1
	}
	return arr[ind], panim, ind
}

func (c *Client) DrawPlayerName(vp *noxrender.Viewport, dr *client.Drawable, tm *server.Team, name string) {
	if hasChatBubble(dr) || noxflags.HasGame(noxflags.GameModeCoop) {
		return
	}
	sz := c.r.GetStringSizeWrapped(nil, name, 0)
	pos := dr.PosVec
	pos = pos.Add(image.Point{X: -sz.X / 2, Y: -64})
	pos = vp.ToScreenPos(pos)
	c.r.Data().SetTextColor(nox_color_gray1)
	c.r.DrawString(nil, name, pos.Add(image.Point{X: 1, Y: 1}))
	var textCl color.Color = noxcolor.RGB5551Color(155, 155, 155)
	if c.Server.Teams.Count() != 0 && tm != nil {
		textCl = c.Server.Teams.GetTeamColor(tm)
	}
	c.r.Data().SetTextColor(textCl)
	c.r.DrawString(nil, name, pos)
}

func (c *Client) DrawArmorAndWeapon(vp *noxrender.Viewport, dr *client.Drawable, h server.ArmorAndWeaponHolder, panim *client.PlayerAnimation, fi int) {
	// A player in Nox has a 32-bit integer field that contains bits for each
	// type of armor / weapon. DrawWeapon and DrawArmor are responsible for iterating
	// over each type and drawing it to the screen.
	//
	// The Z ordering is simple to understand. Usually Nox will draw the player
	// body, and then the armor / weapon on top (or vice versa depending on
	// rotation). The quiver is unique because it is on the player's back, e.g.
	// it must be drawn first, then the body, then the rest of the armor.
	weapEquip, weapArr := h.WeaponData()
	armorEquip, armorArr := h.ArmorData()
	if dr.AnimDir != 1 && dr.AnimDir != 0 && dr.AnimDir != 2 && dr.AnimDir != 3 && dr.AnimDir != 6 || dr.AnimInd == 37 {
		c.DrawWeapon(vp, dr, weapEquip&2, weapArr, panim, fi)
		c.DrawArmor(vp, dr, armorEquip, armorArr, panim, fi)
		c.DrawWeapon(vp, dr, weapEquip&^2, weapArr, panim, fi)
	} else {
		c.DrawWeapon(vp, dr, weapEquip&^2, weapArr, panim, fi)
		c.DrawArmor(vp, dr, armorEquip, armorArr, panim, fi)
		c.DrawWeapon(vp, dr, weapEquip&2, weapArr, panim, fi)
	}
}

func (c *Client) DrawArmor(vp *noxrender.Viewport, dr *client.Drawable, equip uint32, earr *server.EquipArmorData, panim *client.PlayerAnimation, fi int) {
	invul := dr.HasEnchant(server.ENCHANT_INVULNERABLE)
	cl := nox_color_blue_2650684
	if c.Server.Frame()%2 != 0 {
		cl = nox_color_white_2523948
	}
	drawCloak := false
	if equip&2 != 0 {
		if (dr.AnimDir == 6 || dr.AnimDir == 7 || dr.AnimDir == 8) &&
			dr.AnimInd != 6 && dr.AnimInd != 35 && dr.AnimInd != 39 && dr.AnimInd != 40 {
			for i, eanim := range panim.Armor {
				if ((1 << i) & 2) != 0 {
					if eanim != nil {
						if invul {
							for j := 0; j < 6; j++ {
								c.r.Data().SetMaterial(j+1, cl)
							}
						} else {
							sub_4B8CA0(earr, 2)
						}
						frames := panim.FramesSlice(eanim.Frames[dr.AnimDir])
						legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
						drawCloak = true
					}
					break
				}
			}
		}
	}
	drawShield := false
	const shieldBits = (1 << 24) | (1 << 25)
	for i, eanim := range panim.Armor {
		if eanim == nil {
			continue
		}
		bit := 1 << i
		if (bit & 2) != 0 {
			continue
		}
		if (bit&shieldBits) == 0 || (dr.AnimDir != 3 && dr.AnimDir != 0 && dr.AnimDir != 6 && dr.AnimDir != 7) {
			if bit&int(equip) != 0 && (bit&0xC00 == 0 || equip&0x4000 == 0) {
				if invul {
					for j := 0; j < 6; j++ {
						c.r.Data().SetMaterial(j+1, cl)
					}
				} else {
					sub_4B8CA0(earr, 1<<i)
				}
				frames := panim.FramesSlice(eanim.Frames[dr.AnimDir])
				legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
				if bit&shieldBits != 0 {
					drawShield = true
				}
			}
		}
	}
	if equip&2 != 0 && !drawCloak {
		for i, eanim := range panim.Armor {
			if ((1 << i) & 2) != 0 {
				// TODO: this was taking index 19 instead of i for animation; why?
				if eanim != nil {
					if invul {
						for j := 0; j < 6; j++ {
							c.r.Data().SetMaterial(j+1, cl)
						}
					} else {
						sub_4B8CA0(earr, 2)
					}
					frames := panim.FramesSlice(eanim.Frames[dr.AnimDir])
					legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
				}
				break
			}
		}
	}
	if !drawShield && equip&shieldBits != 0 {
		bit := 0x2000000
		if (equip & 0x1000000) != 0 {
			bit = 0x1000000
		}
		for i, eanim := range panim.Armor {
			if ((1 << i) & bit) != 0 {
				if eanim != nil {
					if invul {
						for j := 0; j < 6; j++ {
							c.r.Data().SetMaterial(j+1, cl)
						}
					} else {
						sub_4B8CA0(earr, uint32(bit))
					}
					frames := panim.FramesSlice(eanim.Frames[dr.AnimDir])
					legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
				}
				break
			}
		}
	}
}
func sub_4B8CA0(earr *server.EquipArmorData, bit uint32) {
	c := noxClient
	var found *server.EquipmentData
	for i := range earr {
		e := &earr[i]
		if e.Field0 == bit {
			found = e
			break
		}
	}
	if found == nil {
		return
	}
	id := c.Server.Armor.Sub_415CD0(bit)
	m := c.Server.Modif.Nox_xxx_equipClothFindDefByTT413270(id)
	if m == nil {
		return
	}
	for i := 0; i < 6; i++ { // TODO: are bounds correct?
		cl := m.Colors12[i]
		c.r.Data().SetMaterialRGB(i, int(cl.R), int(cl.G), int(cl.B))
	}
	inds := m.ColorIndexes()
	for i := 0; i < 4; i++ {
		p := found.Field4[i]
		if p != nil {
			cl := *(*server.ModColor)(unsafe.Add(p, 24))
			c.r.Data().SetMaterialRGB(int(inds[i]), int(cl.R), int(cl.G), int(cl.B))
		}
	}
}
func (c *Client) DrawWeapon(vp *noxrender.Viewport, dr *client.Drawable, equip uint32, earr *server.EquipWeaponData, panim *client.PlayerAnimation, fi int) {
	eff := dr.HasEnchant(server.ENCHANT_FREEZE) // TODO: should be ENCHANT_INVULNERABLE ?
	cl := nox_color_blue_2650684
	if c.Server.Frame()%2 != 0 {
		cl = nox_color_white_2523948
	}
	for i := 1; i < len(panim.Weapon); i++ {
		if (1<<i)&equip == 0 {
			continue
		}
		eani := panim.Weapon[i]
		if eani == nil {
			continue
		}
		if eff {
			for j := 0; j < 6; j++ {
				c.r.Data().SetMaterial(j+1, cl)
			}
		} else {
			c.sub_4B8E10(earr, 1<<i)
		}
		frames := panim.FramesSlice(eani.Frames[dr.AnimDir])
		legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
	}
}
func (c *Client) sub_4B8E10(earr *[server.PlayerWeaponCnt]server.EquipmentData, bit uint32) {
	var found *server.EquipmentData
	for i := range earr {
		e := &earr[i]
		if e.Field0 == bit {
			found = e
			break
		}
	}
	if found == nil {
		return
	}
	id := c.Server.Weapons.Sub_415840(bit)
	m := c.Server.Modif.Nox_xxx_getProjectileClassById413250(id)
	if m == nil {
		return
	}
	for i := 0; i < 5; i++ { // TODO: are bounds correct?
		cl := m.Colors12[i]
		c.r.Data().SetMaterialRGB(i, int(cl.R), int(cl.G), int(cl.B))
	}
	inds := m.ColorIndexes()
	for i := 0; i < 4; i++ {
		p := found.Field4[i]
		if p != nil {
			cl := *(*server.ModColor)(unsafe.Add(p, 24))
			c.r.Data().SetMaterialRGB(int(inds[i]), int(cl.R), int(cl.G), int(cl.B))
		}
	}
}
func (c *Client) drawOtherPlayerHP(vp *noxrender.Viewport, dr *client.Drawable, perc int, alt bool) {
	if dr == nil {
		return
	}
	const (
		height = 48
		border = 2
	)
	pos := vp.ToScreenPos(dr.PosVec)
	pos = pos.Add(image.Point{
		X: int(2 * dr.Shape.Circle.R),
		Y: -int(dr.ZVal) - height,
	})
	c.r.DrawRectFilledOpaque(pos.X, pos.Y, border, height, nox_color_black_2650656)
	cl := noxcolor.RGBA5551(memmap.Uint32(0x85B3FC, 940))
	if alt {
		cl = nox_color_green
	}
	c.r.DrawRectFilledOpaque(pos.X, pos.Y-perc*height/100+height, border, perc*height/100, cl)
	cl = nox_color_violet_2598268
	if alt {
		cl = noxcolor.RGBA5551(memmap.Uint32(0x85B3FC, 984))
	}
	c.r.DrawBorder(pos.X-1, pos.Y-1, border+border, height+border, cl)
}
