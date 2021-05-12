package main

/*
#include <stdint.h>
int nox_client_sendToServer_555010(unsigned int addr, uint16_t port, char* buf, int sz);
*/
import "C"

import (
	"context"
	"net"
	"unsafe"

	"nox/common/discover"
)

//export nox_client_OnServerSearch
func nox_client_OnServerSearch(port C.int, cdata unsafe.Pointer, sz C.int) {
	data := asByteSlice(cdata, int(sz))
	discoverAndPingServers(int(port), data)
}

func clientPingServer(addr net.IP, data []byte, cliport int) {
	C.nox_client_sendToServer_555010(C.uint(ip2int(addr)), C.uint16_t(cliport), (*C.char)(unsafe.Pointer(&data[0])), C.int(len(data)))
}

func discoverAndPingServers(cliport int, data []byte) {
	err := discover.EachServer(context.Background(), func(s discover.Server) error {
		clientPingServer(s.Addr, data, cliport)
		return nil
	})
	if err != nil {
		discover.Log.Println(err)
	}
}
