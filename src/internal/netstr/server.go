package netstr

import (
	"errors"

	"github.com/noxworld-dev/opennox-lib/common"
)

type Server struct {
	*Conn
}

func (g *Streams) Listen(opt *Options) (Server, error) {
	g.reset()
	if opt == nil {
		return Server{}, errors.New("empty options")
	}
	if opt.Max > maxStructs {
		return Server{}, errors.New("max limit reached")
	}
	if opt.Port < 1024 || opt.Port > 0x10000 {
		opt.Port = common.GamePort
	}
	pc, port, err := listenOnFreePort(g.Log, opt.Port)
	if err != nil {
		return Server{}, err
	}
	opt.Port = port
	ns := g.newStream(-1, opt)
	if ns == nil {
		return Server{}, errors.New("no more slots for net structs")
	}
	ns.pc = pc
	ns.data2hdr()[0] = byte(ns.ind)
	s := Server{ns}
	g.lis = s
	return s, nil
}
