//go:build server

package opennox

import (
	"image"
)

func resetRenderer(sz image.Point, _ bool) error {
	return nil
}

func copyPixBuffer() {
}

func playMovieFile(name string) {
}

func sub_43C060() bool { return true }
