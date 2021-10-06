package main

import (
	"context"

	octl "github.com/szhublox/opennoxcontrol"
)

func init() {
	var opts octl.Options
	configBoolPtr("server.control.allow_cmds", "NOX_SERVER_HTTP_ALLOWS_CMDS", false, &opts.AllowCommands)
	configBoolPtr("server.control.allow_map_change", "NOX_SERVER_HTTP_ALLOWS_MAP_CHANGE", false, &opts.AllowMapChange)
	registerOnConfigRead(func() {
		game := &gameControlHTTP{
			// enforce these flags from our side as well
			allowCmds:      opts.AllowCommands,
			allowMapChange: opts.AllowMapChange,
		}
		srv := octl.NewControlPanel(game, &opts)
		gameMux.Handle("/", srv)
	})
}

type gameControlHTTP struct {
	allowCmds      bool
	allowMapChange bool
}

func (g *gameControlHTTP) GameInfo() (octl.Info, error) {
	resp, err := getGameInfo(context.Background())
	if err != nil {
		return octl.Info{}, err
	}
	var list []octl.Player
	for _, p := range resp.Players.List {
		list = append(list, octl.Player{
			Name: p.Name, Class: p.Class,
		})
	}
	return octl.Info{
		Name: resp.Name,
		Map:  resp.Map,
		Mode: resp.Mode,
		Vers: resp.Vers,
		PlayerInfo: octl.PlayerInfo{
			Cur:  resp.Players.Cur,
			Max:  resp.Players.Max,
			List: list,
		},
	}, nil
}

func (g *gameControlHTTP) ListMaps() ([]octl.Map, error) {
	list, err := scanMaps()
	var out []octl.Map
	for _, l := range list {
		out = append(out, octl.Map{
			Name:       l.Filename,
			Summary:    l.Summary,
			Flags:      int(l.Flags),
			MinPlayers: int(l.MinPlayers),
			MaxPlayers: int(l.MaxPlayers),
		})
	}
	return out, err
}

func (g *gameControlHTTP) ChangeMap(name string) error {
	if g.allowMapChange {
		queueServerMapLoad(name)
	}
	return nil
}

func (g *gameControlHTTP) Command(cmd string) error {
	if g.allowCmds {
		queueServerCmd(cmd)
	}
	return nil
}
