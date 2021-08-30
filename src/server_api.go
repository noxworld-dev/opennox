package main

import (
	"context"
	"encoding/json"
	"net/http"
	"sort"
	"strings"

	noxflags "nox/v1/common/flags"
)

func init() {
	gameMux.HandleFunc("/api/v0/game/info", handleServerInfo)
}

type gameInfoPlayers struct {
	Cur  int              `json:"cur"`
	Max  int              `json:"max"`
	List []gameInfoPlayer `json:"list"`
}

type gameInfoPlayer struct {
	Name  string `json:"name"`
	Class string `json:"class,omitempty"`
}

type gameInfoQuest struct {
	Stage int `json:"stage"`
}

type gameInfoResp struct {
	Name    string          `json:"name"`
	Map     string          `json:"map"`
	Mode    string          `json:"mode"`
	Vers    string          `json:"vers"`
	Players gameInfoPlayers `json:"players"`
	Quest   *gameInfoQuest  `json:"quest,omitempty"`
}

func getGameInfo(ctx context.Context) (*gameInfoResp, error) {
	ch := make(chan *gameInfoResp, 1)
	addGameTickHook(func() {
		v := &gameInfoResp{
			Name: getServerName(),
			Map:  strings.ToLower(getServerMap()),
			Vers: Version,
			Mode: noxflags.GetGame().Mode(),
		}
		if noxflags.HasGame(noxflags.GameModeQuest) {
			v.Quest = &gameInfoQuest{Stage: nox_game_getQuestStage_4E3CC0()}
		}
		v.Players.Max = getServerMaxPlayers()
		for _, p := range getPlayers() {
			v.Players.List = append(v.Players.List, gameInfoPlayer{
				Name:  p.Name(),
				Class: p.PlayerClass().String(),
			})
		}
		v.Players.Cur = len(v.Players.List)
		ch <- v
	})
	select {
	case v := <-ch:
		sort.Slice(v.Players.List, func(i, j int) bool {
			return v.Players.List[i].Name < v.Players.List[j].Name
		})
		return v, nil
	case <-ctx.Done():
		return nil, ctx.Err()
	}
}

func handleServerInfo(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	default:
		w.WriteHeader(http.StatusMethodNotAllowed)
		return
	case http.MethodGet, http.MethodHead:
	}
	resp, err := getGameInfo(r.Context())
	if err != nil {
		// TODO: set correct status code
		w.WriteHeader(http.StatusInternalServerError)
		return
	}
	w.Header().Set("Content-Type", "application/json")
	_ = json.NewEncoder(w).Encode(resp)
}
