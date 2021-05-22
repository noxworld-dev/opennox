package nat

import (
	"context"
	"fmt"
	"io/ioutil"
	"net"
	"net/http"
	"sync"
	"time"

	"github.com/jpillora/backoff"
)

var (
	ipifyClient = http.DefaultClient
	externalIP  struct {
		sync.RWMutex
		addr net.IP
	}
	internalIPs struct {
		sync.RWMutex
		addrs []*net.IPNet
	}
)

// InternalIPs returns a list of all local IP nets this machine is connected to.
// It caches results and does lookup only once.
func InternalIPs(ctx context.Context) ([]*net.IPNet, error) {
	internalIPs.RLock()
	addrs := internalIPs.addrs
	internalIPs.RUnlock()
	if len(addrs) != 0 {
		return addrs, nil
	}
	internalIPs.Lock()
	defer internalIPs.Unlock()
	if addrs = internalIPs.addrs; len(addrs) != 0 {
		return addrs, nil
	}

	ifaces, err := net.Interfaces()
	if err != nil {
		return nil, fmt.Errorf("cannot get network interfaces: %w", err)
	}

	var out []*net.IPNet
	for _, iface := range ifaces {
		addrs, err := iface.Addrs()
		if err != nil {
			return nil, fmt.Errorf("cannot get internal addresses: %w", err)
		}
		for _, addr := range addrs {
			switch x := addr.(type) {
			case *net.IPNet:
				if !x.IP.IsLoopback() {
					Log.Printf("internal IP: %v", x)
					out = append(out, x)
				}
			}
		}
	}
	internalIPs.addrs = out
	return out, nil
}

// ExternalIP returns an IP address as observed by other online peers.
// It caches results and does lookup only once.
func ExternalIP(ctx context.Context) (net.IP, error) {
	externalIP.RLock()
	ip := externalIP.addr
	externalIP.RUnlock()
	if ip != nil {
		return ip, nil
	}
	externalIP.Lock()
	defer externalIP.Unlock()
	if ip = externalIP.addr; ip != nil {
		return ip, nil
	}

	b := &backoff.Backoff{
		Jitter: true,
	}
	req, err := http.NewRequestWithContext(ctx, "GET", "https://api.ipify.org", nil)
	if err != nil {
		return nil, fmt.Errorf("cannot get external IP: %w", err)
	}
	var resp *http.Response
	for tries := 0; tries < 3; tries++ {
		resp, err = ipifyClient.Do(req)
		if err == nil {
			break
		}
		Log.Printf("failed to get external IP: %v", err)
		select {
		case <-ctx.Done():
			return nil, ctx.Err()
		case <-time.After(b.Duration()):
		}
	}
	if err != nil {
		return nil, fmt.Errorf("cannot get external IP: %w", err)
	}
	defer resp.Body.Close()
	if resp.StatusCode != http.StatusOK {
		return nil, fmt.Errorf("cannot get external IP: %s", resp.Status)
	}
	str, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, fmt.Errorf("cannot read external IP: %w", err)
	}
	ip = net.ParseIP(string(str))
	if ip == nil {
		return nil, fmt.Errorf("cannot parse external IP: %q", str)
	}
	Log.Printf("external IP: %v", ip)
	externalIP.addr = ip
	return ip, nil
}
