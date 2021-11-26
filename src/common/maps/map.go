package maps

import "image"

type UnknownSect struct {
	Name string
	Data []byte
}

type Info struct {
	Filename      string `json:"name"`
	Size          int    `json:"size"`
	Format        int    `json:"format,omitempty"`
	Summary       string `json:"summary,omitempty"`        // 0 [64]
	Description   string `json:"description,omitempty"`    // 64 [512]
	Version       string `json:"version,omitempty"`        // 576 [16]
	Author        string `json:"author,omitempty"`         // 592 [64]
	Email         string `json:"email,omitempty"`          // 656 [64]
	Author2       string `json:"author_2,omitempty"`       // 720 [128]
	Email2        string `json:"email_2,omitempty"`        // 848 [128]
	Field7        string `json:",omitempty"`               // 976 [256]
	Copyright     string `json:"copyright,omitempty"`      // 1232 [128]
	Date          string `json:"date_str,omitempty"`       // 1360 [32]
	Flags         uint32 `json:"flags,omitempty"`          // 1392
	MinPlayers    byte   `json:"min_players,omitempty"`    // 1396
	MaxPlayers    byte   `json:"max_players,omitempty"`    // 1397
	QuestIntro    string `json:"quest_intro,omitempty"`    // 1398
	QuestGraphics string `json:"quest_graphics,omitempty"` // 1430
}

type Map struct {
	Info

	crc      uint32
	wallOffX uint32
	wallOffY uint32
	walls    *wallMap
	floor    *floorMap

	Script     *Script
	ScriptData *ScriptData
	Unknown    []UnknownSect
}

func (m *Map) Walls() []*Wall {
	return m.walls.Walls()
}

// GridBoundingBox returns a bounding box for all walls and tiles on the map.
// Returned rectangle uses grid coordinates, not pixel coordinates.
func (m *Map) GridBoundingBox() image.Rectangle {
	var r image.Rectangle
	r.Min.X = -1
	r.Min.Y = -1
	for _, w := range m.Walls() {
		p := w.Pos
		if r.Min.X == -1 || r.Min.X > int(p.X) {
			r.Min.X = int(p.X)
		}
		if r.Min.Y == -1 || r.Min.Y > int(p.Y) {
			r.Min.Y = int(p.Y)
		}
		if r.Max.X < int(p.X) {
			r.Max.X = int(p.X)
		}
		if r.Max.Y < int(p.Y) {
			r.Max.Y = int(p.Y)
		}
	}
	// TODO: tiles
	return r
}

type gridData struct {
	prefix uint16
	var1   uint32
	var2   uint32
	var3   uint32
	var4   uint32
}

type WallPos struct {
	X, Y byte
}

type wallMap struct {
	grid gridData
	loc  map[WallPos]*Wall
	list []*Wall
}

func (wm *wallMap) Walls() []*Wall {
	if wm == nil {
		return nil
	}
	return wm.list
}

type Wall struct {
	Pos      WallPos
	Dir      byte
	Material byte
	Variant  byte
	Minimap  byte
	Modified byte
}

type Script struct {
	Data []byte
}

type ScriptData struct {
	Data []byte
}
