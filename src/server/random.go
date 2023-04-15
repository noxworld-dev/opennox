package server

import (
	"github.com/noxworld-dev/opennox-lib/platform"
	"github.com/noxworld-dev/opennox-lib/prand"
)

type serverRandom struct {
	src   platform.Platform
	Logic *prand.Rand
	Other *prand.Rand
}

func (s *serverRandom) init(src platform.Platform) {
	s.src = src
	s.Logic = prand.New(0)
	s.Other = prand.New(0)
}

func (s *serverRandom) Reset() {
	var v int64
	if s.src != nil {
		v = s.src.TimeSeed()
	} else {
		v = platform.TimeSeed()
	}
	s.Logic.Reset(int(v))
	s.Other.Reset(int(v))
}

func (s *serverRandom) RandomColor3() Color3 {
	return Color3{
		R: byte(s.Other.Int(0, 255)),
		G: byte(s.Other.Int(0, 255)),
		B: byte(s.Other.Int(0, 255)),
	}
}
