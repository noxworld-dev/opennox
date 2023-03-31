package server

type GlyphInitData struct {
	Spells    [5]uint32 // 0, 0
	SpellsCnt uint32    // 5, 20
	SpellArg  SpellAcceptArg
}
