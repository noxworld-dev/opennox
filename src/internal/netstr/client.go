package netstr

import (
	"encoding"
	"errors"
	"fmt"
	"net"
	"net/netip"
	"time"
)

type Client struct {
	*Conn
}

func (g *Streams) NewClient(narg *Options) (*Client, error) {
	g.reset()
	if narg == nil {
		return nil, NewConnectErr(-2, errors.New("empty options"))
	}
	ns := g.newStream(0, narg)
	if ns == nil {
		return nil, NewConnectErr(-8, errors.New("no more slots for net structs"))
	}
	return &Client{ns}, nil
}

func (ns *Client) Dial(host string, port int, cport int, opts encoding.BinaryMarshaler) error {
	if ns.g.Debug {
		ns.g.Log.Println("NET_CONNECT", host, port)
	}
	if ns == nil {
		return NewConnectErr(-3, errors.New("no net struct"))
	}
	if len(host) == 0 {
		return NewConnectErr(-4, errors.New("empty hostname"))
	}
	if port < 1024 || port > 0x10000 {
		return NewConnectErr(-15, errors.New("invalid port"))
	}
	var ip netip.Addr
	if host[0] < '0' || host[0] > '9' {
		list, err := net.LookupIP(host)
		if err != nil || len(list) == 0 {
			Log.Printf("error: cannot find ip for a host %q: %v", host, err)

			return NewConnectErr(-4, err)
		}
		ip, _ = netip.AddrFromSlice(list[0].To4())
	} else {
		var err error
		ip, err = netip.ParseAddr(host)
		if err != nil {
			Log.Printf("error: cannot parse host %q: %v", host, err)
			return NewConnectErr(-4, err)
		}
	}
	addr := netip.AddrPortFrom(ip, uint16(port))
	ns.setAddr(addr)

	for {
		sock, err := listen(ns.g.Log, netip.AddrPortFrom(netip.IPv4Unspecified(), uint16(cport)))
		if err == nil {
			ns.pc = sock
			break
		} else if !ErrIsInUse(err) {
			return NewConnectErr(-1, err)
		}
		cport++
	}
	ns.g.Responded = false
	var v12 [1]byte // TODO: sending zero, is that correct? if so, set explicitly here
	seq, err := ns.SendReliable(v12[:])
	if err != nil {
		return fmt.Errorf("cannot send data: %w", err)
	}

	retries, counter := 60, 0
	for {
		//counter = 0 // TODO: is this correct?
		counter++
		if counter > 20*retries {
			return NewConnectErr(-23, errors.New("timeout"))
		}
		ns.recvLoop(RecvCanRead | RecvNoHooks | RecvJustOne)
		ns.g.MaybeSendReliable()
		if int(ns.seqRecv) >= seq {
			break
		}
		ns.g.Sleep(30 * time.Millisecond)
	}

	if ns.g.Responded && ns.handle().Valid() {
		data, err := opts.MarshalBinary()
		if err != nil {
			return err
		}
		buf := make([]byte, 3+len(data))
		buf[0] = byte(code31) // TODO: it isn't a code, it an ID?
		buf[1] = ns.data2hdr()[1]
		buf[2] = byte(code32)
		if len(data) > 0 {
			copy(buf[3:], data)
		}
		_, _ = ns.SendReliable(buf)
	}

	if !ns.handle().Valid() {
		return NewConnectErr(-1, errors.New("invalid net struct id"))
	}
	return nil
}

func (ns *Client) DialWait(timeout time.Duration, send func(), check func() bool) error {
	deadline := ns.g.Now() + timeout
	if ns.g.Debug {
		ns.g.Log.Println("CONNECT_WAIT_LOOP_START", deadline)
	}
	for {
		now := ns.g.Now()
		if timeout >= 0 && now >= deadline {
			return NewConnectErr(-19, errors.New("timeout 2"))
		}
		ns.recvLoop(RecvCanRead)
		send()
		ns.g.MaybeSendReliable()
		if check() {
			break
		}
		ns.g.Sleep(5 * time.Millisecond)
	}
	return nil
}

func (ns *Client) WaitServerResponse(seq int, try int, flags RecvFlags) int {
	if ns == nil {
		return -3
	}
	if ns.g.Debug {
		ns.g.Log.Printf("nox_xxx_cliWaitServerResponse_5525B0: %d, %d, %d\n", seq, try, flags)
	}

	if int(ns.seqRecv) >= seq {
		return 0
	}
	for i := 0; i <= 20*try; i++ {
		ns.g.Sleep(50 * time.Millisecond)
		ns.recvLoop(flags | RecvCanRead)
		ns.g.MaybeSendReliable()
		if int(ns.seqRecv) >= seq {
			return 0
		}
		// FIXME(awesie)
		return 0
	}
	return -23
}
