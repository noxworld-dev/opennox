package client

import (
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (c *Client) handleCBORXfer(ind ntype.PlayerInd, m server.NetXferExt) {
	switch m := m.(type) {
	case *server.XferObjectSetLabel:
		if dr := c.Objs.ByNetCode(uint16(m.Object)); dr != nil {
			dr.setDisplayName(m.Label, m.Color.Color())
		} else {
			Log.Printf("cannot find object %d for XferObjectSetLabel", m.Object)
		}
	}
}
