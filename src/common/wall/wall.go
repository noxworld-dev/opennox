package wall

import "nox/v1/common/types"

const GridStep = 23

func PosToGrid(pos types.Pointf) types.Point {
	return types.Point{
		X: int(pos.X / GridStep),
		Y: int(pos.Y / GridStep),
	}
}

func GridToPos(pos types.Point) types.Pointf {
	return types.Pointf{
		X: float32(pos.X) * GridStep,
		Y: float32(pos.Y) * GridStep,
	}
}
