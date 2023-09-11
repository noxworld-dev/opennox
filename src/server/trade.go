package server

type TradeSession struct {
	Field0  uint32        // 0, 0
	Field4  uint32        // 1, 4
	Field8  *Object       // 2, 8
	Field12 *Object       // 3, 12
	Field16 uint32        // 4, 16
	Field20 *TradeItem    // 5, 20
	Field24 uint32        // 6, 24
	Field28 uint32        // 7, 28
	Field32 *TradeItem    // 8, 32
	Field36 *TradeItem    // 9, 36
	Field40 uint32        // 10, 40
	Field44 uint32        // 11, 44
	Field48 *Object       // 12, 48
	Field52 *Object       // 13, 52
	Field56 *TradeSession // 14, 56
	Field60 *TradeSession // 15, 60
}

type TradeItem struct {
	Item0   *Object    // 0, 0
	Cost4   uint32     // 1, 4
	Field8  *TradeItem // 2, 8
	Field12 *TradeItem // 3, 12
}
