package nat

import (
	"context"
	"encoding/xml"
	"errors"
	"fmt"
	"net"
	"net/url"
	"sort"
	"strings"
	"sync"
	"time"

	"github.com/huin/goupnp/dcps/internetgateway2"
	"github.com/huin/goupnp/soap"
	"golang.org/x/sync/errgroup"

	"nox/v1/common/log"
)

var LogUPNP = log.New("nat-upnp")

type upnpClient interface {
	GetExternalIPAddress() (string, error)
	AddPortMapping(extHost string, extPort uint16, proto string, intPort uint16, intHost string, enabled bool, desc string, dur uint32) error
	DeletePortMapping(extHost string, extPort uint16, proto string) error
}

type upnpType int

func (t upnpType) Clients(ctx context.Context) ([]upnpClientT, error) {
	switch t {
	case upnpIG2IP1:
		return upnpIP1Clients(ctx)
	case upnpIG2IP2:
		return upnpIP2Clients(ctx)
	case upnpIG2PPP1:
		return upnpPPP1Clients(ctx)
	default:
		panic(t)
	}
}

func (t upnpType) String() string {
	switch t {
	case upnpIG2IP1:
		return "IG2-IP1"
	case upnpIG2IP2:
		return "IG2-IP2"
	case upnpIG2PPP1:
		return "IG2-PPP1"
	default:
		return fmt.Sprintf("upnpType(%d)", int(t))
	}
}

const ( // order matters, it determines priority
	upnpIG2IP2  = upnpType(1)
	upnpIG2IP1  = upnpType(2)
	upnpIG2PPP1 = upnpType(3)
)

type upnpClientT struct {
	upnpClient
	loc *url.URL
}

type upnpDevice struct {
	cli   upnpClientT
	typ   upnpType
	ip    net.IP // our IP in the device subnet
	intIP net.IP // internal IP of the device
	extIP net.IP // external IP of the device
}

func (d *upnpDevice) Priority() int {
	return int(d.typ)
}

func (d *upnpDevice) Type() string {
	return d.typ.String()
}

func (d *upnpDevice) Name() string {
	return fmt.Sprintf("%s (%s -> %s)", d.typ, d.intIP, d.extIP)
}

func (d *upnpDevice) InternalIP() net.IP {
	return d.intIP
}

func (d *upnpDevice) ExternalIP() net.IP {
	return d.extIP
}

func upnpErrorCode(err error) (string, bool) {
	e := new(soap.SOAPFaultError)
	if !errors.As(err, &e) {
		return "", false
	}
	if e.FaultString != "UPnPError" || len(e.Detail.Raw) == 0 {
		return "", false
	}
	var d struct {
		Code string `xml:"errorCode"`
		Desc string `xml:"errorDescription"`
	}
	if err := xml.Unmarshal(e.Detail.Raw, &d); err != nil {
		return "", false
	}
	return d.Desc, d.Desc != ""
}

func (d *upnpDevice) AddPortMapping(port uint16, proto string, desc string) error {
	var dur = 3 * time.Hour
	proto = strings.ToUpper(proto)
	extIP := d.extIP.String()
	intIP := d.ip.String()
	for {
		LogUPNP.Printf("map: %s:%d/%s -> %s:%d (%v)", intIP, port, proto, extIP, port, dur)
		err := d.cli.AddPortMapping("", port, proto, port, intIP, true, desc, uint32(dur/time.Second))
		if err == nil {
			LogUPNP.Printf("mapped %s:%d/%s", intIP, port, proto)
			return nil
		}
		code, ok := upnpErrorCode(err)
		if !ok || code == "" {
			LogUPNP.Println("map failed:", err)
			return err
		}
		LogUPNP.Println("map failed with code:", code)
		switch code {
		default:
			return err
		case "OnlyPermanentLeasesSupported":
			dur = 0 // make permanent
			LogUPNP.Println("retrying with permanent lease")
		}
		continue
	}
}

func (d *upnpDevice) DeletePortMapping(port uint16, proto string) error {
	proto = strings.ToUpper(proto)
	return d.cli.DeletePortMapping("", port, proto)
}

func upnpIP1Clients(ctx context.Context) ([]upnpClientT, error) {
	arr, _, err := internetgateway2.NewWANIPConnection1Clients()
	var out []upnpClientT
	for _, g := range arr {
		out = append(out, upnpClientT{upnpClient: g, loc: g.Location})
	}
	return out, err
}

func upnpIP2Clients(ctx context.Context) ([]upnpClientT, error) {
	arr, _, err := internetgateway2.NewWANIPConnection2Clients()
	var out []upnpClientT
	for _, g := range arr {
		out = append(out, upnpClientT{upnpClient: g, loc: g.Location})
	}
	return out, err
}

func upnpPPP1Clients(ctx context.Context) ([]upnpClientT, error) {
	arr, _, err := internetgateway2.NewWANPPPConnection1Clients()
	var out []upnpClientT
	for _, g := range arr {
		out = append(out, upnpClientT{upnpClient: g, loc: g.Location})
	}
	return out, err
}

func mapUPNP(ctx context.Context, ports []Port) (func(), error) {
	tasks, _ := errgroup.WithContext(ctx)
	Log.Println("discovering UPnP gateways...")

	// start those first, so the result can be cached before discovery completes
	tasks.Go(func() error {
		_, err := InternalIPs(ctx)
		return err
	})
	tasks.Go(func() error {
		_, err := ExternalIP(ctx)
		return err
	})
	var (
		gmu      sync.Mutex
		gateways []Gateway
	)

	// Discovery will start as soon as addDiscovery is called and will run in parallel.
	// We check for a few things here: first, we need to locate the device (obviously),
	// then check if it reports exactly the same IP as observed by online peers,
	// and finally check if we have a local interface in the same subnet.
	addDiscovery := func(typ upnpType) {
		tasks.Go(func() error {
			arr, err := typ.Clients(ctx)
			if err != nil {
				LogUPNP.Printf("%s: %v", typ, err)
			} else if len(arr) != 0 {
				LogUPNP.Printf("%s: %d device(s)", typ, len(arr))
				inetIP, err := ExternalIP(ctx)
				if err != nil {
					return err
				}
				nets, err := InternalIPs(ctx)
				if err != nil {
					return err
				}
				for _, c := range arr {
					intIP := net.ParseIP(c.loc.Hostname())
					if intIP == nil {
						LogUPNP.Printf("%s: skipping device (%s): cannot parse internal IP", typ, c.loc.Host)
						continue
					}
					addr, err := c.GetExternalIPAddress()
					if err != nil {
						LogUPNP.Printf("%s: skipping device (%s): cannot get external address: %v", typ, intIP, err)
						continue
					}
					extIP := net.ParseIP(addr)
					if extIP == nil {
						LogUPNP.Printf("%s: skipping device (%s -> %s): cannot parse IP", typ, intIP, addr)
						continue
					}
					if !inetIP.Equal(extIP) {
						LogUPNP.Printf("%s: skipping device (%s -> %s): doesn't offer our external IP", typ, intIP, extIP)
						continue
					}
					var ip net.IP
					for _, n := range nets {
						if n.Contains(intIP) {
							ip = n.IP
							break
						}
					}
					if ip == nil {
						LogUPNP.Printf("%s: skipping device (%s -> %s): cannot find relevant local interface", typ, intIP, addr)
						continue
					}

					gmu.Lock()
					gateways = append(gateways, &upnpDevice{
						typ: typ, cli: c,
						ip: ip, extIP: extIP, intIP: intIP,
					})
					gmu.Unlock()
				}
			}
			return err
		})
	}

	// run the actual discovery
	addDiscovery(upnpIG2IP2)
	addDiscovery(upnpIG2IP1)
	addDiscovery(upnpIG2PPP1)

	if err := tasks.Wait(); err != nil {
		Log.Println("cannot discover gateways:", err)
		return nil, err
	}
	if len(gateways) == 0 {
		Log.Println("no NAT gateways detected")
		return func() {}, nil
	}
	sort.Slice(gateways, func(i, j int) bool {
		return gateways[i].Priority() < gateways[j].Priority()
	})

	type mapping struct {
		g Gateway
		p Port
	}
	var mapped []mapping
	stop := func() {
		for _, m := range mapped {
			_ = m.g.DeletePortMapping(uint16(m.p.Port), m.p.Proto)
		}
		mapped = nil
	}

	var last error
gwloop:
	for _, g := range gateways {
		Log.Println("trying to map via", g.Name())
		for _, p := range ports {
			Log.Printf("mapping %d/%s -> %s:%d", p.Port, p.Proto, g.ExternalIP(), p.Port)
			err := g.AddPortMapping(uint16(p.Port), p.Proto, p.Desc)
			if err != nil {
				Log.Printf("mapping %d/%s failed: %v", p.Port, p.Proto, err)
				stop()
				last = err
				continue gwloop
			}
			mapped = append(mapped, mapping{g: g, p: p})
		}
	}
	if len(mapped) != len(ports) {
		Log.Println("port mapping failed")
		stop()
		return nil, last
	}
	Log.Println("port mapping successful")
	return stop, nil
}
