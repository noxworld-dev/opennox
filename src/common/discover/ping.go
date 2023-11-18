package discover

import (
	"context"
	"encoding/binary"
	"math/rand"
	"net"
	"net/netip"
	"strings"
	"sync"
	"time"

	"github.com/noxworld-dev/lobby"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

const (
	pingTimeout = 600 * time.Millisecond
)

// PingAll pings all servers in a list and merges the results back to the slice.
func PingAll(ctx context.Context, pc *net.UDPConn, arr []Server) error {
	if _, ok := ctx.Deadline(); !ok {
		var cancel func()
		ctx, cancel = context.WithTimeout(ctx, pingTimeout)
		defer cancel()
	}
	p := NewPinger(pc)
	defer p.Close()

	var (
		last      error
		remaining int
	)
	out := make(chan *lobby.Game, len(arr))
	byKey := make(map[serverKey]*Server, len(arr))
	start := time.Now()
	for i := range arr {
		s := &arr[i]
		byKey[s.key()] = s
		if err := p.SendPing(out, netip.AddrPortFrom(s.IP, uint16(s.Port))); err != nil {
			Log.Printf("ping: cannot ping server %s:%d: %v", s.IP, s.Port, err)
			last = err
		} else {
			remaining++
		}
	}
loop:
	for remaining > 0 {
		select {
		case <-ctx.Done():
			Log.Printf("ping timeout for %d/%d servers", remaining, len(arr))
			break loop
		case g := <-out:
			remaining--
			if s := byKey[serverKey{Addr: g.Address, Port: g.Port}]; s != nil {
				s.Ping = time.Since(start)
				s.Game = mergeInfo(s.Game, g)
				s.NoPing = true
			} else {
				Log.Printf("ping: cannot find server: %s:%d", g.Address, g.Port)
			}
		}
	}
	return last
}

// NewPinger creates a pinger for game servers with an existing net.PacketConn.
func NewPinger(pc net.PacketConn) *Pinger {
	p := &Pinger{
		pc:      pc,
		stop:    make(chan struct{}),
		done:    make(chan struct{}),
		rnd:     rand.New(rand.NewSource(time.Now().UnixNano())),
		byToken: make(map[uint32]chan<- *lobby.Game),
	}
	go p.read()
	return p
}

type Pinger struct {
	pc   net.PacketConn
	stop chan struct{}
	done chan struct{}

	mu      sync.Mutex
	err     error
	rnd     *rand.Rand
	byToken map[uint32]chan<- *lobby.Game
}

func (p *Pinger) Close() error {
	if p.stop == nil {
		return nil
	}
	close(p.stop)
	p.pc.SetReadDeadline(time.Now())
	<-p.done
	p.pc.SetReadDeadline(time.Time{})
	p.stop = nil
	return nil
}

func (p *Pinger) read() {
	defer close(p.done)
	buf := make([]byte, 256)
	for {
		buf = buf[:cap(buf)]
		n, addr, err := p.pc.ReadFrom(buf)
		if err != nil {
			select {
			case <-p.stop:
				return
			default:
			}
			p.mu.Lock()
			p.err = err
			p.mu.Unlock()
			return
		}
		buf = buf[:n]
		m := decodeGameInfo(buf)
		if m == nil {
			continue
		}
		p.mu.Lock()
		ch := p.byToken[m.Token]
		if ch != nil {
			delete(p.byToken, m.Token)
		}
		p.mu.Unlock()
		if ch == nil {
			continue
		}
		g := convGameInfo(getAddr(addr), m, buf)
		if g == nil {
			continue
		}
		select {
		case <-p.stop:
			return
		case ch <- g:
		}
	}
}

func (p *Pinger) SendPing(out chan<- *lobby.Game, addr netip.AddrPort) error {
	Log.Printf("pinging %s", addr)
	p.mu.Lock()
	if err := p.err; err != nil {
		p.mu.Unlock()
		return err
	}
	token := p.rnd.Uint32()
	p.byToken[token] = out
	p.mu.Unlock()
	data := encodeGameDiscovery(token)
	_, err := p.pc.WriteTo(data, net.UDPAddrFromAddrPort(addr))
	return err
}

func (p *Pinger) Ping(ctx context.Context, addr netip.AddrPort) (*lobby.Game, error) {
	out := make(chan *lobby.Game, 1)
	err := p.SendPing(out, addr)
	if err != nil {
		return nil, err
	}
	select {
	case <-ctx.Done():
		return nil, ctx.Err()
	case g := <-out:
		return g, nil
	}
}

func encodeGameDiscovery(token uint32) []byte {
	data := make([]byte, 2, 12)
	data[0] = 0
	data[1] = 0
	data, err := noxnet.AppendPacket(data, &noxnet.MsgDiscover{
		Token: token,
		// TODO: set the rest of the fields?
	})
	if err != nil {
		panic(err)
	}
	return data
}

func getAddr(addr net.Addr) netip.AddrPort {
	switch a := addr.(type) {
	case nil:
	case interface{ AddrPort() netip.AddrPort }:
		return a.AddrPort()
	case *net.TCPAddr:
		return a.AddrPort()
	case *net.UDPAddr:
		return a.AddrPort()
	default:
		Log.Printf("unsupported address type: %T", a)
	}
	return netip.AddrPort{}
}

func decodeGameInfo(buf []byte) *noxnet.MsgServerInfo {
	if len(buf) < 2 {
		return nil
	}
	buf = buf[2:] // skip header
	var p noxnet.MsgServerInfo
	_, err := noxnet.DecodePacket(buf, &p)
	if err != nil {
		return nil
	}
	return &p
}

func convGameInfo(addr netip.AddrPort, m *noxnet.MsgServerInfo, buf []byte) *lobby.Game {
	name := m.ServerName
	mname := m.MapName
	status := buf[20] | buf[21]
	access := lobby.AccessOpen
	if status&0x10 != 0 {
		access = lobby.AccessClosed
	} else if status&0x20 != 0 {
		access = lobby.AccessPassword
	}
	flags := noxflags.GameFlag(m.Flags)
	var q *lobby.QuestInfo
	if flags.Has(noxflags.GameModeQuest) {
		q = &lobby.QuestInfo{Stage: int(binary.LittleEndian.Uint16(buf[68:]))}
	}
	// TODO: more fields
	return &lobby.Game{
		Name:    name,
		Address: addr.Addr().String(),
		Port:    int(addr.Port()),
		Map:     strings.ToLower(mname),
		Mode:    gameFlagsToMode(flags),
		Access:  access,
		Vers:    "", // TODO: is there a version code in the response?
		Res:     lobby.Resolution{},
		Players: lobby.PlayersInfo{
			Cur: int(buf[3]),
			Max: int(buf[4]),
		},
		Quest: q,
	}
}
