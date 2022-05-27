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
