package main

/*
#include <stdint.h>
*/
import "C"

import (
	"context"
	"encoding/binary"
	"unsafe"

	"nox/v1/common/discover"
)

//export nox_client_OnServerSearch
func nox_client_OnServerSearch(port C.int, cdata unsafe.Pointer, sz C.int) {
	data := asByteSlice(cdata, int(sz))
	discoverAndPingServers(int(port), data)
}

func onLobbyServer(addr string, port int, name string, packet []byte) bool {
	discover.Log.Printf("server response: %s:%d, %q", addr, port, name)
	if guiOnLobbyServer == nil {
		return false
	}
	return guiOnLobbyServer(addr, uint16(port), name, packet) != 0
}

func discoverAndPingServers(port int, data []byte) {
	ctx := context.Background()
	err := discover.EachServer(ctx, func(s discover.Server) error {
		_, err := sendToServer(s.Addr, port, data)
		return err
	})
	if err != nil {
		discover.Log.Println(err)
	}
	ts := binary.LittleEndian.Uint32(data[8:])
	for _, l := range discover.XWISRooms() {
		if l.Game == nil {
			continue
		}
		g := l.Game

		// TODO: more fields
		rec := make([]byte, 86)
		rec[3] = byte(g.Players)
		rec[4] = byte(g.MaxPlayers)
		copy(rec[10:], g.Map)
		binary.LittleEndian.PutUint16(rec[28:], uint16(g.Flags)|uint16(g.MapType))
		binary.LittleEndian.PutUint32(rec[44:], ts)
		onLobbyServer(g.Addr, port, g.Name, rec)
	}
}
