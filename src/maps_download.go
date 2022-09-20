package opennox

import (
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/maps"
)

var mapsend struct {
	srv *maps.Server
}

func init() {
	registerOnDataPathSet(func() {
		mapsend.srv = maps.NewServer(datapath.Maps())
		mapsend.srv.RegisterOnMux(noxServer.http.mux)
	})
}

func clientGetServerMap() string {
	if gameIsNotMultiplayer {
		return nox_xxx_mapFilenameGetSolo_4DB260()
	}
	return noxServer.nox_server_currentMapGetFilename_409B30()
}
