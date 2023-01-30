package opennox

import "github.com/noxworld-dev/opennox/v1/legacy"

var noxCursors struct {
	Select     *legacy.ImageRef
	Grab       *legacy.ImageRef
	Pickup     *legacy.ImageRef
	Trade      *legacy.ImageRef
	Talk       *legacy.ImageRef
	Target     *legacy.ImageRef
	Identify   *legacy.ImageRef
	IdentifyNo *legacy.ImageRef
	Repair     *legacy.ImageRef
	CreateGame *legacy.ImageRef
	Busy       *legacy.ImageRef
	Buy        *legacy.ImageRef
	Sell       *legacy.ImageRef
	Use        *legacy.ImageRef
	Move       *legacy.ImageRef
	PickupFar  *legacy.ImageRef
	Caution    *legacy.ImageRef
}

func nox_xxx_cursorLoadAll_477710() {
	p := &noxCursors
	if p.Select != nil {
		return
	}
	p.Select = nox_xxx_gLoadAnim("CursorSelect")
	p.Grab = nox_xxx_gLoadAnim("CursorGrab")
	p.Pickup = nox_xxx_gLoadAnim("CursorPickup")
	p.Trade = nox_xxx_gLoadAnim("CursorTrade")
	p.Target = nox_xxx_gLoadAnim("CursorTarget")
	p.Talk = nox_xxx_gLoadAnim("CursorTalk")
	p.Identify = nox_xxx_gLoadAnim("CursorIdentify")
	p.IdentifyNo = nox_xxx_gLoadAnim("CursorIdentifyNo")
	p.Repair = nox_xxx_gLoadAnim("CursorRepair")
	p.CreateGame = nox_xxx_gLoadAnim("CursorCreateGame")
	p.Busy = nox_xxx_gLoadAnim("CursorBusy")
	p.Buy = nox_xxx_gLoadAnim("CursorBuy")
	p.Sell = nox_xxx_gLoadAnim("CursorSell")
	p.Use = nox_xxx_gLoadAnim("CursorUse")
	p.Move = nox_xxx_gLoadAnim("CursorMove")
	p.PickupFar = nox_xxx_gLoadAnim("CursorPickupFar")
	p.Caution = nox_xxx_gLoadAnim("CursorCaution")
}
