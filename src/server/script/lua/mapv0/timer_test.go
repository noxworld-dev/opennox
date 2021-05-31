package mapv0_test

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestFrameTimer(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo()
		v.x = 1
	end
	Nox.FrameTimer(1, foo)
`)
	require.Equal(t, float32(0), v.pos.X)
	g.Tick()
	require.Equal(t, float32(1), v.pos.X)
}

func TestFrameTimerStop(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo()
		v.x = 1
	end
	t = Nox.FrameTimer(1, foo)
`)
	require.Equal(t, float32(0), v.pos.X)
	g.Exec(`
	t:Stop()
`)
	for i := 0; i < 3; i++ {
		g.Tick()
	}
	require.Equal(t, float32(0), v.pos.X)
}

func TestFrameTimerAlt(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo()
		v.x = 1
	end
	Nox.Timer(Nox.Frames(1), foo)
`)
	require.Equal(t, float32(0), v.pos.X)
	g.Tick()
	require.Equal(t, float32(1), v.pos.X)
}

func TestFrameTimerArg(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo(a,x)
		a.x = x
	end
	Nox.FrameTimer(1, foo, v, 2)
`)
	require.Equal(t, float32(0), v.pos.X)
	g.Tick()
	require.Equal(t, float32(2), v.pos.X)
}

func TestFrameTimerAltArg(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo(a,x)
		a.x = x
	end
	Nox.Timer(Nox.Frames(1), foo, v, 2)
`)
	require.Equal(t, float32(0), v.pos.X)
	g.Tick()
	require.Equal(t, float32(2), v.pos.X)
}

func TestSecondTimer(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo()
		v.x = 1
	end
	Nox.SecondTimer(1, foo)
`)
	require.Equal(t, float32(0), v.pos.X)
	for i := 0; i < 31; i++ {
		g.Tick()
	}
	require.Equal(t, float32(1), v.pos.X)
}

func TestSecondTimerStop(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo()
		v.x = 1
	end
	t = Nox.SecondTimer(1, foo)
`)
	require.Equal(t, float32(0), v.pos.X)
	g.Exec(`
	t:Stop()
`)
	for i := 0; i < 31*2; i++ {
		g.Tick()
	}
	require.Equal(t, float32(0), v.pos.X)
}

func TestSecondTimerAlt(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo()
		v.x = 1
	end
	Nox.Timer(Nox.Sec(1), foo)
`)
	require.Equal(t, float32(0), v.pos.X)
	for i := 0; i < 31; i++ {
		g.Tick()
	}
	require.Equal(t, float32(1), v.pos.X)
}

func TestSecondTimerArg(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo(a,x)
		a.x = x
	end
	Nox.SecondTimer(1, foo, v, 2)
`)
	require.Equal(t, float32(0), v.pos.X)
	for i := 0; i < 31; i++ {
		g.Tick()
	}
	require.Equal(t, float32(2), v.pos.X)
}

func TestSecondTimerAltArg(t *testing.T) {
	g := newGame(t)
	v := g.newObject("Test", 0, 0)
	g.Exec(`
	v = Nox.Object("Test")
	function foo(a,x)
		a.x = x
	end
	Nox.Timer(Nox.Sec(1), foo, v, 2)
`)
	require.Equal(t, float32(0), v.pos.X)
	for i := 0; i < 31; i++ {
		g.Tick()
	}
	require.Equal(t, float32(2), v.pos.X)
}
