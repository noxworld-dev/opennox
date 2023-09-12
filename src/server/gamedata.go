package server

import (
	"github.com/noxworld-dev/opennox-lib/balance"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

var (
	gamedataLog = log.New("gamedata")
)

type serverBalance struct {
	file *balance.File
}

func (s *serverBalance) Free() {
	s.file = nil
}

func (s *serverBalance) Read() error {
	s.file = nil
	var err error
	s.file, err = balance.ReadBalance(datapath.Data(balance.GamedataFile))
	if err != nil {
		gamedataLog.Println("error parsing gamedata:", err)
	}
	return err
}

func (s *serverBalance) Tag() balance.Tag {
	// TODO: check if it's a valid condition
	if noxflags.HasGame(noxflags.GameModeCoop) {
		return balance.TagSolo
	}
	return balance.TagArena
}

func (s *serverBalance) Float(key string) float64 {
	tag := s.Tag()
	return s.file.FloatDef(tag, key, 0)
}

func (s *serverBalance) FloatInd(key string, i int) float64 {
	if i < 0 {
		return 0
	}
	tag := s.Tag()
	arr := s.file.Array(tag, key)
	if i >= len(arr) {
		return 0
	}
	return arr[i]
}
