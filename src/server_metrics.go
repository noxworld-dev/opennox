package opennox

import (
	"strconv"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promauto"
)

var (
	cntMainloop = promauto.NewCounter(prometheus.CounterOpts{
		Name: "nox_mainloop",
		Help: "Mainloop iteration",
	})
	cntPlatformTick = promauto.NewGauge(prometheus.GaugeOpts{
		Name: "nox_platform_tick",
		Help: "Current platform tick",
	})
	cntGameTick = promauto.NewGauge(prometheus.GaugeOpts{
		Name: "nox_game_tick",
		Help: "Current game tick",
	})
	cntGameMap = promauto.NewCounterVec(prometheus.CounterOpts{
		Name: "nox_map_played",
		Help: "The number of times a specific map was played",
	}, []string{"map"})
	cntPlayers = promauto.NewGauge(prometheus.GaugeOpts{
		Name: "nox_players_online",
		Help: "The number of online players",
	})
	cntPlayerHealth = promauto.NewGaugeVec(prometheus.GaugeOpts{
		Name: "nox_player_health",
		Help: "Current health of the player",
	}, []string{"ind", "name"})
	cntPlayerMana = promauto.NewGaugeVec(prometheus.GaugeOpts{
		Name: "nox_player_mana",
		Help: "Current mana of the player",
	}, []string{"ind", "name"})
)

func (s *Server) initMetrics() {
	var ticks uint64
	s.addGameTickHook(func() {
		cntPlatformTick.Set(float64(platformTicks()))
		cntGameTick.Set(float64(noxServer.Frame()))
		if ticks%uint64(gameFPS()/2) == 0 {
			s.updateMetrics()
		}
		ticks++
	})
}

func (s *Server) updateMetrics() {
	cntPlayers.Set(float64(s.cntPlayers()))
	for _, p := range s.getPlayers() {
		u := p.UnitC()
		if u == nil {
			continue
		}
		labels := []string{strconv.Itoa(p.Index()), p.Name()}
		hp, _ := u.Health()
		mp, _ := u.Mana()
		cntPlayerHealth.WithLabelValues(labels...).Set(float64(hp))
		cntPlayerMana.WithLabelValues(labels...).Set(float64(mp))
	}
}
