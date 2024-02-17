package server

import (
	"github.com/noxworld-dev/opennox-lib/object"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

type playerCamper struct {
	s         *Server
	LastCheck uint32
	RadiusSq  float64
	StartTime uint32
	FadeTime  uint32
}

func (s *playerCamper) init(srv *Server) {
	s.s = srv
}

func (s *playerCamper) Reset() {
	s.LastCheck = 0
	s.RadiusSq = s.s.Balance.Float("CamperRadiusSq")
	s.StartTime = uint32(s.s.Balance.Float("CamperStartTime"))
	s.FadeTime = uint32(s.s.Balance.Float("CamperFadeTime"))
}

func (s *playerCamper) Update() {
	if (s.s.Frame() - s.s.Players.Camper.LastCheck) > s.s.Players.Camper.StartTime {
		for it := s.s.Players.FirstUnit(); it != nil; it = s.s.Players.NextUnit(it) {
			if it.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
				continue
			}
			ud := it.UpdateDataPlayer()
			if (ud.Player.Field3680 & 1) == 0 {
				dx := float64(it.PosVec.X - float32(int32(ud.Field62)))
				dy := float64(it.PosVec.Y - float32(int32(ud.Field63)))
				if dx*dx+dy*dy < s.s.Players.Camper.RadiusSq {
					ud.Field64 = s.s.Frame()
				}
				ud.Field62 = uint32(int32(it.PosVec.X))
				ud.Field63 = uint32(int32(it.PosVec.Y))
			}
		}
		s.s.Players.Camper.LastCheck = s.s.Frame()
	}
	for it := s.s.Players.FirstUnit(); it != nil; it = s.s.Players.NextUnit(it) {
		if it.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			continue
		}
		ud := it.UpdateDataPlayer()
		if (ud.Player.Field3680 & 1) == 0 {
			if (s.s.Players.Camper.LastCheck - ud.Field64) > s.s.Players.Camper.FadeTime {
				if ud.IsCamping != 0 {
					s.s.NetSendInterestingIDOff(it)
					ud.IsCamping = 0
				}
			} else {
				if ud.IsCamping == 0 {
					if !noxflags.HasGame(noxflags.GameModeCTF) || ud.Player.WeaponEquip&1 != 0 {
						s.s.Audio.EventObj(sound.SoundBigBell, it, 0, 0)
					}
					s.s.NetSendInterestingIDOn(it)
					ud.IsCamping = 1
				}
			}
		}
	}
}
