package opennox

import (
	"image"
)

func pointUnpack(packed int32) image.Point {
	return image.Pt(int(packed>>16), int(uint16(packed))) // Or, packed & 0xffff
}

func nox_script_openSecretWall_511F50() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Enable(false)
	}
	return 0
}

func nox_script_closeWall_512040() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Enable(false)
	}
	return 0
}

func nox_script_toggleWall_512130() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Toggle()
	}
	return 0
}

func nox_script_wallBreak_512290() int {
	s := &noxServer.noxScript

	grid := pointUnpack(s.PopI32())
	wall := noxServer.getWallAtGrid(grid)
	if wall != nil {
		wall.Destroy()
	}
	return 0
}
