package nat

import (
	"context"
	"fmt"
	"net"

	"nox/v1/common/log"
)

var Log = log.New("nat")

// Port describes a port mapping.
type Port struct {
	Proto string // tcp or udp
	Port  int    // port number
	Desc  string // description
}

func (p Port) String() string {
	return fmt.Sprintf("(%d/%s: %q)", p.Port, p.Proto, p.Desc)
}

// Map discovers NAT gateway and maps specified ports.
func Map(ctx context.Context, ports []Port) (func(), error) {
	Log.Println("preparing to map ports", ports)
	if len(ports) == 0 {
		return func() {}, nil
	}
	return mapUPNP(ctx, ports)
}

type Gateway interface {
	Priority() int
	Type() string
	Name() string
	InternalIP() net.IP
	ExternalIP() net.IP
	AddPortMapping(port uint16, proto string, desc string) error
	DeletePortMapping(port uint16, proto string) error
}
