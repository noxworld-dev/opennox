package nox

import (
	"context"

	"nox/v1/common/discover"
)

func discoverAndPingServers(port int, ts uint32, data []byte) {
	ctx := context.Background()
	err := discover.EachServer(ctx, func(s discover.Server) error {
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
		// TODO: more fields
		onLobbyServer(&LobbyServerInfo{
			Addr:       g.Addr,
			Port:       port, // TODO: this should come from the server
			Name:       g.Name,
			Map:        g.Map,
			Players:    g.Players,
			MaxPlayers: g.MaxPlayers,
			Flags:      uint16(g.Flags) | uint16(g.MapType),
			Ping:       -1, // we have no idea - it comes from a central server
			Level:      uint16(level),
		})
	}
}
