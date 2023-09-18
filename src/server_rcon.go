package opennox

import (
	"bufio"
	"context"
	"crypto/rand"
	"crypto/rsa"
	"crypto/x509"
	"encoding/binary"
	"encoding/pem"
	"errors"
	"fmt"
	"io"
	"net"
	"os"
	"strconv"
	"strings"
	"sync"

	"golang.org/x/crypto/ssh"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox-lib/console"

	"github.com/noxworld-dev/opennox/v1/internal/version"
)

const (
	rconDefaultHost = "127.0.0.1:18522"
)

var (
	rconLog            = log.New("rcon")
	errRconInvalidPass = errors.New("invalid user name or password")
)

type RconOptions struct {
	Pass    string `json:"pass"`
	KeyPath string `json:"key_path"`
}

func NewRemoteConsole(host string, exec console.ExecFunc, opts RconOptions) (*RemoteConsole, error) {
	if opts.KeyPath == "" {
		opts.KeyPath = datapath.Data("server.pem")
	}
	l, err := net.Listen("tcp", host)
	if err != nil {
		return nil, err
	}
	rc := &RemoteConsole{
		l: l, opts: opts, exec: exec,
		conf: ssh.ServerConfig{
			ServerVersion: "SSH-2.0-OpenNox-" + version.Version(),
			BannerCallback: func(c ssh.ConnMetadata) string {
				return `
  /888888                                /88   /88           /88   /88
 /88__  88                              | 888 | 88          | 88  / 88
| 88  \ 88  /888888   /888888  /8888888 | 8888| 88  /888888 |  88/ 88/
| 88  | 88 /88__  88 /88__  88| 88__  88| 88 88 88 /88__  88 \  8888/
| 88  | 88| 88  \ 88| 88888888| 88  \ 88| 88  8888| 88  \ 88  >88  88
| 88  | 88| 88  | 88| 88_____/| 88  | 88| 88\  888| 88  | 88 /88/\  88
|  888888/| 8888888/|  8888888| 88  | 88| 88 \  88|  888888/| 88  \ 88
 \______/ | 88____/  \_______/|__/  |__/|__/  \__/ \______/ |__/  |__/
          | 88
          | 88        Version: ` + version.ClientVersion() + `
          |__/

`
			},
		},
	}
	if opts.Pass != "" {
		rc.conf.PasswordCallback = rc.authPassword
	} else {
		rc.conf.NoClientAuth = true
	}
	if err := rc.loadKey(opts.KeyPath); err != nil {
		_ = rc.Close()
		return nil, err
	}
	return rc, nil
}

var _ console.Printer = (*RemoteConsole)(nil)

type RemoteConsole struct {
	l        net.Listener
	exec     console.ExecFunc
	opts     RconOptions
	conf     ssh.ServerConfig
	sessions struct {
		sync.RWMutex
		list map[*rcShell]struct{}
	}
}

func (rc *RemoteConsole) Close() error {
	rc.sessions.Lock()
	rc.sessions.list = nil
	rc.sessions.Unlock()
	return rc.l.Close()
}

func encodePEM(key *rsa.PrivateKey) []byte {
	block := pem.Block{
		Type:  "RSA PRIVATE KEY",
		Bytes: x509.MarshalPKCS1PrivateKey(key),
	}
	return pem.EncodeToMemory(&block)
}

func (rc *RemoteConsole) loadKey(path string) error {
	pk, err := rc.readKey(path)
	if os.IsNotExist(err) {
		pk, err = rc.genKey(path)
	}
	if err != nil {
		return err
	}
	sign, err := ssh.NewSignerFromKey(pk)
	if err != nil {
		return err
	}
	rc.conf.AddHostKey(sign)
	return nil
}

func (rc *RemoteConsole) readKey(path string) (*rsa.PrivateKey, error) {
	data, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	decoded, _ := pem.Decode(data)
	if decoded == nil {
		return nil, errors.New("no PEM data found")
	}
	return x509.ParsePKCS1PrivateKey(decoded.Bytes)
}

func (rc *RemoteConsole) genKey(path string) (*rsa.PrivateKey, error) {
	pk, err := rsa.GenerateKey(rand.Reader, 4096)
	if err != nil {
		return nil, err
	}
	data := encodePEM(pk)
	if err = os.WriteFile(path, data, 0600); err != nil {
		return nil, err
	}
	return pk, nil
}

func (rc *RemoteConsole) Print(cl console.Color, str string) {
	rc.sessions.RLock()
	defer rc.sessions.RUnlock()
	for sh := range rc.sessions.list {
		sh.Print(cl, str)
	}
}

func (rc *RemoteConsole) Printf(cl console.Color, format string, args ...interface{}) {
	str := fmt.Sprintf(format, args...)
	rc.Print(cl, str)
}

func (rc *RemoteConsole) Serve() error {
	for {
		c, err := rc.l.Accept()
		if err != nil {
			return err
		}
		sc, chans, reqs, err := ssh.NewServerConn(c, &rc.conf)
		if err != nil {
			_ = c.Close()
			rconLog.Println(err)
			continue
		}
		go rc.serveConn(sc, chans, reqs)
	}
}

func (rc *RemoteConsole) authPassword(c ssh.ConnMetadata, pass []byte) (*ssh.Permissions, error) {
	if len(rc.opts.Pass) != len(pass) || rc.opts.Pass != string(pass) {
		return nil, errRconInvalidPass
	}
	return &ssh.Permissions{}, nil
}

func (rc *RemoteConsole) newShell(ctx context.Context, ch ssh.Channel, user string) *rcShell {
	sh := &rcShell{
		rc: rc, ctx: ctx, ch: ch,
		user: user,
		br:   bufio.NewReader(ch),
		bw:   bufio.NewWriter(ch),
	}
	rc.sessions.Lock()
	if rc.sessions.list == nil {
		rc.sessions.list = make(map[*rcShell]struct{})
	}
	rc.sessions.list[sh] = struct{}{}
	rc.sessions.Unlock()
	return sh
}

type rcShell struct {
	rc   *RemoteConsole
	ctx  context.Context
	user string

	br      *bufio.Reader
	line    []rune
	cursor  int
	history struct {
		list []string
		cur  int
	}

	mu sync.Mutex
	ch ssh.Channel
	bw *bufio.Writer
}

func (sh *rcShell) Close() error {
	sh.rc.sessions.Lock()
	delete(sh.rc.sessions.list, sh)
	sh.rc.sessions.Unlock()

	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteString("\r\n")
	sh.bw.Flush()
	var msg [4]byte
	binary.BigEndian.PutUint32(msg[:], 0)
	sh.ch.SendRequest("exit-status", false, msg[:])
	sh.ch.Close()
	return nil
}

func (sh *rcShell) newLine() {
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteString("\r\n")
}

func (sh *rcShell) print(cl console.Color, str string, nl bool) {
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.printUnsafe(cl, str, nl)
}

func (sh *rcShell) printUnsafe(cl console.Color, str string, nl bool) {
	colored := cl > 0
	if colored {
		code := 0
		switch cl {
		case console.ColorBlack, console.ColorDarkGrey:
			code = 30 // Black
		case console.ColorDarkRed, console.ColorRed:
			code = 31 // Red
		case console.ColorDarkGreen, console.ColorGreen, console.ColorLightGreen:
			code = 32 // Green
		case console.ColorDarkYellow, console.ColorYellow, console.ColorLightYellow:
			code = 33 // Yellow
		case console.ColorDarkBlue, console.ColorBlue:
			code = 34 // Blue
		case console.ColorLightRed:
			code = 35 // Magenta
		case console.ColorLightBlue:
			code = 36 // Cyan
		case console.ColorLightGrey, console.ColorWhite:
			code = 37 // White
		}
		colored = code != 0
		if colored {
			sh.bw.WriteString("\033[0;")
			sh.bw.WriteString(strconv.Itoa(code))
			sh.bw.WriteByte('m')
		}
	}
	sh.bw.WriteString(str)
	if colored {
		sh.bw.WriteString("\033[0m")
	}
	if nl && !strings.HasSuffix(str, "\n") {
		sh.bw.WriteString("\r\n")
	}
	sh.bw.Flush()
}

func (sh *rcShell) Print(cl console.Color, str string) {
	sh.print(cl, str, true)
}

func (sh *rcShell) printPrompt() {
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteString("\033[0;36m")
	sh.bw.WriteString(sh.user)
	sh.bw.WriteString("@opennox")
	sh.bw.WriteString("\033[0m")
	sh.bw.WriteRune(':')
	sh.bw.WriteString("\033[0;34m")
	sh.bw.WriteString("~")
	sh.bw.WriteString("\033[0m")
	sh.bw.WriteString("$ ")
	sh.bw.Flush()
}

func (sh *rcShell) Exec(cmd string) {
	if cmd == "" {
		return
	}
	rconLog.Printf("command: %q", cmd)
	if n := len(sh.history.list); n == 0 || cmd != sh.history.list[n-1] {
		sh.history.list = append(sh.history.list, cmd)
	}
	sh.history.cur = len(sh.history.list)
	sh.rc.exec(sh.ctx, cmd)
}

func (sh *rcShell) eraseOne() {
	if sh.cursor == 0 || len(sh.line) == 0 {
		return
	}
	if sh.cursor == len(sh.line) {
		sh.line = sh.line[:len(sh.line)-1]
		sh.cursor--
	} else {
		sh.line = append(sh.line[:sh.cursor-1], sh.line[sh.cursor:]...)
		sh.cursor--
	}

	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteRune('\b')
	right := sh.line[sh.cursor:]
	sh.bw.WriteString(string(right))
	sh.bw.WriteRune(' ')
	sh.bw.WriteString("\033[")
	sh.bw.WriteString(strconv.Itoa(len(right) + 1))
	sh.bw.WriteRune('D')
	sh.bw.Flush()
}

func (sh *rcShell) delOne() {
	if sh.cursor == len(sh.line) {
		return
	}
	sh.line = append(sh.line[:sh.cursor], sh.line[sh.cursor+1:]...)

	sh.mu.Lock()
	defer sh.mu.Unlock()
	right := sh.line[sh.cursor:]
	sh.bw.WriteString(string(right))
	sh.bw.WriteRune(' ')
	sh.bw.WriteString("\033[")
	sh.bw.WriteString(strconv.Itoa(len(right) + 1))
	sh.bw.WriteRune('D')
	sh.bw.Flush()
}

func (sh *rcShell) eraseLine() {
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteString("\033[2K\r")
	sh.bw.Flush()
}

func (sh *rcShell) cursorLeft() {
	if sh.cursor <= 0 {
		return
	}
	sh.mu.Lock()
	sh.bw.WriteRune('\b')
	sh.bw.Flush()
	sh.mu.Unlock()
	sh.cursor--
}

func (sh *rcShell) cursorRight() {
	if sh.cursor >= len(sh.line) {
		return
	}
	sh.mu.Lock()
	sh.bw.WriteRune(sh.line[sh.cursor])
	sh.bw.Flush()
	sh.mu.Unlock()
	sh.cursor++
}

func (sh *rcShell) doCmd() bool {
	cmd := string(sh.line)
	sh.line = sh.line[:0]
	sh.cursor = 0
	switch cmd {
	case "q", "quit":
		return false
	default:
		sh.newLine()
		sh.Exec(cmd)
		sh.printPrompt()
		return true
	}
}

func (sh *rcShell) recall() {
	i := sh.history.cur
	if i < 0 || i >= len(sh.history.list) {
		return
	}
	sh.eraseLine()
	old := sh.history.list[i]
	sh.line = []rune(old)
	sh.printPrompt()
	sh.print(0, old, false)
	sh.cursor = len(old)
}

func (sh *rcShell) addRune(r rune) bool {
	//rconLog.Printf("key: %q", r)
	switch r {
	case '\x03':
		return false
	case '\r':
		return sh.doCmd()
	case '\b', '\u007f':
		sh.eraseOne()
		return true
	case '\033':
		return sh.readSpec()
	}
	if len(sh.line) == sh.cursor {
		sh.line = append(sh.line, r)
		sh.cursor++
	} else {
		sh.line = append(sh.line, ' ')
		i := sh.cursor
		copy(sh.line[i+1:], sh.line[i:])
		sh.line[i] = r
		sh.cursor++
	}
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteRune(r)
	right := sh.line[sh.cursor:]
	sh.bw.WriteString(string(right))
	if len(right) != 0 {
		sh.bw.WriteString("\033[")
		sh.bw.WriteString(strconv.Itoa(len(right)))
		sh.bw.WriteRune('D')
	}
	sh.bw.Flush()
	return true
}

func (sh *rcShell) readSpec() bool {
	var cmd []rune
	for {
		r, _, err := sh.br.ReadRune()
		if err == io.EOF {
			return false
		} else if err != nil {
			rconLog.Println(err)
			return false
		}
		switch r {
		case '\x03':
			return false
		case '\r':
			rconLog.Printf("skip: %q", string(cmd))
			sh.line = sh.line[:0]
			sh.cursor = 0
			sh.eraseLine()
			sh.printPrompt()
			return true
		}
		cmd = append(cmd, r)
		switch string(cmd) {
		case "[3~": // del
			sh.delOne()
			return true
		case "[A": // up
			if sh.history.cur > 0 {
				sh.history.cur--
			}
			sh.recall()
			return true
		case "[B": // down
			if sh.history.cur < len(sh.history.list)-1 {
				sh.history.cur++
			}
			sh.recall()
			return true
		case "[C": // right
			sh.cursorRight()
			return true
		case "[D": // left
			sh.cursorLeft()
			return true
		}
	}
}

func (sh *rcShell) Serve() {
	defer sh.Close()
	sh.printPrompt()
	for {
		r, _, err := sh.br.ReadRune()
		if err == io.EOF {
			return
		} else if err != nil {
			rconLog.Println(err)
			return
		}
		if !sh.addRune(r) {
			return
		}
	}
}

func (rc *RemoteConsole) serveSession(ctx context.Context, ch ssh.Channel, user string, reqs <-chan *ssh.Request) {
	defer ch.Close()
	ctx, cancel := context.WithCancel(ctx)
	defer cancel()
	for r := range reqs {
		switch r.Type {
		case "env":
			var req struct {
				Name  string
				Value string
			}
			ok := true
			if err := ssh.Unmarshal(r.Payload, &req); err != nil {
				rconLog.Println(err)
				ok = false
			} else {
				//rconLog.Printf("env: %q = %q", req.Name, req.Value)
			}
			if r.WantReply {
				r.Reply(ok, nil)
			}
		case "pty-req":
			var req struct {
				Term     string
				Columns  uint32
				Rows     uint32
				Width    uint32
				Height   uint32
				Modelist string
			}
			ok := true
			if err := ssh.Unmarshal(r.Payload, &req); err != nil {
				rconLog.Println(err)
				ok = false
			} else {
				rconLog.Printf("pty-req: %q, %dx%d, %dx%d", req.Term, req.Columns, req.Rows, req.Width, req.Height)
			}
			if r.WantReply {
				r.Reply(ok, nil)
			}
		case "shell":
			rconLog.Printf("shell: %q", string(r.Payload))
			if r.WantReply {
				r.Reply(true, nil)
			}
			sh := rc.newShell(ctx, ch, user)
			go sh.Serve()
		default:
			rconLog.Printf("unsupported session request: %q", r.Type)
			if r.WantReply {
				r.Reply(false, nil)
			}
		}
	}
}

func (rc *RemoteConsole) serveConn(sc *ssh.ServerConn, chans <-chan ssh.NewChannel, reqs <-chan *ssh.Request) {
	defer sc.Close()
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()
	rconLog.Printf("accepted: %q (%v)", sc.User(), sc.RemoteAddr())
	go func() {
		for cr := range chans {
			switch typ := cr.ChannelType(); typ {
			case "session":
				cc, ccr, err := cr.Accept()
				if err != nil {
					rconLog.Printf("cannot open session: %v", err)
				} else {
					go rc.serveSession(ctx, cc, sc.User(), ccr)
				}
			default:
				rconLog.Printf("unsupported channel type: %q", typ)
				cr.Reject(ssh.UnknownChannelType, "Unsupported channel type")
			}
		}
	}()
	go func() {
		for r := range reqs {
			switch r.Type {
			default:
				rconLog.Printf("unsupported request type: %q", r.Type)
				if r.WantReply {
					r.Reply(false, nil)
				}
			}
		}
	}()
	if err := sc.Wait(); err != nil {
		rconLog.Printf("error: %q: %v", sc.RemoteAddr(), err)
	}

}
