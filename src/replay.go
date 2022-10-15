package opennox

/*
#include "defs.h"
void  nox_xxx_playerLeaveObserver_0_4E6AA0(nox_playerInfo* pl);
*/
import "C"
import (
	"context"
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"

	"github.com/noxworld-dev/opennox-lib/log"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

const (
	replayOpMsg     = 1
	replayOpInit    = 2
	replayOpConsole = 3
	replayOpFrame   = 4
)

var (
	replayLog = log.New("replay")
	replay    struct {
		writer     io.Writer
		wcloser    io.Closer
		reader     io.Reader
		rcloser    io.Closer
		err        error
		op         byte
		frame      uint32
		readHeader bool
	}
)

func (s *Server) nox_xxx_replayStartSave_4D3370(name string) error {
	replayLog.Printf("writing replay to: %q", name)
	f, err := os.Create(name)
	if err != nil {
		replay.err = err
		return err
	}
	replay.err = nil
	replay.writer = f
	replay.wcloser = f
	noxflags.SetEngine(noxflags.EngineReplayWrite)
	return nil
}

func (s *Server) nox_xxx_replayFileOpen_4D34C0(name string) error {
	replayLog.Printf("replaying file: %q", name)
	f, err := os.Open(name)
	if err != nil {
		replay.err = err
		return err
	}
	replay.err = nil
	replay.reader = f
	replay.rcloser = f
	replay.readHeader = false
	*memmap.PtrUint32(0x5D4594, 1548728) = 0
	*memmap.PtrUint8(0x5D4594, 1548724) = 0
	noxflags.SetEngine(noxflags.EngineReplayRead)
	pl := s.getPlayerByID(255)
	pl.GoObserver(false, true)
	return nil
}

func (s *Server) nox_xxx_replayStopSave_4D33B0() {
	if replay.wcloser != nil {
		replayLog.Println("recording stopped")
		replay.wcloser.Close()
		replay.wcloser = nil
	}
	replay.writer = nil
	noxflags.UnsetEngine(noxflags.EngineReplayWrite)
}

func nox_xxx_replaySaveConsole(cmd string) {
	if replay.writer == nil || len(cmd) == 0 {
		return
	}
	var buf [9]byte
	binary.LittleEndian.PutUint32(buf[0:4], noxServer.Frame())
	buf[4] = replayOpConsole
	binary.LittleEndian.PutUint32(buf[5:9], uint32(len(cmd)))
	replay.writer.Write(buf[:])
	// TODO: vanilla was writing UTF-16 here
	//       since we are not aware of any replays, we will write UTF-8
	//       we could revisit this by writing a different opcode
	replay.writer.Write([]byte(cmd))
}

func (s *Server) nox_xxx_replayWriteMSgMB(pl *Player, data []byte) {
	if replay.writer == nil {
		return
	}
	var buf [10]byte
	binary.LittleEndian.PutUint32(buf[0:4], s.Frame())
	buf[4] = replayOpMsg
	buf[5] = byte(pl.Index())
	binary.LittleEndian.PutUint32(buf[6:10], uint32(len(data)))
	replay.writer.Write(buf[:])
	replay.writer.Write(data)
}

func (s *Server) nox_xxx_replayStopReadMB_4D3530() {
	if replay.rcloser != nil {
		replayLog.Println("replay stopped")
		replay.rcloser.Close()
		replay.rcloser = nil
	}
	replay.reader = nil
	replay.readHeader = false
	noxflags.UnsetEngine(noxflags.EngineReplayRead)
	pl := s.getPlayerByID(255)
	C.nox_xxx_playerLeaveObserver_0_4E6AA0(pl.C())
}

func nox_xxx_replay_4D3860(pi *PlayerOpts) error {
	if noxflags.HasEngine(noxflags.EngineReplayWrite) && replay.writer != nil {
		data, err := pi.MarshalBinary()
		if err != nil {
			return err
		}
		nox_xxx_replayWriteRndCounter_415F30(replay.writer)
		replay.writer.Write(data)
		return nil
	}
	if noxflags.HasEngine(noxflags.EngineReplayRead) && replay.reader != nil {
		data := make([]byte, 153)
		nox_xxx_replayReadeRndCounter_415F50(replay.reader)
		replay.reader.Read(data)
		if err := pi.UnmarshalBinary(data); err != nil {
			return err
		}
		return nil
	}
	return nil
}

func nox_xxx_replayWriteRndCounter_415F30(w io.Writer) {
	i := noxRndCounter1.Index()
	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:], uint32(i))
	w.Write(buf[:])
}

func nox_xxx_replayReadeRndCounter_415F50(r io.Reader) {
	var buf [4]byte
	r.Read(buf[:])
	i := int(binary.LittleEndian.Uint32(buf[:]))
	noxRndCounter1.Reset(i)
}

func (s *Server) nox_xxx_replayStartReadingOrSaving_4D38D0() error {
	if noxflags.HasEngine(noxflags.EngineReplayWrite) && replay.writer != nil {
		var buf [6]byte
		binary.LittleEndian.PutUint32(buf[0:4], s.Frame())
		buf[4] = replayOpInit
		mapname := s.nox_server_currentMapGetFilename_409B30()
		buf[5] = byte(len(mapname))
		replay.writer.Write(buf[:])
		replay.writer.Write([]byte(mapname))
		binary.LittleEndian.PutUint32(buf[0:4], uint32(NOX_CLIENT_VERS_CODE))
		replay.writer.Write(buf[:4])
		return nil
	}
	if noxflags.HasEngine(noxflags.EngineReplayRead) && replay.reader != nil {
		return s.nox_xxx_replayTickMB_4D3580_net_playback(false)
	}
	return nil
}

func nox_xxx_replayWriteFrame_4D39B0() {
	if noxflags.HasEngine(noxflags.EngineReplayWrite) && replay.writer != nil {
		var buf [5]byte
		binary.LittleEndian.PutUint32(buf[0:4], noxServer.Frame())
		buf[4] = replayOpFrame
		replay.writer.Write(buf[:])
	}
}

func (s *Server) nox_xxx_replayTickMB(a1 bool) error {
	if err := replay.err; err != nil {
		return err
	}
	ctx := context.Background()
	var buf [5]byte
	if !replay.readHeader {
		if _, err := io.ReadFull(replay.reader, buf[:5]); err == io.EOF {
			s.nox_xxx_replayStopReadMB_4D3530()
			nox_game_exit_xxx2()
			return nil
		} else if err != nil {
			return fmt.Errorf("cannot read header: %w", err)
		}
		replay.readHeader = true
		replay.frame = binary.LittleEndian.Uint32(buf[:4])
		replay.op = buf[4]
	}
	var data []byte
	for {
		if s.Frame() == replay.frame {
			return nil
		}
		switch replay.op {
		case replayOpMsg:
			if a1 {
				return nil
			}
			if _, err := io.ReadFull(replay.reader, buf[:5]); err != nil {
				return fmt.Errorf("cannot read packet header: %w", err)
			}
			ind := int(buf[0])
			sz := int(binary.LittleEndian.Uint32(buf[1:5]))
			if cap(data) < sz {
				data = make([]byte, sz)
			} else {
				data = data[:sz]
			}
			if _, err := io.ReadFull(replay.reader, data); err != nil {
				return fmt.Errorf("cannot read packet: %w", err)
			}
			s.onPacket(ind, data)
		case replayOpInit:
			if a1 {
				return nil
			}
			if _, err := io.ReadFull(replay.reader, buf[:1]); err != nil {
				return fmt.Errorf("cannot read init header: %w", err)
			}
			sz := int(buf[0])
			if cap(data) < sz {
				data = make([]byte, sz)
			} else {
				data = data[:sz]
			}
			if _, err := io.ReadFull(replay.reader, data); err != nil {
				return fmt.Errorf("cannot read map name: %w", err)
			}
			s.nox_xxx_gameSetMapPath_409D70(string(data))
			if _, err := io.ReadFull(replay.reader, buf[:4]); err != nil {
				return fmt.Errorf("cannot read version: %w", err)
			}
			v7 := binary.LittleEndian.Uint32(buf[0:4])
			if (v7 & 0xFF0000) != 0x10000 {
				nox_game_exit_xxx2()
				return errors.New("replay playback error")
			}
		case replayOpConsole:
			if a1 {
				if _, err := io.ReadFull(replay.reader, buf[:4]); err != nil {
					return fmt.Errorf("cannot cmd header: %w", err)
				}
				sz := int(binary.LittleEndian.Uint32(buf[:4]))
				if cap(data) < sz {
					data = make([]byte, sz)
				} else {
					data = data[:sz]
				}
				// TODO: reading as UTF-8 instead of UTF-16
				if _, err := io.ReadFull(replay.reader, data); err != nil {
					return fmt.Errorf("cannot cmd: %w", err)
				}
				execConsoleCmd(ctx, string(data))
			}
		case replayOpFrame:
			if a1 {
				return nil
			}
			nox_game_exit_xxx2()
		}
		if _, err := io.ReadFull(replay.reader, buf[:5]); err != nil {
			replay.readHeader = false
			return fmt.Errorf("cannot read header: %w", err)
		}
		replay.frame = binary.LittleEndian.Uint32(buf[:4])
		replay.op = buf[4]
	}
}

func (s *Server) nox_xxx_replayTickMB_4D3580_net_playback(a1 bool) error {
	if err := s.nox_xxx_replayTickMB(a1); err != nil {
		replayLog.Println(err)
		s.nox_xxx_replayStopReadMB_4D3530()
		nox_game_exit_xxx2()
		return err
	}
	return nil
}
