package discover

import (
	"bufio"
	"context"
	"fmt"
	"net"
	"os"
	"path/filepath"
	"strings"

	"github.com/noxworld-dev/lobby"

	"github.com/noxworld-dev/opennox-lib/common"
)

const (
	StaticFile = "game_ip.txt"
)

func init() {
	RegisterBackend(StaticFile, func(ctx context.Context, out chan<- Server) error {
		list, err := staticIPs(StaticFile)
		if len(list) == 0 {
			return err
		}
		for _, s := range list {
			s.Priority = -1
			select {
			case <-ctx.Done():
				return ctx.Err()
			case out <- s:
			}
		}
		return nil
	})
}

func staticIPs(path string) ([]Server, error) {
	name := filepath.Base(path)
	f, err := os.Open(path)
	if os.IsNotExist(err) {
		Log.Printf("no %s file", name)
		return nil, nil
	} else if err != nil {
		return nil, fmt.Errorf("cannot read %s: %w", name, err)
	}
	defer f.Close()

	var (
		out  []Server
		last error
	)
	sc := bufio.NewScanner(f)
	for sc.Scan() {
		line := sc.Text()
		if strings.HasPrefix(line, "#") {
			continue
		}
		// TODO: support server ports
		const port = common.GamePort
		ip := net.ParseIP(line).To4()
		if ip == nil {
			last = fmt.Errorf("cannot parse server IP in %s: %q", name, line)
			Log.Println(last)
			continue
		}
		Log.Printf("%s: %v", name, ip)
		out = append(out, Server{
			Source:   name,
			Priority: priorityStatic,
			IP:       ip,
			Game: lobby.Game{
				Address: ip.String(),
				Port:    port,
			},
		})
	}
	if err := sc.Err(); err != nil {
		last = fmt.Errorf("error reading %s: %w", name, err)
		Log.Println(last)
	}
	return out, last
}
