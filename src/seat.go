package nox

import (
	"nox/v1/client/seat"
	"nox/v1/common/types"
)

var (
	noxSeat seat.Seat
)

func InitSeat(sz types.Size) error {
	s, err := newSeat(sz)
	if err != nil {
		return err
	}
	noxSeat = s
	return nil
}

func FreeSeat() {
	if noxSeat != nil {
		noxSeat.Close()
		noxSeat = nil
	}
}

func setScreenSize(sz types.Size) {
	if noxSeat != nil {
		noxSeat.ResizeScreen(sz)
	}
}
