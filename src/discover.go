package main

/*
#include <stdint.h>
*/
import "C"

import (
	"context"
	"unsafe"

	"nox/common/discover"
)

//export nox_client_OnServerSearch
func nox_client_OnServerSearch(port C.int, cdata unsafe.Pointer, sz C.int) {
	data := asByteSlice(cdata, int(sz))
	discoverAndPingServers(int(port), data)
}

func discoverAndPingServers(port int, data []byte) {
	err := discover.EachServer(context.Background(), func(s discover.Server) error {
		_, err := sendToServer(s.Addr, port, data)
		return err
	})
	if err != nil {
		discover.Log.Println(err)
	}
}
