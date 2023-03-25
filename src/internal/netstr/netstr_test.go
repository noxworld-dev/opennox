package netstr

import (
	"testing"

	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/stretchr/testify/require"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
)

func TestNetstr(t *testing.T) {
	DebugSockets = true
	go func() {
		var frame uint32 = 1
		s := NewStreams()
		s.Debug = true
		s.Log = log.New("SRV")
		s.GameFlags = func() noxflags.GameFlag {
			return noxflags.GameHost
		}
		s.GameFrame = func() uint32 {
			return frame
		}
		s.GetMaxPlayers = func() int {
			return 10
		}
		s.Xor = false
		conn, err := s.NewServer(&Options{
			Port:       18501,
			Max:        10,
			BufferSize: 2048,
			OnSend: func(id Handle, buf []byte) int {
				t.Logf("SRV: func1: %v, [%d]", id.i, len(buf))
				return len(buf)
			},
			OnReceive: func(id Handle, buf []byte) int {
				t.Logf("SRV: func2: %v, [%d]", id.i, len(buf))
				return len(buf)
			},
			Check14: func(out []byte, packet []byte, a4a bool, add func(pid ntype.Player) bool) int {
				t.Logf("SRV: check14: [%d], %v: %x", len(packet), a4a, packet)
				out[2] = 20 // OK
				return 3
			},
			Check17: func(out []byte, packet []byte) int {
				t.Logf("SRV: check17: [%d]: %x", len(packet), packet)
				out[2] = 20 // OK
				return 3
			},
		})
		require.NoError(t, err)
		defer conn.Close()

		for {
			s.Update()
			conn.RecvLoop(ServeCanRead)
			frame++
		}
	}()

	s := NewStreams()
	s.Debug = true
	s.Log = log.New("CLI")
	s.GameFlags = func() noxflags.GameFlag {
		return 0
	}
	s.Xor = false

	conn, err := s.NewClient(&Options{
		Max:        10,
		BufferSize: 2048,
		OnSend: func(id Handle, buf []byte) int {
			t.Logf("CLI: func1: %v, [%d]", id.i, len(buf))
			return len(buf)
		},
		OnReceive: func(id Handle, buf []byte) int {
			op := noxnet.Op(buf[0])
			switch op {
			case noxnet.MSG_XXX_STOP:
				t.Error("failed")
			}
			t.Logf("CLI: func2: %v, [%d]", id.i, len(buf))
			return len(buf)
		},
		Check14: func(out []byte, packet []byte, a4a bool, add func(pid ntype.Player) bool) int {
			t.Logf("CLI: check14: [%d], %v: %x", len(packet), a4a, packet)
			out[2] = 20 // OK
			return 3
		},
		Check17: func(out []byte, packet []byte) int {
			t.Logf("CLI: check17: [%d]: %x", len(packet), packet)
			out[2] = 20 // OK
			return 3
		},
	})
	require.NoError(t, err)
	defer conn.Close()

	err = conn.Dial("localhost", 18501, 18502, &fakeOpts{Str: "Hello\x01\x02\x03"})
	require.NoError(t, err)

	err = conn.DialWait(-1, func() {
		t.Logf("CLI: dial resend")
	}, func() bool {
		t.Logf("CLI: dial check")
		return true
	})
	require.NoError(t, err)
}

type fakeOpts struct {
	Str string
}

func (opt *fakeOpts) MarshalBinary() ([]byte, error) {
	return []byte(opt.Str), nil
}
