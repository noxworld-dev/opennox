package opennox

import (
	"fmt"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	client.RegisterDraw("MonsterDraw", legacy.Get_nox_thing_monster_draw(), 7, parseMonsterDraw)
}

func parseMonsterDraw(obj *client.ObjectType, f *binfile.MemFile, _ string, _ []byte) error {
	dd, _ := alloc.New(client.MonsterDrawData{})
	dd.Size = uint32(unsafe.Sizeof(client.MonsterDrawData{}))
	for {
		tok := f.ReadU32()
		if tok == 0x454E4420 { // "END "
			break
		}
		ind := f.ReadU8()
		if int(ind) >= len(dd.Anim) {
			return fmt.Errorf("invalid animation index: %d", int(ind))
		}
		f.SkipString8()
		f.SkipString8()
		ani := &dd.Anim[ind]
		if err := nox_xxx_loadVectorAnimated_44B8B0(ani, f); err != nil {
			return err
		}
		if err := nox_xxx_loadVectorAnimated_44BC50(ani, f); err != nil {
			return err
		}
	}
	obj.DrawFunc = legacy.Get_nox_thing_monster_draw()
	obj.DrawData = unsafe.Pointer(dd)
	return nil
}

func (c *Client) DrawMonster(vp *noxrender.Viewport, dr *client.Drawable) int {
	dd := (*client.MonsterDrawData)(dr.DrawData)
	if !noxflags.HasGame(noxflags.GameFlag22) {
		d := dr.UnionMonster()
		if dr.AnimDir != d.Field_108_0 {
			if dr.AnimInd != 1 && dr.AnimInd != 3 && dr.AnimInd != 5 {
				if (c.Server.Frame() - d.Field_109) >= c.Server.TickRate()/4 {
					d.Field_109 = c.Server.Frame()
					d.Field_108_0 = dr.AnimDir
				} else {
					dr.AnimDir = d.Field_108_0
				}
			}
		}
	}
	ani := &dd.Anim[dr.AnimInd]
	if ani.Cnt40 == 0 {
		// no animation :(
		return 1
	}
	res := 1
	if int(dr.TypeIDVal) == c.Things.IndByID("Ghost") {
		// Ghosts are only visible up close or with infravision
		var dp image.Point
		if !noxflags.HasGame(noxflags.GameFlag22) {
			dp = dr.PosVec.Sub(c.ClientPlayerUnit().PosVec)
		}
		if c.ClientPlayerUnit() != nil && c.ClientPlayerUnit().HasEnchant(server.ENCHANT_INFRAVISION) {
			c.r.Data().SetColorize17(1)
			c.r.SetColorMultAndIntensity(nox_color_green)
			c.r.Data().SetAlphaEnabled(true)
			c.r.Data().SetAlpha(255)
			c.drawMonsterUpdate(dr)
			res = c.drawAnimVector(vp, dr, ani)
			c.r.Data().SetColorize17(0)
		} else if dp.X*dp.X+dp.Y*dp.Y < 40000 {
			c.r.Data().SetAlphaEnabled(true)
			c.r.Data().SetAlpha(0)
			c.drawMonsterUpdate(dr)
			res = c.drawAnimVector(vp, dr, ani)
			c.r.Data().SetColorize17(0)
		} else {
			// do not draw the ghost at all
		}
	} else {
		c.drawMonsterUpdate(dr)
		res = c.drawAnimVector(vp, dr, ani)
		c.r.Data().SetColorize17(0)
	}
	c.DrawEnchantsTop(vp, dr)
	c.DrawMonsterHP(vp, dr)
	if !noxflags.HasGamePlay(noxflags.GameplayFlag4) && (c.ClientPlayerUnit() == nil || !c.ClientPlayerUnit().TeamPtr().Has()) {
		c.r.Data().SetAlphaEnabled(false)
		return res
	}
	var t *server.ObjectTeam
	if !noxflags.HasGame(noxflags.GameHost) {
		t = c.ClientPlayerUnit().TeamPtr()
	} else if pl := c.Server.Players.ByInd(server.HostPlayerIndex); pl != nil && pl.PlayerUnit != nil {
		t = pl.PlayerUnit.TeamPtr()
	}
	// If monster belongs to the same team as the player - show the colored dot.
	if t != nil {
		drawDot := false
		tm := c.Server.Teams.ByID(t.ID)
		if tm != nil && legacy.Sub_495A80(dr.NetCode32) != 0 {
			drawDot = true
		}
		// Looks like shopkeepers are in the player's team in Quest, so they are excluded here explicitly.
		// Otherwise, they will also show a dot on top.
		if drawDot && noxflags.HasGame(noxflags.GameModeQuest) && dr.Class().Has(object.ClassMonster) && dr.SubClass().AsMonster().Has(object.MonsterShopkeeper) {
			drawDot = false
		}
		if drawDot {
			cl := c.Server.Teams.GetTeamColor(tm)
			pos := dr.PosVec
			pos = pos.Add(image.Point{Y: -(int(dr.ZVal) + int(dr.ZSizeMax)*2)})
			pos = vp.ToScreenPos(pos)
			c.r.DrawPointRad(pos, 3, cl)
		}
	}
	c.r.Data().SetAlphaEnabled(false)
	return res
}

func (c *Client) drawMonsterUpdate(dr *client.Drawable) {
	if !dr.SubClass().AsMonster().Has(object.MonsterLookAround) {
		return
	}
	if dr.AnimInd != 8 { // IDLE
		return
	}
	if c.Server.Frame()&3 != 0 {
		return
	}
	switch dr.AnimFrameSlave {
	case 0:
		if v := c.Server.Rand.Other.Int(0, 100); v < 15 {
			dr.Field_74_4 = 0
			dr.AnimFrameSlave++
		}
	case 2:
		if v := c.Server.Rand.Other.Int(0, 100); v < 5 {
			dr.Field_74_4 = 1
			dr.AnimFrameSlave--
		} else if v < 10 {
			dr.Field_74_4 = 2
			dr.AnimFrameSlave++
		}
	case 4:
		if v := c.Server.Rand.Other.Int(0, 100); v < 15 {
			dr.Field_74_4 = 0
			dr.AnimFrameSlave--
		}
	default:
		switch dr.Field_74_4 {
		case 0:
			if dr.AnimFrameSlave < 2 {
				dr.AnimFrameSlave++
			} else {
				dr.AnimFrameSlave--
			}
		case 1:
			dr.AnimFrameSlave--
			return
		case 2:
			dr.AnimFrameSlave++
		default:
			dr.AnimFrameSlave = 2
			dr.Field_74_4 = 0
		}
	}
}

func (c *Client) DrawMonsterHP(vp *noxrender.Viewport, dr *client.Drawable) {
	if legacy.Nox_xxx_unitSpriteCheckAlly_4951F0(int(dr.NetCode32)) {
		curHP, maxHP, alt, _ := legacy.Sub_495180(int(dr.NetCode32))
		c.drawMonsterHP(vp, dr, curHP, maxHP, alt)
	}
}

func (c *Client) drawMonsterHP(vp *noxrender.Viewport, dr *client.Drawable, curHP int, maxHP int, alt bool) {
	if dr == nil {
		return
	}
	pos := dr.PosVec
	pos = pos.Add(image.Point{X: int(2 * dr.Shape.Circle.R), Y: -int(dr.ZVal)})
	pos = vp.ToScreenPos(pos)

	zsz := int(dr.ZSizeMax - dr.ZSizeMin)
	if zsz < 30 {
		zsz = 30
	}
	barSize := zsz
	v12 := int(dr.ZSizeMin + dr.ZSizeMax)
	pos.Y -= v12/2 + barSize/2
	if int32(maxHP) == 0 {
		return
	}

	c.r.DrawRectFilledOpaque(pos.X, pos.Y, 2, barSize, nox_color_black_2650656)
	cl := nox_color_red
	if alt {
		cl = nox_color_green
	}
	c.r.DrawRectFilledOpaque(pos.X, pos.Y+barSize-barSize*curHP/maxHP, 2, barSize*curHP/maxHP, cl)
}
