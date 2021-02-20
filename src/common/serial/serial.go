package serial

import (
	"math/rand"
	"time"
)

// TODO: Origin/GoG integration
// TODO: read from registry on Windows

var serial = generateSerial()

const (
	size     = 22
	alphabet = "0123456789"
)

func generateSerial() string {
	var rnd = rand.New(rand.NewSource(time.Now().UnixNano()))
	out := make([]byte, size)
	for i := range out {
		out[i] = alphabet[rnd.Intn(len(alphabet))]
	}
	return string(out)
}

// Serial returns a serial number for the game.
func Serial() (string, bool) {
	return serial, len(serial) != 0
}

// SetSerial sets a serial number for the game.
func SetSerial(code string) {
	if n := len(code); n > 0 && n != size {
		panic("invalid serial!")
	}
	serial = code
}
