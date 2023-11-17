package server

import (
	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func (s *Server) Sub_532EC0(who *Object, mat uint16) {
	switch mat {
	case 0x8:
		s.Audio.EventObj(sound.SoundHitWoodBreakable, who, 0, 0)
	case 0x10:
		s.Audio.EventObj(sound.SoundHitMetalBreakable, who, 0, 0)
	case 0x20:
		s.Audio.EventObj(sound.SoundHitStoneBreakable, who, 0, 0)
	case 0x40:
		s.Audio.EventObj(sound.SoundHitEarthBreakable, who, 0, 0)
	case 0x400:
		s.Audio.EventObj(sound.SoundHitEarthBreakable, who, 0, 0)
	case 0x1000:
		s.Audio.EventObj(sound.SoundHitMagicBreakable, who, 0, 0)
	}
}
func (s *Server) Sub_533010(mat uint16, who *Object) int {
	if who != nil {
		s.Sub_532EC0(who, mat)
	}
	return 1
}
func (s *Server) Sub_532930(obj *Object, a2 uint16, a3 uint16) {
	if int32(a2) <= 32 {
		if int32(a2) == 32 {
			if int32(a3) > 16 {
				if int32(a3) == 32 {
					s.Audio.EventObj(848, obj, 0, 0)
				} else if int32(a3) == 0x2000 {
					s.Audio.EventObj(868, obj, 0, 0)
				}
			} else if int32(a3) == 16 {
				s.Audio.EventObj(858, obj, 0, 0)
			} else {
				switch a3 {
				case 1, 2, 4:
					s.Audio.EventObj(863, obj, 0, 0)
				case 8:
					s.Audio.EventObj(853, obj, 0, 0)
				default:
					return
				}
			}
		} else {
			switch a2 {
			case 1, 2, 4:
				if int32(a3) > 16 {
					if int32(a3) == 32 {
						s.Audio.EventObj(852, obj, 0, 0)
					} else if int32(a3) == 0x2000 {
						s.Audio.EventObj(872, obj, 0, 0)
					}
				} else if int32(a3) == 16 {
					s.Audio.EventObj(862, obj, 0, 0)
				} else {
					switch a3 {
					case 1, 2, 4:
						s.Audio.EventObj(867, obj, 0, 0)
					case 8:
						s.Audio.EventObj(857, obj, 0, 0)
					default:
						return
					}
				}
			case 8:
				if int32(a3) > 16 {
					if int32(a3) == 32 {
						s.Audio.EventObj(850, obj, 0, 0)
					} else if int32(a3) == 0x2000 {
						s.Audio.EventObj(870, obj, 0, 0)
					}
				} else if int32(a3) == 16 {
					s.Audio.EventObj(860, obj, 0, 0)
				} else {
					switch a3 {
					case 1, 2, 4:
						s.Audio.EventObj(865, obj, 0, 0)
					case 8:
						s.Audio.EventObj(855, obj, 0, 0)
					default:
						return
					}
				}
			case 0x10:
				if int32(a3) > 16 {
					if int32(a3) == 32 {
						s.Audio.EventObj(851, obj, 0, 0)
					} else if int32(a3) == 0x2000 {
						s.Audio.EventObj(871, obj, 0, 0)
					}
				} else if int32(a3) == 16 {
					s.Audio.EventObj(861, obj, 0, 0)
				} else {
					switch a3 {
					case 1, 2, 4:
						s.Audio.EventObj(866, obj, 0, 0)
					case 8:
						s.Audio.EventObj(856, obj, 0, 0)
					default:
						return
					}
				}
			default:
				return
			}
		}
		return
	}
	if int32(a2) != 64 && int32(a2) != 1024 {
		if int32(a2) != 0x2000 {
			return
		}
		if int32(a3) > 16 {
			if int32(a3) == 32 {
				s.Audio.EventObj(868, obj, 0, 0)
				return
			}
			if int32(a3) != 0x2000 {
				return
			}
		} else if int32(a3) != 16 {
			switch a3 {
			case 1, 2, 4:
				s.Audio.EventObj(872, obj, 0, 0)
			case 8:
				s.Audio.EventObj(870, obj, 0, 0)
			default:
				return
			}
			return
		}
		s.Audio.EventObj(871, obj, 0, 0)
		return
	}
	if int32(a3) > 16 {
		if int32(a3) == 32 {
			s.Audio.EventObj(849, obj, 0, 0)
		} else if int32(a3) == 0x2000 {
			s.Audio.EventObj(869, obj, 0, 0)
		}
	} else if int32(a3) == 16 {
		s.Audio.EventObj(859, obj, 0, 0)
	} else {
		switch a3 {
		case 1, 2, 4:
			s.Audio.EventObj(864, obj, 0, 0)
		case 8:
			s.Audio.EventObj(854, obj, 0, 0)
		default:
			return
		}
	}
}
func (s *Server) Sub_532FE0(mat uint16, who *Object) int {
	if who != nil {
		s.Sub_532930(who, mat, who.Material)
	}
	return 1
}

func Nox_xxx_soundDefaultDamageSound_532E20(obj1 *Object, obj2 *Object) int {
	if obj1 != nil && obj1.Class().HasAny(object.ClassWeapon|object.ClassWand) && obj1.InvHolder != nil {
		return 1
	}
	s := obj1.Server()
	if !(obj2 != nil && obj2.Material != 0x4000 && sub_532F70(int32(obj1.Field131)) != 0) {
		return 1
	}
	hp := obj1.HealthData
	if hp != nil && hp.Max != 0 && sub_532FB0(obj1.Material) != 0 {
		s.Sub_532EC0(obj1, obj1.Material)
		return 1
	}
	s.Sub_532930(obj1, obj1.Material, obj2.Material)
	return 1
}

func sub_532F70(v int32) int32 {
	switch v {
	case 0, 2, 3, 10, 11:
		return 1
	default:
		return 0
	}
}

func sub_532FB0(v uint16) int32 {
	switch v {
	case 8, 32, 64:
		return 1
	default:
		return 0
	}
}
