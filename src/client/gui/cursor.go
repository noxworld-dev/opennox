package gui

type Cursor int

const (
	CursorSelect       = Cursor(0)
	CursorGrab         = Cursor(1)
	CursorPickup       = Cursor(2)
	CursorShop         = Cursor(3)
	CursorTalk         = Cursor(4)
	CursorTarget       = Cursor(5)
	CursorIdentify     = Cursor(6)
	CursorCantIdentify = Cursor(7)
	CursorRepair       = Cursor(8)
	CursorCreateGame   = Cursor(9)
	CursorBusy         = Cursor(10)
	CursorBuy          = Cursor(11)
	CursorSell         = Cursor(12)
	CursorUse          = Cursor(13)
	CursorMoveArrow    = Cursor(14)
	CursorPickupFar    = Cursor(15)
	CursorCaution      = Cursor(16)
	Cursor17           = Cursor(17)
)
