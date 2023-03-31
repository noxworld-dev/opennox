package server

import "github.com/noxworld-dev/opennox-lib/types"

type GlyphInitData struct {
	Spells    [5]uint32    // 0, 0
	SpellsCnt uint32       // 5, 20
	Field24   uint32       // 6, 24
	Targ      types.Pointf // 7, 28
}
