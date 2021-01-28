package platform

import (
	"math/rand"
	"time"
)

// New returns a platform based on the real hardware.
func New() Platform {
	p := &hardware{
		start: time.Now(),
	}
	p.RandSeedTime()
	return p
}

type hardware struct {
	start time.Time
	rand  *rand.Rand
}

func (p *hardware) Ticks() time.Duration {
	return time.Since(p.start)
}

func (*hardware) Sleep(dt time.Duration) {
	time.Sleep(dt)
}

func (*hardware) TimeSeed() int64 {
	return time.Now().UnixNano()
}

func (p *hardware) RandInt() int {
	return p.rand.Int()
}

func (p *hardware) RandSeed(seed int64) {
	p.rand = rand.New(rand.NewSource(seed))
}

func (p *hardware) RandSeedTime() {
	p.RandSeed(p.TimeSeed())
}
