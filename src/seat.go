package opennox

import (
	"image"

	"github.com/noxworld-dev/opennox-lib/client/seat"
)

var (
	noxSeat seat.Seat
)

func InitSeat(sz image.Point) error {
	s, err := newSeat(sz)
	if err != nil {
		return err
	}
	if s != nil {
		s.SetGamma(getGamma())
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

func setScreenSize(sz image.Point) {
	if noxSeat != nil {
		noxSeat.ResizeScreen(sz)
	}
}
