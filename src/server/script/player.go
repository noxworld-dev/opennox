package script

import (
	"nox/v1/common/types"
)

type Player interface {
	ObjectWrapper // proxies to Unit
	Positionable  // proxies to Unit
	Named
	// IsHost checks if this player hosts the game.
	IsHost() bool
	Printer
	// Blind or unblind the player.
	Blind(v bool)
	// Cinema enables wide-screen "cinema" mode.
	Cinema(v bool)
	// Unit that the player controls.
	Unit() Unit
}

var _ Player = BasePlayer{}

// BasePlayer implements Player, but panics on all the methods.
// Useful when you only want to define a part of the implementation.
type BasePlayer struct{}

func (BasePlayer) GetObject() Object {
	panic("implement me")
}

func (BasePlayer) Pos() types.Pointf {
	panic("implement me")
}

func (BasePlayer) SetPos(p types.Pointf) {
	panic("implement me")
}

func (BasePlayer) String() string {
	panic("implement me")
}

func (BasePlayer) Name() string {
	panic("implement me")
}

func (BasePlayer) IsHost() bool {
	panic("implement me")
}

func (BasePlayer) Print(text string) {
	panic("implement me")
}

func (BasePlayer) Blind(v bool) {
	panic("implement me")
}

func (BasePlayer) Cinema(v bool) {
	panic("implement me")
}

func (BasePlayer) Unit() Unit {
	panic("implement me")
}
