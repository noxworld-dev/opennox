package nox

import (
	"fmt"
	"net"
	"net/http"

	"nox/v1/common"
	"nox/v1/common/log"
)

var (
	gameMux     = http.NewServeMux()
	gameHTTP    = &http.Server{Addr: fmt.Sprintf(":%d", common.GameHTTPPort), Handler: gameMux}
	gameHTTPLis net.Listener
	httpLog     = log.New("http")
)

func gameStartHTTP(port int) error {
	if gameHTTPLis != nil {
		return nil
	}
	gameHTTP.Addr = fmt.Sprintf(":%d", port)
	ln, err := net.Listen("tcp", gameHTTP.Addr)
	if err != nil {
		return fmt.Errorf("cannot start http server: %w", err)
	}
	gameHTTPLis = ln
	go gameHTTP.Serve(ln)
	httpLog.Println("http api server started:", gameHTTP.Addr)
	return nil
}

func gameStopHTTP() {
	if gameHTTPLis != nil {
		_ = gameHTTPLis.Close()
		gameHTTPLis = nil
		httpLog.Println("http api server stopped")
	}
}
