package nox

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

	"nox/v1/common/console"
	"nox/v1/common/datapath"
	"nox/v1/common/log"
	"nox/v1/internal/version"
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
		opts.KeyPath = datapath.Path("server.pem")
	}
	l, err := net.Listen("tcp", host)
	if err != nil {
		return nil, err
	}
	rc := &RemoteConsole{
		l: l, opts: opts, exec: exec,
		conf: ssh.ServerConfig{
			ServerVersion: "SSH-2.0-OpenNox-" + version.Version(),
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

func (rc *RemoteConsole) newShell(ctx context.Context, ch ssh.Channel) *rcShell {
	sh := &rcShell{
		rc: rc, ctx: ctx, ch: ch,
		br: bufio.NewReader(ch),
		bw: bufio.NewWriter(ch),
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
	rc  *RemoteConsole
	ctx context.Context

	br      *bufio.Reader
	line    []rune
	history []string
	cur     int

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

func (sh *rcShell) printPrompt() {
	sh.print(console.ColorGreen, "nox> ", false)
}

func (sh *rcShell) print(cl console.Color, str string, nl bool) {
	sh.mu.Lock()
	defer sh.mu.Unlock()
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

func (sh *rcShell) Exec(cmd string) {
	if cmd == "" {
		return
	}
	rconLog.Printf("command: %q", cmd)
	if len(sh.history) == 0 || cmd != sh.history[len(sh.history)-1] {
		sh.history = append(sh.history, cmd)
	}
	sh.cur = len(sh.history)
	sh.rc.exec(sh.ctx, cmd)
}

func (sh *rcShell) eraseOne() {
	if len(sh.line) > 0 {
		sh.line = sh.line[:len(sh.line)-1]
	}
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteString("\b \b") // TODO: smarter way?
	sh.bw.Flush()
}

func (sh *rcShell) eraseLine() {
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteString("\033[2K\r")
	sh.bw.Flush()
}

func (sh *rcShell) doCmd() bool {
	cmd := string(sh.line)
	sh.line = sh.line[:0]
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
	if sh.cur < 0 || sh.cur >= len(sh.history) {
		return
	}
	sh.eraseLine()
	old := sh.history[sh.cur]
	sh.line = []rune(old)
	sh.printPrompt()
	sh.print(0, old, false)
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
	sh.line = append(sh.line, r)
	sh.mu.Lock()
	defer sh.mu.Unlock()
	sh.bw.WriteRune(r)
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
			sh.eraseLine()
			sh.printPrompt()
			return true
		}
		cmd = append(cmd, r)
		switch string(cmd) {
		case "[A":
			if sh.cur > 0 {
				sh.cur--
			}
			sh.recall()
			return true
		case "[B":
			if sh.cur < len(sh.history)-1 {
				sh.cur++
			}
			sh.recall()
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

func (rc *RemoteConsole) serveSession(ctx context.Context, ch ssh.Channel, reqs <-chan *ssh.Request) {
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
			sh := rc.newShell(ctx, ch)
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
					go rc.serveSession(ctx, cc, ccr)
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
