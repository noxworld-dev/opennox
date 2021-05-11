package main

/*
#include <stdint.h>
int nox_client_sendToServer_555010(unsigned int addr, uint16_t port, char* buf, int sz);
*/
import "C"

import (
	"bufio"
	"log"
	"net"
	"os"
	"path/filepath"
	"unsafe"

	"nox/common/fs"
)

var (
	discoverLog = log.New(os.Stderr, "[discover]: ", log.LstdFlags|log.Lmsgprefix)
)

//export nox_client_OnServerSearch
func nox_client_OnServerSearch(port C.int, cdata unsafe.Pointer, sz C.int) {
	data := asByteSlice(cdata, int(sz))
	discoverAndPingServers(int(port), data)
}

func discoverAndPingServers(cliport int, data []byte) {
	discoverLog.Println("searching for servers...")
	n := 0
	for _, ip := range discoverServers() {
		clientPingServer(ip, data, cliport)
		n++
	}
	discoverLog.Printf("found %d server(s)", n)
}

func clientPingServer(addr net.IP, data []byte, cliport int) {
	C.nox_client_sendToServer_555010(C.uint(ip2int(addr)), C.uint16_t(cliport), (*C.char)(unsafe.Pointer(&data[0])), C.int(len(data)))
}

func discoverServers() []net.IP {
	var out []net.IP
	out = append(out, reaIPsFile(filepath.Join(getDataPath(), "game_ip.txt"))...)
	return out
}

func reaIPsFile(path string) []net.IP {
	name := filepath.Base(path)
	f, err := fs.Open(path)
	if os.IsNotExist(err) {
		discoverLog.Printf("no %s file", name)
		return nil
	} else if err != nil {
		discoverLog.Printf("cannot read %s: %v", name, err)
		return nil
	}
	defer f.Close()

	var out []net.IP
	sc := bufio.NewScanner(f)
	for sc.Scan() {
		line := sc.Text()
		ip := net.ParseIP(line).To4()
		if ip == nil {
			discoverLog.Printf("cannot parse server IP in %s: %q", name, line)
			continue
		}
		discoverLog.Printf("%s: %v", name, ip)
		out = append(out, ip)
	}
	if err := sc.Err(); err != nil {
		discoverLog.Printf("error reading %s: %v", name, err)
	}
	return out
}
