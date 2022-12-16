package client

import (
	"image"
	"image/color"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

func (c *Client) drawProtectParticle(vp *noxrender.Viewport, part, tail image.Point, partCl, tailCl color.Color) { // nox_client_drawXxxProtectParticle_474DD0
	part = vp.ToScreenPos(part)
	tail = vp.ToScreenPos(tail)

	c.r.DrawGlow(part, partCl, 10, 12)
	c.r.DrawPoint(part, 3, tailCl)
	c.r.DrawLine(part, tail, tailCl)
}

func (c *Client) DrawProtectEffectDefault(vp *noxrender.Viewport, pos image.Point, dr *Drawable, phase, eff int, cl1, cl2 color.Color, back bool) { // nox_client_drawXxxProtect_474BE0
	opts := ProtectEffect{
		Cnt:       2,
		Height:    20,
		Speed:     10,
		Phase:     phase,
		Radius:    1.0,
		TailLeng:  6,
		GlowColor: cl1,
		TailColor: cl2,
	}
	switch eff {
	case 1:
		opts.Radius = 0.70709997
		opts.Angle = +35
	case 2:
		opts.Radius = 0.70709997
		opts.Angle = -35
	}
	c.drawProtectEffect(vp, pos, dr, opts, back)
}

type ProtectEffect struct {
	Cnt       int
	Height    int
	Speed     int
	Radius    float32
	Angle     int
	Phase     int
	TailLeng  int
	GlowColor color.Color
	TailColor color.Color
}

func intAngle(val, min, max int) int {
	sz := max - min
	for val < min {
		val += sz
	}
	for val >= max {
		val -= sz
	}
	return val
}

func (c *Client) drawProtectEffect(vp *noxrender.Viewport, pos image.Point, dr *Drawable, opts ProtectEffect, back bool) { // nox_client_drawXxxProtect
	frame := c.r.Frame()
	phi := opts.Phase + opts.Speed*int(byte(frame)+byte(dr.Field32()))
	for i := 0; i < opts.Cnt; i++ {
		// Calculate positions of two points on a (possibly inclined) orbit.
		// These two points are used to draw a tiny vector, where the head is the particle, and the line is a tail.
		ph1 := phi + (256/opts.Cnt)*i
		ph2 := ph1 - opts.TailLeng

		ph1 = intAngle(ph1, 0, 256)
		ph2 = intAngle(ph2, 0, 256)

		rad := opts.Radius
		part := image.Point{
			X: int(2 * rad * float32(sincosTable16[ph1].X)),
			Y: int(2 * rad * float32(sincosTable16[ph1].Y)),
		}

		draw := false
		if back {
			draw = part.Y < pos.Y
		} else {
			draw = part.Y >= pos.Y
		}
		if !draw {
			continue
		}
		tail := image.Point{
			X: int(2 * rad * float32(sincosTable16[ph2].X)),
			Y: int(2 * rad * float32(sincosTable16[ph2].Y)),
		}
		part = part.Add(pos)
		tail = tail.Add(pos)

		dy := opts.Angle * (pos.X - part.X) / (2 * sincosTable16[0].X)
		dy -= opts.Height + dr.Z()
		part.Y += dy
		tail.Y += dy
		c.drawProtectParticle(vp, part, tail, opts.GlowColor, opts.TailColor)
	}
}

// sincosTable16 assumes circle radius of 16, and expects an angle in range [0,256).
var sincosTable16 = []image.Point{
	{16, 0}, {16, 0}, {16, 1}, {16, 1}, {16, 2}, {16, 2}, {16, 2}, {16, 3},
	{16, 3}, {16, 4}, {16, 4}, {15, 4}, {15, 5}, {15, 5}, {15, 5}, {15, 6},
	{15, 6}, {15, 6}, {14, 7}, {14, 7}, {14, 8}, {14, 8}, {14, 8}, {14, 9},
	{13, 9}, {13, 9}, {13, 10}, {13, 10}, {12, 10}, {12, 10}, {12, 11}, {12, 11},
	{11, 11}, {11, 12}, {11, 12}, {10, 12}, {10, 12}, {10, 13}, {10, 13}, {9, 13},
	{9, 13}, {9, 14}, {8, 14}, {8, 14}, {8, 14}, {7, 14}, {7, 14}, {6, 15},
	{6, 15}, {6, 15}, {5, 15}, {5, 15}, {5, 15}, {4, 15}, {4, 16}, {4, 16},
	{3, 16}, {3, 16}, {2, 16}, {2, 16}, {2, 16}, {1, 16}, {1, 16}, {0, 16},
	{0, 16}, {0, 16}, {0, 16}, {0, 16}, {-1, 16}, {-1, 16}, {-1, 16}, {-2, 16},
	{-2, 16}, {-3, 16}, {-3, 16}, {-3, 15}, {-4, 15}, {-4, 15}, {-4, 15}, {-5, 15},
	{-5, 15}, {-5, 15}, {-6, 14}, {-6, 14}, {-7, 14}, {-7, 14}, {-7, 14}, {-8, 14},
	{-8, 13}, {-8, 13}, {-9, 13}, {-9, 13}, {-9, 12}, {-9, 12}, {-10, 12}, {-10, 12},
	{-10, 11}, {-11, 11}, {-11, 11}, {-11, 10}, {-11, 10}, {-12, 10}, {-12, 10}, {-12, 9},
	{-12, 9}, {-13, 9}, {-13, 8}, {-13, 8}, {-13, 8}, {-13, 7}, {-13, 7}, {-14, 6},
	{-14, 6}, {-14, 6}, {-14, 5}, {-14, 5}, {-14, 5}, {-14, 4}, {-15, 4}, {-15, 4},
	{-15, 3}, {-15, 3}, {-15, 2}, {-15, 2}, {-15, 2}, {-15, 1}, {-15, 1}, {-15, 0},
	{-15, 0}, {-15, 0}, {-15, 0}, {-15, 0}, {-15, -1}, {-15, -1}, {-15, -1}, {-15, -2},
	{-15, -2}, {-15, -3}, {-15, -3}, {-14, -3}, {-14, -4}, {-14, -4}, {-14, -4}, {-14, -5},
	{-14, -5}, {-14, -5}, {-13, -6}, {-13, -6}, {-13, -7}, {-13, -7}, {-13, -7}, {-13, -8},
	{-12, -8}, {-12, -8}, {-12, -9}, {-12, -9}, {-11, -9}, {-11, -9}, {-11, -10}, {-11, -10},
	{-10, -10}, {-10, -11}, {-10, -11}, {-9, -11}, {-9, -11}, {-9, -12}, {-9, -12}, {-8, -12},
	{-8, -12}, {-8, -13}, {-7, -13}, {-7, -13}, {-7, -13}, {-6, -13}, {-6, -13}, {-5, -14},
	{-5, -14}, {-5, -14}, {-4, -14}, {-4, -14}, {-4, -14}, {-3, -14}, {-3, -15}, {-3, -15},
	{-2, -15}, {-2, -15}, {-1, -15}, {-1, -15}, {-1, -15}, {0, -15}, {0, -15}, {0, -15},
	{0, -15}, {0, -15}, {1, -15}, {1, -15}, {2, -15}, {2, -15}, {2, -15}, {3, -15},
	{3, -15}, {4, -15}, {4, -15}, {4, -14}, {5, -14}, {5, -14}, {5, -14}, {6, -14},
	{6, -14}, {6, -14}, {7, -13}, {7, -13}, {8, -13}, {8, -13}, {8, -13}, {9, -13},
	{9, -12}, {9, -12}, {10, -12}, {10, -12}, {10, -11}, {10, -11}, {11, -11}, {11, -11},
	{11, -10}, {12, -10}, {12, -10}, {12, -9}, {12, -9}, {13, -9}, {13, -9}, {13, -8},
	{13, -8}, {14, -8}, {14, -7}, {14, -7}, {14, -7}, {14, -6}, {14, -6}, {15, -5},
	{15, -5}, {15, -5}, {15, -4}, {15, -4}, {15, -4}, {15, -3}, {16, -3}, {16, -3},
	{16, -2}, {16, -2}, {16, -1}, {16, -1}, {16, -1}, {16, 0}, {16, 0}, {16, 0},
}
