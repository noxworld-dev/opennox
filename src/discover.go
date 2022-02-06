package nox

import (
	"context"

	"github.com/noxworld-dev/xwis"

	"nox/v1/common/discover"
)

func discoverAndPingServers(defPort int, ts uint32, data []byte) {
	ctx := context.Background()
	err := discover.EachServer(ctx, func(s discover.Server) error {
		port := s.Port
		if port <= 0 {
			port = defPort
		}
		_, err := sendToServer(s.Addr, port, data)
		return err
	})
	if err != nil {
		discover.Log.Println(err)
	}
	for _, l := range discover.XWISRooms() {
		if l.Game == nil {
			continue
		}
		g := l.Game
		level := 0
		if xwisIsQuest(l.Game) {
			level = g.FragLimit
		}
		var status byte
		switch g.Access {
		case xwis.AccessClosed:
			status |= 0x10
		case xwis.AccessPrivate:
			status |= 0x20
		}
		// TODO: more fields
		onLobbyServer(&LobbyServerInfo{
			Addr:       g.Addr,
			Port:       defPort, // TODO: this should come from the server
			Name:       g.Name,
			Map:        g.Map,
			Players:    g.Players,
			MaxPlayers: g.MaxPlayers,
			Flags:      uint16(g.Flags) | uint16(g.MapType),
			Status:     status,
			Ping:       -1, // we have no idea - it comes from a central server
			Level:      uint16(level),
		})
	}
}
