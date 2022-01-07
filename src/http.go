package nox

import (
	"fmt"
	"net"
	"net/http"

	"nox/v1/common"
	"nox/v1/common/log"
)

var (
	httpLog = log.New("http")
)

type httpService struct {
	mux *http.ServeMux
	srv *http.Server
	lis net.Listener
}

func (s *httpService) init() {
	s.mux = http.NewServeMux()
	s.srv = &http.Server{Addr: fmt.Sprintf(":%d", common.GameHTTPPort), Handler: s.mux}
}

func (s *Server) gameStartHTTP(port int) error {
	if s.http.lis != nil {
		return nil
	}
	addr := fmt.Sprintf(":%d", port)
	s.http.srv.Addr = addr
	ln, err := net.Listen("tcp", addr)
	if err != nil {
		return fmt.Errorf("cannot start http server: %w", err)
	}
	s.http.lis = ln
	go s.http.srv.Serve(ln)
	httpLog.Println("http api server started:", addr)
	return nil
}

func (s *Server) gameStopHTTP() {
	if s.http.lis != nil {
		_ = s.http.lis.Close()
		s.http.lis = nil
		httpLog.Println("http api server stopped")
	}
}
